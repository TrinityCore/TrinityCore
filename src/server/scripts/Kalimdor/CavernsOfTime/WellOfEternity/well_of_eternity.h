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

#ifndef _Well_of_Eternity_h__
#define _Well_of_Eternity_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "WOE";
constexpr char const* WoEScriptName = "instance_well_of_eternity";

constexpr uint32 const EncounterCount = 3;

enum WOEDataTypes
{
    // Encounters
    BOSS_PEROTHARN          = 0,
    BOSS_QUEEN_AZSHARA      = 1,
    BOSS_MANNOROTH          = 2,

    // Additional Data
    DATA_NOZDORMU,
    DATA_PEROTHARN_INTRO,

    // Illidan Data
    DATA_ILLIDAN_1,
    DATA_ILLIDAN_START_INTRO,
    DATA_ILLIDAN_START_ESCORT,
    DATA_ILLIDAN_FIRST_CRYSTAL
};

enum WOECreatureIds
{
    // Bosses
    NPC_PEROTHARN           = 55085,
    NPC_QUEEN_AZSHARA       = 54853,
    NPC_MANNOROTH           = 54969,

    // NPCs
    NPC_NOZDORMU            = 55624,
    NPC_VAROTHEN            = 55419,
    NPC_FIRE_WALL_STALKER   = 56096,
    NPC_ILLIDAN_PART_1      = 55500,
    NPC_DEMON_STALKER       = 58200
};

enum WOEGameObjectIds
{
    GO_LARGE_FIRE_WALL_DOOR = 210234,
    GO_COURTYARD_DOOR       = 210084
};

enum WOESpells
{
    SPELL_SHADOWCLOAK_PLAYER  = 103004
};

enum WOESharedActions
{
    ACTION_PEROTHARN_INTRO          = 1,
    ACTION_ILLIDAN_ON_FIRST_CRYSTAL = 10
};

template <class AI, class T>
inline AI* GetWellOfEnernityAI(T* obj)
{
    return GetInstanceAI<AI>(obj, WoEScriptName);
}

#define RegisterWellOfEternityCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetWellOfEnernityAI)

#endif // _Well_of_Eternity_h__
