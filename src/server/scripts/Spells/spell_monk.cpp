/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
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
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Containers.h"
#include "Group.h"

enum MonkSpells
{
    SPELL_MONK_PROVOKE = 118635,
    SPELL_MONK_SOOTHING_MIST_VISUAL = 125955,
    SPELL_MONK_SOOTHING_MIST_ENERGIZE = 116335,
    SPELL_MONK_LIGHT_STAGGER = 124275,
    SPELL_MONK_MODERATE_STAGGER = 124274,
    SPELL_MONK_HEAVY_STAGGER = 124273,
    SPELL_MONK_CHI_TORPEDO_HEAL = 124040,
    SPELL_MONK_CHI_TORPEDO_DAMAGE = 117993,
    SPELL_MONK_FLYING_SERPENT_KICK = 101545,
    SPELL_MONK_FLYING_SERPENT_KICK_NEW = 115057,
    SPELL_MONK_FLYING_SERPENT_KICK_AOE = 123586,
    SPELL_MONK_TIGEREYE_BREW = 116740,
    SPELL_MONK_TIGEREYE_BREW_STACKS = 125195,
    SPELL_MONK_ELUSIVE_BREW_STACKS = 128939,
    SPELL_MONK_ELUSIVE_BREW = 115308,
    SPELL_MONK_KEG_SMASH_VISUAL = 123662,
    SPELL_MONK_KEG_SMASH_ENERGIZE = 127796,
    SPELL_MONK_WEAKENED_BLOWS = 115798,
    SPELL_MONK_DIZZYING_HAZE = 116330,
    SPELL_MONK_CLASH_CHARGE = 126452,
    SPELL_MONK_SPEAR_HAND_STRIKE_SILENCE = 116709,
    SPELL_MONK_CHI_BURST_DAMAGE = 130651,
    SPELL_MONK_CHI_BURST_HEAL = 130654,
    SPELL_MONK_ZEN_SPHERE_DAMAGE = 124098,
    SPELL_MONK_ZEN_SPHERE_HEAL = 124081,
    SPELL_MONK_ZEN_SPHERE_DETONATE_HEAL = 124101,
    SPELL_MONK_ZEN_SPHERE_DETONATE_DAMAGE = 125033,
    SPELL_MONK_HEALING_ELIXIRS_AURA = 122280,
    SPELL_MONK_HEALING_ELIXIRS_RESTORE_HEALTH = 122281,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHANNEL = 117952,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_HIDDEN_CD = 117953,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_AURA = 117959,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK = 117962,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC = 123332,
    SPELL_MONK_FORTIFYING_BREW_AURA = 120954,
    SPELL_MONK_GLYPH_OF_FORTIFYING_BREW = 124997,
    SPELL_MONK_BREATH_OF_FIRE_PERIODIC = 123725,
    SPELL_MONK_BREATH_OF_FIRE_CONFUSE = 123393,
    SPELL_MONK_GLYPH_OF_BREATH_OF_FIRE = 123394,
    SPELL_MONK_LEGACY_OF_THE_EMPEROR_RAID = 117666,
    SPELL_MONK_LEGACY_OF_THE_EMPEROR_ALLY = 117667,
    SPELL_MONK_EXPEL_HARM_AREA_DMG = 115129,
    SPELL_MONK_TOUCH_OF_DEATH_PLAYER = 124490,
    SPELL_MONK_ROLL = 109132,
    SPELL_MONK_ROLL_TRIGGER = 107427,
    SPELL_MONK_ITEM_PVP_GLOVES_BONUS = 124489,
    SPELL_MONK_DISABLE = 116095,
    SPELL_MONK_DISABLE_ROOT = 116706,
    SPELL_MONK_PARALYSIS = 115078,
    SPELL_MONK_SPINNING_CRANE_KICK = 107270,
    SPELL_MONK_SPINNING_CRANE_KICK_ENERGIZE = 129881,
    SPELL_MONK_BREWING_TIGEREYE_BREW = 123980,
    SPELL_MONK_TIGEREYE_BREW_BUFF = 125195,
    SPELL_MONK_TIGER_STRIKES = 120273,
    SPELL_MONK_ZEN_PILGRIMAGE = 126892,
    SPELL_MONK_ZEN_PILGRIMAGE_RETURN = 126895,
    SPELL_MONK_HEALING_SPHERE = 115460,
};

// 117952 - Crackling Jade Lightning
class spell_monk_crackling_jade_lightning : public SpellScriptLoader
{
    public:
    spell_monk_crackling_jade_lightning() : SpellScriptLoader("spell_monk_crackling_jade_lightning")
    { }

    class spell_monk_crackling_jade_lightning_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_crackling_jade_lightning_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_CRACKLING_JADE_LIGHTNING_AURA))
                return false;
            return true;
        }

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (GetCaster())
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_MONK_CRACKLING_JADE_LIGHTNING_AURA, true);
                GetCaster()->CastSpell(GetCaster(), SPELL_MONK_CRACKLING_JADE_LIGHTNING_AURA, true, NULL, aurEff);
                GetCaster()->CastSpell(GetCaster(), SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC, true);
            }
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetCaster())
            {
                GetCaster()->RemoveAura(SPELL_MONK_CRACKLING_JADE_LIGHTNING_AURA);
                GetCaster()->RemoveAura(SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC);
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_monk_crackling_jade_lightning_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_monk_crackling_jade_lightning_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_monk_crackling_jade_lightning_AuraScript();
    }
};

// 117959 Crackling - Jade Lightning
class spell_monk_crackling_jade_lightning_aura : public SpellScriptLoader
{
    public:
    spell_monk_crackling_jade_lightning_aura() : SpellScriptLoader("spell_monk_crackling_jade_lightning_aura")
    { }

    class spell_monk_crackling_jade_lightning_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_crackling_jade_lightning_aura_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_CRACKLING_JADE_LIGHTNING_HIDDEN_CD))
                return false;
            return true;
        }

        bool CheckProc(ProcEventInfo& /*eventInfo*/)
        {
            if (GetTarget()->HasAura(SPELL_MONK_CRACKLING_JADE_LIGHTNING_HIDDEN_CD))
                return false;

            // Just prevention against buggers
            Spell* currentChanneledSpell = GetTarget()->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
            if (!currentChanneledSpell || currentChanneledSpell->GetSpellInfo()->Id != SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHANNEL)
                return false;

            return true;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            GetTarget()->CastSpell(eventInfo.GetActor(), SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK, true);
            GetTarget()->CastSpell(GetTarget(), SPELL_MONK_CRACKLING_JADE_LIGHTNING_HIDDEN_CD, true);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_monk_crackling_jade_lightning_aura_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_monk_crackling_jade_lightning_aura_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_monk_crackling_jade_lightning_aura_AuraScript();
    }
};

class spell_monk_fortifying_brew : public SpellScriptLoader
{
    public:
    spell_monk_fortifying_brew() : SpellScriptLoader("spell_monk_fortifying_brew")
    { }

    class spell_monk_fortifying_brew_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_fortifying_brew_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_FORTIFYING_BREW_AURA) || !sSpellMgr->GetSpellInfo(SPELL_MONK_GLYPH_OF_FORTIFYING_BREW))
                return false;
            return true;
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            if (Unit* target = GetHitUnit())
            {
                int32 bp0 = GetEffectValue();
                int32 bp1 = -bp0;

                if (Aura* aura = target->GetAura(SPELL_MONK_GLYPH_OF_FORTIFYING_BREW))
                {
                    bp0 -= aura->GetEffect(EFFECT_1)->GetAmount();
                    bp1 -= aura->GetEffect(EFFECT_0)->GetAmount();
                }

                bp0 = CalculatePct(target->GetMaxHealth(), bp0);
                target->CastCustomSpell(target, SPELL_MONK_FORTIFYING_BREW_AURA, &bp0, &bp1, NULL, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_monk_fortifying_brew_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_monk_fortifying_brew_SpellScript();
    }
};

class spell_monk_breath_of_fire : public SpellScriptLoader
{
    public:
    spell_monk_breath_of_fire() : SpellScriptLoader("spell_monk_breath_of_fire")
    { }

    class spell_monk_breath_of_fire_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_breath_of_fire_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_BREATH_OF_FIRE_PERIODIC) || !sSpellMgr->GetSpellInfo(SPELL_MONK_DIZZYING_HAZE))
                return false;
            return true;
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            if (!GetHitUnit())
                return;

            if (GetHitUnit()->HasAura(SPELL_MONK_DIZZYING_HAZE))
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_MONK_BREATH_OF_FIRE_PERIODIC, true);
                if (GetCaster()->HasAura(SPELL_MONK_GLYPH_OF_BREATH_OF_FIRE))
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_MONK_BREATH_OF_FIRE_CONFUSE, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_monk_breath_of_fire_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_monk_breath_of_fire_SpellScript();
    }
};

class spell_monk_legacy_of_the_emperor : public SpellScriptLoader
{
    public:
    spell_monk_legacy_of_the_emperor() : SpellScriptLoader("spell_monk_legacy_of_the_emperor")
    { }

    class spell_monk_legacy_of_the_emperor_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_legacy_of_the_emperor_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_LEGACY_OF_THE_EMPEROR_RAID))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (!GetHitUnit())
                return;

            if (GetCaster()->IsInRaidWith(GetHitUnit()))
                GetCaster()->CastSpell(GetCaster(), SPELL_MONK_LEGACY_OF_THE_EMPEROR_RAID, true);
            else
                GetCaster()->CastSpell(GetHitUnit(), SPELL_MONK_LEGACY_OF_THE_EMPEROR_ALLY, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_monk_legacy_of_the_emperor_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_monk_legacy_of_the_emperor_SpellScript();
    }
};

class spell_monk_expel_harm : public SpellScriptLoader
{
    public:
    spell_monk_expel_harm() : SpellScriptLoader("spell_monk_expel_harm")
    { }

    class spell_monk_expel_harm_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_expel_harm_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_EXPEL_HARM_AREA_DMG))
                return false;
            return true;
        }

        void DealAreaDamage(SpellEffIndex index)
        {
            if (!GetHitUnit())
                return;

            int32 dmg = GetHitHeal() / 2;
            if (dmg > 0)
                GetHitUnit()->CastCustomSpell(SPELL_MONK_EXPEL_HARM_AREA_DMG, SPELLVALUE_BASE_POINT0, dmg, GetHitUnit(), true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_monk_expel_harm_SpellScript::DealAreaDamage, EFFECT_0, SPELL_EFFECT_HEAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_monk_expel_harm_SpellScript();
    }
};

class spell_monk_touch_of_death : public SpellScriptLoader
{
    public:
    spell_monk_touch_of_death() : SpellScriptLoader("spell_monk_touch_of_death")
    { }

    class spell_monk_touch_of_death_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_touch_of_death_SpellScript);

        SpellCastResult CheckRequirement()
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetExplTargetUnit())
                {
                    if (target->ToPlayer())
                    {
                        if (caster->HasAura(SPELL_MONK_TOUCH_OF_DEATH_PLAYER))
                        {
                            if (target->HealthAbovePct(GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints))
                                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
                        }
                        else
                            return SPELL_FAILED_TARGET_IS_PLAYER;
                    }
                    else
                    {
                        if (target->GetHealth() > caster->GetHealth())
                            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
                    }
                }
            }
            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_monk_touch_of_death_SpellScript::CheckRequirement);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_monk_touch_of_death_SpellScript();
    }
};

// Roll - 109132 or Roll (3 charges) - 121827
class spell_monk_roll : public SpellScriptLoader
{
    public:
    spell_monk_roll() : SpellScriptLoader("spell_monk_roll")
    { }

