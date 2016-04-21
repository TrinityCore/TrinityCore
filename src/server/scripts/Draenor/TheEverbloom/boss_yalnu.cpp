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
    SPELL_COLOSSAL_BLOW = 169179,
    SPELL_ENTANGLEMENT = 169251,
    SPELL_GENESIS = 169613,
    SPELL_GERMINATE_ARBORBLADE = 169265
};

enum Events
{
    EVENT_COLOSSAL_BLOW = 1,
    EVENT_ENTANGLEMENT,
    EVENT_GENESIS,
    EVENT_GERMINATE_ARBORBLADE
};

class boss_yalnu : public CreatureScript
{
public:
    boss_yalnu() : CreatureScript("boss_yalnu") { }

    struct boss_yalnuAI : public BossAI
    {
        boss_yalnuAI(Creature* creature) : BossAI(creature, 83846)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_COLOSSAL_BLOW, 4000);
            events.ScheduleEvent(EVENT_ENTANGLEMENT, 8000);
            events.ScheduleEvent(EVENT_GENESIS, 12000);
            events.ScheduleEvent(EVENT_GERMINATE_ARBORBLADE, 16000);
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
                case EVENT_COLOSSAL_BLOW:
                    DoCastAOE(SPELL_COLOSSAL_BLOW);
                    events.ScheduleEvent(EVENT_COLOSSAL_BLOW, 4000);
                    break;
                case EVENT_ENTANGLEMENT:
                    DoCastAOE(SPELL_ENTANGLEMENT);
                    events.ScheduleEvent(EVENT_ENTANGLEMENT, 8000);
                    break;
                case EVENT_GENESIS:
                    DoCast(SPELL_GENESIS);
                    events.ScheduleEvent(EVENT_GENESIS, 12000);
                    break;
                case EVENT_GERMINATE_ARBORBLADE:
                    DoCast(SPELL_GERMINATE_ARBORBLADE);
                    events.ScheduleEvent(EVENT_GERMINATE_ARBORBLADE, 16000);
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
        return new boss_yalnuAI(creature);
    }
};

void AddSC_boss_yalnu()
{
    new boss_yalnu();
}
