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

#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "BattlegroundPackets.h"
#include "BattlegroundScore.h"
#include "ChatTextBuilder.h"
#include "Creature.h"
#include "CreatureTextMgr.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Formulas.h"
#include "GameEventSender.h"
#include "GameTime.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "KillRewarder.h"
#include "Language.h"
#include "Log.h"
#include "Map.h"
#include "MapUtils.h"
#include "MiscPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "SpellAuras.h"
#include "TemporarySummon.h"
#include "Transport.h"
#include "Util.h"
#include "WorldStateMgr.h"
#include <cstdarg>

template<class Do>
void Battleground::BroadcastWorker(Do& _do)
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        if (Player* player = _GetPlayer(itr, "BroadcastWorker"))
            _do(player);
}

Battleground::Battleground(BattlegroundTemplate const* battlegroundTemplate) : _battlegroundTemplate(battlegroundTemplate), _pvpDifficultyEntry(nullptr), _pvpStatIds(nullptr)
{
    ASSERT(_battlegroundTemplate, "Nonexisting Battleground Template passed to battleground ctor!");

    m_InstanceID        = 0;
    m_Status            = STATUS_NONE;
    m_ClientInstanceID  = 0;
    m_EndTime           = 0;
    m_InvitedAlliance   = 0;
    m_InvitedHorde      = 0;
    m_ArenaType         = 0;
    _winnerTeamId       = PVP_TEAM_NEUTRAL;
    m_StartTime         = 0;
    m_CountdownTimer    = 0;
    m_ResetStatTimer    = 0;
    m_ValidStartPositionTimer = 0;
    m_Events            = 0;
    m_StartDelayTime    = 0;
    m_IsRated           = false;
    m_InBGFreeSlotQueue = false;
    m_SetDeleteThis     = false;

    m_Map               = nullptr;

    m_ArenaTeamIds[TEAM_ALLIANCE]   = 0;
    m_ArenaTeamIds[TEAM_HORDE]      = 0;

    m_ArenaTeamMMR[TEAM_ALLIANCE]   = 0;
    m_ArenaTeamMMR[TEAM_HORDE]      = 0;

    m_BgRaids[TEAM_ALLIANCE]         = nullptr;
    m_BgRaids[TEAM_HORDE]            = nullptr;

    m_PlayersCount[TEAM_ALLIANCE]    = 0;
    m_PlayersCount[TEAM_HORDE]       = 0;

    m_TeamScores[TEAM_ALLIANCE]      = 0;
    m_TeamScores[TEAM_HORDE]         = 0;

    m_PrematureCountDown = false;
    m_PrematureCountDownTimer = 0;

    m_LastPlayerPositionBroadcast = 0;

    StartDelayTimes[BG_STARTING_EVENT_FIRST]  = BG_START_DELAY_2M;
    StartDelayTimes[BG_STARTING_EVENT_SECOND] = BG_START_DELAY_1M;
    StartDelayTimes[BG_STARTING_EVENT_THIRD]  = BG_START_DELAY_30S;
    StartDelayTimes[BG_STARTING_EVENT_FOURTH] = BG_START_DELAY_NONE;

    StartMessageIds[BG_STARTING_EVENT_FIRST]  = BG_TEXT_START_TWO_MINUTES;
    StartMessageIds[BG_STARTING_EVENT_SECOND] = BG_TEXT_START_ONE_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_THIRD]  = BG_TEXT_START_HALF_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = BG_TEXT_BATTLE_HAS_BEGUN;
}

Battleground::Battleground(Battleground const&) = default;

Battleground::~Battleground()
{
    // remove objects and creatures
    // (this is done automatically in mapmanager update, when the instance is reset after the reset time)
    uint32 size = uint32(BgCreatures.size());
    for (uint32 i = 0; i < size; ++i)
        DelCreature(i);

    size = uint32(BgObjects.size());
    for (uint32 i = 0; i < size; ++i)
        DelObject(i);

    sBattlegroundMgr->RemoveBattleground(GetTypeID(), GetInstanceID());
    // unload map
    if (m_Map)
    {
        m_Map->UnloadAll(); // unload all objects (they may hold a reference to bg in their ZoneScript pointer)
        m_Map->SetUnload(); // mark for deletion by MapManager

        //unlink to prevent crash, always unlink all pointer reference before destruction
        m_Map->SetBG(nullptr);
        m_Map = nullptr;
    }
    // remove from bg free slot queue
    RemoveFromBGFreeSlotQueue();

    for (BattlegroundScoreMap::const_iterator itr = PlayerScores.begin(); itr != PlayerScores.end(); ++itr)
        delete itr->second;

    _playerPositions.clear();
}

void Battleground::Update(uint32 diff)
{
    if (!PreUpdateImpl(diff))
        return;

    if (!GetPlayersSize())
    {
        //BG is empty
        // if there are no players invited, delete BG
        // this will delete arena or bg object, where any player entered
        // [[   but if you use battleground object again (more battles possible to be played on 1 instance)
        //      then this condition should be removed and code:
        //      if (!GetInvitedCount(HORDE) && !GetInvitedCount(ALLIANCE))
        //          AddToFreeBGObjectsQueue(); // not yet implemented
        //      should be used instead of current
        // ]]
        // Battleground Template instance cannot be updated, because it would be deleted
        if (!GetInvitedCount(HORDE) && !GetInvitedCount(ALLIANCE))
            m_SetDeleteThis = true;
        return;
    }

    switch (GetStatus())
    {
        case STATUS_WAIT_JOIN:
            if (GetPlayersSize())
            {
                _ProcessJoin(diff);
                _CheckSafePositions(diff);
            }
            break;
        case STATUS_IN_PROGRESS:
            _ProcessOfflineQueue();
            _ProcessPlayerPositionBroadcast(diff);
            // after 47 minutes without one team losing, the arena closes with no winner and no rating change
            if (isArena())
            {
                if (GetElapsedTime() >= 47 * MINUTE*IN_MILLISECONDS)
                {
                    EndBattleground(TEAM_OTHER);
                    return;
                }
            }
            else
            {
                if (sBattlegroundMgr->GetPrematureFinishTime() && (GetPlayersCountByTeam(ALLIANCE) < GetMinPlayersPerTeam() || GetPlayersCountByTeam(HORDE) < GetMinPlayersPerTeam()))
                    _ProcessProgress(diff);
                else if (m_PrematureCountDown)
                    m_PrematureCountDown = false;
            }
            break;
        case STATUS_WAIT_LEAVE:
            _ProcessLeave(diff);
            break;
        default:
            break;
    }

    // Update start time and reset stats timer
    SetElapsedTime(GetElapsedTime() + diff);
    if (GetStatus() == STATUS_WAIT_JOIN)
    {
        m_ResetStatTimer += diff;
        m_CountdownTimer += diff;
    }

    PostUpdateImpl(diff);
}

inline void Battleground::_CheckSafePositions(uint32 diff)
{
    float maxDist = GetStartMaxDist();
    if (!maxDist)
        return;

    m_ValidStartPositionTimer += diff;
    if (m_ValidStartPositionTimer >= CHECK_PLAYER_POSITION_INVERVAL)
    {
        m_ValidStartPositionTimer = 0;

        for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
        {
            if (Player* player = ObjectAccessor::FindPlayer(itr->first))
            {
                if (player->IsGameMaster())
                    continue;

                Position pos = player->GetPosition();
                WorldSafeLocsEntry const* startPos = GetTeamStartPosition(Battleground::GetTeamIndexByTeamId(player->GetBGTeam()));
                if (pos.GetExactDistSq(startPos->Loc) > maxDist)
                {
                    TC_LOG_DEBUG("bg.battleground", "BATTLEGROUND: Sending {} back to start location (map: {}) (possible exploit)", player->GetName(), GetMapId());
                    player->TeleportTo(startPos->Loc);
                }
            }
        }
    }
}

void Battleground::_ProcessPlayerPositionBroadcast(uint32 diff)
{
    m_LastPlayerPositionBroadcast += diff;
    if (m_LastPlayerPositionBroadcast >= PLAYER_POSITION_UPDATE_INTERVAL)
    {
        m_LastPlayerPositionBroadcast = 0;

        WorldPackets::Battleground::BattlegroundPlayerPositions playerPositions;

        for (WorldPackets::Battleground::BattlegroundPlayerPosition& playerPosition : _playerPositions)
        {
            // Update position data if we found player.
            if (Player* player = ObjectAccessor::GetPlayer(GetBgMap(), playerPosition.Guid))
                playerPosition.Pos = player->GetPosition();

            playerPositions.FlagCarriers.push_back(playerPosition);
        }

        SendPacketToAll(playerPositions.Write());
    }
}

inline void Battleground::_ProcessOfflineQueue()
{
    // remove offline players from bg after 5 minutes
    if (!m_OfflineQueue.empty())
    {
        BattlegroundPlayerMap::iterator itr = m_Players.find(*(m_OfflineQueue.begin()));
        if (itr != m_Players.end())
        {
            if (itr->second.OfflineRemoveTime <= GameTime::GetGameTime())
            {
                RemovePlayerAtLeave(itr->first, true, true);// remove player from BG
                m_OfflineQueue.pop_front();                 // remove from offline queue
                //do not use itr for anything, because it is erased in RemovePlayerAtLeave()
            }
        }
    }
}

