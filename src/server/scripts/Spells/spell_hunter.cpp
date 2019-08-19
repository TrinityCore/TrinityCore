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
 * Scripts for spells with SPELLFAMILY_HUNTER, SPELLFAMILY_PET and SPELLFAMILY_GENERIC spells used by hunter players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_hun_".
 */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "Pet.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum HunterSpells
{
    SPELL_HUNTER_ASPECT_OF_THE_BEAST                = 13161,
    SPELL_HUNTER_ASPECT_OF_THE_BEAST_PET            = 61669,
    SPELL_HUNTER_ASPECT_OF_THE_VIPER                = 34074,
    SPELL_HUNTER_ASPECT_OF_THE_VIPER_ENERGIZE       = 34075,
    SPELL_HUNTER_BESTIAL_WRATH                      = 19574,
    SPELL_HUNTER_CHIMERA_SHOT_SERPENT               = 53353,
    SPELL_HUNTER_CHIMERA_SHOT_VIPER                 = 53358,
    SPELL_HUNTER_CHIMERA_SHOT_SCORPID               = 53359,
    SPELL_HUNTER_GLYPH_OF_ARCANE_SHOT               = 61389,
    SPELL_HUNTER_GLYPH_OF_ASPECT_OF_THE_VIPER       = 56851,
    SPELL_HUNTER_IMPROVED_MEND_PET                  = 24406,
    SPELL_HUNTER_INVIGORATION_TRIGGERED             = 53398,
    SPELL_HUNTER_MASTERS_CALL_TRIGGERED             = 62305,
    SPELL_HUNTER_MISDIRECTION                       = 34477,
    SPELL_HUNTER_MISDIRECTION_PROC                  = 35079,
    SPELL_HUNTER_PET_LAST_STAND_TRIGGERED           = 53479,
    SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX           = 55709,
    SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED = 54114,
    SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF    = 55711,
    SPELL_HUNTER_PET_CARRION_FEEDER_TRIGGERED       = 54045,
    SPELL_HUNTER_PIERCING_SHOTS                     = 63468,
    SPELL_HUNTER_READINESS                          = 23989,
    SPELL_HUNTER_SNIPER_TRAINING_R1                 = 53302,
    SPELL_HUNTER_SNIPER_TRAINING_BUFF_R1            = 64418,
    SPELL_HUNTER_T9_4P_GREATNESS                    = 68130,
    SPELL_HUNTER_VICIOUS_VIPER                      = 61609,
    SPELL_HUNTER_VIPER_ATTACK_SPEED                 = 60144,
    SPELL_DRAENEI_GIFT_OF_THE_NAARU                 = 59543,
    SPELL_ROAR_OF_SACRIFICE_TRIGGERED               = 67481,
    SPELL_HUNTER_LOCK_AND_LOAD_TRIGGER              = 56453,
    SPELL_HUNTER_LOCK_AND_LOAD_MARKER               = 67544,
    SPELL_HUNTER_KILL_COMMAND_HUNTER                = 34027,
    SPELL_HUNTER_THRILL_OF_THE_HUNT_MANA            = 34720,
    SPELL_REPLENISHMENT                             = 57669,
    SPELL_HUNTER_RAPID_RECUPERATION_MANA_R1         = 56654,
    SPELL_HUNTER_RAPID_RECUPERATION_MANA_R2         = 58882,
    SPELL_HUNTER_GLYPH_OF_MEND_PET_HAPPINESS        = 57894,
    SPELL_HUNTER_EXPLOSIVE_SHOT_DAMAGE              = 53352,
    SPELL_HUNTER_FEEDING_FRENZY_BUFF_R1             = 60096,
    SPELL_HUNTER_FEEDING_FRENZY_BUFF_R2             = 60097,
    SPELL_HUNTER_WYVERN_STING_DOT_R1                = 24131,
    SPELL_HUNTER_WYVERN_STING_DOT_R2                = 24134,
    SPELL_HUNTER_WYVERN_STING_DOT_R3                = 24135,
    SPELL_HUNTER_WYVERN_STING_DOT_R4                = 27069,
    SPELL_HUNTER_WYVERN_STING_DOT_R5                = 49009,
    SPELL_HUNTER_WYVERN_STING_DOT_R6                = 49010
};

// 13161 - Aspect of the Beast
class spell_hun_aspect_of_the_beast : public SpellScriptLoader
{
    public:
        spell_hun_aspect_of_the_beast() : SpellScriptLoader("spell_hun_aspect_of_the_beast") { }

        class spell_hun_aspect_of_the_beast_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_aspect_of_the_beast_AuraScript);

            bool Load() override
            {
                return GetOwner()->GetTypeId() == TYPEID_PLAYER;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_ASPECT_OF_THE_BEAST_PET });
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Player* player = GetTarget()->ToPlayer();
                if (Pet* pet = player->GetPet())
                    pet->RemoveAurasDueToSpell(SPELL_HUNTER_ASPECT_OF_THE_BEAST_PET);
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Player* player = GetTarget()->ToPlayer();
                if (player->GetPet())
                    player->CastSpell(player, SPELL_HUNTER_ASPECT_OF_THE_BEAST_PET, true);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_hun_aspect_of_the_beast_AuraScript::OnApply, EFFECT_0, SPELL_AURA_UNTRACKABLE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_hun_aspect_of_the_beast_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_UNTRACKABLE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_aspect_of_the_beast_AuraScript();
        }
};

