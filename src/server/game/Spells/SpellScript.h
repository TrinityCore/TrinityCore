/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

enum SpellScriptState
{
    SPELL_SCRIPT_STATE_NONE = 0,
    SPELL_SCRIPT_STATE_REGISTRATION,
    SPELL_SCRIPT_STATE_LOADING,
    SPELL_SCRIPT_STATE_UNLOADING,
};
#define SPELL_SCRIPT_STATE_END SPELL_SCRIPT_STATE_UNLOADING + 1

// helper class from which SpellScript and SpellAura derive, use these classes instead
class _SpellScript
{
    // internal use classes & functions
    // DO NOT OVERRIDE THESE IN SCRIPTS
    protected:
        virtual bool _Validate(SpellEntry const * entry);
    public:
        virtual ~_SpellScript() {}
        virtual void _Register();
        virtual void _Unload();
        virtual void _Init(const std::string * scriptname, uint32 spellId);
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

        uint8 m_currentScriptState;
        const std::string * m_scriptName;
        uint32 m_scriptSpellId;
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

// SpellScript interface - enum used for runtime checks of script function calls
enum SpellScriptHookType
{
    SPELL_SCRIPT_HOOK_EFFECT = SPELL_SCRIPT_STATE_END,
    SPELL_SCRIPT_HOOK_BEFORE_HIT,
    SPELL_SCRIPT_HOOK_HIT,
    SPELL_SCRIPT_HOOK_AFTER_HIT,
    SPELL_SCRIPT_HOOK_UNIT_TARGET_SELECT,
};
#define HOOK_SPELL_HIT_START SPELL_SCRIPT_HOOK_EFFECT
#define HOOK_SPELL_HIT_END SPELL_SCRIPT_HOOK_AFTER_HIT + 1
#define HOOK_SPELL_START SPELL_SCRIPT_HOOK_EFFECT
#define HOOK_SPELL_END SPELL_SCRIPT_HOOK_UNIT_TARGET_SELECT + 1
#define HOOK_SPELL_COUNT HOOK_SPELL_END - HOOK_SPELL_START

class SpellScript : public _SpellScript
{
    // internal use classes & functions
    // DO NOT OVERRIDE THESE IN SCRIPTS
    public:
        #define SPELLSCRIPT_FUNCTION_TYPE_DEFINES(CLASSNAME) \
            typedef void(CLASSNAME::*SpellEffectFnType)(SpellEffIndex); \
            typedef void(CLASSNAME::*SpellHitFnType)(); \
            typedef void(CLASSNAME::*SpellUnitTargetFnType)(std::list<Unit*>&); \

        SPELLSCRIPT_FUNCTION_TYPE_DEFINES(SpellScript)

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

        class HitHandler
        {
            public:
                HitHandler(SpellHitFnType _pHitHandlerScript);
                void Call(SpellScript * spellScript);
            private:
                SpellHitFnType pHitHandlerScript;
        };

        class UnitTargetHandler : public _SpellScript::EffectHook
        {
            public:
                UnitTargetHandler(SpellUnitTargetFnType _pUnitTargetHandlerScript, uint8 _effIndex, uint16 _targetType);
                std::string ToString();
                bool CheckEffect(SpellEntry const * spellEntry, uint8 targetType);
                void Call(SpellScript * spellScript, std::list<Unit*>& unitTargets);
            private:
                SpellUnitTargetFnType pUnitTargetHandlerScript;
                uint16 targetType;
        };

        #define SPELLSCRIPT_FUNCTION_CAST_DEFINES(CLASSNAME) \
        class EffectHandlerFunction : public SpellScript::EffectHandler { public: EffectHandlerFunction(SpellEffectFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName) : SpellScript::EffectHandler((SpellScript::SpellEffectFnType)_pEffectHandlerScript, _effIndex, _effName) {} }; \
        class HitHandlerFunction : public SpellScript::HitHandler { public: HitHandlerFunction(SpellHitFnType _pHitHandlerScript) : SpellScript::HitHandler((SpellScript::SpellHitFnType)_pHitHandlerScript) {} }; \
        class UnitTargetHandlerFunction : public SpellScript::UnitTargetHandler { public: UnitTargetHandlerFunction(SpellUnitTargetFnType _pUnitTargetHandlerScript, uint8 _effIndex, uint16 _targetType) : SpellScript::UnitTargetHandler((SpellScript::SpellUnitTargetFnType)_pUnitTargetHandlerScript, _effIndex, _targetType) {} }; \

