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
 * Scripts for spells with SPELLFAMILY_ROGUE and SPELLFAMILY_GENERIC spells used by rogue players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_rog_".
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "Item.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum RogueSpells
{
    SPELL_ROGUE_ADRENALINE_RUSH                     = 13750,
    SPELL_ROGUE_BETWEEN_THE_EYES                    = 199804,
    SPELL_ROGUE_BLACKJACK_TALENT                    = 379005,
    SPELL_ROGUE_BLACKJACK                           = 394119,
    SPELL_ROGUE_BLADE_FLURRY                        = 13877,
    SPELL_ROGUE_BLADE_FLURRY_EXTRA_ATTACK           = 22482,
    SPELL_ROGUE_BROADSIDE                           = 193356,
    SPELL_ROGUE_BURIED_TREASURE                     = 199600,
    SPELL_ROGUE_CHEAT_DEATH_DUMMY                   = 31231,
    SPELL_ROGUE_CHEATED_DEATH                       = 45181,
    SPELL_ROGUE_CHEATING_DEATH                      = 45182,
    SPELL_ROGUE_DEATH_FROM_ABOVE                    = 152150,
    SPELL_ROGUE_GRAND_MELEE                         = 193358,
    SPELL_ROGUE_GRAPPLING_HOOK                      = 195457,
    SPELL_ROGUE_IMPROVED_SHIV                       = 319032,
    SPELL_ROGUE_KILLING_SPREE                       = 51690,
    SPELL_ROGUE_KILLING_SPREE_TELEPORT              = 57840,
    SPELL_ROGUE_KILLING_SPREE_WEAPON_DMG            = 57841,
    SPELL_ROGUE_KILLING_SPREE_DMG_BUFF              = 61851,
    SPELL_ROGUE_MARKED_FOR_DEATH                    = 137619,
    SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT   = 31665,
    SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE          = 31223,
    SPELL_ROGUE_MAIN_GAUCHE                         = 86392,
    SPELL_ROGUE_PREMEDITATION_PASSIVE               = 343160,
    SPELL_ROGUE_PREMEDITATION_AURA                  = 343173,
    SPELL_ROGUE_PREY_ON_THE_WEAK_TALENT             = 131511,
    SPELL_ROGUE_PREY_ON_THE_WEAK                    = 255909,
    SPELL_ROGUE_RUTHLESS_PRECISION                  = 193357,
    SPELL_ROGUE_SANCTUARY                           = 98877,
    SPELL_ROGUE_SKULL_AND_CROSSBONES                = 199603,
    SPELL_ROGUE_SHADOW_FOCUS                        = 108209,
    SPELL_ROGUE_SHADOW_FOCUS_EFFECT                 = 112942,
    SPELL_ROGUE_SHIV_NATURE_DAMAGE                  = 319504,
    SPELL_ROGUE_SLICE_AND_DICE                      = 315496,
    SPELL_ROGUE_SPRINT                              = 2983,
    SPELL_ROGUE_STEALTH                             = 1784,
    SPELL_ROGUE_STEALTH_STEALTH_AURA                = 158185,
    SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA             = 158188,
    SPELL_ROGUE_SYMBOLS_OF_DEATH_CRIT_AURA          = 227151,
    SPELL_ROGUE_SYMBOLS_OF_DEATH_RANK2              = 328077,
    SPELL_ROGUE_TRUE_BEARING                        = 193359,
    SPELL_ROGUE_TURN_THE_TABLES_BUFF                = 198027,
    SPELL_ROGUE_VANISH                              = 1856,
    SPELL_ROGUE_VANISH_AURA                         = 11327,
    SPELL_ROGUE_TRICKS_OF_THE_TRADE                 = 57934,
    SPELL_ROGUE_TRICKS_OF_THE_TRADE_PROC            = 59628,
    SPELL_ROGUE_HONOR_AMONG_THIEVES_ENERGIZE        = 51699,
    SPELL_ROGUE_T5_2P_SET_BONUS                     = 37169,
    SPELL_ROGUE_VENOMOUS_WOUNDS                     = 79134,
};

/* Returns true if the spell is a finishing move.
 * A finishing move is a spell that cost combo points */
