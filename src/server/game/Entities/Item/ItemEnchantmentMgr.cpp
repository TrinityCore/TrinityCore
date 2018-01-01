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

#include "ItemEnchantmentMgr.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "ItemTemplate.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Random.h"
#include "Timer.h"
#include "Util.h"

#include <list>
#include <vector>
#include <stdlib.h>

struct EnchStoreItem
{
    ItemRandomEnchantmentType type;
    uint32  ench;
    float   chance;

    EnchStoreItem()
        : type(ItemRandomEnchantmentType::Property), ench(0), chance(0) { }

    EnchStoreItem(ItemRandomEnchantmentType _type, uint32 _ench, float _chance)
        : type(_type), ench(_ench), chance(_chance) { }
};

typedef std::vector<EnchStoreItem> EnchStoreList;

class EnchantmentStore
{
    std::unordered_map<uint32, EnchStoreList> _data[2];

public:
    std::unordered_map<uint32, EnchStoreList>& operator[](ItemRandomEnchantmentType type)
    {
        ASSERT(type != ItemRandomEnchantmentType::BonusList, "Random bonus lists do not have their own storage, use Suffix for them");
        return _data[uint8(type)];
    }

} static RandomItemEnch;

void LoadRandomEnchantmentsTable()
{
    uint32 oldMSTime = getMSTime();

    RandomItemEnch[ItemRandomEnchantmentType::Property].clear();
    RandomItemEnch[ItemRandomEnchantmentType::Suffix].clear();

    //                                                 0      1     2      3
    QueryResult result = WorldDatabase.Query("SELECT entry, type, ench, chance FROM item_enchantment_template");

    if (result)
    {
        uint32 count = 0;

        do
        {
            Field* fields = result->Fetch();

            uint32 entry = fields[0].GetUInt32();
            ItemRandomEnchantmentType type = ItemRandomEnchantmentType(fields[1].GetUInt8());
            uint32 ench = fields[2].GetUInt32();
            float chance = fields[3].GetFloat();

            switch (type)
            {
                case ItemRandomEnchantmentType::Property:
                    if (!sItemRandomPropertiesStore.LookupEntry(ench))
                    {
                        TC_LOG_ERROR("sql.sql", "Property %u used in `item_enchantment_template` by entry %u doesn't have exist in ItemRandomProperties.db2", ench, entry);
                        continue;
                    }
                    break;
                case ItemRandomEnchantmentType::Suffix:
                    if (!sItemRandomSuffixStore.LookupEntry(ench))
                    {
                        TC_LOG_ERROR("sql.sql", "Suffix %u used in `item_enchantment_template` by entry %u doesn't have exist in ItemRandomSuffix.db2", ench, entry);
                        continue;
                    }
                    break;
                case ItemRandomEnchantmentType::BonusList:
                    if (!sDB2Manager.GetItemBonusList(ench))
                    {
                        TC_LOG_ERROR("sql.sql", "Bonus list %u used in `item_enchantment_template` by entry %u doesn't have exist in ItemBonus.db2", ench, entry);
                        continue;
                    }
                    break;
                default:
                    TC_LOG_ERROR("sql.sql", "Invalid random enchantment type specified in `item_enchantment_template` table for `entry` %u `ench` %u", entry, ench);
                    break;
            }

            if (chance < 0.000001f || chance > 100.0f)
            {
                TC_LOG_ERROR("sql.sql", "Random item enchantment for entry %u type %u ench %u has invalid chance %f", entry, uint32(type), ench, chance);
                continue;
            }

            switch (type)
            {
                case ItemRandomEnchantmentType::Property:
                    RandomItemEnch[ItemRandomEnchantmentType::Property][entry].emplace_back(type, ench, chance);
                    break;
                case ItemRandomEnchantmentType::Suffix:
                case ItemRandomEnchantmentType::BonusList: // random bonus lists use RandomSuffix field in Item-sparse.db2
                    RandomItemEnch[ItemRandomEnchantmentType::Suffix][entry].emplace_back(type, ench, chance);
                    break;
                default:
                    break;
            }

            ++count;
        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded %u Item Enchantment definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
    else
        TC_LOG_ERROR("server.loading", ">> Loaded 0 Item Enchantment definitions. DB table `item_enchantment_template` is empty.");
}

ItemRandomEnchantmentId GetItemEnchantMod(int32 entry, ItemRandomEnchantmentType type)
{
    if (!entry)
        return{};

    if (entry == -1)
        return{};

    auto tab = RandomItemEnch[type].find(entry);
    if (tab == RandomItemEnch[type].end())
    {
        TC_LOG_ERROR("sql.sql", "Item RandomProperty / RandomSuffix id #%u used in `item_template` but it does not have records in `item_enchantment_template` table.", entry);
        return{};
    }

    auto selectedItr = Trinity::Containers::SelectRandomWeightedContainerElement(tab->second, [](EnchStoreItem const& enchant)
    {
        return enchant.chance;
    });

    return{ selectedItr->type, selectedItr->ench };
}

ItemRandomEnchantmentId GenerateItemRandomPropertyId(uint32 item_id)
{
    ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(item_id);
    if (!itemProto)
        return{};

    // item must have one from this field values not null if it can have random enchantments
    if (!itemProto->GetRandomProperty() && !itemProto->GetRandomSuffix())
        return{};

    // item can have not null only one from field values
    if (itemProto->GetRandomProperty() && itemProto->GetRandomSuffix())
    {
        TC_LOG_ERROR("sql.sql", "Item template %u have RandomProperty == %u and RandomSuffix == %u, but must have one from field =0", itemProto->GetId(), itemProto->GetRandomProperty(), itemProto->GetRandomSuffix());
        return{};
    }

    // RandomProperty case
    if (itemProto->GetRandomProperty())
        return GetItemEnchantMod(itemProto->GetRandomProperty(), ItemRandomEnchantmentType::Property);
    // RandomSuffix case
    else
        return GetItemEnchantMod(itemProto->GetRandomSuffix(), ItemRandomEnchantmentType::Suffix);
}

uint32 GenerateEnchSuffixFactor(uint32 item_id)
{
    ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(item_id);

    if (!itemProto)
        return 0;
    if (!itemProto->GetRandomSuffix())
        return 0;

    return GetRandomPropertyPoints(itemProto->GetBaseItemLevel(), itemProto->GetQuality(), itemProto->GetInventoryType(), itemProto->GetSubClass());
}

TC_GAME_API uint32 GetRandomPropertyPoints(uint32 itemLevel, uint32 quality, uint32 inventoryType, uint32 subClass)
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
        default:
            return 0;
    }

    RandPropPointsEntry const* randPropPointsEntry = sRandPropPointsStore.LookupEntry(itemLevel);
    if (!randPropPointsEntry)
        return 0;

    switch (quality)
    {
        case ITEM_QUALITY_UNCOMMON:
            return randPropPointsEntry->UncommonPropertiesPoints[propIndex];
        case ITEM_QUALITY_RARE:
        case ITEM_QUALITY_HEIRLOOM:
            return randPropPointsEntry->RarePropertiesPoints[propIndex];
        case ITEM_QUALITY_EPIC:
        case ITEM_QUALITY_LEGENDARY:
        case ITEM_QUALITY_ARTIFACT:
            return randPropPointsEntry->EpicPropertiesPoints[propIndex];
    }

    return 0;
}
