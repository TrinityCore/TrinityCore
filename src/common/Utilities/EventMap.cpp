/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Random.h"

void EventMap::Reset()
{
    _eventMap.clear();
    _time = 0;
    _phase = 0;
}

void EventMap::SetPhase(uint16 phase)
{
    if (!phase)
        _phase = 0;
    else if (phase <= 16)
        _phase = uint16(1 << (phase - 1));
}

bool EventMap::HasEvent(uint32 eventId) const
{
    for (EventStore::const_iterator itr = _eventMap.begin(); itr != _eventMap.end(); ++itr)
        if ((itr->second & 0x00000000FFFFFFFF) == eventId)
            return true;

    return false;
}

void EventMap::ScheduleEvent(uint32 eventId, Milliseconds const& minTime, Milliseconds const& maxTime, uint16 group /*= 0*/, uint16 phase /*= 0*/)
{
    ScheduleEvent(eventId, urand(uint32(minTime.count()), uint32(maxTime.count())), group, phase);
}

void EventMap::ScheduleEvent(uint32 eventId, uint32 time, uint16 group /*= 0*/, uint16 phase /*= 0*/)
{
    if (group && group < 16)
        eventId |= (1LL << (group + 31));

    if (phase && phase < 16)
        eventId |= (1LL << (phase + 47));

    _eventMap.insert(EventStore::value_type(_time + time, eventId));
}

void EventMap::RescheduleEvent(uint32 eventId, Milliseconds const& minTime, Milliseconds const& maxTime, uint16 group /*= 0*/, uint16 phase /*= 0*/)
{
    RescheduleEvent(eventId, urand(uint32(minTime.count()), uint32(maxTime.count())), group, phase);
}

void EventMap::ScheduleNextEvent(uint32 minTime, uint32 maxTime)
{
    ScheduleNextEvent(urand(minTime, maxTime));
}

void EventMap::Repeat(uint32 minTime, uint32 maxTime)
{
    Repeat(urand(minTime, maxTime));
}

uint32 EventMap::ExecuteEvent()
{
    while (!Empty())
    {
        EventStore::iterator itr = _eventMap.begin();

        if (itr->first > _time)
            return 0;
        else if (_phase && (itr->second & 0xFFFF000000000000) && !((itr->second >> 48) & _phase))
            _eventMap.erase(itr);
        else
        {
            uint32 eventId = (itr->second & 0x00000000FFFFFFFF);
            _lastEvent = itr->second; // include phase/group
            _eventMap.erase(itr);
            return eventId;
        }
    }

    return 0;
}

void EventMap::DelayEvent(uint32 eventID, uint32 delay)
{
    if (Empty())
        return;

    EventStore delayed;

    for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        if ((itr->second & 0x00000000FFFFFFFF) == eventID)
        {
            delayed.insert(EventStore::value_type(itr->first + delay, itr->second));
            _eventMap.erase(itr++);
        }
        else
            ++itr;
    }

    _eventMap.insert(delayed.begin(), delayed.end());
}

void EventMap::DelayEvents(uint32 delay, uint16 group)
{
    if (!group || group > 16 || Empty())
        return;

    EventStore delayed;

    for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        if (itr->second & (1ULL << (group + 31)))
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
        if (eventId == (itr->second & 0x00000000FFFFFFFF))
            _eventMap.erase(itr++);
        else
            ++itr;
    }
}

void EventMap::CancelEventGroup(uint16 group)
{
    if (!group || group > 16 || Empty())
        return;

    for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        if (itr->second & (1ULL << (group + 31)))
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
        if (eventId == (itr->second & 0x00000000FFFFFFFF))
            return itr->first;

    return 0;
}

uint32 EventMap::GetTimeUntilEvent(uint32 eventId) const
{
    for (EventStore::const_iterator itr = _eventMap.begin(); itr != _eventMap.end(); ++itr)
        if (eventId == (itr->second & 0x00000000FFFFFFFF))
            return itr->first - _time;

    return std::numeric_limits<uint32>::max();
}