Optional<int32> GetFinishingMoveCPCost(Spell const* spell)
{
    if (!spell)
        return { };

    return spell->GetPowerTypeCostAmount(POWER_COMBO_POINTS);
}

/* Return true if the spell is a finishing move.
 * A finishing move is a spell that cost combo points */
bool IsFinishingMove(Spell const* spell)
{
    return GetFinishingMoveCPCost(spell).has_value();
}

// 53 - Backstab
class spell_rog_backstab : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_3 } });
    }

    void HandleHitDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* hitUnit = GetHitUnit();
        if (!hitUnit)
            return;

        Unit* caster = GetCaster();
        if (hitUnit->isInBack(caster))
        {
            float currDamage = float(GetHitDamage());
            float newDamage = AddPct(currDamage, float(GetEffectInfo(EFFECT_3).CalcValue(caster)));
            SetHitDamage(newDamage);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rog_backstab::HandleHitDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 379005 - Blackjack
// Called by Sap - 6770 and Blind - 2094
class spell_rog_blackjack : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_BLACKJACK_TALENT, SPELL_ROGUE_BLACKJACK });
    }

    void EffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (Unit* caster = GetCaster())
            if (caster->HasAura(SPELL_ROGUE_BLACKJACK_TALENT))
                caster->CastSpell(GetTarget(), SPELL_ROGUE_BLACKJACK, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectApplyFn(spell_rog_blackjack::EffectRemove, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 13877, 33735, (check 51211, 65956) - Blade Flurry
class spell_rog_blade_flurry : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_BLADE_FLURRY_EXTRA_ATTACK });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        _procTarget = GetTarget()->SelectNearbyTarget(eventInfo.GetProcTarget());
        return _procTarget && eventInfo.GetDamageInfo();
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        if (DamageInfo* damageInfo = eventInfo.GetDamageInfo())
        {
            CastSpellExtraArgs args(aurEff);
            args.AddSpellBP0(damageInfo->GetDamage());
            GetTarget()->CastSpell(_procTarget, SPELL_ROGUE_BLADE_FLURRY_EXTRA_ATTACK, args);
        }
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_rog_blade_flurry::CheckProc);
        if (m_scriptSpellId == SPELL_ROGUE_BLADE_FLURRY)
            OnEffectProc += AuraEffectProcFn(spell_rog_blade_flurry::HandleProc, EFFECT_0, SPELL_AURA_MOD_POWER_REGEN_PERCENT);
        else
            OnEffectProc += AuraEffectProcFn(spell_rog_blade_flurry::HandleProc, EFFECT_0, SPELL_AURA_MOD_MELEE_HASTE);
    }

    Unit* _procTarget = nullptr;
};

// 31230 - Cheat Death
class spell_rog_cheat_death : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_CHEAT_DEATH_DUMMY, SPELL_ROGUE_CHEATED_DEATH, SPELL_ROGUE_CHEATING_DEATH })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    void HandleAbsorb(AuraEffect const* /*aurEff*/, DamageInfo const& /*dmgInfo*/, uint32& absorbAmount)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_ROGUE_CHEATED_DEATH))
        {
            absorbAmount = 0;
            return;
        }

        PreventDefaultAction();

        target->CastSpell(target, SPELL_ROGUE_CHEAT_DEATH_DUMMY, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        target->CastSpell(target, SPELL_ROGUE_CHEATED_DEATH, TRIGGERED_DONT_REPORT_CAST_ERROR);
        target->CastSpell(target, SPELL_ROGUE_CHEATING_DEATH, TRIGGERED_DONT_REPORT_CAST_ERROR);

        target->SetHealth(target->CountPctFromMaxHealth(GetEffectInfo(EFFECT_1).CalcValue(target)));
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbOverkillFn(spell_rog_cheat_death::HandleAbsorb, EFFECT_0);
    }
};

// 2818 - Deadly Poison
class spell_rog_deadly_poison : public SpellScript
{
    bool Load() override
    {
        // at this point CastItem must already be initialized
        return GetCaster()->GetTypeId() == TYPEID_PLAYER && GetCastItem();
    }

