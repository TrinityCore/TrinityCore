/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include <stdlib.h>
#include <functional>
#include "ItemEnchantmentMgr.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "ObjectMgr.h"
#include <list>
#include <vector>
#include "Util.h"
#include "DBCStores.h"

struct EnchStoreItem
{
    uint32  ench;
    float   chance;

    EnchStoreItem()
        : ench(0), chance(0) {}

    EnchStoreItem(uint32 _ench, float _chance)
        : ench(_ench), chance(_chance) {}
};

typedef std::vector<EnchStoreItem> EnchStoreList;
typedef UNORDERED_MAP<uint32, EnchStoreList> EnchantmentStore;

static EnchantmentStore RandomItemEnch;

void LoadRandomEnchantmentsTable()
{
    uint32 oldMSTime = getMSTime();

    RandomItemEnch.clear();                                 // for reload case

    //                                                 0      1      2
    QueryResult result = WorldDatabase.Query("SELECT entry, ench, chance FROM item_enchantment_template");

    if (result)
    {
        uint32 count = 0;

        do
        {
            Field* fields = result->Fetch();

            uint32 entry = fields[0].GetUInt32();
            uint32 ench = fields[1].GetUInt32();
            float chance = fields[2].GetFloat();

            if (chance > 0.000001f && chance <= 100.0f)
                RandomItemEnch[entry].push_back(EnchStoreItem(ench, chance));

            ++count;
        } while (result->NextRow());

        sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded %u Item Enchantment definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
    else
        sLog->outError(LOG_FILTER_SQL, ">> Loaded 0 Item Enchantment definitions. DB table `item_enchantment_template` is empty.");
}

uint32 GetItemEnchantMod(int32 entry)
{
    if (!entry)
        return 0;

    if (entry == -1)
        return 0;

    EnchantmentStore::const_iterator tab = RandomItemEnch.find(entry);
    if (tab == RandomItemEnch.end())
    {
        sLog->outError(LOG_FILTER_SQL, "Item RandomProperty / RandomSuffix id #%u used in `item_template` but it does not have records in `item_enchantment_template` table.", entry);
        return 0;
    }

    double dRoll = rand_chance();
    float fCount = 0;

    for (EnchStoreList::const_iterator ench_iter = tab->second.begin(); ench_iter != tab->second.end(); ++ench_iter)
    {
        fCount += ench_iter->chance;

        if (fCount > dRoll)
            return ench_iter->ench;
    }

    //we could get here only if sum of all enchantment chances is lower than 100%
    dRoll = (irand(0, (int)floor(fCount * 100) + 1)) / 100;
    fCount = 0;

    for (EnchStoreList::const_iterator ench_iter = tab->second.begin(); ench_iter != tab->second.end(); ++ench_iter)
    {
        fCount += ench_iter->chance;

        if (fCount > dRoll)
            return ench_iter->ench;
    }

    return 0;
}

uint32 GenerateEnchSuffixFactor(uint32 item_id)
{
    ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(item_id);

    if (!itemProto)
        return 0;
    if (!itemProto->RandomSuffix)
        return 0;

    RandomPropertiesPointsEntry const* randomProperty = sRandomPropertiesPointsStore.LookupEntry(itemProto->ItemLevel);
    if (!randomProperty)
        return 0;

    uint32 suffixFactor;
    switch (itemProto->InventoryType)
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
            suffixFactor = 0;
            break;
        case INVTYPE_SHOULDERS:
        case INVTYPE_WAIST:
        case INVTYPE_FEET:
        case INVTYPE_HANDS:
        case INVTYPE_TRINKET:
            suffixFactor = 1;
            break;
        case INVTYPE_NECK:
        case INVTYPE_WRISTS:
        case INVTYPE_FINGER:
        case INVTYPE_SHIELD:
        case INVTYPE_CLOAK:
        case INVTYPE_HOLDABLE:
            suffixFactor = 2;
            break;
        case INVTYPE_WEAPON:
        case INVTYPE_WEAPONMAINHAND:
        case INVTYPE_WEAPONOFFHAND:
            suffixFactor = 3;
            break;
        case INVTYPE_RANGED:
        case INVTYPE_THROWN:
        case INVTYPE_RANGEDRIGHT:
            suffixFactor = 4;
            break;
        default:
            return 0;
    }
    // Select rare/epic modifier
    switch (itemProto->Quality)
    {
        case ITEM_QUALITY_UNCOMMON:
            return randomProperty->UncommonPropertiesPoints[suffixFactor];
        case ITEM_QUALITY_RARE:
            return randomProperty->RarePropertiesPoints[suffixFactor];
        case ITEM_QUALITY_EPIC:
            return randomProperty->EpicPropertiesPoints[suffixFactor];
        case ITEM_QUALITY_LEGENDARY:
        case ITEM_QUALITY_ARTIFACT:
            return 0;                                       // not have random properties
        default:
            break;
    }
    return 0;
}

