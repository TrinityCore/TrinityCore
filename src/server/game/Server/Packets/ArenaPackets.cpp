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

#include "ArenaPackets.h"
#include "PacketUtilities.h"
#include "Player.h"
#include "SharedDefines.h"

WorldPacket const* WorldPackets::Arena::PvpSeason::Write()
{
    _worldPacket << int32(Unk0);
    _worldPacket << int32(Unk1);
    _worldPacket << int32(CurrentArenaSeason);
    _worldPacket << int32(PreviousArenaSeason);
    _worldPacket << int32(CurrentArenaUsesTeams);
    _worldPacket << int32(PreviousArenaUsesTeams);
    _worldPacket << int32(Unk6);
    _worldPacket << Bits<1>(Unk7);
    _worldPacket << Bits<1>(Unk8);
    _worldPacket << Bits<1>(Unk9);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Arena::CArenaTeamRoster::Read()
{
    _worldPacket >> TeamID;
}

WorldPacket const* WorldPackets::Arena::SArenaTeamRoster::Write()
{
    _worldPacket << int32(TeamID);
    _worldPacket << int32(TeamSize);
    _worldPacket << int32(MatchesPlayed);
    _worldPacket << int32(MatchesWon);
    _worldPacket << int32(SeasonMatchesPlayed);
    _worldPacket << int32(SeasonMatchesWon);
    _worldPacket << int32(Rating);
    _worldPacket << int32(Ranking);
    _worldPacket << Size<int32>(Members);
    _worldPacket << Bits<1>(Disqualified);
    _worldPacket.FlushBits();

    for (ArenaTeamMember const& member : Members)
        _worldPacket << member;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Arena::QueryArenaTeamResponse::Write()
{
    _worldPacket << int32(TeamID);
    _worldPacket << Bits<1>(Allow);
    _worldPacket.FlushBits();

    if (Allow)
    {
        _worldPacket << int32(TeamID);
        _worldPacket << int32(TeamSize);
        _worldPacket << int32(EmblemBackground);
        _worldPacket << int32(EmblemIconStyle);
        _worldPacket << int32(EmblemIconColor);
        _worldPacket << int32(EmblemBorderStyle);
        _worldPacket << int32(EmblemBorderColor);

        _worldPacket << BitsSize<7>(Name);
        _worldPacket.FlushBits();

        _worldPacket.WriteString(Name);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Arena::ArenaTeamCommandResult::Write()
{
    _worldPacket << uint8(Action);
    _worldPacket << uint8(ErrorID);

    _worldPacket << BitsSize<7>(TeamName);
    _worldPacket << BitsSize<6>(PlayerName);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(TeamName);
    _worldPacket.WriteString(PlayerName);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Arena::ArenaTeamEvent::Write()
{
    _worldPacket << uint8(Event);

    for (std::string const& param : Params)
        _worldPacket << BitsSize<9>(param);

    _worldPacket.FlushBits();

    for (std::string const& param : Params)
        _worldPacket.WriteString(param);

    return &_worldPacket;
}

void WorldPackets::Arena::ArenaTeamDisband::Read()
{
    _worldPacket >> TeamID;
}

void WorldPackets::Arena::ArenaTeamLeave::Read()
{
    _worldPacket >> TeamID;
}

ByteBuffer& WorldPackets::Arena::operator<<(ByteBuffer& data, ArenaTeamMember const& member)
{
    data << member.MemberGUID;
    data << uint8(member.Online);
    data << int32(member.Rank);
    data << uint8(member.Level);
    data << uint8(member.ClassID);
    data << int32(member.WeekMatches);
    data << int32(member.WeekWins);
    data << int32(member.SeasonMatches);
    data << int32(member.SeasonWins);
    data << int32(member.ContributionRating);

    data << BitsSize<6>(member.Name);
    data << OptionalInit(member.GDFRating);
    data << OptionalInit(member.GDFVariance);
    data.FlushBits();

    data.WriteString(member.Name);

    if (member.GDFRating)
        data << float(*member.GDFRating);

    if (member.GDFVariance)
        data << float(*member.GDFVariance);

    return data;
}
