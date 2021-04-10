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
 * Scripts for spells with SPELLFAMILY_DEMONHUNTER and SPELLFAMILY_GENERIC spells used by demon hunter players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dh_".
 */


#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "AreaTriggerTemplate.h"
#include "SpellPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Pet.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "Unit.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "Spell.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "PassiveAI.h"
#include "CombatAI.h"
#include "GridNotifiers.h"
#include <G3D/Vector3.h>

enum ProjectDemonHunterSpells
{
    SPELL_DH_FEL_RUSH_DASH = 197922,
    SPELL_DH_FEL_RUSH_AIR = 197923,
    SPELL_DH_FEL_RUSH = 195072,
    SPELL_DH_FEL_RUSH_DAMAGE = 223107,
    SPELL_DH_EYE_BEAM = 198013,
    SPELL_DH_EYE_BEAM_VISUAL = 194326,
    SPELL_DH_EYE_BEAM_DAMAGE = 198030,
    SPELL_DH_CHAOS_STRIKE_PROC = 193840,
    SPELL_DH_CHAOS_STRIKE_MAIN_HAND = 199547,
    SPELL_DH_CHAOS_STRIKE_OFF_HAND = 222031,
    SPELL_DH_CHARRED_FLESH = 336639,
    SPELL_DH_ANNIHILIATION_MAIN_HAND = 201428,
    SPELL_DH_ANNIHILIATION_OFF_HAND = 227518,
    SPELL_DH_FEL_ERUPTION = 211881,
    SPELL_DH_FEL_ERUPTION_DAMAGE = 225102,
    SPELL_DH_THROW_GLAIVE = 185123,
    SPELL_DH_LAST_RESORT_DEBUFF = 209261,
    SPELL_DH_METAMORPHOSIS_VENGEANCE = 187827,
    SPELL_DH_METAMORPHOSIS_HAVOC = 162264,
    SPELL_DH_METAMORPHOSIS_JUMP = 191428,
    SPELL_DH_METAMORPHOSIS_STUN = 200166,
    SPELL_DH_GLIDE_KNOCKBACK = 196353,
    SPELL_DH_GLIDE = 131347,
    SPELL_DH_FEL_MASTERY_FURY = 234244,
    SPELL_DH_FEL_MASTERY = 192939,
    SPELL_DH_PREPARED = 203551,
    SPELL_DH_PREPARED_FURY = 203650,
    SPELL_DH_DEMON_BLADES = 203796,
    SPELL_DH_FELBLADE = 232893,
    SPELL_DH_DEMONS_BITE = 162243,
    SPELL_DH_SHEAR = 203782,
    SPELL_DH_SHEAR_PROC = 203783,
    SPELL_DH_FIRST_BLOOD = 206416,
    SPELL_DH_BLOODLET_DOT = 207690,
    SPELL_DH_SOUL_RENDING_HAVOC = 204909,
    SPELL_DH_SOUL_RENDING_VENGEANCE = 217996,
    SPELL_DH_DEMONIC = 213410,
    SPELL_DH_DEMON_REBORN = 193897,
    SPELL_DH_BLUR = 198589,
    SPELL_DH_CHAOS_NOVA = 179057,
    SPELL_DH_FEL_BARRAGE = 211053,
    SPELL_DH_FEL_BARRAGE_TRIGGER = 211052,
    SPELL_DH_INFERNAL_STRIKE_JUMP = 189111,
    SPELL_DH_INFERNAL_STRIKE_DAMAGE = 189112,
    SPELL_DH_INFERNAL_STRIKE_VISUAL = 208461,
    SPELL_DH_INFERNAL_STRIKE = 189110,
    SPELL_DH_SOUL_CLEAVE_DAMAGE = 228478,
    SPELL_DH_FIERY_BRAND_DOT = 207771,
    SPELL_DH_FIERY_BRAND_MARKER = 207744,
    SPELL_DH_BURNING_ALIVE = 207739,
    SPELL_DH_RAZOR_SPIKES_SLOW = 210003,
    SPELL_DH_DEMON_SPIKES_BUFF = 203819,
    SPELL_DH_FEAST_OF_SOULS = 207697,
    SPELL_DH_FEAST_OF_SOULS_HEAL = 207693,
    SPELL_DH_SOUL_BARRIER = 263648,
    SPELL_DH_NETHER_BOND = 207810,
    SPELL_DH_NETHER_BOND_PERIODIC = 207811,
    SPELL_DH_NETHER_BOND_DAMAGE = 207812,
    SPELL_DH_SOLITUDE_BUFF = 211510,
    SPELL_DH_AWAKEN_THE_DEMON_CD = 207128,
    SPELL_DH_GLIMPSE = 203468,
    SPELL_DH_BLUR_BUFF = 212800,
    SPELL_DH_RUSHING_VAULT = 205601,
    SPELL_DH_EYE_OF_LEOTHERAS = 206649,
    SPELL_DH_EYE_OF_LEOTHERAS_DAMAGE = 206650,
    SPELL_DH_CLEANSED_BY_FLAME = 205625,
    SPELL_DH_CLEANSED_BY_FLAME_DISPEL = 208770,
    SPELL_DH_RAIN_OF_CHAOS = 205628,
    SPELL_DH_RAIN_OF_CHAOS_SLOW = 232538,
    SPELL_DH_JAGGED_SPIKES = 205627,
    SPELL_DH_JAGGED_SPIKES_DAMAGE = 208790,
    SPELL_DH_INTIMIDATED = 206891,
    SPELL_DH_TORMENTOR = 207029,
    SPELL_DH_DEMON_SPEED = 201469,
    SPELL_DH_DECEIVERS_FURY_ENERGIZE = 202120,
    SPELL_DH_ANGUISH_DAMAGE = 202446,
    SPELL_DH_SIGIL_OF_MISERY_TRIGGER = 207685,
    SPELL_DH_SIGIL_OF_MISERY_EXPLOSION = 208714,
    SPELL_DH_SIGIL_OF_FLAME_TRIGGER = 204598,
    SPELL_DH_SIGIL_OF_FLAME_EXPLOSION = 208710,
    SPELL_DH_SIGIL_OF_SILENCE_TRIGGER = 204490,
    SPELL_DH_SIGIL_OF_SILENCE_EXPLOSION = 208709,
    SPELL_DH_DARKNESS_ABSORB = 209426,
    SPELL_DH_BLIND_FURY = 203550,
    SPELL_DH_DEMONIC_APPETITE = 206478,
    SPELL_DH_CHAOS_CLEAVE_PROC = 236237,
    SPELL_DH_FALLOUT = 227174,
    SPELL_DH_FELBLADE_CHARGE = 213241,
    SPELL_DH_FELBLADE_DAMAGE = 213243,
    SPELL_DH_ABYSSAL_STRIKE = 207550,
    SPELL_DH_SIGIL_OF_FLAME_NO_DEST = 228973,
    SPELL_DH_FEED_THE_DEMON = 218612,
    SPELL_DH_DEMON_SPIKES = 203720,
    SPELL_DH_SIGIL_OF_CHAINS_EXPLOSION = 208673,
    SPELL_DH_SIGIL_OF_CHAINS_TRIGGER = 208674,
    SPELL_DH_SIGIL_OF_CHAINS_SLOW = 204843,
    SPELL_DH_FEL_DEVASTATION_DAMAGE = 212105,
    SPELL_DH_FEL_DEVASTATION_HEAL = 212106,
    SPELL_DH_FRAILTY = 224509,
    SPELL_DH_FRAILTY_HEAL = 227255,
    SPELL_DH_SPIRIT_BOMB_DAMAGE = 218677,
    SPELL_DH_FURY_OF_THE_ILLIDARI_MAINHAND = 201628,
    SPELL_DH_FURY_OF_THE_ILLIDARI_OFFHAND = 201789,
    SPELL_DH_INNER_DEMONS_DAMAGE = 202388,
    SPELL_DH_BALANCED_BLADES = 201470,
    SPELL_DH_RAGE_OF_THE_ILLIDARI_VISUAL = 226948,
    SPELL_DH_RAGE_OF_THE_ILLIDARI_DAMAGE = 217070,
    SPELL_DH_OVERWHELMING_POWER = 201464,
    SPELL_DK_RAIN_FROM_ABOVE_SLOWFALL = 206804,
    SPELL_DH_DEMONIC_ORIGINS_BUFF = 235894,
    SPELL_DH_DEMONIC_ORIGINS = 235893,
    SPELL_DH_MANA_RIFT_SPELL = 235903,
    SPELL_DH_MANA_RIFT_DAMAGE = 235904,
    SPELL_DH_DEMONIC_TRAMPLE_DAMAGE = 208645,
    SPELL_DH_DEMONIC_TRAMPLE_STUN = 213491,
    SPELL_DH_DEMON_BLADES_AURA = 203555,
    SPELL_DH_REWARD_PAIN = 187724,
    SPELL_DH_FEAST_ON_THE_SOULS = 201468,
    SPELL_DH_MANA_BREAK = 203704,
    SPELL_DH_BLADE_DANCE = 188499,
    SPELL_DH_TRAIL_OF_RUIN_TALENT = 258881,
};

enum ShatteredSoulsSpells
{
    SPELL_DH_SHATTERED_SOULS = 204255,
    SPELL_DH_SHATTERED_SOULS_DEMON = 204256,
    SPELL_DH_LESSER_SOUL_SHARD = 203795,
    SPELL_DH_LESSER_SOUL_SHARD_HEAL = 203794,
    SPELL_DH_SHATTERED_SOULS_MISSILE = 209651,
    SPELL_DH_SOUL_FRAGMENT_HEAL_25_HAVOC = 178963,
    SPELL_DH_SOUL_FRAGMENT_DEMON_BONUS = 163073,
    SPELL_DH_SOUL_FRAGMENT_HEAL_VENGEANCE = 210042,
    SPELL_DH_CONSUME_SOUL_MISSILE = 210047,
    SPELL_DH_LESSER_SOUL_FRAGMENT_HAVOC = 228532,
    SPELL_DH_PAINBRINGER = 207387,
    SPELL_DH_PAINBRINGER_BUFF = 212988,
    SPELL_DH_DEVOUR_SOULS = 212821,
    SPELL_DH_CHARRED_WARBLADES_HEAL = 213011,
    SPELL_DH_SHATTER_THE_SOULS = 212827,
    SPELL_DH_FIERY_DEMISE_DEBUFF = 212818,
    SPELL_DH_COVER_OF_DARKNESS = 227635,
    //8.0
    SPELL_DH_SHATTERED_SOULS_HAVOC = 178940,
    SPELL_DH_SHATTERED_SOULS_VENGEANCE = 204254,
    SPELL_DH_MOMENTUM = 206476,
    SPELL_DH_MOMENTUM_BUFF = 208628,
    SPELL_DH_SHATTERED_SOULS_SHEAR_1 = 226258,
    SPELL_DH_SHATTERED_SOULS_SHEAR_2 = 226259,
};

enum NemesisSpells
{
    NEMESIS_ABERRATION = 208607,
    NEMESIS_ELEMENTAL = 208611,
    NEMESIS_MECHANICAL = 208616,
    NEMESIS_DRAGONKIN = 208610,
    NEMESIS_HUMANOID = 208605,
    NEMESIS_CRITTERS = 208609,
    NEMESIS_DEMONS = 208579,
    NEMESIS_GIANTS = 208612,
    NEMESIS_UNDEAD = 208614,
    NEMESIS_BEASTS = 208608
};

// Bloodlet - 206473
class spell_dh_bloodlet : public SpellScriptLoader
{
public:
    spell_dh_bloodlet() : SpellScriptLoader("spell_dh_bloodlet") {}

    class spell_dh_bloodlet_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_bloodlet_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetSpellInfo()->Id == SPELL_DH_THROW_GLAIVE)
                return true;
            return false;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            Unit* target = eventInfo.GetActionTarget();
            if (!caster || !target || !eventInfo.GetDamageInfo() || !GetSpellInfo()->GetEffect(EFFECT_0))
                return;

            int32 basePoints = GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints;
            int32 dmg = (eventInfo.GetDamageInfo()->GetDamage() * (float)basePoints) / 100.f;
            float dmgPerTick = (float)dmg / 5.f;

            // Any remaining damage must be added
            if (AuraEffect* dot = target->GetAuraEffect(SPELL_DH_BLOODLET_DOT, EFFECT_0, caster->GetGUID()))
            {
                dmgPerTick += (dot->GetAmount() * (dot->GetTotalTicks() - dot->GetTickNumber())) / 5;
            }

            caster->CastCustomSpell(target, SPELL_DH_BLOODLET_DOT, &dmgPerTick, nullptr, nullptr, true);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dh_bloodlet_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dh_bloodlet_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_bloodlet_AuraScript();
    }
};

// 188499 - Blade Dance main
class spell_demon_hunter_blade_dance_main : public SpellScriptLoader
{
public:
    spell_demon_hunter_blade_dance_main() : SpellScriptLoader("spell_demon_hunter_blade_dance_main") { }

    class spell_demon_hunter_blade_dance_main_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_demon_hunter_blade_dance_main_SpellScript);

        void HandleCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (Unit* target = caster->SelectNearbyTarget(nullptr, 8.f))
                caster->Variables.Set("Spells.BladeDanceMainTarget", target->GetGUID());
        }

        void Register()
        {
            OnCast += SpellCastFn(spell_demon_hunter_blade_dance_main_SpellScript::HandleCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_demon_hunter_blade_dance_main_SpellScript();
    }
};

// First Blood - 206416
// Called by Blade Dance damage dealers - 199552, 200685, 210153, 210155
class spell_dh_first_blood : public SpellScriptLoader
{
public:
    spell_dh_first_blood() : SpellScriptLoader("spell_dh_first_blood") {}

    class spell_dh_first_blood_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_first_blood_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            int32 hitDamage = GetHitDamage();
            if (int32 bonus = caster->GetAuraEffectAmount(SPELL_DH_BALANCED_BLADES, true))
            {
                int32 addPct = 0;
                std::list<Unit*> units;
                caster->GetAttackableUnitListInRange(units, 8.f);
                for (Unit* unit : units)
                    if (caster->IsValidAttackTarget(unit))
                        addPct += bonus;

                AddPct(hitDamage, addPct);
            }

