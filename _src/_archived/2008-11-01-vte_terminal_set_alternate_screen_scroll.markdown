--- 
layout: post
title: vte_terminal_set_alternate_screen_scroll
tags: 
- fix
- vte_terminal_set_alternate_screen_scroll
---
I upgraded to Intrepid last night, and it broke my gnome-terminal. So after some digging, etc. here is what I did to make it work:

{% highlight bash %}
wget http://ftp.gnome.org/pub/gnome/sources/vte/0.17/vte-0.17.4.tar.gz
tar xzvf vte-0.17.4.tar.gz
cd vte-0.17.4

wget http://patches.ubuntu.com/v/vte/extracted/93_add_alt_screen_scroll_toggle.patch
patch -p1 &lt; 93_add_alt_screen_scroll_toggle.patch

./configure
make
make install
{% endhighlight %}

... and BOOM, now it should work since the method is there :)

Enjoy :)

<strong>UPDATE: 2/26/2009</strong>

The latest available version of the VTE library should be downloaded instead of the old 0.17.4 from <a title="Get VTE!" href="http://ftp.gnome.org/pub/gnome/sources/vte" target="_blank">here</a> .
