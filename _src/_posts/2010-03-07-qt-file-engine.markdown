--- 
layout: post
title: QT's File Engine
tags: [qt, coding, bloody, sunday] 
---

[QT's](http://qt.nokia.com) [QAbstractFileEngine](http://doc.trolltech.com/4.6/qfsfileengine.html) isn't a very well 
documented subject, nor there are any good examples on how to make good use of it.

It makes sense using it when the application needs a virtual filesytem for reading files directly from a ZIP
or just restrict access to a certain directory.

Lets say that you have a scriptable game and you don't want to allow access outside of the "data" folder which holds all
the necessary data, with [QAbstractFileEngine](http://doc.trolltech.com/4.6/qfsfileengine.html) this can be resolved in 
a transparent way as shown in the code snippet below.

{% highlight cpp %}
...

//! File System Class
class FileSystem : public QFSFileEngine
{
	public:
		//! Constructor
		FileSystem(const QString &pFileName);
		//! Destructor
		virtual ~FileSystem();
};

//! File System Handler
class FileSystemHandler : public QAbstractFileEngineHandler
{
	public:
		//! Constructor
		QAbstractFileEngine *create(const QString &pFileName) const;
};

...

int main(int argc, char *argv[])
{
	FileSystemHandler lFileSystemHandler;
	QFile lFile("scripts/test.js");
	if(lFile.open(QFile::ReadOnly | QFile::Text))
	{
		...
	}
	return 0;
}
{% endhighlight %}

In *our* ***FileSystem class*** we preprend our base path to the fileName, i.e *"./data/"* so 
[QFile](http://doc.trolltech.com/4.6/qfile.html), [QDir](http://doc.trolltech.com/4.6/qdir.html), 
[QFileInfo](http://doc.trolltech.com/4.6/qfileinfo.html) all work the exact same way they did before registering 
our file engine handler just the paths get altered in the background.

The latest registered handler takes precedence over existing handlers.

We could also do another nifty thing and register a handler which would respond to **"fs://myfile.txt"**.

{% highlight cpp %}
QFile lFile("fs://myfile.txt");
{% endhighlight %}

QT's internal resource system is implemented this way, so that's a good place to study especially if you want to implement a ZIP
based virtual filesystem.
