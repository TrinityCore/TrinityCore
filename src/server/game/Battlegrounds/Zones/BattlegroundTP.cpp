/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "BattlegroundTP.h"
#include "BattlegroundMgr.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "Log.h"
#include "Map.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellInfo.h"
#include "WorldStatePackets.h"

enum BG_TP_Rewards
{
    BG_TP_WIN = 0,
    BG_TP_FLAG_CAP,
    BG_TP_MAP_COMPLETE,
    BG_TP_REWARD_NUM
};

uint32 BG_TP_Honor[BG_HONOR_MODE_NUM][BG_TP_REWARD_NUM] =
{
    {20, 40, 40}, // normal honor
    {60, 40, 80}  // holiday
};

BattlegroundTP::BattlegroundTP()
{
    BgObjects.resize(BG_TP_OBJECT_MAX);
    BgCreatures.resize(BG_CREATURES_MAX_TP);

    StartMessageIds[BG_STARTING_EVENT_SECOND] = BG_TP_TEXT_START_ONE_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_THIRD]  = BG_TP_TEXT_START_HALF_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = BG_TP_TEXT_BATTLE_HAS_BEGUN;

    _flagSpellForceTimer = 0;
    _bothFlagsKept = false;
    _flagDebuffState = 0;
    m_FlagKeepers[TEAM_ALLIANCE].Clear();
    m_FlagKeepers[TEAM_HORDE].Clear();
    m_DroppedFlagGUID[TEAM_ALLIANCE].Clear();
    m_DroppedFlagGUID[TEAM_HORDE].Clear();
    _flagState[TEAM_ALLIANCE] = BG_TP_FLAG_STATE_ON_BASE;
    _flagState[TEAM_HORDE] = BG_TP_FLAG_STATE_ON_BASE;
    _flagsTimer[TEAM_ALLIANCE] = 0;
    _flagsTimer[TEAM_HORDE] = 0;
    _flagsDropTimer[TEAM_ALLIANCE] = 0;
    _flagsDropTimer[TEAM_HORDE] = 0;
    _lastFlagCaptureTeam = 0;
    m_ReputationCapture = 0;
    m_HonorWinKills = 0;
    m_HonorEndKills = 0;
    m_EndTimestamp  = 0;
}


BattlegroundTP::~BattlegroundTP() { }


void BattlegroundTP::PostUpdateImpl(uint32 diff)
{
    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        if (GetElapsedTime() >= 25*MINUTE*IN_MILLISECONDS)
        {
            if (GetTeamScore(TEAM_ALLIANCE) == 0)
            {
                if (GetTeamScore(TEAM_HORDE) == 0)        // No one scored - result is tie
                    EndBattleground(0);
                else                                 // Horde has more points and thus wins
                    EndBattleground(HORDE);
            }
            else if (GetTeamScore(TEAM_HORDE) == 0)
                EndBattleground(ALLIANCE);           // Alliance has > 0, Horde has 0, alliance wins
            else if (GetTeamScore(TEAM_HORDE) == GetTeamScore(TEAM_ALLIANCE)) // Team score equal, winner is team that scored the last flag
                EndBattleground(_lastFlagCaptureTeam);
            else if (GetTeamScore(TEAM_HORDE) > GetTeamScore(TEAM_ALLIANCE))  // Last but not least, check who has the higher score
                EndBattleground(HORDE);
            else
                EndBattleground(ALLIANCE);
        }

        if (_flagState[TEAM_ALLIANCE] == BG_TP_FLAG_STATE_WAIT_RESPAWN)
        {
            _flagsTimer[TEAM_ALLIANCE] -= diff;

            if (_flagsTimer[TEAM_ALLIANCE] < 0)
            {
                _flagsTimer[TEAM_ALLIANCE] = 0;
                RespawnFlag(ALLIANCE, true);
            }
        }

        if (_flagState[TEAM_ALLIANCE] == BG_TP_FLAG_STATE_ON_GROUND)
        {
            _flagsDropTimer[TEAM_ALLIANCE] -= diff;

            if (_flagsDropTimer[TEAM_ALLIANCE] < 0)
            {
                _flagsDropTimer[TEAM_ALLIANCE] = 0;
                RespawnFlagAfterDrop(ALLIANCE);
                _bothFlagsKept = false;
            }
        }

        if (_flagState[TEAM_HORDE] == BG_TP_FLAG_STATE_WAIT_RESPAWN)
        {
            _flagsTimer[TEAM_HORDE] -= diff;

            if (_flagsTimer[TEAM_HORDE] < 0)
            {
                _flagsTimer[TEAM_HORDE] = 0;
                RespawnFlag(HORDE, true);
            }
        }

        if (_flagState[TEAM_HORDE] == BG_TP_FLAG_STATE_ON_GROUND)
        {
            _flagsDropTimer[TEAM_HORDE] -= diff;

            if (_flagsDropTimer[TEAM_HORDE] < 0)
            {
                _flagsDropTimer[TEAM_HORDE] = 0;
                RespawnFlagAfterDrop(HORDE);
                _bothFlagsKept = false;
            }
        }

        if (_bothFlagsKept)
        {
            _flagSpellForceTimer += diff;
            if (_flagDebuffState == 0 && _flagSpellForceTimer >= 10*MINUTE*IN_MILLISECONDS)  //10 minutes
            {
                if (Player* player = ObjectAccessor::FindPlayer(m_FlagKeepers[0]))
                    player->CastSpell(player, TP_SPELL_FOCUSED_ASSAULT, true);
                if (Player* player = ObjectAccessor::FindPlayer(m_FlagKeepers[1]))
                    player->CastSpell(player, TP_SPELL_FOCUSED_ASSAULT, true);
                _flagDebuffState = 1;
            }
            else if (_flagDebuffState == 1 && _flagSpellForceTimer >= 15*MINUTE*IN_MILLISECONDS) //15 minutes
            {
                if (Player* player = ObjectAccessor::FindPlayer(m_FlagKeepers[0]))
                {
                    player->RemoveAurasDueToSpell(TP_SPELL_FOCUSED_ASSAULT);
                    player->CastSpell(player, TP_SPELL_BRUTAL_ASSAULT, true);
                }
                if (Player* player = ObjectAccessor::FindPlayer(m_FlagKeepers[1]))
                {
                    player->RemoveAurasDueToSpell(TP_SPELL_FOCUSED_ASSAULT);
                    player->CastSpell(player, TP_SPELL_BRUTAL_ASSAULT, true);
                }
                _flagDebuffState = 2;
            }
        }
        else
        {
            if (Player* player = ObjectAccessor::FindPlayer(m_FlagKeepers[0]))
            {
                player->RemoveAurasDueToSpell(TP_SPELL_FOCUSED_ASSAULT);
                player->RemoveAurasDueToSpell(TP_SPELL_BRUTAL_ASSAULT);
            }
            if (Player* player = ObjectAccessor::FindPlayer(m_FlagKeepers[1]))
            {
                player->RemoveAurasDueToSpell(TP_SPELL_FOCUSED_ASSAULT);
                player->RemoveAurasDueToSpell(TP_SPELL_BRUTAL_ASSAULT);
            }

            _flagSpellForceTimer = 0; //reset timer.
            _flagDebuffState = 0;
        }
    }
}

