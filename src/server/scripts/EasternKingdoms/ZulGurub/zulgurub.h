/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_ZULGURUB_H
#define DEF_ZULGURUB_H

uint32 const EncounterCount = 13;

enum DataTypes
{
    DATA_JEKLIK             = 0,  // Main boss
    DATA_VENOXIS            = 1,  // Main boss
    DATA_MARLI              = 2,  // Main boss
    DATA_ARLOKK             = 3,  // Main boss
    DATA_HAKKAR             = 4,  // Main boss
    DATA_MANDOKIR           = 5,  // Optional boss
    DATA_JINDO              = 6,  // Optional boss
    DATA_GAHZRANKA          = 7,  // Optional boss
    DATA_EDGE_OF_MADNESS    = 8,  // Optional Event Edge of Madness - one of: Gri'lek, Renataki, Hazza'rah, or Wushoolay
    DATA_THEKAL             = 9,  // ??
    DATA_LORKHAN            = 10, // ??
    DATA_ZATH               = 11, // ??
    DATA_OHGAN              = 12  // ??
};

enum CreatureIds
{
    NPC_ZEALOT_LORKHAN      = 11347,
    NPC_ZEALOT_ZATH         = 11348,
    NPC_HIGH_PRIEST_THEKAL  = 14509,
    NPC_JINDO_THE_HEXXER    = 11380,
    NPC_NIGHTMARE_ILLUSION  = 15163
};

#endif
