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
    SPELL_DIFFUSED_ENERGY = 161588,
    SPELL_FREEZING_SNARE = 162066,
    SPELL_SPINNING_SPEAR = 162057
};

enum Events
{
    EVENT_DIFFUSED_ENERGY = 1,
    EVENT_FREEZING_SNARE,
    EVENT_SPINNING_SPEAR
};

class boss_skylord_tovra : public CreatureScript
{
public:
    boss_skylord_tovra() : CreatureScript("boss_skylord_tovra") { }

    struct boss_skylord_tovraAI : public BossAI
    {
        boss_skylord_tovraAI(Creature* creature) : BossAI(creature, 80005)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_DIFFUSED_ENERGY, 4000);
            events.ScheduleEvent(EVENT_FREEZING_SNARE, 8000);
            events.ScheduleEvent(EVENT_SPINNING_SPEAR, 12000);
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
                case EVENT_DIFFUSED_ENERGY:
                    DoCastAOE(SPELL_DIFFUSED_ENERGY);
                    events.ScheduleEvent(EVENT_DIFFUSED_ENERGY, 4000);
                    break;
                case EVENT_FREEZING_SNARE:
                    DoCastAOE(SPELL_FREEZING_SNARE);
                    events.ScheduleEvent(EVENT_FREEZING_SNARE, 8000);
                    break;
                case EVENT_SPINNING_SPEAR:
                    DoCastVictim(SPELL_SPINNING_SPEAR);
                    events.ScheduleEvent(EVENT_SPINNING_SPEAR, 12000);
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
        return new boss_skylord_tovraAI(creature);
    }
};

void AddSC_boss_skylord_tovra()
{
    new boss_skylord_tovra();
}
