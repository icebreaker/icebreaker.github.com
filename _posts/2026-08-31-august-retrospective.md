---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2026/
title: 2026 August Retrospective
propaganda: kinoleto
music: iOvYGQtFBNM
tags: retrospective digital-archeology
---

2026 August Retrospective
=========================

The summer is officially over. That was quick, wasn't it? It feels like May was just a few weeks ago.

I am really hoping for a very extended warm *indian summer*, just like last year, especially, since I am just not ready to pull out the trench coats, and all that good stuff.

It's worth calling out that I don't touch grass all that often though, but still.

## Insidious: Out of the Further

![insidiousf](/media/2026/insidiousf.png)

The final trailer has dropped earlier this month, just before the theatrical release on the 21st.

{% include youtube.html id="gXjurDkYnEM" %}

This quick recap video might also come handy to remind yourself of the *overarching timeline*.

{% include youtube.html id="c07G-PQfH98" %}

## Hocus Focus

![hf2](/media/2026/hf2.png)

My good friends at [Stuck in Attic][stuckinattic] have released [Hocus Focus][hocusfocus] on the 7th.

{% include youtube.html id="FxYXTxbTDLg" %}

Make sure to check this one out, but only if you feel like it resonates of course.

## Fravia+

[Fravia][fravia] would have been 74 this month, and I know for a certain that he would have had a field day with all the large language models out there right now.

![fravia](/media/2026/fravia.png)

