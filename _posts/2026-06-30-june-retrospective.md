---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2026/
title: 2026 June Retrospective
propaganda: kinoleto
music: iOvYGQtFBNM
tags: retrospective
---

2026 June Retrospective
=========================

The first month of summer all gone; *Poof!*, like the great Houdini. The older I get, the more and more I tend to adhere to the *mythos* of the perception of time accelerating ever so faster with age.

All that is to say, that the whole month felt like it lasted about as long as the whole [Fable 5][fable5] release.

Too soon? Alright, I'll shut up.

## The Boroughs

What did I just say last time around? There goes nothing, it has been canceled.  It's finished!

> The series premiered on May 21, 2026. In June 2026, the series was canceled after one season.

![tb](/media/2026/tb.png)

Dang it. Perhaps I should have bit my tongue, and said nothing at all. Oh well!

## The Story of C++

{% include youtube.html id="lI7tMxzSJ7w" %}

This seems to be handy-work for the very same people who did the Python documentary of yesteryear.

## Ahoy: Ammo Counters

{% include youtube.html id="kZVX7PHbqJ4" %}

## Fred

Dusted off yet another ancient side-project from the very depths of my archives. This one is written in Delphi and compiled with Delphi 6 Personal Edition (and maybe 7 as well later?).

![fred](/media/2026/fred.png)

Too lazy to look at the `DVCLAL` resource to figure out if the executable that I still got is one or the other.

At any rate, this was one of the many things that I spent my summer vacations of 2003, and 2004 working on rather tirelessly.

Makes use of quite a lo of trial-ware (nag-ware!) so called *VCL components*. There was also support for importing *ActiveX controls* directly, for which Delphi would generate a *wrapper* VLC component for.

```pascal
uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, Menus, StdCtrls, ToolWin, ImgList,
  StdActns, ActnList, ExtCtrls,shellapi, richedit,
  IniFiles, DosCommand, Clipbrd, PlusMemoU, UrlHighlightU,
  PMSupportU, OOPHilitU, PlusToFormatU, HtmlHighlightU,
  NbHilitU, CPPHilitU, SQLHilitU, sSkinProvider, sSkinManager, ExtHilitU;
```

![trout_salmon](/media/2026/fishart/trout_salmon.png)

At any rate, I usually ended up *removing* (cough, cough!), the nags from the components themselves or the final executable depending on which way it was easier and more convenient.

It should go without saying that this is all pretty terrible code under the hood. I mean, I was young and restless, but it's also not the worst thing that one could write either all things considered.

Look at this absolute unit of a gem that I have found, while sifting through the code base.

```pascal
procedure TForm1.LoadTemplate(Sender: TObject);
var mycap:string;
begin
  with Sender as TMenuItem do begin
    if pmemo.GetTextLen = 0 then
     begin
       mycap:=caption;
       Clean(mycap);
       PMemo.Lines.LoadFromFile(localdir+mycap);
     end {if} else
       MessageBox(form1.Handle,'Oh, I''m sorry great master, but you can apply a template only into a blank file ):','Error',MB_ICONERROR);
  end; {with}
end; {LoadTemplate}
```

What a *beaut*, am I right or what? By the by, this little hit and run incursion, made me realize that I don't have Pascal or Object Pascal syntax highlighting support in my code snippets.

## Clown Hole

![ch](/media/2026/ch.gif)

While [Clown Hole][clownhole] is far from perfect, my *delirious-summer-monkey-brain* seems to have enjoyed it way more than I'd care to admit. It's just one of those games, you know? Go, give it a try yourself!

## The "Sackhoff" Show

![starbuck](/media/2026/starbuck.png)

{% include youtube.html id="Abo3yvuW6j4" %}

{% include youtube.html id="Eiq7TZ1Um2w" %}

{% include youtube.html id="PXBgyUb80EM" %}

{% include youtube.html id="OjIJ3W0EQqk" %}

{% include youtube.html id="_gM4f9uTEzw" %}

[Caprica Six][capricasix] and [Chief Tyrol][chieftyrol] joining in on the *fun*, was most definitely not on my bingo card when this series has started all the way back at the beginning of this year.

## Monthly "*Book Review*"

This is another book that never got translated into  English nor did it ever make it to Amazon. It is by the very same author as last months' book on Pascal, which is not too surprising.

Sadly, I no longer have a physical copy of it as I lent it away many moons ago, and quite honestly didn't bother with getting it back. Totally my fault. At any rate, the book is nothing to write home about anyway, but with the power of mighty Google and AI (*ooohhh, scary!*), I managed to conjure it up in all its glory.

![limbdelphi](/media/2026/limbdelphi.png)

Unbeknownst to there was sort of a follow-up compilation book type of thingy all the way back in 2005, that combined this book and another one in the same vein about Visual Basic into a single book.

I did manage to find a copy of this in PDF form of course, on the sideways of the great information super-highway. I told you that my *google-fu* is still pretty good.

Anyway, the bits about Delphi are exactly the way I remembered them. Brought back some memories, however there was a funny bit in the Visual Basic section, where the author tried to recreate a more or less bastardized version of *Swat!* using the very same sprites from the original.

If you are slightly confused and asking yourself what on earth is *Swat!*? Let me clue you in. It's a silly little sample *game* that used to ship with Borland Delphi and Borland C++Builder.

![swatd6p](/media/2026/swatd6p.png)

![swatbcb1](/media/2026/swatbcb1.png)

It's pretty nuts to be honest that both of these IDEs are fully functional in Wine.

## Monthly *"Coup de cœur"*

The [Assembly 2004 invitation][asm04invtro] by [Moppi Productions][moppi] is probably one of the greatest *invtros* out there, if you ask for my totally and brutally honest opinion.

{% include youtube.html id="SVYjT3VJ3gU" %}

I am happy to report that the [*flower effect*][floweffect], still feels as mesmerizing and fresh as it did all the way back in 2004, when I saw this for the very first time.

Please enjoy the show, and don't forget to try the fish!

[asm04invtro]: https://www.pouet.net/prod.php?which=12031
[moppi]: https://www.pouet.net/groups.php?which=90
[floweffect]: /media/2026/flower_effect_explained.pdf
[capricasix]: https://galactica.fandom.com/wiki/Caprica_Six
[chieftyrol]: https://galactica.fandom.com/wiki/Galen_Tyrol
[clownhole]: https://jaco-van-hemert.itch.io/clown-hole
[fable5]: https://www.anthropic.com/news/fable-mythos-access
