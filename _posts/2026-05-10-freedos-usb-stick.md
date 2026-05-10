---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2026/
title: FreeDOS on a USB stick
propaganda: msdos
tags: dos abandonware digital-archeology
---

# FreeDOS on a USB stick

I looked around and couldn't find any reasonably good *guide* to install [FreeDOS][freedos] on a USB stick with persistence. So, I thought to myself that I'd write something up, because why not?

Now, why on earth would one want a USB stick with [FreeDOS][freedos]? I don't know, perhaps one doesn't really need any particular reason. You can just do things! Haven't you heard?

## Installation

Anyway, let's get down to it. I'll be using a rather ancient Kingston USB stick clocking at a whopping `2GB` of available storage.

![kingston_2gb](/media/2026/kingston_2gb.png)

What a beaut, right? Brings back to late 2007 and early 2008 vibes, Way back when all those snotty nosed brats in tweed jackets got all us screwed over. Those were the good old days. Aye?

Other than the stick at hand, we'll need [QEMU][qemu], and the latest version of [FreeDOS][freedos], which happens to be `1.4` at the time of me writing this down.

```bash
$ mkdir freedos
$ cd freedos
$ wget https://www.ibiblio.org/pub/micro/pc-stuff/freedos/files/distributions/1.4/FD14-LiveCD.zip
$ unzip FD14-LiveCD.zip
```

This should result in a  lovely ISO file called `FD14LIVE.iso` in the current directory.

Now it's time to boot it up. Please make sure to replace `/dev/sdX` with the device that corresponds to your USB stick, when running the incantations outlined below.

```bash
$ sudo -E qemu-system-i386 \
	-cpu pentium \
	-m 32 \
	-vga cirrus \
	-drive file=/dev/sdX,format=raw \
	-cdrom `pwd`/FD14LIVE.iso \
	-boot d
```

If everything went according to plan, you should be greeted with a screen that looks something like the one below.

![01](/media/2026/freedos/01.png)

You'll want to pick the first option, namely: `Use FreeDOS 1.4 in a Live Environment mode`.

The next step is to partition, and format the disk with `fdisk`. This could have been done beforehand of course, with a slightly more comfortable tool like [GParted][gparted], but where's the fun in that? We are very *bullish-10x-LLM-augmented-DOS-engineers* here, am I right?

To do so, simply type `fdisk` and take it from there. It all should be pretty self explanatory. I decided to have two partitions, a smaller `C:` for the OS and `D:` using up all the remaining space for everything else.

Make sure to toggle the `bootable` flag on the `C:` partition.

![02](/media/2026/freedos/02.png)

Finally, type `shutdown`, then run `qemu-system-i386` again, making sure to pick the first option once more, then it's time to format both partitions by typing in the following incantations:

```bat
format C:
format D:
shutdown
```

![03](/media/2026/freedos/03.png)

![04](/media/2026/freedos/04.png)

Run `qemu-system-i386` for the third time, picking the `Install to harrdisk` this time around.

![05](/media/2026/freedos/05.png)

![06](/media/2026/freedos/06.png)

![07](/media/2026/freedos/07.png)

![08](/media/2026/freedos/08.png)

![09](/media/2026/freedos/09.png)

![10](/media/2026/freedos/10.png)

![11](/media/2026/freedos/11.png)

![12](/media/2026/freedos/12.png)

![13](/media/2026/freedos/13.png)

![14](/media/2026/freedos/14.png)

At end of the installation, make sure to pick `Yes - Please reboot now`, and then subsequently `Boot from system harddisk`

![15](/media/2026/freedos/15.png)

![16](/media/2026/freedos/16.png)

If all went well you should find yourself at a `C:\>` prompt. You'll want to type `shutdown` for the last time, and boot it all up again, making sure to adjust the incantation to `-boot` from the `C:` partition instead.

```bash
$ sudo -E qemu-system-i386 \
	-cpu pentium \
	-m 32 \
	-vga cirrus \
	-drive file=/dev/sdX,format=raw \
	-boot c
```

Now, let's have a little chat about the *free space* situation. There's around `535MB` free space left on `C:`, and we got all the free space in the world on `D:`, or `1.2GB` to be more exact.

