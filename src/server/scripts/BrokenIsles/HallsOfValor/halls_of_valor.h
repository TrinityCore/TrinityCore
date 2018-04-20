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
    DATA_HYMDALL            = 0,
    DATA_HYRJA              = 1,
    DATA_FRENRYR            = 2,
    DATA_GODKING_SKOVALD    = 3,
    DATA_ODYN               = 4,

    DATA_MAX_ENCOUNTERS     = 5
};

enum GameObjects
{
    GOB_DOOR_HYMDALL_ENTRANCE   = 245700,
    GOB_DOOR_HYMDALL_EXIT       = 245701,

    GOB_DOOR_HYRJA_ROOM         = 245702,

    GOB_DOOR_ODYN_PASSAGE       = 244664,
    GOB_DOOR_ODYN_BRIDGE        = 246144,

    GOB_DOOR_ODYN_ROOM          = 246145,
};

#endif
