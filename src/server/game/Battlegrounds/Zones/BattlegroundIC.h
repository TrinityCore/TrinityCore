/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef __BATTLEGROUNDIC_H
#define __BATTLEGROUNDIC_H

#include "Battleground.h"
#include "BattlegroundScore.h"
#include "EventMap.h"
#include "Language.h"
#include "Object.h"

enum creaturesIC
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

enum gameobjectsIC
{
    GO_ALLIANCE_GATE_1                          = 195699,
    GO_ALLIANCE_GATE_2                          = 195698,
    GO_ALLIANCE_GATE_3                          = 195700,

    GO_ALLIANCE_GUNSHIP_PORTAL                  = 195320,

    GO_ALLIANCE_GUNSHIP_PORTAL_EFFECTS          = 195705,

    GO_BENCH_1                                  = 186896,
    GO_BENCH_2                                  = 186922,
    GO_BENCH_3                                  = 186899,
    GO_BENCH_4                                  = 186904,
    GO_BENCH_5                                  = 186897,

    GO_BONFIRE_1                                = 195376,
    GO_BONFIRE_2                                = 195208,
    GO_BONFIRE_3                                = 195210,
    GO_BONFIRE_4                                = 195207,
    GO_BONFIRE_5                                = 195209,
    GO_BONFIRE_6                                = 195377,

    GO_DOODAD_HU_PORTCULLIS01                   = 195436,
    GO_DOODAD_VR_PORTCULLIS01                   = 195437,

    GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01     = 195703,

    GO_DOODAD_PORTCULLISACTIVE01                = 195451,
    GO_DOODAD_PORTCULLISACTIVE02                = 195452,

    GO_CHAIR_1                                  = 195410,
    GO_CHAIR_2                                  = 195414,
    GO_CHAIR_3                                  = 160415,
    GO_CHAIR_4                                  = 195418,
    GO_CHAIR_5                                  = 195416,
    GO_CHAIR_6                                  = 160410,
    GO_CHAIR_7                                  = 160418,
    GO_CHAIR_8                                  = 160416,
    GO_CHAIR_9                                  = 160419,

    GO_FLAGPOLE_1                               = 195131,
    GO_FLAGPOLE_2                               = 195439,

    GO_HORDE_GATE_1                             = 195494,
    GO_HORDE_GATE_2                             = 195496,
    GO_HORDE_GATE_3                             = 195495,

    GO_HORDE_GUNSHIP_PORTAL                     = 195326,

    GO_HORDE_GUNSHIP_PORTAL_EFFECTS             = 195706,

    GO_HORDE_KEEP_PORTCULLIS                    = 195223,

    GO_HUGE_SEAFORIUM_BOMB_A                    = 195332,
    GO_HUGE_SEAFORIUM_BOMB_H                    = 195333,
    GO_SEAFORIUM_BOMBS                          = 195237,

    GO_STOVE_1                                  = 174863,
    GO_STOVE_2                                  = 160411,

    GO_TELEPORTER_1                             = 195314, // 195314 H-OUT 66549
    GO_TELEPORTER_2                             = 195313, // 195313 H-IN 66548

    GO_TELEPORTER_3                             = 195315, // 195315 A-OUT 66549
    GO_TELEPORTER_4                             = 195316, // 195316 A-IN 66548

    GO_TELEPORTER_EFFECTS_A                     = 195701,
    GO_TELEPORTER_EFFECTS_H                     = 195702,

    GO_BRAZIER_1                                = 195402,
    GO_BRAZIER_2                                = 195403,
    GO_BRAZIER_3                                = 195425,
    GO_BRAZIER_4                                = 195424,

    GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01   = 195491,

    GO_HANGAR_BANNER                            = 195158,
    GO_ALLIANCE_BANNER_HANGAR                   = 195153,
    GO_ALLIANCE_BANNER_HANGAR_CONT              = 195154,
    GO_HORDE_BANNER_HANGAR                      = 195155,
    GO_HORDE_BANNER_HANGAR_CONT                 = 195156,

