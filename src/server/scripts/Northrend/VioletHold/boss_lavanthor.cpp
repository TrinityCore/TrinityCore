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
#include "violet_hold.h"

enum Spells
{
    SPELL_CAUTERIZING_FLAMES                    = 59466, // Only in heroic
    SPELL_FIREBOLT                              = 54235,
    SPELL_FLAME_BREATH                          = 54282,
    SPELL_LAVA_BURN                             = 54249
};

class boss_lavanthor : public CreatureScript
{
    public:
        boss_lavanthor() : CreatureScript("boss_lavanthor") { }

        struct boss_lavanthorAI : public BossAI
        {
            boss_lavanthorAI(Creature* creature) : BossAI(creature, DATA_LAVANTHOR) { }

            void Reset() override
            {
                BossAI::Reset();
            }

            void EnterCombat(Unit* who) override
            {
                BossAI::EnterCombat(who);
            }

            void JustReachedHome() override
            {
                BossAI::JustReachedHome();
                instance->SetData(DATA_HANDLE_CELLS, DATA_LAVANTHOR);
            }

            void JustDied(Unit* killer) override
            {
                BossAI::JustDied(killer);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                scheduler.Update(diff,
                    std::bind(&BossAI::DoMeleeAttackIfReady, this));
            }

            void ScheduleTasks() override
            {
                scheduler.Schedule(Seconds(1), [this](TaskContext task)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                        DoCast(target, SPELL_FIREBOLT);
                    task.Repeat(Seconds(5), Seconds(13));
                });

                scheduler.Schedule(Seconds(5), [this](TaskContext task)
                {
                    DoCastVictim(SPELL_FLAME_BREATH);
                    task.Repeat(Seconds(10), Seconds(15));
                });

                scheduler.Schedule(Seconds(10), [this](TaskContext task)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f))
                        DoCast(target, SPELL_LAVA_BURN);
                    task.Repeat(Seconds(15), Seconds(23));
                });

                if (IsHeroic())
                {
                    scheduler.Schedule(Seconds(3), [this](TaskContext task)
                    {
                        DoCastAOE(SPELL_CAUTERIZING_FLAMES);
                        task.Repeat(Seconds(10), Seconds(16));
                    });
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<boss_lavanthorAI>(creature);
        }
};

void AddSC_boss_lavanthor()
{
    new boss_lavanthor();
}
