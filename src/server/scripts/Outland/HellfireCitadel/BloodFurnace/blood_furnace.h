/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef DEF_BLOOD_FURNACE_H
#define DEF_BLOOD_FURNACE_H

enum DataTypes
{
    DATA_THE_MAKER                 = 1,
    DATA_BROGGOK                   = 2,
    DATA_KELIDAN_THE_MAKER         = 3,
    TYPE_THE_MAKER_EVENT           = 4,
    TYPE_BROGGOK_EVENT             = 5,
    TYPE_KELIDAN_THE_BREAKER_EVENT = 6,
    DATA_DOOR1                     = 7,
    DATA_DOOR2                     = 8,
    DATA_DOOR3                     = 9,
    DATA_DOOR4                     = 10,
    DATA_DOOR5                     = 11,
    DATA_DOOR6                     = 12,
    DATA_PRISON_CELL1              = 13,
    DATA_PRISON_CELL2              = 14,
    DATA_PRISON_CELL3              = 15,
    DATA_PRISON_CELL4              = 16,
    DATA_PRISON_CELL5              = 17,
    DATA_PRISON_CELL6              = 18,
    DATA_PRISON_CELL7              = 19,
    DATA_PRISON_CELL8              = 20,
    DATA_BROGGOK_LEVER             = 21
};

enum ActionIds
{
    ACTION_ACTIVATE_BROGGOK     = 1,
    ACTION_RESET_BROGGOK        = 2,
    ACTION_PREPARE_BROGGOK      = 3
};

#endif

