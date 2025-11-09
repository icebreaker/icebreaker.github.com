---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2024
title: 2024 April Retrospective
propaganda: rustysretirement
class: blood grinch
tags: retrospective
---

# 2024 April Retrospective

Continuing with the tradition of talking about a fresh or interesting indie games, I'd like to point out [Rusty's Retriment][rustysretirement], which came fresh out of the oven at the tail end of the month.

Now, I am not a fan of the so called *"cozy game genre"*, but this one happens to be the proverbial exception that enforces and solidifies the rule itself, I guess.

{% include youtube.html id="_EjvV4c8on8" %}

Based on the [Gamalytic][gamalytic] data and the [author's][rustyauthor] own [tweets][rustytweet], it appears that the game has been a commercial success already, mere days since its launch; which is a really thing nice to hear, because it truly is a labor of love.

Give it a try, even if you do not fancy *cozy games* like myself. Besides, it's 10% off until the 7th of May.

## Rebel Moon

I also ended up watching the second part of [Rebel Moon][rebelmoon], and it didn't really change my opinion about how this should have been a series, instead of some long form two part movie-type-thingamajig.

{% include youtube.html id="fhr3MzT6exg" %}

{% include youtube.html id="UEJuNHOd8Dw" %}

If you were expecting any particular salacious comments, sorry to disappoint you, but you'll have to look elsewhere on the great information super-highway.

## Cursed Makefile Techniques

This is really in the ***"Kids, do not attempt this at home!"*** category, but I thought that I'd share it here anyway, just in case someone might stumble upon it and find it useful.

It turns out that it's possible to craft a `Makefile` that is compatible with both [(*GNU*) make][gnumake] and Microsoft's [Nmake][nmake].  Now, why would anyone want such a cursed combination that could accidentally summon the four horsemen of the apocalypse? The answer to that question is for reasons! Very mature, I know.

### test.c

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Cursed Makefile Techniques ...\n");
    return 0;
}
```

### Makefile

```makefile
TARGET = test
SOURCE = test.c

# Kids, do not attempt this at home! \
!ifndef __GNU__SLASH__MAKE__ # \
!include mk/nmake.mk # \
!else
include mk/make.mk
# \
!endif
```

### mk/make.mk

```makefile
# MSYS2 and Cygwin
ifdef COMSPEC
CC := x86_64-w64-mingw32-gcc
TARGET := $(TARGET).exe
endif

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(SOURCE) -o $@

clean:
	$(RM) $(TARGET)

.PHONY: all clean
```

### mk/nmake.mk

```makefile
TARGET = $(TARGET).exe

all: $(TARGET)

$(TARGET): $(SOURCE)
	cl /nologo $(SOURCE) /link /out:$@

clean:
	del /Q $(TARGET)

.PHONY: all clean
```

This whole *"trick"* works because `make` respects the `\` character inside comments (lines starting with `#`) while, `nmake` does not. It's really as simple as that.

If you have a relatively small project, it can come in handy; because it allows you to just type `make` or `nmake` to build, without having to install additional tools or type in crazy incantations.

## Monthly Archive

As per usual, you can find a collection of my random monthly scribblings and musings below.

{% include posts.html year="2024" month="4" retrospective="false" reverse="true" %}

I know that it's not much, but it's honest work.

[gamalytic]: https://gamalytic.com/game/2666510
[gnumake]: https://www.gnu.org/software/make/manual/make.html
[nmake]: https://learn.microsoft.com/en-us/cpp/build/reference/nmake-reference?view=msvc-170
[rebelmoon]: https://en.wikipedia.org/wiki/Rebel_Moon
[rustytweet]: https://twitter.com/MrMorrisGames/status/1785388610318901645
[rustyauthor]: https://twitter.com/MrMorrisGames
[rustysretirement]: https://store.steampowered.com/app/2666510/Rustys_Retirement/
