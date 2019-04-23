/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_DEMON_HUNTER and SPELLFAMILY_GENERIC spells used by demon hunter players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dh_".
 */

#include <chrono>
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "ObjectAccessor.h"
#include "PathGenerator.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellPackets.h"
#include "TemporarySummon.h"
#include "Unit.h"
#include "World.h"

enum DHSpells
{
    SPELL_DH_ANNIHILATION                   = 201427,
    SPELL_DH_ANNIHILATION_MAINHAIND         = 201428,
    SPELL_DH_ANNIHILATION_OFFHAND           = 227518,
    SPELL_DH_BLADE_DANCE                    = 188499,
    SPELL_DH_BLIND_FURY                     = 203550,
    SPELL_DH_BLOODLET                       = 206473,
    SPELL_DH_BLOODLET_DOT                   = 207690,
    SPELL_DH_BLUR                           = 198589,
    SPELL_DH_BURNING_ALIVE                  = 207739,
    SPELL_DH_CHAOS_CLEAVE                   = 206475,
    SPELL_DH_CHAOS_CLEAVE_DAMAGE            = 236237,
    SPELL_DH_CHAOS_NOVA                     = 179057,
    SPELL_DH_CHAOS_STRIKE                   = 162794,
    SPELL_DH_CHAOS_STRIKE_MAIN_HAND         = 199547,
    SPELL_DH_CHAOS_STRIKE_OFF_HAND          = 222031,
    SPELL_DH_CHAOS_STRIKE_PROC              = 193840,
    SPELL_DH_CONSUME_MAGIC                  = 183752,
    SPELL_DH_CONSUME_SOUL_10                = 228532,
    SPELL_DH_CONSUME_SOUL_10_VENG           = 203794,
    SPELL_DH_CONSUME_SOUL_25                = 178963,
    SPELL_DH_CONSUME_SOUL_25_VENG           = 210042,
    SPELL_DH_CONSUME_SOUL_DEMON             = 202644,
    SPELL_DH_CONSUME_SOUL_DEMON_VENG        = 208015,
    SPELL_DH_CONSUME_SOUL_MISSILE           = 210047,
    SPELL_DH_DARKNESS_BUFF                  = 209426,
    SPELL_DH_DEMON_BLADES                   = 203555,
    SPELL_DH_DEMON_BLADES_TRIGGER           = 203796,
    SPELL_DH_DEMON_REBORN                   = 193897,
    SPELL_DH_DEMON_SPIKES                   = 203720,
    SPELL_DH_DEMON_SPIKES_BUFF              = 203819,
    SPELL_DH_DEMONIC                        = 213410,
    SPELL_DH_DEMONIC_APPETITE               = 206478,
    SPELL_DH_DEMONIC_APPETITE_FURY          = 210041,
    SPELL_DH_DEMONS_BITE                    = 162243,
    SPELL_DH_EYE_BEAM                       = 198013,
    SPELL_DH_EYE_BEAM_DAMAGE                = 198030,
    SPELL_DH_EYE_BEAM_VISUAL                = 194326,
    SPELL_DH_FEAST_OF_SOULS                 = 207697,
    SPELL_DH_FEAST_OF_SOULS_HEAL            = 207693,
    SPELL_DH_FEED_THE_DEMON                 = 218612,
    SPELL_DH_FEL_BARRAGE                    = 211053,
    SPELL_DH_FEL_BARRAGE_TRIGGER            = 211052,
    SPELL_DH_FEL_DEVASTATION_DAMAGE         = 212105,
    SPELL_DH_FEL_DEVASTATION_HEAL           = 212106,
    SPELL_DH_FEL_ERUPTION                   = 211881,
    SPELL_DH_FEL_ERUPTION_DAMAGE            = 225102,
    SPELL_DH_FEL_MASTERY                    = 192939,
    SPELL_DH_FEL_RUSH                       = 195072,
    SPELL_DH_FEL_RUSH_AIR                   = 197923,
    SPELL_DH_FEL_RUSH_DAMAGE                = 192611,
    SPELL_DH_FEL_RUSH_DASH                  = 197922,
    SPELL_DH_FEL_RUSH_DASH2                 = 208101,
    SPELL_DH_FELBLADE                       = 232893,
    SPELL_DH_FELBLADE_CHARGE                = 213241,
    SPELL_DH_FELBLADE_DAMAGE                = 213243,
    SPELL_DH_FIERY_BRAND_DOT                = 207771,
    SPELL_DH_FIRST_BLOOD                    = 206416,
    SPELL_DH_FLAME_CRASH                    = 227322,
    SPELL_DH_FRAILITY                       = 224509,
    SPELL_DH_GLIDE                          = 131347,
    SPELL_DH_GLIDE_KNOCKBACK                = 196353,
    SPELL_DH_GLUTTONY                       = 227327,
    SPELL_DH_GLUTTONY_BUFF                  = 227330,
    SPELL_DH_IMMOLATION_AURA                = 178740,
    SPELL_DH_IMMOLATION_AURA_VISUAL         = 201122,
    SPELL_DH_INFERNAL_STRIKE                = 189110,
    SPELL_DH_INFERNAL_STRIKE_DAMAGE         = 189112,
    SPELL_DH_INFERNAL_STRIKE_JUMP           = 189111,
    SPELL_DH_INFERNAL_STRIKE_VISUAL         = 208461,
    SPELL_DH_LAST_RESORT_DEBUFF             = 209261,
    SPELL_DH_METAMORPHOSIS                  = 191427,
    SPELL_DH_METAMORPHOSIS_BUFFS            = 162264,
    SPELL_DH_METAMORPHOSIS_IMMUNITY         = 201453,
    SPELL_DH_METAMORPHOSIS_LEAP             = 191428,
    SPELL_DH_METAMORPHOSIS_STUN             = 200166,
    SPELL_DH_METAMORPHOSIS_VENGEANCE        = 187827,
    SPELL_DH_MOMENTUM                       = 206476,
    SPELL_DH_MOMENTUM_BUFF                  = 208628,
    SPELL_DH_NEMESIS                        = 206491,
    SPELL_DH_NETHER_BOND                    = 207810,
    SPELL_DH_NETHER_BOND_DAMAGE             = 207812,
    SPELL_DH_NETHER_BOND_PERIODIC           = 207811,
    SPELL_DH_PREPARED                       = 203551,
    SPELL_DH_RAZOR_SPIKES_SLOW              = 210003,
    SPELL_DH_SHATTERED_SOULS                = 178940,
    SPELL_DH_SHATTERED_SOULS_AT_DEMON       = 203795,
    SPELL_DH_SHATTERED_SOULS_AT_NORMAL      = 228537,
    SPELL_DH_SHATTERED_SOULS_LESSER         = 204255,
    SPELL_DH_SHATTERED_SOULS_MISSILE        = 209651,
    SPELL_DH_SHEAR                          = 203782,
    SPELL_DH_SIGIL_OF_CHAINS_EXPLOSION      = 208673,
    SPELL_DH_SIGIL_OF_CHAINS_SLOW           = 204843,
    SPELL_DH_SIGIL_OF_CHAINS_TRIGGER        = 208674,
    SPELL_DH_SIGIL_OF_FLAME_EXPLOSION       = 208710,
    SPELL_DH_SIGIL_OF_FLAME_NO_DEST         = 204513,
    SPELL_DH_SIGIL_OF_FLAME_TRIGGER         = 204598,
    SPELL_DH_SIGIL_OF_MISERY_EXPLOSION      = 208714,
    SPELL_DH_SIGIL_OF_MISERY_TRIGGER        = 207685,
    SPELL_DH_SIGIL_OF_SILENCE_EXPLOSION     = 208709,
    SPELL_DH_SIGIL_OF_SILENCE_TRIGGER       = 204490,
    SPELL_DH_SOUL_BARRIER                   = 227225,
    SPELL_DH_SOUL_CLEAVE_DAMAGE             = 228478,
    SPELL_DH_SOUL_RENDING_HAVOC             = 204909,
    SPELL_DH_SOUL_RENDING_VENGEANCE         = 217996,
    SPELL_DH_SPIRIT_BOMB                    = 247454,
    SPELL_DH_SPIRIT_BOMB_DAMAGE             = 247455,
    SPELL_DH_SPIRIT_BOMB_HEAL               = 227255,
    SPELL_DH_THROW_GLAIVE                   = 185123,
    SPELL_DH_VENGEFUL_RETREAT               = 198793,
    SPELL_DH_VENGEFUL_RETREAT_FURY          = 203650,
    SPELL_DH_VENGEFUL_RETREAT_TRIGGER       = 198813,
};

