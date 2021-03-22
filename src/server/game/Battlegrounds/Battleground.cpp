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
#include "Formulas.h"
#include "GameTime.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Log.h"
#include "Map.h"
#include "MiscPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "SpellAuras.h"
#include "TemporarySummon.h"
#include "Transport.h"
#include "Util.h"
#include "WorldStatePackets.h"
#include <cstdarg>

template<class Do>
void Battleground::BroadcastWorker(Do& _do)
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        if (Player* player = _GetPlayer(itr, "BroadcastWorker"))
            _do(player);
}

Battleground::Battleground(BattlegroundTemplate const* battlegroundTemplate) : _battlegroundTemplate(battlegroundTemplate), _pvpDifficultyEntry(nullptr)
{
    ASSERT(_battlegroundTemplate, "Nonexisting Battleground Template passed to battleground ctor!");

    m_RandomTypeID      = BATTLEGROUND_TYPE_NONE;
    m_InstanceID        = 0;
    m_Status            = STATUS_NONE;
    m_ClientInstanceID  = 0;
    m_EndTime           = 0;
    m_LastResurrectTime = 0;
    m_InvitedAlliance   = 0;
    m_InvitedHorde      = 0;
    m_ArenaType         = 0;
    _winnerTeamId       = BG_TEAM_NEUTRAL;
    m_StartTime         = 0;
    m_CountdownTimer    = 0;
    m_ResetStatTimer    = 0;
    m_ValidStartPositionTimer = 0;
    m_Events            = 0;
    m_StartDelayTime    = 0;
    m_IsRated           = false;
    m_BuffChange        = false;
    m_IsRandom          = false;
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

    m_HonorMode = BG_NORMAL;

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
        m_Map->SetUnload();
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
                    EndBattleground(0);
                    return;
                }
            }
            else
            {
                _ProcessResurrect(diff);
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
                    TC_LOG_DEBUG("bg.battleground", "BATTLEGROUND: Sending %s back to start location (map: %u) (possible exploit)", player->GetName().c_str(), GetMapId());
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

inline void Battleground::_ProcessResurrect(uint32 diff)
{
    // *********************************************************
    // ***        BATTLEGROUND RESURRECTION SYSTEM           ***
    // *********************************************************
    // this should be handled by spell system
    m_LastResurrectTime += diff;
    if (m_LastResurrectTime >= RESURRECTION_INTERVAL)
    {
        if (GetReviveQueueSize())
        {
            for (std::map<ObjectGuid, GuidVector>::iterator itr = m_ReviveQueue.begin(); itr != m_ReviveQueue.end(); ++itr)
            {
                Creature* sh = nullptr;
                for (GuidVector::const_iterator itr2 = (itr->second).begin(); itr2 != (itr->second).end(); ++itr2)
                {
                    Player* player = ObjectAccessor::FindPlayer(*itr2);
                    if (!player)
                        continue;

                    if (!sh && player->IsInWorld())
                    {
                        sh = player->GetMap()->GetCreature(itr->first);
                        // only for visual effect
                        if (sh)
                            // Spirit Heal, effect 117
                            sh->CastSpell(sh, SPELL_SPIRIT_HEAL, true);
                    }

                    // Resurrection visual
                    player->CastSpell(player, SPELL_RESURRECTION_VISUAL, true);
                    m_ResurrectQueue.push_back(*itr2);
                }
                (itr->second).clear();
            }

            m_ReviveQueue.clear();
            m_LastResurrectTime = 0;
        }
        else
            // queue is clear and time passed, just update last resurrection time
            m_LastResurrectTime = 0;
    }
    else if (m_LastResurrectTime > 500)    // Resurrect players only half a second later, to see spirit heal effect on NPC
    {
        for (GuidVector::const_iterator itr = m_ResurrectQueue.begin(); itr != m_ResurrectQueue.end(); ++itr)
        {
            Player* player = ObjectAccessor::FindPlayer(*itr);
            if (!player)
                continue;
            player->ResurrectPlayer(1.0f);
            player->CastSpell(player, 6962, true);
            player->CastSpell(player, SPELL_SPIRIT_HEAL_MANA, true);
            player->SpawnCorpseBones(false);
        }
        m_ResurrectQueue.clear();
    }
}

uint32 Battleground::GetPrematureWinner()
{
    uint32 winner = 0;
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
        int32 countdownMaxForBGType = isArena() ? ARENA_COUNTDOWN_MAX : BATTLEGROUND_COUNTDOWN_MAX;

        WorldPackets::Misc::StartTimer startTimer;
        startTimer.Type         = 0;
        startTimer.TimeLeft     = countdownMaxForBGType - (GetElapsedTime() / 1000);
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
            TC_LOG_ERROR("bg.battleground", "Battleground::_ProcessJoin: map (map id: %u, instance id: %u) is not created!", GetMapId(), m_InstanceID);
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
                                && !aura->GetSpellInfo()->HasAttribute(SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY)
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
            TC_LOG_ERROR("bg.battleground", "Battleground::%s: player (%s) not found for BG (map: %u, instance id: %u)!",
                context, guid.ToString().c_str(), GetMapId(), m_InstanceID);
    }
    return player;
}

