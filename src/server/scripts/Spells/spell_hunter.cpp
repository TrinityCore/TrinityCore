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
    SPELL_HUNTER_AIMED_SHOT                         = 19434,
    SPELL_HUNTER_AIMED_SHOT_INSTANT                 = 82928,
    SPELL_HUNTER_BESTIAL_WRATH                      = 19574,
    SPELL_HUNTER_CALL_PET_1                         = 883,
    SPELL_HUNTER_CALL_PET_2                         = 83242,
    SPELL_HUNTER_CALL_PET_3                         = 83243,
    SPELL_HUNTER_CALL_PET_4                         = 83244,
    SPELL_HUNTER_CALL_PET_5                         = 83245,
    SPELL_HUNTER_CAMOUFLAGE_DURATION                = 51755,
    SPELL_HUNTER_CAMOUFLAGE_PERIODIC                = 80326,
    SPELL_HUNTER_CAMOUFLAGE_PERIODIC_TRIGGERED      = 80326,
    SPELL_HUNTER_CHIMERA_SHOT                       = 53209,
    SPELL_HUNTER_CHIMERA_SHOT_HEAL                  = 53353,
    SPELL_HUNTER_FIRE                               = 82926,
    SPELL_HUNTER_GENERIC_ENERGIZE_FOCUS             = 91954,
    SPELL_HUNTER_IMPROVED_MEND_PET                  = 24406,
    SPELL_HUNTER_IMPROVED_SERPENT_STING_DAMAGE      = 83077,
    SPELL_HUNTER_IMPROVED_SERPENT_STING_R1          = 19464,
    SPELL_HUNTER_IMPROVED_SERPENT_STING_R2          = 82834,
    SPELL_HUNTER_INSANITY                           = 95809,
    SPELL_HUNTER_INVIGORATION_TRIGGERED             = 53398,
    SPELL_HUNTER_GLYPH_OF_KILL_SHOT_COOLDOWN        = 90967,
    SPELL_HUNTER_LOCK_AND_LOAD                      = 56453,
    SPELL_HUNTER_MASTERS_CALL_TRIGGERED             = 62305,
    SPELL_HUNTER_MISDIRECTION_PROC                  = 35079,
    SPELL_HUNTER_MULTISHOT                          = 2643,
    SPELL_HUNTER_PET_LAST_STAND_TRIGGERED           = 53479,
    SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX           = 55709,
    SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED = 54114,
    SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF    = 55711,
    SPELL_HUNTER_PET_CARRION_FEEDER_TRIGGERED       = 54045,
    SPELL_HUNTER_PIERCING_SHOTS                     = 63468,
    SPELL_HUNTER_RAPID_RECUPERATION                 = 58883,
    SPELL_HUNTER_READINESS                          = 23989,
    SPELL_HUNTER_SERPENT_STING                      = 1978,
    SPELL_HUNTER_SNIPER_TRAINING_R1                 = 53302,
    SPELL_HUNTER_SNIPER_TRAINING_BUFF_R1            = 64418,
    SPELL_HUNTER_STEADY_SHOT                        = 56641,
    SPELL_HUNTER_STEADY_SHOT_FOCUS                  = 77443,
    SPELL_HUNTER_TERMINATION_R_1                    = 83489,
    SPELL_HUNTER_TERMINATION_R_2                    = 83490,
    SPELL_HUNTER_TRAP_LAUNCHER_LINKED               = 82946,
    SPELL_HUNTER_IMPROVED_STEADY_SHOT_TRIGGERED     = 53220,
    SPELL_HUNTER_THRILL_OF_THE_HUNT                 = 34720,
    SPELL_HUNTER_WILD_QUIVER_DAMAGE                 = 76663,
    SPELL_LOCK_AND_LOAD_TRIGGER                     = 56453,
    SPELL_LOCK_AND_LOAD_MARKER                      = 67544
};

enum MiscSpells
{
    SPELL_DRAENEI_GIFT_OF_THE_NAARU                 = 59543,
    SPELL_MAGE_TEMPORAL_DISPLACEMENT                = 80354,
    SPELL_SHAMAN_EXHAUSTION                         = 57723,
    SPELL_SHAMAN_SATED                              = 57724
};

