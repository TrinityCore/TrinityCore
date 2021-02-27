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
    SPELL_SHAMAN_EARTHQUAKE_DAMAGE              = 77478,
    SPELL_SHAMAN_EARTHQUAKE_STUN                = 77505,
    SPELL_SHAMAN_ELEMENTAL_MASTERY              = 16166,
    SPELL_SHAMAN_EXHAUSTION                     = 57723,
    SPELL_SHAMAN_FIRE_NOVA_DAMAGE               = 8349,
    SPELL_SHAMAN_FLAME_SHOCK                    = 8050,
    SPELL_SHAMAN_FLAMETONGUE_ATTACK             = 10444,
    SPELL_SHAMAN_FLAMETONGUE_WEAPON             = 8024,
    SPELL_SHAMAN_FOCUSED_INSIGHT                = 77800,
    SPELL_SHAMAN_FREEZE                         = 63685,
    SPELL_SHAMAN_FULMINATION_PROC               = 95774,
    SPELL_SHAMAN_FULMINATION_DAMAGE             = 88767,
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
    SPELL_SHAMAN_LAVA_LASH_SPREAD_FLAME_SHOCK   = 105792,
    SPELL_SHAMAN_LAVA_SURGE                     = 77762,
    SPELL_SHAMAN_LIGHTNING_BOLT                 = 403,
    SPELL_SHAMAN_LIGHTNING_BOLT_TRIGGERED       = 45284,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD          = 23552,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE   = 27635,
    SPELL_SHAMAN_ITEM_MANA_SURGE                = 23571,
    SPELL_SHAMAN_LIGHTNING_SHIELD               = 324,
    SPELL_SHAMAN_LIGHTNING_SHIELD_DAMAGE        = 26364,
    SPELL_SHAMAN_MAELSTROM_DUMMY                = 60349,
    SPELL_SHAMAN_NATURE_GUARDIAN                = 31616,
    SPELL_SHAMAN_RESURGENCE_ENERGIZE            = 101033,
    SPELL_SHAMAN_RIPTIDE                        = 61295,
    SPELL_SHAMAN_SATED                          = 57724,
    SPELL_SHAMAN_SEARING_FLAMES_DAMAGE          = 77661,
    SPELL_SHAMAN_STORM_EARTH_AND_FIRE           = 51483,
    SPELL_SHAMAN_TELLURIC_CURRENTS              = 82987,
    SPELL_SHAMAN_TOTEM_EARTHBIND_EARTHGRAB      = 64695,
    SPELL_SHAMAN_TOTEM_EARTHBIND_TOTEM          = 6474,
    SPELL_SHAMAN_TOTEM_EARTHEN_POWER            = 59566,
    SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL      = 52042,
    SPELL_SHAMAN_TIDAL_WAVES                    = 53390,
    SPELL_SHAMAN_TOTEMIC_MASTERY                = 38437,
    SPELL_SHAMAN_THUNDERSTORM_SLOW              = 100955,
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
    SHAMAN_ICON_ID_FULMINATION                  = 2010,
    SHAMAN_ICON_ID_GLYPH_OF_LIGHTNING_SHIELD    = 19,
    SHAMAN_ICON_ID_GLYPH_OF_EARTH_SHIELD        = 2015,
    SHAMAN_ICON_ID_SEARING_FLAMES               = 680,
    SHAMAN_ICON_ID_IMPROVED_LAVA_LASH           = 4780
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
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_TIDAL_WAVES });
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 heal = int32(CalculatePct(eventInfo.GetHealInfo()->GetHeal(), aurEff->GetAmount()));

                GetTarget()->CastSpell(nullptr, SPELL_SHAMAN_ANCESTRAL_AWAKENING, CastSpellExtraArgs(aurEff).AddSpellBP0(heal));
            }

            void Register() override
            {
                OnEffectProc.Register(&spell_sha_ancestral_awakening_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
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
                GetCaster()->CastSpell(GetHitUnit(), SPELL_SHAMAN_ANCESTRAL_AWAKENING_PROC, CastSpellExtraArgs(true).AddSpellBP0(GetEffectValue()));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect.Register(&spell_sha_ancestral_awakening_proc_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
                OnEffectHitTarget.Register(&spell_sha_ancestral_awakening_proc_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
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
                OnObjectAreaTargetSelect.Register(&spell_sha_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect.Register(&spell_sha_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect.Register(&spell_sha_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_2, TARGET_UNIT_CASTER_AREA_RAID);
                AfterHit.Register(&spell_sha_bloodlust_SpellScript::ApplyDebuff);
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
                OnEffectHitTarget.Register(&spell_sha_chain_heal_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
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
class spell_sha_earth_shield : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_EARTH_SHIELD_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetTarget();
        int32 basePoints = caster->SpellHealingBonusDone(target, GetSpellInfo(), aurEff->GetAmount(), HEAL, EFFECT_0);
        if (AuraEffect const* glyphEff = caster->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_GLYPH_OF_EARTH_SHIELD, EFFECT_0))
            AddPct(basePoints, glyphEff->GetAmount());

        target->CastSpell(target, SPELL_SHAMAN_EARTH_SHIELD_HEAL, CastSpellExtraArgs(aurEff).SetOriginalCaster(GetCasterGUID()).AddSpellBP0(basePoints));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_sha_earth_shield::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
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
                 OnEffectPeriodic.Register(&spell_sha_earthbind_totem_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                 OnEffectApply.Register(&spell_sha_earthbind_totem_AuraScript::Apply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
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
            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove_if(EarthenPowerTargetSelector());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect.Register(&spell_sha_earthen_power_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
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
                OnEffectProc.Register(&spell_sha_feedback_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_feedback_AuraScript();
        }
};

// 1535 Fire Nova
/// Updated 4.3.4
class spell_sha_fire_nova : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_ELEMENTAL_MASTERY });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Unit* target = GetHitUnit())
                if (target->HasAura(SPELL_SHAMAN_FLAME_SHOCK))
                    caster->CastSpell(target, SPELL_SHAMAN_FIRE_NOVA_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_sha_fire_nova::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 8349 - Fire Nova
class spell_sha_fire_nova_damage : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Unit const* targetUnit = GetExplTargetUnit();

        targets.remove_if([targetUnit](WorldObject const* target)->bool
        {
            return targetUnit == target;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_sha_fire_nova_damage::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
        OnObjectAreaTargetSelect.Register(&spell_sha_fire_nova_damage::FilterTargets, EFFECT_2, TARGET_UNIT_DEST_AREA_ENEMY);
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
                        caster->CastSpell(caster, SPELL_SHAMAN_LAVA_FLOWS_TRIGGERED_R1, CastSpellExtraArgs(true).AddSpellBP0(basepoints));
                    }
                }
            }

            void Register() override
            {
                AfterDispel.Register(&spell_sha_flame_shock_AuraScript::HandleDispel);
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

                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_FOCUSED_INSIGHT, CastSpellExtraArgs(aurEff).AddSpellBP0(bp0).AddSpellMod(SPELLVALUE_BASE_POINT1, bp1).AddSpellMod(SPELLVALUE_BASE_POINT2, bp1));
            }

            void Register() override
            {
                DoCheckProc.Register(&spell_sha_focused_insight_AuraScript::CheckProc);
                OnEffectProc.Register(&spell_sha_focused_insight_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
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

                GetTarget()->CastSpell(nullptr, SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE, CastSpellExtraArgs(aurEff).AddSpellBP0(heal));
            }

            void Register() override
            {
                DoCheckProc.Register(&spell_sha_glyph_of_healing_wave_AuraScript::CheckProc);
                OnEffectProc.Register(&spell_sha_glyph_of_healing_wave_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_glyph_of_healing_wave_AuraScript();
        }
};

// 52041 - Healing Stream Totem
/// Updated 4.3.4
class spell_sha_healing_stream_totem : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        SpellInfo const* triggeringSpell = GetTriggeringSpell();
        if (!caster || !triggeringSpell)
            return;

        Unit* target = GetHitUnit();

        int32 bp = triggeringSpell->Effects[EFFECT_0].CalcValue(caster);
        bp = caster->SpellHealingBonusDone(target, triggeringSpell, bp, HEAL, EFFECT_0);
        if (AuraEffect* dummy = caster->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_SOOTHING_RAIN, EFFECT_0))
            AddPct(bp, dummy->GetAmount());

        caster->CastSpell(GetHitUnit(), SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL, CastSpellExtraArgs(caster->GetCreatorGUID()).AddSpellBP0(bp));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_sha_healing_stream_totem::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
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
                OnObjectAreaTargetSelect.Register(&spell_sha_heroism_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect.Register(&spell_sha_heroism_SpellScript::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect.Register(&spell_sha_heroism_SpellScript::RemoveInvalidTargets, EFFECT_2, TARGET_UNIT_CASTER_AREA_RAID);
                AfterHit.Register(&spell_sha_heroism_SpellScript::ApplyDebuff);
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
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD });
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD, aurEff);
            }

            void Register() override
            {
                OnEffectProc.Register(&spell_sha_item_lightning_shield_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
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
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_ITEM_MANA_SURGE });
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE, aurEff);
            }

            void Register() override
            {
                OnEffectProc.Register(&spell_sha_item_lightning_shield_trigger_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
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
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE });
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 mana = eventInfo.GetDamageInfo()->GetSpellInfo()->CalcPowerCost(GetTarget(), SpellSchoolMask(eventInfo.GetDamageInfo()->GetSchoolMask()));
                mana = int32(CalculatePct(mana, 35));

                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_ITEM_MANA_SURGE, CastSpellExtraArgs(aurEff).AddSpellBP0(mana));
            }

            void Register() override
            {
                OnEffectProc.Register(&spell_sha_item_mana_surge_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
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
                OnEffectProc.Register(&spell_sha_item_t10_elemental_2p_bonus_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_t10_elemental_2p_bonus_AuraScript();
        }
};

// 60103 - Lava Lash
/// Updated 4.3.4
class spell_sha_lava_lash : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SHAMAN_SEARING_FLAMES_DAMAGE,
                SPELL_SHAMAN_LAVA_LASH_SPREAD_FLAME_SHOCK,
                SPELL_SHAMAN_FLAME_SHOCK
            });
    }

    void HandleDamageBonus(SpellEffIndex /*effIndex*/)
    {
        Player* caster = GetCaster()->ToPlayer();
        Unit* target = GetHitUnit();
        if (!target || !caster)
            return;

        int32 bonusDamage = 0;

        // Increase damage of lava lash by 40% if the offhand weapon is enchanted with Flametongue
        if (Item* offhand = caster->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND))
            if (offhand->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == SHAMAN_ENCHANTMENT_ID_FLAMETONGUE)
                bonusDamage += GetSpellInfo()->Effects[EFFECT_1].CalcValue(caster);

        // Improved Lava Lash
        if (AuraEffect const* bonusAura = caster->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_IMPROVED_LAVA_LASH, EFFECT_1))
        {
            if (Aura* aura = target->GetAura(SPELL_SHAMAN_SEARING_FLAMES_DAMAGE, caster->GetGUID()))
            {
                bonusDamage += bonusAura->GetAmount() * aura->GetStackAmount();
                aura->Remove();
            }

            if (target->HasAura(SPELL_SHAMAN_FLAME_SHOCK, caster->GetGUID()))
                caster->CastSpell(target, SPELL_SHAMAN_LAVA_LASH_SPREAD_FLAME_SHOCK, CastSpellExtraArgs(bonusAura).AddSpellMod(SPELLVALUE_MAX_TARGETS, 4));
        }
        SetEffectValue(GetEffectValue() + bonusDamage);
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_sha_lava_lash::HandleDamageBonus, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
    }
};

