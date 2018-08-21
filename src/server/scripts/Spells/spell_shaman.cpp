/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_SHAMAN and SPELLFAMILY_GENERIC spells used by shaman players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_sha_".
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "GridNotifiers.h"
#include "Item.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum ShamanSpells
{
    SPELL_SHAMAN_ANCESTRAL_AWAKENING            = 52759,
    SPELL_SHAMAN_ANCESTRAL_AWAKENING_PROC       = 52752,
    SPELL_SHAMAN_ANCESTRAL_VIGOR                = 105284,
    SPELL_SHAMAN_BIND_SIGHT                     = 6277,
    SPELL_SHAMAN_CHAIN_HEAL                     = 1064,
    SPELL_SHAMAN_CHAIN_LIGHTNING                = 421,
    SPELL_SHAMAN_CHAIN_LIGHTNING_TRIGGERED      = 45297,
    SPELL_SHAMAN_CLEANSING_WATERS_DUMMY_R1      = 86959,
    SPELL_SHAMAN_CLEANSING_WATERS_DUMMY_R2      = 86962,
    SPELL_SMAMAN_CLEANSING_WATERS_HEAL_R1       = 86961,
    SPELL_SMAMAN_CLEANSING_WATERS_HEAL_R2       = 86958,
    SPELL_SHAMAN_EARTH_SHIELD_HEAL              = 379,
    SPELL_SHAMAN_ELEMENTAL_MASTERY              = 16166,
    SPELL_SHAMAN_EXHAUSTION                     = 57723,
    SPELL_SHAMAN_FIRE_NOVA_TRIGGERED_R1         = 8349,
    SPELL_SHAMAN_FLAME_SHOCK                    = 8050,
    SPELL_SHAMAN_FLAMETONGUE_ATTACK             = 10444,
    SPELL_SHAMAN_FLAMETONGUE_WEAPON             = 8024,
    SPELL_SHAMAN_FOCUSED_INSIGHT                = 77800,
    SPELL_SHAMAN_FREEZE                         = 63685,
    SPELL_SHAMAN_FULMINATION_PROC               = 95774,
    SPELL_SHAMAN_FULMINATION_DAMAGE             = 88767,
    SPELL_SHAMAN_GLYPH_OF_EARTH_SHIELD          = 63279,
    SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM  = 55456,
    SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE          = 55533,
    SPELL_SHAMAN_GLYPH_OF_MANA_TIDE             = 55441,
    SPELL_SHAMAN_GLYPH_OF_THUNDERSTORM          = 62132,
    SPELL_SHAMAN_HEALING_RAIN_TRIGGERED         = 73921,
    SPELL_SHAMAN_HEALING_SURGE                  = 8004,
    SPELL_SHAMAN_LAVA_BURST                     = 51505,
    SPELL_SHAMAN_LAVA_BURST_TRIGGERED           = 77451,
    SPELL_SHAMAN_LAVA_FLOWS_R1                  = 51480,
    SPELL_SHAMAN_LAVA_FLOWS_TRIGGERED_R1        = 65264,
    SPELL_SHAMAN_LAVA_SURGE                     = 77762,
    SPELL_SHAMAN_LIGHTNING_BOLT                 = 403,
    SPELL_SHAMAN_LIGHTNING_BOLT_TRIGGERED       = 45284,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD          = 23552,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE   = 27635,
    SPELL_SHAMAN_ITEM_MANA_SURGE                = 23571,
    SPELL_SHAMAN_LIGHTNING_SHIELD               = 324,
    SPELL_SHAMAN_LIGHTNING_SHIELD_DAMAGE        = 26364,
    SPELL_SHAMAN_NATURE_GUARDIAN                = 31616,
    SPELL_SHAMAN_RESURGENCE_ENERGIZE            = 101033,
    SPELL_SHAMAN_RIPTIDE                        = 61295,
    SPELL_SHAMAN_SATED                          = 57724,
    SPELL_SHAMAN_STORM_EARTH_AND_FIRE           = 51483,
    SPELL_SHAMAN_TELLURIC_CURRENTS              = 82987,
    SPELL_SHAMAN_TOTEM_EARTHBIND_EARTHGRAB      = 64695,
    SPELL_SHAMAN_TOTEM_EARTHBIND_TOTEM          = 6474,
    SPELL_SHAMAN_TOTEM_EARTHEN_POWER            = 59566,
    SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL      = 52042,
    SPELL_SHAMAN_TIDAL_WAVES                    = 53390,
    SPELL_SHAMAN_TOTEMIC_MASTERY                = 38437,
    SPELL_SHAMAN_UNLEASH_LIFE                   = 73685,
    SPELL_SHAMAN_UNLEASH_WIND                   = 73681,
    SPELL_SHAMAN_UNLEASH_FROST                  = 73682,
    SPELL_SHAMAN_UNLEASH_FLAME                  = 73683,
    SPELL_SHAMAN_UNLEASH_EARTH                  = 73684,
    SPELL_SHAMAN_WATER_SHIELD                   = 52127,
    SPELL_SHAMAN_WINDFURY_ATTACK_MAINHAND       = 25504,
    SPELL_SHAMAN_WINDFURY_ATTACK_OFFHAND        = 33750,
    SPELL_SHAMAN_WINDFURY_WEAPON                = 8232
};

enum ShamanSpellIcons
{
    SHAMAN_ICON_ID_SOOTHING_RAIN                = 2011,
    SHAMAN_ICON_ID_SHAMAN_LAVA_FLOW             = 3087,
    SHAMAN_ICON_ID_CLEANSING_WATERS             = 2020,
    SHAMAN_ICON_ID_BLESSING_OF_THE_ETERNALS     = 3157,
    SHAMAN_ICON_ID_FULMINATION                  = 2010
};

enum MiscSpells
{
    SPELL_HUNTER_INSANITY                       = 95809,
    SPELL_MAGE_TEMPORAL_DISPLACEMENT            = 80354
};

enum ShamanSpellCategories
{
    SHAMAN_SPELL_CATEGORY_SHOCK_SPELLS = 19
};

enum ShamanEnchantmentIds
{
    SHAMAN_ENCHANTMENT_ID_FLAMETONGUE   = 5,
    SHAMAN_ENCHANTMENT_ID_EARTHLIVING   = 3345,
    SHAMAN_ENCHANTMENT_ID_FROSTBRAND    = 2,
    SHAMAN_ENCHANTMENT_ID_ROCKBITER     = 3021,
    SHAMAN_ENCHANTMENT_ID_WINDFURY      = 283
};

// -51556 - Ancestral Awakening
class spell_sha_ancestral_awakening : public SpellScriptLoader
{
    public:
        spell_sha_ancestral_awakening() : SpellScriptLoader("spell_sha_ancestral_awakening") { }

