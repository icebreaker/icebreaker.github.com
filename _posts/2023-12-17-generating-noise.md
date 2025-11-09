---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2023
title: Generating Noise
propaganda: 33
class: blood poltergeist
tags: c
---

Generating Noise
=========================

In my previous post I talked about [generating voronoi noise][voronoinoise], but when the subject of noise comes up, most people tend to think of [perlin noise][perlinnoise] or [simplex noise][simplexnoise] rather than anything else.

However, one doesn't have to go that fancy to get relatively decent results. But, without any further ado, let's dive into it and explore the world of noise.

To start things off on the right foot, let's generate some good old static noise.

```c
static void process(
    rgba_t *restrict output,
    const int w,
    const int h
)
{
    int i, n, c;

    for(i = 0, n = w * h; i < n; i++)
    {
        c = rand() & 0xFF;
        output[i] = (rgba_t) {
            .r = c,
            .g = c,
            .b = c,
            .a = 0xFF
        };
    }
}
```

![noise](/media/2023/noise.png)

Do not worry, there's no [poltergeist][poltergeistmovie] coming through if you stare at it for too long. I pinky promise.

Let's see what happens if we blur this by simply taking the average of the surrounding pixels.

```c
static void randomize(
    rgba_t *restrict output,
    const int w,
    const int h,
    const unsigned int seed
)
{
    int i, n, c;

    srand(seed);

    for(i = 0, n = w * h; i < n; i++)
    {
        c = rand() & 0xFF;
        output[i] = (rgba_t) {
            .r = c,
            .g = c,
            .b = c,
            .a = 0xFF
        };
    }
}

static void process(
    rgba_t *restrict output,
    const int w,
    const int h
)
{
    int x, y, yo, you, yod, ww, hh;
    uint32_t c;
    rgba_t cu, cd, cl, cr;

    ww = w - 1;
    hh = h - 1;

    for(y = 0; y < h; y++)
    {
        yo  = y * w;
        you = max(y - 1,  0) * w;
        yod = min(y + 1, hh) * w;

        for(x = 0; x < w; x++)
        {
            cu = output[x + you];
            cd = output[x + yod];
            cl = output[max(x - 1,  0) + yo];
            cr = output[min(x + 1, ww) + yo];

            c = (cu.r + cd.r + cl.r + cr.r) >> 2;

            output[x + yo] = (rgba_t) {
                .r = c,
                .g = c,
                .b = c,
                .a = 0xFF
            };
        }
    }
}
```

![noiseb](/media/2023/noiseb.png)

This works best with a relatively small size and at least 4 passes of blur.

```c
w = 128;
h = 128;

randomize(output, w, h, seed);

for(i = 0; i < 4; i++)
	process(output, w, h);
```

Now that is not too shabby, but we can do better than that, but first we'll divorce the randomization from the output image and fill out a separate array with values in the range of `[0, 255]`.

```c
static void randomize(
    uint8_t *restrict noise,
    const int w,
    const int h,
    const unsigned int seed
)
{
    int i, n;

    srand(seed);

    for(i = 0, n = w * h; i < n; i++)
        noise[i] = rand() & 0xFF;
}
```

Then we modify the processing portion to sample N pixels around the current pixel in the range of `[-N/2, +N/2]`.

```c
static void process(
	const uint8_t *restrict noise,
	rgba_t *restrict output,
	const int w,
	const int h,
	const int num_samples
)
{
	int i, x, y, xx, yy, yo, ww, hh, num_samples;
	uint32_t c, cc;
	float num_samples;

	ww = w - 1;
	hh = h - 1;

	half_num_samples = num_samples >> 1;
	inv_num_samples = 1.0f / (num_samples << 1);

	for(y = 0; y < h; y++)
	{
		yo = y * w;

		for(x = 0; x < w; x++)
		{
			cc = 0;

			for(i = -half_num_samples; i <= half_num_samples; i++)
			{
				xx = clamp(x + i, 0, ww);
				yy = clamp(y + i, 0, hh);

				cc += noise[xx +  y * w];
				cc += noise[x  + yy * w];
			}

			c = cc * inv_num_samples;

			output[x + yo] = (rgba_t) {
				.r = c,
				.g = c,
				.b = c,
				.a = 0xFF
			};
		}
	}
}
```

