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
 * Scripts for spells with SPELLFAMILY_ROGUE and SPELLFAMILY_GENERIC spells used by rogue players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_rog_".
 */

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Containers.h"
#include "DynamicObject.h"
#include "Item.h"
#include "Log.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum RogueSpells
{
    SPELL_ROGUE_ADRENALINE_RUSH                     = 13750,
    SPELL_ROGUE_ALACRITY                            = 193539,
    SPELL_ROGUE_ALACRITY_BUFF                       = 193538,
    SPELL_ROGUE_BLADE_FLURRY                        = 13877,
    SPELL_ROGUE_BLADE_FLURRY_EXTRA_ATTACK           = 22482,
    SPELL_ROGUE_CANNONBALL_BARRAGE_DAMAGE           = 185779,
    SPELL_ROGUE_CANNONBALL_BARRAGE_SLOW             = 185778,
    SPELL_ROGUE_CHEAT_DEATH_COOLDOWN                = 45181,
    SPELL_ROGUE_CHEAT_DEATH_REDUCE_DAMAGE           = 45182,
    SPELL_ROGUE_CRIMSON_TEMPEST_DOT                 = 122233,
    SPELL_ROGUE_CRIPPLING_POISON                    = 3409,
    SPELL_ROGUE_CRIPPLING_POISON_DEBUFF             = 3409,
    SPELL_ROGUE_CUT_TO_THE_CHASE_AURA               = 51667,
    SPELL_ROGUE_DEADLY_BREW                         = 51626,
    SPELL_ROGUE_DEADLY_POISON                       = 2823,
    SPELL_ROGUE_DEADLY_POISON_DOT                   = 2818,
    SPELL_ROGUE_DEADLY_POISON_INSTANT_DAMAGE        = 113780,
    SPELL_ROGUE_DEATH_FROM_ABOVE_DAMAGE_BONUS       = 163786,
    SPELL_ROGUE_DEATH_FROM_ABOVE_JUMP               = 178153,
    SPELL_ROGUE_DEBILITATING_POISON                 = 115196,
    SPELL_ROGUE_DEEPENING_SHADOWS                   = 185314,
    SPELL_ROGUE_DEEPER_STRATAGEM                    = 193531,
    SPELL_ROGUE_ENERGETIC_RECOVERY_AURA             = 79152,
    SPELL_ROGUE_ENVELOPING_SHADOWS                  = 206237,
    SPELL_ROGUE_ENVENOM                             = 32645,
    SPELL_ROGUE_EVISCERATE                          = 196819,
    SPELL_ROGUE_FAN_OF_KNIVES                       = 51723,
    SPELL_ROGUE_GARROTE_DOT                         = 703,
    SPELL_ROGUE_GARROTE_SILENCE                     = 1330,
    SPELL_ROGUE_GLYPH_OF_EXPOSE_ARMOR               = 56803,
    SPELL_ROGUE_GLYPH_OF_HEMORRHAGE                 = 56807,
    SPELL_ROGUE_GLYPH_OF_PREPARATION                = 56819,
    SPELL_ROGUE_GLYPH_OF_REGENERATE                 = 146625,
    SPELL_ROGUE_GRAPPLING_HOOK_TRIGGER              = 227180,
    SPELL_ROGUE_HEMORRHAGE_DOT                      = 89775,
    SPELL_ROGUE_HONOR_AMONG_THIEVES                 = 51698,
    SPELL_ROGUE_HONOR_AMONG_THIEVES_PROC            = 51699,
    SPELL_ROGUE_KIDNEY_SHOT                         = 408,
    SPELL_ROGUE_KILLING_SPREE                       = 51690,
    SPELL_ROGUE_KILLING_SPREE_DMG_BUFF              = 61851,
    SPELL_ROGUE_KILLING_SPREE_TELEPORT              = 57840,
    SPELL_ROGUE_KILLING_SPREE_WEAPON_DMG            = 57841,
    SPELL_ROGUE_LEECHING_POISON                     = 108211,
    SPELL_ROGUE_LEECHING_POISON_DEBUFF              = 112961,
    SPELL_ROGUE_LEECH_VITALITY                      = 116921,
    SPELL_ROGUE_MASTERY_MAIN_GAUCHE_DAMAGE          = 86392,
    SPELL_ROGUE_MASTER_OF_SHADOWS                   = 196976,
    SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT   = 31665,
    SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE          = 31223,
    SPELL_ROGUE_MASTER_POISONER_AURA                = 58410,
    SPELL_ROGUE_MASTER_POISONER_DEBUFF              = 93068,
    SPELL_ROGUE_MIND_NUMBLING_POISON                = 5761,
    SPELL_ROGUE_MIND_PARALYSIS                      = 115194,
    SPELL_ROGUE_NERVE_STRIKE_AURA                   = 108210,
    SPELL_ROGUE_NERVE_STRIKE_REDUCE_DAMAGE_DONE     = 112947,
    SPELL_ROGUE_NIGHTBLADE                          = 195452,
    SPELL_ROGUE_NIGHTBLADE_SLOW                     = 206760,
    SPELL_ROGUE_NIGHTSTALKER_AURA                   = 14062,
    SPELL_ROGUE_NIGHTSTALKER_DAMAGE_DONE            = 130493,
    SPELL_ROGUE_OPPORTUNITY                         = 195627,
    SPELL_ROGUE_PARALYTIC_POISON                    = 108215,
    SPELL_ROGUE_PARALYTIC_POISON_DEBUFF             = 113952,
    SPELL_ROGUE_PARTIAL_PARALYSIS                   = 115197,
    SPELL_ROGUE_PISTOL_SHOT                         = 185763,
    SPELL_ROGUE_PREY_ON_THE_WEAK                    = 58670,
    SPELL_ROGUE_RECUPERATE                          = 73651,
    SPELL_ROGUE_REDIRECT                            = 73981,
    SPELL_ROGUE_RELENTLESS_STRIKES                  = 58423,
    SPELL_ROGUE_RELENTLESS_STRIKES_POWER            = 98440,
    SPELL_ROGUE_RESTLESS_BLADES                     = 79096,
    SPELL_ROGUE_RIPOSTE_DAMAGE                      = 199753,
    SPELL_ROGUE_ROLL_THE_BONES                      = 193316,
    SPELL_ROGUE_ROLL_THE_BONES_VISUAL               = 208244,
    SPELL_ROGUE_RUN_THROUGH                         = 2098,
    SPELL_ROGUE_RUPTURE                             = 1943,
    SPELL_ROGUE_RUPTURE_DOT                         = 1943,
    SPELL_ROGUE_SABER_SLASH                         = 193315,
    SPELL_ROGUE_SANCTUARY                           = 98877,
    SPELL_ROGUE_SANGUINARY_VEIN_DEBUFF              = 124271,
    SPELL_ROGUE_SERRATED_BLADES_R1                  = 14171,
    SPELL_ROGUE_SHADOWSTEP_LEAP                     = 36563,
    SPELL_ROGUE_SHADOWSTRIKE                        = 185438,
    SPELL_ROGUE_SHADOW_BLADES                       = 121471,
    SPELL_ROGUE_SHADOW_DANCE                        = 185313,
    SPELL_ROGUE_SHADOW_DANCE_AURA                   = 185422,
    SPELL_ROGUE_SHADOW_FOCUS                        = 108209,
    SPELL_ROGUE_SHADOW_FOCUS_AURA                   = 108209,
    SPELL_ROGUE_SHADOW_FOCUS_COST_PCT               = 112942,
    SPELL_ROGUE_SHADOW_FOCUS_EFFECT                 = 112942,
    SPELL_ROGUE_SHADOW_TENCHNIQUES_POWER            = 196911,
    SPELL_ROGUE_SHIV_TRIGGERED                      = 5940,
    SPELL_ROGUE_SHROUD_OF_CONCEALMENT_AURA          = 115834,
    SPELL_ROGUE_SHURIKEN_STORM                      = 197835,
    SPELL_ROGUE_SILCE_AND_DICE                      = 5171,
    SPELL_ROGUE_SLICE_AND_DICE                      = 5171,
    SPELL_ROGUE_SMOKE_BOMB_AURA                     = 212183,
    SPELL_ROGUE_SMOKE_BOMB_VISUAL                   = 183859,
    SPELL_ROGUE_SPRINT                              = 2983,
    SPELL_ROGUE_STEALTH                             = 1784,
    SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA             = 158188,
    SPELL_ROGUE_STEALTH_STEALTH_AURA                = 158185,
    SPELL_ROGUE_STRIKE_FROM_THE_SHADOWS             = 196951,
    SPELL_ROGUE_SUBTERFUGE                          = 108208,
    SPELL_ROGUE_SUBTERFUGE_AURA                     = 115192,
    SPELL_ROGUE_THUGGEE                             = 196861,
    SPELL_ROGUE_TOTAL_PARALYSIS                     = 113953,
    SPELL_ROGUE_TRICKS_OF_THE_TRADE_DMG_BOOST       = 57933,
    SPELL_ROGUE_TRICKS_OF_THE_TRADE_PROC            = 59628,
    SPELL_ROGUE_VANISH_AURA                         = 11327,
    SPELL_ROGUE_VENOMOUS_VIM_ENERGIZE               = 51637,
    SPELL_ROGUE_VENOMOUS_WOUNDS                     = 79134,
    SPELL_ROGUE_VENOMOUS_WOUND_DAMAGE               = 79136,
    SPELL_ROGUE_VENOM_RUSH                          = 152152,
    SPELL_ROGUE_WEAKENED_ARMOR                      = 113746,
    SPELL_ROGUE_WOUND_POISON                        = 8679,
};

