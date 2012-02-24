/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

/*

DROP TABLE IF EXISTS `calendar_events`;
CREATE TABLE IF NOT EXISTS `calendar_events` (
  `id` int(11) unsigned NOT NULL DEFAULT '0',
  `creator` int(11) unsigned NOT NULL DEFAULT '0',
  `title` varchar(255) NOT NULL DEFAULT '',
  `description` varchar(255) NOT NULL DEFAULT '',
  `type` tinyint(1) unsigned NOT NULL DEFAULT '4',
  `dungeon` tinyint(3) NOT NULL DEFAULT '-1',
  `eventtime` int(10) unsigned NOT NULL DEFAULT '0',
  `flags` int(10) unsigned NOT NULL DEFAULT '0',
  `repeatable` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `time2` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
);

DROP TABLE IF EXISTS `calendar_invites`;
CREATE TABLE IF NOT EXISTS `calendar_invites` (
  `id` int(11) unsigned NOT NULL DEFAULT '0',
  `event` int(11) unsigned NOT NULL DEFAULT '0',
  `invitee` int(11) unsigned NOT NULL DEFAULT '0',
  `sender` int(11) unsigned NOT NULL DEFAULT '0',
  `status` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `statustime` int(10) unsigned NOT NULL DEFAULT '0',
  `rank` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `text` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`)
);
*/

#include "CalendarMgr.h"
#include "QueryResult.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "Player.h"
#include "ObjectAccessor.h"

CalendarMgr::CalendarMgr() :
    _eventNum(0), _inviteNum(0)
{
}

CalendarMgr::~CalendarMgr()
{
}

uint32 CalendarMgr::GetPlayerNumPending(uint64 guid)
{
    if (!guid)
        return 0;

    CalendarPlayerinviteIdMap::const_iterator itr = _playerInvites.find(guid);
    if (itr == _playerInvites.end())
        return 0;

    uint32 pendingNum = 0;
    for (CalendarinviteIdList::const_iterator it = itr->second.begin(); it != itr->second.end(); ++it)
        if (CalendarInvite* invite = GetInvite(*it))
            if (invite->GetRank() != CALENDAR_RANK_OWNER
                && invite->GetStatus() != CALENDAR_STATUS_CONFIRMED
                && invite->GetStatus() != CALENDAR_STATUS_8
                && invite->GetStatus() != CALENDAR_STATUS_9) // FIXME Check the proper value
                ++pendingNum;

    return pendingNum;
}

CalendarinviteIdList const& CalendarMgr::GetPlayerInvites(uint64 guid)
{
    return _playerInvites[guid];
}

CalendarEventIdList const& CalendarMgr::GetPlayerEvents(uint64 guid)
{
    return _playerEvents[guid];
}

CalendarInvite* CalendarMgr::GetInvite(uint64 inviteId)
{
    CalendarInviteMap::iterator it = _invites.find(inviteId);
    if (it != _invites.end())
        return &(it->second);

    sLog->outError("CalendarMgr::GetInvite: [" UI64FMTD "] not found!", inviteId);
    return NULL;
}

CalendarEvent* CalendarMgr::GetEvent(uint64 eventId)
{
    CalendarEventMap::iterator it = _events.find(eventId);
    if (it != _events.end())
        return &(it->second);

    sLog->outError("CalendarMgr::GetEvent: [" UI64FMTD "] not found!", eventId);
    return NULL;
}

uint64 CalendarMgr::GetFreeEventId()
{
    return ++_eventNum;
}
uint64 CalendarMgr::GetFreeInviteId()
{
    return ++_inviteNum;
}

