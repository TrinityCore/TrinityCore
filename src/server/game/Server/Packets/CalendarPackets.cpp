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
#include "PacketOperators.h"

namespace WorldPackets::Calendar
{
ByteBuffer& operator<<(ByteBuffer& data, CalendarSendCalendarEventInfo const& eventInfo)
{
    data << uint64(eventInfo.EventID);
    data << uint8(eventInfo.EventType);
    data << eventInfo.Date;
    data << uint16(eventInfo.Flags);
    data << int32(eventInfo.TextureID);
    data << uint64(eventInfo.EventClubID);
    data << eventInfo.OwnerGuid;

    data << SizedString::BitsSize<8>(eventInfo.EventName);
    data.FlushBits();

    data << SizedString::Data(eventInfo.EventName);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, CalendarSendCalendarRaidLockoutInfo const& lockoutInfo)
{
    data << uint64(lockoutInfo.InstanceID);
    data << int32(lockoutInfo.MapID);
    data << uint32(lockoutInfo.DifficultyID);
    data << int32(lockoutInfo.ExpireTime);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, CalendarSendCalendarInviteInfo const& inviteInfo)
{
    data << uint64(inviteInfo.EventID);
    data << uint64(inviteInfo.InviteID);
    data << uint8(inviteInfo.Status);
    data << uint8(inviteInfo.Moderator);
    data << uint8(inviteInfo.InviteType);
    data << inviteInfo.InviterGuid;
    data << Bits<1>(inviteInfo.IgnoreFriendAndGuildRestriction);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, CalendarEventInviteInfo const& inviteInfo)
{
    data << inviteInfo.Guid;
    data << uint64(inviteInfo.InviteID);

    data << uint8(inviteInfo.Level);
    data << uint8(inviteInfo.Status);
    data << uint8(inviteInfo.Moderator);
    data << uint8(inviteInfo.InviteType);
    data << inviteInfo.ResponseTime;

    data << SizedString::BitsSize<8>(inviteInfo.Notes);
    data.FlushBits();

    data << SizedString::Data(inviteInfo.Notes);

    return data;
}

void CalendarGetEvent::Read()
{
    _worldPacket >> EventID;
}

void CalendarCommunityInviteRequest::Read()
{
    _worldPacket >> ClubID;
    _worldPacket >> MinLevel;
    _worldPacket >> MaxLevel;
    _worldPacket >> MaxRankOrder;
}

ByteBuffer& operator>>(ByteBuffer& buffer, CalendarAddEventInviteInfo& invite)
{
    buffer >> invite.Guid;
    buffer >> invite.Status;
    buffer >> invite.Moderator;
    buffer >> OptionalInit(invite.BnetAccountID);
    buffer >> OptionalInit(invite.RealmAddress);
    buffer >> OptionalInit(invite.CommunityID);

    if (invite.BnetAccountID)
        buffer >> *invite.BnetAccountID;

    if (invite.RealmAddress)
        buffer >> *invite.RealmAddress;

    if (invite.CommunityID)
        buffer >> *invite.CommunityID;

    return buffer;
}

ByteBuffer& operator>>(ByteBuffer& buffer, CalendarAddEventInfo& addEventInfo)
{
    buffer >> addEventInfo.ClubID;
    buffer >> addEventInfo.EventType;
    buffer >> addEventInfo.TextureID;
    buffer >> addEventInfo.Time;
    buffer >> addEventInfo.Flags;
    buffer >> Size<uint32>(addEventInfo.Invites);

    buffer >> SizedString::BitsSize<8>(addEventInfo.Title);
    buffer >> SizedString::BitsSize<11>(addEventInfo.Description);

    for (CalendarAddEventInviteInfo& invite : addEventInfo.Invites)
        buffer >> invite;

    buffer >> SizedString::Data(addEventInfo.Title);
    buffer >> SizedString::Data(addEventInfo.Description);

    return buffer;
}

void CalendarAddEvent::Read()
{
    _worldPacket >> EventInfo;
    _worldPacket >> MaxSize;
}

ByteBuffer& operator>>(ByteBuffer& buffer, CalendarUpdateEventInfo& updateEventInfo)
{
    buffer >> updateEventInfo.ClubID;
    buffer >> updateEventInfo.EventID;
    buffer >> updateEventInfo.ModeratorID;
    buffer >> updateEventInfo.EventType;
    buffer >> updateEventInfo.TextureID;
    buffer >> updateEventInfo.Time;
    buffer >> updateEventInfo.Flags;

    buffer >> SizedString::BitsSize<8>(updateEventInfo.Title);
    buffer >> SizedString::BitsSize<11>(updateEventInfo.Description);

    buffer >> SizedString::Data(updateEventInfo.Title);
    buffer >> SizedString::Data(updateEventInfo.Description);

    return buffer;
}

void CalendarUpdateEvent::Read()
{
    _worldPacket >> EventInfo;
    _worldPacket >> MaxSize;
}

void CalendarRemoveEvent::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> ModeratorID;
    _worldPacket >> ClubID;
    _worldPacket >> Flags;
}

