---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2025
title: 2025 August Retrospective
year: 2025
month: 8
monthly: true
propaganda: kinoleto
music: iOvYGQtFBNM
tags: retrospective
---

# 2025 August Retrospective

As [summer is coming to an end][kinoleto], I can only hope that we'll have some [indian summer][indiansummer] this year, or just a plain old fashioned warm-autumn at least. Is that too much to ask?

This August felt to be packed with all sorts of events, drama and so forth, so much so that I had to cherry-pick some of the highlights, which is very rarely the case.

The base selection or filtering criteria that anyone reading this blog should be familiar with by now, boils down to the infamous *trifecta* composed of *no sex, religion or politics*. Deceptively simple rules to follow, but it's surprising how little remains there to talk about, once said rules have been rather judiciously applied.

## The end of an era

Before you say *"Hold on, sir! didn't you just preach about the rules, and then you follow up with this?"* - let me reassure you good sir, that the only reason I am even mentioning it, is due to the fact that both of them ended up dying at the opposite ends of the month of August. Which is a rather interesting, and curious coincidence if I might add, wouldn't you agree with your fellow *internaut*?

![iliescu_gorbachev](/media/2025/iliescu_gorbachev.png)

*"Come on now! Tell the truth and shame the devil"* - to paraphrase the words of my dear old friend, [André Linoge][legion]. I am taking my tinfoil hat off now, so you can rest easy. Pinkie promise!

## Brat

The production values of every single video dropped by [Ahoy][ahoy] (*Stuart Brown*) never seem to disappoint, and it's not any different this time around. There's not much else to add. The video speaks for itself.

{% include youtube.html id="pzq_4REOABk" %}

## Summer Band Camp

I kept getting updates via e-mail from [Bandcamp][bandcamp] about the new releases of a very talented, but highly underrated artist called [Sum][sumkilla]. I must have bumped into him around 2009 or thereabouts, and totally forgot about the fact that one could just sign-up for updates without actually having to create an account. Those were the days, huh?

Have a listen to two of my personal all-time favorite tracks, [Puddinhead][sumpuddinhead] and [35 cents][sum35cents] from his 2009 album entitled ["Sum and Belief are...The Lone Wolf"][sumthelonewolf].

<iframe style="border: 0; width: 100%; height: 120px;" src="https://bandcamp.com/EmbeddedPlayer/album=3876128231/size=large/bgcol=333333/linkcol=e99708/tracklist=false/artwork=small/track=2607661339/transparent=true/" seamless><a href="https://sumkilla.bandcamp.com/album/sum-and-belief-are-the-lone-wolf-2">Sum and Belief are...The Lone Wolf by Sum</a></iframe>

<iframe style="border: 0; width: 100%; height: 120px;" src="https://bandcamp.com/EmbeddedPlayer/album=3876128231/size=large/bgcol=333333/linkcol=e99708/tracklist=false/artwork=small/track=2881941093/transparent=true/" seamless><a href="https://sumkilla.bandcamp.com/album/sum-and-belief-are-the-lone-wolf-2">Sum and Belief are...The Lone Wolf by Sum</a></iframe>

So, this glorious month of August, I said to myself that it's time to finally bite the bullet and create an account; only to discover that I actually have bought some music already way back in 2011 or so that I totally forgot about. The wonders of life itself, or just the first signs of getting old? I am not quite sure to be perfectly honest.

Then, while randomly browsing around, I noticed that [Enigma][enigma] was also present on the site, so I had to reach to my wallet and buy their pivotal [MCMXC a.D.][mcmxcad] album.

<iframe style="border: 0; width: 100%; height: 1076px;" src="https://bandcamp.com/EmbeddedPlayer/album=854346938/size=large/bgcol=333333/linkcol=e99708/transparent=true/" seamless><a href="https://enigmamusic.bandcamp.com/album/mcmxc-a-d">MCMXC a.D. by Enigma</a></iframe>

It feels pretty weird to buy download-able music in this day and age, when one can find and listen to pretty much everything straight up on YouTube. No fuss, no muss! Definitely gives off some ancient arcane and primordial ritual vibes.

