/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_DEATHKNIGHT and SPELLFAMILY_GENERIC spells used by deathknight players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dk_".
 */

#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Containers.h"

enum DeathKnightSpells
{
    SPELL_DK_ARMY_FLESH_BEAST_TRANSFORM         = 127533,
    SPELL_DK_ARMY_GEIST_TRANSFORM               = 127534,
    SPELL_DK_ARMY_NORTHREND_SKELETON_TRANSFORM  = 127528,
    SPELL_DK_ARMY_SKELETON_TRANSFORM            = 127527,
    SPELL_DK_ARMY_SPIKED_GHOUL_TRANSFORM        = 127525,
    SPELL_DK_ARMY_SUPER_ZOMBIE_TRANSFORM        = 127526,
    SPELL_DK_BLOOD_PLAGUE                       = 55078,
    SPELL_DK_BLOOD_PRESENCE                     = 48263,
    SPELL_DK_BLOOD_SHIELD_MASTERY               = 77513,
    SPELL_DK_BLOOD_SHIELD_ABSORB                = 77535,
    SPELL_DK_CHAINS_OF_ICE                      = 45524,
    SPELL_DK_CORPSE_EXPLOSION_TRIGGERED         = 43999,
    SPELL_DK_DEATH_AND_DECAY_DAMAGE             = 52212,
    SPELL_DK_DEATH_AND_DECAY_SLOW               = 143375,
    SPELL_DK_DEATH_COIL_BARRIER                 = 115635,
    SPELL_DK_DEATH_COIL_DAMAGE                  = 47632,
    SPELL_DK_DEATH_COIL_HEAL                    = 47633,
    SPELL_DK_DEATH_STRIKE_HEAL                  = 45470,
    SPELL_DK_ENHANCED_DEATH_COIL                = 157343,
    SPELL_DK_FROST_FEVER                        = 55095,
    SPELL_DK_GHOUL_EXPLODE                      = 47496,
    SPELL_DK_GLYPH_OF_ABSORB_MAGIC              = 159415,
    SPELL_DK_GLYPH_OF_ANTI_MAGIC_SHELL          = 58623,
    SPELL_DK_GLYPH_OF_ARMY_OF_THE_DEAD          = 58669,
    SPELL_DK_GLYPH_OF_DEATH_COIL                = 63333,
    SPELL_DK_GLYPH_OF_DEATH_AND_DECAY           = 58629,
    SPELL_DK_GLYPH_OF_FOUL_MENAGERIE            = 58642,
    SPELL_DK_GLYPH_OF_REGENERATIVE_MAGIC        = 146648,
    SPELL_DK_GLYPH_OF_RUNIC_POWER_TRIGGERED     = 159430,
    SPELL_DK_GLYPH_OF_SWIFT_DEATH               = 146645,
    SPELL_DK_GLYPH_OF_THE_GEIST                 = 58640,
    SPELL_DK_GLYPH_OF_THE_SKELETON              = 146652,
    SPELL_DK_IMPROVED_BLOOD_PRESENCE            = 50371,
    SPELL_DK_IMPROVED_SOUL_REAPER               = 157342,
    SPELL_DK_RUNIC_POWER_ENERGIZE               = 49088,
    SPELL_DK_SCENT_OF_BLOOD                     = 49509,
    SPELL_DK_SCENT_OF_BLOOD_TRIGGERED           = 50421,
    SPELL_DK_SCOURGE_STRIKE_TRIGGERED           = 70890,
    SPELL_DK_SHADOW_OF_DEATH                    = 164047,
    SPELL_DK_SOUL_REAPER_DAMAGE                 = 114867,
    SPELL_DK_SOUL_REAPER_HASTE                  = 114868,
    SPELL_DK_T15_DPS_4P_BONUS                   = 138347,
    SPELL_DK_UNHOLY_PRESENCE                    = 48265,
    SPELL_DK_WILL_OF_THE_NECROPOLIS             = 157335
};

