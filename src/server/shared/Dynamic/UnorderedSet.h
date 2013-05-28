/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef TRINITY_UNORDERED_SET_H
#define TRINITY_UNORDERED_SET_H

#include "HashNamespace.h"

#if COMPILER_HAS_CPP11_SUPPORT
# include <unordered_set>
#elif COMPILER == COMPILER_INTEL
# include <ext/hash_set>
#elif COMPILER == COMPILER_GNU && defined(__clang__) && defined(_LIBCPP_VERSION)
# include <unordered_set>
#elif COMPILER == COMPILER_GNU && GCC_VERSION > 40200
# include <tr1/unordered_set>
#elif COMPILER == COMPILER_GNU && GCC_VERSION >= 30000
# include <ext/hash_set>
#elif COMPILER == COMPILER_MICROSOFT && ((_MSC_VER >= 1500 && _HAS_TR1) || _MSC_VER >= 1700) // VC9.0 SP1 and later
# include <unordered_set>
#else
# include <hash_set>
#endif

#ifdef _STLPORT_VERSION
# define UNORDERED_SET std::hash_set
using std::hash_set;
#elif COMPILER_HAS_CPP11_SUPPORT
# define UNORDERED_SET std::unordered_set
#elif COMPILER == COMPILER_MICROSOFT && _MSC_VER >= 1600 // VS100
# define UNORDERED_SET std::tr1::unordered_set
#elif COMPILER == COMPILER_MICROSOFT && _MSC_VER >= 1500 && _HAS_TR1
# define UNORDERED_SET std::tr1::unordered_set
#elif COMPILER == COMPILER_MICROSOFT && _MSC_VER >= 1300
# define UNORDERED_SET stdext::hash_set
using stdext::hash_set;
#elif COMPILER == COMPILER_INTEL
# define UNORDERED_SET std::hash_set
using std::hash_set;
#elif COMPILER == COMPILER_GNU && defined(__clang__) && defined(_LIBCPP_VERSION)
# define UNORDERED_SET std::unordered_set
#elif COMPILER == COMPILER_GNU && GCC_VERSION > 40200
# define UNORDERED_SET std::tr1::unordered_set
#elif COMPILER == COMPILER_GNU && GCC_VERSION >= 30000
# define UNORDERED_SET __gnu_cxx::hash_set
#else
# define UNORDERED_SET std::hash_set
using std::hash_set;
#endif

#endif
