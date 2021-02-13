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
 * Scripts for spells with SPELLFAMILY_DEATHKNIGHT and SPELLFAMILY_GENERIC spells used by deathknight players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dk_".
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum DeathKnightSpells
{
    SPELL_DK_ARMY_FLESH_BEAST_TRANSFORM         = 127533,
    SPELL_DK_ARMY_GEIST_TRANSFORM               = 127534,
    SPELL_DK_ARMY_NORTHREND_SKELETON_TRANSFORM  = 127528,
    SPELL_DK_ARMY_SKELETON_TRANSFORM            = 127527,
    SPELL_DK_ARMY_SPIKED_GHOUL_TRANSFORM        = 127525,
    SPELL_DK_ARMY_SUPER_ZOMBIE_TRANSFORM        = 127526,
    SPELL_DK_BLOOD                              = 137008,
    SPELL_DK_BLOOD_PLAGUE                       = 55078,
    SPELL_DK_BLOOD_SHIELD_ABSORB                = 77535,
    SPELL_DK_BLOOD_SHIELD_MASTERY               = 77513,
    SPELL_DK_CORPSE_EXPLOSION_TRIGGERED         = 43999,
    SPELL_DK_DEATH_AND_DECAY_DAMAGE             = 52212,
    SPELL_DK_DEATH_COIL_DAMAGE                  = 47632,
    SPELL_DK_DEATH_GRIP_DUMMY                   = 243912,
    SPELL_DK_DEATH_GRIP_JUMP                    = 49575,
    SPELL_DK_DEATH_GRIP_TAUNT                   = 51399,
    SPELL_DK_DEATH_STRIKE_HEAL                  = 45470,
    SPELL_DK_DEATH_STRIKE_OFFHAND               = 66188,
    SPELL_DK_FESTERING_WOUND                    = 194310,
    SPELL_DK_FROST                              = 137006,
    SPELL_DK_FROST_FEVER                        = 55095,
    SPELL_DK_GLYPH_OF_FOUL_MENAGERIE            = 58642,
    SPELL_DK_GLYPH_OF_THE_GEIST                 = 58640,
    SPELL_DK_GLYPH_OF_THE_SKELETON              = 146652,
    SPELL_DK_MARK_OF_BLOOD_HEAL                 = 206945,
    SPELL_DK_NECROSIS_EFFECT                    = 216974,
    SPELL_DK_RAISE_DEAD_SUMMON                  = 52150,
    SPELL_DK_RECENTLY_USED_DEATH_STRIKE         = 180612,
    SPELL_DK_RUNIC_POWER_ENERGIZE               = 49088,
    SPELL_DK_RUNIC_RETURN                       = 61258,
    SPELL_DK_SLUDGE_BELCHER                     = 207313,
    SPELL_DK_SLUDGE_BELCHER_SUMMON              = 212027,
    SPELL_DK_TIGHTENING_GRASP                   = 206970,
    SPELL_DK_TIGHTENING_GRASP_SLOW              = 143375,
    SPELL_DK_UNHOLY                             = 137007,
    SPELL_DK_UNHOLY_VIGOR                       = 196263,
    SPELL_DK_VOLATILE_SHIELDING                 = 207188,
    SPELL_DK_VOLATILE_SHIELDING_DAMAGE          = 207194
};

enum Misc
{
    NPC_DK_DANCING_RUNE_WEAPON                  = 27893
};

// 70656 - Advantage (T10 4P Melee Bonus)
class spell_dk_advantage_t10_4p : public SpellScriptLoader
{
public:
    spell_dk_advantage_t10_4p() : SpellScriptLoader("spell_dk_advantage_t10_4p") { }

    class spell_dk_advantage_t10_4p_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_advantage_t10_4p_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (Unit* caster = eventInfo.GetActor())
            {
                Player* player = caster->ToPlayer();
                if (!player  || caster->getClass() != CLASS_DEATH_KNIGHT)
                    return false;

                for (uint8 i = 0; i < player->GetMaxPower(POWER_RUNES); ++i)
                    if (player->GetRuneCooldown(i) == 0)
                        return false;

                return true;
            }

            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dk_advantage_t10_4p_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_advantage_t10_4p_AuraScript();
    }
};

