/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef __BATTLEGROUNDWS_H
#define __BATTLEGROUNDWS_H

#include "BattleGround.h"

enum BG_WS_TimerOrScore
{
    BG_WS_MAX_TEAM_SCORE    = 3,
    BG_WS_FLAG_RESPAWN_TIME = 23000,
    BG_WS_FLAG_DROP_TIME    = 10000,
    BG_WS_SPELL_FORCE_TIME  = 600000,
    BG_WS_SPELL_BRUTAL_TIME = 900000
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
    BG_WS_SPELL_SILVERWING_FLAG         = 23335,
    BG_WS_SPELL_SILVERWING_FLAG_DROPPED = 23336,
    BG_WS_SPELL_FOCUSED_ASSAULT         = 46392,
    BG_WS_SPELL_BRUTAL_ASSAULT          = 46393
};

enum BG_WS_WorldStates
{
    BG_WS_FLAG_UNK_ALLIANCE       = 1545,
    BG_WS_FLAG_UNK_HORDE          = 1546,
//    FLAG_UNK                      = 1547,
    BG_WS_FLAG_CAPTURES_ALLIANCE  = 1581,
    BG_WS_FLAG_CAPTURES_HORDE     = 1582,
    BG_WS_FLAG_CAPTURES_MAX       = 1601,
    BG_WS_FLAG_STATE_HORDE        = 2338,
    BG_WS_FLAG_STATE_ALLIANCE     = 2339,
    BG_WS_STATE_TIMER             = 4248,
    BG_WS_STATE_TIMER_ACTIVE      = 4247
};

enum BG_WS_ObjectTypes
{
    BG_WS_OBJECT_DOOR_A_1       = 0,
    BG_WS_OBJECT_DOOR_A_2       = 1,
    BG_WS_OBJECT_DOOR_A_3       = 2,
    BG_WS_OBJECT_DOOR_A_4       = 3,
    BG_WS_OBJECT_DOOR_A_5       = 4,
    BG_WS_OBJECT_DOOR_A_6       = 5,
    BG_WS_OBJECT_DOOR_H_1       = 6,
    BG_WS_OBJECT_DOOR_H_2       = 7,
    BG_WS_OBJECT_DOOR_H_3       = 8,
    BG_WS_OBJECT_DOOR_H_4       = 9,
    BG_WS_OBJECT_A_FLAG         = 10,
    BG_WS_OBJECT_H_FLAG         = 11,
    BG_WS_OBJECT_SPEEDBUFF_1    = 12,
    BG_WS_OBJECT_SPEEDBUFF_2    = 13,
    BG_WS_OBJECT_REGENBUFF_1    = 14,
    BG_WS_OBJECT_REGENBUFF_2    = 15,
    BG_WS_OBJECT_BERSERKBUFF_1  = 16,
    BG_WS_OBJECT_BERSERKBUFF_2  = 17,
    BG_WS_OBJECT_MAX            = 18
};

enum BG_WS_ObjectEntry
{
    BG_OBJECT_DOOR_A_1_WS_ENTRY          = 179918,
    BG_OBJECT_DOOR_A_2_WS_ENTRY          = 179919,
    BG_OBJECT_DOOR_A_3_WS_ENTRY          = 179920,
    BG_OBJECT_DOOR_A_4_WS_ENTRY          = 179921,
    BG_OBJECT_DOOR_A_5_WS_ENTRY          = 180322,
    BG_OBJECT_DOOR_A_6_WS_ENTRY          = 180322,
    BG_OBJECT_DOOR_H_1_WS_ENTRY          = 179916,
    BG_OBJECT_DOOR_H_2_WS_ENTRY          = 179917,
    BG_OBJECT_DOOR_H_3_WS_ENTRY          = 180322,
    BG_OBJECT_DOOR_H_4_WS_ENTRY          = 180322,
    BG_OBJECT_A_FLAG_WS_ENTRY            = 179830,
    BG_OBJECT_H_FLAG_WS_ENTRY            = 179831,
    BG_OBJECT_A_FLAG_GROUND_WS_ENTRY     = 179785,
    BG_OBJECT_H_FLAG_GROUND_WS_ENTRY     = 179786
};

enum BG_WS_FlagState
{
    BG_WS_FLAG_STATE_ON_BASE      = 0,
    BG_WS_FLAG_STATE_WAIT_RESPAWN = 1,
    BG_WS_FLAG_STATE_ON_PLAYER    = 2,
    BG_WS_FLAG_STATE_ON_GROUND    = 3
};

enum BG_WS_Graveyards
{
    WS_GRAVEYARD_FLAGROOM_ALLIANCE = 769,
    WS_GRAVEYARD_FLAGROOM_HORDE    = 770,
    WS_GRAVEYARD_MAIN_ALLIANCE     = 771,
    WS_GRAVEYARD_MAIN_HORDE        = 772
};

