/*
    Base class interface
    Copyright (C) 1998,1999 by Andrew Zabolotny

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef __BASE_H__
#define __BASE_H__

#include "Common.h"

/**
 * This class is intended to be a base class for every other class.
 * It defines the basic interface available for any object.
 */
class Base
{
    private:
        /// Object reference count
        int RefCount;

    protected:
        /**
         * Destroy this object. Destructor is virtual, because class contains
         * virtual methods; also it is private because it is never intended
         * to be called directly; use DecRef() instead: when reference counter
         * reaches zero, the object will be destroyed.
         */
        virtual ~Base ();

    public:

        Base ();

        void IncRef ();

        void DecRef ();
        int GetRefCount ();

};
#endif                                                      // __BASE_H__

