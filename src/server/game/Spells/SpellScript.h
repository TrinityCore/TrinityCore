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
    SpellScriptBase() noexcept;
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

    // compile barrier to avoid instantiating operator+= in every script file
    template <typename T>
    class HookList : public ::HookList<T>
    {
    public:
        HookList& operator+=(T&& t);
    };

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

    template<typename Return, typename Class, typename... Args>
    struct GetScriptClass<Return(*)(Class&, Args...)>
    {
        using type = std::remove_const_t<Class>;
    };

    template<typename ScriptFunc>
    using GetScriptClass_t = typename GetScriptClass<ScriptFunc>::type;

    template <typename Ret, typename BaseClass, typename... Args>
    struct ScriptFuncInvoker
    {
        union SizeAndAlignment
        {
            Ret(BaseClass::* Member)(Args...);
            Ret(* Static)(BaseClass&, Args...);
        };

        static constexpr std::size_t Size = sizeof(SizeAndAlignment);
        static constexpr std::size_t Alignment = alignof(SizeAndAlignment);

        struct alignas(Alignment) StorageType : std::array<std::byte, Size> { };

        template <typename ScriptFunc>
        struct Impl
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static Ret Invoke(BaseClass& script, Args... args, StorageType callImpl)
            {
                return std::invoke(reinterpret_cast<Impl const*>(callImpl.data())->Func, static_cast<ScriptClass&>(script), args...);
            }

            ScriptFunc Func;
        };

        StorageType ImplStorage;
        Ret(* Thunk)(BaseClass&, Args..., StorageType);
    };

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
    SPELL_SCRIPT_HOOK_CALC_DAMAGE,
    SPELL_SCRIPT_HOOK_CALC_HEALING,
    SPELL_SCRIPT_HOOK_ON_PRECAST,
    SPELL_SCRIPT_HOOK_CALC_CAST_TIME,
    SPELL_SCRIPT_HOOK_EMPOWER_STAGE_COMPLETED,
    SPELL_SCRIPT_HOOK_EMPOWER_COMPLETED,
};

#define HOOK_SPELL_HIT_START SPELL_SCRIPT_HOOK_EFFECT_HIT
#define HOOK_SPELL_HIT_END SPELL_SCRIPT_HOOK_AFTER_HIT + 1

class TC_GAME_API SpellScript : public SpellScriptBase
{
    // internal use classes & functions
    // DO NOT OVERRIDE THESE IN SCRIPTS
    template <typename Ret, typename... Args>
    using ScriptFuncInvoker = SpellScriptBase::ScriptFuncInvoker<Ret, SpellScript, Args...>;

public:
    class CastHandler final
    {
    public:
        using ScriptFuncInvoker = SpellScript::ScriptFuncInvoker<void>;

