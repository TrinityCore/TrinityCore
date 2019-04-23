/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Player.h"
#include "DynamicObject.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
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
    SPELL_DK_DEATH_GRIP                         = 49576,
    SPELL_DK_DEATH_GRIP_PULL                    = 49575,
    SPELL_DK_DEATH_GRIP_VISUAL                  = 55719,
    SPELL_DK_DEATH_GRIP_TAUNT                   = 57603,
    SPELL_DK_DEATH_STRIKE_HEAL                  = 45470,
    SPELL_DK_DECOMPOSING_AURA                   = 199720,
    SPELL_DK_DECOMPOSING_AURA_DAMAGE            = 199721,
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
    SPELL_DK_WILL_OF_THE_NECROPOLIS             = 206967,
    SPELL_DK_BLOOD_BOIL_TRIGGERED               = 65658,
    SPELL_DK_BLOOD_GORGED_HEAL                  = 50454,
    SPELL_DK_DEATH_STRIKE_ENABLER               = 89832,
    SPELL_DK_FROST_PRESENCE                     = 48266,
    SPELL_DK_IMPROVED_FROST_PRESENCE            = 50385,
    SPELL_DK_IMPROVED_FROST_PRESENCE_TRIGGERED  = 50385,
    SPELL_DK_IMPROVED_UNHOLY_PRESENCE           = 50392,
    SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED = 55222,
    SPELL_DK_RUNE_TAP                           = 48982,
    SPELL_DK_CORPSE_EXPLOSION_VISUAL            = 51270,
    SPELL_DK_MASTER_OF_GHOULS                   = 52143,
    SPELL_DK_GHOUL_AS_GUARDIAN                  = 46585,
    SPELL_DK_GHOUL_AS_PET                       = 52150,
    SPELL_DK_ROILING_BLOOD                      = 108170,
    SPELL_DK_PESTILENCE                         = 50842,
    SPELL_DK_CHILBLAINS                         = 50041,
    SPELL_DK_CHAINS_OF_ICE_ROOT                 = 53534,
    SPELL_DK_PLAGUE_LEECH                       = 123693,
    SPELL_DK_PERDITION                          = 123981,
    SPELL_DK_SHROUD_OF_PURGATORY                = 116888,
    SPELL_DK_PURGATORY_INSTAKILL                = 123982,
    SPELL_DK_BLOOD_RITES                        = 50034,
    SPELL_DK_DEATH_SIPHON_HEAL                  = 116783,
    SPELL_DK_BLOOD_CHARGE                       = 114851,
    SPELL_DK_BOOD_TAP                           = 45529,
    SPELL_DK_PILLAR_OF_FROST                    = 51271,
    SPELL_DK_CONVERSION                         = 119975,
    SPELL_DK_WEAKENED_BLOWS                     = 115798,
    SPELL_DK_SCARLET_FEVER                      = 81132,
    SPELL_DK_SCENT_OF_BLOOD_AURA                = 50421,
    SPELL_DK_DESECRATED_GROUND                  = 118009,
    SPELL_DK_DESECRATED_GROUND_IMMUNE           = 115018,
    SPELL_DK_ASPHYXIATE                         = 108194,
    SPELL_DK_DARK_INFUSION_STACKS               = 91342,
    SPELL_DK_DARK_INFUSION_AURA                 = 93426,
    SPELL_DK_RUNIC_CORRUPTION_REGEN             = 51460,
    SPELL_DK_RUNIC_EMPOWERMENT                  = 81229,
    SPELL_DK_GOREFIENDS_GRASP_GRIP_VISUAL       = 114869,
    SPELL_DK_SLUDGE_BELCHER_AURA                = 207313,
    SPELL_DK_SLUDGE_BELCHER_ABOMINATION         = 212027,
    SPELL_DK_RAISE_DEAD                         = 46584,
    SPELL_DK_RAISE_DEAD_GHOUL                   = 52150,
    SPELL_DK_GEIST_TRANSFORM                    = 121916,
    SPELL_DK_ANTI_MAGIC_BARRIER                 = 205725,
    SPELL_DK_RUNIC_CORRUPTION                   = 51462,
    SPELL_DK_NECROSIS                           = 207346,
    SPELL_DK_NECROSIS_EFFECT                    = 216974,
    SPELL_DK_ALL_WILL_SERVE                     = 194916,
    SPELL_DK_ALL_WILL_SERVE_SUMMON              = 196910,
    SPELL_DK_BREATH_OF_SINDRAGOSA               = 152279,
    SPELL_DK_DEATH_GRIP_ONLY_JUMP               = 146599,
    SPELL_DK_HEART_STRIKE                       = 206930,
    SPELL_DK_FESTERING_WOUND                    = 194310,
    SPELL_DK_FESTERING_WOUND_DAMAGE             = 194311,
    SPELL_DK_BONE_SHIELD                        = 195181,
    SPELL_DK_BLOOD_MIRROR_DAMAGE                = 221847,
    SPELL_DK_BLOOD_MIRROR                       = 206977,
    SPELL_DK_BONESTORM_HEAL                     = 196545,
    SPELL_DK_GLACIAL_ADVANCE                    = 194913,
    SPELL_DK_GLACIAL_ADVANCE_DAMAGE             = 195975,
    SPELL_DK_HOWLING_BLAST                      = 49184,
    SPELL_DK_HOWLING_BLAST_AOE                  = 237680,
    SPELL_DK_RIME_BUFF                          = 59052,
    SPELL_DK_NORTHREND_WINDS                    = 204088,
    SPELL_DK_KILLING_MACHINE                    = 51124,
    SPELL_DK_REMORSELESS_WINTER_SLOW_DOWN       = 211793,
    SPELL_DK_EPIDEMIC                           = 207317,
    SPELL_DK_EPIDEMIC_DAMAGE_SINGLE             = 212739,
    SPELL_DK_EPIDEMIC_DAMAGE_AOE                = 215969,
    SPELL_DK_VIRULENT_PLAGUE                    = 191587,
    SPELL_DK_VIRULENT_ERUPTION                  = 191685,
    SPELL_DK_OUTBREAK_PERIODIC                  = 196782,
    SPELL_DK_DEFILE                             = 152280,
    SPELL_DK_DEFILE_DAMAGE                      = 156000,
    SPELL_DK_DEFILE_DUMMY                       = 156004,
    SPELL_DK_DEFILE_MASTERY                     = 218100,
    SPELL_DK_UNHOLY_FRENZY                      = 207289,
    SPELL_DK_UNHOLY_FRENZY_BUFF                 = 207290,
    SPELL_DK_PESTILENT_PUSTULES                 = 194917,
    SPELL_DK_CASTIGATOR                         = 207305,
    SPELL_DK_UNHOLY_VIGOR                       = 196263,
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
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_RUNIC_POWER_ENERGIZE))
                    return false;
                return true;
            }

            bool Load() override
            {
                absorbPct = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue(GetCaster());
                maxHealth = (int32)GetCaster()->GetMaxHealth();
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
                        player->GetSpellHistory()->ModifyCooldown(GetId(), -int32(player->GetSpellHistory()->GetRemainingCooldown(GetSpellInfo()) * val / 100));
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

        class spell_dk_anti_magic_shell_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_anti_magic_shell_SpellScript);

            void HandleOnCast()
            {
                Unit* caster = GetCaster();

                if (caster->HasSpell(205727))
                    caster->CastSpell(caster, SPELL_DK_ANTI_MAGIC_BARRIER, true);
            }

            void Register() override
            {
                OnCast += SpellCastFn(spell_dk_anti_magic_shell_SpellScript::HandleOnCast);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_anti_magic_shell_AuraScript();
        }

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_anti_magic_shell_SpellScript();
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
class spell_dk_blood_boil : public SpellScriptLoader
{
    public:
        spell_dk_blood_boil() : SpellScriptLoader("spell_dk_blood_boil") { }

