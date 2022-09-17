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
    SPELL_HUNTER_BESTIAL_WRATH                      = 19574,
    SPELL_HUNTER_CALL_PET_1                         = 883,
    SPELL_HUNTER_CALL_PET_2                         = 83242,
    SPELL_HUNTER_CALL_PET_3                         = 83243,
    SPELL_HUNTER_CALL_PET_4                         = 83244,
    SPELL_HUNTER_CALL_PET_5                         = 83245,
    SPELL_HUNTER_CAMOUFLAGE_DURATION                = 51755,
    SPELL_HUNTER_CAMOUFLAGE_PERIODIC                = 80326,
    SPELL_HUNTER_CAMOUFLAGE_PERIODIC_TRIGGERED      = 80325,
    SPELL_HUNTER_CHIMERA_SHOT                       = 53209,
    SPELL_HUNTER_CHIMERA_SHOT_HEAL                  = 53353,
    SPELL_HUNTER_DISENGAGE                          = 781,
    SPELL_HUNTER_DETERRENCE                         = 19263,
    SPELL_HUNTER_FERVOR_PET_ENERGIZE                = 82728,
    SPELL_HUNTER_FIRE                               = 82926,
    SPELL_HUNTER_FRENZY_EFFECT                      = 19615,
    SPELL_HUNTER_FOCUS_FIRE_ENERGIZE                = 83468,
    SPELL_HUNTER_FOCUS_FIRE_DUMMY                   = 88843,
    SPELL_HUNTER_FOCUS_FIRE                         = 82692,
    SPELL_HUNTER_GENERIC_ENERGIZE_FOCUS             = 91954,
    SPELL_HUNTER_IMPROVED_MEND_PET                  = 24406,
    SPELL_HUNTER_IMPROVED_SERPENT_STING_DAMAGE      = 83077,
    SPELL_HUNTER_INSANITY                           = 95809,
    SPELL_HUNTER_INVIGORATION_TRIGGERED             = 53398,
    SPELL_HUNTER_GLYPH_OF_KILL_SHOT_COOLDOWN        = 90967,
    SPELL_HUNTER_KILLING_STREAK_TRIGGERED_R1        = 94006,
    SPELL_HUNTER_KILLING_STREAK_TRIGGERED_R2        = 94007,
    SPELL_HUNTER_LOCK_AND_LOAD                      = 56453,
    SPELL_HUNTER_MARKED_FOR_DEATH_TRIGGERED         = 88691,
    SPELL_HUNTER_MASTERS_CALL_TRIGGERED             = 62305,
    SPELL_HUNTER_MISDIRECTION                       = 34477,
    SPELL_HUNTER_MISDIRECTION_PROC                  = 35079,
    SPELL_HUNTER_PET_LAST_STAND_TRIGGERED           = 53479,
    SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX           = 55709,
    SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED = 54114,
    SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF    = 55711,
    SPELL_HUNTER_PET_CARRION_FEEDER_TRIGGERED       = 54045,
    SPELL_HUNTER_PIERCING_SHOTS                     = 63468,
    SPELL_HUNTER_RAPID_RECUPERATION                 = 58883,
    SPELL_HUNTER_READINESS                          = 23989,
    SPELL_HUNTER_SIC_EM_R1                          = 83359,
    SPELL_HUNTER_SIC_EM_R2                          = 89388,
    SPELL_HUNTER_STEADY_SHOT                        = 56641,
    SPELL_HUNTER_STEADY_SHOT_FOCUS                  = 77443,
    SPELL_HUNTER_TRAP_LAUNCHER_LINKED               = 82946,
    SPELL_HUNTER_IMPROVED_STEADY_SHOT_TRIGGERED     = 53220,
    SPELL_HUNTER_THRILL_OF_THE_HUNT                 = 34720,
    SPELL_HUNTER_WILD_QUIVER_DAMAGE                 = 76663,
    SPELL_LOCK_AND_LOAD_MARKER                      = 67544
};

