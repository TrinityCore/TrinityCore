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
 * Scripts for spells with SPELLFAMILY_MAGE and SPELLFAMILY_GENERIC spells used by mage players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_mage_".
 */

#include "ScriptMgr.h"
#include "GridNotifiers.h"
#include "ObjectAccessor.h"
#include "Pet.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum MageSpells
{
    SPELL_MAGE_ARCANE_POTENCY_RANK_1             = 31571,
    SPELL_MAGE_ARCANE_POTENCY_RANK_2             = 31572,
    SPELL_MAGE_ARCANE_POTENCY_TRIGGER_RANK_1     = 57529,
    SPELL_MAGE_ARCANE_POTENCY_TRIGGER_RANK_2     = 57531,
    SPELL_MAGE_ARCANE_BLAST                      = 30451,
    SPELL_MAGE_ARCANE_MISSILES                   = 5143,
    SPELL_MAGE_ARCANE_MISSILES_AURASTATE         = 79808,
    SPELL_MAGE_BLAZING_SPEED                     = 31643,
    SPELL_MAGE_BRAIN_FREEZE_R1                   = 44546,
    SPELL_MAGE_BURNOUT                           = 29077,
    SPELL_MAGE_COLD_SNAP                         = 11958,
    SPELL_MAGE_COMBUSTION_DAMAGE                 = 83853,
    SPELL_MAGE_DEEP_FREEZE_DAMAGE                = 71757,
    SPELL_MAGE_EARLY_FROST_R1                    = 83049,
    SPELL_MAGE_EARLY_FROST_R2                    = 83050,
    SPELL_MAGE_EARLY_FROST_TRIGGERED_R1          = 83162,
    SPELL_MAGE_EARLY_FROST_TRIGGERED_R2          = 83239,
    SPELL_MAGE_EARLY_FROST_VISUAL                = 94315,
    SPELL_MAGE_FIREBALL                          = 133,
    SPELL_MAGE_FIRE_BLAST                        = 2136,
    SPELL_MAGE_FROST_NOVA                        = 122,
    SPELL_MAGE_FLAME_ORB_DUMMY                   = 82731,
    SPELL_MAGE_FLAME_ORB_SUMMON                  = 84765,
    SPELL_MAGE_FLAME_ORB_AOE                     = 82734,
    SPELL_MAGE_FLAME_ORB_BEAM_DUMMY              = 86719,
    SPELL_MAGE_FLAME_ORB_DAMAGE                  = 82739,
    SPELL_MAGE_FLAME_ORB_SELF_SNARE              = 82736,
    SPELL_MAGE_FROSTFIRE_BOLT                    = 44614,
    SPELL_MAGE_FROSTFIRE_ORB_DUMMY               = 92283,
    SPELL_MAGE_FROSTFIRE_ORB_SUMMON              = 84714,
    SPELL_MAGE_FROSTFIRE_ORB_AOE                 = 84718,
    SPELL_MAGE_FROSTFIRE_ORB_DAMAGE_R1           = 95969,
    SPELL_MAGE_FROSTFIRE_ORB_DAMAGE_R2           = 84721,
    SPELL_MAGE_FROSTFIRE_ORB_RANK_R2             = 84727,
    SPELL_MAGE_FROSTFIRE_BOLT_CHILL_EFFECT       = 44614,
    SPELL_MAGE_HOT_STREAK                        = 44445,
    SPELL_MAGE_HOT_STREAK_TRIGGERED              = 48108,
    SPELL_MAGE_HYPOTHERMIA                       = 41425,
    SPELL_MAGE_IMPROVED_HOT_STREAK               = 44446,
    SPELL_MAGE_IMPROVED_POLYMORPH_RANK_1         = 11210,
    SPELL_MAGE_IMPROVED_POLYMORPH_STUN_RANK_1    = 83046,
    SPELL_MAGE_IMPROVED_POLYMORPH_MARKER         = 87515,
    SPELL_MAGE_INCANTERS_ABSORBTION_TRIGGERED    = 44413,
    SPELL_MAGE_INCANTERS_ABSORBTION_KNOCKBACK    = 86261,
    SPELL_MAGE_IGNITE                            = 12654,
    SPELL_MAGE_LIVING_BOMB                       = 44457,
    SPELL_MAGE_MASTER_OF_ELEMENTS_ENERGIZE       = 29077,
    SPELL_MAGE_MIRROR_IMAGE_TRIGGERED_FIRE       = 88092,
    SPELL_MAGE_MIRROR_IMAGE_TRIGGERED_ARCANE     = 88091,
    SPELL_MAGE_MIRROR_IMAGE_TRIGGERED_FROST      = 58832,
    SPELL_MAGE_PERMAFROST_REDUCE_HEAL            = 68391,
    SPELL_MAGE_PERMAFROST_HEAL                   = 91394,
    SPELL_MAGE_PYROBLAST                         = 11366,
    SPELL_MAGE_PYROBLAST_HOT_STREAK              = 92315,
    SPELL_MAGE_PYROMANIAC_TRIGGERED              = 83582,
    SPELL_MAGE_SCORCH                            = 2948,
    SPELL_MAGE_SLOW                              = 31589,
    SPELL_MAGE_T12_4P_BONUS                      = 99064,
    SPELL_MAGE_GLYPH_OF_ETERNAL_WATER            = 70937,
    SPELL_MAGE_SHATTERED_BARRIER                 = 55080,
    SPELL_MAGE_SUMMON_WATER_ELEMENTAL_PERMANENT  = 70908,
    SPELL_MAGE_SUMMON_WATER_ELEMENTAL_TEMPORARY  = 70907,
    SPELL_MAGE_GLYPH_OF_BLAST_WAVE               = 62126,

    SPELL_MAGE_FLAMESTRIKE                       = 2120,

    SPELL_MAGE_CHILLED_R1                        = 12484,
    SPELL_MAGE_CHILLED_R2                        = 12485,

    SPELL_MAGE_CONE_OF_COLD_AURA_R1              = 11190,
    SPELL_MAGE_CONE_OF_COLD_AURA_R2              = 12489,
    SPELL_MAGE_CONE_OF_COLD_TRIGGER_R1           = 83301,
    SPELL_MAGE_CONE_OF_COLD_TRIGGER_R2           = 83302,

    SPELL_MAGE_SHATTERED_BARRIER_R1              = 44745,
    SPELL_MAGE_SHATTERED_BARRIER_R2              = 54787,
    SPELL_MAGE_SHATTERED_BARRIER_FREEZE_R1       = 55080,
    SPELL_MAGE_SHATTERED_BARRIER_FREEZE_R2       = 83073,

    SPELL_MAGE_IMPROVED_MANA_GEM_TRIGGERED       = 83098,

    SPELL_MAGE_RING_OF_FROST_SUMMON              = 82676,
    SPELL_MAGE_RING_OF_FROST_FREEZE              = 82691,
    SPELL_MAGE_RING_OF_FROST_DUMMY               = 91264,

    SPELL_MAGE_FINGERS_OF_FROST                  = 44544,
    SPELL_MAGE_TEMPORAL_DISPLACEMENT             = 80354,
};