    class spell_monk_roll_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_roll_SpellScript);

        bool Validate(SpellInfo const* /*spell*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_ROLL))
                return false;
            return true;
        }

        void HandleBeforeCast()
        {
            Aura* aur = GetCaster()->AddAura(SPELL_MONK_ROLL_TRIGGER, GetCaster());
            if (!aur)
                return;

            AuraApplication* app = aur->GetApplicationOfTarget(GetCaster()->GetGUID());
            if (!app)
                return;

            app->ClientUpdate();
        }

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            if (!caster || caster->GetTypeId() != TYPEID_PLAYER)
                return;

            caster->CastSpell(caster, SPELL_MONK_ROLL_TRIGGER, true);

            if (caster->HasAura(SPELL_MONK_ITEM_PVP_GLOVES_BONUS))
                caster->RemoveAurasByType(SPELL_AURA_MOD_DECREASE_SPEED);
        }

        void Register()
        {
            BeforeCast += SpellCastFn(spell_monk_roll_SpellScript::HandleBeforeCast);
            AfterCast += SpellCastFn(spell_monk_roll_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_roll_SpellScript();
    }
};

// Disable - 116095
class spell_monk_disable : public SpellScriptLoader
{
    public:
    spell_monk_disable() : SpellScriptLoader("spell_monk_disable")
    { }

    class spell_monk_disable_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_disable_AuraScript);

        bool Validate(SpellInfo const* /*spell*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_DISABLE))
                return false;
            return true;
        }

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (aurEff->GetTickNumber() % aurEff->GetTotalTicks() != 0) // last tick of duration
                return;

            if (Unit* caster = GetCaster())
                if (Unit* owner = GetUnitOwner())
                    if ((owner->GetDistance2d(caster) < 10.0f) && caster->IsAlive())
                        aurEff->GetBase()->RefreshDuration();
        }

        void AfterReapply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetTarget())
                    caster->CastSpell(target, SPELL_MONK_DISABLE_ROOT, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_disable_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            AfterEffectApply += AuraEffectRemoveFn(spell_monk_disable_AuraScript::AfterReapply, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAPPLY);
        }
    };


    AuraScript* GetAuraScript() const
    {
        return new spell_monk_disable_AuraScript();
    }
};

// Paralysis - 115078
class spell_monk_paralysis : public SpellScriptLoader
{
    public:
    spell_monk_paralysis() : SpellScriptLoader("spell_monk_paralysis")
    { }

    class spell_monk_paralysis_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_paralysis_SpellScript);

        void HandleOnHit()
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (target->isInBack(caster))
                    {
                        if (AuraApplication* aura = target->GetAuraApplication(SPELL_MONK_PARALYSIS))
                        {
                            Aura* Paralysis = aura->GetBase();
                            int32 maxDuration = Paralysis->GetMaxDuration();
                            int32 newDuration = maxDuration * 2;
                            Paralysis->SetDuration(newDuration);

                            if (newDuration > maxDuration)
                                Paralysis->SetMaxDuration(newDuration);
                        }
                    }

                    if (target->ToPlayer())
                    {
                        if (AuraApplication* aura = target->GetAuraApplication(SPELL_MONK_PARALYSIS))
                        {
                            Aura* Paralysis = aura->GetBase();
                            int32 maxDuration = Paralysis->GetMaxDuration();
                            int32 newDuration = maxDuration / 2;
                            Paralysis->SetDuration(newDuration);
                            Paralysis->SetMaxDuration(newDuration);
                        }
                    }
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_paralysis_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_paralysis_SpellScript();
    }
};


// Spinning Crane Kick - 107270
class spell_monk_spinning_crane_kick : public SpellScriptLoader
{
    public:
    spell_monk_spinning_crane_kick() : SpellScriptLoader("spell_monk_spinning_crane_kick")
    { }

    class spell_monk_spinning_crane_kick_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_spinning_crane_kick_SpellScript);

        bool Validate(SpellInfo const* /*spell*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_SPINNING_CRANE_KICK))
                return false;
            return true;
        }

        void HandleOnCast()
        {
            if (Unit* caster = GetCaster())
            {
                std::list<Unit*> targets;
                Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(caster, caster, 8.0f);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(caster, targets, u_check);
                caster->VisitNearbyObject(8.0f, searcher);
                if (targets.size() >= 3)
                    caster->CastSpell(caster, SPELL_MONK_SPINNING_CRANE_KICK_ENERGIZE, true);
            }
        }

        void Register()
        {
            OnCast += SpellCastFn(spell_monk_spinning_crane_kick_SpellScript::HandleOnCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_spinning_crane_kick_SpellScript();
    }
};

// Brewing: Tigereye Brew - 123980
class spell_monk_brewing_tigereye_brew : public SpellScriptLoader
{
    public:
    spell_monk_brewing_tigereye_brew() : SpellScriptLoader("spell_monk_brewing_tigereye_brew")
    { }

    class spell_monk_brewing_tigereye_brew_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_brewing_tigereye_brew_AuraScript);

        bool Validate(SpellInfo const* /*spell*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_BREWING_TIGEREYE_BREW))
                return false;
            return true;
        }

        uint32 chiConsumed;

        void HandleOnEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            chiConsumed = 0;
        }

        void SetData(uint32 type, uint32 data)
        {
            if (Unit* caster = GetCaster())
            {
                chiConsumed += data;
                if (chiConsumed >= 4)
                {
                    caster->CastSpell(caster, SPELL_MONK_TIGEREYE_BREW_BUFF, true);
                    chiConsumed -= 4;
                }
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_monk_brewing_tigereye_brew_AuraScript::HandleOnEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };


    AuraScript* GetAuraScript() const
    {
        return new spell_monk_brewing_tigereye_brew_AuraScript();
    }
};

#define maxStack 10

// Tigereye Brew - 116740
class spell_monk_tigereye_brew : public SpellScriptLoader
{
    public:
    spell_monk_tigereye_brew() : SpellScriptLoader("spell_monk_tigereye_brew")
    { }

    class spell_monk_tigereye_brew_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_tigereye_brew_AuraScript);

        bool Validate(SpellInfo const* /*spell*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_TIGEREYE_BREW))
                return false;
            return true;
        }

        void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Aura* aur = caster->GetAura(SPELL_MONK_TIGEREYE_BREW_BUFF))
                {
                    uint16 stack = aur->GetStackAmount();

                    // Max bonus = 60%
                    if (stack > maxStack)
                        amount *= maxStack;
                    else
                        amount *= stack;
                }
            }
        }

        void Register()
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_monk_tigereye_brew_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_monk_tigereye_brew_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_HEALING_DONE_PERCENT);
        }
    };


    AuraScript* GetAuraScript() const
    {
        return new spell_monk_tigereye_brew_AuraScript();
    }

    class spell_monk_tigereye_brew_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_tigereye_brew_SpellScript);

        void HandleAfterCast()
        {
            if (Unit* caster = GetCaster())
            {
                if (Aura* aur = caster->GetAura(SPELL_MONK_TIGEREYE_BREW_BUFF))
                {
                    uint16 stack = aur->GetStackAmount();
                    // Removes at most 10 stacks
                    if (stack > maxStack)
                    {
                        // One of the stacks is already removed automatically
                        aur->SetStackAmount(stack - maxStack + 1);
                    }
                    else
                        caster->RemoveAura(SPELL_MONK_TIGEREYE_BREW_BUFF);
                }
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_monk_tigereye_brew_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_tigereye_brew_SpellScript();
    }
};

// Tiger Strikes - 120273
class spell_monk_tiger_strikes : public SpellScriptLoader
{
    public:
    spell_monk_tiger_strikes() : SpellScriptLoader("spell_monk_tiger_strikes")
    { }

    class spell_monk_tiger_strikes_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_tiger_strikes_AuraScript);

        bool Validate(SpellInfo const* /*spell*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_TIGER_STRIKES))
                return false;
            return true;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = eventInfo.GetDamageInfo()->GetVictim())
                    caster->CastSpell(target, 120274, true);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_monk_tiger_strikes_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_MOD_MELEE_HASTE_3);
        }
    };


    AuraScript* GetAuraScript() const
    {
        return new spell_monk_tiger_strikes_AuraScript();
    }
};

// Zen Pilgrimage - 126892
class spell_monk_zen_pilgrimage : public SpellScriptLoader
{
    public:
    spell_monk_zen_pilgrimage() : SpellScriptLoader("spell_monk_zen_pilgrimage")
    { }

    class spell_monk_zen_pilgrimage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_zen_pilgrimage_SpellScript);

        bool Validate(SpellInfo const* /*spell*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_ZEN_PILGRIMAGE))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Player* player = caster->ToPlayer())
                    player->SaveRecallPosition();
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_monk_zen_pilgrimage_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_TELEPORT_UNITS);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_zen_pilgrimage_SpellScript();
    }
};

// Zen Pilgrimage: Return - 126895
class spell_monk_zen_pilgrimage_return : public SpellScriptLoader
{
    public:
    spell_monk_zen_pilgrimage_return() : SpellScriptLoader("spell_monk_zen_pilgrimage_return")
    { }

    class spell_monk_zen_pilgrimage_return_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_zen_pilgrimage_return_SpellScript);

        bool Validate(SpellInfo const* /*spell*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_ZEN_PILGRIMAGE_RETURN))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Player* player = caster->ToPlayer())
                    player->TeleportTo(player->m_recallMap, player->m_recallX, player->m_recallY, player->m_recallZ, player->m_recallO);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_monk_zen_pilgrimage_return_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_zen_pilgrimage_return_SpellScript();
    }
};

enum Enveloping
{
    SPELL_MONK_ENVELOPING_MIST_HEAL = 132120
};

// Enveloping Mist - 124682
class spell_monk_enveloping_mist : public SpellScriptLoader
{
    public:
    spell_monk_enveloping_mist() : SpellScriptLoader("spell_monk_enveloping_mist")
    { }

    class spell_monk_enveloping_mist_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_enveloping_mist_SpellScript);

        void HandleAfterCast()
        {
            if (Player* _player = GetCaster()->ToPlayer())
                if (Unit* target = GetExplTargetUnit())
                    _player->CastSpell(target, SPELL_MONK_ENVELOPING_MIST_HEAL, true);
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_monk_enveloping_mist_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_enveloping_mist_SpellScript();
    }
};

enum Surging
{
    SPELL_MONK_SURGING_MIST_HEAL = 116995
};

// Surging Mist - 116694
class spell_monk_surging_mist : public SpellScriptLoader
{
    public:
    spell_monk_surging_mist() : SpellScriptLoader("spell_monk_surging_mist")
    { }

    class spell_monk_surging_mist_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_surging_mist_SpellScript);

        void HandleAfterCast()
        {
            if (Player* _player = GetCaster()->ToPlayer())
                if (Unit* target = GetExplTargetUnit())
                    _player->CastSpell(target, SPELL_MONK_SURGING_MIST_HEAL, true);
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_monk_surging_mist_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_surging_mist_SpellScript();
    }
};

enum Renewing
{
    CREATURE_SERPENT_ID = 60849,
    SPELL_MONK_GLYPH_OF_RENEWING_MIST = 123334,
    SPELL_MONK_RENEWING_MIST_HOT = 116611,
    SPELL_MONK_RENEWING_MIST_JUMP_AURA = 119607
};

enum Uplift
{
    SPELL_MONK_UPLIFT_ALLOWING_CAST = 123757,
    SPELL_MONK_ITEM_2_S12_MISTWEAVER = 131561
};

enum ManaTea
{
    SPELL_MONK_MANA_TEA_REGEN = 115294,
    SPELL_MONK_MANA_TEA_STACKS = 115867,
    SPELL_MONK_PLUS_ONE_MANA_TEA = 123760
};

// Renewing Mist - 119611
class spell_monk_renewing_mist : public SpellScriptLoader
{
    public:
    spell_monk_renewing_mist() : SpellScriptLoader("spell_monk_renewing_mist")
    { }

    class spell_monk_renewing_mist_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_renewing_mist_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                std::list<Unit*> playerList;
                std::list<Creature*> tempList;
                std::list<Creature*> statueList;
                Creature* statue;

                _player->GetPartyMembers(playerList);

                if (playerList.size() > 1)
                {
                    playerList.sort(Trinity::HealthPctOrderPred());
                    playerList.resize(1);
                }

                _player->GetCreatureListWithEntryInGrid(tempList, CREATURE_SERPENT_ID, 100.0f);
                _player->GetCreatureListWithEntryInGrid(statueList, CREATURE_SERPENT_ID, 100.0f);

                // Remove other players jade statue
                for (std::list<Creature*>::iterator i = tempList.begin(); i != tempList.end(); ++i)
                {
                    Unit* owner = (*i)->GetOwner();
                    if (owner && owner == _player && (*i)->IsSummon())
                        continue;

                    statueList.remove((*i));
                }

                for (auto itr : playerList)
                {
                    if (statueList.size() == 1)
                    {
                        for (auto itrBis : statueList)
                            statue = itrBis;

                        if (statue && (statue->IsPet() || statue->IsGuardian()))
                        {
                            if (statue->GetOwner() && statue->GetOwner()->GetGUID() == _player->GetGUID())
                            {
                                _player->AddAura(SPELL_MONK_RENEWING_MIST_HOT, itr);
                                _player->CastSpell(itr, SPELL_MONK_RENEWING_MIST_JUMP_AURA, true);
                            }
                        }
                    }
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_renewing_mist_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_renewing_mist_SpellScript();
    }

    class spell_monk_renewing_mist_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_renewing_mist_AuraScript);

        uint32 update;
        uint8  spreadCount;

        bool Validate(SpellInfo const* /*spell*/)
        {
            update = 0;
            spreadCount = 1;

            if (!sSpellMgr->GetSpellInfo(119611))
                return false;
            return true;
        }

        void OnUpdate(uint32 diff, AuraEffect* aurEff)
        {
            update += diff;

            if (update >= 2500)
            {
                if (GetCaster())
                    if (Player* _player = GetCaster()->ToPlayer())
                        _player->CastSpell(_player, SPELL_MONK_UPLIFT_ALLOWING_CAST, true);

                update = 0;
            }
        }

        void OnTick(AuraEffect const* aurEff)
        {
            if (Unit* caster = GetCaster())
            {
                if (Player* _player = caster->ToPlayer())
                {
                    Player* target = GetTarget()->ToPlayer();
                    Unit* newTarget;

                    if (!target)
                        return;

                    if (target->HasAura(SPELL_MONK_RENEWING_MIST_JUMP_AURA, _player->GetGUID()))
                    {
                        if (_player->HasAura(SPELL_MONK_GLYPH_OF_RENEWING_MIST))
                            newTarget = target->GetNextRandomRaidMemberOrPet(40.0f);
                        else
                            newTarget = target->GetNextRandomRaidMemberOrPet(20.0f);

                        if (!newTarget)
                            return;

                        if (Aura* renewingMistJump = target->GetAura(SPELL_MONK_RENEWING_MIST_JUMP_AURA, _player->GetGUID()))
                        {
                            if (renewingMistJump->GetCharges() > 1)
                            {
                                renewingMistJump->DropCharge();

                                // Spreads Renewing Mists 3 times maximum
                                if (Aura* renewingMistHot = target->GetAura(SPELL_MONK_RENEWING_MIST_HOT, _player->GetGUID()))
                                    _player->AddAura(SPELL_MONK_RENEWING_MIST_HOT, newTarget);
                            }
                            else
                            {
                                target->RemoveAura(SPELL_MONK_RENEWING_MIST_JUMP_AURA, _player->GetGUID());

                                // Spreads Renewing Mists 3 times maximum
                                if (Aura* renewingMistHot = target->GetAura(SPELL_MONK_RENEWING_MIST_HOT, _player->GetGUID()))
                                    _player->AddAura(SPELL_MONK_RENEWING_MIST_HOT, newTarget);
                            }
                        }
                    }
                }
            }
        }

        void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes mode)
        {
            if (GetCaster())
            {
                if (Aura* uplift = GetCaster()->GetAura(SPELL_MONK_UPLIFT_ALLOWING_CAST, GetCaster()->GetGUID()))
                    GetCaster()->RemoveAura(SPELL_MONK_UPLIFT_ALLOWING_CAST, GetCaster()->GetGUID());

                if (GetCaster()->HasAura(SPELL_MONK_ITEM_2_S12_MISTWEAVER))
                {
                    AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                    if (removeMode == AURA_REMOVE_BY_EXPIRE)
                    {
                        GetCaster()->CastSpell(GetCaster(), SPELL_MONK_MANA_TEA_STACKS, true);
                        GetCaster()->CastSpell(GetCaster(), SPELL_MONK_PLUS_ONE_MANA_TEA, true);
                    }
                }
            }
        }

        void Register() override
        {
            //OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_renewing_mist_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
            //OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_monk_renewing_mist_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
            //OnEffectRemove += AuraEffectApplyFn(spell_monk_renewing_mist_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_monk_renewing_mist_AuraScript();
    }
};

