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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "Containers.h"
#include "SpellPackets.h"

enum DruidSpells
{
    SPELL_DRUID_THRASH_PERIODIC_DAMAGE              = 192090,

    SPELL_DRUID_BLESSING_OF_THE_ANCIENTS            = 202360,
    SPELL_DRUID_BLESSING_OF_ELUNE                   = 202737,
    SPELL_DRUID_BLESSING_OF_ANSHE                   = 202739,

    SPELL_DRUID_STARLORD_DUMMY                      = 202345,
    SPELL_DRUID_STARLORD_SOLAR                      = 202416,
    SPELL_DRUID_STARLORD_LUNAR                      = 202423,

    SPELL_DRUID_GLYPH_OF_STARS                      = 114301,
    SPELL_DRUID_CHOSEN_OF_ELUNE                     = 102560,
    SPELL_DRUID_BLUE_COLOR                          = 108268,
    SPELL_DRUID_SHADOWY_GHOST                       = 165114,
};

enum ShapeshiftFormSpells
{
    SPELL_DRUID_BEAR_FORM                           = 5487,
    SPELL_DRUID_CAT_FORM                            = 768,
    SPELL_DRUID_MOONKIN_FORM                        = 24858,
    SPELL_DRUID_INCARNATION_TREE_OF_LIFE            = 33891,
    SPELL_DRUID_INCARNATION_KING_OF_JUNGLE          = 102543
};

enum SoulOfTheForestSpells
{
    SPELL_DRUID_SOUL_OF_THE_FOREST_RESTO_TALENT  = 158478,
    SPELL_DRUID_SOUL_OF_THE_FOREST_RESTO         = 114108
};

enum EfflorescenceSpells
{
    SPELL_DRUID_EFFLORESCENCE_HEAL   = 81269,
    SPELL_DRUID_EFFLORESCENCE_DUMMY  = 81262
};

//7.3.2.25549
// 77758 - Thrash
class spell_dru_thrash : public SpellScript
{
    PrepareSpellScript(spell_dru_thrash);

    void OnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        caster->CastSpell(target, SPELL_DRUID_THRASH_PERIODIC_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dru_thrash::OnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Thrash periodic damage - 192090
class spell_dru_thrash_periodic_damage : public AuraScript
{
    PrepareAuraScript(spell_dru_thrash_periodic_damage);

    void OnTick(AuraEffect const* auraEff)
    {
        if (Unit* caster = auraEff->GetCaster())
        {
            if (Player* player = caster->ToPlayer())
            {
                if (AuraEffect* aurEff = GetAura()->GetEffect(EFFECT_0))
                {
                    int32 dmg = player->GetUInt32Value(UNIT_FIELD_ATTACK_POWER) * 0.605f;
                    dmg = (dmg * GetStackAmount()) / 5;
                    aurEff->SetDamage(dmg);
                } 
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_thrash_periodic_damage::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// Blessing of the Ancients - 202360
class spell_dru_blessing_of_the_ancients : public SpellScript
{
    PrepareSpellScript(spell_dru_blessing_of_the_ancients);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        uint32 removeAura   = GetCaster()->HasAura(SPELL_DRUID_BLESSING_OF_ELUNE) ? SPELL_DRUID_BLESSING_OF_ELUNE : SPELL_DRUID_BLESSING_OF_ANSHE;
        uint32 addAura      = GetCaster()->HasAura(SPELL_DRUID_BLESSING_OF_ELUNE) ? SPELL_DRUID_BLESSING_OF_ANSHE : SPELL_DRUID_BLESSING_OF_ELUNE;

        GetCaster()->RemoveAurasDueToSpell(removeAura);
        GetCaster()->CastSpell(nullptr, addAura, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dru_blessing_of_the_ancients::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Solar empowerment - 164545
class aura_dru_solar_empowerment : public AuraScript
{
    PrepareAuraScript(aura_dru_solar_empowerment);

    void OnApply(const AuraEffect* /* aurEff */, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget()->HasAura(SPELL_DRUID_STARLORD_DUMMY))
            GetTarget()->CastSpell(nullptr, SPELL_DRUID_STARLORD_SOLAR, true);
    }

    void OnRemove(const AuraEffect* /* aurEff */, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_STARLORD_SOLAR);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(aura_dru_solar_empowerment::OnApply, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(aura_dru_solar_empowerment::OnRemove, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

// Lunar empowerment - 164547
class aura_dru_lunar_empowerment : public AuraScript
{
    PrepareAuraScript(aura_dru_lunar_empowerment);

    void OnApply(const AuraEffect* /* aurEff */, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget()->HasAura(SPELL_DRUID_STARLORD_DUMMY))
            GetTarget()->CastSpell(nullptr, SPELL_DRUID_STARLORD_LUNAR, true);
    }

    void OnRemove(const AuraEffect* /* aurEff */, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_STARLORD_LUNAR);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(aura_dru_lunar_empowerment::OnApply, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(aura_dru_lunar_empowerment::OnRemove, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};
//7.3.2.25549 END

// Efflorescence - 145205
// @Version : 7.1.0.22908
class spell_dru_efflorescence : public SpellScriptLoader
{
public:
    spell_dru_efflorescence() : SpellScriptLoader("spell_dru_efflorescence") {}

    class spell_dru_efflorescence_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_efflorescence_SpellScript);

        enum eCreature
        {
            Efflorescence = 47649
        };

        void HandleSummon()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Creature*> efflorescenceList;
            caster->GetCreatureListWithEntryInGrid(efflorescenceList, eCreature::Efflorescence, 500.0f);

            for (auto creature : efflorescenceList)
            {
                if (creature->GetOwner() == caster)
                    creature->DespawnOrUnsummon();
            }
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_dru_efflorescence_SpellScript::HandleSummon);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_efflorescence_SpellScript();
    }
};

// Efflorescence (Aura) - 81262
// @Version : 7.1.0.22908
class spell_dru_efflorescence_aura : public SpellScriptLoader
{
public:
    spell_dru_efflorescence_aura() : SpellScriptLoader("spell_dru_efflorescence_aura") {}

    class spell_dru_efflorescence_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_efflorescence_aura_AuraScript);

        void HandleHeal(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->GetOwner())
                caster->CastSpell(caster, SPELL_DRUID_EFFLORESCENCE_HEAL, true, NULL, NULL, caster->GetOwnerGUID());
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_efflorescence_aura_AuraScript::HandleHeal, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_efflorescence_aura_AuraScript();
    }
};

// Efflorescence (Heal) - 81269
// @Version : 7.1.0.22908
class spell_dru_efflorescence_heal : public SpellScriptLoader
{
public:
    spell_dru_efflorescence_heal() : SpellScriptLoader("spell_dru_efflorescence_heal") {}

    class spell_dru_efflorescence_heal_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_efflorescence_heal_SpellScript);

        int32 targetCount;

        bool Load() override
        {
            targetCount = 0;
            return true;
        }

        void SortTargets(std::list<WorldObject*>& targets)
        {
            targets.sort(Trinity::HealthPctOrderPred());
        }

        void HandleHeal(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            if (caster == target || targetCount > 2)
            {
                SetHitHeal(0);
            }
            else
                targetCount++;
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dru_efflorescence_heal_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_efflorescence_heal_SpellScript::SortTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_efflorescence_heal_SpellScript();
    }
};

enum PrimalFurySpells
{
    SPELL_DRUID_RAKE          = 1822,
    SPELL_DRUID_SHRED         = 5221,
    SPELL_DRUID_MOONFIRE_CAT  = 155625,
    SPELL_DRUID_SWIPE_CAT     = 106785
};

// Primal Fury - 159286
// @Version : 7.1.0.22908
class spell_dru_primal_fury : public SpellScriptLoader
{
public:
    spell_dru_primal_fury() : SpellScriptLoader("spell_dru_primal_fury") { }

    class spell_dru_primal_fury_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_primal_fury_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            bool _spellCanProc = (eventInfo.GetSpellInfo()->Id == SPELL_DRUID_SHRED || eventInfo.GetSpellInfo()->Id == SPELL_DRUID_RAKE || eventInfo.GetSpellInfo()->Id == SPELL_DRUID_SWIPE_CAT || eventInfo.GetSpellInfo()->Id == SPELL_DRUID_MOONFIRE_CAT);

            if ((eventInfo.GetHitMask() & PROC_HIT_CRITICAL) && _spellCanProc)
                return true;

            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dru_primal_fury_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_primal_fury_AuraScript();
    }
};

enum PredatorySwiftnessSpells
{
    SPELL_DRUID_PREDATORY_SWIFTNESS       = 16974,
    SPELL_DRUID_PREDATORY_SWIFTNESS_AURA  = 69369
};

// Predatory Swiftness - 16974
// @Called : Maim - 22570, Ferocious Bite - 22568, Rip - 1079, Savage Roar - 1079
// @Version : 7.1.0.22908
class spell_dru_predatory_swiftness : public SpellScriptLoader
{
public:
    spell_dru_predatory_swiftness() : SpellScriptLoader("spell_dru_predatory_swiftness") { }

    class spell_dru_predatory_swiftness_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_predatory_swiftness_SpellScript);

        uint8 _cp;

        bool Load() override
        {
            _cp = GetCaster()->GetPower(POWER_COMBO_POINTS);
            return true;
        }

        SpellCastResult CheckCast()
        {
            if (GetCaster())
            {
                if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_DONT_REPORT;

                if (!GetCaster()->ToPlayer()->GetComboPoints())
                    return SPELL_FAILED_NO_COMBO_POINTS;
            }
            else
                return SPELL_FAILED_DONT_REPORT;

            return SPELL_CAST_OK;
        }

        void HandleOnHit()
        {
            if (Player* player = GetCaster()->ToPlayer())
                if (player->HasAura(SPELL_DRUID_PREDATORY_SWIFTNESS) && roll_chance_i(20 * _cp))
                    player->CastSpell(player, SPELL_DRUID_PREDATORY_SWIFTNESS_AURA, true);
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_dru_predatory_swiftness_SpellScript::CheckCast);
            AfterHit += SpellHitFn(spell_dru_predatory_swiftness_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_predatory_swiftness_SpellScript();
    }
};

// Predatory Swiftness (Aura) - 69369
// @Called : Entangling Roots - 339, Rebirth - 20484, Regrowth - 8936
// @Version : 7.1.0.22908
class spell_dru_predatory_swiftness_aura : public SpellScriptLoader
{
public:
    spell_dru_predatory_swiftness_aura() : SpellScriptLoader("spell_dru_predatory_swiftness_aura") { }

    class spell_dru_predatory_swiftness_aura_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_predatory_swiftness_aura_SpellScript);

        void HandleAfterHit()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                if (player->HasAura(SPELL_DRUID_PREDATORY_SWIFTNESS_AURA))
                    player->RemoveAurasDueToSpell(SPELL_DRUID_PREDATORY_SWIFTNESS_AURA);
            }
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_dru_predatory_swiftness_aura_SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_predatory_swiftness_aura_SpellScript();
    }
};

