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

#ifndef __BATTLEGROUNDEY_H
#define __BATTLEGROUNDEY_H

#include "Battleground.h"
#include "BattlegroundScore.h"
#include "Object.h"
#include "Timer.h"

static constexpr Seconds POINTS_TICK_TIME = 2s;
static constexpr Seconds BG_EY_FLAG_ASSAULT_TIMER = 30s;
static constexpr uint16 BG_EY_FLAG_BRUTAL_ASSAULT_STACK_COUNT = 5;

enum BG_EY_Misc
{
    BG_EY_EVENT_START_BATTLE        = 13180 // Achievement: Flurry
};

enum BG_EY_WorldStates
{
    EY_ALLIANCE_RESOURCES           = 1776,
    EY_HORDE_RESOURCES              = 1777,
    EY_MAX_RESOURCES                = 1780,
    EY_ALLIANCE_BASE                = 2752,
    EY_HORDE_BASE                   = 2753,
    DRAENEI_RUINS_HORDE_CONTROL     = 2733,
    DRAENEI_RUINS_ALLIANCE_CONTROL  = 2732,
    DRAENEI_RUINS_UNCONTROL         = 2731,
    MAGE_TOWER_ALLIANCE_CONTROL     = 2730,
    MAGE_TOWER_HORDE_CONTROL        = 2729,
    MAGE_TOWER_UNCONTROL            = 2728,
    FEL_REAVER_HORDE_CONTROL        = 2727,
    FEL_REAVER_ALLIANCE_CONTROL     = 2726,
    FEL_REAVER_UNCONTROL            = 2725,
    BLOOD_ELF_HORDE_CONTROL         = 2724,
    BLOOD_ELF_ALLIANCE_CONTROL      = 2723,
    BLOOD_ELF_UNCONTROL             = 2722,
    PROGRESS_BAR_PERCENT_GREY       = 2720,                 //100 = empty (only grey), 0 = blue|red (no grey)
    PROGRESS_BAR_STATUS             = 2719,                 //50 init!, 48 ... hordak bere .. 33 .. 0 = full 100% hordacky, 100 = full alliance
    PROGRESS_BAR_SHOW               = 2718,                 //1 init, 0 druhy send - bez messagu, 1 = controlled aliance
    NETHERSTORM_FLAG                = 8863,
    //set to 2 when flag is picked up, and to 1 if it is dropped
    NETHERSTORM_FLAG_STATE_ALLIANCE = 9808,
    NETHERSTORM_FLAG_STATE_HORDE    = 9809,

    DRAENEI_RUINS_HORDE_CONTROL_STATE       = 17362,
    DRAENEI_RUINS_ALLIANCE_CONTROL_STATE    = 17366,
    MAGE_TOWER_HORDE_CONTROL_STATE          = 17361,
    MAGE_TOWER_ALLIANCE_CONTROL_STATE       = 17368,
    FEL_REAVER_HORDE_CONTROL_STATE          = 17364,
    FEL_REAVER_ALLIANCE_CONTROL_STATE       = 17367,
    BLOOD_ELF_HORDE_CONTROL_STATE           = 17363,
    BLOOD_ELF_ALLIANCE_CONTROL_STATE        = 17365,
};

enum BG_EY_Sounds
{
    //strange ids, but sure about them
    BG_EY_SOUND_FLAG_PICKED_UP_ALLIANCE = 8212,
    BG_EY_SOUND_FLAG_CAPTURED_HORDE     = 8213,
    BG_EY_SOUND_FLAG_PICKED_UP_HORDE    = 8174,
    BG_EY_SOUND_FLAG_CAPTURED_ALLIANCE  = 8173,
    BG_EY_SOUND_FLAG_RESET              = 8192
};

enum BG_EY_Spells
{
    BG_EY_NETHERSTORM_FLAG_SPELL        = 34976,
    BG_EY_PLAYER_DROPPED_FLAG_SPELL     = 34991,

    // Focused/Brutal Assault
    BG_EY_FOCUSED_ASSAULT_SPELL         = 46392,
    BG_EY_BRUTAL_ASSAULT_SPELL          = 46393
};