        class spell_sha_ancestral_awakening_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_ancestral_awakening_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_TIDAL_WAVES });
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 heal = int32(CalculatePct(eventInfo.GetHealInfo()->GetHeal(), aurEff->GetAmount()));

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_ANCESTRAL_AWAKENING, SPELLVALUE_BASE_POINT0, heal, (Unit*)nullptr, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_ancestral_awakening_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_ancestral_awakening_AuraScript();
        }
};

// 52759 - Ancestral Awakening
/// Updated 4.3.4
class spell_sha_ancestral_awakening_proc : public SpellScriptLoader
{
    public:
        spell_sha_ancestral_awakening_proc() : SpellScriptLoader("spell_sha_ancestral_awakening_proc") { }

        class spell_sha_ancestral_awakening_proc_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_ancestral_awakening_proc_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_ANCESTRAL_AWAKENING_PROC });
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.size() < 2)
                    return;

                targets.sort(Trinity::HealthPctOrderPred());

                WorldObject* target = targets.front();
                targets.clear();
                targets.push_back(target);
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastCustomSpell(SPELL_SHAMAN_ANCESTRAL_AWAKENING_PROC, SPELLVALUE_BASE_POINT0, GetEffectValue(), GetHitUnit(), true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_ancestral_awakening_proc_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
                OnEffectHitTarget += SpellEffectFn(spell_sha_ancestral_awakening_proc_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_ancestral_awakening_proc_SpellScript();
        }
};

// 2825 - Bloodlust
/// Updated 4.3.4
class spell_sha_bloodlust : public SpellScriptLoader
{
    public:
        spell_sha_bloodlust() : SpellScriptLoader("spell_sha_bloodlust") { }

        class spell_sha_bloodlust_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_bloodlust_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_SHAMAN_SATED,
                    SPELL_HUNTER_INSANITY,
                    SPELL_MAGE_TEMPORAL_DISPLACEMENT
                });
            }

            void RemoveInvalidTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHAMAN_SATED));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_HUNTER_INSANITY));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_MAGE_TEMPORAL_DISPLACEMENT));
            }

            void ApplyDebuff()
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, SPELL_SHAMAN_SATED, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_2, TARGET_UNIT_CASTER_AREA_RAID);
                AfterHit += SpellHitFn(spell_sha_bloodlust_SpellScript::ApplyDebuff);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_bloodlust_SpellScript();
        }
};

// 1064 - Chain Heal
/// Updated 4.3.4
class spell_sha_chain_heal : public SpellScriptLoader
{
    public:
        spell_sha_chain_heal() : SpellScriptLoader("spell_sha_chain_heal") { }

        class spell_sha_chain_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_chain_heal_SpellScript);

        public:
            spell_sha_chain_heal_SpellScript()
            {
                firstHeal = true;
                riptide = false;
                amount = 0;
            }

        private:
            void HandleHeal(SpellEffIndex /*effIndex*/)
            {
                if (firstHeal)
                {
                    // Check if the target has Riptide
                    if (AuraEffect* aurEff = GetHitUnit()->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_SHAMAN, 0, 0, 0x10, GetCaster()->GetGUID()))
                    {
                        riptide = true;
                        amount = aurEff->GetSpellInfo()->Effects[EFFECT_2].CalcValue();
                        // Consume it
                        GetHitUnit()->RemoveAura(aurEff->GetBase());
                    }
                    firstHeal = false;
                }
                // Riptide increases the Chain Heal effect by 25%
                if (riptide)
                {
                    uint32 bonus = CalculatePct(GetHitHeal(), amount);
                    SetHitHeal(GetHitHeal() + bonus);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_chain_heal_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
            }

            bool firstHeal;
            bool riptide;
            uint32 amount;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_chain_heal_SpellScript();
        }
};

// 974 - Earth Shield
class spell_sha_earth_shield : public SpellScriptLoader
{
    public:
        spell_sha_earth_shield() : SpellScriptLoader("spell_sha_earth_shield") { }

        class spell_sha_earth_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_earth_shield_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_EARTH_SHIELD_HEAL, SPELL_SHAMAN_GLYPH_OF_EARTH_SHIELD });
            }

            void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool & /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster())
                {
                    amount = caster->SpellHealingBonusDone(GetUnitOwner(), GetSpellInfo(), amount, HEAL, aurEff->GetEffIndex());
                    amount = GetUnitOwner()->SpellHealingBonusTaken(caster, GetSpellInfo(), amount, HEAL);

                    //! WORKAROUND
                    // If target is affected by healing reduction, modifier is guaranteed to be negative
                    // value (e.g. -50). To revert the effect, multiply amount with reciprocal of relative value:
                    // (100 / ((-1) * modifier)) * 100 = (-1) * 100 * 100 / modifier = -10000 / modifier
                    if (int32 modifier = GetUnitOwner()->GetMaxNegativeAuraModifier(SPELL_AURA_MOD_HEALING_PCT))
                        ApplyPct(amount, -10000.0f / float(modifier));

                    // Glyph of Earth Shield
                    //! WORKAROUND
                    //! this glyph is a proc
                    if (AuraEffect* glyph = caster->GetAuraEffect(SPELL_SHAMAN_GLYPH_OF_EARTH_SHIELD, EFFECT_0))
                        AddPct(amount, glyph->GetAmount());
                }
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                //! HACK due to currenct proc system implementation
                if (Player* player = GetTarget()->ToPlayer())
                    if (player->GetSpellHistory()->HasCooldown(SPELL_SHAMAN_EARTH_SHIELD_HEAL))
                        return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_EARTH_SHIELD_HEAL, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetTarget(), true, nullptr, aurEff, GetCasterGUID());

                /// @hack: due to currenct proc system implementation
                if (Player* player = GetTarget()->ToPlayer())
                    player->GetSpellHistory()->AddCooldown(SPELL_SHAMAN_EARTH_SHIELD_HEAL, 0, std::chrono::seconds(3));
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_sha_earth_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_DUMMY);
                DoCheckProc += AuraCheckProcFn(spell_sha_earth_shield_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_earth_shield_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_earth_shield_AuraScript();
        }
};

// 6474 - Earthbind Totem - Fix Talent:Earthen Power, Earth's Grasp
/// Updated 4.3.4
class spell_sha_earthbind_totem : public SpellScriptLoader
{
    public:
        spell_sha_earthbind_totem() : SpellScriptLoader("spell_sha_earthbind_totem") { }

