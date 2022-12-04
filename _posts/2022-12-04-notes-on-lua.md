---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2022
title: Notes on Lua
propaganda: 2
---

Notes on Lua
=========================

Avid readers of my blog and followers of mine probably can tell by now that most of my personal projects are written in C and Lua.

Would these be the the languages I'd take with me if I had to leave on a deserted island? The answer to that is a resounding yes.

Some orthodox C++, JS or even 16-bit assembly might rear their ugly head every now and then, but those instances can be considered the exceptions rather than rules.

What the heck is orthodox C++? If you asked that question, then you are in luck because I just happen to know the location of this [perfect place][orthodoxcpp], where you'll find the answers you've been looking for your entire life. 

With that said, I thought that I'd put together some notes on Lua in the hopes that it might help total newcomers, as well as people who might have dabbled with it to a certain extent in the past, but then decided not to go with it for one reason or another.

2022 is really the year of second chances, therefore perhaps these notes might change your mind and you'll give Lua another try.

Lua is really an excellent companion language and one of the best (if not the best) languages out there for making your games and apps script-able.

It's one of those languages where embeddability isn't just an after thought or an unintended happy consequence, but it's actually a core part of the language.

If I had to describe Lua in three words, I'd probably say something along the lines of compact, fast and flexible.

Without any further ado, let's get started.

## Non-zero index based arrays

When talking about Lua, one of the first, if not the absolute first thing that comes up is the non-zero index based arrays.

Languages where arrays start at `1` instead of `0` are evil and yada, yada! You probably heard this spiel a million times over.

While, this is a totally valid point to discuss, it's really not that big of a deal as it might appear to the unsuspecting eye.

Why? Well, first of all nothing stops you from using 0 as an index in the first place so long you are aware of the implications of doing so.

```lua
local t = {}

for i=0,3 do
	t[i] = i
end
```

The code above is perfectly valid Lua.  Now, what are the caveats or the implications?

- can't use `#t` because the length will not take into count the element at index 0
- can't use the `ipairs(t)` iterator, because once again it will skip the element at index 0

But, once again this is truly a non-issue for all intents and purposes. The mental shift that people say that is required is an imaginary one. Take my word for it.

When would you actually need zero based array indexing? I can think of two specific scenarios.

- working with binary data and offsets
- working with level/map data that you want to index into by turning `x`, `y` coordinates into an array index

In both of these cases you could really just do a `+1` and everything would be just fine. On the other hand, you will most likely have a higher level interface that is more convenient to use rather than litter the entire code-base with inline `index` or `offset` computations.

If this was **THE MAJOR THING** that has been preventing you from trying out Lua, just ignore it and you might find yourself pleasantly surprised.

## Procedural vs Functional vs OOP

Another thing that is sometimes brought up as kind of a negative when it comes to Lua is the fact that it doesn't really forces you to pick and/or use any particular so called *design patterns* or *styles*.

Obviously, Lua is not the only language out there that does this, but I feel like Lua is still special in some ways when it comes to this because of its dynamic nature. 

I also consider this fact to be one its strengths rather than shortcomings.

### Procedural

Let's take a look at a purely procedural way of doing things first.

```lua
function init_monster(t)
	t.health = 100
	t.speed = 50
	t.position = { x = 0, y = 0 }
end

function move_monster(t)
	local p = t.position
	p.x = p.x + t.speed
	p.y = p.y + t.speed
end

local t = {}
init_monster(t)
move_monster(t)
```

Another variation on this theme could something like this:

```lua
function create_monster()
	local t = {
		health = 100,
		speed = 50,
		position = { x = 0, y = 0 }     
	}
	return t
end

local t = create_monster()
move_monster(t)
```

One could also do away with the so called `constructor` altogether and just declare the table inline.

```lua
local t = {
	health = 100,
	speed = 50,
	position = { x = 0, y = 0 }     
}

move_monster(t)
```

Alternatively, one could also use a combination of inline declaration and an anonymous function.

```lua
local t = (function()
	return {
		health = 100,
		speed = 50,
		position = { x = 0, y = 0 }     
	}
)()
    
move_monster(t)
```

### Functional

What about all that totally amaze-balls functional hotness? No problem at all, Lua got you covered.

```lua
function map(t, f)
	local result = {}

	for i, v in ipairs(t) do
		result[i] = f(v, i)
	end
    
	return result
end

function create_monster(id)
	local t = {
		id = id,
		health = 100,
		speed = 50,
		position = { x = 0, y = 0 }     
	}
	return t
end

function move_monster(t)
	local p = t.position
    
	p.x = p.x + t.speed
	p.y = p.y + t.speed
    
	return t
end

function add_log(message, f)
	return function(v)
		print(message, v.id)
		return f(v)
	end
end

map(
	map(
		{ 1, 2, 3 },
		create_monster
	),
	add_log(
		"moving monster",
		move_monster
	)
)
```

### OOP

And now, what everybody has been waiting for. Drum-rolls! Object Oriented Programming, or Brain Damage Oriented Programming as I like to call it these days.

Once your mind has been infested with the OOP paradigm it's always impossible to rid of it, at least not without significant efforts.

```lua
local CLASS_METATABLE <const> = {
	__call = function(self, ...)
		local instance = setmetatable({}, self)
        
		if type(instance.init) == "function" then
			instance:init(...)
		end
        
		return instance
	end
}

function class(klass, super_klass)
	local klass = klass or {}
    
	for k, v in pairs(super_klass or {}) do
		klass[k] = v   	    
	end
    
	klass.__index = klass
	return setmetatable(klass, CLASS_METATABLE)
end

Monster = class(Monster)
Monster.init = function(self, name, kind, speed)
	self.name = name
	self.kind = kind
	self.speed = speed or 5
	self.position = { x = 0, y = 0 }
    
	return self
end
Monster.move = function(self, x, y)
	local p = self.position
	local speed = self.speed
    
	p.x = p.x + speed
	p.y = p.y + speed
    
	return self
end

Zombie = class(Zombie, Monster)
Zombie.init = function(self, name)
	return Monster.init(self, name, "zombie")
end
Zombie.print = function(self)
	print(self.kind, self.name)
	return self
end

local zombie = Zombie("peter")
zombie:move():print()
```

### DSL

Now, what if you want a DSL to describe your monster types in a nice data-oriented fashion? Lua really shines when it comes to this, considering that it has its roots as a data description language of sorts.

```lua
local MONSTER_TYPE_METATABLE <const> = {
	__call = function(self, t)
		assert(t.name ~= nil, "monster type needs a valid name")
		assert(self[t.name] == nil, "duplicate monster type")
    
		self[t.name] = t
		table.insert(self, t)
        
		return t
	end
}

monster = setmetatable({}, MONSTER_TYPE_METATABLE)

monster {
	name = "zombie",
	speed = 5
}

monster {
	name = "ogre",
	speed = 15
}

for _, v in ipairs(monster) do
	print(v.name, v.speed)    
end

print("ogre speed", monster.ogre.speed)
```

One nice feature that makes this possible is that the `paranthesis` around functions can be omitted if said function has a single `string` or `table` argument.

This feature makes Lua perfect for creating DSLs of all sorts.

## Metatables and Metamethods

Both **OOP** and **DSL** examples above made use of so called `metatables` as well as `metamethods` in the form of `__call` in order to achieve the desired and necessary syntactic sugar.

A metatable is table that contains one or more metamethods and then is set as the metatable of another table.

Any given table at any given time can have a single metatable associated with it, which can be set and retrieved by `setmetable` and `getmetable` respectively.

