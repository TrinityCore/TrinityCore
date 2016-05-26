/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "EventMap.h"

void EventMap::Reset()
{
    _eventMap.clear();
    _time = 0;
    _phase = 0;
}

void EventMap::SetPhase(uint8 phase)
{
    if (!phase)
        _phase = 0;
    else if (phase <= 8)
        _phase = uint8(1 << (phase - 1));
}

void EventMap::ScheduleEvent(uint32 eventId, uint32 time, uint32 group /*= 0*/, uint8 phase /*= 0*/)
{
    if (group && group <= 8)
        eventId |= (1 << (group + 15));

    if (phase && phase <= 8)
        eventId |= (1 << (phase + 23));

    _eventMap.insert(EventStore::value_type(_time + time, eventId));
}

uint32 EventMap::ExecuteEvent()
{
    while (!Empty())
    {
        EventStore::iterator itr = _eventMap.begin();

        if (itr->first > _time)
            return 0;
        else if (_phase && (itr->second & 0xFF000000) && !((itr->second >> 24) & _phase))
            _eventMap.erase(itr);
        else
        {
            uint32 eventId = (itr->second & 0x0000FFFF);
            _lastEvent = itr->second; // include phase/group
            _eventMap.erase(itr);
            return eventId;
        }
    }

    return 0;
}

void EventMap::DelayEvents(uint32 delay, uint32 group)
{
    if (!group || group > 8 || Empty())
        return;

    EventStore delayed;

    for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        if (itr->second & (1 << (group + 15)))
        {
            delayed.insert(EventStore::value_type(itr->first + delay, itr->second));
            _eventMap.erase(itr++);
        }
        else
            ++itr;
    }

    _eventMap.insert(delayed.begin(), delayed.end());
}

void EventMap::CancelEvent(uint32 eventId)
{
    if (Empty())
        return;

    for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        if (eventId == (itr->second & 0x0000FFFF))
            _eventMap.erase(itr++);
        else
            ++itr;
    }
}

void EventMap::CancelEventGroup(uint32 group)
{
    if (!group || group > 8 || Empty())
        return;

    for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        if (itr->second & (1 << (group + 15)))
            _eventMap.erase(itr++);
        else
            ++itr;
    }
}

uint32 EventMap::GetNextEventTime(uint32 eventId) const
{
    if (Empty())
        return 0;

    for (EventStore::const_iterator itr = _eventMap.begin(); itr != _eventMap.end(); ++itr)
        if (eventId == (itr->second & 0x0000FFFF))
            return itr->first;

    return 0;
}

uint32 EventMap::GetTimeUntilEvent(uint32 eventId) const
{
    for (EventStore::const_iterator itr = _eventMap.begin(); itr != _eventMap.end(); ++itr)
        if (eventId == (itr->second & 0x0000FFFF))
            return itr->first - _time;

    return std::numeric_limits<uint32>::max();
}
