--- 
layout: post
title: C++ like format for std::string ...
tags: 
- c
- coding
- code
---
Now, the 'quite heavy' BOOST libs have some nice format(), and also MFC has it, but not the poor STL string container.

I came up with a very nice and compact way to do this, and thought that I should share it.

So, here we are, let's see the code ...

{% highlight cpp %} #include <cstdarg> {% endhighlight %}

... the format ...

{% highlight cpp %}

#define BUFF_SIZE 4096
string format( const string &msg, ... )
{
	va_list ap;
	char text[BUFF_SIZE] = {0,};
	va_start(ap, msg);
		vsnprintf(text, BUFF_SIZE, msg.c_str(), ap);
	va_end(ap);
	return string( text );
}

{% endhighlight %}

BUFF_SIZE as 4096 should be enough, in most cases, but of course it can be tweaked as necessary, the rest is just the normal way to play with functions which have variable number of arguments.

vsnprintf have been used in order to avoid buffer overflows and the like.

{% highlight cpp %}
cout<<format(string("%s hello") + string("world %d"),"this is",13)<<endl;
{% endhighlight %}

From the one liner above it is clearly visible, the cleanness and elegance of this approach.

Neat isn't it?

PS: I like the new Syntax Highlighter plug-in :P
