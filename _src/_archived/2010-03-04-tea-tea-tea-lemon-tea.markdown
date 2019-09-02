--- 
layout: post
title: Tea, Tea, Tea, Lemon Tea
tags: [lemontea, project, qt, opengl] 
---

### She said: but it makes sense actually; like to make lemon tea you need to know something but it doesn't take a lot of knowledge.

A few days ago I announced Lemon Tea (formerly known as Prototype3D) which is meant to provide a 
complete development environment for rapid prototyping games (or even non-interactive demos) .

I would like to make a few additions/corrections to that announcement; first of all the license will be just **GPLv3** 
(*commercial* licenses can be negotiated for a couple of ***$$$***, but let's just stay with the good old GPLv3), 
this covers the *tool code* **NOT** the actual *user created content* which can be licensed as the user sees fit.

**Lera3D** *(un-released, hidden in the dark forests of Git)* is meant to be a fully portable next generation 3D 
engine geared towards Linux; if you take a look in the Linux ecosystem you will notice quite quickly that 
all the 3D (graphics or game) engines out there are either outdated or doesn't provide "World Editor" so to 
speak which increases the learning curve and stops the mainstream from adopting it.

IMHO, [Ogre](http://www.ogre3d.org) is the only one which has some chance to survive especially after being adopted 
by the [Torchlight](http://www.torchlightgame.com) developers (who built their own tool set around it) and now it got a 
really really permissive MIT license. (the license itself won't make a huge difference anyway)

Why is this? Realistically you build the engine itself (the next big thing), but then you realize that a couple
of new features just landed in (the scene) or new techniques and you need to upgrade the engine in order to support 
these features, so basically the engine never matures and there will be no "World Editor", or just the author(s) have 
no interest in developing something like this.

I've been developing the concept and architecture of Lera3D since early 2005, since then its architecture 
went through a few major overhauls; it felt like that it will never be ready ... but now the core architecture is 
pretty close to be finished and I got an idea! *sparkle, sparkle* !??!

What it would happen if I temporarily stop working on it and start working on the opposite side? 
I said, let's build the whole Editor first with a very very basic rendering path which later on can be swapped 
with Lera3D's highly efficient and optimized rendering paths (this also applies to a few other sub-systems which 
may find their ways in Lemon Tea).

### A crank is someone with a new idea ... until it caches on ...

Even though there is no source code in the wild yet, I would like to publish the planned or expected feature set
to land in Lemon Tea.

This is all subject to change, *but you can't change the plan unless you have the plan*.

There are no sprints or specific release dates which is normal considering that it's a personal project and I'm not 
working on it full time. (at least not at the moment)

<script src="http://gist.github.com/321972.js"></script>

I promise regular updates (builds?!) regarding the development and update this list accordingly. I guess these should be done 
in the next couple of months, let's say August, early September. (we'll see how this goes in practice ... zzzaayycckksss!)

### End of Line
