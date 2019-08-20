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
 * Scripts for spells with SPELLFAMILY_GENERIC which cannot be included in AI script file
 * of creature using it or can't be bound to any player class.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_gen_"
 */

#include "ScriptMgr.h"
#include "Battleground.h"
#include "CellImpl.h"
#include "DBCStores.h"
#include "GameTime.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "InstanceScript.h"
#include "Item.h"
#include "LFGMgr.h"
#include "Log.h"
#include "Pet.h"
#include "ReputationMgr.h"
#include "SkillDiscovery.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Vehicle.h"

class spell_gen_absorb0_hitlimit1 : public AuraScript
{
    PrepareAuraScript(spell_gen_absorb0_hitlimit1);

    uint32 limit = 0;

    bool Load() override
    {
        // Max absorb stored in 1 dummy effect
        limit = GetSpellInfo()->Effects[EFFECT_1].CalcValue();
        return true;
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo& /*dmgInfo*/, uint32& absorbAmount)
    {
        absorbAmount = std::min(limit, absorbAmount);
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_gen_absorb0_hitlimit1::Absorb, EFFECT_0);
    }
};

// 28764 - Adaptive Warding (Frostfire Regalia Set)
enum AdaptiveWarding
{
    SPELL_GEN_ADAPTIVE_WARDING_FIRE     = 28765,
    SPELL_GEN_ADAPTIVE_WARDING_NATURE   = 28768,
    SPELL_GEN_ADAPTIVE_WARDING_FROST    = 28766,
    SPELL_GEN_ADAPTIVE_WARDING_SHADOW   = 28769,
    SPELL_GEN_ADAPTIVE_WARDING_ARCANE   = 28770
};

class spell_gen_adaptive_warding : public AuraScript
{
    PrepareAuraScript(spell_gen_adaptive_warding);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_GEN_ADAPTIVE_WARDING_FIRE,
            SPELL_GEN_ADAPTIVE_WARDING_NATURE,
            SPELL_GEN_ADAPTIVE_WARDING_FROST,
            SPELL_GEN_ADAPTIVE_WARDING_SHADOW,
            SPELL_GEN_ADAPTIVE_WARDING_ARCANE
        });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetSpellInfo())
            return false;

        // find Mage Armor
        if (!GetTarget()->GetAuraEffect(SPELL_AURA_MOD_MANA_REGEN_INTERRUPT, SPELLFAMILY_MAGE, 0x10000000, 0x0, 0x0))
            return false;

        switch (GetFirstSchoolInMask(eventInfo.GetSchoolMask()))
        {
            case SPELL_SCHOOL_NORMAL:
            case SPELL_SCHOOL_HOLY:
                return false;
            default:
                break;
        }
        return true;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        uint32 spellId = 0;
        switch (GetFirstSchoolInMask(eventInfo.GetSchoolMask()))
        {
            case SPELL_SCHOOL_FIRE:
                spellId = SPELL_GEN_ADAPTIVE_WARDING_FIRE;
                break;
            case SPELL_SCHOOL_NATURE:
                spellId = SPELL_GEN_ADAPTIVE_WARDING_NATURE;
                break;
            case SPELL_SCHOOL_FROST:
                spellId = SPELL_GEN_ADAPTIVE_WARDING_FROST;
                break;
            case SPELL_SCHOOL_SHADOW:
                spellId = SPELL_GEN_ADAPTIVE_WARDING_SHADOW;
                break;
            case SPELL_SCHOOL_ARCANE:
                spellId = SPELL_GEN_ADAPTIVE_WARDING_ARCANE;
                break;
            default:
                return;
        }
        GetTarget()->CastSpell(GetTarget(), spellId, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_gen_adaptive_warding::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_gen_adaptive_warding::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_gen_allow_cast_from_item_only : public SpellScript
{
    PrepareSpellScript(spell_gen_allow_cast_from_item_only);

    SpellCastResult CheckRequirement()
    {
        if (!GetCastItem())
            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_gen_allow_cast_from_item_only::CheckRequirement);
    }
};

enum AnimalBloodPoolSpell
{
    SPELL_ANIMAL_BLOOD      = 46221,
    SPELL_SPAWN_BLOOD_POOL  = 63471
};

// 46221 - Animal Blood
class spell_gen_animal_blood : public AuraScript
{
    PrepareAuraScript(spell_gen_animal_blood);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SPAWN_BLOOD_POOL });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // Remove all auras with spell id 46221, except the one currently being applied
        while (Aura* aur = GetUnitOwner()->GetOwnedAura(SPELL_ANIMAL_BLOOD, ObjectGuid::Empty, ObjectGuid::Empty, 0, GetAura()))
            GetUnitOwner()->RemoveOwnedAura(aur);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* owner = GetUnitOwner())
            if (owner->IsInWater())
                owner->CastSpell(owner, SPELL_SPAWN_BLOOD_POOL, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectRemoveFn(spell_gen_animal_blood::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_gen_animal_blood::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 63471 -Spawn Blood Pool
class spell_spawn_blood_pool : public SpellScript
{
    PrepareSpellScript(spell_spawn_blood_pool);

    void SetDest(SpellDestination& dest)
    {
        Unit* caster = GetCaster();
        Position summonPos = caster->GetPosition();
        LiquidData liquidStatus;
        if (caster->GetMap()->GetLiquidStatus(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), MAP_ALL_LIQUIDS, &liquidStatus, caster->GetCollisionHeight()))
            summonPos.m_positionZ = liquidStatus.level;
        dest.Relocate(summonPos);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_spawn_blood_pool::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

class spell_gen_arcane_charge : public SpellScript
{
    PrepareSpellScript(spell_gen_arcane_charge);

    SpellCastResult CheckRequirement()
    {
        if (Unit* target = GetExplTargetUnit())
        {
            if (!(target->GetCreatureTypeMask() & CREATURE_TYPEMASK_DEMON_OR_UNDEAD))
                return SPELL_FAILED_DONT_REPORT;
        }

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_gen_arcane_charge::CheckRequirement);
    }
};

// 430 Drink
// 431 Drink
// 432 Drink
// 1133 Drink
// 1135 Drink
// 1137 Drink
// 10250 Drink
// 22734 Drink
// 27089 Drink
// 34291 Drink
// 43182 Drink
// 43183 Drink
// 46755 Drink
// 49472 Drink Coffee
// 57073 Drink
// 61830 Drink
// 72623 Drink
class spell_gen_arena_drink : public AuraScript
{
    PrepareAuraScript(spell_gen_arena_drink);

    bool Load() override
    {
        return GetCaster() && GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    bool Validate(SpellInfo const* spellInfo) override
    {
        if (!spellInfo->Effects[EFFECT_0].IsAura() || spellInfo->Effects[EFFECT_0].ApplyAuraName != SPELL_AURA_MOD_POWER_REGEN)
        {
            TC_LOG_ERROR("spells", "Aura %d structure has been changed - first aura is no longer SPELL_AURA_MOD_POWER_REGEN", GetId());
            return false;
        }

        return true;
    }

    void CalcPeriodic(AuraEffect const* /*aurEff*/, bool& isPeriodic, int32& /*amplitude*/)
    {
        // Get SPELL_AURA_MOD_POWER_REGEN aura from spell
        AuraEffect* regen = GetAura()->GetEffect(EFFECT_0);
        if (!regen)
            return;

        // default case - not in arena
        if (!GetCaster()->ToPlayer()->InArena())
            isPeriodic = false;
    }

    void CalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        AuraEffect* regen = GetAura()->GetEffect(EFFECT_0);
        if (!regen)
            return;

        // default case - not in arena
        if (!GetCaster()->ToPlayer()->InArena())
            regen->ChangeAmount(amount);
    }

    void UpdatePeriodic(AuraEffect* aurEff)
    {
        AuraEffect* regen = GetAura()->GetEffect(EFFECT_0);
        if (!regen)
            return;

        // **********************************************
        // This feature used only in arenas
        // **********************************************
        // Here need increase mana regen per tick (6 second rule)
        // on 0 tick -   0  (handled in 2 second)
        // on 1 tick - 166% (handled in 4 second)
        // on 2 tick - 133% (handled in 6 second)

        // Apply bonus for 1 - 4 tick
        switch (aurEff->GetTickNumber())
        {
            case 1:   // 0%
                regen->ChangeAmount(0);
                break;
            case 2:   // 166%
                regen->ChangeAmount(aurEff->GetAmount() * 5 / 3);
                break;
            case 3:   // 133%
                regen->ChangeAmount(aurEff->GetAmount() * 4 / 3);
                break;
            default:  // 100% - normal regen
                regen->ChangeAmount(aurEff->GetAmount());
                // No need to update after 4th tick
                aurEff->SetPeriodic(false);
                break;
        }
    }

    void Register() override
    {
        DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_gen_arena_drink::CalcPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_arena_drink::CalcAmount, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_gen_arena_drink::UpdatePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 41337 Aura of Anger
class spell_gen_aura_of_anger : public AuraScript
{
    PrepareAuraScript(spell_gen_aura_of_anger);

    void HandleEffectPeriodicUpdate(AuraEffect* aurEff)
    {
        if (AuraEffect* aurEff1 = aurEff->GetBase()->GetEffect(EFFECT_1))
            aurEff1->ChangeAmount(aurEff1->GetAmount() + 5);
        aurEff->SetAmount(100 * aurEff->GetTickNumber());
    }

    void Register() override
    {
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_gen_aura_of_anger::HandleEffectPeriodicUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 28313 - Aura of Fear
class spell_gen_aura_of_fear : public AuraScript
{
    PrepareAuraScript(spell_gen_aura_of_fear);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->Effects[EFFECT_0].TriggerSpell });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        if (!roll_chance_i(GetSpellInfo()->ProcChance))
            return;

        GetTarget()->CastSpell(nullptr, GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_aura_of_fear::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

enum ServiceUniform
{
    // Spells
    SPELL_SERVICE_UNIFORM       = 71450,

    // Models
    MODEL_GOBLIN_MALE           = 31002,
    MODEL_GOBLIN_FEMALE         = 31003
};

class spell_gen_aura_service_uniform : public AuraScript
{
    PrepareAuraScript(spell_gen_aura_service_uniform);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SERVICE_UNIFORM });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // Apply model goblin
        Unit* target = GetTarget();
        if (target->GetTypeId() == TYPEID_PLAYER)
        {
            if (target->GetNativeGender() == GENDER_MALE)
                target->SetDisplayId(MODEL_GOBLIN_MALE);
            else
                target->SetDisplayId(MODEL_GOBLIN_FEMALE);
        }
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->GetTypeId() == TYPEID_PLAYER)
            target->RestoreDisplayId();
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectRemoveFn(spell_gen_aura_service_uniform::OnApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_gen_aura_service_uniform::OnRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_gen_av_drekthar_presence : public AuraScript
{
    PrepareAuraScript(spell_gen_av_drekthar_presence);

    bool CheckAreaTarget(Unit* target)
    {
        switch (target->GetEntry())
        {
            // alliance
            case 14762: // Dun Baldar North Marshal
            case 14763: // Dun Baldar South Marshal
            case 14764: // Icewing Marshal
            case 14765: // Stonehearth Marshal
            case 11948: // Vandar Stormspike
            // horde
            case 14772: // East Frostwolf Warmaster
            case 14776: // Tower Point Warmaster
            case 14773: // Iceblood Warmaster
            case 14777: // West Frostwolf Warmaster
            case 11946: // Drek'thar
                return true;
            default:
                return false;
        }
    }

    void Register() override
    {
        DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_gen_av_drekthar_presence::CheckAreaTarget);
    }
};

enum GenericBandage
{
    SPELL_RECENTLY_BANDAGED     = 11196
};

class spell_gen_bandage : public SpellScript
{
    PrepareSpellScript(spell_gen_bandage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RECENTLY_BANDAGED });
    }

    SpellCastResult CheckCast()
    {
        if (Unit* target = GetExplTargetUnit())
        {
            if (target->HasAura(SPELL_RECENTLY_BANDAGED))
                return SPELL_FAILED_TARGET_AURASTATE;
        }
        return SPELL_CAST_OK;
    }

    void HandleScript()
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, SPELL_RECENTLY_BANDAGED, true);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_gen_bandage::CheckCast);
        AfterHit += SpellHitFn(spell_gen_bandage::HandleScript);
    }
};

// Blood Reserve - 64568
enum BloodReserve
{
    SPELL_GEN_BLOOD_RESERVE_AURA = 64568,
    SPELL_GEN_BLOOD_RESERVE_HEAL = 64569
};

class spell_gen_blood_reserve : public AuraScript
{
    PrepareAuraScript(spell_gen_blood_reserve);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GEN_BLOOD_RESERVE_HEAL });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (Unit* caster = eventInfo.GetActionTarget())
            if (caster->HealthBelowPct(35))
                return true;

        return false;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* caster = eventInfo.GetActionTarget();
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(aurEff->GetAmount());
        caster->CastSpell(caster, SPELL_GEN_BLOOD_RESERVE_HEAL, args);
        caster->RemoveAura(SPELL_GEN_BLOOD_RESERVE_AURA);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_gen_blood_reserve::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_gen_blood_reserve::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// Blade Warding - 64440
enum BladeWarding
{
    SPELL_GEN_BLADE_WARDING_TRIGGERED = 64442
};