void CalendarCopyEvent::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> ModeratorID;
    _worldPacket >> EventClubID;
    _worldPacket >> Date;
}

void CalendarRSVP::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> InviteID;
    _worldPacket >> Status;
}

void CalendarInvite::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> ModeratorID;
    _worldPacket >> ClubID;

    _worldPacket >> SizedString::BitsSize<9>(Name);
    _worldPacket >> Bits<1>(Creating);
    _worldPacket >> Bits<1>(IsSignUp);

    _worldPacket >> SizedString::Data(Name);
}

void CalendarEventSignUp::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> ClubID;
    _worldPacket >> Bits<1>(Tentative);
}

void CalendarRemoveInvite::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> InviteID;
    _worldPacket >> ModeratorID;
    _worldPacket >> EventID;
}

void CalendarStatus::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> EventID;
    _worldPacket >> InviteID;
    _worldPacket >> ModeratorID;
    _worldPacket >> Status;
}

void SetSavedInstanceExtend::Read()
{
    _worldPacket >> MapID;
    _worldPacket >> DifficultyID;
    _worldPacket >> Bits<1>(Extend);
}

void CalendarModeratorStatusQuery::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> EventID;
    _worldPacket >> InviteID;
    _worldPacket >> ModeratorID;
    _worldPacket >> Status;
}

WorldPacket const* CalendarInviteAdded::Write()
{
    _worldPacket << InviteGuid;
    _worldPacket << uint64(EventID);
    _worldPacket << uint64(InviteID);
    _worldPacket << uint8(Level);
    _worldPacket << uint8(Status);
    _worldPacket << uint8(Type);
    _worldPacket << ResponseTime;
    _worldPacket << Bits<1>(ClearPending);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* CalendarSendCalendar::Write()
{
    _worldPacket << ServerTime;
    _worldPacket << Size<uint32>(Invites);
    _worldPacket << Size<uint32>(Events);
    _worldPacket << Size<uint32>(RaidLockouts);

    for (CalendarSendCalendarRaidLockoutInfo const& lockout : RaidLockouts)
        _worldPacket << lockout;

    for (CalendarSendCalendarInviteInfo const& invite : Invites)
        _worldPacket << invite;

    for (CalendarSendCalendarEventInfo const& event : Events)
        _worldPacket << event;

    return &_worldPacket;
}

WorldPacket const* CalendarSendEvent::Write()
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
    _worldPacket << Size<uint32>(Invites);
    _worldPacket << SizedString::BitsSize<8>(EventName);
    _worldPacket << SizedString::BitsSize<11>(Description);
    _worldPacket.FlushBits();

    for (CalendarEventInviteInfo const& invite : Invites)
        _worldPacket << invite;

    _worldPacket << SizedString::Data(EventName);
    _worldPacket << SizedString::Data(Description);

    return &_worldPacket;
}

WorldPacket const* CalendarInviteAlert::Write()
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

    _worldPacket << SizedString::BitsSize<8>(EventName);
    _worldPacket << Bits<1>(Unknown_1100);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(EventName);

    return &_worldPacket;
}

