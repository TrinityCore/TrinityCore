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
    SPELL_SHAMAN_CONVERGING_STORMS              = 384363,
    SPELL_SHAMAN_CRASH_LIGHTNING                = 187874,
    SPELL_SHAMAN_CRASH_LIGHTNING_CLEAVE         = 187878,
    SPELL_SHAMAN_CRASH_LIGHTNING_DAMAGE_BUFF    = 333964,
    SPELL_SHAMAN_DELUGE_AURA                    = 200075,
    SPELL_SHAMAN_DELUGE_TALENT                  = 200076,
    SPELL_SHAMAN_DOOM_WINDS_DAMAGE              = 469270,
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
    SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE          = 173183,
    SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY        = 173184,
    SPELL_SHAMAN_ELEMENTAL_BLAST_OVERLOAD       = 120588,
    SPELL_SHAMAN_ELEMENTAL_MASTERY              = 16166,
    SPELL_SHAMAN_ELEMENTAL_WEAPONS_BUFF         = 408390,
    SPELL_SHAMAN_ENERGY_SURGE                   = 40465,
    SPELL_SHAMAN_ENHANCED_ELEMENTS              = 77223,
    SPELL_SHAMAN_FIRE_NOVA_DAMAGE               = 333977,
    SPELL_SHAMAN_FIRE_NOVA_ENABLER              = 466622,
    SPELL_SHAMAN_FLAME_SHOCK                    = 188389,
    SPELL_SHAMAN_FLAMETONGUE_ATTACK             = 10444,
    SPELL_SHAMAN_FLAMETONGUE_WEAPON_ENCHANT     = 334294,
    SPELL_SHAMAN_FLAMETONGUE_WEAPON_AURA        = 319778,
    SPELL_SHAMAN_FORCEFUL_WINDS_PROC            = 262652,
    SPELL_SHAMAN_FORCEFUL_WINDS_TALENT          = 262647,
    SPELL_SHAMAN_FROST_SHOCK                    = 196840,
    SPELL_SHAMAN_FROST_SHOCK_ENERGIZE           = 289439,
    SPELL_SHAMAN_GATHERING_STORMS               = 198299,
    SPELL_SHAMAN_GATHERING_STORMS_BUFF          = 198300,
    SPELL_SHAMAN_GHOST_WOLF                     = 2645,
    SPELL_SHAMAN_HAILSTORM_BUFF                 = 334196,
    SPELL_SHAMAN_HAILSTORM_TALENT               = 334195,
    SPELL_SHAMAN_HEALING_RAIN_VISUAL            = 147490,
    SPELL_SHAMAN_HEALING_RAIN                   = 73920,
    SPELL_SHAMAN_HEALING_RAIN_HEAL              = 73921,
    SPELL_SHAMAN_ICE_STRIKE_OVERRIDE_AURA       = 466469,
    SPELL_SHAMAN_ICE_STRIKE_PROC                = 466467,
    SPELL_SHAMAN_ICEFURY                        = 210714,
    SPELL_SHAMAN_ICEFURY_OVERLOAD               = 219271,
    SPELL_SHAMAN_IGNEOUS_POTENTIAL              = 279830,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD          = 23552,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE   = 27635,
    SPELL_SHAMAN_ITEM_MANA_SURGE                = 23571,
    SPELL_SHAMAN_LAVA_BURST                     = 51505,
    SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE        = 71824,
    SPELL_SHAMAN_LAVA_BURST_OVERLOAD            = 77451,
    SPELL_SHAMAN_LAVA_LASH                      = 60103,
    SPELL_SHAMAN_LAVA_SURGE                     = 77762,
    SPELL_SHAMAN_LIGHTNING_BOLT                 = 188196,
    SPELL_SHAMAN_LIGHTNING_BOLT_ENERGIZE        = 214815,
    SPELL_SHAMAN_LIGHTNING_BOLT_OVERLOAD        = 45284,
    SPELL_SHAMAN_LIGHTNING_BOLT_OVERLOAD_ENERGIZE = 214816,
    SPELL_SHAMAN_LIQUID_MAGMA_HIT               = 192231,
    SPELL_SHAMAN_MAELSTROM_CONTROLLER           = 343725,
    SPELL_SHAMAN_MAELSTROM_WEAPON_MOD_AURA      = 187881,
    SPELL_SHAMAN_MAELSTROM_WEAPON_VISIBLE_AURA  = 344179,
    SPELL_SHAMAN_MAELSTROM_WEAPON_OVERLAY       = 187890,
    SPELL_SHAMAN_MAELSTROM_WEAPON_OVERLAY_HEALS = 412692,
    SPELL_SHAMAN_MASTERY_ELEMENTAL_OVERLOAD     = 168534,
    SPELL_SHAMAN_MOLTEN_ASSAULT                 = 334033,
    SPELL_SHAMAN_MOLTEN_THUNDER_PROC            = 469346,
    SPELL_SHAMAN_MOLTEN_THUNDER_TALENT          = 469344,
    SPELL_SHAMAN_NATURES_GUARDIAN_COOLDOWN      = 445698,
    SPELL_SHAMAN_OVERFLOWING_MAELSTROM_AURA     = 384669,
    SPELL_SHAMAN_OVERFLOWING_MAELSTROM_TALENT   = 384149,
    SPELL_SHAMAN_PATH_OF_FLAMES_SPREAD          = 210621,
    SPELL_SHAMAN_PATH_OF_FLAMES_TALENT          = 201909,
    SPELL_SHAMAN_POWER_SURGE                    = 40466,
    SPELL_SHAMAN_PRIMORDIAL_WAVE_DAMAGE         = 375984,
    SPELL_SHAMAN_RESTORATIVE_MISTS              = 114083,
    SPELL_SHAMAN_RESTORATIVE_MISTS_INITIAL      = 294020,
    SPELL_SHAMAN_RIPTIDE                        = 61295,
    SPELL_SHAMAN_SPIRIT_WOLF_TALENT             = 260878,
    SPELL_SHAMAN_SPIRIT_WOLF_PERIODIC           = 260882,
    SPELL_SHAMAN_SPIRIT_WOLF_AURA               = 260881,
    SPELL_SHAMAN_STORMBLAST_DAMAGE              = 390287,
    SPELL_SHAMAN_STORMBLAST_PROC                = 470466,
    SPELL_SHAMAN_STORMBLAST_TALENT              = 319930,
    SPELL_SHAMAN_STORMFLURRY                    = 344357,
    SPELL_SHAMAN_STORMFLURRY_ARTIFACT           = 198367,
    SPELL_SHAMAN_STORMKEEPER                    = 191634,
    SPELL_SHAMAN_STORMSTRIKE                    = 17364,
    SPELL_SHAMAN_STORMSTRIKE_DAMAGE_MAIN_HAND   = 32175,
    SPELL_SHAMAN_STORMSTRIKE_DAMAGE_OFF_HAND    = 32176,
    SPELL_SHAMAN_STORMSURGE_PROC                = 201846,
    SPELL_SHAMAN_STORMWEAVER_PVP_TALENT         = 410673,
    SPELL_SHAMAN_STORMWEAVER_PVP_TALENT_BUFF    = 410681,
    SPELL_SHAMAN_T29_2P_ELEMENTAL_DAMAGE_BUFF   = 394651,
    SPELL_SHAMAN_THORIMS_INVOCATION             = 384444,
    SPELL_SHAMAN_TIDAL_WAVES                    = 53390,
    SPELL_SHAMAN_TOTEMIC_POWER_ARMOR            = 28827,
    SPELL_SHAMAN_TOTEMIC_POWER_ATTACK_POWER     = 28826,
    SPELL_SHAMAN_TOTEMIC_POWER_MP5              = 28824,
    SPELL_SHAMAN_TOTEMIC_POWER_SPELL_POWER      = 28825,
    SPELL_SHAMAN_UNDULATION_PROC                = 216251,
    SPELL_SHAMAN_UNLIMITED_POWER_BUFF           = 272737,
    SPELL_SHAMAN_UNRELENTING_STORMS_REDUCTION   = 470491,
    SPELL_SHAMAN_UNRELENTING_STORMS_TALENT      = 470490,
    SPELL_SHAMAN_UNRULY_WINDS                   = 390288,
    SPELL_SHAMAN_VOLTAIC_BLAZE_DAMAGE           = 470057,
    SPELL_SHAMAN_VOLTAIC_BLAZE_OVERRIDE         = 470058,
    SPELL_SHAMAN_WINDFURY_ATTACK                = 25504,
    SPELL_SHAMAN_WINDFURY_AURA                  = 319773,
    SPELL_SHAMAN_WINDFURY_ENCHANTMENT           = 334302,
    SPELL_SHAMAN_WINDFURY_VISUAL_1              = 466440,
    SPELL_SHAMAN_WINDFURY_VISUAL_2              = 466442,
    SPELL_SHAMAN_WINDFURY_VISUAL_3              = 466443,
    SPELL_SHAMAN_WIND_RUSH                      = 192082,
    SPELL_SHAMAN_WINDSTRIKE_DAMAGE_MAIN_HAND    = 115357,
    SPELL_SHAMAN_WINDSTRIKE_DAMAGE_OFF_HAND     = 115360
};

enum ShamanSpellLabels
{
    SPELL_LABEL_SHAMAN_WINDFURY_TOTEM           = 1038,
};

enum MiscNpcs
{
    NPC_HEALING_RAIN_INVISIBLE_STALKER          = 73400
};

struct spell_sha_maelstrom_weapon_base
{
    static bool Validate();
    static void GenerateMaelstromWeapon(Unit* shaman, int32 stacks);
    static void ConsumeMaelstromWeapon(Unit* shaman, Aura* maelstromWeaponVisibleAura, int32 stacks, Spell const* consumingSpell = nullptr);
};

class WindfuryProcEvent : public BasicEvent
{
public:
    struct WindfuryProcEventInfo
    {
        Milliseconds Delay;
        uint32 VisualSpellId;
    };

    static constexpr std::array<WindfuryProcEventInfo, 3> Sequence =
    { {
        {.Delay = 500ms, .VisualSpellId = SPELL_SHAMAN_WINDFURY_VISUAL_1 },
        {.Delay = 150ms, .VisualSpellId = SPELL_SHAMAN_WINDFURY_VISUAL_2 },
        {.Delay = 250ms, .VisualSpellId = SPELL_SHAMAN_WINDFURY_VISUAL_3 },
    } };

    WindfuryProcEvent(Unit* shaman, Unit* target, std::ptrdiff_t attacks) : _shaman(shaman), _target(target), _itr(Sequence.begin()), _end(_itr + attacks) { }

    bool Execute(uint64 time, uint32 /*diff*/) override;

    static void Trigger(Unit* shaman, Unit* target);

private:
    Unit* _shaman;
    CastSpellTargetArg _target;
    using EventInfoIterator = decltype(Sequence)::const_iterator;
    EventInfoIterator _itr;
    EventInfoIterator _end;
};