// 48707 - Anti-Magic Shell
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
                return ValidateSpellInfo({ SPELL_DK_RUNIC_POWER_ENERGIZE, SPELL_DK_VOLATILE_SHIELDING });
            }

            bool Load() override
            {
                absorbPct = GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue(GetCaster());
                maxHealth = GetCaster()->GetMaxHealth();
                absorbedAmount = 0;
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                amount = CalculatePct(maxHealth, absorbPct);
            }

            void Trigger(AuraEffect* aurEff, DamageInfo& /*dmgInfo*/, uint32& absorbAmount)
            {
                absorbedAmount += absorbAmount;

                if (!GetTarget()->HasAura(SPELL_DK_VOLATILE_SHIELDING))
                {
                    int32 bp = 2 * absorbAmount * 100 / maxHealth;
                    GetTarget()->CastCustomSpell(SPELL_DK_RUNIC_POWER_ENERGIZE, SPELLVALUE_BASE_POINT0, bp, GetTarget(), true, nullptr, aurEff);
                }
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (AuraEffect const* volatileShielding = GetTarget()->GetAuraEffect(SPELL_DK_VOLATILE_SHIELDING, EFFECT_1))
                {
                    int32 damage = CalculatePct(absorbedAmount, volatileShielding->GetAmount());
                    GetTarget()->CastCustomSpell(SPELL_DK_VOLATILE_SHIELDING_DAMAGE, SPELLVALUE_BASE_POINT0, damage, nullptr, TRIGGERED_FULL_MASK, nullptr, volatileShielding);
                }
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_anti_magic_shell_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
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

static uint32 const ArmyTransforms[]
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

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_GLYPH_OF_FOUL_MENAGERIE });
            }

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
                GetCaster()->CastSpell(GetCaster(), Trinity::Containers::SelectRandomContainerElement(ArmyTransforms), true);
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
class spell_dk_blood_boil : public SpellScriptLoader
{
    public:
        spell_dk_blood_boil() : SpellScriptLoader("spell_dk_blood_boil") { }

        class spell_dk_blood_boil_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_blood_boil_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_BLOOD_PLAGUE });
            }

            void HandleEffect()
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_DK_BLOOD_PLAGUE, true);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_dk_blood_boil_SpellScript::HandleEffect);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_blood_boil_SpellScript();
        }
};

// 49028 - Dancing Rune Weapon
/// 7.1.5
class spell_dk_dancing_rune_weapon : public SpellScriptLoader
{
    public:
        spell_dk_dancing_rune_weapon() : SpellScriptLoader("spell_dk_dancing_rune_weapon") { }

        class spell_dk_dancing_rune_weapon_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_dancing_rune_weapon_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sObjectMgr->GetCreatureTemplate(NPC_DK_DANCING_RUNE_WEAPON))
                    return false;
                return true;
            }

            // This is a port of the old switch hack in Unit.cpp, it's not correct
            void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                Unit* drw = nullptr;
                for (Unit* controlled : caster->m_Controlled)
                {
                    if (controlled->GetEntry() == NPC_DK_DANCING_RUNE_WEAPON)
                    {
                        drw = controlled;
                        break;
                    }
                }

                if (!drw || !drw->GetVictim())
                    return;

                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return;

                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                int32 amount = static_cast<int32>(damageInfo->GetDamage()) / 2;
                SpellNonMeleeDamage log(drw, drw->GetVictim(), spellInfo, { spellInfo->GetSpellXSpellVisualId(drw), 0 }, spellInfo->GetSchoolMask());
                log.damage = amount;
                drw->DealDamage(drw->GetVictim(), amount, nullptr, SPELL_DIRECT_DAMAGE, spellInfo->GetSchoolMask(), spellInfo, true);
                drw->SendSpellNonMeleeDamageLog(&log);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dk_dancing_rune_weapon_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_dancing_rune_weapon_AuraScript();
        }
};

// 43265 - Death and Decay
class spell_dk_death_and_decay : public SpellScriptLoader
{
    public:
        spell_dk_death_and_decay() : SpellScriptLoader("spell_dk_death_and_decay") { }