// 90355 - Ancient Hysteria
class spell_hun_ancient_hysteria : public SpellScriptLoader
{
    public:
        spell_hun_ancient_hysteria() : SpellScriptLoader("spell_hun_ancient_hysteria") { }

        class spell_hun_ancient_hysteria_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_ancient_hysteria_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_HUNTER_INSANITY,
                    SPELL_MAGE_TEMPORAL_DISPLACEMENT,
                    SPELL_SHAMAN_EXHAUSTION,
                    SPELL_SHAMAN_SATED
                });
            }

            void RemoveInvalidTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_HUNTER_INSANITY));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_MAGE_TEMPORAL_DISPLACEMENT));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHAMAN_EXHAUSTION));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHAMAN_SATED));
            }

            void ApplyDebuff()
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, SPELL_HUNTER_INSANITY, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hun_ancient_hysteria_SpellScript::RemoveInvalidTargets, EFFECT_ALL, TARGET_UNIT_CASTER_AREA_RAID);
                AfterHit += SpellHitFn(spell_hun_ancient_hysteria_SpellScript::ApplyDebuff);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_ancient_hysteria_SpellScript();
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
                return ValidateSpellInfo({ SPELL_HUNTER_CHIMERA_SHOT_HEAL, SPELL_HUNTER_SERPENT_STING });
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_HUNTER_CHIMERA_SHOT_HEAL, true);

                if (Aura* aur = GetHitUnit()->GetAura(SPELL_HUNTER_SERPENT_STING, GetCaster()->GetGUID()))
                    aur->SetDuration(aur->GetSpellInfo()->GetMaxDuration(), true);
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

// 77767 - Cobra Shot
class spell_hun_cobra_shot : public SpellScriptLoader
{
    public:
        spell_hun_cobra_shot() : SpellScriptLoader("spell_hun_cobra_shot") { }

        class spell_hun_cobra_shot_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_cobra_shot_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                    {
                        SPELL_HUNTER_TERMINATION_R_1,
                        SPELL_HUNTER_TERMINATION_R_2,
                        SPELL_HUNTER_GENERIC_ENERGIZE_FOCUS,
                        SPELL_HUNTER_SERPENT_STING
                    });
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleLaunch(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    uint32 spellId = 0;
                    if (caster->HasAura(SPELL_HUNTER_TERMINATION_R_2))
                        spellId = SPELL_HUNTER_TERMINATION_R_2;
                    else if (caster->HasAura(SPELL_HUNTER_TERMINATION_R_1))
                        spellId = SPELL_HUNTER_TERMINATION_R_1;

                    uint32 amount = GetSpellInfo()->Effects[EFFECT_1].BasePoints;
                    if (Aura* terminationAura = caster->GetAura(spellId))
                    {
                        if (Unit* spellTarget = GetExplTargetUnit())
                            if (spellTarget->GetHealthPct() <= float(terminationAura->GetSpellInfo()->Effects[EFFECT_1].BasePoints))
                                amount += terminationAura->GetEffect(EFFECT_0)->GetAmount();
                    }
                    caster->CastCustomSpell(SPELL_HUNTER_GENERIC_ENERGIZE_FOCUS, SPELLVALUE_BASE_POINT0, amount, caster, true);
                }
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (Aura* aur = GetHitUnit()->GetAura(SPELL_HUNTER_SERPENT_STING, GetCaster()->GetGUID()))
                {
                    int32 newDuration = aur->GetDuration() + GetEffectValue() * IN_MILLISECONDS;
                    aur->SetDuration(std::min(newDuration, aur->GetMaxDuration()), true);
                }
            }

            void Register() override
            {
                OnEffectLaunch += SpellEffectFn(spell_hun_cobra_shot_SpellScript::HandleLaunch, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
                OnEffectHitTarget += SpellEffectFn(spell_hun_cobra_shot_SpellScript::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_cobra_shot_SpellScript();
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

// 82926 - Fire!
class spell_hun_fire : public SpellScriptLoader
{
    public:
        spell_hun_fire() : SpellScriptLoader("spell_hun_fire") { }

        class spell_hun_fire_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_fire_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_AIMED_SHOT_INSTANT });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcSpell()->GetSpellInfo()->Id == SPELL_HUNTER_AIMED_SHOT_INSTANT;
            }

            void HandleEffectCalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)
            {
                if (!spellMod)
                {
                    spellMod = new SpellModifier(GetAura());
                    spellMod->op = SPELLMOD_CASTING_TIME;
                    spellMod->type = SPELLMOD_PCT;
                    spellMod->spellId = GetId();
                    spellMod->mask = GetSpellInfo()->Effects[aurEff->GetEffIndex()].SpellClassMask;
                }

                spellMod->value = -aurEff->GetAmount();
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_hun_fire_AuraScript::CheckProc);
                DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_hun_fire_AuraScript::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_fire_AuraScript();
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
                GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_IMPROVED_MEND_PET, true, nullptr, aurEff);
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