// 273221 - Aftershock
class spell_sha_aftershock : public AuraScript
{
    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_AFTERSHOCK_ENERGIZE });
    }

    static bool CheckProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        if (Spell const* procSpell = eventInfo.GetProcSpell())
            if (Optional<int32> cost = procSpell->GetPowerTypeCostAmount(POWER_MAELSTROM))
                return cost > 0 && roll_chance_i(aurEff->GetAmount());

        return false;
    }

    static void HandleEffectProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        Spell const* procSpell = eventInfo.GetProcSpell();
        eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_SHAMAN_AFTERSHOCK_ENERGIZE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = procSpell,
            .TriggeringAura = aurEff,
            .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, *procSpell->GetPowerTypeCostAmount(POWER_MAELSTROM) } }
        });
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

    static bool CheckProc(AuraScript const&, ProcEventInfo const& eventInfo)
    {
        if (eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->Id == SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL)
            return false;

        if (!eventInfo.GetHealInfo() && !eventInfo.GetDamageInfo())
            return false;

        return true;
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        PreventDefaultAction();
        int32 bp0 = CalculatePct(int32(eventInfo.GetDamageInfo() ? eventInfo.GetDamageInfo()->GetDamage() : eventInfo.GetHealInfo()->GetHeal()), aurEff->GetAmount());
        if (!bp0)
            return;

        eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff,
            .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, bp0 } }
        });
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
    static void ResizeTargets(SpellScript const&, std::list<WorldObject*>& targets)
    {
        Trinity::SelectRandomInjuredTargets(targets, 3, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_ancestral_guidance_heal::ResizeTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
    }
};

// 462764 - Arctic Snowstorm
class spell_sha_arctic_snowstorm : public AuraScript
{
    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_ARCTIC_SNOWSTORM_AREATRIGGER });
    }

    static void HandleEffectProc(AuraScript const&, AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo)
    {
        eventInfo.GetActor()->CastSpell(eventInfo.GetActionTarget(), SPELL_SHAMAN_ARCTIC_SNOWSTORM_AREATRIGGER,
            CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR });
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_arctic_snowstorm::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 198299 - Gathering Storms
class spell_sha_artifact_gathering_storms : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_GATHERING_STORMS, SPELL_SHAMAN_GATHERING_STORMS_BUFF });
    }

    bool Load() override
    {
        return GetCaster()->HasAuraEffect(SPELL_SHAMAN_GATHERING_STORMS, EFFECT_0);
    }

    void TriggerBuff(SpellEffIndex effIndex) const
    {
        AuraEffect const* gatheringStorms = GetCaster()->GetAuraEffect(SPELL_SHAMAN_GATHERING_STORMS, EFFECT_0);
        if (!gatheringStorms)
            return;

        GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_GATHERING_STORMS_BUFF, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK,
            .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, int32(gatheringStorms->GetAmount() * GetUnitTargetCountForEffect(effIndex)) } }
        });
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_sha_artifact_gathering_storms::TriggerBuff, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 114052 - Ascendance (Restoration)
class spell_sha_ascendance_restoration : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_RESTORATIVE_MISTS });
    }

    static bool CheckProc(AuraScript const&, ProcEventInfo const& procInfo)
    {
        return procInfo.GetHealInfo() && procInfo.GetHealInfo()->GetOriginalHeal() && procInfo.GetSpellInfo()->Id != SPELL_SHAMAN_RESTORATIVE_MISTS_INITIAL;
    }

    void OnProcHeal(AuraEffect const* aurEff, ProcEventInfo const& procInfo)
    {
        _healToDistribute += CalculatePct(int32(procInfo.GetHealInfo()->GetOriginalHeal()), aurEff->GetAmount());
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        if (!_healToDistribute)
            return;

        GetTarget()->CastSpell(nullptr, SPELL_SHAMAN_RESTORATIVE_MISTS, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff,
            .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, _healToDistribute } }
        });
        _healToDistribute = 0;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_ascendance_restoration::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_sha_ascendance_restoration::OnProcHeal, EFFECT_8, SPELL_AURA_DUMMY);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_ascendance_restoration::HandleEffectPeriodic, EFFECT_6, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    int32 _healToDistribute = 0;
};

// 390370 - Ashen Catalyst
class spell_sha_ashen_catalyst : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_LAVA_LASH });
    }

    void ReduceLavaLashCooldown(AuraEffect const* aurEff, ProcEventInfo const& /*procInfo*/) const
    {
        GetTarget()->GetSpellHistory()->ModifyCooldown(SPELL_SHAMAN_LAVA_LASH, -aurEff->GetAmount() * 100ms);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_ashen_catalyst::ReduceLavaLashCooldown, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 188443 - Chain Lightning
class spell_sha_chain_lightning_crash_lightning : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_CRASH_LIGHTNING, SPELL_SHAMAN_CRASH_LIGHTNING_DAMAGE_BUFF });
    }

    bool Load() override
    {
        return GetCaster()->HasSpell(SPELL_SHAMAN_CRASH_LIGHTNING);
    }

    void HandleCooldownReduction(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->GetSpellHistory()->ModifyCooldown(SPELL_SHAMAN_CRASH_LIGHTNING, Milliseconds(-GetEffectValue()) * GetUnitTargetCountForEffect(EFFECT_0));
    }

    void HandleDamageBuff(SpellEffIndex effIndex) const
    {
        int64 targetsHit = GetUnitTargetCountForEffect(effIndex);
        if (targetsHit > 1)
            GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_CRASH_LIGHTNING_DAMAGE_BUFF, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .SpellValueOverrides = { { SPELLVALUE_AURA_STACK, int32(targetsHit) } }
            });
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sha_chain_lightning_crash_lightning::HandleCooldownReduction, EFFECT_2, SPELL_EFFECT_DUMMY);
        OnEffectLaunch += SpellEffectFn(spell_sha_chain_lightning_crash_lightning::HandleDamageBuff, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 188443 - Chain Lightning
class spell_sha_chain_lightning_energize : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_CHAIN_LIGHTNING_ENERGIZE })
            && ValidateSpellEffect({ { SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_4 } });
    }

    bool Load() override
    {
        return GetCaster()->HasAuraEffect(SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_4);
    }

    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        if (AuraEffect const* energizeAmount = GetCaster()->GetAuraEffect(SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_4))
            GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_CHAIN_LIGHTNING_ENERGIZE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = energizeAmount,
                .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, int32(energizeAmount->GetAmount() * GetUnitTargetCountForEffect(EFFECT_0)) } }
            });
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sha_chain_lightning_energize::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 45297 - Chain Lightning Overload
class spell_sha_chain_lightning_overload : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_CHAIN_LIGHTNING_OVERLOAD_ENERGIZE })
            && ValidateSpellEffect({ { SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_5 } });
    }

    bool Load() override
    {
        return GetCaster()->HasAuraEffect(SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_5);
    }

    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        if (AuraEffect const* energizeAmount = GetCaster()->GetAuraEffect(SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_5))
            GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_CHAIN_LIGHTNING_OVERLOAD_ENERGIZE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = energizeAmount,
                .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, int32(energizeAmount->GetAmount() * GetUnitTargetCountForEffect(EFFECT_0)) } }
            });
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sha_chain_lightning_overload::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 384363 - Converging Storms
class spell_sha_converging_storms : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_CONVERGING_STORMS, SPELL_SHAMAN_GATHERING_STORMS_BUFF });
    }

    bool Load() override
    {
        return GetCaster()->HasAuraEffect(SPELL_SHAMAN_CONVERGING_STORMS, EFFECT_0);
    }

    void TriggerBuff(SpellEffIndex effIndex) const
    {
        AuraEffect const* convergingStorms = GetCaster()->GetAuraEffect(SPELL_SHAMAN_CONVERGING_STORMS, EFFECT_0);
        if (!convergingStorms)
            return;

        GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_GATHERING_STORMS_BUFF, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK,
            .SpellValueOverrides = { { SPELLVALUE_AURA_STACK, std::min<int32>(GetUnitTargetCountForEffect(effIndex), 6) } }
        });
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_sha_converging_storms::TriggerBuff, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 198300 - Converging Storms
class spell_sha_delayed_stormstrike_mod_charge_drop_proc : public AuraScript
{
    void DropAura(ProcEventInfo const& /*eventInfo*/) const
    {
        GetAura()->DropChargeDelayed(1);
    }

    void Register() override
    {
        AfterProc += AuraProcFn(spell_sha_delayed_stormstrike_mod_charge_drop_proc::DropAura);
    }
};

// 187874 - Crash Lightning
class spell_sha_crash_lightning : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_CRASH_LIGHTNING_CLEAVE });
    }

    void TriggerCleaveBuff(SpellEffIndex effIndex) const
    {
        if (GetUnitTargetCountForEffect(effIndex) >= 2)
            GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_CRASH_LIGHTNING_CLEAVE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
            });
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_sha_crash_lightning::TriggerCleaveBuff, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 200076 - Deluge (attached to 77472 - Healing Wave, 8004 - Healing Surge and 1064 - Chain Heal
class spell_sha_deluge : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_RIPTIDE, SPELL_SHAMAN_DELUGE_AURA })
            && ValidateSpellEffect({ { SPELL_SHAMAN_DELUGE_TALENT, EFFECT_0 } });
    }

    void CalculateHealingBonus(SpellEffectInfo const& /*spellEffectInfo*/, Unit const* victim, int32& /*healing*/, int32& /*flatMod*/, float& pctMod) const
    {
        if (AuraEffect const* deluge = GetCaster()->GetAuraEffect(SPELL_SHAMAN_DELUGE_TALENT, EFFECT_0))
            if (victim->GetAura(SPELL_SHAMAN_RIPTIDE, GetCaster()->GetGUID()) || victim->GetAura(SPELL_SHAMAN_DELUGE_AURA, GetCaster()->GetGUID()))
                AddPct(pctMod, deluge->GetAmount());
    }

    void Register() override
    {
        CalcHealing += SpellCalcHealingFn(spell_sha_deluge::CalculateHealingBonus);
    }
};

namespace HealingRain
{
Position GetHealingRainPosition(Aura const* healingRain);
}

// 200075 - Deluge (attached to 73920 - Healing Rain)
class spell_sha_deluge_healing_rain : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_DELUGE_TALENT, SPELL_SHAMAN_DELUGE_AURA });
    }

    bool Load() override
    {
        return GetUnitOwner()->HasAura(SPELL_SHAMAN_DELUGE_TALENT);
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/) const
    {
        GetCaster()->CastSpell(HealingRain::GetHealingRainPosition(GetAura()), SPELL_SHAMAN_DELUGE_AURA, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_deluge_healing_rain::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
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

    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& procInfo)
    {
        if (!procInfo.GetSpellInfo())
            return false;

        if (procInfo.GetSpellInfo()->Id != _triggeringSpellId)
            return false;

        return roll_chance_i(_procAttempts++ - 2);
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        _procAttempts = 0;

        Unit* target = eventInfo.GetActor();

        int32 duration = GetEffect(EFFECT_0)->GetAmount();
        if (Aura const* ascendanceAura = target->GetAura(_triggeredSpellId))
            duration += ascendanceAura->GetDuration();

        target->CastSpell(target, _triggeredSpellId, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD | TRIGGERED_IGNORE_CAST_IN_PROGRESS,
            .TriggeringSpell = eventInfo.GetProcSpell(),
            .TriggeringAura = aurEff,
            .SpellValueOverrides = { { SPELLVALUE_DURATION, duration } }
        });
    }

    void Register() override
    {
        ChrSpecialization specialization = ChrSpecialization::None;
        if (Aura const* aura = GetAura()) // aura doesn't exist at startup validation
            if (Player const* owner = Object::ToPlayer(aura->GetOwner()))
                specialization = owner->GetPrimarySpecialization();

        if (specialization == ChrSpecialization::None || specialization == ChrSpecialization::ShamanElemental)
        {
            DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_deeply_rooted_elements::CheckProc, EFFECT_1, SPELL_AURA_DUMMY);
            OnEffectProc += AuraEffectProcFn(spell_sha_deeply_rooted_elements::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            _triggeringSpellId = SPELL_SHAMAN_LAVA_BURST;
            _triggeredSpellId = SPELL_SHAMAN_ASCENDANCE_ELEMENTAL;
        }

        if (specialization == ChrSpecialization::None || specialization == ChrSpecialization::ShamanEnhancement)
        {
            DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_deeply_rooted_elements::CheckProc, EFFECT_2, SPELL_AURA_DUMMY);
            OnEffectProc += AuraEffectProcFn(spell_sha_deeply_rooted_elements::HandleProc, EFFECT_2, SPELL_AURA_DUMMY);
            _triggeringSpellId = SPELL_SHAMAN_STORMSTRIKE;
            _triggeredSpellId = SPELL_SHAMAN_ASCENDANCE_ENHANCEMENT;
        }

        if (specialization == ChrSpecialization::None || specialization == ChrSpecialization::ShamanRestoration)
        {
            DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_deeply_rooted_elements::CheckProc, EFFECT_3, SPELL_AURA_DUMMY);
            OnEffectProc += AuraEffectProcFn(spell_sha_deeply_rooted_elements::HandleProc, EFFECT_3, SPELL_AURA_DUMMY);
            _triggeringSpellId = SPELL_SHAMAN_RIPTIDE;
            _triggeredSpellId = SPELL_SHAMAN_ASCENDANCE_RESTORATION;
        }
    }

    int32 _procAttempts = 0;
    uint32 _triggeringSpellId = 0;
    uint32 _triggeredSpellId = 0;
};

