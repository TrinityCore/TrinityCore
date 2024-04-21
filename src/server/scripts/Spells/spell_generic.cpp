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
 * Scripts for spells with SPELLFAMILY_GENERIC which cannot be included in AI script file
 * of creature using it or can't be bound to any player class.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_gen_"
 */

#include "ScriptMgr.h"
#include "Battleground.h"
#include "BattlePetMgr.h"
#include "CellImpl.h"
#include "CommonPredicates.h"
#include "Containers.h"
#include "CreatureAI.h"
#include "DB2Stores.h"
#include "GameTime.h"
#include "GridNotifiersImpl.h"
#include "Item.h"
#include "Log.h"
#include "MotionMaster.h"
#include "NPCPackets.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "ReputationMgr.h"
#include "SkillDiscovery.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "WorldStateMgr.h"

class spell_gen_absorb0_hitlimit1 : public AuraScript
{
    uint32 limit = 0;

    bool Load() override
    {
        // Max absorb stored in 1 dummy effect
        limit = GetSpellInfo()->GetEffect(EFFECT_1).CalcValue();
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
        if (!eventInfo.GetSpellInfo())
            return false;

        // find Mage Armor
        if (!GetTarget()->GetAuraEffect(SPELL_AURA_MOD_MANA_REGEN_INTERRUPT, SPELLFAMILY_MAGE, flag128(0x10000000, 0x0, 0x0)))
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

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
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
                owner->CastSpell(owner, SPELL_SPAWN_BLOOD_POOL, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectRemoveFn(spell_gen_animal_blood::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_gen_animal_blood::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 63471 - Spawn Blood Pool
class spell_spawn_blood_pool : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        Unit* caster = GetCaster();
        Position summonPos = caster->GetPosition();
        LiquidData liquidStatus;
        if (caster->GetMap()->GetLiquidStatus(caster->GetPhaseShift(), caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), {}, &liquidStatus, caster->GetCollisionHeight()))
            summonPos.m_positionZ = liquidStatus.level;
        dest.Relocate(summonPos);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_spawn_blood_pool::SetDest, EFFECT_0, TARGET_DEST_CASTER);
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
    bool Load() override
    {
        return GetCaster() && GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    bool Validate(SpellInfo const* spellInfo) override
    {
        if (!ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } }) || !spellInfo->GetEffect(EFFECT_0).IsAura(SPELL_AURA_MOD_POWER_REGEN))
        {
            TC_LOG_ERROR("spells", "Aura {} structure has been changed - first aura is no longer SPELL_AURA_MOD_POWER_REGEN", GetId());
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

// 28313 - Aura of Fear
class spell_gen_aura_of_fear : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } }) && ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        if (!roll_chance_i(GetSpellInfo()->ProcChance))
            return;

        GetTarget()->CastSpell(nullptr, aurEff->GetSpellEffectInfo().TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_aura_of_fear::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_gen_av_drekthar_presence : public AuraScript
{
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

// 193970 - Mercenary Shapeshift
class spell_gen_battleground_mercenary_shapeshift : public AuraScript
{
    using OtherFactionRacePriorityList = std::array<Races, 3>;

    inline static std::unordered_map<Races, OtherFactionRacePriorityList> const RaceInfo =
    {
        { RACE_HUMAN, { RACE_UNDEAD_PLAYER, RACE_BLOODELF } },
        { RACE_ORC, { RACE_DWARF } },
        { RACE_DWARF, { RACE_ORC, RACE_UNDEAD_PLAYER, RACE_TAUREN } },
        { RACE_NIGHTELF, { RACE_TROLL, RACE_BLOODELF } },
        { RACE_UNDEAD_PLAYER, { RACE_HUMAN } },
        { RACE_TAUREN, { RACE_DRAENEI, RACE_NIGHTELF } },
        { RACE_GNOME, { RACE_GOBLIN, RACE_BLOODELF } },
        { RACE_TROLL, { RACE_NIGHTELF, RACE_HUMAN, RACE_DRAENEI } },
        { RACE_GOBLIN, { RACE_GNOME, RACE_DWARF } },
        { RACE_BLOODELF, { RACE_HUMAN, RACE_NIGHTELF } },
        { RACE_DRAENEI, { RACE_TAUREN, RACE_ORC } },
        { RACE_WORGEN, { RACE_TROLL } },
        { RACE_PANDAREN_NEUTRAL, { RACE_PANDAREN_NEUTRAL } },
        { RACE_PANDAREN_ALLIANCE, { RACE_PANDAREN_HORDE, RACE_PANDAREN_NEUTRAL } },
        { RACE_PANDAREN_HORDE, { RACE_PANDAREN_ALLIANCE, RACE_PANDAREN_NEUTRAL } },
        { RACE_NIGHTBORNE, { RACE_NIGHTELF, RACE_HUMAN } },
        { RACE_HIGHMOUNTAIN_TAUREN, { RACE_DRAENEI, RACE_NIGHTELF } },
        { RACE_VOID_ELF, { RACE_TROLL, RACE_BLOODELF } },
        { RACE_LIGHTFORGED_DRAENEI, { RACE_TAUREN, RACE_ORC } },
        { RACE_ZANDALARI_TROLL, { RACE_KUL_TIRAN, RACE_HUMAN } },
        { RACE_KUL_TIRAN, { RACE_ZANDALARI_TROLL } },
        { RACE_DARK_IRON_DWARF, { RACE_MAGHAR_ORC, RACE_ORC } },
        { RACE_VULPERA, { RACE_MECHAGNOME, RACE_DARK_IRON_DWARF /*guessed, for shamans*/ } },
        { RACE_MAGHAR_ORC, { RACE_DARK_IRON_DWARF } },
        { RACE_MECHAGNOME, { RACE_VULPERA } },
    };

    inline static std::unordered_map<Races, std::array<uint32, 2>> const RaceDisplayIds =
    {
        { RACE_HUMAN, { 55239, 55238 } },
        { RACE_ORC, { 55257, 55256 } },
        { RACE_DWARF, { 55241, 55240 } },
        { RACE_NIGHTELF, { 55243, 55242 } },
        { RACE_UNDEAD_PLAYER, { 55259, 55258 } },
        { RACE_TAUREN, { 55261, 55260 } },
        { RACE_GNOME, { 55245, 55244 } },
        { RACE_TROLL, { 55263, 55262 } },
        { RACE_GOBLIN, { 55267, 57244 } },
        { RACE_BLOODELF, { 55265, 55264 } },
        { RACE_DRAENEI, { 55247, 55246 } },
        { RACE_WORGEN, { 55255, 55254 } },
        { RACE_PANDAREN_NEUTRAL, { 55253, 55252 } }, // not verified, might be swapped with RACE_PANDAREN_HORDE
        { RACE_PANDAREN_ALLIANCE, { 55249, 55248 } },
        { RACE_PANDAREN_HORDE, { 55251, 55250 } },
        { RACE_NIGHTBORNE, { 82375, 82376 } },
        { RACE_HIGHMOUNTAIN_TAUREN, { 82377, 82378 } },
        { RACE_VOID_ELF, { 82371, 82372 } },
        { RACE_LIGHTFORGED_DRAENEI, { 82373, 82374 } },
        { RACE_ZANDALARI_TROLL, { 88417, 88416 } },
        { RACE_KUL_TIRAN, { 88414, 88413 } },
        { RACE_DARK_IRON_DWARF, { 88409, 88408 } },
        { RACE_VULPERA, { 94999, 95001 } },
        { RACE_MAGHAR_ORC, { 88420, 88410 } },
        { RACE_MECHAGNOME, { 94998, 95000 } },
    };

    inline static std::vector<uint32> RacialSkills;

    static Races GetReplacementRace(Races nativeRace, Classes playerClass)
    {
        if (OtherFactionRacePriorityList const* otherRaces = Trinity::Containers::MapGetValuePtr(RaceInfo, nativeRace))
            for (Races race : *otherRaces)
                if (sObjectMgr->GetPlayerInfo(race, playerClass))
                    return race;

        return RACE_NONE;
    }

    static uint32 GetDisplayIdForRace(Races race, Gender gender)
    {
        if (std::array<uint32, 2> const* displayIds = Trinity::Containers::MapGetValuePtr(RaceDisplayIds, race))
            return (*displayIds)[gender];

        return 0;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        for (auto const& [race, otherRaces] : RaceInfo)
        {
            if (!sChrRacesStore.LookupEntry(race))
                return false;

            for (Races otherRace : otherRaces)
                if (!sChrRacesStore.LookupEntry(otherRace))
                    return false;
        }

        for (auto const& [race, displayIds] : RaceDisplayIds)
        {
            if (!sChrRacesStore.LookupEntry(race))
                return false;

            for (uint32 displayId : displayIds)
                if (!sCreatureDisplayInfoStore.LookupEntry(displayId))
                    return false;
        }

        RacialSkills.clear();
        for (SkillLineEntry const* skillLine : sSkillLineStore)
            if (skillLine->GetFlags().HasFlag(SkillLineFlags::RacialForThePurposeOfTemporaryRaceChange))
                RacialSkills.push_back(skillLine->ID);

        return true;
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes mode)
    {
        Unit* owner = GetUnitOwner();
        Races otherFactionRace = GetReplacementRace(Races(owner->GetRace()), Classes(owner->GetClass()));
        if (otherFactionRace == RACE_NONE)
            return;

        if (uint32 displayId = GetDisplayIdForRace(otherFactionRace, owner->GetNativeGender()))
            owner->SetDisplayId(displayId);

        if (mode & AURA_EFFECT_HANDLE_REAL)
            UpdateRacials(Races(owner->GetRace()), otherFactionRace);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        Races otherFactionRace = GetReplacementRace(Races(owner->GetRace()), Classes(owner->GetClass()));
        if (otherFactionRace == RACE_NONE)
            return;

        UpdateRacials(otherFactionRace, Races(owner->GetRace()));
    }

    void UpdateRacials(Races oldRace, Races newRace)
    {
        Player* player = GetUnitOwner()->ToPlayer();
        if (!player)
            return;

        for (uint32 racialSkillId : RacialSkills)
        {
            if (sDB2Manager.GetSkillRaceClassInfo(racialSkillId, oldRace, player->GetClass()))
                if (std::vector<SkillLineAbilityEntry const*> const* skillLineAbilities = sDB2Manager.GetSkillLineAbilitiesBySkill(racialSkillId))
                    for (SkillLineAbilityEntry const* ability : *skillLineAbilities)
                        player->RemoveSpell(ability->Spell, false, false);

            if (sDB2Manager.GetSkillRaceClassInfo(racialSkillId, newRace, player->GetClass()))
                player->LearnSkillRewardedSpells(racialSkillId, player->GetMaxSkillValueForLevel(), newRace);
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_gen_battleground_mercenary_shapeshift::HandleApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_SEND_FOR_CLIENT_MASK);
        AfterEffectRemove += AuraEffectApplyFn(spell_gen_battleground_mercenary_shapeshift::HandleRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
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

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
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

enum Bonked
{
    SPELL_BONKED            = 62991,
    SPELL_FOAM_SWORD_DEFEAT = 62994,
    SPELL_ON_GUARD          = 62972
};

class spell_gen_bonked : public SpellScript
{
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

class spell_gen_break_shield: public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ 62552, 62719, 64100, 66482 });
    }

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
                        if (aura->GetId() == 62552 || aura->GetId() == 62719 || aura->GetId() == 64100 || aura->GetId() == 66482)
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
        OnEffectHitTarget += SpellEffectFn(spell_gen_break_shield::HandleScriptEffect, EFFECT_FIRST_FOUND, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 48750 - Burning Depths Necrolyte Image
class spell_gen_burning_depths_necrolyte_image : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_2 } })
            && ValidateSpellInfo({ static_cast<uint32>(spellInfo->GetEffect(EFFECT_2).CalcValue()) });
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), uint32(GetEffectInfo(EFFECT_2).CalcValue()));
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(uint32(GetEffectInfo(EFFECT_2).CalcValue()), GetCasterGUID());
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
        Trinity::AnyDeadUnitSpellTargetInRangeCheck check(caster, max_range, GetSpellInfo(), TARGET_CHECK_ENEMY, TARGET_OBJECT_TYPE_CORPSE_ENEMY);
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

