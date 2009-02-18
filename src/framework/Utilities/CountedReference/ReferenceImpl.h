/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#ifndef TRINITY_REFERENCEIMPL_H
#define TRINITY_REFERENCEIMPL_H

#include "Reference.h"

template
<
typename T,
class THREADING_MODEL
>
Referencer<T, THREADING_MODEL>::Referencer(T *ref)
: i_holder(NULL)
{
    if( ref != NULL )
    {
        i_holder = new ReferenceeHolder(ref);
        ++i_holder->i_referenceCount;
    }
}

template
<
typename T,
class THREADING_MODEL
>
Referencer<T, THREADING_MODEL>::~Referencer()
{
    if( i_holder != NULL )
        deReference(i_holder);
    i_holder = NULL;
}

template
<
typename T,
class THREADING_MODEL
>
Referencer<T, THREADING_MODEL>&
Referencer<T, THREADING_MODEL>::operator=(const Referencer<T, THREADING_MODEL> &obj)
{
    if( i_holder != NULL )
        deReference(i_holder);
    if( obj.i_holder != NULL )
        addReference(obj.i_holder);
    i_holder = obj.i_holder;
    return *this;
}

template
<
typename T,
class THREADING_MODEL
>
Referencer<T, THREADING_MODEL>&
Referencer<T, THREADING_MODEL>::operator=(T *ref)
{
    if( i_holder != NULL )
        deReference(i_holder);
    i_holder = NULL;
    if( ref != NULL )
    {
        i_holder = new ReferenceeHolder(ref);
        ++i_holder->i_referenceCount;
    }

    return *this;
}

template
<
typename T,
class THREADING_MODEL
>
void
Referencer<T, THREADING_MODEL>::deReference(ReferenceHolder<T, THREADING_MODEL> *holder)
{
    assert( holder != NULL && holder->i_referenceCount > 0);
    bool delete_object = false;

    {
        // The guard is within the scope due to the guard
        // must release earlier than expected.
        Lock guard(*holder);
        Guard(&guard);

        --holder->i_referenceCount;
        if( holder->i_referenceCount == 0 )
            delete_object = true;
    }

    if( delete_object )
    {
        delete holder->i_referencee;
        delete holder;
    }
}

template
<
typename T,
class THREADING_MODEL
>
void
Referencer<T, THREADING_MODEL>::addReference(ReferenceHolder<T, THREADING_MODEL> *holder)
{
    assert( i_holder != NULL );
    Lock guard(*holder);
    Guard(&guard);

    ++holder->i_referenceCount;
}
#endif

