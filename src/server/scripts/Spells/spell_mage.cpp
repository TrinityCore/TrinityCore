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
 * Scripts for spells with SPELLFAMILY_MAGE and SPELLFAMILY_GENERIC spells used by mage players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_mage_".
 */

#include "ScriptMgr.h"
#include "Creature.h"
#include "Player.h"
#include "Random.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum MageSpells
{
    SPELL_MAGE_BLAZING_SPEED                     = 31643,
    SPELL_MAGE_BURNOUT                           = 44450,
    SPELL_MAGE_COLD_SNAP                         = 11958,
    SPELL_MAGE_FOCUS_MAGIC_PROC                  = 54648,
    SPELL_MAGE_FROST_WARDING_R1                  = 11189,
    SPELL_MAGE_FROST_WARDING_TRIGGERED           = 57776,
    SPELL_MAGE_INCANTERS_ABSORBTION_R1           = 44394,
    SPELL_MAGE_INCANTERS_ABSORBTION_TRIGGERED    = 44413,
    SPELL_MAGE_IGNITE                            = 12654,
    SPELL_MAGE_MASTER_OF_ELEMENTS_ENERGIZE       = 29077,
    SPELL_MAGE_SQUIRREL_FORM                     = 32813,
    SPELL_MAGE_GIRAFFE_FORM                      = 32816,
    SPELL_MAGE_SERPENT_FORM                      = 32817,
    SPELL_MAGE_DRAGONHAWK_FORM                   = 32818,
    SPELL_MAGE_WORGEN_FORM                       = 32819,
    SPELL_MAGE_SHEEP_FORM                        = 32820,
    SPELL_MAGE_GLYPH_OF_ETERNAL_WATER            = 70937,
    SPELL_MAGE_SHATTERED_BARRIER                 = 55080,
    SPELL_MAGE_SUMMON_WATER_ELEMENTAL_PERMANENT  = 70908,
    SPELL_MAGE_SUMMON_WATER_ELEMENTAL_TEMPORARY  = 70907,
    SPELL_MAGE_GLYPH_OF_BLAST_WAVE               = 62126,
    SPELL_MAGE_CHILLED                           = 12484,
    SPELL_MAGE_MANA_SURGE                        = 37445,
    SPELL_MAGE_MAGIC_ABSORPTION_MANA             = 29442,
    SPELL_MAGE_ARCANE_POTENCY_RANK_1             = 57529,
    SPELL_MAGE_ARCANE_POTENCY_RANK_2             = 57531,
    SPELL_MAGE_HOT_STREAK_PROC                   = 48108,
    SPELL_MAGE_ARCANE_SURGE                      = 37436,
    SPELL_MAGE_COMBUSTION                        = 11129,
    SPELL_MAGE_COMBUSTION_PROC                   = 28682,
    SPELL_MAGE_EMPOWERED_FIRE_PROC               = 67545,
    SPELL_MAGE_T10_2P_BONUS                      = 70752,
    SPELL_MAGE_T10_2P_BONUS_EFFECT               = 70753,
    SPELL_MAGE_T8_4P_BONUS                       = 64869,
    SPELL_MAGE_MISSILE_BARRAGE                   = 44401,
    SPELL_MAGE_FINGERS_OF_FROST_AURASTATE_AURA   = 44544,
    SPELL_MAGE_PERMAFROST_AURA                   = 68391
};

enum MageSpellIcons
{
    SPELL_ICON_MAGE_SHATTERED_BARRIER = 2945,
    SPELL_ICON_MAGE_PRESENCE_OF_MIND  = 139,
    SPELL_ICON_MAGE_CLEARCASTING      = 212,
    SPELL_ICON_MAGE_LIVING_BOMB       = 3000
};

// Incanter's Absorbtion
class spell_mage_incanters_absorbtion_base_AuraScript : public AuraScript
{
    public:
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_MAGE_INCANTERS_ABSORBTION_TRIGGERED,
                SPELL_MAGE_INCANTERS_ABSORBTION_R1
            });
        }

        void Trigger(AuraEffect* aurEff, DamageInfo& /*dmgInfo*/, uint32& absorbAmount)
        {
            Unit* target = GetTarget();

            if (AuraEffect* talentAurEff = target->GetAuraEffectOfRankedSpell(SPELL_MAGE_INCANTERS_ABSORBTION_R1, EFFECT_0))
            {
                int32 bp = CalculatePct(absorbAmount, talentAurEff->GetAmount());
                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(bp);
                target->CastSpell(target, SPELL_MAGE_INCANTERS_ABSORBTION_TRIGGERED, args);
            }
        }
};

