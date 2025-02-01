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

#ifndef DEF_NERUBAR_PALACE_H_
#define DEF_NERUBAR_PALACE_H_

#include "CreatureAIImpl.h"

#define NPScriptName "instance_nerubar_palace"
#define DataHeader "NerubarPalace"

uint32 const EncounterCount = 8;

enum NerubarPalaceDataTypes
{
    // Encounters
    DATA_ULGRAX_THE_DEVOURER   = 0,
    DATA_THE_BLOODBOUND_HORROR = 1,
    DATA_SIKRAN                = 2,
    DATA_RASHANAN              = 3,
    DATA_BROODTWISTER_OVINAX   = 4,
    DATA_NEXUS_PRINCESS_KYVEZA = 5,
    DATA_THE_SILKEN_COURT      = 6,
    DATA_QUEEN_ANSUREK         = 7,

    // Additional Data
    DATA_NERUBAR_PALACE_DOOR_INTRO,
    DATA_WEB_BRIDGE_ULGRAX_INTRO
};

enum NerubarPalaceCreatureIds
{
    // Bosses
    BOSS_ULGRAX_THE_DEVOURER   = 215657,
    BOSS_THE_BLOODBOUND_HORROR = 214502,
    BOSS_SIKRAN                = 219853,
    BOSS_RASHANAN              = 224552,
    BOSS_BROODTWISTER_OVINAX   = 214506,
    BOSS_NEXUS_PRINCESS_KYVEZA = 228470,
    BOSS_ANUBARASH             = 223779,
    BOSS_QUEEN_ANSUREK         = 219778
};

enum NerubarPalaceGameObjectIds
{
    GO_NERUBAR_PALACE_DOOR_INTRO = 444355,
    GO_WEB_BRIDGE_ULGRAX_INTRO   = 437052
};

template <class AI, class T>
inline AI* GetNerubarPalaceAI(T* obj)
{
    return GetInstanceAI<AI>(obj, NPScriptName);
}

#define RegisterNerubarPalaceCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetNerubarPalaceAI)

#endif
