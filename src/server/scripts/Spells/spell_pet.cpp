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
 * Scripts for spells with SPELLFAMILY_DEATHKNIGHT and SPELLFAMILY_GENERIC spells used by deathknight players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dk_".
 */

#include "DBCStores.h"
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Unit.h"

enum HunterPetCalculate
{
    SPELL_TAMED_PET_PASSIVE_09          = 34667,
    SPELL_TAMED_PET_PASSIVE_10          = 34675,
    SPELL_HUNTER_PET_SCALING_01         = 34902,
    SPELL_HUNTER_PET_SCALING_02         = 34903,
    SPELL_HUNTER_PET_SCALING_03         = 34904,
    SPELL_HUNTER_PET_SCALING_04         = 61017,
    SPELL_HUNTER_PET_SCALING_05         = 89446,

    SPELL_HUNTER_PET_CUNNING_MARKER     = 87884,
    SPELL_HUNTER_PET_FEROCITY_MARKER    = 87887,
    SPELL_HUNTER_PET_TENACITY_MARKER    = 87891,
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
    SPELL_WARLOCK_GLYPH_OF_VOIDWALKER  = 56247,
};

enum DKPetCalculate
{
    SPELL_DEATH_KNIGHT_RUNE_WEAPON_02       = 51906,
    SPELL_DEATH_KNIGHT_PET_SCALING_01       = 54566,
    SPELL_DEATH_KNIGHT_PET_SCALING_02       = 51996,
    SPELL_DEATH_KNIGHT_PET_SCALING_03       = 61697,
    SPELL_DEATH_KNIGHT_PET_SCALING_05       = 110474,
    SPELL_NIGHT_OF_THE_DEAD                 = 55620,
    SPELL_DEATH_KNIGHT_GLYPH_OF_GHOUL       = 58686,
    DEATH_KNIGHT_ICON_ID_GLYPH_OF_RAISE_DEAD = 221,
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
};

class spell_warl_pet_scaling_01 : public AuraScript
{
    PrepareAuraScript(spell_warl_pet_scaling_01);

    void CalculateStaminaAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;

        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float stamina = owner->GetStat(STAT_STAMINA);
                float healthBonus = 0.0f;
                switch (pet->GetEntry())
                {
                    case ENTRY_IMP:
                        healthBonus = uint32(stamina * 8.4f);
                        break;
                    case ENTRY_FELGUARD:
                    case ENTRY_VOIDWALKER:
                        healthBonus = uint32(stamina * 11.0f);
                        break;
                    case ENTRY_SUCCUBUS:
                        healthBonus = uint32(stamina * 9.1f);
                        break;
                    case ENTRY_FELHUNTER:
                        healthBonus = uint32(stamina * 9.5f);
                        break;
                    default:
                        break;
                }

                float ownerHealth = owner->CountPctFromMaxHealth(75);
                amount = int32(ownerHealth + healthBonus);
            }
        }
    }

    void CalculateAttackPowerAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                int32 fire = owner->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_FIRE);
                int32 shadow = owner->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SHADOW);

                amount = std::max(fire, shadow) * 0.57f;
            }
        }
    }

    void CalculateDamageDoneAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                int32 fire = owner->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_FIRE);
                int32 shadow = owner->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SHADOW);

                amount = std::max(fire, shadow) * 0.5f;
            }
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_scaling_01::CalculateStaminaAmount, EFFECT_0, SPELL_AURA_MOD_MAX_HEALTH);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_scaling_01::CalculateAttackPowerAmount, EFFECT_1, SPELL_AURA_MOD_ATTACK_POWER);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_scaling_01::CalculateDamageDoneAmount, EFFECT_2, SPELL_AURA_MOD_DAMAGE_DONE);
    }
};

class spell_warl_pet_scaling_02 : public AuraScript
{
    PrepareAuraScript(spell_warl_pet_scaling_02);

    void CalculateIntellectAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float intellect = owner->GetStat(STAT_INTELLECT);
                float manaBonus = 0.0f;
                switch (pet->GetEntry())
                {
                    case ENTRY_IMP:
                        manaBonus = uint32(intellect * 4.9f);
                        break;
                    case ENTRY_FELGUARD:
                    case ENTRY_VOIDWALKER:
                    case ENTRY_SUCCUBUS:
                    case ENTRY_FELHUNTER:
                        manaBonus = uint32(intellect * 11.5f);
                        break;
                    default:
                        break;
                }

