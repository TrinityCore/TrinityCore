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

#ifndef __BATTLEGROUNDAV_H
#define __BATTLEGROUNDAV_H

#include "Battleground.h"
#include "BattlegroundScore.h"

enum SharedActions
{
    ACTION_BUFF_YELL    = -30001
};

enum BG_AV_Sounds
{ /// @todo: get out if there comes a sound when neutral team captures mine

/*
8212:
    alliance grave assault
    alliance tower assault
    drek "mlanzenabschaum! In meiner Burg?! Toetet sie all" - nicht immer der sound
8333:
    galv "sterbt fuer euch ist kein platz hier"

8332:
    bal "Verschwinde, dreckiger Abschaum! Die Allianz wird im Alteractal "
8174:
    horde tower assault
    horde grave assault
    van "es Sturmlanzenklans, euer General wird angegriffen! Ich fordere Unterst"
8173:
    ally grave capture/defend
    tower destroy
    mine capture
    ally wins
8192:
    ally tower destroy(only iceblood - found a bug^^)
    ally tower  defend
    horde tower defend
8213
horde:
    grave defend/capture
    tower destroy
    mine capture
    horde wins
    */

    AV_SOUND_NEAR_VICTORY                   = 8456, /// @todo: Not confirmed yet

    AV_SOUND_ALLIANCE_ASSAULTS              = 8212, //tower, grave + enemy boss if someone tries to attack him
    AV_SOUND_HORDE_ASSAULTS                 = 8174,
    AV_SOUND_ALLIANCE_GOOD                  = 8173, //if something good happens for the team:  wins(maybe only through killing the boss), captures mine or grave, destroys tower and defends grave
    AV_SOUND_HORDE_GOOD                     = 8213,
    AV_SOUND_BOTH_TOWER_DEFEND              = 8192,

    AV_SOUND_ALLIANCE_CAPTAIN               = 8232, //gets called when someone attacks them and at the beginning after 3min+rand(x)*10sec (maybe buff)
    AV_SOUND_HORDE_CAPTAIN                  = 8333
};

enum BG_AV_OTHER_VALUES
{
    BG_AV_CAPTIME = 4 * MINUTE * IN_MILLISECONDS,

    BG_AV_SCORE_INITIAL_POINTS      = 600,
    SEND_MSG_NEAR_LOSE              = 120,

    BG_AV_KILL_BOSS                 = 4,
    BG_AV_REP_BOSS                  = 350,

    BG_AV_KILL_CAPTAIN              = 3,
    BG_AV_REP_CAPTAIN               = 125,
    BG_AV_RES_CAPTAIN               = 100,

    BG_AV_KILL_TOWER                = 3,
    BG_AV_REP_TOWER                 = 12,
    BG_AV_RES_TOWER                 = 75,

    BG_AV_GET_COMMANDER             = 1, //for a safely returned wingcommander

    //bonus honor at the end
    BG_AV_KILL_SURVIVING_TOWER      = 2,
    BG_AV_REP_SURVIVING_TOWER       = 12,

    BG_AV_KILL_SURVIVING_CAPTAIN    = 2,
    BG_AV_REP_SURVIVING_CAPTAIN     = 125,

    BG_AV_EVENT_START_BATTLE        = 9166, // Achievement: The Alterac Blitz

    AV_STATICCPLACE_MAX             = 123,
    AV_NORTH_MINE                   = 0,
    AV_SOUTH_MINE                   = 1,
    AV_MINE_TICK_TIMER              = 45000,
    AV_MINE_RECLAIM_TIMER           = 20 * MINUTE * IN_MILLISECONDS, /// @todo: get the right value
    AV_NEUTRAL_TEAM                 = 0 //this is the neutral owner of snowfall
};

enum BG_AV_ObjectIds
{
    BG_AV_OBJECTID_BANNER_A_AID_STATION             = 179465, // can only be used by horde
    BG_AV_OBJECTID_BANNER_A_STORMPIKE               = 178389,
    BG_AV_OBJECTID_BANNER_A_STONEHEARTH_GRAVE       = 179284,
    BG_AV_OBJECTID_BANNER_A_SNOWFALL_GRAVE          = 178365,
    BG_AV_OBJECTID_BANNER_A_ICEBLOOD_GRAVE          = 179481,
    BG_AV_OBJECTID_BANNER_A_FROSTWOLF_GRAVE         = 178394,
    BG_AV_OBJECTID_BANNER_A_FROSTWOLF_HUT           = 179470,
    BG_AV_OBJECTID_BANNER_A_DUN_BALDAR_S            = 178925,
    BG_AV_OBJECTID_BANNER_A_DUN_BALDAR_N            = 178929,
    BG_AV_OBJECTID_BANNER_A_ICEWING_BUNKER          = 178935,
    BG_AV_OBJECTID_BANNER_A_STONEHEARTH_BUNKER      = 178936,

    BG_AV_OBJECTID_BANNER_H_AID_STATION             = 179467, // can only be used by alliance
    BG_AV_OBJECTID_BANNER_H_STORMPIKE               = 178388,
    BG_AV_OBJECTID_BANNER_H_STONEHEARTH_GRAVE       = 179285,
    BG_AV_OBJECTID_BANNER_H_SNOWFALL                = 178364,
    BG_AV_OBJECTID_BANNER_H_ICEBLOOD_GRAVE          = 179483,
    BG_AV_OBJECTID_BANNER_H_FROSTWOLF_GRAVE         = 178393,
    BG_AV_OBJECTID_BANNER_H_FROSTWOLF_HUT           = 179472,
    BG_AV_OBJECTID_BANNER_H_ICEBLOOD_GARRISON       = 178946,
    BG_AV_OBJECTID_BANNER_H_TOWER_POINT             = 178945,
    BG_AV_OBJECTID_BANNER_H_FROSTWOLF_E             = 178944,
    BG_AV_OBJECTID_BANNER_H_FROSTWOLF_W             = 178943,

