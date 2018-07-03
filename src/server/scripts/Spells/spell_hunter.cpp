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
    SPELL_HUNTER_ARCANE_SHOT_FOCUS                  = 187675,
    SPELL_HUNTER_ASPECT_CHEETAH_SLOW                = 186258,
    SPELL_HUNTER_BESTIAL_WRATH                      = 19574,
    SPELL_HUNTER_CHIMERA_SHOT_HEAL                  = 53353,
    SPELL_HUNTER_EXHILARATION                       = 109304,
    SPELL_HUNTER_EXHILARATION_PET                   = 128594,
    SPELL_HUNTER_EXHILARATION_R2                    = 231546,
    SPELL_HUNTER_FIRE                               = 82926,
    SPELL_HUNTER_GENERIC_ENERGIZE_FOCUS             = 91954,
    SPELL_HUNTER_IMPROVED_MEND_PET                  = 24406,
    SPELL_HUNTER_INSANITY                           = 95809,
    SPELL_HUNTER_LOCK_AND_LOAD                      = 56453,
    SPELL_HUNTER_LONE_WOLF                          = 155228,
    SPELL_HUNTER_MASTERS_CALL_TRIGGERED             = 62305,
    SPELL_HUNTER_MISDIRECTION_PROC                  = 35079,
    SPELL_HUNTER_MULTI_SHOT_FOCUS                   = 213363,
    SPELL_HUNTER_PET_LAST_STAND_TRIGGERED           = 53479,
    SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX           = 55709,
    SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED = 54114,
    SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF    = 55711,
    SPELL_HUNTER_PET_CARRION_FEEDER_TRIGGERED       = 54045,
    SPELL_HUNTER_READINESS                          = 23989,
    SPELL_HUNTER_SERPENT_STING                      = 1978,
    SPELL_HUNTER_SNIPER_TRAINING_R1                 = 53302,
    SPELL_HUNTER_SNIPER_TRAINING_BUFF_R1            = 64418,
    SPELL_HUNTER_STEADY_SHOT_FOCUS                  = 77443,
    SPELL_HUNTER_T9_4P_GREATNESS                    = 68130,
    SPELL_ROAR_OF_SACRIFICE_TRIGGERED               = 67481
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

// 185358 - Arcane Shot
class spell_hun_arcane_shot : public SpellScriptLoader
{
    public:
        spell_hun_arcane_shot() : SpellScriptLoader("spell_hun_arcane_shot") { }

        class spell_hun_arcane_shot_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_arcane_shot_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_ARCANE_SHOT_FOCUS });
            }

            void HandleOnHit()
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_HUNTER_ARCANE_SHOT_FOCUS, true);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_hun_arcane_shot_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_arcane_shot_SpellScript();
        }
};

// 186257 - Aspect of the Cheetah
class spell_hun_aspect_cheetah : public SpellScriptLoader
{
    public:
        spell_hun_aspect_cheetah() : SpellScriptLoader("spell_hun_aspect_cheetah") { }

        class spell_hun_aspect_cheetah_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_aspect_cheetah_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo
                ({
                    SPELL_HUNTER_ASPECT_CHEETAH_SLOW
                });
            }

            void HandleOnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_ASPECT_CHEETAH_SLOW, true);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_hun_aspect_cheetah_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_MOD_INCREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
             return new spell_hun_aspect_cheetah_AuraScript();
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
                return ValidateSpellInfo({ SPELL_HUNTER_GENERIC_ENERGIZE_FOCUS, SPELL_HUNTER_SERPENT_STING });
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_HUNTER_GENERIC_ENERGIZE_FOCUS, true);

                if (Aura* aur = GetHitUnit()->GetAura(SPELL_HUNTER_SERPENT_STING, GetCaster()->GetGUID()))
                {
                    int32 newDuration = aur->GetDuration() + GetEffectValue() * IN_MILLISECONDS;
                    aur->SetDuration(std::min(newDuration, aur->GetMaxDuration()), true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hun_cobra_shot_SpellScript::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_cobra_shot_SpellScript();
        }
};

// 109304 - Exhilaration
class spell_hun_exhilaration : public SpellScriptLoader
{
    public:
        spell_hun_exhilaration() : SpellScriptLoader("spell_hun_exhilaration") { }

        class spell_hun_exhilaration_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_exhilaration_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_EXHILARATION_R2, SPELL_HUNTER_LONE_WOLF });
            }

            void HandleOnHit()
            {
                if (GetCaster()->HasAura(SPELL_HUNTER_EXHILARATION_R2) && !GetCaster()->HasAura(SPELL_HUNTER_LONE_WOLF))
                    GetCaster()->CastSpell((Unit*)nullptr, SPELL_HUNTER_EXHILARATION_PET, true);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_hun_exhilaration_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_exhilaration_SpellScript();
        }
};

// 212658 - Hunting Party
class spell_hun_hunting_party : public SpellScriptLoader
{
    public:
        spell_hun_hunting_party() : SpellScriptLoader("spell_hun_hunting_party") { }

