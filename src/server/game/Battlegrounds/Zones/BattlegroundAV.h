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

#ifndef __BATTLEGROUNDAV_H
#define __BATTLEGROUNDAV_H

#include "Battleground.h"
#include "BattlegroundScore.h"
#include "Object.h"
#include "QuaternionData.h"
#include "Timer.h"

constexpr uint32 BG_AV_SCORE_INITIAL_POINTS = 700;
constexpr uint32 BG_AV_EVENT_START_BATTLE = 9166; // Achievement: The Alterac Blitz

enum AlteracValleySharedActions
{
    ACTION_BUFF_YELL    = -30001,
    ACTION_AV_INTERACT_CAPTURABLE_OBJECT = 1,
    ACTION_AV_CAPTURE_CAPTURABLE_OBJECT = 2,
};

enum BG_AV_BroadcastTexts
{
    BG_AV_TEXT_START_ONE_MINUTE     = 10638,
    BG_AV_TEXT_START_HALF_MINUTE    = 10639,
    BG_AV_TEXT_BATTLE_HAS_BEGUN     = 10640,

    BG_AV_TEXT_ALLIANCE_NEAR_LOSE   = 23210,
    BG_AV_TEXT_HORDE_NEAR_LOSE      = 23211
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
    ally tower defend
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

    AV_SOUND_ALLIANCE_CAPTAIN               = 8232, //gets called when someone attacks them and at the beginning after 5min+rand(x)*10sec (maybe buff)
    AV_SOUND_HORDE_CAPTAIN                  = 8333
};

constexpr Seconds BG_AV_MINE_RESOURCE_TIMER = 45s;

enum class AlteracValleyMine : uint8
{
    North = 0,
    South
};

enum BG_AV_CreatureIds
{
    BG_AV_CREATURE_VANNDAR              = 11948,
    BG_AV_CREATURE_DREKTHAR             = 11946,
    BG_AV_CREATURE_BALINDA              = 11949,
    BG_AV_CREATURE_GALVANGAR            = 11947,
    BG_AV_CREATURE_MORLOCH              = 11657,
    BG_AV_CREATURE_UMI_THORSON          = 13078,
    BG_AV_CREATURE_KEETAR               = 13079,
    BG_AV_CREATURE_TASKMASTER_SNIVVLE   = 11677,
    BG_AV_CREATURE_AGI_RUMBLESTOMP      = 13086,
    BG_AV_CREATURE_MASHA_SWIFTCUT       = 13088,
    BG_AV_CREATURE_HERALD               = 14848,

    BG_AV_CREATURE_STORMPIKE_DEFENDER   = 12050,
    BG_AV_CREATURE_FROSTWOLF_GUARDIAN   = 12053,
    BG_AV_CREATURE_SEASONED_DEFENDER    = 13326,
    BG_AV_CREATURE_SEASONED_GUARDIAN    = 13328,
    BG_AV_CREATURE_VETERAN_DEFENDER     = 13331,
    BG_AV_CREATURE_VETERAN_GUARDIAN     = 13332,
    BG_AV_CREATURE_CHAMPION_DEFENDER    = 13422,
    BG_AV_CREATURE_CHAMPION_GUARDIAN    = 13421
};

enum BG_AV_ObjectIds
{
    //cause the mangos-system is a bit different, we don't use the right go-ids for every node.. if we want to be 100% like another big server, we must take one object for every node
    //snowfall 4flags as eyecandy 179424 (alliance neutral)
    //Banners - stolen from battleground_AB.h ;-)
    BG_AV_OBJECTID_BANNER_A             = 178925, // can only be used by horde
    BG_AV_OBJECTID_BANNER_H             = 178943, // can only be used by alliance
    BG_AV_OBJECTID_BANNER_CONT_A        = 178940, // can only be used by horde
    BG_AV_OBJECTID_BANNER_CONT_H        = 179435, // can only be used by alliance

    BG_AV_OBJECTID_BANNER_A_B           = 178365,
    BG_AV_OBJECTID_BANNER_H_B           = 178364,
    BG_AV_OBJECTID_BANNER_CONT_A_B      = 179286,
    BG_AV_OBJECTID_BANNER_CONT_H_B      = 179287,
    BG_AV_OBJECTID_BANNER_SNOWFALL_N    = 180418,

