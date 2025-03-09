---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2023
title: Generating Voronoi Noise
year: 2023
monthly: false
propaganda: 9
topic: c
---

Generating Voronoi Noise
=========================

[Voronoi Diagrams][voronoidia] always seemed to me like a weird stepchild of [noise][noise] and [signed distance fields][sdf].

The process of creating a Voronoi diagram is not terribly complicated and it consists of two steps:

1. Pick N random points and colors
2. For each pixel find the closest point relative to it and use its color
3. Profit!

Talk is cheap, so let's take a look at the code, starting with the first step of picking N random points and colors as one might expect.

```c
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

typedef struct
{
    int x;
    int y;
    rgba_t rgba;
} point_t;

static void randomize(
    point_t *points,
    const int n,
    const int w,
    const int h,
    const unsigned int seed
)
{
    point_t *p, *e;

    const int ww = w - 16;
    const int hh = h - 16;

    srand(seed);

    for(p = points, e = points + n; p != e; p++)
    {
        p->x = (rand() % ww) + 8;
        p->y = (rand() % hh) + 8;
        p->rgba = (rgba_t) {
            .r = ((rand() & 127) + 64),
            .g = ((rand() & 127) + 32),
            .b = ((rand() & 127) + 64),
            .a = 0xFF
        };
    }
}
```

And then the actual part where the magic happens.

```c
static inline unsigned int distance(
    const point_t *p,
    const int x,
    const int y
)
{
    const int dx = p->x - x;
    const int dy = p->y - y;
    return dx * dx + dy * dy;
}

static void process(
    const point_t *points,
    const int n,
    rgba_t *restrict output,
    const int w,
    const int h
)
{
    int x, y, yo;
    unsigned int d, cd;
    const point_t *cp, *p, *e = points + n;

    for(y = 0; y < h; y++)
    {
        yo = y * w;

        for(x = 0; x < w; x++)
        {
            cd = UINT_MAX;
            cp = points;

            for(p = points; p != e; p++)
            {
                d = distance(p, x, y);
                if(d < cd)
                {
                    cd = d;
                    cp = p;
                }
            }

            output[x + yo] = cp->rgba;
        }
    }
}
```

*Voilà*!

![voronoi](/media/2023/voronoi.png)

## Worley Noise

What if instead of using random colors we used the distance to the point as the actual color?

That's exactly what the so called [Worley Noise][worleynoise] is all about.

Before taking a look at the code, let's see the results first in order to switch things up a wee bit.

![voronoiw](/media/2023/voronoiw.png)

The modifications to the `process` function can be seen below. The only thing worth calling out is the fact that we only take the `sqrt` of the distance once, which is still going to be expensive but it's not end of the world.

```c
static void process(
	const point_t *points,
	const int n,
	rgba_t *restrict output,
	const int w,
	const int h
)
{
	int x, y, yo;
	unsigned int d, cd;
	const point_t *p, *e = points + n;

	for(y = 0; y < h; y++)
	{
		yo = y * w;

		for(x = 0; x < w; x++)
		{
			cd = UINT_MAX;

			for(p = points; p != e; p++)
			{
				d = distance(p, x, y);
				if(d < cd)
				{
					cd = d;
				}
			}

			cd = sqrt(cd);
			output[x + yo] = (rgba_t) {
				.r = cd,
				.g = cd,
				.b = cd,
				.a = 0xFF
			};
		}
	}
}
```

Obviously, instead of picking random points, we could also place points on a grid an then simply displace them in order to have more fine grained control. Also, the distance could be manipulated in a gazillion ways in order to customize and alter the output even further.

Let's take a quick look at what happens if we apply a simple step function.

```c
#define step(a, b) ((a) < (b) ? 0 : 1)

cd = step(64, cd) * 0xFF;
```

![voronows](/media/2023/voronows.png)

[Metaballs][metaballs] anyone?

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
#include <limits.h>
#include <math.h>
#include <time.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#ifndef UNUSED
	#define UNUSED(x) (void)(x)
#endif

#define DEFAULT_SIZE 1024
#define DEFAULT_NUM_POINTS 64

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define clamp(x, a, b) max(a, min(b, x))
#define step(a, b) ((a) < (b) ? 0 : 1)

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

