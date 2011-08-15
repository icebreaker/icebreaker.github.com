--- 
layout: post
title: Indie Game Dev Rant #1 ...
tags: [indie, game, rant] 
---

Last week I stumbled across an interesting blog [post](http://blog.fishingcactus.com/index.php/2010/02/01/mojito-on-linux-diary-2/) about deciding to port an *engine* to Linux.

The reason??!!

*As you can see in World of Goo, created by 2D Boy, they had about 17% of their sales on the Linux platform. It looks like a lot of open source gamers are just waiting for some stuff to play on the penguin!*

Well, gentlemen, you don't have be a super genius to realize that as an indie game developer you just cannot afford locking yourself to a single
operating system.

It's OK if you develop PS or Wii games only, but when it comes to the PC, Linux and MacOSX are to be considered because their user base is growing every single day.

Linux users are more likely to pay and buy a quality game ... why ?! because there aren't many **good** games in the Linux ecosystem, believe it or not that's a solid reason.

Indies tend to have the misconception that it's not possible to release a game on these three operating systems without any upfront costs ... this is factually false, because it's perfectly possible
and totally feasable, BUT ... (there's always a BUT) you just have to choose and use portable libraries from the very beginning.

Fortunately, there is an open source alternative to pretty much every "sub-system" a (game) engine needs.

* Renderer => OpenGL
* Sound => SDL_mixer, OpenAL + Ogg
* Image => SDL_image, DevIL
* Input & Window Management => SDL, Allegro, GLUT, SFML

Or Why not just use QT for everything (perfectly possible now with Phonon for Audio) ??!

These are all well proven and mature libraries; you might have to write more code or wrappers around them, but the outcome will be complete and total win.

I will write a book focusing on Open Source Indie Game Development in the near future ...

### End of Line