class spell_gen_blade_warding : public AuraScript
{
    PrepareAuraScript(spell_gen_blade_warding);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GEN_BLADE_WARDING_TRIGGERED });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* caster = eventInfo.GetActionTarget();
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_GEN_BLADE_WARDING_TRIGGERED);

        uint8 stacks = GetStackAmount();
        int32 bp = 0;

        for (uint8 i = 0; i < stacks; ++i)
            bp += spellInfo->Effects[EFFECT_0].CalcValue(caster);

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(bp);
        caster->CastSpell(eventInfo.GetActor(), SPELL_GEN_BLADE_WARDING_TRIGGERED, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_gen_blade_warding::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

enum Bonked
{
    SPELL_BONKED            = 62991,
    SPELL_FOAM_SWORD_DEFEAT = 62994,
    SPELL_ON_GUARD          = 62972
};

class spell_gen_bonked : public SpellScript
{
    PrepareSpellScript(spell_gen_bonked);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Player* target = GetHitPlayer())
        {
            Aura const* aura = GetHitAura();
            if (!(aura && aura->GetStackAmount() == 3))
                return;

            target->CastSpell(target, SPELL_FOAM_SWORD_DEFEAT, true);
            target->RemoveAurasDueToSpell(SPELL_BONKED);

            if (Aura const* auraOnGuard = target->GetAura(SPELL_ON_GUARD))
                if (Item* item = target->GetItemByGuid(auraOnGuard->GetCastItemGUID()))
                    target->DestroyItemCount(item->GetEntry(), 1, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_bonked::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/* DOCUMENTATION: Break-Shield spells
    Break-Shield spells can be classified in three groups:

        - Spells on vehicle bar used by players:
            + EFFECT_0: SCRIPT_EFFECT
            + EFFECT_1: NONE
            + EFFECT_2: NONE
        - Spells cast by players triggered by script:
            + EFFECT_0: SCHOOL_DAMAGE
            + EFFECT_1: SCRIPT_EFFECT
            + EFFECT_2: FORCE_CAST
        - Spells cast by NPCs on players:
            + EFFECT_0: SCHOOL_DAMAGE
            + EFFECT_1: SCRIPT_EFFECT
            + EFFECT_2: NONE

    In the following script we handle the SCRIPT_EFFECT for effIndex EFFECT_0 and EFFECT_1.
        - When handling EFFECT_0 we're in the "Spells on vehicle bar used by players" case
          and we'll trigger "Spells cast by players triggered by script"
        - When handling EFFECT_1 we're in the "Spells cast by players triggered by script"
          or "Spells cast by NPCs on players" so we'll search for the first defend layer and drop it.
*/

enum BreakShieldSpells
{
    SPELL_BREAK_SHIELD_DAMAGE_2K                 = 62626,
    SPELL_BREAK_SHIELD_DAMAGE_10K                = 64590,

    SPELL_BREAK_SHIELD_TRIGGER_FACTION_MOUNTS    = 62575, // Also on ToC5 mounts
    SPELL_BREAK_SHIELD_TRIGGER_CAMPAING_WARHORSE = 64595,
    SPELL_BREAK_SHIELD_TRIGGER_UNK               = 66480
};

class spell_gen_break_shield: public SpellScriptLoader
{
    public:
        spell_gen_break_shield(char const* name) : SpellScriptLoader(name) { }

        class spell_gen_break_shield_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gen_break_shield_SpellScript);

            void HandleScriptEffect(SpellEffIndex effIndex)
            {
                Unit* target = GetHitUnit();

                switch (effIndex)
                {
                    case EFFECT_0: // On spells wich trigger the damaging spell (and also the visual)
                    {
                        uint32 spellId;

                        switch (GetSpellInfo()->Id)
                        {
                            case SPELL_BREAK_SHIELD_TRIGGER_UNK:
                            case SPELL_BREAK_SHIELD_TRIGGER_CAMPAING_WARHORSE:
                                spellId = SPELL_BREAK_SHIELD_DAMAGE_10K;
                                break;
                            case SPELL_BREAK_SHIELD_TRIGGER_FACTION_MOUNTS:
                                spellId = SPELL_BREAK_SHIELD_DAMAGE_2K;
                                break;
                            default:
                                return;
                        }

                        if (Unit* rider = GetCaster()->GetCharmer())
                            rider->CastSpell(target, spellId, false);
                        else
                            GetCaster()->CastSpell(target, spellId, false);
                        break;
                    }
                    case EFFECT_1: // On damaging spells, for removing a defend layer
                    {
                        Unit::AuraApplicationMap const& auras = target->GetAppliedAuras();
                        for (Unit::AuraApplicationMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                        {
                            if (Aura* aura = itr->second->GetBase())
                            {
                                SpellInfo const* auraInfo = aura->GetSpellInfo();
                                if (auraInfo && auraInfo->SpellIconID == 2007 && aura->HasEffectType(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN))
                                {
                                    aura->ModStackAmount(-1, AURA_REMOVE_BY_ENEMY_SPELL);
                                    // Remove dummys from rider (Necessary for updating visual shields)
                                    if (Unit* rider = target->GetCharmer())
                                        if (Aura* defend = rider->GetAura(aura->GetId()))
                                            defend->ModStackAmount(-1, AURA_REMOVE_BY_ENEMY_SPELL);
                                    break;
                                }
                            }
                        }
                        break;
                    }
                    default:
                        break;
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_gen_break_shield_SpellScript::HandleScriptEffect, EFFECT_FIRST_FOUND, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gen_break_shield_SpellScript();
        }
};

// 46394 Brutallus Burn
class spell_gen_burn_brutallus : public AuraScript
{
    PrepareAuraScript(spell_gen_burn_brutallus);

    void HandleEffectPeriodicUpdate(AuraEffect* aurEff)
    {
        if (aurEff->GetTickNumber() % 11 == 0)
            aurEff->SetAmount(aurEff->GetAmount() * 2);
    }

    void Register() override
    {
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_gen_burn_brutallus::HandleEffectPeriodicUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 48750 - Burning Depths Necrolyte Image
class spell_gen_burning_depths_necrolyte_image : public AuraScript
{
    PrepareAuraScript(spell_gen_burning_depths_necrolyte_image);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ static_cast<uint32>(spellInfo->Effects[EFFECT_2].CalcValue()) });
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), uint32(GetSpellInfo()->Effects[EFFECT_2].CalcValue()));
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(uint32(GetSpellInfo()->Effects[EFFECT_2].CalcValue()), GetCasterGUID());
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_gen_burning_depths_necrolyte_image::HandleApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_gen_burning_depths_necrolyte_image::HandleRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
    }
};

enum CannibalizeSpells
{
    SPELL_CANNIBALIZE_TRIGGERED = 20578
};

class spell_gen_cannibalize : public SpellScript
{
    PrepareSpellScript(spell_gen_cannibalize);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CANNIBALIZE_TRIGGERED });
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
        GetCaster()->CastSpell(GetCaster(), SPELL_CANNIBALIZE_TRIGGERED, false);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_gen_cannibalize::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnCheckCast += SpellCheckCastFn(spell_gen_cannibalize::CheckIfCorpseNear);
    }
};

// 45524 Chains of Ice
// 66020 Chains of Ice
class spell_gen_chains_of_ice : public AuraScript
{
    PrepareAuraScript(spell_gen_chains_of_ice);

    void UpdatePeriodic(AuraEffect* aurEff)
    {
        // Get 0 effect aura
        AuraEffect* slow = GetAura()->GetEffect(EFFECT_0);
        if (!slow)
            return;

        int32 newAmount = std::min<int32>(slow->GetAmount() + aurEff->GetAmount(), 0);
        slow->ChangeAmount(newAmount);
    }

    void Register() override
    {
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_gen_chains_of_ice::UpdatePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

enum ChaosBlast
{
    SPELL_CHAOS_BLAST   = 37675
};

class spell_gen_chaos_blast : public SpellScript
{
    PrepareSpellScript(spell_gen_chaos_blast);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CHAOS_BLAST });
    }
    void HandleDummy(SpellEffIndex /* effIndex */)
    {
        int32 basepoints0 = 100;
        Unit* caster = GetCaster();
        if (Unit* target = GetHitUnit())
        {
            CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
            args.AddSpellBP0(basepoints0);
            caster->CastSpell(target, SPELL_CHAOS_BLAST, args);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_chaos_blast::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum ChokingVines
{
    SPELL_CHOKING_WOUND = 35247
};

// 35244 - Choking Vines
class spell_gen_choking_vines : public AuraScript
{
    PrepareAuraScript(spell_gen_choking_vines);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CHOKING_WOUND });
    }

    void HandleChoke(AuraEffect const* /*aurEff*/)
    {
        if (GetStackAmount() != GetSpellInfo()->StackAmount)
            return;

        GetTarget()->CastSpell(nullptr, SPELL_CHOKING_WOUND, true);
        Remove();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_choking_vines::HandleChoke, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 8129 - Mana Burn
class spell_gen_clear_fear_poly : public SpellScript
{
    PrepareSpellScript(spell_gen_clear_fear_poly);

    void HandleAfterHit()
    {
        if (Unit* unitTarget = GetHitUnit())
            unitTarget->RemoveAurasWithMechanic((1 << MECHANIC_FEAR) | (1 << MECHANIC_POLYMORPH));
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_gen_clear_fear_poly::HandleAfterHit);
    }
};

class spell_gen_clone : public SpellScript
{
    PrepareSpellScript(spell_gen_clone);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetHitUnit()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_clone::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectHitTarget += SpellEffectFn(spell_gen_clone::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum CloneWeaponSpells
{
    SPELL_COPY_WEAPON_AURA       = 41054,
    SPELL_COPY_WEAPON_2_AURA     = 63418,
    SPELL_COPY_WEAPON_3_AURA     = 69893,

    SPELL_COPY_OFFHAND_AURA      = 45205,
    SPELL_COPY_OFFHAND_2_AURA    = 69896,

    SPELL_COPY_RANGED_AURA       = 57594
};

class spell_gen_clone_weapon : public SpellScript
{
    PrepareSpellScript(spell_gen_clone_weapon);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetHitUnit()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_clone_weapon::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_gen_clone_weapon_aura : public AuraScript
{
    PrepareAuraScript(spell_gen_clone_weapon_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_COPY_WEAPON_AURA,
            SPELL_COPY_WEAPON_2_AURA,
            SPELL_COPY_WEAPON_3_AURA,
            SPELL_COPY_OFFHAND_AURA,
            SPELL_COPY_OFFHAND_2_AURA,
            SPELL_COPY_RANGED_AURA
        });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();
        if (!caster)
            return;

        switch (GetSpellInfo()->Id)
        {
            case SPELL_COPY_WEAPON_AURA:
            case SPELL_COPY_WEAPON_2_AURA:
            case SPELL_COPY_WEAPON_3_AURA:
            {
                prevItem = target->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID);

                if (Player* player = caster->ToPlayer())
                {
                    if (Item* mainItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND))
                        target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, mainItem->GetEntry());
                }
                else
                    target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, caster->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID));
                break;
            }
            case SPELL_COPY_OFFHAND_AURA:
            case SPELL_COPY_OFFHAND_2_AURA:
            {
                prevItem = target->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1);

                if (Player* player = caster->ToPlayer())
                {
                    if (Item* offItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND))
                        target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, offItem->GetEntry());
                }
                else
                    target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, caster->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1));
                break;
            }
            case SPELL_COPY_RANGED_AURA:
            {
                prevItem = target->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2);

                if (Player* player = caster->ToPlayer())
                {
                    if (Item* rangedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED))
                        target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, rangedItem->GetEntry());
                }
                else
                    target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, caster->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2));
                break;
            }
            default:
                break;
        }
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        switch (GetSpellInfo()->Id)
        {
            case SPELL_COPY_WEAPON_AURA:
            case SPELL_COPY_WEAPON_2_AURA:
            case SPELL_COPY_WEAPON_3_AURA:
                target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, prevItem);
                break;
            case SPELL_COPY_OFFHAND_AURA:
            case SPELL_COPY_OFFHAND_2_AURA:
                target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, prevItem);
                break;
            case SPELL_COPY_RANGED_AURA:
                target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, prevItem);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_gen_clone_weapon_aura::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        OnEffectRemove += AuraEffectRemoveFn(spell_gen_clone_weapon_aura::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }

    uint32 prevItem = 0;
};

class spell_gen_count_pct_from_max_hp : public SpellScriptLoader
{
    public:
        spell_gen_count_pct_from_max_hp(char const* name, int32 damagePct = 0) : SpellScriptLoader(name), _damagePct(damagePct) { }

        class spell_gen_count_pct_from_max_hp_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gen_count_pct_from_max_hp_SpellScript);

        public:
            spell_gen_count_pct_from_max_hp_SpellScript(int32 damagePct) : SpellScript(), _damagePct(damagePct) { }

            void RecalculateDamage()
            {
                if (!_damagePct)
                    _damagePct = GetHitDamage();

                SetHitDamage(GetHitUnit()->CountPctFromMaxHealth(_damagePct));
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_gen_count_pct_from_max_hp_SpellScript::RecalculateDamage);
            }

        private:
            int32 _damagePct;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gen_count_pct_from_max_hp_SpellScript(_damagePct);
        }

    private:
        int32 _damagePct;
};

// 63845 - Create Lance
enum CreateLanceSpells
{
    SPELL_CREATE_LANCE_ALLIANCE = 63914,
    SPELL_CREATE_LANCE_HORDE    = 63919
};

class spell_gen_create_lance : public SpellScript
{
    PrepareSpellScript(spell_gen_create_lance);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_CREATE_LANCE_ALLIANCE,
            SPELL_CREATE_LANCE_HORDE
        });
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        if (Player* target = GetHitPlayer())
        {
            if (target->GetTeam() == ALLIANCE)
                GetCaster()->CastSpell(target, SPELL_CREATE_LANCE_ALLIANCE, true);
            else
                GetCaster()->CastSpell(target, SPELL_CREATE_LANCE_HORDE, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_create_lance::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_gen_creature_permanent_feign_death : public AuraScript
{
    PrepareAuraScript(spell_gen_creature_permanent_feign_death);

    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
        target->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);

        if (Creature* creature = target->ToCreature())
            creature->SetReactState(REACT_PASSIVE);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
        target->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);

        if (Creature* creature = target->ToCreature())
            creature->InitializeReactState();
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_gen_creature_permanent_feign_death::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_gen_creature_permanent_feign_death::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

enum DalaranDisguiseSpells
{
    SPELL_SUNREAVER_DISGUISE_TRIGGER       = 69672,
    SPELL_SUNREAVER_DISGUISE_FEMALE        = 70973,
    SPELL_SUNREAVER_DISGUISE_MALE          = 70974,

    SPELL_SILVER_COVENANT_DISGUISE_TRIGGER = 69673,
    SPELL_SILVER_COVENANT_DISGUISE_FEMALE  = 70971,
    SPELL_SILVER_COVENANT_DISGUISE_MALE    = 70972
};

class spell_gen_dalaran_disguise : public SpellScriptLoader
{
    public:
        spell_gen_dalaran_disguise(char const* name) : SpellScriptLoader(name) { }

        class spell_gen_dalaran_disguise_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gen_dalaran_disguise_SpellScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                switch (spellInfo->Id)
                {
                    case SPELL_SUNREAVER_DISGUISE_TRIGGER:
                        return ValidateSpellInfo(
                        {
                            SPELL_SUNREAVER_DISGUISE_FEMALE,
                            SPELL_SUNREAVER_DISGUISE_MALE
                        });
                    case SPELL_SILVER_COVENANT_DISGUISE_TRIGGER:
                        return ValidateSpellInfo(
                        {
                            SPELL_SILVER_COVENANT_DISGUISE_FEMALE,
                            SPELL_SILVER_COVENANT_DISGUISE_MALE
                        });
                    default:
                        break;
                }

                return false;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Player* player = GetHitPlayer())
                {
                    uint8 gender = player->GetNativeGender();

                    uint32 spellId = GetSpellInfo()->Id;

                    switch (spellId)
                    {
                        case SPELL_SUNREAVER_DISGUISE_TRIGGER:
                            spellId = gender ? SPELL_SUNREAVER_DISGUISE_FEMALE : SPELL_SUNREAVER_DISGUISE_MALE;
                            break;
                        case SPELL_SILVER_COVENANT_DISGUISE_TRIGGER:
                            spellId = gender ? SPELL_SILVER_COVENANT_DISGUISE_FEMALE : SPELL_SILVER_COVENANT_DISGUISE_MALE;
                            break;
                        default:
                            break;
                    }

                    GetCaster()->CastSpell(player, spellId, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_gen_dalaran_disguise_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gen_dalaran_disguise_SpellScript();
        }
};

enum DamageReductionAura
{
    SPELL_BLESSING_OF_SANCTUARY         = 20911,
    SPELL_GREATER_BLESSING_OF_SANCTUARY = 25899,
    SPELL_RENEWED_HOPE                  = 63944,
    SPELL_VIGILANCE                     = 50720,
    SPELL_DAMAGE_REDUCTION_AURA         = 68066
};

class spell_gen_damage_reduction_aura : public AuraScript
{
    PrepareAuraScript(spell_gen_damage_reduction_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DAMAGE_REDUCTION_AURA });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_DAMAGE_REDUCTION_AURA, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_DAMAGE_REDUCTION_AURA) && !(target->HasAura(SPELL_BLESSING_OF_SANCTUARY) ||
            target->HasAura(SPELL_GREATER_BLESSING_OF_SANCTUARY) ||
            target->HasAura(SPELL_RENEWED_HOPE) ||
            target->HasAura(SPELL_VIGILANCE)))
        {
            target->RemoveAurasDueToSpell(SPELL_DAMAGE_REDUCTION_AURA);
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_gen_damage_reduction_aura::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        OnEffectRemove += AuraEffectRemoveFn(spell_gen_damage_reduction_aura::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

class spell_gen_decay_over_time : public SpellScriptLoader
{
    public:
        spell_gen_decay_over_time(char const* name) : SpellScriptLoader(name) { }

        SpellScript* GetSpellScript() const override
        {
            return new spell_gen_decay_over_time_SpellScript();
        }

    private:
        class spell_gen_decay_over_time_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gen_decay_over_time_SpellScript);

            void ModAuraStack()
            {
                if (Aura* aur = GetHitAura())
                    aur->SetStackAmount(static_cast<uint8>(GetSpellInfo()->StackAmount));
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_gen_decay_over_time_SpellScript::ModAuraStack);
            }
        };

    protected:
        class spell_gen_decay_over_time_AuraScript : public AuraScript
        {
            protected:
                PrepareAuraScript(spell_gen_decay_over_time_AuraScript);

                bool CheckProc(ProcEventInfo& eventInfo)
                {
                    return (eventInfo.GetSpellInfo() == GetSpellInfo());
                }

                void Decay(ProcEventInfo& /*eventInfo*/)
                {
                    PreventDefaultAction();
                    ModStackAmount(-1);
                }

                void Register() override
                {
                    DoCheckProc += AuraCheckProcFn(spell_gen_decay_over_time_AuraScript::CheckProc);
                    OnProc += AuraProcFn(spell_gen_decay_over_time_AuraScript::Decay);
                }

                ~spell_gen_decay_over_time_AuraScript() = default;
        };

        ~spell_gen_decay_over_time() = default;
};