enum RollTheBones
{
    SPELL_ROGUE_JOLLY_ROGER                         = 199603,
    SPELL_ROGUE_GRAND_MELEE                         = 193358,
    SPELL_ROGUE_SHARK_INFESTED_WATERS               = 193357,
    SPELL_ROGUE_TRUE_BEARING                        = 193359,
    SPELL_ROGUE_BURIED_TREASURE                     = 199600,
    SPELL_ROGUE_BROADSIDES                          = 193356,
};

enum RogueSpellIcons
{
    ICON_ROGUE_IMPROVED_RECUPERATE                  = 4819
};

enum CheatDeath
{
    SPELL_ROGUE_CHEAT_DEATH                         = 31230,
    SPELL_ROGUE_CHEAT_DEATH_ANIM                    = 31231,
    SPELL_ROGUE_CHEAT_DEATH_DMG_REDUC               = 45182,
    SPELL_ROGUE_CHEAT_DEATH_CD_AURA                 = 45181
};

enum TrueBearingIDs
{
    SPELL_ROGUE_BETWEEN_THE_EYES                    = 199804,
    SPELL_ROGUE_VANISH                              = 1856,
    SPELL_ROGUE_BLIND                               = 2094,
    SPELL_ROGUE_CLOAK_OF_SHADOWS                    = 31224,
    SPELL_ROGUE_RIPOSTE                             = 199754,
    SPELL_ROGUE_GRAPPLING_HOOK                      = 195457,
    SPELL_ROGUE_CANNONBALL_BARRAGE                  = 185767,
    SPELL_ROGUE_MARKED_FOR_DEATH                    = 137619,
    SPELL_ROGUE_DEATH_FROM_ABOVE                    = 152150
};

// Cannonball Barrage - 185767
class spell_rog_cannonball_barrage : public SpellScriptLoader
{
public:
    spell_rog_cannonball_barrage() : SpellScriptLoader("spell_rog_cannonball_barrage") {}

    class spell_rog_cannonball_barrage_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_cannonball_barrage_AuraScript);

        bool Validate(SpellInfo const*) override
        {
            return ValidateSpellInfo(
            {
                SPELL_ROGUE_CANNONBALL_BARRAGE,
                SPELL_ROGUE_CANNONBALL_BARRAGE_DAMAGE,
                SPELL_ROGUE_CANNONBALL_BARRAGE_SLOW
            });
        }

        void HandlePeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = aurEff->GetCaster();
            if (!caster)
                return;

            DynamicObject* barrage = caster->GetDynObject(SPELL_ROGUE_CANNONBALL_BARRAGE);
            if (!barrage)
                return;

            caster->CastSpell(barrage->GetPositionX(), barrage->GetPositionY(), barrage->GetPositionZ(), SPELL_ROGUE_CANNONBALL_BARRAGE_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_rog_cannonball_barrage_AuraScript::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    class spell_rog_cannonball_barrage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_cannonball_barrage_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_ROGUE_CANNONBALL_BARRAGE,
                SPELL_ROGUE_CANNONBALL_BARRAGE_DAMAGE,
                SPELL_ROGUE_CANNONBALL_BARRAGE_SLOW
            });
        }

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!target || !caster)
                return;

            caster->CastSpell(target, SPELL_ROGUE_CANNONBALL_BARRAGE_SLOW, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_rog_cannonball_barrage_SpellScript::HandleHit, EFFECT_2, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_cannonball_barrage_SpellScript();
    }

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_cannonball_barrage_AuraScript();
    }
};

// Between the Eyes - 199804
class spell_rog_between_the_eyes :public SpellScript
{
    PrepareSpellScript(spell_rog_between_the_eyes);

    void HandleTakePower(SpellPowerCost& powerCost)
    {
        if (powerCost.Power == POWER_COMBO_POINTS)
            _cp = powerCost.Amount;
    }

    void HandleAfterHit()
    {
        if (Unit* target = GetHitUnit())
            if (Aura* aura = target->GetAura(SPELL_ROGUE_BETWEEN_THE_EYES, GetCaster()->GetGUID()))
                aura->SetDuration(_cp * IN_MILLISECONDS);
    }

    void Register() override
    {
        OnTakePower += SpellOnTakePowerFn(spell_rog_between_the_eyes::HandleTakePower);
        AfterHit += SpellHitFn(spell_rog_between_the_eyes::HandleAfterHit);
    }
private:
    uint8 _cp = 0;
};

// Grappling Hook - 195457
class spell_rog_grappling_hook : public SpellScriptLoader
{
public:
    spell_rog_grappling_hook() : SpellScriptLoader("spell_rog_grappling_hook") {}

    class spell_rog_grappling_hook_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_grappling_hook_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_ROGUE_GRAPPLING_HOOK,
                SPELL_ROGUE_GRAPPLING_HOOK_TRIGGER
            });
        }

        void HandleDummy()
        {
            Unit* caster = GetCaster();
            WorldLocation const* dest = GetExplTargetDest();
            if (!caster || !dest)
                return;

            caster->CastSpell(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), SPELL_ROGUE_GRAPPLING_HOOK_TRIGGER, true);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_rog_grappling_hook_SpellScript::HandleDummy);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_grappling_hook_SpellScript();
    }
};

// 199603,193358,193357,193359,199600,193356 - Roll The Bones buffs
class spell_rog_roll_the_bones_duration : public SpellScriptLoader
{
public:
    spell_rog_roll_the_bones_duration() : SpellScriptLoader("spell_rog_roll_the_bones_duration") { }

    class spell_rog_roll_the_bones_duration_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_roll_the_bones_duration_AuraScript);

        void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            Aura* rtb = caster->GetAura(SPELL_ROGUE_ROLL_THE_BONES);
            if (!rtb)
            {
                caster->RemoveAurasDueToSpell(GetSpellInfo()->Id); //sometimes it remains on the caster after relog incorrectly.
                return;
            }

            if (Aura* aur = caster->GetAura(GetSpellInfo()->Id))
            {
                aur->SetMaxDuration(rtb->GetDuration());
                aur->SetDuration(rtb->GetDuration());
            }
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_rog_roll_the_bones_duration_AuraScript::AfterApply, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_roll_the_bones_duration_AuraScript();
    }
};

// Roll the bones animation - 208244
class spell_rog_roll_the_bones_visual : public SpellScriptLoader
{
public:
    spell_rog_roll_the_bones_visual() : SpellScriptLoader("spell_rog_roll_the_bones_visual") { }

    class spell_rog_roll_the_bones_visual_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_roll_the_bones_visual_SpellScript);

        void Prevent(SpellEffIndex effIndex)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->ToPlayer())
            {
                PreventHitAura();
                PreventHitDamage();
                PreventHitDefaultEffect(effIndex);
                PreventHitEffect(effIndex);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_rog_roll_the_bones_visual_SpellScript::Prevent, EFFECT_ALL, SPELL_EFFECT_ANY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_roll_the_bones_visual_SpellScript();
    }
};

// Roll the Bones - 193316
class spell_rog_roll_the_bones : public SpellScriptLoader
{
public:
    spell_rog_roll_the_bones() : SpellScriptLoader("spell_rog_roll_the_bones") {}

    class spell_rog_roll_the_bones_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_roll_the_bones_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_ROGUE_ROLL_THE_BONES,
                SPELL_ROGUE_JOLLY_ROGER,
                SPELL_ROGUE_GRAND_MELEE,
                SPELL_ROGUE_SHARK_INFESTED_WATERS,
                SPELL_ROGUE_TRUE_BEARING,
                SPELL_ROGUE_BURIED_TREASURE,
                SPELL_ROGUE_BROADSIDES
            });
        }

        void HandleDummy(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            // Six identical dice are rolled that have six sides representing each buff.
            //The side that comes up the most will be what buff you get.
            //On ties you get all buffs that are tied for the most.
            //Rolling each unique buff on each die counts as all six tying, granting you all six buffs.

            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_ROGUE_ROLL_THE_BONES_VISUAL, true);

            std::srand(std::time(NULL));
            std::vector<int32> rolls{ 0,0,0,0,0,0 };
            std::vector<int32> buffs{ SPELL_ROGUE_JOLLY_ROGER, SPELL_ROGUE_GRAND_MELEE, SPELL_ROGUE_SHARK_INFESTED_WATERS,
                                       SPELL_ROGUE_TRUE_BEARING, SPELL_ROGUE_BURIED_TREASURE, SPELL_ROGUE_BROADSIDES };
            for (int i = 0; i < 6; i++) //We roll the six dices
            {
                rolls[std::rand() % 6]++;
            }
            int32 maxroll = 0;
            for (auto elem : rolls) //Search for the highest roll
                if (elem > maxroll)
                    maxroll = elem;

            for (int i = 0; i < 6; i++) //Apply each buff corresponding to the highest roll (can be tied)
            {
                if (rolls[i] == maxroll)
                {
                    if (caster->HasAura(buffs[i]))
                        caster->RemoveAura(buffs[i]);
                    caster->CastSpell(caster, buffs[i], true);
                }
            }
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_rog_roll_the_bones_AuraScript::HandleDummy, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_roll_the_bones_AuraScript();
    }

    class spell_rog_roll_the_bones_duration_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_roll_the_bones_duration_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_ROGUE_ROLL_THE_BONES });
        }

        void HandleAfterHit()
        {
            if (Aura* rtbAura = GetCaster()->GetAura(GetSpellInfo()->Id))
                if (SpellPowerCost const* powerCost = GetSpell()->GetPowerCost(POWER_COMBO_POINTS))
                    rtbAura->SetDuration((powerCost->Amount + 1) * 6 * IN_MILLISECONDS);
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_rog_roll_the_bones_duration_SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_roll_the_bones_duration_SpellScript();
    }
};