Who wouldn't have killed for a `2GB` hard-drive back in the day, am I right? I was fortunate enough not to have to endure the pain of `20MB` and `40MB` hard-drives, as my very first PC had a `540MB` one.

## Bonus CD

You'll very likely want to grab the so called `Bonus CD`, and install even more software, which you can do fairly easily simply by executing the following incantations:

```bash
$ wget https://www.ibiblio.org/pub/micro/pc-stuff/freedos/files/distributions/1.4/FD14-BonusCD.zip
$ unzip FD14-BonusCD.zip
$ sudo -E qemu-system-i386 \
	-cpu pentium \
	-m 32 \
	-vga cirrus \
	-drive file=/dev/sdX,format=raw \
	-cdrom `pwd`/FD14BNS.iso \
	-boot c
```

I can never remember the name of the package manager for the life of me. It's called `FDIMPLES`, which rhymes with `PIMPLES`, but my brain simply refuses to cooperate with me when it comes to recalling it.

![17](/media/2026/freedos/17.png)

![18](/media/2026/freedos/18.png)

![19](/media/2026/freedos/19.png)

Based on the things that I have selected to install, I was left with `388MB` on the `C:` partition after it was all said and done.

![20](/media/2026/freedos/20.png)

What did you pick? Decisions, decisions.

## Extras

If you are like me, then you'll probably want to add in even more extras into the mix, because life is way too short without some spice and excitement.

| Name                                | Version | Type    | License     | Download                     |
| ----------------------------------- | ------- | ------- | ----------- | ---------------------------- |
| [Catacomb 3-D Abyss][catacomb3d]    | 1.13    | Game    | Shareware   | [catabs13.zip][catabs13]     |
| [Wolfenstein 3-D][wolf3d]           | 1.4g    | Game    | Shareware   | [1wolf14.zip][1wolf14]       |
| [DOOM][doom]                        | 1.92    | Game    | Shareware   | [doom19s.zip][doom19s]       |
| [Commander Keen: Episode VI][keen6] | Promo   | Game    | Shareware   | [keen6promo.zip][keen6promo] |
| [Tomb Raider][tr]                   | Part 1  | Game    | Demo        | [tombdemo.zip][tombdemo]     |
| [Tomb Raider][tr]                   | Part 2  | Game    | Demo        | [tombraid.zip][tombraid]     |
| [Cracker Editor][crackereditor]     | 1.16a   | Utility | Freeware    | [cre116a.zip][cre116a]       |
| [PictView][pictview]                | 1.94    | Utility | Freeware    | [pictview.zip][pictviewz]    |
| [Norton Commander][nc]              | 5.50    | Utility | Abandonware | [nc.zip][wwnc]               |
| [Borland C++][bc]                   | 3.0     | IDE     | Abandonware | [bcpp.zip][wwbcpp]           |
| [Turbo C++][tc]                     | 3.0     | IDE     | Abandonware | [tbcpp.zip][wwtbcpp]         |
| [Turbo Pascal][tp]                  | 7.01    | IDE     | Abandonware | [tp7.zip][wwtp7]             |

I ended up dropping these on the `D:` partition inside an aptly named `SETUP` directory, and then installing them from there to `C:` as one would from an actual floppy disk image.

The `SETUP` files for these will amount to about `45MB` in total when unpacked.

## RAM Disk

If you have embarked on this journey, you probably are going to be running [FreeDOS][freedos] on a system that has plenty of RAM to spare; way more in fact that you ever could have dreamed off during the days of old, and therefore spinning up a RAM Disk or two is generally just what the doctor ordered.

Luckily, this is relatively painless to do with [FreeDOS][freedos], and it comes down to using `RDISK`.

In `FDCONFIG.SYS`:

```bat
23?DEVICEHIGH=C:\FreeDOS\BIN\RDISK.COM /S64 /:E
```

And, then in `FDAUTO.BAT`:

```bat
IF EXIST E:\NUL MKDIR E:\TEMP
IF EXIST E:\TEMP\NUL SET TEMP=E:\TEMP
IF EXIST E:\TEMP\NUL SET TMP=E:\TEMP
```

