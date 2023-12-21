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

#ifndef __BATTLEGROUNDWS_H
#define __BATTLEGROUNDWS_H

#include "Battleground.h"
#include "BattlegroundScore.h"
#include "Timer.h"

enum BG_WS_TimerOrScore
{
    BG_WS_MAX_TEAM_SCORE    = 3,
    BG_WS_FLAG_RESPAWN_TIME = 23000,
    BG_WS_FLAG_DROP_TIME    = 10000,
    BG_WS_SPELL_FORCE_TIME  = 600000,
    BG_WS_SPELL_BRUTAL_TIME = 900000
};

enum BG_WS_BroadcastTexts
{
    BG_WS_TEXT_START_ONE_MINUTE         = 10015,
    BG_WS_TEXT_START_HALF_MINUTE        = 10016,
    BG_WS_TEXT_BATTLE_HAS_BEGUN         = 10014,

    BG_WS_TEXT_CAPTURED_HORDE_FLAG      = 9801,
    BG_WS_TEXT_CAPTURED_ALLIANCE_FLAG   = 9802,
    BG_WS_TEXT_FLAGS_PLACED             = 9803,
    BG_WS_TEXT_ALLIANCE_FLAG_PICKED_UP  = 9804,
    BG_WS_TEXT_ALLIANCE_FLAG_DROPPED    = 9805,
    BG_WS_TEXT_HORDE_FLAG_PICKED_UP     = 9807,
    BG_WS_TEXT_HORDE_FLAG_DROPPED       = 9806,
    BG_WS_TEXT_ALLIANCE_FLAG_RETURNED   = 9808,
    BG_WS_TEXT_HORDE_FLAG_RETURNED      = 9809,
};

enum BG_WS_Sound
{
    BG_WS_SOUND_FLAG_CAPTURED_ALLIANCE  = 8173,
    BG_WS_SOUND_FLAG_CAPTURED_HORDE     = 8213,
    BG_WS_SOUND_FLAG_PLACED             = 8232,
    BG_WS_SOUND_FLAG_RETURNED           = 8192,
    BG_WS_SOUND_HORDE_FLAG_PICKED_UP    = 8212,
    BG_WS_SOUND_ALLIANCE_FLAG_PICKED_UP = 8174,
    BG_WS_SOUND_FLAGS_RESPAWNED         = 8232
};

enum BG_WS_SpellId
{
    BG_WS_SPELL_WARSONG_FLAG            = 23333,
    BG_WS_SPELL_WARSONG_FLAG_DROPPED    = 23334,
    //BG_WS_SPELL_WARSONG_FLAG_PICKED     = 61266,
    BG_WS_SPELL_SILVERWING_FLAG         = 23335,
    BG_WS_SPELL_SILVERWING_FLAG_DROPPED = 23336,
    //BG_WS_SPELL_SILVERWING_FLAG_PICKED  = 61265,
    BG_WS_SPELL_FOCUSED_ASSAULT         = 46392,
    BG_WS_SPELL_BRUTAL_ASSAULT          = 46393,
    BG_WS_SPELL_QUICK_CAP_TIMER         = 183317,   // serverside
};

enum BG_WS_WorldStates
{
    BG_WS_FLAG_STATE_ALLIANCE           = 1545,
    BG_WS_FLAG_STATE_HORDE              = 1546,
    BG_WS_FLAG_STATE_NEUTRAL            = 1547,     // unused
    BG_WS_HORDE_FLAG_COUNT_PICKED_UP    = 17712,    // brawl
    BG_WS_ALLIANCE_FLAG_COUNT_PICKED_UP = 17713,    // brawl
    BG_WS_FLAG_CAPTURES_ALLIANCE        = 1581,
    BG_WS_FLAG_CAPTURES_HORDE           = 1582,
    BG_WS_FLAG_CAPTURES_MAX             = 1601,
    BG_WS_FLAG_CAPTURES_MAX_NEW         = 17303,
    BG_WS_FLAG_CONTROL_HORDE            = 2338,
    BG_WS_FLAG_CONTROL_ALLIANCE         = 2339,
    BG_WS_STATE_TIMER                   = 4248,
    BG_WS_STATE_TIMER_ACTIVE            = 4247
};

// save the day
// alliance criteria: BG_WS_FLAG_STATE_HORDE == 1 && BG_WS_FLAG_STATE_NEUTRAL == 0 && WS(1664) > 0
// horde criteria: BG_WS_FLAG_STATE_ALLIANCE == 1 && BG_WS_FLAG_STATE_NEUTRAL == 0 && WS(1664) > 0