// 66020 Chains of Ice
class spell_gen_chains_of_ice : public AuraScript
{
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

// 28471 - ClearAll
class spell_clear_all : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->RemoveAllAurasOnDeath();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_clear_all::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum Clone
{
    SPELL_NIGHTMARE_FIGMENT_MIRROR_IMAGE        = 57528
};

class spell_gen_clone : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetHitUnit()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        if (m_scriptSpellId == SPELL_NIGHTMARE_FIGMENT_MIRROR_IMAGE)
        {
            OnEffectHitTarget += SpellEffectFn(spell_gen_clone::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
            OnEffectHitTarget += SpellEffectFn(spell_gen_clone::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_DUMMY);
        }
        else
        {
            OnEffectHitTarget += SpellEffectFn(spell_gen_clone::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            OnEffectHitTarget += SpellEffectFn(spell_gen_clone::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
        }
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
                prevItem = target->GetVirtualItemId(0);

                if (Player* player = caster->ToPlayer())
                {
                    if (Item* mainItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND))
                        target->SetVirtualItem(0, mainItem->GetEntry());
                }
                else
                    target->SetVirtualItem(0, caster->GetVirtualItemId(0));
                break;
            }
            case SPELL_COPY_OFFHAND_AURA:
            case SPELL_COPY_OFFHAND_2_AURA:
            {
                prevItem = target->GetVirtualItemId(1);

                if (Player* player = caster->ToPlayer())
                {
                    if (Item* offItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND))
                        target->SetVirtualItem(1, offItem->GetEntry());
                }
                else
                    target->SetVirtualItem(1, caster->GetVirtualItemId(1));
                break;
            }
            case SPELL_COPY_RANGED_AURA:
            {
                prevItem = target->GetVirtualItemId(2);

                if (Player* player = caster->ToPlayer())
                {
                    if (Item* rangedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND))
                        target->SetVirtualItem(2, rangedItem->GetEntry());
                }
                else
                    target->SetVirtualItem(2, caster->GetVirtualItemId(2));
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
                target->SetVirtualItem(0, prevItem);
                break;
            case SPELL_COPY_OFFHAND_AURA:
            case SPELL_COPY_OFFHAND_2_AURA:
                target->SetVirtualItem(1, prevItem);
                break;
            case SPELL_COPY_RANGED_AURA:
                target->SetVirtualItem(2, prevItem);
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

class spell_gen_count_pct_from_max_hp : public SpellScript
{
public:
    spell_gen_count_pct_from_max_hp(int32 damagePct = 0) : SpellScript(), _damagePct(damagePct) { }

    void RecalculateDamage()
    {
        if (!_damagePct)
            _damagePct = GetHitDamage();

        SetHitDamage(GetHitUnit()->CountPctFromMaxHealth(_damagePct));
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_gen_count_pct_from_max_hp::RecalculateDamage);
    }

private:
    int32 _damagePct;
};

// 28865 - Consumption
// 64208 - Consumption
class spell_gen_consumption : public SpellScript
{
    void CalculateDamage(Unit const* /*victim*/, int32& damage, int32& /*flatMod*/, float& /*pctMod*/) const
    {
        if (SpellInfo const* createdBySpell = sSpellMgr->GetSpellInfo(GetCaster()->m_unitData->CreatedBySpell, GetCastDifficulty()))
            damage = createdBySpell->GetEffect(EFFECT_1).CalcValue();
    }

    void Register() override
    {
        CalcDamage += SpellCalcDamageFn(spell_gen_consumption::CalculateDamage);
    }
};

// 63845 - Create Lance
enum CreateLanceSpells
{
    SPELL_CREATE_LANCE_ALLIANCE = 63914,
    SPELL_CREATE_LANCE_HORDE    = 63919
};

class spell_gen_create_lance : public SpellScript
{
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
            else if (target->GetTeam() == HORDE)
                GetCaster()->CastSpell(target, SPELL_CREATE_LANCE_HORDE, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_create_lance::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
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

class spell_gen_dalaran_disguise : public SpellScript
{
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
                    spellId = gender == GENDER_FEMALE ? SPELL_SUNREAVER_DISGUISE_FEMALE : SPELL_SUNREAVER_DISGUISE_MALE;
                    break;
                case SPELL_SILVER_COVENANT_DISGUISE_TRIGGER:
                    spellId = gender == GENDER_FEMALE ? SPELL_SILVER_COVENANT_DISGUISE_FEMALE : SPELL_SILVER_COVENANT_DISGUISE_MALE;
                    break;
                default:
                    break;
            }

            GetCaster()->CastSpell(player, spellId, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_dalaran_disguise::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_gen_decay_over_time_spell : public SpellScript
{
    void ModAuraStack()
    {
        if (Aura* aur = GetHitAura())
            aur->SetStackAmount(static_cast<uint8>(GetSpellInfo()->StackAmount));
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_gen_decay_over_time_spell::ModAuraStack);
    }
};

class spell_gen_decay_over_time_aura : public AuraScript
{
protected:
    spell_gen_decay_over_time_aura() = default;

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
        DoCheckProc += AuraCheckProcFn(spell_gen_decay_over_time_aura::CheckProc);
        OnProc += AuraProcFn(spell_gen_decay_over_time_aura::Decay);
    }
};

enum FungalDecay
{
    // found in sniffs, there is no duration entry we can possibly use
    AURA_DURATION = 12600
};

// 32065 - Fungal Decay
class spell_gen_decay_over_time_fungal_decay : public spell_gen_decay_over_time_aura
{
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
        spell_gen_decay_over_time_aura::Register();
        OnEffectApply += AuraEffectApplyFn(spell_gen_decay_over_time_fungal_decay::ModDuration, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 36659 - Tail Sting
class spell_gen_decay_over_time_tail_sting : public spell_gen_decay_over_time_aura
{
};

enum DefendVisuals
{
    SPELL_VISUAL_SHIELD_1 = 63130,
    SPELL_VISUAL_SHIELD_2 = 63131,
    SPELL_VISUAL_SHIELD_3 = 63132
};

class spell_gen_defend : public AuraScript
{
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
        /*
        SpellInfo const* spell = sSpellMgr->AssertSpellInfo(m_scriptSpellId, DIFFICULTY_NONE);

        // 6.x effects removed

        // Defend spells cast by NPCs (add visuals)
        if (spell->GetEffect(EFFECT_0)->ApplyAuraName == SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN)
        {
            AfterEffectApply += AuraEffectApplyFn(spell_gen_defend::RefreshVisualShields, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            OnEffectRemove += AuraEffectRemoveFn(spell_gen_defend::RemoveVisualShields, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
        }

        // Remove Defend spell from player when he dismounts
        if (spell->GetEffect(EFFECT_2)->ApplyAuraName == SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN)
            OnEffectRemove += AuraEffectRemoveFn(spell_gen_defend::RemoveDummyFromDriver, EFFECT_2, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);

        // Defend spells cast by players (add/remove visuals)
        if (spell->GetEffect(EFFECT_1)->ApplyAuraName == SPELL_AURA_DUMMY)
        {
            AfterEffectApply += AuraEffectApplyFn(spell_gen_defend::RefreshVisualShields, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            OnEffectRemove += AuraEffectRemoveFn(spell_gen_defend::RemoveVisualShields, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
        }
        */
    }
};

class spell_gen_despawn_aura : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
            target->DespawnOrUnsummon();
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_gen_despawn_aura::OnRemove, EFFECT_FIRST_FOUND, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

/// @todo: migrate spells to spell_gen_despawn_target, then remove this
class spell_gen_despawn_self : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (GetEffectInfo().IsEffect(SPELL_EFFECT_DUMMY) || GetEffectInfo().IsEffect(SPELL_EFFECT_SCRIPT_EFFECT))
            GetCaster()->ToCreature()->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_despawn_self::HandleDummy, EFFECT_ALL, SPELL_EFFECT_ANY);
    }
};

class spell_gen_despawn_target : public SpellScript
{
    void HandleDespawn(SpellEffIndex /*effIndex*/)
    {
        if (GetEffectInfo().IsEffect(SPELL_EFFECT_DUMMY) || GetEffectInfo().IsEffect(SPELL_EFFECT_SCRIPT_EFFECT))
            if (Creature* target = GetHitCreature())
                target->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_despawn_target::HandleDespawn, EFFECT_ALL, SPELL_EFFECT_ANY);
    }
};

enum DivineStormSpell
{
    SPELL_DIVINE_STORM      = 53385,
};

