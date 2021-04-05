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
#include "TSIncludes.h"
#include "TSItemTemplate.h"
#include "ItemTemplate.h"
#include "ObjectMgr.h"
#include <memory.h>

TSItemTemplate::TSItemTemplate(ItemTemplate const* info)
{
    this->info = const_cast<ItemTemplate*>(info);
}

TSItemTemplate::TSItemTemplate()
{
    this->info = nullptr;
}

uint32 TSItemTemplate::ID()  {
    return info->ItemId;
}

uint32 TSItemTemplate::Class() { return info->Class; }
uint32 TSItemTemplate::SubClass() { return info->SubClass; };
int32  TSItemTemplate::SoundOverrideSubclass() { return info->SoundOverrideSubclass; };
TSString TSItemTemplate::Name() { return JSTR(info->Name1); };
uint32 TSItemTemplate::DisplayInfoID() { return info->DisplayInfoID; };
uint32 TSItemTemplate::Quality() { return info->Quality; };
uint32 TSItemTemplate::Flags() { return info->Flags; };
uint32 TSItemTemplate::Flags2() { return info->Flags2; };
uint32 TSItemTemplate::BuyCount() { return info->BuyCount; };
int32  TSItemTemplate::BuyPrice() { return info->BuyPrice; };
uint32 TSItemTemplate::SellPrice() { return info->SellPrice; };
uint32 TSItemTemplate::InventoryType() { return info->InventoryType; };
uint32 TSItemTemplate::AllowableClass() { return info->AllowableClass; };
uint32 TSItemTemplate::AllowableRace() { return info->AllowableRace; };
uint32 TSItemTemplate::ItemLevel() { return info->ItemLevel; };
uint32 TSItemTemplate::RequiredLevel() { return info->RequiredLevel; };
uint32 TSItemTemplate::RequiredSkill() { return info->RequiredSkill; };
uint32 TSItemTemplate::RequiredSkillRank() { return info->RequiredSkillRank; };
uint32 TSItemTemplate::RequiredSpell() { return info->RequiredSpell; };
uint32 TSItemTemplate::RequiredHonorRank() { return info->RequiredHonorRank; };
uint32 TSItemTemplate::RequiredCityRank() { return info->RequiredCityRank; };
uint32 TSItemTemplate::RequiredReputationFaction() { return info->RequiredReputationFaction; };
uint32 TSItemTemplate::RequiredReputationRank() { return info->RequiredReputationRank; };
int32  TSItemTemplate::MaxCount() { return info->MaxCount; };
int32  TSItemTemplate::Stackable() { return info->Stackable; };
uint32 TSItemTemplate::ContainerSlots() { return info->ContainerSlots; };
uint32 TSItemTemplate::StatsCount() { return info->StatsCount; };
uint32 TSItemTemplate::ScalingStatDistribution() { return info->ScalingStatDistribution; };
uint32 TSItemTemplate::ScalingStatValue() { return info->ScalingStatValue; };
uint32 TSItemTemplate::Armor() { return info->Armor; };
uint32 TSItemTemplate::HolyRes() { return info->HolyRes; };
uint32 TSItemTemplate::FireRes() { return info->FireRes; };
uint32 TSItemTemplate::NatureRes() { return info->NatureRes; };
uint32 TSItemTemplate::FrostRes() { return info->FrostRes; };
uint32 TSItemTemplate::ShadowRes() { return info->ShadowRes; };
uint32 TSItemTemplate::ArcaneRes() { return info->ArcaneRes; };
uint32 TSItemTemplate::Delay() { return info->Delay; };
uint32 TSItemTemplate::AmmoType() { return info->AmmoType; };
float  TSItemTemplate::RangedModRange() { return info->RangedModRange; };
uint32 TSItemTemplate::Bonding() { return info->Bonding; };
TSString TSItemTemplate::Description() { return JSTR(info->Description); };
uint32 TSItemTemplate::PageText() { return info->PageText; };
uint32 TSItemTemplate::LanguageID() { return info->LanguageID; };
uint32 TSItemTemplate::PageMaterial() { return info->PageMaterial; };
uint32 TSItemTemplate::StartQuest() { return info->StartQuest; };
uint32 TSItemTemplate::LockID() { return info->LockID; };
int32  TSItemTemplate::Material() { return info->Material; };
uint32 TSItemTemplate::Sheath() { return info->Sheath; };
int32  TSItemTemplate::RandomProperty() { return info->RandomProperty; };
int32  TSItemTemplate::RandomSuffix() { return info->RandomSuffix; };
uint32 TSItemTemplate::Block() { return info->Block; };
uint32 TSItemTemplate::ItemSet() { return info->ItemSet; };
uint32 TSItemTemplate::MaxDurability() { return info->MaxDurability; };
uint32 TSItemTemplate::Area() { return info->Area; };
uint32 TSItemTemplate::Map() { return info->Map; };
uint32 TSItemTemplate::BagFamily() { return info->BagFamily; };
uint32 TSItemTemplate::TotemCategory() { return info->TotemCategory; };
uint32 TSItemTemplate::SocketBonus() { return info->socketBonus; };
uint32 TSItemTemplate::GemProperties() { return info->GemProperties; };
uint32 TSItemTemplate::RequiredDisenchantSkill(){ return info->RequiredDisenchantSkill; };
float  TSItemTemplate::ArmorDamageModifier() { return info->ArmorDamageModifier; };
uint32 TSItemTemplate::Duration() { return info->Duration; };
uint32 TSItemTemplate::ItemLimitCategory() { return info->ItemLimitCategory; };
uint32 TSItemTemplate::HolidayId() { return info->HolidayId; };
uint32 TSItemTemplate::ScriptId() { return info->ScriptId; };
uint32 TSItemTemplate::DisenchantID() { return info->DisenchantID; };
uint32 TSItemTemplate::FoodType() { return info->FoodType; };
uint32 TSItemTemplate::MinMoneyLoot() { return info->MinMoneyLoot; };
uint32 TSItemTemplate::MaxMoneyLoot() { return info->MaxMoneyLoot; };
uint32 TSItemTemplate::FlagsCu() { return info->FlagsCu; };

