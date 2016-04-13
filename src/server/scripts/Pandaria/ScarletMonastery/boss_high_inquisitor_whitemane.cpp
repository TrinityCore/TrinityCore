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
    SPELL_DEEP_SLEEP = 9256,
    SPELL_HOLY_SMITE = 114848,
    SPELL_POWER_WORD_SHIELD = 127399,
    SPELL_SCARLET_RESURRECTION = 9232
};

enum Events
{
    EVENT_DEEP_SLEEP = 1,
    EVENT_HOLY_SMITE,
    EVENT_POWER_WORD_SHIELD,
    EVENT_SCARLET_RESURRECTION
};

class boss_high_inquisitor_whitemane : public CreatureScript
{
public:
    boss_high_inquisitor_whitemane() : CreatureScript("boss_high_inquisitor_whitemane") { }

    struct boss_high_inquisitor_whitemaneAI : public BossAI
    {
        boss_high_inquisitor_whitemaneAI(Creature* creature) : BossAI(creature, 74366)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_DEEP_SLEEP, 4000);
            events.ScheduleEvent(EVENT_HOLY_SMITE, 12000);
            events.ScheduleEvent(EVENT_POWER_WORD_SHIELD, 16000);
            events.ScheduleEvent(EVENT_SCARLET_RESURRECTION, 20000);
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
                case EVENT_DEEP_SLEEP:
                    DoCastAOE(SPELL_DEEP_SLEEP);
                    events.ScheduleEvent(EVENT_DEEP_SLEEP, 4000);
                    break;
                case EVENT_HOLY_SMITE:
                    DoCastVictim(SPELL_HOLY_SMITE);
                    events.ScheduleEvent(EVENT_HOLY_SMITE, 12000);
                    break;
                case EVENT_POWER_WORD_SHIELD:
                    DoCast(SPELL_POWER_WORD_SHIELD);
                    events.ScheduleEvent(EVENT_POWER_WORD_SHIELD, 16000);
                    break;
                case EVENT_SCARLET_RESURRECTION:
                    DoCast(SPELL_SCARLET_RESURRECTION);
                    events.ScheduleEvent(EVENT_SCARLET_RESURRECTION, 20000);
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
        return new boss_high_inquisitor_whitemaneAI(creature);
    }
};

void AddSC_boss_high_inquisitor_whitemane()
{
    new boss_high_inquisitor_whitemane();
}