        template<typename ScriptFunc>
        explicit CastHandler(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&>,
                R""(CastHandler signature must be "void HandleCast()")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(SpellScript* spellScript) const
        {
            return _invoker.Thunk(*spellScript, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class CheckCastHandler final
    {
    public:
        using ScriptFuncInvoker = SpellScript::ScriptFuncInvoker<SpellCastResult>;

        template<typename ScriptFunc>
        explicit CheckCastHandler(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<SpellCastResult, ScriptFunc, ScriptClass&>,
                    R""(CheckCastHandler signature must be "SpellCastResult CheckCast()")"");
            else
                static_assert(std::is_invocable_r_v<SpellCastResult, ScriptFunc, SpellScript&>,
                    R""(CheckCastHandler signature must be "static SpellCastResult CheckCast(your_script_class& script, SpellScript&)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        SpellCastResult Call(SpellScript* spellScript) const
        {
            return _invoker.Thunk(*spellScript, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class TC_GAME_API EffectBase : public EffectHook
    {
    public:
        EffectBase(uint8 effIndex, uint16 effName);
        EffectBase(EffectBase const& right) = delete;
        EffectBase(EffectBase&& right) noexcept;
        EffectBase& operator=(EffectBase const& right) = delete;
        EffectBase& operator=(EffectBase&& right) noexcept;
        ~EffectBase();
        std::string ToString() const;
        bool CheckEffect(SpellInfo const* spellInfo, uint8 effIndex) const override;
    private:
        uint16 _effName;
    };

    class EffectHandler final : public EffectBase
    {
    public:
        using ScriptFuncInvoker = SpellScript::ScriptFuncInvoker<void, SpellEffIndex>;

        template<typename ScriptFunc>
        explicit EffectHandler(ScriptFunc handler, uint8 effIndex, uint16 effName)
            : EffectBase(effIndex, effName)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, SpellEffIndex>,
                R""(EffectHandler signature must be "void HandleEffect(SpellEffIndex effIndex)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(SpellScript* spellScript, SpellEffIndex effIndex) const
        {
            return _invoker.Thunk(*spellScript, effIndex, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class BeforeHitHandler final
    {
    public:
        using ScriptFuncInvoker = SpellScript::ScriptFuncInvoker<void, SpellMissInfo>;

        template<typename ScriptFunc>
        explicit BeforeHitHandler(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, SpellMissInfo>,
                R""(BeforeHitHandler signature must be "void HandleBeforeHit(SpellMissInfo missInfo)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(SpellScript* spellScript, SpellMissInfo missInfo) const
        {
            return _invoker.Thunk(*spellScript, missInfo, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class HitHandler final
    {
    public:
        using ScriptFuncInvoker = SpellScript::ScriptFuncInvoker<void>;

        template<typename ScriptFunc>
        explicit HitHandler(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&>,
                R""(HitHandler signature must be "void HandleHit()")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(SpellScript* spellScript) const
        {
            return _invoker.Thunk(*spellScript, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class OnCalcCritChanceHandler final
    {
    public:
        using ScriptFuncInvoker = SpellScript::ScriptFuncInvoker<void, Unit const*, float&>;

        template<typename ScriptFunc>
        explicit OnCalcCritChanceHandler(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, Unit const*, float&>,
                    R""(OnCalcCritChanceHandler signature must be "void CalcCritChance(Unit const* victim, float& critChance)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, Unit const*, float&>,
                    R""(OnCalcCritChanceHandler signature must be "static void CalcCritChance(your_script_class& script, Unit const* victim, float& critChance)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(SpellScript* spellScript, Unit const* victim, float& critChance) const
        {
            return _invoker.Thunk(*spellScript, victim, critChance, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
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

    class ObjectAreaTargetSelectHandler final : public TargetHook
    {
    public:
        using ScriptFuncInvoker = SpellScript::ScriptFuncInvoker<void, std::list<WorldObject*>&>;

        template<typename ScriptFunc>
        explicit ObjectAreaTargetSelectHandler(ScriptFunc handler, uint8 effIndex, uint16 targetType)
            : TargetHook(effIndex, targetType, true, false)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, std::list<WorldObject*>&>,
                    R""(ObjectAreaTargetSelectHandler signature must be "void SetTargets(std::list<WorldObject*>& targets)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, std::list<WorldObject*>&>,
                    R""(ObjectAreaTargetSelectHandler signature must be "static void SetTargets(your_script_class& script, std::list<WorldObject*>& targets)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(SpellScript* spellScript, std::list<WorldObject*>& targets) const
        {
            return _invoker.Thunk(*spellScript, targets, _invoker.ImplStorage);
        }

        bool HasSameTargetFunctionAs(ObjectAreaTargetSelectHandler const& other) const
        {
            return _invoker.ImplStorage == other._invoker.ImplStorage;
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class ObjectTargetSelectHandler final : public TargetHook
    {
    public:
        using ScriptFuncInvoker = SpellScript::ScriptFuncInvoker<void, WorldObject*&>;

        template<typename ScriptFunc>
        explicit ObjectTargetSelectHandler(ScriptFunc handler, uint8 effIndex, uint16 targetType)
            : TargetHook(effIndex, targetType, false, false)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, WorldObject*&>,
                    R""(ObjectTargetSelectHandler signature must be "void SetTarget(WorldObject*& target)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, WorldObject*&>,
                    R""(ObjectTargetSelectHandler signature must be "static void SetTarget(your_script_class& script, WorldObject*& target)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(SpellScript* spellScript, WorldObject*& target) const
        {
            return _invoker.Thunk(*spellScript, target, _invoker.ImplStorage);
        }

        bool HasSameTargetFunctionAs(ObjectTargetSelectHandler const& other) const
        {
            return _invoker.ImplStorage == other._invoker.ImplStorage;
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class DestinationTargetSelectHandler final : public TargetHook
    {
    public:
        using ScriptFuncInvoker = SpellScript::ScriptFuncInvoker<void, SpellDestination&>;

        template<typename ScriptFunc>
        explicit DestinationTargetSelectHandler(ScriptFunc handler, uint8 effIndex, uint16 targetType)
            : TargetHook(effIndex, targetType, false, true)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, SpellDestination&>,
                    R""(DestinationTargetSelectHandler signature must be "void SetTarget(SpellDestination& target)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, SpellDestination&>,
                    R""(DestinationTargetSelectHandler signature must be "static void SetTarget(your_script_class& script, SpellDestination& target)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(SpellScript* spellScript, SpellDestination& target) const
        {
            return _invoker.Thunk(*spellScript, target, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class DamageAndHealingCalcHandler final
    {
    public:
        using ScriptFuncInvoker = SpellScript::ScriptFuncInvoker<void, SpellEffectInfo const&, Unit*, int32&, int32&, float&>;

        template<typename ScriptFunc>
        explicit DamageAndHealingCalcHandler(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, SpellEffectInfo const&, Unit*, int32&, int32&, float&>,
                    R""(DamageAndHealingCalcHandler signature must be "void CalcDamage(SpellEffectInfo const& spellEffectInfo, Unit* victim, int32& damageOrHealing, int32& flatMod, float& pctMod)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, SpellEffectInfo const&, Unit*, int32&, int32&, float&>,
                    R""(DamageAndHealingCalcHandler signature must be "static void CalcDamage(your_script_class& script, SpellEffectInfo const& spellEffectInfo, Unit* victim, int32& damageOrHealing, int32& flatMod, float& pctMod)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(SpellScript* spellScript, SpellEffectInfo const& spellEffectInfo, Unit* victim, int32& damageOrHealing, int32& flatMod, float& pctMod) const
        {
            return _invoker.Thunk(*spellScript, spellEffectInfo, victim, damageOrHealing, flatMod, pctMod, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class OnCalculateResistAbsorbHandler final
    {
    public:
        using ScriptFuncInvoker = SpellScript::ScriptFuncInvoker<void, DamageInfo const&, uint32&, int32&>;

        template<typename ScriptFunc>
        explicit OnCalculateResistAbsorbHandler(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, DamageInfo const&, uint32&, int32&>,
                    R""(OnCalculateResistAbsorbHandler signature must be "void CalcAbsorbResist(DamageInfo const& damageInfo, uint32& resistAmount, int32& absorbAmount)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, DamageInfo const&, uint32&, int32&>,
                    R""(OnCalculateResistAbsorbHandler signature must be "static void CalcAbsorbResist(your_script_class& script, DamageInfo const& damageInfo, uint32& resistAmount, int32& absorbAmount)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(SpellScript* spellScript, DamageInfo const& damageInfo, uint32& resistAmount, int32& absorbAmount) const
        {
            return _invoker.Thunk(*spellScript, damageInfo, resistAmount, absorbAmount, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class EmpowerStageCompletedHandler final
    {
    public:
        using ScriptFuncInvoker = SpellScript::ScriptFuncInvoker<void, int32>;

        template<typename ScriptFunc>
        explicit EmpowerStageCompletedHandler(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, int32>,
                R""(EmpowerStageCompleted/EmpowerCompleted signature must be "void HandleEmpowerStageCompleted(int32 completedStagesCount)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(SpellScript* spellScript, int32 completedStagesCount) const
        {
            return _invoker.Thunk(*spellScript, completedStagesCount, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

     // left for custom compatibility only, DO NOT USE
    #define PrepareSpellScript(CLASSNAME)

    SpellScript() noexcept;
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
    #define SpellCastFn(F) CastHandler(&F)

    // example: OnCheckCast += SpellCheckCastFn();
    // where function is SpellCastResult function()
    HookList<CheckCastHandler> OnCheckCast;
    #define SpellCheckCastFn(F) CheckCastHandler(&F)

    // example: int32 CalcCastTime(int32 castTime) override { return 1500; }
    virtual int32 CalcCastTime(int32 castTime) { return castTime; }

    // example: OnEffect**** += SpellEffectFn(class::function, EffectIndexSpecifier, EffectNameSpecifier);
    // where function is void function(SpellEffIndex effIndex)
    HookList<EffectHandler> OnEffectLaunch;
    HookList<EffectHandler> OnEffectLaunchTarget;
    HookList<EffectHandler> OnEffectHit;
    HookList<EffectHandler> OnEffectHitTarget;
    HookList<EffectHandler> OnEffectSuccessfulDispel;
    #define SpellEffectFn(F, I, N) EffectHandler(&F, I, N)

    // example: BeforeHit += BeforeSpellHitFn(class::function);
    // where function is void function(SpellMissInfo missInfo)
    HookList<BeforeHitHandler> BeforeHit;
    #define BeforeSpellHitFn(F) BeforeHitHandler(&F)

    // example: OnHit += SpellHitFn(class::function);
    HookList<HitHandler> OnHit;
    // example: AfterHit += SpellHitFn(class::function);
    HookList<HitHandler> AfterHit;
    // where function is: void function()
    #define SpellHitFn(F) HitHandler(&F)

    // example: OnCalcCritChance += SpellOnCalcCritChanceFn(class::function);
    // where function is: void function(Unit* victim, float& critChance)
    HookList<OnCalcCritChanceHandler> OnCalcCritChance;
    #define SpellOnCalcCritChanceFn(F) OnCalcCritChanceHandler(&F)

    // example: OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(class::function, EffectIndexSpecifier, TargetsNameSpecifier);
    // where function is void function(std::list<WorldObject*>& targets)
    HookList<ObjectAreaTargetSelectHandler> OnObjectAreaTargetSelect;
    #define SpellObjectAreaTargetSelectFn(F, I, N) ObjectAreaTargetSelectHandler(&F, I, N)

    // example: OnObjectTargetSelect += SpellObjectTargetSelectFn(class::function, EffectIndexSpecifier, TargetsNameSpecifier);
    // where function is void function(WorldObject*& target)
    HookList<ObjectTargetSelectHandler> OnObjectTargetSelect;
    #define SpellObjectTargetSelectFn(F, I, N) ObjectTargetSelectHandler(&F, I, N)

    // example: OnDestinationTargetSelect += SpellDestinationTargetSelectFn(class::function, EffectIndexSpecifier, TargetsNameSpecifier);
    // where function is void function(SpellDestination& target)
    HookList<DestinationTargetSelectHandler> OnDestinationTargetSelect;
    #define SpellDestinationTargetSelectFn(F, I, N) DestinationTargetSelectHandler(&F, I, N)

    // example: CalcDamage += SpellCalcDamageFn(class::function);
    // where function is void function(SpellEffectInfo const& effectInfo, Unit* victim, int32& damage, int32& flatMod, float& pctMod)
    HookList<DamageAndHealingCalcHandler> CalcDamage;
    #define SpellCalcDamageFn(F) DamageAndHealingCalcHandler(&F)

    // example: CalcHealing += SpellCalcHealingFn(class::function);
    // where function is void function(SpellEffectInfo const& effectInfo, Unit* victim, int32& healing, int32& flatMod, float& pctMod)
    HookList<DamageAndHealingCalcHandler> CalcHealing;
    #define SpellCalcHealingFn(F) DamageAndHealingCalcHandler(&F)

    // example: OnCalculateResistAbsorb += SpellOnResistAbsorbCalculateFn(class::function);
    // where function is void function(DamageInfo const& damageInfo, uint32& resistAmount, int32& absorbAmount)
    HookList<OnCalculateResistAbsorbHandler> OnCalculateResistAbsorb;
    #define SpellOnResistAbsorbCalculateFn(F) OnCalculateResistAbsorbHandler(&F)

    // example: OnEmpowerStageCompleted += SpellOnEmpowerStageCompletedFn(class::function);
    // where function is void function(int32 completedStages)
    HookList<EmpowerStageCompletedHandler> OnEmpowerStageCompleted;
    #define SpellOnEmpowerStageCompletedFn(F) EmpowerStageCompletedHandler(&F)

    // example: OnEmpowerCompleted += SpellOnEmpowerCompletedFn(class::function);
    // where function is void function(int32 completedStages)
    HookList<EmpowerStageCompletedHandler> OnEmpowerCompleted;
    #define SpellOnEmpowerCompletedFn(F) EmpowerStageCompletedHandler(&F)

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
    // 8. OnCalcCritChance - executed just after specified effect handler call - when spell missile is launched - called for each target from spell target map
    // 9. OnEffectLaunchTarget - executed just before specified effect handler call - when spell missile is launched - called for each target from spell target map
    // 10a. CalcDamage - executed during specified effect handler call - when spell missile is launched - called for each target from spell target map
    // 10b. CalcHealing - executed during specified effect handler call - when spell missile is launched - called for each target from spell target map
    // 11. OnCalculateResistAbsorb - executed when damage resist/absorbs is calculated - before spell hit target
    // 12. OnEffectHit - executed just before specified effect handler call - when spell missile hits dest
    // 13. BeforeHit - executed just before spell hits a target - called for each target from spell target map
    // 14. OnEffectHitTarget - executed just before specified effect handler call - called for each target from spell target map
    // 15. OnHit - executed just before spell deals damage and procs auras - when spell hits target - called for each target from spell target map
    // 16. AfterHit - executed just after spell finishes all it's jobs for target - called for each target from spell target map
    // 17. OnEmpowerStageCompleted - executed when empowered spell completes each stage
    // 18. OnEmpowerCompleted - executed when empowered spell is released

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

    void SetExplTargetDest(WorldLocation const& loc);

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
    Aura* GetHitAura(bool dynObjAura = false, bool withRemoved = false) const;
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
    AURA_SCRIPT_HOOK_EFFECT_CALC_DAMAGE_AND_HEALING,
    AURA_SCRIPT_HOOK_EFFECT_ABSORB,
    AURA_SCRIPT_HOOK_EFFECT_AFTER_ABSORB,
    AURA_SCRIPT_HOOK_EFFECT_MANASHIELD,
    AURA_SCRIPT_HOOK_EFFECT_AFTER_MANASHIELD,
    AURA_SCRIPT_HOOK_EFFECT_SPLIT,
    AURA_SCRIPT_HOOK_CHECK_AREA_TARGET,
    AURA_SCRIPT_HOOK_DISPEL,
    AURA_SCRIPT_HOOK_AFTER_DISPEL,
    AURA_SCRIPT_HOOK_ON_HEARTBEAT,
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
    template <typename Ret, typename... Args>
    using ScriptFuncInvoker = SpellScriptBase::ScriptFuncInvoker<Ret, AuraScript, Args...>;

public:
    class CheckAreaTargetHandler final
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<bool, Unit*>;

        template<typename ScriptFunc>
        explicit CheckAreaTargetHandler(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<bool, ScriptFunc, ScriptClass&, Unit*>,
                    R""(CheckAreaTargetHandler signature must be "bool CheckTarget(Unit* target)")"");
            else
                static_assert(std::is_invocable_r_v<bool, ScriptFunc, ScriptClass&, Unit*>,
                    R""(CheckAreaTargetHandler signature must be "static bool CheckTarget(your_script_class& script, Unit* target)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        bool Call(AuraScript* auraScript, Unit* target) const
        {
            return _invoker.Thunk(*auraScript, target, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class AuraDispelHandler final
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void, DispelInfo*>;

        template<typename ScriptFunc>
        explicit AuraDispelHandler(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, DispelInfo*>,
                    R""(AuraDispelHandler signature must be "void HandleDispel(DispelInfo* dispelInfo)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, DispelInfo*>,
                    R""(AuraDispelHandler signature must be "static void HandleDispel(your_script_class& script, DispelInfo* dispelInfo)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript, DispelInfo* dispelInfo) const
        {
            return _invoker.Thunk(*auraScript, dispelInfo, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class AuraHeartbeatHandler final
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void>;

        template<typename ScriptFunc>
        explicit AuraHeartbeatHandler(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass>,
                    R""(AuraHeartbeatHandler signature must be "void HandleHeartbeat()")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc>,
                    R""(AuraHeartbeatHandler signature must be "static void HandleHeartbeat(your_script_class& script)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript) const
        {
            return _invoker.Thunk(*auraScript, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
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

    class EffectPeriodicHandler final : public EffectBase
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void, AuraEffect const*>;

        template<typename ScriptFunc>
        explicit EffectPeriodicHandler(ScriptFunc handler, uint8 effIndex, uint16 auraType)
            : EffectBase(effIndex, auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect const*>,
                    R""(EffectPeriodicHandler signature must be "void HandlePeriodic(AuraEffect const* aurEff)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect const*>,
                    R""(EffectPeriodicHandler signature must be "static void HandlePeriodic(your_script_class& script, AuraEffect const* aurEff)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript, AuraEffect const* aurEff) const
        {
            return _invoker.Thunk(*auraScript, aurEff, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class EffectUpdatePeriodicHandler final : public EffectBase
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void, AuraEffect*>;

        template<typename ScriptFunc>
        explicit EffectUpdatePeriodicHandler(ScriptFunc handler, uint8 effIndex, uint16 auraType)
            : EffectBase(effIndex, auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect*>,
                    R""(EffectUpdatePeriodicHandler signature must be "void HandleUpdatePeriodic(AuraEffect* aurEff)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect*>,
                    R""(EffectUpdatePeriodicHandler signature must be "static void HandleUpdatePeriodic(your_script_class& script, AuraEffect* aurEff)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript, AuraEffect* aurEff) const
        {
            return _invoker.Thunk(*auraScript, aurEff, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class EffectCalcAmountHandler final : public EffectBase
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void, AuraEffect const*, int32&, bool&>;

        template<typename ScriptFunc>
        explicit EffectCalcAmountHandler(ScriptFunc handler, uint8 effIndex, uint16 auraType)
            : EffectBase(effIndex, auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect const*, int32&, bool&>,
                    R""(EffectCalcAmountHandler signature must be "void CalcAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect const*, int32&, bool&>,
                    R""(EffectCalcAmountHandler signature must be "static void CalcAmount(your_script_class& script, AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript, AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated) const
        {
            return _invoker.Thunk(*auraScript, aurEff, amount, canBeRecalculated, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class EffectCalcPeriodicHandler final : public EffectBase
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void, AuraEffect const*, bool&, int32&>;

        template<typename ScriptFunc>
        explicit EffectCalcPeriodicHandler(ScriptFunc handler, uint8 effIndex, uint16 auraType)
            : EffectBase(effIndex, auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect const*, bool&, int32&>,
                    R""(EffectCalcPeriodicHandler signature must be "void CalcPeriodic(AuraEffect const* aurEff, bool& isPeriodic, int32& periodicTimer)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect const*, bool&, int32&>,
                    R""(EffectCalcPeriodicHandler signature must be "static void CalcPeriodic(your_script_class& script, AuraEffect const* aurEff, bool& isPeriodic, int32& periodicTimer)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript, AuraEffect const* aurEff, bool& isPeriodic, int32& periodicTimer) const
        {
            return _invoker.Thunk(*auraScript, aurEff, isPeriodic, periodicTimer, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class EffectCalcSpellModHandler final : public EffectBase
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void, AuraEffect const*, SpellModifier*&>;

        template<typename ScriptFunc>
        explicit EffectCalcSpellModHandler(ScriptFunc handler, uint8 effIndex, uint16 auraType)
            : EffectBase(effIndex, auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect const*, SpellModifier*&>,
                    R""(EffectCalcSpellModHandler signature must be "void CalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect const*, SpellModifier*&>,
                    R""(EffectCalcSpellModHandler signature must be "static void CalcSpellMod(your_script_class& script, AuraEffect const* aurEff, SpellModifier*& spellMod)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript, AuraEffect const* aurEff, SpellModifier*& spellMod) const
        {
            return _invoker.Thunk(*auraScript, aurEff, spellMod, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class EffectCalcCritChanceHandler final : public EffectBase
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void, AuraEffect const*, Unit const*, float&>;

        template<typename ScriptFunc>
        explicit EffectCalcCritChanceHandler(ScriptFunc handler, uint8 effIndex, uint16 auraType)
            : EffectBase(effIndex, auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect const*, Unit const*, float&>,
                    R""(EffectCalcCritChanceHandler signature must be "void CalcCritChance(AuraEffect const* aurEff, Unit const* victim, float& critChance)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect const*, Unit const*, float&>,
                    R""(EffectCalcCritChanceHandler signature must be "static void CalcCritChance(your_script_class& script, AuraEffect const* aurEff, Unit const* victim, float& critChance)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript, AuraEffect const* aurEff, Unit const* victim, float& critChance) const
        {
            return _invoker.Thunk(*auraScript, aurEff, victim, critChance, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class EffectCalcDamageAndHealingHandler final : public EffectBase
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void, AuraEffect const*, Unit*, int32&, int32&, float&>;

        template<typename ScriptFunc>
        explicit EffectCalcDamageAndHealingHandler(ScriptFunc handler, uint8 effIndex, uint16 auraType)
            : EffectBase(effIndex, auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect const*, Unit*, int32&, int32&, float&>,
                    R""(EffectCalcDamageAndHealingHandler signature must be "void CalcDamageAndHealing(AuraEffect const* aurEff, Unit* victim, int32& damageOrHealing, int32& flatMod, float& pctMod)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect const*, Unit*, int32&, int32&, float&>,
                    R""(EffectCalcDamageAndHealingHandler signature must be "static void CalcDamageAndHealing(your_script_class& script, AuraEffect const* aurEff, Unit* victim, int32& damageOrHealing, int32& flatMod, float& pctMod)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript, AuraEffect const* aurEff, Unit* victim, int32& damageOrHealing, int32& flatMod, float& pctMod) const
        {
            return _invoker.Thunk(*auraScript, aurEff, victim, damageOrHealing, flatMod, pctMod, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class EffectApplyHandler final : public EffectBase
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void, AuraEffect const*, AuraEffectHandleModes>;

        template<typename ScriptFunc>
        explicit EffectApplyHandler(ScriptFunc handler, uint8 effIndex, uint16 auraType, AuraEffectHandleModes mode)
            : EffectBase(effIndex, auraType), _mode(mode)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect const*, AuraEffectHandleModes>,
                    R""(EffectApplyHandler signature must be "void HandleApplyOrRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect const*, AuraEffectHandleModes>,
                    R""(EffectApplyHandler signature must be "static void HandleApplyOrRemove(your_script_class& script, AuraEffect const* aurEff, AuraEffectHandleModes mode)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript, AuraEffect const* aurEff, AuraEffectHandleModes mode) const
        {
            if (!(_mode & mode))
                return;

            return _invoker.Thunk(*auraScript, aurEff, mode, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
        AuraEffectHandleModes _mode;
    };

    class EffectAbsorbHandler final : public EffectBase
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void, AuraEffect*, DamageInfo&, uint32&>;

        template<typename ScriptFunc>
        explicit EffectAbsorbHandler(ScriptFunc handler, uint8 effIndex, uint16 auraType)
            : EffectBase(effIndex, auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect*, DamageInfo&, uint32&>,
                    R""(EffectAbsorbHandler signature must be "void HandleAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect*, DamageInfo&, uint32&>,
                    R""(EffectAbsorbHandler signature must be "static void HandleAbsorb(your_script_class& script, AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript, AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount) const
        {
            return _invoker.Thunk(*auraScript, aurEff, dmgInfo, absorbAmount, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class EffectAbsorbHealHandler final : public EffectBase
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void, AuraEffect*, HealInfo&, uint32&>;

        template<typename ScriptFunc>
        explicit EffectAbsorbHealHandler(ScriptFunc handler, uint8 effIndex, uint16 auraType)
            : EffectBase(effIndex, auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect*, HealInfo&, uint32&>,
                    R""(EffectAbsorbHealHandler signature must be "void HandleAbsorb(AuraEffect* aurEff, HealInfo& healInfo, uint32& absorbAmount)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect*, HealInfo&, uint32&>,
                    R""(EffectAbsorbHealHandler signature must be "static void HandleAbsorb(your_script_class& script, AuraEffect* aurEff, HealInfo& healInfo, uint32& absorbAmount)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript, AuraEffect* aurEff, HealInfo& healInfo, uint32& absorbAmount) const
        {
            return _invoker.Thunk(*auraScript, aurEff, healInfo, absorbAmount, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class CheckProcHandler final
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<bool, ProcEventInfo&>;

        template<typename ScriptFunc>
        explicit CheckProcHandler(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<bool, ScriptFunc, ScriptClass&, ProcEventInfo&>,
                    R""(CheckProcHandler signature must be "bool CheckProc(ProcEventInfo& eventInfo)")"");
            else
                static_assert(std::is_invocable_r_v<bool, ScriptFunc, ScriptClass&, ProcEventInfo&>,
                    R""(CheckProcHandler signature must be "static bool CheckProc(your_script_class& script, ProcEventInfo& eventInfo)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        bool Call(AuraScript* auraScript, ProcEventInfo& eventInfo) const
        {
            return _invoker.Thunk(*auraScript, eventInfo, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class CheckEffectProcHandler final : public EffectBase
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<bool, AuraEffect const*, ProcEventInfo&>;

        template<typename ScriptFunc>
        explicit CheckEffectProcHandler(ScriptFunc handler, uint8 effIndex, uint16 auraType)
            : EffectBase(effIndex, auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<bool, ScriptFunc, ScriptClass&, AuraEffect const*, ProcEventInfo&>,
                    R""(CheckEffectProcHandler signature must be "bool CheckProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)")"");
            else
                static_assert(std::is_invocable_r_v<bool, ScriptFunc, ScriptClass&, AuraEffect const*, ProcEventInfo&>,
                    R""(CheckEffectProcHandler signature must be "static bool CheckProc(your_script_class& script, AuraEffect const* aurEff, ProcEventInfo& eventInfo)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        bool Call(AuraScript* auraScript, AuraEffect const* aurEff, ProcEventInfo& eventInfo) const
        {
            return _invoker.Thunk(*auraScript, aurEff, eventInfo, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class AuraProcHandler final
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void, ProcEventInfo&>;

        template<typename ScriptFunc>
        explicit AuraProcHandler(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, ProcEventInfo&>,
                    R""(AuraProcHandler signature must be "void HandleProc(ProcEventInfo& eventInfo)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, ProcEventInfo&>,
                    R""(AuraProcHandler signature must be "static void HandleProc(your_script_class& script, ProcEventInfo& eventInfo)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript, ProcEventInfo& eventInfo) const
        {
            return _invoker.Thunk(*auraScript, eventInfo, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class EffectProcHandler final : public EffectBase
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void, AuraEffect*, ProcEventInfo&>;

        template<typename ScriptFunc>
        explicit EffectProcHandler(ScriptFunc handler, uint8 effIndex, uint16 auraType)
            : EffectBase(effIndex, auraType)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            if constexpr (std::is_member_function_pointer_v<ScriptFunc>)
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect*, ProcEventInfo&>,
                    R""(EffectProcHandler signature must be "void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)")"");
            else
                static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass&, AuraEffect*, ProcEventInfo&>,
                    R""(EffectProcHandler signature must be "static void HandleProc(your_script_class& script, AuraEffect* aurEff, ProcEventInfo& eventInfo)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript, AuraEffect* aurEff, ProcEventInfo& eventInfo) const
        {
            return _invoker.Thunk(*auraScript, aurEff, eventInfo, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

    class EnterLeaveCombatHandler final
    {
    public:
        using ScriptFuncInvoker = AuraScript::ScriptFuncInvoker<void, bool>;

        template<typename ScriptFunc>
        explicit EnterLeaveCombatHandler(ScriptFunc handler)
        {
            using ScriptClass = GetScriptClass_t<ScriptFunc>;

            static_assert(ScriptFuncInvoker::Size >= sizeof(ScriptFunc));
            static_assert(ScriptFuncInvoker::Alignment >= alignof(ScriptFunc));

            static_assert(std::is_invocable_r_v<void, ScriptFunc, ScriptClass, bool>,
                R""(EnterLeaveCombatHandler signature must be "void HandleEnterLeaveCombat(bool isNowInCombat)")"");

            new (_invoker.ImplStorage.data()) ScriptFuncInvoker::Impl<ScriptFunc>{ .Func = handler };
            _invoker.Thunk = &ScriptFuncInvoker::Impl<ScriptFunc>::Invoke;
        }

        void Call(AuraScript* auraScript, bool isNowInCombat) const
        {
            return _invoker.Thunk(*auraScript, isNowInCombat, _invoker.ImplStorage);
        }
    private:
        ScriptFuncInvoker _invoker;
    };

     // left for custom compatibility only, DO NOT USE
    #define PrepareAuraScript(CLASSNAME)

public:
    AuraScript() noexcept;
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
    // where function is: bool function(Unit* target);
    HookList<CheckAreaTargetHandler> DoCheckAreaTarget;
    #define AuraCheckAreaTargetFn(F) CheckAreaTargetHandler(&F)

    // executed when aura is dispelled by a unit
    // example: OnDispel += AuraDispelFn(class::function);
    // where function is: void function(DispelInfo* dispelInfo);
    HookList<AuraDispelHandler> OnDispel;
    // executed after aura is dispelled by a unit
    // example: AfterDispel += AuraDispelFn(class::function);
    // where function is: void function(DispelInfo* dispelInfo);
    HookList<AuraDispelHandler> AfterDispel;
    #define AuraDispelFn(F) AuraDispelHandler(&F)

    // executed on every heartbeat of a unit
    // example: OnHeartbeat += AuraHeartbeatFn(class::function);
    // where function is: void function();
    HookList<AuraHeartbeatHandler> OnHeartbeat;
    #define AuraHeartbeatFn(F) AuraHeartbeatHandler(&F)

    // executed when aura effect is applied with specified mode to target
    // should be used when when effect handler preventing/replacing is needed, do not use this hook for triggering spellcasts/removing auras etc - may be unsafe
    // example: OnEffectApply += AuraEffectApplyFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier, AuraEffectHandleModes);
    // where function is: void function(AuraEffect const* aurEff, AuraEffectHandleModes mode);
    HookList<EffectApplyHandler> OnEffectApply;
    // executed after aura effect is applied with specified mode to target
    // example: AfterEffectApply += AuraEffectApplyFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier, AuraEffectHandleModes);
    // where function is: void function(AuraEffect const* aurEff, AuraEffectHandleModes mode);
    HookList<EffectApplyHandler> AfterEffectApply;
    #define AuraEffectApplyFn(F, I, N, M) EffectApplyHandler(&F, I, N, M)

    // executed after aura effect is removed with specified mode from target
    // should be used when effect handler preventing/replacing is needed, do not use this hook for triggering spellcasts/removing auras etc - may be unsafe
    // example: OnEffectRemove += AuraEffectRemoveFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier, AuraEffectHandleModes);
    // where function is: void function(AuraEffect const* aurEff, AuraEffectHandleModes mode);
    HookList<EffectApplyHandler> OnEffectRemove;
    // executed when aura effect is removed with specified mode from target
    // example: AfterEffectRemove += AuraEffectRemoveFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier, AuraEffectHandleModes);
    // where function is: void function(AuraEffect const* aurEff, AuraEffectHandleModes mode);
    HookList<EffectApplyHandler> AfterEffectRemove;
    #define AuraEffectRemoveFn(F, I, N, M) EffectApplyHandler(&F, I, N, M)

    // executed when periodic aura effect ticks on target
    // example: OnEffectPeriodic += AuraEffectPeriodicFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function(AuraEffect const* aurEff);
    HookList<EffectPeriodicHandler> OnEffectPeriodic;
    #define AuraEffectPeriodicFn(F, I, N) EffectPeriodicHandler(&F, I, N)

    // executed when periodic aura effect is updated
    // example: OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function(AuraEffect* aurEff);
    HookList<EffectUpdatePeriodicHandler> OnEffectUpdatePeriodic;
    #define AuraEffectUpdatePeriodicFn(F, I, N) EffectUpdatePeriodicHandler(&F, I, N)

    // executed when aura effect calculates amount
    // example: DoEffectCalcAmount += AuraEffectCalcAmounFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function(AuraEffect* aurEff, int32& amount, bool& canBeRecalculated);
    HookList<EffectCalcAmountHandler> DoEffectCalcAmount;
    #define AuraEffectCalcAmountFn(F, I, N) EffectCalcAmountHandler(&F, I, N)

    // executed when aura effect calculates periodic data
    // example: DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function(AuraEffect const* aurEff, bool& isPeriodic, int32& amplitude);
    HookList<EffectCalcPeriodicHandler> DoEffectCalcPeriodic;
    #define AuraEffectCalcPeriodicFn(F, I, N) EffectCalcPeriodicHandler(&F, I, N)

    // executed when aura effect calculates spellmod
    // example: DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function(AuraEffect const* aurEff, SpellModifier*& spellMod);
    HookList<EffectCalcSpellModHandler> DoEffectCalcSpellMod;
    #define AuraEffectCalcSpellModFn(F, I, N) EffectCalcSpellModHandler(&F, I, N)

    // executed when aura effect calculates crit chance for dots and hots
    // example: DoEffectCalcCritChance += AuraEffectCalcCritChanceFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function(AuraEffect const* aurEff, Unit* victim, float& critChance);
    HookList<EffectCalcCritChanceHandler> DoEffectCalcCritChance;
    #define AuraEffectCalcCritChanceFn(F, I, N) EffectCalcCritChanceHandler(&F, I, N)

    // executed when aura effect calculates damage or healing for dots and hots
    // example: DoEffectCalcDamageAndHealing += AuraEffectCalcDamageFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // example: DoEffectCalcDamageAndHealing += AuraEffectCalcHealingFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function(AuraEffect const* aurEff, Unit* victim, int32& damageOrHealing, int32& flatMod, float& pctMod);
    HookList<EffectCalcDamageAndHealingHandler> DoEffectCalcDamageAndHealing;
    #define AuraEffectCalcDamageFn(F, I, N) EffectCalcDamageAndHealingHandler(&F, I, N)
    #define AuraEffectCalcHealingFn(F, I, N) EffectCalcDamageAndHealingHandler(&F, I, N)

    // executed when absorb aura effect is going to reduce damage
    // example: OnEffectAbsorb += AuraEffectAbsorbFn(class::function, EffectIndexSpecifier);
    // where function is: void function(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount);
    HookList<EffectAbsorbHandler> OnEffectAbsorb;
    #define AuraEffectAbsorbFn(F, I) EffectAbsorbHandler(&F, I, SPELL_AURA_SCHOOL_ABSORB)
    #define AuraEffectAbsorbOverkillFn(F, I) EffectAbsorbHandler(&F, I, SPELL_AURA_SCHOOL_ABSORB_OVERKILL)

    // executed after absorb aura effect reduced damage to target - absorbAmount is real amount absorbed by aura
    // example: AfterEffectAbsorb += AuraEffectAbsorbFn(class::function, EffectIndexSpecifier);
    // where function is: void function(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount);
    HookList<EffectAbsorbHandler> AfterEffectAbsorb;

    // executed when absorb aura effect is going to reduce damage
    // example: OnEffectAbsorbHeal += AuraEffectAbsorbHealFn(class::function, EffectIndexSpecifier);
    // where function is: void function(AuraEffect const* aurEff, HealInfo& healInfo, uint32& absorbAmount);
    HookList<EffectAbsorbHealHandler> OnEffectAbsorbHeal;
    #define AuraEffectAbsorbHealFn(F, I) EffectAbsorbHealHandler(&F, I, SPELL_AURA_SCHOOL_HEAL_ABSORB)

    // executed after absorb aura effect reduced heal to target - absorbAmount is real amount absorbed by aura
    // example: AfterEffectAbsorbHeal += AuraEffectAbsorbHealFn(class::function, EffectIndexSpecifier);
    // where function is: void function(AuraEffect* aurEff, HealInfo& healInfo, uint32& absorbAmount);
    HookList<EffectAbsorbHealHandler> AfterEffectAbsorbHeal;

    // executed when mana shield aura effect is going to reduce damage
    // example: OnEffectManaShield += AuraEffectManaShieldFn(class::function, EffectIndexSpecifier);
    // where function is: void function (AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount);
    HookList<EffectAbsorbHandler> OnEffectManaShield;
    #define AuraEffectManaShieldFn(F, I) EffectAbsorbHandler(&F, I, SPELL_AURA_MANA_SHIELD)

    // executed after mana shield aura effect reduced damage to target - absorbAmount is real amount absorbed by aura
    // example: AfterEffectManaShield += AuraEffectManaShieldFn(class::function, EffectIndexSpecifier);
    // where function is: void function(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount);
    HookList<EffectAbsorbHandler> AfterEffectManaShield;

    // executed when the caster of some spell with split dmg aura gets damaged through it
    // example: OnEffectSplit += AuraEffectSplitFn(class::function, EffectIndexSpecifier);
    // where function is: void function(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& splitAmount);
    HookList<EffectAbsorbHandler> OnEffectSplit;
    #define AuraEffectSplitFn(F, I) EffectAbsorbHandler(&F, I, SPELL_AURA_SPLIT_DAMAGE_PCT)

    // executed when aura checks if it can proc
    // example: DoCheckProc += AuraCheckProcFn(class::function);
    // where function is: bool function(ProcEventInfo& eventInfo);
    HookList<CheckProcHandler> DoCheckProc;
    #define AuraCheckProcFn(F) CheckProcHandler(&F)

    // executed when aura effect checks if it can proc the aura
    // example: DoCheckEffectProc += AuraCheckEffectProcFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is bool function(AuraEffect const* aurEff, ProcEventInfo& eventInfo);
    HookList<CheckEffectProcHandler> DoCheckEffectProc;
    #define AuraCheckEffectProcFn(F, I, N) CheckEffectProcHandler(&F, I, N)

    // executed before aura procs (possibility to prevent charge drop/cooldown)
    // example: DoPrepareProc += AuraProcFn(class::function);
    // where function is: void function(ProcEventInfo& eventInfo);
    HookList<AuraProcHandler> DoPrepareProc;
    // executed when aura procs
    // example: OnProc += AuraProcFn(class::function);
    // where function is: void function(ProcEventInfo& eventInfo);
    HookList<AuraProcHandler> OnProc;
    // executed after aura proced
    // example: AfterProc += AuraProcFn(class::function);
    // where function is: void function(ProcEventInfo& eventInfo);
    HookList<AuraProcHandler> AfterProc;
    #define AuraProcFn(F) AuraProcHandler(&F)

    // executed when aura effect procs
    // example: OnEffectProc += AuraEffectProcFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function(AuraEffect* aurEff, ProcEventInfo& procInfo);
    HookList<EffectProcHandler> OnEffectProc;
    // executed after aura effect proced
    // example: AfterEffectProc += AuraEffectProcFn(class::function, EffectIndexSpecifier, EffectAuraNameSpecifier);
    // where function is: void function(AuraEffect* aurEff, ProcEventInfo& procInfo);
    HookList<EffectProcHandler> AfterEffectProc;
    #define AuraEffectProcFn(F, I, N) EffectProcHandler(&F, I, N)

    // executed when target enters or leaves combat
    // example: OnEnterLeaveCombat += AuraEnterLeaveCombatFn(class::function)
    // where function is: void function (bool isNowInCombat);
    HookList<EnterLeaveCombatHandler> OnEnterLeaveCombat;
    #define AuraEnterLeaveCombatFn(F) EnterLeaveCombatHandler(&F)

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
