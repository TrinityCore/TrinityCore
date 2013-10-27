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

#ifndef TRINITY_TYPECONTAINER_H
#define TRINITY_TYPECONTAINER_H

/*
 * Here, you'll find a series of containers that allow you to hold multiple
 * types of object at the same time.
 */

#include <map>
#include <vector>
#include "Define.h"
#include "Dynamic/TypeList.h"
#include "GridRefManager.h"

/*
 * @class ContainerMapList is a mulit-type container for map elements
 * By itself its meaningless but collaborate along with TypeContainers,
 * it become the most powerfully container in the whole system.
 */
template<class OBJECT> struct ContainerMapList
{
    //std::map<OBJECT_HANDLE, OBJECT *> _element;
    GridRefManager<OBJECT> _element;
};

template<> struct ContainerMapList<TypeNull>                /* nothing is in type null */
{
};
template<class H, class T> struct ContainerMapList<TypeList<H, T> >
{
    ContainerMapList<H> _elements;
    ContainerMapList<T> _TailElements;
};

/*
 * @class ContaierArrayList is a multi-type container for
 * array of elements.
 */
template<class OBJECT> struct ContainerArrayList
{
    std::vector<OBJECT> _element;
};

// termination condition
template<> struct ContainerArrayList<TypeNull> { };
// recursion
template<class H, class T> struct ContainerArrayList<TypeList<H, T> >
{
    ContainerArrayList<H> _elements;
    ContainerArrayList<T> _TailElements;
};

/*
 * @class ContainerList is a simple list of different types of elements
 *
 */
template<class OBJECT> struct ContainerList
{
    OBJECT _element;
};

/* TypeNull is underfined */
template<> struct ContainerList<TypeNull> { };
template<class H, class T> struct ContainerList<TypeList<H, T> >
{
    ContainerList<H> _elements;
    ContainerMapList<T> _TailElements;
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
        template<class SPECIFIC_TYPE> size_t Count() const { return Trinity::Count(i_elements, (SPECIFIC_TYPE*)NULL); }

        /// inserts a specific object into the container
        template<class SPECIFIC_TYPE> bool insert(SPECIFIC_TYPE *obj)
        {
            SPECIFIC_TYPE* t = Trinity::Insert(i_elements, obj);
            return (t != NULL);
        }

        ///  Removes the object from the container, and returns the removed object
        //template<class SPECIFIC_TYPE> bool remove(SPECIFIC_TYPE* obj)
        //{
        //    SPECIFIC_TYPE* t = Trinity::Remove(i_elements, obj);
        //    return (t != NULL);
        //}

        ContainerMapList<OBJECT_TYPES> & GetElements(void) { return i_elements; }
        const ContainerMapList<OBJECT_TYPES> & GetElements(void) const { return i_elements;}

    private:
        ContainerMapList<OBJECT_TYPES> i_elements;
};
#endif

