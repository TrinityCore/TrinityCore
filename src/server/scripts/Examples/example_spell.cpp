/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"

class spell_ex_49375 : public SpellHandlerScript
{
    public:
        spell_ex_49375() : SpellHandlerScript("spell_ex_49375") { }

        class spell_ex_49375SpellScript : public SpellScript
        {
            std::string localVariable;
            char * localVariable2;

            // effect handler hook - effIndex - effIndex of handled effect of a spell
            void HandleDummy(SpellEffIndex effIndex)
            {
                // we're handling SPELL_EFFECT_DUMMY in effIndex 0 here
                sLog.outError("WE ARE HANDLING DUMMY!");
                sLog.outError(localVariable.c_str());
                // make caster cast a spell on a unit target of effect
                if (Unit * target = GetHitUnit())
                    GetCaster()->CastSpell(target, 70522, true);
            };

            void HandleBeforeHit()
            {
                sLog.outError("Spell is about to hit target!");
            }

            void HandleOnHit()
            {
                sLog.outError("Spell just hit target!");
            }

            void HandleAfterHit()
            {
                sLog.outError("Spell just finished hitting target!");
            }

            void Register()
            {
                // we're registering our function here
                // function HandleDummy will be called when unit is hit by spell, just before default effect 0 handler
                EffectHandlers += EffectHandlerFn(spell_ex_49375SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                // this will prompt an error on startup because effect 0 of spell 49375 is set to SPELL_EFFECT_DUMMY, not SPELL_EFFECT_APPLY_AURA
                //EffectHandlers += EffectHandlerFn(spell_gen_49375SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
                // this will make HandleDummy function to be called on first != 0 effect of spell 49375
                //EffectHandlers += EffectHandlerFn(spell_gen_49375SpellScript::HandleDummy, EFFECT_FIRST_FOUND, SPELL_EFFECT_ANY);
                // this will make HandleDummy function to be called on all != 0 effect of spell 49375
                //EffectHandlers += EffectHandlerFn(spell_gen_49375SpellScript::HandleDummy, EFFECT_ALL, SPELL_EFFECT_ANY);
                // bind handler to BeforeHit event of the spell
                BeforeHit += HitHandlerFn(spell_ex_49375SpellScript::HandleBeforeHit);
                // bind handler to OnHit event of the spell
                OnHit += HitHandlerFn(spell_ex_49375SpellScript::HandleOnHit);
                // bind handler to AfterHit event of the spell
                AfterHit += HitHandlerFn(spell_ex_49375SpellScript::HandleAfterHit);
            };

            // function called on server startup
            // checks if script has data required for it to work
            bool Validate(SpellEntry const * spellEntry)
            {
                // check if spellid 1 exists in dbc
                if (!sSpellStore.LookupEntry(70522))
                    return false;
                return true;
            };

            // function called just after script is added to spell
            // we initialize local variables if needed
            bool Load()
            {
                localVariable = "WE'RE USING LOCAL VARIABLE";
                localVariable2 = new char;
                return true;
                // script will be immediately removed from the spell
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
        };

        // function which creates SpellScript
        SpellScript *GetSpellScript() const
        {
            return new spell_ex_49375SpellScript();
        }
};
/* empty script for copypasting
class spell_ex : public SpellHandlerScript
{
    public:
        spell_ex() : SpellHandlerScript("spell_ex") { }

        class spell_ex_SpellScript : public SpellScript
        {
            void Function(SpellEffIndex effIndex){}
            void Register()
            {
                //EffectHandlers += EffectHandlerFn(spell_ex_SpellScript::Function, EFFECT_ANY, SPELL_EFFECT_ANY);
            }

            //bool Load(){return true;}
            //void Unload(){}
            //bool Validate(SpellEntry const * spellEntry){return true;}
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_ex_SpellScript();
        }
};

*/

// this function has to be added to function set in ScriptLoader.cpp
void AddSC_example_spell_scripts()
{
/* Commented out to prevent loading errors
    new spell_ex_49375;
*/
}