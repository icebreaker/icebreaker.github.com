---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2026
title: Cracker Editor
propaganda: cre
music: 9STiQ8cCIo0
tags: dos digital-archeology
---

Cracker Editor
=========================

The Hungarian edition of the [Chip Magazine][chipmagazine] used to ship semi-regular dumps of [sac][sac] (*Slovak Antivirus Center*) archive, which was nothing short of a treastrove composed of copious amounts of freeware and shareware, among a variety of other things like documentation.

![chip96dec](/media/2026/chip96dec.png)

The whole collection used to be around `500` megabytes in the mid 90s, which of course would have been unphantomably massive for me to be able to attempt to download and store on my own. Not to mention absolutely prohibitively expensive.

Now, I have completely forgotten about it all, until relatively recently when I started dumping my aging CD collection into ISO, and noticed the `sac` directory while browsing one of them.

I quickly went to see if it's still up and running, and to my surprise it was. Then, I went to my favorite category called `UTILPROG`, and it didn't an awful long time before something that I don't ever remember seeing caught my eye. What was it, you might ask?

A rather curiously named [cre116a.zip][cre116a.zip], with the following description: *Cracker Editor v1.16a - DOS HEX-Editor*. I just knew that I had to try it out right there and then in [DOSBox][dosbox]. Well, what can I tell you? I most certainly wasn't dissapointed, that much is absolutely certain.

Since I know that you are dying to see how it looks, I won't hold the suspense for much longer.

![browse](/media/2026/cre/browse.png)

When you run it, you are greeted by this wonderfully colored and rather trippy file browser. This caught me off guard for a hot second, I have to confess. I don't really know how to explain it, but it most definitely has a certain rather unique charm to it.

Then of course, after choosing a file it gets even more colorful and stylish. Tell me that this is not the most beautiful things you've seen in your entire life. Come on now, tell the truth and shame the devil, like my good old friend Andre Linoge used to say.

![search](/media/2026/cre/search.png)

I really like how it displays pretty much all the relevant metadata in a single screen. The search dialog is simple, but has case sensitive and wildcard search options, as no doubt can be seen in the screenshot.

What else? It also has your usual decimal to hexadecimal and vice-versa converter.

![dec2hex](/media/2026/cre/dec2hex.png)

And last, but not least the quintessential `ASCII table`, which cannot be missing from any hex editor.

![ascii](/media/2026/cre/ascii.png)

It also has a bunch of other features like: a calculator, a DOS shell, goto to a given offset, and inserting a `NOP` (*0x90*) at the current offset among other features.

One thing however, that I found to be lacking is the ability to switch to a non-hex-view for text files at least. I know, I know that that not every hex-editor can be as feature rich as [HIEW][hiew], but still.

![doc](/media/2026/cre/doc.png)

Alas, not much can be found on the great information super-highway about the author, who happens to be going by the name of `Toni Mäkelä`, and rather unsurprisiginly appears to be from Finland.

The URL `http://www.sci.fi/~makton/cre/` listed in `CRE.DOC` cannot be found on [archive.org][archiveorg] either, which makes sense considering that the year was `1996`; which is exactly the year when the *Internet Archive* was founded.

At any rate, I consider it to be a true hidden gem that have survived well into the Windows era, and besides `16` colors should be enough for everyone, right? *Wink, wink*.

[cre116a.zip]: {{ "/extras/dos/utils/cre116a.zip" | absolute_url }}

[chipmagazine]: https://en.wikipedia.org/wiki/Chip_(magazine)
[dosbox]: https://en.wikipedia.org/wiki/DOSBox
[hiew]: https://en.wikipedia.org/wiki/HIEW
[archiveorg]: https://en.wikipedia.org/wiki/Internet_Archive
[sac]: https://www.sac.sk/
