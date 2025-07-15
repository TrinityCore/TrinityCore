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
    data << eventInfo.EventName;
    data << uint32(eventInfo.EventType);
    data << eventInfo.Date;
    data << uint32(eventInfo.Flags);
    data << int32(eventInfo.TextureID);
    data << eventInfo.OwnerGuid.WriteAsPacked();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Calendar::CalendarSendCalendarRaidLockoutInfo const& lockoutInfo)
{
    data << int32(lockoutInfo.MapID);
    data << uint32(lockoutInfo.DifficultyID);
    data << int32(lockoutInfo.ExpireTime);
    data << uint64(lockoutInfo.InstanceID);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Calendar::CalendarSendCalendarInviteInfo const& inviteInfo)
{
    data << uint64(inviteInfo.EventID);
    data << uint64(inviteInfo.InviteID);
    data << uint8(inviteInfo.Status);
    data << uint8(inviteInfo.Moderator);
    data << uint8(inviteInfo.InviteType);
    data << inviteInfo.InviterGuid.WriteAsPacked();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Calendar::CalendarSendCalendarHolidayInfo const& holidayInfo)
{
    data << uint32(holidayInfo.HolidayID);
    data << uint32(holidayInfo.Region);
    data << uint32(holidayInfo.Looping);
    data << uint32(holidayInfo.Priority);
    data << uint32(holidayInfo.FilterType);

    for (uint8 j = 0; j < MAX_HOLIDAY_DATES; ++j)
        data << holidayInfo.Date[j];

    data.append(holidayInfo.Duration.data(), holidayInfo.Duration.size());
    data.append(holidayInfo.CalendarFlags.data(), holidayInfo.CalendarFlags.size());

    data << holidayInfo.TextureFilename;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Calendar::CalendarSendCalendarRaidResetInfo const& raidResetInfo)
{
    data << int32(raidResetInfo.MapID);
    data << int32(raidResetInfo.Duration);
    data << int32(raidResetInfo.Offset);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Calendar::CalendarEventInviteInfo const& inviteInfo)
{
    data << inviteInfo.Guid.WriteAsPacked();
    data << uint8(inviteInfo.Level);
    data << uint8(inviteInfo.Status);
    data << uint8(inviteInfo.Moderator);
    data << uint8(inviteInfo.InviteType);
    data << uint64(inviteInfo.InviteID);
    data << inviteInfo.ResponseTime;
    data << inviteInfo.Notes;

    return data;
}

void WorldPackets::Calendar::CalendarGetEvent::Read()
{
    _worldPacket >> EventID;
}

void WorldPackets::Calendar::CalendarGuildFilter::Read()
{
    _worldPacket >> MinLevel;
    _worldPacket >> MaxLevel;
    _worldPacket >> MaxRankOrder;
}

void WorldPackets::Calendar::CalendarArenaTeam::Read()
{
    _worldPacket >> ArenaTeamId;
}

ByteBuffer& operator>>(ByteBuffer& buffer, WorldPackets::Calendar::CalendarAddEventInviteInfo& invite)
{
    buffer >> invite.Guid.ReadAsPacked();
    buffer >> invite.Status;
    buffer >> invite.Moderator;

    return buffer;
}

void WorldPackets::Calendar::CalendarAddEvent::Read()
{
    _worldPacket >> Title;
    _worldPacket >> Description;
    _worldPacket >> EventType;
    _worldPacket.read_skip<uint8>(); // Repeatable
    _worldPacket >> MaxSize;
    _worldPacket >> TextureID;
    _worldPacket >> Time;
    _worldPacket >> LockDate;
    _worldPacket >> Flags;
    Invites.resize(_worldPacket.read<uint32>());
    for (CalendarAddEventInviteInfo& invite : Invites)
        _worldPacket >> invite;
}

