--- 
layout: post
title: Qt Creator - best thing since sliced bread
tags: 
- coding
- qtcreator
- git
- qt
---
Today, I started again my never ending race for the perfect cross platform IDE (duhh, instead of working on Lera :P), and stumbled across Qt Creator. I was quite sceptical while waiting for the "binary" version to install, but once it was installed BOOOOOOMMM!!!!

QtCreator is fully modular, everything is a plugin and it has an pleasant and very very clean interface, besides that its speed is comparable to a naked GEdit with a few plugins ( this is what I was using until now ).

Then I did a simple project and included (without generating any tag database etc ), some files form Lera3D and the code completion worked out of the box (CodeLite is close to this, but I hate the Scintilla editor component).

After this, it was clear ... I WANT THE SOURCE code ... haha, so I headed over Gitorious and "forked" (cloned) the repository in order to make my own changes and eventually submit them to the "official" master branch.

The first thing I added is a persistent settings dialog for the "Generic Project" wizard, in order to allow to follow symbolic links when creating a new project.

I like to keep my "framework" separately from the actual projects using the "framework", this way when something changes in the framework I don't need to bother updating the various copies, this is where Symbolic Links come into the scene.

<a title="Click to see the bigger version." class="image" href="/images/2009/05/screenshot.png" target="_blank"><img class="size-thumbnail wp-image-549" title="Click to see the bigger version." src="/images/2009/05/screenshot-400x132.png" alt="Click to see the bigger version." width="400" height="132" /></a>

Another thing I would like to add (in the near future) is the ability to "add directories" to a project instead of just manually selecting files.

Here is my "cloned" repository, where I will push all my changes.

<a title="Click to go and fork!" href="http://gitorious.org/~icebreaker/qt-creator/qt-creator-personal" target="_blank"></a>UPDATE: Sept 17, 2009 -- REMOVED THE FORK!

The original "master" branch is here:

<a title="Original Qt Creator Master Branch!" href="http://qt.gitorious.org/qt-creator/qt-creator" target="_blank">http://qt.gitorious.org/qt-creator/qt-creator</a>

Oh, and I "ported" over the "Desert" color scheme from Gedit, and set the default font to Droid Sans Mono ( but you already noticed that from the screenshot ) :P

From now on Qt Creator is definitely my IDE of choice, even though I don't have any QT based projects at the moment.

It can work with Scons as well, all we need is a simple "wrapper" makefile like this:

{% highlight basemake %}

all:
scons -Q -j3 nocolors=1
clean:
scons -c nocolors=1
distclean: clean
realclean: clean

.PHONY: all clean distclean realclean

{% endhighlight %}

<em>(Qt Creator seems to be the only viable enemy to Visual Studio at the time being)</em>

<em>Update: Nov 17, 2009</em>

<em><a title="Desert" href="/files/desert.xml" target="_blank">Desert Theme Port</a></em>

<em><a title="Oblivion" href="/files/oblivion.xml" target="_blank">Oblivion Theme Port</a>
</em>
