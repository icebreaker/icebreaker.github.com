---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2025
title: 2025 September Retrospective
year: 2025
month: 9
monthly: true
propaganda: ctlr
class: blood nun
music: dj_Xi_yfnAU
tags: retrospective
---

# 2025 September Retrospective

It's September, that's pretty much the start of the early-spooky-season, right? Therefore, I thought that it would be appropriate to have [Conjuring: The Last Rites][conjuringthelastrites] as the theme of this month's retrospective. 

I even adjusted the link highlight color to be *redrum*. As far as the movie goes, I haven't had a chance to watch it yet, but based on the trailer it feels like a proper banger that will do proper justice to the [Conjuring Universe][conjuringseries]. Or perhaps, I should just take my *rose-tinted* glasses off during this rather bitter-sweet moment?

{% include youtube.html id="bMgfsdYoEEo" %}

It turns out that I have gotten my wish after all, and it was very mild and warm September. What more could one want in their lives?

In other news, you'll be pleased to know that there won't be a single mention of [Stronghold Cursader: Definitive Edition][scde] this time around. *Phew*. You can rest easy.

## s&box

One thing that people building products and games seem to get wrong more often than not is the need for frequent and meaningful communication with the customers of said products and/or games.

This is especially true for the so called indies. How many times you stumbled upon a game on Steam or a product on Kickstarter, with no updates in months or years. The excuses are always the same, to the point of becoming boring:

> *Oh, we are very busy!*
>
> *Oh, it takes a lot of time and effort to write up an update.*
>
> *Oh, there isn't much to write about.*

Sounds familiar? It does take some time to write up something meaningful, but it is not an unreasonable or unsparable amount of time by any stretch of the imagination.

Some folks will say, well that is why you need a marketing and social media department, and us poor indies cannot possibly afford that. This is all extremely meaningless cry-baby-woe-is-me type of drivel, totally inconsistent with reality itself, and utter poppy-cock to be perfectly blunt.

If marketing is your only channel of communication, then your product or game is dead, might as well just spare everybody the trouble, and close up shop. I am telling you this as someone who has spent a significant portion of their professional career building tools for marketers. In other words, I know full well, what I am talking about.

