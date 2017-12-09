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
 * Scripts for spells with SPELLFAMILY_MAGE and SPELLFAMILY_GENERIC spells used by mage players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_mage_".
 */

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GridNotifiers.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum MageSpells
{
    SPELL_MAGE_CONE_OF_COLD_AURA_R1              = 11190,
    SPELL_MAGE_CONE_OF_COLD_AURA_R2              = 12489,
    SPELL_MAGE_CONE_OF_COLD_TRIGGER_R1           = 83301,
    SPELL_MAGE_CONE_OF_COLD_TRIGGER_R2           = 83302,
    SPELL_MAGE_RING_OF_FROST_FREEZE              = 82691,
    SPELL_MAGE_RING_OF_FROST_IMMUNE              = 91264,
    SPELL_MAGE_FINGERS_OF_FROST                  = 112965,
    SPELL_MAGE_FINGERS_OF_FROST_AURA             = 44544,
    SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI        = 126084,
    SPELL_MAGE_ICE_LANCE                         = 30455,
    SPELL_MAGE_ICE_LANCE_TRIGGER                 = 228598,
    SPELL_MAGE_HEATING_UP                        = 48107,
    SPELL_MAGE_HOT_STREAK                        = 48108,
    SPELL_MAGE_ENHANCED_PYROTECHNICS_AURA        = 157644,
    SPELL_MAGE_FIRE_MAGE_PASSIVE                 = 137019,
    SPELL_MAGE_FIRE_BLAST                        = 108853,
    SPELL_MAGE_FLURRY                            = 44614,
    SPELL_MAGE_FLURRY_DAMAGE                     = 228672,
    SPELL_MAGE_FLURRY_CHILL_PROC                 = 228358,
    SPELL_MAGE_FLURRY_VISUAL                     = 228671,
    SPELL_MAGE_FIRE_ON                           = 205029,
    SPELL_MAGE_FIREBALL                          = 133,
    SPELL_MAGE_FROSTBOLT                         = 116,
    SPELL_MAGE_FROSTBOLT_TRIGGER                 = 228597,
    SPELL_MAGE_ARCANE_BLAST                      = 30451,
    SPELL_MAGE_FIRESTARTER                       = 205026,
    SPELL_MAGE_INCANTERS_FLOW_BUFF               = 116267,
    SPELL_MAGE_ARCANE_CHARGE                     = 36032,
    SPELL_MAGE_ARCANE_MISSILES                   = 5143,
    SPELL_MAGE_ARCANE_MISSILES_CHARGES           = 79683,
    SPELL_MAGE_ARCANE_MISSILES_PROC              = 79684,
    SPELL_MAGE_ARCANE_MISSILES_POWER             = 208030,
    SPELL_MAGE_ARCANE_MISSILES_TRIGGER           = 7268,
    SPELL_MAGE_ARCANE_MISSILES_VISUAL            = 79808,
    SPELL_MAGE_POLYMORPH_CRITTERMORPH            = 120091,
    SPELL_MAGE_CAUTERIZE                         = 87023,
    SPELL_MAGE_MIRROR_IMAGE_LEFT                 = 58834,
    SPELL_MAGE_MIRROR_IMAGE_RIGHT                = 58833,
    SPELL_MAGE_MIRROR_IMAGE_FRONT                = 58831,
    SPELL_MAGE_CONJURE_REFRESHMENT_GROUP         = 167145,
    SPELL_MAGE_CONJURE_REFRESHMENT_SOLO          = 116136,
    SPELL_MAGE_COMBUSTION                        = 190319,
    SPELL_MAGE_PYROBLAST                         = 11366,
    SPELL_MAGE_METEOR_DAMAGE                     = 153564,
    SPELL_MAGE_METEOR_TIMER                      = 177345,
    SPELL_MAGE_METEOR_VISUAL                     = 174556,
    SPELL_MAGE_METEOR_BURN                       = 155158,
    SPELL_MAGE_LIVING_BOMB_DAMAGE                = 44461,
    SPELL_MAGE_LIVING_BOMB_DOT                   = 217694,
    SPELL_MAGE_CHILLED                           = 205708,
    SPELL_MAGE_BRAIN_FREEZE                      = 190447,
    SPELL_MAGE_BRAIN_FREEZE_AURA                 = 190446,
    SPELL_MAGE_WATER_JET                         = 135029,
    SPELL_MAGE_FROST_BOMB_AURA                   = 112948,
    SPELL_MAGE_FROST_BOMB_TRIGGERED              = 113092,
    SPELL_MAGE_COLD_SNAP                         = 11958,
    SPELL_MAGE_UNSTABLE_MAGIC                    = 157976,
    SPELL_MAGE_UNSTABLE_MAGIC_DAMAGE_FIRE        = 157977,
    SPELL_MAGE_UNSTABLE_MAGIC_DAMAGE_FROST       = 157978,
    SPELL_MAGE_UNSTABLE_MAGIC_DAMAGE_ARCANE      = 157979,
    SPELL_MAGE_THERMAL_VOID                      = 155149,
    SPELL_MAGE_ICY_VEINS                         = 12472,
    SPELL_MAGE_FROZEN_ORB_DAMAGE                 = 84721,
    SPELL_MAGE_ARCANE_ORB_DAMAGE                 = 153640,
    SPELL_MAGE_BONE_CHILLING                     = 205027,
    SPELL_MAGE_BONE_CHILLING_PROC                = 205766,
    SPELL_MAGE_ICE_FLOES                         = 108839,
};

enum TemporalDisplacementSpells
{
    SPELL_MAGE_TEMPORAL_DISPLACEMENT             = 80354,
    SPELL_HUNTER_INSANITY                        = 95809,
    SPELL_PRIEST_SHADOW_WORD_DEATH               = 32409,
    SPELL_SHAMAN_EXHAUSTION                      = 57723,
    SPELL_SHAMAN_SATED                           = 57724,
    SPELL_PET_NETHERWINDS_FATIGUED               = 160455
};

// Living Bomb - 44457
class spell_mage_living_bomb : public SpellScriptLoader
{
public:
    spell_mage_living_bomb() : SpellScriptLoader("spell_mage_living_bomb") {}

    class spell_mage_living_bomb_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_living_bomb_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MAGE_LIVING_BOMB_DAMAGE) ||
                !sSpellMgr->GetSpellInfo(SPELL_MAGE_LIVING_BOMB_DOT))
                return false;
            return true;
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!target || !caster)
                return;

            caster->CastCustomSpell(SPELL_MAGE_LIVING_BOMB_DOT, SPELLVALUE_BASE_POINT1, 1, target, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_living_bomb_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_living_bomb_SpellScript();
    }
};

// Living Bomb Dot - 217694
class spell_mage_living_bomb_dot : public SpellScriptLoader
{
public:
    spell_mage_living_bomb_dot() : SpellScriptLoader("spell_mage_living_bomb_dot") {}

    class spell_mage_living_bomb_dot_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_living_bomb_dot_AuraScript);

        void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            int32 check = GetAura()->GetEffect(EFFECT_1)->GetBaseAmount();
            caster->CastCustomSpell(SPELL_MAGE_LIVING_BOMB_DAMAGE, SPELLVALUE_BASE_POINT0, check, target, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_mage_living_bomb_dot_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_living_bomb_dot_AuraScript();
    }
};