        class spell_sha_earthbind_totem_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_earthbind_totem_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_TOTEM_EARTHBIND_TOTEM, SPELL_SHAMAN_TOTEM_EARTHEN_POWER });
            }

            void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
            {
                if (!GetCaster())
                    return;
                if (Player* owner = GetCaster()->GetCharmerOrOwnerPlayerOrPlayerItself())
                    if (AuraEffect* aur = owner->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, 2289, 0))
                        if (roll_chance_i(aur->GetBaseAmount()))
                            GetTarget()->CastSpell((Unit*)nullptr, SPELL_SHAMAN_TOTEM_EARTHEN_POWER, true);
            }

            void Apply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster())
                    return;
                Player* owner = GetCaster()->GetCharmerOrOwnerPlayerOrPlayerItself();
                if (!owner)
                    return;
                // Earth's Grasp
                if (AuraEffect* aurEff = owner->GetAuraEffectOfRankedSpell(SPELL_SHAMAN_STORM_EARTH_AND_FIRE, EFFECT_1))
                {
                    if (roll_chance_i(aurEff->GetAmount()))
                        GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_TOTEM_EARTHBIND_EARTHGRAB, false);
                }
            }

            void Register() override
            {
                 OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_earthbind_totem_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                 OnEffectApply += AuraEffectApplyFn(spell_sha_earthbind_totem_AuraScript::Apply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_earthbind_totem_AuraScript();
        }
};

class EarthenPowerTargetSelector
{
    public:
        EarthenPowerTargetSelector() { }

        bool operator() (WorldObject* target)
        {
            if (!target->ToUnit())
                return true;

            if (!target->ToUnit()->HasAuraWithMechanic(1 << MECHANIC_SNARE))
                return true;

            return false;
        }
};

// 59566 - Earthen Power
class spell_sha_earthen_power : public SpellScriptLoader
{
    public:
        spell_sha_earthen_power() : SpellScriptLoader("spell_sha_earthen_power") { }

        class spell_sha_earthen_power_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_earthen_power_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove_if(EarthenPowerTargetSelector());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_earthen_power_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_earthen_power_SpellScript();
        }
};

// 86185 Feedback
class spell_sha_feedback : public SpellScriptLoader
{
    public:
        spell_sha_feedback() : SpellScriptLoader("spell_sha_feedback") { }

        class spell_sha_feedback_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_feedback_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_ELEMENTAL_MASTERY });
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction(); // will prevent default effect execution
                if (Player* target = GetTarget()->ToPlayer())
                    target->GetSpellHistory()->ModifyCooldown(SPELL_SHAMAN_ELEMENTAL_MASTERY, aurEff->GetBaseAmount());
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_feedback_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_feedback_AuraScript();
        }
};

// 1535 Fire Nova
/// Updated 4.3.4
class spell_sha_fire_nova : public SpellScriptLoader
{
    public:
        spell_sha_fire_nova() : SpellScriptLoader("spell_sha_fire_nova") { }

        class spell_sha_fire_nova_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_fire_nova_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    if (target->HasAura(SPELL_SHAMAN_FLAME_SHOCK))
                    {
                        caster->CastSpell(target, SPELL_SHAMAN_FIRE_NOVA_TRIGGERED_R1, true);
                        target->RemoveAurasDueToSpell(SPELL_SHAMAN_FLAME_SHOCK);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_fire_nova_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_fire_nova_SpellScript();
        }
};

// 8050 -Flame Shock
/// Updated 4.3.4
class spell_sha_flame_shock : public SpellScriptLoader
{
    public:
        spell_sha_flame_shock() : SpellScriptLoader("spell_sha_flame_shock") { }

        class spell_sha_flame_shock_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_flame_shock_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_LAVA_FLOWS_R1, SPELL_SHAMAN_LAVA_FLOWS_TRIGGERED_R1 });
            }

            void HandleDispel(DispelInfo* /*dispelInfo*/)
            {
                if (Unit* caster = GetCaster())
                {
                    // Lava Flows
                    if (AuraEffect const* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_SHAMAN_LAVA_FLOW, EFFECT_0))
                    {
                        if (SpellInfo const* firstRankSpellInfo = sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LAVA_FLOWS_R1))
                            if (!aurEff->GetSpellInfo()->IsRankOf(firstRankSpellInfo))
                                return;

                        int32 basepoints = aurEff->GetAmount();
                        caster->CastCustomSpell(caster, SPELL_SHAMAN_LAVA_FLOWS_TRIGGERED_R1, &basepoints, nullptr, nullptr, true);
                    }
                }
            }

            void Register() override
            {
                AfterDispel += AuraDispelFn(spell_sha_flame_shock_AuraScript::HandleDispel);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_flame_shock_AuraScript();
        }
};

// Updated 4.3.4
// 77794 - Focused Insight
class spell_sha_focused_insight : public SpellScriptLoader
{
    public:
        spell_sha_focused_insight() : SpellScriptLoader("spell_sha_focused_insight") { }

        class spell_sha_focused_insight_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_focused_insight_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_FOCUSED_INSIGHT });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetSpellInfo()->GetCategory() == SHAMAN_SPELL_CATEGORY_SHOCK_SPELLS;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                int32 bp0 = -CalculatePct(eventInfo.GetSpellInfo()->CalcPowerCost(GetUnitOwner(), SpellSchoolMask(eventInfo.GetSpellInfo()->SchoolMask)), aurEff->GetAmount());
                int32 bp1 = aurEff->GetSpellInfo()->Effects[EFFECT_1].CalcValue();

                GetTarget()->CastCustomSpell(GetTarget(), SPELL_SHAMAN_FOCUSED_INSIGHT, &bp0, &bp1, &bp1, true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_focused_insight_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_focused_insight_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_focused_insight_AuraScript();
        }
};

// 55440 - Glyph of Healing Wave
class spell_sha_glyph_of_healing_wave : public SpellScriptLoader
{
    public:
        spell_sha_glyph_of_healing_wave() : SpellScriptLoader("spell_sha_glyph_of_healing_wave") { }

        class spell_sha_glyph_of_healing_wave_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_glyph_of_healing_wave_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                // Not proc from self heals
                return GetTarget() != eventInfo.GetProcTarget();
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 heal = CalculatePct(int32(eventInfo.GetHealInfo()->GetHeal()), aurEff->GetAmount());

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE, SPELLVALUE_BASE_POINT0, heal, (Unit*)nullptr, true, nullptr, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_glyph_of_healing_wave_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_glyph_of_healing_wave_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_glyph_of_healing_wave_AuraScript();
        }
};

// 52041 - Healing Stream Totem
/// Updated 4.3.4
class spell_sha_healing_stream_totem : public SpellScriptLoader
{
    public:
        spell_sha_healing_stream_totem() : SpellScriptLoader("spell_sha_healing_stream_totem") { }