    GO_WORKSHOP_BANNER                          = 195133,
    GO_ALLIANCE_BANNER_WORKSHOP                 = 195132,
    GO_ALLIANCE_BANNER_WORKSHOP_CONT            = 195144,
    GO_HORDE_BANNER_WORKSHOP                    = 195130,
    GO_HORDE_BANNER_WORKSHOP_CONT               = 195145,

    GO_QUARRY_BANNER                            = 195338,
    GO_ALLIANCE_BANNER_QUARRY                   = 195334,
    GO_ALLIANCE_BANNER_QUARRY_CONT              = 195335,
    GO_HORDE_BANNER_QUARRY                      = 195336,
    GO_HORDE_BANNER_QUARRY_CONT                 = 195337,

    GO_REFINERY_BANNER                          = 195343,
    GO_ALLIANCE_BANNER_REFINERY                 = 195339,
    GO_ALLIANCE_BANNER_REFINERY_CONT            = 195340,
    GO_HORDE_BANNER_REFINERY                    = 195341,
    GO_HORDE_BANNER_REFINERY_CONT               = 195342,

    GO_DOCKS_BANNER                             = 195157,
    GO_ALLIANCE_BANNER_DOCKS                    = 195149,
    GO_ALLIANCE_BANNER_DOCKS_CONT               = 195150,
    GO_HORDE_BANNER_DOCKS                       = 195151,
    GO_HORDE_BANNER_DOCKS_CONT                  = 195152,

    GO_ALLIANCE_BANNER_GRAVEYARD_A              = 195396,
    GO_ALLIANCE_BANNER_GRAVEYARD_A_CONT         = 195397,
    GO_HORDE_BANNER_GRAVEYARD_A                 = 195398,
    GO_HORDE_BANNER_GRAVEYARD_A_CONT            = 195399,

    GO_ALLIANCE_BANNER_GRAVEYARD_H              = 195391,
    GO_ALLIANCE_BANNER_GRAVEYARD_H_CONT         = 195392,
    GO_HORDE_BANNER_GRAVEYARD_H                 = 195393,
    GO_HORDE_BANNER_GRAVEYARD_H_CONT            = 195394,

    GO_HORDE_GUNSHIP                            = 195276,
    GO_ALLIANCE_GUNSHIP                         = 195121
};

enum Times
{
    WORKSHOP_UPDATE_TIME     = 3 * MINUTE * IN_MILLISECONDS, // 3 minutes
    DOCKS_UPDATE_TIME        = 3 * MINUTE * IN_MILLISECONDS, // not sure if it is 3 minutes
    IC_RESOURCE_TIME         = 45 * IN_MILLISECONDS, // not sure, need more research
    CLOSE_DOORS_TIME         = 30 * IN_MILLISECONDS,
    DESPAWN_FAKE_DOORS_TIME  = 6 * IN_MILLISECONDS,
    BANNER_STATE_CHANGE_TIME = 1 * MINUTE * IN_MILLISECONDS,
    TRANSPORT_PERIOD_TIME    = 2 * MINUTE * IN_MILLISECONDS
};

enum Actions
{
    ACTION_GUNSHIP_READY = 1
};

enum BG_IC_GOs
{
    BG_IC_GO_ALLIANCE_GATE_1 = 0,
    BG_IC_GO_ALLIANCE_GATE_2,
    BG_IC_GO_ALLIANCE_GATE_3,

    BG_IC_GO_HORDE_GATE_1,
    BG_IC_GO_HORDE_GATE_2,
    BG_IC_GO_HORDE_GATE_3,

    BG_IC_GO_REFINERY_BANNER_N,
    BG_IC_GO_QUARRY_BANNER_N,
    BG_IC_GO_DOCKS_BANNER_N,
    BG_IC_GO_HANGAR_BANNER_N,
    BG_IC_GO_WORKSHOP_BANNER_N,