    void HandleBeforeHit(SpellMissInfo missInfo)
    {
        if (missInfo != SPELL_MISS_NONE)
            return;

        if (Unit* target = GetHitUnit())
            // Deadly Poison
            if (AuraEffect const* aurEff = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_ROGUE, flag128(0x10000, 0x80000, 0), GetCaster()->GetGUID()))
                _stackAmount = aurEff->GetBase()->GetStackAmount();
    }

    void HandleAfterHit()
    {
        if (_stackAmount < 5)
            return;

        Player* player = GetCaster()->ToPlayer();

        if (Unit* target = GetHitUnit())
        {

            Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);

            if (item == GetCastItem())
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

            if (!item)
                return;

            // item combat enchantments
            for (uint8 slot = 0; slot < MAX_ENCHANTMENT_SLOT; ++slot)
            {
                SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(item->GetEnchantmentId(EnchantmentSlot(slot)));
                if (!enchant)
                    continue;

                for (uint8 s = 0; s < 3; ++s)
                {
                    if (enchant->Effect[s] != ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL)
                        continue;

                    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(enchant->EffectArg[s], DIFFICULTY_NONE);
                    if (!spellInfo)
                    {
                        TC_LOG_ERROR("spells", "Player::CastItemCombatSpell Enchant {}, player (Name: {}, {}) cast unknown spell {}", enchant->ID, player->GetName(), player->GetGUID().ToString(), enchant->EffectArg[s]);
                        continue;
                    }

                    // Proc only rogue poisons
                    if (spellInfo->SpellFamilyName != SPELLFAMILY_ROGUE || spellInfo->Dispel != DISPEL_POISON)
                        continue;

                    // Do not reproc deadly
                    if (spellInfo->SpellFamilyFlags & flag128(0x10000))
                        continue;

                    if (spellInfo->IsPositive())
                        player->CastSpell(player, enchant->EffectArg[s], item);
                    else
                        player->CastSpell(target, enchant->EffectArg[s], item);
                }
            }
        }
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_rog_deadly_poison::HandleBeforeHit);
        AfterHit += SpellHitFn(spell_rog_deadly_poison::HandleAfterHit);
    }

    uint8 _stackAmount = 0;
};

// 32645 - Envenom
class spell_rog_envenom : public SpellScript
{
    void CalculateDamage(Unit* /*victim*/, int32& /*damage*/, int32& flatMod, float& pctMod) const
    {
        pctMod *= GetSpell()->GetPowerTypeCostAmount(POWER_COMBO_POINTS).value_or(0);

        if (AuraEffect const* t5 = GetCaster()->GetAuraEffect(SPELL_ROGUE_T5_2P_SET_BONUS, EFFECT_0))
            flatMod += t5->GetAmount();
    }

    void Register() override
    {
        CalcDamage += SpellCalcDamageFn(spell_rog_envenom::CalculateDamage);
    }
};

// 196819 - Eviscerate
class spell_rog_eviscerate : public SpellScript
{
    void CalculateDamage(Unit* /*victim*/, int32& /*damage*/, int32& flatMod, float& pctMod) const
    {
        pctMod *= GetSpell()->GetPowerTypeCostAmount(POWER_COMBO_POINTS).value_or(0);

        if (AuraEffect const* t5 = GetCaster()->GetAuraEffect(SPELL_ROGUE_T5_2P_SET_BONUS, EFFECT_0))
            flatMod += t5->GetAmount();
    }

    void Register() override
    {
        CalcDamage += SpellCalcDamageFn(spell_rog_eviscerate::CalculateDamage);
    }
};

