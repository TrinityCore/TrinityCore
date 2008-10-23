/* 
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRINITY_DEFINE_H
#define TRINITY_DEFINE_H

#include "Platform/CompilerDefs.h"
#include <sys/types.h>

/* Endian detection code from sha2.c:
-------------------------------------------------------------------------
Copyright (c) 2001, Dr Brian Gladman <brg@gladman.me.uk>, Worcester, UK.
All rights reserved.

TERMS

Redistribution and use in source and binary forms, with or without 
modification, are permitted subject to the following conditions:

1. Redistributions of source code must retain the above copyright 
notice, this list of conditions and the following disclaimer. 

2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the 
documentation and/or other materials provided with the distribution. 

3. The copyright holder's name must not be used to endorse or promote 
any products derived from this software without his specific prior 
written permission. 

This software is provided 'as is' with no express or implied warranties 
of correctness or fitness for purpose.
-------------------------------------------------------------------------
*/

/*  1. PLATFORM SPECIFIC INCLUDES */

#if defined(__GNU_LIBRARY__)
#  include <endian.h>
#  include <byteswap.h>
#elif defined(__CRYPTLIB__)
#  if defined( INC_ALL )
#    include "crypt.h"
#  elif defined( INC_CHILD )
#    include "../crypt.h"
#  else
#    include "crypt.h"
#  endif
#  if defined(DATA_LITTLEENDIAN)
#    define PLATFORM_BYTE_ORDER SHA_LITTLE_ENDIAN
#  else
#    define PLATFORM_BYTE_ORDER SHA_BIG_ENDIAN
#  endif
#elif defined(_MSC_VER)
#  include <stdlib.h>
#elif !defined(WIN32)
#  include <stdlib.h>
#  if !defined (_ENDIAN_H)
#    include <sys/param.h>
#  else
#    include _ENDIAN_H
#  endif
#endif

/*  2. BYTE ORDER IN 32-BIT WORDS

To obtain the highest speed on processors with 32-bit words, this code 
needs to determine the order in which bytes are packed into such words.
The following block of code is an attempt to capture the most obvious 
ways in which various environemnts specify their endian definitions. 
It may well fail, in which case the definitions will need to be set by 
editing at the points marked **** EDIT HERE IF NECESSARY **** below.
*/

#define TRINITY_LITTLEENDIAN 0
#define TRINITY_BIGENDIAN    1

#if !defined(TRINITY_ENDIAN)
#  if defined(LITTLE_ENDIAN) || defined(BIG_ENDIAN)
#    if defined(LITTLE_ENDIAN) && defined(BIG_ENDIAN)
#      if defined(BYTE_ORDER)
#        if   (BYTE_ORDER == LITTLE_ENDIAN)
#          define TRINITY_ENDIAN TRINITY_LITTLEENDIAN
#        elif (BYTE_ORDER == BIG_ENDIAN)
#          define TRINITY_ENDIAN TRINITY_BIGENDIAN
#        endif
#      endif
#    elif defined(LITTLE_ENDIAN) && !defined(BIG_ENDIAN) 
#      define TRINITY_ENDIAN TRINITY_LITTLEENDIAN
#    elif !defined(LITTLE_ENDIAN) && defined(BIG_ENDIAN)
#      define TRINITY_ENDIAN TRINITY_BIGENDIAN
#    endif
#  elif defined(_LITTLE_ENDIAN) || defined(_BIG_ENDIAN)
#    if defined(_LITTLE_ENDIAN) && defined(_BIG_ENDIAN)
#      if defined(_BYTE_ORDER)
#        if   (_BYTE_ORDER == _LITTLE_ENDIAN)
#          define TRINITY_ENDIAN TRINITY_LITTLEENDIAN
#        elif (_BYTE_ORDER == _BIG_ENDIAN)
#          define TRINITY_ENDIAN TRINITY_BIGENDIAN
#        endif
#      endif
#    elif defined(_LITTLE_ENDIAN) && !defined(_BIG_ENDIAN) 
#      define TRINITY_ENDIAN TRINITY_LITTLE_ENDIAN
#    elif !defined(_LITTLE_ENDIAN) && defined(_BIG_ENDIAN)
#      define TRINITY_ENDIAN TRINITY_BIGENDIAN
#    endif
#  elif 0     /* **** EDIT HERE IF NECESSARY **** */
#    define TRINITY_ENDIAN TRINITY_LITTLEENDIAN
#  elif 0     /* **** EDIT HERE IF NECESSARY **** */
#    define TRINITY_ENDIAN TRINITY_BIGENDIAN
#  elif (('1234' >> 24) == '1')
#    define TRINITY_ENDIAN TRINITY_LITTLEENDIAN
#  elif (('4321' >> 24) == '1')
#    define TRINITY_ENDIAN TRINITY_BIGENDIAN
#  else
#    define TRINITY_ENDIAN TRINITY_LITTLEENDIAN
#  endif
#endif

