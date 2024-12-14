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

#ifndef TRINITY_ARENA_H
#define TRINITY_ARENA_H

#include "ArenaScore.h"
#include "Battleground.h"

enum ArenaBroadcastTexts
{
    ARENA_TEXT_START_ONE_MINUTE             = 15740,
    ARENA_TEXT_START_THIRTY_SECONDS         = 15741,
    ARENA_TEXT_START_FIFTEEN_SECONDS        = 15739,
    ARENA_TEXT_START_BATTLE_HAS_BEGUN       = 15742,
};

enum ArenaSpellIds
{
    SPELL_ALLIANCE_GOLD_FLAG                = 32724,
    SPELL_ALLIANCE_GREEN_FLAG               = 32725,
    SPELL_HORDE_GOLD_FLAG                   = 35774,
    SPELL_HORDE_GREEN_FLAG                  = 35775,

    SPELL_LAST_MAN_STANDING                 = 26549  // Achievement Credit
};

enum ArenaWorldStates
{
    ARENA_WORLD_STATE_ALIVE_PLAYERS_GREEN       = 3600,
    ARENA_WORLD_STATE_ALIVE_PLAYERS_GOLD        = 3601,
    ARENA_WORLD_STATE_SHOW_ALIVE_PLAYERS        = 3610,
    ARENA_WORLD_STATE_TIME_REMAINING            = 8529,
    ARENA_WORLD_STATE_SHOW_TIME_REMAINING       = 8524,
    ARENA_WORLD_STATE_GREEN_TEAM_EXTRA_LIVES    = 15480,
    ARENA_WORLD_STATE_GOLD_TEAM_EXTRA_LIVES     = 15481,
    ARENA_WORLD_STATE_SHOW_EXTRA_LIVES          = 13401,
    ARENA_WORLD_STATE_SOLO_SHUFFLE_ROUND        = 21427,
    ARENA_WORLD_STATE_SHOW_SOLO_SHUFFLE_ROUND   = 21322,
};

class TC_GAME_API Arena : public Battleground
{
    public:
        Arena(BattlegroundTemplate const* battlegroundTemplate);
    protected:
        void AddPlayer(Player* player, BattlegroundQueueTypeId queueId) override;
        void RemovePlayer(Player* /*player*/, ObjectGuid /*guid*/, uint32 /*team*/) override;

        void UpdateArenaWorldState();

        void HandleKillPlayer(Player* player, Player* killer) override;

        void BuildPvPLogDataPacket(WorldPackets::Battleground::PVPMatchStatistics& pvpLogData) const override;

    private:
        void RemovePlayerAtLeave(ObjectGuid guid, bool transport, bool sendPacket) override;
        void CheckWinConditions() override;
        void EndBattleground(Team winner) override;

        ArenaTeamScore _arenaTeamScores[PVP_TEAMS_COUNT];
};

#endif // TRINITY_ARENA_H
