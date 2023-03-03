/*
 * Copyright (C) 2022 BfaCore Reforged
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

#ifndef DEF_DARKHEART_THICKET_H
#define DEF_DARKHEART_THICKET_H

enum DataTypes
{
    DATA_ARCHDRUID_GLAIDALIS    = 0,
    DATA_OAKHEART               = 1,
    DATA_DRESARON               = 2,
    DATA_SHADE_OF_XAVIUS        = 3,

    DATA_MAX_ENCOUNTERS         = 4,
    DATA_SHIELD_TRIGGER         = 5,
    GO_EVENT_GLAIDALIS          = 6
};

enum ActionTypes
{
    ACTION_GLAIDALIS_INTRO,
    ACTION_MALFURION_OUTRO
};

enum CreatureIds
{
    NPC_ARCHDRUID_GLAIDALIS      = 96512,
    NPC_OAKHEART                 = 103344,
    NPC_DRESARON                 = 99200,
    NPC_SHADE_OF_XAVIUS          = 99192,
    NPC_MALFURION_STORMRAGE      = 100652,
    NPC_DRUIDIC_PRESERVER        = 100403,
    NPC_TRIGGER_PERSERVER        = 100404,
    NPC_TRIGGER_SHIELD           = 102851
};

enum GameObjectIds
{
    GO_DOOR_ROOM_GLAIDALIS_1     = 254984,
    GO_DOOR_ROOM_GLAIDALIS_2     = 254985,
    GO_DOOR_ROOM_GLAIDALIS_3     = 254986,
    GO_DOOR_ROOM_GLAIDALIS_4     = 254987,
    GO_DOOR_ROOM_GLAIDALIS_5     = 254988,
    GO_DOOR_ROOM_GLAIDALIS_6     = 254989,
    GO_DOOR_ROOM_GLAIDALIS_7     = 254997,
    GO_DOOR_ROOM_GLAIDALIS_8     = 254990,
    GO_DOOR_ROOM_GLAIDALIS_9     = 254998,
    GO_DOOR_ROOM_GLAIDALIS_10    = 254991,
    GO_DOOR_ROOM_GLAIDALIS_11    = 254999,
    GO_DOOR_ROOM_GLAIDALIS_12    = 254992,
    GO_DOOR_ROOM_GLAIDALIS_13    = 254996,
    GO_DOOR_ROOM_GLAIDALIS_14    = 254995,
    GO_DOOR_ROOM_GLAIDALIS_15    = 254994,
    GO_DOOR_ROOM_GLAIDALIS_16    = 254993,

    GO_GLAIDALIS_EVENT           = 254851,

    GO_DOOR_ROOM_DRESARON_1      = 254849,
    GO_DOOR_ROOM_DRESARON_2      = 254850,

    GO_DOOR_ROOM_XAVIUS          = 254855
};

enum ConversationSpells
{
    SPELL_CONVERSATION_INTRO            = 202867,
    SPELL_CONVERSATION_AFTER_FIRST_BOSS = 202882,
};

#endif
