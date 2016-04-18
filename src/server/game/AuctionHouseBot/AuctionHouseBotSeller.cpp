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

#include "Log.h"
#include "DBCStores.h"
#include "ObjectMgr.h"
#include "AuctionHouseMgr.h"
#include "AuctionHouseBotSeller.h"

AuctionBotSeller::AuctionBotSeller()
{
    // Define faction for our main data class.
    for (int i = 0; i < MAX_AUCTION_HOUSE_TYPE; ++i)
        _houseConfig[i].Initialize(AuctionHouseType(i));
}

AuctionBotSeller::~AuctionBotSeller()
{
}

bool AuctionBotSeller::Initialize()
{
    std::vector<uint32> npcItems;
    std::vector<uint32> lootItems;
    std::vector<uint32> includeItems;
    std::vector<uint32> excludeItems;

    TC_LOG_DEBUG("ahbot", "AHBot seller filters:");

    {
        std::stringstream includeStream(sAuctionBotConfig->GetAHBotIncludes());
        std::string temp;
        while (std::getline(includeStream, temp, ','))
            includeItems.push_back(atoi(temp.c_str()));
    }

    {
        std::stringstream excludeStream(sAuctionBotConfig->GetAHBotExcludes());
        std::string temp;
        while (std::getline(excludeStream, temp, ','))
            excludeItems.push_back(atoi(temp.c_str()));
    }

    TC_LOG_DEBUG("ahbot", "Forced Inclusion %u items", (uint32)includeItems.size());
    TC_LOG_DEBUG("ahbot", "Forced Exclusion %u items", (uint32)excludeItems.size());

    TC_LOG_DEBUG("ahbot", "Loading npc vendor items for filter..");
    const CreatureTemplateContainer* creatures = sObjectMgr->GetCreatureTemplates();
    std::set<uint32> tempItems;
    for (CreatureTemplateContainer::const_iterator it = creatures->begin(); it != creatures->end(); ++it)
    {
        if (const VendorItemData* data = sObjectMgr->GetNpcVendorItemList(it->first))
        {
            for (VendorItemList::const_iterator it2 = data->m_items.begin(); it2 != data->m_items.end(); ++it2)
                tempItems.insert((*it2)->item);
        }
    }
    for (std::set<uint32>::const_iterator it = tempItems.begin(); it != tempItems.end(); ++it)
        npcItems.push_back(*it);

    TC_LOG_DEBUG("ahbot", "Npc vendor filter has %u items", (uint32)npcItems.size());

    TC_LOG_DEBUG("ahbot", "Loading loot items for filter..");
    QueryResult result = WorldDatabase.PQuery(
        "SELECT `item` FROM `creature_loot_template` WHERE `Reference` = 0 UNION "
        "SELECT `item` FROM `disenchant_loot_template` WHERE `Reference` = 0 UNION "
        "SELECT `item` FROM `fishing_loot_template` WHERE `Reference` = 0 UNION "
        "SELECT `item` FROM `gameobject_loot_template` WHERE `Reference` = 0 UNION "
        "SELECT `item` FROM `item_loot_template` WHERE `Reference` = 0 UNION "
        "SELECT `item` FROM `milling_loot_template` WHERE `Reference` = 0 UNION "
        "SELECT `item` FROM `pickpocketing_loot_template` WHERE `Reference` = 0 UNION "
        "SELECT `item` FROM `prospecting_loot_template` WHERE `Reference` = 0 UNION "
        "SELECT `item` FROM `reference_loot_template` WHERE `Reference` = 0 UNION "
        "SELECT `item` FROM `skinning_loot_template` WHERE `Reference` = 0 UNION "
        "SELECT `item` FROM `spell_loot_template` WHERE `Reference` = 0");

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            uint32 entry = fields[0].GetUInt32();
            if (!entry)
                continue;

            lootItems.push_back(entry);
        } while (result->NextRow());
    }

    TC_LOG_DEBUG("ahbot", "Loot filter has %u items", (uint32)lootItems.size());
    TC_LOG_DEBUG("ahbot", "Sorting and cleaning items for AHBot seller...");

    uint32 itemsAdded = 0;

    for (uint32 itemId = 0; itemId < sItemStore.GetNumRows(); ++itemId)
    {
        ItemTemplate const* prototype = sObjectMgr->GetItemTemplate(itemId);

        if (!prototype)
            continue;

        // skip items with too high quality (code can't properly work with its)
        if (prototype->Quality >= MAX_AUCTION_QUALITY)
            continue;

        // forced exclude filter
        bool isExcludeItem = false;
        for (size_t i = 0; i < excludeItems.size() && !isExcludeItem; ++i)
            if (itemId == excludeItems[i])
                isExcludeItem = true;

        if (isExcludeItem)
            continue;

        // forced include filter
        bool isForcedIncludeItem = false;
        for (size_t i = 0; i < includeItems.size() && !isForcedIncludeItem; ++i)
            if (itemId == includeItems[i])
                isForcedIncludeItem = true;

        if (isForcedIncludeItem)
        {
            _itemPool[prototype->Quality][prototype->Class].push_back(itemId);
            ++itemsAdded;
            continue;
        }

        // bounding filters
        switch (prototype->Bonding)
        {
            case NO_BIND:
                if (!sAuctionBotConfig->GetConfig(CONFIG_AHBOT_BIND_NO))
                    continue;
                break;
            case BIND_WHEN_PICKED_UP:
                if (!sAuctionBotConfig->GetConfig(CONFIG_AHBOT_BIND_PICKUP))
                    continue;
                break;
            case BIND_WHEN_EQUIPED:
                if (!sAuctionBotConfig->GetConfig(CONFIG_AHBOT_BIND_EQUIP))
                    continue;
                break;
            case BIND_WHEN_USE:
                if (!sAuctionBotConfig->GetConfig(CONFIG_AHBOT_BIND_USE))
                    continue;
                break;
            case BIND_QUEST_ITEM:
                if (!sAuctionBotConfig->GetConfig(CONFIG_AHBOT_BIND_QUEST))
                    continue;
                break;
            default:
                continue;
        }

        bool allowZero = false;
        switch (prototype->Class)
        {
            case ITEM_CLASS_CONSUMABLE:
                allowZero = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONSUMABLE_ALLOW_ZERO); break;
            case ITEM_CLASS_CONTAINER:
                allowZero = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONTAINER_ALLOW_ZERO); break;
            case ITEM_CLASS_WEAPON:
                allowZero = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_WEAPON_ALLOW_ZERO); break;
            case ITEM_CLASS_GEM:
                allowZero = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GEM_ALLOW_ZERO); break;
            case ITEM_CLASS_ARMOR:
                allowZero = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_ARMOR_ALLOW_ZERO); break;
            case ITEM_CLASS_REAGENT:
                allowZero = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_REAGENT_ALLOW_ZERO); break;
            case ITEM_CLASS_PROJECTILE:
                allowZero = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_PROJECTILE_ALLOW_ZERO); break;
            case ITEM_CLASS_TRADE_GOODS:
                allowZero = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_TRADEGOOD_ALLOW_ZERO); break;
            case ITEM_CLASS_RECIPE:
                allowZero = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RECIPE_ALLOW_ZERO); break;
            case ITEM_CLASS_QUIVER:
                allowZero = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_QUIVER_ALLOW_ZERO); break;
            case ITEM_CLASS_QUEST:
                allowZero = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_QUEST_ALLOW_ZERO); break;
            case ITEM_CLASS_KEY:
                allowZero = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_KEY_ALLOW_ZERO); break;
            case ITEM_CLASS_MISC:
                allowZero = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_MISC_ALLOW_ZERO); break;
            case ITEM_CLASS_GLYPH:
                allowZero = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GLYPH_ALLOW_ZERO); break;
            default:
                allowZero = false;
        }

        // Filter out items with no buy/sell price unless otherwise flagged in the config.
        if (!allowZero)
        {
            if (sAuctionBotConfig->GetConfig(CONFIG_AHBOT_BUYPRICE_SELLER))
            {
                if (prototype->SellPrice == 0)
                    continue;
            }
            else
            {
                if (prototype->BuyPrice == 0)
                    continue;
            }
        }

        // vendor filter
        if (!sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEMS_VENDOR))
        {
            bool isVendorItem = false;
            for (size_t i = 0; i < npcItems.size() && !isVendorItem; ++i)
                if (itemId == npcItems[i])
                    isVendorItem = true;

            if (isVendorItem)
                continue;
        }

        // loot filter
        if (!sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEMS_LOOT))
        {
            bool isLootItem = false;
            for (size_t i = 0; i < lootItems.size() && !isLootItem; ++i)
                if (itemId == lootItems[i])
                    isLootItem = true;

            if (isLootItem)
                continue;
        }

        // not vendor/loot filter
        if (!sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEMS_MISC))
        {
            bool isVendorItem = false;
            bool isLootItem = false;

            for (size_t i = 0; i < npcItems.size() && !isVendorItem; ++i)
                if (itemId == npcItems[i])
                    isVendorItem = true;

            for (size_t i = 0; i < lootItems.size() && !isLootItem; ++i)
                if (itemId == lootItems[i])
                    isLootItem = true;

            if (!isLootItem && !isVendorItem)
                continue;
        }

        // item class/subclass specific filters
        switch (prototype->Class)
        {
            case ITEM_CLASS_ARMOR:
            case ITEM_CLASS_WEAPON:
            {
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_MIN_ITEM_LEVEL))
                    if (prototype->ItemLevel < value)
                        continue;
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_MAX_ITEM_LEVEL))
                    if (prototype->ItemLevel > value)
                        continue;
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_MIN_REQ_LEVEL))
                    if (prototype->RequiredLevel < value)
                        continue;
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_MAX_REQ_LEVEL))
                    if (prototype->RequiredLevel > value)
                        continue;
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_MIN_SKILL_RANK))
                    if (prototype->RequiredSkillRank < value)
                        continue;
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_MAX_SKILL_RANK))
                    if (prototype->RequiredSkillRank > value)
                        continue;
                break;
            }
            case ITEM_CLASS_RECIPE:
            case ITEM_CLASS_CONSUMABLE:
            case ITEM_CLASS_PROJECTILE:
            {
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_MIN_REQ_LEVEL))
                    if (prototype->RequiredLevel < value)
                        continue;
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_MAX_REQ_LEVEL))
                    if (prototype->RequiredLevel > value)
                        continue;
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_MIN_SKILL_RANK))
                    if (prototype->RequiredSkillRank < value)
                        continue;
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_MAX_SKILL_RANK))
                    if (prototype->RequiredSkillRank > value)
                        continue;
                break;
            }
            case ITEM_CLASS_MISC:
                if (prototype->SubClass == ITEM_SUBCLASS_JUNK_MOUNT)
                {
                    if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_MISC_MOUNT_MIN_REQ_LEVEL))
                        if (prototype->RequiredLevel < value)
                            continue;
                    if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_MISC_MOUNT_MAX_REQ_LEVEL))
                        if (prototype->RequiredLevel > value)
                            continue;
                    if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_MISC_MOUNT_MIN_SKILL_RANK))
                        if (prototype->RequiredSkillRank < value)
                            continue;
                    if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_MISC_MOUNT_MAX_SKILL_RANK))
                        if (prototype->RequiredSkillRank > value)
                            continue;
                }

                if (prototype->Flags & ITEM_FLAG_UNLOCKED)
                {
                    // skip any not locked lootable items (mostly quest specific or reward cases)
                    if (!prototype->LockID)
                        continue;

                    if (!sAuctionBotConfig->GetConfig(CONFIG_AHBOT_LOCKBOX_ENABLED))
                        continue;
                }

                break;
            case ITEM_CLASS_GLYPH:
            {
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GLYPH_MIN_REQ_LEVEL))
                    if (prototype->RequiredLevel < value)
                        continue;
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GLYPH_MAX_REQ_LEVEL))
                    if (prototype->RequiredLevel > value)
                        continue;
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GLYPH_MIN_ITEM_LEVEL))
                    if (prototype->RequiredLevel < value)
                        continue;
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GLYPH_MAX_ITEM_LEVEL))
                    if (prototype->RequiredLevel > value)
                        continue;
                break;
            }
            case ITEM_CLASS_TRADE_GOODS:
            {
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_TRADEGOOD_MIN_ITEM_LEVEL))
                    if (prototype->ItemLevel < value)
                        continue;
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_TRADEGOOD_MAX_ITEM_LEVEL))
                    if (prototype->ItemLevel > value)
                        continue;
                break;
            }
            case ITEM_CLASS_CONTAINER:
            case ITEM_CLASS_QUIVER:
            {
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONTAINER_MIN_ITEM_LEVEL))
                    if (prototype->ItemLevel < value)
                        continue;
                if (uint32 value = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONTAINER_MAX_ITEM_LEVEL))
                    if (prototype->ItemLevel > value)
                        continue;
                break;
            }
        }

        _itemPool[prototype->Quality][prototype->Class].push_back(itemId);
        ++itemsAdded;
    }

    if (!itemsAdded)
    {
        TC_LOG_ERROR("ahbot", "AuctionHouseBot seller not have items, disabled.");
        sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ALLIANCE_ITEM_AMOUNT_RATIO, 0);
        sAuctionBotConfig->SetConfig(CONFIG_AHBOT_HORDE_ITEM_AMOUNT_RATIO, 0);
        sAuctionBotConfig->SetConfig(CONFIG_AHBOT_NEUTRAL_ITEM_AMOUNT_RATIO, 0);
        return false;
    }

    TC_LOG_DEBUG("ahbot", "AuctionHouseBot seller will use %u items to fill auction house (according your config choices)", itemsAdded);

    LoadConfig();

    TC_LOG_DEBUG("ahbot", "Items loaded \tGray\tWhite\tGreen\tBlue\tPurple\tOrange\tYellow");
    for (uint32 i = 0; i < MAX_ITEM_CLASS; ++i)
        TC_LOG_DEBUG("ahbot", "\t\t%u\t%u\t%u\t%u\t%u\t%u\t%u",
        (uint32)_itemPool[0][i].size(), (uint32)_itemPool[1][i].size(), (uint32)_itemPool[2][i].size(),
        (uint32)_itemPool[3][i].size(), (uint32)_itemPool[4][i].size(), (uint32)_itemPool[5][i].size(),
        (uint32)_itemPool[6][i].size());

    TC_LOG_DEBUG("ahbot", "AHBot seller configuration data loaded and initialized");
    return true;
}