WorldPacket const* CalendarInviteStatus::Write()
{
    _worldPacket << InviteGuid;
    _worldPacket << uint64(EventID);
    _worldPacket << Date;
    _worldPacket << uint16(Flags);
    _worldPacket << uint8(Status);
    _worldPacket << ResponseTime;
    _worldPacket << Bits<1>(ClearPending);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* CalendarInviteRemoved::Write()
{
    _worldPacket << InviteGuid;
    _worldPacket << uint64(EventID);
    _worldPacket << uint16(Flags);
    _worldPacket << Bits<1>(ClearPending);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* CalendarModeratorStatus::Write()
{
    _worldPacket << InviteGuid;
    _worldPacket << uint64(EventID);
    _worldPacket << uint8(Status);
    _worldPacket << Bits<1>(ClearPending);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* CalendarInviteRemovedAlert::Write()
{
    _worldPacket << uint64(EventID);
    _worldPacket << Date;
    _worldPacket << uint16(Flags);
    _worldPacket << uint8(Status);

    return &_worldPacket;
}

WorldPacket const* CalendarEventUpdatedAlert::Write()
{
    _worldPacket << uint64(EventClubID);
    _worldPacket << uint64(EventID);

    _worldPacket << OriginalDate;
    _worldPacket << Date;
    _worldPacket << LockDate;
    _worldPacket << uint16(Flags);
    _worldPacket << uint32(TextureID);
    _worldPacket << uint8(EventType);

    _worldPacket << SizedString::BitsSize<8>(EventName);
    _worldPacket << SizedString::BitsSize<11>(Description);
    _worldPacket << Bits<1>(ClearPending);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(EventName);
    _worldPacket << SizedString::Data(Description);

    return &_worldPacket;
}

WorldPacket const* CalendarEventRemovedAlert::Write()
{
    _worldPacket << uint64(EventID);
    _worldPacket << Date;
    _worldPacket << Bits<1>(ClearPending);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* CalendarSendNumPending::Write()
{
    _worldPacket << uint32(NumPending);

    return &_worldPacket;
}

WorldPacket const* CalendarCommandResult::Write()
{
    _worldPacket << uint8(Command);
    _worldPacket << uint8(Result);
    _worldPacket << SizedString::BitsSize<9>(Name);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(Name);

    return &_worldPacket;
}

WorldPacket const* CalendarRaidLockoutAdded::Write()
{
    _worldPacket << uint64(InstanceID);
    _worldPacket << ServerTime;
    _worldPacket << int32(MapID);
    _worldPacket << uint32(DifficultyID);
    _worldPacket << int32(TimeRemaining);

    return &_worldPacket;
}

WorldPacket const* CalendarRaidLockoutRemoved::Write()
{
    _worldPacket << uint64(InstanceID);
    _worldPacket << int32(MapID);
    _worldPacket << uint32(DifficultyID);

    return &_worldPacket;
}

WorldPacket const* CalendarRaidLockoutUpdated::Write()
{
    _worldPacket << ServerTime;
    _worldPacket << int32(MapID);
    _worldPacket << uint32(DifficultyID);
    _worldPacket << int32(OldTimeRemaining);
    _worldPacket << int32(NewTimeRemaining);

    return &_worldPacket;
}

WorldPacket const* CalendarCommunityInvite::Write()
{
    _worldPacket << Size<uint32>(Invites);
    for (CalendarEventInitialInviteInfo const& invite : Invites)
    {
        _worldPacket << invite.InviteGuid;
        _worldPacket << uint8(invite.Level);
    }

    return &_worldPacket;
}

WorldPacket const* CalendarInviteStatusAlert::Write()
{
    _worldPacket << uint64(EventID);
    _worldPacket << Date;
    _worldPacket << uint16(Flags);
    _worldPacket << uint8(Status);

    return &_worldPacket;
}

WorldPacket const* CalendarInviteNotesAlert::Write()
{
    _worldPacket << uint64(EventID);
    _worldPacket << SizedString::BitsSize<8>(Notes);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(Notes);

    return &_worldPacket;
}

WorldPacket const* CalendarInviteNotes::Write()
{
    _worldPacket << InviteGuid;
    _worldPacket << uint64(EventID);

    _worldPacket << Bits<1>(ClearPending);
    _worldPacket << SizedString::BitsSize<8>(Notes);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(Notes);

    return &_worldPacket;
}

void CalendarComplain::Read()
{
    _worldPacket >> InvitedByGUID;
    _worldPacket >> EventID;
    _worldPacket >> InviteID;
}
}