    BG_IC_GO_REFINERY_BANNER_A,
    BG_IC_GO_QUARRY_BANNER_A,
    BG_IC_GO_DOCKS_BANNER_A,
    BG_IC_GO_HANGAR_BANNER_A,
    BG_IC_GO_WORKSHOP_BANNER_A,
    BG_IC_GO_ALLIANCE_GRAVEYARD_A,
    BG_IC_GO_HORDE_GRAVEYARD_A,

    BG_IC_GO_REFINERY_BANNER_CONT_A,
    BG_IC_GO_QUARRY_BANNER_CONT_A,
    BG_IC_GO_DOCKS_BANNER_CONT_A,
    BG_IC_GO_HANGAR_BANNER_CONT_A,
    BG_IC_GO_WORKSHOP_BANNER_CONT_A,
    BG_IC_GO_ALLIANCE_GRAVEYARD_CONT_A,
    BG_IC_GO_HORDE_GRAVEYARD_CONT_A,

    BG_IC_GO_REFINERY_BANNER_CONT_H,
    BG_IC_GO_QUARRY_BANNER_CONT_H,
    BG_IC_GO_DOCKS_BANNER_CONT_H,
    BG_IC_GO_HANGAR_BANNER_CONT_H,
    BG_IC_GO_WORKSHOP_BANNER_CONT_H,
    BG_IC_GO_ALLIANCE_GRAVEYARD_CONT_H,
    BG_IC_GO_HORDE_GRAVEYARD_CONT_H,

    BG_IC_GO_REFINERY_BANNER_H,
    BG_IC_GO_QUARRY_BANNER_H,
    BG_IC_GO_DOCKS_BANNER_H,
    BG_IC_GO_HANGAR_BANNER_H,
    BG_IC_GO_WORKSHOP_BANNER_H,
    BG_IC_GO_ALLIANCE_GRAVEYARD_H,
    BG_IC_GO_HORDE_GRAVEYARD_H,

    BG_IC_GO_BENCH_1,
    BG_IC_GO_BENCH_2,
    BG_IC_GO_BENCH_3,
    BG_IC_GO_BENCH_4,
    BG_IC_GO_BENCH_5,

    BG_IC_GO_BONFIRE_1,
    BG_IC_GO_BONFIRE_2,
    BG_IC_GO_BONFIRE_3,
    BG_IC_GO_BONFIRE_4,
    BG_IC_GO_BONFIRE_5,
    BG_IC_GO_BONFIRE_6,

    BG_IC_GO_BRAZIER_1,
    BG_IC_GO_BRAZIER_2,
    BG_IC_GO_BRAZIER_3,
    BG_IC_GO_BRAZIER_4,

    BG_IC_GO_CHAIR_1,
    BG_IC_GO_CHAIR_2,
    BG_IC_GO_CHAIR_3_1,
    BG_IC_GO_CHAIR_4,
    BG_IC_GO_CHAIR_5,
    BG_IC_GO_CHAIR_6_1,
    BG_IC_GO_CHAIR_7,
    BG_IC_GO_CHAIR_3_2,
    BG_IC_GO_CHAIR_6_2,
    BG_IC_GO_CHAIR_8_1,
    BG_IC_GO_CHAIR_8_2,
    BG_IC_GO_CHAIR_9,

    BG_IC_GO_DOODAD_HU_PORTCULLIS01_1,
    BG_IC_GO_DOODAD_HU_PORTCULLIS01_2,

    BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01,
    BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR02,
    BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR03,

    BG_IC_GO_DOODAD_PORTCULLISACTIVE01,
    BG_IC_GO_DOODAD_PORTCULLISACTIVE02,

    BG_IC_GO_DOODAD_VR_PORTCULLIS01_1,
    BG_IC_GO_DOODAD_VR_PORTCULLIS01_2,

    BG_IC_GO_FLAGPOLE_1_1,
    BG_IC_GO_FLAGPOLE_2_1,
    BG_IC_GO_FLAGPOLE_2_2,
    BG_IC_GO_FLAGPOLE_1_2,
    BG_IC_GO_FLAGPOLE_1_3,
    BG_IC_GO_FLAGPOLE_1_4,
    BG_IC_GO_FLAGPOLE_1_5,

