/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __LOOTITEMSTORAGE_H
#define __LOOTITEMSTORAGE_H

#include "Common.h"
#include "LootMgr.h"

#include <unordered_map>
#include <vector>

class Player;
namespace boost
{
    class shared_mutex;
}

struct StoredLootItem
{
    StoredLootItem(uint32 itemId, uint32 count, bool followRules, bool ffa, bool blocked, bool counted, bool underTreshold, bool needsQuest, int32 randomPropertyId, uint32 randomSuffix) : 
        itemId(itemId), count(count), followRules(followRules), ffa(ffa), blocked(blocked), counted(counted), underTreshold(underTreshold), needsQuest(needsQuest),
        randomPropertyId(randomPropertyId), randomSuffix(randomSuffix)
    {
    }

    uint32 itemId;
    uint32 count;
    bool followRules;
    bool ffa;
    bool blocked;
    bool counted;
    bool underTreshold;
    bool needsQuest;
    int32 randomPropertyId;
    uint32 randomSuffix;
};

typedef std::vector<StoredLootItem> StoredLootItems;

class StoredLootContainer
{
    public:
        StoredLootContainer() : _money(0) { }

        void SetContainer(uint32 containerId);
        void AddLootItem(uint32 itemId, uint32 count, bool followRules, bool ffa, bool blocked, bool counted, bool underTreshold, bool needsQuest, int32 randomPropertyId, uint32 randomSuffix, SQLTransaction trans);
        void AddMoney(uint32 money, SQLTransaction trans);

        void RemoveMoney();
        void RemoveItem(uint32 itemId, uint32 count);

        uint32 GetContainer() const;
        uint32 GetMoney() const;
        StoredLootItems const& GetLootItems() const;

    private:
        StoredLootItems _lootItems;
        uint32 _money;
        uint32 _containerId;
};

typedef std::unordered_map<uint32, StoredLootContainer> LootItemContainer;

class LootItemStorage
{
    public:
        LootItemStorage();
        ~LootItemStorage();

        static LootItemStorage* instance();
        static boost::shared_mutex* GetLock();

        void LoadStorageFromDB();
        bool LoadStoredLoot(Item* item, Player* player);
        void RemoveStoredMoneyForContainer(uint32 containerId);
        void RemoveStoredLootForContainer(uint32 containerId);
        void RemoveStoredLootItemForContainer(uint32 containerId, uint32 itemId, uint32 count);
        void AddNewStoredLoot(Loot* loot, Player* player);

    private:
        LootItemContainer _lootItemStore;
};

#define sLootItemStorage LootItemStorage::instance()

#endif
