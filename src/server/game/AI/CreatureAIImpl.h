/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

class EventMap : private std::map<uint32, uint32>
{
    public:
        EventMap() : _time(0), _phase(0) {}

        // Returns current timer value, does not represent real dates/times
        uint32 GetTimer() const { return _time; }

        // Removes all events and clears phase
        void Reset() { clear(); _time = 0; _phase = 0; }

        void Update(uint32 time) { _time += time; }

        uint32 GetPhaseMask() const { return (_phase >> 24) & 0xFF; }

        // Sets event phase, must be in range 1 - 8
        void SetPhase(uint32 phase)
        {
            if (phase && phase < 9)
                _phase = (1 << (phase + 24));
        }

        // Creates new event entry in map with given id, time, group if given (1 - 8) and phase if given (1 - 8)
        // 0 for group/phase means it belongs to no group or runs in all phases
        void ScheduleEvent(uint32 eventId, uint32 time, uint32 groupId = 0, uint32 phase = 0)
        {
            time += _time;
            if (groupId && groupId < 9)
                eventId |= (1 << (groupId + 16));
            if (phase && phase < 9)
                eventId |= (1 << (phase + 24));
            const_iterator itr = find(time);
            while (itr != end())
            {
                ++time;
                itr = find(time);
            }

            insert(std::make_pair(time, eventId));
        }

        // Removes event with specified id and creates new entry for it
        void RescheduleEvent(uint32 eventId, uint32 time, uint32 groupId = 0, uint32 phase = 0)
        {
            CancelEvent(eventId);
            ScheduleEvent(eventId, time, groupId, phase);
        }

        // Reschedules closest event
        void RepeatEvent(uint32 time)
        {
            if (empty())
                return;

            uint32 eventId = begin()->second;
            erase(begin());
            time += _time;
            const_iterator itr = find(time);
            while (itr != end())
            {
                ++time;
                itr = find(time);
            }

            insert(std::make_pair(time, eventId));
        }

        // Removes first event
        void PopEvent()
        {
            erase(begin());
        }

        // Gets next event id to execute and removes it from map
        uint32 ExecuteEvent()
        {
            while (!empty())
            {
                if (begin()->first > _time)
                    return 0;
                else if (_phase && (begin()->second & 0xFF000000) && !(begin()->second & _phase))
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

        // Gets next event id to execute
        uint32 GetEvent()
        {
            while (!empty())
            {
                if (begin()->first > _time)
                    return 0;
                else if (_phase && (begin()->second & 0xFF000000) && !(begin()->second & _phase))
                    erase(begin());
                else
                    return (begin()->second & 0x0000FFFF);
            }

            return 0;
        }

        // Delay all events
        void DelayEvents(uint32 delay)
        {
            if (delay < _time)
                _time -= delay;
            else
                _time = 0;
        }

        // Delay all events having the specified Group
        void DelayEvents(uint32 delay, uint32 groupId)
        {
            uint32 nextTime = _time + delay;
            uint32 groupMask = (1 << (groupId + 16));
            for (iterator itr = begin(); itr != end() && itr->first < nextTime;)
            {
                if (itr->second & groupMask)
                {
                    ScheduleEvent(itr->second, itr->first - _time + delay);
                    erase(itr);
                    itr = begin();
                }
                else
                    ++itr;
            }
        }

        // Cancel events with specified id
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

        // Cancel events belonging to specified group
        void CancelEventGroup(uint32 groupId)
        {
            uint32 groupMask = (1 << (groupId + 16));

            for (iterator itr = begin(); itr != end();)
            {
                if (itr->second & groupMask)
                {
                    erase(itr);
                    itr = begin();
                }
                else
                    ++itr;
            }
        }

        // Returns time of next event to execute
        // To get how much time remains substract _time
        uint32 GetNextEventTime(uint32 eventId) const
        {
            for (const_iterator itr = begin(); itr != end(); ++itr)
                if (eventId == (itr->second & 0x0000FFFF))
                    return itr->first;

            return 0;
        }

    private:
        uint32 _time;
        uint32 _phase;
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

AISpellInfoType* GetAISpellInfo(uint32 i);

inline void CreatureAI::SetGazeOn(Unit* target)
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

    if (Unit* victim = me->SelectVictim())
        AttackStart(victim);
    return me->getVictim();
}

inline bool CreatureAI::UpdateVictim()
{
    if (!me->isInCombat())
        return false;

    if (!me->HasReactState(REACT_PASSIVE))
    {
        if (Unit* victim = me->SelectVictim())
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

inline bool CreatureAI::_EnterEvadeMode()
{
    if (!me->isAlive())
        return false;

    // dont remove vehicle auras, passengers arent supposed to drop off the vehicle
    me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);

    // sometimes bosses stuck in combat?
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
    if (!victim || (me->HasUnitState(UNIT_STAT_CASTING) && !triggered))
        return;

    me->CastSpell(victim, spellId, triggered);
}

inline void UnitAI::DoCastVictim(uint32 spellId, bool triggered)
{
    me->CastSpell(me->getVictim(), spellId, triggered);
}

inline void UnitAI::DoCastAOE(uint32 spellId, bool triggered)
{
    if (!triggered && me->HasUnitState(UNIT_STAT_CASTING))
        return;

    me->CastSpell((Unit*)NULL, spellId, triggered);
}

inline Creature* CreatureAI::DoSummon(uint32 entry, const Position& pos, uint32 despawnTime, TempSummonType summonType)
{
    return me->SummonCreature(entry, pos, summonType, despawnTime);
}

inline Creature* CreatureAI::DoSummon(uint32 entry, WorldObject* obj, float radius, uint32 despawnTime, TempSummonType summonType)
{
    Position pos;
    obj->GetRandomNearPosition(pos, radius);
    return me->SummonCreature(entry, pos, summonType, despawnTime);
}

inline Creature* CreatureAI::DoSummonFlyer(uint32 entry, WorldObject* obj, float flightZ, float radius, uint32 despawnTime, TempSummonType summonType)
{
    Position pos;
    obj->GetRandomNearPosition(pos, radius);
    pos.m_positionZ += flightZ;
    return me->SummonCreature(entry, pos, summonType, despawnTime);
}

#endif

