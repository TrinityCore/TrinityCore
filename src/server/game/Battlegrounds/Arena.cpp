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

#include "Arena.h"
#include "ArenaTeamMgr.h"
#include "BattlegroundPackets.h"
#include "BattlegroundScore.h"
#include "GuildMgr.h"
#include "Guild.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "World.h"
#include "WorldSession.h"

Arena::Arena(BattlegroundTemplate const* battlegroundTemplate) : Battleground(battlegroundTemplate)
{
    StartDelayTimes[BG_STARTING_EVENT_FIRST]  = BG_START_DELAY_1M;
    StartDelayTimes[BG_STARTING_EVENT_SECOND] = BG_START_DELAY_30S;
    StartDelayTimes[BG_STARTING_EVENT_THIRD]  = BG_START_DELAY_15S;
    StartDelayTimes[BG_STARTING_EVENT_FOURTH] = BG_START_DELAY_NONE;

    StartMessageIds[BG_STARTING_EVENT_FIRST]  = ARENA_TEXT_START_ONE_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_SECOND] = ARENA_TEXT_START_THIRTY_SECONDS;
    StartMessageIds[BG_STARTING_EVENT_THIRD]  = ARENA_TEXT_START_FIFTEEN_SECONDS;
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = ARENA_TEXT_START_BATTLE_HAS_BEGUN;
}

void Arena::AddPlayer(Player* player, BattlegroundQueueTypeId queueId)
{
    Battleground::AddPlayer(player, queueId);

    if (player->GetBGTeam() == ALLIANCE)        // gold
    {
        if (player->GetEffectiveTeam() == HORDE)
            player->CastSpell(player, SPELL_HORDE_GOLD_FLAG, true);
        else
            player->CastSpell(player, SPELL_ALLIANCE_GOLD_FLAG, true);
    }
    else                                        // green
    {
        if (player->GetEffectiveTeam() == HORDE)
            player->CastSpell(player, SPELL_HORDE_GREEN_FLAG, true);
        else
            player->CastSpell(player, SPELL_ALLIANCE_GREEN_FLAG, true);
    }

    UpdateArenaWorldState();
}

void Arena::RemovePlayer(Player* /*player*/, ObjectGuid /*guid*/, uint32 /*team*/)
{
    if (GetStatus() == STATUS_WAIT_LEAVE)
        return;

    UpdateArenaWorldState();
    CheckWinConditions();
}

void Arena::UpdateArenaWorldState()
{
    UpdateWorldState(ARENA_WORLD_STATE_ALIVE_PLAYERS_GREEN, GetAlivePlayersCountByTeam(HORDE));
    UpdateWorldState(ARENA_WORLD_STATE_ALIVE_PLAYERS_GOLD, GetAlivePlayersCountByTeam(ALLIANCE));
}

void Arena::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    Battleground::HandleKillPlayer(player, killer);

    UpdateArenaWorldState();
    CheckWinConditions();
}

void Arena::BuildPvPLogDataPacket(WorldPackets::Battleground::PVPMatchStatistics& pvpLogData) const
{
    Battleground::BuildPvPLogDataPacket(pvpLogData);

    if (isRated())
    {
        pvpLogData.Ratings.emplace();

        for (uint8 i = 0; i < PVP_TEAMS_COUNT; ++i)
        {
            pvpLogData.Ratings->Postmatch[i] = _arenaTeamScores[i].PostMatchRating;
            pvpLogData.Ratings->Prematch[i] = _arenaTeamScores[i].PreMatchRating;
            pvpLogData.Ratings->PrematchMMR[i] = _arenaTeamScores[i].PreMatchMMR;
        }
    }
}

void Arena::RemovePlayerAtLeave(ObjectGuid guid, bool transport, bool sendPacket)
{
    if (isRated() && GetStatus() == STATUS_IN_PROGRESS)
    {
        BattlegroundPlayerMap::const_iterator itr = m_Players.find(guid);
        if (itr != m_Players.end()) // check if the player was a participant of the match, or only entered through gm command (appear)
        {
            // if the player was a match participant, calculate rating
            Team team = itr->second.Team;

            ArenaTeam* winnerArenaTeam = sArenaTeamMgr->GetArenaTeamById(GetArenaTeamIdForTeam(GetOtherTeam(team)));
            ArenaTeam* loserArenaTeam = sArenaTeamMgr->GetArenaTeamById(GetArenaTeamIdForTeam(team));

            // left a rated match while the encounter was in progress, consider as loser
            if (winnerArenaTeam && loserArenaTeam && winnerArenaTeam != loserArenaTeam)
            {
                if (Player* player = _GetPlayer(itr->first, itr->second.OfflineRemoveTime != 0, "Arena::RemovePlayerAtLeave"))
                    loserArenaTeam->MemberLost(player, GetArenaMatchmakerRating(GetOtherTeam(team)));
                else
                    loserArenaTeam->OfflineMemberLost(guid, GetArenaMatchmakerRating(GetOtherTeam(team)));
            }
        }
    }

    // remove player
    Battleground::RemovePlayerAtLeave(guid, transport, sendPacket);
}

