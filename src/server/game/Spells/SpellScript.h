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

#ifndef TRINITY_SPELL_SCRIPT_H
#define TRINITY_SPELL_SCRIPT_H

#include "ObjectGuid.h"
#include "SharedDefines.h"
#include "SpellAuraDefines.h"
#include "Util.h"
#include <stack>

#ifdef TRINITY_API_USE_DYNAMIC_LINKING
#include <memory>
#endif

class Aura;
class AuraApplication;
class AuraEffect;
class Creature;
class Corpse;
class DamageInfo;
class DispelInfo;
class DynamicObject;
class GameObject;
class HealInfo;
class Item;
class ModuleReference;
class Player;
class ProcEventInfo;
class Spell;
class SpellEffectInfo;
class SpellInfo;
class SpellScript;
class Unit;
class WorldLocation;
class WorldObject;
struct SpellDestination;
struct SpellModifier;
struct SpellValue;
enum Difficulty : uint8;
enum class ItemContext : uint8;

#define SPELL_EFFECT_ANY ((uint16)-1)
#define SPELL_AURA_ANY ((uint16)-1)

enum SpellScriptState
{
    SPELL_SCRIPT_STATE_NONE = 0,
    SPELL_SCRIPT_STATE_REGISTRATION,
    SPELL_SCRIPT_STATE_LOADING,
    SPELL_SCRIPT_STATE_UNLOADING
};
#define SPELL_SCRIPT_STATE_END (SPELL_SCRIPT_STATE_UNLOADING + 1)

// helper class from which SpellScript and AuraScript derive, use these classes instead
class TC_GAME_API SpellScriptBase
{
// internal use classes & functions
// DO NOT OVERRIDE THESE IN SCRIPTS
public:
    SpellScriptBase();
    virtual ~SpellScriptBase();

    SpellScriptBase(SpellScriptBase const& right) = delete;
    SpellScriptBase(SpellScriptBase&& right) = delete;
    SpellScriptBase& operator=(SpellScriptBase const& right) = delete;
    SpellScriptBase& operator=(SpellScriptBase&& right) = delete;

    void _Register();
    void _Unload();
    void _Init(std::string const& scriptname, uint32 spellId);
    std::string_view GetScriptName() const;

protected:
    virtual bool _Validate(SpellInfo const* entry);

    class TC_GAME_API EffectHook
    {
    public:
        explicit EffectHook(uint8 effIndex);
        EffectHook(EffectHook const& right) = delete;
        EffectHook(EffectHook&& right) noexcept;
        EffectHook& operator=(EffectHook const& right) = delete;
        EffectHook& operator=(EffectHook&& right) noexcept;
        virtual ~EffectHook();

        uint32 GetAffectedEffectsMask(SpellInfo const* spellInfo) const;
        bool IsEffectAffected(SpellInfo const* spellInfo, uint8 effIndex) const;
        virtual bool CheckEffect(SpellInfo const* spellInfo, uint8 effIndex) const = 0;
        std::string EffIndexToString() const;

    protected:
        uint8 _effIndex;
    };

    template<typename>
    struct GetScriptClass
    {
        using type = void;
    };

    template<typename Return, typename Class, typename... Args>
    struct GetScriptClass<Return(Class::*)(Args...)>
    {
        using type = Class;
    };

    template<typename Return, typename Class, typename... Args>
    struct GetScriptClass<Return(Class::*)(Args...) const>
    {
        using type = Class;
    };

    template<typename ScriptFunc>
    using GetScriptClass_t = typename GetScriptClass<ScriptFunc>::type;

    uint8 m_currentScriptState;
    std::string_view m_scriptName;
    uint32 m_scriptSpellId;

private:

#ifdef TRINITY_API_USE_DYNAMIC_LINKING

    // Strong reference to keep the binary code loaded
    std::shared_ptr<ModuleReference> m_moduleReference;

#endif // #ifndef TRINITY_API_USE_DYNAMIC_LINKING

public:
    //
    // SpellScript/AuraScript interface base
    // these functions are safe to override, see notes below for usage instructions
    //
    // Function in which handler functions are registered, must be implemented in script
    virtual void Register() = 0;
    // Function called on server startup, if returns false script won't be used in core
    // use for: dbc/template data presence/correctness checks
    virtual bool Validate([[maybe_unused]] SpellInfo const* spellInfo) { return true; }
    // Function called when script is created, if returns false script will be unloaded afterwards
    // use for: initializing local script variables (DO NOT USE CONSTRUCTOR FOR THIS PURPOSE!)
    virtual bool Load() { return true; }
    // Function called when script is destroyed
    // use for: deallocating memory allocated by script
    virtual void Unload() { }
    // Helpers
    static bool ValidateSpellInfo(std::initializer_list<uint32> spellIds)
    {
        return ValidateSpellInfoImpl(spellIds.begin(), spellIds.end());
    }

    template <class T>
    static bool ValidateSpellInfo(T const& spellIds)
    {
        return ValidateSpellInfoImpl(std::cbegin(spellIds), std::cend(spellIds));
    }

    static bool ValidateSpellEffect(std::initializer_list<std::pair<uint32, SpellEffIndex>> effects)
    {
        return ValidateSpellEffectsImpl(effects.begin(), effects.end());
    }

    template <class T>
    static bool ValidateSpellEffect(T const& spellEffects)
    {
        return ValidateSpellEffectsImpl(std::cbegin(spellEffects), std::cend(spellEffects));
    }

private:
    template<typename Iterator>
    static bool ValidateSpellInfoImpl(Iterator begin, Iterator end)
    {
        bool allValid = true;
        while (begin != end)
        {
            if (!ValidateSpellInfoImpl(*begin))
                allValid = false;

            ++begin;
        }
        return allValid;
    }

    template<typename Iterator>
    static bool ValidateSpellEffectsImpl(Iterator begin, Iterator end)
    {
        bool allValid = true;
        while (begin != end)
        {
            if (!ValidateSpellEffectImpl(begin->first, begin->second))
                allValid = false;

            ++begin;
        }
        return allValid;
    }

    static bool ValidateSpellInfoImpl(uint32 spellId);
    static bool ValidateSpellEffectImpl(uint32 spellId, SpellEffIndex effectIndex);
};

// SpellScript interface - enum used for runtime checks of script function calls
enum SpellScriptHookType
{
    SPELL_SCRIPT_HOOK_EFFECT_LAUNCH = SPELL_SCRIPT_STATE_END,
    SPELL_SCRIPT_HOOK_EFFECT_LAUNCH_TARGET,
    SPELL_SCRIPT_HOOK_EFFECT_HIT,
    SPELL_SCRIPT_HOOK_EFFECT_HIT_TARGET,
    SPELL_SCRIPT_HOOK_EFFECT_SUCCESSFUL_DISPEL,
    SPELL_SCRIPT_HOOK_BEFORE_HIT,
    SPELL_SCRIPT_HOOK_HIT,
    SPELL_SCRIPT_HOOK_AFTER_HIT,
    SPELL_SCRIPT_HOOK_OBJECT_AREA_TARGET_SELECT,
    SPELL_SCRIPT_HOOK_OBJECT_TARGET_SELECT,
    SPELL_SCRIPT_HOOK_DESTINATION_TARGET_SELECT,
    SPELL_SCRIPT_HOOK_CHECK_CAST,
    SPELL_SCRIPT_HOOK_BEFORE_CAST,
    SPELL_SCRIPT_HOOK_ON_CAST,
    SPELL_SCRIPT_HOOK_ON_RESIST_ABSORB_CALCULATION,
    SPELL_SCRIPT_HOOK_AFTER_CAST,
    SPELL_SCRIPT_HOOK_CALC_CRIT_CHANCE,
    SPELL_SCRIPT_HOOK_ON_PRECAST,
    SPELL_SCRIPT_HOOK_CALC_CAST_TIME,
};

#define HOOK_SPELL_HIT_START SPELL_SCRIPT_HOOK_EFFECT_HIT
#define HOOK_SPELL_HIT_END SPELL_SCRIPT_HOOK_AFTER_HIT + 1

class TC_GAME_API SpellScript : public SpellScriptBase
{
    // internal use classes & functions
    // DO NOT OVERRIDE THESE IN SCRIPTS
public:
    class TC_GAME_API CastHandler
    {
    public:
        using SpellCastFnType = void(SpellScript::*)();

        template<typename ScriptFunc>
        static CastHandler Create(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(SpellCastFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(SpellCastFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass>, void>,
                "CastHandler signature must be \"void HandleCast()\"");

            return { reinterpret_cast<SpellCastFnType>(handler) };
        }

        CastHandler(SpellCastFnType callImpl);
        CastHandler(CastHandler const& right) = delete;
        CastHandler(CastHandler&& right) noexcept;
        CastHandler& operator=(CastHandler const& right) = delete;
        CastHandler& operator=(CastHandler&& right) noexcept;
        ~CastHandler();
        void Call(SpellScript* spellScript) const;
    private:
        SpellCastFnType _callImpl;
    };

