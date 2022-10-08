/*
 * This file is part of the AshamaneCore Project. See AUTHORS file for Copyright information
 * Copyright (C) 2018+ MagicStormProject <https://github.com/MagicStormTeam>
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

#ifndef ANTHORUS_H
#define ANTHORUS_H

enum DataTypes
{
    // Bosses
    DATA_GAROTHI_WORLDBREAKER     = 0,
    DATA_FELHOUNDS                = 1,
    DATA_ANTORAN                  = 2,
    DATA_HASABEL                  = 3,
    DATA_EONAR                    = 4,
    DATA_IMONAR                   = 5,
    DATA_KINGAROTH                = 6,
    DATA_VARIMATHRAS              = 7,
    DATA_COVEN_OF_SHIMARRA        = 8,
    DATA_AGGRAMAR                 = 9,
    DATA_ARGUS                    = 10,
    DATA_SHIWAR                   = 11,

    DATA_MAX_ENCOUNTERS,

    // Additional data
    DATA_CANNON_ANNIHILATOR,
    DATA_CANNON_DECIMATOR,
};

enum Creatures
{
    // Garothi Worldbreaker
    NPC_GAROTHI_WORLDBREAKER      = 123371,
    NPC_GAROTHI_ANNIHILATOR       = 123398,
    NPC_CANNON_ANNIHILATOR        = 122778,
    NPC_CANNON_DECIMATOR          = 122773,

};

enum Gameobjects
{
    GO_DOOR_ROOM_GOROTH_ES           = 269973,
};

#endif // ANTHORUS_H
