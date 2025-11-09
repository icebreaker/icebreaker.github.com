---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2024
title: 2024 September Retrospective
propaganda: frostpunk2
tags: retrospective
---

# 2024 September Retrospective

September was a truly *indie game release month* in my book. Isn't every month of the year like that? Probably, but these days I am only interested in a relatively tiny selection of games, and most of them do fall into the *indie game* bucket; which is not too shocking or surprising, I guess.

## Frostpunk 2

Let's start with the behemoth in the room, which I am sure you guessed by now that it's none other than the latest installment of the [Frostpunk][frostpunk] franchise, **drum-rolls, please**, [Frostpunk 2][frostpunk2].

{% include youtube.html id="BuvJAcptUd0" %}

While the city-building-survival-game genre isn't exactly my cup of tea, I've been following the game pretty closely due to the simple fact that the first installment, can be pretty much considered nothing short of a bona fide cult classic.

It shouldn't be shocking that it had a very successful launch and sold over 350k units during the *opening weekend* alone. I am always thankful when studios release any sort of numbers ***post-launch***, because it allows me to double check the estimates provided by tools like [Gamalytic][gamalytic].

![frostpunk2com](/media/2024/frostpunk2com.png)

When I looked at [frostpunk2.com][frostpunk2com], I immediately noticed the [video][frostpunk2bgvideo] being used as a background, and thought that it would make a great wallpaper, then proceed straight to using the following series of  incantations in order to extract and resize a suitable frame:

```bash
$ ffmpeg -i Frostpunk_2_Hammer_Trailer_Endslate_LOOP.mp4 \
	-ss 00:00:04 \
	-frames:v 1 \
	wallpaper_4k.png
$ convert wallpaper_4k.png -resize 1024 wallpaper_1080p.png
```

You can graciously witness the results of my great labor below.

[![frostpunk2_wallpaper](/media/2024/frostpunk2_wallpaper.png)](/media/2024/frostpunk2_4k_wallpaper.png)

It's quite surreal seeing a *4K video* being used as a mere background. If you'd tell me in the 90s that this was going to be the case, I would have laughed you out of the room, and asked you to kindly remind me when was the last time you awed a gander at `D:\funstuff\videos\goodtime.avi`.

{% include youtube.html id="okt9GcWiWmE" %}

## Tiny Glade

Yet another banger this month was the quite *whimsically chill diorama builder*, called [Tiny Glade][tinyglade].

![tinyglade](/media/2024/tinyglade.png)

One of the reasons why I thought of mentioning is because it's being powered by some rather *unorthodox and deliriously hipster* tech stack under the hood.

{% include youtube.html id="CdWpq2efN8Y" %}

A healthy mix of [Rust][rustlang], and [Bevy][bevyengine], infused with copious amounts of procedural generation, go figure!  Please tell me that it's not the most surprising and amazing thing you've read or heard all week.

Come on now, tell the truth and shame the devil!

## UFO 50

[UFO 50][ufo50] has been baking in the oven for an awfully long time, and it's the brain-child of none other than [Derek Yu][derekyu] of [Spelunky][spelunky] fame.

![ufo50](/media/2024/ufo50.png)

People have been complaining about the fact that the included games are too hard and so forth, which is understandable; that was the whole point in fact, but perhaps it might have not come across clearly enough.

{% include youtube.html id="tfW0K4rRLnw" %}

Teleport yourself into a bygone age filled with nostalgia and old-school tunes. It's also worth pointing out the perhaps much lesser known fact that it's a [GameMaker][gamemaker] game. That was quite a mouthful, wasn't it?

But, then again, what else do you expect from a true to the heart [Mossmouth][mossmouth] production? Right on the money!

## Kingdom Rush Vengeance: Pirate Kings Campaign DLC

I am not even going to bother saying anything about this one. One can never have enough of good old fashioned tower defense in their lives.

{% include youtube.html id="1WFs_6Xh_hg" %}

