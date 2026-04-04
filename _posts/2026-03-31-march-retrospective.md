---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2026
title: 2026 March Retrospective
propaganda: ddr
music: bqxYLZ885RA
tags: retrospective
---

2026 March Retrospective
=========================

This month was pretty much dominated by war, death, sex, drugs, layoffs, [DLSS 5][dlss5], and last but not least quite a few highly anticipated indie-game releases.

But, isn't this actually the case every single month nowadays? A fair point *my liege*.

## DLSS 5

![jensen](/media/2026/jensen.png)

Let's start with the elephant in the room, just to get it out of the way. Personally, I couldn't care less about [DLSS][dlss] or any other related technology, simply because *realism* is not something that interests me in the slightest when it comes to video games or movies for that matter.

While I love eye-candy as much as the next person out there, I never ever play anything simply due to its realism or graphical fidelity. It's just not my thing, and it never was. However, unlike others out there, I have no quarrel with people who do and very much expect games to deliver on this front.

The last thing I am going to say on this matter is that if people don't want [DLSS 5][dlss5] to *become a thing*, then it's time they start shipping games (*and game engines!*), that work just fine on 15 years old hardware.

## The "Sackhoff" Show

![starbuck](/media/2026/starbuck.png)

{% include youtube.html id="AjgazB-e170" %}

{% include youtube.html id="O29kTA-BSK8" %}

{% include youtube.html id="kClqpJgj6uE" %}

{% include youtube.html id="uw0dcPmw2aw" %}

## Chop Shop

![chopshop](/media/2026/chopshop.png)

[Chop Shop][chopshop] has been released, and I feel like it didn't really get the attention that it deserved. But, I am biased because like I said when I first mentioned it, I happen to know one half of the team.

{% include youtube.html id="qQp2WtReg60" %}

Look at these absolutely gorgeous achievement icons. This alone should convince you to buy it.

![chopshopachievements](/media/2026/chopshopachievements.png)

Here is my review of the game that I have posted on Steam.

> The best way to describe this game is by imagining that in some alternate timeline Dave the Diver and Shank had a baby. It has a very unique look and feel, and the controls are pretty tight as well.
>
> Even though this particular sub-genre is not my usual cup of tea, I still felt engaged, while I played through the first couple of levels.
>
> Last but not least, there's a lot of attention to detail, and one can see that this is nothing short of a labor of pure and concentrated love.
>
> Go play it. Chop, chop!

## Mewgenics

![mewgenics](/media/2026/mewgenics.png)

[Mewgenics][mewgenics] has been one of the most anticipated games out there. While not my personal cup of tea, I still wanted to mention it as it's an [Edmund McMillen][edmundmcmillen] game.

{% include youtube.html id="kNKoHJKs20A" %}

I find it funny how people were surprised that it sold over `150_000` copies in the first `6` hours.

## Slay the Spire 2

![slaythespire2](/media/2026/slaythespire2.png)

[Slay the Spire 2][slaythespire2] has been yet another highly anticipated title, that fans of the first installment have been ardently waiting for the past couple of years.

{% include youtube.html id="ttVtllHkb4E" %}

I am just not fan of this genre. Please don't try to take a shot every single time I say that.

## Tangy TD

![tangytd](/media/2026/tangytd.png)

