/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef _MAPREFMANAGER
#define _MAPREFMANAGER

#include "RefManager.h"

class MapReference;

class MapRefManager : public RefManager<Map, Player>
{
    public:
        typedef LinkedListHead::Iterator<MapReference> iterator;
        typedef LinkedListHead::Iterator<MapReference const> const_iterator;

        MapReference* getFirst()             { return (MapReference*)RefManager<Map, Player>::getFirst(); }
        MapReference const* getFirst() const { return (MapReference const*)RefManager<Map, Player>::getFirst(); }

        iterator begin() { return iterator(getFirst()); }
        iterator end()   { return iterator(nullptr); }

        const_iterator begin() const { return const_iterator(getFirst()); }
        const_iterator end() const   { return const_iterator(nullptr); }
};
#endif
