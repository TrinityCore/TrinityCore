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

#ifndef TRINITYCORE_MAP_UTILS_H
#define TRINITYCORE_MAP_UTILS_H

#include <type_traits>

namespace Trinity::Containers
{
/**
 * Returns a pointer to mapped value (or the value itself if map stores pointers)
 */
template<class M>
auto MapGetValuePtr(M& map, typename M::key_type const& key)
{
    auto itr = map.find(key);
    if constexpr (std::is_pointer_v<typename M::mapped_type>)
        return itr != map.end() ? itr->second : nullptr;
    else
        return itr != map.end() ? &itr->second : nullptr;
}

template<class K, class V, template<class, class, class...> class M, class... Rest>
void MultimapErasePair(M<K, V, Rest...>& multimap, K const& key, V const& value)
{
    auto range = multimap.equal_range(key);
    for (auto itr = range.first; itr != range.second;)
    {
        if (itr->second == value)
            itr = multimap.erase(itr);
        else
            ++itr;
    }
}
}
#endif // TRINITYCORE_MAP_UTILS_H
