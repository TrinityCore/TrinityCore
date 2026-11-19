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

#ifndef DEF_AZURE_VAULT_H_
#define DEF_AZURE_VAULT_H_

#include "CreatureAIImpl.h"

#define DataHeader "TrialOfValor"
#define TOVScriptName "instance_trial_of_valor"

uint32 const EncounterCount = 3;

enum TOVDataTypes
{
    // Encounters
    DATA_ODYN                       = 0,
    DATA_GUARM,
    DATA_HELYA,
};

enum TOVCreatureIds
{
    // Bosses
    BOSS_ODYN                       = 114263,
    BOSS_GUARM                      = 114323,
    BOSS_HELYA                      = 114537,
};

enum TOVGameObjectIds
{
    GO_GUARM_BOSS_DOOR_ENTRANCE     = 266532,
    GO_GUARM_BOSS_DOOR_EXIT         = 266533,
};

template <class AI, class T>
inline AI* GetTrialOfValorAI(T* obj)
{
    return GetInstanceAI<AI>(obj, TOVScriptName);
}

#define RegisterTrialOfValorCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetTrialOfValorAI)

#endif
