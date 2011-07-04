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

#ifndef TRINITY_ARENA_SCORE_H
#define TRINITY_ARENA_SCORE_H

#include "BattlegroundScore.h"

class ArenaMap;

class ArenaScore : public BattlegroundScore
{
    friend class ArenaMap;
    protected:
        ArenaScore(uint32 team) : BattlegroundScore(), TeamId(team) {};
        virtual ~ArenaScore() {};
        void AppendToPacket(WorldPacket* data) 
        {
            *data << KillingBlows;
            *data << TeamId;
            *data << DamageDone;
            *data << HealingDone;
            *data << uint32(0); // Padding
        }

        uint8 TeamId;   // TEAM_ALLIANCE or ''_HORDE 
};

class ArenaTeamScore
{
    friend class ArenaMap;
    protected:
        ArenaTeamScore() : RatingChange(0), MatchmakerRating(0) {};

        void Assign(int32 ratingChange, uint32 matchMakerRating, std::string const& teamName)
        {
            RatingChange = ratingChange;
            MatchmakerRating = matchMakerRating;
            TeamName = teamName;
        }

        int32 RatingChange;
        uint32 MatchmakerRating;
        std::string TeamName;
};

#endif