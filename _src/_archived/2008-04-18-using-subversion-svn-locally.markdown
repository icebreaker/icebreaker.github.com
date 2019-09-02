--- 
layout: post
title: Using Subversion (svn) locally ...
tags: 
- commit
- control
- linux
- locally
- source
- subversion
- svn
- tortoisesvn
- ubuntu
---
It does makes sense using Subversion locally even for small projects, because later it can be easily exported and imported into Sourceforge, Google Code for instance.

On Windows this can be done fairly easy with TortoiseSVN, under Linux there are also a bunch of GUI svn clients, my favorite one is KDESVN, but you can always fire up a terminal and use "svn" ...

We can create a repository with the following command:

<em><strong>svnadmin create /home/user/svn_repo</strong></em>

Now let's import some "initial" content into with the following command:

<em><strong>svn import /home/user/projects/krad_proj file:///home/user/svn_repo -m 'initial import of krad_proj'</strong></em>

We don't work right in the repository so let's make another directory and get a copy of the project from the newly create repository with the following command:

<em><strong>svn checkout file:///home/user/svn_repo/krad_proj</strong></em>

So this way we can alter our "copy" and then just commit the changes, all locally without any server or exposing our system in any way, which is great.

For more commands, information feel free to visit <a title="SVN rocks!" href="http://subversion.tigris.org/" target="_blank">http://subversion.tigris.org/</a> .

May the source be with you, and good night!
