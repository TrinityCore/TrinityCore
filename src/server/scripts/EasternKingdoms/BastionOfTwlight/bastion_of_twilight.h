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

#ifndef _Bastion_of_Twilight_h__
#define _Bastion_of_Twilight_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "BOT";
constexpr char const* BotScriptName = "instance_bastion_of_twilight";

constexpr uint32 const EncounterCount = 5;

enum BotDataTypes
{
    // Encounters
    BOSS_HALFUS_WYRMBREAKER     = 0,
    BOSS_THERALION_AND_VALIONA  = 1,
    BOSS_ASCENDANT_COUNCIL      = 2,
    BOSS_CHOGALL                = 3,
    BOSS_SINESTRA               = 4
};

enum BotCreatureIds
{
    // Bosses
    NPC_HALFUS_WYRMBREAKER      = 44600,
    NPC_THERALION               = 45993,
    NPC_VALIONA                 = 45992,
    NPC_IGNACIOUS               = 43686,
    NPC_FELUDIUS                = 43687,
    NPC_TERRASTRA               = 43689,
    NPC_ARION                   = 43688,
    NPC_ELEMENTIUM_MONSTROSITY  = 43735,
    NPC_CHOGALL                 = 43324,
    NPC_SINESTRA                = 45213
};

enum BotGameObjectIds
{
    GO_HALFUS_ENTRANCE                  = 205222,
    GO_HALFUS_EXIT                      = 205223,
    GO_DRAGON_SIBLINGS_DOOR_ENTRANCE    = 205224,
    GO_DRAGON_SIBLINGS_DOOR_EXIT        = 205225,
    GO_ASCENDANT_COUNCIL_ENTRANCE       = 205226,
    GO_ASCENDANT_COUNCIL_EXIT           = 205227,
    GO_CHOGALL_ENTRANCE                 = 205228,
    GO_GRIM_BATOL_RAID_TRAP_DOOR        = 205898
};

template <class AI, class T>
inline AI* GetBastionOfTwilightAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BotScriptName);
}

#define RegisterBastionOfTwilightCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetBastionOfTwilightAI)

#endif // _Bastion_of_Twilight_h__
