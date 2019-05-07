/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
    DATA_MAGMAW                                     = 0,
    DATA_OMNOTRON_DEFENSE_SYSTEM                    = 1,
    DATA_CHIMAERON                                  = 2,
    DATA_ATRAMEDES                                  = 3,
    DATA_MALORIAK                                   = 4,
    DATA_NEFARIANS_END                              = 5,

    // Encounter Data
    DATA_PREPARE_MASSIVE_CRASH_AND_GET_TARGET_GUID,
    DATA_NEFARIAN_MAGMAW,
};

enum BWDCreatureIds
{
    // Bosses
    BOSS_MAGMAW                     = 41570,
    BOSS_MAGMATRON                  = 42178,
    BOSS_ARCANOTRON                 = 42166,
    BOSS_TOXITRON                   = 42180,
    BOSS_ELECTRON                   = 42179,
    BOSS_CHIMAERON                  = 43296,
    BOSS_ATRAMEDES                  = 41442,
    BOSS_MALORIAK                   = 41378,
    BOSS_NEFARIAN                   = 41376,

    // Encounter related creatures
    /*Magmaw*/
    NPC_MAGMAWS_PINCER_1            = 41620,
    NPC_MAGMAWS_PINCER_2            = 41789,
    NPC_EXPOSED_HEAD_OF_MAGMAW      = 42347,
    NPC_EXPOSED_HEAD_OF_MAGMAW_2    = 48270,
    NPC_PILLAR_OF_FLAME             = 41843,
    NPC_LAVA_PARASITE_1             = 41806,
    NPC_LAVA_PARASITE_2             = 42321,
    NPC_MASSIVE_CRASH               = 47330,
    NPC_ROOM_STALKER                = 47196,
    NPC_MAGMAW_SPIKE_STALKER        = 41767,
    NPC_NEFARIAN_MAGMAW             = 49427,
    NPC_BLAZING_BONE_CONSTRUCT      = 49416,
    NPC_IGNITION                    = 49447,
};

enum BWDGameObjectIds
{
};

enum BWDMisc
{
    MASSIVE_CRASH_SIDE_LEFT     = 0,
    MASSIVE_CRASH_SIDE_RIGHT    = 1
};

enum BWDSpells
{
    // Room Stalker
    SPELL_LIGHT_SHOW            = 87949,

    // Massive Crash
    SPELL_MASSIVE_CRASH_DAMAGE  = 88287,
};

template <class AI, class T>
inline AI* GetBlackwingDescentAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BWDScriptName);
}

#define RegisterBlackwingDescentCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetBlackwingDescentAI)

#endif
