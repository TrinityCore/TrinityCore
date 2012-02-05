/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_BLACKWING_DESCENT_H
#define DEF_BLACKWING_DESCENT_H

enum BlackwingDescentBosses
{
    BOSS_MAGMAW                     = 0,
    BOSS_OMNOTRON_DEFENSE_SYSTEM    = 1,
    BOSS_MALORIAK                   = 2,
    BOSS_ATRAMEDES                 = 3,
    BOSS_CHIMAERON                  = 4,
    BOSS_NEFARIAN                   = 5,

    BOSS_ARCANOTRON                 = 6,
    BOSS_ELECTRON                   = 7,
    BOSS_MAGMATRON                  = 8,
    BOSS_TOXITRON                   = 9,

    MAX_ENCOUNTER                   = 10,
};

enum BlackwingDescentNPCs
{
    // Magmaw
    NPC_MAGMAW                      = 41570,

    // Omnotron Defense System
    NPC_ARCANOTRON                  = 42166,
    NPC_ELECTRON                    = 42179,
    NPC_MAGMATRON                   = 42178,
    NPC_TOXITRON                    = 42180,

    // Maloriak
    NPC_MALORIAK                    = 41378,

    // Atramedes
    NPC_ATRAMEDES                  = 41442,

    // Chimaeron
    NPC_CHIMAERON                   = 43296,

    // Nefarian
    NPC_NEFARIAN                    = 41376,
    NPC_ONYXIA                      = 41270,
};

#endif
