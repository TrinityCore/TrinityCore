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
 
#ifndef DEF_THE_STONECORE_H
#define DEF_THE_STONECORE_H

enum Data
{
    DATA_CORBORUS_EVENT,
    DATA_SLABHIDE_EVENT,
    DATA_OZRUK_EVENT,
    DATA_HIGH_PRIESTESS_AZIL_EVENT,
    DATA_TEAM_IN_INSTANCE,
};

enum Data64
{
    DATA_CORBORUS,
    DATA_SLABHIDE,
    DATA_OZRUK,
    DATA_HIGH_PRIESTESS_AZIL,
};

enum CreatureIds
{
    // Dungeon Bosses

    BOSS_CORBORUS                  = 43438,
    BOSS_SLABHIDE                  = 43214,
    BOSS_OZRUK                     = 42188,
    BOSS_HIGH_PRIESTESS_AZIL       = 42333,

    // Trash mobs

    NPC_CRYSTALSPAWN_GIANT         = 42810,
    NPC_IMP                        = 43014,
    NPC_MILLHOUSE_MANASTORM        = 43391,
    NPC_ROCK_BORER                 = 43917,
    NPC_ROCK_BORER2                = 42845,
    NPC_STONECORE_BERSERKER        = 43430,
    NPC_STONECORE_BRUISER          = 42692,
    NPC_STONECORE_EARTHSHAPER      = 43537,
    NPC_STONECORE_FLAYER           = 42808,
    NPC_MAGMALORD                  = 42789,
    NPC_RIFT_CONJURER              = 42691,
    NPC_STONECORE_SENTRY           = 42695,
    NPC_STONECORE_WARBRINGER       = 42696,

    // Various NPCs

    NPC_EARTHWARDEN_YRSA           = 50048,
    NPC_STONECORE_TELEPORTER1      = 51396,
    NPC_STONECORE_TELEPORTER2      = 51397,
};

enum GameObjectIds
{
    GO_BROKEN_PILLAR               = 207407,
    GO_TWILIGHT_DOCUMENTS          = 207415,
};

#endif