    class TC_GAME_API CheckCastHandler
    {
    public:
        using SpellCheckCastFnType = SpellCastResult(SpellScript::*)();

        template<typename ScriptFunc>
        static CheckCastHandler Create(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(SpellCheckCastFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(SpellCheckCastFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass>, SpellCastResult>,
                "CheckCastHandler signature must be \"SpellCastResult CheckCast()\"");

            return { reinterpret_cast<SpellCheckCastFnType>(handler) };
        }

        CheckCastHandler(SpellCheckCastFnType callImpl);
        CheckCastHandler(CheckCastHandler const& right) = delete;
        CheckCastHandler(CheckCastHandler&& right) noexcept;
        CheckCastHandler& operator=(CheckCastHandler const& right) = delete;
        CheckCastHandler& operator=(CheckCastHandler&& right) noexcept;
        ~CheckCastHandler();
        SpellCastResult Call(SpellScript* spellScript) const;
    private:
        SpellCheckCastFnType _callImpl;
    };

    class TC_GAME_API EffectHandler : public EffectHook
    {
    public:
        using SpellEffectFnType = void(SpellScript::*)(SpellEffIndex);

        template<typename ScriptFunc>
        static EffectHandler Create(ScriptFunc handler, uint8 effIndex, uint16 effName)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(SpellEffectFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(SpellEffectFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, SpellEffIndex>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, SpellEffIndex>, void>,
                "EffectHandler signature must be \"void HandleEffect(SpellEffIndex effIndex)\"");

            return { reinterpret_cast<SpellEffectFnType>(handler), effIndex, effName };
        }

        EffectHandler(SpellEffectFnType callImpl, uint8 effIndex, uint16 effName);
        EffectHandler(EffectHandler const& right) = delete;
        EffectHandler(EffectHandler&& right) noexcept;
        EffectHandler& operator=(EffectHandler const& right) = delete;
        EffectHandler& operator=(EffectHandler&& right) noexcept;
        ~EffectHandler();
        std::string ToString() const;
        bool CheckEffect(SpellInfo const* spellInfo, uint8 effIndex) const override;
        void Call(SpellScript* spellScript, SpellEffIndex effIndex) const;
    private:
        SpellEffectFnType _callImpl;
        uint16 _effName;
    };

    class TC_GAME_API BeforeHitHandler
    {
    public:
        using SpellBeforeHitFnType = void(SpellScript::*)(SpellMissInfo missInfo);

        template<typename ScriptFunc>
        static BeforeHitHandler Create(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(SpellBeforeHitFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(SpellBeforeHitFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, SpellMissInfo>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, SpellMissInfo>, void>,
                "BeforeHitHandler signature must be \"void HandleBeforeHit(SpellMissInfo missInfo)\"");

            return { reinterpret_cast<SpellBeforeHitFnType>(handler) };
        }

        BeforeHitHandler(SpellBeforeHitFnType callImpl);
        BeforeHitHandler(BeforeHitHandler const& right) = delete;
        BeforeHitHandler(BeforeHitHandler&& right) noexcept;
        BeforeHitHandler& operator=(BeforeHitHandler const& right) = delete;
        BeforeHitHandler& operator=(BeforeHitHandler&& right) noexcept;
        ~BeforeHitHandler();
        void Call(SpellScript* spellScript, SpellMissInfo missInfo) const;
    private:
        SpellBeforeHitFnType _callImpl;
    };

    class TC_GAME_API HitHandler
    {
    public:
        using SpellHitFnType = void(SpellScript::*)();

        template<typename ScriptFunc>
        static HitHandler Create(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(SpellHitFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(SpellHitFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass>, void>,
                "HitHandler signature must be \"void HandleHit()\"");

            return { reinterpret_cast<SpellHitFnType>(handler) };
        }

        HitHandler(SpellHitFnType callImpl);
        HitHandler(HitHandler const& right) = delete;
        HitHandler(HitHandler&& right) noexcept;
        HitHandler& operator=(HitHandler const& right) = delete;
        HitHandler& operator=(HitHandler&& right) noexcept;
        virtual ~HitHandler();
        void Call(SpellScript* spellScript) const;
    private:
        SpellHitFnType _callImpl;
    };

    class TC_GAME_API OnCalcCritChanceHandler
    {
    public:
        using SpellOnCalcCritChanceFnType = void(SpellScript::*)(Unit const* victim, float& chance);

        template<typename ScriptFunc>
        static OnCalcCritChanceHandler Create(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(SpellOnCalcCritChanceFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(SpellOnCalcCritChanceFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, Unit const*, float&>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, Unit const*, float&>, void>,
                "OnCalcCritChanceHandler signature must be \"void CalcCritChance(Unit const* victim, float& critChance)\"");

            return { reinterpret_cast<SpellOnCalcCritChanceFnType>(handler) };
        }

        OnCalcCritChanceHandler(SpellOnCalcCritChanceFnType callImpl);
        OnCalcCritChanceHandler(OnCalcCritChanceHandler const& right) = delete;
        OnCalcCritChanceHandler(OnCalcCritChanceHandler&& right) noexcept;
        OnCalcCritChanceHandler& operator=(OnCalcCritChanceHandler const& right) = delete;
        OnCalcCritChanceHandler& operator=(OnCalcCritChanceHandler&& right) noexcept;
        virtual ~OnCalcCritChanceHandler();
        void Call(SpellScript* spellScript, Unit const* victim, float& critChance) const;
    private:
        SpellOnCalcCritChanceFnType _callImpl;
    };

    class TC_GAME_API TargetHook : public EffectHook
    {
    public:
        TargetHook(uint8 effectIndex, uint16 targetType, bool area, bool dest);
        TargetHook(TargetHook const& right) = delete;
        TargetHook(TargetHook&& right) noexcept;
        TargetHook& operator=(TargetHook const& right) = delete;
        TargetHook& operator=(TargetHook&& right) noexcept;
        virtual ~TargetHook();
        bool CheckEffect(SpellInfo const* spellInfo, uint8 effIndex) const override;
        std::string ToString() const;
        uint16 GetTarget() const { return _targetType; }
    protected:
        uint16 _targetType;
        bool _area;
        bool _dest;
    };

    class TC_GAME_API ObjectAreaTargetSelectHandler : public TargetHook
    {
    public:
        using SpellObjectAreaTargetSelectFnType = void(SpellScript::*)(std::list<WorldObject*>&);

        template<typename ScriptFunc>
        static ObjectAreaTargetSelectHandler Create(ScriptFunc handler, uint8 effIndex, uint16 targetType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(SpellObjectAreaTargetSelectFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(SpellObjectAreaTargetSelectFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, std::list<WorldObject*>&>
               && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, std::list<WorldObject*>&>, void>,
               "ObjectAreaTargetSelectHandler signature must be \"void SetTargets(std::list<WorldObject*>& targets)\"");

            return { reinterpret_cast<SpellObjectAreaTargetSelectFnType>(handler), effIndex, targetType };
        }

        ObjectAreaTargetSelectHandler(SpellObjectAreaTargetSelectFnType callImpl, uint8 effIndex, uint16 targetType);
        ObjectAreaTargetSelectHandler(ObjectAreaTargetSelectHandler const& right) = delete;
        ObjectAreaTargetSelectHandler(ObjectAreaTargetSelectHandler&& right) noexcept;
        ObjectAreaTargetSelectHandler& operator=(ObjectAreaTargetSelectHandler const& right) = delete;
        ObjectAreaTargetSelectHandler& operator=(ObjectAreaTargetSelectHandler&& right) noexcept;
        ~ObjectAreaTargetSelectHandler();
        void Call(SpellScript* spellScript, std::list<WorldObject*>& targets) const;
    private:
        SpellObjectAreaTargetSelectFnType _callImpl;
    };

    class TC_GAME_API ObjectTargetSelectHandler : public TargetHook
    {
    public:
        using SpellObjectTargetSelectFnType = void(SpellScript::*)(WorldObject*&);

        template<typename ScriptFunc>
        static ObjectTargetSelectHandler Create(ScriptFunc handler, uint8 effIndex, uint16 targetType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(SpellObjectTargetSelectFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(SpellObjectTargetSelectFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, WorldObject*&>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, WorldObject*&>, void>,
                "ObjectTargetSelectHandler signature must be \"void SetTarget(WorldObject*& target)\"");

            return { reinterpret_cast<SpellObjectTargetSelectFnType>(handler), effIndex, targetType };
        }

        ObjectTargetSelectHandler(SpellObjectTargetSelectFnType callImpl, uint8 effIndex, uint16 targetType);
        ObjectTargetSelectHandler(ObjectTargetSelectHandler const& right) = delete;
        ObjectTargetSelectHandler(ObjectTargetSelectHandler&& right) noexcept;
        ObjectTargetSelectHandler& operator=(ObjectTargetSelectHandler const& right) = delete;
        ObjectTargetSelectHandler& operator=(ObjectTargetSelectHandler&& right) noexcept;
        ~ObjectTargetSelectHandler();
        void Call(SpellScript* spellScript, WorldObject*& target) const;
    private:
        SpellObjectTargetSelectFnType _callImpl;
    };

