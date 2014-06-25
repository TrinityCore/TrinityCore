/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
    SPELL_WHIRLWIND                                        = 15589,
    SPELL_MORTALSTRIKE                                     = 24573
};

enum Events
{
    EVENT_WHIRLWIND                                        = 1,
    EVENT_MORTALSTRIKE                                     = 2
};

class boss_gorosh_the_dervish : public CreatureScript
{
    public:
        boss_gorosh_the_dervish() : CreatureScript("boss_gorosh_the_dervish") { }

        struct boss_gorosh_the_dervishAI : public ScriptedAI
        {
            boss_gorosh_the_dervishAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                _events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_WHIRLWIND, 12000);
                _events.ScheduleEvent(EVENT_MORTALSTRIKE, 22000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WHIRLWIND:
                            DoCast(me, SPELL_WHIRLWIND);
                            _events.ScheduleEvent(EVENT_WHIRLWIND, 15000);
                            break;
                        case EVENT_MORTALSTRIKE:
                            DoCastVictim(SPELL_MORTALSTRIKE);
                            _events.ScheduleEvent(EVENT_MORTALSTRIKE, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_gorosh_the_dervishAI(creature);
        }
};

void AddSC_boss_gorosh_the_dervish()
{
    new boss_gorosh_the_dervish();
}