// 13877, 33735, (check 51211, 65956) - Blade Flurry
class spell_rog_blade_flurry : public SpellScriptLoader
{
    public:
        spell_rog_blade_flurry() : SpellScriptLoader("spell_rog_blade_flurry") { }

        class spell_rog_blade_flurry_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_blade_flurry_AuraScript);

        public:
            spell_rog_blade_flurry_AuraScript()
            {
                _procTarget = nullptr;
            }

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_ROGUE_BLADE_FLURRY_EXTRA_ATTACK
                });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                _procTarget = GetTarget()->SelectNearbyTarget(eventInfo.GetProcTarget());
                return _procTarget && eventInfo.GetDamageInfo();
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                TC_LOG_ERROR("misc", "damage: %u procSpell: %u",
                    eventInfo.GetDamageInfo()->GetDamage(), eventInfo.GetDamageInfo()->GetSpellInfo() ? eventInfo.GetDamageInfo()->GetSpellInfo()->Id : 0);

                GetTarget()->CastCustomSpell(SPELL_ROGUE_BLADE_FLURRY_EXTRA_ATTACK, SPELLVALUE_BASE_POINT0, eventInfo.GetDamageInfo()->GetDamage(), _procTarget, true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_rog_blade_flurry_AuraScript::CheckProc);
                if (m_scriptSpellId == SPELL_ROGUE_BLADE_FLURRY)
                    OnEffectProc += AuraEffectProcFn(spell_rog_blade_flurry_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_MOD_POWER_REGEN_PERCENT);
                else
                    OnEffectProc += AuraEffectProcFn(spell_rog_blade_flurry_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_MOD_MELEE_HASTE);
            }

        private:
            Unit* _procTarget;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_blade_flurry_AuraScript();
        }
};

// 31230 - Cheat Death
class spell_rog_cheat_death : public SpellScriptLoader
{
    public:
        spell_rog_cheat_death() : SpellScriptLoader("spell_rog_cheat_death") { }

        class spell_rog_cheat_death_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_cheat_death_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_ROGUE_CHEAT_DEATH_COOLDOWN
                });
            }

            bool Load() override
            {
                return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                Player* target = GetTarget()->ToPlayer();
                if (target->HasAura(SPELL_ROGUE_CHEAT_DEATH_DMG_REDUC))
                {
                    absorbAmount = CalculatePct(dmgInfo.GetDamage(), 85);
                    return;
                }
                else
                {
                    if (dmgInfo.GetDamage() < target->GetHealth() || target->HasAura(SPELL_ROGUE_CHEAT_DEATH_COOLDOWN))
                        return;

                    uint64 health7 = target->CountPctFromMaxHealth(7);
                    target->SetHealth(1);
                    HealInfo healInfo(target, target, health7, GetSpellInfo(), GetSpellInfo()->GetSchoolMask());
                    target->HealBySpell(healInfo);
                    target->CastSpell(target, SPELL_ROGUE_CHEAT_DEATH_ANIM, true);
                    target->CastSpell(target, SPELL_ROGUE_CHEAT_DEATH_DMG_REDUC, true);
                    target->CastSpell(target, SPELL_ROGUE_CHEAT_DEATH_COOLDOWN, true);
                    absorbAmount = dmgInfo.GetDamage();
                }
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_rog_cheat_death_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_rog_cheat_death_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_cheat_death_AuraScript();
        }
};

// 2818 - Deadly Poison
class spell_rog_deadly_poison : public SpellScriptLoader
{
    public:
        spell_rog_deadly_poison() : SpellScriptLoader("spell_rog_deadly_poison") { }

        class spell_rog_deadly_poison_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rog_deadly_poison_SpellScript);

        public:
            spell_rog_deadly_poison_SpellScript()
            {
                _stackAmount = 0;
            }

        private:
            bool Load() override
            {
                // at this point CastItem must already be initialized
                return GetCaster()->GetTypeId() == TYPEID_PLAYER && GetCastItem();
            }

            void HandleBeforeHit(SpellMissInfo missInfo)
            {
                if (missInfo != SPELL_MISS_NONE)
                    return;

                if (Unit* target = GetHitUnit())
                    // Deadly Poison
                    if (AuraEffect const* aurEff = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_ROGUE, flag128(0x10000, 0x80000, 0), GetCaster()->GetGUID()))
                        _stackAmount = aurEff->GetBase()->GetStackAmount();
            }

            void HandleAfterHit()
            {
                if (_stackAmount < 5)
                    return;

                Player* player = GetCaster()->ToPlayer();

                if (Unit* target = GetHitUnit())
                {

                    Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);

                    if (item == GetCastItem())
                        item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

                    if (!item)
                        return;

                    // item combat enchantments
                    for (uint8 slot = 0; slot < MAX_ENCHANTMENT_SLOT; ++slot)
                    {
                        SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(item->GetEnchantmentId(EnchantmentSlot(slot)));
                        if (!enchant)
                            continue;

                        for (uint8 s = 0; s < 3; ++s)
                        {
                            if (enchant->Effect[s] != ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL)
                                continue;

                            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(enchant->EffectArg[s]);
                            if (!spellInfo)
                            {
                                TC_LOG_ERROR("spells", "Player::CastItemCombatSpell Enchant %i, player (Name: %s, %s) cast unknown spell %i", enchant->ID, player->GetName().c_str(), player->GetGUID().ToString().c_str(), enchant->EffectArg[s]);
                                continue;
                            }

                            // Proc only rogue poisons
                            if (spellInfo->SpellFamilyName != SPELLFAMILY_ROGUE || spellInfo->Dispel != DISPEL_POISON)
                                continue;

                            // Do not reproc deadly
                            if (spellInfo->SpellFamilyFlags == flag128(0x10000, 0x80000, 0, 0))
                                continue;

                            if (spellInfo->IsPositive())
                                player->CastSpell(player, enchant->EffectArg[s], true, item);
                            else
                                player->CastSpell(target, enchant->EffectArg[s], true, item);
                        }
                    }
                }
            }

            void Register() override
            {
                BeforeHit += BeforeSpellHitFn(spell_rog_deadly_poison_SpellScript::HandleBeforeHit);
                AfterHit += SpellHitFn(spell_rog_deadly_poison_SpellScript::HandleAfterHit);
            }

            uint8 _stackAmount;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_rog_deadly_poison_SpellScript();
        }
};

// 51690 - Killing Spree
#define KillingSpreeScriptName "spell_rog_killing_spree"
class spell_rog_killing_spree : public SpellScriptLoader
{
    public:
        spell_rog_killing_spree() : SpellScriptLoader(KillingSpreeScriptName) { }

        class spell_rog_killing_spree_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rog_killing_spree_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty() || GetCaster()->GetVehicleBase())
                    FinishCast(SPELL_FAILED_OUT_OF_RANGE);
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Aura* aura = GetCaster()->GetAura(SPELL_ROGUE_KILLING_SPREE))
                {
                    if (spell_rog_killing_spree_AuraScript* script = dynamic_cast<spell_rog_killing_spree_AuraScript*>(aura->GetScriptByName(KillingSpreeScriptName)))
                        script->AddTarget(GetHitUnit());
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_rog_killing_spree_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_DEST_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_rog_killing_spree_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_rog_killing_spree_SpellScript();
        }

        class spell_rog_killing_spree_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_killing_spree_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_ROGUE_KILLING_SPREE_TELEPORT,
                    SPELL_ROGUE_KILLING_SPREE_WEAPON_DMG,
                    SPELL_ROGUE_KILLING_SPREE_DMG_BUFF
                });
            }

            void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_ROGUE_KILLING_SPREE_DMG_BUFF, true);
            }

            void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
            {
                while (!_targets.empty())
                {
                    ObjectGuid guid = Trinity::Containers::SelectRandomContainerElement(_targets);
                    if (Unit* target = ObjectAccessor::GetUnit(*GetTarget(), guid))
                    {
                        GetTarget()->CastSpell(target, SPELL_ROGUE_KILLING_SPREE_TELEPORT, true);
                        GetTarget()->CastSpell(target, SPELL_ROGUE_KILLING_SPREE_WEAPON_DMG, true);
                        break;
                    }
                    else
                        _targets.remove(guid);
                }
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAurasDueToSpell(SPELL_ROGUE_KILLING_SPREE_DMG_BUFF);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_rog_killing_spree_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_rog_killing_spree_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                AfterEffectRemove += AuraEffectRemoveFn(spell_rog_killing_spree_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }

        public:
            void AddTarget(Unit* target)
            {
                _targets.push_back(target->GetGUID());
            }

        private:
            GuidList _targets;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_killing_spree_AuraScript();
        }
};

// 1943 - Rupture
class spell_rog_rupture : public SpellScript
{
    PrepareSpellScript(spell_rog_rupture);

    void HandleAfterHit()
    {
        if (Unit* target = GetHitUnit())
        {
            if (Aura* ruptureAura = target->GetAura(GetSpellInfo()->Id))
            {
                if (AuraEffect* effect = ruptureAura->GetEffect(EFFECT_0))
                {
                    if (SpellPowerCost const* powerCost = GetSpell()->GetPowerCost(POWER_COMBO_POINTS))
                    {
                        effect->SetDamage(effect->GetDamage() / 2);

                        int32 duration = 4 + (4 * powerCost->Amount);
                        ruptureAura->SetDuration(duration * IN_MILLISECONDS);
                    }
                }
            }
        }
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_rog_rupture::HandleAfterHit);
    }
};

