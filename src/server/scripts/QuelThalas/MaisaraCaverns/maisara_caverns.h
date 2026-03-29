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

#ifndef DEF_MAISARA_CAVERNS_H_
#define DEF_MAISARA_CAVERNS_H_

#include "CreatureAIImpl.h"

#define MCScriptName "instance_maisara_caverns"
#define DataHeader "MaisaraCaverns"

uint32 const EncounterCount = 3;

enum MaisaraCavernsDataTypes
{
    // Encounters
    DATA_MUROJIN_AND_NEKRAXX    = 0,
    DATA_VORDAZA                = 1,
    DATA_RAKTUL_VESSEL_OF_SOULS = 2,

    DATA_MUROJIN_AND_NEKRAXX_INTRO_STATE,
    DATA_MUROJIN,
    DATA_NEKRAXX
};

enum MaisaraCavernsCreatureIds
{
    // Bosses
    BOSS_MUROJIN                = 247570,
    BOSS_NEKRAXX                = 247572,
    BOSS_VORDAZA                = 248595,
    BOSS_RAKTUL_VESSEL_OF_SOULS = 248605
};

enum MaisaraCavernsActions
{
    ACTION_NEKRAXX_INTRO        = 1
};

template <class AI, class T>
inline AI* GetMaisaraCavernsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, MCScriptName);
}

#define RegisterMaisaraCavernsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetMaisaraCavernsAI)

#endif