enum NemesisTargets
{
    NEMESIS_ABERRATION                          = 208607,
    NEMESIS_ELEMENTAL                           = 208611,
    NEMESIS_MECHANICAL                          = 208616,
    NEMESIS_DRAGONKIN                           = 208610,
    NEMESIS_HUMANOID                            = 208605,
    NEMESIS_CRITTERS                            = 208609,
    NEMESIS_DEMONS                              = 208579,
    NEMESIS_GIANTS                              = 208612,
    NEMESIS_UNDEAD                              = 208614,
    NEMESIS_BEASTS                              = 208608
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
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_NETHER_BOND_DAMAGE) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_NETHER_BOND_PERIODIC))
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

            if (!m_BondUnit)
                m_BondUnit = GetBondUnit();

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

// Soul Barrier - 227225
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
                amount = 15 * player->GetUInt32Value(UNIT_FIELD_ATTACK_POWER);

            std::list<WorldObject*> units;
            Trinity::AllWorldObjectsInRange check(caster, 25.0f);
            Trinity::WorldObjectListSearcher<Trinity::AllWorldObjectsInRange> searcher(caster, units, check);
            Cell::VisitAllObjects(caster, searcher, 25.0f);

            for (WorldObject* obj : units)
            {
                if (obj->GetTypeId() != TYPEID_AREATRIGGER)
                    continue;

                AreaTrigger* at = obj->ToAreaTrigger();
                if (at->GetCaster() != caster)
                    continue;

                switch (at->GetEntry())
                {
                    case 8867:
                        caster->CastSpell(caster, SPELL_DH_CONSUME_SOUL_25_VENG, true);
                        break;
                    case 6710:
                        caster->CastSpell(caster, SPELL_DH_CONSUME_SOUL_DEMON_VENG, true);
                        break;
                    case 6007:
                        caster->CastSpell(caster, SPELL_DH_CONSUME_SOUL_10_VENG, true);
                        break;
                }
                at->SetDuration(0);
            }

            if (AuraApplication* app = caster->GetAuraApplication(SPELL_DH_SOUL_BARRIER))
                app->ClientUpdate();
        }

        void HandleAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            uint32 threshold = caster->GetUInt32Value(UNIT_FIELD_ATTACK_POWER) * 2;

            if (absorbAmount < dmgInfo.GetDamage())
                aurEff->SetAmount(absorbAmount+threshold);

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

// Fraility - 224509
class aura_dh_fraility : public AuraScript
{
    PrepareAuraScript(aura_dh_fraility);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_SPIRIT_BOMB_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        Unit* caster = aurEff->GetCaster();
        if (!caster || !eventInfo.GetDamageInfo())
            return;

        int32 healAmount = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), GetEffectInfo(EFFECT_0)->BasePoints);
        caster->CastCustomSpell(caster, SPELL_DH_SPIRIT_BOMB_HEAL, &healAmount, NULL, NULL, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(aura_dh_fraility::HandleProc, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// Spirit Bomb - 247454
class spell_dh_spirit_bomb : public SpellScript
{
    PrepareSpellScript(spell_dh_spirit_bomb);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_SPIRIT_BOMB, SPELL_DH_SPIRIT_BOMB_DAMAGE, SPELL_DH_SPIRIT_BOMB_HEAL });
    }

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return SPELL_FAILED_DONT_REPORT;

        float range = float(GetEffectInfo(EFFECT_0)->BasePoints);

        std::list<AreaTrigger*> ats;
        caster->GetAreaTriggerListWithSpellIDInRange(ats, SPELL_DH_SHATTERED_SOULS_AT_NORMAL, range);
        caster->GetAreaTriggerListWithSpellIDInRange(ats, SPELL_DH_SHATTERED_SOULS_AT_DEMON, range);
        caster->GetAreaTriggerListWithSpellIDInRange(ats, SPELL_DH_SHATTERED_SOULS_LESSER, range);

        _shatteredSoulsCount = ats.size();
        for (AreaTrigger* at : ats)
            at->SetDuration(0);

        return !_shatteredSoulsCount ? SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW: SPELL_CAST_OK;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            for (uint8 i = 0; i < _shatteredSoulsCount; ++i)
                caster->CastSpell(caster, SPELL_DH_SPIRIT_BOMB_DAMAGE, true);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dh_spirit_bomb::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_dh_spirit_bomb::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
private:
    uint8 _shatteredSoulsCount;
};

// Spirit Bomb damage - 247455
class spell_dh_spirit_bomb_damage : public SpellScript
{
    PrepareSpellScript(spell_dh_spirit_bomb_damage);

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Unit* target = GetHitUnit())
                caster->CastSpell(target, SPELL_DH_FRAILITY, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dh_spirit_bomb_damage::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Blade Turning - 203753
class spell_dh_blade_turning : public SpellScriptLoader
{
public:
    spell_dh_blade_turning() : SpellScriptLoader("spell_dh_blade_turning") {}

    class spell_dh_blade_turning_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_blade_turning_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetHitMask() & PROC_HIT_PARRY)
                return true;
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dh_blade_turning_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_blade_turning_AuraScript();
    }
};

// Fel Devastation - 212084
class spell_dh_fel_devastation : public SpellScriptLoader
{
public:
    spell_dh_fel_devastation() : SpellScriptLoader("spell_dh_fel_devastation") {}

    class spell_dh_fel_devastation_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_fel_devastation_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_FEL_DEVASTATION_DAMAGE) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_FEL_DEVASTATION_HEAL))
                return false;
            return true;
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_DH_FEL_DEVASTATION_DAMAGE, true);
            caster->CastSpell(caster, SPELL_DH_FEL_DEVASTATION_HEAL, true);
        }

        void Demorph(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->SetDisplayId(caster->GetNativeDisplayId());
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_fel_devastation_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            OnEffectRemove += AuraEffectRemoveFn(spell_dh_fel_devastation_AuraScript::Demorph, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    class spell_dh_fel_devastation_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_fel_devastation_SpellScript);

        void Morph()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->SetDisplayId(68671);
        }

        void Register() override
        {
            OnPrepare += SpellOnPrepareFn(spell_dh_fel_devastation_SpellScript::Morph);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_fel_devastation_SpellScript();
    }

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_fel_devastation_AuraScript();
    }
};

// Fracture - 209795
class spell_dh_fracture : public SpellScriptLoader
{
public:
    spell_dh_fracture() : SpellScriptLoader("spell_dh_fracture") {}

    class spell_dh_fracture_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_fracture_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                caster->CastCustomSpell(SPELL_DH_SHATTERED_SOULS_MISSILE, SpellValueMod(SPELLVALUE_TRIGGER_SPELL + EFFECT_1), SPELL_DH_SHATTERED_SOULS_LESSER, caster, TRIGGERED_FULL_MASK);
                caster->CastCustomSpell(SPELL_DH_SHATTERED_SOULS_MISSILE, SpellValueMod(SPELLVALUE_TRIGGER_SPELL + EFFECT_1), SPELL_DH_SHATTERED_SOULS_LESSER, caster, TRIGGERED_FULL_MASK);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_fracture_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_fracture_SpellScript();
    }
};


// Consume Soul vengeance - 210042, 203794, 208015
class spell_dh_consume_soul_vengeance : public SpellScriptLoader
{
public:
    spell_dh_consume_soul_vengeance() : SpellScriptLoader("spell_dh_consume_soul_vengeance") {}

    class spell_dh_consume_soul_vengeance_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_consume_soul_vengeance_SpellScript);

        void HandleCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->HasAura(SPELL_DH_GLUTTONY))
                caster->CastSpell(caster, SPELL_DH_GLUTTONY_BUFF, true);

            //if (caster->HasAura(SPELL_DH_FEED_THE_DEMON))
            //    caster->GetSpellHistory()->ReduceChargeCooldown(sSpellCategoryStore.LookupEntry(sSpellMgr->GetSpellInfo(SPELL_DH_DEMON_SPIKES)->ChargeCategoryId), 1 * IN_MILLISECONDS);

            if (Aura* soulBarrier = caster->GetAura(SPELL_DH_SOUL_BARRIER))
                if (AuraEffect* aurEff = soulBarrier->GetEffect(EFFECT_0))
                    aurEff->SetAmount((float)aurEff->GetAmount() + (float)caster->GetUInt32Value(UNIT_FIELD_ATTACK_POWER)*2.5f);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_dh_consume_soul_vengeance_SpellScript::HandleCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_consume_soul_vengeance_SpellScript();
    }
};