        class spell_dk_blood_boil_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_blood_boil_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_PLAGUE))
                    return false;
                return true;
            }

            void HandleOnHit(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();

                caster->CastSpell(target, SPELL_DK_BLOOD_PLAGUE, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_blood_boil_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
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

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_and_decay_SpellScript();
        }

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_death_and_decay_AuraScript();
        }
};

// 47541 - Death Coil
class spell_dk_death_coil : public SpellScript
{
    PrepareSpellScript(spell_dk_death_coil);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_DEATH_COIL_DAMAGE, SPELL_DK_UNHOLY_VIGOR });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* target = GetHitUnit())
        {
            caster->CastSpell(target, SPELL_DK_DEATH_COIL_DAMAGE, true);
            caster->CastSpell(nullptr, SPELL_DK_UNHOLY_VIGOR, true);

            if (caster->HasAura(SPELL_DK_NECROSIS))
                caster->CastSpell(caster, SPELL_DK_NECROSIS_EFFECT, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_death_coil::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
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
                Unit* target = GetHitUnit();
                if (!target)
                    return;

                if (Player* player = target->ToPlayer())
                {
                    if (player->getLevel() < 98)
                        player->CastSpell(player, GetEffectValue(), true);
                    else
                        player->TeleportTo(1220, -1503.367f, 1052.059f, 260.396f, player->GetOrientation());
                }
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
                int64 heal = caster->GetTotalAttackPowerValue(BASE_ATTACK) * 4; /// todo, add versatality bonus as it will probably not apply to the heal due to its damageclass SPELL_DAMAGE_CLASS_NONE.
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
class spell_dk_festering_strike : public SpellScript
{
    PrepareSpellScript(spell_dk_festering_strike);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_FESTERING_WOUND });
    }

    void HandleFesteringWounds(SpellEffIndex effIndex)
    {
        if (Unit* target = GetHitUnit())
        {
            uint32 amount = GetSpellInfo()->GetEffect(effIndex)->CalcValue();

            if (Aura* castiragorAura = GetCaster()->GetAura(SPELL_DK_CASTIGATOR))
                amount += castiragorAura->GetSpellEffectInfo(EFFECT_0)->BasePoints;

            for (uint8 i = 0; i < amount; ++i)
                GetCaster()->CastSpell(target, SPELL_DK_FESTERING_WOUND, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_festering_strike::HandleFesteringWounds, EFFECT_2, SPELL_EFFECT_DUMMY);
    }
};

// 47496 - Explode, Ghoul spell for Corpse Explosion
class spell_dk_ghoul_explode : public SpellScript
{
    PrepareSpellScript(spell_dk_ghoul_explode);

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
        // Corpse Explosion (Suicide)
        if (Unit* unitTarget = GetHitUnit())
            unitTarget->CastSpell(unitTarget, SPELL_DK_CORPSE_EXPLOSION_TRIGGERED, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_ghoul_explode::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectHitTarget += SpellEffectFn(spell_dk_ghoul_explode::Suicide, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
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
                Unit* actionTarget = eventInfo.GetActionTarget();
                return actionTarget && actionTarget->GetCreatureType() == CREATURE_TYPE_UNDEAD && actionTarget->GetOwner();
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

            bool Load() override
            {
                return GetUnitOwner()->getClass() == CLASS_DEATH_KNIGHT;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetSpellInfo() && (eventInfo.GetSpellInfo()->GetAllEffectsMechanicMask() & (1 << MECHANIC_SNARE | 1 << MECHANIC_ROOT | 1 << MECHANIC_FREEZE));
            }

            void HandleProc(ProcEventInfo& eventInfo)
            {
                if (Unit* target = eventInfo.GetProcTarget())
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
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_RAISE_DEAD)||
                    !sSpellMgr->GetSpellInfo(SPELL_DK_SLUDGE_BELCHER_ABOMINATION)||
                    !sSpellMgr->GetSpellInfo(SPELL_DK_SLUDGE_BELCHER_AURA)||
                    !sSpellMgr->GetSpellInfo(SPELL_DK_RAISE_DEAD_GHOUL))
                    return false;
                return true;
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleDummy()
            {
                Unit* caster = GetCaster();

                if (caster->HasAura(SPELL_DK_SLUDGE_BELCHER_AURA))
                    caster->CastSpell((Unit*)nullptr, SPELL_DK_SLUDGE_BELCHER_ABOMINATION, true);
                else
                {
                    caster->CastSpell((Unit*)nullptr, SPELL_DK_RAISE_DEAD_GHOUL, true);
                    if (caster->HasAura(58640)) //Glyph of the Geist
                    {
                        if (Guardian* pet = caster->ToPlayer()->GetGuardianPet())
                            pet->CastSpell(pet, SPELL_DK_GEIST_TRANSFORM, true);
                    }
                }

                if (caster->HasAura(SPELL_DK_ALL_WILL_SERVE))
                {
                    caster->CastSpell(caster, SPELL_DK_ALL_WILL_SERVE_SUMMON, true);
                }
            }

            void Register() override
            {
                OnCast += SpellCastFn(spell_dk_raise_dead_SpellScript::HandleDummy);
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

// 206967 - Will of the Necropolis
class spell_dk_will_of_the_necropolis : public AuraScript
{
    PrepareAuraScript(spell_dk_will_of_the_necropolis);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return spellInfo->GetEffect(EFFECT_0) && spellInfo->GetEffect(EFFECT_1) && spellInfo->GetEffect(EFFECT_2);
    }

    void CalculateAmount(AuraEffect const* /*p_AuraEffect*/, int32& p_Amount, bool& /*p_CanBeRecalculated*/)
    {
        p_Amount = -1;
    }

    void Absorb(AuraEffect* /*auraEffect*/, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        absorbAmount = 0;

        if (GetTarget()->GetHealthPct() < GetEffect(EFFECT_2)->GetBaseAmount())
            absorbAmount = CalculatePct(dmgInfo.GetDamage(), GetEffect(EFFECT_1)->GetBaseAmount());
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_will_of_the_necropolis::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_will_of_the_necropolis::Absorb, EFFECT_0);
    }
};

// 49576 - Death Grip
class spell_dk_death_grip_initial : public SpellScript
{
    PrepareSpellScript(spell_dk_death_grip_initial);