                float ownerMana = CalculatePct(owner->GetMaxPower(POWER_MANA), 30);
                amount = int32(ownerMana + manaBonus);
            }
        }
    }

    void CalculateArmorAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float ownerBonus = 0.0f;
                ownerBonus = CalculatePct(owner->GetArmor(), 35);
                amount = ownerBonus;
            }
        }
    }

    void CalculateFireResistanceAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float ownerBonus = 0.0f;
                ownerBonus = CalculatePct(owner->GetResistance(SPELL_SCHOOL_MASK_FIRE), 40);
                amount = ownerBonus;
            }
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_scaling_02::CalculateIntellectAmount, EFFECT_0, SPELL_AURA_MOD_INCREASE_ENERGY);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_scaling_02::CalculateArmorAmount, EFFECT_1, SPELL_AURA_MOD_RESISTANCE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_scaling_02::CalculateFireResistanceAmount, EFFECT_2, SPELL_AURA_MOD_RESISTANCE);
    }
};

class spell_warl_pet_scaling_03 : public AuraScript
{
    PrepareAuraScript(spell_warl_pet_scaling_03);

    void CalculateResistanceAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
    {
        // Formular: owner resistance of targeted school * 0.4
        canBeRecalculated = true;
        int32 resistanceSchool = GetSpellInfo()->Effects[aurEff->GetEffIndex()].MiscValue;

        if (Pet* pet = GetUnitOwner()->ToPet())
            if (Player* owner = pet->GetOwner())
                amount = uint32(owner->GetResistance(SpellSchoolMask(resistanceSchool)) * 0.4);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_scaling_03::CalculateResistanceAmount, EFFECT_ALL, SPELL_AURA_MOD_RESISTANCE);
    }
};

class spell_warl_pet_scaling_04 : public AuraScript
{
    PrepareAuraScript(spell_warl_pet_scaling_04);

    void CalculateResistanceAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
    {
        // Formular: owner resistance of targeted school * 0.4
        canBeRecalculated = true;
        int32 resistanceSchool = GetSpellInfo()->Effects[aurEff->GetEffIndex()].MiscValue;

        if (Pet* pet = GetUnitOwner()->ToPet())
            if (Player* owner = pet->GetOwner())
                amount = uint32(owner->GetResistance(SpellSchoolMask(resistanceSchool)) * 0.4);
    }

    void CalculatePowerRegen(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            // For others recalculate it from:
            float regen = 0.0f;
            // Increase regen from new max power
            regen += pet->GetMaxPower(POWER_MANA) * 0.02;

            amount += int32(regen);
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_scaling_04::CalculateResistanceAmount, EFFECT_0, SPELL_AURA_MOD_RESISTANCE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_scaling_04::CalculatePowerRegen, EFFECT_1, SPELL_AURA_MOD_POWER_REGEN);
    }
};

class spell_warl_pet_scaling_05 : public AuraScript
{
    PrepareAuraScript(spell_warl_pet_scaling_05);

    void CalculateMeleeHitChanceBonusAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float hitChance = 0.0f;
                hitChance += owner->GetTotalAuraModifier(SPELL_AURA_MOD_HIT_CHANCE);
                hitChance += owner->GetRatingBonusValue(CR_HIT_MELEE);
                amount += int32(hitChance);
            }
        }
    }

    void CalculateSpellHitChanceBonusAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float hitChance = 0.0f;
                hitChance += owner->GetTotalAuraModifier(SPELL_AURA_MOD_SPELL_HIT_CHANCE);
                hitChance += owner->GetRatingBonusValue(CR_HIT_SPELL);
                amount += int32(hitChance);
            }
        }
    }

    void CalculateExpertiseBonusAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float expertise = 0.0f;
                expertise += owner->GetTotalAuraModifier(SPELL_AURA_MOD_EXPERTISE);
                expertise += owner->GetRatingBonusValue(CR_EXPERTISE);
                amount += int32(expertise);
            }
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_scaling_05::CalculateMeleeHitChanceBonusAmount, EFFECT_0, SPELL_AURA_MOD_HIT_CHANCE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_scaling_05::CalculateSpellHitChanceBonusAmount, EFFECT_1, SPELL_AURA_MOD_SPELL_HIT_CHANCE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_scaling_05::CalculateExpertiseBonusAmount, EFFECT_2, SPELL_AURA_MOD_EXPERTISE);
    }
};