Team Battleground::GetPrematureWinner()
{
    Team winner = TEAM_OTHER;
    if (GetPlayersCountByTeam(ALLIANCE) >= GetMinPlayersPerTeam())
        winner = ALLIANCE;
    else if (GetPlayersCountByTeam(HORDE) >= GetMinPlayersPerTeam())
        winner = HORDE;

    return winner;
}

inline void Battleground::_ProcessProgress(uint32 diff)
{
    // *********************************************************
    // ***           BATTLEGROUND BALLANCE SYSTEM            ***
    // *********************************************************
    // if less then minimum players are in on one side, then start premature finish timer
    if (!m_PrematureCountDown)
    {
        m_PrematureCountDown = true;
        m_PrematureCountDownTimer = sBattlegroundMgr->GetPrematureFinishTime();
    }
    else if (m_PrematureCountDownTimer < diff)
    {
        // time's up!
        EndBattleground(GetPrematureWinner());
        m_PrematureCountDown = false;
    }
    else if (!sBattlegroundMgr->isTesting())
    {
        uint32 newtime = m_PrematureCountDownTimer - diff;
        // announce every minute
        if (newtime > (MINUTE * IN_MILLISECONDS))
        {
            if (newtime / (MINUTE * IN_MILLISECONDS) != m_PrematureCountDownTimer / (MINUTE * IN_MILLISECONDS))
                PSendMessageToAll(LANG_BATTLEGROUND_PREMATURE_FINISH_WARNING, CHAT_MSG_SYSTEM, nullptr, (uint32)(m_PrematureCountDownTimer / (MINUTE * IN_MILLISECONDS)));
        }
        else
        {
            //announce every 15 seconds
            if (newtime / (15 * IN_MILLISECONDS) != m_PrematureCountDownTimer / (15 * IN_MILLISECONDS))
                PSendMessageToAll(LANG_BATTLEGROUND_PREMATURE_FINISH_WARNING_SECS, CHAT_MSG_SYSTEM, nullptr, (uint32)(m_PrematureCountDownTimer / IN_MILLISECONDS));
        }
        m_PrematureCountDownTimer = newtime;
    }
}

inline void Battleground::_ProcessJoin(uint32 diff)
{
    // *********************************************************
    // ***           BATTLEGROUND STARTING SYSTEM            ***
    // *********************************************************
    ModifyStartDelayTime(diff);

    if (!isArena())
        SetRemainingTime(300000);

    if (m_ResetStatTimer > 5000)
    {
        m_ResetStatTimer = 0;
        for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(itr->first))
                player->ResetAllPowers();
    }

    // Send packet every 10 seconds until the 2nd field reach 0
    if (m_CountdownTimer >= 10000)
    {
        Seconds countdownMaxForBGType = Seconds(isArena() ? ARENA_COUNTDOWN_MAX : BATTLEGROUND_COUNTDOWN_MAX);

        WorldPackets::Misc::StartTimer startTimer;
        startTimer.Type         = WorldPackets::Misc::StartTimer::Pvp;
        startTimer.TimeLeft     = std::chrono::duration_cast<Seconds>(countdownMaxForBGType - Milliseconds(GetElapsedTime()));
        startTimer.TotalTime    = countdownMaxForBGType;

        for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(itr->first))
                player->SendDirectMessage(startTimer.Write());

        m_CountdownTimer = 0;
    }

    if (!(m_Events & BG_STARTING_EVENT_1))
    {
        m_Events |= BG_STARTING_EVENT_1;

        if (!FindBgMap())
        {
            TC_LOG_ERROR("bg.battleground", "Battleground::_ProcessJoin: map (map id: {}, instance id: {}) is not created!", GetMapId(), m_InstanceID);
            EndNow();
            return;
        }

        // Setup here, only when at least one player has ported to the map
        if (!SetupBattleground())
        {
            EndNow();
            return;
        }

        StartingEventCloseDoors();
        SetStartDelayTime(StartDelayTimes[BG_STARTING_EVENT_FIRST]);
        // First start warning - 2 or 1 minute
        if (StartMessageIds[BG_STARTING_EVENT_FIRST])
            SendBroadcastText(StartMessageIds[BG_STARTING_EVENT_FIRST], CHAT_MSG_BG_SYSTEM_NEUTRAL);
    }
    // After 1 minute or 30 seconds, warning is signaled
    else if (GetStartDelayTime() <= StartDelayTimes[BG_STARTING_EVENT_SECOND] && !(m_Events & BG_STARTING_EVENT_2))
    {
        m_Events |= BG_STARTING_EVENT_2;
        if (StartMessageIds[BG_STARTING_EVENT_SECOND])
            SendBroadcastText(StartMessageIds[BG_STARTING_EVENT_SECOND], CHAT_MSG_BG_SYSTEM_NEUTRAL);
    }
    // After 30 or 15 seconds, warning is signaled
    else if (GetStartDelayTime() <= StartDelayTimes[BG_STARTING_EVENT_THIRD] && !(m_Events & BG_STARTING_EVENT_3))
    {
        m_Events |= BG_STARTING_EVENT_3;
        if (StartMessageIds[BG_STARTING_EVENT_THIRD])
            SendBroadcastText(StartMessageIds[BG_STARTING_EVENT_THIRD], CHAT_MSG_BG_SYSTEM_NEUTRAL);
    }
    // Delay expired (after 2 or 1 minute)
    else if (GetStartDelayTime() <= 0 && !(m_Events & BG_STARTING_EVENT_4))
    {
        m_Events |= BG_STARTING_EVENT_4;

        StartingEventOpenDoors();

        if (StartMessageIds[BG_STARTING_EVENT_FOURTH])
            SendBroadcastText(StartMessageIds[BG_STARTING_EVENT_FOURTH], CHAT_MSG_BG_SYSTEM_NEUTRAL);
        SetStatus(STATUS_IN_PROGRESS);
        SetStartDelayTime(StartDelayTimes[BG_STARTING_EVENT_FOURTH]);

        SendPacketToAll(WorldPackets::Battleground::PVPMatchSetState(WorldPackets::Battleground::PVPMatchState::Engaged).Write());

        for (auto const& [guid, _] : GetPlayers())
        {
            if (Player* player = ObjectAccessor::GetPlayer(GetBgMap(), guid))
            {
                player->StartCriteria(CriteriaStartEvent::StartBattleground, GetBgMap()->GetId());
                player->AtStartOfEncounter(EncounterType::Battleground);
            }
        }

        // Remove preparation
        if (isArena())
        {
            /// @todo add arena sound PlaySoundToAll(SOUND_ARENA_START);
            for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
            {
                if (Player* player = ObjectAccessor::FindPlayer(itr->first))
                {
                    // Correctly display EnemyUnitFrame
                    player->SetArenaFaction(player->GetBGTeam());

                    player->RemoveAurasDueToSpell(SPELL_ARENA_PREPARATION);
                    player->ResetAllPowers();
                    if (!player->IsGameMaster())
                    {
                        // remove auras with duration lower than 30s
                        player->RemoveAppliedAuras([](AuraApplication const* aurApp)
                        {
                            Aura* aura = aurApp->GetBase();
                            return !aura->IsPermanent()
                                && aura->GetDuration() <= 30 * IN_MILLISECONDS
                                && aurApp->IsPositive()
                                && !aura->GetSpellInfo()->HasAttribute(SPELL_ATTR0_NO_IMMUNITIES)
                                && !aura->HasEffectType(SPELL_AURA_MOD_INVISIBILITY);
                        });
                    }
                }
            }

            CheckWinConditions();
        }
        else
        {
            PlaySoundToAll(SOUND_BG_START);

            for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
            {
                if (Player* player = ObjectAccessor::FindPlayer(itr->first))
                {
                    player->RemoveAurasDueToSpell(SPELL_PREPARATION);
                    player->ResetAllPowers();
                }
            }
            // Announce BG starting
            if (sWorld->getBoolConfig(CONFIG_BATTLEGROUND_QUEUE_ANNOUNCER_ENABLE))
                sWorld->SendWorldText(LANG_BG_STARTED_ANNOUNCE_WORLD, GetName(), GetMinLevel(), GetMaxLevel());
        }
    }

    if (GetRemainingTime() > 0 && (m_EndTime -= diff) > 0)
        SetRemainingTime(GetRemainingTime() - diff);
}

inline void Battleground::_ProcessLeave(uint32 diff)
{
    // *********************************************************
    // ***           BATTLEGROUND ENDING SYSTEM              ***
    // *********************************************************
    // remove all players from battleground after 2 minutes
    SetRemainingTime(GetRemainingTime() - diff);
    if (GetRemainingTime() <= 0)
    {
        SetRemainingTime(0);
        BattlegroundPlayerMap::iterator itr, next;
        for (itr = m_Players.begin(); itr != m_Players.end(); itr = next)
        {
            next = itr;
            ++next;
            //itr is erased here!
            RemovePlayerAtLeave(itr->first, true, true);// remove player from BG
            // do not change any battleground's private variables
        }
    }
}