void BattlegroundTP::GetPlayerPositionData(std::vector<WorldPackets::Battleground::BattlegroundPlayerPosition>* positions) const
{
    if (Player* player = ObjectAccessor::GetPlayer(GetBgMap(), m_FlagKeepers[TEAM_ALLIANCE]))
    {
        WorldPackets::Battleground::BattlegroundPlayerPosition position;
        position.Guid = player->GetGUID();
        position.Pos = player->GetPosition();
        position.IconID = PLAYER_POSITION_ICON_ALLIANCE_FLAG;
        position.ArenaSlot = PLAYER_POSITION_ARENA_SLOT_NONE;
        positions->push_back(position);
    }

    if (Player* player = ObjectAccessor::GetPlayer(GetBgMap(), m_FlagKeepers[TEAM_HORDE]))
    {
        WorldPackets::Battleground::BattlegroundPlayerPosition position;
        position.Guid = player->GetGUID();
        position.Pos = player->GetPosition();
        position.IconID = PLAYER_POSITION_ICON_HORDE_FLAG;
        position.ArenaSlot = PLAYER_POSITION_ARENA_SLOT_NONE;
        positions->push_back(position);
    }
}

void BattlegroundTP::StartingEventCloseDoors()
{
    for (uint32 i = BG_TP_OBJECT_DOOR_A_1; i <= BG_TP_OBJECT_DOOR_H_4; ++i)
    {
        DoorClose(i);
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);
    }
    for (uint32 i = BG_TP_OBJECT_A_FLAG; i <= BG_TP_OBJECT_BERSERKBUFF_2; ++i)
        SpawnBGObject(i, RESPAWN_ONE_DAY);
}

void BattlegroundTP::StartingEventOpenDoors()
{
    DoorOpen(BG_TP_OBJECT_DOOR_A_1);
    DoorOpen(BG_TP_OBJECT_DOOR_A_2);
    DoorOpen(BG_TP_OBJECT_DOOR_A_3);
    DoorOpen(BG_TP_OBJECT_DOOR_A_4);
    DoorOpen(BG_TP_OBJECT_DOOR_H_1);
    DoorOpen(BG_TP_OBJECT_DOOR_H_2);
    DoorOpen(BG_TP_OBJECT_DOOR_H_3);
    DoorOpen(BG_TP_OBJECT_DOOR_H_4);

    for (uint32 i = BG_TP_OBJECT_A_FLAG; i <= BG_TP_OBJECT_BERSERKBUFF_2; ++i)
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);

    // players joining later are not eligible
    //StartCriteriaTimer(CRITERIA_TIMED_TYPE_EVENT, TP_EVENT_START_BATTLE);

    // Send start timer
    m_EndTimestamp = time(nullptr) + 1500;

    UpdateWorldState(BG_TP_STATE_TIMER_ACTIVE, 1);
    UpdateWorldState(BG_TP_STATE_TIMER, m_EndTimestamp);
}


void BattlegroundTP::AddPlayer(Player* player)
{
    Battleground::AddPlayer(player);
    PlayerScores[player->GetGUID()] = new BattlegroundTPScore(player->GetGUID(), player->GetBGTeam());
}


void BattlegroundTP::RespawnFlag(uint32 Team, bool captured)
{
    if (Team == ALLIANCE)
    {
        TC_LOG_DEBUG("bg.battleground", "Respawn Alliance flag");
        _flagState[TEAM_ALLIANCE] = BG_TP_FLAG_STATE_ON_BASE;
    }
    else
    {
        TC_LOG_DEBUG("bg.battleground", "Respawn Horde flag");
        _flagState[TEAM_HORDE] = BG_TP_FLAG_STATE_ON_BASE;
    }

    if (captured)
    {
        //when map_update will be allowed for battlegrounds this code will be useless
        SpawnBGObject(BG_TP_OBJECT_H_FLAG, RESPAWN_IMMEDIATELY);
        SpawnBGObject(BG_TP_OBJECT_A_FLAG, RESPAWN_IMMEDIATELY);
        SendBroadcastText(BG_TP_TEXT_FLAGS_PLACED, CHAT_MSG_BG_SYSTEM_NEUTRAL);
        PlaySoundToAll(BG_TP_SOUND_FLAGS_RESPAWNED);        // flag respawned sound...
    }
    _bothFlagsKept = false;
}


