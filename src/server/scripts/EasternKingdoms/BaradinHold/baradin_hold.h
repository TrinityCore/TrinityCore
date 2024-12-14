/*
* This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
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

#ifndef DEF_BARADIN_HOLD_H_
#define DEF_BARADIN_HOLD_H_

#include "CreatureAIImpl.h"

#define DataHeader "BH"
#define BHScriptName "instance_baradin_hold"

uint32 const EncounterCount = 3;

enum BHDataTypes
{
    // Encounters
    BOSS_ARGALOTH   = 0,
    BOSS_OCCUTHAR   = 1,
    BOSS_ALIZABAL   = 2,

    // Encounter Related
    DATA_EXTINUISH_FEL_FLAMES
};

enum BHCreatureIds
{
    // Bosses
    NPC_ARGALOTH            = 47120,
    NPC_OCCUTHAR            = 52363,
    NPC_ALIZABAL            = 55869,

    // Encounter Related Creatures
    /*Argaloth*/
    NPC_FEL_FLAMES          = 47829,

    NPC_EYE_OF_OCCUTHAR     = 52389,
    NPC_FOCUS_FIRE_DUMMY    = 52369,
    NPC_OCCUTHAR_EYE        = 52368
};

enum BHGameObjectIds
{
    GO_ARGALOTH_DOOR        = 207619,
    GO_OCCUTHAR_DOOR        = 208953,
    GO_ALIZABAL_DOOR        = 209849
};

enum BHSpells
{
    // Fel Flames
    SPELL_FEL_FLAMES = 88999
};

template<class AI, class T>
inline AI* GetBaradinHoldAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BHScriptName);
}

#define RegisterBaradinHoldCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetBaradinHoldAI)

#endif
