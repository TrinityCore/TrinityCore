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
    SPELL_GRASPING_VINE = 168375,
    SPELL_NOXIOUS_ERUPTION = 175997,
    SPELL_RENDING_CHARGE = 168187,
    SPELL_SLASH = 168383
};

enum Events
{
    EVENT_GRASPING_VINE = 1,
    EVENT_NOXIOUS_ERUPTION,
    EVENT_RENDING_CHARGE,
    EVENT_SLASH
};

class boss_dulhu : public CreatureScript
{
public:
    boss_dulhu() : CreatureScript("boss_dulhu") { }

    struct boss_dulhuAI : public BossAI
    {
        boss_dulhuAI(Creature* creature) : BossAI(creature, 83894)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_GRASPING_VINE, 4000);
            events.ScheduleEvent(EVENT_NOXIOUS_ERUPTION, 8000);
            events.ScheduleEvent(EVENT_RENDING_CHARGE, 12000);
            events.ScheduleEvent(EVENT_SLASH, 16000);
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
                case EVENT_GRASPING_VINE:
                    if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target,SPELL_GRASPING_VINE);
                    events.ScheduleEvent(EVENT_GRASPING_VINE, 4000);
                    break;
                case EVENT_NOXIOUS_ERUPTION:
                    DoCastAOE(SPELL_NOXIOUS_ERUPTION);
                    events.ScheduleEvent(EVENT_NOXIOUS_ERUPTION, 8000);
                    break;
                case EVENT_RENDING_CHARGE:
                    if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target,SPELL_RENDING_CHARGE);
                    events.ScheduleEvent(EVENT_RENDING_CHARGE, 12000);
                    break;
                case EVENT_SLASH:
                    DoCastAOE(SPELL_SLASH);
                    events.ScheduleEvent(EVENT_SLASH, 16000);
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
        return new boss_dulhuAI(creature);
    }
};

void AddSC_boss_dulhu()
{
    new boss_dulhu();
}
