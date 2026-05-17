---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2026/
title: 2026 February Retrospective
propaganda: starbuck
music: 1FXn-EPB3sg
tags: retrospective morcheeba c digital-archeology
---

2026 February Retrospective
=========================

Let me start this off by saying yet again: we should really offset each day of the year by a tiny amount in order to have a **February** with *proper 30 days*. This nonsense has to stop somewhere. Imagine us as a multi-planetary species, doing shit like this across multiple planets; it's gonna be a nightmare to deal with this crap. And, while we are at it, let's just all use **UTC** only for crying out loud.

Februaries are always weird anyway, because they are the month when I grow older with one cycle, and because of this, I have decided to write a special  [Birthday Retrospective][birthday-retro] each year going forward.

Also, this month's retrospective is packed with a metric ton of video content, due to the fact that there have been quite a few banger drops to the likes of which I wanted to draw special attention to.

## The "Sackhoff" Show

When [Katee "Starbuck" Sackhoff][starbuck] made a rather impromptu appearance on [Joe Rogan][joerogan] at the tail of last year, it all really caught me totally by surprise, and I said as much at the time.

This time she's back with a brand new series that it's going to be an absolute banger.

{% include youtube.html id="HK4wgx8TbrU" %}

{% include youtube.html id="IZK1E28QT9Q" %}

{% include youtube.html id="nMzFxJLKBJk" %}

{% include youtube.html id="uJ4vN4tniw0" %}

You better get used to me posting about this until the very end. So say we all.

## Escape the Chaos