// Living Bomb Damage - 44461
class spell_mage_living_bomb_spread : public SpellScriptLoader
{
public:
    spell_mage_living_bomb_spread() : SpellScriptLoader("spell_mage_living_bomb_spread") {}

    class spell_mage_living_bomb_spread_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_living_bomb_spread_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* hitunit = GetHitUnit();
            Unit* explunit = GetExplTargetUnit();
            if (!caster || !hitunit || !explunit)
                return;

            int32 check = GetSpellValue()->EffectBasePoints[0];
            if (check && hitunit != explunit)
                caster->CastCustomSpell(SPELL_MAGE_LIVING_BOMB_DOT, SPELLVALUE_BASE_POINT1, 0, hitunit, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_living_bomb_spread_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_living_bomb_spread_SpellScript();
    }
};

// Kindling - 155148
class spell_mage_kindling : public SpellScriptLoader
{
public:
    spell_mage_kindling() : SpellScriptLoader("spell_mage_kindling") {}

    class spell_mage_kindling_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_kindling_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            bool spellCanProc = eventInfo.GetSpellInfo()->Id == SPELL_MAGE_FIREBALL ||
                eventInfo.GetSpellInfo()->Id == SPELL_MAGE_FIRE_BLAST ||
                eventInfo.GetSpellInfo()->Id == SPELL_MAGE_PYROBLAST;

            if (spellCanProc && eventInfo.GetHitMask() & PROC_HIT_CRITICAL)
                return true;
            return false;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->GetSpellHistory()->ModifyCooldown(SPELL_MAGE_COMBUSTION, -1 * IN_MILLISECONDS);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_mage_kindling_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_mage_kindling_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_kindling_AuraScript();
    }
};

// Combustion - 190319
class spell_mage_combustion : public SpellScriptLoader
{
public:
    spell_mage_combustion() : SpellScriptLoader("spell_mage_combustion") {}

    class spell_mage_combustion_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_combustion_AuraScript);

        void CalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (!caster->ToPlayer())
                return;

            int32 crit = caster->GetUInt32Value(PLAYER_FIELD_COMBAT_RATING_1 + CR_CRIT_SPELL);
            amount += crit;
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_combustion_AuraScript::CalcAmount, EFFECT_1, SPELL_AURA_MOD_RATING);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_combustion_AuraScript();
    }
};

// Arcane Explosion - 1449
class spell_mage_arcane_explosion : public SpellScriptLoader
{
public:
    spell_mage_arcane_explosion() : SpellScriptLoader("spell_mage_arcane_explosion") {}

    class spell_mage_arcane_explosion_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_arcane_explosion_SpellScript);

        bool _hit;

        bool Load() override
        {
            _hit = false;
            return true;
        }

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            if (!targets.empty())
                _hit = true;
        }

        void Prevent(SpellEffIndex effIndex)
        {
            if (!_hit)
                PreventHitEffect(effIndex);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mage_arcane_explosion_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectLaunch += SpellEffectFn(spell_mage_arcane_explosion_SpellScript::Prevent, EFFECT_1, SPELL_EFFECT_ENERGIZE);
            OnEffectLaunchTarget += SpellEffectFn(spell_mage_arcane_explosion_SpellScript::Prevent, EFFECT_1, SPELL_EFFECT_ENERGIZE);
            OnEffectHit += SpellEffectFn(spell_mage_arcane_explosion_SpellScript::Prevent, EFFECT_1, SPELL_EFFECT_ENERGIZE);
            OnEffectHitTarget += SpellEffectFn(spell_mage_arcane_explosion_SpellScript::Prevent, EFFECT_1, SPELL_EFFECT_ENERGIZE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_arcane_explosion_SpellScript();
    }
};

// Arcane Missiles - 5143
class spell_mage_arcane_missiles : public SpellScriptLoader
{
public:
    spell_mage_arcane_missiles() : SpellScriptLoader("spell_mage_arcane_missiles") {}

    class spell_mage_arcane_missiles_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_arcane_missiles_AuraScript);

        void OnApply(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* l_Caster = GetCaster();
            if (!l_Caster)
                return;

            GetCaster()->CastSpell(GetCaster(), SPELL_MAGE_ARCANE_MISSILES_POWER, true);

            if (Player* _player = GetCaster()->ToPlayer())
                if (Aura* arcaneMissiles = _player->GetAura(SPELL_MAGE_ARCANE_MISSILES_CHARGES))
                    arcaneMissiles->ModStackAmount(-1);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_mage_arcane_missiles_AuraScript::OnApply, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_arcane_missiles_AuraScript();
    }
};

// Arcane Missiles Damage - 7268
class spell_mage_arcane_missiles_damage : public SpellScriptLoader
{
public:
    spell_mage_arcane_missiles_damage() : SpellScriptLoader("spell_mage_arcane_missiles_damage") {}

    class spell_mage_arcane_missiles_damage_SpellScript :public SpellScript
    {
        PrepareSpellScript(spell_mage_arcane_missiles_damage_SpellScript);

        void CheckTarget(WorldObject*& target)
        {
            if (target == GetCaster())
                target = nullptr;
        }

        void Register() override
        {
            OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_mage_arcane_missiles_damage_SpellScript::CheckTarget, EFFECT_0, TARGET_UNIT_CHANNEL_TARGET);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_arcane_missiles_damage_SpellScript();
    }
};

// Arcane Missiles Proc - 79684
class spell_mage_arcane_missiles_proc : public SpellScriptLoader
{
public:
    spell_mage_arcane_missiles_proc() : SpellScriptLoader("spell_mage_arcane_missiles_proc") {}

    class spell_mage_arcane_missiles_proc_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_arcane_missiles_proc_AuraScript);

        bool HandleProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetSpellInfo()->Id == SPELL_MAGE_ARCANE_MISSILES ||
                eventInfo.GetSpellInfo()->Id == SPELL_MAGE_ARCANE_MISSILES_TRIGGER)
                return false;
            return true;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_mage_arcane_missiles_proc_AuraScript::HandleProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_arcane_missiles_proc_AuraScript();
    }
};

// Arcane Missiles charges - 79683
class spell_mage_arcane_missiles_charges : public SpellScriptLoader
{
public:
    spell_mage_arcane_missiles_charges() : SpellScriptLoader("spell_mage_arcane_missiles_charges") {}

    class spell_mage_arcane_missiles_charges_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_arcane_missiles_charges_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_ARCANE_MISSILES_VISUAL, true);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->RemoveAurasDueToSpell(SPELL_MAGE_ARCANE_MISSILES_VISUAL);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_mage_arcane_missiles_charges_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_mage_arcane_missiles_charges_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_arcane_missiles_charges_AuraScript();
    }
};

// Arcane Barrage - 44425
class spell_mage_arcane_barrage : public SpellScriptLoader
{
public:
    spell_mage_arcane_barrage() : SpellScriptLoader("spell_mage_arcane_barrage") {}

