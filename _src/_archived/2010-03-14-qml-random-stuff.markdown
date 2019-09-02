--- 
layout: post
title: QML and other random stuff
tags: [qt, qml, coding, random, rant, wildfire, game] 
---

### QML

I'm using the bleeding edge versions of both QT and QT Creator straight from the Git(orious) repositories; doing so has a couple
of benefits, but also drawbacks mostly because some of this bleeding edge stuff may break :)

How do I test / use all these? 

It's quite simple, I have my **/opt** mounted on a 10GB partition and I install qt and qt creator
there via 'make install' then just make sure that all the utilities (i.e qmake) are in my path (all the libs in LD_LIBRARY_PATH), so basically
I can even have multiple versions installed without breaking the "stable" versions residing in **/usr** or **/usr/local** .

<a href="/images/2010/03/qt-creator.png" class="image">
<img src="/images/2010/03/qt-creator_thumb.png"></a>

I also discovered this awesome 'Boxes' demo, I have no idea how long this have been part of the demos, but it's really awesome.

<a href="/images/2010/03/qt-boxes-demo.png" class="image">
<img src="/images/2010/03/qt-boxes-demo_thumb.png"></a>

Sooooo *drum rolls* **finally** I was able to get my hands on QML and test it without way any headache as it has landed
into the 4.7 branch.

With this at my fingertips I was also able to compile QT Creator with the QML related plug-ins enabled. **yaaaayyy**!!?!

<a href="/images/2010/03/qml-designer.png" class="image">
<img src="/images/2010/03/qml-designer_thumb.png"></a>

Here is a short video demoing the 'SameGame' example (part of the declarative samples); it was played and recorded using the
*official* QML viewer bundled with QT.

<object width="640" height="360"><param name="wmode" value="transparent" /><param name="allowfullscreen" value="true" /><param name="allowscriptaccess" value="always" /><param name="movie" value="http://vimeo.com/moogaloop.swf?clip_id=10150113&amp;server=vimeo.com&amp;show_title=1&amp;show_byline=1&amp;show_portrait=1&amp;color=A80000&amp;fullscreen=1" /><embed src="http://vimeo.com/moogaloop.swf?clip_id=10150113&amp;server=vimeo.com&amp;show_title=1&amp;show_byline=1&amp;show_portrait=1&amp;color=A80000&amp;fullscreen=1" type="application/x-shockwave-flash" allowfullscreen="true" allowscriptaccess="always" wmode="transparent" width="640" height="360"></embed></object>

Total and complete **AWESOMENESS**!!!

### Time?

I'm not going to write about *wasting* time, but basically I spent my time playing around with the [0.A.D](http://wildfiregames.com/0ad/) code base 
[more on this later] updating and recompiling QT and its friends, plus took a few decisions regarding Lera3D's engine architecture .

The weekend is not over **yet**, so there's a lot more to do! *Go, go, power ranger!*

### 0.A.D code base