        class spell_sha_healing_stream_totem_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_healing_stream_totem_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                int32 damage = GetEffectValue();
                SpellInfo const* triggeringSpell = GetTriggeringSpell();
                if (Unit* target = GetHitUnit())
                    if (Unit* caster = GetCaster())
                    {
                        if (Unit* owner = caster->GetOwner())
                        {
                            if (triggeringSpell)
                                damage = int32(owner->SpellHealingBonusDone(target, triggeringSpell, damage, HEAL, EFFECT_0));

                            // Soothing Rains
                            if (AuraEffect* dummy = owner->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_SOOTHING_RAIN, EFFECT_0))
                                AddPct(damage, dummy->GetAmount());

                            damage = int32(target->SpellHealingBonusTaken(owner, triggeringSpell, damage, HEAL));
                        }
                        caster->CastCustomSpell(target, SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL, &damage, 0, 0, true, 0, 0, GetOriginalCaster()->GetGUID());
                    }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_healing_stream_totem_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_healing_stream_totem_SpellScript();
        }
};

// 32182 - Heroism
/// Updated 4.3.4
class spell_sha_heroism : public SpellScriptLoader
{
    public:
        spell_sha_heroism() : SpellScriptLoader("spell_sha_heroism") { }

        class spell_sha_heroism_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_heroism_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_SHAMAN_EXHAUSTION,
                    SPELL_HUNTER_INSANITY,
                    SPELL_MAGE_TEMPORAL_DISPLACEMENT
                });
            }

            void RemoveInvalidTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHAMAN_EXHAUSTION));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_HUNTER_INSANITY));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_MAGE_TEMPORAL_DISPLACEMENT));
            }

            void ApplyDebuff()
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, SPELL_SHAMAN_EXHAUSTION, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_heroism_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_heroism_SpellScript::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_heroism_SpellScript::RemoveInvalidTargets, EFFECT_2, TARGET_UNIT_CASTER_AREA_RAID);
                AfterHit += SpellHitFn(spell_sha_heroism_SpellScript::ApplyDebuff);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_heroism_SpellScript();
        }
};

// 23551 - Lightning Shield
class spell_sha_item_lightning_shield : public SpellScriptLoader
{
    public:
        spell_sha_item_lightning_shield() : SpellScriptLoader("spell_sha_item_lightning_shield") { }

        class spell_sha_item_lightning_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_item_lightning_shield_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD });
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_lightning_shield_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_lightning_shield_AuraScript();
        }
};

// 23552 - Lightning Shield
class spell_sha_item_lightning_shield_trigger : public SpellScriptLoader
{
    public:
        spell_sha_item_lightning_shield_trigger() : SpellScriptLoader("spell_sha_item_lightning_shield_trigger") { }

        class spell_sha_item_lightning_shield_trigger_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_item_lightning_shield_trigger_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_ITEM_MANA_SURGE });
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_lightning_shield_trigger_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_lightning_shield_trigger_AuraScript();
        }
};

// 23572 - Mana Surge
class spell_sha_item_mana_surge : public SpellScriptLoader
{
    public:
        spell_sha_item_mana_surge() : SpellScriptLoader("spell_sha_item_mana_surge") { }

        class spell_sha_item_mana_surge_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_item_mana_surge_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE });
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 mana = eventInfo.GetDamageInfo()->GetSpellInfo()->CalcPowerCost(GetTarget(), SpellSchoolMask(eventInfo.GetDamageInfo()->GetSchoolMask()));
                mana = int32(CalculatePct(mana, 35));

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_ITEM_MANA_SURGE, SPELLVALUE_BASE_POINT0, mana, GetTarget(), true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_mana_surge_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_mana_surge_AuraScript();
        }
};

// 70811 - Item - Shaman T10 Elemental 2P Bonus
class spell_sha_item_t10_elemental_2p_bonus : public SpellScriptLoader
{
    public:
        spell_sha_item_t10_elemental_2p_bonus() : SpellScriptLoader("spell_sha_item_t10_elemental_2p_bonus") { }

        class spell_sha_item_t10_elemental_2p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_item_t10_elemental_2p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_ELEMENTAL_MASTERY });
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                if (Player* target = GetTarget()->ToPlayer())
                    target->GetSpellHistory()->ModifyCooldown(SPELL_SHAMAN_ELEMENTAL_MASTERY, -aurEff->GetAmount());
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_t10_elemental_2p_bonus_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_t10_elemental_2p_bonus_AuraScript();
        }
};

// 60103 - Lava Lash
/// Updated 4.3.4
class spell_sha_lava_lash : public SpellScriptLoader
{
    public:
        spell_sha_lava_lash() : SpellScriptLoader("spell_sha_lava_lash") { }

        class spell_sha_lava_lash_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_lava_lash_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Player* caster = GetCaster()->ToPlayer())
                {
                    int32 damage = GetEffectValue();
                    int32 hitDamage = GetHitDamage();
                    if (caster->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND))
                    {
                        // Damage is increased by 25% if your off-hand weapon is enchanted with Flametongue.
                        if (caster->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_SHAMAN, 0x200000, 0, 0))
                            AddPct(hitDamage, damage);
                        SetHitDamage(hitDamage);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_lava_lash_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
            }

        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_lava_lash_SpellScript();
        }
};

class spell_sha_lava_surge : public SpellScriptLoader
{
    public:
        spell_sha_lava_surge() : SpellScriptLoader("spell_sha_lava_surge") { }

        class spell_sha_lava_surge_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_lava_surge_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_LAVA_SURGE });
            }

            void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_LAVA_SURGE, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_lava_surge_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_lava_surge_AuraScript();
        }
};

class spell_sha_lava_surge_proc : public SpellScriptLoader
{
    public:
        spell_sha_lava_surge_proc() : SpellScriptLoader("spell_sha_lava_surge_proc") { }

        class spell_sha_lava_surge_proc_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_lava_surge_proc_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_LAVA_BURST });
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->ToPlayer()->GetSpellHistory()->ResetCooldown(SPELL_SHAMAN_LAVA_BURST, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_lava_surge_proc_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_lava_surge_proc_SpellScript();
        }
};

// 16191 - Mana Tide
/// Updated 4.3.4
class spell_sha_mana_tide_totem : public SpellScriptLoader
{
    public:
        spell_sha_mana_tide_totem() : SpellScriptLoader("spell_sha_mana_tide_totem") { }

        class spell_sha_mana_tide_totem_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_mana_tide_totem_AuraScript);

            void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
            {
                // @TODO: Exclude the "short term" buffs from the stat value
                if (Unit* caster = GetUnitOwner())
                    if (Unit* owner = caster->GetCharmerOrOwner())
                        amount = CalculatePct(owner->GetStat(STAT_SPIRIT), amount);
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_sha_mana_tide_totem_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_STAT);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_mana_tide_totem_AuraScript();
        }
};

// -30881 - Nature's Guardian
class spell_sha_nature_guardian : public SpellScriptLoader
{
    public:
        spell_sha_nature_guardian() : SpellScriptLoader("spell_sha_nature_guardian") { }