// 48707 - Anti-Magic Shell
/// 6.x
class spell_dk_anti_magic_shell : public SpellScriptLoader
{
    public:
        spell_dk_anti_magic_shell() : SpellScriptLoader("spell_dk_anti_magic_shell") { }

        class spell_dk_anti_magic_shell_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_anti_magic_shell_AuraScript);

        public:
            spell_dk_anti_magic_shell_AuraScript() 
            {
                absorbPct = 0;
                maxHealth = 0;
                absorbedAmount = 0;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_RUNIC_POWER_ENERGIZE))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_GLYPH_OF_ABSORB_MAGIC))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_GLYPH_OF_REGENERATIVE_MAGIC))
                    return false;
                return true;
            }

            bool Load() override
            {
                absorbPct = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue(GetCaster());
                maxHealth = GetCaster()->GetMaxHealth();
                absorbedAmount = 0;
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                amount = maxHealth;

                /// todo, check if AMS has basepoints for EFFECT_2. in that case, this function should be rewritten.
                if (!GetUnitOwner()->HasAura(SPELL_DK_GLYPH_OF_ABSORB_MAGIC))
                    amount /= 2;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
            {
                // we may only absorb a certain percentage of incoming damage.
                absorbAmount = dmgInfo.GetDamage() * uint32(absorbPct) / 100;
            }

            void Trigger(AuraEffect* aurEff, DamageInfo& /*dmgInfo*/, uint32& absorbAmount)
            {
                absorbedAmount += absorbAmount;

                if (!GetTarget()->HasAura(SPELL_DK_GLYPH_OF_ABSORB_MAGIC))
                {
                    // Patch 6.0.2 (October 14, 2014): Anti-Magic Shell now restores 2 Runic Power per 1% of max health absorbed.
                    int32 bp = 2 * absorbAmount * 100 / maxHealth;
                    GetTarget()->CastCustomSpell(SPELL_DK_RUNIC_POWER_ENERGIZE, SPELLVALUE_BASE_POINT0, bp, GetTarget(), true, nullptr, aurEff);
                }
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Player* player = GetTarget()->ToPlayer())
                    if (AuraEffect const* glyph = player->GetAuraEffect(SPELL_DK_GLYPH_OF_REGENERATIVE_MAGIC, EFFECT_0)) // reduce cooldown of AMS if player has glyph
                    {
                        // Cannot reduce cooldown by more than 50%
                        int32 val = std::min(glyph->GetAmount(), int32(absorbedAmount) * 100 / maxHealth);
                        player->ModifySpellCooldown(GetId(), -int32(player->GetSpellCooldownDelay(GetId()) * val / 100));
                    }
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_anti_magic_shell_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_shell_AuraScript::Absorb, EFFECT_0);
                AfterEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_shell_AuraScript::Trigger, EFFECT_0);
                AfterEffectRemove += AuraEffectRemoveFn(spell_dk_anti_magic_shell_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            }

        private:
            int32 absorbPct;
            int32 maxHealth;
            uint32 absorbedAmount;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_anti_magic_shell_AuraScript();
        }
};

// 43264 - Periodic Taunt
/// 6.x, does this belong here or in spell_generic? apply this in creature_template_addon? sniffs say this is always cast army of the dead ghouls.
class spell_dk_army_periodic_taunt : public SpellScriptLoader
{
    public:
        spell_dk_army_periodic_taunt() : SpellScriptLoader("spell_dk_army_periodic_taunt") { }

        class spell_dk_army_periodic_taunt_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_army_periodic_taunt_SpellScript);

            bool Load() override
            {
                return GetCaster()->IsGuardian();
            }

            SpellCastResult CheckCast()
            {
                if (Unit* owner = GetCaster()->GetOwner())
                    if (!owner->HasAura(SPELL_DK_GLYPH_OF_ARMY_OF_THE_DEAD))
                        return SPELL_CAST_OK;

                return SPELL_FAILED_SPELL_UNAVAILABLE;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_army_periodic_taunt_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_army_periodic_taunt_SpellScript();
        }
};