            if (uint32 bonusDamage = caster->GetAuraEffectAmount(SPELL_DH_FIRST_BLOOD, EFFECT_0))
            {
                ObjectGuid guid = caster->Variables.GetValue<ObjectGuid>("Spells.BladeDanceMainTarget", ObjectGuid::Empty);

                if (!guid.IsEmpty())
                    if (target->GetGUID() == guid)
                        AddPct(hitDamage, bonusDamage);
            }

            SetHitDamage(hitDamage);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_first_blood_SpellScript::HandleHit, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_first_blood_SpellScript();
    }
};

// Vengeful Retread Damage - 198813
class spell_dh_vengeful_retreat_damage : public SpellScriptLoader
{
public:
    spell_dh_vengeful_retreat_damage() : SpellScriptLoader("spell_dh_vengeful_retreat_damage") {}

    class spell_dh_vengeful_retreat_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_vengeful_retreat_damage_SpellScript);

        bool targetHit;

        bool Validate(SpellInfo const*) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_PREPARED_FURY))
                return false;

            return true;
        }

        void CountTargets(std::list<WorldObject*>& targets)
        {
            targetHit = !targets.empty();
        }

        void HandleCast()
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->HasAura(SPELL_DH_PREPARED) && targetHit)
                    caster->CastSpell(caster, SPELL_DH_PREPARED_FURY, true);

                if (Aura* aur = caster->GetAura(SPELL_DH_GLIMPSE))
                    if (AuraEffect* aurEff = aur->GetEffect(EFFECT_0))
                        if (Aura* blur = caster->AddAura(SPELL_DH_BLUR_BUFF, caster))
                            blur->SetDuration(aurEff->GetBaseAmount());

                if (caster->HasAura(SPELL_DH_RUSHING_VAULT))
                {
                    int32 chargeCatId = sSpellMgr->GetSpellInfo(SPELL_DH_FEL_RUSH)->ChargeCategoryId;
                    caster->GetSpellHistory()->RestoreCharge(chargeCatId);
                    caster->GetSpellHistory()->ForceSendSpellCharges();
                }
            }
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_dh_vengeful_retreat_damage_SpellScript::HandleCast);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dh_vengeful_retreat_damage_SpellScript::CountTargets, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_vengeful_retreat_damage_SpellScript();
    }
};

// Fel Rush Damage - 223107
class spell_dh_fel_rush_damage : public SpellScript
{
    PrepareSpellScript(spell_dh_fel_rush_damage);

    bool targetHit;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetCaster());
    }

    void CountTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        targets.clear();
        std::list<Unit*> units;
        caster->GetAttackableUnitListInRange(units, 25.f);
        units.remove_if([caster](Unit* unit)
            {
                return !caster->HasInLine(unit, 6.f, caster->GetObjectScale());
            });

        for (Unit* unit : units)
            targets.push_back(unit);

        targetHit = !targets.empty();
    }

    void HandleCast()
    {
        if (Unit* caster = GetCaster())
            if (caster->HasAura(SPELL_DH_FEL_MASTERY) && targetHit)
                caster->CastSpell(caster, SPELL_DH_FEL_MASTERY_FURY, true);
    }

    void HandleOnHit()
    {
        if (GetCaster() && GetHitUnit())
        {
            int32 attackPower = GetCaster()->m_unitData->AttackPower / 100 * 25.3f;
            SetHitDamage(attackPower);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dh_fel_rush_damage::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENTRY_129);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dh_fel_rush_damage::CountTargets, EFFECT_0, TARGET_UNIT_CONE_ENTRY_129);
        OnCast += SpellCastFn(spell_dh_fel_rush_damage::HandleCast);
        OnHit += SpellHitFn(spell_dh_fel_rush_damage::HandleOnHit);
    }
};

// Metamorphosis (Havoc) - 191427
class spell_dh_metamorphosis : public SpellScriptLoader
{
public:
    spell_dh_metamorphosis() : SpellScriptLoader("spell_dh_metamorphosis") {}

    class spell_dh_metamorphosis_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_metamorphosis_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_METAMORPHOSIS_HAVOC, DIFFICULTY_NONE) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_METAMORPHOSIS_JUMP, DIFFICULTY_NONE) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_METAMORPHOSIS_STUN, DIFFICULTY_NONE))
                return false;
            return true;
        }

        void HandleDummy()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            Player* player = caster->ToPlayer();
            if (!player)
                return;

            if (const WorldLocation* dest = GetExplTargetDest())
                player->CastSpell(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), SPELL_DH_METAMORPHOSIS_JUMP, true);

            if (player->HasAura(SPELL_DH_DEMON_REBORN)) // Remove CD of Eye Beam, Chaos Nova and Blur
            {
                player->GetSpellHistory()->ResetCooldown(SPELL_DH_CHAOS_NOVA, true);
                player->GetSpellHistory()->ResetCooldown(SPELL_DH_BLUR, true);
                player->GetSpellHistory()->AddCooldown(SPELL_DH_BLUR_BUFF, 0, std::chrono::minutes(1));
                player->GetSpellHistory()->ResetCooldown(SPELL_DH_BLUR_BUFF, true);
                player->GetSpellHistory()->ResetCooldown(SPELL_DH_EYE_BEAM, true);
            }
        }

        void Register() override
        {
            BeforeCast += SpellCastFn(spell_dh_metamorphosis_SpellScript::HandleDummy);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_metamorphosis_SpellScript();
    }
};

// Metamorphosis temporary immunity - 201453
class spell_dh_metamorphosis_immunity : public SpellScriptLoader
{
public:
    spell_dh_metamorphosis_immunity() : SpellScriptLoader("spell_dh_metamorphosis_immunity") {}

    class spell_dh_metamorphosis_immunity_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_metamorphosis_immunity_AuraScript);

        void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            //caster->CastSpell(caster, SPELL_DH_METAMORPHOSIS_STUN, true);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_dh_metamorphosis_immunity_AuraScript::HandleRemove, EFFECT_1, SPELL_AURA_DISABLE_CASTING_EXCEPT_ABILITIES, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_metamorphosis_immunity_AuraScript();
    }
};

// Fel Rush air - 197923
class spell_dh_fel_rush_dash : public SpellScriptLoader
{
public:
    spell_dh_fel_rush_dash() : SpellScriptLoader("spell_dh_fel_rush_dash") {}

    class spell_dh_fel_rush_dash_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_fel_rush_dash_AuraScript);

        void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                caster->GetScheduler().Schedule(100ms, [caster](TaskContext /*context*/)
                    {
                        if (!caster->HasAura(SPELL_DH_FEL_RUSH_AIR))
                            caster->SetDisableGravity(false);
                    });
        }

        void CalcSpeed(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = 1250;
            RefreshDuration();
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_fel_rush_dash_AuraScript::CalcSpeed, EFFECT_1, 373);
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_fel_rush_dash_AuraScript::CalcSpeed, EFFECT_3, SPELL_AURA_MOD_MINIMUM_SPEED);
            AfterEffectRemove += AuraEffectRemoveFn(spell_dh_fel_rush_dash_AuraScript::AfterRemove, EFFECT_9, SPELL_AURA_MOD_MINIMUM_SPEED_RATE, AURA_EFFECT_HANDLE_SEND_FOR_CLIENT_MASK);
        }
    };

    class spell_dh_fel_rush_dash_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_fel_rush_dash_SpellScript);

        void PreventTrigger(SpellEffIndex effIndex)
        {
            PreventHitEffect(effIndex);
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_dh_fel_rush_dash_SpellScript::PreventTrigger, EFFECT_6, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectHit += SpellEffectFn(spell_dh_fel_rush_dash_SpellScript::PreventTrigger, EFFECT_6, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_fel_rush_dash_AuraScript();
    }

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_fel_rush_dash_SpellScript();
    }
};

// Fel Rush air - 197922
class spell_dh_fel_rush_dash_ground : public SpellScriptLoader
{
public:
    spell_dh_fel_rush_dash_ground() : SpellScriptLoader("spell_dh_fel_rush_dash_ground") {}

    class spell_dh_fel_rush_dash_ground_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_fel_rush_dash_ground_AuraScript);

        void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                caster->SetDisableGravity(false);
            }
        }

        void CalcSpeed(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = 1250;
            RefreshDuration();
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_fel_rush_dash_ground_AuraScript::CalcSpeed, EFFECT_1, 373);
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_fel_rush_dash_ground_AuraScript::CalcSpeed, EFFECT_3, SPELL_AURA_MOD_MINIMUM_SPEED);
            AfterEffectRemove += AuraEffectRemoveFn(spell_dh_fel_rush_dash_ground_AuraScript::AfterRemove, EFFECT_6, SPELL_AURA_MOD_MINIMUM_SPEED_RATE, AURA_EFFECT_HANDLE_SEND_FOR_CLIENT_MASK);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_fel_rush_dash_ground_AuraScript();
    }
};

// Fel Rush - 195072
class spell_dh_fel_rush : public SpellScriptLoader
{
public:
    spell_dh_fel_rush() : SpellScriptLoader("spell_dh_fel_rush") {}

    class spell_dh_fel_rush_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_fel_rush_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_FEL_RUSH_DASH, DIFFICULTY_NONE))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_FEL_RUSH_AIR, DIFFICULTY_NONE))
                return false;
            return true;
        }

        void HandleDashGround(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster->IsFalling() || caster->IsInWater())
                {
                    caster->RemoveAurasDueToSpell(SPELL_DH_GLIDE);
                    caster->CastSpell(caster, SPELL_DH_FEL_RUSH_DASH, true);
                    if (GetHitUnit())
                        caster->CastSpell(GetHitUnit(), SPELL_DH_FEL_RUSH_DAMAGE, true);
                    if (caster->HasAura(SPELL_DH_MOMENTUM))
                        caster->CastSpell(nullptr, SPELL_DH_MOMENTUM_BUFF, true);
                }
                caster->GetSpellHistory()->AddCooldown(GetSpellInfo()->Id, 0, std::chrono::milliseconds(750));
            }
        }

        void HandleDashAir(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->IsFalling())
                {
                    caster->RemoveAurasDueToSpell(SPELL_DH_GLIDE);
                    caster->SetDisableGravity(true);
                    caster->CastSpell(caster, SPELL_DH_FEL_RUSH_AIR, true);
                    if (GetHitUnit())
                        caster->CastSpell(GetHitUnit(), SPELL_DH_FEL_RUSH_DAMAGE, true);
                    if (caster->HasAura(SPELL_DH_MOMENTUM))
                        caster->CastSpell(nullptr, SPELL_DH_MOMENTUM_BUFF, true);

                    caster->GetSpellHistory()->AddCooldown(GetSpellInfo()->Id, 0, std::chrono::milliseconds(750));
                }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_fel_rush_SpellScript::HandleDashGround, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnEffectHitTarget += SpellEffectFn(spell_dh_fel_rush_SpellScript::HandleDashAir, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_fel_rush_SpellScript();
    }
};

// Eye Beam - 198013
class spell_dh_eye_beam : public SpellScriptLoader
{
public:
    spell_dh_eye_beam() : SpellScriptLoader("spell_dh_eye_beam") {}

    class spell_dh_eye_beam_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_eye_beam_AuraScript);

        bool firstTick = true;

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_EYE_BEAM, DIFFICULTY_NONE) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_EYE_BEAM_DAMAGE, DIFFICULTY_NONE))
                return false;
            return true;
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (!firstTick)
                {
                    caster->CastSpell(caster, SPELL_DH_EYE_BEAM_DAMAGE, true);
                    if (int32 energize = caster->GetAuraEffectAmount(SPELL_DH_BLIND_FURY, EFFECT_2))
                        caster->ModifyPower(POWER_FURY, energize * 2.f / 50.f);
                }
            }

            firstTick = false;
        }

        void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                caster->RemoveAurasDueToSpell(SPELL_DH_EYE_BEAM_VISUAL);
        }

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster->HasAura(SPELL_DH_DEMONIC))
                    caster->CastSpell(caster, SPELL_DH_EYE_BEAM_VISUAL, true);

                if (caster->HasAura(SPELL_DH_DEMONIC))
                {
                    if (Aura* aur = caster->GetAura(SPELL_DH_METAMORPHOSIS_HAVOC))
                        aur->ModDuration(8 * IN_MILLISECONDS);
                    else if (Aura* aur = caster->AddAura(SPELL_DH_METAMORPHOSIS_HAVOC, caster))
                        aur->SetDuration(10 * IN_MILLISECONDS);
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_eye_beam_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            OnEffectRemove += AuraEffectRemoveFn(spell_dh_eye_beam_AuraScript::HandleRemove, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectApply += AuraEffectApplyFn(spell_dh_eye_beam_AuraScript::HandleApply, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_eye_beam_AuraScript();
    }
};

// 198030 - Eye Beam damage
class spell_demon_hunter_eye_beam_damage : public SpellScriptLoader
{
public:
    spell_demon_hunter_eye_beam_damage() : SpellScriptLoader("spell_demon_hunter_eye_beam_damage") { }

    class spell_demon_hunter_eye_beam_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_demon_hunter_eye_beam_damage_SpellScript);

        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            unitList.clear();
            std::list<Unit*>  units;
            caster->GetAttackableUnitListInRange(units, 25.f);
            units.remove_if([caster](Unit* unit)
                {
                    return !caster->HasInLine(unit, 5.f, caster->GetObjectScale());
                });

            for (Unit* unit : units)
                unitList.push_back(unit);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_demon_hunter_eye_beam_damage_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENTRY_129);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_demon_hunter_eye_beam_damage_SpellScript();
    }
};

// 197125 - Chaos Strike
class spell_dh_chaos_strike : public SpellScriptLoader
{
public:
    spell_dh_chaos_strike() : SpellScriptLoader("spell_dh_chaos_strike") { }

