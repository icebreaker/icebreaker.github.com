---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2023
image: /media/og/suzanne.png
title: Branchless Line Drawing
propaganda: 5
---

Branchless Line Drawing
=========================

When it comes to drawing non-antialised lines, undoubtedly the very first approach that comes to mind is of course [Bresenham's line drawing algorithm][bresenham].

I always dreaded implementing it, simply because it's full of special cases; and special cases generally mean branches, which are the last things you'd want anywhere near tight loops.

A couple of weeks ago, I had a shower thought. Why not just use linear interpolation and simply interpolate between the two points?

Naturally, I was almost certain that someone, somewhere, already thought of this and perhaps even patented it as folks do with these things.

After a cursory search on the information super highway I confirmed that my gut instinct was right, however the implementations I found still used branches and superfluous divisions, so I decided to roll and share my own flavor.

```c
void image_render_line(
	image_t *image,
	const point_t p0,
	const point_t p1,
	const color_t color
)
{
	color_t *pixels = image->pixels;
	const int w = image->w;

	const float x0 = p0.x;
	const float y0 = p0.y;
	const float dx = p1.x - x0;
	const float dy = p1.y - y0;

	const float step = 1.0f / fmaxf(fabsf(dx), fabsf(dy));

	for(float t = 0.0f; t < 1.0f; t += step)
	{
		const int x = x0 + dx * t;
		const int y = y0 + dy * t;

		pixels[x + y * w] = color;
	}
}
```

Let's also take a peak at the disassembly, just for funsies no less.

 ```nasm
 ; cc -O2 -ffast-math -masm=intel -S line.c
 image_render_line:
 	movq	r8, xmm0
 	movq	rax, xmm1
 	movdqa	xmm4, xmm1
 	mov	ecx, edi
 	shr	r8, 32
 	shr	rax, 32
 	subss	xmm4, xmm0
 	movdqa	xmm7, xmm0
 	movd	xmm3, r8d
 	movd	xmm1, eax
 	mov	edi, edx
 	movss	xmm5, DWORD PTR .LC2[rip]
 	subss	xmm1, xmm3
 	movss	xmm0, DWORD PTR .LC1[rip]
 	movaps	xmm6, xmm5
 	movaps	xmm2, xmm1
 	andps	xmm2, xmm0
 	andps	xmm0, xmm4
 	maxss	xmm0, xmm2
 	divss	xmm6, xmm0
 	pxor	xmm0, xmm0
 .L2:
 	movaps	xmm2, xmm1
 	mulss	xmm2, xmm0
 	addss	xmm2, xmm3
 	cvttss2si	eax, xmm2
 	movaps	xmm2, xmm4
 	mulss	xmm2, xmm0
 	addss	xmm0, xmm6
 	imul	eax, ecx
 	addss	xmm2, xmm7
 	cvttss2si	edx, xmm2
 	add	eax, edx
 	comiss	xmm5, xmm0
 	cdqe
 	mov	DWORD PTR [rsi+rax*4], edi
 	ja	.L2
 	ret
 ```

What's the catch? There must be some caveats, right?

First of all, there is no clipping, so you must ensure that both points are within the viewport. In other words, the following must be `true`:

```c
p0.x >= 0 && p0.x <= w - 1
p0.y >= 0 && p0.y <= h - 1
p1.x >= 0 && p1.x <= w - 1
p1.y >= 0 && p1.y <= h - 1
```

Second, it doesn't ensure that `t = 1.0` which means that line is not guaranteed reach the coordinates of the endpoint.

This of course could be addressed by drawing one additional point or simply changing `t < 1.0` to `t <= 1.0` and then making sure that `t` never goes beyond `1.0`.

Third, it doesn't handle the case when both points are in the same position, in other words `p0 == p1`.

This could be solved as well relatively easily, by clamping the step value before the division, like illustrated below.

```c
const float step = 1.0 / fmax(fmax(fabs(dx), fabs(dy)), 1.0);
```

That's it. And now, here's an actual full fledged example, which outputs a lovely wireframe render of [Suzanne][suzanne].

```c
/*
	MIT LICENSE
	Copyright (c) 2023, Mihail Szabolcs
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#ifndef IMAGE_WIDTH
	#define IMAGE_WIDTH 1024
#endif

#ifndef IMAGE_HEIGHT
	#define IMAGE_HEIGHT 1024
#endif

#define IMAGE_SIZE IMAGE_WIDTH * IMAGE_HEIGHT

typedef union
{
	uint32_t bgra;
	struct
	{
		uint8_t b : 8;
		uint8_t g : 8;
		uint8_t r : 8;
		uint8_t a : 8;
	};
} color_t;

#pragma pack(push, 1)
typedef struct {
   uint8_t idlength;
   uint8_t colourmaptype;
   uint8_t datatypecode;
   uint16_t colourmaporigin;
   uint16_t colourmaplength;
   uint8_t colourmapdepth;
   uint16_t x_origin;
   uint16_t y_origin;
   uint16_t width;
   uint16_t height;
   uint8_t bitsperpixel;
   uint8_t imagedescriptor;
} image_header_t;
#pragma pack(pop)

typedef struct
{
	int w;
	int h;
	int size;
	color_t *pixels;
	image_header_t header;
} image_t;

typedef struct
{
	float x, y;
} point_t;

typedef struct
{
	float x, y, z;
} vertex_t;

typedef struct
{
	int v0, v1, v2;
} triangle_t;

typedef struct
{
	vertex_t *vertices;
	triangle_t *triangles;
	int num_triangles;
} mesh_t;

static inline point_t vertex_to_point(
    const vertex_t vertex,
    const float half_w,
    const float half_h
);

static void image_clear(image_t *image, const color_t color);
static bool image_save(image_t *image, const char *filename);
static void image_render_line(
    image_t *image,
    const point_t p0,
    const point_t p1,
    const color_t color
);
static void image_render_mesh(
    image_t *image,
    const mesh_t *mesh,
    const color_t color
);

static image_t *image = &(image_t) {
	.w = IMAGE_WIDTH,
	.h = IMAGE_HEIGHT,
	.size = IMAGE_SIZE,
	.pixels = (color_t[IMAGE_SIZE]) { 0, },
	.header = {
		.datatypecode = 2,
		.width = IMAGE_WIDTH,
		.height = IMAGE_HEIGHT,
		.y_origin = IMAGE_HEIGHT,
		.bitsperpixel = sizeof(color_t) << 3,
		.imagedescriptor = 8 | (1 << 5)
	}
};

static const mesh_t *mesh = &(mesh_t) {
	#include "mesh.h"
};

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "usage: %s output.tga\n", argv[0]);
		return EXIT_FAILURE;
	}

	image_clear(image, (color_t) { .a = 0xFF });
    
	image_render_mesh(
        image,
        mesh,
        (color_t) {
            .r = 0xFF,
            .g = 0xFF,
            .a = 0xFF
        }
    );

	if(!image_save(image, argv[1]))
	{
		fprintf(stderr, "error: could not save image `%s'\n", argv[1]);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

static inline point_t vertex_to_point(
    const vertex_t vertex,
    const float half_w,
    const float half_h
)
{
	return (point_t) {
		.x = vertex.x * half_w + half_w,
		.y = vertex.y * half_h + half_h
	};
}

static void image_clear(image_t *image, const color_t color)
{
	for(color_t *p = image->pixels,
        *end = image->pixels + image->size; p != end; p++)
		*pixel = color;
}

static bool image_save(image_t *image, const char *filename)
{
	FILE *fp = fopen(filename, "wb");
	if(fp == NULL)
		return false;

	if(fwrite(
        &image->header,
        1,
        sizeof(image->header), fp) != sizeof(image->header))
	{
		fclose(fp);
		return false;
	}

	if(fwrite(
        image->pixels,
        sizeof(color_t),
        image->size, fp) != image->size)
	{
		fclose(fp);
		return false;
	}

	fclose(fp);
	return true;
}

static void image_render_line(
	image_t *image,
	const point_t p0,
	const point_t p1,
	const color_t color
)
{
	color_t *pixels = image->pixels;
	const int w = image->w;

	const float x0 = p0.x;
	const float y0 = p0.y;
	const float dx = p1.x - x0;
	const float dy = p1.y - y0;

	const float step = 1.0f / fmaxf(fabsf(dx), fabsf(dy));

	for(float t = 0.0f; t < 1.0f; t += step)
	{
		const int x = x0 + dx * t;
		const int y = y0 + dy * t;

		pixels[x + y * w] = color;
	}
}

static void image_render_mesh(
    image_t *image,
    const mesh_t *mesh,
    const color_t color
)
{
	const vertex_t *vertices = mesh->vertices;
	const float half_w = image->w * 0.5f;
	const float half_h = image->h * 0.5f;

	for(const triangle_t *tri = mesh->triangles,
        *end = mesh->triangles + mesh->num_triangles; tri != end; tri++)
	{
		const vertex_t v0 = vertices[tri->v0];
		const vertex_t v1 = vertices[tri->v1];
		const vertex_t v2 = vertices[tri->v2];

		const point_t p0 = vertex_to_point(v0, half_w, half_h);
		const point_t p1 = vertex_to_point(v1, half_w, half_h);
		const point_t p2 = vertex_to_point(v2, half_w, half_h);

		image_render_line(image, p0, p1, color);
		image_render_line(image, p1, p2, color);
		image_render_line(image, p2, p0, color);
	}
}

/* vim: set ts=4 sw=4 sts=4 noet: */
```

![suzanne](/media/2023/suzanne.png)

What a thing of beauty, isn't it? Those lovely jaggies, just be hitting different. I think so too.

If we really wanted to do away with the `fmax`, `fabs` and the division, we could *borrow* the [fast inverse square root implementation from Q3][fsqrtq3] and *optimize* things even further.

```c
float Q_rsqrt(float number)
{
 	long i;
 	float x2, y;
 	const float threehalfs = 1.5F;

 	x2 = number * 0.5F;
 	y  = number;
 	i  = * ( long * ) &y; // evil floating point bit level hacking
 	i  = 0x5f3759df - ( i >> 1 ); // what the fuck?
 	y  = * ( float * ) &i;
 	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration

 	return y;
}

void image_render_line(
	image_t *image,
	const point_t p0,
	const point_t p1,
	const color_t color
)
{
	color_t *pixels = image->pixels;
	const int w = image->w;

	const float x0 = p0.x;
	const float y0 = p0.y;
	const float dx = p1.x - x0;
	const float dy = p1.y - y0;

	const float step = Q_rsqrt(dx * dx + dy * dy);

	for(float t = 0.0f; t < 1.0f; t += step)
	{
		const int x = x0 + dx * t;
		const int y = y0 + dy * t;

		pixels[x + y * w] = color;
	}
}
```

[bresenham]: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
[suzanne]: https://www.dummies.com/article/technology/software/animation-software/blender/meet-suzanne-the-blender-monkey-142918/
[fsqrtq3]: https://en.wikipedia.org/wiki/Fast_inverse_square_root
