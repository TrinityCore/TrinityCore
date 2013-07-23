/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "Player.h"
#include "ScriptMgr.h"
#include "GridNotifiers.h"
#include "Unit.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum ShamanSpells
{
    SPELL_HUNTER_INSANITY                       = 95809,
    SPELL_MAGE_TEMPORAL_DISPLACEMENT            = 80354,
    SPELL_SHAMAN_ANCESTRAL_AWAKENING            = 52759,
    SPELL_SHAMAN_ANCESTRAL_AWAKENING_PROC       = 52752,
    SPELL_SHAMAN_BIND_SIGHT                     = 6277,
    SPELL_SHAMAN_EARTH_SHIELD_HEAL              = 379,
    SPELL_SHAMAN_ELEMENTAL_MASTERY              = 16166,
    SPELL_SHAMAN_EXHAUSTION                     = 57723,
    SPELL_SHAMAN_FIRE_NOVA_TRIGGERED_R1         = 8349,
    SPELL_SHAMAN_FLAME_SHOCK                    = 8050,
    SPELL_SHAMAN_FOCUSED_INSIGHT                = 77800,
    SPELL_SHAMAN_GLYPH_OF_EARTH_SHIELD          = 63279,
    SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM  = 55456,
    SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE          = 55533,
    SPELL_SHAMAN_GLYPH_OF_MANA_TIDE             = 55441,
    SPELL_SHAMAN_GLYPH_OF_THUNDERSTORM          = 62132,
    SPELL_SHAMAN_LAVA_BURST                     = 51505,
    SPELL_SHAMAN_LAVA_FLOWS_R1                  = 51480,
    SPELL_SHAMAN_LAVA_FLOWS_TRIGGERED_R1        = 65264,
    SPELL_SHAMAN_LAVA_SURGE                     = 77762,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD          = 23552,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE   = 27635,
    SPELL_SHAMAN_ITEM_MANA_SURGE                = 23571,
    SPELL_SHAMAN_LIGHTNING_SHIELD               = 324,
    SPELL_SHAMAN_NATURE_GUARDIAN                = 31616,
    SPELL_SHAMAN_SATED                          = 57724,
    SPELL_SHAMAN_STORM_EARTH_AND_FIRE           = 51483,
    SPELL_SHAMAN_TELLURIC_CURRENTS              = 82987,
    SPELL_SHAMAN_TOTEM_EARTHBIND_EARTHGRAB      = 64695,
    SPELL_SHAMAN_TOTEM_EARTHBIND_TOTEM          = 6474,
    SPELL_SHAMAN_TOTEM_EARTHEN_POWER            = 59566,
    SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL      = 52042,
    SPELL_SHAMAN_TIDAL_WAVES                    = 53390
};

enum ShamanSpellIcons
{
    SHAMAN_ICON_ID_SOOTHING_RAIN                = 2011,
    SHAMAN_ICON_ID_SHAMAN_LAVA_FLOW             = 3087
};

// -51556 - Ancestral Awakening
class spell_sha_ancestral_awakening : public SpellScriptLoader
{
    public:
        spell_sha_ancestral_awakening() : SpellScriptLoader("spell_sha_ancestral_awakening") { }

        class spell_sha_ancestral_awakening_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_ancestral_awakening_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TIDAL_WAVES))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 heal = CalculatePct(int32(eventInfo.GetHealInfo()->GetHeal()), aurEff->GetAmount());

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_ANCESTRAL_AWAKENING, SPELLVALUE_BASE_POINT0, heal, (Unit*)NULL, true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_ancestral_awakening_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ANCESTRAL_AWAKENING_PROC))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastCustomSpell(SPELL_SHAMAN_ANCESTRAL_AWAKENING_PROC, SPELLVALUE_BASE_POINT0, GetEffectValue(), GetHitUnit(), true);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_ancestral_awakening_proc_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_SATED))
                    return false;
                return true;
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

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_2, TARGET_UNIT_CASTER_AREA_RAID);
                AfterHit += SpellHitFn(spell_sha_bloodlust_SpellScript::ApplyDebuff);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            bool Load() OVERRIDE
            {
                firstHeal = true;
                riptide = false;
                amount = 0;
                return true;
            }

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

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_chain_heal_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
            }

            bool firstHeal;
            bool riptide;
            uint32 amount;
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_sha_chain_heal_SpellScript();
        }
};

// -974 - Earth Shield
class spell_sha_earth_shield : public SpellScriptLoader
{
    public:
        spell_sha_earth_shield() : SpellScriptLoader("spell_sha_earth_shield") { }

