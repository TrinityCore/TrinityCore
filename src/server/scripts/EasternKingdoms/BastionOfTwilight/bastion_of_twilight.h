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

#ifndef DEF_BASTION_OF_TWILIGHT_H
#define DEF_BASTION_OF_TWILIGHT_H

enum BastionOfTwilightBosses
{
    BOSS_HALFUS_WYRMBREAKER     = 0,
    BOSS_DOUBLE_DRAGON          = 1,
    BOSS_ASCENDANT_COUNCIL      = 2,
    BOSS_CHOGALL                = 3,
    BOSS_SINESTRA               = 4,

    BOSS_VALIONA                = 5,
    BOSS_THERALION              = 6,
    BOSS_FELUDIUS               = 7,
    BOSS_IGNACIOUS              = 8,
    BOSS_ARION                  = 9,
    BOSS_TERRASTRA              = 10,
    BOSS_ELEMENTIUM_MONSTROSITY = 11,

    MAX_ENCOUNTER               = 12,
};

enum BastionOfTwilightNPCs
{
    // Halfus Wyrmbreaker
    NPC_HALFUS_WYRMBREAKER       = 44600,

    // Double Dragon encounter
    NPC_VALIONA                  = 45992,
    NPC_THERALION                = 45993,

    // Ascendant Council
    NPC_FELUDIUS                 = 43687,
    NPC_IGNACIOUS                = 43686,
    NPC_ARION                    = 43688,
    NPC_TERRASTRA                = 43689,
    NPC_ELEMENTIUM_MONSTROSITY   = 43735,

    // Cho'gall
    NPC_CHOGALL                  = 43324,

    // Sinestra
    NPC_SINESTRA                 = 45213,
};

#endif
