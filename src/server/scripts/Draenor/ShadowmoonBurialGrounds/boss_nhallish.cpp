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
    SPELL_PLANAR_SHIFT = 153623,
    SPELL_SOUL_STEAL = 152962,
    SPELL_VOID_BLAST = 153501,
    SPELL_VOID_DEVASTATION = 153070,
    SPELL_VOID_VORTEX = 152801
};

enum Events
{
    EVENT_PLANAR_SHIFT = 1,
    EVENT_SOUL_STEAL,
    EVENT_VOID_BLAST,
    EVENT_VOID_DEVASTATION,
    EVENT_VOID_VORTEX
};

class boss_nhallish : public CreatureScript
{
public:
    boss_nhallish() : CreatureScript("boss_nhallish") { }

    struct boss_nhallishAI : public BossAI
    {
        boss_nhallishAI(Creature* creature) : BossAI(creature, 75829)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_PLANAR_SHIFT, 4000);
            events.ScheduleEvent(EVENT_SOUL_STEAL, 8000);
            events.ScheduleEvent(EVENT_VOID_BLAST, 12000);
            events.ScheduleEvent(EVENT_VOID_DEVASTATION, 16000);
            events.ScheduleEvent(EVENT_VOID_VORTEX, 20000);
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
                case EVENT_PLANAR_SHIFT:
                    DoCastAOE(SPELL_PLANAR_SHIFT);
                    events.ScheduleEvent(EVENT_PLANAR_SHIFT, 4000);
                    break;
                case EVENT_SOUL_STEAL:
                    DoCast(SPELL_SOUL_STEAL);
                    events.ScheduleEvent(EVENT_SOUL_STEAL, 8000);
                    break;
                case EVENT_VOID_BLAST:
                    DoCastAOE(SPELL_VOID_BLAST);
                    events.ScheduleEvent(EVENT_VOID_BLAST, 12000);
                    break;
                case EVENT_VOID_DEVASTATION:
                    DoCastAOE(SPELL_VOID_DEVASTATION);
                    events.ScheduleEvent(EVENT_VOID_DEVASTATION, 16000);
                    break;
                case EVENT_VOID_VORTEX:
                    DoCastAOE(SPELL_VOID_VORTEX);
                    events.ScheduleEvent(EVENT_VOID_VORTEX, 20000);
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
        return new boss_nhallishAI(creature);
    }
};

void AddSC_boss_nhallish()
{
    new boss_nhallish();
}
