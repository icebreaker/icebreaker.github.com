--- 
layout: post
title: OpenSolaris -- Part X
tags: 
- nvidia
- opensolaris
- cg
---
I have <strong><em>OpenSolaris 2008.11</em></strong> installed on an external HDD, and boot it up from time to time, when there is some time to loose.

Today, I went over to NVIDIA Developers area and grabbed the Solaris version of the Cg Toolkit, which is a nice Solaris package, installs and works flawlessly under OpenSolaris, except the example programs won't compile because of the evil GLUT.

I tried to compile GLUT 3.7, but after 2 hours of pain I gave up, and installed the freeglut which is available in the Blastwave repo. In the next few lines I will illustrate how to get one of the samples compiling and working with freeglut without much pain.

The best way to go is to copy the examples directory into your home directory or desktop for convenience. I will modify the examples/OpenGL/basic/26_toon_shadding sample program.

First we need to edt 26_toon_shading.c in order to change the <em><strong>"GL/GLUT.h"</strong></em> include to <em><strong>"GL/freeglut.h"</strong></em>, and after this modifying the Makefile.

First of all I added :
{% highlight basemake %}CFLAGS += -I"/opt/csw/include"{% endhighlight %}
This is required because the Freeglut package will install there, and modified <strong><em>CLINKFLAGS</em></strong> by appending <em><strong>-L/opt/csw/lib</strong></em> so it looks like this:
{% highlight basemake %}CLINKFLAGS += -L/usr/X11R6/lib64 -L/usr/X11R6/lib -L/opt/csw/lib{% endhighlight %}
After this, a regular 'make' will do the job, but when running the executable there will be an error saying that the freeglut shared object cannot be found. This is fixed by prepending the <strong><em>/opt/csw/lib</em></strong> to the <em><strong>LD_LIBRARY_PATH</strong></em> environment variable with the following shell command:
{% highlight bash %}export LD_LIBRARY_PATH=/opt/csw/lib:$LD_LIBRARY_PATH{% endhighlight %}
... there you go :D up and running.

<a class="image" href="/images/2009/04/screen.jpg">
<img class="alignnone size-thumbnail wp-image-485" title="screen" src="/images/2009/04/screen-400x330.jpg" alt="screen" width="400" height="330" />
</a>

Personally, I think that it's an good idea installing all the 3rd party stuff inside the /opt dir instead of /usr or /usr/local, which seems to be a common practice in the existing Linux communities, of course this is more or less a matter of tastes.

<em>"Gustibus non, disputatum est.</em>"

PS: can't wait for the native Skype port, especially for OpenSolaris :D
