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

enum TheradrasSpells
{
    SPELL_DUST_FIELD            = 21909,
    SPELL_BOULDER               = 21832,
    SPELL_THRASH                = 3391,
    SPELL_REPULSIVE_GAZE        = 21869
};

enum TheradrasMisc
{
    NPC_ZAETARS_SPIRIT          = 12238
};

// 12201 - Princess Theradras
struct boss_princess_theradras : public ScriptedAI
{
    boss_princess_theradras(Creature* creature) : ScriptedAI(creature) { }

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
            .Schedule(20s, 25s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_DUST_FIELD);
                task.Repeat(20s, 25s);
            })
            .Schedule(20s, 30s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_BOULDER);
                task.Repeat(15s, 25s);
            })
            .Schedule(10s, 20s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_THRASH);
                task.Repeat(10s, 20s);
            })
            .Schedule(25s, 35s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_REPULSIVE_GAZE);
                task.Repeat(30s, 40s);
            });
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->SummonCreature(NPC_ZAETARS_SPIRIT, 28.1887f, 62.3964f, -123.161f, 4.31096f, TEMPSUMMON_MANUAL_DESPAWN);
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

void AddSC_boss_ptheradras()
{
    RegisterMaraudonCreatureAI(boss_princess_theradras);
}