static const uint32 ArmyTransforms[6]
{
    SPELL_DK_ARMY_FLESH_BEAST_TRANSFORM,
    SPELL_DK_ARMY_GEIST_TRANSFORM,
    SPELL_DK_ARMY_NORTHREND_SKELETON_TRANSFORM,
    SPELL_DK_ARMY_SKELETON_TRANSFORM,
    SPELL_DK_ARMY_SPIKED_GHOUL_TRANSFORM,
    SPELL_DK_ARMY_SUPER_ZOMBIE_TRANSFORM
};

// 127517 - Army Transform
/// 6.x, does this belong here or in spell_generic? where do we cast this? sniffs say this is only cast when caster has glyph of foul menagerie.
class spell_dk_army_transform : public SpellScriptLoader
{
    public:
        spell_dk_army_transform() : SpellScriptLoader("spell_dk_army_transform") { }

        class spell_dk_army_transform_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_army_transform_SpellScript);

            bool Load() override
            {
                return GetCaster()->IsGuardian();
            }

            SpellCastResult CheckCast()
            {
                if (Unit* owner = GetCaster()->GetOwner())
                    if (owner->HasAura(SPELL_DK_GLYPH_OF_FOUL_MENAGERIE))
                        return SPELL_CAST_OK;

                return SPELL_FAILED_SPELL_UNAVAILABLE;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetCaster(), ArmyTransforms[urand(0, 5)], true);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_army_transform_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_dk_army_transform_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_army_transform_SpellScript();
        }
};

// 50842 - Blood Boil
/// 6.x
class spell_dk_blood_boil : public SpellScriptLoader
{
    public:
        spell_dk_blood_boil() : SpellScriptLoader("spell_dk_blood_boil") { }

        class spell_dk_blood_boil_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_blood_boil_SpellScript);

        public:
            spell_dk_blood_boil_SpellScript()
            {
                bpDuration = 0;
                ffDuration = 0;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_SCENT_OF_BLOOD_TRIGGERED))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_SCENT_OF_BLOOD))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_PLAGUE))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_FROST_FEVER))
                    return false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Unit* caster = GetCaster();

                if (caster->HasAura(SPELL_DK_SCENT_OF_BLOOD))
                    return;

                for (auto target : targets)
                {
                    if (bpDuration && ffDuration)
                        break;

                    if (Unit* unit = target->ToUnit())
                    {
                        if (Aura const* bp = unit->GetAura(SPELL_DK_BLOOD_PLAGUE, caster->GetGUID()))
                            bpDuration = bp->GetDuration();
                        if (Aura const* ff = unit->GetAura(SPELL_DK_FROST_FEVER, caster->GetGUID()))
                            ffDuration = ff->GetDuration();
                    }
                }
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();

                if (ffDuration)
                    caster->CastSpell(target, SPELL_DK_FROST_FEVER, true);
                if (bpDuration)
                    caster->CastSpell(target, SPELL_DK_BLOOD_PLAGUE, true);

                if (!caster->HasAura(SPELL_DK_SCENT_OF_BLOOD))
                {
                    if (Aura* bp = target->GetAura(SPELL_DK_BLOOD_PLAGUE, caster->GetGUID()))
                    {
                        bp->SetDuration(bpDuration);
                        bp->SetMaxDuration(bpDuration);
                    }
                    if (Aura* ff = target->GetAura(SPELL_DK_FROST_FEVER, caster->GetGUID()))
                    {
                        ff->SetDuration(ffDuration);
                        ff->SetMaxDuration(ffDuration);
                    }
                }
            }

            void HandleEnergize(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();

                if (caster->HasAura(SPELL_DK_SCENT_OF_BLOOD))
                    caster->CastSpell(caster, SPELL_DK_SCENT_OF_BLOOD_TRIGGERED, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dk_blood_boil_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_dk_blood_boil_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnEffectHitTarget += SpellEffectFn(spell_dk_blood_boil_SpellScript::HandleEnergize, EFFECT_1, SPELL_EFFECT_ENERGIZE);
            }

        private:
            int32 bpDuration;
            int32 ffDuration;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_blood_boil_SpellScript();
        }
};

