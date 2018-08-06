/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef THRONEOFTHETIDES_H_
#define THRONEOFTHETIDES_H_

#include "CreatureAIImpl.h"

#define TotTScriptName "instance_throne_of_the_tides"
#define DataHeader "TOTT"

uint32 const EncounterCount = 4;

enum TotTDataTypes
{
    // Encounters
    DATA_LADY_NAZJAR            = 0,
    DATA_COMMANDER_ULTHOK       = 1,
    DATA_MINDBENDER_GURSHA      = 2,
    DATA_OZUMAT                 = 3,

    // Additional Data Types
    DATA_CURRENT_EVENT_PROGRESS = 4
};

enum TotTCreatureIds
{
    // Bosses
    BOSS_LADY_NAZJAR                = 40586,
    BOSS_COMMANDER_ULTHOK           = 40765,
    BOSS_MINDBENDER_GURSHA          = 40788,
    BOSS_OZUMAT                     = 40655,

    // Event Creatures
    NPC_OZUMAT_VEHICLE_BIG          = 45030,
    NPC_OZUMAT_VEHICLE              = 44581,
    NPC_WORLD_TRIGGER_INFINITE_AOI  = 36171,
    NPC_NAZJAR_SPIRITMENDER         = 41096,
    NPC_NAZJAR_INVADER              = 39616,

};

enum TotTSpells
{
    SPELL_SUMMON_FALLING_ROCKS              = 74465,
    SPELL_WATER_JUMP_THROUGH_WINDOW_VISUAL  = 74048
};

enum TotTEventIndex
{
    EVENT_INDEX_NONE = 0,
    EVENT_INDEX_FIRST_INVADERS,
    EVENT_INDEX_LADY_NAZJAR_GAUNTLET,
    EVENT_INDEX_DEFENSE_SYSTEM_ACTIVATED,
    EVENT_INDEX_ULTHOK_ARRIVED
};

Position const TotTFirstInvaderPositions[] =
{
    { -409.0035f, 839.2552f, 262.0498f, 5.119945f }, // Naz'jar Spiritmender
    { -396.9653f, 779.9288f, 265.7069f, 1.55391f  }, // Naz'jar Spiritmender
    { -421.6042f, 839.7882f, 263.3889f, 4.842506f }, // Naz'jar Invader
    { -411.3646f, 778.8055f, 262.9503f, 1.528872f }  // Naz'Jar Invader
};

Position const TotTFirstInvaderInitialMovePositions[] =
{
    { -400.842f, 820.351f, 263.69f  },
    { -396.74f,  793.269f, 260.422f },
    { -418.925f, 819.314f, 261.505f },
    { -410.885f, 790.238f, 261.178f }
};

Position const TotTFirstInvaderJumpPositions[] =
{
    { -410.087f, 807.931f, 248.335f, 3.106686f },
    { -409.13f,  802.774f, 248.357f, 3.106686f },
    { -414.969f, 810.604f, 248.433f, 3.106686f },
    { -413.5f,   798.38f,  248.561f, 3.106686f }
};

template <class AI, class T>
inline AI* GetThroneOfTheTodesAI(T* obj)
{
    return GetInstanceAI<AI>(obj, TotTScriptName);
}

#define RegisterThroneOfTheTidesCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetThroneOfTheTodesAI)

#endif // THRONEOFTHETIDES_H_
