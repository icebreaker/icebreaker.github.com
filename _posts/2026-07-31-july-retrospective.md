---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2026/
title: 2026 July Retrospective
propaganda: kinoleto
music: iOvYGQtFBNM
tags: retrospective
---

2026 July Retrospective
=========================

With the second month of this big beautiful summer all wrapped up, writing this one up feels more like a *monthly newsletter* than anything else, and oddly enough I am not even covering half of all the remotely *semi-interesting topics* that came into my radar and sparked my interest.

Perhaps this is a sign that I should venture into the *monthly newsletter* business, which still seems to be well and thriving for some weird reason or another.

## The East Palace

![tep](/media/2026/tep.png)

I really don't want to cast the evil curse of the *single-season-show* on yet another series, but if you enjoyed the [Kingdom][kingdom], then you'll more than likely find yourself binging the [East Palace][eastpalace] in nothing less than a single sitting.

{% include youtube.html id="wBUkNE1l9DU" %}

If you like *ghosts*, and rather stylish *hats* that is.

## Our Machinery

![ourmachinery](/media/2026/ourmachinery.png)

I am no *interweb sleuth*, but I have to admit that one of my guilty pleasures is to do a couple of searches *every-now-and-then* around [Our Machinery][ourmachinery], in an attempt to find out more about what exactly happened before and after the *shutdown* of the company and discontinuation of the engine.

