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

#ifndef BLACKROCKCAVERNS_H_
#define BLACKROCKCAVERNS_H_

#include "CreatureAIImpl.h"
#include "Position.h"

#define BCScriptName "instance_blackrock_caverns"
#define DataHeader "BRC"

uint32 const EncounterCount             = 5;

enum BRCDataTypes
{
    // Encounters
    DATA_ROMOGG_BONECRUSHER         = 0,
    DATA_CORLA_HERALD_OF_TWILIGHT   = 1,
    DATA_KARSH_STEELBENDER          = 2,
    DATA_BEAUTY                     = 3,
    DATA_ASCENDANT_LORD_OBSIDIUS    = 4,

    // Additional Data
    DATA_RAZ_THE_CRAZED             = 5,
    DATA_RAZ_LAST_AREA_INDEX        = 6
};

enum BRCCreatureIds
{
    // Bosses
    BOSS_ROMOGG_BONECRUSHER             = 39665,
    BOSS_CORLA_HERALD_OF_TWILIGHT       = 39679,
    BOSS_KARSH_STEELBENDER              = 39698,
    BOSS_BEAUTY                         = 39700,
    BOSS_ASCENDANT_LORD_OBSIDIUS        = 39705,

    // Encounter Related
    /*Rom'ogg Bonecrusher*/
    NPC_CHAINS_OF_WOE                   = 40447,
    NPC_ANGERED_EARTH                   = 50376,
    NPC_QUAKE                           = 40401,

    /*Corla, Herald of Twilight*/
    NPC_TWILIGHT_ZEALOT                 = 50284,
    NPC_EVOLVED_TWILIGHT_ZEALOT         = 39987,

    /*Karsh Steelbender*/
    NPC_INVISIBLE_STALKER               = 39842,
    NPC_BOUND_FLAMES                    = 50417,

    /*Beauty*/
    NPC_LUCKY                           = 40008,
    NPC_SPOT                            = 40011,
    NPC_BUSTER                          = 40013,
    NPC_RUNTY                           = 40015,

    /*Ascendant Lord Obsidius*/
    NPC_SHADOW_OF_OBSIDIUS              = 40817,

    // Generic Creatures
    NPC_TWILIGHT_FLAME_CALLER           = 39708,
    NPC_RAZ_THE_CRAZED                  = 39670,
    NPC_TWILIGHT_PORTAL                 = 51340
};

enum BRCActions
{
    ACTION_BREAK_OUT_OF_PRISON = 0
};

enum BRCRazAreaIndex
{
    RAZ_AREA_INDEX_ROMOGG   = 0,
    RAZ_AREA_INDEX_CORLA    = 1,
    RAZ_AREA_INDEX_OBSIDIUS = 2
};

Position const RazTheCrazedSummonPositions[] =
{
    { 249.2639f, 949.1614f, 191.7866f, 3.141593f },
    { 406.1927f, 906.0121f, 163.4926f, 4.310963f },
    { 308.9653f, 635.8195f, 64.79769f, 4.555309f }
};

template <class AI, class T>
inline AI* GetBlackrockCavernsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BCScriptName);
}

#define RegisterBlackrockCavernsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetBlackrockCavernsAI)

#endif // BLACKROCKCAVERNS_H_