class spell_warl_pet_scaling_06 : public AuraScript
{
    PrepareAuraScript(spell_warl_pet_scaling_06);

    void CalculateCritChanceBonus(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
            if (Player* owner = pet->GetOwner())
                amount = uint32(owner->GetFloatValue(PLAYER_RANGED_CRIT_PERCENTAGE));
    }

    void CalculateMeleeHasteAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
            if (Player* owner = pet->GetOwner())
                if (float meleeHaste = (1.0f - owner->m_modAttackSpeedPct[BASE_ATTACK]) * 100.0f)
                    amount += int32(meleeHaste);
    }

    void Register()
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_scaling_06::CalculateMeleeHasteAmount, EFFECT_0, SPELL_AURA_MOD_CRIT_PCT);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_scaling_06::CalculateMeleeHasteAmount, EFFECT_1, SPELL_AURA_MELEE_SLOW);
    }
};

class spell_warl_pet_passive : public AuraScript
{
    PrepareAuraScript(spell_warl_pet_passive);

    bool Load() override
    {
        if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
            return false;
        return true;
    }

    void CalculateAmountCritSpell(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
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

            amount += CritSpell;
        }
    }

    void CalculateAmountCritMelee(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
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

            amount += CritMelee;
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_passive::CalculateAmountCritSpell, EFFECT_0, SPELL_AURA_MOD_SPELL_CRIT_CHANCE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_pet_passive::CalculateAmountCritMelee, EFFECT_1, SPELL_AURA_MOD_WEAPON_CRIT_PERCENT);
    }
};

class spell_sha_pet_scaling_04 : public SpellScriptLoader
{
public:
    spell_sha_pet_scaling_04() : SpellScriptLoader("spell_sha_pet_scaling_04") { }

    class spell_sha_pet_scaling_04_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_pet_scaling_04_AuraScript);

        bool Load() override
        {
            if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
                return false;
            return true;
        }

        void CalculateAmountMeleeHit(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
        {
            canBeRecalculated = true;
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

        void CalculateAmountSpellHit(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
        {
            canBeRecalculated = true;
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

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_sha_pet_scaling_04_AuraScript::CalculateAmountMeleeHit, EFFECT_0, SPELL_AURA_MOD_HIT_CHANCE);
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_sha_pet_scaling_04_AuraScript::CalculateAmountSpellHit, EFFECT_1, SPELL_AURA_MOD_SPELL_HIT_CHANCE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_pet_scaling_04_AuraScript();
    }
};

class spell_hun_pet_scaling_01 : public AuraScript
{
    PrepareAuraScript(spell_hun_pet_scaling_01);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_HUNTER_PET_FEROCITY_MARKER,
                SPELL_HUNTER_PET_TENACITY_MARKER,
                SPELL_HUNTER_PET_CUNNING_MARKER
            });
    }

    void CalculateHealthAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                // Base Health value for all pets at level 85 is 32,474
                int32 bonus = int32(owner->GetCreateHealth() * 0.831877f);

                // Apply health scaling bonuses based on pet type
                float mod = 0.0f;
                if (pet->HasAura(SPELL_HUNTER_PET_FEROCITY_MARKER))
                    mod = 0.67f;
                else if (pet->HasAura(SPELL_HUNTER_PET_TENACITY_MARKER))
                    mod = 0.78f;
                else if (pet->HasAura(SPELL_HUNTER_PET_CUNNING_MARKER))
                    mod = 0.725f;

                bonus += int32(owner->GetMaxHealth() * mod);
                amount = bonus;
            }
        }
    }

    void CalculateAttackPowerAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float agility = std::max(0.0f, owner->GetCreateStat(STAT_AGILITY) - 20.0f);
                // Base attack power value at level 85 is 932
                int32 bonus = int32(agility* 4.8541f);

                // All pets gain 42.5% from owners attack power
                bonus += owner->GetTotalAttackPowerValue(RANGED_ATTACK) * 0.425f;
                amount = bonus;
            }
        }
    }

    void CalculateDamageDoneAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        // Formular: Owner ranged attack power * 0.4
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
            if (Player* owner = pet->GetOwner())
                amount = uint32(owner->GetTotalAttackPowerValue(RANGED_ATTACK) * 0.4f);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_01::CalculateHealthAmount, EFFECT_0, SPELL_AURA_MOD_MAX_HEALTH);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_01::CalculateAttackPowerAmount, EFFECT_1, SPELL_AURA_MOD_ATTACK_POWER);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_01::CalculateDamageDoneAmount, EFFECT_2, SPELL_AURA_MOD_DAMAGE_DONE);
    }
};