// 43265 - Death and Decay
/// 6.x
class spell_dk_death_and_decay : public SpellScriptLoader
{
    public:
        spell_dk_death_and_decay() : SpellScriptLoader("spell_dk_death_and_decay") { }

        class spell_dk_death_and_decay_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_and_decay_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (GetCaster()->HasAura(SPELL_DK_GLYPH_OF_DEATH_AND_DECAY))
                    if (WorldLocation const* pos = GetExplTargetDest())
                        GetCaster()->CastSpell(pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), SPELL_DK_DEATH_AND_DECAY_SLOW, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_and_decay_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_and_decay_SpellScript();
        }

        class spell_dk_death_and_decay_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_death_and_decay_AuraScript);

            void HandleDummyTick(AuraEffect const* aurEff)
            {
                if (Unit* caster = GetCaster())
                    caster->CastCustomSpell(SPELL_DK_DEATH_AND_DECAY_DAMAGE, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_dk_death_and_decay_AuraScript::HandleDummyTick, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_death_and_decay_AuraScript();
        }
};

// 47541 - Death Coil
/// 6.x
class spell_dk_death_coil : public SpellScriptLoader
{
    public:
        spell_dk_death_coil() : SpellScriptLoader("spell_dk_death_coil") { }

        class spell_dk_death_coil_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_coil_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_DEATH_COIL_DAMAGE) || !sSpellMgr->GetSpellInfo(SPELL_DK_DEATH_COIL_HEAL) || !sSpellMgr->GetSpellInfo(SPELL_DK_GLYPH_OF_DEATH_COIL))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    if (caster->IsFriendlyTo(target))
                    {
                        if (target->GetCreatureType() == CREATURE_TYPE_UNDEAD) // Any undead ally, including caster if he has lichborne.
                        {
                            caster->CastSpell(target, SPELL_DK_DEATH_COIL_HEAL, true);
                        }
                        else if (target != caster) // Any non undead ally except caster and only if caster has glyph of death coil.
                        {
                            SpellInfo const* DCD = sSpellMgr->EnsureSpellInfo(SPELL_DK_DEATH_COIL_DAMAGE);
                            SpellEffectInfo const* eff = DCD->GetEffect(EFFECT_0);
                            int32 bp = caster->SpellDamageBonusDone(target, DCD, eff->CalcValue(caster), DIRECT_DAMAGE, eff);

                            caster->CastCustomSpell(target, SPELL_DK_DEATH_COIL_BARRIER, &bp, nullptr, nullptr, true);
                        }
                    }
                    else // Any enemy target.
                    {
                        caster->CastSpell(target, SPELL_DK_DEATH_COIL_DAMAGE, true);
                    }
                }

                if (caster->HasAura(SPELL_DK_ENHANCED_DEATH_COIL))
                    caster->CastSpell(caster, SPELL_DK_SHADOW_OF_DEATH, true);
            }

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetExplTargetUnit())
                {
                    if (!caster->IsFriendlyTo(target) && !caster->isInFront(target))
                        return SPELL_FAILED_UNIT_NOT_INFRONT;

                    if (target->IsFriendlyTo(caster) && target->GetCreatureType() != CREATURE_TYPE_UNDEAD && !caster->HasAura(SPELL_DK_GLYPH_OF_DEATH_COIL))
                        return SPELL_FAILED_BAD_TARGETS;
                }
                else
                    return SPELL_FAILED_BAD_TARGETS;

                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_death_coil_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_coil_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_coil_SpellScript();
        }
};

