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

#ifndef __BATTLEGROUNDTP_H
#define __BATTLEGROUNDTP_H

#include "Battleground.h"
#include "BattlegroundScore.h"
#include "EventMap.h"

namespace WorldPackets
{
    namespace WorldState
    {
        class InitWorldStates;
    }
}

enum BG_TP_TimerOrScore
{
    BG_TP_MAX_TEAM_SCORE            = 3,
    BG_TP_FLAG_RESPAWN_TIME         = 23000,
    BG_TP_FLAG_DROP_TIME            = 10000,
    BG_TP_SPELL_FORCE_TIME          = 600000,
    BG_TP_SPELL_BRUTAL_TIME         = 900000
};

enum BG_TP_BroadcastTexts
{
    BG_TP_TEXT_START_ONE_MINUTE         = 41186,
    BG_TP_TEXT_START_HALF_MINUTE        = 41187,
    BG_TP_TEXT_BATTLE_HAS_BEGUN         = 10014,

    BG_TP_TEXT_CAPTURED_HORDE_FLAG      = 9801,
    BG_TP_TEXT_CAPTURED_ALLIANCE_FLAG   = 9802,
    BG_TP_TEXT_FLAG_PLACED_HORDE        = 24892,
    BG_TP_TEXT_FLAG_PLACED_ALLIANCE     = 24891,
    BG_TP_TEXT_ALLIANCE_FLAG_PICKED_UP  = 9804,
    BG_TP_TEXT_ALLIANCE_FLAG_DROPPED    = 9805,
    BG_TP_TEXT_HORDE_FLAG_PICKED_UP     = 9807,
    BG_TP_TEXT_HORDE_FLAG_DROPPED       = 9806,
    BG_TP_TEXT_ALLIANCE_FLAG_RETURNED   = 9808,
    BG_TP_TEXT_HORDE_FLAG_RETURNED      = 9809,
};

enum BG_TP_Sound
{
    BG_TP_SOUND_FLAG_CAPTURED_ALLIANCE  = 8173,
    BG_TP_SOUND_FLAG_CAPTURED_HORDE     = 8213,
    BG_TP_SOUND_FLAG_PLACED             = 8232,
    BG_TP_SOUND_FLAG_RETURNED           = 8192,
    BG_TP_SOUND_HORDE_FLAG_PICKED_UP    = 8212,
    BG_TP_SOUND_ALLIANCE_FLAG_PICKED_UP = 8174,
    BG_TP_SOUND_FLAGS_RESPAWNED         = 8232
};

enum BG_TP_SpellId
{
    BG_TP_SPELL_HORDE_FLAG              = 23333,
    BG_TP_SPELL_HORDE_FLAG_DROPPED      = 23334,
    BG_TP_SPELL_HORDE_FLAG_PICKED       = 61266, // fake spell, does not exist but used as timer start event
    BG_TP_SPELL_ALLIANCE_FLAG           = 23335,
    BG_TP_SPELL_ALLIANCE_FLAG_DROPPED   = 23336,
    BG_TP_SPELL_ALLIANCE_FLAG_PICKED    = 61265, // fake spell, does not exist but used as timer start event
    BG_TP_SPELL_FOCUSED_ASSAULT         = 46392,
    BG_TP_SPELL_BRUTAL_ASSAULT          = 46393,
    BG_TP_SPELL_REMOVE_CARRIED_FLAG     = 45919
};

/// To Do: Find what unk world states means and rename
enum BG_TP_WorldStates
{
    BG_TP_FLAG_UNK_ALLIANCE         = 1545, ///< Value: -1 when alliance flag is dropped | 1 when alliance flag is on player | 0 On base | -2 ???
    BG_TP_FLAG_UNK_HORDE            = 1546, ///< Value: -1 when horde flag is dropped | 1 when horde flag is on player | 0 On base | -2 ???
    BG_TP_FLAG_UNKNOWN              = 1547, ///< -1 before capturing flag, 0 after both flags respawned
    BG_TP_FLAG_CAPTURES_ALLIANCE    = 1581,
    BG_TP_FLAG_CAPTURES_HORDE       = 1582,
    BG_TP_FLAG_CAPTURES_MAX         = 1601,
    BG_TP_FLAG_STATE_HORDE          = 2338,
    BG_TP_FLAG_STATE_ALLIANCE       = 2339,
    BG_TP_STATE_TIMER               = 4248,
    BG_TP_STATE_TIMER_ACTIVE        = 4247,
    BG_TP_STATE_UNKNOWN             = 4249  ///< Used after flag is captured (value: 1)
};