// 466772 - Doom Winds
class spell_sha_doom_winds : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_DOOM_WINDS_DAMAGE });
    }

    void PeriodicTick(AuraEffect const* aurEff) const
    {
        GetTarget()->CastSpell(GetTarget()->GetPosition(), SPELL_SHAMAN_DOOM_WINDS_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_doom_winds::PeriodicTick, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 335902 - Doom Winds
class spell_sha_doom_winds_legendary : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_DOOM_WINDS_LEGENDARY_COOLDOWN });
    }

    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& procInfo) const
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

    static void FilterTargets(SpellScript const&, std::list<WorldObject*>& targets)
    {
        Trinity::SelectRandomInjuredTargets(targets, 6, true);
    }

    void CountEffectivelyHealedTarget()
    {
        // Cooldown increased for each target effectively healed
        if (GetHitHeal())
            ++_healedTargets;
    }

    void HandleCooldown() const
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

    bool CheckProc(ProcEventInfo const& eventInfo) const
    {
        if (!eventInfo.GetDamageInfo() || !HasEffect(EFFECT_1) || eventInfo.GetDamageInfo()->GetDamage() < GetTarget()->CountPctFromMaxHealth(GetEffect(EFFECT_1)->GetAmount()))
            return false;
        return true;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& /*eventInfo*/)
    {
        PreventDefaultAction();

        GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_EARTH_SHIELD_HEAL, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK,
            .TriggeringAura = aurEff,
            .OriginalCaster = GetCasterGUID()
        });
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

    static bool CheckProc(AuraScript const&, ProcEventInfo const& procInfo)
    {
        return procInfo.GetSpellInfo() && procInfo.GetSpellInfo()->Id != SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE;
    }

    void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo)
    {
        PreventDefaultAction();
        _procTargetGuid = eventInfo.GetProcTarget()->GetGUID();
        eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_SHAMAN_EARTHEN_RAGE_PERIODIC, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK
        });
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
                    GetTarget()->CastSpell(procTarget, SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE, CastSpellExtraArgsInit{
                        .TriggerFlags = TRIGGERED_FULL_MASK
                    });
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
    using AreaTriggerAI::AreaTriggerAI;

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
                caster->CastSpell(at->GetPosition(), SPELL_SHAMAN_EARTHQUAKE_TICK, CastSpellExtraArgsInit{
                    .TriggerFlags = TRIGGERED_FULL_MASK,
                    .OriginalCaster = at->GetGUID(),
                    .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, int32(caster->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_NATURE) * 0.213f * _damageMultiplier) } }
                });

            _refreshTimer += _period;
        }
    }

    // Each target can only be stunned once by each earthquake - keep track of who we already stunned
    bool AddStunnedTarget(ObjectGuid const& guid)
    {
        return _stunnedUnits.insert(guid).second;
    }

private:
    Milliseconds _refreshTimer = 0s;
    Milliseconds _period = 1s;
    GuidUnorderedSet _stunnedUnits;
    float _damageMultiplier = 1.0f;
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

    void SnapshotDamageMultiplier(SpellEffIndex /*effIndex*/) const
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

    void HandleOnHit() const
    {
        if (Unit* target = GetHitUnit())
        {
            if (roll_chance_i(GetEffectInfo(EFFECT_1).CalcValue()))
            {
                std::vector<AreaTrigger*> areaTriggers = GetCaster()->GetAreaTriggers(SPELL_SHAMAN_EARTHQUAKE);
                auto itr = std::ranges::find(areaTriggers, GetSpell()->GetOriginalCasterGUID(), [](AreaTrigger const* at) { return at->GetGUID(); });
                if (itr != areaTriggers.end())
                    if (areatrigger_sha_earthquake* eq = CAST_AI(areatrigger_sha_earthquake, (*itr)->AI()))
                        if (eq->AddStunnedTarget(target->GetGUID()))
                            GetCaster()->CastSpell(target, SPELL_SHAMAN_EARTHQUAKE_KNOCKING_DOWN, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
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
    static constexpr std::array<uint32, 3> BuffSpells = { SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT, SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE, SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT,
            SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE,
            SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY
        }) && ValidateSpellEffect({
            { SPELL_SHAMAN_T29_2P_ELEMENTAL_DAMAGE_BUFF, EFFECT_0 }
        });
    }

    void TriggerBuff() const
    {
        Unit* caster = GetCaster();
        std::array<double, BuffSpells.size()> weights;
        double total = 0.0;
        for (std::size_t i = 0; i < BuffSpells.size(); ++i)
            total += weights[i] = !caster->HasAura(BuffSpells[i]) ? 1.0 : 0.0;

        uint32 spellId = [&]
        {
            if (total > 0.0)
                return *Trinity::Containers::SelectRandomWeightedContainerElement(BuffSpells, weights);

            // refresh random one if we have them all
            return Trinity::Containers::SelectRandomContainerElement(BuffSpells);
        }();

        GetCaster()->CastSpell(GetCaster(), spellId, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
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
        AfterCast += SpellCastFn(spell_sha_elemental_blast::TriggerBuff);
        OnHit += SpellHitFn(spell_sha_elemental_blast::AddScriptedDamageMods);
    }
};

// 384355 - Elemental Weapons
class spell_sha_elemental_weapons : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_ELEMENTAL_WEAPONS_BUFF });
    }

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    void CheckEnchantments() const
    {
        Player* owner = GetUnitOwner()->ToPlayer();
        int32 enchatmentCount = 0;
        if (owner->HasAura(SPELL_SHAMAN_FLAMETONGUE_WEAPON_AURA))
            ++enchatmentCount;
        if (owner->HasAura(SPELL_SHAMAN_WINDFURY_AURA))
            ++enchatmentCount;

        int32 valuePerStack = GetEffect(EFFECT_0)->GetAmount();

        if (Aura* buff = owner->GetAura(SPELL_SHAMAN_ELEMENTAL_WEAPONS_BUFF))
        {
            if (enchatmentCount)
                for (AuraEffect* aurEff : buff->GetAuraEffects())
                    aurEff->ChangeAmount(valuePerStack * enchatmentCount / 10);
            else
                buff->Remove();
        }
        else if (enchatmentCount)
            owner->CastSpell(owner, SPELL_SHAMAN_ELEMENTAL_WEAPONS_BUFF, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .SpellValueOverrides = {
                    { SPELLVALUE_BASE_POINT0, valuePerStack * enchatmentCount / 10 },
                    { SPELLVALUE_BASE_POINT1, valuePerStack * enchatmentCount / 10 }
                }
            });
    }

    void RemoveAllBuffs(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        GetUnitOwner()->RemoveAurasDueToSpell(SPELL_SHAMAN_ELEMENTAL_WEAPONS_BUFF);
    }

    void Register() override
    {
        OnHeartbeat += AuraHeartbeatFn(spell_sha_elemental_weapons::CheckEnchantments);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sha_elemental_weapons::RemoveAllBuffs, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

struct FireNovaTargetCheck
{
    float MaxSearchRange = 40.0f;
    Unit const* Shaman;

    bool operator()(Unit const* candidate) const
    {
        return candidate->IsWithinDist3d(Shaman, MaxSearchRange) && candidate->HasAura(SPELL_SHAMAN_FLAME_SHOCK, Shaman->GetGUID());
    }
};

// 333974 - Fire Nova
class spell_sha_fire_nova : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_FIRE_NOVA_DAMAGE });
    }

    void TriggerDamage(SpellEffIndex /*effIndex*/) const
    {
        Unit* shaman = GetCaster();
        std::vector<Unit*> targets;
        FireNovaTargetCheck check{ .Shaman = shaman };
        Trinity::UnitListSearcher searcher(shaman, targets, check);
        Cell::VisitAllObjects(shaman, searcher, check.MaxSearchRange);

        CastSpellExtraArgs args;
        args.SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        args.SetTriggeringSpell(GetSpell());

        for (Unit* target : targets)
            shaman->CastSpell(target, SPELL_SHAMAN_FIRE_NOVA_DAMAGE, args);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_fire_nova::TriggerDamage, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 466620 - Flame Shock
class spell_sha_flame_shock_fire_nova_enabler : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_FLAME_SHOCK, SPELL_SHAMAN_FIRE_NOVA_ENABLER });
    }

    void CheckFlameShocks(AuraEffect const* aurEff) const
    {
        Unit* shaman = GetTarget();
        Unit* target = nullptr;
        FireNovaTargetCheck check{ .Shaman = shaman };
        Trinity::UnitSearcher searcher(shaman, target, check);
        Cell::VisitAllObjects(shaman, searcher, check.MaxSearchRange);
        if (target)
            shaman->CastSpell(shaman, SPELL_SHAMAN_FIRE_NOVA_ENABLER, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = aurEff
            });
        else
            shaman->RemoveAurasDueToSpell(SPELL_SHAMAN_FIRE_NOVA_ENABLER);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_flame_shock_fire_nova_enabler::CheckFlameShocks, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
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

    void HandleEffectHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Player* player = GetCaster()->ToPlayer();
        uint8 slot = EQUIPMENT_SLOT_MAINHAND;
        if (player->GetPrimarySpecialization() == ChrSpecialization::ShamanEnhancement)
            slot = EQUIPMENT_SLOT_OFFHAND;

        Item* targetItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
        if (!targetItem || !targetItem->GetTemplate()->IsWeapon())
            return;

        player->CastSpell(targetItem, SPELL_SHAMAN_FLAMETONGUE_WEAPON_ENCHANT, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
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

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        PreventDefaultAction();

        eventInfo.GetActor()->CastSpell(eventInfo.GetActionTarget(), SPELL_SHAMAN_FLAMETONGUE_ATTACK, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_flametongue_weapon_aura::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 334196 - Hailstorm
class spell_sha_hailstorm : public AuraScript
{
    void CalcCleaveMod(AuraEffect const* aurEff, SpellModifier*& spellMod) const
    {
        if (!spellMod)
        {
            SpellModifierByClassMask* mod = new SpellModifierByClassMask(GetAura());
            mod->op = SpellModOp::ChainTargets;
            mod->type = SPELLMOD_FLAT;
            mod->spellId = GetId();
            mod->mask = { 0x80000000, 0x00000000, 0x00000000, 0x00000000 };

            spellMod = mod;
        }

        if (AuraEffect const* hailstormPassive = GetUnitOwner()->GetAuraEffect(SPELL_SHAMAN_HAILSTORM_TALENT, EFFECT_0))
        {
            int32 targetCap = hailstormPassive->GetAmount() / aurEff->GetBaseAmount();
            static_cast<SpellModifierByClassMask*>(spellMod)->value = std::min<int32>(targetCap, GetStackAmount()) + 1;
        }
    }

    void Register() override
    {
        DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_sha_hailstorm::CalcCleaveMod, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 73920 - Healing Rain (Aura)
class spell_sha_healing_rain_aura : public AuraScript
{
public:
    void SetVisualDummy(TempSummon const* summon)
    {
        _visualDummy = summon->GetGUID();
        _dest = summon->GetPosition();
    }

    Position GetPosition() const { return _dest; }

private:
    void HandleEffectPeriodic(AuraEffect const* aurEff) const
    {
        GetTarget()->CastSpell(_dest, SPELL_SHAMAN_HEALING_RAIN_HEAL, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK,
            .TriggeringAura = aurEff
        });
    }

    void HandleEffecRemoved(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
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

Position HealingRain::GetHealingRainPosition(Aura const* healingRain)
{
    if (spell_sha_healing_rain_aura const* script = healingRain->GetScript<spell_sha_healing_rain_aura>())
        return script->GetPosition();

    return healingRain->GetUnitOwner()->GetPosition();
}

// 73920 - Healing Rain
class spell_sha_healing_rain : public SpellScript
{
    void InitializeVisualStalker() const
    {
        if (Aura* aura = GetHitAura())
        {
            if (WorldLocation const* dest = GetExplTargetDest())
            {
                Milliseconds duration = Milliseconds(GetSpellInfo()->CalcDuration(GetOriginalCaster()));
                TempSummon* summon = GetCaster()->GetMap()->SummonCreature(NPC_HEALING_RAIN_INVISIBLE_STALKER, *dest, nullptr, duration, GetOriginalCaster());
                if (!summon)
                    return;

                summon->CastSpell(summon, SPELL_SHAMAN_HEALING_RAIN_VISUAL, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });

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
    static void SelectTargets(SpellScript const&, std::list<WorldObject*>& targets)
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
    static void SelectTargets(SpellScript const&, std::list<WorldObject*>& targets)
    {
        Trinity::SelectRandomInjuredTargets(targets, 1, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_healing_stream_totem_heal::SelectTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// 201900 - Hot Hand
class spell_sha_hot_hand : public AuraScript
{
    static bool CheckProc(AuraScript const&, AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo)
    {
        return eventInfo.GetActor()->HasAura(SPELL_SHAMAN_FLAMETONGUE_WEAPON_AURA);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_hot_hand::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 342240 - Ice Strike
class spell_sha_ice_strike : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return spell_sha_maelstrom_weapon_base::Validate();
    }

    void EnergizeMaelstrom(SpellEffIndex /*effIndex*/) const
    {
        spell_sha_maelstrom_weapon_base::GenerateMaelstromWeapon(GetCaster(), GetEffectValue());
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_sha_ice_strike::EnergizeMaelstrom, EFFECT_3, SPELL_EFFECT_DUMMY);
    }
};

// 466467 - Ice Strike
class spell_sha_ice_strike_proc : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_ICE_STRIKE_OVERRIDE_AURA });
    }

    void Register() override { }

public:
    void AttemptProc()
    {
        if (!roll_chance_i(++_attemptCount * 7))
            return;

        _attemptCount = 0;
        Unit* shaman = GetUnitOwner();
        shaman->CastSpell(shaman, SPELL_SHAMAN_ICE_STRIKE_OVERRIDE_AURA, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

private:
    int32 _attemptCount = 0;
};

// 210714 - Icefury
class spell_sha_icefury : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_FROST_SHOCK_ENERGIZE });
    }

    void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& /*eventInfo*/) const
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_SHAMAN_FROST_SHOCK_ENERGIZE, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS });
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

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK,
            .TriggeringAura = aurEff
        });
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

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK,
            .TriggeringAura = aurEff
        });
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

    static bool CheckProc(AuraScript const&, ProcEventInfo const& eventInfo)
    {
        return eventInfo.GetProcSpell() != nullptr;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        PreventDefaultAction();

        if (Optional<int32> manaCost = eventInfo.GetProcSpell()->GetPowerTypeCostAmount(POWER_MANA))
        {
            int32 mana = CalculatePct(*manaCost, 35);
            if (mana > 0)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_ITEM_MANA_SURGE, CastSpellExtraArgsInit{
                    .TriggerFlags = TRIGGERED_FULL_MASK,
                    .TriggeringAura = aurEff,
                    .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, mana } }
                });
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

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo)
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
            eventInfo.GetActor()->CastSpell(nullptr, spellId, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
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

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo const& /*eventInfo*/)
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

    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        if (Unit* caster = GetCaster())
            if (caster->HasAura(SPELL_SHAMAN_PATH_OF_FLAMES_TALENT))
                caster->CastSpell(GetHitUnit(), SPELL_SHAMAN_PATH_OF_FLAMES_SPREAD, CastSpellExtraArgsInit{
                    .TriggerFlags = TRIGGERED_FULL_MASK,
                    .TriggeringSpell = GetSpell()
                });
    }

    void EnsureLavaSurgeCanBeImmediatelyConsumed() const
    {
        Unit* caster = GetCaster();

        if (Aura* lavaSurge = caster->GetAura(SPELL_SHAMAN_LAVA_SURGE))
        {
            if (!GetSpell()->m_appliedMods.contains(lavaSurge))
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

    void CalcCritChance(Unit const* victim, float& chance) const
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

// 60103 - Lava Lash
class spell_sha_lava_lash : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } })
            && ValidateSpellInfo({ SPELL_SHAMAN_FLAMETONGUE_WEAPON_AURA });
    }

    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    void AddBonusFlametongueDamage(SpellEffectInfo const& /*effectInfo*/, Unit const* victim, int32& /*damage*/, int32& /*flatMod*/, float& pctMod) const
    {
        Player* caster = GetCaster()->ToPlayer();
        ObjectGuid offhandItemGuid = Object::GetGUID(caster->GetWeaponForAttack(GetSpellInfo()->GetAttackType()));
        if (GetCaster()->HasAura(SPELL_SHAMAN_FLAMETONGUE_WEAPON_AURA, ObjectGuid::Empty, offhandItemGuid))
            AddPct(pctMod, GetSpell()->CalculateDamage(GetEffectInfo(EFFECT_1), victim));
    }

    void Register() override
    {
        CalcDamage += SpellCalcDamageFn(spell_sha_lava_lash::AddBonusFlametongueDamage);
    }
};

