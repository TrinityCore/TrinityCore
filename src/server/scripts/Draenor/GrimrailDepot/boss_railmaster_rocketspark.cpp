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
    SPELL_ACQUIRING_TARGETS = 162491,
    SPELL_BETTER_POSITION = 162171,
    SPELL_LOCKING_ON = 166561,
    SPELL_MISSILE_SMOKE = 162572,
    SPELL_NEW_PLAN = 161091,
    SPELL_RECOVERING = 163947,
    SPELL_VX18B_TARGET_ELIMINATOR = 162500,
    SPELL_X2101A_MISSILE_BARRAGE = 162407
};

enum Events
{
    EVENT_ACQUIRING_TARGETS = 1,
    EVENT_BETTER_POSITION,
    EVENT_LOCKING_ON,
    EVENT_MISSILE_SMOKE,
    EVENT_NEW_PLAN,
    EVENT_RECOVERING,
    EVENT_VX18B_TARGET_ELIMINATOR,
    EVENT_X2101A_MISSILE_BARRAGE
};

class boss_railmaster_rocketspark : public CreatureScript
{
public:
    boss_railmaster_rocketspark() : CreatureScript("boss_railmaster_rocketspark") { }

    struct boss_railmaster_rocketsparkAI : public BossAI
    {
        boss_railmaster_rocketsparkAI(Creature* creature) : BossAI(creature, 77803)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_ACQUIRING_TARGETS, 4000);
            events.ScheduleEvent(EVENT_BETTER_POSITION, 8000);
            events.ScheduleEvent(EVENT_LOCKING_ON, 12000);
            events.ScheduleEvent(EVENT_MISSILE_SMOKE, 16000);
            events.ScheduleEvent(EVENT_NEW_PLAN, 20000);
            events.ScheduleEvent(EVENT_RECOVERING, 4000);
            events.ScheduleEvent(EVENT_VX18B_TARGET_ELIMINATOR, 8000);
            events.ScheduleEvent(EVENT_X2101A_MISSILE_BARRAGE, 12000);
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
                case EVENT_ACQUIRING_TARGETS:
                    if(Unit *target1 = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target1,SPELL_ACQUIRING_TARGETS);
                    if(randomBool()){
                        if(Unit *target2 = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target2,SPELL_ACQUIRING_TARGETS);
                    }
                    events.ScheduleEvent(EVENT_ACQUIRING_TARGETS, 4000);
                    break;
                case EVENT_BETTER_POSITION:
                    DoCast(SPELL_BETTER_POSITION);
                    events.ScheduleEvent(EVENT_BETTER_POSITION, 8000);
                    break;
                case EVENT_LOCKING_ON:
                    DoCast(SPELL_LOCKING_ON);
                    events.ScheduleEvent(EVENT_LOCKING_ON, 12000);
                    break;
                case EVENT_MISSILE_SMOKE:
                    DoCast(SPELL_MISSILE_SMOKE);
                    events.ScheduleEvent(EVENT_MISSILE_SMOKE, 16000);
                    break;
                case EVENT_NEW_PLAN:
                    DoCast(SPELL_NEW_PLAN);
                    events.ScheduleEvent(EVENT_NEW_PLAN, 20000);
                    break;
                case EVENT_RECOVERING:
                    DoCast(SPELL_RECOVERING);
                    events.ScheduleEvent(EVENT_RECOVERING, 4000);
                    break;
                case EVENT_VX18B_TARGET_ELIMINATOR:
                    if(Unit *target1 = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target1,SPELL_VX18B_TARGET_ELIMINATOR);
                    if(randomBool()){
                        if(Unit *target2 = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target2,SPELL_VX18B_TARGET_ELIMINATOR);
                    }
                    events.ScheduleEvent(EVENT_VX18B_TARGET_ELIMINATOR, 8000);
                    break;
                case EVENT_X2101A_MISSILE_BARRAGE:
                    if(Unit *target1 = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target1,SPELL_X2101A_MISSILE_BARRAGE);
                    if(Unit *target2 = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target2,SPELL_X2101A_MISSILE_BARRAGE);
                    events.ScheduleEvent(EVENT_X2101A_MISSILE_BARRAGE, 12000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

        bool randomBool() {
            return rand() % 2 == 1;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_railmaster_rocketsparkAI(creature);
    }
};

void AddSC_boss_railmaster_rocketspark()
{
    new boss_railmaster_rocketspark();
}
