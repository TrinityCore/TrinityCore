/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Calendar.h"

CalendarInvite::CalendarInvite(uint64 _inviteId /* = 0 */): inviteId(_inviteId),
eventId(0), invitee(0), senderGUID(0), statusTime(0), status(0), rank(0)
{
}

CalendarInvite::~CalendarInvite()
{
}

void CalendarInvite::SetInviteId(uint64 _inviteId)
{
    inviteId = _inviteId;
}

uint64 CalendarInvite::GetInviteId() const
{
    return inviteId;
}

void CalendarInvite::SetEventId(uint64 _eventId)
{
    eventId = _eventId;
}

uint64 CalendarInvite::GetEventId() const
{
    return eventId;
}

void CalendarInvite::SetSenderGUID(uint64 _guid)
{
    senderGUID = _guid;
}

uint64 CalendarInvite::GetSenderGUID() const
{
    return senderGUID;
}

void CalendarInvite::SetInvitee(uint64 _guid)
{
    invitee = _guid;
}

uint64 CalendarInvite::GetInvitee() const
{
    return invitee;
}

void CalendarInvite::SetStatusTime(uint32 _statusTime)
{
    statusTime = _statusTime;
}

uint32 CalendarInvite::GetStatusTime() const
{
    return statusTime;
}

void CalendarInvite::SetText(std::string _text)
{
    text = _text;
}

std::string CalendarInvite::GetText() const
{
    return text;
}

void CalendarInvite::SetStatus(uint8 _status)
{
    status = _status;
}

uint8 CalendarInvite::GetStatus() const
{
    return status;
}

void CalendarInvite::SetRank(uint8 _rank)
{
    rank = _rank;
}

uint8 CalendarInvite::GetRank() const
{
    return rank;
}

CalendarEvent::CalendarEvent(uint64 _eventId /* = 0 */) : eventId(_eventId),
creatorGUID(0), guildId(0), type(CALENDAR_TYPE_OTHER), dungeonId(-1),
maxInvites(0), eventTime(0), flags(0), repeatable(false), timezoneTime(0),
title(""), description("")
{
}

CalendarEvent::~CalendarEvent()
{
}

void CalendarEvent::SetEventId(uint64 _eventId)
{
    eventId = _eventId;
}

uint64 CalendarEvent::GetEventId() const
{
    return eventId;
}

void CalendarEvent::SetCreatorGUID(uint64 _guid)
{
    creatorGUID = _guid;
}

uint64 CalendarEvent::GetCreatorGUID() const
{
    return creatorGUID;
}

void CalendarEvent::SetGuildId(uint32 _guildId)
{
    guildId = _guildId;
}

uint32 CalendarEvent::GetGuildId() const
{
    return guildId;
}

void CalendarEvent::SetTitle(std::string _title)
{
    title = _title;
}

std::string CalendarEvent::GetTitle() const
{
    return title;
}

void CalendarEvent::SetDescription(std::string _description)
{
    description = _description;
}

std::string CalendarEvent::GetDescription() const
{
    return description;
}

void CalendarEvent::SetType(uint8 _type)
{
    type = _type;
}

uint8 CalendarEvent::GetType() const
{
    return type;
}

void CalendarEvent::SetMaxInvites(uint32 max)
{
    maxInvites = max;
}

uint32 CalendarEvent::GetMaxInvites() const
{
    return maxInvites;
}

void CalendarEvent::SetDungeonId(int32 _dungeonId)
{
    dungeonId = _dungeonId;
}

int32 CalendarEvent::GetDungeonId() const
{
    return dungeonId;
}

void CalendarEvent::SetTime(uint32 _eventTime)
{
    eventTime = _eventTime;
}

uint32 CalendarEvent::GetTime() const
{
    return eventTime;
}

void CalendarEvent::SetFlags(uint32 _flags)
{
    flags = _flags;
}

uint32 CalendarEvent::GetFlags() const
{
    return flags;
}

void CalendarEvent::SetRepeatable(bool _repeatable)
{
    repeatable = _repeatable;
}

uint8 CalendarEvent::GetRepeatable() const
{
    return repeatable;
}

void CalendarEvent::SetTimeZoneTime(uint32 _timezoneTime)
{
    timezoneTime = _timezoneTime;
}

uint32 CalendarEvent::GetTimeZoneTime() const
{
    return timezoneTime;
}

void CalendarEvent::AddInvite(uint64 inviteId)
{
    if (inviteId)
        _invites.insert(inviteId);
}

void CalendarEvent::RemoveInvite(uint64 inviteId)
{
    _invites.erase(inviteId);
}

bool CalendarEvent::HasInvite(uint64 inviteId) const
{
    return _invites.find(inviteId) != _invites.end();
}

CalendarinviteIdList const& CalendarEvent::GetInviteIdList() const
{
    return _invites;
}

void CalendarEvent::SetInviteIdList(CalendarinviteIdList const& list)
{
    _invites = list;
}

void CalendarEvent::ClearInviteIdList()
{
    _invites.clear();
}

std::string CalendarInvite::GetDebugString() const
{
    std::ostringstream data;

    data << "CalendarInvite::"
        << " inviteId: " << inviteId
        << " EventId: " << eventId
        << " Status: " << uint32(status)
        << " Invitee: " << invitee
        << " Sender: " << senderGUID
        << " Rank: " << uint32(rank)
        << " Text: " << text;

    return data.str();
}

std::string CalendarEvent::GetDebugString() const
{
    std::ostringstream data;

    data << "CalendarEvent::"
        << " EventId: " << eventId
        << " Title: " << title
        << " Description" << description
        << " Type: " << uint32(type)
        << " Max Invites: " << maxInvites
        << " Creator: " << creatorGUID
        << " Flags: " << flags
        << " Guild: " << guildId
        << " Time: " << eventTime
        << " Time2: " << timezoneTime
        << " Repeatable: " << uint32(repeatable)
        << " DungeonId: " << dungeonId;

    return data.str();
}

std::string CalendarAction::GetDebugString() const
{
    std::ostringstream data;

    data << "CalendarAction::"
        << " Action: " << GetAction()
        << " Guid: " << GetGUID()
        << " Invite Id: " << GetInviteId()
        << " Extra data: " << GetExtraData()
        << " Event: " << Event.GetDebugString()
        << " Invite: " << Invite.GetDebugString();

    return data.str();
}
