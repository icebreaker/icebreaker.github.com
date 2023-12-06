---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2023
title: Upscaling Pixel Art
imagediffviewer: true
propaganda: 8
---

Upscaling Pixel Art
=========================

A few years ago there was some sort of renessaince of pixel-art-upscalers, mainly fueled by the
emulator community. It has gotten to a point where even some research division at Microsoft
joined in and produced a [paper][paper] around the subject.

The emulator community of course wanted to be able to "apply the upscaling" in real-time; as a
direct result many of the so called upscalers were ported and made available as pixel shaders.

One such upscaling technique was called [XBR][xbr] and was the brainchild of the mysterious internet
citizen Hyllian.

Not much is known about him, other than what can be gleaned from the trail of posts left
behind on dying old-school forums like [one][forum].

XBR has many flavors an options, but the one that I was interested in has been known as XBR4x.

The 4x of course stands for the scale factor itself. Very creative, I know!

I finally decided to bite the bullet and come up with a relatively sane and simple
implementation in C. Without too many bells and whistles of course, as per usual!

Before diving into any of the technical details, let's take a look at some examples.

First this tiny house taken from the [Tiny Swords][tinyswords] asset pack by [Pixel Frog][pixelfrog].

<div class="image-diff-viewer">
<img src="/media/2023/houseo.png" />
<img src="/media/2023/housexbr4.png" />
</div>

And, then something more involved in the form of this amazing [Dungeon Crawler Tileset][dct] from the open source rogue-like adventure called [Dungeon Crawl Stone Soup][dcss].

<div class="image-diff-viewer">
<img src="/media/2023/tileso.png" />
<img src="/media/2023/tilesxbr4.png" />
</div>

Most implementations out there convert from RGB to YUV and employ all sorts of magical formulas to calculate the distance (or similarity if wish) between two pixels.

As it turn out, it's more than enough to just use an approximation of [luma][luma] (Y' not to be confused with Y) and still get more than decent results. This really simplifies and speeds up the implementation quite a bit without sacrificing too much.

```c
static inline unsigned int rgba_distance(
    const rgba_t a,
    const rgba_t b
)
{
    const int dr = a.r - b.r;
    const int dg = a.g - b.g;
    const int db = a.b - b.b;

    const int ddr = dr * dr; 
    const int ddg = dg * dg; 
    const int ddb = db * db; 

    return ((ddr << 1) + ddr) + (ddg << 2) + (ddb << 1); 
}
```

The original formula to get `Y'` as seen on the link above looks like this:

```c
0.299 * R + 0.587 * G + 0.114 * B
```

Notice how adding the *weights* together produces `1`.

```c
0.299 + 0.587 + 0.114 = 1.0
```

Now, we want to avoid doing 3 floating point multiplications, so we convert the *weights* into integers.

```c
2 + 5 + 1 = 8
```

This means that the formula becomes:

```c
(2 * R + 5 * G + B) / 8
```

It feels a bit heavy on the green channel and we can tweak it a bit, so we end up with:

```c
(3 * R + 4 * G + 2 * B) / 10
```

Since we only use the computed distance relative to another distance, we can safely do away with normalizing the sum, which means that we don't have to divide by 10.

With all this in place we can transform it into its final form by using only bitwise operations.

```c
((r << 1) + r) + (g << 2) + (b << 1)
```

I just want to call out that your mileage may vary, there's no absolute right or definitive way of doing this.

Hopefully, this little disclaimer seen above will be enough to dissuade anyone from denouncing me to the information superhighway color/gamma correction police and related organizations.

The interpolation (weighted average) between two pixels is also implemented with bitwise operations only.

```c
static inline rgba_t rgba_interpolate(
    const rgba_t a,
    const rgba_t b
)
{
    return (rgba_t) {
        .r = (a.r + b.r) >> 1,
        .g = (a.g + b.g) >> 1,
        .b = (a.b + b.b) >> 1,
        .a = (a.a + b.a) >> 1
    };
}
```

Take a look at the full source code below.