enum MageIcons
{
    ICON_MAGE_SHATTER                            = 976,
    ICON_MAGE_IMPROVED_CONE_OF_COLD              = 35,
    ICON_MAGE_IMPROVED_FLAMESTRIKE               = 37,
    ICON_MAGE_IMPROVED_FREEZE                    = 94,
    ICON_MAGE_INCANTERS_ABSORPTION               = 2941,
    ICON_MAGE_IMPROVED_MANA_GEM                  = 1036,
    ICON_MAGE_EARLY_FROST_SKILL                  = 189,
    ICON_MAGE_EARLY_FROST                        = 2114,
    ICON_MAGE_GLYPH_OF_ICE_BLOCK                 = 14,
    ICON_MAGE_GLYPH_OF_ICY_VEINS                 = 2162,
    ICON_MAGE_GLYPH_OF_MIRROR_IMAGE              = 331,
    ICON_MAGE_GLYPH_OF_POLYMORPH                 = 82,
    ICON_MAGE_LIVING_BOMB                        = 3000,
    ICON_MAGE_GLYPH_OF_FROSTFIRE                 = 2946,
    ICON_MAGE_HOT_STREAK                         = 2999

};

enum MiscSpells
{
    SPELL_HUNTER_INSANITY                        = 95809,
    SPELL_PRIEST_SHADOW_WORD_DEATH               = 32409,
    SPELL_SHAMAN_EXHAUSTION                      = 57723,
    SPELL_SHAMAN_SATED                           = 57724
};

// -31571 - Arcane Potency
class spell_mage_arcane_potency : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MAGE_ARCANE_POTENCY_RANK_1,
                SPELL_MAGE_ARCANE_POTENCY_RANK_2,
                SPELL_MAGE_ARCANE_POTENCY_TRIGGER_RANK_1,
                SPELL_MAGE_ARCANE_POTENCY_TRIGGER_RANK_2
            });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        uint32 spellId = 0;

        if (GetSpellInfo()->Id == SPELL_MAGE_ARCANE_POTENCY_RANK_1)
            spellId = SPELL_MAGE_ARCANE_POTENCY_TRIGGER_RANK_1;
        else if (GetSpellInfo()->Id == SPELL_MAGE_ARCANE_POTENCY_RANK_2)
            spellId = SPELL_MAGE_ARCANE_POTENCY_TRIGGER_RANK_2;
        if (!spellId)
            return;

        GetTarget()->CastSpell(GetTarget(), spellId, aurEff);

    }

    void Register() override
    {
        OnEffectProc.Register(&spell_mage_arcane_potency::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

enum MageSpellIcons
{
    SPELL_ICON_MAGE_SHATTERED_BARRIER = 2945
};

// 11113 - Blast Wave
class spell_mage_blast_wave : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_FLAMESTRIKE });
    }

    void HandleImprovedFlamestrike(SpellEffIndex /*effIndex*/)
    {
        ++_hitTargetsCount;
        if (_hitTargetsCount != 2)
            return;

        if (AuraEffect const* aurEff = GetCaster()->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_MAGE, ICON_MAGE_IMPROVED_FLAMESTRIKE, EFFECT_0))
            if (!roll_chance_i(aurEff->GetAmount()))
                return;

        if (WorldLocation const* targetDest = GetExplTargetDest())
            GetCaster()->CastSpell(targetDest->GetPosition(), SPELL_MAGE_FLAMESTRIKE, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_mage_blast_wave::HandleImprovedFlamestrike, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
    }
private:
    uint8 _hitTargetsCount = 0;
};

// -31641 - Blazing Speed
class spell_mage_blazing_speed : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_BLAZING_SPEED });
    }

    void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_BLAZING_SPEED, aurEff);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_mage_blazing_speed::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 42208 - Blizzard
