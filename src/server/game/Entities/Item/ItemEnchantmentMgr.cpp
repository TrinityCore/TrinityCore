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

#include "ItemEnchantmentMgr.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "ItemBonusMgr.h"
#include "ItemTemplate.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Timer.h"
#include <list>
#include <vector>

namespace
{
    struct RandomBonusListIds
    {
        std::vector<int32> BonusListIDs;
        std::vector<double> Chances;
    };

    std::unordered_map<uint32, RandomBonusListIds> _storage;
}

void LoadItemRandomBonusListTemplates()
{
    uint32 oldMSTime = getMSTime();

    _storage.clear();

    //                                               0   1            2
    QueryResult result = WorldDatabase.Query("SELECT Id, BonusListID, Chance FROM item_random_bonus_list_template");

    if (result)
    {
        uint32 count = 0;

        do
        {
            Field* fields = result->Fetch();

            uint32 id = fields[0].GetUInt32();
            uint32 bonusListId = fields[1].GetUInt32();
            float chance = fields[2].GetFloat();

            if (ItemBonusMgr::GetItemBonuses(bonusListId).empty())
            {
                TC_LOG_ERROR("sql.sql", "Bonus list {} used in `item_random_bonus_list_template` by id {} doesn't have exist in ItemBonus.db2", bonusListId, id);
                continue;
            }

            if (chance < 0.000001f || chance > 100.0f)
            {
                TC_LOG_ERROR("sql.sql", "Bonus list {} used in `item_random_bonus_list_template` by id {} has invalid chance {}", bonusListId, id, chance);
                continue;
            }

            RandomBonusListIds& ids = _storage[id];
            ids.BonusListIDs.push_back(bonusListId);
            ids.Chances.push_back(chance);

            ++count;
        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded {} Random item bonus list definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 Random item bonus list definitions. DB table `item_random_bonus_list_template` is empty.");
}

ItemRandomBonusListId GenerateItemRandomBonusListId(uint32 item_id)
{
    ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(item_id);
    if (!itemProto)
        return 0;

    // item must have one from this field values not null if it can have random enchantments
    if (!itemProto->RandomBonusListTemplateId)
        return 0;

    auto tab = _storage.find(itemProto->RandomBonusListTemplateId);
    if (tab == _storage.end())
    {
        TC_LOG_ERROR("sql.sql", "Item RandomBonusListTemplateId id #{} used in `item_template_addon` but it does not have records in `item_random_bonus_list_template` table.", itemProto->RandomBonusListTemplateId);
        return 0;
    }

    return *Trinity::Containers::SelectRandomWeightedContainerElement(tab->second.BonusListIDs, std::span(tab->second.Chances));
}

TC_GAME_API float GetRandomPropertyPoints(uint32 itemLevel, uint32 quality, uint32 inventoryType, uint32 subClass)
{
    uint32 propIndex;

    switch (inventoryType)
    {
        case INVTYPE_HEAD:
        case INVTYPE_BODY:
        case INVTYPE_CHEST:
        case INVTYPE_LEGS:
        case INVTYPE_RANGED:
        case INVTYPE_2HWEAPON:
        case INVTYPE_ROBE:
        case INVTYPE_THROWN:
            propIndex = 0;
            break;
        case INVTYPE_RANGEDRIGHT:
            if (subClass == ITEM_SUBCLASS_WEAPON_WAND)
                propIndex = 3;
            else
                propIndex = 0;
            break;
        case INVTYPE_WEAPON:
        case INVTYPE_WEAPONMAINHAND:
        case INVTYPE_WEAPONOFFHAND:
            propIndex = 3;
            break;
        case INVTYPE_SHOULDERS:
        case INVTYPE_WAIST:
        case INVTYPE_FEET:
        case INVTYPE_HANDS:
        case INVTYPE_TRINKET:
            propIndex = 1;
            break;
        case INVTYPE_NECK:
        case INVTYPE_WRISTS:
        case INVTYPE_FINGER:
        case INVTYPE_SHIELD:
        case INVTYPE_CLOAK:
        case INVTYPE_HOLDABLE:
            propIndex = 2;
            break;
        case INVTYPE_RELIC:
            propIndex = 4;
            break;
        default:
            return 0;
    }

    RandPropPointsEntry const* randPropPointsEntry = sRandPropPointsStore.LookupEntry(itemLevel);
    if (!randPropPointsEntry)
        return 0;

    switch (quality)
    {
        case ITEM_QUALITY_UNCOMMON:
            return randPropPointsEntry->Good[propIndex];
        case ITEM_QUALITY_RARE:
        case ITEM_QUALITY_HEIRLOOM:
            return randPropPointsEntry->Superior[propIndex];
        case ITEM_QUALITY_EPIC:
        case ITEM_QUALITY_LEGENDARY:
        case ITEM_QUALITY_ARTIFACT:
            return randPropPointsEntry->Epic[propIndex];
    }

    return 0;
}