// -31571 - Arcane Potency
class spell_mage_arcane_potency : public SpellScriptLoader
{
    public:
        spell_mage_arcane_potency() : SpellScriptLoader("spell_mage_arcane_potency") { }

        class spell_mage_arcane_potency_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_arcane_potency_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_MAGE_ARCANE_POTENCY_RANK_1,
                    SPELL_MAGE_ARCANE_POTENCY_RANK_2
                });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                // due to family mask sharing with brain freeze/missile barrage proc, we need to filter out by icon id
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo || (spellInfo->SpellIconID != SPELL_ICON_MAGE_CLEARCASTING && spellInfo->SpellIconID != SPELL_ICON_MAGE_PRESENCE_OF_MIND))
                    return false;

                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                static uint32 const triggerSpell[2] = { SPELL_MAGE_ARCANE_POTENCY_RANK_1, SPELL_MAGE_ARCANE_POTENCY_RANK_2 };

                PreventDefaultAction();
                Unit* caster = eventInfo.GetActor();
                uint32 spellId = triggerSpell[GetSpellInfo()->GetRank() - 1];
                caster->CastSpell(caster, spellId, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_mage_arcane_potency_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_mage_arcane_potency_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_arcane_potency_AuraScript();
        }
};

// -11113 - Blast Wave
class spell_mage_blast_wave : public SpellScriptLoader
{
    public:
        spell_mage_blast_wave() : SpellScriptLoader("spell_mage_blast_wave") { }

        class spell_mage_blast_wave_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mage_blast_wave_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_GLYPH_OF_BLAST_WAVE });
            }

            void HandleKnockBack(SpellEffIndex effIndex)
            {
                if (GetCaster()->HasAura(SPELL_MAGE_GLYPH_OF_BLAST_WAVE))
                    PreventHitDefaultEffect(effIndex);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mage_blast_wave_SpellScript::HandleKnockBack, EFFECT_2, SPELL_EFFECT_KNOCK_BACK);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mage_blast_wave_SpellScript();
        }
};

// -31641 - Blazing Speed
class spell_mage_blazing_speed : public SpellScriptLoader
{
public:
    spell_mage_blazing_speed() : SpellScriptLoader("spell_mage_blazing_speed") { }

    class spell_mage_blazing_speed_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_blazing_speed_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_MAGE_BLAZING_SPEED });
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            if (Unit* target = eventInfo.GetActionTarget())
                target->CastSpell(target, SPELL_MAGE_BLAZING_SPEED, aurEff);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_mage_blazing_speed_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_blazing_speed_AuraScript();
    }
};

// -54747 - Burning Determination
// 54748 - Burning Determination
class spell_mage_burning_determination : public SpellScriptLoader
{
    public:
        spell_mage_burning_determination() : SpellScriptLoader("spell_mage_burning_determination") { }

        class spell_mage_burning_determination_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_burning_determination_AuraScript);

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (SpellInfo const* spellInfo = eventInfo.GetSpellInfo())
                    if (spellInfo->GetAllEffectsMechanicMask() & ((1 << MECHANIC_INTERRUPT) | (1 << MECHANIC_SILENCE)))
                        return true;

                return false;
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_mage_burning_determination_AuraScript::CheckProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_burning_determination_AuraScript();
        }
};

// -44449 - Burnout
class spell_mage_burnout : public SpellScriptLoader
{
    public:
        spell_mage_burnout() : SpellScriptLoader("spell_mage_burnout") { }

        class spell_mage_burnout_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_burnout_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_BURNOUT });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetSpellInfo())
                    return false;

                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                int32 mana = eventInfo.GetDamageInfo()->GetSpellInfo()->CalcPowerCost(GetTarget(), eventInfo.GetDamageInfo()->GetSchoolMask());
                mana = CalculatePct(mana, aurEff->GetAmount());

                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(mana);
                GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_BURNOUT, args);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_mage_burnout_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_mage_burnout_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_burnout_AuraScript();
        }
};

