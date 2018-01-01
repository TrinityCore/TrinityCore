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
* Scripts for spells with SPELLFAMILY_PALADIN and SPELLFAMILY_GENERIC spells used by paladin players.
* Ordered alphabetically using scriptname.
* Scriptnames of files in this file should be prefixed with "spell_pal_".
*/

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Creature.h"
#include "Group.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"

enum PaladinSpells
{
    SPELL_PALADIN_AVENGERS_SHIELD                = 31935,
    SPELL_PALADIN_BEACON_OF_LIGHT_MARKER         = 53563,
    SPELL_PALADIN_BEACON_OF_LIGHT_HEAL           = 53652,
    SPELL_PALADIN_FORBEARANCE                    = 25771,
    SPELL_PALADIN_HAND_OF_SACRIFICE              = 6940,
    SPELL_PALADIN_HOLY_SHOCK_GENERIC             = 20473,
    SPELL_PALADIN_HOLY_SHOCK_DAMAGE              = 25912,
    SPELL_PALADIN_HOLY_SHOCK_HEAL                = 25914,
    SPELL_PALADIN_HOLY_PRISM_ALLIES              = 114871,
    SPELL_PALADIN_HOLY_PRISM_DAMAGE_VISUAL       = 114862,
    SPELL_PALADIN_HOLY_PRISM_DAMAGE_VISUAL_2     = 114870,
    SPELL_PALADIN_HOLY_PRISM_ENNEMIES            = 114852,
    SPELL_PALADIN_HOLY_PRISM_HEAL_VISUAL         = 121551,
    SPELL_PALADIN_HOLY_PRISM_HEAL_VISUAL_2       = 121552,
    SPELL_PALADIN_JUDGMENT                       = 20271,
    SPELL_PALADIN_CONSECRATION                   = 26573,
    SPELL_PALADIN_CONSECRATION_DAMAGE            = 81297,
    SPELL_PALADIN_CONSECRATION_HEAL              = 204241,
    SPELL_PALADIN_CONSECRATION_INCREASE_SPEED    = 204242, // Need impentation
    SPELL_PALADIN_CONSECRATED_GROUND             = 204054,
    SPELL_PALADIN_HOLY_LIGHT                     = 82326,
    SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS        = 53600,
    SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS_PROC   = 132403,
    SPELL_PALADIN_TEMPLARS_VERDICT_DAMAGE        = 224266,
    SPELL_PALADIN_LIGHT_OF_THE_MARTYR_DAMAGE     = 196917,
    SPELL_PALADIN_LIGHT_OF_THE_PROTECTOR         = 184092,
    SPELL_PALADIN_HAND_OF_THE_PROTECTOR          = 213652,
    SPELL_PALADIN_INFUSION_OF_LIGHT_AURA         = 54149,
    SPELL_PALADIN_RIGHTEOUS_PROTECTOR            = 204074,
    SPELL_PALADIN_AVENGING_WRATH                 = 31884,
    SPELL_PALADIN_LIGHT_OF_DAWN                  = 85222,
    SPELL_PALADIN_LIGHT_OF_DAWN_TRIGGER          = 185984,
    SPELL_PALADIN_CRUSADERS_MIGHT                = 196926,
    SPELL_PALADIN_GRAND_CRUSADER                 = 85043,
    SPELL_PALADIN_CRUSADERS_JUDGMENT             = 204023,
    SPELL_PALADIN_DIVINE_STEED_SPEED             = 220509,
    SPELL_PALADIN_DIVINE_STEED_HUMAN             = 221883,
    SPELL_PALADIN_DIVINE_STEED_DRAENEI           = 221887,
    SPELL_PALADIN_DIVINE_STEED_BLOODELF          = 221886,
    SPELL_PALADIN_DIVINE_STEED_TAUREN            = 221885,
    SPELL_PALADIN_BLINDING_LIGHT_CONFUSE         = 105421,
    SPELL_PALADIN_DIVINE_STORM_DUMMY             = 174333,
    SPELL_PALADIN_DIVINE_STORM_DAMAGE            = 224239,
    SPELL_PALADIN_DIVINE_INTERVENTION_HEAL       = 184250,
    SPELL_PALADIN_DIVINE_SHIELD                  = 642,
    SPELL_PALADIN_WORD_OF_GLORY_HEAL             = 214894,
    SPELL_PALADIN_DIVINE_PURPOSE_RET             = 223817,
    SPELL_PALADIN_DIVINE_PURPOSE_HOLY            = 197646,
    SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA        = 223819,
    SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_1     = 216411,
    SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_2     = 216413,
    SPELL_PALADIN_THE_FIRES_OF_JUSTICE           = 209785,
    SPELL_PALADIN_CRUSADER_STRIKE                = 35395,
    SPELL_PALADIN_SEAL_OF_LIGHT                  = 213757,
    SPELL_PALADIN_DIVINE_STORM                   = 53385,
    SPELL_PALADIN_JUSTICARS_VENGEANCE            = 215661,
    SPELL_PALADIN_WORD_OF_GLORY                  = 210191,
    SPELL_PALADIN_EXECUTE_SENTENCE               = 213757,
    SPELL_PALADIN_TEMPLARS_VERDICT               = 85256,
    SPELL_PALADIN_HAMMER_OF_JUSTICE              = 853,
    SPELL_PALADIN_FIST_OF_JUSTICE                = 198054,
    SPELL_PALADIN_FINAL_STAND                    = 204077,
    SPELL_PALADIN_FINAL_STAND_TAUNT              = 204079,
    SPELL_PALADIN_JUDGMENT_OF_LIGHT_HEAL         = 183811,
    SPELL_PALADIN_RETRIBUTION_AURA_DAMAGE        = 204011,
    SPELL_PALADIN_HAMMER_OF_THE_RIGHTEOUS        = 53595,
    SPELL_PALDIN_BLESSED_HAMMER                  = 204019,
    SPELL_PALADIN_LIGHTS_HAMMER_TICK             = 114918,
    SPELL_PALADIN_LIGHT_HAMMER_COSMETIC          = 122257,
    SPELL_PALADIN_ARCING_LIGHT_HEAL              = 119952,
    SPELL_PALADIN_ARCING_LIGHT_DAMAGE            = 114919,
    SPELL_PALADIN_BLADE_OF_JUSTICE               = 184575,
    SPELL_PALADIN_GREATER_BLESSING_OF_KINGS      = 203538,
    SPELL_PALADIN_DIVINE_HAMMER                  = 198034,
    SPELL_PALADIN_ARDENT_DEFENDER                = 31850,
    SPELL_PALADIN_ARDENT_DEFENDER_HEAL           = 66235,
    SPELL_PALADIN_SERAPHIM                       = 152262,
};

enum PaladinNPCs
{
    NPC_PALADIN_LIGHTS_HAMMER = 59738
};

// 216860 - Judgement of the Pure
class spell_pal_judgement_of_the_pure : public SpellScriptLoader
{
public:
    spell_pal_judgement_of_the_pure() : SpellScriptLoader("spell_pal_judgement_of_the_pure") {}

    class spell_pal_judgement_of_the_pure_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_judgement_of_the_pure_AuraScript);

        bool HandleProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->Id == SPELL_PALADIN_JUDGMENT)
                return true;
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_pal_judgement_of_the_pure_AuraScript::HandleProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_judgement_of_the_pure_AuraScript();
    }
};


// 6940 - Hand of Sacrifice
class spell_pal_hand_of_sacrifice : public SpellScriptLoader
{
public:
    spell_pal_hand_of_sacrifice() : SpellScriptLoader("spell_pal_hand_of_sacrifice") { }

