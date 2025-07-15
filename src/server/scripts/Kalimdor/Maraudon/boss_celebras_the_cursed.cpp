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
#include "maraudon.h"
#include "ScriptedCreature.h"

enum CelebrasSpells
{
    SPELL_WRATH                 = 21807,
    SPELL_ENTANGLING_ROOTS      = 12747,
    SPELL_CORRUPT_FORCES        = 21968
};

enum CelebrasMisc
{
    NPC_CELEBRAS_THE_REDEEMED   = 13716
};

// 12225 - Celebras the Cursed
struct boss_celebras_the_cursed : public ScriptedAI
{
    boss_celebras_the_cursed(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler
            .SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            })
            .Schedule(0s, 6s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_WRATH);
                task.Repeat(4s, 8s);
            })
            .Schedule(0s, 5s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_ENTANGLING_ROOTS);
                task.Repeat(20s);
            })
            .Schedule(30s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_CORRUPT_FORCES);
                task.Repeat(20s);
            });
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->SummonCreature(NPC_CELEBRAS_THE_REDEEMED, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    TaskScheduler _scheduler;
};

void AddSC_boss_celebras_the_cursed()
{
    RegisterMaraudonCreatureAI(boss_celebras_the_cursed);
}