        class spell_sha_nature_guardian_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_nature_guardian_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_NATURE_GUARDIAN });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                //! HACK due to currenct proc system implementation
                if (Player* player = GetTarget()->ToPlayer())
                    if (player->GetSpellHistory()->HasCooldown(GetSpellInfo()->Id))
                        return false;

                return GetTarget()->HealthBelowPctDamaged(30, eventInfo.GetDamageInfo()->GetDamage());
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 basePoints0 = GetTarget()->CountPctFromMaxHealth(aurEff->GetAmount());

                GetTarget()->CastCustomSpell(GetTarget(), SPELL_SHAMAN_NATURE_GUARDIAN, &basePoints0, nullptr, nullptr, true);

                if (eventInfo.GetProcTarget() && eventInfo.GetProcTarget()->IsAlive())
                    eventInfo.GetProcTarget()->getThreatManager().modifyThreatPercent(GetTarget(), -10);

                if (Player* player = GetTarget()->ToPlayer())
                    player->GetSpellHistory()->AddCooldown(GetSpellInfo()->Id, 0, std::chrono::seconds(GetSpellInfo()->Effects[EFFECT_1].CalcValue()));
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_nature_guardian_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_nature_guardian_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_nature_guardian_AuraScript();
        }
};

// 88756 - Rolling Thunder
class spell_sha_rolling_thunder : public SpellScriptLoader
{
    public:
        spell_sha_rolling_thunder() : SpellScriptLoader("spell_sha_rolling_thunder") { }

        class spell_sha_rolling_thunder_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_rolling_thunder_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                    {
                        SPELL_SHAMAN_LIGHTNING_SHIELD,
                        SPELL_SHAMAN_FULMINATION_PROC
                    });
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                Unit* target = GetTarget();

                if (Aura* aura = target->GetAura(SPELL_SHAMAN_LIGHTNING_SHIELD))
                {
                    aura->SetCharges(std::min(aura->GetCharges() + 1, aurEff->GetAmount()));
                    aura->RefreshDuration();

                    // Fulmination
                    if (AuraEffect const* fulAurEff = target->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_FULMINATION, EFFECT_0))
                        if (aura->GetCharges() - fulAurEff->GetAmount() > 0)
                            target->CastSpell(GetTarget(), SPELL_SHAMAN_FULMINATION_PROC, true, nullptr, aurEff);

                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_rolling_thunder_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_rolling_thunder_AuraScript();
        }
};

// 82984 - Telluric Currents
class spell_sha_telluric_currents : public SpellScriptLoader
{
    public:
        spell_sha_telluric_currents() : SpellScriptLoader("spell_sha_telluric_currents") { }

        class spell_sha_telluric_currents_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_telluric_currents_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_TELLURIC_CURRENTS });
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 basePoints0 = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount());

                GetUnitOwner()->CastCustomSpell(GetUnitOwner(), SPELL_SHAMAN_TELLURIC_CURRENTS, &basePoints0, 0, 0, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_telluric_currents_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_telluric_currents_AuraScript();
        }
};

// 51490 - Thunderstorm
class spell_sha_thunderstorm : public SpellScriptLoader
{
    public:
        spell_sha_thunderstorm() : SpellScriptLoader("spell_sha_thunderstorm") { }

        class spell_sha_thunderstorm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_thunderstorm_SpellScript);

            void HandleKnockBack(SpellEffIndex effIndex)
            {
                // Glyph of Thunderstorm
                if (GetCaster()->HasAura(SPELL_SHAMAN_GLYPH_OF_THUNDERSTORM))
                    PreventHitDefaultEffect(effIndex);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_thunderstorm_SpellScript::HandleKnockBack, EFFECT_2, SPELL_EFFECT_KNOCK_BACK);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_thunderstorm_SpellScript();
        }
};

// 51562 - Tidal Waves
class spell_sha_tidal_waves : public SpellScriptLoader
{
    public:
        spell_sha_tidal_waves() : SpellScriptLoader("spell_sha_tidal_waves") { }

        class spell_sha_tidal_waves_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_tidal_waves_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_TIDAL_WAVES });
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                int32 basePoints0 = -aurEff->GetAmount();
                int32 basePoints1 = aurEff->GetAmount();

                GetTarget()->CastCustomSpell(GetTarget(), SPELL_SHAMAN_TIDAL_WAVES, &basePoints0, &basePoints1, nullptr, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_tidal_waves_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_tidal_waves_AuraScript();
        }
};

// 38443 - Totemic Mastery (Tier 6 - 2P)
class spell_sha_totemic_mastery : public SpellScriptLoader
{
public:
    spell_sha_totemic_mastery() : SpellScriptLoader("spell_sha_totemic_mastery") { }

    class spell_sha_totemic_mastery_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_totemic_mastery_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHAMAN_TOTEMIC_MASTERY });
        }

        void HandleDummy(AuraEffect const* /*aurEff*/)
        {
            Unit* target = GetTarget();
            for (uint8 i = SUMMON_SLOT_TOTEM; i < MAX_TOTEM_SLOT; ++i)
                if (!target->m_SummonSlot[i])
                    return;

            target->CastSpell(target, SPELL_SHAMAN_TOTEMIC_MASTERY, true);
            PreventDefaultAction();
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_totemic_mastery_AuraScript::HandleDummy, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_totemic_mastery_AuraScript();
    }
};

// 77222 - Elemental Overload
class spell_sha_elemental_overload : public SpellScriptLoader
{
public:
    spell_sha_elemental_overload() : SpellScriptLoader("spell_sha_elemental_overload") { }

    class spell_sha_elemental_overload_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_elemental_overload_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHAMAN_LIGHTNING_BOLT, SPELL_SHAMAN_LIGHTNING_BOLT_TRIGGERED,
                SPELL_SHAMAN_CHAIN_LIGHTNING, SPELL_SHAMAN_CHAIN_LIGHTNING_TRIGGERED,
                SPELL_SHAMAN_LAVA_BURST, SPELL_SHAMAN_LAVA_BURST_TRIGGERED });
        }

        bool CheckProc(ProcEventInfo& /*eventInfo*/)
        {
            return roll_chance_i(GetEffect(EFFECT_0)->GetAmount());
        }

        void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();

            if (Unit* target = eventInfo.GetProcTarget())
            {
                if (Unit* caster = GetCaster())
                {
                    switch (eventInfo.GetProcSpell()->GetSpellInfo()->Id)
                    {
                        case SPELL_SHAMAN_LIGHTNING_BOLT:
                            caster->CastSpell(target, SPELL_SHAMAN_LIGHTNING_BOLT_TRIGGERED, true);
                            break;
                        case SPELL_SHAMAN_CHAIN_LIGHTNING:
                            caster->CastSpell(target, SPELL_SHAMAN_CHAIN_LIGHTNING_TRIGGERED, true);
                            break;
                        case SPELL_SHAMAN_LAVA_BURST:
                            caster->CastSpell(target, SPELL_SHAMAN_LAVA_BURST_TRIGGERED, true);
                            break;
                        default:
                            break;
                    }
                }
            }
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_sha_elemental_overload_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_sha_elemental_overload_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_elemental_overload_AuraScript();
    }
};