class spell_hun_pet_scaling_02 : public AuraScript
{
    PrepareAuraScript(spell_hun_pet_scaling_02);

    void CalculateResistanceAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
    {
        // Formular: owner resistance of targeted school * 0.4
        canBeRecalculated = true;
        int32 resistanceSchool = GetSpellInfo()->Effects[aurEff->GetEffIndex()].MiscValue;

        if (Pet* pet = GetUnitOwner()->ToPet())
            if (Player* owner = pet->GetOwner())
                amount = uint32(owner->GetResistance(SpellSchoolMask(resistanceSchool)) * 0.4);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_02::CalculateResistanceAmount, EFFECT_ALL, SPELL_AURA_MOD_RESISTANCE);
    }
};

class spell_hun_pet_scaling_03 : public AuraScript
{
    PrepareAuraScript(spell_hun_pet_scaling_03);

    void CalculateResistanceAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
    {
        // Formular: owner resistance of targeted school * 0.4
        canBeRecalculated = true;
        int32 resistanceSchool = GetSpellInfo()->Effects[aurEff->GetEffIndex()].MiscValue;

        if (Pet* pet = GetUnitOwner()->ToPet())
            if (Player* owner = pet->GetOwner())
                amount = uint32(owner->GetResistance(SpellSchoolMask(resistanceSchool)) * 0.4);
    }

    void CalculateArmorAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        int32 resistanceSchool = GetSpellInfo()->Effects[aurEff->GetEffIndex()].MiscValue;

        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                // 11,647 armor baseline at level 85
                int32 bonus = int32(owner->GetCreateHealth() * 0.2983579f);

                // Apply armor scaling bonuses based on pet type
                float mod = 0.0f;
                if (pet->HasAura(SPELL_HUNTER_PET_FEROCITY_MARKER))
                    mod = 0.50f;
                else if (pet->HasAura(SPELL_HUNTER_PET_TENACITY_MARKER))
                    mod = 0.70f;
                else if (pet->HasAura(SPELL_HUNTER_PET_CUNNING_MARKER))
                    mod = 0.60f;

                bonus += int32(owner->GetArmor() * mod);
                amount = bonus;
            }
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_03::CalculateResistanceAmount, EFFECT_0, SPELL_AURA_MOD_RESISTANCE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_03::CalculateResistanceAmount, EFFECT_1, SPELL_AURA_MOD_RESISTANCE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_03::CalculateArmorAmount, EFFECT_2, SPELL_AURA_MOD_RESISTANCE);
    }
};

class spell_hun_pet_scaling_04 : public AuraScript
{
    PrepareAuraScript(spell_hun_pet_scaling_04);

    void CalculateMeleeHitChanceBonusAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float hitChance = 0.0f;
                hitChance += owner->GetTotalAuraModifier(SPELL_AURA_MOD_HIT_CHANCE);
                hitChance += owner->GetRatingBonusValue(CR_HIT_MELEE);
                amount += int32(hitChance);
            }
        }
    }

    void CalculateSpellHitChanceBonusAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float hitChance = 0.0f;
                hitChance += owner->GetTotalAuraModifier(SPELL_AURA_MOD_SPELL_HIT_CHANCE);
                hitChance += owner->GetRatingBonusValue(CR_HIT_SPELL);
                amount += int32(hitChance);
            }
        }
    }

    void CalculateExpertiseBonusAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float expertise = 0.0f;
                expertise += owner->GetTotalAuraModifier(SPELL_AURA_MOD_EXPERTISE);
                expertise += owner->GetRatingBonusValue(CR_EXPERTISE);
                amount += int32(expertise);
            }
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_04::CalculateMeleeHitChanceBonusAmount, EFFECT_0, SPELL_AURA_MOD_HIT_CHANCE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_04::CalculateSpellHitChanceBonusAmount, EFFECT_1, SPELL_AURA_MOD_SPELL_HIT_CHANCE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_04::CalculateExpertiseBonusAmount, EFFECT_2, SPELL_AURA_MOD_EXPERTISE);
    }
};

