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
#include "SpellScript.h"

enum NoxxionSpells
{
    SPELL_TOXIC_VOLLEY          = 21687,
    SPELL_UPPERCUT              = 22916,
    SPELL_SUMMON_SPAWNS_DUMMY   = 21708,
    SPELL_SUMMON_SPAWNS         = 21707
};

// 13282 - Noxxion
struct boss_noxxion : public ScriptedAI
{
    boss_noxxion(Creature* creature) : ScriptedAI(creature) { }

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
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_TOXIC_VOLLEY);
                task.Repeat(15s, 20s);
            })
            .Schedule(15s, 20s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_UPPERCUT);
                task.Repeat(20s, 30s);
            })
            .Schedule(30s, 40s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_SUMMON_SPAWNS_DUMMY);
                task.Repeat(50s, 60s);
            });
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

// 21708 - Summon Noxxion's Spawns
class spell_noxxion_summon_spawns : public AuraScript
{
    PrepareAuraScript(spell_noxxion_summon_spawns);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_SPAWNS });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
        {
            target->SetReactState(REACT_PASSIVE);
            target->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            target->CastSpell(target, SPELL_SUMMON_SPAWNS, true);
        }
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
        {
            target->SetReactState(REACT_AGGRESSIVE);
            target->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_noxxion_summon_spawns::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectApplyFn(spell_noxxion_summon_spawns::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_noxxion()
{
    RegisterMaraudonCreatureAI(boss_noxxion);
    RegisterSpellScript(spell_noxxion_summon_spawns);
}