// 52751 - Death Gate
class spell_dk_death_gate : public SpellScriptLoader
{
    public:
        spell_dk_death_gate() : SpellScriptLoader("spell_dk_death_gate") { }

        class spell_dk_death_gate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_gate_SpellScript);

            SpellCastResult CheckClass()
            {
                if (GetCaster()->getClass() != CLASS_DEATH_KNIGHT)
                {
                    SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_MUST_BE_DEATH_KNIGHT);
                    return SPELL_FAILED_CUSTOM_ERROR;
                }

                return SPELL_CAST_OK;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, GetEffectValue(), false);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_death_gate_SpellScript::CheckClass);
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_gate_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_gate_SpellScript();
        }
};

// 49560 - Death Grip
class spell_dk_death_grip : public SpellScriptLoader
{
    public:
        spell_dk_death_grip() : SpellScriptLoader("spell_dk_death_grip") { }

        class spell_dk_death_grip_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_grip_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                int32 damage = GetEffectValue();
                Position const* pos = GetExplTargetDest();
                if (Unit* target = GetHitUnit())
                {
                    if (!target->HasAuraType(SPELL_AURA_DEFLECT_SPELLS)) // Deterrence
                        target->CastSpell(pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), damage, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_grip_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_grip_SpellScript();
        }
};

// 48743 - Death Pact
/// 6.x
class spell_dk_death_pact : public SpellScriptLoader
{
    public:
        spell_dk_death_pact() : SpellScriptLoader("spell_dk_death_pact") { }

        class spell_dk_death_pact_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_death_pact_AuraScript);

            void HandleCalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster())
                    amount = int32(caster->CountPctFromMaxHealth(amount));
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_death_pact_AuraScript::HandleCalcAmount, EFFECT_1, SPELL_AURA_SCHOOL_HEAL_ABSORB);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_death_pact_AuraScript();
        }
};

// 49998 - Death Strike
/// 6.x
class spell_dk_death_strike : public SpellScriptLoader
{
    public:
        spell_dk_death_strike() : SpellScriptLoader("spell_dk_death_strike") { }

        class spell_dk_death_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_strike_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_DEATH_STRIKE_HEAL) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_SHIELD_MASTERY) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_SHIELD_ABSORB))
                    return false;
                return true;
            }

            void HandleHeal(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                int32 heal = caster->GetTotalAttackPowerValue(BASE_ATTACK) * 4; /// todo, add versatality bonus as it will probably not apply to the heal due to its damageclass SPELL_DAMAGE_CLASS_NONE.
                caster->CastCustomSpell(SPELL_DK_DEATH_STRIKE_HEAL, SPELLVALUE_BASE_POINT0, heal, caster, true);

                if (!caster->HasAura(SPELL_DK_BLOOD_PRESENCE) || !caster->HasAura(SPELL_DK_IMPROVED_BLOOD_PRESENCE))
                    return;

                /// todo, if SPELL_AURA_MOD_ABSORB_PERCENTAGE will not apply to SPELL_DAMAGE_CLASS_NONE, resolve must be applied here.
                if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_DK_BLOOD_SHIELD_MASTERY, EFFECT_0))
                    caster->CastCustomSpell(SPELL_DK_BLOOD_SHIELD_ABSORB, SPELLVALUE_BASE_POINT0, CalculatePct(heal, aurEff->GetAmount()), caster);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_strike_SpellScript::HandleHeal, EFFECT_1, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_strike_SpellScript();
        }
};

// 85948 - Festering Strike
/// 6.x
class spell_dk_festering_strike : public SpellScriptLoader
{
    public:
        spell_dk_festering_strike() : SpellScriptLoader("spell_dk_festering_strike") { }

