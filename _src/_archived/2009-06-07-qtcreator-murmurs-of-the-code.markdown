--- 
layout: post
title: QtCreator - Murmurs of the Code
tags: 
- c
- coding
- qtcreator
- qt
---
QtCreator has a quite strict coding style, but there is one important thing I would like to highlight. The pollution of the header files is minimal ... and when I'm say pollution I'm referring to the inclusion of other header files.

If you look at a regular header file from the code base, you will notice stuff like this:

{% highlight cpp %}
namespace Core
{
	class someclass;
	namespace Internal
	{
		class anotherclass;
	}
}

namespace
{
	bool debug = false;
}

class MyClass : public Core::Internal::anotherclass
{
	...
}
{% endhighlight %}

Instead of doing something like this:

{% highlight cpp %}
#include <Core/Internal>

using namespace Core::Internal;

bool debug = false;

class MyClass : public anotherclass
{
	...
}
{% endhighlight %}

Why is the 1st approach important, clean and a lot more self explaining?

Now think about that you will include the file containing MyClass in some other file, this will lead to the inclusion of &lt;Core/Internal&gt; and even worse the whole Core::Internal name-space, which can lead to variable collisions and tons of other frustrations.

With the first approach, everything is fully incapsulated, and there are virtually no side effects thus leading to a way much cleaner design with almost no extra work.

The anonymous name-space does pretty much the same thing (it's more like the good old "static") .

Personally I think that this is a very very good practice, regardless of the actual size of the code base.
