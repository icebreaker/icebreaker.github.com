--- 
layout: post
title: Forging wallpapers ...
tags: 
- dual
- imagemagick
- linux
- monitor
- twinview
- ubuntu
- wallpaper
---
Recently I bought a nice 19' wide LCD monitor with an 1440x900 resolution, so I quickly setup <strong>Twinview</strong> between my laptop running at 1280x800 and obviously moved down the first screen by 100 pixels, to achieve the same effect as "Extend my ..." Wind0ze.

Everything was fine, until I wanted to set a wallpaper, and it hurt my eyes ... duhh, it was horible ... stretched between the two screens. yuck!

The wallpapers designed for dual monitors assume that both have the same height, which obviously wasn't my case ... so the only viable solution was to create my own wallpaper by arranging two images in GIMP.

I like to have the same wallpaper on both screens, so that wasn't a problem, but it was rather annoying after trying 2-3 wallpapers.

Instead I thought of the nice utility package called "ImageMagick" ... Yay! and wrote a nice little bash script to generate the desired wallpaper from two images given as input.

Here is the contents of the script:

{% highlight bash %}
#!/bin/bash

if [ $# -ne 3 ] ; then
echo "Usage: $0 image1.png image2.png outimage.png"
exit 13
fi

convert -size 2720x900 xc:black "$1" -geometry +0+100 -composite "$2" -geometry +1280+0 -composite "$3"

echo "Done ..."
exit 1
{% endhighlight %}

I named it "mkwlp" , made it executable (chmod u+x mkwlp) then copied it into /usr/bin for convenience ...

This can be customized for other resolutions, etc and it's fairly straight forward so i won't go into this.

(I highlighted the customizable parts for convenience)

Voila!!!

Here are a few wallpapers i "forged" with this little script :) Enjoy! (click to see the bigger version)

<a class="image" href="/images/2008/04/rihanna_wall1.png"><img class="alignnone size-medium wp-image-162" src="/images/2008/04/rihanna_wall1.png?w=400" alt="" width="400" height="132" /></a>

<a class="image" href="/images/2008/04/rihanna_wall2.png"><img class="alignnone size-medium wp-image-163" src="/images/2008/04/rihanna_wall2.png?w=400" alt="" width="400" height="132" /></a>

<a class="image" href="/images/2008/04/arielle_wall1.png"><img class="alignnone size-medium wp-image-168" src="/images/2008/04/arielle_wall1.png?w=400" alt="" width="400" height="132" /></a>

<a class="image" href="/images/2008/04/rihanna_wall3.png"><img class="alignnone size-medium wp-image-164" src="/images/2008/04/rihanna_wall3.png?w=400" alt="" width="400" height="132" /></a>

<a class="image" href="/images/2008/04/swanepoel_wall1.png"><img class="alignnone size-medium wp-image-165" src="/images/2008/04/swanepoel_wall1.png?w=400" alt="" width="400" height="132" /></a>

<a class="image" href="/images/2008/04/elisha_wall1.png"><img class="alignnone size-medium wp-image-166" src="/images/2008/04/elisha_wall1.png?w=400" alt="" width="400" height="132" /></a>

<a class="image" href="/images/2008/04/angelina_wall1.png"><img class="alignnone size-medium wp-image-167" src="/images/2008/04/angelina_wall1.png?w=400" alt="" width="400" height="132" /></a>

Oh, I almost forgot to tell that <a title="Click to visit!" href="http://www.ewallpapers.eu" target="_blank">EWallpapers.eu</a> is my number #1 landing place when I'm looking for high resolution wide screen wallpapers ( but not only! ) and also <a title="Click to visit!" href="http://www.hollywooddesktop.com/" target="_blank">Hollywood Desktop</a>.