void AuctionBotSeller::LoadConfig()
{
    for (int i = 0; i < MAX_AUCTION_HOUSE_TYPE; ++i)
        if (sAuctionBotConfig->GetConfigItemAmountRatio(AuctionHouseType(i)))
            LoadSellerValues(_houseConfig[i]);
}

void AuctionBotSeller::LoadItemsQuantity(SellerConfiguration& config)
{
    uint32 ratio = sAuctionBotConfig->GetConfigItemAmountRatio(config.GetHouseType());

    config.SetItemsAmountPerQuality(AUCTION_QUALITY_GRAY, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_GRAY_AMOUNT) * ratio / 100);
    config.SetItemsAmountPerQuality(AUCTION_QUALITY_WHITE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_WHITE_AMOUNT) * ratio / 100);
    config.SetItemsAmountPerQuality(AUCTION_QUALITY_GREEN, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_GREEN_AMOUNT) * ratio / 100);
    config.SetItemsAmountPerQuality(AUCTION_QUALITY_BLUE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_BLUE_AMOUNT) * ratio / 100);
    config.SetItemsAmountPerQuality(AUCTION_QUALITY_PURPLE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_PURPLE_AMOUNT) * ratio / 100);
    config.SetItemsAmountPerQuality(AUCTION_QUALITY_ORANGE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_ORANGE_AMOUNT) * ratio / 100);
    config.SetItemsAmountPerQuality(AUCTION_QUALITY_YELLOW, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_YELLOW_AMOUNT) * ratio / 100);

    // Set quantity wanted but only on possible item color
    // This avoid any no-exist class-color items selection by random items create function
    // ============================================================================================
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_CONSUMABLE, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_CONTAINER, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_WEAPON, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_WEAPON_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_GEM, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_ARMOR, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_ARMOR_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_REAGENT, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_PROJECTILE, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_TRADE_GOODS, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_TRADEGOOD_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_GENERIC, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_RECIPE, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_QUIVER, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_QUEST, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_QUEST_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_KEY, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_MISC, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_MISC_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GRAY, ITEM_CLASS_GLYPH, 0);

    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_CONSUMABLE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONSUMABLE_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_CONTAINER, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONTAINER_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_WEAPON, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_WEAPON_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_GEM, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GEM_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_ARMOR, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_ARMOR_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_REAGENT, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_REAGENT_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_PROJECTILE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_PROJECTILE_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_TRADE_GOODS, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_TRADEGOOD_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_GENERIC, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GENERIC_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_RECIPE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RECIPE_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_QUIVER, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_QUIVER_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_QUEST, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_QUEST_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_KEY, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_KEY_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_MISC, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_MISC_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_WHITE, ITEM_CLASS_GLYPH, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GLYPH_AMOUNT));

    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_CONSUMABLE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONSUMABLE_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_CONTAINER, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONTAINER_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_WEAPON, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_WEAPON_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_GEM, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GEM_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_ARMOR, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_ARMOR_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_REAGENT, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_PROJECTILE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_PROJECTILE_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_TRADE_GOODS, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_TRADEGOOD_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_GENERIC, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_RECIPE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RECIPE_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_QUIVER, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_QUIVER_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_QUEST, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_QUEST_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_KEY, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_KEY_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_MISC, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_MISC_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_GREEN, ITEM_CLASS_GLYPH, 0);

    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_CONSUMABLE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONSUMABLE_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_CONTAINER, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONTAINER_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_WEAPON, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_WEAPON_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_GEM, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GEM_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_ARMOR, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_ARMOR_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_REAGENT, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_PROJECTILE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_PROJECTILE_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_TRADE_GOODS, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_TRADEGOOD_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_GENERIC, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_RECIPE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RECIPE_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_QUIVER, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_QUIVER_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_QUEST, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_QUEST_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_KEY, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_MISC, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_MISC_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_BLUE, ITEM_CLASS_GLYPH, 0);

    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_CONSUMABLE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONSUMABLE_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_CONTAINER, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONTAINER_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_WEAPON, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_WEAPON_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_GEM, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GEM_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_ARMOR, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_ARMOR_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_REAGENT, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_PROJECTILE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_PROJECTILE_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_TRADE_GOODS, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_TRADEGOOD_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_GENERIC, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_RECIPE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RECIPE_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_QUIVER, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_QUEST, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_QUEST_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_KEY, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_MISC, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_MISC_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_PURPLE, ITEM_CLASS_GLYPH, 0);

    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_CONSUMABLE, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_CONTAINER, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_WEAPON, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_WEAPON_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_GEM, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_ARMOR, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_ARMOR_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_REAGENT, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_PROJECTILE, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_TRADE_GOODS, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_TRADEGOOD_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_GENERIC, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_RECIPE, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_QUIVER, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_QUEST, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_KEY, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_MISC, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_ORANGE, ITEM_CLASS_GLYPH, 0);

    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_CONSUMABLE, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_CONTAINER, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_WEAPON, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_WEAPON_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_GEM, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_ARMOR, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_ARMOR_AMOUNT));
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_REAGENT, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_PROJECTILE, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_TRADE_GOODS, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_GENERIC, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_RECIPE, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_QUIVER, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_QUEST, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_KEY, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_MISC, 0);
    config.SetItemsQuantityPerClass(AUCTION_QUALITY_YELLOW, ITEM_CLASS_GLYPH, 0);
    // ============================================================================================

    // Set Stack Quantities
    config.SetRandomStackRatioPerClass(ITEM_CLASS_CONSUMABLE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_CONSUMABLE));
    config.SetRandomStackRatioPerClass(ITEM_CLASS_CONTAINER, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_CONTAINER));
    config.SetRandomStackRatioPerClass(ITEM_CLASS_WEAPON, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_WEAPON));
    config.SetRandomStackRatioPerClass(ITEM_CLASS_GEM, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_GEM));
    config.SetRandomStackRatioPerClass(ITEM_CLASS_ARMOR, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_ARMOR));
    config.SetRandomStackRatioPerClass(ITEM_CLASS_REAGENT, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_REAGENT));
    config.SetRandomStackRatioPerClass(ITEM_CLASS_PROJECTILE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_PROJECTILE));
    config.SetRandomStackRatioPerClass(ITEM_CLASS_TRADE_GOODS, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_TRADEGOOD));
    config.SetRandomStackRatioPerClass(ITEM_CLASS_GENERIC, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_GENERIC));
    config.SetRandomStackRatioPerClass(ITEM_CLASS_RECIPE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_RECIPE));
    config.SetRandomStackRatioPerClass(ITEM_CLASS_QUIVER, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_QUIVER));
    config.SetRandomStackRatioPerClass(ITEM_CLASS_QUEST, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_QUEST));
    config.SetRandomStackRatioPerClass(ITEM_CLASS_KEY, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_KEY));
    config.SetRandomStackRatioPerClass(ITEM_CLASS_MISC, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_MISC));
    config.SetRandomStackRatioPerClass(ITEM_CLASS_GLYPH, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RANDOMSTACKRATIO_GLYPH));

    // Set the best value to get nearest amount of items wanted
    for (uint32 j = 0; j < MAX_AUCTION_QUALITY; ++j)
    {
        uint32 index = config.GetItemsAmountPerQuality(AuctionQuality(j)) /
            (sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONSUMABLE_AMOUNT) + sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONTAINER_AMOUNT) + sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_WEAPON_AMOUNT) +
            sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GEM_AMOUNT) + sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_ARMOR_AMOUNT) + sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_REAGENT_AMOUNT) +
            sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_PROJECTILE_AMOUNT) + sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_TRADEGOOD_AMOUNT) + sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GENERIC_AMOUNT) +
            sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RECIPE_AMOUNT) + sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_QUIVER_AMOUNT) + sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_QUEST_AMOUNT) +
            sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_KEY_AMOUNT) + sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_MISC_AMOUNT) + sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GLYPH_AMOUNT));

        for (uint32 i = 0; i < MAX_ITEM_CLASS; ++i)
            config.SetItemsAmountPerClass(AuctionQuality(j), ItemClass(i), index);
    }
}

