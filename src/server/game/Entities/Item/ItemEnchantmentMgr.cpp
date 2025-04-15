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
#include "Util.h"
#include <list>
#include <vector>

enum class ItemRandomEnchantmentType : uint8
{
    Property    = 0,
    Suffix      = 1
};

namespace
{
    struct RandomBonusListIds
    {
        std::vector<int32> BonusListIDs;
        std::vector<double> Chances;
    };

    struct RandomEnchantmentIds
    {
        std::vector<int32> EnchantmentIDs;
        std::vector<double> Chances;
    };

    std::unordered_map<uint32, RandomBonusListIds> _bonusListStorage;
    std::unordered_map<uint32, RandomEnchantmentIds> _randomPropertiesStorage;
    std::unordered_map<uint32, RandomEnchantmentIds> _randomSuffixStorage;
}

void LoadItemRandomBonusListTemplates()
{
    uint32 oldMSTime = getMSTime();

    _bonusListStorage.clear();

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
                TC_LOG_ERROR("sql.sql", "Bonus list {} used in `item_random_bonus_list_template` by id {} doesn't exist in ItemBonus.db2", bonusListId, id);
                continue;
            }

            if (chance < 0.000001f || chance > 100.0f)
            {
                TC_LOG_ERROR("sql.sql", "Bonus list {} used in `item_random_bonus_list_template` by id {} has invalid chance {}", bonusListId, id, chance);
                continue;
            }

            RandomBonusListIds& ids = _bonusListStorage[id];
            ids.BonusListIDs.push_back(bonusListId);
            ids.Chances.push_back(chance);

            ++count;
        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded {} Random item bonus list definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 Random item bonus list definitions. DB table `item_random_bonus_list_template` is empty.");
}