enum LifebloomSpells
{
    SPELL_DRUID_LIFEBLOOM_FINAL_HEAL = 33778
};

// Lifebloom - 33763
// @Version : 7.1.0.22908
class spell_dru_lifebloom : public SpellScriptLoader
{
public:
    spell_dru_lifebloom() : SpellScriptLoader("spell_dru_lifebloom") { }

    class spell_dru_lifebloom_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_lifebloom_AuraScript);

        void AfterRemove(AuraEffect const* /* aurEff */, AuraEffectHandleModes /*mode*/)
        {
            // Final heal only on duration end
            AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
            if (removeMode != AURA_REMOVE_BY_EXPIRE && removeMode != AURA_REMOVE_BY_ENEMY_SPELL)
                return;

            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(GetTarget(), SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, true);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_dru_lifebloom_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_lifebloom_AuraScript();
    }
};

// Berserk - 106951
// @Version : 7.1.0.22908
class spell_dru_berserk : public SpellScriptLoader
{
public:
    spell_dru_berserk() : SpellScriptLoader("spell_dru_berserk") { }

    class spell_dru_berserk_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_berserk_SpellScript);

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            if (caster->GetShapeshiftForm() != FORM_CAT_FORM)
                return SPELL_FAILED_ONLY_SHAPESHIFT;

            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_dru_berserk_SpellScript::CheckCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_berserk_SpellScript();
    }
};

enum SunfireSpells
{
    SPELL_DRUID_SUNFIRE_DAMAGE = 164815
};

// Sunfire - 93402
// @Version : 7.1.0.22908
class spell_dru_sunfire : public SpellScriptLoader
{
public:
    spell_dru_sunfire() : SpellScriptLoader("spell_dru_sunfire") {}

    class spell_dru_sunfire_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_sunfire_SpellScript);

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!target || !caster)
                return;

            caster->CastSpell(target, SPELL_DRUID_SUNFIRE_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dru_sunfire_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_sunfire_SpellScript();
    }
};

enum BalanceAffinitySpells
{
    SPELL_DRUID_STARSURGE     = 78674,
    SPELL_DRUID_SUNFIRE       = 93402,
    SPELL_DRUID_LUNAR_STRIKE  = 194153,
    SPELL_DRUID_SOLAR_WRATH   = 190984
};

// Balance Affinity (Feral, Guardian) - 197488
// @Version : 7.1.0.22908
class spell_dru_balance_affinity_dps : public SpellScriptLoader
{
public:
    spell_dru_balance_affinity_dps() : SpellScriptLoader("spell_dru_balance_affinity_dps") {}

