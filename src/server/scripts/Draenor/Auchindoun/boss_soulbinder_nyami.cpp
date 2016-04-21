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
    SPELL_MIND_SPIKE = 154415,
    SPELL_SHADOW_WORD_PAIN = 154477,
    SPELL_SOUL_VESSEL = 153477,
    SPELL_TORN_SPIRITS = 153994,
};

enum Events
{
    EVENT_MIND_SPIKE = 1,
    EVENT_SHADOW_WORD_PAIN,
    EVENT_SOUL_VESSEL,
    EVENT_TORN_SPIRITS,
};

class boss_soulbinder_nyami : public CreatureScript
{
public:
    boss_soulbinder_nyami() : CreatureScript("boss_soulbinder_nyami") { }

    struct boss_soulbinder_nyamiAI : public BossAI
    {
        boss_soulbinder_nyamiAI(Creature* creature) : BossAI(creature, 76177)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);

            events.ScheduleEvent(EVENT_MIND_SPIKE, 4000);
            events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000);
            events.ScheduleEvent(EVENT_SOUL_VESSEL, 12000);
            events.ScheduleEvent(EVENT_TORN_SPIRITS, 16000);
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
                case EVENT_MIND_SPIKE:
                    DoCastVictim(SPELL_MIND_SPIKE);
                    events.ScheduleEvent(EVENT_MIND_SPIKE, 4000);
                    break;
                case EVENT_SHADOW_WORD_PAIN:
                    DoCastVictim(SPELL_SHADOW_WORD_PAIN);
                    events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000);
                    break;
                case EVENT_SOUL_VESSEL:
                    DoCastAOE(SPELL_SOUL_VESSEL);
                    events.ScheduleEvent(EVENT_SOUL_VESSEL, 12000);
                    break;
                case EVENT_TORN_SPIRITS:
                    DoCast(SPELL_TORN_SPIRITS);
                    events.ScheduleEvent(EVENT_TORN_SPIRITS, 16000);
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
        return new boss_soulbinder_nyamiAI(creature);
    }
};

void AddSC_boss_soulbinder_nyami()
{
    new boss_soulbinder_nyami();
}
