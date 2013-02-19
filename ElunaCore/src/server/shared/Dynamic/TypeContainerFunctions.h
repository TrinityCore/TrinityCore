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

namespace Trinity
{
    /* ContainerMapList Helpers */
    // count functions
    template<class SPECIFIC_TYPE> size_t Count(const ContainerMapList<SPECIFIC_TYPE> &elements, SPECIFIC_TYPE* /*fake*/)
    {
        return elements._element.getSize();
    }

    template<class SPECIFIC_TYPE> size_t Count(const ContainerMapList<TypeNull> &/*elements*/, SPECIFIC_TYPE* /*fake*/)
    {
        return 0;
    }

    template<class SPECIFIC_TYPE, class T> size_t Count(const ContainerMapList<T> &/*elements*/, SPECIFIC_TYPE* /*fake*/)
    {
        return 0;
    }

    template<class SPECIFIC_TYPE, class T> size_t Count(const ContainerMapList<TypeList<SPECIFIC_TYPE, T> >&elements, SPECIFIC_TYPE* fake)
    {
        return Count(elements._elements, fake);
    }

    template<class SPECIFIC_TYPE, class H, class T> size_t Count(const ContainerMapList<TypeList<H, T> >&elements, SPECIFIC_TYPE* fake)
    {
        return Count(elements._TailElements, fake);
    }

    // non-const insert functions
    template<class SPECIFIC_TYPE> SPECIFIC_TYPE* Insert(ContainerMapList<SPECIFIC_TYPE> &elements, SPECIFIC_TYPE *obj)
    {
        //elements._element[hdl] = obj;
        obj->AddToGrid(elements._element);
        return obj;
    }

    template<class SPECIFIC_TYPE> SPECIFIC_TYPE* Insert(ContainerMapList<TypeNull> &/*elements*/, SPECIFIC_TYPE * /*obj*/)
    {
        return NULL;
    }

    // this is a missed
    template<class SPECIFIC_TYPE, class T> SPECIFIC_TYPE* Insert(ContainerMapList<T> &/*elements*/, SPECIFIC_TYPE * /*obj*/)
    {
        return NULL;                                        // a missed
    }

    // Recursion
    template<class SPECIFIC_TYPE, class H, class T> SPECIFIC_TYPE* Insert(ContainerMapList<TypeList<H, T> >&elements, SPECIFIC_TYPE *obj)
    {
        SPECIFIC_TYPE* t= Insert(elements._elements, obj);
        return (t != NULL ? t : Insert(elements._TailElements, obj));
    }

    //// non-const remove method
    //template<class SPECIFIC_TYPE> SPECIFIC_TYPE* Remove(ContainerMapList<SPECIFIC_TYPE> & /*elements*/, SPECIFIC_TYPE *obj)
    //{
    //    obj->GetGridRef().unlink();
    //    return obj;
    //}

    //template<class SPECIFIC_TYPE> SPECIFIC_TYPE* Remove(ContainerMapList<TypeNull> &/*elements*/, SPECIFIC_TYPE * /*obj*/)
    //{
    //    return NULL;
    //}

    //// this is a missed
    //template<class SPECIFIC_TYPE, class T> SPECIFIC_TYPE* Remove(ContainerMapList<T> &/*elements*/, SPECIFIC_TYPE * /*obj*/)
    //{
    //    return NULL;                                        // a missed
    //}

    //template<class SPECIFIC_TYPE, class T, class H> SPECIFIC_TYPE* Remove(ContainerMapList<TypeList<H, T> > &elements, SPECIFIC_TYPE *obj)
    //{
    //    // The head element is bad
    //    SPECIFIC_TYPE* t = Remove(elements._elements, obj);
    //    return ( t != NULL ? t : Remove(elements._TailElements, obj) );
    //}
}
#endif

