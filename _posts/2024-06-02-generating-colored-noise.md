---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2024
title: Generating Colored Noise
year: 2024
month: 5
monthly: false
propaganda: noise
topic: c
---

# Generating Colored Noise

When I talked about [generating noise][generatingnoise], I only focused on storing the results in the typical grayscale form and ended up just using the same noise value for the `R`, `G`, `B` channels, while setting the `A` channel to `255`.

It should go without saying that it's perfectly fine and possible to store a separate noise value in each channel and thus have 4 noise textures packed into one.

Let's see how this looks and works in practice by starting with the typical good old static noise at first.

![noises](/media/2024/noises.png)

```c
static void process(
    rgba_t *output,
    const int w,
    const int h
)
{
    int i, n, r, g, b, a;

    for(i = 0, n = w * h; i < n; i++)
    {
        r = rand() & 0xFF;
		g = rand() & 0xFF;
		b = rand() & 0xFF;
		a = rand() & 0xFF;

        output[i] = (rgba_t) {
            .r = r,
            .g = g,
            .b = b,
            .a = a
        };
    }
}
```

And now, our friendly neighborhood *faux* [Perlin noise][perlinnoise] imitation.

![noisebi](/media/2024/noisebi.png)

```c
#define NOISE_MAX (1 << 14)
#define NOISE_MAX_MASK (NOISE_MAX - 1)
#define NOISE_MAX_MASK_INV (1.0f / (float) NOISE_MAX_MASK)

static void randomize(
	float *noise[4],
	const int w,
	const int h,
	const unsigned int seed
)
{
	int i, j, n;

    for(j = 0; j < 4; j++)
    {
		srand(seed + j);

		for(i = 0, n = w * h; i < n; i++)
		{
			noise[j][i] = (rand() & NOISE_MAX_MASK) * NOISE_MAX_MASK_INV;
		}
    }
}

#define fract(a) ((a) - ((int)(a)))
#define lerp(a, b, t) ((1 - (t)) * (a) + (t) * (b))

static void process(
	const float *restrict noise[4],
	rgba_t *restrict output,
	const int w,
	const int h,
	const int num_samples
)
{
	int x, y, i, j, xx0, yy0, xx1, yy1, yyo0, yyo1, yo, ww, hh;
	float inv_num_samples, inv_scale, xx, yy, fx, fy;
    float ac[4], v0, v1, cr, cg, cb, ca, c0, c1, c2, c3;

	ww = w - 1;
	hh = h - 1;

	inv_num_samples = 127.0f / (float) num_samples;

	for(y = 0; y < h; y++)
	{
		yo = y * w;

		for(x = 0; x < w; x++)
		{
			ac[0] = 0;
			ac[1] = 0;
			ac[2] = 0;
			ac[3] = 0;

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

                fx = fract(xx);
				fy = fract(yy);

                for(j = 0; j < 4; j++)
            	{
					c0 = noise[j][xx0 + yyo0];
					c1 = noise[j][xx1 + yyo0];
					c2 = noise[j][xx0 + yyo1];
					c3 = noise[j][xx1 + yyo1];

					v0 = lerp(c0, c1, fx);
					v1 = lerp(c2, c3, fx);

					ac[j] += lerp(v0, v1, fy) * i;
				}
            }

			cr = ac[0] * inv_num_samples;
			cg = ac[1] * inv_num_samples;
			cb = ac[2] * inv_num_samples;
			ca = ac[3] * inv_num_samples;

			output[x + yo] = (rgba_t) {
				.r = cr,
				.g = cg,
				.b = cb,
				.a = ca
			};
		}
	}
}
```

I purposely left the `A` channel on `255` in the generated examples above, in order to prevent the random transparency from spoiling all the fun. I hope that you can forgive me for that.

[generatingnoise]: /2023/12/17/generating-noise/
[perlinnoise]: https://en.wikipedia.org/wiki/Perlin_noise