// Immolation Aura initial damage - 187727
class spell_dh_immolation_aura_damage : public SpellScriptLoader
{
public:
    spell_dh_immolation_aura_damage() : SpellScriptLoader("spell_dh_immolation_aura_damage") {}

    class spell_dh_immolation_aura_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_immolation_aura_damage_SpellScript);

        void HandleShatter(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (roll_chance_i(15))
                    caster->CastCustomSpell(SPELL_DH_SHATTERED_SOULS_MISSILE, SpellValueMod(SPELLVALUE_TRIGGER_SPELL + EFFECT_1), SPELL_DH_SHATTERED_SOULS_LESSER, caster, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_immolation_aura_damage_SpellScript::HandleShatter, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_immolation_aura_damage_SpellScript();
    }
};

// Feast of Souls heal - 207693
class spell_dh_feast_of_souls : public SpellScriptLoader
{
public:
    spell_dh_feast_of_souls() : SpellScriptLoader("spell_dh_feast_of_souls") {}

    class spell_dh_feast_of_souls_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_feast_of_souls_AuraScript);

        void CalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            if (Unit* caster = GetCaster())
                amount = caster->GetUInt32Value((UNIT_FIELD_ATTACK_POWER) / 100.0f) * 54.0f;
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_feast_of_souls_AuraScript::CalcAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_feast_of_souls_AuraScript();
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
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_RAZOR_SPIKES_SLOW))
                return false;
            return true;
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetDamageInfo() &&
                (eventInfo.GetDamageInfo()->GetAttackType() == BASE_ATTACK ||
                 eventInfo.GetDamageInfo()->GetAttackType() == OFF_ATTACK))
            {
                Unit* caster = eventInfo.GetDamageInfo()->GetAttacker();
                Unit* target = eventInfo.GetDamageInfo()->GetVictim();
                if (!caster || !target)
                    return false;

                if (caster->HasAura(SPELL_DH_DEMON_SPIKES_BUFF))
                    caster->CastSpell(target, SPELL_DH_RAZOR_SPIKES_SLOW, true);
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

// Soul Cleave - 228477
class spell_dh_soul_cleave : public SpellScriptLoader
{
public:
    spell_dh_soul_cleave() : SpellScriptLoader("spell_dh_soul_cleave") {}

    class spell_dh_soul_cleave_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_soul_cleave_SpellScript);

        int32 m_ExtraSpellCost;

        bool Load() override
        {
            if (Unit* caster = GetCaster())
            {
                m_ExtraSpellCost = std::min(caster->GetPower(POWER_PAIN), 600);
                return true;
            }
            return false;
        }

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_SOUL_CLEAVE_DAMAGE))
                return false;
            return true;
        }

        void HandleSouls(SpellEffIndex /*effindex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<WorldObject*> units;
            Trinity::AllWorldObjectsInRange check(caster, 25.f);
            Trinity::WorldObjectListSearcher<Trinity::AllWorldObjectsInRange> searcher(caster, units, check);
            Cell::VisitAllObjects(caster, searcher, 25.f);

            for (WorldObject* obj : units)
            {
                if (obj->GetTypeId() != TYPEID_AREATRIGGER)
                    continue;

                AreaTrigger* at = obj->ToAreaTrigger();
                if (at->GetCaster() != caster)
                    continue;

                int32 bp;
                switch (at->GetEntry())
                {
                case 8867:
                    bp = SPELL_DH_CONSUME_SOUL_25_VENG;
                    break;
                case 6710:
                    bp = SPELL_DH_CONSUME_SOUL_DEMON_VENG;
                    break;
                case 6007:
                    bp = SPELL_DH_CONSUME_SOUL_10_VENG;
                    break;
                }
                if (TempSummon* tempSumm = caster->SummonCreature(WORLD_TRIGGER, at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 200))
                {
                    tempSumm->setFaction(caster->getFaction());
                    tempSumm->SetGuidValue(UNIT_FIELD_SUMMONEDBY, caster->GetGUID());
                    PhasingHandler::InheritPhaseShift(tempSumm, caster);
                    caster->CastSpell(tempSumm, SPELL_DH_CONSUME_SOUL_MISSILE, true);
                }
                at->SetDuration(0);
            }
        }

        void HandleHeal(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->GetTypeId() != TYPEID_PLAYER)
                return;

            uint32 dmg = 11.0f * caster->GetUInt32Value(UNIT_FIELD_ATTACK_POWER);
            dmg = caster->SpellHealingBonusDone(caster, GetSpellInfo(), dmg, HEAL, GetSpellInfo()->GetEffect(EFFECT_3));
            dmg = (float)dmg * ((float)m_ExtraSpellCost / 600.0f);
            SetHitHeal(dmg);

            if (caster->HasAura(SPELL_DH_FEAST_OF_SOULS))
                caster->CastSpell(caster, SPELL_DH_FEAST_OF_SOULS_HEAL, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_soul_cleave_SpellScript::HandleSouls, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnEffectHitTarget += SpellEffectFn(spell_dh_soul_cleave_SpellScript::HandleHeal, EFFECT_3, SPELL_EFFECT_HEAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_soul_cleave_SpellScript();
    }
};

// Soul cleave damage - 228478
class spell_dh_soul_cleave_damage : public SpellScriptLoader
{
public:
    spell_dh_soul_cleave_damage() : SpellScriptLoader("spell_dh_soul_cleave_damage") {}

    class spell_dh_soul_cleave_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_soul_cleave_damage_SpellScript);

        int32 m_ExtraSpellCost;

        bool Load() override
        {
            if (Unit* caster = GetCaster())
            {
                m_ExtraSpellCost = std::min(caster->GetPower(POWER_PAIN), 300);
                return true;
            }
            return false;
        }

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            int32 dmg = GetHitDamage() * 2;
            dmg = (float)dmg * (((float)m_ExtraSpellCost + 300.0f) / 600.0f);
            SetHitDamage(dmg);

            caster->SetPower(POWER_PAIN, caster->GetPower(POWER_PAIN) - m_ExtraSpellCost);
            caster->ToPlayer()->SetPower(POWER_PAIN, caster->GetPower(POWER_PAIN) - m_ExtraSpellCost);
            if (caster->HasAura(SPELL_DH_GLUTTONY_BUFF))
                caster->RemoveAurasDueToSpell(SPELL_DH_GLUTTONY_BUFF);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_soul_cleave_damage_SpellScript::HandleDamage, EFFECT_1, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_soul_cleave_damage_SpellScript();
    }
};

// Shear Proc - 203783
class spell_dh_shear_proc : public SpellScriptLoader
{
public:
    spell_dh_shear_proc() : SpellScriptLoader("spell_dh_shear_proc") {}

    class spell_dh_shear_proc_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_shear_proc_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetSpellInfo()->Id == SPELL_DH_SHEAR)
                return true;
            return false;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();

            if (Unit* caster = GetCaster())
                if (roll_chance_i(20))
                    caster->CastCustomSpell(SPELL_DH_SHATTERED_SOULS_MISSILE, SpellValueMod(SPELLVALUE_TRIGGER_SPELL + EFFECT_1), SPELL_DH_SHATTERED_SOULS_LESSER, caster, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dh_shear_proc_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dh_shear_proc_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_shear_proc_AuraScript();
    }
};

// Fiery Brand - 204021
class spell_dh_fiery_brand : public SpellScriptLoader
{
public:
    spell_dh_fiery_brand() : SpellScriptLoader("spell_dh_fiery_brand") {}

    class spell_dh_fiery_brand_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_fiery_brand_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_FIERY_BRAND_DOT))
                return false;
            return true;
        }

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_DH_FIERY_BRAND_DOT, true);
            if (Aura* burningAlive = caster->GetAura(SPELL_DH_BURNING_ALIVE))
                burningAlive->Variables.Set("TargetGUID", target->GetGUID());
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_fiery_brand_SpellScript::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_fiery_brand_SpellScript();
    }
};

// Fiery Brand dot - 207771
class spell_dh_fiery_brand_dot : public SpellScriptLoader
{
public:
    spell_dh_fiery_brand_dot() : SpellScriptLoader("spell_dh_fiery_brand_dot") {}

    class spell_dh_fiery_brand_dot_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_fiery_brand_dot_AuraScript);

        void CalcAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
        {
            Unit* caster = aurEff->GetCaster();
            if (!caster->HasAura(SPELL_DH_BURNING_ALIVE))
                amount = 0;
        }

        void HandlePeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = aurEff->GetCaster();
            if (!caster || !caster->HasAura(SPELL_DH_BURNING_ALIVE))
                return;

            WorldObject* owner = GetOwner();
            if (!owner->ToUnit())
                return;

            if (Aura* burningAlive = caster->GetAura(SPELL_DH_BURNING_ALIVE))
            {
                ObjectGuid const originalTarget = burningAlive->Variables.GetValue<ObjectGuid>("TargetGUID");
                if (owner == ObjectAccessor::GetUnit(*caster, originalTarget))
                {
                    std::list<Unit*> nearbyUnits;
                    Trinity::AnyUnitInObjectRangeCheck checker(owner->ToUnit(), 8.0f);
                    Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(owner->ToUnit(), nearbyUnits, checker);
                    Cell::VisitAllObjects(caster, searcher, 100.0f);

                    for (Unit* unit : nearbyUnits)
                    {
                        if (unit->HasAura(SPELL_DH_FIERY_BRAND_DOT))
                            continue;

                        if (caster->IsValidAttackTarget(unit))
                        {
                            caster->CastSpell(unit, SPELL_DH_FIERY_BRAND_DOT, true);
                            burningAlive->RefreshDuration();
                            return;
                        }
                    }
                }
            }
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_fiery_brand_dot_AuraScript::CalcAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_fiery_brand_dot_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_fiery_brand_dot_AuraScript();
    }
};

// Fiery Brand aura - 204022
class spell_dh_fiery_brand_absorb : public SpellScriptLoader
{
public:
    spell_dh_fiery_brand_absorb() : SpellScriptLoader("spell_dh_fiery_brand_absorb") {}

    class spell_dh_fiery_brand_absorb_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_fiery_brand_absorb_AuraScript);

        void CalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void HandleAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            Unit* caster = aurEff->GetCaster();
            Unit* target = dmgInfo.GetAttacker();
            if (!caster || !target)
                return;

            if (target->HasAura(SPELL_DH_FIERY_BRAND_DOT))
                absorbAmount = CalculatePct(dmgInfo.GetDamage(), 40);
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_fiery_brand_absorb_AuraScript::CalcAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_dh_fiery_brand_absorb_AuraScript::HandleAbsorb, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_fiery_brand_absorb_AuraScript();
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
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_LAST_RESORT_DEBUFF))
                return false;
            return true;
        }

        void CalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void HandleAbsorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& /*absorbAmount*/)
        {
            Unit* target = GetTarget();

            if (dmgInfo.GetDamage() < target->GetHealth())
                return;

            if (target->HasAura(SPELL_DH_LAST_RESORT_DEBUFF))
                return;

            HealInfo healInfo(target, target, target->CountPctFromMaxHealth(30), GetSpellInfo(), GetSpellInfo()->GetSchoolMask());
            target->AddAura(SPELL_DH_METAMORPHOSIS_VENGEANCE, target);
            target->CastSpell(target, SPELL_DH_LAST_RESORT_DEBUFF, true);
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

// Shattered Souls - 178940 and 204254
class spell_dh_shattered_souls : public SpellScriptLoader
{
public:
    spell_dh_shattered_souls() : SpellScriptLoader("spell_dh_shattered_souls") {}

    class spell_dh_shattered_souls_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_shattered_souls_AuraScript);

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            Unit* target = eventInfo.GetActionTarget();
            if (!caster || !target)
                return;

            if (roll_chance_i(GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints))
            {
                uint32 triggerSpellId = 0;
                if (target->GetCreatureType() == CREATURE_TYPE_DEMON)
                    triggerSpellId = SPELL_DH_SHATTERED_SOULS_AT_DEMON;
                else
                    triggerSpellId = SPELL_DH_SHATTERED_SOULS_AT_NORMAL;

                caster->CastCustomSpell(SPELL_DH_SHATTERED_SOULS_MISSILE, SpellValueMod(SPELLVALUE_TRIGGER_SPELL + EFFECT_1), triggerSpellId, caster);
            }
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_shattered_souls_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_shattered_souls_AuraScript();
    }
};