void CalendarMgr::LoadFromDB()
{
    /*
    uint32 count = 0;
    //                                                       0   1        2      3            4     5        6          7      8           9
    if (QueryResult result = CharacterDatabase.Query("SELECT id, creator, title, description, type, dungeon, eventtime, flags, repeatable, time2 FROM calendar_events"))
        do
        {
            Field * fields = result->Fetch();

            uint64 eventId = fields[0].GetUInt64();
            CalendarEvent& calendarEvent = _events[eventId];

            calendarEvent.SetEventId(eventId);
            calendarEvent.SetCreatorGUID(fields[1].GetUInt64());
            calendarEvent.SetTitle(fields[2].GetString());
            calendarEvent.SetDescription(fields[3].GetString());
            calendarEvent.SetType(fields[4].GetUInt8());
            calendarEvent.SetDungeonId(fields[5].GetInt32());
            calendarEvent.SetTime(fields[6].GetUInt32());
            calendarEvent.SetFlags(fields[7].GetUInt32());
            calendarEvent.SetRepeatable(fields[8].GetBool());
            calendarEvent.SetTimeZoneTime(fields[9].GetUInt32());
            ++count;
        }
        while (result->NextRow());

    sLog->outString(">> Loaded %u calendar events", count);
    count = 0;

    //                                                       0   1      2        3       4       5           6     7
    if (QueryResult result = CharacterDatabase.Query("SELECT id, event, invitee, sender, status, statustime, rank, text FROM calendar_invites"))
        do
        {
            Field * fields = result->Fetch();

            uint64 inviteId = fields[0].GetUInt64();
            uint64 eventId = fields[1].GetUInt64();

            CalendarInvite& invite = _invites[inviteId];

            invite.SetEventId(eventId);
            invite.SetInvitee(fields[2].GetUInt64());
            invite.SetSenderGUID(fields[3].GetUInt64());
            invite.SetStatus(fields[4].GetUInt8());
            invite.SetStatusTime(fields[5].GetUInt32());
            invite.SetRank(fields[6].GetUInt8());
            invite.SetText(fields[7].GetString());

            CalendarEvent& calendarEvent = _events[eventId];
            calendarEvent.AddInvite(inviteId);
        }
        while (result->NextRow());

    sLog->outString(">> Loaded %u calendar Invites", count);
    */
}

CalendarEvent* CalendarMgr::CheckPermisions(uint64 eventId, Player* player, uint64 inviteId, CalendarRanks minRank)
{
    if (!player)
        return NULL;    // CALENDAR_ERROR_INTERNAL

    CalendarEvent* calendarEvent = GetEvent(eventId);
    if (!calendarEvent)
    {
        player->GetSession()->SendCalendarCommandResult(CALENDAR_ERROR_EVENT_INVALID);
        return NULL;
    }

    CalendarInvite* invite = GetInvite(inviteId);
    if (!invite)
    {
        player->GetSession()->SendCalendarCommandResult(CALENDAR_ERROR_NO_INVITE);
        return NULL;
    }

    if (!calendarEvent->HasInvite(inviteId))
    {
        player->GetSession()->SendCalendarCommandResult(CALENDAR_ERROR_NOT_INVITED);
        return NULL;
    }

    if (invite->GetEventId() != calendarEvent->GetEventId() || invite->GetInvitee() != player->GetGUID())
    {
        player->GetSession()->SendCalendarCommandResult(CALENDAR_ERROR_INTERNAL);
        return NULL;
    }

    if (invite->GetRank() < minRank)
    {
        player->GetSession()->SendCalendarCommandResult(CALENDAR_ERROR_PERMISSIONS);
        return NULL;
    }

    return calendarEvent;
}