```c
/*
    MIT LICENSE
    Copyright (c) 2023, Mihail Szabolcs
*/
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stb.h>

#define STBI_NO_HDR
#define STBI_NO_LINEAR
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"

#ifndef UNUSED
	#define UNUSED(x) (void)(x)
#endif

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef union
{
	uint32_t value;
	struct
	{
		uint32_t r : 8;
		uint32_t g : 8;
		uint32_t b : 8;
		uint32_t a : 8;
	};
} rgba_t;

#define rgba_equal(a, b) ((a).value == (b).value)
#define rgba_not_equal(a, b) ((a).value != (b).value)

static void process(
	const rgba_t *restrict input,
	rgba_t *restrict output,
	const int iw,
	const int ih,
	const int ow,
	const int oh
);

int main(int argc, char *argv[])
{
	int w, h, bpp, ret;
	rgba_t *input, *output;

	if(argc != 3)
	{
		fprintf(stderr, "usage: %s input.png output.png\n", argv[0]);
		return EXIT_FAILURE;
	}

	input = (rgba_t *) stbi_load(argv[1], &w, &h, &bpp, sizeof(rgba_t));
	if(input == NULL)
	{
		fprintf(stderr, "failed to load input: %s\n", stbi_failure_reason());
		return EXIT_FAILURE;
	}

	output = malloc(w * 4 * h * 4 * sizeof(rgba_t));
	if(output == NULL)
	{
		fprintf(stderr, "failed to allocate memory for output image\n");
		stbi_image_free(input);
		return EXIT_FAILURE;
	}

	process(input, output, w, h, w * 4, h * 4);

	ret = stbi_write_png(
        argv[2],
        w * 4,
        h * 4,
        sizeof(rgba_t),
        output,
        w * 4 * sizeof(rgba_t)
    );
	if(ret == 0)
	{
		fprintf(stderr, "failed to write output image: '%s'\n", argv[2]);
		ret = EXIT_FAILURE;
	}
	else
	{
		fprintf(stdout, "wrote output image to '%s' ...\n", argv[2]);
		ret = EXIT_SUCCESS;
	}

	free(output);
	stbi_image_free(input);
	return ret;
}

static inline unsigned int rgba_distance(
	const rgba_t a,
	const rgba_t b
)
{
	const int dr = a.r - b.r;
	const int dg = a.g - b.g;
	const int db = a.b - b.b;

	const int ddr = dr * dr;
	const int ddg = dg * dg;
	const int ddb = db * db;

	return ((ddr << 1) + ddr) + (ddg << 2) + (ddb << 1);
}

static inline rgba_t rgba_interpolate(
	const rgba_t a,
	const rgba_t b
)
{
	return (rgba_t) {
		.r = (a.r + b.r) >> 1,
		.g = (a.g + b.g) >> 1,
		.b = (a.b + b.b) >> 1,
		.a = (a.a + b.a) >> 1
	};
}

static inline rgba_t rgba_interpolate13(
	const rgba_t a,
	const rgba_t b
)
{
	return (rgba_t) {
		.r = (a.r + ((b.r << 1) + b.r)) >> 2,
		.g = (a.g + ((b.g << 1) + b.g)) >> 2,
		.b = (a.b + ((b.b << 1) + b.b)) >> 2,
		.a = (a.a + ((b.a << 1) + b.a)) >> 2
	};
}

static inline rgba_t rgba_interpolate31(
	const rgba_t a,
	const rgba_t b
)
{
	return (rgba_t) {
		.r = (((a.r << 1) + a.r) + b.r) >> 2,
		.g = (((a.g << 1) + a.g) + b.g) >> 2,
		.b = (((a.b << 1) + a.b) + b.b) >> 2,
		.a = (((a.a << 1) + a.a) + b.a) >> 2
	};
}

static void kernel(
	const rgba_t pe,
	const rgba_t pi,
	const rgba_t ph,
	const rgba_t pf,
	const rgba_t pg,
	const rgba_t pc,
	const rgba_t pd,
	const rgba_t pb,
	const rgba_t f4,
	const rgba_t i4,
	const rgba_t h5,
	const rgba_t i5,
	rgba_t *n15,
	rgba_t *n14,
	rgba_t *n11,
	rgba_t *n3,
	rgba_t *n7,
	rgba_t *n10,
	rgba_t *n13,
	rgba_t *n12
)
{
	unsigned int e, i, ke, ki;
	bool be, bi;
	rgba_t px;

	if(rgba_equal(pe, ph) || rgba_equal(pe, pf))
		return;

    e = (
		rgba_distance(pe, pc) +
		rgba_distance(pe, pg) +
		rgba_distance(pi, h5) +
		rgba_distance(pi, f4)
	) + (rgba_distance(ph, pf) << 2);

	i = (
		rgba_distance(ph, pd) +
		rgba_distance(ph, i5) +
		rgba_distance(pf, i4) +
		rgba_distance(pf, pb)
	) + (rgba_distance(pe, pi) << 2);

	if(e >= i)
		return;

	be = (rgba_not_equal(pe, pg) && rgba_not_equal(pd, pg));
	bi = (rgba_not_equal(pe, pc) && rgba_not_equal(pb, pc));

	ke = rgba_distance(pf, pg);
	ki = rgba_distance(ph, pc);

	px = (rgba_distance(pe, pf) <= rgba_distance(pe, ph)) ? pf : ph;

	if(be && bi && ke == 0 && ki == 0)
	{
		*n13 = rgba_interpolate13(*n13, px);
		*n12 = rgba_interpolate31(*n12, px);
		*n15 = *n14 = *n11 = px;
		*n10 = *n3 = *n12;
		*n7 = *n13;
	}
	else if(be && ((ke << 2) <= ki))
	{
		*n11 = rgba_interpolate13(*n11, px);
		*n13 = rgba_interpolate13(*n13, px);
		*n10 = rgba_interpolate31(*n10, px);
		*n12 = rgba_interpolate31(*n12, px);
		*n14 = *n15 = px;
	}
	else if(bi && (ke >= (ki << 2)))
	{
		*n14 = rgba_interpolate13(*n14, px);
		*n7 = rgba_interpolate13(*n7, px);
		*n10 = rgba_interpolate31(*n10, px);
		*n3 = rgba_interpolate31(*n3, px);
		*n11 = *n15 = px;
	}
	else
	{
		*n11 = rgba_interpolate(*n11, px);
		*n14 = rgba_interpolate(*n14, px);
		*n15 = px;
	}
}

static void process(
	const rgba_t *restrict input,
	rgba_t *restrict output,
	const int iw,
	const int ih,
	const int ow,
	const int oh
)
{
	int x, y, yo, ox, oy, ihh, iww, xn1, xn2, xp1, xp2;
    int yn1, yn2, yp1, yp2, yon1, yon2, yop1, yop2;
	int oxo1, oxo2, oxo3, oyo, oyo1, oyo2, oyo3;
	rgba_t a1, b1, c1, a0, pa, pb, pc, c4, d0, pd, pe;
    rgba_t pf, f4, g0, pg, ph, pi, i4, g5, h5, i5;
	rgba_t o0, o1, o2, o3, o4, o5, o6, o7, o8, o9, oa, ob, oc, od, oe, of;

	UNUSED(oh);

	iww = iw - 1;
	ihh = ih - 1;

	for(y = 0; y < ih; y++)
	{
		yn1 = max(y - 1,   0);
		yn2 = max(y - 2,   0);
		yp1 = min(y + 1, ihh);
		yp2 = min(y + 2, ihh);

		yon1 = yn1 * iw;
		yon2 = yn2 * iw;
		yop1 = yp1 * iw;
		yop2 = yp2 * iw;

		yo = y * iw;

		oy   = y << 2;
		oyo  = oy * ow;
		oyo1 = (oy + 1) * ow;
		oyo2 = (oy + 2) * ow;
		oyo3 = (oy + 3) * ow;

		for(x = 0; x < iw; x++)
		{
			xn1 = max(x - 1,   0);
			xn2 = max(x - 2,   0);
			xp1 = min(x + 1, iww);
			xp2 = min(x + 2, iww);

			a1 = input[xn1 + yon2];
			b1 = input[  x + yon2];
			c1 = input[xp1 + yon2];

			a0 = input[xn2 + yon1];
			pa = input[xn1 + yon1];
			pb = input[  x + yon1];
			pc = input[xp1 + yon1];
			c4 = input[xp2 + yon1];

			d0 = input[xn2 + yo];
			pd = input[xn1 + yo];
			pe = input[  x + yo];
			pf = input[xp1 + yo];
			f4 = input[xp2 + yo];

			g0 = input[xn2 + yop1];
			pg = input[xn1 + yop1];
			ph = input[  x + yop1];
			pi = input[xp1 + yop1];
			i4 = input[xp2 + yop1];

			g5 = input[xn1 + yop2];
			h5 = input[  x + yop2];
			i5 = input[xp1 + yop2];

			o0 = o1 = o2 = o3 = o4 = o5 = o6 = o7 = o8 = o9 = pe;
            oa = ob = oc = od = oe = of = pe;

			kernel(
				pe, pi, ph, pf, pg, pc, pd, pb, f4, i4, h5, i5,
				&of, &oe, &ob, &o3, &o7, &oa, &od, &oc
			);
			kernel(
				pe, pc, pf, pb, pi, pa, ph, pd, b1, c1, f4, c4,
				&o3, &o7, &o2, &o0, &o1, &o6, &ob, &of
			);
			kernel(
				pe, pa, pb, pd, pc, pg, pf, ph, d0, a0, b1, a1,
				&o0, &o1, &o4, &oc, &o8, &o5, &o2, &o3
			);
			kernel(
				pe, pg, pd, ph, pa, pi, pb, pf, h5, g5, d0, g0,
				&oc, &o8, &od, &of, &oe, &o9, &o4, &o0
			);

			ox   = x << 2;
			oxo1 = ox + 1;
			oxo2 = ox + 2;
			oxo3 = ox + 3;

			output[  ox +  oyo] = o0;
			output[oxo1 +  oyo] = o1;
			output[oxo2 +  oyo] = o2;
			output[oxo3 +  oyo] = o3;
			output[  ox + oyo1] = o4;
			output[oxo1 + oyo1] = o5;
			output[oxo2 + oyo1] = o6;
			output[oxo3 + oyo1] = o7;
			output[  ox + oyo2] = o8;
			output[oxo1 + oyo2] = o9;
			output[oxo2 + oyo2] = oa;
			output[oxo3 + oyo2] = ob;
			output[  ox + oyo3] = oc;
			output[oxo1 + oyo3] = od;
			output[oxo2 + oyo3] = oe;
			output[oxo3 + oyo3] = of;
		}
	}
}

/* vim: set ts=4 sw=4 sts=4 noet: */
```

