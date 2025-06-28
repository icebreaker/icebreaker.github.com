---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2023
title: 2023 April Retrospective
year: 2023
monthly: true
propaganda: 2
tags: retrospective
---

2023 April Retrospective
=========================

April came and went like the wind, but I finally did end up posting about [USD][usd] which can you peruse at your own leisure by clicking [here][usdhere].

## Marmota

I rambled about [Marmota][marmota] in the past, but in case you were living under a rock and don't know what it is, here's a quick refresher.

[Marmota][marmota] is a tiny terminal emulator that I've cobbled together which uses [libvte][libvte] to do al the hard work when it comes to actual terminal emulation.

It's been my daily driver ever since I released it and I ended up adding a couple of additional features to it in the months and years since its inception.

Some of these were simply quality of life type features, like the ability to zoom-in-and-out at runtime; while others were absolutely non-essential, like the ability to set a background image.

When it comes to configuration, all settings are compiled into the executable at compile time in traditional [suckless.org][suckless] style, however a couple of them can be overridden via the means of command line arguments.

### Background Image

The `-background` and `-background-opacity` are one of these, which can come handy if you fancy setting the background and its opacity at runtime. Perhaps even in a randomized fashion, or whatever.

Images with abstract patterns and dark color palettes work best, because you don't want to be stare at something that is too distracting or too light which makes the text difficult to read.

In addition I found that images which fade to black, from right to left, also seem to work fairly well.

Take this image of a chimpanzee from the article "[Chimpanzee Rights Get a Day in Court][chimpanzee]" by Wired.

![chimpanzee](/media/2023/chimpanzee.png)

Doing this by hand in your favorite Image Editor is probably going to get boring very fast, even if you do try to script it, so I ended up writing a small utility that can do this without too much hassle.

