---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2022
title: 2022 April Retrospective
propaganda: 1
tags: retrospective
---
2022 April Retrospective
========================
The days, weeks and months are just flying by. Perhaps it's just a sign that I must be getting old.

At any rate, I find that the monthly retrospectives do bare fruit, even more so than I would have thought.

Last month, with all the excitement around [Flordle][flordle], I forgot to mention another small experiment that I did involving pixel art and bump mapping. The result of which you can enjoy in its full glory in the tiny video below.

{% include video.html src="/media/2022/bumpmap.mp4" %}

One of the advantages of writing your own terminal emulator is that you can add in any feature that you want, without having to deal with anybody else.

![](/media/2022/marmota.png)

As you can see in the screen-shot above, I ended up adding support for background images. Not the most impressive or useful of features but why the heck not.

By the way, I am still on the fence about [VTE][vte], due to the [absolutely nonsensical decisions][fontweight] taken by its maintainers, and it takes a lot of strength to suppress the need to ditch it and roll my own *widget*. Please, do not tempt me Satan!

If for any reason you might want the background image seen in the screen-shot above, then you can find it over [here][background].

I also launched a tiny [Gemini][gemini] capsule which can be found over at [gemini://gemini.mihail.co][capsule]. How long will I keep this up and operating? It's hard to tell at this point in time, we'll see where the four winds take us in the coming months.

![gemini](/media/2022/gemini.png)

Does this mean that I finished the small Gemini server that I intended to write in Go and mentioned in my end of the year retrospective? No, of course not. It would have been way to simple to do so.

I ended up rolling something rather unusual and special in a way by using `ncat` with its built-in `--lua-exec` support.

```bash
$ openssl req -new -subj "/CN=gemini.mihail.co" -x509 -newkey ec \
	-pkeyopt ec_paramgen_curve:prime256v1 -days 3650 -nodes \
	-out certs/cert.pem -keyout certs/key.pem
```

```bash
$ ncat --lua-exec server.lua -l --keep-open -m 32 --ssl \
	--ssl-cert certs/cert.pem --ssl-key certs/key.pem -p 1965
```

```lua
-- server.lua
local f = assert(io.open("index.gmi", "rb"))
local s = f:read("*a")
f:close()

io.stdout:write("20 text/gemini\r\n")
io.stdout:write(s)
io.stdout:flush()
```

Of course the version I have running is a bit more advanced and can handle arbitrary paths by reading from `stdin` via `io.read` and then figuring out the requested resource path from there, but the general idea stays very much the same. I think it's pretty neat and low maintenance, without having to roll any sort of heavy infrastructure around it in order to support it, which is always a huge plus in my eyes.

I will still come back and finish up the server in Go at some point or another, but do not hold me to it.

What I did say about seemingly random and ad-hoc side projects? Well, I started another one and without going into way too many details too early, it's an *experimental* **2D** graphics playground.

![niva](/media/2022/niva.png)

```lua
$ niva preview.lua --preview
```

```lua
-- preview.lua
local w, h = canvas_current_size()
local num_segments = 6
local theta = 2 * math.pi / num_segments
local rd = 256
local xc = w >> 1
local yc = h >> 1
local sin = math.sin
local cos = math.cos

set_line_width(2)
grid(0, 0, w, h, rd, rd)

set_color(1, 0.1 * theta, 0.4 * theta, 1)

for i=0,num_segments-1 do
	local x = xc + cos(i * theta) * rd
	local y = yc + sin(i * theta) * rd

	line_to(x, y)
end

fill()

if argv and argv[1] == "--preview" then
	canvas_current_preview()
else
	assert(canvas_current_save_to_png("preview.png"))
end

-- vim: set ft=lua ts=4 sw=4 sts=4 noet:
```

In other news, I also started digging into the binary crate file format that is part of [USDZ][usdz] and boy it's an absolute disaster.  I said this a few time, but once I figure it out all and write a dependency free exporter, I will most definitely write up a lengthy post about it. Not much to report just yet!

Oh, I almost forgot. Ended up buying a [snowball iCE][mic] microphone, which should provide me with some better sound quality, whenever I end up doing another coding live-stream on Twitch.

And, that is the majority of the things that I wanted to report on this month. Not great, not terrible at the same time.

[flordle]: /flordle
[vte]: https://wiki.gnome.org/Apps/Terminal/VTE
[fontweight]: https://gitlab.gnome.org/GNOME/vte/-/issues/323
[background]: http://randallmackey.com/thelonelycosmonaut#the-lonely-cosmonaut
[usdz]: https://graphics.pixar.com/usd/release/wp_usdz.html
[gemini]: https://gemini.circumlunar.space/
[capsule]: gemini://gemini.mihail.co
[legion]: https://stephenking.fandom.com/wiki/Andr%C3%A9_Linoge
[mic]: https://www.bluemic.com/en-us/products/snowball-ice/
