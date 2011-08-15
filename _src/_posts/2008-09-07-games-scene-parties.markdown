--- 
layout: post
title: Games @ Scene Parties
tags: 
- c
- games
- scene
- wine
- pouet.net
---
Today, I've taken a look at the 'Games' on Pouet.net and made a selection of the ones I liked.

Here they are, in no particular order ... yeah, my arse! I won't post any links only "production name" + "team name", you can find them at Pouet.net :P

Please note that I'm running them under Linux using Wine, just in case you didn't noticed :)

I will also include a small analysis on the technologies I believe they are using. Reverse engineering is one of my older hobbies ... lol

<strong><em>London Game</em> by Team Fragment</strong>

This is a lovely GTA 3 clone. It's one of the most impressive game <em>demos</em> I've seen @ a Scene Party ... correct me, if I'm wrong :)

<a class="image" href="/images/2008/09/london_game.jpg"><img class="alignnone size-thumbnail wp-image-300" title="london_game" src="/images/2008/09/london_game-400x300.jpg" alt="" width="400" height="300" /></a>

Game Engine: in-house game engine ( proof GSystem.dll ) . A closer exanimation of the DLL Imports revealed that it's using Direct Input (DINPUT8) for input, and OpenGL (also GLU32 is imported) for rendering.

Sound System: FMod ( proof fmodex.dll )

Physics: NVidia PhysX ( proof PhysXLoader.dll )

Other Notes: Uses Zlib for virtual filesystem (proof zwlibapi.dll -- which is probably a wrapper )

PAK files have GS extension. This doesn't seem to be a complex format, because I checked out one of the files with a hex editor, and the file "signatures" were there, possibly followed by the offsets to the "real meat" ... You know, data is a sleeping monster, and code is a living monster :) The 1st part seems to be the table of contents.

There are two data files "data.gs" and "london.gs" as of now.

Signature: GS10 -- this means GS v1.0 most probably

The sounds are in WAV format. Most of the textures seem to be either PNG or DDS. There are also ".font" with associated DDS files, which most probably contain the dimensions, positions, etc. of the letters used for text rendering.

There are scripts which have the ".script" extension, vertex and pixel shaders have ".vertex", and ".fragment" respectively.

Material (script) files have the extension ".material" .

At the end of the PAK files, there is a text which says: "If you are reading this, you have no life!" .

This amused me a lot ... lol, now I'm scared to death ... haha!

It has an external configuration utility named Config.exe, but it definitely worths checking out the "userdata/settings.script", especially if you wanna enable "debug" mode and a few other interesting stuff, though setting "motion blur" to true, didn't take any effect.

<a class="image" href="/images/2008/09/london_game2.jpg"><img class="alignnone size-thumbnail wp-image-301" title="london_game2" src="/images/2008/09/london_game2-400x290.jpg" alt="" width="400" height="290" /></a>

I didn't go any further, and waiting for new updated versions as promised in the "readme" file :)

<strong><em>Sylph Wind</em> by Pieslice Productions</strong>

This is a really cool shoot-em up arcade game, really immersing, nice graphics, very good music, and good game-play .

<a class="image" href="/images/2008/09/sylph_wind.jpg"><img class="alignnone size-thumbnail wp-image-303" title="sylph_wind" src="/images/2008/09/sylph_wind-400x300.jpg" alt="" width="400" height="300" /></a>

Game Engine: in-house game engine, statically linked, so there is no separate <em>engine</em> dynamic library. Analyzing the imports, this also seems to be using Direct Input for Input (DINPUT8) and OpenGL (also GLU32 is imported ) for rendering.

Sound System: FMod ( proof fmodex.dll, and also credited in the "Manual.html" )

Other Notes: Uses the Cg Shader Technology from NVidia ( proof cg.dll and cggl.dll, and also credited in the "Manual.html" ) instead of pure GLSL .

Some of the resources are exposed like ...

The "devscripts" directory contains the "script" files which manipulate different variables, setup "spawn points" or facilitate the loading of content arrays with predefined presets.

The "devshaders" directory obviously contains the "Cg Shader" script files.

The level file have "lvl" extension and seems to have a long signature "pie_sylphengine_level3Ddata_v001d" .

Other resources like textures, sounds reside in the "data" directory as PAK files with "pr" extension. The signature of these files is "_PieResource02" . At the 1st glance i couldn't indentify any clearly visible patterns like file headers, etc.

It also imports the ChooseColor, GetOpenFileName and GetSaveFileName from comdlg32, which makes me think that a some sort of "level editor" is also included somewhere, but that's just a guess, because as always, I didn't go any further :)

This is a good game, worth playing :)

<strong><em>Kiuasturvat feat Vastaisku</em> by Sx Cracked by Taat</strong>

This is the typical "rag-doll" type game. No strings attached.

<a class="image" href="/images/2008/09/kiuasturvat.jpg"><img class="alignnone size-thumbnail wp-image-308" title="kiuasturvat" src="/images/2008/09/kiuasturvat-400x300.jpg" alt="" width="400" height="300" /></a>

Game Engine: Irrlicht

Sound System: Bass

Other Notes: N/A :P

<strong><em>Flipout</em> by Mikkosoft Productions</strong>

Flipout is breakout game with pinball style controls. This is an innovative concept, IMHO ... but at first it's a bit difficult to control.

