/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2010-2011 Trinity <http://www.projecttrinity.org/>
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

enum Data64
{
    DATA_LADY_NAZJAR,
    DATA_COMMANDER_ULTHOK,
    DATA_ERUNAK_STONESPEAKER,
    DATA_MINDBENDER_GHURSHA,
    DATA_OZUMAT,
    DATA_NEPTULON,
};

enum Data
{
    DATA_LADY_NAZJAR_EVENT,
    DATA_COMMANDER_ULTHOK_EVENT,
    DATA_ERUNAK_STONESPEAKER_EVENT,
    DATA_MINDBENDER_GHURSHA_EVENT,
    DATA_OZUMAT_EVENT,

    // Areatriggers data
    DATA_FIRST_TUNNEL,
};

enum CreatureIds
{
    /* Dungeons Bosses */

    BOSS_LADY_NAZJAR            = 40586,
    NPC_SUMMONED_WITCH          = 44404, // 2 of them
    NPC_SUMMONED_GUARD          = 40633,
    NPC_SUMMONED_WATERSPOUT     = 48571,

    BOSS_COMMANDER_ULTHOK       = 40765,
    BOSS_ERUNAK_STONESPEAKER    = 40825,
    BOSS_MINDBENDER_GHURSHA     = 40788,
    BOSS_OZUMAT                 = 44566,
    BOSS_NEPTULON               = 40792,


    /* Various NPCs */

    NPC_CAPTAIN_TAYLOR          = 50270,
    NPC_LEGIONNAIRE_NAZGRIM     = 50272,
    NPC_NEPTULON                = 40792,
    NPC_THRONE_TELEPORTER_1     = 51395,
    NPC_THRONE_TELEPORTER_2     = 51391,
    NPC_ULTHOK_VOID             = 40784,
    NPC_TELEPORTER              = 51391,

    // Left Wing counter
    NPC_TAINTED_SENTRY          = 40925,
    // Right Wing counter
    NPC_GILGOBLIN_AQUAMAGE      = 40943,
    NPC_GILGOBLIN_HUNTER        = 40935,
    NPC_FACELESS_WATCHER        = 40936,

    /* Gauntlet Event */

    NPC_LADY_NAZJAR_GAUNTLET    = 39959,
    NPC_DEEP_MURLOC_DRUDGE      = 39960,

    /* Trash mobs */

    NPC_NAZJAR_INVADER          = 39616, // First Tunnel (5806 AT)
    NPC_NAZJAR_INVADER2         = 40584,
    NPC_NAZJAR_SPIRITMENDER     = 41096, // First Tunnel
    NPC_NAZJAR_SPIRITMENDER2    = 41139, // Second Tunnel

    /* Ozumat Waves */

    NPC_DEEP_MURLOC             = 44658,
    NPC_MINDLASHER              = 44715,
    NPC_BEHEMOTH                = 44648,
    NPC_SAPPER                  = 44752,
    NPC_BEAST                   = 44841,

    /* Various data */

    SPELL_TIDAL_SURGE           = 76133,
    SPELL_CLEAR_TIDAL_SURGE     = 83909,
    INSTANCE_CINEMATIC          = 169,
};

enum GameObjectIds
{
    GO_STRANGE_FOUNTAIN               = 207406,
    GO_LADY_NAZJAR_DOOR               = 204338,
    GO_COMMANDER_ULTHOK_DOOR          = 204339,
    GO_ERUNAK_STONESPEAKER_DOOR       = 204340,
    GO_OZUMAT_DOOR                    = 204341,
    GO_OZUMAT_CHEST_NORMAL            = 205216,
    GO_OZUMAT_CHEST_HEROIC            = 207973,

    GO_OZUMAT_TENTACLE_1              = 204927, // Down
    GO_OZUMAT_TENTACLE_2              = 204944, // Up
    GO_INVISIBLE_DOOR                 = 402356,
};

enum AchievemtsIds
{
    NORMAL_OZUMAT_DEFEAT = 4839,
    HEROIC_OZUMAT_DEFEAT = 5061,
    HEROIC_OZUMAT_DEFEAT_WHILE_IN_GUILD_GROUP = 5135,
    HEROIC_NAZJAR_GEYSER_KILLED_TRASH = 5285,
    HEROIC_DEFEAT_BEHEMOT_WITH_SURGE_EFFECT = 5286,
};

#endif
