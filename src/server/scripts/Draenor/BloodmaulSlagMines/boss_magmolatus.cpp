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
    SPELL_MAGMABARRAGE = 150004,
    SPELL_MAGMABARRAGE_AOE = 150011,
    SPELL_MOLTENBINDING = 149891,
    SPELL_THROWEARTH = 150076,
    SPELL_THROWFLAME = 150078,
};

enum Events
{
    EVENT_MAGMABARRAGE = 1,
    EVENT_MAGMABARRAGE_AOE,
    EVENT_MOLTENBINDING,
    EVENT_THROWEARTH,
    EVENT_THROWFLAME,
};

class Boss_Magmolatus : public CreatureScript
{
public:
    Boss_Magmolatus() : CreatureScript("boss_magmolatus") { }

    struct Boss_MagmolatusAI : public BossAI
    {
        Boss_MagmolatusAI(Creature* creature) : BossAI(creature, 74366)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_MAGMABARRAGE, 4000);
            events.ScheduleEvent(EVENT_MAGMABARRAGE_AOE, 8000);
            events.ScheduleEvent(EVENT_MOLTENBINDING, 12000);
            events.ScheduleEvent(EVENT_THROWEARTH, 16000);
            events.ScheduleEvent(EVENT_THROWFLAME, 20000);
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
                case EVENT_MAGMABARRAGE:
                    if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target,SPELL_MAGMABARRAGE);
                    events.ScheduleEvent(EVENT_MAGMABARRAGE, 4000);
                    break;
                case EVENT_MAGMABARRAGE_AOE:
                    DoCastAOE(SPELL_MAGMABARRAGE_AOE);
                    events.ScheduleEvent(EVENT_MAGMABARRAGE_AOE, 8000);
                    break;
                case EVENT_MOLTENBINDING:
                    DoCastVictim(SPELL_MOLTENBINDING);
                    events.ScheduleEvent(EVENT_MOLTENBINDING, 12000);
                    break;
                case EVENT_THROWEARTH:
                    DoCastVictim(SPELL_THROWEARTH);
                    events.ScheduleEvent(EVENT_THROWEARTH, 16000);
                    break;
                case EVENT_THROWFLAME:
                    DoCastVictim(SPELL_THROWFLAME);
                    events.ScheduleEvent(EVENT_THROWFLAME, 20000);
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
        return new Boss_MagmolatusAI(creature);
    }
};

void AddSC_Boss_Magmolatus()
{
    new Boss_Magmolatus();
}