    bool Validate(SpellInfo const* /*spellinfo*/) override
    {
        return ValidateSpellInfo({  SPELL_DK_DEATH_GRIP,
                                    SPELL_DK_DEATH_GRIP_PULL,
                                    SPELL_DK_DEATH_GRIP_VISUAL,
                                    SPELL_DK_DEATH_GRIP_TAUNT });
    }

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();

        // Death Grip should not be castable while jumping/falling
        if (caster->HasUnitState(UNIT_STATE_JUMPING) || caster->HasUnitMovementFlag(MOVEMENTFLAG_FALLING))
            return SPELL_FAILED_MOVING;

        // Patch 3.3.3 (2010-03-23): Minimum range has been changed to 8 yards in PvP.
        Unit* target = GetExplTargetUnit();
        if (target && target->IsPlayer())
            if (caster->GetDistance(target) < 8.f)
                return SPELL_FAILED_TOO_CLOSE;

        return SPELL_CAST_OK;
    }

    void HandleOnCast()
    {
        Unit* caster = GetCaster();
        Unit* target = GetExplTargetUnit();

        if (!target->HasAuraType(SPELL_AURA_DEFLECT_SPELLS))
        {
            caster->CastSpell(target, SPELL_DK_DEATH_GRIP_VISUAL, true);
            target->CastSpell(caster, SPELL_DK_DEATH_GRIP_PULL, true);

            if (caster->IsPlayer() && caster->ToPlayer()->GetSpecializationId() == TALENT_SPEC_DEATHKNIGHT_BLOOD)
                caster->CastSpell(target, SPELL_DK_DEATH_GRIP_TAUNT, true);
        }
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dk_death_grip_initial::CheckCast);
        OnCast += SpellCastFn(spell_dk_death_grip_initial::HandleOnCast);
    }
};

// Dark transformation - transform pet spell - 63560
class spell_dk_dark_transformation_form : public SpellScriptLoader
{
public:
    spell_dk_dark_transformation_form() : SpellScriptLoader("spell_dk_dark_transformation_form") { }

    class spell_dk_dark_transformation_form_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_dark_transformation_form_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* pet = GetHitUnit())
                {
                    if (pet->HasAura(SPELL_DK_DARK_INFUSION_STACKS))
                    {
                        _player->RemoveAura(SPELL_DK_DARK_INFUSION_STACKS);
                        pet->RemoveAura(SPELL_DK_DARK_INFUSION_STACKS);
                    }
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_dk_dark_transformation_form_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_dark_transformation_form_SpellScript();
    }
};


// Desecrated ground - 118009
class spell_dk_desecrated_ground : public SpellScriptLoader
{
public:
    spell_dk_desecrated_ground() : SpellScriptLoader("spell_dk_desecrated_ground") { }

    class spell_dk_desecrated_ground_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_desecrated_ground_AuraScript);

        void OnTick(AuraEffect const* /* aurEff */)
        {
            if (GetCaster())
                if (DynamicObject* dynObj = GetCaster()->GetDynObject(SPELL_DK_DESECRATED_GROUND))
                    if (GetCaster()->GetDistance(dynObj) <= 8.0f)
                        GetCaster()->CastSpell(GetCaster(), SPELL_DK_DESECRATED_GROUND_IMMUNE, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dk_desecrated_ground_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_desecrated_ground_AuraScript();
    }
};

// Howling Blast - 49184
class spell_dk_howling_blast : public SpellScript
{
    PrepareSpellScript(spell_dk_howling_blast);

    ObjectGuid tar;

    void HandleBeforeCast()
    {
        if (Unit* target = GetExplTargetUnit())
            tar = target->GetGUID();
    }

    void HandleOnHit()
    {
        Unit* target = GetHitUnit();
        Unit* caster = GetCaster();

        if (!caster || !target || !tar)
            return;

        if (target->GetGUID() != tar)
            if (const SpellInfo* info = GetSpellInfo())
                SetHitDamage(int32(GetHitDamage()*info->GetEffect(EFFECT_0)->BasePoints / 100));

        caster->CastSpell(target, SPELL_DK_FROST_FEVER, true);

        if (!caster->HasAura(SPELL_DK_NORTHREND_WINDS))
            caster->CastSpell(target, SPELL_DK_HOWLING_BLAST_AOE, true);

        if (caster->HasAura(SPELL_DK_RIME_BUFF))
            caster->RemoveAura(SPELL_DK_RIME_BUFF);
    }

    void Register() override
    {
        BeforeCast += SpellCastFn(spell_dk_howling_blast::HandleBeforeCast);
        OnHit += SpellHitFn(spell_dk_howling_blast::HandleOnHit);
    }
};

// Howling Blast AOE - 237680
class spell_dk_howling_blast_aoe : public SpellScript
{
    PrepareSpellScript(spell_dk_howling_blast_aoe);

    ObjectGuid tar;

    void HandleBeforeCast()
    {
        tar = GetOrigUnitTargetGUID();
    }

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
			if (target->GetGUID() == tar)
				PreventHitDamage();
			else
			{
				Unit* caster = GetCaster();
				if (caster)
					caster->CastSpell(target, SPELL_DK_FROST_FEVER, true);
			}
        }
    }

    void Register() override
    {
        BeforeCast += SpellCastFn(spell_dk_howling_blast_aoe::HandleBeforeCast);
        OnEffectHitTarget += SpellEffectFn(spell_dk_howling_blast_aoe::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Remorseless Winter - 196771
class spell_dk_remorseless_winter_damage : public SpellScript
{
    PrepareSpellScript(spell_dk_remorseless_winter_damage);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* unit = GetHitUnit())
            GetCaster()->CastSpell(unit, SPELL_DK_REMORSELESS_WINTER_SLOW_DOWN, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_remorseless_winter_damage::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Pillar of Frost - 51271
class spell_dk_pillar_of_frost : public SpellScriptLoader
{
public:
    spell_dk_pillar_of_frost() : SpellScriptLoader("spell_dk_pillar_of_frost") { }

    class spell_dk_pillar_of_frost_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_pillar_of_frost_AuraScript);

        void OnRemove(AuraEffect const*  /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Player* _player = GetTarget()->ToPlayer())
                _player->ApplySpellImmune(SPELL_DK_PILLAR_OF_FROST, IMMUNITY_MECHANIC, MECHANIC_KNOCKOUT, false);
        }

        void OnApply(AuraEffect const*  /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Player* _player = GetTarget()->ToPlayer())
                _player->ApplySpellImmune(SPELL_DK_PILLAR_OF_FROST, IMMUNITY_MECHANIC, MECHANIC_KNOCKOUT, true);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_dk_pillar_of_frost_AuraScript::OnApply, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_dk_pillar_of_frost_AuraScript::OnRemove, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_pillar_of_frost_AuraScript();
    }
};


