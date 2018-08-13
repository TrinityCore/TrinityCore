/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
 * Scripts for spells with SPELLFAMILY_PRIEST and SPELLFAMILY_GENERIC spells used by priest players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_pri_".
 */

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GridNotifiers.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "SpellHistory.h"

enum PriestSpells
{
    SPELL_PRIEST_2P_S12_HEAL                        = 33333,
    SPELL_PRIEST_2P_S12_SHADOW                      = 92711,
    SPELL_PRIEST_4P_S12_HEAL                        = 131566,
    SPELL_PRIEST_4P_S12_SHADOW                      = 131556,
    SPELL_PRIEST_ABSOLUTION                         = 33167,
    SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER        = 158624,
    SPELL_PRIEST_ANGELIC_FEATHER_AURA               = 121557,
    SPELL_PRIEST_ANGELIC_FEATHER_TRIGGER            = 121536,
    SPELL_PRIEST_ARCHANGEL                          = 81700,
    SPELL_PRIEST_ATONEMENT                          = 81749,
    SPELL_PRIEST_ATONEMENT_AURA                     = 194384,
    SPELL_PRIEST_ATONEMENT_HEAL                     = 81751,
    SPELL_PRIEST_BODY_AND_SOUL_AURA                 = 64129,
    SPELL_PRIEST_BODY_AND_SOUL_SPEED                = 65081,
    SPELL_PRIEST_CENSURE                            = 200199,
    SPELL_PRIEST_CURE_DISEASE                       = 528,
    SPELL_PRIEST_DEVOURING_PLAGUE                   = 2944,
    SPELL_PRIEST_DEVOURING_PLAGUE_HEAL              = 127626,
    SPELL_PRIEST_DISPEL_MAGIC_FRIENDLY              = 97690,
    SPELL_PRIEST_DISPEL_MAGIC_HOSTILE               = 97691,
    SPELL_PRIEST_DISPERSION_SPRINT                  = 129960,
    SPELL_PRIEST_DIVINE_AEGIS                       = 47753,
    SPELL_PRIEST_DIVINE_INSIGHT_DISCIPLINE          = 123266,
    SPELL_PRIEST_DIVINE_INSIGHT_HOLY                = 123267,
    SPELL_PRIEST_DIVINE_INSIGHT_TALENT              = 109175,
    SPELL_PRIEST_DIVINE_STAR                        = 110744,
    SPELL_PRIEST_DIVINE_STAR_DAMAGE                 = 122128,
    SPELL_PRIEST_DIVINE_STAR_HEAL                   = 110745,
    SPELL_PRIEST_DIVINE_TOUCH                       = 63544,
    SPELL_PRIEST_ECHO_OF_LIGHT                      = 77485,
    SPELL_PRIEST_ECHO_OF_LIGHT_HEAL                 = 77489,
    SPELL_PRIEST_EMPOWERED_RENEW                    = 63544,
    SPELL_PRIEST_EVANGELISM_AURA                    = 81662,
    SPELL_PRIEST_EVANGELISM_STACK                   = 81661,
    SPELL_PRIEST_FOCUSED_WILL_BUFF                  = 45242,
    SPELL_PRIEST_FROM_DARKNESS_COMES_LIGHT_AURA     = 109186,
    SPELL_PRIEST_GLYPH_OF_CIRCLE_OF_HEALING         = 55675,
    SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC              = 55677,
    SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL         = 56131,
    SPELL_PRIEST_GLYPH_OF_LIGHTWELL                 = 55673,
    SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL    = 56161,
    SPELL_PRIEST_GLYPH_OF_SHADOW                    = 107906,
    SPELL_PRIEST_GUARDIAN_SPIRIT_AURA               = 47788,
    SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL               = 48153,
    SPELL_PRIEST_HALO_DAMAGE                        = 120696,
    SPELL_PRIEST_HALO_HEAL                          = 120692,
    SPELL_PRIEST_HOLY_FIRE                          = 14914,
    SPELL_PRIEST_HOLY_SPARK                         = 131567,
    SPELL_PRIEST_HOLY_WORD_CHASTISE                 = 88625,
    SPELL_PRIEST_HOLY_WORD_CHASTISE_STUN            = 200200,
    SPELL_PRIEST_HOLY_WORD_SANCTIFY                 = 34861,
    SPELL_PRIEST_HOLY_WORD_SANCTUARY_AREA           = 88685,
    SPELL_PRIEST_HOLY_WORD_SANCTUARY_HEAL           = 88686,
    SPELL_PRIEST_HOLY_WORD_SERENITY                 = 2050,
    SPELL_PRIEST_INNER_FIRE                         = 588,
    SPELL_PRIEST_INNER_FOCUS                        = 89485,
    SPELL_PRIEST_INNER_WILL                         = 73413,
    SPELL_PRIEST_ITEM_EFFICIENCY                    = 37595,
    SPELL_PRIEST_LEAP_OF_FAITH                      = 73325,
    SPELL_PRIEST_LEAP_OF_FAITH_EFFECT               = 92832,
    SPELL_PRIEST_LEAP_OF_FAITH_EFFECT_TRIGGER       = 92833,
    SPELL_PRIEST_LEAP_OF_FAITH_GLYPH                = 119850,
    SPELL_PRIEST_LEAP_OF_FAITH_JUMP                 = 110726,
    SPELL_PRIEST_LEAP_OF_FAITH_TRIGGERED            = 92572,
    SPELL_PRIEST_LEVITATE                           = 111758,
    SPELL_PRIEST_LEVITATE_AURA                      = 111759,
    SPELL_PRIEST_LEVITATE_TRIGGERED                 = 111758,
    SPELL_PRIEST_LIGHTSPRING_RENEW                  = 126154,
    SPELL_PRIEST_LIGHTWELL_CHARGES                  = 59907,
    SPELL_PRIEST_LINGERING_INSANITY                 = 197937,
    SPELL_PRIEST_MANA_LEECH_PROC                    = 34650,
    SPELL_PRIEST_MASOCHISM                          = 193063,
    SPELL_PRIEST_MASOCHISM_HEAL                     = 193065,
    SPELL_PRIEST_MIND_BLAST                         = 8092,
    SPELL_PRIEST_MIND_BOMB                          = 205369,
    SPELL_PRIEST_MIND_BOMB_STUN                     = 226943,
    SPELL_PRIEST_MIND_SEAR_INSANITY                 = 208232,
    SPELL_PRIEST_MISERY                             = 238558,
    SPELL_PRIEST_NPC_PSYFIEND                       = 59190,
    SPELL_PRIEST_NPC_SHADOWY_APPARITION             = 46954,
    SPELL_PRIEST_NPC_VOID_TENDRILS                  = 65282,
    SPELL_PRIEST_PENANCE                            = 47540,
    SPELL_PRIEST_PENANCE_DAMAGE                     = 47758,
    SPELL_PRIEST_PENANCE_HEAL                       = 47757,
    SPELL_PRIEST_PENANCE_R1                         = 47540,
    SPELL_PRIEST_PENANCE_R1_DAMAGE                  = 47758,
    SPELL_PRIEST_PENANCE_R1_HEAL                    = 47757,
    SPELL_PRIEST_PHANTASM_AURA                      = 108942,
    SPELL_PRIEST_PHANTASM_PROC                      = 114239,
    SPELL_PRIEST_PIETY                              = 197034,
    SPELL_PRIEST_PLEA                               = 200829,
    SPELL_PRIEST_PLEA_MANA                          = 212100,
    SPELL_PRIEST_POWER_WORD_BARRIER_BUFF            = 81782,
    SPELL_PRIEST_POWER_WORD_BARRIER_VISUAL          = 146810,
    SPELL_PRIEST_POWER_WORD_FORTITUDE               = 21562,
    SPELL_PRIEST_POWER_WORD_SHIELD                  = 17,
    SPELL_PRIEST_PRAYER_OF_MENDING                  = 33076,
    SPELL_PRIEST_PRAYER_OF_MENDING_BUFF             = 41635,
    SPELL_PRIEST_PRAYER_OF_MENDING_HEAL             = 33110,
    SPELL_PRIEST_PRAYER_OF_MENDING_RADIUS           = 123262,
    SPELL_PRIEST_RAPID_RENEWAL_AURA                 = 95649,
    SPELL_PRIEST_RAPTURE_ENERGIZE                   = 47755,
    SPELL_PRIEST_REFLECTIVE_SHIELD_R1               = 33201,
    SPELL_PRIEST_REFLECTIVE_SHIELD_TRIGGERED        = 33619,
    SPELL_PRIEST_SHADOWFORM                         = 165767,
    SPELL_PRIEST_SHADOWFORM_STANCE                  = 232698,
    SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH    = 107903,
    SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH       = 107904,
    SPELL_PRIEST_SHADOW_MEND_AURA                   = 187464,
    SPELL_PRIEST_SHADOW_MEND_DAMAGE                 = 186439,
    SPELL_PRIEST_SHADOW_MEND_HEAL                   = 186263,
    SPELL_PRIEST_SHADOW_WORD_DEATH                  = 32379,
    SPELL_PRIEST_SHADOW_WORD_DEATH_ENERGIZE_KILL    = 190714,
    SPELL_PRIEST_SHADOW_WORD_INSANITY_ALLOWING_CAST = 130733,
    SPELL_PRIEST_SHADOW_WORD_INSANITY_DAMAGE        = 129249,
    SPELL_PRIEST_SHADOW_WORD_PAIN                   = 589,
    SPELL_PRIEST_SIN_AND_PUNISHMENT                 = 87204,
    SPELL_PRIEST_SMITE_ABSORB                       = 208771,
    SPELL_PRIEST_SMITE_AURA                         = 208772,
    SPELL_PRIEST_SOUL_OF_DIAMOND                    = 96219,
    SPELL_PRIEST_SPECTRAL_GUISE_CHARGES             = 119030,
    SPELL_PRIEST_SPIRIT_OF_REDEMPTION_FORM          = 27795,
    SPELL_PRIEST_SPIRIT_OF_REDEMPTION_IMMUNITY      = 62371,
    SPELL_PRIEST_SPIRIT_OF_REDEMPTION_SHAPESHIFT    = 27827,
    SPELL_PRIEST_SPIRIT_OF_REDEMPTION_UNTRANS_HERO  = 25100,
    SPELL_PRIEST_SPIRIT_SHELL_ABSORPTION            = 114908,
    SPELL_PRIEST_SPIRIT_SHELL_AURA                  = 109964,
    SPELL_PRIEST_STRENGTH_OF_SOUL                   = 89488,
    SPELL_PRIEST_STRENGTH_OF_SOUL_AURA              = 89488,
    SPELL_PRIEST_STRENGTH_OF_SOUL_REDUCE_TIME       = 89490,
    SPELL_PRIEST_SURGE_OF_DARKNESS                  = 87160,
    SPELL_PRIEST_SURGE_OF_LIGHT                     = 114255,
    SPELL_PRIEST_T9_HEALING_2P                      = 67201,
    SPELL_PRIEST_TRAIN_OF_THOUGHT                   = 92297,
    SPELL_PRIEST_TWIN_DISCIPLINES_RANK_1            = 47586,
    SPELL_PRIEST_TWIST_OF_FATE                      = 109142,
    SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL              = 15290,
    SPELL_PRIEST_VAMPIRIC_EMBRACE_TRIGGER           = 15290,
    SPELL_PRIEST_VAMPIRIC_TOUCH                     = 34914,
    SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL              = 201146, // Fear
    SPELL_PRIEST_VOIDFORM                           = 228264,
    SPELL_PRIEST_VOIDFORM_BUFFS                     = 194249,
    SPELL_PRIEST_VOIDFORM_TENTACLES                 = 210196,
    SPELL_PRIEST_VOID_BOLT                          = 205448,
    SPELL_PRIEST_VOID_BOLT_DURATION                 = 231688,
    SPELL_PRIEST_VOID_ERUPTION                      = 228260,
    SPELL_PRIEST_VOID_ERUPTION_DAMAGE               = 228360,
    SPELL_PRIEST_VOID_SHIFT                         = 108968,
    SPELL_PRIEST_VOID_TENDRILS_SUMMON               = 127665,
    SPELL_PRIEST_VOID_TENDRILS_TRIGGER              = 127665,
    SPELL_PRIEST_WEAKENED_SOUL                      = 6788,
};