A prime example that I always like to give to illustrate the concept is defining a metatable that implements the `__tostring` metamethod in order to provide pretty-printing capabilities.

```lua
local sprintf = string.format

local METATABLE <const> = {
	__tostring = function(self)
		return sprintf("{ x = %d, y = %d }", self.x, self.y)
	end
}

t = setmetatable({ x = 11, y = 22 }, METATABLE)
print(t)
```

With this setup, `print(t)` will print out `{ x = 11, y = 22 }` instead of `table: 0xdeadbeef`.

Even if you do not intend to do any heavy meta-programming like in the examples given above, you should still take the time and familiarize yourself with the concept of metatables and metamethods.

You can learn more about metatables and metamethods by clicking [here][meta].

## Coroutines

Lua comes with support for coroutines out of the box. I won't go into a lot of details and will provide only a relatively simple and easy to understand example below.

```lua
function monster_wait(self, amount)
	local t = 0
	while t < amount do
		coroutine.yield()
		t = t + sys.delta_time 
	end
end

function monster_think(self, dt)
	while true do
		local player = monster_find_player(self)
        
		if player then
			print('shooting at player')
			monster_shoot_at_player(self, player)
		end
       
		monster_wait(self, 0.5)
	end
end

local t = create_monster()
local co = coroutine.create(monster_think)
coroutine.resume(co, t, dt)
coroutine.resume(co, t, dt)
coroutine.resume(co, t, dt)
```

One interesting thing to note here is that one can `yield` anywhere from within the coroutine, even from another function as illustrated by the `monster_wait` function.

You can learn more about coroutines by clicking [here][coro].

## Modules and Packages

Lua doesn't have any special keywords or language features per-say when it comes to providing support for modules and packages alike.

If you think about it, both modules and packages are just Lua tables containing functions.

```lua
local math = require "math"
print(math.pi)
```

Sometimes the words `library`, `module` and `package` are used interchangeably when referring to modules.

So, how is this implemented behind the scenes?

The `require` function, which is just a good old regular function, ends up looking for the required module or package by parsing two variables. Namely `package.path` and `package.cpath`.

```lua
> package.path
./?.lua;./?/init.lua
> package.cpath
./?.so
```

What is the difference between `path` and `cpath`? I am pretty sure that you guessed already, `cpath` is used to look for Lua native extensions in the form of dynamic linking libraries or shared objects, while `path` is exclusively for looking up Lua source files, including pre-compiled ones with `luac` given that they still use `.lua` as an extension.

There's no real difference as far as the `user` is concerned between the two. You just call `require` and whatever matches first will be returned, or if the given module cannot be found in either paths an error that indicates this fact will be raised.

It should go without saying that both of these variables can be modified at run-time and the changes will take effect the next time `require` is called with module name that hasn't been loaded or required previously.

Another interesting bit of trivia that I'd like to mention is the fact that by looking at the directory separator one can determine the platform the Lua interpreter. On Windows this is going to be `\` and on Unix-likes it's going to be `/` obviously.

This *trick* is sometimes used in Lua scripts designed to be executed via the command line Lua interpreter, also known as `lua` or `lua.exe` respectively.

If you have a Lua script called `monster.lua` then you just require it like this.

```lua
-- without parenthesis
local monster = require "monster"

-- with parenthesis
local zombie = require("zombie")
```

Of course this assumes that your `monster.lua` looks something like this.

```lua
local M = {}

M.create = function(name)
	return { name = name }
end

return M
```

What about packages? If you have a directory called `monster` with a Lua script called `init.lua` in it, then once again you just require the same way.

```lua
local monster = require "monster"
```

This in in turn will `load` the `init.lua` from within that directory.

Remember that `monster.lua` takes priority over `monster/init.lua` as per the patterns defined in `package.path`, so if you happen to have both of them within the very same directory, it will end up requiring `monster.lua` instead.

What if you want to be able to `require` from other *sources* like a ZIP archived backed virtual file system?

You can create your own custom loader and insert into `package.loaders` before or after the default loader as you see fit as illustrated in the example below.

```lua
function create_zip_archive_loader(archive_filename)
    local archive = assert(zip.open(archive_filename, "r"))
    
    return function(name)
        local filename = string.format(
            "%s.lua",
            string.gsub(name, "%.", "/")
        )

        local contents = archive:read(filename)
        if contents then
            return assert(loadstring(contents, filename))
        end

        return string.format(
            "could not find '%s' in zip archive '%s'",
            filename,
            archive_filename
        )
    end
end

table.insert(package.loaders, 2, create_zip_archive_loader("scripts.zip"))
```

Not too shabby right?

In most cases you will really want to just roll your own import, especially when it comes to games where you will also want sandboxing and you are almost always going to be `loading` from a virtual file system of some description.

With all that being said, I'd recommend creating your own `import` function and exposing that instead of the built-in `require`.

```lua
function create_import(archive_filename)
    local archive = assert(zip.open(archive_filename, "r"))
    
    return function(name)
        local filename = string.format(
            "%s.lua",
            string.gsub(name, "%.", "/")
        )
        local contents = assert(archive:read(filename))
        return assert(loadstring(contents, filename))
   	end
end

import = create_import("scripts.zip")

-- use it just like you would the built-in `require`
local monster = import "monster"
```

## Sandboxing

Sandboxing is another thing that Lua can do without the need for any complicated or fancy language features.

If you worked with Lua before you probably stumbled upon the mysterious `_G` table, which is really an alias to the table that serves as the global environment when the `lua_State` is first createda nd initialized.

Any global variables or functions that one defines will end up in this table. The alias is provided for convenience purposes, more exactly cases like these:

- enumerating all globally defined variables or functions
- interacting in some unusual way with the global environment from within a nested scope

As a result, sandboxing in its most basic and pure form is simply a matter of `shadowing` the global environment table with another table called `_ENV` defined in the local scope.

```lua
function sandbox()
	local _ENV = {
        print = print
    }
    
    return function(message)
    	print(message)
        print(_VERSION)
    end
end

sandbox()("hello world")
```

If you run this, you'll see that it will print `hello world` and `nil`, because the global constant `_VERSION` wasn't included in the `_ENV` table thus it is not accessible from within the returned function. Which is really a closure, but more on that later.

In most real world scenarios however, you'll probably never set `_ENV` by hand and let `loadstring` or `loadfile` do it internally while loading the desired `chunk` and setting its `upvalue` to the desired environment.

And now, I am going to illustrate sandboxing via `loadfile` by combining the `DSL` and  `import` examples shown above in order to give you a more realistic approach on how one would go about it.

```lua
local MONSTER_TYPE_METATABLE <const> = {
	__call = function(self, t)
		assert(t.name ~= nil, "monster type needs a valid name")
		assert(self[t.name] == nil, "duplicate monster type")
    
		self[t.name] = t
		table.insert(self, t)
        
		return t
    end
}

function create_monster_importer()
	local env = {
		monster = setmetatable({}, MONSTER_TYPE_METATABLE),
		print = print
	}

	env.import = function(name)
		local filename = string.format(
			"%s.lua",
			string.gsub(name, "%.", "/")
		)
		local chunk = assert(loadfile(filename, "tb", env))
		return chunk()
	end
    
	return env
end

local monster_importer = create_monster_importer()

monster_importer:import("monsters/ogre")
monster_importer:import("monsters/zombie")

for i, v in ipairs(monster_importer.monster) do
	print(i, v.name, v.speed)    
end
```