// 1784 - Stealth
class spell_rog_stealth : public SpellScriptLoader
{
    public:
        spell_rog_stealth() : SpellScriptLoader("spell_rog_stealth") { }

        class spell_rog_stealth_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_stealth_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE,
                    SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT,
                    SPELL_ROGUE_SANCTUARY,
                    SPELL_ROGUE_SHADOW_FOCUS,
                    SPELL_ROGUE_SHADOW_FOCUS_EFFECT,
                    SPELL_ROGUE_STEALTH_STEALTH_AURA,
                    SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA
                });
            }

            void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                // Master of Subtlety
                if (target->HasAura(SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE))
                    target->CastSpell(target, SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT, TRIGGERED_FULL_MASK);

                // Shadow Focus
                if (target->HasAura(SPELL_ROGUE_SHADOW_FOCUS))
                    target->CastSpell(target, SPELL_ROGUE_SHADOW_FOCUS_EFFECT, TRIGGERED_FULL_MASK);

                target->RemoveAurasDueToSpell(SPELL_ROGUE_VANISH);
                target->RemoveAurasDueToSpell(SPELL_ROGUE_VANISH_AURA);
                target->RemoveAurasDueToSpell(SPELL_ROGUE_STEALTH_STEALTH_AURA);
                target->RemoveAurasDueToSpell(SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA);

                target->CastSpell(target, SPELL_ROGUE_SANCTUARY, TRIGGERED_FULL_MASK);
                target->CastSpell(target, SPELL_ROGUE_STEALTH_STEALTH_AURA, TRIGGERED_FULL_MASK);
                target->CastSpell(target, SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA, TRIGGERED_FULL_MASK);

                if(target->HasAura(SPELL_ROGUE_MASTER_OF_SHADOWS))
                    target->ModifyPower(POWER_ENERGY, +30);
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                // Master of Subtlety
                if (AuraEffect* masterOfSubtletyPassive = GetTarget()->GetAuraEffect(SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE, EFFECT_0))
                {
                    if (Aura* masterOfSubtletyAura = GetTarget()->GetAura(SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT))
                    {
                        masterOfSubtletyAura->SetMaxDuration(masterOfSubtletyPassive->GetAmount());
                        masterOfSubtletyAura->RefreshDuration();
                    }
                }

                target->RemoveAurasDueToSpell(SPELL_ROGUE_SHADOW_FOCUS_EFFECT);
                target->RemoveAurasDueToSpell(SPELL_ROGUE_STEALTH_STEALTH_AURA);
                target->RemoveAurasDueToSpell(SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA);
                if (target->HasAura(SPELL_ROGUE_SUBTERFUGE))
                    target->CastSpell(target, SPELL_ROGUE_SUBTERFUGE_AURA, true);
                if (Aura* aur = target->GetAura(SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT))
                {
                    aur->SetMaxDuration(6000);
                    aur->SetDuration(6000);
                }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_rog_stealth_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                AfterEffectRemove += AuraEffectRemoveFn(spell_rog_stealth_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_stealth_AuraScript();
        }
};

// 115192 - Subterfuge Aura
class spell_rog_subterfuge : public SpellScriptLoader
{
public:
    spell_rog_subterfuge() : SpellScriptLoader("spell_rog_subterfuge") {}

    class spell_rog_subterfuge_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_subterfuge_AuraScript);

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            caster->CastSpell(caster, SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA, true);
        }

        void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            caster->RemoveAurasDueToSpell(SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_rog_subterfuge_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_rog_subterfuge_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_subterfuge_AuraScript();
    }
};

// 1856 - Vanish
class spell_rog_vanish : public SpellScriptLoader
{
    public:
        spell_rog_vanish() : SpellScriptLoader("spell_rog_vanish") { }

        class spell_rog_vanish_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rog_vanish_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_ROGUE_VANISH_AURA,
                    SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA
                });
            }

            void OnLaunch()
            {
                Unit* caster = GetCaster();

                caster->RemoveMovementImpairingAuras();
                caster->RemoveAurasByType(SPELL_AURA_MOD_STALKED);

                caster->CastSpell(caster, SPELL_ROGUE_VANISH_AURA, true);
                caster->CastSpell(caster, SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA, true);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_rog_vanish_SpellScript::OnLaunch);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_rog_vanish_SpellScript();
        }
};

// 11327 - Vanish
class spell_rog_vanish_aura : public SpellScriptLoader
{
    public:
        spell_rog_vanish_aura() : SpellScriptLoader("spell_rog_vanish_aura") { }

        class spell_rog_vanish_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_vanish_aura_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_ROGUE_STEALTH
                });
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_ROGUE_STEALTH, true);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_rog_vanish_aura_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_vanish_aura_AuraScript();
        }
};

class spell_rog_serrated_blades : public SpellScriptLoader
{
public:
    spell_rog_serrated_blades() : SpellScriptLoader("spell_rog_serrated_blades") { }

    class spell_rog_serrated_blades_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_serrated_blades_SpellScript);

        void HandleHit()
        {
            if (AuraEffect* blade = GetCaster()->GetAuraEffectOfRankedSpell(SPELL_ROGUE_SERRATED_BLADES_R1, EFFECT_0))
            {
                uint32 combo = GetCaster()->ToPlayer()->GetComboPoints();

                if (roll_chance_i(blade->GetAmount() * combo))
                    if (Aura* dot = GetHitUnit()->GetAura(SPELL_ROGUE_RUPTURE, GetCaster()->GetGUID()))
                        dot->RefreshDuration();

            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_rog_serrated_blades_SpellScript::HandleHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_serrated_blades_SpellScript();
    }
};

// Kidney Shot - 408
class spell_rog_kidney_shot :public SpellScript
{
    PrepareSpellScript(spell_rog_kidney_shot);

    void HandleTakePower(SpellPowerCost& powerCost)
    {
        if (powerCost.Power == POWER_COMBO_POINTS)
            _cp = powerCost.Amount + 1;
    }

    void HandleAfterHit()
    {
        if (Unit* target = GetHitUnit())
            if (Aura* aura = target->GetAura(SPELL_ROGUE_KIDNEY_SHOT, GetCaster()->GetGUID()))
                aura->SetDuration(_cp * IN_MILLISECONDS);
    }

    void Register() override
    {
        OnTakePower += SpellOnTakePowerFn(spell_rog_kidney_shot::HandleTakePower);
        AfterHit += SpellHitFn(spell_rog_kidney_shot::HandleAfterHit);
    }
private:
    uint8 _cp = 0;
};

// Blade Flurry
class spell_rogue_blade_flurry : public SpellScriptLoader
{
public:
    spell_rogue_blade_flurry() : SpellScriptLoader("spell_rogue_blade_flurry") { }

    class spell_rogue_blade_flurry_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rogue_blade_flurry_SpellScript);

        void HandleOnHit()
        {
            if (GetHitUnit() == GetExplTargetUnit())
                SetHitDamage(0);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_rogue_blade_flurry_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rogue_blade_flurry_SpellScript();
    }
};

enum CombatPotency
{
    SPELL_ROGUE_COMBAT_POTENCY = 35551
};

// 35551 - Combat Potency
class spell_rogue_combat_potency : public SpellScriptLoader
{
public:
    spell_rogue_combat_potency() : SpellScriptLoader("spell_rogue_combat_potency") { }

    class spell_rogue_combat_potency_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rogue_combat_potency_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            bool offHand = (eventInfo.GetDamageInfo()->GetAttackType() == OFF_ATTACK && roll_chance_i(20));
            float mainRollChance = 20.f * GetCaster()->getAttackTimer(BASE_ATTACK) / 1.4f / 600.f;
            bool mainHand = (eventInfo.GetDamageInfo()->GetAttackType() == BASE_ATTACK && roll_chance_f(mainRollChance));
            return offHand || mainHand;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_rogue_combat_potency_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rogue_combat_potency_AuraScript();
    }
};

class spell_rog_deadly_throw : public SpellScriptLoader
{
public:
    spell_rog_deadly_throw() : SpellScriptLoader("spell_rog_deadly_throw") { }

    class spell_rog_deadly_throw_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_deadly_throw_SpellScript);

        void HandleOnHit()
        {
            if (Unit* target = GetHitUnit())
                if (Player* caster = GetCaster()->ToPlayer())
                    if (caster->GetComboPoints() >= 5)
                        caster->CastSpell(target, 137576, true);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_rog_deadly_throw_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_deadly_throw_SpellScript();
    }
};

class spell_rog_deadly_poison_instant_damage : public SpellScriptLoader
{
public:
    spell_rog_deadly_poison_instant_damage() : SpellScriptLoader("spell_rog_deadly_poison_instant_damage") { }

    class spell_rog_deadly_poison_instant_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_deadly_poison_instant_damage_SpellScript);

        void HandleOnCast()
        {
            if (Player* _player = GetCaster()->ToPlayer())
                if (Unit* target = GetExplTargetUnit())
                    if (target->HasAura(SPELL_ROGUE_DEADLY_POISON_DOT, _player->GetGUID()))
                        _player->CastSpell(target, SPELL_ROGUE_DEADLY_POISON_INSTANT_DAMAGE, true);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_rog_deadly_poison_instant_damage_SpellScript::HandleOnCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_deadly_poison_instant_damage_SpellScript();
    }
};

