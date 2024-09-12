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
 * Scripts for spells with SPELLFAMILY_SHAMAN and SPELLFAMILY_GENERIC spells used by shaman players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_sha_".
 */

#include "ScriptMgr.h"
#include "AreaTriggerAI.h"
#include "CellImpl.h"
#include "Containers.h"
#include "CreatureAIImpl.h" // for RAND()
#include "GridNotifiersImpl.h"
#include "Item.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum ShamanSpells
{
    SPELL_SHAMAN_AFTERSHOCK_ENERGIZE            = 210712,
    SPELL_SHAMAN_ANCESTRAL_GUIDANCE             = 108281,
    SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL        = 114911,
    SPELL_SHAMAN_ARCTIC_SNOWSTORM_AREATRIGGER   = 462767,
    SPELL_SHAMAN_ARCTIC_SNOWSTORM_SLOW          = 462765,
    SPELL_SHAMAN_ASCENDANCE_ELEMENTAL           = 114050,
    SPELL_SHAMAN_ASCENDANCE_ENHANCEMENT         = 114051,
    SPELL_SHAMAN_ASCENDANCE_RESTORATION         = 114052,
    SPELL_SHAMAN_CHAIN_LIGHTNING                = 188443,
    SPELL_SHAMAN_CHAIN_LIGHTNING_ENERGIZE       = 195897,
    SPELL_SHAMAN_CHAIN_LIGHTNING_OVERLOAD       = 45297,
    SPELL_SHAMAN_CHAIN_LIGHTNING_OVERLOAD_ENERGIZE = 218558,
    SPELL_SHAMAN_CHAINED_HEAL                   = 70809,
    SPELL_SHAMAN_CRASH_LIGHTNING_CLEAVE         = 187878,
    SPELL_SHAMAN_DOOM_WINDS_LEGENDARY_COOLDOWN  = 335904,
    SPELL_SHAMAN_EARTHQUAKE                     = 61882,
    SPELL_SHAMAN_EARTHQUAKE_KNOCKING_DOWN       = 77505,
    SPELL_SHAMAN_EARTHQUAKE_TICK                = 77478,
    SPELL_SHAMAN_EARTH_SHIELD_HEAL              = 204290,
    SPELL_SHAMAN_EARTHEN_RAGE_PASSIVE           = 170374,
    SPELL_SHAMAN_EARTHEN_RAGE_PERIODIC          = 170377,
    SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE            = 170379,
    SPELL_SHAMAN_ECHOES_OF_GREAT_SUNDERING_LEGENDARY = 336217,
    SPELL_SHAMAN_ECHOES_OF_GREAT_SUNDERING_TALENT = 384088,
    SPELL_SHAMAN_ELECTRIFIED                    = 64930,
    SPELL_SHAMAN_ELEMENTAL_BLAST                = 117014,
    SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT           = 118522,
    SPELL_SHAMAN_ELEMENTAL_BLAST_ENERGIZE       = 344645,
    SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE          = 173183,
    SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY        = 173184,
    SPELL_SHAMAN_ELEMENTAL_BLAST_OVERLOAD       = 120588,
    SPELL_SHAMAN_ELEMENTAL_MASTERY              = 16166,
    SPELL_SHAMAN_ENERGY_SURGE                   = 40465,
    SPELL_SHAMAN_FLAME_SHOCK                    = 188389,
    SPELL_SHAMAN_FLAMETONGUE_ATTACK             = 10444,
    SPELL_SHAMAN_FLAMETONGUE_WEAPON_ENCHANT     = 334294,
    SPELL_SHAMAN_FLAMETONGUE_WEAPON_AURA        = 319778,
    SPELL_SHAMAN_FROST_SHOCK                    = 196840,
    SPELL_SHAMAN_FROST_SHOCK_ENERGIZE           = 289439,
    SPELL_SHAMAN_GATHERING_STORMS               = 198299,
    SPELL_SHAMAN_GATHERING_STORMS_BUFF          = 198300,
    SPELL_SHAMAN_GHOST_WOLF                     = 2645,
    SPELL_SHAMAN_HEALING_RAIN_VISUAL            = 147490,
    SPELL_SHAMAN_HEALING_RAIN_HEAL              = 73921,
    SPELL_SHAMAN_ICEFURY                        = 210714,
    SPELL_SHAMAN_ICEFURY_OVERLOAD               = 219271,
    SPELL_SHAMAN_IGNEOUS_POTENTIAL              = 279830,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD          = 23552,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE   = 27635,
    SPELL_SHAMAN_ITEM_MANA_SURGE                = 23571,
    SPELL_SHAMAN_LAVA_BEAM                      = 114074,
    SPELL_SHAMAN_LAVA_BEAM_OVERLOAD             = 114738,
    SPELL_SHAMAN_LAVA_BURST                     = 51505,
    SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE        = 71824,
    SPELL_SHAMAN_LAVA_BURST_OVERLOAD            = 77451,
    SPELL_SHAMAN_LAVA_SURGE                     = 77762,
    SPELL_SHAMAN_LIGHTNING_BOLT                 = 188196,
    SPELL_SHAMAN_LIGHTNING_BOLT_ENERGIZE        = 214815,
    SPELL_SHAMAN_LIGHTNING_BOLT_OVERLOAD        = 45284,
    SPELL_SHAMAN_LIGHTNING_BOLT_OVERLOAD_ENERGIZE = 214816,
    SPELL_SHAMAN_LIQUID_MAGMA_HIT               = 192231,
    SPELL_SHAMAN_MAELSTROM_CONTROLLER           = 343725,
    SPELL_SHAMAN_MASTERY_ELEMENTAL_OVERLOAD     = 168534,
    SPELL_SHAMAN_PATH_OF_FLAMES_SPREAD          = 210621,
    SPELL_SHAMAN_PATH_OF_FLAMES_TALENT          = 201909,
    SPELL_SHAMAN_POWER_SURGE                    = 40466,
    SPELL_SHAMAN_RESTORATIVE_MISTS              = 114083,
    SPELL_SHAMAN_RESTORATIVE_MISTS_INITIAL      = 294020,
    SPELL_SHAMAN_RIPTIDE                        = 61295,
    SPELL_SHAMAN_SPIRIT_WOLF_TALENT             = 260878,
    SPELL_SHAMAN_SPIRIT_WOLF_PERIODIC           = 260882,
    SPELL_SHAMAN_SPIRIT_WOLF_AURA               = 260881,
    SPELL_SHAMAN_STORMKEEPER                    = 191634,
    SPELL_SHAMAN_STORMSTRIKE                    = 17364,
    SPELL_SHAMAN_T29_2P_ELEMENTAL_DAMAGE_BUFF   = 394651,
    SPELL_SHAMAN_TIDAL_WAVES                    = 53390,
    SPELL_SHAMAN_TOTEMIC_POWER_ARMOR            = 28827,
    SPELL_SHAMAN_TOTEMIC_POWER_ATTACK_POWER     = 28826,
    SPELL_SHAMAN_TOTEMIC_POWER_MP5              = 28824,
    SPELL_SHAMAN_TOTEMIC_POWER_SPELL_POWER      = 28825,
    SPELL_SHAMAN_UNDULATION_PROC                = 216251,
    SPELL_SHAMAN_UNLIMITED_POWER_BUFF           = 272737,
    SPELL_SHAMAN_VOLCANIC_SURGE                 = 408572,
    SPELL_SHAMAN_WINDFURY_ATTACK                = 25504,
    SPELL_SHAMAN_WINDFURY_ENCHANTMENT           = 334302,
    SPELL_SHAMAN_WIND_RUSH                      = 192082
};