class spell_hun_pet_scaling_05 : public AuraScript
{
    PrepareAuraScript(spell_hun_pet_scaling_05);

    void CalculateCritChanceBonus(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
            if (Player* owner = pet->GetOwner())
                amount = uint32(owner->GetFloatValue(PLAYER_RANGED_CRIT_PERCENTAGE));
    }

    void CalculateMeleeHasteAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
            if (Player* owner = pet->GetOwner())
                if (float meleeHaste = (1.0f - owner->m_modAttackSpeedPct[BASE_ATTACK]) * 100.0f)
                    amount += int32(meleeHaste);
    }

    void Register()
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_05::CalculateMeleeHasteAmount, EFFECT_0, SPELL_AURA_MOD_CRIT_PCT);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_05::CalculateMeleeHasteAmount, EFFECT_1, SPELL_AURA_MELEE_SLOW);
    }
};

class spell_hun_pet_passive_crit : public AuraScript
{
    PrepareAuraScript(spell_hun_pet_passive_crit);

    bool Load() override
    {
        if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
            return false;
        return true;
    }

    void CalculateAmountCritSpell(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (!GetCaster() || !GetCaster()->GetOwner())
            return;
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

            amount += CritSpell;
        }
    }

    void CalculateAmountCritMelee(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (!GetCaster() || !GetCaster()->GetOwner())
            return;
        if (Player *owner = GetCaster()->GetOwner()->ToPlayer())
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

            amount += CritMelee;
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_passive_crit::CalculateAmountCritSpell, EFFECT_1, SPELL_AURA_MOD_SPELL_CRIT_CHANCE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_passive_crit::CalculateAmountCritMelee, EFFECT_0, SPELL_AURA_MOD_WEAPON_CRIT_PERCENT);
    }
};

class spell_dk_avoidance_passive : public SpellScriptLoader
{
public:
    spell_dk_avoidance_passive() : SpellScriptLoader("spell_dk_avoidance_passive") { }

    class spell_dk_avoidance_passive_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_avoidance_passive_AuraScript);

        bool Load() override
        {
            if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
                return false;
            return true;
        }

        void CalculateAvoidanceAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
        {
            canBeRecalculated = true;
            if (Unit* pet = GetUnitOwner())
            {
                if (Unit* owner = pet->GetOwner())
                {
                    // Army of the dead ghoul
                    if (pet->GetEntry() == ENTRY_ARMY_OF_THE_DEAD_GHOUL)
                        amount = -90;
                    // Night of the dead
                    else if (Aura* aur = owner->GetAuraOfRankedSpell(SPELL_NIGHT_OF_THE_DEAD))
                        amount = aur->GetSpellInfo()->Effects[EFFECT_2].CalcValue();
                }
            }
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_avoidance_passive_AuraScript::CalculateAvoidanceAmount, EFFECT_0, SPELL_AURA_MOD_CREATURE_AOE_DAMAGE_AVOIDANCE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_avoidance_passive_AuraScript();
    }
};

class spell_dk_pet_scaling_01 : public AuraScript
{
    PrepareAuraScript(spell_dk_pet_scaling_01);

    bool Load() override
    {
        if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
            return false;
        return true;
    }

    void CalculateStaminaAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                uint8 percentage = 30;

                // Glyph of Raise Dead
                if (AuraEffect const* aurEff = owner->GetDummyAuraEffect(SPELLFAMILY_DEATHKNIGHT, DEATH_KNIGHT_ICON_ID_GLYPH_OF_RAISE_DEAD, EFFECT_0))
                    percentage += aurEff->GetAmount();

