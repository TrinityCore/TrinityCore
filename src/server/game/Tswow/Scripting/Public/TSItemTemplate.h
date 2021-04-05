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

#include "TSClasses.h"
#include "TSStorage.h"
#include "TSEntity.h"

class ItemTemplate;

class TC_GAME_API TSItemTemplate {
private:
    ItemTemplate * info;
public:
    bool IsNull() { return info == nullptr; };
    TSItemTemplate(ItemTemplate const* info);
    TSItemTemplate();
    TSItemTemplate* operator->() { return this;}
    uint32 ID();

    float DamageMinA();
    float DamageMinB();

    float DamageMaxA();
    float DamageMaxB();

    uint32 DamageTypeA();
    uint32 DamageTypeB();

    uint32 Class();
    uint32 SubClass();
    int32  SoundOverrideSubclass();
    TSString Name();
    uint32 DisplayInfoID();
    uint32 Quality();
    uint32 Flags();
    uint32 Flags2();
    uint32 BuyCount();
    int32  BuyPrice();
    uint32 SellPrice();
    uint32 InventoryType();
    uint32 AllowableClass();
    uint32 AllowableRace();
    uint32 ItemLevel();
    uint32 RequiredLevel();
    uint32 RequiredSkill();
    uint32 RequiredSkillRank();
    uint32 RequiredSpell();
    uint32 RequiredHonorRank();
    uint32 RequiredCityRank();
    uint32 RequiredReputationFaction();
    uint32 RequiredReputationRank();
    int32  MaxCount();
    int32  Stackable();
    uint32 ContainerSlots();
    uint32 StatsCount();
    uint32 ScalingStatDistribution();
    uint32 ScalingStatValue();
    uint32 Armor();
    uint32 HolyRes();
    uint32 FireRes();
    uint32 NatureRes();
    uint32 FrostRes();
    uint32 ShadowRes();
    uint32 ArcaneRes();
    uint32 Delay();
    uint32 AmmoType();
    float  RangedModRange();
    uint32 Bonding();
    TSString Description();
    uint32 PageText();
    uint32 LanguageID();
    uint32 PageMaterial();
    uint32 StartQuest();
    uint32 LockID();
    int32  Material();
    uint32 Sheath();
    int32  RandomProperty();
    int32  RandomSuffix();
    uint32 Block();
    uint32 ItemSet();
    uint32 MaxDurability();
    uint32 Area();
    uint32 Map();
    uint32 BagFamily();
    uint32 TotemCategory();
    uint32 SocketBonus();
    uint32 GemProperties();
    uint32 RequiredDisenchantSkill();
    float  ArmorDamageModifier();
    uint32 Duration();
    uint32 ItemLimitCategory();
    uint32 HolidayId();
    uint32 ScriptId();
    uint32 DisenchantID();
    uint32 FoodType();
    uint32 MinMoneyLoot();
    uint32 MaxMoneyLoot();
    uint32 FlagsCu();

    bool IsCurrencyToken();
    uint32 GetMaxStackSize();
    float GetDPS();
    bool CanChangeEquipStateInCombat();
    int32 GetFeralBonus(int32 extraDPS = 0);
    int32 GetTotalAPBonus();
    float GetItemLevelIncludingQuality();
    uint32 GetSkill();
    bool IsPotion();
    bool IsWeaponVellum();
    bool IsArmorVellum();
    bool IsConjuredConsumable();
    bool HasSignature();

    TSStorage * GetData();
    TS_ENTITY_DATA_DECL(TSItemTemplate);
};