class spell_rog_hemorrhage : public SpellScriptLoader
{
public:
    spell_rog_hemorrhage() : SpellScriptLoader("spell_rog_hemorrhage") { }

    class spell_rog_hemorrhage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_hemorrhage_SpellScript);

        bool Load() override
        {
            bleeding = false;
            return true;
        }

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (GetHitUnit())
                {
                    if (_player->HasAura(SPELL_ROGUE_GLYPH_OF_HEMORRHAGE))
                    {
                        if (!bleeding)
                        {
                            PreventHitAura();
                            return;
                        }
                    }
                }
            }
        }

        void CheckBleed(SpellMissInfo /*missInfo*/)
        {
            if (Unit* target = GetHitUnit())
                bleeding = target->HasAuraState(AURA_STATE_BLEEDING);
        }

        void RemoveCP()
        {
            Unit* caster = GetCaster();
            uint8 cp = caster->GetPower(POWER_COMBO_POINTS);

            if (cp > 0)
            {
                caster->SetPower(POWER_COMBO_POINTS, cp - 1);
            }
        }

        void Register() override
        {
            BeforeHit += BeforeSpellHitFn(spell_rog_hemorrhage_SpellScript::CheckBleed);
            OnHit += SpellHitFn(spell_rog_hemorrhage_SpellScript::HandleOnHit);
            AfterHit += SpellHitFn(spell_rog_hemorrhage_SpellScript::RemoveCP);
        }
        bool bleeding;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_hemorrhage_SpellScript();
    }
};

class spell_rog_nerve_strike : public SpellScriptLoader
{
public:
    spell_rog_nerve_strike() : SpellScriptLoader("spell_rog_nerve_strike") { }

    class spell_rog_combat_readiness_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_combat_readiness_AuraScript);

        void HandleRemove(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /* mode */)
        {
            if (GetCaster() && GetTarget())
                if (GetCaster()->HasAura(SPELL_ROGUE_NERVE_STRIKE_AURA))
                    GetCaster()->CastSpell(GetTarget(), SPELL_ROGUE_NERVE_STRIKE_REDUCE_DAMAGE_DONE, true);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_rog_combat_readiness_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_combat_readiness_AuraScript();
    }
};

class spell_rog_nerve_strike_aura : public SpellScriptLoader
{
public:
    spell_rog_nerve_strike_aura() : SpellScriptLoader("spell_rog_nerve_strike_aura") { }

    class spell_rog_nerve_strike_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_nerve_strike_aura_AuraScript);

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /* canBeRecalculated */)
        {
            if (Unit* target = GetUnitOwner())
                if (target->GetTypeId() == TYPEID_PLAYER)
                    amount = 25;
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_rog_nerve_strike_aura_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_nerve_strike_aura_AuraScript();
    }
};

class spell_rog_nightstalker : public SpellScriptLoader
{
public:
    spell_rog_nightstalker() : SpellScriptLoader("spell_rog_nightstalker") { }

    class spell_rog_nightstalker_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_nightstalker_AuraScript);

        void HandleApply(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /* mode */)
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->HasAura(SPELL_ROGUE_NIGHTSTALKER_AURA))
                    caster->CastSpell(caster, SPELL_ROGUE_NIGHTSTALKER_DAMAGE_DONE, true);

                if (caster->HasAura(SPELL_ROGUE_SHADOW_FOCUS_AURA))
                    caster->CastSpell(caster, SPELL_ROGUE_SHADOW_FOCUS_COST_PCT, true);
            }
        }

        void HandleRemove(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /* mode */)
        {
            if (GetCaster())
            {
                if (GetCaster()->HasAura(SPELL_ROGUE_NIGHTSTALKER_DAMAGE_DONE))
                    GetCaster()->RemoveAura(SPELL_ROGUE_NIGHTSTALKER_DAMAGE_DONE);

                if (GetCaster()->HasAura(SPELL_ROGUE_SHADOW_FOCUS_COST_PCT))
                    GetCaster()->RemoveAura(SPELL_ROGUE_SHADOW_FOCUS_COST_PCT);
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_rog_nightstalker_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_rog_nightstalker_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_nightstalker_AuraScript();
    }
};

class spell_rog_dirty_tricks : public SpellScriptLoader
{
public:
    spell_rog_dirty_tricks() : SpellScriptLoader("spell_rog_dirty_tricks") { }

    class spell_rog_dirty_tricks_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_dirty_tricks_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            const SpellInfo* spellInfo = eventInfo.GetDamageInfo()->GetSpellInfo();
            if (!spellInfo)
                return true;

            if (eventInfo.GetActor()->GetGUID() != GetCasterGUID())
                return true;

            if (spellInfo->Mechanic == MECHANIC_BLEED || spellInfo->GetAllEffectsMechanicMask() & MECHANIC_BLEED || spellInfo->Dispel == DISPEL_POISON)
                if (eventInfo.GetActor()->HasAura(108216))
                    return false;

            return true;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_rog_dirty_tricks_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_dirty_tricks_AuraScript();
    }
};

class spell_rog_poisons : public SpellScriptLoader
{
public:
    spell_rog_poisons() : SpellScriptLoader("spell_rog_poisons") { }

    class spell_rog_poisons_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_poisons_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                switch (GetSpellInfo()->Id)
                {
                    case SPELL_ROGUE_WOUND_POISON:
                    {
                        if (_player->HasAura(SPELL_ROGUE_DEADLY_POISON))
                            _player->RemoveAura(SPELL_ROGUE_DEADLY_POISON);
                        break;
                    }
                    case SPELL_ROGUE_MIND_NUMBLING_POISON:
                    {
                        if (_player->HasAura(SPELL_ROGUE_CRIPPLING_POISON))
                            _player->RemoveAura(SPELL_ROGUE_CRIPPLING_POISON);
                        if (_player->HasAura(SPELL_ROGUE_LEECHING_POISON))
                            _player->RemoveAura(SPELL_ROGUE_LEECHING_POISON);
                        if (_player->HasAura(SPELL_ROGUE_PARALYTIC_POISON))
                            _player->RemoveAura(SPELL_ROGUE_PARALYTIC_POISON);
                        break;
                    }
                    case SPELL_ROGUE_CRIPPLING_POISON:
                    {
                        if (_player->HasAura(SPELL_ROGUE_MIND_NUMBLING_POISON))
                            _player->RemoveAura(SPELL_ROGUE_MIND_NUMBLING_POISON);
                        if (_player->HasAura(SPELL_ROGUE_LEECHING_POISON))
                            _player->RemoveAura(SPELL_ROGUE_LEECHING_POISON);
                        if (_player->HasAura(SPELL_ROGUE_PARALYTIC_POISON))
                            _player->RemoveAura(SPELL_ROGUE_PARALYTIC_POISON);
                        break;
                    }
                    case SPELL_ROGUE_LEECHING_POISON:
                    {
                        if (_player->HasAura(SPELL_ROGUE_MIND_NUMBLING_POISON))
                            _player->RemoveAura(SPELL_ROGUE_MIND_NUMBLING_POISON);
                        if (_player->HasAura(SPELL_ROGUE_CRIPPLING_POISON))
                            _player->RemoveAura(SPELL_ROGUE_CRIPPLING_POISON);
                        if (_player->HasAura(SPELL_ROGUE_PARALYTIC_POISON))
                            _player->RemoveAura(SPELL_ROGUE_PARALYTIC_POISON);
                        break;
                    }
                    case SPELL_ROGUE_PARALYTIC_POISON:
                    {
                        if (_player->HasAura(SPELL_ROGUE_MIND_NUMBLING_POISON))
                            _player->RemoveAura(SPELL_ROGUE_MIND_NUMBLING_POISON);
                        if (_player->HasAura(SPELL_ROGUE_CRIPPLING_POISON))
                            _player->RemoveAura(SPELL_ROGUE_CRIPPLING_POISON);
                        if (_player->HasAura(SPELL_ROGUE_LEECHING_POISON))
                            _player->RemoveAura(SPELL_ROGUE_LEECHING_POISON);
                        break;
                    }
                    case SPELL_ROGUE_DEADLY_POISON:
                    {
                        if (_player->HasAura(SPELL_ROGUE_WOUND_POISON))
                            _player->RemoveAura(SPELL_ROGUE_WOUND_POISON);
                        break;
                    }
                    default:
                        break;
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_rog_poisons_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_poisons_SpellScript();
    }
};

class spell_rog_cloak_and_dagger : public SpellScriptLoader
{
public:
    spell_rog_cloak_and_dagger() : SpellScriptLoader("spell_rog_cloak_and_dagger") { }

    class spell_rog_cloak_and_dagger_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_cloak_and_dagger_SpellScript);

        SpellCastResult CheckCast()
        {
            if (Unit* caster = GetCaster())
                if (caster->HasAuraType(SPELL_AURA_MOD_STEALTH))
                    if (caster->HasAura(138106))
                        if (Unit* target = GetExplTargetUnit())
                            caster->CastSpell(target, 138916, true);

            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_rog_cloak_and_dagger_SpellScript::CheckCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_cloak_and_dagger_SpellScript();
    }
};

// static uint32 spell_rog_restless_blades_reducedCooldownsSpells[5] = { SPELL_ROGUE_ADRENALINE_RUSH, SPELL_ROGUE_KILLING_SPREE, SPELL_ROGUE_REDIRECT, SPELL_ROGUE_SHADOW_BLADES, SPELL_ROGUE_SPRINT };