    BG_AV_OBJECTID_BANNER_CONT_A_AID_STATION        = 179466, // can only be used by horde
    BG_AV_OBJECTID_BANNER_CONT_A_STORMPIKE          = 179286,
    BG_AV_OBJECTID_BANNER_CONT_A_STONEHEARTH_GRAVE  = 179308,
    BG_AV_OBJECTID_BANNER_CONT_A_SNOWFALL           = 180419,
    BG_AV_OBJECTID_BANNER_CONT_A_ICEBLOOD_GRAVE     = 179482,
    BG_AV_OBJECTID_BANNER_CONT_A_FROSTWOLF_GRAVE    = 179304,
    BG_AV_OBJECTID_BANNER_CONT_A_FROSTWOLF_HUT      = 179471,
    BG_AV_OBJECTID_BANNER_CONT_A_ICEBLOOD_GARRISON  = 178940,
    BG_AV_OBJECTID_BANNER_CONT_A_TOWER_POINT        = 179453,
    BG_AV_OBJECTID_BANNER_CONT_A_FROSTWOLF_E        = 179449,
    BG_AV_OBJECTID_BANNER_CONT_A_FROSTWOLF_W        = 179445,

    BG_AV_OBJECTID_BANNER_CONT_H_AID_STATION        = 179468, // can only be used by alliance
    BG_AV_OBJECTID_BANNER_CONT_H_STORMPIKE          = 179287,
    BG_AV_OBJECTID_BANNER_CONT_H_STONEHEARTH_GRAVE  = 179310,
    BG_AV_OBJECTID_BANNER_CONT_H_SNOWFALL           = 180420,
    BG_AV_OBJECTID_BANNER_CONT_H_ICEBLOOD_GRAVE     = 179484,
    BG_AV_OBJECTID_BANNER_CONT_H_FROSTWOLF_GRAVE    = 179305,
    BG_AV_OBJECTID_BANNER_CONT_H_FROSTWOLF_HUT      = 179473,
    BG_AV_OBJECTID_BANNER_CONT_H_DUN_BALDAR_S       = 179435,
    BG_AV_OBJECTID_BANNER_CONT_H_DUN_BALDAR_N       = 179439,
    BG_AV_OBJECTID_BANNER_CONT_H_ICEWING_BUNKER     = 179441,
    BG_AV_OBJECTID_BANNER_CONT_H_STONEHEARTH_BUNKER = 179443,

    BG_AV_OBJECTID_BANNER_SNOWFALL_N                = 180418,

    //snowfall eyecandy banner:
    BG_AV_OBJECTID_SNOWFALL_CANDY_A                 = 179044,
    BG_AV_OBJECTID_SNOWFALL_CANDY_PA                = 179424,
    BG_AV_OBJECTID_SNOWFALL_CANDY_H                 = 179064,
    BG_AV_OBJECTID_SNOWFALL_CANDY_PH                = 179425,

    //banners on top of towers:
    BG_AV_OBJECTID_TOWER_BANNER_A                   = 178927, // [PH] Alliance A1 Tower Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_A_B                 = 178932, // [PH] Alliance A2 Tower Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_A_C                 = 178947, // [PH] Alliance A3 Tower Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_A_D                 = 178948, // [PH] Alliance A4 Tower Banner BIG

    BG_AV_OBJECTID_TOWER_BANNER_H                   = 178955, // [PH] Horde H1 Tower Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_H_B                 = 178956, // [PH] Horde H2 Tower Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_H_C                 = 178957, // [PH] Horde H3 Tower Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_H_D                 = 178958, // [PH] Horde H4 Tower Banner BIG

    BG_AV_OBJECTID_TOWER_BANNER_PA                  = 179446, // [PH] Alliance H1 Tower Pre - Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_PA_B                = 179450, // [PH] Alliance H2 Tower Pre - Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_PA_C                = 179454, // [PH] Alliance H3 Tower Pre - Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_PA_D                = 179458, // [PH] Alliance H4 Tower Pre - Banner BIG

    BG_AV_OBJECTID_TOWER_BANNER_PH                  = 179436, // [PH] Horde A1 Tower Pre - Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_PH_B                = 179440, // [PH] Horde A2 Tower Pre - Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_PH_C                = 179442, // [PH] Horde A3 Tower Pre - Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_PH_D                = 179444, // [PH] Horde A4 Tower Pre - Banner BIG

    //Auras
    BG_AV_OBJECTID_AURA_A                           = 180421,
    BG_AV_OBJECTID_AURA_H                           = 180422,
    BG_AV_OBJECTID_AURA_N                           = 180423,
    BG_AV_OBJECTID_AURA_A_S                         = 180100,
    BG_AV_OBJECTID_AURA_H_S                         = 180101,
    BG_AV_OBJECTID_AURA_N_S                         = 180102,

    BG_AV_OBJECTID_GATE                             = 180424,
    BG_AV_GHOST_GATE                                = 180322,

    //mine supplies
    BG_AV_OBJECTID_MINE_N                           = 178785,
    BG_AV_OBJECTID_MINE_S                           = 178784,

    BG_AV_OBJECTID_FIRE                             = 179065,
    BG_AV_OBJECTID_SMOKE                            = 179066
};

enum BG_AV_Destructible_Buildings
{
    BG_AV_DESTRUCTIBLE_DUNBALDAR_SOUTH      = 0,
    BG_AV_DESTRUCTIBLE_DUNBALDAR_NORTH      = 1,
    BG_AV_DESTRUCTIBLE_ICEWING_BUNKER       = 2,
    BG_AV_DESTRUCTIBLE_STONEHEART_BUNKER    = 3,
    BG_AV_DESTRUCTIBLE_ICEBLOOD_TOWER       = 4,
    BG_AV_DESTRUCTIBLE_TOWER_POINT          = 5,
    BG_AV_DESTRUCTIBLE_FROSTWOLF_ETOWER     = 6,
    BG_AV_DESTRUCTIBLE_FROSTWOLF_WTOWER     = 7,
    BG_AV_DESTRUCTIBLE_BUILDING_ALLIANCE    = 8,
    BG_AV_DESTRUCTIBLE_BUILDING_HORDE       = 9,

    BG_AV_DESTRUCTIBLE_MAX                  = 10
};

