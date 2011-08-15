--- 
layout: post
title: RakeBuild a.k.a Rake for CPP
tags: [rake, build, coding, c++, rakebuild]
article: true
---

### Build System Wanted

There was a little project named Lera3D and it was looking for a good cross-platform build system. Ha!

Yeah, Lera3D currently uses [Scons](http://www.scons.org) which is Python based. I was quite happy with it, but it feels
heavy and complicated, I like Python but Scons feels over-engineered; even a simple thing like adding an additional 'include' path 
can't be done in a reasonably intuitive way. I don't want to open a war between the Pythonist and Rubyst camps, these are my
own personal thoughts, don't take them as granted.

LemonTea as well as my other QT based projects use [QMake](#); is much better design wise, but it's QT centric which
makes it feel awkward when used to build Non-QT projects.

At some point I considered migrating Lera3D to [QMake](#), but changed my mind ... and opted for Rake. I'm most definitely not a
Ruby fan boy and I'm not becoming one, but Ruby *feels natural* ... (this is purely a matter of personal taste / choice)

Don't get me started when it comes to [CMake](#) et al.

### Going Rake

Rake is surprisingly well documented, there are hundreds of Ruby **addicts** and despite the *rumors* saying that it's not easy
to handle *sub-modules*, I find it quite intuitive . There is no need for writing additional wrappers or abstraction layers
on the top of it, nor very complicated 'Rakefile' scripts, everything can be kept simple and efficient (most of the time).

With Rake you have 100% control over the build process plus all the benefits offered by Ruby; one can do pre-processing, 
generate files, archive files, get revision numbers from Git, etc, etc. the possibilities are virtually endless.

### Birth of RakeBuild

It took me a day and a half to build this 'Rakefile' which is somewhat similar to QMake and Scons but uses YAML configuration
files instead of individual Rake scripts for every sub-module.

RakeBuild is tailored towards building modular C/C++ projects in an effective and simple manner.

Consider the following directory structure:

* Project
  * src
  	* plugin1
  		* file.cpp
  		* plugin1.yaml (optional)
  		* plugin1-debug.yaml (optional)
  	* plugin2
  		* file.cpp
  		* plugin2.yaml (optional)
  		* plugin2-debug.yaml (optional)
  	* application
  		* main.cpp
  		* application.yaml (optional)
  		* application-debug.yaml (optional)
  * build
  	* release
  		* plugin1
  		* plugin2
  		* application
  	* debug
  		* plugin1
  		* plugin2
  		* application
  * Rakefile
  * Makefile (calls rake commands)
  * Project.yaml (optional)

Each sub-directory of *src* contains a *module* with source code and an appropriate RakeBuild project file. Sub-directories
which doesn't contain a RakeBuild project will be skipped.

RakeBuild supports two build targets *Release* and *Debug*.

* Release => [module-dir-name].yaml
* Debug => [module-dir-name]-debug.yaml

Each RakeBuild project contains key=>value pairs (in valid YAML format) which is merged with the default global
project configuration for every module.

If there is [project-dir-name].yaml file in the root of the project where the Rakefile is, then it will be picked up
and all key=>values will be merged into the default global project configuration. 

This is useful because the whole build process can be configured from here, without ever changing the Rakefile itself.

A basic executable can be compiled just by placing an empty RakeBuild project file in the module directory as the
default settings are for executable targets.

The 'build' directory structure (which is a mirror of the source directory structure) is created automatically so you 
don't have to worry about it.

There's also automatic dependency linking which can be turned off if needed, but it comes handy when you have to link
to modules with an executable module.

For this scenario the RakeBuild project file for the executable would be something like this:

{% highlight yaml %}
name: hello_world
type: app
deps: [lib1, lib2]
{% endhighlight %}

The **deps** is an array of module directory names from within the top level *src* directory; with automatic dependency
linking those two libraries will be automatically linked without specifying extra flags for the linker manually.

### Getting Started with RakeBuild

You can get a better understanding about how this works by looking at the source code or checking out the provided
sample projects.

The whole RakeBuild work-flow is in my head, but it's rather cumbersome to write it down, I think that it's easier to understand
by looking at the provided samples.

Documentation is good, but self-explaining code is even better. **evil grin**

I find it quite intuitive and perfect for my purposes but as always, everybody has different needs so your mileage may vary.

Contributions, input (constructive!), ideas, etc. are more than welcome. The source code can be found on GitHub right 
[here](http://github.com/icebreaker/RakeBuild) .

I'm looking forward to get some feedback, especially from **Rubyst** *camp*, because I'm pretty sure that some of the stuff 
can be done in a lot more elegant or simpler way .

With a simple Makefile like below, RakeBuild can be used with QT Creator or other IDEs which have support for *importing* 
existing Makefile based projects.

{% highlight makefile %}
all:
	rake
release:
	rake release
debug:
	rake debug
clean:
	rake clean
distclean:
	rake clobber
realclean: distclean

.PHONY: all release debug clean distclean realclean
{% endhighlight %}

### What's missing

What I consider that it's missing at this point is a *configure* **stage** which can check for 'external' dependencies and do a
complete report if something isn't the way it was originally expected.

### Two Column Layout

I added another flag to my Jekyll layouts, this makes it possible to 'toggle' the two column fluid layout for certain posts. 

Neat isn't it??!

If **you** still didn't migrate to Jekyll then **you** should definitely give it a try, because once you try it (*I guarantee*) 
you never go back and find solutions like WordPress cluttered, heavy-weight or altogether ... lets say it .. unnecessary.
(less is more, most of the time)

Alas, users with browsers without support for this multi-column CSS3 feature (as of now), will render the posts
using the standard one column fluid layout.

### End of Line