class spell_sha_lava_lash_script : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_FLAME_SHOCK });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if([this](WorldObject const* obj)->bool
            {
                Unit const* target = obj->ToUnit();

                if (!target || obj == GetExplTargetUnit())
                    return true;

                if (target->HasAura(SPELL_SHAMAN_FLAME_SHOCK, GetCaster()->GetGUID()))
                    return true;

                return target->HasBreakableByDamageCrowdControlAura();
            });

        if (targets.size() > 4)
            targets.resize(4);
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* spellTarget = GetExplTargetUnit();
        if (!caster || !spellTarget)
            return;

        if (Aura* flameshock = spellTarget->GetAura(SPELL_SHAMAN_FLAME_SHOCK, caster->GetGUID()))
            if (Aura* spread = caster->AddAura(SPELL_SHAMAN_FLAME_SHOCK, GetHitUnit()))
                spread->SetDuration(flameshock->GetDuration());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_sha_lava_lash_script::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_sha_lava_lash_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// -77755 - Lava Surge
class spell_sha_lava_surge : public AuraScript
{
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
        OnEffectProc.Register(&spell_sha_lava_surge::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_sha_lava_surge_proc : public SpellScript
{
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
        OnEffectHitTarget.Register(&spell_sha_lava_surge_proc::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
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
            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                // @TODO: Exclude the "short term" buffs from the stat value
                if (Unit* caster = GetUnitOwner())
                    if (Unit* owner = caster->GetCharmerOrOwner())
                        amount = CalculatePct(owner->GetStat(STAT_SPIRIT), amount);
            }

            void Register() override
            {
                DoEffectCalcAmount.Register(&spell_sha_mana_tide_totem_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_STAT);
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

                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_NATURE_GUARDIAN, CastSpellExtraArgs(true).AddSpellBP0(basePoints0));

                if (eventInfo.GetProcTarget() && eventInfo.GetProcTarget()->IsAlive())
                    eventInfo.GetProcTarget()->GetThreatManager().ModifyThreatByPercent(GetTarget(), -10);

                if (Player* player = GetTarget()->ToPlayer())
                    player->GetSpellHistory()->AddCooldown(GetSpellInfo()->Id, 0, std::chrono::seconds(GetSpellInfo()->Effects[EFFECT_1].CalcValue()));
            }

            void Register() override
            {
                DoCheckProc.Register(&spell_sha_nature_guardian_AuraScript::CheckProc);
                OnEffectProc.Register(&spell_sha_nature_guardian_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_nature_guardian_AuraScript();
        }
};

// -88756 - Rolling Thunder
class spell_sha_rolling_thunder : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SHAMAN_LIGHTNING_SHIELD,
                SPELL_SHAMAN_FULMINATION_PROC
            });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        return GetTarget()->HasAura(SPELL_SHAMAN_LIGHTNING_SHIELD);
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        Unit* target = GetTarget();

        if (Aura* aura = target->GetAura(SPELL_SHAMAN_LIGHTNING_SHIELD))
        {
            uint8 charges = std::min(aura->GetCharges() + 1, aurEff->GetAmount());
            aura->SetCharges(charges);
            aura->RefreshDuration();

            // Fulmination visual
            if (target->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_FULMINATION, EFFECT_0))
                if (charges == aurEff->GetAmount())
                    target->CastSpell(GetTarget(), SPELL_SHAMAN_FULMINATION_PROC, aurEff);
        }
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_sha_rolling_thunder::CheckProc);
        OnEffectProc.Register(&spell_sha_rolling_thunder::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 82984 - Telluric Currents
class spell_sha_telluric_currents : public SpellScriptLoader
{
    public:
        spell_sha_telluric_currents() : SpellScriptLoader("spell_sha_telluric_currents") { }

        class spell_sha_telluric_currents_AuraScript : public AuraScript
        {
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_TELLURIC_CURRENTS });
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 basePoints0 = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount());

                GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_SHAMAN_TELLURIC_CURRENTS, CastSpellExtraArgs(aurEff).AddSpellBP0(basePoints0));
            }

            void Register() override
            {
                OnEffectProc.Register(&spell_sha_telluric_currents_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_telluric_currents_AuraScript();
        }
};

