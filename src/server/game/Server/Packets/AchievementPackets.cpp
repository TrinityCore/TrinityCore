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

#include "AchievementPackets.h"

namespace WorldPackets::Achievement
{
ByteBuffer& operator<<(ByteBuffer& data, EarnedAchievement const& earned)
{
    data << uint32(earned.Id);
    data << earned.Date;
    data << earned.Owner;
    data << uint32(earned.VirtualRealmAddress);
    data << uint32(earned.NativeRealmAddress);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, CriteriaProgress const& criteria)
{
    data << uint32(criteria.Id);
    data << uint64(criteria.Quantity);
    data << criteria.Player;
    data << uint32(criteria.Flags);
    data << uint32(criteria.StateFlags);
    data << criteria.Date;
    data << criteria.TimeFromStart;
    data << criteria.TimeFromCreate;
    data.WriteBit(criteria.DynamicID.has_value());
    data.FlushBits();

    if (criteria.DynamicID)
        data << uint64(*criteria.DynamicID);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, AllAchievements const& allAchievements)
{
    data << uint32(allAchievements.Earned.size());
    data << uint32(allAchievements.Progress.size());

    for (EarnedAchievement const& earned : allAchievements.Earned)
        data << earned;

    for (CriteriaProgress const& progress : allAchievements.Progress)
        data << progress;

    return data;
}

WorldPacket const* AllAchievementData::Write()
{
    _worldPacket << Data;

    return &_worldPacket;
}

WorldPacket const* AllAccountCriteria::Write()
{
    _worldPacket << uint32(Progress.size());
    for (CriteriaProgress const& progress : Progress)
        _worldPacket << progress;

    return &_worldPacket;
}

WorldPacket const* RespondInspectAchievements::Write()
{
    _worldPacket << Player;
    _worldPacket << Data;

    return &_worldPacket;
}

WorldPacket const* CriteriaUpdate::Write()
{
    _worldPacket << uint32(CriteriaID);
    _worldPacket << uint64(Quantity);
    _worldPacket << PlayerGUID;
    _worldPacket << uint32(Flags);
    _worldPacket << uint32(StateFlags);
    _worldPacket << CurrentTime;
    _worldPacket << ElapsedTime;
    _worldPacket << CreationTime;
    _worldPacket.WriteBit(DynamicID.has_value());
    _worldPacket.FlushBits();

    if (DynamicID)
        _worldPacket << uint64(*DynamicID);

    return &_worldPacket;
}

WorldPacket const* AccountCriteriaUpdate::Write()
{
    _worldPacket << Progress;

    return &_worldPacket;
}

WorldPacket const* CriteriaDeleted::Write()
{
    _worldPacket << uint32(CriteriaID);

    return &_worldPacket;
}

WorldPacket const* AchievementDeleted::Write()
{
    _worldPacket << uint32(AchievementID);
    _worldPacket << uint32(Immunities);

    return &_worldPacket;
}

WorldPacket const* AchievementEarned::Write()
{
    _worldPacket << Sender;
    _worldPacket << Earner;
    _worldPacket << uint32(AchievementID);
    _worldPacket << Time;
    _worldPacket << uint32(EarnerNativeRealm);
    _worldPacket << uint32(EarnerVirtualRealm);
    _worldPacket.WriteBit(Initial);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* BroadcastAchievement::Write()
{
    _worldPacket.WriteBits(Name.length(), 7);
    _worldPacket.WriteBit(GuildAchievement);
    _worldPacket << PlayerGUID;
    _worldPacket << AchievementID;
    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

WorldPacket const* GuildCriteriaUpdate::Write()
{
    _worldPacket << uint32(Progress.size());

    for (GuildCriteriaProgress const& progress : Progress)
    {
        _worldPacket << int32(progress.CriteriaID);
        _worldPacket << progress.DateCreated;
        _worldPacket << progress.DateStarted;
        _worldPacket << int64(progress.DateUpdated.GetPackedTime());
        _worldPacket << uint64(progress.Quantity);
        _worldPacket << progress.PlayerGUID;
        _worldPacket << int32(progress.Flags);
        _worldPacket << int32(progress.StateFlags);
    }

    return &_worldPacket;
}

WorldPacket const* GuildCriteriaDeleted::Write()
{
    _worldPacket << GuildGUID;
    _worldPacket << int32(CriteriaID);

    return &_worldPacket;
}

void GuildSetFocusedAchievement::Read()
{
    _worldPacket >> AchievementID;
}

WorldPacket const* GuildAchievementDeleted::Write()
{
    _worldPacket << GuildGUID;
    _worldPacket << uint32(AchievementID);
    _worldPacket << TimeDeleted;

    return &_worldPacket;
}

WorldPacket const* GuildAchievementEarned::Write()
{
    _worldPacket << GuildGUID;
    _worldPacket << uint32(AchievementID);
    _worldPacket << TimeEarned;

    return &_worldPacket;
}

WorldPacket const* AllGuildAchievements::Write()
{
    _worldPacket << uint32(Earned.size());

    for (EarnedAchievement const& earned : Earned)
        _worldPacket << earned;

    return &_worldPacket;
}

void GuildGetAchievementMembers::Read()
{
    _worldPacket >> PlayerGUID;
    _worldPacket >> GuildGUID;
    _worldPacket >> AchievementID;
}

ByteBuffer& operator<<(ByteBuffer& data, GuildAchievementMember const& guildAchievementMember)
{
    data << guildAchievementMember.MemberGUID;
    return data;
}

WorldPacket const* GuildAchievementMembers::Write()
{
    _worldPacket << GuildGUID;
    _worldPacket << int32(AchievementID);
    _worldPacket << uint32(Member.size());
    for (GuildAchievementMember const& member : Member)
        _worldPacket << member;

    return &_worldPacket;
}
}
