--- 
layout: post
title: Wireless + Ubuntu 7.10 = love
tags: 
- "7.10"
- "8.04"
- fix
- gutsy
- hardy
- linux
- startup
- ubuntu
- wireless
- wlan
- wpa
- wpa-tkip
- wpa2
---
As almost everyone around here, I was waiting for the new Ubuntu mostly because it promised improved wireless support. 7.04 haven't even recognized my wireless card, after install, and also I had sound problems, though anything else seemed to work great.The 7.10 solved these right out of the box, <strong>but</strong> I still wasn't able to connect via WPA-TKIP and WPA2-AES to my wireless Netgear router.

So, after a few days of digging and reading, I managed to make my wireless connection working. It's not the most elegant solution, but for me it works, and that's all what matters.
In this guide, I assume that your wireless card is recognized by Ubuntu, and it's functional. In 7.10 you have the wpa_supplicant installed by default, so you won't have to worry about it.
Here is with what I came up, and making my wireless working, exactly as it works under Windows.
<ol>
	<li>I removed the silly network-manager by typing "sudo apt-get remove network-manager" in a terminal.</li>
	<li>Now go to System-&gt;Administration-&gt;Networking, and make sure to fill the fields with the correct info, and enable the wireless connection.</li>
	<li>To make sure that everything is right, check your /etc/network/interfaces file. Open up the file by typing "gksudo gedit /etc/network/interfaces".</li>
</ol>
For WPA-TKIP:

<p style="margin-left:40px;">iface wlan0 inet static
address 192.168.0.25
netmask 255.255.255.0
gateway &lt;your router's ip&gt;
wpa-ap-scan 1
wpa-pairwise TKIP
wpa-group TKIP
wpa-psk &lt;your long wpa key&gt;
wpa-driver wext
wpa-key-mgmt WPA-PSK
wpa-proto WPA
wpa-ssid &lt;your essid&gt;</p>
auto wlan0

For WPA2-AES:

iface wlan0 inet static
address 192.168.0.25
netmask 255.255.255.0
gateway &lt;your router's ip&gt;
wpa-ap-scan 1
wpa-pairwise CCMP
wpa-group CCMP
wpa-psk &lt;your long wpa key&gt;
wpa-driver wext
wpa-key-mgmt WPA-PSK
wpa-proto WPA2
wpa-ssid &lt;your essid&gt;

auto wlan0

Make sure that these, are in the file, if not then add the lines, and save the file, then you can close the gedit window.
4.   In a terminal type in the followings, exactly in this order:
"sudo killall wpa_supplicant" [enter]
"sudo /etc/init.d/networking stop" [enter]
"sudo /etc/init.d/networking start" [enter]

5.    Now we should take a look at our connection status in the "Network Monitor" applet.
6.    Finally we can do a "ping google.com" right from the terminal.

So, by now we should have a working wireless connection, but if you will restart your PC, you will have to type in the commands from "section 4.".
That's really, really annoying, so here is the solution to get wireless at startup automatically.

Type in a terminal "sudo gedit /etc/init.d/wifi" and paste the followings in the file (basically our 3 commands):
<p style="margin-left:40px;">#!/bin/bash</p>
#kill all wpa_supplicant instances
killall wpa_supplicant

#stop the network interfaces
/etc/init.d/networking stop

#start the network interfaces
/etc/init.d/networking start

Close the gedit window, and type "sudo chmod +x /etc/init.d/wifi" to make the script "executable". When done, we must add it to be executed at every system
start-up as the last "thing". :))

To do that type the following in a terminal window:
<p style="margin-left:40px;">"sudo update-rc.d wifi defaults 99"</p>
Later if you will like to disable this you have two choices:

<p style="margin-left:40px;">1. "sudo update-rc.d -f wifi remove" OR
2. "sudo chmod -x /etc/init.d/wifi"</p>
Too test out this, just restart your computer and you should have internet access right after boot-up, just like on a Wind0ze machine. Totally rad huh?

<strong>[Updates Sun Mar 30, 2008]</strong>

This "post" proven to be really popular, so here are a few updates, to make even more users happy :)

If you are getting your IP from your router automatically then you can replace this:

iface wlan0 inet static
address 192.168.0.25
netmask 255.255.255.0

with this

iface wlan0 inet dhcp

If you ping and you get no "reponse", then it worth to check out your /etc/resolv.conf and make sure that it contains the following lines:

nameserver &lt;your router's ip&gt;

You can edit / create this file by "sudo gedit /etc/resolv.conf".

If it still doesn't work, you may try changing "wlan0" to "wifi0","ath0" ...

If you get disconnected you can always fire up a terminal and run "sudo /etc/init.d/wifi" to get your connection back, without any hassle ...

Because the silly "network-manager" was removed you can add an "Network Monitor" to one of your Gnome Panels ...

Also I'm thinking on coding a nice little GUI tool to do all this stuff, so stay tuned!

<strong>[Updates Sat Apr 26, 2008]</strong>

This works perfectly in the final release of Ubuntu 8.04 (Hardy Heron), just like Dave confirmed that it works with the beta.

<strong>[Updates Sat May 10, 2008]</strong>

The development of little GUI tool is on hold, eventually I will continue the development if there will be enough requests, but I seriously doubt it :)

Please feel free to post any comments/suggestions/experiences, etc. related to this. :))