    class TC_GAME_API DestinationTargetSelectHandler : public TargetHook
    {
    public:
        using SpellDestinationTargetSelectFnType = void(SpellScript::*)(SpellDestination&);

        template<typename ScriptFunc>
        static DestinationTargetSelectHandler Create(ScriptFunc handler, uint8 effIndex, uint16 targetType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(SpellDestinationTargetSelectFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(SpellDestinationTargetSelectFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, SpellDestination&>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, SpellDestination&>, void>,
                "DestinationTargetSelectHandler signature must be \"void SetTarget(SpellDestination& target)\"");

            return { reinterpret_cast<SpellDestinationTargetSelectFnType>(handler), effIndex, targetType };
        }

        DestinationTargetSelectHandler(SpellDestinationTargetSelectFnType callImpl, uint8 effIndex, uint16 targetType);
        DestinationTargetSelectHandler(DestinationTargetSelectHandler const& right) = delete;
        DestinationTargetSelectHandler(DestinationTargetSelectHandler&& right) noexcept;
        DestinationTargetSelectHandler& operator=(DestinationTargetSelectHandler const& right) = delete;
        DestinationTargetSelectHandler& operator=(DestinationTargetSelectHandler&& right) noexcept;
        ~DestinationTargetSelectHandler();
        void Call(SpellScript* spellScript, SpellDestination& target) const;
    private:
        SpellDestinationTargetSelectFnType _callImpl;
    };

    class TC_GAME_API OnCalculateResistAbsorbHandler
    {
    public:
        using SpellOnResistAbsorbCalculateFnType = void(SpellScript::*)(DamageInfo const& damageInfo, uint32& resistAmount, int32& absorbAmount);

        template<typename ScriptFunc>
        static OnCalculateResistAbsorbHandler Create(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(SpellOnResistAbsorbCalculateFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(SpellOnResistAbsorbCalculateFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, DamageInfo const&, uint32&, int32&>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, DamageInfo const&, uint32&, int32&>, void>,
                "OnCalculateResistAbsorbHandler signature must be \"void CalcAbsorbResist(DamageInfo const& damageInfo, uint32& resistAmount, int32& absorbAmount)\"");

            return { reinterpret_cast<SpellOnResistAbsorbCalculateFnType>(handler) };
        }

        OnCalculateResistAbsorbHandler(SpellOnResistAbsorbCalculateFnType callImpl);
        OnCalculateResistAbsorbHandler(OnCalculateResistAbsorbHandler const& right) = delete;
        OnCalculateResistAbsorbHandler(OnCalculateResistAbsorbHandler&& right) noexcept;
        OnCalculateResistAbsorbHandler& operator=(OnCalculateResistAbsorbHandler const& right) = delete;
        OnCalculateResistAbsorbHandler& operator=(OnCalculateResistAbsorbHandler&& right) noexcept;
        ~OnCalculateResistAbsorbHandler();
        void Call(SpellScript* spellScript, DamageInfo const& damageInfo, uint32& resistAmount, int32& absorbAmount) const;
    private:
        SpellOnResistAbsorbCalculateFnType _callImpl;
    };

     // left for custom compatibility only, DO NOT USE
    #define PrepareSpellScript(CLASSNAME) using silence_semicolon_warning = void

    SpellScript();
    ~SpellScript();
    bool _Validate(SpellInfo const* entry) override;
    bool _Load(Spell* spell);
    void _InitHit();
    bool _IsEffectPrevented(SpellEffIndex effIndex) const { return (m_hitPreventEffectMask & (1 << effIndex)) != 0; }
    bool _IsDefaultEffectPrevented(SpellEffIndex effIndex) const { return (m_hitPreventDefaultEffectMask & (1 << effIndex)) != 0; }
    void _PrepareScriptCall(SpellScriptHookType hookType);
    void _FinishScriptCall();
    bool IsInCheckCastHook() const;
    bool IsAfterTargetSelectionPhase() const;
    bool IsInTargetHook() const;
    bool IsInModifiableHook() const;
    bool IsInHitPhase() const;
    bool IsInEffectHook() const;
private:
    Spell* m_spell;
    uint32 m_hitPreventEffectMask;
    uint32 m_hitPreventDefaultEffectMask;
public:
    //
    // SpellScript interface
    //
    // example: void OnPrecast() override { }
    virtual void OnPrecast() { }
    //
    // hooks to which you can attach your functions
    //
    // example: BeforeCast += SpellCastFn(class::function);
    HookList<CastHandler> BeforeCast;
    // example: OnCast += SpellCastFn(class::function);
    HookList<CastHandler> OnCast;
    // example: AfterCast += SpellCastFn(class::function);
    HookList<CastHandler> AfterCast;
    #define SpellCastFn(F) CastHandler::Create(&F)

    // example: OnCheckCast += SpellCheckCastFn();
    // where function is SpellCastResult function()
    HookList<CheckCastHandler> OnCheckCast;
    #define SpellCheckCastFn(F) CheckCastHandler::Create(&F)

    // example: int32 CalcCastTime(int32 castTime) override { return 1500; }
    virtual int32 CalcCastTime(int32 castTime) { return castTime; }

    // example: OnEffect**** += SpellEffectFn(class::function, EffectIndexSpecifier, EffectNameSpecifier);
    // where function is void function(SpellEffIndex effIndex)
    HookList<EffectHandler> OnEffectLaunch;
    HookList<EffectHandler> OnEffectLaunchTarget;
    HookList<EffectHandler> OnEffectHit;
    HookList<EffectHandler> OnEffectHitTarget;
    HookList<EffectHandler> OnEffectSuccessfulDispel;
    #define SpellEffectFn(F, I, N) EffectHandler::Create(&F, I, N)

    // example: BeforeHit += BeforeSpellHitFn(class::function);
    // where function is void function(SpellMissInfo missInfo)
    HookList<BeforeHitHandler> BeforeHit;
    #define BeforeSpellHitFn(F) BeforeHitHandler::Create(&F)

    // example: OnHit += SpellHitFn(class::function);
    HookList<HitHandler> OnHit;
    // example: AfterHit += SpellHitFn(class::function);
    HookList<HitHandler> AfterHit;
    // where function is: void function()
    #define SpellHitFn(F) HitHandler::Create(&F)

    // example: OnCalcCritChance += SpellOnCalcCritChanceFn(class::function);
    // where function is: void function(Unit* victim, float& critChance)
    HookList<OnCalcCritChanceHandler> OnCalcCritChance;
    #define SpellOnCalcCritChanceFn(F) OnCalcCritChanceHandler::Create(&F)

    // example: OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(class::function, EffectIndexSpecifier, TargetsNameSpecifier);
    // where function is void function(std::list<WorldObject*>& targets)
    HookList<ObjectAreaTargetSelectHandler> OnObjectAreaTargetSelect;
    #define SpellObjectAreaTargetSelectFn(F, I, N) ObjectAreaTargetSelectHandler::Create(&F, I, N)

    // example: OnObjectTargetSelect += SpellObjectTargetSelectFn(class::function, EffectIndexSpecifier, TargetsNameSpecifier);
    // where function is void function(WorldObject*& target)
    HookList<ObjectTargetSelectHandler> OnObjectTargetSelect;
    #define SpellObjectTargetSelectFn(F, I, N) ObjectTargetSelectHandler::Create(&F, I, N)

    // example: OnDestinationTargetSelect += SpellDestinationTargetSelectFn(class::function, EffectIndexSpecifier, TargetsNameSpecifier);
    // where function is void function(SpellDestination& target)
    HookList<DestinationTargetSelectHandler> OnDestinationTargetSelect;
    #define SpellDestinationTargetSelectFn(F, I, N) DestinationTargetSelectHandler::Create(&F, I, N)

    // example: OnCalculateResistAbsorb += SpellOnResistAbsorbCalculateFn(class::function);
    // where function is void function(DamageInfo const& damageInfo, uint32& resistAmount, int32& absorbAmount)
    HookList<OnCalculateResistAbsorbHandler> OnCalculateResistAbsorb;
    #define SpellOnResistAbsorbCalculateFn(F) OnCalculateResistAbsorbHandler::Create(&F)

    // hooks are executed in following order, at specified event of spell:
    // 1. OnPrecast - executed during spell preparation (before cast bar starts)
    // 2. BeforeCast - executed when spell preparation is finished (when cast bar becomes full) before cast is handled
    // 3. OnCheckCast - allows to override result of CheckCast function
    // 4a. OnObjectAreaTargetSelect - executed just before adding selected targets to final target list (for area targets)
    // 4b. OnObjectTargetSelect - executed just before adding selected target to final target list (for single unit targets)
    // 4c. OnDestinationTargetSelect - executed just before adding selected target to final target list (for destination targets)
    // 5. OnCast - executed just before spell is launched (creates missile) or executed
    // 6. AfterCast - executed after spell missile is launched and immediate spell actions are done
    // 7. OnEffectLaunch - executed just before specified effect handler call - when spell missile is launched
    // 8. OnEffectLaunchTarget - executed just before specified effect handler call - when spell missile is launched - called for each target from spell target map
    // 9. OnCalcCritChance - executed just after specified effect handler call - when spell missile is launched - called for each target from spell target map
    // 10. OnCalculateResistAbsorb - executed when damage resist/absorbs is calculated - before spell hit target
    // 11. OnEffectHit - executed just before specified effect handler call - when spell missile hits dest
    // 12. BeforeHit - executed just before spell hits a target - called for each target from spell target map
    // 13. OnEffectHitTarget - executed just before specified effect handler call - called for each target from spell target map
    // 14. OnHit - executed just before spell deals damage and procs auras - when spell hits target - called for each target from spell target map
    // 15. AfterHit - executed just after spell finishes all it's jobs for target - called for each target from spell target map