// -19464 Improved Serpent Sting
class spell_hun_improved_serpent_sting : public SpellScriptLoader
{
    public:
        spell_hun_improved_serpent_sting() : SpellScriptLoader("spell_hun_improved_serpent_sting") { }

        class spell_hun_improved_serpent_sting_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_improved_serpent_sting_AuraScript);

            void HandleEffectCalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)
            {
                if (!spellMod)
                {
                    spellMod = new SpellModifier(GetAura());
                    spellMod->op = SpellModOp(aurEff->GetMiscValue());
                    spellMod->type = SPELLMOD_PCT;
                    spellMod->spellId = GetId();
                    spellMod->mask = GetSpellInfo()->Effects[aurEff->GetEffIndex()].SpellClassMask;
                }

                spellMod->value = aurEff->GetAmount();
            }

            void Register() override
            {
                DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_hun_improved_serpent_sting_AuraScript::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_improved_serpent_sting_AuraScript();
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
                int32 healthModSpellBasePoints0 = int32(caster->CountPctFromMaxHealth(30));
                caster->CastCustomSpell(caster, SPELL_HUNTER_PET_LAST_STAND_TRIGGERED, &healthModSpellBasePoints0, nullptr, nullptr, true, nullptr);
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
                        SPELL_LOCK_AND_LOAD_TRIGGER,
                        SPELL_LOCK_AND_LOAD_MARKER
                    });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (eventInfo.GetActor()->HasAura(SPELL_LOCK_AND_LOAD_MARKER))
                    return false;

                return true;
            }

            template <uint32 mask>
            void HandleProcs(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (!(eventInfo.GetTypeMask() & mask))
                    return;

                // Additional check: do not proc on traps for immolation/explosive trap
                // (But still do it for the periodic damage part)
                if (mask == PROC_FLAG_DONE_TRAP_ACTIVATION)
                    if (!(eventInfo.GetSpellInfo()->GetSchoolMask() & SPELL_SCHOOL_MASK_FROST))
                        return;

                if (!roll_chance_i(aurEff->GetAmount()))
                    return;

                Unit* caster = eventInfo.GetActor();
                caster->CastSpell(caster, SPELL_LOCK_AND_LOAD_TRIGGER, true);
                caster->CastSpell(caster, SPELL_LOCK_AND_LOAD_MARKER, true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_hun_lock_and_load_AuraScript::CheckProc);

                OnEffectProc += AuraEffectProcFn(spell_hun_lock_and_load_AuraScript::HandleProcs<PROC_FLAG_DONE_TRAP_ACTIVATION>, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
                OnEffectProc += AuraEffectProcFn(spell_hun_lock_and_load_AuraScript::HandleProcs<PROC_FLAG_DONE_PERIODIC>, EFFECT_1, SPELL_AURA_DUMMY);
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
                return ValidateSpellInfo({ SPELL_HUNTER_MASTERS_CALL_TRIGGERED, uint32(spellInfo->Effects[EFFECT_0].CalcValue()) });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* ally = GetHitUnit())
                    if (Player* caster = GetCaster()->ToPlayer())
                        if (Pet* target = caster->GetPet())
                        {
                            TriggerCastFlags castMask = TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_CASTER_AURASTATE);
                            target->CastSpell(ally, GetEffectValue(), castMask);
                        }
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                {
                    // Cannot be processed while pet is dead
                    TriggerCastFlags castMask = TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_CASTER_AURASTATE);
                    target->CastSpell(target, SPELL_HUNTER_MASTERS_CALL_TRIGGERED, castMask);
                }
            }

            void Register() override
            {
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
                    GetTarget()->ResetRedirectThreat();
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                return GetTarget()->GetRedirectThreatTarget() != nullptr;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_MISDIRECTION_PROC, true, nullptr, aurEff);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_hun_misdirection_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                DoCheckProc += AuraCheckProcFn(spell_hun_misdirection_AuraScript::CheckProc);
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
                GetTarget()->ResetRedirectThreat();
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
                    if (!caster->HasAura(SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF))
                    {
                        owner->CastCustomSpell(SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED, SPELLVALUE_BASE_POINT0, 100, caster, true);
                        caster->CastSpell(caster, SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF, true);
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

// -53228 - Rapid Recuperation
class spell_hun_rapid_recuperation : public SpellScriptLoader
{
    public:
        spell_hun_rapid_recuperation() : SpellScriptLoader("spell_hun_rapid_recuperation") { }

        class spell_hun_rapid_recuperation_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_rapid_recuperation_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_RAPID_RECUPERATION });
            }

            void HandleAbilityCast(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                // This effect only from Rapid Fire (ability cast)
                if (!(eventInfo.GetDamageInfo()->GetSpellInfo()->SpellFamilyFlags[0] & 0x20))
                    PreventDefaultAction();
            }

            void HandleFocusRegen(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                // This effect only from Rapid Killing (focus regen)
                if (!(eventInfo.GetDamageInfo()->GetSpellInfo()->SpellFamilyFlags[1] & 0x01000000))
                    return;

                int32 focus = aurEff->GetAmount();
                GetTarget()->CastCustomSpell(SPELL_HUNTER_RAPID_RECUPERATION, SPELLVALUE_BASE_POINT0, focus, GetTarget(), true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_hun_rapid_recuperation_AuraScript::HandleAbilityCast, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
                OnEffectProc += AuraEffectProcFn(spell_hun_rapid_recuperation_AuraScript::HandleFocusRegen, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_rapid_recuperation_AuraScript();
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

// 82925 - Ready, Set, Aim...
class spell_hun_ready_set_aim : public SpellScriptLoader
{
    public:
        spell_hun_ready_set_aim() : SpellScriptLoader("spell_hun_ready_set_aim") { }

        class spell_hun_ready_set_aim_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_ready_set_aim_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_FIRE });
            }

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetStackAmount() == 5)
                {
                    GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_FIRE, true, nullptr, aurEff);
                    GetTarget()->RemoveAura(GetId());
                }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_hun_ready_set_aim_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_ready_set_aim_AuraScript();
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

                    target->CastSpell(target, spellId, true, 0, aurEff);
                    if (Player* playerTarget = GetUnitOwner()->ToPlayer())
                    {
                        int32 baseAmount = aurEff->GetBaseAmount();
                        int32 amount = playerTarget->CalculateSpellDamage(playerTarget, GetSpellInfo(), aurEff->GetEffIndex(), &baseAmount);
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
                    playerTarget->CalculateSpellDamage(playerTarget, GetSpellInfo(), aurEff->GetEffIndex(), &baseAmount) :
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

// 56641 - Steady Shot
class spell_hun_steady_shot : public SpellScriptLoader
{
    public:
        spell_hun_steady_shot() : SpellScriptLoader("spell_hun_steady_shot") { }

        class spell_hun_steady_shot_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_steady_shot_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                    {
                        SPELL_HUNTER_TERMINATION_R_1,
                        SPELL_HUNTER_TERMINATION_R_2,
                        SPELL_HUNTER_STEADY_SHOT_FOCUS,
                    });
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleLaunch(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    uint32 spellId = 0;
                    if (caster->HasAura(SPELL_HUNTER_TERMINATION_R_2))
                        spellId = SPELL_HUNTER_TERMINATION_R_2;
                    else if (caster->HasAura(SPELL_HUNTER_TERMINATION_R_1))
                        spellId = SPELL_HUNTER_TERMINATION_R_1;

                    uint32 amount = 0;
                    if (SpellInfo const* focusSpell = sSpellMgr->GetSpellInfo(SPELL_HUNTER_STEADY_SHOT_FOCUS))
                        amount = focusSpell->Effects[EFFECT_0].BasePoints;

                    if (Aura* terminationAura = caster->GetAura(spellId))
                    {
                        if (Unit* spellTarget = GetExplTargetUnit())
                            if (spellTarget->GetHealthPct() <= float(terminationAura->GetSpellInfo()->Effects[EFFECT_1].BasePoints))
                                amount += terminationAura->GetEffect(EFFECT_0)->GetAmount();
                    }

                    caster->CastCustomSpell(SPELL_HUNTER_STEADY_SHOT_FOCUS, SPELLVALUE_BASE_POINT0, amount, caster, true);
                }
            }

            void Register() override
            {
                OnEffectLaunch += SpellEffectFn(spell_hun_steady_shot_SpellScript::HandleLaunch, EFFECT_0, SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_steady_shot_SpellScript();
        }
};

