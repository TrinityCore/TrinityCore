/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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

#ifndef TRINITY_CREATIONPOLICY_H
#define TRINITY_CREATIONPOLICY_H

#include <stdlib.h>
#include "Platform/Define.h"

namespace Trinity
{
    /**
     * OperatorNew policy creates an object on the heap using new.
     */
    template <class T>
        class TRINITY_DLL_DECL OperatorNew
    {
        public:
            static T* Create(void) { return (new T); }
            static void Destroy(T *obj) { delete obj; }
    };

    /**
     * LocalStaticCreation policy creates an object on the stack
     * the first time call Create.
     */
    template <class T>
        class TRINITY_DLL_DECL LocalStaticCreation
    {
        union MaxAlign
        {
            char t_[sizeof(T)];
            short int shortInt_;
            int int_;
            long int longInt_;
            float float_;
            double double_;
            long double longDouble_;
            struct Test;
            int Test::* pMember_;
            int (Test::*pMemberFn_)(int);
        };
        public:
            static T* Create(void)
            {
                static MaxAlign si_localStatic;
                return new(&si_localStatic) T;
            }

            static void Destroy(T *obj) { obj->~T(); }
    };

    /**
     * CreateUsingMalloc by pass the memory manger.
     */
    template<class T>
        class TRINITY_DLL_DECL CreateUsingMalloc
    {
        public:
            static T* Create()
            {
                void* p = ::malloc(sizeof(T));
                if (!p) return 0;
                return new(p) T;
            }

            static void Destroy(T* p)
            {
                p->~T();
                ::free(p);
            }
    };

    /**
     * CreateOnCallBack creates the object base on the call back.
     */
    template<class T, class CALL_BACK>
        class TRINITY_DLL_DECL CreateOnCallBack
    {
        public:
            static T* Create()
            {
                return CALL_BACK::createCallBack();
            }

            static void Destroy(T *p)
            {
                CALL_BACK::destroyCallBack(p);
            }
    };
}
#endif