enum HunterIcons
{
    HUNTER_ICON_ID_INVIGORATION             = 3487,
    HUNTER_ICON_ID_IMPROVED_SERPPENT_STING  = 536,
    HUNTER_ICON_ID_TERMINATION              = 2008,
    HUNTER_ICON_ID_GLYPH_OF_DAZZLED_PREY    = 2109
};

enum MiscSpells
{
    SPELL_DRAENEI_GIFT_OF_THE_NAARU                 = 59543,
    SPELL_MAGE_TEMPORAL_DISPLACEMENT                = 80354,
    SPELL_SHAMAN_EXHAUSTION                         = 57723,
    SPELL_SHAMAN_SATED                              = 57724
};

// 90355 - Ancient Hysteria
class spell_hun_ancient_hysteria : public SpellScript
{
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
        OnObjectAreaTargetSelect.Register(&spell_hun_ancient_hysteria::RemoveInvalidTargets, EFFECT_ALL, TARGET_UNIT_CASTER_AREA_RAID);
        AfterHit.Register(&spell_hun_ancient_hysteria::ApplyDebuff);
    }
};

// Universal helper to get the serpent sting aura of all variants of it (original and the procced versions of Serpent Spread)
static Aura* GetSerpentStingAura(Unit* target, ObjectGuid casterGUID)
{
    if (AuraEffect* aurff = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_HUNTER, 0x4000, 0, 0, casterGUID))
        return aurff->GetBase();

    return nullptr;
}

// 53209 - Chimera Shot
class spell_hun_chimera_shot : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_CHIMERA_SHOT_HEAL });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(nullptr, SPELL_HUNTER_CHIMERA_SHOT_HEAL, true);

        if (Aura* serpentSting = GetSerpentStingAura(GetHitUnit(), caster->GetGUID()))
            serpentSting->RefreshDuration();
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_hun_chimera_shot::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 77767 - Cobra Shot
class spell_hun_cobra_shot : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_GENERIC_ENERGIZE_FOCUS });
    }

    void HandleLaunch(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        int32 focusAmount = sSpellMgr->AssertSpellInfo(SPELL_HUNTER_GENERIC_ENERGIZE_FOCUS)->Effects[EFFECT_0].CalcValue();

        if (Unit* target = GetExplTargetUnit())
        {
            if (AuraEffect const* termination = caster->GetDummyAuraEffect(SPELLFAMILY_HUNTER, HUNTER_ICON_ID_TERMINATION, EFFECT_0))
                if (target->GetHealthPct() < termination->GetSpellInfo()->Effects[EFFECT_1].CalcValue())
                    focusAmount += termination->GetAmount();

            if (AuraEffect const* dazzledPrey = caster->GetDummyAuraEffect(SPELLFAMILY_HUNTER, HUNTER_ICON_ID_GLYPH_OF_DAZZLED_PREY, EFFECT_0))
                if (target->HasAuraWithMechanic(1 << MECHANIC_DAZE))
                    focusAmount += dazzledPrey->GetAmount();
        }

        caster->CastSpell(caster, SPELL_HUNTER_GENERIC_ENERGIZE_FOCUS, CastSpellExtraArgs(true).AddSpellBP0(focusAmount));
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Aura* aur = GetSerpentStingAura(GetHitUnit(), GetCaster()->GetGUID()))
        {
            int32 newDuration = aur->GetDuration() + GetEffectValue() * IN_MILLISECONDS;
            aur->SetDuration(std::min(newDuration, aur->GetMaxDuration()), true);
        }
    }

    void Register() override
    {
        OnEffectLaunch.Register(&spell_hun_cobra_shot::HandleLaunch, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectHitTarget.Register(&spell_hun_cobra_shot::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 781 - Disengage
class spell_hun_disengage : public SpellScript
{
    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (caster->GetTypeId() == TYPEID_PLAYER && !caster->IsInCombat())
            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_hun_disengage::CheckCast);
    }
};

// -19572 - Improved Mend Pet
class spell_hun_improved_mend_pet : public AuraScript
{
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
        DoCheckProc.Register(&spell_hun_improved_mend_pet::CheckProc);
        OnEffectProc.Register(&spell_hun_improved_mend_pet::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 53412 - Invigoration
class spell_hun_invigoration : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_INVIGORATION_TRIGGERED });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (AuraEffect* aurEff = target->GetDummyAuraEffect(SPELLFAMILY_HUNTER, HUNTER_ICON_ID_INVIGORATION, EFFECT_0))
            target->CastSpell(target, SPELL_HUNTER_INVIGORATION_TRIGGERED, CastSpellExtraArgs(aurEff).AddSpellBP0(aurEff->GetAmount()));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_hun_invigoration::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 53478 - Last Stand Pet
class spell_hun_last_stand_pet : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_PET_LAST_STAND_TRIGGERED });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        int32 healthModSpellBasePoints0 = int32(caster->CountPctFromMaxHealth(30));
        caster->CastSpell(caster, SPELL_HUNTER_PET_LAST_STAND_TRIGGERED, CastSpellExtraArgs(true).AddSpellBP0(healthModSpellBasePoints0));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_hun_last_stand_pet::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// -56342 - Lock and Load