![noise](/media/2023/noises.png)

Not bad, not terrible! But, sadly it's not the noise we are looking for.

Let's combine the two techniques into one and see if we can get closer to the kind of noise that we are looking for. Namely, something more akin to what one gets with those *"noise cloud"* type filters in amazing programs like photoshop or gimp. I am sure that you know what I am talking about.

```c
#define NOISE_MAX (1 << 14)
#define NOISE_MAX_MASK (NOISE_MAX - 1)
#define NOISE_MAX_MASK_INV (1.0f / (float) NOISE_MAX_MASK)

static void randomize(
    float *restrict noise,
    const int w,
    const int h,
    const unsigned int seed
)
{
    int i, n;

    srand(seed);

    for(i = 0, n = w * h; i < n; i++)
        noise[i] = (rand() & NOISE_MAX_MASK) * NOISE_MAX_MASK_INV;
}

#define fract(a) ((a) - ((int)(a)))
#define lerp(a, b, t) ((1 - (t)) * (a) + (t) * (b))

static void process(
	const float *restrict noise,
	rgba_t *restrict output,
	const int w,
	const int h,
	const int num_samples
)
{
	int x, y, i, xx0, yy0, xx1, yy1, yyo0, yyo1, yo, ww, hh;
	float inv_num_samples, inv_scale, xx, yy, fx, fy;
    float ac, v0, v1, c, c0, c1, c2, c3;

	ww = w - 1;
	hh = h - 1;

	inv_num_samples = 127.0f / (float) num_samples;

	for(y = 0; y < h; y++)
	{
		yo = y * w;

		for(x = 0; x < w; x++)
		{
			ac = 0;

			for(i = 1; i <= num_samples; i <<= 1)
			{
                inv_scale = 1.0f / (float) i;

				xx = x * inv_scale;
				yy = y * inv_scale;

				xx0 = ((int) xx) & ww;
				yy0 = ((int) yy) & hh;

				xx1 = (xx0 + 1) & ww;
				yy1 = (yy0 + 1) & hh;

				yyo0 = yy0 * w;
				yyo1 = yy1 * w;

				c0 = noise[xx0 + yyo0];
				c1 = noise[xx1 + yyo0];
				c2 = noise[xx0 + yyo1];
				c3 = noise[xx1 + yyo1];

				fx = fract(xx);
				fy = fract(yy);

				v0 = lerp(c0, c1, fx);
				v1 = lerp(c2, c3, fx);

				ac += lerp(v0, v1, fy) * i;
			}

			c = ac * inv_num_samples;

			output[x + yo] = (rgba_t) {
				.r = c,
				.g = c,
				.b = c,
				.a = 0xFF
			};
		}
	}
}
```

First, we changed the `randomize` function to generate random floating point values in the range of `[0,1]` in order to increase accuracy and simplify things down the line.

Second, we now sample from `[1, num_samples]` in increments of powers of two. In other words, if `num_samples = 128`, then we end up sampling `[1, 2, 4, 8, 16, 32, 64, 128]`.

Third, we scale the `x` and `y` coordinates by the current sample size. We could avoid the lonely division there, but it's not end of the world since everything else is using multiplications and additions.

I am talking about this portion of the code of course, in case you've been scratching your head.

```c
inv_scale = 1.0f / (float) i;

xx = x * inv_scale;
yy = y * inv_scale;
```

Forth, instead of simply taking the mean average of the surrounding pixels we perform bilinear interpolation, which is just a fancy word for linearly interpolating on the `x` and `y` axis at the same time.

Let's take a deeper dive into this because this is really the most interesting part and it's also where the so called magic happens.