Finally, if let's say you wanted to run and play `WOLF3D` from the RAM disk, you'd do:

```bat
xcopy C:\WOLF3D E:\WOLF3D /I /S /E
E:
cd WOLF3D
WOLF3D.EXE
```

## Snapshot

At this point, it might be a good idea to take a full snapshot of the drive for safe keeping:

```bash
$ sudo dd if=/dev/sdX of=usbstick.img bs=1M
```

This snapshot then can be restored at a later time, by simply running the following incantation:

```bash
$ sudo dd if=usbstick.img of=/dev/sdX bs=1M
```

Plus, you won't have to go through the pain of installing and configuring everything if something gets all tangled up after a botched install.

## The End

The nice thing about this setup is that both partitions are good old regular `FAT32`, so one can just copy to/from freely, without having to go through [QEMU][qemu] or use any other special disk imaging utility.

Some of you might be asking right now, why didn't I just create an empty `.img`, install to that via [QEMU][qemu], then use `dd` to perform a raw copy to the USB stick with the following incantations:

```bash
$ qemu-img create usbstick.img 2G
$ qemu-system-i386 <...>
$ dd if=usbstick.img of=/dev/sdX bs=1M
```

Wouldn't that also been faster? The answer to that question is as always a resounding: *"It depends!"* 

To paraphrase a very dear acquaintance of mine with excellent taste in food and expert level culinary skills: *"After all, as I am sure your mother tells you, and most certainly told me, it's always important to try new things".*

If you are in the mood for having some *real period appropriate fun*, then you could try following this  [guide][fswolf3d] by [Fabien Sanglard][fabiensanglard], and take a stab at compiling [Wolfenstein 3-D][wolf3d] from *source*, the way it was intended way back in the great year of `1992`.

[freedos]: https://www.freedos.org/
[qemu]: https://www.qemu.org/
[floppybird]: https://www.ibiblio.org/pub/micro/pc-stuff/freedos/files/repositories/unstable/html/en/games/flpybird/20250409.9/index.html
[flappybird]: https://en.wikipedia.org/wiki/Flappy_Bird
[theborgcollective]: https://memory-alpha.fandom.com/wiki/Borg_Collective
[gparted]: https://gparted.org/
[fswolf3d]: https://fabiensanglard.net/Compile_Like_Its_1992/index.php
[fabiensanglard]: https://fabiensanglard.net/
[wolf3d]: https://en.wikipedia.org/wiki/Wolfenstein_3D
[pictview]: http://www.pictview.com/
[crackereditor]: https://www.sac.sk/files.php?d=17&amp;l=C
[catacomb3d]: https://en.wikipedia.org/wiki/Catacomb_3-D
[doom]: https://en.wikipedia.org/wiki/Doom_(1993_video_game)
[keen6]: https://en.wikipedia.org/wiki/Commander_Keen
[tr]: https://en.wikipedia.org/wiki/Tomb_Raider_(1996_video_game)
[nc]: https://en.wikipedia.org/wiki/Norton_Commander
[bc]: https://en.wikipedia.org/wiki/Borland_C%2B%2B
[tc]: https://en.wikipedia.org/wiki/Turbo_C%2B%2B
[tp]: https://en.wikipedia.org/wiki/Turbo_Pascal
[wwnc]: https://winworldpc.com/product/norton-commander/55x
[wwbcpp]: https://winworldpc.com/product/borland-c/30
[wwtbcpp]: https://winworldpc.com/product/turbo-c/3x
[wwtp7]: https://winworldpc.com/product/turbo-pascal/7x
[pictviewz]: /extras/dos/utils/pictview.zip
[cre116a]: /extras/dos/utils/cre116a.zip
[tombraid]: /extras/dos/games/tombraid.zip
[tombdemo]: /extras/dos/games/tombdemo.zip
[keen6promo]: /extras/dos/games/keen6promo.zip
[doom19s]: /extras/dos/games/doom19s.zip
[1wolf14]: /extras/dos/games/1wolf14.zip
[catabs13]: /extras/dos/games/catabs13.zip