// 193358 - Grand Melee
class spell_rog_grand_melee : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_SLICE_AND_DICE });
    }

    bool HandleCheckProc(ProcEventInfo& eventInfo)
    {
        Spell const* procSpell = eventInfo.GetProcSpell();
        return procSpell && procSpell->HasPowerTypeCost(POWER_COMBO_POINTS);
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& procInfo)
    {
        Spell const* procSpell = procInfo.GetProcSpell();
        int32 amount = aurEff->GetAmount() * *procSpell->GetPowerTypeCostAmount(POWER_COMBO_POINTS) * 1000;

        if (Unit* target = GetTarget())
        {
            if (Aura* aura = target->GetAura(SPELL_ROGUE_SLICE_AND_DICE))
                aura->SetDuration(aura->GetDuration() + amount);
            else
            {
                CastSpellExtraArgs args;
                args.TriggerFlags = TRIGGERED_FULL_MASK;
                args.AddSpellMod(SPELLVALUE_DURATION, amount);
                target->CastSpell(target, SPELL_ROGUE_SLICE_AND_DICE, args);
            }
        }
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_rog_grand_melee::HandleCheckProc);
        OnEffectProc += AuraEffectProcFn(spell_rog_grand_melee::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 198031 - Honor Among Thieves
/// 7.1.5
class spell_rog_honor_among_thieves : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_HONOR_AMONG_THIEVES_ENERGIZE });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_ROGUE_HONOR_AMONG_THIEVES_ENERGIZE, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_rog_honor_among_thieves::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 5938 - Shiv
class spell_rog_improved_shiv : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_SHIV_NATURE_DAMAGE });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_ROGUE_IMPROVED_SHIV);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_ROGUE_SHIV_NATURE_DAMAGE, CastSpellExtraArgs()
            .SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR)
            .SetTriggeringSpell(GetSpell()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rog_improved_shiv::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 51690 - Killing Spree
class spell_rog_killing_spree_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_ROGUE_KILLING_SPREE_TELEPORT,
            SPELL_ROGUE_KILLING_SPREE_WEAPON_DMG,
            SPELL_ROGUE_KILLING_SPREE_DMG_BUFF
        });
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_ROGUE_KILLING_SPREE_DMG_BUFF, true);
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        while (!_targets.empty())
        {
            ObjectGuid guid = Trinity::Containers::SelectRandomContainerElement(_targets);
            if (Unit* target = ObjectAccessor::GetUnit(*GetTarget(), guid))
            {
                GetTarget()->CastSpell(target, SPELL_ROGUE_KILLING_SPREE_TELEPORT, true);
                GetTarget()->CastSpell(target, SPELL_ROGUE_KILLING_SPREE_WEAPON_DMG, true);
                break;
            }
            else
                _targets.remove(guid);
        }
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_ROGUE_KILLING_SPREE_DMG_BUFF);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_rog_killing_spree_aura::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_rog_killing_spree_aura::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_rog_killing_spree_aura::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }

public:
    void AddTarget(Unit* target)
    {
        _targets.push_back(target->GetGUID());
    }

private:
    GuidList _targets;
};

class spell_rog_killing_spree : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty() || GetCaster()->GetVehicleBase())
            FinishCast(SPELL_FAILED_OUT_OF_RANGE);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Aura* aura = GetCaster()->GetAura(SPELL_ROGUE_KILLING_SPREE))
            if (spell_rog_killing_spree_aura* script = aura->GetScript<spell_rog_killing_spree_aura>())
                script->AddTarget(GetHitUnit());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_rog_killing_spree::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_rog_killing_spree::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 385627 - Kingsbane
class spell_rog_kingsbane : public AuraScript
{
    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo& procInfo)
    {
        return procInfo.GetActionTarget()->HasAura(GetId(), GetCasterGUID());
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_rog_kingsbane::CheckProc, EFFECT_4, SPELL_AURA_PROC_TRIGGER_SPELL);;
    }
};