Player* Battleground::_GetPlayerForTeam(uint32 teamId, BattlegroundPlayerMap::const_iterator itr, char const* context) const
{
    Player* player = _GetPlayer(itr, context);
    if (player)
    {
        uint32 team = itr->second.Team;
        if (!team)
            team = player->GetTeam();
        if (team != teamId)
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

void Battleground::SendPacketToTeam(uint32 teamId, WorldPacket const* packet, Player* except /*= nullptr*/) const
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        if (Player* player = _GetPlayerForTeam(teamId, itr, "SendPacketToTeam"))
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
        TC_LOG_ERROR("bg.battleground", "Battleground::SendBroadcastText: `broadcast_text` (ID: %u) was not found", id);
        return;
    }

    Trinity::BroadcastTextBuilder builder(nullptr, msgType, id, GENDER_MALE, target);
    Trinity::LocalizedPacketDo<Trinity::BroadcastTextBuilder> localizer(builder);
    BroadcastWorker(localizer);
}

void Battleground::PlaySoundToAll(uint32 soundID)
{
    SendPacketToAll(WorldPackets::Misc::PlaySound(ObjectGuid::Empty, soundID, 0).Write());
}

void Battleground::PlaySoundToTeam(uint32 soundID, uint32 teamID)
{
    SendPacketToTeam(teamID, WorldPackets::Misc::PlaySound(ObjectGuid::Empty, soundID, 0).Write());
}

void Battleground::CastSpellOnTeam(uint32 SpellID, uint32 TeamID)
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        if (Player* player = _GetPlayerForTeam(TeamID, itr, "CastSpellOnTeam"))
            player->CastSpell(player, SpellID, true);
}

void Battleground::RemoveAuraOnTeam(uint32 SpellID, uint32 TeamID)
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        if (Player* player = _GetPlayerForTeam(TeamID, itr, "RemoveAuraOnTeam"))
            player->RemoveAura(SpellID);
}

void Battleground::RewardHonorToTeam(uint32 Honor, uint32 TeamID)
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        if (Player* player = _GetPlayerForTeam(TeamID, itr, "RewardHonorToTeam"))
            UpdatePlayerScore(player, SCORE_BONUS_HONOR, Honor);
}

void Battleground::RewardReputationToTeam(uint32 faction_id, uint32 Reputation, uint32 TeamID)
{
    FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction_id);
    if (!factionEntry)
        return;

    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        Player* player = _GetPlayerForTeam(TeamID, itr, "RewardReputationToTeam");
        if (!player)
            continue;

        uint32 repGain = Reputation;
        AddPct(repGain, player->GetTotalAuraModifier(SPELL_AURA_MOD_REPUTATION_GAIN));
        AddPct(repGain, player->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_FACTION_REPUTATION_GAIN, faction_id));
        player->GetReputationMgr().ModifyReputation(factionEntry, repGain);
    }
}

void Battleground::UpdateWorldState(uint32 variable, uint32 value, bool hidden /*= false*/)
{
    WorldPackets::WorldState::UpdateWorldState worldstate;
    worldstate.VariableID = variable;
    worldstate.Value = value;
    worldstate.Hidden = hidden;
    SendPacketToAll(worldstate.Write());
}