/* End of Endian detection code from sha2.c: */

#if PLATFORM == PLATFORM_WINDOWS
#define TRINITY_EXPORT __declspec(dllexport)
#define TRINITY_LIBRARY_HANDLE HMODULE
#define TRINITY_LOAD_LIBRARY(a) LoadLibrary(a)
#define TRINITY_CLOSE_LIBRARY FreeLibrary
#define TRINITY_GET_PROC_ADDR GetProcAddress
#define TRINITY_IMPORT __cdecl
#define TRINITY_SCRIPT_EXT ".dll"
#define TRINITY_SCRIPT_NAME "TrinityScript"
#else
#define TRINITY_LIBRARY_HANDLE void*
#define TRINITY_EXPORT export
#define TRINITY_LOAD_LIBRARY(a) dlopen(a,RTLD_NOW)
#define TRINITY_CLOSE_LIBRARY dlclose
#define TRINITY_GET_PROC_ADDR dlsym

#if defined(__APPLE_CC__) && defined(BIG_ENDIAN)
#define TRINITY_IMPORT __attribute__ ((longcall))
#else
#define TRINITY_IMPORT __attribute__ ((cdecl))
#endif

#define TRINITY_SCRIPT_EXT ".so"
#define TRINITY_SCRIPT_NAME "libtrinityscript"
#endif

#ifdef WIN32
#ifdef TRINITY_WIN32_DLL_IMPORT

#define TRINITY_DLL_DECL __declspec(dllimport)
#else
#ifdef TRINITY_WIND_DLL_EXPORT
#define TRINITY_DLL_DECL __declspec(dllexport)
#else
#define TRINITY_DLL_DECL
#endif
#endif

#else
#define TRINITY_DLL_DECL
#endif

#ifndef DEBUG
#define TRINITY_INLINE inline
#else
#ifndef TRINITY_DEBUG
#define TRINITY_DEBUG
#endif
#define TRINITY_INLINE
#endif

#if COMPILER == COMPILER_MICROSOFT
typedef __int64            int64;
typedef __int32            int32;
typedef __int16            int16;
typedef __int8             int8;
typedef unsigned __int64   uint64;
typedef unsigned __int32   uint32;
typedef unsigned __int16   uint16;
typedef unsigned __int8    uint8;
#else
typedef __int64_t   int64;
typedef __int32_t   int32;
typedef __int16_t   int16;
typedef __int8_t    int8;
typedef __uint64_t  uint64;
typedef __uint32_t  uint32;
typedef __uint16_t  uint16;
typedef __uint8_t   uint8;
typedef uint16      WORD;
typedef uint32      DWORD;
#endif
typedef uint64      OBJECT_HANDLE;

#if PLATFORM == PLATFORM_WINDOWS
#  define TRINITY_DLL_SPEC __declspec(dllexport)
#  ifndef DECLSPEC_NORETURN
#    define DECLSPEC_NORETURN __declspec(noreturn)
#  endif
#else
#  define TRINITY_DLL_SPEC
#  define DECLSPEC_NORETURN
#endif

#if COMPILER == COMPILER_GNU
#  define ATTR_NORETURN __attribute__((noreturn))
#  define ATTR_PRINTF(F,V) __attribute__ ((format (printf, F, V)))
#else
#  define ATTR_NORETURN
#  define ATTR_PRINTF(F,V)
#endif

#endif