    class spell_mage_arcane_barrage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_arcane_barrage_SpellScript);

        void RemoveCharges()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            Player* player = caster->ToPlayer();
            if (!player)
                return;

            if (player->GetPower(POWER_ARCANE_CHARGES))
            {
                player->SetPower(POWER_ARCANE_CHARGES, 0);
                player->SendPowerUpdate(POWER_ARCANE_CHARGES, 0);
            }

            player->RemoveAurasDueToSpell(SPELL_MAGE_ARCANE_CHARGE);
        }

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* target = GetHitUnit();
            Unit* originalTarget = GetExplTargetUnit();
            if (!target || !originalTarget)
                return;

            if (target != originalTarget)
                SetHitDamage(GetHitDamage() / 2.0f);
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_mage_arcane_barrage_SpellScript::RemoveCharges);
            OnEffectHitTarget += SpellEffectFn(spell_mage_arcane_barrage_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_arcane_barrage_SpellScript();
    }
};

// Incanter's Flow - 1463
class spell_mage_incanters_flow : public SpellScriptLoader
{
public:
    spell_mage_incanters_flow() : SpellScriptLoader("spell_mage_incanters_flow") { }

    class spell_mage_incanters_flow_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_incanters_flow_AuraScript);

        bool m_Up = true;
        bool m_Changed = false;

        void OnTick(AuraEffect const* /*auraEff*/)
        {
            if (Unit* caster = GetCaster())
            {
                /// Break the cycle if caster is out of combat
                if (!caster->IsInCombat())
                    return;

                if (caster->HasAura(SPELL_MAGE_INCANTERS_FLOW_BUFF))
                {
                    if (Aura* incantersFlow = caster->GetAura(SPELL_MAGE_INCANTERS_FLOW_BUFF))
                    {
                        m_Changed = false;

                        if (incantersFlow->GetStackAmount() == 5 && m_Up)
                        {
                            m_Up = false;
                            m_Changed = true;
                        }
                        else if (incantersFlow->GetStackAmount() == 1 && !m_Up)
                        {
                            m_Up = true;
                            m_Changed = true;
                        }

                        if (!m_Changed)
                            incantersFlow->ModStackAmount(m_Up ? 1 : -1);
                    }
                }
                else if (caster->IsInCombat())
                {
                    caster->CastSpell(caster, SPELL_MAGE_INCANTERS_FLOW_BUFF, true);
                    m_Up = true;
                    m_Changed = false;
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_mage_incanters_flow_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_incanters_flow_AuraScript();
    }
};

// Fireball - 133
class spell_mage_fireball : public SpellScriptLoader
{
public:
    spell_mage_fireball() : SpellScriptLoader("spell_mage_fireball") { }

    class spell_mage_fireball_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_fireball_SpellScript);

    public:

        spell_mage_fireball_SpellScript()
        {
            _hit = false;
        }

    private:

        SpellModifier* mod;

        bool _hit;

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MAGE_FIREBALL) ||
                !sSpellMgr->GetSpellInfo(SPELL_MAGE_FIRESTARTER))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Player* caster = GetCaster()->ToPlayer();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            if (target->GetHealthPct() >= 85 && caster->HasAura(SPELL_MAGE_FIRESTARTER))
            {
                mod = new SpellModifier(caster->GetAura(SPELL_MAGE_FIRESTARTER));
                mod->op = SPELLMOD_CRITICAL_CHANCE;
                mod->type = SPELLMOD_FLAT;
                mod->spellId = SPELL_MAGE_FIRESTARTER;
                mod->value = 200;
                mod->mask[0] = 0x1;

                caster->AddSpellMod(mod, true);
                _hit = true;
            }
        }

        void RemoveMod()
        {
            Player* caster = GetCaster()->ToPlayer();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            if (_hit)
                caster->AddSpellMod(mod, false);
        }

        void Register() override
        {
            OnEffectLaunchTarget += SpellEffectFn(spell_mage_fireball_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            AfterHit += SpellHitFn(spell_mage_fireball_SpellScript::RemoveMod);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_fireball_SpellScript();
    }
};

// Enhanced Pyrotechnics - 157642
class spell_mage_enhanced_pyrotechnics : public SpellScriptLoader
{
public:
    spell_mage_enhanced_pyrotechnics() : SpellScriptLoader("spell_mage_enhanced_pyrotechnics") {}

    class spell_mage_enhanced_pyrotechnics_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_enhanced_pyrotechnics_AuraScript);

        bool HandleProc(ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();

            if ((eventInfo.GetHitMask() & PROC_HIT_CRITICAL))
            {
                if (caster->HasAura(SPELL_MAGE_ENHANCED_PYROTECHNICS_AURA))
                    caster->RemoveAurasDueToSpell(SPELL_MAGE_ENHANCED_PYROTECHNICS_AURA);
                return false;
            }
            return true;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_mage_enhanced_pyrotechnics_AuraScript::HandleProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_enhanced_pyrotechnics_AuraScript();
    }
};

// Pyroblast Clearcasting Driver - 44448
class spell_mage_pyroblast_clearcasting_driver : public SpellScriptLoader
{
public:
    spell_mage_pyroblast_clearcasting_driver() : SpellScriptLoader("spell_mage_pyroblast_clearcasting_driver") {}

    class spell_mage_pyroblast_clearcasting_driver_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_pyroblast_clearcasting_driver_AuraScript);
        
        bool CheckProc(ProcEventInfo& eventInfo)
        {
            //Only Scorch, Fireball, Fire Blast, Flamestrike, Pyroblast and Phoenix Flames should proc
            uint32 _spellId = eventInfo.GetSpellInfo()->Id;
            std::vector<uint32> spellList = { 2948 , 133, 108853, 2120, 11366, 194466 };
            for (auto id : spellList)
                if (_spellId == id)
                    return true;
            return false;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();

            if (!(eventInfo.GetHitMask() & PROC_HIT_CRITICAL))
            {
                if (caster->HasAura(SPELL_MAGE_HEATING_UP))
                    caster->RemoveAurasDueToSpell(SPELL_MAGE_HEATING_UP);
                return;
            }

            if (!caster->HasAura(SPELL_MAGE_HEATING_UP))
                caster->CastSpell(caster, SPELL_MAGE_HEATING_UP, true);
            else
            {
                caster->RemoveAurasDueToSpell(SPELL_MAGE_HEATING_UP);
                caster->CastSpell(caster, SPELL_MAGE_HOT_STREAK, true);
            }
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_mage_pyroblast_clearcasting_driver_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            DoCheckProc += AuraCheckProcFn(spell_mage_pyroblast_clearcasting_driver_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_pyroblast_clearcasting_driver_AuraScript();
    }
};

// Ice Lance - 30455
class spell_mage_ice_lance : public SpellScriptLoader
{
public:
    spell_mage_ice_lance() : SpellScriptLoader("spell_mage_ice_lance") {}

    class spell_mage_ice_lance_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_ice_lance_SpellScript);

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster && !target)
                return;

            caster->CastSpell(target, SPELL_MAGE_ICE_LANCE_TRIGGER, true);

            // Frost Bomb
            if (target->HasAura(SPELL_MAGE_FROST_BOMB_AURA, caster->GetGUID()) && (target->HasAuraState(AURA_STATE_FROZEN) || caster->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA)))
                caster->CastSpell(target, SPELL_MAGE_FROST_BOMB_TRIGGERED, true);

            // Thermal Void
            if (caster->HasSpell(SPELL_MAGE_THERMAL_VOID) && target->HasAuraState(AURA_STATE_FROZEN))
            {
                if (Aura* icyVeins = caster->GetAura(SPELL_MAGE_ICY_VEINS, caster->GetGUID()))
                {
                    int32 increaseDuration = sSpellMgr->GetSpellInfo(SPELL_MAGE_THERMAL_VOID)->GetEffect(EFFECT_0)->BasePoints * IN_MILLISECONDS;
                    int32 newDuration = (icyVeins->GetDuration() + increaseDuration);
                    icyVeins->SetDuration(newDuration);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_ice_lance_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_ice_lance_SpellScript();
    }
};

