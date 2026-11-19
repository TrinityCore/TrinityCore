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

#ifndef SCARLET_M_
#define SCARLET_M_

#include "CreatureAIImpl.h"
#include "Position.h"

#define SMScriptName "instance_scarlet_monastery"
#define DataHeader "SM"

uint32 const EncounterCount = 9;

extern Position const BunnySpawnPosition;
extern Position const EarthBunnySpawnPosition;
extern Position const HeadlessHorsemanSpawnPosition;
extern Position const HeadlessHorsemanHeadSpawnPosition;

enum SMDataTypes
{
    DATA_INTERROGATOR_VISHAS = 0,
    DATA_BLOODMAGE_THALNOS,
    DATA_HOUNDMASTER_LOKSEY,
    DATA_ARCANIST_DOAN,
    DATA_HEROD,
    DATA_HIGH_INQUISITOR_FAIRBANKS,
    DATA_MOGRAINE_AND_WHITE_EVENT, // Last DungeonEncounter.dbc entry

    DATA_AZSHIR,
    DATA_SCORN,
    DATA_MOGRAINE,
    DATA_VORREL,
    DATA_WHITEMANE,

    // Headless Horseman
    DATA_HORSEMAN_HEAD,
    DATA_HEADLESS_HORSEMAN,
    DATA_PUMPKIN_SHRINE,
    DATA_HIGH_INQUISITORS_DOOR,
    DATA_LOOSELY_TURNED_SOIL,
    DATA_START_HORSEMAN_EVENT,
    DATA_FLAME_BUNNY,
    DATA_EARTH_BUNNY,
    DATA_HORSEMAN_EVENT_STATE,
    DATA_PREPARE_RESET,
    DATA_THOMAS
};

enum SMCreatureIds
{
    NPC_MOGRAINE               = 3976,
    NPC_WHITEMANE              = 3977,
    NPC_VORREL                 = 3981,
    NPC_HEADLESS_HORSEMAN      = 23682,
    NPC_HEADLESS_HORSEMAN_HEAD = 23775,
    NPC_PULSING_PUMPKIN        = 23694,
    NPC_PUMPKIN_FIEND          = 23545,
    NPC_FLAME_BUNNY            = 23686,
    NPC_EARTH_BUNNY            = 23758,
    NPC_SIR_THOMAS             = 23904
};

enum SMCreatureMisc
{
    SPELL_EARTH_EXPLOSION         = 42373,
    EVENT_ACTIVE_EARTH_EXPLOSION  = 1,
    EVENT_SPAWN_HEADLESS_HORSEMAN = 2,
    EVENT_DESPAWN_OBJECTS         = 3,
    ACTION_HORSEMAN_EVENT_START   = 101
};

enum SMGameObjectIds
{
    GO_HIGH_INQUISITORS_DOOR = 104600,
    GO_PUMPKIN_SHRINE        = 186267,
    GO_LOOSELY_TURNED_SOIL   = 186314
};

template <class AI, class T>
inline AI* GetScarletMonasteryAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SMScriptName);
}

#define RegisterScarletMonasteryCreatureAI(ai) RegisterCreatureAIWithFactory(ai, GetScarletMonasteryAI)
#define RegisterScarletMonasteryGameObjectAI(ai) RegisterGameObjectAIWithFactory(ai, GetScarletMonasteryAI)

#endif // SCARLET_M_