[ this should be a completely separate post, but I'm just being **lazy** ]

[0.A.D](http://wildfiregames.com/0ad/) is developed by [Wildfire](http://wildfiregames.com/) games and recently (a year ago or so) have been open sourced. 
I blogged about this last year when I just compiled and pretty much forgot about it.

Yesterday I said, lets look at the source code again. I'm interested mostly in the rendering part, including the different rendering
paths (fixed or shader), etc.

( a couple of *fresh* screens )

<a href="/images/2010/03/0ad-oasis.png" class="image">
<img src="/images/2010/03/0ad-oasis_thumb.png"></a>

<a href="/images/2010/03/0ad-closeup.png" class="image">
<img src="/images/2010/03/0ad-closeup_thumb.png"></a>

<a href="/images/2010/03/0ad-animals-closeup.png" class="image">
<img src="/images/2010/03/0ad-animals-closeup_thumb.png"></a>

The actual code base is quite messy and not everything is clearly separated or grouped together where necessary.

{% highlight bash %}
c0d3rguy@Seth:/opt/0ad/source/maths$ ls -l
total 160
-rw-r--r-- 1 c0d3rguy c0d3rguy  6315 2010-03-13 16:59 Bound.cpp		# point of interest
-rw-r--r-- 1 c0d3rguy c0d3rguy  2717 2010-03-13 16:59 Bound.h		# point of interest
-rw-r--r-- 1 c0d3rguy c0d3rguy  7913 2010-03-13 16:59 Brush.cpp
-rw-r--r-- 1 c0d3rguy c0d3rguy  2521 2010-03-13 16:59 Brush.h
-rw-r--r-- 1 c0d3rguy c0d3rguy  1422 2010-03-13 16:59 Fixed.cpp
-rw-r--r-- 1 c0d3rguy c0d3rguy  4436 2010-03-13 16:59 Fixed.h
-rw-r--r-- 1 c0d3rguy c0d3rguy  2782 2010-03-13 16:59 FixedVector2D.h
-rw-r--r-- 1 c0d3rguy c0d3rguy  4054 2010-03-13 16:59 FixedVector3D.h
-rw-r--r-- 1 c0d3rguy c0d3rguy  1685 2010-03-13 16:59 MathUtil.h
-rw-r--r-- 1 c0d3rguy c0d3rguy 14111 2010-03-13 16:59 Matrix3D.cpp
-rw-r--r-- 1 c0d3rguy c0d3rguy  5286 2010-03-13 16:59 Matrix3D.h
-rw-r--r-- 1 c0d3rguy c0d3rguy  6385 2010-03-13 16:59 MD5.cpp
-rw-r--r-- 1 c0d3rguy c0d3rguy  1239 2010-03-13 16:59 MD5.h
-rw-r--r-- 1 c0d3rguy c0d3rguy  4265 2010-03-13 16:59 Noise.cpp
-rw-r--r-- 1 c0d3rguy c0d3rguy  1643 2010-03-13 16:59 Noise.h
-rw-r--r-- 1 c0d3rguy c0d3rguy  7260 2010-03-13 16:59 NUSpline.cpp
-rw-r--r-- 1 c0d3rguy c0d3rguy  2560 2010-03-13 16:59 NUSpline.h
-rw-r--r-- 1 c0d3rguy c0d3rguy  3152 2010-03-13 16:59 Plane.cpp		# point of interest
-rw-r--r-- 1 c0d3rguy c0d3rguy  2015 2010-03-13 16:59 Plane.h		# point of interest
-rw-r--r-- 1 c0d3rguy c0d3rguy  7352 2010-03-13 16:59 Quaternion.cpp
-rw-r--r-- 1 c0d3rguy c0d3rguy  2291 2010-03-13 16:59 Quaternion.h
drwxr-xr-x 3 c0d3rguy c0d3rguy  4096 2010-03-13 16:59 scripting
-rw-r--r-- 1 c0d3rguy c0d3rguy  1434 2010-03-13 16:59 Sqrt.cpp
-rw-r--r-- 1 c0d3rguy c0d3rguy   919 2010-03-13 16:59 Sqrt.h
drwxr-xr-x 3 c0d3rguy c0d3rguy  4096 2010-03-13 18:27 tests
-rw-r--r-- 1 c0d3rguy c0d3rguy  2518 2010-03-13 16:59 Vector2D.h
-rw-r--r-- 1 c0d3rguy c0d3rguy  3247 2010-03-13 16:59 Vector3D.cpp
-rw-r--r-- 1 c0d3rguy c0d3rguy  2457 2010-03-13 16:59 Vector3D.h
-rw-r--r-- 1 c0d3rguy c0d3rguy  3131 2010-03-13 16:59 Vector4D.h
{% endhighlight %}

Soo, the *"maths"*, in addition to the *usual* VectorND and Matrix classes the Plane and Bound can be a valuable source of inspiration
especially the Ray Intersection (& Bounding Box) stuff which is useful for *picking* . This is definitely
the first place to look when investigating a renderer.

Lets digg further ... **source/lib/** contains some of the *low-level* including some OpenGL related stuff.

Points of interest in **source/lib/**:

* ogl.h (basic util stuff like "ogl_HaveExtension", etc)
* ogl.cpp
* glext_funcs.h (>OpenGL 1.1 i.e glActiveTexture and other ARB stuff)

**source/ps/** contains more low-level stuff, some of these should be in **source/lib/** like CStr or the FileSystem, and Vector2D should be
most definitely inside "Maths".

IMHO, most of this directory should be merged with **source/graphics/**.

**source/graphics/** contains higher-level Game related stuff which basically sits on the top of **source/renderer** so maybe it would be
a good idea to merge all these into the **renderer** . [The frustum.* and camera.* code is definitely interesting.]

In **source/renderer** the render paths are OK, they are well separated but I feel like it has been over engineered, it's clearly visible
that all these parts have been hacked together in order to create something which works rather than designing it carefully .

An example of this hacky design from **source/renderer/Renderer.cpp**:

{% highlight cpp %}
bool CRenderer::IsTextureTransparent(CTexture* texture)
{
	if (!texture) return false;
	Handle h=texture->GetHandle();
	size_t flags = 0;   // assume no alpha on failure
	(void)ogl_tex_get_format(h, &flags, 0);
	return (flags & TEX_ALPHA) != 0;
}
{% endhighlight %}

This should have been part of the actual CTexture class (maybe as a static member) and not the CRenderer class; it's easy to see that
the guys behind 0.A.D are primarily Windows developers, the code tells it all.

There are huge dependencies like [Boost](http://www.boost.org) or [Xerces](http://xerces.apache.org/xerces-c/), personally I would get rid of these, 
especially [Boost](http://www.boost.org) which is a TRUE monster.

Oh well, this is not a complete code base analysis or anything, just a few very *personal* thoughts, don't pay attention if you don't want to.

[ Hear me NOW, believe me later. ]

Maybe, I will contribute to 0.A.D, who knows ... :) Lady who? **BUG**!!!

Until next time as **server** *said* ...

### End of Line