void BattlegroundTP::RespawnFlagAfterDrop(uint32 team)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    RespawnFlag(team, false);
    if (team == ALLIANCE)
        SpawnBGObject(BG_TP_OBJECT_A_FLAG, RESPAWN_IMMEDIATELY);
        SpawnBGObject(BG_TP_OBJECT_H_FLAG, RESPAWN_IMMEDIATELY);

    SendBroadcastText(BG_TP_TEXT_FLAGS_PLACED, CHAT_MSG_BG_SYSTEM_NEUTRAL);
    PlaySoundToAll(BG_TP_SOUND_FLAGS_RESPAWNED);


    if (GameObject* obj = GetBgMap()->GetGameObject(GetDroppedFlagGUID(team)))
        obj->Delete();
    else
        TC_LOG_ERROR("bg.battleground", "unknown dropped flag (%s)", GetDroppedFlagGUID(team).ToString().c_str());

    SetDroppedFlagGUID(ObjectGuid::Empty, GetTeamIndexByTeamId(team));
    _bothFlagsKept = false;
}


void BattlegroundTP::EventPlayerCapturedFlag(Player* player)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    uint32 winner = 0;

    player->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT);
    if (player->GetTeam() == ALLIANCE)
    {
        if (!IsHordeFlagPickedup())
            return;
        SetHordeFlagPicker(ObjectGuid::Empty);              // must be before aura remove to prevent 2 events (drop+capture) at the same time
                                                            // horde flag in base (but not respawned yet)
        _flagState[TEAM_HORDE] = BG_TP_FLAG_STATE_WAIT_RESPAWN;
                                                            // Drop Horde Flag from Player
        player->RemoveAurasDueToSpell(BG_TP_SPELL_WARSONG_FLAG);
        if (_flagDebuffState == 1)
          player->RemoveAurasDueToSpell(TP_SPELL_FOCUSED_ASSAULT);
        if (_flagDebuffState == 2)
          player->RemoveAurasDueToSpell(TP_SPELL_BRUTAL_ASSAULT);
        if (GetTeamScore(TEAM_ALLIANCE) < BG_TP_MAX_TEAM_SCORE)
            AddPoint(ALLIANCE, 1);
        PlaySoundToAll(BG_TP_SOUND_FLAG_CAPTURED_ALLIANCE);
        RewardReputationToTeam(1174, m_ReputationCapture, ALLIANCE);
    }
    else
    {
        if (!IsAllianceFlagPickedup())
            return;
        SetAllianceFlagPicker(ObjectGuid::Empty);           // must be before aura remove to prevent 2 events (drop+capture) at the same time
                                                            // alliance flag in base (but not respawned yet)
        _flagState[TEAM_ALLIANCE] = BG_TP_FLAG_STATE_WAIT_RESPAWN;
                                                            // Drop Alliance Flag from Player
        player->RemoveAurasDueToSpell(BG_TP_SPELL_SILVERWING_FLAG);
        if (_flagDebuffState == 1)
          player->RemoveAurasDueToSpell(TP_SPELL_FOCUSED_ASSAULT);
        if (_flagDebuffState == 2)
          player->RemoveAurasDueToSpell(TP_SPELL_BRUTAL_ASSAULT);
        if (GetTeamScore(TEAM_HORDE) < BG_TP_MAX_TEAM_SCORE)
            AddPoint(HORDE, 1);
        PlaySoundToAll(BG_TP_SOUND_FLAG_CAPTURED_HORDE);
        RewardReputationToTeam(1172, m_ReputationCapture, HORDE);
    }
    //for flag capture is reward 2 honorable kills
    RewardHonorToTeam(GetBonusHonorFromKill(2), player->GetTeam());

    SpawnBGObject(BG_TP_OBJECT_H_FLAG, BG_TP_FLAG_RESPAWN_TIME);
    SpawnBGObject(BG_TP_OBJECT_A_FLAG, BG_TP_FLAG_RESPAWN_TIME);

    if (player->GetTeam() == ALLIANCE)
        SendBroadcastText(BG_TP_TEXT_CAPTURED_HORDE_FLAG, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
    else
        SendBroadcastText(BG_TP_TEXT_CAPTURED_ALLIANCE_FLAG, CHAT_MSG_BG_SYSTEM_HORDE, player);

    UpdateFlagState(player->GetTeam(), 1);                  // flag state none
    UpdateTeamScore(player->GetTeamId());

    // only flag capture should be updated
    UpdatePlayerScore(player, SCORE_FLAG_CAPTURES, 1);      // +1 flag captures

    // update last flag capture to be used if teamscore is equal
    SetLastFlagCapture(player->GetTeam());

    if (GetTeamScore(TEAM_ALLIANCE) == BG_TP_MAX_TEAM_SCORE)
        winner = ALLIANCE;

    if (GetTeamScore(TEAM_HORDE) == BG_TP_MAX_TEAM_SCORE)
        winner = HORDE;

    if (winner)
    {
        UpdateWorldState(BG_TP_FLAG_UNK_ALLIANCE, 0);
        UpdateWorldState(BG_TP_FLAG_UNK_HORDE, 0);
        UpdateWorldState(BG_TP_FLAG_STATE_ALLIANCE, 1);
        UpdateWorldState(BG_TP_FLAG_STATE_HORDE, 1);
        UpdateWorldState(BG_TP_STATE_TIMER_ACTIVE, 0);

        RewardHonorToTeam(BG_TP_Honor[m_HonorMode][BG_TP_WIN], winner);
        EndBattleground(winner);
    }
    else
    {
        _flagsTimer[GetTeamIndexByTeamId(player->GetTeam()) ? 0 : 1] = BG_TP_FLAG_RESPAWN_TIME;
    }
}