enum ShamanSpellLabels
{
    SPELL_LABEL_SHAMAN_WINDFURY_TOTEM           = 1038,
};

enum MiscNpcs
{
    NPC_HEALING_RAIN_INVISIBLE_STALKER          = 73400
};

// 273221 - Aftershock
class spell_sha_aftershock : public AuraScript
{
    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_AFTERSHOCK_ENERGIZE });
    }

    bool CheckProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        if (Spell const* procSpell = eventInfo.GetProcSpell())
            if (Optional<int32> cost = procSpell->GetPowerTypeCostAmount(POWER_MAELSTROM))
                return cost > 0 && roll_chance_i(aurEff->GetAmount());

        return false;
    }

    void HandleEffectProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        Spell const* procSpell = eventInfo.GetProcSpell();
        int32 energize = *procSpell->GetPowerTypeCostAmount(POWER_MAELSTROM);

        eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_SHAMAN_AFTERSHOCK_ENERGIZE, CastSpellExtraArgs(energize)
            .AddSpellMod(SPELLVALUE_BASE_POINT0, energize));
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_aftershock::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_sha_aftershock::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 108281 - Ancestral Guidance
class spell_sha_ancestral_guidance : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetHealInfo() && eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->Id == SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL)
            return false;

        if (!eventInfo.GetHealInfo() && !eventInfo.GetDamageInfo())
            return false;

        return true;
    }

    void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        int32 bp0 = CalculatePct(int32(eventInfo.GetDamageInfo() ? eventInfo.GetDamageInfo()->GetDamage() : eventInfo.GetHealInfo()->GetHeal()), aurEff->GetAmount());
        if (bp0)
        {
            CastSpellExtraArgs args(aurEff);
            args.AddSpellMod(SPELLVALUE_BASE_POINT0, bp0);
            eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL, args);
        }
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_ancestral_guidance::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_sha_ancestral_guidance::HandleEffectProc, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 114911 - Ancestral Guidance Heal
class spell_sha_ancestral_guidance_heal : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_ANCESTRAL_GUIDANCE });
    }

    static void ResizeTargets(std::list<WorldObject*>& targets)
    {
        Trinity::SelectRandomInjuredTargets(targets, 3, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_ancestral_guidance_heal::ResizeTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// 462764 - Arctic Snowstorm
class spell_sha_arctic_snowstorm : public AuraScript
{
    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_ARCTIC_SNOWSTORM_AREATRIGGER });
    }

    void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo) const
    {
        eventInfo.GetActor()->CastSpell(eventInfo.GetActionTarget(), SPELL_SHAMAN_ARCTIC_SNOWSTORM_AREATRIGGER,
            TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_arctic_snowstorm::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 114052 - Ascendance (Restoration)
class spell_sha_ascendance_restoration : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_RESTORATIVE_MISTS });
    }

    bool CheckProc(ProcEventInfo& procInfo)
    {
        return procInfo.GetHealInfo() && procInfo.GetHealInfo()->GetOriginalHeal() && procInfo.GetSpellInfo()->Id != SPELL_SHAMAN_RESTORATIVE_MISTS_INITIAL;
    }

    void OnProcHeal(AuraEffect* /*aurEff*/, ProcEventInfo& procInfo)
    {
        _healToDistribute += procInfo.GetHealInfo()->GetOriginalHeal();
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        if (!_healToDistribute)
            return;

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(_healToDistribute);
        GetTarget()->CastSpell(nullptr, SPELL_SHAMAN_RESTORATIVE_MISTS, args);
        _healToDistribute = 0;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_ascendance_restoration::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_sha_ascendance_restoration::OnProcHeal, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_ascendance_restoration::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    uint32 _healToDistribute = 0;
};

// 188443 - Chain Lightning
class spell_sha_chain_lightning : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_CHAIN_LIGHTNING_ENERGIZE, SPELL_SHAMAN_MAELSTROM_CONTROLLER })
            && ValidateSpellEffect({ { SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_4 } });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (AuraEffect const* energizeAmount = GetCaster()->GetAuraEffect(SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_4))
            GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_CHAIN_LIGHTNING_ENERGIZE, CastSpellExtraArgs(energizeAmount)
                .AddSpellMod(SPELLVALUE_BASE_POINT0, energizeAmount->GetAmount() * GetUnitTargetCountForEffect(EFFECT_0)));
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sha_chain_lightning::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 45297 - Chain Lightning Overload
class spell_sha_chain_lightning_overload : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_CHAIN_LIGHTNING_OVERLOAD_ENERGIZE, SPELL_SHAMAN_MAELSTROM_CONTROLLER })
            && ValidateSpellEffect({ { SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_5 } });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (AuraEffect const* energizeAmount = GetCaster()->GetAuraEffect(SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_5))
            GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_CHAIN_LIGHTNING_OVERLOAD_ENERGIZE, CastSpellExtraArgs(energizeAmount)
                .AddSpellMod(SPELLVALUE_BASE_POINT0, energizeAmount->GetAmount() * GetUnitTargetCountForEffect(EFFECT_0)));
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sha_chain_lightning_overload::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 187874 - Crash Lightning
class spell_sha_crash_lightning : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_CRASH_LIGHTNING_CLEAVE, SPELL_SHAMAN_GATHERING_STORMS, SPELL_SHAMAN_GATHERING_STORMS_BUFF });
    }

    void CountTargets(std::list<WorldObject*>& targets)
    {
        _targetsHit = targets.size();
    }

    void TriggerCleaveBuff()
    {
        if (_targetsHit >= 2)
            GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_CRASH_LIGHTNING_CLEAVE, true);

        if (AuraEffect const* gatheringStorms = GetCaster()->GetAuraEffect(SPELL_SHAMAN_GATHERING_STORMS, EFFECT_0))
        {
            CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
            args.AddSpellMod(SPELLVALUE_BASE_POINT0, int32(gatheringStorms->GetAmount() * _targetsHit));
            GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_GATHERING_STORMS_BUFF, args);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_crash_lightning::CountTargets, EFFECT_0, TARGET_UNIT_CONE_CASTER_TO_DEST_ENEMY);
        AfterCast += SpellCastFn(spell_sha_crash_lightning::TriggerCleaveBuff);
    }

    size_t _targetsHit = 0;
};