// 51490 - Thunderstorm
class spell_sha_thunderstorm : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_THUNDERSTORM_SLOW });
    }

    void HandleKnockBack(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        // Glyph of Thunderstorm
        if (caster->HasAura(SPELL_SHAMAN_GLYPH_OF_THUNDERSTORM))
        {
            PreventHitDefaultEffect(effIndex);
            return;
        }

        caster->CastSpell(GetHitUnit(), SPELL_SHAMAN_THUNDERSTORM_SLOW);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_sha_thunderstorm::HandleKnockBack, EFFECT_2, SPELL_EFFECT_KNOCK_BACK);
    }
};

// 51562 - Tidal Waves
class spell_sha_tidal_waves : public SpellScriptLoader
{
    public:
        spell_sha_tidal_waves() : SpellScriptLoader("spell_sha_tidal_waves") { }

        class spell_sha_tidal_waves_AuraScript : public AuraScript
        {
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_TIDAL_WAVES });
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                int32 basePoints0 = -aurEff->GetAmount();
                int32 basePoints1 = aurEff->GetAmount();

                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_TIDAL_WAVES, CastSpellExtraArgs(aurEff).AddSpellBP0(basePoints0).AddSpellMod(SPELLVALUE_BASE_POINT1, basePoints1));
            }

            void Register() override
            {
                OnEffectProc.Register(&spell_sha_tidal_waves_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
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
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHAMAN_TOTEMIC_MASTERY });
        }

        void HandleDummy(AuraEffect const* /*aurEff*/)
        {
            Unit* target = GetTarget();
            for (uint8 i = SUMMON_SLOT_TOTEM_FIRE; i < MAX_TOTEM_SLOT; ++i)
                if (!target->m_SummonSlot[i])
                    return;

            target->CastSpell(target, SPELL_SHAMAN_TOTEMIC_MASTERY, true);
            PreventDefaultAction();
        }

        void Register() override
        {
            OnEffectPeriodic.Register(&spell_sha_totemic_mastery_AuraScript::HandleDummy, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_totemic_mastery_AuraScript();
    }
};

