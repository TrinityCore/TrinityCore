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

#ifndef MythicPlusPacketsCommon_h__
#define MythicPlusPacketsCommon_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "PacketUtilities.h"

namespace WorldPackets
{
    namespace MythicPlus
    {
        struct DungeonScoreMapSummary
        {
            int32 ChallengeModeID = 0;
            int32 MapScore = 0;
            int32 BestRunLevel = 0;
            int32 BestRunDurationMS = 0;
            bool FinishedSuccess = false;
        };

        struct DungeonScoreSummary
        {
            int32 CurrentSeasonScore = 0;
            std::vector<DungeonScoreMapSummary> Runs;
        };

        struct MythicPlusMember
        {
            ObjectGuid BnetAccountGUID;
            uint64 GuildClubMemberID = 0;
            ObjectGuid GUID;
            ObjectGuid GuildGUID;
            uint32 NativeRealmAddress = 0;
            uint32 VirtualRealmAddress = 0;
            int16 ChrSpecializationID = 0;
            int16 RaceID = 0;
            int32 ItemLevel = 0;
            int32 CovenantID = 0;
            int32 SoulbindID = 0;
        };

        struct MythicPlusRun
        {
            int32 MapChallengeModeID = 0;
            bool Completed = false;
            uint32 Level = 0;
            int32 DurationMs = 0;
            Timestamp<> StartDate;
            Timestamp<> CompletionDate;
            int32 Season;
            std::vector<MythicPlusMember> Members;
            int32 RunScore;
            std::array<int32, 4> KeystoneAffixIDs;
        };

        struct DungeonScoreBestRunForAffix
        {
            int32 KeystoneAffixID = 0;
            MythicPlusRun Run;
            int32 Score = 0;
        };

        struct DungeonScoreMapData
        {
            int32 MapChallengeModeID = 0;
            std::vector<DungeonScoreBestRunForAffix> BestRuns;
            int32 OverAllScore = 0;

        };

        struct DungeonScoreSeasonData
        {
            int32 Season = 0;
            std::vector<DungeonScoreMapData> Maps;
            int32 SeasonScore = 0;
        };

        struct DungeonScoreData
        {
            std::vector<DungeonScoreSeasonData> Seasons;
            int32 TotalRuns = 0;
        };

        ByteBuffer& operator<<(ByteBuffer& data, DungeonScoreSummary const& dungeonScoreSummary);
        ByteBuffer& operator<<(ByteBuffer& data, DungeonScoreData const& dungeonScoreData);
    }
}

#endif // MythicPlusPacketsCommon_h__
