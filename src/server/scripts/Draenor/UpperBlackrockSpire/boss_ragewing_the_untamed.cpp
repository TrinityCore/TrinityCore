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
    SPELL_BURNING_RANGE = 155620,
    SPELL_ENGULFING_FIRE = 155031,
    SPELL_FIRE_BREATH = 155593,
    SPELL_RIPPING_CLAW = 155065,
    SPELL_SWIRLING_WINDS = 167203
};

enum Events
{
    EVENT_BURNING_RANGE = 1,
    EVENT_ENGULFING_FIRE,
    EVENT_FIRE_BREATH,
    EVENT_RIPPING_CLAW,
    EVENT_SWIRLING_WINDS
};

class boss_ragewing_the_untamed : public CreatureScript
{
public:
    boss_ragewing_the_untamed() : CreatureScript("boss_ragewing_the_untamed") { }

    struct boss_ragewing_the_untamedAI : public BossAI
    {
        boss_ragewing_the_untamedAI(Creature* creature) : BossAI(creature, 76585)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_BURNING_RANGE, 4000);
            events.ScheduleEvent(EVENT_ENGULFING_FIRE, 8000);
            events.ScheduleEvent(EVENT_FIRE_BREATH, 12000);
            events.ScheduleEvent(EVENT_RIPPING_CLAW, 16000);
            events.ScheduleEvent(EVENT_SWIRLING_WINDS, 20000);
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
                case EVENT_BURNING_RANGE:
                    DoCast(me,SPELL_BURNING_RANGE);
                    events.ScheduleEvent(EVENT_BURNING_RANGE, 4000);
                    break;
                case EVENT_ENGULFING_FIRE:
                    DoCastAOE(SPELL_ENGULFING_FIRE);
                    events.ScheduleEvent(EVENT_ENGULFING_FIRE, 8000);
                    break;
                case EVENT_FIRE_BREATH:
                    DoCastVictim(SPELL_FIRE_BREATH);
                    events.ScheduleEvent(EVENT_FIRE_BREATH, 12000);
                    break;
                case EVENT_RIPPING_CLAW:
                    DoCastVictim(SPELL_RIPPING_CLAW);
                    events.ScheduleEvent(EVENT_RIPPING_CLAW, 16000);
                    break;
                case EVENT_SWIRLING_WINDS:
                    DoCast(SPELL_SWIRLING_WINDS);
                    events.ScheduleEvent(EVENT_SWIRLING_WINDS, 20000);
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
        return new boss_ragewing_the_untamedAI(creature);
    }
};

void AddSC_boss_ragewing_the_untamed()
{
    new boss_ragewing_the_untamed();
}