// 11958 - Cold Snap
class spell_mage_cold_snap : public SpellScriptLoader
{
    public:
        spell_mage_cold_snap() : SpellScriptLoader("spell_mage_cold_snap") { }

        class spell_mage_cold_snap_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mage_cold_snap_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->GetSpellHistory()->ResetCooldowns([](SpellHistory::CooldownStorageType::iterator itr) -> bool
                {
                    SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(itr->first);
                    return spellInfo->SpellFamilyName == SPELLFAMILY_MAGE && (spellInfo->GetSchoolMask() & SPELL_SCHOOL_MASK_FROST) &&
                        spellInfo->Id != SPELL_MAGE_COLD_SNAP && spellInfo->GetRecoveryTime() > 0;
                }, true);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_mage_cold_snap_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mage_cold_snap_SpellScript();
        }
};

// 11129 - Combustion
class spell_mage_combustion : public SpellScriptLoader
{
    public:
        spell_mage_combustion() : SpellScriptLoader("spell_mage_combustion") { }

        class spell_mage_combustion_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_combustion_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_COMBUSTION_PROC });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                // Do not take charges, add a stack of crit buff
                if (!(eventInfo.GetHitMask() & PROC_HIT_CRITICAL))
                {
                    eventInfo.GetActor()->CastSpell(nullptr, SPELL_MAGE_COMBUSTION_PROC, true);
                    return false;
                }

                return true;
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_mage_combustion_AuraScript::CheckProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_combustion_AuraScript();
        }
};

// 28682 - Combustion proc
class spell_mage_combustion_proc : public SpellScriptLoader
{
    public:
        spell_mage_combustion_proc() : SpellScriptLoader("spell_mage_combustion_proc") { }

        class spell_mage_combustion_proc_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_combustion_proc_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_COMBUSTION });
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAurasDueToSpell(SPELL_MAGE_COMBUSTION);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_mage_combustion_proc_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_ADD_FLAT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_combustion_proc_AuraScript();
        }
};

// -31661 - Dragon's Breath
class spell_mage_dragon_breath : public AuraScript
{
    PrepareAuraScript(spell_mage_dragon_breath);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        // Dont proc with Living Bomb explosion
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (spellInfo && spellInfo->SpellIconID == SPELL_ICON_MAGE_LIVING_BOMB && spellInfo->SpellFamilyName == SPELLFAMILY_MAGE)
            return false;
        return true;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_mage_dragon_breath::CheckProc);
    }
};

// -11185 - Improved Blizzard
class spell_mage_imp_blizzard : public SpellScriptLoader
{
    public:
        spell_mage_imp_blizzard() : SpellScriptLoader("spell_mage_imp_blizzard") { }

        class spell_mage_imp_blizzard_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_imp_blizzard_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_CHILLED });
            }

            void HandleChill(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                uint32 triggerSpellId = sSpellMgr->GetSpellWithRank(SPELL_MAGE_CHILLED, GetSpellInfo()->GetRank());
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), triggerSpellId, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_mage_imp_blizzard_AuraScript::HandleChill, EFFECT_0, SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_imp_blizzard_AuraScript();
        }
};

// 37447 - Improved Mana Gems
// 61062 - Improved Mana Gems
class spell_mage_imp_mana_gems : public SpellScriptLoader
{
    public:
        spell_mage_imp_mana_gems() : SpellScriptLoader("spell_mage_imp_mana_gems") { }

        class spell_mage_imp_mana_gems_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_imp_mana_gems_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_MANA_SURGE });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell(nullptr, SPELL_MAGE_MANA_SURGE, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_mage_imp_mana_gems_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_imp_mana_gems_AuraScript();
        }
};

// -31656 - Empowered Fire
class spell_mage_empowered_fire : public SpellScriptLoader
{
    public:
        spell_mage_empowered_fire() : SpellScriptLoader("spell_mage_empowered_fire") { }

        class spell_mage_empowered_fire_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_empowered_fire_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_EMPOWERED_FIRE_PROC });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (SpellInfo const* spellInfo = eventInfo.GetSpellInfo())
                    if (spellInfo->Id == SPELL_MAGE_IGNITE)
                        return true;

                return false;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();

                Unit* target = GetTarget();
                CastSpellExtraArgs args(aurEff);
                uint8 percent = sSpellMgr->AssertSpellInfo(SPELL_MAGE_EMPOWERED_FIRE_PROC)->Effects[EFFECT_0].CalcValue();
                args.AddSpellBP0(CalculatePct(target->GetCreateMana(), percent));
                target->CastSpell(target, SPELL_MAGE_EMPOWERED_FIRE_PROC, args);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_mage_empowered_fire_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_mage_empowered_fire_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_ADD_FLAT_MODIFIER);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_empowered_fire_AuraScript();
        }
};

