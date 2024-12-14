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
};

enum FlightSpellsNA
{
    NA_SPELL_FLY_SOUTH = 32059,
    NA_SPELL_FLY_WEST = 32068,
    NA_SPELL_FLY_NORTH = 32075,
    NA_SPELL_FLY_EAST = 32081
};

enum HalaaSpawnGroupIds
{
    SPAWN_GROUP_HORDE_GUARDS = 123,
    SPAWN_GROUP_ALLIANCE_GUARDS = 124,
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

enum HalaaEvents
{
    HALAA_EVENT_CAPTURE_HORDE       = 11504,
    HALAA_EVENT_CAPTURE_ALLIANCE    = 11503,
    HALAA_EVENT_CONTESTED_HORDE     = 11559,
    HALAA_EVENT_CONTESTED_ALLIANCE  = 11558,
    HALAA_EVENT_PROGRESS_HORDE      = 11821,
    HALAA_EVENT_PROGRESS_ALLIANCE   = 11822
};

class Unit;
class Creature;
class WorldObject;

class OutdoorPvPNA;

class NAControlZoneHandler : public OutdoorPvPControlZoneHandler
{
public:
    explicit NAControlZoneHandler(OutdoorPvPNA* pvp);

    void HandleCaptureEventHorde([[maybe_unused]] GameObject* controlZone) override;
    void HandleCaptureEventAlliance([[maybe_unused]] GameObject* controlZone) override;
    void HandleContestedEventHorde([[maybe_unused]] GameObject* controlZone) override;
    void HandleContestedEventAlliance([[maybe_unused]] GameObject* controlZone) override;
    void HandleProgressEventHorde([[maybe_unused]] GameObject* controlZone) override;
    void HandleProgressEventAlliance([[maybe_unused]] GameObject* controlZone) override;
    void HandleNeutralEventHorde([[maybe_unused]] GameObject* controlZone) override;
    void HandleNeutralEventAlliance([[maybe_unused]] GameObject* controlZone) override;
    void HandleNeutralEvent([[maybe_unused]] GameObject* controlZone) override;

    OutdoorPvPNA* GetOutdoorPvPNA() const;
};

class OPvPCapturePointNA : public OPvPCapturePoint
{
    public:
        OPvPCapturePointNA(OutdoorPvP* pvp);

        void Update(uint32 diff) override;
        void ChangeState() override { } // todo remove?
        bool HandleCustomSpell(Player* player, uint32 spellId, GameObject* go) override;
        int32 HandleOpenGo(Player* player, GameObject* go) override;

        uint32 GetAliveGuardsCount() const;
        Team GetControllingFaction() const;
        void FactionTakeOver(Team team); // called when a faction takes control
        void UpdateWyvernRoostWorldState(uint32 roost);

        void SetControlZoneGUID(ObjectGuid guid) { _controlZoneGUID = guid; }
    private:
        bool m_capturable;
        uint32 m_GuardsAlive;
        Team m_ControllingFaction;
        uint32 m_WyvernStateNorth;
        uint32 m_WyvernStateSouth;
        uint32 m_WyvernStateEast;
        uint32 m_WyvernStateWest;
        uint32 m_RespawnTimer;
        uint32 m_GuardCheckTimer;
        ObjectGuid _controlZoneGUID;
};

class OutdoorPvPNA : public OutdoorPvP
{
    public:
        OutdoorPvPNA(Map* map);

        void OnGameObjectCreate(GameObject* go) override;

        bool SetupOutdoorPvP() override;
        void HandlePlayerEnterZone(Player* player, uint32 zone) override;
        void HandlePlayerLeaveZone(Player* player, uint32 zone) override;
        void Update(uint32 diff) override;
        void SendRemoveWorldStates(Player* player) override;
        void HandleKillImpl(Player* player, Unit* killed) override;
        void SendMapWorldStates(int32 neutral, int32 progressHorde, int32 progressAlliance, int32 capturedHorde, int32 captureAlliance);
        OPvPCapturePointNA* GetCapturePoint() const { return m_obj; }
    private:
        OPvPCapturePointNA* m_obj;
};

#endif
