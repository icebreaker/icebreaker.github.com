---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2022
title: 2022 March Retrospective
propaganda: 2
music: fJy5FRrFI8U
topic: retrospective
---
2022 March Retrospective
===========
Has been a month already? It does look like it. The weeks are just flying by like no tomorrow!

At any rate, as promised, [Flordle][flordle], my boot-table and M$-DOS compatible text-mode [Wordle][wordle] clone, has indeed seen the light of day and is fresh out of my proverbial code oven.

![flordle](/media/2022/flordle.gif)

It took me a little bit more time than I expected, but it did turn out fairly well in the end, if you ask my personal and totally biased opinion.

Ended up rolling with **1024** built-in words and the final executable size of **8 kilo-bytes**. Could have been smaller if I would have compressed the list of words, but honestly I didn't feel like it was worth the effort to do so.

When I built and released [Floppy Bird][floppybird], there was one thing that I never ended up fixing before release and that was booting on certain laptops with floppy emulation.

It appears that certain BIOSes (in particular ones shipped with laptops) end up being too smart for their own good and attempt to patch the [BPB][bpb] (BIOS Parameter Block), which of course I didn't realize or know about. What this means is that, the BIOS ends up overwriting a few bytes after it loads up the boot sector (the first 512 bytes), which in turn messes everything up.

To work around, it's best to define a BPB or at least reserve some empty space for it at the beginning of the boot sector and then **"jump"** over it with a **"near"** *(short)* jump.

```nasm
bits 16                           ; 16 bit mode

; 0xEB, 0x76, 0x90
jmp start                         ; jump to start
nop                               ;
times 117 db 0                    ; reserve some empty space for BPB

start:
...
```

And, **BINGO**, problem solved! Thanks to this, **Flordle** should boot-up on *most hardware*.

Now that [Flordle][flordle] is out there, in the month of April, I intend to focus on the [USDZ][usdz] exporter. Would really like to figure and flesh out the under-document binary **crate** file portion of it, which is going to a going to be a lot of **FUN**. /s

Oh, another relatively small thing that I'd like to mention is that I ended up buying a license for [Typora][typora].

Typora is a really cool markdown editor and reader that **just** came out of **beta**. Even though I am a heavy **VIM** user, I still enjoy writing some of my markdown in it.

The in-line seamless WYSIWYG editing is really cool. Instant feedback. If I peeked your interest, there's a 15 day free trial version that you can play around with before you start throwing all your hard earned cash at your monitor.

[flordle]: /flordle
[floppybird]: /floppybird
[bpb]: https://en.wikipedia.org/wiki/BIOS_parameter_block
[wordle]: https://www.nytimes.com/games/wordle/index.html
[usdz]: https://graphics.pixar.com/usd/release/spec_usdz.html
[typora]: https://typora.io