    BG_IC_GO_HORDE_KEEP_PORTCULLIS,

    BG_IC_GO_STOVE_1_1,
    BG_IC_GO_STOVE_2_1,
    BG_IC_GO_STOVE_1_2,
    BG_IC_GO_STOVE_2_2,

    BG_IC_GO_HUGE_SEAFORIUM_BOMBS_A_1,
    BG_IC_GO_HUGE_SEAFORIUM_BOMBS_A_2,
    BG_IC_GO_HUGE_SEAFORIUM_BOMBS_A_3,
    BG_IC_GO_HUGE_SEAFORIUM_BOMBS_A_4,

    BG_IC_GO_HUGE_SEAFORIUM_BOMBS_H_1,
    BG_IC_GO_HUGE_SEAFORIUM_BOMBS_H_2,
    BG_IC_GO_HUGE_SEAFORIUM_BOMBS_H_3,
    BG_IC_GO_HUGE_SEAFORIUM_BOMBS_H_4,

    BG_IC_GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01,
    BG_IC_GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR02,
    BG_IC_GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR03,

    BG_IC_GO_SEAFORIUM_BOMBS_1,
    BG_IC_GO_SEAFORIUM_BOMBS_2,

    BG_IC_GO_HANGAR_TELEPORTER_1_A,
    BG_IC_GO_HANGAR_TELEPORTER_1_H,
    BG_IC_GO_HANGAR_TELEPORTER_2_A,
    BG_IC_GO_HANGAR_TELEPORTER_2_H,
    BG_IC_GO_HANGAR_TELEPORTER_3_A,
    BG_IC_GO_HANGAR_TELEPORTER_3_H,

    BG_IC_GO_HANGAR_TELEPORTER_EFFECT_1_A,
    BG_IC_GO_HANGAR_TELEPORTER_EFFECT_1_H,
    BG_IC_GO_HANGAR_TELEPORTER_EFFECT_2_A,
    BG_IC_GO_HANGAR_TELEPORTER_EFFECT_2_H,
    BG_IC_GO_HANGAR_TELEPORTER_EFFECT_3_A,
    BG_IC_GO_HANGAR_TELEPORTER_EFFECT_3_H,

    BG_IC_GO_TELEPORTER_1_1,
    BG_IC_GO_TELEPORTER_1_2,
    BG_IC_GO_TELEPORTER_2_1,
    BG_IC_GO_TELEPORTER_3_1,
    BG_IC_GO_TELEPORTER_2_2,
    BG_IC_GO_TELEPORTER_4_1,
    BG_IC_GO_TELEPORTER_3_2,
    BG_IC_GO_TELEPORTER_3_3,
    BG_IC_GO_TELEPORTER_4_2,
    BG_IC_GO_TELEPORTER_4_3,
    BG_IC_GO_TELEPORTER_1_3,
    BG_IC_GO_TELEPORTER_2_3,

    BG_IC_GO_TELEPORTER_EFFECTS_A_1,
    BG_IC_GO_TELEPORTER_EFFECTS_A_2,
    BG_IC_GO_TELEPORTER_EFFECTS_A_3,
    BG_IC_GO_TELEPORTER_EFFECTS_A_4,
    BG_IC_GO_TELEPORTER_EFFECTS_A_5,
    BG_IC_GO_TELEPORTER_EFFECTS_A_6,

    BG_IC_GO_TELEPORTER_EFFECTS_H_1,
    BG_IC_GO_TELEPORTER_EFFECTS_H_2,
    BG_IC_GO_TELEPORTER_EFFECTS_H_3,
    BG_IC_GO_TELEPORTER_EFFECTS_H_4,
    BG_IC_GO_TELEPORTER_EFFECTS_H_5,
    BG_IC_GO_TELEPORTER_EFFECTS_H_6,

