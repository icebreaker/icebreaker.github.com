---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2026/
title: 2026 May Retrospective
propaganda: tb
music: Q364ssrqhEU
tags: retrospective
---

2026 May Retrospective
=========================

In my April retrospective. I have hinted at how we might have just heard the first gong that signaled the beginning of the end of the so called unlimited and highly subsidized token era.

Roughly a month or so later, it feels like it's a lot more serious than that, and a whole lot of people might find themselves feeling like their favorite toys were taken away by the end of year.

`2026` is shaping up to be one of the most interesting years since the *annus horribilis* that turned out to be `2020`, sans the mighty tiger king, the toilet paper craze, and all that sweet banana bread of course.

## The Boroughs

This was a rather unexpected surprise to be perfectly honest. Take Dr. Octopus, the Stranger Things and Cocoon. Blend it all together really well, and you get something approximately resembling [the Boroughs][theboroughs].

{% include youtube.html id="PsvUvqXoTpE" %}

I really hope that this won't be yet another one of those *single-season-wonders*, like the rather excellent [Night Sky][nightsky], which sadly has never seen second season.

{% include youtube.html id="XLnhAbbMkEY" %}

## Future Shock (Documentary)

{% include youtube.html id="fDza2hiU9WQ" %}

There's no greater raconteur than [Orson Welles][orsonwelles]. Enough said.

## Abandoned Rail Road

{% include youtube.html id="SPuTvFGKo1Y" %}

## The "Sackhoff" Show

![starbuck](/media/2026/starbuck.png)

{% include youtube.html id="XB5o_lf5m-s" %}

{% include youtube.html id="1wQdFeEOVsE" %}

{% include youtube.html id="J25PrOUWEPc" %}

{% include youtube.html id="cAbo8DeACtc" %}

## Monthly "*Layoffs Report*"

![yogibear](/media/2026/yogibear.png)

According to [Layoffs.fyi][layoffsfyi], there were `124_636` people laid off in `2025`,  and at the time of me writing this up in `2026`, the count is at a whopping `116_739` already.

We are not even halfway through the year. Let that sink in, *phun* intended. It's also worth keeping in mind that the actual number is way higher than whatever is being reported on [Layoffs.fyi][layoffsfyi].

## Monthly "*Book Review*"

This months' book has never been translated into English, and as a direct result cannot be found on Amazon, but I still have a physical copy of it in my relatively tiny collection of *techno-babble*, which is why I decided to share it with you here.

![limbpas](/media/2026/limbpas.png)

I happen to own the edition displayed on the left (*white and bordeaux*), and I totally didn't expect there to be another edition of it, considering that it is really nothing to write home about to be perfectly honest.

Don't want to be too harsh on my fellow countryman here, but it is the truth. Why did I buy it then, back in the day? Well, it had a couple of chapters on the `CHR` and `FLI` formats, which raised my interest at a glance, only to be disappointed once I actually got the chance to read through it all.

### Runtime Error 200

While I am on the subject of Pascal, I thought that I'd do a little detour and talk about the infamous `Runtime Error 200`. Do you still remember it? While it probably never caused the mass hysteria that the various `Y2K` bugs ended up causing, it was still something that generated quite a bit of a stir back in the good old days to put it bluntly.

![trout_salmon2](/media/2026/fishart/trout_salmon2.png)

People of course would spread all sorts of FUD about it, like the claims that it was an actual CPU hardware bug, which of course was total and utter nonsense. It was nothing more than a good old fashioned bug inside the `CRT` library that shipped with the respective Pascal versions.

The resolution of the timer (PIT) controllable via the BIOS interrupts was about `55 ms`. Now, in order to implement the `Delay` procedure within the `CRT` library, there was a tiny bit of initialization code that would be performed early in the execution of any executable that happened to be compiled and linked with the affected versions.

This initialization code would try to measure the amount of ticks that could be performed within this `55 ms` interval. The ticks would then be divided by `55` in order to get the final result, which then in turn would be used by the `Delay` procedure later.

As CPUs were getting faster, the number of ticks that could be performed within the given internal would increase, until it has gotten to the point where the result of the division would no longer fit within a `16-bit` register.

This was then mistakenly classified as a `division by zero` error by the `CRT`, hence the peculiar runtime error message, which makes this whole affair even more confusing.

```pas
program Hello;

uses crt;

begin
  writeln('Hello, world!');
  Delay(1000);
end.
```

```bash
$ TPC HELLO.PAS
$ NDISASM HELLO.EXE > HELLO.ASM
```

```asm
; ...
00000140  268A1D            mov bl,[es:di]
00000143  B8E4FF            mov ax,0xffe4
00000146  99                cwd  
00000147  E83C02            call 0x386
0000014A  F7D0              not ax
0000014C  F7D2              not dx
0000014E  B93700            mov cx,0x37    ; = 55
00000151  F7F1              div cx          
00000153  A35E00            mov [0x5e],ax
; ...
```

Oh, the good old days, am I right?

## Monthly *"Coup de cœur"*

This is the last one from the [Mekka & Symposium 2000][mekka2000], alright? [Mikrostrange][mikrostrange] by [Haujobb][haujobb] happens to be one of the most memorable demos from around this time frame.

{% include youtube.html id="U9Z2ZUAysWM" %}

Please enjoy the show, and don't forget to try the fish!

[mekka2000]: https://www.pouet.net/party.php?which=26&amp;when=2000
[layoffsfyi]: https://layoffs.fyi/
[yogibear]: https://en.wikipedia.org/wiki/Yogi_Bear
[mikrostrange]: https://www.pouet.net/prod.php?which=1092
[haujobb]: https://www.pouet.net/groups.php?which=31
[theboroughs]: https://en.wikipedia.org/wiki/The_Boroughs
[nightsky]: https://en.wikipedia.org/wiki/Night_Sky_(TV_series)
[orsonwelles]: https://en.wikipedia.org/wiki/Orson_Welles
