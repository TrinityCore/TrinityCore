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
    SPELL_BONE_SPIKE = 113999,
    SPELL_RUSTING = 113765
};

enum Events
{
    EVENT_BONE_SPIKE = 1,
    EVENT_RUSTING
};

class boss_rattlegore_script : public CreatureScript
{
public:
    boss_rattlegore_script() : CreatureScript("boss_rattlegore_script") { }

    struct boss_rattlegore_scriptAI : public BossAI
    {
        boss_rattlegore_scriptAI(Creature* creature) : BossAI(creature, 59153)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_BONE_SPIKE, 4000);
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
                case EVENT_BONE_SPIKE:
                    DoCastVictim(SPELL_BONE_SPIKE);
                    events.ScheduleEvent(EVENT_BONE_SPIKE, 4000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
            DoCast(SPELL_RUSTING);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_rattlegore_scriptAI(creature);
    }
};

void AddSC_boss_rattlegore_script()
{
    new boss_rattlegore_script();
}