// 77756 - Lava Surge
class spell_sha_lava_surge : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_LAVA_SURGE, SPELL_SHAMAN_IGNEOUS_POTENTIAL });
    }

    bool CheckProcChance(AuraEffect const* aurEff, ProcEventInfo const& /*eventInfo*/)
    {
        Unit* caster = GetTarget();
        float flameShocks = 0.0f;
        auto work = [&, shaman = caster->GetGUID()](Unit const* target)
        {
            if (target->HasAuraEffect(SPELL_SHAMAN_FLAME_SHOCK, EFFECT_1, shaman))
                flameShocks += 1.0f;
        };
        Trinity::UnitWorker worker(caster, work);
        Cell::VisitAllObjects(caster, worker, 100.0f);

        // Proc uptime is not supposed to scale with the number of applied flame shocks
        _normalizedTicks += 1.0f / flameShocks;

        // first 6 ticks after last proc fail to prevent overwriting
        if (_normalizedTicks < 6.0f)
            return false;

        float procChance = aurEff->GetAmount();
        if (AuraEffect const* igneousPotential = GetTarget()->GetAuraEffect(SPELL_SHAMAN_IGNEOUS_POTENTIAL, EFFECT_0))
            procChance += igneousPotential->GetAmount();

        float missChance = std::max(100 - procChance, 0.0f) / 100.0f;

        procChance = (1.0f - std::pow(missChance, _normalizedTicks)) * 100.0f;

        return roll_chance_f(procChance);
    }

    void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& /*eventInfo*/)
    {
        _normalizedTicks = 0.0f;

        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_LAVA_SURGE, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_lava_surge::CheckProcChance, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_sha_lava_surge::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

    float _normalizedTicks = 0.0f;
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

    void ResetCooldown() const
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
        return ValidateSpellInfo({ SPELL_SHAMAN_LIGHTNING_BOLT_ENERGIZE })
            && ValidateSpellEffect({ { SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_0 } });
    }

    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        if (AuraEffect const* energizeAmount = GetCaster()->GetAuraEffect(SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_0))
            GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_LIGHTNING_BOLT_ENERGIZE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = energizeAmount,
                .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, energizeAmount->GetAmount() } }
            });
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
        return ValidateSpellInfo({ SPELL_SHAMAN_LIGHTNING_BOLT_OVERLOAD_ENERGIZE })
            && ValidateSpellEffect({ { SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_1 } });
    }

    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        if (AuraEffect const* energizeAmount = GetCaster()->GetAuraEffect(SPELL_SHAMAN_MAELSTROM_CONTROLLER, EFFECT_1))
            GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_LIGHTNING_BOLT_OVERLOAD_ENERGIZE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = energizeAmount,
                .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, energizeAmount->GetAmount() } }
            });
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

    void HandleEffectHitTarget(SpellEffIndex /*effIndex*/) const
    {
        if (Unit* hitUnit = GetHitUnit())
            GetCaster()->CastSpell(hitUnit, SPELL_SHAMAN_LIQUID_MAGMA_HIT, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
    }

    static void HandleTargetSelect(SpellScript const&, std::list<WorldObject*>& targets)
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

bool spell_sha_maelstrom_weapon_base::Validate()
{
    return SpellScriptBase::ValidateSpellInfo
    ({
        SPELL_SHAMAN_MAELSTROM_WEAPON_VISIBLE_AURA,
        SPELL_SHAMAN_MAELSTROM_WEAPON_OVERLAY,
        SPELL_SHAMAN_MAELSTROM_WEAPON_OVERLAY_HEALS,
        SPELL_SHAMAN_OVERFLOWING_MAELSTROM_TALENT,
        SPELL_SHAMAN_OVERFLOWING_MAELSTROM_AURA,
        SPELL_SHAMAN_STORMWEAVER_PVP_TALENT_BUFF,
        SPELL_SHAMAN_ICE_STRIKE_PROC,
        SPELL_SHAMAN_HAILSTORM_BUFF,
        SPELL_SHAMAN_HAILSTORM_TALENT
    }) && SpellScriptBase::ValidateSpellEffect
    ({
        { SPELL_SHAMAN_MAELSTROM_WEAPON_MOD_AURA, EFFECT_1 },
        { SPELL_SHAMAN_STORMWEAVER_PVP_TALENT, EFFECT_0 }
    });
}

void spell_sha_maelstrom_weapon_base::GenerateMaelstromWeapon(Unit* shaman, int32 stacks)
{
    CastSpellExtraArgs args;
    args.SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    while (--stacks >= 0)
    {
        uint32 totalStacks = shaman->GetAuraCount(SPELL_SHAMAN_MAELSTROM_WEAPON_VISIBLE_AURA);
        if (totalStacks >= 4)
        {
            // cast action bar overlays
            if (!shaman->HasAura(SPELL_SHAMAN_STORMWEAVER_PVP_TALENT))
                shaman->CastSpell(shaman, SPELL_SHAMAN_MAELSTROM_WEAPON_OVERLAY_HEALS, args);

            shaman->CastSpell(shaman, SPELL_SHAMAN_MAELSTROM_WEAPON_OVERLAY, args);
        }

        shaman->CastSpell(shaman, SPELL_SHAMAN_MAELSTROM_WEAPON_MOD_AURA, args);
        shaman->CastSpell(shaman, SPELL_SHAMAN_MAELSTROM_WEAPON_VISIBLE_AURA, args);
        if (totalStacks >= 5 && shaman->HasAura(SPELL_SHAMAN_OVERFLOWING_MAELSTROM_TALENT))
            shaman->CastSpell(shaman, SPELL_SHAMAN_OVERFLOWING_MAELSTROM_AURA, args);
    }
}

void spell_sha_maelstrom_weapon_base::ConsumeMaelstromWeapon(Unit* shaman, Aura* maelstromWeaponVisibleAura, int32 stacks, Spell const* consumingSpell)
{
    if (AuraEffect const* stormweaver = shaman->GetAuraEffect(SPELL_SHAMAN_STORMWEAVER_PVP_TALENT, EFFECT_0))
    {
        shaman->RemoveAurasDueToSpell(SPELL_SHAMAN_STORMWEAVER_PVP_TALENT_BUFF);    // remove to ensure new buff has exactly "consumedStacks" stacks
        if (Aura const* maelstromSpellMod = shaman->GetAura(SPELL_SHAMAN_MAELSTROM_WEAPON_MOD_AURA))
            shaman->CastSpell(shaman, SPELL_SHAMAN_STORMWEAVER_PVP_TALENT_BUFF, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = consumingSpell,
                .SpellValueOverrides = {
                    { SPELLVALUE_BASE_POINT0, maelstromSpellMod->GetEffect(EFFECT_0)->GetAmount() },
                    // this is indeed very silly but it is how it behaves on official servers
                    // it ignores how many stacks were actually consumed and calculates benefit from max stacks (Thorim's Invocation can consume less stacks than entire aura)
                    { SPELLVALUE_BASE_POINT1, CalculatePct(maelstromSpellMod->GetEffect(EFFECT_1)->GetAmount(), stormweaver->GetAmount()) },
                    { SPELLVALUE_AURA_STACK, std::min<int32>(stacks, maelstromWeaponVisibleAura->GetStackAmount()) }
                }
            });
    }

    if (Aura const* iceStrike = shaman->GetAura(SPELL_SHAMAN_ICE_STRIKE_PROC))
        if (spell_sha_ice_strike_proc* script = iceStrike->GetScript<spell_sha_ice_strike_proc>())
            script->AttemptProc();

    if (shaman->HasAura(SPELL_SHAMAN_HAILSTORM_TALENT))
        shaman->CastSpell(shaman, SPELL_SHAMAN_HAILSTORM_BUFF, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = consumingSpell,
            .SpellValueOverrides = { { SPELLVALUE_AURA_STACK, std::min<int32>(stacks, maelstromWeaponVisibleAura->GetStackAmount()) } }
        });

    if (maelstromWeaponVisibleAura->ModStackAmount(-stacks))
        return;

    // not removed
    uint8 newStacks = maelstromWeaponVisibleAura->GetStackAmount();

    if (Aura* overflowingMaelstrom = shaman->GetAura(SPELL_SHAMAN_OVERFLOWING_MAELSTROM_AURA))
    {
        if (newStacks > 5)
            overflowingMaelstrom->SetStackAmount(newStacks - 5);
        else
            overflowingMaelstrom->Remove();
    }

    if (Aura* maelstromSpellMod = shaman->GetAura(SPELL_SHAMAN_MAELSTROM_WEAPON_MOD_AURA))
    {
        if (newStacks > 0)
            maelstromSpellMod->SetStackAmount(std::min<uint8>(newStacks, 5));
        else
            maelstromSpellMod->Remove();
    }

    if (newStacks < 5)
    {
        shaman->RemoveAurasDueToSpell(SPELL_SHAMAN_MAELSTROM_WEAPON_OVERLAY);
        shaman->RemoveAurasDueToSpell(SPELL_SHAMAN_MAELSTROM_WEAPON_OVERLAY_HEALS);
    }
}

