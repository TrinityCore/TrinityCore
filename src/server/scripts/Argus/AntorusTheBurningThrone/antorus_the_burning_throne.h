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

#ifndef DEF_ANTORUS_THE_BURNING_THRONE_H_
#define DEF_ANTORUS_THE_BURNING_THRONE_H_

#include "CreatureAIImpl.h"

#define DataHeader "ABT"
#define ABTScriptName "instance_antorus_the_burning_throne"

uint32 const EncounterCount = 10;

enum AntorusDataTypes
{
    // Encounters
    DATA_GAROTHI_WORLDBREAKER   = 0,
    DATA_FELHOUNDS_OF_SAGERAS   = 1,
    DATA_ANTORAN_HIGH_COMMAND   = 2,
    DATA_PORTAL_KEEPER_HASABEL  = 3,
    DATA_EONAR_THE_LIFE_BINDER  = 4,
    DATA_IMONAR_THE_SOULHUNTER  = 5,
    DATA_KINGAROTH              = 6,
    DATA_VARIMATHRAS            = 7,
    DATA_THE_COVEN_OF_SHIVARRA  = 8,
    DATA_AGGRAMAR               = 9,
    DATA_ARGUS_THE_UNMAKER      = 10,

    // Encounter related data
    DATA_DECIMATOR,
    DATA_ANNIHILATOR
};

enum AntorusCreatureIds
{
    // Bosses
    BOSS_GAROTHI_WORLDBREAKER   = 122450,

    // Encounter related creatures
    /*Garothi Worldbreaker*/
    NPC_DECIMATOR               = 122773,
    NPC_ANNIHILATOR             = 122778,
    NPC_ANNIHILATION            = 122818,
    NPC_GAROTHI_WORLDBREAKER    = 124167
};

enum AntorusGameObjectIds
{
    GO_COLLISION    = 277365,
    GO_ROCK         = 278488
};

template <class AI, class T>
inline AI* GetAntorusTheBurningThroneAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ABTScriptName);
}

#define RegisterAntorusTheBurningThroneCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetAntorusTheBurningThroneAI)

#endif