    class spell_pal_hand_of_sacrifice_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_hand_of_sacrifice_AuraScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_HAND_OF_SACRIFICE))
                return false;
            return true;
        }

        int32 remainingAmount;

        bool Load() override
        {
            if (Unit* caster = GetCaster())
            {
                remainingAmount = caster->GetMaxHealth();
                return true;
            }
            return false;
        }

        void Split(AuraEffect* /*aurEff*/, DamageInfo & /*dmgInfo*/, uint32 & splitAmount)
        {
            remainingAmount -= splitAmount;

            if (remainingAmount <= 0)
            {
                GetTarget()->RemoveAura(SPELL_PALADIN_HAND_OF_SACRIFICE);
            }
        }

        void Register() override
        {
            OnEffectSplit += AuraEffectSplitFn(spell_pal_hand_of_sacrifice_AuraScript::Split, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_hand_of_sacrifice_AuraScript();
    }
};

// Holy Shock - 20473
class spell_pal_holy_shock : public SpellScriptLoader
{
public:
    spell_pal_holy_shock() : SpellScriptLoader("spell_pal_holy_shock") { }

    class spell_pal_holy_shock_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_holy_shock_SpellScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_SHOCK_HEAL) || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_SHOCK_DAMAGE))
                return false;
            return true;
        }

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            if (Unit* target = GetExplTargetUnit())
            {
                if (!caster->IsFriendlyTo(target))
                {
                    if (!caster->IsValidAttackTarget(target))
                        return SPELL_FAILED_BAD_TARGETS;

                    if (!caster->isInFront(target))
                        return SPELL_FAILED_UNIT_NOT_INFRONT;
                }
            }
            else
                return SPELL_FAILED_BAD_TARGETS;
            return SPELL_CAST_OK;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Player* caster = GetCaster()->ToPlayer())
            {
                if (Unit* unitTarget = GetHitUnit())
                {
                    if (caster->IsFriendlyTo(unitTarget))
                        caster->CastSpell(unitTarget, SPELL_PALADIN_HOLY_SHOCK_HEAL, true);
                    else
                        caster->CastSpell(unitTarget, SPELL_PALADIN_HOLY_SHOCK_DAMAGE, true);
                }

                if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_1))
                    caster->RemoveAurasDueToSpell(SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_1);
            }
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_pal_holy_shock_SpellScript::CheckCast);
            OnEffectHitTarget += SpellEffectFn(spell_pal_holy_shock_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_holy_shock_SpellScript();
    }
};

// Activate Forbearance
// Called by Blessing of Protection - 1022, Lay on Hands - 633, Blessing of Spellwarding - 204018
class spell_pal_activate_forbearance : public SpellScriptLoader
{
public:
    spell_pal_activate_forbearance() : SpellScriptLoader("spell_pal_activate_forbearance") { }

    class spell_pal_activate_forbearance_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_activate_forbearance_SpellScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_FORBEARANCE))
                return false;
            return true;
        }

        SpellCastResult CheckForbearance()
        {
            if (Unit* target = GetExplTargetUnit())
            {
                if (target->HasAura(SPELL_PALADIN_FORBEARANCE))
                {
                    return SPELL_FAILED_TARGET_AURASTATE;
                }
            }
            return SPELL_CAST_OK;
        }

        void HandleOnHit()
        {
            if (Player* player = GetCaster()->ToPlayer())
                if (Unit* target = GetHitUnit())
                    player->CastSpell(target, SPELL_PALADIN_FORBEARANCE, true);
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_pal_activate_forbearance_SpellScript::CheckForbearance);
            OnHit += SpellHitFn(spell_pal_activate_forbearance_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_activate_forbearance_SpellScript();
    }
};

// Divine Shield - 642
class spell_pal_divine_shield : public SpellScriptLoader
{
public:
    spell_pal_divine_shield() : SpellScriptLoader("spell_pal_divine_shield") { }

    class spell_pal_divine_shield_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_divine_shield_SpellScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_FORBEARANCE))
                return false;
            return true;
        }

        SpellCastResult CheckForbearance()
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->HasAura(SPELL_PALADIN_FORBEARANCE))
                    return SPELL_FAILED_TARGET_AURASTATE;
            }
            return SPELL_CAST_OK;
        }

        void HandleOnCast()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                player->CastSpell(player, SPELL_PALADIN_FORBEARANCE, true);

                if (player->HasSpell(SPELL_PALADIN_FINAL_STAND))
                    player->CastSpell(player, SPELL_PALADIN_FINAL_STAND_TAUNT, true);
            }
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_pal_divine_shield_SpellScript::CheckForbearance);
            OnCast += SpellCastFn(spell_pal_divine_shield_SpellScript::HandleOnCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_divine_shield_SpellScript();
    }
};

// 210191 - Word of Glory
class spell_pal_word_of_glory : public SpellScriptLoader
{
public:
    spell_pal_word_of_glory() : SpellScriptLoader("spell_pal_word_of_glory") { }

    class spell_pal_word_of_glory_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_word_of_glory_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            uint32 const maxTargets = uint32(GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue(GetCaster()));

            if (targets.size() > maxTargets)
            {
                targets.sort(Trinity::HealthPctOrderPred());
                targets.resize(maxTargets);
            }

            _targets = targets;
        }

        void SetTargets(std::list<WorldObject*>& targets)
        {
            targets = _targets;
        }

        void HandleOnCast()
        {
            if (Unit* caster = GetCaster())
            {
                // Personnal Heal
                caster->CastSpell(caster, SPELL_PALADIN_WORD_OF_GLORY_HEAL, true);

                uint8 hp = caster->GetPower(POWER_HOLY_POWER);

                if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA))
                {
                    caster->RemoveAurasDueToSpell(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA);
                }
                else if (caster->HasAura(SPELL_PALADIN_THE_FIRES_OF_JUSTICE))
                {
                    caster->RemoveAurasDueToSpell(SPELL_PALADIN_THE_FIRES_OF_JUSTICE);
                    caster->SetPower(POWER_HOLY_POWER, hp - 2);
                }
                else
                {
                    caster->SetPower(POWER_HOLY_POWER, hp - 3);
                }
            }
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_pal_word_of_glory_SpellScript::HandleOnCast);
        }

    private:
        std::list<WorldObject*> _targets;

    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_word_of_glory_SpellScript();
    }
};

// Holy Prism - 114165
class spell_pal_holy_prism : public SpellScriptLoader
{
public:
    spell_pal_holy_prism() : SpellScriptLoader("spell_pal_holy_prism") { }

    class spell_pal_holy_prism_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_holy_prism_SpellScript);

        void HandleOnHit()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (player->IsValidAttackTarget(target))
                    {
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_DAMAGE_VISUAL, true);
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_DAMAGE_VISUAL_2, true);
                    }
                    else
                    {
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_HEAL_VISUAL, true);
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_HEAL_VISUAL_2, true);
                    }
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pal_holy_prism_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_holy_prism_SpellScript();
    }
};

// Holy Prism (damage) - 114852 or Holy Prism (heal) - 114871
// Called by Holy Prism (visual damage) - 114862 or Holy Prism (visual heal) - 121551
class spell_pal_holy_prism_effect : public SpellScriptLoader
{
public:
    spell_pal_holy_prism_effect() : SpellScriptLoader("spell_pal_holy_prism_effect") { }

    class spell_pal_holy_prism_effect_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_holy_prism_effect_SpellScript);

        void HandleOnHit()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    // damage
                    if (GetSpellInfo()->Id == 114862)
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_ENNEMIES, true);
                    // heal
                    else if (GetSpellInfo()->Id == 121551)
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_ALLIES, true);
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pal_holy_prism_effect_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_holy_prism_effect_SpellScript();
    }
};

// Called by Holy Prism (heal) - 114852 or Holy Prism (damage) - 114871
class spell_pal_holy_prism_visual : public SpellScriptLoader
{
public:
    spell_pal_holy_prism_visual() : SpellScriptLoader("spell_pal_holy_prism_visual") { }

