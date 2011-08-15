--- 
layout: post
title: Libtouch and more ...
tags: 
- cameras
- fix
- multi-touch
- multiple
- patch
- touchlib
- two
- webcam
---
Today I saw this excellent HOWTO at <a title="Click and whoooo!" href="http://ssandler.wordpress.com/mtmini/" target="_blank">http://ssandler.wordpress.com/mtmini/</a> on how to make your very own multi-touch pad, which is the coolest thing i've ever seen during the last two decades ... *cough, cough* ...

I haven't made one myself yet, but I downloaded touchlib and I found it quite annoying that it used my built-in cam from my toshiba sattelite laptop however I plugged in another external one.

So, I did a quick fix to be able to use /dev/video1 ... oh yeah, I tried this under Linux, more specifically Ubuntu, because I was lazy to setup all the libs with headers and shits under Windows.

In the CvCaptureFilter.cpp right in the void CvCaptureFilter::setParamater( ... ) I added two more lines, so my version looks like this:

{% highlight cpp %}
void CvCaptureFilter::setParameter(const char *name,
                                   const char *value)
{
   if(!capture)
   {
      if(strcmp( name, "source" ) == 0)
      {
        strcpy(source, value);
        if(strcmp( value, "cam" ) == 0)
        {
          capture = cvCaptureFromCAM( CV_CAP_ANY );
        }
        else if(strcmp( value, "cam1" ) == 0)
        {
          capture = cvCaptureFromCAM( 1 );
        }
        else
        {
          capture = cvCaptureFromAVI(value);
        }
      }
   }
}
{% endhighlight %}

With this done, i can just change in the "config.xml" the "source" to "cam1" and make use of my other camera device on /dev/video1 :)

That's all I need :D

A few other thoughts ... you can give an index from 0..99 to the cvCaptureFromCam( ... ) and then it will try to find the first available driver for that particular device, or if you give something &gt;=100 then it will try to use that particular driver with the first available video device; CV_CAP_ANY = 100 .
