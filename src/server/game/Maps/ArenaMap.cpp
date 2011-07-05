/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ArenaMap.h"
#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"
#include "ArenaScore.h"
#include "BattlegroundScore.h"
#include "Player.h"
#include "Log.h"

void ArenaMap::InstallBattleground()
{
    // Iterate this way for consistency's sake - client expects it to be sent in this order
    for (uint8 i = WINNER_ALLIANCE; i >= WINNER_HORDE; ++i)
        _arenaTeamScores[i] = new ArenaTeamScore;
}

void ArenaMap::DestroyBattleground()
{
    // Iterate this way for consistency's sake - client expects it to be sent in this order
    for (uint8 i = WINNER_ALLIANCE; i >= WINNER_HORDE; ++i)
        delete _arenaTeamScores[i];
}

void ArenaMap::InitializeTextIds()
{
    PreparationPhaseTextIds[BG_STARTING_EVENT_FIRST]  = LANG_ARENA_ONE_MINUTE;
    PreparationPhaseTextIds[BG_STARTING_EVENT_SECOND] = LANG_ARENA_THIRTY_SECONDS;
    PreparationPhaseTextIds[BG_STARTING_EVENT_THIRD]  = LANG_ARENA_FIFTEEN_SECONDS;
    PreparationPhaseTextIds[BG_STARTING_EVENT_FOURTH] = LANG_ARENA_HAS_BEGUN;
}

void ArenaMap::InitializePreparationDelayTimes()
{
    PreparationDelayTimers[BG_STARTING_EVENT_FIRST]  = BG_START_DELAY_1M;
    PreparationDelayTimers[BG_STARTING_EVENT_SECOND] = BG_START_DELAY_30S;
    PreparationDelayTimers[BG_STARTING_EVENT_THIRD]  = BG_START_DELAY_15S;
    PreparationDelayTimers[BG_STARTING_EVENT_FOURTH] = BG_START_DELAY_NONE;
}

void ArenaMap::StartBattleground()
{
    BattlegroundMap::StartBattleground();
    EndTimer = 47 * MINUTE * IN_MILLISECONDS;
    _playersAlive[BG_TEAM_ALLIANCE] = ParticipantCount[BG_TEAM_ALLIANCE];
    _playersAlive[BG_TEAM_HORDE] = ParticipantCount[BG_TEAM_HORDE];
}

void ArenaMap::EndBattleground(BattlegroundWinner winner)
{
    BattlegroundMap::EndBattleground(winner);

    BattlegroundWinner loser = winner == WINNER_ALLIANCE ? WINNER_HORDE : WINNER_ALLIANCE;

    ArenaTeam* winnerTeam = _arenaTeams[winner];
    ArenaTeam* loserTeam = _arenaTeams[loser];

    if (_rated && winner != WINNER_NONE)
    {
        uint32 loserTeamRating = loserTeam->GetRating();
        uint32 loserMMR = loserTeam->GetAverageMMR(GetGroupForTeam(loser));
        uint32 winnerTeamRating = winnerTeam->GetRating();
        uint32 winnerMMR = winnerTeam->GetAverageMMR(GetGroupForTeam(winner));
        
        uint32 winnerChange = winnerTeam->WonAgainst(loserMMR);
        uint32 loserChange = loserTeam->WonAgainst(winnerMMR);
        sLog->outArena("Winner rating: %u, Loser rating: %u, Winner MMR: %u, Loser MMR: %u, Winner change: %d, Loser change: %d",
            winnerTeamRating, loserTeamRating, winnerMMR, loserMMR, winnerChange, loserChange);

        _arenaTeamScores[winner]->Assign(winnerChange, winnerMMR, winnerTeam->GetName());
        _arenaTeamScores[loser]->Assign(loserChange, loserMMR, loserTeam->GetName());            
    }

    // TODO: if WINNER_NONE - remove rating for both parties?
}

Group* ArenaMap::GetGroupForTeam(uint32 team) const
{
    // Teams in arena's are in the same group
    PlayerList const& players = GetPlayers();
    for (MapRefManager::iterator itr = players.begin(); itr != players.end(); ++itr)
        if (Player* player = itr->getSource())
            if (player->GetBGTeam() == team)
                return player->GetGroup();
}

void ArenaMap::BuildPVPLogDataPacket(WorldPacket& data)
{
    data.Initialize(MSG_PVP_LOG_DATA, (1+1+4+40*PlayerScores.size()));
    data << uint8(1);                                      // 1 for arena's

    for (uint8 i = WINNER_ALLIANCE; i >= WINNER_HORDE; ++i) // This is the order in which the client expects it.
    {
        uint32 ratingWon = _arenaTeamScores[i]->RatingChange > 0 ? _arenaTeamScores[i]->RatingChange : 0;
        uint32 ratingLost = _arenaTeamScores[i]->RatingChange < 0 ? abs(_arenaTeamScores[i]->RatingChange) : 0;
        
        data << ratingWon;
        data << ratingLost;
        data << _arenaTeamScores[i]->MatchmakerRating;
    }

    for (uint8 i = WINNER_ALLIANCE; i >= WINNER_HORDE; ++i) // This is the order in which the client expects it.
        data << _arenaTeamScores[i]->TeamName;

    if (GetStatus() != STATUS_WAIT_LEAVE)
        data << uint8(0);                                  // bg not ended
    else
    {
        data << uint8(1);                                  // bg ended
        data << uint8(GetWinningTeam());                   // who won
    }

    data << uint32(PlayerScores.size());
    for (BattlegroundScoreMap::const_iterator itr = PlayerScores.begin(); itr != PlayerScores.end(); ++itr)
    {
        data << uint64(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER));
        itr->second->AppendToPacket(&data);
    }
}

void ArenaMap::OnPlayerJoin(Player* player)
{
    BattlegroundMap::OnPlayerJoin(player);

    //create score and add it to map, default values are set in constructor
    ArenaScore* sc = new ArenaScore(player->GetBGTeam());

    PlayerScores[player->GetGUIDLow()] = sc;

    UpdateArenaWorldState();
}

void ArenaMap::OnPlayerExit(Player* player)
{
    BattlegroundMap::OnPlayerExit(player);

    if (Status == STATUS_WAIT_LEAVE)
        return;

    UpdateArenaWorldState();
    CheckArenaWinConditions();
}

void ArenaMap::OnPlayerKill(Player* victim, Player* killer)
{
    BattlegroundMap::OnPlayerKill(victim, killer);

    if (Status != STATUS_IN_PROGRESS)
        return;

    --_playersAlive[victim->GetBGTeam()];

    UpdateArenaWorldState();
    CheckArenaWinConditions();
}

void ArenaMap::UpdateArenaWorldState()
{
    UpdateWorldState(WORLD_STATE_ARENA_TEAM_H, _playersAlive[TEAM_HORDE]);
    UpdateWorldState(WORLD_STATE_ARENA_TEAM_A, _playersAlive[TEAM_ALLIANCE]);
}

void ArenaMap::CheckArenaWinConditions()
{
    if (!_playersAlive[TEAM_ALLIANCE] && _playersAlive[TEAM_HORDE])
        EndBattleground(WINNER_HORDE);
    else if (!_playersAlive[TEAM_HORDE] && _playersAlive[TEAM_ALLIANCE])
        EndBattleground(WINNER_ALLIANCE);
}