enum BG_WS_CreatureTypes
{
    WS_SPIRIT_MAIN_ALLIANCE   = 0,
    WS_SPIRIT_MAIN_HORDE      = 1,

    BG_CREATURES_MAX_WS       = 2
};

enum BG_WS_CarrierDebuffs
{
    WS_SPELL_FOCUSED_ASSAULT   = 46392,
    WS_SPELL_BRUTAL_ASSAULT    = 46393
};

class BattleGroundWGScore : public BattleGroundScore
{
    public:
        BattleGroundWGScore() : FlagCaptures(0), FlagReturns(0) {};
        virtual ~BattleGroundWGScore() {};
        uint32 FlagCaptures;
        uint32 FlagReturns;
};

class BattleGroundWS : public BattleGround
{
    friend class BattleGroundMgr;

    public:
        /* Construction */
        BattleGroundWS();
        ~BattleGroundWS();
        void Update(uint32 diff);

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player *plr);
        virtual void StartingEventCloseDoors();
        virtual void StartingEventOpenDoors();

        /* BG Flags */
        uint64 GetAllianceFlagPickerGUID() const    { return m_FlagKeepers[BG_TEAM_ALLIANCE]; }
        uint64 GetHordeFlagPickerGUID() const       { return m_FlagKeepers[BG_TEAM_HORDE]; }
        void SetAllianceFlagPicker(uint64 guid)     { m_FlagKeepers[BG_TEAM_ALLIANCE] = guid; }
        void SetHordeFlagPicker(uint64 guid)        { m_FlagKeepers[BG_TEAM_HORDE] = guid; }
        bool IsAllianceFlagPickedup() const         { return m_FlagKeepers[BG_TEAM_ALLIANCE] != 0; }
        bool IsHordeFlagPickedup() const            { return m_FlagKeepers[BG_TEAM_HORDE] != 0; }
        void RespawnFlag(uint32 Team, bool captured);
        void RespawnFlagAfterDrop(uint32 Team);
        uint8 GetFlagState(uint32 team)             { return m_FlagState[GetTeamIndexByTeamId(team)]; }
        void AddTimedAura(uint32 aura);
        void RemoveTimedAura(uint32 aura);
        bool IsBrutalTimerDone;
        bool IsForceTimerDone;

        /* Battleground Events */
        virtual void EventPlayerDroppedFlag(Player *Source);
        virtual void EventPlayerClickedOnFlag(Player *Source, GameObject* target_obj);
        virtual void EventPlayerCapturedFlag(Player *Source);

        void RemovePlayer(Player *plr, uint64 guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);
        void HandleKillPlayer(Player *player, Player *killer);
        bool SetupBattleGround();
        virtual void Reset();
        void EndBattleGround(uint32 winner);
        virtual WorldSafeLocsEntry const* GetClosestGraveYard(Player* player);

        void UpdateFlagState(uint32 team, uint32 value);
        void SetFirstFlagCapture(uint32 team)                { m_FirstFlagCaptureTeam = team; }
        void UpdateTeamScore(uint32 team);
        void UpdatePlayerScore(Player *Source, uint32 type, uint32 value);
        void SetDroppedFlagGUID(uint64 guid, uint32 TeamID)  { m_DroppedFlagGUID[GetTeamIndexByTeamId(TeamID)] = guid;}
        uint64 GetDroppedFlagGUID(uint32 TeamID)             { return m_DroppedFlagGUID[GetTeamIndexByTeamId(TeamID)];}
        virtual void FillInitialWorldStates(WorldPacket& data);

        /* Scorekeeping */
        uint32 GetTeamScore(uint32 TeamID) const            { return m_TeamScores[GetTeamIndexByTeamId(TeamID)]; }
        void AddPoint(uint32 TeamID, uint32 Points = 1)     { m_TeamScores[GetTeamIndexByTeamId(TeamID)] += Points; }
        void SetTeamPoint(uint32 TeamID, uint32 Points = 0) { m_TeamScores[GetTeamIndexByTeamId(TeamID)] = Points; }
        void RemovePoint(uint32 TeamID, uint32 Points = 1)  { m_TeamScores[GetTeamIndexByTeamId(TeamID)] -= Points; }
    private:
        uint64 m_FlagKeepers[2];                            // 0 - alliance, 1 - horde
        uint64 m_DroppedFlagGUID[2];
        uint8 m_FlagState[2];                               // for checking flag state
        int32 m_FlagsTimer[2];
        int32 m_FlagsDropTimer[2];
        uint32 m_FirstFlagCaptureTeam;                      // Winner is based on this if score is equal

        uint32 m_ReputationCapture;
        uint32 m_HonorWinKills;
        uint32 m_HonorEndKills;
        int32 m_FlagSpellForceTimer;
        bool m_BothFlagsKept;
        uint8 m_FlagDebuffState;                            // 0 - no debuffs, 1 - focused assault, 2 - brutal assault
        uint8 m_minutesElapsed;
};
#endif

