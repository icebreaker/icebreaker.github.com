--- 
layout: post
title: Logging &#38; Filters ... etc
tags: 
- c
- console
- filters
- log
- log levels
- logging
- programming
---
I think that is extremely beneficial for every desktop application having an flexible yet powerful logging system.

This can "log" to a file, to a console (internal or not) or both. Anyway, the most important thing are the different log levels, and filters.

Let's say that we have Text, Info, Warning, Error ... each represents an level. Then we can setup a filter to "show" only the Warnings, or the Errors supressing all the other messages. This is extremly useful if you have bunch messages showing up in your log file / console.

Now let's see some code :)

{% highlight cpp %}
#define SAFE_ARRAY_DELETE(x) if(x) {delete [] x; x=NULL;}
#define INRANGE(x,min,max) ( (x >= min) && (x <= max) )

namespace Log
{
	const int Text		= 0;
	const int Info		= 1;
	const int Warning	= 2;
	const int Error		= 3;
	// used only by the filtering
	const int Any		= 4;
};

static int g_logFilter = Log::Any;

void setConsoleLogFilter( const int logFilter )
{
	if( INRANGE(logFilter,0,5) )
	{
		g_logFilter = logFilter;
		return;
	}
	g_logFilter = Log::Any;
}

void consoleLog( const int logLevel, const char *msg, ... )
{
	va_list ap;
	// is filtering turned on?
	if( g_logFilter != Log::Any && g_logFilter != logLevel )
	{
		return;
	}
	char *text = new char[ 2048 ];
	assert( text );
	memset(text,0,sizeof(text));
	va_start(ap, msg);
		vsprintf(text, msg, ap);
	va_end(ap);
	switch( logLevel )
	{
		case Log::Info:
			printf( "INFO: %s\n", text );
			break;
		case Log::Warning:
			printf( "WARNING: %s\n", text );
			break;
		case Log::Error:
			printf( "ERROR: %s\n", text );
			break;
		default:
			printf( "%s\n", text );
			break;
	}
	SAFE_ARRAY_DELETE( text );
}
{% endhighlight %}

This is very very straightforward ... it's C++, but it can be adapted to C, by replacing the memory managment stuff ... new with malloc, delete [] with free :) and moving out the constants into an enum :)

It works out great for me, and I use something very very similar to this on a day to day basis :D

Happy coding!