/// Updated 4.3.4
class spell_mage_blizzard : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MAGE_CHILLED_R1,
                SPELL_MAGE_CHILLED_R2
            });
    }

    void AddChillEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* unitTarget = GetHitUnit())
        {
            if (caster->IsScriptOverriden(GetSpellInfo(), 836))
                caster->CastSpell(unitTarget, SPELL_MAGE_CHILLED_R1, true);
            else if (caster->IsScriptOverriden(GetSpellInfo(), 988))
                caster->CastSpell(unitTarget, SPELL_MAGE_CHILLED_R2, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_mage_blizzard::AddChillEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 11958 - Cold Snap
class spell_mage_cold_snap : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsPlayer();
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
        OnEffectHit.Register(&spell_mage_cold_snap::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 120 - Cone of Cold
/// Updated 4.3.4
static std::array<uint32, 2> const ImprovedConeOfColdSpellIds = { SPELL_MAGE_CONE_OF_COLD_TRIGGER_R1, SPELL_MAGE_CONE_OF_COLD_TRIGGER_R2 };

class spell_mage_cone_of_cold : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(ImprovedConeOfColdSpellIds);
    }

    void HandleConeOfColdScript(SpellEffIndex /*effIndex*/)
    {
        if (AuraEffect const* aurEff = GetCaster()->GetDummyAuraEffect(SPELLFAMILY_MAGE, ICON_MAGE_IMPROVED_CONE_OF_COLD, EFFECT_0))
            if (aurEff->IsAffectingSpell(GetSpellInfo()))
                GetHitUnit()->CastSpell(GetHitUnit(), ImprovedConeOfColdSpellIds[uint8(aurEff->GetSpellInfo()->GetRank() - 1)], true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_mage_cone_of_cold::HandleConeOfColdScript, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 42955 Conjure Refreshment
/// Updated 4.3.4
struct ConjureRefreshmentData
{
    uint32 minLevel;
    uint32 maxLevel;
    uint32 spellId;
};

ConjureRefreshmentData const _conjureData[] =
{
    { 33, 43, 92739 },
    { 44, 53, 92799 },
    { 54, 63, 92802 },
    { 64, 73, 92805 },
    { 74, 79, 74625 },
    { 80, 84, 92822 },
    { 85, 85, 92727 }
};
uint8 const MAX_CONJURE_REFRESHMENT_SPELLS = std::extent<decltype(_conjureData)>::value;

// 42955 - Conjure Refreshment
class spell_mage_conjure_refreshment : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        for (uint8 i = 0; i < MAX_CONJURE_REFRESHMENT_SPELLS; ++i)
            if (!ValidateSpellInfo({ _conjureData[i].spellId }))
                return false;
        return true;
    }

    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        uint8 level = GetHitUnit()->getLevel();
        for (uint8 i = 0; i < MAX_CONJURE_REFRESHMENT_SPELLS; ++i)
        {
            ConjureRefreshmentData const& spellData = _conjureData[i];
            if (level < spellData.minLevel || level > spellData.maxLevel)
                continue;
            GetHitUnit()->CastSpell(GetHitUnit(), spellData.spellId);
            break;
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_mage_conjure_refreshment::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// -31661 - Dragon's Breath
class spell_mage_dragon_breath : public AuraScript
{
    bool CheckProc(ProcEventInfo& eventInfo)
    {
        // Dont proc with Living Bomb explosion
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (spellInfo && spellInfo->SpellIconID == ICON_MAGE_LIVING_BOMB && spellInfo->SpellFamilyName == SPELLFAMILY_MAGE)
            return false;
        return true;
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_mage_dragon_breath::CheckProc);
    }
};

// 54646 - Focus Magic
class spell_mage_focus_magic : public AuraScript
{
    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
            if (caster->IsAlive())
                caster->CastSpell(caster, GetSpellInfo()->Effects[EFFECT_1].TriggerSpell, aurEff);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_mage_focus_magic::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 116 - Frostbolt
/// Updated 4.3.4
class spell_mage_frostbolt : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                 SPELL_MAGE_EARLY_FROST_R1,
                 SPELL_MAGE_EARLY_FROST_R2,
                 SPELL_MAGE_EARLY_FROST_TRIGGERED_R1,
                 SPELL_MAGE_EARLY_FROST_TRIGGERED_R2,
                 SPELL_MAGE_EARLY_FROST_VISUAL
            });
    }

    bool Load() override
    {
        _earlyFrostActive = false;
        _earlyFrostSpellId = 0;

        Unit* caster = GetCaster();
        if (!caster)
            return false;

        // Check Early Frost state
        if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_MAGE, ICON_MAGE_EARLY_FROST_SKILL, 0))
        {
            // Check if the cooldown effect is inactive
            if (!caster->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_MAGE, ICON_MAGE_EARLY_FROST, EFFECT_0))
            {
                _earlyFrostActive = true;
                if (aurEff->GetId() == SPELL_MAGE_EARLY_FROST_R1)
                    _earlyFrostSpellId = SPELL_MAGE_EARLY_FROST_TRIGGERED_R1;
                else if (aurEff->GetId() == SPELL_MAGE_EARLY_FROST_R2)
                    _earlyFrostSpellId = SPELL_MAGE_EARLY_FROST_TRIGGERED_R2;
            }
        }

        return true;
    }

    void HandleEarlyFrost()
    {
        if (Unit* caster = GetCaster())
        {
            if (_earlyFrostActive)
            {
                caster->CastSpell(caster, _earlyFrostSpellId, true);
                caster->RemoveAurasDueToSpell(SPELL_MAGE_EARLY_FROST_VISUAL);
            }
        }
    }

    void RecalculateDamage(SpellEffIndex /*effIndex*/)
    {
        if (GetHitUnit() && GetHitUnit()->HasAuraState(AURA_STATE_FROZEN, GetSpellInfo(), GetCaster()))
        {
            if (AuraEffect* aurEff = GetCaster()->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_MAGE, ICON_MAGE_SHATTER, EFFECT_1))
            {
                int32 damage = GetHitDamage();
                AddPct(damage, aurEff->GetAmount());
                SetHitDamage(damage);
            }
        }
    }

    void Register() override
    {
        OnSpellStart.Register(&spell_mage_frostbolt::HandleEarlyFrost);
        OnEffectHitTarget.Register(&spell_mage_frostbolt::RecalculateDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }

private:
    bool _earlyFrostActive;
    uint32 _earlyFrostSpellId;
};

// 45438 - Ice Block
class spell_mage_ice_block : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_HYPOTHERMIA, SPELL_MAGE_FROST_NOVA });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // Hypothermia debuff
        GetTarget()->CastSpell(nullptr, SPELL_MAGE_HYPOTHERMIA, true);

        // Glyph of Ice Block
        if (GetTarget()->GetDummyAuraEffect(SPELLFAMILY_MAGE, ICON_MAGE_GLYPH_OF_ICE_BLOCK, EFFECT_0))
            GetTarget()->GetSpellHistory()->ResetCooldown(SPELL_MAGE_FROST_NOVA, true);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_mage_ice_block::AfterApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 12472 - Icy Veins
