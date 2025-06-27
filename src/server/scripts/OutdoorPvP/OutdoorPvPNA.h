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

enum FlightSpellsNA
{
    NA_SPELL_FLY_SOUTH = 32059,
    NA_SPELL_FLY_WEST = 32068,
    NA_SPELL_FLY_NORTH = 32075,
    NA_SPELL_FLY_EAST = 32081
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

class OPvPCapturePointNA : public OPvPCapturePoint
{
    public:
        OPvPCapturePointNA(OutdoorPvP* pvp);

        bool Update(uint32 diff) override;
        void ChangeState() override;
        void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;
        bool HandleCustomSpell(Player* player, uint32 spellId, GameObject* go) override;
        int32 HandleOpenGo(Player* player, GameObject* go) override;

        uint32 GetAliveGuardsCount();
        uint32 GetControllingFaction() const;
        void FactionTakeOver(uint32 team); // called when a faction takes control
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

        bool SetupOutdoorPvP() override;
        void HandlePlayerEnterZone(Player* player, uint32 zone) override;
        void HandlePlayerLeaveZone(Player* player, uint32 zone) override;
        bool Update(uint32 diff) override;
        void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;
        void SendRemoveWorldStates(Player* player) override;
        void HandleKillImpl(Player* player, Unit* killed) override;

    private:
        OPvPCapturePointNA* m_obj;
};

#endif
