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

#include "MythicPlusPacketsCommon.h"

namespace WorldPackets
{
namespace MythicPlus
{
ByteBuffer& operator<<(ByteBuffer& data, DungeonScoreMapSummary const& dungeonScoreMapSummary)
{
    data << int32(dungeonScoreMapSummary.ChallengeModeID);
    data << int32(dungeonScoreMapSummary.MapScore);
    data << int32(dungeonScoreMapSummary.BestRunLevel);
    data << int32(dungeonScoreMapSummary.BestRunDurationMS);
    data.WriteBit(dungeonScoreMapSummary.FinishedSuccess);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, DungeonScoreSummary const& dungeonScoreSummary)
{
    data << int32(dungeonScoreSummary.CurrentSeasonScore);
    data << uint32(dungeonScoreSummary.Runs.size());
    for (DungeonScoreMapSummary const& dungeonScoreMapSummary : dungeonScoreSummary.Runs)
        data << dungeonScoreMapSummary;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MythicPlusMember const& mythicPlusMember)
{
    data << mythicPlusMember.BnetAccountGUID;
    data << uint64(mythicPlusMember.GuildClubMemberID);
    data << mythicPlusMember.GUID;
    data << mythicPlusMember.GuildGUID;
    data << uint32(mythicPlusMember.NativeRealmAddress);
    data << uint32(mythicPlusMember.VirtualRealmAddress);
    data << int16(mythicPlusMember.ChrSpecializationID);
    data << int16(mythicPlusMember.RaceID);
    data << int32(mythicPlusMember.ItemLevel);
    data << int32(mythicPlusMember.CovenantID);
    data << int32(mythicPlusMember.SoulbindID);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MythicPlusRun const& mythicPlusRun)
{
    data << int32(mythicPlusRun.MapChallengeModeID);
    data << uint32(mythicPlusRun.Level);
    data << int32(mythicPlusRun.DurationMs);
    data << mythicPlusRun.StartDate;
    data << mythicPlusRun.CompletionDate;
    data << int32(mythicPlusRun.Season);
    data.append(mythicPlusRun.KeystoneAffixIDs.data(), mythicPlusRun.KeystoneAffixIDs.size());
    data << uint32(mythicPlusRun.Members.size());
    data << int32(mythicPlusRun.RunScore);
    for (MythicPlusMember const& member : mythicPlusRun.Members)
        data << member;

    data.WriteBit(mythicPlusRun.Completed);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, DungeonScoreBestRunForAffix const& dungeonScoreBestRunForAffix)
{
    data << int32(dungeonScoreBestRunForAffix.KeystoneAffixID);
    data << int32(dungeonScoreBestRunForAffix.Score);
    data << dungeonScoreBestRunForAffix.Run;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, DungeonScoreMapData const& dungeonScoreMapData)
{
    data << int32(dungeonScoreMapData.MapChallengeModeID);
    data << uint32(dungeonScoreMapData.BestRuns.size());
    data << int32(dungeonScoreMapData.OverAllScore);
    for (DungeonScoreBestRunForAffix const& bestRun : dungeonScoreMapData.BestRuns)
        data << bestRun;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, DungeonScoreSeasonData const& dungeonScoreSeasonData)
{
    data << int32(dungeonScoreSeasonData.Season);
    data << uint32(dungeonScoreSeasonData.Maps.size());
    data << int32(dungeonScoreSeasonData.SeasonScore);
    for (DungeonScoreMapData const& map : dungeonScoreSeasonData.Maps)
        data << map;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, DungeonScoreData const& dungeonScoreData)
{
    data << uint32(dungeonScoreData.Seasons.size());
    data << int32(dungeonScoreData.TotalRuns);
    for (DungeonScoreSeasonData const& season : dungeonScoreData.Seasons)
        data << season;

    return data;
}
}
}