Then `monsters/ogre.lua` could look like this.

```lua
monster {
    name = "ogre",
    speed = 15
}

monster {
    name = "zombie_boss",
    speed = 20
}
```

And finally `monsters/zombie.lua` which is more of the same but in a different Lua script.

```lua
monster {
    name = "zombie",
    speed = 5
}

monster {
    name = "zombie_boss",
    speed = 10
}
```

Please note how we pass in the `env` table as the last argument of `loadfile`. The `loadstring` function supports the same arguments as well and can be used in the same manner.

This `env` table ends up overriding the global environment by altering the `upvalue` of the loaded chunk and only the functions and/or variables defined within said table will be available within said chunk when executed.

In other words, trying to call any other functions than `monster`, `print` and `import` will result in an error, simply because nothing else has been defined in the `env` table.

Also, any variables, functions that might be defined within the loaded chunks, they also end up in the `env` table rather than the global environment table.

Obviously, if we are talking about user generated content like in the case of [Roblox][roblox], then obviously additional measures have to taken, like preventing infinite loops and so forth, but in most other locally moddable games and/or apps, this is more than sufficient to provide a safe, intuitive and a super convenient data-driven way to define configuration, entities, levels, maps and so on.

## C <-> Lua interaction

I feel like we traveled down far enough through the proverbial rabbit hole at this point to bring the bi-directional interaction between C and Lua to the table in the context of embedding the Lua interpreter inside a game or an application.

Considering that this is quite a big topic to tackle, I'll try to be as concise as possible without sacrificing too much in terms of details that are important to gain a better understanding of how things are glued together.

What I noticed is that most people end up under or over exposing and never really taking the time to find just the right balance that actually make sense and feels what I like to call *Lua-like* for whatever its worth.

The over exposing is generally done by people who happen be using C++. Which of course is to be expected, considering that any prolonged exposure to C++ or OOP in general is well known to cause permanent and irreversible brain damage.

It's never ever desirable to expose C++ classes 1:1 in a purely OOP fashion. I am not your mum, and I can't tell you what to do with your adult life, but **PRETTY PLEASE, DO NOT EVER DO THIS**, if for nothing else but respect for you fellow human beings you happen to be sharing this piece of rock floating in space with.

And even more importantly, do not use one of those *"auto-class-binding generator"* like libraries. If your mind just took you to a very dark place called BOOST, please find the nearest church and pour some holy water on over your head, but it might be too late, so please don't hold your breath.

Writing your own `bindings` by hand is the way to go, even if it might look intimidating at first glance.

### Calling Lua functions from C

However, before go into all that let's take a look at how one would go about calling Lua functions from C.

In the case of a game, if you have done things right, you do not ever really need more than 3 global functions to serve as trusty entry points into the world of Lua.

By taking this route, you make it very easy to profile how much time is spent in Lua every frame, which is a very important and rather convenient side effect to consider.

```lua
local escape_key = nil

function on_init(argv)
    -- call once on init
    escape_key = input_key_index("escape")
end

function on_frame(dt, w, h)
    -- called once every frame
    if input_key_pressed(escape_key) then
		print("key pressed") 
    end
end

function on_quit()
	-- called once on quit    
end
```

On the `C` side of things, you create your `lua_State` and then lookup and call the 3 functions.

Proper error handling has been largely omitted for purposes of brevity.

```c
lua_State *L = luaL_newstate();
if(L == NULL)
{
    // fatal error failed to create Lua state
    return -1;
}
// load and initialize the Lua standard library
luaL_openlibs(L);

if(!script_on_init(L, argc, argv))
{
    // fatal error so just return early
    return -1;
}

while(running)
{
    double dt = /* calculate delta time in ms/sec */;
    
    process_os_events();
    
    script_on_frame(L, dt, w, h);
    
    // swap GL buffers
    // vsync and/or apply frame limiting
}

script_on_quit(L);

lua_close(L);
L = NULL;
```

Now, you might be tempted to ask, should one even call `process_os_events()` on in C or simply expose it to Lua and then let the user decide if they care about processing events during any particular frame, or perhaps also pick and choose which events they might want to process.

This would also mean that one doesn't have to change the change and recompile the C side of things in situations where certain events are irrelevant for the current game. For example, if the game doesn't support joysticks, then there's no reason to process anything joystick related.

```lua
function on_frame(dt, w, h)
	for event in poll_events() do
		if event.type == EVENT_TYPE_KEYDOWN && event.key == 27 then
    		print("key pressed")  
		end
	end
end
```

Both approaches have their pros and cons. I'll let you make up your own mind about which one resonates more with your particular style and needs.

Alright, but how do you actually call any of these Lua functions from C (the host game/application)?

```c
bool script_on_init(lua_State *L, const int argc, const char *argv[])
{
    int i, ret;
        
 	if(lua_getglobal(L, "on_init") != LUA_TFUNCTION)
    {
        lua_pop(L, 1);
        return false;
    }
    
   	lua_createtable(L, argc, 0);
    for(i = 0; i < argc; i++) 
    {    
        lua_pushstring(L, argv[i]);
        lua_rawseti(L, -2, i);
    }
    
    ret = lua_pcall(L, 1 /* one argument */, 0, 0);
    if(ret != 0)
    {
        fprintf(stderr, "Lua Error:\n%s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
        return false;
    }
    
    return true;
}
```

Alright, I admit it that there's a lot going on and I'll try to point everything out almost in a line by line fashion, so bear with me. It will be worth it in the end.

The first order of business is to lookup the `on_init` function by name in the global environment, which should sound familiar since I mentioned it briefly when I talked about sandboxing above.

```c
if(lua_getglobal(L, "on_init") != LUA_TFUNCTION)
{
	lua_pop(L, 1);
    return false;
}
```

This is done by using the `lua_getglobal` function, which conveniently pushes the value of the key `"on_init"` into the stack and then returns the type of said value.

Before going much further, it's worth noting that the Lua C API is stack based, which means that one interacts with the `lua_State` by pushing and popping values into and from aforementioned stack.

Values pushed into the stack can be referred to by a numeric index. This index can be positive or negative.

A positive index can be used to refer to values from the bottom of the stack going in an upwards direction, while a negative index can be used to refer to values from the top of the stack going in a downwards direction.

So let's rewrite the above piece of code in a slightly different way to illusrate the use of a negative index when referring to a value at the top of stack, which translates to index `-1`.

```c
lua_getglobal(L, "on_init");
if(!lua_isfunction(L, -1))
{
	lua_pop(L, 1);
    return false;
}
```

Here we ignore the return value of `lua_getglobal` and use the `lua_isfunction` to find out if the value pushed into the top of the stack by `lua_getglobal` is of type `LUA_TFUNCTION`.

The usage of `lua_pop` should be self explanatory and it is simply used to pop values off the top of he stack.

One important distinction to note here is that the second argument is the actual count of values to pop and it doesn't represent a stack index.

Now there's a third way to rewrite this lookup that we just did which also illustrates popping two values of the top of the stack in one fell swoop.

```c
lua_pushglobaltable(L);
if(lua_getfield(L, -1, "on_init") != LUA_TFUNCTION)
{
    lua_pop(L, 2);
    return false;
}
lua_pop(L, 1);
```

Of course we could also just ignore th return value of `lua_getfield` and then use `lua_isfunction` in order to determine the type of said value just like we did in the previous implementation.

Speaking of `lua_isfunction`, I want to point out that the fact that it's just a good old fashioned convenience macro, which expands to an expression making use of the `lua_type` function.