// 187880 - Maelstrom Weapon
class spell_sha_maelstrom_weapon : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return spell_sha_maelstrom_weapon_base::Validate();
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& /*procEvent*/) const
    {
        spell_sha_maelstrom_weapon_base::GenerateMaelstromWeapon(GetTarget(), 1);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_maelstrom_weapon::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 344179 - Maelstrom Weapon
class spell_sha_maelstrom_weapon_proc : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return spell_sha_maelstrom_weapon_base::Validate();
    }

    bool CheckProc(ProcEventInfo const& procEvent) const
    {
        Spell const* procSpell = procEvent.GetProcSpell();
        if (!procSpell)
            return false;

        Aura* maelstromSpellMod = GetTarget()->GetAura(SPELL_SHAMAN_MAELSTROM_WEAPON_MOD_AURA);
        if (!maelstromSpellMod)
            return false;

        return procSpell->m_appliedMods.contains(maelstromSpellMod);
    }

    void RemoveMaelstromAuras(ProcEventInfo const& procEvent) const
    {
        Unit* shaman = GetTarget();
        int32 stacksToConsume = 5;
        if (shaman->HasAura(SPELL_SHAMAN_OVERFLOWING_MAELSTROM_TALENT))
            stacksToConsume = 10;

        spell_sha_maelstrom_weapon_base::ConsumeMaelstromWeapon(shaman, GetAura(), stacksToConsume, procEvent.GetProcSpell());
    }

    void ExpireMaelstromAuras(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* shaman = GetTarget();
        AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
        shaman->RemoveAurasDueToSpell(SPELL_SHAMAN_OVERFLOWING_MAELSTROM_AURA, ObjectGuid::Empty, 0, removeMode);
        shaman->RemoveAurasDueToSpell(SPELL_SHAMAN_MAELSTROM_WEAPON_MOD_AURA, ObjectGuid::Empty, 0, removeMode);
        shaman->RemoveAurasDueToSpell(SPELL_SHAMAN_MAELSTROM_WEAPON_OVERLAY, ObjectGuid::Empty, 0, removeMode);
        shaman->RemoveAurasDueToSpell(SPELL_SHAMAN_MAELSTROM_WEAPON_OVERLAY_HEALS, ObjectGuid::Empty, 0, removeMode);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_maelstrom_weapon_proc::CheckProc);
        OnProc += AuraProcFn(spell_sha_maelstrom_weapon_proc::RemoveMaelstromAuras);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sha_maelstrom_weapon_proc::ExpireMaelstromAuras, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
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
            SPELL_SHAMAN_STORMKEEPER
        });
    }

    static bool CheckProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
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
            if (eventInfo.GetProcSpell()->m_appliedMods.contains(stormkeeper))
                chance = 100.0f;

        return roll_chance_f(chance);
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& procInfo)
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

    static uint32 GetTriggeredSpellId(uint32 triggeringSpellId)
    {
        switch (triggeringSpellId)
        {
            case SPELL_SHAMAN_LIGHTNING_BOLT: return SPELL_SHAMAN_LIGHTNING_BOLT_OVERLOAD;
            case SPELL_SHAMAN_ELEMENTAL_BLAST: return SPELL_SHAMAN_ELEMENTAL_BLAST_OVERLOAD;
            case SPELL_SHAMAN_ICEFURY: return SPELL_SHAMAN_ICEFURY_OVERLOAD;
            case SPELL_SHAMAN_LAVA_BURST: return SPELL_SHAMAN_LAVA_BURST_OVERLOAD;
            case SPELL_SHAMAN_CHAIN_LIGHTNING: return SPELL_SHAMAN_CHAIN_LIGHTNING_OVERLOAD;
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

// 334033 - Molten Assault (60103 - Lava Lash)
class spell_sha_molten_assault : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_FLAME_SHOCK });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_SHAMAN_MOLTEN_ASSAULT);
    }

    void TriggerFlameShocks(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        Unit const* lavaLashTarget = GetHitUnit();
        if (!lavaLashTarget->HasAura(SPELL_SHAMAN_FLAME_SHOCK, caster->GetGUID()))
            return;

        float range = 10.0f;
        std::vector<WorldObject*> targets;
        Trinity::WorldObjectSpellAreaTargetCheck check(range, lavaLashTarget, caster, caster, sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_FLAME_SHOCK, DIFFICULTY_NONE),
            TARGET_CHECK_ENEMY, nullptr, TARGET_OBJECT_TYPE_UNIT, Trinity::WorldObjectSpellAreaTargetSearchReason::Area);
        Trinity::WorldObjectListSearcher searcher(caster, targets, check, GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER);
        Cell::VisitAllObjects(lavaLashTarget, searcher, range + EXTRA_CELL_SEARCH_RADIUS);

        auto withoutFlameShockItr = std::partition(targets.begin(), targets.end(), Trinity::UnitAuraCheck(true, SPELL_SHAMAN_FLAME_SHOCK, GetCaster()->GetGUID()));
        std::size_t flameShocksMissing = GetEffectValue() + 1 - std::ranges::distance(targets.begin(), withoutFlameShockItr);

        if (flameShocksMissing)
            Trinity::Containers::RandomShuffle(withoutFlameShockItr, targets.end());

        CastSpellExtraArgs args;
        args.SetTriggerFlags(TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD | TRIGGERED_IGNORE_POWER_COST | TRIGGERED_IGNORE_CAST_IN_PROGRESS);
        args.SetTriggeringSpell(GetSpell());

        // targets that already have flame shock are first in the list (and need to refresh it)
        for (std::size_t i = 0; i < std::min<std::size_t>(targets.size(), GetEffectValue() + 1); ++i)
            caster->CastSpell(targets[i], SPELL_SHAMAN_FLAME_SHOCK, args);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_molten_assault::TriggerFlameShocks, EFFECT_2, SPELL_EFFECT_DUMMY);
    }
};

// 469344 Molten Thunder
class spell_sha_molten_thunder : public AuraScript
{
    void Register() override { }

public:
    int32 ProcCount = 0;
};

class spell_sha_molten_thunder_sundering : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_MOLTEN_THUNDER_TALENT, SPELL_SHAMAN_MOLTEN_THUNDER_PROC });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_SHAMAN_MOLTEN_THUNDER_TALENT);
    }

    static void RemoveIncapacitateEffect(SpellScript const&, std::list<WorldObject*>& targets)
    {
        targets.clear();
    }

    void RollReset() const
    {
        Unit* shaman = GetCaster();
        Aura const* talent = shaman->GetAura(SPELL_SHAMAN_MOLTEN_THUNDER_TALENT);
        if (!talent)
            return;

        AuraEffect const* chanceBaseEffect = talent->GetEffect(EFFECT_1);
        AuraEffect const* chancePerTargetEffect = talent->GetEffect(EFFECT_2);
        AuraEffect const* targetLimitEffect = talent->GetEffect(EFFECT_3);
        if (!chanceBaseEffect || !chancePerTargetEffect || !targetLimitEffect)
            return;

        spell_sha_molten_thunder* counterScript = talent->GetScript<spell_sha_molten_thunder>();
        if (!counterScript)
            return;

        int32 procChance = chanceBaseEffect->GetAmount();
        procChance += std::min<int32>(targetLimitEffect->GetAmount(), GetUnitTargetCountForEffect(EFFECT_0)) * chancePerTargetEffect->GetAmount();
        procChance >>= counterScript->ProcCount; // Each consecutive reset reduces these chances by half
        if (roll_chance_i(procChance))
        {
            shaman->CastSpell(shaman, SPELL_SHAMAN_MOLTEN_THUNDER_PROC, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
            });
            shaman->GetSpellHistory()->ResetCooldown(GetSpellInfo()->Id, true);
            ++counterScript->ProcCount;
        }
        else
            counterScript->ProcCount = 0;
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_molten_thunder_sundering::RemoveIncapacitateEffect, EFFECT_3, TARGET_UNIT_RECT_CASTER_ENEMY);
        AfterCast += SpellCastFn(spell_sha_molten_thunder_sundering::RollReset);
    }
};

