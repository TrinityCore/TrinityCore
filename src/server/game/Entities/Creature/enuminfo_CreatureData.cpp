/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "CreatureData.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity
{
namespace Impl
{

/*************************************************************************\
|* data for enum 'CreatureFlagsExtra' in 'CreatureData.h' auto-generated *|
\*************************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<CreatureFlagsExtra>::ToString(CreatureFlagsExtra value)
{
    switch (value)
    {
        case CREATURE_FLAG_EXTRA_INSTANCE_BIND: return { "CREATURE_FLAG_EXTRA_INSTANCE_BIND", "CREATURE_FLAG_EXTRA_INSTANCE_BIND", "creature kill bind instance with killer and killer's group" };
        case CREATURE_FLAG_EXTRA_CIVILIAN: return { "CREATURE_FLAG_EXTRA_CIVILIAN", "CREATURE_FLAG_EXTRA_CIVILIAN", "not aggro (ignore faction/reputation hostility)" };
        case CREATURE_FLAG_EXTRA_NO_PARRY: return { "CREATURE_FLAG_EXTRA_NO_PARRY", "CREATURE_FLAG_EXTRA_NO_PARRY", "creature can't parry" };
        case CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN: return { "CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN", "CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN", "creature can't counter-attack at parry" };
        case CREATURE_FLAG_EXTRA_NO_BLOCK: return { "CREATURE_FLAG_EXTRA_NO_BLOCK", "CREATURE_FLAG_EXTRA_NO_BLOCK", "creature can't block" };
        case CREATURE_FLAG_EXTRA_NO_CRUSH: return { "CREATURE_FLAG_EXTRA_NO_CRUSH", "CREATURE_FLAG_EXTRA_NO_CRUSH", "creature can't do crush attacks" };
        case CREATURE_FLAG_EXTRA_NO_XP_AT_KILL: return { "CREATURE_FLAG_EXTRA_NO_XP_AT_KILL", "CREATURE_FLAG_EXTRA_NO_XP_AT_KILL", "creature kill not provide XP" };
        case CREATURE_FLAG_EXTRA_TRIGGER: return { "CREATURE_FLAG_EXTRA_TRIGGER", "CREATURE_FLAG_EXTRA_TRIGGER", "trigger creature" };
        case CREATURE_FLAG_EXTRA_NO_TAUNT: return { "CREATURE_FLAG_EXTRA_NO_TAUNT", "CREATURE_FLAG_EXTRA_NO_TAUNT", "creature is immune to taunt auras and effect attack me" };
        case CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE: return { "CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE", "CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE", "creature won't update movement flags" };
        case CREATURE_FLAG_EXTRA_GHOST_VISIBILITY: return { "CREATURE_FLAG_EXTRA_GHOST_VISIBILITY", "CREATURE_FLAG_EXTRA_GHOST_VISIBILITY", "creature will be only visible for dead players" };
        case CREATURE_FLAG_EXTRA_USE_OFFHAND_ATTACK: return { "CREATURE_FLAG_EXTRA_USE_OFFHAND_ATTACK", "CREATURE_FLAG_EXTRA_USE_OFFHAND_ATTACK", "creature will use offhand attacks" };
        case CREATURE_FLAG_EXTRA_NO_SELL_VENDOR: return { "CREATURE_FLAG_EXTRA_NO_SELL_VENDOR", "CREATURE_FLAG_EXTRA_NO_SELL_VENDOR", "players can't sell items to this vendor" };
        case CREATURE_FLAG_EXTRA_UNUSED_13: return { "CREATURE_FLAG_EXTRA_UNUSED_13", "CREATURE_FLAG_EXTRA_UNUSED_13", "" };
        case CREATURE_FLAG_EXTRA_WORLDEVENT: return { "CREATURE_FLAG_EXTRA_WORLDEVENT", "CREATURE_FLAG_EXTRA_WORLDEVENT", "custom flag for world event creatures (left room for merging)" };
        case CREATURE_FLAG_EXTRA_GUARD: return { "CREATURE_FLAG_EXTRA_GUARD", "CREATURE_FLAG_EXTRA_GUARD", "Creature is guard" };
        case CREATURE_FLAG_EXTRA_UNUSED_16: return { "CREATURE_FLAG_EXTRA_UNUSED_16", "CREATURE_FLAG_EXTRA_UNUSED_16", "" };
        case CREATURE_FLAG_EXTRA_NO_CRIT: return { "CREATURE_FLAG_EXTRA_NO_CRIT", "CREATURE_FLAG_EXTRA_NO_CRIT", "creature can't do critical strikes" };
        case CREATURE_FLAG_EXTRA_NO_SKILLGAIN: return { "CREATURE_FLAG_EXTRA_NO_SKILLGAIN", "CREATURE_FLAG_EXTRA_NO_SKILLGAIN", "creature won't increase weapon skills" };
        case CREATURE_FLAG_EXTRA_TAUNT_DIMINISH: return { "CREATURE_FLAG_EXTRA_TAUNT_DIMINISH", "CREATURE_FLAG_EXTRA_TAUNT_DIMINISH", "Taunt is a subject to diminishing returns on this creautre" };
        case CREATURE_FLAG_EXTRA_ALL_DIMINISH: return { "CREATURE_FLAG_EXTRA_ALL_DIMINISH", "CREATURE_FLAG_EXTRA_ALL_DIMINISH", "creature is subject to all diminishing returns as player are" };
        case CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ: return { "CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ", "CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ", "creature does not need to take player damage for kill credit" };
        case CREATURE_FLAG_EXTRA_UNUSED_22: return { "CREATURE_FLAG_EXTRA_UNUSED_22", "CREATURE_FLAG_EXTRA_UNUSED_22", "" };
        case CREATURE_FLAG_EXTRA_UNUSED_23: return { "CREATURE_FLAG_EXTRA_UNUSED_23", "CREATURE_FLAG_EXTRA_UNUSED_23", "" };
        case CREATURE_FLAG_EXTRA_UNUSED_24: return { "CREATURE_FLAG_EXTRA_UNUSED_24", "CREATURE_FLAG_EXTRA_UNUSED_24", "" };
        case CREATURE_FLAG_EXTRA_UNUSED_25: return { "CREATURE_FLAG_EXTRA_UNUSED_25", "CREATURE_FLAG_EXTRA_UNUSED_25", "" };
        case CREATURE_FLAG_EXTRA_UNUSED_26: return { "CREATURE_FLAG_EXTRA_UNUSED_26", "CREATURE_FLAG_EXTRA_UNUSED_26", "" };
        case CREATURE_FLAG_EXTRA_UNUSED_27: return { "CREATURE_FLAG_EXTRA_UNUSED_27", "CREATURE_FLAG_EXTRA_UNUSED_27", "" };
        case CREATURE_FLAG_EXTRA_DUNGEON_BOSS: return { "CREATURE_FLAG_EXTRA_DUNGEON_BOSS", "CREATURE_FLAG_EXTRA_DUNGEON_BOSS", "creature is a dungeon boss (SET DYNAMICALLY, DO NOT ADD IN DB)" };
        case CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING: return { "CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING", "CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING", "creature ignore pathfinding" };
        case CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK: return { "CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK", "CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK", "creature is immune to knockback effects" };
        case CREATURE_FLAG_EXTRA_UNUSED_31: return { "CREATURE_FLAG_EXTRA_UNUSED_31", "CREATURE_FLAG_EXTRA_UNUSED_31", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<CreatureFlagsExtra>::Count() { return 32; }

template <>
TC_API_EXPORT CreatureFlagsExtra EnumUtils<CreatureFlagsExtra>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return CREATURE_FLAG_EXTRA_INSTANCE_BIND;
        case 1: return CREATURE_FLAG_EXTRA_CIVILIAN;
        case 2: return CREATURE_FLAG_EXTRA_NO_PARRY;
        case 3: return CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN;
        case 4: return CREATURE_FLAG_EXTRA_NO_BLOCK;
        case 5: return CREATURE_FLAG_EXTRA_NO_CRUSH;
        case 6: return CREATURE_FLAG_EXTRA_NO_XP_AT_KILL;
        case 7: return CREATURE_FLAG_EXTRA_TRIGGER;
        case 8: return CREATURE_FLAG_EXTRA_NO_TAUNT;
        case 9: return CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE;
        case 10: return CREATURE_FLAG_EXTRA_GHOST_VISIBILITY;
        case 11: return CREATURE_FLAG_EXTRA_USE_OFFHAND_ATTACK;
        case 12: return CREATURE_FLAG_EXTRA_NO_SELL_VENDOR;
        case 13: return CREATURE_FLAG_EXTRA_UNUSED_13;
        case 14: return CREATURE_FLAG_EXTRA_WORLDEVENT;
        case 15: return CREATURE_FLAG_EXTRA_GUARD;
        case 16: return CREATURE_FLAG_EXTRA_UNUSED_16;
        case 17: return CREATURE_FLAG_EXTRA_NO_CRIT;
        case 18: return CREATURE_FLAG_EXTRA_NO_SKILLGAIN;
        case 19: return CREATURE_FLAG_EXTRA_TAUNT_DIMINISH;
        case 20: return CREATURE_FLAG_EXTRA_ALL_DIMINISH;
        case 21: return CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ;
        case 22: return CREATURE_FLAG_EXTRA_UNUSED_22;
        case 23: return CREATURE_FLAG_EXTRA_UNUSED_23;
        case 24: return CREATURE_FLAG_EXTRA_UNUSED_24;
        case 25: return CREATURE_FLAG_EXTRA_UNUSED_25;
        case 26: return CREATURE_FLAG_EXTRA_UNUSED_26;
        case 27: return CREATURE_FLAG_EXTRA_UNUSED_27;
        case 28: return CREATURE_FLAG_EXTRA_DUNGEON_BOSS;
        case 29: return CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING;
        case 30: return CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK;
        case 31: return CREATURE_FLAG_EXTRA_UNUSED_31;
        default: throw std::out_of_range("index");
    }
}
}
}