    BG_IC_GO_MAX
};

enum BG_IC_NPCs
{
    BG_IC_NPC_OVERLORD_AGMAR = 0,
    BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE,
    BG_IC_NPC_KOR_KRON_GUARD_1,
    BG_IC_NPC_KOR_KRON_GUARD_2,
    BG_IC_NPC_KOR_KRON_GUARD_3,
    BG_IC_NPC_KOR_KRON_GUARD_4,
    BG_IC_NPC_SEVEN_TH_LEGION_INFANTRY_1,
    BG_IC_NPC_SEVEN_TH_LEGION_INFANTRY_2,
    BG_IC_NPC_SEVEN_TH_LEGION_INFANTRY_3,
    BG_IC_NPC_SEVEN_TH_LEGION_INFANTRY_4,
    BG_IC_NPC_KEEP_CANNON_1,
    BG_IC_NPC_KEEP_CANNON_2,
    BG_IC_NPC_KEEP_CANNON_3,
    BG_IC_NPC_KEEP_CANNON_4,
    BG_IC_NPC_KEEP_CANNON_5,
    BG_IC_NPC_KEEP_CANNON_6,
    BG_IC_NPC_KEEP_CANNON_7,
    BG_IC_NPC_KEEP_CANNON_8,
    BG_IC_NPC_KEEP_CANNON_9,
    BG_IC_NPC_KEEP_CANNON_10,
    BG_IC_NPC_KEEP_CANNON_11,
    BG_IC_NPC_KEEP_CANNON_12,
    BG_IC_NPC_KEEP_CANNON_13,
    BG_IC_NPC_KEEP_CANNON_14,
    BG_IC_NPC_KEEP_CANNON_15,
    BG_IC_NPC_KEEP_CANNON_16,
    BG_IC_NPC_KEEP_CANNON_17,
    BG_IC_NPC_KEEP_CANNON_18,
    BG_IC_NPC_KEEP_CANNON_19,
    BG_IC_NPC_KEEP_CANNON_20,
    BG_IC_NPC_KEEP_CANNON_21,
    BG_IC_NPC_KEEP_CANNON_22,
    BG_IC_NPC_KEEP_CANNON_23,
    BG_IC_NPC_KEEP_CANNON_24,

    BG_IC_NPC_SIEGE_ENGINE_A,
    BG_IC_NPC_SIEGE_ENGINE_H,

    BG_IC_NPC_DEMOLISHER_1_A,
    BG_IC_NPC_DEMOLISHER_2_A,
    BG_IC_NPC_DEMOLISHER_3_A,
    BG_IC_NPC_DEMOLISHER_4_A,

    BG_IC_NPC_DEMOLISHER_1_H,
    BG_IC_NPC_DEMOLISHER_2_H,
    BG_IC_NPC_DEMOLISHER_3_H,
    BG_IC_NPC_DEMOLISHER_4_H,

    BG_IC_NPC_GLAIVE_THROWER_1_A,
    BG_IC_NPC_GLAIVE_THROWER_2_A,
    BG_IC_NPC_GLAIVE_THROWER_1_H,
    BG_IC_NPC_GLAIVE_THROWER_2_H,

    BG_IC_NPC_CATAPULT_1_A,
    BG_IC_NPC_CATAPULT_2_A,
    BG_IC_NPC_CATAPULT_3_A,
    BG_IC_NPC_CATAPULT_4_A,

    BG_IC_NPC_CATAPULT_1_H,
    BG_IC_NPC_CATAPULT_2_H,
    BG_IC_NPC_CATAPULT_3_H,
    BG_IC_NPC_CATAPULT_4_H,

    BG_IC_NPC_WORLD_TRIGGER_NOT_FLOATING,
    BG_IC_NPC_GUNSHIP_CAPTAIN_1,
    BG_IC_NPC_GUNSHIP_CAPTAIN_2,

