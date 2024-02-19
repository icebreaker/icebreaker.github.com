---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2024
title: Image Kernels
imagediffviewer: true
propaganda: 42
class: blood
---

Image Kernels
=========================

I built quite a lot of utilities last year that did image processing in some form or another. However, whenever I've written about them, I purposely avoided using the terms *kernel* and *convolution*. Why? Simply speaking, to save the unsuspecting AI bros from wetting their pants too much.

So, what are convolution kernels or filters exactly? These fancy words are used to describe an `NxN` matrix of *weights*. Is that it? Yes, nothing more and nothing less.

```c
const float kernel[9] = {
  0, 0, 0,
  0, 1, 0,
  0, 0, 0
};
```

Kernels can be of various sizes, but one of the most common ones that you'll see in the wild is composed of 9 elements which can be represented by a `3x3` matrix.

This is all useful information, I guess, but how does one use such a kernel? Oh, it's easy peasy lemon squeezy and boils down to the following steps:

1. for every pixel in an image
2. sample the surrounding 8 pixels; the current pixel is in the center
3. multiply each sampled pixel with the corresponding weight from the kernel
4. sum up the results

If you are asking yourself if I just wasted 30 seconds of your life to describe doing a `dot product` in a very backhanded way;  then you are absolutely right!

It's a `dot product` with two vectors that have 9 elements or components each. Let's take a look at the code to demystify this further.

```c
const float kernel[9] = {
  0, 0, 0,
  0, 1, 0,
  0, 0, 0
};

const rgba_t samples[9] = { ... };

float sum = 0.0f;

for(int i = 0; i < 9; i++)
	sum += samples[i].r * kernel[i];
```

Often times, a so called `factor` and a `bias` are applied to the `sum`. More fancy words, huh?

```c
sum = sum * factor + bias;
```

While optional, these can help fine-tune the results. For instance if one wanted to halve the intensity of the results, one could simply set the `factor` to `0.5`.

Talk is cheap, so let's take a look at applying a so called `emboss kernel` and check out the results.

```c
const float emboss_kernel[9] = {
	-2, -1, 0,
	-1,  1, 1,
     0,  1, 2
};
```

<div class="image-diff-viewer">
<img src="/media/2024/skeksisbw.png" />
<img src="/media/2024/skeksisbwemboss.png" />
</div>

Not too shabby right? But what about colors? Instead of applying the kernel to only one channel, it's possible to apply it red, green and blue at the same time.

```c
const float kernel[9] = {
	-2, -1, 0,
	-1,  1, 1,
     0,  1, 2
};

const rgba_t samples[9] = { ... };

float r = 0.0f;
float g = 0.0f;
float b = 0.0f;

for(int i = 0; i < 9; i++)
{
	r += samples[i].r * kernel[i];
    g += samples[i].g * kernel[i];
    b += samples[i].b * kernel[i];
}
```

<div class="image-diff-viewer">
<img src="/media/2024/skeksis.png" />
<img src="/media/2024/skeksisemboss.png" />
</div>

Before we take a look at the full source code, let's awe a gander at another shiny kernel that results in a rough outline.

```c
const float outline_kernel[9] = {
	-1, -1, -1,
	-1,  8, -1,
    -1, -1, -1
};
```

In order to spice things up a little bit even more, let's also set the `factor` to a value of `2` this time.

<div class="image-diff-viewer">
<img src="/media/2024/skeksisbw.png" />
<img src="/media/2024/skeksisbwoutline.png" />
</div>

## Source Code

You can find the full source code below as per usual.

