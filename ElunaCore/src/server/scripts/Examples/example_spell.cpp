/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
 * An example of a spell script file
 * to bind a script to spell you have to add entry for it in `spell_script_names`
 * where `spell_id` is id of the spell to bind
 * and `ScriptName` is the name of a script assigned on registration
 */

#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "Player.h"

enum Spells
{
    SPELL_TRIGGERED = 18282
};

class spell_ex_5581 : public SpellScriptLoader
{
    public:
        spell_ex_5581() : SpellScriptLoader("spell_ex_5581") { }

        class spell_ex_5581SpellScript : public SpellScript
        {
            // initialize script, this macro does compile time check for type of the function - prevents possible issues
            // if you have assigned wrong type of function to a hook you'll receive type conversion error during build
            // this line is required, otherwise you'll get XXXHandlerFunction - identifier not found errors
            PrepareSpellScript(spell_ex_5581SpellScript);

            std::string localVariable;
            char* localVariable2;

            // function called on server startup
            // checks if script has data required for it to work
            bool Validate(SpellInfo const* /*spellEntry*/)
            {
                // check if spellid 70522 exists in dbc, we will trigger it later
                if (!sSpellMgr->GetSpellInfo(SPELL_TRIGGERED))
                    return false;
                return true;
            }

            // function called just after script is added to spell
            // we initialize local variables if needed
            bool Load()
            {
                localVariable = "we're using local variable";
                localVariable2 = new char();
                return true;
                // return false - script will be immediately removed from the spell
                // for example - we don't want this script to be executed on a creature
                // if (GetCaster()->GetTypeID() != TYPEID_PLAYER)
                //     return false;
            }

            // function called just before script delete
            // we free allocated memory
            void Unload()
            {
                delete localVariable2;
            }

            void HandleBeforeCast()
            {
                // this hook is executed before anything about casting the spell is done
                // after this hook is executed all the machinery starts
                sLog->outInfo(LOG_FILTER_GENERAL, "Caster just finished preparing the spell (cast bar has expired)");
            }

            void HandleOnCast()
            {
                // cast is validated and spell targets are selected at this moment
                // this is a last place when the spell can be safely interrupted
                sLog->outInfo(LOG_FILTER_GENERAL, "Spell is about to do take reagents, power, launch missile, do visuals and instant spell effects");
            }

