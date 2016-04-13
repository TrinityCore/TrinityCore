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
    SPELL_IMBUED_IRON_AXE = 162090,
    SPELL_IRON_AXE = 161765,
    SPELL_IRON_RANGE = 161985,
    SPELL_IRON_REAVER = 162000
};

enum Events
{
    EVENT_IMBUED_IRON_AXE = 1,
    EVENT_IRON_AXE,
    EVENT_IRON_RANGE,
    EVENT_IRON_REAVER
};

class boss_commander_tharbek : public CreatureScript
{
public:
    boss_commander_tharbek() : CreatureScript("boss_commander_tharbek") { }

    struct boss_commander_tharbekAI : public BossAI
    {
        boss_commander_tharbekAI(Creature* creature) : BossAI(creature, 79912)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_IMBUED_IRON_AXE, 4000);
            events.ScheduleEvent(EVENT_IRON_AXE, 8000);
            events.ScheduleEvent(EVENT_IRON_RANGE, 12000);
            events.ScheduleEvent(EVENT_IRON_REAVER, 16000);
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
                case EVENT_IMBUED_IRON_AXE:
                    DoCastAOE(SPELL_IMBUED_IRON_AXE);
                    events.ScheduleEvent(EVENT_IMBUED_IRON_AXE, 4000);
                    break;
                case EVENT_IRON_AXE:
                    DoCastVictim(SPELL_IRON_AXE);
                    events.ScheduleEvent(EVENT_IRON_AXE, 8000);
                    break;
                case EVENT_IRON_RANGE:
                    DoCast(me,SPELL_IRON_RANGE);
                    events.ScheduleEvent(EVENT_IRON_RANGE, 12000);
                    break;
                case EVENT_IRON_REAVER:
                    if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target,SPELL_IRON_REAVER);
                    events.ScheduleEvent(EVENT_IRON_REAVER, 16000);
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
        return new boss_commander_tharbekAI(creature);
    }
};

void AddSC_boss_commander_tharbek()
{
    new boss_commander_tharbek();
}