    class spell_dh_chaos_strike_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_chaos_strike_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_CHAOS_STRIKE_PROC, DIFFICULTY_NONE))
                return false;
            return true;
        }

        void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();

            if (Unit* caster = GetCaster())
                if (Player* player = caster->ToPlayer())
                    player->CastSpell(player, SPELL_DH_CHAOS_STRIKE_PROC, true);
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (!eventInfo.GetSpellInfo())
                return false;
            if ((eventInfo.GetSpellInfo()->Id == SPELL_DH_CHAOS_STRIKE_MAIN_HAND ||
                eventInfo.GetSpellInfo()->Id == SPELL_DH_ANNIHILIATION_MAIN_HAND))
                return true;
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dh_chaos_strike_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dh_chaos_strike_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_chaos_strike_AuraScript();
    }
};

// 131347 - Glide
class spell_dh_glide : public SpellScriptLoader
{
public:
    spell_dh_glide() : SpellScriptLoader("spell_dh_glide") { }

    class spell_dh_glide_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_glide_SpellScript);

        SpellCastResult CheckCast()
        {
            if (!GetCaster())
                return SPELL_FAILED_DONT_REPORT;

            if (!GetCaster()->IsFalling())
                return SPELL_FAILED_NOT_ON_GROUND;

            return SPELL_CAST_OK;
        }

        void HandleKnockback()
        {
            if (Unit* caster = GetCaster())
            {
                caster->RemoveAurasByType(SPELL_AURA_MOUNTED);
                caster->CastSpell(caster, SPELL_DH_GLIDE_KNOCKBACK, true);
                caster->GetScheduler().Schedule(1s, [caster](TaskContext /*context*/)
                    {
                        if (!caster->HasAura(SPELL_DH_GLIDE))
                        {
                            caster->AddUnitMovementFlag(MOVEMENTFLAG_FALLING_SLOW);
                            caster->SetFeatherFall(false);
                            if (Player* player = caster->ToPlayer())
                                player->SetFallInformation(0, player->GetPositionZ());
                        }
                    });
            }
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_dh_glide_SpellScript::CheckCast);
            OnCast += SpellCastFn(spell_dh_glide_SpellScript::HandleKnockback);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_glide_SpellScript();
    }
};

// Master of the Glaive - 203556
class spell_dh_master_of_the_glaive : public SpellScriptLoader
{
public:
    spell_dh_master_of_the_glaive() : SpellScriptLoader("spell_dh_master_of_the_glaive") {}

    class spell_dh_master_of_the_glaive_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_master_of_the_glaive_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetSpellInfo()->Id == SPELL_DH_THROW_GLAIVE)
                return true;
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dh_master_of_the_glaive_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_master_of_the_glaive_AuraScript();
    }
};

// Fel Eruption - 211881
class spell_dh_fel_eruption : public SpellScriptLoader
{
public:
    spell_dh_fel_eruption() : SpellScriptLoader("spell_dh_fel_eruption") {}

    class spell_dh_fel_eruption_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_fel_eruption_SpellScript);

        void HandleOnHit()
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();
            if (!caster || !target)
                return;
            caster->CastCustomSpell(SPELL_DH_FEL_ERUPTION_DAMAGE, SPELLVALUE_BASE_POINT1, 1, target, true);
        }

        void HandleHit(SpellMissInfo missInfo)
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();
            if (!caster || !target)
                return;

            if (missInfo == SPELL_MISS_IMMUNE || missInfo == SPELL_MISS_IMMUNE2)
                caster->CastCustomSpell(SPELL_DH_FEL_ERUPTION_DAMAGE, SPELLVALUE_BASE_POINT1, 2, target, true);
        }

        void Register() override
        {
            BeforeHit += BeforeSpellHitFn(spell_dh_fel_eruption_SpellScript::HandleHit);
            OnHit += SpellHitFn(spell_dh_fel_eruption_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_fel_eruption_SpellScript();
    }
};

// Last resort - 209258
class spell_dh_last_resort : public SpellScriptLoader
{
public:
    spell_dh_last_resort() : SpellScriptLoader("spell_dh_last_resort") {}

    class spell_dh_last_resort_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_last_resort_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_LAST_RESORT_DEBUFF, DIFFICULTY_NONE))
                return false;
            return true;
        }

        void CalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void HandleAbsorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            Unit* target = GetTarget();
            if (!target)
                return;

            if (dmgInfo.GetDamage() < target->GetHealth())
                return;

            if (target->HasAura(SPELL_DH_LAST_RESORT_DEBUFF))
                return;

            int32 healthPct = GetSpellInfo()->GetEffect(EFFECT_1) ? GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints : 0;
            target->SetHealth(1);
            HealInfo healInfo = HealInfo(target, target, target->CountPctFromMaxHealth(healthPct), GetSpellInfo(), (SpellSchoolMask)GetSpellInfo()->SchoolMask);
            target->HealBySpell(healInfo);
            // We use AddAura instead of CastSpell, since if the spell is on cooldown, it will not be casted
            target->AddAura(SPELL_DH_METAMORPHOSIS_VENGEANCE, target);
            target->CastSpell(target, SPELL_DH_LAST_RESORT_DEBUFF, true);

            absorbAmount = dmgInfo.GetDamage();
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_last_resort_AuraScript::CalcAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_dh_last_resort_AuraScript::HandleAbsorb, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_last_resort_AuraScript();
    }
};

// Fel Barrage - 211053
class spell_dh_fel_barrage : public SpellScriptLoader
{
public:
    spell_dh_fel_barrage() : SpellScriptLoader("spell_dh_fel_barrage") {}

    class spell_dh_fel_barrage_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_fel_barrage_AuraScript);

        int32 _charges = 1;

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_FEL_BARRAGE, DIFFICULTY_NONE) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_FEL_BARRAGE_TRIGGER, DIFFICULTY_NONE))
                return false;
            return true;
        }

        bool Load() override
        {
            Unit* caster = GetCaster();
            if (!caster || !GetSpellInfo())
                return false;

            uint32 chargeCategoryId = GetSpellInfo()->ChargeCategoryId;
            while (caster->GetSpellHistory()->HasCharge(chargeCategoryId))
            {
                caster->GetSpellHistory()->ConsumeCharge(chargeCategoryId);
                caster->GetSpellHistory()->ForceSendSpellCharges();
                _charges++;
            }
            return true;
        }

        void HandleTrigger(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            caster->CastCustomSpell(target, SPELL_DH_FEL_BARRAGE_TRIGGER, &_charges, nullptr, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_fel_barrage_AuraScript::HandleTrigger, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_fel_barrage_AuraScript();
    }
};

// Fel Barrage Damage - 211052
class spell_dh_fel_barrage_damage : public SpellScriptLoader
{
public:
    spell_dh_fel_barrage_damage() : SpellScriptLoader("spell_dh_fel_barrage_damage") {}

    class spell_dh_fel_barrage_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_fel_barrage_damage_SpellScript);

        void HandleHit()
        {
            int32 chargesUsed = GetSpellValue()->EffectBasePoints[0];
            int32 dmg = GetHitDamage();
            SetHitDamage((float)(dmg * chargesUsed) / 5.f);
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_dh_fel_barrage_damage_SpellScript::HandleHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_fel_barrage_damage_SpellScript();
    }
};

// Fel Barrage aura - 222703
class spell_dh_fel_barrage_aura : public SpellScriptLoader
{
public:
    spell_dh_fel_barrage_aura() : SpellScriptLoader("spell_dh_fel_barrage_aura") {}

    class spell_dh_fel_barrage_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_fel_barrage_aura_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            // Blade Dance, Chaos Strike and Annihilation have many damagers,
            // so we accept only 1 of those, and we remove the others
            // Also we remove fel barrage itself too.
            if (!eventInfo.GetSpellInfo())
                return false;

            //Blade Dance    //Chaos Strike   //Fel Barrage
            std::vector<uint32> removeSpellIds{ 199552, 210153,  222031, 227518,      211052 };
            return std::find(removeSpellIds.begin(), removeSpellIds.end(), eventInfo.GetSpellInfo()->Id) == removeSpellIds.end();
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();

            Unit* caster = GetCaster();
            if (!caster)
                return;

            int32 chargeCatId = sSpellMgr->GetSpellInfo(SPELL_DH_FEL_BARRAGE, DIFFICULTY_NONE)->ChargeCategoryId;
            if (SpellCategoryEntry const* barrage = sSpellCategoryStore.LookupEntry(chargeCatId))
            {
                caster->GetSpellHistory()->RestoreCharge(chargeCatId);
                caster->GetSpellHistory()->ForceSendSpellCharge(barrage);
            }
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dh_fel_barrage_aura_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dh_fel_barrage_aura_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_fel_barrage_aura_AuraScript();
    }
};

// Nemesis - 206491
class spell_dh_nemesis : public SpellScriptLoader
{
public:
    spell_dh_nemesis() : SpellScriptLoader("spell_dh_nemesis") {}

    class spell_dh_nemesis_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_nemesis_AuraScript);

        void HandleAfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (!GetTargetApplication())
                return;
            if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
                return;

            Unit* target = GetTargetApplication()->GetTarget();
            uint32 type = target->GetCreatureType();
            int32 dur = GetTargetApplication()->GetBase()->GetDuration();
            Unit* caster = GetAura()->GetCaster();

            if (!caster || !target)
                return;

            int32 spellId = 0;

            switch (type)
            {
            case CREATURE_TYPE_ABERRATION:
                spellId = NEMESIS_ABERRATION;
                break;
            case CREATURE_TYPE_BEAST:
                spellId = NEMESIS_BEASTS;
                break;
            case CREATURE_TYPE_CRITTER:
                spellId = NEMESIS_CRITTERS;
                break;
            case CREATURE_TYPE_DEMON:
                spellId = NEMESIS_DEMONS;
                break;
            case CREATURE_TYPE_DRAGONKIN:
                spellId = NEMESIS_DRAGONKIN;
                break;
            case CREATURE_TYPE_ELEMENTAL:
                spellId = NEMESIS_ELEMENTAL;
                break;
            case CREATURE_TYPE_GIANT:
                spellId = NEMESIS_GIANTS;
                break;
            case CREATURE_TYPE_HUMANOID:
                spellId = NEMESIS_HUMANOID;
                break;
            case CREATURE_TYPE_MECHANICAL:
                spellId = NEMESIS_MECHANICAL;
                break;
            case CREATURE_TYPE_UNDEAD:
                spellId = NEMESIS_UNDEAD;
                break;
            default:
                break;
            }

            if (spellId)
                if (Aura* aur = caster->AddAura(spellId, caster))
                    aur->SetDuration(dur);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_dh_nemesis_AuraScript::HandleAfterRemove, EFFECT_0, SPELL_AURA_MOD_SCHOOL_MASK_DAMAGE_FROM_CASTER, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_nemesis_AuraScript();
    }
};

class event_dh_infernal_strike : public BasicEvent
{
public:
    event_dh_infernal_strike(Unit* caster) : _caster(caster) {}

    bool Execute(uint64 /*execTime*/, uint32 /*diff*/)
    {
        if (_caster)
        {
            _caster->CastSpell(_caster, SPELL_DH_INFERNAL_STRIKE_DAMAGE, true);

            if (_caster->HasAura(SPELL_DH_RAIN_OF_CHAOS))
                _caster->CastSpell(_caster, SPELL_DH_RAIN_OF_CHAOS_SLOW, true);

            if (_caster->HasAura(SPELL_DH_ABYSSAL_STRIKE))
                _caster->CastSpell(_caster, SPELL_DH_SIGIL_OF_FLAME_NO_DEST, true);
        }

        return true;
    }

private:
    Unit* _caster;
};

// Infernal Strike - 189110
// 189110 - Infernal Strike
class spell_dh_infernal_strike : public SpellScript
{
    PrepareSpellScript(spell_dh_infernal_strike);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({
            SPELL_DH_INFERNAL_STRIKE_JUMP,
            SPELL_DH_INFERNAL_STRIKE_DAMAGE
            });
    }

    void HandleOnHit()
    {
        Unit* caster = GetCaster();
        WorldLocation const* dest = GetHitDest();
        Unit* target = GetHitUnit();
        if (!caster || !dest || !target)
            return;

        if (target->IsHostileTo(caster))
        {
            caster->CastSpell(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), SPELL_DH_INFERNAL_STRIKE_JUMP, true);
            caster->CastSpell(caster, SPELL_DH_INFERNAL_STRIKE_VISUAL, true);
        }
    }

    void HandleOnCast()
    {
        if (Unit* caster = GetCaster())
            caster->m_Events.AddEvent(new event_dh_infernal_strike(caster), caster->m_Events.CalculateTime(750));
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_dh_infernal_strike::HandleOnHit);
        OnCast += SpellCastFn(spell_dh_infernal_strike::HandleOnCast);
    }
};

// Soul Cleave - 228477
class spell_dh_soul_cleave : public SpellScriptLoader
{
public:
    spell_dh_soul_cleave() : SpellScriptLoader("spell_dh_soul_cleave") {}

