--- 
layout: post
title: Drunken escapades with Glest ...
tags: [glest, rts, game, coding, linux]

---
I grabbed Glest tonight, and wanted to compile it, but BOOM! when I wanted to compile the map editor, tons of errors related to wxWidgets popped up ... of course the 1st thing on what I was thinking is that my wxWidgets version is too old ... and so it was, so I grabbed the latest wxWidgets and after compiling it several times enabling one by one every feature required by the Glest map editor i did it ... Yay!

Here is my "configure" command ( just for the curious ):

{% highlight bash %}
./configure --enable-unicode --enable-config --enable-std_string --enable-std_iostreams --with-gl --with-gtk
{% endhighlight %}

wxWidgets takes quite some time to compile, even on my dual-core @ 1.8Ghz ... damn, usually I compile in a "yakuake" session so I can forget about it :P

One thing I noticed though, if I compiled wxWidgets with X11 the editor didn't flicker, but with GTK flickers heavily ...

I think that wouldn't be wrong if I would say that Glest is the best open source RTS at the moment in all means, graphics, ai, etc...

<a class="image" href="/images/2008/03/glest_screenshot.png" title="glest_screenshot.png"><img src="/images/2008/03/glest_screenshot.png" alt="glest_screenshot.png" height="353" width="563" /></a>

Anyway I'm planning to contribute to Glest ... maybe fixing some bugs, or making some improvements, we'll see ...

Until then, happy coding and may the source be with you!

<a class="image" href="/images/2008/03/glest_screenshot-1.png" title="glest_screenshot-1.png"><img src="/images/2008/03/glest_screenshot-1.png" alt="glest_screenshot-1.png" height="353" width="563" /></a>