class spell_hun_lock_and_load : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LOCK_AND_LOAD_MARKER });
    }

    void HandleProcs(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        if (!roll_chance_i(aurEff->GetAmount()))
            return;

        Unit* actor = eventInfo.GetActor();
        actor->CastSpell(nullptr, GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, true);
        actor->CastSpell(nullptr, SPELL_LOCK_AND_LOAD_MARKER, true);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_hun_lock_and_load::HandleProcs, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 53271 - Masters Call
class spell_hun_masters_call : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_MASTERS_CALL_TRIGGERED, uint32(spellInfo->Effects[EFFECT_0].CalcValue()) });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* ally = GetHitUnit())
            if (Player* caster = GetCaster()->ToPlayer())
                if (Pet* target = caster->GetPet())
                    target->CastSpell(ally, GetEffectValue(), TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_CASTER_AURASTATE));
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
        OnEffectHitTarget.Register(&spell_hun_masters_call::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget.Register(&spell_hun_masters_call::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 34477 - Misdirection
class spell_hun_misdirection : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_MISDIRECTION_PROC });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::ByDefault) || !GetTarget()->HasAura(SPELL_HUNTER_MISDIRECTION_PROC))
            GetTarget()->GetThreatManager().UnregisterRedirectThreat(SPELL_HUNTER_MISDIRECTION);
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_MISDIRECTION_PROC, aurEff);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_hun_misdirection::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectProc.Register(&spell_hun_misdirection::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 35079 - Misdirection (Proc)
class spell_hun_misdirection_proc : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_MISDIRECTION });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->GetThreatManager().UnregisterRedirectThreat(SPELL_HUNTER_MISDIRECTION);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_hun_misdirection_proc::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 54044 - Pet Carrion Feeder
class spell_hun_pet_carrion_feeder : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsPet();
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
        OnEffectHit.Register(&spell_hun_pet_carrion_feeder::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnCheckCast.Register(&spell_hun_pet_carrion_feeder::CheckIfCorpseNear);
    }
};

// 55709 - Pet Heart of the Phoenix
class spell_hun_pet_heart_of_the_phoenix : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsPet();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED,
                SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF
            });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* owner = caster->GetOwner())
            if (!caster->HasAura(SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF))
            {
                owner->CastSpell(caster, SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED, CastSpellExtraArgs(true).AddSpellBP0(100));
                caster->CastSpell(caster, SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF, true);
            }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_hun_pet_heart_of_the_phoenix::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// -53228 - Rapid Recuperation