// Ice lance (damage) - 228598
class spell_mage_ice_lance_damage : public SpellScriptLoader
{
public:
    spell_mage_ice_lance_damage() : SpellScriptLoader("spell_mage_ice_lance_damage") {}

    class spell_mage_ice_lance_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_ice_lance_damage_SpellScript);

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetHitUnit())
                {
                    if (target->HasAuraState(AURA_STATE_FROZEN))
                        SetHitDamage(GetHitDamage() * 3);

                    if (Aura* brainFreeze = caster->GetAura(SPELL_MAGE_FINGERS_OF_FROST_AURA))
                    {
                        uint8 stack = brainFreeze->GetStackAmount();
                        if (stack == 2)
                            caster->RemoveAurasDueToSpell(SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI);
                        brainFreeze->ModStackAmount(-1);

                        SetHitDamage(GetHitDamage() * 3);
                    }
                }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_ice_lance_damage_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_ice_lance_damage_SpellScript();
    }
};

// Cone of Cold - 120
class spell_mage_cone_of_cold : public SpellScriptLoader
{
    public:
        spell_mage_cone_of_cold() : SpellScriptLoader("spell_mage_cone_of_cold") { }

        class spell_mage_cone_of_cold_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mage_cone_of_cold_SpellScript);

            void HandleConeOfColdScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* unitTarget = GetHitUnit())
                {
                    if (caster->HasAura(SPELL_MAGE_CONE_OF_COLD_AURA_R1)) // Improved Cone of Cold Rank 1
                        unitTarget->CastSpell(unitTarget, SPELL_MAGE_CONE_OF_COLD_TRIGGER_R1, true);
                    else if (caster->HasAura(SPELL_MAGE_CONE_OF_COLD_AURA_R2)) // Improved Cone of Cold Rank 2
                        unitTarget->CastSpell(unitTarget, SPELL_MAGE_CONE_OF_COLD_TRIGGER_R2, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mage_cone_of_cold_SpellScript::HandleConeOfColdScript, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mage_cone_of_cold_SpellScript();
        }
};

// Conjure Refreshment - 190336
class spell_mage_conjure_refreshment : public SpellScriptLoader
{
public:
    spell_mage_conjure_refreshment() : SpellScriptLoader("spell_mage_conjure_refreshment") { }

    class spell_mage_conjure_refreshment_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_conjure_refreshment_SpellScript);

        void HandleOnHit()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                Group* group = player->GetGroup();

                if (group)
                    player->CastSpell(player, SPELL_MAGE_CONJURE_REFRESHMENT_GROUP, true);
                else
                    player->CastSpell(player, SPELL_MAGE_CONJURE_REFRESHMENT_SOLO, true);
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_mage_conjure_refreshment_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_conjure_refreshment_SpellScript();
    }
};

// Frostbolt - 228597
class spell_mage_frostbolt : public SpellScriptLoader
{
   public:
       spell_mage_frostbolt() : SpellScriptLoader("spell_mage_frostbolt") { }

       class spell_mage_frostbolt_SpellScript : public SpellScript
       {
           PrepareSpellScript(spell_mage_frostbolt_SpellScript);

           void HandleDummy(SpellEffIndex /*effIndex*/)
           {
               Unit* caster = GetCaster();
               Unit* target = GetHitUnit();
               if (!caster || !target)
                   return;

               caster->CastSpell(target, SPELL_MAGE_CHILLED, true);

               // Brain Freeze
               float brainFreezeChance = sSpellMgr->GetSpellInfo(SPELL_MAGE_BRAIN_FREEZE)->GetEffect(EFFECT_0)->CalcValue(caster);
               if (roll_chance_i(brainFreezeChance))
                   caster->CastSpell(caster, SPELL_MAGE_BRAIN_FREEZE_AURA, true);

               // Fingers of Frost
               float fingersFrostChance = sSpellMgr->GetSpellInfo(SPELL_MAGE_FINGERS_OF_FROST)->GetEffect(EFFECT_0)->CalcValue(caster);
               if (roll_chance_i(fingersFrostChance))
               {
                   if (caster->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA))
                       caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI, true);
                   caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_AURA, true);
               }

               Unit* pet = caster->GetGuardianPet();
               if (!pet)
                   return;

               // Water Jet
               if (target->HasAura(SPELL_MAGE_WATER_JET, pet->GetGUID()))
               {
                   if (caster->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA))
                       caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI, true);
                   caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_AURA, true);
               }
           }

           void Register() override
           {
               OnEffectHitTarget += SpellEffectFn(spell_mage_frostbolt_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
           }
       };

       SpellScript* GetSpellScript() const override
       {
           return new spell_mage_frostbolt_SpellScript();
       }
};

// Ice Barrier - 11426
class spell_mage_ice_barrier : public SpellScriptLoader
{
public:
    spell_mage_ice_barrier() : SpellScriptLoader("spell_mage_ice_barrier") { }

    class spell_mage_ice_barrier_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_ice_barrier_AuraScript);

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
        {
            canBeRecalculated = false;
            if (Unit* caster = GetCaster())
                amount += int32(10.0f * caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask()));
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_ice_barrier_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_ice_barrier_AuraScript();
    }
};

// Arcane Barrier - 235450
class spell_mage_arcane_barrier : public SpellScriptLoader
{
public:
    spell_mage_arcane_barrier() : SpellScriptLoader("spell_mage_arcane_barrier") { }

    class spell_mage_arcane_barrier_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_arcane_barrier_AuraScript);

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
        {
            canBeRecalculated = false;
            if (Unit* caster = GetCaster())
                amount += int32(7.0f * caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask()));
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_arcane_barrier_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_arcane_barrier_AuraScript();
    }
};

// Polymorph - 118
class spell_mage_polymorph : public SpellScriptLoader
{
public:
    spell_mage_polymorph() : SpellScriptLoader("spell_mage_polymorph") { }

    class spell_mage_polymorph_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_polymorph_SpellScript);

        void HandleTarget(SpellEffIndex)
        {
            if (Unit* l_Caster = GetCaster())
            {
                if (!l_Caster->HasAura(56382))
                    return;

                if (Unit* l_Target = GetHitUnit())
                {
                    if (l_Target->GetCreatureType() == CreatureType::CREATURE_TYPE_CRITTER)
                    {
                        PreventHitAura();

                        l_Caster->CastSpell(l_Target, SPELL_MAGE_POLYMORPH_CRITTERMORPH, true);
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_polymorph_SpellScript::HandleTarget, SpellEffIndex::EFFECT_1, Targets::TARGET_UNIT_TARGET_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_polymorph_SpellScript();
    }
};

// Time Warp - 80353
class spell_mage_time_warp : public SpellScriptLoader
{
    public:
        spell_mage_time_warp() : SpellScriptLoader("spell_mage_time_warp") { }

        class spell_mage_time_warp_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mage_time_warp_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MAGE_TEMPORAL_DISPLACEMENT)
                    || !sSpellMgr->GetSpellInfo(SPELL_HUNTER_INSANITY)
                    || !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_EXHAUSTION)
                    || !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_SATED)
                    || !sSpellMgr->GetSpellInfo(SPELL_PET_NETHERWINDS_FATIGUED))
                    return false;
                return true;
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
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mage_time_warp_SpellScript::RemoveInvalidTargets, EFFECT_ALL, TARGET_UNIT_CASTER_AREA_RAID);
                AfterHit += SpellHitFn(spell_mage_time_warp_SpellScript::ApplyDebuff);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mage_time_warp_SpellScript();
        }
};