// Blade Dance damaging abilities - 199552, 200685, 210153, 210155
class spell_dh_blade_dance : public SpellScriptLoader
{
public:
    spell_dh_blade_dance() : SpellScriptLoader("spell_dh_blade_dance") {}

    class spell_dh_blade_dance_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_blade_dance_SpellScript);

    public:

        spell_dh_blade_dance_SpellScript()
        {
            targetIndex = 0;
        }

    private:

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            int32 dmg = GetHitDamage();
            if (targetIndex == 0 && GetCaster()->HasAura(SPELL_DH_FIRST_BLOOD))
            {
                dmg *= 2;
            }
            SetHitDamage(dmg);
            targetIndex++;
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_blade_dance_SpellScript::HandleOnHit, EFFECT_1, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
        }

        int32 targetIndex;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_blade_dance_SpellScript();
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
            if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
                return;

            Unit* target = GetTargetApplication()->GetTarget();
            uint32 type = target->GetCreatureType();
            int32 dur = GetTargetApplication()->GetBase()->GetDuration();
            Unit* caster = GetAura()->GetCaster();

            switch (type)
            {
                case CREATURE_TYPE_ABERRATION:
                    caster->CastCustomSpell(caster, NEMESIS_ABERRATION, NULL, NULL, NULL, true);
                    if (Aura* nemesis = caster->GetAura(NEMESIS_ABERRATION))
                        nemesis->SetDuration(dur);
                    break;
                case CREATURE_TYPE_BEAST:
                    caster->CastCustomSpell(caster, NEMESIS_BEASTS, NULL, NULL, NULL, true);
                    if (Aura* nemesis = caster->GetAura(NEMESIS_BEASTS))
                        nemesis->SetDuration(dur);
                    break;
                case CREATURE_TYPE_CRITTER:
                    caster->CastCustomSpell(caster, NEMESIS_CRITTERS, NULL, NULL, NULL, true);
                    if (Aura* nemesis = caster->GetAura(NEMESIS_CRITTERS))
                        nemesis->SetDuration(dur);
                    break;
                case CREATURE_TYPE_DEMON:
                    caster->CastCustomSpell(caster, NEMESIS_DEMONS, NULL, NULL, NULL, true);
                    if (Aura* nemesis = caster->GetAura(NEMESIS_DEMONS))
                        nemesis->SetDuration(dur);
                    break;
                case CREATURE_TYPE_DRAGONKIN:
                    caster->CastCustomSpell(caster, NEMESIS_DRAGONKIN, NULL, NULL, NULL, true);
                    if (Aura* nemesis = caster->GetAura(NEMESIS_DRAGONKIN))
                        nemesis->SetDuration(dur);
                    break;
                case CREATURE_TYPE_ELEMENTAL:
                    caster->CastCustomSpell(caster, NEMESIS_ELEMENTAL, NULL, NULL, NULL, true);
                    if (Aura* nemesis = caster->GetAura(NEMESIS_ELEMENTAL))
                        nemesis->SetDuration(dur);
                    break;
                case CREATURE_TYPE_GIANT:
                    caster->CastCustomSpell(caster, NEMESIS_GIANTS, NULL, NULL, NULL, true);
                    if (Aura* nemesis = caster->GetAura(NEMESIS_GIANTS))
                        nemesis->SetDuration(dur);
                    break;
                case CREATURE_TYPE_HUMANOID:
                    caster->CastCustomSpell(caster, NEMESIS_HUMANOID, NULL, NULL, NULL, true);
                    if (Aura* nemesis = caster->GetAura(NEMESIS_HUMANOID))
                        nemesis->SetDuration(dur);
                    break;
                case CREATURE_TYPE_MECHANICAL:
                    caster->CastCustomSpell(caster, NEMESIS_MECHANICAL, NULL, NULL, NULL, true);
                    if (Aura* nemesis = caster->GetAura(NEMESIS_MECHANICAL))
                        nemesis->SetDuration(dur);
                    break;
                case CREATURE_TYPE_UNDEAD:
                    caster->CastCustomSpell(caster, NEMESIS_UNDEAD, NULL, NULL, NULL, true);
                    if (Aura* nemesis = caster->GetAura(NEMESIS_UNDEAD))
                        nemesis->SetDuration(dur);
                    break;
                default:
                    break;
            }
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_dh_nemesis_AuraScript::HandleAfterRemove, EFFECT_0, 270, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_nemesis_AuraScript();
    }
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
            int32 dmg = int32((eventInfo.GetDamageInfo()->GetDamage()*2)/5);
            if (AuraEffect* dot = target->GetAuraEffect(SPELL_DH_BLOODLET_DOT, EFFECT_0, caster->GetGUID()))
            {
                dmg += (dot->GetAmount() * (dot->GetTotalTicks() - dot->GetTickNumber())) / 5;
            }

            caster->CastCustomSpell(target, SPELL_DH_BLOODLET_DOT, &dmg, NULL, NULL, true);
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