// Called by Death Coil - 47541, Rune Strike - 56815 and Frost Strike - 49143
// Blood Charges - 114851 for Blood Tap - 45529
class spell_dk_blood_charges : public SpellScriptLoader
{
public:
    spell_dk_blood_charges() : SpellScriptLoader("spell_dk_blood_charges") { }

    class spell_dk_blood_charges_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_blood_charges_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return sSpellMgr->GetSpellInfo(SPELL_DK_BOOD_TAP) && sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_CHARGE);
        }

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (GetHitUnit())
                {
                    if (_player->HasSpell(SPELL_DK_BOOD_TAP))
                    {
                        _player->CastSpell(_player, SPELL_DK_BLOOD_CHARGE, true);
                        _player->CastSpell(_player, SPELL_DK_BLOOD_CHARGE, true);
                    }
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_dk_blood_charges_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_blood_charges_SpellScript();
    }
};

// Death Siphon - 108196
class spell_dk_death_siphon : public SpellScriptLoader
{
public:
    spell_dk_death_siphon() : SpellScriptLoader("spell_dk_death_siphon") { }

    class spell_dk_death_siphon_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_death_siphon_SpellScript);

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (GetHitUnit())
                {
                    int32 bp = GetHitDamage();
                    _player->CastCustomSpell(_player, SPELL_DK_DEATH_SIPHON_HEAL, &bp, NULL, NULL, true);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dk_death_siphon_SpellScript::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_death_siphon_SpellScript();
    }
};

// Purgatory - 116888
class spell_dk_purgatory : public SpellScriptLoader
{
public:
    spell_dk_purgatory() : SpellScriptLoader("spell_dk_purgatory") { }

    class spell_dk_purgatory_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_purgatory_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Player* _player = GetTarget()->ToPlayer())
            {
                AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                if (removeMode == AURA_REMOVE_BY_EXPIRE)
                    _player->CastSpell(_player, SPELL_DK_PURGATORY_INSTAKILL, true);
            }
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_dk_purgatory_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_purgatory_AuraScript();
    }
};


// Purgatory - 114556
class spell_dk_purgatory_absorb : public SpellScriptLoader
{
public:
    spell_dk_purgatory_absorb() : SpellScriptLoader("spell_dk_purgatory_absorb") { }

    class spell_dk_purgatory_absorb_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_purgatory_absorb_AuraScript);

        void CalculateAmount(AuraEffect const* /*auraEffect*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void Absorb(AuraEffect* /*auraEffect*/, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            Unit* target = GetTarget();

            if (dmgInfo.GetDamage() < target->GetHealth())
                return;

            // No damage received under Shroud of Purgatory
            if (target->ToPlayer()->HasAura(SPELL_DK_SHROUD_OF_PURGATORY))
            {
                absorbAmount = dmgInfo.GetDamage();
                return;
            }

            if (target->ToPlayer()->HasAura(SPELL_DK_PERDITION))
                return;

            int32 bp = dmgInfo.GetDamage();

            target->CastCustomSpell(target, SPELL_DK_SHROUD_OF_PURGATORY, &bp, NULL, NULL, true);
            target->CastSpell(target, SPELL_DK_PERDITION, true);
            target->SetHealth(1);
            absorbAmount = dmgInfo.GetDamage();
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_purgatory_absorb_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_purgatory_absorb_AuraScript::Absorb, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_purgatory_absorb_AuraScript();
    }
};

// Called by Chains of Ice - 45524
// Chilblains - 50041
class spell_dk_chilblains : public SpellScriptLoader
{
public:
    spell_dk_chilblains() : SpellScriptLoader("spell_dk_chilblains") { }

    class spell_dk_chilblains_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_chilblains_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
                if (Unit* target = GetHitUnit())
                    if (_player->HasAura(SPELL_DK_CHILBLAINS))
                        _player->CastSpell(target, SPELL_DK_CHAINS_OF_ICE_ROOT, true);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_dk_chilblains_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_chilblains_SpellScript();
    }
};

// Outbreak - 77575
class spell_dk_outbreak : public SpellScript
{
    PrepareSpellScript(spell_dk_outbreak);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            if (!target->HasAura(SPELL_DK_OUTBREAK_PERIODIC, GetCaster()->GetGUID()))
                GetCaster()->CastSpell(target, SPELL_DK_OUTBREAK_PERIODIC, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_outbreak::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Outbreak - 196782
class aura_dk_outbreak_periodic : public AuraScript
{
    PrepareAuraScript(aura_dk_outbreak_periodic);

    void HandleDummyTick(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
        {
            std::list<Unit*> friendlyUnits;
            GetTarget()->GetFriendlyUnitListInRange(friendlyUnits, 10.f);

            for (Unit* unit : friendlyUnits)
                caster->CastSpell(unit, SPELL_DK_VIRULENT_PLAGUE, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_dk_outbreak_periodic::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 48707 - Anti-Magic Shell (on self)
class spell_dk_anti_magic_shell_self : public SpellScriptLoader
{
public:
    spell_dk_anti_magic_shell_self() : SpellScriptLoader("spell_dk_anti_magic_shell_self") { }

    class spell_dk_anti_magic_shell_self_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_anti_magic_shell_self_AuraScript);

        uint32 absorbPct;
        bool Load() override
        {
            absorbPct = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue(GetCaster());
            return true;
        }

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool & /*canBeRecalculated*/)
        {
            amount = GetUnitOwner()->CountPctFromMaxHealth(40);
        }

        void Absorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
        }

        void Trigger(AuraEffect* aurEff, DamageInfo& /*dmgInfo*/, uint32& absorbAmount)
        {
            Unit* target = GetTarget();
            // Patch 6.0.2 (October 14, 2014): Anti-Magic Shell now restores 2 Runic Power per 1% of max health absorbed.
            float damagePerRp = target->CountPctFromMaxHealth(1) / 2.0f;
            int32 energizeAmount = (absorbAmount / damagePerRp) * 10.0f;
            target->CastCustomSpell(target, SPELL_DK_RUNIC_POWER_ENERGIZE, &energizeAmount, NULL, NULL, true, NULL, aurEff);
        }

        void Register() override
        {
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_shell_self_AuraScript::Absorb, EFFECT_0);
            AfterEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_shell_self_AuraScript::Trigger, EFFECT_0);
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_anti_magic_shell_self_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_anti_magic_shell_self_AuraScript();
    }
};

// Plague Leech
class spell_dk_plague_leech : public SpellScriptLoader
{
public:
    spell_dk_plague_leech() : SpellScriptLoader("spell_dk_plague_leech") {}

    class spell_dk_plague_leech_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_plague_leech_SpellScript);

