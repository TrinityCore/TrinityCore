/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

/*
Name: Boss_the_ravenian
%Complete: 100
Comment:
Category: Scholomance
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "scholomance.h"

enum Spells
{
    SPELL_TRAMPLE                   = 15550,
    SPELL_CLEAVE                    = 20691,
    SPELL_SUNDERINCLEAVE            = 25174,
    SPELL_KNOCKAWAY                 = 10101
};

enum Events
{
    EVENT_TRAMPLE                   = 1,
    EVENT_CLEAVE                    = 2,
    EVENT_SUNDERINCLEAVE            = 3,
    EVENT_KNOCKAWAY                 = 4
};

class boss_the_ravenian : public CreatureScript
{
    public: boss_the_ravenian() : CreatureScript("boss_the_ravenian") { }

        struct boss_theravenianAI : public BossAI
        {
            boss_theravenianAI(Creature* creature) : BossAI(creature, DATA_THERAVENIAN) {}

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_TRAMPLE, 24000);
                events.ScheduleEvent(EVENT_CLEAVE, 15000);
                events.ScheduleEvent(EVENT_SUNDERINCLEAVE, 40000);
                events.ScheduleEvent(EVENT_KNOCKAWAY, 32000);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                        case EVENT_TRAMPLE:
                            DoCastVictim(SPELL_TRAMPLE, true);
                            events.ScheduleEvent(EVENT_TRAMPLE, 10000);
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE, true);
                            events.ScheduleEvent(EVENT_CLEAVE, 7000);
                            break;
                        case EVENT_SUNDERINCLEAVE:
                            DoCastVictim(SPELL_SUNDERINCLEAVE, true);
                            events.ScheduleEvent(EVENT_SUNDERINCLEAVE, 20000);
                            break;
                        case EVENT_KNOCKAWAY:
                            DoCastVictim(SPELL_KNOCKAWAY, true);
                            events.ScheduleEvent(EVENT_KNOCKAWAY, 12000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_theravenianAI(creature);
        }
};

void AddSC_boss_theravenian()
{
    new boss_the_ravenian();
}