            void HandleAfterCast()
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "All immediate Actions for the spell are finished now");
                // this is a safe for triggering additional effects for a spell without interfering
                // with visuals or with other effects of the spell
                //GetCaster()->CastSpell(target, SPELL_TRIGGERED, true);
            }

            SpellCastResult CheckRequirement()
            {
                // in this hook you can add additional requirements for spell caster (and throw a client error if reqs're not passed)
                // in this case we're disallowing to select non-player as a target of the spell
                //if (!GetExplTargetUnit() || GetExplTargetUnit()->ToPlayer())
                    //return SPELL_FAILED_BAD_TARGETS;
                return SPELL_CAST_OK;
            }


            void HandleDummyLaunch(SpellEffIndex /*effIndex*/)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Spell %u with SPELL_EFFECT_DUMMY is just launched!", GetSpellInfo()->Id);
            }

            void HandleDummyLaunchTarget(SpellEffIndex /*effIndex*/)
            {
                uint64 targetGUID = 0;
                if (Unit* unitTarget = GetHitUnit())
                    targetGUID = unitTarget->GetGUID();
                // we're handling SPELL_EFFECT_DUMMY in effIndex 0 here
                sLog->outInfo(LOG_FILTER_GENERAL, "Spell %u with SPELL_EFFECT_DUMMY is just launched at it's target: " UI64FMTD "!", GetSpellInfo()->Id, targetGUID);
            }

            void HandleDummyHit(SpellEffIndex /*effIndex*/)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Spell %u with SPELL_EFFECT_DUMMY has hit!", GetSpellInfo()->Id);
            }

            void HandleDummyHitTarget(SpellEffIndex /*effIndex*/)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "SPELL_EFFECT_DUMMY is hits it's target!");
                // make caster cast a spell on a unit target of effect
                if (Unit* target = GetHitUnit())
                    GetCaster()->CastSpell(target, SPELL_TRIGGERED, true);
            }

            void HandleBeforeHit()
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Spell is about to hit target!");
            }

            void HandleOnHit()
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Spell just hit target!");
            }

            void HandleAfterHit()
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Spell just finished hitting target!");
            }

            void FilterTargets(std::list<Unit*>& /*targetList*/)
            {
                // usually you want this call for Area Target spells
                sLog->outInfo(LOG_FILTER_GENERAL, "Spell is about to add targets from targetList to final targets!");
            }

            // register functions used in spell script - names of these functions do not matter
            void Register()
            {
                // we're registering our functions here
                BeforeCast += SpellCastFn(spell_ex_5581SpellScript::HandleBeforeCast);
                OnCast += SpellCastFn(spell_ex_5581SpellScript::HandleOnCast);
                AfterCast += SpellCastFn(spell_ex_5581SpellScript::HandleAfterCast);
                OnCheckCast += SpellCheckCastFn(spell_ex_5581SpellScript::CheckRequirement);
                // function HandleDummy will be called when spell is launched, independant from targets selected for spell, just before default effect 0 launch handler
                OnEffectLaunch += SpellEffectFn(spell_ex_5581SpellScript::HandleDummyLaunch, EFFECT_0, SPELL_EFFECT_DUMMY);
                // function HandleDummy will be called when spell is launched at target, just before default effect 0 launch at target handler
                OnEffectLaunchTarget += SpellEffectFn(spell_ex_5581SpellScript::HandleDummyLaunchTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
                // function HandleDummy will be called when spell hits it's destination, independant from targets selected for spell, just before default effect 0 hit handler
                OnEffectHit += SpellEffectFn(spell_ex_5581SpellScript::HandleDummyHit, EFFECT_0, SPELL_EFFECT_DUMMY);
                // function HandleDummy will be called when unit is hit by spell, just before default effect 0 hit target handler
                OnEffectHitTarget += SpellEffectFn(spell_ex_5581SpellScript::HandleDummyHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
                // this will prompt an error on startup because effect 0 of spell 49375 is set to SPELL_EFFECT_DUMMY, not SPELL_EFFECT_APPLY_AURA
                //OnEffectHitTarget += SpellEffectFn(spell_gen_49375SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
                // this will make HandleDummy function to be called on first != 0 effect of spell 49375
                //OnEffectHitTarget += SpellEffectFn(spell_gen_49375SpellScript::HandleDummy, EFFECT_FIRST_FOUND, SPELL_EFFECT_ANY);
                // this will make HandleDummy function to be called on all != 0 effect of spell 49375
                //OnEffectHitTarget += SpellEffectFn(spell_gen_49375SpellScript::HandleDummy, EFFECT_ALL, SPELL_EFFECT_ANY);
                // bind handler to BeforeHit event of the spell
                BeforeHit += SpellHitFn(spell_ex_5581SpellScript::HandleBeforeHit);
                // bind handler to OnHit event of the spell
                OnHit += SpellHitFn(spell_ex_5581SpellScript::HandleOnHit);
                // bind handler to AfterHit event of the spell
                AfterHit += SpellHitFn(spell_ex_5581SpellScript::HandleAfterHit);
                // bind handler to OnUnitTargetSelect event of the spell
                //OnUnitTargetSelect += SpellUnitTargetFn(spell_ex_5581SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER);
            }
        };

        // function which creates SpellScript
        SpellScript* GetSpellScript() const
        {
            return new spell_ex_5581SpellScript();
        }
};

class spell_ex_66244 : public SpellScriptLoader
{
    public:
        spell_ex_66244() : SpellScriptLoader("spell_ex_66244") { }

