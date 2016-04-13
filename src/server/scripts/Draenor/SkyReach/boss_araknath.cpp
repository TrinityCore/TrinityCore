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
    SPELL_BURST = 154135,
    SPELL_SMASH = 154132
};

enum Events
{
    EVENT_BURST = 1,
    EVENT_SMASH
};

class boss_araknath : public CreatureScript
{
public:
    boss_araknath() : CreatureScript("boss_araknath") { }

    struct boss_araknathAI : public BossAI
    {
        boss_araknathAI(Creature* creature) : BossAI(creature, 76141)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_BURST, 4000);
            events.ScheduleEvent(EVENT_SMASH, 8000);
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
                case EVENT_BURST:
                    DoCastAOE(SPELL_BURST);
                    events.ScheduleEvent(EVENT_BURST, 4000);
                    break;
                case EVENT_SMASH:
                    DoCastAOE(SPELL_SMASH);
                    events.ScheduleEvent(EVENT_SMASH, 8000);
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
        return new boss_araknathAI(creature);
    }
};

void AddSC_boss_araknath()
{
    new boss_araknath();
}