I must apologize to all those who ended up being disappointed after seeing the title and realizing that I am not going to talk about [American Pie Presents: Band Camp][americanpiebandcamp]. Sorry, not sorry!

## Lua 5.5.0-beta

The beta version of Lua 5.5.0 dropped at the end of June, then it somehow managed to slip through the cracks, and I didn't notice it. I know that it's not the best excuse in the world, especially since it's not like I had the power of the sun in the palm of my hand or anything of the sort.

Here is a short list of some of the major or [important changes][lua5changes] since the latest stable release of Lua 5.4.

- declarations for global variables
- for-loop variables are read only
- floats are printed in decimal with enough digits to be read back correctly.
- more levels for constructors
- table.create
- utf8.offset returns also final position of character
- external strings (that use memory not managed by Lua)
- new functions luaL_openselectedlibs and luaL_makeseed
- major collections done incrementally
- more compact arrays (large arrays use about 60% less memory)
- lua.c loads 'readline' dynamically
- static (fixed) binaries (when loading a binary chunk in memory, Lua can reuse its original memory in some of the internal structures)
- dump and undump reuse all strings
- auxiliary buffer reuses buffer when it creates final string

The thing that really caught my eye from the list of changes was the introduction of so called *external strings*, which are facilitated by the new [lua_pushexternalstring][lua_pushexternalstring] function part of the Lua C API.

>### `lua_pushexternalstring`
>
>[-0, +1, *m*]
>
>```c
>const char *(lua_pushexternalstring) (
>	lua_State *L,
>	const char *s,
>	size_t len,
>	lua_Alloc falloc,
>	void *ud
>);
>```
>
>Creates an *external string*, that is, a string that uses memory not managed by Lua. The pointer `s` points to the external buffer holding the string content, and `len` is the length of the string. The string should have a zero at its end, that is, the condition `s[len] == '\0'` should hold. As with any string in Lua, the length must fit in a Lua integer.
>
>If `falloc` is different from `NULL`, that function will be called by Lua when the external buffer is no longer needed. The contents of the buffer should not change before this call. The function will be called with the given `ud`, the string `s` as the block, the length plus one (to account for the ending zero) as the old size, and 0 as the new size.
>
>Lua always internalizes strings with lengths up to 40 characters. So, for strings in that range, this function will immediately internalize the string and call `falloc` to free the buffer.
>
>Even when using an external buffer, Lua still has to allocate a header for the string. In case of a memory-allocation error, Lua will call `falloc` before raising the error.

Alas, the devil is in the details as per usual, and I became way less excited once I took the time to read the proverbial *fine print*. I am referring to this bit in particular:

> Lua always internalizes strings with lengths up to 40 characters. So, for strings in that range, this function will immediately internalize the string and call `falloc` to free the buffer.

I fully understand the reasons of why this was done this way, but it's a bummer because this little detail that helps with consistency makes the whole feature less appealing, and rather unpredictable to use if I might add.

Would have loved to be able to push a C string without any additional overhead, and without it being interned. Even so, this should come very handy, and avoid a lot of the rather unnecessary string copying when passing around constant strings from C to Lua.

## Stutter Engine

Referring to [Unreal Engine][ue] as *stutter engine* is neither a new nor a hip thing to do anymore, but just as old wounds heal slow, the drama around micro-stuttering got ignited again this month, and it culminated in some well coordinated review bombing of certain games powered by UE.

It has gotten to the point where [Tim Sweeney][timsweeney] decided it was time to finally [chime in][pcgamerue]. *And, no, he's not the daddy of a certain Sydney! Very sorry to disappoint you twice in a single post no less!*

All this brought back memories from when this was happening to Unity way back in its relative early days. The damage from which Unity never really managed to fully recover, and some remnants of that energy persist to this day, although they the reverberations are way too low in order to be felt in any tangible way anymore.

Okay, so where is the stutter coming from? Mainly from ad-hoc mid-frame shader (re)-compilation. Unsuspecting gamers will simply file this under the umbrella term of *lagging*, which encompass everything from perceived drops in frames per second to actual noticeable delays to networking issues.

I said this before many times, unless you happen to be in the business of Triple A gaming, just roll your own tech. Not only that you'll sleep better at night, but your customers (gamers) will be happier and thank you for it.