    // this hook is only executed after a successful dispel of any aura
    // OnEffectSuccessfulDispel - executed just after effect successfully dispelled aura(s)

    //
    // methods allowing interaction with Spell object
    //
    // methods useable during all spell handling phases
    Unit* GetCaster() const;
    GameObject* GetGObjCaster() const;
    Unit* GetOriginalCaster() const;
    SpellInfo const* GetSpellInfo() const;
    SpellEffectInfo const& GetEffectInfo(SpellEffIndex effIndex) const;
    SpellValue const* GetSpellValue() const;

    // methods useable after spell is prepared
    // accessors to the explicit targets of the spell
    // explicit target - target selected by caster (player, game client, or script - DoCast(explicitTarget, ...), required for spell to be cast
    // examples:
    // -shadowstep - explicit target is the unit you want to go behind of
    // -chain heal - explicit target is the unit to be healed first
    // -holy nova/arcane explosion - explicit target = NULL because target you are selecting doesn't affect how spell targets are selected
    // you can determine if spell requires explicit targets by dbc columns:
    // - Targets - mask of explicit target types
    // - ImplicitTargetXX set to TARGET_XXX_TARGET_YYY, _TARGET_ here means that explicit target is used by the effect, so spell needs one too

    // returns: WorldLocation which was selected as a spell destination or NULL
    WorldLocation const* GetExplTargetDest() const;

    void SetExplTargetDest(WorldLocation& loc);

    // returns: WorldObject which was selected as an explicit spell target or NULL if there's no target
    WorldObject* GetExplTargetWorldObject() const;

    // returns: Unit which was selected as an explicit spell target or NULL if there's no target
    Unit* GetExplTargetUnit() const;

    // returns: GameObject which was selected as an explicit spell target or NULL if there's no target
    GameObject* GetExplTargetGObj() const;

    // returns: Item which was selected as an explicit spell target or NULL if there's no target
    Item* GetExplTargetItem() const;

    // methods usable only after spell targets have been fully selected
    int64 GetUnitTargetCountForEffect(SpellEffIndex effect) const;
    int64 GetGameObjectTargetCountForEffect(SpellEffIndex effect) const;
    int64 GetItemTargetCountForEffect(SpellEffIndex effect) const;
    int64 GetCorpseTargetCountForEffect(SpellEffIndex effect) const;

    // methods useable only during spell hit on target, or during spell launch on target:
    // returns: target of current effect if it was Unit otherwise NULL
    Unit* GetHitUnit() const;
    // returns: target of current effect if it was Creature otherwise NULL
    Creature* GetHitCreature() const;
    // returns: target of current effect if it was Player otherwise NULL
    Player* GetHitPlayer() const;
    // returns: target of current effect if it was Item otherwise NULL
    Item* GetHitItem() const;
    // returns: target of current effect if it was GameObject otherwise NULL
    GameObject* GetHitGObj() const;
    // returns: target of current effect if it was Corpse otherwise nullptr
    Corpse* GetHitCorpse() const;
    // returns: destination of current effect
    WorldLocation* GetHitDest() const;
    // setter/getter for for damage done by spell to target of spell hit
    // returns damage calculated before hit, and real dmg done after hit
    int32 GetHitDamage() const;
    void SetHitDamage(int32 damage);
    void PreventHitDamage() { SetHitDamage(0); }
    // setter/getter for for heal done by spell to target of spell hit
    // returns healing calculated before hit, and real dmg done after hit
    int32 GetHitHeal() const;
    void SetHitHeal(int32 heal);
    void PreventHitHeal() { SetHitHeal(0); }
    // returns: true if spell critically hits current HitUnit
    bool IsHitCrit() const;
    Spell* GetSpell() const { return m_spell; }
    // returns current spell hit target aura
    Aura* GetHitAura(bool dynObjAura = false) const;
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

    // method available only in EffectHandler method
    SpellEffectInfo const& GetEffectInfo() const;
    int32 GetEffectValue() const;
    void SetEffectValue(int32 value);
    float GetEffectVariance() const;
    void SetEffectVariance(float variance);

    // returns: cast item if present.
    Item* GetCastItem() const;

    // Creates item. Calls Spell::DoCreateItem method.
    void CreateItem(uint32 itemId, ItemContext context);

    // Returns SpellInfo from the spell that triggered the current one
    SpellInfo const* GetTriggeringSpell() const;

    // finishes spellcast prematurely with selected error message
    void FinishCast(SpellCastResult result, int32* param1 = nullptr, int32* param2 = nullptr);

    void SetCustomCastResultMessage(SpellCustomErrors result);

    // returns desired cast difficulty for triggered spells
    Difficulty GetCastDifficulty() const;
};

// AuraScript interface - enum used for runtime checks of script function calls
enum AuraScriptHookType
{
    AURA_SCRIPT_HOOK_EFFECT_APPLY = SPELL_SCRIPT_STATE_END,
    AURA_SCRIPT_HOOK_EFFECT_AFTER_APPLY,
    AURA_SCRIPT_HOOK_EFFECT_REMOVE,
    AURA_SCRIPT_HOOK_EFFECT_AFTER_REMOVE,
    AURA_SCRIPT_HOOK_EFFECT_PERIODIC,
    AURA_SCRIPT_HOOK_EFFECT_UPDATE_PERIODIC,
    AURA_SCRIPT_HOOK_EFFECT_CALC_AMOUNT,
    AURA_SCRIPT_HOOK_EFFECT_CALC_PERIODIC,
    AURA_SCRIPT_HOOK_EFFECT_CALC_SPELLMOD,
    AURA_SCRIPT_HOOK_EFFECT_CALC_CRIT_CHANCE,
    AURA_SCRIPT_HOOK_EFFECT_ABSORB,
    AURA_SCRIPT_HOOK_EFFECT_AFTER_ABSORB,
    AURA_SCRIPT_HOOK_EFFECT_MANASHIELD,
    AURA_SCRIPT_HOOK_EFFECT_AFTER_MANASHIELD,
    AURA_SCRIPT_HOOK_EFFECT_SPLIT,
    AURA_SCRIPT_HOOK_CHECK_AREA_TARGET,
    AURA_SCRIPT_HOOK_DISPEL,
    AURA_SCRIPT_HOOK_AFTER_DISPEL,
    AURA_SCRIPT_HOOK_ENTER_LEAVE_COMBAT,
    // Spell Proc Hooks
    AURA_SCRIPT_HOOK_CHECK_PROC,
    AURA_SCRIPT_HOOK_CHECK_EFFECT_PROC,
    AURA_SCRIPT_HOOK_PREPARE_PROC,
    AURA_SCRIPT_HOOK_PROC,
    AURA_SCRIPT_HOOK_EFFECT_PROC,
    AURA_SCRIPT_HOOK_EFFECT_AFTER_PROC,
    AURA_SCRIPT_HOOK_AFTER_PROC,
    /*AURA_SCRIPT_HOOK_APPLY,
    AURA_SCRIPT_HOOK_REMOVE, */
};
/*
#define HOOK_AURA_EFFECT_START HOOK_AURA_EFFECT_APPLY
#define HOOK_AURA_EFFECT_END HOOK_AURA_EFFECT_CALC_SPELLMOD + 1
#define HOOK_AURA_EFFECT_COUNT HOOK_AURA_EFFECT_END - HOOK_AURA_EFFECT_START
*/
class TC_GAME_API AuraScript : public SpellScriptBase
{
    // internal use classes & functions
    // DO NOT OVERRIDE THESE IN SCRIPTS
public:
    class TC_GAME_API CheckAreaTargetHandler
    {
    public:
        using AuraCheckAreaTargetFnType = bool(AuraScript::*)(Unit* target);

        template<typename ScriptFunc>
        static CheckAreaTargetHandler Create(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraCheckAreaTargetFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraCheckAreaTargetFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, Unit*>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, Unit*>, bool>,
                "CheckAreaTargetHandler signature must be \"bool CheckTarget(Unit* target)\"");

            return { reinterpret_cast<AuraCheckAreaTargetFnType>(handler) };
        }

