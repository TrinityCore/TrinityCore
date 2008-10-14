/* 
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: MaNGOS <http://www.mangosproject.org/>
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

#ifndef TRINITY_HASHMAP_H
#define TRINITY_HASHMAP_H

#include "Platform/CompilerDefs.h"
#include "Platform/Define.h"

#if COMPILER == COMPILER_INTEL
#include <ext/hash_map>
#elif COMPILER == COMPILER_GNU && __GNUC__ >= 3
#include <ext/hash_map>
#else
#include <hash_map>
#endif

#ifdef _STLPORT_VERSION
#define HM_NAMESPACE std
using std::hash_map;
#elif COMPILER == COMPILER_MICROSOFT && _MSC_VER >= 1300
#define HM_NAMESPACE stdext
using stdext::hash_map;
#elif COMPILER == COMPILER_INTEL
#define HM_NAMESPACE std
using std::hash_map;
#elif COMPILER == COMPILER_GNU && __GNUC__ >= 3
#define HM_NAMESPACE __gnu_cxx
using __gnu_cxx::hash_map;

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
#define HM_NAMESPACE std
using std::hash_map;
#endif
#endif
