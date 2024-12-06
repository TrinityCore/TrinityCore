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

#ifndef TRINITYCORE_EVENT_MAP_H
#define TRINITYCORE_EVENT_MAP_H

#include "Define.h"
#include "Duration.h"
#include <map>

class TC_COMMON_API EventMap
{
    using EventId = uint16;
    using GroupIndex = uint8;
    using GroupMask = uint8;
    using PhaseIndex = uint8;
    using PhaseMask = uint8;
    struct Event
    {
        Event() = default;
        Event(EventId id, GroupIndex groupIndex, PhaseIndex phaseIndex) :
            _id(id),
            _groupMask(groupIndex ? GroupMask(1u << (groupIndex - 1u)) : 0u),
            _phaseMask(phaseIndex ? PhaseMask(1u << (phaseIndex - 1u)) : 0u)
        {
        }

        EventId _id          = 0u;
        GroupMask _groupMask = 0u;
        PhaseMask _phaseMask = 0u;
    };

    /**
     * Internal storage type.
     * Key: Time as TimePoint when the event should occur.
     */
    using EventStore = std::multimap<TimePoint, Event>;

public:
    EventMap() : _time(TimePoint::min()), _phaseMask(0) { }

    /**
    * @name Reset
    * @brief Removes all scheduled events and resets time and phase.
    */
    void Reset();

    /**
    * @name Update
    * @brief Updates the timer of the event map.
    * @param time Value in ms to be added to time.
    */
    void Update(uint32 time)
    {
        Update(Milliseconds(time));
    }

    /**
    * @name Update
    * @brief Updates the timer of the event map.
    * @param time Value in ms to be added to time.
    */
    void Update(Milliseconds time)
    {
        _time += time;
    }

    /**
    * @name GetPhaseMask
    * @return Active phases as mask.
    */
    PhaseMask GetPhaseMask() const
    {
        return _phaseMask;
    }

    /**
    * @name Empty
    * @return True, if there are no events scheduled.
    */
    bool Empty() const
    {
        return _eventMap.empty();
    }

    /**
    * @name SetPhase
    * @brief Sets the phase of the map (absolute).
    * @param phase Phase which should be set. Values: 1 - 8. 0 resets phase.
    */
    void SetPhase(PhaseIndex phase);

    /**
    * @name AddPhase
    * @brief Activates the given phase (absolute).
    * @param phase Phase which should be activated. Values: 1 - 8
    */
    void AddPhase(PhaseIndex phase)
    {
        if (phase && phase <= sizeof(PhaseMask) * 8)
            _phaseMask |= PhaseMask(1u << (phase - 1u));
    }

    /**
    * @name RemovePhase
    * @brief Deactivates the given phase (absolute).
    * @param phase Phase which should be deactivated. Values: 1 - 8.
    */
    void RemovePhase(PhaseIndex phase)
    {
        if (phase && phase <= sizeof(PhaseMask) * 8)
            _phaseMask &= PhaseMask(~(1u << (phase - 1u)));
    }

    /**
    * @name ScheduleEvent
    * @brief Creates new event entry in map.
    * @param eventId The id of the new event.
    * @param time The time until the event occurs as std::chrono type.
    * @param group The group which the event is associated to. Has to be between 1 and 8. 0 means it has no group.
    * @param phase The phase in which the event can occur. Has to be between 1 and 8. 0 means it can occur in all phases.
    */
    void ScheduleEvent(EventId eventId, Milliseconds time, GroupIndex group = 0u, PhaseIndex phase = 0u);

    /**
    * @name ScheduleEvent
    * @brief Creates new event entry in map.
    * @param eventId The id of the new event.
    * @param minTime The minimum time until the event occurs as std::chrono type.
    * @param maxTime The maximum time until the event occurs as std::chrono type.
    * @param group The group which the event is associated to. Has to be between 1 and 8. 0 means it has no group.
    * @param phase The phase in which the event can occur. Has to be between 1 and 8. 0 means it can occur in all phases.
    */
    void ScheduleEvent(EventId eventId, Milliseconds minTime, Milliseconds maxTime, GroupIndex group = 0u, PhaseIndex phase = 0u);

    /**
    * @name RescheduleEvent
    * @brief Cancels the given event and reschedules it.
    * @param eventId The id of the event.
    * @param time The time until the event occurs as std::chrono type.
    * @param group The group which the event is associated to. Has to be between 1 and 8. 0 means it has no group.
    * @param phase The phase in which the event can occur. Has to be between 1 and 8. 0 means it can occur in all phases.
    */
    void RescheduleEvent(EventId eventId, Milliseconds time, GroupIndex group = 0u, PhaseIndex phase = 0u);

