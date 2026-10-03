---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2026/
title: 2026 September Retrospective
propaganda: residentevil
music: emT9oQuXtnU
tags: retrospective
---

2026 September Retrospective
=========================

This is the first month, where I started jotting down notes about the various *thingamajigs* that ended up peeking my interest as they happened over the course of the month; and boy-oh-boy it quickly became a rather large compilation of semi-random-ad-hoc stuff. I had to cull the list a wee bit, but not terribly too much.

Nonetheless, it's a step in the right direction as I don't have to scramble around chaotically anymore when the time comes to writing up these monthly retrospectives, trying to remember *all of the things*.

I'd like to get to the point where I'd only have to do some lightweight editing before publishing it all, but hey, let's don't get ahead of ourselves yet again.

## Resident Evil

I came to expect [James Wan][jameswan] to officially kick-off the *horror season*, but since the latest entry in the [Insidious franchise][insidiousfranchise] dropped all the way back in August, I found myself shopping around for another horror flick worthy of *becoming* September's theme.

Now, there's plenty of *indie* slop out there, which is how it always was in this particular genre, but I  naturally expect a bit *more*, if I am to spend `90` to `120` minutes on something like this.

![residentevil](/media/2026/residentevil.png)

In any case, I didn't have to look for too long before the trailer for [Resident Evil][residentevil] popped up on my radar.

{% include youtube.html id="dvyDrw7KlNE" %}

I haven't had a chance to watch it yet. as I am not a big movie theater guy. Who would have guessed, right? But, I do hope that it will do at least slightly better than [Return to Silent Hill][silenthill] from all the way back in January this year.

If the official soundtrack is anything to go by, this one might turn out to be pretty good.

## Your Debt Is Paid

![yourdebtispaid](/media/2026/yourdebtispaid.png)

While we are on the subject of horror, I wanted to call out this tiny clicker game going by the title of [Your Debt Is Paid][yourdebtispaid], which has been baked in something like 2 weeks for the [Creepy Clicker Horror Game Jam 2026][creepyclickerhorrorgamejam2026].

The `CRT` effect is really not my *jam* (*phun intended!*), but other than that who can say no to some mindless auto-clicking-action, especially during the dark, and rather cold autumn nights?

## M$ 0ff1c3 2K: Get ready for a brand-new age

![mso2k](/media/2026/mso2k.png)

If you were in the mood to be transported back to a time, when M1cr0sl0p's marketing budget was bigger than several developing countries **GDP** combined, then I can guarantee that you'll not walk away disappointed, after listening to this absolute *banger* of a *gem* from around the time of the *new millennium*. 

{% include archiveorg.html slug="12-well-balanced" playlist="true" %}

## Jev

> *Et tu, Brute?*

Yes, I am going to go there, and going to talk about it. *Exhales, audibly!* I saw this one coming from an *X feed away*, as it was slowly working its way up until everybody and their grandmother was yapping about it.

Just when I was thinking that the *webizens* of the great information-superhighway might have learned a thing or two about the *OpenClaw-hype-cycle* of yesteryear, they have proven yet again without a shadow of a doubt that the more things change, the more they stay the same.

The buzzword salad recipe got a rather tasty new ingredient in the form of [System One models][systemonemodels] this time around. The major question of course is whether did it make the salad ever so slightly tastier or not?

I'll let you be the judge of that on your own time, and your own dime.

Be that as it may, I'll add two things. First, don't even think about using such a *model-as-a-service*, if you know what's good for you. Train it, host it and run it on-premise, or simply forget about it.

Second, the only good thing that came out of this *whole charade* is the fact that more people have gotten to see that fact that alternate model types can be fast, while still remaining somewhat accurate and useful.

## Kingdom Rush 6: Genesis

![kingdomrush6genesis](/media/2026/kingdomrush6genesis.png)

All three of you who actually pretend to read any of the stuff that I end up yapping about on here, must know by now that I am a huge fan of the [Kingdom Rush][kingdomrush] series.

{% include youtube.html id="dgQ7SAbmCVY" %}

I am happy to report that [Kingdom Rush 6: Genesis][kingdomrush6genesis] is pretty much all what we have grown to expect from an entry in this long running franchise; a tad unbalanced around the edges as per usual, but I wouldn't have it any other way to be honest.

## Monoplex: Terminal

