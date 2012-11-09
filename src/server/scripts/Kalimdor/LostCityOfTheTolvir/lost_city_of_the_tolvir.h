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
 
#ifndef DEF_LOST_CITY_OF_THE_TOLVIR_H
#define DEF_LOST_CITY_OF_THE_TOLVIR_H

enum Data
{
    DATA_GENERAL_HUSAM_EVENT,
    DATA_HIGH_PROPHET_BARIM_EVENT,
    DATA_LOCKMAW_EVENT,
    DATA_AUGH_EVENT,
    DATA_SIAMAT_EVENT,
    DATA_TEAM_IN_INSTANCE,
};

enum Data64
{
    DATA_GENERAL_HUSAM,
    DATA_HIGH_PROPHET_BARIM,
    DATA_LOCKMAW,
    DATA_AUGH,
    DATA_SIAMAT,
};

enum CreatureIds
{
    // Dungeon Bosses

    BOSS_GENERAL_HUSAM           = 44577,
    BOSS_HIGH_PROPHET_BARIM      = 43612,
    BOSS_LOCKMAW                 = 43614,
    BOSS_AUGH                    = 49045,
    BOSS_SIAMAT                  = 44819,

    // Trash mobs

    NPC_MINION_OF_SIAMAT         = 44704,
    NPC_NEFERSET_DARKCASTER      = 44982,
    NPC_NEFERSET_PLAGUEBRINGER   = 44976,
    NPC_NEFERSET_THEURGIST       = 44980,
    NPC_NEFERSET_TORTURER        = 44977,
    NPC_OATHSWORN_AXEMASTER      = 44922,
    NPC_OATHSWORN_CAPTAIN        = 45122,
    NPC_OATHSWORN_MYRMIDON       = 44924,
    NPC_OATHSWORN_PATHFINDER     = 44932,
    NPC_OATHSWORN_SCORPID_KEEPER = 45062,
    NPC_OATHSWORN_SKINNER        = 44981,
    NPC_OATHSWORN_TAMER          = 45097,
    NPC_WANDERER                 = 44926,
    NPC_PYGMY_BRUTE              = 44896,
    NPC_PYGMY_FIREBREATHER       = 44898,
    NPC_PYGMY_SCOUT              = 44897,
    NPC_SERVANT_OF_SIAMAT        = 45269,

    // Various NPCs

    NPC_CAPTAIN_HADAN            = 50038,
    NPC_WIND_TUNNEL              = 48092,
};

enum GameObjectIds
{
    GO_TOLVIR_GRAVE              = 207409,
};

#endif