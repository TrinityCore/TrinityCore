/*
 * Copyright 2023 AzgathCore
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

#ifndef TEMPLE_OF_SETHRALISS_H
#define TEMPLE_OF_SETHRALISS_H

#define DataHeader "TOS"

uint32 const EncounterCount = 4;

enum EncounterData
{
    DATA_ADDERIS_AND_ASPIX      = 0,
    DATA_MEREKTHA               = 1,
    DATA_GALVAZZT               = 2,
    DATA_AVATAR_OF_SETHRALISS   = 3,
};

enum CreatureIds
{
    NPC_ADDERIS                 = 133379,
    NPC_ASPIX                   = 133944,
    NPC_MEREKTHA                = 133384,
    NPC_SAND_CRUSHED_STRIKER    = 134390,
    NPC_SAND_CRUSTED_STRIKER_2  = 135846,
    NPC_GALVAZZT                = 133389,
    NPC_CHAOTIC_SPARK           = 135456,
    NPC_ENERGY_CORE             = 135445,
    NPC_AVATAR_OF_SETHRALISS    = 133392,
    NPC_HOODOO_HEXER            = 136250,
    NPC_PLAGUE_DOCTOR           = 139949,
    NPC_HEART_GUARDIAN          = 139946,
    NPC_PLAGUE_TOAD             = 137233,
};

enum Gameobjects
{
    GO_SETHRALISS_TREASURE = 288640,
    GO_CHALLENGERS_CACHE_SETHRALISS = 290758,
    GO_ADDERIS_ASPIX_EXIT = 292551,
    GO_MEREKTHA_EXIT = 290906,
    GO_GALVAZZT_EXIT = 292414,
};

#endif // TEMPLE_OF_SETHRALISS_H
