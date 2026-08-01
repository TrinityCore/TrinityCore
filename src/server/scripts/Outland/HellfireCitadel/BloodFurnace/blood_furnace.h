/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef BLOOD_FURNACE_H_
#define BLOOD_FURNACE_H_

#include "CreatureAIImpl.h"

#define BFScriptName "instance_blood_furnace"
#define DataHeader   "BF"

uint32 constexpr EncounterCount = 3;

enum BFDataTypes
{
    // Encounter States/Boss GUIDs
    DATA_THE_MAKER              = 0,
    DATA_BROGGOK                = 1,
    DATA_KELIDAN                = 2,

    // Additional Data
    DATA_PRISONERS_EVENT,
    DATA_PRISON_DOOR_04,
    DATA_PRISON_DOOR_05,
    DATA_BROGGOK_LEVER,
    DATA_PRISON_CELL_DOOR_5,
    DATA_PRISON_CELL_DOOR_6,
    DATA_PRISON_CELL_DOOR_7,
    DATA_PRISON_CELL_DOOR_8
};

enum BFCreatureIds
{
    NPC_THE_MAKER               = 17381,
    NPC_BROGGOK                 = 17380,
    NPC_KELIDAN                 = 17377
};

enum BFGameObjectIds
{
    GO_PRISON_DOOR_01           = 181766, // Final Exit Door
    GO_PRISON_DOOR_02           = 181811, // The Maker Front Door
    GO_PRISON_DOOR_03           = 181812, // The Maker Rear Door
    GO_PRISON_DOOR_04           = 181819, // Broggok Rear Door
    GO_PRISON_DOOR_05           = 181822, // Broggok Front Door
    GO_SUMMON_DOOR              = 181823, // Kelidan Exit Door

    GO_PRISON_CELL_DOOR_1       = 181813, // The Maker
    GO_PRISON_CELL_DOOR_2       = 181814,
    GO_PRISON_CELL_DOOR_3       = 181816,
    GO_PRISON_CELL_DOOR_4       = 181815,
    GO_PRISON_CELL_DOOR_5       = 181817, // Broggok
    GO_PRISON_CELL_DOOR_6       = 181818,
    GO_PRISON_CELL_DOOR_7       = 181820,
    GO_PRISON_CELL_DOOR_8       = 181821,

    GO_BROGGOK_LEVER            = 181982
};

enum BFActionIds
{
    ACTION_PERFORM_INTRO        = 1738000,
    ACTION_RELEASE_BROGGOK      = 1738001,
    ACTION_DESPAWN_TRIGGER      = 1738002
};

enum BFSpawnGroupIds
{
    SPAWN_GROUP_PRISONERS_1     = 402,
    SPAWN_GROUP_PRISONERS_2     = 403,
    SPAWN_GROUP_PRISONERS_3     = 404,
    SPAWN_GROUP_PRISONERS_4     = 405
};

template <class AI, class T>
inline AI* GetBloodFurnaceAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BFScriptName);
}

#define RegisterBloodFurnaceCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetBloodFurnaceAI)
#define RegisterBloodFurnaceGameObjectAI(ai_name) RegisterGameObjectAIWithFactory(ai_name, GetBloodFurnaceAI)

#endif // BLOOD_FURNACE_H_