// 53221 - 53221 - 53224 - Improved Steady Shot
class spell_hun_improved_steady_shot : public SpellScriptLoader
{
    public:
        spell_hun_improved_steady_shot() : SpellScriptLoader("spell_hun_improved_steady_shot") { }

        class spell_hun_improved_steady_shot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_improved_steady_shot_AuraScript);

            bool Load() override
            {
                _steadyShotCounter = 0;
                return true;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_STEADY_SHOT, SPELL_HUNTER_IMPROVED_STEADY_SHOT_TRIGGERED });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (eventInfo.GetSpellInfo()->Id == SPELL_HUNTER_STEADY_SHOT)
                {
                    _steadyShotCounter++;
                    if (_steadyShotCounter == 2)
                    {
                        GetCaster()->CastCustomSpell(SPELL_HUNTER_IMPROVED_STEADY_SHOT_TRIGGERED, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetCaster(), true);
                        _steadyShotCounter = 0;
                    }
                }
                else
                    _steadyShotCounter = 0;
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_hun_improved_steady_shot_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }

        private:
            uint8 _steadyShotCounter;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_improved_steady_shot_AuraScript();
        }
};

uint32 callPetSpellIdBySlot[] =
{
    SPELL_HUNTER_CALL_PET_1,
    SPELL_HUNTER_CALL_PET_2,
    SPELL_HUNTER_CALL_PET_3,
    SPELL_HUNTER_CALL_PET_4,
    SPELL_HUNTER_CALL_PET_5
};

