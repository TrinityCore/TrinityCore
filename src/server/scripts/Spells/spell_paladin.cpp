/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_PALADIN and SPELLFAMILY_GENERIC spells used by paladin players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_pal_".
 */

#include "ScriptMgr.h"
#include "Group.h"
#include "Player.h"
#include "Random.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum PaladinSpells
{
    SPELL_PALADIN_AVENGERS_SHIELD                = 31935,
    SPELL_PALADIN_BEACON_OF_LIGHT                = 53563,
    SPELL_PALADIN_BEACON_OF_LIGHT_HEAL           = 53652,
    SPELL_PALADIN_BLINDING_LIGHT_EFFECT          = 105421,
    SPELL_PALADIN_DIVINE_STEED_HUMAN             = 221883,
    SPELL_PALADIN_DIVINE_STEED_DRAENEI           = 221887,
    SPELL_PALADIN_DIVINE_STEED_BLOODELF          = 221886,
    SPELL_PALADIN_DIVINE_STEED_TAUREN            = 221885,
    SPELL_PALADIN_DIVINE_STORM_DAMAGE            = 224239,
    SPELL_PALADIN_DIVINE_HAMMER                  = 198034,
    SPELL_PALADIN_ENDURING_LIGHT                 = 40471,
    SPELL_PALADIN_ENDURING_JUDGEMENT             = 40472,
    SPELL_PALADIN_EYE_FOR_AN_EYE_RANK_1          = 9799,
    SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE          = 25997,
    SPELL_PALADIN_FORBEARANCE                    = 25771,
    SPELL_PALADIN_FINAL_STAND                    = 204077,
    SPELL_PALADIN_FINAL_STAND_EFFECT             = 204079,
    SPELL_PALADIN_HAND_OF_SACRIFICE              = 6940,
    SPELL_PALADIN_HOLY_SHOCK_R1                  = 20473,
    SPELL_PALADIN_HOLY_SHOCK_R1_DAMAGE           = 25912,
    SPELL_PALADIN_HOLY_SHOCK_R1_HEALING          = 25914,
    SPELL_PALADIN_ITEM_HEALING_TRANCE            = 37706,
    SPELL_PALADIN_JUDGEMENT_DAMAGE               = 54158,
    SPELL_PALADIN_RIGHTEOUS_DEFENSE_TAUNT        = 31790,
    SPELL_PALADIN_SANCTIFIED_WRATH               = 57318,
    SPELL_PALADIN_SANCTIFIED_WRATH_TALENT_R1     = 53375,
    SPELL_PALADIN_TEMPLAR_VERDICT_DAMAGE         = 224266,
    SPELL_PALADIN_TEMPLAR_VERDICT_HOLY           = 138169,
    SPELL_PALADIN_TEMPLAR_VERDICT_HOLY_DAMAGE    = 138165
};

enum PaladinSpellVisualKit
{
    PALADIN_VISUAL_KIT_DIVINE_STORM = 73892
};

// 31884 - Avenging Wrath
class spell_pal_avenging_wrath : public SpellScriptLoader
{
    public:
        spell_pal_avenging_wrath() : SpellScriptLoader("spell_pal_avenging_wrath") { }

        class spell_pal_avenging_wrath_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_avenging_wrath_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_SANCTIFIED_WRATH, SPELL_PALADIN_SANCTIFIED_WRATH_TALENT_R1 });
            }

            void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (AuraEffect const* aurEff = target->GetAuraEffectOfRankedSpell(SPELL_PALADIN_SANCTIFIED_WRATH_TALENT_R1, EFFECT_2))
                {
                    int32 basepoints = aurEff->GetAmount();
                    target->CastCustomSpell(target, SPELL_PALADIN_SANCTIFIED_WRATH, &basepoints, &basepoints, NULL, true, NULL, aurEff);
                }
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAurasDueToSpell(SPELL_PALADIN_SANCTIFIED_WRATH);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_pal_avenging_wrath_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_pal_avenging_wrath_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_avenging_wrath_AuraScript();
        }
};