// 61669 - Aspect of the Beast
class spell_hun_aspect_of_the_beast_pet : public AuraScript
{
    PrepareAuraScript(spell_hun_aspect_of_the_beast_pet);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_ASPECT_OF_THE_BEAST });
    }

    bool Load() override
    {
        return GetUnitOwner()->GetSpellModOwner();
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Player* owner = GetUnitOwner()->GetSpellModOwner();
        if (!ASSERT_NOTNULL(owner)->HasAura(SPELL_HUNTER_ASPECT_OF_THE_BEAST))
            Remove();
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_hun_aspect_of_the_beast_pet::OnApply, EFFECT_0, SPELL_AURA_UNTRACKABLE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 34074 - Aspect of the Viper
class spell_hun_ascpect_of_the_viper : public SpellScriptLoader
{
    public:
        spell_hun_ascpect_of_the_viper() : SpellScriptLoader("spell_hun_ascpect_of_the_viper") { }

        class spell_hun_ascpect_of_the_viper_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_ascpect_of_the_viper_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_HUNTER_ASPECT_OF_THE_VIPER_ENERGIZE,
                    SPELL_HUNTER_GLYPH_OF_ASPECT_OF_THE_VIPER,
                    SPELL_HUNTER_VIPER_ATTACK_SPEED,
                    SPELL_HUNTER_VICIOUS_VIPER
                });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();

                uint32 maxMana = GetTarget()->GetMaxPower(POWER_MANA);
                int32 mana = CalculatePct(maxMana, GetTarget()->GetAttackTime(RANGED_ATTACK) / 1000.0f);

                if (AuraEffect const* glyph = GetTarget()->GetAuraEffect(SPELL_HUNTER_GLYPH_OF_ASPECT_OF_THE_VIPER, EFFECT_0))
                    AddPct(mana, glyph->GetAmount());

                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(mana);
                GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_ASPECT_OF_THE_VIPER_ENERGIZE, args);
            }

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                // Hunter T7 4P Bonus
                if (GetTarget()->HasAura(SPELL_HUNTER_VIPER_ATTACK_SPEED))
                    GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_VICIOUS_VIPER, aurEff);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                // Hunter T7 4P Bonus
                if (GetTarget()->HasAura(SPELL_HUNTER_VIPER_ATTACK_SPEED))
                    GetTarget()->RemoveAurasDueToSpell(SPELL_HUNTER_VICIOUS_VIPER);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_hun_ascpect_of_the_viper_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_OBS_MOD_POWER);
                AfterEffectApply += AuraEffectApplyFn(spell_hun_ascpect_of_the_viper_AuraScript::OnApply, EFFECT_0, SPELL_AURA_OBS_MOD_POWER, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_hun_ascpect_of_the_viper_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_OBS_MOD_POWER, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_ascpect_of_the_viper_AuraScript();
        }
};

// 53209 - Chimera Shot
class spell_hun_chimera_shot : public SpellScriptLoader
{
    public:
        spell_hun_chimera_shot() : SpellScriptLoader("spell_hun_chimera_shot") { }

        class spell_hun_chimera_shot_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_chimera_shot_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_CHIMERA_SHOT_SERPENT, SPELL_HUNTER_CHIMERA_SHOT_VIPER, SPELL_HUNTER_CHIMERA_SHOT_SCORPID });
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* unitTarget = GetHitUnit())
                {
                    uint32 spellId = 0;
                    int32 basePoint = 0;
                    Unit::AuraApplicationMap const& auras = unitTarget->GetAppliedAuras();
                    for (Unit::AuraApplicationMap::const_iterator i = auras.begin(); i != auras.end(); ++i)
                    {
                        Aura* aura = i->second->GetBase();
                        if (aura->GetCasterGUID() != caster->GetGUID())
                            continue;

                        // Search only Serpent Sting, Viper Sting, Scorpid Sting auras
                        flag96 familyFlag = aura->GetSpellInfo()->SpellFamilyFlags;
                        if (!(familyFlag[1] & 0x00000080 || familyFlag[0] & 0x0000C000))
                            continue;
                        if (AuraEffect const* aurEff = aura->GetEffect(EFFECT_0))
                        {
                            // Serpent Sting - Instantly deals 40% of the damage done by your Serpent Sting.
                            if (familyFlag[0] & 0x4000)
                            {
                                spellId = SPELL_HUNTER_CHIMERA_SHOT_SERPENT;

                                // calculate damage of basic tick (bonuses are already factored in AuraEffect)
                                basePoint = aurEff->GetAmount() * aurEff->GetTotalTicks();
                                ApplyPct(basePoint, 40);
                            }
                            // Viper Sting - Instantly restores mana to you equal to 60% of the total amount drained by your Viper Sting.
                            else if (familyFlag[1] & 0x00000080)
                            {
                                spellId = SPELL_HUNTER_CHIMERA_SHOT_VIPER;

                                // % of mana drained in max duration
                                basePoint = aurEff->GetAmount() * aurEff->GetTotalTicks();

                                // max value
                                int32 maxManaReturn = CalculatePct(static_cast<int32>(caster->GetMaxPower(POWER_MANA)), basePoint * 2);
                                ApplyPct(basePoint, unitTarget->GetMaxPower(POWER_MANA));
                                if (basePoint > maxManaReturn)
                                    basePoint = maxManaReturn;

                                ApplyPct(basePoint, 60);
                            }
                            // Scorpid Sting - Attempts to Disarm the target for 10 sec. This effect cannot occur more than once per 1 minute.
                            else if (familyFlag[0] & 0x00008000)
                                spellId = SPELL_HUNTER_CHIMERA_SHOT_SCORPID;

                            // Refresh aura duration
                            aura->RefreshDuration();
                        }
                        break;
                    }

                    if (spellId)
                    {
                        CastSpellExtraArgs args(TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD));
                        args.AddSpellBP0(basePoint);
                        caster->CastSpell(unitTarget, spellId, args);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hun_chimera_shot_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_chimera_shot_SpellScript();
        }
};

