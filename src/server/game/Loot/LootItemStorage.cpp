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

#include "DatabaseEnv.h"
#include "Item.h"
#include "ItemTemplate.h"
#include "Log.h"
#include "LootItemStorage.h"
#include "LootMgr.h"
#include "ObjectMgr.h"
#include "Player.h"

#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/locks.hpp>

#include <unordered_map>

namespace
{
    std::unordered_map<uint64, StoredLootContainer> _lootItemStore;
}

StoredLootItem::StoredLootItem(LootItem const& lootItem) : ItemId(lootItem.itemid), Count(lootItem.count), FollowRules(lootItem.follow_loot_rules),
FFA(lootItem.freeforall), Blocked(lootItem.is_blocked), Counted(lootItem.is_counted), UnderThreshold(lootItem.is_underthreshold),
NeedsQuest(lootItem.needs_quest), RandomBonusListId(lootItem.randomBonusListId), Context(lootItem.context), BonusListIDs(lootItem.BonusListIDs)
{
}

LootItemStorage* LootItemStorage::instance()
{
    static LootItemStorage instance;
    return &instance;
}

boost::shared_mutex* LootItemStorage::GetLock()
{
    static boost::shared_mutex _lock;
    return &_lock;
}

void LootItemStorage::LoadStorageFromDB()
{
    uint32 oldMSTime = getMSTime();
    _lootItemStore.clear();
    uint32 count = 0;

    CharacterDatabaseTransaction trans = CharacterDatabaseTransaction(nullptr);
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEMCONTAINER_ITEMS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            uint64 key = fields[0].GetUInt64();
            auto itr = _lootItemStore.find(key);
            if (itr == _lootItemStore.end())
            {
                bool added;
                std::tie(itr, added) = _lootItemStore.emplace(std::piecewise_construct, std::forward_as_tuple(key), std::forward_as_tuple(key));

                ASSERT(added);
            }

            StoredLootContainer& storedContainer = itr->second;

            LootItem lootItem;
            lootItem.itemid = fields[1].GetUInt32();
            lootItem.count = fields[2].GetUInt32();
            lootItem.follow_loot_rules = fields[3].GetBool();
            lootItem.freeforall = fields[4].GetBool();
            lootItem.is_blocked = fields[5].GetBool();
            lootItem.is_counted = fields[6].GetBool();
            lootItem.is_underthreshold = fields[7].GetBool();
            lootItem.needs_quest = fields[8].GetBool();
            lootItem.randomBonusListId = fields[9].GetUInt32();
            lootItem.context = ItemContext(fields[10].GetUInt8());
            Tokenizer bonusLists(fields[11].GetString(), ' ');
            std::transform(bonusLists.begin(), bonusLists.end(), std::back_inserter(lootItem.BonusListIDs), [](char const* token)
                {
                    return int32(strtol(token, nullptr, 10));
                });

            storedContainer.AddLootItem(lootItem, trans);

            ++count;
        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded %u stored item loots in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 stored item loots");

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEMCONTAINER_MONEY);
    result = CharacterDatabase.Query(stmt);
    if (result)
    {
        count = 0;
        do
        {
            Field* fields = result->Fetch();

            uint64 key = fields[0].GetUInt64();
            auto itr = _lootItemStore.find(key);
            if (itr == _lootItemStore.end())
            {
                bool added;
                std::tie(itr, added) = _lootItemStore.emplace(std::piecewise_construct, std::forward_as_tuple(key), std::forward_as_tuple(key));

                ASSERT(added);
            }

            StoredLootContainer& storedContainer = itr->second;
            storedContainer.AddMoney(fields[1].GetUInt32(), trans);

            ++count;
        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded %u stored item money in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 stored item money");
}

bool LootItemStorage::LoadStoredLoot(Item* item, Player* player)
{
    Loot* loot = &item->loot;
    StoredLootContainer const* container = nullptr;

    // read
    {
        boost::shared_lock<boost::shared_mutex> lock(*GetLock());

        auto itr = _lootItemStore.find(loot->containerID.GetCounter());
        if (itr == _lootItemStore.end())
            return false;

        container = &itr->second;
    }

    // container is never null at this point
    loot->gold = container->GetMoney();

    if (LootTemplate const* lt = LootTemplates_Item.GetLootFor(item->GetEntry()))
    {
        for (auto const& storedItemPair : container->GetLootItems())
        {
            LootItem li;
            li.itemid = storedItemPair.first;
            li.count = storedItemPair.second.Count;
            li.follow_loot_rules = storedItemPair.second.FollowRules;
            li.freeforall = storedItemPair.second.FFA;
            li.is_blocked = storedItemPair.second.Blocked;
            li.is_counted = storedItemPair.second.Counted;
            li.is_underthreshold = storedItemPair.second.UnderThreshold;
            li.needs_quest = storedItemPair.second.NeedsQuest;
            li.randomBonusListId = storedItemPair.second.RandomBonusListId;
            li.context = storedItemPair.second.Context;
            li.BonusListIDs = storedItemPair.second.BonusListIDs;

            // Copy the extra loot conditions from the item in the loot template
            lt->CopyConditions(&li);

            // If container item is in a bag, add that player as an allowed looter
            if (item->GetBagSlot())
                li.AddAllowedLooter(player);

            // Finally add the LootItem to the container
            loot->items.push_back(li);

            // Increment unlooted count
            ++loot->unlootedCount;
        }
    }

    // Mark the item if it has loot so it won't be generated again on open
    item->m_lootGenerated = true;
    return true;
}

void LootItemStorage::RemoveStoredMoneyForContainer(uint64 containerId)
{
    // write
    boost::unique_lock<boost::shared_mutex> lock(*GetLock());

    auto itr = _lootItemStore.find(containerId);
    if (itr == _lootItemStore.end())
        return;

    itr->second.RemoveMoney();
}

void LootItemStorage::RemoveStoredLootForContainer(uint64 containerId)
{
    // write
    {
        boost::unique_lock<boost::shared_mutex> lock(*GetLock());
        _lootItemStore.erase(containerId);
    }

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_ITEMS);
    stmt->setUInt64(0, containerId);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_MONEY);
    stmt->setUInt64(0, containerId);
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void LootItemStorage::RemoveStoredLootItemForContainer(uint64 containerId, uint32 itemId, uint32 count)
{
    // write
    boost::unique_lock<boost::shared_mutex> lock(*GetLock());

    auto itr = _lootItemStore.find(containerId);
    if (itr == _lootItemStore.end())
        return;

    itr->second.RemoveItem(itemId, count);
}