// Demon Blades - 203555
class spell_dh_demon_blades : public SpellScriptLoader
{
public:
    spell_dh_demon_blades() : SpellScriptLoader("spell_dh_demon_blades") {}

    class spell_dh_demon_blades_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_demon_blades_AuraScript);

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            Unit* target = eventInfo.GetActionTarget();

            if(roll_chance_i(sSpellMgr->GetSpellInfo(SPELL_DH_DEMON_BLADES)->GetEffect(0)->BasePoints))
                caster->CastSpell(target, SPELL_DH_DEMON_BLADES_TRIGGER, true);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_demon_blades_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_demon_blades_AuraScript();
    }
};

// Felblade reset aura - 203557
class spell_dh_felblade_reset : public SpellScriptLoader
{
public:
    spell_dh_felblade_reset() : SpellScriptLoader("spell_dh_felblade_reset") {}

    class spell_dh_felblade_reset_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_felblade_reset_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetSpellInfo()->Id == SPELL_DH_DEMONS_BITE ||
                eventInfo.GetSpellInfo()->Id == SPELL_DH_SHEAR ||
                eventInfo.GetSpellInfo()->Id == SPELL_DH_DEMON_BLADES_TRIGGER)
                return true;
            return false;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            Unit* caster = GetCaster();
            caster->GetSpellHistory()->ResetCooldown(SPELL_DH_FELBLADE, true);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dh_felblade_reset_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dh_felblade_reset_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_felblade_reset_AuraScript();
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

    public:

        spell_dh_fel_barrage_AuraScript()
        {
            _charges = 1;
        }

    private:

        int32 _charges;

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_FEL_BARRAGE) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_FEL_BARRAGE_TRIGGER))
                return false;
            return true;
        }

        bool Load() override
        {
            _charges = GetCaster()->GetSpellHistory()->GetChargeCount(sSpellMgr->GetSpellInfo(SPELL_DH_FEL_BARRAGE)->ChargeCategoryId);
            return true;
        }

        void HandleTrigger(AuraEffect const* /*aurEff*/)
        {
            GetCaster()->CastCustomSpell(GetTarget(), SPELL_DH_FEL_BARRAGE_TRIGGER, &_charges, NULL, NULL, true);
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

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            int32 chargesUsed = GetSpellValue()->EffectBasePoints[0];
            int32 dmg = GetHitDamage();
            SetHitDamage((dmg*chargesUsed)/5);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_fel_barrage_damage_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
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
            std::vector<uint32> removeSpellIds{ 199552, 210153, 222031, 227518, 211052, 198030 };
            return std::find(removeSpellIds.begin(), removeSpellIds.end(), eventInfo.GetSpellInfo()->Id) == removeSpellIds.end();
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();

            Unit* caster = GetCaster();
            if (!caster)
                return;

            int32 chargeCatId = sSpellMgr->GetSpellInfo(SPELL_DH_FEL_BARRAGE)->ChargeCategoryId;
            if (SpellCategoryEntry const* barrage = sSpellCategoryStore.LookupEntry(chargeCatId))
            {
                caster->GetSpellHistory()->RestoreCharge(chargeCatId);
                caster->GetSpellHistory()->ForceSendSetSpellCharges(barrage);
            }
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dh_fel_barrage_aura_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dh_fel_barrage_aura_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_fel_barrage_aura_AuraScript();
    }
};


// Annihilation - 201427
class spell_dh_annihilation : public SpellScriptLoader
{
public:
    spell_dh_annihilation() : SpellScriptLoader("spell_dh_annihilation") {}

    class spell_dh_annihilation_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_annihilation_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_ANNIHILATION) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_ANNIHILATION_MAINHAIND) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_ANNIHILATION_OFFHAND))
                return false;
            return true;
        }

        void PreventMainhandEffect(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();

            caster->CastSpell(target, SPELL_DH_ANNIHILATION_MAINHAIND, true);
        }

        void PreventOffhandEffect(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();

            caster->CastSpell(target, SPELL_DH_ANNIHILATION_OFFHAND, true);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_dh_annihilation_SpellScript::PreventMainhandEffect, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectHit += SpellEffectFn(spell_dh_annihilation_SpellScript::PreventOffhandEffect, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_annihilation_SpellScript();
    }
};

// Annihilation mainhand damge and offhand damage - 201428, 227518
class spell_dh_annihilation_damage : public SpellScriptLoader
{
public:
    spell_dh_annihilation_damage() : SpellScriptLoader("spell_dh_annihilation_damage") {}

    class spell_dh_annihilation_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_annihilation_damage_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (caster == target)
                PreventHitDamage();
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_annihilation_damage_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
            OnEffectHitTarget += SpellEffectFn(spell_dh_annihilation_damage_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_WEAPON_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_annihilation_damage_SpellScript();
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

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_DH_FEL_ERUPTION, SPELL_DH_FEL_ERUPTION_DAMAGE });
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();

            caster->CastSpell(target, SPELL_DH_FEL_ERUPTION_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_fel_eruption_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_fel_eruption_SpellScript();
    }
};

// Immolation aura - 178740
class spell_dh_immolation_aura : public SpellScriptLoader
{
public:
    spell_dh_immolation_aura() : SpellScriptLoader("spell_dh_immolation_aura") {}

    class spell_dh_immolation_aura_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_immolation_aura_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_IMMOLATION_AURA) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_IMMOLATION_AURA_VISUAL))
                return false;
            return true;
        }

        void ApplyVisual(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_DH_IMMOLATION_AURA_VISUAL, true);

            if (Aura* imm = caster->GetAura(SPELL_DH_IMMOLATION_AURA_VISUAL))
            {
                imm->SetDuration(6000); //it's 10 seconds otherwise.
                caster->RemoveVisibleAura(imm->GetApplicationOfTarget(caster->GetGUID()));
            }
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_dh_immolation_aura_SpellScript::ApplyVisual, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_immolation_aura_SpellScript();
    }
};

// Vengeful retreat trigger - 198813
class spell_dh_vengeful_retreat_trigger : public SpellScriptLoader
{
public:
    spell_dh_vengeful_retreat_trigger() : SpellScriptLoader("spell_dh_vengeful_retreat_trigger") {}

    class spell_dh_vengeful_retreat_trigger_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_vengeful_retreat_trigger_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_VENGEFUL_RETREAT) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_VENGEFUL_RETREAT_FURY))
                return false;
            return true;
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();

            if (caster->HasAura(SPELL_DH_PREPARED) && !caster->HasAura(SPELL_DH_VENGEFUL_RETREAT_FURY))
            {
                caster->CastSpell(caster, SPELL_DH_VENGEFUL_RETREAT_FURY, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_vengeful_retreat_trigger_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_vengeful_retreat_trigger_SpellScript();
    }
};

// Prepare refiller - 203650
class spell_dh_vengeful_retreat_fury_refiller : public SpellScriptLoader
{
public:
    spell_dh_vengeful_retreat_fury_refiller() : SpellScriptLoader("spell_dh_vengeful_retreat_fury_refiller") {}

    class spell_dh_vengeful_retreat_fury_refiller_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_vengeful_retreat_fury_refiller_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_VENGEFUL_RETREAT_FURY))
                return false;
            return true;
        }

        void Energize(AuraEffect const* /*aurEff*/)
        {
            PreventDefaultAction();

            Unit* caster = GetCaster();
            int32 fury = caster->GetPower(POWER_FURY);

            if (fury + 4 < caster->GetMaxPower(POWER_FURY))
            {
                caster->SetPower(POWER_FURY, fury + 4);
            }
            else
            {
                caster->SetPower(POWER_FURY, caster->GetMaxPower(POWER_FURY));
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_vengeful_retreat_fury_refiller_AuraScript::Energize, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_vengeful_retreat_fury_refiller_AuraScript();
    }
};

// Vengeful retreat - 198793
class spell_dh_vengeful_retreat : public SpellScriptLoader
{
public:
    spell_dh_vengeful_retreat() : SpellScriptLoader("spell_dh_vengeful_retreat") {}

    class spell_dh_vengeful_retreat_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_vengeful_retreat_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_VENGEFUL_RETREAT))
                return false;
            return true;
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();

            if (caster->HasAura(SPELL_DH_MOMENTUM))
                caster->CastSpell(caster, SPELL_DH_MOMENTUM_BUFF, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_vengeful_retreat_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_vengeful_retreat_SpellScript();
    }
};

