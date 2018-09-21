/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef DEF_STONECORE_H
#define DEF_STONECORE_H

#include "CreatureAIImpl.h"

#define SCScriptName "instance_stonecore"
#define DataHeader "SC"

enum SCDataTypes
{
    // Encounter States/Boss GUIDs
    DATA_CORBORUS,
    DATA_SLABHIDE,
    DATA_OZRUK,
    DATA_HIGH_PRIESTESS_AZIL,

    // Additional Data
    DATA_MILLHOUSE_MANASTORM,
    DATA_MILLHOUSE_EVENT_FACE,
    DATA_HANDLE_CORBORUS_ROCKDOOR,
    DATA_MILLHOUSE_EVENT_KNOCKBACK,
    DATA_MILLHOUSE_EVENT_DESPAWN,

    DATA_SLABHIDE_INTRO,
    DATA_SLABHIDE_ROCK_WALL,

    // Teleporters
    DATA_STONECORE_TELEPORTER,
    DATA_STONECORE_TELEPORTER_2,
};

enum SCMisc
{
    ACTION_CORBORUS_INTRO,
    ACTION_SLABHIDE_INTRO,

    NPC_WORLDTRIGGER = 22515,
    NPC_MILLHOUSE_MANASTORM = 43391,

    NPC_CORBORUS = 43438,
    NPC_SLABHIDE = 43214,
    NPC_OZRUK = 42188,
    NPC_HIGH_PRIESTESS_AZIL = 42333,

    // Stonecore Teleporter misc
    MAX_STONECORE_TELEPORTERS = 2,
    NPC_STONECORE_TELEPORTER = 51396, // Entrance teleporter
    NPC_STONECORE_TELEPORTER_2 = 51397, // Slabhide teleporter
    SPELL_TELEPORTER_ACTIVE_VISUAL = 95298,

    GAMEOBJECT_TWILIGHT_DOCUMENTS = 207415,
    GAMEOBJECT_CORBORUS_ROCKDOOR = 207343,
    GAMEOBJECT_SLABHIDE_ROCK_WALL = 204381,

    SPELL_RING_WYRM_KNOCKBACK = 81235,

    // Creature Formation IDs
    CREATURE_FORMATION_MILLHOUSE_EVENT_TRASH      = 340418,
    CREATURE_FORMATION_MILLHOUSE_EVENT_LAST_GROUP = 340492,
};

template<typename AI>
inline AI* GetStonecoreAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, SCScriptName);
}

#endif // DEF_STONECORE
