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

#ifndef TOL_DAGOR_H
#define TOL_DAGOR_H

#define DataHeader "TD"

uint32 const EncounterCount = 4;

enum EncounterData
{
    DATA_THE_SAND_QUEEN         = 0,
    DATA_JES_HOWLIS             = 1,
    DATA_KNIGHT_CAPTAIN_VALYRI  = 2,
    DATA_OVERSEER_KORGUS        = 3,
};

enum CreatureIds
{
    NPC_THE_SAND_QUEEN          = 127479,
    NPC_JES_HOWLIS              = 127484,
    NPC_KNIGHT_CAPTAIN_VALYRI   = 127490,
    NPC_OVERSEER_KORGUS         = 127503,
    NPC_BUZZING_DRONE           = 131785,
    NPC_ASHAVANE_QUATERMASTER   = 131856,
    NPC_MUNITIONS_BARREL        = 129437,
    NPC_HEAVY_CANNON            = 134025,
};

#endif // TOL_DAGOR_H
