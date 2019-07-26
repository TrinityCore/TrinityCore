/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TrinityCore_Hash_h__
#define TrinityCore_Hash_h__

#include <functional>
#include <utility>

namespace Trinity
{
    template<typename T>
    inline void hash_combine(std::size_t& seed, T const& val)
    {
        seed ^= std::hash<T>()(val) + 0x9E3779B9 + (seed << 6) + (seed >> 2);
    }
}

 //! Hash implementation for std::pair to allow using pairs in unordered_set or as key for unordered_map
 //! Individual types used in pair must be hashable by std::hash
namespace std
{
    template<class K, class V>
    struct hash<std::pair<K, V>>
    {
    public:
        size_t operator()(std::pair<K, V> const& p) const
        {
            size_t hashVal = 0;
            Trinity::hash_combine(hashVal, p.first);
            Trinity::hash_combine(hashVal, p.second);
            return hashVal;
        }
    };
}

//! Hash implementation for std::tuple to allow using tuples in unordered_set or as key for unordered_map
//! Individual types used in tuple must be hashable by std::hash
namespace std
{
    template<class T1>
    struct hash<std::tuple<T1>>
    {
    public:
        size_t operator()(std::tuple<T1> const& p) const
        {
            size_t hashVal = 0;
            Trinity::hash_combine(hashVal, std::get<0>(p));
            return hashVal;
        }
    };

    template<class T1, class T2>
    struct hash<std::tuple<T1, T2>>
    {
    public:
        size_t operator()(std::tuple<T1, T2> const& p) const
        {
            size_t hashVal = 0;
            Trinity::hash_combine(hashVal, std::get<0>(p));
            Trinity::hash_combine(hashVal, std::get<1>(p));
            return hashVal;
        }
    };

    template<class T1, class T2, class T3>
    struct hash<std::tuple<T1, T2, T3>>
    {
    public:
        size_t operator()(std::tuple<T1, T2, T3> const& p) const
        {
            size_t hashVal = 0;
            Trinity::hash_combine(hashVal, std::get<0>(p));
            Trinity::hash_combine(hashVal, std::get<1>(p));
            Trinity::hash_combine(hashVal, std::get<2>(p));
            return hashVal;
        }
    };
}

#endif // TrinityCore_Hash_h__