// Healing Sphere 115460
class spell_monk_healing_sphere : public SpellScriptLoader
{
    public:
    spell_monk_healing_sphere() : SpellScriptLoader("spell_monk_healing_sphere")
    { }

    class spell_monk_healing_sphere_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_healing_sphere_SpellScript);

        void Sphere(SpellEffIndex /*eff*/)
        {
            /*int32 count = GetCaster()->CountAreaTrigger(SPELL_MONK_HEALING_SPHERE);
            if (count >= 3)
            {
                std::list<AreaTrigger*> sphereList;
                GetCaster()->GetAreaTriggerList(sphereList, SPELL_MONK_HEALING_SPHERE);
                if (!sphereList.empty())
                {
                    sphereList.sort(Trinity::AreaTriggerDurationPctOrderPred());
                    for (auto itr : sphereList)
                    {
                        AreaTrigger* sphere = itr;
                        sphere->SetDuration(0);
                        break;
                    }
                }
            }*/

        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_monk_healing_sphere_SpellScript::Sphere, EFFECT_0, SPELL_EFFECT_CREATE_AREATRIGGER);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_healing_sphere_SpellScript();
    }
};

/*######
## npc_transcendence_spirit -- 54569
######*/

enum TranscendenceSpiritSpells
{
    SPELL_SPAWN_TRANS = 102141,
    SPELL_INITIALIZE_IMAGES = 102284,
    SPELL_CLONE_CASTER = 119051,
    SPELL_VISUAL_SPIRIT = 119053,
    SPELL_MEDITATE = 124416,
    SPELL_ROOT_FOR_EVER = 31366
};

enum transcendenceActions
{
    ACTION_TELEPORT = 1
};

class npc_transcendence_spirit : public CreatureScript
{
    public:
    npc_transcendence_spirit() : CreatureScript("npc_transcendence_spirit")
    { }

    struct npc_transcendence_spiritAI : public ScriptedAI
    {
        npc_transcendence_spiritAI(Creature* c) : ScriptedAI(c)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void JustDied(Unit* who) override
        {
           /* if (me->GetOwner() && me->GetOwner()->GetTypeId() == TYPEID_PLAYER)
                me->GetOwner()->ToPlayer()->setTransForm(NULL);*/
        }

        void EnterCombat(Unit* /*who*/) override
        { }
        void AttackStart(Unit* /*who*/) override
        { }

        void Reset() override
        {
            if (!me->HasAura(SPELL_MEDITATE))
                me->AddAura(SPELL_MEDITATE, me);
        }

        void CorpseRemoved(uint32& /*respawnDelay*/) override
        {
            /*if (me->GetOwner() && me->GetOwner()->GetTypeId() == TYPEID_PLAYER)
                me->GetOwner()->ToPlayer()->setTransForm(NULL);*/
        }

        void IsSummonedBy(Unit* owner) override
        {
            if (owner && owner->GetTypeId() == TYPEID_PLAYER)
            {
                //owner->ToPlayer()->SetTransSpirit(me);
            }
            else
                me->DespawnOrUnsummon();
        }
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new npc_transcendence_spiritAI(creature);
    }
};

// 102141 - Transcendence
class spell_monk_transcendence : public SpellScriptLoader
{
    public:
    spell_monk_transcendence() : SpellScriptLoader("spell_monk_transcendence")
    { }

    class spell_monk_transcendence_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_transcendence_SpellScript);

        void Despawn()
        {
            /*if (Player* player = GetCaster()->ToPlayer())
                if (Creature* spirit = player->GetTransSpirit())
                    spirit->DespawnOrUnsummon();*/
        }

        void Visualize()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                /*if (Creature* spirit = player->GetTransSpirit())
                {
                    player->CastSpell(spirit, SPELL_CLONE_CASTER);
                    spirit->AddAura(SPELL_VISUAL_SPIRIT, spirit);
                    spirit->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    spirit->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    spirit->CastSpell(spirit, SPELL_MEDITATE);
                    spirit->AddAura(SPELL_ROOT_FOR_EVER, spirit);
                }*/
            }
        }

        void Register()
        {
            BeforeCast += SpellCastFn(spell_monk_transcendence_SpellScript::Despawn);
            AfterCast += SpellCastFn(spell_monk_transcendence_SpellScript::Visualize);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_transcendence_SpellScript();
    }
};

// 119996 - Transcendence Transfer
class spell_monk_transcendence_transfer : public SpellScriptLoader
{
    public:
    spell_monk_transcendence_transfer() : SpellScriptLoader("spell_monk_transcendence_transfer")
    { }

    class spell_monk_transcendence_transfer_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_transcendence_transfer_SpellScript);

        SpellCastResult CheckCast()
        {
            if (GetCaster() && GetCaster()->ToPlayer())
            {
                Player* player = GetCaster()->ToPlayer();
               /* if (Creature* spirit = player->GetTransSpirit())
                {
                    float distance = 40.0f;

                    if (player->GetExactDist2d(spirit->GetPositionX(), spirit->GetPositionY()) <= distance)
                        return SPELL_CAST_OK;
                    else if (player->GetExactDist2d(spirit->GetPositionX(), spirit->GetPositionY()) >= distance)
                        return SPELL_FAILED_OUT_OF_RANGE;
                }
                else
                    return SPELL_FAILED_NO_PET;*/
            }

            return SPELL_FAILED_DONT_REPORT;
        }

        void Cast()
        {
            if (GetCaster() && GetCaster()->ToPlayer())
            {
                Player* player = GetCaster()->ToPlayer();

               /* if (Creature* spirit = player->GetTransSpirit())
                {
                    float distance = 40.0f;
                    if (player->GetExactDist2d(spirit->GetPositionX(), spirit->GetPositionY()) <= distance)
                    {
                        float petX, petY, petZ;
                        uint32 petMapId;
                        spirit->GetPosition(petX, petY, petZ);
                        petMapId = spirit->GetMapId();

                        spirit->DespawnOrUnsummon();
                        player->TeleportTo(petMapId, petX, petY, petZ, 0.0f);
                        player->CastSpell(player, SPELL_SPAWN_TRANS);
                    }
                }*/
            }

        }

        void Register()
        {
            OnCast += SpellCastFn(spell_monk_transcendence_transfer_SpellScript::Cast);
            OnCheckCast += SpellCheckCastFn(spell_monk_transcendence_transfer_SpellScript::CheckCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_transcendence_transfer_SpellScript();
    }
};

enum Karma
{
    SPELL_MONK_TOUCH_OF_KARMA_REDIRECT_DAMAGE = 124280
};

// Touch of Karma - 122470
class spell_monk_touch_of_karma : public SpellScriptLoader
{
    public:
    spell_monk_touch_of_karma() : SpellScriptLoader("spell_monk_touch_of_karma")
    { }

    class spell_monk_touch_of_karma_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_touch_of_karma_AuraScript);

        uint32 totalAbsorbAmount;

        bool Load()
        {
            totalAbsorbAmount = 0;
            return true;
        }

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
        {
            if (GetCaster())
                amount = GetCaster()->GetMaxHealth();
        }

        void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            if (Unit* caster = dmgInfo.GetVictim())
            {
                if (Unit* attacker = dmgInfo.GetAttacker())
                {
                    totalAbsorbAmount += dmgInfo.GetDamage();

                    if (attacker->HasAura(aurEff->GetSpellInfo()->Id, caster->GetGUID()))
                        caster->CastCustomSpell(SPELL_MONK_TOUCH_OF_KARMA_REDIRECT_DAMAGE, SPELLVALUE_BASE_POINT0, (totalAbsorbAmount / 16), attacker);
                }
            }
        }

        void Register()
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_monk_touch_of_karma_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_monk_touch_of_karma_AuraScript::OnAbsorb, EFFECT_1);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_monk_touch_of_karma_AuraScript();
    }
};

struct auraData
{
    auraData(uint32 id, uint64 casterGUID) : m_id(id), m_casterGuid(casterGUID)
    { }
    uint32 m_id;
    uint64 m_casterGuid;
};

