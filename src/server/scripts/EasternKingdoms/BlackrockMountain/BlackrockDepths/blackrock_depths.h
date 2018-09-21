/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef DEF_BRD_H
#define DEF_BRD_H

#include "CreatureAIImpl.h"

#define BRDScriptName "instance_blackrock_depths"
#define DataHeader "BRD"
#define MAX_ENCOUNTER           5

enum BRDFactionIds
{
    FACTION_NEUTRAL            = 734,
    FACTION_HOSTILE            = 754,
    FACTION_FRIEND             = 35
};

enum BRDDataTypes
{
    TYPE_RING_OF_LAW        = 1,
    TYPE_VAULT              = 2,
    TYPE_BAR                = 3,
    TYPE_TOMB_OF_SEVEN      = 4,
    TYPE_IRON_HALL          = 5,

    DATA_EMPEROR            = 10,
    DATA_PHALANX            = 11,

    DATA_ARENA1             = 12,
    DATA_ARENA2             = 13,
    DATA_ARENA3             = 14,
    DATA_ARENA4             = 15,

    DATA_GO_BAR_KEG         = 16,
    DATA_GO_BAR_KEG_TRAP    = 17,
    DATA_GO_BAR_DOOR        = 18,
    DATA_GO_CHALICE         = 19,

    DATA_GHOSTKILL          = 20,
    DATA_EVENSTARTER        = 21,

    DATA_GOLEM_DOOR_N       = 22,
    DATA_GOLEM_DOOR_S       = 23,

    DATA_THRONE_DOOR        = 24,

    DATA_SF_BRAZIER_N       = 25,
    DATA_SF_BRAZIER_S       = 26,
    DATA_MOIRA              = 27,
    DATA_COREN              = 28
};

enum BRDCreatures
{
    NPC_EMPEROR             = 9019,
    NPC_PHALANX             = 9502,
    NPC_ANGERREL            = 9035,
    NPC_DOPEREL             = 9040,
    NPC_HATEREL             = 9034,
    NPC_VILEREL             = 9036,
    NPC_SEETHREL            = 9038,
    NPC_GLOOMREL            = 9037,
    NPC_DOOMREL             = 9039,
    NPC_MAGMUS              = 9938,
    NPC_MOIRA               = 8929,
    NPC_COREN               = 23872
};

enum BRDGameObjects
{
    GO_ARENA1               = 161525,
    GO_ARENA2               = 161522,
    GO_ARENA3               = 161524,
    GO_ARENA4               = 161523,
    GO_SHADOW_LOCK          = 161460,
    GO_SHADOW_MECHANISM     = 161461,
    GO_SHADOW_GIANT_DOOR    = 157923,
    GO_SHADOW_DUMMY         = 161516,
    GO_BAR_KEG_SHOT         = 170607,
    GO_BAR_KEG_TRAP         = 171941,
    GO_BAR_DOOR             = 170571,
    GO_TOMB_ENTER           = 170576,
    GO_TOMB_EXIT            = 170577,
    GO_LYCEUM               = 170558,
    GO_SF_BRAZIER_N         = 174745, // Shadowforge Brazier North
    GO_SF_BRAZIER_S         = 174744, // Shadowforge Brazier South
    GO_GOLEM_ROOM_N         = 170573, // Magmus door North
    GO_GOLEM_ROOM_S         = 170574, // Magmus door Soutsh
    GO_THRONE_ROOM          = 170575, // Throne door
    GO_SPECTRAL_CHALICE     = 164869,
    GO_CHEST_SEVEN          = 169243
};

template <class AI, class T>
inline AI* GetBlackrockDepthsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BRDScriptName);
}

#define RegisterBlackrockDepthsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetBlackrockDepthsAI)

#endif
