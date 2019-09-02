--- 
layout: post
title: WebGL is trendy ...
tags: [webgl, opengl, chrome, webkit, mini3d, javascript] 
---

### Mini3D

I'm a hardcore C/C++ programmer, but when I do 'web' my all time favorite is JavaScript; however I tend to take JavaScript to
the extreme by doing OOP, this confuses 99% of the 'web' dudes who have no idea about optimizations or just pretty much 
copied JavaScript from DHTML.com all their lives without ever knowing what's going on.

Soooooooo, *drum rolls* ... I'm here to announce [Mini3D](http://icebreaker.github.com/mini3d/) a small 3D engine written in pure JavaScript, built on the top of WebGL which uses the
canvas element and it's part of the HTML5 standard.

### Rant Begin

I should have rather spent time working on [Lera3D](/tag/lera3d) instead, but after seeing the [Quake2 port to WebGL](http://code.google.com/p/quake2-gwt-port/) and being pissed off by
[CopperLicht](http://www.ambiera.com/copperlicht/index.html) which is basically a subset of the crappy [irrLicht](http://irrlicht.sourceforge.net/) ported to JavaScript and WebGL, I decided
to build a 100% free alternative myself.

### Rant End

Mini3D itself is fairly simple, yet written in a very elegant manner without any 3rd party libraries; it's quite light-weight.
It has a modular design, so it's relatively easy to stick in a new module which can make use of other existing modules.

To run this piece of shit you will need an unstable build of Chrome, Safari or Firefox. I'd recommend Chrome, because it seems
to be ahead of the time and the WebGL implementation is quite solid (at least so it seems under Linux).

### Development

The development of Mini3D took barely two weekends so don't expect too much, but it's quite usable already and abstracts most
of the required functionalities well enough; the primary reason was to simplify things and provide boilerplate code so the 
programmer can focus on the 'demo' or 'game' itself rather than writing miles of code every single time ...

The 'low' level part is ready (more or less), now higher level stuff can be built on the top of it.

This is a very very early version, but this time I stick to *'Release early, release often'*.

### Demos

<a href="http://icebreaker.github.com/mini3d/demos/cube/cube.html" class="image">
<img src="/images/2010/04/cube.png"/>
</a>

<a href="http://icebreaker.github.com/mini3d/demos/clod/clod.html" class="image">
<img src="/images/2010/04/clod.png"/>
</a>

Click on the images above to start the demos. You will need a WebGL enabled browser in order to watch them; for more information about
how to get a WebGL enabled browser please consult the following [documentation](http://www.khronos.org/webgl/wiki/Getting_a_WebGL_Implementation) .

### Source Code

The source is on GitHub, and can be found right [here](https://github.com/icebreaker/mini3d) . 

Feel free to fork it, hack it and submit a pull request. Your contributions are more than welcome.

Be sure to checkout the [documentation](http://icebreaker.github.com/mini3d/docs/index.html) as well.

### End of Line

