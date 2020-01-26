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

#ifndef DEF_MAGISTERS_TERRACE_H
#define DEF_MAGISTERS_TERRACE_H

#include "CreatureAIImpl.h"

#define MGTScriptName "instance_magisters_terrace"
#define DataHeader "MT"

uint32 const EncounterCount = 4;

enum MTDataTypes
{
    DATA_SELIN,
    DATA_VEXALLUS,
    DATA_DELRISSA,
    DATA_KAELTHAS,

    DATA_KAEL_STATUE_LEFT,
    DATA_KAEL_STATUE_RIGHT,

    DATA_DELRISSA_DEATH_COUNT,
    DATA_KAELTHAS_STATUES,
    DATA_ESCAPE_ORB
};

enum MTCreatureIds
{
    NPC_SELIN               = 24723,
    NPC_DELRISSA            = 24560,
    NPC_FEL_CRYSTAL         = 24722,
    NPC_KALECGOS            = 24844,
    NPC_HUMAN_KALECGOS      = 24848
};

enum MTGameObjectIds
{
    GO_VEXALLUS_DOOR        = 187896,
    GO_SELIN_DOOR           = 187979,
    GO_SELIN_ENCOUNTER_DOOR = 188065,
    GO_DELRISSA_DOOR        = 187770,
    GO_KAEL_DOOR            = 188064,
    GO_KAEL_STATUE_1        = 188165,
    GO_KAEL_STATUE_2        = 188166,
    GO_ESCAPE_ORB           = 188173
};

enum MTInstanceEventIds
{
    EVENT_SPAWN_KALECGOS    = 16547
};

enum MTInstanceText
{
    SAY_KALECGOS_SPAWN      = 0
};

enum MTMovementData
{
    PATH_KALECGOS_FLIGHT    = 248440
};

template<typename AI>
inline AI* GetMagistersTerraceAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, MGTScriptName);
}

#endif