    class spell_dh_soul_cleave_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_soul_cleave_SpellScript);

        void HandleHeal(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->GetTypeId() != TYPEID_PLAYER)
                return;

            if (caster->HasAura(SPELL_DH_FEAST_OF_SOULS))
                caster->CastSpell(caster, SPELL_DH_FEAST_OF_SOULS_HEAL, true);
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            // Consume all soul fragments in 25 yards;
            std::vector<std::vector<AreaTrigger*>> fragments;
            fragments.push_back(caster->GetAreaTriggers(SPELL_DH_SHATTERED_SOULS));
            fragments.push_back(caster->GetAreaTriggers(SPELL_DH_SHATTERED_SOULS_DEMON));
            fragments.push_back(caster->GetAreaTriggers(SPELL_DH_LESSER_SOUL_SHARD));
            int32 range = GetEffectInfo()->BasePoints;

            for (std::vector<AreaTrigger*> vec : fragments)
            {
                for (AreaTrigger* at : vec)
                {
                    if (!caster->IsWithinDist(at, range))
                        continue;

                    if (TempSummon* tempSumm = caster->SummonCreature(WORLD_TRIGGER, at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 100))
                    {
                        tempSumm->SetFaction(caster->GetFaction());
                        tempSumm->SetSummonerGUID(caster->GetGUID());
                        int32 bp = 0;
                        switch (at->GetTemplate()->Id)
                        {
                        case 6007:
                        case 5997:
                            bp = SPELL_DH_SOUL_FRAGMENT_HEAL_VENGEANCE;
                            break;
                        case 6710:
                            bp = SPELL_DH_LESSER_SOUL_SHARD_HEAL;
                            break;
                        }
                        caster->CastCustomSpell(SPELL_DH_CONSUME_SOUL_MISSILE, SPELLVALUE_BASE_POINT0, bp, tempSumm, true);
                        if (at->GetTemplate()->Id == 6007)
                            caster->CastSpell(caster, SPELL_DH_SOUL_FRAGMENT_DEMON_BONUS, true);

                        if (caster->HasAura(SPELL_DH_FEED_THE_DEMON))
                            caster->GetSpellHistory()->ReduceChargeCooldown(sSpellMgr->GetSpellInfo(SPELL_DH_DEMON_SPIKES, DIFFICULTY_NONE)->ChargeCategoryId, 1000);

                        if (caster->HasAura(SPELL_DH_PAINBRINGER))
                            caster->CastSpell(caster, SPELL_DH_PAINBRINGER_BUFF, true);

                        if (AuraEffect* soulBarrier = caster->GetAuraEffect(SPELL_DH_SOUL_BARRIER, EFFECT_0))
                        {
                            int32 amount = soulBarrier->GetAmount() + (float(sSpellMgr->GetSpellInfo(SPELL_DH_SOUL_BARRIER, DIFFICULTY_NONE)->GetEffect(EFFECT_1)->BasePoints) / 100.f) * caster->GetTotalAttackPowerValue(BASE_ATTACK);
                            soulBarrier->SetAmount(amount);
                        }

                        at->SetDuration(0);
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_soul_cleave_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnEffectHitTarget += SpellEffectFn(spell_dh_soul_cleave_SpellScript::HandleHeal, EFFECT_3, SPELL_EFFECT_HEAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_soul_cleave_SpellScript();
    }
};

// Soul cleave damage - 228478
class spell_dh_soul_cleave_damage : public SpellScript
{
    PrepareSpellScript(spell_dh_soul_cleave_damage);

    void HandleOnHit()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        float dmg = GetHitDamage() * 2;
        dmg *= caster->Variables.GetValue<float>("lastSoulCleaveMod");
        SetHitDamage(dmg);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_dh_soul_cleave_damage::HandleOnHit);
    }
};

// Fiery Brand - 204021
class spell_dh_fiery_brand : public SpellScript
{
    PrepareSpellScript(spell_dh_fiery_brand);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FIERY_BRAND_DOT, SPELL_DH_FIERY_BRAND_MARKER });
    }

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, SPELL_DH_FIERY_BRAND_DOT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dh_fiery_brand::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Fiery Brand Dot - 207771
class spell_dh_fiery_brand_dot : public AuraScript
{
    PrepareAuraScript(spell_dh_fiery_brand_dot);

    void PeriodicTick(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        if (!caster || !caster->HasAura(SPELL_DH_BURNING_ALIVE))
            return;

        std::list<Unit*> unitList;
        GetTarget()->GetAnyUnitListInRange(unitList, 8.f);
        for (Unit* target : unitList)
        {
            if (!target->HasAura(SPELL_DH_FIERY_BRAND_DOT) &&
                !target->HasAura(SPELL_DH_FIERY_BRAND_MARKER) &&
                !caster->IsFriendlyTo(target))
            {
                caster->CastSpell(target, SPELL_DH_FIERY_BRAND_MARKER, true);
                break;
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_fiery_brand_dot::PeriodicTick, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// Razor Spikes - 209400
class spell_dh_razor_spikes : public SpellScriptLoader
{
public:
    spell_dh_razor_spikes() : SpellScriptLoader("spell_dh_razor_spikes") {}

    class spell_dh_razor_spikes_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_razor_spikes_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_DH_RAZOR_SPIKES_SLOW });
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            DamageInfo* damageInfo = eventInfo.GetDamageInfo();
            if (!damageInfo)
                return false;

            if (damageInfo->GetAttackType() == BASE_ATTACK ||
                damageInfo->GetAttackType() == OFF_ATTACK)
            {
                Unit* caster = damageInfo->GetAttacker();
                Unit* target = damageInfo->GetVictim();
                if (!caster || !target || !caster->ToPlayer())
                    return false;

                if (!caster->IsValidAttackTarget(target))
                    return false;

                if (caster->HasAura(SPELL_DH_DEMON_SPIKES_BUFF))
                {
                    caster->GetScheduler().Schedule(750ms, [caster, target](TaskContext /*context*/)
                        {
                            caster->CastSpell(target, SPELL_DH_RAZOR_SPIKES_SLOW, true);
                        });
                }
                return true;
            }
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dh_razor_spikes_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_razor_spikes_AuraScript();
    }
};

// Soul Barrier - 263648
class spell_dh_soul_barrier : public SpellScriptLoader
{
public:
    spell_dh_soul_barrier() : SpellScriptLoader("spell_dh_soul_barrier") {}

    class spell_dh_soul_barrier_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_soul_barrier_AuraScript);

        void CalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (Player* player = caster->ToPlayer())
            {
                float coeff = amount / 100.f;
                float soulShardCoeff = GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints / 100.f;
                int32 ap = player->GetTotalAttackPowerValue(BASE_ATTACK);

                amount = coeff * ap;

                // Consume all soul fragments in 25 yards;
                std::vector<std::vector<AreaTrigger*>> fragments;
                fragments.push_back(caster->GetAreaTriggers(SPELL_DH_SHATTERED_SOULS));
                fragments.push_back(caster->GetAreaTriggers(SPELL_DH_SHATTERED_SOULS_DEMON));
                fragments.push_back(caster->GetAreaTriggers(SPELL_DH_LESSER_SOUL_SHARD));
                float range = 25.f;

                for (std::vector<AreaTrigger*> vec : fragments)
                {
                    for (AreaTrigger* at : vec)
                    {
                        if (!caster->IsWithinDist(at, range))
                            continue;

                        if (TempSummon* tempSumm = caster->SummonCreature(WORLD_TRIGGER, at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 100))
                        {
                            tempSumm->SetFaction(caster->GetFaction());
                            tempSumm->SetSummonerGUID(caster->GetGUID());
                            int32 bp = 0;
                            switch (at->GetTemplate()->Id)
                            {
                            case 6007:
                            case 5997:
                                bp = SPELL_DH_SOUL_FRAGMENT_HEAL_VENGEANCE;
                                break;
                            case 6710:
                                bp = SPELL_DH_LESSER_SOUL_SHARD_HEAL;
                                break;
                            }

                            caster->CastCustomSpell(SPELL_DH_CONSUME_SOUL_MISSILE, SPELLVALUE_BASE_POINT0, bp, tempSumm, true);

                            if (at->GetTemplate()->Id == 6007)
                                caster->CastSpell(caster, SPELL_DH_SOUL_FRAGMENT_DEMON_BONUS, true);

                            if (caster->HasAura(SPELL_DH_FEED_THE_DEMON))
                                caster->GetSpellHistory()->ReduceChargeCooldown(sSpellMgr->GetSpellInfo(SPELL_DH_DEMON_SPIKES, DIFFICULTY_NONE)->ChargeCategoryId, 1000);

                            if (caster->HasAura(SPELL_DH_PAINBRINGER))
                                caster->CastSpell(caster, SPELL_DH_PAINBRINGER_BUFF, true);

                            amount += soulShardCoeff * ap;

                            at->SetDuration(0);
                        }
                    }
                }
            }

            if (AuraApplication* app = caster->GetAuraApplication(SPELL_DH_SOUL_BARRIER))
                app->ClientUpdate();
        }

        void HandleAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            uint32 threshold = caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.4914f;

            if (absorbAmount < dmgInfo.GetDamage())
                aurEff->SetAmount(absorbAmount + threshold);

            if (AuraApplication* app = caster->GetAuraApplication(SPELL_DH_SOUL_BARRIER))
                app->ClientUpdate();
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_soul_barrier_AuraScript::CalcAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_dh_soul_barrier_AuraScript::HandleAbsorb, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_soul_barrier_AuraScript();
    }
};

// Nether Bond - 207810
class spell_dh_nether_bond : public SpellScriptLoader
{
public:
    spell_dh_nether_bond() : SpellScriptLoader("spell_dh_nether_bond") {}

    class spell_dh_nether_bond_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_nether_bond_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_NETHER_BOND_DAMAGE, DIFFICULTY_NONE) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_NETHER_BOND_PERIODIC, DIFFICULTY_NONE))
                return false;
            return true;
        }

        void HandleDummy()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_DH_NETHER_BOND_PERIODIC, true);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_dh_nether_bond_SpellScript::HandleDummy);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_nether_bond_SpellScript();
    }
};

// Nether Bond periodic - 207811
class spell_dh_nether_bond_periodic : public SpellScriptLoader
{
public:
    spell_dh_nether_bond_periodic() : SpellScriptLoader("spell_dh_nether_bond_periodic") {}

    class spell_dh_nether_bond_periodic_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_nether_bond_periodic_AuraScript);

        Unit* m_BondUnit;

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            // Try to get the bonded Unit
            if (!m_BondUnit)
                m_BondUnit = GetBondUnit();

            // If still not found, return
            if (!m_BondUnit)
                return;

            int32 casterHealBp = 0;
            int32 casterDamageBp = 0;
            int32 targetHealBp = 0;
            int32 targetDamageBp = 0;

            float casterHp = caster->GetHealthPct();
            float targetHp = m_BondUnit->GetHealthPct();
            float healthPct = (casterHp + targetHp) / 2.0f;

            if (casterHp < targetHp)
            {
                casterHealBp = caster->CountPctFromMaxHealth(healthPct) - caster->GetHealth();
                targetDamageBp = m_BondUnit->GetHealth() - m_BondUnit->CountPctFromMaxHealth(healthPct);
            }
            else
            {
                casterDamageBp = caster->GetHealth() - caster->CountPctFromMaxHealth(healthPct);
                targetHealBp = m_BondUnit->CountPctFromMaxHealth(healthPct) - m_BondUnit->GetHealth();
            }

            CustomSpellValues casterValues;
            CustomSpellValues targetValues;
            casterValues.AddSpellMod(SPELLVALUE_BASE_POINT0, casterDamageBp);
            casterValues.AddSpellMod(SPELLVALUE_BASE_POINT1, casterHealBp);
            targetValues.AddSpellMod(SPELLVALUE_BASE_POINT0, targetDamageBp);
            targetValues.AddSpellMod(SPELLVALUE_BASE_POINT1, targetHealBp);

            caster->CastCustomSpell(SPELL_DH_NETHER_BOND_DAMAGE, casterValues, caster, TRIGGERED_FULL_MASK);
            caster->CastCustomSpell(SPELL_DH_NETHER_BOND_DAMAGE, targetValues, m_BondUnit, TRIGGERED_FULL_MASK);
        }

        Unit* GetBondUnit()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return nullptr;

            std::list<Unit*> units;
            Trinity::AnyUnitInObjectRangeCheck check(caster, 100.0f);
            Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> search(caster, units, check);
            Cell::VisitAllObjects(caster, search, 100.0f);

            for (Unit* u : units)
                if (u->HasAura(SPELL_DH_NETHER_BOND, caster->GetGUID()))
                    return u;

            return nullptr;
        }

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            m_BondUnit = GetBondUnit();
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_dh_nether_bond_periodic_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_nether_bond_periodic_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_nether_bond_periodic_AuraScript();
    }
};

/// Honor Talents

// Solitude - 211509
class spell_dh_solitude : public SpellScriptLoader
{
public:
    spell_dh_solitude() : SpellScriptLoader("spell_dh_solitude") {}

    class spell_dh_solitude_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_solitude_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_SOLITUDE_BUFF, DIFFICULTY_NONE))
                return false;
            return true;
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            PreventDefaultAction();

            Unit* caster = GetCaster();
            if (!caster || !GetSpellInfo()->GetEffect(EFFECT_1))
                return;

            int32 range = GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints;
            std::list<Unit*> allies;
            Trinity::AnyFriendlyUnitInObjectRangeCheck check(caster, caster, range, true);
            Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(caster, allies, check);
            Cell::VisitAllObjects(caster, searcher, range);
            allies.remove(caster);

            if (allies.empty() && !caster->HasAura(SPELL_DH_SOLITUDE_BUFF))
                caster->CastSpell(caster, SPELL_DH_SOLITUDE_BUFF, true);
            else if (!allies.empty())
                caster->RemoveAurasDueToSpell(SPELL_DH_SOLITUDE_BUFF);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_solitude_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_solitude_AuraScript();
    }
};

// Awaken the demon - 205598
class spell_dh_awaken_the_demon : public SpellScriptLoader
{
public:
    spell_dh_awaken_the_demon() : SpellScriptLoader("spell_dh_awaken_the_demon") {}

    class spell_dh_awaken_the_demon_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_awaken_the_demon_AuraScript);

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            if (!caster || !eventInfo.GetDamageInfo())
                return;

            if (!GetSpellInfo()->GetEffect(EFFECT_1) || !GetSpellInfo()->GetEffect(EFFECT_2))
                return;

            uint64 threshold1 = caster->CountPctFromMaxHealth(aurEff->GetBaseAmount());
            uint64 threshold2 = caster->CountPctFromMaxHealth(GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints);
            int32 duration = GetSpellInfo()->GetEffect(EFFECT_2)->BasePoints;

            if (caster->GetHealth() - eventInfo.GetDamageInfo()->GetDamage() < threshold1)
            {
                if (caster->HasAura(SPELL_DH_AWAKEN_THE_DEMON_CD))
                    return;
                caster->CastSpell(caster, SPELL_DH_AWAKEN_THE_DEMON_CD, true);
                if (Aura* aur = caster->GetAura(SPELL_DH_METAMORPHOSIS_HAVOC))
                {
                    aur->SetDuration(std::min(duration * IN_MILLISECONDS + aur->GetDuration(), aur->GetMaxDuration()));
                    return;
                }
                if (Aura* aur = caster->AddAura(SPELL_DH_METAMORPHOSIS_HAVOC, caster))
                    aur->SetDuration(duration * IN_MILLISECONDS);
            }

            // Check only if we are above the second threshold and we are falling under it just now
            if (caster->GetHealth() > threshold2 && caster->GetHealth() - eventInfo.GetDamageInfo()->GetDamage() < threshold2)
            {
                if (Aura* aur = caster->GetAura(SPELL_DH_METAMORPHOSIS_HAVOC))
                {
                    aur->SetDuration(std::min(duration * IN_MILLISECONDS + aur->GetDuration(), aur->GetMaxDuration()));
                    return;
                }
            }
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_awaken_the_demon_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_awaken_the_demon_AuraScript();
    }
};