// Fire mage (passive) - 137019
class spell_mage_fire_mage_passive : public SpellScriptLoader
{
public:
    spell_mage_fire_mage_passive() : SpellScriptLoader("spell_mage_fire_mage_passive") {}

    class spell_mage_fire_mage_passive_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_fire_mage_passive_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MAGE_FIRE_MAGE_PASSIVE) ||
                !sSpellMgr->GetSpellInfo(SPELL_MAGE_FIRE_BLAST))
                return false;
            return true;
        }

    public:

        spell_mage_fire_mage_passive_AuraScript() {}

    private:

        SpellModifier* mod;

        void HandleApply(AuraEffect const* aurEffect, AuraEffectHandleModes /*mode*/)
        {
            Player* player = GetCaster()->ToPlayer();
            if (!player)
                return;

            mod = new SpellModifier(aurEffect->GetBase());
            mod->op = SPELLMOD_CRITICAL_CHANCE;
            mod->type = SPELLMOD_FLAT;
            mod->spellId = SPELL_MAGE_FIRE_MAGE_PASSIVE;
            mod->value = 200;
            mod->mask[0] = 0x2;

            player->AddSpellMod(mod, true);
        }

        void HandleRemove(AuraEffect const* /*aurEffect*/, AuraEffectHandleModes /*mode*/)
        {
            Player* player = GetCaster()->ToPlayer();
            if (!player)
                return;

            player->AddSpellMod(mod, false);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_mage_fire_mage_passive_AuraScript::HandleApply, EFFECT_4, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_mage_fire_mage_passive_AuraScript::HandleRemove, EFFECT_4, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_fire_mage_passive_AuraScript();
    }
};

class FlurryDamageEvent : public BasicEvent
{
public:

    FlurryDamageEvent(Unit* caster, Unit* target) : _caster(caster), _target(target) { }

    bool Execute(uint64 /*execTime*/, uint32 /*diff*/) override
    {
        _caster->CastSpell(_target, SPELL_MAGE_FLURRY_VISUAL, false);
        return true;
    }

private:
    Unit* _caster;
    Unit* _target;
};

// Flurry - 44614
class spell_mage_flurry : public SpellScriptLoader
{
public:
    spell_mage_flurry() : SpellScriptLoader("spell_mage_flurry") { }

    class spell_mage_flurry_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_flurry_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            caster->m_Events.AddEvent(new FlurryDamageEvent(caster, target), caster->m_Events.CalculateTime(0));
            caster->m_Events.AddEvent(new FlurryDamageEvent(caster, target), caster->m_Events.CalculateTime(250));
            caster->m_Events.AddEvent(new FlurryDamageEvent(caster, target), caster->m_Events.CalculateTime(500));
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_flurry_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_flurry_SpellScript();
    }
};

// Flame On - 205029
class spell_mage_fire_on : public SpellScriptLoader
{
public:
    spell_mage_fire_on() : SpellScriptLoader("spell_mage_fire_on") { }

    class spell_mage_fire_on_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_fire_on_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MAGE_FIRE_ON) ||
                !sSpellMgr->GetSpellInfo(SPELL_MAGE_FIRE_BLAST))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            caster->ToPlayer()->GetSpellHistory()->ResetCharges(sSpellMgr->GetSpellInfo(SPELL_MAGE_FIRE_BLAST)->ChargeCategoryId);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_fire_on_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_fire_on_SpellScript();
    }
};

// Mirror Image - 55342
class spell_mage_mirror_image_summon : public SpellScriptLoader
{
public:
    spell_mage_mirror_image_summon() : SpellScriptLoader("spell_mage_mirror_image_summon") { }

    class spell_mage_mirror_image_summon_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_mirror_image_summon_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                caster->CastSpell(caster, SPELL_MAGE_MIRROR_IMAGE_LEFT, true);
                caster->CastSpell(caster, SPELL_MAGE_MIRROR_IMAGE_FRONT, true);
                caster->CastSpell(caster, SPELL_MAGE_MIRROR_IMAGE_RIGHT, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_mirror_image_summon_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_mirror_image_summon_SpellScript();
    }
};

// Cauterize - 86949
class spell_mage_cauterize : public SpellScriptLoader
{
public:
    spell_mage_cauterize() : SpellScriptLoader("spell_mage_cauterize") { }

