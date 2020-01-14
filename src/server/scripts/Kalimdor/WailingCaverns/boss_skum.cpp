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

#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "wailing_caverns.h"

enum Spells
{
    SPELL_CHAINED_BOLT = 6254
};

enum Events
{
    EVENT_CHAINED_BOLT = 1
};

class boss_skum : public CreatureScript
{
public:
    boss_skum() : CreatureScript("boss_skum") { }

    struct boss_skumAI : public BossAI
    {
        boss_skumAI(Creature* creature) : BossAI(creature, DATA_SKUM) { }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);

            events.ScheduleEvent(EVENT_CHAINED_BOLT, Seconds(3), Seconds(4));
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
                    case EVENT_CHAINED_BOLT:
                        DoCastVictim(SPELL_CHAINED_BOLT);
                        events.Repeat(randtime(Seconds(3), Seconds(4)));
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
        return GetWailingCavernsAI<boss_skumAI>(creature);
    }
};


void AddSC_boss_skum()
{
    new boss_skum();
}
