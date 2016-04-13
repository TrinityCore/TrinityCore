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
    SPELL_DEBILITATING_FIXATION = 161199,
    SPELL_REJUVENATING_SERUM = 161203,
    SPELL_VILEBLOOD_SERUM = 161233
};

enum Events
{
    EVENT_DEBILITATING_FIXATION = 1,
    EVENT_REJUVENATING_SERUM,
    EVENT_VILEBLOOD_SERUM
};

class boss_kyrak : public CreatureScript
{
public:
    boss_kyrak() : CreatureScript("boss_kyrak") { }

    struct boss_kyrakAI : public BossAI
    {
        boss_kyrakAI(Creature* creature) : BossAI(creature, 76021)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_DEBILITATING_FIXATION, 4000);
            events.ScheduleEvent(EVENT_REJUVENATING_SERUM, 8000);
            events.ScheduleEvent(EVENT_VILEBLOOD_SERUM, 12000);
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
                case EVENT_DEBILITATING_FIXATION:
                    DoCastVictim(SPELL_DEBILITATING_FIXATION);
                    events.ScheduleEvent(EVENT_DEBILITATING_FIXATION, 4000);
                    break;
                case EVENT_REJUVENATING_SERUM:
                    DoCast(me,SPELL_REJUVENATING_SERUM);
                    events.ScheduleEvent(EVENT_REJUVENATING_SERUM, 8000);
                    break;
                case EVENT_VILEBLOOD_SERUM:
                    DoCastAOE(SPELL_VILEBLOOD_SERUM);
                    events.ScheduleEvent(EVENT_VILEBLOOD_SERUM, 12000);
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
        return new boss_kyrakAI(creature);
    }
};

void AddSC_boss_kyrak()
{
    new boss_kyrak();
}