    class spell_dru_balance_affinity_dps_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_balance_affinity_dps_AuraScript);

        void LearnSpells(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (Player* player = caster->ToPlayer())
            {
                player->AddTemporarySpell(SPELL_DRUID_MOONKIN_FORM);
                player->AddTemporarySpell(SPELL_DRUID_STARSURGE);
                player->AddTemporarySpell(SPELL_DRUID_LUNAR_STRIKE);
                player->AddTemporarySpell(SPELL_DRUID_SOLAR_WRATH);
                player->AddTemporarySpell(SPELL_DRUID_SUNFIRE);
            }
        }

        void UnlearnSpells(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (Player* player = caster->ToPlayer())
            {
                player->RemoveTemporarySpell(SPELL_DRUID_MOONKIN_FORM);
                player->RemoveTemporarySpell(SPELL_DRUID_STARSURGE);
                player->RemoveTemporarySpell(SPELL_DRUID_LUNAR_STRIKE);
                player->RemoveTemporarySpell(SPELL_DRUID_SOLAR_WRATH);
                player->RemoveTemporarySpell(SPELL_DRUID_SUNFIRE);
            }
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_dru_balance_affinity_dps_AuraScript::UnlearnSpells, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectApply += AuraEffectApplyFn(spell_dru_balance_affinity_dps_AuraScript::LearnSpells, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_balance_affinity_dps_AuraScript();
    }
};

// Balance Affinity (Restoration) - 197632
// @Version : 7.1.0.22908
class spell_dru_balance_affinity_resto : public SpellScriptLoader
{
public:
    spell_dru_balance_affinity_resto() : SpellScriptLoader("spell_dru_balance_affinity_resto") {}

    class spell_dru_balance_affinity_resto_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_balance_affinity_resto_AuraScript);

        void LearnSpells(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (Player* player = caster->ToPlayer())
            {
                player->AddTemporarySpell(SPELL_DRUID_MOONKIN_FORM);
                player->AddTemporarySpell(SPELL_DRUID_STARSURGE);
                player->AddTemporarySpell(SPELL_DRUID_LUNAR_STRIKE);
            }
        }

        void UnlearnSpells(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (Player* player = caster->ToPlayer())
            {
                player->RemoveTemporarySpell(SPELL_DRUID_MOONKIN_FORM);
                player->RemoveTemporarySpell(SPELL_DRUID_STARSURGE);
                player->RemoveTemporarySpell(SPELL_DRUID_LUNAR_STRIKE);
            }
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_dru_balance_affinity_resto_AuraScript::UnlearnSpells, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectApply += AuraEffectApplyFn(spell_dru_balance_affinity_resto_AuraScript::LearnSpells, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_balance_affinity_resto_AuraScript();
    }
};

enum FerociousBiteSpells
{
    SPELL_DRUID_RIP         = 1079,
    SPELL_DRUID_SABERTOOTH  = 202031
};

// Ferocious Bite - 22568
// @Edit : Sabertooth - 202031
// @Version : 7.1.0.22908
class spell_dru_ferocious_bite : public SpellScriptLoader
{
public:
    spell_dru_ferocious_bite() : SpellScriptLoader("spell_dru_ferocious_bite") { }

    class spell_dru_ferocious_bite_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_ferocious_bite_SpellScript);

        void CalcDmg(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            uint32 dmg = GetHitDamage();
            uint32 cp = caster->GetPower(POWER_COMBO_POINTS) + 1;
            float multiplier = (float)cp / (float)caster->GetMaxPower(POWER_COMBO_POINTS);
            int32 newdmg = dmg * (int32)multiplier;

            SetHitDamage(newdmg);

            if (Unit* target = GetHitUnit())
            {
                if (target->GetHealthPct() < 25 || caster->HasAura(SPELL_DRUID_SABERTOOTH))
                {
                    if (Aura* rip = target->GetAura(SPELL_DRUID_RIP, caster->GetGUID()))
                        rip->RefreshDuration();
                }
            }
        }

        void RemoveCP()
        {
            Unit* caster = GetCaster();
            caster->SetPower(POWER_COMBO_POINTS, 0);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dru_ferocious_bite_SpellScript::CalcDmg, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            AfterHit += SpellHitFn(spell_dru_ferocious_bite_SpellScript::RemoveCP);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_ferocious_bite_SpellScript();
    }
};

// Dash - 1850
// @Version : 7.1.0.22908
class spell_dru_dash : public SpellScriptLoader
{
public:
    spell_dru_dash() : SpellScriptLoader("spell_dru_dash") { }

    class spell_dru_dash_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_dash_AuraScript);

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            // do not set speed if not in cat form
            if (GetUnitOwner()->GetShapeshiftForm() != FORM_CAT_FORM)
                amount = 0;
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_dash_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_INCREASE_SPEED);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_dash_AuraScript();
    }
};

enum SavageRoarSpells
{
    SPELL_DRUID_SAVAGE_ROAR = 62071
};

// Savage Roar - 52610
// @Version : 7.1.0.22908
class spell_dru_savage_roar : public SpellScriptLoader
{
public:
    spell_dru_savage_roar() : SpellScriptLoader("spell_dru_savage_roar") { }

    class spell_dru_savage_roar_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_savage_roar_SpellScript);

        int32 m_ComboPoint = 0;
        int32 m_OldDuration = 0;

        SpellCastResult CheckCast()
        {
            Unit* l_Caster = GetCaster();
            if (l_Caster->GetShapeshiftForm() != FORM_CAT_FORM)
                return SPELL_FAILED_ONLY_SHAPESHIFT;

            return SPELL_CAST_OK;
        }

        void HandleOnPrepare()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            m_ComboPoint = caster->GetPower(POWER_COMBO_POINTS);

            if (Aura* savageRoar = caster->GetAura(GetSpellInfo()->Id))
                m_OldDuration = savageRoar->GetDuration();
        }

        void HandleAfterHit()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            int32 bonusDuration = m_ComboPoint * 8 * IN_MILLISECONDS;
            int32 maxDuration = GetSpellInfo()->GetMaxDuration();
            int32 newDuration = m_OldDuration + GetSpellInfo()->GetDuration() + bonusDuration;

            if (Aura* savageRoar = caster->GetAura(GetSpellInfo()->Id))
            {
                /// Can't be more then 130% of max duration
                if (newDuration > maxDuration)
                    newDuration = maxDuration;

                savageRoar->SetDuration(newDuration);
            }
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_dru_savage_roar_SpellScript::CheckCast);
            OnPrepare += SpellOnPrepareFn(spell_dru_savage_roar_SpellScript::HandleOnPrepare);
            AfterHit += SpellHitFn(spell_dru_savage_roar_SpellScript::HandleAfterHit);
        }
    };

    class spell_dru_savage_roar_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_savage_roar_AuraScript);

        void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                target->CastSpell(target, SPELL_DRUID_SAVAGE_ROAR, true, NULL, aurEff, GetCasterGUID());
        }

        void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                target->RemoveAurasDueToSpell(SPELL_DRUID_SAVAGE_ROAR);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_dru_savage_roar_AuraScript::AfterApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_dru_savage_roar_AuraScript::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_savage_roar_SpellScript();
    }

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_savage_roar_AuraScript();
    }
};

