/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
Name: Boss_Illucia_Barov
%Complete: 100
Comment:
Category: Scholomance
*/

#include "ScriptMgr.h"
#include "scholomance.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_CURSEOFAGONY          = 18671,
    SPELL_DOMINATE              = 7645, // UNUSED YET added for documentation
    SPELL_FEAR                  = 12542,
    SPELL_SHADOWSHOCK           = 17234,
    SPELL_SILENCE               = 12528
};

enum Events
{
    EVENT_CURSEOFAGONY          = 1,
    EVENT_SHADOWSHOCK           = 2,
    EVENT_SILENCE               = 3,
    EVENT_FEAR                  = 4
};

class boss_illucia_barov : public CreatureScript
{
    public: boss_illucia_barov() : CreatureScript("boss_illucia_barov") { }

        struct boss_illuciabarovAI : public BossAI
        {
            boss_illuciabarovAI(Creature* creature) : BossAI(creature, DATA_LADYILLUCIABAROV) { }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                events.ScheduleEvent(EVENT_CURSEOFAGONY, 18s);
                events.ScheduleEvent(EVENT_SHADOWSHOCK, 9s);
                events.ScheduleEvent(EVENT_SILENCE, 5s);
                events.ScheduleEvent(EVENT_FEAR, 30s);
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
                        case EVENT_CURSEOFAGONY:
                            DoCastVictim(SPELL_CURSEOFAGONY, true);
                            events.ScheduleEvent(EVENT_CURSEOFAGONY, 30s);
                            break;
                        case EVENT_SHADOWSHOCK:
                            DoCast(SelectTarget(SelectTargetMethod::Random, 0, 100, true), SPELL_SHADOWSHOCK, true);
                            events.ScheduleEvent(EVENT_SHADOWSHOCK, 12s);
                            break;
                        case EVENT_SILENCE:
                            DoCastVictim(SPELL_SILENCE, true);
                            events.ScheduleEvent(EVENT_SILENCE, 14s);
                            break;
                        case EVENT_FEAR:
                            DoCastVictim(SPELL_FEAR, true);
                            events.ScheduleEvent(EVENT_FEAR, 30s);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetScholomanceAI<boss_illuciabarovAI>(creature);
        }
};

void AddSC_boss_illuciabarov()
{
    new boss_illucia_barov();
}
