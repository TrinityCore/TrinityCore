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

#ifndef DEF_BLACK_ROOK_HOLD_H_
#define DEF_BLACK_ROOK_HOLD_H_

#include "CreatureAIImpl.h"

#define DataHeader "BlackRookHold"
#define BRHScriptName "instance_black_rook_hold"

constexpr uint32 EncounterCount = 4;

enum BRHDataTypes : uint8
{
    // Encounters
    DATA_AMALGAM_OF_SOULS = 0,
    DATA_ILLYSANNA_RAVENCREST,
    DATA_SMASHPITE_THE_HATEFUL,
    DATA_LORD_KURTALOS_RAVENCREST,

    DATA_BOSS_1_POST_BOSS_DOOR
};

enum BRHCreatureIds
{
    // Bosses
    BOSS_AMALGAM_OF_SOULS         = 98542,
    BOSS_ILLYSANNA_RAVENCREST     = 98696,
    BOSS_SMASHPITE_THE_HATEFUL    = 98949,
    BOSS_LORD_KURTALOS_RAVENCREST = 94923
};

enum BRHGameObjects
{
    GO_BOSS_1_DOOR_1         = 247403,
    GO_BOSS_1_DOOR_2         = 247404,
    GO_BOSS_1_DOOR_3         = 247405,
    GO_BOSS_1_DOOR_4         = 247406,
    GO_BOSS_1_POST_BOSS_DOOR = 247407
};

template <class AI, class T>
inline AI* GetBlackRookHoldAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BRHScriptName);
}

#define RegisterBlackRookHoldCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetBlackRookHoldAI)

#endif