        SpellCastResult CheckClass()
        {
            if (Unit* target = GetExplTargetUnit())
            {
                uint8 diseases = target->GetDiseasesByCaster(GetCaster()->GetGUID());
                uint8 requiredDiseases = GetCaster()->HasAura(152281) ? 1 : 2;
                if (diseases < requiredDiseases)
                {
                    //SetCustomCastResultMessage(159);
                    return SPELL_FAILED_CUSTOM_ERROR;
                }
            }

            return SPELL_CAST_OK;
        }

        void HandleOnHit()
        {
            Player* player = GetCaster()->ToPlayer();
            if (!player)
                return;

            std::vector<uint8> runes;
            for (uint8 i = 0; i < MAX_RUNES; ++i)
                if (player->GetRuneCooldown(i) == player->GetRuneBaseCooldown())
                    runes.push_back(i);

            if (!runes.empty())
            {
                for (uint8 i = 0; i < 2 && !runes.empty(); i++)
                {
                    std::vector<uint8>::iterator itr = runes.begin();
                    std::advance(itr, urand(0, runes.size() - 1));
                    uint32 runesState = player->GetRunesState();
                    player->SetRuneCooldown((*itr), 0);
                    if ((player->GetRunesState() & ~runesState) != 0)
                        player->AddRunePower((player->GetRunesState() & ~runesState));

                    runes.erase(itr);
                }

                GetHitUnit()->GetDiseasesByCaster(GetCaster()->GetGUID(), true);
            }
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_dk_plague_leech_SpellScript::CheckClass);
            OnHit += SpellHitFn(spell_dk_plague_leech_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_plague_leech_SpellScript();
    }
};

// 50453 - Bloodworms Health Leech
class spell_dk_blood_gorged : public SpellScriptLoader
{
public:
    spell_dk_blood_gorged() : SpellScriptLoader("spell_dk_blood_gorged") { }

    class spell_dk_blood_gorged_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_blood_gorged_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_GORGED_HEAL))
                return false;
            return true;
        }

        bool Load() override
        {
            _procTarget = NULL;
            return true;
        }

        bool CheckProc(ProcEventInfo& /*eventInfo*/)
        {
            _procTarget = GetTarget()->GetOwner();
            return _procTarget != nullptr;
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            int32 heal = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), 150));
            GetTarget()->CastCustomSpell(SPELL_DK_BLOOD_GORGED_HEAL, SPELLVALUE_BASE_POINT0, heal, _procTarget, true, NULL, aurEff);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dk_blood_gorged_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dk_blood_gorged_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }

    private:
        Unit* _procTarget;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_blood_gorged_AuraScript();
    }
};

// 48266 - Blood Presence
// 48263 - Frost Presence
// 48265 - Unholy Presence
class spell_dk_presence : public SpellScriptLoader
{
public:
    spell_dk_presence() : SpellScriptLoader("spell_dk_presence") { }

    class spell_dk_presence_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_presence_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DK_FROST_PRESENCE)
                || !sSpellMgr->GetSpellInfo(SPELL_DK_UNHOLY_PRESENCE)
                || !sSpellMgr->GetSpellInfo(SPELL_DK_IMPROVED_FROST_PRESENCE)
                || !sSpellMgr->GetSpellInfo(SPELL_DK_IMPROVED_UNHOLY_PRESENCE)
                || !sSpellMgr->GetSpellInfo(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED)
                || !sSpellMgr->GetSpellInfo(SPELL_DK_IMPROVED_FROST_PRESENCE_TRIGGERED))
                return false;

            return true;
        }

        void HandleImprovedFrostPresence(AuraEffect const* /* aurEff */, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            if (AuraEffect * impAurEff = target->GetAuraEffect(SPELL_DK_IMPROVED_FROST_PRESENCE, EFFECT_0))
                impAurEff->SetAmount(impAurEff->CalculateAmount(GetCaster()));
        }

        void HandleImprovedUnholyPresence(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            if (AuraEffect const* impAurEff = target->GetAuraEffect(SPELL_DK_IMPROVED_UNHOLY_PRESENCE, EFFECT_0))
                if (!target->HasAura(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED))
                    target->CastCustomSpell(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED, SPELLVALUE_BASE_POINT0, impAurEff->GetAmount(), target, true, NULL, aurEff);
        }

        void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            if (AuraEffect * impAurEff = target->GetAuraEffect(SPELL_DK_IMPROVED_FROST_PRESENCE, EFFECT_0))
                impAurEff->SetAmount(0);
            target->RemoveAura(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED);
        }

        void Register() override
        {
            if (m_scriptSpellId == SPELL_DK_FROST_PRESENCE)
                AfterEffectApply += AuraEffectApplyFn(spell_dk_presence_AuraScript::HandleImprovedFrostPresence, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
            if (m_scriptSpellId == SPELL_DK_UNHOLY_PRESENCE)
                AfterEffectApply += AuraEffectApplyFn(spell_dk_presence_AuraScript::HandleImprovedUnholyPresence, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);

            AfterEffectRemove += AuraEffectRemoveFn(spell_dk_presence_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_presence_AuraScript();
    }

    class spell_dk_presence_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_presence_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DK_SCOURGE_STRIKE_TRIGGERED))
                return false;
            return true;
        }

        void HandleAfterHit()
        {
            Unit* caster = GetCaster();
            if (GetHitUnit())
            {
                uint32 runicPower = caster->GetPower(POWER_RUNIC_POWER);
                if (AuraEffect* aurEff = caster->GetAuraEffect(58647, EFFECT_0))
                    runicPower = CalculatePct(runicPower, aurEff->GetAmount());
                else
                    runicPower = 0;

                caster->SetPower(POWER_RUNIC_POWER, runicPower);
            }
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_dk_presence_SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_presence_SpellScript();
    }
};

// Chains of Ice
class spell_dk_chains_of_ice : public SpellScriptLoader
{
public:
    spell_dk_chains_of_ice() : SpellScriptLoader("spell_dk_chains_of_ice") { }

    class spell_dk_chains_of_ice_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_chains_of_ice_SpellScript);

        void HandleOnHit()
        {
            Unit* caster = GetCaster();
            if (Unit* target = GetHitUnit())
            {
                if (caster->HasAura(152281))
                    caster->CastSpell(target, 155159, true);
                else
                    caster->CastSpell(target, 55095, true);
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_dk_chains_of_ice_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_chains_of_ice_SpellScript();
    }
};


// Icy touch
class spell_dk_icy_touch : public SpellScriptLoader
{
public:
    spell_dk_icy_touch() : SpellScriptLoader("spell_dk_icy_touch") { }

    class spell_dk_icy_touch_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_icy_touch_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (Unit* target = GetHitUnit())
            {
                if (caster->HasAura(152281))
                    caster->CastSpell(target, 155159, true);
                else
                    caster->CastSpell(target, 55095, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dk_icy_touch_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_icy_touch_SpellScript();
    }
};

// Plague Strike
class spell_dk_plague_strike : public SpellScriptLoader
{
public:
    spell_dk_plague_strike() : SpellScriptLoader("spell_dk_plague_strike") { }