void BattlegroundTP::EventPlayerDroppedFlag(Player* player)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
    {
        // if not running, do not cast things at the dropper player (prevent spawning the "dropped" flag), neither send unnecessary messages
        // just take off the aura
        if (player->GetTeam() == ALLIANCE)
        {
            if (!IsHordeFlagPickedup())
                return;
            if (GetFlagPickerGUID(TEAM_HORDE) == player->GetGUID())
            {
                SetHordeFlagPicker(ObjectGuid::Empty);
                player->RemoveAurasDueToSpell(BG_TP_SPELL_WARSONG_FLAG);
            }
        }
        else
        {
            if (!IsAllianceFlagPickedup())
                return;
            if (GetFlagPickerGUID(TEAM_ALLIANCE) == player->GetGUID())
            {
                SetAllianceFlagPicker(ObjectGuid::Empty);
                player->RemoveAurasDueToSpell(BG_TP_SPELL_SILVERWING_FLAG);
            }
        }
        return;
    }

    bool set = false;


    if (player->GetTeam() == ALLIANCE)
    {
        if (!IsHordeFlagPickedup())
            return;
        if (GetFlagPickerGUID(TEAM_HORDE) == player->GetGUID())
        {
            SetHordeFlagPicker(ObjectGuid::Empty);
            player->RemoveAurasDueToSpell(BG_TP_SPELL_WARSONG_FLAG);
            if (_flagDebuffState == 1)
              player->RemoveAurasDueToSpell(TP_SPELL_FOCUSED_ASSAULT);
            else if (_flagDebuffState == 2)
              player->RemoveAurasDueToSpell(TP_SPELL_BRUTAL_ASSAULT);
            _flagState[TEAM_HORDE] = BG_TP_FLAG_STATE_ON_GROUND;
            player->CastSpell(player, BG_TP_SPELL_WARSONG_FLAG_DROPPED, true);
            set = true;
        }
    }
    else
    {
        if (!IsAllianceFlagPickedup())
            return;
        if (GetFlagPickerGUID(TEAM_ALLIANCE) == player->GetGUID())
        {
            SetAllianceFlagPicker(ObjectGuid::Empty);
            player->RemoveAurasDueToSpell(BG_TP_SPELL_SILVERWING_FLAG);
            if (_flagDebuffState == 1)
              player->RemoveAurasDueToSpell(TP_SPELL_FOCUSED_ASSAULT);
            else if (_flagDebuffState == 2)
              player->RemoveAurasDueToSpell(TP_SPELL_BRUTAL_ASSAULT);
            _flagState[TEAM_ALLIANCE] = BG_TP_FLAG_STATE_ON_GROUND;
            player->CastSpell(player, BG_TP_SPELL_SILVERWING_FLAG_DROPPED, true);
            set = true;
        }
    }

    if (set)
    {
        player->CastSpell(player, SPELL_RECENTLY_DROPPED_FLAG, true);
        UpdateFlagState(player->GetTeam(), 1);

        if (player->GetTeam() == ALLIANCE)
        {
            SendBroadcastText(BG_TP_TEXT_HORDE_FLAG_DROPPED, CHAT_MSG_BG_SYSTEM_HORDE, player);
            UpdateWorldState(BG_TP_FLAG_UNK_HORDE, uint32(-1));
        }
        else
        {
            SendBroadcastText(BG_TP_TEXT_ALLIANCE_FLAG_DROPPED, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
            UpdateWorldState(BG_TP_FLAG_UNK_ALLIANCE, uint32(-1));
        }

        _flagsDropTimer[GetTeamIndexByTeamId(player->GetTeam()) ? 0 : 1] = BG_TP_FLAG_DROP_TIME;
    }
}

