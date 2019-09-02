--- 
layout: post
title: FOSS yada yada ...
tags: 
- lera3d
- yada
- licensing
- business
---
-><a class="image" href="/images/2010/01/art54_1.jpg"><img class="size-full wp-image-766 alignleft" title="art54_1" src="/images/2010/01/art54_1.jpg" alt="" width="240" height="204" /></a><-

It's not my style to blog yada-yada; I try to focus on the technical side of things, but lately I've been thinking about what it takes to bootstrap a small start-up governed by '<a title="The Hacking Business Model" href="http://askmonty.org/wiki/index.php/The_hacking_business_model" target="_blank">The Hacking Business Model</a>' crafted together by our fellows Zak Greant and Michael Widenius .

Personally, I think that dual-licensing is very important, especially for a 3D Game Engine &amp; Framework; instead of LGPL I will go with EPL. The next question which comes up is why? Well, while EPL guarantees that <em>derived works </em>must be contributed back to the community, it does allow completely separate modules to be licensed under another license, even a proprietary one; the primary benefit of this is that some 3rd party might not want to open source their plugin, with EPL they can do that without any problems.

The biggest question is that with a license like EPL, when the <em>alternate commercial license</em> will make sense, if ever? Lets take this step by step; first of all most of the time for any serious project based on a game engine, the programmers will have to touch the engine itself or at least some module of it; it's just impossible to make an engine to suit everyones needs, so if they modify it, but don't want to contribute back their changes to the community (let's say that they re-wrote major parts of some of the existing renderers -- this would be classified as a <em>derivate work</em>), or they just want professional prioritized support (they always have the community as a support free of charge) it's feasible for them to pay a license or just support fee.

-><a class="image" href="/images/2010/01/team.jpg"><img class="alignright size-full wp-image-767" title="team" src="/images/2010/01/team.jpg" alt="" width="295" height="225" /></a><-

We'll see how it goes after I release the first <em>community version </em>of Lera3D ; to be able to form a community around it is the most important step, without a developer community an open source project means <em>NOTHING</em>. The <em>bazaar </em>model works so much better than the cathedral model, this have been proven many many times already.
I'm not planning to make the <em>alternate commercial license </em>available until the first stable version 1.0 ; obviously to be the <em>next big thing </em>it<em> </em>means mature code, and crafting mature code takes some time, even with a fully open development model.
I know that there is a motto which says <em>"release early, release often"</em>, but I'm not releasing any source code until Lera3D reaches beta, it just wouldn't make sense releasing any code earlier, mostly because I want to implement all my ideas first (or stuff I miss in other engines, etc), be them good or bad, they are mine!
Wow, this post got really really long ... lots of blah, blah ... just another late night post ... Good Night!
