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

// 45284 - Lightning Bolt Overload
// 45297 - Chain Lightning Overload
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

// 2645 - Ghost Wolf
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

//  12676 - AreaTriggerId
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
    RegisterSpellScript(spell_sha_chain_lightning_overload);
    RegisterSpellScript(spell_sha_earth_shock);
    RegisterAreaTriggerAI(areatrigger_sha_earthquake);
    RegisterSpellScript(spell_sha_earthquake);
    RegisterSpellScript(spell_sha_earthquake_tick);
    RegisterSpellAndAuraScriptPair(spell_sha_healing_rain, spell_sha_healing_rain_aura);
    RegisterSpellScript(spell_sha_healing_rain_target_limit);
    RegisterSpellScript(spell_sha_healing_stream_totem_heal);
    RegisterSpellScript(spell_sha_item_lightning_shield);
    RegisterSpellScript(spell_sha_item_lightning_shield_trigger);
    RegisterSpellScript(spell_sha_item_mana_surge);
    RegisterSpellScript(spell_sha_item_t6_trinket);
    RegisterSpellScript(spell_sha_item_t10_elemental_2p_bonus);
    RegisterSpellScript(spell_sha_lava_burst);
    RegisterSpellScript(spell_sha_lava_surge);
    RegisterSpellScript(spell_sha_lava_surge_proc);
    RegisterSpellScript(spell_sha_lightning_bolt_overload);
    RegisterSpellScript(spell_sha_mastery_elemental_overload_proc);
    RegisterSpellScript(spell_sha_natures_guardian);
    RegisterSpellScript(spell_sha_spirit_wolf);
    RegisterSpellScript(spell_sha_tidal_waves);
    RegisterSpellScript(spell_sha_t3_6p_bonus);
    RegisterSpellScript(spell_sha_t3_8p_bonus);
    RegisterSpellScript(spell_sha_t8_elemental_4p_bonus);
    RegisterSpellScript(spell_sha_t9_elemental_4p_bonus);
    RegisterSpellScript(spell_sha_t10_elemental_4p_bonus);
    RegisterSpellScript(spell_sha_t10_restoration_4p_bonus);
    RegisterSpellScript(spell_sha_windfury_weapon);
    RegisterAreaTriggerAI(areatrigger_sha_wind_rush_totem);
}