class spell_mage_icy_veins : public AuraScript
{
    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget()->GetDummyAuraEffect(SPELLFAMILY_MAGE, ICON_MAGE_GLYPH_OF_ICY_VEINS, EFFECT_0))
        {
            GetTarget()->RemoveAurasByType(SPELL_AURA_HASTE_SPELLS, ObjectGuid::Empty, 0, true, false);
            GetTarget()->RemoveAurasByType(SPELL_AURA_MOD_DECREASE_SPEED);
        }
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_mage_icy_veins::AfterApply, EFFECT_0, SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 44457 - Living Bomb
class spell_mage_living_bomb : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->Effects[EFFECT_1].CalcValue()) });
    }

    void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (!GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::Expired))
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), uint32(aurEff->GetAmount()), aurEff);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_mage_living_bomb::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 11426 - Ice Barrier
/// Updated 4.3.4
class spell_mage_ice_barrier : public AuraScript
{
    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;
        if (Unit* caster = GetCaster())
            amount += int32(0.87f * caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask()));
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::ByEnemySpell))
            return;

        if (GetTarget()->HasAura(SPELL_MAGE_SHATTERED_BARRIER_R1))
            GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_SHATTERED_BARRIER_FREEZE_R1, true);
        else if (GetTarget()->HasAura(SPELL_MAGE_SHATTERED_BARRIER_R2))
            GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_SHATTERED_BARRIER_FREEZE_R2, true);
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_mage_ice_barrier::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        AfterEffectRemove.Register(&spell_mage_ice_barrier::AfterRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_mage_ice_barrier::AfterRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

// -11119 - Ignite
class spell_mage_ignite : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MAGE_IGNITE,
                SPELL_MAGE_FLAME_ORB_DAMAGE,
                SPELL_MAGE_FROSTFIRE_ORB_DAMAGE_R1,
                SPELL_MAGE_FROSTFIRE_ORB_DAMAGE_R2
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (!eventInfo.GetSpellInfo() || !eventInfo.GetProcTarget())
            return false;

        switch (eventInfo.GetSpellInfo()->Id)
        {
            case SPELL_MAGE_FLAME_ORB_DAMAGE:
            case SPELL_MAGE_FROSTFIRE_ORB_DAMAGE_R1:
            case SPELL_MAGE_FROSTFIRE_ORB_DAMAGE_R2:
                return false;
        }

        return true;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();

        DamageInfo* damage = eventInfo.GetDamageInfo();

        int32 bp = CalculatePct(damage->GetDamage(), aurEff->GetAmount()) * 0.5f;
        if (bp > 0)
            target->CastSpell(eventInfo.GetProcTarget(), SPELL_MAGE_IGNITE, CastSpellExtraArgs(aurEff).AddSpellBP0(bp));
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_mage_ignite::CheckProc);
        OnEffectProc.Register(&spell_mage_ignite::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 12654 - Ignite
class spell_mage_ignite_periodic : public AuraScript
{
    void CalculateRefreshedDot(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;
        _critDamageValues.emplace_back(std::make_pair(2, amount));

        amount = 0;
        for (auto const& damageValuePair : _critDamageValues)
            amount += damageValuePair.second;
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        int32 newDotValue = 0;
        bool changed = false;
        for (std::vector<std::pair<uint8, int32>>::iterator itr = _critDamageValues.begin(); itr != _critDamageValues.end();)
        {
            --itr->first;
            newDotValue += itr->second;
            if (itr->first == 0)
            {
                itr = _critDamageValues.erase(itr);
                changed = true;
            }
            else
                ++itr;
        }

        if (changed)
            const_cast<AuraEffect*>(aurEff)->SetAmount(newDotValue);
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_mage_ignite_periodic::CalculateRefreshedDot, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        OnEffectPeriodic.Register(&spell_mage_ignite_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
private:
    std::vector<std::pair<uint8, int32>> _critDamageValues;
};

// 543 - Mage Ward
/// Updated 4.3.4
class spell_mage_mage_ward : public AuraScript
{
    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;
        if (Unit* caster = GetCaster())
        {
            // ${$m1+0.807*$SPA}
            float bonus = 0.807f * caster->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_ARCANE);
            amount += int32(bonus);
        }
    }

    void HandleAbsorb(AuraEffect* /*aurEff*/, DamageInfo& /*dmgInfo*/, uint32& absorbAmount)
    {
        if (AuraEffect const* aurEff = GetTarget()->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_GENERIC, ICON_MAGE_INCANTERS_ABSORPTION, EFFECT_0))
        {
            int32 bp = CalculatePct(absorbAmount, aurEff->GetAmount());
            GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_INCANTERS_ABSORBTION_TRIGGERED, CastSpellExtraArgs(true).AddSpellBP0(bp));
        }
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_mage_mage_ward::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        AfterEffectAbsorb.Register(&spell_mage_mage_ward::HandleAbsorb, EFFECT_0);
    }
};

// 1463 - Mana Shield
/// Updated 4.3.4
class spell_mage_mana_shield : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MAGE_INCANTERS_ABSORBTION_TRIGGERED,
                SPELL_MAGE_INCANTERS_ABSORBTION_KNOCKBACK
            });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;
        if (Unit* caster = GetCaster())
        {
            // 87% of the spellpower as bonus
            float bonus = 0.807f * caster->SpellBaseDamageBonusDone(GetSpellInfo()->GetSchoolMask());
            amount += int32(bonus);
        }
    }

    void HandleAbsorb(AuraEffect* /*aurEff*/, DamageInfo& /*dmgInfo*/, uint32& absorbAmount)
    {
        if (AuraEffect const* aurEff = GetTarget()->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_GENERIC, ICON_MAGE_INCANTERS_ABSORPTION, EFFECT_0))
        {
            int32 bp = CalculatePct(absorbAmount, aurEff->GetAmount());
            GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_INCANTERS_ABSORBTION_TRIGGERED, CastSpellExtraArgs(true).AddSpellBP0(bp));
        }
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget()->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_GENERIC, ICON_MAGE_INCANTERS_ABSORPTION, EFFECT_0))
            if (GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::ByEnemySpell))
                GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_INCANTERS_ABSORBTION_KNOCKBACK, true);
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_mage_mana_shield::CalculateAmount, EFFECT_0, SPELL_AURA_MANA_SHIELD);
        AfterEffectManaShield.Register(&spell_mage_mana_shield::HandleAbsorb, EFFECT_0);
        AfterEffectRemove.Register(&spell_mage_mana_shield::AfterRemove, EFFECT_0, SPELL_AURA_MANA_SHIELD, AURA_EFFECT_HANDLE_REAL);
    }
};

// -29074 - Master of Elements
class spell_mage_master_of_elements : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_MASTER_OF_ELEMENTS_ENERGIZE });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetDamageInfo()->GetSpellInfo() != nullptr;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        SpellInfo const* spell = eventInfo.GetSpellInfo();
        int32 mana = int32(spell->CalcPowerCost(GetTarget(), spell->GetSchoolMask()));
        mana = CalculatePct(mana, aurEff->GetAmount());

        if (mana)
            GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_MASTER_OF_ELEMENTS_ENERGIZE, CastSpellExtraArgs(aurEff).AddSpellBP0(mana));
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_mage_master_of_elements::CheckProc);
        OnEffectProc.Register(&spell_mage_master_of_elements::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -86181 - Nether Vortex
class spell_mage_nether_vortex : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_SLOW });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        return !GetTarget()->HasSingleCastAuraOfSpell(SPELL_MAGE_SLOW);
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_MAGE_SLOW, aurEff);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_mage_nether_vortex::CheckProc);
        OnEffectProc.Register(&spell_mage_nether_vortex::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -11175 - Permafrost
class spell_mage_permafrost : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MAGE_PERMAFROST_HEAL,
                SPELL_MAGE_PERMAFROST_REDUCE_HEAL
            });
    }

    bool DoCheck(ProcEventInfo& eventInfo)
    {
        return GetTarget()->GetGuardianPet() && eventInfo.GetDamageInfo()->GetDamage() && eventInfo.GetProcTarget();
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* target = GetTarget();
        int32 heal = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount()));
        target->CastSpell(nullptr, SPELL_MAGE_PERMAFROST_HEAL, CastSpellExtraArgs(aurEff).AddSpellBP0(heal));
        target->CastSpell(eventInfo.GetProcTarget(), SPELL_MAGE_PERMAFROST_REDUCE_HEAL, aurEff);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_mage_permafrost::DoCheck);
        OnEffectProc.Register(&spell_mage_permafrost::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 118 - Polymorph
class spell_mage_polymorph : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MAGE_IMPROVED_POLYMORPH_RANK_1,
                SPELL_MAGE_IMPROVED_POLYMORPH_STUN_RANK_1,
                SPELL_MAGE_IMPROVED_POLYMORPH_MARKER
            });
    }

    void HandleGlyphEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (AuraEffect const* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_MAGE, ICON_MAGE_GLYPH_OF_POLYMORPH, EFFECT_0))
            {
                // Improved Polymorph and Glyph of Polymorph both use dummy auras with the same icon.
                if (aurEff->GetSpellInfo()->Id == SPELL_MAGE_IMPROVED_POLYMORPH_RANK_1 || aurEff->GetSpellInfo()->GetRank() > 1)
                    return;

                GetTarget()->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
                GetTarget()->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
                GetTarget()->RemoveAurasByType(SPELL_AURA_PERIODIC_LEECH);
            }
        }
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (!eventInfo.GetDamageInfo() || eventInfo.GetDamageInfo()->GetDamage() == 0)
            return false;

        Unit* caster = GetCaster();
        return caster && !caster->HasAura(SPELL_MAGE_IMPROVED_POLYMORPH_MARKER);
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        Unit* caster = GetCaster();
        if (!caster)
            return;

        // Improved Polymorph
        if (AuraEffect const* improvedPolymorph = caster->GetAuraEffectOfRankedSpell(SPELL_MAGE_IMPROVED_POLYMORPH_RANK_1, EFFECT_0))
        {
            if (caster->HasAura(SPELL_MAGE_IMPROVED_POLYMORPH_MARKER))
                return;

            GetTarget()->CastSpell(GetTarget(), sSpellMgr->GetSpellWithRank(SPELL_MAGE_IMPROVED_POLYMORPH_STUN_RANK_1, improvedPolymorph->GetSpellInfo()->GetRank()), aurEff);
            caster->CastSpell(nullptr, SPELL_MAGE_IMPROVED_POLYMORPH_MARKER, aurEff);
        }
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_mage_polymorph::HandleGlyphEffect, EFFECT_0, SPELL_AURA_MOD_CONFUSE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        DoCheckProc.Register(&spell_mage_polymorph::CheckProc);
        OnEffectProc.Register(&spell_mage_polymorph::HandleEffectProc, EFFECT_0, SPELL_AURA_MOD_CONFUSE);
    }
};

