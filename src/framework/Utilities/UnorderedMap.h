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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef TRINITY_UNORDERED_MAP_H
#define TRINITY_UNORDERED_MAP_H
#include "Platform/CompilerDefs.h"
#include "Platform/Define.h"
#if COMPILER == COMPILER_INTEL
#include <ext/hash_map>
#elif COMPILER == COMPILER_GNU && (__GNUC__ > 4 || __GNUC__ == 4 && __GNUC_MINOR__ >= 3)
#include <tr1/unordered_map>
#elif COMPILER == COMPILER_GNU && __GNUC__ >= 3
#include <ext/hash_map>
#elif COMPILER == COMPILER_MICROSOFT && _MSC_VER >= 1500 && _HAS_TR1    // VC9.0 and later
#include <unordered_map>
#else
#include <hash_map>
#endif
#ifdef _STLPORT_VERSION
#define UNORDERED_MAP std::hash_map
using std::hash_map;
#elif COMPILER == COMPILER_MICROSOFT && _MSC_VER >= 1500 && _HAS_TR1
#define UNORDERED_MAP std::tr1::unordered_map
#elif COMPILER == COMPILER_MICROSOFT && _MSC_VER >= 1300
#define UNORDERED_MAP stdext::hash_map
using stdext::hash_map;
#elif COMPILER == COMPILER_INTEL
#define UNORDERED_MAP std::hash_map
using std::hash_map;
#elif COMPILER == COMPILER_GNU && (__GNUC__ > 4 || __GNUC__ == 4 && __GNUC_MINOR__ >= 3)
#define UNORDERED_MAP std::tr1::unordered_map
#elif COMPILER == COMPILER_GNU && __GNUC__ >= 3
#define UNORDERED_MAP __gnu_cxx::hash_map
namespace __gnu_cxx
{
    template<> struct hash<unsigned long long>
    {
        size_t operator()(const unsigned long long &__x) const { return (size_t)__x; }
    };
    template<typename T> struct hash<T *>
    {
        size_t operator()(T * const &__x) const { return (size_t)__x; }
    };
};
#else
#define UNORDERED_MAP std::hash_map
using std::hash_map;
#endif
#endif

