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
#include <sstream>

struct TC_GAME_API ArenaScore : public BattlegroundScore
{
    friend class Arena;

    protected:
        ArenaScore(ObjectGuid playerGuid, uint32 team) : BattlegroundScore(playerGuid), TeamId(team == ALLIANCE ? PVP_TEAM_ALLIANCE : PVP_TEAM_HORDE) { }

        void AppendToPacket(WorldPacket& data) final override;
        void BuildObjectivesBlock(WorldPacket& data) final override;

        // For Logging purpose
        std::string ToString() const override
        {
            std::ostringstream stream;
            stream << "Damage done: " << DamageDone << ", Healing done: " << HealingDone << ", Killing blows: " << KillingBlows;
            return stream.str();
        }

        uint8 TeamId; // PvPTeamId
};

struct TC_GAME_API ArenaTeamScore
{
    friend class Arena;
    friend class Battleground;

    protected:
        ArenaTeamScore() : RatingChange(0), MatchmakerRating(0) { }

        virtual ~ArenaTeamScore() { }

        void Reset()
        {
            RatingChange = 0;
            MatchmakerRating = 0;
            TeamName.clear();
        }

        void Assign(int32 ratingChange, uint32 matchMakerRating, std::string const& teamName)
        {
            RatingChange = ratingChange;
            MatchmakerRating = matchMakerRating;
            TeamName = teamName;
        }

        void BuildRatingInfoBlock(WorldPacket& data);
        void BuildTeamInfoBlock(WorldPacket& data);

        int32 RatingChange;
        uint32 MatchmakerRating;
        std::string TeamName;
};

#endif // TRINITY_ARENA_SCORE_H