// -53256 - Cobra Strikes
class spell_hun_cobra_strikes : public SpellScriptLoader
{
    public:
        spell_hun_cobra_strikes() : SpellScriptLoader("spell_hun_cobra_strikes") { }

        class spell_hun_cobra_strikes_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_cobra_strikes_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                return ValidateSpellInfo({ spellInfo->Effects[EFFECT_0].TriggerSpell });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();

                SpellInfo const* triggeredSpellInfo = sSpellMgr->AssertSpellInfo(GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell);

                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellMod(SPELLVALUE_AURA_STACK, triggeredSpellInfo->StackAmount);
                GetTarget()->CastSpell(nullptr, triggeredSpellInfo->Id, args);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_hun_cobra_strikes_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_cobra_strikes_AuraScript();
        }
};

// 53257 - Cobra Strikes (triggered spell)
class spell_hun_cobra_strikes_triggered : public SpellScriptLoader
{
    public:
        spell_hun_cobra_strikes_triggered() : SpellScriptLoader("spell_hun_cobra_strikes_triggered") { }

        class spell_hun_cobra_strikes_triggered_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_cobra_strikes_triggered_AuraScript);

            void HandleStackDrop(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                ModStackAmount(-1);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_hun_cobra_strikes_triggered_AuraScript::HandleStackDrop, EFFECT_0, SPELL_AURA_ADD_FLAT_MODIFIER);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_cobra_strikes_triggered_AuraScript();
        }
};

// 781 - Disengage
class spell_hun_disengage : public SpellScriptLoader
{
    public:
        spell_hun_disengage() : SpellScriptLoader("spell_hun_disengage") { }

        class spell_hun_disengage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_disengage_SpellScript);

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (caster->GetTypeId() == TYPEID_PLAYER && !caster->IsInCombat())
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_hun_disengage_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_disengage_SpellScript();
        }
};

// 56841 - Glyph of Arcane Shot
class spell_hun_glyph_of_arcane_shot : public SpellScriptLoader
{
    public:
        spell_hun_glyph_of_arcane_shot() : SpellScriptLoader("spell_hun_glyph_of_arcane_shot") { }

        class spell_hun_glyph_of_arcane_shot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_glyph_of_arcane_shot_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_GLYPH_OF_ARCANE_SHOT });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (Unit* procTarget = eventInfo.GetProcTarget())
                {
                    Unit::AuraApplicationMap const& auras = procTarget->GetAppliedAuras();
                    for (Unit::AuraApplicationMap::const_iterator i = auras.begin(); i != auras.end(); ++i)
                    {
                        Aura const* aura = i->second->GetBase();
                        if (aura->GetCasterGUID() != GetTarget()->GetGUID())
                            continue;
                        // Search only Serpent Sting, Viper Sting, Scorpid Sting, Wyvern Sting
                        if (aura->GetSpellInfo()->SpellFamilyName == SPELLFAMILY_HUNTER
                            && aura->GetSpellInfo()->SpellFamilyFlags.HasFlag(0xC000, 0x1080))
                            return true;
                    }
                }
                return false;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                SpellInfo const* procSpell = eventInfo.GetSpellInfo();
                if (!procSpell)
                    return;

                int32 mana = procSpell->CalcPowerCost(GetTarget(), procSpell->GetSchoolMask());
                ApplyPct(mana, aurEff->GetAmount());

                // castspell refactor note: this is not triggered - is this intended?
                CastSpellExtraArgs args;
                args.AddSpellBP0(mana);
                GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_GLYPH_OF_ARCANE_SHOT, args);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_hun_glyph_of_arcane_shot_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_hun_glyph_of_arcane_shot_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_glyph_of_arcane_shot_AuraScript();
        }
};

// 57870 - Glyph of Mend Pet
class spell_hun_glyph_of_mend_pet : public SpellScriptLoader
{
    public:
        spell_hun_glyph_of_mend_pet() : SpellScriptLoader("spell_hun_glyph_of_mend_pet") { }

        class spell_hun_glyph_of_mend_pet_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_glyph_of_mend_pet_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_GLYPH_OF_MEND_PET_HAPPINESS });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetProcTarget()->CastSpell(nullptr, SPELL_HUNTER_GLYPH_OF_MEND_PET_HAPPINESS, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_hun_glyph_of_mend_pet_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_glyph_of_mend_pet_AuraScript();
        }
};

// -53301 - Explosive Shot
class spell_hun_explosive_shot : public AuraScript
{
    PrepareAuraScript(spell_hun_explosive_shot);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_EXPLOSIVE_SHOT_DAMAGE });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        if (Unit* caster = GetCaster())
        {
            CastSpellExtraArgs args(aurEff);
            args.AddSpellBP0(aurEff->GetAmount());
            caster->CastSpell(GetTarget(), SPELL_HUNTER_EXPLOSIVE_SHOT_DAMAGE, args);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hun_explosive_shot::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// -53511 - Feeding Frenzy
class spell_hun_feeding_frenzy : public AuraScript
{
    PrepareAuraScript(spell_hun_feeding_frenzy);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_FEEDING_FRENZY_BUFF_R1, SPELL_HUNTER_FEEDING_FRENZY_BUFF_R2 });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        static uint32 const triggerSpells[2] = { SPELL_HUNTER_FEEDING_FRENZY_BUFF_R1, SPELL_HUNTER_FEEDING_FRENZY_BUFF_R2 };

        uint8 rank = GetSpellInfo()->GetRank();
        uint32 spellId = triggerSpells[rank - 1];

        if (GetTarget()->GetVictim() && GetTarget()->EnsureVictim()->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT))
            GetTarget()->CastSpell(nullptr, spellId, aurEff);
        else
            GetTarget()->RemoveAurasDueToSpell(spellId);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hun_feeding_frenzy::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// -53290 - Hunting Party