    class spell_mage_cauterize_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_cauterize_AuraScript);

        int32 healtPct;

        bool Load() override
        {
            healtPct = GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue(GetCaster());
            return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
        }

        void CalculateAmount(AuraEffect const* /*auraEffect*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void Absorb(AuraEffect* /*auraEffect*/, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            Unit* target = GetTarget();

            if (dmgInfo.GetDamage() < target->GetHealth())
                return;

            if (target->ToPlayer()->GetSpellHistory()->HasCooldown(SPELL_MAGE_CAUTERIZE))
                return;

            int bp1 = target->CountPctFromMaxHealth(healtPct);
            target->CastCustomSpell(target, SPELL_MAGE_CAUTERIZE, NULL, &bp1, NULL, true);
            target->CastSpell(target, GetSpellInfo()->GetEffect(EFFECT_2)->TriggerSpell, true);
            target->GetSpellHistory()->AddCooldown(SPELL_MAGE_CAUTERIZE, 0, std::chrono::minutes(2));

            absorbAmount = dmgInfo.GetDamage();
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_cauterize_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_mage_cauterize_AuraScript::Absorb, EFFECT_0);
        }
    };

    class spell_mage_cauterize_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_cauterize_SpellScript);

        void PreventTrigger(SpellEffIndex effIndex)
        {
            PreventHitEffect(effIndex);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_mage_cauterize_SpellScript::PreventTrigger, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectHitTarget += SpellEffectFn(spell_mage_cauterize_SpellScript::PreventTrigger, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectLaunch += SpellEffectFn(spell_mage_cauterize_SpellScript::PreventTrigger, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectLaunchTarget += SpellEffectFn(spell_mage_cauterize_SpellScript::PreventTrigger, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_cauterize_AuraScript();
    }

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_cauterize_SpellScript();
    }
};


// Ring of Frost - 136511
class spell_mage_ring_of_frost : public SpellScriptLoader
{
public:
    spell_mage_ring_of_frost() : SpellScriptLoader("spell_mage_ring_of_frost") { }

    class spell_mage_ring_of_frost_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_ring_of_frost_AuraScript);

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
            {
                std::list<Creature*> tempList;
                std::list<Creature*> frozenRingList;

                // Get all of the Frozen Ring in Area
                caster->GetCreatureListWithEntryInGrid(frozenRingList, 44199, 200.0f);

                tempList = frozenRingList;

                // Remove other players Frozen Ring
                for (std::list<Creature*>::iterator i = tempList.begin(); i != tempList.end(); ++i)
                {
                    Unit* owner = (*i)->GetOwner();
                    if (owner && owner == caster && (*i)->IsSummon())
                        continue;

                    frozenRingList.remove((*i));
                }

                // Check all the Frozen Ring of player in case of more than one
                for (Creature* frozenRing : frozenRingList)
                {
                    std::list<Creature*> tempListCreature;
                    std::list<Player*> tempListPlayer;

                    // Apply aura on hostile creatures in the grid
                    frozenRing->GetCreatureListInGrid(tempListCreature, -2.0f);
                    for (Creature* creature : tempListCreature)
                        if (!creature->IsWithinDist3d(frozenRing, 1.0f) && !creature->HasAura(SPELL_MAGE_RING_OF_FROST_FREEZE) && !creature->HasAura(SPELL_MAGE_RING_OF_FROST_IMMUNE) && caster->IsValidAttackTarget(creature))
                            caster->CastSpell(creature, SPELL_MAGE_RING_OF_FROST_FREEZE, true);

                    // Apply aura on hostile players in the grid
                    frozenRing->GetPlayerListInGrid(tempListPlayer, -2.0f);
                    for (Player* player : tempListPlayer)
                        if (!player->IsWithinDist3d(frozenRing, 1.0f) && !player->HasAura(SPELL_MAGE_RING_OF_FROST_FREEZE) && !player->HasAura(SPELL_MAGE_RING_OF_FROST_IMMUNE) && caster->IsValidAttackTarget(player))
                            caster->CastSpell(player, SPELL_MAGE_RING_OF_FROST_FREEZE, true);
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_mage_ring_of_frost_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_ring_of_frost_AuraScript();
    }
};

// Ring of Frost (immunity 2.5s) - 91264
// Call by Ring of Frost (Aura) - 82691
class spell_mage_ring_of_frost_immunity : public SpellScriptLoader
{
public:
    spell_mage_ring_of_frost_immunity() : SpellScriptLoader("spell_mage_ring_of_frost_immunity") { }

    class spell_mage_ring_of_frost_immunity_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_ring_of_frost_immunity_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
            if (removeMode == AuraRemoveMode::AURA_REMOVE_BY_DEATH)
                return;

            if (Unit* target = GetTarget())
                target->CastSpell(target, SPELL_MAGE_RING_OF_FROST_IMMUNE, true);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_mage_ring_of_frost_immunity_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_ring_of_frost_immunity_AuraScript();
    }
};

// Meteor - 153561
class spell_mage_meteor : public SpellScriptLoader
{
public:
    spell_mage_meteor() : SpellScriptLoader("spell_mage_meteor") {}

    class spell_mage_meteor_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_meteor_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MAGE_METEOR_DAMAGE))
                return false;
            return true;
        }

        void HandleDummy()
        {
            Unit* caster = GetCaster();
            WorldLocation const* dest = GetExplTargetDest();
            if (!caster || !dest)
                return;

            caster->CastSpell(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), SPELL_MAGE_METEOR_TIMER, true);
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_mage_meteor_SpellScript::HandleDummy);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_meteor_SpellScript();
    }
};

// Meteor Damage - 153564
class spell_mage_meteor_damage : public SpellScriptLoader
{
public:
    spell_mage_meteor_damage() : SpellScriptLoader("spell_mage_meteor_damage") {}

    class spell_mage_meteor_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_meteor_damage_SpellScript);

        int32 _targets;

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* unit = GetHitUnit();
            if (!unit)
                return;

            SetHitDamage(GetHitDamage() / _targets);
        }

        void CountTargets(std::list<WorldObject*>& targets)
        {
            _targets = targets.size();
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_meteor_damage_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mage_meteor_damage_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_meteor_damage_SpellScript();
    }
};

// Blizzard damge - 190357
class spell_mage_blizzard : public SpellScriptLoader
{
public:
    spell_mage_blizzard() : SpellScriptLoader("spell_mage_blizzard") {}

    class spell_mage_blizzard_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_blizzard_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_MAGE_CHILLED, true);

            // Fingers of Frost
            float fingersFrostChance = sSpellMgr->GetSpellInfo(SPELL_MAGE_FINGERS_OF_FROST)->GetEffect(EFFECT_1)->CalcValue(caster);
            if (roll_chance_i(fingersFrostChance))
            {
                if (caster->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA))
                    caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI, true);
                caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_AURA, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_blizzard_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_blizzard_SpellScript();
    }
};

// Frozen Touch - 205030
class spell_mage_frozen_touch : public SpellScriptLoader
{
public:
    spell_mage_frozen_touch() : SpellScriptLoader("spell_mage_frozen_touch") { }

    class spell_mage_frozen_touch_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_frozen_touch_SpellScript);

        void HandleOnCast()
        {
            Player* player = GetCaster()->ToPlayer();

            if (!player)
                return;

            player->CastSpell(player, SPELL_MAGE_FINGERS_OF_FROST_AURA, true);
            player->CastSpell(player, SPELL_MAGE_FINGERS_OF_FROST_AURA, true);
            player->CastSpell(player, SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI, true);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_mage_frozen_touch_SpellScript::HandleOnCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_frozen_touch_SpellScript();
    }
};

// Nova - Talent (Fire / Arcane / Frost)
// Called by Blast Wave 157981 - Supernova 157980 - Ice Nova 157997
class spell_mage_novas_talent : public SpellScriptLoader
{
public:
    spell_mage_novas_talent() : SpellScriptLoader("spell_mage_novas_talent") { }

    class spell_mage_novas_talent_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_novas_talent_SpellScript);

        ObjectGuid PlayerGUID;

        void HandleOnCast()
        {
            if (GetExplTargetUnit() != nullptr)
                PlayerGUID = GetExplTargetUnit()->GetGUID();
        }

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetHitUnit())
                    if (target->GetGUID() == PlayerGUID && !target->IsFriendlyTo(caster))
                    {
                        int32 dmg = (GetHitDamage() + CalculatePct(GetHitDamage(), GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints));

                        dmg = caster->SpellDamageBonusDone(target, GetSpellInfo(), dmg, SPELL_DIRECT_DAMAGE, GetEffectInfo(EFFECT_1));
                        dmg = target->SpellDamageBonusTaken(caster, GetSpellInfo(), dmg, SPELL_DIRECT_DAMAGE, GetEffectInfo(EFFECT_1));

                        SetHitDamage(dmg);
                    }
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_mage_novas_talent_SpellScript::HandleOnCast);
            OnEffectHitTarget += SpellEffectFn(spell_mage_novas_talent_SpellScript::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_novas_talent_SpellScript();
    }
};

// Frost Armor - 7302
class spell_mage_frost_armor : public SpellScriptLoader
{
public:
    spell_mage_frost_armor() : SpellScriptLoader("spell_mage_frost_armor") {}

    class spell_mage_frost_armor_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_frost_armor_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            Unit* target = eventInfo.GetDamageInfo()->GetAttacker();
            if (!caster || !target)
            return false;