// 30884 - Nature's Guardian
class spell_sha_natures_guardian : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_NATURES_GUARDIAN_COOLDOWN });
    }

    static bool CheckProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        return eventInfo.GetActionTarget()->HealthBelowPct(aurEff->GetAmount())
            && !eventInfo.GetActionTarget()->HasAura(SPELL_SHAMAN_NATURES_GUARDIAN_COOLDOWN);
    }

    static void StartCooldown(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        Unit* shaman = eventInfo.GetActionTarget();
        shaman->CastSpell(shaman, SPELL_SHAMAN_NATURES_GUARDIAN_COOLDOWN, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_natures_guardian::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_sha_natures_guardian::StartCooldown, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 210621 - Path of Flames Spread
class spell_sha_path_of_flames_spread : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_FLAME_SHOCK });
    }

    void FilterTargets(std::list<WorldObject*>& targets) const
    {
        targets.remove(GetExplTargetUnit());
        Trinity::Containers::RandomResize(targets, Trinity::UnitAuraCheck(false, SPELL_SHAMAN_FLAME_SHOCK, GetCaster()->GetGUID()), 1);
    }

    void HandleScript(SpellEffIndex /*effIndex*/) const
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

// 375982 - Primordial Wave
class spell_sha_primordial_wave : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_FLAME_SHOCK, SPELL_SHAMAN_PRIMORDIAL_WAVE_DAMAGE });
    }

    void TriggerDamage(SpellEffIndex /*effIndex*/) const
    {
        Unit* shaman = GetCaster();
        std::vector<Unit*> targets;
        FireNovaTargetCheck check{ .MaxSearchRange = GetSpell()->GetMinMaxRange(false).second, .Shaman = shaman };
        Trinity::UnitListSearcher searcher(shaman, targets, check);
        Cell::VisitAllObjects(shaman, searcher, check.MaxSearchRange);

        CastSpellExtraArgs args;
        args.SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        args.SetTriggeringSpell(GetSpell());

        for (Unit* target : targets)
            shaman->CastSpell(target, SPELL_SHAMAN_PRIMORDIAL_WAVE_DAMAGE, args);
    }

    void PreventLavaSurge(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
    }

    void EnergizeMaelstrom(SpellEffIndex /*effIndex*/) const
    {
        spell_sha_maelstrom_weapon_base::GenerateMaelstromWeapon(GetCaster(), GetEffectValue());
    }

    void Register() override
    {
        ChrSpecialization specialization = ChrSpecialization::None;
        if (Spell const* spell = GetSpell()) // spell doesn't exist at startup validation
            if (Player const* caster = Object::ToPlayer(spell->GetCaster()))
                specialization = caster->GetPrimarySpecialization();

        OnEffectHitTarget += SpellEffectFn(spell_sha_primordial_wave::TriggerDamage, EFFECT_0, SPELL_EFFECT_DUMMY);

        if (specialization != ChrSpecialization::ShamanElemental)
            OnEffectLaunch += SpellEffectFn(spell_sha_primordial_wave::PreventLavaSurge, EFFECT_5, SPELL_EFFECT_TRIGGER_SPELL);

        if (specialization == ChrSpecialization::None || specialization == ChrSpecialization::ShamanEnhancement)
            OnEffectHitTarget += SpellEffectFn(spell_sha_primordial_wave::EnergizeMaelstrom, EFFECT_4, SPELL_EFFECT_DUMMY);
    }
};

// 114083 - Restorative Mists
// 294020 - Restorative Mists
class spell_sha_restorative_mists : public SpellScript
{
    void HandleHeal(SpellEffIndex effIndex)
    {
        SetHitHeal(GetHitHeal() / GetUnitTargetCountForEffect(effIndex));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_restorative_mists::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
    }
};

// 2645 - Ghost Wolf
// 260878 - Spirit Wolf
class spell_sha_spirit_wolf : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_GHOST_WOLF, SPELL_SHAMAN_SPIRIT_WOLF_TALENT, SPELL_SHAMAN_SPIRIT_WOLF_PERIODIC, SPELL_SHAMAN_SPIRIT_WOLF_AURA });
    }

    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_SHAMAN_SPIRIT_WOLF_TALENT) && target->HasAura(SPELL_SHAMAN_GHOST_WOLF))
            target->CastSpell(target, SPELL_SHAMAN_SPIRIT_WOLF_PERIODIC, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_FULL_MASK,
                .TriggeringAura = aurEff
            });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
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

// 319930 - Stormblast
class spell_sha_stormblast : public AuraScript
{
    void Register() override { }

public:
    ObjectGuid AllowedOriginalCastId;
};

// 470466 - Stormblast (Stormstrike and Winstrike damaging spells)
class spell_sha_stormblast_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({
            { SPELL_SHAMAN_STORMBLAST_TALENT, EFFECT_0 },
            { SPELL_SHAMAN_ENHANCED_ELEMENTS, EFFECT_0 }
        });
    }

    bool Load() override
    {
        if (Aura const* stormblast = GetCaster()->GetAura(SPELL_SHAMAN_STORMBLAST_TALENT))
            if (spell_sha_stormblast const* script = stormblast->GetScript<spell_sha_stormblast>())
                return script->AllowedOriginalCastId == GetSpell()->m_originalCastId;

        return false;
    }

    void TriggerDamage() const
    {
        if (AuraEffect const* stormblast = GetCaster()->GetAuraEffect(SPELL_SHAMAN_STORMBLAST_TALENT, EFFECT_0))
        {
            int32 damage = CalculatePct(GetHitDamage(), stormblast->GetAmount());

            // Not part of SpellFamilyFlags for mastery effect but known to be affected by it
            if (AuraEffect const* mastery = GetCaster()->GetAuraEffect(SPELL_SHAMAN_ENHANCED_ELEMENTS, EFFECT_0))
                AddPct(damage, mastery->GetAmount());

            GetCaster()->CastSpell(GetHitUnit(), SPELL_SHAMAN_STORMBLAST_DAMAGE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, damage } }
            });
        }
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_sha_stormblast_damage::TriggerDamage);
    }
};

// 470466 - Stormblast (17364 - Stormstrike, 115356 - Windstrike)
class spell_sha_stormblast_proc : public SpellScript
{
    bool Load() override
    {
        Unit const* caster = GetCaster();
        return caster->HasAura(SPELL_SHAMAN_STORMBLAST_TALENT)
            && caster->HasAura(SPELL_SHAMAN_STORMBLAST_PROC);
    }

    // Store allowed CastId in passive aura because damaging spells are delayed (and delayed further if Stormflurry is triggered)
    void SaveCastId() const
    {
        Unit* caster = GetCaster();
        if (Aura* stormblast = caster->GetAura(SPELL_SHAMAN_STORMBLAST_TALENT))
            if (spell_sha_stormblast* script = stormblast->GetScript<spell_sha_stormblast>())
                script->AllowedOriginalCastId = GetSpell()->m_castId;

        caster->RemoveAuraFromStack(SPELL_SHAMAN_STORMBLAST_PROC);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_sha_stormblast_proc::SaveCastId);
    }
};

class StormflurryEvent : public BasicEvent
{
public:
    struct Data
    {
        int32 DamagePercent = 0;
    };

    explicit StormflurryEvent(Unit* caster, Unit* target, ObjectGuid const& originalCastId, int32 damagePercent,
        uint32 mainHandDamageSpellId, uint32 offHandDamageSpellId, int32 procChance)
        : _caster(caster), _target(target), _originalCastId(originalCastId), _damagePercent(damagePercent),
            _mainHandDamageSpellId(mainHandDamageSpellId), _offHandDamageSpellId(offHandDamageSpellId), _procChance(procChance)
    {
    }

    bool Execute(uint64 time, uint32 /*diff*/) override
    {
        if (!_target.Targets)
            return true;

        _target.Targets->Update(_caster);

        CastSpellExtraArgs args;
        args.TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR;
        args.OriginalCastId = _originalCastId;
        args.CustomArg.emplace<Data>().DamagePercent = _damagePercent;

        _caster->CastSpell(_target, _mainHandDamageSpellId, args);
        _caster->CastSpell(_target, _offHandDamageSpellId, args);

        if (!roll_chance_i(_procChance))
            return true;

        _caster->m_Events.AddEvent(this, Milliseconds(time) + 200ms);
        return false;
    }

private:
    Unit* _caster;
    CastSpellTargetArg _target;
    ObjectGuid _originalCastId;
    int32 _damagePercent;
    uint32 _mainHandDamageSpellId;
    uint32 _offHandDamageSpellId;
    int32 _procChance;
};

// 198367 Stormflurry
// 344357 Stormflurry
class spell_sha_stormflurry : public SpellScript
{
public:
    explicit spell_sha_stormflurry(uint32 stormflurrySpellId, uint32 mainHandDamageSpellId, uint32 offHandDamageSpellId)
        : _stormflurrySpellId(stormflurrySpellId), _mainHandDamageSpellId(mainHandDamageSpellId), _offHandDamageSpellId(offHandDamageSpellId) { }

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ _stormflurrySpellId, _mainHandDamageSpellId, _offHandDamageSpellId })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } })
            && spellInfo->GetEffect(EFFECT_0).IsEffect(SPELL_EFFECT_TRIGGER_SPELL)
            && spellInfo->GetEffect(EFFECT_1).IsEffect(SPELL_EFFECT_TRIGGER_SPELL);
    }

    bool Load() override
    {
        return GetCaster()->HasAura(_stormflurrySpellId);
    }

    void HandleProc(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        Aura const* stormflurry = caster->GetAura(_stormflurrySpellId);
        if (!stormflurry)
            return;

        AuraEffect const* chanceEffect = stormflurry->GetEffect(EFFECT_0);
        AuraEffect const* damageEffect = stormflurry->GetEffect(EFFECT_1);
        if (!chanceEffect || !damageEffect)
            return;

        int32 procChance = chanceEffect->GetAmount();
        if (!roll_chance_i(procChance))
            return;

        caster->m_Events.AddEventAtOffset(new StormflurryEvent(caster, GetHitUnit(), GetSpell()->m_castId, damageEffect->GetAmount(),
            _mainHandDamageSpellId, _offHandDamageSpellId, procChance), 200ms);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_stormflurry::HandleProc, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
    }

private:
    uint32 _stormflurrySpellId;
    uint32 _mainHandDamageSpellId;
    uint32 _offHandDamageSpellId;
};

// 32175 - Stormstrike
// 32176 - Stormstrike Off-Hand
class spell_sha_stormflurry_damage : public SpellScript
{
    bool Load() override
    {
        return GetSpell()->m_customArg.type() == typeid(StormflurryEvent::Data);
    }

    void ApplyModifier(SpellEffectInfo const& /*effectInfo*/, Unit* /*victim*/, int32& /*damage*/, int32& /*flatMod*/, float& pctMod) const
    {
        ApplyPct(pctMod, std::any_cast<StormflurryEvent::Data>(&GetSpell()->m_customArg)->DamagePercent);
    }