enum PriestSpellIcons
{
    PRIEST_ICON_ID_BORROWED_TIME                    = 2899,
    PRIEST_ICON_ID_DIVINE_TOUCH_TALENT              = 3021,
    PRIEST_ICON_ID_PAIN_AND_SUFFERING               = 2874
};

enum MiscSpells
{
    SPELL_GEN_REPLENISHMENT                         = 57669
};

//7.3.2.25549
// 17 - Power Word: Shield
class spell_pri_power_word_shield : public SpellScript
{
    PrepareSpellScript(spell_pri_power_word_shield);

    void OnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        if (caster->HasAura(SPELL_PRIEST_ATONEMENT))
            caster->CastSpell(target, SPELL_PRIEST_ATONEMENT_AURA, true);

        if (caster->HasAura(SPELL_PRIEST_BODY_AND_SOUL_AURA))
            caster->CastSpell(target, SPELL_PRIEST_BODY_AND_SOUL_SPEED, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pri_power_word_shield::OnHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

class spell_pri_power_word_shield_AuraScript : public AuraScript
{
    PrepareAuraScript(spell_pri_power_word_shield_AuraScript);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_POWER_WORD_SHIELD });
    }

    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (Unit* caster = aurEff->GetCaster())
        {
            if (Player* player = caster->ToPlayer())
            {
                int32 absorbamount = int32(5.5f * player->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask()));
                amount += absorbamount;
            }
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_power_word_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
    }
};

// Clarity of Will - 152118
class spell_pri_clarity_of_will : public AuraScript
{
    PrepareAuraScript(spell_pri_clarity_of_will);

    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (Unit* caster = aurEff->GetCaster())
        {
            if (Player* player = caster->ToPlayer())
            {
                int32 absorbamount = int32(9.0f * player->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask()));
                amount += absorbamount;
            }
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_clarity_of_will::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
    }
};

// 109142 - Twist of Fate
class spell_pri_twist_of_fate : public AuraScript
{
    PrepareAuraScript(spell_pri_twist_of_fate);

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        Unit* target = GetTarget();
        int32 targetPct = target->GetHealthPct();

        if (targetPct < 35)
            return true;

        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pri_twist_of_fate::CheckProc);
    }
};

// 205369 - Mind Bomb
class spell_pri_mind_bomb : public AuraScript
{
    PrepareAuraScript(spell_pri_mind_bomb);

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();
        if (!caster || !target)
            return;

        std::list<Unit*> targets;
        target->GetAttackableUnitListInRange(targets, 8.0f);

        for (auto itr : targets)
        {
            caster->CastSpell(itr, SPELL_PRIEST_MIND_BOMB_STUN, true);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_pri_mind_bomb::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// Holy Word: Chastise - 88625
class spell_pri_holy_word_chastise : public SpellScript
{
    PrepareSpellScript(spell_pri_holy_word_chastise);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        if (caster->HasAura(SPELL_PRIEST_CENSURE))
            caster->CastSpell(target, SPELL_PRIEST_HOLY_WORD_CHASTISE_STUN, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pri_holy_word_chastise::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Flash Heal - 2061 / Heal - 2060
class spell_pri_heal_flash_heal : public SpellScript
{
    PrepareSpellScript(spell_pri_heal_flash_heal);

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->GetSpellHistory()->HasCooldown(SPELL_PRIEST_HOLY_WORD_SERENITY))
            caster->GetSpellHistory()->ModifyCooldown(SPELL_PRIEST_HOLY_WORD_SERENITY, -6 * IN_MILLISECONDS);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_pri_heal_flash_heal::HandleAfterCast);
    }
};

// Binding Heal - 32546
class spell_pri_binding_heal : public SpellScript
{
    PrepareSpellScript(spell_pri_binding_heal);

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->GetSpellHistory()->HasCooldown(SPELL_PRIEST_HOLY_WORD_SANCTIFY))
            caster->GetSpellHistory()->ModifyCooldown(SPELL_PRIEST_HOLY_WORD_SANCTIFY, -3 * IN_MILLISECONDS);

        if (caster->GetSpellHistory()->HasCooldown(SPELL_PRIEST_HOLY_WORD_SERENITY))
            caster->GetSpellHistory()->ModifyCooldown(SPELL_PRIEST_HOLY_WORD_SERENITY, -3 * IN_MILLISECONDS);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_pri_binding_heal::HandleAfterCast);
    }
};

// Prayer of Mending - 33076
class spell_pri_prayer_of_mending : public SpellScript
{
    PrepareSpellScript(spell_pri_prayer_of_mending);

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->HasAura(SPELL_PRIEST_PIETY))
        {
            if (caster->GetSpellHistory()->HasCooldown(SPELL_PRIEST_HOLY_WORD_SANCTIFY))
                caster->GetSpellHistory()->ModifyCooldown(SPELL_PRIEST_HOLY_WORD_SANCTIFY, -6 * IN_MILLISECONDS);
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_pri_prayer_of_mending::HandleAfterCast);
    }
};

// Prayer of Healing - 596
class spell_pri_prayer_of_healing : public SpellScript
{
    PrepareSpellScript(spell_pri_prayer_of_healing);

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->GetSpellHistory()->HasCooldown(SPELL_PRIEST_HOLY_WORD_SANCTIFY))
            caster->GetSpellHistory()->ModifyCooldown(SPELL_PRIEST_HOLY_WORD_SANCTIFY, -6 * IN_MILLISECONDS);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_pri_prayer_of_healing::HandleAfterCast);
    }
};

// Smite - 585
class spell_pri_smite : public SpellScript
{
    PrepareSpellScript(spell_pri_smite);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_SMITE_ABSORB });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        if (!caster->ToPlayer())
            return;

        int32 dmg = GetHitDamage();

        if (caster->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == TALENT_SPEC_PRIEST_DISCIPLINE)
        {
            caster->CastCustomSpell(SPELL_PRIEST_SMITE_AURA, SPELLVALUE_BASE_POINT0, dmg, target, TRIGGERED_FULL_MASK);
            caster->CastCustomSpell(SPELL_PRIEST_SMITE_ABSORB, SPELLVALUE_BASE_POINT0, dmg, caster, TRIGGERED_FULL_MASK);
        }
    }

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == TALENT_SPEC_PRIEST_HOLY)
        {
            if (caster->GetSpellHistory()->HasCooldown(SPELL_PRIEST_HOLY_WORD_CHASTISE))
                caster->GetSpellHistory()->ModifyCooldown(SPELL_PRIEST_HOLY_WORD_CHASTISE, -6 * IN_MILLISECONDS);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pri_smite::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        AfterCast += SpellCastFn(spell_pri_smite::HandleAfterCast);
    }
};
//7.3.2.25549 END

