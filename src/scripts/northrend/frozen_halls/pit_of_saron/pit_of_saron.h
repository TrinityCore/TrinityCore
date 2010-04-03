/* Copyright (C) 2006 - 2010 TrinityCore <https://www.trinitycore.org/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef DEF_PIT_OF_SARON_H
#define DEF_PIT_OF_SARON_H

enum Data
{
    DATA_GARFROST_EVENT,
    DATA_KRICKANDICK_EVENT,
    DATA_TYRANNUS_EVENT,
    DATA_TEAM_IN_INSTANCE,
};

enum Data64
{
    DATA_GARFROST,
    DATA_KRICK,
    DATA_ICK,
    DATA_TYRANNUS,
    DATA_RIMEFANG,

    DATA_JAINA_SYLVANAS_1,    // GUID of either Jaina or Sylvanas part 1, depending on team, as it's the same spawn.
    DATA_JAINA_SYLVANAS_2,    // GUID of either Jaina or Sylvanas part 2, depending on team, as it's the same spawn.
};

enum Creatures
{
    CREATURE_GARFROST                           = 36494,
    CREATURE_KRICK                              = 36477,
    CREATURE_ICK                                = 36476,
    CREATURE_TYRANNUS                           = 36658,
    CREATURE_RIMEFANG                           = 36661,

    NPC_SYLVANAS_PART1                          = 36990,
    NPC_SYLVANAS_PART2                          = 38189,
    NPC_JAINA_PART1                             = 36993,
    NPC_JAINA_PART2                             = 38188,
    NPC_KILARA                                  = 37583,
    NPC_ELANDRA                                 = 37774,
    NPC_KORALEN                                 = 37779,
    NPC_KORLAEN                                 = 37582,
    NPC_CHAMPION_1_HORDE                        = 37584,
    NPC_CHAMPION_2_HORDE                        = 37587,
    NPC_CHAMPION_3_HORDE                        = 37588,
    NPC_CHAMPION_1_ALLIANCE                     = 37496,
    NPC_CHAMPION_2_ALLIANCE                     = 37497,
};

#endif
