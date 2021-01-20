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

TSLootStoreItem TSLootStoreItem::SetItemID(uint32 itemId)
{
    this->itemid = itemId;
    return *this;
}

TSLootStoreItem TSLootStoreItem::SetReference(uint32 reference)
{
    this->reference = reference;
    return *this;
}

TSLootStoreItem TSLootStoreItem::SetChance(float chance)
{
    this->chance = chance;
    return *this;
}

TSLootStoreItem TSLootStoreItem::SetLootMode(uint16 lootmode)
{
    this->lootmode = lootmode;
    return *this;
}

TSLootStoreItem TSLootStoreItem::SetNeedsQuest(bool needsQuest)
{
    this->needs_quest = needsQuest;
    return *this;
}

TSLootStoreItem TSLootStoreItem::SetGroupID(uint8 groupId)
{
    this->groupid= groupId;
    return *this;
}

TSLootStoreItem TSLootStoreItem::SetMinCount(uint8 minCount)
{
    this->mincount = minCount;
    return *this;
}

TSLootStoreItem TSLootStoreItem::SetMaxCount(uint8 maxCount)
{
    this->maxcount = maxCount;
    return *this;
}

uint32 TSLootStoreItem::GetItemID()
{
    return this->itemid;
}

uint32 TSLootStoreItem::GetReference()
{
    return this->reference;
}

float TSLootStoreItem::GetChance()
{
    return this->chance;
}

uint16 TSLootStoreItem::GetLootMode()
{
    return this->lootmode;
}

bool TSLootStoreItem::GetNeedsQuest()
{
    return this->needs_quest;
}

uint8 TSLootStoreItem::GetGroupID()
{
    return this->groupid;
}

uint8 TSLootStoreItem::GetMinCount()
{
    return this->mincount;
}

uint8 TSLootStoreItem::GetMaxCount()
{
    return this->maxcount;
}

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

void TSLoot::AddItem(TSLootStoreItem item)
{
    if(item.chance < 100 && Math.random()*100>item.chance)
    {
        return;
    }
    // TODO: Maybe we don't need to initialize both
    loot->items.reserve(MAX_NR_LOOT_ITEMS);
    loot->quest_items.reserve(MAX_NR_QUEST_ITEMS);

    LootStoreItem storeItem(item.itemid,item.reference,item.chance,item.lootmode,item.needs_quest,item.groupid,item.mincount,item.maxcount);
    loot->AddItem(storeItem);
}

void TSLoot::AddItems(TSArray<TSLootStoreItem> items)
{
    for(int i=0;i<items.get_length();++i) {
        AddItem(items->get(i));
    }
}

void TSLoot::AddLooter(uint64 looter)
{
    loot->AddLooter(ObjectGuid(looter));
}

void TSLoot::RemoveLooter(uint64 looter)
{
    loot->RemoveLooter(ObjectGuid(looter));
}

TC_GAME_API TSLootStoreItem CreateLootItem(uint32 id, uint32 reference, float chance, uint16 lootmode, bool needsQuest, uint8 groupId, uint8 minCount, uint8 maxCount)
{
    return TSLootStoreItem()
        ->SetItemID(id)
        ->SetReference(reference)
        ->SetChance(chance)
        ->SetLootMode(lootmode)
        ->SetNeedsQuest(needsQuest)
        ->SetGroupID(groupId)
        ->SetMinCount(minCount)
        ->SetMaxCount(maxCount);
}