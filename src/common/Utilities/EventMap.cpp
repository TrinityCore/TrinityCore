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
    _phaseMask = 0;
}

void EventMap::SetPhase(PhaseIndex phase)
{
    if (!phase)
        _phaseMask = 0;
    else if (phase <= sizeof(PhaseMask) * 8)
        _phaseMask = PhaseMask(1u << (phase - 1u));
}

void EventMap::ScheduleEvent(EventId eventId, Milliseconds time, GroupIndex group /*= 0*/, PhaseIndex phase /*= 0*/)
{
    if (group > sizeof(GroupMask) * 8)
        return;

    if (phase > sizeof(PhaseMask) * 8)
        return;

    _eventMap.insert(EventStore::value_type(_time + time, Event(eventId, group, phase)));
}

void EventMap::ScheduleEvent(EventId eventId, Milliseconds minTime, Milliseconds maxTime, GroupIndex group /*= 0*/, PhaseIndex phase /*= 0*/)
{
    ScheduleEvent(eventId, randtime(minTime, maxTime), group, phase);
}

void EventMap::RescheduleEvent(EventId eventId, Milliseconds time, GroupIndex group, PhaseIndex phase)
{
    CancelEvent(eventId);
    ScheduleEvent(eventId, time, group, phase);
}

void EventMap::RescheduleEvent(EventId eventId, Milliseconds minTime, Milliseconds maxTime, GroupIndex group /*= 0*/, PhaseIndex phase /*= 0*/)
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

EventMap::EventId EventMap::ExecuteEvent()
{
    while (!Empty())
    {
        auto itr = _eventMap.begin();

        if (itr->first > _time)
            return 0;
        else if (_phaseMask && itr->second._phaseMask && !(itr->second._phaseMask & _phaseMask))
            _eventMap.erase(itr);
        else
        {
            auto eventId = itr->second._id;
            _lastEvent = itr->second;
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
    for (auto itr = delayed.begin(); itr != delayed.end();)
    {
        EventStore::node_type node = delayed.extract(itr++);
        node.key() = node.key() + delay;
        _eventMap.insert(_eventMap.end(), std::move(node));
    }
}

void EventMap::DelayEvents(Milliseconds delay, GroupIndex group)
{
    if (!group || group > sizeof(GroupMask) * 8 || Empty())
        return;

    EventStore delayed;

    for (auto itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        if (itr->second._groupMask & GroupMask(1u << (group - 1u)))
        {
            delayed.insert(EventStore::value_type(itr->first + delay, itr->second));
            _eventMap.erase(itr++);
        }
        else
            ++itr;
    }

    _eventMap.insert(delayed.begin(), delayed.end());
}

void EventMap::SetMinimalDelay(EventId eventId, Milliseconds delay)
{
    if (Empty())
        return;

    for (auto itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        if (eventId == itr->second._id)
        {
            if (itr->first < (_time + delay))
            {
                _eventMap.insert(EventStore::value_type(_time + delay, itr->second));
                itr = _eventMap.erase(itr);
                continue;
            }

        }
        ++itr;
    }
}

void EventMap::CancelEvent(EventId eventId)
{
    if (Empty())
        return;

    for (auto itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        if (eventId == itr->second._id)
            _eventMap.erase(itr++);
        else
            ++itr;
    }
}

void EventMap::CancelEventGroup(GroupIndex group)
{
    if (!group || group > sizeof(GroupMask) * 8 || Empty())
        return;

    for (auto itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        if (itr->second._groupMask & GroupMask(1u << (group - 1u)))
            _eventMap.erase(itr++);
        else
            ++itr;
    }
}

Milliseconds EventMap::GetTimeUntilEvent(EventId eventId) const
{
    for (auto const& [time, event] : _eventMap)
        if (eventId == event._id)
            return std::chrono::duration_cast<Milliseconds>(time - _time);

    return Milliseconds::max();
}

bool EventMap::HasEventScheduled(EventId eventId) const
{
    return GetTimeUntilEvent(eventId) != Milliseconds::max();
}
