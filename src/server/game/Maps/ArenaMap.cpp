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
#include "Player.h"
#include "Log.h"

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

void ArenaMap::EndBattleground(uint32 winner)
{
    BattlegroundMap::EndBattleground();

    uint32 loser = 1 - winner;

    ArenaTeam* winnerTeam = _arenaTeams[winner];
    ArenaTeam* loserTeam = _arenaTeams[loser];

    if (_rated && winner != WINNER_NONE)
    {
        uint32 loserTeamRating = loserTeam->GetRating();
        uint32 loserMMR = loserTeam->GetAverageMMR(GetGroupForTeam(loserTeam));
        uint32 winnerTeamRating = winnerTeam->GetRating();
        uint32 winnerMMR = winnerTeam->GetAverageMMR(GetGroupForTeam(winnerTeam));
        
        uint32 winnerChange = winnerTeam->WonAgainst(loserMMR);
        uint32 loserChange = loserTeam->WonAgainst(winnerMMR);
        sLog->outArena("Winner rating: %u, Loser rating: %u, Winner MMR: %u, Loser MMR: %u, Winner change: %d, Loser change: %d ---",
            winnerTeamRating, loserTeamRating, winnerMMR, loserMMR, winnerChange, loserChange);

    }
}

Group* ArenaMap::GetGroupForTeam(uint32 team) const
{
    for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        if (Player* player = itr->getSource())
            if (player->GetBGTeam() == winner)
                return player->GetGroup();
}