void CalendarMgr::AddAction(CalendarAction const& action)
{
    switch (action.GetAction())
    {
        case CALENDAR_ACTION_ADD_EVENT:
        {
            if (AddEvent(action.Event) && AddInvite(action.Invite))
            {
                SendCalendarEventInviteAlert(action.Event, action.Invite);
                SendCalendarEvent(action.Event, CALENDAR_SENDTYPE_ADD);
            }
            break;
        }
        case CALENDAR_ACTION_MODIFY_EVENT:
        {
            uint64 eventId = action.Event.GetEventId();
            CalendarEvent* calendarEvent = CheckPermisions(eventId, action.GetPlayer(), action.GetInviteId(), CALENDAR_RANK_MODERATOR);
            if (!calendarEvent)
                return;

            calendarEvent->SetEventId(action.Event.GetEventId());
            calendarEvent->SetType(action.Event.GetType());
            calendarEvent->SetFlags(action.Event.GetFlags());
            calendarEvent->SetTime(action.Event.GetTime());
            calendarEvent->SetTimeZoneTime(action.Event.GetTimeZoneTime());
            calendarEvent->SetRepeatable(action.Event.GetRepeatable());
            calendarEvent->SetDungeonId(action.Event.GetDungeonId());
            calendarEvent->SetTitle(action.Event.GetTitle());
            calendarEvent->SetDescription(action.Event.GetDescription());
            calendarEvent->SetMaxInvites(action.Event.GetMaxInvites());

            CalendarinviteIdList const& invites = calendarEvent->GetInviteIdList();
            for (CalendarinviteIdList::const_iterator itr = invites.begin(); itr != invites.end(); ++itr)
                if (CalendarInvite* invite = GetInvite(*itr))
                    SendCalendarEventUpdateAlert(invite->GetInvitee(), *calendarEvent, CALENDAR_SENDTYPE_ADD);

            break;
        }
        case CALENDAR_ACTION_COPY_EVENT:
        {
            CalendarEvent* calendarEvent = CheckPermisions(action.Event.GetEventId(), action.GetPlayer(), action.GetInviteId(), CALENDAR_RANK_OWNER);

            if (!calendarEvent)
                return;

            uint64 eventId = GetFreeEventId();
            CalendarEvent newEvent(eventId);
            newEvent.SetType(calendarEvent->GetType());
            newEvent.SetFlags(calendarEvent->GetFlags());
            newEvent.SetTime(action.Event.GetTime());
            newEvent.SetTimeZoneTime(calendarEvent->GetTimeZoneTime());
            newEvent.SetRepeatable(calendarEvent->GetRepeatable());
            newEvent.SetDungeonId(calendarEvent->GetDungeonId());
            newEvent.SetTitle(calendarEvent->GetTitle());
            newEvent.SetDescription(calendarEvent->GetDescription());
            newEvent.SetMaxInvites(calendarEvent->GetMaxInvites());
            newEvent.SetCreatorGUID(calendarEvent->GetCreatorGUID());
            newEvent.SetGuildId(calendarEvent->GetGuildId());

            CalendarinviteIdList const invites = calendarEvent->GetInviteIdList();
            for (CalendarinviteIdList::const_iterator itr = invites.begin(); itr != invites.end(); ++itr)
            {
                if (CalendarInvite* invite = GetInvite(*itr))
                {
                    uint64 inviteId = GetFreeInviteId();
                    CalendarInvite newInvite(inviteId);
                    newInvite.SetEventId(eventId);
                    newInvite.SetSenderGUID(action.GetPlayer()->GetGUID());
                    newInvite.SetInvitee(invite->GetInvitee());
                    newInvite.SetStatus(invite->GetStatus());
                    newInvite.SetStatusTime(invite->GetStatusTime());
                    newInvite.SetText(invite->GetText());
                    newInvite.SetRank(invite->GetRank());
                    if (AddInvite(newInvite))
                    {
                        SendCalendarEventInviteAlert(newEvent, newInvite);
                        newEvent.AddInvite(inviteId);
                    }
                }
            }

            if (AddEvent(newEvent))
                SendCalendarEvent(newEvent, CALENDAR_SENDTYPE_COPY);

            break;
        }
        case CALENDAR_ACTION_REMOVE_EVENT:
        {
            uint64 eventId = action.Event.GetEventId();
            uint32 flags = action.Event.GetFlags();
            // FIXME - Use of Flags here!

            CalendarEvent* calendarEvent = CheckPermisions(eventId, action.GetPlayer(), action.GetInviteId(), CALENDAR_RANK_OWNER);
            if (!calendarEvent)
                return;

            CalendarinviteIdList const& inviteIds = calendarEvent->GetInviteIdList();
            for (CalendarinviteIdList::const_iterator it = inviteIds.begin(); it != inviteIds.end(); ++it)
                if (uint64 invitee = RemoveInvite(*it))
                    SendCalendarEventRemovedAlert(invitee, *calendarEvent);

            RemoveEvent(eventId);
            break;
        }
        case CALENDAR_ACTION_ADD_EVENT_INVITE:
        {
            uint64 eventId = action.Invite.GetEventId();
            CalendarEvent* calendarEvent = CheckPermisions(eventId, action.GetPlayer(), action.GetInviteId(), CALENDAR_RANK_MODERATOR);
            if (!calendarEvent)
                return;

            if (AddInvite(action.Invite))
            {
                calendarEvent->AddInvite(action.Invite.GetInviteId());
                SendCalendarEventInvite(action.Invite, (!(calendarEvent->GetFlags() & CALENDAR_FLAG_INVITES_LOCKED) &&
                    !action.Invite.GetStatusTime()));
                SendCalendarEventInviteAlert(*calendarEvent, action.Invite);
            }

            break;
        }
        case CALENDAR_ACTION_SIGNUP_TO_EVENT:
        {
            uint64 eventId = action.Event.GetEventId();
            CalendarEvent* calendarEvent = GetEvent(eventId);
            CheckPermisions(eventId, action.GetPlayer(), action.GetInviteId(), CALENDAR_RANK_MODERATOR);

            if (!calendarEvent || !(calendarEvent->GetFlags() & CALENDAR_FLAG_GUILD_ONLY)
                || !calendarEvent->GetGuildId() || calendarEvent->GetGuildId() != action.GetExtraData())
                return;

            uint8 status = action.Invite.GetStatus();

            if (status == CALENDAR_STATUS_INVITED)
                status = CALENDAR_STATUS_CONFIRMED;
            else if (status == CALENDAR_STATUS_ACCEPTED)
                status = CALENDAR_STATUS_8;

            CalendarInvite newInvite(GetFreeInviteId());
            newInvite.SetStatus(status);
            newInvite.SetStatusTime(uint32(time(NULL)));
            newInvite.SetEventId(eventId);
            newInvite.SetInvitee(action.GetPlayer()->GetGUID());
            newInvite.SetSenderGUID(action.GetPlayer()->GetGUID());

            if (AddInvite(newInvite))
                SendCalendarEventInvite(newInvite, false);

            break;
        }
        case CALENDAR_ACTION_MODIFY_EVENT_INVITE:
        {
            uint64 eventId = action.Invite.GetEventId();
            uint64 inviteId = action.Invite.GetInviteId();

            CalendarEvent* calendarEvent;
            if (action.GetInviteId() != action.Invite.GetInviteId())
                calendarEvent = CheckPermisions(eventId, action.GetPlayer(), action.GetInviteId(), CALENDAR_RANK_MODERATOR);
            else
                calendarEvent = GetEvent(eventId);

            CalendarInvite* invite = GetInvite(inviteId);

            if (!calendarEvent || !invite || !calendarEvent->HasInvite(inviteId))
                return;

            invite->SetStatus(action.Invite.GetStatus());
            SendCalendarEventStatus(invite->GetSenderGUID(), *calendarEvent, *invite);
            break;
        }
        case CALENDAR_ACTION_MODIFY_MODERATOR_EVENT_INVITE:
        {
            uint64 eventId = action.Invite.GetEventId();
            uint64 inviteId = action.Invite.GetInviteId();

            CalendarEvent* calendarEvent;
            if (action.GetInviteId() != action.Invite.GetInviteId())
                calendarEvent = CheckPermisions(eventId, action.GetPlayer(), action.GetInviteId(), CALENDAR_RANK_OWNER);
            else
                calendarEvent = GetEvent(eventId);

            CalendarInvite* invite = GetInvite(inviteId);

            if (!calendarEvent || !invite || !calendarEvent->HasInvite(inviteId))
                return;

            invite->SetStatus(action.Invite.GetStatus());
            SendCalendarEventModeratorStatusAlert(*invite);
            break;
        }
        case CALENDAR_ACTION_REMOVE_EVENT_INVITE:
        {
            uint64 eventId = action.Invite.GetEventId();
            uint64 inviteId = action.Invite.GetInviteId();
            CalendarEvent* calendarEvent = CheckPermisions(eventId, action.GetPlayer(), action.GetInviteId(), CALENDAR_RANK_MODERATOR);
            if (!calendarEvent)
                return;

            // already checked in CheckPermisions
            CalendarInvite* invite = GetInvite(inviteId);
            if (calendarEvent->GetCreatorGUID() == invite->GetInvitee())
            {
                action.GetPlayer()->GetSession()->SendCalendarCommandResult(CALENDAR_ERROR_DELETE_CREATOR_FAILED);
                return;
            }

            if (uint64 invitee = RemoveInvite(inviteId))
            {
                SendCalendarEventInviteRemoveAlert(invitee, *calendarEvent, CALENDAR_STATUS_9);
                SendCalendarEventInviteRemove(action.GetPlayer()->GetGUID(), action.Invite, calendarEvent->GetFlags());
            }
            break;
        }
        default:
            break;
    }

}

