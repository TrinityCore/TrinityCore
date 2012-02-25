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

std::string CalendarInvite::GetDebugString() const
{
    std::ostringstream data;

    data << "CalendarInvite::"
        << " inviteId: " << _inviteId
        << " EventId: " << _eventId
        << " Status: " << uint32(_status)
        << " Invitee: " << _invitee
        << " Sender: " << _senderGUID
        << " Rank: " << uint32(_rank)
        << " Text: " << _text;

    return data.str();
}

void CalendarInvite::Init()
{
    _eventId = 0;
    _invitee = 0;
    _senderGUID = 0;
    _statusTime = 0;
    _status = CALENDAR_STATUS_INVITED; // default (0)?
    _rank = CALENDAR_RANK_PLAYER;
    _text = "";
}

std::string CalendarEvent::GetDebugString() const
{
    std::ostringstream data;

    data << "CalendarEvent::"
        << " EventId: " << _eventId
        << " Title: " << _title
        << " Description" << _description
        << " Type: " << uint32(_type)
        << " Max Invites: " << _maxInvites
        << " Creator: " << _creatorGUID
        << " Flags: " << _flags
        << " Guild: " << _guildId
        << " Time: " << _eventTime
        << " Time2: " << _timezoneTime
        << " Repeatable: " << uint32(_repeatable)
        << " DungeonId: " << _dungeonId;

    return data.str();
}

void CalendarEvent::Init()
{
    _creatorGUID = 0;
    _guildId = 0;
    _type = CALENDAR_TYPE_OTHER;
    _dungeonId = -1;
    _maxInvites = 0;
    _eventTime = 0;
    _flags = (CalendarFlags) 0;
    _repeatable = false;
    _timezoneTime = 0;
    _title = "";
    _description = "";

}

std::string CalendarAction::GetDebugString() const
{
    std::ostringstream data;

    data << "CalendarAction::"
        << " Action: " << GetAction()
        << " Guid: " << GetPlayer()->GetGUID()
        << " Invite Id: " << GetInviteId()
        << " Extra data: " << GetExtraData()
        << " Event: " << Event.GetDebugString()
        << " Invite: " << Invite.GetDebugString();

    return data.str();
}