void AuctionBotSeller::LoadSellerValues(SellerConfiguration& config)
{
    LoadItemsQuantity(config);
    uint32 PriceRatio;
    switch (config.GetHouseType())
    {
        case AUCTION_HOUSE_ALLIANCE:
            PriceRatio = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ALLIANCE_PRICE_RATIO);
            break;
        case AUCTION_HOUSE_HORDE:
            PriceRatio = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_HORDE_PRICE_RATIO);
            break;
        default:
            PriceRatio = sAuctionBotConfig->GetConfig(CONFIG_AHBOT_NEUTRAL_PRICE_RATIO);
            break;
    }

    config.SetPriceRatioPerQuality(AUCTION_QUALITY_GRAY, PriceRatio * sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_GRAY_PRICE_RATIO));
    config.SetPriceRatioPerQuality(AUCTION_QUALITY_WHITE, PriceRatio * sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_WHITE_PRICE_RATIO));
    config.SetPriceRatioPerQuality(AUCTION_QUALITY_GREEN, PriceRatio * sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_GREEN_PRICE_RATIO));
    config.SetPriceRatioPerQuality(AUCTION_QUALITY_BLUE, PriceRatio * sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_BLUE_PRICE_RATIO));
    config.SetPriceRatioPerQuality(AUCTION_QUALITY_PURPLE, PriceRatio * sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_PURPLE_PRICE_RATIO));
    config.SetPriceRatioPerQuality(AUCTION_QUALITY_ORANGE, PriceRatio * sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_ORANGE_PRICE_RATIO));
    config.SetPriceRatioPerQuality(AUCTION_QUALITY_YELLOW, PriceRatio * sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ITEM_YELLOW_PRICE_RATIO));

    config.SetPriceRatioPerClass(ITEM_CLASS_CONSUMABLE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONSUMABLE_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_CONTAINER, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_CONTAINER_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_WEAPON, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_WEAPON_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_GEM, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GEM_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_ARMOR, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_ARMOR_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_REAGENT, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_REAGENT_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_PROJECTILE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_PROJECTILE_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_TRADE_GOODS, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_TRADEGOOD_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_GENERIC, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GENERIC_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_RECIPE, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_RECIPE_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_MONEY, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_MONEY_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_QUIVER, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_QUIVER_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_QUEST, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_QUEST_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_KEY, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_KEY_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_PERMANENT, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_PERMANENT_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_MISC, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_MISC_PRICE_RATIO));
    config.SetPriceRatioPerClass(ITEM_CLASS_GLYPH, sAuctionBotConfig->GetConfig(CONFIG_AHBOT_CLASS_GLYPH_PRICE_RATIO));

    //load min and max auction times
    config.SetMinTime(sAuctionBotConfig->GetConfig(CONFIG_AHBOT_MINTIME));
    config.SetMaxTime(sAuctionBotConfig->GetConfig(CONFIG_AHBOT_MAXTIME));

    TC_LOG_DEBUG("ahbot", "AHBot: minTime = %u", config.GetMinTime());
    TC_LOG_DEBUG("ahbot", "AHBot: maxTime = %u", config.GetMaxTime());

    TC_LOG_DEBUG("ahbot", "AHBot: For AH type %u", config.GetHouseType());
    TC_LOG_DEBUG("ahbot", "AHBot: GrayItems = %u", config.GetItemsAmountPerQuality(AUCTION_QUALITY_GRAY));
    TC_LOG_DEBUG("ahbot", "AHBot: WhiteItems = %u", config.GetItemsAmountPerQuality(AUCTION_QUALITY_WHITE));
    TC_LOG_DEBUG("ahbot", "AHBot: GreenItems = %u", config.GetItemsAmountPerQuality(AUCTION_QUALITY_GREEN));
    TC_LOG_DEBUG("ahbot", "AHBot: BlueItems = %u", config.GetItemsAmountPerQuality(AUCTION_QUALITY_BLUE));
    TC_LOG_DEBUG("ahbot", "AHBot: PurpleItems = %u", config.GetItemsAmountPerQuality(AUCTION_QUALITY_PURPLE));
    TC_LOG_DEBUG("ahbot", "AHBot: OrangeItems = %u", config.GetItemsAmountPerQuality(AUCTION_QUALITY_ORANGE));
    TC_LOG_DEBUG("ahbot", "AHBot: YellowItems = %u", config.GetItemsAmountPerQuality(AUCTION_QUALITY_YELLOW));
}