    class spell_dk_plague_strike_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_plague_strike_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (Unit* target = GetHitUnit())
            {
                if (caster->HasAura(152281))
                    caster->CastSpell(target, 155159, true);
                else
                {
                    caster->CastSpell(target, 55078, true);
                    if (caster->HasAura(51160))
                        caster->CastSpell(target, 55095, true);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dk_plague_strike_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_plague_strike_SpellScript();
    }
};

// Anti-Magic Barrier - 205725
class spell_dk_anti_magic_barrier : public SpellScriptLoader
{
public:
    spell_dk_anti_magic_barrier() : SpellScriptLoader("spell_dk_anti_magic_barrier") { }

    class spell_dk_anti_magic_barrier_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_anti_magic_barrier_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DK_ANTI_MAGIC_BARRIER))
                return false;
            return true;
        }

        void CalcAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
        {
            if (Unit* caster = GetCaster())
                amount = int32((caster->GetMaxHealth()*25.0f) / 100.0f);

            aurEff->GetCaster()->DealDamage(aurEff->GetCaster(), 6969); //debug
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_anti_magic_barrier_AuraScript::CalcAmount, EFFECT_0, SPELL_AURA_MOD_INCREASE_HEALTH_2);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_anti_magic_barrier_AuraScript();
    }
};

// Breath of Sindragosa - 152279
class spell_dk_breath_of_sindragosa : public SpellScriptLoader
{
public:
    spell_dk_breath_of_sindragosa() : SpellScriptLoader("spell_dk_breath_of_sindragosa") { }

    class spell_dk_breath_of_sindragosa_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_breath_of_sindragosa_AuraScript);

        void OnTick(AuraEffect const* /*p_AurEff*/)
        {
            Unit* l_Caster = GetCaster();
            if (l_Caster == nullptr)
                return;

            Player* l_Player = l_Caster->ToPlayer();
            if (l_Player == nullptr)
                return;

            l_Caster->ModifyPower(POWER_RUNIC_POWER, -130);
            if (l_Caster->ToPlayer())
                l_Caster->ToPlayer()->SendPowerUpdate(POWER_RUNIC_POWER, l_Caster->GetPower(POWER_RUNIC_POWER));

            if (l_Caster->GetPower(POWER_RUNIC_POWER) <= 130)
                l_Caster->RemoveAura(SPELL_DK_BREATH_OF_SINDRAGOSA);

        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dk_breath_of_sindragosa_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_breath_of_sindragosa_AuraScript();
    }
};

//47568 - Empower rune weapon
class spell_dk_empower_rune_weapon : public SpellScriptLoader
{
public:
    spell_dk_empower_rune_weapon() : SpellScriptLoader("spell_dk_empower_rune_weapon") { }

    class spell_dk_empower_rune_weapon_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_empower_rune_weapon_SpellScript);

        void OnHitTarget(SpellEffIndex /*eff*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Player* player = caster->ToPlayer())
                {
                    for (int i = 0; i < MAX_RUNES; ++i)
                        player->SetRuneCooldown(i, 0);
                    player->ResyncRunes();
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dk_empower_rune_weapon_SpellScript::OnHitTarget, EFFECT_0, SPELL_EFFECT_ENERGIZE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_empower_rune_weapon_SpellScript();
    }
};

// Runic Empowerment - 81229
class spell_dk_runic_empowerment : public PlayerScript
{
public:
    spell_dk_runic_empowerment() : PlayerScript("spell_dk_runic_empowerment") {}

    enum eSpells
    {
        RunicEmpowerment = 81229,
    };

    void OnModifyPower(Player * p_Player, Powers p_Power, int32 p_OldValue, int32& p_NewValue, bool p_Regen, bool p_After)
    {
        if (p_After)
            return;

        if (p_Player->getClass() != CLASS_DEATH_KNIGHT || p_Power != POWER_RUNIC_POWER || p_Regen || p_NewValue > p_OldValue)
            return;

        if (AuraEffect* l_RunicEmpowerment = p_Player->GetAuraEffect(eSpells::RunicEmpowerment, EFFECT_0))
        {
            /// 1.00% chance per Runic Power spent
            float l_Chance = (l_RunicEmpowerment->GetAmount() / 100.0f);

            if (roll_chance_f(l_Chance))
            {
                std::list<uint8> l_LstRunesUsed;

                for (uint8 i = 0; i < MAX_RUNES; ++i)
                {
                    if (p_Player->GetRuneCooldown(i))
                        l_LstRunesUsed.push_back(i);
                }

                if (l_LstRunesUsed.empty())
                    return;

                uint8 l_RuneRandom = Trinity::Containers::SelectRandomContainerElement(l_LstRunesUsed);

                p_Player->SetRuneCooldown(l_RuneRandom, 0);
                p_Player->ResyncRunes();
            }
        }
    }
};

// Gorefiend's Grasp - 108199
class spell_dk_gorefiends_grasp : public SpellScriptLoader
{
public:
    spell_dk_gorefiends_grasp() : SpellScriptLoader("spell_dk_gorefiends_grasp") { }

    class spell_dk_gorefiends_grasp_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_gorefiends_grasp_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    std::list<Unit*> tempList;
                    std::list<Unit*> gripList;

                    _player->GetAttackableUnitListInRange(tempList, 20.0f);

                    for (auto itr : tempList)
                    {
                        if (itr->GetGUID() == _player->GetGUID())
                            continue;

                        if (!_player->IsValidAttackTarget(itr))
                            continue;

                        if (itr->IsImmunedToSpell(GetSpellInfo(), GetCaster()))
                            continue;

                        if (!itr->IsWithinLOSInMap(_player))
                            continue;

                        gripList.push_back(itr);
                    }

                    for (auto itr : gripList)
                    {
                        itr->CastSpell(target, SPELL_DK_DEATH_GRIP_ONLY_JUMP, true);
                        itr->CastSpell(target, SPELL_DK_GOREFIENDS_GRASP_GRIP_VISUAL, true);
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dk_gorefiends_grasp_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_gorefiends_grasp_SpellScript();
    }
};

//55233 Vampiric Blood
class spell_dk_vampiric_blood : public SpellScriptLoader
{
public:
    spell_dk_vampiric_blood() : SpellScriptLoader("spell_dk_vampiric_blood") { }

    class spell_dk_vampiric_blood_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_vampiric_blood_AuraScript);

        void CalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            amount *= caster->GetMaxHealth() / 100;
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_vampiric_blood_AuraScript::CalcAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_HEALTH_2);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_vampiric_blood_AuraScript();
    }
};

//195181 - Bone Shield (Triggered by artifact)
class spell_dk_bone_shield : public SpellScriptLoader
{
public:
    spell_dk_bone_shield() : SpellScriptLoader("spell_dk_bone_shield") { }

    class spell_dk_bone_shield_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_bone_shield_AuraScript);

        void CalculateAmount(AuraEffect const* /*p_AuraEffect*/, int32& p_Amount, bool& /*p_CanBeRecalculated*/)
        {
            p_Amount = -1;
        }

        void Absorb(AuraEffect* /*p_AuraEffect*/, DamageInfo& /*p_DmgInfo*/, uint32& p_AbsorbAmount)
        {
            p_AbsorbAmount = 0; //This is set at 0 because we don't want to absorb
            GetCaster()->GetAura(SPELL_DK_BONE_SHIELD)->ModStackAmount(-1);
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_bone_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_bone_shield_AuraScript::Absorb, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_bone_shield_AuraScript();
    }
};