enum SurvivalInstinctsSpells
{
    SPELL_DRUID_SURVIVAL_INSTINCTS = 50322
};

// Survival Instincts - 61336
// @Version : 7.1.0.22908
class spell_dru_survival_instincts : public SpellScriptLoader
{
public:
    spell_dru_survival_instincts() : SpellScriptLoader("spell_dru_survival_instincts") { }

    class spell_dru_survival_instincts_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_survival_instincts_AuraScript);

        void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                target->CastSpell(target, SPELL_DRUID_SURVIVAL_INSTINCTS, true);
        }

        void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                target->RemoveAurasDueToSpell(SPELL_DRUID_SURVIVAL_INSTINCTS);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_dru_survival_instincts_AuraScript::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
            AfterEffectRemove += AuraEffectRemoveFn(spell_dru_survival_instincts_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_survival_instincts_AuraScript();
    }
};

// Swift Flight Form (Passive) - 40121
// @Version : 7.1.0.22908
class spell_dru_swift_flight_passive : public SpellScriptLoader
{
public:
    spell_dru_swift_flight_passive() : SpellScriptLoader("spell_dru_swift_flight_passive") { }

    class spell_dru_swift_flight_passive_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_swift_flight_passive_AuraScript);

        bool Load() override
        {
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool & /*canBeRecalculated*/)
        {
            if (Player* caster = GetCaster()->ToPlayer())
                if (caster->GetSkillValue(SKILL_RIDING) >= 375)
                    amount = 310;
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_swift_flight_passive_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_swift_flight_passive_AuraScript();
    }
};

// Wild growth - 48438
// @Edit : Soul of the Forest - 114108, Tree of Life - 33891
// @Version : 7.1.0.22908
class spell_dru_wild_growth : public SpellScriptLoader
{
public:
    spell_dru_wild_growth() : SpellScriptLoader("spell_dru_wild_growth") { }

    class spell_dru_wild_growth_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_wild_growth_SpellScript);

        bool m_HasSoulOfTheForest = false;

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            uint8 maxTargets = GetSpellInfo()->GetEffect(EFFECT_2)->BasePoints + 1;
            if (!maxTargets)
                return;

            // If Tree of Life is activated we increase 2 targets
            if (caster->HasAura(SPELL_DRUID_INCARNATION_TREE_OF_LIFE))
                maxTargets += 2;

            if (targets.size() > maxTargets)
            {
                targets.sort(Trinity::HealthPctOrderPred());
                targets.resize(maxTargets);
            }
        }

        void HandleAfterHit()
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!target)
                return;

            // If soul of the forest is activated we increase the heal by 50%
            if (AuraEffect* wildGrowth = target->GetAuraEffect(GetSpellInfo()->Id, EFFECT_0, caster->GetGUID()))
            {
                if (caster->HasAura(SPELL_DRUID_SOUL_OF_THE_FOREST_RESTO) || m_HasSoulOfTheForest)
                {
                    uint8 SoulofTheForestBonus = GetSpellInfo()->GetEffect(EFFECT_2)->BasePoints;
                    if (!SoulofTheForestBonus)
                        return;

                    wildGrowth->SetAmount(wildGrowth->GetAmount() + CalculatePct(wildGrowth->GetAmount(), SoulofTheForestBonus));
                    m_HasSoulOfTheForest = true;
                    caster->RemoveAura(SPELL_DRUID_SOUL_OF_THE_FOREST_RESTO);
                }
            }
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_dru_wild_growth_SpellScript::HandleAfterHit);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_wild_growth_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_wild_growth_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_wild_growth_SpellScript();
    }
};

// Incarnation : Chosen of Elune - 102560
// @Version : 7.1.0.22908
class spell_dru_incarnation_chosen_of_elune : public SpellScriptLoader
{
public:
    spell_dru_incarnation_chosen_of_elune() : SpellScriptLoader("spell_dru_incarnation_chosen_of_elune") { }

    class spell_dru_incarnation_chosen_of_elune_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_incarnation_chosen_of_elune_SpellScript);

        void OnActivate()
        {
            if (Player* player = GetCaster()->ToPlayer())
                if (!player->HasAura(SPELL_DRUID_MOONKIN_FORM))
                    player->CastSpell(player, SPELL_DRUID_MOONKIN_FORM, true);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_dru_incarnation_chosen_of_elune_SpellScript::OnActivate);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_incarnation_chosen_of_elune_SpellScript();
    }
};

// Incarnation : King of the Jungle - 102543
// @Version : 7.1.0.22908
class spell_dru_incarnation_king_of_the_jungle : public SpellScriptLoader
{
public:
    spell_dru_incarnation_king_of_the_jungle() : SpellScriptLoader("spell_dru_incarnation_king_of_the_jungle") { }

    class spell_dru_incarnation_king_of_the_jungle_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_incarnation_king_of_the_jungle_SpellScript);

        void OnActivate()
        {
            if (Player* player = GetCaster()->ToPlayer())
                if (!player->HasAura(SPELL_DRUID_CAT_FORM))
                    player->CastSpell(player, SPELL_DRUID_CAT_FORM, true);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_dru_incarnation_king_of_the_jungle_SpellScript::OnActivate);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_incarnation_king_of_the_jungle_SpellScript();
    }
};

// Incarnation : Guardian of Ursoc - 102558
// @Version : 7.1.0.22908
class spell_dru_incarnation_guardian_of_ursoc : public SpellScriptLoader
{
public:
    spell_dru_incarnation_guardian_of_ursoc() : SpellScriptLoader("spell_dru_incarnation_guardian_of_ursoc") { }

    class spell_dru_incarnation_guardian_of_ursoc_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_incarnation_guardian_of_ursoc_SpellScript);

        void OnActivate()
        {
            if (Player* player = GetCaster()->ToPlayer())
                if (!player->HasAura(SPELL_DRUID_BEAR_FORM))
                    player->CastSpell(player, SPELL_DRUID_BEAR_FORM, true);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_dru_incarnation_guardian_of_ursoc_SpellScript::OnActivate);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_incarnation_guardian_of_ursoc_SpellScript();
    }
};

// Wild Charge (Moonkin) - 102383
// @Version : 7.1.0.22908
class spell_dru_wild_charge_moonkin : public SpellScriptLoader
{
public:
    spell_dru_wild_charge_moonkin() : SpellScriptLoader("spell_dru_wild_charge_moonkin") { }

    class spell_dru_wild_charge_moonkin_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_wild_charge_moonkin_SpellScript);

        SpellCastResult CheckFight()
        {
            if (GetCaster())
            {
                if (!GetCaster()->IsInCombat())
                    return SPELL_FAILED_DONT_REPORT;
            }
            else
                return SPELL_FAILED_DONT_REPORT;

            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_dru_wild_charge_moonkin_SpellScript::CheckFight);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_wild_charge_moonkin_SpellScript();
    }
};