class spell_hun_hunting_party : public SpellScriptLoader
{
    public:
        spell_hun_hunting_party() : SpellScriptLoader("spell_hun_hunting_party") { }

        class spell_hun_hunting_party_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_hunting_party_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_REPLENISHMENT });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell(nullptr, SPELL_REPLENISHMENT, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_hun_hunting_party_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_hunting_party_AuraScript();
        }
};

// -19572 - Improved Mend Pet
class spell_hun_improved_mend_pet : public SpellScriptLoader
{
    public:
        spell_hun_improved_mend_pet() : SpellScriptLoader("spell_hun_improved_mend_pet") { }

        class spell_hun_improved_mend_pet_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_improved_mend_pet_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_IMPROVED_MEND_PET });
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                return roll_chance_i(GetEffect(EFFECT_0)->GetAmount());
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_IMPROVED_MEND_PET, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_hun_improved_mend_pet_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_hun_improved_mend_pet_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_improved_mend_pet_AuraScript();
        }
};

// 53412 - Invigoration
class spell_hun_invigoration : public SpellScriptLoader
{
    public:
        spell_hun_invigoration() : SpellScriptLoader("spell_hun_invigoration") { }

        class spell_hun_invigoration_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_invigoration_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_INVIGORATION_TRIGGERED });
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (Unit* unitTarget = GetHitUnit())
                    if (AuraEffect* aurEff = unitTarget->GetDummyAuraEffect(SPELLFAMILY_HUNTER, 3487, 0))
                        if (roll_chance_i(aurEff->GetAmount()))
                            unitTarget->CastSpell(unitTarget, SPELL_HUNTER_INVIGORATION_TRIGGERED, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hun_invigoration_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_invigoration_SpellScript();
        }
};

// 58914 - Kill Command
class spell_hun_kill_command_pet : public SpellScriptLoader
{
    public:
        spell_hun_kill_command_pet() : SpellScriptLoader("spell_hun_kill_command_pet") { }

        class spell_hun_kill_command_pet_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_kill_command_pet_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_KILL_COMMAND_HUNTER });
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                // prevent charge drop (aura has both proc charge and stacks)
                PreventDefaultAction();

                if (Unit* owner = eventInfo.GetActor()->GetOwner())
                    owner->RemoveAuraFromStack(SPELL_HUNTER_KILL_COMMAND_HUNTER);

                ModStackAmount(-1);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_hun_kill_command_pet_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_kill_command_pet_AuraScript();
        }
};

// 53478 - Last Stand Pet
class spell_hun_last_stand_pet : public SpellScriptLoader
{
    public:
        spell_hun_last_stand_pet() : SpellScriptLoader("spell_hun_last_stand_pet") { }

        class spell_hun_last_stand_pet_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_last_stand_pet_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_PET_LAST_STAND_TRIGGERED });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellBP0(caster->CountPctFromMaxHealth(30));
                caster->CastSpell(caster, SPELL_HUNTER_PET_LAST_STAND_TRIGGERED, args);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hun_last_stand_pet_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_last_stand_pet_SpellScript();
        }
};

// -56342 - Lock and Load
class spell_hun_lock_and_load : public SpellScriptLoader
{
    public:
        spell_hun_lock_and_load() : SpellScriptLoader("spell_hun_lock_and_load") { }