At first glance, it doesn't look very efficient now, does it? That's correct, it's stinks of branches, but it's still plenty fast as-is.

When upscaling the `house` with an original resolution of `128x256` to `512x1024`.

```bash
$ time build/xbr4x house.png house4x.png
wrote output image to 'house4x.png' ...

real 0m0.061s
user 0m0.057s
sys	 0m0.004s

$ time build/xbr4x house.png house4x.png
wrote output image to 'house4x.png' ...

real 0m0.060s
user 0m0.056s
sys	 0m0.004s

$ time build/xbr4x house.png house4x.png
wrote output image to 'house4x.png' ...

real 0m0.058s
user 0m0.054s
sys	 0m0.004s
```

When upscaling the `tileset` with an original resolution of `256x256` to `1024x1024`.

```bash
$ time build/xbr4x tileset.png tileset4x.png
wrote output image to 'tileset4x.png' ...

real 0m0.156s
user 0m0.148s
sys	 0m0.007s

$ time build/xbr4x tileset.png tileset4x.png
wrote output image to 'tileset4x.png' ...

real 0m0.147s
user 0m0.141s
sys	 0m0.005s

$ time build/xbr4x tileset.png tileset4x.png
wrote output image to 'tileset4x.png' ...

real 0m0.136s
user 0m0.124s
sys	 0m0.010s
```