struct auraData
{
    auraData(uint32 id, ObjectGuid casterGUID) : m_id(id), m_casterGuid(casterGUID) {}
    uint32 m_id;
    ObjectGuid m_casterGuid;
};

// Reverse Magic - 205604
class spell_dh_reverse_magic : public SpellScriptLoader
{
public:
    spell_dh_reverse_magic() : SpellScriptLoader("spell_dh_reverse_magic") {}

    class spell_dh_reverse_magic_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_reverse_magic_SpellScript);

        void HandleScript()
        {
            Unit* player = GetCaster();
            if (!player || !player->ToPlayer())
                return;

            Unit* _player = player->ToPlayer();

            std::list<Unit*> allies;
            Trinity::AnyFriendlyUnitInObjectRangeCheck check(_player, _player, 10.f, true);
            Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(_player, allies, check);
            Cell::VisitAllObjects(_player, searcher, 10.f);

            for (Unit* unit : allies)
            {
                std::set<auraData*> auraListToRemove;
                Unit::AuraApplicationMap AuraList = unit->GetAppliedAuras();
                for (Unit::AuraApplicationMap::iterator iter = AuraList.begin(); iter != AuraList.end(); ++iter)
                {
                    Aura* aura = iter->second->GetBase();
                    if (!aura)
                        continue;

                    Unit* caster = aura->GetCaster();
                    if (!caster || caster->GetGUID() == unit->GetGUID())
                        continue;

                    if (!caster->IsWithinDist(unit, 40.0f))
                        continue;

                    if (aura->GetSpellInfo()->IsPositive())
                        continue;

                    if (aura->GetSpellInfo()->Dispel != DISPEL_MAGIC)
                        continue;

                    if (Creature* creature = caster->ToCreature())
                    {
                        if (creature->GetCreatureTemplate()->rank == CREATURE_ELITE_WORLDBOSS)
                            continue;
                        if (creature->GetCreatureTemplate()->rank == CREATURE_ELITE_ELITE && creature->GetMap()->IsDungeon())
                            continue;
                    }

                    if (Aura* targetAura = unit->AddAura(aura->GetSpellInfo()->Id, caster))
                    {
                        for (int i = 0; i < MAX_SPELL_EFFECTS; ++i)
                        {
                            targetAura->SetMaxDuration(aura->GetMaxDuration());
                            targetAura->SetDuration(aura->GetDuration());
                            if (targetAura->GetEffect(i) && aura->GetEffect(i))
                            {
                                AuraEffect* auraEffect = unit->GetAuraEffect(aura->GetSpellInfo()->Id, i);
                                if (!auraEffect)
                                    continue;

                                int32 amount = auraEffect->GetAmount();
                                int32 damage = auraEffect->GetDamage();

                                if (auraEffect->GetAuraType() == SPELL_AURA_PERIODIC_DAMAGE ||
                                    auraEffect->GetAuraType() == SPELL_AURA_PERIODIC_DAMAGE_PERCENT)
                                    damage = caster->SpellDamageBonusDone(unit, aura->GetSpellInfo(), damage, DOT, aura->GetSpellInfo()->GetEffect(i), auraEffect->GetBase()->GetStackAmount());

                                targetAura->GetEffect(i)->Variables.Set("DontRecalculatePerodics", true);
                                targetAura->GetEffect(i)->SetAmount(amount);
                                targetAura->GetEffect(i)->SetDamage(damage);
                                targetAura->GetEffect(i)->SetPeriodicTimer(auraEffect->GetPeriodicTimer());
                            }
                        }
                        targetAura->SetNeedClientUpdateForTargets();
                    }

                    auraListToRemove.insert(new auraData(aura->GetSpellInfo()->Id, caster->GetGUID()));
                }

                for (auto aura : auraListToRemove)
                {
                    unit->RemoveAura(aura->m_id, aura->m_casterGuid);
                    delete aura;
                }

                auraListToRemove.clear();
            }
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_dh_reverse_magic_SpellScript::HandleScript);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_reverse_magic_SpellScript();
    }
};

// Eye of leotheras - 206649
class spell_dh_eye_of_leotheras : public SpellScriptLoader
{
public:
    spell_dh_eye_of_leotheras() : SpellScriptLoader("spell_dh_eye_of_leotheras") {}

    class spell_dh_eye_of_leotheras_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_eye_of_leotheras_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_EYE_OF_LEOTHERAS_DAMAGE, DIFFICULTY_NONE))
                return false;

            return true;
        }

        bool HandleProc(ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            WorldObject* target = GetAura()->GetOwner();
            if (!caster || !target || !eventInfo.GetSpellInfo() || !caster->ToPlayer())
                return false;
            Unit* unitTarget = target->ToUnit();
            if (!unitTarget || eventInfo.GetSpellInfo()->IsPositive())
                return false;

            if (AuraEffect* aurEff = GetAura()->GetEffect(EFFECT_0))
            {
                int32 bp = aurEff->GetAmount();
                GetAura()->RefreshDuration();
                caster->GetScheduler().Schedule(100ms, [caster, unitTarget, bp](TaskContext /*context*/)
                    {
                        caster->CastCustomSpell(SPELL_DH_EYE_OF_LEOTHERAS_DAMAGE, SPELLVALUE_BASE_POINT0, bp, unitTarget, TRIGGERED_FULL_MASK);
                    });
                return true;
            }
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dh_eye_of_leotheras_AuraScript::HandleProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_eye_of_leotheras_AuraScript();
    }
};

// Immolation Aura - 258920
class spell_dh_immolation_aura : public SpellScript
{
    PrepareSpellScript(spell_dh_immolation_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({
            SPELL_DH_CLEANSED_BY_FLAME,
            SPELL_DH_CLEANSED_BY_FLAME_DISPEL,
            SPELL_DH_FALLOUT,
            SPELL_DH_SHATTERED_SOULS_MISSILE,
            });
    }

    void HandleCast()
    {
        Unit* caster = GetCaster();

        if (caster->HasAura(SPELL_DH_CLEANSED_BY_FLAME))
            caster->CastSpell(caster, SPELL_DH_CLEANSED_BY_FLAME_DISPEL, true);

        if (roll_chance_i(40) && caster->HasAura(SPELL_DH_FALLOUT))
            caster->CastCustomSpell(SPELL_DH_SHATTERED_SOULS_MISSILE, SPELLVALUE_BASE_POINT0, SPELL_DH_LESSER_SOUL_SHARD, caster, true);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_dh_immolation_aura::HandleCast);
    }
};

// Immolation Aura damage - 258922
class spell_dh_immolation_aura_damage : public SpellScript
{
    PrepareSpellScript(spell_dh_immolation_aura_damage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({
            SPELL_DH_CHARRED_FLESH,
            SPELL_DH_FIERY_BRAND_DOT,
            SPELL_DH_FIERY_BRAND_MARKER,
            });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            if (GetCaster()->HasAura(SPELL_DH_CHARRED_FLESH))
            {
                for (uint32 spellId : { SPELL_DH_FIERY_BRAND_DOT, SPELL_DH_FIERY_BRAND_MARKER })
                {
                    if (Aura* fieryBrand = target->GetAura(spellId))
                    {
                        int32 durationMod = GetCaster()->GetAuraEffectAmount(SPELL_DH_CHARRED_FLESH, EFFECT_0);
                        fieryBrand->ModDuration(durationMod);
                    }
                }
            }
        }
    }

    void Register()
    {
        OnEffectHitTarget += SpellEffectFn(spell_dh_immolation_aura_damage::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Jagged Spikes - 208796
class spell_dh_jagged_spikes : public SpellScriptLoader
{
public:
    spell_dh_jagged_spikes() : SpellScriptLoader("spell_dh_jagged_spikes") {}

    class spell_dh_jagged_spikes_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_jagged_spikes_AuraScript);

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            Unit* target = eventInfo.GetActor();
            if (!caster || !eventInfo.GetDamageInfo())
                return;
            if (caster->IsFriendlyTo(target))
                return;

            int32 pct = caster->GetAuraEffectAmount(SPELL_DH_JAGGED_SPIKES, EFFECT_0);
            int32 damage = eventInfo.GetDamageInfo()->GetDamage();
            ApplyPct(damage, pct);

            caster->CastCustomSpell(SPELL_DH_JAGGED_SPIKES_DAMAGE, SPELLVALUE_BASE_POINT0, damage, target, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_jagged_spikes_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_jagged_spikes_AuraScript();
    }
};

// 206966 - Fel Lance
class spell_dh_fel_lance : public SpellScriptLoader
{
public:
    spell_dh_fel_lance() : SpellScriptLoader("spell_dh_fel_lance") { }

    class spell_dh_fel_lance_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_fel_lance_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            int32 pct = GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints;
            SetHitDamage(GetHitDamage() + target->CountPctFromMaxHealth(pct));
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_fel_lance_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dh_fel_lance_SpellScript();
    }
};

// 206891 - Intimidated
class spell_dh_intimidated : public SpellScriptLoader
{
public:
    spell_dh_intimidated() : SpellScriptLoader("spell_dh_intimidated") { }

    class spell_dh_intimidated_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_intimidated_AuraScript);

        void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            Unit* attacker = eventInfo.GetActor();
            WorldObject* auraOwner = GetAura()->GetOwner();
            if (!attacker || !auraOwner)
                return;

            if (attacker == GetCaster())
            {
                RefreshDuration();
                return;
            }

            if (uniqueTargets.size() >= 4 || !auraOwner->ToUnit())
                return;

            if (uniqueTargets.find(attacker->GetGUID()) == uniqueTargets.end())
            {
                attacker->CastSpell(auraOwner->ToUnit(), GetSpellInfo()->Id, true);
                uniqueTargets.insert(attacker->GetGUID());
            }
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_intimidated_AuraScript::OnProc, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
        }

    private:
        GuidSet uniqueTargets;
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_intimidated_AuraScript();
    }
};

// 203753 - Blade Turning
class spell_dh_blade_turning : public SpellScriptLoader
{
public:
    spell_dh_blade_turning() : SpellScriptLoader("spell_dh_blade_turning") { }

    class spell_dh_blade_turning_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_blade_turning_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetHitMask() & PROC_HIT_PARRY)
                return true;
            return false;
        }

        void Register()
        {
            DoCheckProc += AuraCheckProcFn(spell_dh_blade_turning_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_blade_turning_AuraScript();
    }
};

// 201469 - Demon Speed
// Called by Blur (212800) and Netherwalk (196555)
class spell_dh_artifact_demon_speed : public SpellScriptLoader
{
public:
    spell_dh_artifact_demon_speed() : SpellScriptLoader("spell_dh_artifact_demon_speed") { }

    class spell_dh_artifact_demon_speed_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_artifact_demon_speed_SpellScript);

        void HandleCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (AuraEffect* aurEff = caster->GetAuraEffect(SPELL_DH_DEMON_SPEED, EFFECT_0))
                for (uint8 i = 0; i < aurEff->GetAmount(); ++i)
                    caster->GetSpellHistory()->RestoreCharge(sSpellMgr->GetSpellInfo(SPELL_DH_FEL_RUSH, DIFFICULTY_NONE)->ChargeCategoryId);
        }

        void Register()
        {
            OnCast += SpellCastFn(spell_dh_artifact_demon_speed_SpellScript::HandleCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dh_artifact_demon_speed_SpellScript();
    }
};

// 201463 - Deceiver's Fury
class spell_dh_artifact_deceivers_fury : public SpellScriptLoader
{
public:
    spell_dh_artifact_deceivers_fury() : SpellScriptLoader("spell_dh_artifact_deceivers_fury") { }

    class spell_dh_artifact_deceivers_fury_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_artifact_deceivers_fury_AuraScript);

        void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastCustomSpell(SPELL_DH_DECEIVERS_FURY_ENERGIZE, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), caster, true);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_artifact_deceivers_fury_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_artifact_deceivers_fury_AuraScript();
    }
};

// 202443 - Anguish
class spell_dh_artifact_anguish : public SpellScriptLoader
{
public:
    spell_dh_artifact_anguish() : SpellScriptLoader("spell_dh_artifact_anguish") { }

    class spell_dh_artifact_anguish_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_artifact_anguish_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetUnitOwner();
            if (!caster || !target)
                return;

            caster->CastCustomSpell(SPELL_DH_ANGUISH_DAMAGE, SPELLVALUE_AURA_STACK, GetStackAmount(), target, true);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_dh_artifact_anguish_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_artifact_anguish_AuraScript();
    }
};

// 202446 - Anguish damage
class spell_dh_artifact_anguish_damage : public SpellScriptLoader
{
public:
    spell_dh_artifact_anguish_damage() : SpellScriptLoader("spell_dh_artifact_anguish_damage") { }

    class spell_dh_artifact_anguish_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_artifact_anguish_damage_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            int32 stacks = GetSpellValue()->AuraStackAmount;
            SetHitDamage(GetHitDamage() * stacks);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_artifact_anguish_damage_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dh_artifact_anguish_damage_SpellScript();
    }
};

// 209651 - Shattered Souls missile
class spell_dh_shattered_souls_missile : public SpellScriptLoader
{
public:
    spell_dh_shattered_souls_missile() : SpellScriptLoader("spell_dh_shattered_souls_missile") { }

