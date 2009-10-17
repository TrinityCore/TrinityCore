/*
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
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
#ifndef OUTDOOR_PVP_NA_
#define OUTDOOR_PVP_NA_
// TODO: "sometimes" set to neutral
#include "OutdoorPvPImpl.h"
enum OutdoorPvPNASpells
{
    NA_KILL_TOKEN_ALLIANCE = 33005,
    NA_KILL_TOKEN_HORDE = 33004,
    NA_CAPTURE_BUFF = 33795  // strength of the halaani
};
// kill credit for pks
const uint32 NA_CREDIT_MARKER = 24867;
const uint32 NA_GUARDS_MAX = 15;
const uint32 NA_BUFF_ZONE = 3518;
const uint32 NA_HALAA_GRAVEYARD = 993;
const uint32 NA_HALAA_GRAVEYARD_ZONE = 3518; // need to add zone id, not area id
const uint32 NA_RESPAWN_TIME = 3600000; // one hour to capture after defeating all guards
const uint32 NA_GUARD_CHECK_TIME = 500; // every half second
enum OutdoorPvPNAWorldStates{
    NA_UI_HORDE_GUARDS_SHOW = 2503,
    NA_UI_ALLIANCE_GUARDS_SHOW = 2502,
    NA_UI_GUARDS_MAX = 2493,
    NA_UI_GUARDS_LEFT = 2491,
    NA_UI_TOWER_SLIDER_DISPLAY = 2495,
    NA_UI_TOWER_SLIDER_POS = 2494,
    NA_UI_TOWER_SLIDER_N = 2497,
    NA_MAP_WYVERN_NORTH_NEU_H = 2762,
    NA_MAP_WYVERN_NORTH_NEU_A = 2662,
    NA_MAP_WYVERN_NORTH_H = 2663,
    NA_MAP_WYVERN_NORTH_A = 2664,
    NA_MAP_WYVERN_SOUTH_NEU_H = 2760,
    NA_MAP_WYVERN_SOUTH_NEU_A = 2670,
    NA_MAP_WYVERN_SOUTH_H = 2668,
    NA_MAP_WYVERN_SOUTH_A = 2669,
    NA_MAP_WYVERN_WEST_NEU_H = 2761,
    NA_MAP_WYVERN_WEST_NEU_A = 2667,
    NA_MAP_WYVERN_WEST_H = 2665,
    NA_MAP_WYVERN_WEST_A = 2666,
    NA_MAP_WYVERN_EAST_NEU_H = 2763,
    NA_MAP_WYVERN_EAST_NEU_A = 2659,
    NA_MAP_WYVERN_EAST_H = 2660,
    NA_MAP_WYVERN_EAST_A = 2661,
    NA_MAP_HALAA_NEUTRAL = 2671,
    NA_MAP_HALAA_NEU_A = 2676,
    NA_MAP_HALAA_NEU_H = 2677,
    NA_MAP_HALAA_HORDE = 2672,
    NA_MAP_HALAA_ALLIANCE = 2673
};
const uint32 FLIGHT_NODES_NUM = 4;
// used to access the elements of Horde/AllyControlGOs
enum ControlGOTypes{
    NA_ROOST_S = 0,
    NA_ROOST_W = 1,
    NA_ROOST_N = 2,
    NA_ROOST_E = 3,
    NA_BOMB_WAGON_S = 4,
    NA_BOMB_WAGON_W = 5,
    NA_BOMB_WAGON_N = 6,
    NA_BOMB_WAGON_E = 7,
    NA_DESTROYED_ROOST_S = 8,
    NA_DESTROYED_ROOST_W = 9,
    NA_DESTROYED_ROOST_N = 10,
    NA_DESTROYED_ROOST_E = 11,
    NA_CONTROL_GO_NUM = 12
};
const uint32 FlightPathStartNodes[FLIGHT_NODES_NUM] = {103,105,107,109};
const uint32 FlightPathEndNodes[FLIGHT_NODES_NUM] = {104,106,108,110};
enum FlightSpellsNA{
    NA_SPELL_FLY_SOUTH = 32059,
    NA_SPELL_FLY_WEST = 32068,
    NA_SPELL_FLY_NORTH = 32075,
    NA_SPELL_FLY_EAST = 32081
};
// spawned when the alliance is attacking, horde is in control
const go_type HordeControlGOs[NA_CONTROL_GO_NUM] = {
    {182267,530,-1815.8,8036.51,-26.2354,-2.89725,0,0,0.992546,-0.121869}, //ALLY_ROOST_SOUTH
    {182280,530,-1507.95,8132.1,-19.5585,-1.3439,0,0,0.622515,-0.782608}, //ALLY_ROOST_WEST
    {182281,530,-1384.52,7779.33,-11.1663,-0.575959,0,0,0.284015,-0.95882}, //ALLY_ROOST_NORTH
    {182282,530,-1650.11,7732.56,-15.4505,-2.80998,0,0,0.986286,-0.165048}, //ALLY_ROOST_EAST
    {182222,530,-1825.4022,8039.2602,-26.08,-2.89725,0,0,0.992546,-0.121869}, //HORDE_BOMB_WAGON_SOUTH
    {182272,530,-1515.37,8136.91,-20.42,-1.3439,0,0,0.622515,-0.782608}, //HORDE_BOMB_WAGON_WEST
    {182273,530,-1377.95,7773.44,-10.31,-0.575959,0,0,0.284015,-0.95882}, //HORDE_BOMB_WAGON_NORTH
    {182274,530,-1659.87,7733.15,-15.75,-2.80998,0,0,0.986286,-0.165048}, //HORDE_BOMB_WAGON_EAST
    {182266,530,-1815.8,8036.51,-26.2354,-2.89725,0,0,0.992546,-0.121869}, //DESTROYED_ALLY_ROOST_SOUTH
    {182275,530,-1507.95,8132.1,-19.5585,-1.3439,0,0,0.622515,-0.782608}, //DESTROYED_ALLY_ROOST_WEST
    {182276,530,-1384.52,7779.33,-11.1663,-0.575959,0,0,0.284015,-0.95882}, //DESTROYED_ALLY_ROOST_NORTH
    {182277,530,-1650.11,7732.56,-15.4505,-2.80998,0,0,0.986286,-0.165048}  //DESTROYED_ALLY_ROOST_EAST
};
// spawned when the horde is attacking, alliance is in control
const go_type AllianceControlGOs[NA_CONTROL_GO_NUM] = {
    {182301,530,-1815.8,8036.51,-26.2354,-2.89725,0,0,0.992546,-0.121869}, //HORDE_ROOST_SOUTH
    {182302,530,-1507.95,8132.1,-19.5585,-1.3439,0,0,0.622515,-0.782608}, //HORDE_ROOST_WEST
    {182303,530,-1384.52,7779.33,-11.1663,-0.575959,0,0,0.284015,-0.95882}, //HORDE_ROOST_NORTH
    {182304,530,-1650.11,7732.56,-15.4505,-2.80998,0,0,0.986286,-0.165048}, //HORDE_ROOST_EAST
    {182305,530,-1825.4022,8039.2602,-26.08,-2.89725,0,0,0.992546,-0.121869}, //ALLY_BOMB_WAGON_SOUTH
    {182306,530,-1515.37,8136.91,-20.42,-1.3439,0,0,0.622515,-0.782608}, //ALLY_BOMB_WAGON_WEST
    {182307,530,-1377.95,7773.44,-10.31,-0.575959,0,0,0.284015,-0.95882}, //ALLY_BOMB_WAGON_NORTH
    {182308,530,-1659.87,7733.15,-15.75,-2.80998,0,0,0.986286,-0.165048}, //ALLY_BOMB_WAGON_EAST
    {182297,530,-1815.8,8036.51,-26.2354,-2.89725,0,0,0.992546,-0.121869}, //DESTROYED_HORDE_ROOST_SOUTH
    {182298,530,-1507.95,8132.1,-19.5585,-1.3439,0,0,0.622515,-0.782608}, //DESTROYED_HORDE_ROOST_WEST
    {182299,530,-1384.52,7779.33,-11.1663,-0.575959,0,0,0.284015,-0.95882}, //DESTROYED_HORDE_ROOST_NORTH
    {182300,530,-1650.11,7732.56,-15.4505,-2.80998,0,0,0.986286,-0.165048}  //DESTROYED_HORDE_ROOST_EAST
};
enum ControlNPCTypes{
    NA_NPC_RESEARCHER = 0,
    NA_NPC_QUARTERMASTER,
    NA_NPC_BLADE_MERCHANT,
    NA_NPC_FOOD_MERCHANT,
    NA_NPC_AMMO,
    NA_NPC_GUARD_01,
    NA_NPC_GUARD_02,
    NA_NPC_GUARD_03,
    NA_NPC_GUARD_04,
    NA_NPC_GUARD_05,
    NA_NPC_GUARD_06,
    NA_NPC_GUARD_07,
    NA_NPC_GUARD_08,
    NA_NPC_GUARD_09,
    NA_NPC_GUARD_10,
    NA_NPC_GUARD_11,
    NA_NPC_GUARD_12,
    NA_NPC_GUARD_13,
    NA_NPC_GUARD_14,
    NA_NPC_GUARD_15,
    NA_CONTROL_NPC_NUM
};
const creature_type HordeControlNPCs[NA_CONTROL_NPC_NUM] = {
    {18816,67,530,-1523.92,7951.76,-17.6942,3.51172},
    {18821,67,530,-1527.75,7952.46,-17.6948,3.99317},
    {21474,67,530,-1520.14,7927.11,-20.2527,3.39389},
    {21484,67,530,-1524.84,7930.34,-20.182,3.6405},
    {21483,67,530,-1570.01,7993.8,-22.4505,5.02655},
    {18192,67,530,-1654.06,8000.46,-26.59,3.37},
    {18192,67,530,-1487.18,7899.1,-19.53,0.954},
    {18192,67,530,-1480.88,7908.79,-19.19,4.485},
    {18192,67,530,-1540.56,7995.44,-20.45,0.947},
    {18192,67,530,-1546.95,8000.85,-20.72,6.035},
    {18192,67,530,-1595.31,7860.53,-21.51,3.747},
    {18192,67,530,-1642.31,7995.59,-25.8,3.317},
    {18192,67,530,-1545.46,7995.35,-20.63,1.094},
    {18192,67,530,-1487.58,7907.99,-19.27,5.567},
    {18192,67,530,-1651.54,7988.56,-26.5289,2.98451},
    {18192,67,530,-1602.46,7866.43,-22.1177,4.74729},
    {18192,67,530,-1591.22,7875.29,-22.3536,4.34587},
    {18192,67,530,-1550.6,7944.45,-21.63,3.559},
    {18192,67,530,-1545.57,7935.83,-21.13,3.448},
    {18192,67,530,-1550.86,7937.56,-21.7,3.801}
};
const creature_type AllianceControlNPCs[NA_CONTROL_NPC_NUM] = {
    {18817,469,530,-1591.18,8020.39,-22.2042,4.59022},
    {18822,469,530,-1588.0,8019.0,-22.2042,4.06662},
    {21485,469,530,-1521.93,7927.37,-20.2299,3.24631},
    {21487,469,530,-1540.33,7971.95,-20.7186,3.07178},
    {21488,469,530,-1570.01,7993.8,-22.4505,5.02655},
    {18256,469,530,-1654.06,8000.46,-26.59,3.37},
    {18256,469,530,-1487.18,7899.1,-19.53,0.954},
    {18256,469,530,-1480.88,7908.79,-19.19,4.485},
    {18256,469,530,-1540.56,7995.44,-20.45,0.947},
    {18256,469,530,-1546.95,8000.85,-20.72,6.035},
    {18256,469,530,-1595.31,7860.53,-21.51,3.747},
    {18256,469,530,-1642.31,7995.59,-25.8,3.317},
    {18256,469,530,-1545.46,7995.35,-20.63,1.094},
    {18256,469,530,-1487.58,7907.99,-19.27,5.567},
    {18256,469,530,-1651.54,7988.56,-26.5289,2.98451},
    {18256,469,530,-1602.46,7866.43,-22.1177,4.74729},
    {18256,469,530,-1591.22,7875.29,-22.3536,4.34587},
    {18256,469,530,-1603.75,8000.36,-24.18,4.516},
    {18256,469,530,-1585.73,7994.68,-23.29,4.439},
    {18256,469,530,-1595.5,7991.27,-23.53,4.738}
};
enum WyvernStates{
    WYVERN_NEU_HORDE = 1,
    WYVERN_NEU_ALLIANCE = 2,
    WYVERN_HORDE = 4,
    WYVERN_ALLIANCE = 8
};
enum HalaaStates{
    HALAA_N = 1,
    HALAA_N_A = 2,
    HALAA_A = 4,
    HALAA_N_H = 8,
    HALAA_H = 16
};
class Unit;
class Creature;
class OutdoorPvPNA;
class OPvPCapturePointNA : public OPvPCapturePoint
{
friend class OutdoorPvPNA;
public:
    OPvPCapturePointNA(OutdoorPvP * pvp);
    bool Update(uint32 diff);
    void ChangeState();
    void SendChangePhase();
    void FillInitialWorldStates(WorldPacket & data);
    // used when player is activated/inactivated in the area
    bool HandlePlayerEnter(Player * plr);
    void HandlePlayerLeave(Player * plr);
    bool HandleCustomSpell(Player *plr, uint32 spellId, GameObject * go);
    int32 HandleOpenGo(Player *plr, uint64 guid);
    uint32 GetAliveGuardsCount();
protected:
    // called when a faction takes control
    void FactionTakeOver(uint32 team);
    void DeSpawnNPCs();
    void DeSpawnGOs();
    void SpawnNPCsForTeam(uint32 team);
    void SpawnGOsForTeam(uint32 team);
    void UpdateWyvernRoostWorldState(uint32 roost);
    void UpdateHalaaWorldState();
private:
    bool m_capturable;
    uint32 m_GuardsAlive;
    uint32 m_ControllingFaction;
    uint32 m_WyvernStateNorth;
    uint32 m_WyvernStateSouth;
    uint32 m_WyvernStateEast;
    uint32 m_WyvernStateWest;
    uint32 m_HalaaState;
    uint32 m_RespawnTimer;
    uint32 m_GuardCheckTimer;
};
class OutdoorPvPNA : public OutdoorPvP
{
friend class OPvPCapturePointNA;
public:
    OutdoorPvPNA();
    bool SetupOutdoorPvP();
    void HandlePlayerEnterZone(Player *plr, uint32 zone);
    void HandlePlayerLeaveZone(Player *plr, uint32 zone);
    bool Update(uint32 diff);
    void FillInitialWorldStates(WorldPacket &data);
    void SendRemoveWorldStates(Player * plr);
    void HandleKillImpl(Player * plr, Unit * killed);
private:
    OPvPCapturePointNA * m_obj;
};
#endif