A couple years ago, I grew very tired of my terminal looking like *fruity loops* on `LSD` all the time, and made the decision of crafting a very low-profile color scheme by using only mostly grays and a very tiny selection of handpicked colors to act as accents.

The first application that I focused on was `vim` of course, and this month I finally finished touching up `tmux` and `cmus`, and I was quite happy to welcome them into the `Monoplex` family.

![monoplex](/media/2026/monoplex.png)

Without giving away too much about the future, I think that `mc` and `irssi` might be next on the list.

Before you say anything, I have spent most of my life in the terminal, way before the *AI bros* even knew what it was, and many of them weren't even born yet.

Before `tmux`, I used to hang out in `screen`. Okay?

## Monoplex: Jekyll

In very much the same vein, I've been working my way towards cobbling together a `Jekyll` theme, by laying down the ground work necessary to be able to extract the *color-scheme* and *layout* into a separate standalone *theme* in the form of a `Ruby` gem.

One piece that was standing in the way of this was the way I ended up pre-processing the `css` in order to replace all the variables which would allow me to play around around with various *color-schemes* in a relatively painless manner as it were.

This month, I got rid of it all and replaced it with something that leverages the built-in layout system, after which my `style.css` ended up looking something like what you can see below:

```css
{%- raw -%}
---
layout: css 
---
{%- include colorscheme.css -%} 
html
{
    text-rendering: geometricprecision;
    -webkit-text-size-adjust: 100%;
    -webkit-font-smoothing: antialiased;
    -moz-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
}

body
{
    margin: 0;
    padding: 0 10px 10px 10px;
    font-family: sans-serif;
    font-size: 21px;
    line-height: 30px;
    background-color: {{ background }}; 
    color: {{ foreground }}; 
    max-width: 1024px;
}
/* the rest of the file has been omitted for brevity */
{% endraw %}
```

 What about the included `colorscheme.css`?

```css
{%- raw -%}
{%- assign colorscheme = page.colorscheme | default: site.colorscheme -%}
{%- assign colorscheme = colorscheme | default: "www" | append: "" -%} 
{%- assign colorscheme = site.data.colorschemes[colorscheme] | default: site.data.colorschemes["www"] -%%}
{%- assign background = colorscheme.background | default: "#FFFFFF" %} 
{%- assign foreground = colorscheme.foreground | default: "#000000" %}
/* the rest of the file has been omitted for brevity */
{% endraw %}
```

Why not `SASS` or `SCSS`? I see that you like acronyms, here's another one for you: `KISS`. How do you like that?

## The Monkey's Paw

![monkeyspaw](/media/2026/monkeyspaw.png)

It appears that my friends over at [Stuck In Attic][stuckinattic] have been rather busy as of late.

{% include youtube.html id="HP8VgFtm2ks" %}