            caster->CastSpell(target, SPELL_MAGE_CHILLED, true);
            return true;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_mage_frost_armor_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_frost_armor_AuraScript();
    }
};

// Unstable Magic - 157976
// Called by Arcane Blast - 30451, Fireball - 133, Frostbolt - 116
class spell_mage_unstable_magic : public SpellScriptLoader
{
public:
    spell_mage_unstable_magic() : SpellScriptLoader("spell_mage_unstable_magic") { }

    class spell_mage_unstable_magic_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_unstable_magic_SpellScript);

        void HandleDamage(SpellEffIndex)
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                if (Aura* unstableMagic = player->GetAura(SPELL_MAGE_UNSTABLE_MAGIC))
                {
                    int32 chance = 0;
                    uint32 spec = player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID);
                    switch (spec)
                    {
                        case TALENT_SPEC_MAGE_ARCANE:
                            chance = unstableMagic->GetEffect(EFFECT_0) ? unstableMagic->GetEffect(EFFECT_0)->GetAmount() : 0;
                            break;
                        case TALENT_SPEC_MAGE_FROST:
                            chance = unstableMagic->GetEffect(EFFECT_1) ? unstableMagic->GetEffect(EFFECT_1)->GetAmount() : 0;
                            break;
                        case TALENT_SPEC_MAGE_FIRE:
                            chance = unstableMagic->GetEffect(EFFECT_2) ? unstableMagic->GetEffect(EFFECT_2)->GetAmount() : 0;
                            break;
                        default:
                            break;
                    }

                    if (!roll_chance_i(chance))
                        return;

                    if (Unit* target = GetHitUnit())
                    {
                        int32 pct = unstableMagic->GetEffect(EFFECT_3) ? unstableMagic->GetEffect(EFFECT_3)->GetAmount() : 0;
                        int32 basePoints = CalculatePct(GetHitDamage(), pct);
                        uint32 spellID = GetSpellInfo()->Id;
                        switch (spellID)
                        {
                            case SPELL_MAGE_ARCANE_BLAST:
                                player->CastCustomSpell(target, SPELL_MAGE_UNSTABLE_MAGIC_DAMAGE_ARCANE, &basePoints, nullptr, nullptr, true);
                                break;
                            case SPELL_MAGE_FROSTBOLT_TRIGGER:
                                player->CastCustomSpell(target, SPELL_MAGE_UNSTABLE_MAGIC_DAMAGE_FROST, &basePoints, nullptr, nullptr, true);
                                break;
                            case SPELL_MAGE_FIREBALL:
                                player->CastCustomSpell(target, SPELL_MAGE_UNSTABLE_MAGIC_DAMAGE_FIRE, &basePoints, nullptr, nullptr, true);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_unstable_magic_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_unstable_magic_SpellScript();
    }
};

// Frozen Orb (damage) - 84721
class spell_mage_frozen_orb : public SpellScriptLoader
{
public:
    spell_mage_frozen_orb() : SpellScriptLoader("spell_mage_frozen_orb") {}

    class spell_mage_frozen_orb_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_frozen_orb_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_MAGE_CHILLED, true);

            // Fingers of Frost
            float fingersFrostChance = sSpellMgr->GetSpellInfo(SPELL_MAGE_FINGERS_OF_FROST)->GetEffect(EFFECT_0)->CalcValue(caster);
            if (roll_chance_i(fingersFrostChance))
            {
                if (caster->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA))
                    caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI, true);
                caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_AURA, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_frozen_orb_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_frozen_orb_SpellScript();
    }
};

// Chilled - 205708
class spell_mage_chilled : public SpellScriptLoader
{
public:
    spell_mage_chilled() : SpellScriptLoader("spell_mage_chilled") {}

    class spell_mage_chilled_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_chilled_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->HasSpell(SPELL_MAGE_BONE_CHILLING))
                caster->CastSpell(caster, SPELL_MAGE_BONE_CHILLING_PROC, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_chilled_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_chilled_SpellScript();
    }
};

// Ice Floes - 108839
class spell_mage_ice_floes : public SpellScriptLoader
{
public:
    spell_mage_ice_floes() : SpellScriptLoader("spell_mage_ice_floes") { }

    class spell_mage_ice_floes_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_ice_floes_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return false;

            if (eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->CalcCastTime() && eventInfo.GetSpellInfo()->Id != 2948) // Exclude Scorch
            {
                if (Aura* iceFloes = caster->GetAura(SPELL_MAGE_ICE_FLOES))
                    iceFloes->ModStackAmount(-1);
            }
            return true;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_mage_ice_floes_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_ice_floes_AuraScript();
    }
};

// Freeze (Water Elemental's) - 33395
class spell_mage_pet_freeze : public SpellScriptLoader
{
public:
    spell_mage_pet_freeze() : SpellScriptLoader("spell_mage_pet_freeze") { }

    class spell_mage_pet_freeze_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_pet_freeze_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->GetOwner())
                {
                    if (Player* player = caster->GetOwner()->ToPlayer())
                    {
                        if (player->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA))
                            player->CastSpell(player, SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI, true);
                        player->CastSpell(player, SPELL_MAGE_FINGERS_OF_FROST_AURA, true);
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_mage_pet_freeze_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_ROOT, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_pet_freeze_AuraScript();
    }
};

// Meteor - 177345
// AreaTriggerID - 3467
class at_mage_meteor_timer : public AreaTriggerEntityScript
{
public:
    at_mage_meteor_timer() : AreaTriggerEntityScript("at_mage_meteor_timer") {}

    struct at_mage_meteor_timerAI : AreaTriggerAI
    {
        at_mage_meteor_timerAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnCreate() override
        {
            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            if (TempSummon* tempSumm = caster->SummonCreature(WORLD_TRIGGER, at->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 1 * IN_MILLISECONDS))
            {
                tempSumm->setFaction(caster->getFaction());
                tempSumm->SetGuidValue(UNIT_FIELD_SUMMONEDBY, caster->GetGUID());
                tempSumm->SetPhaseMask(caster->GetPhaseMask(), true);
                caster->CastSpell(tempSumm, SPELL_MAGE_METEOR_VISUAL, true);
            }

        }

        void OnRemove() override
        {
            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            if (TempSummon* tempSumm = caster->SummonCreature(WORLD_TRIGGER, at->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 1 * IN_MILLISECONDS))
            {
                tempSumm->setFaction(caster->getFaction());
                tempSumm->SetGuidValue(UNIT_FIELD_SUMMONEDBY, caster->GetGUID());
                tempSumm->SetPhaseMask(caster->GetPhaseMask(), true);
                caster->CastSpell(tempSumm, SPELL_MAGE_METEOR_DAMAGE, true);
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_mage_meteor_timerAI(areatrigger);
    }
};

// Meteor Burn - 175396
// AreaTriggerID - 1712
class at_mage_meteor_burn : public AreaTriggerEntityScript
{
public:
    at_mage_meteor_burn() : AreaTriggerEntityScript("at_mage_meteor_burn") { }

    struct at_mage_meteor_burnAI : AreaTriggerAI
    {
        at_mage_meteor_burnAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (!caster->ToPlayer())
                return;

