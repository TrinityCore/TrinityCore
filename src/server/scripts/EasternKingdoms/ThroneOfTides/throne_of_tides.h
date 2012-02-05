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

#ifndef DEF_THRONE_OF_TIDES_H
#define DEF_THRONE_OF_TIDES_H

enum ThroneOfTidesBosses
{
    BOSS_NAZJAR                 = 0,
    BOSS_COMMANDER_ULTHOK       = 1,
    BOSS_ERUNAK_STONESPEAKER    = 2,
    BOSS_OZUMAT                 = 3,

    MAX_ENCOUNTER               = 4,
};

enum ThroneOfTidesNPCs
{
    // Lady Naz'jar
    NPC_NAZJAR                  = 40586,

    // Commander Ulthok
    NPC_COMMANDER_ULTHOK        = 40765,

    // Erunak Stonespeaker
    NPC_ERUNAK_STONESPEAKER     = 40825,
    NPC_MINDBENDER_GHURSHA      = 40788,

    // Ozumat
    NPC_OZUMAT                  = 42172,
};

#endif