// 5405  - Replenish Mana (Mana Gem)
/// Updated 4.3.4
class spell_mage_replenish_mana : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_IMPROVED_MANA_GEM_TRIGGERED });
    }

    void HandleImprovedManaGem()
    {
        if (AuraEffect* aurEff = GetCaster()->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_MAGE, ICON_MAGE_IMPROVED_MANA_GEM, EFFECT_0))
        {
            int32 bp = CalculatePct(GetCaster()->GetMaxPower(POWER_MANA), aurEff->GetAmount());
            GetCaster()->CastSpell(GetCaster(), SPELL_MAGE_IMPROVED_MANA_GEM_TRIGGERED, CastSpellExtraArgs(true).AddSpellBP0(bp).AddSpellMod(SPELLVALUE_BASE_POINT1, bp));
        }
    }

    void Register() override
    {
        AfterCast.Register(&spell_mage_replenish_mana::HandleImprovedManaGem);
    }
};

// 82676 - Ring of Frost
/// Updated 4.3.4
class spell_mage_ring_of_frost : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MAGE_RING_OF_FROST_SUMMON,
                SPELL_MAGE_RING_OF_FROST_FREEZE,
                SPELL_MAGE_RING_OF_FROST_DUMMY
            });
    }

    bool Load() override
    {
        ringOfFrost = nullptr;
        return true;
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (ringOfFrost)
            if (GetMaxDuration() - (int32)ringOfFrost->GetTimer() >= sSpellMgr->GetSpellInfo(SPELL_MAGE_RING_OF_FROST_DUMMY)->GetDuration())
                GetTarget()->CastSpell({ ringOfFrost->GetPositionX(), ringOfFrost->GetPositionY(), ringOfFrost->GetPositionZ() }, SPELL_MAGE_RING_OF_FROST_FREEZE, true);
    }

    void Apply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        std::list<Creature*> MinionList;
        GetTarget()->GetAllMinionsByEntry(MinionList, GetSpellInfo()->Effects[EFFECT_0].MiscValue);

        // Get the last summoned RoF, save it and despawn older ones
        for (std::list<Creature*>::iterator itr = MinionList.begin(); itr != MinionList.end(); itr++)
        {
            TempSummon* summon = (*itr)->ToTempSummon();

            if (ringOfFrost && summon)
            {
                if (summon->GetTimer() > ringOfFrost->GetTimer())
                {
                    ringOfFrost->DespawnOrUnsummon();
                    ringOfFrost = summon;
                }
                else
                    summon->DespawnOrUnsummon();
            }
            else if (summon)
                ringOfFrost = summon;
        }
    }

    TempSummon* ringOfFrost;

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_mage_ring_of_frost::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        OnEffectApply.Register(&spell_mage_ring_of_frost::Apply, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 82691 - Ring of Frost (freeze efect)
/// Updated 4.3.4
class spell_mage_ring_of_frost_freeze : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_RING_OF_FROST_SUMMON, SPELL_MAGE_RING_OF_FROST_FREEZE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        float outRadius = sSpellMgr->GetSpellInfo(SPELL_MAGE_RING_OF_FROST_SUMMON)->Effects[EFFECT_0].CalcRadius();
        float inRadius = 4.7f;

        for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
            if (Unit* unit = (*itr)->ToUnit())
                if (unit->HasAura(SPELL_MAGE_RING_OF_FROST_DUMMY) || unit->HasAura(SPELL_MAGE_RING_OF_FROST_FREEZE) || unit->GetExactDist(GetExplTargetDest()) > outRadius || unit->GetExactDist(GetExplTargetDest()) < inRadius)
                    targets.erase(itr--);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_mage_ring_of_frost_freeze::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

class spell_mage_ring_of_frost_freeze_AuraScript : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_RING_OF_FROST_DUMMY });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::Expired))
            if (GetCaster())
                GetCaster()->CastSpell(GetTarget(), SPELL_MAGE_RING_OF_FROST_DUMMY, true);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_mage_ring_of_frost_freeze_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 80353 - Time Warp
class spell_mage_time_warp : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MAGE_TEMPORAL_DISPLACEMENT,
                SPELL_HUNTER_INSANITY,
                SPELL_SHAMAN_EXHAUSTION,
                SPELL_SHAMAN_SATED
            });
    }

    void RemoveInvalidTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_MAGE_TEMPORAL_DISPLACEMENT));
        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_HUNTER_INSANITY));
        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHAMAN_EXHAUSTION));
        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHAMAN_SATED));
    }

    void ApplyDebuff()
    {
        if (Unit* target = GetHitUnit())
            target->CastSpell(target, SPELL_MAGE_TEMPORAL_DISPLACEMENT, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_mage_time_warp::RemoveInvalidTargets, EFFECT_ALL, TARGET_UNIT_CASTER_AREA_RAID);
        AfterHit.Register(&spell_mage_time_warp::ApplyDebuff);
    }
};