        #define PrepareSpellScript(CLASSNAME) SPELLSCRIPT_FUNCTION_TYPE_DEFINES(CLASSNAME) SPELLSCRIPT_FUNCTION_CAST_DEFINES(CLASSNAME)
    public:
        bool _Validate(SpellEntry const * entry);
        bool _Load(Spell * spell);
        void _InitHit();
        bool _IsEffectPrevented(SpellEffIndex effIndex) { return m_hitPreventEffectMask & (1<<effIndex); }
        bool _IsDefaultEffectPrevented(SpellEffIndex effIndex) { return m_hitPreventDefaultEffectMask & (1<<effIndex); }
        void _PrepareScriptCall(SpellScriptHookType hookType);
        void _FinishScriptCall();
        bool IsInHitPhase() { return (m_currentScriptState >= HOOK_SPELL_HIT_START && m_currentScriptState < HOOK_SPELL_HIT_END); }
        bool IsInEffectHook() { return (m_currentScriptState == SPELL_SCRIPT_HOOK_EFFECT); }
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
        #define SpellEffectFn(F, I, N) EffectHandlerFunction(&F, I, N)

        // example: BeforeHit += SpellHitFn(class::function);
        HookList<HitHandler> BeforeHit;
        // example: OnHit += SpellHitFn(class::function);
        HookList<HitHandler> OnHit;
        // example: AfterHit += SpellHitFn(class::function);
        HookList<HitHandler> AfterHit;
        // where function is: void function()
        #define SpellHitFn(F) HitHandlerFunction(&F)

        // example: OnUnitTargetSelect += SpellUnitTargetFn(class::function, EffectIndexSpecifier, TargetsNameSpecifier);
        // where function is void function(std::list<Unit*>& targetList)
        HookList<UnitTargetHandler> OnUnitTargetSelect;
        #define SpellUnitTargetFn(F, I, N) UnitTargetHandlerFunction(&F, I, N)

        // hooks are executed in following order, at specified event of spell:
        // 1. OnUnitTargetSelect - executed just before adding selected targets to final target list
        // 2. BeforeHit - executed just before spell hits a target
        // 3. OnEffect - executed just before specified effect handler call
        // 4. OnHit - executed just before spell deals damage and procs auras
        // 5. AfterHit - executed just after spell finishes all it's jobs for target

        //
        // methods allowing interaction with Spell object
        //
        // methods useable during all spell handling phases
        Unit * GetCaster();
        Unit * GetOriginalCaster();
        SpellEntry const * GetSpellInfo();

        // methods useable after spell targets are set
        // accessors to the "focus" targets of the spell
        // note: do not confuse these with spell hit targets
        // returns: WorldLocation which was selected as a spell destination or NULL
        WorldLocation * GetTargetDest();

        // returns: Unit which was selected as a spell target or NULL
        Unit * GetTargetUnit();

        // returns: GameObject which was selected as a spell target or NULL
        GameObject * GetTargetGObj();

        // returns: Item which was selected as a spell target or NULL
        Item * GetTargetItem();

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

