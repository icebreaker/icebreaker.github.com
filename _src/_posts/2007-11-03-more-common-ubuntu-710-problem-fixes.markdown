--- 
layout: post
title: More Common Ubuntu 7.10 problem fixes :))
tags: [ubuntu, linux, fix]

---
Today I found solutions to two other frequent problems with Ubuntu and newer laptops.

1). When the headphone jack is plugged in the sound doesn't stops in the internal speakers.

- The workaround to this problem is the following:

- compiling the latest alsa-driver, alsa-lib, alsa-utils and alsa-firmwire

- try adding the "options snd-hda-intel model=lenovo" line to the end of the "/etc/modprobe.d/alsa_base" file.

- and after a restart it will work as expected, or very very close to that :))

2).  Getting hardware acceleration enabled with the 'problematic' Geforce Go 7300.

- Well in this case we could go the hard way, and re-compile our kernel and nvidia module by ourself,etc -- but there is  a lot more simple solution, and it will work almost 100% guaranteed.

- All we need to do is to get "envy". Debian/Ubuntu users just type in a terminal: "sudo apt-get install envy".use

- Now that we have envy installed we switch to the "real terminal" by pressing Ctrl+Alt+F1, and kill the GDM.

- "sudo /etc/init.d/gdm stop"

- after this we call "envy -t", and press 1.  You may have to solve some dependecies manually if the "process halts", but that's piece of cake especially under Debian/Ubuntu, because the problems will be listed by "apt" :)

- repeat the previous step after you solved the dependencies, and let the "envy" do his job.

When "envy" done, will ask you if you wanna let him to modify the "xorg.conf" -- answer yes to this question, then it will ask if you want to reboot -- chose yes again.

Now, if everything worked well, you should get to the "login" screen. If anything goes wrong just copy back the backed up "xorg.conf" and restart just X or the whole machine.

How to check if we have 3D acceleration? Well that's quite simple ... in a terminal  type: "glxinfo  | grep -i "direct"  "

If you get "direct rendering: yes" then you can celebrate and you have 3D acceleration, if you get something else, then you may have to digg, and modify your xorg.conf, because there are big chances that the problem is in there.

Also to check the 3D in action, type "glxgears" in a terminal window. :)) Enjoy :)

Regarding to issue number two, I tried: Unreal Tournament 2003 (with all the details to maximum), OpenArena,Sauerbraten (a.k.a Cube2), just to name a few, and they all worked very very well :)