// 33395 Water Elemental's Freeze
/// Updated 4.3.4
class spell_mage_water_elemental_freeze : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_FINGERS_OF_FROST });
    }

    void CountTargets(std::list<WorldObject*>& targetList)
    {
        _didHit = !targetList.empty();
    }

    void HandleImprovedFreeze()
    {
        if (!_didHit)
            return;

        Unit* owner = GetCaster()->GetOwner();
        if (!owner)
            return;

        if (AuraEffect* aurEff = owner->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_MAGE, ICON_MAGE_IMPROVED_FREEZE, EFFECT_0))
        {
            if (roll_chance_i(aurEff->GetAmount()))
                owner->CastSpell(owner, SPELL_MAGE_FINGERS_OF_FROST, CastSpellExtraArgs(true).AddSpellMod(SPELLVALUE_AURA_STACK, 2));
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_mage_water_elemental_freeze::CountTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        AfterCast.Register(&spell_mage_water_elemental_freeze::HandleImprovedFreeze);
    }

private:
    bool _didHit;
};

// 79683 Arcane Missiles!
class spell_mage_arcane_missiles_trigger : public AuraScript
{
    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_ARCANE_MISSILES_AURASTATE });
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_MAGE_ARCANE_MISSILES_AURASTATE, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetCaster()->RemoveAura(SPELL_MAGE_ARCANE_MISSILES_AURASTATE);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_mage_arcane_missiles_trigger::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        AfterEffectApply.Register(&spell_mage_arcane_missiles_trigger::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_mage_arcane_missiles_trigger::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 79684 Offensive State (DND)
class spell_mage_offensive_state_dnd : public AuraScript
{
    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MAGE_ARCANE_MISSILES,
                SPELL_MAGE_HOT_STREAK,
                SPELL_MAGE_BRAIN_FREEZE_R1
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        Player* player = GetTarget()->ToPlayer();
        if (!player || !eventInfo.GetSpellInfo())
            return false;

        // Don't proc when caster does not know Arcane Missiles
        if (!player->HasSpell(SPELL_MAGE_ARCANE_MISSILES))
            return false;

        // Hot Streak will no longer allow Arcane Missiles to proc
        if (player->HasAura(SPELL_MAGE_HOT_STREAK))
            return false;

        // Brain Freeze will no longer allow Arcane Missiles to proc
        if (player->GetAuraOfRankedSpell(SPELL_MAGE_BRAIN_FREEZE_R1))
            return false;

        return true;
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_mage_offensive_state_dnd::CheckProc);
    }
};

class spell_mage_early_frost : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_EARLY_FROST_VISUAL });
    }

    void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_MAGE_EARLY_FROST_VISUAL, aurEff);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_mage_early_frost::AfterRemove, EFFECT_0, SPELL_AURA_ADD_FLAT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 82731 - Flame Orb
class spell_mage_flame_orb : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MAGE_FLAME_ORB_DUMMY,
                SPELL_MAGE_FROSTFIRE_ORB_DUMMY,
                SPELL_MAGE_FLAME_ORB_SUMMON,
                SPELL_MAGE_FROSTFIRE_ORB_SUMMON
            });
    }

    bool Load() override
    {
        dummySpellId = GetSpellInfo()->Id;
        return true;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            switch (dummySpellId)
            {
                case SPELL_MAGE_FLAME_ORB_DUMMY:
                    caster->CastSpell(caster, SPELL_MAGE_FLAME_ORB_SUMMON, true);
                    break;
                case SPELL_MAGE_FROSTFIRE_ORB_DUMMY:
                    caster->CastSpell(caster, SPELL_MAGE_FROSTFIRE_ORB_SUMMON, true);
                    break;
                default:
                    break;
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_mage_flame_orb::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    uint32 dummySpellId;
};

// 82734 - Flame Orb dummy AOE
class spell_mage_flame_orb_aoe_dummy : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MAGE_FLAME_ORB_AOE,
                SPELL_MAGE_FROSTFIRE_ORB_AOE,
                SPELL_MAGE_FLAME_ORB_BEAM_DUMMY,
                SPELL_MAGE_FROSTFIRE_ORB_DAMAGE_R1,
                SPELL_MAGE_FROSTFIRE_ORB_DAMAGE_R2,
                SPELL_MAGE_FLAME_ORB_DAMAGE,
                SPELL_MAGE_FLAME_ORB_SELF_SNARE,
                SPELL_MAGE_FROSTFIRE_ORB_RANK_R2,
            });
    }

    bool Load() override
    {
        dummySpellId = GetSpellInfo()->Id;
        return true;
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster(), true));
        targets.resize(1);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (TempSummon* caster = GetCaster()->ToTempSummon())
            if (Unit* summoner = caster->GetSummoner())
                if (Unit* target = GetHitUnit())
                {
                    switch (dummySpellId)
                    {
                        case SPELL_MAGE_FLAME_ORB_AOE:
                            caster->CastSpell(caster, SPELL_MAGE_FLAME_ORB_SELF_SNARE, true);
                            caster->CastSpell(target, SPELL_MAGE_FLAME_ORB_BEAM_DUMMY, true);
                            summoner->CastSpell(target, SPELL_MAGE_FLAME_ORB_DAMAGE, true);
                            break;
                        case SPELL_MAGE_FROSTFIRE_ORB_AOE:
                            caster->CastSpell(caster, SPELL_MAGE_FLAME_ORB_SELF_SNARE, true);
                            caster->CastSpell(target, SPELL_MAGE_FLAME_ORB_BEAM_DUMMY, true);

                            if (summoner->HasAura(SPELL_MAGE_FROSTFIRE_ORB_RANK_R2))
                                summoner->CastSpell(target, SPELL_MAGE_FROSTFIRE_ORB_DAMAGE_R2, true);
                            else
                                summoner->CastSpell(target, SPELL_MAGE_FROSTFIRE_ORB_DAMAGE_R1, true);
                            break;
                        default:
                            break;
                    }
                }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_mage_flame_orb_aoe_dummy::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_mage_flame_orb_aoe_dummy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    uint32 dummySpellId;
};