    class spell_pal_holy_prism_visual_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_holy_prism_visual_SpellScript);

        void HandleOnHit()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (player->IsValidAttackTarget(target))
                    {
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_DAMAGE_VISUAL_2, true);
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_DAMAGE_VISUAL_2, true);
                    }
                    else
                    {
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_HEAL_VISUAL_2, true);
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_HEAL_VISUAL_2, true);
                    }
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pal_holy_prism_visual_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_holy_prism_visual_SpellScript();
    }
};

// Shield of the Righteous - 53600
class spell_pal_shield_of_the_righteous : public SpellScriptLoader
{
public:
    spell_pal_shield_of_the_righteous() : SpellScriptLoader("spell_pal_shield_of_the_righteous") { }

    class spell_pal_shield_of_the_righteous_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_shield_of_the_righteous_SpellScript);

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                if (GetHitUnit())
                {
                    if (player->FindNearestCreature(43499, 8) && player->HasAura(SPELL_PALADIN_CONSECRATION)) //if player is standing in his consecration all effects are increased by 20%
                    {
                        uint32 dmg = GetHitDamage();
                        dmg += dmg / 5;
                        SetHitDamage(dmg); //damage is increased by 20%

                        float mastery = player->GetFloatValue(PLAYER_MASTERY);

                        int32 reduction = int32(((-25 - int32(mastery / 2.0f)) * 120.0f) / 100.0f); //damage reduction is increased by 20%
                        player->CastCustomSpell(player, SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS_PROC, &reduction, NULL, NULL, true);
                    }
                    else
                    {
                        player->CastSpell(player, SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS_PROC, true);
                    }

                    if (player->HasSpell(SPELL_PALADIN_RIGHTEOUS_PROTECTOR)) //reduce the CD of Light of the Protector and Avenging Wrath by 3
                    {
                        if (player->GetSpellHistory()->HasCooldown(SPELL_PALADIN_LIGHT_OF_THE_PROTECTOR))
                            player->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_LIGHT_OF_THE_PROTECTOR, -3000);

                        if (player->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HAND_OF_THE_PROTECTOR))
                            player->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAND_OF_THE_PROTECTOR, -3000);

                        if (player->GetSpellHistory()->HasCooldown(SPELL_PALADIN_AVENGING_WRATH))
                            player->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_AVENGING_WRATH, -3000);
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_shield_of_the_righteous_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_shield_of_the_righteous_SpellScript();
    }
};

// 53651 - Beacon of Light
class spell_pal_beacon_of_light : public SpellScriptLoader
{
public:
    spell_pal_beacon_of_light() : SpellScriptLoader("spell_pal_beacon_of_light") { }

    class spell_pal_beacon_of_light_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_beacon_of_light_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_BEACON_OF_LIGHT_HEAL))
                return false;
            return true;
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetActionTarget()->GetAura(SPELL_PALADIN_BEACON_OF_LIGHT_MARKER, GetCasterGUID()))
                return false;
            return true;
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            int32 heal = eventInfo.GetHealInfo()->GetHeal();

            if (eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_PALADIN_HOLY_LIGHT)
                heal = int32(CalculatePct(heal, aurEff->GetAmount()));

            Unit::AuraList const& auras = GetCaster()->GetSingleCastAuras();
            for (Unit::AuraList::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
            {
                if ((*itr)->GetId() == SPELL_PALADIN_BEACON_OF_LIGHT_MARKER)
                {
                    std::list<AuraApplication*> applications;
                    (*itr)->GetApplicationList(applications);
                    if (applications.empty())
                        return;

                    GetCaster()->CastCustomSpell(SPELL_PALADIN_BEACON_OF_LIGHT_HEAL, SPELLVALUE_BASE_POINT0, heal, applications.front()->GetTarget(), true, NULL, aurEff);
                    return;
                }
            }
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_pal_beacon_of_light_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_pal_beacon_of_light_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_beacon_of_light_AuraScript();
    }
};

// 85043 - Grand Crusader
class spell_pal_grand_crusader : public SpellScriptLoader
{
public:
    spell_pal_grand_crusader() : SpellScriptLoader("spell_pal_grand_crusader") { }

    class spell_pal_grand_crusader_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_grand_crusader_AuraScript);

        void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            GetCaster()->ToPlayer()->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_AVENGERS_SHIELD, true);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_pal_grand_crusader_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_grand_crusader_AuraScript();
    }
};

// Grand Crusader Proc
// Called by Hammer of The Righteous - 53595, Blessed Hammer - 204019 (Passive)
// Called by Jugment - 20271 (Talent)
class spell_pal_grand_crusader_proc : public SpellScriptLoader
{
public:
    spell_pal_grand_crusader_proc() : SpellScriptLoader("spell_pal_grand_crusader_proc") { }

    class spell_pal_grand_crusader_proc_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_grand_crusader_proc_SpellScript);

        void HandleAfterCast()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                uint32 activateSpell = GetSpellInfo()->Id;

                if (player->HasSpell(SPELL_PALADIN_GRAND_CRUSADER) && roll_chance_i(15))
                {
                    if (activateSpell == SPELL_PALADIN_HAMMER_OF_THE_RIGHTEOUS || activateSpell == SPELL_PALDIN_BLESSED_HAMMER)
                    {
                        if (player->GetSpellHistory()->HasCooldown(SPELL_PALADIN_AVENGERS_SHIELD))
                            player->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_AVENGERS_SHIELD, true);
                    }
                }

                if (player->HasSpell(SPELL_PALADIN_CRUSADERS_JUDGMENT) && roll_chance_i(15))
                {
                    if (activateSpell == SPELL_PALADIN_JUDGMENT)
                    {
                        if (player->GetSpellHistory()->HasCooldown(SPELL_PALADIN_AVENGERS_SHIELD))
                            player->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_AVENGERS_SHIELD, true);
                    }
                }
            }
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_pal_grand_crusader_proc_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_grand_crusader_proc_SpellScript();
    }
};

// 20271 - Judgement
class spell_pal_judgment : public SpellScriptLoader
{
public:
    spell_pal_judgment() : SpellScriptLoader("spell_pal_judgment") { }

    class spell_pal_judgment_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_judgment_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();
            uint32 spec = caster->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID);

            if (spec == TALENT_SPEC_PALADIN_RETRIBUTION)
            {
                caster->CastSpell(target, 197277, true); //8 sec debuff: modify damage received from holy power spenders. (Retribution mastery)
            }
            if (spec == TALENT_SPEC_PALADIN_HOLY)
            {
                caster->CastSpell(target, 214222, true); //6 sec debuff: modify damage done by Crusader Strike and Holy Shock (Holy spec)

                if (caster->HasSpell(SPELL_PALADIN_FIST_OF_JUSTICE))
                {
                    if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE))
                        caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE, -10000);
                }
            }
            if (spec == TALENT_SPEC_PALADIN_PROTECTION)
            {
                SpellCategoryEntry const* charge = sSpellCategoryStore.LookupEntry(sSpellMgr->GetSpellInfo(SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS)->ChargeCategoryId);
                caster->ToPlayer()->GetSpellHistory()->ReduceChargeCooldown(charge, 1000); //Remove 1 sec from the cooldown of SotR

                if (caster->HasSpell(SPELL_PALADIN_FIST_OF_JUSTICE))
                {
                    if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE))
                        caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE, -10000);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_judgment_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_judgment_SpellScript();
    }
};

// 85256 - Templar's Verdict
class spell_pal_templar_s_verdict : public SpellScriptLoader
{
public:
    spell_pal_templar_s_verdict() : SpellScriptLoader("spell_pal_templar_s_verdict") { }