// Set static of items on one AH faction.
// Fill ItemInfos object with real content of AH.
uint32 AuctionBotSeller::SetStat(SellerConfiguration& config)
{
    AllItemsArray itemsSaved(MAX_AUCTION_QUALITY, std::vector<uint32>(MAX_ITEM_CLASS));

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(config.GetHouseType());
    for (AuctionHouseObject::AuctionEntryMap::const_iterator itr = auctionHouse->GetAuctionsBegin(); itr != auctionHouse->GetAuctionsEnd(); ++itr)
    {
        AuctionEntry* auctionEntry = itr->second;
        Item* item = sAuctionMgr->GetAItem(auctionEntry->itemGUIDLow);
        if (item)
        {
            ItemTemplate const* prototype = item->GetTemplate();
            if (prototype)
                if (!auctionEntry->owner)                         // Add only ahbot items
                    ++itemsSaved[prototype->Quality][prototype->Class];
        }
    }

    uint32 count = 0;
    for (uint32 j = 0; j < MAX_AUCTION_QUALITY; ++j)
    {
        for (uint32 i = 0; i < MAX_ITEM_CLASS; ++i)
        {
            config.SetMissedItemsPerClass((AuctionQuality)j, (ItemClass)i, itemsSaved[j][i]);
            count += config.GetMissedItemsPerClass((AuctionQuality)j, (ItemClass)i);
        }
    }

    TC_LOG_DEBUG("ahbot", "AHBot: Missed Item       \tGray\tWhite\tGreen\tBlue\tPurple\tOrange\tYellow");
    for (uint32 i = 0; i < MAX_ITEM_CLASS; ++i)
    {
        TC_LOG_DEBUG("ahbot", "AHBot: \t\t%u\t%u\t%u\t%u\t%u\t%u\t%u",
            config.GetMissedItemsPerClass(AUCTION_QUALITY_GRAY, (ItemClass)i),
            config.GetMissedItemsPerClass(AUCTION_QUALITY_WHITE, (ItemClass)i),
            config.GetMissedItemsPerClass(AUCTION_QUALITY_GREEN, (ItemClass)i),
            config.GetMissedItemsPerClass(AUCTION_QUALITY_BLUE, (ItemClass)i),
            config.GetMissedItemsPerClass(AUCTION_QUALITY_PURPLE, (ItemClass)i),
            config.GetMissedItemsPerClass(AUCTION_QUALITY_ORANGE, (ItemClass)i),
            config.GetMissedItemsPerClass(AUCTION_QUALITY_YELLOW, (ItemClass)i));
    }
    config.LastMissedItem = count;

    return count;
}

