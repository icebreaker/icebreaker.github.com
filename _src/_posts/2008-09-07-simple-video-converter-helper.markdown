--- 
layout: post
title: Simple Video Converter Helper
tags: 
- bash
- script
- video
- resize
- ffmpeg
---
I made this little script to be able to convert - resize videos easily, without typing in kilometric strings into the terminal.

It's not the most elegant script you ever seen, but hey, it works :)

As always, make it executable and put it in a safe place like /usr/bin :P

{% highlight bash %}
#!/bin/bash

# Author: Icebreaker
# Description: Resize a video to 1280x720 (HD).
# I'm using this script to resize videos to 1280x720
# ( maintaining the source quality )
# which can be posted to Vimeo.com for example and be converted
# automatically to a HD quality  video.
#
# This could be done a lot more elegantly ... I'm sure, but it does
# the job for me and that's all what matters :)
#
# The argument "parsing" is not completely n00b proof :P
#
# PS: vimeo.com is cool :P
#
# Requires: ffmpeg
#
# Public Domain

if [ $# -lt 2 ] ; then
echo Usage: mkhdv input.video output.video [-t "some video title"] \
[-s 1280x720]
exit 13
fi

if [ $# -eq 4 ] ; then
	# title
	if [ "$3" = "-t" ] ; then
		ffmpeg -i "$1" -sameq -s 1280x720 -title "$4" "$2"
	else
		# size
		if [ "$3" = "-s" ] ; then
		ffmpeg -i "$1" -sameq -s "$4" "$2"
		else
		echo Usage: mkhdv input.video output.video \ 
[-t "some video title"] [-s 1280x720]
		exit 666
		fi
	fi
else
	# we have size and title
	if [ $# -eq 6 ] ; then
		TITLE=""
		SIZE=""
		# look for title
		if [ "$3" = "-t" ] ; then
			TITLE="$4"
		fi
		if [ "$5" = "-t" ] ; then
			TITLE="$6"
		fi
		# look for size
		if [ "$3" = "-s" ] ; then
			SIZE="$4"
		fi
		if [ "$5" = "-s" ] ; then
			SIZE="$6"
		fi
		if [ -z "$TITLE" ] ; then
			TITLE="Untitled Video"
		fi
		if [ -z "$SIZE" ] ; then
			SIZE="1280x720"
		fi
		ffmpeg -i "$1" -sameq -s "$SIZE" -title "$TITLE" "$2"
	else
		ffmpeg -i "$1" -sameq -s 1280x720 "$2"
	fi
fi
echo Done
exit 1
{% endhighlight %}