//195182 - Marrowrend
class spell_dk_marrowrend : public SpellScriptLoader
{
public:
    spell_dk_marrowrend() : SpellScriptLoader("spell_dk_marrowrend") { }

    class spell_dk_marrowrend_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_marrowrend_SpellScript);

        void HandleHit(SpellEffIndex effIndex)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            for(int i = 0; i < GetSpellInfo()->GetEffect(effIndex)->BasePoints;i++)
                caster->CastSpell(caster, SPELL_DK_BONE_SHIELD);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_dk_marrowrend_SpellScript::HandleHit, EFFECT_2, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_marrowrend_SpellScript();
    }
};

//206977
class spell_dk_blood_mirror : public SpellScriptLoader
{
public:
    spell_dk_blood_mirror() : SpellScriptLoader("spell_dk_blood_mirror") { }

    class spell_dk_blood_mirror_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_blood_mirror_AuraScript);

        void CalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            Unit* caster = GetCaster();
            if (!target || !caster)
                return;
            if(caster->HasAura(SPELL_DK_BLOOD_MIRROR))
                caster->GetAura(SPELL_DK_BLOOD_MIRROR)->Variables.Set("targetGUID", target->GetGUID());
        }

        void HandleAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            absorbAmount = dmgInfo.GetDamage() * (aurEff->GetBaseAmount() / 100);

            Unit* caster = GetCaster();
            ObjectGuid const procTargetGUID = GetAura()->Variables.GetValue<ObjectGuid>("targetGUID");
            if (!caster || procTargetGUID.IsEmpty())
                return;

            Unit* target = ObjectAccessor::GetUnit(*caster, procTargetGUID);
            if (!target)
                return;

            caster->CastCustomSpell(SPELL_DK_BLOOD_MIRROR_DAMAGE, SPELLVALUE_BASE_POINT0, absorbAmount, target, true);
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_blood_mirror_AuraScript::CalcAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
            AfterEffectApply += AuraEffectApplyFn(spell_dk_blood_mirror_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_blood_mirror_AuraScript::HandleAbsorb, EFFECT_1);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_blood_mirror_AuraScript();
    }
};

//194909 - Frozen Pulse
//Updated to 7.1
class spell_dk_frozen_pulse : public SpellScriptLoader
{
public:
    spell_dk_frozen_pulse() : SpellScriptLoader("spell_dk_frozen_pulse") { }

    class spell_dk_frozen_pulse_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_frozen_pulse_AuraScript);

        bool HandleProc(ProcEventInfo& /*procInfo*/)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return false;

            if (caster->GetPower(POWER_RUNES) > GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints)
                return false;

            return true;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dk_frozen_pulse_AuraScript::HandleProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_frozen_pulse_AuraScript();
    }
};

//194844 - Bonestorm
class spell_dk_bonestorm : public SpellScriptLoader
{
public:
    spell_dk_bonestorm() : SpellScriptLoader("spell_dk_bonestorm") { }

    class spell_dk_bonestorm_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_bonestorm_AuraScript);

        int32 m_ExtraSpellCost;

        bool Load() override
        {
            Unit* caster = GetCaster();
            if (!caster)
                return false;

            int availablePower = std::min(caster->GetPower(POWER_RUNIC_POWER), 90);

            //Round down to nearest multiple of 10
            m_ExtraSpellCost = availablePower - (availablePower % 10);
            return true;
        }

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            int32 m_newDuration = GetDuration() + (m_ExtraSpellCost / 10);
            SetDuration(m_newDuration);

            if (Unit* caster = GetCaster())
            {
                int32 m_newPower = caster->GetPower(POWER_RUNIC_POWER) - m_ExtraSpellCost;
                if (m_newPower < 0)
                    m_newPower = 0;
                caster->SetPower(POWER_RUNIC_POWER, m_newPower);
                if (Player* player = caster->ToPlayer())
                    player->SendPowerUpdate(POWER_RUNIC_POWER, m_newPower);
            }
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_DK_BONESTORM_HEAL, true);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_dk_bonestorm_AuraScript::HandleApply, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_dk_bonestorm_AuraScript::HandlePeriodic, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_bonestorm_AuraScript();
    }
};

// 194913 - Glacial Advance
class spell_dk_glacial_advance : public SpellScript
{
    PrepareSpellScript(spell_dk_glacial_advance);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        Position castPosition = *caster;
        Position collisonPos = caster->GetFirstCollisionPosition(GetEffectInfo()->MaxRadiusEntry->RadiusMax);
        float maxDistance = caster->GetDistance(collisonPos);