enum BG_TP_ObjectTypes
{
    BG_TP_OBJECT_DOOR_A_1 = 0,
    BG_TP_OBJECT_DOOR_A_2,
    BG_TP_OBJECT_DOOR_A_3,
    BG_TP_OBJECT_DOOR_H_1,
    BG_TP_OBJECT_DOOR_H_2,
    BG_TP_OBJECT_DOOR_H_3,
    BG_TP_OBJECT_DOOR_H_4,
    BG_TP_OBJECT_A_FLAG,
    BG_TP_OBJECT_H_FLAG,
    BG_TP_OBJECT_SPEEDBUFF_1,
    BG_TP_OBJECT_SPEEDBUFF_2,
    BG_TP_OBJECT_REGENBUFF_1,
    BG_TP_OBJECT_REGENBUFF_2,
    BG_TP_OBJECT_BERSERKBUFF_1,
    BG_TP_OBJECT_BERSERKBUFF_2,
    BG_TP_OBJECT_MAX
};

enum BG_TP_ObjectEntry
{
    BG_OBJECT_DOOR_A_1_TP_ENTRY         = 206655,
    BG_OBJECT_DOOR_A_2_TP_ENTRY         = 206654,
    BG_OBJECT_DOOR_A_3_TP_ENTRY         = 206653,
    BG_OBJECT_DOOR_H_1_TP_ENTRY         = 208205,
    BG_OBJECT_DOOR_H_2_TP_ENTRY         = 208206,
    BG_OBJECT_DOOR_H_3_TP_ENTRY         = 208207,
    BG_OBJECT_DOOR_H_4_TP_ENTRY         = 203710,
    BG_OBJECT_A_FLAG_TP_ENTRY           = 179830,
    BG_OBJECT_H_FLAG_TP_ENTRY           = 179831,
    BG_OBJECT_A_FLAG_GROUND_TP_ENTRY    = 179785,
    BG_OBJECT_H_FLAG_GROUND_TP_ENTRY    = 179786,
    GB_OBJECT_SPEED_BUFF_1_TP_ENTRY     = 179899,
    GB_OBJECT_BERSERKER_BUFF_1_TP_ENTRY = 179907,
    GB_OBJECT_FOOD_BUFF_1_TP_ENTRY      = 179906
};

enum BG_TP_FlagState
{
    BG_TP_FLAG_STATE_ON_BASE = 0,
    BG_TP_FLAG_STATE_WAIT_RESPAWN,
    BG_TP_FLAG_STATE_ON_PLAYER,
    BG_TP_FLAG_STATE_ON_GROUND,
};

enum BG_TP_Graveyards
{
    TP_GRAVEYARD_FLAGROOM_ALLIANCE  = 0,
    TP_GRAVEYARD_FLAGROOM_HORDE     = 1,

    TP_GRAVEYARD_START_ALLIANCE     = 2,
    TP_GRAVEYARD_START_HORDE        = 3,

    TP_GRAVEYARD_MIDDLE_ALLIANCE    = 4,
    TP_GRAVEYARD_MIDDLE_HORDE       = 5,

    TP_MAX_GRAVEYARDS               = 6
};

const uint32 BG_TP_GraveyardIds[TP_MAX_GRAVEYARDS] = { 1726, 1727, 1729, 1728, 1749, 1750 };

enum BG_TP_CreatureTypes
{
    TP_SPIRIT_ALLIANCE  = 0,
    TP_SPIRIT_HORDE     = 1,

    BG_CREATURES_MAX_TP = 2
};

enum BG_TP_CarrierDebuffs
{
    TP_SPELL_FOCUSED_ASSAULT = 46392,
    TP_SPELL_BRUTAL_ASSAULT = 46393
};

enum BG_TP_Objectives
{
    TP_OBJECTIVE_CAPTURE_FLAG = 290,
    TP_OBJECTIVE_RETURN_FLAG = 291
};

enum BG_TP_Events
{
    TP_EVENT_SPAWN_FLAGS = 1,
    TP_EVENT_CLOSE_BATTLEGROUND,
    TP_EVENT_UPDATE_BATTLEGROUND_TIMER,
    TP_EVENT_RESPAWN_ALLIANCE_FLAG,
    TP_EVENT_RESPAWN_HORDE_FLAG,
};

#define TP_EVENT_START_BATTLE 8563

class BattlegroundTPScore final : public BattlegroundScore
{
    friend class BattlegroundTP;

    protected:
        BattlegroundTPScore(ObjectGuid playerGuid, uint32 team) : BattlegroundScore(playerGuid, team), FlagCaptures(0), FlagReturns(0) { }

