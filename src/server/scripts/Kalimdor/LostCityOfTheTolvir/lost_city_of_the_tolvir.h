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

#ifndef DEF_LOST_CITY_OF_THE_TOLVIR_H
#define DEF_LOST_CITY_OF_THE_TOLVIR_H

enum Data64
{
    DATA_GENERAL_HUSAM,
    DATA_LOCKMAW,
    DATA_AUGH,
    DATA_HIGH_PROPHET_BARIM,
    DATA_SIAMAT,
    MAX_ENCOUNTER,
    DATA_HARBINGER,
    DATA_BLAZE,
};

enum Creatures
{
    // Dungeon Bosses
    BOSS_GENERAL_HUSAM           = 44577,
    BOSS_HIGH_PROPHET_BARIM      = 43612,
    BOSS_LOCKMAW                 = 43614,
    BOSS_AUGH                    = 49045,
    BOSS_SIAMAT                  = 44819,
    // Various NPCs
    NPC_WIND_TUNNEL              = 48092,
};

enum GameObjects
{
    SIAMAT_PLATFORM              = 205365,
};

#endif