// 76806 - Mastery: Main Gauche
class spell_rog_mastery_main_gauche : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_MAIN_GAUCHE });
    }

    bool HandleCheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetDamageInfo() && eventInfo.GetDamageInfo()->GetVictim();
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& procInfo)
    {
        if (Unit* target = GetTarget())
            target->CastSpell(procInfo.GetDamageInfo()->GetVictim(), SPELL_ROGUE_MAIN_GAUCHE, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_rog_mastery_main_gauche::HandleCheckProc);
        OnEffectProc += AuraEffectProcFn(spell_rog_mastery_main_gauche::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_rog_pickpocket : public SpellScript
{
    SpellCastResult CheckCast()
    {
        if (!GetExplTargetUnit() || !GetCaster()->IsValidAttackTarget(GetExplTargetUnit(), GetSpellInfo()))
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_rog_pickpocket::CheckCast);
    }
};

// 131511 - Prey on the Weak
// Called by Cheap Shot - 1833 and Kidney Shot - 408
class spell_rog_prey_on_the_weak : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_PREY_ON_THE_WEAK_TALENT, SPELL_ROGUE_PREY_ON_THE_WEAK });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (Unit* caster = GetCaster())
            if (caster->HasAura(SPELL_ROGUE_PREY_ON_THE_WEAK_TALENT))
                caster->CastSpell(GetTarget(), SPELL_ROGUE_PREY_ON_THE_WEAK, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_rog_prey_on_the_weak::OnApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 79096 - Restless Blades
class spell_rog_restless_blades : public AuraScript
{
    static uint32 constexpr Spells[] = { SPELL_ROGUE_ADRENALINE_RUSH, SPELL_ROGUE_BETWEEN_THE_EYES, SPELL_ROGUE_SPRINT,
        SPELL_ROGUE_GRAPPLING_HOOK, SPELL_ROGUE_VANISH, SPELL_ROGUE_KILLING_SPREE, SPELL_ROGUE_MARKED_FOR_DEATH, SPELL_ROGUE_DEATH_FROM_ABOVE };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(Spells);
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& procInfo)
    {
        if (Optional<int32> spentCP = GetFinishingMoveCPCost(procInfo.GetProcSpell()))
        {
            int32 cdExtra = -(float(aurEff->GetAmount() * *spentCP) * 0.1f);

            SpellHistory* history = GetTarget()->GetSpellHistory();
            for (uint32 spellId : Spells)
                history->ModifyCooldown(spellId, Seconds(cdExtra), true);
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_rog_restless_blades::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 315508 - Roll the Bones
class spell_rog_roll_the_bones : public SpellScript
{
    static uint32 constexpr Spells[] = { SPELL_ROGUE_SKULL_AND_CROSSBONES, SPELL_ROGUE_GRAND_MELEE, SPELL_ROGUE_RUTHLESS_PRECISION,
        SPELL_ROGUE_TRUE_BEARING, SPELL_ROGUE_BURIED_TREASURE, SPELL_ROGUE_BROADSIDE };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(Spells);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        int32 currentDuration = 0;
        for (uint32 spellId : Spells)
        {
            if (Aura* aura = GetCaster()->GetAura(spellId))
            {
                currentDuration = aura->GetDuration();
                GetCaster()->RemoveAura(aura);
            }
        }

        std::vector<uint32> possibleBuffs(std::begin(Spells), std::end(Spells));
        Trinity::Containers::RandomShuffle(possibleBuffs);

        // https://www.icy-veins.com/wow/outlaw-rogue-pve-dps-rotation-cooldowns-abilities
        // 1 Roll the Bones buff  : 100.0 % chance;
        // 2 Roll the Bones buffs : 19 % chance;
        // 5 Roll the Bones buffs : 1 % chance.
        int32 chance = irand(1, 100);
        int32 numBuffs = 1;
        if (chance <= 1)
            numBuffs = 5;
        else if (chance <= 20)
            numBuffs = 2;

        for (int32 i = 0; i < numBuffs; ++i)
        {
            uint32 spellId = possibleBuffs[i];
            CastSpellExtraArgs args;
            args.TriggerFlags = TRIGGERED_FULL_MASK;
            args.AddSpellMod(SPELLVALUE_DURATION, GetSpellInfo()->GetDuration() + currentDuration);
            GetCaster()->CastSpell(GetCaster(), spellId, args);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rog_roll_the_bones::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 1943 - Rupture
class spell_rog_rupture : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_VENOMOUS_WOUNDS });
    }

    void OnEffectRemoved(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
            return;

        Aura* aura = GetAura();
        Unit* caster = aura->GetCaster();
        if (!caster)
            return;

        Aura* auraVenomousWounds = caster->GetAura(SPELL_ROGUE_VENOMOUS_WOUNDS);
        if (!auraVenomousWounds)
            return;

        // Venomous Wounds: if unit dies while being affected by rupture, regain energy based on remaining duration
        Optional<SpellPowerCost> cost = GetSpellInfo()->CalcPowerCost(POWER_ENERGY, false, caster, GetSpellInfo()->GetSchoolMask(), nullptr);
        if (!cost)
            return;

        float pct = float(aura->GetDuration()) / float(aura->GetMaxDuration());
        int32 extraAmount = float(cost->Amount) * pct;
        caster->ModifyPower(POWER_ENERGY, extraAmount);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_rog_rupture::OnEffectRemoved, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 14161 - Ruthlessness
class spell_rog_ruthlessness : public AuraScript
{
    void HandleProc(AuraEffect* aurEff, ProcEventInfo& procInfo)
    {
        Unit* target = GetTarget();

        if (Optional<int32> cost = GetFinishingMoveCPCost(procInfo.GetProcSpell()))
            if (roll_chance_i(aurEff->GetSpellEffectInfo().PointsPerResource * (*cost)))
                target->ModifyPower(POWER_COMBO_POINTS, 1);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_rog_ruthlessness::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 185438 - Shadowstrike
class spell_rog_shadowstrike : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_PREMEDITATION_AURA, SPELL_ROGUE_SLICE_AND_DICE, SPELL_ROGUE_PREMEDITATION_PASSIVE })
            && ValidateSpellEffect({ { SPELL_ROGUE_PREMEDITATION_PASSIVE, EFFECT_0 } });
    }

    SpellCastResult HandleCheckCast()
    {
        // Because the premeditation aura is removed when we're out of stealth,
        // when we reach HandleEnergize the aura won't be there, even if it was when player launched the spell
        _hasPremeditationAura = GetCaster()->HasAura(SPELL_ROGUE_PREMEDITATION_AURA);
        return SPELL_FAILED_SUCCESS;
    }

    void HandleEnergize(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (_hasPremeditationAura)
        {
            if (caster->HasAura(SPELL_ROGUE_SLICE_AND_DICE))
                if (Aura* premeditationPassive = caster->GetAura(SPELL_ROGUE_PREMEDITATION_PASSIVE))
                    if (AuraEffect const* auraEff = premeditationPassive->GetEffect(EFFECT_1))
                        SetHitDamage(GetHitDamage() + auraEff->GetAmount());

            // Grant 10 seconds of slice and dice
            int32 duration = sSpellMgr->AssertSpellInfo(SPELL_ROGUE_PREMEDITATION_PASSIVE, DIFFICULTY_NONE)->GetEffect(EFFECT_0).CalcValue(GetCaster());

            CastSpellExtraArgs args;
            args.TriggerFlags = TRIGGERED_FULL_MASK;
            args.AddSpellMod(SPELLVALUE_DURATION, duration * IN_MILLISECONDS);
            caster->CastSpell(caster, SPELL_ROGUE_SLICE_AND_DICE, args);
        }
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_rog_shadowstrike::HandleCheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_rog_shadowstrike::HandleEnergize, EFFECT_1, SPELL_EFFECT_ENERGIZE);
    }

private:
    bool _hasPremeditationAura = false;
};