// Voidform buffs - 194249
class spell_pri_voidform : public SpellScriptLoader
{
public:
    spell_pri_voidform() : SpellScriptLoader("spell_pri_voidform") {}

    class spell_pri_voidform_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pri_voidform_AuraScript);

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                caster->RemoveAurasDueToSpell(SPELL_PRIEST_LINGERING_INSANITY);
        }

        void HandlePeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            // This spell must end when insanity hit 0
            if (caster->GetPower(POWER_INSANITY) == 0)
            {
                caster->RemoveAura(aurEff->GetBase());
                return;
            }

            int32 tick = GetAura()->GetStackAmount()-1;
            switch (tick)
            {
                case 0:
                    caster->CastSpell(caster, SPELL_PRIEST_VOIDFORM_TENTACLES, true);
                    break;
                case 3:
                    caster->CastSpell(caster, SPELL_PRIEST_VOIDFORM_TENTACLES + 1, true);
                    break;
                case 6:
                    caster->CastSpell(caster, SPELL_PRIEST_VOIDFORM_TENTACLES + 2, true);
                    break;
                case 9:
                    caster->CastSpell(caster, SPELL_PRIEST_VOIDFORM_TENTACLES + 3, true);
                    break;
                default:
                    break;
            }

            caster->CastSpell(caster, SPELL_PRIEST_VOIDFORM_BUFFS, true);
        }

        void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            for (int i = 0; i < 4; ++i)
                caster->RemoveAurasDueToSpell(SPELL_PRIEST_VOIDFORM_TENTACLES + i);

            int32 haste = aurEff->GetAmount();
            CustomSpellValues mod;
            mod.AddSpellMod(SPELLVALUE_BASE_POINT0, haste);

            if (AuraEffect* aEff = caster->GetAuraEffectOfRankedSpell(SPELL_PRIEST_VOIDFORM_BUFFS, EFFECT_3, caster->GetGUID()))
                mod.AddSpellMod(SPELLVALUE_BASE_POINT1, aEff->GetAmount());

            caster->CastCustomSpell(SPELL_PRIEST_LINGERING_INSANITY, mod, caster, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_pri_voidform_AuraScript::HandlePeriodic, EFFECT_4, SPELL_AURA_PERIODIC_DUMMY);
            AfterEffectRemove += AuraEffectRemoveFn(spell_pri_voidform_AuraScript::HandleRemove, EFFECT_2, SPELL_AURA_MELEE_SLOW, AURA_EFFECT_HANDLE_REAL);
            AfterEffectApply += AuraEffectApplyFn(spell_pri_voidform_AuraScript::HandleApply, EFFECT_4, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pri_voidform_AuraScript();
    }
};

// Void Eruption - 228260
class spell_pri_void_eruption : public SpellScript
{
    PrepareSpellScript(spell_pri_void_eruption);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_VOID_ERUPTION, SPELL_PRIEST_VOID_ERUPTION_DAMAGE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        targets.remove_if([caster](WorldObject* target)
        {
            Unit* targ = target->ToUnit(); //Remove all non-unit targets
            if (!targ)
                return true;

            return !(targ->HasAura(SPELL_PRIEST_SHADOW_WORD_PAIN, caster->GetGUID()) || targ->HasAura(SPELL_PRIEST_VAMPIRIC_TOUCH, caster->GetGUID()));
        });
    }

    void HandleTakePower(SpellPowerCost& powerCost)
    {
        powerCost.Amount = 0;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        int8 spellid = std::rand() % 2; //there are two animations which should be random
        caster->CastSpell(target, SPELL_PRIEST_VOID_ERUPTION_DAMAGE + spellid, true);
    }

    void EnterVoidform()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_PRIEST_VOIDFORM_BUFFS, true);
        if (!caster->HasAura(SPELL_PRIEST_SHADOWFORM_STANCE))
            caster->CastSpell(caster, SPELL_PRIEST_SHADOWFORM_STANCE, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_void_eruption::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnTakePower += SpellOnTakePowerFn(spell_pri_void_eruption::HandleTakePower);
        OnEffectHitTarget += SpellEffectFn(spell_pri_void_eruption::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_pri_void_eruption::EnterVoidform);
    }
};

class PowerCheck
{
    public:
        explicit PowerCheck(Powers const power) : _power(power) { }

        bool operator()(WorldObject* obj) const
        {
            if (Unit* target = obj->ToUnit())
                return target->GetPowerType() != _power;

            return true;
        }

    private:
        Powers const _power;
};

class RaidCheck
{
    public:
        explicit RaidCheck(Unit const* caster) : _caster(caster) { }

        bool operator()(WorldObject* obj) const
        {
            if (Unit* target = obj->ToUnit())
                return !_caster->IsInRaidWith(target);

            return true;
        }

    private:
        Unit const* _caster;
};

// 34861 - Circle of Healing
class spell_pri_circle_of_healing : public SpellScriptLoader
{
    public:
        spell_pri_circle_of_healing() : SpellScriptLoader("spell_pri_circle_of_healing") { }

        class spell_pri_circle_of_healing_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_circle_of_healing_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_GLYPH_OF_CIRCLE_OF_HEALING))
                    return false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(RaidCheck(GetCaster()));

                uint32 const maxTargets = GetCaster()->HasAura(SPELL_PRIEST_GLYPH_OF_CIRCLE_OF_HEALING) ? 6 : 5; // Glyph of Circle of Healing

                if (targets.size() > maxTargets)
                {
                    targets.sort(Trinity::HealthPctOrderPred());
                    targets.resize(maxTargets);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_circle_of_healing_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_circle_of_healing_SpellScript();
        }
};

// 527 - Dispel magic
class spell_pri_dispel_magic : public SpellScriptLoader
{
public:
    spell_pri_dispel_magic() : SpellScriptLoader("spell_pri_dispel_magic") { }

    class spell_pri_dispel_magic_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_dispel_magic_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_ABSOLUTION))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC))
                return false;
            return true;
        }

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();

            if (!target || (!caster->HasAura(SPELL_PRIEST_ABSOLUTION) && caster != target && target->IsFriendlyTo(caster)))
                return SPELL_FAILED_BAD_TARGETS;
            return SPELL_CAST_OK;
        }

        void AfterEffectHit(SpellEffIndex /*effIndex*/)
        {
            if (GetHitUnit()->IsFriendlyTo(GetCaster()))
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_PRIEST_DISPEL_MAGIC_FRIENDLY, true);
                if (AuraEffect const* aurEff = GetHitUnit()->GetAuraEffect(SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC, EFFECT_0))
                {
                    int32 heal = GetHitUnit()->CountPctFromMaxHealth(aurEff->GetAmount());
                    GetCaster()->CastCustomSpell(SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL, SPELLVALUE_BASE_POINT0, heal, GetHitUnit());
                }
            }
            else
                GetCaster()->CastSpell(GetHitUnit(), SPELL_PRIEST_DISPEL_MAGIC_HOSTILE, true);
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_pri_dispel_magic_SpellScript::CheckCast);
            OnEffectHitTarget += SpellEffectFn(spell_pri_dispel_magic_SpellScript::AfterEffectHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_dispel_magic_SpellScript();
    }
};

// -47509 - Divine Aegis
class spell_pri_divine_aegis : public SpellScriptLoader
{
    public:
        spell_pri_divine_aegis() : SpellScriptLoader("spell_pri_divine_aegis") { }

        class spell_pri_divine_aegis_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_divine_aegis_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_DIVINE_AEGIS))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcTarget() != nullptr;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                int32 absorb = CalculatePct(int32(eventInfo.GetHealInfo()->GetHeal()), aurEff->GetAmount());

                // Multiple effects stack, so let's try to find this aura.
                if (AuraEffect const* aegis = eventInfo.GetProcTarget()->GetAuraEffect(SPELL_PRIEST_DIVINE_AEGIS, EFFECT_0))
                    absorb += aegis->GetAmount();

                absorb = std::min(absorb, eventInfo.GetProcTarget()->getLevel() * 125);

                GetTarget()->CastCustomSpell(SPELL_PRIEST_DIVINE_AEGIS, SPELLVALUE_BASE_POINT0, absorb, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_divine_aegis_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_divine_aegis_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_divine_aegis_AuraScript();
        }
};

// 64844 - Divine Hymn
class spell_pri_divine_hymn : public SpellScriptLoader
{
    public:
        spell_pri_divine_hymn() : SpellScriptLoader("spell_pri_divine_hymn") { }

        class spell_pri_divine_hymn_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_divine_hymn_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(RaidCheck(GetCaster()));

                uint32 const maxTargets = 3;

                if (targets.size() > maxTargets)
                {
                    targets.sort(Trinity::HealthPctOrderPred());
                    targets.resize(maxTargets);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_divine_hymn_SpellScript::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_divine_hymn_SpellScript();
        }
};

class spell_pri_improved_power_word_shield : public SpellScriptLoader
{
    public:
        spell_pri_improved_power_word_shield() : SpellScriptLoader("spell_pri_improved_power_word_shield") { }

