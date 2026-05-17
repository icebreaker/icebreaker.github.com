---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2026/
title: Does your blog still render in IE6?
propaganda: www
music: seIP_1f92vc
tags: www digital-archeology
---

Does your blog still render in IE6?
=========================

I got really curious a short while back, if this very blog would still be somewhat readable in the crown prince of terrible browsers, also known as [IE6][ie6]. And, while I was contemplating that evil thought, I said to myself what about others like [Mozilla 1.5][moz15] or [Netscape 6][ns6]?

## IIS

While this blog is statically generated, it still needs a local *web server* to be browse-able, due to the directory structure that provides the so called *pretty-permalinks*.

No permalinks that end with `/index.html` here. Oh no, no! Not on my watch.

Now, there's absolutely no better choice than [IIS][iis] for this very purpose, right? Besides, a bastardized (*personal?*) version of it is available right under our very own finger tips, via the infamous *Add or Remove Windows Components"*.

![iis](/media/2026/iis.png)

Then, I dropped all the files into `C:\Inetpub\wwwroot`, and then added `index.html` to the list of files recognized as a `Default Document`.

![iisdefdoc](/media/2026/iisdefdoc.png)

> **Microsoft Peer Web Services**
>
> ![pws](/media/2026/pws.gif)
>
> It turns out that Microsoft used to ship an utter monstrosity called [Peer Web Services][pws], which was supposed to be the equivalent of IIS for Win9x.
>
> The more you know!

With all that out of the way, it was time to fire up each browser, and take a look.

## IE6

![ie6](/media/2026/ie6.png)

## Mozilla 1.5

![moz15](/media/2026/moz15.png)

## Netscape 6

![ns6](/media/2026/ns6.png)

## The "Final" Verdict

I would be lying if I didn't mention that I did end up making a couple of minor tweaks.

First and foremost, I added a couple of additional font-families like `Verdana` and `Tahoma` to make the fonts somewhat more palatable, and a tiny bit easier on the eyes.

Then continued with adding *render-fallbacks* inside the `<video>` and  `<audio>` elements (tags?), so that they render a link that can be used to download and view the media.

```html
<video muted controls width="1024">
    <source src="ie6.mp4" type="video/mp4">
    <blockquote>
    Your browser does not support the video element.
    Please click <a href="ie6.mp4">here</a> in order to
    download and view the video.
    </blockquote>
</video>
```

But overall, everything is pretty much readable at a `1024x768` resolution. What about that very annoying horizontal scrollbar? I really wasn't in the mood of doing more layout sizing and padding *kung-fu* in order to make it all *fit* inside a `1024px` wide viewport.

Sorry, not sorry!

[ie6]: https://en.wikipedia.org/wiki/Internet_Explorer_6
[moz15]: https://en.wikipedia.org/wiki/Mozilla
[ns6]: https://en.wikipedia.org/wiki/Netscape
[pws]: https://home.ubalt.edu/abento/452/Pws/pws.html
[iis]: https://en.wikipedia.org/wiki/Internet_Information_Services