Player* Battleground::_GetPlayer(ObjectGuid guid, bool offlineRemove, char const* context) const
{
    Player* player = nullptr;
    if (!offlineRemove)
    {
        // should this be ObjectAccessor::FindConnectedPlayer() to return players teleporting ?
        player = ObjectAccessor::FindPlayer(guid);
        if (!player)
            TC_LOG_ERROR("bg.battleground", "Battleground::{}: player ({}) not found for BG (map: {}, instance id: {})!",
                context, guid.ToString(), GetMapId(), m_InstanceID);
    }
    return player;
}

Player* Battleground::_GetPlayerForTeam(Team team, BattlegroundPlayerMap::const_iterator itr, char const* context) const
{
    Player* player = _GetPlayer(itr, context);
    if (player)
    {
        Team playerTeam = itr->second.Team;
        if (!playerTeam)
            playerTeam = player->GetEffectiveTeam();
        if (playerTeam != team)
            player = nullptr;
    }
    return player;
}

BattlegroundMap* Battleground::GetBgMap() const
{
    ASSERT(m_Map);
    return m_Map;
}

WorldSafeLocsEntry const* Battleground::GetTeamStartPosition(TeamId teamId) const
{
    ASSERT(teamId < TEAM_NEUTRAL);
    return _battlegroundTemplate->StartLocation[teamId];
}

float Battleground::GetStartMaxDist() const
{
    return _battlegroundTemplate->MaxStartDistSq;
}

void Battleground::SendPacketToAll(WorldPacket const* packet) const
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        if (Player* player = _GetPlayer(itr, "SendPacketToAll"))
            player->SendDirectMessage(packet);
}

void Battleground::SendPacketToTeam(Team team, WorldPacket const* packet, Player* except /*= nullptr*/) const
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        if (Player* player = _GetPlayerForTeam(team, itr, "SendPacketToTeam"))
            if (player != except)
                player->SendDirectMessage(packet);
    }
}

void Battleground::SendChatMessage(Creature* source, uint8 textId, WorldObject* target /*= nullptr*/)
{
    sCreatureTextMgr->SendChat(source, textId, target);
}

void Battleground::SendBroadcastText(uint32 id, ChatMsg msgType, WorldObject const* target)
{
    if (!sBroadcastTextStore.LookupEntry(id))
    {
        TC_LOG_ERROR("bg.battleground", "Battleground::SendBroadcastText: `broadcast_text` (ID: {}) was not found", id);
        return;
    }

    Trinity::BroadcastTextBuilder builder(nullptr, msgType, id, GENDER_MALE, target);
    Trinity::LocalizedDo<Trinity::BroadcastTextBuilder> localizer(builder);
    BroadcastWorker(localizer);
}

void Battleground::PlaySoundToAll(uint32 soundID)
{
    SendPacketToAll(WorldPackets::Misc::PlaySound(ObjectGuid::Empty, soundID, 0).Write());
}

void Battleground::PlaySoundToTeam(uint32 soundID, Team team)
{
    SendPacketToTeam(team, WorldPackets::Misc::PlaySound(ObjectGuid::Empty, soundID, 0).Write());
}

void Battleground::CastSpellOnTeam(uint32 SpellID, Team team)
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        if (Player* player = _GetPlayerForTeam(team, itr, "CastSpellOnTeam"))
            player->CastSpell(player, SpellID, true);
}

void Battleground::RemoveAuraOnTeam(uint32 SpellID, Team team)
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        if (Player* player = _GetPlayerForTeam(team, itr, "RemoveAuraOnTeam"))
            player->RemoveAura(SpellID);
}

void Battleground::RewardHonorToTeam(uint32 Honor, Team team)
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        if (Player* player = _GetPlayerForTeam(team, itr, "RewardHonorToTeam"))
            UpdatePlayerScore(player, SCORE_BONUS_HONOR, Honor);
}

void Battleground::RewardReputationToTeam(uint32 faction_id, uint32 Reputation, Team team)
{
    FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction_id);
    if (!factionEntry)
        return;

    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        Player* player = _GetPlayerForTeam(team, itr, "RewardReputationToTeam");
        if (!player)
            continue;

        if (player->HasPlayerFlagEx(PLAYER_FLAGS_EX_MERCENARY_MODE))
            continue;

        uint32 repGain = Reputation;
        AddPct(repGain, player->GetTotalAuraModifier(SPELL_AURA_MOD_REPUTATION_GAIN));
        AddPct(repGain, player->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_FACTION_REPUTATION_GAIN, faction_id));
        player->GetReputationMgr().ModifyReputation(factionEntry, repGain);
    }
}

void Battleground::UpdateWorldState(int32 worldStateId, int32 value, bool hidden /*= false*/)
{
    sWorldStateMgr->SetValue(worldStateId, value, hidden, GetBgMap());
}

void Battleground::EndBattleground(Team winner)
{
    RemoveFromBGFreeSlotQueue();

    bool guildAwarded = false;

    if (winner == ALLIANCE)
    {
        if (isBattleground())
            SendBroadcastText(BG_TEXT_ALLIANCE_WINS, CHAT_MSG_BG_SYSTEM_NEUTRAL);

        PlaySoundToAll(SOUND_ALLIANCE_WINS);                // alliance wins sound

        SetWinner(PVP_TEAM_ALLIANCE);
    }
    else if (winner == HORDE)
    {
        if (isBattleground())
            SendBroadcastText(BG_TEXT_HORDE_WINS, CHAT_MSG_BG_SYSTEM_NEUTRAL);

        PlaySoundToAll(SOUND_HORDE_WINS);                   // horde wins sound

        SetWinner(PVP_TEAM_HORDE);
    }
    else
    {
        SetWinner(PVP_TEAM_NEUTRAL);
    }

    CharacterDatabasePreparedStatement* stmt = nullptr;
    uint64 battlegroundId = 1;
    if (isBattleground() && sWorld->getBoolConfig(CONFIG_BATTLEGROUND_STORE_STATISTICS_ENABLE))
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PVPSTATS_MAXID);
        PreparedQueryResult result = CharacterDatabase.Query(stmt);

        if (result)
        {
            Field* fields = result->Fetch();
            battlegroundId = fields[0].GetUInt64() + 1;
        }

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PVPSTATS_BATTLEGROUND);
        stmt->setUInt64(0, battlegroundId);
        stmt->setUInt8(1, GetWinner());
        stmt->setUInt8(2, GetUniqueBracketId());
        stmt->setUInt32(3, GetTypeID());
        CharacterDatabase.Execute(stmt);
    }

    SetStatus(STATUS_WAIT_LEAVE);
    //we must set it this way, because end time is sent in packet!
    SetRemainingTime(TIME_AUTOCLOSE_BATTLEGROUND);

    WorldPackets::Battleground::PVPMatchComplete pvpMatchComplete;
    pvpMatchComplete.Winner = GetWinner();
    pvpMatchComplete.Duration = std::chrono::duration_cast<Seconds>(Milliseconds(std::max<int32>(0, (GetElapsedTime() - BG_START_DELAY_2M))));
    pvpMatchComplete.LogData.emplace();
    BuildPvPLogDataPacket(*pvpMatchComplete.LogData);
    pvpMatchComplete.Write();

    for (BattlegroundPlayerMap::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        Team team = itr->second.Team;

        Player* player = _GetPlayer(itr, "EndBattleground");
        if (!player)
            continue;

        // should remove spirit of redemption
        if (player->HasAuraType(SPELL_AURA_SPIRIT_OF_REDEMPTION))
            player->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);

        if (!player->IsAlive())
        {
            player->ResurrectPlayer(1.0f);
            player->SpawnCorpseBones();
        }
        else
            //needed cause else in av some creatures will kill the players at the end
            player->CombatStop();

        // remove temporary currency bonus auras before rewarding player
        player->RemoveAura(SPELL_HONORABLE_DEFENDER_25Y);
        player->RemoveAura(SPELL_HONORABLE_DEFENDER_60Y);

        uint32 winnerKills = player->GetRandomWinner() ? sWorld->getIntConfig(CONFIG_BG_REWARD_WINNER_HONOR_LAST) : sWorld->getIntConfig(CONFIG_BG_REWARD_WINNER_HONOR_FIRST);
        uint32 loserKills = player->GetRandomWinner() ? sWorld->getIntConfig(CONFIG_BG_REWARD_LOSER_HONOR_LAST) : sWorld->getIntConfig(CONFIG_BG_REWARD_LOSER_HONOR_FIRST);

        if (isBattleground() && sWorld->getBoolConfig(CONFIG_BATTLEGROUND_STORE_STATISTICS_ENABLE))
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PVPSTATS_PLAYER);
            BattlegroundScoreMap::const_iterator score = PlayerScores.find(player->GetGUID());

            stmt->setUInt32(0,  battlegroundId);
            stmt->setUInt64(1,  player->GetGUID().GetCounter());
            stmt->setBool  (2,  team == winner);
            stmt->setUInt32(3,  score->second->GetKillingBlows());
            stmt->setUInt32(4,  score->second->GetDeaths());
            stmt->setUInt32(5,  score->second->GetHonorableKills());
            stmt->setUInt32(6,  score->second->GetBonusHonor());
            stmt->setUInt32(7,  score->second->GetDamageDone());
            stmt->setUInt32(8,  score->second->GetHealingDone());
            stmt->setUInt32(9,  score->second->GetAttr(0));
            stmt->setUInt32(10, score->second->GetAttr(1));
            stmt->setUInt32(11, score->second->GetAttr(2));
            stmt->setUInt32(12, score->second->GetAttr(3));
            stmt->setUInt32(13, score->second->GetAttr(4));

            CharacterDatabase.Execute(stmt);
        }

        // Reward winner team
        if (team == winner)
        {
            if (BattlegroundPlayer const* bgPlayer = GetBattlegroundPlayerData(player->GetGUID()))
            {
                if (BattlegroundMgr::IsRandomBattleground(bgPlayer->queueTypeId.BattlemasterListId)
                    || BattlegroundMgr::IsBGWeekend(BattlegroundTypeId(bgPlayer->queueTypeId.BattlemasterListId)))
                {
                    UpdatePlayerScore(player, SCORE_BONUS_HONOR, GetBonusHonorFromKill(winnerKills));
                    if (!player->GetRandomWinner())
                    {
                        player->SetRandomWinner(true);
                        // TODO: win honor xp
                    }
                }
                else
                {
                    // TODO: loss honor xp
                }
            }

            player->UpdateCriteria(CriteriaType::WinBattleground, player->GetMapId());
            if (!guildAwarded)
            {
                guildAwarded = true;
                if (ObjectGuid::LowType guildId = GetBgMap()->GetOwnerGuildId(player->GetBGTeam()))
                {
                    if (Guild* guild = sGuildMgr->GetGuildById(guildId))
                        guild->UpdateCriteria(CriteriaType::WinBattleground, player->GetMapId(), 0, 0, nullptr, player);
                }
            }
        }
        else
        {
            if (BattlegroundPlayer const* bgPlayer = GetBattlegroundPlayerData(player->GetGUID()))
            {
                if (BattlegroundMgr::IsRandomBattleground(bgPlayer->queueTypeId.BattlemasterListId)
                    || BattlegroundMgr::IsBGWeekend(BattlegroundTypeId(bgPlayer->queueTypeId.BattlemasterListId)))
                    UpdatePlayerScore(player, SCORE_BONUS_HONOR, GetBonusHonorFromKill(loserKills));
            }
        }

        player->ResetAllPowers();
        player->CombatStopWithPets(true);

        BlockMovement(player);

        player->SendDirectMessage(pvpMatchComplete.GetRawPacket());

        player->UpdateCriteria(CriteriaType::ParticipateInBattleground, player->GetMapId());
    }
}