        class spell_ex_66244AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ex_66244AuraScript);
            // function called on server startup
            // checks if script has data required for it to work
            bool Validate(SpellInfo const* /*spellEntry*/)
            {
                // check if spellid exists in dbc, we will trigger it later
                if (!sSpellMgr->GetSpellInfo(SPELL_TRIGGERED))
                    return false;
                return true;
            }

            // function called in aura constructor
            // we initialize local variables if needed
            bool Load()
            {
                // do not load script if aura is casted by player or caster not avalible
                if (Unit* caster = GetCaster())
                    if (caster->GetTypeId() == TYPEID_PLAYER)
                        return true;
                return false;
            }


            void HandleOnEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Aura Effect is about to be applied on target!");
                // this hook allows you to prevent execution of AuraEffect handler, or to replace it with your own handler
                //PreventDefaultAction();
            }
            void HandleOnEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Aura Effect is about to be removed from target!");
                // this hook allows you to prevent execution of AuraEffect handler, or to replace it with your own handler
                //PreventDefaultAction();
            }

            void HandleAfterEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Aura Effect has just been applied on target!");
                Unit* target = GetTarget();
                // cast spell on target on aura apply
                target->CastSpell(target, SPELL_TRIGGERED, true);
            }

            void HandleAfterEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Aura Effect has just been just removed from target!");
                Unit* target = GetTarget();
                Unit* caster = GetCaster();
                // caster may be not avalible (logged out for example)
                if (!caster)
                    return;
                // cast spell on caster on aura remove
                target->CastSpell(caster, SPELL_TRIGGERED, true);
            }

            void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Perioidic Aura Effect is does a tick on target!");
                Unit* target = GetTarget();
                // aura targets damage self on tick
                target->DealDamage(target, 100);
            }

            void HandleEffectPeriodicUpdate(AuraEffect* aurEff)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Perioidic Aura Effect is now updated!");
                // we're doubling aura amount every tick
                aurEff->ChangeAmount(aurEff->GetAmount() * 2);
            }

            void HandleEffectCalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Amount of Aura Effect is being calculated now!");
                // we're setting amount to 100
                amount = 100;
                // amount will be never recalculated due to applying passive aura
                canBeRecalculated = false;
            }

            void HandleEffectCalcPeriodic(AuraEffect const* /*aurEff*/, bool& isPeriodic, int32& amplitude)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Periodic data of Aura Effect is being calculated now!");
                // we're setting aura to be periodic and tick every 10 seconds
                isPeriodic = true;
                amplitude = 2 * IN_MILLISECONDS;
            }

            void HandleEffectCalcSpellMod(AuraEffect const* /*aurEff*/, SpellModifier*& spellMod)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "SpellMod data of Aura Effect is being calculated now!");
                // we don't want spellmod for example
                if (spellMod)
                {
                    delete spellMod;
                    spellMod = NULL;
                }
                /*
                // alternative: we want spellmod for spell which doesn't have it
                if (!spellMod)
                {
                    spellMod = new SpellModifier(GetAura());
                    spellMod->op = SPELLMOD_DOT;
                    spellMod->type = SPELLMOD_PCT;
                    spellMod->spellId = GetId();
                    spellMod->mask[1] = 0x00002000;
                }
                */
            }

            // function registering
            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_ex_66244AuraScript::HandleOnEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_ex_66244AuraScript::HandleOnEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                // AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK - makes handler to be called when aura is reapplied on target
                AfterEffectApply += AuraEffectApplyFn(spell_ex_66244AuraScript::HandleAfterEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                AfterEffectRemove += AuraEffectRemoveFn(spell_ex_66244AuraScript::HandleAfterEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_ex_66244AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
                OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_ex_66244AuraScript::HandleEffectPeriodicUpdate, EFFECT_0, SPELL_AURA_DUMMY);
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_ex_66244AuraScript::HandleEffectCalcAmount, EFFECT_0, SPELL_AURA_DUMMY);
                DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_ex_66244AuraScript::HandleEffectCalcPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
                DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_ex_66244AuraScript::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
                /*OnApply += AuraEffectApplyFn();
                OnRemove += AuraEffectRemoveFn();
                DoCheckAreaTarget += AuraCheckAreaTargetFn();*/
            }
            /*
            void OnApply()
            {
            }

            void OnRemove()
            {
            }

            bool DoCheckAreaTarget(Unit* proposedTarget)
            {
            }*/
        };

        // function which creates AuraScript
        AuraScript* GetAuraScript() const
        {
            return new spell_ex_66244AuraScript();
        }
};

// example usage of OnEffectManaShield and AfterEffectManaShield hooks
// see spell_ex_absorb_aura, these hooks work the same as OnEffectAbsorb and AfterEffectAbsorb

// example usage of OnEffectAbsorb and AfterEffectAbsorb hooks
class spell_ex_absorb_aura : public SpellScriptLoader
{
    public:
        spell_ex_absorb_aura() : SpellScriptLoader("spell_ex_absorb_aura") { }

