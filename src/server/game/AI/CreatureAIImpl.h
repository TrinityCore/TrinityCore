/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#ifndef CREATUREAIIMPL_H
#define CREATUREAIIMPL_H

#include "Common.h"
#include "Define.h"
#include "TemporarySummon.h"
#include "CreatureAI.h"
#include "SpellMgr.h"

template<class T>
inline
const T& RAND(const T& v1, const T& v2)
{
    return (urand(0, 1)) ? v1 : v2;
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3)
{
    switch (urand(0, 2))
    {
        default:
        case 0: return v1;
        case 1: return v2;
        case 2: return v3;
    }
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3, const T& v4)
{
    switch (urand(0, 3))
    {
        default:
        case 0: return v1;
        case 1: return v2;
        case 2: return v3;
        case 3: return v4;
    }
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3, const T& v4, const T& v5)
{
    switch (urand(0, 4))
    {
        default:
        case 0: return v1;
        case 1: return v2;
        case 2: return v3;
        case 3: return v4;
        case 4: return v5;
    }
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3, const T& v4, const T& v5, const T& v6)
{
    switch (urand(0, 5))
    {
        default:
        case 0: return v1;
        case 1: return v2;
        case 2: return v3;
        case 3: return v4;
        case 4: return v5;
        case 5: return v6;
    }
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3, const T& v4, const T& v5, const T& v6, const T& v7)
{
    switch (urand(0, 6))
    {
        default:
        case 0: return v1;
        case 1: return v2;
        case 2: return v3;
        case 3: return v4;
        case 4: return v5;
        case 5: return v6;
        case 6: return v7;
    }
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3, const T& v4, const T& v5, const T& v6, const T& v7, const T& v8)
{
    switch (urand(0, 7))
    {
        default:
        case 0: return v1;
        case 1: return v2;
        case 2: return v3;
        case 3: return v4;
        case 4: return v5;
        case 5: return v6;
        case 6: return v7;
        case 7: return v8;
    }
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3, const T& v4, const T& v5, const T& v6, const T& v7, const T& v8,
              const T& v9)
{
    switch (urand(0, 8))
    {
        default:
        case 0: return v1;
        case 1: return v2;
        case 2: return v3;
        case 3: return v4;
        case 4: return v5;
        case 5: return v6;
        case 6: return v7;
        case 7: return v8;
        case 8: return v9;
    }
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3, const T& v4, const T& v5, const T& v6, const T& v7, const T& v8,
              const T& v9, const T& v10)
{
    switch (urand(0, 9))
    {
        default:
        case 0: return v1;
        case 1: return v2;
        case 2: return v3;
        case 3: return v4;
        case 4: return v5;
        case 5: return v6;
        case 6: return v7;
        case 7: return v8;
        case 8: return v9;
        case 9: return v10;
    }
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3, const T& v4, const T& v5, const T& v6, const T& v7, const T& v8,
              const T& v9, const T& v10, const T& v11)
{
    switch (urand(0, 10))
    {
        default:
        case 0: return v1;
        case 1: return v2;
        case 2: return v3;
        case 3: return v4;
        case 4: return v5;
        case 5: return v6;
        case 6: return v7;
        case 7: return v8;
        case 8: return v9;
        case 9: return v10;
        case 10: return v11;
    }
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3, const T& v4, const T& v5, const T& v6, const T& v7, const T& v8,
              const T& v9, const T& v10, const T& v11, const T& v12)
{
    switch (urand(0, 11))
    {
        default:
        case 0: return v1;
        case 1: return v2;
        case 2: return v3;
        case 3: return v4;
        case 4: return v5;
        case 5: return v6;
        case 6: return v7;
        case 7: return v8;
        case 8: return v9;
        case 9: return v10;
        case 10: return v11;
        case 11: return v12;
    }
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3, const T& v4, const T& v5, const T& v6, const T& v7, const T& v8,
              const T& v9, const T& v10, const T& v11, const T& v12, const T& v13)
{
    switch (urand(0, 12))
    {
        default:
        case 0: return v1;
        case 1: return v2;
        case 2: return v3;
        case 3: return v4;
        case 4: return v5;
        case 5: return v6;
        case 6: return v7;
        case 7: return v8;
        case 8: return v9;
        case 9: return v10;
        case 10: return v11;
        case 11: return v12;
        case 12: return v13;
    }
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3, const T& v4, const T& v5, const T& v6, const T& v7, const T& v8,
              const T& v9, const T& v10, const T& v11, const T& v12, const T& v13, const T& v14)
{
    switch (urand(0, 13))
    {
        default:
        case 0: return v1;
        case 1: return v2;
        case 2: return v3;
        case 3: return v4;
        case 4: return v5;
        case 5: return v6;
        case 6: return v7;
        case 7: return v8;
        case 8: return v9;
        case 9: return v10;
        case 10: return v11;
        case 11: return v12;
        case 12: return v13;
        case 13: return v14;
    }
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3, const T& v4, const T& v5, const T& v6, const T& v7, const T& v8,
              const T& v9, const T& v10, const T& v11, const T& v12, const T& v13, const T& v14, const T& v15)
{
    switch (urand(0, 14))
    {
        default:
        case 0: return v1;
        case 1: return v2;
        case 2: return v3;
        case 3: return v4;
        case 4: return v5;
        case 5: return v6;
        case 6: return v7;
        case 7: return v8;
        case 8: return v9;
        case 9: return v10;
        case 10: return v11;
        case 11: return v12;
        case 12: return v13;
        case 13: return v14;
        case 14: return v15;
    }
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3, const T& v4, const T& v5, const T& v6, const T& v7, const T& v8,
              const T& v9, const T& v10, const T& v11, const T& v12, const T& v13, const T& v14, const T& v15, const T& v16)
{
    switch (urand(0, 15))
    {
        default:
        case 0: return v1;
        case 1: return v2;
        case 2: return v3;
        case 3: return v4;
        case 4: return v5;
        case 5: return v6;
        case 6: return v7;
        case 7: return v8;
        case 8: return v9;
        case 9: return v10;
        case 10: return v11;
        case 11: return v12;
        case 12: return v13;
        case 13: return v14;
        case 14: return v15;
        case 15: return v16;
    }
}