void WorldPackets::Calendar::CalendarUpdateEvent::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> ModeratorID;
    _worldPacket >> Title;
    _worldPacket >> Description;
    _worldPacket >> EventType;
    _worldPacket.read_skip<uint8>(); // Repeatable
    _worldPacket >> MaxSize;
    _worldPacket >> TextureID;
    _worldPacket >> Time;
    _worldPacket >> LockDate;
    _worldPacket >> Flags;
}

void WorldPackets::Calendar::CalendarRemoveEvent::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> ModeratorID;
    _worldPacket >> IsSignUp;
}

void WorldPackets::Calendar::CalendarCopyEvent::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> ModeratorID;
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
    _worldPacket >> Name;
    _worldPacket >> Creating;
    _worldPacket >> IsSignUp;
}

void WorldPackets::Calendar::CalendarEventSignUp::Read()
{
    _worldPacket >> EventID;
    _worldPacket >> Tentative;
}

void WorldPackets::Calendar::CalendarRemoveInvite::Read()
{
    _worldPacket >> Guid.ReadAsPacked();
    _worldPacket >> InviteID;
    _worldPacket >> ModeratorID;
    _worldPacket >> EventID;
}

void WorldPackets::Calendar::CalendarStatus::Read()
{
    _worldPacket >> Guid.ReadAsPacked();
    _worldPacket >> EventID;
    _worldPacket >> InviteID;
    _worldPacket >> ModeratorID;
    _worldPacket >> Status;
}

void WorldPackets::Calendar::SetSavedInstanceExtend::Read()
{
    _worldPacket >> MapID;
    _worldPacket >> DifficultyID;
    _worldPacket >> Extend;
}

void WorldPackets::Calendar::CalendarModeratorStatusQuery::Read()
{
    _worldPacket >> Guid.ReadAsPacked();
    _worldPacket >> EventID;
    _worldPacket >> InviteID;
    _worldPacket >> ModeratorID;
    _worldPacket >> Status;
}