// 74396 - Fingers of Frost
class spell_mage_fingers_of_frost : public SpellScriptLoader
{
    public:
        spell_mage_fingers_of_frost() : SpellScriptLoader("spell_mage_fingers_of_frost") { }

        class spell_mage_fingers_of_frost_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_fingers_of_frost_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_FINGERS_OF_FROST_AURASTATE_AURA });
            }

            void HandleDummy(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->RemoveAuraFromStack(GetId());
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAurasDueToSpell(SPELL_MAGE_FINGERS_OF_FROST_AURASTATE_AURA);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_mage_fingers_of_frost_AuraScript::HandleDummy, EFFECT_0, SPELL_AURA_DUMMY);
                AfterEffectRemove += AuraEffectRemoveFn(spell_mage_fingers_of_frost_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_fingers_of_frost_AuraScript();
        }
};

// -543  - Fire Ward
// -6143 - Frost Ward
class spell_mage_fire_frost_ward : public SpellScriptLoader
{
    public:
        spell_mage_fire_frost_ward() : SpellScriptLoader("spell_mage_fire_frost_ward") { }

        class spell_mage_fire_frost_ward_AuraScript : public spell_mage_incanters_absorbtion_base_AuraScript
        {
            PrepareAuraScript(spell_mage_fire_frost_ward_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_MAGE_FROST_WARDING_TRIGGERED,
                    SPELL_MAGE_FROST_WARDING_R1
                });
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
            {
                canBeRecalculated = false;
                if (Unit* caster = GetCaster())
                {
                    // +80.68% from sp bonus
                    float bonus = 0.8068f;

                    bonus *= caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask());
                    bonus *= caster->CalculateSpellpowerCoefficientLevelPenalty(GetSpellInfo());

                    amount += int32(bonus);
                }
            }

            void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
            {
                Unit* target = GetTarget();
                if (AuraEffect* talentAurEff = target->GetAuraEffectOfRankedSpell(SPELL_MAGE_FROST_WARDING_R1, EFFECT_0))
                {
                    int32 chance = talentAurEff->GetSpellInfo()->Effects[EFFECT_1].CalcValue(); // SPELL_EFFECT_DUMMY with NO_TARGET

                    if (roll_chance_i(chance))
                    {
                        int32 bp = dmgInfo.GetDamage();
                        dmgInfo.AbsorbDamage(bp);
                        CastSpellExtraArgs args(aurEff);
                        args.AddSpellBP0(bp);
                        target->CastSpell(target, SPELL_MAGE_FROST_WARDING_TRIGGERED, args);
                        absorbAmount = 0;
                        PreventDefaultAction();
                    }
                }
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_fire_frost_ward_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_mage_fire_frost_ward_AuraScript::Absorb, EFFECT_0);
                AfterEffectAbsorb += AuraEffectAbsorbFn(spell_mage_fire_frost_ward_AuraScript::Trigger, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_fire_frost_ward_AuraScript();
        }
};

// -44614 - Frostfire Bolt
class spell_mage_frostfire_bolt : public AuraScript
{
    PrepareAuraScript(spell_mage_frostfire_bolt);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_PERMAFROST_AURA });
    }

    void ApplyPermafrost(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_MAGE_PERMAFROST_AURA, aurEff);
    }

    void RemovePermafrost(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_MAGE_PERMAFROST_AURA);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_mage_frostfire_bolt::ApplyPermafrost, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        AfterEffectRemove += AuraEffectRemoveFn(spell_mage_frostfire_bolt::ApplyPermafrost, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
    }
};

// 54646 - Focus Magic
class spell_mage_focus_magic : public SpellScriptLoader
{
    public:
        spell_mage_focus_magic() : SpellScriptLoader("spell_mage_focus_magic") { }