class EventMap
{
    /**
    * Internal storage type.
    * Key: Time as uint32 when the event should occur.
    * Value: The event data as uint32.
    *
    * Structure of event data:
    * - Bit  0 - 15: Event Id.
    * - Bit 16 - 23: Group
    * - Bit 24 - 31: Phase
    * - Pattern: 0xPPGGEEEE
    */
    typedef std::multimap<uint32, uint32> EventStore;

    public:
        EventMap() : _time(0), _phase(0), _lastEvent(0) { }

        /**
        * @name Reset
        * @brief Removes all scheduled events and resets time and phase.
        */
        void Reset()
        {
            _eventMap.clear();
            _time = 0;
            _phase = 0;
        }

        /**
         * @name Update
         * @brief Updates the timer of the event map.
         * @param time Value to be added to time.
         */
        void Update(uint32 time)
        {
            _time += time;
        }

        /**
        * @name GetTimer
        * @return Current timer value.
        */
        uint32 GetTimer() const
        {
            return _time;
        }

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
        * @param phase Phase which should be set. Values: 1 - 8. 0 resets phase.
        */
        void SetPhase(uint8 phase)
        {
            if (!phase)
                _phase = 0;
            else if (phase <= 8)
                _phase = (1 << (phase - 1));
        }

        /**
        * @name AddPhase
        * @brief Activates the given phase (bitwise).
        * @param phase Phase which should be activated. Values: 1 - 8
        */
        void AddPhase(uint8 phase)
        {
            if (phase && phase <= 8)
                _phase |= (1 << (phase - 1));
        }

        /**
        * @name RemovePhase
        * @brief Deactivates the given phase (bitwise).
        * @param phase Phase which should be deactivated. Values: 1 - 8.
        */
        void RemovePhase(uint8 phase)
        {
            if (phase && phase <= 8)
                _phase &= ~(1 << (phase - 1));
        }

        /**
        * @name ScheduleEvent
        * @brief Creates new event entry in map.
        * @param eventId The id of the new event.
        * @param time The time in milliseconds until the event occurs.
        * @param group The group which the event is associated to. Has to be between 1 and 8. 0 means it has no group.
        * @param phase The phase in which the event can occur. Has to be between 1 and 8. 0 means it can occur in all phases.
        */
        void ScheduleEvent(uint32 eventId, uint32 time, uint32 group = 0, uint8 phase = 0)
        {
            if (group && group <= 8)
                eventId |= (1 << (group + 15));

            if (phase && phase <= 8)
                eventId |= (1 << (phase + 23));

            _eventMap.insert(EventStore::value_type(_time + time, eventId));
        }

        /**
        * @name RescheduleEvent
        * @brief Cancels the given event and reschedules it.
        * @param eventId The id of the event.
        * @param time The time in milliseconds until the event occurs.
        * @param group The group which the event is associated to. Has to be between 1 and 8. 0 means it has no group.
        * @param phase The phase in which the event can occur. Has to be between 1 and 8. 0 means it can occur in all phases.
        */
        void RescheduleEvent(uint32 eventId, uint32 time, uint32 group = 0, uint8 phase = 0)
        {
            CancelEvent(eventId);
            ScheduleEvent(eventId, time, group, phase);
        }