// -77829 - Ancestral Resolve
class spell_sha_ancestral_resolve : public SpellScriptLoader
{
    public:
        spell_sha_ancestral_resolve() : SpellScriptLoader("spell_sha_ancestral_resolve") { }

        class sspell_sha_ancestral_resolve_AuraScript : public AuraScript
        {
            PrepareAuraScript(sspell_sha_ancestral_resolve_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                amount = -1;
            }

            void Absorb(AuraEffect* aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                if (Unit* target = GetTarget())
                {
                    if (target->HasUnitState(UNIT_STATE_CASTING))
                        absorbAmount = CalculatePct(dmgInfo.GetDamage(), aurEff->GetBaseAmount());
                    else
                        absorbAmount = 0;
                }
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(sspell_sha_ancestral_resolve_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(sspell_sha_ancestral_resolve_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new sspell_sha_ancestral_resolve_AuraScript();
        }
};

// -16180 - Resourgence
class spell_sha_resurgence : public SpellScriptLoader
{
    public:
        spell_sha_resurgence() : SpellScriptLoader("spell_sha_resurgence") { }

        class spell_sha_resurgence_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_resurgence_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                    {
                        SPELL_SHAMAN_RESURGENCE_ENERGIZE,
                        SPELL_SHAMAN_HEALING_SURGE,
                        SPELL_SHAMAN_RIPTIDE,
                        SPELL_SHAMAN_UNLEASH_LIFE,
                        SPELL_SHAMAN_CHAIN_HEAL,
                        SPELL_SHAMAN_WATER_SHIELD
                    });
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                return GetUnitOwner()->HasAura(SPELL_SHAMAN_WATER_SHIELD);
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                // Calculate the default amount
                int32 baseAmount = sSpellMgr->GetSpellInfo(SPELL_SHAMAN_RESURGENCE_ENERGIZE)->Effects[EFFECT_0].CalcValue(GetTarget());
                baseAmount = CalculatePct(baseAmount, aurEff->GetAmount());

                // Apply extra modifiers for specific spells
                float modifier = 1.0f;
                switch (eventInfo.GetSpellInfo()->Id)
                {
                    case SPELL_SHAMAN_HEALING_SURGE:
                    case SPELL_SHAMAN_RIPTIDE:
                    case SPELL_SHAMAN_UNLEASH_LIFE:
                        modifier = 0.6f;
                        break;
                    case SPELL_SHAMAN_CHAIN_HEAL:
                        modifier = 0.333f;
                        break;
                    default:
                        break;
                }

                int32 bp = ceil(baseAmount * modifier);
                GetTarget()->EnergizeBySpell(GetTarget(), SPELL_SHAMAN_RESURGENCE_ENERGIZE, bp, POWER_MANA);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_resurgence_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_resurgence_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_resurgence_AuraScript();
        }
};

// -16176 - Ancestral Healing
class spell_sha_ancestral_healing : public SpellScriptLoader
{
    public:
        spell_sha_ancestral_healing() : SpellScriptLoader("spell_sha_ancestral_healing") { }

        class spell_sha_ancestral_healing_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_ancestral_healing_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_ANCESTRAL_VIGOR });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (Unit* target = eventInfo.GetHealInfo()->GetTarget())
                {
                    uint32 baseHealth = target->GetMaxHealth();

                    // Do not take previous Ancestral Vigor buffs into account to avoid endless stacking
                    if (Aura* oldVigor = target->GetAura(SPELL_SHAMAN_ANCESTRAL_VIGOR))
                        baseHealth -= oldVigor->GetEffect(EFFECT_0)->GetAmount();

                    int32 bp = std::min(CalculatePct(baseHealth, aurEff->GetAmount()), CalculatePct(eventInfo.GetHealInfo()->GetHeal(), aurEff->GetAmount()));

                    GetUnitOwner()->CastCustomSpell(target, SPELL_SHAMAN_ANCESTRAL_VIGOR, &bp, 0, 0, true, nullptr, aurEff);
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_ancestral_healing_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_ancestral_healing_AuraScript();
        }
};

// 51886 - Cleanse Spirit
class spell_sha_cleanse_spirit : public SpellScriptLoader
{
    public:
        spell_sha_cleanse_spirit() : SpellScriptLoader("spell_sha_cleanse_spirit") { }

        class spell_sha_cleanse_spirit_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_cleanse_spirit_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                    {
                        SPELL_SHAMAN_CLEANSING_WATERS_DUMMY_R1,
                        SPELL_SHAMAN_CLEANSING_WATERS_DUMMY_R2,
                        SPELL_SMAMAN_CLEANSING_WATERS_HEAL_R1,
                        SPELL_SMAMAN_CLEANSING_WATERS_HEAL_R2
                    });
            }

            void HandleDispel(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Player* player = caster->ToPlayer())
                    {
                        if (player->GetSpellHistory()->HasCooldown(SPELL_SMAMAN_CLEANSING_WATERS_HEAL_R1))
                            return;

                        // Cleansing Waters
                        if (AuraEffect* aura = caster->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_CLEANSING_WATERS, EFFECT_0))
                        {
                            switch (aura->GetId())
                            {
                                case SPELL_SHAMAN_CLEANSING_WATERS_DUMMY_R1:
                                    caster->CastSpell(GetHitUnit(), SPELL_SMAMAN_CLEANSING_WATERS_HEAL_R1, true);
                                    break;
                                case SPELL_SHAMAN_CLEANSING_WATERS_DUMMY_R2:
                                    caster->CastSpell(GetHitUnit(), SPELL_SMAMAN_CLEANSING_WATERS_HEAL_R2, true);
                                    break;
                            }

                            // The heal effect may not occur again for 6 seconds
                            player->GetSpellHistory()->AddCooldown(SPELL_SMAMAN_CLEANSING_WATERS_HEAL_R1, 0, std::chrono::seconds(6));
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectSuccessfulDispel += SpellEffectFn(spell_sha_cleanse_spirit_SpellScript::HandleDispel, EFFECT_0, SPELL_EFFECT_DISPEL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_cleanse_spirit_SpellScript();
        }
};

// 73920 - Healing Rain
class spell_sha_healing_rain : public SpellScriptLoader
{
    public:
        spell_sha_healing_rain() : SpellScriptLoader("spell_sha_healing_rain") { }