uint32 Battleground::GetScriptId() const
{
    return _battlegroundTemplate->ScriptId;
}

uint32 Battleground::GetBonusHonorFromKill(uint32 kills) const
{
    //variable kills means how many honorable kills you scored (so we need kills * honor_for_one_kill)
    uint32 maxLevel = std::min<uint32>(GetMaxLevel(), 80U);
    return Trinity::Honor::hk_honor_at_level(maxLevel, float(kills));
}

void Battleground::BlockMovement(Player* player)
{
    // movement disabled NOTE: the effect will be automatically removed by client when the player is teleported from the battleground, so no need to send with uint8(1) in RemovePlayerAtLeave()
    player->SetClientControl(player, false);
}

void Battleground::RemovePlayerAtLeave(ObjectGuid guid, bool Transport, bool SendPacket)
{
    Team team = GetPlayerTeam(guid);
    bool participant = false;
    // Remove from lists/maps
    BattlegroundPlayerMap::iterator itr = m_Players.find(guid);
    Optional<BattlegroundQueueTypeId> bgQueueTypeId;
    if (itr != m_Players.end())
    {
        bgQueueTypeId = itr->second.queueTypeId;
        UpdatePlayersCountByTeam(team, true);               // -1 player
        m_Players.erase(itr);
        // check if the player was a participant of the match, or only entered through gm command (goname)
        participant = true;
    }

    BattlegroundScoreMap::iterator itr2 = PlayerScores.find(guid);
    if (itr2 != PlayerScores.end())
    {
        delete itr2->second;                                // delete player's score
        PlayerScores.erase(itr2);
    }

    Player* player = ObjectAccessor::FindPlayer(guid);

    if (player)
    {
        // should remove spirit of redemption
        if (player->HasAuraType(SPELL_AURA_SPIRIT_OF_REDEMPTION))
            player->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);

        player->RemoveAurasByType(SPELL_AURA_MOUNTED);
        player->RemoveAura(SPELL_MERCENARY_HORDE_1);
        player->RemoveAura(SPELL_MERCENARY_HORDE_REACTIONS);
        player->RemoveAura(SPELL_MERCENARY_ALLIANCE_1);
        player->RemoveAura(SPELL_MERCENARY_ALLIANCE_REACTIONS);
        player->RemoveAura(SPELL_MERCENARY_SHAPESHIFT);
        player->RemovePlayerFlagEx(PLAYER_FLAGS_EX_MERCENARY_MODE);

        player->AtEndOfEncounter(EncounterType::Battleground);

        player->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2::LeaveArenaOrBattleground);

        if (!player->IsAlive())                              // resurrect on exit
        {
            player->ResurrectPlayer(1.0f);
            player->SpawnCorpseBones();
        }
    }
    else
    {
        CharacterDatabaseTransaction trans(nullptr);
        Player::OfflineResurrect(guid, trans);
    }

    RemovePlayer(player, guid, team);                           // BG subclass specific code

    if (participant) // if the player was a match participant, remove auras, calc rating, update queue
    {
        if (player)
        {
            player->ClearAfkReports();

            // if arena, remove the specific arena auras
            if (isArena())
            {
                // unsummon current and summon old pet if there was one and there isn't a current pet
                player->RemovePet(nullptr, PET_SAVE_NOT_IN_SLOT);
                player->ResummonPetTemporaryUnSummonedIfAny();
            }

            if (SendPacket && bgQueueTypeId)
            {
                WorldPackets::Battleground::BattlefieldStatusNone battlefieldStatus;
                sBattlegroundMgr->BuildBattlegroundStatusNone(&battlefieldStatus, player, player->GetBattlegroundQueueIndex(*bgQueueTypeId), player->GetBattlegroundQueueJoinTime(*bgQueueTypeId));
                player->SendDirectMessage(battlefieldStatus.Write());
            }

            // this call is important, because player, when joins to battleground, this method is not called, so it must be called when leaving bg
            if (bgQueueTypeId)
                player->RemoveBattlegroundQueueId(*bgQueueTypeId);
        }

        // remove from raid group if player is member
        if (Group* group = GetBgRaid(team))
        {
            if (!group->RemoveMember(guid))                // group was disbanded
                SetBgRaid(team, nullptr);
        }
        DecreaseInvitedCount(team);
        //we should update battleground queue, but only if bg isn't ending
        if (isBattleground() && GetStatus() < STATUS_WAIT_LEAVE && bgQueueTypeId)
        {
            // a player has left the battleground, so there are free slots -> add to queue
            AddToBGFreeSlotQueue();
            sBattlegroundMgr->ScheduleQueueUpdate(0, *bgQueueTypeId, GetBracketId());
        }

        // Let others know
        WorldPackets::Battleground::BattlegroundPlayerLeft playerLeft;
        playerLeft.Guid = guid;
        SendPacketToTeam(team, playerLeft.Write(), player);
    }

    if (player)
    {
        // Do next only if found in battleground
        player->SetBattlegroundId(0, BATTLEGROUND_TYPE_NONE, BATTLEGROUND_QUEUE_NONE);  // We're not in BG.
        // reset destination bg team
        player->SetBGTeam(TEAM_OTHER);

        // remove all criterias on bg leave
        player->FailCriteria(CriteriaFailEvent::LeaveBattleground, 0);

        if (Transport)
            player->TeleportToBGEntryPoint();

        TC_LOG_DEBUG("bg.battleground", "Removed player {} from Battleground.", player->GetName());
    }

    //battleground object will be deleted next Battleground::Update() call
}

// this method is called when no players remains in battleground
void Battleground::Reset()
{
    SetWinner(PVP_TEAM_NEUTRAL);
    SetStatus(STATUS_WAIT_QUEUE);
    SetElapsedTime(0);
    SetRemainingTime(0);
    m_Events = 0;

    if (m_InvitedAlliance > 0 || m_InvitedHorde > 0)
        TC_LOG_ERROR("bg.battleground", "Battleground::Reset: one of the counters is not 0 (alliance: {}, horde: {}) for BG (map: {}, instance id: {})!",
            m_InvitedAlliance, m_InvitedHorde, GetMapId(), m_InstanceID);

    m_InvitedAlliance = 0;
    m_InvitedHorde = 0;
    m_InBGFreeSlotQueue = false;

    m_Players.clear();

    for (BattlegroundScoreMap::const_iterator itr = PlayerScores.begin(); itr != PlayerScores.end(); ++itr)
        delete itr->second;
    PlayerScores.clear();

    _playerPositions.clear();
}