class spell_hun_rapid_recuperation : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_RAPID_RECUPERATION });
    }

    void HandleAbilityCast(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        // This effect may only trigger from Rapid Fire
        if (!(eventInfo.GetDamageInfo()->GetSpellInfo()->SpellFamilyFlags[0] & 0x20))
            PreventDefaultAction();
    }

    void HandleFocusRegen(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        // This effect may only trigger from Rapid Killing
        if (!(eventInfo.GetDamageInfo()->GetSpellInfo()->SpellFamilyFlags[1] & 0x01000000))
            return;

        int32 focus = aurEff->GetAmount();
        GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_RAPID_RECUPERATION, CastSpellExtraArgs(aurEff).AddSpellBP0(focus));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_hun_rapid_recuperation::HandleAbilityCast, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        OnEffectProc.Register(&spell_hun_rapid_recuperation::HandleFocusRegen, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 23989 - Readiness
class spell_hun_readiness : public SpellScript
{
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
        OnEffectHitTarget.Register(&spell_hun_readiness::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 82925 - Ready, Set, Aim...
class spell_hun_ready_set_aim : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_FIRE });
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetStackAmount() == 5)
        {
            GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_FIRE, aurEff);
            Remove();
        }
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_hun_ready_set_aim::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 37506 - Scatter Shot
class spell_hun_scatter_shot : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsPlayer();
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
        OnEffectHitTarget.Register(&spell_hun_scatter_shot::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// -53302 - Sniper Training
static std::array<uint32, 3> SnaperTrainingSpells = { 64418, 64419, 64420 };

class spell_hun_sniper_training : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(SnaperTrainingSpells);
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        Unit* target = GetTarget();
        bool hasMoved = _previousPosition.GetExactDist(target->GetPosition()) >= 0.01f;

        if (!hasMoved && _ticksWhileStationary < aurEff->GetAmount())
            ++_ticksWhileStationary;
        else if (hasMoved)
            _ticksWhileStationary = 0;

        _previousPosition = target->GetPosition();

        if (_ticksWhileStationary == aurEff->GetAmount())
        {
            uint8 index = aurEff->GetSpellInfo()->GetRank() - 1;
            target->CastSpell(nullptr, SnaperTrainingSpells[index], true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_hun_sniper_training::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
private:
    Position _previousPosition;
    uint8 _ticksWhileStationary = 0;
};

// 56641 - Steady Shot
class spell_hun_steady_shot : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_STEADY_SHOT_FOCUS });
    }

    void HandleLaunch(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        int32 focusAmount = sSpellMgr->AssertSpellInfo(SPELL_HUNTER_STEADY_SHOT_FOCUS)->Effects[EFFECT_0].CalcValue();

        if (Unit* target = GetExplTargetUnit())
        {
            if (AuraEffect const* termination = caster->GetDummyAuraEffect(SPELLFAMILY_HUNTER, HUNTER_ICON_ID_TERMINATION, EFFECT_0))
                if (target->GetHealthPct() < termination->GetSpellInfo()->Effects[EFFECT_1].CalcValue())
                    focusAmount += termination->GetAmount();

            if (AuraEffect const* dazzledPrey = caster->GetDummyAuraEffect(SPELLFAMILY_HUNTER, HUNTER_ICON_ID_GLYPH_OF_DAZZLED_PREY, EFFECT_0))
                if (target->HasAuraWithMechanic(1 << MECHANIC_DAZE))
                    focusAmount += dazzledPrey->GetAmount();
        }

        caster->CastSpell(caster, SPELL_HUNTER_STEADY_SHOT_FOCUS, CastSpellExtraArgs(true).AddSpellBP0(focusAmount));
    }

    void Register() override
    {
        OnEffectLaunch.Register(&spell_hun_steady_shot::HandleLaunch, EFFECT_0, SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
    }
};

// -53221 - Improved Steady Shot
class spell_hun_improved_steady_shot : public AuraScript
{
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
                GetCaster()->CastSpell(GetCaster(), SPELL_HUNTER_IMPROVED_STEADY_SHOT_TRIGGERED, CastSpellExtraArgs(aurEff).AddSpellBP0(aurEff->GetAmount()));
                _steadyShotCounter = 0;
            }
        }
        else
            _steadyShotCounter = 0;
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_hun_improved_steady_shot::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

private:
    uint8 _steadyShotCounter = 0;
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
class spell_hun_tame_beast : public SpellScript
{
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

