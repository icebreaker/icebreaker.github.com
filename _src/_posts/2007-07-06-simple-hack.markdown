--- 
layout: post
title: Simple 'hack'
tags: [hack, javascript, photobucket]

---
Ever wanted to download all the photos in located in one album on <a href="http://www.photobucket.com" title="Click to visit!" target="_blank">PhotoBucket.com</a> ? If the answer is positive then here is my very <em>own</em> and very simple trick to do it.

All you need is a browser and the little downloader named wget. Linux users most probably have it on their systems, and windows users can get it from <a href="http://users.ugent.be/~bpuype/wget/" title="Click to download wget!" target="_blank">here</a>.

Now what this 'hack' consists of? Go to the PhotoBucket album you want to download and chose the "View All" to get a page with all the photos. Now view the source of the page and check the last "urlcodeN" where N is the total number of photos. Write down this or keep it in your mind, and paste the following script in your browsers address bar and replace the N with your number of photos.
<h6><em>javascript:var wnd=window.open("about:blank"); for(var i=0;i&lt;N;i++){ wnd.document.write(document.getElementById("urlcode"+i).value+"&lt;br&gt;"); }</em></h6>
Now press [Enter] and wait until the script finishes. It can take a few seconds.

What this script will do anyway?  First of all it will open a new window with blank contents, and it will write all the "paths" to the photos inside it, each on a new line.

Now that you have all the download paths to the photos, copy and paste the contents into a text file and open a terminal (windows users a command prompt - cmd) navigate to the directory where you saved the file with the list, and execute "wget -i saved_urls.txt" and sit back. This will download all the files. Windows users make sure that you have wget in your path else the command won't work.

It's great to create a new directory and place the "saved_urls.txt" inside that, and this way you already organized the photos.

This works 100% all the time, and you can have the photos you wanted almost with no effort.

Enjoy :-)

The script can be improved to prompt for the number of files, and this way we transformed it into a "bookmarklet" script!

Here is the improved version:
<h6><em>javascript:var n = prompt('Enter the number of photos:',0); if(n != null &amp;&amp; n &gt; 0) { var wnd=window.open("about:blank"); for(var i=0;i&lt;n;i++){ wnd.document.write(document.getElementById("urlcode"+i).value+"&lt;br&gt;"); }}</em></h6>
You can put the last version in your Firefox "bookmarks" toolbar, and have it just a click away, when you want to get some photos.

We always get what we want, because we can!
