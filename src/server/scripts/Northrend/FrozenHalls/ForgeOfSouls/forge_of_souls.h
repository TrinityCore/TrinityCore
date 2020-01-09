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

#ifndef FORGE_OF_SOULS_H_
#define FORGE_OF_SOULS_H_

#include "CreatureAIImpl.h"

#define FoSScriptName "instance_forge_of_souls"
#define DataHeader    "FOS"

uint32 const EncounterCount = 2;

enum FOSData
{
    // Encounter states and GUIDs
    DATA_BRONJAHM                   = 0,
    DATA_DEVOURER_OF_SOULS          = 1,

    // Additional Data
    DATA_TEAM_IN_INSTANCE           = 2
};

enum FOSCreatures
{
    NPC_BRONJAHM                    = 36497,
    NPC_DEVOURER                    = 36502,
    NPC_CORRUPTED_SOUL_FRAGMENT     = 36535,

    NPC_SYLVANAS_PART1              = 37596,
    NPC_SYLVANAS_PART2              = 38161,
    NPC_JAINA_PART1                 = 37597,
    NPC_JAINA_PART2                 = 38160,
    NPC_KALIRA                      = 37583,
    NPC_ELANDRA                     = 37774,
    NPC_LORALEN                     = 37779,
    NPC_KORELN                      = 37582,
    NPC_CHAMPION_1_HORDE            = 37584,
    NPC_CHAMPION_2_HORDE            = 37587,
    NPC_CHAMPION_3_HORDE            = 37588,
    NPC_CHAMPION_1_ALLIANCE         = 37496,
    NPC_CHAMPION_2_ALLIANCE         = 37497,
    NPC_CRUCIBLE_OF_SOULS           = 37094
};

template <class AI, class T>
inline AI* GetForgeOfSoulsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, FoSScriptName);
}

#endif // FORGE_OF_SOULS_H_
