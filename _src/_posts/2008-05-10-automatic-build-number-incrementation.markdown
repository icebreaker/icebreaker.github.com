--- 
layout: post
title: Automatic Build number incrementation
tags: 
- automatic
- build
- gcc
- linux
- make
- makefile
- number
- ubuntu
---
Automatic build number incrementation always was a <em>hot topic</em> especially under Linux. My solution is fairly simple to implement, so let's see some "code" right away:

{% highlight bash %}

#!/bin/bash
echo Fetching and updating build number ...
cat Core/Build.cpp | awk '{ printf("unsigned int g_internalbuildNumber = %d ;\n",$5+1); }' > Core/_Build.cpp
rm Core/Build.cpp
mv Core/_Build.cpp Core/Build.cpp

{% endhighlight %}

This is a nice little bash script, but you already knew that, what it does? Well it reads in the previous build number and writes it back after incrementing it with 1.

The initial "Build.cpp" must contain the line:

<strong>unsigned int g_internalbuildNumber = 0 ;</strong>

... please notice the spacing because it is very very important, since awk parses the tokens based on the spaces.

Now make this script to be executed as the first thing inside your makefile, and make sure that the "Build.cpp" is compiled and linked with your executable, shared object or whatever.

To access the build number from within the code, you just have to do an "<em>extern unsigned int g_internalbuildNumber;</em>" and there you go, nothing fancy but still cool :P

Maybe it's not the most elegant solution, but hey ... it works for me and that's all what matters :D
