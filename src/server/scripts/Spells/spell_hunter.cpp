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
 * Scripts for spells with SPELLFAMILY_HUNTER, SPELLFAMILY_PET and SPELLFAMILY_GENERIC spells used by hunter players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_hun_".
 */

#include "Pet.h"
#include "ScriptMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "SpellHistory.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum HunterSpells
{
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
    SPELL_HUNTER_GLYPH_OF_MEND_PET_HAPPINESS        = 57894
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_ASPECT_OF_THE_BEAST_PET))
                    return false;
                return true;
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_ASPECT_OF_THE_VIPER_ENERGIZE) ||
                    !sSpellMgr->GetSpellInfo(SPELL_HUNTER_GLYPH_OF_ASPECT_OF_THE_VIPER) ||
                    !sSpellMgr->GetSpellInfo(SPELL_HUNTER_VIPER_ATTACK_SPEED) ||
                    !sSpellMgr->GetSpellInfo(SPELL_HUNTER_VICIOUS_VIPER))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();

                uint32 maxMana = GetTarget()->GetMaxPower(POWER_MANA);
                int32 mana = CalculatePct(maxMana, GetTarget()->GetAttackTime(RANGED_ATTACK) / 1000.0f);

                if (AuraEffect const* glyph = GetTarget()->GetAuraEffect(SPELL_HUNTER_GLYPH_OF_ASPECT_OF_THE_VIPER, EFFECT_0))
                    AddPct(mana, glyph->GetAmount());

                GetTarget()->CastCustomSpell(SPELL_HUNTER_ASPECT_OF_THE_VIPER_ENERGIZE, SPELLVALUE_BASE_POINT0, mana, GetTarget(), true, NULL, aurEff);
            }

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                // Hunter T7 4P Bonus
                if (GetTarget()->HasAura(SPELL_HUNTER_VIPER_ATTACK_SPEED))
                    GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_VICIOUS_VIPER, true, NULL, aurEff);
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_CHIMERA_SHOT_SERPENT) || !sSpellMgr->GetSpellInfo(SPELL_HUNTER_CHIMERA_SHOT_VIPER) || !sSpellMgr->GetSpellInfo(SPELL_HUNTER_CHIMERA_SHOT_SCORPID))
                    return false;
                return true;
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

                                // first, calculate damage of basic tick (C&P from AuraEffect::HandlePeriodicDamageAurasTick)
                                basePoint = (aurEff->GetAmount() + aurEff->GetBonusAmount()) * aurEff->GetDonePct();
                                if (Player* modOwner = caster->GetSpellModOwner())
                                    modOwner->ApplySpellMod<SPELLMOD_DOT>(aurEff->GetSpellInfo()->Id, basePoint);
                                basePoint = unitTarget->SpellDamageBonusTaken(caster, aurEff->GetSpellInfo(), basePoint, DOT, aura->GetStackAmount());

                                // then, multiply to get damage potential
                                basePoint *= aurEff->GetTotalTicks();
                                ApplyPct(basePoint, 40);
                            }
                            // Viper Sting - Instantly restores mana to you equal to 60% of the total amount drained by your Viper Sting.
                            else if (familyFlag[1] & 0x00000080)
                            {
                                spellId = SPELL_HUNTER_CHIMERA_SHOT_VIPER;

                                // Amount of one aura tick (C&P from AuraEffect::HandlePeriodicManaLeechAuraTick)
                                basePoint = aurEff->GetAmount();
                                    // max value
                                    int32 maxmana = CalculatePct(caster->GetMaxPower(POWER_MANA), basePoint * 2.0f);
                                    ApplyPct(basePoint, caster->GetMaxPower(POWER_MANA));
                                    if (basePoint > maxmana)
                                        basePoint = maxmana;

                                basePoint = int32(CalculatePct(unitTarget->GetMaxPower(POWER_MANA), aurEff->GetAmount()));
                                int32 casterBasePoint = CalculatePct(caster->GetMaxPower(POWER_MANA), aurEff->GetAmount() * 2.0f);
                                if (basePoint > casterBasePoint)
                                    basePoint = casterBasePoint;

                                basePoint *= aurEff->GetTotalTicks();
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
                        caster->CastCustomSpell(spellId, SPELLVALUE_BASE_POINT0, basePoint, unitTarget, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD));
                    if (spellId == SPELL_HUNTER_CHIMERA_SHOT_SCORPID && caster->ToPlayer()) // Scorpid Sting - Add 1 minute cooldown
                        caster->GetSpellHistory()->AddCooldown(spellId, 0, std::chrono::minutes(1));
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_GLYPH_OF_ARCANE_SHOT))
                    return false;
                return true;
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

                GetTarget()->CastCustomSpell(SPELL_HUNTER_GLYPH_OF_ARCANE_SHOT, SPELLVALUE_BASE_POINT0, mana, GetTarget());
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_GLYPH_OF_MEND_PET_HAPPINESS))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_HUNTER_GLYPH_OF_MEND_PET_HAPPINESS, true);
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
                if (!sSpellMgr->GetSpellInfo(SPELL_REPLENISHMENT))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell((Unit*)nullptr, SPELL_REPLENISHMENT, true);
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_IMPROVED_MEND_PET))
                    return false;
                return true;
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_INVIGORATION_TRIGGERED))
                    return false;
                return true;
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_KILL_COMMAND_HUNTER))
                    return false;
                return true;
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_PET_LAST_STAND_TRIGGERED))
                    return false;
                return true;
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_LOCK_AND_LOAD_TRIGGER) ||
                    !sSpellMgr->GetSpellInfo(SPELL_HUNTER_LOCK_AND_LOAD_MARKER))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (eventInfo.GetActor()->HasAura(SPELL_HUNTER_LOCK_AND_LOAD_MARKER))
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
                    if (!(eventInfo.GetDamageInfo()->GetSchoolMask() & SPELL_SCHOOL_MASK_FROST))
                        return;

                if (!roll_chance_i(aurEff->GetAmount()))
                    return;

                Unit* caster = eventInfo.GetActor();
                caster->CastSpell(caster, SPELL_HUNTER_LOCK_AND_LOAD_TRIGGER, true);
                caster->CastSpell(caster, SPELL_HUNTER_LOCK_AND_LOAD_MARKER, true);
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_MASTERS_CALL_TRIGGERED) || !sSpellMgr->GetSpellInfo(spellInfo->Effects[EFFECT_0].CalcValue()) || !sSpellMgr->GetSpellInfo(spellInfo->Effects[EFFECT_1].CalcValue()))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* ally = GetHitUnit())
                    if (Player* caster = GetCaster()->ToPlayer())
                        if (Pet* target = caster->GetPet())
                        {
                            TriggerCastFlags castMask = TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_CASTER_AURASTATE);
                            target->CastSpell(ally, GetEffectValue(), castMask);
                            target->CastSpell(ally, GetSpellInfo()->Effects[EFFECT_0].CalcValue(), castMask);
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_MISDIRECTION_PROC))
                    return false;
                return true;
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_PET_CARRION_FEEDER_TRIGGERED))
                    return false;
                return true;
            }

            SpellCastResult CheckIfCorpseNear()
            {
                Unit* caster = GetCaster();
                float max_range = GetSpellInfo()->GetMaxRange(false);
                WorldObject* result = NULL;
                // search for nearby enemy corpse in range
                Trinity::AnyDeadUnitSpellTargetInRangeCheck check(caster, max_range, GetSpellInfo(), TARGET_CHECK_ENEMY);
                Trinity::WorldObjectSearcher<Trinity::AnyDeadUnitSpellTargetInRangeCheck> searcher(caster, result, check);
                caster->GetMap()->VisitFirstFound(caster->m_positionX, caster->m_positionY, max_range, searcher);
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED) || !sSpellMgr->GetSpellInfo(SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF))
                    return false;
                return true;
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
            if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_PIERCING_SHOTS))
                return false;
            return true;
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
                int32 duration = piercingShots->GetMaxDuration();
                uint32 amplitude = piercingShots->Effects[EFFECT_0].Amplitude;
                uint32 dmg = dmgInfo->GetDamage();

                uint32 bp = CalculatePct(int32(dmg), aurEff->GetAmount()) / (duration / int32(amplitude));
                bp += target->GetRemainingPeriodicAmount(target->GetGUID(), SPELL_HUNTER_PIERCING_SHOTS, SPELL_AURA_PERIODIC_DAMAGE);

                caster->CastCustomSpell(SPELL_HUNTER_PIERCING_SHOTS, SPELLVALUE_BASE_POINT0, bp, target, true, nullptr, aurEff);
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
                if (!sSpellMgr->GetSpellInfo(spellInfo->Effects[EFFECT_0].TriggerSpell))
                    return false;
                return true;
            }

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                PreventDefaultAction();

                Unit* target = GetTarget();
                uint32 mana = CalculatePct(target->GetMaxPower(POWER_MANA), aurEff->GetAmount());

                target->CastCustomSpell(GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, SPELLVALUE_BASE_POINT0, int32(mana), target, true, nullptr, aurEff);
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_RAPID_RECUPERATION_MANA_R1) ||
                    !sSpellMgr->GetSpellInfo(SPELL_HUNTER_RAPID_RECUPERATION_MANA_R2))
                    return false;
                return true;
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

            void HandleRapidKillingProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                static uint32 const triggerSpells[2] = { SPELL_HUNTER_RAPID_RECUPERATION_MANA_R1, SPELL_HUNTER_RAPID_RECUPERATION_MANA_R2 };

                PreventDefaultAction();

                // Proc only from Rapid Killing
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo || !(spellInfo->SpellFamilyFlags[1] & 0x01000000))
                    return;

                uint8 rank = GetSpellInfo()->GetRank();
                uint32 spellId = triggerSpells[rank - 1];
                eventInfo.GetActor()->CastSpell((Unit*)nullptr, spellId, true);
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
                if (!sSpellMgr->GetSpellInfo(SPELL_ROAR_OF_SACRIFICE_TRIGGERED))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return GetCaster() && (eventInfo.GetDamageInfo()->GetSchoolMask() & GetEffect(EFFECT_1)->GetMiscValue()) != 0;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                uint32 damage = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount());
                eventInfo.GetActor()->CastCustomSpell(SPELL_ROAR_OF_SACRIFICE_TRIGGERED, SPELLVALUE_BASE_POINT0, damage, GetCaster(), TRIGGERED_FULL_MASK, nullptr, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_hun_roar_of_sacrifice_AuraScript::CheckProc);
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_SNIPER_TRAINING_R1) || !sSpellMgr->GetSpellInfo(SPELL_HUNTER_SNIPER_TRAINING_BUFF_R1))
                    return false;
                return true;
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

                    if (caster->GetPetGUID())
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                    if (caster->GetCharmGUID())
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_THRILL_OF_THE_HUNT_MANA))
                    return false;
                return true;
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
                        amount /= explosiveShot->GetSpellInfo()->GetMaxTicks();
                    }
                }
                else
                    amount = CalculatePct(static_cast<int32>(spellInfo->CalcPowerCost(caster, spellInfo->GetSchoolMask())), aurEff->GetAmount());

                if (!amount)
                    return;

                caster->CastCustomSpell(SPELL_HUNTER_THRILL_OF_THE_HUNT_MANA, SPELLVALUE_BASE_POINT0, amount, (Unit*)nullptr, true);
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
            if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_T9_4P_GREATNESS))
                return false;
            return true;
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
                if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_ASPECT_OF_THE_VIPER) ||
                    !sSpellMgr->GetSpellInfo(SPELL_HUNTER_VICIOUS_VIPER))
                    return false;
                return true;
            }

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->HasAura(SPELL_HUNTER_ASPECT_OF_THE_VIPER))
                    GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_VICIOUS_VIPER, true, NULL, aurEff);
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

void AddSC_hunter_spell_scripts()
{
    new spell_hun_aspect_of_the_beast();
    new spell_hun_ascpect_of_the_viper();
    new spell_hun_chimera_shot();
    new spell_hun_disengage();
    new spell_hun_glyph_of_arcane_shot();
    new spell_hun_glyph_of_mend_pet();
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
}
