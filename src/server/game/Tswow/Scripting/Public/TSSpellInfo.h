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

class TC_GAME_API TSSpellInfo {
public:
    SpellInfo * info;
    TSSpellInfo(SpellInfo const* info);
    TSSpellInfo();
    TSSpellInfo* operator->() { return this;}
    bool IsNull() { return info == nullptr; }
    uint32 ID();
    uint32 School();
    uint32 BaseLevel();
    uint32 DmgClass();
    uint32 ActiveIconID();
    uint32 AreaGroupId();
    uint32 Attributes();
    uint32 AttributesCu();
    uint32 AttributesEx();
    uint32 AttributesEx2();
    uint32 AttributesEx3();
    uint32 AttributesEx4();
    uint32 AttributesEx5();
    uint32 AttributesEx6();
    uint32 AttributesEx7();
    uint32 AuraInterruptFlags();
    uint32 CasterAuraSpell();
    uint32 CasterAuraState();
    uint32 CasterAuraStateNot();
    uint32 CategoryRecoveryTime();
    uint32 ChannelInterruptFlags();
    uint32 Dispel();
    uint32 EquippedItemClass();
    uint32 EquippedItemInventoryTypeMask();
    uint32 EquippedItemSubClassMask();
    uint32 ExcludeCasterAuraSpell();
    uint32 ExcludeTargetAuraSpell();
    uint32 ExplicitTargetMask();
    uint32 FacingCasterFlags();
    uint32 InterruptFlags();
    uint32 ManaCost();
    uint32 ManaCostPercentage();
    uint32 ManaCostPerlevel();
    uint32 ManaPerSecond();
    uint32 ManaPerSecondPerLevel();
    uint32 MaxAffectedTargets();
    uint32 MaxLevel();
    uint32 MaxTargetLevel();
    uint32 Mechanic();
    uint32 PowerType();
    uint32 PreventionType();
    uint32 Priority();
    uint32 ProcChance();
    uint32 ProcCharges();
    uint32 ProcFlags();
    uint32 RecoveryTime();
    uint32 RequiresSpellFocus();
    uint32 RuneCostID();
    uint32 SchoolMask();
    uint32 Speed();
    uint32 SpellFamilyFlags();
    uint32 SpellFamilyName();
    uint32 SpellIconID();
    uint32 SpellLevel();
    uint32 StackAmount();
    uint32 Stances();
    uint32 StancesNot();
    uint32 StartRecoveryCategory();
    uint32 StartRecoveryTime();
    uint32 TargetAuraSpell();
    uint32 TargetAuraState();
    uint32 TargetAuraStateNot();
    uint32 TargetCreatureType();
    uint32 Targets();
    TSStorage * GetData();
    TS_ENTITY_DATA_DECL(TSSpellInfo);
};

TC_GAME_API TSSpellInfo GetSpellInfo(uint32 entry);