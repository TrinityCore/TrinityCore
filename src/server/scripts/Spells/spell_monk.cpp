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

/*
 * Scripts for spells with SPELLFAMILY_MONK and SPELLFAMILY_GENERIC spells used by monk players.
 * Scriptnames of files in this file should be prefixed with "spell_monk_".
 */

#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
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
    SPELL_MONK_RENEWING_MIST                            = 115151,
    SPELL_MONK_RENEWING_MIST_PERIODIC_HEAL              = 119611,
    SPELL_MONK_RENEWING_MIST_TARGET_SELECT              = 119607,
    SPELL_MONK_RENEWING_MIST_DUMMY_VISUAL               = 119647,
    SPELL_MONK_STANCE_OF_THE_SPIRITED_CRANE             = 154436
};

// 117952 - Crackling Jade Lightning
class spell_monk_crackling_jade_lightning : public SpellScriptLoader
{
public:
    spell_monk_crackling_jade_lightning() : SpellScriptLoader("spell_monk_crackling_jade_lightning") { }

    class spell_monk_crackling_jade_lightning_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_crackling_jade_lightning_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC))
                return false;
            return true;
        }

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->HasAura(SPELL_MONK_STANCE_OF_THE_SPIRITED_CRANE))
                    caster->CastSpell(caster, SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_crackling_jade_lightning_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_monk_crackling_jade_lightning_AuraScript();
    }
};

// 117959 - Crackling Jade Lightning
class spell_monk_crackling_jade_lightning_knockback_proc_aura : public SpellScriptLoader
{
public:
    spell_monk_crackling_jade_lightning_knockback_proc_aura() : SpellScriptLoader("spell_monk_crackling_jade_lightning_knockback_proc_aura") { }

    class spell_monk_crackling_jade_lightning_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_crackling_jade_lightning_aura_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD))
                return false;
            return true;
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (GetTarget()->HasAura(SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD))
                return false;

            if (eventInfo.GetActor()->GetGUID() != GetTarget()->GetChannelObjectGuid())
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
            DoCheckProc += AuraCheckProcFn(spell_monk_crackling_jade_lightning_aura_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_monk_crackling_jade_lightning_aura_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_monk_crackling_jade_lightning_aura_AuraScript();
    }
};

// 115546 - Provoke
class spell_monk_provoke : public SpellScriptLoader
{
public:
    spell_monk_provoke() : SpellScriptLoader("spell_monk_provoke") { }

    class spell_monk_provoke_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_provoke_SpellScript);

        static uint32 const BlackOxStatusEntry = 61146;

        bool Validate(SpellInfo const* spellInfo) override
        {
            if (!(spellInfo->GetExplicitTargetMask() & TARGET_FLAG_UNIT_MASK)) // ensure GetExplTargetUnit() will return something meaningful during CheckCast
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_PROVOKE_SINGLE_TARGET))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_PROVOKE_AOE))
                return false;
            return true;
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
            OnCheckCast += SpellCheckCastFn(spell_monk_provoke_SpellScript::CheckExplicitTarget);
            OnEffectHitTarget += SpellEffectFn(spell_monk_provoke_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_monk_provoke_SpellScript();
    }
};

// 115151 - Renewing Mist
class spell_monk_renewing_mist : public SpellScriptLoader
{
    public:
        spell_monk_renewing_mist() : SpellScriptLoader("spell_monk_renewing_mist") { }

        class spell_monk_renewing_mist_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_renewing_mist_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_PERIODIC_HEAL))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_TARGET_SELECT))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_DUMMY_VISUAL))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_MONK_RENEWING_MIST_PERIODIC_HEAL, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_renewing_mist_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_monk_renewing_mist_SpellScript();
        }
};

// 119611 - Renewing Mist Periodic Heal
class spell_monk_renewing_mist_periodic_heal : public SpellScriptLoader
{
    public:
        spell_monk_renewing_mist_periodic_heal() : SpellScriptLoader("spell_monk_renewing_mist_periodic_heal") { }

        class spell_monk_renewing_mist_periodic_heal_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_renewing_mist_periodic_heal_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_PERIODIC_HEAL))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_TARGET_SELECT))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_DUMMY_VISUAL))
                    return false;
                return true;
            }

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                if (aurEff->GetBase()->GetCharges() > 1)
                    if (Unit* originCaster = GetCaster())
                        originCaster->CastSpell(GetTarget(), SPELL_MONK_RENEWING_MIST_TARGET_SELECT, true);
            }

            void HandleDummy(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                aurEff->GetBase()->SetCharges(aurEff->GetAmount());
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_renewing_mist_periodic_heal_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
                OnEffectApply += AuraEffectApplyFn(spell_monk_renewing_mist_periodic_heal_AuraScript::HandleDummy, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_monk_renewing_mist_periodic_heal_AuraScript();
        }
};

// 119607 - Renewing Mist Target Selection
class spell_monk_renewing_mist_target_selector : public SpellScriptLoader
{
    public:
        spell_monk_renewing_mist_target_selector() : SpellScriptLoader("spell_monk_renewing_mist_target_selector") { }

        class spell_monk_renewing_mist_target_selector_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_renewing_mist_target_selector_SpellScript);

        public:
            spell_monk_renewing_mist_target_selector_SpellScript() { }

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_PERIODIC_HEAL))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_TARGET_SELECT))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_DUMMY_VISUAL))
                    return false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove(GetExplTargetWorldObject());
                if (targets.empty())
                    return;
                targets.sort(Trinity::HealthPctOrderPred());
                targets.resize(1);
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Unit* target = GetHitUnit())
                    if (Aura* aura = GetExplTargetUnit()->GetAura(SPELL_MONK_RENEWING_MIST_PERIODIC_HEAL, GetCaster()->GetGUID()))
                        if (AuraEffect* effect = aura->GetEffect(EFFECT_1))
                        {
                            GetExplTargetUnit()->CastSpell(target, SPELL_MONK_RENEWING_MIST_DUMMY_VISUAL, true);
                            aura->SetCharges(0);
                            int32 bp1 = std::max(0, effect->GetAmount() - 1);
                            GetExplTargetUnit()->CastCustomSpell(SPELL_MONK_RENEWING_MIST_PERIODIC_HEAL, SPELLVALUE_BASE_POINT1, bp1, target, true, 0, effect, GetCaster()->GetGUID());
                        }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_renewing_mist_target_selector_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
                OnEffectHitTarget += SpellEffectFn(spell_monk_renewing_mist_target_selector_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_monk_renewing_mist_target_selector_SpellScript();
        }
};

void AddSC_monk_spell_scripts()
{
    new spell_monk_crackling_jade_lightning();
    new spell_monk_crackling_jade_lightning_knockback_proc_aura();
    new spell_monk_provoke();
    new spell_monk_renewing_mist();
    new spell_monk_renewing_mist_periodic_heal();
    new spell_monk_renewing_mist_target_selector();
}