// getRandomArray is used to make viable the possibility to add any of missed item in place of first one to last one.
bool AuctionBotSeller::GetItemsToSell(SellerConfiguration& config, ItemsToSellArray& itemsToSellArray, AllItemsArray const& addedItem)
{
    itemsToSellArray.clear();
    bool found = false;

    for (uint32 j = 0; j < MAX_AUCTION_QUALITY; ++j)
    {
        for (uint32 i = 0; i < MAX_ITEM_CLASS; ++i)
        {
            if (config.GetMissedItemsPerClass(AuctionQuality(j), ItemClass(i)) > addedItem[j][i] && !_itemPool[j][i].empty())
            {
                ItemToSell miss_item;
                miss_item.Color = j;
                miss_item.Itemclass = i;
                itemsToSellArray.push_back(miss_item);
                found = true;
            }
        }
    }

    return found;
}

// Set items price. All important value are passed by address.
void AuctionBotSeller::SetPricesOfItem(ItemTemplate const* itemProto, SellerConfiguration& config, uint32& buyp, uint32& bidp, uint32 stackCount)
{
    uint32 classRatio = config.GetPriceRatioPerClass(ItemClass(itemProto->Class));
    uint32 qualityRatio = config.GetPriceRatioPerQuality(AuctionQuality(itemProto->Quality));
    float priceRatio = (classRatio * qualityRatio) / 10000.0f;

    float buyPrice = itemProto->BuyPrice;
    float sellPrice = itemProto->SellPrice;

    if (buyPrice == 0)
    {
        if (sellPrice > 0)
            buyPrice = sellPrice * GetSellModifier(itemProto);
        else
        {
            float divisor = ((itemProto->Class == ITEM_CLASS_WEAPON || itemProto->Class == ITEM_CLASS_ARMOR) ? 284.0f : 80.0f);
            float tempLevel = (itemProto->ItemLevel == 0 ? 1.0f : itemProto->ItemLevel);
            float tempQuality = (itemProto->Quality == 0 ? 1.0f : itemProto->Quality);

            buyPrice = tempLevel * tempQuality * static_cast<float>(GetBuyModifier(itemProto))* tempLevel / divisor;
        }
    }

    if (sellPrice == 0)
        sellPrice = (buyPrice > 10 ? buyPrice / GetSellModifier(itemProto) : buyPrice);

    if (sAuctionBotConfig->GetConfig(CONFIG_AHBOT_BUYPRICE_SELLER))
        buyPrice = sellPrice;

    float basePriceFloat = (buyPrice * stackCount * priceRatio) / (itemProto->Class == 6 ? 200.0f : static_cast<float>(itemProto->BuyCount)) / 100.0f;
    float range = basePriceFloat * 0.04f;

    buyp = static_cast<uint32>(frand(basePriceFloat - range, basePriceFloat + range) + 0.5f);
    if (buyp == 0)
        buyp = 1;
    uint32 basePrice = buyp * .5;
    range = buyp * .4;
    bidp = urand(static_cast<uint32>(basePrice - range + 0.5f), static_cast<uint32>(basePrice + range + 0.5f)) + 1;
}