enum EYBattlegroundObjectEntry
{
    BG_OBJECT_A_DOOR_EY_ENTRY                           = 184719,           //Alliance door
    BG_OBJECT_H_DOOR_EY_ENTRY                           = 184720,           //Horde door
    BG_OBJECT_FLAG2_EY_ENTRY                            = 208977,           //Netherstorm flag (flagstand)
    BG_OBJECT_BE_TOWER_CAP_EY_ENTRY                     = 184080,           //BE Tower Cap Pt
    BG_OBJECT_FR_TOWER_CAP_EY_ENTRY                     = 184081,           //Fel Reaver Cap Pt
    BG_OBJECT_HU_TOWER_CAP_EY_ENTRY                     = 184082,           //Human Tower Cap Pt
    BG_OBJECT_DR_TOWER_CAP_EY_ENTRY                     = 184083,           //Draenei Tower Cap Pt
};

enum EYBattlegroundPointsTrigger
{
    AREATRIGGER_CAPTURE_FLAG = 33
};

enum EYBattlegroundPoints
{
    FEL_REAVER      = 0,
    BLOOD_ELF       = 1,
    DRAENEI_RUINS   = 2,
    MAGE_TOWER      = 3,

    EY_PLAYERS_OUT_OF_POINTS  = 4,
    EY_POINTS_MAX             = 4
};

#define BG_EY_NotEYWeekendHonorTicks    260
#define BG_EY_EYWeekendHonorTicks       160

enum BG_EY_Score
{
    BG_EY_WARNING_NEAR_VICTORY_SCORE    = 1200,
    BG_EY_MAX_TEAM_SCORE                = 1500
};

enum BG_EY_FlagState
{
    BG_EY_FLAG_STATE_ON_BASE      = 0,
    BG_EY_FLAG_STATE_WAIT_RESPAWN = 1,
    BG_EY_FLAG_STATE_ON_PLAYER    = 2,
    BG_EY_FLAG_STATE_ON_GROUND    = 3
};

enum EYBattlegroundPointState
{
    EY_POINT_NO_OWNER           = 0,
    EY_POINT_STATE_UNCONTROLLED = 0,
    EY_POINT_UNDER_CONTROL      = 3
};

enum BG_EY_ExploitTeleportLocations
{
    EY_EXPLOIT_TELEPORT_LOCATION_ALLIANCE   = 3773,
    EY_EXPLOIT_TELEPORT_LOCATION_HORDE      = 3772
};

enum BG_EY_BroadcastTexts
{
    BG_EY_TEXT_ALLIANCE_TAKEN_FEL_REAVER_RUINS  = 17828,
    BG_EY_TEXT_HORDE_TAKEN_FEL_REAVER_RUINS     = 17829,
    BG_EY_TEXT_ALLIANCE_LOST_FEL_REAVER_RUINS   = 91961,
    BG_EY_TEXT_HORDE_LOST_FEL_REAVER_RUINS      = 91962,

    BG_EY_TEXT_ALLIANCE_TAKEN_BLOOD_ELF_TOWER   = 17819,
    BG_EY_TEXT_HORDE_TAKEN_BLOOD_ELF_TOWER      = 17823,
    BG_EY_TEXT_ALLIANCE_LOST_BLOOD_ELF_TOWER    = 91957,
    BG_EY_TEXT_HORDE_LOST_BLOOD_ELF_TOWER       = 91958,

    BG_EY_TEXT_ALLIANCE_TAKEN_DRAENEI_RUINS     = 17827,
    BG_EY_TEXT_HORDE_TAKEN_DRAENEI_RUINS        = 91917,
    BG_EY_TEXT_ALLIANCE_LOST_DRAENEI_RUINS      = 91959,
    BG_EY_TEXT_HORDE_LOST_DRAENEI_RUINS         = 91960,

    BG_EY_TEXT_ALLIANCE_TAKEN_MAGE_TOWER        = 17824,
    BG_EY_TEXT_HORDE_TAKEN_MAGE_TOWER           = 17825,
    BG_EY_TEXT_ALLIANCE_LOST_MAGE_TOWER         = 91963,
    BG_EY_TEXT_HORDE_LOST_MAGE_TOWER            = 91964,

    BG_EY_TEXT_TAKEN_FLAG                       = 18359,
    BG_EY_TEXT_FLAG_DROPPED                     = 18361,
    BG_EY_TEXT_FLAG_RESET                       = 18364,
    BG_EY_TEXT_ALLIANCE_CAPTURED_FLAG           = 18375,
    BG_EY_TEXT_HORDE_CAPTURED_FLAG              = 18384,
};