// Demon Spikes - 203720
class spell_dh_demon_spikes : public SpellScriptLoader
{
public:
    spell_dh_demon_spikes() : SpellScriptLoader("spell_dh_demon_spikes") {}

    class spell_dh_demon_spikes_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_demon_spikes_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_DEMON_SPIKES) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_DEMON_SPIKES_BUFF))
                return false;
            return true;
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (!caster->ToPlayer())
                return;
            caster->CastSpell(caster, SPELL_DH_DEMON_SPIKES_BUFF, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_demon_spikes_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_demon_spikes_SpellScript();
    }
};

// Demon Spikes buff - 203819
class spell_dh_demon_spikes_buff : public SpellScriptLoader
{
public:
    spell_dh_demon_spikes_buff() : SpellScriptLoader("spell_dh_demon_spikes_buff") {}

    class spell_dh_demon_spikes_buff_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_demon_spikes_buff_AuraScript);

        void CalcAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
        {
            Unit* caster = aurEff->GetCaster();
            if (!caster)
                return;

            amount -= std::ceil(caster->GetFloatValue(ACTIVE_PLAYER_FIELD_MASTERY));
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_demon_spikes_buff_AuraScript::CalcAmount, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_demon_spikes_buff_AuraScript();
    }
};

// Fel Mastery - 192939
class spell_dh_fel_mastery : public SpellScriptLoader
{
public:
    spell_dh_fel_mastery() : SpellScriptLoader("spell_dh_fel_mastery") {}

    class spell_dh_fel_mastery_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_fel_mastery_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            return (eventInfo.GetSpellInfo()->Id == SPELL_DH_FEL_RUSH_DAMAGE);
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (Player* player = caster->ToPlayer())
            {
                int32 fury = caster->GetPower(POWER_FURY);
                int32 amountToAdd = GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints;
                if (fury + amountToAdd < caster->GetMaxPower(POWER_FURY))
                    caster->SetPower(POWER_FURY, fury + amountToAdd);
                else
                    caster->SetPower(POWER_FURY, caster->GetMaxPower(POWER_FURY));

                player->SetPower(POWER_FURY, caster->GetPower(POWER_FURY));
            }

        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dh_fel_mastery_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dh_fel_mastery_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_fel_mastery_AuraScript();
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
            {
                caster->SetDisableGravity(false);
                caster->SetFall(true);
                caster->SendSetPlayHoverAnim(false);
            }
        }

        void CalcSpeed(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = 1400;
        }

        void Register() override
        {
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
            return ValidateSpellInfo({ SPELL_DH_FEL_RUSH_DASH, SPELL_DH_FEL_RUSH_AIR });
        }

        void HandleDashGround(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster->IsFalling() || caster->IsInWater())
                {
                    caster->CastSpell(caster, SPELL_DH_FEL_RUSH_DASH, true);
                    caster->CastSpell(caster, SPELL_DH_FEL_RUSH_DAMAGE, true);
                }
                if (caster->HasAura(SPELL_DH_MOMENTUM))
                    caster->CastSpell(caster, SPELL_DH_MOMENTUM_BUFF, true);
            }
        }

        void HandleDashAir(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->IsFalling())
                {
                    caster->SetDisableGravity(true);
                    caster->CastSpell(caster, SPELL_DH_FEL_RUSH_AIR, true);
                    caster->CastSpell(caster, SPELL_DH_FEL_RUSH_DAMAGE, true);
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

// Metamorphosis buffs (for Soul Rending - 204909) - 162264
class spell_dh_metamorphosis_buffs : public SpellScriptLoader
{
public:
    spell_dh_metamorphosis_buffs() : SpellScriptLoader("spell_dh_metamorphosis_buffs") {}

    class spell_dh_metamorphosis_buffs_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_metamorphosis_buffs_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_METAMORPHOSIS))
                return false;
            return true;
        }

        void CalcLeech(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->HasAura(SPELL_DH_SOUL_RENDING_HAVOC))
                amount += 100;
            else
                amount += 30;
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_metamorphosis_buffs_AuraScript::CalcLeech, EFFECT_3, SPELL_AURA_MOD_LEECH);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_metamorphosis_buffs_AuraScript();
    }
};

// Metamorphosis (vengeance) buffs - 187827
class spell_dh_metamorphosis_buffs_veng : public SpellScriptLoader
{
public:
    spell_dh_metamorphosis_buffs_veng() : SpellScriptLoader("spell_dh_metamorphosis_buffs_veng") {}

    class spell_dh_metamorphosis_buffs_veng_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_metamorphosis_buffs_veng_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_METAMORPHOSIS))
                return false;
            return true;
        }

        void CalcLeech(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->HasAura(SPELL_DH_SOUL_RENDING_VENGEANCE))
                amount += 50;
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_metamorphosis_buffs_veng_AuraScript::CalcLeech, EFFECT_2, SPELL_AURA_MOD_LEECH);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_metamorphosis_buffs_veng_AuraScript();
    }
};

// Metamorphosis - 191427
class spell_dh_metamorphosis : public SpellScriptLoader
{
public:
    spell_dh_metamorphosis() : SpellScriptLoader("spell_dh_metamorphosis") {}

    class spell_dh_metamorphosis_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_metamorphosis_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_METAMORPHOSIS) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_METAMORPHOSIS_BUFFS) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_METAMORPHOSIS_LEAP) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_METAMORPHOSIS_STUN))
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
                player->CastSpell(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), SPELL_DH_METAMORPHOSIS_LEAP, false);

            if (player->HasAura(SPELL_DH_DEMON_REBORN)) // Remove cd of chaos nova, blur and eye beam
            {
                player->GetSpellHistory()->ResetCooldown(SPELL_DH_CHAOS_NOVA, true);
                player->GetSpellHistory()->ResetCharges(sSpellMgr->GetSpellInfo(SPELL_DH_BLUR)->ChargeCategoryId);
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
class spell_dh_metamorphosis_immunity : public SpellScript
{
    PrepareSpellScript(spell_dh_metamorphosis_immunity);

    void PreventImmunity(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            if (caster->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == TALENT_SPEC_DEMON_HUNTER_VENGEANCE)
                PreventHitEffect(effIndex);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_dh_metamorphosis_immunity::PreventImmunity, EFFECT_1, SPELL_AURA_SCHOOL_IMMUNITY);
        OnEffectHit    += SpellEffectFn(spell_dh_metamorphosis_immunity::PreventImmunity, EFFECT_1, SPELL_AURA_SCHOOL_IMMUNITY);
    }
};

// Metamorphosis temporary immunity - 201453
class aura_dh_metamorphosis_immunity : public AuraScript
{
    PrepareAuraScript(aura_dh_metamorphosis_immunity);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_METAMORPHOSIS });
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (caster->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == TALENT_SPEC_DEMON_HUNTER_VENGEANCE)
                GetAura()->SetDuration(750);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == TALENT_SPEC_DEMON_HUNTER_HAVOC)
            caster->CastSpell(caster, SPELL_DH_METAMORPHOSIS_STUN, true);
        else
        {
            caster->CastSpell(caster, SPELL_DH_INFERNAL_STRIKE_DAMAGE, true);
            if (caster->HasAura(SPELL_DH_FLAME_CRASH))
                caster->CastSpell(caster, SPELL_DH_SIGIL_OF_FLAME_NO_DEST, true);
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(aura_dh_metamorphosis_immunity::HandleApply, EFFECT_1, SPELL_AURA_ALLOW_ONLY_ABILITY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(aura_dh_metamorphosis_immunity::HandleRemove, EFFECT_1, SPELL_AURA_ALLOW_ONLY_ABILITY, AURA_EFFECT_HANDLE_REAL);
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

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_EYE_BEAM) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_EYE_BEAM_DAMAGE))
                return false;
            return true;
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            caster->CastSpell(caster, SPELL_DH_EYE_BEAM_DAMAGE, true);
        }

        void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();

            caster->RemoveAurasDueToSpell(SPELL_DH_EYE_BEAM_VISUAL);

            if (caster->HasAura(SPELL_DH_DEMONIC) && !caster->HasAura(SPELL_DH_METAMORPHOSIS_BUFFS)) //Eye Beam causes you to enter demon form for 5 sec after it finishes dealing damage.
            {
                caster->CastSpell(caster, SPELL_DH_METAMORPHOSIS_BUFFS, true); // Metamorphosis
                if (Aura* aur = caster->GetAura(SPELL_DH_METAMORPHOSIS_BUFFS))
                    aur->SetDuration(8000);
            }
        }

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            caster->CastSpell(caster, SPELL_DH_EYE_BEAM_VISUAL, true);
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