        class spell_dk_festering_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_festering_strike_SpellScript);

        public:
            spell_dk_festering_strike_SpellScript() { }

        private:
            bool Validate(SpellInfo const* spellInfo) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_FROST_FEVER) || !sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_PLAGUE) || !sSpellMgr->GetSpellInfo(SPELL_DK_CHAINS_OF_ICE))
                    return false;
                return false;
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                int32 extraDuration = GetSpellInfo()->GetEffect(EFFECT_2)->CalcValue();
                Unit* target = GetHitUnit();
                ObjectGuid casterGUID = GetCaster()->GetGUID();

                if (Aura* ff = target->GetAura(SPELL_DK_FROST_FEVER, casterGUID))
                {
                    int32 newDuration = std::min(ff->GetDuration() + extraDuration, 2 * MINUTE * IN_MILLISECONDS); // caps at 2min.
                    ff->SetDuration(newDuration);
                    ff->SetMaxDuration(newDuration);
                }

                if (Aura* bp = target->GetAura(SPELL_DK_BLOOD_PLAGUE, casterGUID))
                {
                    int32 newDuration = std::min(bp->GetDuration() + extraDuration, 2 * MINUTE * IN_MILLISECONDS); // caps at 2min.
                    bp->SetDuration(newDuration);
                    bp->SetMaxDuration(newDuration);
                }

                if (Aura* coi = target->GetAura(SPELL_DK_CHAINS_OF_ICE, casterGUID))
                {
                    int32 newDuration = std::min(coi->GetDuration() + extraDuration, 20 * IN_MILLISECONDS); // is 20sec cap? couldnt manage to get runes up to pass 20.
                    coi->SetDuration(newDuration);
                    coi->SetMaxDuration(newDuration);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_festering_strike_SpellScript::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_festering_strike_SpellScript();
        }
};

// 47496 - Explode, Ghoul spell for Corpse Explosion
class spell_dk_ghoul_explode : public SpellScriptLoader
{
    public:
        spell_dk_ghoul_explode() : SpellScriptLoader("spell_dk_ghoul_explode") { }

        class spell_dk_ghoul_explode_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_ghoul_explode_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_CORPSE_EXPLOSION_TRIGGERED))
                    return false;
                return true;
            }

            void Suicide(SpellEffIndex /*effIndex*/)
            {
                if (Unit* unitTarget = GetHitUnit())
                {
                    // Corpse Explosion (Suicide)
                    unitTarget->CastSpell(unitTarget, SPELL_DK_CORPSE_EXPLOSION_TRIGGERED, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_ghoul_explode_SpellScript::Suicide, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_ghoul_explode_SpellScript();
        }
};

// 58677 - Glyph of Death's Embrace
/// 6.x
class spell_dk_glyph_of_deaths_embrace : public SpellScriptLoader
{
    public:
        spell_dk_glyph_of_deaths_embrace() : SpellScriptLoader("spell_dk_glyph_of_deaths_embrace") { }

        class spell_dk_glyph_of_deaths_embrace_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_glyph_of_deaths_embrace_AuraScript);

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return (GetTarget()->GetCreatureType() == CREATURE_TYPE_UNDEAD && GetTarget()->GetOwner());
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_dk_glyph_of_deaths_embrace_AuraScript::CheckProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_glyph_of_deaths_embrace_AuraScript();
        }
};

// 159429 - Glyph of Runic Power
/// 6.x
class spell_dk_glyph_of_runic_power : public SpellScriptLoader
{
    public:
        spell_dk_glyph_of_runic_power() : SpellScriptLoader("spell_dk_glyph_of_runic_power") { }

        class spell_dk_glyph_of_runic_power_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_glyph_of_runic_power_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_GLYPH_OF_RUNIC_POWER_TRIGGERED))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetSpellInfo() && (eventInfo.GetSpellInfo()->GetAllEffectsMechanicMask() & (1 << MECHANIC_SNARE | 1 << MECHANIC_ROOT | 1 << MECHANIC_FREEZE));
            }

            void HandleProc(ProcEventInfo& eventInfo)
            {
                if (Unit* target = eventInfo.GetProcTarget())
                    if (target->getClass() == CLASS_DEATH_KNIGHT)
                        target->CastSpell(target, SPELL_DK_GLYPH_OF_RUNIC_POWER_TRIGGERED, true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_dk_glyph_of_runic_power_AuraScript::CheckProc);
                OnProc += AuraProcFn(spell_dk_glyph_of_runic_power_AuraScript::HandleProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_glyph_of_runic_power_AuraScript();
        }
};