struct BattlegroundEYPointIconsStruct
{
    BattlegroundEYPointIconsStruct(uint32 _WorldStateControlIndex, uint32 _WorldStateAllianceControlledIndex, uint32 _WorldStateHordeControlledIndex,
        uint32 worldStateAllianceStatusBarIcon, uint32 worldStateHordeStatusBarIcon)
        : WorldStateControlIndex(_WorldStateControlIndex), WorldStateAllianceControlledIndex(_WorldStateAllianceControlledIndex), WorldStateHordeControlledIndex(_WorldStateHordeControlledIndex),
        WorldStateAllianceStatusBarIcon(worldStateAllianceStatusBarIcon), WorldStateHordeStatusBarIcon(worldStateHordeStatusBarIcon) { }
    uint32 WorldStateControlIndex;
    uint32 WorldStateAllianceControlledIndex;
    uint32 WorldStateHordeControlledIndex;
    uint32 WorldStateAllianceStatusBarIcon;
    uint32 WorldStateHordeStatusBarIcon;
};

struct BattlegroundEYLosingPointStruct
{
    BattlegroundEYLosingPointStruct(uint32 _MessageIdAlliance, uint32 _MessageIdHorde)
        : MessageIdAlliance(_MessageIdAlliance), MessageIdHorde(_MessageIdHorde)
    { }

    uint32 MessageIdAlliance;
    uint32 MessageIdHorde;
};

struct BattlegroundEYCapturingPointStruct
{
    BattlegroundEYCapturingPointStruct(uint32 _MessageIdAlliance, uint32 _MessageIdHorde)
        : MessageIdAlliance(_MessageIdAlliance), MessageIdHorde(_MessageIdHorde)
    { }

    uint32 MessageIdAlliance;
    uint32 MessageIdHorde;
};

class BattlegroundEY;

class BattlegroundEYControlZoneHandler : public ControlZoneHandler
{
public:
    explicit BattlegroundEYControlZoneHandler(BattlegroundEY* bg, uint32 point);

    void HandleProgressEventHorde(GameObject* controlZone) override;
    void HandleProgressEventAlliance(GameObject* controlZone) override;
    void HandleNeutralEventHorde(GameObject* controlZone) override;
    void HandleNeutralEventAlliance(GameObject* controlZone) override;

    uint32 GetPoint() const { return _point; }

private:
    BattlegroundEY* _battleground;
    uint32 _point;
};

const std::array<uint8, EY_POINTS_MAX> BG_EY_TickPoints = { 1, 2, 5, 10 };
const std::array<uint32, EY_POINTS_MAX> BG_EY_FlagPoints = { 75, 85, 100, 500 };

//constant arrays:
const std::array<BattlegroundEYPointIconsStruct, EY_POINTS_MAX> m_PointsIconStruct =
{
    BattlegroundEYPointIconsStruct(FEL_REAVER_UNCONTROL, FEL_REAVER_ALLIANCE_CONTROL, FEL_REAVER_HORDE_CONTROL, FEL_REAVER_ALLIANCE_CONTROL_STATE, FEL_REAVER_HORDE_CONTROL_STATE),
    BattlegroundEYPointIconsStruct(BLOOD_ELF_UNCONTROL, BLOOD_ELF_ALLIANCE_CONTROL, BLOOD_ELF_HORDE_CONTROL, BLOOD_ELF_ALLIANCE_CONTROL_STATE, BLOOD_ELF_HORDE_CONTROL_STATE),
    BattlegroundEYPointIconsStruct(DRAENEI_RUINS_UNCONTROL, DRAENEI_RUINS_ALLIANCE_CONTROL, DRAENEI_RUINS_HORDE_CONTROL, DRAENEI_RUINS_ALLIANCE_CONTROL_STATE, DRAENEI_RUINS_HORDE_CONTROL_STATE),
    BattlegroundEYPointIconsStruct(MAGE_TOWER_UNCONTROL, MAGE_TOWER_ALLIANCE_CONTROL, MAGE_TOWER_HORDE_CONTROL, MAGE_TOWER_ALLIANCE_CONTROL_STATE, MAGE_TOWER_HORDE_CONTROL_STATE)
};

