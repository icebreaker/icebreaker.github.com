--- 
layout: post
title: C++ like 'string' transform ...
tags: 
- c
- coding
---
All we need is a naked class with the<strong> () operator</strong> overloaded to execute and wrap the "real" <em><strong>tolower</strong></em>.

{% highlight cpp %}
struct toLower
{
	int operator()(int ch)
	{
		return tolower(ch);
	};
};
{% endhighlight %}

With this our <em>transform</em> will resume to this <em>beautiful</em> and <em>elegant</em> line ...

{% highlight cpp %} transform( s.begin(), s.end(), s.begin(), toLower() ); {% endhighlight %}

... instead of the very <em>'C like'</em> looking (even if we used C++ like casting):

{% highlight cpp %} transform( s.begin(), s.end(), s.begin(), (int(*)(int))tolower ); {% endhighlight %}

Pretty, pretty :D