// 193315 - Sinister Strike
class spell_rog_sinister_strike : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_T5_2P_SET_BONUS });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        int32 damagePerCombo = GetHitDamage();
        if (AuraEffect const* t5 = GetCaster()->GetAuraEffect(SPELL_ROGUE_T5_2P_SET_BONUS, EFFECT_0))
            damagePerCombo += t5->GetAmount();

        int32 finalDamage = damagePerCombo;
        std::vector<SpellPowerCost> const& costs = GetSpell()->GetPowerCost();
        auto c = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_COMBO_POINTS; });
        if (c != costs.end())
            finalDamage *= c->Amount;

        SetHitDamage(finalDamage);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rog_sinister_strike::HandleDummy, EFFECT_2, SPELL_EFFECT_DUMMY);
    }
};

// 1784 - Stealth
class spell_rog_stealth : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE,
            SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT,
            SPELL_ROGUE_SANCTUARY,
            SPELL_ROGUE_SHADOW_FOCUS,
            SPELL_ROGUE_SHADOW_FOCUS_EFFECT,
            SPELL_ROGUE_STEALTH_STEALTH_AURA,
            SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA
        });
    }

    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        // Master of Subtlety
        if (target->HasAura(SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE))
            target->CastSpell(target, SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT, TRIGGERED_FULL_MASK);

        // Shadow Focus
        if (target->HasAura(SPELL_ROGUE_SHADOW_FOCUS))
            target->CastSpell(target, SPELL_ROGUE_SHADOW_FOCUS_EFFECT, TRIGGERED_FULL_MASK);

        // Premeditation
        if (target->HasAura(SPELL_ROGUE_PREMEDITATION_PASSIVE))
            target->CastSpell(target, SPELL_ROGUE_PREMEDITATION_AURA, true);

        target->CastSpell(target, SPELL_ROGUE_SANCTUARY, TRIGGERED_FULL_MASK);
        target->CastSpell(target, SPELL_ROGUE_STEALTH_STEALTH_AURA, TRIGGERED_FULL_MASK);
        target->CastSpell(target, SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA, TRIGGERED_FULL_MASK);
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        // Master of Subtlety
        if (AuraEffect* masterOfSubtletyPassive = GetTarget()->GetAuraEffect(SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE, EFFECT_0))
        {
            if (Aura* masterOfSubtletyAura = GetTarget()->GetAura(SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT))
            {
                masterOfSubtletyAura->SetMaxDuration(masterOfSubtletyPassive->GetAmount());
                masterOfSubtletyAura->RefreshDuration();
            }
        }

        // Premeditation
        target->RemoveAura(SPELL_ROGUE_PREMEDITATION_AURA);

        target->RemoveAurasDueToSpell(SPELL_ROGUE_SHADOW_FOCUS_EFFECT);
        target->RemoveAurasDueToSpell(SPELL_ROGUE_STEALTH_STEALTH_AURA);
        target->RemoveAurasDueToSpell(SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_rog_stealth::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_rog_stealth::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 212283 - Symbols of Death
class spell_rog_symbols_of_death : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_SYMBOLS_OF_DEATH_RANK2, SPELL_ROGUE_SYMBOLS_OF_DEATH_CRIT_AURA });
    }

    void HandleEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (GetCaster()->HasAura(SPELL_ROGUE_SYMBOLS_OF_DEATH_RANK2))
            GetCaster()->CastSpell(GetCaster(), SPELL_ROGUE_SYMBOLS_OF_DEATH_CRIT_AURA, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rog_symbols_of_death::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 57934 - Tricks of the Trade
class spell_rog_tricks_of_the_trade_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_TRICKS_OF_THE_TRADE_PROC });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEFAULT || !GetTarget()->HasAura(SPELL_ROGUE_TRICKS_OF_THE_TRADE_PROC))
            GetTarget()->GetThreatManager().UnregisterRedirectThreat(SPELL_ROGUE_TRICKS_OF_THE_TRADE);
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        Unit* rogue = GetTarget();
        if (ObjectAccessor::GetUnit(*rogue, _redirectTarget))
            rogue->CastSpell(rogue, SPELL_ROGUE_TRICKS_OF_THE_TRADE_PROC, aurEff);
        Remove(AURA_REMOVE_BY_DEFAULT);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_rog_tricks_of_the_trade_aura::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectProc += AuraEffectProcFn(spell_rog_tricks_of_the_trade_aura::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }

    ObjectGuid _redirectTarget;