// 77222 - Elemental Overload
class spell_sha_elemental_overload : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SHAMAN_LIGHTNING_BOLT,
                SPELL_SHAMAN_LIGHTNING_BOLT_TRIGGERED,
                SPELL_SHAMAN_CHAIN_LIGHTNING,
                SPELL_SHAMAN_CHAIN_LIGHTNING_TRIGGERED,
                SPELL_SHAMAN_LAVA_BURST,
                SPELL_SHAMAN_LAVA_BURST_TRIGGERED
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (!eventInfo.GetSpellInfo())
            return false;

        if (eventInfo.GetSpellInfo()->Id == SPELL_SHAMAN_CHAIN_LIGHTNING)
            return roll_chance_i(CalculatePct(GetEffect(EFFECT_0)->GetAmount(), 33));

        return roll_chance_i(GetEffect(EFFECT_0)->GetAmount());
    }

    void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        if (Unit* target = eventInfo.GetProcTarget())
        {
            if (Unit* caster = GetCaster())
            {
                switch (eventInfo.GetSpellInfo()->Id)
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
        DoCheckProc.Register(&spell_sha_elemental_overload::CheckProc);
        OnEffectProc.Register(&spell_sha_elemental_overload::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -77829 - Ancestral Resolve
class spell_sha_ancestral_resolve : public SpellScriptLoader
{
    public:
        spell_sha_ancestral_resolve() : SpellScriptLoader("spell_sha_ancestral_resolve") { }

        class sspell_sha_ancestral_resolve_AuraScript : public AuraScript
        {
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
                DoEffectCalcAmount.Register(&sspell_sha_ancestral_resolve_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb.Register(&sspell_sha_ancestral_resolve_AuraScript::Absorb, EFFECT_0);
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
                DoCheckProc.Register(&spell_sha_resurgence_AuraScript::CheckProc);
                OnEffectProc.Register(&spell_sha_resurgence_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
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
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_ANCESTRAL_VIGOR });
            }

            void HandleAncestralFortitude(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                if (!(eventInfo.GetHitMask() & PROC_HIT_CRITICAL))
                    PreventDefaultAction();
            }

            void HandleAncestralVigor(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (Unit* target = eventInfo.GetHealInfo()->GetTarget())
                {
                    int32 healBonus = CalculatePct(eventInfo.GetHealInfo()->GetHeal(), aurEff->GetAmount());
                    int32 healthCap = CalculatePct(target->GetMaxHealth(), 10);

                    if (Aura* oldVigor = target->GetAura(SPELL_SHAMAN_ANCESTRAL_VIGOR, GetTarget()->GetGUID()))
                        healBonus += oldVigor->GetEffect(EFFECT_0)->GetAmount();

                    healBonus = std::min(healBonus, healthCap);

                    GetUnitOwner()->CastSpell(target, SPELL_SHAMAN_ANCESTRAL_VIGOR, CastSpellExtraArgs(aurEff).AddSpellBP0(healBonus));
                }
            }

            void Register() override
            {
                OnEffectProc.Register(&spell_sha_ancestral_healing_AuraScript::HandleAncestralFortitude, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
                OnEffectProc.Register(&spell_sha_ancestral_healing_AuraScript::HandleAncestralVigor, EFFECT_1, SPELL_AURA_DUMMY);
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
                OnEffectSuccessfulDispel.Register(&spell_sha_cleanse_spirit_SpellScript::HandleDispel, EFFECT_0, SPELL_EFFECT_DISPEL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_cleanse_spirit_SpellScript();
        }
};

// 8042 - Earth Shock
class spell_sha_earth_shock : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SHAMAN_LIGHTNING_SHIELD,
                SPELL_SHAMAN_FULMINATION_DAMAGE,
                SPELL_SHAMAN_FULMINATION_PROC,
                SPELL_SHAMAN_LIGHTNING_SHIELD_DAMAGE
            });
    }

    void HandleFulmination(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!target)
            return;

        if (AuraEffect const* fulminationEffect = caster->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_FULMINATION, EFFECT_0))
        {
            if (Aura* lightningShieldAura = caster->GetAura(SPELL_SHAMAN_LIGHTNING_SHIELD, caster->GetGUID()))
            {
                uint8 surplousCharges = std::max<int8>(0, lightningShieldAura->GetCharges() - fulminationEffect->GetAmount());
                if (surplousCharges)
                {
                    SpellInfo const* lightningShieldSpell = sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_LIGHTNING_SHIELD_DAMAGE);
                    lightningShieldAura->SetCharges(fulminationEffect->GetAmount());

                    int32 bp = lightningShieldSpell->Effects[EFFECT_0].CalcValue(caster, nullptr, target);
                    bp = caster->SpellDamageBonusDone(target, lightningShieldSpell, bp, SPELL_DIRECT_DAMAGE, EFFECT_0);
                    bp *= surplousCharges;

                    caster->CastSpell(target, SPELL_SHAMAN_FULMINATION_DAMAGE, CastSpellExtraArgs(true).AddSpellBP0(bp));
                    caster->RemoveAurasDueToSpell(SPELL_SHAMAN_FULMINATION_PROC);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_sha_earth_shock::HandleFulmination, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 73920 - Healing Rain
class spell_sha_healing_rain : public SpellScriptLoader
{
    public:
        spell_sha_healing_rain() : SpellScriptLoader("spell_sha_healing_rain") { }

        class spell_sha_healing_rain_AuraScript : public AuraScript
        {
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_HEALING_RAIN_TRIGGERED });
            }

            void HandleEffectPeriodic(AuraEffect const* aurEff)
            {
                if (DynamicObject* dyn = GetTarget()->GetDynObject(aurEff->GetId()))
                    GetTarget()->CastSpell({ dyn->GetPositionX(), dyn->GetPositionY(), dyn->GetPositionZ() }, SPELL_SHAMAN_HEALING_RAIN_TRIGGERED, true);
            }

            void Register() override
            {
                OnEffectPeriodic.Register(&spell_sha_healing_rain_AuraScript::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_healing_rain_AuraScript();
        }
};

// 73921 - Healing Rain Triggered
class spell_sha_healing_rain_triggered : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        _targets = unitList.size();
    }

    void HandleHeal(SpellEffIndex /*effIndex*/)
    {
        if (GetHitHeal() && _targets > 6)
            SetHitHeal((GetHitHeal() * 6) / _targets);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_sha_healing_rain_triggered::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        OnEffectHitTarget.Register(&spell_sha_healing_rain_triggered::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
    }
private:
    uint8 _targets = 0;
};

class spell_sha_earthliving_weapon : public SpellScriptLoader
{
    public:
        spell_sha_earthliving_weapon() : SpellScriptLoader("spell_sha_earthliving_weapon") { }

        class spell_sha_earthliving_weapon_AuraScript : public AuraScript
        {
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
                DoCheckProc.Register(&spell_sha_earthliving_weapon_AuraScript::CheckProc);
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

        player->CastSpell(target, SPELL_SHAMAN_FLAMETONGUE_ATTACK, CastSpellExtraArgs(aurEff).SetCastItem(item).AddSpellBP0(fireDamage + statBonus));
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_sha_flametongue_weapon::CheckProc);
        OnEffectProc.Register(&spell_sha_flametongue_weapon::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 33757 - Windfury Weapon (Passive)
class spell_sha_windfury_weapon : public AuraScript
{
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

        for (uint8 i = 0; i < 3; i++)
            player->CastSpell(target, spellId, CastSpellExtraArgs(aurEff).SetCastItem(item).AddSpellBP0(amount));
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_sha_windfury_weapon::CheckProc);
        OnEffectProc.Register(&spell_sha_windfury_weapon::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_sha_unleash_elements : public SpellScript
{
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
        OnEffectHitTarget.Register(&spell_sha_unleash_elements::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// -51525 - Static Shock
class spell_sha_static_shock : public AuraScript
{
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

        caster->CastSpell(target, SPELL_SHAMAN_LIGHTNING_SHIELD_DAMAGE, aurEff);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_sha_static_shock::CheckProc);
        OnEffectProc.Register(&spell_sha_static_shock::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -63373 - Frozen Power
class spell_sha_frozen_power : public AuraScript
{
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

        caster->CastSpell(target, SPELL_SHAMAN_FREEZE, aurEff);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_sha_frozen_power::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 61882 - Earthquake
class spell_sha_earthquake : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_EARTHQUAKE_DAMAGE });
    }

    void HandleDummyTick(AuraEffect const* aurEff)
    {
        if (DynamicObject* dyn = GetTarget()->GetDynObject(aurEff->GetId()))
            GetTarget()->CastSpell({ dyn->GetPositionX(), dyn->GetPositionY(), dyn->GetPositionZ() }, SPELL_SHAMAN_EARTHQUAKE_DAMAGE, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_sha_earthquake::HandleDummyTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 77478 - Earthquake
class spell_sha_earthquake_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_EARTHQUAKE_STUN });
    }

    void HandleKnockdown(SpellEffIndex effIndex)
    {
        if (roll_chance_i(GetSpellInfo()->Effects[effIndex].BasePoints))
            if (Unit* caster = GetCaster())
                caster->CastSpell(GetHitUnit(), SPELL_SHAMAN_EARTHQUAKE_STUN, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_sha_earthquake_damage::HandleKnockdown, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 324 - Lightning Shield
class spell_sha_lightning_shield : public AuraScript
{
    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        if (GetTarget()->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_GLYPH_OF_LIGHTNING_SHIELD, EFFECT_0))
            if (GetCharges() < 3)
                SetCharges(3);
    }

    void Register() override
    {
        AfterEffectProc.Register(&spell_sha_lightning_shield::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

class spell_sha_searing_bolt : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_SEARING_FLAMES_DAMAGE });
    }

    void HandleSearingFlames(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Unit* owner = caster->GetOwner())
            if (AuraEffect const* effect = owner->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_SEARING_FLAMES, EFFECT_0))
                if (roll_chance_i(effect->GetAmount()))
                    owner->CastSpell(GetHitUnit(), SPELL_SHAMAN_SEARING_FLAMES_DAMAGE, effect);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_sha_searing_bolt::HandleSearingFlames, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 53817 - Maelstrom Weapon
class spell_sha_maelstrom_weapon : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_MAELSTROM_DUMMY });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetStackAmount() == GetSpellInfo()->StackAmount)
            GetTarget()->CastSpell(nullptr, SPELL_SHAMAN_MAELSTROM_DUMMY);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_SHAMAN_MAELSTROM_DUMMY, GetTarget()->GetGUID());
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_sha_maelstrom_weapon::AfterApply, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        AfterEffectRemove.Register(&spell_sha_maelstrom_weapon::AfterRemove, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
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
    RegisterSpellScript(spell_sha_earth_shield);
    RegisterSpellScript(spell_sha_earth_shock);
    new spell_sha_earthbind_totem();
    new spell_sha_earthen_power();
    new spell_sha_earthliving_weapon();
    RegisterSpellScript(spell_sha_earthquake);
    RegisterSpellScript(spell_sha_earthquake_damage);
    RegisterSpellScript(spell_sha_elemental_overload);
    new spell_sha_feedback();
    RegisterSpellScript(spell_sha_fire_nova);
    RegisterSpellScript(spell_sha_fire_nova_damage);
    new spell_sha_flame_shock();
    RegisterSpellScript(spell_sha_flametongue_weapon);
    new spell_sha_focused_insight();
    RegisterSpellScript(spell_sha_frozen_power);
    new spell_sha_glyph_of_healing_wave();
    new spell_sha_healing_rain();
    RegisterSpellScript(spell_sha_healing_rain_triggered);
    RegisterSpellScript(spell_sha_healing_stream_totem);
    new spell_sha_heroism();
    new spell_sha_item_lightning_shield();
    new spell_sha_item_lightning_shield_trigger();
    new spell_sha_item_mana_surge();
    new spell_sha_item_t10_elemental_2p_bonus();
    RegisterSpellScript(spell_sha_lava_lash);
    RegisterSpellScript(spell_sha_lava_lash_script);
    RegisterSpellScript(spell_sha_lava_surge);
    RegisterSpellScript(spell_sha_lava_surge_proc);
    RegisterSpellScript(spell_sha_lightning_shield);
    RegisterSpellScript(spell_sha_maelstrom_weapon);
    new spell_sha_mana_tide_totem();
    new spell_sha_nature_guardian();
    new spell_sha_resurgence();
    RegisterSpellScript(spell_sha_rolling_thunder);
    RegisterSpellScript(spell_sha_searing_bolt);
    RegisterSpellScript(spell_sha_static_shock);
    new spell_sha_telluric_currents();
    RegisterSpellScript(spell_sha_thunderstorm);
    new spell_sha_tidal_waves();
    new spell_sha_totemic_mastery();
    RegisterSpellScript(spell_sha_unleash_elements);
    RegisterSpellScript(spell_sha_windfury_weapon);
}