void LoadItemRandomEnchantmentsTemplates()
{
    uint32 oldMSTime = getMSTime();

    _randomPropertiesStorage.clear();
    _randomSuffixStorage.clear();

    //                                               0   1                2              3
    QueryResult result = WorldDatabase.Query("SELECT Id, EnchantmentType, EnchantmentId, Chance FROM item_random_enchantment_template");

    if (result)
    {
        uint32 count = 0;

        do
        {
            Field* fields = result->Fetch();
            uint32 Id = fields[0].GetUInt32();
            ItemRandomEnchantmentType enchantmentType = static_cast<ItemRandomEnchantmentType>(fields[1].GetUInt8());
            uint32 enchantmentId = fields[2].GetUInt32();
            float chance = fields[3].GetFloat();

            switch (enchantmentType)
            {
                case ItemRandomEnchantmentType::Property:
                    if (!sItemRandomPropertiesStore.HasRecord(enchantmentId))
                    {
                        TC_LOG_ERROR("sql.sql", "Random properties Id {} for Id {} defined in `item_random_enchantment_template` doesn't exist in ItemRandomProperties.db2", enchantmentId, Id);
                        continue;
                    }
                    break;
                case ItemRandomEnchantmentType::Suffix:
                    if (!sItemRandomSuffixStore.HasRecord(enchantmentId))
                    {
                        TC_LOG_ERROR("sql.sql", "Random suffix Id {} for Id {} defined in `item_random_enchantment_template` doesn't exist in ItemRandomSuffix.db2", enchantmentId, Id);
                        continue;
                    }
                    break;
                default:
                    TC_LOG_ERROR("sql.sql", "Invalid random enchantment type specified in `item_random_enchantment_template` table for `Id` {} `EnchantmentId` {}", Id, enchantmentId);
                    break;
            }

            if (chance < 0.000001f || chance > 100.0f)
            {
                TC_LOG_ERROR("sql.sql", "Random enchantment Id {} used in `item_random_enchantment_template` by Id {} and Type {} has an invalid chance {}", enchantmentId, Id, AsUnderlyingType(enchantmentType), chance);
                continue;
            }

            switch (enchantmentType)
            {
                case ItemRandomEnchantmentType::Property:
                {
                    RandomEnchantmentIds& randomProperties = _randomPropertiesStorage[Id];
                    randomProperties.EnchantmentIDs.push_back(enchantmentId);
                    randomProperties.Chances.push_back(chance);
                    break;
                }
                case ItemRandomEnchantmentType::Suffix:
                {
                    RandomEnchantmentIds& randomSuffix = _randomSuffixStorage[Id];
                    randomSuffix.EnchantmentIDs.push_back(enchantmentId);
                    randomSuffix.Chances.push_back(chance);
                    break;
                }
                default:
                    break;
            }

            ++count;

        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded {} Random item random enchantment definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 Random item random enchantment definitions. DB table `item_random_enchantment_template` is empty.");

}

ItemRandomBonusListId GenerateItemRandomBonusListId(uint32 item_id)
{
    ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(item_id);
    if (!itemProto)
        return 0;

    // item must have one from this field values not null if it can have random enchantments
    if (!itemProto->RandomBonusListTemplateId)
        return 0;

    auto tab = _bonusListStorage.find(itemProto->RandomBonusListTemplateId);
    if (tab == _bonusListStorage.end())
    {
        TC_LOG_ERROR("sql.sql", "Item RandomBonusListTemplateId id #{} used in `item_template_addon` but it does not have records in `item_random_bonus_list_template` table.", itemProto->RandomBonusListTemplateId);
        return 0;
    }

    return *Trinity::Containers::SelectRandomWeightedContainerElement(tab->second.BonusListIDs, std::span(tab->second.Chances));
}

TC_GAME_API ItemRandomPropertiesId GenerateItemRandomPropertiesId(uint32 item_id)
{
    ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(item_id);
    if (!itemProto)
        return 0;

    uint16 randomSelect = itemProto->GetRandomSelect();
    uint16 randomSuffix = itemProto->GetItemRandomSuffixGroupID();

    if (!randomSelect && !randomSuffix)
        return 0;

    // An item cannot have random properties and suffix at the same time
    if (randomSelect && randomSuffix)
    {
        TC_LOG_ERROR("sql.sql", "Item (Id: {} has RandomSelect and ItemRandomSuffixGroupID values which is not allowed!", itemProto->GetId());
        return 0;
    }

    if (randomSelect)
    {
        auto tab = _randomPropertiesStorage.find(randomSelect);
        if (tab == _randomPropertiesStorage.end())
        {
            TC_LOG_ERROR("sql.sql", "RandomSelect Id {} used does not have any data defined in `item_random_enchantment_template`tabel.", itemProto->GetRandomSelect());
            return 0;
        }

        return *Trinity::Containers::SelectRandomWeightedContainerElement(tab->second.EnchantmentIDs, std::span(tab->second.Chances));
    }

    if (randomSuffix)
    {
        auto tab = _randomSuffixStorage.find(randomSuffix);
        if (tab == _randomSuffixStorage.end())
        {
            TC_LOG_ERROR("sql.sql", "RandomSuffixGroup Id {} used does not have any data defined in `item_random_enchantment_template`tabel.", itemProto->GetRandomSelect());
            return 0;
        }

        return -*Trinity::Containers::SelectRandomWeightedContainerElement(tab->second.EnchantmentIDs, std::span(tab->second.Chances));
    }

    return 0;
}

TC_GAME_API uint32 GenerateEnchSuffixFactor(uint32 item_id)
{
    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item_id);
    if (!proto || !proto->GetItemRandomSuffixGroupID())
        return 0;

    return GetRandomPropertyPoints(proto->GetBaseItemLevel(), proto->GetQuality(), proto->GetInventoryType(), proto->GetSubClass());
}

TC_GAME_API uint32 GetRandomPropertyPoints(uint32 itemLevel, uint32 quality, uint32 inventoryType, uint32 subClass)
{
    uint32 propIndex = 0;

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