        class spell_pri_improved_power_word_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_improved_power_word_shield_AuraScript);

            void HandleEffectCalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)
            {
                if (!spellMod)
                {
                    spellMod = new SpellModifier(GetAura());
                    spellMod->op = SpellModOp(aurEff->GetMiscValue());
                    spellMod->type = SPELLMOD_PCT;
                    spellMod->spellId = GetId();
                    spellMod->mask = GetSpellInfo()->GetEffect(aurEff->GetEffIndex())->SpellClassMask;
                }

                spellMod->value = aurEff->GetAmount();
            }

            void Register() override
            {
                DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_pri_improved_power_word_shield_AuraScript::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_improved_power_word_shield_AuraScript();
        }
};

// 37594 - Greater Heal Refund
class spell_pri_item_greater_heal_refund : public SpellScriptLoader
{
    public:
        spell_pri_item_greater_heal_refund() : SpellScriptLoader("spell_pri_item_greater_heal_refund") { }

        class spell_pri_item_greater_heal_refund_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_item_greater_heal_refund_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_ITEM_EFFICIENCY))
                    return false;
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_PRIEST_ITEM_EFFICIENCY, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pri_item_greater_heal_refund_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_item_greater_heal_refund_AuraScript();
        }
};

// 47788 - Guardian Spirit
class spell_pri_guardian_spirit : public SpellScriptLoader
{
    public:
        spell_pri_guardian_spirit() : SpellScriptLoader("spell_pri_guardian_spirit") { }

        class spell_pri_guardian_spirit_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_guardian_spirit_AuraScript);

        public:
            spell_pri_guardian_spirit_AuraScript()
            {
                healPct = 0;
            }

        private:
            uint32 healPct;

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL))
                    return false;
                return true;
            }

            bool Load() override
            {
                healPct = GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue();
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                Unit* target = GetTarget();
                if (dmgInfo.GetDamage() < target->GetHealth())
                    return;

                int32 healAmount = int32(target->CountPctFromMaxHealth(healPct));
                // remove the aura now, we don't want 40% healing bonus
                Remove(AURA_REMOVE_BY_ENEMY_SPELL);
                target->CastCustomSpell(target, SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL, &healAmount, NULL, NULL, true);
                absorbAmount = dmgInfo.GetDamage();
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_guardian_spirit_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_pri_guardian_spirit_AuraScript::Absorb, EFFECT_1);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_guardian_spirit_AuraScript();
        }
};

// 64904 - Hymn of Hope
class spell_pri_hymn_of_hope : public SpellScriptLoader
{
    public:
        spell_pri_hymn_of_hope() : SpellScriptLoader("spell_pri_hymn_of_hope") { }

        class spell_pri_hymn_of_hope_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_hymn_of_hope_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(PowerCheck(POWER_MANA));
                targets.remove_if(RaidCheck(GetCaster()));

                uint32 const maxTargets = 3;

                if (targets.size() > maxTargets)
                {
                    targets.sort(Trinity::PowerPctOrderPred(POWER_MANA));
                    targets.resize(maxTargets);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_hymn_of_hope_SpellScript::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_hymn_of_hope_SpellScript();
        }
};

// 92833 - Leap of Faith
class spell_pri_leap_of_faith_effect_trigger : public SpellScriptLoader
{
    public:
        spell_pri_leap_of_faith_effect_trigger() : SpellScriptLoader("spell_pri_leap_of_faith_effect_trigger") { }

        class spell_pri_leap_of_faith_effect_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_leap_of_faith_effect_trigger_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_LEAP_OF_FAITH_EFFECT))
                    return false;
                return true;
            }

            void HandleEffectDummy(SpellEffIndex /*effIndex*/)
            {
                Position destPos = GetHitDest()->GetPosition();

                SpellCastTargets targets;
                targets.SetDst(destPos);
                targets.SetUnitTarget(GetCaster());
                GetHitUnit()->CastSpell(targets, sSpellMgr->GetSpellInfo(GetEffectValue()), NULL);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_leap_of_faith_effect_trigger_SpellScript::HandleEffectDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_leap_of_faith_effect_trigger_SpellScript();
        }
};

// 7001 - Lightwell Renew
class spell_pri_lightwell_renew : public SpellScriptLoader
{
    public:
        spell_pri_lightwell_renew() : SpellScriptLoader("spell_pri_lightwell_renew") { }

        class spell_pri_lightwell_renew_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_lightwell_renew_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster())
                {
                    // Bonus from Glyph of Lightwell
                    if (AuraEffect* modHealing = caster->GetAuraEffect(SPELL_PRIEST_GLYPH_OF_LIGHTWELL, EFFECT_0))
                        AddPct(amount, modHealing->GetAmount());
                }
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_lightwell_renew_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_lightwell_renew_AuraScript();
        }
};

// 8122 - Pshychic Scream
class spell_pri_psychic_scream : public SpellScriptLoader
{
public:
    spell_pri_psychic_scream() : SpellScriptLoader("spell_pri_psychic_scream") {}

    class spell_pri_psychic_scream_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pri_psychic_scream_AuraScript);

        bool Load() override
        {
            if (Aura* fear = GetAura())
                fear->Variables.Set("damage", (uint64)0);

            return true;
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            Unit* target = eventInfo.GetActionTarget();
            if (!target)
                return false;

            if (Aura* fear = GetAura())
            {
                uint64 const dmg = fear->Variables.GetValue<uint64>("damage");
                uint64 newdamage = eventInfo.GetDamageInfo()->GetDamage() + dmg;
                if (newdamage > target->CountPctFromMaxHealth(10))
                    fear->SetDuration(0);
                else
                    fear->Variables.Set("damage", newdamage);
            }
            return true;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_pri_psychic_scream_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pri_psychic_scream_AuraScript();
    }
};

// 28305 - Mana Leech (Passive) (Priest Pet Aura)
class spell_pri_mana_leech : public SpellScriptLoader
{
    public:
        spell_pri_mana_leech() : SpellScriptLoader("spell_pri_mana_leech") { }

        class spell_pri_mana_leech_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_mana_leech_AuraScript);

        public:
            spell_pri_mana_leech_AuraScript()
            {
                _procTarget = nullptr;
            }

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_MANA_LEECH_PROC))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                _procTarget = GetTarget()->GetOwner();
                return _procTarget != nullptr;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(_procTarget, SPELL_PRIEST_MANA_LEECH_PROC, true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_mana_leech_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_mana_leech_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }

        private:
            Unit* _procTarget;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_mana_leech_AuraScript();
        }
};

// 49821 - Mind Sear
class spell_pri_mind_sear : public SpellScriptLoader
{
public:
    spell_pri_mind_sear() : SpellScriptLoader("spell_pri_mind_sear") {}

    class spell_pri_mind_sear_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_mind_sear_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_MIND_SEAR_INSANITY))
                return false;
            return true;
        }

        void HandleInsanity(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_PRIEST_MIND_SEAR_INSANITY, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pri_mind_sear_SpellScript::HandleInsanity, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_mind_sear_SpellScript();
    }
};


// 47948 - Pain and Suffering (Proc)
class spell_pri_pain_and_suffering_proc : public SpellScriptLoader
{
    public:
        spell_pri_pain_and_suffering_proc() : SpellScriptLoader("spell_pri_pain_and_suffering_proc") { }

        class spell_pri_pain_and_suffering_proc_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_pain_and_suffering_proc_SpellScript);

            void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                // Refresh Shadow Word: Pain on target
                if (Unit* target = GetHitUnit())
                    if (AuraEffect* aur = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, flag128(0x8000, 0, 0), caster->GetGUID()))
                    {
                        uint32 damage = std::max(aur->GetAmount(), 0);
                        sScriptMgr->ModifyPeriodicDamageAurasTick(target, caster, damage);
                        aur->SetDamage(caster->SpellDamageBonusDone(target, aur->GetSpellInfo(), damage, DOT, aur->GetSpellEffectInfo()) * aur->GetDonePct());
                        aur->CalculatePeriodic(caster, false, false);
                        aur->GetBase()->RefreshDuration();
                    }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_pain_and_suffering_proc_SpellScript::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_pain_and_suffering_proc_SpellScript;
        }
};

// 47540 - Penance
class spell_pri_penance : public SpellScript
{
    PrepareSpellScript(spell_pri_penance);

    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellInfo const* firstRankSpellInfo = sSpellMgr->GetSpellInfo(SPELL_PRIEST_PENANCE_R1);
        if (!firstRankSpellInfo)
            return false;

        // can't use other spell than this penance due to spell_ranks dependency
        if (!spellInfo->IsRankOf(firstRankSpellInfo))
            return false;

        uint8 rank = spellInfo->GetRank();
        if (!sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_DAMAGE, rank, true))
            return false;
        if (!sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_HEAL, rank, true))
            return false;

        return true;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* unitTarget = GetHitUnit())
        {
            if (!unitTarget->IsAlive())
                return;

            uint8 rank = GetSpellInfo()->GetRank();

            if (caster->IsFriendlyTo(unitTarget))
                caster->CastSpell(unitTarget, sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_HEAL, rank), false);
            else
                caster->CastSpell(unitTarget, sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_DAMAGE, rank), false);
        }
    }

    SpellCastResult CheckCast()
    {
        Player* caster = GetCaster()->ToPlayer();
        if (Unit* target = GetExplTargetUnit())
            if (!caster->IsFriendlyTo(target))
            {
                if (!caster->IsValidAttackTarget(target))
                    return SPELL_FAILED_BAD_TARGETS;
                if (!caster->isInFront(target))
                    return SPELL_FAILED_UNIT_NOT_INFRONT;
            }
        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pri_penance::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnCheckCast += SpellCheckCastFn(spell_pri_penance::CheckCast);
    }
};