// 48792 - Icebound Fortitude
/// 6.x
class spell_dk_icebound_fortitude : public SpellScriptLoader
{
    public:
        spell_dk_icebound_fortitude() : SpellScriptLoader("spell_dk_icebound_fortitude") { }

        class spell_dk_icebound_fortitude_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_icebound_fortitude_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (GetUnitOwner()->HasAura(SPELL_DK_IMPROVED_BLOOD_PRESENCE))
                    amount += 30; /// todo, figure out how tooltip is updated
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_icebound_fortitude_AuraScript::CalculateAmount, EFFECT_2, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_icebound_fortitude_AuraScript();
        }
};

// 121916 - Glyph of the Geist (Unholy)
/// 6.x, does this belong here or in spell_generic? apply this in creature_template_addon? sniffs say this is always cast on raise dead.
class spell_dk_pet_geist_transform : public SpellScriptLoader
{
    public:
        spell_dk_pet_geist_transform() : SpellScriptLoader("spell_dk_pet_geist_transform") { }

        class spell_dk_pet_geist_transform_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_pet_geist_transform_SpellScript);

            bool Load() override
            {
                return GetCaster()->IsPet();
            }

            SpellCastResult CheckCast()
            {
                if (Unit* owner = GetCaster()->GetOwner())
                    if (owner->HasAura(SPELL_DK_GLYPH_OF_THE_GEIST))
                        return SPELL_CAST_OK;

                return SPELL_FAILED_SPELL_UNAVAILABLE;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_pet_geist_transform_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_pet_geist_transform_SpellScript();
        }
};

// 147157 Glyph of the Skeleton (Unholy)
/// 6.x, does this belong here or in spell_generic? apply this in creature_template_addon? sniffs say this is always cast on raise dead.
class spell_dk_pet_skeleton_transform : public SpellScriptLoader
{
    public:
        spell_dk_pet_skeleton_transform() : SpellScriptLoader("spell_dk_pet_skeleton_transform") { }

        class spell_dk_pet_skeleton_transform_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_pet_skeleton_transform_SpellScript);

            SpellCastResult CheckCast()
            {
                if (Unit* owner = GetCaster()->GetOwner())
                    if (owner->HasAura(SPELL_DK_GLYPH_OF_THE_SKELETON))
                        return SPELL_CAST_OK;

                return SPELL_FAILED_SPELL_UNAVAILABLE;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_pet_skeleton_transform_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_pet_skeleton_transform_SpellScript();
        }
};

// 46584 - Raise Dead
/// 6.x
class spell_dk_raise_dead : public SpellScriptLoader
{
    public:
        spell_dk_raise_dead() : SpellScriptLoader("spell_dk_raise_dead") { }

        class spell_dk_raise_dead_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_raise_dead_SpellScript);

        public:
            spell_dk_raise_dead_SpellScript() { }

        private:
            bool Validate(SpellInfo const* spellInfo) override
            {
                if (!spellInfo->GetEffect(EFFECT_0) || !sSpellMgr->GetSpellInfo(spellInfo->GetEffect(EFFECT_0)->CalcValue()))
                    return false;
                return false;
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(((Unit*)nullptr), GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue(), true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_raise_dead_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_raise_dead_SpellScript();
        }
};

// 114866 - Soul Reaper, 130735 - Soul Reaper, 130736 - Soul Reaper
/// 6.x
class spell_dk_soul_reaper: public SpellScriptLoader
{
    public:
        spell_dk_soul_reaper() : SpellScriptLoader("spell_dk_soul_reaper") { }

