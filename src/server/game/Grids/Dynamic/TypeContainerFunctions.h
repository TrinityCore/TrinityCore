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

#ifndef TYPECONTAINER_FUNCTIONS_H
#define TYPECONTAINER_FUNCTIONS_H

/*
 * Here you'll find a list of helper functions to make
 * the TypeContainer usefull.  Without it, its hard
 * to access or mutate the container.
 */

#include "Define.h"
#include "Dynamic/TypeList.h"
#include <map>
#include <unordered_map>

namespace Trinity
{
    // Helpers
    // Insert helpers
    template<class SPECIFIC_TYPE, class KEY_TYPE>
    bool Insert(ContainerUnorderedMap<SPECIFIC_TYPE, KEY_TYPE>& elements, KEY_TYPE const& handle, SPECIFIC_TYPE* obj)
    {
        auto i = elements._element.find(handle);
        if (i == elements._element.end())
        {
            elements._element[handle] = obj;
            return true;
        }
        else
        {
            ASSERT(i->second == obj, "Object with certain key already in but objects are different!");
            return false;
        }
    }

    template<class SPECIFIC_TYPE, class KEY_TYPE>
    bool Insert(ContainerUnorderedMap<TypeNull, KEY_TYPE>& /*elements*/, KEY_TYPE const& /*handle*/, SPECIFIC_TYPE* /*obj*/)
    {
        return false;
    }

    template<class SPECIFIC_TYPE, class KEY_TYPE, class T>
    bool Insert(ContainerUnorderedMap<T, KEY_TYPE>& /*elements*/, KEY_TYPE const& /*handle*/, SPECIFIC_TYPE* /*obj*/)
    {
        return false;
    }

    template<class SPECIFIC_TYPE, class KEY_TYPE, class H, class T>
    bool Insert(ContainerUnorderedMap<TypeList<H, T>, KEY_TYPE>& elements, KEY_TYPE const& handle, SPECIFIC_TYPE* obj)
    {
        bool ret = Insert(elements._elements, handle, obj);
        return ret ? ret : Insert(elements._TailElements, handle, obj);
    }

    // Find helpers
    template<class SPECIFIC_TYPE, class KEY_TYPE>
    SPECIFIC_TYPE* Find(ContainerUnorderedMap<SPECIFIC_TYPE, KEY_TYPE> const& elements, KEY_TYPE const& handle, SPECIFIC_TYPE* /*obj*/)
    {
        auto i = elements._element.find(handle);
        if (i == elements._element.end())
            return nullptr;
        else
            return i->second;
    }

    template<class SPECIFIC_TYPE, class KEY_TYPE>
    SPECIFIC_TYPE* Find(ContainerUnorderedMap<TypeNull, KEY_TYPE> const& /*elements*/, KEY_TYPE const& /*handle*/, SPECIFIC_TYPE* /*obj*/)
    {
        return nullptr;
    }

    template<class SPECIFIC_TYPE, class KEY_TYPE, class T>
    SPECIFIC_TYPE* Find(ContainerUnorderedMap<T, KEY_TYPE> const& /*elements*/, KEY_TYPE const& /*handle*/, SPECIFIC_TYPE* /*obj*/)
    {
        return nullptr;
    }

    template<class SPECIFIC_TYPE, class KEY_TYPE, class H, class T>
    SPECIFIC_TYPE* Find(ContainerUnorderedMap<TypeList<H, T>, KEY_TYPE> const& elements, KEY_TYPE const& handle, SPECIFIC_TYPE* /*obj*/)
    {
        SPECIFIC_TYPE* ret = Find(elements._elements, handle, (SPECIFIC_TYPE*)nullptr);
        return ret ? ret : Find(elements._TailElements, handle, (SPECIFIC_TYPE*)nullptr);
    }

    // Erase helpers
    template<class SPECIFIC_TYPE, class KEY_TYPE>
    bool Remove(ContainerUnorderedMap<SPECIFIC_TYPE, KEY_TYPE>& elements, KEY_TYPE const& handle, SPECIFIC_TYPE* /*obj*/)
    {
        elements._element.erase(handle);
        return true;
    }

    template<class SPECIFIC_TYPE, class KEY_TYPE>
    bool Remove(ContainerUnorderedMap<TypeNull, KEY_TYPE>& /*elements*/, KEY_TYPE const& /*handle*/, SPECIFIC_TYPE* /*obj*/)
    {
        return false;
    }

    template<class SPECIFIC_TYPE, class KEY_TYPE, class T>
    bool Remove(ContainerUnorderedMap<T, KEY_TYPE>& /*elements*/, KEY_TYPE const& /*handle*/, SPECIFIC_TYPE* /*obj*/)
    {
        return false;
    }

    template<class SPECIFIC_TYPE, class KEY_TYPE, class H, class T>
    bool Remove(ContainerUnorderedMap<TypeList<H, T>, KEY_TYPE>& elements, KEY_TYPE const& handle, SPECIFIC_TYPE* /*obj*/)
    {
        bool ret = Remove(elements._elements, handle, (SPECIFIC_TYPE*)nullptr);
        return ret ? ret : Remove(elements._TailElements, handle, (SPECIFIC_TYPE*)nullptr);
    }

