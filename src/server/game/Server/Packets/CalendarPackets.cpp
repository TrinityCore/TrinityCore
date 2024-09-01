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

#include "CalendarPackets.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Calendar::CalendarSendCalendarEventInfo const& eventInfo)
{
    data << uint64(eventInfo.EventID);
    data << uint8(eventInfo.EventType);
    data << eventInfo.Date;
    data << uint16(eventInfo.Flags);
    data << int32(eventInfo.TextureID);
    data << uint64(eventInfo.EventClubID);
    data << eventInfo.OwnerGuid;

    data.WriteBits(eventInfo.EventName.size(), 8);
    data.FlushBits();
    data.WriteString(eventInfo.EventName);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Calendar::CalendarSendCalendarRaidLockoutInfo const& lockoutInfo)
{
    data << uint64(lockoutInfo.InstanceID);
    data << int32(lockoutInfo.MapID);
    data << uint32(lockoutInfo.DifficultyID);
    data << int32(lockoutInfo.ExpireTime);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Calendar::CalendarSendCalendarInviteInfo const& inviteInfo)
{
    data << uint64(inviteInfo.EventID);
    data << uint64(inviteInfo.InviteID);
    data << uint8(inviteInfo.Status);
    data << uint8(inviteInfo.Moderator);
    data << uint8(inviteInfo.InviteType);
    data << inviteInfo.InviterGuid;
    data.WriteBit(inviteInfo.IgnoreFriendAndGuildRestriction);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Calendar::CalendarEventInviteInfo const& inviteInfo)
{
    data << inviteInfo.Guid;
    data << uint64(inviteInfo.InviteID);

    data << uint8(inviteInfo.Level);
    data << uint8(inviteInfo.Status);
    data << uint8(inviteInfo.Moderator);
    data << uint8(inviteInfo.InviteType);
    data << inviteInfo.ResponseTime;

    data.WriteBits(inviteInfo.Notes.size(), 8);
    data.FlushBits();
    data.WriteString(inviteInfo.Notes);

    return data;
}

void WorldPackets::Calendar::CalendarGetEvent::Read()
{
    _worldPacket >> EventID;
}

void WorldPackets::Calendar::CalendarCommunityInviteRequest::Read()
{
    _worldPacket >> ClubID;
    _worldPacket >> MinLevel;
    _worldPacket >> MaxLevel;
    _worldPacket >> MaxRankOrder;
}

ByteBuffer& operator>>(ByteBuffer& buffer, WorldPackets::Calendar::CalendarAddEventInviteInfo& invite)
{
    buffer >> invite.Guid;
    buffer >> invite.Status;
    buffer >> invite.Moderator;
    if (buffer.ReadBit())
        invite.Unused_801_1.emplace();

    if (buffer.ReadBit())
        invite.Unused_801_2.emplace();

    if (buffer.ReadBit())
        invite.Unused_801_3.emplace();

    if (invite.Unused_801_1)
        buffer >> *invite.Unused_801_1;

    if (invite.Unused_801_2)
        buffer >> *invite.Unused_801_2;

    if (invite.Unused_801_3)
        buffer >> *invite.Unused_801_3;

    return buffer;
}

ByteBuffer& operator>>(ByteBuffer& buffer, WorldPackets::Calendar::CalendarAddEventInfo& addEventInfo)
{
    buffer >> addEventInfo.ClubID;
    buffer >> addEventInfo.EventType;
    buffer >> addEventInfo.TextureID;
    buffer >> addEventInfo.Time;
    buffer >> addEventInfo.Flags;
    addEventInfo.Invites.resize(buffer.read<uint32>());

    uint8 titleLength = buffer.ReadBits(8);
    uint16 descriptionLength = buffer.ReadBits(11);

    for (WorldPackets::Calendar::CalendarAddEventInviteInfo& invite : addEventInfo.Invites)
        buffer >> invite;

    addEventInfo.Title = buffer.ReadString(titleLength);
    addEventInfo.Description = buffer.ReadString(descriptionLength);

    return buffer;
}

void WorldPackets::Calendar::CalendarAddEvent::Read()
{
    _worldPacket >> EventInfo;
    _worldPacket >> MaxSize;
}