// 378270 - Deeply Rooted Elements
class spell_sha_deeply_rooted_elements : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_LAVA_BURST, SPELL_SHAMAN_STORMSTRIKE, SPELL_SHAMAN_RIPTIDE,
                SPELL_SHAMAN_ASCENDANCE_ELEMENTAL, SPELL_SHAMAN_ASCENDANCE_ENHANCEMENT, SPELL_SHAMAN_ASCENDANCE_RESTORATION })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } })
            && spellInfo->GetEffect(EFFECT_0).IsAura();
    }

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    template<uint32 requiredSpellId>
    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo& procInfo)
    {
        if (!procInfo.GetSpellInfo())
            return false;

        if (procInfo.GetSpellInfo()->Id != requiredSpellId)
            return false;

        return roll_chance_i(_procAttempts++ - 2);
    }

    template<uint32 ascendanceSpellId>
    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        _procAttempts = 0;

        Unit* target = eventInfo.GetActor();

        int32 duration = GetEffect(EFFECT_0)->GetAmount();
        if (Aura const* ascendanceAura = target->GetAura(ascendanceSpellId))
            duration += ascendanceAura->GetDuration();

        target->CastSpell(target, ascendanceSpellId,
            CastSpellExtraArgs(TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD | TRIGGERED_IGNORE_CAST_IN_PROGRESS)
            .SetTriggeringAura(aurEff)
            .SetTriggeringSpell(eventInfo.GetProcSpell())
            .AddSpellMod(SPELLVALUE_DURATION, duration));
    }

    void Register() override
    {
        if (!GetAura() || GetUnitOwner()->ToPlayer()->GetPrimarySpecialization() == ChrSpecialization::ShamanElemental)
        {
            DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_deeply_rooted_elements::CheckProc<SPELL_SHAMAN_LAVA_BURST>, EFFECT_1, SPELL_AURA_DUMMY);
            OnEffectProc += AuraEffectProcFn(spell_sha_deeply_rooted_elements::HandleProc<SPELL_SHAMAN_ASCENDANCE_ELEMENTAL>, EFFECT_1, SPELL_AURA_DUMMY);
        }

        if (!GetAura() || GetUnitOwner()->ToPlayer()->GetPrimarySpecialization() == ChrSpecialization::ShamanEnhancement)
        {
            DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_deeply_rooted_elements::CheckProc<SPELL_SHAMAN_STORMSTRIKE>, EFFECT_2, SPELL_AURA_DUMMY);
            OnEffectProc += AuraEffectProcFn(spell_sha_deeply_rooted_elements::HandleProc<SPELL_SHAMAN_ASCENDANCE_ENHANCEMENT>, EFFECT_2, SPELL_AURA_DUMMY);
        }

        if (!GetAura() || GetUnitOwner()->ToPlayer()->GetPrimarySpecialization() == ChrSpecialization::ShamanRestoration)
        {
            DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_deeply_rooted_elements::CheckProc<SPELL_SHAMAN_RIPTIDE>, EFFECT_3, SPELL_AURA_DUMMY);
            OnEffectProc += AuraEffectProcFn(spell_sha_deeply_rooted_elements::HandleProc<SPELL_SHAMAN_ASCENDANCE_RESTORATION>, EFFECT_3, SPELL_AURA_DUMMY);
        }
    }

    int32 _procAttempts = 0;
};

// 335902 - Doom Winds
class spell_sha_doom_winds_legendary : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_DOOM_WINDS_LEGENDARY_COOLDOWN });
    }

    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo& procInfo)
    {
        if (GetTarget()->HasAura(SPELL_SHAMAN_DOOM_WINDS_LEGENDARY_COOLDOWN))
            return false;

        SpellInfo const* spellInfo = procInfo.GetSpellInfo();
        if (!spellInfo)
            return false;

        return spellInfo->HasLabel(SPELL_LABEL_SHAMAN_WINDFURY_TOTEM);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_doom_winds_legendary::CheckProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 207778 - Downpour
class spell_sha_downpour : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::SelectRandomInjuredTargets(targets, 6, true);
    }

    void CountEffectivelyHealedTarget()
    {
        // Cooldown increased for each target effectively healed
        if (GetHitHeal())
            ++_healedTargets;
    }

    void HandleCooldown()
    {
        SpellHistory::Duration cooldown = Milliseconds(GetSpellInfo()->RecoveryTime) + Seconds(GetEffectInfo(EFFECT_1).CalcValue() * _healedTargets);
        GetCaster()->GetSpellHistory()->StartCooldown(GetSpellInfo(), 0, GetSpell(), false, cooldown);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_downpour::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        AfterHit += SpellHitFn(spell_sha_downpour::CountEffectivelyHealedTarget);
        AfterCast += SpellCastFn(spell_sha_downpour::HandleCooldown);
    }

    int32 _healedTargets = 0;
};

// 204288 - Earth Shield
class spell_sha_earth_shield : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_EARTH_SHIELD_HEAL });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (!eventInfo.GetDamageInfo() || !HasEffect(EFFECT_1) || eventInfo.GetDamageInfo()->GetDamage() < GetTarget()->CountPctFromMaxHealth(GetEffect(EFFECT_1)->GetAmount()))
            return false;
        return true;
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_EARTH_SHIELD_HEAL, CastSpellExtraArgs(aurEff)
            .SetOriginalCaster(GetCasterGUID()));
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_earth_shield::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_sha_earth_shield::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 8042 - Earth Shock
class spell_sha_earth_shock : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_SHAMAN_T29_2P_ELEMENTAL_DAMAGE_BUFF, EFFECT_0 } });
    }

    void AddScriptedDamageMods()
    {
        if (AuraEffect* t29 = GetCaster()->GetAuraEffect(SPELL_SHAMAN_T29_2P_ELEMENTAL_DAMAGE_BUFF, EFFECT_0))
        {
            SetHitDamage(CalculatePct(GetHitDamage(), 100 + t29->GetAmount()));
            t29->GetBase()->Remove();
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_sha_earth_shock::AddScriptedDamageMods);
    }
};

// 170374 - Earthen Rage (Passive)
class spell_sha_earthen_rage_passive : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_EARTHEN_RAGE_PERIODIC, SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE });
    }

    bool CheckProc(ProcEventInfo& procInfo)
    {
        return procInfo.GetSpellInfo() && procInfo.GetSpellInfo()->Id != SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE;
    }

    void HandleEffectProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        _procTargetGuid = eventInfo.GetProcTarget()->GetGUID();
        eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_SHAMAN_EARTHEN_RAGE_PERIODIC, true);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_earthen_rage_passive::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_sha_earthen_rage_passive::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

    ObjectGuid _procTargetGuid;

public:
    ObjectGuid const& GetProcTargetGuid() const
    {
        return _procTargetGuid;
    }
};

// 170377 - Earthen Rage (Proc Aura)
class spell_sha_earthen_rage_proc_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_EARTHEN_RAGE_PASSIVE, SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE });
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Aura const* aura = GetCaster()->GetAura(SPELL_SHAMAN_EARTHEN_RAGE_PASSIVE))
            if (spell_sha_earthen_rage_passive* script = aura->GetScript<spell_sha_earthen_rage_passive>())
                if (Unit* procTarget = ObjectAccessor::GetUnit(*GetCaster(), script->GetProcTargetGuid()))
                    GetTarget()->CastSpell(procTarget, SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_earthen_rage_proc_aura::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 61882 - Earthquake
//  8382 - AreaTriggerId
struct areatrigger_sha_earthquake : AreaTriggerAI
{
    areatrigger_sha_earthquake(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger), _refreshTimer(0s), _period(1s), _damageMultiplier(1.0f) { }

    void OnCreate(Spell const* creatingSpell) override
    {
        if (Unit* caster = at->GetCaster())
            if (AuraEffect const* earthquake = caster->GetAuraEffect(SPELL_SHAMAN_EARTHQUAKE, EFFECT_1))
                _period = Milliseconds(earthquake->GetPeriod());

        if (creatingSpell)
            if (float const* damageMultiplier = std::any_cast<float>(&creatingSpell->m_customArg))
                _damageMultiplier = *damageMultiplier;
    }

    void OnUpdate(uint32 diff) override
    {
        _refreshTimer -= Milliseconds(diff);
        while (_refreshTimer <= 0s)
        {
            if (Unit* caster = at->GetCaster())
                caster->CastSpell(at->GetPosition(), SPELL_SHAMAN_EARTHQUAKE_TICK, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                    .SetOriginalCaster(at->GetGUID())
                    .AddSpellMod(SPELLVALUE_BASE_POINT0, caster->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_NATURE) * 0.213f * _damageMultiplier));

            _refreshTimer += _period;
        }
    }

    // Each target can only be stunned once by each earthquake - keep track of who we already stunned
    bool AddStunnedTarget(ObjectGuid const& guid)
    {
        return _stunnedUnits.insert(guid).second;
    }

private:
    Milliseconds _refreshTimer;
    Milliseconds _period;
    GuidUnorderedSet _stunnedUnits;
    float _damageMultiplier;
};