public:
    void SetRedirectTarget(ObjectGuid guid) { _redirectTarget = guid; }
};

// 57934 - Tricks of the Trade
class spell_rog_tricks_of_the_trade : public SpellScript
{
    void DoAfterHit()
    {
        if (Aura* aura = GetHitAura())
            if (spell_rog_tricks_of_the_trade_aura* script = aura->GetScript<spell_rog_tricks_of_the_trade_aura>())
            {
                if (Unit* explTarget = GetExplTargetUnit())
                    script->SetRedirectTarget(explTarget->GetGUID());
                else
                    script->SetRedirectTarget(ObjectGuid::Empty);
            }
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_rog_tricks_of_the_trade::DoAfterHit);
    }
};

// 59628 - Tricks of the Trade (Proc)
class spell_rog_tricks_of_the_trade_proc : public AuraScript
{
    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->GetThreatManager().UnregisterRedirectThreat(SPELL_ROGUE_TRICKS_OF_THE_TRADE);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_rog_tricks_of_the_trade_proc::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 198020 - Turn the Tables (PvP Talent)
class spell_rog_turn_the_tables : public AuraScript
{
    bool CheckForStun(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        return eventInfo.GetProcSpell() && eventInfo.GetProcSpell()->GetSpellInfo()->HasAura(SPELL_AURA_MOD_STUN);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_rog_turn_the_tables::CheckForStun, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 198023 - Turn the Tables (periodic)
class spell_rog_turn_the_tables_periodic_check : public AuraScript
{
    bool Validate(SpellInfo const*) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_TURN_THE_TABLES_BUFF });
    }

