/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef CollectionMgr_h__
#define CollectionMgr_h__

#include "WorldSession.h"

typedef std::map<uint32, bool> ToyBoxContainer;

class CollectionMgr
{
public:
    explicit CollectionMgr(WorldSession* owner) : _owner(owner) { }

    WorldSession* GetOwner() const { return _owner; }

    // Account-wide toys
    void LoadToys();
    void LoadAccountToys(PreparedQueryResult result);
    void SaveAccountToys(SQLTransaction& trans);
    void ToySetFavorite(uint32 itemId, bool favorite);

    bool AddToy(uint32 itemId, bool isFavourite /*= false*/);
    bool UpdateAccountToys(uint32 itemId, bool isFavourite /*= false*/);

    ToyBoxContainer const& GetAccountToys() const { return _toys; }

    // Account-wide heirlooms
    // Account-wide mounts

private:
    WorldSession* _owner;

    ToyBoxContainer _toys;
};

#endif // CollectionMgr_h__