    class spell_dh_shattered_souls_missile_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_shattered_souls_missile_SpellScript);

        void HandleHit(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            Unit* caster = GetCaster();
            if (!caster)
                return;

            int32 spellToCast = GetSpellValue()->EffectBasePoints[0];
            if (WorldLocation* dest = GetHitDest())
                caster->CastSpell(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), spellToCast, true);
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_dh_shattered_souls_missile_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_TRIGGER_MISSILE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dh_shattered_souls_missile_SpellScript();
    }
};

// 203783 - Shear proc
class spell_dh_shear_proc : public SpellScriptLoader
{
public:
    spell_dh_shear_proc() : SpellScriptLoader("spell_dh_shear_proc") { }

    class spell_dh_shear_proc_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_shear_proc_AuraScript);

        void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            Unit* caster = GetCaster();
            if (!caster || !eventInfo.GetSpellInfo())
                return;

            int32 procChance = 100;
            if (eventInfo.GetSpellInfo()->Id == SPELL_DH_SHEAR)
            {
                procChance = 15;
                procChance += caster->GetAuraEffectAmount(SPELL_DH_SHATTER_THE_SOULS, EFFECT_0);
            }

            if (roll_chance_i(procChance))
                caster->CastCustomSpell(SPELL_DH_SHATTERED_SOULS_MISSILE, SPELLVALUE_BASE_POINT0, SPELL_DH_LESSER_SOUL_SHARD, caster, true);

            if (caster->GetSpellHistory()->HasCooldown(SPELL_DH_FELBLADE))
                if (roll_chance_i(caster->GetAuraEffectAmount(SPELL_DH_SHEAR_PROC, EFFECT_3)))
                    caster->GetSpellHistory()->ResetCooldown(SPELL_DH_FELBLADE);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_shear_proc_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_shear_proc_AuraScript();
    }
};

// 210047 - Consume Soul missile
class spell_dh_consume_soul_missile : public SpellScriptLoader
{
public:
    spell_dh_consume_soul_missile() : SpellScriptLoader("spell_dh_consume_soul_missile") { }

    class spell_dh_consume_soul_missile_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_consume_soul_missile_SpellScript);

        void HandleHit(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            Unit* caster = GetCaster();
            if (!caster)
                return;

            int32 spellToCast = GetSpellValue()->EffectBasePoints[0];
            caster->CastSpell(caster, spellToCast, true);
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_dh_consume_soul_missile_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_TRIGGER_MISSILE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dh_consume_soul_missile_SpellScript();
    }
};

// 207684 - Sigil of Misery
// MiscId - 6351
struct at_dh_sigil_of_misery : AreaTriggerAI
{
    at_dh_sigil_of_misery(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnRemove() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(*at, SPELL_DH_SIGIL_OF_MISERY_EXPLOSION, true);
        caster->CastSpell(*at, SPELL_DH_SIGIL_OF_MISERY_TRIGGER, true);
    }
};

// 204596 - Sigil of Flame
// MiscId - 6039
struct at_dh_sigil_of_flame : AreaTriggerAI
{
    at_dh_sigil_of_flame(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnRemove() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(*at, SPELL_DH_SIGIL_OF_FLAME_EXPLOSION, true);
        caster->CastSpell(*at, SPELL_DH_SIGIL_OF_FLAME_TRIGGER, true);
    }
};

// 202137 - Sigil of Silence
// MiscId - 6027
struct at_dh_sigil_of_silence : AreaTriggerAI
{
    at_dh_sigil_of_silence(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnRemove() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(*at, SPELL_DH_SIGIL_OF_SILENCE_EXPLOSION, true);
        caster->CastSpell(*at, SPELL_DH_SIGIL_OF_SILENCE_TRIGGER, true);
    }
};

// 209426 - Darkness absorb
class spell_dh_darkness_absorb : public SpellScriptLoader
{
public:
    spell_dh_darkness_absorb() : SpellScriptLoader("spell_dh_darkness_absorb") { }

    class spell_dh_darkness_absorb_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_darkness_absorb_AuraScript);

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void OnAbsorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            int32 chance = GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints + caster->GetAuraEffectAmount(SPELL_DH_COVER_OF_DARKNESS, EFFECT_0);
            if (roll_chance_i(chance))
                absorbAmount = dmgInfo.GetDamage();
        }

        void Register()
        {
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_dh_darkness_absorb_AuraScript::OnAbsorb, EFFECT_0);
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_darkness_absorb_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_darkness_absorb_AuraScript();
    }
};

// 196718 - Darkness
// MiscId - 6615
struct at_dh_darkness : AreaTriggerAI
{
    at_dh_darkness(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

private:
    bool entered;

    void OnInitialize() override
    {
        at->SetDuration(8000);
    }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster || !unit)
            return;

        if (caster->IsFriendlyTo(unit) && !unit->HasAura(SPELL_DH_DARKNESS_ABSORB))
        {
            entered = true;

            if (entered)
            {
                caster->CastSpell(unit, SPELL_DH_DARKNESS_ABSORB, true);
                entered = false;
            }
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster || !unit)
            return;
        if (unit->HasAura(SPELL_DH_DARKNESS_ABSORB))
            unit->RemoveAurasDueToSpell(SPELL_DH_DARKNESS_ABSORB, caster->GetGUID());
    }
};

// 203650 - Prepared
class spell_dh_prepared : public SpellScriptLoader
{
public:
    spell_dh_prepared() : SpellScriptLoader("spell_dh_prepared") { }

    class spell_dh_prepared_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_prepared_AuraScript);

        void PeriodicTick(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->ModifyPower(POWER_FURY, aurEff->GetAmount() / 10.f);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_prepared_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_MOD_POWER_REGEN);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_prepared_AuraScript();
    }
};

// 206478 - Demonic Appetite
class spell_dh_demonic_appetite : public SpellScriptLoader
{
public:
    spell_dh_demonic_appetite() : SpellScriptLoader("spell_dh_demonic_appetite") { }

    class spell_dh_demonic_appetite_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_demonic_appetite_AuraScript);

        void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastCustomSpell(SPELL_DH_SHATTERED_SOULS_MISSILE, SPELLVALUE_BASE_POINT0, SPELL_DH_LESSER_SOUL_SHARD, caster, true);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_demonic_appetite_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_demonic_appetite_AuraScript();
    }
};

// Soul Fragment healing effects - 178963, 203794, 228532
class spell_dh_soul_fragment_heals : public SpellScriptLoader
{
public:
    spell_dh_soul_fragment_heals() : SpellScriptLoader("spell_dh_soul_fragment_heals") { }

    class spell_dh_soul_fragment_heals_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_soul_fragment_heals_SpellScript);

        void HandleHit(SpellEffIndex effIndex)
        {
            if (!GetCaster()->HasAura(SPELL_DH_DEMONIC_APPETITE))
                PreventHitDefaultEffect(effIndex);
        }

        void HandleHeal(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (int32 reductionTime = caster->GetAuraEffectAmount(SPELL_DH_FEAST_ON_THE_SOULS, EFFECT_0))
            {
                caster->GetSpellHistory()->ModifyCooldown(SPELL_DH_CHAOS_NOVA, -reductionTime);
                caster->GetSpellHistory()->ModifyCooldown(SPELL_DH_EYE_BEAM, -reductionTime);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_soul_fragment_heals_SpellScript::HandleHeal, EFFECT_0, SPELL_AURA_ANY);
            OnEffectLaunchTarget += SpellEffectFn(spell_dh_soul_fragment_heals_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectLaunch += SpellEffectFn(spell_dh_soul_fragment_heals_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dh_soul_fragment_heals_SpellScript();
    }
};

// 206475 - Chaos Cleave
class spell_dh_chaos_cleave : public SpellScriptLoader
{
public:
    spell_dh_chaos_cleave() : SpellScriptLoader("spell_dh_chaos_cleave") { }

    class spell_dh_chaos_cleave_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_chaos_cleave_AuraScript);

        void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            Unit* caster = GetCaster();
            if (!caster || !eventInfo.GetDamageInfo())
                return;

            int32 damage = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount());
            caster->CastCustomSpell(SPELL_DH_CHAOS_CLEAVE_PROC, SPELLVALUE_BASE_POINT0, damage, caster, true);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_chaos_cleave_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_chaos_cleave_AuraScript();
    }
};

// 205411 - Desperate Instints
class spell_dh_desperate_instincts : public SpellScriptLoader
{
public:
    spell_dh_desperate_instincts() : SpellScriptLoader("spell_dh_desperate_instincts") { }

    class spell_dh_desperate_instincts_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_desperate_instincts_AuraScript);

        void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            Unit* caster = GetCaster();
            if (!caster || !eventInfo.GetDamageInfo())
                return;

            if (caster->GetSpellHistory()->HasCooldown(SPELL_DH_BLUR_BUFF))
                return;

            uint32 triggerOnHealth = caster->CountPctFromMaxHealth(aurEff->GetAmount());
            uint32 currentHealth = caster->GetHealth();
            // Just falling below threshold
            if (currentHealth > triggerOnHealth && (currentHealth - eventInfo.GetDamageInfo()->GetDamage()) <= triggerOnHealth)
                caster->CastSpell(caster, SPELL_DH_BLUR_BUFF, false);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_desperate_instincts_AuraScript::OnProc, EFFECT_0, SPELL_AURA_TRIGGER_SPELL_ON_HEALTH_PCT);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_desperate_instincts_AuraScript();
    }
};

// 209795 - Fracture
class spell_dh_fracture : public SpellScriptLoader
{
public:
    spell_dh_fracture() : SpellScriptLoader("spell_dh_fracture") { }

    class spell_dh_fracture_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_fracture_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            for (uint8 i = 0; i < 2; ++i)
                caster->CastCustomSpell(SPELL_DH_SHATTERED_SOULS_MISSILE, SPELLVALUE_BASE_POINT0, SPELL_DH_LESSER_SOUL_SHARD, caster, true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_fracture_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dh_fracture_SpellScript();
    }
};

// 202138 - Sigil of Chains
// MiscId - 6031
struct at_dh_sigil_of_chains : AreaTriggerAI
{
    at_dh_sigil_of_chains(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnRemove() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (caster->GetTypeId() != TYPEID_PLAYER)
            return;

        caster->CastSpell(*at, SPELL_DH_SIGIL_OF_CHAINS_EXPLOSION, true);

        for (ObjectGuid guid : at->GetInsideUnits())
        {
            if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
            {
                caster->CastSpell(unit, SPELL_DH_SIGIL_OF_CHAINS_SLOW, true);
                unit->CastSpell(*at, SPELL_DH_SIGIL_OF_CHAINS_TRIGGER, true);
            }
        }
    }
};

// 212084 - Fel Devastation
class spell_dh_fel_devastation : public SpellScriptLoader
{
public:
    spell_dh_fel_devastation() : SpellScriptLoader("spell_dh_fel_devastation") { }

    class spell_dh_fel_devastation_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_fel_devastation_AuraScript);

        void PeriodicTick(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (aurEff->GetTickNumber() == 1)
                return;

            caster->CastSpell(caster, SPELL_DH_FEL_DEVASTATION_DAMAGE, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_fel_devastation_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_fel_devastation_AuraScript();
    }
};

// 212105 - Fel Devastation damage
class spell_dh_fel_devastation_damage : public SpellScriptLoader
{
public:
    spell_dh_fel_devastation_damage() : SpellScriptLoader("spell_dh_fel_devastation_damage") { }

    class spell_dh_fel_devastation_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_fel_devastation_damage_SpellScript);

        bool firstHit = true;

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (firstHit)
            {
                firstHit = false;
                caster->CastSpell(caster, SPELL_DH_FEL_DEVASTATION_HEAL, true);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_fel_devastation_damage_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dh_fel_devastation_damage_SpellScript();
    }
};

// 218679 - Spirit Bomb
class spell_dh_spirit_bomb : public SpellScriptLoader
{
public:
    spell_dh_spirit_bomb() : SpellScriptLoader("spell_dh_spirit_bomb") { }

    class spell_dh_spirit_bomb_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_spirit_bomb_SpellScript);

        bool tryCastDamage(Unit* caster, Unit* target, uint32 spellId)
        {
            if (AreaTrigger* at = caster->GetAreaTrigger(spellId))
            {
                caster->CastSpell(target, SPELL_DH_SPIRIT_BOMB_DAMAGE, true);
                at->Remove();
                return true;
            }

            return false;
        }

        void HandleHit()
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            for (uint32 spellId : { SPELL_DH_LESSER_SOUL_SHARD, SPELL_DH_SHATTERED_SOULS, SPELL_DH_SHATTERED_SOULS_DEMON })
                if (tryCastDamage(caster, target, spellId))
                    break;
        }

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            if (!caster->GetAreaTrigger(SPELL_DH_LESSER_SOUL_SHARD) && !caster->GetAreaTrigger(SPELL_DH_SHATTERED_SOULS) && !caster->GetAreaTrigger(SPELL_DH_SHATTERED_SOULS_DEMON))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_dh_spirit_bomb_SpellScript::HandleHit);
            OnCheckCast += SpellCheckCastFn(spell_dh_spirit_bomb_SpellScript::CheckCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dh_spirit_bomb_SpellScript();
    }
};

// 224509 - Frailty
class spell_dh_frailty : public SpellScriptLoader
{
public:
    spell_dh_frailty() : SpellScriptLoader("spell_dh_frailty") { }