// Diffuse Magic - 122783
class spell_monk_diffuse_magic : public SpellScriptLoader
{
    public:
    spell_monk_diffuse_magic() : SpellScriptLoader("spell_monk_diffuse_magic")
    { }

    class spell_monk_diffuse_magic_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_diffuse_magic_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                std::set<auraData*> auraListToRemove;
                Unit::AuraApplicationMap AuraList = _player->GetAppliedAuras();
                for (Unit::AuraApplicationMap::iterator iter = AuraList.begin(); iter != AuraList.end(); ++iter)
                {
                    Aura* aura = iter->second->GetBase();
                    if (!aura)
                        continue;

                    Unit* caster = aura->GetCaster();
                    if (!caster || caster->GetGUID() == _player->GetGUID())
                        continue;

                    if (!caster->IsWithinDist(_player, 40.0f))
                        continue;

                    if (aura->GetSpellInfo()->IsPositive())
                        continue;

                    if (!(aura->GetSpellInfo()->GetSchoolMask() & SPELL_SCHOOL_MASK_MAGIC))
                        continue;

                    _player->AddAura(aura->GetSpellInfo()->Id, caster);

                    if (Aura* targetAura = caster->GetAura(aura->GetSpellInfo()->Id, _player->GetGUID()))
                    {
                        for (int i = 0; i < MAX_SPELL_EFFECTS; ++i)
                        {
                            if (targetAura->GetEffect(i) && aura->GetEffect(i))
                            {
                                AuraEffect* auraEffect = _player->GetAuraEffect(aura->GetSpellInfo()->Id, i);
                                if (!auraEffect)
                                    continue;

                                int32 damage = auraEffect->GetAmount();

                                // need to check auraEffect pointer here !!
                                if (auraEffect->GetAuraType() == SPELL_AURA_PERIODIC_DAMAGE ||
                                    auraEffect->GetAuraType() == SPELL_AURA_PERIODIC_DAMAGE_PERCENT)
                                    //damage = caster->SpellDamageBonusDone(_player, aura->GetSpellInfo(), damage, DOT, auraEffect->GetBase()->GetStackAmount());

                                targetAura->GetEffect(i)->SetAmount(damage);
                            }
                        }
                    }

                    auraListToRemove.insert(new auraData(aura->GetSpellInfo()->Id, caster->GetGUID().GetEntry()));
                }

                for (std::set<auraData*>::iterator itr = auraListToRemove.begin(); itr != auraListToRemove.end(); ++itr)
                {
                    //_player->RemoveAura((*itr)->m_id, (*itr)->m_casterGuid);
                    delete (*itr);
                }

                auraListToRemove.clear();
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_diffuse_magic_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_diffuse_magic_SpellScript();
    }
};

enum BlackOx // tehee
{
    MONK_NPC_BLACK_OX_STATUE = 61146,
    SPELL_MONK_GUARD = 115295
};

// Summon Black Ox Statue - 115315
class spell_monk_black_ox_statue : public SpellScriptLoader
{
    public:
    spell_monk_black_ox_statue() : SpellScriptLoader("spell_monk_black_ox_statue")
    { }

    class spell_monk_black_ox_statue_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_black_ox_statue_SpellScript);

            void HandleSummon(SpellEffIndex effIndex)
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                PreventHitDefaultEffect(effIndex);

                const SpellInfo* spell = GetSpellInfo();
                std::list<Creature*> tempList;
                std::list<Creature*> blackOxList;

                player->GetCreatureListWithEntryInGrid(tempList, MONK_NPC_BLACK_OX_STATUE, 500.0f);

                for (auto itr : tempList)
                    blackOxList.push_back(itr);

                // Remove other players jade statue
                for (std::list<Creature*>::iterator i = tempList.begin(); i != tempList.end(); ++i)
                {
                    Unit* owner = (*i)->GetOwner();
                    if (owner && owner == player && (*i)->IsSummon())
                        continue;

                    blackOxList.remove((*i));
                }

                // 1 statue max
                if ((int32) blackOxList.size() >= spell->GetEffect(effIndex)->BasePoints)
                    blackOxList.back()->ToTempSummon()->UnSummon();

                Position pos;
                GetExplTargetDest()->GetPosition();
                const SummonPropertiesEntry* properties = sSummonPropertiesStore.LookupEntry(spell->GetEffect(effIndex)->MiscValueB);
                TempSummon* summon = player->SummonCreature(spell->GetEffect(effIndex)->MiscValue, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, spell->GetDuration());
                if (!summon)
                    return;

                //summon->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, player->GetGUID());
                summon->setFaction(player->getFaction());
                summon->SetUInt32Value(UNIT_FIELD_CREATEDBY, GetSpellInfo()->Id);
                summon->SetMaxHealth(player->CountPctFromMaxHealth(50));
                summon->SetHealth(summon->GetMaxHealth());
            }
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_monk_black_ox_statue_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_black_ox_statue_SpellScript();
    }

    class spell_monk_black_ox_statue_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_black_ox_statue_AuraScript);

        uint32 damageDealed;

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            damageDealed = 0;
        }

        void SetData(uint32 type, uint32 data)
        {
            if (!GetCaster())
                return;

            if (Player* _plr = GetCaster()->ToPlayer())
            {
                uint32 value = _plr->GetTotalAttackPowerValue(BASE_ATTACK) * 16;

                damageDealed += data;

                if (damageDealed >= value)
                {
                    damageDealed = 0;

                    std::list<Creature*> tempList;
                    std::list<Creature*> statueList;

                    _plr->GetCreatureListWithEntryInGrid(tempList, MONK_NPC_BLACK_OX_STATUE, 100.0f);
                    _plr->GetCreatureListWithEntryInGrid(statueList, MONK_NPC_BLACK_OX_STATUE, 100.0f);

                    // Remove other players' ox statue
                    for (auto itr : tempList)
                    {
                        Unit* owner = itr->GetOwner();
                        if (owner && owner->GetGUID() == _plr->GetGUID() && itr->IsSummon())
                            continue;

                        statueList.remove(itr);
                    }

                    if (!statueList.empty() && statueList.size() == 1)
                    {
                        for (auto itr : statueList)
                        {
                            if (itr && (itr->IsPet() || itr->IsGuardian()))
                            {
                                if (itr->GetOwner() && itr->GetOwner()->GetGUID() == _plr->GetGUID())
                                {
                                    if (Group* _grp = _plr->GetGroup())
                                    {
                                        for (GroupReference* itr = _grp->GetFirstMember(); itr != NULL; itr = itr->next())
                                            if (Player* member = itr->GetSource())
                                            {
                                                if (member->GetGUID() == _plr->GetGUID())
                                                    continue;

                                                member->CastSpell(member, SPELL_MONK_GUARD, true);
                                                break;
                                            }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        void Register()
        {
            AfterEffectApply += AuraEffectApplyFn(spell_monk_black_ox_statue_AuraScript::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_monk_black_ox_statue_AuraScript();
    }
};

// Guard - 115295
class spell_monk_guard : public SpellScriptLoader
{
    public:
    spell_monk_guard() : SpellScriptLoader("spell_monk_guard")
    { }

    class spell_monk_guard_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_guard_AuraScript);

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
        {
            if (!GetCaster())
                return;

            if (Player* _plr = GetCaster()->ToPlayer())
                amount += int32(_plr->GetTotalAttackPowerValue(BASE_ATTACK) * 1.971f);
            else if (GetCaster()->GetOwner()) // For Black Ox Statue
            {
                if (Player* _plr = GetCaster()->GetOwner()->ToPlayer())
                    amount += int32(_plr->GetTotalAttackPowerValue(BASE_ATTACK) * 1.971f);
            }
        }

        void Register()
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_monk_guard_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_monk_guard_AuraScript();
    }
};

enum Zen
{
    SPELL_MONK_ZEN_FLIGHT = 125883
};

// Glyph of Zen Flight - 125893
class spell_monk_glyph_of_zen_flight : public SpellScriptLoader
{
    public:
    spell_monk_glyph_of_zen_flight() : SpellScriptLoader("spell_monk_glyph_of_zen_flight")
    { }

    class spell_monk_glyph_of_zen_flight_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_glyph_of_zen_flight_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Player* _player = GetTarget()->ToPlayer())
                _player->LearnSpell(SPELL_MONK_ZEN_FLIGHT, false);

        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Player* _player = GetTarget()->ToPlayer())
                if (_player->HasSpell(SPELL_MONK_ZEN_FLIGHT))
                    _player->RemoveSpell(SPELL_MONK_ZEN_FLIGHT, false, false);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_monk_glyph_of_zen_flight_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_monk_glyph_of_zen_flight_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_monk_glyph_of_zen_flight_AuraScript();
    }
};

enum Serpent
{
    MONK_NPC_JADE_SERPENT_STATUE = 60849
};

// Summon Jade Serpent Statue - 115313
class spell_monk_jade_serpent_statue : public SpellScriptLoader
{
    public:
    spell_monk_jade_serpent_statue() : SpellScriptLoader("spell_monk_jade_serpent_statue")
    { }

    class spell_monk_jade_serpent_statue_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_jade_serpent_statue_SpellScript);

            void HandleSummon(SpellEffIndex effIndex)
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                PreventHitDefaultEffect(effIndex);

                const SpellInfo* spell = GetSpellInfo();
                std::list<Creature*> tempList;
                std::list<Creature*> jadeSerpentlist;

                player->GetCreatureListWithEntryInGrid(tempList, MONK_NPC_JADE_SERPENT_STATUE, 500.0f);
                player->GetCreatureListWithEntryInGrid(jadeSerpentlist, MONK_NPC_JADE_SERPENT_STATUE, 500.0f);

                // Remove other players jade statue
                for (std::list<Creature*>::iterator i = tempList.begin(); i != tempList.end(); ++i)
                {
                    Unit* owner = (*i)->GetOwner();
                    if (owner && owner == player && (*i)->IsSummon())
                        continue;

                    jadeSerpentlist.remove((*i));
                }

                // 1 statue max
                if ((int32) jadeSerpentlist.size() >= spell->GetEffect(effIndex)->BasePoints)
                    jadeSerpentlist.back()->ToTempSummon()->UnSummon();

                Position pos;
                GetExplTargetDest()->GetPosition();
                const SummonPropertiesEntry* properties = sSummonPropertiesStore.LookupEntry(spell->GetEffect(effIndex)->MiscValueB);
                TempSummon* summon = player->SummonCreature(spell->GetEffect(effIndex)->MiscValue, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, spell->GetDuration());
                if (!summon)
                    return;

                //summon->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, player->GetGUID());
                summon->setFaction(player->getFaction());
                summon->SetUInt32Value(UNIT_FIELD_CREATEDBY, GetSpellInfo()->Id);
                summon->SetMaxHealth(player->CountPctFromMaxHealth(50));
                summon->SetHealth(summon->GetMaxHealth());
            }
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_monk_jade_serpent_statue_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_jade_serpent_statue_SpellScript();
    }
};

enum Fists
{
    SPELL_MONK_FISTS_OF_FURY_VISUAL = 123154
};

// Fists of Fury (stun effect) - 120086
class spell_monk_fists_of_fury_stun : public SpellScriptLoader
{
    public:
    spell_monk_fists_of_fury_stun() : SpellScriptLoader("spell_monk_fists_of_fury_stun")
    { }

    class spell_monk_fists_of_fury_stun_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_fists_of_fury_stun_SpellScript);

        void RemoveInvalidTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(Trinity::UnitAuraCheck(true, GetSpellInfo()->Id));
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_fists_of_fury_stun_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_24);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_fists_of_fury_stun_SpellScript();
    }

    class spell_monk_fists_of_fury_stun_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_fists_of_fury_stun_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Player* _player = GetTarget()->ToPlayer())
                if (_player->HasAura(SPELL_MONK_FISTS_OF_FURY_VISUAL))
                    _player->RemoveAura(SPELL_MONK_FISTS_OF_FURY_VISUAL);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_monk_fists_of_fury_stun_AuraScript::OnRemove, EFFECT_0, SPELL_EFFECT_APPLY_AURA, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_monk_fists_of_fury_stun_AuraScript();
    }
};

