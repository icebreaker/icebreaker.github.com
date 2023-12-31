---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2023
title: 2023 November Retrospective
year: 2023
monthly: true
propaganda: 0
---
2023 November Retrospective
==========================
Now that November is all said and done, the glorious month of December can begin, which is the month of the year when nothing really gets done.

A while back, I wrote a tiny [Tamper Monkey][tampermonkey] script that would *inject* some extra buttons into Steam App pages. I did this to make it easier to launch tools like [Steam Spy][steamspy], without having to go through the pain of searching for a particular game by its *game id* and so forth.

![suika](/media/2023/suika.png)

I ended up cleaning it up a little bit and added [Gamalytic][gamalytic] into the mix, as can be seen in the screenshot above.

You can find the integral source code below. It's not much, but it's honest work.

```js
// ==UserScript==
// @name         Extra Steam Buttons
// @namespace    https://mihail.co
// @version      0.2
// @description  Adds extra buttons to Steam.
// @author       Mihail Szabolcs
// @match        https://store.steampowered.com/app/*
// @grant        none
// ==/UserScript==

(function()
{
    'use strict';

    const add_button = (title, url, margin, match_id_only) =>
    {
        const el = document.querySelector('.apphub_OtherSiteInfo');
        if(!el) {
            return;
        }

        const a = el.querySelector('a');
        if(!a) {
            return;
        }

        const button = a.cloneNode(true);
        const path = a.href.match(/\/app\/([0-9]+)/)[match_id_only ? 1 : 0];

        button.href = url + path;
        button.target = '_blank';

        if(margin && margin > 0) {
          button.style.marginLeft = margin + 'px';
        }

        const text = button.querySelector('span');
        if(!text) {
            return;
        }
        text.innerHTML = title;

        el.appendChild(button);
    }

    add_button('Steam Spy', 'https://steamspy.com');
    add_button('Steam Charts', 'https://steamcharts.com', 3);
    add_button('Gamalytic', 'https://gamalytic.com/game/', 3, true);
})();
```

If you were wondering what on earth is [Suika Game][suikagame]. Well, it appears that it's the next best viral game out there. It's a combination of [Tetris][tetris] and [2048][2048].

The official version is available on the [Nintendo Switch Store][suikagamenintendostore].

{% include youtube.html id="BDqJUJ-jOSQ" %}

It's extremely addictive, so be careful. Consider yourself warned! Maybe it's time for a new DOS & boot-able viral game. You've heard it here first.

Almost forgot, I also ended up trying out yet another vampire survivors-like this month called [Death Must Die][deathmustdie].

{% include youtube.html id="MhjXHpU2JJU" %}

I will have to make list or some sort of a top of all the vampire survivors-likes that I ended up playing during the past year and a half or so.

There's a TODO item for the final retrospective of the year at end of December.

[suikagame]: https://en.wikipedia.org/wiki/Suika_Game
[suikagamenintendostore]: https://www.nintendo.com/us/store/products/suika-game-switch/
[gamalytic]: https://gamalytic.com
[deathmustdie]: https://store.steampowered.com/app/2334730/Death_Must_Die/
[tetris]:https://en.wikipedia.org/wiki/Tetris
[2048]:https://en.wikipedia.org/wiki/2048_(video_game)
[tampermonkey]: https://www.tampermonkey.net/
[steamspy]: https://steamspy.com/
