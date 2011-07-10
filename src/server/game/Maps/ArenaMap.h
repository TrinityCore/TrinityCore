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

#ifndef TRINITY_ARENA_MAP_H
#define TRINITY_ARENA_MAP_H

#include "Define.h"
#include "BattlegroundMap.h"

enum ArenaWorldStates
{
    WORLD_STATE_ARENA_TEAM_A = 0xE10,   // Amount of players alive
    WORLD_STATE_ARENA_TEAM_H = 0xE11,   // Amount of players alive
};

class ArenaTeam;
class ArenaTeamScore;
class Player;

class ArenaMap : public BattlegroundMap
{
    friend class MapManager;
    friend class WorldSession;

    protected:
        ArenaMap(uint32 id, time_t expiry, uint32 instanceId, BattlegroundTemplate const* bgTemplate) : BattlegroundMap(id, expiry, instanceId, bgTemplate) {}

        void InitializeTextIds();                   // Initializes text IDs that are used in the battleground at any possible phase.
        void InitializePreparationDelayTimes();     // Initializes preparation delay timers.

        void InstallBattleground();
        void StartBattleground();
        void DestroyBattleground();
        void EndBattleground(BattlegroundWinner winner);

        void UpdateArenaWorldState();
        void CheckArenaWinConditions();

        void OnPlayerJoin(Player* player);
        void OnPlayerExit(Player* player);
        void OnPlayerKill(Player* victim, Player* killer);

        void BuildPVPLogDataPacket(WorldPacket& data);

    private:
        Group* GetGroupForTeam(uint32 team) const;  // Needed for GetAverageMMR

        bool _rated;
        ArenaTeam* _arenaTeams[BG_TEAMS_COUNT];
        ArenaTeamScore* _arenaTeamScores[BG_TEAMS_COUNT];
        uint32 _playersAlive[BG_TEAMS_COUNT];
        
};

#endif