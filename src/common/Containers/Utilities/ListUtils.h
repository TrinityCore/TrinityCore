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

#ifndef TRINITYCORE_LIST_UTILS_H
#define TRINITYCORE_LIST_UTILS_H

#include <forward_list>
#include <list>

namespace Trinity::Containers::Lists
{
template<typename T, typename Alloc = std::allocator<T>>
inline typename std::list<T, Alloc>::iterator RemoveUnique(std::list<T, Alloc>& list, std::type_identity_t<T> const& value)
{
    auto itr = std::find(list.begin(), list.end(), value);
    if (itr != list.end())
        return list.erase(itr);

    return list.end();
}

template<typename T, typename Alloc = std::allocator<T>>
inline typename std::forward_list<T, Alloc>::iterator RemoveUnique(std::forward_list<T, Alloc>& list, std::type_identity_t<T> const& value)
{
    auto itr = list.before_begin();
    auto toErase = std::next(itr);
    while (toErase != list.end())
    {
        if (*toErase == value)
            return list.erase_after(itr);

        itr = toErase++;
    }

    return list.end();
}
}

#endif // TRINITYCORE_LIST_UTILS_H
