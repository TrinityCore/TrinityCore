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
#include "Player.h"
#include "ObjectAccessor.h"

struct ArenaScore : public BattlegroundScore
{
    friend class BattlegroundBE;
    friend class BattlegroundDS;
    friend class BattlegroundNA;
    friend class BattlegroundRL;
    friend class BattlegroundRV;

    protected:
        ArenaScore(uint64 playerGuid, uint32 team) : BattlegroundScore(playerGuid, team), TeamId(team == ALLIANCE ? 1 : 0) { }

        void AppendToPacket(WorldPacket& data, ByteBuffer& content) final
        {
            uint32 primaryTree = 0;
            if (Player* player = ObjectAccessor::FindPlayer(PlayerGuid))
                primaryTree = player->GetPrimaryTalentTree(player->GetActiveSpec());

            data.WriteBit(0);                   // Unk 1
            data.WriteBit(0);                   // Unk 2
            data.WriteBit(PlayerGuid[2]);
            data.WriteBit(/*!IsArena*/ 0);      // IsArena
            data.WriteBit(0);                   // Unk 4
            data.WriteBit(0);                   // Unk 5
            data.WriteBit(0);                   // Unk 6
            data.WriteBit(PlayerGuid[3]);
            data.WriteBit(PlayerGuid[0]);
            data.WriteBit(PlayerGuid[5]);
            data.WriteBit(PlayerGuid[1]);
            data.WriteBit(PlayerGuid[6]);
            data.WriteBit(TeamId);
            data.WriteBit(PlayerGuid[7]);

            content << uint32(HealingDone);     // healing done
            content << uint32(DamageDone);      // damage done

            content.WriteByteSeq(PlayerGuid[4]);
            content << uint32(KillingBlows);

            //if (unk5)
            //  content << int32(RatingChange); // RatingChange

            content.WriteByteSeq(PlayerGuid[5]);

            //if (unk 6)
            //    content << uint32();

            //if (unk 2)
            //    content << uint32();

            content.WriteByteSeq(PlayerGuid[1]);
            content.WriteByteSeq(PlayerGuid[6]);

            content << int32(primaryTree);

            data.WriteBits(0, 24); // Objectives Count

            data.WriteBit(PlayerGuid[4]);

            content.WriteByteSeq(PlayerGuid[0]);
            content.WriteByteSeq(PlayerGuid[3]);

            //if (unk 4)
            //    content << uint32() unk

            content.WriteByteSeq(PlayerGuid[7]);
            content.WriteByteSeq(PlayerGuid[2]);
        }

        // For Logging purpose
        std::string ToString() const override
        {
            std::ostringstream stream;
            stream << "Damage done: " << DamageDone << ", Healing done: " << HealingDone << ", Killing blows: " << KillingBlows;
            return stream.str();
        }

        uint8 TeamId; // TEAM_ALLIANCE or TEAM_HORDE
};

struct ArenaTeamScore
{
    friend class Battleground;

    protected:
        ArenaTeamScore() : RatingChange(0), MatchmakerRating(0) { }

        virtual ~ArenaTeamScore() { }

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

            data << uint32(MatchmakerRating);
            data << uint32(ratingLost);
            data << uint32(ratingWon);
        }

        void BuildTeamInfoLengthBlock(WorldPacket& data)
        {
            data.WriteBits(TeamName.length(), 8);
        }

        void BuildTeamInfoBlock(WorldPacket& data)
        {
            data.WriteString(TeamName);
        }

        int32 RatingChange;
        uint32 MatchmakerRating;
        std::string TeamName;
};

#endif // TRINITY_ARENA_SCORE_H