        CheckAreaTargetHandler(AuraCheckAreaTargetFnType callImpl);
        CheckAreaTargetHandler(CheckAreaTargetHandler const& right) = delete;
        CheckAreaTargetHandler(CheckAreaTargetHandler&& right) noexcept;
        CheckAreaTargetHandler& operator=(CheckAreaTargetHandler const& right) = delete;
        CheckAreaTargetHandler& operator=(CheckAreaTargetHandler&& right) noexcept;
        ~CheckAreaTargetHandler();
        bool Call(AuraScript* auraScript, Unit* target) const;
    private:
        AuraCheckAreaTargetFnType _callImpl;
    };

    class TC_GAME_API AuraDispelHandler
    {
    public:
        using AuraDispelFnType = void(AuraScript::*)(DispelInfo* dispelInfo);

        template<typename ScriptFunc>
        static AuraDispelHandler Create(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraDispelFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraDispelFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, DispelInfo*>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, DispelInfo*>, void>,
                "AuraDispelHandler signature must be \"void HandleDispel(DispelInfo* dispelInfo)\"");

            return { reinterpret_cast<AuraDispelFnType>(handler) };
        }

        AuraDispelHandler(AuraDispelFnType callImpl);
        AuraDispelHandler(AuraDispelHandler const& right) = delete;
        AuraDispelHandler(AuraDispelHandler&& right) noexcept;
        AuraDispelHandler& operator=(AuraDispelHandler const& right) = delete;
        AuraDispelHandler& operator=(AuraDispelHandler&& right) noexcept;
        ~AuraDispelHandler();
        void Call(AuraScript* auraScript, DispelInfo* dispelInfo) const;
    private:
        AuraDispelFnType _callImpl;
    };

    class TC_GAME_API EffectBase : public EffectHook
    {
    public:
        EffectBase(uint8 effIndex, uint16 auraType);
        EffectBase(EffectBase const& right) = delete;
        EffectBase(EffectBase&& right) noexcept;
        EffectBase& operator=(EffectBase const& right) = delete;
        EffectBase& operator=(EffectBase&& right) noexcept;
        virtual ~EffectBase();
        std::string ToString() const;
        bool CheckEffect(SpellInfo const* spellInfo, uint8 effIndex) const override;
    private:
        uint16 _auraType;
    };

    class TC_GAME_API EffectPeriodicHandler : public EffectBase
    {
    public:
        using AuraEffectPeriodicFnType = void(AuraScript::*)(AuraEffect const* aurEff);

        template<typename ScriptFunc>
        static EffectPeriodicHandler Create(ScriptFunc handler, uint8 effIndex, uint16 auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraEffectPeriodicFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraEffectPeriodicFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, AuraEffect const*>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, AuraEffect const*>, void>,
                "EffectPeriodicHandler signature must be \"void HandlePeriodic(AuraEffect const* aurEff)\"");

            return { reinterpret_cast<AuraEffectPeriodicFnType>(handler), effIndex, auraType };
        }

        EffectPeriodicHandler(AuraEffectPeriodicFnType callImpl, uint8 effIndex, uint16 auraType);
        EffectPeriodicHandler(EffectPeriodicHandler const& right) = delete;
        EffectPeriodicHandler(EffectPeriodicHandler&& right) noexcept;
        EffectPeriodicHandler& operator=(EffectPeriodicHandler const& right) = delete;
        EffectPeriodicHandler& operator=(EffectPeriodicHandler&& right) noexcept;
        ~EffectPeriodicHandler();
        void Call(AuraScript* auraScript, AuraEffect const* aurEff) const;
    private:
        AuraEffectPeriodicFnType _callImpl;
    };

    class TC_GAME_API EffectUpdatePeriodicHandler : public EffectBase
    {
    public:
        using AuraEffectUpdatePeriodicFnType = void(AuraScript::*)(AuraEffect* aurEff);

        template<typename ScriptFunc>
        static EffectUpdatePeriodicHandler Create(ScriptFunc handler, uint8 effIndex, uint16 auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraEffectUpdatePeriodicFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraEffectUpdatePeriodicFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, AuraEffect*>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, AuraEffect*>, void>,
                "EffectUpdatePeriodicHandler signature must be \"void HandleUpdatePeriodic(AuraEffect* aurEff)\"");

            return { reinterpret_cast<AuraEffectUpdatePeriodicFnType>(handler), effIndex, auraType };
        }

        EffectUpdatePeriodicHandler(AuraEffectUpdatePeriodicFnType callImpl, uint8 effIndex, uint16 auraType);
        EffectUpdatePeriodicHandler(EffectUpdatePeriodicHandler const& right) = delete;
        EffectUpdatePeriodicHandler(EffectUpdatePeriodicHandler&& right) noexcept;
        EffectUpdatePeriodicHandler& operator=(EffectUpdatePeriodicHandler const& right) = delete;
        EffectUpdatePeriodicHandler& operator=(EffectUpdatePeriodicHandler&& right) noexcept;
        ~EffectUpdatePeriodicHandler();
        void Call(AuraScript* auraScript, AuraEffect* aurEff) const;
    private:
        AuraEffectUpdatePeriodicFnType _callImpl;
    };

    class TC_GAME_API EffectCalcAmountHandler : public EffectBase
    {
    public:
        using AuraEffectCalcAmountFnType = void(AuraScript::*)(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated);

        template<typename ScriptFunc>
        static EffectCalcAmountHandler Create(ScriptFunc handler, uint8 effIndex, uint16 auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraEffectCalcAmountFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraEffectCalcAmountFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, AuraEffect const*, int32&, bool&>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, AuraEffect const*, int32&, bool&>, void>,
                "EffectCalcAmountHandler signature must be \"void CalcAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)\"");

            return { reinterpret_cast<AuraEffectCalcAmountFnType>(handler), effIndex, auraType };
        }

        EffectCalcAmountHandler(AuraEffectCalcAmountFnType callImpl, uint8 effIndex, uint16 auraType);
        EffectCalcAmountHandler(EffectCalcAmountHandler const& right) = delete;
        EffectCalcAmountHandler(EffectCalcAmountHandler&& right) noexcept;
        EffectCalcAmountHandler& operator=(EffectCalcAmountHandler const& right) = delete;
        EffectCalcAmountHandler& operator=(EffectCalcAmountHandler&& right) noexcept;
        ~EffectCalcAmountHandler();
        void Call(AuraScript* auraScript, AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated) const;
    private:
        AuraEffectCalcAmountFnType _callImpl;
    };

    class TC_GAME_API EffectCalcPeriodicHandler : public EffectBase
    {
    public:
        using AuraEffectCalcPeriodicFnType = void(AuraScript::*)(AuraEffect const* aurEff, bool& isPeriodic, int32& periodicTimer);

        template<typename ScriptFunc>
        static EffectCalcPeriodicHandler Create(ScriptFunc handler, uint8 effIndex, uint16 auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraEffectCalcPeriodicFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraEffectCalcPeriodicFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, AuraEffect const*, bool&, int32&>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, AuraEffect const*, bool&, int32&>, void>,
                "EffectCalcPeriodicHandler signature must be \"void CalcPeriodic(AuraEffect const* aurEff, bool& isPeriodic, int32& periodicTimer)\"");

            return { reinterpret_cast<AuraEffectCalcPeriodicFnType>(handler), effIndex, auraType };
        }

        EffectCalcPeriodicHandler(AuraEffectCalcPeriodicFnType callImpl, uint8 effIndex, uint16 auraType);
        EffectCalcPeriodicHandler(EffectCalcPeriodicHandler const& right) = delete;
        EffectCalcPeriodicHandler(EffectCalcPeriodicHandler&& right) noexcept;
        EffectCalcPeriodicHandler& operator=(EffectCalcPeriodicHandler const& right) = delete;
        EffectCalcPeriodicHandler& operator=(EffectCalcPeriodicHandler&& right) noexcept;
        ~EffectCalcPeriodicHandler();
        void Call(AuraScript* auraScript, AuraEffect const* aurEff, bool& isPeriodic, int32& periodicTimer) const;
    private:
        AuraEffectCalcPeriodicFnType _callImpl;
    };

    class TC_GAME_API EffectCalcSpellModHandler : public EffectBase
    {
    public:
        using AuraEffectCalcSpellModFnType = void(AuraScript::*)(AuraEffect const* aurEff, SpellModifier*& spellMod);

        template<typename ScriptFunc>
        static EffectCalcSpellModHandler Create(ScriptFunc handler, uint8 effIndex, uint16 auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraEffectCalcSpellModFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraEffectCalcSpellModFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, AuraEffect const*, SpellModifier*&>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, AuraEffect const*, SpellModifier*&>, void>,
                "EffectCalcSpellModHandler signature must be \"void CalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)\"");

            return { reinterpret_cast<AuraEffectCalcSpellModFnType>(handler), effIndex, auraType };
        }

        EffectCalcSpellModHandler(AuraEffectCalcSpellModFnType callImpl, uint8 effIndex, uint16 auraType);
        EffectCalcSpellModHandler(EffectCalcSpellModHandler const& right) = delete;
        EffectCalcSpellModHandler(EffectCalcSpellModHandler&& right) noexcept;
        EffectCalcSpellModHandler& operator=(EffectCalcSpellModHandler const& right) = delete;
        EffectCalcSpellModHandler& operator=(EffectCalcSpellModHandler&& right) noexcept;
        ~EffectCalcSpellModHandler();
        void Call(AuraScript* auraScript, AuraEffect const* aurEff, SpellModifier*& spellMod) const;
    private:
        AuraEffectCalcSpellModFnType _callImpl;
    };