// Determines the stack size to use for the item
uint32 AuctionBotSeller::GetStackSizeForItem(ItemTemplate const* itemProto, SellerConfiguration& config) const
{
    if (config.GetRandomStackRatioPerClass(ItemClass(itemProto->Class)) > urand(0, 99))
        return urand(1, itemProto->GetMaxStackSize());
    else
        return 1;
}

// Determine the multiplier for the sell price of any weapon without a buy price.
uint32 AuctionBotSeller::GetSellModifier(ItemTemplate const* prototype)
{
    switch (prototype->Class)
    {
        case ITEM_CLASS_WEAPON:
        case ITEM_CLASS_ARMOR:
        case ITEM_CLASS_REAGENT:
        case ITEM_CLASS_PROJECTILE:
            return 5;
        default:
            return 4;
    }
}

// Return the modifier by which the item's level and quality will be modified by to derive a relatively accurate price.
uint32 AuctionBotSeller::GetBuyModifier(ItemTemplate const* prototype)
{
    switch (prototype->Class)
    {
        case ITEM_CLASS_CONSUMABLE:
        {
            switch (prototype->SubClass)
            {
            case ITEM_SUBCLASS_CONSUMABLE:
                return 100;
            case ITEM_SUBCLASS_FLASK:
                return 400;
            case ITEM_SUBCLASS_SCROLL:
                return 15;
            case ITEM_SUBCLASS_ITEM_ENHANCEMENT:
                return 250;
            case ITEM_SUBCLASS_BANDAGE:
                return 125;
            default:
                return 300;
            }
        }
        case ITEM_CLASS_WEAPON:
        {
            switch (prototype->SubClass)
            {
                case ITEM_SUBCLASS_WEAPON_AXE:
                case ITEM_SUBCLASS_WEAPON_MACE:
                case ITEM_SUBCLASS_WEAPON_SWORD:
                case ITEM_SUBCLASS_WEAPON_FIST:
                case ITEM_SUBCLASS_WEAPON_DAGGER:
                    return 1200;
                case ITEM_SUBCLASS_WEAPON_AXE2:
                case ITEM_SUBCLASS_WEAPON_MACE2:
                case ITEM_SUBCLASS_WEAPON_POLEARM:
                case ITEM_SUBCLASS_WEAPON_SWORD2:
                case ITEM_SUBCLASS_WEAPON_STAFF:
                    return 1500;
                case ITEM_SUBCLASS_WEAPON_THROWN:
                    return 350;
                default:
                    return 1000;
            }
        }
        case ITEM_CLASS_ARMOR:
        {
            switch (prototype->SubClass)
            {
                case ITEM_SUBCLASS_ARMOR_MISC:
                case ITEM_SUBCLASS_ARMOR_CLOTH:
                    return 500;
                case ITEM_SUBCLASS_ARMOR_LEATHER:
                    return 600;
                case ITEM_SUBCLASS_ARMOR_MAIL:
                    return 700;
                case ITEM_SUBCLASS_ARMOR_PLATE:
                case ITEM_SUBCLASS_ARMOR_SHIELD:
                    return 800;
                default:
                    return 400;
            }
        }
        case ITEM_CLASS_REAGENT:
        case ITEM_CLASS_PROJECTILE:
            return 50;
        case ITEM_CLASS_TRADE_GOODS:
        {
            switch (prototype->SubClass)
            {
                case ITEM_SUBCLASS_TRADE_GOODS:
                case ITEM_SUBCLASS_PARTS:
                case ITEM_SUBCLASS_MEAT:
                    return 50;
                case ITEM_SUBCLASS_EXPLOSIVES:
                    return 250;
                case ITEM_SUBCLASS_DEVICES:
                    return 500;
                case ITEM_SUBCLASS_ELEMENTAL:
                case ITEM_SUBCLASS_TRADE_GOODS_OTHER:
                case ITEM_SUBCLASS_ENCHANTING:
                    return 300;
                default:
                    return 100;
            }
        }
        case ITEM_CLASS_QUEST: return 1000;
        case ITEM_CLASS_KEY: return 3000;
        default:
            return 500;
    }
}

