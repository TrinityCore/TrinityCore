/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "LootItemStorage.h"
#include "ItemTemplate.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"

#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/locks.hpp>

LootItemStorage::LootItemStorage()
{
}

LootItemStorage::~LootItemStorage()
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

    SQLTransaction trans = SQLTransaction(nullptr);
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEMCONTAINER_ITEMS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            StoredLootContainer& storedContainer = _lootItemStore[fields[0].GetUInt32()];
            storedContainer.SetContainer(fields[0].GetUInt32());
            storedContainer.AddLootItem(fields[1].GetUInt32(), fields[2].GetUInt32(), fields[3].GetBool(), fields[4].GetBool(), fields[5].GetBool(), fields[6].GetBool(),
                fields[7].GetBool(), fields[8].GetBool(), fields[9].GetInt32(), fields[10].GetUInt32(), trans);

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

            StoredLootContainer& storedContainer = _lootItemStore[fields[0].GetUInt32()];
            storedContainer.SetContainer(fields[0].GetUInt32());
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
    // read
    boost::shared_lock<boost::shared_mutex> lock(*GetLock());

    Loot* loot = &item->loot;
    auto itr = _lootItemStore.find(loot->containerID);
    if (itr == _lootItemStore.end())
        return false;

    StoredLootContainer& container = itr->second;
    loot->gold = container.GetMoney();

    LootTemplate const* lt = LootTemplates_Item.GetLootFor(item->GetEntry());
    if (lt)
    {
        for (auto const& storedItem : container.GetLootItems())
        {
            LootItem li = LootItem();
            li.itemid = storedItem.itemId;
            li.count = storedItem.count;
            li.follow_loot_rules = storedItem.followRules;
            li.freeforall = storedItem.ffa;
            li.is_blocked = storedItem.blocked;
            li.is_counted = storedItem.counted;
            li.is_underthreshold = storedItem.underTreshold;
            li.needs_quest = storedItem.needsQuest;
            li.randomPropertyId = storedItem.randomPropertyId;
            li.randomSuffix = storedItem.randomSuffix;

            // Copy the extra loot conditions from the item in the loot template
            lt->CopyConditions(&li);

            // If container item is in a bag, add that player as an allowed looter
            if (item->GetBagSlot())
                li.AddAllowedLooter(player);

            // Finally add the LootItem to the container
            loot->items.push_back(li);

            // Increment unlooted count
            loot->unlootedCount++;
        }
    }

    // Mark the item if it has loot so it won't be generated again on open
    item->m_lootGenerated = true;
    return true;
}

void LootItemStorage::RemoveStoredMoneyForContainer(uint32 containerId)
{
    // write
    boost::unique_lock<boost::shared_mutex> lock(*GetLock());

    auto itr = _lootItemStore.find(containerId);
    if (itr == _lootItemStore.end())
        return;

    itr->second.RemoveMoney();
}