enum FungalDecay
{
    // found in sniffs, there is no duration entry we can possibly use
    AURA_DURATION = 12600
};

// 32065 - Fungal Decay
class spell_gen_decay_over_time_fungal_decay : public spell_gen_decay_over_time
{
    public:
        spell_gen_decay_over_time_fungal_decay() : spell_gen_decay_over_time("spell_gen_decay_over_time_fungal_decay") { }

        class spell_gen_decay_over_time_fungal_decay_AuraScript : public spell_gen_decay_over_time_AuraScript
        {
            PrepareAuraScript(spell_gen_decay_over_time_fungal_decay_AuraScript);

            void ModDuration(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                // only on actual reapply, not on stack decay
                if (GetDuration() == GetMaxDuration())
                {
                    SetMaxDuration(AURA_DURATION);
                    SetDuration(AURA_DURATION);
                }
            }

            void Register() override
            {
                spell_gen_decay_over_time_AuraScript::Register();
                OnEffectApply += AuraEffectApplyFn(spell_gen_decay_over_time_fungal_decay_AuraScript::ModDuration, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_gen_decay_over_time_fungal_decay_AuraScript();
        }
};

// 36659 - Tail Sting
class spell_gen_decay_over_time_tail_sting : public spell_gen_decay_over_time
{
    public:
        spell_gen_decay_over_time_tail_sting() : spell_gen_decay_over_time("spell_gen_decay_over_time_tail_sting") { }

        class spell_gen_decay_over_time_tail_sting_AuraScript : public spell_gen_decay_over_time_AuraScript
        {
            PrepareAuraScript(spell_gen_decay_over_time_tail_sting_AuraScript);
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_gen_decay_over_time_tail_sting_AuraScript();
        }
};

enum DefendVisuals
{
    SPELL_VISUAL_SHIELD_1 = 63130,
    SPELL_VISUAL_SHIELD_2 = 63131,
    SPELL_VISUAL_SHIELD_3 = 63132
};

class spell_gen_defend : public AuraScript
{
    PrepareAuraScript(spell_gen_defend);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_VISUAL_SHIELD_1,
            SPELL_VISUAL_SHIELD_2,
            SPELL_VISUAL_SHIELD_3
        });
    }

    void RefreshVisualShields(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetCaster())
        {
            Unit* target = GetTarget();

            for (uint8 i = 0; i < GetSpellInfo()->StackAmount; ++i)
                target->RemoveAurasDueToSpell(SPELL_VISUAL_SHIELD_1 + i);

            target->CastSpell(target, SPELL_VISUAL_SHIELD_1 + GetAura()->GetStackAmount() - 1, aurEff);
        }
        else
            GetTarget()->RemoveAurasDueToSpell(GetId());
    }

    void RemoveVisualShields(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        for (uint8 i = 0; i < GetSpellInfo()->StackAmount; ++i)
            GetTarget()->RemoveAurasDueToSpell(SPELL_VISUAL_SHIELD_1 + i);
    }

    void RemoveDummyFromDriver(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (TempSummon* vehicle = caster->ToTempSummon())
                if (Unit* rider = vehicle->GetSummonerUnit())
                    rider->RemoveAurasDueToSpell(GetId());
    }

    void Register() override
    {
        SpellInfo const* spell = sSpellMgr->AssertSpellInfo(m_scriptSpellId);

        // Defend spells cast by NPCs (add visuals)
        if (spell->Effects[EFFECT_0].ApplyAuraName == SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN)
        {
            AfterEffectApply += AuraEffectApplyFn(spell_gen_defend::RefreshVisualShields, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            OnEffectRemove += AuraEffectRemoveFn(spell_gen_defend::RemoveVisualShields, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
        }

        // Remove Defend spell from player when he dismounts
        if (spell->Effects[EFFECT_2].ApplyAuraName == SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN)
            OnEffectRemove += AuraEffectRemoveFn(spell_gen_defend::RemoveDummyFromDriver, EFFECT_2, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);

        // Defend spells cast by players (add/remove visuals)
        if (spell->Effects[EFFECT_1].ApplyAuraName == SPELL_AURA_DUMMY)
        {
            AfterEffectApply += AuraEffectApplyFn(spell_gen_defend::RefreshVisualShields, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            OnEffectRemove += AuraEffectRemoveFn(spell_gen_defend::RemoveVisualShields, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
        }
    }
};

class spell_gen_despawn_self : public SpellScript
{
    PrepareSpellScript(spell_gen_despawn_self);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        if (GetSpellInfo()->Effects[effIndex].Effect == SPELL_EFFECT_DUMMY || GetSpellInfo()->Effects[effIndex].Effect == SPELL_EFFECT_SCRIPT_EFFECT)
            GetCaster()->ToCreature()->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_despawn_self::HandleDummy, EFFECT_ALL, SPELL_EFFECT_ANY);
    }
};

enum DivineStormSpell
{
    SPELL_DIVINE_STORM      = 53385,
};

// 70769 Divine Storm!
class spell_gen_divine_storm_cd_reset : public SpellScript
{
    PrepareSpellScript(spell_gen_divine_storm_cd_reset);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DIVINE_STORM });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Player* caster = GetCaster()->ToPlayer();
        if (caster->GetSpellHistory()->HasCooldown(SPELL_DIVINE_STORM))
            caster->GetSpellHistory()->ResetCooldown(SPELL_DIVINE_STORM, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_divine_storm_cd_reset::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_gen_ds_flush_knockback : public SpellScript
{
    PrepareSpellScript(spell_gen_ds_flush_knockback);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        // Here the target is the water spout and determines the position where the player is knocked from
        if (Unit* target = GetHitUnit())
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                float horizontalSpeed = 20.0f + (40.0f - GetCaster()->GetDistance(target));
                float verticalSpeed = 8.0f;
                // This method relies on the Dalaran Sewer map disposition and Water Spout position
                // What we do is knock the player from a position exactly behind him and at the end of the pipe
                player->KnockbackFrom(target->GetPositionX(), player->GetPositionY(), horizontalSpeed, verticalSpeed);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_ds_flush_knockback::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_gen_dungeon_credit : public SpellScript
{
    PrepareSpellScript(spell_gen_dungeon_credit);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void CreditEncounter()
    {
        // This hook is executed for every target, make sure we only credit instance once
        if (_handled)
            return;

        _handled = true;
        Unit* caster = GetCaster();
        if (InstanceScript* instance = caster->GetInstanceScript())
            instance->UpdateEncounterStateForSpellCast(GetSpellInfo()->Id, caster);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_gen_dungeon_credit::CreditEncounter);
    }

    bool _handled = false;
};

enum EluneCandle
{
    // Creatures
    NPC_OMEN                       = 15467,

    // Spells
    SPELL_ELUNE_CANDLE_OMEN_HEAD   = 26622,
    SPELL_ELUNE_CANDLE_OMEN_CHEST  = 26624,
    SPELL_ELUNE_CANDLE_OMEN_HAND_R = 26625,
    SPELL_ELUNE_CANDLE_OMEN_HAND_L = 26649,
    SPELL_ELUNE_CANDLE_NORMAL      = 26636
};

class spell_gen_elune_candle : public SpellScript
{
    PrepareSpellScript(spell_gen_elune_candle);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_ELUNE_CANDLE_OMEN_HEAD,
            SPELL_ELUNE_CANDLE_OMEN_CHEST,
            SPELL_ELUNE_CANDLE_OMEN_HAND_R,
            SPELL_ELUNE_CANDLE_OMEN_HAND_L,
            SPELL_ELUNE_CANDLE_NORMAL
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        uint32 spellId = 0;

        if (GetHitUnit()->GetEntry() == NPC_OMEN)
        {
            switch (urand(0, 3))
            {
                case 0:
                    spellId = SPELL_ELUNE_CANDLE_OMEN_HEAD;
                    break;
                case 1:
                    spellId = SPELL_ELUNE_CANDLE_OMEN_CHEST;
                    break;
                case 2:
                    spellId = SPELL_ELUNE_CANDLE_OMEN_HAND_R;
                    break;
                case 3:
                    spellId = SPELL_ELUNE_CANDLE_OMEN_HAND_L;
                    break;
            }
        }
        else
            spellId = SPELL_ELUNE_CANDLE_NORMAL;

        GetCaster()->CastSpell(GetHitUnit(), spellId, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_elune_candle::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 50051 - Ethereal Pet Aura
enum EtherealPet
{
    NPC_ETHEREAL_SOUL_TRADER        = 27914,

    SAY_STEAL_ESSENCE               = 1,
    SAY_CREATE_TOKEN                = 2,

    SPELL_PROC_TRIGGER_ON_KILL_AURA = 50051,
    SPELL_ETHEREAL_PET_AURA         = 50055,
    SPELL_CREATE_TOKEN              = 50063,
    SPELL_STEAL_ESSENCE_VISUAL      = 50101
};

// 50051 - Ethereal Pet Aura
class spell_ethereal_pet_aura : public AuraScript
{
    PrepareAuraScript(spell_ethereal_pet_aura);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        uint32 levelDiff = std::abs(GetTarget()->GetLevel() - eventInfo.GetProcTarget()->GetLevel());
        return levelDiff <= 9;
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        std::list<Creature*> minionList;
        GetUnitOwner()->GetAllMinionsByEntry(minionList, NPC_ETHEREAL_SOUL_TRADER);
        for (Creature* minion : minionList)
        {
            if (minion->IsAIEnabled())
            {
                minion->AI()->Talk(SAY_STEAL_ESSENCE);
                minion->CastSpell(eventInfo.GetProcTarget(), SPELL_STEAL_ESSENCE_VISUAL);
            }
        }
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_ethereal_pet_aura::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_ethereal_pet_aura::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 50052 - Ethereal Pet onSummon
class spell_ethereal_pet_onsummon : public SpellScript
{
    PrepareSpellScript(spell_ethereal_pet_onsummon);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PROC_TRIGGER_ON_KILL_AURA });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_PROC_TRIGGER_ON_KILL_AURA, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ethereal_pet_onsummon::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 50055 - Ethereal Pet Aura Remove
class spell_ethereal_pet_aura_remove : public SpellScript
{
    PrepareSpellScript(spell_ethereal_pet_aura_remove);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ETHEREAL_PET_AURA });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_ETHEREAL_PET_AURA);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ethereal_pet_aura_remove::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 50101 - Steal Essence Visual
class spell_steal_essence_visual : public AuraScript
{
    PrepareAuraScript(spell_steal_essence_visual);

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            caster->CastSpell(caster, SPELL_CREATE_TOKEN, true);
            if (Creature* soulTrader = caster->ToCreature())
                soulTrader->AI()->Talk(SAY_CREATE_TOKEN);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_steal_essence_visual::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 46642 - 5,000 Gold
class spell_gen_5000_gold : public SpellScript
{
    PrepareSpellScript(spell_gen_5000_gold);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Player* target = GetHitPlayer())
            target->ModifyMoney(5000 * GOLD);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_5000_gold::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum TransporterBackfires
{
    SPELL_TRANSPORTER_MALFUNCTION_POLYMORPH     = 23444,
    SPELL_TRANSPORTER_EVIL_TWIN                 = 23445,
    SPELL_TRANSPORTER_MALFUNCTION_MISS          = 36902
};

class spell_gen_gadgetzan_transporter_backfire : public SpellScript
{
    PrepareSpellScript(spell_gen_gadgetzan_transporter_backfire);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_TRANSPORTER_MALFUNCTION_POLYMORPH,
            SPELL_TRANSPORTER_EVIL_TWIN,
            SPELL_TRANSPORTER_MALFUNCTION_MISS
        });
    }

    void HandleDummy(SpellEffIndex /* effIndex */)
    {
        Unit* caster = GetCaster();
        int32 r = irand(0, 119);
        if (r < 20)                           // Transporter Malfunction - 1/6 polymorph
            caster->CastSpell(caster, SPELL_TRANSPORTER_MALFUNCTION_POLYMORPH, true);
        else if (r < 100)                     // Evil Twin               - 4/6 evil twin
            caster->CastSpell(caster, SPELL_TRANSPORTER_EVIL_TWIN, true);
        else                                    // Transporter Malfunction - 1/6 miss the target
            caster->CastSpell(caster, SPELL_TRANSPORTER_MALFUNCTION_MISS, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_gadgetzan_transporter_backfire::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};


class spell_gen_gift_of_naaru : public AuraScript
{
    PrepareAuraScript(spell_gen_gift_of_naaru);

    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (!GetCaster() || !aurEff->GetTotalTicks())
            return;

        float heal = 0.0f;
        switch (GetSpellInfo()->SpellFamilyName)
        {
            case SPELLFAMILY_MAGE:
            case SPELLFAMILY_WARLOCK:
            case SPELLFAMILY_PRIEST:
                heal = 1.885f * float(GetCaster()->SpellBaseDamageBonusDone(GetSpellInfo()->GetSchoolMask()));
                break;
            case SPELLFAMILY_PALADIN:
            case SPELLFAMILY_SHAMAN:
                heal = std::max(1.885f * float(GetCaster()->SpellBaseDamageBonusDone(GetSpellInfo()->GetSchoolMask())), 1.1f * float(GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK)));
                break;
            case SPELLFAMILY_WARRIOR:
            case SPELLFAMILY_HUNTER:
            case SPELLFAMILY_DEATHKNIGHT:
                heal = 1.1f * float(std::max(GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK), GetCaster()->GetTotalAttackPowerValue(RANGED_ATTACK)));
                break;
            case SPELLFAMILY_GENERIC:
            default:
                break;
        }

        int32 healTick = std::floor(heal / aurEff->GetTotalTicks());
        amount += int32(std::max(healTick, 0));
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_gift_of_naaru::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
    }
};

enum GnomishTransporter
{
    SPELL_TRANSPORTER_SUCCESS                   = 23441,
    SPELL_TRANSPORTER_FAILURE                   = 23446
};

class spell_gen_gnomish_transporter : public SpellScript
{
    PrepareSpellScript(spell_gen_gnomish_transporter);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_TRANSPORTER_SUCCESS,
            SPELL_TRANSPORTER_FAILURE
        });
    }

    void HandleDummy(SpellEffIndex /* effIndex */)
    {
        GetCaster()->CastSpell(GetCaster(), roll_chance_i(50) ? SPELL_TRANSPORTER_SUCCESS : SPELL_TRANSPORTER_FAILURE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_gnomish_transporter::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_gen_lifeblood : public AuraScript
{
    PrepareAuraScript(spell_gen_lifeblood);

    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (!aurEff->GetTotalTicks())
            return;

        if (Unit* owner = GetUnitOwner())
            amount += int32(CalculatePct(owner->GetMaxHealth(), 1.5f / aurEff->GetTotalTicks()));
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_lifeblood::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
    }
};

enum GenericLifebloom
{
    SPELL_HEXLORD_MALACRASS_LIFEBLOOM_FINAL_HEAL        = 43422,
    SPELL_TUR_RAGEPAW_LIFEBLOOM_FINAL_HEAL              = 52552,
    SPELL_CENARION_SCOUT_LIFEBLOOM_FINAL_HEAL           = 53692,
    SPELL_TWISTED_VISAGE_LIFEBLOOM_FINAL_HEAL           = 57763,
    SPELL_FACTION_CHAMPIONS_DRU_LIFEBLOOM_FINAL_HEAL    = 66094
};

class spell_gen_lifebloom : public SpellScriptLoader
{
    public:
        spell_gen_lifebloom(char const* name, uint32 spellId) : SpellScriptLoader(name), _spellId(spellId) { }

        class spell_gen_lifebloom_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_gen_lifebloom_AuraScript);

        public:
            spell_gen_lifebloom_AuraScript(uint32 spellId) : AuraScript(), _spellId(spellId) { }

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ _spellId });
            }

            void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                // final heal only on duration end or dispel
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE && GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
                    return;

                // final heal
                GetTarget()->CastSpell(GetTarget(), _spellId, { aurEff, GetCasterGUID() });
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_gen_lifebloom_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
            }

            uint32 _spellId;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_gen_lifebloom_AuraScript(_spellId);
        }

    private:
        uint32 _spellId;
};

