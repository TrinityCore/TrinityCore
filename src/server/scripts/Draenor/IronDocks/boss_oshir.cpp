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
    SPELL_BREAKOUT = 178124,
    SPELL_FEEDING_FRENZY = 162424,
    SPELL_PRIMAL_ASSAULT = 161256,
    SPELL_TIME_TO_FEED = 162415,
};

enum Events
{
    EVENT_BREAKOUT = 1,
    EVENT_FEEDING_FRENZY,
    EVENT_PRIMAL_ASSAULT,
    EVENT_TIME_TO_FEED,
};

class boss_oshir : public CreatureScript
{
public:
    boss_oshir() : CreatureScript("boss_oshir") { }

    struct boss_oshirAI : public BossAI
    {
        boss_oshirAI(Creature* creature) : BossAI(creature, 79852)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_BREAKOUT, 4000);
            events.ScheduleEvent(EVENT_FEEDING_FRENZY, 8000);
            events.ScheduleEvent(EVENT_PRIMAL_ASSAULT, 12000);
            events.ScheduleEvent(EVENT_TIME_TO_FEED, 16000);
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
                case EVENT_BREAKOUT:
                    DoCast(SPELL_BREAKOUT);
                    events.ScheduleEvent(EVENT_BREAKOUT, 4000);
                    break;
                case EVENT_FEEDING_FRENZY:
                    DoCast(SPELL_FEEDING_FRENZY);
                    events.ScheduleEvent(EVENT_FEEDING_FRENZY, 8000);
                    break;
                case EVENT_PRIMAL_ASSAULT:
                    DoCast(SPELL_PRIMAL_ASSAULT);
                    events.ScheduleEvent(EVENT_PRIMAL_ASSAULT, 12000);
                    break;
                case EVENT_TIME_TO_FEED:
                    DoCastVictim(SPELL_TIME_TO_FEED);
                    events.ScheduleEvent(EVENT_TIME_TO_FEED, 16000);
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
        return new boss_oshirAI(creature);
    }
};

void AddSC_boss_oshir()
{
    new boss_oshir();
}
