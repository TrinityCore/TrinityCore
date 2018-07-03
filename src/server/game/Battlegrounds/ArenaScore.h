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

#ifndef TRINITY_ARENA_SCORE_H
#define TRINITY_ARENA_SCORE_H

#include "BattlegroundScore.h"

struct TC_GAME_API ArenaScore : public BattlegroundScore
{
    friend class Arena;

    protected:
        ArenaScore(ObjectGuid playerGuid, uint32 team);

        void BuildPvPLogPlayerDataPacket(WorldPackets::Battleground::PVPLogData::PlayerData& playerData) const override;

        // For Logging purpose
        std::string ToString() const override;

        uint32 PreMatchRating = 0;
        uint32 PreMatchMMR = 0;
        uint32 PostMatchRating = 0;
        uint32 PostMatchMMR = 0;
};

struct TC_GAME_API ArenaTeamScore
{
    friend class Arena;
    friend class Battleground;

    protected:
        ArenaTeamScore();
        virtual ~ArenaTeamScore();

        void Assign(uint32 preMatchRating, uint32 postMatchRating, uint32 preMatchMMR, uint32 postMatchMMR);

        uint32 PreMatchRating = 0;
        uint32 PostMatchRating = 0;
        uint32 PreMatchMMR = 0;
        uint32 PostMatchMMR = 0;
};

#endif // TRINITY_ARENA_SCORE_H