enum ChiWave
{
    SPELL_MONK_CHI_WAVE_HEAL = 132463,
    SPELL_MONK_CHI_WAVE_DAMAGE = 132467,
    SPELL_MONK_CHI_WAVE_HEALING_BOLT = 132464,
    SPELL_MONK_CHI_WAVE_TALENT_AURA = 115098,
};

// Chi Wave (damage) - 132467 and Chi Wave (heal) - 132463
class spell_monk_chi_wave_bolt : public SpellScriptLoader
{
    public:
    spell_monk_chi_wave_bolt() : SpellScriptLoader("spell_monk_chi_wave_bolt")
    { }

    class spell_monk_chi_wave_bolt_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_chi_wave_bolt_SpellScript);

        void HandleOnHit()
        {
            if (!GetOriginalCaster())
                return;

            if (Unit* _player = GetOriginalCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    uint8 count = 0;
                    std::list<Unit*> targetList;
                    std::vector<uint64> validTargets;

                    if (AuraEffect* chiWave = _player->GetAuraEffect(SPELL_MONK_CHI_WAVE_TALENT_AURA, EFFECT_1))
                    {
                        count = chiWave->GetAmount();

                        if (count >= 7)
                        {
                            _player->RemoveAura(SPELL_MONK_CHI_WAVE_TALENT_AURA);
                            return;
                        }

                        count++;
                        chiWave->SetAmount(count);
                    }
                    else
                        return;

                    CellCoord p(Trinity::ComputeCellCoord(target->GetPositionX(), target->GetPositionY()));
                    Cell cell(p);
                    cell.SetNoCreate();

                    Trinity::AnyUnitInObjectRangeCheck u_check(_player, 20.0f);
                    Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(_player, targetList, u_check);

                    TypeContainerVisitor<Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck>, WorldTypeMapContainer> world_unit_searcher(searcher);
                    TypeContainerVisitor<Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck>, GridTypeMapContainer>  grid_unit_searcher(searcher);

                    cell.Visit(p, world_unit_searcher, *_player->GetMap(), *_player, 20.0f);
                    cell.Visit(p, grid_unit_searcher, *_player->GetMap(), *_player, 20.0f);

                    for (auto itr : targetList)
                    {
                        if (!itr->IsWithinLOSInMap(_player))
                            continue;

                        if (itr == target)
                            continue;

                       // validTargets.push_back(itr->GetGUID());
                    }

                    if (validTargets.empty())
                    {
                        _player->RemoveAurasDueToSpell(SPELL_MONK_CHI_WAVE_TALENT_AURA);
                        return;
                    }

                    std::random_shuffle(validTargets.begin(), validTargets.end());

                    //if (Unit* newTarget = sObjectAccessor->FindUnit(validTargets.front()))
                   /*{
                        if (_player->IsValidAttackTarget(newTarget))
                            target->CastSpell(newTarget, SPELL_MONK_CHI_WAVE_DAMAGE, true, NULL, NULL, _player->GetGUID());
                        else
                        {
                            std::list<Unit*> alliesList;

                            for (auto itr : validTargets)
                            {
                                if (_player->IsValidAttackTarget(sObjectAccessor->FindUnit(itr)))
                                    continue;

                                if (!_player->IsValidAssistTarget(sObjectAccessor->FindUnit(itr)))
                                    continue;

                                alliesList.push_back(sObjectAccessor->FindUnit(itr));
                            }

                            if (alliesList.empty())
                                return;

                            alliesList.sort(Trinity::HealthPctOrderPred());

                            target->CastSpell(alliesList.front(), SPELL_MONK_CHI_WAVE_HEALING_BOLT, true, NULL, NULL, _player->GetGUID());
                        }
                    }*/
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_chi_wave_bolt_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_chi_wave_bolt_SpellScript();
    }
};

// Chi Wave (talent) - 115098
class spell_monk_chi_wave : public SpellScriptLoader
{
    public:
    spell_monk_chi_wave() : SpellScriptLoader("spell_monk_chi_wave")
    { }

    class spell_monk_chi_wave_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_chi_wave_SpellScript);

        uint64 targetGUID;
        bool done;

        bool Load()
        {
            targetGUID = 0;
            done = false;
            return true;
        }

        void HandleDummy(SpellEffIndex effIndex)
        {
            if (Unit* target = GetHitUnit())
                targetGUID = target->GetGUID().GetEntry();
        }

        void HandleApplyAura()
        {
            if (!targetGUID || done)
                return;

            if (Player* _player = GetCaster()->ToPlayer())
            {
                /*if (Unit* target = ObjectAccessor::FindPlayer(GUID(targetGUID)))
                {
                    _player->CastSpell(target, _player->IsValidAttackTarget(target) ? SPELL_MONK_CHI_WAVE_DAMAGE : SPELL_MONK_CHI_WAVE_HEALING_BOLT, true);
                    done = true;
                }*/
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_monk_chi_wave_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            AfterHit += SpellHitFn(spell_monk_chi_wave_SpellScript::HandleApplyAura);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_chi_wave_SpellScript();
    }
};

enum Grapple
{
    SPELL_MONK_GRAPPLE_WEAPON_TANK_UPGRADE = 123232,
    SPELL_MONK_GRAPPLE_WEAPON_HEAL_UPGRADE = 123234,
    SPELL_MONK_GRAPPLE_WEAPON_DPS_UPGRADE = 123231
};

// Grapple Weapon - 117368
class spell_monk_grapple_weapon : public SpellScriptLoader
{
    public:
    spell_monk_grapple_weapon() : SpellScriptLoader("spell_monk_grapple_weapon")
    { }

    class spell_monk_grapple_weapon_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_grapple_weapon_SpellScript);

            void HandleBeforeHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                   /* if (target->ToPlayer())
                    {
                        Item* mainItem = _player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                        Item* targetMainItem = target->ToPlayer()->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);

                        if (mainItem && targetMainItem)
                        {
                            if (targetMainItem->GetTemplate()-> > mainItem->GetTemplate()->ItemLevel)
                            {
                                switch (_player->GetSpecializationId(_player->GetActiveSpec()))
                                {
                                    case SPEC_MONK_BREWMASTER:
                                        _player->CastSpell(_player, SPELL_MONK_GRAPPLE_WEAPON_TANK_UPGRADE, true);
                                        break;
                                    case SPEC_MONK_MISTWEAVER:
                                        _player->CastSpell(_player, SPELL_MONK_GRAPPLE_WEAPON_HEAL_UPGRADE, true);
                                        break;
                                    case SPEC_MONK_WINDWALKER:
                                        _player->CastSpell(_player, SPELL_MONK_GRAPPLE_WEAPON_DPS_UPGRADE, true);
                                        break;
                                    default:
                                        break;
                                }
                            }
                        }
                    }
                    else if (target->GetTypeId() == TYPEID_UNIT)
                    {
                        if (target->getLevel() > _player->getLevel())
                        {
                            switch (_player->GetSpecializationId(_player->GetActiveSpec()))
                            {
                                case SPEC_MONK_BREWMASTER:
                                    _player->CastSpell(_player, SPELL_MONK_GRAPPLE_WEAPON_TANK_UPGRADE, true);
                                    break;
                                case SPEC_MONK_MISTWEAVER:
                                    _player->CastSpell(_player, SPELL_MONK_GRAPPLE_WEAPON_HEAL_UPGRADE, true);
                                    break;
                                case SPEC_MONK_WINDWALKER:
                                    _player->CastSpell(_player, SPELL_MONK_GRAPPLE_WEAPON_DPS_UPGRADE, true);
                                    break;
                                default:
                                    break;
                            }
                        }
                    }*/
                }
            }
        }

        void Register()
        {
            BeforeHit += SpellHitFn(spell_monk_grapple_weapon_SpellScript::HandleBeforeHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_grapple_weapon_SpellScript();
    }
};

// Chi Wave (healing bolt) - 132464
class spell_monk_chi_wave_healing_bolt : public SpellScriptLoader
{
    public:
    spell_monk_chi_wave_healing_bolt() : SpellScriptLoader("spell_monk_chi_wave_healing_bolt")
    { }

    class spell_monk_chi_wave_healing_bolt_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_chi_wave_healing_bolt_SpellScript);

        void HandleOnHit()
        {
            if (!GetOriginalCaster())
                return;

            if (Player* _player = GetOriginalCaster()->ToPlayer())
                if (Unit* target = GetHitUnit())
                    _player->CastSpell(target, SPELL_MONK_CHI_WAVE_HEAL, true);
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_chi_wave_healing_bolt_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_chi_wave_healing_bolt_SpellScript();
    }
};

enum SerpentZeal
{
    SPELL_MONK_EMINENCE_HEAL = 126890
};

// Serpent's Zeal - 127722
class spell_monk_serpents_zeal : public SpellScriptLoader
{
    public:
    spell_monk_serpents_zeal() : SpellScriptLoader("spell_monk_serpents_zeal")
    { }

    class spell_monk_serpents_zeal_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_serpents_zeal_AuraScript);

        void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();

            if (!GetCaster())
                return;

            if (eventInfo.GetActor()->GetGUID() != GetTarget()->GetGUID())
                return;

            if (eventInfo.GetDamageInfo()->GetSpellInfo())
                return;

            if (!(eventInfo.GetDamageInfo()->GetDamage()))
                return;

            if (eventInfo.GetDamageInfo()->GetAttackType() != BASE_ATTACK && eventInfo.GetDamageInfo()->GetAttackType() != OFF_ATTACK)
                return;

            int32 bp = eventInfo.GetDamageInfo()->GetDamage();

            if (Player* _player = GetCaster()->ToPlayer())
            {
                std::list<Creature*> tempList;
                std::list<Creature*> statueList;
                Creature* statue = NULL;

                if (Aura* serpentsZeal = _player->GetAura(aurEff->GetSpellInfo()->Id))
                {
                    if (serpentsZeal->GetStackAmount() < 2)
                        bp /= 4;
                    else
                        bp /= 2;
                }

                _player->GetCreatureListWithEntryInGrid(tempList, MONK_NPC_JADE_SERPENT_STATUE, 100.0f);
                _player->GetCreatureListWithEntryInGrid(statueList, MONK_NPC_JADE_SERPENT_STATUE, 100.0f);

                // Remove other players jade statue
                for (std::list<Creature*>::iterator i = tempList.begin(); i != tempList.end(); ++i)
                {
                    Unit* owner = (*i)->GetOwner();
                    if (owner && owner == _player && (*i)->IsSummon())
                        continue;

                    statueList.remove((*i));
                }

                // you gain Serpent's Zeal causing you to heal nearby injured targets equal to 25% of your auto-attack damage. Stacks up to 2 times.
                _player->CastCustomSpell(_player, SPELL_MONK_EMINENCE_HEAL, &bp, NULL, NULL, true);

                if (statueList.size() == 1)
                {
                    for (auto itrBis : statueList)
                        statue = itrBis;

                    if (statue && (statue->IsPet() || statue->IsGuardian()))
                        if (statue->GetOwner() && statue->GetOwner()->GetGUID() == _player->GetGUID())
                            statue->CastCustomSpell(statue, SPELL_MONK_EMINENCE_HEAL, &bp, NULL, NULL, true, 0, NULL, _player->GetGUID()); // Eminence - statue
                }
            }
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_monk_serpents_zeal_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_monk_serpents_zeal_AuraScript();
    }
};

// Dampen Harm - 122278
class spell_monk_dampen_harm : public SpellScriptLoader
{
    public:
    spell_monk_dampen_harm() : SpellScriptLoader("spell_monk_dampen_harm")
    { }

