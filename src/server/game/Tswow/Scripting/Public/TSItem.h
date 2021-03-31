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
#include "TSString.h"
#include "TSClasses.h"
#include "TSObject.h"
#include "TSItemTemplate.h"

class TC_GAME_API TSItem : public TSObject {
public:
    Item* item;
    bool IsNull() { return item == nullptr; };
    TSItem(Item* item);
    TSItem();
    TSItem* operator->() { return this;}
    bool IsSoulBound();
    bool IsBoundAccountWide();
    bool IsBoundByEnchant();
    bool IsNotBoundToPlayer(TSPlayer player);
    bool IsLocked();
    bool IsBag();
    bool IsCurrencyToken();
    bool IsNotEmptyBag();
    bool IsBroken();
    bool CanBeTraded(bool mail);
    bool IsInTrade();
    bool IsInBag();
    bool IsEquipped();
    bool HasQuest(uint32 quest);
    bool IsPotion();
    bool IsWeaponVellum();
    bool IsArmorVellum();
    bool IsConjuredConsumable();
    TSItemTemplate GetTemplate();
    TSString GetItemLink(uint8 locale);
    uint64 GetOwnerGUID();
    TSPlayer  GetOwner();
    uint32 GetCount();
    uint32 GetMaxStackCount();
    uint8 GetSlot();
    uint8 GetBagSlot();
    uint32 GetEnchantmentId(uint32 enchant_slot);
    uint32 GetSpellId(uint32 index);
    uint32 GetSpellTrigger(uint32 index);
    uint32 GetClass();
    uint32 GetSubClass();
    TSString GetName();
    uint32 GetDisplayId();
    uint32 GetQuality();
    uint32 GetBuyCount();
    uint32 GetBuyPrice();
    uint32 GetSellPrice();
    uint32 GetInventoryType();
    uint32 GetAllowableClass();
    uint32 GetAllowableRace();
    uint32 GetItemLevel();
    uint32 GetRequiredLevel();
    uint32 GetStatsCount();
    uint32 GetRandomProperty();
    int32 GetRandomSuffix();
    uint32 GetItemSet();
    uint32 GetBagSize();
    void SetOwner(TSPlayer player);
    void SetBinding(bool soulbound);
    void SetCount(uint32 count);
    bool SetEnchantment(uint32 enchant, uint32 slot);
    bool ClearEnchantment(uint32 slot);
    void SaveToDB();
};

TC_GAME_API TSItem CreateItem(uint32 entry, uint32 count = 0);