        // finishes spellcast prematurely with selected error message
        void FinishCast(SpellCastResult result);
};

// AuraScript interface - enum used for runtime checks of script function calls
enum AuraScriptHookType
{
    AURA_SCRIPT_HOOK_EFFECT_APPLY = SPELL_SCRIPT_STATE_END,
    AURA_SCRIPT_HOOK_EFFECT_REMOVE,
    AURA_SCRIPT_HOOK_EFFECT_PERIODIC,
    AURA_SCRIPT_HOOK_EFFECT_UPDATE_PERIODIC,
    AURA_SCRIPT_HOOK_EFFECT_CALC_AMOUNT,
    AURA_SCRIPT_HOOK_EFFECT_CALC_PERIODIC,
    AURA_SCRIPT_HOOK_EFFECT_CALC_SPELLMOD,
    AURA_SCRIPT_HOOK_EFFECT_ABSORB,
    AURA_SCRIPT_HOOK_EFFECT_AFTER_ABSORB,
    AURA_SCRIPT_HOOK_EFFECT_MANASHIELD,
    AURA_SCRIPT_HOOK_EFFECT_AFTER_MANASHIELD,
    /*AURA_SCRIPT_HOOK_APPLY,
    AURA_SCRIPT_HOOK_REMOVE,*/
};
#define HOOK_AURA_EFFECT_START HOOK_AURA_EFFECT_APPLY
#define HOOK_AURA_EFFECT_END HOOK_AURA_EFFECT_CALC_SPELLMOD + 1
#define HOOK_AURA_EFFECT_COUNT HOOK_AURA_EFFECT_END - HOOK_AURA_EFFECT_START

class AuraScript : public _SpellScript
{
    // internal use classes & functions
    // DO NOT OVERRIDE THESE IN SCRIPTS
    public:

    #define AURASCRIPT_FUNCTION_TYPE_DEFINES(CLASSNAME) \
        typedef void(CLASSNAME::*AuraEffectApplicationModeFnType)(AuraEffect const *, AuraEffectHandleModes); \
        typedef void(CLASSNAME::*AuraEffectPeriodicFnType)(AuraEffect const *); \
        typedef void(CLASSNAME::*AuraEffectUpdatePeriodicFnType)(AuraEffect *); \
        typedef void(CLASSNAME::*AuraEffectCalcAmountFnType)(AuraEffect const *, int32 &, bool &); \
        typedef void(CLASSNAME::*AuraEffectCalcPeriodicFnType)(AuraEffect const *, bool &, int32 &); \
        typedef void(CLASSNAME::*AuraEffectCalcSpellModFnType)(AuraEffect const *, SpellModifier *&); \
        typedef void(CLASSNAME::*AuraEffectAbsorbFnType)(AuraEffect *, DamageInfo &, uint32 &); \

        AURASCRIPT_FUNCTION_TYPE_DEFINES(AuraScript)

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
                void Call(AuraScript * auraScript, AuraEffect const * _aurEff);
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
                void Call(AuraScript * auraScript, AuraEffect const * _aurEff, AuraEffectHandleModes _mode);
            private:
                AuraEffectApplicationModeFnType pEffectHandlerScript;
                AuraEffectHandleModes mode;
        };
        class EffectAbsorbHandler : public EffectBase
        {
            public:
                EffectAbsorbHandler(AuraEffectAbsorbFnType _pEffectHandlerScript, uint8 _effIndex);
                void Call(AuraScript * auraScript, AuraEffect * aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount);
            private:
                AuraEffectAbsorbFnType pEffectHandlerScript;
        };
        class EffectManaShieldHandler : public EffectBase
        {
            public:
                EffectManaShieldHandler(AuraEffectAbsorbFnType _pEffectHandlerScript, uint8 _effIndex);
                void Call(AuraScript * auraScript, AuraEffect * aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount);
            private:
                AuraEffectAbsorbFnType pEffectHandlerScript;
        };