    class spell_monk_dampen_harm_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_dampen_harm_AuraScript);

        uint32 healthPct;

        bool Load()
        {
            healthPct = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue(GetCaster());
            return GetUnitOwner()->ToPlayer();
        }

        void CalculateAmount(AuraEffect const* /*auraEffect*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void Absorb(AuraEffect* auraEffect, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            Unit* target = GetTarget();

            uint32 health = target->CountPctFromMaxHealth(healthPct);

            if (dmgInfo.GetDamage() < health)
                return;

            // The next 3 attacks within 45 sec that deal damage equal to 10% or more of your total health are reduced by half
            absorbAmount = dmgInfo.GetDamage() / 2;
            auraEffect->GetBase()->DropCharge();
        }

        void Register()
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_monk_dampen_harm_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_monk_dampen_harm_AuraScript::Absorb, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_monk_dampen_harm_AuraScript();
    }
};

enum bearHug
{
    SPELL_MONK_BEAR_HUG = 127361
};

// Bear Hug - 127361
class spell_monk_bear_hug : public SpellScriptLoader
{
    public:
    spell_monk_bear_hug() : SpellScriptLoader("spell_monk_bear_hug")
    { }

    class spell_monk_bear_hug_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_bear_hug_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
                if (Unit* target = GetHitUnit())
                    if (Aura* bearHug = target->GetAura(SPELL_MONK_BEAR_HUG, _player->GetGUID()))
                        if (bearHug->GetEffect(EFFECT_1))
                            bearHug->GetEffect(EFFECT_1)->SetAmount(_player->CountPctFromMaxHealth(2));
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_bear_hug_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_bear_hug_SpellScript();
    }
};

// Zen Flight - 125883
class spell_monk_zen_flight_check : public SpellScriptLoader
{
    public:
    spell_monk_zen_flight_check() : SpellScriptLoader("spell_monk_zen_flight_check")
    { }

    class spell_monk_zen_flight_check_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_zen_flight_check_SpellScript);

        SpellCastResult CheckTarget()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (_player->GetMap()->IsBattlegroundOrArena())
                    return SPELL_FAILED_NOT_IN_BATTLEGROUND;

                // In Kalimdor or Eastern Kingdom with Flight Master's License
                if (!_player->HasSpell(90267) && (_player->GetMapId() == 1 || _player->GetMapId() == 0))
                    return SPELL_FAILED_NOT_HERE;

                // In Pandaria with Wisdom of the Four Winds
                if (!_player->HasSpell(115913) && (_player->GetMapId() == 870))
                    return SPELL_FAILED_NOT_HERE;
            }

            return SPELL_CAST_OK;
        }

        void Register()
        {
            OnCheckCast += SpellCheckCastFn(spell_monk_zen_flight_check_SpellScript::CheckTarget);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_zen_flight_check_SpellScript();
    }

    class spell_monk_zen_flight_check_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_zen_flight_check_AuraScript);

        bool Load()
        {
            return GetCaster() && GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
        {
            if (!GetCaster())
                return;

            if (Player* caster = GetCaster()->ToPlayer())
                if (caster->GetSkillValue(SKILL_RIDING) >= 375)
                    amount = 310;
        }

        void Register()
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_monk_zen_flight_check_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_monk_zen_flight_check_AuraScript();
    }
};

enum PowerStrikes
{
    SPELL_MONK_POWER_STRIKES_TALENT = 121817,
    SPELL_MONK_CREATE_CHI_SPHERE = 121286
};

// Called by Jab - 100780
// Power Strikes - 121817
class spell_monk_power_strikes : public SpellScriptLoader
{
    public:
    spell_monk_power_strikes() : SpellScriptLoader("spell_monk_power_strikes")
    { }

    class spell_monk_power_strikes_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_power_strikes_SpellScript);

            void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (target->GetGUID() != _player->GetGUID())
                    {
                        if (_player->HasAura(SPELL_MONK_POWER_STRIKES_TALENT))
                        {
                            /*if (!_player->HasSpellCooldown(SPELL_MONK_POWER_STRIKES_TALENT))
                            {
                                if (_player->GetPower(POWER_CHI) < _player->GetMaxPower(POWER_CHI))
                                {
                                    _player->EnergizeBySpell(_player, GetSpellInfo()->Id, 1, POWER_CHI);
                                    //_player->AddSpellCooldown(SPELL_MONK_POWER_STRIKES_TALENT, 0, time(NULL) + 20);
                                }
                                else
                                    _player->CastSpell(_player, SPELL_MONK_CREATE_CHI_SPHERE, true);
                            }*/
                        }
                    }
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_power_strikes_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_power_strikes_SpellScript();
    }
};

enum SpinningFireBlossom
{
    SPELL_MONK_SPINNING_FIRE_BLOSSOM_ROOT = 123407,
    SPELL_MONK_SPINNING_FIRE_BLOSSOM_DAMAGE = 123408,
    SPELL_MONK_SPINNING_FIRE_BLOSSOM_MISSILE = 118852
};

// Spinning Fire Blossom - 123408
class spell_monk_spinning_fire_blossom_damage : public SpellScriptLoader
{
    public:
    spell_monk_spinning_fire_blossom_damage() : SpellScriptLoader("spell_monk_spinning_fire_blossom_damage")
    { }

    class spell_monk_spinning_fire_blossom_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_spinning_fire_blossom_damage_SpellScript);

        SpellCastResult CheckTarget()
        {
            if (Player* _player = GetCaster()->ToPlayer())
                if (Unit* target = GetExplTargetUnit())
                    if (_player->IsFriendlyTo(target))
                        return SPELL_FAILED_BAD_TARGETS;

            return SPELL_CAST_OK;
        }

        void HandleAfterHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (target->GetDistance(_player) > 10.0f)
                    {
                        SetHitDamage(int32(GetHitDamage() * 1.5f));
                        _player->CastSpell(target, SPELL_MONK_SPINNING_FIRE_BLOSSOM_ROOT, true);
                    }
                }
            }
        }

        void Register()
        {
            OnCheckCast += SpellCheckCastFn(spell_monk_spinning_fire_blossom_damage_SpellScript::CheckTarget);
            AfterHit += SpellHitFn(spell_monk_spinning_fire_blossom_damage_SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_spinning_fire_blossom_damage_SpellScript();
    }
};

// Spinning Fire Blossom - 115073
class spell_monk_spinning_fire_blossom : public SpellScriptLoader
{
    public:
    spell_monk_spinning_fire_blossom() : SpellScriptLoader("spell_monk_spinning_fire_blossom")
    { }

    class spell_monk_spinning_fire_blossom_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_spinning_fire_blossom_SpellScript);

            void HandleAfterCast()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                std::list<Unit*> tempList;
                std::list<Unit*> targetList;

               // _player->GetAttackableUnitListInRange(tempList, 50.0f);

                for (auto itr : tempList)
                {
                    if (!_player->IsValidAttackTarget(itr))
                        continue;

                    if (!_player->isInFront(itr))
                        continue;

                    if (!itr->IsWithinLOSInMap(_player))
                        continue;

                    if (itr->GetGUID() == _player->GetGUID())
                        continue;

                    targetList.push_back(itr);
                }

                if (!targetList.empty())
                {
                    Trinity::Containers::RandomResizeList(targetList, 1);

                    for (auto itr : targetList)
                        _player->CastSpell(itr, SPELL_MONK_SPINNING_FIRE_BLOSSOM_DAMAGE, true);
                }
                else
                    _player->CastSpell(_player, SPELL_MONK_SPINNING_FIRE_BLOSSOM_MISSILE, true);
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_monk_spinning_fire_blossom_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_spinning_fire_blossom_SpellScript();
    }
};

enum ThunderTea
{
    SPELL_MONK_THUNDER_FOCUS_TEA = 116680
};

// Called by Uplift - 116670 and Uplift - 130316
// Thunder Focus Tea - 116680
class spell_monk_thunder_focus_tea : public SpellScriptLoader
{
    public:
    spell_monk_thunder_focus_tea() : SpellScriptLoader("spell_monk_thunder_focus_tea")
    { }

    class spell_monk_thunder_focus_tea_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_thunder_focus_tea_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
        {
            unitList.remove_if(Trinity::UnitAuraCheck(false, SPELL_MONK_RENEWING_MIST_HOT, GetCaster()->GetGUID()));
        }

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (_player->HasAura(SPELL_MONK_THUNDER_FOCUS_TEA))
                    {
                        std::list<Unit*> groupList;

                        _player->GetPartyMembers(groupList);

                        for (auto itr : groupList)
                            if (Aura* renewingMistGroup = itr->GetAura(SPELL_MONK_RENEWING_MIST_HOT, _player->GetGUID()))
                                renewingMistGroup->RefreshDuration();

                        _player->RemoveAura(SPELL_MONK_THUNDER_FOCUS_TEA);
                    }
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_thunder_focus_tea_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_RAID);
            OnHit += SpellHitFn(spell_monk_thunder_focus_tea_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_thunder_focus_tea_SpellScript();
    }
};

enum Teachings
{
    SPELL_MONK_SPINNING_CRANE_KICK_HEAL = 117640
};

// Called by Spinning Crane Kick - 107270
// Teachings of the Monastery - 116645
class spell_monk_teachings_of_the_monastery : public SpellScriptLoader
{
    public:
    spell_monk_teachings_of_the_monastery() : SpellScriptLoader("spell_monk_teachings_of_the_monastery")
    { }

    class spell_monk_teachings_of_the_monastery_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_teachings_of_the_monastery_SpellScript);

        void HandleAfterCast()
        {
            if (GetCaster())
                if (GetCaster()->HasAura(118672))
                    GetCaster()->CastSpell(GetCaster(), SPELL_MONK_SPINNING_CRANE_KICK_HEAL, true);
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_monk_teachings_of_the_monastery_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_teachings_of_the_monastery_SpellScript();
    }
};

// Glyph of Mana Tea - 123763
class spell_monk_glyph_of_mana_tea : public SpellScriptLoader
{
    public:
    spell_monk_glyph_of_mana_tea() : SpellScriptLoader("spell_monk_glyph_of_mana_tea")
    { }

    class spell_monk_glyph_of_mana_tea_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_glyph_of_mana_tea_SpellScript);

        SpellModifier* spellMod;

        void HandleBeforeCast()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                int32 stacks = 0;

                if (Aura* manaTeaStacks = _player->GetAura(SPELL_MONK_MANA_TEA_STACKS))
                    stacks = manaTeaStacks->GetStackAmount();

                int32 newDuration = stacks * IN_MILLISECONDS;

                spellMod = new SpellModifier();
                spellMod->op = SPELLMOD_DURATION;
                spellMod->type = SPELLMOD_FLAT;
                spellMod->spellId = SPELL_MONK_MANA_TEA_STACKS;
                spellMod->value = newDuration;
                spellMod->mask [1] = 0x200000;
                spellMod->mask [2] = 0x1;

                _player->AddSpellMod(spellMod, true);
            }
        }

        void HandleOnHit()
        {
            if (GetCaster())
            {
                if (Aura* manaTea = GetCaster()->GetAura(SPELL_MONK_MANA_TEA_STACKS))
                {
                    if (manaTea->GetStackAmount() > 1)
                        manaTea->SetStackAmount(manaTea->GetStackAmount() - 1);
                    else
                        GetCaster()->RemoveAura(SPELL_MONK_MANA_TEA_STACKS);
                }
            }
        }

        void HandleAfterCast()
        {
            if (Player* _player = GetCaster()->ToPlayer())
                _player->AddSpellMod(spellMod, false);
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_glyph_of_mana_tea_SpellScript::HandleOnHit);
            BeforeCast += SpellCastFn(spell_monk_glyph_of_mana_tea_SpellScript::HandleBeforeCast);
            AfterCast += SpellCastFn(spell_monk_glyph_of_mana_tea_SpellScript::HandleAfterCast);
        }
    };
};

// Mana Tea - 115294
class spell_monk_mana_tea : public SpellScriptLoader
{
    public:
    spell_monk_mana_tea() : SpellScriptLoader("spell_monk_mana_tea")
    { }