enum MoonfireSpells
{
    SPELL_DRUID_MOONFIRE_DAMAGE = 164812
};

// Moonfire - 8921
// @Version : 7.1.0.22908
class spell_dru_moonfire : public SpellScriptLoader
{
public:
    spell_dru_moonfire() : SpellScriptLoader("spell_dru_moonfire") { }

    class spell_dru_moonfire_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_moonfire_SpellScript);

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (caster != target)
                caster->CastSpell(target, SPELL_DRUID_MOONFIRE_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dru_moonfire_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_moonfire_SpellScript();
    }
};

enum OmenOfClaritySpells
{
    SPELL_DRUID_CLEARCASTING       = 16870,
    SPELL_DRUID_MOMENT_OF_CLARITY  = 155577,
    SPELL_DRUID_OMEN_OF_CLARITY    = 113043
};

// Omen of Clarity - 113043
// @Called : Lifebloom - 33763, Moment of Clarity - 155577
// @Version : 7.1.0.22908
class spell_dru_omen_of_clarity : public SpellScriptLoader
{
public:
    spell_dru_omen_of_clarity() : SpellScriptLoader("spell_dru_omen_of_clarity") { }

    class spell_dru_omen_of_clarity_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_omen_of_clarity_AuraScript);

        void HandleEffectPeriodic(const AuraEffect* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->HasAura(SPELL_DRUID_OMEN_OF_CLARITY))
            {
                if (roll_chance_i(4))
                {
                    caster->CastSpell(caster, SPELL_DRUID_CLEARCASTING, true);

                    if (caster->HasAura(SPELL_DRUID_MOMENT_OF_CLARITY))
                    {
                        if (Aura* clearcasting = caster->GetAura(SPELL_DRUID_CLEARCASTING))
                            clearcasting->ModStackAmount(3);
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_omen_of_clarity_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_omen_of_clarity_AuraScript();
    }
};

enum CatFormSpells
{
    SPELL_DRUID_DASH                     = 1850,
    SPELL_DRUID_PROWL                    = 5215,
    SPELL_DRUID_FORM_CAT_INCREASE_SPEED  = 113636,
    SPELL_DRUID_CATFORM_OVERRIDE         = 48629,
    SPELL_DRUID_LUNAR_INSPIRATION        = 155580,
    SPELL_DRUID_MOONFIRE_CAT_OVERRIDE    = 155627
};

// Cat Form - 768
// @Called : Cat Form (Speed) - 113636, Cat Form (Thrash/Swipe) - 48629, Dash - 1850, Lunar Inspiration - 155580
// @Version : 7.1.0.22908
class spell_dru_cat_form : public SpellScriptLoader
{
public:
    spell_dru_cat_form() : SpellScriptLoader("spell_dru_cat_form") { }

    class spell_dru_cat_form_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_cat_form_SpellScript);

        void OnActivate()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                if (!player->HasAura(SPELL_DRUID_FORM_CAT_INCREASE_SPEED))
                {
                    player->CastSpell(player, SPELL_DRUID_FORM_CAT_INCREASE_SPEED, true);
                    player->RemoveMovementImpairingAuras();
                }
            }
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_dru_cat_form_SpellScript::OnActivate);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_cat_form_SpellScript();
    }

    class spell_dru_cat_form_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_cat_form_AuraScript);

        void OnApply(const AuraEffect* /* aurEff */, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Aura* dash = caster->GetAura(SPELL_DRUID_DASH))
                    if (dash->GetEffect(0))
                        if (dash->GetEffect(0)->GetAmount() == 0)
                            dash->GetEffect(0)->SetAmount(70);

                if (caster->HasAura(SPELL_DRUID_LUNAR_INSPIRATION))
                    caster->CastSpell(caster, SPELL_DRUID_MOONFIRE_CAT_OVERRIDE, true);

                caster->CastSpell(caster, SPELL_DRUID_CATFORM_OVERRIDE, true);
            }
        }

        void OnRemove(const AuraEffect* /* aurEff */, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Aura* dash = caster->GetAura(SPELL_DRUID_DASH))
                    dash->GetEffect(0)->SetAmount(0);

                if (caster->HasAura(SPELL_DRUID_PROWL))
                    caster->RemoveAura(SPELL_DRUID_PROWL);

                if (caster->HasAura(SPELL_DRUID_LUNAR_INSPIRATION))
                    caster->RemoveAura(SPELL_DRUID_MOONFIRE_CAT_OVERRIDE);

                caster->RemoveAura(SPELL_DRUID_CATFORM_OVERRIDE);
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_dru_cat_form_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_dru_cat_form_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_cat_form_AuraScript();
    }
};

enum BearFormSpells
{
    SPELL_DRUID_BEARFORM_OVERRIDE              = 106829,
    SPELL_DRUID_STAMPEDING_ROAR                = 106898,
    SPELL_DRUID_STAMPEDING_ROAR_BEAR_OVERRIDE  = 106899
};

// Bear form - 5487
// @Called : Bear Form (Thrash/Swipe) - 106829, Bear Form (Stampeding Roar) - 106899
// @Version : 7.1.0.22908
class spell_dru_bear_form : public SpellScriptLoader
{
public:
    spell_dru_bear_form() : SpellScriptLoader("spell_dru_bear_form") {}

    class spell_dru_bear_form_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_bear_form_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_DRUID_BEARFORM_OVERRIDE, true);

            if (caster->HasSpell(SPELL_DRUID_STAMPEDING_ROAR))
                caster->CastSpell(caster, SPELL_DRUID_STAMPEDING_ROAR_BEAR_OVERRIDE, true);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->RemoveAurasDueToSpell(SPELL_DRUID_BEARFORM_OVERRIDE);

            if (caster->HasSpell(SPELL_DRUID_STAMPEDING_ROAR))
                caster->RemoveAurasDueToSpell(SPELL_DRUID_STAMPEDING_ROAR_BEAR_OVERRIDE);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_dru_bear_form_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_dru_bear_form_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_bear_form_AuraScript();
    }
};

enum SkullBashSpells
{
    SPELL_DRUID_SKULL_BASH_CHARGE    = 221514,
    SPELL_DRUID_SKULL_BASH_INTERUPT  = 93985
};

// Skull Bash - 106839
// @Version : 7.1.0.22908
class spell_dru_skull_bash : public SpellScriptLoader
{
public:
    spell_dru_skull_bash() : SpellScriptLoader("spell_dru_skull_bash") { }

    class spell_dru_skull_bash_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_skull_bash_SpellScript);

        void HandleOnHit()
        {
            if (Unit* target = GetHitUnit())
            {
                GetCaster()->CastSpell(target, SPELL_DRUID_SKULL_BASH_CHARGE, true);
                GetCaster()->CastSpell(target, SPELL_DRUID_SKULL_BASH_INTERUPT, true);
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_dru_skull_bash_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_skull_bash_SpellScript();
    }
};