// 61882 - Earthquake
class spell_sha_earthquake : public SpellScript
{
    static constexpr std::array<std::pair<uint32, SpellEffIndex>, 3> DamageBuffs =
    { {
        { SPELL_SHAMAN_ECHOES_OF_GREAT_SUNDERING_LEGENDARY, EFFECT_1 },
        { SPELL_SHAMAN_ECHOES_OF_GREAT_SUNDERING_TALENT, EFFECT_0 },
        { SPELL_SHAMAN_T29_2P_ELEMENTAL_DAMAGE_BUFF, EFFECT_0 }
    } };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect(DamageBuffs);
    }

    void SnapshotDamageMultiplier(SpellEffIndex /*effIndex*/)
    {
        float damageMultiplier = 1.0f;
        for (auto const& [spellId, effect] : DamageBuffs)
        {
            if (AuraEffect* buff = GetCaster()->GetAuraEffect(spellId, effect))
            {
                AddPct(damageMultiplier, buff->GetAmount());
                buff->GetBase()->Remove();
            }
        }

        if (damageMultiplier != 1.0f)
            GetSpell()->m_customArg = damageMultiplier;
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sha_earthquake::SnapshotDamageMultiplier, EFFECT_2, SPELL_EFFECT_CREATE_AREATRIGGER);
    }
};

// 77478 - Earthquake tick
class spell_sha_earthquake_tick : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_EARTHQUAKE_KNOCKING_DOWN })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    void HandleOnHit()
    {
        if (Unit* target = GetHitUnit())
        {
            if (roll_chance_i(GetEffectInfo(EFFECT_1).CalcValue()))
            {
                std::vector<AreaTrigger*> areaTriggers = GetCaster()->GetAreaTriggers(SPELL_SHAMAN_EARTHQUAKE);
                auto itr = std::find_if(areaTriggers.begin(), areaTriggers.end(), [&](AreaTrigger const* at)
                {
                    return at->GetGUID() == GetSpell()->GetOriginalCasterGUID();
                });
                if (itr != areaTriggers.end())
                    if (areatrigger_sha_earthquake* eq = CAST_AI(areatrigger_sha_earthquake, (*itr)->AI()))
                        if (eq->AddStunnedTarget(target->GetGUID()))
                            GetCaster()->CastSpell(target, SPELL_SHAMAN_EARTHQUAKE_KNOCKING_DOWN, true);
            }
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_sha_earthquake_tick::HandleOnHit);
    }
};

// 117014 - Elemental Blast
// 120588 - Elemental Blast Overload
class spell_sha_elemental_blast : public SpellScript
{
    static constexpr uint32 BuffSpells[] = { SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT, SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE, SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT,
            SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE,
            SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY,
            SPELL_SHAMAN_ELEMENTAL_BLAST_ENERGIZE,
            SPELL_SHAMAN_MAELSTROM_CONTROLLER
        }) && ValidateSpellEffect({
            { SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_10 },
            { SPELL_SHAMAN_T29_2P_ELEMENTAL_DAMAGE_BUFF, EFFECT_0 }
        });
    }

    void HandleEnergize(SpellEffIndex /*effIndex*/)
    {
        if (AuraEffect const* energizeAmount = GetCaster()->GetAuraEffect(SPELL_SHAMAN_MAELSTROM_CONTROLLER, GetSpellInfo()->Id == SPELL_SHAMAN_ELEMENTAL_BLAST ? EFFECT_9 : EFFECT_10))
            GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_ELEMENTAL_BLAST_ENERGIZE, CastSpellExtraArgs(energizeAmount)
                .AddSpellMod(SPELLVALUE_BASE_POINT0, energizeAmount->GetAmount()));
    }

    void TriggerBuff()
    {
        Unit* caster = GetCaster();
        uint32 spellId = *Trinity::Containers::SelectRandomWeightedContainerElement(BuffSpells, [caster](uint32 buffSpellId)
        {
            return !caster->HasAura(buffSpellId) ? 1.0 : 0.0;
        });

        GetCaster()->CastSpell(GetCaster(), spellId, TRIGGERED_FULL_MASK);
    }

    void AddScriptedDamageMods()
    {
        if (AuraEffect* t29 = GetCaster()->GetAuraEffect(SPELL_SHAMAN_T29_2P_ELEMENTAL_DAMAGE_BUFF, EFFECT_0))
        {
            SetHitDamage(CalculatePct(GetHitDamage(), 100 + t29->GetAmount()));
            t29->GetBase()->Remove();
        }
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sha_elemental_blast::HandleEnergize, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        AfterCast += SpellCastFn(spell_sha_elemental_blast::TriggerBuff);
        OnHit += SpellHitFn(spell_sha_elemental_blast::AddScriptedDamageMods);
    }
};

// 318038 - Flametongue Weapon
class spell_sha_flametongue_weapon : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_FLAMETONGUE_WEAPON_ENCHANT });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        Player* player = GetCaster()->ToPlayer();
        uint8 slot = EQUIPMENT_SLOT_MAINHAND;
        if (player->GetPrimarySpecialization() == ChrSpecialization::ShamanEnhancement)
            slot = EQUIPMENT_SLOT_OFFHAND;

        Item* targetItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
        if (!targetItem || !targetItem->GetTemplate()->IsWeapon())
            return;

        player->CastSpell(targetItem, SPELL_SHAMAN_FLAMETONGUE_WEAPON_ENCHANT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_flametongue_weapon::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 319778  - Flametongue - SPELL_SHAMAN_FLAMETONGUE_WEAPON_AURA
class spell_sha_flametongue_weapon_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_FLAMETONGUE_ATTACK });
    }

    void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* attacker = eventInfo.GetActor();
        CastSpellExtraArgs args(aurEff);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, std::max(1, int32(attacker->GetTotalAttackPowerValue(BASE_ATTACK) * 0.0264f)));
        attacker->CastSpell(eventInfo.GetActionTarget(), SPELL_SHAMAN_FLAMETONGUE_ATTACK, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_flametongue_weapon_aura::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 73920 - Healing Rain (Aura)
class spell_sha_healing_rain_aura : public AuraScript
{
public:
    void SetVisualDummy(TempSummon* summon)
    {
        _visualDummy = summon->GetGUID();
        _dest = summon->GetPosition();
    }

private:
    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        GetTarget()->CastSpell(_dest, SPELL_SHAMAN_HEALING_RAIN_HEAL, aurEff);
    }

    void HandleEffecRemoved(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* summon = ObjectAccessor::GetCreature(*GetTarget(), _visualDummy))
            summon->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_sha_healing_rain_aura::HandleEffecRemoved, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_healing_rain_aura::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }

    ObjectGuid _visualDummy;
    Position _dest;
};

