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

#include "Util.h"
#include "SharedDefines.h"
#include "SpellAuraDefines.h"

class Unit;
struct SpellEntry;
class SpellScript;
class Spell;
class Aura;
class AuraEffect;
struct SpellModifier;
class Creature;
class GameObject;
class DynamicObject;
class Player;
class Item;
class WorldLocation;
class WorldObject;

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
        virtual bool Validate(SpellEntry const * /*spellEntry*/) {return true;};
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
        typedef void(SpellScript::*SpellEffectFnType)(SpellEffIndex);
        typedef void(SpellScript::*SpellHitFnType)();

        class EffectHandler : public  _SpellScript::EffectNameCheck, public _SpellScript::EffectHook
        {
            public:
                EffectHandler(SpellEffectFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName);
                std::string ToString();
                bool CheckEffect(SpellEntry const * spellEntry, uint8 effIndex);
                void Call(SpellScript * spellScript, SpellEffIndex effIndex);
            private:
                SpellEffectFnType pEffectHandlerScript;
        };
        typedef SpellHitFnType HitHandler;
    public:
        bool _Validate(SpellEntry const * entry, const char * scriptname);
        bool _Load(Spell * spell);
        void _InitHit();
        bool _IsEffectPrevented(SpellEffIndex effIndex) {return m_hitPreventEffectMask & (1<<effIndex);};
        bool _IsDefaultEffectPrevented(SpellEffIndex effIndex) {return m_hitPreventDefaultEffectMask & (1<<effIndex);};
    private:
        Spell * m_spell;
        uint8 m_hitPreventEffectMask;
        uint8 m_hitPreventDefaultEffectMask;
    public:
        //
        // SpellScript interface
        // hooks to which you can attach your functions
        //
        // example: OnEffect += SpellEffectFn(class::function, EffectIndexSpecifier, EffectNameSpecifier);
        // where function is void function(SpellEffIndex effIndex)
        HookList<EffectHandler> OnEffect;
        #define SpellEffectFn(F, I, N) EffectHandler((SpellEffectFnType)&F, I, N)

        // example: BeforeHit += SpellHitFn(class::function);
        HookList<HitHandler> BeforeHit;
        // example: OnHit += SpellHitFn(class::function);
        HookList<HitHandler> OnHit;
        // example: AfterHit += SpellHitFn(class::function);
        HookList<HitHandler> AfterHit;
        // where function is: void function()
        #define SpellHitFn(F) (SpellHitFnType)&F

        // hooks are executed in following order, at specified event of spell:
        // 1. BeforeHit - executed just before spell hits a target
        // 2. OnEffect - executed just before specified effect handler call
        // 3. OnHit - executed just before spell deals damage and procs auras
        // 4. AfterHit - executed just after spell finishes all it's jobs for target

        //
        // methods allowing interaction with Spell object
        //
        // methods useable during all spell handling phases
        Unit * GetCaster();
        Unit * GetOriginalCaster();
        SpellEntry const * GetSpellInfo();

        // methods useable after spell targets are set
        // returns: destination of the spell if exists, otherwise NULL
        WorldLocation * GetDest();

        // methods useable only during spell hit on target phase:

        // returns: target of current effect if it was Unit otherwise NULL
        Unit * GetHitUnit();
        // returns: target of current effect if it was Creature otherwise NULL
        Creature * GetHitCreature();
        // returns: target of current effect if it was Player otherwise NULL
        Player * GetHitPlayer();
        // returns: target of current effect if it was Item otherwise NULL
        Item * GetHitItem();
        // returns: target of current effect if it was GameObject otherwise NULL
        GameObject * GetHitGObj();
        // setter/getter for for damage done by spell to target of spell hit
        int32 GetHitDamage();
        void SetHitDamage(int32 damage);
        void PreventHitDamage() { SetHitDamage(0); };
        // setter/getter for for heal done by spell to target of spell hit
        int32 GetHitHeal();
        void SetHitHeal(int32 heal);
        void PreventHitHeal() { SetHitHeal(0); };

        // returns current spell hit target aura
        Aura * GetHitAura();
        // prevents applying aura on current spell hit target
        void PreventHitAura();

        // prevents effect execution on current spell hit target
        // including other effect/hit scripts
        // will not work on aura/damage/heal
        // will not work if effects were already handled
        void PreventHitEffect(SpellEffIndex effIndex);

        // prevents default effect execution on current spell hit target
        // will not work on aura/damage/heal effects
        // will not work if effects were already handled
        void PreventHitDefaultEffect(SpellEffIndex effIndex);

        // method avalible only in EffectHandler method
        int32 GetEffectValue();

        // returns: cast item if present.
        Item * GetCastItem();

        // Creates item. Calls Spell::DoCreateItem method.
        void CreateItem(uint32 effIndex, uint32 itemId);
};

