/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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


    CalendarInvite *GetInvite(uint64 inviteID)
    {
        CalendarInviteMap::const_iterator itr = _inviteMap.find(itemId);
        if(itr != _inviteMap.end())
            return &itr->second;
        return NULL;
    }

    void AddInvite(CalendarInvite invite) { _inviteMap[invite.id] = invite; }
    void RemoveInvite(uint64 inviteID) { _inviteMap.erase(inviteID); }

    CalendarEvent *GetEvent(uint64 eventID)
    {
        CalendarEventMap::const_iterator itr = _eventMap.find(eventID);
        if(itr != _eventMap.end())
            return &itr->second;
        return NULL;
    }

    void AddEvent(CalendarEvent event) { _eventMap[event.id] = event; }
    void RemoveEvent(uint64 eventID) { _eventMap.erase(eventID); }

    void AppendInvitesToCalendarPacketForPlayer(WorldPacket &data, Player *player);
    void AppendEventsToCalendarPacketForPlayer(WorldPacket &data, Player *player);

    uint64 GetNextEventID() { return ++_currentEventID; }
    uint64 GetNextInviteID() { return ++_currentInviteID; }

private:
    CalendarInviteMap _inviteMap;
    CalendarEventMap _eventMap;
    uint64 _currentEventID;
    uint64 _currentInviteID;
};

#define sCalendarMgr ACE_Singleton<CalendarMgr, ACE_Null_Mutex>::instance()

#endif