void Battleground::EndBattleground(uint32 winner)
{
    RemoveFromBGFreeSlotQueue();

    bool guildAwarded = false;

    if (winner == ALLIANCE)
    {
        if (isBattleground())
            SendBroadcastText(BG_TEXT_ALLIANCE_WINS, CHAT_MSG_BG_SYSTEM_NEUTRAL);

        PlaySoundToAll(SOUND_ALLIANCE_WINS);                // alliance wins sound

        SetWinner(BG_TEAM_ALLIANCE);
    }
    else if (winner == HORDE)
    {
        if (isBattleground())
            SendBroadcastText(BG_TEXT_HORDE_WINS, CHAT_MSG_BG_SYSTEM_NEUTRAL);

        PlaySoundToAll(SOUND_HORDE_WINS);                   // horde wins sound

        SetWinner(BG_TEAM_HORDE);
    }
    else
    {
        SetWinner(BG_TEAM_NEUTRAL);
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
        stmt->setUInt8(3, GetTypeID(true));
        CharacterDatabase.Execute(stmt);
    }

    SetStatus(STATUS_WAIT_LEAVE);
    //we must set it this way, because end time is sent in packet!
    SetRemainingTime(TIME_AUTOCLOSE_BATTLEGROUND);

    WorldPackets::Battleground::PVPMatchComplete pvpMatchComplete;
    pvpMatchComplete.Winner = GetWinner();
    pvpMatchComplete.Duration = std::max<int32>(0, (GetElapsedTime() - BG_START_DELAY_2M) / IN_MILLISECONDS);
    pvpMatchComplete.LogData.emplace();
    BuildPvPLogDataPacket(*pvpMatchComplete.LogData);
    pvpMatchComplete.Write();

    for (BattlegroundPlayerMap::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        uint32 team = itr->second.Team;

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
        {
            //needed cause else in av some creatures will kill the players at the end
            player->CombatStop();
            player->getHostileRefManager().deleteReferences();
        }

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
            stmt->setUInt32(9,  score->second->GetAttr1());
            stmt->setUInt32(10, score->second->GetAttr2());
            stmt->setUInt32(11, score->second->GetAttr3());
            stmt->setUInt32(12, score->second->GetAttr4());
            stmt->setUInt32(13, score->second->GetAttr5());

            CharacterDatabase.Execute(stmt);
        }

        // Reward winner team
        if (team == winner)
        {
            if (IsRandom() || BattlegroundMgr::IsBGWeekend(GetTypeID()))
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

            player->UpdateCriteria(CRITERIA_TYPE_WIN_BG, player->GetMapId());
            if (!guildAwarded)
            {
                guildAwarded = true;
                if (ObjectGuid::LowType guildId = GetBgMap()->GetOwnerGuildId(player->GetBGTeam()))
                {
                    if (Guild* guild = sGuildMgr->GetGuildById(guildId))
                        guild->UpdateCriteria(CRITERIA_TYPE_WIN_BG, player->GetMapId(), 0, 0, nullptr, player);
                }
            }
        }
        else
        {
            if (IsRandom() || BattlegroundMgr::IsBGWeekend(GetTypeID()))
                UpdatePlayerScore(player, SCORE_BONUS_HONOR, GetBonusHonorFromKill(loserKills));
        }

        player->ResetAllPowers();
        player->CombatStopWithPets(true);

        BlockMovement(player);

        player->SendDirectMessage(pvpMatchComplete.GetRawPacket());

        player->UpdateCriteria(CRITERIA_TYPE_COMPLETE_BATTLEGROUND, player->GetMapId());
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
    player->SetClientControl(player, 0);                          // movement disabled NOTE: the effect will be automatically removed by client when the player is teleported from the battleground, so no need to send with uint8(1) in RemovePlayerAtLeave()
}

void Battleground::RemovePlayerAtLeave(ObjectGuid guid, bool Transport, bool SendPacket)
{
    uint32 team = GetPlayerTeam(guid);
    bool participant = false;
    // Remove from lists/maps
    BattlegroundPlayerMap::iterator itr = m_Players.find(guid);
    if (itr != m_Players.end())
    {
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

    RemovePlayerFromResurrectQueue(guid);

    Player* player = ObjectAccessor::FindPlayer(guid);

    if (player)
    {
        // should remove spirit of redemption
        if (player->HasAuraType(SPELL_AURA_SPIRIT_OF_REDEMPTION))
            player->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);

        player->RemoveAurasByType(SPELL_AURA_MOUNTED);

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

    BattlegroundQueueTypeId bgQueueTypeId = GetQueueId();

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

            if (SendPacket)
            {
                WorldPackets::Battleground::BattlefieldStatusNone battlefieldStatus;
                sBattlegroundMgr->BuildBattlegroundStatusNone(&battlefieldStatus, player, player->GetBattlegroundQueueIndex(bgQueueTypeId), player->GetBattlegroundQueueJoinTime(bgQueueTypeId));
                player->SendDirectMessage(battlefieldStatus.Write());
            }

            // this call is important, because player, when joins to battleground, this method is not called, so it must be called when leaving bg
            player->RemoveBattlegroundQueueId(bgQueueTypeId);
        }

        // remove from raid group if player is member
        if (Group* group = GetBgRaid(team))
        {
            if (!group->RemoveMember(guid))                // group was disbanded
                SetBgRaid(team, nullptr);
        }
        DecreaseInvitedCount(team);
        //we should update battleground queue, but only if bg isn't ending
        if (isBattleground() && GetStatus() < STATUS_WAIT_LEAVE)
        {
            // a player has left the battleground, so there are free slots -> add to queue
            AddToBGFreeSlotQueue();
            sBattlegroundMgr->ScheduleQueueUpdate(0, bgQueueTypeId, GetBracketId());
        }

        // Let others know
        WorldPackets::Battleground::BattlegroundPlayerLeft playerLeft;
        playerLeft.Guid = guid;
        SendPacketToTeam(team, playerLeft.Write(), player);
    }

    if (player)
    {
        // Do next only if found in battleground
        player->SetBattlegroundId(0, BATTLEGROUND_TYPE_NONE);  // We're not in BG.
        // reset destination bg team
        player->SetBGTeam(0);

        // remove all criterias on bg leave
        player->ResetCriteria(CRITERIA_CONDITION_BG_MAP, GetMapId(), true);

        if (Transport)
            player->TeleportToBGEntryPoint();

        TC_LOG_DEBUG("bg.battleground", "Removed player %s from Battleground.", player->GetName().c_str());
    }

    //battleground object will be deleted next Battleground::Update() call
}