// 70769 Divine Storm!
class spell_gen_divine_storm_cd_reset : public SpellScript
{
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
        GetCaster()->GetSpellHistory()->ResetCooldown(SPELL_DIVINE_STORM, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_divine_storm_cd_reset::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_gen_ds_flush_knockback : public SpellScript
{
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
                player->KnockbackFrom(target->GetPosition(), horizontalSpeed, verticalSpeed);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_ds_flush_knockback::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
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
    bool CheckProc(ProcEventInfo& eventInfo)
    {
        uint32 levelDiff = std::abs(GetTarget()->GetLevel() - eventInfo.GetProcTarget()->GetLevel());
        return levelDiff <= 9;
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        std::list<TempSummon*> minionList;
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

// 50101 - Ethereal Pet OnKill Steal Essence
class spell_steal_essence_visual : public AuraScript
{
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

enum Feast
{
    SPELL_GREAT_FEAST                   = 57337,
    SPELL_FISH_FEAST                    = 57397,
    SPELL_GIGANTIC_FEAST                = 58466,
    SPELL_SMALL_FEAST                   = 58475,
    SPELL_BOUNTIFUL_FEAST               = 66477,

    SPELL_FEAST_FOOD                    = 45548,
    SPELL_FEAST_DRINK                   = 57073,
    SPELL_BOUNTIFUL_FEAST_DRINK         = 66041,
    SPELL_BOUNTIFUL_FEAST_FOOD          = 66478,

    SPELL_GREAT_FEAST_REFRESHMENT       = 57338,
    SPELL_FISH_FEAST_REFRESHMENT        = 57398,
    SPELL_GIGANTIC_FEAST_REFRESHMENT    = 58467,
    SPELL_SMALL_FEAST_REFRESHMENT       = 58477,
    SPELL_BOUNTIFUL_FEAST_REFRESHMENT   = 66622
};

/* 57337 - Great Feast
   57397 - Fish Feast
   58466 - Gigantic Feast
   58475 - Small Feast
   66477 - Bountiful Feast */
class spell_gen_feast : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_FEAST_FOOD,
            SPELL_FEAST_DRINK,
            SPELL_BOUNTIFUL_FEAST_DRINK,
            SPELL_BOUNTIFUL_FEAST_FOOD,

            SPELL_GREAT_FEAST_REFRESHMENT,
            SPELL_FISH_FEAST_REFRESHMENT,
            SPELL_GIGANTIC_FEAST_REFRESHMENT,
            SPELL_SMALL_FEAST_REFRESHMENT,
            SPELL_BOUNTIFUL_FEAST_REFRESHMENT
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        switch (GetSpellInfo()->Id)
        {
            case SPELL_GREAT_FEAST:
                target->CastSpell(target, SPELL_FEAST_FOOD);
                target->CastSpell(target, SPELL_FEAST_DRINK);
                target->CastSpell(target, SPELL_GREAT_FEAST_REFRESHMENT);
                break;
            case SPELL_FISH_FEAST:
                target->CastSpell(target, SPELL_FEAST_FOOD);
                target->CastSpell(target, SPELL_FEAST_DRINK);
                target->CastSpell(target, SPELL_FISH_FEAST_REFRESHMENT);
                break;
            case SPELL_GIGANTIC_FEAST:
                target->CastSpell(target, SPELL_FEAST_FOOD);
                target->CastSpell(target, SPELL_FEAST_DRINK);
                target->CastSpell(target, SPELL_GIGANTIC_FEAST_REFRESHMENT);
                break;
            case SPELL_SMALL_FEAST:
                target->CastSpell(target, SPELL_FEAST_FOOD);
                target->CastSpell(target, SPELL_FEAST_DRINK);
                target->CastSpell(target, SPELL_SMALL_FEAST_REFRESHMENT);
                break;
            case SPELL_BOUNTIFUL_FEAST:
                target->CastSpell(target, SPELL_BOUNTIFUL_FEAST_REFRESHMENT);
                target->CastSpell(target, SPELL_BOUNTIFUL_FEAST_DRINK);
                target->CastSpell(target, SPELL_BOUNTIFUL_FEAST_FOOD);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_feast::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*
There are only 3 possible flags Feign Death auras can apply: UNIT_DYNFLAG_DEAD, UNIT_FLAG2_FEIGN_DEATH
and UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT. Some auras can apply only 2 flags

spell_gen_feign_death_all_flags applies all 3 flags
spell_gen_feign_death_all_flags_uninteractible applies all 3 flags and additionally sets UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_UNINTERACTIBLE
spell_gen_feign_death_all_flags_no_uninteractible applies all 3 flags and additionally sets UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC
spell_gen_feign_death_no_dyn_flag applies no UNIT_DYNFLAG_DEAD (does not make the creature appear dead)
spell_gen_feign_death_no_prevent_emotes applies no UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT

REACT_PASSIVE should be handled directly in scripts since not all creatures should be passive. Otherwise
creature will be not able to aggro or execute MoveInLineOfSight events. Removing may cause more issues
than already exists
*/

class spell_gen_feign_death_all_flags : public AuraScript
{
    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetUnitFlag3(UNIT_FLAG3_FAKE_DEAD);
        target->SetUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
        target->SetUnitFlag(UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT);

        if (Creature* creature = target->ToCreature())
            creature->SetReactState(REACT_PASSIVE);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveUnitFlag3(UNIT_FLAG3_FAKE_DEAD);
        target->RemoveUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
        target->RemoveUnitFlag(UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT);

        if (Creature* creature = target->ToCreature())
            creature->InitializeReactState();
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_gen_feign_death_all_flags::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_gen_feign_death_all_flags::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_gen_feign_death_all_flags_uninteractible : public AuraScript
{
    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetUnitFlag3(UNIT_FLAG3_FAKE_DEAD);
        target->SetUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
        target->SetUnitFlag(UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT);
        target->SetImmuneToAll(true);
        target->SetUninteractible(true);

        if (Creature* creature = target->ToCreature())
            creature->SetReactState(REACT_PASSIVE);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveUnitFlag3(UNIT_FLAG3_FAKE_DEAD);
        target->RemoveUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
        target->RemoveUnitFlag(UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT);
        target->SetImmuneToAll(false);
        target->SetUninteractible(false);

        if (Creature* creature = target->ToCreature())
            creature->InitializeReactState();
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_gen_feign_death_all_flags_uninteractible::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_gen_feign_death_all_flags_uninteractible::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 96733 - Permanent Feign Death (Stun)
class spell_gen_feign_death_all_flags_no_uninteractible : public AuraScript
{
    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* target = GetTarget();
        target->SetUnitFlag3(UNIT_FLAG3_FAKE_DEAD);
        target->SetUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
        target->SetUnitFlag(UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT);
        target->SetImmuneToAll(true);

        if (Creature* creature = target->ToCreature())
            creature->SetReactState(REACT_PASSIVE);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* target = GetTarget();
        target->RemoveUnitFlag3(UNIT_FLAG3_FAKE_DEAD);
        target->RemoveUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
        target->RemoveUnitFlag(UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT);
        target->SetImmuneToAll(false);

        if (Creature* creature = target->ToCreature())
            creature->InitializeReactState();
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_gen_feign_death_all_flags_no_uninteractible::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_gen_feign_death_all_flags_no_uninteractible::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 35357 - Spawn Feign Death
// 51329 - Feign Death
class spell_gen_feign_death_no_dyn_flag : public AuraScript
{
    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
        target->SetUnitFlag(UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT);

        if (Creature* creature = target->ToCreature())
            creature->SetReactState(REACT_PASSIVE);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
        target->RemoveUnitFlag(UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT);

        if (Creature* creature = target->ToCreature())
            creature->InitializeReactState();
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_gen_feign_death_no_dyn_flag::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_gen_feign_death_no_dyn_flag::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 58951 - Permanent Feign Death
class spell_gen_feign_death_no_prevent_emotes : public AuraScript
{
    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetUnitFlag3(UNIT_FLAG3_FAKE_DEAD);
        target->SetUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);

        if (Creature* creature = target->ToCreature())
            creature->SetReactState(REACT_PASSIVE);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveUnitFlag3(UNIT_FLAG3_FAKE_DEAD);
        target->RemoveUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);

        if (Creature* creature = target->ToCreature())
            creature->InitializeReactState();
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_gen_feign_death_no_prevent_emotes::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_gen_feign_death_no_prevent_emotes::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

enum FuriousRage
{
    EMOTE_FURIOUS_RAGE       = 19415,
    EMOTE_EXHAUSTED          = 18368,
    SPELL_EXHAUSTION         = 35492
};

// 35491 - Furious Rage
class spell_gen_furious_rage : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EXHAUSTION }) &&
            sBroadcastTextStore.HasRecord(EMOTE_FURIOUS_RAGE) &&
            sBroadcastTextStore.HasRecord(EMOTE_EXHAUSTED);
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->Unit::TextEmote(EMOTE_FURIOUS_RAGE, target, false);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Unit* target = GetTarget();
        target->Unit::TextEmote(EMOTE_EXHAUSTED, target, false);
        target->CastSpell(target, SPELL_EXHAUSTION, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_gen_furious_rage::AfterApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_gen_furious_rage::AfterRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 46642 - 5,000 Gold
class spell_gen_5000_gold : public SpellScript
{
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

enum FishingSpells
{
    SPELL_FISHING_NO_FISHING_POLE   = 131476,
    SPELL_FISHING_WITH_POLE         = 131490
};

// 131474 - Fishing
class spell_gen_fishing : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FISHING_NO_FISHING_POLE, SPELL_FISHING_WITH_POLE });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        uint32 spellId;
        Item* mainHand = GetCaster()->ToPlayer()->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
        if (!mainHand || mainHand->GetTemplate()->GetClass() != ITEM_CLASS_WEAPON || mainHand->GetTemplate()->GetSubClass() != ITEM_SUBCLASS_WEAPON_FISHING_POLE)
            spellId = SPELL_FISHING_NO_FISHING_POLE;
        else
            spellId = SPELL_FISHING_WITH_POLE;

        GetCaster()->CastSpell(GetCaster(), spellId, false);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_fishing::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
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

// 28880 - Warrior
// 59542 - Paladin
// 59543 - Hunter
// 59544 - Priest
// 59545 - Death Knight
// 59547 - Shaman
// 59548 - Mage
// 121093 - Monk
class spell_gen_gift_of_naaru : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (!GetCaster() || !aurEff->GetTotalTicks())
            return;

        float healPct = GetEffectInfo(EFFECT_1).CalcValue() / 100.0f;
        float heal = healPct * GetCaster()->GetMaxHealth();
        int32 healTick = std::floor(heal / aurEff->GetTotalTicks());
        amount += healTick;
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

// 69641 - Gryphon/Wyvern Pet - Mounting Check Aura
class spell_gen_gryphon_wyvern_mount_check : public AuraScript
{
    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        Unit* owner = target->GetOwner();

        if (!owner)
            return;

        if (owner->IsMounted())
            target->SetDisableGravity(true);
        else
            target->SetDisableGravity(false);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_gryphon_wyvern_mount_check::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

/* 9204 - Hate to Zero (Melee)
  20538 - Hate to Zero (AoE)
  26569 - Hate to Zero (AoE)
  26637 - Hate to Zero (AoE, Unique)
  37326 - Hate to Zero (AoE)
  40410 - Hate to Zero (Should be added, AoE)
  40467 - Hate to Zero (Should be added, AoE)
  41582 - Hate to Zero (Should be added, Melee) */
class spell_gen_hate_to_zero : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (GetCaster()->CanHaveThreatList())
            GetCaster()->GetThreatManager().ModifyThreatByPercent(GetHitUnit(), -100);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_hate_to_zero::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// This spell is used by both player and creature, but currently works only if used by player
// 63984 - Hate to Zero
class spell_gen_hate_to_zero_caster_target : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            if (target->CanHaveThreatList())
                target->GetThreatManager().ModifyThreatByPercent(GetCaster(), -100);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_hate_to_zero_caster_target::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 19707 - Hate to 50%
class spell_gen_hate_to_50 : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (GetCaster()->CanHaveThreatList())
            GetCaster()->GetThreatManager().ModifyThreatByPercent(GetHitUnit(), -50);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_hate_to_50::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 26886 - Hate to 75%
class spell_gen_hate_to_75 : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (GetCaster()->CanHaveThreatList())
            GetCaster()->GetThreatManager().ModifyThreatByPercent(GetHitUnit(), -25);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_hate_to_75::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum Interrupt
{
    SPELL_GEN_THROW_INTERRUPT           = 32747
};

// 32748 - Deadly Throw Interrupt
// 44835 - Maim Interrupt
class spell_gen_interrupt : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GEN_THROW_INTERRUPT });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_GEN_THROW_INTERRUPT, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_gen_interrupt::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_gen_increase_stats_buff : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (GetHitUnit()->IsInRaidWith(GetCaster()))
            GetCaster()->CastSpell(GetCaster(), GetEffectValue() + 1, true); // raid buff
        else
            GetCaster()->CastSpell(GetHitUnit(), GetEffectValue(), true); // single-target buff
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_increase_stats_buff::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
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

class spell_gen_lifebloom : public AuraScript
{
public:
    spell_gen_lifebloom(uint32 spellId) : AuraScript(), _spellId(spellId) { }

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
        GetTarget()->CastSpell(GetTarget(), _spellId, CastSpellExtraArgs(aurEff).SetOriginalCaster(GetCasterGUID()));
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_gen_lifebloom::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
    }

    uint32 _spellId;
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
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ 62552, 62719, 64100, 66482 });
    }

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
                        if (aura->GetId() == 62552 || aura->GetId() == 62719 || aura->GetId() == 64100 || aura->GetId() == 66482)
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
        SpellInfo const* spell = sSpellMgr->AssertSpellInfo(m_scriptSpellId, DIFFICULTY_NONE);

        if (spell->HasEffect(SPELL_EFFECT_SCRIPT_EFFECT))
            OnEffectHitTarget += SpellEffectFn(spell_gen_mounted_charge::HandleScriptEffect, EFFECT_FIRST_FOUND, SPELL_EFFECT_SCRIPT_EFFECT);

        if (spell->GetEffect(EFFECT_0).IsEffect(SPELL_EFFECT_CHARGE))
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
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FALL_DOWN });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetActionTarget()->CastSpell(nullptr, SPELL_FALL_DOWN, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_gen_moss_covered_feet::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

enum Netherbloom : uint32
{
    SPELL_NETHERBLOOM_POLLEN_1      = 28703
};

// 28702 - Netherbloom
class spell_gen_netherbloom : public SpellScript
{
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
        if (!eventInfo.GetSpellInfo())
            return false;

        if (GetFirstSchoolInMask(eventInfo.GetSchoolMask()) == SPELL_SCHOOL_NORMAL)
            return false;

        return true;
    }

    void OnProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
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

class spell_gen_oracle_wolvar_reputation : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Player* player = GetCaster()->ToPlayer();
        uint32 factionId = GetEffectInfo().CalcValue();
        int32  repChange = GetEffectInfo(EFFECT_1).CalcValue();

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

class spell_gen_prevent_emotes : public AuraScript
{
    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetUnitFlag(UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveUnitFlag(UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_gen_prevent_emotes::HandleEffectApply, EFFECT_FIRST_FOUND, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_gen_prevent_emotes::OnRemove, EFFECT_FIRST_FOUND, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_gen_player_say : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return sBroadcastTextStore.HasRecord(uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()));
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        // Note: target here is always player; caster here is gameobject, creature or player (self cast)
        if (Unit* target = GetHitUnit())
            target->Unit::Say(uint32(GetEffectValue()), target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_player_say::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_gen_proc_below_pct_damaged : public AuraScript
{
    bool CheckProc(ProcEventInfo& eventInfo)
    {
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return false;

        int32 pct = GetSpellInfo()->GetEffect(EFFECT_0).CalcValue();

        if (eventInfo.GetActionTarget()->HealthBelowPctDamaged(pct, damageInfo->GetDamage()))
            return true;

        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_gen_proc_below_pct_damaged::CheckProc);
    }
};

class spell_gen_proc_charge_drop_only : public AuraScript
{
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
                if (newPet->getDeathState() != ALIVE && newPet->getDeathState() != JUST_RESPAWNED)
                    newPet->setDeathState(JUST_RESPAWNED);

                newPet->SetFullHealth();
                newPet->SetFullPower(newPet->GetPowerType());

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

// 36553 - PetWait
class spell_gen_pet_wait : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->GetMotionMaster()->Clear();
        GetCaster()->GetMotionMaster()->MoveIdle();
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_gen_pet_wait::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum ProfessionResearch
{
    SPELL_NORTHREND_INSCRIPTION_RESEARCH = 61177
};

class spell_gen_profession_research : public SpellScript
{
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

enum TrinketSpells
{
    SPELL_PVP_TRINKET_ALLIANCE  = 97403,
    SPELL_PVP_TRINKET_HORDE     = 97404
};

class spell_gen_pvp_trinket : public SpellScript
{
    void TriggerAnimation()
    {
        Player* caster = GetCaster()->ToPlayer();

        switch (caster->GetEffectiveTeam())
        {
            case ALLIANCE:
                caster->CastSpell(caster, SPELL_PVP_TRINKET_ALLIANCE, TRIGGERED_FULL_MASK);
                break;
            case HORDE:
                caster->CastSpell(caster, SPELL_PVP_TRINKET_HORDE, TRIGGERED_FULL_MASK);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_gen_pvp_trinket::TriggerAnimation);
    }
};

class spell_gen_remove_flight_auras : public SpellScript
{
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
class spell_gen_remove_impairing_auras : public SpellScript
{
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
    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();

        Unit* target = GetTarget();
        if (!target)
            return;

        int32 heal = target->CountPctFromMaxHealth(10);
        HealInfo healInfo(target, target, heal, GetSpellInfo(), GetSpellInfo()->GetSchoolMask());
        target->HealBySpell(healInfo);

        /// @todo: should proc other auras?
        if (int32 mana = target->GetMaxPower(POWER_MANA))
        {
            mana /= 10;
            target->EnergizeBySpell(target, GetSpellInfo(), mana, POWER_MANA);
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
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        // they apply damage so no need to check for ticks here

        if (GetTarget()->HealthAbovePct(GetEffectInfo(EFFECT_1).CalcValue()))
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
    void PeriodicTick(AuraEffect const* aurEff)
    {
        // if it has only periodic effect, allow 1 tick
        bool onlyEffect = GetSpellInfo()->GetEffects().size() == 1;
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
class spell_gen_remove_on_full_health_pct : public AuraScript
{
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
            targets.sort(Trinity::Predicates::PowerPctOrderPred(POWER_MANA));
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

enum RunningWildMountIds
{
    SPELL_ALTERED_FORM          = 97709
};

class spell_gen_running_wild : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_ALTERED_FORM });
    }

    bool Load() override
    {
        // Definitely not a good thing, but currently the only way to do something at cast start
        // Should be replaced as soon as possible with a new hook: BeforeCastStart
        GetCaster()->CastSpell(GetCaster(), SPELL_ALTERED_FORM, TRIGGERED_FULL_MASK);
        return false;
    }

    void Register() override
    {
    }
};

class spell_gen_running_wild_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        if (!sCreatureDisplayInfoStore.LookupEntry(DISPLAYID_HIDDEN_MOUNT))
            return false;
        return true;
    }

    void HandleMount(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        PreventDefaultAction();

        target->Mount(DISPLAYID_HIDDEN_MOUNT, 0, 0);

        // cast speed aura
        if (MountCapabilityEntry const* mountCapability = sMountCapabilityStore.LookupEntry(aurEff->GetAmount()))
            target->CastSpell(target, mountCapability->ModSpellAuraID, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_gen_running_wild_aura::HandleMount, EFFECT_1, SPELL_AURA_MOUNTED, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_gen_two_forms : public SpellScript
{
    SpellCastResult CheckCast()
    {
        if (GetCaster()->IsInCombat())
        {
            SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_CANT_TRANSFORM);
            return SPELL_FAILED_CUSTOM_ERROR;
        }

        // Player cannot transform to human form if he is forced to be worgen for some reason (Darkflight)
        Unit::AuraEffectList const& alteredFormAuras = GetCaster()->GetAuraEffectsByType(SPELL_AURA_WORGEN_ALTERED_FORM);
        if (std::distance(alteredFormAuras.begin(), alteredFormAuras.end()) > 1)
        {
            SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_CANT_TRANSFORM);
            return SPELL_FAILED_CUSTOM_ERROR;
        }

        return SPELL_CAST_OK;
    }

    void HandleTransform(SpellEffIndex effIndex)
    {
        Unit* target = GetHitUnit();
        PreventHitDefaultEffect(effIndex);
        if (target->HasAuraType(SPELL_AURA_WORGEN_ALTERED_FORM))
            target->RemoveAurasByType(SPELL_AURA_WORGEN_ALTERED_FORM);
        else    // Basepoints 1 for this aura control whether to trigger transform transition animation or not.
            target->CastSpell(target, SPELL_ALTERED_FORM, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_BASE_POINT0, 1));
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_gen_two_forms::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_gen_two_forms::HandleTransform, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_gen_darkflight : public SpellScript
{
    void TriggerTransform()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_ALTERED_FORM, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_gen_darkflight::TriggerTransform);
    }
};

enum SeaforiumSpells
{
    SPELL_PLANT_CHARGES_CREDIT_ACHIEVEMENT  = 60937
};

class spell_gen_seaforium_blast : public SpellScript
{
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

static Emote const EmoteArray[] = { EMOTE_ONESHOT_CHEER, EMOTE_ONESHOT_EXCLAMATION, EMOTE_ONESHOT_APPLAUD };

class spell_gen_spectator_cheer_trigger : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (roll_chance_i(40))
            GetCaster()->HandleEmoteCommand(Trinity::Containers::SelectRandomContainerElement(EmoteArray));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_spectator_cheer_trigger::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_gen_spirit_healer_res : public SpellScript
{
    bool Load() override
    {
        return GetOriginalCaster() && GetOriginalCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleDummy(SpellEffIndex /* effIndex */)
    {
        Player* originalCaster = GetOriginalCaster()->ToPlayer();
        if (Unit* target = GetHitUnit())
        {
            WorldPackets::NPC::NPCInteractionOpenResult spiritHealerConfirm;
            spiritHealerConfirm.Npc = target->GetGUID();
            spiritHealerConfirm.InteractionType = PlayerInteractionType::SpiritHealer;
            spiritHealerConfirm.Success = true;
            originalCaster->SendDirectMessage(spiritHealerConfirm.Write());
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_spirit_healer_res::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum TournamentMountsSpells
{
    SPELL_LANCE_EQUIPPED     = 62853
};

class spell_gen_summon_tournament_mount : public SpellScript
{
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

class spell_gen_trigger_exclude_caster_aura_spell : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->ExcludeCasterAuraSpell });
    }

    void HandleTrigger()
    {
        // Blizz seems to just apply aura without bothering to cast
        GetCaster()->AddAura(GetSpellInfo()->ExcludeCasterAuraSpell, GetCaster());
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_gen_trigger_exclude_caster_aura_spell::HandleTrigger);
    }
};

class spell_gen_trigger_exclude_target_aura_spell : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->ExcludeTargetAuraSpell });
    }

    void HandleTrigger()
    {
        if (Unit* target = GetHitUnit())
            // Blizz seems to just apply aura without bothering to cast
            GetCaster()->AddAura(GetSpellInfo()->ExcludeTargetAuraSpell, target);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_gen_trigger_exclude_target_aura_spell::HandleTrigger);
    }
};

enum PvPTrinketTriggeredSpells
{
    SPELL_WILL_OF_THE_FORSAKEN_COOLDOWN_TRIGGER         = 72752,
    SPELL_WILL_OF_THE_FORSAKEN_COOLDOWN_TRIGGER_WOTF    = 72757
};

template <uint32 TriggeredSpellId>
class spell_pvp_trinket_wotf_shared_cd : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ TriggeredSpellId });
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
        GetCaster()->CastSpell(nullptr, TriggeredSpellId, false);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_pvp_trinket_wotf_shared_cd::HandleScript);
    }
};

