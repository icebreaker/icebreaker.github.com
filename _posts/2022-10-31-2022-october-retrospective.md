---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2022
title: 2022 October Retrospective
propaganda: 1
tags: retrospective
---
2022 October Retrospective
=========================
This glorious month I spent some more time working on **Niva**, the experimental **2D** graphics playground that I mentioned back in april, if I am not entirely and completely mistaken.

There is still a whole lot of the Cairo/Pango + some GTK API to expose to Lua, but it's getting there.

One of the things I focused on in particular was getting some of the Pango API exposed to Lua. The results of which you can witness in the GIF below.

![preview](/media/2022/preview.gif)

Speaking of *fonts*, the font you can see in the GIF above is the excellent [Yulong][yulong] font.

```lua
local w, h = canvas_current_size()
local num_segments = 3
local rd = 256
local sin = math.sin
local cos = math.cos
local sqrt = math.sqrt
local sprintf = string.format

register_font("examples/fonts/Yulong-Regular.ttf")
set_font(sprintf("Yulong Bold %d", 192))

function draw(w, h, rd, num_segments)
    local xc = w >> 1
	local yc = h >> 1
    local theta = 2 * math.pi / num_segments
    
	local s = sprintf("%02d", num_segments)
	local tx, ty = measure_text(s, rd, rd)

    clear(1, 1, 1, 1)
    
	set_color(0, 0, 0, 1)
	text(tx + 4, ty + 4, s)
	fill()

	set_color(1, 0, 0, 1)
	text(tx, ty, s)
	fill()

	set_color(0, 0, 0, 1)
	set_line_width(2)
	grid(0, 0, w, h, rd, rd)

	set_color(1, 0.1 * theta, 0.4 * theta, 1)

	for i=0,num_segments-1 do
		local x = xc + cos(i * theta) * rd
		local y = yc + sin(i * theta) * rd
		line_to(x, y)
	end
	fill()

	set_line_width(num_segments * theta)
	set_color(0, 0.4, 0.4 * theta, 1)

	local l = rd * 0.5
	for i=0,num_segments-1 do
		local xx = cos(i * theta) * rd
		local yy = sin(i * theta) * rd

		local x = xc + xx
		local y = yc + yy

		local invlen = 1.0 / sqrt(xx * xx + yy * yy) * l
		local dx = xx * invlen
		local dy = yy * invlen

		move_to(x, y)
		line_to(x + dx, y + dy)
	end
	stroke()
end

draw(w, h, rd, num_segments)

if argv and argv[1] == "--preview" then
	canvas_current_preview()
else
	assert(canvas_current_save_to_png("build/preview.png"))
end
```

As for Pango, the only time I used it was when I built my terminal emulator called [Marmota][marmota], but in that particular instance it was nothing more than *parsing* a font description and then passing it to [libvte][libvte]. No actual drawing on a proverbial canvas or anything.

One particularly nasty thing with Pango is the inability to use custom user defined fonts without doing any hacks.

In order to show you what I mean by this, please take a look at the implementation of the `register_font` function used in the Lua script above.

```c
int nva_lua_canvas_register_font(lua_State *L)
{
    bool result;
    const char *filename;

    filename = luaL_checkstring(L, 1);

    result = FcConfigAppFontAddFile(
        FcConfigGetCurrent(),
        (const FcChar8 *) filename
    );

    lua_pushboolean(L, result);
    return 1;
}
```

Oh yeah, one has to abuse the `fontconfig` API in order to make the custom font available for Pango to be able to pick up and use.

```c
pango_font_description_from_string("Yulong Bold 16")
```

I don't want to end on a bad note, but it's a mess and makes Pango totally unsuitable for anything portable.

One might say that it's fine, since Pango is heavily tied to the GTK and Gnome ecosystems; which is true of course, but on the other hand GTK fancies itself as a portable *toolkit* of sorts. Oh well.

[yulong]: https://ggbot.itch.io/yulong-font
[libvte]: https://github.com/GNOME/vte
[marmota]: https://github.com/icebreaker/marmota