        class spell_sha_healing_rain_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_healing_rain_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_HEALING_RAIN_TRIGGERED });
            }

            void HandleEffectPeriodic(AuraEffect const* aurEff)
            {
                if (DynamicObject* dyn = GetTarget()->GetDynObject(aurEff->GetId()))
                    GetTarget()->CastSpell(dyn->GetPositionX(), dyn->GetPositionY(), dyn->GetPositionZ(), SPELL_SHAMAN_HEALING_RAIN_TRIGGERED, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_healing_rain_AuraScript::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_healing_rain_AuraScript();
        }
};

// 73921 - Healing Rain Triggered
class spell_sha_healing_rain_triggered : public SpellScriptLoader
{
    public:
        spell_sha_healing_rain_triggered() : SpellScriptLoader("spell_sha_healing_rain_triggered") { }

        class spell_sha_healing_rain_triggered_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_healing_rain_triggered_SpellScript);

            bool Load()
            {
                _targets = 0;
                return true;
            }

            void HandleHeal(SpellEffIndex /*effIndex*/)
            {
                if (GetHitHeal() && _targets > 6)
                    SetHitHeal(GetHitHeal() / _targets);
            }

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                _targets = unitList.size();
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_healing_rain_triggered_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
                OnEffectHitTarget += SpellEffectFn(spell_sha_healing_rain_triggered_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
            }

            uint32 _targets;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_healing_rain_triggered_SpellScript();
        }
};

class spell_sha_earthliving_weapon : public SpellScriptLoader
{
    public:
        spell_sha_earthliving_weapon() : SpellScriptLoader("spell_sha_earthliving_weapon") { }

        class spell_sha_earthliving_weapon_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_earthliving_weapon_AuraScript);

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                // Blessing of the Eternals
                // Increases the default 20% proc chance by additional 40%/80% when healing target is below 35% health
                if (eventInfo.GetHealInfo()->GetTarget() && eventInfo.GetHealInfo()->GetTarget()->HealthBelowPct(35))
                    if (AuraEffect const* aurEff = GetUnitOwner()->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_BLESSING_OF_THE_ETERNALS, EFFECT_1))
                        return roll_chance_i(20 + aurEff->GetBaseAmount());

                // Default Proc Chance is 20%
                return roll_chance_i(20);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_earthliving_weapon_AuraScript::CheckProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_earthliving_weapon_AuraScript();
        }
};

// 10400 - Flametongue Weapon (Passive)
class spell_sha_flametongue_weapon : public AuraScript
{
    PrepareAuraScript(spell_sha_flametongue_weapon);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SHAMAN_FLAMETONGUE_ATTACK,
                SPELL_SHAMAN_FLAMETONGUE_WEAPON
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        Player* player = eventInfo.GetActor()->ToPlayer();
        if (!player)
            return false;

        Item* item = player->GetItemByGuid(GetAura()->GetCastItemGUID());
        if (!item || !item->IsEquipped())
            return false;

        uint8 attType = Player::GetAttackBySlot(item->GetSlot());
        if (attType != BASE_ATTACK && attType != OFF_ATTACK)
            return false;

        if (((attType == BASE_ATTACK) && !(eventInfo.GetTypeMask() & PROC_FLAG_DONE_MAINHAND_ATTACK)) ||
            ((attType == OFF_ATTACK) && !(eventInfo.GetTypeMask() & PROC_FLAG_DONE_OFFHAND_ATTACK)))
            return false;

        return true;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Player* player = eventInfo.GetActor()->ToPlayer();
        Unit* target = eventInfo.GetProcTarget();
        WeaponAttackType attType = BASE_ATTACK;
        if (eventInfo.GetTypeMask() & PROC_FLAG_DONE_OFFHAND_ATTACK)
            attType = OFF_ATTACK;

        Item* item = ASSERT_NOTNULL(player->GetWeaponForAttack(attType));

        SpellInfo const* spell = sSpellMgr->GetSpellInfo(SPELL_SHAMAN_FLAMETONGUE_WEAPON);
        if (!spell)
            return;

        float basePoints = spell->Effects[EFFECT_1].CalcValue(player);
        float attackSpeed = player->GetAttackTime(attType) / 1000.f;
        float fireDamage = basePoints / 100.0f;
        fireDamage *= attackSpeed;

        RoundToInterval(fireDamage, basePoints / 77.0f, basePoints / 25.0f);