// 44445 - Hot Streak
class spell_mage_hot_streak : public AuraScript
{
    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MAGE_HOT_STREAK_TRIGGERED,
                SPELL_MAGE_T12_4P_BONUS,
                SPELL_MAGE_IMPROVED_HOT_STREAK
            });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        if (AuraEffect const* aurEff = GetTarget()->GetDummyAuraEffect(SPELLFAMILY_MAGE, ICON_MAGE_HOT_STREAK, EFFECT_0))
            if (aurEff->GetSpellInfo()->Id == SPELL_MAGE_IMPROVED_HOT_STREAK || aurEff->GetSpellInfo()->GetRank() > 1)
                return false;

        int32 procChance = GetSpellInfo()->Effects[EFFECT_0].CalcValue();
        // T12 4P bonus
        if (AuraEffect const* aurEff = GetTarget()->GetAuraEffect(SPELL_MAGE_T12_4P_BONUS, EFFECT_1))
            procChance += aurEff->GetAmount();

        return roll_chance_i(procChance);
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetCaster()->CastSpell(GetCaster(), SPELL_MAGE_HOT_STREAK_TRIGGERED, aurEff);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_mage_hot_streak::CheckProc);
        OnEffectProc.Register(&spell_mage_hot_streak::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -44446 - Improved Hot Streak
class spell_mage_improved_hot_streak : public AuraScript
{
    bool Load() override
    {
        _critCount = 0;
        return GetCaster()->IsPlayer();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_HOT_STREAK_TRIGGERED });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetDamageInfo()->GetDamageType() != SPELL_DIRECT_DAMAGE)
            return false;

        if (eventInfo.GetDamageInfo()->GetHitMask() & PROC_HIT_CRITICAL)
            _critCount++;
        else
            _critCount = 0;

        if (_critCount == 2)
        {
            _critCount = 0;
            return roll_chance_i(GetSpellInfo()->Effects[EFFECT_0].CalcValue());
        }

        return false;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetCaster()->CastSpell(GetCaster(), SPELL_MAGE_HOT_STREAK_TRIGGERED, aurEff);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_mage_improved_hot_streak::CheckProc);
        OnEffectProc.Register(&spell_mage_improved_hot_streak::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

private:
    uint8 _critCount = 0;
};

// 55342 - Mirror Image
class spell_mage_mirror_image : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MAGE_MIRROR_IMAGE_TRIGGERED_FIRE,
                SPELL_MAGE_MIRROR_IMAGE_TRIGGERED_ARCANE,
                SPELL_MAGE_MIRROR_IMAGE_TRIGGERED_FROST
            });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Player* player = GetHitPlayer();
        if (!player)
            return;

        uint32 spellId = SPELL_MAGE_MIRROR_IMAGE_TRIGGERED_FROST;
        if (player->GetDummyAuraEffect(SPELLFAMILY_MAGE, ICON_MAGE_GLYPH_OF_MIRROR_IMAGE, EFFECT_0))
        {
            if (player->GetPrimaryTalentTree(player->GetActiveSpec()) == TALENT_TREE_MAGE_FIRE)
                spellId = SPELL_MAGE_MIRROR_IMAGE_TRIGGERED_FIRE;
            else if (player->GetPrimaryTalentTree(player->GetActiveSpec()) == TALENT_TREE_MAGE_ARCANE)
                spellId = SPELL_MAGE_MIRROR_IMAGE_TRIGGERED_ARCANE;
        }

        player->CastSpell(player, spellId, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_mage_mirror_image::HandleDummyEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

class spell_mage_mirror_image_AurasScript : public AuraScript
{
    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() == 1)
            GetTarget()->CastSpell(GetTarget(), GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_mage_mirror_image_AurasScript::HandleEffectPeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class SummonerCheck
{
    public:
        SummonerCheck(Unit* _summoner) : summoner(_summoner)  { }

        bool operator()(WorldObject* object)
        {
            if (Unit* unit = object->ToUnit())
                if (TempSummon* summon = unit->ToTempSummon())
                    return (summon->GetSummoner() && summon->GetSummoner() != summoner);

            return false;
        }

    private:
        Unit* summoner;
};

class spell_mage_initialize_images : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(SummonerCheck(GetCaster()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_mage_initialize_images::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_mage_deep_freeze : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_DEEP_FREEZE_DAMAGE });
    }

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetExplTargetUnit();
        if (!target)
            return;

        if (target->GetTypeId() == TYPEID_UNIT)
            if (target->IsImmunedToSpell(GetSpellInfo(), caster))
                caster->CastSpell(target, SPELL_MAGE_DEEP_FREEZE_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectLaunch.Register(&spell_mage_deep_freeze::HandleDamage, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// -34293 - Pyromaniac
class spell_mage_pyromaniac : public AuraScript
{
    bool Load() override
    {
        _buffActive = false;
        return true;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_PYROMANIAC_TRIGGERED });
    }

    void CalcPeriodic(AuraEffect const* /*aurEff*/, bool& isPeriodic, int32& amplitude)
    {
        isPeriodic = true;
        amplitude = 1 * IN_MILLISECONDS;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        _dotTargetGuids.insert(eventInfo.GetProcTarget()->GetGUID());

        // Pyomaniac is active already so there is no need to iterate through potential targets
        if (_buffActive)
            return;

        Unit* target = GetTarget();
        CleanDotTargets(target);

        if (_dotTargetGuids.size() >= 3)
        {
            target->CastSpell(target, SPELL_MAGE_PYROMANIAC_TRIGGERED, CastSpellExtraArgs(aurEff).AddSpellBP0(aurEff->GetAmount()));
            _buffActive = true;
        }
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        // Buff is not active right now so there is no need to check targets
        if (!_buffActive)
            return;

        Unit* target = GetTarget();
        CleanDotTargets(target);

        if (_dotTargetGuids.size() < 3)
        {
            target->RemoveAurasDueToSpell(SPELL_MAGE_PYROMANIAC_TRIGGERED);
            _buffActive = false;
        }
    }

    void Register() override
    {
        DoEffectCalcPeriodic.Register(&spell_mage_pyromaniac::CalcPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc.Register(&spell_mage_pyromaniac::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectPeriodic.Register(&spell_mage_pyromaniac::HandlePeriodic, EFFECT_0, SPELL_AURA_DUMMY);
    }
private:
    GuidSet _dotTargetGuids;
    bool _buffActive;

    void CleanDotTargets(Unit* caster)
    {
        GuidSet guids = _dotTargetGuids;
        for (ObjectGuid guid : guids)
            if (!IsValidDotTarget(caster, guid))
                _dotTargetGuids.erase(guid);
    }

    bool IsValidDotTarget(Unit* caster, ObjectGuid guid) const
    {
        Unit* target = ObjectAccessor::GetUnit(*caster, guid);
        if (!target)
            return false;

        std::list<AuraEffect*> dotAuraEffects = target->GetAuraEffectsByType(SPELL_AURA_PERIODIC_DAMAGE);
        if (dotAuraEffects.empty())
            return false;

        for (AuraEffect const* effect : dotAuraEffects)
            if (effect->GetCasterGUID() == caster->GetGUID() && effect->GetSpellInfo()->SpellFamilyFlags[2] & 0x00000008)
                return true;

        return true;
    }
};

// -11103 - Impact
class spell_mage_impact : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_FIRE_BLAST });
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        GetTarget()->GetSpellHistory()->ResetCooldown(SPELL_MAGE_FIRE_BLAST, true);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_mage_impact::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 12355 - Impact
class spell_mage_impact_triggered : public SpellScript
{
    void RegisterFireDots(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetExplTargetUnit();
        Unit* launchTarget = GetHitUnit();
        if (!target || !caster || target != launchTarget)
            return;

        std::list<AuraEffect*> dotAuraEffects = target->GetAuraEffectsByType(SPELL_AURA_PERIODIC_DAMAGE);
        if (dotAuraEffects.empty())
            return;

        for (AuraEffect const* effect : dotAuraEffects)
            if (effect->GetCasterGUID() == caster->GetGUID() && effect->GetSpellInfo()->SpellFamilyFlags[2] & 0x00000008)
                _fireDotEffects.push_back(effect->GetBase());
    }

    void SpeadFireDots(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (GetExplTargetUnit() == GetHitUnit())
            return;

        for (Aura* aura : _fireDotEffects)
        {
            if (Aura* addAura = caster->AddAura(aura->GetSpellInfo()->Id, GetHitUnit()))
            {
                for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                    if (AuraEffect* originalEffect = aura->GetEffect(i))
                        if (AuraEffect* effect = addAura->GetEffect(i))
                            effect->SetAmount(originalEffect->GetAmount());

                addAura->SetDuration(aura->GetDuration());
            }
        }
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_mage_impact_triggered::RegisterFireDots, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectHitTarget.Register(&spell_mage_impact_triggered::SpeadFireDots, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
private:
    std::vector<Aura*> _fireDotEffects;
};

// 11129 - Combustion
class spell_mage_combustion : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_COMBUSTION_DAMAGE });
    }

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetHitUnit();

        int32 basePoints = 0;
        float scalingFactor = static_cast<float>(GetEffectValue());

        for (AuraEffect const* aurEff : target->GetAuraEffectsByType(SPELL_AURA_PERIODIC_DAMAGE))
        {
            if (aurEff->GetCasterGUID() != caster->GetGUID()
                || !(aurEff->GetSpellInfo()->GetSchoolMask() & SPELL_SCHOOL_MASK_FIRE)
                || aurEff->GetSpellInfo()->SpellFamilyName != SPELLFAMILY_MAGE)
                continue;

            // Only combine auras specified in the script effect's class mask
            if (!aurEff->GetSpellInfo()->IsAffected(SPELLFAMILY_MAGE, GetSpellInfo()->Effects[effIndex].SpellClassMask))
                continue;

            basePoints = CalculatePct(aurEff->GetAmount(), scalingFactor);
            if (basePoints > 0)
                caster->CastSpell(target, SPELL_MAGE_COMBUSTION_DAMAGE, CastSpellExtraArgs(true).AddSpellBP0(basePoints));
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_mage_combustion::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 44614 - Frostfire Bolt
class spell_mage_frostfire_bolt : public SpellScript
{
    void HandleGlyphSlow(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Aura* aura = GetHitAura())
        {
            if (AuraEffect* effect = aura->GetEffect(effIndex))
            {
                if (caster->GetDummyAuraEffect(SPELLFAMILY_MAGE, ICON_MAGE_GLYPH_OF_FROSTFIRE, EFFECT_2))
                    effect->SetAmount(0);
                else
                    effect->SetAmount(GetSpellInfo()->Effects[effIndex].CalcValue());
            }
        }
    }

    void HandleGlyphDot(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            if (!caster->GetDummyAuraEffect(SPELLFAMILY_MAGE, ICON_MAGE_GLYPH_OF_FROSTFIRE, EFFECT_2))
                if (Aura* aura = GetHitAura())
                    if (AuraEffect* effect = aura->GetEffect(effIndex))
                        effect->SetAmount(0);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_mage_frostfire_bolt::HandleGlyphSlow, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        OnEffectHitTarget.Register(&spell_mage_frostfire_bolt::HandleGlyphDot, EFFECT_2, SPELL_EFFECT_APPLY_AURA);
    }
};