typedef struct
{
	int x;
	int y;
#ifdef COLORS
	rgba_t rgba;
#endif
} point_t;

static void randomize(
	point_t *points,
	const int n,
	const int w,
	const int h,
	const unsigned int seed
);

static void process(
	const point_t *points,
	const int n,
	rgba_t *restrict output,
	const int w,
	const int h
);

int main(int argc, char *argv[])
{
	int w, h, n, ret;
	unsigned int seed;
	rgba_t *output;
	point_t *points;

	if(argc < 2)
	{
		fprintf(
        	stderr,
            "usage: %s output.png [[size] [num points] [seed]]\n",
            argv[0]
        );
		return EXIT_FAILURE;
	}

	if(argc > 2)
	{
		w = clamp(atoi(argv[2]), 64, 4096);
		h = w;
	}
	else
	{
		w = DEFAULT_SIZE;
		h = DEFAULT_SIZE;
	}

	if(argc > 3)
		n = clamp(atoi(argv[3]), 1, 4096);
	else
		n = DEFAULT_NUM_POINTS;

	if(argc > 4)
		seed = atoi(argv[4]);
	else
		seed = time(NULL);

	output = malloc(w * h * sizeof(rgba_t));
	if(output == NULL)
	{
		fprintf(stderr, "failed to allocate memory for output image\n");
		return EXIT_FAILURE;
	}

	points = malloc(n * sizeof(point_t));
	if(points == NULL)
	{
		fprintf(stderr, "failed to allocate memory for pointsn");
		free(output);
		return EXIT_FAILURE;
	}

	randomize(points, n, w, h, seed);
	process(points, n, output, w, h);

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

	free(points);
	free(output);
	return ret;
}

static void randomize(
	point_t *points,
	const int n,
	const int w,
	const int h,
	const unsigned int seed
)
{
	point_t *p, *e;

	const int ww = w - 16;
	const int hh = h - 16;

	srand(seed);

	for(p = points, e = points + n; p != e; p++)
	{
		p->x = (rand() % ww) + 8;
		p->y = (rand() % hh) + 8;
#ifdef COLORS
		p->rgba = (rgba_t) {
			.r = ((rand() & 127) + 64),
			.g = ((rand() & 127) + 32),
			.b = ((rand() & 127) + 64),
			.a = 0xFF
		};
#endif
	}
}

static inline unsigned int distance(
	const point_t *p,
	const int x,
	const int y
)
{
	const int dx = p->x - x;
	const int dy = p->y - y;
	return dx * dx + dy * dy;
}

static void process(
	const point_t *points,
	const int n,
	rgba_t *restrict output,
	const int w,
	const int h
)
{
	int x, y, yo;
	unsigned int d, cd;
	const point_t *p, *e = points + n;
#ifdef COLORS
	const point_t *cp;
#endif

	for(y = 0; y < h; y++)
	{
		yo = y * w;

		for(x = 0; x < w; x++)
		{
			cd = UINT_MAX;
#ifdef COLORS
			cp = points;
#endif

			for(p = points; p != e; p++)
			{
				d = distance(p, x, y);
				if(d < cd)
				{
					cd = d;
#ifdef COLORS
					cp = p;
#endif
				}
			}

#ifdef COLORS
			output[x + yo] = cp->rgba;
#else
			cd = sqrt(cd);

			// cd = step(STEP, cd) * 0xFF;

			output[x + yo] = (rgba_t) {
				.r = cd,
				.g = cd,
				.b = cd,
				.a = 0xFF
			};
#endif
		}
	}
}

/* vim: set ts=4 sw=4 sts=4 noet: */
```

[metaballs]: https://en.wikipedia.org/wiki/Metaballs
[worleynoise]: https://en.wikipedia.org/wiki/Worley_noise
[voronoidia]: https://en.wikipedia.org/wiki/Voronoi_diagram
[noise]: https://en.wikipedia.org/wiki/Value_noise
[sdf]: https://steamcdn-a.akamaihd.net/apps/valve/2007/SIGGRAPH2007_AlphaTestedMagnification.pdf