void LootItemStorage::RemoveStoredLootForContainer(uint32 containerId)
{
    // write
    boost::unique_lock<boost::shared_mutex> lock(*GetLock());

    _lootItemStore.erase(containerId);

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_ITEMS);
    stmt->setUInt32(0, containerId);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_MONEY);
    stmt->setUInt32(0, containerId);
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void LootItemStorage::RemoveStoredLootItemForContainer(uint32 containerId, uint32 itemId, uint32 count)
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
    // write
    boost::unique_lock<boost::shared_mutex> lock(*GetLock());

    // Saves the money and item loot associated with an openable item to the DB
    if (loot->isLooted()) // no money and no loot
        return;

    auto itr = _lootItemStore.find(loot->containerID);
    if (itr != _lootItemStore.end())
    {
        TC_LOG_ERROR("misc", "Trying to store item loot by player: %s for container id: %u that is already in storage!", player->GetGUID().ToString().c_str(), loot->containerID);
        return;
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    StoredLootContainer& container = _lootItemStore[loot->containerID];
    container.SetContainer(loot->containerID);
    if (loot->gold)
        container.AddMoney(loot->gold, trans);

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_ITEMS);
    stmt->setUInt32(0, loot->containerID);
    trans->Append(stmt);

    for (auto const& _li : loot->items)
    {
        // Conditions are not checked when loot is generated, it is checked when loot is sent to a player.
        // For items that are lootable, loot is saved to the DB immediately, that means that loot can be
        // saved to the DB that the player never should have gotten. This check prevents that, so that only
        // items that the player should get in loot are in the DB.
        // IE: Horde items are not saved to the DB for Ally players.
        if (!_li.AllowedForPlayer(player))
            continue;

        // Don't save currency tokens
        const ItemTemplate* itemTemplate = sObjectMgr->GetItemTemplate(_li.itemid);
        if (!itemTemplate || itemTemplate->IsCurrencyToken())
            continue;

        container.AddLootItem(_li.itemid, _li.count, _li.follow_loot_rules, _li.freeforall, _li.is_blocked, _li.is_counted, _li.is_underthreshold, _li.needs_quest, _li.randomPropertyId, _li.randomSuffix, trans);
    }

    CharacterDatabase.CommitTransaction(trans);
}

void StoredLootContainer::SetContainer(uint32 containerId)
{
    _containerId = containerId;
}

void StoredLootContainer::AddLootItem(uint32 itemId, uint32 count, bool followRules, bool ffa, bool blocked, bool counted, bool underTreshold, bool needsQuest, int32 randomPropertyId, uint32 randomSuffix, SQLTransaction trans)
{
    _lootItems.emplace_back(itemId, count, followRules, ffa, blocked, counted, underTreshold, needsQuest, randomPropertyId, randomSuffix);
    if (!trans)
        return;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEMCONTAINER_ITEMS);

    // container_id, item_id, item_count, follow_rules, ffa, blocked, counted, under_threshold, needs_quest, rnd_prop, rnd_suffix
    stmt->setUInt32(0, _containerId);
    stmt->setUInt32(1, itemId);
    stmt->setUInt32(2, count);
    stmt->setBool(3, followRules);
    stmt->setBool(4, ffa);
    stmt->setBool(5, blocked);
    stmt->setBool(6, counted);
    stmt->setBool(7, underTreshold);
    stmt->setBool(8, needsQuest);
    stmt->setInt32(9, randomPropertyId);
    stmt->setUInt32(10, randomSuffix);
    trans->Append(stmt);
}

void StoredLootContainer::AddMoney(uint32 money, SQLTransaction trans)
{
    _money = money;
    if (!trans)
        return;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_MONEY);
    stmt->setUInt32(0, _containerId);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEMCONTAINER_MONEY);
    stmt->setUInt32(0, _containerId);
    stmt->setUInt32(1, _money);
    trans->Append(stmt);
}

uint32 StoredLootContainer::GetContainer() const
{
    return _containerId;
}

uint32 StoredLootContainer::GetMoney() const
{
    return _money;
}

StoredLootItems const& StoredLootContainer::GetLootItems() const
{
    return _lootItems;
}

void StoredLootContainer::RemoveMoney()
{
    _money = 0;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_MONEY);
    stmt->setUInt32(0, _containerId);
    CharacterDatabase.Execute(stmt);
}

void StoredLootContainer::RemoveItem(uint32 itemId, uint32 count)
{
    for (auto itr = _lootItems.begin(); itr != _lootItems.end(); ++itr)
        if (itr->itemId == itemId && itr->count == count)
        {
            _lootItems.erase(itr);
            break;
        }

    // Deletes a single item associated with an openable item from the DB
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_ITEM);
    stmt->setUInt32(0, _containerId);
    stmt->setUInt32(1, itemId);
    stmt->setUInt32(2, count);
    CharacterDatabase.Execute(stmt);
}
