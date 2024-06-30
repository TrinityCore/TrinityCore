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

#ifndef _Waycrest_Manor_h__
#define _Waycrest_Manor_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "WM";
constexpr char const* WaycrestManorScriptName = "instance_waycrest_manor";

constexpr uint32 const EncounterCount = 5;

enum WaycrestManorDataTypes
{
    // Encounters
    DATA_HEARTSBANE_TRIAD       = 0,
    DATA_SOULBOUND_GOLIATH      = 1,
    DATA_RAAL_THE_GLUTTONOUS    = 2,
    DATA_LORD_AND_LADY_WAYCREST = 3,
    DATA_GORAK_TUL              = 4,

    DATA_SISTER_BRIAR,
    DATA_SISTER_MALADY,
    DATA_SISTER_SOLENA
};

enum WaycrestManorCreatureIds
{
    // Bosses
    BOSS_SISTER_BRIAR        = 131825,
    BOSS_SISTER_MALADY       = 131823,
    BOSS_SISTER_SOLENA       = 131824,
    BOSS_SOULBOUND_GOLIATH   = 131667,
    BOSS_RAAL_THE_GLUTTONOUS = 131863,
    BOSS_LADY_WAYCREST       = 136918,
    BOSS_LORD_WAYCREST       = 131527,
    BOSS_GORAK_TUL           = 131863,

    NPC_FOCUSING_IRIS        = 132361
};

enum WaycrestManorGameObjectIds
{
    GO_HEARTSBANE_TRIAD_DOOR = 282410
};

template <class AI, class T>
inline AI* GetWaycrestManorAI(T* obj)
{
    return GetInstanceAI<AI>(obj, WaycrestManorScriptName);
}

#define RegisterWaycrestManorCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetWaycrestManorAI)

#endif // _Waycrest_Manor_h__