```c
#define lua_isfunction(L, n) (lua_type(L, (n)) == LUA_TFUNCTION)
```

Alright, let's take a look at a forth variation of the lookup.

```c
lua_pushglobaltable(L);
lua_pushstring(L, "on_init");
if(lua_gettable(L, -2) != LUA_TFUNCTION)
{
    lua_pop(L, 2);
	return false;   
}
lua_pop(L, 1);
```

Wait a minute, why are we still popping 2 and then 1 off the stack? Shouldn't we also account for the value pushed by `lua_pushstring`?

No, because `lua_gettable` pops it off the stack and then pushes the resulting value of the lookup in its place.

Instead of `lua_pushstring` could have also used `lua_pushliteral` which is another macro that ensures that its argument is a compile-time constant string literal and not a run-time variable.

```c
#define lua_pushliteral(L, s) lua_pushstring(L, "" s)
```

This is done by the means of a preprocessor trick that makes the compiler throw an error when `s` is not a compile-time constant string literal.

How does it do that? Well, we know that the preprocessor is kind enough and happens concatenate adjacent compile-time constant string literals, but will refuse to concatenate a variable and a string literal due to the expression not being computable at compile-time.

And now it's time for the fifth and final version of looking up our `on_init` function. It's true, cross my heart and hope to die or pinkie promise, whichever you happen to fancy.

If we look at `lua_pushglobaltable` we notice that it also happens to be a macro.

```c
#define lua_pushglobaltable(L) \          
    ((void) lua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_GLOBALS))
```

Casting to `(void)` is just another preprocessor trick to silence any unwanted compiler warnings regarding unused return values.

You might have seen this used for doing the same when it comes to unused variables.

```c
#define UNUSED(x) (void) (x)

int main(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    
    return 0;
}
```

Syntatic macro sugar and spice is what makes your code look pretty and nice. I am a poetic genius, aren't I? I am sure you agree, so let's carry on. Time is of the essence.

```c
lua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_GLOBALS));
lua_pushliteral(L, "on_init");
if(lua_rawget(L, -2) != LUA_TFUNCTION)
{
    lua_pop(L, 2);
    return false;
}
lua_pop(L, 1);
```

Please ignore the `LUA_REGISTRYINDEX` pseudo-index for now, we'll come back to it in a second and all will be revealed before your eyes.

The `lua_rawgeti` and `lua_rawget` operate raw on a given table hence their name.

What this means is that they do not call any of the table's metamethods like `__index` when doing lookups. Of course if the table in question doesn't have a metatable or doesn't implement the `__index` metamethod then it doesn't really matter, but I am sure you get the idea.

The `lua_gettable` and `lua_getfield` functions on the other hand will end up calling the metamethods in question.

When to use one versus the other? Generally speaking you'd use the raw access methods when implementing metamethods themselves to avoid infinite loops, or when you simply don't care about metamethods at all.

It should go without saying that raw access has less overhead especially if the defined metamethods are heavy duty and do otherwise complicated lookups.

What if the function that we wanted to lookup isn't in the global environment table, but rather in a module or package.

```lua
game = game or {}
game.on_init = function(argv)
	-- noop    
end
```

Given the five examples above, I think we can kind of tell how to go about that.

```c
if(lua_getglobal(L, "game") != LUA_TTABLE)
{
    lua_pop(L, 1);
    return false;
}
if(lua_getfield(L, -1, "on_init") != LUA_TFUNCTION)
{
    lua_pop(L, 2);
    return false;
}
lua_pop(L, 1);
```

Easy peasy, lemon squeezy.

Now that we mastered the dark arts of looking up the function we want to call, written our thesis and gotten our well deserved PhD, it's time to move on to the next phase, which involves preparing the argument that we want to call the function with.

```c
lua_createtable(L, argc, 0);
for(i = 0; i < argc; i++) 
{    
	lua_pushstring(L, argv[i]);
    lua_rawseti(L, -2, i);
}
```

First we create a new table and push it into the stack by calling `lua_createtable`.

The second and third arguments allow us to reserve memory for numeric and key indices. These come handy when we happen to know the expected or approximate amount of elements that we wish to insert into said table. 

This of course can also help us reduce the number of extraneous memory allocations as the table grows during the insertion process of the elements.

In our particular case we know the exact amount we want and that is equal to `argc` which is the number of command line arguments that were passed to our executable.

Then we simply iterate over the arguments and set each argument at a given numeric index by the meas of `lua_rawseti` which just like its companion getter `lua_rawgeti` will not try to invoke any of the metamethods as we established before.

The second argument to `lua_rawseti` is set to `-2` because the table we just created is on position two downwards from the top of the stack.

After it sets the value, `lua_rawseti` will also pop the string we previously pushed into the stack.

You might have noticed that we start at index `0` rather than `1`, which is not a typo by the way. Why?

```lua
function on_init(argv)
	for _, arg in ipairs(argv) do
       -- noop 
    end
    print(argv[0])
end
```

This allows us access to the name of the executable if we need it, without having to worry about skipping the first argument when working with the table in every other case.

```lua
function on_init(argv)
	for i=2, #argv do
		local arg = argv[i]
       	-- noop
    end
    print(argv[1])
end
```

Now that our table (array) of command line arguments is ready, we can go ahead and finally call our `on_init` function.

```c
ret = lua_pcall(L, 1 /* one argument */, 0, 0);
if(ret != 0)
{
	fprintf(stderr, "Lua Error:\n%s\n", lua_tostring(L, -1));
    lua_pop(L, 1);
    return false;
}
```

When `lua_pcall` is called, it will pop both the function and the number of arguments indicated by the first argument off the stack.

If there have been any errors with calling the function it will return a non zero value and push the error message into the top of the stack, which we can retrieve and display the user in some form or another.

The `p` in `lua_pcall` comes from *protected*, meaning that it is guaranteed to return safely in case of any errors and unwind the stack as expected.

What if we wanted to allow `on_init` to return an error code and then propagate that up to `main()` and use it as an `exit code`?

```lua
function on_init(argv)
	-- noop
    return -1
end
```

```c
int script_on_init(lua_State *L, const int argc, const char *argv[])
{
    int i, ret;
        
 	if(lua_getglobal(L, "on_init") != LUA_TFUNCTION)
    {
        lua_pop(L, 1);
        return false;
    }
    
   	lua_createtable(L, argc, 0);
    for(i = 0; i < argc; i++) 
    {    
        lua_pushstring(L, argv[i]);
        lua_rawseti(L, -2, i);
    }
    
    ret = lua_pcall(L, 1 /* one argument */, 1 /* one return value */, 0);
    if(ret != 0)
    {
        fprintf(stderr, "Lua Error:\n%s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
        return false;
    }
    
    if(lua_isnumber(L, -1))
    {
        ret = lua_tonumber(L, -1);
    }
    
    lua_pop(L, 1);
    return ret;
}

int main(int argc, char *argv[])
{
    int ret;
    lua_State *L;
    
    ret = script_on_init(L, argc, (const char **) argv);
    if(ret != 0)
    	return ret;
    
    // ...
    
    return ret;
}
```

The first thing that you might notice is that `lua_pcall` now has its third argument set to `1` which is the number of return values we expect `on_init` to have.

```c
ret = lua_pcall(L, 1 /* one argument */, 1 /* one return value */, 0);
```

The second thing to call out is the fact that we check if said return value is a number. If it is, then we grab the actual value and pop it off the stack.