                amount = int32(CalculatePct(owner->GetStat(STAT_STAMINA), percentage));
            }
        }
    }

    void CalculateStrengthAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                uint8 percentage = 70;

                // Glyph of Raise Dead
                if (AuraEffect const* aurEff = owner->GetDummyAuraEffect(SPELLFAMILY_DEATHKNIGHT, DEATH_KNIGHT_ICON_ID_GLYPH_OF_RAISE_DEAD, EFFECT_0))
                    percentage += aurEff->GetAmount();

                amount = int32(CalculatePct(owner->GetStat(STAT_STAMINA), percentage));
            }
        }
    }

    void CalculateDamageDoneAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float bonusDamage = owner->GetTotalAttackPowerValue(BASE_ATTACK) * 0.11f;
                amount += bonusDamage;
            }
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_pet_scaling_01::CalculateStaminaAmount, EFFECT_0, SPELL_AURA_MOD_STAT);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_pet_scaling_01::CalculateStrengthAmount, EFFECT_1, SPELL_AURA_MOD_STAT);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_pet_scaling_01::CalculateDamageDoneAmount, EFFECT_2, SPELL_AURA_MOD_DAMAGE_DONE);
    }
};

class spell_dk_pet_scaling_02 : public AuraScript
{
    PrepareAuraScript(spell_dk_pet_scaling_02);

    bool Load() override
    {
        if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
            return false;
        return true;
    }

    void CalculateAmountMeleeHaste(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                // For others recalculate it from:
                float HasteMelee = 0.0f;
                // Increase hit from SPELL_AURA_MOD_HIT_CHANCE
                HasteMelee += (1 - owner->m_modAttackSpeedPct[BASE_ATTACK]) * 100;

                amount += int32(HasteMelee);
            }
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_pet_scaling_02::CalculateAmountMeleeHaste, EFFECT_1, SPELL_AURA_MELEE_SLOW);
    }
};

class spell_dk_pet_scaling_03 : public AuraScript
{
    PrepareAuraScript(spell_dk_pet_scaling_03);

    bool Load() override
    {
        if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
            return false;
        return true;
    }

    void CalculateAmountMeleeHit(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (!GetCaster() || !GetCaster()->GetOwner())
            return;
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

    void CalculateAmountSpellHit(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (!GetCaster() || !GetCaster()->GetOwner())
            return;
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

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_pet_scaling_03::CalculateAmountMeleeHit, EFFECT_0, SPELL_AURA_MOD_HIT_CHANCE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_pet_scaling_03::CalculateAmountSpellHit, EFFECT_1, SPELL_AURA_MOD_SPELL_HIT_CHANCE);
    }
};

class spell_dk_pet_scaling_05 : public AuraScript
{
    PrepareAuraScript(spell_dk_pet_scaling_05);

    bool Load()
    {
        if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
            return false;
        return true;
    }

    void CalculateAmountCritPct(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float CritSpell = owner->GetMeleeCritFromAgility();
                CritSpell += owner->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_CHANCE);
                CritSpell += owner->GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_PCT);
                CritSpell += owner->GetRatingBonusValue(CR_CRIT_MELEE);
                amount += int32(CritSpell);
            }
        }
    }

    void CalculateAmountResistance(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (Pet* pet = GetUnitOwner()->ToPet())
            if (Player* owner = pet->GetOwner())
                amount += owner->GetInt32Value(PLAYER_FIELD_MOD_TARGET_RESISTANCE);
    }

    void Register()
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_pet_scaling_05::CalculateAmountCritPct, EFFECT_0, SPELL_AURA_MOD_CRIT_PCT);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_pet_scaling_05::CalculateAmountResistance, EFFECT_2, SPELL_AURA_MOD_TARGET_RESISTANCE);
    }
};

class spell_dk_rune_weapon_scaling_02 : public AuraScript
{
    PrepareAuraScript(spell_dk_rune_weapon_scaling_02);

    bool Load() override
    {
        if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
            return false;
        return true;
    }

