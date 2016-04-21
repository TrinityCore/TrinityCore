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
    SPELL_FAN_OF_BLADES = 153757,
    SPELL_FOUR_WINDS = 156793,
    SPELL_PIERCING_RUSH = 165733,
    SPELL_WINDWALL = 153315,
};

enum Events
{
    EVENT_FAN_OF_BLADES = 1,
    EVENT_FOUR_WINDS,
    EVENT_PIERCING_RUSH,
    EVENT_WINDWALL,
};

class boss_ranjit : public CreatureScript
{
public:
    boss_ranjit() : CreatureScript("boss_ranjit") { }

    struct boss_ranjitAI : public BossAI
    {
        boss_ranjitAI(Creature* creature) : BossAI(creature, 75964)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_FAN_OF_BLADES, 4000);
            events.ScheduleEvent(EVENT_FOUR_WINDS, 8000);
            events.ScheduleEvent(EVENT_PIERCING_RUSH, 12000);
            events.ScheduleEvent(EVENT_WINDWALL, 16000);
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
                case EVENT_FAN_OF_BLADES:
                    DoCastAOE(SPELL_FAN_OF_BLADES);
                    events.ScheduleEvent(EVENT_FAN_OF_BLADES, 4000);
                    break;
                case EVENT_FOUR_WINDS:
                    DoCastAOE(SPELL_FOUR_WINDS);
                    events.ScheduleEvent(EVENT_FOUR_WINDS, 8000);
                    break;
                case EVENT_PIERCING_RUSH:
                    DoCastVictim(SPELL_PIERCING_RUSH);
                    events.ScheduleEvent(EVENT_PIERCING_RUSH, 12000);
                    break;
                case EVENT_WINDWALL:
                    DoCastAOE(SPELL_WINDWALL);
                    events.ScheduleEvent(EVENT_WINDWALL, 16000);
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
        return new boss_ranjitAI(creature);
    }
};

void AddSC_boss_ranjit()
{
    new boss_ranjit();
}