enum BG_AV_Nodes
{
    BG_AV_NODES_AID_STATION             = 0,
    BG_AV_NODES_STORMPIKE_GRAVE         = 1,
    BG_AV_NODES_STONEHEART_GRAVE        = 2,
    BG_AV_NODES_SNOWFALL_GRAVE          = 3,
    BG_AV_NODES_ICEBLOOD_GRAVE          = 4,
    BG_AV_NODES_FROSTWOLF_GRAVE         = 5,
    BG_AV_NODES_FROSTWOLF_HUT           = 6,
    BG_AV_NODES_DUNBALDAR_SOUTH         = 7,
    BG_AV_NODES_DUNBALDAR_NORTH         = 8,
    BG_AV_NODES_ICEWING_BUNKER          = 9,
    BG_AV_NODES_STONEHEART_BUNKER       = 10,
    BG_AV_NODES_ICEBLOOD_TOWER          = 11,
    BG_AV_NODES_TOWER_POINT             = 12,
    BG_AV_NODES_FROSTWOLF_ETOWER        = 13,
    BG_AV_NODES_FROSTWOLF_WTOWER        = 14,

    BG_AV_NODES_MAX                     = 15
};

enum BG_AV_ObjectTypes
{
    BG_AV_OBJECT_DOOR_A                         = 0,
    BG_AV_OBJECT_DOOR_H                         = 1,
    BG_AV_GHOST_GATE_A                          = 2,
    BG_AV_GHOST_GATE_H                          = 3,

    BG_AV_OBJECT_FLAG_A_AID_STATION             = 4,
    BG_AV_OBJECT_FLAG_A_STORMPIKE_GRAVE         = 5,
    BG_AV_OBJECT_FLAG_A_STONEHEART_GRAVE        = 6,
    BG_AV_OBJECT_FLAG_A_SNOWFALL_GRAVE          = 7,
    BG_AV_OBJECT_FLAG_A_ICEBLOOD_GRAVE          = 8,
    BG_AV_OBJECT_FLAG_A_FROSTWOLF_GRAVE         = 9,
    BG_AV_OBJECT_FLAG_A_FROSTWOLF_HUT           = 10,
    BG_AV_OBJECT_FLAG_A_DUNBALDAR_SOUTH         = 11,
    BG_AV_OBJECT_FLAG_A_DUNBALDAR_NORTH         = 12,
    BG_AV_OBJECT_FLAG_A_ICEWING_BUNKER          = 13,
    BG_AV_OBJECT_FLAG_A_STONEHEART_BUNKER       = 14,

    BG_AV_OBJECT_FLAG_C_A_AID_STATION           = 15,
    BG_AV_OBJECT_FLAG_C_A_STORMPIKE_GRAVE       = 16,
    BG_AV_OBJECT_FLAG_C_A_STONEHEART_GRAVE      = 17,
    BG_AV_OBJECT_FLAG_C_A_SNOWFALL_GRAVE        = 18,
    BG_AV_OBJECT_FLAG_C_A_ICEBLOOD_GRAVE        = 19,
    BG_AV_OBJECT_FLAG_C_A_FROSTWOLF_GRAVE       = 20,
    BG_AV_OBJECT_FLAG_C_A_FROSTWOLF_HUT         = 21,
    BG_AV_OBJECT_FLAG_C_A_ICEBLOOD_TOWER        = 22,
    BG_AV_OBJECT_FLAG_C_A_TOWER_POINT           = 23,
    BG_AV_OBJECT_FLAG_C_A_FROSTWOLF_ETOWER      = 24,
    BG_AV_OBJECT_FLAG_C_A_FROSTWOLF_WTOWER      = 25,

    BG_AV_OBJECT_FLAG_C_H_AID_STATION           = 26,
    BG_AV_OBJECT_FLAG_C_H_STORMPIKE_GRAVE       = 27,
    BG_AV_OBJECT_FLAG_C_H_STONEHEART_GRAVE      = 28,
    BG_AV_OBJECT_FLAG_C_H_SNOWFALL_GRAVE        = 29,
    BG_AV_OBJECT_FLAG_C_H_ICEBLOOD_GRAVE        = 30,
    BG_AV_OBJECT_FLAG_C_H_FROSTWOLF_GRAVE       = 31,
    BG_AV_OBJECT_FLAG_C_H_FROSTWOLF_HUT         = 32,
    BG_AV_OBJECT_FLAG_C_H_DUNBALDAR_SOUTH       = 33,
    BG_AV_OBJECT_FLAG_C_H_DUNBALDAR_NORTH       = 34,
    BG_AV_OBJECT_FLAG_C_H_ICEWING_BUNKER        = 35,
    BG_AV_OBJECT_FLAG_C_H_STONEHEART_BUNKER     = 36,

    BG_AV_OBJECT_FLAG_H_AID_STATION             = 37,
    BG_AV_OBJECT_FLAG_H_STORMPIKE_GRAVE         = 38,
    BG_AV_OBJECT_FLAG_H_STONEHEART_GRAVE        = 39,
    BG_AV_OBJECT_FLAG_H_SNOWFALL_GRAVE          = 40,
    BG_AV_OBJECT_FLAG_H_ICEBLOOD_GRAVE          = 41,
    BG_AV_OBJECT_FLAG_H_FROSTWOLF_GRAVE         = 42,
    BG_AV_OBJECT_FLAG_H_FROSTWOLF_HUT           = 43,
    BG_AV_OBJECT_FLAG_H_ICEBLOOD_TOWER          = 44,
    BG_AV_OBJECT_FLAG_H_TOWER_POINT             = 45,
    BG_AV_OBJECT_FLAG_H_FROSTWOLF_ETOWER        = 46,
    BG_AV_OBJECT_FLAG_H_FROSTWOLF_WTOWER        = 47,