    void CalculateDamageDoneAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Unit* pet = GetUnitOwner())
        {
            Unit* owner = pet->GetOwner();
            if (!owner)
                return;

            amount += owner->CalculateDamage(BASE_ATTACK, true, true);
        }
    }

    void CalculateAmountMeleeHaste(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (!GetCaster() || !GetCaster()->GetOwner())
            return;
        if (Player* owner = GetCaster()->GetOwner()->ToPlayer())
        {
            // For others recalculate it from:
            float HasteMelee = 0.0f;
            // Increase hit from SPELL_AURA_MOD_HIT_CHANCE
            HasteMelee += (1 - owner->m_modAttackSpeedPct[BASE_ATTACK]) * 100;

            amount += int32(HasteMelee);
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_rune_weapon_scaling_02::CalculateDamageDoneAmount, EFFECT_0, SPELL_AURA_MOD_DAMAGE_DONE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_rune_weapon_scaling_02::CalculateAmountMeleeHaste, EFFECT_1, SPELL_AURA_MELEE_SLOW);
    }
};

class spell_mage_water_elemental_scaling_01 : public AuraScript
{
    PrepareAuraScript(spell_mage_water_elemental_scaling_01);

    bool Load() override
    {
        if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
            return false;
        return true;
    }

    void CalculateDamageDoneAmount(AuraEffect const* /* aurEff */, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float bonusDamage = owner->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_FROST) * 0.4f;
                amount = int32(bonusDamage);
            }
        }
    }

    void CalculateAttackPowerAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
        {
            if (Player* owner = pet->GetOwner())
            {
                float bonusDamage = owner->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_FROST) * 0.57f;
                amount = int32(bonusDamage);
            }
        }
    }

    void CalculateStaminaAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
            if (Player* owner = pet->GetOwner())
                amount = int32(CalculatePct(owner->GetStat(STAT_STAMINA), 30));
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_water_elemental_scaling_01::CalculateStaminaAmount, EFFECT_0, SPELL_AURA_MOD_STAT);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_water_elemental_scaling_01::CalculateAttackPowerAmount, EFFECT_1, SPELL_AURA_MOD_ATTACK_POWER);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_water_elemental_scaling_01::CalculateDamageDoneAmount, EFFECT_2, SPELL_AURA_MOD_DAMAGE_DONE);
    }
};

class spell_mage_water_elemental_scaling_02 : public AuraScript
{
    PrepareAuraScript(spell_mage_water_elemental_scaling_02);

    bool Load() override
    {
        if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
            return false;
        return true;
    }

    void CalculateIntellectAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        if (Pet* pet = GetUnitOwner()->ToPet())
            if (Player* owner = pet->GetOwner())
                amount = int32(CalculatePct(owner->GetStat(STAT_INTELLECT), 30));
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_water_elemental_scaling_02::CalculateIntellectAmount, EFFECT_0, SPELL_AURA_MOD_STAT);
    }
};

void AddSC_pet_spell_scripts()
{
    RegisterAuraScript(spell_warl_pet_scaling_01);
    RegisterAuraScript(spell_warl_pet_scaling_02);
    RegisterAuraScript(spell_warl_pet_scaling_03);
    RegisterAuraScript(spell_warl_pet_scaling_04);
    RegisterAuraScript(spell_warl_pet_scaling_05);
    RegisterAuraScript(spell_warl_pet_scaling_06);
    RegisterAuraScript(spell_warl_pet_passive);

    RegisterAuraScript(spell_hun_pet_scaling_01);
    RegisterAuraScript(spell_hun_pet_scaling_02);
    RegisterAuraScript(spell_hun_pet_scaling_03);
    RegisterAuraScript(spell_hun_pet_scaling_04);
    RegisterAuraScript(spell_hun_pet_scaling_05);
    RegisterAuraScript(spell_hun_pet_passive_crit);

    RegisterAuraScript(spell_dk_pet_scaling_01);
    RegisterAuraScript(spell_dk_pet_scaling_02);
    RegisterAuraScript(spell_dk_pet_scaling_03);
    RegisterAuraScript(spell_dk_pet_scaling_05);

    RegisterAuraScript(spell_dk_rune_weapon_scaling_02);

    RegisterAuraScript(spell_mage_water_elemental_scaling_01);
    RegisterAuraScript(spell_mage_water_elemental_scaling_02);
}