ByteBuffer& operator>>(ByteBuffer& buffer, WorldPackets::Calendar::CalendarUpdateEventInfo& updateEventInfo)
{
    buffer >> updateEventInfo.ClubID;
    buffer >> updateEventInfo.EventID;
    buffer >> updateEventInfo.ModeratorID;
    buffer >> updateEventInfo.EventType;
    buffer >> updateEventInfo.TextureID;
    buffer >> updateEventInfo.Time;
    buffer >> updateEventInfo.Flags;

    uint8 titleLen = buffer.ReadBits(8);
    uint16 descLen = buffer.ReadBits(11);

    updateEventInfo.Title = buffer.ReadString(titleLen);
    updateEventInfo.Description = buffer.ReadString(descLen);

    return buffer;
}

void WorldPackets::Calendar::CalendarUpdateEvent::Read()
{
    _worldPacket >> EventInfo;
    _worldPacket >> MaxSize;
}

void WorldPackets::Calendar::CalendarRemoveEvent::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> ModeratorID;
    _worldPacket >> ClubID;
    _worldPacket >> Flags;
}

void WorldPackets::Calendar::CalendarCopyEvent::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> ModeratorID;
    _worldPacket >> EventClubID;
    _worldPacket >> Date;
}

void WorldPackets::Calendar::CalendarRSVP::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> InviteID;
    _worldPacket >> Status;
}

void WorldPackets::Calendar::CalendarInvite::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> ModeratorID;
    _worldPacket >> ClubID;

    uint16 nameLen = _worldPacket.ReadBits(9);
    Creating = _worldPacket.ReadBit();
    IsSignUp = _worldPacket.ReadBit();

    Name = _worldPacket.ReadString(nameLen);
}

void WorldPackets::Calendar::CalendarEventSignUp::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> ClubID;
    Tentative = _worldPacket.ReadBit();
}

void WorldPackets::Calendar::CalendarRemoveInvite::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> InviteID;
    _worldPacket >> ModeratorID;
    _worldPacket >> EventID;
}

void WorldPackets::Calendar::CalendarStatus::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> EventID;
    _worldPacket >> InviteID;
    _worldPacket >> ModeratorID;
    _worldPacket >> Status;
}

void WorldPackets::Calendar::SetSavedInstanceExtend::Read()
{
    _worldPacket >> MapID;
    _worldPacket >> DifficultyID;
    Extend = _worldPacket.ReadBit();
}

void WorldPackets::Calendar::CalendarModeratorStatusQuery::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> EventID;
    _worldPacket >> InviteID;
    _worldPacket >> ModeratorID;
    _worldPacket >> Status;
}