        for (float dist = 0.0f; dist <= maxDistance; dist += 1.5f)
        {
            caster->GetScheduler().Schedule(Milliseconds(uint32(dist / 1.5f * 50.0f)), [castPosition, dist](TaskContext context)
            {
                Unit* caster = context.GetUnit();

                Position targetPosition = castPosition;
                caster->MovePosition(targetPosition, dist);
                caster->CastSpell(targetPosition, SPELL_DK_GLACIAL_ADVANCE_DAMAGE, true);
            });
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_dk_glacial_advance::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 49020 - Obliterate
class spell_dk_obliterate : public SpellScript
{
    PrepareSpellScript(spell_dk_obliterate);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->RemoveAurasDueToSpell(SPELL_DK_KILLING_MACHINE);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_dk_obliterate::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 207317 - Epidemic
class spell_dk_epidemic : public SpellScript
{
    PrepareSpellScript(spell_dk_epidemic);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            if (Aura* aura = target->GetAura(SPELL_DK_VIRULENT_PLAGUE, GetCaster()->GetGUID()))
            {
                target->RemoveAura(aura);
                GetCaster()->CastSpell(target, SPELL_DK_EPIDEMIC_DAMAGE_SINGLE, true);
                GetCaster()->CastSpell(target, SPELL_DK_EPIDEMIC_DAMAGE_AOE, true);
            }
        }

        PreventHitDamage();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_epidemic::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 215969 - Epidemic AOE
class spell_dk_epidemic_aoe : public SpellScript
{
    PrepareSpellScript(spell_dk_epidemic_aoe);

    void HandleOnHitMain(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            explicitTarget = target->GetGUID();
    }

    void HandleOnHitAOE(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            if (target->GetGUID() == explicitTarget)
                PreventHitDamage();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_epidemic_aoe::HandleOnHitMain, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_dk_epidemic_aoe::HandleOnHitAOE, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
private:
    ObjectGuid explicitTarget;
};

// 191587 - Virulent Plague
class aura_dk_virulent_plague : public AuraScript
{
    PrepareAuraScript(aura_dk_virulent_plague);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        uint32 eruptionChances = GetEffectInfo(EFFECT_1)->BasePoints;
        if (roll_chance_i(eruptionChances))
            GetAura()->Remove(AURA_REMOVE_BY_DEATH);
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
        if (removeMode == AURA_REMOVE_BY_DEATH)
            if (Unit* caster = GetCaster())
                caster->CastSpell(GetTarget(), SPELL_DK_VIRULENT_ERUPTION, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_dk_virulent_plague::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        AfterEffectRemove += AuraEffectRemoveFn(aura_dk_virulent_plague::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 152280 - Defile
class aura_dk_defile : public AuraScript
{
    PrepareAuraScript(aura_dk_defile);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
        {
            for (AreaTrigger* at : caster->GetAreaTriggers(GetId()))
            {
                caster->CastSpell(at->GetPosition(), SPELL_DK_DEFILE_DAMAGE, true);

                if (at->GetInsideUnits().size())
                    caster->CastSpell(caster, SPELL_DK_DEFILE_MASTERY, true);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_dk_defile::HandlePeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 55090 - Scourge Strike
class spell_dk_scourge_strike : public SpellScript
{
    PrepareSpellScript(spell_dk_scourge_strike);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* target = GetHitUnit())
        {
            if (Aura* festeringWoundAura = target->GetAura(SPELL_DK_FESTERING_WOUND, GetCaster()->GetGUID()))
            {
                if (caster->HasAura(SPELL_DK_UNHOLY_FRENZY))
                    caster->CastSpell(caster, SPELL_DK_UNHOLY_FRENZY_BUFF, true);

                if (Aura* pestilentPustulesAura = caster->GetAura(SPELL_DK_PESTILENT_PUSTULES))
                    if (festeringWoundAura->GetStackAmount() >= pestilentPustulesAura->GetSpellEffectInfo(EFFECT_0)->BasePoints)
                        caster->ModifyPower(POWER_RUNES, 1);

                uint8 festeringWoundBurst = 1;
                if (Aura* castiragorAura = caster->GetAura(SPELL_DK_CASTIGATOR))
                    festeringWoundBurst += castiragorAura->GetSpellEffectInfo(EFFECT_1)->BasePoints;

                festeringWoundBurst = std::min(festeringWoundBurst, festeringWoundAura->GetStackAmount());

                for (uint8 i = 0; i < festeringWoundBurst; ++i)
                {
                    caster->CastSpell(target, SPELL_DK_FESTERING_WOUND_DAMAGE, true);
                    festeringWoundAura->ModStackAmount(-1);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_scourge_strike::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Spell 152280
// At 6212
struct at_dk_defile : AreaTriggerAI
{
    at_dk_defile(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            caster->CastSpell(unit, SPELL_DK_DEFILE_DUMMY, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_DK_DEFILE_DUMMY);
    }
};

// 195758 - Blighted Rune Weapon
class spell_dk_blighted_rune_weapon : public SpellScript
{
    PrepareSpellScript(spell_dk_blighted_rune_weapon);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_FESTERING_WOUND });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, SPELL_DK_FESTERING_WOUND, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_blighted_rune_weapon::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Spell 199720
// At 199720
struct at_dk_decomposing_aura : AreaTriggerAI
{
    at_dk_decomposing_aura(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_DK_DECOMPOSING_AURA_DAMAGE, at->GetCasterGuid());
    }
};

void AddSC_deathknight_spell_scripts()
{
    new spell_dk_advantage_t10_4p();
    new spell_dk_anti_magic_barrier();
    new spell_dk_anti_magic_shell();
    new spell_dk_anti_magic_shell_self();
    new spell_dk_army_periodic_taunt();
    new spell_dk_army_transform();
    new spell_dk_blood_boil();
    new spell_dk_blood_charges();
    new spell_dk_blood_gorged();
    new spell_dk_blood_mirror();
    new spell_dk_breath_of_sindragosa();
    new spell_dk_bonestorm();
    new spell_dk_bone_shield();
    new spell_dk_chains_of_ice();
    new spell_dk_chilblains();
    new spell_dk_dark_transformation_form();
    new spell_dk_death_and_decay();
    RegisterSpellScript(spell_dk_death_coil);
    new spell_dk_death_gate();
    RegisterSpellScript(spell_dk_death_grip_initial);
    new spell_dk_death_pact();
    new spell_dk_death_siphon();
    new spell_dk_death_strike();
    new spell_dk_desecrated_ground();
    new spell_dk_empower_rune_weapon();
    RegisterSpellScript(spell_dk_festering_strike);
    new spell_dk_frozen_pulse();
    RegisterSpellScript(spell_dk_ghoul_explode);
    new spell_dk_glyph_of_deaths_embrace();
    new spell_dk_glyph_of_runic_power();
    new spell_dk_gorefiends_grasp();
    RegisterSpellScript(spell_dk_howling_blast);
    RegisterSpellScript(spell_dk_howling_blast_aoe);
    new spell_dk_icebound_fortitude();
    new spell_dk_icy_touch();
    new spell_dk_marrowrend();
    RegisterSpellScript(spell_dk_outbreak);
    RegisterAuraScript(aura_dk_outbreak_periodic);
    new spell_dk_pet_geist_transform();
    new spell_dk_pet_skeleton_transform();
    new spell_dk_pillar_of_frost();
    new spell_dk_plague_leech();
    new spell_dk_plague_strike();
    new spell_dk_presence();
    new spell_dk_purgatory();
    new spell_dk_purgatory_absorb();
    new spell_dk_raise_dead();
    RegisterSpellScript(spell_dk_remorseless_winter_damage);
    new spell_dk_runic_empowerment(); //NOT WORKING - Need implementation on PlayerScript :)
    new spell_dk_soul_reaper();
    new spell_dk_unholy_blight();
    new spell_dk_vampiric_blood();
    RegisterAuraScript(spell_dk_will_of_the_necropolis);
    RegisterSpellScript(spell_dk_glacial_advance);
    RegisterSpellScript(spell_dk_obliterate);
    RegisterSpellScript(spell_dk_epidemic);
    RegisterSpellScript(spell_dk_epidemic_aoe);
    RegisterAuraScript(aura_dk_virulent_plague);
    RegisterSpellScript(spell_dk_scourge_strike);
    RegisterAuraScript(aura_dk_defile);
    RegisterAreaTriggerAI(at_dk_defile);
    RegisterSpellScript(spell_dk_blighted_rune_weapon);
    RegisterAreaTriggerAI(at_dk_decomposing_aura);
}
