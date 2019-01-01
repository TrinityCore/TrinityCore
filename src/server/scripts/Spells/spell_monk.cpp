/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

/*
 * Scripts for spells with SPELLFAMILY_MONK and SPELLFAMILY_GENERIC spells used by monk players.
 * Scriptnames of files in this file should be prefixed with "spell_monk_".
 */

#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Unit.h"

enum MonkSpells
{
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHANNEL         = 117952,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC        = 123333,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK       = 117962,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD    = 117953,
    SPELL_MONK_PROVOKE_SINGLE_TARGET                    = 116189,
    SPELL_MONK_PROVOKE_AOE                              = 118635,
    SPELL_MONK_SOOTHING_MIST                            = 115175,
    SPELL_MONK_STANCE_OF_THE_SPIRITED_CRANE             = 154436,
    SPELL_MONK_SURGING_MIST_HEAL                        = 116995,
};

// 117952 - Crackling Jade Lightning
class spell_monk_crackling_jade_lightning : public AuraScript
{
    PrepareAuraScript(spell_monk_crackling_jade_lightning);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_MONK_STANCE_OF_THE_SPIRITED_CRANE,
            SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC
        });
    }

    void OnTick(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            if (caster->HasAura(SPELL_MONK_STANCE_OF_THE_SPIRITED_CRANE))
                caster->CastSpell(caster, SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_crackling_jade_lightning::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 117959 - Crackling Jade Lightning
class spell_monk_crackling_jade_lightning_knockback_proc_aura : public AuraScript
{
    PrepareAuraScript(spell_monk_crackling_jade_lightning_knockback_proc_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK,
            SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD
        });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (GetTarget()->HasAura(SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD))
            return false;

        if (eventInfo.GetActor()->HasAura(SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHANNEL, GetTarget()->GetGUID()))
            return false;

        Spell* currentChanneledSpell = GetTarget()->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
        if (!currentChanneledSpell || currentChanneledSpell->GetSpellInfo()->Id != SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHANNEL)
            return false;

        return true;
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        GetTarget()->CastSpell(eventInfo.GetActor(), SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK, TRIGGERED_FULL_MASK);
        GetTarget()->CastSpell(GetTarget(), SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_monk_crackling_jade_lightning_knockback_proc_aura::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_monk_crackling_jade_lightning_knockback_proc_aura::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 115546 - Provoke
class spell_monk_provoke : public SpellScript
{
    PrepareSpellScript(spell_monk_provoke);

    static uint32 const BlackOxStatusEntry = 61146;

    bool Validate(SpellInfo const* spellInfo) override
    {
        if (!(spellInfo->GetExplicitTargetMask() & TARGET_FLAG_UNIT_MASK)) // ensure GetExplTargetUnit() will return something meaningful during CheckCast
            return false;
        return ValidateSpellInfo(
        {
            SPELL_MONK_PROVOKE_SINGLE_TARGET,
            SPELL_MONK_PROVOKE_AOE
        });
    }

    SpellCastResult CheckExplicitTarget()
    {
        if (GetExplTargetUnit()->GetEntry() != BlackOxStatusEntry)
        {
            SpellInfo const* singleTarget = sSpellMgr->AssertSpellInfo(SPELL_MONK_PROVOKE_SINGLE_TARGET);
            SpellCastResult singleTargetExplicitResult = singleTarget->CheckExplicitTarget(GetCaster(), GetExplTargetUnit());
            if (singleTargetExplicitResult != SPELL_CAST_OK)
                return singleTargetExplicitResult;
        }
        else if (GetExplTargetUnit()->GetOwnerGUID() != GetCaster()->GetGUID())
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (GetHitUnit()->GetEntry() != BlackOxStatusEntry)
            GetCaster()->CastSpell(GetHitUnit(), SPELL_MONK_PROVOKE_SINGLE_TARGET, true);
        else
            GetCaster()->CastSpell(GetHitUnit(), SPELL_MONK_PROVOKE_AOE, true);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_monk_provoke::CheckExplicitTarget);
        OnEffectHitTarget += SpellEffectFn(spell_monk_provoke::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_monk_spell_scripts()
{
    RegisterAuraScript(spell_monk_crackling_jade_lightning);
    RegisterAuraScript(spell_monk_crackling_jade_lightning_knockback_proc_aura);
    RegisterSpellScript(spell_monk_provoke);
}