<a class="image" href="/images/2008/09/flipout.jpg"><img class="alignnone size-thumbnail wp-image-310" title="flipout" src="/images/2008/09/flipout-400x300.jpg" alt="" width="400" height="300" /></a>

It has a Linux port, and obviously uses a great deal of open source libraries.

Game Engine: in-house game engine. Obviously it uses OpenGL for rendering. ( no GLU32 this time )

Sound System: OpenAL with Ogg Vorbis (proof libvorbis-0.dll, OpenAL32.dll, wrap_oal.dll )

Other Notes: Uses DevIL ( DevIL.dll ) for (image) texture loading loading. Also uses libsigc++ (proof libsigc-2.0-0.dll) which is typesafe callback system for standard C++ .

Uses a virtual filesystem to store most of it's data. The extension of the PAK file is ".data" . There aren't any clearly identifiable signatures, etc. inside, but again I didn't go any further :)

<strong><em>Frontal Assault</em> by Eturintama</strong>

No comments, but not X-rated, neverthless interesting and spicy :P

<a class="image" href="/images/2008/09/frontal_assault.jpg"><img class="alignnone size-thumbnail wp-image-316" title="frontal_assault" src="/images/2008/09/frontal_assault-400x300.jpg" alt="" width="400" height="300" /></a>

Game Engine: in-house game engine. It uses GLUT32 ( proof glut32.dll ) and obviously OpenGL for rendering.

Sound System: FMod ( proof fmod.dll )

Other Notes: there is no virtual file system, so all the data files are exposed.

<strong><em>A Tribute To The Rolling Boulder</em> by Kloonigames</strong>

This is a nice 2D platform game.

<a class="image" href="/images/2008/09/tribute.jpg"><img class="alignnone size-thumbnail wp-image-317" title="tribute" src="/images/2008/09/tribute-400x300.jpg" alt="" width="400" height="300" /></a>

Game Engine: in-house game engine, uses SDL for rendering.

Sound System: SDL_mixer

Physics: Box2D

Other Notes: Uses SDL_Image for texture loading, and SDL_rotozoom for texture manipulation. There is no virtual filesystem all the data can be found in the "data" directory.

It has a nice "autoexec.txt" script file, which setups key bindings, pre-loads sound effects, etc. It also seems to have it's own in-house GUI framework. ( some of these is mentioned in the "readme.html" )

<strong><em>Dust</em> by Sandbox Software</strong>

I was talking about no particular order, but I should have mentioned this one right after the 1st two as a 3rd. :P

<a class="image" href="/images/2008/09/dust.jpg"><img class="alignnone size-thumbnail wp-image-319" title="dust" src="/images/2008/09/dust-400x300.jpg" alt="" width="400" height="300" /></a>

Game Engine: in-house game engine. Uses SDL + OpenGL for rendering ( imports GLU32 ). It seems to import GLUT just for gluSolidSphere , also uses GLEW for extension handling. There are lots of XML files, because of the Collada file format ( proof FColladaR.dll, FColladaD.dll ) .

Sound System: FMod (proof fmodex.dll, and fmod_event.dll )

Physics: Ode ( proof ode.dll )

Networking: Raknet a cross-platform C++ game networking engine. ( proof RakNet.dll )

Other Notes: uses SDL_image for (image) texture loading. The config.ini worth checking :)

No virtual file system this time either, so everything is there at your own mercy. I think that Maya was used for modeling, hence the "Maya 8.5 | ColladaMaya v3.02 | FCollada v3.2" in content/scenes/alien.xml :)

The shaders are GLSL, textures mostly in PNG, sounds and effects in MP3 and WAV. Alos there are few FMOD specific files for sounds / sound effects.

Again, as always I didn't go any further.

<strong><em>TTS Demo</em> by Aukiogames</strong>

This is another GTA clone, with a huge playable level, and lovely graphics.

<a class="image" href="/images/2008/09/tts1.jpg"><img class="alignnone size-thumbnail wp-image-320" title="tts1" src="/images/2008/09/tts1-400x300.jpg" alt="" width="400" height="300" /></a>

Game Engine: in-house game engine, using DirectX8 for rendering and input, it also seems to be written in Delphi 7 which means that it's Object Pascal :) niceeee :) ... just check those nice TParticleSystem, etc. with an hex editor ;) :P

Sound System: Fmod ( proof fmod.dll )

Other Notes: again there is no virtual filesystem, but it does have a proprietary model format, with the generic "obj" extension.

Textures are in DDS, sounds and music in WAV, MP3 and OGG ... Scripts have the extension "tsl" and the language seems to be a subset of Pascal, combined with some PHP.

<a class="image" href="/images/2008/09/tts2.jpg"><img class="alignnone size-thumbnail wp-image-321" title="tts2" src="/images/2008/09/tts2-400x300.jpg" alt="" width="400" height="300" /></a>

I stopped right here!

Uffff, this was a long long journey, it took my whole Sunday afternoon ... :) There were a few other games, but mostly they were seriously lacking quality or just failed to run reasonably.

I think that these prove that Indie Game Development do exists, and it is possible for a small team to create really nice games, even if some are just "tech demos", showcasing the engines behind :)

Also, this post has more than 1285 words now, so probably I should stop!!!

Be nice, and happy coding or gaming !!!