bool CalendarMgr::AddEvent(CalendarEvent const& newEvent)
{
    uint64 eventId = newEvent.GetEventId();
    if (_events.find(eventId) != _events.end())
    {
        sLog->outError("CalendarMgr::AddEvent: Event [" UI64FMTD "] exists", eventId);
        return false;
    }

    _events[eventId] = newEvent;
    return true;
}

bool CalendarMgr::RemoveEvent(uint64 eventId)
{
    CalendarEventMap::iterator itr = _events.find(eventId);
    if (itr == _events.end())
    {
        sLog->outError("CalendarMgr::RemoveEvent: Event [" UI64FMTD "] does not exist", eventId);
        return false;
    }

    _events.erase(itr);

    bool val = true;

    CalendarinviteIdList const& invites = itr->second.GetInviteIdList();
    for (CalendarinviteIdList::const_iterator itr = invites.begin(); itr != invites.end(); ++itr)
    {
        CalendarInvite* invite = GetInvite(*itr);
        if (!invite || !RemovePlayerEvent(invite->GetInvitee(), eventId))
            val = false;
    }

    return val;
}

bool CalendarMgr::AddPlayerEvent(uint64 guid, uint64 eventId)
{
    _playerEvents[guid].insert(eventId);
    return true;
}

bool CalendarMgr::RemovePlayerEvent(uint64 guid, uint64 eventId)
{
    _playerEvents[guid].erase(eventId);
    return true;
}