// 73920 - Healing Rain
class spell_sha_healing_rain : public SpellScript
{
    void InitializeVisualStalker()
    {
        if (Aura* aura = GetHitAura())
        {
            if (WorldLocation const* dest = GetExplTargetDest())
            {
                Milliseconds duration = Milliseconds(GetSpellInfo()->CalcDuration(GetOriginalCaster()));
                TempSummon* summon = GetCaster()->GetMap()->SummonCreature(NPC_HEALING_RAIN_INVISIBLE_STALKER, *dest, nullptr, duration, GetOriginalCaster());
                if (!summon)
                    return;

                summon->CastSpell(summon, SPELL_SHAMAN_HEALING_RAIN_VISUAL, true);

                if (spell_sha_healing_rain_aura* script = aura->GetScript<spell_sha_healing_rain_aura>())
                    script->SetVisualDummy(summon);
            }
        }
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_sha_healing_rain::InitializeVisualStalker);
    }
};

// 73921 - Healing Rain
class spell_sha_healing_rain_target_limit : public SpellScript
{
    void SelectTargets(std::list<WorldObject*>& targets)
    {
        Trinity::SelectRandomInjuredTargets(targets, 6, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_healing_rain_target_limit::SelectTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// 52042 - Healing Stream Totem
class spell_sha_healing_stream_totem_heal : public SpellScript
{
    void SelectTargets(std::list<WorldObject*>& targets)
    {
        Trinity::SelectRandomInjuredTargets(targets, 1, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_healing_stream_totem_heal::SelectTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// 210714 - Icefury
class spell_sha_icefury : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_FROST_SHOCK_ENERGIZE });
    }

    void HandleEffectProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_SHAMAN_FROST_SHOCK_ENERGIZE, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_icefury::HandleEffectProc, EFFECT_1, SPELL_AURA_ADD_PCT_MODIFIER);
    }
};

// 23551 - Lightning Shield T2 Bonus
class spell_sha_item_lightning_shield : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_item_lightning_shield::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 23552 - Lightning Shield T2 Bonus
class spell_sha_item_lightning_shield_trigger : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_item_lightning_shield_trigger::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 23572 - Mana Surge
class spell_sha_item_mana_surge : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_ITEM_MANA_SURGE });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetProcSpell() != nullptr;
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        std::vector<SpellPowerCost> const& costs = eventInfo.GetProcSpell()->GetPowerCost();
        auto m = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_MANA; });
        if (m != costs.end())
        {
            int32 mana = CalculatePct(m->Amount, 35);
            if (mana > 0)
            {
                CastSpellExtraArgs args(aurEff);
                args.AddSpellMod(SPELLVALUE_BASE_POINT0, mana);
                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_ITEM_MANA_SURGE, args);
            }
        }
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_item_mana_surge::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_sha_item_mana_surge::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 40463 - Shaman Tier 6 Trinket
class spell_sha_item_t6_trinket : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SHAMAN_ENERGY_SURGE,
            SPELL_SHAMAN_POWER_SURGE
        });
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo)
            return;

        uint32 spellId;
        int32 chance;

        // Lesser Healing Wave
        if (spellInfo->SpellFamilyFlags[0] & 0x00000080)
        {
            spellId = SPELL_SHAMAN_ENERGY_SURGE;
            chance = 10;
        }
        // Lightning Bolt
        else if (spellInfo->SpellFamilyFlags[0] & 0x00000001)
        {
            spellId = SPELL_SHAMAN_ENERGY_SURGE;
            chance = 15;
        }
        // Stormstrike
        else if (spellInfo->SpellFamilyFlags[1] & 0x00000010)
        {
            spellId = SPELL_SHAMAN_POWER_SURGE;
            chance = 50;
        }
        else
            return;

        if (roll_chance_i(chance))
            eventInfo.GetActor()->CastSpell(nullptr, spellId, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_item_t6_trinket::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 70811 - Item - Shaman T10 Elemental 2P Bonus
class spell_sha_item_t10_elemental_2p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_ELEMENTAL_MASTERY });
    }

    void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        if (Player* target = GetTarget()->ToPlayer())
            target->GetSpellHistory()->ModifyCooldown(SPELL_SHAMAN_ELEMENTAL_MASTERY, Milliseconds(-aurEff->GetAmount()));
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_item_t10_elemental_2p_bonus::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 189063 - Lightning Vortex (proc 185881 Item - Shaman T18 Elemental 4P Bonus)
class spell_sha_item_t18_elemental_4p_bonus : public AuraScript
{
    void DiminishHaste(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        if (AuraEffect* hasteBuff = GetEffect(EFFECT_0))
            hasteBuff->ChangeAmount(hasteBuff->GetAmount() - aurEff->GetAmount());
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_item_t18_elemental_4p_bonus::DiminishHaste, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 51505 - Lava burst
class spell_sha_lava_burst : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_PATH_OF_FLAMES_TALENT, SPELL_SHAMAN_PATH_OF_FLAMES_SPREAD, SPELL_SHAMAN_LAVA_SURGE });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (caster->HasAura(SPELL_SHAMAN_PATH_OF_FLAMES_TALENT))
                caster->CastSpell(GetHitUnit(), SPELL_SHAMAN_PATH_OF_FLAMES_SPREAD, GetSpell());
    }

    void EnsureLavaSurgeCanBeImmediatelyConsumed()
    {
        Unit* caster = GetCaster();

        if (Aura* lavaSurge = caster->GetAura(SPELL_SHAMAN_LAVA_SURGE))
        {
            if (!GetSpell()->m_appliedMods.count(lavaSurge))
            {
                uint32 chargeCategoryId = GetSpellInfo()->ChargeCategoryId;

                // Ensure we have at least 1 usable charge after cast to allow next cast immediately
                if (!caster->GetSpellHistory()->HasCharge(chargeCategoryId))
                    caster->GetSpellHistory()->RestoreCharge(chargeCategoryId);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_lava_burst::HandleScript, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
        AfterCast += SpellCastFn(spell_sha_lava_burst::EnsureLavaSurgeCanBeImmediatelyConsumed);
    }
};

// 285452 - Lava Burst damage
// 285466 - Lava Burst Overload damage
class spell_sha_lava_crit_chance : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_FLAME_SHOCK });
    }

    void CalcCritChance(Unit const* victim, float& chance)
    {
        Unit* caster = GetCaster();

        if (!caster || !victim)
            return;

        if (victim->HasAura(SPELL_SHAMAN_FLAME_SHOCK, caster->GetGUID()))
            if (victim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE) > -100)
                chance = 100.f;
    }

    void Register() override
    {
        OnCalcCritChance += SpellOnCalcCritChanceFn(spell_sha_lava_crit_chance::CalcCritChance);
    }
};

// 77756 - Lava Surge
class spell_sha_lava_surge : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_LAVA_SURGE, SPELL_SHAMAN_IGNEOUS_POTENTIAL });
    }

    bool CheckProcChance(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        int32 procChance = aurEff->GetAmount();
        if (AuraEffect const* igneousPotential = GetTarget()->GetAuraEffect(SPELL_SHAMAN_IGNEOUS_POTENTIAL, EFFECT_0))
            procChance += igneousPotential->GetAmount();

        return roll_chance_i(procChance);
    }

    void HandleEffectProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_LAVA_SURGE, true);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_lava_surge::CheckProcChance, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_sha_lava_surge::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 77762 - Lava Surge