            if (caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_MAGE_METEOR_BURN, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (!caster->ToPlayer())
                return;

            if (Aura* meteor = unit->GetAura(SPELL_MAGE_METEOR_BURN, caster->GetGUID()))
                meteor->SetDuration(0);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_mage_meteor_burnAI(areatrigger);
    }
};

// Blizzard - 190356
// AreaTriggerID - 4658
class at_mage_blizzard : public AreaTriggerEntityScript
{
public:
    at_mage_blizzard() : AreaTriggerEntityScript("at_mage_blizzard") { }

    struct at_mage_blizzardAI : AreaTriggerAI
    {
        at_mage_blizzardAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
        {
            timeInterval = 1000;
        }

        int32 timeInterval;

        enum UsingSpells
        {
            SPELL_MAGE_BLIZZARD_DAMAGE = 190357
        };

        void OnUpdate(uint32 diff) override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            if (!caster->ToPlayer())
                return;

            timeInterval += diff;
            if (timeInterval < 1000)
                return;

            if (Creature* tempSumm = caster->SummonCreature(WORLD_TRIGGER, at->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 200))
            {
                tempSumm->setFaction(caster->getFaction());
                tempSumm->SetGuidValue(UNIT_FIELD_SUMMONEDBY, caster->GetGUID());
                tempSumm->SetPhaseMask(caster->GetPhaseMask(), true);
                caster->CastSpell(tempSumm, SPELL_MAGE_BLIZZARD_DAMAGE, true);
            }

            timeInterval -= 1000;
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_mage_blizzardAI(areatrigger);
    }
};

// Rune of Power - 116011
// AreaTriggerID - 304
class at_mage_rune_of_power : public AreaTriggerEntityScript
{
public:
    at_mage_rune_of_power() : AreaTriggerEntityScript("at_mage_rune_of_power") { }

    struct at_mage_rune_of_powerAI : AreaTriggerAI
    {
        at_mage_rune_of_powerAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        enum UsingSpells
        {
            SPELL_MAGE_RUNE_OF_POWER_AURA = 116014
        };

        void OnCreate() override
        {
            at->SetUInt32Value(AREATRIGGER_SPELL_X_SPELL_VISUAL_ID, 25943);
        }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (!caster->ToPlayer())
                return;

            if (caster->IsFriendlyTo(unit) && unit->GetGUID() == caster->GetGUID())
                caster->CastSpell(unit, SPELL_MAGE_RUNE_OF_POWER_AURA, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (!caster->ToPlayer())
                return;

            if (unit->HasAura(SPELL_MAGE_RUNE_OF_POWER_AURA))
                unit->RemoveAurasDueToSpell(SPELL_MAGE_RUNE_OF_POWER_AURA);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_mage_rune_of_powerAI(areatrigger);
    }
};

// Frozen Orb - 84714
// AreaTriggerID - 8661
class at_mage_frozen_orb : public AreaTriggerEntityScript
{
public:
    at_mage_frozen_orb() : AreaTriggerEntityScript("at_mage_frozen_orb")  { }

    struct at_mage_frozen_orbAI : AreaTriggerAI
    {
        at_mage_frozen_orbAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
        {
            // How often should the action be executed
            timeInterval = 500;
        }

        int32 timeInterval;

        void OnCreate() override
        {
            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            if (caster->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA))
                caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI, true);

            caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_AURA, true);
            at->SetUInt32Value(AREATRIGGER_SPELL_X_SPELL_VISUAL_ID, 40291);
        }

        void OnUpdate(uint32 diff) override
        {
            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            if (caster->GetTypeId() != TYPEID_PLAYER)
                return;

            // Check if we can handle actions
            timeInterval += diff;
            if (timeInterval < 500)
                return;

            if (Creature* tempSumm = caster->SummonCreature(WORLD_TRIGGER, at->GetPosition(),TEMPSUMMON_TIMED_DESPAWN, 200))
            {
                tempSumm->setFaction(caster->getFaction());
                tempSumm->SetGuidValue(UNIT_FIELD_SUMMONEDBY, caster->GetGUID());
                tempSumm->SetPhaseMask(caster->GetPhaseMask(), true);
                caster->CastSpell(tempSumm, SPELL_MAGE_FROZEN_ORB_DAMAGE, true);
            }

            timeInterval -= 500;
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_mage_frozen_orbAI(areatrigger);
    }
};

// Arcane Orb - 153626
// AreaTriggerID - 1612
class at_mage_arcane_orb : public AreaTriggerEntityScript
{
public:

    at_mage_arcane_orb() : AreaTriggerEntityScript("at_mage_arcane_orb") { }

    struct at_mage_arcane_orbAI : AreaTriggerAI
    {
        at_mage_arcane_orbAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
        {
            // How often should the action be executed
            timeInterval = 500;
        }

        int32 timeInterval;

        void OnUpdate(uint32 diff) override
        {
            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            if (caster->GetTypeId() != TYPEID_PLAYER)
                return;

            // Check if we can handle actions
            timeInterval += diff;
            if (timeInterval < 500)
                return;

            for (auto guid : at->GetInsideUnits())
            {
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                {
                    if (!caster->IsFriendlyTo(unit))
                    {
                        caster->CastSpell(unit, SPELL_MAGE_ARCANE_ORB_DAMAGE, true);
                    }
                }
            }

            timeInterval -= 500;
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_mage_arcane_orbAI(areatrigger);
    }
};

void AddSC_mage_spell_scripts()
{
    new spell_mage_living_bomb();
    new spell_mage_living_bomb_dot();
    new spell_mage_living_bomb_spread();
    new spell_mage_kindling();
    new spell_mage_combustion();
    new spell_mage_arcane_explosion();
    new spell_mage_arcane_missiles();
    new spell_mage_arcane_missiles_damage();
    new spell_mage_arcane_missiles_proc();
    new spell_mage_arcane_missiles_charges();
    new spell_mage_arcane_barrage();
    new spell_mage_incanters_flow();
    new spell_mage_fireball();
    new spell_mage_enhanced_pyrotechnics();
    new spell_mage_pyroblast_clearcasting_driver();
    new spell_mage_ice_lance();
    new spell_mage_ice_lance_damage();
    new spell_mage_cone_of_cold();
    new spell_mage_conjure_refreshment();
    new spell_mage_frostbolt();
    new spell_mage_ice_barrier();
    new spell_mage_arcane_barrier();
    new spell_mage_polymorph();
    new spell_mage_time_warp();
    new spell_mage_fire_mage_passive();
    new spell_mage_flurry();
    new spell_mage_fire_on();
    new spell_mage_mirror_image_summon();
    new spell_mage_cauterize();
    //new spell_mage_ring_of_frost();
    //new spell_mage_ring_of_frost_immunity();
    new spell_mage_meteor();
    new spell_mage_meteor_damage();
    new spell_mage_blizzard();
    new spell_mage_frozen_touch();
    new spell_mage_novas_talent();
    new spell_mage_frost_armor();
    new spell_mage_unstable_magic();
    new spell_mage_frozen_orb();
    new spell_mage_chilled();
    new spell_mage_ice_floes();

    // Spell Pet scripts
    new spell_mage_pet_freeze();

    // AreaTrigger scripts
    new at_mage_meteor_timer();
    new at_mage_meteor_burn();
    new at_mage_blizzard();
    new at_mage_rune_of_power();
    new at_mage_frozen_orb();
    new at_mage_arcane_orb();
}
