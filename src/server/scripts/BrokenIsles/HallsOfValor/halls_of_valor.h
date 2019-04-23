/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef DEF_HALLS_OF_VALOR_H
#define DEF_HALLS_OF_VALOR_H

enum DataTypes
{
    DATA_HYMDALL,
    DATA_HYRJA,
    DATA_FENRYR,
    DATA_GODKING_SKOVALD,
    DATA_ODYN,

    // Hyrja Adds
    DATA_OLMYR,
    DATA_SOLSTEN,

    // Odyn Adds
    DATA_KING_RANULF,
    DATA_KING_HALDOR,
    DATA_KING_BJORN,
    DATA_KING_TOR,

    DATA_MAX_ENCOUNTERS
};

enum CreatureIds
{
    BOSS_HYMDALL                = 94960,
    BOSS_HYRJA                  = 95833,
    BOSS_FENRYR                 = 99868,
    BOSS_GOD_KING_SKOVALD       = 95675,
    BOSS_ODYN                   = 95676,

    NPC_KING_RANULF             = 97083,
    NPC_KING_HALDOR             = 95843,
    NPC_KING_BJORN              = 97081,
    NPC_KING_TOR                = 97084,

    NPC_STORM_DRAKE             = 99891,
    NPC_STATIC_FIELD            = 97795,
    NPC_SOLSTEN                 = 97219,
    NPC_SOLSTEN_GHOST           = 102558,
    NPC_OLMYR_THE_ENLIGHTENED   = 97202,
    NPC_OLMYR_GHOST             = 102557,
};

enum GameObjects
{
    GOB_DOOR_HYMDALL_ENTRANCE   = 245700,
    GOB_DOOR_HYMDALL_EXIT       = 245701,
    GOB_HYMDALLS_CACHE          = 258968,

    GOB_DOOR_HYRJA_ROOM         = 245702,

    GOB_DOOR_ODYN_PASSAGE       = 244664,
    GOB_DOOR_ODYN_BRIDGE        = 246144,

    GOB_DOOR_ODYN_ROOM          = 246145,
    GO_SPOILS_OF_THE_WORTHY     = 245847,
};

enum Actions
{
    ACTION_EVENT_START,
    ACTION_CAN_JOIN_COMBAT,
};

enum SpellVisualKit
{
    SPELL_VISUAL_KIT_VALHALLA_ENTRANCE_FIELD_ETERNAL_HUNT = 62761,
    SPELL_VISUAL_KIT_VALHALLA_EXIT_FIELD_ETERNAL_HUNT     = 82068,
};

#endif
