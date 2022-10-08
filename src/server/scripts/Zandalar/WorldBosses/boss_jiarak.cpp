/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "world_bosses_zuldazar.h"

enum Events {
    EVENT_STORM_WING      = 1,
    EVENT_HURRICANE_CRASH = 2,
    EVENT_MATRIARCHS_CALL = 3,
};

enum Spells {
    SPELL_STORM_WING      = 260908,
    SPELL_HURRICANE_CRASH = 261088,
    SPELL_MATRIARCHS_CALL = 261467,
};

struct boss_jiarak : public BossAI
{
    boss_jiarak(Creature* creature) : BossAI(creature, DATA_JIRAK) { }

    void Reset() override
    {
        events.Reset();
        summons.DespawnAll();
    }

    void EnterCombat(Unit* who) override
    {
        BossAI::EnterCombat(who);

        //EVENTS
        events.ScheduleEvent(EVENT_STORM_WING, 11000);
        events.ScheduleEvent(EVENT_MATRIARCHS_CALL, 30000);
        events.ScheduleEvent(EVENT_HURRICANE_CRASH, 45000);
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
            case EVENT_STORM_WING:
            {
                me->CastSpell(me, SPELL_STORM_WING);
                if (urand(0, 1) == 0)
                {
                    events.ScheduleEvent(EVENT_STORM_WING, 15000);
                }
                else
                {
                    events.ScheduleEvent(EVENT_STORM_WING, 45000);
                }
                break;
            }
            case EVENT_MATRIARCHS_CALL:
            {
                me->CastSpell(me, SPELL_MATRIARCHS_CALL);
                if (urand(0, 1) == 0)
                {
                    events.ScheduleEvent(EVENT_MATRIARCHS_CALL, 12000);
                }
                else
                {
                    events.ScheduleEvent(EVENT_MATRIARCHS_CALL, 45000);
                }
                break;
            }
            case EVENT_HURRICANE_CRASH:
            {
                me->CastSpell(me, SPELL_HURRICANE_CRASH);
                events.ScheduleEvent(EVENT_HURRICANE_CRASH, 45000);
                break;
            }
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
};

void AddSC_boss_jiarak()
{
    RegisterCreatureAI(boss_jiarak);
}
