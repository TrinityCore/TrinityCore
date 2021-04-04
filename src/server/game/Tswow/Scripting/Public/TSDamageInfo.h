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

#include "TSBase.h"
#include "TSUnit.h"

struct CalcDamageInfo;
struct SpellNonMeleeDamage;

class TC_GAME_API TSMeleeDamageInfo {
public:
    CalcDamageInfo * _info;
    TSMeleeDamageInfo(CalcDamageInfo * info);
    TSMeleeDamageInfo * operator->() { return this;}

    TSUnit GetAttacker();
    TSUnit GetTarget();

    uint32 GetSchool1();
    uint32 GetSchool2();

    uint32 GetDamage1();
    uint32 GetDamage2();

    uint32 GetAbsorb1();
    uint32 GetAbsorb2();

    uint32 GetResist1();
    uint32 GetResist2();

    uint32 GetBlocked();
    uint32 GetHitInfo();
    uint32 GetTargetState();

    uint32 GetAttackType();
    uint32 GetProcAttacker();
    uint32 GetProcVictim();
    uint32 GetCleanDamage();

    uint8 GetMeleeHitOutcome();
};

class TC_GAME_API TSSpellDamageInfo {
public:
    SpellNonMeleeDamage * _info;
    TSSpellDamageInfo(SpellNonMeleeDamage * info);
    TSSpellDamageInfo* operator->() { return this; }
    TSUnit GetAttacker();
    TSUnit GetTarget();
    uint32 GetSpellID();
    uint32 GetDamage();
    uint32 GetOverkill();
    uint32 GetSchoolMask();
    uint32 GetAbsorb();
    uint32 GetResist();
    bool GetPeriodicLog();
    bool GetUnused();
    uint32 GetBlocked();
    uint32 GetHitInfo();
    uint32 GetCleanDamage();
    bool GetFullBlock();
};