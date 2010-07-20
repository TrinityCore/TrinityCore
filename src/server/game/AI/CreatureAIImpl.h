/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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
#include "Define.h"
#include "TemporarySummon.h"
#include "CreatureAI.h"
#include "SpellMgr.h"

template<class T>
inline
const T& RAND(const T& v1, const T& v2)
{
    return (urand(0,1)) ? v1 : v2;
}

template<class T>
inline
const T& RAND(const T& v1, const T& v2, const T& v3)
{
    switch (urand(0,2))
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
    switch (urand(0,3))
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
    switch (urand(0,4))
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
    switch (urand(0,5))
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
    switch (urand(0,6))
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
    switch (urand(0,7))
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
    switch (urand(0,8))
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
    switch (urand(0,9))
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
    switch (urand(0,10))
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
    switch (urand(0,11))
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
    switch (urand(0,12))
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
    switch (urand(0,13))
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
    switch (urand(0,14))
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
    switch (urand(0,15))
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
            if (phase && phase < 9)
                m_phase = (1 << (phase + 24));
        }

        void ScheduleEvent(uint32 eventId, uint32 time, uint32 gcd = 0, uint32 phase = 0)
        {
            time += m_time;
            if (gcd && gcd < 9)
                eventId |= (1 << (gcd + 16));
            if (phase && phase < 9)
                eventId |= (1 << (phase + 24));
            iterator itr = find(time);
            while (itr != end())
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

        void RepeatEvent(uint32 time)
        {
            if (empty())
                return;
            uint32 eventId = begin()->second;
            erase(begin());
            time += m_time;
            iterator itr = find(time);
            while (itr != end())
            {
                ++time;
                itr = find(time);
            }
            insert(std::make_pair(time, eventId));
        }

        void PopEvent()
        {
            erase(begin());
        }

        uint32 ExecuteEvent()
        {
            while (!empty())
            {
                if (begin()->first > m_time)
                    return 0;
                else if (m_phase && (begin()->second & 0xFF000000) && !(begin()->second & m_phase))
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

        uint32 GetEvent()
        {
            while (!empty())
            {
                if (begin()->first > m_time)
                    return 0;
                else if (m_phase && (begin()->second & 0xFF000000) && !(begin()->second & m_phase))
                    erase(begin());
                else
                    return (begin()->second & 0x0000FFFF);
            }
            return 0;
        }

        // Delay all events
        void DelayEvents(uint32 delay)
        {
            if (delay < m_time)
                m_time -= delay;
            else
                m_time = 0;
        }

        // Delay all events having the specified Global Cooldown.
        void DelayEvents(uint32 delay, uint32 gcd)
        {
            uint32 nextTime = m_time + delay;
            gcd = (1 << (gcd + 16));
            for (iterator itr = begin(); itr != end() && itr->first < nextTime;)
            {
                if (itr->second & gcd)
                {
                    ScheduleEvent(itr->second, itr->first-m_time+delay);
                    erase(itr);
                    itr = begin();
                }
                else
                    ++itr;
            }
        }

        void CancelEvent(uint32 eventId)
        {
            for (iterator itr = begin(); itr != end();)
            {
                if (eventId == (itr->second & 0x0000FFFF))
                {
                    erase(itr);
                    itr = begin();
                }
                else
                    ++itr;
            }
        }

        void CancelEventsByGCD(uint32 gcd)
        {
            gcd = (1 << (gcd + 16));

            for (iterator itr = begin(); itr != end();)
            {
                if (itr->second & gcd)
                {
                    erase(itr);
                    itr = begin();
                }
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
    AISpellInfoType() : target(AITARGET_SELF), condition(AICOND_COMBAT)
        , cooldown(AI_DEFAULT_COOLDOWN), realCooldown(0), maxRange(0.0f){}
    AITarget target;
    AICondition condition;
    uint32 cooldown;
    uint32 realCooldown;
    float maxRange;
};

 AISpellInfoType * GetAISpellInfo(uint32 i);

inline void CreatureAI::SetGazeOn(Unit *target)
{
    if (me->canAttack(target))
    {
        AttackStart(target);
        me->SetReactState(REACT_PASSIVE);
    }
}

inline bool CreatureAI::UpdateVictimWithGaze()
{
    if (!me->isInCombat())
        return false;

    if (me->HasReactState(REACT_PASSIVE))
    {
        if (me->getVictim())
            return true;
        else
            me->SetReactState(REACT_AGGRESSIVE);
    }

    if (Unit *victim = me->SelectVictim())
        AttackStart(victim);
    return me->getVictim();
}

inline bool CreatureAI::UpdateCombatState()
{
    if (!me->isInCombat())
        return false;

    if (!me->HasReactState(REACT_PASSIVE))
    {
        if (Unit *victim = me->SelectVictim())
            AttackStart(victim);
        return me->getVictim();
    }
    else if (me->getThreatManager().isThreatListEmpty())
    {
        EnterEvadeMode();
        return false;
    }

    return true;
}

inline bool CreatureAI::UpdateVictim()
{
    if (!me->isInCombat())
        return false;

    if (!me->HasReactState(REACT_PASSIVE))
    {
        if (Unit *victim = me->SelectVictim())
            AttackStart(victim);
        return me->getVictim();
    }
    else if (me->getThreatManager().isThreatListEmpty())
    {
        EnterEvadeMode();
        return false;
    }

    return true;
}

/*
inline bool CreatureAI::UpdateVictim()
{
    if (!me->isInCombat())
        return false;
    if (Unit *victim = me->SelectVictim())
        AttackStart(victim);
    return me->getVictim();
}
*/

inline bool CreatureAI::_EnterEvadeMode()
{
    if (!me->isAlive())
        return false;

    // sometimes bosses stuck in combat?
    me->RemoveAllAuras();
    me->DeleteThreatList();
    me->CombatStop(true);
    me->LoadCreaturesAddon();
    me->SetLootRecipient(NULL);
    me->ResetPlayerDamageReq();

    if (me->IsInEvadeMode())
        return false;

    return true;
}

inline void UnitAI::DoCast(Unit* victim, uint32 spellId, bool triggered)
{
    if (!victim || (me->hasUnitState(UNIT_STAT_CASTING) && !triggered))
        return;

    me->CastSpell(victim, spellId, triggered);
}

inline void UnitAI::DoCastVictim(uint32 spellId, bool triggered)
{
    me->CastSpell(me->getVictim(), spellId, triggered);
}

inline void UnitAI::DoCastAOE(uint32 spellId, bool triggered)
{
    if (!triggered && me->hasUnitState(UNIT_STAT_CASTING))
        return;

    me->CastSpell((Unit*)NULL, spellId, triggered);
}

inline Creature *CreatureAI::DoSummon(uint32 uiEntry, const Position &pos, uint32 uiDespawntime, TempSummonType uiType)
{
    return me->SummonCreature(uiEntry, pos, uiType, uiDespawntime);
}

inline Creature *CreatureAI::DoSummon(uint32 uiEntry, WorldObject* obj, float fRadius, uint32 uiDespawntime, TempSummonType uiType)
{
    Position pos;
    obj->GetRandomNearPosition(pos, fRadius);
    return me->SummonCreature(uiEntry, pos, uiType, uiDespawntime);
}

inline Creature *CreatureAI::DoSummonFlyer(uint32 uiEntry, WorldObject *obj, float _fZ, float fRadius, uint32 uiDespawntime, TempSummonType uiType)
{
    Position pos;
    obj->GetRandomNearPosition(pos, fRadius);
    pos.m_positionZ += _fZ;
    return me->SummonCreature(uiEntry, pos, uiType, uiDespawntime);
}

#endif