        #define AURASCRIPT_FUNCTION_CAST_DEFINES(CLASSNAME) \
        class EffectPeriodicHandlerFunction : public AuraScript::EffectPeriodicHandler { public: EffectPeriodicHandlerFunction(AuraEffectPeriodicFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName) : AuraScript::EffectPeriodicHandler((AuraScript::AuraEffectPeriodicFnType)_pEffectHandlerScript, _effIndex, _effName) {} }; \
        class EffectUpdatePeriodicHandlerFunction : public AuraScript::EffectUpdatePeriodicHandler { public: EffectUpdatePeriodicHandlerFunction(AuraEffectUpdatePeriodicFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName) : AuraScript::EffectUpdatePeriodicHandler((AuraScript::AuraEffectUpdatePeriodicFnType)_pEffectHandlerScript, _effIndex, _effName) {} }; \
        class EffectCalcAmountHandlerFunction : public AuraScript::EffectCalcAmountHandler { public: EffectCalcAmountHandlerFunction(AuraEffectCalcAmountFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName) : AuraScript::EffectCalcAmountHandler((AuraScript::AuraEffectCalcAmountFnType)_pEffectHandlerScript, _effIndex, _effName) {} }; \
        class EffectCalcPeriodicHandlerFunction : public AuraScript::EffectCalcPeriodicHandler { public: EffectCalcPeriodicHandlerFunction(AuraEffectCalcPeriodicFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName) : AuraScript::EffectCalcPeriodicHandler((AuraScript::AuraEffectCalcPeriodicFnType)_pEffectHandlerScript, _effIndex, _effName) {} }; \
        class EffectCalcSpellModHandlerFunction : public AuraScript::EffectCalcSpellModHandler { public: EffectCalcSpellModHandlerFunction(AuraEffectCalcSpellModFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName) : AuraScript::EffectCalcSpellModHandler((AuraScript::AuraEffectCalcSpellModFnType)_pEffectHandlerScript, _effIndex, _effName) {} }; \
        class EffectApplyHandlerFunction : public AuraScript::EffectApplyHandler { public: EffectApplyHandlerFunction(AuraEffectApplicationModeFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName, AuraEffectHandleModes _mode) : AuraScript::EffectApplyHandler((AuraScript::AuraEffectApplicationModeFnType)_pEffectHandlerScript, _effIndex, _effName, _mode) {} }; \
        class EffectAbsorbFunction : public AuraScript::EffectAbsorbHandler { public: EffectAbsorbFunction(AuraEffectAbsorbFnType _pEffectHandlerScript,uint8 _effIndex) : AuraScript::EffectAbsorbHandler((AuraScript::AuraEffectAbsorbFnType)_pEffectHandlerScript, _effIndex) {} }; \
        class EffectManaShieldFunction : public AuraScript::EffectManaShieldHandler { public: EffectManaShieldFunction(AuraEffectAbsorbFnType _pEffectHandlerScript,uint8 _effIndex) : AuraScript::EffectManaShieldHandler((AuraScript::AuraEffectAbsorbFnType)_pEffectHandlerScript, _effIndex) {} }; \

        #define PrepareAuraScript(CLASSNAME) AURASCRIPT_FUNCTION_TYPE_DEFINES(CLASSNAME) AURASCRIPT_FUNCTION_CAST_DEFINES(CLASSNAME)

    public:
        bool _Validate(SpellEntry const * entry);
        bool _Load(Aura * aura);
        void _PrepareScriptCall(AuraScriptHookType hookType, AuraApplication const * aurApp = NULL);
        void _FinishScriptCall();
        bool _IsDefaultActionPrevented();
    private:
        Aura * m_aura;
        AuraApplication const * m_auraApplication;
        bool m_defaultActionPrevented;
    public:
        //
        // AuraScript interface
        // hooks to which you can attach your functions
        //
        // executed when periodic aura effect is applied with specified mode to target
        // example: OnEffectApply += AuraEffectApplyFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier, AuraEffectHandleModes);
        // where function is: void function (AuraEffect const * aurEff, AuraEffectHandleModes mode);
        HookList<EffectApplyHandler> OnEffectApply;
        #define AuraEffectApplyFn(F, I, N, M) EffectApplyHandlerFunction(&F, I, N, M)

        // executed when periodic aura effect is removed with specified mode from target
        // example: OnEffectRemove += AuraEffectRemoveFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier, AuraEffectHandleModes);
        // where function is: void function (AuraEffect const * aurEff, AuraEffectHandleModes mode);
        HookList<EffectApplyHandler> OnEffectRemove;
        #define AuraEffectRemoveFn(F, I, N, M) EffectApplyHandlerFunction(&F, I, N, M)