```c
if(lua_isnumber(L, -1))
{
	ret = lua_tonumber(L, -1);
}
lua_pop(L, 1);
```

This enables us to also not have to explicitly return anything in `on_init` and in such cases we will just assume that the return value is equal to `0`.

```lua
function on_init(argv)
	-- noop
end
```

Obviously, we could also just print an error and return a specific error code in case it wasn't a number if we so desired. But, personally I prefer to make things optional when it makes sense to do so.

Now let's take a look at how would one go about calling `on_quit`.

```c
void script_on_quit(lua_State *L)
{
    int ret;
    
    if(lua_getglobal(L, "on_quit") != LUA_TFUNCTION)
    {
        lua_pop(L, 1);
		return;
    }
    
    ret = lua_pcall(L, 0, 0, 0);
    if(ret != 0)
    {
        fprintf(stderr, "Lua Error:\n%s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
    }
}
```

I don't think that `on_quit` needs any discussion or clarifications, it should all self explanatory.

And, finally the implementation of calling `on_frame`.

```c
void script_on_frame(
	lua_State *L,
    const double dt,
    const int w,
    const int h
)
{
    int ret;
        
 	if(lua_getglobal(L, "on_frame") != LUA_TFUNCTION)
    {
        lua_pop(L, 1);
        return;
    }

    lua_pushnumber(L, dt);
    lua_pushinteger(L, w);
    lua_pushinteger(L, h);
    
    ret = lua_pcall(L, 3 /* arguments argument */, 0, 0);
    if(ret != 0)
    {
        fprintf(stderr, "Lua Error:\n%s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
        return false;
    }
}
```

The only thing we haven't see before is the fact that `on_frame` expects and receives 3 arguments, which are pushed in order into the stack and then `lua_pcall` is passed in 3 as its second argument.

Considering this function is going to be called every frame, which can mean 60 or more times per second, depending on the frame rate, it would be nice to avoid having to do the `lookup` by name every single time.

A way to do this is by grabbing a reference which is then stored in the global registry that I mentioned before and told you that we'll come back to later.

```c
if(lua_getglobal(L, "on_frame") != LUA_TFUNCTION)
{
	lua_pop(L, 1);
    return;
}

int on_frame_ref = luaL_ref(lua, LUA_REGISTRYINDEX);
```

The idea behind this is to grab the *reference* once on startup and then just reuse said reference avoiding the more expensive global lookup on every frame.

It is also worth pointing out that grabbing a reference will prevent Lua from garbage collecting the *object* or *function* in question that the reference is pointing to.

The sister function `luaL_unref` can be used to release a reference once we are done with it.

So let's take a look at how this affects the implementation of `script_on_frame`.

```c
void script_on_frame(
    lua_State *L,
    const int ref,
    const double dt,
    const int w,
    const int h)
{
    int ret;
        
 	lua_rawgeti(L, LUA_REGISTRYINDEX, ref);

    lua_pushnumber(L, dt);
    lua_pushinteger(L, w);
    lua_pushinteger(L, h);
    
    ret = lua_pcall(L, 3 /* arguments argument */, 0, 0);
    if(ret != 0)
    {
        fprintf(stderr, "Lua Error:\n%s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
        return false;
    }
}
```

### Calling C functions from Lua

Now that we know how to call Lua functions from C, it is time to dive into exposing some C functions that then can be called from Lua.

```c
int create_window(lua_State *L)
{
    return 0;
}
```

Notice the `signature` of the function, it has a single argument which is the `lua_State` and returns an `int`.

The return value indicates how many values it should pop from the stack and return to the caller. In the example above, this is `0`, meaning that the function is not expected to push anything into the stack and as a direct result not expected to return anything.

Let's take a look at a more full fledged example.

```c
int create_window(lua_State *L)
{
    const char *title;
    int w, h;
    
    title = luaL_checkstring(L, 1);
    w = luaL_checkinteger(L, 2);
    h = luaL_checkinteger(L, 3);
    
   	if(!os_window_create(title, w, h))
    {
        lua_pushboolean(L, false);
        lua_pushliteral(L, "window creation failed");
        return 2; 
    }
    
    lua_pushboolean(L, true);
    lua_pushnil(L);
    return 2;
}
```

```lua
local ok, err = create_window("My Window", 640, 480)
if not ok then
   print(err) 
end

local ok = assert(create_window("My Window", 800, 600))
```

The `create_window` function takes 3 arguments, a string and two integers, which we use retrieve the values of by calling the family of `luaL_checktype` functions.

These simply check the type of the value in the stack at the given index, if it matches the expected type, then the value is returned, otherwise a type-check like `error` is raised.

```c
title = luaL_checkstring(L, 1);
w = luaL_checkinteger(L, 2);
h = luaL_checkinteger(L, 3);
```

We could have also used negative stack indexing if we so desired.

```c
title = luaL_checkstring(L, -3);
w = luaL_checkinteger(L, -2);
h = luaL_checkinteger(L, -1);
```

These two are obviously equivalent. The question now arises when to use one versus the other?

My recommendation would be to use negative stack indexing when looking up arguments only in the case of auxiliary and/or utility type functions which cannot make any assumptions about the stack other than what is currently at the top.

Take a look at the example below.

```c
int set_window_title(lua_State *L)
{
    const char *title;
    
    title = luaL_checkstring(L, -1);
    
    os_set_window_title(title);
    
    return 0;
}

lua_pushliteral(L, "Nice Window");
set_window_title(L);
lua_pop(L, 1);
```

The second thing to note about the implementation of `create_window` is how it returns a `tuple` (*fancy word for two values*) rather than one as indicated by the return value of `2`.

This so called pattern is used by the built-in Lua standard library and its kind of an unwritten rule when it comes to handling certain types of errors without raising an fatal error explicitly by calling the `luaL_error`, `luaL_typerror`, and `luaL_argerror` family of functions.

In order to catch errors raised by these functions one must make use the two protected flavors of `lua_call`, namely `lua_pcall` and `lua_xpcall` respectively.

Once more the quintessential question arises in the form of when to use one versus the other?

My recommendation is to use the `tuple` approach in cases when the error is about dealing with an external resource of some sort (i.e file system error) that can be retried and might not be considered a fatal error, while raising actual errors via the means of `luaL_error` should be reserved for actual fatal errors that might require stopping execution of the script or even the host application altogether.

```lua
local f, err = io.open("test.lua", "rb")
if not f then
	print(err)    
end

local f = assert(io.open("test.lua", "rb"))
```

The use of strings rather than numerical constants when passing in options (flags) to a certain function is yet another common pattern used by the built-in Lua standard library, as well as third party libraries.

While this makes total sense and seems like a reasonable thing to do, and in many cases is probably what one would end up doing anyway, in the context of a game, if a particular function is called every frame, it's probably not desirable have a whole lot of `strcmp` happening in there.

With that in mind, I'd recommend to use good old numerical constants that can be **OR-ed** together as flags; which is what one would do on the C side of things anyway in this particular situation.

```c
#define BIT(x) (1 << (x))
#define _STRINGIFY(x) #s
#define STRINGIFY(x) _STRINGIFY(x)

enum
{
    WINDOW_FULLSCREEN = BIT(0),
    WINDOW_RESIZABLE  = BIT(1),
    WINDOW_CENTERED   = BIT(2)
    // ...
};

#define script_set_constant(L, c) \
	do \
	{ \
		lua_pushinteger(L, c); \
		lua_setglobal(L, STRINGIFY(c)); \
	} while(0)

// ...

script_set_constant(L, WINDOW_FULLSCREEN);
script_set_constant(L, WINDOW_RESIZABLE);
script_set_constant(L, WINDOW_CENTERED);
// ...
```