// Stampeding Roar - 106898
// @Version : 7.1.0.22908
class spell_dru_stampeding_roar : public SpellScriptLoader
{
public:
    spell_dru_stampeding_roar() : SpellScriptLoader("spell_dru_stampeding_roar") { }

    class spell_dru_stampeding_roar_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_stampeding_roar_SpellScript);

        void HandleOnHit()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (!caster->HasAura(SPELL_DRUID_BEAR_FORM) && !caster->HasAura(SPELL_DRUID_CAT_FORM))
                caster->CastSpell(caster, SPELL_DRUID_BEAR_FORM, true);

            if (Unit* target = GetHitUnit())
                target->RemoveMovementImpairingAuras();
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_dru_stampeding_roar_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_stampeding_roar_SpellScript();
    }
};

// Activate Cat Form
// @Called : Dash - 1850, Prowl - 5215, Displacer Beast - 102280
// @Version : 7.1.0.22908
class spell_dru_activate_cat_form : public SpellScriptLoader
{
public:
    spell_dru_activate_cat_form() : SpellScriptLoader("spell_dru_activate_cat_form") { }

    class spell_dru_activate_cat_form_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_activate_cat_form_SpellScript);

        void HandleOnHit()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (!caster->HasAura(SPELL_DRUID_CAT_FORM))
                caster->CastSpell(caster, SPELL_DRUID_CAT_FORM, true);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_dru_activate_cat_form_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_activate_cat_form_SpellScript();
    }
};

enum KillerInstinctSpells
{
    SPELL_DRUID_KILLER_INSTINCT          = 108299,
    SPELL_DRUID_KILLER_INSTINCT_MOD_STAT = 108300
};

//Killer Instinct - 108299
// @Called : Called by Cat Form - 768 and Bear Form - 5487
// @Version : 7.1.0.22908
class spell_dru_killer_instinct : public SpellScriptLoader
{
public:
    spell_dru_killer_instinct() : SpellScriptLoader("spell_dru_killer_instinct") { }

    class spell_dru_killer_instinct_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_killer_instinct_AuraScript);

        void AfterApply(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*m_Mode*/)
        {
            if (Player* player = GetTarget()->ToPlayer())
            {
                if (player->HasAura(SPELL_DRUID_KILLER_INSTINCT))
                {
                    int32 bp = player->GetStat(STAT_INTELLECT);

                    player->CastCustomSpell(player, SPELL_DRUID_KILLER_INSTINCT_MOD_STAT, &bp, NULL, NULL, true);
                }
            }
        }

        void AfterRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*m_Mode*/)
        {
            if (Player* player = GetTarget()->ToPlayer())
            {
                if (player->HasAura(SPELL_DRUID_KILLER_INSTINCT))
                    player->RemoveAura(SPELL_DRUID_KILLER_INSTINCT_MOD_STAT);
            }
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_dru_killer_instinct_AuraScript::AfterApply, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_dru_killer_instinct_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_killer_instinct_AuraScript();
    }
};

enum LivingSeedSpells
{
    SPELL_DRUID_LIVING_SEED_PROC = 48504
};

// Living Seed - 48500
// @Version : 7.1.0.22908
class spell_dru_living_seed : public SpellScriptLoader
{
public:
    spell_dru_living_seed() : SpellScriptLoader("spell_dru_living_seed") { }

    class spell_dru_living_seed_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_living_seed_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetTypeMask() & PROC_FLAG_TAKEN_PERIODIC && eventInfo.GetSpellTypeMask() & PROC_SPELL_TYPE_HEAL)
                return false;

            return true;
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();

            if (HealInfo* healInfo = eventInfo.GetHealInfo())
            {
                int32 amount = CalculatePct(healInfo->GetHeal(), aurEff->GetAmount());
                GetTarget()->CastCustomSpell(SPELL_DRUID_LIVING_SEED_PROC, SPELLVALUE_BASE_POINT0, amount, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dru_living_seed_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dru_living_seed_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_living_seed_AuraScript();
    }
};

// Infected wound - 48484
// @Version : 7.1.0.22908
class spell_dru_infected_wound : public SpellScriptLoader
{
public:
    spell_dru_infected_wound() : SpellScriptLoader("spell_dru_infected_wound") { }

    class spell_dru_infected_wound_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_infected_wound_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetSpellInfo()->Id == SPELL_DRUID_RAKE)
                return true;

            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dru_infected_wound_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_infected_wound_AuraScript();
    }
};

enum YserasGiftSpellls
{
    SPELL_DRUID_YSERA_GIFT_CASTER_HEAL  = 145109,
    SPELL_DRUID_YSERA_GIFT_RAID_HEAL    = 145110
};

// Ysera's Gift - 145108
// @Version : 7.1.0.22908
class spell_dru_ysera_gift : public SpellScriptLoader
{
public:
    spell_dru_ysera_gift() : SpellScriptLoader("spell_dru_ysera_gift") {}

    class spell_dru_ysera_gift_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_ysera_gift_AuraScript);

        void HandleEffectPeriodic(AuraEffect const* /* aurEff */)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (!caster->IsAlive())
                return;

            int64 amount = (caster->GetHealth() * 3) / 100;
            CustomSpellValues values;
            values.AddSpellMod(SPELLVALUE_MAX_TARGETS, 1);
            values.AddSpellMod(SPELLVALUE_BASE_POINT0, amount);

            if (caster->IsFullHealth())
                caster->CastCustomSpell(SPELL_DRUID_YSERA_GIFT_RAID_HEAL, values, caster, TRIGGERED_FULL_MASK);
            else
                caster->CastCustomSpell(SPELL_DRUID_YSERA_GIFT_CASTER_HEAL, values, caster, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_ysera_gift_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_ysera_gift_AuraScript();
    }
};

enum RakeSpells
{
    SPELL_DRUID_RAKE_STUN             = 163505
};

// Rake - 1822
// @Version : 7.1.0.22908
class spell_dru_rake : public SpellScriptLoader
{
public:
    spell_dru_rake() : SpellScriptLoader("spell_dru_rake") { }

    class spell_dru_rake_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_rake_SpellScript);

    public:
        spell_dru_rake_SpellScript()
        {
            _stealthed = false;
        }

    private:
        bool _stealthed;

        bool Load() override
        {
            Unit* caster = GetCaster();
            if (caster->HasAuraType(SPELL_AURA_MOD_STEALTH))
                _stealthed = true;
            return true;
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();
            if (!caster || !target)
                return;

            if (this->_stealthed || caster->HasAura(SPELL_DRUID_INCARNATION_KING_OF_JUNGLE))
            {
                SetHitDamage(GetHitDamage() * 2);
                caster->CastSpell(target, SPELL_DRUID_RAKE_STUN, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dru_rake_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_rake_SpellScript();
    }
};

enum MaimSpells
{
    SPELL_DRUID_MAIM_STUN  = 203123
};

// Maim - 22570
// @Version : 7.1.0.22908
class spell_dru_maim : public SpellScriptLoader
{
public:
    spell_dru_maim() : SpellScriptLoader("spell_dru_maim") { }

    class spell_dru_maim_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_maim_SpellScript);

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();
            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_DRUID_MAIM_STUN, true);
        }

        void RemoveCP()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->SetPower(POWER_COMBO_POINTS, 0);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dru_maim_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            AfterHit += SpellHitFn(spell_dru_maim_SpellScript::RemoveCP);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_maim_SpellScript();
    }
};