    /**
    * @name RescheduleEvent
    * @brief Cancels the given event and reschedules it.
    * @param eventId The id of the event.
    * @param minTime The minimum time until the event occurs as std::chrono type.
    * @param maxTime The maximum time until the event occurs as std::chrono type.
    * @param group The group which the event is associated to. Has to be between 1 and 8. 0 means it has no group.
    * @param phase The phase in which the event can occur. Has to be between 1 and 8. 0 means it can occur in all phases.
    */
    void RescheduleEvent(EventId eventId, Milliseconds minTime, Milliseconds maxTime, GroupIndex group = 0u, PhaseIndex phase = 0u);

    /**
    * @name RepeatEvent
    * @brief Repeats the most recently executed event.
    * @param time Time until the event occurs as std::chrono type.
    */
    void Repeat(Milliseconds time);

    /**
    * @name RepeatEvent
    * @brief Repeats the most recently executed event.
    * @param minTime The minimum time until the event occurs as std::chrono type.
    * @param maxTime The maximum time until the event occurs as std::chrono type.
    */
    void Repeat(Milliseconds minTime, Milliseconds maxTime);

    /**
    * @name ExecuteEvent
    * @brief Returns the next event to execute and removes it from map.
    * @return Id of the event to execute.
    */
    EventId ExecuteEvent();

    /**
    * @name DelayEvents
    * @brief Delays all events.
    * @param delay Amount of delay as std::chrono type.
    */
    void DelayEvents(Milliseconds delay);

    /**
    * @name DelayEvents
    * @brief Delay all events of the same group.
    * @param delay Amount of delay as std::chrono type.
    * @param group Group of the events.
    */
    void DelayEvents(Milliseconds delay, GroupIndex group);

    /**
    * @name SetMinimalDelay
    * @brief Increase event delay if smaller than given delay.
    * @param eventId The id of the event.
    * @param delay Minimum delay for given event.
    */
    void SetMinimalDelay(EventId eventId, Milliseconds delay);

    /**
    * @name CancelEvent
    * @brief Cancels all events of the specified id.
    * @param eventId Event id to cancel.
    */
    void CancelEvent(EventId eventId);

    /**
    * @name CancelEventGroup
    * @brief Cancel events belonging to specified group.
    * @param group Group to cancel.
    */
    void CancelEventGroup(GroupIndex group);

    /**
    * @name IsInPhase
    * @brief Returns whether event map is in specified phase or not.
    * @param phase Wanted phase.
    * @return True, if phase of event map contains specified phase.
    */
    bool IsInPhase(PhaseIndex phase) const
    {
        return phase <= sizeof(PhaseIndex) * 8 && (!phase || _phaseMask & PhaseMask(1u << (phase - 1u)));
    }

    /**
    * @name GetTimeUntilEvent
    * @brief Returns time as std::chrono type until next event.
    * @param eventId The id of the event.
    * @return Time of next event. If event is not scheduled returns Milliseconds::max()
    * @return Time of next event.
    */
    Milliseconds GetTimeUntilEvent(EventId eventId) const;

    /**
     * @name HasEventScheduled
     * @brief Returns whether an event is scheduled
     * @param eventId The id of the event.
     * @return True if event is scheduled
     */
    bool HasEventScheduled(EventId eventId) const;

private:
    /**
    * @name _time
    * @brief Internal timer.
    *
    * This does not represent the real date/time value.
    * It's more like a stopwatch: It can run, it can be stopped,
    * it can be resetted and so on. Events occur when this timer
    * has reached their time value. Its value is changed in the
    * Update method.
    */
    TimePoint _time;

    /**
    * @name _phaseMask
    * @brief Phase mask of the event map.
    *
    * Contains the phases the event map is in. Multiple
    * phases from 1 to 8 can be set with SetPhase or
    * AddPhase. RemovePhase deactives a phase.
    */
    PhaseMask _phaseMask;

    /**
    * @name _eventMap
    * @brief Internal event storage map. Contains the scheduled events.
    *
    * See typedef at the beginning of the class for more
    * details.
    */
    EventStore _eventMap;

    /**
    * @name _lastEvent
    * @brief Stores information on the most recently executed event
    */
    Event _lastEvent;
};

#endif // TRINITYCORE_EVENT_MAP_H