enum FriendOrFowl
{
    SPELL_TURKEY_VENGEANCE      = 25285
};

class spell_gen_turkey_marker : public AuraScript
{
    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        // store stack apply times, so we can pop them while they expire
        _applyTimes.push_back(GameTime::GetGameTimeMS());
        Unit* target = GetTarget();

        // on stack 15 cast the achievement crediting spell
        if (GetStackAmount() >= 15)
            target->CastSpell(target, SPELL_TURKEY_VENGEANCE, CastSpellExtraArgs(aurEff)
                .SetOriginalCaster(GetCasterGUID()));
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        int32 removeCount = 0;

        // pop expired times off of the stack
        while (!_applyTimes.empty() && _applyTimes.front() + GetMaxDuration() < GameTime::GetGameTimeMS())
        {
            _applyTimes.pop_front();
            removeCount++;
        }

        if (removeCount)
            ModStackAmount(-removeCount, AURA_REMOVE_BY_EXPIRE);
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
    void HandleScript(SpellEffIndex /*effIndex*/)
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

            CreateItem(itemId[urand(0, 4)], ItemContext::NONE);
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
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VAMPIRIC_TOUCH_HEAL });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
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

class spell_gen_whisper_to_controller : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return sBroadcastTextStore.HasRecord(uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()));
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (TempSummon* casterSummon = GetCaster()->ToTempSummon())
            if (Player* target = casterSummon->GetSummonerUnit()->ToPlayer())
                casterSummon->Unit::Whisper(uint32(GetEffectValue()), target, false);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_gen_whisper_to_controller::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum WhisperToControllerTexts
{
    WHISPER_FUTURE_YOU   = 2,
    WHISPER_DEFENDER     = 1,
    WHISPER_PAST_YOU     = 2
};

// BasePoints of spells is ID of npc_text used to group texts, it's not implemented so texts are grouped the old way
// 50037 - Mystery of the Infinite: Future You's Whisper to Controller - Random
// 50287 - Azure Dragon: On Death Force Cast Wyrmrest Defender to Whisper to Controller - Random
// 60709 - MOTI, Redux: Past You's Whisper to Controller - Random
class spell_gen_whisper_to_controller_random : public SpellScript
{
public:
    spell_gen_whisper_to_controller_random(uint32 text) : SpellScript(), _text(text) { }

private:
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        // Same for all spells
        if (!roll_chance_i(20))
            return;

        if (Creature* target = GetHitCreature())
            if (TempSummon* targetSummon = target->ToTempSummon())
                if (Player* player = targetSummon->GetSummonerUnit()->ToPlayer())
                    targetSummon->AI()->Talk(_text, player);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_whisper_to_controller_random::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }

    uint32 _text;
};