const std::array<BattlegroundEYLosingPointStruct, EY_POINTS_MAX> m_LosingPointTypes =
{
    BattlegroundEYLosingPointStruct(BG_EY_TEXT_ALLIANCE_LOST_FEL_REAVER_RUINS, BG_EY_TEXT_HORDE_LOST_FEL_REAVER_RUINS),
    BattlegroundEYLosingPointStruct(BG_EY_TEXT_ALLIANCE_LOST_BLOOD_ELF_TOWER, BG_EY_TEXT_HORDE_LOST_BLOOD_ELF_TOWER),
    BattlegroundEYLosingPointStruct(BG_EY_TEXT_ALLIANCE_LOST_DRAENEI_RUINS, BG_EY_TEXT_HORDE_LOST_DRAENEI_RUINS),
    BattlegroundEYLosingPointStruct(BG_EY_TEXT_ALLIANCE_LOST_MAGE_TOWER, BG_EY_TEXT_HORDE_LOST_MAGE_TOWER)
};

const std::array<BattlegroundEYCapturingPointStruct, EY_POINTS_MAX> m_CapturingPointTypes =
{
    BattlegroundEYCapturingPointStruct(BG_EY_TEXT_ALLIANCE_TAKEN_FEL_REAVER_RUINS, BG_EY_TEXT_HORDE_TAKEN_FEL_REAVER_RUINS),
    BattlegroundEYCapturingPointStruct(BG_EY_TEXT_ALLIANCE_TAKEN_BLOOD_ELF_TOWER, BG_EY_TEXT_HORDE_TAKEN_BLOOD_ELF_TOWER),
    BattlegroundEYCapturingPointStruct(BG_EY_TEXT_ALLIANCE_TAKEN_DRAENEI_RUINS, BG_EY_TEXT_HORDE_TAKEN_DRAENEI_RUINS),
    BattlegroundEYCapturingPointStruct(BG_EY_TEXT_ALLIANCE_TAKEN_MAGE_TOWER, BG_EY_TEXT_HORDE_TAKEN_MAGE_TOWER)
};

class BattlegroundEY : public Battleground
{
    public:
        BattlegroundEY(BattlegroundTemplate const* battlegroundTemplate);
        ~BattlegroundEY();

        /* inherited from BattlegroundClass */
        void StartingEventOpenDoors() override;

        void HandleAreaTrigger(Player* source, uint32 trigger, bool entered) override;
        void HandleKillPlayer(Player* player, Player* killer) override;
        WorldSafeLocsEntry const* GetExploitTeleportLocation(Team team) override;
        bool SetupBattleground() override;
        void Reset() override;
        void UpdateTeamScore(TeamId Team);
        void EndBattleground(Team winner) override;

        Team GetPrematureWinner() override;

        void ProcessEvent(WorldObject* target, uint32 eventId, WorldObject* invoker) override;
        void PostUpdateImpl(uint32 diff) override;

        void EventTeamCapturedPoint(TeamId teamId, uint32 point, GameObject* controlZone);
        void EventTeamLostPoint(TeamId teamId, uint32 point, GameObject* controlZone);
        void UpdatePointsCount(TeamId teamId);

        void OnGameObjectCreate(GameObject* gameObject) override;

        bool CanCaptureFlag([[maybe_unused]] AreaTrigger* areaTrigger, [[maybe_unused]] Player* player) override;
        void OnCaptureFlag([[maybe_unused]] AreaTrigger* areaTrigger, [[maybe_unused]] Player* player) override;
        void OnFlagStateChange(GameObject* flagInBase, FlagState oldValue, FlagState newValue, Player* player) override;

    private:
        /* Scorekeeping */
        void AddPoints(Team team, uint32 Points);

        void RemovePoint(Team team, uint32 Points = 1) { m_TeamScores[GetTeamIndexByTeamId(team)] -= Points; }
        void SetTeamPoint(Team team, uint32 Points = 0) { m_TeamScores[GetTeamIndexByTeamId(team)] = Points; }

        uint8 GetControlledBaseCount(TeamId teamId) const;

        std::array<uint32, PVP_TEAMS_COUNT> m_HonorScoreTics;

        uint32 m_FlagCapturedBgObjectType;                  // type that should be despawned when flag is captured

        TimeTracker _pointsTimer;
        uint32 m_HonorTics;

        std::unordered_map<uint32, std::unique_ptr<BattlegroundEYControlZoneHandler>> _controlZoneHandlers;
        GuidUnorderedSet _doorGUIDs;
        ObjectGuid _flagGUID;

        // Focused/Brutal Assault
        bool _assaultEnabled;
        TimeTracker _flagAssaultTimer;
        uint16 _assaultStackCount;

        void DoForFlagKeepers(std::function<void(Player*)> action) const;
        void ResetAssaultDebuff();
        void ApplyAssaultDebuffToPlayer(Player* player);
        void RemoveAssaultDebuffFromPlayer(Player* player);
};
#endif
