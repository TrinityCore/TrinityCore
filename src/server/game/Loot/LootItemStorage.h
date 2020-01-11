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

#ifndef __LOOTITEMSTORAGE_H
#define __LOOTITEMSTORAGE_H

#include "Define.h"
#include "DatabaseEnvFwd.h"

#include <unordered_map>

class Item;
class Player;
struct Loot;
struct LootItem;

namespace boost
{
    class shared_mutex;
}

struct StoredLootItem
{
    explicit StoredLootItem(LootItem const& lootItem);

    uint32 ItemId;
    uint32 Count;
    bool FollowRules;
    bool FFA;
    bool Blocked;
    bool Counted;
    bool UnderThreshold;
    bool NeedsQuest;
    int32 RandomPropertyId;
    uint32 RandomSuffix;
};

class StoredLootContainer
{
    public:
        typedef std::unordered_multimap<uint32 /*itemId*/, StoredLootItem> StoredLootItemContainer;

        explicit StoredLootContainer(uint32 containerId) : _containerId(containerId), _money(0) { }

        void AddLootItem(LootItem const& lootItem, SQLTransaction& trans);
        void AddMoney(uint32 money, SQLTransaction& trans);

        void RemoveMoney();
        void RemoveItem(uint32 itemId, uint32 count);

        uint32 GetContainer() const { return _containerId; }
        uint32 GetMoney() const { return _money; }
        StoredLootItemContainer const& GetLootItems() const { return _lootItems; }

    private:
        StoredLootItemContainer _lootItems;
        uint32 const _containerId;
        uint32 _money;
};

class LootItemStorage
{
    public:
        static LootItemStorage* instance();
        static boost::shared_mutex* GetLock();

        void LoadStorageFromDB();
        bool LoadStoredLoot(Item* item, Player* player);
        void RemoveStoredMoneyForContainer(uint32 containerId);
        void RemoveStoredLootForContainer(uint32 containerId);
        void RemoveStoredLootItemForContainer(uint32 containerId, uint32 itemId, uint32 count);
        void AddNewStoredLoot(Loot* loot, Player* player);

    private:
        LootItemStorage() { }
        ~LootItemStorage() { }
};

#define sLootItemStorage LootItemStorage::instance()

#endif