WorldPacket const* WorldPackets::Calendar::CalendarInviteAdded::Write()
{
    _worldPacket << InviteGuid;
    _worldPacket << uint64(EventID);
    _worldPacket << uint64(InviteID);
    _worldPacket << uint8(Level);
    _worldPacket << uint8(Status);
    _worldPacket << uint8(Type);
    _worldPacket << ResponseTime;

    _worldPacket.WriteBit(ClearPending);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarSendCalendar::Write()
{
    _worldPacket << ServerTime;
    _worldPacket << uint32(Invites.size());
    _worldPacket << uint32(Events.size());
    _worldPacket << uint32(RaidLockouts.size());

    for (CalendarSendCalendarRaidLockoutInfo const& lockout : RaidLockouts)
        _worldPacket << lockout;

    for (CalendarSendCalendarInviteInfo const& invite : Invites)
        _worldPacket << invite;

    for (CalendarSendCalendarEventInfo const& event : Events)
        _worldPacket << event;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarSendEvent::Write()
{
    _worldPacket << uint8(EventType);
    _worldPacket << OwnerGuid;
    _worldPacket << uint64(EventID);
    _worldPacket << uint8(GetEventType);
    _worldPacket << int32(TextureID);
    _worldPacket << uint16(Flags);
    _worldPacket << Date;
    _worldPacket << LockDate;
    _worldPacket << uint64(EventClubID);
    _worldPacket << uint32(Invites.size());
    _worldPacket << BitsSize<8>(EventName);
    _worldPacket << BitsSize<11>(Description);
    _worldPacket.FlushBits();

    for (auto const& invite : Invites)
        _worldPacket << invite;

    _worldPacket.WriteString(EventName);
    _worldPacket.WriteString(Description);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarInviteAlert::Write()
{
    _worldPacket << uint64(EventID);
    _worldPacket << Date;
    _worldPacket << uint16(Flags);
    _worldPacket << uint8(EventType);
    _worldPacket << int32(TextureID);
    _worldPacket << uint64(EventClubID);
    _worldPacket << uint64(InviteID);
    _worldPacket << uint8(Status);
    _worldPacket << uint8(ModeratorStatus);

    // Todo: check order
    _worldPacket << InvitedByGuid;
    _worldPacket << OwnerGuid;

    _worldPacket << BitsSize<8>(EventName);
    _worldPacket << Bits<1>(Unknown_1100);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(EventName);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarInviteStatus::Write()
{
    _worldPacket << InviteGuid;
    _worldPacket << uint64(EventID);
    _worldPacket << Date;
    _worldPacket << uint32(Flags);
    _worldPacket << uint8(Status);
    _worldPacket << ResponseTime;

    _worldPacket.WriteBit(ClearPending);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarInviteRemoved::Write()
{
    _worldPacket << InviteGuid;
    _worldPacket << uint64(EventID);
    _worldPacket << uint32(Flags);

    _worldPacket.WriteBit(ClearPending);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarModeratorStatus::Write()
{
    _worldPacket << InviteGuid;
    _worldPacket << uint64(EventID);
    _worldPacket << uint8(Status);

    _worldPacket.WriteBit(ClearPending);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarInviteRemovedAlert::Write()
{
    _worldPacket << uint64(EventID);
    _worldPacket << Date;
    _worldPacket << uint32(Flags);
    _worldPacket << uint8(Status);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarEventUpdatedAlert::Write()
{
    _worldPacket << uint64(EventClubID);
    _worldPacket << uint64(EventID);

    _worldPacket << OriginalDate;
    _worldPacket << Date;
    _worldPacket << LockDate;
    _worldPacket << uint16(Flags);
    _worldPacket << uint32(TextureID);
    _worldPacket << uint8(EventType);

    _worldPacket.WriteBits(EventName.size(), 8);
    _worldPacket.WriteBits(Description.size(), 11);
    _worldPacket.WriteBit(ClearPending);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(EventName);
    _worldPacket.WriteString(Description);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarEventRemovedAlert::Write()
{
    _worldPacket << uint64(EventID);
    _worldPacket << Date;

    _worldPacket.WriteBit(ClearPending);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarSendNumPending::Write()
{
    _worldPacket << uint32(NumPending);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarCommandResult::Write()
{
    _worldPacket << uint8(Command);
    _worldPacket << uint8(Result);

    _worldPacket.WriteBits(Name.size(), 9);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarRaidLockoutAdded::Write()
{
    _worldPacket << uint64(InstanceID);
    _worldPacket << ServerTime;
    _worldPacket << int32(MapID);
    _worldPacket << uint32(DifficultyID);
    _worldPacket << int32(TimeRemaining);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarRaidLockoutRemoved::Write()
{
    _worldPacket << uint64(InstanceID);
    _worldPacket << int32(MapID);
    _worldPacket << uint32(DifficultyID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarRaidLockoutUpdated::Write()
{
    _worldPacket << ServerTime;
    _worldPacket << int32(MapID);
    _worldPacket << uint32(DifficultyID);
    _worldPacket << int32(OldTimeRemaining);
    _worldPacket << int32(NewTimeRemaining);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarCommunityInvite::Write()
{
    _worldPacket << uint32(Invites.size());
    for (auto const& invite : Invites)
    {
        _worldPacket << invite.InviteGuid;
        _worldPacket << uint8(invite.Level);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarInviteStatusAlert::Write()
{
    _worldPacket << uint64(EventID);
    _worldPacket << Date;
    _worldPacket << uint32(Flags);
    _worldPacket << uint8(Status);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarInviteNotesAlert::Write()
{
    _worldPacket << uint64(EventID);

    _worldPacket.WriteBits(Notes.size(), 8);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(Notes);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarInviteNotes::Write()
{
    _worldPacket << InviteGuid;
    _worldPacket << uint64(EventID);

    _worldPacket.WriteBit(ClearPending);
    _worldPacket.WriteBits(Notes.size(), 8);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(Notes);

    return &_worldPacket;
}

void WorldPackets::Calendar::CalendarComplain::Read()
{
    _worldPacket >> InvitedByGUID;
    _worldPacket >> EventID;
    _worldPacket >> InviteID;
}
