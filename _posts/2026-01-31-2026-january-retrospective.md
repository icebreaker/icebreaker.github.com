---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2026
title: 2026 January Retrospective
propaganda: sh
music: xXwZSMEuFxI
tags: retrospective
---

2026 January Retrospective
=========================

The year started as good as [Return to SIlent Hill][returntosh] ended up doing at the box office.

{% include youtube.html id="fTPHkslPCr0" %}

It's not all doom and gloom though, I stumbled upon this funny little nugget on mighty Wokopedia, that made me smile. That must count for something, right?

>The film had its release on January 23, 2026 in the United States had grossed $2 million in the United States on opening day. It is projected to gross below *[Avatar: Fire and Ash](https://en.wikipedia.org/wiki/Avatar:_Fire_and_Ash)* and another fellow newcomer *[Mercy](https://en.wikipedia.org/wiki/Mercy_(2026_film))*, with most theaters closing down during the weekend due to the [January 2026 North American winter storm](https://en.wikipedia.org/wiki/January_2026_North_American_winter_storm).

I might return with a little blurb after I had the chance to watch it; not going to be paying too much attention to ratings or the critics for that matter; and neither should you, if you ask my honest opinion.

Oh, by the way, I forgot to tell you, that I've already failed one of my *promises* for 2026 as I didn't end up posting at least once every week of the month. This is precisely the reason why I never really did proper New Year's resolutions of any description.

## Layoffs

![amazon](/media/2026/amazon.png)

In other news, we have yet another batch of `16_000` jobs, [cut][amazonlayoffs] by Amazon. I said this last year, it's going to be a bloodbath out there for many many years to come. It's probably fair to claim that millenials will never know any sort of tangible *job security* within their lifetimes (*whatever that means*); the effects of which are probably going to be absolutely devastating in the long run.

One thing is certain though, the mirage of the *parallel economy* based purely on graphs, numbers, and excelsheets is starting to show some rather serious cracks yet again, which is never a good sign.

## Hocus Focus

![hf](/media/2026/hf.png)

I consider the people behind [Stuck In Attic][stuckinattic], to be dear good friends of mine, therefore I would have been remiss, if I didn't mention their *new cozy game* that they just happened to announce at the beginning of January; the very aptly named [Hocus Focus][hocusfocus].

 {% include youtube.html id="RqgFl4b6Xoo" %}

I am sure that they wouldn't mind if it ended up selling `500_000` units or more, considering that there seems to be a fairly vibrant market for cozy games out there at the moment.

The SEO needs some more time to settle down, because right now, when one does search for the name, there's a high chance that one might stumble upon things like essential oils instead. The ways of the great information super-highway are very mysterious indeed.

## Reloaded 2: Retro Gaming Zine

![rld_zine_2](/media/2026/rld_zine_2.png)

[Reloaded 2][reloaded2] came out in the middle of December last year, but somehow it managed to fall through the cracks, and didn't make it into my last retrospective.

I really wanted to mention it, considering that it focuses on the best RTS games of 1997. Said, this before, and I'll say it again, I am really super glad that people are still releasing these zines. They are truly a labor of love in every sense of the word.

## NVIDIA

I was almost ready to forgive [Jensen][jensenhuang] for the absolute disgrace that went down in the history books as the [Geforce4 MX 440][gf4mx]. In other words, selling a slightly beefed up GF2 as an entry level GF4 was an dick marketing move, no matter how you slice or dice it.

Only to wake up in the year 2026, and find out that decade old NVIDIA GPUs have been deprecated, and now are pretty much unsupported, unless one wants to spend their precious life patching the kernel module for each new kernel version out there.

As someone who has been there, and most importantly have done that, let me tell you that it's not a journey you want to embark on; which in turn means that if you happen to have one of those affected GPUs, then you will be pretty much out of luck, and forced to use abominations like [nouveau][nouveau].

I can fully understand that supporting something as ancient as let's say the [NVIDIA Ion][nvidiaion] is totally out of the question, but something that is barely a decade old or thereabouts, well that's a completely different story in my honest opinion.

Speaking of the [NVIDIA Ion][nvidiaion], here's a patch that I cobbled together way back in late 2020, in order to make the `340.108` kernel module compile successfully on the `4.8` kernel.

```diff
--- kernel/uvm/nvidia_uvm_lite.c	2019-12-12 00:04:24.000000000 +0200
+++ kernel/uvm/nvidia_uvm_lite.c	2020-11-19 02:15:59.338918014 +0200
@@ -820,7 +820,7 @@
 }
 
 #if defined(NV_VM_OPERATIONS_STRUCT_HAS_FAULT)
-int _fault(struct vm_area_struct *vma, struct vm_fault *vmf)
+vm_fault_t _fault(struct vm_fault *vmf)
 {
 #if defined(NV_VM_FAULT_HAS_ADDRESS)
     unsigned long vaddr = vmf->address;
@@ -828,13 +828,14 @@
     unsigned long vaddr = (unsigned long)vmf->virtual_address;
 #endif
     struct page *page = NULL;
+    struct vm_area_struct *vma = vmf->vma;
     int retval;
 
     retval = _fault_common(vma, vaddr, &page, vmf->flags);
 
     vmf->page = page;
 
-    return retval;
+    return (__force vm_fault_t) retval;
 }
 
 #else
@@ -868,7 +869,7 @@
 // it's dealing with anonymous mapping (see handle_pte_fault).
 //
 #if defined(NV_VM_OPERATIONS_STRUCT_HAS_FAULT)
-int _sigbus_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
+vm_fault_t _sigbus_fault(struct vm_fault *vmf)
 {
     vmf->page = NULL;
     return VM_FAULT_SIGBUS;
```

Anyway, it's no point in crying over spilled milk, but what a shame nonetheless.

If you had the impression that this rant was going to be about [Jensen][jensenhuang] not caring about the *household variety gamers* anymore, then I am sure that you've been mighty disappointed. Sorry, not sorry!

## *Khajiit* has new wares, if you have coin!

The NVIDIA kernel module situation has forced me set condition one through the ship, and launch the alert vipers. I really didn't want to reach into the war-chest (reserves), given the current economic, and general situation in the world, but alas it was necessary.

I always buy ASUS, as they seem to be only general purpose hardware company out making products that just last, without breaking down soon after their warranty runs out.

![tuf](/media/2026/tuf.png)

The *upgrade* is better illustrated with numbers than words, so let me lay it all out in a table.

| Before                   | After                                            |
| ------------------------ | ------------------------------------------------ |
| 16GB RAM                 | 32GB RAM                                         |
| 4 cores + 8 threads      | 8 cores + 12 threads                             |
| 4GB dedicated NVIDIA GPU | integrated Intel iGPU + 6GB dedicated NVIDIA GPU |
| 250GB SSD + 1TB HDD      | 512GB SSD                                        |

The only thing that is kind of a downgrade is the 512 SSD, but I'll very likely get an external drive via USB-C to satiate my needs for judicious data hoarding.

I also intend to use this as an opportunity to clean-up, and perhaps also consolidate some of my ancient `.dotfiles`, which happens to be a thing that I really wanted to do for quite some time, but I always managed to find some reasonable excuse to put it off.

2026 is going to be the year of no excuses or half measures. You've heard it here first folks!

## Enshitification (Contd.)

If the nitroglycerin, sorry I meant to say the [glycin][glycin] wasn't bad enough in terms of absolutely bonkers regressions across the board, most of which haven't been addressed, and given the situation with GNOME and GTK very likely never be; then you'll be glad to find out that the global enshitification continues in full force.

This time around in [vim][vim]. It will be three years this *August* since [Bram][bram] has unexpectedly passed away, and just like I predicted, breaking changes are being introduced left and right, without anyone batting an eye.

How on earth, can the number of arguments be changed on a function that is part of the public API, and is known to be relied on by countless plugins out there?

```diff
" netrw#BrowseX: (implements "x") executes a special "viewer" script or
" program for the given filename; typically this means given their 
" extension. 0=local, 1=remote
-function netrw#BrowseX(fname,remote)
+function netrw#BrowseX(fname)
```

How difficult can be it for these people to understand that this is something you just don't do? Don't answer that, as this was a purely rhetorical question. Not really, but here we are!

The only explanation that I can come up with to explain this attitude is that people seem to be under the impression that coding is like cooking. In other words, something half-edible will come out in the end, no matter what you do. I am not so sure that I agree, but it's definitely a certain point of view.

![salmon](/media/2026/salmon.png) 

So, instead of reverting this change, what ended up happening instead is that all affected plugins came up with specific patches like this [one][vim-fugitive-patch] by [Tim Pope][tpope].

Never ever do this kids. Don't make a grown man cry. Pretty, please?

 {% include youtube.html id="lAkuJXGldrM" %}

## Monthly *"Coup de cœur"*

Instead of the monthly *"Dad Joke"*, I thought that I'd switch things up a little this year around, and present a monthly "Coup de cœur" from the demo scene instead.

This month, I picked one of my all time favorites from way back in 2000, called [VIP2][vip2] by Popsy Team.

{% include youtube.html id="ObtPizPFMbo" %}

Please enjoy the show, and don't forget to try the fish. Until next month, end of line!

[reloaded2]: https://gameloadedmuseum.wordpress.com/2025/12/15/reloaded-2/
[vip2]: https://www.pouet.net/prod.php?which=10
[returntosh]: https://en.wikipedia.org/wiki/Return_to_Silent_Hill
[stuckinattic]: https://linktr.ee/stuckinattic
[hocusfocus]: https://store.steampowered.com/app/4202710/Hocus_Focus/
[nvidiaion]: https://en.wikipedia.org/wiki/Nvidia_Ion
[nouveau]: https://en.wikipedia.org/wiki/Nouveau_(software)
[gf4mx]: https://www.techpowerup.com/gpu-specs/geforce4-mx-440.c781
[jensenhuang]: https://en.wikipedia.org/wiki/Jensen_Huang
[glycin]: https://gitlab.gnome.org/GNOME/glycin/-/issues/212
[vim]: https://github.com/vim/vim/issues/17794
[vim-fugitive-patch]: https://github.com/tpope/vim-fugitive/commit/d3e2b58dec75fc6012fecc82ce0d33a45ed0560e
[tpope]: https://tpo.pe/
[amazonlayoffs]: https://www.aboutamazon.com/news/company-news/amazon-layoffs-corporate-jan-2026
[bram]: https://en.wikipedia.org/wiki/Bram_Moolenaar