void Battleground::StartBattleground()
{
    SetElapsedTime(0);
    // add BG to free slot queue
    AddToBGFreeSlotQueue();

    // add bg to update list
    // This must be done here, because we need to have already invited some players when first BG::Update() method is executed
    // and it doesn't matter if we call StartBattleground() more times, because m_Battlegrounds is a map and instance id never changes
    sBattlegroundMgr->AddBattleground(this);

    if (m_IsRated)
        TC_LOG_DEBUG("bg.arena", "Arena match type: {} for Team1Id: {} - Team2Id: {} started.", m_ArenaType, m_ArenaTeamIds[TEAM_ALLIANCE], m_ArenaTeamIds[TEAM_HORDE]);
}

void Battleground::TeleportPlayerToExploitLocation(Player* player)
{
    if (WorldSafeLocsEntry const* loc = GetExploitTeleportLocation(Team(player->GetBGTeam())))
        player->TeleportTo(loc->Loc);
}

void Battleground::AddPlayer(Player* player, BattlegroundQueueTypeId queueId)
{
    // remove afk from player
    if (player->isAFK())
        player->ToggleAFK();

    // score struct must be created in inherited class

    Team team = player->GetBGTeam();

    BattlegroundPlayer bp;
    bp.OfflineRemoveTime = 0;
    bp.Team = team;
    bp.Mercenary = player->IsMercenaryForBattlegroundQueueType(queueId);
    bp.queueTypeId = queueId;

    bool const isInBattleground = IsPlayerInBattleground(player->GetGUID());
    // Add to list/maps
    m_Players[player->GetGUID()] = bp;

    if (!isInBattleground)
    {
        UpdatePlayersCountByTeam(team, false);                  // +1 player
        PlayerScores[player->GetGUID()] = new BattlegroundScore(player->GetGUID(), player->GetBGTeam(), _pvpStatIds);
    }

    WorldPackets::Battleground::BattlegroundPlayerJoined playerJoined;
    playerJoined.Guid = player->GetGUID();
    SendPacketToTeam(team, playerJoined.Write(), player);

    WorldPackets::Battleground::PVPMatchInitialize pvpMatchInitialize;
    pvpMatchInitialize.MapID = GetMapId();
    switch (GetStatus())
    {
        case STATUS_NONE:
        case STATUS_WAIT_QUEUE:
            pvpMatchInitialize.State = WorldPackets::Battleground::PVPMatchState::Inactive;
            break;
        case STATUS_WAIT_JOIN:
            pvpMatchInitialize.State = WorldPackets::Battleground::PVPMatchState::StartUp;
            break;
        case STATUS_IN_PROGRESS:
            pvpMatchInitialize.State = WorldPackets::Battleground::PVPMatchState::Engaged;
            break;
        case STATUS_WAIT_LEAVE:
            pvpMatchInitialize.State = WorldPackets::Battleground::PVPMatchState::Complete;
            break;
        default:
            break;
    }

    if (GetElapsedTime() >= BG_START_DELAY_2M)
    {
        Milliseconds duration(GetElapsedTime() - BG_START_DELAY_2M);
        pvpMatchInitialize.Duration = std::chrono::duration_cast<Seconds>(duration);
        pvpMatchInitialize.StartTime = GameTime::GetSystemTime() - duration;
    }

    pvpMatchInitialize.ArenaFaction = player->GetBGTeam() == HORDE ? PVP_TEAM_HORDE : PVP_TEAM_ALLIANCE;
    pvpMatchInitialize.BattlemasterListID = queueId.BattlemasterListId;
    pvpMatchInitialize.Registered = false;
    pvpMatchInitialize.AffectsRating = isRated();

    player->SendDirectMessage(pvpMatchInitialize.Write());

    player->RemoveAurasByType(SPELL_AURA_MOUNTED);

    // add arena specific auras
    if (isArena())
    {
        player->RemoveArenaEnchantments(TEMP_ENCHANTMENT_SLOT);
        player->DestroyConjuredItems(true);
        player->UnsummonPetTemporaryIfAny();

        if (GetStatus() == STATUS_WAIT_JOIN)                 // not started yet
        {
            player->CastSpell(player, SPELL_ARENA_PREPARATION, true);
            player->ResetAllPowers();
        }
    }
    else
    {
        if (GetStatus() == STATUS_WAIT_JOIN)                 // not started yet
        {
            player->CastSpell(player, SPELL_PREPARATION, true);   // reduces all mana cost of spells.

            Seconds countdownMaxForBGType = Seconds(isArena() ? ARENA_COUNTDOWN_MAX : BATTLEGROUND_COUNTDOWN_MAX);

            WorldPackets::Misc::StartTimer startTimer;
            startTimer.Type         = WorldPackets::Misc::StartTimer::Pvp;
            startTimer.TimeLeft     = std::chrono::duration_cast<Seconds>(countdownMaxForBGType - Milliseconds(GetElapsedTime()));
            startTimer.TotalTime    = countdownMaxForBGType;
            player->SendDirectMessage(startTimer.Write());
        }

        if (bp.Mercenary)
        {
            if (bp.Team == HORDE)
            {
                player->CastSpell(player, SPELL_MERCENARY_HORDE_1);
                player->CastSpell(player, SPELL_MERCENARY_HORDE_REACTIONS);
            }
            else if (bp.Team == ALLIANCE)
            {
                player->CastSpell(player, SPELL_MERCENARY_ALLIANCE_1);
                player->CastSpell(player, SPELL_MERCENARY_ALLIANCE_REACTIONS);
            }
            player->CastSpell(player, SPELL_MERCENARY_SHAPESHIFT);
            player->SetPlayerFlagEx(PLAYER_FLAGS_EX_MERCENARY_MODE);
        }
    }

    // setup BG group membership
    PlayerAddedToBGCheckIfBGIsRunning(player);
    AddOrSetPlayerToCorrectBgGroup(player, team);
}

// this method adds player to his team's bg group, or sets his correct group if player is already in bg group
void Battleground::AddOrSetPlayerToCorrectBgGroup(Player* player, Team team)
{
    ObjectGuid playerGuid = player->GetGUID();
    Group* group = GetBgRaid(team);
    if (!group)                                      // first player joined
    {
        group = new Group;
        SetBgRaid(team, group);
        group->Create(player);
    }
    else                                            // raid already exist
    {
        if (group->IsMember(playerGuid))
        {
            uint8 subgroup = group->GetMemberGroup(playerGuid);
            player->SetBattlegroundOrBattlefieldRaid(group, subgroup);
        }
        else
        {
            group->AddMember(player);
            if (Group* originalGroup = player->GetOriginalGroup())
                if (originalGroup->IsLeader(playerGuid))
                {
                    group->ChangeLeader(playerGuid);
                    group->SendUpdate();
                }
        }
    }
}

// This method should be called when player logs into running battleground
void Battleground::EventPlayerLoggedIn(Player* player)
{
    ObjectGuid guid = player->GetGUID();
    // player is correct pointer
    for (auto itr = m_OfflineQueue.begin(); itr != m_OfflineQueue.end(); ++itr)
    {
        if (*itr == guid)
        {
            m_OfflineQueue.erase(itr);
            break;
        }
    }
    m_Players[guid].OfflineRemoveTime = 0;
    PlayerAddedToBGCheckIfBGIsRunning(player);
    // if battleground is starting, then add preparation aura
    // we don't have to do that, because preparation aura isn't removed when player logs out
}

// This method should be called when player logs out from running battleground
void Battleground::EventPlayerLoggedOut(Player* player)
{
    ObjectGuid guid = player->GetGUID();
    if (!IsPlayerInBattleground(guid))  // Check if this player really is in battleground (might be a GM who teleported inside)
        return;

    // player is correct pointer, it is checked in WorldSession::LogoutPlayer()
    m_OfflineQueue.push_back(player->GetGUID());
    m_Players[guid].OfflineRemoveTime = GameTime::GetGameTime() + MAX_OFFLINE_TIME;
    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        // drop flag and handle other cleanups
        RemovePlayer(player, guid, GetPlayerTeam(guid));

        // 1 player is logging out, if it is the last alive, then end arena!
        if (isArena() && player->IsAlive())
            if (GetAlivePlayersCountByTeam(player->GetBGTeam()) <= 1 && GetPlayersCountByTeam(GetOtherTeam(player->GetBGTeam())))
                EndBattleground(GetOtherTeam(player->GetBGTeam()));
    }
}

// This method should be called only once ... it adds pointer to queue
void Battleground::AddToBGFreeSlotQueue()
{
    if (!m_InBGFreeSlotQueue && isBattleground())
    {
        sBattlegroundMgr->AddToBGFreeSlotQueue(this);
        m_InBGFreeSlotQueue = true;
    }
}