void BattlegroundTP::EventPlayerClickedOnFlag(Player* player, GameObject* target_obj)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    //alliance flag picked up from base
    if (player->GetTeam() == HORDE && GetFlagState(ALLIANCE) == BG_TP_FLAG_STATE_ON_BASE
        && BgObjects[BG_TP_OBJECT_A_FLAG] == target_obj->GetGUID())
    {
        SendBroadcastText(BG_TP_TEXT_ALLIANCE_FLAG_PICKED_UP, CHAT_MSG_BG_SYSTEM_HORDE, player);
        PlaySoundToAll(BG_TP_SOUND_ALLIANCE_FLAG_PICKED_UP);
        SpawnBGObject(BG_TP_OBJECT_A_FLAG, RESPAWN_ONE_DAY);
        SetAllianceFlagPicker(player->GetGUID());
        _flagState[TEAM_ALLIANCE] = BG_TP_FLAG_STATE_ON_PLAYER;
        //update world state to show correct flag carrier
        UpdateFlagState(HORDE, BG_TP_FLAG_STATE_ON_PLAYER);
        UpdateWorldState(BG_TP_FLAG_UNK_ALLIANCE, 1);
        player->CastSpell(player, BG_TP_SPELL_SILVERWING_FLAG, true);
        player->StartCriteriaTimer(CRITERIA_TIMED_TYPE_SPELL_TARGET, BG_TP_SPELL_SILVERWING_FLAG_PICKED);
        if (_flagState[1] == BG_TP_FLAG_STATE_ON_PLAYER)
          _bothFlagsKept = true;
    }

    //horde flag picked up from base
    if (player->GetTeam() == ALLIANCE && GetFlagState(HORDE) == BG_TP_FLAG_STATE_ON_BASE
        && BgObjects[BG_TP_OBJECT_H_FLAG] == target_obj->GetGUID())
    {
        SendBroadcastText(BG_TP_TEXT_HORDE_FLAG_PICKED_UP, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
        PlaySoundToAll(BG_TP_SOUND_HORDE_FLAG_PICKED_UP);
        SpawnBGObject(BG_TP_OBJECT_H_FLAG, RESPAWN_ONE_DAY);
        SetHordeFlagPicker(player->GetGUID());
        _flagState[TEAM_HORDE] = BG_TP_FLAG_STATE_ON_PLAYER;
        //update world state to show correct flPag carrier
        UpdateFlagState(ALLIANCE, BG_TP_FLAG_STATE_ON_PLAYER);
        UpdateWorldState(BG_TP_FLAG_UNK_HORDE, 1);
        player->CastSpell(player, BG_TP_SPELL_WARSONG_FLAG, true);
        player->StartCriteriaTimer(CRITERIA_TIMED_TYPE_SPELL_TARGET, BG_TP_SPELL_WARSONG_FLAG_PICKED);
        if (_flagState[0] == BG_TP_FLAG_STATE_ON_PLAYER)
          _bothFlagsKept = true;
    }

    //Alliance flag on ground(not in base) (returned or picked up again from ground!)
    if (GetFlagState(ALLIANCE) == BG_TP_FLAG_STATE_ON_GROUND && player->IsWithinDistInMap(target_obj, 10)
        && target_obj->GetGOInfo()->entry == BG_OBJECT_A_FLAG_GROUND_TP_ENTRY)
    {
        if (player->GetTeam() == ALLIANCE)
        {
            SendBroadcastText(BG_TP_TEXT_ALLIANCE_FLAG_RETURNED, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
            UpdateFlagState(HORDE, BG_TP_FLAG_STATE_WAIT_RESPAWN);
            RespawnFlag(ALLIANCE, false);
            SpawnBGObject(BG_TP_OBJECT_A_FLAG, RESPAWN_IMMEDIATELY);
            PlaySoundToAll(BG_TP_SOUND_FLAG_RETURNED);
            UpdatePlayerScore(player, SCORE_FLAG_RETURNS, 1);
            _bothFlagsKept = false;
        }
        else
        {
            SendBroadcastText(BG_TP_TEXT_ALLIANCE_FLAG_PICKED_UP, CHAT_MSG_BG_SYSTEM_HORDE, player);
            PlaySoundToAll(BG_TP_SOUND_ALLIANCE_FLAG_PICKED_UP);
            SpawnBGObject(BG_TP_OBJECT_A_FLAG, RESPAWN_ONE_DAY);
            SetAllianceFlagPicker(player->GetGUID());
            player->CastSpell(player, BG_TP_SPELL_SILVERWING_FLAG, true);
            _flagState[TEAM_ALLIANCE] = BG_TP_FLAG_STATE_ON_PLAYER;
            UpdateFlagState(HORDE, BG_TP_FLAG_STATE_ON_PLAYER);
            if (_flagDebuffState == 1)
              player->CastSpell(player, TP_SPELL_FOCUSED_ASSAULT, true);
            else if (_flagDebuffState == 2)
              player->CastSpell(player, TP_SPELL_BRUTAL_ASSAULT, true);
            UpdateWorldState(BG_TP_FLAG_UNK_ALLIANCE, 1);
        }
        //called in HandleGameObjectUseOpcode:
        //target_obj->Delete();
    }

    //Horde flag on ground(not in base) (returned or picked up again)
    if (GetFlagState(HORDE) == BG_TP_FLAG_STATE_ON_GROUND && player->IsWithinDistInMap(target_obj, 10)
        && target_obj->GetGOInfo()->entry == BG_OBJECT_H_FLAG_GROUND_TP_ENTRY)
    {
        if (player->GetTeam() == HORDE)
        {
            SendBroadcastText(BG_TP_TEXT_HORDE_FLAG_RETURNED, CHAT_MSG_BG_SYSTEM_HORDE, player);
            UpdateFlagState(ALLIANCE, BG_TP_FLAG_STATE_WAIT_RESPAWN);
            RespawnFlag(HORDE, false);
            SpawnBGObject(BG_TP_OBJECT_H_FLAG, RESPAWN_IMMEDIATELY);
            PlaySoundToAll(BG_TP_SOUND_FLAG_RETURNED);
            UpdatePlayerScore(player, SCORE_FLAG_RETURNS, 1);
            _bothFlagsKept = false;
        }
        else
        {
            SendBroadcastText(BG_TP_TEXT_HORDE_FLAG_PICKED_UP, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
            PlaySoundToAll(BG_TP_SOUND_HORDE_FLAG_PICKED_UP);
            SpawnBGObject(BG_TP_OBJECT_H_FLAG, RESPAWN_ONE_DAY);
            SetHordeFlagPicker(player->GetGUID());
            player->CastSpell(player, BG_TP_SPELL_WARSONG_FLAG, true);
            _flagState[TEAM_HORDE] = BG_TP_FLAG_STATE_ON_PLAYER;
            UpdateFlagState(ALLIANCE, BG_TP_FLAG_STATE_ON_PLAYER);
            if (_flagDebuffState == 1)
              player->CastSpell(player, TP_SPELL_FOCUSED_ASSAULT, true);
            else if (_flagDebuffState == 2)
              player->CastSpell(player, TP_SPELL_BRUTAL_ASSAULT, true);
            UpdateWorldState(BG_TP_FLAG_UNK_HORDE, 1);
        }
        //called in HandleGameObjectUseOpcode:
        //target_obj->Delete();
    }

    player->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT);
}

void BattlegroundTP::RemovePlayer(Player* player, ObjectGuid guid, uint32 /*team*/)
{
    // sometimes flag aura not removed :(
    if (IsAllianceFlagPickedup() && m_FlagKeepers[TEAM_ALLIANCE] == guid)
    {
        if (!player)
        {
            TC_LOG_ERROR("bg.battleground", "BattlegroundTP: Removing offline player who has the FLAG!!");
            SetAllianceFlagPicker(ObjectGuid::Empty);
            RespawnFlag(ALLIANCE, false);
        }
        else
            EventPlayerDroppedFlag(player);
    }
    if (IsHordeFlagPickedup() && m_FlagKeepers[TEAM_HORDE] == guid)
    {
        if (!player)
        {
            TC_LOG_ERROR("bg.battleground", "BattlegroundTP: Removing offline player who has the FLAG!!");
            SetHordeFlagPicker(ObjectGuid::Empty);
            RespawnFlag(HORDE, false);
        }
        else
            EventPlayerDroppedFlag(player);
    }
}

void BattlegroundTP::UpdateFlagState(uint32 team, uint32 value)
{
    if (team == ALLIANCE)
        UpdateWorldState(BG_TP_FLAG_STATE_ALLIANCE, value);
    else
        UpdateWorldState(BG_TP_FLAG_STATE_HORDE, value);
}

void BattlegroundTP::UpdateTeamScore(uint32 team)
{
    if (team == TEAM_ALLIANCE)
        UpdateWorldState(BG_TP_FLAG_CAPTURES_ALLIANCE, GetTeamScore(team));
    else
        UpdateWorldState(BG_TP_FLAG_CAPTURES_HORDE, GetTeamScore(team));
}

void BattlegroundTP::HandleAreaTrigger(Player* player, uint32 trigger, bool entered)
{
    //uint32 SpellId = 0;
    //uint64 buff_guid = 0;
    switch (trigger)
    {
        case 5904:                                          // Alliance Flag spawn
            if (_flagState[TEAM_HORDE] && !_flagState[TEAM_ALLIANCE])
                if (GetFlagPickerGUID(TEAM_HORDE) == player->GetGUID())
                    EventPlayerCapturedFlag(player);
            break;
        case 5905:                                          // Horde Flag spawn
            if (_flagState[TEAM_ALLIANCE] && !_flagState[TEAM_HORDE])
                if (GetFlagPickerGUID(TEAM_ALLIANCE) == player->GetGUID())
                    EventPlayerCapturedFlag(player);
            break;
        case 5908:                                          // Horde Tower
        case 5909:                                          // Twin Peak House big
        case 5910:                                          // Horde House
        case 5911:                                          // Twin Peak House small
        case 5914:                                          // Alliance Start right
        case 5916:                                          // Alliance Start
        case 5917:                                          // Alliance Start left
        case 5918:                                          // Horde Start
        case 5920:                                          // Horde Start Front entrance
        case 5921:                                          // Horde Start left Water channel
            break;
        default:
            Battleground::HandleAreaTrigger(player, trigger, entered);
            break;
    }

    //if (buff_guid)
    //    HandleTriggerBuff(buff_guid, Source);
}


bool BattlegroundTP::SetupBattleground()
{
    // flags X Y Z Orientation Rotation2 Rotation3
    if (!AddObject(BG_TP_OBJECT_A_FLAG, BG_OBJECT_A_FLAG_TP_ENTRY, 2118.210f, 191.621f, 44.052f, 5.741259f, 0, 0, 0.9996573f, 0.02617699f, BG_TP_FLAG_RESPAWN_TIME/1000)
        || !AddObject(BG_TP_OBJECT_H_FLAG, BG_OBJECT_H_FLAG_TP_ENTRY, 1578.380f, 344.037f, 2.419f, 3.055978f, 0, 0, 0.008726535f, 0.9999619f, BG_TP_FLAG_RESPAWN_TIME/1000)
        // buffs
        || !AddObject(BG_TP_OBJECT_SPEEDBUFF_1, BG_OBJECTID_SPEEDBUFF_ENTRY, 1545.402f, 304.028f, 0.5923f, -1.64061f, 0, 0, 0.7313537f, -0.6819983f, BUFF_RESPAWN_TIME)
        || !AddObject(BG_TP_OBJECT_SPEEDBUFF_2, BG_OBJECTID_SPEEDBUFF_ENTRY, 2171.279f, 222.334f, 43.8001f, 2.663309f, 0, 0, 0.7313537f, 0.6819984f, BUFF_RESPAWN_TIME)
        || !AddObject(BG_TP_OBJECT_REGENBUFF_1, BG_OBJECTID_REGENBUFF_ENTRY, 1753.957f, 242.092f, -14.1170f, 1.105848f, 0, 0, 0.1305263f, -0.9914448f, BUFF_RESPAWN_TIME)
        || !AddObject(BG_TP_OBJECT_REGENBUFF_2, BG_OBJECTID_REGENBUFF_ENTRY, 1952.121f, 383.857f, -10.2870f, 4.192612f, 0, 0, 0.333807f, -0.9426414f, BUFF_RESPAWN_TIME)
        || !AddObject(BG_TP_OBJECT_BERSERKBUFF_1, BG_OBJECTID_BERSERKERBUFF_ENTRY, 1934.369f, 226.064f, -17.0441f, 2.499154f, 0, 0, 0.5591929f, 0.8290376f, BUFF_RESPAWN_TIME)
        || !AddObject(BG_TP_OBJECT_BERSERKBUFF_2, BG_OBJECTID_BERSERKERBUFF_ENTRY, 1725.240f, 446.431f, -7.8327f, 5.709677f, 0, 0, 0.9396926f, -0.3420201f, BUFF_RESPAWN_TIME)
        // alliance gates
        || !AddObject(BG_TP_OBJECT_DOOR_A_1, BG_OBJECT_DOOR_A_1_TP_ENTRY, 2115.399f, 150.175f, 43.526f, 2.544690f, 0, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_TP_OBJECT_DOOR_A_2, BG_OBJECT_DOOR_A_2_TP_ENTRY, 2156.803f, 220.331f, 43.482f, 2.544690f, 0, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_TP_OBJECT_DOOR_A_3, BG_OBJECT_DOOR_A_3_TP_ENTRY, 2127.512f, 223.711f, 43.640f, 2.544690f, 0, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_TP_OBJECT_DOOR_A_4, BG_OBJECT_DOOR_A_4_TP_ENTRY, 2096.102f, 166.920f, 54.230f, 2.544690f, 0, 0, 0, 0, RESPAWN_IMMEDIATELY)
        // horde gates
        || !AddObject(BG_TP_OBJECT_DOOR_H_1, BG_OBJECT_DOOR_H_1_TP_ENTRY, 1556.595f, 314.502f, 1.2230f, 6.179126f, 0, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_TP_OBJECT_DOOR_H_2, BG_OBJECT_DOOR_H_2_TP_ENTRY, 1587.093f, 319.853f, 1.5233f, 6.179126f, 0, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_TP_OBJECT_DOOR_H_3, BG_OBJECT_DOOR_H_3_TP_ENTRY, 1591.463f, 365.732f, 13.494f, 6.179126f, 0, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_TP_OBJECT_DOOR_H_4, BG_OBJECT_DOOR_H_4_TP_ENTRY, 1558.315f, 372.709f, 1.4840f, 6.179126f, 0, 0, 0, 0, RESPAWN_IMMEDIATELY)
       )
    {
        TC_LOG_ERROR("sql.sql", "BatteGroundTP: Failed to spawn some objects Battleground not created!");
        return false;
    }

    WorldSafeLocsEntry const *sg = sWorldSafeLocsStore.LookupEntry(TP_GRAVEYARD_MIDDLE_ALLIANCE);
    if (!sg || !AddSpiritGuide(TP_SPIRIT_ALLIANCE, sg->Loc.X, sg->Loc.Y, sg->Loc.Z, 3.641396f, TEAM_ALLIANCE))
    {
        TC_LOG_ERROR("sql.sql", "BatteGroundTP: Failed to spawn Alliance spirit guides! Battleground not created!");
        return false;
    }


    sg = sWorldSafeLocsStore.LookupEntry(TP_GRAVEYARD_START_ALLIANCE);
    if (!sg || !AddSpiritGuide(TP_SPIRIT_ALLIANCE, sg->Loc.X, sg->Loc.Y, sg->Loc.Z, 3.641396f, TEAM_ALLIANCE))
    {
        TC_LOG_ERROR("sql.sql", "BatteGroundTP: Failed to spawn Alliance start spirit guides! Battleground not created!");
        return false;
    }


    sg = sWorldSafeLocsStore.LookupEntry(TP_GRAVEYARD_MIDDLE_HORDE);
    if (!sg || !AddSpiritGuide(TP_SPIRIT_HORDE, sg->Loc.X, sg->Loc.Y, sg->Loc.Z, 3.641396f, TEAM_HORDE))
    {
        TC_LOG_ERROR("sql.sql", "BatteGroundTP: Failed to spawn Horde spirit guides! Battleground not created!");
        return false;
    }
    sg = sWorldSafeLocsStore.LookupEntry(TP_GRAVEYARD_START_HORDE);
    if (!sg || !AddSpiritGuide(TP_SPIRIT_ALLIANCE, sg->Loc.X, sg->Loc.Y, sg->Loc.Z, 3.641396f, TEAM_HORDE))
    {
        TC_LOG_ERROR("sql.sql", "BatteGroundTP: Failed to spawn Horde start spirit guide! Battleground not created!");
        return false;
    }


    TC_LOG_DEBUG("bg.battleground", "BatteGroundTP: BG objects and spirit guides spawned");


    return true;
}


void BattlegroundTP::Reset()
{
    //call parent's class reset
    Battleground::Reset();

    m_FlagKeepers[TEAM_ALLIANCE].Clear();
    m_FlagKeepers[TEAM_HORDE].Clear();
    m_DroppedFlagGUID[TEAM_ALLIANCE].Clear();
    m_DroppedFlagGUID[TEAM_HORDE].Clear();
    _flagState[TEAM_ALLIANCE]        = BG_TP_FLAG_STATE_ON_BASE;
    _flagState[TEAM_HORDE]           = BG_TP_FLAG_STATE_ON_BASE;
    m_TeamScores[TEAM_ALLIANCE]      = 0;
    m_TeamScores[TEAM_HORDE]         = 0;

    if (sBattlegroundMgr->IsBGWeekend(GetTypeID()))
    {
        m_ReputationCapture = 45;
        m_HonorWinKills = 3;
        m_HonorEndKills = 4;
    }
    else
    {
        m_ReputationCapture = 35;
        m_HonorWinKills = 1;
        m_HonorEndKills = 2;
    }
    _lastFlagCaptureTeam             = 0;
    _bothFlagsKept                   = false;
    _flagDebuffState                 = 0;
    _flagSpellForceTimer             = 0;
    _flagsDropTimer[TEAM_ALLIANCE]   = 0;
    _flagsDropTimer[TEAM_HORDE]      = 0;
    _flagsTimer[TEAM_ALLIANCE]       = 0;
    _flagsTimer[TEAM_HORDE]          = 0;
}

void BattlegroundTP::EndBattleground(uint32 winner)
{
    // win reward
    if (winner == ALLIANCE)
        RewardHonorToTeam(GetBonusHonorFromKill(m_HonorWinKills), ALLIANCE);
    if (winner == HORDE)
        RewardHonorToTeam(GetBonusHonorFromKill(m_HonorWinKills), HORDE);
    // complete map_end rewards (even if no team wins)
    RewardHonorToTeam(GetBonusHonorFromKill(m_HonorEndKills), ALLIANCE);
    RewardHonorToTeam(GetBonusHonorFromKill(m_HonorEndKills), HORDE);

    Battleground::EndBattleground(winner);
}

void BattlegroundTP::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    EventPlayerDroppedFlag(player);

    Battleground::HandleKillPlayer(player, killer);
}


