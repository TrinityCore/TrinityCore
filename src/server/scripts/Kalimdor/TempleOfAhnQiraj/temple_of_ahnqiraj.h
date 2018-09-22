/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef DEF_TEMPLE_OF_AHNQIRAJ_H
#define DEF_TEMPLE_OF_AHNQIRAJ_H

#include "CreatureAIImpl.h"

#define AQ40ScriptName "instance_temple_of_ahnqiraj"
#define DataHeader "AQT"

enum AQTDataTypes
{
    DATA_SKERAM             = 1,
    DATA_KRI                = 2,
    DATA_VEM                = 3,
    DATA_VEMISDEAD          = 4,
    DATA_VEM_DEATH          = 5,
    DATA_VEKLOR             = 6,
    DATA_VEKLORISDEAD       = 7,
    DATA_VEKLOR_DEATH       = 8,
    DATA_VEKNILASH          = 9,
    DATA_VEKNILASHISDEAD    = 10,
    DATA_VEKNILASH_DEATH    = 11,
    DATA_BUG_TRIO_DEATH     = 14,
    DATA_CTHUN_PHASE        = 20,
    DATA_VISCIDUS           = 21,
    DATA_SARTURA            = 22
};

enum AQTCreatures
{
    BOSS_EYE_OF_CTHUN       = 15589,
    NPC_CTHUN_PORTAL        = 15896,
    NPC_CLAW_TENTACLE       = 15725,
    NPC_EYE_TENTACLE        = 15726,
    NPC_SMALL_PORTAL        = 15904,
    NPC_BODY_OF_CTHUN       = 15809,
    NPC_GIANT_CLAW_TENTACLE = 15728,
    NPC_GIANT_EYE_TENTACLE  = 15334,
    NPC_FLESH_TENTACLE      = 15802,
    NPC_GIANT_PORTAL        = 15910,

    NPC_VISCIDUS            = 15299,
    NPC_GLOB_OF_VISCIDUS    = 15667,

    NPC_SKERAM              = 15263,
    NPC_VEM                 = 15544,
    NPC_KRI                 = 15511,
    NPC_VEKLOR              = 15276,
    NPC_VEKNILASH           = 15275,
    NPC_SARTURA             = 15516
};

template <class AI, class T>
inline AI* GetAQ40AI(T* obj)
{
    return GetInstanceAI<AI>(obj, AQ40ScriptName);
}

#endif
