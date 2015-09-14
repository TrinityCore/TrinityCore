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

#include "CollectionMgr.h"
#include "Player.h"

void CollectionMgr::LoadToys()
{
    for (auto const& t : _toys)
        _owner->GetPlayer()->AddDynamicValue(PLAYER_DYNAMIC_FIELD_TOYS, t.first);
}

bool CollectionMgr::AddToy(uint32 itemId, bool isFavourite /*= false*/)
{
    if (UpdateAccountToys(itemId, isFavourite))
    {
        _owner->GetPlayer()->AddDynamicValue(PLAYER_DYNAMIC_FIELD_TOYS, itemId);
        return true;
    }

    return false;
}

void CollectionMgr::LoadAccountToys(PreparedQueryResult result)
{
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 itemId = fields[0].GetUInt32();
        bool isFavourite = fields[1].GetBool();

        _toys[itemId] = isFavourite;
    } while (result->NextRow());
}

void CollectionMgr::SaveAccountToys(SQLTransaction& trans)
{
    PreparedStatement* stmt = NULL;
    for (ToyBoxContainer::const_iterator itr = _toys.begin(); itr != _toys.end(); ++itr)
    {
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_REP_ACCOUNT_TOYS);
        stmt->setUInt32(0, _owner->GetBattlenetAccountId());
        stmt->setUInt32(1, itr->first);
        stmt->setBool(2, itr->second);
        trans->Append(stmt);
    }
}

bool CollectionMgr::UpdateAccountToys(uint32 itemId, bool isFavourite /*= false*/)
{
    return _toys.insert(ToyBoxContainer::value_type(itemId, isFavourite)).second;
}

void CollectionMgr::ToySetFavorite(uint32 itemId, bool favorite)
{
    ToyBoxContainer::iterator itr = _toys.find(itemId);
    if (itr == _toys.end())
        return;

    itr->second = favorite;
}