bool BattlegroundTP::UpdatePlayerScore(Player* player, uint32 type, uint32 value, bool doAddHonor)
{
    if (!Battleground::UpdatePlayerScore(player, type, value, doAddHonor))
        return false;

    switch (type)
    {
        case SCORE_FLAG_CAPTURES:                           // flags captured
            player->UpdateCriteria(CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, TP_OBJECTIVE_CAPTURE_FLAG);
            break;
        case SCORE_FLAG_RETURNS:                            // flags returned
            player->UpdateCriteria(CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, TP_OBJECTIVE_RETURN_FLAG);
            break;
        default:
            break;
    }
    return true;
}


WorldSafeLocsEntry const* BattlegroundTP::GetClosestGraveYard(Player* player)
{
    // if status in progress, it returns main or start graveyards with spiritguides
    // else it will return the graveyard in the flagroom - this is especially good
    // if a player dies in preparation phase - then the player can't cheat
    // and teleport to the graveyard outside the flagroom
    // and start running around, while the doors are still closed
    if (player->GetTeam() == ALLIANCE)
    {
        if (GetStatus() == STATUS_IN_PROGRESS)
            return sWorldSafeLocsStore.LookupEntry(TP_GRAVEYARD_MIDDLE_ALLIANCE);
        else
            return sWorldSafeLocsStore.LookupEntry(TP_GRAVEYARD_FLAGROOM_ALLIANCE);
    }
    else
    {
        if (GetStatus() == STATUS_IN_PROGRESS)
            return sWorldSafeLocsStore.LookupEntry(TP_GRAVEYARD_MIDDLE_HORDE);
        else
            return sWorldSafeLocsStore.LookupEntry(TP_GRAVEYARD_FLAGROOM_HORDE);
    }
}

