--- 
layout: post
title: "Programming Tip #0"
tags: 
- c
- programming
- tip
---
I'll start a series of programming tips and tricks in various languages, and this will be the first one :)

These are very rare, strange and uncommon stuff for the normal mortals ... oK enough chit-chat let's see some code.

What's wrong with the following code snippet?

{% highlight cpp %}
template <typename T>
class obj
{
	public:
		obj(){};
		virtual ~obj()
		{
			map<unsigned long, T*>;::iterator it;
			//...
			//...
		};
	//...
	//...
	//...
	private:
		map<unsigned long,T*> items;
};
{% endhighlight %}

Well this will fail, at this line <em>map&lt;unsigned long, T*&gt;::iterator it;</em> giving a rather confusing and cryptic error message which looks something like this <em>error: expected `;' before it</em> . Hmmm ...

This can be solved by putting the <em>typename</em> keyword at the beginning of that line. It took me some time to figure out what was the problem :)

Happy coding, and may the source be with you!