// 115750 - Blinding Light 
class spell_pal_blinding_light : public SpellScript
{
    PrepareSpellScript(spell_pal_blinding_light);
    
    bool Validate(SpellInfo const* /*spellinfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_BLINDING_LIGHT_EFFECT });
    }
    
    void HandleDummy(SpellEffIndex /*eff*/)
    {
        if (Unit* target = GetHitUnit())
        {
            GetCaster()->CastSpell(target, SPELL_PALADIN_BLINDING_LIGHT_EFFECT, true);
        }
    }
    
    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_blinding_light::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
}
// 190784 - Divine Steed
class spell_pal_divine_steed : public SpellScriptLoader
{
public:
    spell_pal_divine_steed() : SpellScriptLoader("spell_pal_divine_steed") { }

    class spell_pal_divine_steed_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_divine_steed_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_PALADIN_DIVINE_STEED_HUMAN,
                SPELL_PALADIN_DIVINE_STEED_DRAENEI,
                SPELL_PALADIN_DIVINE_STEED_BLOODELF,
                SPELL_PALADIN_DIVINE_STEED_TAUREN
            });
        }

        void HandleOnCast()
        {
            Unit* caster = GetCaster();

            uint32 spellId = SPELL_PALADIN_DIVINE_STEED_HUMAN;
            switch (caster->getRace())
            {
                case RACE_HUMAN:
                case RACE_DWARF:
                    spellId = SPELL_PALADIN_DIVINE_STEED_HUMAN;
                    break;
                case RACE_DRAENEI:
                    spellId = SPELL_PALADIN_DIVINE_STEED_DRAENEI;
                    break;
                case RACE_BLOODELF:
                    spellId = SPELL_PALADIN_DIVINE_STEED_BLOODELF;
                    break;
                case RACE_TAUREN:
                    spellId = SPELL_PALADIN_DIVINE_STEED_TAUREN;
                    break;
                default:
                    break;
            }

            caster->CastSpell(caster, spellId, true);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_pal_divine_steed_SpellScript::HandleOnCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_divine_steed_SpellScript();
    }
};

// 53385 - Divine Storm
class spell_pal_divine_storm : public SpellScriptLoader
{
    public:
        spell_pal_divine_storm() : SpellScriptLoader("spell_pal_divine_storm") { }

        class spell_pal_divine_storm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_divine_storm_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_DIVINE_STORM_DAMAGE });
            }

            void HandleOnCast()
            {
                Unit* caster = GetCaster();
                caster->SendPlaySpellVisualKit(PALADIN_VISUAL_KIT_DIVINE_STORM, 0, 0);
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();
                if (!target)
                    return;

                caster->CastSpell(target, SPELL_PALADIN_DIVINE_STORM_DAMAGE, true);
            }

            void Register() override
            {
                OnCast += SpellCastFn(spell_pal_divine_storm_SpellScript::HandleOnCast);
                OnEffectHitTarget += SpellEffectFn(spell_pal_divine_storm_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_divine_storm_SpellScript();
        }
};

// 7.1.5 Divine Shield - 642
class spell_pal_divine_shield : public SpellScript
{
    PrepareSpellScript(spell_pal_divine_shield);
    
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_PALADIN_FINAL_STAND,
            SPELL_PALADIN_FINAL_STAND_EFFECT
        });
    }
    
    SpellCastResult Forbearance()
    {
        if (Unit* caster = GetCaster())
        {
            if (caster->HasAura(SPELL_PALADIN_FORBEARANCE))
                return SPELL_FAILED_TARGET_AURASTATE;
        }
        return SPELL_CAST_OK;
    }
    
    void HandleOnHit()
    {
        if (caster->HasAura(SPELL_PALADIN_FINAL_STAND))
            caster->CastSpell(caster, SPELL_PALADIN_FINAL_STAND_EFFECT, true);
        caster->CastSpell(caster, SPELL_PALADIN_FORBEARANCE, true);
    }
    
    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_pal_divine_shield::Forbearance);
        OnHit += SpellHitFn(spell_pal_divine_shield::HandleOnHit);
    }
};