    class spell_monk_mana_tea_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_mana_tea_SpellScript);

        SpellModifier* spellMod;

        void HandleBeforeCast()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                int32 stacks = 0;

                if (Aura* manaTeaStacks = _player->GetAura(SPELL_MONK_MANA_TEA_STACKS))
                    stacks = manaTeaStacks->GetStackAmount();

                int32 newDuration = stacks * IN_MILLISECONDS;

                spellMod = new SpellModifier();
                spellMod->op = SPELLMOD_DURATION;
                spellMod->type = SPELLMOD_FLAT;
                spellMod->spellId = SPELL_MONK_MANA_TEA_REGEN;
                spellMod->value = newDuration;
                spellMod->mask [1] = 0x200000;
                spellMod->mask [2] = 0x1;

                _player->AddSpellMod(spellMod, true);
            }
        }

        void HandleAfterCast()
        {
            if (Player* _player = GetCaster()->ToPlayer())
                _player->AddSpellMod(spellMod, false);
        }

        void Register()
        {
            BeforeCast += SpellCastFn(spell_monk_mana_tea_SpellScript::HandleBeforeCast);
            AfterCast += SpellCastFn(spell_monk_mana_tea_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_mana_tea_SpellScript();
    }

    class spell_monk_mana_tea_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_mana_tea_AuraScript);

        void OnTick(AuraEffect const* aurEff)
        {
            if (GetCaster())
            {
                // remove one charge per tick instead of remove aura on cast
                // "Cancelling the channel will not waste stacks"
                if (Aura* manaTea = GetCaster()->GetAura(SPELL_MONK_MANA_TEA_STACKS))
                {
                    if (manaTea->GetStackAmount() > 1)
                        manaTea->SetStackAmount(manaTea->GetStackAmount() - 1);
                    else
                        GetCaster()->RemoveAura(SPELL_MONK_MANA_TEA_STACKS);
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_mana_tea_AuraScript::OnTick, EFFECT_0, SPELL_AURA_OBS_MOD_POWER);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_monk_mana_tea_AuraScript();
    }
};

// Brewing : Mana Tea - 123766
class spell_monk_mana_tea_stacks : public SpellScriptLoader
{
    public:
    spell_monk_mana_tea_stacks() : SpellScriptLoader("spell_monk_mana_tea_stacks")
    { }

    class spell_monk_mana_tea_stacks_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_mana_tea_stacks_AuraScript);

        uint32 chiConsumed;

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            chiConsumed = 0;
        }

        void SetData(uint32 type, uint32 data)
        {
            while ((chiConsumed += data) >= 4)
            {
                chiConsumed = 0;
                data = data > 4 ? data - 4 : 0;

                if (GetCaster())
                {
                    GetCaster()->CastSpell(GetCaster(), SPELL_MONK_MANA_TEA_STACKS, true);
                    GetCaster()->CastSpell(GetCaster(), SPELL_MONK_PLUS_ONE_MANA_TEA, true);
                }
            }
        }

        void Register()
        {
            AfterEffectApply += AuraEffectApplyFn(spell_monk_mana_tea_stacks_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_monk_mana_tea_stacks_AuraScript();
    }
};

// Called by : Fortifying Brew - 115203, Chi Brew - 115399, Elusive Brew - 115308, Tigereye Brew - 116740
// Purifying Brew - 119582, Mana Tea - 115294, Thunder Focus Tea - 116680 and Energizing Brew - 115288
// Healing Elixirs - 122280
class spell_monk_healing_elixirs : public SpellScriptLoader
{
    public:
    spell_monk_healing_elixirs() : SpellScriptLoader("spell_monk_healing_elixirs")
    { }

    class spell_monk_healing_elixirs_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_healing_elixirs_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (_player->HasAura(SPELL_MONK_HEALING_ELIXIRS_AURA))
                {
                    int32 bp = 10;

                    /*if (!_player->HasSpellCooldown(SPELL_MONK_HEALING_ELIXIRS_RESTORE_HEALTH))
                    {
                        _player->CastCustomSpell(_player, SPELL_MONK_HEALING_ELIXIRS_RESTORE_HEALTH, &bp, NULL, NULL, true);
                        // This effect cannot occur more than once per 18s
                        _player->AddSpellCooldown(SPELL_MONK_HEALING_ELIXIRS_RESTORE_HEALTH, 0, time(NULL) + 18);
                    }*/
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_healing_elixirs_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_healing_elixirs_SpellScript();
    }
};

// Zen Sphere - 124081
class spell_monk_zen_sphere : public SpellScriptLoader
{
    public:
    spell_monk_zen_sphere() : SpellScriptLoader("spell_monk_zen_sphere")
    { }

    class spell_monk_zen_sphere_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_zen_sphere_SpellScript);

        bool active;

        void HandleBeforeHit()
        {
            active = false;

            if (Player* _player = GetCaster()->ToPlayer())
                if (Unit* target = GetHitUnit())
                    if (target->HasAura(SPELL_MONK_ZEN_SPHERE_HEAL))
                        active = true;
        }

        void HandleAfterHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (active)
                    {
                        _player->CastSpell(_player, SPELL_MONK_ZEN_SPHERE_DETONATE_HEAL, true);
                        _player->CastSpell(_player, SPELL_MONK_ZEN_SPHERE_DETONATE_DAMAGE, true);
                        _player->RemoveAura(SPELL_MONK_ZEN_SPHERE_HEAL);
                        active = false;
                    }
                }
            }
        }

        void Register()
        {
            BeforeHit += SpellHitFn(spell_monk_zen_sphere_SpellScript::HandleBeforeHit);
            AfterHit += SpellHitFn(spell_monk_zen_sphere_SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_zen_sphere_SpellScript();
    }
};

// Zen Sphere - 124081
class spell_monk_zen_sphere_hot : public SpellScriptLoader
{
    public:
    spell_monk_zen_sphere_hot() : SpellScriptLoader("spell_monk_zen_sphere_hot")
    { }

    class spell_monk_zen_sphere_hot_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_zen_sphere_hot_AuraScript);

        void OnTick(AuraEffect const* aurEff)
        {
            if (Player* _player = GetCaster()->ToPlayer())
                _player->CastSpell(_player, SPELL_MONK_ZEN_SPHERE_DAMAGE, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_zen_sphere_hot_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_monk_zen_sphere_hot_AuraScript();
    }
};

// Chi Burst - 123986
class spell_monk_chi_burst : public SpellScriptLoader
{
    public:
    spell_monk_chi_burst() : SpellScriptLoader("spell_monk_chi_burst")
    { }

    class spell_monk_chi_burst_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_chi_burst_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    std::list<Unit*> tempUnitMap;
                   // _player->GetAttackableUnitListInRange(tempUnitMap, _player->GetDistance(target));

                    // Chi Burst will always heal the Monk, but not heal twice if Monk targets himself
                    if (target->GetGUID() != _player->GetGUID())
                        _player->CastSpell(_player, SPELL_MONK_CHI_BURST_HEAL, true);

                    if (_player->IsValidAttackTarget(target))
                        _player->CastSpell(target, SPELL_MONK_CHI_BURST_DAMAGE, true);
                    else
                        _player->CastSpell(target, SPELL_MONK_CHI_BURST_HEAL, true);

                    for (auto itr : tempUnitMap)
                    {
                        if (itr->GetGUID() == _player->GetGUID())
                            continue;

                        if (!itr->IsInBetween(_player, target, 3.0f))
                            continue;

                        uint32 spell = _player->IsValidAttackTarget(itr) ? SPELL_MONK_CHI_BURST_DAMAGE : SPELL_MONK_CHI_BURST_HEAL;
                        _player->CastSpell(itr, spell, true);
                    }
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_chi_burst_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_chi_burst_SpellScript();
    }
};

// Energizing Brew - 115288
class spell_monk_energizing_brew : public SpellScriptLoader
{
    public:
    spell_monk_energizing_brew() : SpellScriptLoader("spell_monk_energizing_brew")
    { }

    class spell_monk_energizing_brew_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_energizing_brew_SpellScript);

        SpellCastResult CheckFight()
        {
            if (!GetCaster()->IsInCombat())
                return SPELL_FAILED_CASTER_AURASTATE;
            return SPELL_CAST_OK;
        }

        void Register()
        {
            OnCheckCast += SpellCheckCastFn(spell_monk_energizing_brew_SpellScript::CheckFight);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_energizing_brew_SpellScript();
    }
};

// Spear Hand Strike - 116705
class spell_monk_spear_hand_strike : public SpellScriptLoader
{
    public:
    spell_monk_spear_hand_strike() : SpellScriptLoader("spell_monk_spear_hand_strike")
    { }

    class spell_monk_spear_hand_strike_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_spear_hand_strike_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (target->isInFront(_player))
                    {
                        _player->CastSpell(target, SPELL_MONK_SPEAR_HAND_STRIKE_SILENCE, true);
                        //_player->AddSpellCooldown(116705, 0, time(NULL) + 15);
                    }
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_spear_hand_strike_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_spear_hand_strike_SpellScript();
    }
};

// Tiger's Lust - 116841
class spell_monk_tigers_lust : public SpellScriptLoader
{
    public:
    spell_monk_tigers_lust() : SpellScriptLoader("spell_monk_tigers_lust")
    { }

    class spell_monk_tigers_lust_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_tigers_lust_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
                if (Unit* target = GetHitUnit())
                    target->RemoveMovementImpairingAuras();
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_tigers_lust_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_tigers_lust_SpellScript();
    }
};

// Flying Serpent Kick - 115057
class spell_monk_flying_serpent_kick : public SpellScriptLoader
{
    public:
    spell_monk_flying_serpent_kick() : SpellScriptLoader("spell_monk_flying_serpent_kick")
    { }

