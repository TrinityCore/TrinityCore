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

#include "AchievementPackets.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Achievement::EarnedAchievement const& earned)
{
    data << uint32(earned.Id);
    data.AppendPackedTime(earned.Date);
    data << earned.Owner;
    data << uint32(earned.VirtualRealmAddress);
    data << uint32(earned.NativeRealmAddress);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Achievement::CriteriaProgress const& criteria)
{
    data << uint32(criteria.Id);
    data << uint64(criteria.Quantity);
    data << criteria.Player;
    data.AppendPackedTime(criteria.Date);
    data << uint32(criteria.TimeFromStart);
    data << uint32(criteria.TimeFromCreate);
    data.WriteBits(criteria.Flags, 4);
    data.FlushBits();
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Achievement::AllAchievements const& allAchievements)
{
    data << uint32(allAchievements.Earned.size());
    data << uint32(allAchievements.Progress.size());

    for (WorldPackets::Achievement::EarnedAchievement const& earned : allAchievements.Earned)
        data << earned;

    for (WorldPackets::Achievement::CriteriaProgress const& progress : allAchievements.Progress)
        data << progress;

    return data;
}

WorldPacket const* WorldPackets::Achievement::AllAchievementData::Write()
{
    _worldPacket << Data;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Achievement::RespondInspectAchievements::Write()
{
    _worldPacket << Player;
    _worldPacket << Data;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Achievement::CriteriaUpdate::Write()
{
    _worldPacket << uint32(CriteriaID);
    _worldPacket << uint64(Quantity);
    _worldPacket << PlayerGUID;
    _worldPacket << uint32(Flags);
    _worldPacket.AppendPackedTime(CurrentTime);
    _worldPacket << uint32(ElapsedTime);
    _worldPacket << uint32(CreationTime);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Achievement::CriteriaDeleted::Write()
{
    _worldPacket << uint32(CriteriaID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Achievement::AchievementDeleted::Write()
{
    _worldPacket << uint32(AchievementID);
    _worldPacket << uint32(Immunities);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Achievement::AchievementEarned::Write()
{
    _worldPacket << Sender;
    _worldPacket << Earner;
    _worldPacket << uint32(AchievementID);
    _worldPacket.AppendPackedTime(Time);
    _worldPacket << uint32(EarnerNativeRealm);
    _worldPacket << uint32(EarnerVirtualRealm);
    _worldPacket.WriteBit(Initial);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Achievement::ServerFirstAchievement::Write()
{
    _worldPacket.WriteBits(Name.length(), 7);
    _worldPacket.WriteBit(GuildAchievement);
    _worldPacket << PlayerGUID;
    _worldPacket << AchievementID;
    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Achievement::GuildCriteriaUpdate::Write()
{
    _worldPacket << uint32(Progress.size());

    for (GuildCriteriaProgress const& progress : Progress)
    {
        _worldPacket << int32(progress.CriteriaID);
        _worldPacket << uint32(progress.DateCreated);
        _worldPacket << uint32(progress.DateStarted);
        _worldPacket.AppendPackedTime(progress.DateUpdated);
        _worldPacket << uint64(progress.Quantity);
        _worldPacket << progress.PlayerGUID;
        _worldPacket << int32(progress.Flags);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Achievement::GuildCriteriaDeleted::Write()
{
    _worldPacket << GuildGUID;
    _worldPacket << int32(CriteriaID);

    return &_worldPacket;
}

void WorldPackets::Achievement::GuildSetFocusedAchievement::Read()
{
    _worldPacket >> AchievementID;
}

WorldPacket const* WorldPackets::Achievement::GuildAchievementDeleted::Write()
{
    _worldPacket << GuildGUID;
    _worldPacket << uint32(AchievementID);
    _worldPacket.AppendPackedTime(TimeDeleted);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Achievement::GuildAchievementEarned::Write()
{
    _worldPacket << GuildGUID;
    _worldPacket << uint32(AchievementID);
    _worldPacket.AppendPackedTime(TimeEarned);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Achievement::AllGuildAchievements::Write()
{
    _worldPacket << uint32(Earned.size());

    for (EarnedAchievement const& earned : Earned)
        _worldPacket << earned;

    return &_worldPacket;
}

void WorldPackets::Achievement::GuildGetAchievementMembers::Read()
{
    _worldPacket >> PlayerGUID;
    _worldPacket >> GuildGUID;
    _worldPacket >> AchievementID;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Achievement::GuildAchievementMember const& guildAchievementMember)
{
    data << guildAchievementMember.MemberGUID;
    return data;
}

WorldPacket const* WorldPackets::Achievement::GuildAchievementMembers::Write()
{
    _worldPacket << GuildGUID;
    _worldPacket << int32(AchievementID);
    _worldPacket << uint32(Member.size());
    for (GuildAchievementMember const& member : Member)
        _worldPacket << member;

    return &_worldPacket;
}
