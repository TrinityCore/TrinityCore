/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include "TSMain.h"
#include "TSArray.h"

class TC_GAME_API TSLootStoreItem {
public:
    uint32 itemid;
    uint32 reference;
    float chance;
    uint16 lootmode;
    bool needs_quest;
    uint8 groupid;
    uint8 mincount;
    uint8 maxcount;

    TSLootStoreItem() {};
    TSLootStoreItem* operator->() {return this;}

    TSLootStoreItem SetItemID(uint32 itemId);
    TSLootStoreItem SetReference(uint32 reference);
    TSLootStoreItem SetChance(float chance);
    TSLootStoreItem SetLootMode(uint16 lootmode);
    TSLootStoreItem SetNeedsQuest(bool needsQuest);
    TSLootStoreItem SetGroupID(uint8 groupId);
    TSLootStoreItem SetMinCount(uint8 min);
    TSLootStoreItem SetMaxCount(uint8 max);

    uint32 GetItemID();
    uint32 GetReference();
    float GetChance();
    uint16 GetLootMode();
    bool GetNeedsQuest();
    uint8 GetGroupID();
    uint8 GetMinCount();
    uint8 GetMaxCount();
};

TC_GAME_API TSLootStoreItem CreateLootItem(uint32 id, uint32 reference = 0, float chance = 100, uint16 lootmode = 0, bool needsQuest = false, uint8 groupId = 0, uint8 minCount = 1, uint8 maxCount = 1);

class Loot;
class TC_GAME_API TSLoot {
    public:
        Loot *loot;
        TSLoot(Loot *loot);
        TSLoot();
        TSLoot* operator->() {return this;}
        bool IsNull() { return loot == nullptr; }
        void Clear();
        bool IsLooted();
        void AddItem(TSLootStoreItem item);
        void AddItems(TSArray<TSLootStoreItem> items);
        void AddLooter(uint64 looter);
        void RemoveLooter(uint64 looter);

        uint32 GetLootType();
        void SetLootType(uint32 lootType);

        uint32 GetMoney();
        void SetMoney(uint32 money);

        uint64 GetLootOwner();
        void SetLootOwner(uint64 owner);
};