enum Mounts
{
    SPELL_COLD_WEATHER_FLYING           = 54197,

    // Magic Broom
    SPELL_MAGIC_BROOM_60                = 42680,
    SPELL_MAGIC_BROOM_100               = 42683,
    SPELL_MAGIC_BROOM_150               = 42667,
    SPELL_MAGIC_BROOM_280               = 42668,

    // Headless Horseman's Mount
    SPELL_HEADLESS_HORSEMAN_MOUNT_60    = 51621,
    SPELL_HEADLESS_HORSEMAN_MOUNT_100   = 48024,
    SPELL_HEADLESS_HORSEMAN_MOUNT_150   = 51617,
    SPELL_HEADLESS_HORSEMAN_MOUNT_280   = 48023,

    // Winged Steed of the Ebon Blade
    SPELL_WINGED_STEED_150              = 54726,
    SPELL_WINGED_STEED_280              = 54727,

    // Big Blizzard Bear
    SPELL_BIG_BLIZZARD_BEAR_60          = 58997,
    SPELL_BIG_BLIZZARD_BEAR_100         = 58999,

    // Big Love Rocket
    SPELL_BIG_LOVE_ROCKET_0             = 71343,
    SPELL_BIG_LOVE_ROCKET_60            = 71344,
    SPELL_BIG_LOVE_ROCKET_100           = 71345,
    SPELL_BIG_LOVE_ROCKET_150           = 71346,
    SPELL_BIG_LOVE_ROCKET_310           = 71347,

    // Invincible
    SPELL_INVINCIBLE_60                 = 72281,
    SPELL_INVINCIBLE_100                = 72282,
    SPELL_INVINCIBLE_150                = 72283,
    SPELL_INVINCIBLE_310                = 72284,

    // Blazing Hippogryph
    SPELL_BLAZING_HIPPOGRYPH_150        = 74854,
    SPELL_BLAZING_HIPPOGRYPH_280        = 74855,

    // Celestial Steed
    SPELL_CELESTIAL_STEED_60            = 75619,
    SPELL_CELESTIAL_STEED_100           = 75620,
    SPELL_CELESTIAL_STEED_150           = 75617,
    SPELL_CELESTIAL_STEED_280           = 75618,
    SPELL_CELESTIAL_STEED_310           = 76153,

    // X-53 Touring Rocket
    SPELL_X53_TOURING_ROCKET_150        = 75957,
    SPELL_X53_TOURING_ROCKET_280        = 75972,
    SPELL_X53_TOURING_ROCKET_310        = 76154
};

class spell_gen_mount : public SpellScriptLoader
{
    public:
        spell_gen_mount(char const* name, uint32 mount0 = 0, uint32 mount60 = 0, uint32 mount100 = 0, uint32 mount150 = 0, uint32 mount280 = 0, uint32 mount310 = 0) : SpellScriptLoader(name),
            _mount0(mount0), _mount60(mount60), _mount100(mount100), _mount150(mount150), _mount280(mount280), _mount310(mount310) { }

        class spell_gen_mount_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gen_mount_SpellScript);

        public:
            spell_gen_mount_SpellScript(uint32 mount0, uint32 mount60, uint32 mount100, uint32 mount150, uint32 mount280, uint32 mount310) : SpellScript(),
                _mount0(mount0), _mount60(mount60), _mount100(mount100), _mount150(mount150), _mount280(mount280), _mount310(mount310) { }

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                bool result = true;
                if (_mount0)
                    result &= ValidateSpellInfo({ _mount0 });
                if (_mount60)
                    result &= ValidateSpellInfo({ _mount60 });
                if (_mount100)
                    result &= ValidateSpellInfo({ _mount100 });
                if (_mount150)
                    result &= ValidateSpellInfo({ _mount150 });
                if (_mount280)
                    result &= ValidateSpellInfo({ _mount280 });
                if (_mount310)
                    result &= ValidateSpellInfo({ _mount310 });

                return result;
            }

            void HandleMount(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                if (Player* target = GetHitPlayer())
                {
                    // Prevent stacking of mounts and client crashes upon dismounting
                    target->RemoveAurasByType(SPELL_AURA_MOUNTED, ObjectGuid::Empty, GetHitAura());

                    // Triggered spell id dependent on riding skill and zone
                    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(_mount150);
                    uint32 zoneid, areaid;
                    target->GetZoneAndAreaId(zoneid, areaid);
                    bool const canFly = spellInfo && (spellInfo->CheckLocation(target->GetMapId(), zoneid, areaid, target) == SPELL_CAST_OK);

                    uint32 mount = 0;
                    switch (target->GetBaseSkillValue(SKILL_RIDING))
                    {
                        case 0:
                            mount = _mount0;
                            break;
                        case 75:
                            mount = _mount60;
                            break;
                        case 150:
                            mount = _mount100;
                            break;
                        case 225:
                            if (canFly)
                                mount = _mount150;
                            else
                                mount = _mount100;
                            break;
                        case 300:
                            if (canFly)
                            {
                                if (_mount310 && target->Has310Flyer(false))
                                    mount = _mount310;
                                else
                                    mount = _mount280;
                            }
                            else
                                mount = _mount100;
                            break;
                        default:
                            break;
                    }

                    if (mount)
                        target->CastSpell(target, mount, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_gen_mount_SpellScript::HandleMount, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
            }

            uint32 _mount0;
            uint32 _mount60;
            uint32 _mount100;
            uint32 _mount150;
            uint32 _mount280;
            uint32 _mount310;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gen_mount_SpellScript(_mount0, _mount60, _mount100, _mount150, _mount280, _mount310);
        }

    private:
        uint32 _mount0;
        uint32 _mount60;
        uint32 _mount100;
        uint32 _mount150;
        uint32 _mount280;
        uint32 _mount310;
};

/* DOCUMENTATION: Charge spells
    Charge spells can be classified in four groups:

        - Spells on vehicle bar used by players:
            + EFFECT_0: SCRIPT_EFFECT
            + EFFECT_1: TRIGGER_SPELL
            + EFFECT_2: NONE
        - Spells cast by player's mounts triggered by script:
            + EFFECT_0: CHARGE
            + EFFECT_1: TRIGGER_SPELL
            + EFFECT_2: APPLY_AURA
        - Spells cast by players on the target triggered by script:
            + EFFECT_0: SCHOOL_DAMAGE
            + EFFECT_1: SCRIPT_EFFECT
            + EFFECT_2: NONE
        - Spells cast by NPCs on players:
            + EFFECT_0: SCHOOL_DAMAGE
            + EFFECT_1: CHARGE
            + EFFECT_2: SCRIPT_EFFECT

    In the following script we handle the SCRIPT_EFFECT and CHARGE
        - When handling SCRIPT_EFFECT:
            + EFFECT_0: Corresponds to "Spells on vehicle bar used by players" and we make player's mount cast
              the charge effect on the current target ("Spells cast by player's mounts triggered by script").
            + EFFECT_1 and EFFECT_2: Triggered when "Spells cast by player's mounts triggered by script" hits target,
              corresponding to "Spells cast by players on the target triggered by script" and "Spells cast by
              NPCs on players" and we check Defend layers and drop a charge of the first found.
        - When handling CHARGE:
            + Only launched for "Spells cast by player's mounts triggered by script", makes the player cast the
              damaging spell on target with a small chance of failing it.
*/

enum ChargeSpells
{
    SPELL_CHARGE_DAMAGE_8K5             = 62874,
    SPELL_CHARGE_DAMAGE_20K             = 68498,
    SPELL_CHARGE_DAMAGE_45K             = 64591,

    SPELL_CHARGE_CHARGING_EFFECT_8K5    = 63661,
    SPELL_CHARGE_CHARGING_EFFECT_20K_1  = 68284,
    SPELL_CHARGE_CHARGING_EFFECT_20K_2  = 68501,
    SPELL_CHARGE_CHARGING_EFFECT_45K_1  = 62563,
    SPELL_CHARGE_CHARGING_EFFECT_45K_2  = 66481,

    SPELL_CHARGE_TRIGGER_FACTION_MOUNTS = 62960,
    SPELL_CHARGE_TRIGGER_TRIAL_CHAMPION = 68282,

    SPELL_CHARGE_MISS_EFFECT            = 62977,
};

class spell_gen_mounted_charge : public SpellScript
{
    PrepareSpellScript(spell_gen_mounted_charge);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        Unit* target = GetHitUnit();