> This "award" was made for me by Master DaVinci\*\*, the greatest artist of the cracking world, in late 1998. Since all readers descending so deep inside my site are automagically supposed to be able Fravias *[sic]* and therefore capable of reversing all possible meanings of any images as well, I won't bother to point out the Moebius tape, nor the +HCU's cross in red email (because I'm a 'red' Fravia) on a golden subtle mace that recalls the style of the juwels *[sic]* used by the russian Zars... *[sic]* I just hope you'll have at least noticed the potentially "subversive" color of the reversed letters 'f'... and also the light rays contrasting the dark night of knowledge we're all at the moment compelled to live in :-)

** Referring to [DaVinci][davinci] of [Phrozen Crew][phrozencrew] *fame*. What an absolute blast from the past, am I right?

{% include youtube.html id="CKMk73gl9j8" %}

## The X-Files: I Want to Believe - *Vrach Frankenshteyn*

The only way to describe this new release in a way current and future generations can easily comprehend is by saying something to the effect of: *"What even is this? But, glad that I found it!"* .

{% include youtube.html id="vbmA8V65czY" %}

Very cringe dad jokes aside, this appears to be a *freshly coated* director's cut edition of sorts. Will most definitely check it out, when it finally lands on some of the other platforms.

## Enshitification: Exhibit #N

This is the second or third time in a short-while where the behavior of an existing `tmux` configuration option [changes between minor versions][tmuxissue600], for absolutely no good reason, that I can think of anyway.

How difficult is this for maintainers and/or authors to understand? Backwards compatibility is king, and is pretty much the only thing that really matters at the end of the day. Everything else is secondary.

```diff
-set -g message-style fg=default,bg=colour235,bold
+set -g message-style fg=default,bg=colour235,fill=colour235,bold
```

The way this change should have been done is by simply defaulting `fill` to the current `bg` color, if `fill` was not specified; then those who do not want the old behavior for some reason, they could explicitly set `fill` to something sensible like `none` or `off` instead.

But why do sensible things, when you can just go and break things instead? Where's the fun in that?

This is one of the many reasons why I absolutely dread doing upgrades these days, and generally reserve an entire weekend for the *glorious post-upgrade-fix-up festivities*.

And, absolutely no; using *clankers* in order to attempt to auto-fix things like this and others, that shouldn't have been broken in the first place is simply not an option that I am even willing to entertain.

*Hi, bye!*

## Ferrox

What in the name of John F. Kennedy is [Ferrox][ferrox]?

> **A pure-Rust GGUF inference engine. Dense and MoE, on CPU, Apple Metal, or CUDA.**

Okay, and, what's so special about it? Well, there are two reasons why I wanted to talk about it, with the first being this little notice that can be found in the `README`:

> ### AI full disclosure
>
> This software is developed with strong assistance from Cursor, Grok 4.5, GPT 5.6, and Claude Fable 5. Humans lead the ideas, the testing, and the debugging. We say this openly because it shaped how the project was built. If you are not happy with AI-developed code, this software is not for you. The acknowledgement below matters as much: none of this would exist without [llama.cpp](https://github.com/ggerganov/llama.cpp) and GGML, largely written by hand.

Now, while I understand why this *disclosure* exists, I also feel like one can tell fairly quickly by taking a peek at the source code itself, that this was simply not written by hand as it were. Ain't no way!

Everything is just too precise, too stiff, too artificial. Phun intended. That is not to say that verbosity is bad per-say, but there is such a thing as too on the nose, too tacky if you will pardon my French.

What is the second reason? The second reason why, I wanted to even get into this very touchy subject matter in the first place, is the fact that many a people out there, seem to be bragging about the fact that they are now producing absolutely copious amounts of code written in Rust, even though they don't find the language itself appealing, but it's all fine and dandy.

Because, well, they claim that they won't actually have to ever *read any of it* later. Make it, make sense!

I'll let you make of all this what you will, but personally I am not quite sure exactly how to feel about this whole situ just yet; but I do know that it can't possibly be a good sign of the shape of things to come.

Besides, my personal opinions on Rust have not changed, but let me tell you that it is possible to write Rust that is almost readable, and kind of easy on the eyes, it just takes a certain amount of sensibility in order to do so, which really defeats the whole purpose of using the language in the first place.

An excellent example of palatable Rust, that exists out there in the wilderness, would be [VoxType][voxtype].

## How Many Dudes?

![howmanydudes](/media/2026/howmanydudes.png)

[How Many Dudes][howmanydudes] is the ultimate game for the *monkey-brain*. Literally! Believe it or not this is yet another game created using [GameMaker][gamemaker].

The presence of `data.win` is always the first tell-tale sign, and if that wasn't enough:

```bash
$ strings HowManyDudes.exe | grep 'with GameMaker'
Made with GameMaker
```

{% include youtube.html id="qpKsnKF1CdA" %}

## Frostbyte's 1980s DOS Shareware Collection

![KISS](/media/2026/KISS.PNG)

I am always on the hunt for new *shareware* or *freeware* software collections out there, on the sideways and byways of the great *immortal interwebz*.

The great [Frostbyte's Collection][frostbytescollection], was totally not on my bingo card for this month or year for that matter.

Given that this been a relatively recent find, I just didn't have the necessary time to scour through it all in depth, however, I still wanted to point out something really creative that caught my eye.

```bat
Archive:  ./APOG/WPGPC1.ZIP
  Length      Date    Time    Name   
---------  ---------- -----   ----   
    58504  1989-09-08 20:36   WP50ART1.ZIP
    29752  1989-09-08 20:43   WP50ART2.ZIP
    69766  1989-09-08 20:57   WP50ART4.ZIP
    21188  1989-09-08 21:01   WP50ART5.ZIP
    88529  1989-09-08 21:18   WP50ART6.ZIP
    24924  1989-09-08 21:24   WP50ART7.ZIP
    18247  1989-10-26 06:26   WP50ART8.ZIP
        1  1987-03-09 20:52   (~~~~~~~.~~)
        1  1987-03-09 20:52   (RUN PBS.TO)
        1  1987-03-09 20:52   (  START.)
        1  1987-03-09 20:52   (_______.__)
       34  1987-05-06 01:29   PBS.BAT
     2432  1987-12-08 10:51   PBS-VIEW.COM
     2136  1989-10-25 21:37   PBS.TXT
    22022  1989-10-01 01:02   PKUNZIP.EXE
---------                     -------
   337538                     15 files
```

Using `1 byte` file entries, and then subsequently *re-purposing* the filenames as comments is such a stroke of *late 80s techno-gremlin-genius*, that I just had to call attention to it. How *kewl* is that?

Here's the `help screen` of the bundled `PKUNZIP.EXE` from the same archive.

![pkunzip](/media/2026/dos/pkunzip.png)

If the `WP50ART1.ZIP` filename, wasn't enough of a clue for you that this must be just additional clip-art package for [WordPerfect 5][wp5], then here's the `PBS.TXT` file displayed by running `PBS.BAT`, which in turn just clears the screen via: `CLS`, and then executes: `PBS-VIEW.COM PBS.TXT` rather unceremoniously.

![pbsview](/media/2026/dos/pbsview.png)

*Chef's kiss!*

## Hugging Face & NVIDIA

![huggingface](/media/2026/huggingface.png)

The only reason [Hugging Face][hf] exists in the first place is because *M1cr0sl0p* has dropped the ball again (*like so many times before!*), when it comes to the nesting ground of the *great evil git monster*, more colloquially known as just [GitHub][gh].

There's literally no reason, why [GitHub][gh] couldn't have become the *defacto* hosting ground for *models* and *datasets*, considering that the core infrastructure was already there and well proven that it could indeed *serve at scale* (*whatever that means!*).

Naturally, there's a lot of noise going around the `12.9B` green American dollars, that [NVIDIA][nvidia] is going to shell out for it though; which unsurprisingly enough, quite a lot of people seem to find to be rather excessive amount.

Even if [Hugging Face][hf] were to go the *way of the dodo*, post-acquisition, not much would be lost. Though one thing is fairly certain, most people out there have a real hard time with being able to distinguish between *manufactured*, and *real* necessity, especially when it comes products such as these.

## Grand Theft Auto VI: An Extended Look

While there has been an absolute metric ton of yapping, about a rumored collaboration between [Netflix][netflix] and [Rockstar][rockstar] in relation to the upcoming release of `Grand Theft Auto VI` for quite some time now, I just wasn't paying too much attention to it all.

So, when [Netflix][netflix] ended up dropping the [extended look][gta6netflix] gameplay footage, it really caught me by surprise to be perfectly honest, and I don't know what to make of it all. The second time, in a month? Huh?

{% include youtube.html id="tJbzMqJGH4k" %}

I am still not quite sure, what does this mean? Is [Netflix][netflix], bucking for a slice of the [YouTube][youtube] or [The Game Awards][tga] pie; or both at the same time, or what exactly is the end game with all this?

Naturally, it's all very Interesting nonetheless..

## OpenAI and Broadcom inference chip

The [press release][aibjalapeno] announcing this chip went largely unnoticed, or at least that was my perceived first impression about it.

Just a couple of short weeks ago, we wouldn't have heard the end of it, for months and months on end. Perhaps, it's just the timing (end of summer?), or perhaps all the looming *IPO* related *doom and gloom* talk that simply ends up tainting everything. Who knows?

In any event, it will be interesting to see if all these *chips* will actually end up standing the test of time, or if they will simply fizzle out, and people will quietly switch back to *NVIDIA* or *AMD* in the end.

I always found the parallel between access to *inference*, and access to *electricity* to be quite funny.

[AGEIA PhysX][physx], anyone? No? It doesn't ring a bell?

I know, I know, this is *very different*, it is not a consumer product. I'll see myself out now.

*P.S*: I know full well that mighty Google also has its own TPUs. Don't DM me about it. Cool, thanks!

## Flow of War

![flowofwar](/media/2026/flowofwar.png)

[Flow of War][flowofwar] is a fresh take on what I like to call the *auto-battler-real-time-strategy genre*. That was quite a mouthful, wasn't it? I know, and I accept full responsibility for all the pain this might have caused you.

 It is also the second game mentioned in this month that has been created in [GameMaker][gamemaker].

```bash
$ strings flow_of_war.exe | grep 'with GameMaker'
Made with GameMaker
```

{% include youtube.html id="3J7VN1izZbI" %}

## Omarchy

![omarchy](/media/2026/omarchy.png)

Unless you've been living under a rock or simply been refusing to come back to where the action is, and leave the *butterfly app* behind in the process, you probably have seen [Omarchy][omarchy] pop up somewhere.

I talked about it when it was just starting to pick up some steam, but I think that it's safe to say that it has now outgrown the meager needs and desires of *Jesus of Denmark*, and his trusty *co-partner*, none other than *Jason the mighty product Baptizer* himself.

Even some of the initial *naysayers* have come around, and started to *acknowledge* it as an actual *linux distribution* now. Even though, I consider this only to be something of a *half-ack*, but hey, nobody's perfect.

One thing that should probably be settled sooner than later is the matter of how does one pronounce it? 

We don't need or want, yet another *Git* or *Gif* situation on our hands, right? I hope not!

{% include youtube.html id="NYFGCESmikA" %}

Just don't leave this video as the last video to watch, before you consider going to bed.

You'll thank me in the morning.

## A rare interview with Roberto Ierusalimschy

[Roberto][roberto] doesn't do a lot of interviews, so it's always a special treat to listen to him.

{% include youtube.html id="jCZnFKk6M9A" %}

Please don't create *t-shirts* with the quote below; and most definitely do not walk around wearing such t-shirts at the next `#cppconf` or something.

> *A camel is a horse designed by a committee.*

## Picture Puzzle v2.0

Wanted to end the summer on the right foot by bringing out yet another ancient project from the chasms of my seemingly bottomless archives. 

The `v2.0` that I have stumbled upon here is from somewhere around `2005` or so, and it's written in Delphi, just like the past two projects that I have included in my previous summer retrospectives.

You'll be glad to notice, that there's no more cheesy skinning action going on, but there are *sound effects* when navigating the menus. Please, don't ask me why exactly is that the case! Thanks!

![ipp2](/media/2026/ipp2.png)

I have no idea what happened to `v1.0` to be perfectly honest. I don't seem to be able to find any traces of it; it's really not like me to just lose source code *willy-nilly* like that.

Oh, well! It can be happen to the best of us, I suppose.

![ipp2_2](/media/2026/ipp2_2.png)

I have totally forgot about the fact that ended up using this so called *extended* `OpenFileDialog`, with the image preview panel on the right, and all the other *little extra bits and bobs*.

If you were thinking that I ended up extending the standard `OpenFileDialog` available in the `Win32 API` myself, then you'll be sorely disappointed, as this is simply the [TOpenPictureDialog][TOpenPictureDialog] component that is included in the standard [ExtDlgs][ExtDlgs] (VCL) included with Delphi.

```pascal
object OpenPictureDialog1: TOpenPictureDialog
	Filter = 
		'All Supported (*.bmp;*.jpg)|*.bmp;*.jpg|JPEG Image File (*.jpg)|' +
		'*.jpg|Bitmaps (*.bmp)|*.bmp'
    Options = [
    	ofReadOnly,
    	ofHideReadOnly,
    	ofShowHelp,
    	ofPathMustExist,
    	ofFileMustExist,
    	ofNoDereferenceLinks,
    	ofEnableSizing
    ]
    Title = 'Load a Picture ...'
    Left = 8
    Top = 104
end
```

I was of course no longer sure myself, which is why I had to take a look to refresh my divine memory.

![ipp2_3](/media/2026/ipp2_3.png)

Another thing that caught me off guard, was the presence of the **Better Random** setting in the *Options*.

Now, obviously, I know what it means, but considering that I didn't touch this for nearly `20` years, I simply had absolutely zero recollections of what approach did I take when it comes the its implemenation.

I know that the anticipation must be killing ya'all, so without any further ado:

```pascal
// Park Miller random number algorithm.

procedure nseed(TheSeed:longint);
begin
	nrandom_seed:=TheSeed;
end;

procedure nrandomize;
begin
	asm
	push eax
	shr eax, 2
	add eax, 1
	mov nrandom_seed, eax
	pop eax
	end;
end;

function nrandom(n:LONGINT):LONGINT;
var base:longint;
begin
	base:=n;
    asm
    pushad
    mov eax, nrandom_seed
    xor edx, edx
    mov ecx, 127773
    div ecx
    mov ecx, eax
    mov eax, 16807
    mul edx
    mov edx, ecx
    mov ecx, eax
    mov eax, 2836
    mul edx
    sub ecx, eax
    xor edx, edx
    mov eax, ecx
    mov nrandom_seed, ecx
    div base
    mov eax, edx
    mov result,eax
    popad
    end;
end;
```

That is quite something, isn't it? It most definitely hits way harder than a fully locked and loaded *elephant gun*, if you get my precise meaning.

It just slapped in some assembly, that I most certainly copied from somewhere, and called it a day.

![salmon3](/media/2026/fishart/salmon3.png)

Did you notice `TheSeed` variable name? Could be the title of a very potent *B-rated-horror-flick*, right?

You know damn well where to send all those juicy royalty checks now.

Another, even more pertinent question is why on earth did I end up embedding several wallpapers with *Sharapova* inside the built-in gallery of *pictures* to pick from.

Alas, at the end of the day, I feel like some questions are better left unanswered, especially when they happen to go all the way back to one's late teenage years.

I am sure, that you'll agree.

## tmp.Out #5

*Volume number 5* of [tmp.Out][tmp.out] landed this month. And, what a total unit of a *beaut'* it is.

![tmpout_vol5](/media/2026/tmpout_vol5.png)

I didn't realize that the more *"old-school \*zine scene"* is was still thriving in the year `2026`.

## Dark Matter: Season 2 Opening

{% include youtube.html id="7D3_67Ds2uE" %}

## Crawl me baby, one more time!

I hate to be repetitious when it comes to the topic of [excessive crawling][creepycrawlers], but it keeps popping up every so often, and every single time, the general consensus out there seems to be that one should just keep hammering away at inventing more and more elaborate defensive techniques, in order to stay ahead of the curve.

Even, when those techniques start to eat into usability, and more often than not become so intrusive that they turn the whole user experience into a complete nuisance in itself.

This of course is a complete and utter disaster; naturally, it all plays into the hand of the *"AI is bad, and evil"* crowd out there, who were seeing *"evil people"* trying to *steal their content* everywhere, way before *"AI crawlers"* were even a thing, and now naturally they are having a field day with all of this.

It's like their personal wet dream! Paranoia feeding on paranoia, a very nasty and vicious cycle!

It's an absolute travesty, that even after all this time, the so called *frontier labs*, still have not taken any steps at all towards making their crawlers respect even the most basic forms of so called *"crawling netiquette"*.

Nobody is saying that each of these labs should cache petabytes worth of web-page content, but they could at least add some form of a time-based rate limiting system, so that if `1_000_000` people tell  their *agents* to look at a given `URL`, there won't be `1_000_000` individual `GET` requests against said `URL`.

How on earth is this not 100% pure and concentrated common sense? It boggles the mind to be honest.

## ~/.localgitconfig

Now, truth be told I do not keep a close eye on all the *features* that end up landing in `git`, but for some reason I never realized that one had the ability to include custom `.gitconfig` in a conditional fashion.

This comes in especially handy-handy if one needs to push into different repositories with a slightly different `user.email` for example, or simply need to reconfigure certain other aspects of a repository.

Here's what I ended up adding to the tail end of my `~/.gitconfig`:

```toml
# ...

[include]
    path = ~/.localgitconfig
```

And, then inside `~/.localgitconfig`:

```toml
[includeIf "gitdir:~/src/"]
	path = ~/src/gitconfig
```

This is very nice indeed! No more of that: *Dang it! I forgot to set `git user.email` shenanigans* ...

## The "Sackhoff" Show

![starbuck](/media/2026/starbuck.png)

{% include youtube.html id="LEfhn2P_-No" %}

{% include youtube.html id="jIT9PSUuJQE" %}

{% include youtube.html id="7FJD9_9VO90" %}

{% include youtube.html id="B__-6LUQprI" %}

## Monthly Amazon "*Book Review*"

I remember purchasing a physical copy of [Game Engine Architecture][gea], only because everybody and their respective grandmother was yapping about it back in the day.

![gea](/media/2026/gea.png)

Let's see what the fine folks over at Amazon have to say about it.

![gearev1](/media/2026/gearev1.png)

![gearev2](/media/2026/gearev2.png)

## Monthly *"Coup de cœur"*

I am not sure if you were aware of the state of "[Still Sucking Nature][stillsuckingnature]" way back in the year of `2003`.

{% include youtube.html id="XS4FqNTO2xA" %}

Regardless, please enjoy the show by the [Federation Against Nature][fan], and don't forget to try the fish!

[fan]: https://www.pouet.net/groups.php?which=216
[stillsuckingnature]: https://www.pouet.net/prod.php?which=9461
[TOpenPictureDialog]: https://docwiki.embarcadero.com/Libraries/Florence/en/Vcl.ExtDlgs.TOpenPictureDialog
[ExtDlgs]: https://docwiki.embarcadero.com/Libraries/Florence/en/Vcl.ExtDlgs
[tmp.out]: https://tmpout.sh/5/
[omarchy]: https://en.wikipedia.org/wiki/Omarchy
[stuckinattic]: https://en.wikipedia.org/wiki/Gibbous_-_A_Cthulhu_Adventure
[hocusfocus]: https://store.steampowered.com/app/4202710/Hocus_Focus/
[fravia]: https://en.wikipedia.org/wiki/Fravia
[davinci]: https://defacto2.net/p/davinci
[phrozencrew]: https://defacto2.net/g/phrozen-crew
[frostbytescollection]: https://archive.org/details/frostbyte_1980s_DOS_collection
[wp5]: https://en.wikipedia.org/wiki/WordPerfect
[tmuxissue600]: https://github.com/catppuccin/tmux/issues/600
[ferrox]: https://github.com/antonellof/ferrox
[voxtype]: https://github.com/peteonrails/voxtype
[howmanydudes]: https://store.steampowered.com/app/3934270/How_Many_Dudes/
[flowofwar]: https://store.steampowered.com/app/2637210/Flow_Of_War/
[gamemaker]: https://en.wikipedia.org/wiki/GameMaker
[gea]: https://www.amazon.com/dp/1568814135
[creepycrawlers]: https://people.kernel.org/monsieuricon/creepy-crawlies
[hf]: https://huggingface.co/
[gh]: https://github.com/
[physx]: https://en.wikipedia.org/wiki/PhysX
[aibjalapeno]: https://openai.com/index/openai-broadcom-jalapeno-inference-chip/
[nvidia]: https://www.nvidia.com/en-us/
[netflix]: https://www.netflix.com/
[rockstar]: https://www.rockstargames.com/
[gta6netflix]: https://www.netflix.com/title/83035795
[youtube]: https://youtube.com/
[tga]: https://en.wikipedia.org/wiki/The_Game_Awards
[roberto]: https://en.wikipedia.org/wiki/Roberto_Ierusalimschy