    BG_IC_NPC_SPIRIT_GUIDE_1,
    BG_IC_NPC_SPIRIT_GUIDE_2,
    BG_IC_NPC_SPIRIT_GUIDE_3,
    BG_IC_NPC_SPIRIT_GUIDE_4,
    BG_IC_NPC_SPIRIT_GUIDE_5,
    BG_IC_NPC_SPIRIT_GUIDE_6,
    BG_IC_NPC_SPIRIT_GUIDE_7,

    BG_IC_NPC_MAX
};

enum BG_IC_MaxSpawns
{
    MAX_NORMAL_NPCS_SPAWNS                              = BG_IC_NPC_KEEP_CANNON_24 + 1,
    MAX_WORKSHOP_SPAWNS                                 = 10,
    MAX_DOCKS_SPAWNS                                    = 12,
    MAX_SPIRIT_GUIDES_SPAWNS                            = 7,
    MAX_HANGAR_TELEPORTERS_SPAWNS                       = 6,
    MAX_HANGAR_TELEPORTER_EFFECTS_SPAWNS                = 6,
    MAX_AIRSHIPS_SPAWNS                                 = 2,
    MAX_FORTRESS_GATES_SPAWNS                           = 6,
    MAX_FORTRESS_TELEPORTERS_SPAWNS                     = 12,
    MAX_FORTRESS_TELEPORTER_EFFECTS_SPAWNS              = 12,
    MAX_HANGAR_NPCS_SPAWNS                              = 3,

    // docks
    MAX_GLAIVE_THROWERS_SPAWNS_PER_FACTION              = 2,
    MAX_CATAPULTS_SPAWNS_PER_FACTION                    = 4,

    // workshop
    MAX_DEMOLISHERS_SPAWNS_PER_FACTION                  = 4,
    MAX_WORKSHOP_BOMBS_SPAWNS_PER_FACTION               = 2,

    // Hangar
    MAX_TRIGGER_SPAWNS_PER_FACTION                      = 1,
    MAX_CAPTAIN_SPAWNS_PER_FACTION                      = 2,
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

enum BG_IC_Objectives
{
    IC_OBJECTIVE_ASSAULT_BASE   = 245,
    IC_OBJECTIVE_DEFEND_BASE    = 246
};

enum ICWorldStates
{
    BG_IC_WS_REINFORCEMENTS_SHOW_A      = 4221,
    BG_IC_WS_REINFORCEMENTS_SHOW_H      = 4222,
    BG_IC_WS_ALLIANCE_REINFORCEMENTS    = 4226,
    BG_IC_WS_HORDE_REINFORCEMENTS       = 4227,
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

enum BG_IC_GateState
{
    BG_IC_GATE_OK           = 1,
    BG_IC_GATE_DAMAGED      = 2,
    BG_IC_GATE_DESTROYED    = 3
};

enum ICDoorList
{
    BG_IC_A_FRONT,
    BG_IC_A_EAST,
    BG_IC_A_WEST,
    BG_IC_H_WEST,
    BG_IC_H_FRONT,
    BG_IC_H_EAST,
    BG_IC_MAXDOOR
};

enum ICNodePointType
{
    NODE_TYPE_REFINERY,
    NODE_TYPE_QUARRY,
    NODE_TYPE_DOCKS,
    NODE_TYPE_HANGAR,
    NODE_TYPE_WORKSHOP,

    // Graveyards
    NODE_TYPE_GRAVEYARD_A,
    NODE_TYPE_GRAVEYARD_H,

    MAX_NODE_TYPES
};

enum ICNodeState : uint8
{
    NODE_STATE_UNCONTROLLED = 0,
    NODE_STATE_CONFLICT_A,
    NODE_STATE_CONFLICT_H,
    NODE_STATE_CONTROLLED_A,
    NODE_STATE_CONTROLLED_H,

