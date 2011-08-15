--- 
layout: post
title: Dino And The Aliens ...
tags: 
- c
- daa
- cracking
- reverse
- engineering
---
<p style="text-align: left;">Initially I wanted to write up and article series about reverse engineering <span><strong><a id="e2lz" title="Click for the DEMO or BUY!" href="http://www.oberongames.com/dino_and_aliens.asp" target="_blank">Dino And the Aliens</a> </strong>by <strong><a id="vg2g" title="Visit NevoSoft!" href="http://www.nevosoft.com/" target="_blank">NevoSoft</a></strong></span>, but I kinda lost interest after I reversed the PAK file format. (I may return later and continue the work here ... who knows .. reversing the custom model format, etc ... lol)</p>
<p style="text-align: left;">To make the long story short, the files inside the Package File are encrypted with their filenames, so now I'm releasing the source code to manipulate (extract, replace, create, etc) these PAK files.</p>
<p style="text-align: left;">With this it is possible to create new levels because the level files are in plain text format and it's not that hard to figure out what character translates to what just by looking at the other levels.</p>
<p style="text-align: left;">I reversed the demo version, but I don't think that there are any differences, so the code should work pretty much fine with the full version as well.</p>
<p style="text-align: left;">If you like the game please BUY it . (IMHO, the best INDIE game ever! -- works under <em>Wine</em> as well :))</p>

<blockquote>Dino and Aliens

Mean aliens land on Dino's peaceful planet intent on blowing it up with lasers and explosives. Help Dino deploy his magic powers to battle the aliens and reclaim his carefree world in this whimsical fantasy game! "</blockquote>
<p style="text-align: center;"></p>


<a class="image" href="/images/2009/07/dfzz4ggw_803d2qk9xfg_b.jpeg" target="_blank"><img class="size-thumbnail wp-image-611" title="dfzz4ggw_803d2qk9xfg_b" src="/images/2009/07/dfzz4ggw_803d2qk9xfg_b-400x300.jpg" alt="Click for bigger version!" width="400" height="300" /></a>

The source code is located in <strong><a title="Get the source!" href="http://github.com/icebreaker/daa/tree/" target="_blank">here</a></strong> ; it's pure ANSI C and will compile pretty much anywhere with a decent ANSI C standard compliant C compiler like GCC.

There is no ready made executable, so <em>please</em> <strong>don't</strong> ask.