        class spell_mage_focus_magic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_focus_magic_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_FOCUS_MAGIC_PROC });
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                _procTarget = GetCaster();
                return _procTarget && _procTarget->IsAlive();
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(_procTarget, SPELL_MAGE_FOCUS_MAGIC_PROC, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_mage_focus_magic_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_mage_focus_magic_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_MOD_SPELL_CRIT_CHANCE);
            }

            Unit* _procTarget = nullptr;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_focus_magic_AuraScript();
        }
};

// 44401 - Missile Barrage
// 48108 - Hot Streak
// 57761 - Fireball!
class spell_mage_gen_extra_effects : public SpellScriptLoader
{
    public:
        spell_mage_gen_extra_effects() : SpellScriptLoader("spell_mage_gen_extra_effects") { }

        class spell_mage_gen_extra_effects_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_gen_extra_effects_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_MAGE_T10_2P_BONUS,
                    SPELL_MAGE_T10_2P_BONUS_EFFECT,
                    SPELL_MAGE_T8_4P_BONUS
                });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                Unit* caster = eventInfo.GetActor();
                // Prevent double proc for Arcane missiles
                if (caster == eventInfo.GetProcTarget())
                    return false;

                // Proc chance is unknown, we'll just use dummy aura amount
                if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_MAGE_T8_4P_BONUS, EFFECT_0))
                    if (roll_chance_i(aurEff->GetAmount()))
                        return false;

                return true;
            }

            void HandleProc(ProcEventInfo& eventInfo)
            {
                Unit* caster = eventInfo.GetActor();

                if (caster->HasAura(SPELL_MAGE_T10_2P_BONUS))
                    caster->CastSpell(nullptr, SPELL_MAGE_T10_2P_BONUS_EFFECT, true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_mage_gen_extra_effects_AuraScript::CheckProc);
                OnProc += AuraProcFn(spell_mage_gen_extra_effects_AuraScript::HandleProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_gen_extra_effects_AuraScript();
        }
};

// 56375 - Glyph of Polymorph
class spell_mage_glyph_of_polymorph : public SpellScriptLoader
{
    public:
        spell_mage_glyph_of_polymorph() : SpellScriptLoader("spell_mage_glyph_of_polymorph") { }

        class spell_mage_glyph_of_polymorph_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_glyph_of_polymorph_AuraScript);

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* target = eventInfo.GetProcTarget();
                target->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE, ObjectGuid::Empty, target->GetAura(32409)); // SW:D shall not be removed.
                target->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
                target->RemoveAurasByType(SPELL_AURA_PERIODIC_LEECH);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_mage_glyph_of_polymorph_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_glyph_of_polymorph_AuraScript();
        }
};

// 56374 - Glyph of Icy Veins
class spell_mage_glyph_of_icy_veins : public SpellScriptLoader
{
    public:
        spell_mage_glyph_of_icy_veins() : SpellScriptLoader("spell_mage_glyph_of_icy_veins") { }

        class spell_mage_glyph_of_icy_veins_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_glyph_of_icy_veins_AuraScript);

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = eventInfo.GetActor();
                caster->RemoveAurasByType(SPELL_AURA_HASTE_SPELLS, ObjectGuid::Empty, 0, true, false);
                caster->RemoveAurasByType(SPELL_AURA_MOD_DECREASE_SPEED);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_mage_glyph_of_icy_veins_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_glyph_of_icy_veins_AuraScript();
        }
};

// 56372 - Glyph of Ice Block
class spell_mage_glyph_of_ice_block : public SpellScriptLoader
{
    public:
        spell_mage_glyph_of_ice_block() : SpellScriptLoader("spell_mage_glyph_of_ice_block") { }

        class spell_mage_glyph_of_ice_block_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_glyph_of_ice_block_AuraScript);

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = eventInfo.GetActor();
                caster->GetSpellHistory()->ResetCooldowns([](SpellHistory::CooldownStorageType::iterator itr) -> bool
                {
                    SpellInfo const* cdSpell = sSpellMgr->GetSpellInfo(itr->first);
                    if (!cdSpell || cdSpell->SpellFamilyName != SPELLFAMILY_MAGE
                        || !(cdSpell->SpellFamilyFlags[0] & 0x00000040))
                        return false;
                    return true;
                }, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_mage_glyph_of_ice_block_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_glyph_of_ice_block_AuraScript();
        }
};

// -44445 - Hot Streak
class spell_mage_hot_streak : public SpellScriptLoader
{
    public:
        spell_mage_hot_streak() : SpellScriptLoader("spell_mage_hot_streak") { }