    class spell_pal_templar_s_verdict_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_templar_s_verdict_SpellScript);

        bool Validate(SpellInfo const* /*spellEntry*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_TEMPLARS_VERDICT_DAMAGE))
                return false;

            return true;
        }

        bool Load() override
        {
            if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                return false;

            if (GetCaster()->ToPlayer()->getClass() != CLASS_PALADIN)
                return false;

            return true;
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();

            caster->CastSpell(target, SPELL_PALADIN_TEMPLARS_VERDICT_DAMAGE, true);

            uint8 hp = caster->GetPower(POWER_HOLY_POWER);
            if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA))
            {
                caster->RemoveAurasDueToSpell(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA);
            }
            else if (caster->HasAura(SPELL_PALADIN_THE_FIRES_OF_JUSTICE))
            {
                caster->RemoveAurasDueToSpell(SPELL_PALADIN_THE_FIRES_OF_JUSTICE);
                caster->SetPower(POWER_HOLY_POWER, hp - 2);
            }
            else
            {
                caster->SetPower(POWER_HOLY_POWER, hp - 3);
            }

            if (caster->HasSpell(SPELL_PALADIN_FIST_OF_JUSTICE))
            {
                if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE))
                    caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE, -8000);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_templar_s_verdict_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_templar_s_verdict_SpellScript();
    }
};

// Light of the Martyr - 183998
class spell_pal_light_of_the_martyr : public SpellScriptLoader
{
public:
    spell_pal_light_of_the_martyr() : SpellScriptLoader("spell_pal_light_of_the_martyr") {}

    class spell_pal_light_of_the_martyr_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_light_of_the_martyr_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_LIGHT_OF_THE_MARTYR_DAMAGE))
                return false;
            return true;
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();

            int32 dmg = (GetHitHeal() * 50.0f) / 100.0f;
            caster->CastCustomSpell(caster, SPELL_PALADIN_LIGHT_OF_THE_MARTYR_DAMAGE, &dmg, NULL, NULL, true);

            if (caster->HasAura(223316)) //Fervent Martyr buff
            {
                caster->RemoveAurasDueToSpell(223316);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_light_of_the_martyr_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_HEAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_light_of_the_martyr_SpellScript();
    }
};

// Flash of Light - 19750
class spell_pal_flash_of_light : public SpellScriptLoader
{
public:
    spell_pal_flash_of_light() : SpellScriptLoader("spell_pal_flash_of_light") {}

    class spell_pal_flash_of_light_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_flash_of_light_SpellScript);

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                uint32 sp = caster->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SPELL);
                uint32 dmg = uint32(1 + sp * 4.25f);

                if (caster->HasAura(SPELL_PALADIN_INFUSION_OF_LIGHT_AURA))
                {
                    dmg = dmg * 1.5f;
                    caster->RemoveAura(SPELL_PALADIN_INFUSION_OF_LIGHT_AURA);
                }

                if (caster->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) != TALENT_SPEC_PALADIN_HOLY)
                {
                    dmg = dmg * 1.5f;
                }

                SetHitHeal(dmg);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_flash_of_light_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_HEAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_flash_of_light_SpellScript();
    }
};

// Holy Light - 82326
class spell_pal_holy_light : public SpellScriptLoader
{
public:
    spell_pal_holy_light() : SpellScriptLoader("spell_pal_holy_light") {}

    class spell_pal_holy_light_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_holy_light_SpellScript);

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                uint32 sp = caster->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SPELL);
                uint32 dmg = uint32(1 + sp * 4.25f);

                if (caster->HasAura(SPELL_PALADIN_INFUSION_OF_LIGHT_AURA))
                {
                    caster->RemoveAura(SPELL_PALADIN_INFUSION_OF_LIGHT_AURA);
                }

                SetHitHeal(dmg);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_holy_light_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_HEAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_holy_light_SpellScript();
    }
};

// Light of the Protector - 184092 and Hand of the Protector - 213652
class spell_pal_light_of_the_protector : public SpellScriptLoader
{
public:
    spell_pal_light_of_the_protector() : SpellScriptLoader("spell_pal_light_of_the_protector") {}

    class spell_pal_light_of_the_protector_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_light_of_the_protector_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_LIGHT_OF_THE_PROTECTOR))
                return false;
            return true;
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            uint32 dmg;

            if (GetSpellInfo()->Id == SPELL_PALADIN_LIGHT_OF_THE_PROTECTOR)
            {
                int32 effvalue = sSpellMgr->GetSpellInfo(SPELL_PALADIN_LIGHT_OF_THE_PROTECTOR)->GetEffect(1)->BasePoints;
                int32 healthMissing = caster->GetMaxHealth() - caster->GetHealth();

                dmg = ApplyPct(healthMissing, effvalue) + GetHitHeal();

                if (caster->FindNearestCreature(43499, 8) && caster->HasAura(SPELL_PALADIN_CONSECRATION)) // if you are standing in your consecration, the heal is increased by 20%
                    AddPct(dmg, 20);
            }

            if (GetSpellInfo()->Id == SPELL_PALADIN_HAND_OF_THE_PROTECTOR)
            {
                int32 effvalue = sSpellMgr->GetSpellInfo(SPELL_PALADIN_HAND_OF_THE_PROTECTOR)->GetEffect(1)->BasePoints;

                Unit* target = GetHitUnit();
                int32 healthMissing = target->GetMaxHealth() - target->GetHealth();

                dmg = ApplyPct(healthMissing, effvalue) + GetHitHeal();
            }

            dmg = std::max(dmg, (uint32)0);

            SetHitHeal(dmg);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_light_of_the_protector_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_HEAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_light_of_the_protector_SpellScript();
    }
};

// Bastion of Light - 204035
class spell_pal_bastion_of_light : public SpellScriptLoader
{
public:
    spell_pal_bastion_of_light() : SpellScriptLoader("spell_pal_bastion_of_light") {}

    class spell_pal_bastion_of_light_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_bastion_of_light_SpellScript);

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();

            caster->GetSpellHistory()->ResetCharges(sSpellMgr->GetSpellInfo(SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS)->ChargeCategoryId);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_bastion_of_light_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_bastion_of_light_SpellScript();
    }
};

// Light of Dawn - 85222
class spell_pal_light_of_dawn : public SpellScriptLoader
{
public:
    spell_pal_light_of_dawn() : SpellScriptLoader("spell_pal_light_of_dawn") {}

    class spell_pal_light_of_dawn_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_light_of_dawn_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_LIGHT_OF_DAWN_TRIGGER))
                return false;
            return true;
        }

        void HandleOnHit()
        {
            if (Unit* caster = GetCaster())
            {
                caster->CastSpell(caster, SPELL_PALADIN_LIGHT_OF_DAWN_TRIGGER, true);

                if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_2))
                    caster->RemoveAurasDueToSpell(SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_2);
            }
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_pal_light_of_dawn_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_light_of_dawn_SpellScript();
    }
};

// 185984 - Light of Dawn aoe heal
class spell_pal_light_of_dawn_trigger : public SpellScriptLoader
{
public:
    spell_pal_light_of_dawn_trigger() : SpellScriptLoader("spell_pal_light_of_dawn_trigger") {}

    class spell_pal_light_of_dawn_trigger_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_light_of_dawn_trigger_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();
            uint8 limit = 5;

            targets.remove_if([caster](WorldObject* target)
            {
                Position pos = target->GetPosition();
                return !(caster->IsWithinDist2d(&pos, 15.0f) && caster->isInFront(target, float(M_PI / 3))); //must be in a cone in 15 yards
            });

            Trinity::Containers::RandomResize(targets, limit); //max 5 targets.
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            int32 dmg = GetHitHeal();

            dmg += GetCaster()->GetUInt32Value(UNIT_FIELD_ATTACK_POWER) * 1.8f;

            SetHitHeal(dmg);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_light_of_dawn_trigger_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
            OnEffectHitTarget += SpellEffectFn(spell_pal_light_of_dawn_trigger_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_HEAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_light_of_dawn_trigger_SpellScript();
    }
};

// Crusader's Might - 196926
class spell_pal_crusaders_might : public SpellScriptLoader
{
public:
    spell_pal_crusaders_might() : SpellScriptLoader("spell_pal_crusaders_might") { }

    class spell_pal_crusaders_might_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_crusaders_might_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_CRUSADERS_MIGHT) ||
                !sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_SHOCK_GENERIC) ||
                !sSpellMgr->GetSpellInfo(SPELL_PALADIN_LIGHT_OF_DAWN))
                return false;
            return true;
        }

        void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            Unit* caster = GetCaster();
            int32 effValue = sSpellMgr->GetSpellInfo(SPELL_PALADIN_CRUSADERS_MIGHT)->GetEffect(0)->BasePoints;

            if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HOLY_SHOCK_GENERIC))
                caster->ToPlayer()->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HOLY_SHOCK_GENERIC, effValue);

            if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_LIGHT_OF_DAWN))
                caster->ToPlayer()->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_LIGHT_OF_DAWN, effValue);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_pal_crusaders_might_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_crusaders_might_AuraScript();
    }
};

// Zeal - 217020
class spell_pal_zeal : public SpellScriptLoader
{
public:
    spell_pal_zeal() : SpellScriptLoader("spell_pal_zeal") {}

    class spell_pal_zeal_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_zeal_SpellScript);

    public:
        spell_pal_zeal_SpellScript()
        {
            targetIdx = 0;
        }

    private:

        uint8 targetIdx;

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            int32 dmg = GetHitDamage();
            for (int i = 0; i < targetIdx; ++i) //damage is reduced by 40% with each jump
            {
                ApplyPct(dmg, 60);
            }
            SetHitDamage(dmg);
            targetIdx++;
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_zeal_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_zeal_SpellScript();
    }
};

// Justicar's Vengeance - 215661
class spell_pal_justicars_vengeance : public SpellScriptLoader
{
public:
    spell_pal_justicars_vengeance() : SpellScriptLoader("spell_pal_justicars_vengeance") {}

    class spell_pal_justicars_vengeance_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_justicars_vengeance_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            int32 damage = GetHitDamage() * 2;

            if (target->HasAuraType(SPELL_AURA_MOD_STUN) || target->HasAuraWithMechanic(1 << MECHANIC_STUN))
            {
                SetHitDamage(damage);
                SetEffectValue(damage);
            }

            uint8 hp = caster->GetPower(POWER_HOLY_POWER);
            if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA))
            {
                caster->RemoveAurasDueToSpell(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA);
            }
            else if (caster->HasAura(SPELL_PALADIN_THE_FIRES_OF_JUSTICE))
            {
                caster->RemoveAurasDueToSpell(SPELL_PALADIN_THE_FIRES_OF_JUSTICE);
                caster->SetPower(POWER_HOLY_POWER, hp - 4);
            }
            else
            {
                caster->SetPower(POWER_HOLY_POWER, hp - 5);
            }

            if (caster->HasSpell(SPELL_PALADIN_FIST_OF_JUSTICE))
            {
                if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE))
                    caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE, -8000);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_justicars_vengeance_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_HEALTH_LEECH);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_justicars_vengeance_SpellScript();
    }
};

// Hammer of the Righteous - 53595
class spell_pal_hammer_of_the_righteous : public SpellScriptLoader
{
public:
    spell_pal_hammer_of_the_righteous() : SpellScriptLoader("spell_pal_hammer_of_the_righteous") { }

    class spell_pal_hammer_of_the_righteous_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_hammer_of_the_righteous_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_AVENGERS_SHIELD))
                return false;
            return true;
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (caster->HasAura(SPELL_PALADIN_GRAND_CRUSADER)) // Grand Crusader: 15% chance to reset the CD of Avenger's Shield
                if (roll_chance_i(15))
                    caster->ToPlayer()->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_AVENGERS_SHIELD, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_hammer_of_the_righteous_SpellScript::HandleOnHit, EFFECT_1, SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_hammer_of_the_righteous_SpellScript();
    }
};

// Divine Intervention - 213313
class spell_pal_divine_intervention : public SpellScriptLoader
{
public:
    spell_pal_divine_intervention() : SpellScriptLoader("spell_pal_divine_intervention") { }

    class spell_pal_divine_intervention_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_divine_intervention_AuraScript);

    public:
        spell_pal_divine_intervention_AuraScript()
        {
            healPct = 0;
        }

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_INTERVENTION_HEAL))
                return false;
            return true;
        }

        bool Load() override
        {
            healPct = GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue();
            return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
        }

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& /*absorbAmount*/)
        {
            Unit* target = GetTarget();

            if (dmgInfo.GetDamage() < target->GetHealth())
                return;

            int32 healAmount = int32(target->CountPctFromMaxHealth(healPct));

            if (!target->HasAura(SPELL_PALADIN_FORBEARANCE) && !target->GetSpellHistory()->HasCooldown(SPELL_PALADIN_DIVINE_SHIELD))
            {
                target->CastSpell(target, SPELL_PALADIN_DIVINE_SHIELD, true);
                target->CastCustomSpell(target, SPELL_PALADIN_DIVINE_INTERVENTION_HEAL, &healAmount, NULL, NULL, true, NULL, aurEff);
            }
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_divine_intervention_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_pal_divine_intervention_AuraScript::Absorb, EFFECT_0);
        }

    private:
        uint32 healPct;

    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_divine_intervention_AuraScript();
    }
};