        class spell_ex_absorb_auraAuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ex_absorb_auraAuraScript);

            void HandleOnEffectAbsorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Our aura is now absorbing damage done to us!");
                // absorb whole damage done to us
                absorbAmount = dmgInfo.GetDamage();
            }

            void HandleAfterEffectAbsorb(AuraEffect* /*aurEff*/, DamageInfo & /*dmgInfo*/, uint32 & absorbAmount)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Our aura has absorbed %u damage!", absorbAmount);
            }

            // function registering
            void Register()
            {
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_ex_absorb_auraAuraScript::HandleOnEffectAbsorb, EFFECT_0);
                AfterEffectAbsorb += AuraEffectAbsorbFn(spell_ex_absorb_auraAuraScript::HandleAfterEffectAbsorb, EFFECT_0);
            }
        };

        // function which creates AuraScript
        AuraScript* GetAuraScript() const
        {
            return new spell_ex_absorb_auraAuraScript();
        }
};

class spell_ex_463 : public SpellScriptLoader
{
    public:
        spell_ex_463() : SpellScriptLoader("spell_ex_463") { }

        class spell_ex_463AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ex_463AuraScript);

            bool CheckAreaTarget(Unit* target)
            {
                sLog->outInfo(LOG_FILTER_GENERAL, "Area aura checks if unit is a valid target for it!");
                // in our script we allow only players to be affected
                return target->GetTypeId() == TYPEID_PLAYER;
            }
            void Register()
            {
                DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_ex_463AuraScript::CheckAreaTarget);
            }
        };

        // function which creates AuraScript
        AuraScript* GetAuraScript() const
        {
            return new spell_ex_463AuraScript();
        }
};

// this function has to be added to function set in ScriptLoader.cpp
void AddSC_example_spell_scripts()
{
    new spell_ex_5581;
    new spell_ex_66244;
    new spell_ex_absorb_aura;
    new spell_ex_463;
}

/* empty script for copypasting
class spell_ex : public SpellScriptLoader
{
    public:
        spell_ex() : SpellScriptLoader("spell_ex") { }

        class spell_ex_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ex_SpellScript);

            //bool Validate(SpellInfo const* spellEntry){return true;}
            //bool Load(){return true;}
            //void Unload(){}

            //void Function(SpellEffIndex effIndex) //OnEffect += SpellEffectFn(spell_ex_SpellScript::Function, EFFECT_ANY, SPELL_EFFECT_ANY);
            //void Function() //OnHit += SpellEffectFn(spell_ex_SpellScript::Function);
            void Register()
            {
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_ex_SpellScript();
        }
};
*/

/* empty script for copypasting
class spell_ex : public SpellScriptLoader
{
    public:
        spell_ex() : SpellScriptLoader("spell_ex") { }

        class spell_ex_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ex)
            //bool Validate(SpellInfo const* spellEntry){return true;}
            //bool Load(){return true;}
            //void Unload(){}

            //void spell_ex_SpellScript::Function(AuraEffect const* aurEff, AuraEffectHandleModes mode) //OnEffectApply += AuraEffectApplyFn(spell_ex_SpellScript::Function, EFFECT_ANY, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
            //void spell_ex_SpellScript::Function(AuraEffect const* aurEff, AuraEffectHandleModes mode) //OnEffectRemove += AuraEffectRemoveFn(spell_ex_SpellScript::Function, EFFECT_ANY, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
            //void spell_ex_SpellScript::Function(AuraEffect const* aurEff) //OnEffectPeriodic += AuraEffectPeriodicFn(spell_ex_SpellScript::Function, EFFECT_ANY, SPELL_AURA_ANY);
            //void spell_ex_SpellScript::Function(AuraEffect* aurEff) //OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_ex_SpellScript::Function, EFFECT_ANY, SPELL_AURA_ANY);
            //void spell_ex_SpellScript::Function(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated) //DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_ex_SpellScript::Function, EFFECT_ANY, SPELL_AURA_ANY);
            //void spell_ex_SpellScript::Function(AuraEffect const* aurEff, bool& isPeriodic, int32& amplitude) //OnEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_ex_SpellScript::Function, EFFECT_ANY, SPELL_AURA_ANY);
            //void spell_ex_SpellScript::Function(AuraEffect const* aurEff, SpellModifier*& spellMod) //OnEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_ex_SpellScript::Function, EFFECT_ANY, SPELL_AURA_ANY);
            void Register()
            {
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_ex_AuraScript();
        }
};
*/
