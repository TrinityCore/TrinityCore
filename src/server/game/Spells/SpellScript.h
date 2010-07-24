/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __SPELL_SCRIPT_H
#define __SPELL_SCRIPT_H

#include "SharedDefines.h"

class Unit;
struct SpellEntry;
class SpellScript;
class Spell;
class Creature;
class GameObject;
class Player;
class Item;

typedef void(SpellScript::*EffectHandlerFnType)(SpellEffIndex);

#define SPELL_EFFECT_ANY (uint16)-1
#define SPELL_AURA_ANY (uint16)-1

// helper class from which SpellScript and SpellAura derive, use these classes instead
class _SpellScript
{
    // internal use classes & functions
    // DO NOT OVERRIDE THESE IN SCRIPTS
    protected:
        virtual bool _Validate(SpellEntry const * entry, const char * scriptname);
    protected:
        class EffectHook
        {
            public:
                EffectHook(uint8 _effIndex);
                uint8 GetAffectedEffectsMask(SpellEntry const * spellEntry);
                bool IsEffectAffected(SpellEntry const * spellEntry, uint8 effIndex);
                virtual bool CheckEffect(SpellEntry const * spellEntry, uint8 effIndex) = 0;
                std::string EffIndexToString();
            protected:
                uint8 effIndex;
        };
        class EffectNameCheck
        {
            public:
                EffectNameCheck(uint16 _effName) {effName = _effName;};
                bool Check(SpellEntry const * spellEntry, uint8 effIndex);
                std::string ToString();
            private:
                uint16 effName;
        };
        class EffectAuraNameCheck
        {
            public:
                EffectAuraNameCheck(uint16 _effAurName) { effAurName = _effAurName; }
                bool Check(SpellEntry const * spellEntry, uint8 effIndex);
                std::string ToString();
            private:
                uint16 effAurName;
        };
    public:
        //
        // SpellScript/AuraScript interface base
        // these functions are safe to override, see notes below for usage instructions
        // 
        // Function in which handler functions are registered, must be implemented in script
        virtual void Register() = 0;
        // Function called on server startup, if returns false script won't be used in core
        // use for: dbc/template data presence/correctness checks
        virtual bool Validate(SpellEntry const * spellEntry) {return true;};
        // Function called when script is created, if returns false script will be unloaded afterwards
        // use for: initializing local script variables (DO NOT USE CONSTRUCTOR FOR THIS PURPOSE!)
        virtual bool Load() {return true;};
        // Function called when script is destroyed
        // use for: deallocating memory allocated by script
        virtual void Unload() {};
};

class SpellScript : public _SpellScript
{
    // internal use classes & functions
    // DO NOT OVERRIDE THESE IN SCRIPTS
    public:
        class EffectHandler : public  _SpellScript::EffectNameCheck, public _SpellScript::EffectHook
        {
            public:
                EffectHandler(EffectHandlerFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName);
                std::string ToString();
                bool CheckEffect(SpellEntry const * spellEntry, uint8 effIndex);
                void Call(SpellScript * spellScript, SpellEffIndex effIndex);
            private:
                EffectHandlerFnType pEffectHandlerScript;
        };
    public:
        bool _Validate(SpellEntry const * entry, const char * scriptname);
        bool _Load(Spell * spell);
    private:
        Spell * m_spell;
    public:
        //
        // SpellScript interface
        // hooks to which you can attach your functions
        // 
        // List of functions registered by EffectHandlerFn
        // allows more than one hook
        // example EffectHandlers += EffectHandlerFn(class::function, EffectIndexSpecifier, EffectNameSpecifier);
        HookList<EffectHandler> EffectHandlers;

        // methods allowing interaction with Spell object
        Unit * GetCaster();
        Unit * GetOriginalCaster();
        SpellEntry const * GetSpellInfo();
        // functions useable only during spell hit on target phase
        Unit * GetEffectUnitTarget();
        Creature * GetEffectCreatureTarget();
        Player * GetEffectPlayerTarget();
        Item * GetEffectItemTarget();
        GameObject * GetEffectGOTarget();
        int32 GetEffectValue();
};
// SpellScript interface
//
// function registering macros, should be used only in Register()
//
// EffectHandlerFn
// called at: Spell hit on unit, just before default effect handler, called for effects matching EffectIndexSpecifier and EffectNameSpecifier conditions
// hook parameter is current effect index
// parameters: function to call, EffectIndexSpecifier, EffectNameSpecifier
#define EffectHandlerFn(F, I, N) EffectHandler((EffectHandlerFnType)&F, I, N)

//
// definitions:
//
// EffectIndexSpecifier - specifies conditions for effects
// EFFECT_0 - first effect matches
// EFFECT_1 - second effect matches
// EFFECT_2 - third effect matches
// EFFECT_FIRST_FOUND - first effect matching other conditions matches
// EFFECT_ALL - all effects of spell match 
//
// EffectNameSpecifier - specifies conditions for spell effect names
// SPELL_EFFECT_ANY - any effect but not 0 matches condition
// SPELL_EFFECT_XXX - one of values of enum SpellEffects - effect with equal name matches
//

#endif // __SPELL_SCRIPT_H