            if (player->GetCharmedGUID())
                return SendTameFailResult(PET_TAME_FAILURE_CREATURE_CONTROLLED);
        }
        else
            return SendTameFailResult(PET_TAME_FAILURE_NOT_TAMEABLE);

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_hun_tame_beast::CheckCast);
    }
};

//  53434 - Call of the Wild
class spell_hun_target_only_pet_and_owner : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.clear();
        targets.push_back(GetCaster());
        if (Unit* owner = GetCaster()->GetOwner())
            targets.push_back(owner);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_hun_target_only_pet_and_owner::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_PARTY);
        OnObjectAreaTargetSelect.Register(&spell_hun_target_only_pet_and_owner::FilterTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_PARTY);
    }
};

// 34497 - Thrill of the Hunt
class spell_hun_thrill_of_the_hunt : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_THRILL_OF_THE_HUNT });
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        int32 focus = eventInfo.GetDamageInfo()->GetSpellInfo()->CalcPowerCost(GetTarget(), SpellSchoolMask(eventInfo.GetDamageInfo()->GetSchoolMask()));
        focus = CalculatePct(focus, aurEff->GetAmount());

        GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_THRILL_OF_THE_HUNT, CastSpellExtraArgs(aurEff).AddSpellBP0(focus));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_hun_thrill_of_the_hunt::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -56333 - T.N.T.
class spell_hun_tnt : public AuraScript
{
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
        GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_LOCK_AND_LOAD, aurEff);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_hun_tnt::CheckProc);
        OnEffectProc.Register(&spell_hun_tnt::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 76659 - Wild Quiver
class spell_hun_wild_quiver : public AuraScript
{
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
                caster->CastSpell(target, SPELL_HUNTER_WILD_QUIVER_DAMAGE, aurEff);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_hun_wild_quiver::CheckProc);
        OnEffectProc.Register(&spell_hun_wild_quiver::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 1978 - Serpent Sting
class spell_hun_serpent_sting : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_IMPROVED_SERPENT_STING_DAMAGE });
    }

    void HandleImprovedSerpentSting(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (AuraEffect const* improved = caster->GetDummyAuraEffect(SPELLFAMILY_HUNTER, HUNTER_ICON_ID_IMPROVED_SERPPENT_STING, EFFECT_0))
        {
            int32 bp = CalculatePct(aurEff->GetAmount() * aurEff->GetTotalTicks(), improved->GetAmount());
            caster->CastSpell(GetTarget(), SPELL_HUNTER_IMPROVED_SERPENT_STING_DAMAGE, CastSpellExtraArgs(improved).AddSpellBP0(bp));
        }
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_hun_serpent_sting::HandleImprovedSerpentSting, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// -53234 - Piercing Shots
class spell_hun_piercing_shots : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_PIERCING_SHOTS });
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        int32 bp = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount());
        if (!bp)
            return;

        bp /= std::max<uint32>(sSpellMgr->AssertSpellInfo(SPELL_HUNTER_PIERCING_SHOTS)->GetMaxTicks(), 1);

        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_HUNTER_PIERCING_SHOTS, CastSpellExtraArgs(aurEff).AddSpellBP0(bp));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_hun_piercing_shots::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

class spell_hun_trap_launcher : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_IMPROVED_STEADY_SHOT_TRIGGERED });
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_IMPROVED_STEADY_SHOT_TRIGGERED, aurEff);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_HUNTER_IMPROVED_STEADY_SHOT_TRIGGERED);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_hun_trap_launcher::AfterApply, EFFECT_0, SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS_TRIGGERED, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_hun_trap_launcher::AfterRemove, EFFECT_0, SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS_TRIGGERED, AURA_EFFECT_HANDLE_REAL);
    }
};