class spell_gen_eject_all_passengers : public SpellScript
{
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
    bool Validate(SpellInfo const* spellInfo) override
    {
        if (!ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } }))
            return false;
        if (spellInfo->GetEffect(EFFECT_0).CalcValue() < 1)
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

class spell_gen_eject_passenger_with_seatId : public SpellScript
{
public:
    spell_gen_eject_passenger_with_seatId(uint8 seatId) : SpellScript(), _seatId(seatId) { }

private:
    uint8 _seatId;

    void EjectPassenger(SpellEffIndex /*effIndex*/)
    {
        if (Vehicle* vehicle = GetHitUnit()->GetVehicleKit())
        {
            if (Unit* passenger = vehicle->GetPassenger(_seatId))
                passenger->ExitVehicle();
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_eject_passenger_with_seatId::EjectPassenger, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum GMFreeze
{
    SPELL_GM_FREEZE = 9454
};

class spell_gen_gm_freeze : public AuraScript
{
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
            player->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);

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
            player->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
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
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_MIXOLOGY }) && ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } });
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
        if (GetCaster()->HasAura(SPELL_MIXOLOGY) && GetCaster()->HasSpell(GetEffectInfo(EFFECT_0).TriggerSpell))
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
                    TC_LOG_ERROR("spells", "SpellId {} couldn't be processed in spell_gen_mixology_bonus", GetId());
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
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_SIEGE_TANK_CONTROL); //aurEff->GetAmount()
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_gen_vehicle_control_link::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

enum FreezingCircleMisc
{
    SPELL_FREEZING_CIRCLE_PIT_OF_SARON_NORMAL = 69574,
    SPELL_FREEZING_CIRCLE_PIT_OF_SARON_HEROIC = 70276,
    SPELL_FREEZING_CIRCLE                     = 34787,
    SPELL_FREEZING_CIRCLE_SCENARIO            = 141383,
    MAP_ID_BLOOD_IN_THE_SNOW_SCENARIO         = 1130
};

// 34779 - Freezing Circle
class spell_freezing_circle : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_FREEZING_CIRCLE_PIT_OF_SARON_NORMAL,
                SPELL_FREEZING_CIRCLE_PIT_OF_SARON_HEROIC,
                SPELL_FREEZING_CIRCLE,
                SPELL_FREEZING_CIRCLE_SCENARIO
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
            spellId = map->GetId() == MAP_ID_BLOOD_IN_THE_SNOW_SCENARIO ? SPELL_FREEZING_CIRCLE_SCENARIO : SPELL_FREEZING_CIRCLE;

        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, GetCastDifficulty()))
            if (!spellInfo->GetEffects().empty())
                SetHitDamage(spellInfo->GetEffect(EFFECT_0).CalcValue());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_freezing_circle::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Used for some spells cast by vehicles or charmed creatures that do not send a cooldown event on their own
class spell_gen_charmed_unit_spell_cooldown : public SpellScript
{
    void HandleCast()
    {
        Unit* caster = GetCaster();
        if (Player* owner = caster->GetCharmerOrOwnerPlayerOrPlayerItself())
        {
            WorldPackets::Spells::SpellCooldown spellCooldown;
            spellCooldown.Caster = owner->GetGUID();
            spellCooldown.Flags = SPELL_COOLDOWN_FLAG_NONE;
            spellCooldown.SpellCooldowns.emplace_back(GetSpellInfo()->Id, GetSpellInfo()->RecoveryTime);
            owner->SendDirectMessage(spellCooldown.Write());
        }
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_gen_charmed_unit_spell_cooldown::HandleCast);
    }
};

enum CannonBlast
{
    SPELL_CANNON_BLAST          = 42578,
    SPELL_CANNON_BLAST_DAMAGE   = 42576
};

class spell_gen_cannon_blast : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CANNON_BLAST });
    }
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        int32 bp = GetEffectValue();
        Unit* target = GetHitUnit();
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellBP0(bp);
        target->CastSpell(target, SPELL_CANNON_BLAST_DAMAGE, args);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_cannon_blast::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 37751 - Submerged
class spell_gen_submerged : public SpellScript
{
    void HandleScript(SpellEffIndex /*eff*/)
    {
        if (Creature* target = GetHitCreature())
            target->SetStandState(UNIT_STAND_STATE_SUBMERGED);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_submerged::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 169869 - Transformation Sickness
class spell_gen_decimatus_transformation_sickness : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            target->SetHealth(target->CountPctFromMaxHealth(25));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_decimatus_transformation_sickness::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 189491 - Summon Towering Infernal.
class spell_gen_anetheron_summon_towering_infernal : public SpellScript
{
    void HandleDummy(SpellEffIndex /* effIndex */)
    {
        GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_anetheron_summon_towering_infernal::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum KazrogalHellfireMark
{
    SPELL_MARK_OF_KAZROGAL_HELLFIRE = 189512,
    SPELL_MARK_OF_KAZROGAL_DAMAGE_HELLFIRE = 189515
};

class MarkTargetHellfireFilter
{
    public:
        bool operator()(WorldObject* target) const
        {
            if (Unit* unit = target->ToUnit())
                return unit->GetPowerType() != POWER_MANA;
            return false;
        }
};

class spell_gen_mark_of_kazrogal_hellfire : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(MarkTargetHellfireFilter());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gen_mark_of_kazrogal_hellfire::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_gen_mark_of_kazrogal_hellfire_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_MARK_OF_KAZROGAL_DAMAGE_HELLFIRE });
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        if (target->GetPower(POWER_MANA) == 0)
        {
            target->CastSpell(target, SPELL_MARK_OF_KAZROGAL_DAMAGE_HELLFIRE, aurEff);
            // Remove aura
            SetDuration(0);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_mark_of_kazrogal_hellfire_aura::OnPeriodic, EFFECT_0, SPELL_AURA_POWER_BURN);
    }
};

