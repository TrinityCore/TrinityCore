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

/*
 * Scripts for spells with SPELLFAMILY_DRUID and SPELLFAMILY_GENERIC spells used by druid players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dru_".
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "Map.h"
#include "Player.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum DruidSpells
{
    SPELL_DRUID_BLESSING_OF_THE_CLAW        = 28750,
    SPELL_DRUID_BLESSING_OF_REMULOS         = 40445,
    SPELL_DRUID_BLESSING_OF_ELUNE           = 40446,
    SPELL_DRUID_BLESSING_OF_CENARIUS        = 40452,
    SPELL_DRUID_EXHILARATE                  = 28742,
    SPELL_DRUID_FERAL_CHARGE_BEAR           = 16979,
    SPELL_DRUID_FERAL_CHARGE_CAT            = 49376,
    SPELL_DRUID_FORM_AQUATIC                = 1066,
    SPELL_DRUID_FORM_FLIGHT                 = 33943,
    SPELL_DRUID_FORM_STAG                   = 165961,
    SPELL_DRUID_FORM_SWIFT_FLIGHT           = 40120,
    SPELL_DRUID_FORMS_TRINKET_BEAR          = 37340,
    SPELL_DRUID_FORMS_TRINKET_CAT           = 37341,
    SPELL_DRUID_FORMS_TRINKET_MOONKIN       = 37343,
    SPELL_DRUID_FORMS_TRINKET_NONE          = 37344,
    SPELL_DRUID_FORMS_TRINKET_TREE          = 37342,
    SPELL_DRUID_IDOL_OF_FERAL_SHADOWS       = 34241,
    SPELL_DRUID_IDOL_OF_WORSHIP             = 60774,
    SPELL_DRUID_INFUSION                    = 37238,
    SPELL_DRUID_LANGUISH                    = 71023,
    SPELL_DRUID_LIFEBLOOM_ENERGIZE          = 64372,
    SPELL_DRUID_LIFEBLOOM_FINAL_HEAL        = 33778,
    SPELL_DRUID_LIVING_SEED_HEAL            = 48503,
    SPELL_DRUID_LIVING_SEED_PROC            = 48504,
    SPELL_DRUID_MOONFIRE_DAMAGE             = 164812,
    SPELL_DRUID_SAVAGE_ROAR                 = 62071,
    SPELL_DRUID_STAMPEDE_BAER_RANK_1        = 81016,
    SPELL_DRUID_STAMPEDE_CAT_RANK_1         = 81021,
    SPELL_DRUID_STAMPEDE_CAT_STATE          = 109881,
    SPELL_DRUID_TRAVEL_FORM                 = 783,
    SPELL_DRUID_REJUVENATION_T10_PROC       = 70691,
    SPELL_DRUID_BALANCE_T10_BONUS           = 70718,
    SPELL_DRUID_BALANCE_T10_BONUS_PROC      = 70721,
    SPELL_DRUID_RESTORATION_T10_2P_BONUS    = 70658,
    SPELL_DRUID_SUNFIRE_DAMAGE              = 164815,
    SPELL_DRUID_SURVIVAL_INSTINCTS          = 50322
};

// 1850 - Dash
class spell_dru_dash : public SpellScriptLoader
{
public:
    spell_dru_dash() : SpellScriptLoader("spell_dru_dash") { }

    class spell_dru_dash_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_dash_AuraScript);

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            // do not set speed if not in cat form
            if (GetUnitOwner()->GetShapeshiftForm() != FORM_CAT_FORM)
                amount = 0;
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_dash_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_INCREASE_SPEED);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_dash_AuraScript();
    }
};

// -33943 - Flight Form
class spell_dru_flight_form : public SpellScriptLoader
{
public:
    spell_dru_flight_form() : SpellScriptLoader("spell_dru_flight_form") { }

    class spell_dru_flight_form_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_flight_form_SpellScript);

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            if (caster->IsInDisallowedMountForm())
                return SPELL_FAILED_NOT_SHAPESHIFT;

            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_dru_flight_form_SpellScript::CheckCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_flight_form_SpellScript();
    }
};

// 37336 - Druid Forms Trinket
class spell_dru_forms_trinket : public SpellScriptLoader
{
public:
    spell_dru_forms_trinket() : SpellScriptLoader("spell_dru_forms_trinket") { }

    class spell_dru_forms_trinket_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_forms_trinket_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_DRUID_FORMS_TRINKET_BEAR,
                SPELL_DRUID_FORMS_TRINKET_CAT,
                SPELL_DRUID_FORMS_TRINKET_MOONKIN,
                SPELL_DRUID_FORMS_TRINKET_NONE,
                SPELL_DRUID_FORMS_TRINKET_TREE
            });
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            Unit* target = eventInfo.GetActor();

            switch (target->GetShapeshiftForm())
            {
                case FORM_BEAR_FORM:
                case FORM_DIRE_BEAR_FORM:
                case FORM_CAT_FORM:
                case FORM_MOONKIN_FORM:
                case FORM_NONE:
                case FORM_TREE_OF_LIFE:
                    return true;
                default:
                    break;
            }

            return false;
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            Unit* target = eventInfo.GetActor();
            uint32 triggerspell = 0;

            switch (target->GetShapeshiftForm())
            {
                case FORM_BEAR_FORM:
                case FORM_DIRE_BEAR_FORM:
                    triggerspell = SPELL_DRUID_FORMS_TRINKET_BEAR;
                    break;
                case FORM_CAT_FORM:
                    triggerspell = SPELL_DRUID_FORMS_TRINKET_CAT;
                    break;
                case FORM_MOONKIN_FORM:
                    triggerspell = SPELL_DRUID_FORMS_TRINKET_MOONKIN;
                    break;
                case FORM_NONE:
                    triggerspell = SPELL_DRUID_FORMS_TRINKET_NONE;
                    break;
                case FORM_TREE_OF_LIFE:
                    triggerspell = SPELL_DRUID_FORMS_TRINKET_TREE;
                    break;
                default:
                    return;
            }

            target->CastSpell(target, triggerspell, true, nullptr, aurEff);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dru_forms_trinket_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dru_forms_trinket_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_forms_trinket_AuraScript();
    }
};

// 34246 - Idol of the Emerald Queen
// 60779 - Idol of Lush Moss
class spell_dru_idol_lifebloom : public SpellScriptLoader
{
public:
    spell_dru_idol_lifebloom() : SpellScriptLoader("spell_dru_idol_lifebloom") { }

    class spell_dru_idol_lifebloom_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_idol_lifebloom_AuraScript);

        void HandleEffectCalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)
        {
            if (!spellMod)
            {
                spellMod = new SpellModifier(GetAura());
                spellMod->op = SPELLMOD_DOT;
                spellMod->type = SPELLMOD_FLAT;
                spellMod->spellId = GetId();
                spellMod->mask = GetSpellInfo()->GetEffect(aurEff->GetEffIndex())->SpellClassMask;
            }
            spellMod->value = aurEff->GetAmount() / 7;
        }

        void Register() override
        {
            DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_dru_idol_lifebloom_AuraScript::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_idol_lifebloom_AuraScript();
    }
};

// 29166 - Innervate
class spell_dru_innervate : public SpellScriptLoader
{
public:
    spell_dru_innervate() : SpellScriptLoader("spell_dru_innervate") { }

    class spell_dru_innervate_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_innervate_AuraScript);

        void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
        {
            if (Unit* caster = GetCaster())
                amount = int32(CalculatePct(caster->GetCreatePowers(POWER_MANA), amount) / aurEff->GetTotalTicks());
            else
                amount = 0;
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_innervate_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_innervate_AuraScript();
    }
};

// 33763 - Lifebloom
class spell_dru_lifebloom : public SpellScriptLoader
{
public:
    spell_dru_lifebloom() : SpellScriptLoader("spell_dru_lifebloom") { }

    class spell_dru_lifebloom_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_lifebloom_AuraScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            return ValidateSpellInfo({ SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, SPELL_DRUID_LIFEBLOOM_ENERGIZE });
        }

        void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            // Final heal only on duration end
            if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                return;

            // final heal
            int32 stack = GetStackAmount();
            int32 healAmount = aurEff->GetAmount();
            if (Unit* caster = GetCaster())
            {
                healAmount = caster->SpellHealingBonusDone(GetTarget(), GetSpellInfo(), healAmount, HEAL, aurEff->GetSpellEffectInfo(), stack);
                healAmount = GetTarget()->SpellHealingBonusTaken(caster, GetSpellInfo(), healAmount, HEAL, aurEff->GetSpellEffectInfo(), stack);

                GetTarget()->CastCustomSpell(GetTarget(), SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, &healAmount, nullptr, nullptr, true, nullptr, aurEff, GetCasterGUID());

                // restore mana
                std::vector<SpellPowerCost> costs = GetSpellInfo()->CalcPowerCost(caster, GetSpellInfo()->GetSchoolMask());
                auto m = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_MANA; });
                if (m != costs.end())
                {
                    int32 returnMana = m->Amount * stack / 2;
                    caster->CastCustomSpell(caster, SPELL_DRUID_LIFEBLOOM_ENERGIZE, &returnMana, nullptr, nullptr, true, nullptr, aurEff, GetCasterGUID());
                }
                return;
            }

            GetTarget()->CastCustomSpell(GetTarget(), SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, &healAmount, nullptr, nullptr, true, nullptr, aurEff, GetCasterGUID());
        }

        void HandleDispel(DispelInfo* dispelInfo)
        {
            if (Unit* target = GetUnitOwner())
            {
                if (AuraEffect const* aurEff = GetEffect(EFFECT_1))
                {
                    // final heal
                    int32 healAmount = aurEff->GetAmount();
                    if (Unit* caster = GetCaster())
                    {
                        healAmount = caster->SpellHealingBonusDone(target, GetSpellInfo(), healAmount, HEAL, aurEff->GetSpellEffectInfo(), dispelInfo->GetRemovedCharges());
                        healAmount = target->SpellHealingBonusTaken(caster, GetSpellInfo(), healAmount, HEAL, aurEff->GetSpellEffectInfo(), dispelInfo->GetRemovedCharges());
                        target->CastCustomSpell(target, SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, &healAmount, nullptr, nullptr, true, nullptr, nullptr, GetCasterGUID());

                        // restore mana
                        std::vector<SpellPowerCost> costs = GetSpellInfo()->CalcPowerCost(caster, GetSpellInfo()->GetSchoolMask());
                        auto m = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_MANA; });
                        if (m != costs.end())
                        {
                            int32 returnMana = m->Amount * dispelInfo->GetRemovedCharges() / 2;
                            caster->CastCustomSpell(caster, SPELL_DRUID_LIFEBLOOM_ENERGIZE, &returnMana, nullptr, nullptr, true, nullptr, nullptr, GetCasterGUID());
                        }
                        return;
                    }

                    target->CastCustomSpell(target, SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, &healAmount, nullptr, nullptr, true, nullptr, nullptr, GetCasterGUID());
                }
            }
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_dru_lifebloom_AuraScript::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            AfterDispel += AuraDispelFn(spell_dru_lifebloom_AuraScript::HandleDispel);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_lifebloom_AuraScript();
    }
};

// -48496 - Living Seed
class spell_dru_living_seed : public SpellScriptLoader
{
public:
    spell_dru_living_seed() : SpellScriptLoader("spell_dru_living_seed") { }

    class spell_dru_living_seed_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_living_seed_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_DRUID_LIVING_SEED_PROC });
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            int32 amount = CalculatePct(eventInfo.GetHealInfo()->GetHeal(), aurEff->GetAmount());
            GetTarget()->CastCustomSpell(SPELL_DRUID_LIVING_SEED_PROC, SPELLVALUE_BASE_POINT0, amount, eventInfo.GetProcTarget(), true, nullptr, aurEff);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_dru_living_seed_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_living_seed_AuraScript();
    }
};

// 48504 - Living Seed (Proc)
class spell_dru_living_seed_proc : public SpellScriptLoader
{
public:
    spell_dru_living_seed_proc() : SpellScriptLoader("spell_dru_living_seed_proc") { }

    class spell_dru_living_seed_proc_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_living_seed_proc_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_DRUID_LIVING_SEED_HEAL });
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();
            GetTarget()->CastCustomSpell(SPELL_DRUID_LIVING_SEED_HEAL, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetTarget(), true, nullptr, aurEff);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_dru_living_seed_proc_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_living_seed_proc_AuraScript();
    }
};

//  8921 - Moonfire
class spell_dru_moonfire : public SpellScriptLoader
{
public:
    spell_dru_moonfire() : SpellScriptLoader("spell_dru_moonfire") { }

    class spell_dru_moonfire_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_moonfire_SpellScript);

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_DRUID_MOONFIRE_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dru_moonfire_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_moonfire_SpellScript();
    }
};

// -16972 - Predatory Strikes
class spell_dru_predatory_strikes : public SpellScriptLoader
{
public:
    spell_dru_predatory_strikes() : SpellScriptLoader("spell_dru_predatory_strikes") { }

    class spell_dru_predatory_strikes_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_predatory_strikes_AuraScript);

        void UpdateAmount(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Player* target = GetTarget()->ToPlayer())
                target->UpdateAttackPowerAndDamage();
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_dru_predatory_strikes_AuraScript::UpdateAmount, EFFECT_ALL, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
            AfterEffectRemove += AuraEffectRemoveFn(spell_dru_predatory_strikes_AuraScript::UpdateAmount, EFFECT_ALL, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_predatory_strikes_AuraScript();
    }
};

// 1079 - Rip
class spell_dru_rip : public SpellScriptLoader
{
public:
    spell_dru_rip() : SpellScriptLoader("spell_dru_rip") { }

    class spell_dru_rip_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_rip_AuraScript);

        bool Load() override
        {
            Unit* caster = GetCaster();
            return caster && caster->GetTypeId() == TYPEID_PLAYER;
        }

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
        {
            canBeRecalculated = false;

            if (Unit* caster = GetCaster())
            {
                // 0.01 * $AP * cp
                uint32 cp = caster->ToPlayer()->GetComboPoints();

                // Idol of Feral Shadows. Can't be handled as SpellMod due its dependency from CPs
                if (AuraEffect const* auraEffIdolOfFeralShadows = caster->GetAuraEffect(SPELL_DRUID_IDOL_OF_FERAL_SHADOWS, EFFECT_0))
                    amount += cp * auraEffIdolOfFeralShadows->GetAmount();
                // Idol of Worship. Can't be handled as SpellMod due its dependency from CPs
                else if (AuraEffect const* auraEffIdolOfWorship = caster->GetAuraEffect(SPELL_DRUID_IDOL_OF_WORSHIP, EFFECT_0))
                    amount += cp * auraEffIdolOfWorship->GetAmount();

                amount += int32(CalculatePct(caster->GetTotalAttackPowerValue(BASE_ATTACK), cp));
            }
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_rip_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_rip_AuraScript();
    }
};

// 16864 - Omen of Clarity
class spell_dru_omen_of_clarity : public SpellScriptLoader
{
    public:
        spell_dru_omen_of_clarity() : SpellScriptLoader("spell_dru_omen_of_clarity") { }

        class spell_dru_omen_of_clarity_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_omen_of_clarity_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DRUID_BALANCE_T10_BONUS, SPELL_DRUID_BALANCE_T10_BONUS_PROC });
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                Unit* target = GetTarget();
                if (target->HasAura(SPELL_DRUID_BALANCE_T10_BONUS))
                    target->CastSpell(nullptr, SPELL_DRUID_BALANCE_T10_BONUS_PROC, true, nullptr);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_omen_of_clarity_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_omen_of_clarity_AuraScript();
        }
};

// 52610 - Savage Roar
class spell_dru_savage_roar : public SpellScriptLoader
{
public:
    spell_dru_savage_roar() : SpellScriptLoader("spell_dru_savage_roar") { }

    class spell_dru_savage_roar_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_savage_roar_SpellScript);

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            if (caster->GetShapeshiftForm() != FORM_CAT_FORM)
                return SPELL_FAILED_ONLY_SHAPESHIFT;

            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_dru_savage_roar_SpellScript::CheckCast);
        }
    };

    class spell_dru_savage_roar_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_savage_roar_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_DRUID_SAVAGE_ROAR });
        }

        void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            target->CastSpell(target, SPELL_DRUID_SAVAGE_ROAR, true, nullptr, aurEff, GetCasterGUID());
        }

        void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_SAVAGE_ROAR);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_dru_savage_roar_AuraScript::AfterApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_dru_savage_roar_AuraScript::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_savage_roar_SpellScript();
    }

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_savage_roar_AuraScript();
    }
};

// -78892 - Stampede
class spell_dru_stampede : public SpellScriptLoader
{
public:
    spell_dru_stampede() : SpellScriptLoader("spell_dru_stampede") { }

    class spell_dru_stampede_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_stampede_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_DRUID_STAMPEDE_BAER_RANK_1,
                SPELL_DRUID_STAMPEDE_CAT_RANK_1,
                SPELL_DRUID_STAMPEDE_CAT_STATE,
                SPELL_DRUID_FERAL_CHARGE_CAT,
                SPELL_DRUID_FERAL_CHARGE_BEAR
            });
        }

        void HandleEffectCatProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            if (GetTarget()->GetShapeshiftForm() != FORM_CAT_FORM || eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_DRUID_FERAL_CHARGE_CAT)
                return;

            GetTarget()->CastSpell(GetTarget(), sSpellMgr->GetSpellWithRank(SPELL_DRUID_STAMPEDE_CAT_RANK_1, GetSpellInfo()->GetRank()), true, nullptr, aurEff);
            GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_STAMPEDE_CAT_STATE, true, nullptr, aurEff);
        }

        void HandleEffectBearProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            if (GetTarget()->GetShapeshiftForm() != FORM_BEAR_FORM || eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_DRUID_FERAL_CHARGE_BEAR)
                return;

            GetTarget()->CastSpell(GetTarget(), sSpellMgr->GetSpellWithRank(SPELL_DRUID_STAMPEDE_BAER_RANK_1, GetSpellInfo()->GetRank()), true, nullptr, aurEff);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_dru_stampede_AuraScript::HandleEffectCatProc, EFFECT_0, SPELL_AURA_DUMMY);
            OnEffectProc += AuraEffectProcFn(spell_dru_stampede_AuraScript::HandleEffectBearProc, EFFECT_1, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_stampede_AuraScript();
    }
};

// 50286 - Starfall (Dummy)
class spell_dru_starfall_dummy : public SpellScriptLoader
{
public:
    spell_dru_starfall_dummy() : SpellScriptLoader("spell_dru_starfall_dummy") { }

    class spell_dru_starfall_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_starfall_dummy_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 2);
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            // Shapeshifting into an animal form or mounting cancels the effect
            if (caster->GetCreatureType() == CREATURE_TYPE_BEAST || caster->IsMounted())
            {
                if (SpellInfo const* spellInfo = GetTriggeringSpell())
                    caster->RemoveAurasDueToSpell(spellInfo->Id);
                return;
            }

            // Any effect which causes you to lose control of your character will supress the starfall effect.
            if (caster->HasUnitState(UNIT_STATE_CONTROLLED))
                return;

            caster->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_starfall_dummy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_dru_starfall_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_starfall_dummy_SpellScript();
    }
};

//  93402 - Sunfire
class spell_dru_sunfire : public SpellScriptLoader
{
public:
    spell_dru_sunfire() : SpellScriptLoader("spell_dru_sunfire") { }

    class spell_dru_sunfire_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_sunfire_SpellScript);


        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_DRUID_SUNFIRE_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dru_sunfire_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_sunfire_SpellScript();
    }
};

// 61336 - Survival Instincts
class spell_dru_survival_instincts : public SpellScriptLoader
{
public:
    spell_dru_survival_instincts() : SpellScriptLoader("spell_dru_survival_instincts") { }

    class spell_dru_survival_instincts_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_survival_instincts_SpellScript);

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            if (!caster->IsInFeralForm())
                return SPELL_FAILED_ONLY_SHAPESHIFT;

            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_dru_survival_instincts_SpellScript::CheckCast);
        }
    };

    class spell_dru_survival_instincts_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_survival_instincts_AuraScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            return ValidateSpellInfo({ SPELL_DRUID_SURVIVAL_INSTINCTS });
        }

        void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            int32 bp0 = target->CountPctFromMaxHealth(aurEff->GetAmount());
            target->CastCustomSpell(target, SPELL_DRUID_SURVIVAL_INSTINCTS, &bp0, nullptr, nullptr, true);
        }

        void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_SURVIVAL_INSTINCTS);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_dru_survival_instincts_AuraScript::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
            AfterEffectRemove += AuraEffectRemoveFn(spell_dru_survival_instincts_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_survival_instincts_SpellScript();
    }

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_survival_instincts_AuraScript();
    }
};

// 40121 - Swift Flight Form (Passive)
class spell_dru_swift_flight_passive : public SpellScriptLoader
{
public:
    spell_dru_swift_flight_passive() : SpellScriptLoader("spell_dru_swift_flight_passive") { }

    class spell_dru_swift_flight_passive_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_swift_flight_passive_AuraScript);

        bool Load() override
        {
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
        {
            if (Player* caster = GetCaster()->ToPlayer())
                if (caster->GetSkillValue(SKILL_RIDING) >= 375)
                    amount = 310;
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_swift_flight_passive_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_swift_flight_passive_AuraScript();
    }
};

// 28744 - Regrowth
class spell_dru_t3_6p_bonus : public SpellScriptLoader
{
    public:
        spell_dru_t3_6p_bonus() : SpellScriptLoader("spell_dru_t3_6p_bonus") { }

        class spell_dru_t3_6p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t3_6p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DRUID_BLESSING_OF_THE_CLAW });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_BLESSING_OF_THE_CLAW, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_t3_6p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t3_6p_bonus_AuraScript();
        }
};

// 28719 - Healing Touch
class spell_dru_t3_8p_bonus : public SpellScriptLoader
{
        public:
            spell_dru_t3_8p_bonus() : SpellScriptLoader("spell_dru_t3_8p_bonus") { }

        class spell_dru_t3_8p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t3_8p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DRUID_EXHILARATE });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Spell const* spell = eventInfo.GetProcSpell();
                if (!spell)
                    return;

                Unit* caster = eventInfo.GetActor();
                std::vector<SpellPowerCost> const& costs = spell->GetPowerCost();
                auto m = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_MANA; });
                if (m == costs.end())
                    return;

                int32 amount = CalculatePct(m->Amount, aurEff->GetAmount());
                caster->CastCustomSpell(SPELL_DRUID_EXHILARATE, SPELLVALUE_BASE_POINT0, amount, nullptr, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_t3_8p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t3_8p_bonus_AuraScript();
        }
};

// 37288 - Mana Restore
// 37295 - Mana Restore
class spell_dru_t4_2p_bonus : public SpellScriptLoader
{
    public:
        spell_dru_t4_2p_bonus() : SpellScriptLoader("spell_dru_t4_2p_bonus") { }

        class spell_dru_t4_2p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t4_2p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DRUID_INFUSION });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell(nullptr, SPELL_DRUID_INFUSION, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_t4_2p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t4_2p_bonus_AuraScript();
        }
};

// 783 - Travel Form (dummy)
class spell_dru_travel_form_dummy : public SpellScriptLoader
{
public:
    spell_dru_travel_form_dummy() : SpellScriptLoader("spell_dru_travel_form_dummy") { }

    class spell_dru_travel_form_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_travel_form_dummy_SpellScript);

        SpellCastResult CheckCast()
        {
            Player* player = GetCaster()->ToPlayer();
            if (!player)
                return SPELL_FAILED_CUSTOM_ERROR;

            if (player->GetSkillValue(SKILL_RIDING) < 75)
                return SPELL_FAILED_APPRENTICE_RIDING_REQUIREMENT;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(player->IsInWater() ? SPELL_DRUID_FORM_AQUATIC : SPELL_DRUID_FORM_STAG, GetCastDifficulty());
            return spellInfo->CheckLocation(player->GetMapId(), player->GetZoneId(), player->GetAreaId(), player);
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_dru_travel_form_dummy_SpellScript::CheckCast);
        }
    };

    class spell_dru_travel_form_dummy_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_travel_form_dummy_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_DRUID_FORM_STAG, SPELL_DRUID_FORM_AQUATIC, SPELL_DRUID_FORM_FLIGHT, SPELL_DRUID_FORM_SWIFT_FLIGHT });
        }

        bool Load() override
        {
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            uint32 triggeredSpellId;

            Player* player = GetTarget()->ToPlayer();
            if (player->IsInWater()) // Aquatic form
                triggeredSpellId = SPELL_DRUID_FORM_AQUATIC;
            else if (player->GetSkillValue(SKILL_RIDING) >= 225 && CheckLocationForForm(SPELL_DRUID_FORM_FLIGHT) == SPELL_CAST_OK) // Flight form
                triggeredSpellId = player->getLevel() >= 71 ? SPELL_DRUID_FORM_SWIFT_FLIGHT : SPELL_DRUID_FORM_FLIGHT;
            else // Stag form (riding skill already checked in CheckCast)
                triggeredSpellId = SPELL_DRUID_FORM_STAG;

            player->AddAura(triggeredSpellId, player);
        }

        void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            // No need to check remove mode, it's safe for auras to remove each other in AfterRemove hook.
            GetTarget()->RemoveAura(SPELL_DRUID_FORM_STAG);
            GetTarget()->RemoveAura(SPELL_DRUID_FORM_AQUATIC);
            GetTarget()->RemoveAura(SPELL_DRUID_FORM_FLIGHT);
            GetTarget()->RemoveAura(SPELL_DRUID_FORM_SWIFT_FLIGHT);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_dru_travel_form_dummy_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_dru_travel_form_dummy_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }

    private:
        // Outdoor check already passed - Travel Form (dummy) has SPELL_ATTR0_OUTDOORS_ONLY attribute.
        SpellCastResult CheckLocationForForm(uint32 spell)
        {
            Player* player = GetTarget()->ToPlayer();
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell, GetCastDifficulty());
            return spellInfo->CheckLocation(player->GetMapId(), player->GetZoneId(), player->GetAreaId(), player);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_travel_form_dummy_SpellScript();
    }

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_travel_form_dummy_AuraScript();
    }
};

// 1066 - Aquatic Form
// 33943 - Flight Form
// 40120 - Swift Flight Form
// 165961 - Stag Form
class spell_dru_travel_form : public SpellScriptLoader
{
public:
    spell_dru_travel_form() : SpellScriptLoader("spell_dru_travel_form") { }

    class spell_dru_travel_form_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_travel_form_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_DRUID_FORM_STAG, SPELL_DRUID_FORM_AQUATIC, SPELL_DRUID_FORM_FLIGHT, SPELL_DRUID_FORM_SWIFT_FLIGHT });
        }

        bool Load() override
        {
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            // If it stays 0, it removes Travel Form dummy in AfterRemove.
            triggeredSpellId = 0;

            // We should only handle aura interrupts.
            if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_INTERRUPT)
                return;

            // Check what form is appropriate
            Player* player = GetTarget()->ToPlayer();
            if (player->IsInWater()) // Aquatic form
                triggeredSpellId = SPELL_DRUID_FORM_AQUATIC;
            else if (player->GetSkillValue(SKILL_RIDING) >= 225 && CheckLocationForForm(SPELL_DRUID_FORM_FLIGHT) == SPELL_CAST_OK) // Flight form
                triggeredSpellId = player->GetSkillValue(SKILL_RIDING) >= 300 ? SPELL_DRUID_FORM_SWIFT_FLIGHT : SPELL_DRUID_FORM_FLIGHT;
            else if (CheckLocationForForm(SPELL_DRUID_FORM_STAG) == SPELL_CAST_OK) // Stag form
                triggeredSpellId = SPELL_DRUID_FORM_STAG;

            // If chosen form is current aura, just don't remove it.
            if (triggeredSpellId == m_scriptSpellId)
                PreventDefaultAction();
        }

        void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Player* player = GetTarget()->ToPlayer();

            if (triggeredSpellId) // Apply new form
                player->AddAura(triggeredSpellId, player);
            else // If not set, simply remove Travel Form dummy
                player->RemoveAura(SPELL_DRUID_TRAVEL_FORM);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_dru_travel_form_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_dru_travel_form_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
        }

    private:
        SpellCastResult CheckLocationForForm(uint32 spell_id)
        {
            Player* player = GetTarget()->ToPlayer();
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell_id, GetCastDifficulty());

            if (!player->GetMap()->IsOutdoors(player->GetPhaseShift(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ()))
                return SPELL_FAILED_ONLY_OUTDOORS;

            return spellInfo->CheckLocation(player->GetMapId(), player->GetZoneId(), player->GetAreaId(), player);
        }

        uint32 triggeredSpellId;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_travel_form_AuraScript();
    }
};

// 40442 - Druid Tier 6 Trinket
class spell_dru_item_t6_trinket : public SpellScriptLoader
{
    public:
        spell_dru_item_t6_trinket() : SpellScriptLoader("spell_dru_item_t6_trinket") { }

        class spell_dru_item_t6_trinket_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_item_t6_trinket_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({
                    SPELL_DRUID_BLESSING_OF_REMULOS,
                    SPELL_DRUID_BLESSING_OF_ELUNE,
                    SPELL_DRUID_BLESSING_OF_CENARIUS
                });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return;

                uint32 spellId;
                int32 chance;

                // Starfire
                if (spellInfo->SpellFamilyFlags[0] & 0x00000004)
                {
                    spellId = SPELL_DRUID_BLESSING_OF_REMULOS;
                    chance = 25;
                }
                // Rejuvenation
                else if (spellInfo->SpellFamilyFlags[0] & 0x00000010)
                {
                    spellId = SPELL_DRUID_BLESSING_OF_ELUNE;
                    chance = 25;
                }
                // Mangle (Bear) and Mangle (Cat)
                else if (spellInfo->SpellFamilyFlags[1] & 0x00000440)
                {
                    spellId = SPELL_DRUID_BLESSING_OF_CENARIUS;
                    chance = 40;
                }
                else
                    return;

                if (roll_chance_i(chance))
                    eventInfo.GetActor()->CastSpell(nullptr, spellId, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_item_t6_trinket_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_item_t6_trinket_AuraScript();
        }
};

// 70723 - Item - Druid T10 Balance 4P Bonus
class spell_dru_t10_balance_4p_bonus : public SpellScriptLoader
{
    public:
        spell_dru_t10_balance_4p_bonus() : SpellScriptLoader("spell_dru_t10_balance_4p_bonus") { }

        class spell_dru_t10_balance_4p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t10_balance_4p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DRUID_LANGUISH });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();

                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_DRUID_LANGUISH, GetCastDifficulty());
                int32 amount = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());
                amount /= spellInfo->GetMaxTicks();
                // Add remaining ticks to damage done
                amount += target->GetRemainingPeriodicAmount(caster->GetGUID(), SPELL_DRUID_LANGUISH, SPELL_AURA_PERIODIC_DAMAGE);

                caster->CastCustomSpell(SPELL_DRUID_LANGUISH, SPELLVALUE_BASE_POINT0, amount, target, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_t10_balance_4p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t10_balance_4p_bonus_AuraScript();
        }
};

// 70691 - Item T10 Restoration 4P Bonus
class spell_dru_t10_restoration_4p_bonus : public SpellScriptLoader
{
public:
    spell_dru_t10_restoration_4p_bonus() : SpellScriptLoader("spell_dru_t10_restoration_4p_bonus") { }

    class spell_dru_t10_restoration_4p_bonus_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_t10_restoration_4p_bonus_SpellScript);

        bool Load() override
        {
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (!GetCaster()->ToPlayer()->GetGroup())
            {
                targets.clear();
                targets.push_back(GetCaster());
            }
            else
            {
                targets.remove(GetExplTargetUnit());
                std::list<Unit*> tempTargets;
                for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    if ((*itr)->GetTypeId() == TYPEID_PLAYER && GetCaster()->IsInRaidWith((*itr)->ToUnit()))
                        tempTargets.push_back((*itr)->ToUnit());

                if (tempTargets.empty())
                {
                    targets.clear();
                    FinishCast(SPELL_FAILED_DONT_REPORT);
                    return;
                }

                Unit* target = Trinity::Containers::SelectRandomContainerElement(tempTargets);
                targets.clear();
                targets.push_back(target);
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_t10_restoration_4p_bonus_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_t10_restoration_4p_bonus_SpellScript();
    }
};

// 70664 - Druid T10 Restoration 4P Bonus (Rejuvenation)
class spell_dru_t10_restoration_4p_bonus_dummy : public SpellScriptLoader
{
    public:
        spell_dru_t10_restoration_4p_bonus_dummy() : SpellScriptLoader("spell_dru_t10_restoration_4p_bonus_dummy") { }

        class spell_dru_t10_restoration_4p_bonus_dummy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t10_restoration_4p_bonus_dummy_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DRUID_REJUVENATION_T10_PROC });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo || spellInfo->Id == SPELL_DRUID_REJUVENATION_T10_PROC)
                    return false;

                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return false;

                Player* caster = eventInfo.GetActor()->ToPlayer();
                if (!caster)
                    return false;

                return caster->GetGroup() || caster != eventInfo.GetProcTarget();
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                int32 amount = static_cast<int32>(eventInfo.GetHealInfo()->GetHeal());
                eventInfo.GetActor()->CastCustomSpell(SPELL_DRUID_REJUVENATION_T10_PROC, SPELLVALUE_BASE_POINT0, amount, nullptr, true, nullptr, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_dru_t10_restoration_4p_bonus_dummy_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_dru_t10_restoration_4p_bonus_dummy_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t10_restoration_4p_bonus_dummy_AuraScript();
        }
};

class RaidCheck
{
public:
    explicit RaidCheck(Unit const* caster) : _caster(caster) { }

    bool operator()(WorldObject* obj) const
    {
        if (Unit* target = obj->ToUnit())
            return !_caster->IsInRaidWith(target);

        return true;
    }

private:
    Unit const* _caster;
};

// 48438 - Wild Growth
class spell_dru_wild_growth : public SpellScriptLoader
{
public:
    spell_dru_wild_growth() : SpellScriptLoader("spell_dru_wild_growth") { }

    class spell_dru_wild_growth_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_wild_growth_SpellScript);

        bool Validate(SpellInfo const* spellInfo) override
        {
            SpellEffectInfo const* effect2 = spellInfo->GetEffect(EFFECT_2);
            if (!effect2 || effect2->IsEffect() || effect2->CalcValue() <= 0)
                return false;
            return true;
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(RaidCheck(GetCaster()));

            uint32 const maxTargets = uint32(GetSpellInfo()->GetEffect(EFFECT_2)->CalcValue(GetCaster()));

            if (targets.size() > maxTargets)
            {
                targets.sort(Trinity::HealthPctOrderPred());
                targets.resize(maxTargets);
            }

            _targets = targets;
        }

        void SetTargets(std::list<WorldObject*>& targets)
        {
            targets = _targets;
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_wild_growth_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_wild_growth_SpellScript::SetTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
        }

        std::list<WorldObject*> _targets;
    };

    class spell_dru_wild_growth_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_wild_growth_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_DRUID_RESTORATION_T10_2P_BONUS });
        }

        void HandleTickUpdate(AuraEffect* aurEff)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            // calculate from base damage, not from aurEff->GetAmount() (already modified)
            float damage = caster->CalculateSpellDamage(GetUnitOwner(), GetSpellInfo(), aurEff->GetEffIndex());

            // Wild Growth = first tick gains a 6% bonus, reduced by 2% each tick
            float reduction = 2.f;
            if (AuraEffect* bonus = caster->GetAuraEffect(SPELL_DRUID_RESTORATION_T10_2P_BONUS, EFFECT_0))
                reduction -= CalculatePct(reduction, bonus->GetAmount());
            reduction *= (aurEff->GetTickNumber() - 1);

            AddPct(damage, 6.f - reduction);
            aurEff->SetAmount(int32(damage));
        }

        void Register() override
        {
            OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_dru_wild_growth_AuraScript::HandleTickUpdate, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_wild_growth_SpellScript();
    }

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_wild_growth_AuraScript();
    }
};

void AddSC_druid_spell_scripts()
{
    new spell_dru_dash();
    new spell_dru_flight_form();
    new spell_dru_forms_trinket();
    new spell_dru_idol_lifebloom();
    new spell_dru_innervate();
    new spell_dru_lifebloom();
    new spell_dru_living_seed();
    new spell_dru_living_seed_proc();
    new spell_dru_moonfire();
    new spell_dru_omen_of_clarity();
    new spell_dru_predatory_strikes();
    new spell_dru_rip();
    new spell_dru_savage_roar();
    new spell_dru_stampede();
    new spell_dru_starfall_dummy();
    new spell_dru_sunfire();
    new spell_dru_survival_instincts();
    new spell_dru_swift_flight_passive();
    new spell_dru_t3_6p_bonus();
    new spell_dru_t3_8p_bonus();
    new spell_dru_t4_2p_bonus();
    new spell_dru_travel_form_dummy();
    new spell_dru_travel_form();
    new spell_dru_item_t6_trinket();
    new spell_dru_t10_balance_4p_bonus();
    new spell_dru_t10_restoration_4p_bonus();
    new spell_dru_t10_restoration_4p_bonus_dummy();
    new spell_dru_wild_growth();
}
