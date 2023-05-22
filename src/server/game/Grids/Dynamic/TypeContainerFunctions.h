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

namespace Trinity
{
    // Helpers
    // Insert helpers
    template<class SPECIFIC_TYPE, class KEY_TYPE, class H, class T>
    inline bool Insert(ContainerUnorderedMap<TypeList<H, T>, KEY_TYPE>& elements, KEY_TYPE const& handle, SPECIFIC_TYPE* obj)
    {
        if constexpr (std::is_same_v<H, SPECIFIC_TYPE>)
        {
            auto i = elements._elements._element.find(handle);
            if (i == elements._elements._element.end())
            {
                elements._elements._element[handle] = obj;
                return true;
            }
            else
            {
                ASSERT(i->second == obj, "Object with certain key already in but objects are different!");
                return false;
            }
        }

        if constexpr (std::is_same_v<T, TypeNull>)
            return false;
        else
            return Insert(elements._TailElements, handle, obj);
    }

    // Find helpers
    template<class SPECIFIC_TYPE, class KEY_TYPE, class H, class T>
    inline SPECIFIC_TYPE* Find(ContainerUnorderedMap<TypeList<H, T>, KEY_TYPE> const& elements, KEY_TYPE const& handle, SPECIFIC_TYPE* obj)
    {
        if constexpr (std::is_same_v<H, SPECIFIC_TYPE>)
        {
            auto i = elements._elements._element.find(handle);
            if (i == elements._elements._element.end())
                return nullptr;
            else
                return i->second;
        }

        if constexpr (std::is_same_v<T, TypeNull>)
            return nullptr;
        else
            return Find(elements._TailElements, handle, obj);
    }

    // Erase helpers
    template<class SPECIFIC_TYPE, class KEY_TYPE, class H, class T>
    inline bool Remove(ContainerUnorderedMap<TypeList<H, T>, KEY_TYPE>& elements, KEY_TYPE const& handle, SPECIFIC_TYPE* obj)
    {
        if constexpr (std::is_same_v<H, SPECIFIC_TYPE>)
        {
            elements._elements._element.erase(handle);
            return true;
        }

        if constexpr (std::is_same_v<T, TypeNull>)
            return false;
        else
            return Remove(elements._TailElements, handle, obj);
    }

    // Count helpers
    template<class SPECIFIC_TYPE, class KEY_TYPE, class H, class T>
    inline bool Size(ContainerUnorderedMap<TypeList<H, T>, KEY_TYPE> const& elements, std::size_t* size, SPECIFIC_TYPE* obj)
    {
        if constexpr (std::is_same_v<H, SPECIFIC_TYPE>)
        {
            *size = elements._elements._element.size();
            return true;
        }

        if constexpr (std::is_same_v<T, TypeNull>)
            return false;
        else
            return Size(elements._TailElements, size, obj);
    }

    /* ContainerMapList Helpers */
    // count functions
    template<class SPECIFIC_TYPE, class H, class T>
    inline size_t Count(ContainerMapList<TypeList<H, T>> const& elements, SPECIFIC_TYPE* fake)
    {
        if constexpr (std::is_same_v<H, SPECIFIC_TYPE>)
        {
            return elements._elements._element.getSize();
        }

        if constexpr (std::is_same_v<T, TypeNull>)
            return 0;
        else
            return Count(elements._TailElements, fake);
    }

    // non-const insert functions
    template<class SPECIFIC_TYPE, class H, class T>
    inline SPECIFIC_TYPE* Insert(ContainerMapList<TypeList<H, T>>& elements, SPECIFIC_TYPE* obj)
    {
        if constexpr (std::is_same_v<H, SPECIFIC_TYPE>)
        {
            obj->AddToGrid(elements._elements._element);
            return obj;
        }

        if constexpr (std::is_same_v<T, TypeNull>)
            return nullptr;
        else
            return Insert(elements._TailElements, obj);
    }

    //// non-const remove method
    //template<class SPECIFIC_TYPE, class H, class T>
    //SPECIFIC_TYPE* Remove(ContainerMapList<TypeList<H, T>>& elements, SPECIFIC_TYPE* obj)
    //{
    //    if constexpr (std::is_same_v<H, SPECIFIC_TYPE>)
    //    {
    //        obj->GetGridRef().unlink();
    //        return obj;
    //    }

    //    if constexpr (std::is_same_v<T, TypeNull>)
    //        return nullptr;
    //    else
    //        return Remove(elements._TailElements, obj);
    //}
}
#endif
