--- 
layout: post
title: 3D Slideshow
tags: 
- coding
- qt
- opengl
- slider3d
---
Here is another quick prototype using QT+OpenGL.

The source code is hosted at GitHub as usual ... right<a title="Get the source!" href="http://github.com/icebreaker/slider3d/tree/" target="_blank"> here </a>.

<object width="640" height="360"><param name="wmode" value="transparent" /><param name="allowfullscreen" value="true" /><param name="allowscriptaccess" value="always" /><param name="movie" value="http://vimeo.com/moogaloop.swf?clip_id=6020605&amp;server=vimeo.com&amp;show_title=1&amp;show_byline=1&amp;show_portrait=1&amp;color=FF7700&amp;fullscreen=1" /><embed src="http://vimeo.com/moogaloop.swf?clip_id=6020605&amp;server=vimeo.com&amp;show_title=1&amp;show_byline=1&amp;show_portrait=1&amp;color=FF7700&amp;fullscreen=1" type="application/x-shockwave-flash" allowfullscreen="true" allowscriptaccess="always" wmode="transparent" width="640" height="360"></embed></object>

Features (as of now):
<ul>
	<li>scans the current directory for photos (png &amp; jpg)</li>
	<li>resizes photos internally before converting them to textures to either 512x512 or 1024x0124; so it should work fine with most video cards.</li>
	<li>keeps the original aspect ratio of the photos</li>
	<li>tries to activate and use 4x multi-sampling (anti-aliasing) if possible</li>
	<li>multi-monitor support (by passing in the command line arguments --monitor X ; where X is the desired monitor to use)</li>
	<li>simple floor reflection using the Stencil Buffer (it may not work with not T&amp;L cards)</li>
	<li>scrolling left/right by using the arrow keys</li>
	<li>automatic slide show mode can be switched on / off by pressing 'space' (switches every 3 seconds; two way)</li>
	<li>displays file names under the current photo</li>
</ul>
It should work fine on most systems (even with those crappy integrated Intel graphic cards). Enjoy :)

(PS: I'm really going to back to Lera3D now ...)
