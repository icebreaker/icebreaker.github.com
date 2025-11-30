---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2025
title: 2025 November Retrospective
propaganda: st
music: wp43OdtAAkM
tags: retrospective
---

# 2025 November Retrospective

I find myself writing this up at the end of the month once more, while getting ready for my usual month long sabbatical. The weeks turned into months, very fast this year, perhaps faster than usual as cliché as might sound. Luckily for you, I decided to leave my more juicy musings about everything that has transpired during the course of this year, for my last retrospective. Very surprising, I know!

## Stranger Things

I am more than sure, that you might have guessed the fact that I'm going to have a word or two say about the [last season][st5] of [Stranger Things][st] franchise.

{% include youtube.html id="PssKpzB0Ah0" %}

Naturally, I binged the first four episodes in one sitting, as it is customary for any hardened specimen of the *homo-netflixoidus* hominid sub-species. Is it any good? Well, I am happy to report that it is still very much [Stranger Things][st], for what it's worth.

Be that as it may, releasing a show in this format, with half of the season coming out in the month of December no less, and then not making it *christmas-holiday-themed* is a major a blunder in my   opinion.

Another thing that has been swirling around in my head for quite some time now, is the fact that [Kingdom: Eighties][kingdomeighties], would have been an absolutely fantastic tie-in for the whole franchise. It got all the ingredients, and replacing [the greed][thegreed] with some creatures from [the upside down][theupsidedown], would have been such a natural fit.

{% include youtube.html id="CyRava_eWX8" %}

Such a missed opportunity. Oh well!

## Black Phone

I really don't know, how I managed to totally miss the original [Black Phone][blackphone] when it initially came out.

{% include youtube.html id="v0kqkRZHqk4" %}
{% include youtube.html id="DdR-gzFZoDk" %}
{% include youtube.html id="3eGP6im8AZA" %}

Think of it as [Freddy Krueger][freedy], meeting up with [Candyman][candyman], and [Jason Voorhees][jason] among others at a house-party organized by none other than [Bughuul][sinister]. If all that didn't raise your interest one bit, then I don't know what else I could possibly say that would.

## Stronghold Crusader: DE

I am always amused by how people still don't seem to get how important it is to make sure that a game is mod-able on release.

{% include youtube.html id="zB8o6him_i8" %}

Just look at the amount of content the community has conjured up in just a few months after release. There is some sort of a deep lesson in there somewhere, for the people who always seem to cry out in the end: *"Mr. President, give us back our 30%! Now!"*.

## Epic & Unity *partnership*

If you were sorta-kinda running low on Unity drama, then the [Epic & Unity partnership][epicunitypartnership] announcement should have replenished your supply to last just a little while longer.

{% include youtube.html id="eDdWSJ5A04E" %}

I know that people must be tired of me repeating this *ad nauseam* at this point, but seriously folks, just roll your own tech. It's the year 2025 for crying out loud. You don't need Unity, even if you think you do.

## s&box

In a rather unexpected turn of events, [s&box][s&box] became [open source][s&boxos] this month, and is now available under the very permissive [MIT license][mitlicense]. This release doesn't include [Source 2][source2] of course, which is the actual *engine* that powers it all under the hood.

One particular thing that I was curious about, when it came to [s&box][s&box] for the longest time, was the way they implemented their own *custom window decorations*. I knew that they were using [Qt][qt], but I wasn't sure if they simply went it by using the available controls (*widgets*), or if they have done it like we used to do it way back in the good old days, by the means of so called *owner drawn* controls.

![sbox](/media/2025/sbox.png)

It didn't take an awfully long time after peeking under the hood in order to discover the absolute truth inside a very aptly named source file called [engine/Sandbox.Tools/Qt/Window/TitleBar.cs][titlebar.cs].

```cs
using System;

namespace Editor;

internal class TitleBar : Widget
{
    private Widget Window { get; init; }
    private Button IconWidget { get; set; }
    private Label TitleLabel { get; set; }
    private Widget Grabber { get; set; }
    private WindowControlButton MinimizeButton { get; set; }
    private WindowControlButton MaximizeButton { get; set; }
    private WindowControlButton CloseButton { get; set; }
    public TitleBarButtons TitleBarButtons { get; init; }

    public MenuBar MenuBar { get; private init; }

    private const int IconSize = 18; 

    public Pixmap IconPixmap
    {   
        set 
        {   
            IconWidget.SetIcon( value.Resize( IconSize ) );
            Update();
        }   
    }
    
    // ...
}
```