// 1515 - Tame Beast
class spell_hun_tame_beast : public SpellScriptLoader
{
    public:
        spell_hun_tame_beast() : SpellScriptLoader("spell_hun_tame_beast") { }

        class spell_hun_tame_beast_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_tame_beast_SpellScript);

            SpellCastResult SendTameFailResult(PetTameFailureReason reason)
            {
                Player* player = GetCaster()->ToPlayer();
                if (!player)
                    return SPELL_FAILED_DONT_REPORT;

                player->SendTamePetFailure(reason);

                return SPELL_FAILED_DONT_REPORT;
            }

            SpellCastResult CheckCast()
            {
                Player* player = GetCaster()->ToPlayer();
                if (!player)
                    return SPELL_FAILED_DONT_REPORT;

                if (!GetExplTargetUnit())
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                if (player->getClass() != CLASS_HUNTER)
                    return SendTameFailResult(PET_TAME_FAILURE_CANNOT_TAME_CREATURES);

                if (!player->GetFirstUnusedActivePetSlot())
                    return SendTameFailResult(PET_TAME_FAILURE_TOO_MANY_PETS);

                if (Optional<uint8> slot = player->GetFirstUnusedActivePetSlot())
                    if (!player->HasSpell(callPetSpellIdBySlot[*slot]))
                        return SendTameFailResult(PET_TAME_FAILURE_SLOT_LOCKED);

                if (Creature* target = GetExplTargetUnit()->ToCreature())
                {
                    if (target->getLevel() > player->getLevel())
                        return SendTameFailResult(PET_TAME_FAILURE_TOO_HIGH_LEVEL);

                    if (!target->GetCreatureTemplate()->IsTameable(player->ToPlayer()->CanTameExoticPets()))
                        return SendTameFailResult(PET_TAME_FAILURE_CANNOT_TAME_EXOTIC);

                    if (player->GetPetGUID())
                        return SendTameFailResult(PET_TAME_FAILURE_ACTIVE_SUMMON);

                    if (player->GetCharmGUID())
                        return SendTameFailResult(PET_TAME_FAILURE_CREATURE_CONTROLLED);
                }
                else
                    return SendTameFailResult(PET_TAME_FAILURE_NOT_TAMEABLE);

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

// 34497 - Thrill of the Hunt
class spell_hun_thrill_of_the_hunt : public SpellScriptLoader
{
    public:
        spell_hun_thrill_of_the_hunt() : SpellScriptLoader("spell_hun_thrill_of_the_hunt") { }

        class spell_hun_thrill_of_the_hunt_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_thrill_of_the_hunt_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_THRILL_OF_THE_HUNT });
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 focus = eventInfo.GetDamageInfo()->GetSpellInfo()->CalcPowerCost(GetTarget(), SpellSchoolMask(eventInfo.GetDamageInfo()->GetSchoolMask()));
                focus = CalculatePct(focus, aurEff->GetAmount());

                GetTarget()->CastCustomSpell(GetTarget(), SPELL_HUNTER_THRILL_OF_THE_HUNT, &focus, nullptr, nullptr, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_hun_thrill_of_the_hunt_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_thrill_of_the_hunt_AuraScript();
        }
};

