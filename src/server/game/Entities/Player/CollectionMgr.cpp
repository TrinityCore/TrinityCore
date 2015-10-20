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
    PreparedStatement* stmt = nullptr;
    for (auto const& toy : _toys)
    {
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_REP_ACCOUNT_TOYS);
        stmt->setUInt32(0, _owner->GetBattlenetAccountId());
        stmt->setUInt32(1, toy.first);
        stmt->setBool(2, toy.second);
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

void CollectionMgr::LoadAccountHeirlooms(PreparedQueryResult result)
{
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 itemId = fields[0].GetUInt32();
        uint32 flags = fields[1].GetUInt32();

        HeirloomEntry const* heirloom = sDB2Manager.GetHeirloomByItemId(itemId);
        if (!heirloom)
            continue;

        uint32 bonusId = 0;

        if (flags & HEIRLOOM_FLAG_BONUS_LEVEL_90)
            bonusId = heirloom->ItemBonusListID[0];
        if (flags & HEIRLOOM_FLAG_BONUS_LEVEL_100)
            bonusId = heirloom->ItemBonusListID[1];

        _heirlooms[itemId] = HeirloomData(flags, bonusId);
    } while (result->NextRow());
}

void CollectionMgr::SaveAccountHeirlooms(SQLTransaction& trans)
{
    PreparedStatement* stmt = nullptr;
    for (auto const& heirloom : _heirlooms)
    {
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_REP_ACCOUNT_HEIRLOOMS);
        stmt->setUInt32(0, _owner->GetBattlenetAccountId());
        stmt->setUInt32(1, heirloom.first);
        stmt->setUInt32(2, heirloom.second.flags);
        trans->Append(stmt);
    }
}

bool CollectionMgr::UpdateAccountHeirlooms(uint32 itemId, uint32 flags)
{
    return _heirlooms.insert(HeirloomContainer::value_type(itemId, HeirloomData(flags, 0))).second;
}

uint32 CollectionMgr::GetHeirloomBonus(uint32 itemId) const
{
    HeirloomContainer::const_iterator itr = _heirlooms.find(itemId);
    if (itr != _heirlooms.end())
        return itr->second.bonusId;

    return 0;
}

void CollectionMgr::LoadHeirlooms()
{
    for (auto const& item : _heirlooms)
    {
        _owner->GetPlayer()->AddDynamicValue(PLAYER_DYNAMIC_FIELD_HEIRLOOMS, item.first);
        _owner->GetPlayer()->AddDynamicValue(PLAYER_DYNAMIC_FIELD_HEIRLOOM_FLAGS, item.second.flags);
    }
}

void CollectionMgr::AddHeirloom(uint32 itemId, uint32 flags)
{
    if (UpdateAccountHeirlooms(itemId, flags))
    {
        _owner->GetPlayer()->AddDynamicValue(PLAYER_DYNAMIC_FIELD_HEIRLOOMS, itemId);
        _owner->GetPlayer()->AddDynamicValue(PLAYER_DYNAMIC_FIELD_HEIRLOOM_FLAGS, flags);
    }
}

void CollectionMgr::UpgradeHeirloom(uint32 itemId, uint32 castItem)
{
    Player* player = _owner->GetPlayer();
    if (!player)
        return;

    HeirloomEntry const* heirloom = sDB2Manager.GetHeirloomByItemId(itemId);
    if (!heirloom)
        return;

    HeirloomContainer::iterator itr = _heirlooms.find(itemId);
    if (itr == _heirlooms.end())
        return;

    uint32 flags = itr->second.flags;
    uint32 bonusId = 0;

    if (heirloom->UpgradeItemID[0] == castItem)
    {
        flags |= HEIRLOOM_FLAG_BONUS_LEVEL_90;
        bonusId = heirloom->ItemBonusListID[0];
    }
    if (heirloom->UpgradeItemID[1] == castItem)
    {
        flags |= HEIRLOOM_FLAG_BONUS_LEVEL_100;
        bonusId = heirloom->ItemBonusListID[1];
    }

    for (Item* item : player->GetItemListByEntry(itemId, true))
        item->AddBonuses(bonusId);

    // Get heirloom offset to update only one part of dynamic field
    std::vector<uint32> const& fields = player->GetDynamicValues(PLAYER_DYNAMIC_FIELD_HEIRLOOMS);
    uint8 offset = std::find(fields.begin(), fields.end(), itemId) - fields.begin();

    player->SetDynamicValue(PLAYER_DYNAMIC_FIELD_HEIRLOOM_FLAGS, offset, flags);
    itr->second.flags = flags;
    itr->second.bonusId = bonusId;
}

void CollectionMgr::CheckHeirloomUpgrades(Item* item)
{
    Player* player = _owner->GetPlayer();
    if (!player)
        return;

    // Check already owned heirloom for upgrade kits
    if (HeirloomEntry const* heirloom = sDB2Manager.GetHeirloomByItemId(item->GetEntry()))
    {
        HeirloomContainer::iterator itr = _heirlooms.find(item->GetEntry());
        if (itr == _heirlooms.end())
            return;

        // Check for heirloom pairs (normal - heroic, heroic - mythic)
        uint32 heirloomItemId = heirloom->NextDifficultyItemID;
        uint32 newItemId = 0;
        while (HeirloomEntry const* heirloomDiff = sDB2Manager.GetHeirloomByItemId(heirloomItemId))
        {
            if (player->GetItemByEntry(heirloomDiff->ItemID))
                newItemId = heirloomDiff->ItemID;

            if (HeirloomEntry const* heirloomSub = sDB2Manager.GetHeirloomByItemId(heirloomDiff->NextDifficultyItemID))
            {
                heirloomItemId = heirloomSub->ItemID;
                continue;
            }

            break;
        }

        if (newItemId)
        {
            std::vector<uint32> const& fields = player->GetDynamicValues(PLAYER_DYNAMIC_FIELD_HEIRLOOMS);
            uint8 offset = std::find(fields.begin(), fields.end(), itr->first) - fields.begin();

            player->SetDynamicValue(PLAYER_DYNAMIC_FIELD_HEIRLOOMS, offset, newItemId);
            player->SetDynamicValue(PLAYER_DYNAMIC_FIELD_HEIRLOOM_FLAGS, offset, 0);

            _heirlooms.erase(itr);
            _heirlooms[newItemId] = 0;

            return;
        }

        std::vector<uint32> const& fields = item->GetDynamicValues(ITEM_DYNAMIC_FIELD_BONUSLIST_IDS);

        for (uint32 bonusId : fields)
            if (bonusId != itr->second.bonusId)
                item->ClearDynamicValue(ITEM_DYNAMIC_FIELD_BONUSLIST_IDS);

        if (std::find(fields.begin(), fields.end(), itr->second.bonusId) == fields.end())
            item->AddBonuses(itr->second.bonusId);
    }
}

bool CollectionMgr::CanApplyHeirloomXpBonus(uint32 itemId, uint32 level)
{
    if (!sDB2Manager.GetHeirloomByItemId(itemId))
        return false;

    HeirloomContainer::iterator itr = _heirlooms.find(itemId);
    if (itr == _heirlooms.end())
        return false;

    if (itr->second.flags & HEIRLOOM_FLAG_BONUS_LEVEL_100)
        return level <= 100;
    if (itr->second.flags & HEIRLOOM_FLAG_BONUS_LEVEL_90)
        return level <= 90;

    return level <= 60;
}
