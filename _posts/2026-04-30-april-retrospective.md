---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2026
title: 2026 April Retrospective
propaganda: further
music: _BmTVEsaxHY
tags: retrospective
---

2026 April Retrospective
=========================

This month we got to hear the *first gong* that signals the beginning of the end of what I like to call the *infinitely subsidized token era*. Uh-oh! Rooh-rah!

What does this really mean in the long term? Well, it remains to be seen, but in my opinion there's a pretty high chance that only a handful of the so called *frontier-labs* will survive in the end.

Which ones? You might be tempted to ask. Well, two of them are *ad-businesses*, that subsidize their entire product lines already, so in theory they should be able to continue doing the same with tokens as well, pretty much indefinitely if necessary.

I am referring to none other than mighty Google, and Facebook of course!

## Micro Cornucopia

Look at this absolutely splendid [issue][microcornucopia41] (*No. 41*) of *Micro Cornucopia* all the way back from `May 1988`.

![mcc](/media/2026/mcc.png)

> Neural Networks: Modeling human reasoning is the first step in creating a useful robot.

The more things change, the more they same. At any rate, we are not on *LinkedIn* over here, so that was more than enough yapping about AI for the time being.

## Insidious: Out of the Further

![insidious_further-fs8](/media/2026/insidious_further.png)

I really thought that we might not get another entry in the [Insidious][insidious] franchise, and boy I am glad that I was dead wrong when it comes to this one.

{% include youtube.html id="jxU8FU3o75A" %}

This is going to be an absolute banger, I can feel it in my old wretched bones already.

## GitHub Enshitification (Part Deux)

I was moaning about the *enshitification* of GitHub last month, and boy things have gotten a whole lot worse since then. I mean, we are now approaching some sort of a tipping point, where utter incompetence, and *corporate brain-rot* happen to be working in tandem.

![badgh](/media/2026/badgh.png)

The latest incident revealed a tiny little technical detail that made a lot of the previous ridiculousness make total and perfect sense. How so? Well, it was revealed that [Elasticsearch][elasticsearch] is being leveraged behind the scenes, and that data was being re-indexed into it, which of course usually will take a while.

When I read all that, I was like: *"Oh, so that's why you can only look at the first 2000 issues!"*, then I almost immediately followed up with: *"Oh, that's why you see the total count of issues or pull requests update, but the actual list takes a while before it's updated!"*.

[Elasticsearch][elasticsearch] has been designed, well for search. Shocking, I know. Would could have guessed, right? And, it's whole-fully unsuited for workloads where one needs to paginate a lot or needs the data to be fresh in close to real-time fashion.

In the end, there's something good or fun to be had in everything, I guess.

## Stronghold Crusader: Definitive Edition

![scdlc26spring](/media/2026/scdlc26spring.png)

The aforementioned [spring DLC][springdlc] is upon us. It landed way sooner than I expected to be perfectly honest.

{% include youtube.html id="8LH3uISgv0Q" %}

May your granaries never run out of food.

## Vampire Crawlers: The Turbo Wildcard from Vampire Survivors

![vc](/media/2026/vc.png)

That is quite a mouthful, isn't it? I mean it's very typical [Poncle][poncle] in every sense of the word.

{% include youtube.html id="2uBGewEqOVg" %}

I feel like, many were wondering about whether [Poncle][poncle] will also turn out to be some sort of like a *one-game-pony* studio or not. This is a fairly common phenomenon among the *indie-crowd,* so the doubt was all justified as far as I am concerned.

However, I am happy to report that the game is super fun, and I am saying that as someone who doesn't like turn-based and card-based anything at all. But, this *bad-boi* manages to trick my primitive monkey-brain somehow, and for that I must tip my hat.

What about the numbers? Over `800_000` units sold according to [Gamalytic][vcgamalytic]. Take that naysayers!

## Game Pricing

The question of *game pricing* has become like some sort of a seasonal flu it appears to me; and seems to resurface with a fairly regular cadence in all circles, be it indie, AA or AAA.