// 47666 - Penance Damage
class spell_pri_penance_damage :public SpellScript
{
    PrepareSpellScript(spell_pri_penance_damage);

    void CheckTarget(WorldObject*& target)
    {
        if (target == GetCaster())
            target = nullptr;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_pri_penance_damage::CheckTarget, EFFECT_0, TARGET_UNIT_CHANNEL_TARGET);
    }
};

// -47569 - Phantasm
class spell_pri_phantasm : public SpellScriptLoader
{
    public:
        spell_pri_phantasm() : SpellScriptLoader("spell_pri_phantasm") { }

        class spell_pri_phantasm_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_phantasm_AuraScript);

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                return roll_chance_i(GetEffect(EFFECT_0)->GetAmount());
            }

            void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->RemoveMovementImpairingAuras();
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_phantasm_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_phantasm_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_phantasm_AuraScript();
        }
};

// 33110 - Prayer of Mending Heal
class spell_pri_prayer_of_mending_heal : public SpellScriptLoader
{
    public:
        spell_pri_prayer_of_mending_heal() : SpellScriptLoader("spell_pri_prayer_of_mending_heal") { }

        class spell_pri_prayer_of_mending_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_prayer_of_mending_heal_SpellScript);

            void HandleHeal(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetOriginalCaster())
                {
                    if (AuraEffect* aurEff = caster->GetAuraEffect(SPELL_PRIEST_T9_HEALING_2P, EFFECT_0))
                    {
                        int32 heal = GetHitHeal();
                        AddPct(heal, aurEff->GetAmount());
                        SetHitHeal(heal);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_prayer_of_mending_heal_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_prayer_of_mending_heal_SpellScript();
        }
};

// 139 - Renew
class spell_pri_renew : public SpellScriptLoader
{
    public:
        spell_pri_renew() : SpellScriptLoader("spell_pri_renew") { }

        class spell_pri_renew_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_renew_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_DIVINE_TOUCH))
                    return false;
                return true;
            }

            bool Load() override
            {
                return GetCaster() && GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleApplyEffect(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    // Divine Touch
                    if (AuraEffect const* empoweredRenewAurEff = caster->GetDummyAuraEffect(SPELLFAMILY_PRIEST, PRIEST_ICON_ID_DIVINE_TOUCH_TALENT, EFFECT_0))
                    {
                        uint32 heal = caster->SpellHealingBonusDone(GetTarget(), GetSpellInfo(), aurEff->GetAmount(), DOT, aurEff->GetSpellEffectInfo());
                        heal = GetTarget()->SpellHealingBonusTaken(caster, GetSpellInfo(), heal, DOT, aurEff->GetSpellEffectInfo());
                        int32 basepoints0 = CalculatePct(int32(heal) * aurEff->GetTotalTicks(), empoweredRenewAurEff->GetAmount());
                        caster->CastCustomSpell(GetTarget(), SPELL_PRIEST_DIVINE_TOUCH, &basepoints0, NULL, NULL, true, NULL, aurEff);
                    }
                }
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_pri_renew_AuraScript::HandleApplyEffect, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_renew_AuraScript();
        }
};

// 32379 - Shadow Word Death
class spell_pri_shadow_word_death : public SpellScript
{
    PrepareSpellScript(spell_pri_shadow_word_death);

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            if (target->GetHealth() < uint64(GetHitDamage()))
                GetCaster()->CastSpell(GetCaster(), SPELL_PRIEST_SHADOW_WORD_DEATH_ENERGIZE_KILL, true);
            else
                GetCaster()->ModifyPower(POWER_INSANITY, GetSpellInfo()->GetEffect(EFFECT_2)->BasePoints);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pri_shadow_word_death::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 232698 - Shadowform
class spell_pri_shadowform : public SpellScriptLoader
{
    public:
        spell_pri_shadowform() : SpellScriptLoader("spell_pri_shadowform") { }

        class spell_pri_shadowform_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_shadowform_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH, SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH });
            }

            void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), GetTarget()->HasAura(SPELL_PRIEST_GLYPH_OF_SHADOW) ? SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH : SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH, true);
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAurasDueToSpell(GetTarget()->HasAura(SPELL_PRIEST_GLYPH_OF_SHADOW) ? SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH : SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_pri_shadowform_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                AfterEffectRemove += AuraEffectRemoveFn(spell_pri_shadowform_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_shadowform_AuraScript();
        }
};

// 15286 - Vampiric Embrace
class spell_pri_vampiric_embrace : public AuraScript
{
    PrepareAuraScript(spell_pri_vampiric_embrace);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (!eventInfo.GetDamageInfo())
            return false;

        if (!eventInfo.GetDamageInfo()->GetSpellInfo())
            return false;

        // Not proc from Mind Sear
        return !(eventInfo.GetDamageInfo()->GetSpellInfo()->SpellFamilyFlags[1] & 0x80000);
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        int32 self = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount()));
        int32 team = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount() / 2));

        GetTarget()->CastCustomSpell((Unit*)NULL, SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL, &team, &self, NULL, true, NULL, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pri_vampiric_embrace::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pri_vampiric_embrace::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 15290 - Vampiric Embrace (heal)
class spell_pri_vampiric_embrace_target : public SpellScript
{
    PrepareSpellScript(spell_pri_vampiric_embrace_target);

    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        unitList.remove(GetCaster());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_vampiric_embrace_target::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_PARTY);
    }
};

// 34914 - Vampiric Touch
class spell_pri_vampiric_touch : public AuraScript
{
    PrepareAuraScript(spell_pri_vampiric_touch);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL, SPELL_GEN_REPLENISHMENT, SPELL_PRIEST_MISERY, SPELL_PRIEST_SHADOW_WORD_PAIN });
    }

    void HandleDispel(DispelInfo* /*dispelInfo*/)
    {
        if (Unit* caster = GetCaster())
            if (Unit* target = GetUnitOwner())
                caster->CastSpell(target, SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL, true);
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetProcTarget() == GetCaster();
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        eventInfo.GetProcTarget()->CastSpell((Unit*)NULL, SPELL_GEN_REPLENISHMENT, true, NULL, aurEff);
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (caster->HasAura(SPELL_PRIEST_MISERY))
                caster->CastSpell(GetTarget(), SPELL_PRIEST_SHADOW_WORD_PAIN, true);
    }

    void Register() override
    {
        AfterDispel += AuraDispelFn(spell_pri_vampiric_touch::HandleDispel);
        DoCheckProc += AuraCheckProcFn(spell_pri_vampiric_touch::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pri_vampiric_touch::HandleEffectProc, EFFECT_2, SPELL_AURA_DUMMY);
        AfterEffectApply += AuraEffectApplyFn(spell_pri_vampiric_touch::OnApply, EFFECT_1, SPELL_AURA_PERIODIC_LEECH, AURA_EFFECT_HANDLE_REAL);
    }
};

// 73325
class spell_pri_leap_of_faith : public SpellScriptLoader
{

public:
    spell_pri_leap_of_faith() : SpellScriptLoader("spell_pri_leap_of_faith") {}

    class spell_pri_leap_of_faith_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_leap_of_faith_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return sSpellMgr->GetSpellInfo(SPELL_PRIEST_LEAP_OF_FAITH_GLYPH)
                && sSpellMgr->GetSpellInfo(SPELL_PRIEST_LEAP_OF_FAITH_EFFECT);
        }

        void HandleScript(SpellEffIndex /* effIndex */)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->HasAura(SPELL_PRIEST_LEAP_OF_FAITH_GLYPH))
                GetHitUnit()->RemoveMovementImpairingAuras();

            GetHitUnit()->CastSpell(caster, SPELL_PRIEST_LEAP_OF_FAITH_EFFECT, true);
        }

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    target->CastSpell(_player, SPELL_PRIEST_LEAP_OF_FAITH_JUMP, true);

                    if (_player->HasAura(SPELL_PRIEST_BODY_AND_SOUL_AURA)) _player->CastSpell(target, SPELL_PRIEST_BODY_AND_SOUL_SPEED, true);
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pri_leap_of_faith_SpellScript::HandleOnHit);
            OnEffectHitTarget += SpellEffectFn(spell_pri_leap_of_faith_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_leap_of_faith_SpellScript();
    }
};

// 1706
class spell_pri_levitate : public SpellScriptLoader
{
public:
    spell_pri_levitate() : SpellScriptLoader("spell_pri_levitate") { }

    class spell_pri_levitate_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_levitate_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_LEVITATE_AURA))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetHitUnit())
                    caster->CastSpell(target, SPELL_PRIEST_LEVITATE_AURA, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pri_levitate_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_levitate_SpellScript;
    }
};

// Void Tendrils - 108920
class spell_pri_void_tendrils : public SpellScriptLoader
{
public:
    spell_pri_void_tendrils() : SpellScriptLoader("spell_pri_void_tendrils") { }

    class spell_pri_void_tendrils_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_void_tendrils_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
                if (Unit* target = GetHitUnit())
                    _player->CastSpell(target, SPELL_PRIEST_VOID_TENDRILS_SUMMON, true);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pri_void_tendrils_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_void_tendrils_SpellScript();
    }
};

