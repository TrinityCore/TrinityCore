/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
    data.AppendPackedTime(eventInfo.Date);
    data << uint32(eventInfo.Flags);
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
    data << uint32(lockoutInfo.ExpireTime);

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

    data.AppendPackedTime(inviteInfo.ResponseTime);

    data.WriteBits(inviteInfo.Notes.size(), 8);
    data.FlushBits();
    data.WriteString(inviteInfo.Notes);

    return data;
}

void WorldPackets::Calendar::CalendarGetEvent::Read()
{
    _worldPacket >> EventID;
}

void WorldPackets::Calendar::CalendarCommunityFilter::Read()
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
        invite.Unused_801_1 = boost::in_place();

    if (buffer.ReadBit())
        invite.Unused_801_2 = boost::in_place();

    if (buffer.ReadBit())
        invite.Unused_801_3 = boost::in_place();

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
    addEventInfo.Time = buffer.ReadPackedTime();
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
    updateEventInfo.Time = buffer.ReadPackedTime();
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
    Date = _worldPacket.ReadPackedTime();
}

void WorldPackets::Calendar::CalendarEventRSVP::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> InviteID;
    _worldPacket >> Status;
}

void WorldPackets::Calendar::CalendarEventInvite::Read()
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

void WorldPackets::Calendar::CalendarEventStatus::Read()
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

void WorldPackets::Calendar::CalendarEventModeratorStatus::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> EventID;
    _worldPacket >> InviteID;
    _worldPacket >> ModeratorID;
    _worldPacket >> Status;
}

WorldPacket const* WorldPackets::Calendar::SCalendarEventInvite::Write()
{
    _worldPacket << InviteGuid;
    _worldPacket << uint64(EventID);
    _worldPacket << uint64(InviteID);
    _worldPacket << uint8(Level);
    _worldPacket << uint8(Status);
    _worldPacket << uint8(Type);
    _worldPacket.AppendPackedTime(ResponseTime);

    _worldPacket.WriteBit(ClearPending);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarSendCalendar::Write()
{
    _worldPacket.AppendPackedTime(ServerTime);
    _worldPacket << uint32(Invites.size());
    _worldPacket << uint32(Events.size());
    _worldPacket << uint32(RaidLockouts.size());

    for (auto const& invite : Invites)
        _worldPacket << invite;

    for (auto const& lockout : RaidLockouts)
        _worldPacket << lockout;

    for (auto const& event : Events)
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
    _worldPacket << uint32(Flags);
    _worldPacket.AppendPackedTime(Date);
    _worldPacket << uint32(LockDate);
    _worldPacket << uint64(EventClubID);
    _worldPacket << uint32(Invites.size());
    _worldPacket.WriteBits(EventName.size(), 8);
    _worldPacket.WriteBits(Description.size(), 11);
    _worldPacket.FlushBits();

    for (auto const& invite : Invites)
        _worldPacket << invite;

    _worldPacket.WriteString(EventName);
    _worldPacket.WriteString(Description);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarEventInviteAlert::Write()
{
    _worldPacket << uint64(EventID);
    _worldPacket.AppendPackedTime(Date);
    _worldPacket << uint32(Flags);
    _worldPacket << uint8(EventType);
    _worldPacket << int32(TextureID);
    _worldPacket << uint64(EventClubID);
    _worldPacket << uint64(InviteID);
    _worldPacket << uint8(Status);
    _worldPacket << uint8(ModeratorStatus);

    // Todo: check order
    _worldPacket << InvitedByGuid;
    _worldPacket << OwnerGuid;

    _worldPacket.WriteBits(EventName.size(), 8);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(EventName);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarEventInviteStatus::Write()
{
    _worldPacket << InviteGuid;
    _worldPacket << uint64(EventID);
    _worldPacket.AppendPackedTime(Date);
    _worldPacket << uint32(Flags);
    _worldPacket << uint8(Status);
    _worldPacket.AppendPackedTime(ResponseTime);

    _worldPacket.WriteBit(ClearPending);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarEventInviteRemoved::Write()
{
    _worldPacket << InviteGuid;
    _worldPacket << uint64(EventID);
    _worldPacket << uint32(Flags);

    _worldPacket.WriteBit(ClearPending);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarEventInviteModeratorStatus::Write()
{
    _worldPacket << InviteGuid;
    _worldPacket << uint64(EventID);
    _worldPacket << uint8(Status);

    _worldPacket.WriteBit(ClearPending);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarEventInviteRemovedAlert::Write()
{
    _worldPacket << uint64(EventID);
    _worldPacket.AppendPackedTime(Date);
    _worldPacket << uint32(Flags);
    _worldPacket << uint8(Status);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarEventUpdatedAlert::Write()
{
    _worldPacket << uint64(EventClubID);
    _worldPacket << uint64(EventID);

    _worldPacket.AppendPackedTime(OriginalDate);
    _worldPacket.AppendPackedTime(Date);
    _worldPacket << uint32(LockDate);
    _worldPacket << uint32(Flags);
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
    _worldPacket.AppendPackedTime(Date);

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
    _worldPacket << uint32(ServerTime);
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
    _worldPacket << uint32(ServerTime);
    _worldPacket << int32(MapID);
    _worldPacket << uint32(DifficultyID);
    _worldPacket << int32(NewTimeRemaining);
    _worldPacket << int32(OldTimeRemaining);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarEventInitialInvites::Write()
{
    _worldPacket << uint32(Invites.size());
    for (auto const& invite : Invites)
    {
        _worldPacket << invite.InviteGuid;
        _worldPacket << uint8(invite.Level);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarEventInviteStatusAlert::Write()
{
    _worldPacket << uint64(EventID);
    _worldPacket.AppendPackedTime(Date);
    _worldPacket << uint32(Flags);
    _worldPacket << uint8(Status);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarEventInviteNotesAlert::Write()
{
    _worldPacket << uint64(EventID);

    _worldPacket.WriteBits(Notes.size(), 8);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(Notes);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarEventInviteNotes::Write()
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