        class spell_sha_earth_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_earth_shield_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_EARTH_SHIELD_HEAL) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_GLYPH_OF_EARTH_SHIELD))
                    return false;
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool & /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster())
                {
                    amount = caster->SpellHealingBonusDone(GetUnitOwner(), GetSpellInfo(), amount, HEAL);
                    amount = GetUnitOwner()->SpellHealingBonusTaken(caster, GetSpellInfo(), amount, HEAL);

                    // Glyph of Earth Shield
                    //! WORKAROUND
                    //! this glyph is a proc
                    if (AuraEffect* glyph = caster->GetAuraEffect(SPELL_SHAMAN_GLYPH_OF_EARTH_SHIELD, EFFECT_0))
                        AddPct(amount, glyph->GetAmount());
                }
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();

                //! HACK due to currenct proc system implementation
                if (Player* player = GetTarget()->ToPlayer())
                    if (player->HasSpellCooldown(SPELL_SHAMAN_EARTH_SHIELD_HEAL))
                        return;

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_EARTH_SHIELD_HEAL, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetTarget(), true, NULL, aurEff, GetCasterGUID());

                if (Player* player = GetTarget()->ToPlayer())
                    player->AddSpellCooldown(SPELL_SHAMAN_EARTH_SHIELD_HEAL, 0, time(NULL) + 3);
            }

            void Register() OVERRIDE
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_sha_earth_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_DUMMY);
                OnEffectProc += AuraEffectProcFn(spell_sha_earth_shield_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TOTEM_EARTHBIND_TOTEM) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TOTEM_EARTHEN_POWER))
                    return false;
                return true;
            }

            void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
            {
                if (!GetCaster())
                    return;
                if (Player* owner = GetCaster()->GetCharmerOrOwnerPlayerOrPlayerItself())
                    if (AuraEffect* aur = owner->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, 2289, 0))
                        if (roll_chance_i(aur->GetBaseAmount()))
                            GetTarget()->CastSpell((Unit*)NULL, SPELL_SHAMAN_TOTEM_EARTHEN_POWER, true);
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

            void Register() OVERRIDE
            {
                 OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_earthbind_totem_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                 OnEffectApply += AuraEffectApplyFn(spell_sha_earthbind_totem_AuraScript::Apply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_earthen_power_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ELEMENTAL_MASTERY))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction(); // will prevent default effect execution
                if (Player* target = GetTarget()->ToPlayer())
                    target->ModifySpellCooldown(SPELL_SHAMAN_ELEMENTAL_MASTERY, aurEff->GetBaseAmount());
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_feedback_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_fire_nova_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LAVA_FLOWS_R1) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LAVA_FLOWS_TRIGGERED_R1))
                    return false;
                return true;
            }

            void HandleDispel(DispelInfo* /*dispelInfo*/)
            {
                if (Unit* caster = GetCaster())
                {
                    // Lava Flows
                    if (AuraEffect const* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_SHAMAN_LAVA_FLOW, EFFECT_0))
                    {
                        SpellInfo const* firstRankSpellInfo = sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LAVA_FLOWS_R1);
                        if (!aurEff->GetSpellInfo()->IsRankOf(firstRankSpellInfo))
                            return;

                        int32 basepoints = aurEff->GetAmount();
                        caster->CastCustomSpell(caster, SPELL_SHAMAN_LAVA_FLOWS_TRIGGERED_R1, &basepoints, NULL, NULL, true);
                    }
                }
            }

            void Register() OVERRIDE
            {
                AfterDispel += AuraDispelFn(spell_sha_flame_shock_AuraScript::HandleDispel);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_sha_flame_shock_AuraScript();
        }
};

// 77794 - Focused Insight
class spell_sha_focused_insight : public SpellScriptLoader
{
    public:
        spell_sha_focused_insight() : SpellScriptLoader("spell_sha_focused_insight") { }