    class spell_dh_frailty_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_frailty_AuraScript);

        void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            Unit* caster = GetCaster();
            if (!caster || caster != eventInfo.GetActor() || !eventInfo.GetDamageInfo())
                return;

            uint32 damage = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount());
            damage += GetAura()->Variables.GetValue<uint32>("_frailtyDamage");

            GetAura()->Variables.Set("_frailtyDamage", damage);
        }

        void PeriodicTick(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (uint32 heal = GetAura()->Variables.GetValue<uint32>("_frailtyDamage"))
            {
                caster->CastCustomSpell(SPELL_DH_FRAILTY_HEAL, SPELLVALUE_BASE_POINT0, heal, caster, true);
                GetAura()->Variables.Set<uint32>("_frailtyDamage", 0);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_frailty_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectProc += AuraEffectProcFn(spell_dh_frailty_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_frailty_AuraScript();
    }
};

// 236189 - Demonic Infusion
class spell_dh_demonic_infusion : public SpellScriptLoader
{
public:
    spell_dh_demonic_infusion() : SpellScriptLoader("spell_dh_demonic_infusion") { }

    class spell_dh_demonic_infusion_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_demonic_infusion_SpellScript);

        void HandleCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->GetSpellHistory()->ResetCharges(sSpellMgr->GetSpellInfo(SPELL_DH_DEMON_SPIKES, DIFFICULTY_NONE)->ChargeCategoryId);
            caster->CastSpell(caster, SPELL_DH_DEMON_SPIKES, true);
            caster->GetSpellHistory()->ResetCharges(sSpellMgr->GetSpellInfo(SPELL_DH_DEMON_SPIKES, DIFFICULTY_NONE)->ChargeCategoryId);
        }

        void Register()
        {
            OnCast += SpellCastFn(spell_dh_demonic_infusion_SpellScript::HandleCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dh_demonic_infusion_SpellScript();
    }
};

// 201467 - Fury of the Illidari
// MiscId - 5758
struct at_dh_artifact_fury_of_the_illidari : AreaTriggerAI
{
    at_dh_artifact_fury_of_the_illidari(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnInitialize() override
    {
        at->Variables.Set<int32>("_timer", 500);
    }

    void OnUpdate(uint32 diff) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        int32 timer = at->Variables.GetValue<int32>("_timer") + diff;
        if (timer >= 490)
        {
            at->Variables.Set<int32>("_timer", timer - 490);
            caster->CastSpell(*at, SPELL_DH_FURY_OF_THE_ILLIDARI_MAINHAND, true);
            caster->CastSpell(*at, SPELL_DH_FURY_OF_THE_ILLIDARI_OFFHAND, true);
        }
        else
            at->Variables.Set("_timer", timer);
    }

    void OnRemove() override
    {
        Unit* caster = at->GetCaster();
        if (!caster || !caster->ToPlayer())
            return;

        int32 rageOfTheIllidari = caster->Variables.GetValue<int32>("Spells.RageOfTheIllidariDamage");
        if (!rageOfTheIllidari)
            return;

        caster->Variables.Set<int32>("Spells.RageOfTheIllidariDamage", 0);

        // Cannot cast custom spell on position...
        if (TempSummon* target = caster->SummonCreature(WORLD_TRIGGER, *at, TEMPSUMMON_TIMED_DESPAWN, 1000))
        {
            caster->CastSpell(*at, SPELL_DH_RAGE_OF_THE_ILLIDARI_VISUAL, true);
            caster->GetScheduler().Schedule(750ms, [caster, target, rageOfTheIllidari](TaskContext /*context*/)
                {
                    caster->CastCustomSpell(SPELL_DH_RAGE_OF_THE_ILLIDARI_DAMAGE, SPELLVALUE_BASE_POINT0, rageOfTheIllidari, target, TRIGGERED_FULL_MASK);
                });
        }
    }
};

// 201471 - Inner Demons
class spell_dh_artifact_inner_demons : public SpellScriptLoader
{
public:
    spell_dh_artifact_inner_demons() : SpellScriptLoader("spell_dh_artifact_inner_demons") { }

    class spell_dh_artifact_inner_demons_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_artifact_inner_demons_AuraScript);

        void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            Unit* target = eventInfo.GetActionTarget();
            if (!caster || !target)
                return;

            caster->Variables.Set("Spells.InnerDemonsTarget", target->GetGUID());
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_artifact_inner_demons_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_artifact_inner_demons_AuraScript();
    }
};

// 202387 - Inner Demons
// MiscId - 5823
struct at_dh_artifact_inner_demons : AreaTriggerAI
{
    at_dh_artifact_inner_demons(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnInitialize() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        ObjectGuid const guid = caster->Variables.GetValue<ObjectGuid>("Spells.InnerDemonsTarget", ObjectGuid::Empty);
        if (Unit* target = ObjectAccessor::GetUnit(*caster, guid))
        {
            std::vector<G3D::Vector3> splinePoints;
            float orientation = caster->GetOrientation();
            float posX = caster->GetPositionX() - 7.f * cos(orientation);
            float posY = caster->GetPositionY() - 7.f * sin(orientation); // Start from behind the caster
            splinePoints.push_back(G3D::Vector3(posX, posY, caster->GetPositionZ()));
            splinePoints.push_back(G3D::Vector3(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ()));

            at->InitSplines(splinePoints, 1000);
        }
    }

    void OnRemove() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(*at, SPELL_DH_INNER_DEMONS_DAMAGE, true);
    }
};

// 201472 - Rage of the Illidari
class spell_dh_artifact_rage_of_the_illidari : public SpellScriptLoader
{
public:
    spell_dh_artifact_rage_of_the_illidari() : SpellScriptLoader("spell_dh_artifact_rage_of_the_illidari") { }

    class spell_dh_artifact_rage_of_the_illidari_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_artifact_rage_of_the_illidari_AuraScript);

        void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            if (!caster || !eventInfo.GetDamageInfo())
                return;

            int32 damage = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetSpellEffectInfo()->BasePoints);
            if (!damage)
                return;

            damage += caster->Variables.GetValue<int32>("Spells.RageOfTheIllidariDamage");

            caster->Variables.Set("Spells.RageOfTheIllidariDamage", damage);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_artifact_rage_of_the_illidari_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_artifact_rage_of_the_illidari_AuraScript();
    }
};

// 201464 - Overwhelming Power
// Called by 179057 - Chaos Nova
class spell_dh_artifact_overwhelming_power : public SpellScriptLoader
{
public:
    spell_dh_artifact_overwhelming_power() : SpellScriptLoader("spell_dh_artifact_overwhelming_power") { }

    class spell_dh_artifact_overwhelming_power_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_artifact_overwhelming_power_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (roll_chance_i(caster->GetAuraEffectAmount(SPELL_DH_OVERWHELMING_POWER, EFFECT_0)))
                caster->CastCustomSpell(SPELL_DH_SHATTERED_SOULS_MISSILE, SPELLVALUE_BASE_POINT0, SPELL_DH_LESSER_SOUL_SHARD, caster, true);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_dh_artifact_overwhelming_power_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_artifact_overwhelming_power_AuraScript();
    }
};

// 207407 - Soul Carver
class spell_dh_artifact_soul_carver : public SpellScriptLoader
{
public:
    spell_dh_artifact_soul_carver() : SpellScriptLoader("spell_dh_artifact_soul_carver") { }

    class spell_dh_artifact_soul_carver_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_artifact_soul_carver_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            uint32 soulsToShatter = GetEffectInfo(EFFECT_3)->BasePoints;
            for (uint32 i = 0; i < soulsToShatter; ++i)
                caster->CastCustomSpell(SPELL_DH_SHATTERED_SOULS_MISSILE, SPELLVALUE_BASE_POINT0, SPELL_DH_LESSER_SOUL_SHARD, caster, true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_artifact_soul_carver_SpellScript::HandleHit, EFFECT_2, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
        }
    };

    class spell_dh_artifact_soul_carver_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_artifact_soul_carver_AuraScript);

        void PeriodicTick(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastCustomSpell(SPELL_DH_SHATTERED_SOULS_MISSILE, SPELLVALUE_BASE_POINT0, SPELL_DH_LESSER_SOUL_SHARD, caster, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_artifact_soul_carver_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_artifact_soul_carver_AuraScript();
    }

    SpellScript* GetSpellScript() const
    {
        return new spell_dh_artifact_soul_carver_SpellScript();
    }
};

// 213010 - Charred Warblades
class spell_dh_artifact_charred_warblades : public SpellScriptLoader
{
public:
    spell_dh_artifact_charred_warblades() : SpellScriptLoader("spell_dh_artifact_charred_warblades") { }

    class spell_dh_artifact_charred_warblades_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_artifact_charred_warblades_AuraScript);

        void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            if (!caster || !eventInfo.GetDamageInfo())
                return;

            if (!eventInfo.GetDamageInfo()->GetDamage() || !(eventInfo.GetDamageInfo()->GetSchoolMask() & SPELL_SCHOOL_MASK_FIRE))
                return;

            int32 heal = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount());
            caster->CastCustomSpell(SPELL_DH_CHARRED_WARBLADES_HEAL, SPELLVALUE_BASE_POINT0, heal, caster, true);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_artifact_charred_warblades_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_artifact_charred_warblades_AuraScript();
    }
};

// 213017 - Fueled by Pain
class spell_dh_artifact_fueled_by_pain : public SpellScriptLoader
{
public:
    spell_dh_artifact_fueled_by_pain() : SpellScriptLoader("spell_dh_artifact_fueled_by_pain") { }

    class spell_dh_artifact_fueled_by_pain_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_artifact_fueled_by_pain_AuraScript);

        void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            int32 duration = aurEff->GetAmount() * IN_MILLISECONDS;
            if (Aura* aur = caster->AddAura(SPELL_DH_METAMORPHOSIS_VENGEANCE, caster))
            {
                aur->SetMaxDuration(duration);
                aur->RefreshDuration();
            }
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            return eventInfo.GetSpellInfo() && (eventInfo.GetSpellInfo()->Id == SPELL_DH_SOUL_FRAGMENT_HEAL_VENGEANCE || eventInfo.GetSpellInfo()->Id == SPELL_DH_LESSER_SOUL_SHARD_HEAL);
        }

        void Register()
        {
            DoCheckProc += AuraCheckProcFn(spell_dh_artifact_fueled_by_pain_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dh_artifact_fueled_by_pain_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_artifact_fueled_by_pain_AuraScript();
    }
};

// 212817 - Fiery Demise
class spell_dh_artifact_fiery_demise : public SpellScriptLoader
{
public:
    spell_dh_artifact_fiery_demise() : SpellScriptLoader("spell_dh_artifact_fiery_demise") { }

    class spell_dh_artifact_fiery_demise_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_artifact_fiery_demise_AuraScript);

        void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            Unit* target = eventInfo.GetActionTarget();
            if (!caster || !target || !caster->IsValidAttackTarget(target))
                return;

            caster->CastCustomSpell(SPELL_DH_FIERY_DEMISE_DEBUFF, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), target, true);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_artifact_fiery_demise_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_dh_artifact_fiery_demise_AuraScript();
    }
};

// 206803 - Rain from Above
class spell_demon_hunter_rain_from_above : public SpellScriptLoader
{
public:
    spell_demon_hunter_rain_from_above() : SpellScriptLoader("spell_demon_hunter_rain_from_above") { }

    class spell_demon_hunter_rain_from_above_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_demon_hunter_rain_from_above_SpellScript);

        void HandleCast()
        {
            Unit* caster = GetCaster();
            if (!caster || !caster->ToPlayer())
                return;

            caster->GetScheduler().Schedule(1750ms, [caster](TaskContext /*context*/)
                {
                    caster->CastCustomSpell((uint32)SPELL_DK_RAIN_FROM_ABOVE_SLOWFALL, SPELLVALUE_BASE_POINT0, 0, caster, TRIGGERED_FULL_MASK);
                });
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_demon_hunter_rain_from_above_SpellScript::HandleCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_demon_hunter_rain_from_above_SpellScript();
    }
};

// 162264 - Metamorphosis buffs @ Vengeance
// SpellId - SpellName
class spell_demon_hunter_metamorphosis_buffs : public SpellScriptLoader
{
public:
    spell_demon_hunter_metamorphosis_buffs() : SpellScriptLoader("spell_demon_hunter_metamorphosis_buffs") { }

    class spell_demon_hunter_metamorphosis_buffs_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_demon_hunter_metamorphosis_buffs_AuraScript);


        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->RemoveAura(SPELL_DH_DEMONIC_ORIGINS_BUFF);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->HasAura(SPELL_DH_DEMONIC_ORIGINS))
                caster->CastSpell(caster, SPELL_DH_DEMONIC_ORIGINS_BUFF, true);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_demon_hunter_metamorphosis_buffs_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
            OnEffectApply += AuraEffectApplyFn(spell_demon_hunter_metamorphosis_buffs_AuraScript::OnApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_demon_hunter_metamorphosis_buffs_AuraScript();
    }
};

// 235903 - Mana Rift
// MiscId - 9695
struct at_demon_hunter_mana_rift : AreaTriggerAI
{
    at_demon_hunter_mana_rift(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitExit(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster || !unit)
            return;

        SpellInfo const* spellProto = sSpellMgr->GetSpellInfo(SPELL_DH_MANA_RIFT_SPELL, DIFFICULTY_NONE);
        if (!spellProto)
            return;

        if (at->IsRemoved())
        {
            if (caster->IsValidAttackTarget(unit))
            {
                int32 hpBp = unit->CountPctFromMaxHealth(spellProto->GetEffect(EFFECT_1)->BasePoints);
                int32 manaBp = unit->CountPctFromMaxPower(POWER_MANA, spellProto->GetEffect(EFFECT_2)->BasePoints);
                caster->CastCustomSpell(unit, SPELL_DH_MANA_RIFT_DAMAGE, &hpBp, &manaBp, true);
            }
        }
    }
};

// 205629 - Demonic Trample
// MiscId - 6482
struct at_demon_hunter_demonic_trample : AreaTriggerAI
{
    at_demon_hunter_demonic_trample(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();

        if (!caster || !unit)
            return;

        if (caster->IsValidAttackTarget(unit))
        {
            caster->CastSpell(unit, SPELL_DH_DEMONIC_TRAMPLE_STUN, true);
            caster->CastSpell(unit, SPELL_DH_DEMONIC_TRAMPLE_DAMAGE, true);
        }
    }
};

// 162794 - Chaos Strike
// 201427 - Annihilation
class spell_demon_hunter_chaos_strike : public SpellScript
{
    PrepareSpellScript(spell_demon_hunter_chaos_strike);

