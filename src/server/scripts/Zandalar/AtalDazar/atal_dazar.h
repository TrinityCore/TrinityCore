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

#ifndef DEF_ATAL_DAZAR_H_
#define DEF_ATAL_DAZAR_H_

#include "CreatureAIImpl.h"

#define DataHeader "AtalDazar"
#define AtalDazarScriptName "instance_atal_dazar"

uint32 const EncounterCount = 4;

enum AtalDazarDataTypes
{
    // Encounters
    DATA_PRIESTESS_ALUNZA = 0,
    DATA_VOLKAAL          = 1,
    DATA_REZAN            = 2,
    DATA_YAZMA            = 3
};

enum AtalDazarCreatureIds
{
    // Bosses
    BOSS_PRIESTESS_ALUNZA = 129614,
    BOSS_VOLKAAL          = 129399,
    BOSS_REZAN            = 122963,
    BOSS_YAZMA            = 129412
};

template <class AI, class T>
inline AI* GetAtalDazarAI(T* obj)
{
    return GetInstanceAI<AI>(obj, AtalDazarScriptName);
}

#define RegisterAtalDazarCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetAtalDazarAI)

#endif