    void Register() override
    {
        CalcDamage += SpellCalcDamageFn(spell_sha_stormflurry_damage::ApplyModifier);
    }
};

// 201845 - Stormsurge
class spell_sha_stormsurge : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_STORMSURGE_PROC });
    }

    static void HandleProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_SHAMAN_STORMSURGE_PROC, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_stormsurge::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 187881 - Maelstrom Weapon
class spell_sha_stormweaver : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_STORMWEAVER_PVP_TALENT });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_SHAMAN_STORMWEAVER_PVP_TALENT);
    }

    static void PreventAffectingHealingSpells(SpellScript const&, WorldObject*& target)
    {
        target = nullptr;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_sha_stormweaver::PreventAffectingHealingSpells, EFFECT_2, TARGET_UNIT_CASTER);
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_sha_stormweaver::PreventAffectingHealingSpells, EFFECT_4, TARGET_UNIT_CASTER);
    }
};

// 384359 - Swirling Maelstrom
class spell_sha_swirling_maelstrom : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } })
            && spell_sha_maelstrom_weapon_base::Validate();
    }

    bool CheckHailstormProc(ProcEventInfo const& eventInfo) const
    {
        if (eventInfo.GetSpellInfo()->IsAffected(SPELLFAMILY_SHAMAN, { 0x80000000, 0x0, 0x0, 0x0 })) // Frost Shock
        {
            Aura* hailstorm = eventInfo.GetActor()->GetAura(SPELL_SHAMAN_HAILSTORM_BUFF);
            if (!hailstorm || hailstorm->GetStackAmount() < GetEffect(EFFECT_1)->GetAmount())
                return false;

            if (!eventInfo.GetProcSpell()->m_appliedMods.contains(hailstorm))
                return false;
        }

        return true;
    }

    void EnergizeMaelstrom(AuraEffect const* aurEff, ProcEventInfo const& /*eventInfo*/) const
    {
        spell_sha_maelstrom_weapon_base::GenerateMaelstromWeapon(GetTarget(), aurEff->GetAmount());
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_swirling_maelstrom::CheckHailstormProc);
        OnEffectProc += AuraEffectProcFn(spell_sha_swirling_maelstrom::EnergizeMaelstrom, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 384444 - Thorim's Invocation
class spell_sha_thorims_invocation : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_LIGHTNING_BOLT, SPELL_SHAMAN_CHAIN_LIGHTNING });
    }

    void Register() override
    {
    }

public:
    uint32 SpellIdToTrigger = SPELL_SHAMAN_LIGHTNING_BOLT;
};

// 188196 - Lightning Bolt
// 188443 - Chain Lightning
// 452201 - Tempest
class spell_sha_thorims_invocation_primer : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_THORIMS_INVOCATION, SPELL_SHAMAN_LIGHTNING_BOLT, SPELL_SHAMAN_CHAIN_LIGHTNING })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } })
            && spellInfo->GetEffect(EFFECT_0).IsEffect(SPELL_EFFECT_SCHOOL_DAMAGE);
    }

    void UpdateThorimsInvocationSpell() const
    {
        if (Aura const* thorimsInvocation = GetCaster()->GetAura(SPELL_SHAMAN_THORIMS_INVOCATION))
            if (spell_sha_thorims_invocation* spellIdHolder = thorimsInvocation->GetScript<spell_sha_thorims_invocation>())
                spellIdHolder->SpellIdToTrigger = GetUnitTargetCountForEffect(EFFECT_0) > 1 ? SPELL_SHAMAN_CHAIN_LIGHTNING : SPELL_SHAMAN_LIGHTNING_BOLT;
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sha_thorims_invocation_primer::UpdateThorimsInvocationSpell);
    }
};

// 115357 - Windstrike (MH)
class spell_sha_thorims_invocation_trigger : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_SHAMAN_THORIMS_INVOCATION, EFFECT_0 } });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_SHAMAN_THORIMS_INVOCATION);
    }

    void TriggerLightningSpell(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();

        AuraEffect const* thorimsInvocation = caster->GetAuraEffect(SPELL_SHAMAN_THORIMS_INVOCATION, EFFECT_0);
        if (!thorimsInvocation)
            return;

        spell_sha_thorims_invocation const* spellIdHolder = thorimsInvocation->GetBase()->GetScript<spell_sha_thorims_invocation>();
        if (!spellIdHolder)
            return;

        auto [spellInfo, triggerFlags] = caster->GetCastSpellInfo(sSpellMgr->GetSpellInfo(spellIdHolder->SpellIdToTrigger, GetCastDifficulty()));

        // Remove Overflowing Maelstrom spellmod early to make next cast behave as if it consumed only 5 or less maelstrom stacks
        // this works because consuming "up to 5 stacks" will always cause Maelstrom Weapon stacks to drop to 5 or lower
        // which means Overflowing Maelstrom needs removing anyway
        caster->RemoveAurasDueToSpell(SPELL_SHAMAN_OVERFLOWING_MAELSTROM_AURA);

        caster->CastSpell(GetHitUnit(), spellInfo->Id, CastSpellExtraArgsInit{
            .TriggerFlags = triggerFlags | TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_IGNORE_CAST_TIME | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });

        // Manually remove stacks - Maelstrom Weapon aura cannot proc from procs and free Lightning Bolt/Chain Lightning procs from Arc Discharge (455096) shoulnd't consume it
        if (Aura* maelstromWeaponVisibleAura = caster->GetAura(SPELL_SHAMAN_MAELSTROM_WEAPON_VISIBLE_AURA))
            spell_sha_maelstrom_weapon_base::ConsumeMaelstromWeapon(caster, maelstromWeaponVisibleAura, thorimsInvocation->GetAmount());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_thorims_invocation_trigger::TriggerLightningSpell, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 51564 - Tidal Waves
class spell_sha_tidal_waves : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_TIDAL_WAVES });
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo const& /*eventInfo*/)
    {
        PreventDefaultAction();

        GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_TIDAL_WAVES, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK,
            .TriggeringAura = aurEff,
            .SpellValueOverrides =
            {
                { SPELLVALUE_BASE_POINT0, -aurEff->GetAmount() },
                { SPELLVALUE_BASE_POINT1, aurEff->GetAmount() }
            }
        });
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

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
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

        caster->CastSpell(target, spellId, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK,
            .TriggeringAura = aurEff
        });
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

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
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

        caster->CastSpell(target, SPELL_SHAMAN_ELECTRIFIED, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK,
            .TriggeringAura = aurEff,
            .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, amount } }
        });
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

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
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

        caster->CastSpell(target, SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK,
            .TriggeringAura = aurEff,
            .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, amount } }
        });
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_t9_elemental_4p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 70817 - Item - Shaman T10 Elemental 4P Bonus
class spell_sha_t10_elemental_4p_bonus : public AuraScript
{
    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
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

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
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

        caster->CastSpell(target, SPELL_SHAMAN_CHAINED_HEAL, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK,
            .TriggeringAura = aurEff,
            .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, amount } }
        });
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

    static void HandleProc(AuraScript const&, AuraEffect const* /*aurEff*/, ProcEventInfo const& procInfo)
    {
        Unit* caster = procInfo.GetActor();
        if (Aura* aura = caster->GetAura(SPELL_SHAMAN_UNLIMITED_POWER_BUFF))
            aura->SetStackAmount(aura->GetStackAmount() + 1);
        else
            caster->CastSpell(caster, SPELL_SHAMAN_UNLIMITED_POWER_BUFF, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_FULL_MASK,
                .TriggeringSpell = procInfo.GetProcSpell()
            });
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

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& /*eventInfo*/)
    {
        if (++_castCounter == 3)
        {
            GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_UNDULATION_PROC, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
            _castCounter = 0;
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_undulation_passive::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

    uint8 _castCounter = 1; // first proc happens after two casts, then one every 3 casts
};

// 470490 - Unrelenting Storms
class spell_sha_unrelenting_storms : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_UNRELENTING_STORMS_REDUCTION })
            && ValidateSpellEffect({ { SPELL_SHAMAN_UNRELENTING_STORMS_TALENT, EFFECT_1 } });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_SHAMAN_UNRELENTING_STORMS_TALENT);
    }

    void Trigger(SpellEffIndex effIndex) const
    {
        Unit* shaman = GetCaster();
        Aura const* unrelentingStorms = shaman->GetAura(SPELL_SHAMAN_UNRELENTING_STORMS_TALENT);
        if (!unrelentingStorms)
            return;

        int64 targetLimit = 0;
        if (AuraEffect const* limitEffect = unrelentingStorms->GetEffect(EFFECT_0))
            targetLimit = limitEffect->GetAmount();

        if (GetUnitTargetCountForEffect(effIndex) > targetLimit)
            return;

        SpellHistory::Duration cooldown = 0ms;
        if (AuraEffect const* reductionPctEffect = unrelentingStorms->GetEffect(EFFECT_1))
        {
            SpellHistory::GetCooldownDurations(GetSpellInfo(), 0, &cooldown, nullptr, nullptr);

            shaman->CastSpell(shaman, SPELL_SHAMAN_UNRELENTING_STORMS_REDUCTION, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, -int32(CalculatePct(cooldown.count(), reductionPctEffect->GetAmount())) } }
            });
        }

        if (shaman->HasAura(SPELL_SHAMAN_WINDFURY_AURA))
            WindfuryProcEvent::Trigger(shaman, GetHitUnit());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_unrelenting_storms::Trigger, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 470057 - Voltaic Blaze
class spell_sha_voltaic_blaze : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return spell_sha_maelstrom_weapon_base::Validate();
    }

    void ApplyFlameShock(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        caster->m_Events.AddEventAtOffset([caster, targets = CastSpellTargetArg(GetHitUnit())]() mutable
        {
            if (!targets.Targets)
                return;

            targets.Targets->Update(caster);

            caster->CastSpell(targets, SPELL_SHAMAN_FLAME_SHOCK, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
        }, 500ms);
    }

    void EnergizeMaelstrom(SpellEffIndex /*effIndex*/) const
    {
        spell_sha_maelstrom_weapon_base::GenerateMaelstromWeapon(GetCaster(), GetEffectValue());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_voltaic_blaze::ApplyFlameShock, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectHitTarget += SpellEffectFn(spell_sha_voltaic_blaze::EnergizeMaelstrom, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 470058 - Voltaic Blaze
class spell_sha_voltaic_blaze_aura : public AuraScript
{
    static bool CheckProc(AuraScript const&, ProcEventInfo const& eventInfo)
    {
        // 470057 - Voltaic Blaze does not have any unique SpellFamilyFlags, check by id
        return eventInfo.GetSpellInfo()->Id == SPELL_SHAMAN_VOLTAIC_BLAZE_DAMAGE;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_voltaic_blaze_aura::CheckProc);
    }
};

// 470053 - Voltaic Blaze
class spell_sha_voltaic_blaze_talent : public AuraScript
{
    static bool CheckProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& /*eventInfo*/)
    {
        return roll_chance_i(aurEff->GetAmount());
    }

    static void HandleProc(AuraScript const&, AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo)
    {
        eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_SHAMAN_VOLTAIC_BLAZE_OVERRIDE);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_sha_voltaic_blaze_talent::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_sha_voltaic_blaze_talent::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
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
            GetCaster()->CastSpell(mainHand, SPELL_SHAMAN_WINDFURY_ENCHANTMENT, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_FULL_MASK,
                .TriggeringSpell = GetSpell()
            });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_windfury_weapon::HandleEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

bool WindfuryProcEvent::Execute(uint64 time, uint32 /*diff*/)
{
    if (!_target.Targets)
        return true;

    _target.Targets->Update(_shaman);
    if (!_target.Targets->GetUnitTarget())
        return true;

    CastSpellExtraArgs args;
    args.TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR;
    args.TriggeringAura = _shaman->GetAuraEffect(SPELL_SHAMAN_WINDFURY_AURA, EFFECT_0); // prevent proc from itself

    _shaman->CastSpell(_shaman, _itr->VisualSpellId, args);
    _shaman->CastSpell(_target, SPELL_SHAMAN_WINDFURY_ATTACK, args);

    if (++_itr == _end)
        return true;

    _shaman->m_Events.AddEvent(this, Milliseconds(time) + _itr->Delay);
    return false;
}

void WindfuryProcEvent::Trigger(Unit* shaman, Unit* target)
{
    // Not a separate script because of ordering requirements for Forceful Winds
    if (shaman->HasAuraEffect(SPELL_SHAMAN_FORCEFUL_WINDS_TALENT, EFFECT_0))
    {
        if (Aura* forcefulWinds = shaman->GetAura(SPELL_SHAMAN_FORCEFUL_WINDS_PROC))
        {
            // gaining a stack should not refresh duration
            uint32 maxStack = forcefulWinds->CalcMaxStackAmount();
            if (forcefulWinds->GetStackAmount() < maxStack)
                forcefulWinds->SetStackAmount(forcefulWinds->GetStackAmount() + 1);
        }
        else
            shaman->CastSpell(shaman, SPELL_SHAMAN_FORCEFUL_WINDS_PROC, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
            });
    }

    std::ptrdiff_t attacks = 2;
    if (AuraEffect const* unrulyWinds = shaman->GetAuraEffect(SPELL_SHAMAN_UNRULY_WINDS, EFFECT_0); roll_chance_i(unrulyWinds->GetAmount()))
        ++attacks;

    shaman->m_Events.AddEventAtOffset(new WindfuryProcEvent(shaman, target, attacks), Sequence.front().Delay);
}