    // Count helpers
    template<class SPECIFIC_TYPE, class KEY_TYPE>
    bool Size(ContainerUnorderedMap<SPECIFIC_TYPE, KEY_TYPE> const& elements, std::size_t* size, SPECIFIC_TYPE* /*obj*/)
    {
        *size = elements._element.size();
        return true;
    }

    template<class SPECIFIC_TYPE, class KEY_TYPE>
    bool Size(ContainerUnorderedMap<TypeNull, KEY_TYPE> const& /*elements*/, std::size_t* /*size*/, SPECIFIC_TYPE* /*obj*/)
    {
        return false;
    }

    template<class SPECIFIC_TYPE, class KEY_TYPE, class T>
    bool Size(ContainerUnorderedMap<T, KEY_TYPE> const& /*elements*/, std::size_t* /*size*/, SPECIFIC_TYPE* /*obj*/)
    {
        return false;
    }

    template<class SPECIFIC_TYPE, class KEY_TYPE, class H, class T>
    bool Size(ContainerUnorderedMap<TypeList<H, T>, KEY_TYPE> const& elements, std::size_t* size, SPECIFIC_TYPE* /*obj*/)
    {
        bool ret = Size(elements._elements, size, (SPECIFIC_TYPE*)nullptr);
        return ret ? ret : Size(elements._TailElements, size, (SPECIFIC_TYPE*)nullptr);
    }

    /* ContainerMapList Helpers */
    // count functions
    template<class SPECIFIC_TYPE>
    size_t Count(ContainerMapList<SPECIFIC_TYPE> const& elements, SPECIFIC_TYPE* /*fake*/)
    {
        return elements._element.getSize();
    }

    template<class SPECIFIC_TYPE>
    size_t Count(ContainerMapList<TypeNull> const& /*elements*/, SPECIFIC_TYPE* /*fake*/)
    {
        return 0;
    }

    template<class SPECIFIC_TYPE, class T>
    size_t Count(ContainerMapList<T> const& /*elements*/, SPECIFIC_TYPE* /*fake*/)
    {
        return 0;
    }

    template<class SPECIFIC_TYPE, class T>
    size_t Count(ContainerMapList<TypeList<SPECIFIC_TYPE, T>> const& elements, SPECIFIC_TYPE* fake)
    {
        return Count(elements._elements, fake);
    }

    template<class SPECIFIC_TYPE, class H, class T>
    size_t Count(ContainerMapList<TypeList<H, T>> const& elements, SPECIFIC_TYPE* fake)
    {
        return Count(elements._TailElements, fake);
    }

    // non-const insert functions
    template<class SPECIFIC_TYPE>
    SPECIFIC_TYPE* Insert(ContainerMapList<SPECIFIC_TYPE>& elements, SPECIFIC_TYPE* obj)
    {
        //elements._element[hdl] = obj;
        obj->AddToGrid(elements._element);
        return obj;
    }

    template<class SPECIFIC_TYPE>
    SPECIFIC_TYPE* Insert(ContainerMapList<TypeNull>& /*elements*/, SPECIFIC_TYPE* /*obj*/)
    {
        return nullptr;
    }

    // this is a missed
    template<class SPECIFIC_TYPE, class T>
    SPECIFIC_TYPE* Insert(ContainerMapList<T>& /*elements*/, SPECIFIC_TYPE* /*obj*/)
    {
        return nullptr;                                        // a missed
    }

    // Recursion
    template<class SPECIFIC_TYPE, class H, class T>
    SPECIFIC_TYPE* Insert(ContainerMapList<TypeList<H, T>>& elements, SPECIFIC_TYPE* obj)
    {
        SPECIFIC_TYPE* t = Insert(elements._elements, obj);
        return (t != nullptr ? t : Insert(elements._TailElements, obj));
    }

    //// non-const remove method
    //template<class SPECIFIC_TYPE> SPECIFIC_TYPE* Remove(ContainerMapList<SPECIFIC_TYPE> & /*elements*/, SPECIFIC_TYPE *obj)
    //{
    //    obj->GetGridRef().unlink();
    //    return obj;
    //}

    //template<class SPECIFIC_TYPE> SPECIFIC_TYPE* Remove(ContainerMapList<TypeNull> &/*elements*/, SPECIFIC_TYPE * /*obj*/)
    //{
    //    return nullptr;
    //}

    //// this is a missed
    //template<class SPECIFIC_TYPE, class T> SPECIFIC_TYPE* Remove(ContainerMapList<T> &/*elements*/, SPECIFIC_TYPE * /*obj*/)
    //{
    //    return nullptr;                                        // a missed
    //}

    //template<class SPECIFIC_TYPE, class T, class H> SPECIFIC_TYPE* Remove(ContainerMapList<TypeList<H, T> > &elements, SPECIFIC_TYPE *obj)
    //{
    //    // The head element is bad
    //    SPECIFIC_TYPE* t = Remove(elements._elements, obj);
    //    return (t != nullptr ? t : Remove(elements._TailElements, obj));
    //}
}
#endif
