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

#ifndef DEF_MURDER_ROW_H_
#define DEF_MURDER_ROW_H_

#include "CreatureAIImpl.h"

#define MRScriptName "instance_murder_row"
#define DataHeader "MurderRow"

uint32 const EncounterCount = 4;

enum MurderRowDataTypes
{
    // Encounters
    DATA_KYSTIA_MANAHEART        = 0,
    DATA_ZAEN_BLADESORROW        = 1,
    DATA_XATHUUX_THE_ANNIHILATOR = 2,
    DATA_LITHIEL_CINDERFURY      = 3,

    // Additional Data
    DATA_NIBBLES
};

enum MurderRowCreatureIds
{
    // Bosses
    BOSS_KYSTIA_MANAHEART        = 234648,
    BOSS_ZAEN_BLADESORROW        = 234649,
    BOSS_XATHUUX_THE_ANNIHILATOR = 234647,
    BOSS_LITHIEL_CINDERFURY      = 237415,

    // Npcs
    NPC_NIBBLES                  = 234660
};

enum MurderRowGameObjectIds
{
    GO_FEL_DOOR = 618401
};

template <class AI, class T>
inline AI* GetMurderRowAI(T* obj)
{
    return GetInstanceAI<AI>(obj, MRScriptName);
}

#define RegisterMurderRowCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetMurderRowAI)

#endif
