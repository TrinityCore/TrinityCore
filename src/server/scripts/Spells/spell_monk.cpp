/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
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
#include "MapManager.h"
#include "ScriptedCreature.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "Spell.h"
#include "GridNotifiers.h"

enum MonkSpells
{
	SPELL_MONK_ENERGIZING_BREW					= 115288,
	SPELL_MONK_CHI_TORPEDO						= 115008,
	SPELL_MONK_ELEVATION						= 116670,
	SPELL_MONK_TOUCH_DEATH						= 115080,
    SPELL_MONK_LEGACY_OF_THE_EMPEROR			= 117666,
    SPELL_MONK_LEGACY_OF_THE_WHITE_TIGER		= 116781,
    SPELL_MONK_TOUCH_OF_DEATH					= 115080,
    SPELL_MONK_FORTIFYING_BREW                  = 120954,
    SPELL_MONK_PROVOKE                          = 118635,
    SPELL_MONK_BLACKOUT_KICK_DOT                = 128531,
    SPELL_MONK_BLACKOUT_KICK_HEAL               = 128591,
    SPELL_MONK_SHUFFLE                          = 115307,
    SPELL_MONK_ZEN_PILGRIMAGE                   = 126892,
    SPELL_MONK_ZEN_PILGRIMAGE_RETURN            = 126895,
    SPELL_MONK_DISABLE_ROOT                     = 116706,
    SPELL_MONK_DISABLE                          = 116095,
    SPELL_MONK_SOOTHING_MIST_VISUAL             = 125955,
    SPELL_MONK_SOOTHING_MIST_ENERGIZE           = 116335,
    SPELL_MONK_BREATH_OF_FIRE_DOT               = 123725,
    SPELL_MONK_BREATH_OF_FIRE_CONFUSED          = 123393,
    SPELL_MONK_ELUSIVE_BREW_STACKS              = 128939,
    SPELL_MONK_ELUSIVE_BREW                     = 115308,
    SPELL_MONK_KEG_SMASH_VISUAL                 = 123662,
    SPELL_MONK_KEG_SMASH_ENERGIZE               = 127796,
    SPELL_MONK_WEAKENED_BLOWS                   = 115798,
    SPELL_MONK_DIZZYING_HAZE                    = 116330,
    SPELL_MONK_CLASH_CHARGE                     = 126452,
    SPELL_MONK_LIGHT_STAGGER                    = 124275,
    SPELL_MONK_MODERATE_STAGGER                 = 124274,
    SPELL_MONK_HEAVY_STAGGER                    = 124273,
    SPELL_MONK_ROLL                             = 109132,
    SPELL_MONK_ROLL_TRIGGER                     = 107427,
    SPELL_MONK_CHI_TORPEDO_HEAL                 = 124040,
    SPELL_MONK_CHI_TORPEDO_DAMAGE               = 117993,
    SPELL_MONK_FLYING_SERPENT_KICK              = 101545,
    SPELL_MONK_FLYING_SERPENT_KICK_NEW          = 115057,
    SPELL_MONK_FLYING_SERPENT_KICK_AOE          = 123586,
    SPELL_MONK_TIGEREYE_BREW                    = 116740,
    SPELL_MONK_TIGEREYE_BREW_STACKS             = 125195,
    SPELL_MONK_SPEAR_HAND_STRIKE_SILENCE        = 116709,
    SPELL_MONK_CHI_BURST_DAMAGE                 = 130651,
    SPELL_MONK_CHI_BURST_HEAL                   = 130654,
    SPELL_MONK_ZEN_SPHERE_DAMAGE                = 124098,
    SPELL_MONK_ZEN_SPHERE_HEAL                  = 124081,
    SPELL_MONK_ZEN_SPHERE_DETONATE_HEAL         = 124101,
    SPELL_MONK_ZEN_SPHERE_DETONATE_DAMAGE       = 125033,
    SPELL_MONK_HEALING_ELIXIRS_AURA             = 122280,
    SPELL_MONK_HEALING_ELIXIRS_RESTORE_HEALTH   = 122281,
    SPELL_MONK_RENEWING_MIST_HOT                = 119611,
    SPELL_MONK_RENEWING_MIST_JUMP_AURA          = 119607,
    SPELL_MONK_GLYPH_OF_RENEWING_MIST           = 123334,
    SPELL_MONK_SURGING_MIST_HEAL                = 116995,
    SPELL_MONK_ENVELOPING_MIST_HEAL             = 132120,
    SPELL_MONK_PLUS_ONE_MANA_TEA                = 123760,
    SPELL_MONK_MANA_TEA_STACKS                  = 115867,
    SPELL_MONK_MANA_TEA_REGEN                   = 115294,
    SPELL_MONK_SPINNING_CRANE_KICK_HEAL         = 117640,
    MONK_NPC_JADE_SERPENT_STATUE                = 60849,
    SPELL_MONK_UPLIFT_ALLOWING_CAST             = 123757,
    SPELL_MONK_THUNDER_FOCUS_TEA                = 116680,
    SPELL_MONK_PATH_OF_BLOSSOM_AREATRIGGER      = 122035,
    SPELL_MONK_SPINNING_FIRE_BLOSSOM_DAMAGE     = 123408,
    SPELL_MONK_SPINNING_FIRE_BLOSSOM_MISSILE    = 118852,
    SPELL_MONK_SPINNING_FIRE_BLOSSOM_ROOT       = 123407,
    SPELL_MONK_TOUCH_OF_KARMA_REDIRECT_DAMAGE   = 124280,
    SPELL_MONK_JADE_LIGHTNING_ENERGIZE          = 123333,
    SPELL_MONK_CRACKLING_JADE_SHOCK_BUMP        = 117962,
    SPELL_MONK_POWER_STRIKES_TALENT             = 121817,
    SPELL_MONK_CREATE_CHI_SPHERE                = 121286,
    SPELL_MONK_GLYPH_OF_ZEN_FLIGHT              = 125893,
    SPELL_MONK_ZEN_FLIGHT                       = 125883,
    SPELL_MONK_BEAR_HUG                         = 127361,
    ITEM_MONK_T14_TANK_4P                       = 123159,
    MONK_NPC_BLACK_OX_STATUE                    = 61146,
    SPELL_MONK_GUARD                            = 115295,
    SPELL_MONK_ITEM_2_S12_MISTWEAVER            = 131561,
    SPELL_MONK_ITEM_4_S12_MISTWEAVER            = 124487,
    SPELL_MONK_ZEN_FOCUS                        = 124488,
    SPELL_MONK_EMINENCE_HEAL                    = 126890,
    SPELL_MONK_GRAPPLE_WEAPON_DPS_UPGRADE       = 123231,
    SPELL_MONK_GRAPPLE_WEAPON_TANK_UPGRADE      = 123232,
    SPELL_MONK_GRAPPLE_WEAPON_HEAL_UPGRADE      = 123234,
    SPELL_MONK_GLYPH_OF_BLACKOUT_KICK           = 132005,
    SPELL_MONK_CHI_WAVE_HEAL                    = 132463,
    SPELL_MONK_CHI_WAVE_DAMAGE                  = 132467,
    SPELL_MONK_CHI_WAVE_HEALING_BOLT            = 132464,
    SPELL_MONK_CHI_WAVE_TALENT_AURA             = 115098,
    SPELL_MONK_ITEM_PVP_GLOVES_BONUS            = 124489,
};