WorldPacket const* WorldPackets::Calendar::CalendarInviteAdded::Write()
{
    _worldPacket << InviteGuid.WriteAsPacked();
    _worldPacket << uint64(EventID);
    _worldPacket << uint64(InviteID);
    _worldPacket << uint8(Level);
    _worldPacket << uint8(Status);
    _worldPacket << uint8(Type);
    if (Type == 1)
        _worldPacket << ResponseTime;

    _worldPacket << uint8(ClearPending);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarSendCalendar::Write()
{
    _worldPacket << uint32(Invites.size());
    for (CalendarSendCalendarInviteInfo const& invite : Invites)
        _worldPacket << invite;

    _worldPacket << uint32(Events.size());
    for (CalendarSendCalendarEventInfo const& event : Events)
        _worldPacket << event;

    _worldPacket << uint32(ServerNow);
    _worldPacket << ServerTime;

    _worldPacket << uint32(RaidLockouts.size());
    for (CalendarSendCalendarRaidLockoutInfo const& lockout : RaidLockouts)
        _worldPacket << lockout;

    _worldPacket << uint32(RaidOrigin);

    _worldPacket << uint32(RaidResets.size());
    for (CalendarSendCalendarRaidResetInfo const& reset : RaidResets)
        _worldPacket << reset;

    _worldPacket << uint32(Holidays.size());
    for (CalendarSendCalendarHolidayInfo const& holiday : Holidays)
        _worldPacket << holiday;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarSendEvent::Write()
{
    _worldPacket << uint8(EventType);
    _worldPacket << OwnerGuid.WriteAsPacked();
    _worldPacket << uint64(EventID);
    _worldPacket << EventName;
    _worldPacket << Description;
    _worldPacket << uint8(GetEventType);
    _worldPacket << uint8(CALENDAR_REPEAT_NEVER);   // repeatable
    _worldPacket << uint32(CALENDAR_MAX_INVITES);
    _worldPacket << int32(TextureID);
    _worldPacket << uint32(Flags);
    _worldPacket << Date;
    _worldPacket << LockDate;
    _worldPacket << uint32(EventGuildID);
    _worldPacket << uint32(Invites.size());
    for (CalendarEventInviteInfo const& invite : Invites)
        _worldPacket << invite;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarInviteAlert::Write()
{
    _worldPacket << uint64(EventID);
    _worldPacket << EventName;
    _worldPacket << Date;
    _worldPacket << uint32(Flags);
    _worldPacket << uint32(EventType);
    _worldPacket << int32(TextureID);
    _worldPacket << uint64(InviteID);
    _worldPacket << uint8(Status);
    _worldPacket << uint8(ModeratorStatus);
    _worldPacket << OwnerGuid.WriteAsPacked();
    _worldPacket << InvitedByGuid.WriteAsPacked();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarInviteStatus::Write()
{
    _worldPacket << InviteGuid.WriteAsPacked();
    _worldPacket << uint64(EventID);
    _worldPacket << Date;
    _worldPacket << uint32(Flags);
    _worldPacket << uint8(Status);
    _worldPacket << uint8(ClearPending);
    _worldPacket << ResponseTime;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarInviteRemoved::Write()
{
    _worldPacket << InviteGuid.WriteAsPacked();
    _worldPacket << uint64(EventID);
    _worldPacket << uint32(Flags);
    _worldPacket << uint8(ClearPending);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarModeratorStatus::Write()
{
    _worldPacket << InviteGuid.WriteAsPacked();
    _worldPacket << uint64(EventID);
    _worldPacket << uint8(Status);
    _worldPacket << uint8(ClearPending);

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
    _worldPacket << uint8(ClearPending);
    _worldPacket << uint64(EventID);
    _worldPacket << OriginalDate;
    _worldPacket << uint32(Flags);
    _worldPacket << Date;
    _worldPacket << uint8(EventType);
    _worldPacket << uint32(TextureID);
    _worldPacket << EventName;
    _worldPacket << Description;
    _worldPacket << uint8(CALENDAR_REPEAT_NEVER);   // repeatable
    _worldPacket << uint32(CALENDAR_MAX_INVITES);
    _worldPacket << LockDate;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarEventRemovedAlert::Write()
{
    _worldPacket << uint8(ClearPending);
    _worldPacket << uint64(EventID);
    _worldPacket << Date;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarSendNumPending::Write()
{
    _worldPacket << uint32(NumPending);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarCommandResult::Write()
{
    _worldPacket << uint32(Command);
    _worldPacket << "";
    _worldPacket << Name;
    _worldPacket << uint32(Result);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarRaidLockoutAdded::Write()
{
    _worldPacket << ServerTime;
    _worldPacket << int32(MapID);
    _worldPacket << uint32(DifficultyID);
    _worldPacket << int32(TimeRemaining);
    _worldPacket << uint64(InstanceID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarRaidLockoutRemoved::Write()
{
    _worldPacket << int32(MapID);
    _worldPacket << uint32(DifficultyID);
    _worldPacket << int32(TimeRemaining);
    _worldPacket << uint64(InstanceID);

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

WorldPacket const* WorldPackets::Calendar::CalendarEventInitialInvites::Write()
{
    _worldPacket << uint32(Invites.size());
    for (CalendarEventInitialInviteInfo const& invite : Invites)
    {
        _worldPacket << invite.InviteGuid.WriteAsPacked();
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
    _worldPacket << Notes;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Calendar::CalendarInviteNotes::Write()
{
    _worldPacket << InviteGuid.WriteAsPacked();
    _worldPacket << uint64(EventID);
    _worldPacket << Notes;
    _worldPacket << uint8(ClearPending);

    return &_worldPacket;
}

void WorldPackets::Calendar::CalendarComplain::Read()
{
    _worldPacket >> InvitedByGUID;
    _worldPacket >> EventID;
    _worldPacket >> InviteID;
}
