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

#ifndef BLACKROCKCAVERNS_H_
#define BLACKROCKCAVERNS_H_

#include "CreatureAIImpl.h"

#define BCScriptName "instance_blackrock_caverns"
#define DataHeader "BRC"

uint32 const EncounterCount             = 5;

enum BRCDataTypes
{
    // Encounter States // Boss GUIDs
    DATA_ROMOGG_BONECRUSHER             = 0,
    DATA_CORLA_HERALD_OF_TWILIGHT       = 1,
    DATA_KARSH_STEELBENDER              = 2,
    DATA_BEAUTY                         = 3,
    DATA_ASCENDANT_LORD_OBSIDIUS        = 4,

    // Additional Objects
    DATA_RAZ_THE_CRAZED                 = 5
};

enum BRCCreatureIds
{
    // Bosses
    BOSS_ROMOGG_BONECRUSHER             = 39665,
    BOSS_CORLA_HERALD_OF_TWILIGHT       = 39679,
    BOSS_KARSH_STEELBENDER              = 39698,

    // Encounter Related
    /*Rom'ogg Bonecrusher*/
    NPC_CHAINS_OF_WOE                   = 40447,
    NPC_ANGERED_EARTH                   = 50376,
    NPC_QUAKE                           = 40401,

    /*Corla, Herald of Twilight*/
    NPC_TWILIGHT_ZEALOT                 = 50284,
    NPC_EVOLVED_TWILIGHT_ZEALOT         = 39987,

    NPC_TWILIGHT_FLAME_CALLER           = 39708,
    NPC_RAZ_THE_CRAZED                  = 39670,

    /*Karsh Steelbender*/
    NPC_INVISIBLE_STALKER               = 39842,
    NPC_BOUND_FLAMES                    = 50417,
};

template <class AI, class T>
inline AI* GetBlackrockCavernsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BCScriptName);
}

#define RegisterBlackrockCavernsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetBlackrockCavernsAI)

#endif // BLACKROCKCAVERNS_H_
