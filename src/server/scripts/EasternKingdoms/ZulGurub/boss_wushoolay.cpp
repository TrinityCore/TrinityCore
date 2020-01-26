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

#include "zulgurub.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum Spells
{
    SPELL_LIGHTNINGCLOUD = 25033,
    SPELL_LIGHTNINGWAVE = 24819
};

enum Events
{
    EVENT_LIGHTNINGCLOUD = 1,
    EVENT_LIGHTNINGWAVE = 2
};

class boss_wushoolay : public CreatureScript
{
    public:
        boss_wushoolay() : CreatureScript("boss_wushoolay") { }

        struct boss_wushoolayAI : public BossAI
        {
            boss_wushoolayAI(Creature* creature) : BossAI(creature, DATA_EDGE_OF_MADNESS) { }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                events.ScheduleEvent(EVENT_LIGHTNINGCLOUD, 5s, 10s);
                events.ScheduleEvent(EVENT_LIGHTNINGWAVE, 8s, 16s);
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
                        case EVENT_LIGHTNINGCLOUD:
                            DoCastVictim(SPELL_LIGHTNINGCLOUD, true);
                            events.ScheduleEvent(EVENT_LIGHTNINGCLOUD, 15s, 20s);
                            break;
                        case EVENT_LIGHTNINGWAVE:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_LIGHTNINGWAVE);
                            events.ScheduleEvent(EVENT_LIGHTNINGWAVE, 12s, 16s);
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
            return GetZulGurubAI<boss_wushoolayAI>(creature);
        }
};

void AddSC_boss_wushoolay()
{
    new boss_wushoolay();
}