class spell_pri_power_word_solace : public SpellScriptLoader
{
public:
    spell_pri_power_word_solace() : SpellScriptLoader("spell_pri_power_word_solace") { }

    class spell_pri_power_word_solace_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_power_word_solace_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
                if (GetHitUnit())
                {
                    int32 amount = GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints / 100;
                    _player->CastCustomSpell(_player, 129253, &amount, NULL, NULL, true);
                }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pri_power_word_solace_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_power_word_solace_SpellScript();
    }
};

class spell_pri_prayer_of_mending_divine_insight : public SpellScriptLoader
{
public:
    spell_pri_prayer_of_mending_divine_insight() : SpellScriptLoader("spell_pri_prayer_of_mending_divine_insight") { }

    class spell_pri_prayer_of_mending_divine_insight_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_prayer_of_mending_divine_insight_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (Aura* prayerOfMending = target->GetAura(SPELL_PRIEST_PRAYER_OF_MENDING_RADIUS, _player->GetGUID()))
                    {
                        int32 value = prayerOfMending->GetEffect(0)->GetAmount();

                        if (_player->HasAura(SPELL_PRIEST_DIVINE_INSIGHT_HOLY))
                            _player->RemoveAura(SPELL_PRIEST_DIVINE_INSIGHT_HOLY);

                        target->CastCustomSpell(target, SPELL_PRIEST_PRAYER_OF_MENDING_HEAL, &value, NULL, NULL, true, NULL, 0, _player->GetGUID());
                        if (target->HasAura(GetSpellInfo()->Id))
                            target->RemoveAura(GetSpellInfo()->Id);

                        float radius = sSpellMgr->GetSpellInfo(SPELL_PRIEST_PRAYER_OF_MENDING_RADIUS)->GetEffect(0)->CalcRadius(_player);

                        if (Unit* secondTarget = target->GetNextRandomRaidMemberOrPet(radius))
                        {
                            target->CastCustomSpell(secondTarget, SPELL_PRIEST_PRAYER_OF_MENDING, &value, NULL, NULL, true, NULL, 0, _player->GetGUID());
                            if (secondTarget->HasAura(SPELL_PRIEST_PRAYER_OF_MENDING))
                                secondTarget->RemoveAura(SPELL_PRIEST_PRAYER_OF_MENDING);

                            secondTarget->CastCustomSpell(secondTarget, SPELL_PRIEST_PRAYER_OF_MENDING_HEAL, &value, NULL, NULL, true, NULL, 0, _player->GetGUID());

                            if (Unit* thirdTarget = target->GetNextRandomRaidMemberOrPet(radius))
                            {
                                secondTarget->CastCustomSpell(thirdTarget, SPELL_PRIEST_PRAYER_OF_MENDING, &value, NULL, NULL, true, NULL, 0, _player->GetGUID());
                                if (thirdTarget->HasAura(SPELL_PRIEST_PRAYER_OF_MENDING))
                                    thirdTarget->RemoveAura(SPELL_PRIEST_PRAYER_OF_MENDING);

                                thirdTarget->CastCustomSpell(thirdTarget, SPELL_PRIEST_PRAYER_OF_MENDING_HEAL, &value, NULL, NULL, true, NULL, 0, _player->GetGUID());

                                if (Unit* fourthTarget = target->GetNextRandomRaidMemberOrPet(radius))
                                {
                                    thirdTarget->CastCustomSpell(fourthTarget, SPELL_PRIEST_PRAYER_OF_MENDING, &value, NULL, NULL, true, NULL, 0, _player->GetGUID());
                                    if (fourthTarget->HasAura(SPELL_PRIEST_PRAYER_OF_MENDING))
                                        fourthTarget->RemoveAura(SPELL_PRIEST_PRAYER_OF_MENDING);

                                    fourthTarget->CastCustomSpell(fourthTarget, SPELL_PRIEST_PRAYER_OF_MENDING_HEAL, &value, NULL, NULL, true, NULL, 0, _player->GetGUID());

                                    if (Unit* fifthTarget = target->GetNextRandomRaidMemberOrPet(radius))
                                    {
                                        fourthTarget->CastCustomSpell(fifthTarget, SPELL_PRIEST_PRAYER_OF_MENDING, &value, NULL, NULL, true, NULL, 0, _player->GetGUID());
                                        if (fifthTarget->HasAura(SPELL_PRIEST_PRAYER_OF_MENDING))
                                            fifthTarget->RemoveAura(SPELL_PRIEST_PRAYER_OF_MENDING);

                                        fifthTarget->CastCustomSpell(fifthTarget, SPELL_PRIEST_PRAYER_OF_MENDING_HEAL, &value, NULL, NULL, true, NULL, 0, _player->GetGUID());
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pri_prayer_of_mending_divine_insight_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_prayer_of_mending_divine_insight_SpellScript();
    }
};

class spell_pri_shadowfiend : public SpellScriptLoader
{
public:
    spell_pri_shadowfiend() : SpellScriptLoader("spell_pri_shadowfiend") { }

    class spell_pri_shadowfiend_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_shadowfiend_SpellScript);

        void HandleAfterHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetExplTargetUnit())
                {
                    if (Guardian* pet = _player->GetGuardianPet())
                    {
                        pet->InitCharmInfo();
                        pet->SetReactState(REACT_DEFENSIVE);
                        pet->ToCreature()->AI()->AttackStart(target);
                    }
                }
            }
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_pri_shadowfiend_SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_shadowfiend_SpellScript();
    }
};

class spell_pri_spirit_shell : public SpellScriptLoader
{
public:
    spell_pri_spirit_shell() : SpellScriptLoader("spell_pri_spirit_shell") { }

    class spell_pri_spirit_shell_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_spirit_shell_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (_player->HasAura(SPELL_PRIEST_SPIRIT_SHELL_AURA))
                    {
                        int32 bp = GetHitHeal();

                        SetHitHeal(0);

                        if (AuraEffect* shell = _player->GetAuraEffect(114908, EFFECT_0))
                            shell->SetAmount(std::min(shell->GetAmount() + bp, (int32)_player->CountPctFromMaxHealth(60)));
                        else
                            _player->CastCustomSpell(target, SPELL_PRIEST_SPIRIT_SHELL_ABSORPTION, &bp, NULL, NULL, true);
                    }
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pri_spirit_shell_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_spirit_shell_SpellScript();
    }
};

class spell_pri_strength_of_soul : public SpellScriptLoader
{
public:
    spell_pri_strength_of_soul() : SpellScriptLoader("spell_pri_strength_of_soul") { }

    class spell_pri_strength_of_soul_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_strength_of_soul_SpellScript);

        void HandleOnHit()
        {
            // TODO
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pri_strength_of_soul_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_strength_of_soul_SpellScript();
    }
};

class spell_pri_void_shift : public SpellScriptLoader
{
public:
    spell_pri_void_shift() : SpellScriptLoader("spell_pri_void_shift") { }

    class spell_pri_void_shift_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_void_shift_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_VOID_SHIFT))
                return false;
            return true;
        }

        SpellCastResult CheckTarget()
        {
            if (GetExplTargetUnit())
                if (GetExplTargetUnit()->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;

            return SPELL_CAST_OK;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    int64 playerPct;
                    int64 targetPct;

                    playerPct = _player->GetHealthPct();
                    targetPct = target->GetHealthPct();

                    if (playerPct < 25)
                        playerPct = 25;
                    if (targetPct < 25)
                        targetPct = 25;

                    playerPct /= 100;
                    targetPct /= 100;

                    _player->SetHealth(_player->GetMaxHealth() * targetPct);
                    target->SetHealth(target->GetMaxHealth() * playerPct);
                }
            }
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_pri_void_shift_SpellScript::CheckTarget);
            OnEffectHitTarget += SpellEffectFn(spell_pri_void_shift_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_void_shift_SpellScript;
    }
};

// 108945 - Angelic Bulwark
class spell_priest_angelic_bulwark : public SpellScriptLoader
{
public:
    spell_priest_angelic_bulwark() : SpellScriptLoader("spell_priest_angelic_bulwark")
    {
    }

    class spell_priest_angelic_bulwark_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_priest_angelic_bulwark_AuraScript);

        bool Validate(SpellInfo const* spellInfo) override
        {
            return spellInfo->GetEffect(EFFECT_1) != nullptr;
        }

        bool CheckProc(ProcEventInfo& procInfo)
        {
            auto damageInfo = procInfo.GetDamageInfo();
            Unit* target = procInfo.GetActionTarget();
            auto auraEffect = GetEffect(EFFECT_0);

            if (!damageInfo || !damageInfo->GetDamage() || !target || !auraEffect)
                return false;

            if (target->HasAura(114216))
                return false;

            uint32 health = target->GetHealth();
            uint32 threashold = CalculatePct(target->GetMaxHealth(), auraEffect->GetAmount());

            return (health - damageInfo->GetDamage() < threashold);
        }

        void HandleEffectProc(AuraEffect const* /* aurEff */, ProcEventInfo& eventInfo)
        {
            Unit* target = eventInfo.GetActionTarget();
            int64 bp0 = CalculatePct(target->GetMaxHealth(), GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints);
            target->CastCustomSpell(114214, SPELLVALUE_BASE_POINT0, bp0, target, true, NULL, GetEffect(EFFECT_0));
            target->CastSpell(target, 114216, true);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_priest_angelic_bulwark_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_priest_angelic_bulwark_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript *GetAuraScript() const override
    {
        return new spell_priest_angelic_bulwark_AuraScript();
    }
};

