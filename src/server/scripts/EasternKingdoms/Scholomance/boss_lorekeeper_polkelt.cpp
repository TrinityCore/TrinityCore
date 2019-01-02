/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
Name: Boss_Lorekeeper_Polkelt
%Complete: 100
Comment:
Category: Scholomance
*/

#include "scholomance.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_VOLATILEINFECTION     = 24928,
    SPELL_DARKPLAGUE            = 18270,
    SPELL_CORROSIVEACID         = 23313,
    SPELL_NOXIOUSCATALYST       = 18151
};

enum Events
{
    EVENT_VOLATILEINFECTION     = 1,
    EVENT_DARKPLAGUE            = 2,
    EVENT_CORROSIVEACID         = 3,
    EVENT_NOXIOUSCATALYST       = 4
};

class boss_lorekeeper_polkelt : public CreatureScript
{
    public: boss_lorekeeper_polkelt() : CreatureScript("boss_lorekeeper_polkelt") { }

        struct boss_lorekeeperpolkeltAI : public BossAI
        {
            boss_lorekeeperpolkeltAI(Creature* creature) : BossAI(creature, DATA_LOREKEEPERPOLKELT) { }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                events.ScheduleEvent(EVENT_VOLATILEINFECTION, 38s);
                events.ScheduleEvent(EVENT_DARKPLAGUE, 8s);
                events.ScheduleEvent(EVENT_CORROSIVEACID, 45s);
                events.ScheduleEvent(EVENT_NOXIOUSCATALYST, 35s);
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
                        case EVENT_VOLATILEINFECTION:
                            DoCastVictim(SPELL_VOLATILEINFECTION, true);
                            events.ScheduleEvent(EVENT_VOLATILEINFECTION, 32s);
                            break;
                        case EVENT_DARKPLAGUE:
                            DoCastVictim(SPELL_DARKPLAGUE, true);
                            events.ScheduleEvent(EVENT_DARKPLAGUE, 8s);
                            break;
                        case EVENT_CORROSIVEACID:
                            DoCastVictim(SPELL_CORROSIVEACID, true);
                            events.ScheduleEvent(EVENT_CORROSIVEACID, 25s);
                            break;
                        case EVENT_NOXIOUSCATALYST:
                            DoCastVictim(SPELL_NOXIOUSCATALYST, true);
                            events.ScheduleEvent(EVENT_NOXIOUSCATALYST, 38s);
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
            return GetScholomanceAI<boss_lorekeeperpolkeltAI>(creature);
        }
};

void AddSC_boss_lorekeeperpolkelt()
{
    new boss_lorekeeper_polkelt();
}
