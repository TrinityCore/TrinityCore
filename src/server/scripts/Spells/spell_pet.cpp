/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_DEATHKNIGHT and SPELLFAMILY_GENERIC spells used by deathknight players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dk_".
 */

#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum HunterPetCalculate
{
     SPELL_TAMED_PET_PASSIVE_06         = 19591,
     SPELL_TAMED_PET_PASSIVE_07         = 20784,
     SPELL_TAMED_PET_PASSIVE_08         = 34666,
     SPELL_TAMED_PET_PASSIVE_09         = 34667,
     SPELL_TAMED_PET_PASSIVE_10         = 34675,
     SPELL_HUNTER_PET_SCALING_01        = 34902,
     SPELL_HUNTER_PET_SCALING_02        = 34903,
     SPELL_HUNTER_PET_SCALING_03        = 34904,
     SPELL_HUNTER_PET_SCALING_04        = 61017,
};

enum WarlockPetCalculate
{
     SPELL_PET_PASSIVE_CRIT             = 35695,
     SPELL_PET_PASSIVE_DAMAGE_TAKEN     = 35697,
     SPELL_WARLOCK_PET_SCALING_01       = 34947,
     SPELL_WARLOCK_PET_SCALING_02       = 34956,
     SPELL_WARLOCK_PET_SCALING_03       = 34957,
     SPELL_WARLOCK_PET_SCALING_04       = 34958,
     SPELL_WARLOCK_PET_SCALING_05       = 61013,
};

enum DKPetCalculate
{
    SPELL_DEATH_KNIGHT_PET_SCALING_01   = 54566,
    SPELL_DEATH_KNIGHT_PET_SCALING_02   = 51996,
    SPELL_DEATH_KNIGHT_PET_SCALING_03   = 61697,
};

enum ShamanPetCalculate
{
    SPELL_FERAL_SPIRIT_PET_UNK_01      = 35674,
    SPELL_FERAL_SPIRIT_PET_UNK_02      = 35675,
    SPELL_FERAL_SPIRIT_PET_UNK_03      = 35676,
    SPELL_FERAL_SPIRIT_PET_SCALING_04  = 61783,
};

enum MiscPetCalculate
{
     SPELL_MAGE_PET_PASSIVE_ELEMENTAL   = 44559,
     SPELL_PET_HEALTH_SCALING           = 61679,
     SPELL_PET_UNK_01                   = 67561,
     SPELL_PET_UNK_01                   = 67557,
};

class spell_gen_pet_calculate : public SpellScriptLoader
{
    public:
        spell_gen_pet_calculate() : SpellScriptLoader("spell_gen_pet_calculate") { }