        /**
        * @name RepeatEvent
        * @brief Repeats the mostly recently executed event.
        * @param time Time until the event occurs.
        */
        void Repeat(uint32 time)
        {
            _eventMap.insert(EventStore::value_type(_time + time, _lastEvent));
        }

        /**
        * @name RepeatEvent
        * @brief Repeats the mostly recently executed event.
        * @param time Time until the event occurs. Equivalent to Repeat(urand(minTime, maxTime).
        */
        void Repeat(uint32 minTime, uint32 maxTime)
        {
            Repeat(urand(minTime, maxTime));
        }

        /**
        * @name ExecuteEvent
        * @brief Returns the next event to execute and removes it from map.
        * @return Id of the event to execute.
        */
        uint32 ExecuteEvent()
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

        /**
        * @name DelayEvents
        * @brief Delays all events in the map. If delay is greater than or equal internal timer, delay will be 0.
        * @param delay Amount of delay.
        */
        void DelayEvents(uint32 delay)
        {
            _time = delay < _time ? _time - delay : 0;
        }

        /**
        * @name DelayEvents
        * @brief Delay all events of the same group.
        * @param delay Amount of delay.
        * @param group Group of the events.
        */
        void DelayEvents(uint32 delay, uint32 group)
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

        /**
        * @name CancelEvent
        * @brief Cancels all events of the specified id.
        * @param eventId Event id to cancel.
        */
        void CancelEvent(uint32 eventId)
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

        /**
        * @name CancelEventGroup
        * @brief Cancel events belonging to specified group.
        * @param group Group to cancel.
        */
        void CancelEventGroup(uint32 group)
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

        /**
        * @name GetNextEventTime
        * @brief Returns closest occurence of specified event.
        * @param eventId Wanted event id.
        * @return Time of found event.
        */
        uint32 GetNextEventTime(uint32 eventId) const
        {
            if (Empty())
                return 0;

            for (EventStore::const_iterator itr = _eventMap.begin(); itr != _eventMap.end(); ++itr)
                if (eventId == (itr->second & 0x0000FFFF))
                    return itr->first;

            return 0;
        }

        /**
         * @name GetNextEventTime
         * @return Time of next event.
         */
        uint32 GetNextEventTime() const
        {
            return Empty() ? 0 : _eventMap.begin()->first;
        }

        /**
        * @name IsInPhase
        * @brief Returns wether event map is in specified phase or not.
        * @param phase Wanted phase.
        * @return True, if phase of event map contains specified phase.
        */
        bool IsInPhase(uint8 phase)
        {
            return phase <= 8 && (!phase || _phase & (1 << (phase - 1)));
        }

        /**
        * @name GetTimeUntilEvent
        * @brief Returns time in milliseconds until next event.
        * @param Id of the event.
        * @return Time of next event.
        */
        uint32 GetTimeUntilEvent(uint32 eventId) const
        {
            for (EventStore::const_iterator itr = _eventMap.begin(); itr != _eventMap.end(); ++itr)
                if (eventId == (itr->second & 0x0000FFFF))
                    return itr->first - _time;

            return std::numeric_limits<uint32>::max();
        }

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
        uint32 _time;

        /**
        * @name _phase
        * @brief Phase mask of the event map.
        *
        * Contains the phases the event map is in. Multiple
        * phases from 1 to 8 can be set with SetPhase or
        * AddPhase. RemovePhase deactives a phase.
        */
        uint8 _phase;

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
        uint32 _lastEvent;
};

enum AITarget
{
    AITARGET_SELF,
    AITARGET_VICTIM,
    AITARGET_ENEMY,
    AITARGET_ALLY,
    AITARGET_BUFF,
    AITARGET_DEBUFF
};

enum AICondition
{
    AICOND_AGGRO,
    AICOND_COMBAT,
    AICOND_DIE
};

#define AI_DEFAULT_COOLDOWN 5000

struct AISpellInfoType
{
    AISpellInfoType() : target(AITARGET_SELF), condition(AICOND_COMBAT)
        , cooldown(AI_DEFAULT_COOLDOWN), realCooldown(0), maxRange(0.0f){ }
    AITarget target;
    AICondition condition;
    uint32 cooldown;
    uint32 realCooldown;
    float maxRange;
};

AISpellInfoType* GetAISpellInfo(uint32 i);

#endif

