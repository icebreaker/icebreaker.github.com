--- 
layout: post
title: How to fix broken folder icons in Ubuntu?
tags: 
- icons
- linux
- ubuntu
- broken
- folder
---
This have been hauting me for some time now, and finally i found out an easy solution which works.

The key is to edit the <em><strong>index.theme</strong></em> file usually located in <em><strong>/home/[username]/.icons/[theme-name]</strong></em> ( after the theme is installed, but it can be done before installing and then just re-pack the patched version to use it right away ) and changing the <em><strong>"inherits=gnome"</strong> line to <strong>"inherits=none"</strong></em>, then copying <strong>gnome-fs-directory.png </strong>to <strong>folder.png </strong>and finally reloading the theme.

The location of the <em><strong>gnome-fs-directory.png</strong></em> is dependent on how each individual theme is organized, so there no exact location for it, but it's there inside the theme directory.

One of my favorite icon themes is the <strong><em>"Glossy Glass"</em></strong> . You can grab it right <a title="Glossy Glass" href="http://www.gnome-look.org/content/show.php/Glossy-Glass?content=27166" target="_blank">here</a> .

Probably the best way is to re-pack the theme after, to avoid repeating these if you wanna use the same icon theme on another machine, or you re-install your system, etc.

It seems easy when you already know the solution huh? haha :))
