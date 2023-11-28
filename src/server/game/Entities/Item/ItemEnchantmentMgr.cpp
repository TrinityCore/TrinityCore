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
#include "ItemTemplate.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Timer.h"
#include <list>
#include <vector>

/*static*/ ItemEnchantmentMgr* ItemEnchantmentMgr::instance()
{
    static ItemEnchantmentMgr instance;
    return &instance;
}

void ItemEnchantmentMgr::LoadRandomEnchantmentsTable()
{
    uint32 oldMSTime = getMSTime();

    _storage.clear();

    //                                               0   1              2
    QueryResult result = WorldDatabase.Query("SELECT Id, EnchantmentId, Chance FROM item_random_enchantment_template");

    if (result)
    {
        uint32 count = 0;

        do
        {
            Field* fields = result->Fetch();

            uint32 id = fields[0].GetUInt32();
            uint32 enchantmentId = fields[1].GetUInt32();
            float chance = fields[2].GetFloat();

            if (!sItemRandomPropertiesStore.LookupEntry(enchantmentId) && !sItemRandomSuffixStore.LookupEntry(enchantmentId))
            {
                TC_LOG_ERROR("sql.sql", "ItemRandomProperties/ItemRandomSuffix Id {} used in `item_random_enchantment_template` by id {} doesn't have exist in its corresponding db2 file.", enchantmentId, id);
                continue;
            }

            if (chance < 0.000001f || chance > 100.0f)
            {
                TC_LOG_ERROR("sql.sql", "Enchantment Id {} used in `item_random_enchantment_template` by id {} has invalid chance {}", enchantmentId, id, chance);
                continue;
            }

            RandomEnchantmentData& ids = _storage[id];
            ids.EnchantmentIDs.push_back(enchantmentId);
            ids.Chances.push_back(chance);

            ++count;
        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded {} Random item enchantment definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 Random item bonus list definitions. DB table `item_random_enchantment_template` is empty.");
}

static int32 GetRandomPropertyPoints(uint32 itemLevel, uint32 quality, uint32 inventoryType)
{
    uint32 propIndex = 0;

    switch (inventoryType)
    {
        // Items of that type don`t have points
        case INVTYPE_NON_EQUIP:
        case INVTYPE_BAG:
        case INVTYPE_TABARD:
        case INVTYPE_AMMO:
        case INVTYPE_QUIVER:
        case INVTYPE_RELIC:
            return 0;
            // Select point coefficient
        case INVTYPE_HEAD:
        case INVTYPE_BODY:
        case INVTYPE_CHEST:
        case INVTYPE_LEGS:
        case INVTYPE_2HWEAPON:
        case INVTYPE_ROBE:
            propIndex = 0;
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
        case INVTYPE_WEAPON:
        case INVTYPE_WEAPONMAINHAND:
        case INVTYPE_WEAPONOFFHAND:
            propIndex = 3;
            break;
        case INVTYPE_RANGED:
        case INVTYPE_THROWN:
        case INVTYPE_RANGEDRIGHT:
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

ItemRandomProperties ItemEnchantmentMgr::GenerateRandomProperties(uint32 itemId)
{
    ItemRandomProperties properties;
    ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(itemId);
    if (!itemProto)
        return properties;

    if (!itemProto->GetRandomSelect() && !itemProto->GetRandomSuffixGroupID())
        return properties;

    if (uint16 randomSelect = itemProto->GetRandomSelect())
    {
        auto tab = _storage.find(randomSelect);
        if (tab == _storage.end())
        {
            TC_LOG_ERROR("sql.sql", "Item RandomSelect Id {} used but it does not have records in `item_random_enchantment_template` table.", randomSelect);
            return properties;
        }

        uint32 randomPropertiesId = *Trinity::Containers::SelectRandomWeightedContainerElement(tab->second.EnchantmentIDs, std::span(tab->second.Chances));
        ItemRandomPropertiesEntry const* randomPropertiesEntry = sItemRandomPropertiesStore.LookupEntry(randomPropertiesId);
        if (!randomPropertiesEntry)
        {
            TC_LOG_ERROR("sql.sql", "Enchantment Id {} used but it doesn't have records in 'ItemRandomProperties.db2'", randomPropertiesId);
            return properties;
        }

        properties.RandomPropertiesID = static_cast<int32>(randomPropertiesEntry->ID);
    }
    else if (uint16 randomSuffix = itemProto->GetRandomSuffixGroupID())
    {
        auto tab = _storage.find(randomSuffix);
        if (tab == _storage.end())
        {
            TC_LOG_ERROR("sql.sql", "Item RandomSuffixGroupID Id {} used but it does not have records in `item_random_enchantment_template` table.", randomSuffix);
            return properties;
        }

        uint32 randomSuffixId = *Trinity::Containers::SelectRandomWeightedContainerElement(tab->second.EnchantmentIDs, std::span(tab->second.Chances));
        ItemRandomSuffixEntry const* randomSuffixEntry = sItemRandomSuffixStore.LookupEntry(randomSuffixId);
        if (!randomSuffixEntry)
        {
            TC_LOG_ERROR("sql.sql", "Enchantment id Id {} used but it doesn't have records in 'ItemRandomSuffixEntry.db2'", randomSuffixId);
            return properties;
        }

        properties.RandomPropertiesID = -static_cast<int32>(randomSuffixEntry->ID);
        properties.RandomPropertiesSeed = GetRandomPropertyPoints(itemProto->GetItemLevel(), itemProto->GetQuality(), itemProto->GetInventoryType());
    }

    return properties;
}
