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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "zulaman.h"

enum Spells
{
};

enum Says
{
};

enum Events
{
};

class boss_nalorakk : public CreatureScript
{
    public:

        boss_nalorakk() : CreatureScript("boss_nalorakk") { }

        struct boss_nalorakkAI : public BossAI
        {
            boss_nalorakkAI(Creature* creature) : BossAI(creature, DATA_NALORAKK) { }

            void Reset()
            {
                _Reset();
            }
            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
            }

            void KilledUnit(Unit* /*victim*/)
            {
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
                /*
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        default:
                            break;
                    }
                }
                */

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_nalorakkAI(creature);
        }
};

void AddSC_boss_nalorakk()
{
    new boss_nalorakk();
}
