--- 
layout: post
title: Prototype2D teaser ...
tags: 
- qt
- opengl
- box2d
- prototype2d
---
This is a little side project to get my attention away from Lera3D, but also a proof of concept for building an small 2d engine using QT + OpenGL, BOX2D for Physics and irrKLang for the Sound.

Features:
<ul>
	<li>Base Actor class with support for tile based animation and multiple layers with z ordering (done)</li>
	<li>Texture Manager (all textures reference counted) (done)</li>
	<li>World Manager ( manages all actors, offers factory methods for easy actor creation, etc ) (done)</li>
	<li>Sound System via irrKLang ( to be done )</li>
	<li>Box2D integrate physics with the Base Actor and World classes (work in progress)</li>
	<li>other misc. features (blending, etc) (partially done)</li>
</ul>
So far it's around 4 days of work, I really hope to finish it this weekend, then push it out into an repo over Gitorious or Github with a basic platformer demo game or something.

So here is a little teaser:

<object width="640" height="480"><param name="wmode" value="transparent" /><param name="allowfullscreen" value="true" /><param name="allowscriptaccess" value="always" /><param name="movie" value="http://vimeo.com/moogaloop.swf?clip_id=5277984&amp;server=vimeo.com&amp;show_title=1&amp;show_byline=1&amp;show_portrait=1&amp;color=FF7700&amp;fullscreen=1" /><embed src="http://vimeo.com/moogaloop.swf?clip_id=5277984&amp;server=vimeo.com&amp;show_title=1&amp;show_byline=1&amp;show_portrait=1&amp;color=FF7700&amp;fullscreen=1" type="application/x-shockwave-flash" allowfullscreen="true" allowscriptaccess="always" wmode="transparent" width="640" height="480"></embed></object>