class AuraScript : public _SpellScript
{
    // internal use classes & functions
    // DO NOT OVERRIDE THESE IN SCRIPTS
    public:
        typedef void(AuraScript::*AuraEffectApplicationModeFnType)(AuraEffect const *, AuraApplication const *, AuraEffectHandleModes mode);
        typedef void(AuraScript::*AuraEffectPeriodicFnType)(AuraEffect const *, AuraApplication const *);
        typedef void(AuraScript::*AuraEffectUpdatePeriodicFnType)(AuraEffect *);
        typedef void(AuraScript::*AuraEffectCalcAmountFnType)(AuraEffect const *, int32 &, bool &);
        typedef void(AuraScript::*AuraEffectCalcPeriodicFnType)(AuraEffect const *, bool &, int32 &);
        typedef void(AuraScript::*AuraEffectCalcSpellModFnType)(AuraEffect const *, SpellModifier *&);

        class EffectBase : public  _SpellScript::EffectAuraNameCheck, public _SpellScript::EffectHook
        {
            public:
                EffectBase(uint8 _effIndex, uint16 _effName);
                std::string ToString();
                bool CheckEffect(SpellEntry const * spellEntry, uint8 effIndex);
        };
        class EffectPeriodicHandler : public EffectBase
        {
            public:
                EffectPeriodicHandler(AuraEffectPeriodicFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName);
                void Call(AuraScript * auraScript, AuraEffect const * _aurEff, AuraApplication const * _aurApp);
            private:
                AuraEffectPeriodicFnType pEffectHandlerScript;
        };
        class EffectUpdatePeriodicHandler : public EffectBase
        {
            public:
                EffectUpdatePeriodicHandler(AuraEffectUpdatePeriodicFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName);
                void Call(AuraScript * auraScript, AuraEffect * aurEff);
            private:
                AuraEffectUpdatePeriodicFnType pEffectHandlerScript;
        };
        class EffectCalcAmountHandler : public EffectBase
        {
            public:
                EffectCalcAmountHandler(AuraEffectCalcAmountFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName);
                void Call(AuraScript * auraScript, AuraEffect const* aurEff, int32 & amount, bool & canBeRecalculated);
            private:
                AuraEffectCalcAmountFnType pEffectHandlerScript;
        };
        class EffectCalcPeriodicHandler : public EffectBase
        {
            public:
                EffectCalcPeriodicHandler(AuraEffectCalcPeriodicFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName);
                void Call(AuraScript * auraScript, AuraEffect const* aurEff, bool & isPeriodic, int32 & periodicTimer);
            private:
                AuraEffectCalcPeriodicFnType pEffectHandlerScript;
        };
        class EffectCalcSpellModHandler : public EffectBase
        {
            public:
                EffectCalcSpellModHandler(AuraEffectCalcSpellModFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName);
                void Call(AuraScript * auraScript, AuraEffect const* aurEff, SpellModifier *& spellMod);
            private:
                AuraEffectCalcSpellModFnType pEffectHandlerScript;
        };
        class EffectApplyHandler : public EffectBase
        {
            public:
                EffectApplyHandler(AuraEffectApplicationModeFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName, AuraEffectHandleModes _mode);
                void Call(AuraScript * auraScript, AuraEffect const * _aurEff, AuraApplication const * _aurApp, AuraEffectHandleModes _mode);
            private:
                AuraEffectApplicationModeFnType pEffectHandlerScript;
                AuraEffectHandleModes mode;
        };
    public:
        bool _Validate(SpellEntry const * entry, const char * scriptname);
        bool _Load(Aura * aura);
        void _ResetDefault() { m_default = true; }
        bool _IsDefaultActionPrevented(SpellEffIndex /*effIndex*/) {return !m_default;};
        void PreventDefaultAction() { m_default = false; };
    private:
        Aura * m_aura;
        bool m_default;
    public:
        //
        // AuraScript interface
        // hooks to which you can attach your functions
        //
        // executed when periodic aura effect is applied with specified mode to target
        // example: OnEffectApply += AuraEffectApplyFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier, AuraEffectHandleModes);
        HookList<EffectApplyHandler> OnEffectApply;
        #define AuraEffectApplyFn(F, I, N, M) EffectApplyHandler((AuraEffectApplicationModeFnType)&F, I, N, M)

        // executed when periodic aura effect is removed with specified mode from target
        // example: OnEffectRemove += AuraEffectRemoveFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier, AuraEffectHandleModes);
        // where function is: void function (AuraEffect const * aurEff, AuraApplication const * aurApp, AuraEffectHandleModes mode);
        HookList<EffectApplyHandler> OnEffectRemove;
        #define AuraEffectRemoveFn(F, I, N, M) EffectApplyHandler((AuraEffectApplicationModeFnType)&F, I, N, M)