// 63067 - Glyph of Kill Shot
class spell_hun_glyph_of_kill_shot : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_GLYPH_OF_KILL_SHOT_COOLDOWN });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return (!GetTarget()->HasAura(SPELL_HUNTER_GLYPH_OF_KILL_SHOT_COOLDOWN) && eventInfo.GetDamageInfo() && eventInfo.GetSpellInfo());
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();
        DamageInfo* damage = eventInfo.GetDamageInfo();
        Unit* victim = damage->GetVictim();
        SpellInfo const* spell = eventInfo.GetSpellInfo();

        if (damage->GetDamage() < victim->GetHealth())
        {
            target->GetSpellHistory()->ResetCooldown(spell->Id, true);
            target->CastSpell(target, SPELL_HUNTER_GLYPH_OF_KILL_SHOT_COOLDOWN, aurEff);
        }
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_hun_glyph_of_kill_shot::CheckProc);
        OnEffectProc.Register(&spell_hun_glyph_of_kill_shot::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 51753 - Camouflage
class spell_hun_camouflage : public SpellScript
{
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
        OnEffectHitTarget.Register(&spell_hun_camouflage::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 51755 - Camouflage
class spell_hun_camouflage_duration : public AuraScript
{
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
        GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_CAMOUFLAGE_PERIODIC, aurEff);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_HUNTER_CAMOUFLAGE_PERIODIC);
        GetTarget()->RemoveAurasDueToSpell(SPELL_HUNTER_CAMOUFLAGE_PERIODIC_TRIGGERED);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_hun_camouflage_duration::AfterApply, EFFECT_0, SPELL_AURA_INTERFERE_TARGETTING, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_hun_camouflage_duration::AfterRemove, EFFECT_0, SPELL_AURA_INTERFERE_TARGETTING, AURA_EFFECT_HANDLE_REAL);
    }
};

// 80325 - Camouflage
class spell_hun_camouflage_triggered : public AuraScript
{
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
        AfterEffectRemove.Register(&spell_hun_camouflage_triggered::AfterRemove, EFFECT_0, SPELL_AURA_MOD_STEALTH, AURA_EFFECT_HANDLE_REAL);
    }
};

// -53241 - Marked for Death
class spell_hun_marked_for_death : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_MARKED_FOR_DEATH_TRIGGERED });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        return (roll_chance_i(GetEffect(EFFECT_0)->GetAmount()));
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_HUNTER_MARKED_FOR_DEATH_TRIGGERED, aurEff);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_hun_marked_for_death::CheckProc);
        OnEffectProc.Register(&spell_hun_marked_for_death::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 82692 - Focus Fire
class spell_hun_focus_fire: public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_HUNTER_FRENZY_EFFECT,
                SPELL_HUNTER_FOCUS_FIRE_ENERGIZE
            });
    }

    SpellCastResult CheckCast()
    {
        Player* player = GetCaster()->ToPlayer();
        Pet* pet = player->GetPet();

        if (!pet)
            return SPELL_FAILED_NO_PET;

        if (!pet->HasAura(SPELL_HUNTER_FRENZY_EFFECT))
            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_hun_focus_fire::CheckCast);
    }
};

class spell_hun_focus_fire_AuraScript : public AuraScript
{
    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
    {
        Player* player = GetUnitOwner()->ToPlayer();
        Pet* pet = player->GetPet();
        if (!pet)
            return;

        if (Aura* frenzy = pet->GetAura(SPELL_HUNTER_FRENZY_EFFECT, pet->GetGUID()))
        {
            _consumedStacks = frenzy->GetStackAmount();
            frenzy->Remove();
            amount = GetSpellInfo()->Effects[aurEff->GetEffIndex()].CalcValue() * _consumedStacks;
        }
        else
            amount = 0;
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (!_consumedStacks)
            return;

        int32 bp = _consumedStacks * aurEff->GetAmount();
        GetTarget()->CastSpell(nullptr, SPELL_HUNTER_FOCUS_FIRE_ENERGIZE,  CastSpellExtraArgs(aurEff).AddSpellBP0(bp));
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_hun_focus_fire_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_RANGED_HASTE);
        AfterEffectApply.Register(&spell_hun_focus_fire_AuraScript::AfterApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
private:
    uint8 _consumedStacks = 0;
};

// 19615 - Frenzy Effect
class spell_hun_frenzy_effect : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_HUNTER_FOCUS_FIRE_DUMMY,
                SPELL_HUNTER_FOCUS_FIRE
            });
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetStackAmount() == GetSpellInfo()->StackAmount)
            if (Unit* owner = GetTarget()->GetOwner())
                if (owner->HasSpell(SPELL_HUNTER_FOCUS_FIRE))
                    owner->CastSpell(owner, SPELL_HUNTER_FOCUS_FIRE_DUMMY, aurEff);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* owner = GetTarget()->GetOwner())
            owner->RemoveAurasDueToSpell(SPELL_HUNTER_FOCUS_FIRE_DUMMY, owner->GetGUID());
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_hun_frenzy_effect::AfterApply, EFFECT_0, SPELL_AURA_MOD_MELEE_HASTE_3, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        AfterEffectRemove.Register(&spell_hun_frenzy_effect::AfterRemove, EFFECT_0, SPELL_AURA_MOD_MELEE_HASTE_3, AURA_EFFECT_HANDLE_REAL);
    }
};