// 7.1.5 Divine Hammer 198034
class spell_pal_divine_hammer : public SpellScript
{
    PrepareSpellScript(spell_pal_divine_hammer);
    
    bool Validate(SpellInfo const* /*spellinfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_DIVINE_HAMMER });
    }
    
    void HolyPowerGenerate()
    {
        if (Unit* Caster = GetCaster())
        {
            uint32 Power = Caster->GetPower(POWER_HOLY_POWER);
            if (Power > 3)
                Power = 3;
            Caster->SetPower(POWER_HOLY_POWER, Power + 2);
        }
    }
    
    void Register() override
    {
        AfterCast += SpellCastFn(spell_pal_divine_hammer::HandleHolyPower);
    }
};

// -9799 - Eye for an Eye
class spell_pal_eye_for_an_eye : public SpellScriptLoader
{
    public:
        spell_pal_eye_for_an_eye() : SpellScriptLoader("spell_pal_eye_for_an_eye") { }

        class spell_pal_eye_for_an_eye_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_eye_for_an_eye_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE });
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                int32 damage = CalculatePct(damageInfo->GetDamage(), aurEff->GetAmount());
                GetTarget()->CastCustomSpell(SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE, SPELLVALUE_BASE_POINT0, damage, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_eye_for_an_eye_AuraScript::HandleEffectProc, EFFECT_0, m_scriptSpellId == SPELL_PALADIN_EYE_FOR_AN_EYE_RANK_1 ? SPELL_AURA_DUMMY : SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_eye_for_an_eye_AuraScript();
        }
};

// -75806 - Grand Crusader
class spell_pal_grand_crusader : public SpellScriptLoader
{
    public:
        spell_pal_grand_crusader() : SpellScriptLoader("spell_pal_grand_crusader") { }

        class spell_pal_grand_crusader_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_grand_crusader_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_AVENGERS_SHIELD });
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                return GetTarget()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                GetTarget()->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_AVENGERS_SHIELD, true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pal_grand_crusader_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_grand_crusader_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_grand_crusader_AuraScript();
        }
};

// 6940 - Hand of Sacrifice
class spell_pal_hand_of_sacrifice : public SpellScriptLoader
{
    public:
        spell_pal_hand_of_sacrifice() : SpellScriptLoader("spell_pal_hand_of_sacrifice") { }

        class spell_pal_hand_of_sacrifice_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_hand_of_sacrifice_AuraScript);

        public:
            spell_pal_hand_of_sacrifice_AuraScript()
            {
                remainingAmount = 0;
            }

        private:
            int32 remainingAmount;

            bool Load() override
            {
                if (Unit* caster = GetCaster())
                {
                    remainingAmount = caster->GetMaxHealth();
                    return true;
                }
                return false;
            }

            void Split(AuraEffect* /*aurEff*/, DamageInfo & /*dmgInfo*/, uint32 & splitAmount)
            {
                remainingAmount -= splitAmount;

                if (remainingAmount <= 0)
                {
                    GetTarget()->RemoveAura(SPELL_PALADIN_HAND_OF_SACRIFICE);
                }
            }

            void Register() override
            {
                OnEffectSplit += AuraEffectSplitFn(spell_pal_hand_of_sacrifice_AuraScript::Split, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_hand_of_sacrifice_AuraScript();
        }
};

// 20473 - Holy Shock
class spell_pal_holy_shock : public SpellScriptLoader
{
    public:
        spell_pal_holy_shock() : SpellScriptLoader("spell_pal_holy_shock") { }

