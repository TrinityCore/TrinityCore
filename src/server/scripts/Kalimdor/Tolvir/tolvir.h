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

#ifndef DEF_TOLVIR_H
#define DEF_TOLVIR_H

enum TolvirBosses
{
    BOSS_GENERAL_HUSAM          = 0,
    BOSS_HIGH_PROPHET_BARIM     = 1,
    BOSS_LOCKMAW                = 2,
    BOSS_SIAMAT                 = 3,

    BOSS_AUGH                   = 4,

    MAX_ENCOUNTER               = 5,
};

enum TolvirNPCs
{
    // General Husam
    NPC_GENERAL_HUSAM           = 44577,

    // High Prophet Barim
    NPC_HIGH_PROPHET_BARIM      = 43612,

    // Lockmaw and Augh
    NPC_LOCKMAW                 = 43614,
    NPC_AUGH                    = 49045,

    // Siamat
    NPC_SIAMAT                  = 44819,
};

#endif
