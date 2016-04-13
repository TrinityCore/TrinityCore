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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_CONSUME = 169248,
    SPELL_DESCEND = 172643,
    SPELL_GASEOUS_VOLLEY = 169382,
    SPELL_TOXIC_BOLT = 169375,
    SPELL_TOXIC_GAS = 169223,
    SPELL_VENOMOUS_STING = 169376,
    SPELL_WEB_CRAWL = 169271
};

enum Events
{
    EVENT_CONSUME = 1,
    EVENT_DESCEND,
    EVENT_GASEOUS_VOLLEY,
    EVENT_TOXIC_BOLT,
    EVENT_TOXIC_GAS,
    EVENT_VENOMOUS_STING,
    EVENT_WEB_CRAWL
};

class boss_xeritac : public CreatureScript
{
public:
    boss_xeritac() : CreatureScript("boss_xeritac") { }

    struct boss_xeritacAI : public BossAI
    {
        boss_xeritacAI(Creature* creature) : BossAI(creature, 84550)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_CONSUME, 4000);
            events.ScheduleEvent(EVENT_DESCEND, 8000);
            events.ScheduleEvent(EVENT_GASEOUS_VOLLEY, 12000);
            events.ScheduleEvent(EVENT_TOXIC_BOLT, 16000);
            events.ScheduleEvent(EVENT_TOXIC_GAS, 20000);
            events.ScheduleEvent(EVENT_VENOMOUS_STING, 4000);
            events.ScheduleEvent(EVENT_WEB_CRAWL, 8000);
        }

        void KilledUnit(Unit * /*victim*/) override
        {
        }

        void JustDied(Unit * /*victim*/) override
        {
            _JustDied();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CONSUME:
                    DoCast(me,SPELL_CONSUME);
                    events.ScheduleEvent(EVENT_CONSUME, 4000);
                    break;
                case EVENT_DESCEND:
                    DoCastAOE(SPELL_DESCEND);
                    events.ScheduleEvent(EVENT_DESCEND, 8000);
                    break;
                case EVENT_GASEOUS_VOLLEY:
                    DoCastAOE(SPELL_GASEOUS_VOLLEY);
                    events.ScheduleEvent(EVENT_GASEOUS_VOLLEY, 12000);
                    break;
                case EVENT_TOXIC_BOLT:
                    DoCastVictim(SPELL_TOXIC_BOLT);
                    events.ScheduleEvent(EVENT_TOXIC_BOLT, 16000);
                    break;
                case EVENT_TOXIC_GAS:
                    DoCastAOE(SPELL_TOXIC_GAS);
                    events.ScheduleEvent(EVENT_TOXIC_GAS, 20000);
                    break;
                case EVENT_VENOMOUS_STING:
                    if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target,SPELL_VENOMOUS_STING);
                    events.ScheduleEvent(EVENT_VENOMOUS_STING, 4000);
                    break;
                case EVENT_WEB_CRAWL:
                    DoCast(SPELL_WEB_CRAWL);
                    events.ScheduleEvent(EVENT_WEB_CRAWL, 8000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_xeritacAI(creature);
    }
};

void AddSC_boss_xeritac()
{
    new boss_xeritac();
}