enum BG_WS_ExploitTeleportLocations
{
    WS_EXPLOIT_TELEPORT_LOCATION_ALLIANCE   = 7051,
    WS_EXPLOIT_TELEPORT_LOCATION_HORDE      = 7050
};

enum BG_WS_ObjectEntry
{
    // doors
    BG_WS_OBJECT_ALLIANCE_DOOR      = 309704,
    BG_WS_OBJECT_PORTCULLIS_009     = 309705, // Doodad_7NE_Blackrook_Portcullis009
    BG_WS_OBJECT_PORTCULLIS_002     = 309883, // Doodad_7NE_Blackrook_Portcullis002
    BG_WS_OBJECT_COLLISION_PC_SIZE  = 242273,
    BG_WS_OBJECT_HORDE_GATE_1       = 352709,
    BG_WS_OBJECT_HORDE_GATE_2       = 352710,

    // flags
    BG_WS_OBJECT_ALLIANCE_FLAG_IN_BASE  = 227741,
    BG_WS_OBJECT_HORDE_FLAG_IN_BASE     = 227740
};

enum BG_WS_CarrierDebuffs
{
    WS_SPELL_FOCUSED_ASSAULT   = 46392,
    WS_SPELL_BRUTAL_ASSAULT    = 46393,

    SPELL_CAPTURED_ALLIANCE_COSMETIC_FX = 262508,
    SPELL_CAPTURED_HORDE_COSMETIC_FX    = 262512,
};

enum BG_WS_AreaTriggers
{
    AT_CAPTURE_POINT_ALLIANCE   = 30,
    AT_CAPTURE_POINT_HORDE      = 31
};

static constexpr uint32 WS_EVENT_START_BATTLE = 35912;

static constexpr Seconds FLAG_ASSAULT_TIMER = 30s;
static constexpr uint16 FLAG_BRUTAL_ASSAULT_STACK_COUNT = 5;

class BattlegroundWS : public Battleground
{
    public:
        /* Construction */
        BattlegroundWS(BattlegroundTemplate const* battlegroundTemplate);
        ~BattlegroundWS();

        /* inherited from BattlegroundClass */
        void StartingEventOpenDoors() override;

        /* BG Flags */
        FlagState GetFlagState(TeamId team) const;
        ObjectGuid const& GetFlagCarrierGUID(TeamId team) const;
        void HandleFlagRoomCapturePoint();

        void HandleKillPlayer(Player* player, Player* killer) override;
        bool SetupBattleground() override;
        void Reset() override;
        void EndBattleground(uint32 winner) override;
        WorldSafeLocsEntry const* GetClosestGraveyard(Player* player) override;
        WorldSafeLocsEntry const* GetExploitTeleportLocation(Team team) override;

        void UpdateFlagState(uint32 team, FlagState value);
        void SetLastFlagCapture(uint32 team)                { _lastFlagCaptureTeam = team; }
        void UpdateTeamScore(uint32 team);

        /* Scorekeeping */
        void AddPoint(uint32 TeamID, uint32 Points = 1)     { m_TeamScores[GetTeamIndexByTeamId(TeamID)] += Points; }
        void SetTeamPoint(uint32 TeamID, uint32 Points = 0) { m_TeamScores[GetTeamIndexByTeamId(TeamID)] = Points; }
        void RemovePoint(uint32 TeamID, uint32 Points = 1)  { m_TeamScores[GetTeamIndexByTeamId(TeamID)] -= Points; }

        uint32 GetPrematureWinner() override;

        void OnGameObjectCreate(GameObject* gameObject) override;
        void OnAreaTriggerCreate(AreaTrigger* areaTrigger) override;
        void OnFlagStateChange(GameObject* flagInBase, FlagState oldValue, FlagState newValue, Player* player) override;

        bool CanCaptureFlag(AreaTrigger* areatrigger, Player* player) override;
        void OnCaptureFlag(AreaTrigger* areatrigger, Player* player) override;

    protected:
        void PostUpdateImpl(uint32 diff) override;
        void DoForFlagKeepers(std::function<void(Player*)> action) const;

        // Focused & Brutal Assault debuffs
        void ResetAssaultDebuff();
        void ApplyAssaultDebuffToPlayer(Player* player);
        void RemoveAssaultDebuffFromPlayer(Player* player);

    private:
        uint32 _lastFlagCaptureTeam;                       // Winner is based on this if score is equal

        uint32 m_ReputationCapture;
        uint32 m_HonorWinKills;
        uint32 m_HonorEndKills;
        bool _bothFlagsKept;

        GuidSet _doors;
        std::array<ObjectGuid, 2> _flags;

        TimeTracker _flagAssaultTimer;
        uint16 _assaultStackCount;
        std::array<ObjectGuid, 2> _capturePointAreaTriggers;
};
#endif