        class spell_hun_lock_and_load_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_lock_and_load_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_HUNTER_LOCK_AND_LOAD_TRIGGER,
                    SPELL_HUNTER_LOCK_AND_LOAD_MARKER
                });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (eventInfo.GetActor()->HasAura(SPELL_HUNTER_LOCK_AND_LOAD_MARKER))
                    return false;
                return true;
            }

            bool CheckTrapProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                if (!(eventInfo.GetTypeMask() & PROC_FLAG_DONE_TRAP_ACTIVATION))
                    return false;

                // Do not proc on traps for immolation/explosive trap
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo || !(spellInfo->GetSchoolMask() & SPELL_SCHOOL_MASK_FROST))
                    return false;

                return roll_chance_i(aurEff->GetAmount());
            }

            bool CheckPeriodicProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                if (!(eventInfo.GetTypeMask() & PROC_FLAG_DONE_PERIODIC))
                    return false;

                return roll_chance_i(aurEff->GetAmount());
            }

            void HandleProc(ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* caster = eventInfo.GetActor();
                caster->CastSpell(caster, SPELL_HUNTER_LOCK_AND_LOAD_TRIGGER, true);
                caster->CastSpell(caster, SPELL_HUNTER_LOCK_AND_LOAD_MARKER, true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_hun_lock_and_load_AuraScript::CheckProc);

                DoCheckEffectProc += AuraCheckEffectProcFn(spell_hun_lock_and_load_AuraScript::CheckTrapProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
                DoCheckEffectProc += AuraCheckEffectProcFn(spell_hun_lock_and_load_AuraScript::CheckPeriodicProc, EFFECT_1, SPELL_AURA_DUMMY);

                OnProc += AuraProcFn(spell_hun_lock_and_load_AuraScript::HandleProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_lock_and_load_AuraScript();
        }
};

// 53271 - Masters Call
class spell_hun_masters_call : public SpellScriptLoader
{
    public:
        spell_hun_masters_call() : SpellScriptLoader("spell_hun_masters_call") { }

        class spell_hun_masters_call_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_masters_call_SpellScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_HUNTER_MASTERS_CALL_TRIGGERED,
                    static_cast<uint32>(spellInfo->Effects[EFFECT_0].CalcValue()),
                    static_cast<uint32>(spellInfo->Effects[EFFECT_1].CalcValue())
                });
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            SpellCastResult DoCheckCast()
            {
                Guardian* pet = GetCaster()->ToPlayer()->GetGuardianPet();
                ASSERT(pet); // checked in Spell::CheckCast

                if (!pet->IsPet() || !pet->IsAlive())
                    return SPELL_FAILED_NO_PET;

                // Do a mini Spell::CheckCasterAuras on the pet, no other way of doing this
                SpellCastResult result = SPELL_CAST_OK;
                uint32 const unitflag = pet->GetUInt32Value(UNIT_FIELD_FLAGS);
                if (pet->GetCharmerGUID())
                    result = SPELL_FAILED_CHARMED;
                else if (unitflag & UNIT_FLAG_STUNNED)
                    result = SPELL_FAILED_STUNNED;
                else if (unitflag & UNIT_FLAG_FLEEING)
                    result = SPELL_FAILED_FLEEING;
                else if (unitflag & UNIT_FLAG_CONFUSED)
                    result = SPELL_FAILED_CONFUSED;

                if (result != SPELL_CAST_OK)
                    return result;

                Unit* target = GetExplTargetUnit();
                if (!target)
                    return SPELL_FAILED_BAD_TARGETS;

                if (!pet->IsWithinLOSInMap(target))
                    return SPELL_FAILED_LINE_OF_SIGHT;

                return SPELL_CAST_OK;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->ToPlayer()->GetPet()->CastSpell(GetHitUnit(), GetEffectValue(), true);
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(nullptr, SPELL_HUNTER_MASTERS_CALL_TRIGGERED, true);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_hun_masters_call_SpellScript::DoCheckCast);

                OnEffectHitTarget += SpellEffectFn(spell_hun_masters_call_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnEffectHitTarget += SpellEffectFn(spell_hun_masters_call_SpellScript::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_masters_call_SpellScript();
        }
};

// 34477 - Misdirection
class spell_hun_misdirection : public SpellScriptLoader
{
    public:
        spell_hun_misdirection() : SpellScriptLoader("spell_hun_misdirection") { }

        class spell_hun_misdirection_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_misdirection_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_MISDIRECTION_PROC });
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEFAULT || !GetTarget()->HasAura(SPELL_HUNTER_MISDIRECTION_PROC))
                    GetTarget()->GetThreatManager().UnregisterRedirectThreat(SPELL_HUNTER_MISDIRECTION);
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_MISDIRECTION_PROC, aurEff);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_hun_misdirection_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectProc += AuraEffectProcFn(spell_hun_misdirection_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_misdirection_AuraScript();
        }
};

// 35079 - Misdirection (Proc)
class spell_hun_misdirection_proc : public SpellScriptLoader
{
    public:
        spell_hun_misdirection_proc() : SpellScriptLoader("spell_hun_misdirection_proc") { }

        class spell_hun_misdirection_proc_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_misdirection_proc_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->GetThreatManager().UnregisterRedirectThreat(SPELL_HUNTER_MISDIRECTION);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_hun_misdirection_proc_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_misdirection_proc_AuraScript();
        }
};

// 54044 - Pet Carrion Feeder
class spell_hun_pet_carrion_feeder : public SpellScriptLoader
{
    public:
        spell_hun_pet_carrion_feeder() : SpellScriptLoader("spell_hun_pet_carrion_feeder") { }

        class spell_hun_pet_carrion_feeder_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_pet_carrion_feeder_SpellScript);

            bool Load() override
            {
                if (!GetCaster()->IsPet())
                    return false;
                return true;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_PET_CARRION_FEEDER_TRIGGERED });
            }

            SpellCastResult CheckIfCorpseNear()
            {
                Unit* caster = GetCaster();
                float max_range = GetSpellInfo()->GetMaxRange(false);
                WorldObject* result = nullptr;
                // search for nearby enemy corpse in range
                Trinity::AnyDeadUnitSpellTargetInRangeCheck check(caster, max_range, GetSpellInfo(), TARGET_CHECK_ENEMY);
                Trinity::WorldObjectSearcher<Trinity::AnyDeadUnitSpellTargetInRangeCheck> searcher(caster, result, check);
                Cell::VisitWorldObjects(caster, searcher, max_range);
                if (!result)
                    Cell::VisitGridObjects(caster, searcher, max_range);
                if (!result)
                    return SPELL_FAILED_NO_EDIBLE_CORPSES;
                return SPELL_CAST_OK;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                caster->CastSpell(caster, SPELL_HUNTER_PET_CARRION_FEEDER_TRIGGERED, false);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_hun_pet_carrion_feeder_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnCheckCast += SpellCheckCastFn(spell_hun_pet_carrion_feeder_SpellScript::CheckIfCorpseNear);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_pet_carrion_feeder_SpellScript();
        }
};

// 55709 - Pet Heart of the Phoenix
class spell_hun_pet_heart_of_the_phoenix : public SpellScriptLoader
{
    public:
        spell_hun_pet_heart_of_the_phoenix() : SpellScriptLoader("spell_hun_pet_heart_of_the_phoenix") { }

