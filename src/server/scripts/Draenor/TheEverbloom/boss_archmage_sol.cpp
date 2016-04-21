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
    SPELL_ARCANE_BURST = 166466,
    SPELL_FIREBALL = 166464,
    SPELL_FIREBLOOM = 166492,
    SPELL_FROSTBOLT = 166465,
    SPELL_FROZEN_RAIN = 166726,
    SPELL_PARASITIC_GROWTH = 168885,
    SPELL_PARASITIC_INJECTION = 166891,
    SPELL_PRIMAL_AFFINITY_ARCANE = 166477,
    SPELL_PRIMAL_AFFINITY_FIRE = 166475,
    SPELL_PRIMAL_AFFINITY_FROST = 166476,
    SPELL_THOUGHT_CHRYSALIS = 166474
};

enum Events
{
    EVENT_ARCANE_BURST = 1,
    EVENT_FIREBALL,
    EVENT_FIREBLOOM,
    EVENT_FROSTBOLT,
    EVENT_FROZEN_RAIN,
    EVENT_PARASITIC_GROWTH,
    EVENT_PARASITIC_INJECTION,
    EVENT_PRIMAL_AFFINITY_ARCANE,
    EVENT_PRIMAL_AFFINITY_FIRE,
    EVENT_PRIMAL_AFFINITY_FROST,
    EVENT_THOUGHT_CHRYSALIS
};

class boss_archmage_sol : public CreatureScript
{
public:
    boss_archmage_sol() : CreatureScript("boss_archmage_sol") { }

    struct boss_archmage_solAI : public BossAI
    {
        boss_archmage_solAI(Creature* creature) : BossAI(creature, 82682)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_ARCANE_BURST, 4000);
            events.ScheduleEvent(EVENT_FIREBALL, 8000);
            events.ScheduleEvent(EVENT_FIREBLOOM, 12000);
            events.ScheduleEvent(EVENT_FROSTBOLT, 16000);
            events.ScheduleEvent(EVENT_FROZEN_RAIN, 20000);
            events.ScheduleEvent(EVENT_PARASITIC_GROWTH, 4000);
            events.ScheduleEvent(EVENT_PARASITIC_INJECTION, 8000);
            events.ScheduleEvent(EVENT_PRIMAL_AFFINITY_ARCANE, 12000);
            events.ScheduleEvent(EVENT_PRIMAL_AFFINITY_FIRE, 16000);
            events.ScheduleEvent(EVENT_PRIMAL_AFFINITY_FROST, 20000);
            events.ScheduleEvent(EVENT_THOUGHT_CHRYSALIS, 4000);
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
                case EVENT_ARCANE_BURST:
                    DoCastVictim(SPELL_ARCANE_BURST);
                    events.ScheduleEvent(EVENT_ARCANE_BURST, 4000);
                    break;
                case EVENT_FIREBALL:
                    DoCast(SPELL_FIREBALL);
                    events.ScheduleEvent(EVENT_FIREBALL, 8000);
                    break;
                case EVENT_FIREBLOOM:
                    DoCast(SPELL_FIREBLOOM);
                    events.ScheduleEvent(EVENT_FIREBLOOM, 12000);
                    break;
                case EVENT_FROSTBOLT:
                    DoCastVictim(SPELL_FROSTBOLT);
                    events.ScheduleEvent(EVENT_FROSTBOLT, 16000);
                    break;
                case EVENT_FROZEN_RAIN:
                    DoCastAOE(SPELL_FROZEN_RAIN);
                    events.ScheduleEvent(EVENT_FROZEN_RAIN, 20000);
                    break;
                case EVENT_PARASITIC_GROWTH:
                    DoCast(me,SPELL_PARASITIC_GROWTH);
                    events.ScheduleEvent(EVENT_PARASITIC_GROWTH, 4000);
                    break;
                case EVENT_PARASITIC_INJECTION:
                    DoCast(me,SPELL_PARASITIC_INJECTION);
                    events.ScheduleEvent(EVENT_PARASITIC_INJECTION, 8000);
                    break;
                case EVENT_PRIMAL_AFFINITY_ARCANE:
                    DoCast(me,SPELL_PRIMAL_AFFINITY_ARCANE);
                    events.ScheduleEvent(EVENT_PRIMAL_AFFINITY_ARCANE, 12000);
                    break;
                case EVENT_PRIMAL_AFFINITY_FIRE:
                    DoCast(me,SPELL_PRIMAL_AFFINITY_FIRE);
                    events.ScheduleEvent(EVENT_PRIMAL_AFFINITY_FIRE, 16000);
                    break;
                case EVENT_PRIMAL_AFFINITY_FROST:
                    DoCast(me,SPELL_PRIMAL_AFFINITY_FROST);
                    events.ScheduleEvent(EVENT_PRIMAL_AFFINITY_FROST, 20000);
                    break;
                case EVENT_THOUGHT_CHRYSALIS:
                    DoCast(me,SPELL_THOUGHT_CHRYSALIS);
                    events.ScheduleEvent(EVENT_THOUGHT_CHRYSALIS, 4000);
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
        return new boss_archmage_solAI(creature);
    }
};

void AddSC_boss_archmage_sol()
{
    new boss_archmage_sol();
}