bool TSItemTemplate::IsCurrencyToken() { return info->IsCurrencyToken(); }
uint32 TSItemTemplate::GetMaxStackSize() {return info->GetMaxStackSize(); };
float TSItemTemplate::GetDPS() { return info->getDPS(); };
bool TSItemTemplate::CanChangeEquipStateInCombat() { return info->CanChangeEquipStateInCombat(); };
int32 TSItemTemplate::GetFeralBonus(int32 extraDPS) { return info->getFeralBonus(extraDPS); }
int32 TSItemTemplate::GetTotalAPBonus() { return info->GetTotalAPBonus(); }
float TSItemTemplate::GetItemLevelIncludingQuality() { return info->GetItemLevelIncludingQuality(); };
uint32 TSItemTemplate::GetSkill() { return info->GetSkill(); };
bool TSItemTemplate::IsPotion() { return info->IsPotion(); };
bool TSItemTemplate::IsWeaponVellum() { return info->IsWeaponVellum(); };
bool TSItemTemplate::IsArmorVellum() { return info->IsArmorVellum(); };
bool TSItemTemplate::IsConjuredConsumable() { return info->IsConjuredConsumable(); };
bool TSItemTemplate::HasSignature() { return info->HasSignature(); };

float TSItemTemplate::DamageMinA()
{
    return info->Damage[0].DamageMin;
}

float TSItemTemplate::DamageMinB()
{
    return info->Damage[1].DamageMin;
}

float TSItemTemplate::DamageMaxA()
{
    return info->Damage[0].DamageMax;
}

float TSItemTemplate::DamageMaxB()
{
    return info->Damage[1].DamageMax;
}

uint32 TSItemTemplate::DamageTypeA()
{
    return info->Damage[0].DamageType;
}

uint32 TSItemTemplate::DamageTypeB()
{
    return info->Damage[1].DamageType;
}

TSStorage * TSItemTemplate::GetData()
{
    return const_cast<TSStorage*>(&info->storage);
}

TS_ENTITY_DATA_IMPL(TSItemTemplate);

TSItemTemplate GetItemTemplate(uint32 entry)
{
    return TSItemTemplate(sObjectMgr->GetItemTemplate(entry));
}