void Arena::CheckWinConditions()
{
    if (!GetAlivePlayersCountByTeam(ALLIANCE) && GetPlayersCountByTeam(HORDE))
        EndBattleground(HORDE);
    else if (GetPlayersCountByTeam(ALLIANCE) && !GetAlivePlayersCountByTeam(HORDE))
        EndBattleground(ALLIANCE);
}

void Arena::EndBattleground(Team winner)
{
    // arena rating calculation
    if (isRated())
    {
        uint32 loserTeamRating        = 0;
        uint32 loserMatchmakerRating  = 0;
        int32  loserChange            = 0;
        int32  loserMatchmakerChange  = 0;
        uint32 winnerTeamRating       = 0;
        uint32 winnerMatchmakerRating = 0;
        int32  winnerChange           = 0;
        int32  winnerMatchmakerChange = 0;
        bool   guildAwarded           = false;

        // In case of arena draw, follow this logic:
        // winnerArenaTeam => ALLIANCE, loserArenaTeam => HORDE
        ArenaTeam* winnerArenaTeam = sArenaTeamMgr->GetArenaTeamById(GetArenaTeamIdForTeam(winner == TEAM_OTHER ? ALLIANCE : winner));
        ArenaTeam* loserArenaTeam = sArenaTeamMgr->GetArenaTeamById(GetArenaTeamIdForTeam(winner == TEAM_OTHER ? HORDE : GetOtherTeam(winner)));

        if (winnerArenaTeam && loserArenaTeam && winnerArenaTeam != loserArenaTeam)
        {
            // In case of arena draw, follow this logic:
            // winnerMatchmakerRating => ALLIANCE, loserMatchmakerRating => HORDE
            loserTeamRating = loserArenaTeam->GetRating();
            loserMatchmakerRating = GetArenaMatchmakerRating(winner == TEAM_OTHER ? HORDE : GetOtherTeam(winner));
            winnerTeamRating = winnerArenaTeam->GetRating();
            winnerMatchmakerRating = GetArenaMatchmakerRating(winner == TEAM_OTHER ? ALLIANCE : winner);

            if (winner != 0)
            {
                winnerMatchmakerChange = winnerArenaTeam->WonAgainst(winnerMatchmakerRating, loserMatchmakerRating, winnerChange);
                loserMatchmakerChange = loserArenaTeam->LostAgainst(loserMatchmakerRating, winnerMatchmakerRating, loserChange);

                TC_LOG_DEBUG("bg.arena", "match Type: {} --- Winner: old rating: {}, rating gain: {}, old MMR: {}, MMR gain: {} --- Loser: old rating: {}, rating loss: {}, old MMR: {}, MMR loss: {} ---",
                    GetArenaType(), winnerTeamRating, winnerChange, winnerMatchmakerRating, winnerMatchmakerChange,
                    loserTeamRating, loserChange, loserMatchmakerRating, loserMatchmakerChange);

                SetArenaMatchmakerRating(winner, winnerMatchmakerRating + winnerMatchmakerChange);
                SetArenaMatchmakerRating(GetOtherTeam(winner), loserMatchmakerRating + loserMatchmakerChange);

                // bg team that the client expects is different to TeamId
                // alliance 1, horde 0
                uint8 winnerTeam = winner == ALLIANCE ? PVP_TEAM_ALLIANCE : PVP_TEAM_HORDE;
                uint8 loserTeam = winner == ALLIANCE ? PVP_TEAM_HORDE : PVP_TEAM_ALLIANCE;

                _arenaTeamScores[winnerTeam].Assign(winnerTeamRating, winnerTeamRating + winnerChange, winnerMatchmakerRating, GetArenaMatchmakerRating(winner));
                _arenaTeamScores[loserTeam].Assign(loserTeamRating, loserTeamRating + loserChange, loserMatchmakerRating, GetArenaMatchmakerRating(GetOtherTeam(winner)));

                TC_LOG_DEBUG("bg.arena", "Arena match Type: {} for Team1Id: {} - Team2Id: {} ended. WinnerTeamId: {}. Winner rating: +{}, Loser rating: {}",
                    GetArenaType(), GetArenaTeamIdByIndex(TEAM_ALLIANCE), GetArenaTeamIdByIndex(TEAM_HORDE), winnerArenaTeam->GetId(), winnerChange, loserChange);

                if (sWorld->getBoolConfig(CONFIG_ARENA_LOG_EXTENDED_INFO))
                    for (auto const& score : PlayerScores)
                        if (Player* player = ObjectAccessor::FindConnectedPlayer(score.first))
                        {
                            TC_LOG_DEBUG("bg.arena", "Statistics match Type: {} for {} ({}, Team: {}, IP: {}): {}",
                                GetArenaType(), player->GetName(), score.first.ToString(), player->GetArenaTeamId(GetArenaType() == 5 ? 2 : GetArenaType() == 3),
                                player->GetSession()->GetRemoteAddress(), score.second->ToString());
                        }
            }
            // Deduct 16 points from each teams arena-rating if there are no winners after 45+2 minutes
            else
            {
                _arenaTeamScores[PVP_TEAM_ALLIANCE].Assign(winnerTeamRating, winnerTeamRating + ARENA_TIMELIMIT_POINTS_LOSS, winnerMatchmakerRating, GetArenaMatchmakerRating(ALLIANCE));
                _arenaTeamScores[PVP_TEAM_HORDE].Assign(loserTeamRating, loserTeamRating + ARENA_TIMELIMIT_POINTS_LOSS, loserMatchmakerRating, GetArenaMatchmakerRating(HORDE));

                winnerArenaTeam->FinishGame(ARENA_TIMELIMIT_POINTS_LOSS);
                loserArenaTeam->FinishGame(ARENA_TIMELIMIT_POINTS_LOSS);
            }

            uint8 aliveWinners = GetAlivePlayersCountByTeam(winner);

            for (auto const& i : GetPlayers())
            {
                Team team = i.second.Team;

                if (i.second.OfflineRemoveTime)
                {
                    // if rated arena match - make member lost!
                    if (team == winner)
                        winnerArenaTeam->OfflineMemberLost(i.first, loserMatchmakerRating, winnerMatchmakerChange);
                    else
                    {
                        if (winner == 0)
                            winnerArenaTeam->OfflineMemberLost(i.first, loserMatchmakerRating, winnerMatchmakerChange);

                        loserArenaTeam->OfflineMemberLost(i.first, winnerMatchmakerRating, loserMatchmakerChange);
                    }
                    continue;
                }

                Player* player = _GetPlayer(i.first, i.second.OfflineRemoveTime != 0, "Arena::EndBattleground");
                if (!player)
                    continue;

                player->UpdateCriteria(CriteriaType::ParticipateInArena, GetMapId());

                // per player calculation
                if (team == winner)
                {
                    // update achievement BEFORE personal rating update
                    uint32 rating = player->GetArenaPersonalRating(winnerArenaTeam->GetSlot());
                    player->StartCriteria(CriteriaStartEvent::WinRankedArenaMatchWithTeamSize, 0);
                    player->UpdateCriteria(CriteriaType::WinAnyRankedArena, rating ? rating : 1);
                    player->UpdateCriteria(CriteriaType::WinArena, GetMapId());

                    // Last standing - Rated 5v5 arena & be solely alive player
                    if (GetArenaType() == ARENA_TYPE_5v5 && aliveWinners == 1 && player->IsAlive())
                        player->CastSpell(player, SPELL_LAST_MAN_STANDING, true);

                    if (!guildAwarded)
                    {
                        guildAwarded = true;
                        if (ObjectGuid::LowType guildId = GetBgMap()->GetOwnerGuildId(player->GetBGTeam()))
                            if (Guild* guild = sGuildMgr->GetGuildById(guildId))
                                guild->UpdateCriteria(CriteriaType::WinAnyRankedArena, std::max<uint32>(winnerArenaTeam->GetRating(), 1), 0, 0, nullptr, player);
                    }

                    winnerArenaTeam->MemberWon(player, loserMatchmakerRating, winnerMatchmakerChange);
                }
                else
                {
                    if (winner == 0)
                        winnerArenaTeam->MemberLost(player, loserMatchmakerRating, winnerMatchmakerChange);

                    loserArenaTeam->MemberLost(player, winnerMatchmakerRating, loserMatchmakerChange);

                    // Arena lost => reset the win_rated_arena having the "no_lose" condition
                    player->FailCriteria(CriteriaFailEvent::LoseRankedArenaMatchWithTeamSize, 0);
                }
            }

            // save the stat changes
            winnerArenaTeam->SaveToDB();
            loserArenaTeam->SaveToDB();
            // send updated arena team stats to players
            // this way all arena team members will get notified, not only the ones who participated in this match
            winnerArenaTeam->NotifyStatsChanged();
            loserArenaTeam->NotifyStatsChanged();
        }
    }

    // end battleground
    Battleground::EndBattleground(winner);
}
