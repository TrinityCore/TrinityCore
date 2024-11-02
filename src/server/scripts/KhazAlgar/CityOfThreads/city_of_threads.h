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

#ifndef DEF_CITY_OF_THREADS_H_
#define DEF_CITY_OF_THREADS_H_

#include "CreatureAIImpl.h"

#define COTScriptName "instance_city_of_threads"
#define DataHeader "CityOfThreads"

uint32 const EncounterCount = 4;

enum CityOfThreadsDataTypes
{
    // Encounters
    DATA_ORATOR_KRIX_VIZK      = 0,
    DATA_FANGS_OF_THE_QUEEN    = 1,
    DATA_THE_COAGLAMATION      = 2,
    DATA_IZO_THE_GRAND_SPLICER = 3,

    // Additional Data
    DATA_ORATOR_CONVO
};

enum CityOfThreadsCreatureIds
{
    // Bosses
    BOSS_ORATOR_KRIX_VIZK      = 216619,
    BOSS_NX                    = 216648,
    BOSS_VX                    = 216649,
    BOSS_THE_COAGLAMATION      = 216320,
    BOSS_IZO_THE_GRAND_SPLICER = 216658,

    // Npcs
    NPC_ORATOR_KRIX_VIZK_CONVO = 220769
};

template <class AI, class T>
inline AI* GetCityOfThreadsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, COTScriptName);
}

#define RegisterCityOfThreadsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetCityOfThreadsAI)

#endif
