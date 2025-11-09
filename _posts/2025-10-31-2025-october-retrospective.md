---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2025
title: 2025 October Retrospective
propaganda: starbuck
music: X_HBIm_8BOE
tags: retrospective
---

# 2025 October Retrospective

Octobers seem to alternate between elections and massive layoffs. Over **112,732** employees have been laid off by **218** companies so far in 2025, according to [Layoffs.fyi][layoffsfyi]. This number doesn't seem to include the recent [30,000][amazon30klayoffs] yet, as this was announced only a couple of days ago by [Amazon][amazon].

People are coming up with all sorts of outlandish theories around these layoffs, but they all fail to realize the simple fact that the recension hasn't even begun in earnest just yet. And, when it finally does, they are going to be in for a surprise. I have said this a couple of times before, but what is coming is going to make *2008-2009* look like just a *bad fever dream*. 

## Katee "Starbuck" Sackhoff

I totally wasn't expecting [Katee Sackhoff][kateesackhoff] to make an appearance on [JRE][jre]. It most definitely wasn't on my *2025 JRE bingo card*, especially since [Bill Murray][billmurray] popped up rather unexpectedly as well, earlier in the year.

{% include youtube.html id="TZu7jymfHrU" %}

Katee will always be [Starbuck][starbuck] to me. One of the many downsides of portaying such an iconic character so early in ones' acting career is that it's going to be very difficult for one to divorce themselves from said character later on. Which can be a blessing, and a curse at the same time, depending on how one looks at and deals with it.

For the younger generations out there, she's probably more [Amunet Black][amunetblack] or [Bo-Katan][bokatan].

### [Battlestar Galactica][bsg]

If I was given the task of summing up *Battlestar Galactica* in only three clips, these would be the ones that I'd pick without even flinching.

{% include youtube.html id="9VBTcDF1eVQ" %}

{% include youtube.html id="yifKIdajCRg" %}

{% include youtube.html id="pHUEYIE_MZA" %}

So say we all!

### [Riddick][riddick]

I feel like Riddick is a pretty underrated franchise all things considered, and it's definitely one of those, where I totally didn't expect Katee to show up.

{% include youtube.html id="iP3eFIOBU0k" %}

## Toasters

<img src="/media/2025/speakers.png" alt="speakers" class="invert-on-hover" />

While on the subject of [walking chrome toasters][toasters], it appears that in our particular case, they might turn out to be *walking gray speakers* instead. This was my rather cringe attempt at making a reference to [NEO][neo] by [1x][1x], of course.

{% include youtube.html id="LTYMWadOW7c" %}

I need to up my *shit-posting-meme-game*, that's for sure.

## The "AI" *browser wars*

Unless you have been living under a rock, you probably have heard about [ChatGPT Atlas][chatgptatlas] by [OpenAI][openai].

{% include youtube.html id="8UWKxJbjriY" %}

I have no desire to comment on the fact that it's just a [Chromium][chromium] fork. My qualms go deeper than that, and aren't directly related to this product in particular.

But, this is a larger subject that I am not ready to dive into just yet. It warrants a dedicated post of its own.

## Porting Marmota to GTK4

I took another stab at trying to port [marmota][marmota] to [GTK4][gtk4] this month, which was rather foolish of me to be perfectly, and totally honest.

What is the point of using GTK at all, when one has to start writing code for the underlying toolkit(s), which in this particular case happens to be [X11][x11], just to be able to center a bloody window, mind you.

```c
static void mrt_center_window(mrt_context_t *ctx)
{
#if GTK_CHECK_VERSION(4, 0, 0)
	int w, h;
	Display *xdisplay;
	Screen *screen;
	Window xwindow;
	GdkDisplay *display;

	if(!gtk_widget_get_realized(ctx->win))
		return;

	display = gdk_display_get_default();
	if(!GDK_IS_X11_DISPLAY(display))
		return;

	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    xdisplay = GDK_DISPLAY_XDISPLAY(display);
	if(xdisplay == NULL)
		return;

	screen = ScreenOfDisplay(xdisplay, 0);
	if(screen == NULL)
		return;

    xwindow = GDK_SURFACE_XID(gtk_native_get_surface(GTK_NATIVE(ctx->win)));
	#pragma GCC diagnostic pop

    gtk_window_get_default_size(GTK_WINDOW(ctx->win), &w, &h);

    XMoveWindow(
		xdisplay,
        xwindow,
        (screen->width  - w) >> 1,
        (screen->height - h) >> 1
    );
    XFlush(xdisplay);
#else
	gtk_window_set_position(
		GTK_WINDOW(ctx->win),
        GTK_WIN_POS_CENTER_ALWAYS
    );
#endif
}
```

Based on the fact that `GDK_SURFACE_XID` has been marked as deprecated, I think that it's fair so say that GTK is no longer a portable toolkit, but rather a toolkit that serves nothing but Wayland.

Now, as if all this wasn't bad enough already, setting the *icon of a window* has also been turned into an overengineered hot mess.

Can you imagine that in the year of 2025, one has to create special definition files and go through largely undocumented hoops in order to set the icon of a window?