        class spell_mage_hot_streak_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_hot_streak_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_HOT_STREAK_PROC });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                AuraEffect* counter = GetEffect(EFFECT_1);
                if (!counter)
                    return;

                // Count spell criticals in a row in second aura
                if (eventInfo.GetHitMask() & PROC_HIT_CRITICAL)
                {
                    counter->SetAmount(counter->GetAmount() * 2);
                    if (counter->GetAmount() < 100) // not enough
                        return;

                    // roll chance
                    if (!roll_chance_i(aurEff->GetAmount()))
                        return;

                    Unit* caster = eventInfo.GetActor();
                    caster->CastSpell(caster, SPELL_MAGE_HOT_STREAK_PROC, aurEff);
                }

                // reset counter
                counter->SetAmount(25);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_mage_hot_streak_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_hot_streak_AuraScript();
        }
};

// -11426 - Ice Barrier
class spell_mage_ice_barrier : public SpellScriptLoader
{
    public:
        spell_mage_ice_barrier() : SpellScriptLoader("spell_mage_ice_barrier") { }

        class spell_mage_ice_barrier_AuraScript : public spell_mage_incanters_absorbtion_base_AuraScript
        {
            PrepareAuraScript(spell_mage_ice_barrier_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_SHATTERED_BARRIER });
            }

            void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
            {
                canBeRecalculated = false;
                if (Unit* caster = GetCaster())
                {
                    // +80.68% from sp bonus
                    float bonus = 0.8068f;

                    bonus *= caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask());

                    // Glyph of Ice Barrier: its weird having a SPELLMOD_ALL_EFFECTS here but its blizzards doing :)
                    // Glyph of Ice Barrier is only applied at the spell damage bonus because it was already applied to the base value in CalculateSpellDamage
                    bonus = caster->ApplyEffectModifiers(GetSpellInfo(), aurEff->GetEffIndex(), bonus);

                    bonus *= caster->CalculateSpellpowerCoefficientLevelPenalty(GetSpellInfo());

                    amount += int32(bonus);
                }
            }

            void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                // Shattered Barrier
                // Procs only if removed by damage.
                if (aurEff->GetAmount() <= 0)
                    if (Unit* caster = GetCaster())
                        if (AuraEffect* dummy = caster->GetDummyAuraEffect(SPELLFAMILY_MAGE, SPELL_ICON_MAGE_SHATTERED_BARRIER, EFFECT_0))
                            if (roll_chance_i(dummy->GetSpellInfo()->ProcChance))
                                caster->CastSpell(GetTarget(), SPELL_MAGE_SHATTERED_BARRIER, aurEff);
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_ice_barrier_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                AfterEffectAbsorb += AuraEffectAbsorbFn(spell_mage_ice_barrier_AuraScript::Trigger, EFFECT_0);
                AfterEffectRemove += AuraEffectRemoveFn(spell_mage_ice_barrier_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_ice_barrier_AuraScript();
        }
};

// 45438 - Ice Block
class spell_mage_ice_block : public SpellScript
{
    PrepareSpellScript(spell_mage_ice_block);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->ExcludeCasterAuraSpell });
    }

    void TriggerHypothermia()
    {
        GetCaster()->CastSpell(nullptr, GetSpellInfo()->ExcludeCasterAuraSpell, true);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_mage_ice_block::TriggerHypothermia);
    }
};

// -11119 - Ignite
class spell_mage_ignite : public SpellScriptLoader
{
    public:
        spell_mage_ignite() : SpellScriptLoader("spell_mage_ignite") { }

        class spell_mage_ignite_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_ignite_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_IGNITE });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetDamageInfo() && eventInfo.GetProcTarget();
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                SpellInfo const* igniteDot = sSpellMgr->AssertSpellInfo(SPELL_MAGE_IGNITE);
                int32 pct = 8 * GetSpellInfo()->GetRank();

                ASSERT(igniteDot->GetMaxTicks() > 0);
                int32 amount = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), pct) / igniteDot->GetMaxTicks());

                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(amount);
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_MAGE_IGNITE, args);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_mage_ignite_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_mage_ignite_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_ignite_AuraScript();
        }
};

// -44457 - Living Bomb
class spell_mage_living_bomb : public SpellScriptLoader
{
    public:
        spell_mage_living_bomb() : SpellScriptLoader("spell_mage_living_bomb") { }