// This method removes this battleground from free queue - it must be called when deleting battleground
void Battleground::RemoveFromBGFreeSlotQueue()
{
    if (m_InBGFreeSlotQueue)
    {
        sBattlegroundMgr->RemoveFromBGFreeSlotQueue(GetMapId(), m_InstanceID);
        m_InBGFreeSlotQueue = false;
    }
}

// get the number of free slots for team
// returns the number how many players can join battleground to MaxPlayersPerTeam
uint32 Battleground::GetFreeSlotsForTeam(Team team) const
{
    // if BG is starting and CONFIG_BATTLEGROUND_INVITATION_TYPE == BG_QUEUE_INVITATION_TYPE_NO_BALANCE, invite anyone
    if (GetStatus() == STATUS_WAIT_JOIN && sWorld->getIntConfig(CONFIG_BATTLEGROUND_INVITATION_TYPE) == BG_QUEUE_INVITATION_TYPE_NO_BALANCE)
        return (GetInvitedCount(team) < GetMaxPlayersPerTeam()) ? GetMaxPlayersPerTeam() - GetInvitedCount(team) : 0;

    // if BG is already started or CONFIG_BATTLEGROUND_INVITATION_TYPE != BG_QUEUE_INVITATION_TYPE_NO_BALANCE, do not allow to join too much players of one faction
    uint32 otherTeamInvitedCount;
    uint32 thisTeamInvitedCount;
    uint32 otherTeamPlayersCount;
    uint32 thisTeamPlayersCount;

    if (team == ALLIANCE)
    {
        thisTeamInvitedCount  = GetInvitedCount(ALLIANCE);
        otherTeamInvitedCount = GetInvitedCount(HORDE);
        thisTeamPlayersCount  = GetPlayersCountByTeam(ALLIANCE);
        otherTeamPlayersCount = GetPlayersCountByTeam(HORDE);
    }
    else
    {
        thisTeamInvitedCount  = GetInvitedCount(HORDE);
        otherTeamInvitedCount = GetInvitedCount(ALLIANCE);
        thisTeamPlayersCount  = GetPlayersCountByTeam(HORDE);
        otherTeamPlayersCount = GetPlayersCountByTeam(ALLIANCE);
    }
    if (GetStatus() == STATUS_IN_PROGRESS || GetStatus() == STATUS_WAIT_JOIN)
    {
        // difference based on ppl invited (not necessarily entered battle)
        // default: allow 0
        uint32 diff = 0;

        // allow join one person if the sides are equal (to fill up bg to minPlayerPerTeam)
        if (otherTeamInvitedCount == thisTeamInvitedCount)
            diff = 1;
        // allow join more ppl if the other side has more players
        else if (otherTeamInvitedCount > thisTeamInvitedCount)
            diff = otherTeamInvitedCount - thisTeamInvitedCount;

        // difference based on max players per team (don't allow inviting more)
        uint32 diff2 = (thisTeamInvitedCount < GetMaxPlayersPerTeam()) ? GetMaxPlayersPerTeam() - thisTeamInvitedCount : 0;

        // difference based on players who already entered
        // default: allow 0
        uint32 diff3 = 0;
        // allow join one person if the sides are equal (to fill up bg minPlayerPerTeam)
        if (otherTeamPlayersCount == thisTeamPlayersCount)
            diff3 = 1;
        // allow join more ppl if the other side has more players
        else if (otherTeamPlayersCount > thisTeamPlayersCount)
            diff3 = otherTeamPlayersCount - thisTeamPlayersCount;
        // or other side has less than minPlayersPerTeam
        else if (thisTeamInvitedCount <= GetMinPlayersPerTeam())
            diff3 = GetMinPlayersPerTeam() - thisTeamInvitedCount + 1;

        // return the minimum of the 3 differences

        // min of diff and diff 2
        diff = std::min(diff, diff2);
        // min of diff, diff2 and diff3
        return std::min(diff, diff3);
    }
    return 0;
}

bool Battleground::isArena() const
{
    return _battlegroundTemplate->IsArena();
}

bool Battleground::isBattleground() const
{
    return !isArena();
}

bool Battleground::HasFreeSlots() const
{
    return GetPlayersSize() < GetMaxPlayers();
}

void Battleground::BuildPvPLogDataPacket(WorldPackets::Battleground::PVPMatchStatistics& pvpLogData) const
{
    pvpLogData.Statistics.reserve(GetPlayerScoresSize());
    for (auto const& score : PlayerScores)
    {
        if (Player* player = ObjectAccessor::GetPlayer(GetBgMap(), score.first))
        {
            WorldPackets::Battleground::PVPMatchStatistics::PVPMatchPlayerStatistics playerData;
            score.second->BuildPvPLogPlayerDataPacket(playerData);

            playerData.IsInWorld = true;
            playerData.PrimaryTalentTree = AsUnderlyingType(player->GetPrimarySpecialization());
            playerData.Sex = player->GetGender();
            playerData.Race = player->GetRace();
            playerData.Class = player->GetClass();
            playerData.HonorLevel = player->GetHonorLevel();

            pvpLogData.Statistics.push_back(playerData);
        }
    }

    pvpLogData.PlayerCount[PVP_TEAM_HORDE] = int8(GetPlayersCountByTeam(HORDE));
    pvpLogData.PlayerCount[PVP_TEAM_ALLIANCE] = int8(GetPlayersCountByTeam(ALLIANCE));
}

BattlegroundScore const* Battleground::GetBattlegroundScore(Player* player) const
{
    return Trinity::Containers::MapGetValuePtr(PlayerScores, player->GetGUID());
}

bool Battleground::UpdatePlayerScore(Player* player, uint32 type, uint32 value, bool doAddHonor)
{
    BattlegroundScoreMap::const_iterator itr = PlayerScores.find(player->GetGUID());
    if (itr == PlayerScores.end()) // player not found...
        return false;

    if (type == SCORE_BONUS_HONOR && doAddHonor && isBattleground())
        player->RewardHonor(nullptr, 1, value); // RewardHonor calls UpdatePlayerScore with doAddHonor = false
    else
        itr->second->UpdateScore(type, value);

    return true;
}

void Battleground::UpdatePvpStat(Player* player, uint32 pvpStatId, uint32 value)
{
    if (BattlegroundScore* score = Trinity::Containers::MapGetValuePtr(PlayerScores, player->GetGUID()))
        score->UpdatePvpStat(pvpStatId, value);
}

bool Battleground::AddObject(uint32 type, uint32 entry, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3, uint32 /*respawnTime*/, GOState goState)
{
    // If the assert is called, means that BgObjects must be resized!
    ASSERT(type < BgObjects.size());

    Map* map = FindBgMap();
    if (!map)
        return false;

    QuaternionData rot(rotation0, rotation1, rotation2, rotation3);
    // Temporally add safety check for bad spawns and send log (object rotations need to be rechecked in sniff)
    if (!rotation0 && !rotation1 && !rotation2 && !rotation3)
    {
        TC_LOG_DEBUG("bg.battleground", "Battleground::AddObject: gameoobject [entry: {}, object type: {}] for BG (map: {}) has zeroed rotation fields, "
            "orientation used temporally, but please fix the spawn", entry, type, GetMapId());

        rot = QuaternionData::fromEulerAnglesZYX(o, 0.f, 0.f);
    }

    // Must be created this way, adding to godatamap would add it to the base map of the instance
    // and when loading it (in go::LoadFromDB()), a new guid would be assigned to the object, and a new object would be created
    // So we must create it specific for this instance
    GameObject* go = GameObject::CreateGameObject(entry, GetBgMap(), Position(x, y, z, o), rot, 255, goState);
    if (!go)
    {
        TC_LOG_ERROR("bg.battleground", "Battleground::AddObject: cannot create gameobject (entry: {}) for BG (map: {}, instance id: {})!",
                entry, GetMapId(), m_InstanceID);
        return false;
    }

/*
    uint32 guid = go->GetGUIDLow();

    // without this, UseButtonOrDoor caused the crash, since it tried to get go info from godata
    // iirc that was changed, so adding to go data map is no longer required if that was the only function using godata from GameObject without checking if it existed
    GameObjectData& data = sObjectMgr->NewGOData(guid);

    data.id             = entry;
    data.mapid          = GetMapId();
    data.posX           = x;
    data.posY           = y;
    data.posZ           = z;
    data.orientation    = o;
    data.rotation0      = rotation0;
    data.rotation1      = rotation1;
    data.rotation2      = rotation2;
    data.rotation3      = rotation3;
    data.spawntimesecs  = respawnTime;
    data.spawnMask      = 1;
    data.animprogress   = 100;
    data.go_state       = 1;
*/
    // Add to world, so it can be later looked up from HashMapHolder
    if (!map->AddToMap(go))
    {
        delete go;
        return false;
    }
    BgObjects[type] = go->GetGUID();
    return true;
}

