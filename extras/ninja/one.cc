/*
	Ninja in one source file, similar to Lua's `one.c`.

	`browse.cc` is not included as that requires python, and it's an optional non-critical
	feature of relatively limited usefulness anyway.

	Apart from that tiny detail, everything else is included and should compile as expected on
	all tested platforms, namely: linux, macos (OSX), windows, freebsd and android (termux).

	Getting started
	---------------
	*nix: c++ -O2 src/one.cc -o ninja

	osxcross: x86_64-apple-darwin19-c++ -O2 src/one.cc -o ninja

	mingw: x86_64-w64-mingw32-c++ -O2 src/one.cc -o ninja.exe

	msvc: cl.exe /nologo /Ox /GR- src\one.cc /out:ninja.exe

	You can define `NINJA_MAKE_LIB` if you want to build a static library instead of an executable.

	Changelog
	---------
	2024-02-24 - Birth (Initial Release)
*/
#if !defined(_DEBUG) && !defined(NDEBUG)
	#define NDEBUG
#endif

#ifdef _MSC_VER
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif

	#ifndef _CRT_SECURE_NO_WARNINGS
		#define _CRT_SECURE_NO_WARNINGS
	#endif

	#ifndef _HAS_EXCEPTIONS
		#define _HAS_EXCEPTIONS 0
	#endif

	#pragma warning(disable : 4244)
#endif

#ifdef _WIN32
	#if defined(__GNUC__) && (defined(__MINGW32__) || defined(__MINGW64__))
		#ifndef _WIN32_WINNT
			#define _WIN32_WINNT 0x601
		#endif

		#ifndef __USE_MINGW_ANSI_STDIO
			#define __USE_MINGW_ANSI_STDIO 1
		#endif
	#endif

	#include "getopt.c"

	#define IsPathSeparator IsWin32PathSeparator
	#include "includes_normalize-win32.cc"
	#undef IsPathSeparator

	#include "minidump-win32.cc"
	#include "msvc_helper-win32.cc"
	#include "msvc_helper_main-win32.cc"
	#include "subprocess-win32.cc"
#else
	#ifdef __GNUC__
		#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
	#endif
	#include "subprocess-posix.cc"
#endif

#define kFileSignature kBuildLogFileSignature
#define kCurrentVersion kBuildLogCurrentVersion

#include "build_log.cc"

#undef kFileSignature
#undef kCurrentVersion

#include "build.cc"
#include "clean.cc"
#include "clparser.cc"
#include "debug_flags.cc"
#include "depfile_parser.cc"
#include "deps_log.cc"
#include "disk_interface.cc"
#include "dyndep.cc"
#include "dyndep_parser.cc"
#include "edit_distance.cc"
#include "eval_env.cc"
#include "graph.cc"
#include "graphviz.cc"
#include "json.cc"
#include "lexer.cc"
#include "line_printer.cc"
#include "manifest_parser.cc"
#include "metrics.cc"
#include "missing_deps.cc"
#include "parser.cc"
#include "state.cc"
#include "status.cc"
#include "string_piece_util.cc"
#include "util.cc"
#include "version.cc"

#ifndef NINJA_MAKE_LIB
	#include "ninja.cc"
#endif

/* vim: set ts=4 sw=4 sts=4 noet: */