In more recent times the number `14,99` has been elected as some sort of an upper limit for the *celebrity-indie crowd*, and as the entry-level lower limit for the *AA club*.

Now take a look at this beautifully preserved rendition of [Cyparade][cyparade], the creators of one of my all time favorite games from the early 2000s, called [Ballance][ballence].

![balance](/media/2026/balance.png)

What do you notice? Our favorite number `14,99` *(euro)*, in the great year of 2004 no less; which when adjusted for inflation, would turn out to be something in the range of `23,77` *(euro)* or thereabouts.

{% include youtube.html id="WCOKSsygnxM" %}

I hate being overly repetitious, but once again, I have to call out the fact that the more things change, the more they stay the same. Enough said!

## s&box

![sbox](/media/2026/sbox.png)

[S&box][sbox] has finally made it out the door this month.

{% include youtube.html id="CrkSYwxpSDo" %}

Last time, I was talking about [S&box][sbox] though, I did mention how based on one of the updates it did seem like [Erin Catto][erincatto] was cooking up a 3D physics engine in the spirit of [Box2D][box2d].

This has been [officially confirmed][box3d] now by none other than the good man himself.

![box3d](/media/2026/box3d.png)

Music to my ears all the way through.

## SameGame

I decided to dust off and show off yet another little *thingamajig* from my ancient forgotten archives. Keep finding these as I sift through them, and will likely share more as the memories of the olden days kick in more than usual these days.

![samegame](/media/2026/samegame.png)

This is not as bad as I remember it being, but it's nothing to write home about either.

```bash
$ winedump samegame.exe | grep TimeDateStamp
  TimeDateStamp:                44F15220 (Sun Aug 27 11:04:48 2006)
```

Twenty years gone in an instant, huh? Now, it's worth calling out that I have *borrowed* (ahem!) the sprites from the [SameGame][samegame] clone that used to ship with [GNOME 2][gnome2].

![herring3](/media/2026/fishart/herring3.png)

Look at this unedited mess. What would anyone do without a highly meretricious soup of globals mixed with a healthy dose of [Hungarian notation][hungariannotation].

```c
void Render( HWND hWnd )
{
	RECT rc;

	HDC  hDC = GetDC( hWnd );
	GetClientRect( hWnd, &rc );

	//FillRect(g_hDCMem,&rc,(HBRUSH) GetStockObject( BLACK_BRUSH ) );

	tileboard_Render(g_hDCMem);

	BufferSwap( hDC, rc );

	ReleaseDC( hWnd, hDC );
}
```

But hey, I can always throw in the excuse that goes something like: *"I was young!"*. Right? Besides, I don't even remember, why on earth did I build this.

Plus, by the looks of it I was using [LCC][lcc] and not [MinGW][mingw] as a compiler. No idea why!

```make
# Project: Makefile Template for the LCC compiler
# Makefile Created by The Icebreaker

LCC      = d:/DevTools/lcc/bin/lcc.exe
LCCLNK   = d:/DevTools/lcc/bin/lcclnk.exe
LCCRC    = d:/DevTools/lcc/bin/lrc.exe
RES      = samegame.res
OBJ      = samegame.obj $(RES)
BIN      = samegame.exe
LNKFLAGS = -subsystem Windows  
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before samegame.exe all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(LCCLNK) $(LNKFLAGS) $(OBJ)

samegame.obj: samegame.c samegame.h
	$(LCC) samegame.c 

samegame.res: samegame.rc 
	$(LCCRC) samegame.rc
```

## The "Sackhoff" Show

![starbuck](/media/2026/starbuck.png)

{% include youtube.html id="cnHk4uCL9fQ" %}

{% include youtube.html id="b47d_hJcEv8" %}

{% include youtube.html id="zzQeUvObs-k" %}

{% include youtube.html id="FNC87cmWJrE" %}

At roughly four episodes a month, this is going to take a while.

