--- 
layout: post
title: (G)UI experiments ...
tags: 
- webkit
- qt
- opengl
- prototype
- ui
---
I should really work only on Lera3D these days, but the guys from <a title="Overgrowth" href="http://www.wolfire.com/overgrowth" target="_blank">Wolfire Games</a> are freaking me out with their really nice WebKit based UI in <a title="Overgrowth" href="http://www.wolfire.com/overgrowth" target="_blank">Overgrowth</a> .

They are using the "Awesonium" library, which I find quite bloathed ... ok ok ... this started from a concret realisation of "I can do this ..."

A web based UI with JavaScript+CSS and all the goodies supported by WebKit itself is nirvana for any UI designer; it just brings the whole thing to a new level.

What's better for prototyping than QT? NOTHING! I already had some base foundation code laying around from my other prototype projects (Slider3D, Prototype2D) so I started tackling around, NOT THE EASY way, BUT THE HARD WAY.

Instead of just cheating and positioning the widget on the top of my custom 3D canvas, I make a snapshot of the content and transform it into an OpenGL Texture, which then I draw on a quad. (this means that any shape can be textured with it)

Now here is an early screenshot demoing this:

<a class="image" href="/images/2009/09/ui_experiments.png"><img class="aligncenter size-medium wp-image-673" title="ui_experiments" src="/images/2009/09/ui_experiments-500x165.png" alt="ui_experiments" width="500" height="165" /></a>

On the left side it's the actual HTML + CSS, displayed in OpenGL ortho (2D) mode on the right side, drawn on the top of the actual 3D scene with blending.

The most important thing left to be done is INPUT, which I will implement most probably during next week or so, then I'll release the source code under BSD license as usual ...

Please don't ask who's the blondie, it just won't get you anywhere :)

Stay tuned :D