        switch (effIndex)
        {
            case EFFECT_0: // On spells wich trigger the damaging spell (and also the visual)
            {
                uint32 spellId;

                switch (GetSpellInfo()->Id)
                {
                    case SPELL_CHARGE_TRIGGER_TRIAL_CHAMPION:
                        spellId = SPELL_CHARGE_CHARGING_EFFECT_20K_1;
                        break;
                    case SPELL_CHARGE_TRIGGER_FACTION_MOUNTS:
                        spellId = SPELL_CHARGE_CHARGING_EFFECT_8K5;
                        break;
                    default:
                        return;
                }

                // If target isn't a training dummy there's a chance of failing the charge
                if (!target->IsCharmedOwnedByPlayerOrPlayer() && roll_chance_f(12.5f))
                    spellId = SPELL_CHARGE_MISS_EFFECT;

                if (Unit* vehicle = GetCaster()->GetVehicleBase())
                    vehicle->CastSpell(target, spellId, false);
                else
                    GetCaster()->CastSpell(target, spellId, false);
                break;
            }
            case EFFECT_1: // On damaging spells, for removing a defend layer
            case EFFECT_2:
            {
                Unit::AuraApplicationMap const& auras = target->GetAppliedAuras();
                for (Unit::AuraApplicationMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                {
                    if (Aura* aura = itr->second->GetBase())
                    {
                        SpellInfo const* auraInfo = aura->GetSpellInfo();
                        if (auraInfo && auraInfo->SpellIconID == 2007 && aura->HasEffectType(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN))
                        {
                            aura->ModStackAmount(-1, AURA_REMOVE_BY_ENEMY_SPELL);
                            // Remove dummys from rider (Necessary for updating visual shields)
                            if (Unit* rider = target->GetCharmer())
                                if (Aura* defend = rider->GetAura(aura->GetId()))
                                    defend->ModStackAmount(-1, AURA_REMOVE_BY_ENEMY_SPELL);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }

    void HandleChargeEffect(SpellEffIndex /*effIndex*/)
    {
        uint32 spellId;

        switch (GetSpellInfo()->Id)
        {
            case SPELL_CHARGE_CHARGING_EFFECT_8K5:
                spellId = SPELL_CHARGE_DAMAGE_8K5;
                break;
            case SPELL_CHARGE_CHARGING_EFFECT_20K_1:
            case SPELL_CHARGE_CHARGING_EFFECT_20K_2:
                spellId = SPELL_CHARGE_DAMAGE_20K;
                break;
            case SPELL_CHARGE_CHARGING_EFFECT_45K_1:
            case SPELL_CHARGE_CHARGING_EFFECT_45K_2:
                spellId = SPELL_CHARGE_DAMAGE_45K;
                break;
            default:
                return;
        }

        if (Unit* rider = GetCaster()->GetCharmer())
            rider->CastSpell(GetHitUnit(), spellId, false);
        else
            GetCaster()->CastSpell(GetHitUnit(), spellId, false);
    }

    void Register() override
    {
        SpellInfo const* spell = sSpellMgr->AssertSpellInfo(m_scriptSpellId);

        if (spell->HasEffect(SPELL_EFFECT_SCRIPT_EFFECT))
            OnEffectHitTarget += SpellEffectFn(spell_gen_mounted_charge::HandleScriptEffect, EFFECT_FIRST_FOUND, SPELL_EFFECT_SCRIPT_EFFECT);

        if (spell->Effects[EFFECT_0].Effect == SPELL_EFFECT_CHARGE)
            OnEffectHitTarget += SpellEffectFn(spell_gen_mounted_charge::HandleChargeEffect, EFFECT_0, SPELL_EFFECT_CHARGE);
    }
};

enum MossCoveredFeet
{
    SPELL_FALL_DOWN = 6869
};

// 6870 Moss Covered Feet
// 31399 Moss Covered Feet
class spell_gen_moss_covered_feet : public AuraScript
{
    PrepareAuraScript(spell_gen_moss_covered_feet);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FALL_DOWN });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetActionTarget()->CastSpell(nullptr, SPELL_FALL_DOWN, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_gen_moss_covered_feet::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 46284 - Negative Energy Periodic
class spell_gen_negative_energy_periodic : public AuraScript
{
    PrepareAuraScript(spell_gen_negative_energy_periodic);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->Effects[EFFECT_0].TriggerSpell });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellMod(SPELLVALUE_MAX_TARGETS, aurEff->GetTickNumber() / 10 + 1);
        GetTarget()->CastSpell(nullptr, GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, args);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_negative_energy_periodic::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

enum Netherbloom : uint32
{
    SPELL_NETHERBLOOM_POLLEN_1      = 28703
};

// 28702 - Netherbloom
class spell_gen_netherbloom : public SpellScript
{
    PrepareSpellScript(spell_gen_netherbloom);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        for (uint8 i = 0; i < 5; ++i)
            if (!ValidateSpellInfo({ SPELL_NETHERBLOOM_POLLEN_1 + i }))
                return false;

        return true;
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        if (Unit* target = GetHitUnit())
        {
            // 25% chance of casting a random buff
            if (roll_chance_i(75))
                return;

            // triggered spells are 28703 to 28707
            // Note: some sources say, that there was the possibility of
            //       receiving a debuff. However, this seems to be removed by a patch.

            // don't overwrite an existing aura
            for (uint8 i = 0; i < 5; ++i)
                if (target->HasAura(SPELL_NETHERBLOOM_POLLEN_1 + i))
                    return;

            target->CastSpell(target, SPELL_NETHERBLOOM_POLLEN_1 + urand(0, 4), true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_netherbloom::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum NightmareVine
{
    SPELL_NIGHTMARE_POLLEN      = 28721
};

// 28720 - Nightmare Vine
class spell_gen_nightmare_vine : public SpellScript
{
    PrepareSpellScript(spell_gen_nightmare_vine);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_NIGHTMARE_POLLEN });
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        if (Unit* target = GetHitUnit())
        {
            // 25% chance of casting Nightmare Pollen
            if (roll_chance_i(25))
                target->CastSpell(target, SPELL_NIGHTMARE_POLLEN, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_nightmare_vine::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 27746 -  Nitrous Boost
class spell_gen_nitrous_boost : public AuraScript
{
    PrepareAuraScript(spell_gen_nitrous_boost);

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();

        if (GetCaster() && GetTarget()->GetPower(POWER_MANA) >= 10)
            GetTarget()->ModifyPower(POWER_MANA, -10);
        else
            Remove();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_nitrous_boost::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

enum ObsidianArmor
{
    SPELL_GEN_OBSIDIAN_ARMOR_HOLY       = 27536,
    SPELL_GEN_OBSIDIAN_ARMOR_FIRE       = 27533,
    SPELL_GEN_OBSIDIAN_ARMOR_NATURE     = 27538,
    SPELL_GEN_OBSIDIAN_ARMOR_FROST      = 27534,
    SPELL_GEN_OBSIDIAN_ARMOR_SHADOW     = 27535,
    SPELL_GEN_OBSIDIAN_ARMOR_ARCANE     = 27540
};

// 27539 - Obsidian Armor
class spell_gen_obsidian_armor : public AuraScript
{
    PrepareAuraScript(spell_gen_obsidian_armor);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_GEN_OBSIDIAN_ARMOR_HOLY,
            SPELL_GEN_OBSIDIAN_ARMOR_FIRE,
            SPELL_GEN_OBSIDIAN_ARMOR_NATURE,
            SPELL_GEN_OBSIDIAN_ARMOR_FROST,
            SPELL_GEN_OBSIDIAN_ARMOR_SHADOW,
            SPELL_GEN_OBSIDIAN_ARMOR_ARCANE
        });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetSpellInfo())
            return false;

        if (GetFirstSchoolInMask(eventInfo.GetSchoolMask()) == SPELL_SCHOOL_NORMAL)
            return false;

        return true;
    }

    void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        uint32 spellId = 0;
        switch (GetFirstSchoolInMask(eventInfo.GetSchoolMask()))
        {
            case SPELL_SCHOOL_HOLY:
                spellId = SPELL_GEN_OBSIDIAN_ARMOR_HOLY;
                break;
            case SPELL_SCHOOL_FIRE:
                spellId = SPELL_GEN_OBSIDIAN_ARMOR_FIRE;
                break;
            case SPELL_SCHOOL_NATURE:
                spellId = SPELL_GEN_OBSIDIAN_ARMOR_NATURE;
                break;
            case SPELL_SCHOOL_FROST:
                spellId = SPELL_GEN_OBSIDIAN_ARMOR_FROST;
                break;
            case SPELL_SCHOOL_SHADOW:
                spellId = SPELL_GEN_OBSIDIAN_ARMOR_SHADOW;
                break;
            case SPELL_SCHOOL_ARCANE:
                spellId = SPELL_GEN_OBSIDIAN_ARMOR_ARCANE;
                break;
            default:
                return;
        }
        GetTarget()->CastSpell(GetTarget(), spellId, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_gen_obsidian_armor::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_gen_obsidian_armor::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 55342 Mirror Image
class spell_gen_one_tick_dummy : public AuraScript
{
    PrepareAuraScript(spell_gen_one_tick_dummy);

    void DisablePeriodic(AuraEffect* aurEff)
    {
        aurEff->SetPeriodic(false);
    }

    void Register() override
    {
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_gen_one_tick_dummy::DisablePeriodic, EFFECT_FIRST_FOUND, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_gen_oracle_wolvar_reputation : public SpellScript
{
    PrepareSpellScript(spell_gen_oracle_wolvar_reputation);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        Player* player = GetCaster()->ToPlayer();
        uint32 factionId = GetSpellInfo()->Effects[effIndex].CalcValue();
        int32  repChange = GetSpellInfo()->Effects[EFFECT_1].CalcValue();

        FactionEntry const* factionEntry = sFactionStore.LookupEntry(factionId);
        if (!factionEntry)
            return;

        // Set rep to baserep + basepoints (expecting spillover for oposite faction -> become hated)
        // Not when player already has equal or higher rep with this faction
        if (player->GetReputationMgr().GetReputation(factionEntry) < repChange)
            player->GetReputationMgr().SetReputation(factionEntry, repChange);

        // EFFECT_INDEX_2 most likely update at war state, we already handle this in SetReputation
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_gen_oracle_wolvar_reputation::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum OrcDisguiseSpells
{
    SPELL_ORC_DISGUISE_TRIGGER       = 45759,
    SPELL_ORC_DISGUISE_MALE          = 45760,
    SPELL_ORC_DISGUISE_FEMALE        = 45762
};

class spell_gen_orc_disguise : public SpellScript
{
    PrepareSpellScript(spell_gen_orc_disguise);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_ORC_DISGUISE_TRIGGER,
            SPELL_ORC_DISGUISE_MALE,
            SPELL_ORC_DISGUISE_FEMALE
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Player* target = GetHitPlayer())
        {
            uint8 gender = target->GetNativeGender();
            if (!gender)
                caster->CastSpell(target, SPELL_ORC_DISGUISE_MALE, true);
            else
                caster->CastSpell(target, SPELL_ORC_DISGUISE_FEMALE, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_orc_disguise::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum ParalyticPoison
{
    SPELL_PARALYSIS = 35202
};

// 35201 - Paralytic Poison
class spell_gen_paralytic_poison : public AuraScript
{
    PrepareAuraScript(spell_gen_paralytic_poison);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PARALYSIS });
    }

    void HandleStun(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        GetTarget()->CastSpell(nullptr, SPELL_PARALYSIS, aurEff);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_gen_paralytic_poison::HandleStun, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_gen_proc_below_pct_damaged : public SpellScriptLoader
{
    public:
        spell_gen_proc_below_pct_damaged(char const* name) : SpellScriptLoader(name) { }

        class spell_gen_proc_below_pct_damaged_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_gen_proc_below_pct_damaged_AuraScript);

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return false;

                int32 pct = GetSpellInfo()->Effects[EFFECT_0].CalcValue();

                if (eventInfo.GetActionTarget()->HealthBelowPctDamaged(pct, damageInfo->GetDamage()))
                    return true;

                return false;
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_gen_proc_below_pct_damaged_AuraScript::CheckProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_gen_proc_below_pct_damaged_AuraScript();
        }
};

class spell_gen_proc_charge_drop_only : public AuraScript
{
    PrepareAuraScript(spell_gen_proc_charge_drop_only);

    void HandleChargeDrop(ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_gen_proc_charge_drop_only::HandleChargeDrop);
    }
};

enum ParachuteSpells
{
    SPELL_PARACHUTE         = 45472,
    SPELL_PARACHUTE_BUFF    = 44795,
};

// 45472 Parachute
class spell_gen_parachute : public AuraScript
{
    PrepareAuraScript(spell_gen_parachute);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PARACHUTE,
            SPELL_PARACHUTE_BUFF
        });
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Player* target = GetTarget()->ToPlayer())
            if (target->IsFalling())
            {
                target->RemoveAurasDueToSpell(SPELL_PARACHUTE);
                target->CastSpell(target, SPELL_PARACHUTE_BUFF, true);
            }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_parachute::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

enum PetSummoned
{
    NPC_DOOMGUARD       = 11859,
    NPC_INFERNAL        = 89,
    NPC_IMP             = 416
};

class spell_gen_pet_summoned : public SpellScript
{
    PrepareSpellScript(spell_gen_pet_summoned);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Player* player = GetCaster()->ToPlayer();
        if (player->GetLastPetNumber())
        {
            PetType newPetType = (player->GetClass() == CLASS_HUNTER) ? HUNTER_PET : SUMMON_PET;
            Pet* newPet = new Pet(player, newPetType);
            if (newPet->LoadPetFromDB(player, 0, player->GetLastPetNumber(), true))
            {
                // revive the pet if it is dead
                if (newPet->getDeathState() == DEAD)
                    newPet->setDeathState(ALIVE);

                newPet->SetFullHealth();
                newPet->SetPower(newPet->GetPowerType(), newPet->GetMaxPower(newPet->GetPowerType()));

                switch (newPet->GetEntry())
                {
                    case NPC_DOOMGUARD:
                    case NPC_INFERNAL:
                        newPet->SetEntry(NPC_IMP);
                        break;
                    default:
                        break;
                }
            }
            else
                delete newPet;
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_pet_summoned::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum ProfessionResearch
{
    SPELL_NORTHREND_INSCRIPTION_RESEARCH = 61177
};

class spell_gen_profession_research : public SpellScript
{
    PrepareSpellScript(spell_gen_profession_research);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    SpellCastResult CheckRequirement()
    {
        Player* player = GetCaster()->ToPlayer();

        if (HasDiscoveredAllSpells(GetSpellInfo()->Id, player))
        {
            SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_NOTHING_TO_DISCOVER);
            return SPELL_FAILED_CUSTOM_ERROR;
        }

        return SPELL_CAST_OK;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Player* caster = GetCaster()->ToPlayer();
        uint32 spellId = GetSpellInfo()->Id;

        // Learn random explicit discovery recipe (if any)
        // Players will now learn 3 recipes the very first time they perform Northrend Inscription Research (3.3.0 patch notes)
        if (spellId == SPELL_NORTHREND_INSCRIPTION_RESEARCH && !HasDiscoveredAnySpell(spellId, caster))
            for (int i = 0; i < 2; ++i)
                if (uint32 discoveredSpellId = GetExplicitDiscoverySpell(spellId, caster))
                    caster->LearnSpell(discoveredSpellId, false);

        if (uint32 discoveredSpellId = GetExplicitDiscoverySpell(spellId, caster))
            caster->LearnSpell(discoveredSpellId, false);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_gen_profession_research::CheckRequirement);
        OnEffectHitTarget += SpellEffectFn(spell_gen_profession_research::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_gen_remove_flight_auras : public SpellScript
{
    PrepareSpellScript(spell_gen_remove_flight_auras);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            target->RemoveAurasByType(SPELL_AURA_FLY);
            target->RemoveAurasByType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_remove_flight_auras::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 20589 - Escape artist
// 30918 - Improved Sprint
class spell_gen_remove_impairing_auras : public SpellScript
{
    PrepareSpellScript(spell_gen_remove_impairing_auras);

    void HandleScriptEffect(SpellEffIndex /* effIndex */)
    {
        GetHitUnit()->RemoveMovementImpairingAuras(true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_remove_impairing_auras::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 23493 - Restoration
// 24379 - Restoration
class spell_gen_restoration : public AuraScript
{
    PrepareAuraScript(spell_gen_restoration);

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();

        Unit* caster = GetCaster();
        if (!caster)
            return;

        int32 heal = caster->CountPctFromMaxHealth(10);
        HealInfo healInfo(caster, GetTarget(), heal, GetSpellInfo(), GetSpellInfo()->GetSchoolMask());
        caster->HealBySpell(healInfo);

        /// @todo: should proc other auras?
        if (int32 mana = caster->GetMaxPower(POWER_MANA))
        {
            mana /= 10;
            caster->EnergizeBySpell(caster, GetId(), mana, POWER_MANA);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_restoration::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 38772 Grievous Wound
// 43937 Grievous Wound
// 62331 Impale
// 62418 Impale
class spell_gen_remove_on_health_pct : public AuraScript
{
    PrepareAuraScript(spell_gen_remove_on_health_pct);

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        // they apply damage so no need to check for ticks here

        if (GetTarget()->HealthAbovePct(GetSpellInfo()->Effects[EFFECT_1].CalcValue()))
        {
            Remove(AURA_REMOVE_BY_ENEMY_SPELL);
            PreventDefaultAction();
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_remove_on_health_pct::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 31956 Grievous Wound
// 38801 Grievous Wound
// 43093 Grievous Throw
// 58517 Grievous Wound
// 59262 Grievous Wound
class spell_gen_remove_on_full_health : public AuraScript
{
    PrepareAuraScript(spell_gen_remove_on_full_health);

    void PeriodicTick(AuraEffect const* aurEff)
    {
        // if it has only periodic effect, allow 1 tick
        bool onlyEffect = !GetSpellInfo()->Effects[EFFECT_1].IsEffect() && !GetSpellInfo()->Effects[EFFECT_2].IsEffect();
        if (onlyEffect && aurEff->GetTickNumber() <= 1)
            return;

        if (GetTarget()->IsFullHealth())
        {
            Remove(AURA_REMOVE_BY_ENEMY_SPELL);
            PreventDefaultAction();
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_remove_on_full_health::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 70292 - Glacial Strike
// 71316 - Glacial Strike
// 71317 - Glacial Strike
class spell_gen_remove_on_full_health_pct : public AuraScript
{
    PrepareAuraScript(spell_gen_remove_on_full_health_pct);

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        // they apply damage so no need to check for ticks here

        if (GetTarget()->IsFullHealth())
        {
            Remove(AURA_REMOVE_BY_ENEMY_SPELL);
            PreventDefaultAction();
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_remove_on_full_health_pct::PeriodicTick, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
    }
};

enum Replenishment
{
    SPELL_REPLENISHMENT             = 57669,
    SPELL_INFINITE_REPLENISHMENT    = 61782
};

class ReplenishmentCheck
{
public:
    bool operator()(WorldObject* obj) const
    {
        if (Unit* target = obj->ToUnit())
            return target->GetPowerType() != POWER_MANA;

        return true;
    }
};

class spell_gen_replenishment : public SpellScript
{
    PrepareSpellScript(spell_gen_replenishment);

    void RemoveInvalidTargets(std::list<WorldObject*>& targets)
    {
        // In arenas Replenishment may only affect the caster
        if (Player* caster = GetCaster()->ToPlayer())
        {
            if (caster->InArena())
            {
                targets.clear();
                targets.push_back(caster);
                return;
            }
        }

        targets.remove_if(ReplenishmentCheck());

        uint8 const maxTargets = 10;

        if (targets.size() > maxTargets)
        {
            targets.sort(Trinity::PowerPctOrderPred(POWER_MANA));
            targets.resize(maxTargets);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gen_replenishment::RemoveInvalidTargets, EFFECT_ALL, TARGET_UNIT_CASTER_AREA_RAID);
    }
};

class spell_gen_replenishment_aura : public AuraScript
{
    PrepareAuraScript(spell_gen_replenishment_aura);

    bool Load() override
    {
        return GetUnitOwner()->GetPowerType() == POWER_MANA;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        switch (GetSpellInfo()->Id)
        {
            case SPELL_REPLENISHMENT:
                amount = GetUnitOwner()->GetMaxPower(POWER_MANA) * 0.002f;
                break;
            case SPELL_INFINITE_REPLENISHMENT:
                amount = GetUnitOwner()->GetMaxPower(POWER_MANA) * 0.0025f;
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_replenishment_aura::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
    }
};

enum SeaforiumSpells
{
    SPELL_PLANT_CHARGES_CREDIT_ACHIEVEMENT  = 60937
};

class spell_gen_seaforium_blast : public SpellScript
{
    PrepareSpellScript(spell_gen_seaforium_blast);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PLANT_CHARGES_CREDIT_ACHIEVEMENT });
    }

    bool Load() override
    {
        return GetGObjCaster()->GetOwnerGUID().IsPlayer();
    }

    void AchievementCredit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* owner = GetGObjCaster()->GetOwner())
            if (GameObject* go = GetHitGObj())
                if (go->GetGOInfo()->type == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
                    owner->CastSpell(nullptr, SPELL_PLANT_CHARGES_CREDIT_ACHIEVEMENT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_seaforium_blast::AchievementCredit, EFFECT_1, SPELL_EFFECT_GAMEOBJECT_DAMAGE);
    }
};

enum SpectatorCheerTrigger
{
    EMOTE_ONE_SHOT_CHEER        = 4,
    EMOTE_ONE_SHOT_EXCLAMATION  = 5,
    EMOTE_ONE_SHOT_APPLAUD      = 21
};

uint8 const EmoteArray[3] = { EMOTE_ONE_SHOT_CHEER, EMOTE_ONE_SHOT_EXCLAMATION, EMOTE_ONE_SHOT_APPLAUD };

class spell_gen_spectator_cheer_trigger : public SpellScript
{
    PrepareSpellScript(spell_gen_spectator_cheer_trigger);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (roll_chance_i(40))
            GetCaster()->HandleEmoteCommand(EmoteArray[urand(0, 2)]);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_spectator_cheer_trigger::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_gen_spirit_healer_res : public SpellScript
{
    PrepareSpellScript(spell_gen_spirit_healer_res);

    bool Load() override
    {
        return GetOriginalCaster() && GetOriginalCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleDummy(SpellEffIndex /* effIndex */)
    {
        Player* originalCaster = GetOriginalCaster()->ToPlayer();
        if (Unit* target = GetHitUnit())
        {
            WorldPacket data(SMSG_SPIRIT_HEALER_CONFIRM, 8);
            data << uint64(target->GetGUID());
            originalCaster->SendDirectMessage(&data);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_spirit_healer_res::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum SummonElemental
{
    SPELL_SUMMON_FIRE_ELEMENTAL  = 8985,
    SPELL_SUMMON_EARTH_ELEMENTAL = 19704
};

class spell_gen_summon_elemental : public SpellScriptLoader
{
    public:
        spell_gen_summon_elemental(char const* name, uint32 spellId) : SpellScriptLoader(name), _spellId(spellId) { }

        class spell_gen_summon_elemental_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_gen_summon_elemental_AuraScript);

        public:
            spell_gen_summon_elemental_AuraScript(uint32 spellId) : AuraScript(), _spellId(spellId) { }

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ _spellId });
            }

            void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetCaster())
                    if (Unit* owner = GetCaster()->GetOwner())
                        owner->CastSpell(owner, _spellId, true);
            }

            void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetCaster())
                    if (Unit* owner = GetCaster()->GetOwner())
                        if (owner->GetTypeId() == TYPEID_PLAYER) /// @todo this check is maybe wrong
                            owner->ToPlayer()->RemovePet(nullptr, PET_SAVE_NOT_IN_SLOT, true);
            }

            void Register() override
            {
                 AfterEffectApply += AuraEffectApplyFn(spell_gen_summon_elemental_AuraScript::AfterApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                 AfterEffectRemove += AuraEffectRemoveFn(spell_gen_summon_elemental_AuraScript::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }

            uint32 _spellId;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_gen_summon_elemental_AuraScript(_spellId);
        }

    private:
        uint32 _spellId;
};

enum TournamentMountsSpells
{
    SPELL_LANCE_EQUIPPED     = 62853
};

class spell_gen_summon_tournament_mount : public SpellScript
{
    PrepareSpellScript(spell_gen_summon_tournament_mount);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LANCE_EQUIPPED });
    }

    SpellCastResult CheckIfLanceEquiped()
    {
        if (GetCaster()->IsInDisallowedMountForm())
            GetCaster()->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);

        if (!GetCaster()->HasAura(SPELL_LANCE_EQUIPPED))
        {
            SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_MUST_HAVE_LANCE_EQUIPPED);
            return SPELL_FAILED_CUSTOM_ERROR;
        }

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_gen_summon_tournament_mount::CheckIfLanceEquiped);
    }
};

// 41213, 43416, 69222, 73076 - Throw Shield
class spell_gen_throw_shield : public SpellScript
{
    PrepareSpellScript(spell_gen_throw_shield);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_throw_shield::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum MountedDuelSpells
{
    SPELL_ON_TOURNAMENT_MOUNT = 63034,
    SPELL_MOUNTED_DUEL        = 62875
};

class spell_gen_tournament_duel : public SpellScript
{
    PrepareSpellScript(spell_gen_tournament_duel);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_ON_TOURNAMENT_MOUNT,
            SPELL_MOUNTED_DUEL
        });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* rider = GetCaster()->GetCharmer())
        {
            if (Player* playerTarget = GetHitPlayer())
            {
                if (playerTarget->HasAura(SPELL_ON_TOURNAMENT_MOUNT) && playerTarget->GetVehicleBase())
                    rider->CastSpell(playerTarget, SPELL_MOUNTED_DUEL, true);
            }
            else if (Unit* unitTarget = GetHitUnit())
            {
                if (unitTarget->GetCharmer() && unitTarget->GetCharmer()->GetTypeId() == TYPEID_PLAYER && unitTarget->GetCharmer()->HasAura(SPELL_ON_TOURNAMENT_MOUNT))
                    rider->CastSpell(unitTarget->GetCharmer(), SPELL_MOUNTED_DUEL, true);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_tournament_duel::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_gen_tournament_pennant : public AuraScript
{
    PrepareAuraScript(spell_gen_tournament_pennant);

    bool Load() override
    {
        return GetCaster() && GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleApplyEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (!caster->GetVehicleBase())
                caster->RemoveAurasDueToSpell(GetId());
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_gen_tournament_pennant::HandleApplyEffect, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

enum Teleporting
{
    AREA_VIOLET_CITADEL_SPIRE   = 4637,

    SPELL_TELEPORT_SPIRE_DOWN   = 59316,
    SPELL_TELEPORT_SPIRE_UP     = 59314
};

class spell_gen_teleporting : public SpellScript
{
    PrepareSpellScript(spell_gen_teleporting);

    void HandleScript(SpellEffIndex /* effIndex */)
    {
        Unit* target = GetHitUnit();
        if (target->GetTypeId() != TYPEID_PLAYER)
            return;

        // return from top
        if (target->ToPlayer()->GetAreaId() == AREA_VIOLET_CITADEL_SPIRE)
            target->CastSpell(target, SPELL_TELEPORT_SPIRE_DOWN, true);
            // teleport atop
        else
            target->CastSpell(target, SPELL_TELEPORT_SPIRE_UP, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_teleporting::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum PvPTrinketTriggeredSpells
{
    SPELL_WILL_OF_THE_FORSAKEN_COOLDOWN_TRIGGER         = 72752,
    SPELL_WILL_OF_THE_FORSAKEN_COOLDOWN_TRIGGER_WOTF    = 72757
};

template <uint32 TriggeredSpellId>
class spell_pvp_trinket_wotf_shared_cd : public SpellScriptLoader
{
    public:
        spell_pvp_trinket_wotf_shared_cd(char const* ScriptName) : SpellScriptLoader(ScriptName) { }

        template <uint32 Triggered>
        class spell_pvp_trinket_wotf_shared_cd_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pvp_trinket_wotf_shared_cd_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ Triggered });
            }

            void HandleScript()
            {
                /*
                 * @workaround: PendingCast flag normally means 'triggered' spell, however
                 * if the spell is cast triggered, the core won't send SMSG_SPELL_GO packet
                 * so client never registers the cooldown (see Spell::IsNeedSendToClient)
                 *
                 * ServerToClient: SMSG_SPELL_GO (0x0132) Length: 42 ConnIdx: 0 Time: 07/19/2010 02:32:35.000 Number: 362675
                 * Caster GUID: Full: Player
                 * Caster Unit GUID: Full: Player
                 * Cast Count: 0
                 * Spell ID: 72752 (72752)
                 * Cast Flags: PendingCast, Unknown3, Unknown7 (265)
                 * Time: 3901468825
                 * Hit Count: 1
                 * [0] Hit GUID: Player
                 * Miss Count: 0
                 * Target Flags: Unit (2)
                 * Target GUID: 0x0
                */

                // Spell flags need further research, until then just cast not triggered
                GetCaster()->CastSpell(nullptr, Triggered, false);
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_pvp_trinket_wotf_shared_cd_SpellScript::HandleScript);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pvp_trinket_wotf_shared_cd_SpellScript<TriggeredSpellId>();
        }
};

enum FriendOrFowl
{
    SPELL_TURKEY_VENGEANCE      = 25285
};

class spell_gen_turkey_marker : public AuraScript
{
    PrepareAuraScript(spell_gen_turkey_marker);

    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        // store stack apply times, so we can pop them while they expire
        _applyTimes.push_back(GameTime::GetGameTimeMS());
        Unit* target = GetTarget();

        // on stack 15 cast the achievement crediting spell
        if (GetStackAmount() >= 15)
            target->CastSpell(target, SPELL_TURKEY_VENGEANCE, { aurEff, GetCasterGUID() });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (_applyTimes.empty())
            return;

        // pop stack if it expired for us
        if (_applyTimes.front() + GetMaxDuration() < GameTime::GetGameTimeMS())
            ModStackAmount(-1, AURA_REMOVE_BY_EXPIRE);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_gen_turkey_marker::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_turkey_marker::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

    std::list<uint32> _applyTimes;
};

enum FoamSword
{
    ITEM_FOAM_SWORD_GREEN   = 45061,
    ITEM_FOAM_SWORD_PINK    = 45176,
    ITEM_FOAM_SWORD_BLUE    = 45177,
    ITEM_FOAM_SWORD_RED     = 45178,
    ITEM_FOAM_SWORD_YELLOW  = 45179
};

class spell_gen_upper_deck_create_foam_sword : public SpellScript
{
    PrepareSpellScript(spell_gen_upper_deck_create_foam_sword);

    void HandleScript(SpellEffIndex effIndex)
    {
        if (Player* player = GetHitPlayer())
        {
            static uint32 const itemId[5] = { ITEM_FOAM_SWORD_GREEN, ITEM_FOAM_SWORD_PINK, ITEM_FOAM_SWORD_BLUE, ITEM_FOAM_SWORD_RED, ITEM_FOAM_SWORD_YELLOW };
            // player can only have one of these items
            for (uint8 i = 0; i < 5; ++i)
            {
                if (player->HasItemCount(itemId[i], 1, true))
                    return;
            }

            CreateItem(effIndex, itemId[urand(0, 4)]);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_upper_deck_create_foam_sword::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum VampiricTouch
{
    SPELL_VAMPIRIC_TOUCH_HEAL   = 52724
};

// 52723 - Vampiric Touch
// 60501 - Vampiric Touch
class spell_gen_vampiric_touch : public AuraScript
{
    PrepareAuraScript(spell_gen_vampiric_touch);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VAMPIRIC_TOUCH_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        Unit* caster = eventInfo.GetActor();
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(damageInfo->GetDamage() / 2);
        caster->CastSpell(caster, SPELL_VAMPIRIC_TOUCH_HEAL, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_gen_vampiric_touch::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

enum VehicleScaling
{
    SPELL_GEAR_SCALING      = 66668
};

class spell_gen_vehicle_scaling : public AuraScript
{
    PrepareAuraScript(spell_gen_vehicle_scaling);

    bool Load() override
    {
        return GetCaster() && GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        Unit* caster = GetCaster();
        float factor;
        uint16 baseItemLevel;

        /// @todo Reserach coeffs for different vehicles
        switch (GetId())
        {
            case SPELL_GEAR_SCALING:
                factor = 1.0f;
                baseItemLevel = 205;
                break;
            default:
                factor = 1.0f;
                baseItemLevel = 170;
                break;
        }

        float avgILvl = caster->ToPlayer()->GetAverageItemLevel();
        if (avgILvl < baseItemLevel)
            return;                     /// @todo Research possibility of scaling down

        amount = uint16((avgILvl - baseItemLevel) * factor);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_vehicle_scaling::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_HEALING_PCT);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_vehicle_scaling::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_vehicle_scaling::CalculateAmount, EFFECT_2, SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT);
    }
};

enum VendorBarkTrigger
{
    NPC_AMPHITHEATER_VENDOR     = 30098,
    SAY_AMPHITHEATER_VENDOR     = 0
};

class spell_gen_vendor_bark_trigger : public SpellScript
{
    PrepareSpellScript(spell_gen_vendor_bark_trigger);

    void HandleDummy(SpellEffIndex /* effIndex */)
    {
        if (Creature* vendor = GetCaster()->ToCreature())
            if (vendor->GetEntry() == NPC_AMPHITHEATER_VENDOR)
                vendor->AI()->Talk(SAY_AMPHITHEATER_VENDOR);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_vendor_bark_trigger::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_gen_wg_water : public SpellScript
{
    PrepareSpellScript(spell_gen_wg_water);

    SpellCastResult CheckCast()
    {
        if (!GetSpellInfo()->CheckTargetCreatureType(GetCaster()))
            return SPELL_FAILED_DONT_REPORT;
        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_gen_wg_water::CheckCast);
    }
};

enum WhisperGulchYoggSaronWhisper
{
    SPELL_YOGG_SARON_WHISPER_DUMMY  = 29072
};

class spell_gen_whisper_gulch_yogg_saron_whisper : public AuraScript
{
    PrepareAuraScript(spell_gen_whisper_gulch_yogg_saron_whisper);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_YOGG_SARON_WHISPER_DUMMY });
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(nullptr, SPELL_YOGG_SARON_WHISPER_DUMMY, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_whisper_gulch_yogg_saron_whisper::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_gen_eject_all_passengers : public SpellScript
{
    PrepareSpellScript(spell_gen_eject_all_passengers);

    void RemoveVehicleAuras()
    {
        if (Vehicle* vehicle = GetHitUnit()->GetVehicleKit())
            vehicle->RemoveAllPassengers();
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_gen_eject_all_passengers::RemoveVehicleAuras);
    }
};

class spell_gen_eject_passenger : public SpellScript
{
    PrepareSpellScript(spell_gen_eject_passenger);

    bool Validate(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Effects[EFFECT_0].CalcValue() < 1)
            return false;
        return true;
    }

    void EjectPassenger(SpellEffIndex /*effIndex*/)
    {
        if (Vehicle* vehicle = GetHitUnit()->GetVehicleKit())
        {
            if (Unit* passenger = vehicle->GetPassenger(GetEffectValue() - 1))
                passenger->ExitVehicle();
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_eject_passenger::EjectPassenger, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum GMFreeze
{
    SPELL_GM_FREEZE = 9454
};

class spell_gen_gm_freeze : public AuraScript
{
    PrepareAuraScript(spell_gen_gm_freeze);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GM_FREEZE });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // Do what was done before to the target in HandleFreezeCommand
        if (Player* player = GetTarget()->ToPlayer())
        {
            // stop combat + make player unattackable + duel stop + stop some spells
            player->SetFaction(FACTION_FRIENDLY);
            player->CombatStop();
            if (player->IsNonMeleeSpellCast(true))
                player->InterruptNonMeleeSpells(true);
            player->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            // if player class = hunter || warlock remove pet if alive
            if ((player->GetClass() == CLASS_HUNTER) || (player->GetClass() == CLASS_WARLOCK))
            {
                if (Pet* pet = player->GetPet())
                {
                    pet->SavePetToDB(PET_SAVE_AS_CURRENT);
                    // not let dismiss dead pet
                    if (pet->IsAlive())
                        player->RemovePet(pet, PET_SAVE_NOT_IN_SLOT);
                }
            }
        }
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // Do what was done before to the target in HandleUnfreezeCommand
        if (Player* player = GetTarget()->ToPlayer())
        {
            // Reset player faction + allow combat + allow duels
            player->SetFactionForRace(player->GetRace());
            player->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            // save player
            player->SaveToDB();
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_gen_gm_freeze::OnApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_gen_gm_freeze::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_gen_stand : public SpellScript
{
    PrepareSpellScript(spell_gen_stand);

    void HandleScript(SpellEffIndex /*eff*/)
    {
        Creature* target = GetHitCreature();
        if (!target)
            return;

        target->SetStandState(UNIT_STAND_STATE_STAND);
        target->HandleEmoteCommand(EMOTE_STATE_NONE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_stand::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum RequiredMixologySpells
{
    SPELL_MIXOLOGY                      = 53042,
    // Flasks
    SPELL_FLASK_OF_THE_FROST_WYRM       = 53755,
    SPELL_FLASK_OF_STONEBLOOD           = 53758,
    SPELL_FLASK_OF_ENDLESS_RAGE         = 53760,
    SPELL_FLASK_OF_PURE_MOJO            = 54212,
    SPELL_LESSER_FLASK_OF_RESISTANCE    = 62380,
    SPELL_LESSER_FLASK_OF_TOUGHNESS     = 53752,
    SPELL_FLASK_OF_BLINDING_LIGHT       = 28521,
    SPELL_FLASK_OF_CHROMATIC_WONDER     = 42735,
    SPELL_FLASK_OF_FORTIFICATION        = 28518,
    SPELL_FLASK_OF_MIGHTY_RESTORATION   = 28519,
    SPELL_FLASK_OF_PURE_DEATH           = 28540,
    SPELL_FLASK_OF_RELENTLESS_ASSAULT   = 28520,
    SPELL_FLASK_OF_CHROMATIC_RESISTANCE = 17629,
    SPELL_FLASK_OF_DISTILLED_WISDOM     = 17627,
    SPELL_FLASK_OF_SUPREME_POWER        = 17628,
    SPELL_FLASK_OF_THE_TITANS           = 17626,
    // Elixirs
    SPELL_ELIXIR_OF_MIGHTY_AGILITY      = 28497,
    SPELL_ELIXIR_OF_ACCURACY            = 60340,
    SPELL_ELIXIR_OF_DEADLY_STRIKES      = 60341,
    SPELL_ELIXIR_OF_MIGHTY_DEFENSE      = 60343,
    SPELL_ELIXIR_OF_EXPERTISE           = 60344,
    SPELL_ELIXIR_OF_ARMOR_PIERCING      = 60345,
    SPELL_ELIXIR_OF_LIGHTNING_SPEED     = 60346,
    SPELL_ELIXIR_OF_MIGHTY_FORTITUDE    = 53751,
    SPELL_ELIXIR_OF_MIGHTY_MAGEBLOOD    = 53764,
    SPELL_ELIXIR_OF_MIGHTY_STRENGTH     = 53748,
    SPELL_ELIXIR_OF_MIGHTY_TOUGHTS      = 60347,
    SPELL_ELIXIR_OF_PROTECTION          = 53763,
    SPELL_ELIXIR_OF_SPIRIT              = 53747,
    SPELL_GURUS_ELIXIR                  = 53749,
    SPELL_SHADOWPOWER_ELIXIR            = 33721,
    SPELL_WRATH_ELIXIR                  = 53746,
    SPELL_ELIXIR_OF_EMPOWERMENT         = 28514,
    SPELL_ELIXIR_OF_MAJOR_MAGEBLOOD     = 28509,
    SPELL_ELIXIR_OF_MAJOR_SHADOW_POWER  = 28503,
    SPELL_ELIXIR_OF_MAJOR_DEFENSE       = 28502,
    SPELL_FEL_STRENGTH_ELIXIR           = 38954,
    SPELL_ELIXIR_OF_IRONSKIN            = 39628,
    SPELL_ELIXIR_OF_MAJOR_AGILITY       = 54494,
    SPELL_ELIXIR_OF_DRAENIC_WISDOM      = 39627,
    SPELL_ELIXIR_OF_MAJOR_FIREPOWER     = 28501,
    SPELL_ELIXIR_OF_MAJOR_FROST_POWER   = 28493,
    SPELL_EARTHEN_ELIXIR                = 39626,
    SPELL_ELIXIR_OF_MASTERY             = 33726,
    SPELL_ELIXIR_OF_HEALING_POWER       = 28491,
    SPELL_ELIXIR_OF_MAJOR_FORTITUDE     = 39625,
    SPELL_ELIXIR_OF_MAJOR_STRENGTH      = 28490,
    SPELL_ADEPTS_ELIXIR                 = 54452,
    SPELL_ONSLAUGHT_ELIXIR              = 33720,
    SPELL_MIGHTY_TROLLS_BLOOD_ELIXIR    = 24361,
    SPELL_GREATER_ARCANE_ELIXIR         = 17539,
    SPELL_ELIXIR_OF_THE_MONGOOSE        = 17538,
    SPELL_ELIXIR_OF_BRUTE_FORCE         = 17537,
    SPELL_ELIXIR_OF_SAGES               = 17535,
    SPELL_ELIXIR_OF_SUPERIOR_DEFENSE    = 11348,
    SPELL_ELIXIR_OF_DEMONSLAYING        = 11406,
    SPELL_ELIXIR_OF_GREATER_FIREPOWER   = 26276,
    SPELL_ELIXIR_OF_SHADOW_POWER        = 11474,
    SPELL_MAGEBLOOD_ELIXIR              = 24363,
    SPELL_ELIXIR_OF_GIANTS              = 11405,
    SPELL_ELIXIR_OF_GREATER_AGILITY     = 11334,
    SPELL_ARCANE_ELIXIR                 = 11390,
    SPELL_ELIXIR_OF_GREATER_INTELLECT   = 11396,
    SPELL_ELIXIR_OF_GREATER_DEFENSE     = 11349,
    SPELL_ELIXIR_OF_FROST_POWER         = 21920,
    SPELL_ELIXIR_OF_AGILITY             = 11328,
    SPELL_MAJOR_TROLLS_BLLOOD_ELIXIR    =  3223,
    SPELL_ELIXIR_OF_FORTITUDE           =  3593,
    SPELL_ELIXIR_OF_OGRES_STRENGTH      =  3164,
    SPELL_ELIXIR_OF_FIREPOWER           =  7844,
    SPELL_ELIXIR_OF_LESSER_AGILITY      =  3160,
    SPELL_ELIXIR_OF_DEFENSE             =  3220,
    SPELL_STRONG_TROLLS_BLOOD_ELIXIR    =  3222,
    SPELL_ELIXIR_OF_MINOR_ACCURACY      = 63729,
    SPELL_ELIXIR_OF_WISDOM              =  3166,
    SPELL_ELIXIR_OF_GIANTH_GROWTH       =  8212,
    SPELL_ELIXIR_OF_MINOR_AGILITY       =  2374,
    SPELL_ELIXIR_OF_MINOR_FORTITUDE     =  2378,
    SPELL_WEAK_TROLLS_BLOOD_ELIXIR      =  3219,
    SPELL_ELIXIR_OF_LIONS_STRENGTH      =  2367,
    SPELL_ELIXIR_OF_MINOR_DEFENSE       =   673
};

class spell_gen_mixology_bonus : public AuraScript
{
    PrepareAuraScript(spell_gen_mixology_bonus);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MIXOLOGY });
    }

    bool Load() override
    {
        return GetCaster() && GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void SetBonusValueForEffect(SpellEffIndex effIndex, int32 value, AuraEffect const* aurEff)
    {
        if (aurEff->GetEffIndex() == uint32(effIndex))
            bonus = value;
    }

    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (GetCaster()->HasAura(SPELL_MIXOLOGY) && GetCaster()->HasSpell(GetSpellInfo()->Effects[EFFECT_0].TriggerSpell))
        {
            switch (GetId())
            {
                case SPELL_WEAK_TROLLS_BLOOD_ELIXIR:
                case SPELL_MAGEBLOOD_ELIXIR:
                    bonus = amount;
                    break;
                case SPELL_ELIXIR_OF_FROST_POWER:
                case SPELL_LESSER_FLASK_OF_TOUGHNESS:
                case SPELL_LESSER_FLASK_OF_RESISTANCE:
                    bonus = CalculatePct(amount, 80);
                    break;
                case SPELL_ELIXIR_OF_MINOR_DEFENSE:
                case SPELL_ELIXIR_OF_LIONS_STRENGTH:
                case SPELL_ELIXIR_OF_MINOR_AGILITY:
                case SPELL_MAJOR_TROLLS_BLLOOD_ELIXIR:
                case SPELL_ELIXIR_OF_SHADOW_POWER:
                case SPELL_ELIXIR_OF_BRUTE_FORCE:
                case SPELL_MIGHTY_TROLLS_BLOOD_ELIXIR:
                case SPELL_ELIXIR_OF_GREATER_FIREPOWER:
                case SPELL_ONSLAUGHT_ELIXIR:
                case SPELL_EARTHEN_ELIXIR:
                case SPELL_ELIXIR_OF_MAJOR_AGILITY:
                case SPELL_FLASK_OF_THE_TITANS:
                case SPELL_FLASK_OF_RELENTLESS_ASSAULT:
                case SPELL_FLASK_OF_STONEBLOOD:
                case SPELL_ELIXIR_OF_MINOR_ACCURACY:
                    bonus = CalculatePct(amount, 50);
                    break;
                case SPELL_ELIXIR_OF_PROTECTION:
                    bonus = 280;
                    break;
                case SPELL_ELIXIR_OF_MAJOR_DEFENSE:
                    bonus = 200;
                    break;
                case SPELL_ELIXIR_OF_GREATER_DEFENSE:
                case SPELL_ELIXIR_OF_SUPERIOR_DEFENSE:
                    bonus = 140;
                    break;
                case SPELL_ELIXIR_OF_FORTITUDE:
                    bonus = 100;
                    break;
                case SPELL_FLASK_OF_ENDLESS_RAGE:
                    bonus = 82;
                    break;
                case SPELL_ELIXIR_OF_DEFENSE:
                    bonus = 70;
                    break;
                case SPELL_ELIXIR_OF_DEMONSLAYING:
                    bonus = 50;
                    break;
                case SPELL_FLASK_OF_THE_FROST_WYRM:
                    bonus = 47;
                    break;
                case SPELL_WRATH_ELIXIR:
                    bonus = 32;
                    break;
                case SPELL_ELIXIR_OF_MAJOR_FROST_POWER:
                case SPELL_ELIXIR_OF_MAJOR_FIREPOWER:
                case SPELL_ELIXIR_OF_MAJOR_SHADOW_POWER:
                    bonus = 29;
                    break;
                case SPELL_ELIXIR_OF_MIGHTY_TOUGHTS:
                    bonus = 27;
                    break;
                case SPELL_FLASK_OF_SUPREME_POWER:
                case SPELL_FLASK_OF_BLINDING_LIGHT:
                case SPELL_FLASK_OF_PURE_DEATH:
                case SPELL_SHADOWPOWER_ELIXIR:
                    bonus = 23;
                    break;
                case SPELL_ELIXIR_OF_MIGHTY_AGILITY:
                case SPELL_FLASK_OF_DISTILLED_WISDOM:
                case SPELL_ELIXIR_OF_SPIRIT:
                case SPELL_ELIXIR_OF_MIGHTY_STRENGTH:
                case SPELL_FLASK_OF_PURE_MOJO:
                case SPELL_ELIXIR_OF_ACCURACY:
                case SPELL_ELIXIR_OF_DEADLY_STRIKES:
                case SPELL_ELIXIR_OF_MIGHTY_DEFENSE:
                case SPELL_ELIXIR_OF_EXPERTISE:
                case SPELL_ELIXIR_OF_ARMOR_PIERCING:
                case SPELL_ELIXIR_OF_LIGHTNING_SPEED:
                    bonus = 20;
                    break;
                case SPELL_FLASK_OF_CHROMATIC_RESISTANCE:
                    bonus = 17;
                    break;
                case SPELL_ELIXIR_OF_MINOR_FORTITUDE:
                case SPELL_ELIXIR_OF_MAJOR_STRENGTH:
                    bonus = 15;
                    break;
                case SPELL_FLASK_OF_MIGHTY_RESTORATION:
                    bonus = 13;
                    break;
                case SPELL_ARCANE_ELIXIR:
                    bonus = 12;
                    break;
                case SPELL_ELIXIR_OF_GREATER_AGILITY:
                case SPELL_ELIXIR_OF_GIANTS:
                    bonus = 11;
                    break;
                case SPELL_ELIXIR_OF_AGILITY:
                case SPELL_ELIXIR_OF_GREATER_INTELLECT:
                case SPELL_ELIXIR_OF_SAGES:
                case SPELL_ELIXIR_OF_IRONSKIN:
                case SPELL_ELIXIR_OF_MIGHTY_MAGEBLOOD:
                    bonus = 10;
                    break;
                case SPELL_ELIXIR_OF_HEALING_POWER:
                    bonus = 9;
                    break;
                case SPELL_ELIXIR_OF_DRAENIC_WISDOM:
                case SPELL_GURUS_ELIXIR:
                    bonus = 8;
                    break;
                case SPELL_ELIXIR_OF_FIREPOWER:
                case SPELL_ELIXIR_OF_MAJOR_MAGEBLOOD:
                case SPELL_ELIXIR_OF_MASTERY:
                    bonus = 6;
                    break;
                case SPELL_ELIXIR_OF_LESSER_AGILITY:
                case SPELL_ELIXIR_OF_OGRES_STRENGTH:
                case SPELL_ELIXIR_OF_WISDOM:
                case SPELL_ELIXIR_OF_THE_MONGOOSE:
                    bonus = 5;
                    break;
                case SPELL_STRONG_TROLLS_BLOOD_ELIXIR:
                case SPELL_FLASK_OF_CHROMATIC_WONDER:
                    bonus = 4;
                    break;
                case SPELL_ELIXIR_OF_EMPOWERMENT:
                    bonus = -10;
                    break;
                case SPELL_ADEPTS_ELIXIR:
                    SetBonusValueForEffect(EFFECT_0, 13, aurEff);
                    SetBonusValueForEffect(EFFECT_1, 13, aurEff);
                    SetBonusValueForEffect(EFFECT_2, 8, aurEff);
                    break;
                case SPELL_ELIXIR_OF_MIGHTY_FORTITUDE:
                    SetBonusValueForEffect(EFFECT_0, 160, aurEff);
                    break;
                case SPELL_ELIXIR_OF_MAJOR_FORTITUDE:
                    SetBonusValueForEffect(EFFECT_0, 116, aurEff);
                    SetBonusValueForEffect(EFFECT_1, 6, aurEff);
                    break;
                case SPELL_FEL_STRENGTH_ELIXIR:
                    SetBonusValueForEffect(EFFECT_0, 40, aurEff);
                    SetBonusValueForEffect(EFFECT_1, 40, aurEff);
                    break;
                case SPELL_FLASK_OF_FORTIFICATION:
                    SetBonusValueForEffect(EFFECT_0, 210, aurEff);
                    SetBonusValueForEffect(EFFECT_1, 5, aurEff);
                    break;
                case SPELL_GREATER_ARCANE_ELIXIR:
                    SetBonusValueForEffect(EFFECT_0, 19, aurEff);
                    SetBonusValueForEffect(EFFECT_1, 19, aurEff);
                    SetBonusValueForEffect(EFFECT_2, 5, aurEff);
                    break;
                case SPELL_ELIXIR_OF_GIANTH_GROWTH:
                    SetBonusValueForEffect(EFFECT_0, 5, aurEff);
                    break;
                default:
                    TC_LOG_ERROR("spells", "SpellId %u couldn't be processed in spell_gen_mixology_bonus", GetId());
                    break;
            }
            amount += bonus;
        }
    }

    int32 bonus = 0;

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_mixology_bonus::CalculateAmount, EFFECT_ALL, SPELL_AURA_ANY);
    }
};

enum LandmineKnockbackAchievement
{
    SPELL_LANDMINE_KNOCKBACK_ACHIEVEMENT = 57064
};

class spell_gen_landmine_knockback_achievement : public SpellScript
{
    PrepareSpellScript(spell_gen_landmine_knockback_achievement);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Player* target = GetHitPlayer())
        {
            Aura const* aura = GetHitAura();
            if (!aura || aura->GetStackAmount() < 10)
                return;

            target->CastSpell(target, SPELL_LANDMINE_KNOCKBACK_ACHIEVEMENT, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_landmine_knockback_achievement::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 34098 - ClearAllDebuffs
class spell_gen_clear_debuffs : public SpellScript
{
    PrepareSpellScript(spell_gen_clear_debuffs);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            target->RemoveOwnedAuras([](Aura const* aura)
            {
                SpellInfo const* spellInfo = aura->GetSpellInfo();
                return !spellInfo->IsPositive() && !spellInfo->IsPassive();
            });
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_clear_debuffs::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum PonySpells
{
    ACHIEV_PONY_UP              = 3736,
    MOUNT_PONY                  = 29736
};

class spell_gen_pony_mount_check : public AuraScript
{
    PrepareAuraScript(spell_gen_pony_mount_check);

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;
        Player* owner = caster->GetOwner()->ToPlayer();
        if (!owner || !owner->HasAchieved(ACHIEV_PONY_UP))
            return;

        if (owner->IsMounted())
        {
            caster->Mount(MOUNT_PONY);
            caster->SetSpeedRate(MOVE_RUN, owner->GetSpeedRate(MOVE_RUN));
        }
        else if (caster->IsMounted())
        {
            caster->Dismount();
            caster->SetSpeedRate(MOVE_RUN, owner->GetSpeedRate(MOVE_RUN));
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_pony_mount_check::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

enum CorruptinPlagueEntrys
{
    NPC_APEXIS_FLAYER       = 22175,
    NPC_SHARD_HIDE_BOAR     = 22180,
    NPC_AETHER_RAY          = 22181,
    SPELL_CORRUPTING_PLAGUE = 40350
};

// 40350 - Corrupting Plague
class CorruptingPlagueSearcher
{
public:
    CorruptingPlagueSearcher(Unit* obj, float distance) : _unit(obj), _distance(distance)  { }

    bool operator()(Unit* u) const
    {
        if (_unit->GetDistance2d(u) < _distance &&
            (u->GetEntry() == NPC_APEXIS_FLAYER || u->GetEntry() == NPC_SHARD_HIDE_BOAR || u->GetEntry() == NPC_AETHER_RAY) &&
            !u->HasAura(SPELL_CORRUPTING_PLAGUE))
            return true;

        return false;
    }

private:
    Unit* _unit;
    float _distance;
};

// 40349 - Corrupting Plague
class spell_corrupting_plague_aura : public AuraScript
{
    PrepareAuraScript(spell_corrupting_plague_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CORRUPTING_PLAGUE });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* owner = GetTarget();

        std::list<Creature*> targets;
        CorruptingPlagueSearcher creature_check(owner, 15.0f);
        Trinity::CreatureListSearcher<CorruptingPlagueSearcher> creature_searcher(owner, targets, creature_check);
        Cell::VisitGridObjects(owner, creature_searcher, 15.0f);

        if (!targets.empty())
            return;

        PreventDefaultAction();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_corrupting_plague_aura::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

enum StasisFieldEntrys
{
    NPC_DAGGERTAIL_LIZARD    = 22255,
    SPELL_STASIS_FIELD       = 40307
};

// 40307 - Stasis Field
class StasisFieldSearcher
{
public:
    StasisFieldSearcher(Unit* obj, float distance) : _unit(obj), _distance(distance)  { }

    bool operator()(Unit* u) const
    {
        if (_unit->GetDistance2d(u) < _distance &&
            (u->GetEntry() == NPC_APEXIS_FLAYER || u->GetEntry() == NPC_SHARD_HIDE_BOAR || u->GetEntry() == NPC_AETHER_RAY || u->GetEntry() == NPC_DAGGERTAIL_LIZARD) &&
            !u->HasAura(SPELL_STASIS_FIELD))
            return true;

        return false;
    }

private:
    Unit* _unit;
    float _distance;
};

// 40306 - Stasis Field
class spell_stasis_field_aura : public AuraScript
{
    PrepareAuraScript(spell_stasis_field_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_STASIS_FIELD });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* owner = GetTarget();

        std::list<Creature*> targets;
        StasisFieldSearcher creature_check(owner, 15.0f);
        Trinity::CreatureListSearcher<StasisFieldSearcher> creature_searcher(owner, targets, creature_check);
        Cell::VisitGridObjects(owner, creature_searcher, 15.0f);

        if (!targets.empty())
            return;

        PreventDefaultAction();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_stasis_field_aura::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

enum SiegeTankControl
{
    SPELL_SIEGE_TANK_CONTROL = 47963
};

class spell_gen_vehicle_control_link : public AuraScript
{
    PrepareAuraScript(spell_gen_vehicle_control_link);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_SIEGE_TANK_CONTROL); //aurEff->GetAmount()
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_gen_vehicle_control_link::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 34779 - Freezing Circle
enum FreezingCircleSpells
{
    SPELL_FREEZING_CIRCLE_PIT_OF_SARON_NORMAL = 69574,
    SPELL_FREEZING_CIRCLE_PIT_OF_SARON_HEROIC = 70276,
    SPELL_FREEZING_CIRCLE                     = 34787,
};

class spell_freezing_circle : public SpellScript
{
    PrepareSpellScript(spell_freezing_circle);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_FREEZING_CIRCLE_PIT_OF_SARON_NORMAL,
                SPELL_FREEZING_CIRCLE_PIT_OF_SARON_HEROIC,
                SPELL_FREEZING_CIRCLE
            });
    }

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        uint32 spellId = 0;
        Map* map = caster->GetMap();

        if (map->IsDungeon())
            spellId = map->IsHeroic() ? SPELL_FREEZING_CIRCLE_PIT_OF_SARON_HEROIC : SPELL_FREEZING_CIRCLE_PIT_OF_SARON_NORMAL;
        else
            spellId = SPELL_FREEZING_CIRCLE;

        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId))
            SetHitDamage(spellInfo->Effects[EFFECT_0].CalcValue());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_freezing_circle::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Used for some spells cast by vehicles or charmed creatures that do not send a cooldown event on their own
class spell_gen_charmed_unit_spell_cooldown : public SpellScript
{
    PrepareSpellScript(spell_gen_charmed_unit_spell_cooldown);

    void HandleCast()
    {
        Unit* caster = GetCaster();
        if (Player* owner = caster->GetCharmerOrOwnerPlayerOrPlayerItself())
        {
            WorldPacket data;
            caster->GetSpellHistory()->BuildCooldownPacket(data, SPELL_COOLDOWN_FLAG_NONE, GetSpellInfo()->Id, GetSpellInfo()->RecoveryTime);
            owner->SendDirectMessage(&data);
        }
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_gen_charmed_unit_spell_cooldown::HandleCast);
    }
};

void AddSC_generic_spell_scripts()
{
    RegisterAuraScript(spell_gen_absorb0_hitlimit1);
    RegisterAuraScript(spell_gen_adaptive_warding);
    RegisterSpellScript(spell_gen_allow_cast_from_item_only);
    RegisterAuraScript(spell_gen_animal_blood);
    RegisterSpellScript(spell_spawn_blood_pool);
    RegisterSpellScript(spell_gen_arcane_charge);
    RegisterAuraScript(spell_gen_arena_drink);
    RegisterAuraScript(spell_gen_aura_of_anger);
    RegisterAuraScript(spell_gen_aura_of_fear);
    RegisterAuraScript(spell_gen_aura_service_uniform);
    RegisterAuraScript(spell_gen_av_drekthar_presence);
    RegisterSpellScript(spell_gen_bandage);
    RegisterAuraScript(spell_gen_blood_reserve);
    RegisterAuraScript(spell_gen_blade_warding);
    RegisterSpellScript(spell_gen_bonked);
    new spell_gen_break_shield("spell_gen_break_shield");
    new spell_gen_break_shield("spell_gen_tournament_counterattack");
    RegisterAuraScript(spell_gen_burn_brutallus);
    RegisterAuraScript(spell_gen_burning_depths_necrolyte_image);
    RegisterSpellScript(spell_gen_cannibalize);
    RegisterAuraScript(spell_gen_chains_of_ice);
    RegisterSpellScript(spell_gen_chaos_blast);
    RegisterAuraScript(spell_gen_choking_vines);
    RegisterSpellScript(spell_gen_clear_fear_poly);
    RegisterSpellScript(spell_gen_clone);
    RegisterSpellScript(spell_gen_clone_weapon);
    RegisterAuraScript(spell_gen_clone_weapon_aura);
    new spell_gen_count_pct_from_max_hp("spell_gen_default_count_pct_from_max_hp");
    new spell_gen_count_pct_from_max_hp("spell_gen_50pct_count_pct_from_max_hp", 50);
    RegisterSpellScript(spell_gen_create_lance);
    RegisterAuraScript(spell_gen_creature_permanent_feign_death);
    new spell_gen_dalaran_disguise("spell_gen_sunreaver_disguise");
    new spell_gen_dalaran_disguise("spell_gen_silver_covenant_disguise");
    RegisterAuraScript(spell_gen_damage_reduction_aura);
    new spell_gen_decay_over_time_fungal_decay();
    new spell_gen_decay_over_time_tail_sting();
    RegisterAuraScript(spell_gen_defend);
    RegisterSpellScript(spell_gen_despawn_self);
    RegisterSpellScript(spell_gen_divine_storm_cd_reset);
    RegisterSpellScript(spell_gen_ds_flush_knockback);
    RegisterSpellScript(spell_gen_dungeon_credit);
    RegisterSpellScript(spell_gen_elune_candle);
    RegisterAuraScript(spell_ethereal_pet_aura);
    RegisterSpellScript(spell_ethereal_pet_onsummon);
    RegisterSpellScript(spell_ethereal_pet_aura_remove);
    RegisterAuraScript(spell_steal_essence_visual);
    RegisterSpellScript(spell_gen_5000_gold);
    RegisterSpellScript(spell_gen_gadgetzan_transporter_backfire);
    RegisterAuraScript(spell_gen_gift_of_naaru);
    RegisterSpellScript(spell_gen_gnomish_transporter);
    RegisterAuraScript(spell_gen_lifeblood);
    new spell_gen_lifebloom("spell_hexlord_lifebloom", SPELL_HEXLORD_MALACRASS_LIFEBLOOM_FINAL_HEAL);
    new spell_gen_lifebloom("spell_tur_ragepaw_lifebloom", SPELL_TUR_RAGEPAW_LIFEBLOOM_FINAL_HEAL);
    new spell_gen_lifebloom("spell_cenarion_scout_lifebloom", SPELL_CENARION_SCOUT_LIFEBLOOM_FINAL_HEAL);
    new spell_gen_lifebloom("spell_twisted_visage_lifebloom", SPELL_TWISTED_VISAGE_LIFEBLOOM_FINAL_HEAL);
    new spell_gen_lifebloom("spell_faction_champion_dru_lifebloom", SPELL_FACTION_CHAMPIONS_DRU_LIFEBLOOM_FINAL_HEAL);
    new spell_gen_mount("spell_magic_broom", 0, SPELL_MAGIC_BROOM_60, SPELL_MAGIC_BROOM_100, SPELL_MAGIC_BROOM_150, SPELL_MAGIC_BROOM_280);
    new spell_gen_mount("spell_headless_horseman_mount", 0, SPELL_HEADLESS_HORSEMAN_MOUNT_60, SPELL_HEADLESS_HORSEMAN_MOUNT_100, SPELL_HEADLESS_HORSEMAN_MOUNT_150, SPELL_HEADLESS_HORSEMAN_MOUNT_280);
    new spell_gen_mount("spell_winged_steed_of_the_ebon_blade", 0, 0, 0, SPELL_WINGED_STEED_150, SPELL_WINGED_STEED_280);
    new spell_gen_mount("spell_big_blizzard_bear", 0, SPELL_BIG_BLIZZARD_BEAR_60, SPELL_BIG_BLIZZARD_BEAR_100);
    new spell_gen_mount("spell_big_love_rocket", SPELL_BIG_LOVE_ROCKET_0, SPELL_BIG_LOVE_ROCKET_60, SPELL_BIG_LOVE_ROCKET_100, SPELL_BIG_LOVE_ROCKET_150, SPELL_BIG_LOVE_ROCKET_310);
    new spell_gen_mount("spell_invincible", 0, SPELL_INVINCIBLE_60, SPELL_INVINCIBLE_100, SPELL_INVINCIBLE_150, SPELL_INVINCIBLE_310);
    new spell_gen_mount("spell_blazing_hippogryph", 0, 0, 0, SPELL_BLAZING_HIPPOGRYPH_150, SPELL_BLAZING_HIPPOGRYPH_280);
    new spell_gen_mount("spell_celestial_steed", 0, SPELL_CELESTIAL_STEED_60, SPELL_CELESTIAL_STEED_100, SPELL_CELESTIAL_STEED_150, SPELL_CELESTIAL_STEED_280, SPELL_CELESTIAL_STEED_310);
    new spell_gen_mount("spell_x53_touring_rocket", 0, 0, 0, SPELL_X53_TOURING_ROCKET_150, SPELL_X53_TOURING_ROCKET_280, SPELL_X53_TOURING_ROCKET_310);
    RegisterSpellScript(spell_gen_mounted_charge);
    RegisterAuraScript(spell_gen_moss_covered_feet);
    RegisterAuraScript(spell_gen_negative_energy_periodic);
    RegisterSpellScript(spell_gen_netherbloom);
    RegisterSpellScript(spell_gen_nightmare_vine);
    RegisterAuraScript(spell_gen_nitrous_boost);
    RegisterAuraScript(spell_gen_obsidian_armor);
    RegisterAuraScript(spell_gen_one_tick_dummy);
    RegisterSpellScript(spell_gen_oracle_wolvar_reputation);
    RegisterSpellScript(spell_gen_orc_disguise);
    RegisterAuraScript(spell_gen_paralytic_poison);
    new spell_gen_proc_below_pct_damaged("spell_item_soul_harvesters_charm");
    new spell_gen_proc_below_pct_damaged("spell_item_commendation_of_kaelthas");
    new spell_gen_proc_below_pct_damaged("spell_item_corpse_tongue_coin");
    new spell_gen_proc_below_pct_damaged("spell_item_corpse_tongue_coin_heroic");
    new spell_gen_proc_below_pct_damaged("spell_item_petrified_twilight_scale");
    new spell_gen_proc_below_pct_damaged("spell_item_petrified_twilight_scale_heroic");
    RegisterAuraScript(spell_gen_proc_charge_drop_only);
    RegisterAuraScript(spell_gen_parachute);
    RegisterSpellScript(spell_gen_pet_summoned);
    RegisterSpellScript(spell_gen_profession_research);
    RegisterSpellScript(spell_gen_remove_flight_auras);
    RegisterSpellScript(spell_gen_remove_impairing_auras);
    RegisterAuraScript(spell_gen_restoration);
    RegisterSpellAndAuraScriptPair(spell_gen_replenishment, spell_gen_replenishment_aura);
    RegisterAuraScript(spell_gen_remove_on_health_pct);
    RegisterAuraScript(spell_gen_remove_on_full_health);
    RegisterAuraScript(spell_gen_remove_on_full_health_pct);
    RegisterSpellScript(spell_gen_seaforium_blast);
    RegisterSpellScript(spell_gen_spectator_cheer_trigger);
    RegisterSpellScript(spell_gen_spirit_healer_res);
    new spell_gen_summon_elemental("spell_gen_summon_fire_elemental", SPELL_SUMMON_FIRE_ELEMENTAL);
    new spell_gen_summon_elemental("spell_gen_summon_earth_elemental", SPELL_SUMMON_EARTH_ELEMENTAL);
    RegisterSpellScript(spell_gen_summon_tournament_mount);
    RegisterSpellScript(spell_gen_throw_shield);
    RegisterSpellScript(spell_gen_tournament_duel);
    RegisterAuraScript(spell_gen_tournament_pennant);
    RegisterSpellScript(spell_gen_teleporting);
    new spell_pvp_trinket_wotf_shared_cd<SPELL_WILL_OF_THE_FORSAKEN_COOLDOWN_TRIGGER>("spell_pvp_trinket_shared_cd");
    new spell_pvp_trinket_wotf_shared_cd<SPELL_WILL_OF_THE_FORSAKEN_COOLDOWN_TRIGGER_WOTF>("spell_wotf_shared_cd");
    RegisterAuraScript(spell_gen_turkey_marker);
    RegisterSpellScript(spell_gen_upper_deck_create_foam_sword);
    RegisterAuraScript(spell_gen_vampiric_touch);
    RegisterAuraScript(spell_gen_vehicle_scaling);
    RegisterSpellScript(spell_gen_vendor_bark_trigger);
    RegisterSpellScript(spell_gen_wg_water);
    RegisterAuraScript(spell_gen_whisper_gulch_yogg_saron_whisper);
    RegisterSpellScript(spell_gen_eject_all_passengers);
    RegisterSpellScript(spell_gen_eject_passenger);
    RegisterAuraScript(spell_gen_gm_freeze);
    RegisterSpellScript(spell_gen_stand);
    RegisterAuraScript(spell_gen_mixology_bonus);
    RegisterSpellScript(spell_gen_landmine_knockback_achievement);
    RegisterSpellScript(spell_gen_clear_debuffs);
    RegisterAuraScript(spell_gen_pony_mount_check);
    RegisterAuraScript(spell_corrupting_plague_aura);
    RegisterAuraScript(spell_stasis_field_aura);
    RegisterAuraScript(spell_gen_vehicle_control_link);
    RegisterSpellScript(spell_freezing_circle);
    RegisterSpellScript(spell_gen_charmed_unit_spell_cooldown);
}