class spell_gen_azgalor_rain_of_fire_hellfire_citadel : public SpellScript
{
    void HandleDummy(SpellEffIndex /* effIndex */)
    {
        GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_azgalor_rain_of_fire_hellfire_citadel::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum AuraProcRemoveSpells
{
    SPELL_FACE_RAGE         = 99947,
    SPELL_IMPATIENT_MIND    = 187213
};

// 99947 - Face Rage
class spell_gen_face_rage : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_FACE_RAGE })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_2 } });
    }

    void OnRemove(AuraEffect const* /*effect*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(GetEffectInfo(EFFECT_2).TriggerSpell);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_gen_face_rage::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 187213 - Impatient Mind
class spell_gen_impatient_mind : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_IMPATIENT_MIND });
    }

    void OnRemove(AuraEffect const* effect, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(effect->GetSpellEffectInfo().TriggerSpell);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_gen_impatient_mind::OnRemove, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 209352 - Boost 2.0 [Paladin+Priest] - Watch for Shield
class spell_gen_boost_2_0_paladin_priest_watch_for_shield : public AuraScript
{
    static constexpr uint32 SPELL_POWER_WORD_SHIELD = 17;
    static constexpr uint32 SPELL_DIVINE_SHIELD = 642;

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_POWER_WORD_SHIELD, SPELL_DIVINE_SHIELD });
    }

    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo& procInfo)
    {
        SpellInfo const* spellInfo = procInfo.GetSpellInfo();
        return spellInfo && (spellInfo->Id == SPELL_POWER_WORD_SHIELD || spellInfo->Id == SPELL_DIVINE_SHIELD);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_gen_boost_2_0_paladin_priest_watch_for_shield::CheckProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 269083 - Enlisted
// 282559 - Enlisted
class spell_gen_war_mode_enlisted : public AuraScript
{
    void CalcWarModeBonus(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        Player* target = GetUnitOwner()->ToPlayer();
        if (!target)
            return;

        switch (target->GetTeamId())
        {
            case TEAM_ALLIANCE:
                amount = sWorldStateMgr->GetValue(WS_WAR_MODE_ALLIANCE_BUFF_VALUE, target->GetMap());
                break;
            case TEAM_HORDE:
                amount = sWorldStateMgr->GetValue(WS_WAR_MODE_HORDE_BUFF_VALUE, target->GetMap());
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(m_scriptSpellId, DIFFICULTY_NONE);

        if (spellInfo->HasAura(SPELL_AURA_MOD_XP_PCT))
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_war_mode_enlisted::CalcWarModeBonus, EFFECT_ALL, SPELL_AURA_MOD_XP_PCT);

        if (spellInfo->HasAura(SPELL_AURA_MOD_XP_QUEST_PCT))
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_war_mode_enlisted::CalcWarModeBonus, EFFECT_ALL, SPELL_AURA_MOD_XP_QUEST_PCT);

        if (spellInfo->HasAura(SPELL_AURA_MOD_CURRENCY_GAIN_FROM_SOURCE))
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_war_mode_enlisted::CalcWarModeBonus, EFFECT_ALL, SPELL_AURA_MOD_CURRENCY_GAIN_FROM_SOURCE);

        if (spellInfo->HasAura(SPELL_AURA_MOD_MONEY_GAIN))
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_war_mode_enlisted::CalcWarModeBonus, EFFECT_ALL, SPELL_AURA_MOD_MONEY_GAIN);

        if (spellInfo->HasAura(SPELL_AURA_MOD_ANIMA_GAIN))
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_war_mode_enlisted::CalcWarModeBonus, EFFECT_ALL, SPELL_AURA_MOD_ANIMA_GAIN);

        if (spellInfo->HasAura(SPELL_AURA_DUMMY))
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_gen_war_mode_enlisted::CalcWarModeBonus, EFFECT_ALL, SPELL_AURA_DUMMY);
    }
};

enum DefenderOfAzerothData
{
    SPELL_DEATH_GATE_TELEPORT_STORMWIND = 316999,
    SPELL_DEATH_GATE_TELEPORT_ORGRIMMAR = 317000,

    QUEST_DEFENDER_OF_AZEROTH_ALLIANCE  = 58902,
    QUEST_DEFENDER_OF_AZEROTH_HORDE     = 58903,

    NPC_NAZGRIM                         = 161706,
    NPC_TROLLBANE                       = 161707,
    NPC_WHITEMANE                       = 161708,
    NPC_MOGRAINE                        = 161709,
};

struct BindLocation
{
    BindLocation(uint32 mapId, float x, float y, float z, float o, uint32 areaId)
        : Loc(mapId, x, y, z, o), AreaId(areaId) { }
    WorldLocation Loc;
    uint32 AreaId;
};

BindLocation const StormwindInnLoc(0, -8868.1f, 675.82f, 97.9f, 5.164778709411621093f, 5148);
BindLocation const OrgrimmarInnLoc(1, 1573.18f, -4441.62f, 16.06f, 1.818284034729003906f, 8618);

class spell_defender_of_azeroth_death_gate_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DEATH_GATE_TELEPORT_STORMWIND,
            SPELL_DEATH_GATE_TELEPORT_ORGRIMMAR
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Player* player = GetHitUnit()->ToPlayer();
        if (!player)
            return;

        if (player->GetQuestStatus(QUEST_DEFENDER_OF_AZEROTH_ALLIANCE) == QUEST_STATUS_NONE && player->GetQuestStatus(QUEST_DEFENDER_OF_AZEROTH_HORDE) == QUEST_STATUS_NONE)
            return;

        BindLocation const& bindLoc = player->GetTeam() == ALLIANCE ? StormwindInnLoc : OrgrimmarInnLoc;
        player->SetHomebind(bindLoc.Loc, bindLoc.AreaId);
        player->SendBindPointUpdate();
        player->SendPlayerBound(player->GetGUID(), bindLoc.AreaId);

        player->CastSpell(player, player->GetTeam() == ALLIANCE ? SPELL_DEATH_GATE_TELEPORT_STORMWIND : SPELL_DEATH_GATE_TELEPORT_ORGRIMMAR);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_defender_of_azeroth_death_gate_selector::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_defender_of_azeroth_speak_with_mograine : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (!GetCaster())
            return;

        Player* player = GetCaster()->ToPlayer();
        if (!player)
            return;

        if (Creature* nazgrim = GetHitUnit()->FindNearestCreature(NPC_NAZGRIM, 10.0f))
            nazgrim->HandleEmoteCommand(EMOTE_ONESHOT_POINT, player);
        if (Creature* trollbane = GetHitUnit()->FindNearestCreature(NPC_TROLLBANE, 10.0f))
            trollbane->HandleEmoteCommand(EMOTE_ONESHOT_POINT, player);
        if (Creature* whitemane = GetHitUnit()->FindNearestCreature(NPC_WHITEMANE, 10.0f))
            whitemane->HandleEmoteCommand(EMOTE_ONESHOT_POINT, player);

        // @TODO: spawntracking - show death gate for casting player
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_defender_of_azeroth_speak_with_mograine::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 118301 - Summon Battle Pet
class spell_summon_battle_pet : public SpellScript
{
    void HandleSummon(SpellEffIndex effIndex)
    {
        uint32 creatureId = uint32(GetSpellValue()->EffectBasePoints[effIndex]);
        if (sObjectMgr->GetCreatureTemplate(creatureId))
        {
            PreventHitDefaultEffect(effIndex);

            Unit* caster = GetCaster();
            SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(uint32(GetEffectInfo().MiscValueB));
            Milliseconds duration = Milliseconds(GetSpellInfo()->CalcDuration(caster));
            Position pos = GetHitDest()->GetPosition();

            if (Creature* summon = caster->GetMap()->SummonCreature(creatureId, pos, properties, duration, caster, GetSpellInfo()->Id))
                summon->SetImmuneToAll(true);
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_summon_battle_pet::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
    }
};

// 132334 - Trainer Heal Cooldown (SERVERSIDE)
class spell_gen_trainer_heal_cooldown : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ BattlePets::SPELL_REVIVE_BATTLE_PETS });
    }

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    void UpdateReviveBattlePetCooldown(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Player* target = GetUnitOwner()->ToPlayer();
        SpellInfo const* reviveBattlePetSpellInfo = sSpellMgr->AssertSpellInfo(BattlePets::SPELL_REVIVE_BATTLE_PETS, DIFFICULTY_NONE);

        if (target->GetSession()->GetBattlePetMgr()->IsBattlePetSystemEnabled())
        {
            Milliseconds expectedCooldown = Milliseconds(GetAura()->GetMaxDuration());
            SpellHistory::Duration remainingCooldown = target->GetSpellHistory()->GetRemainingCategoryCooldown(reviveBattlePetSpellInfo);
            if (remainingCooldown > SpellHistory::Duration::zero())
            {
                if (remainingCooldown < expectedCooldown)
                    target->GetSpellHistory()->ModifyCooldown(reviveBattlePetSpellInfo, expectedCooldown - remainingCooldown);
            }
            else
            {
                target->GetSpellHistory()->StartCooldown(reviveBattlePetSpellInfo, 0, nullptr, false, expectedCooldown);
            }
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_gen_trainer_heal_cooldown::UpdateReviveBattlePetCooldown, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 45313 - Anchor Here
class spell_gen_anchor_here : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitCreature())
            creature->SetHomePosition(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_anchor_here::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 147066 - (Serverside/Non-DB2) Generic - Mount Check Aura
class spell_gen_mount_check_aura : public AuraScript
{
    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        uint32 mountDisplayId = 0;

        TempSummon* tempSummon = target->ToTempSummon();
        if (!tempSummon)
            return;

        Player const* summoner = Object::ToPlayer(tempSummon->GetSummoner());
        if (!summoner)
            return;

        if (summoner->IsMounted() && (!summoner->IsInCombat() || summoner->IsFlying()))
        {
            if (CreatureSummonedData const* summonedData = sObjectMgr->GetCreatureSummonedData(tempSummon->GetEntry()))
            {
                if (summoner->IsFlying() && summonedData->FlyingMountDisplayID)
                    mountDisplayId = *summonedData->FlyingMountDisplayID;
                else if (summonedData->GroundMountDisplayID)
                    mountDisplayId = *summonedData->GroundMountDisplayID;
            }
        }

        if (mountDisplayId != target->GetMountDisplayId())
            target->SetMountDisplayId(mountDisplayId);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_mount_check_aura::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

enum AncestralCallSpells
{
    SPELL_RICTUS_OF_THE_LAUGHING_SKULL  = 274739,
    SPELL_ZEAL_OF_THE_BURNING_BLADE     = 274740,
    SPELL_FEROCITY_OF_THE_FROSTWOLF     = 274741,
    SPELL_MIGHT_OF_THE_BLACKROCK        = 274742
};

// 274738 - Ancestral Call (Mag'har Orc Racial)
class spell_gen_ancestral_call : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_RICTUS_OF_THE_LAUGHING_SKULL,
            SPELL_ZEAL_OF_THE_BURNING_BLADE,
            SPELL_FEROCITY_OF_THE_FROSTWOLF,
            SPELL_MIGHT_OF_THE_BLACKROCK
        });
    }

    static constexpr uint32 AncestralCallBuffs[] = { SPELL_RICTUS_OF_THE_LAUGHING_SKULL, SPELL_ZEAL_OF_THE_BURNING_BLADE, SPELL_FEROCITY_OF_THE_FROSTWOLF, SPELL_MIGHT_OF_THE_BLACKROCK };

    void HandleOnCast()
    {
        Unit* caster = GetCaster();
        uint32 spellId = Trinity::Containers::SelectRandomContainerElement(AncestralCallBuffs);

        caster->CastSpell(caster, spellId, true);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_gen_ancestral_call::HandleOnCast);
    }
};

// 83477 - Eject Passengers 3-8
class spell_gen_eject_passengers_3_8 : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Vehicle* vehicle = GetHitUnit()->GetVehicleKit();
        if (!vehicle)
            return;

        for (uint8 i = 2; i < 8; i++)
        {
            if (Unit* passenger = vehicle->GetPassenger(i))
                passenger->ExitVehicle();
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_eject_passengers_3_8::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 83781 - Reverse Cast Ride Vehicle
class spell_gen_reverse_cast_target_to_caster_triggered: public SpellScript
{
    void HandleScript(SpellEffIndex effIndex)
    {
        GetHitUnit()->CastSpell(GetCaster(), GetSpellInfo()->GetEffect(effIndex).CalcValue(), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_reverse_cast_target_to_caster_triggered::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// Note: this spell unsummons any creature owned by the caster. Set appropriate target conditions on the DB.
// 84065 - Despawn All Summons
// 83935 - Despawn All Summons
// 160938 - Despawn All Summons (Garrison Intro Only)
class spell_gen_despawn_all_summons_owned_by_caster : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            Creature* target = GetHitCreature();

            if (target->GetOwner() == caster)
                target->DespawnOrUnsummon();
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_despawn_all_summons_owned_by_caster::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum SkinningLearningSpell
{
     SPELL_CLASSIC_SKINNING      = 265856,
     SPELL_OUTLAND_SKINNING      = 265858,
     SPELL_NORTHREND_SKINNING    = 265860,
     SPELL_CATACLYSM_SKINNING    = 265862,
     SPELL_PANDARIA_SKINNING     = 265864,
     SPELL_DRAENOR_SKINNING      = 265866,
     SPELL_LEGION_SKINNING       = 265868,
     SPELL_KUL_TIRAN_SKINNING    = 265870,
     SPELL_ZANDALARI_SKINNING    = 265872,
     SPELL_SHADOWLANDS_SKINNING  = 308570,
     SPELL_DRAGON_ISLES_SKINNING = 366263
};

// 8613 - Skinning
class spell_gen_skinning : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_OUTLAND_SKINNING,
            SPELL_NORTHREND_SKINNING,
            SPELL_CATACLYSM_SKINNING,
            SPELL_PANDARIA_SKINNING,
            SPELL_DRAENOR_SKINNING,
            SPELL_KUL_TIRAN_SKINNING,
            SPELL_ZANDALARI_SKINNING,
            SPELL_SHADOWLANDS_SKINNING,
            SPELL_DRAGON_ISLES_SKINNING
        });
    }

    void HandleSkinningEffect(SpellEffIndex /*effIndex*/)
    {
        Player* player = GetCaster()->ToPlayer();
        if (!player)
            return;

        ContentTuningEntry const* contentTuning = sContentTuningStore.LookupEntry(GetHitUnit()->GetContentTuning());
        if (!contentTuning)
            return;

        uint32 skinningSkill = player->GetProfessionSkillForExp(SKILL_SKINNING, 0);
        if (!skinningSkill)
            return;

        // Autolearning missing skinning skill (Dragonflight)
        auto getSkinningLearningSpellBySkill = [&]() -> uint32
        {
            switch (skinningSkill)
            {
                case SKILL_OUTLAND_SKINNING:      return SPELL_OUTLAND_SKINNING;
                case SKILL_NORTHREND_SKINNING:    return SPELL_NORTHREND_SKINNING;
                case SKILL_CATACLYSM_SKINNING:    return SPELL_CATACLYSM_SKINNING;
                case SKILL_PANDARIA_SKINNING:     return SPELL_PANDARIA_SKINNING;
                case SKILL_DRAENOR_SKINNING:      return SPELL_DRAENOR_SKINNING;
                case SKILL_KUL_TIRAN_SKINNING:    return player->GetTeam() == ALLIANCE ? SPELL_KUL_TIRAN_SKINNING : (player->GetTeam() == HORDE ? SPELL_ZANDALARI_SKINNING : 0);
                case SKILL_SHADOWLANDS_SKINNING:  return SPELL_SHADOWLANDS_SKINNING;
                case SKILL_DRAGON_ISLES_SKINNING: return SPELL_DRAGON_ISLES_SKINNING;
                case SKILL_CLASSIC_SKINNING:      // Trainer only
                case SKILL_LEGION_SKINNING:       // Quest only
                default: break;
            }

            return 0;
        };

        if (!player->HasSkill(skinningSkill))
            if (uint32 spellId = getSkinningLearningSpellBySkill())
                player->CastSpell(nullptr, spellId, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_skinning::HandleSkinningEffect, EFFECT_0, SPELL_EFFECT_SKINNING);
    }
};

enum BloodlustExhaustionSpell : uint32
{
    SPELL_SHAMAN_SATED               = 57724, // Bloodlust
    SPELL_SHAMAN_EXHAUSTION          = 57723, // Heroism, Drums
    SPELL_MAGE_TEMPORAL_DISPLACEMENT = 80354,
    SPELL_HUNTER_FATIGUED            = 264689,
    SPELL_EVOKER_EXHAUSTION          = 390435,
};

// 2825 - Bloodlust
// 32182 - Heroism
// 80353 - Time Warp
// 264667 - Primal Rage
// 390386 - Fury of the Aspects
// 146555 - Drums of Rage
// 178207 - Drums of Fury
// 230935 - Drums of the Mountain
// 256740 - Drums of the Maelstrom
// 309658 - Drums of Deathly Ferocity
// 381301 - Feral Hide Drums
class spell_gen_bloodlust : public SpellScript
{
public:
    spell_gen_bloodlust(uint32 exhaustionSpellId) : _exhaustionSpellId(exhaustionSpellId) { }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SHAMAN_SATED,
            SPELL_SHAMAN_EXHAUSTION,
            SPELL_MAGE_TEMPORAL_DISPLACEMENT,
            SPELL_HUNTER_FATIGUED,
            SPELL_EVOKER_EXHAUSTION
        });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* target) -> bool
        {
            Unit* unit = target->ToUnit();
            if (!unit)
                return true;

            return unit->HasAura(SPELL_SHAMAN_SATED)
                || unit->HasAura(SPELL_SHAMAN_EXHAUSTION)
                || unit->HasAura(SPELL_MAGE_TEMPORAL_DISPLACEMENT)
                || unit->HasAura(SPELL_HUNTER_FATIGUED)
                || unit->HasAura(SPELL_EVOKER_EXHAUSTION);
        });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, _exhaustionSpellId, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gen_bloodlust::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gen_bloodlust::FilterTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_RAID);
        OnEffectHitTarget += SpellEffectFn(spell_gen_bloodlust::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }

