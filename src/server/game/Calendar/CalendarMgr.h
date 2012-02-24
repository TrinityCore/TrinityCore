/*
 * Copyright (C) 2008-2012 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef TRINITY_CALENDARMGR_H
#define TRINITY_CALENDARMGR_H

#include <ace/Singleton.h>
#include "Calendar.h"
#include "Player.h"

class CalendarMgr
{
    friend class ACE_Singleton<CalendarMgr, ACE_Null_Mutex>;

public:
    CalendarMgr();
    ~CalendarMgr();

    CalendarInvite const* GetInvite(uint64 inviteId)
    {
        CalendarInviteMap::const_iterator itr = _inviteMap.find(inviteId);
        if(itr != _inviteMap.end())
            return &itr->second;
        return NULL;
    }

    void AddInvite(CalendarInvite invite) { _inviteMap[invite.Id] = invite; }
    void RemoveInvite(uint64 inviteId) { _inviteMap.erase(inviteId); }

    CalendarEvent const* GetEvent(uint64 eventId)
    {
        CalendarEventMap::const_iterator itr = _eventMap.find(eventId);
        if(itr != _eventMap.end())
            return &itr->second;
        return NULL;
    }

    void AddEvent(CalendarEvent event) { _eventMap[event.Id] = event; }
    void RemoveEvent(uint64 eventId) { _eventMap.erase(eventId); }

    void AppendInvitesToCalendarPacketForPlayer(WorldPacket& data, Player* player);
    void AppendEventsToCalendarPacketForPlayer(WorldPacket& data, Player* player);

    uint64 GetNextEventId() { return ++_currentEventId; }
    uint64 GetNextInviteId() { return ++_currentInviteId; }

private:
    CalendarInviteMap _inviteMap;
    CalendarEventMap _eventMap;
    uint64 _currentEventId;
    uint64 _currentInviteId;
};

#define sCalendarMgr ACE_Singleton<CalendarMgr, ACE_Null_Mutex>::instance()

#endif
