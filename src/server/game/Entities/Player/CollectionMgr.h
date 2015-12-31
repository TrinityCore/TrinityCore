/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

enum HeirloomPlayerFlags
{
    HEIRLOOM_FLAG_NONE                    = 0x00,
    HEIRLOOM_FLAG_BONUS_LEVEL_90          = 0x01,
    HEIRLOOM_FLAG_BONUS_LEVEL_100         = 0x02
};

enum HeirloomItemFlags
{
    HEIRLOOM_ITEM_FLAG_NONE               = 0x00,
    HEIRLOOM_ITEM_FLAG_SHOW_ONLY_IF_KNOWN = 0x01,
    HEIRLOOM_ITEM_FLAG_PVP                = 0x02
};

struct HeirloomData
{
    HeirloomData(uint32 _flags = 0, uint32 _bonusId = 0) : flags(_flags), bonusId(_bonusId) { }

    uint32 flags;
    uint32 bonusId;
};

typedef std::map<uint32, bool> ToyBoxContainer;
typedef std::map<uint32, HeirloomData> HeirloomContainer;

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
    void LoadHeirlooms();
    void LoadAccountHeirlooms(PreparedQueryResult result);
    void SaveAccountHeirlooms(SQLTransaction& trans);
    void AddHeirloom(uint32 itemId, uint32 flags);
    void UpgradeHeirloom(uint32 itemId, uint32 castItem);
    void CheckHeirloomUpgrades(Item* item);

    bool UpdateAccountHeirlooms(uint32 itemId, uint32 flags);
    bool CanApplyHeirloomXpBonus(uint32 itemId, uint32 level);
    uint32 GetHeirloomBonus(uint32 itemId) const;
    HeirloomContainer const& GetAccountHeirlooms() const { return _heirlooms; }

    // Account-wide mounts

private:
    WorldSession* _owner;

    ToyBoxContainer _toys;
    HeirloomContainer _heirlooms;
};

#endif // CollectionMgr_h__
