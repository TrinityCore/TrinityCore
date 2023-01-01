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

#ifndef GroupInstanceRefManager_h__
#define GroupInstanceRefManager_h__

#include "GroupInstanceReference.h"
#include "RefManager.h"

class Group;
class InstanceMap;

class GroupInstanceRefManager : public RefManager<Group, InstanceMap>
{
public:
    typedef LinkedListHead::Iterator<GroupInstanceReference> iterator;
    typedef LinkedListHead::Iterator<GroupInstanceReference const> const_iterator;

    GroupInstanceReference* getFirst() { return ((GroupInstanceReference*)RefManager<Group, InstanceMap>::getFirst()); }
    GroupInstanceReference const* getFirst() const { return ((GroupInstanceReference const*)RefManager<Group, InstanceMap>::getFirst()); }

    iterator begin() { return iterator(getFirst()); }
    iterator end()   { return iterator(nullptr); }

    const_iterator begin() const { return const_iterator(getFirst()); }
    const_iterator end() const   { return const_iterator(nullptr); }
};

#endif // GroupInstanceRefManager_h__
