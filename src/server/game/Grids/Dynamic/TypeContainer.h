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

#ifndef TRINITY_TYPECONTAINER_H
#define TRINITY_TYPECONTAINER_H

/*
 * Here, you'll find a series of containers that allow you to hold multiple
 * types of object at the same time.
 */

#include "Define.h"
#include <type_traits>

template <template <typename> typename UnderlyingContainer, typename... Types>
struct TypeListContainerStorage
{
    // empty case
};

template <template <typename> typename UnderlyingContainer, typename First, typename... Rest>
struct TypeListContainerStorage<UnderlyingContainer, First, Rest...>
{
    typename UnderlyingContainer<First>::Container Head;
    TypeListContainerStorage<UnderlyingContainer, Rest...> Tail;

    template <typename ObjectType>
    typename UnderlyingContainer<ObjectType>::Container& FindContainer()
    {
        if constexpr (std::is_same_v<First, ObjectType>)
            return Head;
        else
            return Tail.template FindContainer<ObjectType>();
    }

    template <typename ObjectType>
    typename UnderlyingContainer<ObjectType>::Container const& FindContainer() const
    {
        if constexpr (std::is_same_v<First, ObjectType>)
            return Head;
        else
            return Tail.template FindContainer<ObjectType>();
    }
};

template <template <typename> typename UnderlyingContainer, typename... Types>
struct TypeListContainer
{
    TypeListContainerStorage<UnderlyingContainer, Types...> Data;

    template <typename ObjectType>
    static constexpr bool TypeExists = std::disjunction_v<std::is_same<ObjectType, Types>...>;

    template <typename ObjectType> requires TypeExists<ObjectType>
    bool Insert(ObjectType* object)
    {
        return UnderlyingContainer<ObjectType>::Insert(Data.template FindContainer<ObjectType>(), object);
    }

    template <typename ObjectType> requires TypeExists<ObjectType>
    bool Remove(ObjectType* object)
    {
        return UnderlyingContainer<ObjectType>::Remove(Data.template FindContainer<ObjectType>(), object);
    }

    template <typename ObjectType> requires TypeExists<ObjectType>
    bool Size() const
    {
        return UnderlyingContainer<ObjectType>::Size(Data.template FindContainer<ObjectType>());
    }

    template <typename ObjectType> requires TypeExists<ObjectType> && requires { typename UnderlyingContainer<ObjectType>::KeyType; }
    ObjectType* Find(typename UnderlyingContainer<ObjectType>::KeyType const& key) const
    {
        return UnderlyingContainer<ObjectType>::Find(Data.template FindContainer<ObjectType>(), key);
    }
};

#endif