Do you think that [No Man's Sky][nomanssky] could have been turned around, had it been using an off the shelf *behemoth* engine like UE? I seriously doubt it to be honest, unless most of the critical parts of the engine would have been completely rewritten, which is what used to happen quite frequently in the early days of UE, way back when it was all closed source, and the license would set your wallet back with nothing short of a million green American dollars a pop.

## Python: The Documentary

The recent documentary about [Python][python], felt more like an attempt to rehabilitate the language after the  absolute travesty of a fiasco that was *Python 3*, rather than an actual documentary.

{% include youtube.html id="GfH4QL4VqJ0" %}

What makes it even more funny is the fact that just last year, I had to fix up some more deprecation warnings around strings yet again, after a certain totally well intentioned Python upgrade of course.

```diff
diff --git a/bash/bin/powerline.py b/bash/bin/powerline.py
index e1daa96..8e377e4 100755
--- a/bash/bin/powerline.py
+++ b/bash/bin/powerline.py
@@ -6,9 +6,9 @@ import subprocess
 import sys
 
 class Powerline:
-    ESC   = '\e'
-    LSQ   = '\['
-    RSQ   = '\]'
+    ESC   = r'\e'
+    LSQ   = r'\['
+    RSQ   = r'\]'
     RESET = LSQ + ESC + '[0m' + RSQ
     BG0   = '236'
     BG1   = '237'
@@ -102,7 +102,7 @@ class Powerline:
         if int(error) != 0:
             bg = self.PINK
 
-        self.append(' \$ ', None, bg)
+        self.append(r' \$ ', None, bg)
 
 if __name__ == '__main__':
     p = Powerline()
```

Which means that very likely strings are still not totally cooked? Will they ever be? Please, don't answer that, as it was nothing more than a rhetorical question.

## Time Travel

What would you say if I came and told you that Time Travel is not only real, but it's available at your very own fingertips today. Right now in fact! You'd probably assume that I've totally lost it, but it's all true.

All you have to do is to create an account on the Butterfly app (*Bluesky*), and you'll be transported straight back in time to late 2022, pre-acquisition of Twitter. It's all frozen in time. The same faces, the same voices, the very same talking points, still there suspended in time.

Gives me the *heebie-jeebies*, and creeps me out every single time I visit. I am more and more tempted  to fund some anthropologists. It would all sure make a hell of a good paper in the end, considering that this is a unique moment in time, which has never been the case ever before.

## X Cancel

As a not so random segue from the previous topic, I stumbled upon this interesting thing for the lack of a better word called [xcancel.com][xcancel.com]. What is it?

> XCancel is an instance of Nitter.
>
> Nitter is a free and open source alternative Twitter front-end focused on privacy and performance. The source is available on GitHub at [https://github.com/zedeus/nitter](https://github.com/zedeus/nitter).
>
> - No JavaScript or ads
> - All requests go through the backend, client never talks to Twitter
> - Prevents Twitter from tracking your IP or JavaScript fingerprint
> - Uses Twitter's unofficial API (no developer account required)
> - Lightweight (for [@nim_lang](https://xcancel.com/nim_lang), 60KB vs 784KB from twitter.com)
> - RSS feeds
> - Themes
> - Mobile support (responsive design)
> - AGPLv3 licensed, no proprietary instances permitted

One can never be too prepared for what one might encounter in the side-lines of the eternal information super-highway. Blessed be his ways!

## Omarchy

The Jesus of Denmark, more colloquially known as [DHH][dhh], has been proselytizing to his flock on X about [Omarchy][omarchy], and [Omakub][omakub] for quite some time now, and it felt like the *movement* has reached critical mass this month, only being interrupted by Elon's frantic posting spree about image generation for a rather brief period of time, which sadly didn't end up culminating in a similar viral event to OpenAI's [Studio Ghibli][ghibli] craze of yesteryear.

All this has been getting on the nerves of people, while others were just simply annoyed by it. Then, it came time for the screenshot showing the payout from X, which simply amounted to twisting the dagger in a typical DHH fashion.

![payout](/media/2025/payout.png)

Is this the year of the Linux desktop at last? I don't think so. I am saying that as someone who has been running a completely custom setup, and have been contemplating automating things beyond managing my `.dotfiles` with source control, which greatly reduces the amount of time I have to spend after a fresh install.

In order for Linux to ever be successful on the desktop, two critical things would need to happen first. With the first being the fact that all hardware vendors would need to start threating it as a first class citizen, and then all the so called critical productivity applications that have been entrenched in the Windows and/or Apple ecosystems would have to be ported one to one. No, half-baked or even half-decent alternatives or ports simply won't cut it.

In other words, the more things change, the more they stay the same. The two things that I mentioned were true in the 90s, in the early 2000s, and they are true today in 2025.

[Valve][valve] has found this out the hard way. Which is why they pivoted, and disposed with the need for porting the games altogether by investing into their very own [Wine][wine] fork called [Proton][proton].

I still wonder to this day if Microsoft regrets not crushing Wine while it was still in its infancy way back when, considering that if it would ever reach true-parity where one could run let's say any of the Adobe or Autodesk products without too much fuss, it could definitely cause some serious ripples for Windows.

## Alien: Earth

I tried not to hype this one up too much in my retrospective of the month of June, as I didn't want to just set myself up for a disappointment of epic proportion, like so many times before.

{% include youtube.html id="FqIi3N9dusk" %}

Now that it's here, and I watched a few episodes, my opinion osculates somewhere in between the not good, yet not terrible territory; I say that as someone who liked both [Aliens][aliens] and [Alien 3][alien3].

The visuals and the world itself are amazing, but the rest feels like a rather odd spiritual successor to [Alien: Resurrection][alienresurrection], more than anything else.

## Stronghold Crusader: Definitive Edition

It has sold over `300_000` copies since its release last month; wanted to put that out there, just in case there were any *naysayers* lurking in the shadows around here.

{% include youtube.html id="Yn98HHTPl4k" %}

I am still of the opinion that this definitive edition should be regarded as the *quintessential cash-cow*, and kept alive with regular content drops way beyond of what has been revealed to be planned already. This game, simply put has no actual shelf-life, this much should be pretty clear to everybody by now.

## A Difficult Game About Climbing: Chapter 2

![new_map_exe](/media/2025/new_map_exe.png)

In a rather unexpected turn of events, [Mr. Ponty Pants][pontypants] has dropped a teaser trailer first, and then subsequently released an expansion for [A Difficult Game About Climbing][adgac].

{% include youtube.html id="adiYSWYntfo" %}

The [expansion][new_map_exe] comes in the form of a brand new map, and it's free.

{% include youtube.html id="2ZQBo5bR1B0" %}

I am sure that some people might be arguing whether it would have been better or made more sense to release it as a paid DLC, and charge let's say *$3.99* for it.

Personally, I am of the opinion that releasing it for free, and giving a special 25% off promotion for a limited time was probably the correct choice, given the nature of the game. It's a *rage game* after all, which has its own very special and selective niche audience.

## You can just do things

![courage](/media/2025/courage.png)

There's a little piece of an anecdote in the never-ending folklore of the information super-hightway about the curious fact that anybody who has been programming for a non-trivial amount of time, will feel some sort of an unconscious and almost primordial urge at least once that compels them want to write a *programming language*, a *database* or an *operating system*.

Now, I'd add a couple of more to that meager list, namely: text editor, media player, image editor, 3D modeler, physics engine, debugger, web server, codec (encoder/decoder/compressor/decompressor), and last but not least an *emulator* of some description.

This made me think about how many could I check off from this rather tedious laundry list.

## V-SaaS

What is *V-Saas*, exactly? It's just what I like to call *Vibe-Software-as-a-Service*. Now, look here, there has been a tsunami of so called *"Look at me, I am making $$$ ARR with my so-and-so SaaS app! Go buy my course about how I did it!"*.

If I had a dollar every single time I've one of these these "convert any video online" type services, which were nothing more than a glorified wrapper over [ffmpeg][ffmpeg], I'd be able to fund the development of [ffmpeg][ffmpeg] until the next millennium.

The advent of vibe coding exacerbated this phenomenon many fold, which is not surprising at all. That being said, one of my toxic traits has been to poke around these so called *"products"*, and watch them break in every imaginable and unimaginable way.

Every single time I see a never ending progress bar, I just imagine that there's probably a zombie process running in there eating up all the CPU time of the server. More than likely launched directly with something like `system(...)`, without sanitizing any of the arguments, and with no way to cancel it in a graceful manner if it has been running for way too long.

Alright, why am I talking about all this? Well, if you paid a little attention to the images in this post, you might have noticed that they look extra sharp to the point of having a rather uncanny feel to them.

If you picked up on all of that, then hats off to you. I confess that I've used [IMGUpscaler][imgupscaler] to resize and sharpen them. I feel so dirty right now, that you wouldn't believe!

![imgupscaler](/media/2025/imgupscaler.png)

This is not a sponsored post, and I am in no way affiliated with them. it should also go without saying that you should probably avoid uploading anything even close to personal to *services* like these, regardless of what is being stated in their terms of use and privacy policies.

That said it's probably one of the better ones that you can find in this particular category. The million dollar question of course is whether it has been *vibe-coded or not*. That is the question, isn't it?

## Monthly Dad Joke

> **Q:** Why did the tablet hit the pool party at the end of August?
>
> **A:**  It wanted to make a splash before summer got "disconnected"!

[sumkilla]: https://sumkilla.bandcamp.com/
[sumpuddinhead]: https://sumkilla.bandcamp.com/track/puddinhead
[sum35cents]: https://sumkilla.bandcamp.com/track/35-cents
[sumthelonewolf]: https://sumkilla.bandcamp.com/album/sum-and-belief-are-the-lone-wolf-2
[enigma]: https://en.wikipedia.org/wiki/Enigma_(German_band)
[mcmxcad]: https://en.wikipedia.org/wiki/MCMXC_a.D.
[americanpiebandcamp]: https://en.wikipedia.org/wiki/American_Pie_Presents:_Band_Camp
[bandcamp]: https://bandcamp.com
[indiansummer]: https://en.wikipedia.org/wiki/Indian_summer
[kinoleto]: https://en.wikipedia.org/wiki/Konchitsya_leto
[legion]: https://villains.fandom.com/wiki/Andr%C3%A9_Linoge
[lua5changes]: https://www.lua.org/work/doc/readme.html#changes
[lua_pushexternalstring]: https://www.lua.org/work/doc/manual.html#lua_pushexternalstring
[nomanssky]: https://en.wikipedia.org/wiki/No_Man%27s_Sky
[timsweeney]: https://en.wikipedia.org/wiki/Tim_Sweeney
[pcgamerue]: https://www.pcgamer.com/hardware/epics-ceo-tim-sweeney-wades-in-on-the-ue-performance-debate-the-primary-reason-unreal-engine-5-based-games-dont-run-smoothly-on-certain-pcs-or-gpus-is-the-development-process/
[ahoy]: https://www.youtube.com/@XboxAhoy
[ghibli]: https://en.wikipedia.org/wiki/Studio_Ghibli
[dhh]: https://en.wikipedia.org/wiki/David_Heinemeier_Hansson
[omakub]: https://omakub.org/
[omarchy]: https://omarchy.org/
[aliens]: https://en.wikipedia.org/wiki/Aliens_(film)
[alien3]: https://en.wikipedia.org/wiki/Alien_3
[alienresurrection]: https://en.wikipedia.org/wiki/Alien_Resurrection
[adgac]: https://store.steampowered.com/app/2497920/A_Difficult_Game_About_Climbing/
[new_map_exe]: https://store.steampowered.com/news/app/2497920?emclan=103582791474323224&amp;emgid=509589459369460023
[pontypants]: https://www.youtube.com/@Pontypants
[ffmpeg]: https://en.wikipedia.org/wiki/FFmpeg
[imgupscaler]: https://imgupscaler.ai/
[valve]: https://www.valvesoftware.com/en/
[wine]: https://en.wikipedia.org/wiki/Wine_(software)
[proton]: https://en.wikipedia.org/wiki/Proton_(software)
[python]: https://en.wikipedia.org/wiki/Python_(programming_language)
[xcancel.com]: https://xcancel.com/ID_AA_Carmack/status/1961172409920491849
