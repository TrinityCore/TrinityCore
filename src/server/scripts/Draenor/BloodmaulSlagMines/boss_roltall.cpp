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
    SPELL_BURNINGSLAG = 152939,
    SPELL_BURNINGSLAG_INSTANT = 153227,
    SPELL_FIERYBOULDER = 153247,
    SPELL_HEATWAVE = 152940,
    SPELL_MOLTENREACH = 152941,
};

enum Events
{
    EVENT_BURNINGSLAG = 1,
    EVENT_BURNINGSLAG_INSTANT,
    EVENT_FIERYBOULDER,
    EVENT_HEATWAVE,
    EVENT_MOLTENREACH,
};


class Boss_Roltall : public CreatureScript
{
public:
    Boss_Roltall() : CreatureScript("boss_roltall") { }

    struct Boss_RoltallAI : public BossAI
    {
        Boss_RoltallAI(Creature* creature) : BossAI(creature, 75786)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_BURNINGSLAG, 4000);
            events.ScheduleEvent(EVENT_BURNINGSLAG_INSTANT, 8000);
            events.ScheduleEvent(EVENT_FIERYBOULDER, 12000);
            events.ScheduleEvent(EVENT_HEATWAVE, 16000);
            events.ScheduleEvent(EVENT_MOLTENREACH, 20000);
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
                case EVENT_BURNINGSLAG:
                    DoCastAOE(SPELL_BURNINGSLAG);
                    events.ScheduleEvent(EVENT_BURNINGSLAG, 4000);
                    break;
                case EVENT_BURNINGSLAG_INSTANT:
                    DoCastAOE(SPELL_BURNINGSLAG_INSTANT);
                    events.ScheduleEvent(EVENT_BURNINGSLAG_INSTANT, 8000);
                    break;
                case EVENT_FIERYBOULDER:
                    DoCastAOE(SPELL_FIERYBOULDER);
                    events.ScheduleEvent(EVENT_FIERYBOULDER, 12000);
                    break;
                case EVENT_HEATWAVE:
                    DoCastAOE(SPELL_HEATWAVE);
                    events.ScheduleEvent(EVENT_HEATWAVE, 16000);
                    break;
                case EVENT_MOLTENREACH:
                    DoCastVictim(SPELL_MOLTENREACH);
                    events.ScheduleEvent(EVENT_MOLTENREACH, 20000);
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
        return new Boss_RoltallAI(creature);
    }
};

void AddSC_Boss_Roltall()
{
    new Boss_Roltall();
}