void LootItemStorage::AddNewStoredLoot(Loot* loot, Player* player)
{
    // Saves the money and item loot associated with an openable item to the DB
    if (loot->isLooted()) // no money and no loot
        return;

    // read
    {
        boost::shared_lock<boost::shared_mutex> lock(*GetLock());

        auto itr = _lootItemStore.find(loot->containerID.GetCounter());
        if (itr != _lootItemStore.end())
        {
            TC_LOG_ERROR("misc", "Trying to store item loot by player: %s for container id: %lu that is already in storage!", player->GetGUID().ToString().c_str(), loot->containerID.GetCounter());
            return;
        }
    }

    StoredLootContainer container(loot->containerID.GetCounter());

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    if (loot->gold)
        container.AddMoney(loot->gold, trans);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_ITEMS);
    stmt->setUInt64(0, loot->containerID.GetCounter());
    trans->Append(stmt);

    for (LootItem const& li : loot->items)
    {
        // Conditions are not checked when loot is generated, it is checked when loot is sent to a player.
        // For items that are lootable, loot is saved to the DB immediately, that means that loot can be
        // saved to the DB that the player never should have gotten. This check prevents that, so that only
        // items that the player should get in loot are in the DB.
        // IE: Horde items are not saved to the DB for Ally players.
        if (!li.AllowedForPlayer(player))
            continue;

        // Don't save currency tokens
        ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(li.itemid);
        if (!itemTemplate || itemTemplate->IsCurrencyToken())
            continue;

        container.AddLootItem(li, trans);
    }

    CharacterDatabase.CommitTransaction(trans);

    // write
    {
        boost::unique_lock<boost::shared_mutex> lock(*GetLock());
        _lootItemStore.emplace(loot->containerID.GetCounter(), std::move(container));
    }
}

void StoredLootContainer::AddLootItem(LootItem const& lootItem, CharacterDatabaseTransaction& trans)
{
    _lootItems.emplace(std::piecewise_construct, std::forward_as_tuple(lootItem.itemid), std::forward_as_tuple(lootItem));
    if (!trans)
        return;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEMCONTAINER_ITEMS);

    // container_id, item_id, item_count, follow_rules, ffa, blocked, counted, under_threshold, needs_quest, rnd_prop, rnd_suffix
    stmt->setUInt64(0, _containerId);
    stmt->setUInt32(1, lootItem.itemid);
    stmt->setUInt32(2, lootItem.count);
    stmt->setBool(3, lootItem.follow_loot_rules);
    stmt->setBool(4, lootItem.freeforall);
    stmt->setBool(5, lootItem.is_blocked);
    stmt->setBool(6, lootItem.is_counted);
    stmt->setBool(7, lootItem.is_underthreshold);
    stmt->setBool(8, lootItem.needs_quest);
    stmt->setInt32(9, lootItem.randomBonusListId);
    stmt->setUInt8(10, AsUnderlyingType(lootItem.context));
    std::ostringstream bonusListIDs;
    for (int32 bonusListID : lootItem.BonusListIDs)
        bonusListIDs << bonusListID << ' ';
    stmt->setString(11, bonusListIDs.str());
    trans->Append(stmt);
}

void StoredLootContainer::AddMoney(uint32 money, CharacterDatabaseTransaction& trans)
{
    _money = money;
    if (!trans)
        return;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_MONEY);
    stmt->setUInt64(0, _containerId);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEMCONTAINER_MONEY);
    stmt->setUInt64(0, _containerId);
    stmt->setUInt32(1, _money);
    trans->Append(stmt);
}

void StoredLootContainer::RemoveMoney()
{
    _money = 0;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_MONEY);
    stmt->setUInt64(0, _containerId);
    CharacterDatabase.Execute(stmt);
}

void StoredLootContainer::RemoveItem(uint32 itemId, uint32 count)
{
    auto bounds = _lootItems.equal_range(itemId);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
    {
        if (itr->second.Count == count)
        {
            _lootItems.erase(itr);
            break;
        }
    }

    // Deletes a single item associated with an openable item from the DB
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_ITEM);
    stmt->setUInt64(0, _containerId);
    stmt->setUInt32(1, itemId);
    stmt->setUInt32(2, count);
    CharacterDatabase.Execute(stmt);
}
