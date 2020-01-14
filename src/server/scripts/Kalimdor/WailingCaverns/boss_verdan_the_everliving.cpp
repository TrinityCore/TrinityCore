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
    SPELL_GRASPING_VINES = 8142
};

enum Events
{
    EVENT_GRASPING_VINES = 1
};

class boss_verdan_the_everliving : public CreatureScript
{
public:
    boss_verdan_the_everliving() : CreatureScript("boss_verdan_the_everliving") { }

    struct boss_verdan_the_everlivingAI : public BossAI
    {
        boss_verdan_the_everlivingAI(Creature* creature) : BossAI(creature, DATA_VERDAN_THE_EVERLIVING) { }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);

            events.ScheduleEvent(EVENT_GRASPING_VINES, Seconds(20),Seconds(35));
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
                    case EVENT_GRASPING_VINES:
                        DoCastVictim(SPELL_GRASPING_VINES);
                        events.Repeat(Seconds(20), Seconds(35));
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
        return GetWailingCavernsAI<boss_verdan_the_everlivingAI>(creature);
    }
};


void AddSC_boss_verdan_the_everliving()
{
    new boss_verdan_the_everliving();
}
