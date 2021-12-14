---
layout: post
title: 2020 Retrospective
propaganda: 5
---
2020 Retrospective
==================
It's that time of the year once more, however considering what a ghastly year
2020 was, I will cut the _intro_ short and not antagonize you any further than
absolutely necessary. If you were expecting wholesome eulogies, this is not the
spot, and you might want to check out medium.

Before getting too much into the weeds of things, let's kick it off with the
mandatory **last year in commits** _chart_ kindly provided by GitHub.

![][0]

As you are probably aware by now, I am always hacking on multiple projects at
any given time, and this year wasn't any different, despite all that has
transpired. While on the surface, sometimes it might appear that my _side
projects_ have nothing in common with each other, there's always some overlap
even if only in the sense of building a proof of concept of some _piece_ that
might fit into some of my other projects.

But, that's enough of that! Let's take a look at some of my highlights.

marmota
-------
![][500]

Earlier this year I ended up releasing [marmota][1], an opinionated
minimalist terminal emulator based on VTE.

It's roughly 600 lines of C, and all configuration is done at compile time.

It has all the basic features that one might expect from a *modern* terminal
emulator, including support for opening links, etc.

However, it doesn't have built-in support for _tabs_, because you are better off
with using a terminal multiplexer like tmux or screen to fulfill that need.

gustav.vim
----------
Ended up writing another vim plugin, called [gustav][2], which is a very simple
GitHub Flavored Markdown compatible task/todo manager.

![][100]

I also ended up making some enhancements to my previously released [asynctotem.vim][3]
and [fastopen.vim][4] plugins.

dose2
-----
Ported [dose2][5] by [mfx][6] to WASM (web assembly) by leveraging [emscripten][8].

![][200]

Click [here][7] to see it in action.

DOSKit
------
DOSKit is a "small framework" that I started putting together to allow one to
write small hobbyist DOS games without the need to install a 16 bit compiler
toolchain.

How is that possible? It turns out that one can _abuse_ gcc/clang and have it
spit out 16-bit _compatible_ machine code, for the most part. Obviously, it's
not without its problems, but hey it's jolly good fun to play around with stuff
like this.

![][300]

In the screenshot above, you can see a small example embedding a TGA image with
a palette and then _blitting_ it into _video memory_.

And yes, it _produces_ .COM files, which makes things more fun, because you have
to limit yourself to 64K.

It's not ready for prime-time just yet, but I might manage to get it over the
finish line and release it sometime next year.

maksu
-----
After using premake4 and then GeNIE for a number of years, I woke up one morning
and said to myself, I am going to build my own "build automation tool", but
unlike premake, it will combine Lua + Ninja into a single statically linked self
contained executable, that will enable single command builds across Linux,
MacOS, Windows and FreeBSD.

Cross-compilation will not be an _after thought_, but rather a built-in as a
core concept from the get go. Therefore, adding new toolchains (compilers,
platforms) will not require hacks and monkey-patching.

You can just check-in the executable with the source code in your favorite
source control system and bada-boom anyone who checks out the source code can
build by running a single command. As with anything, there are and will be some
_caveats_, but nothing too out of the ordinary.

I know that this might sound too good to be true, and maybe some of you might
even say, why on earth do we need another _build tool_, but it's going to
happen, hopefully sometime early next year if the stars and planets align.

Calling it `maksu` for the time being, and as you probably guessed by now, it
will be driven by a so called `Maksufile`.

GitHub Arctic Code Vault
-----------------------
The [Arctic Code Vault][9] was something totally unexpected and perhaps one of
the very few truly _cool_ things that have transpired this past year.

At least one of my personal projects, [Floppy Bird][10], a boot-able _flappy bird_
clone that I wrote in 16 bit assembly, got included in the _vault_. Even though
this is one of my most popular projects of yesteryear's, its inclusion in the
vault still caught me off guard.

![][400]

What a pleasant surprise.

However, I do want to bring up the fact that there was little to no information
to be found about this whole thing and I noticed that I got the "Arctic Code
Vault" badge totally by accident, when looking at my GitHub profile.

Also, the criteria based on which eligible projects/repositories were chosen to
be included in the vault should have been communicated in a better way, rather
than being buried and very hard to find.

GitHub Codespaces
-----------------
A few months ago, I got _early access_ to [GitHub Codespaces][11].

What is _codespaces_? Simply put, it allows you to open any GitHub repository in
a purely web based IDE. And this IDE is really just a VSCode that runs in your
browser, rather than as a _standalone_ executable via the means of _electron_.

It does look like a rather promising piece of technology. What makes it really
convenient is that you get full shell access to the container that is spawned,
which allows you to install any tools that you might need, expose ports, etc.

Another very convenient thing is that if you have a `dotfiles` repository, it
will pull it in and setup your "terminal" and environment automatically.

I might write a more comprehensive standalone review/article about it next year.

Thoughts on Go
--------------
With the advent of [Go][12] 1.15.x, I thought that it's about high-time I give Go _a
go_, pun intended.

My initial impressions were good, but I still need to spend some more time with
it and write something fairly non-trivial before jumping to or drawing any
definitive conclusions.

There are _still_ a couple of things that might rub you the wrong way, if you
are person who wrote any non-trivial amount of C/C++ (myself included), but it
does look like a promising language to _complement_ C/C++, definitely not as a
_replacement_.

[0]: /media/github/2020.png
[1]: https://github.com/icebreaker/marmota
[2]: https://github.com/icebreaker/gustav.vim
[3]: https://github.com/icebreaker/asynctotem.vim
[4]: https://github.com/icebreaker/fastopen.vim
[5]: https://www.pouet.net/prod.php?which=3289
[6]: http://mfx.scene.org/
[7]: /dose2
[8]: https://emscripten.org
[9]: https://archiveprogram.github.com/
[10]: https://github.com/icebreaker/floppybird
[11]: https://github.com/features/codespaces
[12]: https://golang.org/
[100]: /media/2020/gustav.gif
[200]: /media/2020/dose2.png
[300]: /media/2020/doskit.png
[400]: /media/games/floppybirdos.gif
[500]: /media/2020/marmota_red.png