    class spell_monk_flying_serpent_kick_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_flying_serpent_kick_SpellScript);

        bool Validate(SpellInfo const* /*spell*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_FLYING_SERPENT_KICK_NEW))
                return false;
            return true;
        }

        void HandleOnCast()
        {
            if (Unit* caster = GetCaster())
            {
                if (Player* _player = caster->ToPlayer())
                {
                    if (_player->HasAura(SPELL_MONK_FLYING_SERPENT_KICK))
                        _player->RemoveAura(SPELL_MONK_FLYING_SERPENT_KICK);

                    if (caster->HasAura(SPELL_MONK_ITEM_PVP_GLOVES_BONUS))
                        caster->RemoveAurasByType(SPELL_AURA_MOD_DECREASE_SPEED);

                    _player->CastSpell(_player, SPELL_MONK_FLYING_SERPENT_KICK_AOE, true);
                }
            }
        }

        void Register()
        {
            OnCast += SpellCastFn(spell_monk_flying_serpent_kick_SpellScript::HandleOnCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_flying_serpent_kick_SpellScript();
    }
};

// Chi Torpedo - 115008 or Chi Torpedo (3 charges) - 121828
class spell_monk_chi_torpedo : public SpellScriptLoader
{
    public:
    spell_monk_chi_torpedo() : SpellScriptLoader("spell_monk_chi_torpedo")
    { }

    class spell_monk_chi_torpedo_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_chi_torpedo_SpellScript);

        void HandleAfterCast()
        {
            if (Unit* caster = GetCaster())
            {
                if (Player* _player = caster->ToPlayer())
                {
                    std::list<Unit*> tempUnitMap;
                   // _player->GetAttackableUnitListInRange(tempUnitMap, 20.0f);

                    for (auto itr : tempUnitMap)
                    {
                        if (!itr->isInFront(_player, M_PI / 3) && itr->GetGUID() != _player->GetGUID())
                            continue;

                        uint32 spell = _player->IsValidAttackTarget(itr) ? SPELL_MONK_CHI_TORPEDO_DAMAGE : SPELL_MONK_CHI_TORPEDO_HEAL;
                        _player->CastSpell(itr, spell, true);
                    }

                    if (caster->HasAura(SPELL_MONK_ITEM_PVP_GLOVES_BONUS))
                        caster->RemoveAurasByType(SPELL_AURA_MOD_DECREASE_SPEED);
                }
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_monk_chi_torpedo_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_chi_torpedo_SpellScript();
    }
};

// Purifying Brew - 119582
class spell_monk_purifying_brew : public SpellScriptLoader
{
    public:
    spell_monk_purifying_brew() : SpellScriptLoader("spell_monk_purifying_brew")
    { }

    class spell_monk_purifying_brew_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_purifying_brew_SpellScript);

        void HandleOnHit()
        {
            if (Unit* caster = GetCaster())
            {
                if (Player* _player = caster->ToPlayer())
                {
                    AuraApplication* staggerAmount = _player->GetAuraApplication(SPELL_MONK_LIGHT_STAGGER);

                    if (!staggerAmount)
                        staggerAmount = _player->GetAuraApplication(SPELL_MONK_MODERATE_STAGGER);
                    if (!staggerAmount)
                        staggerAmount = _player->GetAuraApplication(SPELL_MONK_HEAVY_STAGGER);

                    if (staggerAmount)
                        _player->RemoveAura(staggerAmount->GetBase()->GetId());
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_purifying_brew_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_purifying_brew_SpellScript();
    }
};

// Keg Smash - 121253
class spell_monk_keg_smash : public SpellScriptLoader
{
    public:
    spell_monk_keg_smash() : SpellScriptLoader("spell_monk_keg_smash")
    { }

    class spell_monk_keg_smash_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_keg_smash_SpellScript);

        void HandleOnHit()
        {
            if (Unit* caster = GetCaster())
            {
                if (Player* _player = caster->ToPlayer())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        _player->CastSpell(target, SPELL_MONK_KEG_SMASH_VISUAL, true);
                        _player->CastSpell(target, SPELL_MONK_WEAKENED_BLOWS, true);
                        _player->CastSpell(_player, SPELL_MONK_KEG_SMASH_ENERGIZE, true);
                        // Prevent to receive 2 CHI more than once time per cast
                       // _player->AddSpellCooldown(SPELL_MONK_KEG_SMASH_ENERGIZE, 0, time(NULL) + 1);
                        _player->CastSpell(target, SPELL_MONK_DIZZYING_HAZE, true);
                    }
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_keg_smash_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_keg_smash_SpellScript();
    }
};

// Elusive Brew - 115308
class spell_monk_elusive_brew : public SpellScriptLoader
{
    public:
    spell_monk_elusive_brew() : SpellScriptLoader("spell_monk_elusive_brew")
    { }

    class spell_monk_elusive_brew_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_elusive_brew_SpellScript);

        void HandleOnHit()
        {
            int32 stackAmount = 0;

            if (Unit* caster = GetCaster())
            {
                if (Player* _player = caster->ToPlayer())
                {
                    if (AuraApplication* brewStacks = _player->GetAuraApplication(SPELL_MONK_ELUSIVE_BREW_STACKS))
                        stackAmount = brewStacks->GetBase()->GetStackAmount();

                    _player->AddAura(SPELL_MONK_ELUSIVE_BREW, _player);

                    if (AuraApplication* aura = _player->GetAuraApplication(SPELL_MONK_ELUSIVE_BREW))
                    {
                        Aura* elusiveBrew = aura->GetBase();
                        int32 maxDuration = elusiveBrew->GetMaxDuration();
                        int32 newDuration = stackAmount * 1000;
                        elusiveBrew->SetDuration(newDuration);

                        if (newDuration > maxDuration)
                            elusiveBrew->SetMaxDuration(newDuration);

                        _player->RemoveAura(SPELL_MONK_ELUSIVE_BREW_STACKS);
                    }
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_elusive_brew_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_elusive_brew_SpellScript();
    }
};

// Soothing Mist - 115175
class spell_monk_soothing_mist : public SpellScriptLoader
{
    public:
    spell_monk_soothing_mist() : SpellScriptLoader("spell_monk_soothing_mist")
    { }

    class spell_monk_soothing_mist_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_soothing_mist_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (!GetCaster())
                return;

            if (Unit* target = GetTarget())
                target->CastSpell(target, SPELL_MONK_SOOTHING_MIST_VISUAL, true);

            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetTarget())
                {
                    std::list<Unit*> playerList;
                    std::list<Creature*> tempList;
                    std::list<Creature*> statueList;
                    Creature* statue;

                    _player->GetPartyMembers(playerList);

                    if (playerList.size() > 1)
                    {
                        playerList.remove(target);
                        playerList.sort(Trinity::HealthPctOrderPred());
                        playerList.resize(1);
                    }

                    _player->GetCreatureListWithEntryInGrid(tempList, MONK_NPC_JADE_SERPENT_STATUE, 100.0f);
                    _player->GetCreatureListWithEntryInGrid(statueList, MONK_NPC_JADE_SERPENT_STATUE, 100.0f);

                    // Remove other players jade statue
                    for (std::list<Creature*>::iterator i = tempList.begin(); i != tempList.end(); ++i)
                    {
                        Unit* owner = (*i)->GetOwner();
                        if (owner && owner == _player && (*i)->IsSummon())
                            continue;

                        statueList.remove((*i));
                    }

                    for (auto itr : playerList)
                    {
                        if (statueList.size() == 1)
                        {
                            for (auto itrBis : statueList)
                                statue = itrBis;

                            if (statue && (statue->IsPet() || statue->IsGuardian()))
                                if (statue->GetOwner() && statue->GetOwner()->GetGUID() == _player->GetGUID())
                                    statue->CastSpell(itr, GetSpellInfo()->Id, true);
                        }
                    }
                }
            }
        }

        void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetTarget())
                    // 25% to give 1 chi per tick
                    if (roll_chance_i(25))
                        caster->CastSpell(caster, SPELL_MONK_SOOTHING_MIST_ENERGIZE, true);
        }

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetTarget())
                    if (target->HasAura(SPELL_MONK_SOOTHING_MIST_VISUAL))
                        target->RemoveAura(SPELL_MONK_SOOTHING_MIST_VISUAL);
        }

        void Register()
        {
            AfterEffectApply += AuraEffectApplyFn(spell_monk_soothing_mist_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_soothing_mist_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_monk_soothing_mist_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_monk_soothing_mist_AuraScript();
    }
};

enum Blackout
{
    SPELL_MONK_COMBAT_CONDITIONING = 128595,
    SPELL_MONK_BLACKOUT_KICK_DOT = 128531,
    SPELL_MONK_GLYPH_OF_BLACKOUT_KICK = 132005,
    SPELL_MONK_BLACKOUT_KICK_HEAL = 128591,
    SPELL_MONK_SHUFFLE = 115307
};

// Blackout Kick - 100784
class spell_monk_blackout_kick : public SpellScriptLoader
{
    public:
    spell_monk_blackout_kick() : SpellScriptLoader("spell_monk_blackout_kick")
    { }

    class spell_monk_blackout_kick_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_blackout_kick_SpellScript);

        void HandleOnHit()
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    // Second effect by spec : Instant heal or DoT
                    if (/*caster->GetTypeId() == TYPEID_PLAYER && caster->ToPlayer()->GetSpecializationId(caster->ToPlayer()->GetActiveSpec()) == SPEC_MONK_WINDWALKER
                        && */caster->ToPlayer()->HasAura(SPELL_MONK_COMBAT_CONDITIONING))
                    {
                        // Your Blackout Kick always deals 20% additional damage over 4 sec regardless of positioning but you're unable to trigger the healing effect.
                        if (caster->HasAura(SPELL_MONK_GLYPH_OF_BLACKOUT_KICK))
                        {
                            int32 bp = int32(GetHitDamage() * 0.2f) / 4;
                            caster->CastCustomSpell(target, SPELL_MONK_BLACKOUT_KICK_DOT, &bp, NULL, NULL, true);
                        }
                        else
                        {
                            // If behind : 20% damage on DoT
                            if (target->isInBack(caster))
                            {
                                int32 bp = int32(GetHitDamage() * 0.2f) / 4;
                                caster->CastCustomSpell(target, SPELL_MONK_BLACKOUT_KICK_DOT, &bp, NULL, NULL, true);
                            }
                            // else : 20% damage on instant heal
                            else
                            {
                                int32 bp = int32(GetHitDamage() * 0.2f);
                                caster->CastCustomSpell(caster, SPELL_MONK_BLACKOUT_KICK_HEAL, &bp, NULL, NULL, true);
                            }
                        }
                    }
                    // Brewmaster : Training - you gain Shuffle, increasing parry chance and stagger amount by 20%
                   // else if (caster->GetTypeId() == TYPEID_PLAYER && caster->ToPlayer()->GetSpecializationId(caster->ToPlayer()->GetActiveSpec()) == SPEC_MONK_BREWMASTER)
                        caster->CastSpell(caster, SPELL_MONK_SHUFFLE, true);
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_monk_blackout_kick_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_blackout_kick_SpellScript();
    }
};

// Provoke - 115546
class spell_monk_provoke : public SpellScriptLoader
{
    public:
    spell_monk_provoke() : SpellScriptLoader("spell_monk_provoke")
    { }

    class spell_monk_provoke_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_provoke_SpellScript);

        SpellCastResult CheckCast()
        {
            Unit* target = GetExplTargetUnit();
            if (!target)
                return SPELL_FAILED_NO_VALID_TARGETS;
            else if (target->GetTypeId() == TYPEID_PLAYER)
                return SPELL_FAILED_BAD_TARGETS;
            else if (!target->IsWithinLOSInMap(GetCaster()))
                return SPELL_FAILED_LINE_OF_SIGHT;
            return SPELL_CAST_OK;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->getClass() == CLASS_MONK && caster->GetTypeId() == TYPEID_PLAYER)
                    if (Unit* target = GetHitUnit())
                        caster->CastSpell(target, SPELL_MONK_PROVOKE, true);
        }

        void Register()
        {
            OnCheckCast += SpellCheckCastFn(spell_monk_provoke_SpellScript::CheckCast);
            OnEffectHitTarget += SpellEffectFn(spell_monk_provoke_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_provoke_SpellScript();
    }
};

// Brewing : Tigereye Brew - 123980
class spell_monk_tigereye_brew_stacks : public SpellScriptLoader
{
    public:
    spell_monk_tigereye_brew_stacks() : SpellScriptLoader("spell_monk_tigereye_brew_stacks")
    { }

    class spell_monk_tigereye_brew_stacks_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_tigereye_brew_stacks_AuraScript);

        uint32 chiConsumed;

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            chiConsumed = 0;
        }

        void SetData(uint32 type, uint32 data)
        {
            while ((chiConsumed += data) >= 4)
            {
                chiConsumed = 0;
                data = data > 4 ? data - 4 : 0;

                if (GetCaster())
                    GetCaster()->CastSpell(GetCaster(), SPELL_MONK_TIGEREYE_BREW_STACKS, true);
            }
        }

        void Register()
        {
            AfterEffectApply += AuraEffectApplyFn(spell_monk_tigereye_brew_stacks_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_monk_tigereye_brew_stacks_AuraScript();
    }
};

void AddSC_monk_spell_scripts()
{
    new spell_monk_fists_of_fury_stun();
    new spell_monk_expel_harm();
    new spell_monk_chi_wave_healing_bolt();
    new spell_monk_chi_wave_bolt();
    new spell_monk_chi_wave();
    new spell_monk_grapple_weapon();
    new npc_transcendence_spirit();
    new spell_monk_transcendence();
    new spell_monk_transcendence_transfer();
    new spell_monk_serpents_zeal();
    new spell_monk_dampen_harm();
    new spell_monk_diffuse_magic();
    new spell_monk_black_ox_statue();
    new spell_monk_guard();
    new spell_monk_bear_hug();
    new spell_monk_zen_flight_check();
    new spell_monk_glyph_of_zen_flight();
    new spell_monk_power_strikes();
    new spell_monk_crackling_jade_lightning();
    new spell_monk_touch_of_karma();
    new spell_monk_spinning_fire_blossom_damage();
    new spell_monk_spinning_fire_blossom();
    new spell_monk_thunder_focus_tea();
    new spell_monk_jade_serpent_statue();
    new spell_monk_teachings_of_the_monastery();
    new spell_monk_mana_tea();
    new spell_monk_glyph_of_mana_tea();
    new spell_monk_mana_tea_stacks();
    new spell_monk_enveloping_mist();
    new spell_monk_surging_mist();
    new spell_monk_renewing_mist();
    new spell_monk_healing_elixirs();
    new spell_monk_zen_sphere();
    new spell_monk_zen_sphere_hot();
    new spell_monk_chi_burst();
    new spell_monk_energizing_brew();
    new spell_monk_spear_hand_strike();
    new spell_monk_tigereye_brew();
    new spell_monk_tigers_lust();
    new spell_monk_flying_serpent_kick();
    new spell_monk_chi_torpedo();
    new spell_monk_purifying_brew();
    new spell_monk_keg_smash();
    new spell_monk_elusive_brew();
    new spell_monk_breath_of_fire();
    new spell_monk_soothing_mist();
    new spell_monk_disable();
    new spell_monk_zen_pilgrimage();
    new spell_monk_blackout_kick();
    new spell_monk_legacy_of_the_emperor();
    new spell_monk_fortifying_brew();
    new spell_monk_touch_of_death();
    new spell_monk_paralysis();
    new spell_monk_provoke();
    new spell_monk_roll();
    new spell_monk_tigereye_brew_stacks();
    new spell_monk_healing_sphere();
}
