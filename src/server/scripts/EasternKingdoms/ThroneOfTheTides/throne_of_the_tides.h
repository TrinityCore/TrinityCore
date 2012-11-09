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
 
#ifndef DEF_THRONE_OF_THE_TIDES
#define DEF_THRONE_OF_THE_TIDES

enum Npcs
{
    // Lady Naz'jar
    BOSS_LADY_NAZJAR                  = 40586,
    NPC_SUMMONED_WITCH                = 40634, // 2 of them
    NPC_SUMMONED_GUARD                = 40633,
    NPC_SUMMONED_WATERSPOUT           = 48571,

    // Commander Ulthok
    BOSS_COMMANDER_ULTHOK             = 40765,
    NPC_DARK_FISSURE                  = 40784,

    // Erunak Stonespeaker & Mindbender Ghur'sha
    BOSS_ERUNAK_STONESPEAKER          = 40825,
    BOSS_MINDBENDER_GHURSHA           = 40788,
    NPC_EARTH_SHARD                   = 45469,
    NPC_MIND_FOG                      = 40861,
    // Ozumat
    BOSS_OZUMAT                       = 42172,
    BOSS_NEPTULON                     = 40792,
    NPC_DEEP_MURLOC                   = 44658,
    NPC_MINDLASHER                    = 44715,
    NPC_BEHEMOTH                      = 44648,
    NPC_SAPPER                        = 44752,
    NPC_BEAST                         = 44841,
    // GOs
    GO_LADY_NAZJAR_DOOR               = 204338,
    GO_JELLYFISH_ELEVATOR             = 207209,
    GO_COMMANDER_ULTHOK_DOOR          = 204339,
    GO_ERUNAK_STONESPEAKER_DOOR       = 204340,
    GO_OZUMAT_DOOR                    = 204341,
    GO_OZUMAT_CHEST_NORMAL            = 205216,
    GO_OZUMAT_CHEST_HEROIC            = 320000,
};

enum Data
{
    DATA_LADY_NAZJAR_EVENT         = 0,
    DATA_COMMANDER_ULTHOK_EVENT    = 1,
    DATA_ERUNAK_STONESPEAKER_EVENT = 2,
    DATA_OZUMAT_EVENT              = 3
};

#define MAX_ENCOUNTER 4

enum Data64
{
    DATA_LADY_NAZJAR,
    DATA_COMMANDER_ULTHOK,
    DATA_ERUNAK_STONESPEAKER,
    DATA_OZUMAT,
    DATA_NEPTULON,
};

#endif