// this method is called when no players remains in battleground
void Battleground::Reset()
{
    SetWinner(BG_TEAM_NEUTRAL);
    SetStatus(STATUS_WAIT_QUEUE);
    SetElapsedTime(0);
    SetRemainingTime(0);
    SetLastResurrectTime(0);
    m_Events = 0;

    if (m_InvitedAlliance > 0 || m_InvitedHorde > 0)
        TC_LOG_ERROR("bg.battleground", "Battleground::Reset: one of the counters is not 0 (alliance: %u, horde: %u) for BG (map: %u, instance id: %u)!",
            m_InvitedAlliance, m_InvitedHorde, GetMapId(), m_InstanceID);

    m_InvitedAlliance = 0;
    m_InvitedHorde = 0;
    m_InBGFreeSlotQueue = false;

    m_Players.clear();

    for (BattlegroundScoreMap::const_iterator itr = PlayerScores.begin(); itr != PlayerScores.end(); ++itr)
        delete itr->second;
    PlayerScores.clear();

    ResetBGSubclass();

    _playerPositions.clear();
}

void Battleground::StartBattleground()
{
    SetElapsedTime(0);
    SetLastResurrectTime(0);
    // add BG to free slot queue
    AddToBGFreeSlotQueue();

    // add bg to update list
    // This must be done here, because we need to have already invited some players when first BG::Update() method is executed
    // and it doesn't matter if we call StartBattleground() more times, because m_Battlegrounds is a map and instance id never changes
    sBattlegroundMgr->AddBattleground(this);

    if (m_IsRated)
        TC_LOG_DEBUG("bg.arena", "Arena match type: %u for Team1Id: %u - Team2Id: %u started.", m_ArenaType, m_ArenaTeamIds[TEAM_ALLIANCE], m_ArenaTeamIds[TEAM_HORDE]);
}

void Battleground::TeleportPlayerToExploitLocation(Player* player)
{
    if (WorldSafeLocsEntry const* loc = GetExploitTeleportLocation(Team(player->GetBGTeam())))
        player->TeleportTo(loc->Loc);
}

void Battleground::AddPlayer(Player* player)
{
    // remove afk from player
    if (player->isAFK())
        player->ToggleAFK();

    // score struct must be created in inherited class

    uint32 team = player->GetBGTeam();

    BattlegroundPlayer bp;
    bp.OfflineRemoveTime = 0;
    bp.Team = team;
    bp.ActiveSpec = player->GetPrimarySpecialization();

    // Add to list/maps
    m_Players[player->GetGUID()] = bp;

    UpdatePlayersCountByTeam(team, false);                  // +1 player

    WorldPackets::Battleground::BattlegroundPlayerJoined playerJoined;
    playerJoined.Guid = player->GetGUID();
    SendPacketToTeam(team, playerJoined.Write(), player);

    WorldPackets::Battleground::PVPMatchInitialize pvpMatchInitialize;
    pvpMatchInitialize.MapID = GetMapId();
    switch (GetStatus())
    {
        case STATUS_NONE:
        case STATUS_WAIT_QUEUE:
            pvpMatchInitialize.State = WorldPackets::Battleground::PVPMatchInitialize::Inactive;
            break;
        case STATUS_WAIT_JOIN:
        case STATUS_IN_PROGRESS:
            pvpMatchInitialize.State = WorldPackets::Battleground::PVPMatchInitialize::InProgress;
            break;
        case STATUS_WAIT_LEAVE:
            pvpMatchInitialize.State = WorldPackets::Battleground::PVPMatchInitialize::Complete;
            break;
        default:
            break;
    }

    if (GetElapsedTime() >= BG_START_DELAY_2M)
    {
        pvpMatchInitialize.Duration = (GetElapsedTime() - BG_START_DELAY_2M) / IN_MILLISECONDS;
        pvpMatchInitialize.StartTime = GameTime::GetGameTime() - pvpMatchInitialize.Duration;
    }
    pvpMatchInitialize.ArenaFaction = player->GetBGTeam() == HORDE ? BG_TEAM_HORDE : BG_TEAM_ALLIANCE;
    pvpMatchInitialize.BattlemasterListID = GetTypeID();
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

            int32 countdownMaxForBGType = isArena() ? ARENA_COUNTDOWN_MAX : BATTLEGROUND_COUNTDOWN_MAX;

            WorldPackets::Misc::StartTimer startTimer;
            startTimer.Type         = 0;
            startTimer.TimeLeft     = countdownMaxForBGType - (GetElapsedTime() / 1000);
            startTimer.TotalTime    = countdownMaxForBGType;
            player->SendDirectMessage(startTimer.Write());
        }
    }

    // reset all map criterias on map enter
    player->ResetCriteria(CRITERIA_CONDITION_BG_MAP, GetMapId(), true);

    // setup BG group membership
    PlayerAddedToBGCheckIfBGIsRunning(player);
    AddOrSetPlayerToCorrectBgGroup(player, team);
}