        class spell_hun_pet_heart_of_the_phoenix_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_pet_heart_of_the_phoenix_SpellScript);

            bool Load() override
            {
                if (!GetCaster()->IsPet())
                    return false;
                return true;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED, SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF });
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* owner = caster->GetOwner())
                {
                    if (!caster->HasAura(SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF))
                    {
                        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                        args.AddSpellBP0(100); // @todo shouldn't this be in spellmgr if it's constant?
                        owner->CastSpell(caster, SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED, args);
                        caster->CastSpell(caster, SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF, true);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hun_pet_heart_of_the_phoenix_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_pet_heart_of_the_phoenix_SpellScript();
        }
};

// -53234  - Piercing Shots
class spell_hun_piercing_shots : public SpellScriptLoader
{
public:
    spell_hun_piercing_shots() : SpellScriptLoader("spell_hun_piercing_shots") { }

    class spell_hun_piercing_shots_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hun_piercing_shots_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_HUNTER_PIERCING_SHOTS });
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetActionTarget())
                return true;
            return false;
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            Unit* caster = eventInfo.GetActor();
            Unit* target = eventInfo.GetActionTarget();

            if (DamageInfo* dmgInfo = eventInfo.GetDamageInfo())
            {
                SpellInfo const* piercingShots = sSpellMgr->AssertSpellInfo(SPELL_HUNTER_PIERCING_SHOTS);
                uint32 dmg = dmgInfo->GetDamage();

                int32 bp = CalculatePct(int32(dmg), aurEff->GetAmount()) / static_cast<int32>(piercingShots->GetMaxTicks());

                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(bp);
                caster->CastSpell(target, SPELL_HUNTER_PIERCING_SHOTS, args);
            }
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_hun_piercing_shots_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_hun_piercing_shots_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_hun_piercing_shots_AuraScript();
    }
};

// 56654, 58882 - Rapid Recuperation
class spell_hun_rapid_recuperation : public SpellScriptLoader
{
    public:
        spell_hun_rapid_recuperation() : SpellScriptLoader("spell_hun_rapid_recuperation") { }

        class spell_hun_rapid_recuperation_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_rapid_recuperation_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                return ValidateSpellInfo({ spellInfo->Effects[EFFECT_0].TriggerSpell });
            }

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                PreventDefaultAction();

                Unit* target = GetTarget();
                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(CalculatePct(target->GetMaxPower(POWER_MANA), aurEff->GetAmount()));
                target->CastSpell(target, GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, args);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_hun_rapid_recuperation_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_rapid_recuperation_AuraScript();
        }
};

// -53228 - Rapid Recuperation (talent aura)
class spell_hun_rapid_recuperation_trigger : public SpellScriptLoader
{
    public:
        spell_hun_rapid_recuperation_trigger() : SpellScriptLoader("spell_hun_rapid_recuperation_trigger") { }

        class spell_hun_rapid_recuperation_trigger_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_rapid_recuperation_trigger_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_HUNTER_RAPID_RECUPERATION_MANA_R1,
                    SPELL_HUNTER_RAPID_RECUPERATION_MANA_R2
                });
            }

            void HandleRapidFireProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                // Proc only from Rapid Fire
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo || !(spellInfo->SpellFamilyFlags[0] & 0x00000020))
                {
                    PreventDefaultAction();
                    return;
                }
            }

            void HandleRapidKillingProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                static uint32 const triggerSpells[2] = { SPELL_HUNTER_RAPID_RECUPERATION_MANA_R1, SPELL_HUNTER_RAPID_RECUPERATION_MANA_R2 };

                PreventDefaultAction();

                // Proc only from Rapid Killing
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo || !(spellInfo->SpellFamilyFlags[1] & 0x01000000))
                    return;

                uint8 rank = GetSpellInfo()->GetRank();
                uint32 spellId = triggerSpells[rank - 1];
                eventInfo.GetActor()->CastSpell(nullptr, spellId, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_hun_rapid_recuperation_trigger_AuraScript::HandleRapidFireProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
                OnEffectProc += AuraEffectProcFn(spell_hun_rapid_recuperation_trigger_AuraScript::HandleRapidKillingProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_rapid_recuperation_trigger_AuraScript();
        }
};

// 23989 - Readiness
class spell_hun_readiness : public SpellScriptLoader
{
    public:
        spell_hun_readiness() : SpellScriptLoader("spell_hun_readiness") { }

        class spell_hun_readiness_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_readiness_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                // immediately finishes the cooldown on your other Hunter abilities except Bestial Wrath
                GetCaster()->GetSpellHistory()->ResetCooldowns([](SpellHistory::CooldownStorageType::iterator itr) -> bool
                {
                    SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(itr->first);

                    ///! If spellId in cooldown map isn't valid, the above will return a null pointer.
                    if (spellInfo->SpellFamilyName == SPELLFAMILY_HUNTER &&
                        spellInfo->Id != SPELL_HUNTER_READINESS &&
                        spellInfo->Id != SPELL_HUNTER_BESTIAL_WRATH &&
                        spellInfo->Id != SPELL_DRAENEI_GIFT_OF_THE_NAARU &&
                        spellInfo->GetRecoveryTime() > 0)
                        return true;
                    return false;
                }, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hun_readiness_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_readiness_SpellScript();
        }
};

// 53480 - Roar of Sacrifice
class spell_hun_roar_of_sacrifice : public SpellScriptLoader
{
    public:
        spell_hun_roar_of_sacrifice() : SpellScriptLoader("spell_hun_roar_of_sacrifice") { }

