--- 
layout: post
title: Python and Co.
tags: 
- c
- coding
- lera3d
- python
- embed
---
<p>Last night, I started playing a little bit with embedding python + exposing classes via Boost::Python, because I wanna integrate this kind of functionalities in my 3D engine.</p>
<p>Since my system is fully modular, and each sub-system lives in its own shared object ( or dynamic linking library under win32 ), it turned out quite easy to make those python modules as well.</p>
<p>(I use Gists @ GistHub to post the source code instead of having it in the post itself, since it's easier to manage over time)</p>
<p>Here is some boilerplate code for a sample sub-subsystem header and implementation:</p>
<p><script src="http://gist.github.com/79333.js"></script> <script src="http://gist.github.com/79334.js"></script></p>
<p>It is clearly visibile that it is a singleton class, hence the getInstance static method. I've also chosen to use the "py" prefix for the actual module name.</p>
<p>Now this can be compiled to a nice shared object or dynamic linking library and used right away.</p>

{% highlight bash %}g++ LeraSystem.cpp -shared -o pyLeraSystem.so -I/usr/include/python2.6 -lboost_python{% endhighlight %}

<p>I provide compile commands for Linux + GCC only, since it is my primary development platform, but this is very similar under Windows, there you one would get two files like pyLeraSystem.dll + pyLeraSystem.lib .</p>
<p>Again some boilerplate code and the expected output produced by it here ( cmd -- <em>python pyLeraTest.py</em> ):</p>
<p><script src="http://gist.github.com/79339.js"></script> Produced Output:</p>

{% highlight bash %}
hello world
Instance check ...
<pyLeraSystem.leraSystem object at 0xb7cb7534>
<pyLeraSystem.leraSystem object at 0xb7cb7534>
<pyLeraSystem.leraSystem object at 0xb7cb7534>
hello world
{% endhighlight %}

<p>Yayy! With this the singleton thingy was working, but wasn't the end of the journey :) Why? The answer is quite simple, I had to embed the python interpreter in order to take full advantage of this.  <script src="http://gist.github.com/79342.js"></script></p>
<p>I already had my sub-system as an shared object (even before exposing anything to python), so I just had to link it to interpreter stub to make the full magic happen between C++ &amp; Python working with truly the same instance of a sub-system.</p>
<p>A hack needs to be done here by doing an symbolic link from pyLeraSystem.so to libLeraSystem.so which can be achieved with the following command (assuming that the files are in the current working directory):</p>
<p>ln -s pyLeraSystem.so libLeraSystem.so</p>
<p>( this is not necessary under Windows, because there the .lib file is used to link against an dynamic linking library )</p>
<p>... to compile the embedded python interpreter ...</p>

{% highlight bash %} g++ LeraPythonEmbed.cpp -I/usr/include/python2.6 -L. -lpython2.6 -lm -lLeraSystem -o leraTestEmbed{% endhighlight %}

<p>To make it run one more hack is necessary, and that is adjusting the LD_LIBRARY_PATH to include the current working directory with a command like:</p>

{% highlight bash %}export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH{% endhighlight %}

<p>( this is again not necessary under Windows )</p>
<p>Also the python script needs to be adjusted a little:</p>
<p><script src="http://gist.github.com/79347.js"></script></p>
<p>Now running ./leraTestEmbed produces the following output:</p>

{% highlight bash %}
this message was set from C++ and printed by Python
this message was set from Python and printed by C++
{% endhighlight %}

<p>With this I reached my final goal, python and c++ fully interacting, using the same singleton sub-system class at runtime.</p>
<p>The approach of using modules instead of exposing classes, etc. directly from the embed interpreter adds a great deal of flexibility, and makes exposing existing plugins to python using Boost::Python piece of cake.</p>
<p>In the real life scenario ( my 3d engine and framework ) the actual sub-subsystems are not linked against the stub, they are dynamically loaded, and instantiated once in their full lifetime, but this is pretty much the same story.</p>
<p>Uffff, 548 words at the moment of typing this ... duhhh, I really need to get a life :))</p>
