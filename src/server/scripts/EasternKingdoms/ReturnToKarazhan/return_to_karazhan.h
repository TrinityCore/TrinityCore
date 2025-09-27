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

#ifndef DEF_RETURN_TO_KARAZHAN_H_
#define DEF_RETURN_TO_KARAZHAN_H_

#include "CreatureAIImpl.h"

#define DataHeader "ReturnToKarazhan"
#define RTKScriptName "instance_return_to_karazhan"

constexpr uint32 EncounterCount = 9;

enum RTKDataTypes : uint8
{
    // Encounters
    DATA_OPERA_HALL = 0,
    DATA_MAIDEN_OF_VIRTUE_RTK,
    DATA_MOROES,
    DATA_ATTUMEN_THE_HUNTSMAN,
    DATA_THE_CURATOR_RTK,
    DATA_SHADE_OF_MEDIVH,
    DATA_MANA_DEVOURER,
    DATA_VIZADUUM_THE_WATCHER,
    DATA_NIGHTBANE
};

enum RTKCreatureIds
{
    // Bosses
    BOSS_MAIDEN_OF_VIRTUE_RTK = 113971,
    BOSS_THE_CURATOR_RTK      = 114247,
    BOSS_MANA_DEVOURER        = 114252
};

enum RTKGameObjectsIds
{
    GO_STRANGE_WALL        = 266508,
    GO_SUSPICIOUS_BOOKCASE = 266510,
    GO_MEDIVH_DOOR         = 266846
};

template <class AI, class T>
inline AI* GetReturnToKarazhanAI(T* obj)
{
    return GetInstanceAI<AI>(obj, RTKScriptName);
}

#define RegisterReturnToKarazhanCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetReturnToKarazhanAI)

#endif