        class spell_hun_roar_of_sacrifice_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_roar_of_sacrifice_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROAR_OF_SACRIFICE_TRIGGERED });
            }

            bool CheckProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !(damageInfo->GetSchoolMask() & aurEff->GetMiscValue()))
                    return false;

                if (!GetCaster())
                    return false;

                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount()));
                eventInfo.GetActionTarget()->CastSpell(GetCaster(), SPELL_ROAR_OF_SACRIFICE_TRIGGERED, args);
            }

            void Register() override
            {
                DoCheckEffectProc += AuraCheckEffectProcFn(spell_hun_roar_of_sacrifice_AuraScript::CheckProc, EFFECT_1, SPELL_AURA_DUMMY);
                OnEffectProc += AuraEffectProcFn(spell_hun_roar_of_sacrifice_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_roar_of_sacrifice_AuraScript();
        }
};

// 37506 - Scatter Shot
class spell_hun_scatter_shot : public SpellScriptLoader
{
    public:
        spell_hun_scatter_shot() : SpellScriptLoader("spell_hun_scatter_shot") { }

        class spell_hun_scatter_shot_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_scatter_shot_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Player* caster = GetCaster()->ToPlayer();
                // break Auto Shot and autohit
                caster->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
                caster->AttackStop();
                caster->SendAttackSwingCancelAttack();
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hun_scatter_shot_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_scatter_shot_SpellScript();
        }
};

// -53302 - Sniper Training
class spell_hun_sniper_training : public SpellScriptLoader
{
    public:
        spell_hun_sniper_training() : SpellScriptLoader("spell_hun_sniper_training") { }

        class spell_hun_sniper_training_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_sniper_training_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_SNIPER_TRAINING_R1, SPELL_HUNTER_SNIPER_TRAINING_BUFF_R1 });
            }

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                PreventDefaultAction();
                if (aurEff->GetAmount() <= 0)
                {
                    Unit* target = GetTarget();
                    uint32 spellId = SPELL_HUNTER_SNIPER_TRAINING_BUFF_R1 + GetId() - SPELL_HUNTER_SNIPER_TRAINING_R1;
                    target->CastSpell(target, spellId, aurEff);
                    if (Player* playerTarget = GetUnitOwner()->ToPlayer())
                    {
                        int32 baseAmount = aurEff->GetBaseAmount();
                        int32 amount = playerTarget->CalculateSpellDamage(GetSpellInfo(), aurEff->GetEffIndex(), &baseAmount);
                        GetEffect(EFFECT_0)->SetAmount(amount);
                    }
                }
            }

            void HandleUpdatePeriodic(AuraEffect* aurEff)
            {
                if (Player* playerTarget = GetUnitOwner()->ToPlayer())
                {
                    int32 baseAmount = aurEff->GetBaseAmount();
                    int32 amount = playerTarget->isMoving() ?
                    playerTarget->CalculateSpellDamage(GetSpellInfo(), aurEff->GetEffIndex(), &baseAmount) :
                    aurEff->GetAmount() - 1;
                    aurEff->SetAmount(amount);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_hun_sniper_training_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_hun_sniper_training_AuraScript::HandleUpdatePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_sniper_training_AuraScript();
        }
};

// 1515 - Tame Beast
class spell_hun_tame_beast : public SpellScriptLoader
{
    public:
        spell_hun_tame_beast() : SpellScriptLoader("spell_hun_tame_beast") { }

        class spell_hun_tame_beast_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_tame_beast_SpellScript);

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_DONT_REPORT;

                if (!GetExplTargetUnit())
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                if (Creature* target = GetExplTargetUnit()->ToCreature())
                {
                    if (target->GetLevel() > caster->GetLevel())
                        return SPELL_FAILED_HIGHLEVEL;

                    // use SMSG_PET_TAME_FAILURE?
                    if (!target->GetCreatureTemplate()->IsTameable(caster->ToPlayer()->CanTameExoticPets()))
                        return SPELL_FAILED_BAD_TARGETS;

                    if (caster->GetPetGUID())
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                    if (caster->GetCharmedGUID())
                        return SPELL_FAILED_ALREADY_HAVE_CHARM;
                }
                else
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_hun_tame_beast_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_tame_beast_SpellScript();
        }
};

// -24604 - Furious Howl
//  53434 - Call of the Wild
class spell_hun_target_only_pet_and_owner : public SpellScriptLoader
{
    public:
        spell_hun_target_only_pet_and_owner() : SpellScriptLoader("spell_hun_target_only_pet_and_owner") { }

        class spell_hun_target_only_pet_and_owner_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_target_only_pet_and_owner_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.clear();
                targets.push_back(GetCaster());
                if (Unit* owner = GetCaster()->GetOwner())
                    targets.push_back(owner);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hun_target_only_pet_and_owner_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_PARTY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hun_target_only_pet_and_owner_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_PARTY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_target_only_pet_and_owner_SpellScript();
        }
};

// -34497 - Thrill of the Hunt
class spell_hun_thrill_of_the_hunt : public SpellScriptLoader
{
    public:
        spell_hun_thrill_of_the_hunt() : SpellScriptLoader("spell_hun_thrill_of_the_hunt") { }