```c
gtk_window_set_icon_name("terminal");
```

This is completely useless now, and does nothing or does the wrong thing on most configurations. Why even include this in the API at all?

While [GTK3][gtk3] is very likely going to be kept alive in some form or another for years to come, I personally see no reason to keep writing or using any software that relies on GTK at this point.

It remains to be seen if [Qt][qt] will start making the same *mistakes* in the near future. For the sake of the Linux desktop, I really hope not.

I am using all my will power in order to resist the urge of writing my own terminal emulator from scratch, one that relies on nothing more than X11, FreeType and OpenGL.

## Stronghold Crusader: DE - The Canary and The Trader DLC

I know, I know. I'll just leave this here. Enough said.

{% include youtube.html id="x8X1iH2vPc0" %}

## Megabonk

![megabonk](/media/2025/megabonk.png)

[Megabonk][megabonk] ended up bonking for most of the month of October. It seems to have sold over 2 million copies, according to the estimates provided by [Gamalytic][gamalytic].

I consistently seen [over 45,000 people][megabonkstats] playing it on Steam, which is pretty bonkers to say the least, especially after more than a month since its launch.

## BALL x PIT

![ballxpit](/media/2025/ballxpit.png)

[BALL x PIT][ballxpit] is a rather fresh, and interesting *rogue-lite* take on the classic [Breakout][breakout].

{% include youtube.html id="18pHUtXzF2w" %}

## Paged Out!

![pagedout](/media/2025/pagedout.png)

I always found it very weird that with the slow death of physical magazines, digital magazines seem to have almost completely died out as well, which never made sense to me.

Especially today, when PDF is ubiqutous, and can be consumed without having to through the pain of installing the mighty [Adobe Acrobat Reader][acreader]. It was probably included in more installers than any other piece of software ever.

Imagine my surprise, when I randomly stumbled upon [Paged Out!][pagedout], which have filled me with nostalgia for the times when I used to buy magazines with my pocket money on Friday afternoons, and then devour them *cover-to-cover* over the weekend.

And, then the bonus wallpapers that come with each issue are absolutely gorgeous. Total *chef's kiss*!

## eXoDOS

![exodos](/media/2025/exodos.png)

The whole [eXoDOS][exodos] project is most definitely treading on a very *thin gray line*, between the so called preservation of abandonware, and privacy.

As I am not a judge or a jury, I'll let you decide for yourself. But, I'll say this, the [manual][exodosmanual] itself screams of nothing more than an absolute passion project.

## Monthly Dad Joke

> **Q:** Why did Hercule Poirot refuse to bob for apples on Halloween?
>
> **A:** Because the little grey cells insisted: *“Mon ami, it is elementary, dunking one’s moustache in a bucket is simply a crime against symmetry!”*

[kateesackhoff]: https://en.wikipedia.org/wiki/Katee_Sackhoff
[starbuck]: https://en.wikipedia.org/wiki/Kara_Thrace
[exodos]: https://www.retro-exo.com/exodos.html
[exodosmanual]: https://www.retro-exo.com/eXoDOS%20Manual.pdf
[acreader]: https://en.wikipedia.org/wiki/Adobe_Acrobat
[pagedout]: https://pagedout.institute/
[layoffsfyi]: https://layoffs.fyi/
[amazon30klayoffs]: https://www.aboutamazon.com/news/company-news/amazon-workforce-reduction
[amazon]: https://amazon.com
[billmurray]: {{ "/2025/02/28/2025-february-retrospective/#bill-murray" | absolute_url }}

[jre]: https://en.wikipedia.org/wiki/The_Joe_Rogan_Experience
[amunetblack]: https://en.wikipedia.org/wiki/Blacksmith_(character)
[bokatan]: https://en.wikipedia.org/wiki/Bo-Katan_Kryze
[riddick]: https://en.wikipedia.org/wiki/Riddick_(film)
[bsg]: https://en.wikipedia.org/wiki/Battlestar_Galactica_(2004_TV_series)
[toasters]: https://en.wikipedia.org/wiki/Cylons
[neo]: https://www.1x.tech/neo
[1x]: https://www.1x.tech/
[chatgptatlas]: https://en.wikipedia.org/wiki/ChatGPT_Atlas
[openai]: https://en.wikipedia.org/wiki/OpenAI
[chromium]: https://en.wikipedia.org/wiki/Chromium_(web_browser)
[breakout]: https://en.wikipedia.org/wiki/Breakout_(video_game)
[ballxpit]: https://store.steampowered.com/app/2062430/BALL_x_PIT/
[megabonk]: https://store.steampowered.com/app/3405340/Megabonk/
[gamalytic]: https://gamalytic.com/game/3405340
[megabonkstats]: https://steamcharts.com/app/3405
[marmota]: https://github.com/icebreaker/marmota
[gtk4]: https://docs.gtk.org/gtk4/
[gtk3]: https://docs.gtk.org/gtk3/
[qt]: https://www.qt.io/
[x11]: https://ro.wikipedia.org/wiki/X_Window_System