        class spell_gen_pet_calculate_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_gen_pet_calculate_AuraScript);

            bool Load()
            {
                if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
                    return false;
                return true;
            }

            void CalculateAmountCritSpell(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Player* owner = GetCaster()->GetOwner()->ToPlayer())
                {
                    // For others recalculate it from:
                    float CritSpell = 0.0f;
                    // Crit from Intellect
                    CritSpell += owner->GetSpellCritFromIntellect();
                    // Increase crit from SPELL_AURA_MOD_SPELL_CRIT_CHANCE
                    CritSpell += owner->GetTotalAuraModifier(SPELL_AURA_MOD_SPELL_CRIT_CHANCE);
                    // Increase crit from SPELL_AURA_MOD_CRIT_PCT
                    CritSpell += owner->GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_PCT);
                    // Increase crit spell from spell crit ratings
                    CritSpell += owner->GetRatingBonusValue(CR_CRIT_SPELL);

                    amount += int32(CritSpell);
                }
            }

            void CalculateAmountCritMelee(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Player* owner = GetCaster()->GetOwner()->ToPlayer())
                {
                    // For others recalculate it from:
                    float CritMelee = 0.0f;
                    // Crit from Agility
                    CritMelee += owner->GetMeleeCritFromAgility();
                    // Increase crit from SPELL_AURA_MOD_WEAPON_CRIT_PERCENT
                    CritMelee += owner->GetTotalAuraModifier(SPELL_AURA_MOD_WEAPON_CRIT_PERCENT);
                    // Increase crit from SPELL_AURA_MOD_CRIT_PCT
                    CritMelee += owner->GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_PCT);
                    // Increase crit melee from melee crit ratings
                    CritMelee += owner->GetRatingBonusValue(CR_CRIT_MELEE);

                    amount += int32(CritMelee);
                }
            }

            void CalculateAmountMeleeHit(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Player* owner = GetCaster()->GetOwner()->ToPlayer())
                {
                    // For others recalculate it from:
                    float HitMelee = 0.0f;
                    // Increase hit from SPELL_AURA_MOD_HIT_CHANCE
                    HitMelee += owner->GetTotalAuraModifier(SPELL_AURA_MOD_HIT_CHANCE);
                    // Increase hit melee from meele hit ratings
                    HitMelee += owner->GetRatingBonusValue(CR_HIT_MELEE);

                    amount += int32(HitMelee);
                }
            }

            void CalculateAmountSpellHit(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Player* owner = GetCaster()->GetOwner()->ToPlayer())
                {
                    // For others recalculate it from:
                    float HitSpell = 0.0f;
                    // Increase hit from SPELL_AURA_MOD_SPELL_HIT_CHANCE
                    HitSpell += owner->GetTotalAuraModifier(SPELL_AURA_MOD_SPELL_HIT_CHANCE);
                    // Increase hit spell from spell hit ratings
                    HitSpell += owner->GetRatingBonusValue(CR_HIT_SPELL);

                    amount += int32(HitSpell);
                }
            }

            void CalculateAmountExpertise(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Player* owner = GetCaster()->GetOwner()->ToPlayer())
                {
                    // For others recalculate it from:
                    float Expertise = 0.0f;
                    // Increase hit from SPELL_AURA_MOD_EXPERTISE
                    Expertise += owner->GetTotalAuraModifier(SPELL_AURA_MOD_EXPERTISE);
                    // Increase Expertise from Expertise ratings
                    Expertise += owner->GetRatingBonusValue(CR_EXPERTISE);

                    amount += int32(Expertise);
                }
            }

            void Register()
            {
                switch (m_scriptSpellId)
                {
                    case SPELL_TAMED_PET_PASSIVE_06:
                        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_pet_calculate_AuraScript::CalculateAmountCritMelee, EFFECT_0, SPELL_AURA_MOD_WEAPON_CRIT_PERCENT);
                        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_pet_calculate_AuraScript::CalculateAmountCritSpell, EFFECT_1, SPELL_AURA_MOD_SPELL_CRIT_CHANCE);
                        break;
                    case SPELL_PET_PASSIVE_CRIT:
                        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_pet_calculate_AuraScript::CalculateAmountCritSpell, EFFECT_0, SPELL_AURA_MOD_SPELL_CRIT_CHANCE);
                        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_pet_calculate_AuraScript::CalculateAmountCritMelee, EFFECT_1, SPELL_AURA_MOD_WEAPON_CRIT_PERCENT);
                        break;
                    case SPELL_WARLOCK_PET_SCALING_05:
                    case SPELL_HUNTER_PET_SCALING_04:
                        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_pet_calculate_AuraScript::CalculateAmountMeleeHit, EFFECT_0, SPELL_AURA_MOD_HIT_CHANCE);
                        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_pet_calculate_AuraScript::CalculateAmountSpellHit, EFFECT_1, SPELL_AURA_MOD_SPELL_HIT_CHANCE);
                        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_pet_calculate_AuraScript::CalculateAmountExpertise, EFFECT_2, SPELL_AURA_MOD_EXPERTISE);
                        break;
                    case SPELL_DEATH_KNIGHT_PET_SCALING_03:
                    case SPELL_SHAMAN_PET_HIT:
                        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_pet_calculate_AuraScript::CalculateAmountMeleeHit, EFFECT_0, SPELL_AURA_MOD_HIT_CHANCE);
                        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_pet_calculate_AuraScript::CalculateAmountSpellHit, EFFECT_1, SPELL_AURA_MOD_SPELL_HIT_CHANCE);
                        break;
                    default:
                        break;
                }
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_gen_pet_calculate_AuraScript();
        }
};

void AddSC_pet_spell_scripts()
{
    new spell_gen_pet_calculate();
}