// Rip - 1079
// @Version : 7.1.0.22908
class spell_dru_rip : public SpellScriptLoader
{
public:
    spell_dru_rip() : SpellScriptLoader("spell_dru_rip") {}

    class spell_dru_rip_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_rip_AuraScript);

        void HandleApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            int8 _cp = caster->GetPower(POWER_COMBO_POINTS) + 1;
            int32 dmg = aurEff->GetDamage() * _cp;

            if (AuraEffect* aurEff = GetAura()->GetEffect(EFFECT_0))
            {
                aurEff->SetDamage(dmg);
                GetAura()->SetNeedClientUpdateForTargets();
            }

            caster->SetPower(POWER_COMBO_POINTS, 0);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_dru_rip_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_rip_AuraScript();
    }
};

enum BloodTalonsSpells
{
    SPELL_BLOODTALONS       = 155672,
    SPELL_BLOODTALONS_AURA  = 145152
};

// Bloodtalons - 155672
// @Called : Regrowth - 8936
// @Version : 7.1.0.22908
class spell_dru_bloodtalons : public SpellScriptLoader
{
public:
    spell_dru_bloodtalons() : SpellScriptLoader("spell_dru_bloodtalons") { }

    class spell_dru_bloodtalons_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_bloodtalons_SpellScript);

        void HandleOnHit()
        {
            Unit* caster = GetCaster();
            if (caster)
                return;

            if (caster->HasAura(SPELL_BLOODTALONS))
                caster->CastSpell(caster, SPELL_BLOODTALONS_AURA, true);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_dru_bloodtalons_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_bloodtalons_SpellScript();
    }
};

enum TravelFormSpells
{
    SPELL_DRUID_TRAVEL_FORM_GENERIC  = 783,
    SPELL_DRUID_TRAVEL_FORM          = 165961,
    SPELL_DRUID_AQUATIC_FORM         = 1066,
    SPELL_DRUID_FLIGHT_FORM          = 33943,
    SPELL_DRUID_FLIGHT_EPIC_FORM     = 40120
};

// Travel Form - 783
// @Version : 7.1.0.22908
class spell_dru_travel_form : public SpellScriptLoader
{
public:
    spell_dru_travel_form() : SpellScriptLoader("spell_dru_travel_form") { }

    class spell_dru_travel_form_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_travel_form_SpellScript);

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            if (!caster->GetMap()->IsOutdoors(caster->GetPhaseShift(), caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ()))
                return SPELL_FAILED_ONLY_OUTDOORS;

            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_dru_travel_form_SpellScript::CheckCast);
        }
    };

    class spell_dru_travel_form_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_travel_form_AuraScript);

        void OnApply(const AuraEffect* /* aurEff */, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->CanFly())
                {
                    caster->CastSpell(caster, SPELL_DRUID_FLIGHT_EPIC_FORM, true);
                }
                else if (caster->IsInWater())
                {
                    caster->CastSpell(caster, SPELL_DRUID_AQUATIC_FORM, true);
                }
                else if (caster->GetMap()->IsOutdoors(caster->GetPhaseShift(), caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ()))
                {
                    caster->CastSpell(caster, SPELL_DRUID_TRAVEL_FORM, true);
                }
            }
        }

        void OnRemove(const AuraEffect* /* aurEff */, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                caster->RemoveAurasDueToSpell(SPELL_DRUID_FLIGHT_EPIC_FORM);
                caster->RemoveAurasDueToSpell(SPELL_DRUID_AQUATIC_FORM);
                caster->RemoveAurasDueToSpell(SPELL_DRUID_TRAVEL_FORM);
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_dru_travel_form_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_dru_travel_form_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_travel_form_AuraScript();
    }

    SpellScript* GetSpellScript() const override
    {
        return new spell_dru_travel_form_SpellScript();
    }
};

// Travel Form (Aura) - 783
// @Called : Travel Form - 165961, Aquatic Form - 1066, Flight Form - 33943, Flight Epic Form - 40120
// @Version : 7.1.0.22908
class spell_dru_travel_form_aura : public SpellScriptLoader
{
public:
    spell_dru_travel_form_aura() : SpellScriptLoader("spell_dru_travel_form_aura") { }

    class spell_dru_travel_form_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_travel_form_aura_AuraScript);

        void OnRemove(const AuraEffect* /* aurEff */, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                caster->RemoveAurasDueToSpell(SPELL_DRUID_TRAVEL_FORM_GENERIC);
            }
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_dru_travel_form_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_travel_form_aura_AuraScript();
    }
};

