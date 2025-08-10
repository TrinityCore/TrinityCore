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
    ZM_ALLIANCE_FIELD_SCOUT = 18581,
    ZM_HORDE_FIELD_SCOUT    = 18564,
};

enum ZM_BeaconType
{
    ZM_BEACON_EAST = 0,
    ZM_BEACON_WEST,
    ZM_NUM_BEACONS
};

enum OutdoorPvPZMWorldStates
{
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

enum ZM_WorldEvents
{
    ZM_EVENT_BEACON_EAST_PROGRESS_HORDE     = 11807,
    ZM_EVENT_BEACON_EAST_PROGRESS_ALLIANCE  = 11806,
    ZM_EVENT_BEACON_EAST_NEUTRAL_HORDE      = 11814,
    ZM_EVENT_BEACON_EAST_NEUTRAL_ALLIANCE   = 11815,

    ZM_EVENT_BEACON_WEST_PROGRESS_HORDE     = 11805,
    ZM_EVENT_BEACON_WEST_PROGRESS_ALLIANCE  = 11804,
    ZM_EVENT_BEACON_WEST_NEUTRAL_HORDE      = 11808,
    ZM_EVENT_BEACON_WEST_NEUTRAL_ALLIANCE   = 11809
};

enum ZM_GraveyardState
{
    ZM_GRAVEYARD_N = 1,
    ZM_GRAVEYARD_A = 2,
    ZM_GRAVEYARD_H = 4
};

enum ZM_GameObjectEntries
{
    ZM_GO_ENTRY_BEACON_WEST = 182522,
    ZM_GO_ENTRY_BEACON_EAST = 182523
};

class OutdoorPvPZM;

class ZMControlZoneHandler : public OutdoorPvPControlZoneHandler
{
public:
    ZMControlZoneHandler(OutdoorPvPZM* pvp, uint32 textBeaconTakenHorde, uint32 textBeaconTakenAlliance, uint32 worldstateNeutralUi, uint32 worldstateNeutralMap, uint32 worldstateHordeUi, uint32 worldstateHordeMap, uint32 worldstateAllianceUi, uint32 worldstateAllianceMap);

    void HandleProgressEventHorde([[maybe_unused]] GameObject* controlZone) override;
    void HandleProgressEventAlliance([[maybe_unused]] GameObject* controlZone) override;
    void HandleNeutralEventHorde([[maybe_unused]] GameObject* controlZone) override;
    void HandleNeutralEventAlliance([[maybe_unused]] GameObject* controlZone) override;
    void HandleNeutralEvent([[maybe_unused]] GameObject* controlZone) override;

    uint32 GetWorldStateNeutralUI() { return _worldstateNeutralUi; }
    uint32 GetWorldStateNeutralMap() { return _worldstateNeutralMap; }
    uint32 GetWorldStateHordeUI() { return _worldstateHordeUi; }
    uint32 GetWorldStateHordeMap() { return _worldstateHordeMap; }
    uint32 GetWorldStateAllianceUI() { return _worldstateAllianceUi; }
    uint32 GetWorldStateAllianceMap() { return _worldstateAllianceMap; }

    OutdoorPvPZM* GetOutdoorPvpZM();

private:
    uint32 _textBeaconTakenHorde;
    uint32 _textBeaconTakenAlliance;
    uint32 _worldstateNeutralUi;
    uint32 _worldstateNeutralMap;
    uint32 _worldstateHordeUi;
    uint32 _worldstateHordeMap;
    uint32 _worldstateAllianceUi;
    uint32 _worldstateAllianceMap;
};

class OPvPCapturePointZM_Graveyard : public OPvPCapturePoint
{
    public:
        OPvPCapturePointZM_Graveyard(OutdoorPvP* pvp);

        void Update(uint32 diff) override;
        void ChangeState() override { }
        int32 HandleOpenGo(Player* player, GameObject* go) override;
        bool HandleDropFlag(Player* player, uint32 spellId) override;

        void UpdateTowerState();
        void SetBeaconState(uint32 controlling_team); // not good atm
        uint32 GetGraveyardState() const;

        ObjectGuid GetFlagCarrierGUID() const { return m_FlagCarrierGUID; }
        void SetFlagCarrierGUID(ObjectGuid guid) { m_FlagCarrierGUID = guid; }

    protected:
        uint32 m_BothControllingFaction;
        ObjectGuid m_FlagCarrierGUID;
        uint32 m_GraveyardState;
};

/// @todo flag carrier death/leave/mount/activitychange should give back the gossip options
class OutdoorPvPZM : public OutdoorPvP
{
    public:
        OutdoorPvPZM(Map* map);

        bool SetupOutdoorPvP() override;
        void HandlePlayerEnterZone(Player* player, uint32 zone) override;
        void HandlePlayerLeaveZone(Player* player, uint32 zone) override;
        void Update(uint32 diff) override;
        void SendRemoveWorldStates(Player* player) override;
        void HandleKillImpl(Player* player, Unit* killed) override;

        uint32 GetAllianceTowersControlled() const;
        void SetAllianceTowersControlled(uint32 count);
        uint32 GetHordeTowersControlled() const;
        void SetHordeTowersControlled(uint32 count);

        OPvPCapturePointZM_Graveyard* GetGraveyard() { return m_Graveyard.get(); }

    private:
        std::unique_ptr<OPvPCapturePointZM_Graveyard> m_Graveyard;
        uint32 m_AllianceTowersControlled;
        uint32 m_HordeTowersControlled;
};

#endif
