/*
* Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef BATTLE_FOR_UNDERCITY_
#define BATTLE_FOR_UNDERCITY_

enum NPC
{
    // NPCs
    NPC_VARIAN                          = 32401,
    NPC_JAINA_PROUDMORE                 = 32402,
    NPC_SYLVANAS                        = 31651,
    NPC_STORMWIND_ELITE_A               = 32387,
    NPC_ALLIANCE_SIEGE                  = 32389,
    NPC_FLYING_MACHINE                  = 32388,
    NPC_WAVES_TRIGGER                   = 31684
};

enum Mobs
{
    // Alliance
    NPC_TREACHEROUS_GUARDIAN_A          = 32390,
    NPC_DREADLORD_A                     = 32391,
    NPC_FELBEAST_A                      = 32392,
    NPC_MARAUDER_A                      = 32393,
    NPC_BETRAYER_A                      = 32394,
    NPC_CHEMIST_A                       = 32395,
    NPC_COLLABORATOR_A                  = 32396,
    NPC_DOCTOR_A                        = 32397,

    // Horde
    NPC_TREACHEROUS_GUARDIAN_H          = 31532,
    NPC_DREADLORD_H                     = 31531,
    NPC_FELBEAST_H                      = 31528,
    NPC_MARAUDER_H                      = 31527,
    NPC_BETRAYER_H                      = 31529,
    NPC_CHEMIST_H                       = 31482,
    NPC_COLLABORATOR_H                  = 31524,
    NPC_DOCTOR_H                        = 31516,
    NPC_DOOMGUARD_PILLARGER             = 32159,
};

enum Data
{
    DATA_GET_ENEMY                      = 0,
    DATA_DREADLORD_COUNT                = 1
};

enum Worldstates
{
    // Alliance
    WORLDSTATE_UNDERCITY_CONTROLLED_A   = 3963,
    WORLDSTATE_MANHUNT_TIMER_STATE      = 3958,
    WORLDSTATE_MANHUNT_TIMER            = 3957,
    WORLDSTATE_MANHUNT_BEGUN            = 3966,
    WORLDSTATE_BATTLING_SEWERS          = 3962,
    WORLDSTATE_SECURED_SEWERS           = 3964,
    WORLDSTATE_BATTLING_APOTHECARIUM    = 3972,
    WORLDSTATE_SECURED_APOTHECARIUM     = 3971,

    // Horde
    WORLDSTATE_UNDERCITY_CONTROLLED_H   = 3878,
    WORLDSTATE_BATTLE_TIMER_STATE       = 3876,
    WORLDSTATE_BATTLE_TIMER             = 3877,
    WORLDSTATE_BATTLE_BEGUN             = 3875,
    WORLDSTATE_BATTLING_COURTYARD       = 3885,
    WORLDSTATE_CONTROLL_COURTYARD       = 3886,
    WORLDSTATE_BATTLING_INNER_SANCTUM   = 3887,
    WORLDSTATE_CONTROLL_INNER_SANCTUM   = 3888,
    WORLDSTATE_BATTLING_ROYAL_QUARTER   = 3889,
    WORLDSTATE_CONTROLL_ROYAL_QUARTER   = 3890,
    WORLDSTATE_RESET_BATTLE             = 3894,
    WORLDSTATE_RESET_TIMER              = 3893
};

enum BattlingAreas
{
    // Alliance
    SEWERS                              = 0,
    APOTHECARIUM,

    // Horde
    COURTYARD,
    INNER_SANCTUM,
    ROYAL_QUARTER,

    MAX_BATTLING_AREAS
};

enum Zones
{
    ZONE_TRISFAL_GLADES                 = 85,
    ZONE_UNDERCITY                      = 1497
};

#endif // BATTLE_FOR_UNDERCITY_
