/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_PIT_OF_SARON_H
#define DEF_PIT_OF_SARON_H

#include "Map.h"
#include "Creature.h"

#define PoSScriptName "instance_pit_of_saron"
#define MAX_ENCOUNTER 3

enum DataTypes
{
    // Encounter states and GUIDs
    DATA_GARFROST           = 0,
    DATA_ICK                = 1,
    DATA_TYRANNUS           = 2,

    // GUIDs
    DATA_RIMEFANG           = 3,
    DATA_KRICK              = 4,
    DATA_JAINA_SYLVANAS_1   = 5,    // GUID of either Jaina or Sylvanas part 1, depending on team, as it's the same spawn.
    DATA_JAINA_SYLVANAS_2   = 6,    // GUID of either Jaina or Sylvanas part 2, depending on team, as it's the same spawn.
    DATA_TYRANNUS_EVENT     = 7,
    DATA_TEAM_IN_INSTANCE   = 8,
};

enum CreatureIds
{
    NPC_GARFROST                                = 36494,
    NPC_KRICK                                   = 36477,
    NPC_ICK                                     = 36476,
    NPC_TYRANNUS                                = 36658,
    NPC_RIMEFANG                                = 36661,

    NPC_TYRANNUS_EVENTS                         = 36794,
    NPC_SYLVANAS_PART1                          = 36990,
    NPC_SYLVANAS_PART2                          = 38189,
    NPC_JAINA_PART1                             = 36993,
    NPC_JAINA_PART2                             = 38188,
    NPC_KILARA                                  = 37583,
    NPC_ELANDRA                                 = 37774,
    NPC_KORALEN                                 = 37779,
    NPC_KORLAEN                                 = 37582,
    NPC_CHAMPION_1_HORDE                        = 37584,
    NPC_CHAMPION_2_HORDE                        = 37587,
    NPC_CHAMPION_3_HORDE                        = 37588,
    NPC_CHAMPION_1_ALLIANCE                     = 37496,
    NPC_CHAMPION_2_ALLIANCE                     = 37497,

    NPC_HORDE_SLAVE_1                           = 36770,
    NPC_HORDE_SLAVE_2                           = 36771,
    NPC_HORDE_SLAVE_3                           = 36772,
    NPC_HORDE_SLAVE_4                           = 36773,
    NPC_ALLIANCE_SLAVE_1                        = 36764,
    NPC_ALLIANCE_SLAVE_2                        = 36765,
    NPC_ALLIANCE_SLAVE_3                        = 36766,
    NPC_ALLIANCE_SLAVE_4                        = 36767,
    NPC_FREED_SLAVE_1_ALLIANCE                  = 37575,
    NPC_FREED_SLAVE_2_ALLIANCE                  = 37572,
    NPC_FREED_SLAVE_3_ALLIANCE                  = 37576,
    NPC_FREED_SLAVE_1_HORDE                     = 37579,
    NPC_FREED_SLAVE_2_HORDE                     = 37578,
    NPC_FREED_SLAVE_3_HORDE                     = 37577,
    NPC_RESCUED_SLAVE_ALLIANCE                  = 36888,
    NPC_RESCUED_SLAVE_HORDE                     = 36889,
    NPC_MARTIN_VICTUS_1                         = 37591,
    NPC_MARTIN_VICTUS_2                         = 37580,
    NPC_GORKUN_IRONSKULL_1                      = 37581,
    NPC_GORKUN_IRONSKULL_2                      = 37592,

    NPC_FORGEMASTER_STALKER                     = 36495,
    NPC_EXPLODING_ORB                           = 36610,
    NPC_YMIRJAR_DEATHBRINGER                    = 36892,
    NPC_ICY_BLAST                               = 36731
};

enum GameObjectIds
{
    GO_SARONITE_ROCK                            = 196485,
    GO_ICE_WALL                                 = 201885,
    GO_HALLS_OF_REFLECTION_PORTCULLIS           = 201848,
};

template<class AI>
AI* GetPitOfSaronAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(PoSScriptName))
                return new AI(creature);
    return NULL;
}

#endif
