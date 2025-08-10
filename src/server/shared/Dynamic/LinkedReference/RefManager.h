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

#ifndef _REFMANAGER_H
#define _REFMANAGER_H

#include "Dynamic/LinkedList.h"
#include "Dynamic/LinkedReference/Reference.h"

template <class ReferenceType>
class RefManager : public LinkedListHead
{
public:
    typedef LinkedListHead::Iterator<ReferenceType> iterator;
    typedef LinkedListHead::Iterator<ReferenceType const> const_iterator;
    RefManager() { }

    ReferenceType* front() { return front_impl<ReferenceType>(); }
    ReferenceType const* front() const { return front_impl<ReferenceType>(); }

    iterator begin() { return begin_impl<ReferenceType>(); }
    iterator end() { return end_impl<ReferenceType>(); }

    const_iterator begin() const { return begin_impl<ReferenceType>(); }
    const_iterator end() const { return end_impl<ReferenceType>(); }

    virtual ~RefManager()
    {
        clearReferences();
    }

    void clearReferences()
    {
        while (!empty())
            front()->invalidate();
    }
};

#endif