I always like to bring up [Facepunch Studios][facepunch] as an example of how to do this right. They are the folks behind a couple of *small* titles (*clears throat!*), like [Garry's Mod][gmod], [Rust][rust] and now [s&box][s&box].

[s&box][s&box] has [monthly updates][s&boxseptemberupdate], which is simply a compilation of screenshots, videos, code-snippets and other tidbits that are sometimes accompanied by small impromptu blurbs of text. Nothing too fancy, but it works quite well, and everybody knows what to expect. There are no endless threads on forums titled "*Is this abandoware?*".

Why do I bring all this up? Well, while I was reading through their [July Update][s&boxjulyupdate], I noticed something that really perked my interest. I am talking about the mention of Box3D, naturally!

> We then moved to Box3D, by the creator of Box2D, which will eventually be free and open source. Rubikon and Box3D are closely related, so this isn't a major difference for users, but it's good for our ecosystem to use libraries that are open source and continually updated.

I always hoped that the talented [Erin Catto][erincatto], the author of [Box2D][box2d], might take pity on us mere mortals at some point or another, and bless us with a 3D physics engine that manages to keep the spirit and usability of [Box2D][box2d]. And, here it was, my eyes weren't deceiving me. It has finally happened.

Speaking of [Box2D][box2d], it came to me that I did a rather silly tech-demo of sorts using it, somewhere in 2008 or maybe 2009. Managed to dust off the source code, and compile it without too much fuss, which is a bit surprising, considering that it uses [Qt][qt] for almost everything. I expected there to be more code-rot as it's customary with anything written in C++, especially when involving a *giga-normous behemoth* of a toolkit like [Qt][qt].

```diff
-#include <QtGui/QApplication>
+#include <QApplication>
```

{% include video.html src="/media/2025/peas.mp4" %}

The sprites are from a particular [Play with your peas][pwp] *prototyping-art-pack* found on [lostgarden.com][lostgarden].

Do you even remember [lostgarden.com][lostgarden], bro? Damn, I feel old just by thinking about it.

## Electron delenda est!

One might argue that [Electron][electron] has become the [Flash][flash] our current era, which wouldn't be too far from the truth, but I claim that it's actually far worse. The seed of the idea has its merits, that much is true, but that's where the pros stop, and the long laundry list of cons start.

The idea of *re-purposing* people with a certain set of skills, to do other adjacent things is as old as this industry, and every single time it has been attempted, it ended in nothing but yet another catastrophic failure.

Do you remember, when everybody and their grandmother was building their in-game UI in Flash all of the sudden? The premise of that fad had its root in the same line of reasoning as Electron. Let's have our people who are familiar with Flash, start working on in-game user interfaces. Everybody profits, right? No, not really!

Now, when it comes to Electron it seems that its maintainers really love mucking around with private and/or undocumented APIs as it can be seen in this [pull request][electronpullrequest].

```objc
// By overriding this built-in method the corners of the vibrant view 
// (if set) will be smooth.
- (NSImage*)_cornerMask {
  if (self.vibrantView != nil) {
    return [self cornerMask];
  } else {
    return [super _cornerMask];
  }
}
```

We have a saying in this particular part of the world, that goes something like this in a more literal translation: *"When you play stupid games, you tend to win stupid prizes!"*. And, that's precisely what these people did by overriding a private method.

When people get upset about Apple rejecting certain apps that use undocumented or private APIs on their iOS app store, this is the reason why.

In the case of Electron, the situation is much worse of course, because it's a toolkit or *platform* if you will, which means that when things break in fundamental ways, then hundreds of thousands of apps break in unison.

## Substack

I always considered [Substack][substack] to be a slightly more posh or elite version of [Medium][medium]. It turns out I was totally off base with my perception (*first time?*); it's more like as if [Tumblr][tumblr] and [X][x] had a weird baby.

A really strange and rather peculiar place, with a *proper feed* (whatever that means!), and everything included. I have to admit that I was shook for a split second. Had to pinch myself to snap out of it.

## YCombinator + GitHub Phishing

I never ceases to amaze me the lengths these people go when it comes to *phishing*. I do wonder how many people have fallen for this particular attempt, which was rather convincing of course.

![yc](/media/2025/yc.png)

It would be interesting to see how many people have fallen for it, especially in this climate, where the AI hype-cycle is still relatively strong, despite what the naysayers might want you to believe.

## Campfire

It looks like one of the members of the great [once.com][once] *buy-once-experiment* has went full open-source. I am talking about the *re-imagined* [Campfire][campfire] of course.

Some people were brining up the fact that this isn't fair to the people who have used their hard earned green American dollars, and bought it at over the course of last year or so.

Well, my message to those people is that long summers, rich harvests, plentiful gain; none of them lasts forever. One can keep complaining about it, or just keep walking with a smile on their face. 

Complaining is much easier, I have to admit.

## Conflict 3049

I am always surprised by what I manage to stumble upon when it comes to [itch.io][itchio]. Truly channels my inner vibe of *"One man's trash, is another man's treasure"*.

This is exactly how I found out about [Conflict 3049][conflict3049], which seems to be a one-man passion project type of a deal from the looks of it.

{% include youtube.html id="gHgubAz8tbc" %}

A little bit rough around the edges, and even somewhat peculiar, but pretty amazing.

But, wait, there's more. I have a very serious question for you. When was the last time you compiled a `game.cs` that was `32000` lines long?

```bash
$ wc game3d.cs -l
32510 game3d.cs
```

Yes, you read that right, it's not a typo. The question is, will it compile on Linux? 

I started by converting the windows new-lines to unix ones, by running:

```bash
$ dos2unix game3d.cs
```

Then, I bumped the [.NET][dotnet] version to `9.0`.

```diff
diff --git a/Raylib-cs.csproj b/Raylib-cs.csproj
index 6a034a6..d735c46 100644
--- a/Raylib-cs.csproj
+++ b/Raylib-cs.csproj
@@ -1,7 +1,7 @@
 <Project Sdk="Microsoft.NET.Sdk">
   <PropertyGroup>
        <OutputType>Exe</OutputType>
-    	<TargetFrameworks>net6.0</TargetFrameworks>
+    	<TargetFrameworks>net9.0</TargetFrameworks>
        <AllowUnsafeBlocks>true</AllowUnsafeBlocks>
        <LangVersion>preview</LangVersion>
   </PropertyGroup>
```

Then, it was time to build it. I must confess that I cheated a little bit, and added `#pragma warning disable CS8981` to `game3d.cs` in order silence some of the obnoxious warnings.

```bash
$ dotnet build
Restore complete (1.1s)
  Raylib-cs net9.0 succeeded (6.3s) → bin/Debug/net9.0/Raylib-cs.dll

Build succeeded in 8.0s
```

Now, I just needed to grab the pre-compiled shared libraries of [Raylib][raylib] for Linux, and unceremoniously untar them into the `bin/Debug/net9.0/` directory. Why didn't we just call them *tar-pits*?

```bash
$ ls
libraylib.so   libraylib.so.550    Raylib-cs.deps.json 
Raylib-cs.pdb  libraylib.so.5.5.0  Raylib-cs
Raylib-cs.dll  Raylib-cs.runtimeconfig.json
```

Then, last but not least, I also copied the `files/` directory, and finally launched the game with the following incantation:

```bash
$ cp media/potato.txt media/potato_windowed.txt
$ <edit media/potato_windowed.txt>
$ ./Raylib-cs potato_windowed.txt
```

![c3049](/media/2025/c3049.png)

On exit, you might notice two distinct things that went wrong, the configuration path is all messed up, and then the more obvious segmentation fault.

```bash
Local Storage Error:Could not find file '/home/user/.local/share\config3049_firebase\localstorage.txt'.
Segmentation fault         (core dumped) ./Raylib-cs potato.txt
```

The first one is a relatively easy fix. No fuss, no muss! Just, don't forget to clean up your `~/.local` directory afterwards.

```cs
// ...

#if false
	string folderd = Environment.GetFolderPath(
		Environment.SpecialFolder.LocalApplicationData
	) + "\\" + NETTITLE;
#else
	string folderd = System.IO.Path.Join(
		Environment.GetFolderPath(
			Environment.SpecialFolder.LocalApplicationData
        ),
    	NETTITLE
	);
#endif
    
// ...

#if false
	filename = Environment.GetFolderPath(
		Environment.SpecialFolder.LocalApplicationData
	) + "\\" + NETTITLE + "\\localstorage.txt";
#else
    filename = System.IO.Path.Join(
   		Environment.GetFolderPath(
        	Environment.SpecialFolder.LocalApplicationData
        ),
        NETTITLE,
        "localstorage.txt"
   	);    
#endif
   
// ...
```

As for the nasty segmentation fault itself, I really couldn't be bothered to fix it, but it's happening during the *"unloading"* (*read: freeing*) of resources.

```cs
// ...
UnloadHelper.UnloadAll();
Raylib.UnloadRenderTexture(ui);
Raylib.UnloadRenderTexture(screentexture);
// ...
```

I'll leave that as some sort of an exercise for the reader. It's not much, but it's honest work.

## [#ChatControl][chatcontrol]

I am really surprised to see how little *noise* is about this, compared to all the previous times. Makes one really question things a whole lot more.

There's a pretty big difference between issuing a *subpoena* to get the messages, emails, etc. of someone on suspicion of any legal mischief, and to preemptively *scanning* absolutely everything in real-time.

If this passes and comes into effect, it will cross a line into the territory of things that simply cannot be undone, and will usher in the beginning of a *pan-european* socialist *nanny-state*. The fact all this is even contemplated as a concept, should worry everyone, regardless of their station in life.

It warrants a national day of mourning and pity. May the [Lords of Kobol][lordsofkobol] have mercy on our souls.

## The Tower Stream

[The Primeagen][theprimeagen] should need no introductions, whatsoever, I hope. This was the second so called *tower stream*, where he and his rag-tag bunch of cyber-misfits took it upon themselves to *vibe-code* a tower defense game.

{% include youtube.html id="4RdIU71yJlY" %}

{% include youtube.html id="MJIMxBEdKBQ" %}

I think that the videos above should speak for themselves. *Enough said*.

## [Keychron B1 Pro Ultra-Slim][keychronb1pro]

Alas, my trusty [ThinkPad TrackPoint Keyboard II](https://www.lenovo.com/us/en/p/accessories-and-software/keyboards-and-mice/keyboards/4y40x49493) has finally given out, and because it didn't look like I could source a new one from any of the local resellers, I decided to try a something rather special, and impulse bought a [Keychron][keychron]. My thinking was that if I doesn't work out, then I'll just buy another ThinkPad straight from the source, with all the import duty fees and all.

![kb1pro](/media/2025/kb1pro.png)

Now, I don't want to hype it up too much just yet. Considering that it's only been around 2 weeks at the time of me writing this, but I must say that it's probably one of the best keyboards that I ever had.

The only minor gripe that I have is the size of the *Up* and *Down arrow keys*, which is not end of the world by any means, but worth calling out nonetheless, lest I be called a shameless shill.

What about, *Home*, *End*, *Page Up* and *Page Down*, though? It's funny that you ask. I ended up remapping *F9* through *F12* for this purpose.

There's a lot of rather conflicting information about how one would go about remapping keys in the Linux world. In reality, the only thing one needs is [xmodmap][xmodmap]. *Easy-peasy lemon-squeezy.*

Here is my `~/.Xmodmap` configuration file:

```bash
keycode 108 = Mode_switch Mode_switch Mode_switch Mode_switch
keycode 75 = Home Home F9 F9 F9
keycode 76 = End End F10 F10 F10 
keycode 95 = Prior F11 F11 F11 F11 
keycode 96 = Next F12 F12 F12 F12
```

In order to save you from the trouble of attempting to decipher the meaning of all this, let me lay it all out neatly on a tray for you.

```bash
key <code> = <key> \
			 <shift + key> \
		     <mode_switch + key> \
		     <mode_switch + shift + key> \
		     <altgr + key>
```

The `Alt_R` key didn't seem to produce `AltGr` for some reason, which is why I ended up remapping it to `Mode_switch` instead, hence the accompanying line:

```bash
keycode 108 = Mode_switch Mode_switch Mode_switch Mode_switch
```

Nice!

## Megabonk

![megabonk](/media/2025/megabonk.png)

Now that the onslaught of *Vampire-survivor-like* clones have tapered off quite a bit, we are starting to get some more interesting takes on the genre. The essence or secret sauce if you will is still very much the same, so if you haven't bought in into this genre before, then it's highly unlikely that [Megabonk][megabonk] or any other title will convince you to do so, but it's still cool to see a new entry joining the family.

Check out the trailer below and decide if this is something that speaks to you, or not. This is a safe and calm place, we do not judge anyone here, rest assured!

{% include youtube.html id="PlC4_c2dcGw" %}

Looking at [Gamalytic][gamalytic], it appears that it has crossed the 1 million copies sold mark, which is always impressive, especially for a game that seems like it has been the brain-child of a *solo-developer*. Yes, yes, I am fully aware that this is a very charged, and highly controversial term to drop without proper trigger warnings in game-development circles, and I just committed the gravest sin by using it. I beg your forgiveness!

## Kingdom Rush 5: Alliance TD - Wukong's Journey Campaign

![wukong](/media/2025/wukong.png)

It should be a relatively well known fact that I am, and I've been a long time fan of the [Kingdom Rush][kingdomrush] series, so whenever there's a new content drop in the form a [DLC][dlcwukong] or a new title in the series, I am bite.

{% include youtube.html id="ewsxkmt8X2A" %}

People always end up complaining about the prices of these DLCs, and get into painstakingly detailed calculations into the dollar versus content (*read: value-add*) ratios, etc. Such a *silly-goose* thing to do!

But, people, gotta' people, am I right?

## A Difficult Game About Climbing: Chapter 2

![new_map_exe](/media/2025/new_map_exe.png)

The *mini-dev-log* of the new map is finally here. [Mr. Ponty Pants][pontypants], doesn't disappoint as per usual. Enjoy!

{% include youtube.html id="ohI3Rvq4enQ" %}

Very curious to see what he'll cook up next!

## MOLYNEUX: The Nobody

[Ahoy][ahoy] (*Stuart Brown*) dropped yet another banger. Two in a row? What a way to kick off fall.

{% include youtube.html id="H1jwoyBRYcU" %}

## We need to start having babies!

Here's your monthly reminder, that we need to start having babies *pronto*!

{% include video.html src="/media/2025/wntshb.mp4" %}

[President Roslin][presidentroslin] is absolutely in the right. Wouldn't you say?

## Monthly Dad Joke

> **Q:** Why did the computer go apple picking in early September?
>
> **A:**  It wanted to upgrade its "core" memory with some fall bytes!

[ahoy]: https://www.youtube.com/@XboxAhoy
[conjuringthelastrites]: https://en.wikipedia.org/wiki/The_Conjuring:_Last_Rites
[conjuringseries]: https://en.wikipedia.org/wiki/The_Conjuring_Universe
[chatcontrol]: https://metalhearf.fr/posts/chatcontrol-wants-your-private-messages/
[pwp]: https://lostgarden.com/2008/02/06/play-with-your-peas-a-game-prototyping-challenge/
[gamalytic]: https://gamalytic.com/game/3405340
[megabonk]: https://store.steampowered.com/app/3405340/Megabonk/
[dlcwukong]: https://store.steampowered.com/app/3732970/Kingdom_Rush_5_Alliance_TD__Wukongs_Journey_Campaign/
[kingdomrush]: https://en.wikipedia.org/wiki/Kingdom_Rush
[pontypants]:  https://www.youtube.com/@Pontypants
[presidentroslin]: https://galactica.fandom.com/wiki/Laura_Roslin
[keychron]: https://www.keychron.com/
[keychronb1pro]: https://www.keychron.com/products/keychron-b1-pro-ultra-slim-wireless-keyboard
[xmodmap]: https://linux.die.net/man/1/xmodmap
[theprimeagen]: https://www.youtube.com/@ThePrimeTimeagen
[once]: https://once.com/campfire
[campfire]: https://github.com/basecamp/once-campfire
[lordsofkobol]: https://en.battlestarwikiclone.org/wiki/Lords_of_Kobol
[substack]: https://substack.com/
[medium]: https://medium.com/
[tumblr]: https://www.tumblr.com/
[x]: https://x.com
[electronpullrequest]: https://github.com/electron/electron/pull/48376
[electron]: https://en.wikipedia.org/wiki/Electron_(software_framework)
[flash]: https://en.wikipedia.org/wiki/Adobe_Flash
[gmod]: https://store.steampowered.com/app/4000/Garrys_Mod/
[rust]: https://store.steampowered.com/app/252490/Rust/
[s&box]: https://sbox.game/
[facepunch]: https://en.wikipedia.org/wiki/Facepunch_Studios
[s&boxseptemberupdate]: https://sbox.game/news/september-2025
[s&boxjulyupdate]: https://sbox.game/news/july-2025#box3d
[erincatto]: https://box2d.org/about/
[box2d]: https://box2d.org/
[qt]: https://www.qt.io/
[lostgarden]: https://lostgarden.com/
[conflict3049]: https://matty77.itch.io/conflict-3049
[dotnet]: https://en.wikipedia.org/wiki/.NET
[scde]: https://store.steampowered.com/app/3024040/Stronghold_Crusader_Definitive_Edition/
[itchio]: https://itch.io/
[raylib]: https://www.raylib.com/