These widgets are then explicitly passed back to the so called *native frameless main window* in C++ land.

```csharp
internal void SetTitleBarWidgets(Native.CFramelessMainWindow nativeWindow)
{   
	nativeWindow.SetTitleBarWidgets(
		IconWidget._button,
		TitleLabel._label,
		MenuBar._menubar,
		Grabber._widget,
		MinimizeButton._widget,
		MaximizeButton._widget,
		CloseButton._widget
	);  
} 
```

The `grabber` is quite an interesting choice of name for a member variable, but this is a safe place where we don't judge anything or anyone for that matter.

While we are on the subject of custom title bars, I would be remiss, if I didn't mention the [Decima Engine][decimaengine], which seems to be doing something similar, as you can see for yourself in the screenshot below.

![decimaeditor](/media/2025/decimaeditor.png)

The only difference here is that it puts the *tab bar*, rather than the *menu bar* *inline* inside the *title bar*. This makes sense to me, if the *menu bar* is very *context specific*, and each tab is almost like a self-contained tool or sub-tool in of itself.

Those who are so inclined, and are interested in the more *nitty-gritty* details can find a fairly detailed [presentation][decimaui] about how the actual user interface is being rendered, and so on.

{% include youtube.html id="U_MnhTuT_l8" %}

## The G* you leave behind

Another upgrade, yet another awful regression in something that starts with the letter G. What is it, this time around? It's [gdk-pixbuf][gdk-pixbuf], thank you very much for asking. It's so kind, and considerate of you to check in at such a difficult time.

I really need to start the process of *de-g-ification* soonish, and simply get rid or replace every piece of software that relies on anything that is somehow related to [GTK][gtk] and [GNOME][gnome].

This is an absolute disgrace, how on earth can you introduce a major regression, and then subsequently refuse to address it for several minor and patch versions? The patients are truly running the asylum now, there's no going back from here.

## Winter *OTK* Games Expo

{% include youtube.html id="4AFyUsCWCJc" %}

## Monthly Dad Joke

> **Q:** Why don't skeletons ever say *"May I meet you?"*.
>
> **A:** Because, they are *dead-icated* to being alone.

[st5]: https://en.wikipedia.org/wiki/Stranger_Things_season_5
[st]: https://en.wikipedia.org/wiki/Stranger_Things
[kingdomeighties]: https://kingdomthegame.fandom.com/wiki/Kingdom_Eighties
[thegreed]: https://kingdomthegame.fandom.com/wiki/Category:Greed
[theupsidedown]: https://strangerthings.fandom.com/wiki/The_Upside_Down
[blackphone]: https://en.wikipedia.org/wiki/The_Black_Phone
[candyman]: https://en.wikipedia.org/wiki/Candyman_(character)
[jason]: https://en.wikipedia.org/wiki/Jason_Voorhees
[freedy]: https://en.wikipedia.org/wiki/Freddy_Krueger
[sinister]: https://en.wikipedia.org/wiki/Sinister_(film)
[epicunitypartnership]: https://unity.com/news/unity-and-epic-games-together-advance-open-interoperable-future-video-gaming
[s&box]: https://sbox.game/
[s&boxos]: https://sbox.game/news/update-25-11-26
[mitlicense]: https://en.wikipedia.org/wiki/MIT_License
[source2]: https://en.wikipedia.org/wiki/Source_2
[qt]: https://qt.io/
[titlebar.cs]: https://github.com/Facepunch/sbox-public/blob/master/engine/Sandbox.Tools/Qt/Window/TitleBar.cs
[decimaengine]: https://en.wikipedia.org/wiki/Decima_(game_engine)
[decimaui]: https://www.guerrilla-games.com/read/uipainter-tile-based-ui-rendering-in-one-draw-call
[gdk-pixbuf]: https://docs.gtk.org/gdk-pixbuf/
[gtk]: https://www.gtk.org/
[gnome]: https://www.gnome.org/