// 190784 - Divine Steed
class spell_pal_divine_steed : public SpellScriptLoader
{
public:
    spell_pal_divine_steed() : SpellScriptLoader("spell_pal_divine_steed") { }

    class spell_pal_divine_steed_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_divine_steed_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_STEED_SPEED))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_STEED_HUMAN))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_STEED_DRAENEI))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_STEED_BLOODELF))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_STEED_TAUREN))
                return false;
            return true;
        }

        void HandleOnHit()
        {
            if (Player* target = GetHitPlayer())
            {
                uint32 spellId = SPELL_PALADIN_DIVINE_STEED_HUMAN;
                switch (target->getRace())
                {
                case RACE_HUMAN:
                    spellId = SPELL_PALADIN_DIVINE_STEED_HUMAN;
                    break;
                case RACE_DWARF:
                    spellId = SPELL_PALADIN_DIVINE_STEED_HUMAN;
                    break;
                case RACE_DRAENEI:
                    spellId = SPELL_PALADIN_DIVINE_STEED_DRAENEI;
                    break;
                case RACE_BLOODELF:
                    spellId = SPELL_PALADIN_DIVINE_STEED_BLOODELF;
                    break;
                case RACE_TAUREN:
                    spellId = SPELL_PALADIN_DIVINE_STEED_TAUREN;
                    break;
                default:
                    break;
                }
                target->CastSpell(target, spellId, true);
                target->CastSpell(target, SPELL_PALADIN_DIVINE_STEED_SPEED, false);
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pal_divine_steed_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_divine_steed_SpellScript();
    }
};

// Judgment of Light - 183778
class spell_pal_judgment_of_light : public SpellScriptLoader
{
public:
    spell_pal_judgment_of_light() : SpellScriptLoader("spell_pal_judgment_of_light") { }

    class spell_pal_judgment_of_light_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_judgment_of_light_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetSpellInfo()->Id == SPELL_PALADIN_JUDGMENT)
                return true;

            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_pal_judgment_of_light_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_judgment_of_light_AuraScript();
    }
};

