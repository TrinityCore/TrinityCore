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

#ifndef DEF_ULDAMAN_H
#define DEF_ULDAMAN_H

#include "CreatureAIImpl.h"

#define UldamanScriptName "instance_uldaman"
#define DataHeader "UD"

uint32 constexpr EncounterCount = 3;

enum UDDataTypes
{
    DATA_IRONAYA                        = 0,
    DATA_STONE_KEEPERS                  = 1,
    DATA_ARCHAEDAS                      = 2,

    DATA_IRONAYA_INTRO,
    DATA_IRONAYA_SEAL_DOOR
};

enum UDCreatureIds
{
    NPC_ARCHAEDAS                       = 2748,
    NPC_STONE_KEEPER                    = 4857,
    NPC_EARTHEN_GUARDIAN                = 7076,
    NPC_EARTHEN_HALLSHAPER              = 7077,
    NPC_EARTHEN_CUSTODIAN               = 7309,
    NPC_VAULT_WARDER                    = 10120
};

enum UDGameObjectIds
{
    GO_IRONAYA_SEAL_DOOR                = 124372,
    GO_KEYSTONE                         = 124371,
    GO_TEMPLE_DOOR_TO_KEEPERS           = 124368,
    GO_TEMPLE_DOOR_TO_ARCHAEDAS         = 124367,
    GO_TEMPLE_DOOR_ARCHAEDAS            = 141869,
    GO_ANCIENT_VAULT_DOOR               = 124369
};

enum UDSpawnGroups
{
    SPAWN_GROUP_IRONAYA                 = 334
};

enum UDActions
{
    ACTION_KEEPER_ACTIVATED             = 0,
    ACTION_ARCHAEDAS_AWAKEN             = 1
};

enum UDGameEvents
{
    EVENT_SUB_BOSS_AGGRO                = 2228,
    EVENT_BOSS_AGGRO                    = 2268
};

template <class AI, class T>
inline AI* GetUldamanAI(T* obj)
{
    return GetInstanceAI<AI>(obj, UldamanScriptName);
}

#define RegisterUldamanCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetUldamanAI)
#define RegisterUldamanGameObjectAI(ai_name) RegisterGameObjectAIWithFactory(ai_name, GetUldamanAI)

#endif