    BG_AV_OBJECT_FLAG_N_SNOWFALL_GRAVE          = 48,

//auras for graveyards (3auras per graveyard neutral, alliance, horde)
    BG_AV_OBJECT_AURA_N_AID_STATION_CONT_A      = 49,
    BG_AV_OBJECT_AURA_N_AID_STATION_CONT_H      = 50,
    BG_AV_OBJECT_AURA_N_STORMPIKE_GRAVE_CONT_A  = 51,
    BG_AV_OBJECT_AURA_N_STORMPIKE_GRAVE_CONT_H  = 52,
    BG_AV_OBJECT_AURA_N_STONEHEART_GRAVE_CONT_A = 53,
    BG_AV_OBJECT_AURA_N_STONEHEART_GRAVE_CONT_H = 54,
    BG_AV_OBJECT_AURA_N_SNOWFALL_GRAVE_CONT_A   = 55,
    BG_AV_OBJECT_AURA_N_SNOWFALL_GRAVE_CONT_H   = 56,
    BG_AV_OBJECT_AURA_N_ICEBLOOD_GRAVE_CONT_A   = 57,
    BG_AV_OBJECT_AURA_N_ICEBLOOD_GRAVE_CONT_H   = 58,
    BG_AV_OBJECT_AURA_N_FROSTWOLF_GRAVE_CONT_A  = 59,
    BG_AV_OBJECT_AURA_N_FROSTWOLF_GRAVE_CONT_H  = 60,
    BG_AV_OBJECT_AURA_N_FROSTWOLF_HUT_CONT_A    = 61,
    BG_AV_OBJECT_AURA_N_FROSTWOLF_HUT_CONT_H    = 62,

    BG_AV_OBJECT_AURA_N_SNOWFALL_GRAVE_N        = 63,

    BG_AV_OBJECT_AURA_A_AID_STATION             = 64,
    BG_AV_OBJECT_AURA_A_STORMPIKE_GRAVE         = 65,
    BG_AV_OBJECT_AURA_A_STONEHEART_GRAVE        = 66,
    BG_AV_OBJECT_AURA_A_SNOWFALL_GRAVE          = 67,
    BG_AV_OBJECT_AURA_A_ICEBLOOD_GRAVE          = 68,
    BG_AV_OBJECT_AURA_A_FROSTWOLF_GRAVE         = 69,
    BG_AV_OBJECT_AURA_A_FROSTWOLF_HUT           = 70,

    BG_AV_OBJECT_AURA_H_AID_STATION             = 71,
    BG_AV_OBJECT_AURA_H_STORMPIKE_GRAVE         = 72,
    BG_AV_OBJECT_AURA_H_STONEHEART_GRAVE        = 73,
    BG_AV_OBJECT_AURA_H_SNOWFALL_GRAVE          = 74,
    BG_AV_OBJECT_AURA_H_ICEBLOOD_GRAVE          = 75,
    BG_AV_OBJECT_AURA_H_FROSTWOLF_GRAVE         = 76,
    BG_AV_OBJECT_AURA_H_FROSTWOLF_HUT           = 77,

//big flags on top of towers 2 flags on each (contested, (alliance | horde)) + 2 auras
    BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH        = 78,
    BG_AV_OBJECT_TFLAG_A_DUNBALDAR_NORTH        = 79,
    BG_AV_OBJECT_TFLAG_A_ICEWING_BUNKER         = 80,
    BG_AV_OBJECT_TFLAG_A_STONEHEART_BUNKER      = 81,

    BG_AV_OBJECT_TFLAG_H_ICEBLOOD_TOWER         = 82,
    BG_AV_OBJECT_TFLAG_H_TOWER_POINT            = 83,
    BG_AV_OBJECT_TFLAG_H_FROSTWOLF_ETOWER       = 84,
    BG_AV_OBJECT_TFLAG_H_FROSTWOLF_WTOWER       = 85,

    BG_AV_OBJECT_TFLAG_H_DUNBALDAR_SOUTH        = 86,
    BG_AV_OBJECT_TFLAG_H_DUNBALDAR_NORTH        = 87,
    BG_AV_OBJECT_TFLAG_H_ICEWING_BUNKER         = 88,
    BG_AV_OBJECT_TFLAG_H_STONEHEART_BUNKER      = 89,

    BG_AV_OBJECT_TFLAG_A_ICEBLOOD_TOWER         = 90,
    BG_AV_OBJECT_TFLAG_A_TOWER_POINT            = 91,
    BG_AV_OBJECT_TFLAG_A_FROSTWOLF_ETOWER       = 92,
    BG_AV_OBJECT_TFLAG_A_FROSTWOLF_WTOWER       = 93,

    BG_AV_OBJECT_TAURA_A_DUNBALDAR_SOUTH        = 94,
    BG_AV_OBJECT_TAURA_A_DUNBALDAR_NORTH        = 95,
    BG_AV_OBJECT_TAURA_A_ICEWING_BUNKER         = 96,
    BG_AV_OBJECT_TAURA_A_STONEHEART_BUNKER      = 97,

    BG_AV_OBJECT_TAURA_H_ICEBLOOD_TOWER         = 98,
    BG_AV_OBJECT_TAURA_H_TOWER_POINT            = 99,
    BG_AV_OBJECT_TAURA_H_FROSTWOLF_ETOWER       = 100,
    BG_AV_OBJECT_TAURA_H_FROSTWOLF_WTOWER       = 101,

    BG_AV_OBJECT_TAURA_N_DUNBALDAR_SOUTH        = 102,
    BG_AV_OBJECT_TAURA_N_DUNBALDAR_NORTH        = 103,
    BG_AV_OBJECT_TAURA_N_ICEWING_BUNKER         = 104,
    BG_AV_OBJECT_TAURA_N_STONEHEART_BUNKER      = 105,
    BG_AV_OBJECT_TAURA_N_ICEBLOOD_TOWER         = 106,
    BG_AV_OBJECT_TAURA_N_TOWER_POINT            = 107,
    BG_AV_OBJECT_TAURA_N_FROSTWOLF_ETOWER       = 108,
    BG_AV_OBJECT_TAURA_N_FROSTWOLF_WTOWER       = 109,

    BG_AV_OBJECT_BURN_DUNBALDAR_SOUTH           = 110, // 13 GOBs
    BG_AV_OBJECT_BURN_DUNBALDAR_NORTH           = 123, // 14 GOBs
    BG_AV_OBJECT_BURN_ICEWING_BUNKER            = 137,
    BG_AV_OBJECT_BURN_STONEHEART_BUNKER         = 147,
    BG_AV_OBJECT_BURN_ICEBLOOD_TOWER            = 157,
    BG_AV_OBJECT_BURN_TOWER_POINT               = 167,
    BG_AV_OBJECT_BURN_FROSTWOLF_ETOWER          = 177,
    BG_AV_OBJECT_BURN_FROSTWOLF_WTOWER          = 187,
    BG_AV_OBJECT_BURN_BUILDING_ALLIANCE         = 197,
    BG_AV_OBJECT_BURN_BUILDING_HORDE            = 207,

