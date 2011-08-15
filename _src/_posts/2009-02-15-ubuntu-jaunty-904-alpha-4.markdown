--- 
layout: post
title: Ubuntu Jaunty 9.04 Alpha 4
tags: [ubuntu, jaunty, alpha, testing, linux, review]

---
I did a clean-up on my system and decided to wipe out everything and do a clean install, but instead of the stable 8.10, I installed Jaunty 9.04 alpha 4.

At first this didn't seemed to be a very wise decision, but later on it turned out quite the opposite.

There are issues with Video + Sound out of the box @ the moment. The sound can be easily fixed by re-compiling alsa, as usual, but with the video part largely depends on X11 and the proprietary NVIDIA drivers.

nvidia-settings doesn't seem to be working properly, it's something with the metamodes, of course I had my old xorg.conf, so my dual monitor setup works 98% great, the remaining 2% will be fixed with further updates ... I hope!

The sound quality is a whole lot better, I wouldn't be wrong if I would say that it was taken to a completely new dimension, so thumbs up for this.

The horizontal "volume slider" is quite sexy as well, in the Gnome version bundled with this release.

If you have lots of music like I do in the MP3 format, it's worth installing the <strong><em>"Fluendo"</em></strong> mp3 decoder GStreamer plugin, to get the most out of sound quality.

For the first time since the very first Ubuntu release, I didn't had to remove the "network manager" in order to make my wireless work flawlessly with WPA2-TKIP.

Anyway I'm most impressed by the improved 'font rendering', it's getting quite close to the smoothed and antialised font look popular and well know from MacOSX. Good job here ;)

<img class="alignnone size-medium wp-image-422" title="font-rendering-ubuntu" src="/images/2009/02/font-rendering-ubuntu-500x236.png" alt="font-rendering-ubuntu" width="500" height="236" />

<strong>Font</strong> : <em>Droid Sans Mono</em>

<strong>GEdit Theme</strong>: <em>Django</em>

There is a lot of buzz about the blazing fast boot time, but yeah, with ext4 partitions it's about 10-14 seconds on my modest system ( dual core @ 1,8ghz, 2GB ram, and 120gb 5400 rpm hdd ) .

In overall 9.04 alpha 4 is looking rock solid and a lot more responsive, it's really really fast.

I also installed the themes, etc. from "Ubuntu Satanic Edition" for Intrepid, so here is a screenshot :)

<a class="image" href="/images/2009/02/desktop.jpg"><img class="alignnone size-thumbnail wp-image-423" title="desktop" src="/images/2009/02/desktop-400x132.jpg" alt="desktop" width="400" height="132" /></a>

To be continued ...