        class spell_mage_living_bomb_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_living_bomb_AuraScript);

            bool Validate(SpellInfo const* spell) override
            {
                return ValidateSpellInfo({ static_cast<uint32>(spell->Effects[EFFECT_1].CalcValue()) });
            }

            void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                if (removeMode != AURA_REMOVE_BY_ENEMY_SPELL && removeMode != AURA_REMOVE_BY_EXPIRE)
                    return;

                if (Unit* caster = GetCaster())
                    caster->CastSpell(GetTarget(), uint32(aurEff->GetAmount()), aurEff);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_mage_living_bomb_AuraScript::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_living_bomb_AuraScript();
        }
};

// -29441 - Magic Absorption
class spell_mage_magic_absorption : public SpellScriptLoader
{
    public:
        spell_mage_magic_absorption() : SpellScriptLoader("spell_mage_magic_absorption") { }

        class spell_mage_magic_absorption_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_magic_absorption_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_MAGIC_ABSORPTION_MANA });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* caster = eventInfo.GetActionTarget();
                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(CalculatePct(caster->GetMaxPower(POWER_MANA), aurEff->GetAmount()));
                caster->CastSpell(caster, SPELL_MAGE_MAGIC_ABSORPTION_MANA, args);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_mage_magic_absorption_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_magic_absorption_AuraScript();
        }
};

// -1463 - Mana Shield
class spell_mage_mana_shield : public SpellScriptLoader
{
    public:
        spell_mage_mana_shield() : SpellScriptLoader("spell_mage_mana_shield") { }

        class spell_mage_mana_shield_AuraScript : public spell_mage_incanters_absorbtion_base_AuraScript
        {
            PrepareAuraScript(spell_mage_mana_shield_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_ARCANE_SURGE }) &&
                    spell_mage_incanters_absorbtion_base_AuraScript::Validate(spellInfo);
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
            {
                canBeRecalculated = false;
                if (Unit* caster = GetCaster())
                {
                    // +80.53% from sp bonus
                    float bonus = 0.8053f;

                    bonus *= caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask());
                    bonus *= caster->CalculateSpellpowerCoefficientLevelPenalty(GetSpellInfo());

                    amount += int32(bonus);
                }
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                Unit* caster = eventInfo.GetActionTarget();
                caster->CastSpell(caster, SPELL_MAGE_ARCANE_SURGE, aurEff);
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_mana_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MANA_SHIELD);
                AfterEffectManaShield += AuraEffectManaShieldFn(spell_mage_mana_shield_AuraScript::Trigger, EFFECT_0);

                OnEffectProc += AuraEffectProcFn(spell_mage_mana_shield_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_MANA_SHIELD);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_mana_shield_AuraScript();
        }
};

// -29074 - Master of Elements
class spell_mage_master_of_elements : public SpellScriptLoader
{
    public:
        spell_mage_master_of_elements() : SpellScriptLoader("spell_mage_master_of_elements") { }

        class spell_mage_master_of_elements_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_master_of_elements_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGE_MASTER_OF_ELEMENTS_ENERGIZE });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetSpellInfo())
                    return false;

                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                int32 mana = eventInfo.GetDamageInfo()->GetSpellInfo()->CalcPowerCost(GetTarget(), eventInfo.GetDamageInfo()->GetSchoolMask());
                mana = CalculatePct(mana, aurEff->GetAmount());

                if (mana > 0)
                {
                    CastSpellExtraArgs args(aurEff);
                    args.AddSpellBP0(mana);
                    GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_MASTER_OF_ELEMENTS_ENERGIZE, args);
                }
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_mage_master_of_elements_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_mage_master_of_elements_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_master_of_elements_AuraScript();
        }
};

// 55342 - Mirror Image
class spell_mage_mirror_image : public AuraScript
{
    PrepareAuraScript(spell_mage_mirror_image);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->Effects[EFFECT_2].TriggerSpell });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        // Set name of summons to name of caster
        GetTarget()->CastSpell(nullptr, GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mage_mirror_image::PeriodicTick, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// -44404 - Missile Barrage
class spell_mage_missile_barrage : public SpellScriptLoader
{
    public:
        spell_mage_missile_barrage() : SpellScriptLoader("spell_mage_missile_barrage") { }

        class spell_mage_missile_barrage_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mage_missile_barrage_AuraScript);

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return false;

                // Arcane Blast - full chance
                if (spellInfo->SpellFamilyFlags[0] & 0x20000000)
                    return true;

                // Rest of spells have half chance
                return roll_chance_i(50);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_mage_missile_barrage_AuraScript::CheckProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mage_missile_barrage_AuraScript();
        }
};