void AddSC_mage_spell_scripts()
{
    RegisterSpellScript(spell_mage_arcane_missiles_trigger);
    RegisterSpellScript(spell_mage_arcane_potency);
    RegisterSpellScript(spell_mage_blast_wave);
    RegisterSpellScript(spell_mage_blazing_speed);
    RegisterSpellScript(spell_mage_blizzard);
    RegisterSpellScript(spell_mage_cold_snap);
    RegisterSpellScript(spell_mage_combustion);
    RegisterSpellScript(spell_mage_cone_of_cold);
    RegisterSpellScript(spell_mage_conjure_refreshment);
    RegisterSpellScript(spell_mage_deep_freeze);
    RegisterSpellScript(spell_mage_dragon_breath);
    RegisterSpellScript(spell_mage_early_frost);
    RegisterSpellScript(spell_mage_flame_orb);
    RegisterSpellScript(spell_mage_flame_orb_aoe_dummy);
    RegisterSpellScript(spell_mage_focus_magic);
    RegisterSpellScript(spell_mage_frostbolt);
    RegisterSpellScript(spell_mage_frostfire_bolt);
    RegisterSpellScript(spell_mage_hot_streak);
    RegisterSpellScript(spell_mage_ice_barrier);
    RegisterSpellScript(spell_mage_ice_block);
    RegisterSpellScript(spell_mage_icy_veins);
    RegisterSpellScript(spell_mage_ignite);
    RegisterSpellScript(spell_mage_ignite_periodic);
    RegisterSpellScript(spell_mage_impact);
    RegisterSpellScript(spell_mage_impact_triggered);
    RegisterSpellScript(spell_mage_improved_hot_streak);
    RegisterSpellScript(spell_mage_initialize_images);
    RegisterSpellScript(spell_mage_living_bomb);
    RegisterSpellScript(spell_mage_mage_ward);
    RegisterSpellScript(spell_mage_mana_shield);
    RegisterSpellScript(spell_mage_master_of_elements);
    RegisterSpellAndAuraScriptPair(spell_mage_mirror_image, spell_mage_mirror_image_AurasScript);
    RegisterSpellScript(spell_mage_nether_vortex);
    RegisterSpellScript(spell_mage_offensive_state_dnd);
    RegisterSpellScript(spell_mage_permafrost);
    RegisterSpellScript(spell_mage_polymorph);
    RegisterSpellScript(spell_mage_pyromaniac);
    RegisterSpellScript(spell_mage_replenish_mana);
    RegisterSpellScript(spell_mage_ring_of_frost);
    RegisterSpellAndAuraScriptPair(spell_mage_ring_of_frost_freeze, spell_mage_ring_of_frost_freeze_AuraScript);
    RegisterSpellScript(spell_mage_time_warp);
    RegisterSpellScript(spell_mage_water_elemental_freeze);
}