// this method adds player to his team's bg group, or sets his correct group if player is already in bg group
void Battleground::AddOrSetPlayerToCorrectBgGroup(Player* player, uint32 team)
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
    for (GuidDeque::iterator itr = m_OfflineQueue.begin(); itr != m_OfflineQueue.end(); ++itr)
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

        // 1 player is logging out, if it is the last, then end arena!
        if (isArena())
            if (GetAlivePlayersCountByTeam(player->GetBGTeam()) <= 1 && GetPlayersCountByTeam(GetOtherTeam(player->GetBGTeam())))
                EndBattleground(GetOtherTeam(player->GetBGTeam()));
    }
}

// This method should be called only once ... it adds pointer to queue
void Battleground::AddToBGFreeSlotQueue()
{
    if (!m_InBGFreeSlotQueue && isBattleground())
    {
        sBattlegroundMgr->AddToBGFreeSlotQueue(GetQueueId(), this);
        m_InBGFreeSlotQueue = true;
    }
}

// This method removes this battleground from free queue - it must be called when deleting battleground
void Battleground::RemoveFromBGFreeSlotQueue()
{
    if (m_InBGFreeSlotQueue)
    {
        sBattlegroundMgr->RemoveFromBGFreeSlotQueue(GetQueueId(), m_InstanceID);
        m_InBGFreeSlotQueue = false;
    }
}

// get the number of free slots for team
// returns the number how many players can join battleground to MaxPlayersPerTeam
uint32 Battleground::GetFreeSlotsForTeam(uint32 Team) const
{
    // if BG is starting and CONFIG_BATTLEGROUND_INVITATION_TYPE == BG_QUEUE_INVITATION_TYPE_NO_BALANCE, invite anyone
    if (GetStatus() == STATUS_WAIT_JOIN && sWorld->getIntConfig(CONFIG_BATTLEGROUND_INVITATION_TYPE) == BG_QUEUE_INVITATION_TYPE_NO_BALANCE)
        return (GetInvitedCount(Team) < GetMaxPlayersPerTeam()) ? GetMaxPlayersPerTeam() - GetInvitedCount(Team) : 0;

    // if BG is already started or CONFIG_BATTLEGROUND_INVITATION_TYPE != BG_QUEUE_INVITATION_TYPE_NO_BALANCE, do not allow to join too much players of one faction
    uint32 otherTeamInvitedCount;
    uint32 thisTeamInvitedCount;
    uint32 otherTeamPlayersCount;
    uint32 thisTeamPlayersCount;

    if (Team == ALLIANCE)
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
        WorldPackets::Battleground::PVPMatchStatistics::PVPMatchPlayerStatistics playerData;
        score.second->BuildPvPLogPlayerDataPacket(playerData);

        if (Player* player = ObjectAccessor::GetPlayer(GetBgMap(), playerData.PlayerGUID))
        {
            playerData.IsInWorld = true;
            playerData.PrimaryTalentTree = player->GetPrimarySpecialization();
            playerData.Sex = player->getGender();
            playerData.Race = player->getRace();
            playerData.Class = player->getClass();
            playerData.HonorLevel = player->GetHonorLevel();
        }

        pvpLogData.Statistics.push_back(playerData);
    }

    pvpLogData.PlayerCount[BG_TEAM_HORDE] = int8(GetPlayersCountByTeam(HORDE));
    pvpLogData.PlayerCount[BG_TEAM_ALLIANCE] = int8(GetPlayersCountByTeam(ALLIANCE));
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

void Battleground::AddPlayerToResurrectQueue(ObjectGuid npc_guid, ObjectGuid player_guid)
{
    m_ReviveQueue[npc_guid].push_back(player_guid);

    Player* player = ObjectAccessor::FindPlayer(player_guid);
    if (!player)
        return;

    player->CastSpell(player, SPELL_WAITING_FOR_RESURRECT, true);
}

