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
#include "TSSpellInfo.h"
#include <memory.h>
#include "SpellInfo.h"
#include "SpellMgr.h"

TSSpellInfo::TSSpellInfo(SpellInfo const* info)
{
    this->info = const_cast<SpellInfo*>(info);
}

TSSpellInfo::TSSpellInfo()
{
    this->info = nullptr;
}

uint32 TSSpellInfo::ID()  {
    return info->Id;
}

uint32 TSSpellInfo::School()
{
    return info->SchoolMask;
}
uint32 TSSpellInfo::BaseLevel()
{
    return info->BaseLevel;
}

uint32 TSSpellInfo::DmgClass()
{
    return info->DmgClass;
}

uint32 TSSpellInfo::ActiveIconID()
{
    return info->ActiveIconID;
}

uint32 TSSpellInfo::AreaGroupId()
{
    return info->AreaGroupId;
}

uint32 TSSpellInfo::Attributes()
{
    return info->Attributes;
}

uint32 TSSpellInfo::AttributesCu()
{
    return info->AttributesCu;
}

uint32 TSSpellInfo::AttributesEx()
{
    return info->AttributesEx;
}

uint32 TSSpellInfo::AttributesEx2()
{
    return info->AttributesEx2;
}

uint32 TSSpellInfo::AttributesEx3()
{
    return info->AttributesEx3;
}

uint32 TSSpellInfo::AttributesEx4()
{
    return info->AttributesEx4;
}

uint32 TSSpellInfo::AttributesEx5()
{
    return info->AttributesEx5;
}

uint32 TSSpellInfo::AttributesEx6()
{
    return info->AttributesEx6;
}

uint32 TSSpellInfo::AttributesEx7()
{
    return info->AttributesEx7;
}

uint32 TSSpellInfo::AuraInterruptFlags()
{
    return info->AuraInterruptFlags;
}

uint32 TSSpellInfo::CasterAuraSpell()
{
    return info->CasterAuraSpell;
}

uint32 TSSpellInfo::CasterAuraState()
{
    return info->CasterAuraState;
}

uint32 TSSpellInfo::CasterAuraStateNot()
{
    return info->CasterAuraStateNot;
}

uint32 TSSpellInfo::CategoryRecoveryTime()
{
    return info->CategoryRecoveryTime;
}

uint32 TSSpellInfo::ChannelInterruptFlags()
{
    return info->ChannelInterruptFlags;
}

uint32 TSSpellInfo::Dispel()
{
    return info->Dispel;
}

uint32 TSSpellInfo::EquippedItemClass()
{
    return info->EquippedItemClass;
}

uint32 TSSpellInfo::EquippedItemInventoryTypeMask()
{
    return info->EquippedItemInventoryTypeMask;
}

uint32 TSSpellInfo::EquippedItemSubClassMask()
{
    return info->EquippedItemSubClassMask;
}

uint32 TSSpellInfo::ExcludeCasterAuraSpell()
{
    return info->ExcludeCasterAuraSpell;
}

uint32 TSSpellInfo::ExcludeTargetAuraSpell()
{
    return info->ExcludeTargetAuraSpell;
}

uint32 TSSpellInfo::ExplicitTargetMask()
{
    return info->ExplicitTargetMask;
}

uint32 TSSpellInfo::FacingCasterFlags()
{
    return info->FacingCasterFlags;
}

uint32 TSSpellInfo::InterruptFlags()
{
    return info->InterruptFlags;
}

uint32 TSSpellInfo::ManaCost()
{
    return info->ManaCost;
}

uint32 TSSpellInfo::ManaCostPercentage()
{
    return info->ManaCostPercentage;
}

uint32 TSSpellInfo::ManaCostPerlevel()
{
    return info->ManaCostPerlevel;
}

uint32 TSSpellInfo::ManaPerSecond()
{
    return info->ManaPerSecond;
}

uint32 TSSpellInfo::ManaPerSecondPerLevel()
{
    return info->ManaPerSecondPerLevel;
}

uint32 TSSpellInfo::MaxAffectedTargets()
{
    return info->MaxAffectedTargets;
}

uint32 TSSpellInfo::MaxLevel()
{
    return info->MaxLevel;
}

uint32 TSSpellInfo::MaxTargetLevel()
{
    return info->MaxTargetLevel;
}

uint32 TSSpellInfo::Mechanic()
{
    return info->Mechanic;
}

uint32 TSSpellInfo::PowerType()
{
    return info->PowerType;
}

uint32 TSSpellInfo::PreventionType()
{
    return info->PreventionType;
}

uint32 TSSpellInfo::Priority()
{
    return info->Priority;
}

uint32 TSSpellInfo::ProcChance()
{
    return info->ProcChance;
}

uint32 TSSpellInfo::ProcCharges()
{
    return info->ProcCharges;
}

uint32 TSSpellInfo::ProcFlags()
{
    return info->ProcFlags;
}

uint32 TSSpellInfo::RecoveryTime()
{
    return info->RecoveryTime;
}

uint32 TSSpellInfo::RequiresSpellFocus()
{
    return info->RequiresSpellFocus;
}

uint32 TSSpellInfo::RuneCostID()
{
    return info->RuneCostID;
}

uint32 TSSpellInfo::SchoolMask()
{
    return info->SchoolMask;
}

uint32 TSSpellInfo::Speed()
{
    return info->Speed;
}

uint32 TSSpellInfo::SpellFamilyFlags()
{
    return info->SpellFamilyFlags;
}

uint32 TSSpellInfo::SpellFamilyName()
{
    return info->SpellFamilyName;
}

uint32 TSSpellInfo::SpellIconID()
{
    return info->SpellIconID;
}

uint32 TSSpellInfo::SpellLevel()
{
    return info->SpellLevel;
}

uint32 TSSpellInfo::StackAmount()
{
    return info->StackAmount;
}

uint32 TSSpellInfo::Stances()
{
    return info->Stances;
}

uint32 TSSpellInfo::StancesNot()
{
    return info->StancesNot;
}

uint32 TSSpellInfo::StartRecoveryCategory()
{
    return info->StartRecoveryCategory;
}

uint32 TSSpellInfo::StartRecoveryTime()
{
    return info->StartRecoveryTime;
}

uint32 TSSpellInfo::TargetAuraSpell()
{
    return info->TargetAuraSpell;
}

uint32 TSSpellInfo::TargetAuraState()
{
    return info->TargetAuraState;
}

uint32 TSSpellInfo::TargetAuraStateNot()
{
    return info->TargetAuraStateNot;
}

uint32 TSSpellInfo::TargetCreatureType()
{
    return info->TargetCreatureType;
}

uint32 TSSpellInfo::Targets()
{
    return info->Targets;
}

TSStorage * TSSpellInfo::GetData()
{
    return const_cast<TSStorage*>(&info->storage);
}

TS_ENTITY_DATA_IMPL(TSSpellInfo);

TSSpellInfo GetSpellInfo(uint32 entry)
{
    return TSSpellInfo(sSpellMgr->GetSpellInfo(entry));
}