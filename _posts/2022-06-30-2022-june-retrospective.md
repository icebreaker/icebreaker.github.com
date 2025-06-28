---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2022
title: 2022 June Retrospective
propaganda: 5
tags: retrospective
---
2022 June Retrospective
======================
Here we are 6 months into the year. Time truly really flies by and I am happy to bring you another dose of nutritious episode of pure and elemental yak-shaving. Getting there, slowly but surely.

A few years ago, I wrote and released a Vim plug-in called [fastopen.vim][fastopen] - a quick file opener. This was before the days of Vim having all the hot and shiny features like asynchronous jobs, timers and pop-up menus. 

![Screenshot](/media/2022/fastopen.png)

It relies on the excellent [dmenu][dmenu] to display the always-on-top drop-down menu.

Now with the advent of [Vim 9][vim9] released just a few days ago, I felt like it's about time to take it to the next level and create another such plug-in while also leveraging `vim9script`, which is more or less a faster and in some ways saner version of good old `vimscript`.

There will be a lot of opinions about the merits of `vim9script` in the coming months.

![nextopen](/media/2022/nextopen.png)

Will wrap it up and release it most likely in the next couple of weeks, as I have the basic functionality all sketched up and functional already.

In other news, I bought an [ASUS Vivobook Flip 14][vivoflipbook] that came bundled with Windows 11 Home Edition. I was super duper curious to see if the rumors were true about Microsoft not letting you create a local account without pulling some stunts.

And, indeed it is true. First of all they do force you to hook up to a WIFI during the initial setup process and as a result you no longer get the option to create a local account.

The only way I managed to get around this is by restarting my router and then going back and forth in the setup in order to pick up the fact that it couldn't connect anymore and voila, the ability to create and use a local account became available.

I don't think that it even has to be called out that this is an absolutely despicable practice.

As far as the actual hardware goes, I find it amusing that we are no longer calling them "Tablet PCs", like we used in the good old days, when of course I could never afford one. I guess the stigma is still up in the air, and besides calling them "Flipbooks" is a lot more hipster. It's still nowhere near cheap, but a lot more affordable and has more than enough horsepower. The "new" Intel GPU, as always will not be the most stellar and shiniest thing on the block, but I feel like it's a good compromise for such a device and it's light years ahead of previous generations of Intel GPUs.

On more somber note, in my May retrospective, I was lamenting about the state of [libvte][libvte] and lo and behold more absolute madness hits the news, this time about [GTK5][gtk5].

This is clearly the result of none of these projects having a Benevolent Dictator For Life. Not going to complain more about this, but my cup keeps filling up and it's getting to the point where it will start overflowing. We can't talk about the "*year of the Linux desktop*" if at every step the underlying foundational blocks end up sabotaging any and all progress, no matter how minuscule.

[libvte]: https://github.com/GNOME/vte
[vim9]: https://www.vim.org/vim90.php
[gtk5]: https://gitlab.gnome.org/GNOME/gtk/-/issues/5004
[fastopen]: https://github.com/icebreaker/fastopen.vim
[dmenu]: https://tools.suckless.org/dmenu/
[vivoflipbook]: https://www.asus.com/Laptops/For-Home/Vivobook/Vivobook-Flip-14-TP470/techspec/