[Morcheeba's][morcheeba] latest album [Escape the Chaos][escapethecaos] is totally as fresh as it can be, while still retaining that quintessential Morcheeba texture and feel that we all have grown accustomed to love and respect.

But as per usual, you don't have to take my word for it. Have a listen and decide for yourself.

{% include bandcamp.html album="4105944988" href="https://morcheeba.bandcamp.com/album/escape-the-chao" title="Escape The Chaos by Morcheeba" %}

## Hocus Focus: Demo

![hf](/media/2026/hf.png)

[Hocus Focus][hocusfocus] got a nice and shiny demo this month. Go and give it a try if you fancy these types of cozy games. I also feel like we are starting to reach the point where the term *cozy game* is starting to be *overloaded*, and people will soon start having arguments about the nuances of it all.

Alas, the SEO still hasn't really picked up on the game yet, and we are roughly two months after the initial announcement. The ways of the great information super-highway are mysterious indeed.

## Chop Shop: Demo

![chopshop](/media/2026/chopshop.png)

[Chop Shop][chopshop] is yet another indie game from another *ex-colleague* and friend of mine, and it got a demo this month. Since I know full well that people hate even the idea of the so called *indie-solo-dev*, you'll be happy to know that it's the product of a great dynamic duo.

## Stronghold Crusader: Definitive Edition

If you thought that news about definitive edition of Stronghold Crusader will come to a complete and total halt in the new year. Well, I have some news for you. You were wrong!

The [winter DLC][scdewinterdlc] has arrived, which is supposed to be the last DLC according to the official roadmap.

{% include youtube.html id="_8jOx1c2f2A" %}

It remains to be seen whether this turns out to be the case or not, considering the game's popularity and the complete revitalization of the community at large as well.

## El desorden que dejas

While finding myself having to do a fresh install on my new box, I have realized that `three` of my long time utilities are *pretty much out of comission*, if not all out dead. Look, I am really not the one to shy away from compiling from source or pulling in something from the [AUR][aur], if and when the situation actually warrants it.

However, it's becoming more and more clear that *GTK delenda est*, and all software that relies on it is bound to encounter a slow but rather painful death.

The utilities that I'm talking about here are as follows: [volumeicon][volumeicon], [viewnior][viewnior], and last but not least [nitrogen][nitrogen]. Obviously, there are far more than these that will be affected in the not so remote future, but these are already difficult to build on modern systems due to their reliance on `GTK`.

If you take a look at their respective project pages or repositories, it's obvious that even porting to `GTK3` was simply far too much pain and effort, let alone anything newer than that.

While, I could most definitely fork them and try to migrate them all to something like `GTK4`, the amount of manual labor and effort that would take is simply too great, or far greater than rebuilding them from scratch with only the features that I rely on or care about.

I managed to hold off from moving away from `libvte` for my terminal emulator at the moment, but I just have to bite the bullet, and replace these with my own *muy pronto*, because I really have no patience anymore to constantly deal with this crap.

What the people building  `GTK` don't seem to quite understand is the fact that without the existence of an official [libgtk2-compat][libgtk2-compat], that happens to maintain full backwards compatibility while using `GTK3` or `GKT4` under the hood; the severe code rot and the extreme difficulty in terms of porting will lead to the deaths of countless projects similar to ones I listed above.

I know full well that I keep beating an already dead horse here, and largely preaching to the choir, but it's extremely frustrating to having to constantly deal with this absolute hot mess, largely left behind by people who just don't seem to understand the importance of backwards compatibility. It is *sooooo* very much frustrating, *arrggh*!

### Exhibit A

Fortunately, there are some projects out there like [SDL][sdl], built and maintained by people who understand backwards compatibility very well; so well in fact, that they basically release a companion *compat* library after each major release that contains breaking changes.

Awe a gander at [sdl12-compat][sdl12-compat] and [sdl2-compat][sdl2-compat] and bask in the glory of software well done.

```c
/*
	SDL_SetRefreshRate was never in an real SDL-1.2 release,
	but apparently StepMania was maintaining a fork with this
	API for literally years.
*/
DECLSPEC12 void SDLCALL SDL_SetRefreshRate(int rate)
{
    /* takes effect on next SDL_SetVideoMode call. */
    DesiredRefreshRate = (rate >= 0) ? rate : 0;
}
```

This is exactly what one would expect from the likes of `GTK`. Oh well!

## Stardew Valley 10-year Anniversary Video

While I am not a fan of this particular genre, which shouldn't come as a surprise really, I still wanted to call this one out. Simply because, [Eric Barone][concernedape] should be heralded as an example in my honest opinion, when it comes to how one should keep a game that is not primarily a *live-service game*, continue to feel alive and remain quite fresh for a decade at this point.

{% include youtube.html id="geiTg6Z7w3A" %}

Seeing how the game evolved over the years in the video above, should be more than enough to convince anybody of all the hard work and sweat that went into it. Eric, really poured his soul into it all, for which he deserves firm handshakes all the way to the *ti-pity-top* of *Mount Success*.

## Rant Radio

I have randomly stumbled upon an ancient episode of [NewsReal][rantradio] by [Sean Kennedy][seankennedy] within my archives; as I couldn't really find it anywhere anymore online, I have decided to [make it available][newsrealarchive] for your very own personal enjoyment of course.

{% include audio.html src="https://archive.org/download/news-real-64-270-040306/NewsReal_64_270_040306.mp3" %}

Based on the [ID3v1][id3v1] metadata within the **MP3**, it seems to be episode **270** from **03/04/2006**.

What makes this even more interesting or weird is that I had picked [The Future][thefuture] by [Leonard Cohen][leonardcohen] as the theme song of my 2025 final end of year post. What an unexpected coincidence, right?

Anyway, this little serendipitous find reminded me of the fact that I have built a super tiny *"Web Radio Player"* way back in late `2006`, for one my *cyber-friends* at the time, which so it happened to have included *RantRadio.com* as one of the default radio *stations*.

Managed to track it down, it was tucked away reasonably well within the depths of my archives; it's just a plain old [Win32][win32] application written in C, using [FMOD][fmod] for the audio streaming bits; which means that it still works just fine today as you can see for yourself in the screenshot below.

![hak5](/media/2026/hak5.png)

Now, why on earth did I make it all [Hak5][hak5] themed or branded? Do you even remember [Hak5][hak5], like at all?

I honestly have zero ideas about what must have been going through my mind at that particular time. Also, the `fmod.dll` that I have used, it seems to be from way back in `2003`, which is absolutely bananas and not to mention super funny. No support for *HTTPS* of course! It goes to show that we didn't really care too much about that until well into the early `2010s`.

What about the rather mysterious and sus' looking *"Change Yahoo Messenger Status"* checkbox? I knew right away that many of you cool *nerds* and *nerdettes* would be dying to know more about that. Therefore, I have decided to demystify it all, and take you behind the great magic curtain.

```c
#define YAHOO_MESSENGER_UPDATE_STATUS 0x188

//
// Get HKEY_CURRENT_USER\Software\Yahoo\Pager\Yahoo! User ID
// Set HKEY_CURRENT_USER\Software\Yahoo\Pager\profiles\%s\Custom Msgs\5
//

// Find the Yahoo Messenger window by its class name
HWND hwnd = FindWindowA("YahooBuddyMain", NULL);

// Send the YAHOO_MESSENGER_UPDATE_STATUS command to said window
SendMessage(hwnd, WM_COMMAND, YAHOO_MESSENGER_UPDATE_STATUS, 0);
```

What is the *magic number* `0x188` for the `SendMessage`, and how did I figure that one out? The truth is that I didn't, but I do remember finding it on some ancient long defunct forum.

The cherry on the cake however is that *Eye of Sauron* system tray icon. Why? Why? Why? At any rate, it's quite interesting isn't it, how all of this is pretty much obsolete arcane knowledge today.

## Making Catacomb 3-D

[John Romero][johnromero] should need no introductions, I hope. There will be people out there no doubt who will say that isn't he tired of *milking* the good old days already?

They would be well within their rights to say that of course, however he happens to be one of the few people out there from that particular era, who have every right to continue to do so for years to come!

{% include youtube.html id="ZcUqwMf01pI" %}

Besides, it's not like there's a plethora of exhaustive material on titles like [Catacomb 3-D][catacomb3d] out there.

{% include youtube.html id="1SzNvJNRHyI" %}

## Bounce Tracking Mitigation

Oh, the Americans and their eternal fascination with acronyms, eh? BTM is a truly terrible thing, and it seems to have sprung forth form the same spring of madness that have blessed the world with Pulse Audio, Systemd and Wayland.

I could understand Google pushing this for their own services. You want to log me out of Google Account every now and then for no good reason? Fine, it's annoying, but you log back in once and you get access to all the services. However, flushing cookies and local storage for all recently visited websites is just plain rude. What is the point of persistent sessions then, if I have to randomly login back into 10+ places with all the 2FA included?

You know what is even worse? There's no way to turn it the *frak off.* But as always, it's not all lost as the good folks at Brave have been hard at [cooking up some fixes][bravebtm] in order to try and address this absolute travesty of a situation. How on earth can you release something as disruptive as this to hundreds of millions of users, without giving them the ability to turn it off for good?

![herring](/media/2026/fishart/herring.png)

I fully realize that I might have yapped about this before, but *"the situation is mighty queer, my dear"* as my *great-grandmother* would have put it. I also have a feeling that one of my good old friends, would have had a sudden urge to throw a dinner party had this happened to him one too many times.

## eXoWin9x

![exowin9x](/media/2026/exowin9x.png)

[eXoWin9x][exowin9x] is even bigger and better than [eXoDOS][exodos] in every sense of the word.

{% include youtube.html id="OJrC5YdB6hk" %}

You can check out the absolutely beautiful manual over [here][exowin9xmanual].

## Ahoy: When Video Games were Brown

Only the mighty Ahoy can manage to dispel the *"brown video game"* myth, once and for all in a single video on the subject. The production values are through the roof as per usual.

{% include youtube.html id="TTjGDkDI49I" %}

I just realized that if you took a shot every time I said banger in this post you'd be pretty tipsy by now.

## Monthly "*Layoffs Report*"

![yogibear](/media/2026/yogibear.png)

Two months in, and according to [Layoffs.fyi][layoffsfyi] about `34_650` tech folks have been laid off. Let that sink in for a moment. As these numbers will continue to grow to *new heights*, as per usual people will naturally try to pin all this this on some convenient *boogey-man* that actually has nothing to do with anything at all.

I don't like to make predictions, especially ones that are about the future, I am very much like [Yogi Bear][yogibear] in this regard, but considering that we had `124_201` people laid off in `2025`, I think it's fair to say that we'll have at least double that number by years end.

As depressing as it is to keep yapping about this extremity touchy subject matter for most, I do intend to include this *section* in every monthly retrospective that I write this year at least.

Before anybody says anything, the answer is a resounding and clear ***NO***. AI or LLMs have absolutely nothing to do with all this whatsoever. Just stop it, and go cry about something else in your safe corner.

## Monthly "*Amazon Book Review*"

![pcintern](/media/2026/pcintern.png)

It's pretty rare for me to stumble upon a review from *February 12, 1999* by accident. The book in question is the rather excellent [PC Intern][pcintern] by none other than authors *Michael Tischer* and *Bruno Jennrich*.

![pc_intern_amazon_review_feb_99](/media/2026/pc_intern_amazon_review_feb_99.png)

Tried to dig around in order to see what they might have been up to as of late, but couldn't really find anything tangible at all (hence why they aren't linked); which is unfortunate of course, but such is the life of those who dare to *dream in digital*.