    //snowfall eyecandy banner:
    BG_AV_OBJECTID_SNOWFALL_CANDY_A     = 179044,
    BG_AV_OBJECTID_SNOWFALL_CANDY_PA    = 179424,
    BG_AV_OBJECTID_SNOWFALL_CANDY_H     = 179064,
    BG_AV_OBJECTID_SNOWFALL_CANDY_PH    = 179425,

    //banners on top of towers:
    BG_AV_OBJECTID_TOWER_BANNER_A       = 178927, //[PH] Alliance A1 Tower Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_H       = 178955, //[PH] Horde H1 Tower Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_PA      = 179446, //[PH] Alliance H1 Tower Pre-Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_PH      = 179436, //[PH] Horde A1 Tower Pre-Banner BIG

    //Auras
    BG_AV_OBJECTID_AURA_A               = 180421,
    BG_AV_OBJECTID_AURA_H               = 180422,
    BG_AV_OBJECTID_AURA_N               = 180423,
    BG_AV_OBJECTID_AURA_A_S             = 180100,
    BG_AV_OBJECTID_AURA_H_S             = 180101,
    BG_AV_OBJECTID_AURA_N_S             = 180102,

    BG_AV_OBJECTID_GATE                 = 180424,
    BG_AV_GHOST_GATE                    = 180322,

    //mine supplies
    BG_AV_OBJECTID_MINE_N               = 178785,
    BG_AV_OBJECTID_MINE_S               = 178784,

    BG_AV_OBJECTID_FIRE                 = 179065,
    BG_AV_OBJECTID_SMOKE                = 179066,

    // Towers
    BG_AV_OBJECTID_SOUTH_BUNKER_CONTROLLED_TOWER_BANNER = 178927,
    BG_AV_OBJECTID_SOUTH_BUNKER_CONTROLLED_BANNER = 178925,
    BG_AV_OBJECTID_SOUTH_BUNKER_CONTESTED_BANNER = 179435,
    BG_AV_OBJECTID_SOUTH_BUNKER_CONTESTED_TOWER_BANNER = 179436,

    BG_AV_OBJECTID_NORTH_BUNKER_CONTROLLED_TOWER_BANNER = 178932,
    BG_AV_OBJECTID_NORTH_BUNKER_CONTROLLED_BANNER = 178929,
    BG_AV_OBJECTID_NORTH_BUNKER_CONTESTED_BANNER = 179439,
    BG_AV_OBJECTID_NORTH_BUNKER_CONTESTED_TOWER_BANNER = 179440,

    BG_AV_OBJECTID_EAST_TOWER_CONTROLLED_TOWER_BANNER = 178956,
    BG_AV_OBJECTID_EAST_TOWER_CONTROLLED_BANNER = 178944,
    BG_AV_OBJECTID_EAST_TOWER_CONTESTED_BANNER = 179449,
    BG_AV_OBJECTID_EAST_TOWER_CONTESTED_TOWER_BANNER = 179450,

    BG_AV_OBJECTID_WEST_TOWER_CONTROLLED_TOWER_BANNER = 178955,
    BG_AV_OBJECTID_WEST_TOWER_CONTROLLED_BANNER = 178943,
    BG_AV_OBJECTID_WEST_TOWER_CONTESTED_BANNER = 179445,
    BG_AV_OBJECTID_WEST_TOWER_CONTESTED_TOWER_BANNER = 179446,

    BG_AV_OBJECTID_TOWER_POINT_CONTROLLED_TOWER_BANNER = 178957,
    BG_AV_OBJECTID_TOWER_POINT_CONTROLLED_BANNER = 178945,
    BG_AV_OBJECTID_TOWER_POINT_CONTESTED_BANNER = 179453,
    BG_AV_OBJECTID_TOWER_POINT_CONTESTED_TOWER_BANNER = 179454,

    BG_AV_OBJECTID_ICEBLOOD_TOWER_CONTROLLED_TOWER_BANNER = 178958,
    BG_AV_OBJECTID_ICEBLOOD_TOWER_CONTROLLED_BANNER = 178946,
    BG_AV_OBJECTID_ICEBLOOD_TOWER_CONTESTED_BANNER = 178940,
    BG_AV_OBJECTID_ICEBLOOD_TOWER_CONTESTED_TOWER_BANNER = 179458,