class spell_pri_fade : public SpellScriptLoader
{
public:
    spell_pri_fade() : SpellScriptLoader("spell_pri_fade") { }

    class spell_pri_fade_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_fade_SpellScript);

        void HandleGlyph()
        {
            Unit* caster = GetCaster();
            if (caster->HasAura(159628)) // Glyph of Mass dispel
                caster->CastSpell(caster, 159630, true);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pri_fade_SpellScript::HandleGlyph);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_fade_SpellScript();
    }
};

// Glyph of Shadow - 107906
class spell_pri_glyph_of_shadow : public SpellScriptLoader
{
public:
    spell_pri_glyph_of_shadow() : SpellScriptLoader("spell_pri_glyph_of_shadow") {}

    class spell_pri_glyph_of_shadow_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pri_glyph_of_shadow_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH))
                return false;
            return true;
        }

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->RemoveAurasDueToSpell(SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH);
            caster->CastSpell(caster, SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH, true);
        }

        void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->RemoveAurasDueToSpell(SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH);
            caster->CastSpell(caster, SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH, true);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_pri_glyph_of_shadow_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_pri_glyph_of_shadow_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pri_glyph_of_shadow_AuraScript();
    }
};

// Shadow Mend heal - 186263
class spell_pri_shadow_mend : public SpellScript
{
    PrepareSpellScript(spell_pri_shadow_mend);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_SHADOW_MEND_AURA,
                                   SPELL_PRIEST_MASOCHISM,
                                   SPELL_PRIEST_MASOCHISM_HEAL });
    }

    void ApplyAura(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        if (caster->HasAura(SPELL_PRIEST_ATONEMENT))
            caster->CastSpell(target, SPELL_PRIEST_ATONEMENT_AURA, true);

        if (caster->HasAura(SPELL_PRIEST_MASOCHISM) && caster == target)
        {
            caster->CastSpell(caster, SPELL_PRIEST_MASOCHISM_HEAL, true);
            return;
        }

        if (target->IsInCombat())
            caster->CastCustomSpell(SPELL_PRIEST_SHADOW_MEND_AURA, SPELLVALUE_BASE_POINT0, GetHitHeal(), target, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pri_shadow_mend::ApplyAura, EFFECT_0, SPELL_EFFECT_HEAL);
    }
};

// Shadow Mend aura - 187464
class spell_pri_shadow_mend_aura : public AuraScript
{
    PrepareAuraScript(spell_pri_shadow_mend_aura);

    int32 damageThreshold = 0;

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        Unit* target = eventInfo.GetActionTarget();

        if (!target)
            return false;

        if (!eventInfo.GetDamageInfo())
            return false;

        damageThreshold -= eventInfo.GetDamageInfo()->GetDamage();

        if (Aura* shadowMendAura = GetAura())
            if (damageThreshold <= 0)
                shadowMendAura->SetDuration(1);

        return true;
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();
        if (!caster || !target)
            return;

        if (!target->IsInCombat())
            GetAura()->Remove();
        else
            target->CastCustomSpell(SPELL_PRIEST_SHADOW_MEND_DAMAGE, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), target, TRIGGERED_FULL_MASK, NULL, NULL, caster->GetGUID());
    }

    void CalcDamage(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        // Remaining damage gets added.
        damageThreshold += amount;
        amount = damageThreshold / 10;
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_shadow_mend_aura::CalcDamage, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        DoCheckProc += AuraCheckProcFn(spell_pri_shadow_mend_aura::CheckProc);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_pri_shadow_mend_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// Power Word: Radiance - 194509
class spell_pri_power_word_radiance : public SpellScriptLoader
{
public:
    spell_pri_power_word_radiance() : SpellScriptLoader("spell_pri_power_word_radiance") {}

    class spell_pri_power_word_radiance_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_power_word_radiance_SpellScript);

        int8 hitCount = 0;

        void ApplyAtonement(SpellEffIndex /*effIndex*/)
        {
            if (hitCount > 2)
                return;

            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            if (caster->HasAura(SPELL_PRIEST_ATONEMENT))
                caster->CastSpell(target, SPELL_PRIEST_ATONEMENT_AURA, true);

            hitCount++;
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pri_power_word_radiance_SpellScript::ApplyAtonement, EFFECT_1, SPELL_EFFECT_HEAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_power_word_radiance_SpellScript();
    }
};

// Plea - 200829
class spell_pri_plea : public SpellScriptLoader
{
public:
    spell_pri_plea() : SpellScriptLoader("spell_pri_plea") {}

    class spell_pri_plea_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_plea_SpellScript);

        void ApplyAtonement(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            if (caster->HasAura(SPELL_PRIEST_ATONEMENT))
                caster->CastSpell(target, SPELL_PRIEST_ATONEMENT_AURA, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pri_plea_SpellScript::ApplyAtonement, EFFECT_0, SPELL_EFFECT_HEAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_plea_SpellScript();
    }
};

// Spirit of Redemption - 20711
class spell_pri_spirit_of_redemption : public AuraScript
{
    PrepareAuraScript(spell_pri_spirit_of_redemption);

    enum eSpells
    {
        SpiritOfRedemptionImmunity = 62371,
        UntransformHero = 25100,
        SpiritOfRedemptionForm = 27795,
        SpiritOfRedemptionShapeshift = 27827
    };

    void CalculateAmount(AuraEffect const* /*p_AuraEffect*/, int32& p_Amount, bool& /*p_CanBeRecalculated*/)
    {
        p_Amount = -1;
    }

    void Absorb(AuraEffect* /*p_AuraEffect*/, DamageInfo& p_DmgInfo, uint32& p_AbsorbAmount)
    {
        p_AbsorbAmount = 0; //This is set at 0 unless conditions are met (last line)
        Unit* l_Caster = GetCaster();
        if (!l_Caster)
            return;

        if (p_DmgInfo.GetDamage() < l_Caster->GetHealth())
            return;

        if (l_Caster->HasAura(eSpells::SpiritOfRedemptionShapeshift))
            return;

        l_Caster->CastSpell(l_Caster, eSpells::SpiritOfRedemptionShapeshift, true);
        l_Caster->CastSpell(l_Caster, eSpells::SpiritOfRedemptionForm, true);
        l_Caster->CastSpell(l_Caster, eSpells::SpiritOfRedemptionImmunity, true);
        l_Caster->CastSpell(l_Caster, eSpells::UntransformHero, true); ///< Visual

        p_AbsorbAmount = p_DmgInfo.GetDamage();
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_spirit_of_redemption::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_pri_spirit_of_redemption::Absorb, EFFECT_0);
    }
};

// Last Update 6.2.3
// Spirit of Redemption (Shapeshift) - 27827
class spell_pri_spirit_of_redemption_form : public AuraScript
{
    PrepareAuraScript(spell_pri_spirit_of_redemption_form);

    enum eSpells
    {
        SpiritOfRedemptionImmunity = 62371,
        SpiritOfRedemptionForm = 27795
    };

    void AfterRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
    {
        Unit* l_Target = GetTarget();

        l_Target->RemoveAura(eSpells::SpiritOfRedemptionForm);
        l_Target->RemoveAura(eSpells::SpiritOfRedemptionImmunity);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_pri_spirit_of_redemption_form::AfterRemove, EFFECT_0, SPELL_AURA_WATER_BREATHING, AURA_EFFECT_HANDLE_REAL);
    }
};

// Atonement - 81749
class spell_pri_atonement : public AuraScript
{
    PrepareAuraScript(spell_pri_atonement);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_ATONEMENT_AURA, SPELL_PRIEST_ATONEMENT_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        Unit* caster = GetCaster();
        if (!caster || !caster->IsPlayer())
            return;

        // Heal = DamageDealt * (40 * (1+mastery%))
        uint32 damage = eventInfo.GetDamageInfo() ? eventInfo.GetDamageInfo()->GetDamage() : 0;
        int32 base = aurEff->GetBaseAmount();
        AddPct(base, caster->GetFloatValue(PLAYER_MASTERY));
        uint32 heal = CalculatePct(damage, base);

        std::list<Unit*> units;
        caster->GetFriendlyUnitListInRange(units, 100.f);

        for (Unit* unit : units)
            if (unit->HasAura(SPELL_PRIEST_ATONEMENT_AURA, caster->GetGUID()))
                caster->CastCustomSpell(SPELL_PRIEST_ATONEMENT_HEAL, SPELLVALUE_BASE_POINT0, heal, unit, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_atonement::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// Atonement Aura - 194384
class spell_pri_atonement_aura : public AuraScript
{
    PrepareAuraScript(spell_pri_atonement_aura);

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (caster->HasAura(SPELL_PRIEST_ATONEMENT))
                caster->CastSpell(caster, SPELL_PRIEST_PLEA_MANA, true);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (Aura* aur = caster->GetAura(SPELL_PRIEST_PLEA_MANA))
                aur->ModStackAmount(-1);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_pri_atonement_aura::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_pri_atonement_aura::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// Angelic Feather - 121536
class spell_pri_angelic_feather : public SpellScriptLoader
{
public:
    spell_pri_angelic_feather() : SpellScriptLoader("spell_pri_angelic_feather") {}

    class spell_pri_angelic_feather_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_angelic_feather_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_PRIEST_ANGELIC_FEATHER_TRIGGER, SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER });
        }