private:
    uint32 _exhaustionSpellId;
};

// AoE resurrections by spirit guides
// 22012 - Spirit Heal
class spell_gen_spirit_heal_aoe : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        targets.remove_if([caster](WorldObject* target) -> bool
        {
            if (Player* playerTarget = target->ToPlayer())
                return !playerTarget->CanAcceptAreaSpiritHealFrom(caster);

            return true;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gen_spirit_heal_aoe::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// Personal resurrections in battlegrounds
// 156758 - Spirit Heal
class spell_gen_spirit_heal_personal : public AuraScript
{
    static constexpr uint32 SPELL_SPIRIT_HEAL_EFFECT = 156763;

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Player* targetPlayer = GetTarget()->ToPlayer();
        if (!targetPlayer)
            return;

        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (targetPlayer->CanAcceptAreaSpiritHealFrom(caster))
            caster->CastSpell(targetPlayer, SPELL_SPIRIT_HEAL_EFFECT);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_gen_spirit_heal_personal::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class RecastSpiritHealChannelEvent : public BasicEvent
{
public:
    RecastSpiritHealChannelEvent(Unit* caster) : _caster(caster) { }

    bool Execute(uint64 /*e_time*/, uint32 /*p_time*/) override
    {
        if (_caster->GetChannelSpellId() == 0)
            _caster->CastSpell(nullptr, SPELL_SPIRIT_HEAL_CHANNEL_AOE, false);

        return true;
    }

private:
    Unit* _caster;
};

// 22011 - Spirit Heal Channel
class spell_gen_spirit_heal_channel : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Unit* target = GetTarget();
        target->m_Events.AddEventAtOffset(new RecastSpiritHealChannelEvent(target), 1s);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_gen_spirit_heal_channel::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 2584 - Waiting to Resurrect
class spell_gen_waiting_to_resurrect : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Player* targetPlayer = GetTarget()->ToPlayer();
        if (!targetPlayer)
            return;

        targetPlayer->SetAreaSpiritHealer(nullptr);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_gen_waiting_to_resurrect::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

enum MajorHealingCooldownSpell
{
    SPELL_DRUID_TRANQUILITY              = 740,
    SPELL_DRUID_TRANQUILITY_HEAL         = 157982,
    SPELL_PRIEST_DIVINE_HYMN             = 64843,
    SPELL_PRIEST_DIVINE_HYMN_HEAL        = 64844,
    SPELL_PRIEST_LUMINOUS_BARRIER        = 271466,
    SPELL_SHAMAN_HEALING_TIDE_TOTEM      = 108280,
    SPELL_SHAMAN_HEALING_TIDE_TOTEM_HEAL = 114942,
    SPELL_MONK_REVIVAL                   = 115310,
    SPELL_EVOKER_REWIND                  = 363534
};

namespace MajorPlayerHealingCooldownHelpers
{
float GetBonusMultiplier(Unit const* unit, uint32 spellId)
{
    // Note: if caster is not in a raid setting, is in PvP or while in arena combat with 5 or less allied players.
    if (!unit->GetMap()->IsRaid() || !unit->GetMap()->IsBattleground())
    {
        uint32 bonusSpellId = 0;
        SpellEffIndex effIndex = EFFECT_0;
        switch (spellId)
        {
            case SPELL_DRUID_TRANQUILITY_HEAL:
                bonusSpellId = SPELL_DRUID_TRANQUILITY;
                effIndex = EFFECT_2;
                break;
            case SPELL_PRIEST_DIVINE_HYMN_HEAL:
                bonusSpellId = SPELL_PRIEST_DIVINE_HYMN;
                effIndex = EFFECT_1;
                break;
            case SPELL_PRIEST_LUMINOUS_BARRIER:
                bonusSpellId = spellId;
                effIndex = EFFECT_1;
                break;
            case SPELL_SHAMAN_HEALING_TIDE_TOTEM_HEAL:
                bonusSpellId = SPELL_SHAMAN_HEALING_TIDE_TOTEM;
                effIndex = EFFECT_2;
                break;
            case SPELL_MONK_REVIVAL:
                bonusSpellId = spellId;
                effIndex = EFFECT_4;
                break;
            case SPELL_EVOKER_REWIND:
                bonusSpellId = spellId;
                effIndex = EFFECT_3;
                break;
            default:
                return 0.0f;
        }

        if (AuraEffect* const healingIncreaseEffect = unit->GetAuraEffect(bonusSpellId, effIndex))
            return healingIncreaseEffect->GetAmount();

        return sSpellMgr->AssertSpellInfo(bonusSpellId, DIFFICULTY_NONE)->GetEffect(effIndex).CalcValue(unit);
    }

    return 0.0f;
}
}

// 157982 - Tranquility (Heal)
// 64844 - Divine Hymn (Heal)
// 114942 - Healing Tide (Heal)
// 115310 - Revival (Heal)
class spell_gen_major_healing_cooldown_modifier : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect
        ({
            { SPELL_DRUID_TRANQUILITY,         EFFECT_2 },
            { SPELL_PRIEST_DIVINE_HYMN,        EFFECT_1 },
            { SPELL_SHAMAN_HEALING_TIDE_TOTEM, EFFECT_2 },
            { SPELL_MONK_REVIVAL,              EFFECT_4 }
        });
    }

    void CalculateHealingBonus(Unit* /*victim*/, int32& /*healing*/, int32& /*flatMod*/, float& pctMod) const
    {
        AddPct(pctMod, MajorPlayerHealingCooldownHelpers::GetBonusMultiplier(GetCaster(), GetSpellInfo()->Id));
    }

    void Register() override
    {
        CalcHealing += SpellCalcHealingFn(spell_gen_major_healing_cooldown_modifier::CalculateHealingBonus);
    }
};

// 157982 - Tranquility (Heal)
// 271466 - Luminous Barrier (Absorb)
// 363534 - Rewind (Heal)
class spell_gen_major_healing_cooldown_modifier_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect
        ({
            { SPELL_DRUID_TRANQUILITY,         EFFECT_2 },
            { SPELL_PRIEST_LUMINOUS_BARRIER,   EFFECT_1 },
            { SPELL_EVOKER_REWIND,             EFFECT_3 }
        });
    }

    void CalculateHealingBonus(AuraEffect const* /*aurEff*/, Unit* /*victim*/, int32& /*damageOrHealing*/, int32& /*flatMod*/, float& pctMod) const
    {
        if (Unit const* caster = GetCaster())
            AddPct(pctMod, MajorPlayerHealingCooldownHelpers::GetBonusMultiplier(caster, GetSpellInfo()->Id));
    }

    void Register() override
    {
        DoEffectCalcDamageAndHealing += AuraEffectCalcHealingFn(spell_gen_major_healing_cooldown_modifier_aura::CalculateHealingBonus, EFFECT_ALL, SPELL_AURA_ANY);
    }
};