    class TC_GAME_API EffectCalcCritChanceHandler : public EffectBase
    {
    public:
        using AuraEffectCalcCritChanceFnType = void(AuraScript::*)(AuraEffect const* aurEff, Unit const* victim, float& critChance);

        template<typename ScriptFunc>
        static EffectCalcCritChanceHandler Create(ScriptFunc handler, uint8 effIndex, uint16 auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraEffectCalcCritChanceFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraEffectCalcCritChanceFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, AuraEffect const*, Unit const*, float&>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, AuraEffect const*, Unit const*, float&>, void>,
                "EffectCalcSpellModHandler signature must be \"void CalcCritChance(AuraEffect const* aurEff, Unit const* victim, float& critChance)\"");

            return { reinterpret_cast<AuraEffectCalcCritChanceFnType>(handler), effIndex, auraType };
        }

        EffectCalcCritChanceHandler(AuraEffectCalcCritChanceFnType callImpl, uint8 effIndex, uint16 auraType);
        EffectCalcCritChanceHandler(EffectCalcCritChanceHandler const& right) = delete;
        EffectCalcCritChanceHandler(EffectCalcCritChanceHandler&& right) noexcept;
        EffectCalcCritChanceHandler& operator=(EffectCalcCritChanceHandler const& right) = delete;
        EffectCalcCritChanceHandler& operator=(EffectCalcCritChanceHandler&& right) noexcept;
        ~EffectCalcCritChanceHandler();
        void Call(AuraScript* auraScript, AuraEffect const* aurEff, Unit const* victim, float& critChance) const;
    private:
        AuraEffectCalcCritChanceFnType _callImpl;
    };

    class TC_GAME_API EffectApplyHandler : public EffectBase
    {
    public:
        using AuraEffectApplicationModeFnType = void(AuraScript::*)(AuraEffect const* aurEff, AuraEffectHandleModes mode);

        template<typename ScriptFunc>
        static EffectApplyHandler Create(ScriptFunc handler, uint8 effIndex, uint16 auraType, AuraEffectHandleModes mode)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraEffectApplicationModeFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraEffectApplicationModeFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, AuraEffect const*, AuraEffectHandleModes>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, AuraEffect const*, AuraEffectHandleModes>, void>,
                "EffectApplyHandler signature must be \"void HandleApplyOrRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)\"");

            return { reinterpret_cast<AuraEffectApplicationModeFnType>(handler), effIndex, auraType, mode };
        }

        EffectApplyHandler(AuraEffectApplicationModeFnType callImpl, uint8 effIndex, uint16 auraType, AuraEffectHandleModes mode);
        EffectApplyHandler(EffectApplyHandler const& right) = delete;
        EffectApplyHandler(EffectApplyHandler&& right) noexcept;
        EffectApplyHandler& operator=(EffectApplyHandler const& right) = delete;
        EffectApplyHandler& operator=(EffectApplyHandler&& right) noexcept;
        ~EffectApplyHandler();
        AuraEffectHandleModes GetMode() const { return _mode; }
        void Call(AuraScript* auraScript, AuraEffect const* aurEff, AuraEffectHandleModes mode) const;
    private:
        AuraEffectApplicationModeFnType _callImpl;
        AuraEffectHandleModes _mode;
    };

    class TC_GAME_API EffectAbsorbHandler : public EffectBase
    {
    public:
        using AuraEffectAbsorbFnType = void(AuraScript::*)(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount);

        template<typename ScriptFunc>
        static EffectAbsorbHandler Create(ScriptFunc handler, uint8 effIndex, uint16 auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraEffectAbsorbFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraEffectAbsorbFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, AuraEffect*, DamageInfo&, uint32&>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, AuraEffect*, DamageInfo&, uint32&>, void>,
                "EffectAbsorbHandler signature must be \"void HandleAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)\"");

            return { reinterpret_cast<AuraEffectAbsorbFnType>(handler), effIndex, auraType };
        }

        EffectAbsorbHandler(AuraEffectAbsorbFnType callImpl, uint8 effIndex, uint16 auraType);
        EffectAbsorbHandler(EffectAbsorbHandler const& right) = delete;
        EffectAbsorbHandler(EffectAbsorbHandler&& right) noexcept;
        EffectAbsorbHandler& operator=(EffectAbsorbHandler const& right) = delete;
        EffectAbsorbHandler& operator=(EffectAbsorbHandler&& right) noexcept;
        ~EffectAbsorbHandler();
        void Call(AuraScript* auraScript, AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount) const;
    private:
        AuraEffectAbsorbFnType _callImpl;
    };

    class TC_GAME_API EffectAbsorbHealHandler : public EffectBase
    {
    public:
        using AuraEffectAbsorbHealFnType = void(AuraScript::*)(AuraEffect* aurEff, HealInfo& healInfo, uint32& absorbAmount);

        template<typename ScriptFunc>
        static EffectAbsorbHealHandler Create(ScriptFunc handler, uint8 effIndex, uint16 auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraEffectAbsorbHealFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraEffectAbsorbHealFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, AuraEffect*, HealInfo&, uint32&>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, AuraEffect*, HealInfo&, uint32&>, void>,
                "EffectAbsorbHealHandler signature must be \"void HandleAbsorb(AuraEffect* aurEff, HealInfo& healInfo, uint32& absorbAmount)\"");

            return { reinterpret_cast<AuraEffectAbsorbHealFnType>(handler), effIndex, auraType };
        }

        EffectAbsorbHealHandler(AuraEffectAbsorbHealFnType callImpl, uint8 effIndex, uint16 auraType);
        EffectAbsorbHealHandler(EffectAbsorbHealHandler const& right) = delete;
        EffectAbsorbHealHandler(EffectAbsorbHealHandler&& right) noexcept;
        EffectAbsorbHealHandler& operator=(EffectAbsorbHealHandler const& right) = delete;
        EffectAbsorbHealHandler& operator=(EffectAbsorbHealHandler&& right) noexcept;
        ~EffectAbsorbHealHandler();
        void Call(AuraScript* auraScript, AuraEffect* aurEff, HealInfo& healInfo, uint32& absorbAmount) const;
    private:
        AuraEffectAbsorbHealFnType _callImpl;
    };

    class TC_GAME_API CheckProcHandler
    {
    public:
        using AuraCheckProcFnType = bool(AuraScript::*)(ProcEventInfo& eventInfo);

        template<typename ScriptFunc>
        static CheckProcHandler Create(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraCheckProcFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraCheckProcFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, ProcEventInfo&>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, ProcEventInfo&>, bool>,
                "CheckProcHandler signature must be \"bool CheckProc(ProcEventInfo& eventInfo)\"");

            return { reinterpret_cast<AuraCheckProcFnType>(handler) };
        }

        CheckProcHandler(AuraCheckProcFnType callImpl);
        CheckProcHandler(CheckProcHandler const& right) = delete;
        CheckProcHandler(CheckProcHandler&& right) noexcept;
        CheckProcHandler& operator=(CheckProcHandler const& right) = delete;
        CheckProcHandler& operator=(CheckProcHandler&& right) noexcept;
        ~CheckProcHandler();
        bool Call(AuraScript* auraScript, ProcEventInfo& eventInfo) const;
    private:
        AuraCheckProcFnType _callImpl;
    };

    class TC_GAME_API CheckEffectProcHandler : public EffectBase
    {
    public:
        using AuraCheckEffectProcFnType = bool(AuraScript::*)(AuraEffect const* aurEff, ProcEventInfo& eventInfo);

        template<typename ScriptFunc>
        static CheckEffectProcHandler Create(ScriptFunc handler, uint8 effIndex, uint16 auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraCheckEffectProcFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraCheckEffectProcFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, AuraEffect const*, ProcEventInfo&>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, AuraEffect const*, ProcEventInfo&>, bool>,
                "CheckEffectProcHandler signature must be \"bool CheckProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)\"");

            return { reinterpret_cast<AuraCheckEffectProcFnType>(handler), effIndex, auraType };
        }

        CheckEffectProcHandler(AuraCheckEffectProcFnType callImpl, uint8 effIndex, uint16 auraType);
        CheckEffectProcHandler(CheckEffectProcHandler const& right) = delete;
        CheckEffectProcHandler(CheckEffectProcHandler&& right) noexcept;
        CheckEffectProcHandler& operator=(CheckEffectProcHandler const& right) = delete;
        CheckEffectProcHandler& operator=(CheckEffectProcHandler&& right) noexcept;
        ~CheckEffectProcHandler();
        bool Call(AuraScript* auraScript, AuraEffect const* aurEff, ProcEventInfo& eventInfo) const;
    private:
        AuraCheckEffectProcFnType _callImpl;
    };

    class TC_GAME_API AuraProcHandler
    {
    public:
        using AuraProcFnType = void(AuraScript::*)(ProcEventInfo&);

        template<typename ScriptFunc>
        static AuraProcHandler Create(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraProcFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraProcFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, ProcEventInfo&>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, ProcEventInfo&>, void>,
                "AuraProcHandler signature must be \"void HandleProc(ProcEventInfo& eventInfo)\"");

            return { reinterpret_cast<AuraProcFnType>(handler) };
        }

        AuraProcHandler(AuraProcFnType callImpl);
        AuraProcHandler(AuraProcHandler const& right) = delete;
        AuraProcHandler(AuraProcHandler&& right) noexcept;
        AuraProcHandler& operator=(AuraProcHandler const& right) = delete;
        AuraProcHandler& operator=(AuraProcHandler&& right) noexcept;
        virtual ~AuraProcHandler();
        void Call(AuraScript* auraScript, ProcEventInfo& eventInfo) const;
    private:
        AuraProcFnType _callImpl;
    };

    class TC_GAME_API EffectProcHandler : public EffectBase
    {
    public:
        using AuraEffectProcFnType = void(AuraScript::*)(AuraEffect*, ProcEventInfo&);

        template<typename ScriptFunc>
        static EffectProcHandler Create(ScriptFunc handler, uint8 effIndex, uint16 auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraEffectProcFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraEffectProcFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, AuraEffect*, ProcEventInfo&>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, AuraEffect*, ProcEventInfo&>, void>,
                "EffectProcHandler signature must be \"void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)\"");

            return { reinterpret_cast<AuraEffectProcFnType>(handler), effIndex, auraType };
        }

        EffectProcHandler(AuraEffectProcFnType callImpl, uint8 effIndex, uint16 auraType);
        EffectProcHandler(EffectProcHandler const& right) = delete;
        EffectProcHandler(EffectProcHandler&& right) noexcept;
        EffectProcHandler& operator=(EffectProcHandler const& right) = delete;
        EffectProcHandler& operator=(EffectProcHandler&& right) noexcept;
        ~EffectProcHandler();
        void Call(AuraScript* auraScript, AuraEffect* aurEff, ProcEventInfo& eventInfo) const;
    private:
        AuraEffectProcFnType _callImpl;
    };

    class TC_GAME_API EnterLeaveCombatHandler
    {
    public:
        using AuraEnterLeaveCombatFnType = void(AuraScript::*)(bool);

        template<typename ScriptFunc>
        static EnterLeaveCombatHandler Create(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(sizeof(AuraEnterLeaveCombatFnType) >= sizeof(ScriptFunc));
            static_assert(alignof(AuraEnterLeaveCombatFnType) >= alignof(ScriptFunc));
            static_assert(std::is_invocable_v<ScriptFunc, ScriptClass, bool>
                && std::is_same_v<std::invoke_result_t<ScriptFunc, ScriptClass, bool>, void>,
                "EnterLeaveCombatHandler signature must be \"void HandleEnterLeaveCombat(bool isNowInCombat)\"");

            return { reinterpret_cast<AuraEnterLeaveCombatFnType>(handler) };
        }

        EnterLeaveCombatHandler(AuraEnterLeaveCombatFnType callImpl);
        EnterLeaveCombatHandler(EnterLeaveCombatHandler const& right) = delete;
        EnterLeaveCombatHandler(EnterLeaveCombatHandler&& right) noexcept;
        EnterLeaveCombatHandler& operator=(EnterLeaveCombatHandler const& right) = delete;
        EnterLeaveCombatHandler& operator=(EnterLeaveCombatHandler&& right) noexcept;
        ~EnterLeaveCombatHandler();
        void Call(AuraScript* auraScript, bool isNowInCombat) const;
    private:
        AuraEnterLeaveCombatFnType _callImpl;
    };

     // left for custom compatibility only, DO NOT USE
    #define PrepareAuraScript(CLASSNAME) using silence_semicolon_warning_2 = void

