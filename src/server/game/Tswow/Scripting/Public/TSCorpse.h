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

#include "TSLoot.h"
#include "TSMain.h"
#include "TSClasses.h"
#include "TSWorldObject.h"

class TC_GAME_API TSCorpse : public TSWorldObject {
public:
    Corpse* corpse;
    bool IsNull() { return corpse==nullptr; };
    TSCorpse(Corpse* corpse);
    TSCorpse();
    TSCorpse* operator->() { return this;}
    uint64 GetOwnerGUID();
    uint32 GetGhostTime();
    uint32 GetType();
    TSLoot GetLoot();
    void ResetGhostTime();
    void SaveToDB();
};