Going to have to get a hard-copy of this one sooner than later. It's just one of those absolute must-haves.

## Monthly *"Coup de cœur"*

This month, I ended up picking a very impressive 64k intro instead of a demo, rather aptly called [Heaven Seven][heavenseven] by [Exceed][exceed], which happened to have won the first place at the great [Mekka & Symposium 2000][mekka2000].

{% include youtube.html id="rNqpD3Mg9hY" %}

Please enjoy the show, and don't forget to try the fish. Until next month, as server said: *"end of line"*!

[birthday-retro]: {% post_url 2026-02-11-2026-birthday-retrospective %}

[hocusfocus]: https://store.steampowered.com/app/4202710/Hocus_Focus/
[starbuck]: https://en.wikipedia.org/wiki/Kara_Thrace
[joerogan]: https://www.youtube.com/watch?v=TZu7jymfHrU
[escapethecaos]: https://morcheeba.bandcamp.com/album/escape-the-chaos
[morcheeba]: https://en.wikipedia.org/wiki/Morcheeba
[bravebtm]: https://github.com/brave/brave-variations/pull/1504
[mekka2000]: https://www.pouet.net/party.php?which=26&amp;when=2000
[heavenseven]: https://www.pouet.net/prod.php?which=5
[exceed]: https://www.pouet.net/groups.php?which=2
[chopshop]: https://store.steampowered.com/app/2698900/Chop_Shop/
[scdewinterdlc]: https://store.steampowered.com/app/3030350/Stronghold_Crusader_Definitive_Edition__The_Sergeant__The_Lioness/
[rantradio]: https://en.wikipedia.org/wiki/RantMedia
[seankennedy]: https://en.wikipedia.org/wiki/RantMedia#Sean_Kennedy
[id3v1]: https://en.wikipedia.org/wiki/ID3
[fmod]: https://www.fmod.com/
[hak5]: https://web.archive.org/web/20060209191223/http://hak5.org/cast
[win32]: https://en.wikipedia.org/wiki/Windows_API
[newsrealarchive]: https://archive.org/details/news-real-64-270-040306
[exowin9x]: https://www.retro-exo.com/win9x.html
[exodos]: https://www.retro-exo.com/exodos.html
[exowin9xmanual]: https://www.retro-exo.com/eXoWin9x%201994-1996%20Manual.pdf
[volumeicon]: https://github.com/Maato/volumeicon
[viewnior]: https://github.com/hellosiyan/Viewnior/pull/108
[nitrogen]: https://github.com/l3ib/nitrogen/issues/27
[aur]: https://wiki.archlinux.org/title/Arch_Use
[libgtk2-compat]: https://github.com/openSUSE/gtk2-compat
[layoffsfyi]: https://layoffs.fyi/
[yogibear]: https://en.wikipedia.org/wiki/Yogi_Bear
[pcintern]: https://www.amazon.com/PC-Intern-Encyclopedia-Programming-Developers/dp/1557553041
[sdl]: https://github.com/libsdl-org/SDL
[sdl12-compat]: https://github.com/libsdl-org/sdl12-compat
[sdl2-compat]: https://github.com/libsdl-org/sdl2-compat
[thefuture]: https://en.wikipedia.org/wiki/The_Future_(Leonard_Cohen_album)
[leonardcohen]: https://en.wikipedia.org/wiki/Leonard_Cohen
[concernedape]: https://en.wikipedia.org/wiki/Eric_Barone
[johnromero]: https://en.wikipedia.org/wiki/John_Romero
[catacomb3d]: https://en.wikipedia.org/wiki/Catacomb_3-D