```c
xx0 = ((int) xx) & ww;
yy0 = ((int) yy) & hh;

xx1 = (xx0 + 1) & ww;
yy1 = (yy0 + 1) & hh;

yyo0 = yy0 * w;
yyo1 = yy1 * w;

c0 = noise[xx0 + yyo0];
c1 = noise[xx1 + yyo0];
c2 = noise[xx0 + yyo1];
c3 = noise[xx1 + yyo1];

fx = fract(xx);
fy = fract(yy);

v0 = lerp(c0, c1, fx);
v1 = lerp(c2, c3, fx);

ac += lerp(v0, v1, fy) * i;
```

I know that it looks a bit intimidating, but it's simpler than it looks as we'll see in a second and basically it boils down to the following operations:

1. clamp `x0` and `y0`
2. offset `x0` and `y0` by `+1` and clamp each
3. sample the noise at the following coordinates:
	1. `[x0, y0]`
	2. `[x1, y0]`
	3. `[x0, y1]`
	4. `[x1, y1]`
4. interpolate `[x0, y0]` and `[x1, y0]` by using `t = fract(xx)`
5. interpolate `[x0, y1]` and `[x1, y1]` by using `t = fract(xx)`
6. interpolate the result of the two previous interpolations by using `t = fract(yy)`
7. scale the result of the interpolation by the current sample size; `lerp * i`
8. accumulate the result into `ac`

Last by not least, we normalize the accumulated result and bring it into the `[0, 127]` range.

```c
c = ac * inv_num_samples;
```

If we expand this, we get the expression seen below; which of course has an unnecessary division.

```c
c = 127 * ac / num_samples;
```

That's all. Anyway, let's see what we get if we execute this by using the following values.

| variable    | value   |
| ----------- | ------- |
| w           | 1024    |
| h           | 1024    |
| num_samples | 128     |
| seed        | 4213666 |

![noisebi](/media/2023/noisebi.png)

Voilà! Not as nice as good old perlin noise or its friends, but it's something that one can throw together without too much fuss in a couple of minutes and it's reasonably cheap in terms of speed.

## Benchmark

```bash
$ time noise noise.png 1024 128 4213666
wrote output image to 'noise.png' ...

real    0m0.279s
user    0m0.268s
sys     0m0.010s

$ time noise noise.png 1024 128 4213666
wrote output image to 'noise.png' ...

real    0m0.271s
user    0m0.263s
sys     0m0.007s

$ time noise noise.png 1024 128 4213666
wrote output image to 'noise.png' ...

real    0m0.271s
user    0m0.266s
sys     0m0.005s
```

## Source Code

You can find the full source code below as per usual.

