/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef OUTDOOR_PVP_ZM_
#define OUTDOOR_PVP_ZM_

#include "OutdoorPvP.h"

enum DefenseMessages
{
    TEXT_WEST_BEACON_TAKEN_ALLIANCE         = 15541, // '|cffffff00The Alliance has taken control of the West Beacon!|r'
    TEXT_WEST_BEACON_TAKEN_HORDE            = 15543, // '|cffffff00The Horde has taken control of the West Beacon!|r'
    TEXT_EAST_BEACON_TAKEN_ALLIANCE         = 15546, // '|cffffff00The Alliance has taken control of the East Beacon!|r'
    TEXT_EAST_BEACON_TAKEN_HORDE            = 15545, // '|cffffff00The Horde has taken control of the East Beacon!|r'
    TEXT_TWIN_SPIRE_RUINS_TAKEN_ALLIANCE    = 15591, // '|cffffff00The Alliance has taken control of Twin Spire Ruins!|r'
    TEXT_TWIN_SPIRE_RUINS_TAKEN_HORDE       = 15590, // '|cffffff00The Horde has taken control of Twin Spire Ruins!|r'
    TEXT_BOTH_BEACONS_TAKEN_ALLIANCE        = 16284, // (NYI) '|cffffff00The Alliance has taken control of both beacons!|r'
    TEXT_BOTH_BEACONS_TAKEN_HORDE           = 16285, // (NYI) '|cffffff00The Horde has taken control of both beacons!|r'
    TEXT_BATTLE_STANDARDS_ALLIANCE          = 16287, // (NYI) '|cffffff00The Alliance Field Scout is now issuing battle standards.|r'
    TEXT_BATTLE_STANDARDS_HORDE             = 16288  // (NYI) '|cffffff00The Horde Field Scout is now issuing battle standards.|r'
};

enum OutdoorPvPZMSpells
{
    // cast on the players of the controlling faction
    ZM_CAPTURE_BUFF = 33779,  // twin spire blessing
    // spell that the field scout casts on the player to carry the flag
    ZM_BATTLE_STANDARD_A = 32430,
    // spell that the field scout casts on the player to carry the flag
    ZM_BATTLE_STANDARD_H = 32431,
    // token create spell
    ZM_AlliancePlayerKillReward = 32155,
    // token create spell
    ZM_HordePlayerKillReward = 32158
};

enum ZMCreatureTypes
{
    ZM_ALLIANCE_FIELD_SCOUT = 0,
    ZM_HORDE_FIELD_SCOUT,
    ZM_CREATURE_NUM
};

enum ZM_BeaconType
{
    ZM_BEACON_EAST = 0,
    ZM_BEACON_WEST,
    ZM_NUM_BEACONS
};

enum OutdoorPvPZMWorldStates
{
    ZM_WORLDSTATE_UNK_1 = 2653,

    ZM_UI_TOWER_EAST_N = 2560,
    ZM_UI_TOWER_EAST_H = 2559,
    ZM_UI_TOWER_EAST_A = 2558,
    ZM_UI_TOWER_WEST_N = 2557,
    ZM_UI_TOWER_WEST_H = 2556,
    ZM_UI_TOWER_WEST_A = 2555,

    ZM_MAP_TOWER_EAST_N = 2652,
    ZM_MAP_TOWER_EAST_H = 2651,
    ZM_MAP_TOWER_EAST_A = 2650,
    ZM_MAP_GRAVEYARD_H = 2649,
    ZM_MAP_GRAVEYARD_A = 2648,
    ZM_MAP_GRAVEYARD_N = 2647,
    ZM_MAP_TOWER_WEST_N = 2646,
    ZM_MAP_TOWER_WEST_H = 2645,
    ZM_MAP_TOWER_WEST_A = 2644,

    ZM_MAP_HORDE_FLAG_READY = 2658,
    ZM_MAP_HORDE_FLAG_NOT_READY = 2657,
    ZM_MAP_ALLIANCE_FLAG_NOT_READY = 2656,
    ZM_MAP_ALLIANCE_FLAG_READY = 2655
};

enum ZM_TowerStateMask
{
    ZM_TOWERSTATE_N = 1,
    ZM_TOWERSTATE_A = 2,
    ZM_TOWERSTATE_H = 4
};

class OPvPCapturePointZM_Beacon : public OPvPCapturePoint
{
    public:
        OPvPCapturePointZM_Beacon(OutdoorPvP* pvp, ZM_BeaconType type);

        void ChangeState() override;
        void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;

        void UpdateTowerState();

    protected:
        ZM_BeaconType m_TowerType;
        uint32 m_TowerState;
};

enum ZM_GraveyardState
{
    ZM_GRAVEYARD_N = 1,
    ZM_GRAVEYARD_A = 2,
    ZM_GRAVEYARD_H = 4
};

class OPvPCapturePointZM_Graveyard : public OPvPCapturePoint
{
    public:
        OPvPCapturePointZM_Graveyard(OutdoorPvP* pvp);

        bool Update(uint32 diff) override;
        void ChangeState() override { }
        void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;
        int32 HandleOpenGo(Player* player, GameObject* go) override;
        bool HandleGossipOption(Player* player, Creature* creature, uint32 gossipid) override;
        bool HandleDropFlag(Player* player, uint32 spellId) override;
        bool CanTalkTo(Player* player, Creature* creature, GossipMenuItems const& gso) override;

        void UpdateTowerState();
        void SetBeaconState(uint32 controlling_team); // not good atm
        uint32 GetGraveyardState() const;

    protected:
        uint32 m_BothControllingFaction;
        ObjectGuid m_FlagCarrierGUID;
        uint32 m_GraveyardState;
};

/// @todo flag carrier death/leave/mount/activitychange should give back the gossip options
class OutdoorPvPZM : public OutdoorPvP
{
    public:
        OutdoorPvPZM();

        bool SetupOutdoorPvP() override;
        void HandlePlayerEnterZone(Player* player, uint32 zone) override;
        void HandlePlayerLeaveZone(Player* player, uint32 zone) override;
        bool Update(uint32 diff) override;
        void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;
        void SendRemoveWorldStates(Player* player) override;
        void HandleKillImpl(Player* player, Unit* killed) override;

        uint32 GetAllianceTowersControlled() const;
        void SetAllianceTowersControlled(uint32 count);
        uint32 GetHordeTowersControlled() const;
        void SetHordeTowersControlled(uint32 count);

    private:
        OPvPCapturePointZM_Graveyard* m_Graveyard;
        uint32 m_AllianceTowersControlled;
        uint32 m_HordeTowersControlled;
};

#endif