class spell_rog_slice_and_dice : public SpellScriptLoader
{
public:
    spell_rog_slice_and_dice() : SpellScriptLoader("spell_rog_slice_and_dice") { }

    class spell_rog_slice_and_dice_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_slice_and_dice_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Aura* sliceAndDice = _player->GetAura(SPELL_ROGUE_SLICE_AND_DICE))
                {
                    int32 duration = sliceAndDice->GetDuration();
                    int32 maxDuration = sliceAndDice->GetMaxDuration();

                    // Replace old duration of Slice and Dice by the new duration ...
                    // ... five combo points : 36s instead of 30s
                    if (maxDuration >= 30000)
                    {
                        sliceAndDice->SetDuration(duration + 6000);
                        sliceAndDice->SetMaxDuration(maxDuration + 6000);
                    }
                    // ... four combo points : 30s instead of 25s
                    else if (maxDuration >= 25000)
                    {
                        sliceAndDice->SetDuration(duration + 5000);
                        sliceAndDice->SetMaxDuration(maxDuration + 5000);
                    }
                    // ... three combo points : 24s instead of 20s
                    else if (maxDuration >= 20000)
                    {
                        sliceAndDice->SetDuration(duration + 4000);
                        sliceAndDice->SetMaxDuration(maxDuration + 4000);
                    }
                    // ... two combo points : 18s instead of 15s
                    else if (maxDuration >= 15000)
                    {
                        sliceAndDice->SetDuration(duration + 3000);
                        sliceAndDice->SetMaxDuration(maxDuration + 3000);
                    }
                    // ... one combo point : 12s instead of 10s
                    else
                    {
                        sliceAndDice->SetDuration(duration + 2000);
                        sliceAndDice->SetMaxDuration(maxDuration + 2000);
                    }
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_rog_slice_and_dice_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_slice_and_dice_SpellScript();
    }
};

// 79134 - Venomous Wounds
class aura_rog_venomous_wounds : public AuraScript
{
    PrepareAuraScript(aura_rog_venomous_wounds);

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*procInfo*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        int32 energyGain = GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints;
        if (caster->HasAura(SPELL_ROGUE_VENOM_RUSH))
            energyGain += sSpellMgr->GetSpellInfo(SPELL_ROGUE_VENOM_RUSH)->GetEffect(EFFECT_0)->BasePoints;

        caster->ModifyPower(POWER_ENERGY, energyGain);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(aura_rog_venomous_wounds::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 51701 - Honor Among Thieves
class spell_rog_honor_among_thieves : public SpellScriptLoader
{
public:
    spell_rog_honor_among_thieves() : SpellScriptLoader("spell_rog_honor_among_thieves") { }

    class spell_rog_honor_among_thieves_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_honor_among_thieves_AuraScript);

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();

            Unit* target = GetUnitOwner();
            target->CastSpell(target, SPELL_ROGUE_HONOR_AMONG_THIEVES_PROC, TRIGGERED_FULL_MASK, nullptr, aurEff);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_rog_honor_among_thieves_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_honor_among_thieves_AuraScript();
    }
};

// 2098 - Run Through and 196819 - Eviscerate
class spell_rog_eviscerate : public SpellScript
{
    PrepareSpellScript(spell_rog_eviscerate);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_EVISCERATE });
    }

    void CalcDamage(SpellEffIndex /*effIndex*/)
    {
        int32 finalDamage = GetHitDamage();

        if (SpellPowerCost const* powerCost = GetSpell()->GetPowerCost(POWER_COMBO_POINTS))
            finalDamage *= powerCost->Amount;

        SetHitDamage(finalDamage);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rog_eviscerate::CalcDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 32645 - Envenom
class spell_rog_envenom : public SpellScript
{
    PrepareSpellScript(spell_rog_envenom);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_ENVENOM });
    }

    void CalculateDamage(SpellEffIndex /*effIndex*/)
    {
        int32 finalDamage = GetHitDamage();

        if (SpellPowerCost const* powerCost = GetSpell()->GetPowerCost(POWER_COMBO_POINTS))
            finalDamage *= powerCost->Amount;

        SetHitDamage(finalDamage);
    }

    void HandleAfterHit()
    {
        if (Aura* envenomAura = GetCaster()->GetAura(GetSpellInfo()->Id))
            if (SpellPowerCost const* powerCost = GetSpell()->GetPowerCost(POWER_COMBO_POINTS))
                envenomAura->SetDuration((powerCost->Amount + 1) * IN_MILLISECONDS);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rog_envenom::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        AfterHit += SpellHitFn(spell_rog_envenom::HandleAfterHit);
    }
};

// Shuriken Storm - 197835
class spell_rog_shuriken_storm : public SpellScriptLoader
{
public:
    spell_rog_shuriken_storm() : SpellScriptLoader("spell_rog_shuriken_storm") {}

    class spell_rog_shuriken_storm_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_shuriken_storm_SpellScript);

    public:
        spell_rog_shuriken_storm_SpellScript()
        {
            _stealthed = false;
        }

    private:

        bool _stealthed;

        bool Load() override
        {
            Unit* caster = GetCaster();
            if (caster->HasAuraType(SPELL_AURA_MOD_STEALTH) || caster->HasAura(SPELL_ROGUE_SHADOW_DANCE))
                _stealthed = true;
            return true;
        }

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_ROGUE_SHURIKEN_STORM
            });
        }

        void RemoveKS()
        {
            Unit* target = GetHitUnit();
            if (target->HasAura(51690)) //Killing spree debuff #1
                target->RemoveAura(51690);
            if (target->HasAura(61851)) //Killing spree debuff #2
                target->RemoveAura(61851);
        }

        void AddComboPoint()
        {
            Unit* caster = GetCaster();
            uint8 cp = caster->GetPower(POWER_COMBO_POINTS);
            if (_stealthed)
            {
                int32 dmg = GetHitDamage();
                SetHitDamage(dmg * 2); //Shuriken Storm deals 200% damage from stealth
            }
            if (cp < caster->GetMaxPower(POWER_COMBO_POINTS))
            {
                caster->SetPower(POWER_COMBO_POINTS, cp + 1);
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_rog_shuriken_storm_SpellScript::AddComboPoint); //add 1 combo points for each target (hook called for each target in map)
            AfterHit += SpellHitFn(spell_rog_shuriken_storm_SpellScript::RemoveKS);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_shuriken_storm_SpellScript();
    }
};

// Fan of Knives - 51723
class spell_rog_fan_of_knives : public SpellScriptLoader
{
public:
    spell_rog_fan_of_knives() : SpellScriptLoader("spell_rog_fan_of_knives") {}

    class spell_rog_fan_of_knives_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_fan_of_knives_SpellScript);

    public:

        spell_rog_fan_of_knives_SpellScript()
        {
            _hit = false;
        }

    private:

        bool _hit;

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_ROGUE_FAN_OF_KNIVES
            });
        }

        bool Load() override
        {
            return true;
        }

        void AddCp()
        {
            if (!_hit)
            {
                uint8 cp = GetCaster()->GetPower(POWER_COMBO_POINTS);
                if (cp < GetCaster()->GetMaxPower(POWER_COMBO_POINTS))
                {
                    GetCaster()->SetPower(POWER_COMBO_POINTS, cp + 1);
                }
                _hit = true;
            }
        }

        void RemoveKS()
        {
            Unit* target = GetHitUnit();
            if (target->HasAura(51690)) //Killing spree debuff #1
                target->RemoveAura(51690);
            if (target->HasAura(61851)) //Killing spree debuff #2
                target->RemoveAura(61851);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_rog_fan_of_knives_SpellScript::AddCp);
            AfterHit += SpellHitFn(spell_rog_fan_of_knives_SpellScript::RemoveKS);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_fan_of_knives_SpellScript();
    }
};

// Shadowstrike - 185438
class spell_rog_shadowstrike : public SpellScriptLoader
{
public:
    spell_rog_shadowstrike() : SpellScriptLoader("spell_rog_shadowstrike") {}