// Judgment of Light Proc - 196941
class spell_pal_judgment_of_light_proc : public SpellScriptLoader
{
public:
    spell_pal_judgment_of_light_proc() : SpellScriptLoader("spell_pal_judgment_of_light_proc") {}

    class spell_pal_judgment_of_light_proc_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_judgment_of_light_proc_AuraScript);

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();

            if (!GetCaster())
                return;

            Unit* attacker = eventInfo.GetActor();
            if (!attacker)
                return;

            if (eventInfo.GetActor()->GetGUID() != GetCaster()->GetGUID())
                return;

            if (Unit* caster = GetCaster())
                caster->CastSpell(attacker, SPELL_PALADIN_JUDGMENT_OF_LIGHT_HEAL, true);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_pal_judgment_of_light_proc_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_judgment_of_light_proc_AuraScript();
    }
};

// Blinding Light - 115750
class spell_pal_blinding_light : public SpellScriptLoader
{
public:
    spell_pal_blinding_light() : SpellScriptLoader("spell_pal_blinding_light") { }

    class spell_pal_blinding_light_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_blinding_light_SpellScript);

        void HandleOnHit()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    player->CastSpell(target, SPELL_PALADIN_BLINDING_LIGHT_CONFUSE, true);
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pal_blinding_light_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_blinding_light_SpellScript();
    }
};

// 184662 - Shield of Vengeance
class spell_pal_shield_of_vengeance : public SpellScriptLoader
{
public:
    spell_pal_shield_of_vengeance() : SpellScriptLoader("spell_pal_shield_of_vengeance") { }

    class spell_pal_shield_of_vengeance_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_shield_of_vengeance_AuraScript);

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
        {
            if (Unit* caster = GetCaster())
            {
                canBeRecalculated = false;

                float ap = caster->GetTotalAttackPowerValue(BASE_ATTACK);
                amount += int32(ap * 10);
            }
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_shield_of_vengeance_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_shield_of_vengeance_AuraScript();
    }
};

// Divine Storm - 53385
class spell_pal_divine_storm : public SpellScriptLoader
{
public:
    spell_pal_divine_storm() : SpellScriptLoader("spell_pal_divine_storm") { }

    class spell_pal_divine_storm_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_divine_storm_SpellScript);

        void HandleOnHit()
        {
            if (Unit* caster = GetCaster())
            {
                std::list<Unit*> targetList;
                caster->GetAttackableUnitListInRange(targetList, 8.0f);

                if (!targetList.empty())
                    for (auto itr : targetList)
                        caster->CastSpell(itr, SPELL_PALADIN_DIVINE_STORM_DAMAGE, true);

                caster->CastSpell(caster, SPELL_PALADIN_DIVINE_STORM_DUMMY, true);

                uint8 hp = caster->GetPower(POWER_HOLY_POWER);
                if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA))
                {
                    caster->RemoveAurasDueToSpell(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA);
                }
                else if (caster->HasAura(SPELL_PALADIN_THE_FIRES_OF_JUSTICE))
                {
                    caster->RemoveAurasDueToSpell(SPELL_PALADIN_THE_FIRES_OF_JUSTICE);
                    caster->SetPower(POWER_HOLY_POWER, hp - 2);
                }
                else
                {
                    caster->SetPower(POWER_HOLY_POWER, hp - 3);
                }

                if (caster->HasSpell(SPELL_PALADIN_FIST_OF_JUSTICE))
                {
                    if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE))
                        caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE, -8000);
                }
            }
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_pal_divine_storm_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_divine_storm_SpellScript();
    }
};

// Divine Storm Dummy - 174333
class spell_pal_divine_storm_dummy : public SpellScriptLoader
{
public:
    spell_pal_divine_storm_dummy() : SpellScriptLoader("spell_pal_divine_storm_dummy") { }

    class spell_pal_divine_storm_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_divine_storm_dummy_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 0);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_divine_storm_dummy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_divine_storm_dummy_SpellScript();
    }
};

// 213757 - Execution Sentence
class spell_pal_execute_sentence : public SpellScriptLoader
{
public:
    spell_pal_execute_sentence() : SpellScriptLoader("spell_pal_execute_sentence") { }

    class spell_pal_execute_sentence_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_execute_sentence_SpellScript);

        void HandleOnHit()
        {
            if (Unit* caster = GetCaster())
            {
                uint8 hp = caster->GetPower(POWER_HOLY_POWER);
                if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA))
                {
                    caster->RemoveAurasDueToSpell(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA);
                }
                else if (caster->HasAura(SPELL_PALADIN_THE_FIRES_OF_JUSTICE))
                {
                    caster->RemoveAurasDueToSpell(SPELL_PALADIN_THE_FIRES_OF_JUSTICE);
                    caster->SetPower(POWER_HOLY_POWER, hp - 2);
                }
                else
                {
                    caster->SetPower(POWER_HOLY_POWER, hp - 3);
                }

                if (caster->HasSpell(SPELL_PALADIN_FIST_OF_JUSTICE))
                {
                    if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE))
                        caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE, -8000);
                }
            }
        }
        void Register() override
        {
            OnCast += SpellCastFn(spell_pal_execute_sentence_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_execute_sentence_SpellScript();
    }
};

// Cleanse - 4987 and Cleanse Toxins - 213644
class spell_pal_cleanse : public SpellScriptLoader
{
public:
    spell_pal_cleanse() : SpellScriptLoader("spell_pal_cleanse") { }

    class spell_pal_cleanse_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_cleanse_SpellScript);

        SpellCastResult CheckCleansing()
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetExplTargetUnit())
                {
                    DispelChargesList dispelList[MAX_SPELL_EFFECTS];

                    // Create dispel mask by dispel type
                    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    {
                        uint32 dispel_type = GetSpellInfo()->GetEffect(i)->MiscValue;
                        uint32 dispelMask = GetSpellInfo()->GetDispelMask(DispelType(dispel_type));

                        // Cleanse can dispell all Magic, Disease and Poison
                        if (GetSpellInfo()->Id == 4987)
                            dispelMask = ((1 << DISPEL_MAGIC) | (1 << DISPEL_DISEASE) | (1 << DISPEL_POISON));

                        // Cleanse Toxins can dispell all Disease and Poison
                        if (GetSpellInfo()->Id == 213644)
                            dispelMask = ((1 << DISPEL_DISEASE) | (1 << DISPEL_POISON));

                        target->GetDispellableAuraList(caster, dispelMask, dispelList[i]);
                    }

                    bool empty = true;
                    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    {
                        if (dispelList[i].empty())
                            continue;

                        empty = false;
                        break;
                    }

                    if (empty)
                        return SPELL_FAILED_NOTHING_TO_DISPEL;

                    return SPELL_CAST_OK;
                }
            }
            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_pal_cleanse_SpellScript::CheckCleansing);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_cleanse_SpellScript();
    }
};

// Divine Purpose (Retribution) - 223817 & Divine Purpose (Holy) - 197646
class spell_pal_divine_purpose : public SpellScriptLoader
{
public:
    spell_pal_divine_purpose() : SpellScriptLoader("spell_pal_divine_purpose") { }

    class spell_pal_divine_purpose_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_divine_purpose_AuraScript);

        bool CheckProc(ProcEventInfo& /*eventInfo*/)
        {
            // Called by spell_pal_divine_purpose_proc
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_pal_divine_purpose_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_divine_purpose_AuraScript();
    }
};

// Divine Purpose Proc
// Called by Seal of Light - 202273, Justicar's Vengeance - 215661, Word of Glory - 210191, Execution Sentence - 213757, Divine Storm - 53385, Templar's Verdict - 85256
// Called by Holy Shock - 20473, Light of Dawn - 85222
class spell_pal_divine_purpose_proc : public SpellScriptLoader
{
public:
    spell_pal_divine_purpose_proc() : SpellScriptLoader("spell_pal_divine_purpose_proc") { }

