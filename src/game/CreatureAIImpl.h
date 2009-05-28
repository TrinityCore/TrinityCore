/*
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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
#ifndef CREATUREAIIMPL_H
#define CREATUREAIIMPL_H

#include "Common.h"
#include "Platform/Define.h"

#define HEROIC(n,h) (HeroicMode ? h : n)

template<class T>
inline
const T& RAND(const T& v1, const T& v2)
{
    return rand()%2 ? v1 : v2;
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3)
{
    switch(rand()%3)
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
    switch(rand()%4)
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
    switch(rand()%5)
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
    switch(rand()%6)
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

class EventMap : private std::map<uint32, uint32>
{
    private:
        uint32 m_time, m_phase;
    public:
        explicit EventMap() : m_phase(0), m_time(0) {}

        uint32 GetTimer() const { return m_time; }

        void Reset() { clear(); m_time = 0; m_phase = 0; }

        void Update(uint32 time) { m_time += time; }

        void SetPhase(uint32 phase)
        {
            if(phase && phase < 9)
                m_phase = (1 << (phase + 24));
        }

        void ScheduleEvent(uint32 eventId, uint32 time, uint32 gcd = 0, uint32 phase = 0)
        {
            time += m_time;
            if(gcd && gcd < 9)
                eventId |= (1 << (gcd + 16));
            if(phase && phase < 9)
                eventId |= (1 << (phase + 24));
            iterator itr = find(time);
            while(itr != end())
            {
                ++time;
                itr = find(time);
            }
            insert(std::make_pair(time, eventId));
        }

        void RescheduleEvent(uint32 eventId, uint32 time, uint32 gcd = 0, uint32 phase = 0)
        {
            CancelEvent(eventId);
            ScheduleEvent(eventId, time, gcd, phase);
        }

        uint32 ExecuteEvent()
        {
            while(!empty())
            {
                if(begin()->first > m_time)
                    return 0;
                else if(m_phase && (begin()->second & 0xFF000000) && !(begin()->second & m_phase))
                    erase(begin());
                else
                {
                    uint32 eventId = (begin()->second & 0x0000FFFF);
                    erase(begin());
                    return eventId;
                }
            }
            return 0;
        }

        void DelayEvents(uint32 time, uint32 gcd)
        {
            time += m_time;
            gcd = (1 << (gcd + 16));
            for(iterator itr = begin(); itr != end();)
            {
                if(itr->first >= time)
                    break;
                if(itr->second & gcd)
                {
                    ScheduleEvent(time, itr->second);
                    erase(itr++);
                }
                else
                    ++itr;
            }
        }

        void CancelEvent(uint32 eventId)
        {
            for(iterator itr = begin(); itr != end();)
            {
                if(eventId == (itr->second & 0x0000FFFF))
                    erase(itr++);
                else
                    ++itr;
            }
        }

        void CancelEventsByGCD(uint32 gcd)
        {
            for(iterator itr = begin(); itr != end();)
            {
                if(itr->second & gcd)
                    erase(itr++);
                else
                    ++itr;
            }
        }
};

enum AITarget
{
    AITARGET_SELF,
    AITARGET_VICTIM,
    AITARGET_ENEMY,
    AITARGET_ALLY,
    AITARGET_BUFF,
    AITARGET_DEBUFF,
};

enum AICondition
{
    AICOND_AGGRO,
    AICOND_COMBAT,
    AICOND_DIE,
};

#define AI_DEFAULT_COOLDOWN 5000

struct AISpellInfoType
{
    AISpellInfoType() : target(AITARGET_SELF), condition(AICOND_COMBAT), cooldown(AI_DEFAULT_COOLDOWN) {}
    AITarget target;
    AICondition condition;
    uint32 cooldown;
};

TRINITY_DLL_SPEC AISpellInfoType * GetAISpellInfo(uint32 i);

#endif

