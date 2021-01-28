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
#include "TSLoot.h"
#include "Loot.h"
#include "LootMgr.h"
#include "ObjectGuid.h"
#include "TSMath.h"

TSLoot::TSLoot(Loot *loot)
{
    this->loot = loot;
}

TSLoot::TSLoot()
{
    this->loot = nullptr;
}

void TSLoot::Clear()
{
    loot->clear();
}

bool TSLoot::IsLooted()
{
    return loot->isLooted();
}

void TSLoot::AddItem(uint32 id, uint8 minCount, uint8 maxCount, uint16 lootmode, bool needsQuest, uint8 groupId)
{
    loot->items.reserve(MAX_NR_LOOT_ITEMS);
    loot->quest_items.reserve(MAX_NR_QUEST_ITEMS);
    loot->AddItem(LootStoreItem(id,0,100,lootmode,needsQuest,groupId,minCount,maxCount));
}

void TSLoot::AddLooter(uint64 looter)
{
    loot->AddLooter(ObjectGuid(looter));
}

void TSLoot::RemoveLooter(uint64 looter)
{
    loot->RemoveLooter(ObjectGuid(looter));
}

void TSLoot::SetMoney(uint32 money)
{
    loot->gold = money;
}

uint32 TSLoot::GetMoney()
{
    return loot->gold;
}

void TSLoot::SetLootType(uint32 lootType)
{
    loot->loot_type = LootType(lootType);
}

uint32 TSLoot::GetLootType()
{
    return loot->loot_type;
}

void TSLoot::SetLootOwner(uint64 owner)
{
    loot->lootOwnerGUID = ObjectGuid(owner);
}

uint64 TSLoot::GetLootOwner()
{
    return loot->lootOwnerGUID;
}

TSLootItem::TSLootItem(LootItem* item)
{
    this->item = item;
}

uint32 TSLootItem::GetItemID()
{
    return item->itemid;
}

uint32 TSLootItem::GetRandomSuffix()
{
    return item->randomSuffix;
}

int32 TSLootItem::GetRandomPropertyID()
{
    return item->randomPropertyId;
}

uint8 TSLootItem::GetCount()
{
    return item->count;
}

void TSLootItem::SetItemID(uint32 id)
{
    item->itemid = id;
}

void TSLootItem::SetRandomSuffix(uint32 randomSuffix)
{
    item->randomSuffix = randomSuffix;
}

void TSLootItem::SetRandomPropertyID(int32 randomPropertyId)
{
    item->randomPropertyId = randomPropertyId;
}

void TSLootItem::SetCount(uint8 count)
{
    item->count = count;
}

uint32 TSLoot::GetItemCount()
{
    return loot->items.size();
}

uint32 TSLoot::GetQuestItemCount()
{
    return loot->quest_items.size();
}

TSLootItem TSLoot::GetItem(uint32 index)
{
    return TSLootItem(&loot->items[index]);
}

TSLootItem TSLoot::GetQuestItem(uint32 index)
{
    return TSLootItem(&loot->quest_items[index]);
}

void TSLoot::Filter(std::function<bool(TSLootItem)> predicate)
{
    auto it = loot->items.begin();
    while(it != loot->items.end())
    {
        if(!predicate(TSLootItem(&*it)))
        {
            --loot->unlootedCount;
            it = loot->items.erase(it);
        }
        else
        {
            ++it;
        }
    }

    it = loot->quest_items.begin();
    while(it != loot->quest_items.end())
    {
        if(!predicate(TSLootItem(&*it)))
        {
            --loot->unlootedCount;
            it = loot->quest_items.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

bool TSLoot::GetGeneratesNormally()
{
    return loot->generateNormally;
}

void TSLoot::SetGeneratesNormally(bool generatesNormally)
{
    loot->generateNormally = generatesNormally;
}