/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "GuildPackets.h"

void WorldPackets::Guild::QueryGuildInfo::Read()
{
    _worldPacket >> GuildGuid;
    _worldPacket >> PlayerGuid;
}

WorldPackets::Guild::QueryGuildInfoResponse::QueryGuildInfoResponse()
    : ServerPacket(SMSG_GUILD_QUERY_RESPONSE) { }

WorldPacket const* WorldPackets::Guild::QueryGuildInfoResponse::Write()
{
    _worldPacket << GuildGuid;
    _worldPacket.WriteBit(Info.HasValue);

    if (Info.HasValue)
    {
        _worldPacket << Info.Value.GuildGUID;
        _worldPacket << uint32(Info.Value.VirtualRealmAddress);
        _worldPacket << uint32(Info.Value.Ranks.size());
        _worldPacket << uint32(Info.Value.EmblemStyle);
        _worldPacket << uint32(Info.Value.EmblemColor);
        _worldPacket << uint32(Info.Value.BorderStyle);
        _worldPacket << uint32(Info.Value.BorderColor);
        _worldPacket << uint32(Info.Value.BackgroundColor);

        for (GuildRank const& rank : Info.Value.Ranks)
        {
            _worldPacket << uint32(rank.RankID);
            _worldPacket << uint32(rank.RankOrder);

            _worldPacket.WriteBits(rank.RankName.size(), 7);
            _worldPacket.WriteString(rank.RankName);
        }

        _worldPacket.WriteBits(Info.Value.GuildName.size(), 7);
        _worldPacket.WriteString(Info.Value.GuildName);
    }
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildRosterResponse::Write()
{
    _worldPacket << uint32(MemberCount);
    _worldPacket.AppendPackedTime(CreatedDate);
    _worldPacket << uint32(GuildFlags);
    _worldPacket << uint32(Members.size());

    for (GuildMemberInfo const& member : Members)
    {
        _worldPacket << member.MemberGUID;
        _worldPacket << uint32(member.RankID);
        _worldPacket << uint32(member.AreaID);
        _worldPacket << uint32(member.AchivementPoints);
        _worldPacket << uint32(member.Reputation);
        _worldPacket << float(member.LastOnlineTime);

        for (GuildMemberInfo::GuildMemberProfession const& profession : member.Professions)
        {
            _worldPacket << uint32(profession.ID);
            _worldPacket << uint32(profession.Rank);
            _worldPacket << uint32(profession.Step);
        }

        _worldPacket << uint32(member.VirtualRealmAddress);
        _worldPacket << uint8(member.Flags);
        _worldPacket << uint8(member.Level);
        _worldPacket << uint8(member.Class);
        _worldPacket << uint8(member.Gender);

        _worldPacket.WriteBits(member.Name.size(), 6);
        _worldPacket.WriteBits(member.Note.size(), 8);
        _worldPacket.WriteBits(member.OfficerNote.size(), 8);

        _worldPacket.WriteBit(member.Authenticated);
        _worldPacket.WriteBit(member.ScrollOfResurrection);

        _worldPacket.WriteString(member.Name);
        _worldPacket.WriteString(member.Note);
        _worldPacket.WriteString(member.OfficerNote);
    }

    _worldPacket.WriteBits(WelcomeText.size(), 10);
    _worldPacket.WriteBits(InfoText.size(), 11);

    _worldPacket.WriteString(WelcomeText);
    _worldPacket.WriteString(InfoText);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Guild::GuildGetRanks::Read()
{
    _worldPacket >> GuildGUID;
}

WorldPacket const* WorldPackets::Guild::GuildRanksResponse::Write()
{
    _worldPacket << uint32(Ranks.size());

    for (auto rank : Ranks)
    {
        _worldPacket << int32(rank.RankID);
        _worldPacket << int32(rank.RankOrder);
        _worldPacket << int32(rank.Flags);
        _worldPacket << int32(rank.WithdrawGoldLimit);

        for (GuildRank::GuildRankTabInfo tab : rank.TabInfo)
        {
            _worldPacket << int32(tab.TabFlags);
            _worldPacket << int32(tab.TabWithdrawItemLimit);
        }

        _worldPacket.WriteBits(rank.RankName.size(), 7);
        _worldPacket.WriteString(rank.RankName);
    }

    _worldPacket.FlushBits();

    return &_worldPacket;
}