I must confess that I haven't gotten the chance to play trough the entire campaign just yet.

By the way, another DLC should be dropping sometime in October, but for latest installment of the series released just a few months ago, called [Kingdom Rush 5: Alliance][kr5]. Just in time for the incoming onset of ***spooky season***.

## The Legend of Zelda: Echoes of Wisdom

Last, but not least, Nintendo dropped the latest entry in the legend of Zelda franchise, which seems to be using the same engine as [The Legend of Zelda: Link's Awakening][tlozla] that came out a few years back.

{% include youtube.html id="fb4__RzOVNs" %}

## Marmota

In other *non-indie-game-related news*, the curiosity got the better of me and wanted to see how [Marmota][marmota] fairs on [Ubuntu][ubuntu]. Now, I knew that it would compile and run because the only real dependencies it has are gtk and libvte, but I was still reasonably curious and intrigued.

![marmota](/media/2024/marmota.png)

Well, it works just fine and plays relatively nicely with [Gnome 3][gnome3], even in border-less full-screen mode, which is precisely what I was primarily interested in finding out more about.

![ubuntu_marmota](/media/2024/ubuntu_marmota.png)

However, in good old *year of the Linux desktop fashion*, there's always a ***BIG BUT*** in the house. In order for the window's *icon* to show up in the sidebar (*launcher*), it's not enough to just specify the name of said icon via `gtk_window_set_icon_name`; in fact this pretty much is ignored and results in an unsurprising no-op.

```c
gtk_window_set_icon_name(GTK_WINDOW(ctx->win), ctx->icon_name);
```

That would have been way too easy, right? One needs to create an actual `.desktop` entry file, which is just as convoluted to put together as it always was *20+ years ago*.

```ini
[Desktop Entry]
Name=Marmota
Exec=marmota
Icon=terminal
Terminal=false
Type=Application
Categories=Utility;Application;
```

Eh, a small price to pay, right? Not really, but here we are!

![ubuntu_launcher](/media/2024/ubuntu_launcher.png)

Yet another reason why (*just in case, there weren't enough already*), I do not use or fancy any of the so called well established, and traditional desktop environments.

As if that wasn't bad enough, it looks like Ubuntu is no longer offering any official *boot-table mini-netinstall* type ISO images; which in turn makes it a pain in the butt to install, because one has to unnecessarily download an already largely out of date totally unnecessary pile of digital bits.

In 2024, having a *net installer* should be mandatory, and most definitely not some optional nice to have kind of a thing; well hidden away, just in case people find out and complain, and boy oh boy, complain they did.

[frostpunk2]: https://en.wikipedia.org/wiki/Frostpunk_2
[frostpunk2bgvideo]: https://frostpunk2.com/wp-content/uploads/2023/09/Frostpunk_2_Hammer_Trailer_Endslate_LOOP.mp4
[frostpunk2com]: https://frostpunk2.com/
[frostpunk]: https://en.wikipedia.org/wiki/Frostpunk
[gamalytic]: https://gamalytic.com/game/1601580
[tinyglade]: https://pouncelight.games/tiny-glade/
[derekyu]: https://en.wikipedia.org/wiki/Derek_Yu
[spelunky]: https://en.wikipedia.org/wiki/Spelunky_2
[rustlang]: https://www.rust-lang.org/
[bevyengine]: https://bevyengine.org/
[ufo50]: https://en.wikipedia.org/wiki/UFO_50
[tlozla]: https://en.wikipedia.org/wiki/The_Legend_of_Zelda:_Link%27s_Awakening
[gnome3]: https://en.wikipedia.org/wiki/GNOME_3
[marmota]: https://github.com/icebreaker/marmota
[ubuntu]: https://ubuntu.com/
[mossmouth]: https://www.mossmouth.com/
[gamemaker]: https://gamemaker.io/en
[kr5]: https://www.ironhidegames.com/Games/kingdom-rush-alliance
