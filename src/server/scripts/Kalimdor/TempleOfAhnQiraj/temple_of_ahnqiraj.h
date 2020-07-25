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

#ifndef DEF_TEMPLE_OF_AHNQIRAJ_H
#define DEF_TEMPLE_OF_AHNQIRAJ_H

#include "CreatureAIImpl.h"

#define AQ40ScriptName "instance_temple_of_ahnqiraj"
#define DataHeader "AQT"

uint32 const EncounterCount = 9;

enum AQTDataTypes
{
    // Boss States
    DATA_SKERAM             = 0,
    DATA_SARTURA            = 1,
    DATA_FRANKRIS           = 2,
    DATA_HUHURAN            = 3,
    DATA_TWIN_EMPERORS      = 4,
    DATA_CTHUN              = 5,
    DATA_BUG_TRIO           = 6,
    DATA_VISCIDUS           = 7,
    DATA_OURO               = 8,

    // Others
    DATA_KRI                = 9,
    DATA_VEM                = 10,
    DATA_VEMISDEAD          = 11,
    DATA_VEM_DEATH          = 12,
    DATA_VEKLOR             = 13,
    DATA_VEKLORISDEAD       = 14,
    DATA_VEKLOR_DEATH       = 15,
    DATA_VEKNILASH          = 16,
    DATA_VEKNILASHISDEAD    = 17,
    DATA_VEKNILASH_DEATH    = 18,
    DATA_BUG_TRIO_DEATH     = 19,
    DATA_CTHUN_PHASE        = 20
};

enum AQTCreatures
{
    // Bosses
    BOSS_EYE_OF_CTHUN       = 15589,
    BOSS_SKERAM             = 15263,
    BOSS_VEM                = 15544,
    BOSS_KRI                = 15511,
    BOSS_VEKLOR             = 15276,
    BOSS_VEKNILASH          = 15275,
    BOSS_SARTURA            = 15516,
    BOSS_OURO               = 15517,
    BOSS_VISCIDUS           = 15299,

    // Encounter Related Creatures
    /*C'Thun*/
    NPC_CTHUN_PORTAL        = 15896,
    NPC_CLAW_TENTACLE       = 15725,
    NPC_EYE_TENTACLE        = 15726,
    NPC_SMALL_PORTAL        = 15904,
    NPC_BODY_OF_CTHUN       = 15809,
    NPC_GIANT_CLAW_TENTACLE = 15728,
    NPC_GIANT_EYE_TENTACLE  = 15334,
    NPC_FLESH_TENTACLE      = 15802,
    NPC_GIANT_PORTAL        = 15910,

    /*Viscidus*/
    NPC_GLOB_OF_VISCIDUS    = 15667
};

enum AQ40GameObjects
{
    AQ40_DOOR_1         = 180634,
    AQ40_DOOR_2         = 180635,
    AQ40_DOOR_3         = 180636,

    GO_SANDWORM_BASE    = 180795
};

template <class AI, class T>
inline AI* GetAQ40AI(T* obj)
{
    return GetInstanceAI<AI>(obj, AQ40ScriptName);
}

#define RegisterTempleOfAhnqirajhCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetAQ40AI)

#endif