```c
/*
	MIT LICENSE
	Copyright (c) 2023, Mihail Szabolcs
*/
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>

#define STBI_NO_HDR
#define STBI_NO_LINEAR
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"
#include "stb_image_resize.h"

#ifndef UNUSED
	#define UNUSED(x) (void)(x)
#endif

#ifndef DEFAULT_OUTPUT_IMAGE_WIDTH
	#define DEFAULT_OUTPUT_IMAGE_WIDTH 1920
#endif

#ifndef DEFAULT_OUTPUT_IMAGE_HEIGHT
	#define DEFAULT_OUTPUT_IMAGE_HEIGHT 1080
#endif

typedef union
{
	uint32_t rgba;
	struct
	{
		uint32_t r : 8;
		uint32_t g : 8;
		uint32_t b : 8;
		uint32_t a : 8;
	};
} rgba_t;

#define resize_image(input, iw, ih, output, ow, oh) \
	stbir_resize_uint8( \
		(const unsigned char *) input, \
		iw, \
		ih, \
		0, \
		(unsigned char *) output, \
		ow, \
		oh, \
		0, \
		sizeof(rgba_t) \
	)

static void fill_image(
    rgba_t *image,
    const int w,
    const int h,
    const rgba_t color
);
static void flip_image(rgba_t *image, const int w, const int h);

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
	int i, iw, ih, rw, rh, ow, oh, bpp, ret;
	bool flip_input;
	rgba_t *input, *rinput, *output;

	if(argc < 3 || argc > 6)
	{
		fprintf(
			stderr,
            "usage: %s input.png output.png [arguments...]\n\n",
            argv[0]
        );
		fprintf(stderr, "arguments:\n");
		fprintf(stderr, "    --flip   - flip input image horizontally\n");
		fprintf(stderr, "    --width  - set width of output image\n");
		fprintf(stderr, "    --height - set height of output image\n");
		return EXIT_FAILURE;
	}

	flip_input = false;
	ow = DEFAULT_OUTPUT_IMAGE_WIDTH;
	oh = DEFAULT_OUTPUT_IMAGE_HEIGHT;

	for(i = 3; i < argc; i++)
	{
		if(!strcmp(argv[i], "--flip"))
		{
			flip_input = true;
		}
		else if(!strcmp(argv[i], "--width") && i + 1 < argc)
		{
			ow = atoi(argv[++i]);
			if(ow <= 0)
			{
				fprintf(
                	stderr,
                    "error: invalid value for '--width' argument"
                );
				return EXIT_FAILURE;
			}
		}
		else if(!strcmp(argv[i], "--height") && i + 1 < argc)
		{
			oh = atoi(argv[++i]);
			if(oh <= 0)
			{
				fprintf(
                	stderr,
                    "error: invalid value for '--height' argument"
                );
				return EXIT_FAILURE;
			}
		}
		else
		{
			fprintf(stderr, "error: invalid argument '%s'\n", argv[i]);
			return EXIT_FAILURE;
		}
	}

	input = (rgba_t *) stbi_load(argv[1], &iw, &ih, &bpp, sizeof(rgba_t));
	if(input == NULL)
	{
		fprintf(
            stderr,
            "failed to load input image: %s\n",
            stbi_failure_reason()
        );
		return EXIT_FAILURE;
	}

	rw = ow;
	rh = oh;

	if(ih > 0 && ih != rh)
	{
		rw = iw * ((double) rh / (double) ih);

		rinput = malloc(rw * rh * sizeof(rgba_t));
		if(rinput == NULL)
		{
			fprintf(
                stderr,
                "failed to allocate memory to resize input image\n"
            );
			free(input);
			return EXIT_FAILURE;
		}

		if(!resize_image(input, iw, ih, rinput, rw, rh))
		{
			fprintf(
                stderr,
                "failed to resize input image from %dx%d to %dx%d ...\n",
                iw,
                ih,
                rw,
                rh
            );
			free(rinput);
			free(input);
			return EXIT_FAILURE;
		}
        
        free(input);

		fprintf(
            stderr,
            "resized input image from %dx%d to %dx%d ...\n",
            iw,
            ih,
            rw,
            rh
        );

		input = rinput;
		iw = rw;
		ih = rh;
	}

	output = malloc(ow * oh * sizeof(rgba_t));
	if(output == NULL)
	{
		fprintf(stderr, "failed to allocate memory for output image\n");
		free(input);
		return EXIT_FAILURE;
	}

	fill_image(output, ow, oh, (rgba_t) { .a = 0xFF });

	if(flip_input)
	{
		flip_image(input, iw, ih);
		fprintf(stderr, "flipped input image horizontally ...\n");
	}

	process(input, output, iw, ih, ow, oh);

	ret = stbi_write_png(
        argv[2],
        ow,
        oh,
        sizeof(rgba_t),
        output,
        ow * sizeof(rgba_t)
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

static void fill_image(
    rgba_t *image,
    const int w,
    const int h,
    const rgba_t color
)
{
	for(rgba_t *c = image, *e = image + w * h; c != e; c++)
		*c = color;
}

static void flip_image(rgba_t *image, const int w, const int h)
{
	int x, y, ww, xw, yo, i, j;
	rgba_t c;

	ww = w - 1;
	xw = w >> 1;

	for(y = 0; y < h; y++)
	{
		yo = y * w;

		for(x = 0; x < xw; x++)
		{
			i = x + yo;
			j = (ww - x) + yo;

			c = image[i];
			image[i] = image[j];
			image[j] = c;
		}
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
	int x, y, ww, xi, xo;
	double t, tw;
	rgba_t c;

	UNUSED(oh);

	xi = 0;
	ww = iw;

	if(iw > ow)
	{
		xi = iw - ow;
		ww = ow;
		input = input + xi;
	}

	xo = ow - ww;
	output = output + xo;

	tw = 1.0 / iw;

	for(y = 0; y < ih; y++)
	{
		for(x = 0; x < ww; x++)
		{
			t = x * tw;

			c = *input++;

			c.r = c.r * t;
			c.g = c.g * t;
			c.b = c.b * t;

			*output++ = c;
		}

		input += xi;
		output += xo;
	}
}

/* vim: set ts=4 sw=4 sts=4 noet: */
```

