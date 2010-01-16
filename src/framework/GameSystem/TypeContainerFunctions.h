/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TYPECONTAINER_FUNCTIONS_H
#define TYPECONTAINER_FUNCTIONS_H

/*
 * Here you'll find a list of helper functions to make
 * the TypeContainer usefull.  Without it, its hard
 * to access or mutate the container.
 */

#include "Platform/Define.h"
#include "Utilities/TypeList.h"
#include <map>

namespace Trinity
{
    /* ContainerMapList Helpers */
    // count functions
    template<class SPECIFIC_TYPE> size_t Count(const ContainerMapList<SPECIFIC_TYPE> &elements, SPECIFIC_TYPE* /*fake*/)
    {
        return elements._element.getSize();
    };

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
        return Count(elements._elements,fake);
    }

    template<class SPECIFIC_TYPE, class H, class T> size_t Count(const ContainerMapList<TypeList<H, T> >&elements, SPECIFIC_TYPE* fake)
    {
        return Count(elements._TailElements, fake);
    }

    // non-const find functions
    template<class SPECIFIC_TYPE> SPECIFIC_TYPE* Find(ContainerMapList<SPECIFIC_TYPE> &/*elements*/, OBJECT_HANDLE /*hdl*/, SPECIFIC_TYPE* /*fake*/)
    {
        //typename std::map<OBJECT_HANDLE, SPECIFIC_TYPE *>::iterator iter = elements._element.find(hdl);
        //return (iter == elements._element.end() ? NULL : iter->second);
        return NULL;
    };

    template<class SPECIFIC_TYPE> SPECIFIC_TYPE* Find(ContainerMapList<TypeNull> &/*elements*/, OBJECT_HANDLE /*hdl*/, SPECIFIC_TYPE* /*fake*/)
    {
        return NULL;                                        // terminate recursion
    }

    template<class SPECIFIC_TYPE, class T> SPECIFIC_TYPE* Find(ContainerMapList<T> &/*elements*/, OBJECT_HANDLE /*hdl*/, SPECIFIC_TYPE* /*fake*/)
    {
        return NULL;                                        // this is a missed
    }

    template<class SPECIFIC_TYPE, class H, class T> SPECIFIC_TYPE* Find(ContainerMapList<TypeList<H, T> >&/*elements*/, OBJECT_HANDLE /*hdl*/, SPECIFIC_TYPE* /*fake*/)
    {
        //SPECIFIC_TYPE* t = Find(elements._elements, hdl,fake);
        //return (t != NULL ? t :Find(elements._TailElements, hdl,fake));
        return NULL;
    }

    // const find functions
    template<class SPECIFIC_TYPE> const SPECIFIC_TYPE* Find(const ContainerMapList<SPECIFIC_TYPE> &/*elements*/, OBJECT_HANDLE /*hdl*/, SPECIFIC_TYPE* /*fake*/)
    {
        //typename SPECIFIC_TYPE::iterator iter = elements._element.find(hdl);
        //return (iter == elements._element.end() ? NULL : iter->second);
        return NULL;
    };

    template<class SPECIFIC_TYPE> const SPECIFIC_TYPE* Find(const ContainerMapList<TypeNull> &/*elements*/, OBJECT_HANDLE /*hdl*/, SPECIFIC_TYPE* /*fake*/)
    {
        return NULL;
    }

    template<class SPECIFIC_TYPE, class T> const SPECIFIC_TYPE* Find(const ContainerMapList<T> &/*elements*/, OBJECT_HANDLE /*hdl*/, SPECIFIC_TYPE* /*fake*/)
    {
        return NULL;
    }

    template<class SPECIFIC_TYPE, class H, class T> SPECIFIC_TYPE* Find(const ContainerMapList<TypeList<H, T> >&elements, OBJECT_HANDLE hdl, SPECIFIC_TYPE* fake)
    {
        SPECIFIC_TYPE* t = Find(elements._elements, hdl,fake);
        if( t)
            return t;

        return Find(elements._TailElement, hdl,fake);
    }

    // non-const insert functions
    template<class SPECIFIC_TYPE> SPECIFIC_TYPE* Insert(ContainerMapList<SPECIFIC_TYPE> &elements, SPECIFIC_TYPE *obj, OBJECT_HANDLE /*hdl*/)
    {
        //elements._element[hdl] = obj;
        obj->GetGridRef().link(&elements._element, obj);
        return obj;
    };

    template<class SPECIFIC_TYPE> SPECIFIC_TYPE* Insert(ContainerMapList<TypeNull> &/*elements*/, SPECIFIC_TYPE * /*obj*/, OBJECT_HANDLE /*hdl*/)
    {
        return NULL;
    }

    // this is a missed
    template<class SPECIFIC_TYPE, class T> SPECIFIC_TYPE* Insert(ContainerMapList<T> &/*elements*/, SPECIFIC_TYPE * /*obj*/, OBJECT_HANDLE /*hdl*/)
    {
        return NULL;                                        // a missed
    }

    // Recursion
    template<class SPECIFIC_TYPE, class H, class T> SPECIFIC_TYPE* Insert(ContainerMapList<TypeList<H, T> >&elements, SPECIFIC_TYPE *obj, OBJECT_HANDLE hdl)
    {
        SPECIFIC_TYPE* t= Insert(elements._elements, obj, hdl);
        return (t != NULL ? t : Insert(elements._TailElements, obj, hdl));
    }

    // non-const remove method
    template<class SPECIFIC_TYPE> SPECIFIC_TYPE* Remove(ContainerMapList<SPECIFIC_TYPE> & /*elements*/, SPECIFIC_TYPE *obj, OBJECT_HANDLE /*hdl*/)
    {
        /*typename std::map<OBJECT_HANDLE, SPECIFIC_TYPE *>::iterator iter = elements._element.find(hdl);
        if( iter != elements._element.end() )
        {
            SPECIFIC_TYPE* t = iter->second;
            elements._element.erase(iter);
            return t;
        }*/
        obj->GetGridRef().unlink();
        return obj;
    }

    template<class SPECIFIC_TYPE> SPECIFIC_TYPE* Remove(ContainerMapList<TypeNull> &/*elements*/, SPECIFIC_TYPE * /*obj*/, OBJECT_HANDLE /*hdl*/)
    {
        return NULL;
    }

    // this is a missed
    template<class SPECIFIC_TYPE, class T> SPECIFIC_TYPE* Remove(ContainerMapList<T> &/*elements*/, SPECIFIC_TYPE * /*obj*/, OBJECT_HANDLE /*hdl*/)
    {
        return NULL;                                        // a missed
    }

    template<class SPECIFIC_TYPE, class T, class H> SPECIFIC_TYPE* Remove(ContainerMapList<TypeList<H, T> > &elements, SPECIFIC_TYPE *obj, OBJECT_HANDLE hdl)
    {
        // The head element is bad
        SPECIFIC_TYPE* t = Remove(elements._elements, obj, hdl);
        return ( t != NULL ? t : Remove(elements._TailElements, obj, hdl) );
    }

}
#endif

