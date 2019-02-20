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

#include "ScriptMgr.h"
#include "blackrock_spire.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_FATAL_BITE                = 16495,
    SPELL_INFECTED_BITE             = 16128,
    SPELL_FRENZY                    = 8269
};

enum Paths
{
    GIZRUL_PATH                     = 402450
};

enum Events
{
    EVENT_FATAL_BITE                = 1,
    EVENT_INFECTED_BITE             = 2,
    EVENT_FRENZY                    = 3
};

class boss_gizrul_the_slavener : public CreatureScript
{
public:
    boss_gizrul_the_slavener() : CreatureScript("boss_gizrul_the_slavener") { }

    struct boss_gizrul_the_slavenerAI : public BossAI
    {
       boss_gizrul_the_slavenerAI(Creature* creature) : BossAI(creature, DATA_GIZRUL_THE_SLAVENER) { }

        void Reset() override
        {
            _Reset();
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            me->GetMotionMaster()->MovePath(GIZRUL_PATH, false);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _JustEngagedWith();
            events.ScheduleEvent(EVENT_FATAL_BITE, 17s, 20s);
            events.ScheduleEvent(EVENT_INFECTED_BITE, 10s, 12s);
        }

        void JustDied(Unit* /*killer*/) override
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
                    case EVENT_FATAL_BITE:
                        DoCastVictim(SPELL_FATAL_BITE);
                        events.ScheduleEvent(EVENT_FATAL_BITE, 8s, 10s);
                        break;
                    case EVENT_INFECTED_BITE:
                        DoCast(me, SPELL_INFECTED_BITE);
                        events.ScheduleEvent(EVENT_FATAL_BITE, 8s, 10s);
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
        return GetBlackrockSpireAI<boss_gizrul_the_slavenerAI>(creature);
    }
};

void AddSC_boss_gizrul_the_slavener()
{
    new boss_gizrul_the_slavener();
}