        // executed when periodic aura effect ticks on target
        // example: OnEffectPeriodic += AuraEffectPeriodicFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
        // where function is: void function (AuraEffect const * aurEff);
        HookList<EffectPeriodicHandler> OnEffectPeriodic;
        #define AuraEffectPeriodicFn(F, I, N) EffectPeriodicHandlerFunction(&F, I, N)

        // executed when periodic aura effect is updated
        // example: OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
        // where function is: void function (AuraEffect const * aurEff);
        HookList<EffectUpdatePeriodicHandler> OnEffectUpdatePeriodic;
        #define AuraEffectUpdatePeriodicFn(F, I, N) EffectUpdatePeriodicHandlerFunction(&F, I, N)

        // executed when aura effect calculates amount
        // example: DoEffectCalcAmount += AuraEffectCalcAmounFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
        // where function is: void function (AuraEffect * aurEff, int32 & amount, bool & canBeRecalculated);
        HookList<EffectCalcAmountHandler> DoEffectCalcAmount;
        #define AuraEffectCalcAmountFn(F, I, N) EffectCalcAmountHandlerFunction(&F, I, N)

        // executed when aura effect calculates periodic data
        // example: DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
        // where function is: void function (AuraEffect const * aurEff, bool & isPeriodic, int32 & amplitude);
        HookList<EffectCalcPeriodicHandler> DoEffectCalcPeriodic;
        #define AuraEffectCalcPeriodicFn(F, I, N) EffectCalcPeriodicHandlerFunction(&F, I, N)

        // executed when aura effect calculates spellmod
        // example: DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
        // where function is: void function (AuraEffect const * aurEff, SpellModifier *& spellMod);
        HookList<EffectCalcSpellModHandler> DoEffectCalcSpellMod;
        #define AuraEffectCalcSpellModFn(F, I, N) EffectCalcSpellModHandlerFunction(&F, I, N)

        // executed when absorb aura effect is going to reduce damage
        // example: OnEffectAbsorb += AuraEffectAbsorbFn(class::function, EffectIndexSpecifier);
        // where function is: void function (AuraEffect * aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount);
        HookList<EffectAbsorbHandler> OnEffectAbsorb;
        #define AuraEffectAbsorbFn(F, I) EffectAbsorbFunction(&F, I)

        // executed after absorb aura effect reduced damage to target - absorbAmount is real amount absorbed by aura
        // example: AfterEffectAbsorb += AuraEffectAbsorbFn(class::function, EffectIndexSpecifier);
        // where function is: void function (AuraEffect * aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount);
        HookList<EffectAbsorbHandler> AfterEffectAbsorb;

        // executed when mana shield aura effect is going to reduce damage
        // example: OnEffectManaShield += AuraEffectAbsorbFn(class::function, EffectIndexSpecifier);
        // where function is: void function (AuraEffect * aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount);
        HookList<EffectManaShieldHandler> OnEffectManaShield;
        #define AuraEffectManaShieldFn(F, I) EffectManaShieldFunction(&F, I)

        // executed after mana shield aura effect reduced damage to target - absorbAmount is real amount absorbed by aura
        // example: AfterEffectManaShield += AuraEffectAbsorbFn(class::function, EffectIndexSpecifier);
        // where function is: void function (AuraEffect * aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount);
        HookList<EffectManaShieldHandler> AfterEffectManaShield;

        // AuraScript interface - hook/effect execution manipulators

        // prevents default action of a hook from being executed (works only while called in a hook which default action can be prevented)
        void PreventDefaultAction();

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
        // returns owner if it's unit or unit derived object, NULL otherwise (only for persistent area auras NULL is returned)
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

        // AuraScript interface - functions which are redirecting to AuraApplication class
        // Do not call these in hooks in which AuraApplication is not avalible, otherwise result will differ from expected (the functions will return NULL)

        // returns currently processed target of an aura
        Unit * GetTarget() const;
        // returns AuraApplication object of currently processed target
        AuraApplication const * GetTargetApplication() const;
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
