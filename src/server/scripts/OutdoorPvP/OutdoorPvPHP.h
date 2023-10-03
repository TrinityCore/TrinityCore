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

#ifndef OUTDOOR_PVP_HP_
#define OUTDOOR_PVP_HP_

#include "OutdoorPvP.h"
#include <array>

enum DefenseMessages
{
    TEXT_OVERLOOK_TAKEN_ALLIANCE        = 14841, // '|cffffff00The Overlook has been taken by the Alliance!|r'
    TEXT_OVERLOOK_TAKEN_HORDE           = 14842, // '|cffffff00The Overlook has been taken by the Horde!|r'
    TEXT_STADIUM_TAKEN_ALLIANCE         = 14843, // '|cffffff00The Stadium has been taken by the Alliance!|r'
    TEXT_STADIUM_TAKEN_HORDE            = 14844, // '|cffffff00The Stadium has been taken by the Horde!|r'
    TEXT_BROKEN_HILL_TAKEN_ALLIANCE     = 14845, // '|cffffff00Broken Hill has been taken by the Alliance!|r'
    TEXT_BROKEN_HILL_TAKEN_HORDE        = 14846, // '|cffffff00Broken Hill has been taken by the Horde!|r'
};

enum OutdoorPvPHPSpells
{
    AlliancePlayerKillReward = 32155,
    HordePlayerKillReward = 32158,
    AllianceBuff = 32071,
    HordeBuff = 32049
};

enum OutdoorPvPHPTowerType
{
    HP_TOWER_BROKEN_HILL = 0,
    HP_TOWER_OVERLOOK = 1,
    HP_TOWER_STADIUM = 2,
    HP_TOWER_NUM = 3
};

enum OutdoorPvPHPWorldStates
{
    HP_UI_TOWER_DISPLAY_A = 0x9ba,
    HP_UI_TOWER_DISPLAY_H = 0x9b9,

    HP_UI_TOWER_COUNT_H = 0x9ae,
    HP_UI_TOWER_COUNT_A = 0x9ac,

    HP_UI_TOWER_S_A = 2483,
    HP_UI_TOWER_S_H = 2484,
    HP_UI_TOWER_S_N = 2485,

    HP_UI_TOWER_N_A = 2480,
    HP_UI_TOWER_N_H = 2481,
    HP_UI_TOWER_N_N = 2482,

    HP_UI_TOWER_W_A = 2471,
    HP_UI_TOWER_W_H = 2470,
    HP_UI_TOWER_W_N = 2472
};

enum OutdoorPvPHPEvents
{
    HP_EVENT_TOWER_W_PROGRESS_HORDE = 11383,
    HP_EVENT_TOWER_W_PROGRESS_ALLIANCE = 11387,
    HP_EVENT_TOWER_W_NEUTRAL_HORDE = 11386,
    HP_EVENT_TOWER_W_NEUTRAL_ALLIANCE = 11385,

    HP_EVENT_TOWER_N_PROGRESS_HORDE = 11396,
    HP_EVENT_TOWER_N_PROGRESS_ALLIANCE = 11395,
    HP_EVENT_TOWER_N_NEUTRAL_HORDE = 11394,
    HP_EVENT_TOWER_N_NEUTRAL_ALLIANCE = 11393,

    HP_EVENT_TOWER_S_PROGRESS_HORDE = 11404,
    HP_EVENT_TOWER_S_PROGRESS_ALLIANCE = 11403,
    HP_EVENT_TOWER_S_NEUTRAL_HORDE = 11402,
    HP_EVENT_TOWER_S_NEUTRAL_ALLIANCE = 11401
};

enum OutdoorPvPHPGameObjectEntries
{
    HP_GO_ENTRY_TOWER_W = 182173,
    HP_GO_ENTRY_TOWER_N = 182174,
    HP_GO_ENTRY_TOWER_S = 182175
};

enum OutdoorPvPHPCredit
{
    HP_KILL_CREDIT_TOWER_S = 19032,
    HP_KILL_CREDIT_TOWER_N = 19028,
    HP_KILL_CREDIT_TOWER_W = 19029
};

