/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DEF_BLACK_ROOK_HOLD_H
#define DEF_BLACK_ROOK_HOLD_H

enum DataTypes
{
    DATA_AMALGAM_OF_SOULS        = 0,
    DATA_ILLYSANNA_RAVENCREST    = 1,
    DATA_SMASHSPITE              = 2,
    DATA_LORD_RAVENCREST         = 3,

    DATA_MAX_ENCOUNTERS          = 4
};

enum Creatures
{
    NPC_AMALGAM_OF_SOULS            = 98542,
    NPC_ILLYSANNA_RAVENCREST        = 98696,
    NPC_SMASHSPITE_THE_HATEFUL      = 98948,
    NPC_LORD_KURTALOS_RAVENCREST    = 94923,
    NPC_DANTALIONAX                 = 99611,

    NPC_LATOSIUS                    = 98970,

    // Amalgam of Souls
    NPC_RESTLESS_SOUL               = 99664,
};

enum GameObjects
{
    GOB_DOOR_AMALGAME_ENTER_1       = 247403,
    GOB_DOOR_AMALGAME_ENTER_2       = 247406,

    GOB_DOOR_AMALGAME_ROOM_1        = 247403,
    GOB_DOOR_AMALGAME_ROOM_2        = 247404,
    GOB_DOOR_AMALGAME_ROOM_3        = 247405,
    GOB_DOOR_AMALGAME_ROOM_4        = 247406,

    GOB_DOOR_AMALGAME_EXIT          = 247407,

    GOB_DOOR_ILLYSANNA_PORTCULLIS_1 = 245079,
    GOB_DOOR_ILLYSANNA_PORTCULLIS_2 = 245080,

    GOB_DOOR_ILLYSANNA_ENTER        = 247400,
    GOB_DOOR_ILLYSANNA_EXIT_1       = 247399,
    GOB_DOOR_ILLYSANNA_EXIT_2       = 247401,

    GOB_DOOR_SMASHSPITE_ROOM        = 247402,

    GOB_DOOR_RAVENCREST_PASSAGE     = 245104,
    GOB_DOOR_RAVENCREST_ROOM        = 247498,
};

#endif
