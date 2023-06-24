/*
 * This file is part of the KitronCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef Kitron_DEFINE_H
#define Kitron_DEFINE_H

#include "CompilerDefs.h"

#if Kitron_COMPILER == Kitron_COMPILER_GNU
#  if !defined(__STDC_FORMAT_MACROS)
#    define __STDC_FORMAT_MACROS
#  endif
#  if !defined(__STDC_CONSTANT_MACROS)
#    define __STDC_CONSTANT_MACROS
#  endif
#  if !defined(_GLIBCXX_USE_NANOSLEEP)
#    define _GLIBCXX_USE_NANOSLEEP
#  endif
#  if defined(HELGRIND)
#    include <valgrind/helgrind.h>
#    undef _GLIBCXX_SYNCHRONIZATION_HAPPENS_BEFORE
#    undef _GLIBCXX_SYNCHRONIZATION_HAPPENS_AFTER
#    define _GLIBCXX_SYNCHRONIZATION_HAPPENS_BEFORE(A) ANNOTATE_HAPPENS_BEFORE(A)
#    define _GLIBCXX_SYNCHRONIZATION_HAPPENS_AFTER(A)  ANNOTATE_HAPPENS_AFTER(A)
#  endif
#endif

#include <cstddef>
#include <cinttypes>
#include <climits>

#define Kitron_LITTLEENDIAN 0
#define Kitron_BIGENDIAN    1

#if !defined(Kitron_ENDIAN)
#  if defined (BOOST_BIG_ENDIAN)
#    define Kitron_ENDIAN Kitron_BIGENDIAN
#  else
#    define Kitron_ENDIAN Kitron_LITTLEENDIAN
#  endif
#endif

#if Kitron_PLATFORM == Kitron_PLATFORM_WINDOWS
#  define Kitron_PATH_MAX 260
#  define _USE_MATH_DEFINES
#else // Kitron_PLATFORM != Kitron_PLATFORM_WINDOWS
#  define Kitron_PATH_MAX PATH_MAX
#endif // Kitron_PLATFORM

#if !defined(COREDEBUG)
#  define Kitron_INLINE inline
#else //COREDEBUG
#  if !defined(Kitron_DEBUG)
#    define Kitron_DEBUG
#  endif //Kitron_DEBUG
#  define Kitron_INLINE
#endif //!COREDEBUG

#if Kitron_COMPILER == Kitron_COMPILER_GNU
#  define ATTR_PRINTF(F, V) __attribute__ ((__format__ (__printf__, F, V)))
#else //Kitron_COMPILER != Kitron_COMPILER_GNU
#  define ATTR_PRINTF(F, V)
#endif //Kitron_COMPILER == Kitron_COMPILER_GNU

#ifdef Kitron_API_USE_DYNAMIC_LINKING
#  if Kitron_COMPILER == Kitron_COMPILER_MICROSOFT
#    define TC_API_EXPORT __declspec(dllexport)
#    define TC_API_IMPORT __declspec(dllimport)
#  elif Kitron_COMPILER == Kitron_COMPILER_GNU
#    define TC_API_EXPORT __attribute__((visibility("default")))
#    define TC_API_IMPORT
#  else
#    error compiler not supported!
#  endif
#else
#  define TC_API_EXPORT
#  define TC_API_IMPORT
#endif

#ifdef Kitron_API_EXPORT_COMMON
#  define TC_COMMON_API TC_API_EXPORT
#else
#  define TC_COMMON_API TC_API_IMPORT
#endif

#ifdef Kitron_API_EXPORT_DATABASE
#  define TC_DATABASE_API TC_API_EXPORT
#else
#  define TC_DATABASE_API TC_API_IMPORT
#endif

#ifdef Kitron_API_EXPORT_SHARED
#  define TC_SHARED_API TC_API_EXPORT
#else
#  define TC_SHARED_API TC_API_IMPORT
#endif

#ifdef Kitron_API_EXPORT_GAME
#  define TC_GAME_API TC_API_EXPORT
#else
#  define TC_GAME_API TC_API_IMPORT
#endif

#define UI64FMTD "%" PRIu64
#define UI64LIT(N) UINT64_C(N)

#define SI64FMTD "%" PRId64
#define SI64LIT(N) INT64_C(N)

#define SZFMTD "%" PRIuPTR

#define STRING_VIEW_FMT "%.*s"
#define STRING_VIEW_FMT_ARG(str) static_cast<int>((str).length()), (str).data()

typedef int64_t int64;
typedef int32_t int32;
typedef int16_t int16;
typedef int8_t int8;
typedef uint64_t uint64;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint8_t uint8;

#endif //Kitron_DEFINE_H