        class spell_dk_death_and_decay_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_and_decay_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_TIGHTENING_GRASP, SPELL_DK_TIGHTENING_GRASP_SLOW });
            }

            void HandleDummy()
            {
                if (GetCaster()->HasAura(SPELL_DK_TIGHTENING_GRASP))
                    if (WorldLocation const* pos = GetExplTargetDest())
                        GetCaster()->CastSpell(pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), SPELL_DK_TIGHTENING_GRASP_SLOW, true);
            }

            void Register() override
            {
                OnCast += SpellCastFn(spell_dk_death_and_decay_SpellScript::HandleDummy);
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
                    caster->CastSpell(GetTarget(), SPELL_DK_DEATH_AND_DECAY_DAMAGE, true, nullptr, aurEff);
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
class spell_dk_death_coil : public SpellScriptLoader
{
    public:
        spell_dk_death_coil() : SpellScriptLoader("spell_dk_death_coil") { }

        class spell_dk_death_coil_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_coil_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_DEATH_COIL_DAMAGE, SPELL_DK_UNHOLY, SPELL_DK_UNHOLY_VIGOR });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                caster->CastSpell(GetHitUnit(), SPELL_DK_DEATH_COIL_DAMAGE, true);
                if (AuraEffect const* unholyAura = caster->GetAuraEffect(SPELL_DK_UNHOLY, EFFECT_6)) // can be any effect, just here to send SPELL_FAILED_DONT_REPORT on failure
                    caster->CastSpell(caster, SPELL_DK_UNHOLY_VIGOR, true, nullptr, unholyAura);
            }

            void Register() override
            {
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

// 49576 - Death Grip Initial
class spell_dk_death_grip_initial : public SpellScriptLoader
{
    public:
        spell_dk_death_grip_initial() : SpellScriptLoader("spell_dk_death_grip_initial") { }

        class spell_dk_death_grip_initial_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_grip_initial_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_DK_DEATH_GRIP_DUMMY,
                    SPELL_DK_DEATH_GRIP_JUMP,
                    SPELL_DK_BLOOD,
                    SPELL_DK_DEATH_GRIP_TAUNT
                });
            }

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                // Death Grip should not be castable while jumping/falling
                if (caster->HasUnitState(UNIT_STATE_JUMPING) || caster->HasUnitMovementFlag(MOVEMENTFLAG_FALLING))
                    return SPELL_FAILED_MOVING;

                return SPELL_CAST_OK;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_DK_DEATH_GRIP_DUMMY, true);
                GetHitUnit()->CastSpell(GetCaster(), SPELL_DK_DEATH_GRIP_JUMP, true);
                if (GetCaster()->HasAura(SPELL_DK_BLOOD))
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_DK_DEATH_GRIP_TAUNT, true);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_death_grip_initial_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_grip_initial_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_grip_initial_SpellScript();
        }
};

// 48743 - Death Pact
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
class spell_dk_death_strike : public SpellScriptLoader
{
    public:
        spell_dk_death_strike() : SpellScriptLoader("spell_dk_death_strike") { }

        class spell_dk_death_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_strike_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_DK_DEATH_STRIKE_HEAL,
                    SPELL_DK_BLOOD_SHIELD_MASTERY,
                    SPELL_DK_BLOOD_SHIELD_ABSORB,
                    SPELL_DK_RECENTLY_USED_DEATH_STRIKE,
                    SPELL_DK_FROST,
                    SPELL_DK_DEATH_STRIKE_OFFHAND
                });
            }

            void HandleHeal(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                //TODO: heal = std::min(10% health, 20% of all damage taken in last 5 seconds)
                int32 heal = CalculatePct(caster->GetMaxHealth(), GetSpellInfo()->GetEffect(EFFECT_4)->CalcValue());
                caster->CastCustomSpell(SPELL_DK_DEATH_STRIKE_HEAL, SPELLVALUE_BASE_POINT0, heal, caster, true);

                if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_DK_BLOOD_SHIELD_MASTERY, EFFECT_0))
                    caster->CastCustomSpell(SPELL_DK_BLOOD_SHIELD_ABSORB, SPELLVALUE_BASE_POINT0, CalculatePct(heal, aurEff->GetAmount()), caster);

                if (caster->HasAura(SPELL_DK_FROST))
                    caster->CastSpell(GetHitUnit(), SPELL_DK_DEATH_STRIKE_OFFHAND, true);
            }

            void TriggerRecentlyUsedDeathStrike()
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_DK_RECENTLY_USED_DEATH_STRIKE, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_strike_SpellScript::HandleHeal, EFFECT_1, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
                AfterCast += SpellCastFn(spell_dk_death_strike_SpellScript::TriggerRecentlyUsedDeathStrike);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_strike_SpellScript();
        }
};

// 85948 - Festering Strike
class spell_dk_festering_strike : public SpellScriptLoader
{
    public:
        spell_dk_festering_strike() : SpellScriptLoader("spell_dk_festering_strike") { }