bool Battleground::AddObject(uint32 type, uint32 entry, Position const& pos, float rotation0, float rotation1, float rotation2, float rotation3, uint32 respawnTime /*= 0*/, GOState goState /*= GO_STATE_READY*/)
{
    return AddObject(type, entry, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), rotation0, rotation1, rotation2, rotation3, respawnTime, goState);
}

// Some doors aren't despawned so we cannot handle their closing in gameobject::update()
// It would be nice to correctly implement GO_ACTIVATED state and open/close doors in gameobject code
void Battleground::DoorClose(uint32 type)
{
    if (GameObject* obj = GetBgMap()->GetGameObject(BgObjects[type]))
    {
        // If doors are open, close it
        if (obj->getLootState() == GO_ACTIVATED && obj->GetGoState() != GO_STATE_READY)
        {
            obj->SetLootState(GO_READY);
            obj->SetGoState(GO_STATE_READY);
        }
    }
    else
        TC_LOG_ERROR("bg.battleground", "Battleground::DoorClose: door gameobject (type: {}, {}) not found for BG (map: {}, instance id: {})!",
            type, BgObjects[type].ToString(), GetMapId(), m_InstanceID);
}

void Battleground::DoorOpen(uint32 type)
{
    if (GameObject* obj = GetBgMap()->GetGameObject(BgObjects[type]))
    {
        obj->SetLootState(GO_ACTIVATED);
        obj->SetGoState(GO_STATE_ACTIVE);
    }
    else
        TC_LOG_ERROR("bg.battleground", "Battleground::DoorOpen: door gameobject (type: {}, {}) not found for BG (map: {}, instance id: {})!",
            type, BgObjects[type].ToString(), GetMapId(), m_InstanceID);
}

GameObject* Battleground::GetBGObject(uint32 type, bool logError)
{
    GameObject* obj = GetBgMap()->GetGameObject(BgObjects[type]);
    if (!obj)
    {
        if (logError)
            TC_LOG_ERROR("bg.battleground", "Battleground::GetBGObject: gameobject (type: {}, {}) not found for BG (map: {}, instance id: {})!",
                type, BgObjects[type].ToString(), GetMapId(), m_InstanceID);
        else
            TC_LOG_INFO("bg.battleground", "Battleground::GetBGObject: gameobject (type: {}, {}) not found for BG (map: {}, instance id: {})!",
                type, BgObjects[type].ToString(), GetMapId(), m_InstanceID);
    }
    return obj;
}

Creature* Battleground::GetBGCreature(uint32 type, bool logError)
{
    Creature* creature = GetBgMap()->GetCreature(BgCreatures[type]);
    if (!creature)
    {
        if (logError)
            TC_LOG_ERROR("bg.battleground", "Battleground::GetBGCreature: creature (type: {}, {}) not found for BG (map: {}, instance id: {})!",
                type, BgCreatures[type].ToString(), GetMapId(), m_InstanceID);
        else
            TC_LOG_INFO("bg.battleground", "Battleground::GetBGCreature: creature (type: {}, {}) not found for BG (map: {}, instance id: {})!",
                type, BgCreatures[type].ToString(), GetMapId(), m_InstanceID);
    }
    return creature;
}

uint32 Battleground::GetMapId() const
{
    return _battlegroundTemplate->BattlemasterEntry->MapID[0];
}

void Battleground::SetBgMap(BattlegroundMap* map)
{
    m_Map = map;
    if (map)
        _pvpStatIds = sDB2Manager.GetPVPStatIDsForMap(map->GetId());
    else
        _pvpStatIds = nullptr;
}

void Battleground::SpawnBGObject(uint32 type, uint32 respawntime)
{
    if (Map* map = FindBgMap())
        if (GameObject* obj = map->GetGameObject(BgObjects[type]))
        {
            if (respawntime)
            {
                obj->SetLootState(GO_JUST_DEACTIVATED);

                if (GameObjectOverride const* goOverride = obj->GetGameObjectOverride())
                    if (goOverride->Flags & GO_FLAG_NODESPAWN)
                    {
                        // This function should be called in GameObject::Update() but in case of
                        // GO_FLAG_NODESPAWN flag the function is never called, so we call it here
                        obj->SendGameObjectDespawn();
                    }
            }
            else if (obj->getLootState() == GO_JUST_DEACTIVATED)
            {
                // Change state from GO_JUST_DEACTIVATED to GO_READY in case battleground is starting again
                obj->SetLootState(GO_READY);
            }
            obj->SetRespawnTime(respawntime);
            map->AddToMap(obj);
        }
}

Creature* Battleground::AddCreature(uint32 entry, uint32 type, float x, float y, float z, float o, TeamId /*teamId = TEAM_NEUTRAL*/, uint32 respawntime /*= 0*/, Transport* transport)
{
    // If the assert is called, means that BgCreatures must be resized!
    ASSERT(type < BgCreatures.size());

    Map* map = FindBgMap();
    if (!map)
        return nullptr;

    if (!sObjectMgr->GetCreatureTemplate(entry))
    {
        TC_LOG_ERROR("bg.battleground", "Battleground::AddCreature: creature template (entry: {}) does not exist for BG (map: {}, instance id: {})!",
            entry, GetMapId(), m_InstanceID);
        return nullptr;
    }

    if (transport)
    {
        if (Creature* creature = transport->SummonPassenger(entry, { x, y, z, o }, TEMPSUMMON_MANUAL_DESPAWN))
        {
            BgCreatures[type] = creature->GetGUID();
            return creature;
        }

        return nullptr;
    }

    Position pos = { x, y, z, o };

    Creature* creature = Creature::CreateCreature(entry, map, pos);
    if (!creature)
    {
        TC_LOG_ERROR("bg.battleground", "Battleground::AddCreature: cannot create creature (entry: {}) for BG (map: {}, instance id: {})!",
            entry, GetMapId(), m_InstanceID);
        return nullptr;
    }

    creature->SetHomePosition(pos);

    if (!map->AddToMap(creature))
    {
        delete creature;
        return nullptr;
    }

    BgCreatures[type] = creature->GetGUID();

    if (respawntime)
        creature->SetRespawnDelay(respawntime);

    return creature;
}

Creature* Battleground::AddCreature(uint32 entry, uint32 type, Position const& pos, TeamId teamId /*= TEAM_NEUTRAL*/, uint32 respawntime /*= 0*/, Transport* transport)
{
    return AddCreature(entry, type, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), teamId, respawntime, transport);
}

bool Battleground::DelCreature(uint32 type)
{
    if (!BgCreatures[type])
        return true;

    if (Creature* creature = GetBgMap()->GetCreature(BgCreatures[type]))
    {
        creature->AddObjectToRemoveList();
        BgCreatures[type].Clear();
        return true;
    }

    TC_LOG_ERROR("bg.battleground", "Battleground::DelCreature: creature (type: {}, {}) not found for BG (map: {}, instance id: {})!",
        type, BgCreatures[type].ToString(), GetMapId(), m_InstanceID);
    BgCreatures[type].Clear();
    return false;
}

bool Battleground::DelObject(uint32 type)
{
    if (!BgObjects[type])
        return true;

    if (GameObject* obj = GetBgMap()->GetGameObject(BgObjects[type]))
    {
        obj->SetRespawnTime(0);                                 // not save respawn time
        obj->Delete();
        BgObjects[type].Clear();
        return true;
    }
    TC_LOG_ERROR("bg.battleground", "Battleground::DelObject: gameobject (type: {}, {}) not found for BG (map: {}, instance id: {})!",
        type, BgObjects[type].ToString(), GetMapId(), m_InstanceID);
    BgObjects[type].Clear();
    return false;
}

bool Battleground::RemoveObjectFromWorld(uint32 type)
{
    if (!BgObjects[type])
        return true;

    if (GameObject* obj = GetBgMap()->GetGameObject(BgObjects[type]))
    {
        obj->RemoveFromWorld();
        BgObjects[type].Clear();
        return true;
    }
    TC_LOG_INFO("bg.battleground", "Battleground::RemoveObjectFromWorld: gameobject (type: {}, {}) not found for BG (map: {}, instance id: {})!",
        type, BgObjects[type].ToString(), GetMapId(), m_InstanceID);
    return false;
}

bool Battleground::AddSpiritGuide(uint32 type, float x, float y, float z, float o, TeamId teamId /*= TEAM_NEUTRAL*/)
{
    uint32 entry = (teamId == TEAM_ALLIANCE) ? BG_CREATURE_ENTRY_A_SPIRITGUIDE : BG_CREATURE_ENTRY_H_SPIRITGUIDE;

    if (AddCreature(entry, type, x, y, z, o, teamId))
        return true;

    TC_LOG_ERROR("bg.battleground", "Battleground::AddSpiritGuide: cannot create spirit guide (type: {}, entry: {}) for BG (map: {}, instance id: {})!",
        type, entry, GetMapId(), m_InstanceID);
    EndNow();
    return false;
}

bool Battleground::AddSpiritGuide(uint32 type, Position const& pos, TeamId teamId /*= TEAM_NEUTRAL*/)
{
    return AddSpiritGuide(type, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), teamId);
}