## Monthly "*Layoffs Report*"

![yogibear](/media/drafts/2026/yogibear.png)

The layoffs continue in full force, and at the time of me writing this the glorious number of `92_272` can be seen on [Layoffs.fyi][layoffsfyi]. That's an increase of roughly `20_825` compared to last month's report.

There goes the entire population of a small town. Poof gone, like Houdini.

## Monthly "*Amazon Book Review*"

This is yet another book from my personal collection and by a fellow Romanian author, Vasile Lungu. I have a physical copy of the first edition (*the one on the left in dark blue*).

I never realized that this got an updated second edition, and that it was subsequently translated into English in `2005` or so; and even less so that it was available on [Amazon][limbasm] for a while.

![limbasm](/media/2026/limbasm.png)

It's out of stock now, which of course shouldn't really surprise anybody.

![limbasmarev](/media/2026/limbasmarev.png)

Why did I buy this? Well, I used to lurk in the bookstores in the so called "*IT&C*" section, whenever I got a chance really. The selection of books was always lackluster, and there weren't a great many copies available either, considering that this was and still is a relatively small town.

So, I liked to be early and enjoy the spoils. But on a more serious note, I saw that it had a fairly complete interrupt reference, plus a chapter or so about MMX, and those two were enough to make me buy it at the time.

Both of those subjects were totally obsolete by `2003`, since people have moved on from `DOS` and `MMX` was overshadowed by `SSE` already  by that time, but hey beggars can't be choosers.

## Monthly *"Coup de cœur"*

Are you ready for another *brutal awesome-sauce-fest* from the [Mekka & Symposium 2000][mekka2000]?

If the answer to that question is a resounding *"fuck yes!"*, then please awe a gander at this absolute unit of a demo called [Nature Suxx][naturesuxx] by none other than [Federation Against Nature][fan].

{% include youtube.html id="CFRZfCgIs2E" %}

Please enjoy the show, and don't forget to try the fish!

[mekka2000]: https://www.pouet.net/party.php?which=26&amp;when=2000
[layoffsfyi]: https://layoffs.fyi/
[yogibear]: https://en.wikipedia.org/wiki/Yogi_Bear
[954]: https://www.pouet.net/prod.php?which=346
[apocalypseinc]: https://www.pouet.net/groups.php?which=180
[springdlc]: https://store.steampowered.com/app/4483540/Stronghold_Crusader_Definitive_Edition__Baldwin__Bullseye/
[naturesuxx]: https://www.pouet.net/prod.php?which=467
[fan]: https://www.pouet.net/groups.php?which=216
[insidious]: https://en.wikipedia.org/wiki/Insidious_(film_series)
[elasticsearch]: https://en.wikipedia.org/wiki/Elasticsearch
[poncle]: https://vampire.survivors.wiki/w/Poncle
[vcgamalytic]: https://gamalytic.com/game/3265700
[cyparade]: https://web.archive.org/web/20050206210822/http://www.cyparade.com/
[ballence]: https://en.wikipedia.org/wiki/Ballance_(video_game)
[sbox]: https://en.wikipedia.org/wiki/S%26box
[erincatto]: https://box2d.org/about/
[box2d]: https://en.wikipedia.org/wiki/Box2D
[box3d]: https://x.com/erin_catto/status/2039863191698821142
[microcornucopia41]: https://mirrors.meulie.net/bitsavers.org/magazines/Micro_Cornucopia/Micro_Cornucopia_41_May88.pdf
[samegame]: https://en.wikipedia.org/wiki/SameGame
[gnome2]: https://en.wikipedia.org/wiki/GNOME_2
[hungariannotation]: https://en.wikipedia.org/wiki/Hungarian_notation
[lcc]: https://en.wikipedia.org/wiki/LCC_(compiler)
[mingw]: https://en.wikipedia.org/wiki/MinGW
[limbasm]: https://www.amazon.com/Assembly-Language-Programming-Processors-Family/dp/1594960364
