---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2024
title: Amalgamation
year: 2024
month: 2
monthly: false
propaganda: 11
tags: c
---

# Amalgamation

[Amalgamation][amalgamation] is not a new thing by any means and in many ways it's the great-great-great ancestor of what we get to call today [single file or header only libraries][stb].

Now, single file libraries don't necessarily have to be *constructed* through amalgamation, but many of them are, simply because of ergonomics and ease of development.

There are a few distinct approaches that one can take on the path to achieve amalgamation, namely:

- simply concatenate **N source files** into one:
	- `cat source1.c source2.c > one.c`

- create a source file acting as an **entrypoint**, that in turn explicitly `#includes` all relevant source files and headers; and then run this file through the **preprocessor** in order to get the final **amalgamated** result:
	- `cc -E one.c -o amalgamated.c`
	- `cc -O2 amalgamated.c -o output`

- same as above, except one does not **preprocess** the source file acting as the **entrypoint**, but rather compiles it directly ***as-is***, skipping the intermediary step:
	- `cc -O2 one.c -o output`

## Lua

[Lua][lua] for instance takes route number three with the neatly tucked away [one.c][luaone.c] source file, provided as one of the lesser known *extras*, not part of the [Lua source code tarball][luasourcetarball].

So, let's take a look at how this works when it comes to [Lua][lua] by performing the following incantations:

```bash
$ wget https://www.lua.org/ftp/lua-5.4.6.tar.gz
$ tar xzvf lua-5.4.6.tar.gz
$ cd lua-5.4.6/src
$ wget https://www.lua.org/extras/5.4/one.c
$ cc -O2 -DLUA_USE_POSIX -lm one.c -o lua
$ ./lua
Lua 5.4.6  Copyright (C) 1994-2023 Lua.org, PUC-Rio
> print("Hello World")
Hello World
```

What about building a static library instead? Sure thing!

```bash
$ cc -O2 -DLUA_USE_POSIX -DMAKE_LIB -c one.c -o one.o
$ ar rcs liblua.a one.o
```

Then let's try it out and see if it's all in good working order.

```bash
$ cat > helloworld.c
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
int main(int argc, char *argv[])
{
	lua_State *L = luaL_newstate();
	if(L != NULL)
	{
		luaL_openlibs(L);
		luaL_dostring(L, "print('Hello World')");
		lua_close(L);
	}
	return 0;
}
<CTRL+D>
$ cc -O2 -DLUA_USE_POSIX helloworld.c -L. -llua -lm -o helloworld
$ ldd helloworld
linux-vdso.so.1
libm.so.6 => /usr/lib/libm.so.6
libc.so.6 => /usr/lib/libc.so.6
/lib64/ld-linux-x86-64.so.2 => /usr/lib64/ld-linux-x86-64.so.2
$ ./helloworld
Hello World
```

Even though I illustrated this on Linux, it works just as beautifully on macOS (OSX) or windows (including with your fan favorite and darling of the great peoples of the interwebs -- [MSVC][msvc]).

## Ninja

Following in the footsteps of [Lua][lua], I wanted to create a [similar source file][ninjaone.cc] for [Ninja][ninja], which would allow one to compile it easily and seamlessly without the need for any third-party tools like [cmake][cmake] or [python][python] to be present and required. All would one need is a relatively **modern** (*ugh!*) **C++** compiler.

There was one tiny little problem though. Two of the Ninja headers didn't seem to have any [include guards][includeguards] which made amalgamation impossible.

So, I took mattrs in my own hands and ended up creating a super tiny [pull request][ninjapullrequest], that added the missing include guards to the relevant header files. I didn't expect it to be approved and merged anytime soon to be honest, but surprisingly enough, it was all said and done in a matter of a few days.

With that out of the way, it was now possible to complete my experiment.

```bash
$ git clone git@github.com:ninja-build/ninja.git
$ cd ninja/src
$ wget {{ "/extras/ninja/one.cc" | absolute_url }}
$ c++ -O2 one.cc -o ninja
$ ./ninja --version
1.12.0.git
```

Once my changes end up in an official release of [Ninja][ninja], it will be possible to just download the official tarball without having to clone the actual Git repository.

And just like that, no more `cmake` or `python` needed to bootstrap [Ninja][ninja] from scratch on pretty much all the supported platforms. Pretty damn' neat, isn't it? I think so too!

[lua]: https://www.lua.org/
[luaone.c]: https://www.lua.org/extras/5.4/one.c
[ninja]: https://ninja-build.org/

[ninjaone.cc]: {{ "/extras/ninja/one.cc.html" | absolute_url }}

[ninjapullrequest]: https://github.com/ninja-build/ninja/pull/2385
[cmake]: https://cmake.org/
[python]: https://www.python.org/
[msvc]: https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B
[amalgamation]: https://sqlite.org/amalgamation.html
[stb]: https://github.com/nothings/stb
[includeguards]: https://en.wikipedia.org/wiki/Include_guard
[luasourcetarball]: https://www.lua.org/ftp/lua-5.4.6.tar.gz