    void HandleCast()
    {
        Unit* caster = GetCaster();
        Unit* target = GetExplTargetUnit();
        if (!caster || !target)
            return;

        // Chaos Strike and Annihilation have a mainhand and an offhand spell, but the crit chance should be the same.
        float criticalChances = caster->GetUnitSpellCriticalChance(target, GetSpell(), nullptr, GetSpellInfo()->GetSchoolMask(), BASE_ATTACK);
        caster->Variables.Set("Spells.ChaosStrikeCrit", roll_chance_f(criticalChances));
        caster->CastSpell(nullptr, SPELL_DH_CHAOS_STRIKE_PROC, true);
    }

    void Register()
    {
        BeforeCast += SpellCastFn(spell_demon_hunter_chaos_strike::HandleCast);
    }
};

// 185244 - Pain
class spell_demon_hunter_pain : public SpellScriptLoader
{
public:
    spell_demon_hunter_pain() : SpellScriptLoader("spell_demon_hunter_pain") { }

    class spell_demon_hunter_pain_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_demon_hunter_pain_AuraScript);

        void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            if (!caster || !eventInfo.GetDamageInfo())
                return;

            if (eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->IsPositive())
                return;

            int32 damageTaken = eventInfo.GetDamageInfo()->GetDamage();
            if (damageTaken <= 0)
                return;

            float painAmount = (50.0f * (float)damageTaken) / (float)caster->GetMaxHealth();
            caster->CastCustomSpell(SPELL_DH_REWARD_PAIN, SPELLVALUE_BASE_POINT0, 10 * painAmount, caster, true);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_demon_hunter_pain_AuraScript::OnProc, EFFECT_0, SPELL_AURA_MOD_POWER_DISPLAY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_demon_hunter_pain_AuraScript();
    }
};

// 203704 - Mana Break
class spell_demon_hunter_mana_break : public SpellScriptLoader
{
public:
    spell_demon_hunter_mana_break() : SpellScriptLoader("spell_demon_hunter_mana_break") { }

    class spell_demon_hunter_mana_break_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_demon_hunter_mana_break_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            int32 damage = GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints;
            float powerPct = target->GetPowerPct(POWER_MANA);
            if (powerPct >= 1.f)
            {
                damage += (100.f - powerPct) / 10.f * GetSpellInfo()->GetEffect(EFFECT_2)->BasePoints;
            }

            damage = std::max<uint32>(GetHitUnit()->CountPctFromMaxHealth(int32(5)), 1);

            SetHitDamage(damage);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_demon_hunter_mana_break_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_demon_hunter_mana_break_SpellScript();
    }
};

// 258881 - Trail of Ruin
class spell_demon_hunter_trail_of_ruin : public SpellScriptLoader
{
public:
    spell_demon_hunter_trail_of_ruin() : SpellScriptLoader("spell_demon_hunter_trail_of_ruin") { }

    class spell_demon_hunter_trail_of_ruin_AuraScript : public AuraScript
    {
    public:
        PrepareAuraScript(spell_demon_hunter_trail_of_ruin_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            return eventInfo.GetSpellInfo()->Id == sSpellMgr->GetSpellInfo(SPELL_DH_BLADE_DANCE)->GetEffect(EFFECT_0)->TriggerSpell;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_demon_hunter_trail_of_ruin_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_demon_hunter_trail_of_ruin_AuraScript();
    }
};

// 213480 - Unending Hatred
class spell_demon_hunter_unending_hatred : public SpellScriptLoader
{
public:
    spell_demon_hunter_unending_hatred() : SpellScriptLoader("spell_demon_hunter_unending_hatred") { }

    class spell_demon_hunter_unending_hatred_AuraScript : public AuraScript
    {
    public:
        PrepareAuraScript(spell_demon_hunter_unending_hatred_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            return eventInfo.GetDamageInfo() && eventInfo.GetDamageInfo()->GetSchoolMask() & SPELL_SCHOOL_MASK_MAGIC;
        }

        void Proc(ProcEventInfo& eventInfo)
        {
            Player* caster = GetPlayerCaster();
            if (!caster)
                return;

            int32 pointsGained = GetPointsGained(caster, eventInfo.GetDamageInfo()->GetDamage());

            if (caster->GetSpecializationId() == TALENT_SPEC_DEMON_HUNTER_HAVOC)
                caster->EnergizeBySpell(caster, GetSpellInfo()->Id, pointsGained, POWER_FURY);
            else if (caster->GetSpecializationId() == TALENT_SPEC_DEMON_HUNTER_VENGEANCE)
                caster->EnergizeBySpell(caster, GetSpellInfo()->Id, pointsGained, POWER_PAIN);
        }

        Player* GetPlayerCaster()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return nullptr;

            return caster->ToPlayer();
        }

        int32 GetPointsGained(Player* caster, uint32 damage)
        {
            float damagePct = (float)damage / caster->GetMaxHealth() * 100.f / 2;
            int32 max = GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints;
            if (damagePct > max)
                return max;
            if (damagePct < 1)
                return 1;
            return 0;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_demon_hunter_unending_hatred_AuraScript::CheckProc);
            OnProc += AuraProcFn(spell_demon_hunter_unending_hatred_AuraScript::Proc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_demon_hunter_unending_hatred_AuraScript();
    }
};

//203720 - Demon Spikes
class spell_dh_demon_spikes : public SpellScript
{
    PrepareSpellScript(spell_dh_demon_spikes);

    void HandleDummy()
    {
        Unit* caster = GetCaster();
        caster->CastSpell(nullptr, 203819, true);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_dh_demon_spikes::HandleDummy);
    }
};

class dh_shattered_souls : public PlayerScript
{
public:
    dh_shattered_souls() : PlayerScript("dh_shattered_souls") { }

    void OnCreatureKill(Player* player, Creature* victim) override
    {
        if (player->getClass() != CLASS_DEMON_HUNTER)
            return;

        Position fragmentPos = victim->GetRandomNearPosition(5.0f);

        if (victim->GetCreatureType() == CREATURE_TYPE_DEMON && roll_chance_f(30))
        {
            //player->CastSpell(nullptr, SPELL_DH_SHATTERED_SOULS_MISSILE, true);
            victim->CastSpell(nullptr, SPELL_DH_SHATTERED_SOULS_DEMON, true); //at
            player->CastSpell(nullptr, SPELL_DH_SOUL_FRAGMENT_DEMON_BONUS, true); //buff
        }

        if (victim->GetCreatureType() != CREATURE_TYPE_DEMON && roll_chance_f(30))
        {
            //victim->CastSpell(nullptr, SPELL_DH_SHATTERED_SOULS_MISSILE, true);
            player->CastSpell(fragmentPos, SPELL_DH_SHATTERED_SOULS, true); //10665
        }

        if (player->HasAura(SPELL_DH_FEED_THE_DEMON))
            player->GetSpellHistory()->ReduceChargeCooldown(sSpellMgr->GetSpellInfo(SPELL_DH_DEMON_SPIKES, DIFFICULTY_NONE)->ChargeCategoryId, 1000);

        if (player->HasAura(SPELL_DH_PAINBRINGER))
            player->CastSpell(player, SPELL_DH_PAINBRINGER_BUFF, true);

        if (AuraEffect* soulBarrier = player->GetAuraEffect(SPELL_DH_SOUL_BARRIER, EFFECT_0))
        {
            int32 amount = soulBarrier->GetAmount() + (float(sSpellMgr->GetSpellInfo(SPELL_DH_SOUL_BARRIER, DIFFICULTY_NONE)->GetEffect(EFFECT_1)->BasePoints) / 100.f) * player->GetTotalAttackPowerValue(BASE_ATTACK);
            soulBarrier->SetAmount(amount);
        }
    }
};

//201427
class spell_dh_annihilation : public SpellScript
{
    PrepareSpellScript(spell_dh_annihilation);

    void HandleHit(SpellMissInfo missInfo)
    {
        if (Unit* caster = GetCaster())
        {
            Unit* target = caster->GetVictim();
            if (!target)
                return;

            float attackPower = caster->GetTotalAttackPowerValue(BASE_ATTACK) + 28.7f;
            float damage = GetHitDamage();

            SetHitDamage(damage + attackPower);

            if (roll_chance_f(20))
                caster->ModifyPower(POWER_FURY, +20);
        }
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_dh_annihilation::HandleHit);
    }
};

//204255 normal, at 10665, 204256 demon, at 10666
struct at_shattered_soul_fragment : AreaTriggerAI
{
    at_shattered_soul_fragment(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit != at->GetCaster() || !unit->IsPlayer() || unit->ToPlayer()->getClass() != CLASS_DEMON_HUNTER)
            return;

        switch (at->GetEntry())
        {
        case 10665:
            if (at->GetCaster()->ToPlayer()->GetSpecializationId() == TALENT_SPEC_DEMON_HUNTER_HAVOC)
                at->GetCaster()->CastSpell(at->GetCaster(), SPELL_DH_SOUL_FRAGMENT_HEAL_25_HAVOC, true);
            at->Remove();
            break;

        case 10666:
            if (at->GetCaster()->ToPlayer()->GetSpecializationId() == TALENT_SPEC_DEMON_HUNTER_HAVOC)
                at->GetCaster()->CastSpell(at->GetCaster(), SPELL_DH_SOUL_FRAGMENT_HEAL_25_HAVOC, true);
            at->Remove();
            break;
        }
    }
};

//232893
class spell_dh_felblade : public SpellScript
{
    PrepareSpellScript(spell_dh_felblade);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        if (!GetCaster() || !GetHitUnit())
            return;

        if (GetCaster()->GetDistance2d(GetHitUnit()) <= 15.0f)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_DH_FELBLADE_CHARGE, true);
            GetCaster()->CastSpell(GetHitUnit(), SPELL_DH_FELBLADE_DAMAGE, true);
        }
    }

    void Register()
    {
        OnEffectHitTarget += SpellEffectFn(spell_dh_felblade::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_demon_hunter_spell_scripts()
{
    new spell_dh_fel_rush();
    new spell_dh_fel_rush_dash();
    new spell_dh_fel_rush_dash_ground();
    new spell_dh_eye_beam();
    new spell_dh_chaos_strike();
    new spell_dh_glide();
    new spell_dh_master_of_the_glaive();
    new spell_dh_fel_eruption();
    new spell_dh_last_resort();
    new spell_dh_metamorphosis();
    new spell_dh_metamorphosis_immunity();
    RegisterSpellScript(spell_dh_fel_rush_damage);
    new spell_dh_vengeful_retreat_damage();
    new spell_dh_first_blood();
    new spell_dh_bloodlet();
    new spell_dh_fel_barrage();
    new spell_dh_fel_barrage_damage();
    new spell_dh_fel_barrage_aura();
    new spell_dh_nemesis();
    RegisterSpellScript(spell_dh_infernal_strike);
    new spell_dh_soul_cleave();
    RegisterSpellScript(spell_dh_soul_cleave_damage);
    RegisterSpellScript(spell_dh_fiery_brand);
    RegisterAuraScript(spell_dh_fiery_brand_dot);
    new spell_dh_razor_spikes();
    new spell_dh_soul_barrier();
    new spell_dh_nether_bond();
    new spell_dh_nether_bond_periodic();
    new spell_dh_solitude();
    new spell_dh_awaken_the_demon();
    new spell_dh_reverse_magic();
    new spell_dh_eye_of_leotheras();
    RegisterSpellScript(spell_dh_immolation_aura);
    RegisterSpellScript(spell_dh_immolation_aura_damage);
    new spell_dh_jagged_spikes();
    new spell_dh_fel_lance();
    new spell_dh_intimidated();
    new spell_dh_blade_turning();
    new spell_dh_artifact_demon_speed();
    new spell_dh_artifact_deceivers_fury();
    new spell_dh_artifact_anguish();
    new spell_dh_artifact_anguish_damage();
    new spell_dh_shattered_souls_missile();
    new spell_dh_shear_proc();
    new spell_dh_consume_soul_missile();
    new spell_dh_darkness_absorb();
    new spell_dh_prepared();
    new spell_dh_demonic_appetite();
    new spell_dh_soul_fragment_heals();
    new spell_dh_chaos_cleave();
    new spell_dh_desperate_instincts();
    new spell_dh_fracture();
    new spell_dh_fel_devastation();
    new spell_dh_frailty();
    new spell_dh_spirit_bomb();
    new spell_dh_demonic_infusion();
    new spell_dh_artifact_inner_demons();
    new spell_dh_artifact_rage_of_the_illidari();
    new spell_dh_artifact_overwhelming_power();
    new spell_dh_artifact_soul_carver();
    new spell_dh_artifact_charred_warblades();
    new spell_dh_artifact_fueled_by_pain();
    new spell_dh_artifact_fiery_demise();
    new spell_demon_hunter_rain_from_above();
    new spell_demon_hunter_metamorphosis_buffs();
    new spell_demon_hunter_blade_dance_main();
    new spell_dh_fel_devastation_damage();
    RegisterSpellScript(spell_demon_hunter_chaos_strike);
    new spell_demon_hunter_eye_beam_damage();
    new spell_demon_hunter_pain();
    new spell_demon_hunter_mana_break();
    new spell_demon_hunter_trail_of_ruin();
    new spell_demon_hunter_unending_hatred();
    RegisterSpellScript(spell_dh_demon_spikes);
    RegisterAreaTriggerAI(at_dh_sigil_of_misery);
    RegisterAreaTriggerAI(at_dh_sigil_of_flame);
    RegisterAreaTriggerAI(at_dh_sigil_of_silence);
    RegisterAreaTriggerAI(at_dh_sigil_of_chains);
    RegisterAreaTriggerAI(at_dh_darkness);
    RegisterAreaTriggerAI(at_dh_artifact_fury_of_the_illidari);
    RegisterAreaTriggerAI(at_dh_artifact_inner_demons);
    RegisterAreaTriggerAI(at_demon_hunter_mana_rift);
    RegisterAreaTriggerAI(at_demon_hunter_demonic_trample);
    RegisterPlayerScript(dh_shattered_souls);
    RegisterSpellScript(spell_dh_annihilation);
    RegisterAreaTriggerAI(at_shattered_soul_fragment);
    RegisterSpellScript(spell_dh_felblade);
}
