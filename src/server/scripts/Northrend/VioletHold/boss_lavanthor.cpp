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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "violet_hold.h"

enum Spells
{
    SPELL_CAUTERIZING_FLAMES                    = 59466, // Only in heroic
    SPELL_FIREBOLT                              = 54235,
    SPELL_FLAME_BREATH                          = 54282,
    SPELL_LAVA_BURN                             = 54249
};

struct boss_lavanthor : public BossAI
{
    boss_lavanthor(Creature* creature) : BossAI(creature, DATA_LAVANTHOR) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
    }

    void JustReachedHome() override
    {
        BossAI::JustReachedHome();
        instance->SetData(DATA_HANDLE_CELLS, DATA_LAVANTHOR);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        scheduler.Update(diff);
    }

    void ScheduleTasks() override
    {
        scheduler.Schedule(Seconds(1), [this](TaskContext task)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, true))
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
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 50.0f))
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

void AddSC_boss_lavanthor()
{
    RegisterVioletHoldCreatureAI(boss_lavanthor);
}
