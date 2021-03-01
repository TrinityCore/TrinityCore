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
#include "TSClasses.h"
#include "TSPosition.h"
#include "TSSpellInfo.h"

class TC_GAME_API TSSpell {
public:
    Spell * spell;
    TSSpell(Spell *spell);
    TSSpell();
    TSSpell* operator->() { return this;}
    bool IsNull() { return spell == nullptr; };
    bool IsAutoRepeat();
    TSWorldObject GetCaster();
    int32 GetCastTime();
    uint32 GetEntry();
    uint32 GetPowerCost();
    int32 GetDuration();
    TSPosition GetTargetDest();
    TSObject  GetTarget();
    TSSpellInfo GetSpellInfo();
    void SetAutoRepeat(bool repeat);
    void Cast(bool skipCheck);
    void Cancel();
    void Finish();
};