        class spell_pal_holy_shock_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_holy_shock_SpellScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                SpellInfo const* firstRankSpellInfo = sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_SHOCK_R1);
                if (!firstRankSpellInfo)
                    return false;

                // can't use other spell than holy shock due to spell_ranks dependency
                if (!spellInfo->IsRankOf(firstRankSpellInfo))
                    return false;

                uint8 rank = spellInfo->GetRank();
                if (!sSpellMgr->GetSpellWithRank(SPELL_PALADIN_HOLY_SHOCK_R1_DAMAGE, rank, true) || !sSpellMgr->GetSpellWithRank(SPELL_PALADIN_HOLY_SHOCK_R1_HEALING, rank, true))
                    return false;

                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* unitTarget = GetHitUnit())
                {
                    uint8 rank = GetSpellInfo()->GetRank();
                    if (caster->IsFriendlyTo(unitTarget))
                        caster->CastSpell(unitTarget, sSpellMgr->GetSpellWithRank(SPELL_PALADIN_HOLY_SHOCK_R1_HEALING, rank), true);
                    else
                        caster->CastSpell(unitTarget, sSpellMgr->GetSpellWithRank(SPELL_PALADIN_HOLY_SHOCK_R1_DAMAGE, rank), true);
                }
            }

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetExplTargetUnit())
                {
                    if (!caster->IsFriendlyTo(target))
                    {
                        if (!caster->IsValidAttackTarget(target))
                            return SPELL_FAILED_BAD_TARGETS;

                        if (!caster->isInFront(target))
                            return SPELL_FAILED_UNIT_NOT_INFRONT;
                    }
                }
                else
                    return SPELL_FAILED_BAD_TARGETS;
                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_pal_holy_shock_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_pal_holy_shock_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_holy_shock_SpellScript();
        }
};

// 37705 - Healing Discount
class spell_pal_item_healing_discount : public SpellScriptLoader
{
    public:
        spell_pal_item_healing_discount() : SpellScriptLoader("spell_pal_item_healing_discount") { }

        class spell_pal_item_healing_discount_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_item_healing_discount_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_ITEM_HEALING_TRANCE });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_ITEM_HEALING_TRANCE, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_item_healing_discount_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_item_healing_discount_AuraScript();
        }
};

// 40470 - Paladin Tier 6 Trinket
class spell_pal_item_t6_trinket : public SpellScriptLoader
{
    public:
        spell_pal_item_t6_trinket() : SpellScriptLoader("spell_pal_item_t6_trinket") { }

        class spell_pal_item_t6_trinket_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_item_t6_trinket_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_ENDURING_LIGHT, SPELL_PALADIN_ENDURING_JUDGEMENT });
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return;

                uint32 spellId;
                int32 chance;

                // Holy Light & Flash of Light
                if (spellInfo->SpellFamilyFlags[0] & 0xC0000000)
                {
                    spellId = SPELL_PALADIN_ENDURING_LIGHT;
                    chance = 15;
                }
                // Judgements
                else if (spellInfo->SpellFamilyFlags[0] & 0x00800000)
                {
                    spellId = SPELL_PALADIN_ENDURING_JUDGEMENT;
                    chance = 50;
                }
                else
                    return;

                if (roll_chance_i(chance))
                    eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), spellId, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_item_t6_trinket_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_item_t6_trinket_AuraScript();
        }
};

// 20271 - Judgement
/// Updated 4.3.4
class spell_pal_judgement : public SpellScriptLoader
{
    public:
        spell_pal_judgement() : SpellScriptLoader("spell_pal_judgement") { }

