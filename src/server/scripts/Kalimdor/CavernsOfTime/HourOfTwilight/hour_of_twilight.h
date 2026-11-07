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

#ifndef _Hour_of_Twilight_h__
#define _Hour_of_Twilight_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "HOT";
constexpr char const* HoTScriptName = "instance_hour_of_twilight";

constexpr uint32 const EncounterCount = 3;

enum TotFWDataTypes
{
    // Encounters
    BOSS_ARCURION               = 0,
    BOSS_ASIRA_DAWNSLAYER       = 1,
    BOSS_ARCHBISHOP_BENEDICTUS  = 2
};

template <class AI, class T>
inline AI* GetGetHourOfTwilightAI(T* obj)
{
    return GetInstanceAI<AI>(obj, HoTScriptName);
}

#define RegisterHourOfTwilightAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetGetHourOfTwilightAI)

#endif // _Hour_of_Twilight_h__
