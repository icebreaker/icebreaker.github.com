---
layout: post
title: Facebook Birthday Wishes
tags: [facebook, birthday, stats, fun, hack, fql, sphreadsheet, google]
---
On Monday it was my 26th birthday (damn!) and a bunch of people (44!) took the time
to wish me 'Happy Birthday' on Facebook.

I made an [FQL](https://developers.facebook.com/docs/technical-guides/fql/) query to extract 
this data in order to play with it just for the LoLs.

```sql
SELECT relationship_status, sex, birthday_date, current_location, devices FROM user 
WHERE uid != me() AND uid IN (SELECT actor_id FROM stream WHERE source_id = me()
AND created_time >  1360353517 AND created_time < 1360622536 LIMIT 100)
```

Without any further ado, here are (some) lovely charts plotted in [Google
Spreadsheet](https://docs.google.com/).

**Please note:** *'n/a' = no data available, due to privacy or other settings.*

![](/images/2013/02/13/gender.png)

![](/images/2013/02/13/age.png)

![](/images/2013/02/13/relationship.png)

![](/images/2013/02/13/country.png)

![](/images/2013/02/13/world.png)

![](/images/2013/02/13/mobile.png)