    class spell_pal_divine_purpose_proc_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_divine_purpose_proc_SpellScript);

        void HandleAfterCast()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                if (player->HasSpell(SPELL_PALADIN_DIVINE_PURPOSE_RET) || player->HasSpell(SPELL_PALADIN_DIVINE_PURPOSE_HOLY))
                {
                    uint32 spec = player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID);
                    uint32 activateSpell = GetSpellInfo()->Id;

                    if (spec == TALENT_SPEC_PALADIN_RETRIBUTION && roll_chance_i(20))
                    {
                        if (activateSpell == SPELL_PALADIN_SEAL_OF_LIGHT || activateSpell == SPELL_PALADIN_JUSTICARS_VENGEANCE || activateSpell == SPELL_PALADIN_WORD_OF_GLORY || activateSpell == SPELL_PALADIN_EXECUTE_SENTENCE || activateSpell == SPELL_PALADIN_DIVINE_STORM || activateSpell == SPELL_PALADIN_TEMPLARS_VERDICT)
                            player->CastSpell(player, SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA, true);
                    }
                    else if (spec == TALENT_SPEC_PALADIN_HOLY && roll_chance_i(15))
                    {
                        if (activateSpell == SPELL_PALADIN_HOLY_SHOCK_GENERIC)
                        {
                            player->CastSpell(player, SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_1, true);

                            if (player->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HOLY_SHOCK_GENERIC))
                                player->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_HOLY_SHOCK_GENERIC, true);
                        }

                        if (activateSpell == SPELL_PALADIN_LIGHT_OF_DAWN)
                        {
                            player->CastSpell(player, SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_2, true);

                            if (player->GetSpellHistory()->HasCooldown(SPELL_PALADIN_LIGHT_OF_DAWN))
                                player->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_LIGHT_OF_DAWN, true);
                        }
                    }
                }
            }
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_pal_divine_purpose_proc_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_divine_purpose_proc_SpellScript();
    }
};

// The fires of Justice - 203316
class spell_pal_the_fire_of_justice : public SpellScriptLoader
{
public:
    spell_pal_the_fire_of_justice() : SpellScriptLoader("spell_pal_the_fire_of_justice") { }

    class spell_pal_the_fire_of_justice_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_the_fire_of_justice_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetSpellInfo()->Id == SPELL_PALADIN_CRUSADER_STRIKE)
                return true;

            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_pal_the_fire_of_justice_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_the_fire_of_justice_AuraScript();
    }
};

// Infusion of Light - 53576
class spell_pal_infusion_of_light : public SpellScriptLoader
{
public:
    spell_pal_infusion_of_light() : SpellScriptLoader("spell_pal_infusion_of_light") { }

    class spell_pal_infusion_of_light_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_infusion_of_light_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            bool _spellCanProc = (eventInfo.GetSpellInfo()->Id == SPELL_PALADIN_HOLY_SHOCK_DAMAGE ||
                eventInfo.GetSpellInfo()->Id == SPELL_PALADIN_HOLY_SHOCK_HEAL);

            if ((eventInfo.GetHitMask() & PROC_HIT_CRITICAL) && _spellCanProc)
                return true;

            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_pal_infusion_of_light_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_infusion_of_light_AuraScript();
    }
};

// Holy Shield - 152261
class spell_pal_holy_shield : public SpellScriptLoader
{
public:
    spell_pal_holy_shield() : SpellScriptLoader("spell_pal_holy_shield") { }

    class spell_pal_holy_shield_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_holy_shield_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetHitMask() & PROC_HIT_BLOCK)
                return true;

            return false;
        }

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            // Disable absorb (shitty blizzard)
            amount = 0;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_pal_holy_shield_AuraScript::CheckProc);
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_holy_shield_AuraScript::CalculateAmount, EFFECT_2, SPELL_AURA_SCHOOL_ABSORB);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_holy_shield_AuraScript();
    }
};

// Light's Hammer - 122773
class spell_pal_lights_hammer : public SpellScriptLoader
{
public:
    spell_pal_lights_hammer() : SpellScriptLoader("spell_pal_lights_hammer") { }

    class spell_pal_lights_hammer_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_lights_hammer_SpellScript);

        void HandleAfterCast()
        {
            if (Unit* caster = GetCaster())
            {
                std::list<Creature*> tempList;
                std::list<Creature*> LightsHammerlist;

                caster->GetCreatureListWithEntryInGrid(LightsHammerlist, NPC_PALADIN_LIGHTS_HAMMER, 200.0f);

                tempList = LightsHammerlist;

                for (std::list<Creature*>::iterator i = tempList.begin(); i != tempList.end(); ++i)
                {
                    Unit* owner = (*i)->GetOwner();
                    if (owner != nullptr && owner->GetGUID() == caster->GetGUID() && (*i)->IsSummon())
                        continue;

                    LightsHammerlist.remove((*i));
                }

                for (std::list<Creature*>::iterator itr = LightsHammerlist.begin(); itr != LightsHammerlist.end(); ++itr)
                    (*itr)->CastSpell((*itr), SPELL_PALADIN_LIGHTS_HAMMER_TICK, true);
            }
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_pal_lights_hammer_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_lights_hammer_SpellScript();
    }
};

// Light's Hammer (Periodic Dummy) - 114918
class spell_pal_lights_hammer_tick : public SpellScriptLoader
{
public:
    spell_pal_lights_hammer_tick() : SpellScriptLoader("spell_pal_lights_hammer_tick") { }

    class spell_pal_lights_hammer_tick_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_lights_hammer_tick_AuraScript);

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->GetOwner())
                {
                    caster->CastSpell(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), SPELL_PALADIN_ARCING_LIGHT_HEAL, true, 0, nullptr, caster->GetOwner()->GetGUID());
                    caster->CastSpell(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), SPELL_PALADIN_ARCING_LIGHT_DAMAGE, true, 0, nullptr, caster->GetOwner()->GetGUID());
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_pal_lights_hammer_tick_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_lights_hammer_tick_AuraScript();
    }
};

//231843 - Blade of Wrath! (proc)
//Updated to 7.1
class spell_pal_blade_of_wrath_proc : public SpellScriptLoader
{
public:
    spell_pal_blade_of_wrath_proc() : SpellScriptLoader("spell_pal_blade_of_wrath_proc") { }

    class spell_pal_blade_of_wrath_proc_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_blade_of_wrath_proc_AuraScript);

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_BLADE_OF_JUSTICE);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_pal_blade_of_wrath_proc_AuraScript::HandleApply, EFFECT_0, SPELL_EFFECT_APPLY_AURA, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_blade_of_wrath_proc_AuraScript();
    }
};

//203538 - Greater Blessing of Kings
class spell_pal_greater_blessing_of_kings : public SpellScriptLoader
{
public:
    spell_pal_greater_blessing_of_kings() : SpellScriptLoader("spell_pal_greater_blessing_of_kings") { }

    class spell_pal_greater_blessing_of_kings_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_greater_blessing_of_kings_AuraScript);

    public:
        spell_pal_greater_blessing_of_kings_AuraScript() : leftAbsorbAmount(0), maxAbsorbAmount(0) { }

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_PALADIN_GREATER_BLESSING_OF_KINGS });
        }

        bool Load() override
        {
            maxAbsorbAmount = 2.7f * GetCaster()->GetTotalSpellPowerValue(SPELL_SCHOOL_MASK_ALL, true);
            leftAbsorbAmount = maxAbsorbAmount;
            return GetUnitOwner()->IsPlayer();
        }

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            leftAbsorbAmount = maxAbsorbAmount;
        }

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void Absorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            absorbAmount = std::min(dmgInfo.GetDamage(), leftAbsorbAmount);
            leftAbsorbAmount -= absorbAmount;
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_pal_greater_blessing_of_kings_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_greater_blessing_of_kings_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_pal_greater_blessing_of_kings_AuraScript::Absorb, EFFECT_1);
        }

    private:
        uint32 leftAbsorbAmount;
        uint32 maxAbsorbAmount;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_greater_blessing_of_kings_AuraScript();
    }
};

