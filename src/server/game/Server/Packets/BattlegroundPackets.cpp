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

#include "BattlegroundPackets.h"

WorldPacket const* WorldPackets::Battleground::PVPOptionsEnabled::Write()
{
    _worldPacket.WriteBit(1); // ignored by the client
    _worldPacket.WriteBit(WargameBattlegrounds);
    _worldPacket.WriteBit(1); // ignored by the client
    _worldPacket.WriteBit(RatedBattlegrounds);
    _worldPacket.WriteBit(RatedArenas);
    _worldPacket.FlushBits();
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::RatedBattlefieldInfo::Write()
{
    _worldPacket << int32(Brackets[2].WeeklyWon);       // BgWeeklyWins25vs25
    _worldPacket << int32(Brackets[2].WeeklyPlayed);    // BgWeeklyPlayed25vs25
    _worldPacket << int32(Brackets[1].WeeklyPlayed);    // BgWeeklyPlayed15vs15
    _worldPacket << int32(Brackets[1].SeasonPlayed);    // BgSeasonalPlayed15vs15
    _worldPacket << int32(Brackets[0].WeeklyWon);       // BgWeeklyWins10vs10
    _worldPacket << int32(Brackets[2].SeasonPlayed);    // BgSeasonalPlayed25vs25
    _worldPacket << int32(Brackets[1].SeasonWon);       // BgSeasonalWins15vs15
    _worldPacket << int32(Brackets[0].TotalWon);        // BgTotalWins10vs10
    _worldPacket << int32(Brackets[1].WeeklyWon);       // BgWeeklyWins15vs15
    _worldPacket << int32(Brackets[2].TotalWon);        // BgTotalWins25vs25
    _worldPacket << int32(Brackets[0].SeasonWon);       // BgSeasonalWins10vs10
    _worldPacket << int32(Brackets[1].TotalWon);        // BgTotalWins15vs15
    _worldPacket << int32(Brackets[0].SeasonPlayed);    // BgSeasonalPlayed10vs10
    _worldPacket << int32(Brackets[2].SeasonWon);       // BgSeasonalWins25vs25
    _worldPacket << int32(Brackets[0].TotalPlayed);     // BgTotalPlayed10vs10
    _worldPacket << int32(Brackets[0].WeeklyPlayed);    // BgWeeklyPlayed10vs10
    _worldPacket << int32(Brackets[2].TotalPlayed);     // BgTotalPlayed25vs25
    _worldPacket << int32(Brackets[1].TotalPlayed);     // BgTotalPlayed15vs15

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::BattlefieldRatedInfo::Write()
{
    _worldPacket << int32(Reward);
    _worldPacket << int8(Mode);
    _worldPacket << int32(PersonalRating);
    _worldPacket << int32(RewardPointsThisWeek);
    _worldPacket << int32(RatedMaxRewardPointsThisWeek);    // this and MaxRewardPointsThisWeek are weekly conquest limits but not sure which one is for rated BGs
    _worldPacket << int32(RatedRewardPointsThisWeek);
    _worldPacket << int32(0);                               // values are being sent in in sniffs but this filed is unused in the client and interface code
    _worldPacket << int32(MaxRewardPointsThisWeek);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::BattlefieldList::Write()
{
    _worldPacket << int32(ConquestBonusHoliday);
    _worldPacket << int32(ConquestBonusRandom);
    _worldPacket << int32(HonorBonusHolidayLoss);
    _worldPacket << int32(BattlemasterListID);
    _worldPacket << int32(HonorBonusRandomLoss);
    _worldPacket << int32(HonorBonusRandomWin);
    _worldPacket << int32(HonorBonusHolidayWin);
    _worldPacket << uint8(MaxLevel);
    _worldPacket << uint8(MinLevel);

    _worldPacket.WriteBit(BattlemasterGuid[0]);
    _worldPacket.WriteBit(BattlemasterGuid[1]);
    _worldPacket.WriteBit(BattlemasterGuid[7]);
    _worldPacket.WriteBit(HasHolidayWinToday);
    _worldPacket.WriteBit(HasRandomWinToday);
    _worldPacket.WriteBits(Battlefields.size(), 24);
    _worldPacket.WriteBit(BattlemasterGuid[6]);
    _worldPacket.WriteBit(BattlemasterGuid[4]);
    _worldPacket.WriteBit(BattlemasterGuid[2]);
    _worldPacket.WriteBit(BattlemasterGuid[3]);
    _worldPacket.WriteBit(IsRandomBG);
    _worldPacket.WriteBit(BattlemasterGuid[5]);
    _worldPacket.WriteBit(PvpAnywhere);
    _worldPacket.FlushBits();

    _worldPacket.WriteByteSeq(BattlemasterGuid[6]);
    _worldPacket.WriteByteSeq(BattlemasterGuid[1]);
    _worldPacket.WriteByteSeq(BattlemasterGuid[7]);
    _worldPacket.WriteByteSeq(BattlemasterGuid[5]);

    for (int32 battlefield : Battlefields)
        _worldPacket << int32(battlefield);

    _worldPacket.WriteByteSeq(BattlemasterGuid[0]);
    _worldPacket.WriteByteSeq(BattlemasterGuid[2]);
    _worldPacket.WriteByteSeq(BattlemasterGuid[4]);
    _worldPacket.WriteByteSeq(BattlemasterGuid[3]);

    return &_worldPacket;
}