// Eye Beam Trigger - 197640
class spell_dh_eye_beam_trigger : public SpellScriptLoader
{
public:
    spell_dh_eye_beam_trigger() : SpellScriptLoader("spell_dh_eye_beam_trigger") {}

    class spell_dh_eye_beam_trigger_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_eye_beam_trigger_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_EYE_BEAM) ||
                !sSpellMgr->GetSpellInfo(SPELL_DH_EYE_BEAM_DAMAGE))
                return false;
            return true;
        }

        void PreventHit(SpellEffIndex /*effIndex*/)
        {
            PreventHitDamage();
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dh_eye_beam_trigger_SpellScript::PreventHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_eye_beam_trigger_SpellScript();
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

// npc 999999
/// TODO: move this to scripts/World when they will be compiled
class npc_dh_spell_trainer : public CreatureScript
{
public:
    npc_dh_spell_trainer() : CreatureScript("npc_dh_spell_trainer") {}

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) != TALENT_SPEC_DEMON_HUNTER_HAVOC)
            return false;
        if (player->getLevel() < 99)
            return false;
        AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "Teach me!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "Close", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();

        std::vector<int32> spellIds
        {
            SPELL_DH_CHAOS_NOVA, SPELL_DH_CONSUME_MAGIC, SPELL_DH_THROW_GLAIVE, SPELL_DH_METAMORPHOSIS,
            SPELL_DH_EYE_BEAM, SPELL_DH_BLUR, SPELL_DH_VENGEFUL_RETREAT, SPELL_DH_BLADE_DANCE
        };

        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF + 1:
                for (auto spell : spellIds)
                {
                    if (sSpellMgr->GetSpellInfo(spell) && !player->HasSpell(spell))
                        player->LearnSpell(spell, false);
                }
                CloseGossipMenuFor(player);
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                CloseGossipMenuFor(player);
                break;
        }
        return true;
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
            return ValidateSpellInfo({ SPELL_DH_CHAOS_STRIKE_PROC });
        }

        void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();

            if (Unit* caster = GetCaster())
                caster->CastCustomSpell(SPELL_DH_CHAOS_STRIKE_PROC, SPELLVALUE_BASE_POINT0, aurEff->GetBaseAmount(), caster);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_chaos_strike_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_chaos_strike_AuraScript();
    }
};

// Consume Soul - 178963, 203794 and 228532
class spell_dh_consume_soul : public SpellScriptLoader
{
public:
    spell_dh_consume_soul() : SpellScriptLoader("spell_dh_consume_soul") {}

    class spell_dh_consume_soul_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dh_consume_soul_SpellScript);

        void PreventPower(SpellEffIndex effIndex)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (!caster->HasAura(SPELL_DH_DEMONIC_APPETITE))
                PreventHitEffect(effIndex);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_dh_consume_soul_SpellScript::PreventPower, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectHitTarget += SpellEffectFn(spell_dh_consume_soul_SpellScript::PreventPower, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectLaunch += SpellEffectFn(spell_dh_consume_soul_SpellScript::PreventPower, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectLaunchTarget += SpellEffectFn(spell_dh_consume_soul_SpellScript::PreventPower, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_consume_soul_SpellScript();
    }
};

// Demonic Appetite - 206478
class spell_dh_demonic_appetite : public SpellScriptLoader
{
public:
    spell_dh_demonic_appetite() : SpellScriptLoader("spell_dh_demonic_appetite") {}

    class spell_dh_demonic_appetite_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_demonic_appetite_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetSpellInfo()->Id == SPELL_DH_CHAOS_STRIKE_MAIN_HAND ||
                eventInfo.GetSpellInfo()->Id == SPELL_DH_ANNIHILATION_MAINHAIND)
                return true;
            return false;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();

            if (Unit* caster = GetCaster())
                caster->CastCustomSpell(SPELL_DH_SHATTERED_SOULS_MISSILE, SpellValueMod(SPELLVALUE_TRIGGER_SPELL + EFFECT_1), SPELL_DH_SHATTERED_SOULS_LESSER, caster, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dh_demonic_appetite_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dh_demonic_appetite_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_demonic_appetite_AuraScript();
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

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DH_GLIDE))
                return false;
            return true;
        }

        SpellCastResult CheckCast()
        {
            if (!GetCaster()->IsFalling())
                return SPELL_FAILED_NOT_ON_GROUND;

            return SPELL_CAST_OK;
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            caster->CastSpell(caster, SPELL_DH_GLIDE_KNOCKBACK, true);
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_dh_glide_SpellScript::CheckCast);
            OnEffectHitTarget += SpellEffectFn(spell_dh_glide_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dh_glide_SpellScript();
    }
};

// Darkness absorb - 209426
class spell_dh_darkness_absorb : public SpellScriptLoader
{
public:
    spell_dh_darkness_absorb() : SpellScriptLoader("spell_dh_darkness_absorb") {}

    class spell_dh_darkness_absorb_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_darkness_absorb_AuraScript);

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = std::numeric_limits<int32>::max();
        }

        void HandleAbsorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            int32 absorbChance = GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints;

            if (roll_chance_i(absorbChance))
                absorbAmount = dmgInfo.GetDamage();
            else
                absorbAmount = 0;
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_darkness_absorb_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_dh_darkness_absorb_AuraScript::HandleAbsorb, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_darkness_absorb_AuraScript();
    }
};

// Infernal Strike - 189110
class spell_dh_infernal_strike : public SpellScript
{
    PrepareSpellScript(spell_dh_infernal_strike);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_INFERNAL_STRIKE_JUMP, SPELL_DH_INFERNAL_STRIKE_DAMAGE });
    }

    SpellCastResult CheckDestination()
    {
        if (WorldLocation const* dest = GetExplTargetDest())
        {
            if (GetCaster()->HasUnitMovementFlag(MOVEMENTFLAG_ROOT))
                return SPELL_FAILED_ROOTED;

            if (GetCaster()->GetMap()->Instanceable())
            {
                float range = GetSpellInfo()->GetMaxRange(true, GetCaster()) * 1.5f;

                PathGenerator generatedPath(GetCaster());
                generatedPath.SetPathLengthLimit(range);

                bool result = generatedPath.CalculatePath(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), false, true);
                if (generatedPath.GetPathType() & PATHFIND_SHORT)
                    return SPELL_FAILED_OUT_OF_RANGE;
                else if (!result || generatedPath.GetPathType() & PATHFIND_NOPATH)
                {
                    result = generatedPath.CalculatePath(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), false, false);
                    if (generatedPath.GetPathType() & PATHFIND_SHORT)
                        return SPELL_FAILED_OUT_OF_RANGE;
                    else if (!result || generatedPath.GetPathType() & PATHFIND_NOPATH)
                        return SPELL_FAILED_NOPATH;
                }
            }
            else if (dest->GetPositionZ() > GetCaster()->GetPositionZ() + 4.0f)
                return SPELL_FAILED_NOPATH;

            return SPELL_CAST_OK;
        }

        return SPELL_FAILED_NO_VALID_TARGETS;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        WorldLocation const* dest = GetHitDest();
        if (!caster || !dest)
            return;

        caster->CastSpell(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), SPELL_DH_INFERNAL_STRIKE_JUMP, true);
        caster->CastSpell(caster, SPELL_DH_INFERNAL_STRIKE_VISUAL, true);
    }

    void HandleAfterDamage()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_DH_METAMORPHOSIS_IMMUNITY, true);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dh_infernal_strike::CheckDestination);
        OnEffectHit += SpellEffectFn(spell_dh_infernal_strike::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnCast += SpellCastFn(spell_dh_infernal_strike::HandleAfterDamage);
    }
};

// Felblade - 232893
class spell_dh_felblade : public SpellScript
{
    PrepareSpellScript(spell_dh_felblade);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FELBLADE_CHARGE });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, SPELL_DH_FELBLADE_CHARGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dh_felblade::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Sigil of Misery fear - 207685
class spell_dh_sigil_of_misery_fear : public SpellScriptLoader
{
public:
    spell_dh_sigil_of_misery_fear() : SpellScriptLoader("spell_dh_sigil_of_misery_fear") {}

