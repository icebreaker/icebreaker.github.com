---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2023
title: Image Diff(erence) Viewer
imagediffviewer: true
propaganda: 14
---

Image Diff(erence) Viewer
=========================

Considering that I've been posting quite a lot of things that perform image manipulation in one form or another, I thought that it's high-time to build one of those fancy image difference viewers that one can use and slide between two images in a seamless fashion.

As I don't intend to release this as a separate standalone project, I thought that I'd just share the entire thing here, considering that it's only a handful of lines of code and nothing too fancy.

## JS

```js
/*
	MIT LICENSE
	Copyright (c) 2023, Mihail Szabolcs
*/
document.querySelectorAll(".image-diff-viewer").forEach(function(el)
{
	var images = el.querySelectorAll("img");
	if(images.length != 2)
		return;

	var image = images[1];
	image.style.display = "block";

	el.removeChild(image);

	var wrapper = document.createElement("div");
	wrapper.className = "wrapper";
	wrapper.style.width = "50%";
	wrapper.appendChild(image);

	el.appendChild(wrapper);

	var update = function(e)
	{
		var rect = el.getBoundingClientRect();
		var border = Math.max(0, wrapper.offsetWidth - wrapper.clientWidth);
		var x = (e.pageX - rect.left - border) / el.offsetWidth;
		var perc = Math.min(Math.max(0, x * 100), 100);

		wrapper.style.width = perc + "%";
	};

	el.addEventListener("mousemove",  update, false);
    el.addEventListener("mouseleave", update, false);
	el.addEventListener("touchstart", update, false);
	el.addEventListener("touchmove" , update, false);
});
```

## CSS

```css
.image-diff-viewer
{
	position: relative;
	cursor: ew-resize;
	display: inline-block;
}

.image-diff-viewer img:last-child
{
	display: none;
}

.image-diff-viewer .wrapper
{
	position: absolute;
	width: auto;
	height: auto;
	top: 0;
	left: 0;
	overflow: hidden;
	border-right: 3px solid white;
	opacity: 0.75;
}
```

## HTML

```html
<div class="image-diff-viewer">
    <img src="image.png" />
    <img src="image_alt.png" />
</div>
```

## Demo

You probably have seen it in action my previous post about anaglyphs, but feel free to check out the  example below, just in case you missed it.

<div class="image-diff-viewer">
<img src="/media/2023/StoneFloorTexture_0.png" />
<img src="/media/2023/output-final.png" />
</div>

To use it, just to hover over the image and slide to the left or right. Touch should work as well. That is all!