class spell_sha_lava_surge_proc : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_LAVA_BURST });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void ResetCooldown()
    {
        GetCaster()->GetSpellHistory()->RestoreCharge(sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_LAVA_BURST, GetCastDifficulty())->ChargeCategoryId);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_sha_lava_surge_proc::ResetCooldown);
    }
};

// 188196 - Lightning Bolt
class spell_sha_lightning_bolt : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_LIGHTNING_BOLT_ENERGIZE, SPELL_SHAMAN_MAELSTROM_CONTROLLER })
            && ValidateSpellEffect({ { SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_0 } });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (AuraEffect const* energizeAmount = GetCaster()->GetAuraEffect(SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_0))
            GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_LIGHTNING_BOLT_ENERGIZE, CastSpellExtraArgs(energizeAmount)
                .AddSpellMod(SPELLVALUE_BASE_POINT0, energizeAmount->GetAmount()));
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sha_lightning_bolt::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 45284 - Lightning Bolt Overload
class spell_sha_lightning_bolt_overload : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_LIGHTNING_BOLT_OVERLOAD_ENERGIZE, SPELL_SHAMAN_MAELSTROM_CONTROLLER })
            && ValidateSpellEffect({ { SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_1 } });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (AuraEffect const* energizeAmount = GetCaster()->GetAuraEffect(SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_1))
            GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_LIGHTNING_BOLT_OVERLOAD_ENERGIZE, CastSpellExtraArgs(energizeAmount)
                .AddSpellMod(SPELLVALUE_BASE_POINT0, energizeAmount->GetAmount()));
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sha_lightning_bolt_overload::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 192223 - Liquid Magma Totem (erupting hit spell)
class spell_sha_liquid_magma_totem : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_LIQUID_MAGMA_HIT });
    }

    void HandleEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* hitUnit = GetHitUnit())
            GetCaster()->CastSpell(hitUnit, SPELL_SHAMAN_LIQUID_MAGMA_HIT, true);
    }

    void HandleTargetSelect(std::list<WorldObject*>& targets)
    {
        // choose one random target from targets
        if (targets.size() > 1)
        {
            WorldObject* selected = Trinity::Containers::SelectRandomContainerElement(targets);
            targets.clear();
            targets.push_back(selected);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_liquid_magma_totem::HandleTargetSelect, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_sha_liquid_magma_totem::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 168534 - Mastery: Elemental Overload (passive)
class spell_sha_mastery_elemental_overload : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_SHAMAN_LIGHTNING_BOLT,
            SPELL_SHAMAN_LIGHTNING_BOLT_OVERLOAD,
            SPELL_SHAMAN_ELEMENTAL_BLAST,
            SPELL_SHAMAN_ELEMENTAL_BLAST_OVERLOAD,
            SPELL_SHAMAN_ICEFURY,
            SPELL_SHAMAN_ICEFURY_OVERLOAD,
            SPELL_SHAMAN_LAVA_BURST,
            SPELL_SHAMAN_LAVA_BURST_OVERLOAD,
            SPELL_SHAMAN_CHAIN_LIGHTNING,
            SPELL_SHAMAN_CHAIN_LIGHTNING_OVERLOAD,
            SPELL_SHAMAN_LAVA_BEAM,
            SPELL_SHAMAN_LAVA_BEAM_OVERLOAD,
            SPELL_SHAMAN_STORMKEEPER
        });
    }

    bool CheckProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo || !eventInfo.GetProcSpell())
            return false;

        if (!GetTriggeredSpellId(spellInfo->Id))
            return false;

        float chance = aurEff->GetAmount();   // Mastery % amount

        if (spellInfo->Id == SPELL_SHAMAN_CHAIN_LIGHTNING)
            chance /= 3.0f;

        if (Aura* stormkeeper = eventInfo.GetActor()->GetAura(SPELL_SHAMAN_STORMKEEPER))
            if (eventInfo.GetProcSpell()->m_appliedMods.find(stormkeeper) != eventInfo.GetProcSpell()->m_appliedMods.end())
                chance = 100.0f;

        return roll_chance_f(chance);
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& procInfo)
    {
        PreventDefaultAction();

        Unit* caster = procInfo.GetActor();

        caster->m_Events.AddEventAtOffset([caster,
            targets = CastSpellTargetArg(procInfo.GetProcTarget()),
            overloadSpellId = GetTriggeredSpellId(procInfo.GetSpellInfo()->Id),
            originalCastId = procInfo.GetProcSpell()->m_castId]() mutable
        {
            if (!targets.Targets)
                return;

            targets.Targets->Update(caster);

            CastSpellExtraArgs args;
            args.OriginalCastId = originalCastId;
            caster->CastSpell(targets, overloadSpellId, args);
        }, 400ms);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_mastery_elemental_overload::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_sha_mastery_elemental_overload::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

    uint32 GetTriggeredSpellId(uint32 triggeringSpellId)
    {
        switch (triggeringSpellId)
        {
            case SPELL_SHAMAN_LIGHTNING_BOLT: return SPELL_SHAMAN_LIGHTNING_BOLT_OVERLOAD;
            case SPELL_SHAMAN_ELEMENTAL_BLAST: return SPELL_SHAMAN_ELEMENTAL_BLAST_OVERLOAD;
            case SPELL_SHAMAN_ICEFURY: return SPELL_SHAMAN_ICEFURY_OVERLOAD;
            case SPELL_SHAMAN_LAVA_BURST: return SPELL_SHAMAN_LAVA_BURST_OVERLOAD;
            case SPELL_SHAMAN_CHAIN_LIGHTNING: return SPELL_SHAMAN_CHAIN_LIGHTNING_OVERLOAD;
            case SPELL_SHAMAN_LAVA_BEAM: return SPELL_SHAMAN_LAVA_BEAM_OVERLOAD;
            default:
                break;
        }
        return 0;
    }
};

// 45284 - Lightning Bolt Overload
// 45297 - Chain Lightning Overload
// 114738 - Lava Beam Overload
// 120588 - Elemental Blast Overload
// 219271 - Icefury Overload
// 285466 - Lava Burst Overload
class spell_sha_mastery_elemental_overload_proc : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_MASTERY_ELEMENTAL_OVERLOAD });
    }

    void ApplyDamageModifier(SpellEffIndex /*effIndex*/)
    {
        if (AuraEffect const* elementalOverload = GetCaster()->GetAuraEffect(SPELL_SHAMAN_MASTERY_ELEMENTAL_OVERLOAD, EFFECT_1))
            SetHitDamage(CalculatePct(GetHitDamage(), elementalOverload->GetAmount()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_mastery_elemental_overload_proc::ApplyDamageModifier, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 30884 - Nature's Guardian
class spell_sha_natures_guardian : public AuraScript
{
    bool CheckProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        return eventInfo.GetActionTarget()->HealthBelowPct(aurEff->GetAmount());
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_natures_guardian::CheckProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 210621 - Path of Flames Spread
class spell_sha_path_of_flames_spread : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_FLAME_SHOCK });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetExplTargetUnit());
        Trinity::Containers::RandomResize(targets, [this](WorldObject* target)
        {
            return target->GetTypeId() == TYPEID_UNIT && !target->ToUnit()->HasAura(SPELL_SHAMAN_FLAME_SHOCK, GetCaster()->GetGUID());
        }, 1);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Unit* mainTarget = GetExplTargetUnit())
        {
            if (Aura* flameShock = mainTarget->GetAura(SPELL_SHAMAN_FLAME_SHOCK, GetCaster()->GetGUID()))
            {
                if (Aura* newAura = GetCaster()->AddAura(SPELL_SHAMAN_FLAME_SHOCK, GetHitUnit()))
                {
                    newAura->SetDuration(flameShock->GetDuration());
                    newAura->SetMaxDuration(flameShock->GetDuration());
                }
            }
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_path_of_flames_spread::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_sha_path_of_flames_spread::HandleScript, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 114083 - Restorative Mists
// 294020 - Restorative Mists
class spell_sha_restorative_mists : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        _targetCount = uint32(targets.size());
    }

    void HandleHeal(SpellEffIndex /*effIndex*/)
    {
        if (_targetCount)
            SetHitHeal(GetHitHeal() / _targetCount);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_restorative_mists::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        OnEffectHitTarget += SpellEffectFn(spell_sha_restorative_mists::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
    }

private:
    uint32 _targetCount = 0;
};