    BG_AV_OBJECT_SNOW_EYECANDY_A                = 217,
    BG_AV_OBJECT_SNOW_EYECANDY_PA               = 221, // on sniffs there are 8 of them spawned, and 4 of the others, purpose of the "extra" pair unknown
    BG_AV_OBJECT_SNOW_EYECANDY_H                = 229,
    BG_AV_OBJECT_SNOW_EYECANDY_PH               = 233,

    BG_AV_OBJECT_MINE_SUPPLY_N_MIN              = 237, // 10 GOBs
    BG_AV_OBJECT_MINE_SUPPLY_N_MAX              = 246,
    BG_AV_OBJECT_MINE_SUPPLY_S_MIN              = 247, // 13 GOBs
    BG_AV_OBJECT_MINE_SUPPLY_S_MAX              = 259,

    BG_AV_OBJECT_MAX                            = 260,

    BG_AV_FIRE_SMOKE_COUNT                      = BG_AV_OBJECT_SNOW_EYECANDY_A - BG_AV_OBJECT_BURN_DUNBALDAR_SOUTH
};

//creaturestuff starts here
//is related to BG_AV_CreaturePos
enum BG_AV_CreaturePlace
{
    AV_CPLACE_SPIRIT_STORM_AID      = 0,
    AV_CPLACE_SPIRIT_STORM_GRAVE    = 1,
    AV_CPLACE_SPIRIT_STONE_GRAVE    = 2,
    AV_CPLACE_SPIRIT_SNOWFALL       = 3,
    AV_CPLACE_SPIRIT_ICE_GRAVE      = 4,
    AV_CPLACE_SPIRIT_FROSTWOLF      = 5,
    AV_CPLACE_SPIRIT_FROST_HUT      = 6,
    AV_CPLACE_SPIRIT_MAIN_ALLIANCE  = 7,
    AV_CPLACE_SPIRIT_MAIN_HORDE     = 8,
//I don't add a variable for all 4 positions... I think one is enough to compute the rest
    AV_CPLACE_DEFENSE_STORM_AID     = 9,
    AV_CPLACE_DEFEMSE_STORM_GRAVE   = 13,
    AV_CPLACE_DEFENSE_STONE_GRAVE   = 17,
    AV_CPLACE_DEFENSE_SNOWFALL      = 21,
    AV_CPLACE_DEFENSE_ICE_GRAVE     = 25,
    AV_CPLACE_DEFENSE_FROSTWOLF     = 29,
    AV_CPLACE_DEFENSE_FROST_HUT     = 33,
    AV_CPLACE_DEFENSE_DUN_S         = 37,
    AV_CPLACE_DEFENSE_DUN_N         = 41,
    AV_CPLACE_DEFENSE_ICEWING       = 45,
    AV_CPLACE_DEFENSE_STONE_TOWER   = 49,
    AV_CPLACE_DEFENSE_ICE_TOWER     = 53,
    AV_CPLACE_DEFENSE_TOWERPOINT    = 57,
    AV_CPLACE_DEFENSE_FROST_E       = 61,
    AV_CPLACE_DEFENSE_FROST_W       = 65,

    AV_CPLACE_A_MARSHAL_SOUTH       = 69,
    AV_CPLACE_A_MARSHAL_NORTH       = 70,
    AV_CPLACE_A_MARSHAL_ICE         = 71,
    AV_CPLACE_A_MARSHAL_STONE       = 72,
    AV_CPLACE_H_MARSHAL_ICE         = 73,
    AV_CPLACE_H_MARSHAL_TOWER       = 74,
    AV_CPLACE_H_MARSHAL_ETOWER      = 75,
    AV_CPLACE_H_MARSHAL_WTOWER      = 76,
    //irondeep
    //miner:
    AV_CPLACE_MINE_N_1_MIN          = 77,
    AV_CPLACE_MINE_N_1_MAX          = 136,
    //special types
    AV_CPLACE_MINE_N_2_MIN          = 137,
    AV_CPLACE_MINE_N_2_MAX          = 192,
    //boss
    AV_CPLACE_MINE_N_3              = 193,
    //coldtooth
    //miner:
    AV_CPLACE_MINE_S_1_MIN          = 194,
    AV_CPLACE_MINE_S_1_MAX          = 250,
    //special types
    AV_CPLACE_MINE_S_2_MIN          = 251,
    AV_CPLACE_MINE_S_2_MAX          = 289,
    //vermin
    AV_CPLACE_MINE_S_S_MIN          = 290,
    AV_CPLACE_MINE_S_S_MAX          = 299,
    //boss
    AV_CPLACE_MINE_S_3              = 300,

    //herald
    AV_CPLACE_HERALD                = 301,

    //node aura triggers
    AV_CPLACE_TRIGGER01             = 302,
    AV_CPLACE_TRIGGER02             = 303,
    AV_CPLACE_TRIGGER03             = 304,
    AV_CPLACE_TRIGGER04             = 305,
    AV_CPLACE_TRIGGER05             = 306,
    AV_CPLACE_TRIGGER06             = 307,
    AV_CPLACE_TRIGGER07             = 308,
    AV_CPLACE_TRIGGER08             = 309,
    AV_CPLACE_TRIGGER09             = 310,
    AV_CPLACE_TRIGGER10             = 311,
    AV_CPLACE_TRIGGER11             = 312,
    AV_CPLACE_TRIGGER12             = 313,
    AV_CPLACE_TRIGGER13             = 314,
    AV_CPLACE_TRIGGER14             = 315,
    AV_CPLACE_TRIGGER15             = 316,

    //boss, captain triggers
    AV_CPLACE_TRIGGER16             = 317,
    AV_CPLACE_TRIGGER17             = 318,
    AV_CPLACE_TRIGGER18             = 319,
    AV_CPLACE_TRIGGER19             = 320,

    AV_CPLACE_MAX                   = 321
};