// -56333 - T.N.T.
class spell_hun_tnt : public SpellScriptLoader
{
    public:
        spell_hun_tnt() : SpellScriptLoader("spell_hun_tnt") { }

        class spell_hun_tnt_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_tnt_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_LOCK_AND_LOAD });
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                return roll_chance_i(GetEffect(EFFECT_0)->GetAmount());
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_LOCK_AND_LOAD, true, nullptr, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_hun_tnt_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_hun_tnt_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_tnt_AuraScript();
        }
};

// 76659 - Wild Quiver
class spell_hun_wild_quiver : public SpellScriptLoader
{
    public:
        spell_hun_wild_quiver() : SpellScriptLoader("spell_hun_wild_quiver") { }

        class spell_hun_wild_quiver_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_wild_quiver_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_WILD_QUIVER_DAMAGE });
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                return roll_chance_i(GetEffect(EFFECT_0)->GetAmount());
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                    if (Unit* target = eventInfo.GetActionTarget())
                        caster->CastSpell(target, SPELL_HUNTER_WILD_QUIVER_DAMAGE, true, nullptr, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_hun_wild_quiver_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_hun_wild_quiver_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_wild_quiver_AuraScript();
        }
};

// 1978 - Serpent Sting
class spell_hun_serpent_sting : public SpellScriptLoader
{
    public:
        spell_hun_serpent_sting() : SpellScriptLoader("spell_hun_serpent_sting") { }

        class spell_hun_serpent_sting_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_serpent_sting_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_HUNTER_IMPROVED_SERPENT_STING_DAMAGE,
                    SPELL_HUNTER_IMPROVED_SERPENT_STING_R1,
                    SPELL_HUNTER_IMPROVED_SERPENT_STING_R2
                });
            }

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    uint32 spellId = 0;

                    if (caster->HasAura(SPELL_HUNTER_IMPROVED_SERPENT_STING_R2))
                        spellId = SPELL_HUNTER_IMPROVED_SERPENT_STING_R2;
                    else if (caster->HasAura(SPELL_HUNTER_IMPROVED_SERPENT_STING_R1))
                        spellId = SPELL_HUNTER_IMPROVED_SERPENT_STING_R1;

                    if (Aura* stingAura = caster->GetAura(spellId))
                    {
                        uint32 periodicDamage = aurEff->GetAmount() * aurEff->GetTotalTicks();
                        uint32 damage = CalculatePct(periodicDamage * stingAura->GetSpellInfo()->Effects[EFFECT_0].BasePoints, 1);
                        caster->CastCustomSpell(SPELL_HUNTER_IMPROVED_SERPENT_STING_DAMAGE, SPELLVALUE_BASE_POINT0, damage, GetTarget(), true);
                    }
                }
            }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_hun_serpent_sting_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_hun_serpent_sting_AuraScript();
    }
};