        // Calculate Spell Power scaling
        float statBonus = player->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_FIRE);
        statBonus += target->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_DAMAGE_TAKEN, SPELL_SCHOOL_MASK_FIRE);

        float const coeff = 0.03811f;
        statBonus *= coeff * attackSpeed;

        player->CastCustomSpell(SPELL_SHAMAN_FLAMETONGUE_ATTACK, SPELLVALUE_BASE_POINT0, fireDamage + statBonus, target, true, item, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_flametongue_weapon::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_sha_flametongue_weapon::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 33757 - Windfury Weapon (Passive)
class spell_sha_windfury_weapon : public AuraScript
{
    PrepareAuraScript(spell_sha_windfury_weapon);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SHAMAN_WINDFURY_ATTACK_MAINHAND,
                SPELL_SHAMAN_WINDFURY_ATTACK_OFFHAND,
                SPELL_SHAMAN_WINDFURY_WEAPON
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        Player* player = eventInfo.GetActor()->ToPlayer();
        if (!player)
            return false;

        Item* item = player->GetItemByGuid(GetAura()->GetCastItemGUID());
        if (!item || !item->IsEquipped())
            return false;

        uint8 attType = Player::GetAttackBySlot(item->GetSlot());
        if (attType != BASE_ATTACK && attType != OFF_ATTACK)
            return false;

        if (((attType == BASE_ATTACK) && !(eventInfo.GetTypeMask() & PROC_FLAG_DONE_MAINHAND_ATTACK)) ||
            ((attType == OFF_ATTACK) && !(eventInfo.GetTypeMask() & PROC_FLAG_DONE_OFFHAND_ATTACK)))
            return false;

        return true;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Player* player = eventInfo.GetActor()->ToPlayer();
        Unit* target = eventInfo.GetProcTarget();
        WeaponAttackType attType = BASE_ATTACK;
        if (eventInfo.GetTypeMask() & PROC_FLAG_DONE_OFFHAND_ATTACK)
            attType = OFF_ATTACK;

        Item* item = ASSERT_NOTNULL(player->GetWeaponForAttack(attType));

        SpellInfo const* spell = sSpellMgr->GetSpellInfo(SPELL_SHAMAN_WINDFURY_WEAPON);
        if (!spell)
            return;

        int32 attackPower = spell->Effects[EFFECT_1].CalcValue(player);
        int32 amount = static_cast<int32>(attackPower / 14.f * player->GetAttackTime(attType) / 1000.f);
        uint32 spellId = attType == BASE_ATTACK ? SPELL_SHAMAN_WINDFURY_ATTACK_MAINHAND : SPELL_SHAMAN_WINDFURY_ATTACK_OFFHAND;

        for (uint8 i = 0; i < 2; i++)
            player->CastCustomSpell(spellId, SPELLVALUE_BASE_POINT0, amount, target, true, item, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_windfury_weapon::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_sha_windfury_weapon::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_sha_unleash_elements : public SpellScript
{
    PrepareSpellScript(spell_sha_unleash_elements);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SHAMAN_UNLEASH_LIFE,
                SPELL_SHAMAN_UNLEASH_WIND,
                SPELL_SHAMAN_UNLEASH_FROST,
                SPELL_SHAMAN_UNLEASH_FLAME,
                SPELL_SHAMAN_UNLEASH_EARTH,
            });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Player* player = caster->ToPlayer();
        if (!player)
            return;

        uint32 spellId = 0;
        uint32 lastSpellId = 0;

        for (uint8 i = 0; i < 2; i++)
        {
            if (Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND + i))
            {
                switch (item->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT))
                {
                    case SHAMAN_ENCHANTMENT_ID_FLAMETONGUE:
                        spellId = SPELL_SHAMAN_UNLEASH_FLAME;
                        break;
                    case SHAMAN_ENCHANTMENT_ID_FROSTBRAND:
                        spellId = SPELL_SHAMAN_UNLEASH_FROST;
                        break;
                    case SHAMAN_ENCHANTMENT_ID_WINDFURY:
                        spellId = SPELL_SHAMAN_UNLEASH_WIND;
                        break;
                    case SHAMAN_ENCHANTMENT_ID_ROCKBITER:
                        spellId = SPELL_SHAMAN_UNLEASH_EARTH;
                        break;
                    case SHAMAN_ENCHANTMENT_ID_EARTHLIVING:
                        spellId = SPELL_SHAMAN_UNLEASH_LIFE;
                        break;
                    default:
                        break;
                }
            }

            if (spellId && spellId != lastSpellId)
            {
                if (Unit* target = GetExplTargetUnit())
                {
                    if (spellId == SPELL_SHAMAN_UNLEASH_LIFE && !target->IsFriendlyTo(caster))
                        target = caster;

                    caster->CastSpell(target, spellId, true);
                }
            }

            lastSpellId = spellId;
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_unleash_elements::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// -51525 - Static Shock
class spell_sha_static_shock : public AuraScript
{
    PrepareAuraScript(spell_sha_static_shock);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_LIGHTNING_SHIELD_DAMAGE });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetActor()->HasAura(SPELL_SHAMAN_LIGHTNING_SHIELD);
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* caster = eventInfo.GetActor();
        Unit* target = eventInfo.GetProcTarget();

        caster->CastSpell(target, SPELL_SHAMAN_LIGHTNING_SHIELD_DAMAGE, true, nullptr, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_static_shock::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_sha_static_shock::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -63373 - Frozen Power
class spell_sha_frozen_power : public AuraScript
{
    PrepareAuraScript(spell_sha_frozen_power);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_FREEZE });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        if (!roll_chance_i(aurEff->GetAmount()))
            return;

        Unit* caster = eventInfo.GetActor();
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_FREEZE);
        float minDistance(spellInfo->Effects[EFFECT_0].CalcValue(caster));

        Unit* target = eventInfo.GetProcTarget();
        if (caster->GetDistance(target) < minDistance)
            return;

        caster->CastSpell(target, SPELL_SHAMAN_FREEZE, true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_frozen_power::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 95774 - Fulmination
class spell_sha_fulmination : public AuraScript
{
    PrepareAuraScript(spell_sha_fulmination);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SHAMAN_FULMINATION_DAMAGE,
                SPELL_SHAMAN_LIGHTNING_SHIELD_DAMAGE
            });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* caster = GetTarget();

        Unit* target = eventInfo.GetProcSpell()->m_targets.GetUnitTarget();
        if (!target)
            return;

        Aura* lightningShieldAura = caster->GetAura(SPELL_SHAMAN_LIGHTNING_SHIELD);
        if (!lightningShieldAura)
            return;

        AuraEffect const* fulminationEffect = caster->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_FULMINATION, EFFECT_0);
        if (!fulminationEffect)
            return;

        if (uint8 surplousCharges = std::max(0, (lightningShieldAura->GetCharges() - fulminationEffect->GetAmount())))
        {
            if (SpellInfo const* shieldDamageSpell = sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LIGHTNING_SHIELD_DAMAGE))
            {
                lightningShieldAura->SetCharges(fulminationEffect->GetAmount());
                int32 basepoints = (shieldDamageSpell->Effects[EFFECT_0].CalcValue() + caster->SpellDamageBonusDone(target, shieldDamageSpell, 0, SPELL_DIRECT_DAMAGE, EFFECT_0)) * surplousCharges;
                caster->CastCustomSpell(SPELL_SHAMAN_FULMINATION_DAMAGE, SPELLVALUE_BASE_POINT0, basepoints, target, true);
            }
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_fulmination::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

void AddSC_shaman_spell_scripts()
{
    new spell_sha_ancestral_awakening();
    new spell_sha_ancestral_awakening_proc();
    new spell_sha_ancestral_healing();
    new spell_sha_ancestral_resolve();
    new spell_sha_bloodlust();
    new spell_sha_cleanse_spirit();
    new spell_sha_chain_heal();
    new spell_sha_earth_shield();
    new spell_sha_earthbind_totem();
    new spell_sha_earthen_power();
    new spell_sha_earthliving_weapon();
    new spell_sha_elemental_overload();
    new spell_sha_feedback();
    new spell_sha_fire_nova();
    new spell_sha_flame_shock();
    RegisterAuraScript(spell_sha_flametongue_weapon);
    new spell_sha_focused_insight();
    RegisterAuraScript(spell_sha_frozen_power);
    RegisterAuraScript(spell_sha_fulmination);
    new spell_sha_glyph_of_healing_wave();
    new spell_sha_healing_rain();
    new spell_sha_healing_rain_triggered();
    new spell_sha_healing_stream_totem();
    new spell_sha_heroism();
    new spell_sha_item_lightning_shield();
    new spell_sha_item_lightning_shield_trigger();
    new spell_sha_item_mana_surge();
    new spell_sha_item_t10_elemental_2p_bonus();
    new spell_sha_lava_lash();
    new spell_sha_lava_surge();
    new spell_sha_lava_surge_proc();
    new spell_sha_mana_tide_totem();
    new spell_sha_nature_guardian();
    new spell_sha_resurgence();
    new spell_sha_rolling_thunder();
    RegisterAuraScript(spell_sha_static_shock);
    new spell_sha_telluric_currents();
    new spell_sha_thunderstorm();
    new spell_sha_tidal_waves();
    new spell_sha_totemic_mastery();
    RegisterSpellScript(spell_sha_unleash_elements);
    RegisterAuraScript(spell_sha_windfury_weapon);
}