enum Monkspec
{
    SPEC_MONK_BREWMASTER						= 268,
    SPEC_MONK_MISTWEAVER						= 270,
    SPEC_MONK_WINDWALKER						= 269,
};

// Fists of Fury (stun effect) - 120086
class spell_monk_fists_of_fury_stun : public SpellScriptLoader
{
    public:
        spell_monk_fists_of_fury_stun() : SpellScriptLoader("spell_monk_fists_of_fury_stun") { }

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
};

// Expel Harm - 115072
class spell_monk_expel_harm : public SpellScriptLoader
{
    public:
        spell_monk_expel_harm() : SpellScriptLoader("spell_monk_expel_harm") { }

        class spell_monk_expel_harm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_expel_harm_SpellScript);

            void HandleOnHit()
            {
                if (!GetCaster())
                    return;

                if (Player* _player = GetCaster()->ToPlayer())
                {
                    std::list<Unit*> targetList;
                    float radius = 10.0f;

                    Trinity::NearestAttackableUnitInObjectRangeCheck u_check(_player, _player, radius);
                    Trinity::UnitListSearcher<Trinity::NearestAttackableUnitInObjectRangeCheck> searcher(_player, targetList, u_check);
                    _player->VisitNearbyObject(radius, searcher);

					for (std::list<Unit*>::const_iterator i = targetList.begin(); i != targetList.end(); ++i)
                    {
                        if (_player->IsValidAttackTarget((*i)))
                        {
                            int32 bp = CalculatePct((-GetHitDamage()), 50);
                            _player->CastCustomSpell((*i), 115129, &bp, NULL, NULL, true);
                        }
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_expel_harm_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_expel_harm_SpellScript();
        }
};

// Chi Wave (healing bolt) - 132464
class spell_monk_chi_wave_healing_bolt : public SpellScriptLoader
{
    public:
        spell_monk_chi_wave_healing_bolt() : SpellScriptLoader("spell_monk_chi_wave_healing_bolt") { }

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

// Guard - 115295
class spell_monk_guard : public SpellScriptLoader
{
    public:
        spell_monk_guard() : SpellScriptLoader("spell_monk_guard") { }

        class spell_monk_guard_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_guard_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                if (!GetCaster())
                    return;

                if (Player* _plr = GetCaster()->ToPlayer())
                {
                    amount += int32(_plr->GetTotalAttackPowerValue(BASE_ATTACK) * 1.971f);

                    if (_plr->HasAura(ITEM_MONK_T14_TANK_4P))
                        amount = int32(amount * 1.2f);
                }
                // For Black Ox Statue
                else if (GetCaster()->GetOwner())
                {
                    if (Player* _plr = GetCaster()->GetOwner()->ToPlayer())
                    {
                        amount += int32(_plr->GetTotalAttackPowerValue(BASE_ATTACK) * 1.971f);

                        if (_plr->HasAura(ITEM_MONK_T14_TANK_4P))
                            amount = int32(amount * 1.2f);
                    }
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

// Bear Hug - 127361
class spell_monk_bear_hug : public SpellScriptLoader
{
    public:
        spell_monk_bear_hug() : SpellScriptLoader("spell_monk_bear_hug") { }

        class spell_monk_bear_hug_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_bear_hug_SpellScript);

            void HandleOnHit()
            {
                if (Player* _player = GetCaster()->ToPlayer())
                    if (Unit* target = GetHitUnit())
                        if (Aura* bearHug = target->GetAura(SPELL_MONK_BEAR_HUG, _player->GetGUID()))
                            if (bearHug->GetEffect(1))
                                bearHug->GetEffect(1)->SetAmount(_player->CountPctFromMaxHealth(2));
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
        spell_monk_zen_flight_check() : SpellScriptLoader("spell_monk_zen_flight_check") { }

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


// Crackling Jade Lightning - 117952
class spell_monk_crackling_jade_lightning : public SpellScriptLoader
{
    public:
        spell_monk_crackling_jade_lightning() : SpellScriptLoader("spell_monk_crackling_jade_lightning") { }

        class spell_monk_crackling_jade_lightning_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_crackling_jade_lightning_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (Unit* caster = GetCaster())
                    if (roll_chance_i(25))
                        caster->CastSpell(caster, SPELL_MONK_JADE_LIGHTNING_ENERGIZE, true);
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (!GetCaster())
                    return;

                if (eventInfo.GetActor()->GetGUID() != GetTarget()->GetGUID())
                    return;

                if (Player* _player = GetCaster()->ToPlayer())
                {
                    if (GetTarget()->HasAura(aurEff->GetSpellInfo()->Id, _player->GetGUID()))
                    {
                        if (!_player->HasSpellCooldown(SPELL_MONK_CRACKLING_JADE_SHOCK_BUMP))
                        {
                            _player->CastSpell(GetTarget(), SPELL_MONK_CRACKLING_JADE_SHOCK_BUMP, true);
                            _player->AddSpellCooldown(SPELL_MONK_CRACKLING_JADE_SHOCK_BUMP, 0, time(NULL) + 8);
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_crackling_jade_lightning_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                OnEffectProc += AuraEffectProcFn(spell_monk_crackling_jade_lightning_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_crackling_jade_lightning_AuraScript();
        }
};

// Touch of Karma - 122470
class spell_monk_touch_of_karma : public SpellScriptLoader
{
    public:
        spell_monk_touch_of_karma() : SpellScriptLoader("spell_monk_touch_of_karma") { }

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

            void OnAbsorb(AuraEffect* aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount)
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

// Spinning Fire Blossom - 123408
class spell_monk_spinning_fire_blossom_damage : public SpellScriptLoader
{
    public:
        spell_monk_spinning_fire_blossom_damage() : SpellScriptLoader("spell_monk_spinning_fire_blossom_damage") { }

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

// Path of Blossom - 124336
class spell_monk_path_of_blossom : public SpellScriptLoader
{
    public:
        spell_monk_path_of_blossom() : SpellScriptLoader("spell_monk_path_of_blossom") { }

        class spell_monk_path_of_blossom_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_path_of_blossom_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (GetCaster())
                    GetCaster()->CastSpell(GetCaster(), SPELL_MONK_PATH_OF_BLOSSOM_AREATRIGGER, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_path_of_blossom_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_path_of_blossom_AuraScript();
        }
};

// Called by Spinning Crane Kick - 107270
// Teachings of the Monastery - 116645
class spell_monk_teachings_of_the_monastery : public SpellScriptLoader
{
    public:
        spell_monk_teachings_of_the_monastery() : SpellScriptLoader("spell_monk_teachings_of_the_monastery") { }

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

// Mana Tea - 115294
class spell_monk_mana_tea : public SpellScriptLoader
{
    public:
        spell_monk_mana_tea() : SpellScriptLoader("spell_monk_mana_tea") { }

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
                    spellMod->mask[1] = 0x200000;
                    spellMod->mask[2] = 0x1;

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
        spell_monk_mana_tea_stacks() : SpellScriptLoader("spell_monk_mana_tea_stacks") { }

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
                    data = data > 4 ? data - 4: 0;

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

// Enveloping Mist - 124682
class spell_monk_enveloping_mist : public SpellScriptLoader
{
    public:
        spell_monk_enveloping_mist() : SpellScriptLoader("spell_monk_enveloping_mist") { }

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

// Surging Mist - 116694
class spell_monk_surging_mist : public SpellScriptLoader
{
    public:
        spell_monk_surging_mist() : SpellScriptLoader("spell_monk_surging_mist") { }

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

// Called by : Fortifying Brew - 115203, Chi Brew - 115399, Elusive Brew - 115308, Tigereye Brew - 116740
// Purifying Brew - 119582, Mana Tea - 115294, Thunder Focus Tea - 116680 and Energizing Brew - 115288
// Healing Elixirs - 122280
class spell_monk_healing_elixirs : public SpellScriptLoader
{
    public:
        spell_monk_healing_elixirs() : SpellScriptLoader("spell_monk_healing_elixirs") { }

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

                        if (!_player->HasSpellCooldown(SPELL_MONK_HEALING_ELIXIRS_RESTORE_HEALTH))
                        {
                            _player->CastCustomSpell(_player, SPELL_MONK_HEALING_ELIXIRS_RESTORE_HEALTH, &bp, NULL, NULL, true);
                            // This effect cannot occur more than once per 18s
                            _player->AddSpellCooldown(SPELL_MONK_HEALING_ELIXIRS_RESTORE_HEALTH, 0, time(NULL) + 18);
                        }
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
        spell_monk_zen_sphere() : SpellScriptLoader("spell_monk_zen_sphere") { }

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
        spell_monk_zen_sphere_hot() : SpellScriptLoader("spell_monk_zen_sphere_hot") { }

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

// Spear Hand Strike - 116705
class spell_monk_spear_hand_strike : public SpellScriptLoader
{
    public:
        spell_monk_spear_hand_strike() : SpellScriptLoader("spell_monk_spear_hand_strike") { }

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
                            _player->AddSpellCooldown(116705, 0, time(NULL) + 15);
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

// Tigereye Brew - 116740
class spell_monk_tigereye_brew : public SpellScriptLoader
{
    public:
        spell_monk_tigereye_brew() : SpellScriptLoader("spell_monk_tigereye_brew") { }

        class spell_monk_tigereye_brew_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_tigereye_brew_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_TIGEREYE_BREW))
                    return false;
                return true;
            }

            void HandleOnHit()
            {
                if (Player* _player = GetCaster()->ToPlayer())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        if (AuraApplication* aura = _player->GetAuraApplication(SPELL_MONK_TIGEREYE_BREW_STACKS, _player->GetGUID()))
                        {
                            int32 stackAmount = aura->GetBase()->GetStackAmount() * 2;

                            AuraApplication* tigereyeBrew = _player->GetAuraApplication(SPELL_MONK_TIGEREYE_BREW, _player->GetGUID());
                            if (tigereyeBrew)
                                tigereyeBrew->GetBase()->GetEffect(0)->ChangeAmount(stackAmount);

                            _player->RemoveAura(SPELL_MONK_TIGEREYE_BREW_STACKS);
                        }
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_tigereye_brew_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_tigereye_brew_SpellScript();
        }
};

// Tiger's Lust - 116841
class spell_monk_tigers_lust : public SpellScriptLoader
{
    public:
        spell_monk_tigers_lust() : SpellScriptLoader("spell_monk_tigers_lust") { }

        class spell_monk_tigers_lust_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_tigers_lust_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_FLYING_SERPENT_KICK_NEW))
                    return false;
                return true;
            }

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
        spell_monk_flying_serpent_kick() : SpellScriptLoader("spell_monk_flying_serpent_kick") { }

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

// Purifying Brew - 119582
class spell_monk_purifying_brew : public SpellScriptLoader
{
    public:
        spell_monk_purifying_brew() : SpellScriptLoader("spell_monk_purifying_brew") { }

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

// Clash - 122057 and Clash - 126449
class spell_monk_clash : public SpellScriptLoader
{
    public:
        spell_monk_clash() : SpellScriptLoader("spell_monk_clash") { }

        class spell_monk_clash_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_clash_SpellScript);

            void HandleOnHit()
            {
                if (Unit* caster = GetCaster())
                {
                    if (Player* _player = caster->ToPlayer())
                    {
                        if (Unit* target = GetHitUnit())
                        {
                            int32 basePoint = 2;
                            _player->CastCustomSpell(target, SPELL_MONK_CLASH_CHARGE, &basePoint, NULL, NULL, true);
                            target->CastSpell(_player, SPELL_MONK_CLASH_CHARGE, true);
                        }
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_clash_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_clash_SpellScript();
        }
};

// Keg Smash - 121253
class spell_monk_keg_smash : public SpellScriptLoader
{
    public:
        spell_monk_keg_smash() : SpellScriptLoader("spell_monk_keg_smash") { }

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
                            _player->AddSpellCooldown(SPELL_MONK_KEG_SMASH_ENERGIZE, 0, time(NULL) + 1);
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


// Breath of Fire - 115181
class spell_monk_breath_of_fire : public SpellScriptLoader
{
    public:
        spell_monk_breath_of_fire() : SpellScriptLoader("spell_monk_breath_of_fire") { }

        class spell_monk_breath_of_fire_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_breath_of_fire_SpellScript);

            void HandleAfterHit()
            {
                if (Unit* caster = GetCaster())
                {
                    if (Player* _player = caster->ToPlayer())
                    {
                        if (Unit* target = GetHitUnit())
                        {
                            // if Dizzying Haze is on the target, they will burn for an additionnal damage over 8s
                            if (target->HasAura(SPELL_MONK_DIZZYING_HAZE))
                            {
                                _player->CastSpell(target, SPELL_MONK_BREATH_OF_FIRE_DOT, true);

                                // Glyph of Breath of Fire
                                if (_player->HasAura(123394))
                                    _player->CastSpell(target, SPELL_MONK_BREATH_OF_FIRE_CONFUSED, true);
                            }
                        }
                    }
                }
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_monk_breath_of_fire_SpellScript::HandleAfterHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_breath_of_fire_SpellScript();
        }
};


// Provoke - 115546
class spell_monk_provoke : public SpellScriptLoader
{
    public:
        spell_monk_provoke() : SpellScriptLoader("spell_monk_provoke") { }

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

// Paralysis - 115078
class spell_monk_paralysis : public SpellScriptLoader
{
    public:
        spell_monk_paralysis() : SpellScriptLoader("spell_monk_paralysis") { }

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
                            if (AuraApplication* aura = target->GetAuraApplication(115078))
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
                            if (AuraApplication* aura = target->GetAuraApplication(115078))
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

// Touch of death : 115080
class spell_monk_touch_of_death : public SpellScriptLoader
{
    public:
        spell_monk_touch_of_death() : SpellScriptLoader("spell_monk_touch_of_death") { }

        class spell_monk_touch_of_death_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_touch_of_death_SpellScript);

            bool Validate(SpellInfo const* /*spellEntry*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_TOUCH_OF_DEATH))
                    return false;
                return true;
            }

			SpellCastResult CheckCast()
            {
				if (GetHitUnit()->GetTypeId() == TYPEID_PLAYER)
				{
					if (GetHitUnit()->GetHealth() > GetHitUnit()->GetMaxHealth()*0.10f)
						return SPELL_FAILED_ERROR;
				}

				if (GetHitUnit()->GetTypeId() != TYPEID_PLAYER && GetCaster()->GetHealth() < GetHitUnit()->GetHealth())
					return SPELL_FAILED_ERROR;

				if (GetCaster() == GetHitUnit())
					return SPELL_FAILED_NO_VALID_TARGETS;

				return SPELL_CAST_OK;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
				Unit* caster = GetCaster();
				Unit* target = GetHitUnit();
				uint32 damage = 0;

				if (caster->GetTypeId() == TYPEID_PLAYER && target->GetHealth() <= target->GetMaxHealth()*0.10f)
				{
					damage = GetHitUnit()->GetHealth();
					SetHitDamage(damage);
				}

				if (target->GetTypeId() != TYPEID_PLAYER && caster->GetHealth() >= target->GetHealth())
				{
					damage = GetHitUnit()->GetHealth();
					SetHitDamage(damage);
				}
			}

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_monk_touch_of_death_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
				OnCheckCast += SpellCheckCastFn(spell_monk_touch_of_death_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_touch_of_death_SpellScript();
        }
};

// Fortifying brew - 115203
class spell_monk_fortifying_brew : public SpellScriptLoader
{
    public:
        spell_monk_fortifying_brew() : SpellScriptLoader("spell_monk_fortifying_brew") { }

        class spell_monk_fortifying_brew_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_fortifying_brew_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (caster && caster->GetTypeId() == TYPEID_PLAYER)
                    caster->CastSpell(caster, SPELL_MONK_FORTIFYING_BREW, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_fortifying_brew_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_fortifying_brew_SpellScript();
        }
};




//119611 - Renewing mist
class spell_monk_renewing_mist : public SpellScriptLoader
{
public:
    spell_monk_renewing_mist() : SpellScriptLoader("spell_monk_renewing_mist") { }


    class spell_monk_renewing_mist_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_renewing_mist_AuraScript);

        void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
        {
            GetCaster()->CastSpell(GetCaster(), 123757); //aura for spell elevation
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_renewing_mist_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_monk_renewing_mist_AuraScript();
    }
};

// Brewing : Tigereye Brew - 123980
class spell_monk_tigereye_brew_stacks : public SpellScriptLoader
{
    public:
        spell_monk_tigereye_brew_stacks() : SpellScriptLoader("spell_monk_tigereye_brew_stacks") { }

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
                    data = data > 4 ? data - 4: 0;

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

// Dampen Harm - 122278
class spell_monk_dampen_harm : public SpellScriptLoader
{
public:
	spell_monk_dampen_harm() : SpellScriptLoader("spell_monk_dampen_harm") { }

	class spell_monk_dampen_harm_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_monk_dampen_harm_AuraScript);

		uint32 healthPct;

		void CalculateAmount(AuraEffect const* /*auraEffect*/, int32& amount, bool& /*canBeRecalculated*/)
		{
			amount = -1;
		}

		void Absorb(AuraEffect* aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount)
		{
			Unit* target = GetTarget();

			uint32 health = target->CountPctFromMaxHealth(healthPct);

			if (dmgInfo.GetDamage() < health)
				return;

			// The next 3 attacks within 45 sec that deal damage equal to 10% or more of your total health are reduced by half
			absorbAmount = dmgInfo.GetDamage() / 2;
			aurEff->GetBase()->DropCharge();
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

// Called by Jab - 100780
// Power Strikes - 121817
class spell_monk_power_strikes : public SpellScriptLoader
{
public:
	spell_monk_power_strikes() : SpellScriptLoader("spell_monk_power_strikes") { }

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
							if (!_player->HasSpellCooldown(SPELL_MONK_POWER_STRIKES_TALENT))
							{
								if (_player->GetPower(POWER_CHI) < _player->GetMaxPower(POWER_CHI))
								{
									_player->EnergizeBySpell(_player, GetSpellInfo()->Id, 1, POWER_CHI);
									_player->AddSpellCooldown(SPELL_MONK_POWER_STRIKES_TALENT, 0, time(NULL) + 20);
								}
								else
									_player->CastSpell(_player, SPELL_MONK_CREATE_CHI_SPHERE, true);
							}
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

class spell_monk_legacy_of_the_white_tiger : public SpellScriptLoader
{
public:
	spell_monk_legacy_of_the_white_tiger() : SpellScriptLoader("spell_monk_legacy_of_the_white_tiger") { }

	class spell_monk_legacy_of_the_white_tiger_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_monk_legacy_of_the_white_tiger_SpellScript);

		void HandleAfterCast()
		{
			if (Player* _player = GetCaster()->ToPlayer())
				if (Unit* target = GetExplTargetUnit())
					_player->CastSpell(target, SPELL_MONK_LEGACY_OF_THE_WHITE_TIGER, true);
		}

		void Register()
		{
			AfterCast += SpellCastFn(spell_monk_legacy_of_the_white_tiger_SpellScript::HandleAfterCast);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_monk_legacy_of_the_white_tiger_SpellScript();
	}
};

// 116670 - Elevation
class spell_monk_elevation : public SpellScriptLoader
{
public:
	spell_monk_elevation() : SpellScriptLoader("spell_monk_elevation") { }


	class spell_monk_elevation_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_monk_elevation_SpellScript);

		void HandleOnHit()
		{
			if (!GetOriginalCaster())
				return;

			if (Player* _player = GetOriginalCaster()->ToPlayer())
				if (Unit* target = GetHitUnit())
					_player->CastSpell(target, SPELL_MONK_ELEVATION, true);
		}

		void Register()
		{
			OnHit += SpellHitFn(spell_monk_elevation_SpellScript::HandleOnHit);
		}

	};

	SpellScript* GetSpellScript() const
	{
		return new spell_monk_elevation_SpellScript();
	}
};

// Zen Pilgrimage - 126892 and Zen Pilgrimage : Return - 126895
class spell_monk_zen_pilgrimage : public SpellScriptLoader
{
public:
	spell_monk_zen_pilgrimage() : SpellScriptLoader("spell_monk_zen_pilgrimage") { }

	class spell_monk_zen_pilgrimage_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_monk_zen_pilgrimage_SpellScript);

		bool Validate(SpellInfo const* /*spell*/)
		{
			if (!sSpellMgr->GetSpellInfo(SPELL_MONK_ZEN_PILGRIMAGE) || !sSpellMgr->GetSpellInfo(SPELL_MONK_ZEN_PILGRIMAGE_RETURN))
				return false;
			return true;
		}

		void HandleDummy(SpellEffIndex /*effIndex*/)
		{
			if (Unit* caster = GetCaster())
			{
				if (Player* _player = caster->ToPlayer())
				{
					if (GetSpellInfo()->Id == SPELL_MONK_ZEN_PILGRIMAGE)
					{
						_player->SaveRecallPosition();
						_player->TeleportTo(870, 3818.55f, 1793.18f, 950.35f, _player->GetOrientation());
					}
					else if (GetSpellInfo()->Id == SPELL_MONK_ZEN_PILGRIMAGE_RETURN)
					{
						_player->TeleportTo(_player->m_recallMap, _player->m_recallX, _player->m_recallY, _player->m_recallZ, _player->m_recallO);
						_player->RemoveAura(126896);
					}
				}
			}
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(spell_monk_zen_pilgrimage_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_monk_zen_pilgrimage_SpellScript();
	}
};

// Elusive Brew - 115308
class spell_monk_elusive_brew : public SpellScriptLoader
{
public:
	spell_monk_elusive_brew() : SpellScriptLoader("spell_monk_elusive_brew") { }

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

// Chi Torpedo - 115008 or Chi Torpedo (3 charges) - 121828
class spell_monk_chi_torpedo : public SpellScriptLoader
{
public:
spell_monk_chi_torpedo() : SpellScriptLoader("spell_monk_chi_torpedo") { }

class spell_monk_chi_torpedo_SpellScript : public SpellScript
{
PrepareSpellScript(spell_monk_chi_torpedo_SpellScript);

void HandleOnHit()
{
	if (!GetOriginalCaster())
		return;

	if (Player* _player = GetOriginalCaster()->ToPlayer())
		if (Unit* target = GetHitUnit())
			_player->CastSpell(target, SPELL_MONK_CHI_TORPEDO, true);
}

void Register()
{
	OnHit += SpellHitFn(spell_monk_chi_torpedo_SpellScript::HandleOnHit);
}
};

SpellScript* GetSpellScript() const
{
return new spell_monk_chi_torpedo_SpellScript();
}
};

/*
// ########## Missing Spells ##########
// Spinning Fire Blossom - 115073
// Summon Jade Serpent Statue - 115313
// Energizing Brew - 115288
// Blackout Kick - 100784
// Soothing Mist - 115175
// 119996 - Transcendence Transfert
// 101643 Transcendence
// 54569 - Trasncendence Spirit
// ####################################
*/

void AddSC_monk_spell_scripts()
{
    new spell_monk_fists_of_fury_stun();
    new spell_monk_expel_harm();
    new spell_monk_guard();
    new spell_monk_bear_hug();
    new spell_monk_zen_flight_check();
    new spell_monk_crackling_jade_lightning();
    new spell_monk_touch_of_karma();
    new spell_monk_spinning_fire_blossom_damage();
    new spell_monk_path_of_blossom();
    new spell_monk_teachings_of_the_monastery();
    new spell_monk_mana_tea();
    new spell_monk_mana_tea_stacks();
    new spell_monk_enveloping_mist();
    new spell_monk_surging_mist();
    new spell_monk_healing_elixirs();
    new spell_monk_zen_sphere();
    new spell_monk_zen_sphere_hot();
    new spell_monk_spear_hand_strike();
    new spell_monk_tigereye_brew();
    new spell_monk_tigers_lust();
    new spell_monk_flying_serpent_kick();
    new spell_monk_purifying_brew();
    new spell_monk_clash();
    new spell_monk_keg_smash();
    new spell_monk_breath_of_fire();
    new spell_monk_provoke();
    new spell_monk_tigereye_brew_stacks();
    new spell_monk_paralysis();
    new spell_monk_renewing_mist();
    new spell_monk_touch_of_death();
	new spell_monk_dampen_harm();
	new spell_monk_legacy_of_the_white_tiger();
	new spell_monk_power_strikes();
	new spell_monk_elevation();
	new spell_monk_zen_pilgrimage();
	new spell_monk_elusive_brew();
	new spell_monk_chi_torpedo();
	//new spell_monk_spinning_fire_blossom();
	//new spell_monk_jade_serpent_statue();
	//new spell_monk_energizing_brew();
	//new spell_monk_blackout_kick();
	//new spell_monk_soothing_mist();
	//new spell_monk_transcendence_transfert();
	//new spell_monk_transcendence();
	//new npc_transcendence_spirit();
}