//198034 - Divine Hammer
class spell_pal_divine_hammer : public SpellScriptLoader
{
public:
    spell_pal_divine_hammer() : SpellScriptLoader("spell_pal_divine_hammer") { }

    class spell_pal_divine_hammer_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_divine_hammer_SpellScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            return ValidateSpellInfo({ SPELL_PALADIN_DIVINE_HAMMER });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            uint8 hp = GetCaster()->GetPower(POWER_HOLY_POWER);
            GetCaster()->SetPower(POWER_HOLY_POWER, hp + 2);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_divine_hammer_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_divine_hammer_SpellScript();
    }
};

// 31850 - ardent defender
class spell_pal_ardent_defender : public SpellScriptLoader
{
public:
    spell_pal_ardent_defender() : SpellScriptLoader("spell_pal_ardent_defender") { }

    class spell_pal_ardent_defender_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_ardent_defender_AuraScript);

    public:
        spell_pal_ardent_defender_AuraScript()
        {
            absorbPct   = 0;
            healPct     = 0;
        }

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_PALADIN_ARDENT_DEFENDER });
        }

        bool Load() override
        {
            absorbPct   = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
            healPct     = GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue();
            return GetUnitOwner()->IsPlayer();
        }

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);

            Unit* target = GetTarget();
            if (dmgInfo.GetDamage() < target->GetHealth())
                return;

            int32 healAmount = int32(target->CountPctFromMaxHealth(healPct));
            target->CastCustomSpell(target, SPELL_PALADIN_ARDENT_DEFENDER_HEAL, &healAmount, NULL, NULL, true, NULL, aurEff);
            aurEff->GetBase()->Remove();
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_ardent_defender_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_pal_ardent_defender_AuraScript::Absorb, EFFECT_0);
        }

    private:
        uint32 absorbPct;
        uint32 healPct;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_ardent_defender_AuraScript();
    }
};

// 152262 - Seraphim
class spell_pal_seraphim : public SpellScript
{
    PrepareSpellScript(spell_pal_seraphim);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_SERAPHIM, SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS });
    }

    SpellCastResult CheckCast()
    {
        uint32 ChargeCategoryId = sSpellMgr->GetSpellInfo(SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS)->ChargeCategoryId;
        if (!GetCaster()->GetSpellHistory()->HasCharge(ChargeCategoryId))
            return SPELL_FAILED_NO_POWER;

        return SPELL_FAILED_SUCCESS;
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        uint32 ChargeCategoryId     = sSpellMgr->GetSpellInfo(SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS)->ChargeCategoryId;
        SpellHistory* spellHistory  = GetCaster()->GetSpellHistory();

        int32 useCharges = std::min(GetSpellInfo()->GetEffect(effIndex)->BasePoints, spellHistory->GetChargeCount(ChargeCategoryId));

        for (uint8 i = 0; i < useCharges; ++i)
            spellHistory->ConsumeCharge(ChargeCategoryId);

        if (Aura* seraphimAura = GetCaster()->GetAura(SPELL_PALADIN_SERAPHIM))
            seraphimAura->SetDuration(GetSpellInfo()->GetMaxDuration() * useCharges);

        spellHistory->ForceSendSpellCharge(sSpellCategoryStore.LookupEntry(ChargeCategoryId));
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_pal_seraphim::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_pal_seraphim::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// Light's Hammer
// NPC Id - 59738
class npc_pal_lights_hammer : public CreatureScript
{
public:
    npc_pal_lights_hammer() : CreatureScript("npc_pal_lights_hammer") {}

    class npc_pal_lights_hammer_AI : public ScriptedAI
    {
    public:

        npc_pal_lights_hammer_AI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            me->CastSpell(me, SPELL_PALADIN_LIGHT_HAMMER_COSMETIC, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_pal_lights_hammer_AI(creature);
    }
};

// Consecration - 26573 and 205228
// AreaTriggerID - 4488
class at_pal_consecration : public AreaTriggerEntityScript
{
public:

    at_pal_consecration() : AreaTriggerEntityScript("at_pal_consecration") { }

    struct at_pal_consecrationAI : AreaTriggerAI
    {
        int32 timeInterval;

        at_pal_consecrationAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
        {
            // How often should the action be executed
            timeInterval = 1000;
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
            if (timeInterval < 1000)
                return;

            if (TempSummon* tempSumm = caster->SummonCreature(WORLD_TRIGGER, at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 200))
            {
                tempSumm->setFaction(caster->getFaction());
                tempSumm->SetGuidValue(UNIT_FIELD_SUMMONEDBY, caster->GetGUID());
                tempSumm->SetPhaseMask(caster->GetPhaseMask(), true);
                caster->CastSpell(tempSumm, SPELL_PALADIN_CONSECRATION_DAMAGE, true, nullptr, nullptr, caster->GetGUID());

                if (caster->HasSpell(SPELL_PALADIN_CONSECRATED_GROUND))
                    caster->CastSpell(tempSumm, SPELL_PALADIN_CONSECRATION_HEAL, true, nullptr, nullptr, caster->GetGUID());
            }

            timeInterval -= 1000;
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_pal_consecrationAI(areatrigger);
    }
};

void AddSC_paladin_spell_scripts()
{
    new spell_pal_activate_forbearance();
    new spell_pal_bastion_of_light();
    new spell_pal_blade_of_wrath_proc();
    new spell_pal_blinding_light();
    //new spell_pal_cleanse();
    new spell_pal_crusaders_might();
    new spell_pal_divine_intervention();
    new spell_pal_divine_purpose();
    new spell_pal_divine_purpose_proc();
    new spell_pal_divine_shield();
    new spell_pal_divine_steed();
    new spell_pal_divine_storm();
    new spell_pal_divine_storm_dummy();
    new spell_pal_execute_sentence();
    new spell_pal_flash_of_light();
    new spell_pal_grand_crusader();
    new spell_pal_grand_crusader_proc();
    new spell_pal_hammer_of_the_righteous();
    new spell_pal_hand_of_sacrifice();
    new spell_pal_holy_light();
    new spell_pal_holy_shock();
    new spell_pal_holy_prism();
    new spell_pal_holy_prism_effect();
    new spell_pal_holy_prism_visual();
    new spell_pal_holy_shield();
    new spell_pal_infusion_of_light();
    new spell_pal_judgment();
    new spell_pal_judgment_of_light();
    new spell_pal_judgment_of_light_proc();
    new spell_pal_judgement_of_the_pure();
    new spell_pal_justicars_vengeance();
    new spell_pal_lights_hammer();
    new spell_pal_lights_hammer_tick();
    new spell_pal_light_of_dawn();
    new spell_pal_light_of_dawn_trigger();
    new spell_pal_light_of_the_martyr();
    new spell_pal_light_of_the_protector();
    new spell_pal_shield_of_the_righteous();
    new spell_pal_shield_of_vengeance();
    new spell_pal_templar_s_verdict();
    new spell_pal_the_fire_of_justice();
    new spell_pal_word_of_glory();
    new spell_pal_zeal();
    new spell_pal_greater_blessing_of_kings();
    new spell_pal_divine_hammer();
    new spell_pal_ardent_defender();
    RegisterSpellScript(spell_pal_seraphim);

    // NPC Scripts
    new npc_pal_lights_hammer();

    // Area Trigger scripts
    new at_pal_consecration();
}
