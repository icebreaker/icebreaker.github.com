--- 
layout: post
title: Windows Mail high CPU utilization fix
tags: 
- cpu
- fix
- high
- intensive
- mail
- utilization
- vista
- windows
---
I know that Thunderbird is a lot more powerful than Windows Mail, but I prefer it under Windows Vista, mostly because it's simple, and I absolutely love the "Junk Mail Filter". Anyway I don't want to open a war between the two camps, and that's not the point of this post.

After some time, I noticed that once I start Windows Mail, my CPU goes to 100% and it stay there forever which obviously made the system unresponsive and very very unstable. Please note that the CPU was an single core AMD Turion ( 64bit ) running at 2.2Ghz with just 512kb as L2 cache.

I started digging around, and stumbled accross users with similar issues, but none of the suggested "solutions" solved my problem, and then I took a look under the folder where Windows Mail actually stores the files, and BOOOM!

What? There were like 10k EML files with 0kb size no subject, etc. Hmmm? I deleted them all, and started Windows Mail again, and it worked prefectly ever after. This is why it was struggling, and I have no idea how those files were created or anything, but deleting them solved the problem, and that's all what counts.

What a story huh? LoL