// related to BG_AV_CreatureInfo
enum BG_AV_CreatureIds
{
    AV_NPC_A_TOWERDEFENSE  = 0,     // stormpike bowman
    AV_NPC_A_GRAVEDEFENSE0 = 1,     // stormpike Defender
    AV_NPC_A_GRAVEDEFENSE1 = 2,     // seasoned defender
    AV_NPC_A_GRAVEDEFENSE2 = 3,     // veteran defender
    AV_NPC_A_GRAVEDEFENSE3 = 4,     // champion defender
    AV_NPC_A_CAPTAIN       = 5,     // balinda
    AV_NPC_A_BOSS          = 6,     // vanndar

    AV_NPC_H_TOWERDEFENSE  = 7,     // frostwolf bowman
    AV_NPC_H_GRAVEDEFENSE0 = 8,     // frostwolf guardian
    AV_NPC_H_GRAVEDEFENSE1 = 9,     // seasoned guardian
    AV_NPC_H_GRAVEDEFENSE2 = 10,    // veteran guardian
    AV_NPC_H_GRAVEDEFENSE3 = 11,    // champion guardian
    AV_NPC_H_CAPTAIN       = 12,    // galvangar
    AV_NPC_H_BOSS          = 13,    // drek thar

    AV_NPC_A_MARSHAL_SOUTH = 14,
    AV_NPC_MARSHAL_NORTH   = 15,
    AV_NPC_A_MARSHAL_ICE   = 16,
    AV_NPC_A_MARSHAL_STONE = 17,

    AV_NPC_H_MARSHAL_ICE   = 18,
    AV_NPC_H_MARSHAL_TOWER = 19,
    AV_NPC_MARSHAL_ETOWER  = 20,
    AV_NPC_H_MARSHAL_WTOWER= 21,

    AV_NPC_N_MINE_N_1      = 22,
    AV_NPC_N_MINE_N_2      = 23,
    AV_NPC_N_MINE_N_3      = 24,
    AV_NPC_N_MINE_N_4      = 25,

    AV_NPC_N_MINE_A_1      = 26,
    AV_NPC_N_MINE_A_2      = 27,
    AV_NPC_N_MINE_A_3      = 28,
    AV_NPC_N_MINE_A_4      = 29,

    AV_NPC_N_MINE_H_1      = 30,
    AV_NPC_N_MINE_H_2      = 31,
    AV_NPC_N_MINE_H_3      = 32,
    AV_NPC_N_MINE_H_4      = 33,

    AV_NPC_S_MINE_N_1      = 34,
    AV_NPC_S_MINE_N_2      = 35,
    AV_NPC_S_MINE_N_3      = 36,
    AV_NPC_S_MINE_N_4      = 37,
    AV_NPC_S_MINE_N_S      = 38,

    AV_NPC_S_MINE_A_1      = 39,
    AV_NPC_S_MINE_A_2      = 40,
    AV_NPC_S_MINE_A_3      = 41,
    AV_NPC_S_MINE_A_4      = 42,

    AV_NPC_S_MINE_H_1      = 43,
    AV_NPC_S_MINE_H_2      = 44,
    AV_NPC_S_MINE_H_3      = 45,
    AV_NPC_S_MINE_H_4      = 46,

    AV_NPC_HERALD          = 47,
    AV_NPC_INFO_MAX        = 48
};

enum BG_AV_Graveyards
{
    AV_GRAVE_STORM_AID         = 751,
    AV_GRAVE_STORM_GRAVE       = 689,
    AV_GRAVE_STONE_GRAVE       = 729,
    AV_GRAVE_SNOWFALL          = 169,
    AV_GRAVE_ICE_GRAVE         = 749,
    AV_GRAVE_FROSTWOLF         = 690,
    AV_GRAVE_FROST_HUT         = 750,
    AV_GRAVE_MAIN_ALLIANCE     = 611,
    AV_GRAVE_MAIN_HORDE        = 610
};

enum BG_AV_BUFF
{ /// @todo: Add all other buffs here
    AV_BUFF_ARMOR = 21163,
    AV_BUFF_A_CAPTAIN = 23693, //the buff which the alliance captain does
    AV_BUFF_H_CAPTAIN = 22751 //the buff which the horde captain does
};
enum BG_AV_States
{
    POINT_NEUTRAL              =  0,
    POINT_ASSAULTED            =  1,
    POINT_DESTROYED            =  2,
    POINT_CONTROLED            =  3
};

