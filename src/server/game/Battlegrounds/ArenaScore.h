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

#ifndef TRINITY_ARENA_SCORE_H
#define TRINITY_ARENA_SCORE_H

#include "BattlegroundScore.h"
#include "SharedDefines.h"

struct ArenaScore : public BattlegroundScore
{
    friend class Arena;

    protected:
        ArenaScore(uint64 playerGuid, uint32 team) : BattlegroundScore(playerGuid), TeamId(team == ALLIANCE ? BG_TEAM_ALLIANCE : BG_TEAM_HORDE) { }

        void AppendToPacket(WorldPacket& data) final override
        {
            data << uint64(PlayerGuid);

            data << uint32(KillingBlows);
            data << uint8(TeamId);
            data << uint32(DamageDone);
            data << uint32(HealingDone);

            BuildObjectivesBlock(data);
        }

        void BuildObjectivesBlock(WorldPacket& data) final override
        {
            data << uint32(0); // Objectives Count
        }

        // For Logging purpose
        std::string ToString() const override
        {
            std::ostringstream stream;
            stream << "Damage done: " << DamageDone << ", Healing done: " << HealingDone << ", Killing blows: " << KillingBlows;
            return stream.str();
        }

        uint8 TeamId; // BattlegroundTeamId
};

struct ArenaTeamScore
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

        void BuildRatingInfoBlock(WorldPacket& data)
        {
            uint32 ratingLost = std::abs(std::min(RatingChange, 0));
            uint32 ratingWon = std::max(RatingChange, 0);

            // should be old rating, new rating, and client will calculate rating change itself
            data << uint32(ratingLost);
            data << uint32(ratingWon);
            data << uint32(MatchmakerRating);
        }

        void BuildTeamInfoBlock(WorldPacket& data)
        {
            data << TeamName;
        }

        int32 RatingChange;
        uint32 MatchmakerRating;
        std::string TeamName;
};

#endif // TRINITY_ARENA_SCORE_H
