/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef _DAMAGE_EVENT_MAP_H_
#define _DAMAGE_EVENT_MAP_H_

#include "Define.h"
#include <map>

class TC_GAME_API DamageEventMap
{
    /**
    * Internal storage type.
    * Key: health pct as uint8 below which the event should occur.
    * Value: The event data as uint64.
    *
    * Structure of event data:
    * - Bit  0 - 31: Event Id.
    * - Bit 32 - 47: Group
    * - Bit 48 - 63: Phase
    * - Pattern: 0xPPPPGGGGEEEEEEEE
    */
    typedef std::multimap<uint8, uint64> DamageEventStore;

public:
    explicit DamageEventMap(Unit* unit) : _phase(0), _lastEvent(0), _target(unit) { }

    /**
    * @name Reset
    * @brief Removes all scheduled events and resets time and phase.
    */
    void Reset();

    /**
    * @name GetPhaseMask
    * @return Active phases as mask.
    */
    uint8 GetPhaseMask() const
    {
        return _phase;
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
    * @param phase Phase which should be set. Values: 1 - 16. 0 resets phase.
    */
    void SetPhase(uint16 phase);

    /**
    * @name AddPhase
    * @brief Activates the given phase (bitwise).
    * @param phase Phase which should be activated. Values: 1 - 8
    */
    void AddPhase(uint16 phase)
    {
        if (phase && phase <= 16)
            _phase |= uint16(1 << (phase - 1));
    }

    /**
    * @name RemovePhase
    * @brief Deactivates the given phase (bitwise).
    * @param phase Phase which should be deactivated. Values: 1 - 8.
    */
    void RemovePhase(uint16 phase)
    {
        if (phase && phase <= 16)
            _phase &= uint16(~(1 << (phase - 1)));
    }

    bool HasEvent(uint32 eventId) const;

    /**
    * @name ScheduleEvent
    * @brief Creates new event entry in map.
    * @param eventId The id of the new event.
    * @param healthPct The healthPct under which the event is triggered
    * @param group The group which the event is associated to. Has to be between 1 and 8. 0 means it has no group.
    * @param phase The phase in which the event can occur. Has to be between 1 and 8. 0 means it can occur in all phases.
    */
    void ScheduleEventBelowHealthPct(uint32 eventId, uint8 healthPct, uint16 group = 0, uint16 phase = 0);

    /**
    * @name RescheduleEvent
    * @brief Cancels the given event and reschedules it.
    * @param eventId The id of the event.
    * @param healthPct The healthPct under which the event is triggered
    * @param group The group which the event is associated to. Has to be between 1 and 8. 0 means it has no group.
    * @param phase The phase in which the event can occur. Has to be between 1 and 8. 0 means it can occur in all phases.
    */
    void RescheduleEvent(uint32 eventId, uint8 healthPct, uint16 group = 0, uint16 phase = 0)
    {
        CancelEvent(eventId);
        ScheduleEventBelowHealthPct(eventId, healthPct, group, phase);
    }

    /**
    * @name ScheduleNextEvent
    * @brief Schedule the next event (_lastEvent + 1).
    * @param healthPct The healthPct under which the event is triggered
    */
    void ScheduleNextEvent(uint8 healthPct)
    {
        _eventMap.insert(DamageEventStore::value_type(healthPct, _lastEvent + 1));
    }

    /**
    * @name RepeatEvent
    * @brief Repeats the mostly recently executed event.
    * @param time Time until the event occurs.
    */
    void Repeat(uint8 healthPct)
    {
        _eventMap.insert(DamageEventStore::value_type(healthPct, _lastEvent));
    }

    /**
    * @name ExecuteEvent
    * @brief Returns the next event to execute and removes it from map.
    * @return Id of the event to execute.
    */
    uint32 OnDamageTaken(uint32 damageTaken);

    /**
    * @name CancelEvent
    * @brief Cancels all events of the specified id.
    * @param eventId Event id to cancel.
    */
    void CancelEvent(uint32 eventId);

    /**
    * @name CancelEventGroup
    * @brief Cancel events belonging to specified group.
    * @param group Group to cancel.
    */
    void CancelEventGroup(uint16 group);

    /**
    * @name IsInPhase
    * @brief Returns whether event map is in specified phase or not.
    * @param phase Wanted phase.
    * @return True, if phase of event map contains specified phase.
    */
    bool IsInPhase(uint16 phase) const
    {
        return phase <= 16 && (!phase || _phase & (1 << (phase - 1)));
    }

private:
    /**
    * @name _phase
    * @brief Phase mask of the event map.
    *
    * Contains the phases the event map is in. Multiple
    * phases from 1 to 8 can be set with SetPhase or
    * AddPhase. RemovePhase deactives a phase.
    */
    uint16 _phase;

    /**
    * @name _eventMap
    * @brief Internal event storage map. Contains the scheduled events.
    *
    * See typedef at the beginning of the class for more
    * details.
    */
    DamageEventStore _eventMap;

    /**
    * @name _lastEvent
    * @brief Stores information on the most recently executed event
    */
    uint64 _lastEvent;

    /**
    * @name _target
    * @brief Stores information on the watched unit
    */
    Unit const* _target;
};

#endif // _EVENT_MAP_H_
