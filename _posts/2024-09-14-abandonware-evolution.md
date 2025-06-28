---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2024
title: "Abandonware: Evolution"
year: 2024
month: 9
monthly: false
propaganda: win95
tags: abandonware
---

# Abandonware: Evolution

[Evolution: The Game of Intelligent Life][evolution] is a hybrid *life-simulation-real-time-strategy* game released all the way back in the absolutely glorious year of `1997`.

It's considered pretty much [abandonware][abandonware] at this point, and sadly doesn't seem to be too happy on modern systems or in [Wine][wine] for that particular matter.

![evolution](/media/2024/evolution.png)

Fortunately, one doesn't have to be an absolute genius in order to determine that the actual culprit is the so called `SmartHeap Memory Management Library`, which can be found in the installation directory, aptly named as `Sh33w32.dll`. What a beautiful name, right? Takes one back!

```bash
$ winedump -j resource Sh33w32.dll 
Contents of Sh33w32.dll: 108032 bytes

Resources:
  VERSION Name=0001 Language=0409:
  |  SIGNATURE      feef04bd
  |  VERSION        1.0
  |  FILEVERSION    3.3.1.0
  |  PRODUCTVERSION 3.3.1.0
  |  FILEFLAGSMASK  0000003f
  |  FILEFLAGS      00000000
  |  FILEOS         VOS_NT_WINDOWS32
  |  FILETYPE       VFT_DLL
  |  FILESUBTYPE    00000000
  |  FILEDATE       00000000.00000000
  |  BLOCK "StringFileInfo"
  |    BLOCK "040904E4"
  |      VALUE "CompanyName", "MicroQuill Software Publishing, Inc."
  |      VALUE "FileDescription", "Memory Management Library for Win32"
  |      VALUE "FileVersion", "3.31"
  |      VALUE "InternalName", "SH33W32.DLL"
  |      VALUE "LegalCopyright", "Copyright \xa9 Arthur D. Applegate 1991-1996"
  |      VALUE "ProductName", "SmartHeap"
  |      VALUE "ProductVersion", "3.31"


Done dumping Sh33w32.dll
```

The natural next step was to look for a slightly newer version of the library. Now, in many cases this doesn't really solve the issue, because newer versions might have broken the ABI or changed behavior in some significant way, however, in this particular case the great *nymphs of luck* did favor me once more.

```bash
$ winedump -j resource Sh33w32.dll
Contents of Sh33w32.dll: 112688 bytes

Resources:
  VERSION Name=0001 Language=0409:
  |  SIGNATURE      feef04bd
  |  VERSION        1.0
  |  FILEVERSION    4.0.1.0
  |  PRODUCTVERSION 4.0.1.0
  |  FILEFLAGSMASK  0000003f
  |  FILEFLAGS      00000000
  |  FILEOS         VOS_NT_WINDOWS32
  |  FILETYPE       VFT_DLL
  |  FILESUBTYPE    00000000
  |  FILEDATE       00000000.00000000
  |  BLOCK "StringFileInfo"
  |    BLOCK "040904E4"
  |      VALUE "CompanyName", "MicroQuill Software Publishing, Inc.\0"
  |      VALUE "FileDescription", "Memory Management Library for Win32\0*"
  |      VALUE "FileVersion", "4.01\0\0004\v"
  |      VALUE "InternalName", "SHW32.DLL\0p"
  |      VALUE "LegalCopyright", "Copyright \xa9 1991-1997 Compuware Corp.\0004"
  |      VALUE "ProductName", "SmartHeap"
  |      VALUE "ProductVersion", "4.01\0\0\0"


Done dumping Sh33w32.dll
```

The more observant of you, most probably have noticed that the `InternalName` of this new version has been set to `SHW32.DLL`, and I just renamed it to match the filename the game has been linked with.

No fuss, no muss. Because I am a very kind and considerate person, just so it happens that I decided to upload a ZIP of this new version, which you can find and download over [here][dll].

```bash
$ unzip sh33w32.zip 
Archive:  sh33w32.zip
replace Sh33w32.dll? [y]es, [n]o, [A]ll, [N]one, [r]ename: y
  inflating: Sh33w32.dll
```

And, voila! No more pesky heap allocation tracking errors.

![evolution2](/media/2024/evolution2.png)

![evolution3](/media/2024/evolution3.png)

There are some issues with the music, it's all scrambled and distorted, which appears to be some sort of a timer and/or buffer underrun type issue, but since I do not care too much for music, I didn't end up digging into the issue any deeper, and besides at this point I'd have to whip out [Olly][olly] or [Ghidra][ghidra] to make any progress or sense of the issue anyway, and I honestly just can't be bothered.

Besides, one can disable the `Music` in the `Options` dialog. I always found it quite charming, when games combined the traditional [Win32][win32] GUI with some custom drawing and an [MDI][mdi] (*Multiple-Document Interface*), which was all the rage in the golden 90s and perhaps even early 2000s.

![evolution4](/media/2024/evolution4.png)

So, any lessons learned? Don't use arcane memory management libraries for absolutely no reason, especially if you want your games to be at least somewhat *"future proof"*, whatever that means.

But most importantly: *Kids, stay in school and remember to say no to malloc!*

[evolution]: https://en.wikipedia.org/wiki/Evolution:_The_Game_of_Intelligent_Life
[abandonware]: https://www.myabandonware.com/game/evolution-the-game-of-intelligent-life-a3f
[wine]: https://www.winehq.org/
[dll]: {{ "/extras/sh33w32.zip" | absolute_url }}

[olly]: https://www.ollydbg.de/
[ghidra]: https://ghidra-sre.org/
[win32]: https://learn.microsoft.com/en-us/windows/win32/learnwin32/learn-to-program-for-windows
[mdi]: https://learn.microsoft.com/ro-ro/dotnet/desktop/winforms/advanced/multiple-document-interface-mdi-applications?view=netframeworkdesktop-4.8