    BG_AV_OBJECTID_STONEHEARTH_BUNKER_CONTROLLED_TOWER_BANNER = 178948,
    BG_AV_OBJECTID_STONEHEARTH_BUNKER_CONTROLLED_BANNER = 178936,
    BG_AV_OBJECTID_STONEHEARTH_BUNKER_CONTESTED_BANNER = 179443,
    BG_AV_OBJECTID_STONEHEARTH_BUNKER_CONTESTED_TOWER_BANNER = 179444,

    BG_AV_OBJECTID_ICEWING_BUNKER_CONTROLLED_TOWER_BANNER = 178947,
    BG_AV_OBJECTID_ICEWING_BUNKER_CONTROLLED_BANNER = 178935,
    BG_AV_OBJECTID_ICEWING_BUNKER_CONTESTED_BANNER = 179441,
    BG_AV_OBJECTID_ICEWING_BUNKER_CONTESTED_TOWER_BANNER = 179442,

    // Graveyards
    BG_AV_OBJECTID_AID_STATION_ALLIANCE_CONTROLLED = 179465,
    BG_AV_OBJECTID_AID_STATION_HORDE_CONTESTED = 179468,
    BG_AV_OBJECTID_AID_STATION_HORDE_CONTROLLED = 179467,
    BG_AV_OBJECTID_AID_STATION_ALLIANCE_CONTESTED = 179466,

    BG_AV_OBJECTID_STORMPIKE_ALLIANCE_CONTROLLED = 178389,
    BG_AV_OBJECTID_STORMPIKE_HORDE_CONTESTED = 179287,
    BG_AV_OBJECTID_STORMPIKE_HORDE_CONTROLLED = 178388,
    BG_AV_OBJECTID_STORMPIKE_ALLIANCE_CONTESTED = 179286,

    BG_AV_OBJECTID_STONEHEARTH_HORDE_CONTESTED = 179310,
    BG_AV_OBJECTID_STONEHEARTH_HORDE_CONTROLLED = 179285,
    BG_AV_OBJECTID_STONEHEARTH_ALLIANCE_CONTESTED = 179308,
    BG_AV_OBJECTID_STONEHEARTH_ALLIANCE_CONTROLLED = 179284,

    BG_AV_OBJECTID_SNOWFALL_NEUTRAL = 180418,
    BG_AV_OBJECTID_SNOWFALL_HORDE_CONTESTED = 180420,
    BG_AV_OBJECTID_SNOWFALL_ALLIANCE_CONTESTED = 180419,
    BG_AV_OBJECTID_SNOWFALL_HORDE_CONTROLLED = 178364,
    BG_AV_OBJECTID_SNOWFALL_ALLIANCE_CONTROLLED = 178365,

    BG_AV_OBJECTID_ICEBLOOD_HORDE_CONTROLLED = 179483,
    BG_AV_OBJECTID_ICEBLOOD_ALLIANCE_CONTESTED = 179482,
    BG_AV_OBJECTID_ICEBLOOD_ALLIANCE_CONTROLLED = 179481,
    BG_AV_OBJECTID_ICEBLOOD_HORDE_CONTESTED = 179484,

    BG_AV_OBJECTID_FROSTWOLF_HORDE_CONTROLLED = 178393,
    BG_AV_OBJECTID_FROSTWOLF_ALLIANCE_CONTESTED = 179304,
    BG_AV_OBJECTID_FROSTWOLF_ALLIANCE_CONTROLLED = 178394,
    BG_AV_OBJECTID_FROSTWOLF_HORDE_CONTESTED = 179305,

    BG_AV_OBJECTID_FROSTWOLF_HUT_HORDE_CONTROLLED = 179472,
    BG_AV_OBJECTID_FROSTWOLF_HUT_ALLIANCE_CONTESTED = 179471,
    BG_AV_OBJECTID_FROSTWOLF_HUT_ALLIANCE_CONTROLLED = 179470,
    BG_AV_OBJECTID_FROSTWOLF_HUT_HORDE_CONTESTED = 179473
};