// 50230 - Random Aggro (Taunt)
class spell_gen_random_aggro_taunt : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } }) && ValidateSpellInfo({ static_cast<uint32>(spellInfo->GetEffect(EFFECT_0).BasePoints) });
    }

    void SelectRandomTarget(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleTauntEffect(SpellEffIndex effIndex)
    {
        GetHitUnit()->CastSpell(GetCaster(), static_cast<uint32>(GetSpellInfo()->GetEffect(effIndex).BasePoints), CastSpellExtraArgs(TRIGGERED_FULL_MASK));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gen_random_aggro_taunt::SelectRandomTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_gen_random_aggro_taunt::HandleTauntEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 24931 - 100 Health
// 24959 - 500 Health
// 28838 - 1 Health
// 43645 - 1 Health
// 73342 - 1 Health
// 86562 - 1 Health
class spell_gen_set_health : public SpellScript
{
public:
    spell_gen_set_health(uint64 health) : _health(health) { }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (GetHitUnit()->IsAlive() && _health > 0)
            GetHitUnit()->SetHealth(_health);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gen_set_health::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }

private:
    uint64 _health;
};

void AddSC_generic_spell_scripts()
{
    RegisterSpellScript(spell_gen_absorb0_hitlimit1);
    RegisterSpellScript(spell_gen_adaptive_warding);
    RegisterSpellScript(spell_gen_allow_cast_from_item_only);
    RegisterSpellScript(spell_gen_animal_blood);
    RegisterSpellScript(spell_spawn_blood_pool);
    RegisterSpellScript(spell_gen_arena_drink);
    RegisterSpellScript(spell_gen_aura_of_fear);
    RegisterSpellScript(spell_gen_av_drekthar_presence);
    RegisterSpellScript(spell_gen_bandage);
    RegisterSpellScript(spell_gen_battleground_mercenary_shapeshift);
    RegisterSpellScript(spell_gen_blood_reserve);
    RegisterSpellScript(spell_gen_bonked);
    RegisterSpellScriptWithArgs(spell_gen_break_shield, "spell_gen_break_shield");
    RegisterSpellScriptWithArgs(spell_gen_break_shield, "spell_gen_tournament_counterattack");
    RegisterSpellScript(spell_gen_burning_depths_necrolyte_image);
    RegisterSpellScript(spell_gen_cannibalize);
    RegisterSpellScript(spell_gen_chains_of_ice);
    RegisterSpellScript(spell_gen_chaos_blast);
    RegisterSpellScript(spell_clear_all);
    RegisterSpellScript(spell_gen_clone);
    RegisterSpellScript(spell_gen_clone_weapon);
    RegisterSpellScript(spell_gen_clone_weapon_aura);
    RegisterSpellScript(spell_gen_consumption);
    RegisterSpellScriptWithArgs(spell_gen_count_pct_from_max_hp, "spell_gen_default_count_pct_from_max_hp");
    RegisterSpellScriptWithArgs(spell_gen_count_pct_from_max_hp, "spell_gen_50pct_count_pct_from_max_hp", 50);
    RegisterSpellScript(spell_gen_create_lance);
    RegisterSpellScriptWithArgs(spell_gen_dalaran_disguise, "spell_gen_sunreaver_disguise");
    RegisterSpellScriptWithArgs(spell_gen_dalaran_disguise, "spell_gen_silver_covenant_disguise");
    RegisterSpellAndAuraScriptPair(spell_gen_decay_over_time_fungal_decay, spell_gen_decay_over_time_spell);
    RegisterSpellAndAuraScriptPair(spell_gen_decay_over_time_tail_sting, spell_gen_decay_over_time_spell);
    RegisterSpellScript(spell_gen_defend);
    RegisterSpellScript(spell_gen_despawn_aura);
    RegisterSpellScript(spell_gen_despawn_self);
    RegisterSpellScript(spell_gen_despawn_target);
    RegisterSpellScript(spell_gen_divine_storm_cd_reset);
    RegisterSpellScript(spell_gen_ds_flush_knockback);
    RegisterSpellScript(spell_ethereal_pet_aura);
    RegisterSpellScript(spell_ethereal_pet_onsummon);
    RegisterSpellScript(spell_ethereal_pet_aura_remove);
    RegisterSpellScript(spell_steal_essence_visual);
    RegisterSpellScript(spell_gen_feast);
    RegisterSpellScript(spell_gen_feign_death_all_flags);
    RegisterSpellScript(spell_gen_feign_death_all_flags_uninteractible);
    RegisterSpellScript(spell_gen_feign_death_all_flags_no_uninteractible);
    RegisterSpellScript(spell_gen_feign_death_no_dyn_flag);
    RegisterSpellScript(spell_gen_feign_death_no_prevent_emotes);
    RegisterSpellScript(spell_gen_furious_rage);
    RegisterSpellScript(spell_gen_5000_gold);
    RegisterSpellScript(spell_gen_fishing);
    RegisterSpellScript(spell_gen_gadgetzan_transporter_backfire);
    RegisterSpellScript(spell_gen_gift_of_naaru);
    RegisterSpellScript(spell_gen_gnomish_transporter);
    RegisterSpellScript(spell_gen_gryphon_wyvern_mount_check);
    RegisterSpellScript(spell_gen_hate_to_zero);
    RegisterSpellScript(spell_gen_hate_to_zero_caster_target);
    RegisterSpellScript(spell_gen_hate_to_50);
    RegisterSpellScript(spell_gen_hate_to_75);
    RegisterSpellScriptWithArgs(spell_gen_increase_stats_buff, "spell_pal_blessing_of_kings");
    RegisterSpellScriptWithArgs(spell_gen_increase_stats_buff, "spell_pal_blessing_of_might");
    RegisterSpellScriptWithArgs(spell_gen_increase_stats_buff, "spell_dru_mark_of_the_wild");
    RegisterSpellScriptWithArgs(spell_gen_increase_stats_buff, "spell_pri_power_word_fortitude");
    RegisterSpellScriptWithArgs(spell_gen_increase_stats_buff, "spell_pri_shadow_protection");
    RegisterSpellScript(spell_gen_interrupt);
    RegisterSpellScriptWithArgs(spell_gen_lifebloom, "spell_hexlord_lifebloom", SPELL_HEXLORD_MALACRASS_LIFEBLOOM_FINAL_HEAL);
    RegisterSpellScriptWithArgs(spell_gen_lifebloom, "spell_tur_ragepaw_lifebloom", SPELL_TUR_RAGEPAW_LIFEBLOOM_FINAL_HEAL);
    RegisterSpellScriptWithArgs(spell_gen_lifebloom, "spell_cenarion_scout_lifebloom", SPELL_CENARION_SCOUT_LIFEBLOOM_FINAL_HEAL);
    RegisterSpellScriptWithArgs(spell_gen_lifebloom, "spell_twisted_visage_lifebloom", SPELL_TWISTED_VISAGE_LIFEBLOOM_FINAL_HEAL);
    RegisterSpellScriptWithArgs(spell_gen_lifebloom, "spell_faction_champion_dru_lifebloom", SPELL_FACTION_CHAMPIONS_DRU_LIFEBLOOM_FINAL_HEAL);
    RegisterSpellScript(spell_gen_mounted_charge);
    RegisterSpellScript(spell_gen_moss_covered_feet);
    RegisterSpellScript(spell_gen_netherbloom);
    RegisterSpellScript(spell_gen_nightmare_vine);
    RegisterSpellScript(spell_gen_nitrous_boost);
    RegisterSpellScript(spell_gen_obsidian_armor);
    RegisterSpellScript(spell_gen_oracle_wolvar_reputation);
    RegisterSpellScript(spell_gen_orc_disguise);
    RegisterSpellScript(spell_gen_paralytic_poison);
    RegisterSpellScript(spell_gen_prevent_emotes);
    RegisterSpellScript(spell_gen_player_say);
    RegisterSpellScriptWithArgs(spell_gen_proc_below_pct_damaged, "spell_item_soul_harvesters_charm");
    RegisterSpellScriptWithArgs(spell_gen_proc_below_pct_damaged, "spell_item_commendation_of_kaelthas");
    RegisterSpellScriptWithArgs(spell_gen_proc_below_pct_damaged, "spell_item_corpse_tongue_coin");
    RegisterSpellScriptWithArgs(spell_gen_proc_below_pct_damaged, "spell_item_corpse_tongue_coin_heroic");
    RegisterSpellScriptWithArgs(spell_gen_proc_below_pct_damaged, "spell_item_petrified_twilight_scale");
    RegisterSpellScriptWithArgs(spell_gen_proc_below_pct_damaged, "spell_item_petrified_twilight_scale_heroic");
    RegisterSpellScript(spell_gen_proc_charge_drop_only);
    RegisterSpellScript(spell_gen_parachute);
    RegisterSpellScript(spell_gen_pet_summoned);
    RegisterSpellScript(spell_gen_pet_wait);
    RegisterSpellScript(spell_gen_profession_research);
    RegisterSpellScript(spell_gen_pvp_trinket);
    RegisterSpellScript(spell_gen_remove_flight_auras);
    RegisterSpellScript(spell_gen_remove_impairing_auras);
    RegisterSpellScript(spell_gen_restoration);
    RegisterSpellAndAuraScriptPair(spell_gen_replenishment, spell_gen_replenishment_aura);
    // Running Wild
    RegisterSpellAndAuraScriptPair(spell_gen_running_wild, spell_gen_running_wild_aura);
    RegisterSpellScript(spell_gen_two_forms);
    RegisterSpellScript(spell_gen_darkflight);
    /*                          */
    RegisterSpellScript(spell_gen_remove_on_health_pct);
    RegisterSpellScript(spell_gen_remove_on_full_health);
    RegisterSpellScript(spell_gen_remove_on_full_health_pct);
    RegisterSpellScript(spell_gen_seaforium_blast);
    RegisterSpellScript(spell_gen_spectator_cheer_trigger);
    RegisterSpellScript(spell_gen_spirit_healer_res);
    RegisterSpellScript(spell_gen_summon_tournament_mount);
    RegisterSpellScript(spell_gen_throw_shield);
    RegisterSpellScript(spell_gen_tournament_duel);
    RegisterSpellScript(spell_gen_tournament_pennant);
    RegisterSpellScript(spell_gen_teleporting);
    RegisterSpellScript(spell_gen_trigger_exclude_caster_aura_spell);
    RegisterSpellScript(spell_gen_trigger_exclude_target_aura_spell);
    RegisterSpellScriptWithArgs(spell_pvp_trinket_wotf_shared_cd<SPELL_WILL_OF_THE_FORSAKEN_COOLDOWN_TRIGGER>, "spell_pvp_trinket_shared_cd");
    RegisterSpellScriptWithArgs(spell_pvp_trinket_wotf_shared_cd<SPELL_WILL_OF_THE_FORSAKEN_COOLDOWN_TRIGGER_WOTF>, "spell_wotf_shared_cd");
    RegisterSpellScript(spell_gen_turkey_marker);
    RegisterSpellScript(spell_gen_upper_deck_create_foam_sword);
    RegisterSpellScript(spell_gen_vampiric_touch);
    RegisterSpellScript(spell_gen_vehicle_scaling);
    RegisterSpellScript(spell_gen_vendor_bark_trigger);
    RegisterSpellScript(spell_gen_wg_water);
    RegisterSpellScript(spell_gen_whisper_gulch_yogg_saron_whisper);
    RegisterSpellScript(spell_gen_whisper_to_controller);
    RegisterSpellScriptWithArgs(spell_gen_whisper_to_controller_random, "spell_future_you_whisper_to_controller_random", WHISPER_FUTURE_YOU);
    RegisterSpellScriptWithArgs(spell_gen_whisper_to_controller_random, "spell_wyrmrest_defender_whisper_to_controller_random", WHISPER_DEFENDER);
    RegisterSpellScriptWithArgs(spell_gen_whisper_to_controller_random, "spell_past_you_whisper_to_controller_random", WHISPER_PAST_YOU);
    RegisterSpellScript(spell_gen_eject_all_passengers);
    RegisterSpellScript(spell_gen_eject_passenger);
    RegisterSpellScriptWithArgs(spell_gen_eject_passenger_with_seatId, "spell_gen_eject_passenger_1", 0);
    RegisterSpellScriptWithArgs(spell_gen_eject_passenger_with_seatId, "spell_gen_eject_passenger_3", 2);
    RegisterSpellScript(spell_gen_gm_freeze);
    RegisterSpellScript(spell_gen_stand);
    RegisterSpellScript(spell_gen_mixology_bonus);
    RegisterSpellScript(spell_gen_landmine_knockback_achievement);
    RegisterSpellScript(spell_gen_clear_debuffs);
    RegisterSpellScript(spell_gen_pony_mount_check);
    RegisterSpellScript(spell_corrupting_plague_aura);
    RegisterSpellScript(spell_stasis_field_aura);
    RegisterSpellScript(spell_gen_vehicle_control_link);
    RegisterSpellScript(spell_freezing_circle);
    RegisterSpellScript(spell_gen_charmed_unit_spell_cooldown);
    RegisterSpellScript(spell_gen_cannon_blast);
    RegisterSpellScript(spell_gen_submerged);
    RegisterSpellScript(spell_gen_decimatus_transformation_sickness);
    RegisterSpellScript(spell_gen_anetheron_summon_towering_infernal);
    RegisterSpellAndAuraScriptPair(spell_gen_mark_of_kazrogal_hellfire, spell_gen_mark_of_kazrogal_hellfire_aura);
    RegisterSpellScript(spell_gen_azgalor_rain_of_fire_hellfire_citadel);
    RegisterSpellScript(spell_gen_face_rage);
    RegisterSpellScript(spell_gen_impatient_mind);
    RegisterSpellScript(spell_gen_boost_2_0_paladin_priest_watch_for_shield);
    RegisterSpellScript(spell_gen_war_mode_enlisted);
    RegisterSpellScript(spell_defender_of_azeroth_death_gate_selector);
    RegisterSpellScript(spell_defender_of_azeroth_speak_with_mograine);
    RegisterSpellScript(spell_summon_battle_pet);
    RegisterSpellScript(spell_gen_trainer_heal_cooldown);
    RegisterSpellScript(spell_gen_anchor_here);
    RegisterSpellScript(spell_gen_mount_check_aura);
    RegisterSpellScript(spell_gen_ancestral_call);
    RegisterSpellScript(spell_gen_eject_passengers_3_8);
    RegisterSpellScript(spell_gen_reverse_cast_target_to_caster_triggered);
    RegisterSpellScript(spell_gen_despawn_all_summons_owned_by_caster);
    RegisterSpellScript(spell_gen_skinning);
    RegisterSpellScriptWithArgs(spell_gen_bloodlust, "spell_sha_bloodlust", SPELL_SHAMAN_SATED);
    RegisterSpellScriptWithArgs(spell_gen_bloodlust, "spell_sha_heroism", SPELL_SHAMAN_EXHAUSTION);
    RegisterSpellScriptWithArgs(spell_gen_bloodlust, "spell_mage_time_warp", SPELL_MAGE_TEMPORAL_DISPLACEMENT);
    RegisterSpellScriptWithArgs(spell_gen_bloodlust, "spell_hun_primal_rage", SPELL_HUNTER_FATIGUED);
    RegisterSpellScriptWithArgs(spell_gen_bloodlust, "spell_evo_fury_of_the_aspects", SPELL_EVOKER_EXHAUSTION);
    RegisterSpellScriptWithArgs(spell_gen_bloodlust, "spell_item_bloodlust_drums", SPELL_SHAMAN_EXHAUSTION);
    RegisterSpellScript(spell_gen_spirit_heal_aoe);
    RegisterSpellScript(spell_gen_spirit_heal_personal);
    RegisterSpellScript(spell_gen_spirit_heal_channel);
    RegisterSpellScript(spell_gen_waiting_to_resurrect);
    RegisterSpellScript(spell_gen_major_healing_cooldown_modifier);
    RegisterSpellScript(spell_gen_major_healing_cooldown_modifier_aura);
    RegisterSpellScript(spell_gen_random_aggro_taunt);
    RegisterSpellScriptWithArgs(spell_gen_set_health, "spell_gen_set_health_1", 1);
    RegisterSpellScriptWithArgs(spell_gen_set_health, "spell_gen_set_health_100", 100);
    RegisterSpellScriptWithArgs(spell_gen_set_health, "spell_gen_set_health_500", 500);
}
