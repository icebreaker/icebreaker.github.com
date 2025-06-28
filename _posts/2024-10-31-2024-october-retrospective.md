---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2024
title: 2024 October Retrospective
year: 2024
month: 10
monthly: true
propaganda: dd
music: NJ62S3A9wn0
tags: retrospective
---

# 2024 October Retrospective

Octobers always seem to fly by in an instant, and this one was no exception. Maybe it's one of the side effects of [Halloween][halloween], or [Donnie Darko][donniedarko]; I'll let you be the judge of that.

{% include youtube.html id="iyj6YAnaN_M" %}

## On moving fast and breaking things

I've been using Linux in some capacity from around 1998, and as my daily driver from around early 2006 or so; which means that I never, or very rarely moan about the constant utter breakage that plagues the Linux ecosystem. However, every now and then, the proverbial glass becomes a tad full, and overspills, which is when I end up rambling about it, usually in a fairly non contentious manner, without calling out names, etc.

This month was one of those moments, where I ended up spending around 4 hours downgrading packages starting from bash to terminal emulators, in order to figure out why a particular key-biding was broken.

Only to find out, that the problem was with tmux itself. This was a total shock to me, because never in a  thousand years would have I imagined something like this. There's a first time for everything, I guess.

As it turns out, tmux made key-bindings case-sensitive all of the sudden, without this being an opt-in feature.

```diff
-bind -n C-T new-window -c '#{pane_current_path}'
+bind -n C-t new-window -c '#{pane_current_path}'
```

Such a breaking change, should never ever been made without being locked behind an option first, giving ample time for people to prepare for it, and second, most definitely shouldn't have be part of a minor version release.

But, here we are -- backwards compatibility seems to be an unknown concept in the world of open source. If something worked in a certain way for the past 15+ years, then that thing is no longer a BUG, that is a feature, plain and simple, no arguments, if and/or buts about it.

Once this change lands in the stable distribution channels, it's going to be an absolute shit-show; believe you me! Going to stock up on popcorn, might even buy a popcorn maker for the occasion.

## Blast from the past

While digging through some of my old archives, I stumbled upon a old screen-shot of my Linux desktop, dated January 4th, 2006; and, I thought that I'd share it for nostalgia's sake.

Why was I digging through my archives? I'd really like to answer that question, I really would, but my lawyers have advised me to exercise my 5th amendment rights at this point in time!

![linux_2006_01_04](/media/2024/linux_2006_01_04.png)

This must have been Ubuntu 5.04 or 5.10, sporting GNOME 2 as its desktop environment.

The Linux port of the [Unreal Tournament 2003][ut2k3] demo, should need absolutely no introductions (I hope!), but the `apocdemo` directory might warrant a quick and dirty run through.

This is of course the [System Apoc][apocdemo] (pc demo) by [Astral][astral], which happens to come bundled with a Linux port.

{% include youtube.html id="UpZmge7V3Uo" %}

Unfortunately, running it today results in a rather disappointing segmentation fault.

```bash
$ gdb demo-lnx.elf 
Reading symbols from demo-lnx.elf...
(No debugging symbols found in demo-lnx.elf)
(gdb) run
Starting program: demo-lnx.elf 
process 31154 is executing new program: /proc/31154/exe
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
AFS Init: PAK contains 156 files.
Program received signal SIGSEGV, Segmentation fault.
0xf7a1c321 in __glDispatchCheckMultithreaded() from /usr/lib32/libGLdispatch.so.0
```

When I ran it during the writing of this post, I expected to bump into a `libc` related issue to be honest, but it appears that the executable has been statically linked, which explains why it ran in way back in 2006, despite being many years old at that point already.

The windows exeuctable on the other hand, seems to run just fine in Wine, so there's that.

## Hardware

I rarely, if ever praise or recommend hardware, but I've been using pretty much the same keyboard and wireless mouse combination for a couple of years now, so I thought that I'd give some shout-outs.

### [ThinkPad TrackPoint Keyboard II][thinkpadkeyboard]

![thinkpadkeyboard](/media/2024/thinkpadkeyboard.png)

Even after a few years of wear and tear, the battery still holds up surprisingly well. One gets used to the swapped FN  and CTRL after a while, but there's definitely a learning curve in the beginning.

The Print-Screen being right near alt is a god-send, for someone like myself taking quite a lot of screenshots.

### [ThinkPad Wireless Mouse][thinkpadmouse]

![thinkpadmouse](/media/2024/thinkpadmouse.png)

The scroll wheel seems to give out at around the 2 year mark, but other than that absolutely no complaints.

It's powered by a single AA battery, and seems to be super power efficient, considering the fact that I always forget when was the last time I changed the battery.

[donniedarko]: https://en.wikipedia.org/wiki/Donnie_Darko
[halloween]: https://en.wikipedia.org/wiki/Halloween_(franchise)
[thinkpadkeyboard]: https://www.lenovo.com/us/en/p/accessories-and-software/keyboards-and-mice/keyboards/4y40x49493
[thinkpadmouse]: https://www.lenovo.com/us/en/p/accessories-and-software/keyboards-and-mice/mice/4x30m56887
[ut2k3]: https://en.wikipedia.org/wiki/Unreal_Tournament_2003
[apocdemo]: https://www.pouet.net/prod.php?which=2582
[astral]: https://www.pouet.net/groups.php?which=80