// 34026 - Kill Command
class spell_hun_kill_command: public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    SpellCastResult CheckCast()
    {
        Player* player = GetCaster()->ToPlayer();
        if (Pet* pet = player->GetPet())
        {
            if (!pet->GetVictim())
            {
                GetSpell()->m_customError = SPELL_CUSTOM_ERROR_PET_MUST_BE_ATTACKING;
                return SPELL_FAILED_CUSTOM_ERROR;
            }
        }

        return SPELL_CAST_OK;
    }

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Player* player = caster->ToPlayer();
        if (Pet* pet = player->GetPet())
            if (Unit* target = pet->GetVictim())
                pet->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints, false);
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_hun_kill_command::CheckCast);
        OnEffectHitTarget.Register(&spell_hun_kill_command::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 82726 - Fervor
class spell_hun_fervor : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_FERVOR_PET_ENERGIZE });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Player* player = caster->ToPlayer();
        if (Pet* pet = player->GetPet())
            player->CastSpell(pet, SPELL_HUNTER_FERVOR_PET_ENERGIZE, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_hun_fervor::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_ENERGIZE);
    }
};

std::array<uint32, 2> const KillingStreakTriggerSpells =
{
    SPELL_HUNTER_KILLING_STREAK_TRIGGERED_R1,
    SPELL_HUNTER_KILLING_STREAK_TRIGGERED_R2
};

// -82748 - Killing Streak
class spell_hun_killing_streak : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_HUNTER_KILLING_STREAK_TRIGGERED_R1,
                SPELL_HUNTER_KILLING_STREAK_TRIGGERED_R2
            });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        if (!(eventInfo.GetHitMask() & PROC_HIT_CRITICAL))
            _firstCrit = false;
        else
        {
            if (_firstCrit)
            {
                GetTarget()->CastSpell(GetTarget(), KillingStreakTriggerSpells[GetSpellInfo()->GetRank() - 1], aurEff);
                _firstCrit = false;
            }
            else
                _firstCrit = true;
        }
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_hun_killing_streak::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

private:
    bool _firstCrit = false;
};