The `BIT` helper macro should be self explanatory as it shifts 1 with N given as an argument giving us a series of power of twos.

In the case of `STRINGIFY` we apply an extra level of indirection by wrapping it in another macro to ensure that it always evaluates to what we expect it to.

This indirection is often used also when defining a macro for concatenation.

```c
#define _CONCAT(a, b) a ## b
#define CONCAT(a, b) _CONCAT(a, b)
```

Finally, the `do { ... } while(0)` within the `script_set_constant` macro is a standard trick for achieving multi-line macros that work with single-line statements without an explicit `{ ... }` block.

```c
if(dev_mode)
    script_set_constant(L, DEV_MODE);
```

But, if you have written any non-trivial amounts of C in your natural life time, these so called tricks should already be in your daily arsenal and not unfamiliar in any shape or form.

On the Lua side our `create_window` function now can be called by **OR-ing** together the flags.

```lua
create_window("My Window", 640, 480, WINDOW_RESIZABLE | WINDOW_CENTERED)
```

In the sample implementation above, `create_window` simply returns `true` or `false` depending if the window creation has succeeded or not. This is fine if you only ever have one window, but what if you want to have more than one?

Well, in that case you probably want to return a handle or a pointer which then can be passed in as an argument to a function like `close_window`.

This is where so called `userdata` enters the picture. Lua happens to offer two flavors of `userdata`.

| **Feature(s)**          | **Light userdata** | **Full userdata**              |
| ----------------------- | ------------------ | ------------------------------ |
| GC (garbage collection) | no                 | yes                            |
| Metatables              | no                 | yes                            |
| `__gc` metamethod       | no                 | yes                            |
| `__eq` metamethod       | no                 | yes                            |
| == (equality)           | same *"pointer"*   | same *"object"*  or via `__eq` |

Let's re-implement `create_window` by using `light userdata`.

```c
int create_window(lua_State *L)
{
    const char *title;
    int w, h;
    uint32_t flags;
    os_window_t *window;
    
    title = luaL_checkstring(L, 1);
    w = luaL_checkinteger(L, 2);
    h = luaL_checkinteger(L, 3);
    flags = luaL_checkinteger(L, 4);
    
    window = os_window_create(title, w, h, flags);
    if(window == NULL)
    {
        lua_pushnil(L);
        lua_pushliteral(L, "window creation failed");
        return 2; 
    }
    
    lua_pushlightuserdata(L, window);
    lua_pushnil(L);
    return 2;
}
```

Let's implement the `close_window` function now in order to showcase how one would use said `light userdata` in another function.

```c
int close_window(lua_State *L)
{
    os_window_t *window;
    
    luaL_checktype(L, 1, LUA_TLIGHTUSERDATA);
    
    window = lua_touserdata(L, 1);
    
    if(window != NULL)
        os_window_close(window);
    
    return 0;
}
```

It should be self evident that `light userdata` is just a good old C pointer. Which means that we can also store any sort of value as `light userdata` so long the size of value in question happens to be less than or equal to the size of `sizeof(void *)` or `uintptr_t`.

```c
int create_window(lua_State *L)
{
    const char *title;
    int w, h;
    uint32_t flags;
    os_window_handle_t window;
    
    title = luaL_checkstring(L, 1);
    w = luaL_checkinteger(L, 2);
    h = luaL_checkinteger(L, 3);
    flags = luaL_checkinteger(L, 4);
    
    window = os_window_create(title, w, h, flags);
    if(window == OS_WINDOW_INVALID)
    {
        lua_pushnil(L);
        lua_pushliteral(L, "window creation failed");
        return 2; 
    }
    
    lua_pushlightuserdata(L, (void *) (uintptr_t) window);
    lua_pushnil(L);
    return 2;
}

int close_window(lua_State *L)
{
    os_window_handle_t window;
    
    luaL_checktype(L, 1, LUA_TLIGHTUSERDATA);
    
    window = (os_window_handle_t) (uintptr_t) lua_touserdata(L, 1);
    
    if(window != OS_WINDOW_INVALID)
        os_window_close(window);
    
    return 0;
}
```

Now it is time to re-implement the `create_window` and `close_window` functions by using `full userdata`.

```c
typedef struct
{
    os_window_t *window;
    uint32_t flags;
} window_userdata_t;

#define WINDOW_METATABLE "WINDOW *"

int close_window(lua_State *L);

static const luaL_Reg window_metamethods[] = {   
	{ "__gc", close_window },            
	{ "__close", close_window },                                     
	{ NULL, NULL }
};

int create_window(lua_State *L)
{
    const char *title;
    int w, h;
    uint32_t flags;
    os_window_t *window;
    window_userdata_t *window_userdata;
    
    title = luaL_checkstring(L, 1);
    w = luaL_checkinteger(L, 2);
    h = luaL_checkinteger(L, 3);
    flags = luaL_checkinteger(L, 4);
    
    window = os_window_create(title, w, h, flags);
    if(window == OS_WINDOW_INVALID)
    {
        lua_pushnil(L);
        lua_pushliteral(L, "window creation failed");
        return 2; 
    }
    
    window_userdata = lua_newuserdata(L, sizeof(window_userdata_t));
    if(window_userdata == NULL)
        return luaL_error(L, "out of memory");
    
    window_userdata->window = window;
    window_userdata->flags = flags;
    
    if(luaL_newmetatable(L, WINDOW_METATABLE))
        luaL_setfuncs(L, window_metamethods);
    
    lua_setmetatable(L, -2);

    lua_pushnil(L);
    return 2;
}

int close_window(lua_State *L)
{
    window_userdata_t *userdata;
    
   	userdata = luaL_checkudata(L, 1, WINDOW_METATABLE);
    if(userdata == NULL)
        return luaL_typeerror(L, 1, WINDOW_METATABLE);
    
    if(userdata->window != NULL)
    {
        os_window_close(userdata->window);
        userdata->window = NULL;
    }
    
    return 0;
}
```

The first thing that should stand out here is the use of `lua_newuserdata` which is used to allocate memory in order to hold our `window_userdata_t` struct.

The second thing that might stand out is this lovely piece of code.

```c
if(luaL_newmetatable(L, WINDOW_METATABLE))
	luaL_setfuncs(L, window_metamethods);
    
lua_setmetatable(L, -2);
```

The `luaL_newmetatable` will attempt to lookup if there is a metatable with the provided name, if there is one it will push it into the top of the stack and return `0`, otherwise it will create a brand new one and return `1`.

In the case it ended up creating a new one, which would be the very first time `create_window` was called, we want to initialize the metadata and set the relevant metamethods we care about, namely `__gc` and `__close`. We do this by calling`luaL_setfuncs` with the array of function definitions.

We'll come back and go into more detail when it comes to `luaL_setfuncs` later.

Finally, `lua_setmetatable` will set this metatable as the metatable of the newly created `full userdata`.

We could of course move this out of the `create_window` function and do it once when we setup the initial `lua_State`, in which case setting the metatable inside `create_window` could be simplified down to calling ``luaL_setmetatable`` instead of `lua_setmetatable`. Notice the uppercase `L`.

```c
luaL_setmetatable(L, WINDOW_METATABLE);
```

Another thing I'd like call out is the way the userdata is being retrieved in `close_window`.

```c
userdata = luaL_checkudata(L, 1, WINDOW_METATABLE);
if(userdata == NULL)
	return luaL_typeerror(L, 1, WINDOW_METATABLE);
```

