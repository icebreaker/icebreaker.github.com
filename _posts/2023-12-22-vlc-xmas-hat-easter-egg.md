---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2023
title: The VLC Xmas Hat Easter Egg
description: The infamous easter egg hunter strikes again.
image: /media/2023/vlcxmas512.png
propaganda: 99
---

The VLC Xmas Hat Easter Egg
=========================

As a certified easter egg hunter, I pride myself with discovering the [llama snake][llamasnake] inside the modern Bento Skin of [Winamp 5][winamp], all the way back in late 2007 or thereabouts. While I can't be 100% certain that I was the first person that ended up discovering it, the chances are pretty damn high. I do remember searching around the information super-highway at the time and finding nothing about it. My [google-fu][googlefu] was always top notch. Trust me on this!

Now, the so called Xmas hat easter egg in VLC is more up in your face so to speak. There's no special key combination to hold or special icons to click in some obscure About dialog box or a place no user dares to wander.

In other words, I am sure you noticed how the VLC icon changes to one with a tiny Xmas hat. This happens at a certain point during the month of December and I could never put my finger on the exact day it happens.

As one might expect, not everybody was super thrilled about this transpiring as you can see for yourself in this beautiful [thread][thread] over the official VLC forums.

So, I thought that it's about high time to take a look at the source code and figure it all out. The benefits  of VLC being an open source project is that I don't even have to whip out my reverse engineering toolkit and disassemble the binary. It's all out there in the open for all to see. Isn't open source wonderful? I think so to.

If we awe a gander inside `modules/gui/qt/qt.cpp`, we can locate the following block of code.

```c
if(QDate::currentDate().dayOfYear() >= QT_XMAS_JOKE_DAY &&
	var_InheritBool(p_intf, "qt-icon-change"))
{
	app.setWindowIcon(
		QIcon::fromTheme(
			"vlc-xmas",
			QIcon(":/logo/vlc128-xmas.png")
		)
	);
}
else
{
	app.setWindowIcon(
		QIcon::fromTheme(
			"vlc",
			QIcon(":/logo/vlc256.png")
		)
	);
}
```

The elephant in the room is value of `QT_XMAS_JOKE_DAY`, which of course we can find conveniently   defined in `modules/gui/qt/qt.hpp` as one would expect.

```c
/*
	After this day of the year, the usual VLC cone is replaced by another cone
	wearing a Father Xmas hat.
	
	Note this icon doesn't represent an endorsment of Coca-Cola company.
*/
#define QT_XMAS_JOKE_DAY 354 
```

It's all revealed. In other words if the current day of the year is greater or equal to `354` the the Xmas specific icon is used.

There are a couple of other spots where there is a similar conditional check, like setting up the system tray icon for instance.

Yet another curious Xmas related thingamajig that I stumbled upon in the source code while taking a look is some animated snowflake effect.

Spotted this naughty boy inside `modules/gui/qt/components/interface_widgets.cpp` while looking for instances where `QT_XMAS_JOKE_DAY` was being referenced.

```c
if(QDate::currentDate().dayOfYear() >= QT_XMAS_JOKE_DAY
    && var_InheritBool( p_intf, "qt-icon-change"))
{    
	bgWidget = new EasterEggBackgroundWidget(p_intf);
	CONNECT(this, kc_pressed(), bgWidget, animate());                          }
else
{
	bgWidget = new BackgroundWidget(p_intf);
}
```

By looking at the code we can see that this is activated by a signal called `kc_pressed()`, which is hooked up to the `animate()` slot of the `EasterEggBackgroundWidget`.

Don't get too discouraged by all this Qt specific techno-prep-school-palabra. These are just rather fancy words for events and event handlers, nothing less and nothing more.

The next step was to track down where the `kc_pressed()` signal was being emitted from, which we can find inside `modules/gui/qt/main_interface.cpp`, conveniently tucked away in the key press event handler.

```c
void MainInterface::keyPressEvent(QKeyEvent *e) 
{
    handleKeyPress(e); 

    /* easter eggs sequence handling */
    if(e->key() == kc[i_kc_offset])
        i_kc_offset++;
    else 
        i_kc_offset = 0; 

    if(i_kc_offset == (sizeof(kc) / sizeof(Qt::Key))) 
    {   
        i_kc_offset = 0; 
        emit kc_pressed();      
    }
}
```

It looks like it's tracking a sequence of key presses, and if they all match, then finally the `kc_pressed()` signal is emitted and the sequence is reset.

The `kc` static array containing the key codes is defined within the same file and it looks like this.

```c
const Qt::Key MainInterface::kc[10] =
{
    Qt::Key_Up, Qt::Key_Up,
    Qt::Key_Down, Qt::Key_Down,
    Qt::Key_Left, Qt::Key_Right, Qt::Key_Left, Qt::Key_Right,
    Qt::Key_B, Qt::Key_A
};
```

Do you recognize the sequence? It's the infamous sequence known as the [Konami code][konamicode].

![vlcsnow](/media/2023/vlcsnow.gif)

Is there anything else? Glad you asked. There is one more easter egg, which is not Xmas related, but just as recognizable, perhaps even more so.

If we take another careful look inside `modules/gui/qt/components/interface_widgets.cpp`, we stumble upon this piece of pure concentrated goodness on steroids or Dr. Pepper, whichever floats your boat, there are no judgments being passed around here, as this is a consecrated safe place.

```c
void BackgroundWidget::titleUpdated(const QString& title)
{
    /* don't ask */
    if(var_InheritBool(p_intf, "qt-icon-change") && !title.isEmpty())
    {    
        int i_pos = title.indexOf(
            "Ki" /* Bps */ "ll",
            0,
            Qt::CaseInsensitive
        );
        if(i_pos != -1 &&
           i_pos + 5 == title.indexOf("Bi" /* directional */ "ll",
                                      i_pos, Qt::CaseInsensitive))
                updateDefaultArt(":/logo/vlc128-kb.png");
        else if(QDate::currentDate().dayOfYear() >= QT_XMAS_JOKE_DAY)    
				updateDefaultArt( ":/logo/vlc128-xmas.png" );
        else 
				updateDefaultArt( ":/logo/vlc128.png" );
    }    
}
```

This piece of code simply checks if the title of the currently plyaing media starts with `Kill Bill` and if it does then the default background art is changed to a `Kill Bill` themed one, which you can see in all its glory below. 

![vlckillbill](/media/2023/vlckillbill.png)

It's important to note that this only takes effect if the media doesn't have its own background art embedded within it, and the easiest way to trigger the `titleUpdated` event is skip to a few seconds before the end of the media and then let it finish.

That is all. I hope this was a fun little pre-Xmas excursion in the world of easter eggs, which by the way are harder and harder to come by in our day and age. So sad, I know!

And, kudos to all the contributors and volunteers keeping VLC alive and kicking. Truly a thankless job!

[googlefu]: https://en.wiktionary.org/wiki/Google-fu
[winamp]: https://en.wikipedia.org/wiki/Winamp
[llamasnake]: https://eeggs.com/items/53813.html
[thread]: https://forum.videolan.org/viewtopic.php?t=96539
[konamicode]: https://en.wikipedia.org/wiki/Konami_Code