        class spell_pal_judgement_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_judgement_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_JUDGEMENT_DAMAGE });
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                uint32 spellId = SPELL_PALADIN_JUDGEMENT_DAMAGE;

                // some seals have SPELL_AURA_DUMMY in EFFECT_2
                Unit::AuraEffectList const& auras = GetCaster()->GetAuraEffectsByType(SPELL_AURA_DUMMY);
                for (Unit::AuraEffectList::const_iterator i = auras.begin(); i != auras.end(); ++i)
                {
                    if ((*i)->GetSpellInfo()->GetSpellSpecific() == SPELL_SPECIFIC_SEAL && (*i)->GetEffIndex() == EFFECT_2)
                    {
                        if (sSpellMgr->GetSpellInfo((*i)->GetAmount()))
                        {
                            spellId = (*i)->GetAmount();
                            break;
                        }
                    }
                }

                GetCaster()->CastSpell(GetHitUnit(), spellId, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_judgement_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_judgement_SpellScript();
        }
};

// 7.1.5 Lay on Hand - 633
class spell_pal_lay_on_hand : public SpellScript
{
    PrepareSpellScript(spell_pal_lay_on_hand);
    
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_FORBEARANCE });
    }
    
    SpellCastResult Forbearance()
    {
        if (Unit* caster = GetCaster())
        {
            if (caster->HasAura(SPELL_PALADIN_FORBEARANCE))
                return SPELL_FAILED_TARGET_AURASTATE;
        }
        return SPELL_CAST_OK;
    }
    
    void HandleOnHit()
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_PALADIN_FORBEARANCE, true);
    }
    
    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_pal_lay_on_hand::Forbearance);
        OnHit += SpellHitFn(spell_pal_lay_on_hand::HandleOnHit);
    }
}

// 53651 - Light's Beacon - Beacon of Light
class spell_pal_light_s_beacon : public SpellScriptLoader
{
    public:
        spell_pal_light_s_beacon() : SpellScriptLoader("spell_pal_light_s_beacon") { }

        class spell_pal_light_s_beacon_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_light_s_beacon_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_BEACON_OF_LIGHT, SPELL_PALADIN_BEACON_OF_LIGHT_HEAL });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (!eventInfo.GetActionTarget())
                    return false;
                if (eventInfo.GetActionTarget()->HasAura(SPELL_PALADIN_BEACON_OF_LIGHT, eventInfo.GetActor()->GetGUID()))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return;

                uint32 heal = CalculatePct(healInfo->GetHeal(), aurEff->GetAmount());

                Unit::AuraList const& auras = GetCaster()->GetSingleCastAuras();
                for (Unit::AuraList::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                {
                    if ((*itr)->GetId() == SPELL_PALADIN_BEACON_OF_LIGHT)
                    {
                        std::list<AuraApplication*> applications;
                        (*itr)->GetApplicationList(applications);
                        if (!applications.empty())
                            eventInfo.GetActor()->CastCustomSpell(SPELL_PALADIN_BEACON_OF_LIGHT_HEAL, SPELLVALUE_BASE_POINT0, heal, applications.front()->GetTarget(), true);
                        return;
                    }
                }
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pal_light_s_beacon_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_light_s_beacon_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_light_s_beacon_AuraScript();
        }
};

// 31789 - Righteous Defense
class spell_pal_righteous_defense : public SpellScriptLoader
{
    public:
        spell_pal_righteous_defense() : SpellScriptLoader("spell_pal_righteous_defense") { }

        class spell_pal_righteous_defense_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_righteous_defense_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_RIGHTEOUS_DEFENSE_TAUNT });
            }

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_DONT_REPORT;

                if (Unit* target = GetExplTargetUnit())
                {
                    if (!target->IsFriendlyTo(caster) || target->getAttackers().empty())
                        return SPELL_FAILED_BAD_TARGETS;
                }
                else
                    return SPELL_FAILED_BAD_TARGETS;

                return SPELL_CAST_OK;
            }

            void HandleTriggerSpellLaunch(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
            }

            void HandleTriggerSpellHit(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Unit* target = GetHitUnit())
                    GetCaster()->CastSpell(target, SPELL_PALADIN_RIGHTEOUS_DEFENSE_TAUNT, true);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_pal_righteous_defense_SpellScript::CheckCast);
                //! WORKAROUND
                //! target select will be executed in hitphase of effect 0
                //! so we must handle trigger spell also in hit phase (default execution in launch phase)
                //! see issue #3718
                OnEffectLaunchTarget += SpellEffectFn(spell_pal_righteous_defense_SpellScript::HandleTriggerSpellLaunch, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
                OnEffectHitTarget += SpellEffectFn(spell_pal_righteous_defense_SpellScript::HandleTriggerSpellHit, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_righteous_defense_SpellScript();
        }
};