        void HandleEffectDummy(SpellEffIndex /*effIndex*/)
        {
            Position destPos = GetHitDest()->GetPosition();
            float radius = GetEffectInfo()->CalcRadius();

            // Caster is prioritary
            if (GetCaster()->IsWithinDist2d(&destPos, radius))
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_PRIEST_ANGELIC_FEATHER_AURA, true);
            }
            else
            {
                SpellCastTargets targets;
                targets.SetDst(destPos);
                GetCaster()->CastSpell(targets, sSpellMgr->GetSpellInfo(SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER), nullptr);
            }
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_pri_angelic_feather_SpellScript::HandleEffectDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_angelic_feather_SpellScript();
    }
};

// Smite Absorb - 208771
class spell_pri_smite_absorb : public SpellScriptLoader
{
public:
    spell_pri_smite_absorb() : SpellScriptLoader("spell_pri_smite_absorb") {}

    class spell_pri_smite_absorb_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pri_smite_absorb_AuraScript);

        void HandleAbsorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            Unit* caster = GetCaster();
            Unit* attacker = dmgInfo.GetAttacker();
            if (!caster || !attacker)
                return;

            if (!attacker->HasAura(SPELL_PRIEST_SMITE_AURA, caster->GetGUID()))
                absorbAmount = 0;
            else
            {
                if (Aura* aur = attacker->GetAura(SPELL_PRIEST_SMITE_AURA, caster->GetGUID()))
                {
                    if (AuraEffect* aurEff = aur->GetEffect(EFFECT_0))
                    {
                        aurEff->SetAmount(aurEff->GetAmount() - dmgInfo.GetDamage());
                        aur->SetNeedClientUpdateForTargets();
                        if (aurEff->GetAmount() <= 0)
                            aur->SetDuration(1);
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_pri_smite_absorb_AuraScript::HandleAbsorb, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pri_smite_absorb_AuraScript();
    }
};

// Focused Will - 45243
class spell_pri_focused_will : public SpellScriptLoader
{
public:
    spell_pri_focused_will() : SpellScriptLoader("spell_pri_focused_will") {}

    class spell_pri_focused_will_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pri_focused_will_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_FOCUSED_WILL_BUFF))
                return false;
            return true;
        }

        bool HandleProc(ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return false;

            if (eventInfo.GetDamageInfo()->GetAttackType() == BASE_ATTACK || eventInfo.GetDamageInfo()->GetAttackType() == OFF_ATTACK)
            {
                caster->CastSpell(caster, SPELL_PRIEST_FOCUSED_WILL_BUFF, true);
                return true;
            }

            return false;
        }

        void PreventAction(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_pri_focused_will_AuraScript::HandleProc);
            OnEffectProc += AuraEffectProcFn(spell_pri_focused_will_AuraScript::PreventAction, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pri_focused_will_AuraScript();
    }
};

// Void Bolt - 234746
class spell_pri_void_bolt : public SpellScript
{
    PrepareSpellScript(spell_pri_void_bolt);

    void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Aura* voidBoltDurationBuffAura = GetCaster()->GetAura(SPELL_PRIEST_VOID_BOLT_DURATION))
        {
            if (Unit* unit = GetHitUnit())
            {
                uint32 durationIncreaseMs = voidBoltDurationBuffAura->GetEffect(EFFECT_0)->GetBaseAmount();

                if (Aura* pain = unit->GetAura(SPELL_PRIEST_SHADOW_WORD_PAIN, GetCaster()->GetGUID()))
                    pain->ModDuration(durationIncreaseMs);

                if (Aura* vampiricTouch = unit->GetAura(SPELL_PRIEST_VAMPIRIC_TOUCH, GetCaster()->GetGUID()))
                    vampiricTouch->ModDuration(durationIncreaseMs);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pri_void_bolt::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// Angelic Feather areatrigger - created by SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER
// AreaTriggerID - 337
struct at_pri_angelic_feather : AreaTriggerAI
{
    at_pri_angelic_feather(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnInitialize() override
    {
        if (Unit* caster = at->GetCaster())
        {
            std::vector<AreaTrigger*> areaTriggers = caster->GetAreaTriggers(SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER);

            if (areaTriggers.size() >= 3)
                areaTriggers.front()->SetDuration(0);
        }
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (caster->IsFriendlyTo(unit) && unit->IsPlayer())
            {
                // If target already has aura, increase duration to max 130% of initial duration
                caster->CastSpell(unit, SPELL_PRIEST_ANGELIC_FEATHER_AURA, true);
                at->SetDuration(0);
            }
        }
    }
};

// Power Word: Barrier - 62618
// AreaTriggerID - 1489
struct at_pri_power_word_barrier : AreaTriggerAI
{
    at_pri_power_word_barrier(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();

        if (!caster || !unit)
            return;

        if (!caster->ToPlayer())
            return;

        if (caster->IsFriendlyTo(unit))
            caster->CastSpell(unit, SPELL_PRIEST_POWER_WORD_BARRIER_BUFF, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        Unit* caster = at->GetCaster();

        if (!caster || !unit)
            return;

        if (!caster->ToPlayer())
            return;

        if (unit->HasAura(SPELL_PRIEST_POWER_WORD_BARRIER_BUFF, caster->GetGUID()))
            unit->RemoveAurasDueToSpell(SPELL_PRIEST_POWER_WORD_BARRIER_BUFF, caster->GetGUID());
    }
};

// 120517 - Halo
// AreaTriggerID - 3921
struct at_pri_halo : AreaTriggerAI
{
    at_pri_halo(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (caster->IsValidAssistTarget(unit))
                caster->CastSpell(unit, SPELL_PRIEST_HALO_HEAL, true);
            else if (caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_PRIEST_HALO_DAMAGE, true);
        }
    }
};

// 110744 - Divine Star
// AreaTriggerID - 6700
struct at_pri_divine_star : AreaTriggerAI
{
    at_pri_divine_star(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (caster->IsValidAssistTarget(unit))
                caster->CastSpell(unit, SPELL_PRIEST_DIVINE_STAR_HEAL, true);
            else if (caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_PRIEST_DIVINE_STAR_DAMAGE, true);
        }
    }
};

void AddSC_priest_spell_scripts()
{
    RegisterAreaTriggerAI(at_pri_angelic_feather);
    RegisterAreaTriggerAI(at_pri_power_word_barrier);
    RegisterAreaTriggerAI(at_pri_halo);
    RegisterAreaTriggerAI(at_pri_divine_star);

    RegisterSpellScript(spell_pri_shadow_mend);
    RegisterAuraScript(spell_pri_shadow_mend_aura);
    new spell_pri_plea();
    new spell_pri_power_word_radiance();
    RegisterAuraScript(spell_pri_atonement);
    RegisterAuraScript(spell_pri_atonement_aura);
    new spell_pri_psychic_scream();
    new spell_pri_smite_absorb();
    new spell_pri_focused_will();
    new spell_pri_angelic_feather();
    new spell_pri_circle_of_healing();
    new spell_pri_dispel_magic();
    new spell_pri_divine_aegis();
    new spell_pri_divine_hymn();
    new spell_pri_fade();
    new spell_pri_glyph_of_shadow();
    new spell_pri_guardian_spirit();
    new spell_pri_hymn_of_hope();
    new spell_pri_item_greater_heal_refund();
    new spell_pri_leap_of_faith();
    new spell_pri_leap_of_faith_effect_trigger();
    new spell_pri_levitate();
    new spell_pri_lightwell_renew();
    new spell_pri_mana_leech();
    new spell_pri_mind_sear();
    new spell_pri_pain_and_suffering_proc();
    RegisterSpellScript(spell_pri_penance);
    RegisterSpellScript(spell_pri_penance_damage);
    new spell_pri_phantasm();
    new spell_pri_power_word_solace();
    new spell_pri_prayer_of_mending_divine_insight();
    new spell_pri_prayer_of_mending_heal();
    new spell_pri_renew();
    RegisterSpellScript(spell_pri_shadow_word_death);
    new spell_pri_shadowfiend();
    new spell_pri_shadowform();
    new spell_pri_spirit_shell();
    new spell_pri_strength_of_soul();
    RegisterAuraScript(spell_pri_vampiric_embrace);
    RegisterSpellScript(spell_pri_vampiric_embrace_target);
    RegisterAuraScript(spell_pri_vampiric_touch);
    RegisterSpellScript(spell_pri_void_eruption);
    new spell_pri_void_shift();
    new spell_pri_void_tendrils();
    new spell_pri_voidform();
    new spell_priest_angelic_bulwark();
    RegisterAuraScript(spell_pri_spirit_of_redemption);
    RegisterAuraScript(spell_pri_spirit_of_redemption_form);
    RegisterSpellScript(spell_pri_holy_word_chastise);
    RegisterSpellScript(spell_pri_smite);
    RegisterSpellScript(spell_pri_heal_flash_heal);
    RegisterSpellScript(spell_pri_prayer_of_mending);
    RegisterSpellScript(spell_pri_prayer_of_healing);
    RegisterSpellScript(spell_pri_binding_heal);
    RegisterSpellScript(spell_pri_void_bolt);

    RegisterAuraScript(spell_pri_clarity_of_will);
    RegisterAuraScript(spell_pri_twist_of_fate);
    RegisterAuraScript(spell_pri_mind_bomb);

    RegisterSpellAndAuraScriptPair(spell_pri_power_word_shield, spell_pri_power_word_shield_AuraScript);
}
