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

#ifndef DEF_DARKFLAME_CLEFT_H_
#define DEF_DARKFLAME_CLEFT_H_

#include "CreatureAIImpl.h"

#define DCScriptName "instance_darkflame_cleft"
#define DataHeader "DarkflameCleft"

uint32 const EncounterCount = 4;

enum DarkflameCleftDataTypes
{
    // Encounters
    DATA_OL_WAXBEARD     = 0,
    DATA_BLAZIKON        = 1,
    DATA_THE_CANDLE_KING = 2,
    DATA_THE_DARKNESS    = 3
};

enum DarkflameCleftCreatureIds
{
    // Bosses
    BOSS_OL_WAXBEARD     = 210149,
    BOSS_BLAZIKON        = 208743,
    BOSS_THE_CANDLE_KING = 208745,
    BOSS_THE_DARKNESS    = 210797
};

template <class AI, class T>
inline AI* GetDarkflameCleftAI(T* obj)
{
    return GetInstanceAI<AI>(obj, DCScriptName);
}

#define RegisterDarkflameCleftCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetDarkflameCleftAI)

#endif