The `luaL_checkudata` function will return `NULL` if the one of the following conditions is `true`:

* the type of the value at the given stack index is not of type full userdata
* the metatable of said full userdata is not the metatable passed in as the second argument

Due to the fact that `luaL_checkudata` doesn't raise an unexpected type error on its own, we end up doing so ourselves by calling the `luaL_typeerror` function.

Why didn't we explicitly cast the userdata to `window_userdata_t *`, is that a typo? No, in C one doesn't have to cast to and from `void *`, due to the fact that such casts are considered to be implicit.

The question that we are faced with yet again is when to use one versus the other?

I'd say, go with `light userdata` when you want to do explicit and manual resource management , otherwise go with `full userdata` especially when garbage collection is needed or is desirable.

Personally, I prefer to use simple opaque integer identifiers, instead of userdata of any kind, except when I need `upvalues`, in which case `light userdata` can come in very handy, but more on that  later down the line.

```c
typedef union
{
	uint64_t opaque;
    struct
    {
		uint64_t type     : 8;
        uint64_t reserved : 24;
		uint64_t index    : 32;
	};
} id_t;

int create_window(lua_State *L)
{
    const char *title;
    int w, h;
    uint32_t flags;
    id_t id;
    
    title = luaL_checkstring(L, 1);
    w = luaL_checkinteger(L, 2);
    h = luaL_checkinteger(L, 3);
    flags = luaL_checkinteger(L, 4);
    
    id = os_window_create(title, w, h, flags);
    
	lua_pushinteger(L, id.opaque);
    lua_pushnil(L);
    return 2;
}

int close_window(lua_State *L)
{
    id_t id;
    
  	id.opaque = luaL_checkinteger(L, 1);
    
    os_window_close(id);
    return 0;
}
```

This approach also reduces the need to litter explicit and verbose error handling everywhere, because you are always guaranteed to get an `id`.

In case of any errors you just get an `id` of `zero`, which is then safe to pass in as an argument to any related functions and is guaranteed to result in a no-op.

On a side note, I just realized the fact that I never brought up how to handle optional arguments.

```c
int create_window(lua_State *L)
{
    const char *title;
    int n, w = 640, h = 480;
    uint32_t flags = 0;
    id_t id;
    
    title = luaL_checkstring(L, 1);
    
    n = lua_gettop(L);
    if(n > 1)
    {
    	w = luaL_checkinteger(L, 2);
    	h = luaL_checkinteger(L, 3);
   		
        if(n > 3)
    		flags = luaL_checkinteger(L, 4);
    }
    
    id = os_window_create(title, w, h, flags);
    
	lua_pushinteger(L, id.opaque);
    lua_pushnil(L);
    return 2;
}
```

The `lua_gettop` function can be used to get the number of elements pushed into the stack. We can use this information to determine how many arguments have been pushed into the stack when our function was called.

It's really as simple as that. Personally, I also like to use `lua_gettop` to ensure that the function leaves the stack in a clean state, especially after performing a lot of operations that alter the stack in one way or another.

```c
int table_map(lua_State *L)
{
    int n;
    
    n = lua_gettop(L);

    /* call functions that operate on the stack */
    
    assert(lua_gettop(L) == n);
    
	/* push any return values on the stack */
    return 1;
}
```

In other words, stack hygiene is essential and can save you from a myriad of weird, subtle and hard to debug issues that might arise when not practiced and taken as seriously as one should.

None of the bindings that we ended up implementing and looking at worked with any global state and it's high time to change that considering that in any game and app one will have some manner of global state or shared context of some description to work with.

```c
typedef struct
{
    bool running;
    bool vsync;
} game_t;

int game_set_vsync(lua_State *L)
{    
    game->vsync = luaL_checkboolean(L, 1);   
    return 0;
}
```

Isn't the use of global variables `static` or otherwise considered bad practice? The answer to that question is yes, however not always.

Two particular scenarios come to mind, when in my opinion it's perfectly fine to use global variables.

Case one, they are `static`, confined to a single compilation unit (*read .c source file*) and `thead-safety` has been considered and handled as necessary (i.e locking read/write via a mutex).

Case two, they are not `static` but marked as `const` and `extern`-ed as such via a declaration in a header file.

However, the use of `non static` and `non const` global variables that can be changed from any compilation unit should be avoided at all cost, unless you are a time traveler who also happens to be coding in C like it's the great year of 1989.

What if the state is not a `static` global variable? This is where the so called `upvalues` that I mentioned above come into play.

But, what are these mysterious `upvalues` exactly?

In simplest terms they are akin to local variables accessible within the confines of a closure.

```lua
function create_id_generator()
	local id = 0
    
    return function()
    	id = id + 1
        return id
    end
end

local id = create_id_generator()
print(id())
print(id())
```

In the example above you can think of the local variable `id` as the `upvalue` of the anonymous function (closure) being returned.

This would be roughly equivalent of a `local static` variable declared within a function in C.

So let's rewrite `game_set_vsync` by using an `upvalue` to a pointer to our game state.

```c
typedef struct
{
    bool running;
    bool vsync;
} game_t;

int game_set_vsync(lua_State *L)
{
    game_t *game;

    game = lua_touserdata(L, lua_upvalueindex(1));
    game->vsync = luaL_checkboolean(L, 1);
    
    return 0;
}
```

We could also check for the `type` of the `upvalue`, but this is largely unnecessary in most cases.

```c
luaL_checktype(L, lua_upvalueindex(1), LUA_TLIGHTUSERDATA);
```

Another useful fact to be aware of when it comes to `upvalues` is that they do not live on the actual stack and that the `lua_upvalueindex` function is just a convenience helper macro that returns a pseudo-index.

```c
#define lua_upvalueindex(i)	(LUA_REGISTRYINDEX - (i))
```

Speaking of closures, let's take a quick detour and look at the implementation of iterators.

```lua
local function odd()
   	local f = function(t, i)
		i = i + 1
        local v = t[i]
        while v do
			if v & 1 == 1 then
                return i, v
            else
                i = i + 1
                v = t[i]
            end
        end
    end
    
	return function(t)
    	return f, t, 0 
    end
end

return odd()
```

And now let's see the iterator in action.

```lua
local odd = require "odd"

local t = { 33, 32, 13 }
for i, v in odd(t) do
    print(i, v)
end
```

This will iterate over all the elements of the array, but will `yield` only when it happens to encounter an element that is odd.implemention

```lua
1	33
3	13
```

The expression `v & n == 1` is equivalent to `v % n == 1` but only when `n` is power of two.  

Iterators compatible with the `in` keyword always return a triple, in our case `return f, t, 0`.

The iterator closure that is called on every iteration, the table that is being iterated on and finally the initial value of the current index.

Closures of course can also be created from C by the means of `lua_pushcclosure`, but we'll talk more about that later.

Now that the deep dive into writing bindings has been more or less completed, it is time to check out how to actually expose them in order to make them callable from the Lua.

The first and obvious approach is to just set them in the global environment, by using the reverse of what we did when looking up functions as illustrated in the **Calling Lua from C** section above.

Except that instead of `getglobal`, `getfield`, `getttable`, `rawget` you'd end up using the sister setter family of functions, namely `setglobal`, `setfield`, `settable` and `rawget` respectively.

Not going to go through absolutely all the permutations yet again, I am sure that you get the basic idea behind what I am driving at.

```c
int create_window(lua_State *L);

lua_pushcfunction(L, create_window);
lua_setglobal("create_window");
```