// 2645 - Ghost Wolf
// 260878 - Spirit Wolf
class spell_sha_spirit_wolf : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_GHOST_WOLF, SPELL_SHAMAN_SPIRIT_WOLF_TALENT, SPELL_SHAMAN_SPIRIT_WOLF_PERIODIC, SPELL_SHAMAN_SPIRIT_WOLF_AURA });
    }

    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_SHAMAN_SPIRIT_WOLF_TALENT) && target->HasAura(SPELL_SHAMAN_GHOST_WOLF))
            target->CastSpell(target, SPELL_SHAMAN_SPIRIT_WOLF_PERIODIC, aurEff);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_SHAMAN_SPIRIT_WOLF_PERIODIC);
        GetTarget()->RemoveAurasDueToSpell(SPELL_SHAMAN_SPIRIT_WOLF_AURA);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_sha_spirit_wolf::OnApply, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sha_spirit_wolf::OnRemove, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 51564 - Tidal Waves
class spell_sha_tidal_waves : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_TIDAL_WAVES });
    }

    void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        CastSpellExtraArgs args(aurEff);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, -aurEff->GetAmount());
        args.AddSpellMod(SPELLVALUE_BASE_POINT1, aurEff->GetAmount());

        GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_TIDAL_WAVES, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_tidal_waves::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 28823 - Totemic Power
class spell_sha_t3_6p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SHAMAN_TOTEMIC_POWER_ARMOR,
            SPELL_SHAMAN_TOTEMIC_POWER_ATTACK_POWER,
            SPELL_SHAMAN_TOTEMIC_POWER_SPELL_POWER,
            SPELL_SHAMAN_TOTEMIC_POWER_MP5
        });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        uint32 spellId;
        Unit* caster = eventInfo.GetActor();
        Unit* target = eventInfo.GetProcTarget();

        switch (target->GetClass())
        {
            case CLASS_PALADIN:
            case CLASS_PRIEST:
            case CLASS_SHAMAN:
            case CLASS_DRUID:
                spellId = SPELL_SHAMAN_TOTEMIC_POWER_MP5;
                break;
            case CLASS_MAGE:
            case CLASS_WARLOCK:
                spellId = SPELL_SHAMAN_TOTEMIC_POWER_SPELL_POWER;
                break;
            case CLASS_HUNTER:
            case CLASS_ROGUE:
                spellId = SPELL_SHAMAN_TOTEMIC_POWER_ATTACK_POWER;
                break;
            case CLASS_WARRIOR:
                spellId = SPELL_SHAMAN_TOTEMIC_POWER_ARMOR;
                break;
            default:
                return;
        }

        caster->CastSpell(target, spellId, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_t3_6p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 28820 - Lightning Shield
class spell_sha_t3_8p_bonus : public AuraScript
{
    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();

        // Need remove self if Lightning Shield not active
        if (!GetTarget()->GetAuraEffect(SPELL_AURA_PROC_TRIGGER_SPELL, SPELLFAMILY_SHAMAN, flag128(0x400), GetCaster()->GetGUID()))
            Remove();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_t3_8p_bonus::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 64928 - Item - Shaman T8 Elemental 4P Bonus
class spell_sha_t8_elemental_4p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_ELECTRIFIED });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_ELECTRIFIED, GetCastDifficulty());
        int32 amount = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());

        ASSERT(spellInfo->GetMaxTicks() > 0);
        amount /= spellInfo->GetMaxTicks();

        Unit* caster = eventInfo.GetActor();
        Unit* target = eventInfo.GetProcTarget();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(amount);
        caster->CastSpell(target, SPELL_SHAMAN_ELECTRIFIED, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_t8_elemental_4p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 67228 - Item - Shaman T9 Elemental 4P Bonus (Lava Burst)
class spell_sha_t9_elemental_4p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE, GetCastDifficulty());
        int32 amount = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());

        ASSERT(spellInfo->GetMaxTicks() > 0);
        amount /= spellInfo->GetMaxTicks();

        Unit* caster = eventInfo.GetActor();
        Unit* target = eventInfo.GetProcTarget();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(amount);
        caster->CastSpell(target, SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_t9_elemental_4p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 70817 - Item - Shaman T10 Elemental 4P Bonus
class spell_sha_t10_elemental_4p_bonus : public AuraScript
{
    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* caster = eventInfo.GetActor();
        Unit* target = eventInfo.GetProcTarget();

        // try to find spell Flame Shock on the target
        AuraEffect* flameShock = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_SHAMAN, flag128(0x10000000), caster->GetGUID());
        if (!flameShock)
            return;

        Aura* flameShockAura = flameShock->GetBase();

        int32 maxDuration = flameShockAura->GetMaxDuration();
        int32 newDuration = flameShockAura->GetDuration() + aurEff->GetAmount() * IN_MILLISECONDS;

        flameShockAura->SetDuration(newDuration);
        // is it blizzlike to change max duration for FS?
        if (newDuration > maxDuration)
            flameShockAura->SetMaxDuration(newDuration);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_t10_elemental_4p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 70808 - Item - Shaman T10 Restoration 4P Bonus
class spell_sha_t10_restoration_4p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_CHAINED_HEAL });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        HealInfo* healInfo = eventInfo.GetHealInfo();
        if (!healInfo || !healInfo->GetHeal())
            return;

        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_CHAINED_HEAL, GetCastDifficulty());
        int32 amount = CalculatePct(static_cast<int32>(healInfo->GetHeal()), aurEff->GetAmount());

        ASSERT(spellInfo->GetMaxTicks() > 0);
        amount /= spellInfo->GetMaxTicks();

        Unit* caster = eventInfo.GetActor();
        Unit* target = eventInfo.GetProcTarget();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(amount);
        caster->CastSpell(target, SPELL_SHAMAN_CHAINED_HEAL, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_t10_restoration_4p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 260895 - Unlimited Power
class spell_sha_unlimited_power : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_UNLIMITED_POWER_BUFF });
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& procInfo)
    {
        Unit* caster = procInfo.GetActor();
        if (Aura* aura = caster->GetAura(SPELL_SHAMAN_UNLIMITED_POWER_BUFF))
            aura->SetStackAmount(aura->GetStackAmount() + 1);
        else
            caster->CastSpell(caster, SPELL_SHAMAN_UNLIMITED_POWER_BUFF, procInfo.GetProcSpell());
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_unlimited_power::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 200071 - Undulation
class spell_sha_undulation_passive : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_UNDULATION_PROC });
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        if (++_castCounter == 3)
        {
            GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_UNDULATION_PROC, true);
            _castCounter = 0;
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_undulation_passive::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

    uint8 _castCounter = 1; // first proc happens after two casts, then one every 3 casts
};

