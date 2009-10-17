/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef TRINITY_DEFINE_H
#define TRINITY_DEFINE_H
#include <sys/types.h>
#include <ace/Basic_Types.h>
#include <ace/ACE_export.h>
#include "Platform/CompilerDefs.h"
#define TRINITY_LITTLEENDIAN 0
#define TRINITY_BIGENDIAN    1
#if !defined(TRINITY_ENDIAN)
#  if defined (ACE_BIG_ENDIAN)
#    define TRINITY_ENDIAN TRINITY_BIGENDIAN
#  else //ACE_BYTE_ORDER != ACE_BIG_ENDIAN
#    define TRINITY_ENDIAN TRINITY_LITTLEENDIAN
#  endif //ACE_BYTE_ORDER
#endif //TRINITY_ENDIAN
#if PLATFORM == PLATFORM_WINDOWS
#  define TRINITY_EXPORT __declspec(dllexport)
#  define TRINITY_LIBRARY_HANDLE HMODULE
#  define TRINITY_LOAD_LIBRARY(a) LoadLibrary(a)
#  define TRINITY_CLOSE_LIBRARY FreeLibrary
#  define TRINITY_GET_PROC_ADDR GetProcAddress
#  define TRINITY_IMPORT __cdecl
#  define TRINITY_SCRIPT_EXT ".dll"
#  define TRINITY_SCRIPT_NAME "TrinityScript"
#  define TRINITY_PATH_MAX MAX_PATH
#else //PLATFORM != PLATFORM_WINDOWS
#  define TRINITY_LIBRARY_HANDLE void*
#  define TRINITY_EXPORT export
#  define TRINITY_LOAD_LIBRARY(a) dlopen(a,RTLD_NOW)
#  define TRINITY_CLOSE_LIBRARY dlclose
#  define TRINITY_GET_PROC_ADDR dlsym
#  if defined(__APPLE_CC__) && defined(BIG_ENDIAN)
#    define TRINITY_IMPORT __attribute__ ((longcall))
#  elif defined(__x86_64__)
#    define TRINITY_IMPORT
#  else
#    define TRINITY_IMPORT __attribute__ ((cdecl))
#  endif //__APPLE_CC__ && BIG_ENDIAN
#  if defined(__APPLE_CC__)
#    define TRINITY_SCRIPT_EXT ".dylib"
#    if defined(DO_SCRIPTS)
#      define TRINITY_SCRIPT_NAME "../lib/libtrinityscript"
#    else
#      define TRINITY_SCRIPT_NAME "../lib/libtrinityinterface"
#    endif // DO_SCRIPTS
#  else
#    define TRINITY_SCRIPT_EXT ".so"
#    if defined(DO_SCRIPTS)
#      define TRINITY_SCRIPT_NAME "libtrinityscript"
#    else
#      define TRINITY_SCRIPT_NAME "libtrinityinterface"
#    endif // DO_SCRIPTS
#  endif //__APPLE_CC__
#  define TRINITY_PATH_MAX PATH_MAX
#endif //PLATFORM
#if PLATFORM == PLATFORM_WINDOWS
#  ifdef TRINITY_WIN32_DLL_IMPORT
#    define TRINITY_DLL_DECL __declspec(dllimport)
#  else //!TRINITY_WIN32_DLL_IMPORT
#    ifdef TRINITY_WIND_DLL_EXPORT
#      define TRINITY_DLL_DECL __declspec(dllexport)
#    else //!TRINITY_WIND_DLL_EXPORT
#      define TRINITY_DLL_DECL
#    endif //TRINITY_WIND_DLL_EXPORT
#  endif //TRINITY_WIN32_DLL_IMPORT
#else //PLATFORM != PLATFORM_WINDOWS
#  define TRINITY_DLL_DECL
#endif //PLATFORM
#if PLATFORM == PLATFORM_WINDOWS
#  define TRINITY_DLL_SPEC __declspec(dllexport)
#  ifndef DECLSPEC_NORETURN
#    define DECLSPEC_NORETURN __declspec(noreturn)
#  endif //DECLSPEC_NORETURN
#else //PLATFORM != PLATFORM_WINDOWS
#  define TRINITY_DLL_SPEC
#  define DECLSPEC_NORETURN
#endif //PLATFORM
#if !defined(DEBUG)
#  define TRINITY_INLINE inline
#else //DEBUG
#  if !defined(TRINITY_DEBUG)
#    define TRINITY_DEBUG
#  endif //TRINITY_DEBUG
#  define TRINITY_INLINE
#endif //!DEBUG
#if COMPILER == COMPILER_GNU
#  define ATTR_NORETURN __attribute__((noreturn))
#  define ATTR_PRINTF(F,V) __attribute__ ((format (printf, F, V)))
#else //COMPILER != COMPILER_GNU
#  define ATTR_NORETURN
#  define ATTR_PRINTF(F,V)
#endif //COMPILER == COMPILER_GNU
typedef ACE_INT64 int64;
typedef ACE_INT32 int32;
typedef ACE_INT16 int16;
typedef ACE_INT8 int8;
typedef ACE_UINT64 uint64;
typedef ACE_UINT32 uint32;
typedef ACE_UINT16 uint16;
typedef ACE_UINT8 uint8;
#if COMPILER != COMPILER_MICROSOFT
typedef uint16      WORD;
typedef uint32      DWORD;
#endif //COMPILER
typedef uint64 OBJECT_HANDLE;
#define MaNGOS              Trinity
#define MANGOS_DLL_DECL     TRINITY_DLL_DECL
#define MANGOS_DLL_SPEC     TRINITY_DLL_SPEC
#define GetMangosString     GetTrinityString
#if defined(MANGOS_DEBUG) || defined(TRINITY_DEBUG)
#  ifndef TRINITY_DEBUG
#    define TRINITY_DEBUG
#  endif
#  ifndef MANGOS_DEBUG
#    define MANGOS_DEBUG
#  endif
#endif
#if !defined(DEBUG) && !defined(MANGOS_DEBUG) && !defined(TRINITY_DEBUG)
#define MULTI_THREAD_MAP
#endif
#ifdef MULTI_THREAD_MAP
#define MAP_BASED_RAND_GEN
#endif
#ifndef CLIENT_VER
#define CLIENT_VER 313
#endif

#endif //TRINITY_DEFINE_H

