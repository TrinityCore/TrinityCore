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
    SPELL_BLOODY_RAGE = 116140,
    SPELL_CALL_DOG = 114259,
    SPELL_DEATH_BLOSSOM = 114242,
    SPELL_PIERCING_THROW = 114004
};

enum Events
{
    EVENT_BLOODY_RAGE = 1,
    EVENT_CALL_DOG,
    EVENT_DEATH_BLOSSOM,
    EVENT_PIERCING_THROW
};

class boss_houndmaster_braun : public CreatureScript
{
public:
    boss_houndmaster_braun() : CreatureScript("boss_houndmaster_braun") { }

    struct boss_houndmaster_braunAI : public BossAI
    {
        boss_houndmaster_braunAI(Creature* creature) : BossAI(creature, 59303)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);

            events.ScheduleEvent(EVENT_BLOODY_RAGE, 4000);
            events.ScheduleEvent(EVENT_CALL_DOG, 8000);
            events.ScheduleEvent(EVENT_DEATH_BLOSSOM, 12000);
            events.ScheduleEvent(EVENT_PIERCING_THROW, 16000);
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
                case EVENT_BLOODY_RAGE:
                    DoCast(me,SPELL_BLOODY_RAGE);
                    events.ScheduleEvent(EVENT_BLOODY_RAGE, 4000);
                    break;
                case EVENT_CALL_DOG:
                    DoCast(SPELL_CALL_DOG);
                    events.ScheduleEvent(EVENT_CALL_DOG, 8000);
                    break;
                case EVENT_DEATH_BLOSSOM:
                    DoCastAOE(SPELL_DEATH_BLOSSOM);
                    events.ScheduleEvent(EVENT_DEATH_BLOSSOM, 12000);
                    break;
                case EVENT_PIERCING_THROW:
                    if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target,SPELL_PIERCING_THROW);
                    events.ScheduleEvent(EVENT_PIERCING_THROW, 16000);
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
        return new boss_houndmaster_braunAI(creature);
    }
};

void AddSC_boss_houndmaster_braun()
{
    new boss_houndmaster_braun();
}