[Tangy TD][tangytd] is a tower defense game built by a *game-dev-twitch-streamer* *(that was quite a mouthful, wasn't it?*), who also happens to be known on the great information super-highway as [Cakez77][cakez77].

{% include youtube.html id="wyjcqPCvk5M" %}

I was pleasantly surprised that it made it over the finish line to be perfectly honest, and then it went viral a couple of times after launch, which helped with the sales quite a bit.

## Stronghold Crusader: Definitive Edition

![scde](/media/2026/scde.png)

Didn't I call it last time? Yes, I did. It would have been absolutely silly not to bring out more content when the game is still relatively hot.

{% include youtube.html id="oJT1Y7U6kNc" %}

## Slug

![slug](/media/2026/slug.png)

[Slug][slug] by [Eric Lengyel][ericlengyel] has been set free this month; both in terms of [the patent][slugpatent] and the relevant [reference implementations of the shaders][slugshaders] that power it under the hood.

The *game-dev community* took no time at all to embrace it all, and various implementations have popped up quicker than mushrooms after a warm spring rain.

Due to its reliance on partial derivatives (*read*: [fwidth][fwidth]) and integer math, which could lead to all sorts of weird issues on older hardware, I wouldn't personally recommend it despite all its clear advantages.

## GitHub

When GitHub ended up without an actual CEO, and ceased to be a somewhat independent organization within the Microsoft umbrella, I didn't think for a second that the *enshitification* of it would hit as fast as it did. Every single day, it becomes more unstable, and unusable.

![ghstatus](/media/2026/ghstatus.png)

A grand total of 32 incidents during the month of March. GitHub is almost cooked as far as I am concerned, and I say that as someone who absolutely loves the platform.

Signed up on `2009-02-23T12:49:46Z` and been a paying user since `2010` or thereabouts. Too bad!

## Tribal Trouble

I found out about [Tribal Trouble][tribaltrouble], way back in 2004 after I stumbled upon a paper that is titled "[Realtime Procedural Terrain Generation][proctergen]", which just so it happened to be authored by one if its creators.

Why am I talking about it now? Well, it occurred to me that its [source code][ttsrc] was open sourced at some point, but I couldn't really remember when exactly. When I went to check it out, I found out that the year was `2014`, which made me feel old yet again.

The curiosity got better of me, and decided to try to compile it. How hard that can be? This is Java, which you write once and run everywhere, or so I've been told when I was young lad.

So, does it still build and run or what? It does, after a couple minor adjustments.

```diff
-<property name="jre" value="jre1.5.0_04"/>
+<property name="jre" value="jre8"/>
```

Is `jre 1.5` in the room with us now? I hope not.

And then in `common/classes/com/oddlabs/regclient/RegistrationClient.java`:

```diff
public boolean isRegistered() {
-	return registration_info != null || registered_offline;
+	return true;
}
```

Could have also used the provided *registration keyfile* and avoid touching the source code at all, but then again where's the fun in that? That's not how we roll around here.

![tt1](/media/2026/tt1.png)

Voilà! It builds and runs as good as ever! The power of a nutritious cup of *covfefe*, right?

Now, it's worth calling out that this is all good old-fashioned fixed-function pipeline, namely OpenGL 1.x with the multi-texturing extension, and at least two available texture units.

![tt2](/media/2026/tt2.png)

The terrain is also as lovely as I remember it. Using `666` as the map seed, produces this super tiny island, which can be fun for 2 players or total mayhem for more. Pick your poison!

## mIRC + Winamp

Continuing with last months' trip down the *"what did I find in my archives"* lane, I wanted to mention yet another silly little thing that I built way back in late `2006`; which lay dormant in my archives waiting for me to stumble upon it once more in the year `2026`.

![hering2](/media/2026/hering2.png)

Do you remember [IRC][irc] and [mIRC][mirc]? They are still around and haven't completed faded into obscurity, but one rarely hears anything at all about either of these anymore.

Way back in `2006` things looked very different, and [IRC][irc] was still somewhat relevant despite the fact that the various *messengers* have severely eaten into its market-share, to say the least.

![mirc](/media/2026/mirc.png)

So what is this all about? It's about a small DLL that can be used to control [Winamp][winamp] from [mIRC][mirc].

How did it work? The *helper* *mIRC script* looked a little something like this:

```ini
; ...

menu channel,query,nicklist,menubar {
  -
  ircMP3 Status: winamp_status
  ircMP3 Play: winamp_play
  ; ...
  -
}

; ...

alias winamp_play {
  if ($dll("ircmp3.dll", winamp_status, NOT_USED) != 0) {
    $dll("ircmp3.dll", winamp_play, NOT_USED)
  }
  winamp_status
}

; ...
```

![mircmp3](/media/2026/mircmp3.png)

Then the DLL exported a bunch of functions like this:

```c
// defined in `wa_ipc.h`
#define WINAMP_BUTTON2 40045

__declspec(dllexport) int __stdcall winamp_play(
    HWND mWnd,
    HWND aWnd,
    TCHAR *data,
    TCHAR *parms,
    BOOL show,
    BOOL nopause
)
{
	HWND hwnd = FindWindowA("Winamp v1.x", NULL);
  	if(hwnd != NULL)
    {
    	SendMessage(hwnd, WM_COMMAND, WINAMP_BUTTON2, 0);
    }
  	return 1;
}
```

For some reason or another, I didn't end up using the [LoadDll][loadll] mechanism, which would have allowed me to avoid having to load the DLL every single time the *mIRC script* called `$dll`.

Oh, well. This was `20` whole years ago, and it's all ancient history now.

> **Warning:** do not use DLLs from sources you do not trust. See the [Accepting Files](https://www.mirc.com/help/html/accepting_files.html) section for information on the dangers of accepting and using files from the internet.

This gave me a little chuckle when I found out that this was still out there in the [mIRC][mirc] documentation.

## Ahoy: AUG

{% include youtube.html id="db-JxEwK5Ng" %}

## Paged Out: Issue #8

![pagedout8](/media/2026/pagedout8.png)

The [new issue][pagedout8] came out on the 26th of last month, but I managed to miss it somehow. Not subscribing to their RSS feed might or might not have had something to do with it.

## Monthly "*Layoffs Report*"

![yogibear](/media/2026/yogibear.png)

I do realize that the numbers shown on [Layoffs.fyi][layoffsfyi] are nowhere near accurate, but `71_447` at the end of March is a pretty high number nonetheless.

These massive layoffs fuel the fires of *socialist brainrot*, and of course those whos' minds have been completely taken over by it are more than happy to bring more people into the fold.

You can see this spreading all over the information super-highway like wildfire. Remember, like I said before, these recent waves have absolutely nothing to do with AI. Don't let yourself be fooled.

## Monthly "*Amazon Book Review*"

I happen to be part of the tiny club of *apostates*, who haven't read or owned what is now considered to be the quintessential, and must have [C Progamming Language][cpl] book written by the dynamic duo composed of the [Bell Labs][belllabs] *extraordinaires* [Brian Kernighan][bkernighan] and [Dennis Ritchie][dritchie].

![ccpp](/media/2026/cc.png)

I got the [C: The Complete Reference][cref] and [C++: The Complete Reference][cppref] by [Herbert Schildt][hschildt] instead.

If you thought that's very weird or cringe, or something along the those lines, then wait until you hear that I've gotten the *translated versions*, since it was near impossible to get the *originals* in *English* at the time in this part of the world at least.

Plus, given the fact that even the *translated editions* were quite expensive at the time, I think that it's rather fair to state the fact that I could have never afforded to import the *originals* from across the great pond anyway.

I was just a poor teenager from the former *Eastern Bloc*, ya' know? The ugly specter of the regime change was still fresh in the air, despite the *new millennium* approaching at an ever so accelerated pace.

### C: The Complete Reference Review

![crev](/media/2026/crev.png)

### C++: The Complete Reference Review

![cpprev](/media/2026/cpprev.png)

Sadly, I couldn't find any reviews from the 90s like last time, so these will have to do. They also aren't exactly singing praises either for what it's worth.

## Monthly *"Coup de cœur"*

Coming at you this month with yet another banger called [954][954] by [Apocalypse Inc][apocalypseinc] from the very same and mighty [Mekka & Symposium 2000][mekka2000] once more.

{% include youtube.html id="lVyCqel-LcU" %}

Please enjoy the show, and don't forget to try the fish!

[mekka2000]: https://www.pouet.net/party.php?which=26&amp;when=2000
[layoffsfyi]: https://layoffs.fyi/
[yogibear]: https://en.wikipedia.org/wiki/Yogi_Bear
[954]: https://www.pouet.net/prod.php?which=346
[apocalypseinc]: https://www.pouet.net/groups.php?which=180
[bkernighan]: https://en.wikipedia.org/wiki/Brian_Kernighan
[dritchie]: https://en.wikipedia.org/wiki/Dennis_Ritchie
[cref]: https://www.amazon.com/C-Complete-Reference-4th-Ed/dp/0072121246/
[cppref]: https://www.amazon.com/C-Complete-Reference-Herbert-Schildt/dp/0072226803/
[hschildt]: https://en.wikipedia.org/wiki/Herbert_Schildt
[cpl]: https://www.amazon.com/Programming-Language-Brian-W-Kernighan/dp/0876925220
[pagedout8]: https://pagedout.institute/?page=issues.php
[belllabs]: https://en.wikipedia.org/wiki/Bell_Labs
[dlss]: https://en.wikipedia.org/wiki/Deep_Learning_Super_Sampling
[dlss5]: https://en.wikipedia.org/wiki/Deep_Learning_Super_Sampling#DLSS_5
[pbr]: https://en.wikipedia.org/wiki/Physically_based_rendering
[chopshop]: https://store.steampowered.com/app/2698900/Chop_Shop/
[edmundmcmillen]: https://en.wikipedia.org/wiki/Edmund_McMillen
[mewgenics]: https://en.wikipedia.org/wiki/Mewgenics
[slaythespire2]: https://en.wikipedia.org/wiki/Slay_the_Spire_II
[cakez77]: https://www.twitch.tv/cakez77
[tangytd]: https://store.steampowered.com/app/2245620/Tangy_TD/
[slug]: https://sluglibrary.com/
[ericlengyel]: https://en.wikipedia.org/wiki/Eric_Lengyel
[slugpatent]: https://terathon.com/blog/decade-slug.html
[slugshaders]: https://github.com/EricLengyel/Slug
[fwidth]: https://developer.download.nvidia.com/cg/fwidth.html
[proctergen]: https://web.mit.edu/cesium/Public/terrain.pdf
[tribaltrouble]: https://en.wikipedia.org/wiki/Tribal_Trouble
[ttsrc]: https://github.com/sunenielsen/tribaltrouble
[loadll]: https://www.mirc.com/help/html/index.html?dll.html
[irc]: https://en.wikipedia.org/wiki/IRC
[mirc]: https://en.wikipedia.org/wiki/MIRC
[winamp]: https://en.wikipedia.org/wiki/Winamp