There are some low-hanging fruits that one could optimize. A prime example of this would be the clamping. 

Instead of clamping to border, we could clamp to bounds.

```c
xn1 = (x - 1) % iw
yn1 = (y - 1) % ih
```

Considering the fact that we very likely going to be upscaling and working with textures, it wouldn't be too far off to suggest that we could also guarantee that their size to be power of two.

Having that little extra constraint, we could go one step further and replace the `%` with a bitwise `&`.

```c
xn1 = (x - 1) & (iw - 1)In this day and age however 
yn1 = (y - 1) & (ih - 1)
```

This works because `P % N == P & (N -1)`, only when `N` is power of two.

On the other hand, we could also eliminate the need for clamping altogether by adding a 2 pixel wide border around the input image, which would guarantee that we never sample out of bounds.

At any rate this implementation is not something that you would be using in real-time, but rather offline as part of your asset pipeline or at run-time when loading your assets.

The second scenario could come in especially handy on platforms where the initial download size still matters, like the web or mobile.

It would also open the door to upscale once on load and then persist the results to disk and subsequent runs could just use the upscaled versions of the assets. Of course special care would have to be taken to invalidate the cache on asset updates, etc.

I'll have to take a look at machine learning based upscaling at some point or another and see how something like that fairs compared to something with a handcrafted kernel like xbr4x.

[paper]: https://johanneskopf.de/publications/pixelart/
[forum]: https://forums.getpaint.net/topic/23601-2d-image-scaling-algorithms/
[tinyswords]: https://pixelfrog-assets.itch.io/tiny-swords
[pixelfrog]: https://pixelfrog-assets.itch.io/
[dct]: https://opengameart.org/content/dungeon-crawl-32x32-tiles
[dcss]: https://crawl.develz.org/
[xbr]: https://en.wikipedia.org/wiki/Pixel-art_scaling_algorithms#xBR_family
