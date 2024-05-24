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

#ifndef DEF_MAW_OF_SOULS_H_
#define DEF_MAW_OF_SOULS_H_

#include "CreatureAIImpl.h"

#define DataHeader "MawOfSouls"
#define MOSScriptName "instance_maw_of_souls"

uint32 const EncounterCount = 3;

enum MOSDataTypes
{
    // Encounters
    DATA_YMIRON                     = 0,
    DATA_HARBARON,
    DATA_HELYA,
};

enum MOSCreatureIds
{
    // Bosses
    BOSS_YMIRON                     = 96756,
    BOSS_HARBARON                   = 96754,
    BOSS_HELYA                      = 96759,
};

template <class AI, class T>
inline AI* GetMawOfSoulsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, MOSScriptName);
}

#define RegisterMawOfSoulsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetMawOfSoulsAI)

#endif