        class spell_sha_focused_insight_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_focused_insight_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_FOCUSED_INSIGHT))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                int32 basePoints0 = aurEff->GetAmount();
                int32 basePoints1 = aurEff->GetSpellInfo()->Effects[EFFECT_1].CalcValue();

                GetTarget()->CastCustomSpell(GetTarget(), SPELL_SHAMAN_FOCUSED_INSIGHT, &basePoints0, &basePoints1, &basePoints1, true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_focused_insight_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE))
                    return false;
                return true;
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

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE, SPELLVALUE_BASE_POINT0, heal, (Unit*)NULL, true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_glyph_of_healing_wave_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_glyph_of_healing_wave_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                return sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL);
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                int32 damage = GetEffectValue();
                SpellInfo const* triggeringSpell = GetTriggeringSpell();
                if (Unit* target = GetHitUnit())
                    if (Unit* caster = GetCaster())
                    {
                        if (Unit* owner = caster->GetOwner())
                        {
                            if (triggeringSpell)
                                damage = int32(owner->SpellHealingBonusDone(target, triggeringSpell, damage, HEAL));

                            // Soothing Rains
                            if (AuraEffect* dummy = owner->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_SOOTHING_RAIN, EFFECT_0))
                                AddPct(damage, dummy->GetAmount());

                            damage = int32(target->SpellHealingBonusTaken(owner, triggeringSpell, damage, HEAL));
                        }
                        caster->CastCustomSpell(target, SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL, &damage, 0, 0, true, 0, 0, GetOriginalCaster()->GetGUID());
                    }
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_healing_stream_totem_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_EXHAUSTION))
                    return false;
                return true;
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

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_heroism_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_heroism_SpellScript::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_heroism_SpellScript::RemoveInvalidTargets, EFFECT_2, TARGET_UNIT_CASTER_AREA_RAID);
                AfterHit += SpellHitFn(spell_sha_heroism_SpellScript::ApplyDebuff);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD))
                    return false;
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD, true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_lightning_shield_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_MANA_SURGE))
                    return false;
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE, true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_lightning_shield_trigger_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE))
                    return false;
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 mana = eventInfo.GetDamageInfo()->GetSpellInfo()->CalcPowerCost(GetTarget(), SpellSchoolMask(eventInfo.GetDamageInfo()->GetSchoolMask()));
                mana = int32(CalculatePct(mana, 35));

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_ITEM_MANA_SURGE, SPELLVALUE_BASE_POINT0, mana, GetTarget(), true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_mana_surge_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_sha_item_mana_surge_AuraScript();
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
            PrepareSpellScript(spell_sha_lava_lash_SpellScript)

            bool Load() OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_lava_lash_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
            }

        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LAVA_SURGE))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_LAVA_SURGE, true);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_lava_surge_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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
            PrepareSpellScript(spell_sha_lava_surge_proc_SpellScript)

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LAVA_BURST))
                    return false;
                return true;
            }

            bool Load() OVERRIDE
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->ToPlayer()->RemoveSpellCooldown(SPELL_SHAMAN_LAVA_BURST, true);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_lava_surge_proc_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

        };

        SpellScript* GetSpellScript() const OVERRIDE
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
                ///@TODO: Exclude the "short term" buffs from the stat value
                if (Unit* caster = GetCaster())
                    if (Unit* owner = caster->GetOwner())
                        amount = CalculatePct(owner->GetStat(STAT_SPIRIT), aurEff->GetAmount());
            }

            void Register() OVERRIDE
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_sha_mana_tide_totem_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_STAT);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_NATURE_GUARDIAN))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                //! HACK due to currenct proc system implementation
                if (Player* player = GetTarget()->ToPlayer())
                    if (player->HasSpellCooldown(GetSpellInfo()->Id))
                        return false;

                return GetTarget()->HealthBelowPctDamaged(30, eventInfo.GetDamageInfo()->GetDamage());
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 basePoints0 = GetTarget()->CountPctFromMaxHealth(aurEff->GetAmount());

                GetTarget()->CastCustomSpell(GetTarget(), SPELL_SHAMAN_NATURE_GUARDIAN, &basePoints0, NULL, NULL, true);

                if (eventInfo.GetProcTarget() && eventInfo.GetProcTarget()->IsAlive())
                    eventInfo.GetProcTarget()->getThreatManager().modifyThreatPercent(GetTarget(), -10);

                if (Player* player = GetTarget()->ToPlayer())
                    player->AddSpellCooldown(GetSpellInfo()->Id, 0, time(NULL) + aurEff->GetSpellInfo()->Effects[EFFECT_1].CalcValue());
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_nature_guardian_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_nature_guardian_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LIGHTNING_SHIELD))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                if (Aura* aura = GetTarget()->GetAura(SPELL_SHAMAN_LIGHTNING_SHIELD))
                {
                    aura->SetCharges(std::min(aura->GetCharges() + 1, aurEff->GetAmount()));
                    aura->RefreshDuration();
                }
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_rolling_thunder_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TELLURIC_CURRENTS))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 basePoints0 = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount());

                GetTarget()->CastCustomSpell(GetTarget(), SPELL_SHAMAN_TELLURIC_CURRENTS, &basePoints0, NULL, NULL, true);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_telluric_currents_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_thunderstorm_SpellScript::HandleKnockBack, EFFECT_2, SPELL_EFFECT_KNOCK_BACK);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TIDAL_WAVES))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                int32 basePoints0 = -aurEff->GetAmount();
                int32 basePoints1 = aurEff->GetAmount();

                GetTarget()->CastCustomSpell(GetTarget(), SPELL_SHAMAN_TIDAL_WAVES, &basePoints0, &basePoints1, NULL, true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_tidal_waves_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_sha_tidal_waves_AuraScript();
        }
};

void AddSC_shaman_spell_scripts()
{
    new spell_sha_ancestral_awakening();
    new spell_sha_ancestral_awakening_proc();
    new spell_sha_bloodlust();
    new spell_sha_chain_heal();
    new spell_sha_earth_shield();
    new spell_sha_earthbind_totem();
    new spell_sha_earthen_power();
    new spell_sha_feedback();
    new spell_sha_fire_nova();
    new spell_sha_flame_shock();
    new spell_sha_focused_insight();
    new spell_sha_glyph_of_healing_wave();
    new spell_sha_healing_stream_totem();
    new spell_sha_heroism();
    new spell_sha_item_lightning_shield();
    new spell_sha_item_lightning_shield_trigger();
    new spell_sha_item_mana_surge();
    new spell_sha_lava_lash();
    new spell_sha_lava_surge();
    new spell_sha_lava_surge_proc();
    new spell_sha_mana_tide_totem();
    new spell_sha_nature_guardian();
    new spell_sha_rolling_thunder();
    new spell_sha_telluric_currents();
    new spell_sha_thunderstorm();
    new spell_sha_tidal_waves();
}
