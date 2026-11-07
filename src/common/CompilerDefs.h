/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef TRINITY_COMPILERDEFS_H
#define TRINITY_COMPILERDEFS_H

#define TRINITY_PLATFORM_WINDOWS 0
#define TRINITY_PLATFORM_UNIX    1
#define TRINITY_PLATFORM_APPLE   2

#if defined( _WIN32 )
#  define TRINITY_PLATFORM TRINITY_PLATFORM_WINDOWS
#elif defined( __APPLE__ )
#  define TRINITY_PLATFORM TRINITY_PLATFORM_APPLE
#else
#  define TRINITY_PLATFORM TRINITY_PLATFORM_UNIX
#endif

#define TRINITY_COMPILER_MICROSOFT_FLAG(on) ((on) << 0)
#define TRINITY_COMPILER_GCC_FLAG(on)       ((on) << 1)
#define TRINITY_COMPILER_CLANG_FLAG(on)     ((on) << 2)
#define TRINITY_COMPILER_INTEL_FLAG(on)     ((on) << 3)

#ifdef _MSC_VER
#  define TRINITY_COMPILER_MICROSOFT_DETECTED 1
#else
#  define TRINITY_COMPILER_MICROSOFT_DETECTED 0
#endif

#ifdef __GNUC__
#  define TRINITY_COMPILER_GCC_DETECTED 1
#else
#  define TRINITY_COMPILER_GCC_DETECTED 0
#endif

#ifdef __clang__
#  define TRINITY_COMPILER_CLANG_DETECTED 1
#else
#  define TRINITY_COMPILER_CLANG_DETECTED 0
#endif

#ifdef __INTEL_COMPILER
#  define TRINITY_COMPILER_INTEL_DETECTED 1
#else
#  define TRINITY_COMPILER_INTEL_DETECTED 0
#endif

#define TRINITY_COMPILER \
    ( TRINITY_COMPILER_MICROSOFT_FLAG(TRINITY_COMPILER_MICROSOFT_DETECTED) \
    | TRINITY_COMPILER_GCC_FLAG(TRINITY_COMPILER_GCC_DETECTED) \
    | TRINITY_COMPILER_CLANG_FLAG(TRINITY_COMPILER_CLANG_DETECTED) \
    | TRINITY_COMPILER_INTEL_FLAG(TRINITY_COMPILER_INTEL_DETECTED) )

#if TRINITY_COMPILER == 0
#  error "FATAL ERROR: Unknown compiler."
#endif

#define TRINITY_COMPILER_IS(compiler) (((TRINITY_COMPILER) & (compiler)) != 0)
#define TRINITY_COMPILER_IS_MICROSOFT TRINITY_COMPILER_IS(TRINITY_COMPILER_MICROSOFT_FLAG(1))
#define TRINITY_COMPILER_IS_GCC       TRINITY_COMPILER_IS(TRINITY_COMPILER_GCC_FLAG(1))
#define TRINITY_COMPILER_IS_CLANG     TRINITY_COMPILER_IS(TRINITY_COMPILER_CLANG_FLAG(1))
#define TRINITY_COMPILER_IS_INTEL     TRINITY_COMPILER_IS(TRINITY_COMPILER_INTEL_FLAG(1))

#endif
