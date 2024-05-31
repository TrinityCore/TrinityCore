/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef TRINITYCORE_ISLE_OF_CONQUEST_H
#define TRINITYCORE_ISLE_OF_CONQUEST_H

enum CreaturesIC
{
    NPC_HIGH_COMMANDER_HALFORD_WYRMBANE     = 34924, // Alliance Boss
    NPC_OVERLORD_AGMAR                      = 34922, // Horde Boss
    NPC_KOR_KRON_GUARD                      = 34918, // horde guard
    NPC_SEVEN_TH_LEGION_INFANTRY            = 34919, // alliance guard
    NPC_KEEP_CANNON                         = 34944,
    NPC_DEMOLISHER                          = 34775,
    NPC_SIEGE_ENGINE_H                      = 35069,
    NPC_SIEGE_ENGINE_A                      = 34776,
    NPC_GLAIVE_THROWER_A                    = 34802,
    NPC_GLAIVE_THROWER_H                    = 35273,
    NPC_CATAPULT                            = 34793,
    NPC_HORDE_GUNSHIP_CANNON                = 34935,
    NPC_ALLIANCE_GUNSHIP_CANNON             = 34929,
    NPC_HORDE_GUNSHIP_CAPTAIN               = 35003,
    NPC_ALLIANCE_GUNSHIP_CAPTAIN            = 34960,
    NPC_WORLD_TRIGGER_NOT_FLOATING          = 34984,
    NPC_WORLD_TRIGGER_ALLIANCE_FRIENDLY     = 20213,
    NPC_WORLD_TRIGGER_HORDE_FRIENDLY        = 20212
};

enum Actions
{
    ACTION_GUNSHIP_READY                    = 1,
    ACTION_IOC_INTERACT_CAPTURABLE_OBJECT   = 2,
    ACTION_IOC_CAPTURE_CAPTURABLE_OBJECT    = 3
};

enum Spells
{
    SPELL_OIL_REFINERY                      = 68719,
    SPELL_QUARRY                            = 68720,
    SPELL_PARACHUTE                         = 66656,
    SPELL_SLOW_FALL                         = 12438,
    SPELL_DESTROYED_VEHICLE_ACHIEVEMENT     = 68357,
    SPELL_BACK_DOOR_JOB_ACHIEVEMENT         = 68502,
    SPELL_DRIVING_CREDIT_DEMOLISHER         = 68365,
    SPELL_DRIVING_CREDIT_GLAIVE             = 68363,
    SPELL_DRIVING_CREDIT_SIEGE              = 68364,
    SPELL_DRIVING_CREDIT_CATAPULT           = 68362,
    SPELL_SIMPLE_TELEPORT                   = 12980,
    SPELL_TELEPORT_VISUAL_ONLY              = 51347,
    SPELL_PARACHUTE_IC                      = 66657,
    SPELL_LAUNCH_NO_FALLING_DAMAGE          = 66251
};

enum ICWorldStates
{
    BG_IC_ALLIANCE_REINFORCEMENTS_SET   = 4221,
    BG_IC_HORDE_REINFORCEMENTS_SET      = 4222,
    BG_IC_ALLIANCE_REINFORCEMENTS       = 4226,
    BG_IC_HORDE_REINFORCEMENTS          = 4227,
    BG_IC_MAX_REINFORCEMENTS            = 17377,

    BG_IC_GATE_FRONT_H_WS_CLOSED        = 4317,
    BG_IC_GATE_WEST_H_WS_CLOSED         = 4318,
    BG_IC_GATE_EAST_H_WS_CLOSED         = 4319,
    BG_IC_GATE_FRONT_A_WS_CLOSED        = 4328,
    BG_IC_GATE_WEST_A_WS_CLOSED         = 4327,
    BG_IC_GATE_EAST_A_WS_CLOSED         = 4326,
    BG_IC_GATE_FRONT_H_WS_OPEN          = 4322,
    BG_IC_GATE_WEST_H_WS_OPEN           = 4321,
    BG_IC_GATE_EAST_H_WS_OPEN           = 4320,
    BG_IC_GATE_FRONT_A_WS_OPEN          = 4323,
    BG_IC_GATE_WEST_A_WS_OPEN           = 4324,
    BG_IC_GATE_EAST_A_WS_OPEN           = 4325,

    BG_IC_DOCKS_UNCONTROLLED            = 4301,
    BG_IC_DOCKS_CONFLICT_A              = 4305,
    BG_IC_DOCKS_CONFLICT_H              = 4302,
    BG_IC_DOCKS_CONTROLLED_A            = 4304,
    BG_IC_DOCKS_CONTROLLED_H            = 4303,

    BG_IC_HANGAR_UNCONTROLLED           = 4296,
    BG_IC_HANGAR_CONFLICT_A             = 4300,
    BG_IC_HANGAR_CONFLICT_H             = 4297,
    BG_IC_HANGAR_CONTROLLED_A           = 4299,
    BG_IC_HANGAR_CONTROLLED_H           = 4298,

    BG_IC_QUARRY_UNCONTROLLED           = 4306,
    BG_IC_QUARRY_CONFLICT_A             = 4310,
    BG_IC_QUARRY_CONFLICT_H             = 4307,
    BG_IC_QUARRY_CONTROLLED_A           = 4309,
    BG_IC_QUARRY_CONTROLLED_H           = 4308,

    BG_IC_REFINERY_UNCONTROLLED         = 4311,
    BG_IC_REFINERY_CONFLICT_A           = 4315,
    BG_IC_REFINERY_CONFLICT_H           = 4312,
    BG_IC_REFINERY_CONTROLLED_A         = 4314,
    BG_IC_REFINERY_CONTROLLED_H         = 4313,

    BG_IC_WORKSHOP_UNCONTROLLED         = 4294,
    BG_IC_WORKSHOP_CONFLICT_A           = 4228,
    BG_IC_WORKSHOP_CONFLICT_H           = 4293,
    BG_IC_WORKSHOP_CONTROLLED_A         = 4229,
    BG_IC_WORKSHOP_CONTROLLED_H         = 4230,

    BG_IC_ALLIANCE_KEEP_UNCONTROLLED    = 4341,
    BG_IC_ALLIANCE_KEEP_CONFLICT_A      = 4342,
    BG_IC_ALLIANCE_KEEP_CONFLICT_H      = 4343,
    BG_IC_ALLIANCE_KEEP_CONTROLLED_A    = 4339,
    BG_IC_ALLIANCE_KEEP_CONTROLLED_H    = 4340,

    BG_IC_HORDE_KEEP_UNCONTROLLED       = 4346,
    BG_IC_HORDE_KEEP_CONFLICT_A         = 4347,
    BG_IC_HORDE_KEEP_CONFLICT_H         = 4348,
    BG_IC_HORDE_KEEP_CONTROLLED_A       = 4344,
    BG_IC_HORDE_KEEP_CONTROLLED_H       = 4345
};

#endif
