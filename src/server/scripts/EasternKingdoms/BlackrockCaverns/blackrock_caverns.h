/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_BLACKROCK_CAVERNS_H
#define DEF_BLACKROCK_CAVERNS_H

enum Data
{
    DATA_ROMOGG_BONECRUSHER_EVENT,
    DATA_CORLA_EVENT,
    DATA_KARSH_STEELBENDER_EVENT,
    DATA_BEAUTY_EVENT,
    DATA_ASCENDANT_LORD_OBSIDIUS_EVENT,
    DATA_TEAM_IN_INSTANCE_EVENT,
};

enum Data64
{
    DATA_ROMOGG_BONECRUSHER,
    DATA_CORLA,
    DATA_KARSH_STEELBENDER,
    DATA_BEAUTY,
    DATA_ASCENDANT_LORD_OBSIDIUS,
};

enum CreatureIds
{
    // Dungeon Bosses

    BOSS_ROMOGG_BONECRUSHER      = 39665,
    BOSS_CORLA                   = 39679,
    BOSS_KARSH_STEELBENDER       = 39698,
    BOSS_BEAUTY                  = 39700,
    BOSS_ASCENDANT_LORD_OBSIDIUS = 39705,

    // Trash mobs

    NPC_BUSTER                   = 40013,
    NPC_CHAINS_OF_WOE            = 40447,
    NPC_CONFLAGRATION            = 39994,
    NPC_CRAZED_MAGE              = 39982,
    NPC_DEFILED_EARTH_RAGER      = 40023,
    NPC_EVOLVED_TWILIGHT_ZEALOT  = 39987,
    NPC_INCENDIARY_SPARK         = 40021,
    NPC_MAD_PRISONER             = 39985,
    NPC_TWILIGHT_ELEMENT_WARDEN  = 40017,
    NPC_TWILIGHT_FLAME_CALLER    = 39708,
    NPC_TWILIGHT_OBSIDIAN_BORER  = 40019,
    NPC_TWILIGHT_SADIST          = 39980,
    NPC_TWILIGHT_TORTURER        = 39978,
    NPC_TWILIGHT_ZEALOT          = 39990,

    // Various NPCs

    NPC_RAZ_THE_CRAZED           = 39670,
    NPC_FINKLE_EINHORN           = 49476,
    NPC_TWILIGHT_PORTAL          = 51340,
};

enum GameObjectIds
{
    GO_STONE_TABLET              = 207412,
};

#endif