        class spell_dk_soul_reaper_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_soul_reaper_AuraScript);

            void HandlePeriodicDummy(AuraEffect const* aurEff)
            {
                Unit* caster = GetCaster();
                Unit* target = GetUnitOwner();

                if (!caster || !target)
                    return;

                float pct = target->GetHealthPct();

                if (pct < 35.f || (pct < 45.f && (caster->HasAura(SPELL_DK_IMPROVED_SOUL_REAPER) || caster->HasAura(SPELL_DK_T15_DPS_4P_BONUS))))
                    caster->CastSpell(target, SPELL_DK_SOUL_REAPER_DAMAGE, true, nullptr, aurEff);
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
                    return;

                if (Unit* caster = GetCaster())
                    caster->CastSpell(caster, SPELL_DK_SOUL_REAPER_HASTE, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_dk_soul_reaper_AuraScript::HandlePeriodicDummy, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
                AfterEffectRemove += AuraEffectApplyFn(spell_dk_soul_reaper_AuraScript::HandleRemove, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_soul_reaper_AuraScript();
        }
};

// 115994 - Unholy Blight
/// 6.x
class spell_dk_unholy_blight : public SpellScriptLoader
{
    public:
        spell_dk_unholy_blight() : SpellScriptLoader("spell_dk_unholy_blight") { }

        class spell_dk_unholy_blight_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_unholy_blight_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_DK_FROST_FEVER, true);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_DK_BLOOD_PLAGUE, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_unholy_blight_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_unholy_blight_SpellScript();
        }
};

// 55233 - Vampiric Blood
/// 6.x
class spell_dk_vampiric_blood : public SpellScriptLoader
{
    public:
        spell_dk_vampiric_blood() : SpellScriptLoader("spell_dk_vampiric_blood") { }

        class spell_dk_vampiric_blood_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_vampiric_blood_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                amount = GetUnitOwner()->CountPctFromMaxHealth(amount);
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_vampiric_blood_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_HEALTH);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_vampiric_blood_AuraScript();
        }
};

// 81164 - Will of the Necropolis
/// 6.x
class spell_dk_will_of_the_necropolis : public SpellScriptLoader
{
    public:
        spell_dk_will_of_the_necropolis() : SpellScriptLoader("spell_dk_will_of_the_necropolis") { }

        class spell_dk_will_of_the_necropolis_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_will_of_the_necropolis_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_WILL_OF_THE_NECROPOLIS))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (GetTarget()->HasAura(SPELL_DK_WILL_OF_THE_NECROPOLIS))
                    return false;

               return GetTarget()->HealthBelowPctDamaged(30, eventInfo.GetDamageInfo()->GetDamage());
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_DK_WILL_OF_THE_NECROPOLIS, true, nullptr, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_dk_will_of_the_necropolis_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_dk_will_of_the_necropolis_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_will_of_the_necropolis_AuraScript();
        }
};

void AddSC_deathknight_spell_scripts()
{
    new spell_dk_anti_magic_shell();
    new spell_dk_army_periodic_taunt();
    new spell_dk_army_transform();
    new spell_dk_blood_boil();
    new spell_dk_death_and_decay();
    new spell_dk_death_coil();
    new spell_dk_death_gate();
    new spell_dk_death_grip();
    new spell_dk_death_pact();
    new spell_dk_death_strike();
    new spell_dk_festering_strike();
    new spell_dk_ghoul_explode();
    new spell_dk_glyph_of_deaths_embrace();
    new spell_dk_glyph_of_runic_power();
    new spell_dk_icebound_fortitude();
    new spell_dk_pet_geist_transform();
    new spell_dk_pet_skeleton_transform();
    new spell_dk_raise_dead();
    new spell_dk_soul_reaper();
    new spell_dk_unholy_blight();
    new spell_dk_vampiric_blood();
    new spell_dk_will_of_the_necropolis();
}