void Battleground::RemovePlayerFromResurrectQueue(ObjectGuid player_guid)
{
    for (std::map<ObjectGuid, GuidVector>::iterator itr = m_ReviveQueue.begin(); itr != m_ReviveQueue.end(); ++itr)
    {
        for (GuidVector::iterator itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
        {
            if (*itr2 == player_guid)
            {
                itr->second.erase(itr2);
                if (Player* player = ObjectAccessor::FindPlayer(player_guid))
                    player->RemoveAurasDueToSpell(SPELL_WAITING_FOR_RESURRECT);
                return;
            }
        }
    }
}

void Battleground::RelocateDeadPlayers(ObjectGuid guideGuid)
{
    // Those who are waiting to resurrect at this node are taken to the closest own node's graveyard
    GuidVector& ghostList = m_ReviveQueue[guideGuid];
    if (!ghostList.empty())
    {
        WorldSafeLocsEntry const* closestGrave = nullptr;
        for (GuidVector::const_iterator itr = ghostList.begin(); itr != ghostList.end(); ++itr)
        {
            Player* player = ObjectAccessor::FindPlayer(*itr);
            if (!player)
                continue;

            if (!closestGrave)
                closestGrave = GetClosestGraveyard(player);

            if (closestGrave)
                player->TeleportTo(closestGrave->Loc);
        }
        ghostList.clear();
    }
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
        TC_LOG_DEBUG("bg.battleground", "Battleground::AddObject: gameoobject [entry: %u, object type: %u] for BG (map: %u) has zeroed rotation fields, "
            "orientation used temporally, but please fix the spawn", entry, type, GetMapId());

        rot = QuaternionData::fromEulerAnglesZYX(o, 0.f, 0.f);
    }

    // Must be created this way, adding to godatamap would add it to the base map of the instance
    // and when loading it (in go::LoadFromDB()), a new guid would be assigned to the object, and a new object would be created
    // So we must create it specific for this instance
    GameObject* go = GameObject::CreateGameObject(entry, GetBgMap(), Position(x, y, z, o), rot, 255, goState);
    if (!go)
    {
        TC_LOG_ERROR("bg.battleground", "Battleground::AddObject: cannot create gameobject (entry: %u) for BG (map: %u, instance id: %u)!",
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
        TC_LOG_ERROR("bg.battleground", "Battleground::DoorClose: door gameobject (type: %u, %s) not found for BG (map: %u, instance id: %u)!",
            type, BgObjects[type].ToString().c_str(), GetMapId(), m_InstanceID);
}

void Battleground::DoorOpen(uint32 type)
{
    if (GameObject* obj = GetBgMap()->GetGameObject(BgObjects[type]))
    {
        obj->SetLootState(GO_ACTIVATED);
        obj->SetGoState(GO_STATE_ACTIVE);
    }
    else
        TC_LOG_ERROR("bg.battleground", "Battleground::DoorOpen: door gameobject (type: %u, %s) not found for BG (map: %u, instance id: %u)!",
            type, BgObjects[type].ToString().c_str(), GetMapId(), m_InstanceID);
}

GameObject* Battleground::GetBGObject(uint32 type, bool logError)
{
    GameObject* obj = GetBgMap()->GetGameObject(BgObjects[type]);
    if (!obj)
    {
        if (logError)
            TC_LOG_ERROR("bg.battleground", "Battleground::GetBGObject: gameobject (type: %u, %s) not found for BG (map: %u, instance id: %u)!",
                type, BgObjects[type].ToString().c_str(), GetMapId(), m_InstanceID);
        else
            TC_LOG_INFO("bg.battleground", "Battleground::GetBGObject: gameobject (type: %u, %s) not found for BG (map: %u, instance id: %u)!",
                type, BgObjects[type].ToString().c_str(), GetMapId(), m_InstanceID);
    }
    return obj;
}

Creature* Battleground::GetBGCreature(uint32 type, bool logError)
{
    Creature* creature = GetBgMap()->GetCreature(BgCreatures[type]);
    if (!creature)
    {
        if (logError)
            TC_LOG_ERROR("bg.battleground", "Battleground::GetBGCreature: creature (type: %u, %s) not found for BG (map: %u, instance id: %u)!",
                type, BgCreatures[type].ToString().c_str(), GetMapId(), m_InstanceID);
        else
            TC_LOG_INFO("bg.battleground", "Battleground::GetBGCreature: creature (type: %u, %s) not found for BG (map: %u, instance id: %u)!",
                type, BgCreatures[type].ToString().c_str(), GetMapId(), m_InstanceID);
    }
    return creature;
}

uint32 Battleground::GetMapId() const
{
    return _battlegroundTemplate->BattlemasterEntry->MapID[0];
}

void Battleground::SpawnBGObject(uint32 type, uint32 respawntime)
{
    if (Map* map = FindBgMap())
        if (GameObject* obj = map->GetGameObject(BgObjects[type]))
        {
            if (respawntime)
                obj->SetLootState(GO_JUST_DEACTIVATED);
            else
                if (obj->getLootState() == GO_JUST_DEACTIVATED)
                    // Change state from GO_JUST_DEACTIVATED to GO_READY in case battleground is starting again
                    obj->SetLootState(GO_READY);
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
        TC_LOG_ERROR("bg.battleground", "Battleground::AddCreature: creature template (entry: %u) does not exist for BG (map: %u, instance id: %u)!",
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
        TC_LOG_ERROR("bg.battleground", "Battleground::AddCreature: cannot create creature (entry: %u) for BG (map: %u, instance id: %u)!",
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

    TC_LOG_ERROR("bg.battleground", "Battleground::DelCreature: creature (type: %u, %s) not found for BG (map: %u, instance id: %u)!",
        type, BgCreatures[type].ToString().c_str(), GetMapId(), m_InstanceID);
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
    TC_LOG_ERROR("bg.battleground", "Battleground::DelObject: gameobject (type: %u, %s) not found for BG (map: %u, instance id: %u)!",
        type, BgObjects[type].ToString().c_str(), GetMapId(), m_InstanceID);
    BgObjects[type].Clear();
    return false;
}

bool Battleground::AddSpiritGuide(uint32 type, float x, float y, float z, float o, TeamId teamId /*= TEAM_NEUTRAL*/)
{
    uint32 entry = (teamId == TEAM_ALLIANCE) ? BG_CREATURE_ENTRY_A_SPIRITGUIDE : BG_CREATURE_ENTRY_H_SPIRITGUIDE;

    if (Creature* creature = AddCreature(entry, type, x, y, z, o, teamId))
    {
        creature->setDeathState(DEAD);
        creature->AddChannelObject(creature->GetGUID());
        // aura
        /// @todo Fix display here
        // creature->SetVisibleAura(0, SPELL_SPIRIT_HEAL_CHANNEL);
        // casting visual effect
        creature->SetChannelSpellId(SPELL_SPIRIT_HEAL_CHANNEL);
        creature->SetChannelVisual({ VISUAL_SPIRIT_HEAL_CHANNEL, 0 });
        //creature->CastSpell(creature, SPELL_SPIRIT_HEAL_CHANNEL, true);
        return true;
    }
    TC_LOG_ERROR("bg.battleground", "Battleground::AddSpiritGuide: cannot create spirit guide (type: %u, entry: %u) for BG (map: %u, instance id: %u)!",
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
    Trinity::LocalizedPacketDo<Trinity::TrinityStringChatBuilder> localizer(builder);
    BroadcastWorker(localizer);
}

void Battleground::PSendMessageToAll(uint32 entry, ChatMsg msgType, Player const* source, ...)
{
    if (!entry)
        return;

    va_list ap;
    va_start(ap, source);

    Trinity::TrinityStringChatBuilder builder(nullptr, msgType, entry, source, &ap);
    Trinity::LocalizedPacketDo<Trinity::TrinityStringChatBuilder> localizer(builder);
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

// IMPORTANT NOTICE:
// buffs aren't spawned/despawned when players captures anything
// buffs are in their positions when battleground starts
void Battleground::HandleTriggerBuff(ObjectGuid go_guid)
{
    GameObject* obj = GetBgMap()->GetGameObject(go_guid);
    if (!obj || obj->GetGoType() != GAMEOBJECT_TYPE_TRAP || !obj->isSpawned())
        return;

    // Change buff type, when buff is used:
    int32 index = BgObjects.size() - 1;
    while (index >= 0 && BgObjects[index] != go_guid)
        index--;
    if (index < 0)
    {
        TC_LOG_ERROR("bg.battleground", "Battleground::HandleTriggerBuff: cannot find buff gameobject (%s, entry: %u, type: %u) in internal data for BG (map: %u, instance id: %u)!",
            go_guid.ToString().c_str(), obj->GetEntry(), obj->GetGoType(), GetMapId(), m_InstanceID);
        return;
    }

    // Randomly select new buff
    uint8 buff = urand(0, 2);
    uint32 entry = obj->GetEntry();
    if (m_BuffChange && entry != Buff_Entries[buff])
    {
        // Despawn current buff
        SpawnBGObject(index, RESPAWN_ONE_DAY);
        // Set index for new one
        for (uint8 currBuffTypeIndex = 0; currBuffTypeIndex < 3; ++currBuffTypeIndex)
            if (entry == Buff_Entries[currBuffTypeIndex])
            {
                index -= currBuffTypeIndex;
                index += buff;
            }
    }

    SpawnBGObject(index, BUFF_RESPAWN_TIME);
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

        UpdatePlayerScore(killer, SCORE_HONORABLE_KILLS, 1);
        UpdatePlayerScore(killer, SCORE_KILLING_BLOWS, 1);

        for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        {
            Player* creditedPlayer = ObjectAccessor::FindPlayer(itr->first);
            if (!creditedPlayer || creditedPlayer == killer)
                continue;

            if (creditedPlayer->GetTeam() == killer->GetTeam() && creditedPlayer->IsAtGroupRewardDistance(victim))
                UpdatePlayerScore(creditedPlayer, SCORE_HONORABLE_KILLS, 1);
        }
    }

    if (!isArena())
    {
        // To be able to remove insignia -- ONLY IN Battlegrounds
        victim->AddUnitFlag(UNIT_FLAG_SKINNABLE);
        RewardXPAtKill(killer, victim);
    }
}

// Return the player's team based on battlegroundplayer info
// Used in same faction arena matches mainly
uint32 Battleground::GetPlayerTeam(ObjectGuid guid) const
{
    BattlegroundPlayerMap::const_iterator itr = m_Players.find(guid);
    if (itr != m_Players.end())
        return itr->second.Team;
    return 0;
}

uint32 Battleground::GetOtherTeam(uint32 teamId) const
{
    return teamId ? ((teamId == ALLIANCE) ? HORDE : ALLIANCE) : 0;
}

bool Battleground::IsPlayerInBattleground(ObjectGuid guid) const
{
    BattlegroundPlayerMap::const_iterator itr = m_Players.find(guid);
    if (itr != m_Players.end())
        return true;
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

uint32 Battleground::GetAlivePlayersCountByTeam(uint32 Team) const
{
    int count = 0;
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        if (itr->second.Team == Team)
        {
            Player* player = ObjectAccessor::FindPlayer(itr->first);
            if (player && player->IsAlive())
                ++count;
        }
    }
    return count;
}

void Battleground::SetHoliday(bool is_holiday)
{
    m_HonorMode = is_holiday ? BG_HOLIDAY : BG_NORMAL;
}

int32 Battleground::GetObjectType(ObjectGuid guid)
{
    for (uint32 i = 0; i < BgObjects.size(); ++i)
        if (BgObjects[i] == guid)
            return i;
    TC_LOG_ERROR("bg.battleground", "Battleground::GetObjectType: player used gameobject (%s) which is not in internal data for BG (map: %u, instance id: %u), cheating?",
        guid.ToString().c_str(), GetMapId(), m_InstanceID);
    return -1;
}

void Battleground::SetBgRaid(uint32 TeamID, Group* bg_raid)
{
    Group*& old_raid = TeamID == ALLIANCE ? m_BgRaids[TEAM_ALLIANCE] : m_BgRaids[TEAM_HORDE];
    if (old_raid)
        old_raid->SetBattlegroundGroup(nullptr);
    if (bg_raid)
        bg_raid->SetBattlegroundGroup(this);
    old_raid = bg_raid;
}

WorldSafeLocsEntry const* Battleground::GetClosestGraveyard(Player* player)
{
    return sObjectMgr->GetClosestGraveyard(*player, player->GetTeam(), player);
}

void Battleground::StartCriteriaTimer(CriteriaTimedTypes type, uint32 entry)
{
    for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
        if (Player* player = ObjectAccessor::FindPlayer(itr->first))
            player->StartCriteriaTimer(type, entry);
}

void Battleground::SetBracket(PVPDifficultyEntry const* bracketEntry)
{
    _pvpDifficultyEntry = bracketEntry;
}

void Battleground::RewardXPAtKill(Player* killer, Player* victim)
{
    if (sWorld->getBoolConfig(CONFIG_BG_XP_FOR_KILL) && killer && victim)
        killer->RewardPlayerAndGroupAtKill(victim, true);
}

uint32 Battleground::GetTeamScore(uint32 teamId) const
{
    if (teamId == TEAM_ALLIANCE || teamId == TEAM_HORDE)
        return m_TeamScores[teamId];

    TC_LOG_ERROR("bg.battleground", "GetTeamScore with wrong Team %u for BG %u", teamId, GetTypeID());
    return 0;
}

void Battleground::HandleAreaTrigger(Player* player, uint32 trigger, bool /*entered*/)
{
    TC_LOG_DEBUG("bg.battleground", "Unhandled AreaTrigger %u in Battleground %u. Player coords (x: %f, y: %f, z: %f)",
                   trigger, player->GetMapId(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());
}

bool Battleground::CheckAchievementCriteriaMeet(uint32 criteriaId, Player const* /*source*/, Unit const* /*target*/, uint32 /*miscvalue1*/)
{
    TC_LOG_ERROR("bg.battleground", "Battleground::CheckAchievementCriteriaMeet: No implementation for criteria %u", criteriaId);
    return false;
}

char const* Battleground::GetName() const
{
    return _battlegroundTemplate->BattlemasterEntry->Name[sWorld->GetDefaultDbcLocale()];
}

BattlegroundTypeId Battleground::GetTypeID(bool getRandom) const
{
    return getRandom ? m_RandomTypeID : _battlegroundTemplate->Id;
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