    void CheckForStun(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();
        if (!target->HasAuraType(SPELL_AURA_MOD_STUN))
        {
            target->CastSpell(target, SPELL_ROGUE_TURN_THE_TABLES_BUFF, aurEff);
            PreventDefaultAction();
            Remove();
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_rog_turn_the_tables_periodic_check::CheckForStun, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 1856 - Vanish - SPELL_ROGUE_VANISH
class spell_rog_vanish : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_VANISH_AURA, SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA });
    }

    void OnLaunchTarget(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        Unit* target = GetHitUnit();

        target->RemoveAurasByType(SPELL_AURA_MOD_STALKED);
        if (target->GetTypeId() != TYPEID_PLAYER)
            return;

        if (target->HasAura(SPELL_ROGUE_VANISH_AURA))
            return;

        target->CastSpell(target, SPELL_ROGUE_VANISH_AURA, TRIGGERED_FULL_MASK);
        target->CastSpell(target, SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_rog_vanish::OnLaunchTarget, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
    }
};

// 11327 - Vanish
class spell_rog_vanish_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_STEALTH });
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_ROGUE_STEALTH, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_rog_vanish_aura::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 79134 - Venomous Wounds - SPELL_ROGUE_VENOMOUS_WOUNDS
class spell_rog_venomous_wounds : public AuraScript
{
    void HandleProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        int32 extraEnergy = aurEff->GetAmount();
        GetTarget()->ModifyPower(POWER_ENERGY, extraEnergy);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_rog_venomous_wounds::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

void AddSC_rogue_spell_scripts()
{
    RegisterSpellScript(spell_rog_backstab);
    RegisterSpellScript(spell_rog_blackjack);
    RegisterSpellScript(spell_rog_blade_flurry);
    RegisterSpellScript(spell_rog_cheat_death);
    RegisterSpellScript(spell_rog_deadly_poison);
    RegisterSpellScript(spell_rog_envenom);
    RegisterSpellScript(spell_rog_eviscerate);
    RegisterSpellScript(spell_rog_grand_melee);
    RegisterSpellScript(spell_rog_honor_among_thieves);
    RegisterSpellScript(spell_rog_improved_shiv);
    RegisterSpellAndAuraScriptPair(spell_rog_killing_spree, spell_rog_killing_spree_aura);
    RegisterSpellScript(spell_rog_kingsbane);
    RegisterSpellScript(spell_rog_mastery_main_gauche);
    RegisterSpellScript(spell_rog_pickpocket);
    RegisterSpellScript(spell_rog_prey_on_the_weak);
    RegisterSpellScript(spell_rog_restless_blades);
    RegisterSpellScript(spell_rog_roll_the_bones);
    RegisterSpellScript(spell_rog_rupture);
    RegisterSpellScript(spell_rog_ruthlessness);
    RegisterSpellScript(spell_rog_shadowstrike);
    RegisterSpellScript(spell_rog_sinister_strike);
    RegisterSpellScript(spell_rog_stealth);
    RegisterSpellScript(spell_rog_symbols_of_death);
    RegisterSpellAndAuraScriptPair(spell_rog_tricks_of_the_trade, spell_rog_tricks_of_the_trade_aura);
    RegisterSpellScript(spell_rog_tricks_of_the_trade_proc);
    RegisterSpellScript(spell_rog_turn_the_tables);
    RegisterSpellScript(spell_rog_turn_the_tables_periodic_check);
    RegisterSpellScript(spell_rog_vanish);
    RegisterSpellScript(spell_rog_vanish_aura);
    RegisterSpellScript(spell_rog_venomous_wounds);
}