// - 53234 - Piercing Shots
class spell_hun_piercing_shots : public SpellScriptLoader
{
    public:
        spell_hun_piercing_shots() : SpellScriptLoader("spell_hun_piercing_shots") { }

        class spell_hun_piercing_shots_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_piercing_shots_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                    {
                        SPELL_HUNTER_PIERCING_SHOTS,
                        SPELL_HUNTER_AIMED_SHOT,
                        SPELL_HUNTER_AIMED_SHOT_INSTANT,
                        SPELL_HUNTER_CHIMERA_SHOT,
                        SPELL_HUNTER_STEADY_SHOT
                    });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                switch (eventInfo.GetProcSpell()->GetSpellInfo()->Id)
                {
                    case SPELL_HUNTER_AIMED_SHOT:
                    case SPELL_HUNTER_AIMED_SHOT_INSTANT:
                    case SPELL_HUNTER_CHIMERA_SHOT:
                    case SPELL_HUNTER_STEADY_SHOT:
                        return true;
                    default:
                        return false;
                }

                return false;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                uint8 tickNumber = 0;

                if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(SPELL_HUNTER_PIERCING_SHOTS))
                    tickNumber = spell->GetMaxTicks();

                if (tickNumber)
                {
                    uint32 damage = CalculatePct(eventInfo.GetDamageInfo()->GetDamage() * aurEff->GetAmount(), 1) / tickNumber;
                    GetCaster()->CastCustomSpell(SPELL_HUNTER_PIERCING_SHOTS, SPELLVALUE_BASE_POINT0, damage, eventInfo.GetActionTarget(), true);
                }
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_hun_piercing_shots_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_hun_piercing_shots_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_piercing_shots_AuraScript();
        }
};

// - 34485 - Master Marksman
class spell_hun_master_marksman : public SpellScriptLoader
{
    public:
        spell_hun_master_marksman() : SpellScriptLoader("spell_hun_master_marksman") { }

        class spell_hun_master_marksman_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_master_marksman_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_STEADY_SHOT });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcSpell()->GetSpellInfo()->Id == SPELL_HUNTER_STEADY_SHOT;
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_hun_master_marksman_AuraScript::CheckProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_master_marksman_AuraScript();
        }
};

// - 35104 - Bombardment
class spell_hun_bombardment : public SpellScriptLoader
{
    public:
        spell_hun_bombardment() : SpellScriptLoader("spell_hun_bombardment") { }

        class spell_hun_bombardment_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_bombardment_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_MULTISHOT });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcSpell()->GetSpellInfo()->Id == SPELL_HUNTER_MULTISHOT;
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_hun_bombardment_AuraScript::CheckProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hun_bombardment_AuraScript();
        }
};

class spell_hun_trap_launcher : public AuraScript
{
    PrepareAuraScript(spell_hun_trap_launcher);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_IMPROVED_STEADY_SHOT_TRIGGERED });
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_IMPROVED_STEADY_SHOT_TRIGGERED, true, nullptr, aurEff);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_HUNTER_IMPROVED_STEADY_SHOT_TRIGGERED);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_hun_trap_launcher::AfterApply, EFFECT_0, SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS_TRIGGERED, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_hun_trap_launcher::AfterRemove, EFFECT_0, SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS_TRIGGERED, AURA_EFFECT_HANDLE_REAL);
    }
};

