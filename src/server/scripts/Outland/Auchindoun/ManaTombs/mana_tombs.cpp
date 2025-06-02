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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "Unit.h"
#include "mana_tombs.h"

enum YorSpells
{
    SPELL_DOUBLE_BREATH          = 38361
};

// 22930 - Yor
struct npc_yor : public ScriptedAI
{
    npc_yor(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        _scheduler.Schedule(1500ms, [this](TaskContext /*task*/)
        {
            me->SetFaction(FACTION_MONSTER_2);
        });
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(6s, 14s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_DOUBLE_BREATH);
            task.Repeat(8s, 14s);
        });
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _scheduler.CancelAll();
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

enum SummonArcaneFiends
{
    SPELL_SUMMON_ARCANE_FIEND_1   = 32349,
    SPELL_SUMMON_ARCANE_FIEND_2   = 32353
};

// 32348 - Summon Arcane Fiends
class spell_mana_tombs_summon_arcane_fiends : public SpellScript
{
    PrepareSpellScript(spell_mana_tombs_summon_arcane_fiends);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_ARCANE_FIEND_1,
            SPELL_SUMMON_ARCANE_FIEND_2
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_SUMMON_ARCANE_FIEND_1);
        caster->CastSpell(caster, SPELL_SUMMON_ARCANE_FIEND_2);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_mana_tombs_summon_arcane_fiends::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_mana_tombs()
{
    RegisterManaTombsCreatureAI(npc_yor);
    RegisterSpellScript(spell_mana_tombs_summon_arcane_fiends);
}
