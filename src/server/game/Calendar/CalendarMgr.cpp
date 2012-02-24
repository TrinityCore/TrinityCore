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

#include "CalendarMgr.h"
#include "QueryResult.h"

CalendarMgr::CalendarMgr() : _currentEventId(0), _currentInviteId(0)
{
}

CalendarMgr::~CalendarMgr()
{
}

void CalendarMgr::AppendInvitesToCalendarPacketForPlayer(WorldPacket& data, Player* player)
{
    size_t pCounter = data.wpos();
    data << uint32(0);
    uint32 counter = 0;
    for (CalendarInviteMap::iterator itr = _inviteMap.begin(); itr != _inviteMap.end(); ++itr)
    {
        CalendarInvite invite = itr->second;
        if (invite.TargetGuid == player->GetGUID())
        {
            data << uint64(invite.Id);                // Invite ID
            data << uint64(invite.Event);             // Event ID
            data << uint8(invite.Rank);               // rank
            data << uint8(0);                         // unk - TODO: Figure out what this is
            data << uint8(0);                         // unk
            data.appendPackGUID(invite.CreatorGuid);  // creator's guid
            counter++;
        }
    }
    data.put<uint32>(pCounter, counter);             // update number of invites
}

void CalendarMgr::AppendEventsToCalendarPacketForPlayer(WorldPacket& data, Player* player)
{
    // TODO: There's gotta be a better way to do this
    size_t pCounter = data.wpos();
    data << uint32(0);
    uint32 counter = 0;
    std::set<uint64> alreadyAdded;
    for (CalendarInviteMap::iterator itr = _inviteMap.begin(); itr != _inviteMap.end(); ++itr)
    {
        CalendarInvite invite = itr->second;
        if (invite.TargetGuid == player->GetGUID())
        {
            if (alreadyAdded.find(invite.Event) == alreadyAdded.end())
            {
                CalendarEvent const* event = GetEvent(invite.Event);
                data << uint64(event->Id);                // event ID
                data << event->Name;                      // event title
                data << uint32(event->Type);              // event type
                data << uint32(event->Time);              // event time as time bit field
                data << uint32(event->Flags);             // event flags
                data << uint32(event->DungeonId);         // dungeon ID
                data.appendPackGUID(event->CreatorGuid);  // creator guid
                alreadyAdded.insert(invite.Event);
                counter++;
            }
        }
    }
    data.put<uint32>(pCounter, counter);             // update number of invites
}