enum BG_AV_Nodes
{
    BG_AV_NODES_FIRSTAID_STATION        = 0,
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
    AV_WS_ALLIANCE_REINFORCEMENTS       = 3127,
    AV_WS_HORDE_REINFORCEMENTS          = 3128,
    AV_WS_SHOW_HORDE_REINFORCEMENTS     = 3133,
    AV_WS_SHOW_ALLIANCE_REINFORCEMENTS  = 3134,
    AV_WS_MAX_REINFORCEMENTS            = 3136,

// Graves
    // Alliance
    //Stormpike first aid station
    AV_WS_STORMPIKE_AID_STATION_ALLIANCE_CONTROLLED             = 1325,
    AV_WS_STORMPIKE_AID_STATION_IN_CONFLICT_ALLIANCE_ATTACKING  = 1326,
    AV_WS_STORMPIKE_AID_STATION_HORDE_CONTROLLED                = 1327,
    AV_WS_STORMPIKE_AID_STATION_IN_CONFLICT_HORDE_ATTACKING     = 1328,
    //Stormpike Graveyard
    AV_WS_STORMPIKE_GRAVEYARD_ALLIANCE_CONTROLLED               = 1333,
    AV_WS_STORMPIKE_GRAVEYARD_IN_CONFLICT_ALLIANCE_ATTACKING    = 1335,
    AV_WS_STORMPIKE_GRAVEYARD_HORDE_CONTROLLED                  = 1334,
    AV_WS_STORMPIKE_GRAVEYARD_IN_CONFLICT_HORDE_ATTACKING       = 1336,
    //Stoneheart Grave
    AV_WS_STONEHEARTH_GRAVEYARD_ALLIANCE_CONTROLLED             = 1302,
    AV_WS_STONEHEARTH_GRAVEYARD_IN_CONFLICT_ALLIANCE_ATTACKING  = 1304,
    AV_WS_STONEHEARTH_GRAVEYARD_HORDE_CONTROLLED                = 1301,
    AV_WS_STONEHEARTH_GRAVEYARD_IN_CONFLICT_HORDE_ATTACKING     = 1303,
    //Neutral
    //Snowfall Grave
    AV_WS_SNOWFALL_GRAVEYARD_UNCONTROLLED                       = 1966,
    AV_WS_SNOWFALL_GRAVEYARD_ALLIANCE_CONTROLLED                = 1341,
    AV_WS_SNOWFALL_GRAVEYARD_IN_CONFLICT_ALLIANCE_ATTACKING     = 1343,
    AV_WS_SNOWFALL_GRAVEYARD_HORDE_CONTROLLED                   = 1342,
    AV_WS_SNOWFALL_GRAVEYARD_IN_CONFLICT_HORDE_ATTACKING        = 1344,
    //Horde
    //Iceblood grave
    AV_WS_ICEBLOOD_GRAVEYARD_ALLIANCE_CONTROLLED                = 1346,
    AV_WS_ICEBLOOD_GRAVEYARD_IN_CONFLICT_ALLIANCE_ATTACKING     = 1348,
    AV_WS_ICEBLOOD_GRAVEYARD_HORDE_CONTROLLED                   = 1347,
    AV_WS_ICEBLOOD_GRAVEYARD_IN_CONFLICT_HORDE_ATTACKING        = 1349,
    //Frostwolf Grave
    AV_WS_FROSTWOLF_GRAVEYARD_ALLIANCE_CONTROLLED               = 1337,
    AV_WS_FROSTWOLF_GRAVEYARD_IN_CONFLICT_ALLIANCE_ATTACKING    = 1339,
    AV_WS_FROSTWOLF_GRAVEYARD_HORDE_CONTROLLED                  = 1338,
    AV_WS_FROSTWOLF_GRAVEYARD_IN_CONFLICT_HORDE_ATTACKING       = 1340,
    //Frostwolf Hut
    AV_WS_FROSTWOLF_RELIEF_HUT_ALLIANCE_CONTROLLED              = 1329,
    AV_WS_FROSTWOLF_RELIEF_HUT_IN_CONFLICT_ALLIANCE_ATTACKING   = 1331,
    AV_WS_FROSTWOLF_RELIEF_HUT_HORDE_CONTROLLED                 = 1330,
    AV_WS_FROSTWOLF_RELIEF_HUT_IN_CONFLICT_HORDE_ATTACKING      = 1332,

//Towers
    //Alliance
    //Dunbaldar South Bunker
    AV_WS_DUN_BALDAR_SOUTH_BUNKER_OWNER                             = 1181,
    AV_WS_DUN_BALDAR_SOUTH_BUNKER_ALLIANCE_CONTROLLED               = 1361,
    AV_WS_DUN_BALDAR_SOUTH_BUNKER_DESTROYED                         = 1370,
    AV_WS_DUN_BALDAR_SOUTH_BUNKER_IN_CONFLICT_HORDE_ATTACKING       = 1378,
    AV_WS_DUN_BALDAR_SOUTH_BUNKER_IN_CONFLICT_ALLIANCE_ATTACKING    = 1374, // unused
    //Dunbaldar North Bunker
    AV_WS_DUN_BALDAR_NORTH_BUNKER_OWNER                             = 1182,
    AV_WS_DUN_BALDAR_NORTH_BUNKER_ALLIANCE_CONTROLLED               = 1362,
    AV_WS_DUN_BALDAR_NORTH_BUNKER_DESTROYED                         = 1371,
    AV_WS_DUN_BALDAR_NORTH_BUNKER_IN_CONFLICT_HORDE_ATTACKING       = 1379,
    AV_WS_DUN_BALDAR_NORTH_BUNKER_IN_CONFLICT_ALLIANCE_ATTACKING    = 1375, // unused
    //Icewing Bunker
    AV_WS_ICEWING_BUNKER_OWNER                                      = 1183,
    AV_WS_ICEWING_BUNKER_ALLIANCE_CONTROLLED                        = 1363,
    AV_WS_ICEWING_BUNKER_DESTROYED                                  = 1372,
    AV_WS_ICEWING_BUNKER_IN_CONFLICT_HORDE_ATTACKING                = 1380,
    AV_WS_ICEWING_BUNKER_IN_CONFLICT_ALLIANCE_ATTACKING             = 1376, // unused
    //Stoneheart Bunker
    AV_WS_STONEHEARTH_BUNKER_OWNER                                  = 1184,
    AV_WS_STONEHEARTH_BUNKER_ALLIANCE_CONTROLLED                    = 1364,
    AV_WS_STONEHEARTH_BUNKER_DESTROYED                              = 1373,
    AV_WS_STONEHEARTH_BUNKER_IN_CONFLICT_HORDE_ATTACKING            = 1381,
    AV_WS_STONEHEARTH_BUNKER_IN_CONFLICT_ALLIANCE_ATTACKING         = 1377, // unused
    //Horde
    //Iceblood Tower
    AV_WS_ICEBLOOD_TOWER_OWNER                                      = 1187,
    AV_WS_ICEBLOOD_TOWER_DESTROYED                                  = 1368,
    AV_WS_ICEBLOOD_TOWER_HORDE_CONTROLLED                           = 1385,
    AV_WS_ICEBLOOD_TOWER_IN_CONFLICT_ALLIANCE_ATTACKING             = 1390,
    AV_WS_ICEBLOOD_TOWER_IN_CONFLICT_HORDE_ATTACKING                = 1395, // unused
    //Tower Point
    AV_WS_TOWER_POINT_OWNER                                         = 1188,
    AV_WS_TOWER_POINT_DESTROYED                                     = 1367,
    AV_WS_TOWER_POINT_HORDE_CONTROLLED                              = 1384,
    AV_WS_TOWER_POINT_IN_CONFLICT_ALLIANCE_ATTACKING                = 1389,
    AV_WS_TOWER_POINT_IN_CONFLICT_HORDE_ATTACKING                   = 1394, // unused
    //Frostwolf West
    AV_WS_WEST_FROSTWOLF_TOWER_OWNER                                = 1185,
    AV_WS_WEST_FROSTWOLF_TOWER_DESTROYED                            = 1365,
    AV_WS_WEST_FROSTWOLF_TOWER_HORDE_CONTROLLED                     = 1382,
    AV_WS_WEST_FROSTWOLF_TOWER_IN_CONFLICT_ALLIANCE_ATTACKING       = 1387,
    AV_WS_WEST_FROSTWOLF_TOWER_IN_CONFLICT_HORDE_ATTACKING          = 1392, // unused
    //Frostwolf East
    AV_WS_EAST_FROSTWOLF_TOWER_OWNER                                = 1186,
    AV_WS_EAST_FROSTWOLF_TOWER_DESTROYED                            = 1366,
    AV_WS_EAST_FROSTWOLF_TOWER_HORDE_CONTROLLED                     = 1383,
    AV_WS_EAST_FROSTWOLF_TOWER_IN_CONFLICT_ALLIANCE_ATTACKING       = 1388,
    AV_WS_EAST_FROSTWOLF_TOWER_IN_CONFLICT_HORDE_ATTACKING          = 1393, // unused

//Mines
    AV_WS_IRONDEEP_MINE_OWNER                   = 801,
    AV_WS_IRONDEEP_MINE_TROGG_CONTROLLED        = 1360,
    AV_WS_IRONDEEP_MINE_ALLIANCE_CONTROLLED     = 1358,
    AV_WS_IRONDEEP_MINE_HORDE_CONTROLLED        = 1359,