        class spell_hun_hunting_party_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hun_hunting_party_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_HUNTER_EXHILARATION,
                    SPELL_HUNTER_EXHILARATION_PET
                });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->GetSpellHistory()->ModifyCooldown(SPELL_HUNTER_EXHILARATION, -Seconds(aurEff->GetAmount()));
                GetTarget()->GetSpellHistory()->ModifyCooldown(SPELL_HUNTER_EXHILARATION_PET, -Seconds(aurEff->GetAmount()));
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
                GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_IMPROVED_MEND_PET, true, NULL, aurEff);
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
                caster->CastCustomSpell(caster, SPELL_HUNTER_PET_LAST_STAND_TRIGGERED, &healthModSpellBasePoints0, NULL, NULL, true, NULL);
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
                return spellInfo->GetEffect(EFFECT_0) && ValidateSpellInfo({ SPELL_HUNTER_MASTERS_CALL_TRIGGERED, uint32(spellInfo->GetEffect(EFFECT_0)->CalcValue()) });
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
                if (!pet->GetCharmerGUID().IsEmpty())
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
                GetHitUnit()->CastSpell((Unit*)nullptr, SPELL_HUNTER_MASTERS_CALL_TRIGGERED, true);
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
                    GetTarget()->ResetRedirectThreat();
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                return GetTarget()->GetRedirectThreatTarget() != nullptr;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_MISDIRECTION_PROC, true, NULL, aurEff);
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

// 2643 - Multi-Shot
class spell_hun_multi_shot : public SpellScriptLoader
{
    public:
        spell_hun_multi_shot() : SpellScriptLoader("spell_hun_multi_shot") { }

        class spell_hun_multi_shot_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hun_multi_shot_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_HUNTER_MULTI_SHOT_FOCUS });
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleOnHit()
            {
                // We need to check hunter's spec because it doesn't generate focus on other specs than MM
                if (GetCaster()->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == TALENT_SPEC_HUNTER_MARKSMAN)
                    GetCaster()->CastSpell(GetCaster(), SPELL_HUNTER_MULTI_SHOT_FOCUS, true);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_hun_multi_shot_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_multi_shot_SpellScript();
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
                WorldObject* result = NULL;
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
                        owner->CastCustomSpell(SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED, SPELLVALUE_BASE_POINT0, 100, caster, true);
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
                GetCaster()->GetSpellHistory()->ResetCooldowns([](SpellHistory::CooldownStorageType::iterator itr)
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
                    GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_FIRE, true, NULL, aurEff);
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

                uint32 damage = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount());
                eventInfo.GetActor()->CastCustomSpell(SPELL_ROAR_OF_SACRIFICE_TRIGGERED, SPELLVALUE_BASE_POINT0, damage, GetCaster(), TRIGGERED_FULL_MASK, nullptr, aurEff);
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
                return ValidateSpellInfo({ SPELL_HUNTER_STEADY_SHOT_FOCUS });
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleOnHit()
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_HUNTER_STEADY_SHOT_FOCUS, true);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_hun_steady_shot_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hun_steady_shot_SpellScript();
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
                    if (target->getLevel() > caster->getLevel())
                        return SPELL_FAILED_HIGHLEVEL;

                    // use SMSG_PET_TAME_FAILURE?
                    if (!target->GetCreatureTemplate()->IsTameable(caster->ToPlayer()->CanTameExoticPets()))
                        return SPELL_FAILED_BAD_TARGETS;

                    if (!caster->GetPetGUID().IsEmpty())
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                    if (!caster->GetCharmGUID().IsEmpty())
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

// 67151 - Item - Hunter T9 4P Bonus (Steady Shot)
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

            caster->CastSpell(caster->ToPlayer()->GetPet(), SPELL_HUNTER_T9_4P_GREATNESS, true, nullptr, aurEff);
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
                GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_LOCK_AND_LOAD, true, NULL, aurEff);
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

void AddSC_hunter_spell_scripts()
{
    new spell_hun_ancient_hysteria();
    new spell_hun_arcane_shot();
    new spell_hun_aspect_cheetah();
    new spell_hun_chimera_shot();
    new spell_hun_cobra_shot();
    new spell_hun_exhilaration();
    new spell_hun_hunting_party();
    new spell_hun_improved_mend_pet();
    new spell_hun_last_stand_pet();
    new spell_hun_masters_call();
    new spell_hun_misdirection();
    new spell_hun_misdirection_proc();
    new spell_hun_multi_shot();
    new spell_hun_pet_carrion_feeder();
    new spell_hun_pet_heart_of_the_phoenix();
    new spell_hun_readiness();
    new spell_hun_ready_set_aim();
    new spell_hun_roar_of_sacrifice();
    new spell_hun_scatter_shot();
    new spell_hun_sniper_training();
    new spell_hun_steady_shot();
    new spell_hun_tame_beast();
    new spell_hun_target_only_pet_and_owner();
    new spell_hun_t9_4p_bonus();
    new spell_hun_tnt();
}
