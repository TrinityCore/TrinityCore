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

#ifndef DEF_ECODOME_ALDANI_H_
#define DEF_ECODOME_ALDANI_H_

#include "CreatureAIImpl.h"

#define EAScriptName "instance_ecodome_aldani"
#define DataHeader "EcodomeAldani"

uint32 const EncounterCount = 3;

enum EcodomeAldaniDataTypes
{
    // Encounters
    DATA_AZHICCAR          = 0,
    DATA_TAAHBAT_AND_AWAZJ = 1,
    DATA_SOUL_SCRIBE       = 2,

    DATA_TAAHBAT,
    DATA_AWAZJ,

    DATA_AZHICCAR_INTRO
};

enum EcodomeAldaniCreatureIds
{
    // Bosses
    BOSS_AZHICCAR    = 234893,
    BOSS_TAAHBAT     = 234933,
    BOSS_AWAZJ       = 241375,
    BOSS_SOUL_SCRIBE = 247283
};

template <class AI, class T>
inline AI* GetEcodomeAldaniAI(T* obj)
{
    return GetInstanceAI<AI>(obj, EAScriptName);
}

#define RegisterEcodomeAldaniCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetEcodomeAldaniAI)

#endif