In order to compile this, you'll need to put [stb_image.h][stb_image], [stb_image_write.h][stb_image_write] and [stb_image_resize.h][stb_image_resize] in the current directory and then:

```bash
$ cc -O2 wallpaper.c -o wallpaper
$ ./wallpaper chimpanzee.png wallpaper.png --flip
```

![chimpanzee](/media/2023/chimpanzeef.png)

Voila! Not too bad, right?

![chimpanzeet](/media/2023/chimpanzeet.png)

### Background Video

Background images are cool, but have you ever used background videos?

Background videos have been a pet peeve of mine for quite some time and I wasn't entirely sure if redrawing the background 24+ times per second would be a realistic thing to do with [libvte][libvte].

I finally decided to go ahead and give it a try and use this as the perfect excuse to try out the excellent single file [pl_mpeg][pl_mpeg] library by [Dominic Szablewski][phoboslab] to decode MPEG videos.

Yes, you read it right, it's MPEG. There's no way that I would pull in some crazy dependency like [gstreamer][gstreamer] just for the sake of such an experimental feature.

It should go without saying that the video should not exceed 10-15 seconds in length and should loop in a seamless manner for the best experience.

In addition it might worth experimenting and downscale the video to 720p and then have it upscaled automatically by specifying the `-background-auto-scale` command line argument.

The other considerations around patterns and color palettes that I touched upon when I talked about background images should apply for videos as well.

{% include video.html src="/media/2023/sands_of_arrakis.mp4" %}

To make the background video seen above, I extracted around 10 seconds from [Sands Of Arrakis][sandsofarrakis].

The effect is pretty subtle, but one can clearly notice the sandstorm moving from left to right in the background.

{% include youtube.html id="F0Jk80wDw2w" %}

Finally, here's the incantation to convert an MP4 video into a compatible MPEG video without sound.

```bash
$ ffmpeg -i input.mp4 -c:v mpeg1video -q:v 0 -an -format mpeg output.mpg
```

## The Legend of Zelda: Tears of the Kingdom

Here we go again, it's that time of the month again. As the release date is only roughly 2 weeks away now, Nintendo has been dropping some more trailers as well as lifting the embargo, so that the select few can finally share their hands-on experience with playing the game for a whopping hour or so.

Let's start things off with the *final official pre-launch trailer* (#3).

{% include youtube.html id="uHGShqcAHlQ" %}

As a follow-up, there is the *"Dive Into the Unknown"* *mini-trailer*.

{% include youtube.html id="O2pzSYE7FWY" %}

Then, there is an actual ad titled "You can do what?"; This is really a tie-in for the NIntendo Switch console more than anything else.

{% include youtube.html id="CUcBlvw0LSk" %}

Finally, a curated list of videos by people who got an early sneak peek into the game during last week.

{% include youtube.html id="_a34CojpPz0" %}

{% include youtube.html id="uZodcZ7lcCU" %}

{% include youtube.html id="GYRXAHSk8VE" %}

{% include youtube.html id="SnJCimdPr34" %}

If you watch the videos, you'll notice how similar they are, which in turn illustrates how much control Nintendo actually has over what is shared, including in what form and when. It's pretty impressive really.

[marmota]: https://github.com/icebreaker/marmota
[usd]: https://openusd.org/release/index.html
[suckless]:https://suckless.org/
[usdhere]: /2023/04/29/universal-scene-description/
[chimpanzee]: https://www.wired.com/2015/05/chimpanzee-rights-get-day-court/
[pl_mpeg]: https://github.com/phoboslab/pl_mpeg
[phoboslab]: https://phoboslab.org/
[gstreamer]: https://gstreamer.freedesktop.org/
[stb_image]:https://github.com/nothings/stb/blob/master/stb_image.h
[stb_image_resize]: https://github.com/nothings/stb/blob/master/stb_image_resize.h
[stb_image_write]: https://github.com/nothings/stb/blob/master/stb_image_write.h
[sandsofarrakis]: https://www.youtube.com/watch?v=F0Jk80wDw2w