void Battleground::SendMessageToAll(uint32 entry, ChatMsg msgType, Player const* source)
{
    if (!entry)
        return;

    Trinity::TrinityStringChatBuilder builder(nullptr, msgType, entry, source);
    Trinity::LocalizedDo<Trinity::TrinityStringChatBuilder> localizer(builder);
    BroadcastWorker(localizer);
}

void Battleground::PSendMessageToAll(uint32 entry, ChatMsg msgType, Player const* source, ...)
{
    if (!entry)
        return;

    va_list ap;
    va_start(ap, source);

    Trinity::TrinityStringChatBuilder builder(nullptr, msgType, entry, source, &ap);
    Trinity::LocalizedDo<Trinity::TrinityStringChatBuilder> localizer(builder);
    BroadcastWorker(localizer);

    va_end(ap);
}

void Battleground::AddPlayerPosition(WorldPackets::Battleground::BattlegroundPlayerPosition const& position)
{
    _playerPositions.push_back(position);
}

void Battleground::RemovePlayerPosition(ObjectGuid guid)
{
    auto itr = std::remove_if(_playerPositions.begin(), _playerPositions.end(), [guid](WorldPackets::Battleground::BattlegroundPlayerPosition const& playerPosition)
    {
        return playerPosition.Guid == guid;
    });

    _playerPositions.erase(itr, _playerPositions.end());
}

void Battleground::EndNow()
{
    RemoveFromBGFreeSlotQueue();
    SetStatus(STATUS_WAIT_LEAVE);
    SetRemainingTime(0);
}

void Battleground::HandleKillPlayer(Player* victim, Player* killer)
{
    // Keep in mind that for arena this will have to be changed a bit

    // Add +1 deaths
    UpdatePlayerScore(victim, SCORE_DEATHS, 1);
    // Add +1 kills to group and +1 killing_blows to killer
    if (killer)
    {
        // Don't reward credit for killing ourselves, like fall damage of hellfire (warlock)
        if (killer == victim)
            return;

        Team killerTeam = GetPlayerTeam(killer->GetGUID());

        UpdatePlayerScore(killer, SCORE_HONORABLE_KILLS, 1);
        UpdatePlayerScore(killer, SCORE_KILLING_BLOWS, 1);

        for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        {
            Player* creditedPlayer = ObjectAccessor::FindPlayer(itr->first);
            if (!creditedPlayer || creditedPlayer == killer)
                continue;

            if (itr->second.Team == killerTeam && creditedPlayer->IsAtGroupRewardDistance(victim))
                UpdatePlayerScore(creditedPlayer, SCORE_HONORABLE_KILLS, 1);
        }
    }

    if (!isArena())
    {
        // To be able to remove insignia -- ONLY IN Battlegrounds
        victim->SetUnitFlag(UNIT_FLAG_SKINNABLE);
        RewardXPAtKill(killer, victim);
    }
}

// Return the player's team based on battlegroundplayer info
// Used in same faction arena matches mainly
Team Battleground::GetPlayerTeam(ObjectGuid guid) const
{
    BattlegroundPlayerMap::const_iterator itr = m_Players.find(guid);
    if (itr != m_Players.end())
        return itr->second.Team;
    return TEAM_OTHER;
}

Team Battleground::GetOtherTeam(Team team) const
{
    return team ? ((team == ALLIANCE) ? HORDE : ALLIANCE) : TEAM_OTHER;
}

bool Battleground::IsPlayerInBattleground(ObjectGuid guid) const
{
    BattlegroundPlayerMap::const_iterator itr = m_Players.find(guid);
    if (itr != m_Players.end())
        return true;
    return false;
}

bool Battleground::IsPlayerMercenaryInBattleground(ObjectGuid guid) const
{
    auto itr = m_Players.find(guid);
    if (itr != m_Players.end())
        return itr->second.Mercenary;
    return false;
}

void Battleground::PlayerAddedToBGCheckIfBGIsRunning(Player* player)
{
    if (GetStatus() != STATUS_WAIT_LEAVE)
        return;

    BlockMovement(player);

    WorldPackets::Battleground::PVPMatchStatisticsMessage pvpMatchStatistics;
    BuildPvPLogDataPacket(pvpMatchStatistics.Data);
    player->SendDirectMessage(pvpMatchStatistics.Write());
}

uint32 Battleground::GetAlivePlayersCountByTeam(Team team) const
{
    int count = 0;
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        if (itr->second.Team == team)
        {
            Player* player = ObjectAccessor::FindPlayer(itr->first);
            if (player && player->IsAlive())
                ++count;
        }
    }
    return count;
}

int32 Battleground::GetObjectType(ObjectGuid guid)
{
    for (uint32 i = 0; i < BgObjects.size(); ++i)
        if (BgObjects[i] == guid)
            return i;
    TC_LOG_ERROR("bg.battleground", "Battleground::GetObjectType: player used gameobject ({}) which is not in internal data for BG (map: {}, instance id: {}), cheating?",
        guid.ToString(), GetMapId(), m_InstanceID);
    return -1;
}

void Battleground::SetBgRaid(Team team, Group* bg_raid)
{
    Group*& old_raid = team == ALLIANCE ? m_BgRaids[TEAM_ALLIANCE] : m_BgRaids[TEAM_HORDE];
    if (old_raid)
        old_raid->SetBattlegroundGroup(nullptr);
    if (bg_raid)
        bg_raid->SetBattlegroundGroup(this);
    old_raid = bg_raid;
}

WorldSafeLocsEntry const* Battleground::GetClosestGraveyard(Player* player)
{
    return sObjectMgr->GetClosestGraveyard(*player, GetPlayerTeam(player->GetGUID()), player);
}

void Battleground::TriggerGameEvent(uint32 gameEventId, WorldObject* source /*= nullptr*/, WorldObject* target /*= nullptr*/)
{
    ProcessEvent(target, gameEventId, source);
    GameEvents::TriggerForMap(gameEventId, GetBgMap(), source, target);
    for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
        if (Player* player = ObjectAccessor::FindPlayer(itr->first))
            GameEvents::TriggerForPlayer(gameEventId, player);
}

void Battleground::SetBracket(PVPDifficultyEntry const* bracketEntry)
{
    _pvpDifficultyEntry = bracketEntry;
}

void Battleground::RewardXPAtKill(Player* killer, Player* victim)
{
    if (sWorld->getBoolConfig(CONFIG_BG_XP_FOR_KILL) && killer && victim)
    {
        Player* killers[] = { killer };
        KillRewarder(Trinity::IteratorPair(std::begin(killers), std::end(killers)), victim, true).Reward();
    }
}

uint32 Battleground::GetTeamScore(TeamId teamId) const
{
    if (teamId == TEAM_ALLIANCE || teamId == TEAM_HORDE)
        return m_TeamScores[teamId];

    TC_LOG_ERROR("bg.battleground", "GetTeamScore with wrong Team {} for BG {}", teamId, GetTypeID());
    return 0;
}

void Battleground::HandleAreaTrigger(Player* player, uint32 trigger, bool /*entered*/)
{
    TC_LOG_DEBUG("bg.battleground", "Unhandled AreaTrigger {} in Battleground {}. Player coords (x: {}, y: {}, z: {})",
                   trigger, player->GetMapId(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());
}

char const* Battleground::GetName() const
{
    return _battlegroundTemplate->BattlemasterEntry->Name[sWorld->GetDefaultDbcLocale()];
}

BattlegroundTypeId Battleground::GetTypeID() const
{
    return _battlegroundTemplate->Id;
}

BattlegroundBracketId Battleground::GetBracketId() const
{
    return _pvpDifficultyEntry->GetBracketId();
}

uint8 Battleground::GetUniqueBracketId() const
{
    return uint8(GetMinLevel() / 5) - 1; // 10 - 1, 15 - 2, 20 - 3, etc.
}

uint32 Battleground::GetMaxPlayers() const
{
    return GetMaxPlayersPerTeam() * 2;
}

uint32 Battleground::GetMinPlayers() const
{
    return GetMinPlayersPerTeam() * 2;
}

uint32 Battleground::GetMinLevel() const
{
    if (_pvpDifficultyEntry)
        return _pvpDifficultyEntry->MinLevel;

    return _battlegroundTemplate->GetMinLevel();
}

uint32 Battleground::GetMaxLevel() const
{
    if (_pvpDifficultyEntry)
        return _pvpDifficultyEntry->MaxLevel;

    return _battlegroundTemplate->GetMaxLevel();
}

uint32 Battleground::GetMaxPlayersPerTeam() const
{
    if (isArena())
    {
        switch (GetArenaType())
        {
            case ARENA_TYPE_2v2:
                return 2;
            case ARENA_TYPE_3v3:
                return 3;
            case ARENA_TYPE_5v5: // removed
                return 5;
            default:
                break;
        }
    }

    return _battlegroundTemplate->GetMaxPlayersPerTeam();
}

uint32 Battleground::GetMinPlayersPerTeam() const
{
    return _battlegroundTemplate->GetMinPlayersPerTeam();
}