// 63067 - Glyph of Kill Shot
class spell_hun_glyph_of_kill_shot : public AuraScript
{
    PrepareAuraScript(spell_hun_glyph_of_kill_shot);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_GLYPH_OF_KILL_SHOT_COOLDOWN });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        return (!GetTarget()->HasAura(SPELL_HUNTER_GLYPH_OF_KILL_SHOT_COOLDOWN));
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* victim = eventInfo.GetProcTarget();
        if (!victim)
            return;

        uint32 spellId = 0;
        if (SpellInfo const* spell = eventInfo.GetSpellInfo())
            spellId = spell->Id;

        if (!victim->isDead() && spellId)
        {
            GetTarget()->GetSpellHistory()->ResetCooldown(spellId, true);
            GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_GLYPH_OF_KILL_SHOT_COOLDOWN, true, nullptr, aurEff);
        }
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_hun_glyph_of_kill_shot::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_hun_glyph_of_kill_shot::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 51753 - Camouflage
class spell_hun_camouflage : public SpellScript
{
    PrepareSpellScript(spell_hun_camouflage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_CAMOUFLAGE_DURATION });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            caster->CastSpell(caster, SPELL_HUNTER_CAMOUFLAGE_DURATION, true);

            if (Player* player = caster->ToPlayer())
                if (Pet* pet = player->GetPet())
                    pet->CastSpell(pet, SPELL_HUNTER_CAMOUFLAGE_DURATION, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_hun_camouflage::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 51755 - Camouflage
class spell_hun_camouflage_duration : public AuraScript
{
    PrepareAuraScript(spell_hun_camouflage_duration);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_HUNTER_CAMOUFLAGE_PERIODIC,
                SPELL_HUNTER_CAMOUFLAGE_PERIODIC_TRIGGERED
            });
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_CAMOUFLAGE_PERIODIC, true, nullptr, aurEff);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_HUNTER_CAMOUFLAGE_PERIODIC);
        GetTarget()->RemoveAurasDueToSpell(SPELL_HUNTER_CAMOUFLAGE_PERIODIC_TRIGGERED);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_hun_camouflage_duration::AfterApply, EFFECT_0, SPELL_AURA_INTERFERE_TARGETTING, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_hun_camouflage_duration::AfterRemove, EFFECT_0, SPELL_AURA_INTERFERE_TARGETTING, AURA_EFFECT_HANDLE_REAL);
    }
};

// 80325 - Camouflage
class spell_hun_camouflage_triggered : public AuraScript
{
    PrepareAuraScript(spell_hun_camouflage_triggered);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_HUNTER_CAMOUFLAGE_PERIODIC,
                SPELL_HUNTER_CAMOUFLAGE_DURATION
            });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_HUNTER_CAMOUFLAGE_PERIODIC);
        GetTarget()->RemoveAurasDueToSpell(SPELL_HUNTER_CAMOUFLAGE_DURATION);

        if (Player* player = GetTarget()->ToPlayer())
        {
            if (Pet* pet = player->GetPet())
            {
                pet->RemoveAurasDueToSpell(SPELL_HUNTER_CAMOUFLAGE_PERIODIC);
                pet->RemoveAurasDueToSpell(SPELL_HUNTER_CAMOUFLAGE_DURATION);
            }
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_hun_camouflage_triggered::AfterRemove, EFFECT_0, SPELL_AURA_MOD_STEALTH, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_hunter_spell_scripts()
{
    new spell_hun_ancient_hysteria();
    new spell_hun_bombardment();
    RegisterSpellScript(spell_hun_camouflage);
    RegisterAuraScript(spell_hun_camouflage_duration);
    RegisterAuraScript(spell_hun_camouflage_triggered);
    new spell_hun_chimera_shot();
    new spell_hun_cobra_shot();
    new spell_hun_disengage();
    new spell_hun_fire();
    RegisterAuraScript(spell_hun_glyph_of_kill_shot);
    new spell_hun_improved_mend_pet();
    new spell_hun_improved_serpent_sting();
    new spell_hun_invigoration();
    new spell_hun_last_stand_pet();
    new spell_hun_lock_and_load();
    new spell_hun_master_marksman();
    new spell_hun_masters_call();
    new spell_hun_misdirection();
    new spell_hun_misdirection_proc();
    new spell_hun_pet_carrion_feeder();
    new spell_hun_pet_heart_of_the_phoenix();
    new spell_hun_piercing_shots();
    new spell_hun_rapid_recuperation();
    new spell_hun_readiness();
    new spell_hun_ready_set_aim();
    new spell_hun_scatter_shot();
    new spell_hun_serpent_sting();
    new spell_hun_sniper_training();
    new spell_hun_steady_shot();
    new spell_hun_improved_steady_shot();
    new spell_hun_tame_beast();
    new spell_hun_target_only_pet_and_owner();
    new spell_hun_thrill_of_the_hunt();
    new spell_hun_tnt();
    RegisterAuraScript(spell_hun_trap_launcher);
    new spell_hun_wild_quiver();
}