        // executed when periodic aura effect ticks on target
        // example: OnEffectPeriodic += AuraEffectPeriodicFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
        // where function is: void function (AuraEffect const * aurEff, AuraApplication const * aurApp, AuraEffectHandleModes mode);
        HookList<EffectPeriodicHandler> OnEffectPeriodic;
        #define AuraEffectPeriodicFn(F, I, N) EffectPeriodicHandler((AuraEffectPeriodicFnType)&F, I, N)

        // executed when periodic aura effect is updated
        // example: OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
        // where function is: void function (AuraEffect const * aurEff, AuraApplication const * aurApp);
        HookList<EffectUpdatePeriodicHandler> OnEffectUpdatePeriodic;
        #define AuraEffectUpdatePeriodicFn(F, I, N) EffectUpdatePeriodicHandler((AuraEffectUpdatePeriodicFnType)&F, I, N)

        // executed when aura effect calculates amount
        // example: OnEffectCalcAmount += AuraEffectCalcAmounFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
        // where function is: void function (AuraEffect * aurEff, int32 & amount, bool & canBeRecalculated);
        HookList<EffectCalcAmountHandler> OnEffectCalcAmount;
        #define AuraEffectCalcAmountFn(F, I, N) EffectCalcAmountHandler((AuraEffectCalcAmountFnType)&F, I, N)

        // executed when aura effect calculates periodic data
        // example: OnEffectCalcPeriodic += AuraEffectCalcPeriodicFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
        // where function is: void function (AuraEffect const * aurEff, bool & isPeriodic, int32 & amplitude);
        HookList<EffectCalcPeriodicHandler> OnEffectCalcPeriodic;
        #define AuraEffectCalcPeriodicFn(F, I, N) EffectCalcPeriodicHandler((AuraEffectCalcPeriodicFnType)&F, I, N)

        // executed when aura effect calculates spellmod
        // example: OnEffectCalcSpellMod += AuraEffectCalcSpellModFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
        // where function is: void function (AuraEffect const * aurEff, SpellModifier *& spellMod);
        HookList<EffectCalcSpellModHandler> OnEffectCalcSpellMod;
        #define AuraEffectCalcSpellModFn(F, I, N) EffectCalcSpellModHandler((AuraEffectCalcSpellModFnType)&F, I, N)

        // AuraScript interface - functions which are redirecting to Aura class

        // returns proto of the spell
        SpellEntry const* GetSpellProto() const;
        // returns spellid of the spell
        uint32 GetId() const;

        // returns guid of object which casted the aura (m_originalCaster of the Spell class)
        uint64 const& GetCasterGUID() const;
        // returns unit which casted the aura or NULL if not avalible (caster logged out for example)
        Unit* GetCaster() const;
        // returns object on which aura was casted, target for non-area auras, area aura source for area auras
        WorldObject * GetOwner() const;
        // returns owner if it's unit, NULL otherwise
        Unit * GetUnitOwner() const;
        // returns owner if it's dynobj, NULL otherwise
        DynamicObject * GetDynobjOwner() const;

        // removes aura with remove mode (see AuraRemoveMode enum)
        void Remove(uint32 removeMode = 0);
        // returns aura object of script
        Aura * GetAura() const;

        // returns type of the aura, may be dynobj owned aura or unit owned aura
        AuraObjectType GetType() const;

        // aura duration manipulation - when duration goes to 0 aura is removed
        int32 GetDuration() const;
        void SetDuration(int32 duration, bool withMods = false);
        // sets duration to maxduration
        void RefreshDuration();
        time_t GetApplyTime() const;
        int32 GetMaxDuration() const;
        void SetMaxDuration(int32 duration);
        // expired - duration just went to 0
        bool IsExpired() const;
        // permament - has infinite duration
        bool IsPermanent() const;

        // charges manipulation - 0 - not charged aura
        uint8 GetCharges() const;
        void SetCharges(uint8 charges);
        // returns true if last charge dropped
        bool DropCharge();

        // stack amount manipulation
        uint8 GetStackAmount() const;
        void SetStackAmount(uint8 num, bool applied = true);
        bool ModStackAmount(int32 num);

        // passive - "working in background", not saved, not removed by immonities, not seen by player
        bool IsPassive() const;
        // death persistent - not removed on death
        bool IsDeathPersistent() const;

        // check if aura has effect of given effindex
        bool HasEffect(uint8 effIndex) const;
        // returns aura effect of given effect index or NULL
        AuraEffect * GetEffect(uint8 effIndex) const;

        // check if aura has effect of given aura type
        bool HasEffectType(AuraType type) const;
};

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
