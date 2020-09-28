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

#include "EventMap.h"
#include "Random.h"

void EventMap::Reset()
{
    _eventMap.clear();
    _time = TimePoint::min();
    _phase = 0;
}

void EventMap::SetPhase(uint8 phase)
{
    if (!phase)
        _phase = 0;
    else if (phase <= 8)
        _phase = uint8(1 << (phase - 1));
}

void EventMap::ScheduleEvent(uint32 eventId, Milliseconds time, uint32 group /*= 0*/, uint8 phase /*= 0*/)
{
    if (group && group <= 8)
        eventId |= (1 << (group + 15));

    if (phase && phase <= 8)
        eventId |= (1 << (phase + 23));

    _eventMap.insert(EventStore::value_type(_time + time, eventId));
}

void EventMap::ScheduleEvent(uint32 eventId, Milliseconds minTime, Milliseconds maxTime, uint32 group /*= 0*/, uint32 phase /*= 0*/)
{
    ScheduleEvent(eventId, randtime(minTime, maxTime), group, phase);
}

void EventMap::RescheduleEvent(uint32 eventId, Milliseconds time, uint32 group /*= 0*/, uint8 phase /*= 0*/)
{
    CancelEvent(eventId);
    ScheduleEvent(eventId, time, group, phase);
}

void EventMap::RescheduleEvent(uint32 eventId, Milliseconds minTime, Milliseconds maxTime, uint32 group /*= 0*/, uint32 phase /*= 0*/)
{
    RescheduleEvent(eventId, randtime(minTime, maxTime), group, phase);
}

void EventMap::Repeat(Milliseconds time)
{
    _eventMap.insert(EventStore::value_type(_time + time, _lastEvent));
}

void EventMap::Repeat(Milliseconds minTime, Milliseconds maxTime)
{
    Repeat(randtime(minTime, maxTime));
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

void EventMap::DelayEvents(Milliseconds delay)
{
    if (Empty())
        return;

    EventStore delayed = std::move(_eventMap);
    for (EventStore::iterator itr = delayed.begin(); itr != delayed.end();)
    {
        EventStore::node_type node = delayed.extract(itr++);
        node.key() = node.key() + delay;
        _eventMap.insert(_eventMap.end(), std::move(node));
    }
}

void EventMap::DelayEvents(Milliseconds delay, uint32 group)
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

Milliseconds EventMap::GetTimeUntilEvent(uint32 eventId) const
{
    for (std::pair<TimePoint const, uint32> const& itr : _eventMap)
        if (eventId == (itr.second & 0x0000FFFF))
            return std::chrono::duration_cast<Milliseconds>(itr.first - _time);

    return Milliseconds::max();
}
