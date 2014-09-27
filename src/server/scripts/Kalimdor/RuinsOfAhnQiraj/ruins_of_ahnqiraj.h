/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_RUINS_OF_AHNQIRAJ_H
#define DEF_RUINS_OF_AHNQIRAJ_H

#define DataHeader "AQR"

enum DataTypes
{
    DATA_KURINNAXX          = 0,
    DATA_RAJAXX             = 1,
    DATA_MOAM               = 2,
    DATA_BURU               = 3,
    DATA_AYAMISS            = 4,
    DATA_OSSIRIAN           = 5,
    NUM_ENCOUNTER           = 6,

    DATA_PARALYZED          = 7
};

enum Creatures
{
    NPC_KURINAXX                = 15348,
    NPC_RAJAXX                  = 15341,
    NPC_MOAM                    = 15340,
    NPC_BURU                    = 15370,
    NPC_AYAMISS                 = 15369,
    NPC_OSSIRIAN                = 15339,
    NPC_HIVEZARA_HORNET         = 15934,
    NPC_HIVEZARA_SWARMER        = 15546,
    NPC_HIVEZARA_LARVA          = 15555,
    NPC_SAND_VORTEX             = 15428,
    NPC_OSSIRIAN_TRIGGER        = 15590,
    NPC_HATCHLING               = 15521,
    NPC_LARVA                   = 15555,
    NPC_SWARMER                 = 15546,
    NPC_HORNET                  = 15934
};

enum GameObjects
{
    GO_OSSIRIAN_CRYSTAL         = 180619
};

#endif
