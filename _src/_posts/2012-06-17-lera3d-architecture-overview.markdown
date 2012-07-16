---
layout: post
title: Lera3D - Architecture Overview
tags: [lera3d, architecture, design]
---
Once again after a long-hiatus I'm back and kicking ass, very close to having enough technology ready to start the pre-production of **Ancestria**, our steam-punk action-adventure.

Personally, I put a lot of effort into the general design and architecture, always reworking and refactoring until it feels easy to use, this is why certain things take longer or seem to take forever for an outsider. There's no pre-mature optimization or overengineering going on, everything must be easy and powerful enough for me to use on a day-to-day basis.

A couple of key principles:

* light-weight (minimum carefully selected depedencies, **NO STL or BOOST**)
* written in ANSI C++ with portability in mind (compiles with `-Wall -Wextra -pedantic -ansi`)
* quality vs quantity (in terms of features you won't find the latest photon mapping)
* scalability (full support for low-end hardware, will run on your craptop)

This is the first of a series of posts in which I want to detail the design and general architecture as well as go into implementation specifics where necessary or makes sense.

After I catch up, I intend to post regurarly about the new stuff added or modified.

In terms of graphics (a.k.a renderer), like I mentioned above, low-end hardware will be fully supported out of the box, I cannot say as of now *how low is low?*; that will reveal itself during the coming months; one can expect *Tomb Raider: Anniversary* (~ 2007) level graphics on the day of release.

[![Tomb Raider Anniversary](/images/2012/06/17/tra1_thumb.jpg "Tomb Raider Anniversary")](/images/2012/06/17/tra1.jpg)

[![Tomb Raider Anniversary](/images/2012/06/17/tra2_thumb.jpg "Tomb Raider Anniversary")](/images/2012/06/17/tra2.jpg)

[![Tomb Raider Anniversary](/images/2012/06/17/tra3_thumb.jpg "Tomb Raider Anniversary")](/images/2012/06/17/tra3.jpg)

Without any further ado, some *diagrams* offering a high level overview of Lera3D's portable architecture.

![Lera3D](/images/2012/06/17/lr3d-arch.png "Lera3D")

### Core

![Lera3D](/images/2012/06/17/lr3d-arch-core.png "Lera3D")

### Interfaces

![Lera3D](/images/2012/06/17/lr3d-arch-interfaces.png "Lera3D")

### Plugins

![Lera3D](/images/2012/06/17/lr3d-arch-plugins.png "Lera3D")

### Game

![Lera3D](/images/2012/06/17/lr3d-arch-game.png "Lera3D")

I consider the *core* frozen now, which means that there won't be any major changes in the coming weeks and I'm in the process of building up the default set of *plugins* that will be bundled out of the box and will power the first episode of **Ancestria**.

Next time, we'll take a deeper look into the *core* and its underlyings.