void AuctionBotSeller::SetItemsRatio(uint32 al, uint32 ho, uint32 ne)
{
    sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ALLIANCE_ITEM_AMOUNT_RATIO, std::max(al, 100000u));
    sAuctionBotConfig->SetConfig(CONFIG_AHBOT_HORDE_ITEM_AMOUNT_RATIO, std::max(ho, 100000u));
    sAuctionBotConfig->SetConfig(CONFIG_AHBOT_NEUTRAL_ITEM_AMOUNT_RATIO, std::max(ne, 100000u));

    for (int i = 0; i < MAX_AUCTION_HOUSE_TYPE; ++i)
        LoadItemsQuantity(_houseConfig[i]);
}

void AuctionBotSeller::SetItemsRatioForHouse(AuctionHouseType house, uint32 val)
{
    val = std::max(val, 10000u); // apply same upper limit as used for config load

    switch (house)
    {
        case AUCTION_HOUSE_ALLIANCE: sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ALLIANCE_ITEM_AMOUNT_RATIO, val); break;
        case AUCTION_HOUSE_HORDE:    sAuctionBotConfig->SetConfig(CONFIG_AHBOT_HORDE_ITEM_AMOUNT_RATIO, val); break;
        default:                     sAuctionBotConfig->SetConfig(CONFIG_AHBOT_NEUTRAL_ITEM_AMOUNT_RATIO, val); break;
    }

    LoadItemsQuantity(_houseConfig[house]);
}

void AuctionBotSeller::SetItemsAmount(uint32(&vals)[MAX_AUCTION_QUALITY])
{
    sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ITEM_GRAY_AMOUNT, vals[AUCTION_QUALITY_GRAY]);
    sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ITEM_WHITE_AMOUNT, vals[AUCTION_QUALITY_WHITE]);
    sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ITEM_GREEN_AMOUNT, vals[AUCTION_QUALITY_GREEN]);
    sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ITEM_BLUE_AMOUNT, vals[AUCTION_QUALITY_BLUE]);
    sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ITEM_PURPLE_AMOUNT, vals[AUCTION_QUALITY_PURPLE]);
    sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ITEM_ORANGE_AMOUNT, vals[AUCTION_QUALITY_ORANGE]);
    sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ITEM_YELLOW_AMOUNT, vals[AUCTION_QUALITY_YELLOW]);

    for (int i = 0; i < MAX_AUCTION_HOUSE_TYPE; ++i)
        LoadItemsQuantity(_houseConfig[i]);
}

void AuctionBotSeller::SetItemsAmountForQuality(AuctionQuality quality, uint32 val)
{
    switch (quality)
    {
        case AUCTION_QUALITY_GRAY:
            sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ITEM_GRAY_AMOUNT, val); break;
        case AUCTION_QUALITY_WHITE:
            sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ITEM_WHITE_AMOUNT, val); break;
        case AUCTION_QUALITY_GREEN:
            sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ITEM_GREEN_AMOUNT, val); break;
        case AUCTION_QUALITY_BLUE:
            sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ITEM_BLUE_AMOUNT, val); break;
        case AUCTION_QUALITY_PURPLE:
            sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ITEM_PURPLE_AMOUNT, val); break;
        case AUCTION_QUALITY_ORANGE:
            sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ITEM_ORANGE_AMOUNT, val); break;
        default:
            sAuctionBotConfig->SetConfig(CONFIG_AHBOT_ITEM_YELLOW_AMOUNT, val); break;
    }

    for (int i = 0; i < MAX_AUCTION_HOUSE_TYPE; ++i)
        LoadItemsQuantity(_houseConfig[i]);
}

