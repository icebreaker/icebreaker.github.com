--- 
layout: post
title: Finally ... Ubuntu +  Compiz + Kiba Dock
tags: [linux, ubuntu, compiz, kiba, dock, nvidia, border, fix]

---
We all know that the Geforce 7300 series are somewhat problematic under Linux and obviously under Ubuntu especially when it comes to Compiz ... and if you don't have compiz you can't run 'eye' candy apps which make use of a composition manager ... yeaaak!

Compiz was working fine for me except that the Windows Borders never showed up, no matter what I did. So here is how I made this work ... make sure that you have this line in your /etc/X11/xorg.conf .

{% highlight bash %}
Option "AddARGBGLXVisuals" "True"
{% endhighlight %}

The easiest way to do this, is to fire up a terminal and type in the following:

{% highlight bash %}
sudo nvidia-xconfig --add-argb-glx-visuals -d 24
{% endhighlight %}

Then restart compiz, and the borders should appear. Of course this assumes that you have installed the "NVidia" drivers (restricted) .

I also compiled the latest version of the "Kiba Dock", and played around with the Compiz settings. Now i'm in the hunt for the perfect theme and maybe background ...

<a class="image" href="/images/2008/02/compiz_ubu.png" title="compiz_ubu.png"><img src="/images/2008/02/compiz_ubu.png" alt="compiz_ubu.png" height="409" width="648" /></a>

May the source be with you, and good night :D

PS: until now I didn't had the will to play around with these extensively ... haha!