// 319773 - Windfury Weapon (proc)
class spell_sha_windfury_weapon_proc : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({
            SPELL_SHAMAN_WINDFURY_ATTACK,
            SPELL_SHAMAN_WINDFURY_VISUAL_1,
            SPELL_SHAMAN_WINDFURY_VISUAL_2,
            SPELL_SHAMAN_WINDFURY_VISUAL_3,
            SPELL_SHAMAN_UNRULY_WINDS,
            SPELL_SHAMAN_FORCEFUL_WINDS_TALENT,
            SPELL_SHAMAN_FORCEFUL_WINDS_PROC
        });
    }

    void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo)
    {
        PreventDefaultAction();

        WindfuryProcEvent::Trigger(eventInfo.GetActor(), eventInfo.GetActionTarget());
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_windfury_weapon_proc::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
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
                caster->CastSpell(unit, SPELL_SHAMAN_ARCTIC_SNOWSTORM_SLOW, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR });
        }
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_SHAMAN_ARCTIC_SNOWSTORM_SLOW, at->GetCasterGuid());
    }
};

// 192078 - Wind Rush Totem (Spell)
// 12676 - AreaTriggerId
struct areatrigger_sha_wind_rush_totem : AreaTriggerAI
{
    static constexpr uint32 REFRESH_TIME = 4500;

    using AreaTriggerAI::AreaTriggerAI;

    void OnUpdate(uint32 diff) override
    {
        _refreshTimer -= diff;
        if (_refreshTimer <= 0)
        {
            if (Unit* caster = at->GetCaster())
                for (ObjectGuid const& guid : at->GetInsideUnits())
                    if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                        CastSpeedBuff(caster, unit);

            _refreshTimer += REFRESH_TIME;
        }
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            CastSpeedBuff(caster, unit);
    }

    static void CastSpeedBuff(Unit* caster, Unit* unit)
    {
        if (!caster->IsValidAssistTarget(unit))
            return;

        caster->CastSpell(unit, SPELL_SHAMAN_WIND_RUSH, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
    }

private:
    int32 _refreshTimer = REFRESH_TIME;
};

void AddSC_shaman_spell_scripts()
{
    RegisterSpellScript(spell_sha_aftershock);
    RegisterSpellScript(spell_sha_ancestral_guidance);
    RegisterSpellScript(spell_sha_ancestral_guidance_heal);
    RegisterSpellScript(spell_sha_arctic_snowstorm);
    RegisterSpellScript(spell_sha_artifact_gathering_storms);
    RegisterSpellScript(spell_sha_ascendance_restoration);
    RegisterSpellScript(spell_sha_ashen_catalyst);
    RegisterSpellScript(spell_sha_chain_lightning_crash_lightning);
    RegisterSpellScript(spell_sha_chain_lightning_energize);
    RegisterSpellScript(spell_sha_chain_lightning_overload);
    RegisterSpellScript(spell_sha_converging_storms);
    RegisterSpellScriptWithArgs(spell_sha_delayed_stormstrike_mod_charge_drop_proc, "spell_sha_converging_storms_buff");
    RegisterSpellScript(spell_sha_crash_lightning);
    RegisterSpellScript(spell_sha_deeply_rooted_elements);
    RegisterSpellScript(spell_sha_deluge);
    RegisterSpellScript(spell_sha_deluge_healing_rain);
    RegisterSpellScript(spell_sha_doom_winds);
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
    RegisterSpellScript(spell_sha_elemental_weapons);
    RegisterSpellScript(spell_sha_fire_nova);
    RegisterSpellScript(spell_sha_flame_shock_fire_nova_enabler);
    RegisterSpellScript(spell_sha_flametongue_weapon);
    RegisterSpellScript(spell_sha_flametongue_weapon_aura);
    RegisterSpellScript(spell_sha_hailstorm);
    RegisterSpellAndAuraScriptPair(spell_sha_healing_rain, spell_sha_healing_rain_aura);
    RegisterSpellScript(spell_sha_healing_rain_target_limit);
    RegisterSpellScript(spell_sha_healing_stream_totem_heal);
    RegisterSpellScript(spell_sha_hot_hand);
    RegisterSpellScript(spell_sha_ice_strike);
    RegisterSpellScript(spell_sha_ice_strike_proc);
    RegisterSpellScript(spell_sha_icefury);
    RegisterSpellScript(spell_sha_item_lightning_shield);
    RegisterSpellScript(spell_sha_item_lightning_shield_trigger);
    RegisterSpellScript(spell_sha_item_mana_surge);
    RegisterSpellScript(spell_sha_item_t6_trinket);
    RegisterSpellScript(spell_sha_item_t10_elemental_2p_bonus);
    RegisterSpellScript(spell_sha_item_t18_elemental_4p_bonus);
    RegisterSpellScript(spell_sha_lava_burst);
    RegisterSpellScript(spell_sha_lava_crit_chance);
    RegisterSpellScript(spell_sha_lava_lash);
    RegisterSpellScript(spell_sha_lava_surge);
    RegisterSpellScript(spell_sha_lava_surge_proc);
    RegisterSpellScript(spell_sha_lightning_bolt);
    RegisterSpellScript(spell_sha_lightning_bolt_overload);
    RegisterSpellScript(spell_sha_liquid_magma_totem);
    RegisterSpellScript(spell_sha_maelstrom_weapon);
    RegisterSpellScript(spell_sha_maelstrom_weapon_proc);
    RegisterSpellScript(spell_sha_mastery_elemental_overload);
    RegisterSpellScript(spell_sha_mastery_elemental_overload_proc);
    RegisterSpellScript(spell_sha_molten_assault);
    RegisterSpellScript(spell_sha_molten_thunder);
    RegisterSpellScript(spell_sha_molten_thunder_sundering);
    RegisterSpellScript(spell_sha_natures_guardian);
    RegisterSpellScript(spell_sha_path_of_flames_spread);
    RegisterSpellScript(spell_sha_primordial_wave);
    RegisterSpellScript(spell_sha_restorative_mists);
    RegisterSpellScript(spell_sha_spirit_wolf);
    RegisterSpellScript(spell_sha_stormblast);
    RegisterSpellScript(spell_sha_stormblast_damage);
    RegisterSpellScript(spell_sha_stormblast_proc);
    RegisterSpellScriptWithArgs(spell_sha_stormflurry, "spell_sha_artifact_stormflurry_stormstrike",
        SPELL_SHAMAN_STORMFLURRY_ARTIFACT, SPELL_SHAMAN_STORMSTRIKE_DAMAGE_MAIN_HAND, SPELL_SHAMAN_STORMSTRIKE_DAMAGE_OFF_HAND);
    RegisterSpellScriptWithArgs(spell_sha_stormflurry, "spell_sha_artifact_stormflurry_windstrike",
        SPELL_SHAMAN_STORMFLURRY_ARTIFACT, SPELL_SHAMAN_WINDSTRIKE_DAMAGE_MAIN_HAND, SPELL_SHAMAN_WINDSTRIKE_DAMAGE_OFF_HAND);
    RegisterSpellScriptWithArgs(spell_sha_stormflurry, "spell_sha_stormflurry_stormstrike",
        SPELL_SHAMAN_STORMFLURRY, SPELL_SHAMAN_STORMSTRIKE_DAMAGE_MAIN_HAND, SPELL_SHAMAN_STORMSTRIKE_DAMAGE_OFF_HAND);
    RegisterSpellScriptWithArgs(spell_sha_stormflurry, "spell_sha_stormflurry_windstrike",
        SPELL_SHAMAN_STORMFLURRY, SPELL_SHAMAN_WINDSTRIKE_DAMAGE_MAIN_HAND, SPELL_SHAMAN_WINDSTRIKE_DAMAGE_OFF_HAND);
    RegisterSpellScript(spell_sha_stormflurry_damage);
    RegisterSpellScript(spell_sha_stormsurge);
    RegisterSpellScriptWithArgs(spell_sha_delayed_stormstrike_mod_charge_drop_proc, "spell_sha_stormsurge_proc");
    RegisterSpellScript(spell_sha_stormweaver);
    RegisterSpellScript(spell_sha_swirling_maelstrom);
    RegisterSpellScript(spell_sha_tidal_waves);
    RegisterSpellScript(spell_sha_t3_6p_bonus);
    RegisterSpellScript(spell_sha_t3_8p_bonus);
    RegisterSpellScript(spell_sha_t8_elemental_4p_bonus);
    RegisterSpellScript(spell_sha_t9_elemental_4p_bonus);
    RegisterSpellScript(spell_sha_t10_elemental_4p_bonus);
    RegisterSpellScript(spell_sha_t10_restoration_4p_bonus);
    RegisterSpellScript(spell_sha_thorims_invocation);
    RegisterSpellScript(spell_sha_thorims_invocation_primer);
    RegisterSpellScript(spell_sha_thorims_invocation_trigger);
    RegisterSpellScript(spell_sha_unlimited_power);
    RegisterSpellScript(spell_sha_undulation_passive);
    RegisterSpellScript(spell_sha_unrelenting_storms);
    RegisterSpellScript(spell_sha_voltaic_blaze);
    RegisterSpellScript(spell_sha_voltaic_blaze_aura);
    RegisterSpellScript(spell_sha_voltaic_blaze_talent);
    RegisterSpellScript(spell_sha_windfury_weapon);
    RegisterSpellScript(spell_sha_windfury_weapon_proc);
    RegisterAreaTriggerAI(areatrigger_sha_arctic_snowstorm);
    RegisterAreaTriggerAI(areatrigger_sha_wind_rush_totem);
}