    class spell_rog_shadowstrike_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_shadowstrike_SpellScript);

        enum UsedSpells
        {
            SPELL_ROGUE_STRIKE_FROM_THE_SHADOWS_SLOW = 222775,
            SPELL_ROGUE_STRIKE_FROM_THE_SHADOWS_STUN = 196958
        };

        bool Validate(SpellInfo const* /*SpellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_ROGUE_SHADOWSTRIKE,
                SPELL_ROGUE_SHADOWSTEP_LEAP
            });
        }

        void LeapBehind()
        {
            if (Unit* target = GetExplTargetUnit())
            {
                GetCaster()->CastSpell(target, SPELL_ROGUE_SHADOWSTEP_LEAP, true);
            }
        }

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if(!caster)
                return;

            Unit* target = GetHitUnit();
            if(!target)
                return;

            if (caster->HasAura(SPELL_ROGUE_STRIKE_FROM_THE_SHADOWS))
            {
                if (target->GetTypeId() == TYPEID_PLAYER)
                    caster->CastSpell(target, SPELL_ROGUE_STRIKE_FROM_THE_SHADOWS_SLOW, true);
                else
                    caster->CastSpell(target, SPELL_ROGUE_STRIKE_FROM_THE_SHADOWS_STUN, true);
            }
        }

        void Register() override
        {
            BeforeCast += SpellCastFn(spell_rog_shadowstrike_SpellScript::LeapBehind);
            OnEffectHitTarget += SpellEffectFn(spell_rog_shadowstrike_SpellScript::HandleHitTarget, EFFECT_1, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_shadowstrike_SpellScript();
    }
};

class spell_rog_garrote : public SpellScriptLoader
{
public:
    spell_rog_garrote() : SpellScriptLoader("spell_rog_garrote") {}

    class spell_rog_garrote_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_garrote_SpellScript);

    public:
        spell_rog_garrote_SpellScript()
        {
            _stealthed = false;
        }

    private:

        bool _stealthed;

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_ROGUE_GARROTE_DOT,
                SPELL_ROGUE_GARROTE_SILENCE
            });
        }

        bool Load() override
        {
            if (GetCaster()->HasAuraType(SPELL_AURA_MOD_STEALTH))
                _stealthed = true;
            return true;
        }

        void HandleOnHit()
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();

            if (_stealthed)
            {
                caster->CastSpell(target, SPELL_ROGUE_GARROTE_SILENCE, true);
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_rog_garrote_SpellScript::HandleOnHit);
        }
    };

    class spell_rog_garrote_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_garrote_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_ROGUE_THUGGEE
            });
        }

        void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
                return;

            Unit* caster = GetAura()->GetCaster();

            if (!caster)
                return;

            if (!caster->HasAura(SPELL_ROGUE_THUGGEE))
                return;

            caster->GetSpellHistory()->ResetCooldown(SPELL_ROGUE_GARROTE_DOT, true);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_rog_garrote_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_garrote_SpellScript();
    }

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_garrote_AuraScript();
    }
};

// Saber slash - 193315
class spell_rog_saber_slash : public SpellScript
{
    PrepareSpellScript(spell_rog_saber_slash);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (!caster || !target)
            return;

        //Saber slash has 35% chance to strike again and make your next Pistol Shot free (buff called Opportunity)
        int32 chance = sSpellMgr->GetSpellInfo(SPELL_ROGUE_SABER_SLASH)->GetEffect(4)->BasePoints;

        //Jolly Roger increases the chance by 40%
        if (caster->HasAura(SPELL_ROGUE_JOLLY_ROGER))
            chance += sSpellMgr->GetSpellInfo(SPELL_ROGUE_JOLLY_ROGER)->GetEffect(0)->BasePoints;

        if (roll_chance_i(chance))
        {
            caster->CastSpell(caster, SPELL_ROGUE_OPPORTUNITY, true);

            SpellNonMeleeDamage dmg(caster, target, SPELL_ROGUE_SABER_SLASH, GetSpellInfo()->GetSpellXSpellVisualId(), GetSpellInfo()->SchoolMask);
            dmg.damage = GetHitDamage();
            caster->DealSpellDamage(&dmg, false);
            caster->SendSpellNonMeleeDamageLog(&dmg);

            caster->ModifyPower(POWER_COMBO_POINTS, 1);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rog_saber_slash::HandleHit, EFFECT_2, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
    }
};

// True Bearing - 193359
class spell_rog_true_bearing : public SpellScriptLoader
{
public:
    spell_rog_true_bearing() : SpellScriptLoader("spell_rog_true_bearing") {}

    class spell_rog_true_bearing_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_true_bearing_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            std::vector<uint32> finishers{ SPELL_ROGUE_BETWEEN_THE_EYES, SPELL_ROGUE_ROLL_THE_BONES, SPELL_ROGUE_EVISCERATE };
            for (uint32 finisher : finishers)
                if (eventInfo.GetSpellInfo()->Id == finisher)
                    return true;
            return false;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            int32 cp = caster->GetPower(POWER_COMBO_POINTS) + 1;

            std::vector<uint32> spellIds{ SPELL_ROGUE_ADRENALINE_RUSH, SPELL_ROGUE_SPRINT, SPELL_ROGUE_BETWEEN_THE_EYES,
                                          SPELL_ROGUE_VANISH, SPELL_ROGUE_BLIND, SPELL_ROGUE_CLOAK_OF_SHADOWS,
                                          SPELL_ROGUE_RIPOSTE, SPELL_ROGUE_GRAPPLING_HOOK, SPELL_ROGUE_CANNONBALL_BARRAGE,
                                          SPELL_ROGUE_KILLING_SPREE, SPELL_ROGUE_MARKED_FOR_DEATH, SPELL_ROGUE_DEATH_FROM_ABOVE };

            for (uint32 spell : spellIds)
            {
                if (caster->HasSpell(spell))
                    caster->GetSpellHistory()->ModifyCooldown(spell, -2000 * cp);
            }
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_rog_true_bearing_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_rog_true_bearing_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_true_bearing_AuraScript();
    }
};

//14161 - Ruthlessness
class spell_rog_ruthlessness : public SpellScriptLoader
{
public:
    spell_rog_ruthlessness() : SpellScriptLoader("spell_rog_ruthlessness") { }

    class spell_rog_ruthlessness_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_ruthlessness_AuraScript);

        uint8 _cp;

        bool Load() override
        {
            _cp = GetCaster()->GetPower(POWER_COMBO_POINTS);
            return true;
        }

        void HandleProc(ProcEventInfo& /*procInfo*/)
        {
            Unit* caster = GetCaster();
            if(!caster)
                return;

            if(roll_chance_i(20 * _cp))
                caster->ModifyPower(POWER_COMBO_POINTS, +1);
        }

        void Register() override
        {
            OnProc += AuraProcFn(spell_rog_ruthlessness_AuraScript::HandleProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_ruthlessness_AuraScript();
    }
};

//199754
class spell_rog_riposte : public SpellScriptLoader
{
public:
    spell_rog_riposte() : SpellScriptLoader("spell_rog_riposte") { }

    class spell_rog_riposte_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_riposte_AuraScript);

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& procInfo)
        {
            PreventDefaultAction();

            Unit* caster = GetCaster();
            if(!caster)
                return;

            Unit* target = procInfo.GetActionTarget();
            if(!target)
                return;
            caster->CastSpell(target, SPELL_ROGUE_RIPOSTE_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_rog_riposte_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_riposte_AuraScript();
    }
};

//185313 shadow dance
class spell_rog_shadow_dance : public SpellScriptLoader
{
public:
    spell_rog_shadow_dance() : SpellScriptLoader("spell_rog_shadow_dance") { }

    class spell_rog_shadow_dance_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_shadow_dance_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if(!caster)
                return;

            if (caster->HasAura(SPELL_ROGUE_MASTER_OF_SHADOWS))
                caster->ModifyPower(POWER_ENERGY, +30);

            caster->CastSpell(caster, SPELL_ROGUE_SHADOW_DANCE_AURA, true);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_rog_shadow_dance_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_shadow_dance_SpellScript();
    }
};

// Backstab - 53
class spell_rog_backstab : public SpellScriptLoader
{
public:
    spell_rog_backstab() : SpellScriptLoader("spell_rog_backstab") {}

    class spell_rog_backstab_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_backstab_SpellScript);

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* target = GetHitUnit();
            Unit* caster = GetCaster();
            if (!target || !caster)
                return;

            int32 dmg = GetHitDamage();
            if (!target->HasInArc(static_cast<float>(M_PI), caster))
                AddPct(dmg, 30);

            SetHitDamage(dmg);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_rog_backstab_SpellScript::HandleDamage, EFFECT_1, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_backstab_SpellScript();
    }
};

// Nightblade - 195452
class spell_rog_nightblade : public SpellScriptLoader
{
public:
    spell_rog_nightblade() : SpellScriptLoader("spell_rog_nightblade") {}

    class spell_rog_nightblade_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_nightblade_AuraScript);

        int8 _cp;

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            int32 maxcp = caster->HasAura(SPELL_ROGUE_DEEPER_STRATAGEM) ? 6 : 5;
            _cp = std::min(caster->GetPower(POWER_COMBO_POINTS) + 1, maxcp);

            if (Aura* aur = GetAura())
            {
                aur->SetMaxDuration(6000 + 2000 * _cp);
                aur->RefreshDuration();
            }
            if (Unit* caster = GetCaster())
                caster->ModifyPower(POWER_COMBO_POINTS, -1 * (_cp - 1));
            SpellCategoryEntry const* catEntry = sSpellCategoryStore.LookupEntry(sSpellMgr->GetSpellInfo(SPELL_ROGUE_SHADOW_DANCE)->ChargeCategoryId);
            if (GetCaster()->HasAura(SPELL_ROGUE_DEEPENING_SHADOWS) && roll_chance_i(20*_cp))
                GetCaster()->GetSpellHistory()->ReduceChargeCooldown(catEntry, _cp * 3000);

            if (Unit* caster = GetCaster())
                if (caster->HasAura(SPELL_ROGUE_RELENTLESS_STRIKES) && roll_chance_i(20*_cp))
                    caster->CastSpell(caster, SPELL_ROGUE_RELENTLESS_STRIKES_POWER, true);
            if (GetCaster()->HasAura(SPELL_ROGUE_ALACRITY) && roll_chance_i(20 * _cp))
                GetCaster()->CastSpell(GetCaster(), SPELL_ROGUE_ALACRITY_BUFF, true);
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetDamageInfo()->GetAttackType() == BASE_ATTACK ||
                eventInfo.GetDamageInfo()->GetAttackType() == OFF_ATTACK)
            {
                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetActionTarget();
                if (!caster || !target)
                    return false;

                caster->CastSpell(target, SPELL_ROGUE_NIGHTBLADE_SLOW, true);
                return true;
            }
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_rog_nightblade_AuraScript::CheckProc);
            AfterEffectApply += AuraEffectApplyFn(spell_rog_nightblade_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        }
    };

    class spell_rog_nightblade_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_nightblade_SpellScript);

        void HandleLaunch(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            target->RemoveAurasDueToSpell(SPELL_ROGUE_NIGHTBLADE, caster->GetGUID());
        }

        void Register() override
        {
            OnEffectLaunchTarget += SpellEffectFn(spell_rog_nightblade_SpellScript::HandleLaunch, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_nightblade_SpellScript();
    }

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_nightblade_AuraScript();
    }
};