    AV_WS_COLDTOOTH_MINE_OWNER                  = 804,
    AV_WS_COLDTOOTH_MINE_KOBOLD_CONTROLLED      = 1357,
    AV_WS_COLDTOOTH_MINE_ALLIANCE_CONTROLLED    = 1355,
    AV_WS_COLDTOOTH_MINE_HORDE_CONTROLLED       = 1356,

//Turnins
    AV_WS_IVUS_STORM_CRYSTAL_COUNT                  = 1043,
    AV_WS_IVUS_STORM_CRYSTAL_MAX                    = 1044,
    AV_WS_LOKHOLAR_STORMPIKE_SOLDIERS_BLOOD_COUNT   = 923,
    AV_WS_LOKHOLAR_STORMPIKE_SOLDIERS_BLOOD_MAX     = 922,

//Bosses
    AV_WS_DREKTHAR_ALIVE    = 601,
    AV_WS_VANDAAR_ALIVE     = 602,

//Captains
    AV_WS_GALVAGAR_ALIVE    = 1352,
    AV_WS_BALINDA_ALIVE     = 1351,
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

struct StaticMineInfo
{
    int32 WorldStateOwner;
    int32 WorldStateAllianceControlled;
    int32 WorldStateHordeControlled;
    int32 WorldStateNeutralControlled;
    uint8 TextIdAlliance;
    uint8 TextIdHorde;
};

struct AlteracValleyMineInfo
{
    Team Owner;