Now, there always have been quite a few theories lingering out there, some more realistic than others, but nothing concrete. Imagine my surprise when I stumbled upon the following article: [Apple's Latest Vision Pro Tool Contains Traces of Defunct Game Engine 'The Machinery'][macrumorsthemachinery]  on [MacRumors.com][macrumors] no less.

This little piece of information throws the theory of [Autodesk][autodesk] suing or buying up the company straight out of the window, which in turn ends up dragging us even further down the *sleuth* rabbit hole.

And, if you are asking why am I talking about it in *July*, when the article is from late *June*. Well, I only stumbled upon it in *July*. it's a simple as that. Not everything is an elaborate mystery, you know that right?

## Stronghold Crusader: Definitive Edition

{% include youtube.html id="epZhmaF1yfw" %}

> *More DLC is needed, my Lord!*

## Box3D

[Box3D][box3d] is finally out of the proverbial oven. It only took 20 years, but finally there's a physics engine out there that doesn't suck, and has a sane API which unsurprisingly is very similar to [Box2D][box2d].

![box3d2](/media/2026/box3d2.png)

Needless to say everybody and their grandmother seems to have jumped on it, which again is not very surprising all things considered. I haven't had a chance to play around with it too much *yet*.

{% include youtube.html id="KzFNwNQZxCM" %}

## Vartamaxxing

Are you tired of all the hardcore *euromaxxing* yet?

![varta](/media/2026/varta.png)

The news about the [insolvency of Varta][vartainsolvency] was most definitely not on my *euro-bingo* card this year.

## Paged Out: Issue #9

![pagedout9](/media/2026/pagedout9.png)

Yet another absolute *banger* [issue][pagedout9] of Paged Out has landed this month.

## AI native-web-browsers

Sometime last year, I have made a *loose promise* that I shall find the time and write a so called *"Tell us how you really feel?"* type of long form post on the subject of *ai-native-web-browsers*.

That was quite a mouthful, wasn't it? Roughly a year later, it seems like that will no longer be necessary.

This month, [OpenAI][openai] has announced rather unceremoniously, the fact that they will be [sunsetting Atlas][openaisunsetatlas].

## s&box

it has been a couple of months since [s&box][sbox] has been released, and out there in the wild, so I thought that I'd take a look at the state of things. I was especially interested if any steps or progress have been made towards making the *editor* usable with [Proton][proton].

Sadly, the answer is a resounding no. Now, I did manage to get it running by performing a couple of minor incantations by using [protontricks][protonticks], which greatly simplifies dealing with Proton *prefixes*.

First, I had to install version `10` of the `.NET runtime`, the installer for which can be located over at `_redist/dotnet-runtime-10.0.0-win-x64.exe`, so there's no need to download it separately.

It should be fairly trivial and straightforward to add an `install.vdf` definition file for the editor as well; which would make this manual installation step completely unnecessary.

```json
"InstallScript"
{
	"Run Process"
	{
		"DotNetRuntime1000"
		{
			"Process 1"     "%INSTALLDIR%\\_redist\\dotnet-runtime-10.0.0-win-x64.exe"
			"Command 1"     "/passive /install"
			"NoCleanUp"     "1"
		}
	}
}
```

Second, I had to run `winecfg` and disable the `Allow the window manager to decorate the windows` option, which is necessary to get the *custom chrome* in good working order.

With these two steps out of the way, the editor does launch, and it *kind of* works.

![sbox1](/media/2026/sbox1.png)

![sbox2](/media/2026/sbox2.png)

### MCP Server

While doing all this, I noticed that it got an [MCP server][mcpserver], which can you take a look at by clicking [here][sboxmcp].

My opinion when it comes to `MCP servers` hasn't really changed since last time I talked about them. I still think that they are solution looking for a problem, very much like [GraphQL][graphql]. Especially today, when it's trivial and much more preferred to just let an agent call out to any `API` directly or to use a `CLI` tool.

Nonetheless, I thought that I'd use this implementation to call out a couple of aspects and things to watch out for if you must build one on your own for whatever reason.

If we awe a gander at `engine/Sandbox.Tools/Mcp/McpServer.cs`, we stumble upon the following absolute and total gems:

```cs
/// <summary>
/// Protocol revisions we can speak, newest first. If the client asks for 
/// something we don't know we answer with the newest and let it decide.
/// </summary>
static readonly string[] SupportedProtocolVersions = [
    "2025-11-25",
    "2025-06-18",
    "2025-03-26",
    "2024-11-05"
];

// ...
try
{   
	message = JsonSerializer.Deserialize<JsonRpcMessage>( body );
}   
catch ( JsonException )
{   
	// JSON-RPC batches (arrays) were removed in protocol revision 2025-06-18
	var error = body.AsSpan().TrimStart().StartsWith( "[" )
        ? JsonRpcResponse.Failure( null, JsonRpcError.InvalidRequest, "Batching is not supported" )
        : JsonRpcResponse.Failure( null, JsonRpcError.ParseError, "Parse error" );

	WriteJson( response, HttpStatusCode.BadRequest, error );
	return;
}
```

Did I mention already that `MCP` as a whole concept is a terrible idea? I did? Alright, I'll shut up then.

Now, let's look at something that is a bit more interesting inside the `HandleRequest` function:

```csharp
// ...
if(request.Headers["Origin"] is string origin && !IsLoopbackOrigin(origin))
{
	response.StatusCode = (int) HttpStatusCode.Forbidden;
	return;
}
// ...
```

This verification step is an absolute must-have for any (*desktop*) application that is exposing an `HTTP` server of any kind running on `localhost`, even if said server supports and requires authentication.

Another equally important thing is not relying on the `Content-Length` header, reading the request payload in reasonable chunks, and finally imposing a hard maximum payload size, all of which can be found inside the `ReadBody` function:

```cs
// ...
const long MaxRequestSize = 8 * 1024 * 1024;

while((read = await request.InputStream.ReadAsync(chunk)) > 0) 
{   
	buffer.Write(chunk, 0, read);

	if(buffer.Length > MaxRequestSize)
		return null;
}
// ...
```

Overall, If you are thinking about adding an `MCP` server into your very own *game-dev-toolchain*, this is quite  solid example to draw inspiration from.

## **The Java Story**

{% include youtube.html id="ZqGSg4b_cZA" %}

These folks are most definitely some of the most prolific documentary makers out there.

## Exorcist: The Two Prequels

The [Exorcist][exorcist] is one of my all time favorite horror franchises out there. Most certainly within my top ten. Even so, I didn't realize until relatively recently that a sequel to the first entry in series ended up being so bad that it ended up being produced and released twice.

Wait, what? It's all quite confusing to be perfectly honest with you. I am talking about [Exorcist: The Beginning][exorcistthebeginning], and [Dominion: Prequel to the Exorcist][domonionprequelexorcist] of course; released in `2004` and `2005` respectively.

{% include youtube.html id="vIoqCIbQ8H8" %}

{% include youtube.html id="HbMF4fPeuzY" %}

## Vampirium: 1997

![v97](/media/2026/v97.png)

Do you remember the day when some very *British*, and very *opinionated rectangles* (*why, am I repeating myself?*), managed to take over the charts at the tail end of the *great indie-resurrection* of the early 2010s?

![twa](/media/2026/twa.png)

I am talking about [Thomas Was Alone][thomaswaslone] of course. [Vampirium: 1997][vampirium1997] seems to me to have inherited at least some of the very same *spiritual elements*. Back to the basics, right?

{% include youtube.html id="uYvxoPzonEw" %}

Not my type of a game *per se*, but I will be most definitely keeping an eye on it.

## IMP

It felt only natural to follow up last months' entry with another one from the depths of my archives written in Delphi around the same time period.

![imp](/media/2026/imp.png)

As you can see, I really must have liked that `skinning component` very much, what can I say?

Look at this beautiful code-snippet below that I have curated and pulled out just for you.

```pascal
type
  TID3Rec = packed record
    Tag     : array[0..2] of Char;
    Title,
    Artist,
    Comment,
    Album   : array[0..29] of Char;
    Year    : array[0..3] of Char;
    Genre   : Byte;
  end;
  
procedure FillMp3Tags(var temp:TID3REC;filename:string);
var fMp3:File;
begin
 try
   AssignFile(fMP3, filename);
   Reset(fMP3,1);
   try
     Seek(fMP3, FileSize(fMP3) - 128);
     BlockRead(fMP3, temp, SizeOf(temp));
   finally
   end;
 finally
   CloseFile(fMP3);
 end;
end;
```

Just `FileSize(fMP3) - 128` without any care or worry in the world. Oh to be young again, right?

![salmon4](/media/2026/fishart/salmon4.png)

To make it *sing*, it looks like I used the [BASS][bass] audio library.

```bash
$ winedump bass.dll | head
Contents of bass.dll: 102284 bytes

File Header
  Machine:                      014C (i386)
  Number of Sections:           2
  TimeDateStamp:                3EF08DAC (Wed Jun 18 19:05:00 2003)
  PointerToSymbolTable:         00000000
  NumberOfSymbols:              00000000
  SizeOfOptionalHeader:         00E0
  Characteristics:              210E
```

## Dark Matter: Season 2

{% include youtube.html id="zhB6_1UbR7s" %}

I do hope that most people haven't moved on by now. `2024` was a long time ago, and I would be very surprised if this will get another season.

## Halls of Tornment: The Lost Archives

![hottadlc](/media/2026/hottadlc.png)

I always considered [Halls of Tornment][hallsoftornment] to be one of the best [Vampire Survivors][vs] clones out there bar none; and, now that a new content drop is on its way in the form of [The Lost Archives][thelostarchives], I thought that it's high time that I mention it again.

{% include youtube.html id="cAoCel3FBOI" %}

## Blade Runner 2099: Rings of Power

{% include youtube.html id="0Dr8I_RyRCg" %}

## Drop Loot

![droploot](/media/2026/droploot.png)

Are you ready for another game for the *monkey-brain*?. If the answer to that question is a yes, then give the demo of [Drop Loot][droploot] a try.

## Pomegranate

Look, I am fully aware that this is rather touchy and delicate subject. Let me be perfectly clear by stating that I am not here to open the floodgates, nor am I here to condone or promote anything. Okay?

{% include youtube.html id="fyZhC2TXgcs" %}

## The "Sackhoff" Show

![starbuck](/media/2026/starbuck.png)

{% include youtube.html id="_gM4f9uTEzw" %}

{% include youtube.html id="zRYlCTUueWg" %}

{% include youtube.html id="m8xIIOC8CBo" %}

{% include youtube.html id="dOCpS3Rw8-I" %}

{% include youtube.html id="BnT2C2lP0-s" %}

## Monthly Amazon "*Book Review*"

![oglsb](/media/2026/oglsb.png)

I bought a physical copy of the [OpenGL SuperBible][openglsuperbible] (*Fifth Edition*) at the tail end of 2010 or thereabouts.

![oglsbrev2](/media/2026/oglsbrev2.png)

![oglsbrev1](/media/2026/oglsbrev1.png)

I'll let the reviews speak for themselves as per usual. Enough said!

## Monthly *"Coup de cœur"*

Decided to follow up last months' entry with yet another production by [Moppi Productions][moppi] called [Halla][halla].

{% include youtube.html id="DsbEny9XBBQ" %}

Please enjoy the show, and don't forget to try the fish!

[moppi]: https://www.pouet.net/groups.php?which=90
[halla]: https://www.pouet.net/prod.php?which=7132
[kingdom]: https://en.wikipedia.org/wiki/Kingdom_(South_Korean_TV_series)
[eastpalace]: https://en.wikipedia.org/wiki/The_East_Palace
[ourmachinery]: https://www.crunchbase.com/organization/our-machinery
[autodesk]: https://en.wikipedia.org/wiki/Autodesk
[macrumorsthemachinery]: https://www.macrumors.com/2026/06/23/apple-reality-composer-pro-the-machinery/
[macrumors]: https://en.wikipedia.org/wiki/MacRumors
[vartainsolvency]: https://www.euronews.com/business/2026/07/27/varta-files-for-insolvency-as-german-battery-makers-crisis-deepens
[box3d]: https://github.com/erincatto/box3d
[box2d]: https://github.com/erincatto/box2d
[pagedout9]: https://pagedout.institute/webview.php?issue=9&amp;page=1
[openaisunsetatlas]: https://openai.com/index/chatgpt-for-your-most-ambitious-work/
[openai]: https://en.wikipedia.org/wiki/OpenAI
[proton]: https://en.wikipedia.org/wiki/Proton_(software)
[sbox]: https://en.wikipedia.org/wiki/S%26box
[protonticks]: https://github.com/matoking/protontricks
[mcpserver]: https://en.wikipedia.org/wiki/Model_Context_Protocol
[sboxmcp]: https://github.com/Facepunch/sbox-public/tree/master/engine/Sandbox.Tools/Mcp
[graphql]: https://en.wikipedia.org/wiki/GraphQL
[exorcist]: https://en.wikipedia.org/wiki/The_Exorcist
[exorcistthebeginning]: https://en.wikipedia.org/wiki/Exorcist:_The_Beginning
[domonionprequelexorcist]: https://en.wikipedia.org/wiki/Dominion:_Prequel_to_the_Exorcist
[thomaswaslone]: https://en.wikipedia.org/wiki/Thomas_Was_Alone
[vampirium1997]: https://store.steampowered.com/app/4035190/Vampirium_1997/
[bass]: https://www.un4seen.com/
[hallsoftornment]: https://en.wikipedia.org/wiki/Halls_of_Torment
[vs]: https://en.wikipedia.org/wiki/Vampire_Survivors
[thelostarchives]: https://steamcommunity.com/app/2218750/eventcomments/588432892837981272
[droploot]: https://johnreno.itch.io/droploot
[openglsuperbible]: https://www.amazon.com/dp/0321712617