// Deepening Shadows - 185314
class spell_rog_deepening_shadows : public SpellScriptLoader
{
public:
    spell_rog_deepening_shadows() : SpellScriptLoader("spell_rog_deepening_shadows") {}

    class spell_rog_deepening_shadows_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_deepening_shadows_AuraScript);

        int8 _cp;

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (Unit* caster = GetCaster())
            {
                int32 maxcp = caster->HasAura(SPELL_ROGUE_DEEPER_STRATAGEM) ? 6 : 5;
                _cp = std::min(caster->GetPower(POWER_COMBO_POINTS) + 1, maxcp);
            }
            if (eventInfo.GetSpellInfo()->Id == 196819)
                return true;
            return false;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            SpellCategoryEntry const* catEntry = sSpellCategoryStore.LookupEntry(sSpellMgr->GetSpellInfo(SPELL_ROGUE_SHADOW_DANCE)->ChargeCategoryId);
            if (GetCaster()->HasAura(SPELL_ROGUE_DEEPENING_SHADOWS))
                GetCaster()->GetSpellHistory()->ReduceChargeCooldown(catEntry, _cp * 3000);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_rog_deepening_shadows_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_rog_deepening_shadows_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_deepening_shadows_AuraScript();
    }
};

// Enveloping Shadows - 206237
class spell_rog_enveloping_shadows : public SpellScriptLoader
{
public:
    spell_rog_enveloping_shadows() : SpellScriptLoader("spell_rog_enveloping_shadows") {}

    class spell_rog_enveloping_shadows_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_enveloping_shadows_AuraScript);

        uint8 _cp;

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (!GetCaster())
                return;

            int32 maxcp = GetCaster()->HasAura(SPELL_ROGUE_DEEPER_STRATAGEM) ? 6 : 5;
            _cp = std::min(GetCaster()->GetPower(POWER_COMBO_POINTS) + 1, maxcp);

            GetCaster()->ModifyPower(POWER_COMBO_POINTS, -1 * (_cp - 1));
            if (Aura* aur = GetAura())
            {
                aur->SetMaxDuration(_cp * 6000);
                aur->RefreshDuration();
            }
            SpellCategoryEntry const* catEntry = sSpellCategoryStore.LookupEntry(sSpellMgr->GetSpellInfo(SPELL_ROGUE_SHADOW_DANCE)->ChargeCategoryId);
            if (GetCaster()->HasAura(SPELL_ROGUE_DEEPENING_SHADOWS))
                GetCaster()->GetSpellHistory()->ReduceChargeCooldown(catEntry, _cp * 3000);
            if (GetCaster()->HasAura(SPELL_ROGUE_RELENTLESS_STRIKES) && roll_chance_i(20*_cp))
                GetCaster()->CastSpell(GetCaster(), SPELL_ROGUE_RELENTLESS_STRIKES_POWER, true);
            if (GetCaster()->HasAura(SPELL_ROGUE_ALACRITY) && roll_chance_i(20 * _cp))
                GetCaster()->CastSpell(GetCaster(), SPELL_ROGUE_ALACRITY_BUFF, true);
        }

        void Register() override
        {

            AfterEffectApply += AuraEffectApplyFn(spell_rog_enveloping_shadows_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        }
    };

    class spell_rog_enveloping_shadows_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_enveloping_shadows_SpellScript);

        void HandleLaunch(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            target->RemoveAurasDueToSpell(SPELL_ROGUE_ENVELOPING_SHADOWS, caster->GetGUID());
        }

        void Register() override
        {
            OnEffectLaunchTarget += SpellEffectFn(spell_rog_enveloping_shadows_SpellScript::HandleLaunch, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_enveloping_shadows_SpellScript();
    }

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_enveloping_shadows_AuraScript();
    }
};

// Shadow Techniques - 196912
class spell_rog_shadow_techniques : public SpellScriptLoader
{
public:
    spell_rog_shadow_techniques() : SpellScriptLoader("spell_rog_shadow_techniques") {}

    class spell_rog_shadow_techniques_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_shadow_techniques_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetDamageInfo()->GetAttackType() == BASE_ATTACK)
                return true;
            return false;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (roll_chance_i(40))
                caster->CastSpell(caster, SPELL_ROGUE_SHADOW_TENCHNIQUES_POWER, true);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_rog_shadow_techniques_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_rog_shadow_techniques_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_shadow_techniques_AuraScript();
    }
};

// Weaponmaster - 193537
class spell_rog_weaponmaster : public SpellScriptLoader
{
public:
    spell_rog_weaponmaster() : SpellScriptLoader("spell_rog_weaponmaster") {}

    class spell_rog_weaponmaster_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_weaponmaster_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            Unit* caster = eventInfo.GetActor();
            Unit* target = eventInfo.GetActionTarget();
            if (!target || !caster)
                return false;

            SpellInfo const* triggerSpell = eventInfo.GetSpellInfo();
            if (!triggerSpell)
                return false;

            if (!roll_chance_i(6))
                return false;

            if (!eventInfo.GetDamageInfo())
                return false;

            SpellNonMeleeDamage damageLog(caster, target, triggerSpell->Id, triggerSpell->GetSpellXSpellVisualId(), triggerSpell->SchoolMask);
            damageLog.damage = eventInfo.GetDamageInfo()->GetDamage();
            damageLog.cleanDamage = damageLog.damage;
            caster->DealSpellDamage(&damageLog, true);
            caster->SendSpellNonMeleeDamageLog(&damageLog);
            return true;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_rog_weaponmaster_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_weaponmaster_AuraScript();
    }
};

// Alacrity - 193539
class spell_rog_alacrity : public SpellScriptLoader
{
public:
    spell_rog_alacrity() : SpellScriptLoader("spell_rog_alacrity") {}

    class spell_rog_alacrity_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_alacrity_AuraScript);

        bool CheckProc(ProcEventInfo& /*eventInfo*/)
        {
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_rog_alacrity_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_alacrity_AuraScript();
    }
};

// Smoke Bomb - 212182
// AreaTriggerID - 6951
class at_rog_smoke_bomb : public AreaTriggerEntityScript
{
public:

    at_rog_smoke_bomb() : AreaTriggerEntityScript("at_rog_smoke_bomb")
    {
    }

    struct at_rog_smoke_bombAI : AreaTriggerAI
    {
        at_rog_smoke_bombAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (!caster->ToPlayer())
                return;

            if (caster->IsValidAssistTarget(unit))
                caster->CastSpell(unit, SPELL_ROGUE_SMOKE_BOMB_AURA, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (!caster->ToPlayer())
                return;

            if (unit->HasAura(SPELL_ROGUE_SMOKE_BOMB_AURA))
                unit->RemoveAurasDueToSpell(SPELL_ROGUE_SMOKE_BOMB_AURA);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_rog_smoke_bombAI(areatrigger);
    }
};

void AddSC_rogue_spell_scripts()
{
    ///AreaTriggerScript
    new at_rog_smoke_bomb();

    ///SpellScripts
    new spell_rog_alacrity();
    new spell_rog_backstab();
    RegisterSpellScript(spell_rog_between_the_eyes);
    new spell_rog_blade_flurry();
    new spell_rog_cannonball_barrage();
    new spell_rog_cheat_death();
    new spell_rog_cloak_and_dagger();
    new spell_rog_deadly_poison();
    new spell_rog_deadly_poison_instant_damage();
    new spell_rog_deadly_throw();
    new spell_rog_deepening_shadows();
    new spell_rog_dirty_tricks();
    new spell_rog_enveloping_shadows();
    RegisterSpellScript(spell_rog_envenom);
    RegisterSpellScript(spell_rog_eviscerate);
    new spell_rog_fan_of_knives();
    new spell_rog_garrote();
    new spell_rog_grappling_hook();
    new spell_rog_hemorrhage();
    RegisterSpellScript(spell_rog_kidney_shot);
    new spell_rog_killing_spree();
    new spell_rog_nerve_strike();
    new spell_rog_nerve_strike_aura();
    new spell_rog_nightblade();
    new spell_rog_nightstalker();
    new spell_rog_poisons();
    new spell_rog_riposte();
    new spell_rog_roll_the_bones();
    new spell_rog_roll_the_bones_duration();
    new spell_rog_roll_the_bones_visual();
    new spell_rog_ruthlessness();
    RegisterSpellScript(spell_rog_rupture);
    RegisterSpellScript(spell_rog_saber_slash);
    new spell_rog_serrated_blades();
    new spell_rog_shadowstrike();
    new spell_rog_shadow_dance();
    new spell_rog_shadow_techniques();
    new spell_rog_shuriken_storm();
    new spell_rog_slice_and_dice();
    new spell_rog_stealth();
    new spell_rog_subterfuge();
    new spell_rog_true_bearing();
    new spell_rog_vanish();
    new spell_rog_vanish_aura();
    RegisterAuraScript(aura_rog_venomous_wounds);
    new spell_rogue_blade_flurry();
    new spell_rogue_combat_potency();
    new spell_rog_weaponmaster();
}
