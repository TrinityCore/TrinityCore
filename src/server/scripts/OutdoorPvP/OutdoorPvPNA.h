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

#ifndef OUTDOOR_PVP_NA_
#define OUTDOOR_PVP_NA_

#include "OutdoorPvP.h"

enum DefenseMessages
{
    TEXT_ALL_GUARDS_DEFEATED                = 15017, // (NYI) '|cffffff00All the guards have been defeated!|r'
    TEXT_HALAA_TAKEN_ALLIANCE               = 15018, // '|cffffff00The Alliance has taken control of Halaa!|r'
    TEXT_HALAA_TAKEN_HORDE                  = 15019, // '|cffffff00The Horde has taken control of Halaa!|r'
    TEXT_HALAA_DEFENSELESS                  = 15020, // (NYI) '|cffffff00Halaa is defenseless!|r'
    TEXT_HALAA_GAINING_CONTROL_HORDE        = 15493, // (NYI) '|cffffff00The Horde is gaining control of Halaa!|r'
    TEXT_HALAA_GAINING_CONTROL_ALLIANCE     = 15494  // (NYI) '|cffffff00The Alliance is gaining control of Halaa!|r'
};

/// @todo "sometimes" set to neutral

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

enum OutdoorPvPNAWorldStates
{
    NA_UI_HORDE_GUARDS_SHOW = 2503,
    NA_UI_ALLIANCE_GUARDS_SHOW = 2502,
    NA_UI_GUARDS_MAX = 2493,
    NA_UI_GUARDS_LEFT = 2491,

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
enum ControlGOTypes
{
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

const uint32 FlightPathStartNodes[FLIGHT_NODES_NUM] = {103, 105, 107, 109};
const uint32 FlightPathEndNodes[FLIGHT_NODES_NUM] = {104, 106, 108, 110};

enum FlightSpellsNA
{
    NA_SPELL_FLY_SOUTH = 32059,
    NA_SPELL_FLY_WEST = 32068,
    NA_SPELL_FLY_NORTH = 32075,
    NA_SPELL_FLY_EAST = 32081
};

// spawned when the alliance is attacking, horde is in control
const go_type HordeControlGOs[NA_CONTROL_GO_NUM] =
{
    {182267, 530, -1815.8f, 8036.51f, -26.2354f, -2.89725f, 0.0f, 0.0f, 0.992546f, -0.121869f}, //ALLY_ROOST_SOUTH
    {182280, 530, -1507.95f, 8132.1f, -19.5585f, -1.3439f, 0.0f, 0.0f, 0.622515f, -0.782608f}, //ALLY_ROOST_WEST
    {182281, 530, -1384.52f, 7779.33f, -11.1663f, -0.575959f, 0.0f, 0.0f, 0.284015f, -0.95882f}, //ALLY_ROOST_NORTH
    {182282, 530, -1650.11f, 7732.56f, -15.4505f, -2.80998f, 0.0f, 0.0f, 0.986286f, -0.165048f}, //ALLY_ROOST_EAST

    {182222, 530, -1825.4022f, 8039.2602f, -26.08f, -2.89725f, 0.0f, 0.0f, 0.992546f, -0.121869f}, //HORDE_BOMB_WAGON_SOUTH
    {182272, 530, -1515.37f, 8136.91f, -20.42f, -1.3439f, 0.0f, 0.0f, 0.622515f, -0.782608f}, //HORDE_BOMB_WAGON_WEST
    {182273, 530, -1377.95f, 7773.44f, -10.31f, -0.575959f, 0.0f, 0.0f, 0.284015f, -0.95882f}, //HORDE_BOMB_WAGON_NORTH
    {182274, 530, -1659.87f, 7733.15f, -15.75f, -2.80998f, 0.0f, 0.0f, 0.986286f, -0.165048f}, //HORDE_BOMB_WAGON_EAST

    {182266, 530, -1815.8f, 8036.51f, -26.2354f, -2.89725f, 0.0f, 0.0f, 0.992546f, -0.121869f}, //DESTROYED_ALLY_ROOST_SOUTH
    {182275, 530, -1507.95f, 8132.1f, -19.5585f, -1.3439f, 0.0f, 0.0f, 0.622515f, -0.782608f}, //DESTROYED_ALLY_ROOST_WEST
    {182276, 530, -1384.52f, 7779.33f, -11.1663f, -0.575959f, 0.0f, 0.0f, 0.284015f, -0.95882f}, //DESTROYED_ALLY_ROOST_NORTH
    {182277, 530, -1650.11f, 7732.56f, -15.4505f, -2.80998f, 0.0f, 0.0f, 0.986286f, -0.165048f}  //DESTROYED_ALLY_ROOST_EAST
};

// spawned when the horde is attacking, alliance is in control
const go_type AllianceControlGOs[NA_CONTROL_GO_NUM] =
{
    {182301, 530, -1815.8f, 8036.51f, -26.2354f, -2.89725f, 0.0f, 0.0f, 0.992546f, -0.121869f}, //HORDE_ROOST_SOUTH
    {182302, 530, -1507.95f, 8132.1f, -19.5585f, -1.3439f, 0.0f, 0.0f, 0.622515f, -0.782608f}, //HORDE_ROOST_WEST
    {182303, 530, -1384.52f, 7779.33f, -11.1663f, -0.575959f, 0.0f, 0.0f, 0.284015f, -0.95882f}, //HORDE_ROOST_NORTH
    {182304, 530, -1650.11f, 7732.56f, -15.4505f, -2.80998f, 0.0f, 0.0f, 0.986286f, -0.165048f}, //HORDE_ROOST_EAST

    {182305, 530, -1825.4022f, 8039.2602f, -26.08f, -2.89725f, 0.0f, 0.0f, 0.992546f, -0.121869f}, //ALLY_BOMB_WAGON_SOUTH
    {182306, 530, -1515.37f, 8136.91f, -20.42f, -1.3439f, 0.0f, 0.0f, 0.622515f, -0.782608f}, //ALLY_BOMB_WAGON_WEST
    {182307, 530, -1377.95f, 7773.44f, -10.31f, -0.575959f, 0.0f, 0.0f, 0.284015f, -0.95882f}, //ALLY_BOMB_WAGON_NORTH
    {182308, 530, -1659.87f, 7733.15f, -15.75f, -2.80998f, 0.0f, 0.0f, 0.986286f, -0.165048f}, //ALLY_BOMB_WAGON_EAST

    {182297, 530, -1815.8f, 8036.51f, -26.2354f, -2.89725f, 0.0f, 0.0f, 0.992546f, -0.121869f}, //DESTROYED_HORDE_ROOST_SOUTH
    {182298, 530, -1507.95f, 8132.1f, -19.5585f, -1.3439f, 0.0f, 0.0f, 0.622515f, -0.782608f}, //DESTROYED_HORDE_ROOST_WEST
    {182299, 530, -1384.52f, 7779.33f, -11.1663f, -0.575959f, 0.0f, 0.0f, 0.284015f, -0.95882f}, //DESTROYED_HORDE_ROOST_NORTH
    {182300, 530, -1650.11f, 7732.56f, -15.4505f, -2.80998f, 0.0f, 0.0f, 0.986286f, -0.165048f}  //DESTROYED_HORDE_ROOST_EAST
};

enum ControlNPCTypes
{
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

const creature_type HordeControlNPCs[NA_CONTROL_NPC_NUM] =
{
    {18816, 530, -1523.92f, 7951.76f, -17.6942f, 3.51172f},
    {18821, 530, -1527.75f, 7952.46f, -17.6948f, 3.99317f},
    {21474, 530, -1520.14f, 7927.11f, -20.2527f, 3.39389f},
    {21484, 530, -1524.84f, 7930.34f, -20.182f, 3.6405f},
    {21483, 530, -1570.01f, 7993.8f, -22.4505f, 5.02655f},
    {18192, 530, -1654.06f, 8000.46f, -26.59f, 3.37f},
    {18192, 530, -1487.18f, 7899.1f, -19.53f, 0.954f},
    {18192, 530, -1480.88f, 7908.79f, -19.19f, 4.485f},
    {18192, 530, -1540.56f, 7995.44f, -20.45f, 0.947f},
    {18192, 530, -1546.95f, 8000.85f, -20.72f, 6.035f},
    {18192, 530, -1595.31f, 7860.53f, -21.51f, 3.747f},
    {18192, 530, -1642.31f, 7995.59f, -25.8f, 3.317f},
    {18192, 530, -1545.46f, 7995.35f, -20.63f, 1.094f},
    {18192, 530, -1487.58f, 7907.99f, -19.27f, 5.567f},
    {18192, 530, -1651.54f, 7988.56f, -26.5289f, 2.98451f},
    {18192, 530, -1602.46f, 7866.43f, -22.1177f, 4.74729f},
    {18192, 530, -1591.22f, 7875.29f, -22.3536f, 4.34587f},
    {18192, 530, -1550.6f, 7944.45f, -21.63f, 3.559f},
    {18192, 530, -1545.57f, 7935.83f, -21.13f, 3.448f},
    {18192, 530, -1550.86f, 7937.56f, -21.7f, 3.801f}
};

const creature_type AllianceControlNPCs[NA_CONTROL_NPC_NUM] =
{
    {18817, 530, -1591.18f, 8020.39f, -22.2042f, 4.59022f},
    {18822, 530, -1588.0f, 8019.0f, -22.2042f, 4.06662f},
    {21485, 530, -1521.93f, 7927.37f, -20.2299f, 3.24631f},
    {21487, 530, -1540.33f, 7971.95f, -20.7186f, 3.07178f},
    {21488, 530, -1570.01f, 7993.8f, -22.4505f, 5.02655f},
    {18256, 530, -1654.06f, 8000.46f, -26.59f, 3.37f},
    {18256, 530, -1487.18f, 7899.1f, -19.53f, 0.954f},
    {18256, 530, -1480.88f, 7908.79f, -19.19f, 4.485f},
    {18256, 530, -1540.56f, 7995.44f, -20.45f, 0.947f},
    {18256, 530, -1546.95f, 8000.85f, -20.72f, 6.035f},
    {18256, 530, -1595.31f, 7860.53f, -21.51f, 3.747f},
    {18256, 530, -1642.31f, 7995.59f, -25.8f, 3.317f},
    {18256, 530, -1545.46f, 7995.35f, -20.63f, 1.094f},
    {18256, 530, -1487.58f, 7907.99f, -19.27f, 5.567f},
    {18256, 530, -1651.54f, 7988.56f, -26.5289f, 2.98451f},
    {18256, 530, -1602.46f, 7866.43f, -22.1177f, 4.74729f},
    {18256, 530, -1591.22f, 7875.29f, -22.3536f, 4.34587f},
    {18256, 530, -1603.75f, 8000.36f, -24.18f, 4.516f},
    {18256, 530, -1585.73f, 7994.68f, -23.29f, 4.439f},
    {18256, 530, -1595.5f, 7991.27f, -23.53f, 4.738f}
};

enum WyvernStates
{
    WYVERN_NEU_HORDE = 1,
    WYVERN_NEU_ALLIANCE = 2,
    WYVERN_HORDE = 4,
    WYVERN_ALLIANCE = 8
};

enum HalaaStates
{
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
    public:
        OPvPCapturePointNA(OutdoorPvP* pvp);

        bool Update(uint32 diff) override;

        void ChangeState() override;

        void FillInitialWorldStates(WorldPacket & data) override;

        bool HandleCustomSpell(Player* player, uint32 spellId, GameObject* go) override;

        int32 HandleOpenGo(Player* player, GameObject* go) override;

        uint32 GetAliveGuardsCount();
        uint32 GetControllingFaction() const;

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
    public:
        OutdoorPvPNA();

        bool SetupOutdoorPvP();

        void HandlePlayerEnterZone(Player* player, uint32 zone);
        void HandlePlayerLeaveZone(Player* player, uint32 zone);

        bool Update(uint32 diff);

        void FillInitialWorldStates(WorldPacket &data);

        void SendRemoveWorldStates(Player* player);

        void HandleKillImpl(Player* player, Unit* killed);

    private:
        OPvPCapturePointNA * m_obj;
};

#endif
