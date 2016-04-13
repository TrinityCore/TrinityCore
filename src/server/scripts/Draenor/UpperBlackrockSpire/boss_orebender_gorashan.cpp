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
    SPELL_BLADES_OF_STEEL = 154417,
    SPELL_SHRAPNEL_NOVA = 154448,
    SPELL_THUNDER_CACOPHONY = 154899
};

enum Events
{
    EVENT_BLADES_OF_STEEL = 1,
    EVENT_SHRAPNEL_NOVA,
    EVENT_THUNDER_CACOPHONY
};

class boss_orebender_gorashan : public CreatureScript
{
public:
    boss_orebender_gorashan() : CreatureScript("boss_orebender_gorashan") { }

    struct boss_orebender_gorashanAI : public BossAI
    {
        boss_orebender_gorashanAI(Creature* creature) : BossAI(creature, 76413)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_BLADES_OF_STEEL, 4000);
            events.ScheduleEvent(EVENT_SHRAPNEL_NOVA, 8000);
            events.ScheduleEvent(EVENT_THUNDER_CACOPHONY, 12000);
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
                case EVENT_BLADES_OF_STEEL:
                    DoCastVictim(SPELL_BLADES_OF_STEEL);
                    events.ScheduleEvent(EVENT_BLADES_OF_STEEL, 4000);
                    break;
                case EVENT_SHRAPNEL_NOVA:
                    DoCastAOE(SPELL_SHRAPNEL_NOVA);
                    events.ScheduleEvent(EVENT_SHRAPNEL_NOVA, 8000);
                    break;
                case EVENT_THUNDER_CACOPHONY:
                    DoCastAOE(SPELL_THUNDER_CACOPHONY);
                    events.ScheduleEvent(EVENT_THUNDER_CACOPHONY, 12000);
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
        return new boss_orebender_gorashanAI(creature);
    }
};

void AddSC_boss_orebender_gorashan()
{
    new boss_orebender_gorashan();
}