// 33757 - Windfury Weapon
class spell_sha_windfury_weapon : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_WINDFURY_ENCHANTMENT });
    }

    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    void HandleEffect(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        if (Item* mainHand = GetCaster()->ToPlayer()->GetWeaponForAttack(BASE_ATTACK, false))
            GetCaster()->CastSpell(mainHand, SPELL_SHAMAN_WINDFURY_ENCHANTMENT, GetSpell());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_windfury_weapon::HandleEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 319773 - Windfury Weapon (proc)
class spell_sha_windfury_weapon_proc : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_WINDFURY_ATTACK });
    }

    void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        for (uint32 i = 0; i < 2; ++i)
            eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_SHAMAN_WINDFURY_ATTACK, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_windfury_weapon_proc::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 378269 - Windspeaker's Lava Resurgence
class spell_sha_windspeakers_lava_resurgence : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_VOLCANIC_SURGE });
    }

    void PreventLavaSurge(SpellEffIndex effIndex)
    {
        if (GetCaster()->HasAura(SPELL_SHAMAN_VOLCANIC_SURGE))
            PreventHitDefaultEffect(effIndex);
    }

    void PreventVolcanicSurge(SpellEffIndex effIndex)
    {
        if (!GetCaster()->HasAura(SPELL_SHAMAN_VOLCANIC_SURGE))
            PreventHitDefaultEffect(effIndex);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sha_windspeakers_lava_resurgence::PreventLavaSurge, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
        OnEffectLaunch += SpellEffectFn(spell_sha_windspeakers_lava_resurgence::PreventVolcanicSurge, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
    }
};

// 462767 - Arctic Snowstorm
// 36797 - AreatriggerId
struct areatrigger_sha_arctic_snowstorm : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (unit->GetAura(SPELL_SHAMAN_FROST_SHOCK, caster->GetGUID()))
                return;

            if (caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_SHAMAN_ARCTIC_SNOWSTORM_SLOW, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_SHAMAN_ARCTIC_SNOWSTORM_SLOW, at->GetCasterGuid());
    }
};

// 192078 - Wind Rush Totem (Spell)
// 12676 - AreaTriggerId
struct areatrigger_sha_wind_rush_totem : AreaTriggerAI
{
    static constexpr uint32 REFRESH_TIME = 4500;

    areatrigger_sha_wind_rush_totem(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger), _refreshTimer(REFRESH_TIME) { }

    void OnUpdate(uint32 diff) override
    {
        _refreshTimer -= diff;
        if (_refreshTimer <= 0)
        {
            if (Unit* caster = at->GetCaster())
            {
                for (ObjectGuid const& guid : at->GetInsideUnits())
                {
                    if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    {
                        if (!caster->IsFriendlyTo(unit))
                            continue;

                        caster->CastSpell(unit, SPELL_SHAMAN_WIND_RUSH, true);
                    }
                }
            }
            _refreshTimer += REFRESH_TIME;
        }
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (!caster->IsFriendlyTo(unit))
                return;

            caster->CastSpell(unit, SPELL_SHAMAN_WIND_RUSH, true);
        }
    }
private:
    int32 _refreshTimer;
};

void AddSC_shaman_spell_scripts()
{
    RegisterSpellScript(spell_sha_aftershock);
    RegisterSpellScript(spell_sha_ancestral_guidance);
    RegisterSpellScript(spell_sha_ancestral_guidance_heal);
    RegisterSpellScript(spell_sha_arctic_snowstorm);
    RegisterSpellScript(spell_sha_ascendance_restoration);
    RegisterSpellScript(spell_sha_chain_lightning);
    RegisterSpellScript(spell_sha_chain_lightning_overload);
    RegisterSpellScript(spell_sha_crash_lightning);
    RegisterSpellScript(spell_sha_deeply_rooted_elements);
    RegisterSpellScript(spell_sha_doom_winds_legendary);
    RegisterSpellScript(spell_sha_downpour);
    RegisterSpellScript(spell_sha_earth_shield);
    RegisterSpellScript(spell_sha_earth_shock);
    RegisterSpellScript(spell_sha_earthen_rage_passive);
    RegisterSpellScript(spell_sha_earthen_rage_proc_aura);
    RegisterAreaTriggerAI(areatrigger_sha_earthquake);
    RegisterSpellScript(spell_sha_earthquake);
    RegisterSpellScript(spell_sha_earthquake_tick);
    RegisterSpellScript(spell_sha_elemental_blast);
    RegisterSpellScript(spell_sha_flametongue_weapon);
    RegisterSpellScript(spell_sha_flametongue_weapon_aura);
    RegisterSpellAndAuraScriptPair(spell_sha_healing_rain, spell_sha_healing_rain_aura);
    RegisterSpellScript(spell_sha_healing_rain_target_limit);
    RegisterSpellScript(spell_sha_healing_stream_totem_heal);
    RegisterSpellScript(spell_sha_icefury);
    RegisterSpellScript(spell_sha_item_lightning_shield);
    RegisterSpellScript(spell_sha_item_lightning_shield_trigger);
    RegisterSpellScript(spell_sha_item_mana_surge);
    RegisterSpellScript(spell_sha_item_t6_trinket);
    RegisterSpellScript(spell_sha_item_t10_elemental_2p_bonus);
    RegisterSpellScript(spell_sha_item_t18_elemental_4p_bonus);
    RegisterSpellScript(spell_sha_lava_burst);
    RegisterSpellScript(spell_sha_lava_crit_chance);
    RegisterSpellScript(spell_sha_lava_surge);
    RegisterSpellScript(spell_sha_lava_surge_proc);
    RegisterSpellScript(spell_sha_lightning_bolt);
    RegisterSpellScript(spell_sha_lightning_bolt_overload);
    RegisterSpellScript(spell_sha_liquid_magma_totem);
    RegisterSpellScript(spell_sha_mastery_elemental_overload);
    RegisterSpellScript(spell_sha_mastery_elemental_overload_proc);
    RegisterSpellScript(spell_sha_natures_guardian);
    RegisterSpellScript(spell_sha_path_of_flames_spread);
    RegisterSpellScript(spell_sha_restorative_mists);
    RegisterSpellScript(spell_sha_spirit_wolf);
    RegisterSpellScript(spell_sha_tidal_waves);
    RegisterSpellScript(spell_sha_t3_6p_bonus);
    RegisterSpellScript(spell_sha_t3_8p_bonus);
    RegisterSpellScript(spell_sha_t8_elemental_4p_bonus);
    RegisterSpellScript(spell_sha_t9_elemental_4p_bonus);
    RegisterSpellScript(spell_sha_t10_elemental_4p_bonus);
    RegisterSpellScript(spell_sha_t10_restoration_4p_bonus);
    RegisterSpellScript(spell_sha_unlimited_power);
    RegisterSpellScript(spell_sha_undulation_passive);
    RegisterSpellScript(spell_sha_windfury_weapon);
    RegisterSpellScript(spell_sha_windfury_weapon_proc);
    RegisterSpellScript(spell_sha_windspeakers_lava_resurgence);
    RegisterAreaTriggerAI(areatrigger_sha_arctic_snowstorm);
    RegisterAreaTriggerAI(areatrigger_sha_wind_rush_totem);
}