[The Monkey's Paw][themonkeyspaw] is definitely a slight departure from their usual cheery vibes, but I think that it's all very much in vogue right now, given the current circumstances.

Also, it is extremely wise to publish this under a separate [Ninja Paw][ninjapaw] entity in order to prevent diluting the other original IPs, all of which have taken literally years to grow and cultivate.

## Q Lazarus: Goodbye Horses

{% include bandcamp.html album="3149333135" href="https://q-lazzarus.bandcamp.com/album/goodbye-horses" title="Goodbye Horses by Q Lazzarus" %}

Are any of you a size `67` by any chance?

## Microsoft Systems Journal

The [Microsoft Systems Journal][msj] is something that I didn't know that I absolutely needed at this point in my life. Dad jokes aside, it's an absolute treasure trove for people like myself who enjoy digging through old stuff just for *funsies*.

Besides, it's always refreshing to hear about certain things straight from the proverbial *horses mouth*, in this particular case the behemoth of the 90s, the absolute unit that used to be *Microshaft* in its *heyday*.

![msj_1994_09](/media/2026/msj_1994_09.png)

There's a fairly comprehensive *index* of all known issues that has been painstakingly compiled by a fellow *internaut* by the name of [Jacob Filipp][jfilip], and can be found by heading over to his [blog][msjindex].

I should have included a trigger warning for [OLE][ole]. Sorry for that, and I promise that I'll do better next time.

## BBC Archive:  1985

{% include youtube.html id="qXAubRZ-qjw" %}

Any comments would be superfluous and totally unnecessary. Just watch it.

## Keychron

I bought a [Keychron B1 Pro Ultra-Slim][keychronb1pro] exactly one year ago. I am happy to report that it's still powered by the single charge from exactly the same time.

![kb1pro](/media/2025/kb1pro.png)

So the battery lasting *8 months plus* on a single charge, wasn't just a marketing gimmick after all. Either that, or I need to work even more crazy hours. *I kid, I kid.* Don't call the *work-life-balance police* on me, pretty please?

The protective silicon cover did start to deteriorate though, around 6 or so months in; but I wasn't expecting that to last more than a few weeks to be perfectly honest.

Since going a whole year without thinking too much about keyboards has started to feel unbearable, I ended up buying a very nice looking [Keychron J2 QMK][keychronj2qmk] as an attempt to satiate my ever growing hunger for brand new keyboards.

![keychron_j2_qmk](/media/2026/keychron_j2_qmk.png)

What I didn't realize before I ordered this one is the fact that it's super duper thick, or the very least way thicker than I imagined, when I looked at the reviews out there.

I didn't take long, before it became obvious that I needed to get a palm rest of some description, in order to not to completely destroy my hands, or what is left of them anyway at this point.

Will I switch away from my trusty *B1 Pro* and use this as my daily driver? I am not sure that I have made up my mind about it just yet. It's still very much early days. 

Besides, there's something rather special between *Miss B1* and myself.

We'll see what the has in store for us, and I'll be sure to give yet another update in a years time or thereabouts.

## Markdown Front-Matter

I totally understand that we live in the *first-agentic-era* right now, but I must say that the *markdown front-matter* situation seems to be getting way out of hand as you'll see in a second.

Take a look at the snippet that I pulled from: [developer.apple.com/documentation/swift/array.md][swiftarray].

````md
<!--
{
  "availability" : [
    "iOS: 8.0.0 -",
    "iPadOS: 8.0.0 -",
    "macCatalyst: 13.0.0 -",
    "macOS: 10.10.0 -",
    "tvOS: 9.0.0 -",
    "visionOS: 1.0.0 -",
    "watchOS: 2.0.0 -"
  ],
  "documentType" : "symbol",
  "framework" : "Swift",
  "identifier" : "/documentation/Swift/Array",
  "metadataVersion" : "0.1.0",
  "role" : "Structure",
  "symbol" : {
    "kind" : "Structure",
    "modules" : [
      "Swift"
    ],
    "preciseIdentifier" : "s:Sa"
  },
  "title" : "Array"
}
-->

# Array

An ordered, random-access collection.

```
@frozen struct Array<Element>
```

## Overview

Arrays are one of the most commonly used data types in an app. You use
arrays to organize your app’s data. Specifically, you use the `Array` type
to hold elements of a single type, the array’s `Element` type. An array
can store any kind of elements—from integers to strings to classes.
````

Hello? What is going on? Would it have been so hard to just use the good old fashioned `YAML` *front-matter* here, without going out there into the wilderness of `JSON`?

````md
---
availability:
  - "iOS: 8.0.0 -"
  - "iPadOS: 8.0.0 -"
  - "macCatalyst: 13.0.0 -"
  - "macOS: 10.10.0 -"
  - "tvOS: 9.0.0 -"
  - "visionOS: 1.0.0 -"
  - "watchOS: 2.0.0 -"
documentType: symbol
framework: Swift
identifier: /documentation/Swift/Array
metadataVersion: 0.1.0
role: Structure
symbol:
  kind: Structure
  modules:
    - Swift
  preciseIdentifier: s:Sa
title: Array
---

# Array

An ordered, random-access collection.

```
@frozen struct Array<Element>
```

## Overview

Arrays are one of the most commonly used data types in an app. You use
arrays to organize your app’s data. Specifically, you use the `Array` type
to hold elements of a single type, the array’s `Element` type. An array
can store any kind of elements—from integers to strings to classes.
````

How about that? Something relatively sane for a change. Look, I like `JSON` as much as the next man, but just adding chaotic `JSON` blobs to markdown *willy-nilly*, seems rather weird to me.

Hi, bye!

## GOG: id

Might have went a tad overboard with all the `60%+` sales going on [GOG][gog] as of late.

![gogid](/media/2026/gogid.png)

Truth be told, I already had most of these on Steam, but I like to have **DRM** free copies as well for select titles within my games library.

## Macroblank - лучшие дни

![macroblank](/media/2026/macroblank.png)

What an *absolutely insane refresh pull*! 

{% include youtube.html id="ObrZov3VJ48" %}

Am I hip enough to be allowed into a *Corgi Cafè*, now?

## Mythbusters Pizza Catcher

After I pulled out three projects in a row written in Delphi over the course of the summer, I wanted to switch things up a bit and dust off something written in C again.

![mbpc](/media/2026/mbpc.png)

It should be patently obvious just by looking at the screenshot above, that this was never finished. Quite honestly, I don't even remember where on earth did I source the graphics from at the time.

I tried searching around , but couldn't find anything about mentioning the *Mythbusters* and *pizzas* in the same breath that might even be remotely related to a game written in Flash or anything of the sorts.

Looking at the source code made me cringe a bit, when I saw things like:

```c
void BufferSwap(HDC hDC)
{
	BitBlt(hDC,
		0,
		0, 
		g_rcClient.right,
		g_rcClient.bottom,
		g_hDCMem,
		0,
		0,
		SRCCOPY
	);
}
```

It's an enormous soup composed of *globals*, and **GDI** *galore*, which is not too surprising to be perfectly honest, because I just didn't know any better at that point in time.

On the other hand, I was doing *double-buffering*, that must count for something, am I right?

![salmon2](/media/2026/fishart/salmon2.png)

Then of course, how could one forget about:

```c
g_hBackground = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(1));
```

But the thing that hit me right in the feels was this little nugget:

```c
void InitPizzas(void)
{
	int i; 
	for(i = 0; i < MAX_PIZZAS; i++)
	{
		g_Pizzas[i].iSpeed = random(5);
	}
}
```

Did I mention that it was unfinished? Yeah, it was left to rot in the archives for a reason.

![mbpcicon](/media/2026/mbpcicon.png)

**P.S**: The icons that I was using for these projects are so totally random, that I don't even know what to say.

## Gemini 4: Argon

Let's hope that [Gemini 4][gemini4] hasn't been also completely *lobotomized* like all its predecessors. The fact that mighty Google who has pretty much the entire web *crawled & cached*, cannot release something that isn't akin to a *neutered* stray dog howling at the moon, it is absolutely mind-boggling to me.

Is this all the *elite-painstaking*, and ultimately *utterly-irrelevant* **interview process** can conjure up from the ***void***?

Now, I am sure that someone will say that I'd have to go higher than the *Plus plan* to get access to the really *juicy stuff*. Maybe so, but it's still all very embarrassing, no matter how one does look at it.

## Kingdom III: Rising Realms

![kingdom3](/media/2026/kingdom3.png)

[Raw Fury][rawfury] have been the *de-facto benevolent stewards* of the [Kingdom franchise][kingdomfranchise] for quuite some time now, but after the last few entries in the franchise ending up having a mostly lukewarm reception, I would say, there didn't seem to be a lot of traction towards yet another major entry in the series.

{% include youtube.html id="Pr6lCUWv5MM" %}

I will no doubt end up buying this on launch day.

## s&box

In my July retrospective I was lamenting about the fact that several months after the release of [s&box][sbox], there didn't seem to be any movement at all towards a native Linux port of the `runtime` or the `editor` itself.

Which is why I ended up exploring running the `editor` via `Proton`. Then, here we are a couple of short months later, and all that has changed for the better I might add.

![sbox-splash-linux](/media/2026/sbox-splash-linux.png)

I was eager to pull down the public repository, and try it out for myself as one does.

```bash
#!/bin/sh
# s&box setup for Linux and macOS (Windows: Setup.bat).
# Downloads the prebuilt engine artifacts, builds the managed engine,
# shaders and content, and installs git hooks that keep the artifacts
# current after a pull, rebase or branch switch.
# Pass --verbose for full build output.
set -e
cd -- "$(dirname -- "$0")"

if ! command -v dotnet >/dev/null 2>&1; then
    echo "The .NET 10 SDK is required but 'dotnet' was not found on PATH."
    echo "Install it from https://dotnet.microsoft.com/download and rerun ./Setup.sh."
    exit 1
fi

exec dotnet run --verbosity quiet \
	--project ./engine/Tools/SboxBuild/SboxBuild.csproj \
	-- bootstrap "$@"
```

Running `Setup.sh` worked on the first try, and I didn't have to adjust anything at all. Job well done *sausage people*.

![sbox-launcher-linux](/media/2026/sbox-launcher-linux.png)

Sadly, I made the mistake of deleting the `sbox` directory outside of **Steam**, while performing some clean-up, after which even with a complete wipe of **Steam**, a fresh clone and running `Setup.sh` again, launching the editor would always result in a segmentation fault due to what appears to be a `double free`,  buried deep somewhere in there.

```bash
free(): invalid pointer
```

My educated guess is that it's failing to link up the `local game depo` again, because the `sbox` directory is not getting *(re-)created* anymore, like the very first time I ran `Setup.sh`, and subsequently launched the `editor`.

Should have taken some more screenshots, back when it was in good working order, but hey, it's quite pointless to cry over spilled milk after the fact, isn't it so?

I might circle back, and attempt running it in a **debugger** at some point, because it's really nagging me now.

That said, I still consider this to be an overall success, I mean when was the last time anything you *cloned* has just built and ran the first time around, without having to fiddle for three days and three nights with it?

## Jonathan Blow: Trip to China & Dev Spotlight

{% include youtube.html id="EPAGXfHkBLA" %}

Is it time for order of the sinking star, or our star yet? So easy to confuse. Too soon? Alright, I'll see myself out.

## Ashens: Microwaved Burger Extravaganza

{% include youtube.html id="oxvpYm6V0ww" %}

All these burgers would be about `1000%` tastier and all around better, if they were heated up in an electric oven, rather than a microwave.

{% include youtube.html id="edZVbaNjt98" %}

No more *saggy buns*, and all that good stuff. I am not affiliated with nor am I sponsored by **SilverCrest**.

## Dungeonbound

![dungeonbound](/media/2026/dungeonbound.png)

[Dungeonbound][dungeonbound] is yet another *first-person auto-battler dungeon-crawler*, which has caught my eye this month.

{% include youtube.html id="EMooHSyTam8" %}

### Can we talk about the sprites' situation?

> *Q: Did you steal these sprites from BuriedBornes?*
>
> *A: those [sic] sprites are public domain, I didn't steal anything.*

One of the many caveats of using sprites or any assets really that have a permissive license or are in the *public-domain* is that conversations like the one above will pretty much be inevitable, I am afraid. So, you better have a thick skin before you decide to do so.

If you aren't exactly *in the know* about which sprites is this all about, just like I was when I first saw this *convo* happening, then you can head over to [pixiv.net/en/users/5887541][javadry] to find out more.

![pixiv_net_5887541_javardry](/media/2026/pixiv_net_5887541_javardry.png)

Just as a side note for all the *young-lings* out there, altering or transforming said sprites ever so slightly can be prove to be fairly effective when it comes to fending off the inevitable troll brigade, when it does show up.

## The .NET

The fact that there was a magazine called [The NET][thenet] is the most typical `1990s` thing ever.

![thenet_vol1_issue10_march_1996](/media/2026/thenet_vol1_issue10_march_1996.png)

Alas, I only managed to find a [handful of issues][thenetarchiveorg] out there on the *great interwebz archive*, which is an absolute shame and an international scandal of epic proportions.

![thenet_vol1_issue10_march_1996_prodigy](/media/2026/thenet_vol1_issue10_march_1996_prodigy.png)

Even Corgi Cafès' were hitting a whole lot different back then, from the looks of it. The ads in these old magazines are just *chef's kiss* all the way out there. It should go without saying that none of these would fly in today's world, but hey, let's not forget that this was the good old ***90s*** after all.

Also, did I ever mention by the way that pretty much all the `CBZ` and `CBR` *viewers* out there are absolutely horrendous in every respect? No? Well, I said it now! Might have to do something about that. *Wink, wink* ...

## M$ Win95 Launch with Bill Gates & Jay Leno

{% include youtube.html id="_JzfROUDsK0" %}

## M$ Win95 Video Guide with Jennifer Aniston & Matthew Perry (VHS)

{% include youtube.html id="6ypXfodOu-s" %}

## Steampeek

Who knew about [Steampeek][steampeek]? I most certainly didn't.

![steampeek](/media/2026/steampeek.png)

The so called *discovery ecosystem* that has been built up around Steam, never ceases to amaze me. Seriously!

## The "Sackhoff" Show

![starbuck](/media/2026/starbuck.png)

{% include youtube.html id="iy5eIhEogXY" %}

{% include youtube.html id="PiOIXIIUdR4" %}

{% include youtube.html id="iHLaj58B_fs" %}

{% include youtube.html id="kcQzCihGAgI" %}

## Monthly Amazon "*Book Review*"

The third edition of [Real Time Rendering][realtimerendering] was yet another one of those spur of the moment purchases.

![realtimerendering](/media/2026/realtimerendering.png)

Is it any good? Well, I know that a great many people weren't too amused by it back in the day, but it's probably still very much the best *"reference book style material"* out there. Sure, some will say that this is *ancient* by now, and perhaps you should get the *fourth edition* instead, but those are just simple details.

The fundamentals in themselves, didn't really change all that much since this was published.

And now, it's time for the obligatory reviews, that I curated specially just for your eyes only.

![rtrrev1](/media/2026/rtrrev1.png)

![rtrrev3](/media/2026/rtrrev3.png)

![rtrrev2](/media/2026/rtrrev2.png)

*No code, no buy?* Oh well.

## Monthly *"Coup de cœur"*

Since I wanted to switch things up a bit, I decided to look up some of my old favorites in the so called *music-disk* category; while browsing around said category, I accidentally stumbled upon one in particular that I do not remember seeing back in the day, like at all. Drawing a complete blank on it.

![musicdisk](/media/2026/emeraldbox.png)

I am talking about [Emerald Box][emeraldbox] by [Conspiracy][conspiracy] from `May 2004`.

{% include youtube.html id="iRu12JHIRHc" %}

Please enjoy the tunes by [Vincenzo][vincenzo], and don't forget to try the fish!

[jameswan]: https://en.wikipedia.org/wiki/James_Wan
[insidiousfranchise]: https://en.wikipedia.org/wiki/Insidious_(film_series)
[rawfury]: https://en.wikipedia.org/wiki/Raw_Fury
[kingdomfranchise]: https://en.wikipedia.org/wiki/Kingdom_(video_game)
[systemonemodels]: https://typesafe.ai/blog/introducing-system-one-models-and-jev
[emeraldbox]: https://www.pouet.net/prod.php?which=12258
[conspiracy]: https://conspiracy.hu/
[vincenzo]: https://vincenzo.bandcamp.com/
[silenthill]: https://en.wikipedia.org/wiki/Return_to_Silent_Hill
[residentevil]: https://en.wikipedia.org/wiki/Resident_Evil_(2026_film)
[realtimerendering]: https://www.amazon.com/dp/1568814240
[steampeek]: https://steampeek.hu/?appid=251730
[thenet]: https://en.wikipedia.org/wiki/Net_(magazine)
[thenetarchiveorg]: https://archive.org/search?tab=all&amp;query=the+net
[dungeonbound]: https://louidev.itch.io/dungeonbound
[javadry]: https://www.pixiv.net/en/users/5887541
[sbox]: https://sbox.game/news/update-26-09-01
[gemini4]: https://blog.google/innovation-and-ai/models-and-research/gemini-models/gemini-4-argon/
[swiftarray]: https://developer.apple.com/documentation/swift/array.md
[keychronj2qmk]: https://www.keychron.com/products/keychron-j2-qmk-wireless-mechanical-keyboard
[keychronb1pro]: https://www.keychron.com/products/keychron-b1-pro-ultra-slim-wireless-keyboard
[msj]: https://www.pcjs.org/documents/magazines/msj/
[msjindex]: https://jacobfilipp.com/msj-index/
[jfilip]: https://jacobfilipp.com/
[ole]: https://en.wikipedia.org/wiki/OLE_Automation
[yourdebtispaid]: https://cmski.itch.io/your-debt-is-paid
[creepyclickerhorrorgamejam2026]: https://itch.io/jam/creepy-clicker-horror-game-jam-prizes
[kingdomrush]: https://en.wikipedia.org/wiki/Kingdom_Rush
[kingdomrush6genesis]: https://store.steampowered.com/app/4259190/Kingdom_Rush_6_Genesis_TD/
[themonkeyspaw]: https://store.steampowered.com/app/5179380/The_Monkeys_Paw/
[ninjapaw]: https://store.steampowered.com/curator/46277932
[stuckinattic]: https://store.steampowered.com/developer/stuckinattic/
[gog]: https://gog.com