// -82898 - Crouching Tiger, Hidden Chimera
class spell_hun_crouching_tiger_hidden_chimera : public AuraScript
{
    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetDamageInfo();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_HUNTER_DISENGAGE,
                SPELL_HUNTER_DETERRENCE
            });
    }

    void HandleDisengageProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        if (eventInfo.GetDamageInfo()->GetAttackType() != BASE_ATTACK && eventInfo.GetDamageInfo()->GetAttackType() != OFF_ATTACK)
            return;

        GetTarget()->GetSpellHistory()->ModifyCooldown(SPELL_HUNTER_DISENGAGE, -aurEff->GetAmount());
    }

    void HandleDeterrenceProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        if (eventInfo.GetDamageInfo()->GetAttackType() != RANGED_ATTACK)
            return;

        GetTarget()->GetSpellHistory()->ModifyCooldown(SPELL_HUNTER_DETERRENCE, -aurEff->GetAmount());
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_hun_crouching_tiger_hidden_chimera::CheckProc);
        OnEffectProc.Register(&spell_hun_crouching_tiger_hidden_chimera::HandleDisengageProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc.Register(&spell_hun_crouching_tiger_hidden_chimera::HandleDeterrenceProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

static std::array<uint32, 2> SicEmSpellIds =
{
    SPELL_HUNTER_SIC_EM_R1,
    SPELL_HUNTER_SIC_EM_R2
};

class spell_hun_sic_em : public AuraScript
{
    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_HUNTER_SIC_EM_R1,
                SPELL_HUNTER_SIC_EM_R2
            });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        if (Player* player = GetTarget()->ToPlayer())
            if (Pet* pet = player->GetPet())
                pet->CastSpell(pet, SicEmSpellIds[GetSpellInfo()->GetRank() - 1], aurEff);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_hun_sic_em::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -87934 - Sperpent Spread
static std::array<uint32, 2> SerpentSpreadSerpentStingSpellIds =
{
    88453,
    88466
};

class spell_hun_serpent_spread : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(SerpentSpreadSerpentStingSpellIds);
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        uint8 index = GetSpellInfo()->GetRank() - 1;
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SerpentSpreadSerpentStingSpellIds[index], CastSpellExtraArgs(aurEff));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_hun_serpent_spread::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

void AddSC_hunter_spell_scripts()
{
    RegisterSpellScript(spell_hun_ancient_hysteria);
    RegisterSpellScript(spell_hun_camouflage);
    RegisterSpellScript(spell_hun_camouflage_duration);
    RegisterSpellScript(spell_hun_camouflage_triggered);
    RegisterSpellScript(spell_hun_chimera_shot);
    RegisterSpellScript(spell_hun_cobra_shot);
    RegisterSpellScript(spell_hun_crouching_tiger_hidden_chimera);
    RegisterSpellScript(spell_hun_disengage);
    RegisterSpellScript(spell_hun_fervor);
    RegisterSpellAndAuraScriptPair(spell_hun_focus_fire, spell_hun_focus_fire_AuraScript);
    RegisterSpellScript(spell_hun_frenzy_effect);
    RegisterSpellScript(spell_hun_glyph_of_kill_shot);
    RegisterSpellScript(spell_hun_improved_mend_pet);
    RegisterSpellScript(spell_hun_invigoration);
    RegisterSpellScript(spell_hun_killing_streak);
    RegisterSpellScript(spell_hun_kill_command);
    RegisterSpellScript(spell_hun_last_stand_pet);
    RegisterSpellScript(spell_hun_lock_and_load);
    RegisterSpellScript(spell_hun_marked_for_death);
    RegisterSpellScript(spell_hun_masters_call);
    RegisterSpellScript(spell_hun_misdirection);
    RegisterSpellScript(spell_hun_misdirection_proc);
    RegisterSpellScript(spell_hun_pet_carrion_feeder);
    RegisterSpellScript(spell_hun_pet_heart_of_the_phoenix);
    RegisterSpellScript(spell_hun_piercing_shots);
    RegisterSpellScript(spell_hun_rapid_recuperation);
    RegisterSpellScript(spell_hun_readiness);
    RegisterSpellScript(spell_hun_ready_set_aim);
    RegisterSpellScript(spell_hun_scatter_shot);
    RegisterSpellScript(spell_hun_serpent_sting);
    RegisterSpellScript(spell_hun_serpent_spread);
    RegisterSpellScript(spell_hun_sic_em);
    RegisterSpellScript(spell_hun_sniper_training);
    RegisterSpellScript(spell_hun_steady_shot);
    RegisterSpellScript(spell_hun_improved_steady_shot);
    RegisterSpellScript(spell_hun_tame_beast);
    RegisterSpellScript(spell_hun_target_only_pet_and_owner);
    RegisterSpellScript(spell_hun_thrill_of_the_hunt);
    RegisterSpellScript(spell_hun_tnt);
    RegisterSpellScript(spell_hun_trap_launcher);
    RegisterSpellScript(spell_hun_wild_quiver);
}
