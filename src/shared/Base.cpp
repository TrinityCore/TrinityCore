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

#include "Base.h"

Base::~Base ()
{
}

/**
 * Decrement object's reference count; as soon as the last reference
 * to the object is removed, it is destroyed.
 */

void Base::DecRef ()
{
    if (!--RefCount)
        delete this;
}

/**
 * Object initialization. The initial reference count is set to one;
 * this means if you call DecRef() immediately after creating the object,
 * it will be destroyed.
 */
Base::Base ()
{
    RefCount = 1;
}

/**
 * Increment reference count.
 * Every time when you copy a pointer to a object and store it for
 * later use you MUST call IncRef() on it; this will allow to keep
 * objects as long as they are referenced by some entity.
 */
void Base::IncRef ()
{
    ++RefCount;

}

/**
 * Query number of references to this object.
 * I would rather prefer to have the reference counter strictly private,
 * but sometimes, mostly for debugging, such a function can help.
 */
int Base::GetRefCount ()
{
    return RefCount;
}

