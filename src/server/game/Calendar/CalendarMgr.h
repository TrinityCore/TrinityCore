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

#ifndef TRINITY_CALENDARMGR_H
#define TRINITY_CALENDARMGR_H

#include <ace/Singleton.h>
#include "Calendar.h"

class CalendarMgr
{
    friend class ACE_Singleton<CalendarMgr, ACE_Null_Mutex>;
    public:
        void LoadFromDB();

        CalendarInvite* GetInvite(uint64 inviteId);
        CalendarEvent* GetEvent(uint64 eventId);

        CalendarinviteIdList const& GetPlayerInvites(uint64 guid);
        CalendarEventIdList const& GetPlayerEvents(uint64 guid);

        uint32 GetPlayerNumPending(uint64 guid);
        uint64 GetFreeEventId();
        uint64 GetFreeInviteId();

        void AddAction(CalendarAction const& action);

        void SendCalendarEvent(CalendarEvent const& calendarEvent, CalendarSendEventType type);
        void SendCalendarEventInvite(CalendarInvite const& invite, bool pending);
        void SendCalendarEventInviteAlert(CalendarEvent const& calendarEvent, CalendarInvite const& invite);
        void SendCalendarEventInviteRemove(uint64 guid, CalendarInvite const& invite, uint32 flags);
        void SendCalendarEventInviteRemoveAlert(uint64 guid, CalendarEvent const& calendarEvent, uint8 status);
        void SendCalendarEventUpdateAlert(uint64 guid, CalendarEvent const& calendarEvent, CalendarSendEventType type);
        void SendCalendarEventStatus(uint64 guid, CalendarEvent const& calendarEvent, CalendarInvite const& invite);
        void SendCalendarEventRemovedAlert(uint64 guid, CalendarEvent const& calendarEvent);
        void SendCalendarEventModeratorStatusAlert(CalendarInvite const& invite);

    private:
        CalendarMgr();
        ~CalendarMgr();
        CalendarEvent* CheckPermisions(uint64 eventId, uint64 guid, uint64 invitateId, CalendarRanks minRank);

        bool addEvent(CalendarEvent const& calendarEvent);
        bool removeEvent(uint64 eventId);
        bool addPlayerEvent(uint64 guid, uint64 eventId);
        bool removePlayerEvent(uint64 guid, uint64 eventId);

        bool addInvite(CalendarInvite const& invite);
        uint64 removeInvite(uint64 inviteId);
        bool addPlayerInvite(uint64 guid, uint64 inviteId);
        bool removePlayerInvite(uint64 guid, uint64 inviteId);

        CalendarEventMap _events;
        CalendarInviteMap _invites;
        CalendarPlayerinviteIdMap _playerInvites;
        CalendarPlayerEventIdMap _playerEvents;

        uint64 eventNum;
        uint64 InviteNum;
};

#define sCalendarMgr ACE_Singleton<CalendarMgr, ACE_Null_Mutex>::instance()

#endif