        class spell_dk_festering_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_festering_strike_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_FESTERING_WOUND });
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastCustomSpell(SPELL_DK_FESTERING_WOUND, SPELLVALUE_AURA_STACK, GetEffectValue(), GetHitUnit(), TRIGGERED_FULL_MASK);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_festering_strike_SpellScript::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_DUMMY);
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
                return ValidateSpellInfo({ SPELL_DK_CORPSE_EXPLOSION_TRIGGERED });
            }

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                SetHitDamage(GetCaster()->CountPctFromMaxHealth(GetEffectInfo(EFFECT_2)->CalcValue(GetCaster())));
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
                OnEffectHitTarget += SpellEffectFn(spell_dk_ghoul_explode_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_dk_ghoul_explode_SpellScript::Suicide, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_ghoul_explode_SpellScript();
        }
};

// 206940 - Mark of Blood
class spell_dk_mark_of_blood : public SpellScriptLoader
{
    public:
        spell_dk_mark_of_blood() : SpellScriptLoader("spell_dk_mark_of_blood") { }

        class spell_dk_mark_of_blood_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_mark_of_blood_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_MARK_OF_BLOOD_HEAL });
            }

            void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                    caster->CastSpell(eventInfo.GetProcTarget(), SPELL_DK_MARK_OF_BLOOD_HEAL, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dk_mark_of_blood_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_mark_of_blood_AuraScript();
        }
};

// 207346 - Necrosis
class spell_dk_necrosis : public SpellScriptLoader
{
    public:
        spell_dk_necrosis() : SpellScriptLoader("spell_dk_necrosis") { }

        class spell_dk_necrosis_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_necrosis_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_NECROSIS_EFFECT });
            }

            void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_DK_NECROSIS_EFFECT, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dk_necrosis_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_necrosis_AuraScript();
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

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_GLYPH_OF_THE_GEIST });
            }

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

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_GLYPH_OF_THE_SKELETON });
            }

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

// 61257 - Runic Power Back on Snare/Root
/// 7.1.5
class spell_dk_pvp_4p_bonus : public SpellScriptLoader
{
    public:
        spell_dk_pvp_4p_bonus() : SpellScriptLoader("spell_dk_pvp_4p_bonus") { }

        class spell_dk_pvp_4p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_pvp_4p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_RUNIC_RETURN });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return false;

                return (spellInfo->GetAllEffectsMechanicMask() & ((1 << MECHANIC_ROOT) | (1 << MECHANIC_SNARE))) != 0;
            }

            void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActionTarget()->CastSpell(nullptr, SPELL_DK_RUNIC_RETURN, true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_dk_pvp_4p_bonus_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_dk_pvp_4p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_pvp_4p_bonus_AuraScript();
        }
};

// 46584 - Raise Dead
class spell_dk_raise_dead : public SpellScriptLoader
{
    public:
        spell_dk_raise_dead() : SpellScriptLoader("spell_dk_raise_dead") { }

        class spell_dk_raise_dead_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_raise_dead_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_RAISE_DEAD_SUMMON, SPELL_DK_SLUDGE_BELCHER, SPELL_DK_SLUDGE_BELCHER_SUMMON });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                uint32 spellId = SPELL_DK_RAISE_DEAD_SUMMON;
                if (GetCaster()->HasAura(SPELL_DK_SLUDGE_BELCHER))
                    spellId = SPELL_DK_SLUDGE_BELCHER_SUMMON;

                GetCaster()->CastSpell(nullptr, spellId, true);
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

// 115994 - Unholy Blight
class spell_dk_unholy_blight : public SpellScriptLoader
{
    public:
        spell_dk_unholy_blight() : SpellScriptLoader("spell_dk_unholy_blight") { }

        class spell_dk_unholy_blight_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_unholy_blight_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_FROST_FEVER, SPELL_DK_BLOOD_PLAGUE });
            }

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
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_vampiric_blood_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_HEALTH_2);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_vampiric_blood_AuraScript();
        }
};

void AddSC_deathknight_spell_scripts()
{
    new spell_dk_advantage_t10_4p();
    new spell_dk_anti_magic_shell();
    new spell_dk_army_transform();
    new spell_dk_blood_boil();
    new spell_dk_dancing_rune_weapon();
    new spell_dk_death_and_decay();
    new spell_dk_death_coil();
    new spell_dk_death_gate();
    new spell_dk_death_grip_initial();
    new spell_dk_death_pact();
    new spell_dk_death_strike();
    new spell_dk_festering_strike();
    new spell_dk_ghoul_explode();
    new spell_dk_mark_of_blood();
    new spell_dk_necrosis();
    new spell_dk_pet_geist_transform();
    new spell_dk_pet_skeleton_transform();
    new spell_dk_pvp_4p_bonus();
    new spell_dk_raise_dead();
    new spell_dk_unholy_blight();
    new spell_dk_vampiric_blood();
}
