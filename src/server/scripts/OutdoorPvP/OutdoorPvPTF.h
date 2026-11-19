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

#ifndef OUTDOOR_PVP_TF_
#define OUTDOOR_PVP_TF_

#include "OutdoorPvP.h"

enum DefenseMessages
{
    TEXT_BONE_WASTES_TAKEN_ALLIANCE     = 16120, // (NYI) '|cffffff00The Alliance has taken control of The Bone Wastes!|r'
    TEXT_BONE_WASTES_TAKEN_HORDE        = 16119, // (NYI) '|cffffff00The Horde has taken control of The Bone Wastes!|r'
    TEXT_SPIRIT_TOWER_TAKEN_ALLIANCE    = 18285, // '|cffffff00The Alliance has taken control of a Spirit Tower!|r'
    TEXT_SPIRIT_TOWER_TAKEN_HORDE       = 18286, // '|cffffff00The Horde has taken control of a Spirit Tower!|r'
    TEXT_SPIRIT_TOWER_LOSE_ALLIANCE     = 18288, // '|cffffff00The Alliance has lost control of a Spirit Tower!|r'
    TEXT_SPIRIT_TOWER_LOSE_HORDE        = 18287  // '|cffffff00The Horde has lost control of a Spirit Tower!|r'
};

enum OutdoorPvPTF_TowerType
{
    TF_TOWER_NW = 0,
    TF_TOWER_N,
    TF_TOWER_NE,
    TF_TOWER_SE,
    TF_TOWER_S,
    TF_TOWER_NUM
};

enum TFWorldStates
{
    TF_UI_TOWER_COUNT_H = 2622,
    TF_UI_TOWER_COUNT_A = 2621,
    TF_UI_TOWERS_CONTROLLED_DISPLAY = 2620,

    TF_UI_LOCKED_TIME_MINUTES_FIRST_DIGIT = 2512,
    TF_UI_LOCKED_TIME_MINUTES_SECOND_DIGIT = 2510,
    TF_UI_LOCKED_TIME_HOURS = 2509,
    TF_UI_LOCKED_DISPLAY_NEUTRAL = 2508,
    TF_UI_LOCKED_DISPLAY_HORDE = 2768,
    TF_UI_LOCKED_DISPLAY_ALLIANCE = 2767
};

enum TFGameEvents
{
    TF_EVENT_TOWER_NW_ALLIANCE_PROGRESS  = 12225,
    TF_EVENT_TOWER_NW_HORDE_PROGRESS     = 12226,
    TF_EVENT_TOWER_NW_NEUTRAL_ALLIANCE   = 12227,
    TF_EVENT_TOWER_NW_NEUTRAL_HORDE      = 12228,

    TF_EVENT_TOWER_NE_HORDE_PROGRESS     = 12486,
    TF_EVENT_TOWER_NE_ALLIANCE_PROGRESS  = 12487,
    TF_EVENT_TOWER_NE_NEUTRAL_HORDE      = 12488,
    TF_EVENT_TOWER_NE_NEUTRAL_ALLIANCE   = 12489,

    TF_EVENT_TOWER_N_NEUTRAL_HORDE       = 12490,
    TF_EVENT_TOWER_N_NEUTRAL_ALLIANCE    = 12491,
    TF_EVENT_TOWER_N_ALLIANCE_PROGRESS   = 12496,
    TF_EVENT_TOWER_N_HORDE_PROGRESS      = 12497,

    TF_EVENT_TOWER_SE_NEUTRAL_HORDE      = 12492,
    TF_EVENT_TOWER_SE_NEUTRAL_ALLIANCE   = 12493,
    TF_EVENT_TOWER_SE_ALLIANCE_PROGRESS  = 12498,
    TF_EVENT_TOWER_SE_HORDE_PROGRESS     = 12499,

    TF_EVENT_TOWER_S_NEUTRAL_HORDE       = 12494,
    TF_EVENT_TOWER_S_NEUTRAL_ALLIANCE    = 12495,
    TF_EVENT_TOWER_S_ALLIANCE_PROGRESS   = 12500,
    TF_EVENT_TOWER_S_HORDE_PROGRESS      = 12501
};

enum TFGameObjects
{
    TF_ENTRY_TOWER_NW   = 183104,
    TF_ENTRY_TOWER_N    = 183411,
    TF_ENTRY_TOWER_NE   = 183412,
    TF_ENTRY_TOWER_SE   = 183413,
    TF_ENTRY_TOWER_S    = 183414
};

class OutdoorPvPTF;

class TFControlZoneHandler : public OutdoorPvPControlZoneHandler
{
public:
    explicit TFControlZoneHandler(OutdoorPvPTF* pvp, uint32 worldstateHorde, uint32 worldstateAlliance, uint32 worldstateNeutral);

    void HandleProgressEventHorde([[maybe_unused]] GameObject* controlZone) override;
    void HandleProgressEventAlliance([[maybe_unused]] GameObject* controlZone) override;
    void HandleNeutralEventHorde([[maybe_unused]] GameObject* controlZone) override;
    void HandleNeutralEventAlliance([[maybe_unused]] GameObject* controlZone) override;
    void HandleNeutralEvent([[maybe_unused]] GameObject* controlZone) override;

    uint32 GetWorldStateHorde() { return _worldstateHorde; }
    uint32 GetWorldStateAlliance() { return _worldstateAlliance; }
    uint32 GetWorldStateNeutral() { return _worldstateNeutral; }

    OutdoorPvPTF* GetOutdoorPvPTF() const;

private:
    uint32 _worldstateHorde;
    uint32 _worldstateAlliance;
    uint32 _worldstateNeutral;
};

class OutdoorPvPTF : public OutdoorPvP
{
    public:
        OutdoorPvPTF(Map* map);

        bool SetupOutdoorPvP() override;
        void OnGameObjectCreate(GameObject* go) override;
        void HandlePlayerEnterZone(Player* player, uint32 zone) override;
        void HandlePlayerLeaveZone(Player* player, uint32 zone) override;
        void Update(uint32 diff) override;
        void SendRemoveWorldStates(Player* player) override;

        uint32 GetAllianceTowersControlled() const;
        void SetAllianceTowersControlled(uint32 count);
        uint32 GetHordeTowersControlled() const;
        void SetHordeTowersControlled(uint32 count);
        bool IsLocked() const;

        void ProcessEvent(WorldObject* obj, uint32 eventId, WorldObject* invoker) override;
        void HandleCapture(TeamId team);
    private:
        bool m_IsLocked;
        uint32 m_LockTimer;
        uint32 m_LockTimerUpdate;
        uint32 m_AllianceTowersControlled;
        uint32 m_HordeTowersControlled;
        uint32 hours_left, second_digit, first_digit;
        GuidUnorderedSet _controlZoneGUIDs;
        std::unordered_map<uint32 /*control zone entry*/, std::unique_ptr<TFControlZoneHandler>> _controlZoneHandlers;
};

#endif
