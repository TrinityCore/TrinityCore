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

#define TRINITY_COMPILER_MICROSOFT 0
#define TRINITY_COMPILER_GNU       1
#define TRINITY_COMPILER_INTEL     2

#ifdef _MSC_VER
#  define TRINITY_COMPILER TRINITY_COMPILER_MICROSOFT
#elif defined( __INTEL_COMPILER )
#  define TRINITY_COMPILER TRINITY_COMPILER_INTEL
#elif defined( __GNUC__ )
#  define TRINITY_COMPILER TRINITY_COMPILER_GNU
#  define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#else
#  error "FATAL ERROR: Unknown compiler."
#endif

#endif
