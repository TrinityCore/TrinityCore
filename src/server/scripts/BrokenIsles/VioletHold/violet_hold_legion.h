/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_VIOLET_HOLD_LEGION_H
#define DEF_VIOLET_HOLD_LEGION_H

uint32 const EncounterCount = 3 + 6;

enum DataTypes
{
    // Main encounters
    DATA_1ST_BOSS                 = 0,
    DATA_2ND_BOSS                 = 1,
    DATA_3RD_BOSS                 = 2,

    // Random Bosses
    DATA_ANUBESSET                = 3,
    DATA_BLOODPRINCESS_THALENA    = 4,
    DATA_FESTERFACE               = 5,
    DATA_MILLIFICENT_MANASTORM    = 6,
    DATA_MINDFLAYER_KAAHRJ        = 7,
    DATA_SHIVERMAW                = 8,

    // Final Bosses
    DATA_FEL_LORD_BETRUG          = 9,
    DATA_SAELORN                  = 10,
};

#endif