```c
/*
    MIT LICENSE
    Copyright (c) 2023, Mihail Szabolcs
*/
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#ifndef UNUSED
	#define UNUSED(x) (void)(x)
#endif

#ifndef DEFAULT_SIZE
	#define DEFAULT_SIZE 1024
#endif

#ifndef DEFAULT_NUM_SAMPLES
	#define DEFAULT_NUM_SAMPLES 128
#endif

#define NOISE_MAX (1 << 14)
#define NOISE_MAX_MASK (NOISE_MAX - 1)
#define NOISE_MAX_MASK_INV (1.0f / (float) NOISE_MAX_MASK)

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define clamp(x, a, b) max(a, min(b, x))
#define fract(a) ((a) - ((int)(a)))
#define lerp(a, b, t) ((1 - (t)) * (a) + (t) * (b))

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

static void randomize(
	float *restrict output,
	const int w,
	const int h,
	const unsigned int seed
);

static void process(
	const float *restrict noise,
	rgba_t *restrict output,
	const int w,
	const int h,
	const int num_samples
);

int main(int argc, char *argv[])
{
	int w, h, num_samples, ret;
	unsigned int seed;
	float *noise;
	rgba_t *output;

	if(argc < 2)
	{
		fprintf(
            stderr,
            "usage: %s output.png [[size] [num_samples] [seed]]\n",
            argv[0]
        );
		return EXIT_FAILURE;
	}

	if(argc > 2)
	{
		w = clamp(atoi(argv[2]), 16, 8192);
		h = w;
	}
	else
	{
		w = DEFAULT_SIZE;
		h = DEFAULT_SIZE;
	}

	if(argc > 3)
		num_samples = clamp(atoi(argv[3]), 1, 4096);
	else
		num_samples = DEFAULT_NUM_SAMPLES;

	if(argc > 4)
		seed = atoi(argv[4]);
	else
		seed = time(NULL);

	noise = malloc(w * h * sizeof(float));
	if(noise == NULL)
	{
		fprintf(stderr, "failed to allocate memory for output image\n");
		return EXIT_FAILURE;
	}

	output = malloc(w * h * sizeof(rgba_t));
	if(output == NULL)
	{
		free(noise);
		fprintf(stderr, "failed to allocate memory for output image\n");
		return EXIT_FAILURE;
	}

	randomize(noise, w, h, seed);
	process(noise, output, w, h, num_samples);

	ret = stbi_write_png(
        argv[1],
        w,
        h,
        sizeof(rgba_t),
        output,
        w * sizeof(rgba_t)
    );
	if(ret == 0)
	{
		fprintf(stderr, "failed to write output image: '%s'\n", argv[1]);
		ret = EXIT_FAILURE;
	}
	else
	{
		fprintf(stdout, "wrote output image to '%s' ...\n", argv[1]);
		ret = EXIT_SUCCESS;
	}

	free(output);
	free(noise);
	return ret;
}

static void randomize(
	float *restrict noise,
	const int w,
	const int h,
	const unsigned int seed
)
{
	int i, n;

	srand(seed);

	for(i = 0, n = w * h; i < n; i++)
		noise[i] = (rand() & NOISE_MAX_MASK) * NOISE_MAX_MASK_INV;
}

static void process(
	const float *restrict noise,
	rgba_t *restrict output,
	const int w,
	const int h,
	const int num_samples
)
{
	int x, y, i, xx0, yy0, xx1, yy1, yyo0, yyo1, yo, ww, hh;
	float inv_num_samples, inv_scale, xx, yy, fx, fy;
    float ac, v0, v1, c, c0, c1, c2, c3;

	ww = w - 1;
	hh = h - 1;

	inv_num_samples = 127.0f / (float) num_samples;

	for(y = 0; y < h; y++)
	{
		yo = y * w;

		for(x = 0; x < w; x++)
		{
			ac = 0;

			for(i = 1; i <= num_samples; i <<= 1)
			{
				inv_scale = 1.0f / (float) i;

				xx = x * inv_scale;
				yy = y * inv_scale;

				xx0 = ((int) xx) & ww;
				yy0 = ((int) yy) & hh;

				xx1 = (xx0 + 1) & ww;
				yy1 = (yy0 + 1) & hh;

				yyo0 = yy0 * w;
				yyo1 = yy1 * w;

				c0 = noise[xx0 + yyo0];
				c1 = noise[xx1 + yyo0];
				c2 = noise[xx0 + yyo1];
				c3 = noise[xx1 + yyo1];

				fx = fract(xx);
				fy = fract(yy);

				v0 = lerp(c0, c1, fx);
				v1 = lerp(c2, c3, fx);

				ac += lerp(v0, v1, fy) * i;
			}

			c = ac * inv_num_samples;

			output[x + yo] = (rgba_t) {
				.r = c,
				.g = c,
				.b = c,
				.a = 0xFF
			};
		}
	}
}

/* vim: set ts=4 sw=4 sts=4 noet: */
```

[poltergeistmovie]: https://en.wikipedia.org/wiki/Poltergeist_(1982_film)
[voronoinoise]: /2023/12/06/generating-voronoi-noise/
[perlinnoise]: https://en.wikipedia.org/wiki/Perlin_noise
[simplexnoise]: https://en.wikipedia.org/wiki/Simplex_noise