Exposing a `C closure` with an `upvalue` isn't much more complicated either.

```c
int create_window(lua_State *L);

game_t *game = /* game state */;

lua_pushlightuserdata(L, game);
lua_pushcclosure(L, game, 1);
lua_setglobal(L, "game_set_vsync");
```

What about exposing some sort of an integer constant? You got a taste of this already when we talked about exposing options and flags.

```c
#define GAME_VERSION 0x100

lua_pushinteger(L, GAME_VERSION);
lua_setglobal(L, "GAME_VERSION");
```

In most cases you will very likely have more than one function to expose, and just so it happens that Lua has a helper function that comes to our rescue.

I am talking about `luaL_setfuncs` of course, which we also used to set the metamethods on our metatable above.

```c
static const luaL_Reg window_funcs[] = {
    { "create_window", create_window },
    { "close_window", close_window },
    { NULL, NULL }
};

lua_pushglobaltable(L);
luaL_setfuncs(L, window_funcs, 0);
lua_pop(L, 1);
```

An important detail to call out is the `{ NULL, NULL }` sentinel value, which is used to designate the end of the static array of function definitions.

The third argument of `luaL_setfuncs` indicates the number of `upvalues` that should be pushed for every function defined in the array, which is `zero` in this particular case due to the fact that the functions in question do not need or use an `upvalue`.

However, if they did then we'd push the `light userdata` and set the third argument to `1` like it can be observed in the example below.

```c
static const luaL_Reg window_funcs[] = {
    { "game_set_vsync", game_set_vsync },
    { "game_set_running", game_set_running },
    { NULL, NULL }
};
game_t *game = /* game state */;

lua_pushglobaltable(L);
lua_pushlightuserdata(L, game);
luaL_setfuncs(L, window_funcs, 1);
lua_pop(L, 1);
```

`luaL_setfuncs` will pop the `upvalues` of the stack, leaving only the table at the top, which is why we pass `1` instead of `2` to `lua_pop`.

Nothing is stopping us from rolling our own `luaL_setfuncs` and `luaL_Reg` if that's what we fancy.

```c
#define _STRINGIFY(x) #x
#define STRINGIFY(x) _STRINGIFY(x)
#define SCRIPT_FUNC(f) { STRINGIFY(f), f }
#define SCRIPT_FUNC_NULL { NULL, NULL }

typedef struct
{
    const char *name;
    lua_CFunction func;
} script_func_t;

static const script_func_t window_funcs[] = {
    SCRIPT_FUNC(game_set_vsync),
    SCRIPT_FUNC(game_set_running),
    SCRIPT_FUNC_NULL
};
game_t *game = /* game state */;

void script_set_funcs(
	lua_State *L,
	const script_func_t *func,
    game_t *game
)
{
    lua_pushglobaltable(L);

    for(; func->name != NULL; func++)
    {
 		lua_pushlightuserdata(L, game);
        lua_pushcclosure(L, func->func, 1);
        lua_setfield(L, -2, func->name);
    }
    
    lua_pop(L, 1);
}

script_set_funcs(L, window_funcs, game);
```

`lua_CFunction` is just convenience function pointer `typedef` as one would expect. 

```c
typedef int (*lua_CFunction)(lua_State *L);
```

If the use of the `{ NULL, NULL }` sentinel is still giving you heavy anxiety and cold sweats, let's re-implement `script_set_funcs` without it in order to ease your pain.

```c
#define _STRINGIFY(x) #x
#define STRINGIFY(x) _STRINGIFY(x)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#define SCRIPT_FUNC(f) { STRINGIFY(f), f }

typedef struct
{
    const char *name;
    lua_CFunction func;
} script_func_t;

static const script_func_t window_funcs[] = {
    SCRIPT_FUNC(game_set_vsync),
    SCRIPT_FUNC(game_set_running)
};
static const size_t window_funcs_size = ARRAY_SIZE(window_funcs);
game_t *game = /* game state */;

void script_set_funcs(
	lua_State *L,
	const script_func_t *func,
    const size_t size,
    game_t *game
)
{
    lua_pushglobaltable(L);

    for(const script_func_t *end = func + size; func != end; func++)
    {
 		lua_pushlightuserdata(L, game);
        lua_pushcclosure(L, func->func, 1);
        lua_setfield(L, -2, func->name);
    }
    
    lua_pop(L, 1);
}

script_set_funcs(L, window_funcs, window_funcs_size, game);
```

Better than a healthy dose of XANAX on a Friday night, right? I certainly hope so.

The second approach we could take, which I am sure you guessed already is to group these functions into modules and then expose those modules. This is what the Lua standard library is doing.

```c
static const luaL_Reg script_window_module_funcs[] = {
    { "create", create_window },
    { "close", close_window },
    { NULL, NULL }
};

int script_window_module(lua_State *L)
{
    luaL_newlibtable(L, script_window_module_funcs);
    luaL_setfuncs(L, script_window_module_funcs, 0);
    return 1;
}

static const luaL_Reg script_modules[] = {
    { "window", script_window_module },
    { NULL, NULL }
};

void script_set_modules(lua_State *L, const luaL_Reg *module)
{
    for(; module->name != NULL; module++)
    {
        luaL_requiref(L, module->name, module->func, 1);
        lua_pop(L, 1);
    }
}

script_set_modules(L, script_modules);
```

The first thing to talk about here is the `luaL_newlibtable` macro.

```c
#define luaL_newlibtable(L, l) \
	lua_createtable(L, 0, sizeof(l) / sizeof((l)[0]) - 1)
```

It creates a table and preallocates enough memory for the number of functions we intend to set in the table. Notice how it accounts for the `{ NULL, NULL `} sentinel value, hence the `-1` at the end of the expression.

The second thing to bring forth is the proverbial fourth argument of the `luaL_requiref` function which is set to `1` (true), which in turn means that each module will also be set in the global environment table.

```lua
asset(window.create("Window", 800, 600, WINDOW_FULLSCREEN))
```

If we set this to `0` (false) then it is necessary to explicitly `require` the module on the Lua side before it can be used.

```lua
local window = require "window"
asset(window.create("Window", 800, 600, WINDOW_FULLSCREEN))
```

It should be crystal clear to you by now that pretty much everything can be implemented in more than one way, with each implementation having their own pros and cons depending on what you need.

So, global functions or modules? I'd say go with global functions if what you are doing is more akin to data-driven configuration than anything else, otherwise go with modules.

## The End

While this turned out to be a much more comprehensive guide of some sorts than what I initially had in mind, it still only manages to scratch the surface when it comes to a great many aspects.

Please take everything outlined here with a grain of salt and do not consider it as some authoritative manual to be followed to the letter, or else all hell will break loose and the four horsemen of the apocalypse will be unleashed upon the world.

To learn more and dive into some of the specific details about Lua, please take a look at the excellent [Lua Reference Manual][refmanual] and [Programming in Lua][pil].

Until next time, please remember to always, and I mean absolutely always to `pop()` your `pushes()` or to `push()` your `pops()`, I always forget which way it is.

Anyways, take whatever happens to resonate more with you and your own personal style.

[meta]: https://www.lua.org/pil/13.html
[coro]: https://www.lua.org/pil/9.1.html
[refmanual]: https://www.lua.org/manual/5.4/manual.html
[pil]: https://www.lua.org/pil/
[roblox]: https://www.roblox.com/
[orthodoxcpp]: https://gist.github.com/bkaradzic/2e39896bc7d8c34e042b