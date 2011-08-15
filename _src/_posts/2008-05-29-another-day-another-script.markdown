--- 
layout: post
title: Another day, another script ...
tags: 
- scripting
- bash
- convert
- image
- magick
---
A few weeks ago I posted a script I made to make customized wallpapers for my system using twinview. Recently I made another nice little script to convert all the images in PNG format from a folder to JPG format.

This is really simple and it fits my needs ... of course as always there is room for improvement :)

{% highlight bash %}
#!/bin/bash
ls *.png | awk '{ printf("Converting %s ... ",$0); \
system("convert " $0 " " substr($0,0,length($0)-3)".jpg" ); \
printf("Done!\n"); }'
{% endhighlight %}

I made it executable and copied it as mkjpg to /usr/bin/ for convenience.

Happy scripting!