enum BG_AV_WorldStates
{
    AV_Alliance_Score               = 3127,
    AV_Horde_Score                  = 3128,
    AV_SHOW_H_SCORE                 = 3133,
    AV_SHOW_A_SCORE                 = 3134,

/*
    //the comments behind the state shows which icon overlaps the other.. but is, until now, unused and maybe not a good solution (but give few performance (:)

// Graves

    // Alliance
    //Stormpike first aid station
    AV_AID_A_C                      = 1325,
    AV_AID_A_A                      = 1326,
    AV_AID_H_C                      = 1327,
    AV_AID_H_A                      = 1328,
    //Stormpike Graveyard
    AV_PIKEGRAVE_A_C                = 1333,
    AV_PIKEGRAVE_A_A                = 1335,
    AV_PIKEGRAVE_H_C                = 1334,
    AV_PIKEGRAVE_H_A                = 1336,
    //Stoneheart Grave
    AV_STONEHEART_A_C               = 1302,
    AV_STONEHEART_A_A               = 1304, //over hc
    AV_STONEHEART_H_C               = 1301, //over ac
    AV_STONEHEART_H_A               = 1303, //over aa
    //Neutral
    //Snowfall Grave
*/
    AV_SNOWFALL_N                   = 1966 //over aa
/*
    AV_SNOWFALL_A_C                 = 1341, //over hc
    AV_SNOWFALL_A_A                 = 1343, //over ha
    AV_SNOWFALL_H_C                 = 1342,
    AV_SNOWFALL_H_A                 = 1344, //over ac
    //Horde
    //Iceblood grave
    AV_ICEBLOOD_A_C                 = 1346, //over hc
    AV_ICEBLOOD_A_A                 = 1348, //over ac
    AV_ICEBLOOD_H_C                 = 1347,
    AV_ICEBLOOD_H_A                 = 1349, //over aa
    //Frostwolf Grave
    AV_FROSTWOLF_A_C                = 1337, //over hc
    AV_FROSTWOLF_A_A                = 1339, //over ac
    AV_FROSTWOLF_H_C                = 1338,
    AV_FROSTWOLF_H_A                = 1340, //over aa
    //Frostwolf Hut
    AV_FROSTWOLFHUT_A_C             = 1329, //over hc
    AV_FROSTWOLFHUT_A_A             = 1331, //over ha
    AV_FROSTWOLFHUT_H_C             = 1330,
    AV_FROSTWOLFHUT_H_A             = 1332, //over ac

//Towers
    //Alliance
    //Dunbaldar South Bunker
    AV_DUNS_CONTROLLED              = 1361,
    AV_DUNS_DESTROYED               = 1370,
    AV_DUNS_ASSAULTED               = 1378,
    //Dunbaldar North Bunker
    AV_DUNN_CONTROLLED              = 1362,
    AV_DUNN_DESTROYED               = 1371,
    AV_DUNN_ASSAULTED               = 1379,
    //Icewing Bunker
    AV_ICEWING_CONTROLLED           = 1363,
    AV_ICEWING_DESTROYED            = 1372,
    AV_ICEWING_ASSAULTED            = 1380,
    //Stoneheart Bunker
    AV_STONEH_CONTROLLED            = 1364,
    AV_STONEH_DESTROYED             = 1373,
    AV_STONEH_ASSAULTED             = 1381,
    //Horde
    //Iceblood Tower
    AV_ICEBLOOD_CONTROLLED          = 1385,
    AV_ICEBLOOD_DESTROYED           = 1368,
    AV_ICEBLOOD_ASSAULTED           = 1390,
    //Tower Point
    AV_TOWERPOINT_CONTROLLED        = 1384,
    AV_TOWERPOINT_DESTROYED         = 1367, //goes over controlled
    AV_TOWERPOINT_ASSAULTED         = 1389, //goes over destroyed
    //Frostwolf West
    AV_FROSTWOLFW_CONTROLLED        = 1382,
    AV_FROSTWOLFW_DESTROYED         = 1365, //over controlled
    AV_FROSTWOLFW_ASSAULTED         = 1387, //over destroyed
    //Frostwolf East
    AV_FROSTWOLFE_CONTROLLED        = 1383,
    AV_FROSTWOLFE_DESTROYED         = 1366,
    AV_FROSTWOLFE_ASSAULTED         = 1388,

//mines

    AV_N_MINE_N              = 1360,
    AV_N_MINE_A              = 1358,
    AV_N_MINE_H              = 1359,

    AV_S_MINE_N                     = 1357,
    AV_S_MINE_A                     = 1355,
    AV_S_MINE_H                     = 1356,

//towers assaulted by own team (unused)
    AV_STONEH_UNUSED                = 1377,
    AV_ICEWING_UNUSED               = 1376,
    AV_DUNS_UNUSED                  = 1375,
    AV_DUNN_UNUSED                  = 1374,

    AV_ICEBLOOD_UNUSED              = 1395,
    AV_TOWERPOINT_UNUSED            = 1394,
    AV_FROSTWOLFE_UNUSED            = 1393,
    AV_FROSTWOLFW_UNUSED            = 1392
*/
};

enum BG_AV_QuestIds
{
    AV_QUEST_A_SCRAPS1      = 7223,
    AV_QUEST_A_SCRAPS2      = 6781,
    AV_QUEST_H_SCRAPS1      = 7224,
    AV_QUEST_H_SCRAPS2      = 6741,
    AV_QUEST_A_COMMANDER1   = 6942, //soldier
    AV_QUEST_H_COMMANDER1   = 6825,
    AV_QUEST_A_COMMANDER2   = 6941, //leutnant
    AV_QUEST_H_COMMANDER2   = 6826,
    AV_QUEST_A_COMMANDER3   = 6943, //commander
    AV_QUEST_H_COMMANDER3   = 6827,
    AV_QUEST_A_BOSS1        = 7386, // 5 cristal/blood
    AV_QUEST_H_BOSS1        = 7385,
    AV_QUEST_A_BOSS2        = 6881, // 1
    AV_QUEST_H_BOSS2        = 6801,
    AV_QUEST_A_NEAR_MINE    = 5892, //the mine near start location of team
    AV_QUEST_H_NEAR_MINE    = 5893,
    AV_QUEST_A_OTHER_MINE   = 6982, //the other mine ;)
    AV_QUEST_H_OTHER_MINE   = 6985,
    AV_QUEST_A_RIDER_HIDE   = 7026,
    AV_QUEST_H_RIDER_HIDE   = 7002,
    AV_QUEST_A_RIDER_TAME   = 7027,
    AV_QUEST_H_RIDER_TAME   = 7001
};

enum BG_AV_Objectives
{
    AV_OBJECTIVE_ASSAULT_TOWER      = 61,
    AV_OBJECTIVE_ASSAULT_GRAVEYARD  = 63,
    AV_OBJECTIVE_DEFEND_TOWER       = 64,
    AV_OBJECTIVE_DEFEND_GRAVEYARD   = 65
};

enum Texts
{
    // Herold
    // Towers/Graveyards = 1 - 60
    TEXT_COLDTOOTH_MINE_ALLIANCE_TAKEN  = 61,
    TEXT_IRONDEEP_MINE_ALLIANCE_TAKEN   = 62,
    TEXT_COLDTOOTH_MINE_HORDE_TAKEN     = 63,
    TEXT_IRONDEEP_MINE_HORDE_TAKEN      = 64,
    TEXT_FROSTWOLF_GENERAL_DEAD         = 65, /// @todo: sound is missing
    TEXT_STORMPIKE_GENERAL_DEAD         = 66, /// @todo: sound is missing
    TEXT_ALLIANCE_WINS                  = 67, // NYI /// @todo: sound is missing
    TEXT_HORDE_WINS                     = 68, // NYI /// @todo: sound is missing

    // Taskmaster Snivvle
    TEXT_SNIVVLE_RANDOM                 = 0
};

struct StaticNodeInfo
{
    struct
    {
        uint8 AllianceCapture;
        uint8 AllianceAttack;
        uint8 HordeCapture;
        uint8 HordeAttack;
    } TextIds;

