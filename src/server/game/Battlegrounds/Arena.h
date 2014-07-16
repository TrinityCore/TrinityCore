/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "Battleground.h"

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
    ARENA_WORLD_STATE_ALIVE_PLAYERS_GREEN   = 3600,
    ARENA_WORLD_STATE_ALIVE_PLAYERS_GOLD    = 3601
};

class Arena : public Battleground
{
    protected:
        Arena();

        void AddPlayer(Player* player) override;
        void RemovePlayer(Player* /*player*/, uint64 /*guid*/, uint32 /*team*/) override;

        void FillInitialWorldStates(WorldPacket& data) override;
        void UpdateArenaWorldState();

        void HandleKillPlayer(Player* player, Player* killer) override;

    private:
        void RemovePlayerAtLeave(uint64 guid, bool transport, bool sendPacket) override;
        void CheckWinConditions() override;
        void EndBattleground(uint32 winner) override;
};

#endif // TRINITY_ARENA_H