/*WorldSafeLocsEntry const* BattlegroundTP::GetExploitTeleportLocation(Team team)
{
    return sWorldSafeLocsStore.LookupEntry(team == ALLIANCE ? TP_EXPLOIT_TELEPORT_LOCATION_ALLIANCE : TP_EXPLOIT_TELEPORT_LOCATION_HORDE);
}*/

void BattlegroundTP::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(uint32(BG_TP_FLAG_CAPTURES_ALLIANCE), int32(GetTeamScore(TEAM_ALLIANCE)));
    packet.Worldstates.emplace_back(uint32(BG_TP_FLAG_CAPTURES_HORDE), int32(GetTeamScore(TEAM_HORDE)));

    if (_flagState[TEAM_ALLIANCE] == BG_TP_FLAG_STATE_ON_GROUND)
        packet.Worldstates.emplace_back(uint32(BG_TP_FLAG_UNK_ALLIANCE), -1);
    else if (_flagState[TEAM_ALLIANCE] == BG_TP_FLAG_STATE_ON_PLAYER)
        packet.Worldstates.emplace_back(uint32(BG_TP_FLAG_UNK_ALLIANCE), 1);
    else
        packet.Worldstates.emplace_back(uint32(BG_TP_FLAG_UNK_ALLIANCE), 0);

    if (_flagState[TEAM_HORDE] == BG_TP_FLAG_STATE_ON_GROUND)
        packet.Worldstates.emplace_back(uint32(BG_TP_FLAG_UNK_HORDE), -1);
    else if (_flagState[TEAM_HORDE] == BG_TP_FLAG_STATE_ON_PLAYER)
        packet.Worldstates.emplace_back(uint32(BG_TP_FLAG_UNK_HORDE), 1);
    else
        packet.Worldstates.emplace_back(uint32(BG_TP_FLAG_UNK_HORDE), 0);

    packet.Worldstates.emplace_back(uint32(BG_TP_FLAG_CAPTURES_MAX), int32(BG_TP_MAX_TEAM_SCORE));

    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        packet.Worldstates.emplace_back(uint32(BG_TP_STATE_TIMER_ACTIVE), 1);
        packet.Worldstates.emplace_back(uint32(BG_TP_STATE_TIMER), int32(m_EndTimestamp));
    }
    else
        packet.Worldstates.emplace_back(uint32(BG_TP_STATE_TIMER_ACTIVE), 0);

    if (_flagState[TEAM_HORDE] == BG_TP_FLAG_STATE_ON_PLAYER)
        packet.Worldstates.emplace_back(uint32(BG_TP_FLAG_STATE_HORDE), 2);
    else
        packet.Worldstates.emplace_back(uint32(BG_TP_FLAG_STATE_HORDE), 1);

    if (_flagState[TEAM_ALLIANCE] == BG_TP_FLAG_STATE_ON_PLAYER)
        packet.Worldstates.emplace_back(uint32(BG_TP_FLAG_STATE_ALLIANCE), 2);
    else
        packet.Worldstates.emplace_back(uint32(BG_TP_FLAG_STATE_ALLIANCE), 1);
}


uint32 BattlegroundTP::GetPrematureWinner()
{
    if (GetTeamScore(TEAM_ALLIANCE) > GetTeamScore(TEAM_HORDE))
        return ALLIANCE;
    else if (GetTeamScore(TEAM_HORDE) > GetTeamScore(TEAM_ALLIANCE))
        return HORDE;


    return Battleground::GetPrematureWinner();
}

bool BattlegroundTP::CheckAchievementCriteriaMeet(uint32 criteriaId, Player const* player, Unit const* target, uint32 miscValue)
{
    switch (criteriaId)
    {
        case BG_CRITERIA_CHECK_SAVE_THE_DAY:
            if (target)
                if (Player const* playerTarget = target->ToPlayer())
                    return GetFlagState(playerTarget->GetTeam()) == BG_TP_FLAG_STATE_ON_BASE;
            return false;
    }

    return Battleground::CheckAchievementCriteriaMeet(criteriaId, player, target, miscValue);
}