    struct
    {
        uint32 AllianceControl;
        uint32 AllianceAssault;
        uint32 HordeControl;
        uint32 HordeAssault;
    } WorldStateIds;
};

struct NodeInfo
{
    BG_AV_States State;
    BG_AV_States PrevState;
    uint32       Timer;
    uint16       TotalOwner;
    uint16       Owner;
    uint16       PrevOwner;
    bool         Tower;
};

inline BG_AV_Nodes &operator++(BG_AV_Nodes& i) { return i = BG_AV_Nodes(i + 1); }

struct BattlegroundAVScore final : public BattlegroundScore
{
    friend class BattlegroundAV;

    protected:
        BattlegroundAVScore(ObjectGuid playerGuid) : BattlegroundScore(playerGuid), GraveyardsAssaulted(0), GraveyardsDefended(0), TowersAssaulted(0), TowersDefended(0), MinesCaptured(0) { }

        void UpdateScore(uint32 type, uint32 value) override
        {
            switch (type)
            {
                case SCORE_GRAVEYARDS_ASSAULTED:
                    GraveyardsAssaulted += value;
                    break;
                case SCORE_GRAVEYARDS_DEFENDED:
                    GraveyardsDefended += value;
                    break;
                case SCORE_TOWERS_ASSAULTED:
                    TowersAssaulted += value;
                    break;
                case SCORE_TOWERS_DEFENDED:
                    TowersDefended += value;
                    break;
                case SCORE_MINES_CAPTURED:
                    MinesCaptured += value;
                    break;
                default:
                    BattlegroundScore::UpdateScore(type, value);
                    break;
            }
        }

        void BuildObjectivesBlock(WorldPacket& data) final override
        {
            data << uint32(5); // Objectives Count
            data << uint32(GraveyardsAssaulted);
            data << uint32(GraveyardsDefended);
            data << uint32(TowersAssaulted);
            data << uint32(TowersDefended);
            data << uint32(MinesCaptured);
        }

        uint32 GetAttr1() const final override { return GraveyardsAssaulted; }
        uint32 GetAttr2() const final override { return GraveyardsDefended; }
        uint32 GetAttr3() const final override { return TowersAssaulted; }
        uint32 GetAttr4() const final override { return TowersDefended; }
        uint32 GetAttr5() const final override { return MinesCaptured; }

        uint32 GraveyardsAssaulted;
        uint32 GraveyardsDefended;
        uint32 TowersAssaulted;
        uint32 TowersDefended;
        uint32 MinesCaptured;
};

class BattlegroundAV : public Battleground
{
    public:
        BattlegroundAV();
        ~BattlegroundAV();

        /* inherited from BattlegroundClass */
        void AddPlayer(Player* player) override;
        void StartingEventCloseDoors() override;
        void StartingEventOpenDoors() override;

        void RemovePlayer(Player* player, ObjectGuid guid, uint32 team) override;
        void HandleAreaTrigger(Player* player, uint32 trigger) override;
        bool SetupBattleground() override;
        void ResetBGSubclass() override;

        /*general stuff*/
        void UpdateScore(uint16 team, int16 points);
        bool UpdatePlayerScore(Player* player, uint32 type, uint32 value, bool doAddHonor = true) override;

        /*handlestuff*/ //these are functions which get called from extern
        void EventPlayerClickedOnFlag(Player* source, GameObject* target_obj) override;
        void HandleKillPlayer(Player* player, Player* killer) override;
        void HandleKillUnit(Creature* unit, Player* killer) override;
        void HandleQuestComplete(uint32 questid, Player* player) override;
        bool CanActivateGO(int32 GOId, uint32 team) const override;

        void EndBattleground(uint32 winner) override;

        WorldSafeLocsEntry const* GetClosestGraveYard(Player* player) override;

        // Achievement: Av perfection and Everything counts
        bool CheckAchievementCriteriaMeet(uint32 criteriaId, Player const* source, Unit const* target = nullptr, uint32 miscvalue1 = 0) override;

        uint32 GetPrematureWinner() override;

    private:
        void PostUpdateImpl(uint32 diff) override;

        /* Nodes occupying */
        void EventPlayerAssaultsPoint(Player* player, uint32 object);
        void EventPlayerDefendsPoint(Player* player, uint32 object);
        void EventPlayerDestroyedPoint(BG_AV_Nodes node);

        void AssaultNode(BG_AV_Nodes node, uint16 team);
        void DestroyNode(BG_AV_Nodes node);
        void InitNode(BG_AV_Nodes node, uint16 team, bool tower);
        void DefendNode(BG_AV_Nodes node, uint16 team);

        void PopulateNode(BG_AV_Nodes node);
        void DePopulateNode(BG_AV_Nodes node);

        static StaticNodeInfo const* GetStaticNodeInfo(uint8 node);

        BG_AV_Nodes GetNodeThroughObject(uint32 object);
        uint32 GetObjectThroughNode(BG_AV_Nodes node);
        bool IsTower(BG_AV_Nodes node) { return m_Nodes[node].Tower; }

        /*mine*/
        void ChangeMineOwner(uint8 mine, uint32 team, bool initial=false);

        /*worldstates*/
        void FillInitialWorldStates(WorldPacket& data) override;
        void SendMineWorldStates(uint32 mine);
        void UpdateNodeWorldState(BG_AV_Nodes node);

        /*general */
        Creature* AddAVCreature(uint16 cinfoid, uint16 type);

        /*variables */
        int32 m_Team_Scores[BG_TEAMS_COUNT];
        uint32 m_Team_QuestStatus[BG_TEAMS_COUNT][9]; //[x][y] x=team y=questcounter

        NodeInfo m_Nodes[BG_AV_NODES_MAX];

        uint32 m_Mine_Owner[2];
        uint32 m_Mine_PrevOwner[2]; //only for worldstates needed
        int32 m_Mine_Timer; //ticks for both teams
        uint32 m_Mine_Reclaim_Timer[2];
        uint32 m_CaptainBuffTimer[BG_TEAMS_COUNT];
        bool m_CaptainAlive[BG_TEAMS_COUNT];

        bool m_IsInformedNearVictory[BG_TEAMS_COUNT];
};

#endif
