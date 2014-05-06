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
#include "blackrock_spire.h"
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

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_FATAL_BITE, urand(17000,20000));
            events.ScheduleEvent(EVENT_INFECTED_BITE, urand(10000,12000));
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
                        events.ScheduleEvent(EVENT_FATAL_BITE, urand(8000,10000));
                        break;
                    case EVENT_INFECTED_BITE:
                        DoCast(me, SPELL_INFECTED_BITE);
                        events.ScheduleEvent(EVENT_FATAL_BITE, urand(8000,10000));
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_gizrul_the_slavenerAI(creature);
    }
};

void AddSC_boss_gizrul_the_slavener()
{
    new boss_gizrul_the_slavener();
}