public:
    AuraScript();
    ~AuraScript();
    bool _Validate(SpellInfo const* entry) override;
    bool _Load(Aura* aura);
    void _PrepareScriptCall(AuraScriptHookType hookType, AuraApplication const* aurApp = nullptr);
    void _FinishScriptCall();
    bool _IsDefaultActionPrevented() const;
private:
    Aura* m_aura;
    AuraApplication const* m_auraApplication;
    bool m_defaultActionPrevented;

    class TC_GAME_API ScriptStateStore
    {
    public:
        AuraApplication const* _auraApplication;
        uint8 _currentScriptState;
        bool _defaultActionPrevented;
        ScriptStateStore(uint8 currentScriptState, AuraApplication const* auraApplication, bool defaultActionPrevented)
            : _auraApplication(auraApplication), _currentScriptState(currentScriptState), _defaultActionPrevented(defaultActionPrevented)
        { }
    };
    typedef std::stack<ScriptStateStore> ScriptStateStack;
    ScriptStateStack m_scriptStates;

public:
    //
    // AuraScript interface
    // hooks to which you can attach your functions
    //
    // executed when area aura checks if it can be applied on target
    // example: OnEffectApply += AuraEffectApplyFn(class::function);
    // where function is: bool function (Unit* target);
    HookList<CheckAreaTargetHandler> DoCheckAreaTarget;
    #define AuraCheckAreaTargetFn(F) CheckAreaTargetHandler::Create(&F)

    // executed when aura is dispelled by a unit
    // example: OnDispel += AuraDispelFn(class::function);
    // where function is: void function (DispelInfo* dispelInfo);
    HookList<AuraDispelHandler> OnDispel;
    // executed after aura is dispelled by a unit
    // example: AfterDispel += AuraDispelFn(class::function);
    // where function is: void function (DispelInfo* dispelInfo);
    HookList<AuraDispelHandler> AfterDispel;
    #define AuraDispelFn(F) AuraDispelHandler::Create(&F)

    // executed when aura effect is applied with specified mode to target
    // should be used when when effect handler preventing/replacing is needed, do not use this hook for triggering spellcasts/removing auras etc - may be unsafe
    // example: OnEffectApply += AuraEffectApplyFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier, AuraEffectHandleModes);
    // where function is: void function (AuraEffect const* aurEff, AuraEffectHandleModes mode);
    HookList<EffectApplyHandler> OnEffectApply;
    // executed after aura effect is applied with specified mode to target
    // example: AfterEffectApply += AuraEffectApplyFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier, AuraEffectHandleModes);
    // where function is: void function (AuraEffect const* aurEff, AuraEffectHandleModes mode);
    HookList<EffectApplyHandler> AfterEffectApply;
    #define AuraEffectApplyFn(F, I, N, M) EffectApplyHandler::Create(&F, I, N, M)

    // executed after aura effect is removed with specified mode from target
    // should be used when effect handler preventing/replacing is needed, do not use this hook for triggering spellcasts/removing auras etc - may be unsafe
    // example: OnEffectRemove += AuraEffectRemoveFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier, AuraEffectHandleModes);
    // where function is: void function (AuraEffect const* aurEff, AuraEffectHandleModes mode);
    HookList<EffectApplyHandler> OnEffectRemove;
    // executed when aura effect is removed with specified mode from target
    // example: AfterEffectRemove += AuraEffectRemoveFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier, AuraEffectHandleModes);
    // where function is: void function (AuraEffect const* aurEff, AuraEffectHandleModes mode);
    HookList<EffectApplyHandler> AfterEffectRemove;
    #define AuraEffectRemoveFn(F, I, N, M) EffectApplyHandler::Create(&F, I, N, M)

    // executed when periodic aura effect ticks on target
    // example: OnEffectPeriodic += AuraEffectPeriodicFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function (AuraEffect const* aurEff);
    HookList<EffectPeriodicHandler> OnEffectPeriodic;
    #define AuraEffectPeriodicFn(F, I, N) EffectPeriodicHandler::Create(&F, I, N)

    // executed when periodic aura effect is updated
    // example: OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function (AuraEffect* aurEff);
    HookList<EffectUpdatePeriodicHandler> OnEffectUpdatePeriodic;
    #define AuraEffectUpdatePeriodicFn(F, I, N) EffectUpdatePeriodicHandler::Create(&F, I, N)

    // executed when aura effect calculates amount
    // example: DoEffectCalcAmount += AuraEffectCalcAmounFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function (AuraEffect* aurEff, int32& amount, bool& canBeRecalculated);
    HookList<EffectCalcAmountHandler> DoEffectCalcAmount;
    #define AuraEffectCalcAmountFn(F, I, N) EffectCalcAmountHandler::Create(&F, I, N)

    // executed when aura effect calculates periodic data
    // example: DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function (AuraEffect const* aurEff, bool& isPeriodic, int32& amplitude);
    HookList<EffectCalcPeriodicHandler> DoEffectCalcPeriodic;
    #define AuraEffectCalcPeriodicFn(F, I, N) EffectCalcPeriodicHandler::Create(&F, I, N)

    // executed when aura effect calculates spellmod
    // example: DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function (AuraEffect const* aurEff, SpellModifier*& spellMod);
    HookList<EffectCalcSpellModHandler> DoEffectCalcSpellMod;
    #define AuraEffectCalcSpellModFn(F, I, N) EffectCalcSpellModHandler::Create(&F, I, N)

    // executed when aura effect calculates crit chance for dots and hots
    // example: DoEffectCalcCritChance += AuraEffectCalcCritChanceFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function (AuraEffect const* aurEff, Unit* victim, float& critChance);
    HookList<EffectCalcCritChanceHandler> DoEffectCalcCritChance;
    #define AuraEffectCalcCritChanceFn(F, I, N) EffectCalcCritChanceHandler::Create(&F, I, N)

    // executed when absorb aura effect is going to reduce damage
    // example: OnEffectAbsorb += AuraEffectAbsorbFn(class::function, EffectIndexSpecifier);
    // where function is: void function (AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount);
    HookList<EffectAbsorbHandler> OnEffectAbsorb;
    #define AuraEffectAbsorbFn(F, I) EffectAbsorbHandler::Create(&F, I, SPELL_AURA_SCHOOL_ABSORB)
    #define AuraEffectAbsorbOverkillFn(F, I) EffectAbsorbHandler::Create(&F, I, SPELL_AURA_SCHOOL_ABSORB_OVERKILL)

    // executed after absorb aura effect reduced damage to target - absorbAmount is real amount absorbed by aura
    // example: AfterEffectAbsorb += AuraEffectAbsorbFn(class::function, EffectIndexSpecifier);
    // where function is: void function (AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount);
    HookList<EffectAbsorbHandler> AfterEffectAbsorb;

    // executed when absorb aura effect is going to reduce damage
    // example: OnEffectAbsorbHeal += AuraEffectAbsorbHealFn(class::function, EffectIndexSpecifier);
    // where function is: void function (AuraEffect const* aurEff, HealInfo& healInfo, uint32& absorbAmount);
    HookList<EffectAbsorbHealHandler> OnEffectAbsorbHeal;
    #define AuraEffectAbsorbHealFn(F, I) EffectAbsorbHealHandler::Create(&F, I, SPELL_AURA_SCHOOL_HEAL_ABSORB)

    // executed after absorb aura effect reduced heal to target - absorbAmount is real amount absorbed by aura
    // example: AfterEffectAbsorbHeal += AuraEffectAbsorbHealFn(class::function, EffectIndexSpecifier);
    // where function is: void function (AuraEffect* aurEff, HealInfo& healInfo, uint32& absorbAmount);
    HookList<EffectAbsorbHealHandler> AfterEffectAbsorbHeal;

    // executed when mana shield aura effect is going to reduce damage
    // example: OnEffectManaShield += AuraEffectManaShieldFn(class::function, EffectIndexSpecifier);
    // where function is: void function (AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount);
    HookList<EffectAbsorbHandler> OnEffectManaShield;
    #define AuraEffectManaShieldFn(F, I) EffectAbsorbHandler::Create(&F, I, SPELL_AURA_MANA_SHIELD)

    // executed after mana shield aura effect reduced damage to target - absorbAmount is real amount absorbed by aura
    // example: AfterEffectManaShield += AuraEffectManaShieldFn(class::function, EffectIndexSpecifier);
    // where function is: void function (AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount);
    HookList<EffectAbsorbHandler> AfterEffectManaShield;

    // executed when the caster of some spell with split dmg aura gets damaged through it
    // example: OnEffectSplit += AuraEffectSplitFn(class::function, EffectIndexSpecifier);
    // where function is: void function (AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& splitAmount);
    HookList<EffectAbsorbHandler> OnEffectSplit;
    #define AuraEffectSplitFn(F, I) EffectAbsorbHandler::Create(&F, I, SPELL_AURA_SPLIT_DAMAGE_PCT)

    // executed when aura checks if it can proc
    // example: DoCheckProc += AuraCheckProcFn(class::function);
    // where function is: bool function (ProcEventInfo& eventInfo);
    HookList<CheckProcHandler> DoCheckProc;
    #define AuraCheckProcFn(F) CheckProcHandler::Create(&F)

    // executed when aura effect checks if it can proc the aura
    // example: DoCheckEffectProc += AuraCheckEffectProcFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is bool function (AuraEffect const* aurEff, ProcEventInfo& eventInfo);
    HookList<CheckEffectProcHandler> DoCheckEffectProc;
    #define AuraCheckEffectProcFn(F, I, N) CheckEffectProcHandler::Create(&F, I, N)

    // executed before aura procs (possibility to prevent charge drop/cooldown)
    // example: DoPrepareProc += AuraProcFn(class::function);
    // where function is: void function (ProcEventInfo& eventInfo);
    HookList<AuraProcHandler> DoPrepareProc;
    // executed when aura procs
    // example: OnProc += AuraProcFn(class::function);
    // where function is: void function (ProcEventInfo& eventInfo);
    HookList<AuraProcHandler> OnProc;
    // executed after aura proced
    // example: AfterProc += AuraProcFn(class::function);
    // where function is: void function (ProcEventInfo& eventInfo);
    HookList<AuraProcHandler> AfterProc;
    #define AuraProcFn(F) AuraProcHandler::Create(&F)

    // executed when aura effect procs
    // example: OnEffectProc += AuraEffectProcFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function (AuraEffect* aurEff, ProcEventInfo& procInfo);
    HookList<EffectProcHandler> OnEffectProc;
    // executed after aura effect proced
    // example: AfterEffectProc += AuraEffectProcFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function (AuraEffect* aurEff, ProcEventInfo& procInfo);
    HookList<EffectProcHandler> AfterEffectProc;
    #define AuraEffectProcFn(F, I, N) EffectProcHandler::Create(&F, I, N)

    // executed when target enters or leaves combat
    // example: OnEnterLeaveCombat += AuraEnterLeaveCombatFn(class::function)
    // where function is: void function (bool isNowInCombat);
    HookList<EnterLeaveCombatHandler> OnEnterLeaveCombat;
    #define AuraEnterLeaveCombatFn(F) EnterLeaveCombatHandler::Create(&F)

    // AuraScript interface - hook/effect execution manipulators

    // prevents default action of a hook from being executed (works only while called in a hook which default action can be prevented)
    void PreventDefaultAction();

    // AuraScript interface - functions which are redirecting to Aura class

    // returns proto of the spell
    SpellInfo const* GetSpellInfo() const;
    SpellEffectInfo const& GetEffectInfo(SpellEffIndex effIndex) const;
    // returns spellid of the spell
    uint32 GetId() const;

    // returns guid of object which cast the aura (m_originalCaster of the Spell class)
    ObjectGuid GetCasterGUID() const;
    // returns unit which cast the aura or NULL if not avalible (caster logged out for example)
    Unit* GetCaster() const;
    // returns gameobject which cast the aura or NULL if not available
    GameObject* GetGObjCaster() const;
    // returns object on which aura was cast, target for non-area auras, area aura source for area auras
    WorldObject* GetOwner() const;
    // returns owner if it's unit or unit derived object, NULL otherwise (only for persistent area auras NULL is returned)
    Unit* GetUnitOwner() const;
    // returns owner if it's dynobj, NULL otherwise
    DynamicObject* GetDynobjOwner() const;

    // removes aura with remove mode (see AuraRemoveMode enum)
    void Remove(AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
    // returns aura object of script
    Aura* GetAura() const;

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
    int32 CalcMaxDuration() const;
    // expired - duration just went to 0
    bool IsExpired() const;
    // permament - has infinite duration
    bool IsPermanent() const;

    // charges manipulation - 0 - not charged aura
    uint8 GetCharges() const;
    void SetCharges(uint8 charges);
    uint8 CalcMaxCharges() const;
    bool ModCharges(int8 num, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
    // returns true if last charge dropped
    bool DropCharge(AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);

    // stack amount manipulation
    uint8 GetStackAmount() const;
    void SetStackAmount(uint8 num);
    bool ModStackAmount(int32 num, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);

    // passive - "working in background", not saved, not removed by immunities, not seen by player
    bool IsPassive() const;
    // death persistent - not removed on death
    bool IsDeathPersistent() const;

    // check if aura has effect of given effindex
    bool HasEffect(uint8 effIndex) const;
    // returns aura effect of given effect index or NULL
    AuraEffect* GetEffect(uint8 effIndex) const;

    // check if aura has effect of given aura type
    bool HasEffectType(AuraType type) const;

    // AuraScript interface - functions which are redirecting to AuraApplication class
    // Do not call these in hooks in which AuraApplication is not avalible, otherwise result will differ from expected (the functions will return NULL)

    // returns currently processed target of an aura
    // Return value does not need to be NULL-checked, the only situation this will (always)
    // return NULL is when the call happens in an unsupported hook, in other cases, it is always valid
    Unit* GetTarget() const;
    // returns AuraApplication object of currently processed target
    AuraApplication const* GetTargetApplication() const;

    // returns desired cast difficulty for triggered spells
    Difficulty GetCastDifficulty() const;
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

#endif // TRINITY_SPELL_SCRIPT_H