enum SilvermoonPolymorph
{
    NPC_AUROSALIA   = 18744,
};

/// @todo move out of here and rename - not a mage spell
// 32826 - Polymorph (Visual)
class spell_mage_polymorph_cast_visual : public SpellScriptLoader
{
    public:
        spell_mage_polymorph_cast_visual() : SpellScriptLoader("spell_mage_polymorph_visual") { }

        class spell_mage_polymorph_cast_visual_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mage_polymorph_cast_visual_SpellScript);

            static const uint32 PolymorphForms[6];

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(PolymorphForms);
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetCaster()->FindNearestCreature(NPC_AUROSALIA, 30.0f))
                    if (target->GetTypeId() == TYPEID_UNIT)
                        target->CastSpell(target, PolymorphForms[urand(0, 5)], true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mage_polymorph_cast_visual_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mage_polymorph_cast_visual_SpellScript();
        }
};

const uint32 spell_mage_polymorph_cast_visual::spell_mage_polymorph_cast_visual_SpellScript::PolymorphForms[6] =
{
    SPELL_MAGE_SQUIRREL_FORM,
    SPELL_MAGE_GIRAFFE_FORM,
    SPELL_MAGE_SERPENT_FORM,
    SPELL_MAGE_DRAGONHAWK_FORM,
    SPELL_MAGE_WORGEN_FORM,
    SPELL_MAGE_SHEEP_FORM
};

// 31687 - Summon Water Elemental
class spell_mage_summon_water_elemental : public SpellScriptLoader
{
    public:
        spell_mage_summon_water_elemental() : SpellScriptLoader("spell_mage_summon_water_elemental") { }

        class spell_mage_summon_water_elemental_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mage_summon_water_elemental_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_MAGE_GLYPH_OF_ETERNAL_WATER,
                    SPELL_MAGE_SUMMON_WATER_ELEMENTAL_TEMPORARY,
                    SPELL_MAGE_SUMMON_WATER_ELEMENTAL_PERMANENT
                });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                // Glyph of Eternal Water
                if (caster->HasAura(SPELL_MAGE_GLYPH_OF_ETERNAL_WATER))
                    caster->CastSpell(caster, SPELL_MAGE_SUMMON_WATER_ELEMENTAL_PERMANENT, true);
                else
                    caster->CastSpell(caster, SPELL_MAGE_SUMMON_WATER_ELEMENTAL_TEMPORARY, true);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_mage_summon_water_elemental_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mage_summon_water_elemental_SpellScript();
        }
};

void AddSC_mage_spell_scripts()
{
    new spell_mage_arcane_potency();
    new spell_mage_blast_wave();
    new spell_mage_blazing_speed();
    new spell_mage_burning_determination();
    new spell_mage_burnout();
    new spell_mage_cold_snap();
    new spell_mage_combustion();
    new spell_mage_combustion_proc();
    RegisterAuraScript(spell_mage_dragon_breath);
    new spell_mage_imp_blizzard();
    new spell_mage_imp_mana_gems();
    new spell_mage_empowered_fire();
    new spell_mage_fingers_of_frost();
    new spell_mage_fire_frost_ward();
    RegisterAuraScript(spell_mage_frostfire_bolt);
    new spell_mage_focus_magic();
    new spell_mage_gen_extra_effects();
    new spell_mage_glyph_of_polymorph();
    new spell_mage_glyph_of_icy_veins();
    new spell_mage_glyph_of_ice_block();
    new spell_mage_hot_streak();
    new spell_mage_ice_barrier();
    RegisterSpellScript(spell_mage_ice_block);
    new spell_mage_ignite();
    new spell_mage_living_bomb();
    new spell_mage_magic_absorption();
    new spell_mage_mana_shield();
    new spell_mage_master_of_elements();
    RegisterAuraScript(spell_mage_mirror_image);
    new spell_mage_missile_barrage();
    new spell_mage_polymorph_cast_visual();
    new spell_mage_summon_water_elemental();
}