```c
/*
	MIT LICENSE
	Copyright (c) 2024, Mihail Szabolcs
*/
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <math.h>

#define STBI_NO_HDR
#define STBI_NO_LINEAR
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"

#ifndef UNUSED
	#define UNUSED(x) (void)(x)
#endif

#ifndef BORDER_SIZE
	#define BORDER_SIZE 1
#endif

#ifndef KERNEL_SIZE
	#define KERNEL_SIZE 9
#endif

#define clampf(a, min, max) fmax(min, fmin(max, a))
#define grayscale(c) (((((c).r << 1) + (c).r) + ((c).g << 2) + (c).b) >> 3)

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

static void convert(
	rgba_t *image,
	const int w,
	const int h
);

static void copy(
	const rgba_t *restrict input,
	rgba_t *restrict output,
	const int iw,
	const int ih,
	const int ow,
	const int oh
);

static void process(
	const rgba_t *restrict input,
	rgba_t *restrict output,
	const int w,
	const int h,
	const float kernel[KERNEL_SIZE],
	const float factor,
	const float bias
);

int main(int argc, char *argv[])
{
	int w, h, ibw, ibh, bpp, ret;
	float factor, bias, kernel[KERNEL_SIZE] = { 0, 0, 0, 0, 1, 0, 0, 0, 0 };
	bool grayscale;
	rgba_t *input, *input_border, *output;

	if(argc < 3)
	{
		fprintf(
            stderr,
            "usage: %s input.png output.png [arguments]\n\n",
            argv[0]
        );
		fprintf(stderr, "arguments:\n");
		fprintf(stderr, "--kernel    - specify kernel matrix\n");
		fprintf(stderr, "--factor    - specify kernel factor\n");
		fprintf(stderr, "--bias      - specify kernel bias\n");
		fprintf(stderr, "--grayscale - convert input image to grayscale\n");
		return EXIT_FAILURE;
	}

	grayscale = false;
	factor = 1.0f;
	bias = 0.0f;

	for(int i = 3; i < argc; i++)
	{
		if(!strcmp(argv[i], "--kernel") && i + 1 < argc)
		{
			ret = sscanf(
				argv[++i],
				"(%f,%f,%f,%f,%f,%f,%f,%f,%f)",
				&kernel[0],
				&kernel[1],
				&kernel[2],
				&kernel[3],
				&kernel[4],
				&kernel[5],
				&kernel[6],
				&kernel[7],
				&kernel[8]
			);
			if(ret != KERNEL_SIZE)
			{
				fprintf(
                    stderr,
                    "error: --kernel is invalid\n"
                );
				return EXIT_FAILURE;
			}
		}
		else if(!strcmp(argv[i], "--factor") && i + 1 < argc)
		{
			factor = atof(argv[++i]);
		}
		else if(!strcmp(argv[i], "--bias") && i + 1 < argc)
		{
			bias = atof(argv[++i]);
		}
		else if(!strcmp(argv[i], "--grayscale"))
		{
			grayscale = true;
		}
		else
		{
			fprintf(
                stderr,
                "error: invalid argument '%s' or argument value\n",
                argv[i]
            );
			return EXIT_FAILURE;
		}
	}

	input = (rgba_t *) stbi_load(argv[1], &w, &h, &bpp, sizeof(rgba_t));
	if(input == NULL)
	{
		fprintf(stderr, "failed to load input: %s\n", stbi_failure_reason());
		return EXIT_FAILURE;
	}

	ibw = w + (BORDER_SIZE << 1);
	ibh = h + (BORDER_SIZE << 1);

	input_border = malloc(ibw * ibh * sizeof(rgba_t));
	if(input_border == NULL)
	{
		fprintf(
            stderr,
            "failed to allocate memory for input image with border\n"
        );
		stbi_image_free(input);
		return EXIT_FAILURE;
	}

	output = malloc(ibw * ibh * sizeof(rgba_t));
	if(output == NULL)
	{
		fprintf(stderr, "failed to allocate memory for output image\n");
		free(input_border);
		stbi_image_free(input);
		return EXIT_FAILURE;
	}

	if(grayscale)
	{
		convert(input, w, h);
		fprintf(stdout, "converted input image to grayscale ...\n");
	}

	copy(input, input_border, w, h, ibw, ibh);

	stbi_image_free(input);
	input = input_border;

	process(input, output, ibw, ibh, kernel, factor, bias);

	ret = stbi_write_png(
		argv[2],
		w,
		h,
		sizeof(rgba_t),
		output + BORDER_SIZE + (BORDER_SIZE * ibw),
		ibw * sizeof(rgba_t)
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
	free(input);
	return ret;
}

static void convert(
	rgba_t *image,
	const int w,
	const int h
)
{
	uint32_t a;
	rgba_t c;

	for(int i = 0, s = w * h; i < s; i++)
	{
		c = image[i];

		a = grayscale(c);
		c.r = a;
		c.g = a;
		c.b = a;

		image[i] = c;
	}
}

static void copy(
	const rgba_t *restrict input,
	rgba_t *restrict output,
	const int iw,
	const int ih,
	const int ow,
	const int oh
)
{
	memset(output, 0, ow * oh * sizeof(rgba_t));

	output = output + BORDER_SIZE + ow * BORDER_SIZE;

	for(int y = 0; y < ih; y++)
	{
		memcpy(output, input, iw * sizeof(rgba_t));
		input += iw;
		output += ow;
	}
}

static void process(
	const rgba_t *restrict input,
	rgba_t *restrict output,
	const int w,
	const int h,
	const float kernel[KERNEL_SIZE],
	const float factor,
	const float bias
)
{
	float r, g, b, k;
	rgba_t s, samples[KERNEL_SIZE];

	for(int y = BORDER_SIZE; y < h - BORDER_SIZE; y++)
	{
		const int yo  = y * w;
		const int you = (y - 1) * w;
		const int yod = (y + 1) * w;

		for(int x = BORDER_SIZE; x < w - BORDER_SIZE; x++)
		{
			const int xl = x - 1;
			const int xr = x + 1;

			samples[0] = input[xl + you]; // -1, -1
			samples[1] = input[ x + you]; //  0, -1
			samples[2] = input[xr + you]; //  1, -1
			samples[3] = input[xl +  yo]; // -1,  0
			samples[4] = input[ x +  yo]; //  0,  0
			samples[5] = input[xr +  yo]; //  1,  0
			samples[6] = input[xl + yod]; // -1,  1
			samples[7] = input[ x + yod]; //  0,  1
			samples[8] = input[xr + yod]; //  1,  1

			r = 0.0f;
			g = 0.0f;
			b = 0.0f;

			for(int i = 0; i < KERNEL_SIZE; i++)
			{
				s = samples[i];
				k = kernel[i];

				r += s.r * k;
				g += s.g * k;
				b += s.b * k;
			}

			r = r * factor + bias;
			g = g * factor + bias;
			b = b * factor + bias;

			r = clampf(r, 0, 255);
			g = clampf(g, 0, 255);
			b = clampf(b, 0, 255);

			output[x + yo] = (rgba_t) {
				.r = r,
				.g = g,
				.b = b,
				.a = 0xFF
			};
		}
	}
}

/* vim: set ts=4 sw=4 sts=4 noet: */
```

I am happy to report that no [Skeksis][skeksis] has been harmed during the writing of this blog post. Hopefully this little disclaimer puts your mind at ease. This is a safe and very inclusive place.

[skeksis]: https://en.wikipedia.org/wiki/Skeksis