// 24858  Moonkin Form
// 102560 Chosen of Elune
class aura_dru_astral_form : public AuraScript
{
    PrepareAuraScript(aura_dru_astral_form);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_GLYPH_OF_STARS });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_DRUID_GLYPH_OF_STARS))
        {
            target->SetDisplayId(target->GetNativeDisplayId());
            target->AddAura(SPELL_DRUID_BLUE_COLOR, target);
            target->AddAura(SPELL_DRUID_SHADOWY_GHOST, target);
            target->CastSpell(target, sSpellMgr->GetSpellInfo(SPELL_DRUID_GLYPH_OF_STARS)->GetEffect(EFFECT_0)->BasePoints, true);
        }
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_DRUID_MOONKIN_FORM) || target->HasAura(SPELL_DRUID_CHOSEN_OF_ELUNE))
            return;

        target->RemoveAura(sSpellMgr->GetSpellInfo(SPELL_DRUID_GLYPH_OF_STARS)->GetEffect(EFFECT_0)->BasePoints);
        target->RemoveAura(SPELL_DRUID_BLUE_COLOR);
        target->RemoveAura(SPELL_DRUID_SHADOWY_GHOST);
    }

    void Register()
    {
        switch (m_scriptSpellId)
        {
            case SPELL_DRUID_MOONKIN_FORM:
                AfterEffectApply += AuraEffectApplyFn(aura_dru_astral_form::AfterApply, EFFECT_1, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(aura_dru_astral_form::AfterRemove, EFFECT_1, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
                break;
            case SPELL_DRUID_CHOSEN_OF_ELUNE:
                AfterEffectApply += AuraEffectApplyFn(aura_dru_astral_form::AfterApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(aura_dru_astral_form::AfterRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
                break;
            default:
                break;
        }
    }
};

enum StarfallSpells
{
    SPELL_DRUID_STARFALL_DAMAGE      = 191037,
    SPELL_DRUID_STELLAR_EMPOWERMENT  = 197637
};

// Starfall - 191034
// AreaTriggerID - 4756
// @Version : 7.1.0.22908
class at_dru_starfall : public AreaTriggerEntityScript
{
public:
    at_dru_starfall() : AreaTriggerEntityScript("at_dru_starfall") {}

    struct at_dru_starfallAI : AreaTriggerAI
    {
        int32 timeInterval;

        at_dru_starfallAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
        {
            // How often should the action be executed
            timeInterval = 850;
        }

        void OnUpdate(uint32 p_Time) override
        {
            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            if (caster->GetTypeId() != TYPEID_PLAYER)
                return;

            // Check if we can handle actions
            timeInterval += p_Time;
            if (timeInterval < 850)
                return;

            GuidUnorderedSet const objects = at->GetInsideUnits();
            for (ObjectGuid objguid : objects)
            {
                Unit* unit = ObjectAccessor::GetUnit(*caster, objguid);
                if (!unit)
                    continue;

                if (!caster->IsValidAttackTarget(unit))
                    continue;

                caster->CastSpell(unit, SPELL_DRUID_STARFALL_DAMAGE, true);
                caster->CastSpell(unit, SPELL_DRUID_STELLAR_EMPOWERMENT, true);
            }

            timeInterval -= 850;
        }
    };
};

enum SolarBeamSpells
{
    SPELL_DRUID_SOLAR_BEAM_SILENCE = 81261
};

// Solar Beam - 78675
// AreaTriggerID - 983
// @Version : 7.1.0.22908
class at_dru_solar_beam : public AreaTriggerEntityScript
{
public:
    at_dru_solar_beam() : AreaTriggerEntityScript("at_dru_solar_beam") {}

    struct at_dru_solar_beamAI : AreaTriggerAI
    {
        at_dru_solar_beamAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();
            if (!caster || !unit)
                return;

            if (caster->GetTypeId() != TYPEID_PLAYER)
                return;

            if (caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_DRUID_SOLAR_BEAM_SILENCE, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            Unit* caster = at->GetCaster();
            if (!caster || !unit)
                return;

            if (caster->GetTypeId() != TYPEID_PLAYER)
                return;

            if (Aura* solarBeam = unit->GetAura(SPELL_DRUID_SOLAR_BEAM_SILENCE, caster->GetGUID()))
                solarBeam->SetDuration(0);
        }
    };
};

enum UrsolsVortexSpells
{
    SPELL_DRUID_URSOLS_VORTEX_SLOW   = 127797,
    SPELL_DRUID_URSOLS_VORTEX_PULL   = 118283
};

// Ursol's Vortex - 102793
// AreaTriggerID - 314
// @Version : 7.1.0.22908
class at_dru_ursols_vortex : public AreaTriggerEntityScript
{
public:
    at_dru_ursols_vortex() : AreaTriggerEntityScript("at_dru_ursols_vortex") { }

    struct at_dru_ursols_vortexAI : AreaTriggerAI
    {
        at_dru_ursols_vortexAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (!caster->ToPlayer())
                return;

            if (caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_DRUID_URSOLS_VORTEX_SLOW, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (!caster->ToPlayer())
                return;

            if (Creature* tempSumm = caster->SummonCreature(WORLD_TRIGGER, at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 200))
            {
                tempSumm->setFaction(caster->getFaction());
                tempSumm->SetGuidValue(UNIT_FIELD_SUMMONEDBY, caster->GetGUID());
                PhasingHandler::InheritPhaseShift(tempSumm, caster);

                if (caster->IsValidAttackTarget(unit))
                {
                    // Was already pulled, we can let him leave, remove slow and pull aura.
                    if (unit->HasAura(SPELL_DRUID_URSOLS_VORTEX_PULL))
                    {
                        unit->RemoveAurasDueToSpell(SPELL_DRUID_URSOLS_VORTEX_PULL);
                        unit->RemoveAurasDueToSpell(SPELL_DRUID_URSOLS_VORTEX_SLOW);
                    }
                    else // Was not yet pulled, we pull him back
                    {
                        unit->CastSpell(tempSumm, SPELL_DRUID_URSOLS_VORTEX_PULL, true);
                    }
                }
            }
        }
    };
};

// Efflorescence
// NPC Id - 47649
// @Version : 7.1.0.22908
class npc_dru_efflorescence : public CreatureScript
{
public:
    npc_dru_efflorescence() : CreatureScript("npc_dru_efflorescence") {}

    class npc_dru_efflorescence_AI : public ScriptedAI
    {
    public:

        npc_dru_efflorescence_AI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            me->CastSpell(me, SPELL_DRUID_EFFLORESCENCE_DUMMY, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dru_efflorescence_AI(creature);
    }
};

void AddSC_druid_spell_scripts()
{
    // Spells Scripts
    new spell_dru_efflorescence();
    new spell_dru_efflorescence_aura();
    new spell_dru_efflorescence_heal();
    new spell_dru_primal_fury();
    new spell_dru_predatory_swiftness();
    new spell_dru_predatory_swiftness_aura();
    new spell_dru_lifebloom();
    new spell_dru_berserk();
    new spell_dru_sunfire();
    new spell_dru_balance_affinity_dps();
    new spell_dru_balance_affinity_resto();
    new spell_dru_ferocious_bite();
    new spell_dru_dash();
    new spell_dru_savage_roar();
    new spell_dru_survival_instincts();
    new spell_dru_swift_flight_passive();
    new spell_dru_wild_growth();
    new spell_dru_incarnation_chosen_of_elune();
    new spell_dru_incarnation_king_of_the_jungle();
    new spell_dru_incarnation_guardian_of_ursoc();
    new spell_dru_wild_charge_moonkin();
    new spell_dru_moonfire();
    new spell_dru_omen_of_clarity();
    new spell_dru_cat_form();
    new spell_dru_bear_form();
    new spell_dru_skull_bash();
    new spell_dru_stampeding_roar();
    new spell_dru_activate_cat_form();
    new spell_dru_killer_instinct();
    new spell_dru_living_seed();
    new spell_dru_infected_wound();
    new spell_dru_ysera_gift();
    new spell_dru_rake();
    new spell_dru_maim();
    new spell_dru_rip();
    new spell_dru_bloodtalons();
    new spell_dru_travel_form();
    new spell_dru_travel_form_aura();

    //7.3.2.25549
    RegisterSpellScript(spell_dru_thrash);
    
    RegisterAuraScript(spell_dru_thrash_periodic_damage);
    //7.3.2.25549 END

    //7.3.5.25996
    RegisterSpellScript(spell_dru_blessing_of_the_ancients);

    RegisterAuraScript(aura_dru_solar_empowerment);
    RegisterAuraScript(aura_dru_lunar_empowerment);
    RegisterAuraScript(aura_dru_astral_form);
    //7.3.5.25996 END

    // AreaTrigger Scripts
    new at_dru_solar_beam();
    new at_dru_starfall();
    new at_dru_ursols_vortex();

    // NPC Scripts
    new npc_dru_efflorescence();
}