    NODE_STATE_MAX
};

// I.E: Hangar, Quarry, Graveyards .. etc
struct ICNodePoint
{
    uint32 gameobjectId;                            // what gameobject type is active here.
    uint32 gameobject_entry;                        // what gameobject entry is active here.
    TeamId faction;                                 // who has this node
    ICNodePointType nodeType;                       // here we can specify if it is graveyards, hangar etc...
    uint32 bannerIds[NODE_STATE_MAX];               // the banners that have this point
    bool needChange;                                // this is used for the 1 minute time period after the point is captured
    uint32 timer;                                   // the same use for needChange
    uint32 last_entry;                              // the last gameobject_entry
    uint32 worldStates[NODE_STATE_MAX];             // the worldstates that represent the node in the map
    ICNodeState nodeState;
    TrinityStrings string;
};

enum HonorRewards
{
    RESOURCE_HONOR_AMOUNT   = 12,
    WINNER_HONOR_AMOUNT     = 500
};

struct BattlegroundICScore final : public BattlegroundScore
{
    friend class BattlegroundIC;

    protected:
        BattlegroundICScore(ObjectGuid playerGuid) : BattlegroundScore(playerGuid), BasesAssaulted(0), BasesDefended(0) { }

        void UpdateScore(uint32 type, uint32 value) override
        {
            switch (type)
            {
                case SCORE_BASES_ASSAULTED:
                    BasesAssaulted += value;
                    break;
                case SCORE_BASES_DEFENDED:
                    BasesDefended += value;
                    break;
                default:
                    BattlegroundScore::UpdateScore(type, value);
                    break;
            }
        }

        void BuildObjectivesBlock(WorldPacket& data) final override
        {
            data << uint32(2); // Objectives Count
            data << uint32(BasesAssaulted);
            data << uint32(BasesDefended);
        }

        uint32 GetAttr1() const final override { return BasesAssaulted; }
        uint32 GetAttr2() const final override { return BasesDefended; }

        uint32 BasesAssaulted;
        uint32 BasesDefended;
};

class BattlegroundIC : public Battleground
{
    public:
        BattlegroundIC();
        ~BattlegroundIC();

        /* inherited from BattlegroundClass */
        void AddPlayer(Player* player) override;
        void StartingEventCloseDoors() override;
        void StartingEventOpenDoors() override;
        void PostUpdateImpl(uint32 diff) override;

        void RemovePlayer(Player* player, ObjectGuid guid, uint32 team) override;
        void HandleAreaTrigger(Player* player, uint32 trigger) override;
        bool SetupBattleground() override;
        void HandleKillUnit(Creature* unit, Player* killer) override;
        void HandleKillPlayer(Player* player, Player* killer) override;
        void EndBattleground(uint32 winner) override;
        void EventPlayerClickedOnFlag(Player* source, GameObject* /*target_obj*/) override;

        void DestroyGate(Player* player, GameObject* go) override;

        WorldSafeLocsEntry const* GetClosestGraveYard(Player* player) override;

        /* Scorekeeping */
        void FillInitialWorldStates(WorldPacket& data) override;

        void HandlePlayerResurrect(Player* player) override;

        uint32 GetNodeState(uint8 nodeType) const { return nodePoint[nodeType].nodeState; }

        bool IsAllNodesControlledByTeam(uint32 team) const override;

        bool IsSpellAllowed(uint32 spellId, Player const* player) const override;

    private:
        EventMap _events;

        uint16 factionReinforcements[BG_TEAMS_COUNT];
        BG_IC_GateState GateStatus[BG_IC_MAXDOOR];
        ICNodePoint nodePoint[MAX_NODE_TYPES];

        ObjectGuid gunshipAllianceGUID;
        ObjectGuid gunshipHordeGUID;

        static uint32 GetNextBanner(ICNodePoint const* node, TeamId team, bool returnDefinitve);
        static uint32 GetGateIDFromEntry(uint32 id);
        static uint32 GetWorldStateFromGateEntry(uint32 id, bool open);

        void UpdateNodeWorldState(ICNodePoint* node);
        void HandleCapturedNodes(ICNodePoint const* node, bool recapture);
        void HandleContestedNodes(ICNodePoint const* node);
};

#endif
