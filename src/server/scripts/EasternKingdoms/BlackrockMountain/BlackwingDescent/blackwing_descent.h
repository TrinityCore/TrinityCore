/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DEF_BLACKWING_DESCENT_H
#define DEF_BLACKWING_DESCENT_H

#include "CreatureAIImpl.h"

#define DataHeader "BWD"
#define BWDScriptName "instance_blackwing_descent"

uint32 const EncounterCount = 6;

enum BWDDataTypes
{
    // Bosses
    DATA_MAGMAW                     = 0,
    DATA_OMNOTRON_DEFENSE_SYSTEM    = 1,
    DATA_CHIMAERON                  = 2,
    DATA_ATRAMEDES                  = 3,
    DATA_MALORIAK                   = 4,
    DATA_NEFARIANS_END              = 5
};

enum BWDCreatureIds
{
    // Bosses
    BOSS_MAGMAW     = 41570,
    BOSS_MAGMATRON  = 42178,
    BOSS_ARCANOTRON = 42166,
    BOSS_TOXITRON   = 42180,
    BOSS_ELECTRON   = 42179,
    BOSS_CHIMAERON  = 43296,
    BOSS_ATRAMEDES  = 41442,
    BOSS_MALORIAK   = 41378,
    BOSS_NEFARIAN   = 41376
};

enum BWDGameObjectIds
{
};

template <class AI, class T>
inline AI* GetBlackwingDescentAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BWDcriptName);
}

#define RegisterBlackwingDescentCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetBlackwingDescentAI)

#endif