class OutdoorPvPHP;

class HPControlZoneHandler : public OutdoorPvPControlZoneHandler
{
public:
    explicit HPControlZoneHandler(OutdoorPvPHP* pvp);

    void SetFlagGuid(ObjectGuid const& guid) { _flagGuid = guid; }
    void SetTextCaptureHorde(uint32 text) { _textCaptureHorde = text; }
    void SetTextCaptureAlliance(uint32 text) { _textCaptureAlliance = text; }
    void SetFlagArtKitNeutral(uint32 artKit) { _flagArtKitNeutral = artKit; }
    void SetFlagArtKitHorde(uint32 artKit) { _flagArtKitHorde = artKit; }
    void SetFlagArtKitAlliance(uint32 artKit) { _flagArtKitAlliance = artKit; }
    void SetWorldstateNeutral(uint32 id) { _worldstateNeutral = id; }
    void SetWorldstateHorde(uint32 id) { _worldstateHorde = id; }
    void SetWorldstateAlliance(uint32 id) { _worldstateAlliance = id; }
    void SetKillCredit(uint32 credit) { _killCredit = credit; }

    void HandleProgressEventHorde([[maybe_unused]] GameObject* controlZone) override;
    void HandleProgressEventAlliance([[maybe_unused]] GameObject* controlZone) override;
    void HandleNeutralEventHorde([[maybe_unused]] GameObject* controlZone) override;
    void HandleNeutralEventAlliance([[maybe_unused]] GameObject* controlZone) override;
    void HandleNeutralEvent([[maybe_unused]] GameObject* controlZone) override;

    uint32 GetWorldStateNeutral() { return _worldstateNeutral; }
    uint32 GetWorldStateHorde() { return _worldstateHorde; }
    uint32 GetWorldStateAlliance() { return _worldstateAlliance; }

    OutdoorPvPHP* GetOutdoorPvPHP() const;

private:
    ObjectGuid _flagGuid;
    uint32 _textCaptureAlliance;
    uint32 _textCaptureHorde;
    uint32 _flagArtKitNeutral;
    uint32 _flagArtKitHorde;
    uint32 _flagArtKitAlliance;
    uint32 _worldstateNeutral;
    uint32 _worldstateHorde;
    uint32 _worldstateAlliance;
    uint32 _killCredit;
};

class OutdoorPvPHP : public OutdoorPvP
{
    public:
        OutdoorPvPHP(Map* map);

        bool SetupOutdoorPvP() override;

        void OnGameObjectCreate(GameObject* go) override;

        void HandlePlayerEnterZone(Player* player, uint32 zone) override;
        void HandlePlayerLeaveZone(Player* player, uint32 zone) override;

        void Update(uint32 diff) override;
        void SendRemoveWorldStates(Player* player) override;
        void HandleKillImpl(Player* player, Unit* killed) override;

        uint32 GetAllianceTowersControlled() const;
        void SetAllianceTowersControlled(uint32 count);
        uint32 GetHordeTowersControlled() const;
        void SetHordeTowersControlled(uint32 count);

    private:
        uint32 m_AllianceTowersControlled; // how many towers are controlled
        uint32 m_HordeTowersControlled;

        GuidUnorderedSet _controlZoneGUIDs;

        HPControlZoneHandler& GetControlZoneTowerNorthHandler() { return *static_cast<HPControlZoneHandler*>(ControlZoneHandlers[HP_GO_ENTRY_TOWER_N].get()); }
        HPControlZoneHandler& GetControlZoneTowerSouthHandler() { return *static_cast<HPControlZoneHandler*>(ControlZoneHandlers[HP_GO_ENTRY_TOWER_S].get()); }
        HPControlZoneHandler& GetControlZoneTowerWestHandler() { return *static_cast<HPControlZoneHandler*>(ControlZoneHandlers[HP_GO_ENTRY_TOWER_W].get()); }
};

#endif
