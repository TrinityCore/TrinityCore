/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TYPECONTAINER_FUNCTIONS_PTR_H
#define TYPECONTAINER_FUNCTIONS_PTR_H

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
    //    template<class SPECIFIC_TYPE> size_t Count(const ContainerMapList<SPECIFIC_TYPE> &elements, CountedPtr<SPECIFIC_TYPE>* /*fake*/)
    //    {
    //        return elements._element.size();
    //    };
    //
    //    template<class SPECIFIC_TYPE> size_t Count(const ContainerMapList<TypeNull> &elements, CountedPtr<SPECIFIC_TYPE>* /*fake*/)
    //    {
    //        return 0;
    //    }
    //
    //    template<class SPECIFIC_TYPE, class T> size_t Count(const ContainerMapList<T> &elements, CountedPtr<SPECIFIC_TYPE>* /*fake*/)
    //    {
    //        return 0;
    //    }
    //
    //    template<class SPECIFIC_TYPE, class T> size_t Count(const ContainerMapList<TypeList<SPECIFIC_TYPE, T> >&elements, SPECIFIC_TYPE* fake)
    //    {
    //        return Count(elements._elements,fake);
    //    }
    //
    //    template<class SPECIFIC_TYPE, class H, class T> size_t Count(const ContainerMapList<TypeList<H, T> >&elements, SPECIFIC_TYPE* fake)
    //    {
    //        return Count(elements._TailElements, fake);
    //    }

    // non-const find functions
    template<class SPECIFIC_TYPE> CountedPtr<SPECIFIC_TYPE>& Find(ContainerMapList<SPECIFIC_TYPE> &elements, OBJECT_HANDLE hdl, CountedPtr<SPECIFIC_TYPE>* /*fake*/)
    {
        typename std::map<OBJECT_HANDLE, CountedPtr<SPECIFIC_TYPE> >::iterator iter = elements._element.find(hdl);
        return (iter == elements._element.end() ? NullPtr<SPECIFIC_TYPE>((SPECIFIC_TYPE*)NULL) : iter->second);
    };

    template<class SPECIFIC_TYPE> CountedPtr<SPECIFIC_TYPE>& Find(ContainerMapList<TypeNull> &elements, OBJECT_HANDLE hdl, CountedPtr<SPECIFIC_TYPE>* /*fake*/)
    {
        return NullPtr<SPECIFIC_TYPE>((SPECIFIC_TYPE*)NULL);// terminate recursion
    }

    template<class SPECIFIC_TYPE, class T> CountedPtr<SPECIFIC_TYPE>& Find(ContainerMapList<T> &elements, OBJECT_HANDLE hdl, CountedPtr<SPECIFIC_TYPE>* /*fake*/)
    {
        return NullPtr<SPECIFIC_TYPE>((SPECIFIC_TYPE*)NULL);// this is a missed
    }

    template<class SPECIFIC_TYPE, class H, class T> CountedPtr<SPECIFIC_TYPE>& Find(ContainerMapList<TypeList<H, T> >&elements, OBJECT_HANDLE hdl, CountedPtr<SPECIFIC_TYPE>* fake)
    {
        CountedPtr<SPECIFIC_TYPE> &t = Find(elements._elements, hdl,fake);
        return (!t ? Find(elements._TailElements, hdl,fake) : t);
    }

    // const find functions
    template<class SPECIFIC_TYPE> const CountedPtr<SPECIFIC_TYPE>& Find(const ContainerMapList<SPECIFIC_TYPE> &elements, OBJECT_HANDLE hdl, CountedPtr<SPECIFIC_TYPE>* /*fake*/)
    {
        typename CountedPtr<SPECIFIC_TYPE>::iterator iter = elements._element.find(hdl);
        return (iter == elements._element.end() ? NullPtr<SPECIFIC_TYPE>((SPECIFIC_TYPE*)NULL) : iter->second);
    };

    template<class SPECIFIC_TYPE> const CountedPtr<SPECIFIC_TYPE>& Find(const ContainerMapList<TypeNull> &elements, OBJECT_HANDLE hdl, CountedPtr<SPECIFIC_TYPE>* /*fake*/)
    {
        return NullPtr<SPECIFIC_TYPE>((SPECIFIC_TYPE*)NULL);
    }

    template<class SPECIFIC_TYPE, class T> const CountedPtr<SPECIFIC_TYPE>& Find(const ContainerMapList<T> &elements, OBJECT_HANDLE hdl, CountedPtr<SPECIFIC_TYPE>* /*fake*/)
    {
        return NullPtr<SPECIFIC_TYPE>((SPECIFIC_TYPE*)NULL);
    }

    template<class SPECIFIC_TYPE, class H, class T> CountedPtr<SPECIFIC_TYPE>& Find(const ContainerMapList<TypeList<H, T> >&elements, OBJECT_HANDLE hdl, CountedPtr<SPECIFIC_TYPE>* fake)
    {
        CountedPtr<SPECIFIC_TYPE> &t = Find(elements._elements, hdl,fake);
        if(!t)
            t = Find(elements._TailElement, hdl,fake);

        return t;
    }

    // non-const insert functions
    template<class SPECIFIC_TYPE> CountedPtr<SPECIFIC_TYPE>& Insert(ContainerMapList<SPECIFIC_TYPE> &elements, CountedPtr<SPECIFIC_TYPE> &obj, OBJECT_HANDLE hdl)
    {
        elements._element[hdl] = obj;
        return obj;
    };

    template<class SPECIFIC_TYPE> CountedPtr<SPECIFIC_TYPE>& Insert(ContainerMapList<TypeNull> &elements, CountedPtr<SPECIFIC_TYPE> &obj, OBJECT_HANDLE hdl)
    {
        return NullPtr<SPECIFIC_TYPE>((SPECIFIC_TYPE*)NULL);
    }

    // this is a missed
    template<class SPECIFIC_TYPE, class T> CountedPtr<SPECIFIC_TYPE>& Insert(ContainerMapList<T> &elements, CountedPtr<SPECIFIC_TYPE> &obj, OBJECT_HANDLE hdl)
    {
        return NullPtr<SPECIFIC_TYPE>((SPECIFIC_TYPE*)NULL);// a missed
    }

    // Recursion
    template<class SPECIFIC_TYPE, class H, class T> CountedPtr<SPECIFIC_TYPE>& Insert(ContainerMapList<TypeList<H, T> >&elements, CountedPtr<SPECIFIC_TYPE> &obj, OBJECT_HANDLE hdl)
    {
        CountedPtr<SPECIFIC_TYPE> &t= Insert(elements._elements, obj, hdl);
        return (!t ? Insert(elements._TailElements, obj, hdl) : t);
    }

    // non-const remove method
    template<class SPECIFIC_TYPE> bool Remove(ContainerMapList<SPECIFIC_TYPE> &elements, CountedPtr<SPECIFIC_TYPE> &obj, OBJECT_HANDLE hdl)
    {
        typename std::map<OBJECT_HANDLE, CountedPtr<SPECIFIC_TYPE> >::iterator iter = elements._element.find(hdl);
        if( iter != elements._element.end() )
        {
            elements._element.erase(iter);
            return true;
        }

        return false;                                       // found... terminate the search
    }

    template<class SPECIFIC_TYPE> bool Remove(ContainerMapList<TypeNull> &elements, CountedPtr<SPECIFIC_TYPE> &obj, OBJECT_HANDLE hdl)
    {
        return false;
    }

    // this is a missed
    template<class SPECIFIC_TYPE, class T> bool Remove(ContainerMapList<T> &elements, CountedPtr<SPECIFIC_TYPE> &obj, OBJECT_HANDLE hdl)
    {
        return false;
    }

    template<class SPECIFIC_TYPE, class T, class H> bool Remove(ContainerMapList<TypeList<H, T> > &elements, CountedPtr<SPECIFIC_TYPE> &obj, OBJECT_HANDLE hdl)
    {
        // The head element is bad
        bool t = Remove(elements._elements, obj, hdl);
        return ( !t ? Remove(elements._TailElements, obj, hdl) : t );
    }

}
#endif