// Add new auction to one of the factions.
// Faction and setting associated is defined passed argument ( config )
void AuctionBotSeller::AddNewAuctions(SellerConfiguration& config)
{
    uint32 count = 0;
    uint32 items = 0;

    // If there is large amount of items missed we can use boost value to get fast filled AH
    if (config.LastMissedItem > sAuctionBotConfig->GetItemPerCycleBoost())
    {
        items = sAuctionBotConfig->GetItemPerCycleBoost();
        TC_LOG_DEBUG("ahbot", "AHBot: Boost value used to fill AH! (if this happens often adjust both ItemsPerCycle in worldserver.conf)");
    }
    else
        items = sAuctionBotConfig->GetItemPerCycleNormal();

    uint32 houseid = 0;
    switch (config.GetHouseType())
    {
        case AUCTION_HOUSE_ALLIANCE:
            houseid = AUCTIONHOUSE_ALLIANCE;
            break;
        case AUCTION_HOUSE_HORDE:
            houseid = AUCTIONHOUSE_HORDE;
            break;
        default:
            houseid = AUCTIONHOUSE_NEUTRAL;
            break;
    }

    AuctionHouseEntry const* ahEntry = sAuctionHouseStore.LookupEntry(houseid);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(config.GetHouseType());

    ItemsToSellArray itemsToSell;
    AllItemsArray allItems(MAX_AUCTION_QUALITY, std::vector<uint32>(MAX_ITEM_CLASS));
    // Main loop
    // getRandomArray will give what categories of items should be added (return true if there is at least 1 items missed)
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    while (GetItemsToSell(config, itemsToSell, allItems) && items > 0)
    {
        --items;

        // Select random position from missed items table
        uint32 pos = urand(0, itemsToSell.size() - 1);

        // Set itemId with random item ID for selected categories and color, from _itemPool table
        uint32 itemId = _itemPool[itemsToSell[pos].Color][itemsToSell[pos].Itemclass][urand(0, _itemPool[itemsToSell[pos].Color][itemsToSell[pos].Itemclass].size() - 1)];
        ++allItems[itemsToSell[pos].Color][itemsToSell[pos].Itemclass]; // Helper table to avoid rescan from DB in this loop. (has we add item in random orders)

        if (!itemId)
        {
            TC_LOG_DEBUG("ahbot", "AHBot: Item entry 0 auction creating attempt.");
            continue;
        }

        ItemTemplate const* prototype = sObjectMgr->GetItemTemplate(itemId);
        if (!prototype)
        {
            TC_LOG_DEBUG("ahbot", "AHBot: Unknown item %u auction creating attempt.", itemId);
            continue;
        }

        uint32 stackCount = GetStackSizeForItem(prototype, config);

        Item* item = Item::CreateItem(itemId, stackCount);
        if (!item)
        {
            TC_LOG_ERROR("ahbot", "AHBot: Item::CreateItem() returned NULL for item %u (stack: %u)", itemId, stackCount);
            return;
        }

        // Update the just created item so that if it needs random properties it has them.
        // Ex:  Notched Shortsword of Stamina will only generate as a Notched Shortsword without this.
        if (int32 randomPropertyId = Item::GenerateItemRandomPropertyId(itemId))
            item->SetItemRandomProperties(randomPropertyId);

        uint32 buyoutPrice;
        uint32 bidPrice = 0;

        // Price of items are set here
        SetPricesOfItem(prototype, config, buyoutPrice, bidPrice, stackCount);

        // Deposit time
        uint32 etime = urand(1, 3);
        switch (etime)
        {
            case 1:
                etime = 43200;
                break;
            case 2:
                etime = 86400;
                break;
            case 3:
                etime = 172800;
                break;
            default:
                etime = 86400;
                break;
        }

        AuctionEntry* auctionEntry = new AuctionEntry();
        auctionEntry->Id = sObjectMgr->GenerateAuctionID();
        auctionEntry->owner = 0;
        auctionEntry->itemGUIDLow = item->GetGUID().GetCounter();
        auctionEntry->itemEntry = item->GetEntry();
        auctionEntry->startbid = bidPrice;
        auctionEntry->buyout = buyoutPrice;
        auctionEntry->houseId = houseid;
        auctionEntry->bidder = 0;
        auctionEntry->bid = 0;
        auctionEntry->deposit = sAuctionMgr->GetAuctionDeposit(ahEntry, etime, item, stackCount);
        auctionEntry->auctionHouseEntry = ahEntry;
        auctionEntry->expire_time = time(NULL) + urand(config.GetMinTime(), config.GetMaxTime()) * HOUR;

        item->SaveToDB(trans);
        sAuctionMgr->AddAItem(item);
        auctionHouse->AddAuction(auctionEntry);
        auctionEntry->SaveToDB(trans);

        auctionHouse->AddAuction(auctionEntry);

        ++count;
    }
    CharacterDatabase.CommitTransaction(trans);

    TC_LOG_DEBUG("ahbot", "AHBot: Added %u items to auction", count);
}

bool AuctionBotSeller::Update(AuctionHouseType houseType)
{
    if (sAuctionBotConfig->GetConfigItemAmountRatio(houseType) > 0)
    {
        TC_LOG_DEBUG("ahbot", "AHBot: %s selling ...", AuctionBotConfig::GetHouseTypeName(houseType));
        if (SetStat(_houseConfig[houseType]))
            AddNewAuctions(_houseConfig[houseType]);
        return true;
    }
    else
        return false;
}
