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

#include <unordered_map>
#include "Define.h"
#include "Dynamic/TypeList.h"
#include "GridRefManager.h"

/*
 * @class ContainerMapList is a mulit-type container for map elements
 * By itself its meaningless but collaborate along with TypeContainers,
 * it become the most powerfully container in the whole system.
 */
template<class OBJECT>
struct ContainerMapList
{
    GridRefManager<OBJECT> _element;
};

template<>
struct ContainerMapList<TypeNull>                /* nothing is in type null */
{
};

template<class H, class T>
struct ContainerMapList<TypeList<H, T> >
{
    ContainerMapList<H> _elements;
    ContainerMapList<T> _TailElements;
};

template<class OBJECT, class KEY_TYPE>
struct ContainerUnorderedMap
{
    std::unordered_map<KEY_TYPE, OBJECT*> _element;
};

template<class KEY_TYPE>
struct ContainerUnorderedMap<TypeNull, KEY_TYPE>
{
};

template<class H, class T, class KEY_TYPE>
struct ContainerUnorderedMap<TypeList<H, T>, KEY_TYPE>
{
    ContainerUnorderedMap<H, KEY_TYPE> _elements;
    ContainerUnorderedMap<T, KEY_TYPE> _TailElements;
};

#include "TypeContainerFunctions.h"

/*
 * @class TypeMapContainer contains a fixed number of types and is
 * determined at compile time.  This is probably the most complicated
 * class and do its simplest thing, that is, holds objects
 * of different types.
 */

template<class OBJECT_TYPES>
class TypeMapContainer
{
public:
    TypeMapContainer();
    TypeMapContainer(TypeMapContainer const&) = default;
    TypeMapContainer(TypeMapContainer&&) noexcept = default;
    TypeMapContainer& operator=(TypeMapContainer const&) = default;
    TypeMapContainer& operator=(TypeMapContainer&&) noexcept = default;
    ~TypeMapContainer();

    template<class SPECIFIC_TYPE>
    size_t Count() const;

    /// inserts a specific object into the container
    template<class SPECIFIC_TYPE>
    bool insert(SPECIFIC_TYPE *obj);

    ///  Removes the object from the container, and returns the removed object
    //template<class SPECIFIC_TYPE>
    //bool remove(SPECIFIC_TYPE* obj)
    //{
    //    SPECIFIC_TYPE* t = Trinity::Remove(i_elements, obj);
    //    return (t != nullptr);
    //}

    ContainerMapList<OBJECT_TYPES>& GetElements(void);
    const ContainerMapList<OBJECT_TYPES>& GetElements(void) const;

private:
    ContainerMapList<OBJECT_TYPES> i_elements;
};

template <class OBJECT_TYPES>
TypeMapContainer<OBJECT_TYPES>::TypeMapContainer() = default;

template <class OBJECT_TYPES>
TypeMapContainer<OBJECT_TYPES>::~TypeMapContainer() = default;

template <class OBJECT_TYPES>
template <class SPECIFIC_TYPE>
size_t TypeMapContainer<OBJECT_TYPES>::Count() const
{
    return Trinity::Count(i_elements, (SPECIFIC_TYPE*)nullptr);
}

template <class OBJECT_TYPES>
template <class SPECIFIC_TYPE>
bool TypeMapContainer<OBJECT_TYPES>::insert(SPECIFIC_TYPE* obj)
{
    SPECIFIC_TYPE* t = Trinity::Insert(i_elements, obj);
    return (t != nullptr);
}

template <class OBJECT_TYPES>
ContainerMapList<OBJECT_TYPES>& TypeMapContainer<OBJECT_TYPES>::GetElements()
{
    return i_elements;
}

template <class OBJECT_TYPES>
const ContainerMapList<OBJECT_TYPES>& TypeMapContainer<OBJECT_TYPES>::GetElements() const
{
    return i_elements;
}

template<class OBJECT_TYPES, class KEY_TYPE>
class TypeUnorderedMapContainer
{
public:
    TypeUnorderedMapContainer();
    TypeUnorderedMapContainer(TypeUnorderedMapContainer const&) = default;
    TypeUnorderedMapContainer(TypeUnorderedMapContainer&&) noexcept = default;
    TypeUnorderedMapContainer& operator=(TypeUnorderedMapContainer const&) = default;
    TypeUnorderedMapContainer& operator=(TypeUnorderedMapContainer&&) noexcept = default;
    ~TypeUnorderedMapContainer();

    template<class SPECIFIC_TYPE>
    bool Insert(KEY_TYPE const& handle, SPECIFIC_TYPE* obj);

    template<class SPECIFIC_TYPE>
    bool Remove(KEY_TYPE const& handle);

    template<class SPECIFIC_TYPE>
    SPECIFIC_TYPE* Find(KEY_TYPE const& handle);

    template<class SPECIFIC_TYPE>
    std::size_t Size() const;

    ContainerUnorderedMap<OBJECT_TYPES, KEY_TYPE>& GetElements();
    ContainerUnorderedMap<OBJECT_TYPES, KEY_TYPE> const& GetElements() const;

private:
    ContainerUnorderedMap<OBJECT_TYPES, KEY_TYPE> _elements;
};

template <class OBJECT_TYPES, class KEY_TYPE>
TypeUnorderedMapContainer<OBJECT_TYPES, KEY_TYPE>::TypeUnorderedMapContainer() = default;

template <class OBJECT_TYPES, class KEY_TYPE>
TypeUnorderedMapContainer<OBJECT_TYPES, KEY_TYPE>::~TypeUnorderedMapContainer() = default;

template <class OBJECT_TYPES, class KEY_TYPE>
template <class SPECIFIC_TYPE>
bool TypeUnorderedMapContainer<OBJECT_TYPES, KEY_TYPE>::Insert(KEY_TYPE const& handle, SPECIFIC_TYPE* obj)
{
    return Trinity::Insert(_elements, handle, obj);
}

template <class OBJECT_TYPES, class KEY_TYPE>
template <class SPECIFIC_TYPE>
bool TypeUnorderedMapContainer<OBJECT_TYPES, KEY_TYPE>::Remove(KEY_TYPE const& handle)
{
    return Trinity::Remove(_elements, handle, (SPECIFIC_TYPE*)nullptr);
}

template <class OBJECT_TYPES, class KEY_TYPE>
template <class SPECIFIC_TYPE>
SPECIFIC_TYPE* TypeUnorderedMapContainer<OBJECT_TYPES, KEY_TYPE>::Find(KEY_TYPE const& handle)
{
    return Trinity::Find(_elements, handle, (SPECIFIC_TYPE*)nullptr);
}

template <class OBJECT_TYPES, class KEY_TYPE>
template <class SPECIFIC_TYPE>
std::size_t TypeUnorderedMapContainer<OBJECT_TYPES, KEY_TYPE>::Size() const
{
    std::size_t size = 0;
    Trinity::Size(_elements, &size, (SPECIFIC_TYPE*)nullptr);
    return size;
}

template <class OBJECT_TYPES, class KEY_TYPE>
ContainerUnorderedMap<OBJECT_TYPES, KEY_TYPE>& TypeUnorderedMapContainer<OBJECT_TYPES, KEY_TYPE>::GetElements()
{
    return _elements;
}

template <class OBJECT_TYPES, class KEY_TYPE>
ContainerUnorderedMap<OBJECT_TYPES, KEY_TYPE> const& TypeUnorderedMapContainer<OBJECT_TYPES, KEY_TYPE>::GetElements() const
{
    return _elements;
}

#endif
