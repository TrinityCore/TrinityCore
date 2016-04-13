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
    SPELL_BARBED_ARROW_BARRAGE = 166923,
    SPELL_INTIMIDATED = 164504,
    SPELL_RECKLESS_PROVOCATION = 164426,
};

enum Events
{
    EVENT_BARBED_ARROW_BARRAGE = 1,
    EVENT_INTIMIDATED,
    EVENT_RECKLESS_PROVOCATION,
};

class boss_fleshrender_nokgar : public CreatureScript
{
public:
    boss_fleshrender_nokgar() : CreatureScript("boss_fleshrender_nokgar") { }

    struct boss_fleshrender_nokgarAI : public BossAI
    {
        boss_fleshrender_nokgarAI(Creature* creature) : BossAI(creature, 81305)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_BARBED_ARROW_BARRAGE, 4000);
            events.ScheduleEvent(EVENT_INTIMIDATED, 8000);
            events.ScheduleEvent(EVENT_RECKLESS_PROVOCATION, 12000);
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
                case EVENT_BARBED_ARROW_BARRAGE:
                    DoCastAOE(SPELL_BARBED_ARROW_BARRAGE);
                    events.ScheduleEvent(EVENT_BARBED_ARROW_BARRAGE, 4000);
                    break;
                case EVENT_INTIMIDATED:
                    DoCastAOE(SPELL_INTIMIDATED);
                    events.ScheduleEvent(EVENT_INTIMIDATED, 8000);
                    break;
                case EVENT_RECKLESS_PROVOCATION:
                    DoCastAOE(SPELL_RECKLESS_PROVOCATION);
                    events.ScheduleEvent(EVENT_RECKLESS_PROVOCATION, 12000);
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
        return new boss_fleshrender_nokgarAI(creature);
    }
};

void AddSC_boss_fleshrender_nokgar()
{
    new boss_fleshrender_nokgar();
}