        void UpdateScore(uint32 type, uint32 value) override
        {
            switch (type)
            {
                case SCORE_FLAG_CAPTURES:
                    FlagCaptures += value;
                    break;
                case SCORE_FLAG_RETURNS:
                    FlagReturns += value;
                    break;
                default:
                    BattlegroundScore::UpdateScore(type, value);
                    break;
            }
        }

        void BuildObjectivesBlock(WorldPacket& data, ByteBuffer& content) final override;

        uint32 GetAttr1() const final override { return FlagCaptures; }
        uint32 GetAttr2() const final override { return FlagReturns; }

        uint32 FlagCaptures;
        uint32 FlagReturns;
};

class BattlegroundTP : public Battleground
{
    public:
        BattlegroundTP();
        ~BattlegroundTP();

        /* inherited from BattlegroundClass */
        void AddPlayer(Player* player) override;
        void StartingEventCloseDoors() override;
        void StartingEventOpenDoors() override;

        /* BG Flags */
        ObjectGuid GetFlagPickerGUID(int32 team) const override
        {
            if (team == TEAM_ALLIANCE || team == TEAM_HORDE)
                return m_FlagKeepers[team];
            return ObjectGuid::Empty;
        }
        void SetAllianceFlagPicker(ObjectGuid guid) { m_FlagKeepers[TEAM_ALLIANCE] = guid; }
        void SetHordeFlagPicker(ObjectGuid guid)    { m_FlagKeepers[TEAM_HORDE] = guid; }
        bool IsAllianceFlagPickedup() const         { return !m_FlagKeepers[TEAM_ALLIANCE].IsEmpty(); }
        bool IsHordeFlagPickedup() const            { return !m_FlagKeepers[TEAM_HORDE].IsEmpty(); }
        void RespawnFlag(uint32 Team, bool captured);
        void RespawnFlagAfterDrop(uint32 Team);
        uint8 GetFlagState(uint32 team)             { return _flagState[GetTeamIndexByTeamId(team)]; }

        /* Battleground Events */
        void EventPlayerDroppedFlag(Player* player) override;
        void EventPlayerClickedOnFlag(Player* player, GameObject* target_obj) override;
        void EventPlayerCapturedFlag(Player* player);

        void RemovePlayer(Player* player, ObjectGuid guid, uint32 team) override;
        void HandleAreaTrigger(Player* player, uint32 trigger) override;
        void HandleKillPlayer(Player* player, Player* killer) override;
        bool SetupBattleground() override;
        void Reset() override;
        void EndBattleground(uint32 winner) override;
        WorldSafeLocsEntry const* GetClosestGraveyard(Player* player) override;

        void UpdateFlagState(uint32 team, uint32 value);
        void SetLastFlagCapture(uint32 team)                { _lastFlagCaptureTeam = team; }
        void UpdateTeamScore(uint32 team);
        bool UpdatePlayerScore(Player* player, uint32 type, uint32 value, bool doAddHonor = true) override;
        void SetDroppedFlagGUID(ObjectGuid guid, int32 team = -1) override
        {
            if (team == TEAM_ALLIANCE || team == TEAM_HORDE)
                m_DroppedFlagGUID[team] = guid;
        }

        ObjectGuid GetDroppedFlagGUID(uint32 TeamID)             { return m_DroppedFlagGUID[GetTeamIndexByTeamId(TeamID)]; }
        /* Scorekeeping */
        void AddPoint(uint32 TeamID, uint32 Points = 1)     { m_TeamScores[GetTeamIndexByTeamId(TeamID)] += Points; }
        void SetTeamPoint(uint32 TeamID, uint32 Points = 0) { m_TeamScores[GetTeamIndexByTeamId(TeamID)] = Points; }
        void RemovePoint(uint32 TeamID, uint32 Points = 1)  { m_TeamScores[GetTeamIndexByTeamId(TeamID)] -= Points; }

        uint32 GetPrematureWinner() override;

    private:
        ObjectGuid m_FlagKeepers[2];                            // 0 - alliance, 1 - horde
        ObjectGuid m_DroppedFlagGUID[2];
        uint8 _flagState[2];                               // for checking flag state
        int32 _flagsTimer[2];
        int32 _flagsDropTimer[2];
        uint32 _lastFlagCaptureTeam;                       // Winner is based on this if score is equal

        uint32 m_ReputationCapture;
        uint32 m_HonorWinKills;
        uint32 m_HonorEndKills;
        int32 _flagSpellForceTimer;
        bool _bothFlagsKept;
        uint8 _flagDebuffState;                            // 0 - no debuffs, 1 - focused assault, 2 - brutal assault
        uint8 _minutesElapsed;

        void PostUpdateImpl(uint32 diff) override;

        EventMap events;
};

#endif