    class spell_dh_sigil_of_misery_fear_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_sigil_of_misery_fear_AuraScript);

        bool Load() override
        {
            if (Aura* fear = GetAura())
                fear->Variables.Set("damage", uint64(0));
            return true;
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            Unit* target = eventInfo.GetActionTarget();
            if (!target)
                return false;

            if (!eventInfo.GetDamageInfo())
                return false;

            if (Aura* fear = GetAura())
            {
                uint64 dmg = fear->Variables.GetValue<uint64>("damage", 0);
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
            DoCheckProc += AuraCheckProcFn(spell_dh_sigil_of_misery_fear_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_sigil_of_misery_fear_AuraScript();
    }
};

// 206475
class aura_dh_chaos_cleave : public AuraScript
{
    PrepareAuraScript(aura_dh_chaos_cleave);

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        int32 bp = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), 10);
        GetTarget()->CastCustomSpell(nullptr, SPELL_DH_CHAOS_CLEAVE_DAMAGE, &bp, nullptr, nullptr, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(aura_dh_chaos_cleave::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// Sigil of Misery - 207684
// AreaTriggerID - 11023
struct at_dh_sigil_of_misery : AreaTriggerAI
{
    at_dh_sigil_of_misery(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
        {
            caster->CastSpell(at->GetPosition(), SPELL_DH_SIGIL_OF_MISERY_TRIGGER, true);
            caster->CastSpell(at->GetPosition(), SPELL_DH_SIGIL_OF_MISERY_EXPLOSION, true);
        }
    }
};

// Sigil of Flame - 204596
// AreaTriggerID - 10727
struct at_dh_sigil_of_flame : AreaTriggerAI
{
    at_dh_sigil_of_flame(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
        {
            caster->CastSpell(at->GetPosition(), SPELL_DH_SIGIL_OF_FLAME_TRIGGER, true);
            caster->CastSpell(at->GetPosition(), SPELL_DH_SIGIL_OF_FLAME_EXPLOSION, true);
        }
    }
};

// Sigil of Chains - 202138
// AreaTriggerID - 10718
struct at_dh_sigil_of_chains : AreaTriggerAI
{
    at_dh_sigil_of_chains(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnRemove() override
    {
        Unit* caster = at->GetCaster();
        if (!caster || !caster->IsPlayer())
            return;

        caster->CastSpell(at->GetPosition(), SPELL_DH_SIGIL_OF_CHAINS_EXPLOSION, true);

        GuidUnorderedSet const& objects = at->GetInsideUnits();
        for (ObjectGuid objguid : objects)
        {
            if (Unit* unit = ObjectAccessor::GetUnit(*caster, objguid))
            {
                if (caster->IsValidAttackTarget(unit))
                {
                    caster->CastSpell(unit, SPELL_DH_SIGIL_OF_CHAINS_SLOW, true);
                    unit->CastSpell(at->GetPosition(), SPELL_DH_SIGIL_OF_CHAINS_TRIGGER, true);
                }
            }
        }
    }
};

// Darkness - 196718
// AreaTriggerID - 6615
struct at_dh_darkness : AreaTriggerAI
{
    at_dh_darkness(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster || !unit || !caster->IsPlayer())
            return;

        if (caster->IsFriendlyTo(unit))
            caster->CastSpell(unit, SPELL_DH_DARKNESS_BUFF, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster || !unit || !caster->IsPlayer())
            return;

        if (Aura* darkness = unit->GetAura(SPELL_DH_DARKNESS_BUFF, caster->GetGUID()))
            darkness->SetDuration(0);
    }
};

// Shattered Souls - 228537
// AreaTriggerID - 12929 (normal) and 11266 (demon) and ?? (lesser)
struct at_dh_shattered_souls : AreaTriggerAI
{
    at_dh_shattered_souls(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        Unit* caster = at->GetCaster();
        if (!caster || !unit || !caster->IsPlayer())
            return;

        if (caster != unit)
            return;

        Player* casterPlayer = caster->ToPlayer();

        switch (at->GetSpellId())
        {
            case SPELL_DH_SHATTERED_SOULS_AT_NORMAL:
            {
                caster->CastSpell(caster, casterPlayer->GetSpecializationId() == TALENT_SPEC_DEMON_HUNTER_HAVOC ? SPELL_DH_CONSUME_SOUL_25 : SPELL_DH_CONSUME_SOUL_25_VENG, true);
                break;
            }
            case SPELL_DH_SHATTERED_SOULS_LESSER:
            {
                caster->CastSpell(caster, casterPlayer->GetSpecializationId() == TALENT_SPEC_DEMON_HUNTER_HAVOC ? SPELL_DH_CONSUME_SOUL_10 : SPELL_DH_CONSUME_SOUL_10_VENG, true);
                break;
            }
            case SPELL_DH_SHATTERED_SOULS_AT_DEMON:
            {
                if (casterPlayer->GetSpecializationId() == TALENT_SPEC_DEMON_HUNTER_HAVOC)
                {
                    caster->CastSpell(caster, SPELL_DH_CONSUME_SOUL_DEMON, true);
                    if (caster->HasAura(SPELL_DH_DEMONIC_APPETITE))
                        caster->CastSpell(caster, SPELL_DH_DEMONIC_APPETITE_FURY, true);
                }
                else
                    caster->CastSpell(caster, SPELL_DH_CONSUME_SOUL_DEMON_VENG, true);
                break;
            }
        }

        at->SetDuration(0);
    }
};

// Sigil of Silence - 202137
// AreaTriggerID -  10714
struct at_dh_sigil_of_silence : AreaTriggerAI
{
    at_dh_sigil_of_silence(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
        {
            caster->CastSpell(at->GetPosition(), SPELL_DH_SIGIL_OF_SILENCE_TRIGGER, true);
            caster->CastSpell(at->GetPosition(), SPELL_DH_SIGIL_OF_SILENCE_EXPLOSION, true);
        }
    }
};

void AddSC_demon_hunter_spell_scripts()
{
    new spell_dh_annihilation();
    new spell_dh_annihilation_damage();
    new spell_dh_blade_dance();
    new spell_dh_blade_turning();
    new spell_dh_bloodlet();
    new spell_dh_chaos_strike();
    new spell_dh_consume_soul();
    new spell_dh_consume_soul_vengeance();
    new spell_dh_darkness_absorb();
    new spell_dh_demon_blades();
    new spell_dh_demon_spikes();
    new spell_dh_demon_spikes_buff();
    new spell_dh_demonic_appetite();
    new spell_dh_eye_beam();
    new spell_dh_eye_beam_trigger();
    new spell_dh_feast_of_souls();
    new spell_dh_fel_barrage();
    new spell_dh_fel_barrage_aura();
    new spell_dh_fel_barrage_damage();
    new spell_dh_fel_devastation();
    new spell_dh_fel_eruption();
    new spell_dh_fel_mastery();
    new spell_dh_fel_rush();
    new spell_dh_fel_rush_dash();
    new spell_dh_felblade_reset();
    new spell_dh_fiery_brand();
    new spell_dh_fiery_brand_absorb();
    new spell_dh_fiery_brand_dot();
    new spell_dh_fracture();
    RegisterAuraScript(aura_dh_fraility);
    new spell_dh_glide();
    new spell_dh_immolation_aura();
    new spell_dh_immolation_aura_damage();
    RegisterSpellScript(spell_dh_infernal_strike);
    new spell_dh_last_resort();
    new spell_dh_master_of_the_glaive();
    new spell_dh_metamorphosis();
    new spell_dh_metamorphosis_buffs();
    new spell_dh_metamorphosis_buffs_veng();
    RegisterSpellAndAuraScriptPair(spell_dh_metamorphosis_immunity, aura_dh_metamorphosis_immunity);
    new spell_dh_nemesis();
    new spell_dh_nether_bond();
    new spell_dh_nether_bond_periodic();
    new spell_dh_razor_spikes();
    new spell_dh_shattered_souls();
    new spell_dh_shear_proc();
    new spell_dh_sigil_of_misery_fear();
    new spell_dh_soul_barrier();
    new spell_dh_soul_cleave();
    new spell_dh_soul_cleave_damage();
    RegisterSpellScript(spell_dh_spirit_bomb);
    RegisterSpellScript(spell_dh_spirit_bomb_damage);
    new spell_dh_vengeful_retreat();
    new spell_dh_vengeful_retreat_fury_refiller();
    new spell_dh_vengeful_retreat_trigger();
    RegisterSpellScript(spell_dh_felblade);
    RegisterAuraScript(aura_dh_chaos_cleave);

    /// AreaTrigger Scripts
    RegisterAreaTriggerAI(at_dh_darkness);
    RegisterAreaTriggerAI(at_dh_shattered_souls);
    RegisterAreaTriggerAI(at_dh_sigil_of_chains);
    RegisterAreaTriggerAI(at_dh_sigil_of_flame);
    RegisterAreaTriggerAI(at_dh_sigil_of_silence);
    RegisterAreaTriggerAI(at_dh_sigil_of_misery);

    /// Custom NPC scripts
    new npc_dh_spell_trainer();
}
