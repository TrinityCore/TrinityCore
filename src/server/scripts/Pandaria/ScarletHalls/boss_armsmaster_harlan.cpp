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
    SPELL_BERSEKER_RAGE = 111221,
    SPELL_BLADES_OF_LIGHT = 111216,
    SPELL_DRAGONS_REACH = 111217,
    SPELL_HEROIC_LEAP = 111218
};

enum Events
{
    EVENT_BERSEKER_RAGE = 1,
    EVENT_BLADES_OF_LIGHT,
    EVENT_DRAGONS_REACH,
    EVENT_HEROIC_LEAP
};

class boss_armsmaster_harlan : public CreatureScript
{
public:
    boss_armsmaster_harlan() : CreatureScript("boss_armsmaster_harlan") { }

    struct boss_armsmaster_harlanAI : public BossAI
    {
        boss_armsmaster_harlanAI(Creature* creature) : BossAI(creature, 58632)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);

            events.ScheduleEvent(EVENT_BERSEKER_RAGE, 4000);
            events.ScheduleEvent(EVENT_BLADES_OF_LIGHT, 8000);
            events.ScheduleEvent(EVENT_DRAGONS_REACH, 12000);
            events.ScheduleEvent(EVENT_HEROIC_LEAP, 16000);
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
                case EVENT_BERSEKER_RAGE:
                    DoCast(me,SPELL_BERSEKER_RAGE);
                    events.ScheduleEvent(EVENT_BERSEKER_RAGE, 4000);
                    break;
                case EVENT_BLADES_OF_LIGHT:
                    DoCastAOE(SPELL_BLADES_OF_LIGHT);
                    events.ScheduleEvent(EVENT_BLADES_OF_LIGHT, 8000);
                    break;
                case EVENT_DRAGONS_REACH:
                    DoCastAOE(SPELL_DRAGONS_REACH);
                    events.ScheduleEvent(EVENT_DRAGONS_REACH, 12000);
                    break;
                case EVENT_HEROIC_LEAP:
                    DoCastAOE(SPELL_HEROIC_LEAP);
                    events.ScheduleEvent(EVENT_HEROIC_LEAP, 16000);
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
        return new boss_armsmaster_harlanAI(creature);
    }
};

void AddSC_boss_armsmaster_harlan()
{
    new boss_armsmaster_harlan();
}