// 85285 - Sacred Shield
class spell_pal_sacred_shield : public SpellScriptLoader
{
    public:
        spell_pal_sacred_shield() : SpellScriptLoader("spell_pal_sacred_shield") { }

        class spell_pal_sacred_shield_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_sacred_shield_SpellScript);

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_DONT_REPORT;

                if (!caster->HealthBelowPct(30))
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_pal_sacred_shield_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_sacred_shield_SpellScript();
        }
};

// 53600 - Shield of the Righteous
/// Updated 4.3.4
class spell_pal_shield_of_the_righteous : public SpellScriptLoader
{
    public:
        spell_pal_shield_of_the_righteous() : SpellScriptLoader("spell_pal_shield_of_the_righteous") { }

        class spell_pal_shield_of_the_righteous_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_shield_of_the_righteous_SpellScript);

            bool Load() override
            {
                if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                    return false;

                if (GetCaster()->ToPlayer()->getClass() != CLASS_PALADIN)
                    return false;

                return true;
            }

            void ChangeDamage(SpellEffIndex /*effIndex*/)
            {
                int32 damage = GetHitDamage();

                // Because 1 Holy Power (HP) is consumed when casting spell,
                // GetPower(POWER_HOLY_POWER) will return 0 when player has 1 HP,
                // return 1 at 2 HP, and 2 at 3 HP
                int32 hp = GetCaster()->GetPower(POWER_HOLY_POWER);

                // Holy Power Scaling: 3 times damage at 2 HP, 6 times at 3 HP
                damage *= 0.5*hp*hp + 1.5*hp + 1;

                SetHitDamage(damage);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_shield_of_the_righteous_SpellScript::ChangeDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_shield_of_the_righteous_SpellScript();
        }
};

// 7.1.5 Templar's Verdict - 85256
class spell_pal_templar_verdict : public  SpellScript
{
    PrepareSpellScript(spell_pal_templar_verdict);
    
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_TEMPLAR_VERDICT_DAMAGE });
    }
    
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* target = GetHitUnit())
        {
            caster->CastSpell(target, SPELL_PALADIN_TEMPLAR_VERDICT_DAMAGE, true);
            if (caster->HasSpell(SPELL_PALADIN_TEMPLAR_VERDICT_HOLY))
                caster->CastSpell(target, SPELL_PALADIN_TEMPLAR_VERDICT_HOLY_DAMAGE, true);
        }
    }
    
    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_templar_verdict::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_paladin_spell_scripts()
{
    new spell_pal_avenging_wrath();
    RegisterSpellScript(spell_pal_blinding_light);
    new spell_pal_divine_steed();
    new spell_pal_divine_storm();
    RegisterSpellScript(spell_pal_divine_shield);
    RegisterSpellScript(spell_pal_divine_hammer);
    new spell_pal_eye_for_an_eye();
    new spell_pal_grand_crusader();
    new spell_pal_hand_of_sacrifice();
    new spell_pal_holy_shock();
    new spell_pal_item_healing_discount();
    new spell_pal_item_t6_trinket();
    new spell_pal_judgement();
    RegisterSpellScript(spell_pal_lay_on_hand);
    new spell_pal_light_s_beacon();
    new spell_pal_righteous_defense();
    new spell_pal_sacred_shield();
    new spell_pal_shield_of_the_righteous();
    RegisterSpellScript(spell_pal_templar_verdict);
}