        class spell_hun_thrill_of_the_hunt_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_thrill_of_the_hunt_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_THRILL_OF_THE_HUNT_MANA });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return;

                Unit* caster = eventInfo.GetActor();
                int32 amount = 0;

                // Explosive Shot
                if (spellInfo->SpellFamilyFlags[2] & 0x200)
                {
                    if (AuraEffect const* explosiveShot = eventInfo.GetProcTarget()->GetAuraEffect(SPELL_AURA_PERIODIC_DUMMY, SPELLFAMILY_HUNTER, 0x00000000, 0x80000000, 0x00000000, caster->GetGUID()))
                    {
                        // due to Lock and Load SpellInfo::CalcPowerCost might return 0, so just calculate it manually
                        amount = CalculatePct(static_cast<int32>(CalculatePct(caster->GetCreateMana(), explosiveShot->GetSpellInfo()->ManaCostPercentage)), aurEff->GetAmount());

                        ASSERT(explosiveShot->GetSpellInfo()->GetMaxTicks() > 0);
                        amount /= explosiveShot->GetSpellInfo()->GetMaxTicks();
                    }
                }
                else
                    amount = CalculatePct(static_cast<int32>(spellInfo->CalcPowerCost(caster, spellInfo->GetSchoolMask())), aurEff->GetAmount());

                if (!amount)
                    return;

                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(amount);
                caster->CastSpell(nullptr, SPELL_HUNTER_THRILL_OF_THE_HUNT_MANA, args);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_hun_thrill_of_the_hunt_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_thrill_of_the_hunt_AuraScript();
        }
};

// 67151   - T9 4P Bonus
class spell_hun_t9_4p_bonus : public SpellScriptLoader
{
public:
    spell_hun_t9_4p_bonus() : SpellScriptLoader("spell_hun_t9_4p_bonus") { }

    class spell_hun_t9_4p_bonus_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hun_t9_4p_bonus_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_HUNTER_T9_4P_GREATNESS });
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetActor()->GetTypeId() == TYPEID_PLAYER && eventInfo.GetActor()->ToPlayer()->GetPet())
                return true;
            return false;
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            Unit* caster = eventInfo.GetActor();

            caster->CastSpell(caster->ToPlayer()->GetPet(), SPELL_HUNTER_T9_4P_GREATNESS, aurEff);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_hun_t9_4p_bonus_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_hun_t9_4p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_hun_t9_4p_bonus_AuraScript();
    }
};

// 60144 - Viper Attack Speed
class spell_hun_viper_attack_speed : public SpellScriptLoader
{
    public:
        spell_hun_viper_attack_speed() : SpellScriptLoader("spell_hun_viper_attack_speed") { }

        class spell_hun_viper_attack_speed_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_viper_attack_speed_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_HUNTER_ASPECT_OF_THE_VIPER,
                    SPELL_HUNTER_VICIOUS_VIPER
                });
            }

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->HasAura(SPELL_HUNTER_ASPECT_OF_THE_VIPER))
                    GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_VICIOUS_VIPER, aurEff);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                // possible exploit
                GetTarget()->RemoveAurasDueToSpell(SPELL_HUNTER_VICIOUS_VIPER);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_hun_viper_attack_speed_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_hun_viper_attack_speed_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_viper_attack_speed_AuraScript();
        }
};

// -19386 - Wyvern Sting
class spell_hun_wyvern_sting : public AuraScript
{
    PrepareAuraScript(spell_hun_wyvern_sting);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_HUNTER_WYVERN_STING_DOT_R1,
                SPELL_HUNTER_WYVERN_STING_DOT_R2,
                SPELL_HUNTER_WYVERN_STING_DOT_R3,
                SPELL_HUNTER_WYVERN_STING_DOT_R4,
                SPELL_HUNTER_WYVERN_STING_DOT_R5,
                SPELL_HUNTER_WYVERN_STING_DOT_R6
            });
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        uint8 rank = sSpellMgr->GetSpellRank(GetId());
        uint32 spellId = sSpellMgr->GetSpellWithRank(SPELL_HUNTER_WYVERN_STING_DOT_R1, rank);
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), spellId, aurEff);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_hun_wyvern_sting::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_hunter_spell_scripts()
{
    new spell_hun_aspect_of_the_beast();
    RegisterAuraScript(spell_hun_aspect_of_the_beast_pet);
    new spell_hun_ascpect_of_the_viper();
    new spell_hun_chimera_shot();
    new spell_hun_cobra_strikes();
    new spell_hun_cobra_strikes_triggered();
    new spell_hun_disengage();
    new spell_hun_glyph_of_arcane_shot();
    new spell_hun_glyph_of_mend_pet();
    RegisterAuraScript(spell_hun_explosive_shot);
    RegisterAuraScript(spell_hun_feeding_frenzy);
    new spell_hun_hunting_party();
    new spell_hun_improved_mend_pet();
    new spell_hun_invigoration();
    new spell_hun_kill_command_pet();
    new spell_hun_last_stand_pet();
    new spell_hun_lock_and_load();
    new spell_hun_masters_call();
    new spell_hun_misdirection();
    new spell_hun_misdirection_proc();
    new spell_hun_pet_carrion_feeder();
    new spell_hun_pet_heart_of_the_phoenix();
    new spell_hun_piercing_shots();
    new spell_hun_rapid_recuperation();
    new spell_hun_rapid_recuperation_trigger();
    new spell_hun_readiness();
    new spell_hun_roar_of_sacrifice();
    new spell_hun_scatter_shot();
    new spell_hun_sniper_training();
    new spell_hun_tame_beast();
    new spell_hun_target_only_pet_and_owner();
    new spell_hun_thrill_of_the_hunt();
    new spell_hun_t9_4p_bonus();
    new spell_hun_viper_attack_speed();
    RegisterAuraScript(spell_hun_wyvern_sting);
}
