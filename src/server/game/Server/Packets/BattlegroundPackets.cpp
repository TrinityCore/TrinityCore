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
    _worldPacket << int32(0);
    _worldPacket << int32(Brackets[0].WeeklyWon);       // BgWeeklyWins10vs10
    _worldPacket << int32(0);
    _worldPacket << int32(0);
    _worldPacket << int32(0);
    _worldPacket << int32(Brackets[1].WeeklyWon);       // BgWeeklyWins15vs15
    _worldPacket << int32(0);
    _worldPacket << int32(0);
    _worldPacket << int32(0);
    _worldPacket << int32(Brackets[0].WeeklyPlayed);    // BgWeeklyPlayed10vs10
    _worldPacket << int32(0);
    _worldPacket << int32(0);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::BattlefieldRatedInfo::Write()
{
    _worldPacket << int32(Reward);
    _worldPacket << int8(Unk);
    _worldPacket << int32(PersonalRating);
    _worldPacket << int32(0);
    _worldPacket << int32(RewardWeeklyLimit);
    _worldPacket << int32(0);
    _worldPacket << int32(0);
    _worldPacket << int32(PurseQuantity);

    return &_worldPacket;
}