    StaticMineInfo StaticInfo;
};

struct StaticNodeInfo
{
    BG_AV_Nodes NodeId;

    struct
    {
        uint8 AllianceCapture;
        uint8 AllianceAttack;
        uint8 HordeCapture;
        uint8 HordeAttack;
    } TextIds;

    struct
    {
        int32 AllianceControl;
        int32 AllianceAssault;
        int32 HordeControl;
        int32 HordeAssault;
        int32 Owner;
    } WorldStateIds;

    struct
    {
        std::string AllianceOrDefend;
        std::string HordeOrDestroy;
    } StringIds;
};

static StaticNodeInfo const BGAVNodeInfo[] =
{
    { BG_AV_NODES_FIRSTAID_STATION,  { 47, 48, 45, 46 }, { 1325, 1326, 1327, 1328, 0 }, { "bg_av_herald_stormpike_aid_station_alliance", "bg_av_herald_stormpike_aid_station_horde" } }, // Stormpike First Aid Station
    { BG_AV_NODES_STORMPIKE_GRAVE,   {  1,  2,  3,  4 }, { 1333, 1335, 1334, 1336, 0 }, { "bg_av_herald_stormpike_alliance", "bg_av_herald_stormpike_horde" } }, // Stormpike Graveyard
    { BG_AV_NODES_STONEHEART_GRAVE,  { 55, 56, 53, 54 }, { 1302, 1304, 1301, 1303, 0 }, { "bg_av_herald_stonehearth_alliance", "bg_av_herald_stonehearth_horde" } }, // Stoneheart Graveyard
    { BG_AV_NODES_SNOWFALL_GRAVE,    {  5,  6,  7,  8 }, { 1341, 1343, 1342, 1344, 0 }, { "bg_av_herald_snowfall_alliance", "bg_av_herald_snowfall_horde" } }, // Snowfall Graveyard
    { BG_AV_NODES_ICEBLOOD_GRAVE,    { 59, 60, 57, 58 }, { 1346, 1348, 1347, 1349, 0 }, { "bg_av_herald_iceblood_alliance", "bg_av_herald_iceblood_horde" } }, // Iceblood Graveyard
    { BG_AV_NODES_FROSTWOLF_GRAVE,   {  9, 10, 11, 12 }, { 1337, 1339, 1338, 1340, 0 }, { "bg_av_herald_frostwolf_alliance", "bg_av_herald_frostwolf_horde" } }, // Frostwolf Graveyard
    { BG_AV_NODES_FROSTWOLF_HUT,     { 51, 52, 49, 50 }, { 1329, 1331, 1330, 1332, 0 }, { "bg_av_herald_frostwolf_hut_alliance", "bg_av_herald_frostwolf_hut_horde" } }, // Frostwolf Hut
    { BG_AV_NODES_DUNBALDAR_SOUTH,   { 16, 15, 14, 13 }, { 1361, 1375, 1370, 1378, 1181 }, { "bg_av_herald_south_bunker_defend", "bg_av_herald_south_bunker_attack" } }, // Dunbaldar South Bunker
    { BG_AV_NODES_DUNBALDAR_NORTH,   { 20, 19, 18, 17 }, { 1362, 1374, 1371, 1379, 1182 }, { "bg_av_herald_north_bunker_defend", "bg_av_herald_south_bunker_attack" } }, // Dunbaldar North Bunker
    { BG_AV_NODES_ICEWING_BUNKER,    { 24, 23, 22, 21 }, { 1363, 1376, 1372, 1380, 1183 }, { "bg_av_herald_icewing_bunker_defend", "bg_av_herald_icewing_bunker_attack" } }, // Icewing Bunker
    { BG_AV_NODES_STONEHEART_BUNKER, { 28, 27, 26, 25 }, { 1364, 1377, 1373, 1381, 1184 }, { "bg_av_herald_stonehearth_bunker_defend", "bg_av_herald_stonehearth_bunker_attack" } }, // Stoneheart Bunker
    { BG_AV_NODES_ICEBLOOD_TOWER,    { 44, 43, 42, 41 }, { 1368, 1390, 1385, 1395, 1188 }, { "bg_av_herald_iceblood_tower_defend", "bg_av_herald_iceblood_tower_attack" } }, // Iceblood Tower
    { BG_AV_NODES_TOWER_POINT,       { 40, 39, 38, 37 }, { 1367, 1389, 1384, 1394, 1187 }, { "bg_av_herald_tower_point_defend", "bg_av_herald_tower_point_attack" } }, // Tower Point
    { BG_AV_NODES_FROSTWOLF_ETOWER,  { 36, 35, 34, 33 }, { 1366, 1388, 1383, 1393, 1186 }, { "bg_av_herald_east_tower_defend", "bg_av_herald_east_tower_attack" } }, // Frostwolf East Tower
    { BG_AV_NODES_FROSTWOLF_WTOWER,  { 32, 31, 30, 29 }, { 1365, 1387, 1382, 1392, 1185 }, { "bg_av_herald_west_tower_defend", "bg_av_herald_west_tower_attack" } }, // Frostwolf West Tower
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

enum BG_AV_ExploitTeleportLocations
{
    AV_EXPLOIT_TELEPORT_LOCATION_ALLIANCE = 3664,
    AV_EXPLOIT_TELEPORT_LOCATION_HORDE = 3665
};

struct BG_AV_NodeInfo
{
    BG_AV_States State;
    BG_AV_States PrevState;
    uint16       TotalOwner;
    Team         Owner;
    uint16       PrevOwner;
    bool         Tower;
};

inline BG_AV_Nodes &operator++(BG_AV_Nodes& i) { return i = BG_AV_Nodes(i + 1); }

enum BG_AV_Data : uint32
{
    DATA_DEFENDER_TIER_HORDE = 1,
    DATA_DEFENDER_TIER_ALLIANCE = 2,
};

enum BG_AV_DefenderTier : uint32
{
    BG_AV_DEFENDER_TIER_DEFENDER,
    BG_AV_DEFENDER_TIER_SEASONED,
    BG_AV_DEFENDER_TIER_VETERAN,
    BG_AV_DEFENDER_TIER_CHAMPION
};

class BattlegroundAV : public Battleground
{
    public:
        BattlegroundAV(BattlegroundTemplate const* battlegroundTemplate);
        ~BattlegroundAV() = default;

        /* inherited from BattlegroundClass */
        void StartingEventOpenDoors() override;

        void RemovePlayer(Player* player, ObjectGuid guid, uint32 team) override;
        void HandleAreaTrigger(Player* player, uint32 trigger, bool entered) override;
        bool SetupBattleground() override;

        /*general stuff*/
        void UpdateScore(Team team, int16 points);

        // Handle Stuff
        void HandleInteractCapturableObject(Player* player, GameObject* target);
        //these are functions which get called from extern
        void HandleKillPlayer(Player* player, Player* killer) override;
        void HandleKillUnit(Creature* unit, Unit* killer) override;
        void HandleQuestComplete(uint32 questid, Player* player) override;

        void EndBattleground(Team winner) override;

        WorldSafeLocsEntry const* GetExploitTeleportLocation(Team team) override;

        Team GetPrematureWinner() override;
        void OnGameObjectCreate(GameObject* gameObject) override;
        void OnCreatureCreate(Creature* creature) override;

        uint32 GetData(uint32 dataId) const override;

    private:
        void PostUpdateImpl(uint32 diff) override;
        bool IsCaptainAlive(TeamId teamId) const;

        /* Nodes occupying */
        void EventPlayerAssaultsPoint(Player* player, uint32 object);
        void EventPlayerDefendsPoint(Player* player, uint32 object);
        void EventPlayerDestroyedPoint(GameObject* gameobject);
        void DoAction([[maybe_unused]] uint32 actionId, [[maybe_unused]] WorldObject* source = nullptr, [[maybe_unused]] WorldObject* target = nullptr) override;

        void AssaultNode(BG_AV_Nodes node, Team team);
        void DestroyNode(BG_AV_Nodes node);
        void InitNode(BG_AV_Nodes node, Team team, bool tower);
        void DefendNode(BG_AV_Nodes node, Team team);

        StaticNodeInfo const* GetStaticNodeInfo(BG_AV_Nodes node) const
        {
            for (uint8 i = 0; i < BG_AV_NODES_MAX; ++i)
                if (BGAVNodeInfo[i].NodeId == node)
                    return &BGAVNodeInfo[i];
            return nullptr;
        }

        BG_AV_Nodes GetNodeThroughObject(uint32 object);
        bool IsTower(BG_AV_Nodes node) const { return _nodes[node].Tower; }

        /*mine*/
        void ChangeMineOwner(AlteracValleyMine mine, Team team, bool initial = false);

        /*worldstates*/
        void SendMineWorldStates(AlteracValleyMine mine);
        void UpdateNodeWorldState(BG_AV_Nodes node);

        Creature* FindHerald(std::string_view stringId) const;

        /*variables */
        std::array<int32, PVP_TEAMS_COUNT> _teamResources;
        uint32 m_Team_QuestStatus[PVP_TEAMS_COUNT][9]; //[x][y] x=team y=questcounter

        std::array<BG_AV_NodeInfo, BG_AV_NODES_MAX> _nodes;

        TimeTracker _mineResourceTimer; //ticks for both teams

        std::array<AlteracValleyMineInfo, 2> _mineInfo;

        std::array<TimeTracker, PVP_TEAMS_COUNT> _captainBuffTimer;

        std::array<bool, PVP_TEAMS_COUNT> _isInformedNearVictory;
        GuidUnorderedSet _doorGUIDs;
        ObjectGuid _balindaGUID;
        ObjectGuid _galvangarGUID;
        GuidUnorderedSet _heraldGUIDs;
};

#endif
