/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "zulgurub.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_MANABURN = 26046,
    SPELL_SLEEP = 24664
};

enum Events
{
    EVENT_MANABURN = 1,
    EVENT_SLEEP = 2,
    EVENT_ILLUSIONS = 3
};

class boss_hazzarah : public CreatureScript
{
    public:
        boss_hazzarah() : CreatureScript("boss_hazzarah") { }

        struct boss_hazzarahAI : public BossAI
        {
            boss_hazzarahAI(Creature* creature) : BossAI(creature, DATA_EDGE_OF_MADNESS) { }

            void Reset() override
            {
                _Reset();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                events.ScheduleEvent(EVENT_MANABURN, 4s, 10s);
                events.ScheduleEvent(EVENT_SLEEP, 10s, 18s);
                events.ScheduleEvent(EVENT_ILLUSIONS, 10s, 18s);
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
                        case EVENT_MANABURN:
                            DoCastVictim(SPELL_MANABURN, true);
                            events.ScheduleEvent(EVENT_MANABURN, 8s, 16s);
                            break;
                        case EVENT_SLEEP:
                            DoCastVictim(SPELL_SLEEP, true);
                            events.ScheduleEvent(EVENT_SLEEP, 12s, 20s);
                            break;
                        case EVENT_ILLUSIONS:
                            // We will summon 3 illusions that will spawn on a random gamer and attack this gamer
                            // We will just use one model for the beginning
                            for (uint8 i = 0; i < 3; ++i)
                            {
                                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.f, true))
                                    if (TempSummon* illusion = me->SummonCreature(NPC_NIGHTMARE_ILLUSION, target->GetPosition(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30s))
                                        illusion->AI()->AttackStart(target);
                            }
                            events.ScheduleEvent(EVENT_ILLUSIONS, 15s, 25s);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<boss_hazzarahAI>(creature);
        }
};

void AddSC_boss_hazzarah()
{
    new boss_hazzarah();
}