bool CalendarMgr::AddInvite(CalendarInvite const& newInvite)
{
    uint64 inviteId = newInvite.GetInviteId();
    if (!inviteId)
    {
        sLog->outError("CalendarMgr::AddInvite: Cant add Invite 0");
        return false;
    }

    if (_invites.find(inviteId) != _invites.end())
    {
        sLog->outError("CalendarMgr::AddInvite: Invite [" UI64FMTD "] exists", inviteId);
        return false;
    }

    _invites[inviteId] = newInvite;
    uint64 guid = newInvite.GetInvitee();
    bool inviteAdded = AddPlayerInvite(guid, inviteId);
    bool eventAdded = AddPlayerEvent(guid, newInvite.GetEventId());
    return eventAdded && inviteAdded;
}

uint64 CalendarMgr::RemoveInvite(uint64 inviteId)
{
    CalendarInviteMap::iterator itr = _invites.find(inviteId);
    if (itr == _invites.end())
    {
        sLog->outError("CalendarMgr::RemoveInvite: Invite [" UI64FMTD "] does not exist", inviteId);
        return 0;
    }

    uint64 invitee = itr->second.GetInvitee();
    _invites.erase(itr);

    return RemovePlayerInvite(invitee, inviteId) ? invitee : 0;
}

bool CalendarMgr::AddPlayerInvite(uint64 guid, uint64 inviteId)
{
    _playerInvites[guid].insert(inviteId);
    return true;
}

bool CalendarMgr::RemovePlayerInvite(uint64 guid, uint64 inviteId)
{
    _playerInvites[guid].erase(inviteId);
    return true;
}

void CalendarMgr::SendCalendarEvent(CalendarEvent const& calendarEvent, CalendarSendEventType type)
{
    if (Player* player = ObjectAccessor::FindPlayer(calendarEvent.GetCreatorGUID()))
        player->GetSession()->SendCalendarEvent(calendarEvent, type);
}

void CalendarMgr::SendCalendarEventInvite(CalendarInvite const& invite, bool pending)
{
    if (Player* player = ObjectAccessor::FindPlayer(invite.GetSenderGUID()))
        player->GetSession()->SendCalendarEventInvite(invite, pending);
}

void CalendarMgr::SendCalendarEventInviteAlert(CalendarEvent const& calendarEvent, CalendarInvite const& invite)
{
    if (Player* player = ObjectAccessor::FindPlayer(invite.GetInvitee()))
        player->GetSession()->SendCalendarEventInviteAlert(calendarEvent, invite);
}

void CalendarMgr::SendCalendarEventUpdateAlert(uint64 guid, CalendarEvent const& calendarEvent, CalendarSendEventType type)
{
    if (Player* player = ObjectAccessor::FindPlayer(guid))
        player->GetSession()->SendCalendarEventUpdateAlert(calendarEvent, type);
}

void CalendarMgr::SendCalendarEventStatus(uint64 guid, CalendarEvent const& calendarEvent, CalendarInvite const& invite)
{
    if (Player* player = ObjectAccessor::FindPlayer(guid))
        player->GetSession()->SendCalendarEventStatus(calendarEvent, invite);
}

void CalendarMgr::SendCalendarEventRemovedAlert(uint64 guid, CalendarEvent const& calendarEvent)
{
    if (Player* player = ObjectAccessor::FindPlayer(guid))
        player->GetSession()->SendCalendarEventRemovedAlert(calendarEvent);
}

void CalendarMgr::SendCalendarEventInviteRemoveAlert(uint64 guid, CalendarEvent const& calendarEvent, uint8 status)
{
    if (Player* player = ObjectAccessor::FindPlayer(guid))
        player->GetSession()->SendCalendarEventInviteRemoveAlert(calendarEvent, status);
}

void CalendarMgr::SendCalendarEventInviteRemove(uint64 guid, CalendarInvite const& invite, uint32 flags)
{
    if (Player* player = ObjectAccessor::FindPlayer(guid))
        player->GetSession()->SendCalendarEventInviteRemove(invite, flags);
}

void CalendarMgr::SendCalendarEventModeratorStatusAlert(CalendarInvite const& invite)
{
    if (Player* player = ObjectAccessor::FindPlayer(invite.GetInvitee()))
        player->GetSession()->SendCalendarEventModeratorStatusAlert(invite);
}
