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

#include "ScriptMgr.h"
#include "AchievementMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ChatCommand.h"
#include "Conversation.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "CreatureAISelector.h"
#include "DB2Stores.h"
#include "Errors.h"
#include "GameObject.h"
#include "GossipDef.h"
#include "InstanceScript.h"
#include "Item.h"
#include "LFGScripts.h"
#include "Log.h"
#include "Map.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "OutdoorPvPMgr.h"
#include "Player.h"
#include "ScriptReloadMgr.h"
#include "ScriptSystem.h"
#include "SmartAI.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Timer.h"
#include "Transport.h"
#include "Vehicle.h"
#include "Weather.h"
#include "WorldPacket.h"
#include <unordered_map>

// Trait which indicates whether this script type
// must be assigned in the database.
template<typename>
struct is_script_database_bound
    : std::false_type { };

template<>
struct is_script_database_bound<SpellScriptLoader>
    : std::true_type { };

template<>
struct is_script_database_bound<InstanceMapScript>
    : std::true_type { };

template<>
struct is_script_database_bound<ItemScript>
    : std::true_type { };

template<>
struct is_script_database_bound<CreatureScript>
    : std::true_type { };

template<>
struct is_script_database_bound<GameObjectScript>
    : std::true_type { };

template<>
struct is_script_database_bound<VehicleScript>
    : std::true_type { };

template<>
struct is_script_database_bound<AreaTriggerScript>
    : std::true_type { };

template<>
struct is_script_database_bound<BattlefieldScript>
    : std::true_type { };

template<>
struct is_script_database_bound<BattlegroundMapScript>
    : std::true_type { };

template<>
struct is_script_database_bound<OutdoorPvPScript>
    : std::true_type { };

template<>
struct is_script_database_bound<WeatherScript>
    : std::true_type { };

template<>
struct is_script_database_bound<ConditionScript>
    : std::true_type { };

template<>
struct is_script_database_bound<TransportScript>
    : std::true_type { };

template<>
struct is_script_database_bound<AchievementScript>
    : std::true_type { };

template<>
struct is_script_database_bound<AchievementCriteriaScript>
    : std::true_type { };

template<>
struct is_script_database_bound<AreaTriggerEntityScript>
    : std::true_type { };

template<>
struct is_script_database_bound<ConversationScript>
    : std::true_type { };

template<>
struct is_script_database_bound<SceneScript>
    : std::true_type { };

template<>
struct is_script_database_bound<QuestScript>
    : std::true_type { };

template<>
struct is_script_database_bound<WorldStateScript>
    : std::true_type { };

template<>
struct is_script_database_bound<EventScript>
    : std::true_type { };

enum Spells
{
    SPELL_HOTSWAP_VISUAL_SPELL_EFFECT = 40162 // 59084
};

class ScriptRegistryInterface
{
public:
    ScriptRegistryInterface() { }
    virtual ~ScriptRegistryInterface() { }

    ScriptRegistryInterface(ScriptRegistryInterface const&) = delete;
    ScriptRegistryInterface(ScriptRegistryInterface&&) = delete;

    ScriptRegistryInterface& operator= (ScriptRegistryInterface const&) = delete;
    ScriptRegistryInterface& operator= (ScriptRegistryInterface&&) = delete;

    /// Removes all scripts associated with the given script context.
    /// Requires ScriptRegistryBase::SwapContext to be called after all transfers have finished.
    virtual void ReleaseContext(std::string const& context) = 0;

    /// Injects and updates the changed script objects.
    virtual void SwapContext(bool initialize) = 0;

    /// Removes the scripts used by this registry from the given container.
    /// Used to find unused script names.
    virtual void RemoveUsedScriptsFromContainer(std::unordered_set<std::string>& scripts) = 0;

    /// Unloads the script registry.
    virtual void Unload() = 0;

    /// Updates the scripts to reflect the current id
    virtual void SyncScriptNames() = 0;
};

template<class>
class ScriptRegistry;

class ScriptRegistryCompositum
    : public ScriptRegistryInterface
{
    ScriptRegistryCompositum() { }

    template<class>
    friend class ScriptRegistry;

    /// Type erasure wrapper for objects
    class DeleteableObjectBase
    {
    public:
        DeleteableObjectBase() { }
        virtual ~DeleteableObjectBase() { }

        DeleteableObjectBase(DeleteableObjectBase const&) = delete;
        DeleteableObjectBase& operator= (DeleteableObjectBase const&) = delete;
    };

    template<typename T>
    class DeleteableObject
        : public DeleteableObjectBase
    {
    public:
        DeleteableObject(T&& object)
            : _object(std::forward<T>(object)) { }

    private:
        T _object;
    };

public:
    void SetScriptNameInContext(std::string const& scriptname, std::string const& context)
    {
        ASSERT(_scriptnames_to_context.find(scriptname) == _scriptnames_to_context.end(),
               "Scriptname was assigned to this context already!");
        _scriptnames_to_context.insert(std::make_pair(scriptname, context));
    }

    std::string const& GetScriptContextOfScriptName(std::string const& scriptname) const
    {
        auto itr = _scriptnames_to_context.find(scriptname);
        ASSERT(itr != _scriptnames_to_context.end() &&
               "Given scriptname doesn't exist!");
        return itr->second;
    }

    void ReleaseContext(std::string const& context) final override
    {
        for (auto const registry : _registries)
            registry->ReleaseContext(context);

        // Clear the script names in context after calling the release hooks
        // since it's possible that new references to a shared library
        // are acquired when releasing.
        for (auto itr = _scriptnames_to_context.begin();
                        itr != _scriptnames_to_context.end();)
            if (itr->second == context)
                itr = _scriptnames_to_context.erase(itr);
            else
                ++itr;
    }

    void SwapContext(bool initialize) final override
    {
        for (auto const registry : _registries)
            registry->SwapContext(initialize);

        DoDelayedDelete();
    }

    void RemoveUsedScriptsFromContainer(std::unordered_set<std::string>& scripts) final override
    {
        for (auto const registry : _registries)
            registry->RemoveUsedScriptsFromContainer(scripts);
    }

    void Unload() final override
    {
        for (auto const registry : _registries)
            registry->Unload();
    }

    void SyncScriptNames() final override
    {
        for (auto const registry : _registries)
            registry->SyncScriptNames();
    }

    template<typename T>
    void QueueForDelayedDelete(T&& any)
    {
        _delayed_delete_queue.push_back(
    std::make_unique<
                DeleteableObject<typename std::decay<T>::type>
            >(std::forward<T>(any))
        );
    }

    static ScriptRegistryCompositum* Instance()
    {
        static ScriptRegistryCompositum instance;
        return &instance;
    }

private:
    void Register(ScriptRegistryInterface* registry)
    {
        _registries.insert(registry);
    }

    void DoDelayedDelete()
    {
        _delayed_delete_queue.clear();
    }

    std::unordered_set<ScriptRegistryInterface*> _registries;

    std::vector<std::unique_ptr<DeleteableObjectBase>> _delayed_delete_queue;

    std::unordered_map<
        std::string /*script name*/,
        std::string /*context*/
    > _scriptnames_to_context;
};

#define sScriptRegistryCompositum ScriptRegistryCompositum::Instance()

template<typename /*ScriptType*/, bool /*IsDatabaseBound*/>
class SpecializedScriptRegistry;

// This is the global static registry of scripts.
template<class ScriptType>
class ScriptRegistry final
    : public SpecializedScriptRegistry<
        ScriptType, is_script_database_bound<ScriptType>::value>
{
    ScriptRegistry()
    {
        sScriptRegistryCompositum->Register(this);
    }

public:
    static ScriptRegistry* Instance()
    {
        static ScriptRegistry instance;
        return &instance;
    }

    void LogDuplicatedScriptPointerError(ScriptType const* first, ScriptType const* second)
    {
        // See if the script is using the same memory as another script. If this happens, it means that
        // someone forgot to allocate new memory for a script.
        TC_LOG_ERROR("scripts", "Script '{}' has same memory pointer as '{}'.",
            first->GetName(), second->GetName());
    }
};

class ScriptRegistrySwapHookBase
{
public:
    ScriptRegistrySwapHookBase() { }
    virtual ~ScriptRegistrySwapHookBase() { }

    ScriptRegistrySwapHookBase(ScriptRegistrySwapHookBase const&) = delete;
    ScriptRegistrySwapHookBase(ScriptRegistrySwapHookBase&&) = delete;

    ScriptRegistrySwapHookBase& operator= (ScriptRegistrySwapHookBase const&) = delete;
    ScriptRegistrySwapHookBase& operator= (ScriptRegistrySwapHookBase&&) = delete;

    /// Called before the actual context release happens
    virtual void BeforeReleaseContext(std::string const& /*context*/) { }

    /// Called before SwapContext
    virtual void BeforeSwapContext(bool /*initialize*/) { }

    /// Called before Unload
    virtual void BeforeUnload() { }

    /// Called manually to sync scriptnames
    virtual void OnScriptNamesSync() { };
};

template<typename ScriptType, typename Base>
class ScriptRegistrySwapHooks
    : public ScriptRegistrySwapHookBase
{
};

template<typename Base>
class UnsupportedScriptRegistrySwapHooks
    : public ScriptRegistrySwapHookBase
{
public:
    void BeforeReleaseContext(std::string const& context) final override
    {
        auto const bounds = static_cast<Base*>(this)->_ids_of_contexts.equal_range(context);
        ASSERT(bounds.first == bounds.second);
    }
};

/// This hook is responsible for swapping Creature, GameObject and AreaTrigger AI's
template<typename ObjectType, typename ScriptType, typename Base>
class CreatureGameObjectAreaTriggerScriptRegistrySwapHooks
    : public ScriptRegistrySwapHookBase
{
    template<typename W>
    class AIFunctionMapWorker
    {
    public:
        template<typename T>
        AIFunctionMapWorker(T&& worker)
            : _worker(std::forward<T>(worker)) { }

        void Visit(std::unordered_map<ObjectGuid, ObjectType*>& objects)
        {
            _worker(objects);
        }

        template<typename O>
        void Visit(std::unordered_map<ObjectGuid, O*>&) { }

    private:
        W _worker;
    };

    class AsyncCastHotswapEffectEvent : public BasicEvent
    {
    public:
        explicit AsyncCastHotswapEffectEvent(Unit* owner) : owner_(owner) { }

        bool Execute(uint64 /*e_time*/, uint32 /*p_time*/) override
        {
            owner_->CastSpell(owner_, SPELL_HOTSWAP_VISUAL_SPELL_EFFECT, true);
            return true;
        }

    private:
        Unit* owner_;
    };

    // Hook which is called before a creature is swapped
    static void UnloadResetScript(Creature* creature)
    {
        // Remove deletable events only,
        // otherwise it causes crashes with non-deletable spell events.
        creature->m_Events.KillAllEvents(false);

        if (creature->IsCharmed())
            creature->RemoveCharmedBy(nullptr);

        ASSERT(!creature->IsCharmed(),
               "There is a disabled AI which is still loaded.");

        if (creature->IsAlive())
            creature->AI()->EnterEvadeMode();
    }

    static void UnloadDestroyScript(Creature* creature)
    {
        bool const destroyed = creature->AIM_Destroy();
        ASSERT(destroyed,
               "Destroying the AI should never fail here!");
        (void)destroyed;

        ASSERT(!creature->AI(),
               "The AI should be null here!");
    }

    // Hook which is called before a gameobject is swapped
    static void UnloadResetScript(GameObject* gameobject)
    {
        // Remove deletable events only,
        // otherwise it causes crashes with non-deletable spell events.
        gameobject->m_Events.KillAllEvents(false);

        gameobject->AI()->Reset();
    }

    static void UnloadDestroyScript(GameObject* gameobject)
    {
        gameobject->AIM_Destroy();

        ASSERT(!gameobject->AI(),
               "The AI should be null here!");
    }

    // Hook which is called before a areatrigger is swapped
    static void UnloadResetScript(AreaTrigger* at)
    {
        // Remove deletable events only,
        // otherwise it causes crashes with non-deletable spell events.
        at->m_Events.KillAllEvents(false);

        at->AI()->OnRemove();
    }

    static void UnloadDestroyScript(AreaTrigger* at)
    {
        at->AI_Destroy();

        ASSERT(!at->AI(),
            "The AI should be null here!");
    }

    // Hook which is called after a creature was swapped
    static void LoadInitializeScript(Creature* creature)
    {
        ASSERT(!creature->AI(),
               "The AI should be null here!");

        if (creature->IsAlive())
            creature->ClearUnitState(UNIT_STATE_EVADE);

        bool const created = creature->AIM_Create();
        ASSERT(created,
               "Creating the AI should never fail here!");
        (void)created;
    }

    static void LoadResetScript(Creature* creature)
    {
        if (!creature->IsAlive())
            return;

        creature->AI()->InitializeAI();
        if (creature->GetVehicleKit())
            creature->GetVehicleKit()->Reset();
        creature->AI()->EnterEvadeMode();

        // Cast a dummy visual spell asynchronously here to signal
        // that the AI was hot swapped
        creature->m_Events.AddEvent(new AsyncCastHotswapEffectEvent(creature),
            creature->m_Events.CalculateTime(0s));
    }

    // Hook which is called after a gameobject was swapped
    static void LoadInitializeScript(GameObject* gameobject)
    {
        ASSERT(!gameobject->AI(),
               "The AI should be null here!");

        gameobject->AIM_Initialize();
    }

    static void LoadResetScript(GameObject* gameobject)
    {
        gameobject->AI()->Reset();
    }

    // Hook which is called after a areatrigger was swapped
    static void LoadInitializeScript(AreaTrigger* at)
    {
        ASSERT(!at->AI(),
            "The AI should be null here!");

        at->AI_Initialize();
    }

    static void LoadResetScript(AreaTrigger* at)
    {
        at->AI()->OnCreate(nullptr);
    }

    static Creature* GetEntityFromMap(std::common_type<Creature>, Map* map, ObjectGuid const& guid)
    {
        return map->GetCreature(guid);
    }

    static GameObject* GetEntityFromMap(std::common_type<GameObject>, Map* map, ObjectGuid const& guid)
    {
        return map->GetGameObject(guid);
    }

    static AreaTrigger* GetEntityFromMap(std::common_type<AreaTrigger>, Map* map, ObjectGuid const& guid)
    {
        return map->GetAreaTrigger(guid);
    }

    static auto VisitObjectsToSwapOnMap(std::unordered_set<uint32> const& idsToRemove)
    {
        return [&idsToRemove](Map* map, auto&& visitor)
        {
            auto evaluator = [&](std::unordered_map<ObjectGuid, ObjectType*>& objects)
            {
                for (auto object : objects)
                {
                    // When the script Id of the script isn't removed in this
                    // context change, do nothing.
                    uint32 aiId = object.second->AI() ? object.second->AI()->GetId() : 0;
                    if (idsToRemove.find(aiId) != idsToRemove.end() || (aiId == 0 && object.second->GetScriptId()))
                        visitor(object.second);
                }
            };

            AIFunctionMapWorker<typename std::decay<decltype(evaluator)>::type> worker(std::move(evaluator));
            TypeContainerVisitor<decltype(worker), MapStoredObjectTypesContainer> containerVisitor(worker);

            containerVisitor.Visit(map->GetObjectsStore());
        };
    }

    static auto VisitObjectsWhereIdWasUpdated()
    {
        return [](Map* map, auto&& visitor)
        {
            auto evaluator = [&](std::unordered_map<ObjectGuid, ObjectType*>& objects)
            {
                for (auto object : objects)
                {
                    if (object.second->AI())
                    {
                        ASSERT(object.second->AI()->GetId());

                        uint32 aiId = object.second->AI()->GetId();
                        uint32 scriptId = FactorySelector::GetSelectedAIId(object.second);

                        ASSERT(scriptId);

                        if (aiId == scriptId)
                        {
                            // Skip if the ai id matches
                            continue;
                        }

                        if (!sObjectMgr->IsScriptDatabaseBound(scriptId)
                            && !sObjectMgr->IsScriptDatabaseBound(aiId))
                        {
                            // Skip if we are dealing with two selectable AI scripts
                            continue;
                        }

                        visitor(object.second);
                    }
                    else
                        visitor(object.second);
                }
            };

            AIFunctionMapWorker<typename std::decay<decltype(evaluator)>::type> worker(std::move(evaluator));
            TypeContainerVisitor<decltype(worker), MapStoredObjectTypesContainer> containerVisitor(worker);

            containerVisitor.Visit(map->GetObjectsStore());
        };
    }

    template<typename T>
    static void DestroyScriptIdsWithVisitor(T&& visitor)
    {
        // First reset all swapped scripts safe by guid
        sMapMgr->DoForAllMaps([&](Map* map)
        {
            std::vector<ObjectGuid> guidsToReset;

            visitor(map, [&](ObjectType* object)
            {
                if (object->AI())
                    guidsToReset.push_back(object->GetGUID());
            });

            for (ObjectGuid const& guid : guidsToReset)
            {
                if (auto entity = GetEntityFromMap(std::common_type<ObjectType>{}, map, guid))
                    UnloadResetScript(entity);
            }

            visitor(map, [&](ObjectType* object)
            {
                // Destroy the scripts instantly
                UnloadDestroyScript(object);
            });
        });
    }

    template<typename T>
    static void InitializeScriptIdsWithVisitor(T&& visitor)
    {
        sMapMgr->DoForAllMaps([&](Map* map)
        {
            std::vector<ObjectGuid> guidsToReset;

            visitor(map, [&](ObjectType* object)
            {
                if (!object->AI())
                {
                    // Initialize the script
                    LoadInitializeScript(object);
                    guidsToReset.push_back(object->GetGUID());
                }
            });

            for (ObjectGuid const& guid : guidsToReset)
            {
                // Reset the script
                if (auto entity = GetEntityFromMap(std::common_type<ObjectType>{}, map, guid))
                {
                    if (!entity->AI())
                        LoadInitializeScript(entity);

                    LoadResetScript(entity);
                }
            }
        });
    }

public:
    void BeforeReleaseContext(std::string const& context) final override
    {
        auto idsToRemove = static_cast<Base*>(this)->GetScriptIDsToRemove(context);
        DestroyScriptIdsWithVisitor(VisitObjectsToSwapOnMap(idsToRemove));

        // Add the new ids which are removed to the global ids to remove set
        ids_removed_.insert(idsToRemove.begin(), idsToRemove.end());
    }

    void BeforeSwapContext(bool initialize) override
    {
        // Never swap creature or gameobject scripts when initializing
        if (initialize)
            return;

        // Add the recently added scripts to the deleted scripts to replace
        // default AI's with recently added core scripts.
        ids_removed_.insert(static_cast<Base*>(this)->GetRecentlyAddedScriptIDs().begin(),
                            static_cast<Base*>(this)->GetRecentlyAddedScriptIDs().end());

        auto const visitor = VisitObjectsToSwapOnMap(ids_removed_);
        DestroyScriptIdsWithVisitor(visitor);
        InitializeScriptIdsWithVisitor(visitor);

        ids_removed_.clear();
    }

    void BeforeUnload() final override
    {
        ASSERT(ids_removed_.empty());
    }

    void OnScriptNamesSync() final override
    {
        auto const visitor = VisitObjectsWhereIdWasUpdated();
        DestroyScriptIdsWithVisitor(visitor);
        InitializeScriptIdsWithVisitor(visitor);
    }

private:
    std::unordered_set<uint32> ids_removed_;
};

// This hook is responsible for swapping CreatureAI's
template<typename Base>
class ScriptRegistrySwapHooks<CreatureScript, Base>
    : public CreatureGameObjectAreaTriggerScriptRegistrySwapHooks<
        Creature, CreatureScript, Base
      > { };

// This hook is responsible for swapping GameObjectAI's
template<typename Base>
class ScriptRegistrySwapHooks<GameObjectScript, Base>
    : public CreatureGameObjectAreaTriggerScriptRegistrySwapHooks<
        GameObject, GameObjectScript, Base
      > { };

// This hook is responsible for swapping AreaTriggerAI's
template<typename Base>
class ScriptRegistrySwapHooks<AreaTriggerEntityScript, Base>
    : public CreatureGameObjectAreaTriggerScriptRegistrySwapHooks<
    AreaTrigger, AreaTriggerEntityScript, Base
    > { };

/// This hook is responsible for swapping BattlefieldScripts
template<typename Base>
class ScriptRegistrySwapHooks<BattlefieldScript, Base>
        : public UnsupportedScriptRegistrySwapHooks<Base> { };

/// This hook is responsible for swapping OutdoorPvP's
template<typename Base>
class ScriptRegistrySwapHooks<OutdoorPvPScript, Base>
    : public ScriptRegistrySwapHookBase
{
public:
    ScriptRegistrySwapHooks() : swapped(false) { }

    void BeforeReleaseContext(std::string const& context) final override
    {
        auto const bounds = static_cast<Base*>(this)->_ids_of_contexts.equal_range(context);

        if ((!swapped) && (bounds.first != bounds.second))
        {
            swapped = true;
            sOutdoorPvPMgr->Die();
        }
    }

    void BeforeSwapContext(bool initialize) override
    {
        // Never swap outdoor pvp scripts when initializing
        if ((!initialize) && swapped)
        {
            sOutdoorPvPMgr->InitOutdoorPvP();
            swapped = false;
        }
    }

    void BeforeUnload() final override
    {
        ASSERT(!swapped);
    }

private:
    bool swapped;
};

/// This hook is responsible for swapping InstanceMapScript's
template<typename Base>
class ScriptRegistrySwapHooks<InstanceMapScript, Base>
    : public ScriptRegistrySwapHookBase
{
public:
    ScriptRegistrySwapHooks()  : swapped(false) { }

    void BeforeReleaseContext(std::string const& context) final override
    {
        auto const bounds = static_cast<Base*>(this)->_ids_of_contexts.equal_range(context);
        if (bounds.first != bounds.second)
            swapped = true;
    }

    void BeforeSwapContext(bool /*initialize*/) override
    {
        swapped = false;
    }

    void BeforeUnload() final override
    {
        ASSERT(!swapped);
    }

private:
    bool swapped;
};

/// This hook is responsible for swapping BattlegroundMapScript's
template<typename Base>
class ScriptRegistrySwapHooks<BattlegroundMapScript, Base>
    : public ScriptRegistrySwapHookBase
{
public:
    ScriptRegistrySwapHooks() : swapped(false) { }

    void BeforeReleaseContext(std::string const& context) final override
    {
        auto const bounds = static_cast<Base*>(this)->_ids_of_contexts.equal_range(context);
        if (bounds.first != bounds.second)
            swapped = true;
    }

    void BeforeSwapContext(bool /*initialize*/) override
    {
        swapped = false;
    }

    void BeforeUnload() final override
    {
        ASSERT(!swapped);
    }

private:
    bool swapped;
};

/// This hook is responsible for swapping SceneScript's
template<typename Base>
class ScriptRegistrySwapHooks<SceneScript, Base>
    : public ScriptRegistrySwapHookBase
{
public:
    ScriptRegistrySwapHooks() : swapped(false) { }

    void BeforeReleaseContext(std::string const& context) final override
    {
        auto const bounds = static_cast<Base*>(this)->_ids_of_contexts.equal_range(context);
        if (bounds.first != bounds.second)
            swapped = true;
    }

    void BeforeSwapContext(bool /*initialize*/) override
    {
        swapped = false;
    }

    void BeforeUnload() final override
    {
        ASSERT(!swapped);
    }

private:
    bool swapped;
};

/// This hook is responsible for swapping QuestScript's
template<typename Base>
class ScriptRegistrySwapHooks<QuestScript, Base>
    : public ScriptRegistrySwapHookBase
{
public:
    ScriptRegistrySwapHooks() : swapped(false) { }

    void BeforeReleaseContext(std::string const& context) final override
    {
        auto const bounds = static_cast<Base*>(this)->_ids_of_contexts.equal_range(context);
        if (bounds.first != bounds.second)
            swapped = true;
    }

    void BeforeSwapContext(bool /*initialize*/) override
    {
        swapped = false;
    }

    void BeforeUnload() final override
    {
        ASSERT(!swapped);
    }

private:
    bool swapped;
};

/// This hook is responsible for swapping SpellScriptLoader's
template<typename Base>
class ScriptRegistrySwapHooks<SpellScriptLoader, Base>
    : public ScriptRegistrySwapHookBase
{
public:
    ScriptRegistrySwapHooks() : swapped(false) { }

    void BeforeReleaseContext(std::string const& context) final override
    {
        auto const bounds = static_cast<Base*>(this)->_ids_of_contexts.equal_range(context);

        if (bounds.first != bounds.second)
            swapped = true;
    }

    void BeforeSwapContext(bool /*initialize*/) override
    {
        if (swapped)
        {
            sObjectMgr->ValidateSpellScripts();
            swapped = false;
        }
    }

    void BeforeUnload() final override
    {
        ASSERT(!swapped);
    }

private:
    bool swapped;
};

// Database bound script registry
template<typename ScriptType>
class SpecializedScriptRegistry<ScriptType, true>
    : public ScriptRegistryInterface,
      public ScriptRegistrySwapHooks<ScriptType, ScriptRegistry<ScriptType>>
{
    template<typename>
    friend class UnsupportedScriptRegistrySwapHooks;

    template<typename, typename>
    friend class ScriptRegistrySwapHooks;

    template<typename, typename, typename>
    friend class CreatureGameObjectAreaTriggerScriptRegistrySwapHooks;

public:
    SpecializedScriptRegistry() { }

    typedef std::unordered_map<
        uint32 /*script id*/,
        std::unique_ptr<ScriptType>
    > ScriptStoreType;

    typedef typename ScriptStoreType::iterator ScriptStoreIteratorType;

    void ReleaseContext(std::string const& context) final override
    {
        this->BeforeReleaseContext(context);

        auto const bounds = _ids_of_contexts.equal_range(context);
        for (auto itr = bounds.first; itr != bounds.second; ++itr)
            _scripts.erase(itr->second);
    }

    void SwapContext(bool initialize) final override
    {
      this->BeforeSwapContext(initialize);

      _recently_added_ids.clear();
    }

    void RemoveUsedScriptsFromContainer(std::unordered_set<std::string>& scripts) final override
    {
        for (auto const& script : _scripts)
            scripts.erase(script.second->GetName());
    }

    void Unload() final override
    {
        this->BeforeUnload();

        ASSERT(_recently_added_ids.empty(),
               "Recently added script ids should be empty here!");

        _scripts.clear();
        _ids_of_contexts.clear();
    }

    void SyncScriptNames() final override
    {
        this->OnScriptNamesSync();
    }

    // Adds a database bound script
    void AddScript(ScriptType* script)
    {
        ASSERT(script,
               "Tried to call AddScript with a nullpointer!");
        ASSERT(!sScriptMgr->GetCurrentScriptContext().empty(),
               "Tried to register a script without being in a valid script context!");

        std::unique_ptr<ScriptType> script_ptr(script);

        // Get an ID for the script.
        uint32 const id = sObjectMgr->GetScriptId(script->GetName());

        // Try to find an existing script.
        for (auto const& stored_script : _scripts)
        {
            // If the script names match...
            if (stored_script.second->GetName() == script->GetName())
            {
                // If the script is already assigned -> delete it!
                ABORT_MSG("Script '%s' already assigned with the same script name, "
                    "so the script can't work.", script->GetName().c_str());

                // Error that should be fixed ASAP.
                sScriptRegistryCompositum->QueueForDelayedDelete(std::move(script_ptr));
                ABORT();
                return;
            }
        }

        // If the script isn't assigned -> assign it!
        _scripts.insert(std::make_pair(id, std::move(script_ptr)));
        _ids_of_contexts.insert(std::make_pair(sScriptMgr->GetCurrentScriptContext(), id));
        _recently_added_ids.insert(id);

        sScriptRegistryCompositum->SetScriptNameInContext(script->GetName(),
            sScriptMgr->GetCurrentScriptContext());
    }

    // Gets a script by its ID (assigned by ObjectMgr).
    ScriptType* GetScriptById(uint32 id)
    {
        auto const itr = _scripts.find(id);
        if (itr != _scripts.end())
            return itr->second.get();

        return nullptr;
    }

    ScriptStoreType& GetScripts()
    {
        return _scripts;
    }

protected:
    // Returns the script id's which are registered to a certain context
    std::unordered_set<uint32> GetScriptIDsToRemove(std::string const& context) const
    {
        // Create a set of all ids which are removed
        std::unordered_set<uint32> scripts_to_remove;

        auto const bounds = _ids_of_contexts.equal_range(context);
        for (auto itr = bounds.first; itr != bounds.second; ++itr)
            scripts_to_remove.insert(itr->second);

        return scripts_to_remove;
    }

    std::unordered_set<uint32> const& GetRecentlyAddedScriptIDs() const
    {
        return _recently_added_ids;
    }

private:
    ScriptStoreType _scripts;

    // Scripts of a specific context
    std::unordered_multimap<std::string /*context*/, uint32 /*id*/> _ids_of_contexts;

    // Script id's which were registered recently
    std::unordered_set<uint32> _recently_added_ids;
};

/// This hook is responsible for swapping CommandScript's
template<typename Base>
class ScriptRegistrySwapHooks<CommandScript, Base>
    : public ScriptRegistrySwapHookBase
{
public:
    void BeforeReleaseContext(std::string const& /*context*/) final override
    {
        Trinity::ChatCommands::InvalidateCommandMap();
    }

    void BeforeSwapContext(bool /*initialize*/) override
    {
        Trinity::ChatCommands::InvalidateCommandMap();
    }

    void BeforeUnload() final override
    {
        Trinity::ChatCommands::InvalidateCommandMap();
    }
};

// Database unbound script registry
template<typename ScriptType>
class SpecializedScriptRegistry<ScriptType, false>
    : public ScriptRegistryInterface,
      public ScriptRegistrySwapHooks<ScriptType, ScriptRegistry<ScriptType>>
{
    template<typename, typename>
    friend class ScriptRegistrySwapHooks;

public:
    typedef std::unordered_multimap<std::string /*context*/, std::unique_ptr<ScriptType>> ScriptStoreType;
    typedef typename ScriptStoreType::iterator ScriptStoreIteratorType;

    SpecializedScriptRegistry() { }

    void ReleaseContext(std::string const& context) final override
    {
        this->BeforeReleaseContext(context);

        _scripts.erase(context);
    }

    void SwapContext(bool initialize) final override
    {
        this->BeforeSwapContext(initialize);
    }

    void RemoveUsedScriptsFromContainer(std::unordered_set<std::string>& scripts) final override
    {
        for (auto const& script : _scripts)
            scripts.erase(script.second->GetName());
    }

    void Unload() final override
    {
        this->BeforeUnload();

        _scripts.clear();
    }

    void SyncScriptNames() final override
    {
    }

    // Adds a non database bound script
    void AddScript(ScriptType* script)
    {
        ASSERT(script,
               "Tried to call AddScript with a nullpointer!");
        ASSERT(!sScriptMgr->GetCurrentScriptContext().empty(),
               "Tried to register a script without being in a valid script context!");

        std::unique_ptr<ScriptType> script_ptr(script);

        for (auto const& entry : _scripts)
            if (entry.second.get() == script)
            {
                static_cast<ScriptRegistry<ScriptType>*>(this)->
                    LogDuplicatedScriptPointerError(script, entry.second.get());

                sScriptRegistryCompositum->QueueForDelayedDelete(std::move(script_ptr));
                return;
            }

        // We're dealing with a code-only script, just add it.
        _scripts.insert(std::make_pair(sScriptMgr->GetCurrentScriptContext(), std::move(script_ptr)));
    }

    ScriptStoreType& GetScripts()
    {
        return _scripts;
    }

private:
    ScriptStoreType _scripts;
};

// Utility macros to refer to the script registry.
#define SCR_REG_MAP(T) ScriptRegistry<T>::ScriptStoreType
#define SCR_REG_ITR(T) ScriptRegistry<T>::ScriptStoreIteratorType
#define SCR_REG_LST(T) ScriptRegistry<T>::Instance()->GetScripts()

// Utility macros for looping over scripts.
#define FOR_SCRIPTS(T, C, E) \
    if (!SCR_REG_LST(T).empty()) \
        for (SCR_REG_ITR(T) C = SCR_REG_LST(T).begin(); \
            C != SCR_REG_LST(T).end(); ++C)

#define FOR_SCRIPTS_RET(T, C, E, R) \
    if (SCR_REG_LST(T).empty()) \
        return R; \
    \
    for (SCR_REG_ITR(T) C = SCR_REG_LST(T).begin(); \
        C != SCR_REG_LST(T).end(); ++C)

#define FOREACH_SCRIPT(T) \
    FOR_SCRIPTS(T, itr, end) \
        itr->second

// Utility macros for finding specific scripts.
#define GET_SCRIPT(T, I, V) \
    T* V = ScriptRegistry<T>::Instance()->GetScriptById(I); \
    if (!V) \
        return;

#define GET_SCRIPT_RET(T, I, V, R) \
    T* V = ScriptRegistry<T>::Instance()->GetScriptById(I); \
    if (!V) \
        return R;

ScriptObject::ScriptObject(char const* name) : _name(name)
{
    sScriptMgr->IncreaseScriptCount();
}

ScriptObject::~ScriptObject()
{
    sScriptMgr->DecreaseScriptCount();
}

std::string const& ScriptObject::GetName() const
{
    return _name;
}

ScriptMgr::ScriptMgr()
    : _scriptCount(0), _scriptIdUpdated(false), _script_loader_callback(nullptr)
{
}

ScriptMgr::~ScriptMgr() = default;

ScriptMgr* ScriptMgr::instance()
{
    static ScriptMgr instance;
    return &instance;
}

void ScriptMgr::Initialize()
{
    ASSERT(sSpellMgr->GetSpellInfo(SPELL_HOTSWAP_VISUAL_SPELL_EFFECT, DIFFICULTY_NONE)
           && "Reload hotswap spell effect for creatures isn't valid!");

    uint32 oldMSTime = getMSTime();

    LoadDatabase();

    TC_LOG_INFO("server.loading", "Loading C++ scripts");

    FillSpellSummary();

    // Load core scripts
    SetScriptContext(GetNameOfStaticContext());

    // SmartAI
    AddSC_SmartScripts();

    // LFGScripts
    lfg::AddSC_LFGScripts();

    // MapScripts
    sMapMgr->AddSC_BuiltInScripts();

    // Load all static linked scripts through the script loader function.
    ASSERT(_script_loader_callback,
           "Script loader callback wasn't registered!");
    _script_loader_callback();

    // Initialize all dynamic scripts
    // and finishes the context switch to do
    // bulk loading
    sScriptReloadMgr->Initialize();

    // Loads all scripts from the current context
    sScriptMgr->SwapScriptContext(true);

    // Print unused script names.
    std::unordered_set<std::string> unusedScriptNames = sObjectMgr->GetAllDBScriptNames();

    // Remove the used scripts from the given container.
    sScriptRegistryCompositum->RemoveUsedScriptsFromContainer(unusedScriptNames);

    for (std::string const& scriptName : unusedScriptNames)
    {
        // Avoid complaining about empty script names since the
        // script name container contains a placeholder as the 0 element.
        if (scriptName.empty())
            continue;

        TC_LOG_ERROR("sql.sql", "Script '{}' is referenced by the database, but does not exist in the core!", scriptName);
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} C++ scripts in {} ms",
        GetScriptCount(), GetMSTimeDiffToNow(oldMSTime));
}

void ScriptMgr::NotifyScriptIDUpdate()
{
    _scriptIdUpdated = true;
}

void ScriptMgr::SyncScripts()
{
    if (_scriptIdUpdated)
    {
        _scriptIdUpdated = false;
        sScriptRegistryCompositum->SyncScriptNames();
    }
}

void ScriptMgr::SetScriptContext(std::string const& context)
{
    _currentContext = context;
}

void ScriptMgr::SwapScriptContext(bool initialize)
{
    sScriptRegistryCompositum->SwapContext(initialize);
    _currentContext.clear();
}

std::string const& ScriptMgr::GetNameOfStaticContext()
{
    static std::string const name = "___static___";
    return name;
}

void ScriptMgr::ReleaseScriptContext(std::string const& context)
{
    sScriptRegistryCompositum->ReleaseContext(context);
}

std::shared_ptr<ModuleReference>
    ScriptMgr::AcquireModuleReferenceOfScriptName(std::string const& scriptname) const
{
#ifdef TRINITY_API_USE_DYNAMIC_LINKING
    // Returns the reference to the module of the given scriptname
    return ScriptReloadMgr::AcquireModuleReferenceOfContext(
        sScriptRegistryCompositum->GetScriptContextOfScriptName(scriptname));
#else
    (void)scriptname;
    // Something went wrong when this function is used in
    // a static linked context.
    WPAbort();
#endif // #ifndef TRINITY_API_USE_DYNAMIC_LINKING
}

void ScriptMgr::Unload()
{
    sScriptRegistryCompositum->Unload();

    UnitAI::AISpellInfo.clear();
}

void ScriptMgr::LoadDatabase()
{
    sScriptSystemMgr->LoadScriptSplineChains();
}

void ScriptMgr::FillSpellSummary()
{
    UnitAI::FillAISpellInfo();
}

template<typename T, typename O>
void CreateSpellOrAuraScripts(uint32 spellId, std::vector<T*>& scriptVector, T*(SpellScriptLoader::*extractor)() const, O* objectInvoker)
{
    SpellScriptsBounds bounds = sObjectMgr->GetSpellScriptsBounds(spellId);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
    {
        // When the script is disabled continue with the next one
        if (!itr->second.second)
            continue;

        SpellScriptLoader* tmpscript = sScriptMgr->GetSpellScriptLoader(itr->second.first);
        if (!tmpscript)
            continue;

        T* script = (tmpscript->*extractor)();
        if (!script)
            continue;

        script->_Init(tmpscript->GetName(), spellId);
        if (!script->_Load(objectInvoker))
        {
            delete script;
            continue;
        }

        scriptVector.push_back(script);
    }
}

void ScriptMgr::CreateSpellScripts(uint32 spellId, std::vector<SpellScript*>& scriptVector, Spell* invoker) const
{
    CreateSpellOrAuraScripts(spellId, scriptVector, &SpellScriptLoader::GetSpellScript, invoker);
}

void ScriptMgr::CreateAuraScripts(uint32 spellId, std::vector<AuraScript*>& scriptVector, Aura* invoker) const
{
    CreateSpellOrAuraScripts(spellId, scriptVector, &SpellScriptLoader::GetAuraScript, invoker);
}

SpellScriptLoader* ScriptMgr::GetSpellScriptLoader(uint32 scriptId)
{
    return ScriptRegistry<SpellScriptLoader>::Instance()->GetScriptById(scriptId);
}

void ScriptMgr::OnNetworkStart()
{
    FOREACH_SCRIPT(ServerScript)->OnNetworkStart();
}

void ScriptMgr::OnNetworkStop()
{
    FOREACH_SCRIPT(ServerScript)->OnNetworkStop();
}

void ScriptMgr::OnSocketOpen(std::shared_ptr<WorldSocket> socket)
{
    ASSERT(socket);

    FOREACH_SCRIPT(ServerScript)->OnSocketOpen(socket);
}

void ScriptMgr::OnSocketClose(std::shared_ptr<WorldSocket> socket)
{
    ASSERT(socket);

    FOREACH_SCRIPT(ServerScript)->OnSocketClose(socket);
}

void ScriptMgr::OnPacketReceive(WorldSession* session, WorldPacket const& packet)
{
    if (SCR_REG_LST(ServerScript).empty())
        return;

    WorldPacket copy(packet);
    FOREACH_SCRIPT(ServerScript)->OnPacketReceive(session, copy);
}

void ScriptMgr::OnPacketSend(WorldSession* session, WorldPacket const& packet)
{
    ASSERT(session);

    if (SCR_REG_LST(ServerScript).empty())
        return;

    WorldPacket copy(packet);
    FOREACH_SCRIPT(ServerScript)->OnPacketSend(session, copy);
}

void ScriptMgr::OnOpenStateChange(bool open)
{
    FOREACH_SCRIPT(WorldScript)->OnOpenStateChange(open);
}

void ScriptMgr::OnConfigLoad(bool reload)
{
    FOREACH_SCRIPT(WorldScript)->OnConfigLoad(reload);
}

void ScriptMgr::OnMotdChange(std::string& newMotd)
{
    FOREACH_SCRIPT(WorldScript)->OnMotdChange(newMotd);
}

void ScriptMgr::OnShutdownInitiate(ShutdownExitCode code, ShutdownMask mask)
{
    FOREACH_SCRIPT(WorldScript)->OnShutdownInitiate(code, mask);
}

void ScriptMgr::OnShutdownCancel()
{
    FOREACH_SCRIPT(WorldScript)->OnShutdownCancel();
}

void ScriptMgr::OnWorldUpdate(uint32 diff)
{
    FOREACH_SCRIPT(WorldScript)->OnUpdate(diff);
}

void ScriptMgr::OnHonorCalculation(float& honor, uint8 level, float multiplier)
{
    FOREACH_SCRIPT(FormulaScript)->OnHonorCalculation(honor, level, multiplier);
}

void ScriptMgr::OnGrayLevelCalculation(uint8& grayLevel, uint8 playerLevel)
{
    FOREACH_SCRIPT(FormulaScript)->OnGrayLevelCalculation(grayLevel, playerLevel);
}

void ScriptMgr::OnColorCodeCalculation(XPColorChar& color, uint8 playerLevel, uint8 mobLevel)
{
    FOREACH_SCRIPT(FormulaScript)->OnColorCodeCalculation(color, playerLevel, mobLevel);
}

void ScriptMgr::OnZeroDifferenceCalculation(uint8& diff, uint8 playerLevel)
{
    FOREACH_SCRIPT(FormulaScript)->OnZeroDifferenceCalculation(diff, playerLevel);
}

void ScriptMgr::OnBaseGainCalculation(uint32& gain, uint8 playerLevel, uint8 mobLevel)
{
    FOREACH_SCRIPT(FormulaScript)->OnBaseGainCalculation(gain, playerLevel, mobLevel);
}

void ScriptMgr::OnGainCalculation(uint32& gain, Player* player, Unit* unit)
{
    ASSERT(player);
    ASSERT(unit);

    FOREACH_SCRIPT(FormulaScript)->OnGainCalculation(gain, player, unit);
}

void ScriptMgr::OnGroupRateCalculation(float& rate, uint32 count, bool isRaid)
{
    FOREACH_SCRIPT(FormulaScript)->OnGroupRateCalculation(rate, count, isRaid);
}

#define SCR_MAP_BGN(M, V, I, E, C, T) \
    if (V->GetEntry() && V->GetEntry()->T()) \
    { \
        FOR_SCRIPTS(M, I, E) \
        { \
            MapEntry const* C = I->second->GetEntry(); \
            if (!C) \
                continue; \
            if (C->ID == V->GetId()) \
            {

#define SCR_MAP_END \
                return; \
            } \
        } \
    }

void ScriptMgr::OnCreateMap(Map* map)
{
    ASSERT(map);

    SCR_MAP_BGN(WorldMapScript, map, itr, end, entry, IsWorldMap);
        itr->second->OnCreate(map);
    SCR_MAP_END;

    SCR_MAP_BGN(InstanceMapScript, map, itr, end, entry, IsDungeon);
        itr->second->OnCreate((InstanceMap*)map);
    SCR_MAP_END;

    SCR_MAP_BGN(BattlegroundMapScript, map, itr, end, entry, IsBattleground);
        itr->second->OnCreate((BattlegroundMap*)map);
    SCR_MAP_END;
}

void ScriptMgr::OnDestroyMap(Map* map)
{
    ASSERT(map);

    SCR_MAP_BGN(WorldMapScript, map, itr, end, entry, IsWorldMap);
        itr->second->OnDestroy(map);
    SCR_MAP_END;

    SCR_MAP_BGN(InstanceMapScript, map, itr, end, entry, IsDungeon);
        itr->second->OnDestroy((InstanceMap*)map);
    SCR_MAP_END;

    SCR_MAP_BGN(BattlegroundMapScript, map, itr, end, entry, IsBattleground);
        itr->second->OnDestroy((BattlegroundMap*)map);
    SCR_MAP_END;
}

void ScriptMgr::OnPlayerEnterMap(Map* map, Player* player)
{
    ASSERT(map);
    ASSERT(player);

    FOREACH_SCRIPT(PlayerScript)->OnMapChanged(player);

    SCR_MAP_BGN(WorldMapScript, map, itr, end, entry, IsWorldMap);
        itr->second->OnPlayerEnter(map, player);
    SCR_MAP_END;

    SCR_MAP_BGN(InstanceMapScript, map, itr, end, entry, IsDungeon);
        itr->second->OnPlayerEnter((InstanceMap*)map, player);
    SCR_MAP_END;

    SCR_MAP_BGN(BattlegroundMapScript, map, itr, end, entry, IsBattleground);
        itr->second->OnPlayerEnter((BattlegroundMap*)map, player);
    SCR_MAP_END;
}

void ScriptMgr::OnPlayerLeaveMap(Map* map, Player* player)
{
    ASSERT(map);
    ASSERT(player);

    SCR_MAP_BGN(WorldMapScript, map, itr, end, entry, IsWorldMap);
        itr->second->OnPlayerLeave(map, player);
    SCR_MAP_END;

    SCR_MAP_BGN(InstanceMapScript, map, itr, end, entry, IsDungeon);
        itr->second->OnPlayerLeave((InstanceMap*)map, player);
    SCR_MAP_END;

    SCR_MAP_BGN(BattlegroundMapScript, map, itr, end, entry, IsBattleground);
        itr->second->OnPlayerLeave((BattlegroundMap*)map, player);
    SCR_MAP_END;
}

void ScriptMgr::OnMapUpdate(Map* map, uint32 diff)
{
    ASSERT(map);

    SCR_MAP_BGN(WorldMapScript, map, itr, end, entry, IsWorldMap);
        itr->second->OnUpdate(map, diff);
    SCR_MAP_END;

    SCR_MAP_BGN(InstanceMapScript, map, itr, end, entry, IsDungeon);
        itr->second->OnUpdate((InstanceMap*)map, diff);
    SCR_MAP_END;

    SCR_MAP_BGN(BattlegroundMapScript, map, itr, end, entry, IsBattleground);
        itr->second->OnUpdate((BattlegroundMap*)map, diff);
    SCR_MAP_END;
}

#undef SCR_MAP_BGN
#undef SCR_MAP_END

InstanceScript* ScriptMgr::CreateInstanceData(InstanceMap* map)
{
    ASSERT(map);

    GET_SCRIPT_RET(InstanceMapScript, map->GetScriptId(), tmpscript, nullptr);
    return tmpscript->GetInstanceScript(map);
}

BattlegroundScript* ScriptMgr::CreateBattlegroundData(BattlegroundMap* map)
{
    ASSERT(map);

    GET_SCRIPT_RET(BattlegroundMapScript, map->GetScriptId(), tmpscript, NULL);
    return tmpscript->GetBattlegroundScript(map);
}

bool ScriptMgr::OnQuestAccept(Player* player, Item* item, Quest const* quest)
{
    ASSERT(player);
    ASSERT(item);
    ASSERT(quest);

    GET_SCRIPT_RET(ItemScript, item->GetScriptId(), tmpscript, false);
    player->PlayerTalkClass->ClearMenus();
    return tmpscript->OnQuestAccept(player, item, quest);
}

bool ScriptMgr::OnItemUse(Player* player, Item* item, SpellCastTargets const& targets, ObjectGuid castId)
{
    ASSERT(player);
    ASSERT(item);

    GET_SCRIPT_RET(ItemScript, item->GetScriptId(), tmpscript, false);
    return tmpscript->OnUse(player, item, targets, castId);
}

bool ScriptMgr::OnItemExpire(Player* player, ItemTemplate const* proto)
{
    ASSERT(player);
    ASSERT(proto);

    GET_SCRIPT_RET(ItemScript, proto->ScriptId, tmpscript, false);
    return tmpscript->OnExpire(player, proto);
}

bool ScriptMgr::OnItemRemove(Player* player, Item* item)
{
    ASSERT(player);
    ASSERT(item);

    GET_SCRIPT_RET(ItemScript, item->GetScriptId(), tmpscript, false);
    return tmpscript->OnRemove(player, item);
}

bool ScriptMgr::OnCastItemCombatSpell(Player* player, Unit* victim, SpellInfo const* spellInfo, Item* item)
{
    ASSERT(player);
    ASSERT(victim);
    ASSERT(spellInfo);
    ASSERT(item);

    GET_SCRIPT_RET(ItemScript, item->GetScriptId(), tmpscript, true);
    return tmpscript->OnCastItemCombatSpell(player, victim, spellInfo, item);
}

bool ScriptMgr::CanCreateCreatureAI(uint32 scriptId) const
{
    return !!ScriptRegistry<CreatureScript>::Instance()->GetScriptById(scriptId);
}

CreatureAI* ScriptMgr::GetCreatureAI(Creature* creature)
{
    ASSERT(creature);

    GET_SCRIPT_RET(CreatureScript, creature->GetScriptId(), tmpscript, nullptr);
    return tmpscript->GetAI(creature);
}

bool ScriptMgr::CanCreateGameObjectAI(uint32 scriptId) const
{
    return !!ScriptRegistry<GameObjectScript>::Instance()->GetScriptById(scriptId);
}

GameObjectAI* ScriptMgr::GetGameObjectAI(GameObject* gameobject)
{
    ASSERT(gameobject);

    GET_SCRIPT_RET(GameObjectScript, gameobject->GetScriptId(), tmpscript, nullptr);
    return tmpscript->GetAI(gameobject);
}

bool ScriptMgr::CanCreateAreaTriggerAI(uint32 scriptId) const
{
    return !!ScriptRegistry<AreaTriggerEntityScript>::Instance()->GetScriptById(scriptId);
}

AreaTriggerAI* ScriptMgr::GetAreaTriggerAI(AreaTrigger* areatrigger)
{
    ASSERT(areatrigger);

    GET_SCRIPT_RET(AreaTriggerEntityScript, areatrigger->GetScriptId(), tmpscript, nullptr);
    return tmpscript->GetAI(areatrigger);
}

bool ScriptMgr::OnAreaTrigger(Player* player, AreaTriggerEntry const* trigger, bool entered)
{
    ASSERT(player);
    ASSERT(trigger);

    GET_SCRIPT_RET(AreaTriggerScript, sObjectMgr->GetAreaTriggerScriptId(trigger->ID), tmpscript, false);
    return entered ? tmpscript->OnTrigger(player, trigger) : tmpscript->OnExit(player, trigger);
}

Battlefield* ScriptMgr::CreateBattlefield(uint32 scriptId, Map* map)
{
    GET_SCRIPT_RET(BattlefieldScript, scriptId, tmpscript, nullptr);
    return tmpscript->GetBattlefield(map);
}

OutdoorPvP* ScriptMgr::CreateOutdoorPvP(uint32 scriptId, Map* map)
{
    GET_SCRIPT_RET(OutdoorPvPScript, scriptId, tmpscript, nullptr);
    return tmpscript->GetOutdoorPvP(map);
}

Trinity::ChatCommands::ChatCommandTable ScriptMgr::GetChatCommands()
{
    Trinity::ChatCommands::ChatCommandTable table;

    FOR_SCRIPTS(CommandScript, itr, end)
    {
        Trinity::ChatCommands::ChatCommandTable cmds = itr->second->GetCommands();
        std::move(cmds.begin(), cmds.end(), std::back_inserter(table));
    }

    return table;
}

void ScriptMgr::OnWeatherChange(Weather* weather, WeatherState state, float grade)
{
    ASSERT(weather);

    GET_SCRIPT(WeatherScript, weather->GetScriptId(), tmpscript);
    tmpscript->OnChange(weather, state, grade);
}

void ScriptMgr::OnWeatherUpdate(Weather* weather, uint32 diff)
{
    ASSERT(weather);

    GET_SCRIPT(WeatherScript, weather->GetScriptId(), tmpscript);
    tmpscript->OnUpdate(weather, diff);
}

void ScriptMgr::OnAuctionAdd(AuctionHouseObject* ah, AuctionPosting* auction)
{
    ASSERT(ah);
    ASSERT(auction);

    FOREACH_SCRIPT(AuctionHouseScript)->OnAuctionAdd(ah, auction);
}

void ScriptMgr::OnAuctionRemove(AuctionHouseObject* ah, AuctionPosting* auction)
{
    ASSERT(ah);
    ASSERT(auction);

    FOREACH_SCRIPT(AuctionHouseScript)->OnAuctionRemove(ah, auction);
}

void ScriptMgr::OnAuctionSuccessful(AuctionHouseObject* ah, AuctionPosting* auction)
{
    ASSERT(ah);
    ASSERT(auction);

    FOREACH_SCRIPT(AuctionHouseScript)->OnAuctionSuccessful(ah, auction);
}

void ScriptMgr::OnAuctionExpire(AuctionHouseObject* ah, AuctionPosting* auction)
{
    ASSERT(ah);
    ASSERT(auction);

    FOREACH_SCRIPT(AuctionHouseScript)->OnAuctionExpire(ah, auction);
}

bool ScriptMgr::OnConditionCheck(Condition const* condition, ConditionSourceInfo& sourceInfo)
{
    ASSERT(condition);

    GET_SCRIPT_RET(ConditionScript, condition->ScriptId, tmpscript, true);
    return tmpscript->OnConditionCheck(condition, sourceInfo);
}

void ScriptMgr::OnInstall(Vehicle* veh)
{
    ASSERT(veh);
    ASSERT(veh->GetBase()->GetTypeId() == TYPEID_UNIT);

    GET_SCRIPT(VehicleScript, veh->GetBase()->ToCreature()->GetScriptId(), tmpscript);
    tmpscript->OnInstall(veh);
}

void ScriptMgr::OnUninstall(Vehicle* veh)
{
    ASSERT(veh);
    ASSERT(veh->GetBase()->GetTypeId() == TYPEID_UNIT);

    GET_SCRIPT(VehicleScript, veh->GetBase()->ToCreature()->GetScriptId(), tmpscript);
    tmpscript->OnUninstall(veh);
}

void ScriptMgr::OnReset(Vehicle* veh)
{
    ASSERT(veh);
    ASSERT(veh->GetBase()->GetTypeId() == TYPEID_UNIT);

    GET_SCRIPT(VehicleScript, veh->GetBase()->ToCreature()->GetScriptId(), tmpscript);
    tmpscript->OnReset(veh);
}

void ScriptMgr::OnInstallAccessory(Vehicle* veh, Creature* accessory)
{
    ASSERT(veh);
    ASSERT(veh->GetBase()->GetTypeId() == TYPEID_UNIT);
    ASSERT(accessory);

    GET_SCRIPT(VehicleScript, veh->GetBase()->ToCreature()->GetScriptId(), tmpscript);
    tmpscript->OnInstallAccessory(veh, accessory);
}

void ScriptMgr::OnAddPassenger(Vehicle* veh, Unit* passenger, int8 seatId)
{
    ASSERT(veh);
    ASSERT(veh->GetBase()->GetTypeId() == TYPEID_UNIT);
    ASSERT(passenger);

    GET_SCRIPT(VehicleScript, veh->GetBase()->ToCreature()->GetScriptId(), tmpscript);
    tmpscript->OnAddPassenger(veh, passenger, seatId);
}

void ScriptMgr::OnRemovePassenger(Vehicle* veh, Unit* passenger)
{
    ASSERT(veh);
    ASSERT(veh->GetBase()->GetTypeId() == TYPEID_UNIT);
    ASSERT(passenger);

    GET_SCRIPT(VehicleScript, veh->GetBase()->ToCreature()->GetScriptId(), tmpscript);
    tmpscript->OnRemovePassenger(veh, passenger);
}

void ScriptMgr::OnDynamicObjectUpdate(DynamicObject* dynobj, uint32 diff)
{
    ASSERT(dynobj);

    FOR_SCRIPTS(DynamicObjectScript, itr, end)
        itr->second->OnUpdate(dynobj, diff);
}

void ScriptMgr::OnAddPassenger(Transport* transport, Player* player)
{
    ASSERT(transport);
    ASSERT(player);

    GET_SCRIPT(TransportScript, transport->GetScriptId(), tmpscript);
    tmpscript->OnAddPassenger(transport, player);
}

void ScriptMgr::OnAddCreaturePassenger(Transport* transport, Creature* creature)
{
    ASSERT(transport);
    ASSERT(creature);

    GET_SCRIPT(TransportScript, transport->GetScriptId(), tmpscript);
    tmpscript->OnAddCreaturePassenger(transport, creature);
}

void ScriptMgr::OnRemovePassenger(Transport* transport, Player* player)
{
    ASSERT(transport);
    ASSERT(player);

    GET_SCRIPT(TransportScript, transport->GetScriptId(), tmpscript);
    tmpscript->OnRemovePassenger(transport, player);
}

void ScriptMgr::OnTransportUpdate(Transport* transport, uint32 diff)
{
    ASSERT(transport);

    GET_SCRIPT(TransportScript, transport->GetScriptId(), tmpscript);
    tmpscript->OnUpdate(transport, diff);
}

void ScriptMgr::OnRelocate(Transport* transport, uint32 mapId, float x, float y, float z)
{
    GET_SCRIPT(TransportScript, transport->GetScriptId(), tmpscript);
    tmpscript->OnRelocate(transport, mapId, x, y, z);
}

void ScriptMgr::OnStartup()
{
    FOREACH_SCRIPT(WorldScript)->OnStartup();
}

void ScriptMgr::OnShutdown()
{
    FOREACH_SCRIPT(WorldScript)->OnShutdown();
}

// Achievement
void ScriptMgr::OnAchievementCompleted(Player* player, AchievementEntry const* achievement)
{
    ASSERT(player);
    ASSERT(achievement);

    GET_SCRIPT(AchievementScript, sAchievementMgr->GetAchievementScriptId(achievement->ID), tmpscript);
    tmpscript->OnCompleted(player, achievement);
}

bool ScriptMgr::OnCriteriaCheck(uint32 scriptId, Player* source, Unit* target)
{
    ASSERT(source);
    // target can be NULL.

    GET_SCRIPT_RET(AchievementCriteriaScript, scriptId, tmpscript, false);
    return tmpscript->OnCheck(source, target);
}

// Player
void ScriptMgr::OnPVPKill(Player* killer, Player* killed)
{
    FOREACH_SCRIPT(PlayerScript)->OnPVPKill(killer, killed);
}

void ScriptMgr::OnCreatureKill(Player* killer, Creature* killed)
{
    FOREACH_SCRIPT(PlayerScript)->OnCreatureKill(killer, killed);
}

void ScriptMgr::OnPlayerKilledByCreature(Creature* killer, Player* killed)
{
    FOREACH_SCRIPT(PlayerScript)->OnPlayerKilledByCreature(killer, killed);
}

void ScriptMgr::OnPlayerLevelChanged(Player* player, uint8 oldLevel)
{
    FOREACH_SCRIPT(PlayerScript)->OnLevelChanged(player, oldLevel);
}

void ScriptMgr::OnPlayerFreeTalentPointsChanged(Player* player, uint32 points)
{
    FOREACH_SCRIPT(PlayerScript)->OnFreeTalentPointsChanged(player, points);
}

void ScriptMgr::OnPlayerTalentsReset(Player* player, bool noCost)
{
    FOREACH_SCRIPT(PlayerScript)->OnTalentsReset(player, noCost);
}

void ScriptMgr::OnPlayerMoneyChanged(Player* player, int64& amount)
{
    FOREACH_SCRIPT(PlayerScript)->OnMoneyChanged(player, amount);
}

void ScriptMgr::OnPlayerMoneyLimit(Player* player, int64 amount)
{
    FOREACH_SCRIPT(PlayerScript)->OnMoneyLimit(player, amount);
}

void ScriptMgr::OnGivePlayerXP(Player* player, uint32& amount, Unit* victim)
{
    FOREACH_SCRIPT(PlayerScript)->OnGiveXP(player, amount, victim);
}

void ScriptMgr::OnPlayerReputationChange(Player* player, uint32 factionID, int32& standing, bool incremental)
{
    FOREACH_SCRIPT(PlayerScript)->OnReputationChange(player, factionID, standing, incremental);
}

void ScriptMgr::OnPlayerDuelRequest(Player* target, Player* challenger)
{
    FOREACH_SCRIPT(PlayerScript)->OnDuelRequest(target, challenger);
}

void ScriptMgr::OnPlayerDuelStart(Player* player1, Player* player2)
{
    FOREACH_SCRIPT(PlayerScript)->OnDuelStart(player1, player2);
}

void ScriptMgr::OnPlayerDuelEnd(Player* winner, Player* loser, DuelCompleteType type)
{
    FOREACH_SCRIPT(PlayerScript)->OnDuelEnd(winner, loser, type);
}

void ScriptMgr::OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg)
{
    FOREACH_SCRIPT(PlayerScript)->OnChat(player, type, lang, msg);
}

void ScriptMgr::OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg, Player* receiver)
{
    FOREACH_SCRIPT(PlayerScript)->OnChat(player, type, lang, msg, receiver);
}

void ScriptMgr::OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg, Group* group)
{
    FOREACH_SCRIPT(PlayerScript)->OnChat(player, type, lang, msg, group);
}

void ScriptMgr::OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg, Guild* guild)
{
    FOREACH_SCRIPT(PlayerScript)->OnChat(player, type, lang, msg, guild);
}

void ScriptMgr::OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg, Channel* channel)
{
    FOREACH_SCRIPT(PlayerScript)->OnChat(player, type, lang, msg, channel);
}

void ScriptMgr::OnPlayerClearEmote(Player* player)
{
    FOREACH_SCRIPT(PlayerScript)->OnClearEmote(player);
}

void ScriptMgr::OnPlayerTextEmote(Player* player, uint32 textEmote, uint32 emoteNum, ObjectGuid guid)
{
    FOREACH_SCRIPT(PlayerScript)->OnTextEmote(player, textEmote, emoteNum, guid);
}

void ScriptMgr::OnPlayerSpellCast(Player* player, Spell* spell, bool skipCheck)
{
    FOREACH_SCRIPT(PlayerScript)->OnSpellCast(player, spell, skipCheck);
}

void ScriptMgr::OnPlayerLogin(Player* player, bool firstLogin)
{
    FOREACH_SCRIPT(PlayerScript)->OnLogin(player, firstLogin);
}

void ScriptMgr::OnPlayerLogout(Player* player)
{
    FOREACH_SCRIPT(PlayerScript)->OnLogout(player);
}

void ScriptMgr::OnPlayerCreate(Player* player)
{
    FOREACH_SCRIPT(PlayerScript)->OnCreate(player);
}

void ScriptMgr::OnPlayerDelete(ObjectGuid guid, uint32 accountId)
{
    FOREACH_SCRIPT(PlayerScript)->OnDelete(guid, accountId);
}

void ScriptMgr::OnPlayerFailedDelete(ObjectGuid guid, uint32 accountId)
{
    FOREACH_SCRIPT(PlayerScript)->OnFailedDelete(guid, accountId);
}

void ScriptMgr::OnPlayerSave(Player* player)
{
    FOREACH_SCRIPT(PlayerScript)->OnSave(player);
}

void ScriptMgr::OnPlayerBindToInstance(Player* player, Difficulty difficulty, uint32 mapid, bool permanent, uint8 extendState)
{
    FOREACH_SCRIPT(PlayerScript)->OnBindToInstance(player, difficulty, mapid, permanent, extendState);
}

void ScriptMgr::OnPlayerUpdateZone(Player* player, uint32 newZone, uint32 newArea)
{
    FOREACH_SCRIPT(PlayerScript)->OnUpdateZone(player, newZone, newArea);
}

void ScriptMgr::OnQuestStatusChange(Player* player, uint32 questId)
{
    FOREACH_SCRIPT(PlayerScript)->OnQuestStatusChange(player, questId);
}

void ScriptMgr::OnPlayerRepop(Player* player)
{
    FOREACH_SCRIPT(PlayerScript)->OnPlayerRepop(player);
}

void ScriptMgr::OnMovieComplete(Player* player, uint32 movieId)
{
    FOREACH_SCRIPT(PlayerScript)->OnMovieComplete(player, movieId);
}

void ScriptMgr::OnPlayerChoiceResponse(Player* player, uint32 choiceId, uint32 responseId)
{
    FOREACH_SCRIPT(PlayerScript)->OnPlayerChoiceResponse(player, choiceId, responseId);
}

// Account
void ScriptMgr::OnAccountLogin(uint32 accountId)
{
    FOREACH_SCRIPT(AccountScript)->OnAccountLogin(accountId);
}

void ScriptMgr::OnFailedAccountLogin(uint32 accountId)
{
    FOREACH_SCRIPT(AccountScript)->OnFailedAccountLogin(accountId);
}

void ScriptMgr::OnEmailChange(uint32 accountId)
{
    FOREACH_SCRIPT(AccountScript)->OnEmailChange(accountId);
}

void ScriptMgr::OnFailedEmailChange(uint32 accountId)
{
    FOREACH_SCRIPT(AccountScript)->OnFailedEmailChange(accountId);
}

void ScriptMgr::OnPasswordChange(uint32 accountId)
{
    FOREACH_SCRIPT(AccountScript)->OnPasswordChange(accountId);
}

void ScriptMgr::OnFailedPasswordChange(uint32 accountId)
{
    FOREACH_SCRIPT(AccountScript)->OnFailedPasswordChange(accountId);
}

// Guild
void ScriptMgr::OnGuildAddMember(Guild* guild, Player* player, uint8 plRank)
{
    FOREACH_SCRIPT(GuildScript)->OnAddMember(guild, player, plRank);
}

void ScriptMgr::OnGuildRemoveMember(Guild* guild, ObjectGuid guid, bool isDisbanding, bool isKicked)
{
    FOREACH_SCRIPT(GuildScript)->OnRemoveMember(guild, guid, isDisbanding, isKicked);
}

void ScriptMgr::OnGuildMOTDChanged(Guild* guild, const std::string& newMotd)
{
    FOREACH_SCRIPT(GuildScript)->OnMOTDChanged(guild, newMotd);
}

void ScriptMgr::OnGuildInfoChanged(Guild* guild, const std::string& newInfo)
{
    FOREACH_SCRIPT(GuildScript)->OnInfoChanged(guild, newInfo);
}

void ScriptMgr::OnGuildCreate(Guild* guild, Player* leader, const std::string& name)
{
    FOREACH_SCRIPT(GuildScript)->OnCreate(guild, leader, name);
}

void ScriptMgr::OnGuildDisband(Guild* guild)
{
    FOREACH_SCRIPT(GuildScript)->OnDisband(guild);
}

void ScriptMgr::OnGuildMemberWitdrawMoney(Guild* guild, Player* player, uint64 &amount, bool isRepair)
{
    FOREACH_SCRIPT(GuildScript)->OnMemberWitdrawMoney(guild, player, amount, isRepair);
}

void ScriptMgr::OnGuildMemberDepositMoney(Guild* guild, Player* player, uint64 &amount)
{
    FOREACH_SCRIPT(GuildScript)->OnMemberDepositMoney(guild, player, amount);
}

void ScriptMgr::OnGuildItemMove(Guild* guild, Player* player, Item* pItem, bool isSrcBank, uint8 srcContainer, uint8 srcSlotId,
            bool isDestBank, uint8 destContainer, uint8 destSlotId)
{
    FOREACH_SCRIPT(GuildScript)->OnItemMove(guild, player, pItem, isSrcBank, srcContainer, srcSlotId, isDestBank, destContainer, destSlotId);
}

void ScriptMgr::OnGuildEvent(Guild* guild, uint8 eventType, ObjectGuid::LowType playerGuid1, ObjectGuid::LowType playerGuid2, uint8 newRank)
{
    FOREACH_SCRIPT(GuildScript)->OnEvent(guild, eventType, playerGuid1, playerGuid2, newRank);
}

void ScriptMgr::OnGuildBankEvent(Guild* guild, uint8 eventType, uint8 tabId, ObjectGuid::LowType playerGuid, uint64 itemOrMoney, uint16 itemStackCount, uint8 destTabId)
{
    FOREACH_SCRIPT(GuildScript)->OnBankEvent(guild, eventType, tabId, playerGuid, itemOrMoney, itemStackCount, destTabId);
}

// Group
void ScriptMgr::OnGroupAddMember(Group* group, ObjectGuid guid)
{
    ASSERT(group);
    FOREACH_SCRIPT(GroupScript)->OnAddMember(group, guid);
}

void ScriptMgr::OnGroupInviteMember(Group* group, ObjectGuid guid)
{
    ASSERT(group);
    FOREACH_SCRIPT(GroupScript)->OnInviteMember(group, guid);
}

void ScriptMgr::OnGroupRemoveMember(Group* group, ObjectGuid guid, RemoveMethod method, ObjectGuid kicker, char const* reason)
{
    ASSERT(group);
    FOREACH_SCRIPT(GroupScript)->OnRemoveMember(group, guid, method, kicker, reason);
}

void ScriptMgr::OnGroupChangeLeader(Group* group, ObjectGuid newLeaderGuid, ObjectGuid oldLeaderGuid)
{
    ASSERT(group);
    FOREACH_SCRIPT(GroupScript)->OnChangeLeader(group, newLeaderGuid, oldLeaderGuid);
}

void ScriptMgr::OnGroupDisband(Group* group)
{
    ASSERT(group);
    FOREACH_SCRIPT(GroupScript)->OnDisband(group);
}

// Unit
void ScriptMgr::OnHeal(Unit* healer, Unit* reciever, uint32& gain)
{
    FOREACH_SCRIPT(UnitScript)->OnHeal(healer, reciever, gain);
}

void ScriptMgr::OnDamage(Unit* attacker, Unit* victim, uint32& damage)
{
    FOREACH_SCRIPT(UnitScript)->OnDamage(attacker, victim, damage);
}

void ScriptMgr::ModifyPeriodicDamageAurasTick(Unit* target, Unit* attacker, uint32& damage)
{
    FOREACH_SCRIPT(UnitScript)->ModifyPeriodicDamageAurasTick(target, attacker, damage);
}

void ScriptMgr::ModifyMeleeDamage(Unit* target, Unit* attacker, uint32& damage)
{
    FOREACH_SCRIPT(UnitScript)->ModifyMeleeDamage(target, attacker, damage);
}

void ScriptMgr::ModifySpellDamageTaken(Unit* target, Unit* attacker, int32& damage, SpellInfo const* spellInfo)
{
    FOREACH_SCRIPT(UnitScript)->ModifySpellDamageTaken(target, attacker, damage, spellInfo);
}

// Conversation
void ScriptMgr::OnConversationCreate(Conversation* conversation, Unit* creator)
{
    ASSERT(conversation);

    GET_SCRIPT(ConversationScript, conversation->GetScriptId(), tmpscript);
    tmpscript->OnConversationCreate(conversation, creator);
}

void ScriptMgr::OnConversationStart(Conversation* conversation)
{
    ASSERT(conversation);

    GET_SCRIPT(ConversationScript, conversation->GetScriptId(), tmpscript);
    tmpscript->OnConversationStart(conversation);
}

void ScriptMgr::OnConversationLineStarted(Conversation* conversation, uint32 lineId, Player* sender)
{
    ASSERT(conversation);
    ASSERT(sender);

    GET_SCRIPT(ConversationScript, conversation->GetScriptId(), tmpscript);
    tmpscript->OnConversationLineStarted(conversation, lineId, sender);
}

void ScriptMgr::OnConversationUpdate(Conversation* conversation, uint32 diff)
{
    ASSERT(conversation);

    GET_SCRIPT(ConversationScript, conversation->GetScriptId(), tmpscript);
    tmpscript->OnConversationUpdate(conversation, diff);
}

// Scene
void ScriptMgr::OnSceneStart(Player* player, uint32 sceneInstanceID, SceneTemplate const* sceneTemplate)
{
    ASSERT(player);
    ASSERT(sceneTemplate);

    GET_SCRIPT(SceneScript, sceneTemplate->ScriptId, tmpscript);
    tmpscript->OnSceneStart(player, sceneInstanceID, sceneTemplate);
}

void ScriptMgr::OnSceneTrigger(Player* player, uint32 sceneInstanceID, SceneTemplate const* sceneTemplate, std::string const& triggerName)
{
    ASSERT(player);
    ASSERT(sceneTemplate);

    GET_SCRIPT(SceneScript, sceneTemplate->ScriptId, tmpscript);
    tmpscript->OnSceneTriggerEvent(player, sceneInstanceID, sceneTemplate, triggerName);
}

void ScriptMgr::OnSceneCancel(Player* player, uint32 sceneInstanceID, SceneTemplate const* sceneTemplate)
{
    ASSERT(player);
    ASSERT(sceneTemplate);

    GET_SCRIPT(SceneScript, sceneTemplate->ScriptId, tmpscript);
    tmpscript->OnSceneCancel(player, sceneInstanceID, sceneTemplate);
}

void ScriptMgr::OnSceneComplete(Player* player, uint32 sceneInstanceID, SceneTemplate const* sceneTemplate)
{
    ASSERT(player);
    ASSERT(sceneTemplate);

    GET_SCRIPT(SceneScript, sceneTemplate->ScriptId, tmpscript);
    tmpscript->OnSceneComplete(player, sceneInstanceID, sceneTemplate);
}

// Quest
void ScriptMgr::OnQuestStatusChange(Player* player, Quest const* quest, QuestStatus oldStatus, QuestStatus newStatus)
{
    ASSERT(player);
    ASSERT(quest);

    GET_SCRIPT(QuestScript, quest->GetScriptId(), tmpscript);
    tmpscript->OnQuestStatusChange(player, quest, oldStatus, newStatus);
}

void ScriptMgr::OnQuestAcknowledgeAutoAccept(Player* player, Quest const* quest)
{
    ASSERT(player);
    ASSERT(quest);

    GET_SCRIPT(QuestScript, quest->GetScriptId(), tmpscript);
    tmpscript->OnAcknowledgeAutoAccept(player, quest);
}

void ScriptMgr::OnQuestObjectiveChange(Player* player, Quest const* quest, QuestObjective const& objective, int32 oldAmount, int32 newAmount)
{
    ASSERT(player);
    ASSERT(quest);

    GET_SCRIPT(QuestScript, quest->GetScriptId(), tmpscript);
    tmpscript->OnQuestObjectiveChange(player, quest, objective, oldAmount, newAmount);
}

// WorldState
void ScriptMgr::OnWorldStateValueChange(WorldStateTemplate const* worldStateTemplate, int32 oldValue, int32 newValue, Map const* map)
{
    ASSERT(worldStateTemplate);

    GET_SCRIPT(WorldStateScript, worldStateTemplate->ScriptId, tmpscript);
    tmpscript->OnValueChange(worldStateTemplate->Id, oldValue, newValue, map);
}

// Event
void ScriptMgr::OnEventTrigger(WorldObject* object, WorldObject* invoker, uint32 eventId)
{
    ASSERT(invoker);

    GET_SCRIPT(EventScript, sObjectMgr->GetEventScriptId(eventId), tmpscript);
    tmpscript->OnTrigger(object, invoker, eventId);
}

SpellScriptLoader::SpellScriptLoader(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<SpellScriptLoader>::Instance()->AddScript(this);
}

SpellScript* SpellScriptLoader::GetSpellScript() const
{
    return nullptr;
}

AuraScript* SpellScriptLoader::GetAuraScript() const
{
    return nullptr;
}

ServerScript::ServerScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<ServerScript>::Instance()->AddScript(this);
}

ServerScript::~ServerScript() = default;

void ServerScript::OnNetworkStart()
{
}

void ServerScript::OnNetworkStop()
{
}

void ServerScript::OnSocketOpen(std::shared_ptr<WorldSocket> /*socket*/)
{
}

void ServerScript::OnSocketClose(std::shared_ptr<WorldSocket> /*socket*/)
{
}

void ServerScript::OnPacketSend(WorldSession* /*session*/, WorldPacket& /*packet*/)
{
}

void ServerScript::OnPacketReceive(WorldSession* /*session*/, WorldPacket& /*packet*/)
{
}

WorldScript::WorldScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<WorldScript>::Instance()->AddScript(this);
}

WorldScript::~WorldScript() = default;

void WorldScript::OnOpenStateChange(bool /*open*/)
{
}

void WorldScript::OnConfigLoad(bool /*reload*/)
{
}

void WorldScript::OnMotdChange(std::string& /*newMotd*/)
{
}

void WorldScript::OnShutdownInitiate(ShutdownExitCode /*code*/, ShutdownMask /*mask*/)
{
}

void WorldScript::OnShutdownCancel()
{
}

void WorldScript::OnUpdate(uint32 /*diff*/)
{
}

void WorldScript::OnStartup()
{
}

void WorldScript::OnShutdown()
{
}

FormulaScript::FormulaScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<FormulaScript>::Instance()->AddScript(this);
}

FormulaScript::~FormulaScript() = default;

void FormulaScript::OnHonorCalculation(float& /*honor*/, uint8 /*level*/, float /*multiplier*/)
{
}

void FormulaScript::OnGrayLevelCalculation(uint8& /*grayLevel*/, uint8 /*playerLevel*/)
{
}

void FormulaScript::OnColorCodeCalculation(XPColorChar& /*color*/, uint8 /*playerLevel*/, uint8 /*mobLevel*/)
{
}

void FormulaScript::OnZeroDifferenceCalculation(uint8& /*diff*/, uint8 /*playerLevel*/)
{
}

void FormulaScript::OnBaseGainCalculation(uint32& /*gain*/, uint8 /*playerLevel*/, uint8 /*mobLevel*/)
{
}

void FormulaScript::OnGainCalculation(uint32& /*gain*/, Player* /*player*/, Unit* /*unit*/)
{
}

void FormulaScript::OnGroupRateCalculation(float& /*rate*/, uint32 /*count*/, bool /*isRaid*/)
{
}

template <class TMap>
MapScript<TMap>::MapScript(MapEntry const* mapEntry) : _mapEntry(mapEntry)
{
}

template <class TMap>
MapEntry const* MapScript<TMap>::GetEntry() const
{
    return _mapEntry;
}

template <class TMap>
void MapScript<TMap>::OnCreate(TMap* /*map*/)
{
}

template <class TMap>
void MapScript<TMap>::OnDestroy(TMap* /*map*/)
{
}

template <class TMap>
void MapScript<TMap>::OnPlayerEnter(TMap* /*map*/, Player* /*player*/)
{
}

template <class TMap>
void MapScript<TMap>::OnPlayerLeave(TMap* /*map*/, Player* /*player*/)
{
}

template <class TMap>
void MapScript<TMap>::OnUpdate(TMap* /*map*/, uint32 /*diff*/)
{
}

template class TC_GAME_API MapScript<Map>;
template class TC_GAME_API MapScript<InstanceMap>;
template class TC_GAME_API MapScript<BattlegroundMap>;

WorldMapScript::WorldMapScript(char const* name, uint32 mapId)
    : ScriptObject(name), MapScript(sMapStore.LookupEntry(mapId))
{
    if (!GetEntry())
        TC_LOG_ERROR("scripts", "Invalid WorldMapScript for {}; no such map ID.", mapId);

    if (GetEntry() && !GetEntry()->IsWorldMap())
        TC_LOG_ERROR("scripts", "WorldMapScript for map {} is invalid.", mapId);

    ScriptRegistry<WorldMapScript>::Instance()->AddScript(this);
}

WorldMapScript::~WorldMapScript() = default;

InstanceMapScript::InstanceMapScript(char const* name, uint32 mapId)
    : ScriptObject(name), MapScript(sMapStore.LookupEntry(mapId))
{
    if (!GetEntry())
        TC_LOG_ERROR("scripts", "Invalid InstanceMapScript for {}; no such map ID.", mapId);

    if (GetEntry() && !GetEntry()->IsDungeon())
        TC_LOG_ERROR("scripts", "InstanceMapScript for map {} is invalid.", mapId);

    ScriptRegistry<InstanceMapScript>::Instance()->AddScript(this);
}

InstanceMapScript::~InstanceMapScript() = default;

InstanceScript* InstanceMapScript::GetInstanceScript(InstanceMap* /*map*/) const
{
    return nullptr;
}

BattlegroundMapScript::BattlegroundMapScript(char const* name, uint32 mapId)
    : ScriptObject(name), MapScript(sMapStore.LookupEntry(mapId))
{
    if (!GetEntry())
        TC_LOG_ERROR("scripts", "Invalid BattlegroundMapScript for {}; no such map ID.", mapId);

    if (GetEntry() && !GetEntry()->IsBattleground())
        TC_LOG_ERROR("scripts", "BattlegroundMapScript for map {} is invalid.", mapId);

    ScriptRegistry<BattlegroundMapScript>::Instance()->AddScript(this);
}

BattlegroundMapScript::~BattlegroundMapScript() = default;

BattlegroundScript* BattlegroundMapScript::GetBattlegroundScript(BattlegroundMap* /*map*/) const
{
    return nullptr;
}

ItemScript::ItemScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<ItemScript>::Instance()->AddScript(this);
}

ItemScript::~ItemScript() = default;

bool ItemScript::OnQuestAccept(Player* /*player*/, Item* /*item*/, Quest const* /*quest*/)
{
    return false;
}

bool ItemScript::OnUse(Player* /*player*/, Item* /*item*/, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/)
{
    return false;
}

bool ItemScript::OnExpire(Player* /*player*/, ItemTemplate const* /*proto*/)
{
    return false;
}

bool ItemScript::OnRemove(Player* /*player*/, Item* /*item*/)
{
    return false;
}

bool ItemScript::OnCastItemCombatSpell(Player* /*player*/, Unit* /*victim*/, SpellInfo const* /*spellInfo*/, Item* /*item*/)
{
    return true;
}

UnitScript::UnitScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<UnitScript>::Instance()->AddScript(this);
}

UnitScript::~UnitScript() = default;

void UnitScript::OnHeal(Unit* /*healer*/, Unit* /*reciever*/, uint32& /*gain*/)
{
}

void UnitScript::OnDamage(Unit* /*attacker*/, Unit* /*victim*/, uint32& /*damage*/)
{
}

void UnitScript::ModifyPeriodicDamageAurasTick(Unit* /*target*/, Unit* /*attacker*/, uint32& /*damage*/)
{
}

void UnitScript::ModifyMeleeDamage(Unit* /*target*/, Unit* /*attacker*/, uint32& /*damage*/)
{
}

void UnitScript::ModifySpellDamageTaken(Unit* /*target*/, Unit* /*attacker*/, int32& /*damage*/, SpellInfo const* /*spellInfo*/)
{
}

CreatureScript::CreatureScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<CreatureScript>::Instance()->AddScript(this);
}

CreatureScript::~CreatureScript() = default;

GameObjectScript::GameObjectScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<GameObjectScript>::Instance()->AddScript(this);
}

GameObjectScript::~GameObjectScript() = default;

AreaTriggerScript::AreaTriggerScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<AreaTriggerScript>::Instance()->AddScript(this);
}

AreaTriggerScript::~AreaTriggerScript() = default;

bool AreaTriggerScript::OnTrigger(Player* /*player*/, AreaTriggerEntry const* /*trigger*/)
{
    return false;
}

bool AreaTriggerScript::OnExit(Player* /*player*/, AreaTriggerEntry const* /*trigger*/)
{
    return false;
}

OnlyOnceAreaTriggerScript::~OnlyOnceAreaTriggerScript() = default;

bool OnlyOnceAreaTriggerScript::OnTrigger(Player* player, AreaTriggerEntry const* trigger)
{
    uint32 const triggerId = trigger->ID;
    InstanceScript* instance = player->GetInstanceScript();
    if (instance && instance->IsAreaTriggerDone(triggerId))
        return true;

    if (TryHandleOnce(player, trigger) && instance)
        instance->MarkAreaTriggerDone(triggerId);

    return true;
}
void OnlyOnceAreaTriggerScript::ResetAreaTriggerDone(InstanceScript* instance, uint32 triggerId) { instance->ResetAreaTriggerDone(triggerId); }
void OnlyOnceAreaTriggerScript::ResetAreaTriggerDone(Player const* player, AreaTriggerEntry const* trigger) { if (InstanceScript* instance = player->GetInstanceScript()) ResetAreaTriggerDone(instance, trigger->ID); }

BattlefieldScript::BattlefieldScript(char const* name)
        : ScriptObject(name)
{
    ScriptRegistry<BattlefieldScript>::Instance()->AddScript(this);
}

BattlefieldScript::~BattlefieldScript() = default;

OutdoorPvPScript::OutdoorPvPScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<OutdoorPvPScript>::Instance()->AddScript(this);
}

OutdoorPvPScript::~OutdoorPvPScript() = default;

CommandScript::CommandScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<CommandScript>::Instance()->AddScript(this);
}

CommandScript::~CommandScript() = default;

WeatherScript::WeatherScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<WeatherScript>::Instance()->AddScript(this);
}

WeatherScript::~WeatherScript() = default;

void WeatherScript::OnChange(Weather* /*weather*/, WeatherState /*state*/, float /*grade*/)
{
}

void WeatherScript::OnUpdate(Weather* /*weather*/, uint32 /*diff*/)
{
}

AuctionHouseScript::AuctionHouseScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<AuctionHouseScript>::Instance()->AddScript(this);
}

AuctionHouseScript::~AuctionHouseScript() = default;

void AuctionHouseScript::OnAuctionAdd(AuctionHouseObject* /*ah*/, AuctionPosting* /*auction*/)
{
}

void AuctionHouseScript::OnAuctionRemove(AuctionHouseObject* /*ah*/, AuctionPosting* /*auction*/)
{
}

void AuctionHouseScript::OnAuctionSuccessful(AuctionHouseObject* /*ah*/, AuctionPosting* /*auction*/)
{
}

void AuctionHouseScript::OnAuctionExpire(AuctionHouseObject* /*ah*/, AuctionPosting* /*auction*/)
{
}

ConditionScript::ConditionScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<ConditionScript>::Instance()->AddScript(this);
}

ConditionScript::~ConditionScript() = default;

bool ConditionScript::OnConditionCheck(Condition const* /*condition*/, ConditionSourceInfo& /*sourceInfo*/)
{
    return true;
}

VehicleScript::VehicleScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<VehicleScript>::Instance()->AddScript(this);
}

VehicleScript::~VehicleScript() = default;

void VehicleScript::OnInstall(Vehicle* /*veh*/)
{
}

void VehicleScript::OnUninstall(Vehicle* /*veh*/)
{
}

void VehicleScript::OnReset(Vehicle* /*veh*/)
{
}

void VehicleScript::OnInstallAccessory(Vehicle* /*veh*/, Creature* /*accessory*/)
{
}

void VehicleScript::OnAddPassenger(Vehicle* /*veh*/, Unit* /*passenger*/, int8 /*seatId*/)
{
}

void VehicleScript::OnRemovePassenger(Vehicle* /*veh*/, Unit* /*passenger*/)
{
}

DynamicObjectScript::DynamicObjectScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<DynamicObjectScript>::Instance()->AddScript(this);
}

DynamicObjectScript::~DynamicObjectScript() = default;

void DynamicObjectScript::OnUpdate(DynamicObject* /*obj*/, uint32 /*diff*/)
{
}

TransportScript::TransportScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<TransportScript>::Instance()->AddScript(this);
}

TransportScript::~TransportScript() = default;

void TransportScript::OnAddPassenger(Transport* /*transport*/, Player* /*player*/)
{
}

void TransportScript::OnAddCreaturePassenger(Transport* /*transport*/, Creature* /*creature*/)
{
}

void TransportScript::OnRemovePassenger(Transport* /*transport*/, Player* /*player*/)
{
}

void TransportScript::OnRelocate(Transport* /*transport*/, uint32 /*mapId*/, float /*x*/, float /*y*/, float /*z*/)
{
}

void TransportScript::OnUpdate(Transport* /*transport*/, uint32 /*diff*/)
{
}

AchievementScript::AchievementScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<AchievementScript>::Instance()->AddScript(this);
}

AchievementScript::~AchievementScript() = default;

void AchievementScript::OnCompleted(Player* /*player*/, AchievementEntry const* /*achievement*/)
{
}

AchievementCriteriaScript::AchievementCriteriaScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<AchievementCriteriaScript>::Instance()->AddScript(this);
}

AchievementCriteriaScript::~AchievementCriteriaScript() = default;

PlayerScript::PlayerScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<PlayerScript>::Instance()->AddScript(this);
}

PlayerScript::~PlayerScript() = default;

void PlayerScript::OnPVPKill(Player* /*killer*/, Player* /*killed*/)
{
}

void PlayerScript::OnCreatureKill(Player* /*killer*/, Creature* /*killed*/)
{
}

void PlayerScript::OnPlayerKilledByCreature(Creature* /*killer*/, Player* /*killed*/)
{
}

void PlayerScript::OnLevelChanged(Player* /*player*/, uint8 /*oldLevel*/)
{
}

void PlayerScript::OnFreeTalentPointsChanged(Player* /*player*/, uint32 /*points*/)
{
}

void PlayerScript::OnTalentsReset(Player* /*player*/, bool /*noCost*/)
{
}

void PlayerScript::OnMoneyChanged(Player* /*player*/, int64& /*amount*/)
{
}

void PlayerScript::OnMoneyLimit(Player* /*player*/, int64 /*amount*/)
{
}

void PlayerScript::OnGiveXP(Player* /*player*/, uint32& /*amount*/, Unit* /*victim*/)
{
}

void PlayerScript::OnReputationChange(Player* /*player*/, uint32 /*factionId*/, int32& /*standing*/, bool /*incremental*/)
{
}

void PlayerScript::OnDuelRequest(Player* /*target*/, Player* /*challenger*/)
{
}

void PlayerScript::OnDuelStart(Player* /*player1*/, Player* /*player2*/)
{
}

void PlayerScript::OnDuelEnd(Player* /*winner*/, Player* /*loser*/, DuelCompleteType /*type*/)
{
}

void PlayerScript::OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/)
{
}

void PlayerScript::OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/, Player* /*receiver*/)
{
}

void PlayerScript::OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/, Group* /*group*/)
{
}

void PlayerScript::OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/, Guild* /*guild*/)
{
}

void PlayerScript::OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/, Channel* /*channel*/)
{
}

void PlayerScript::OnClearEmote(Player* /*player*/)
{
}

void PlayerScript::OnTextEmote(Player* /*player*/, uint32 /*textEmote*/, uint32 /*emoteNum*/, ObjectGuid /*guid*/)
{
}

void PlayerScript::OnSpellCast(Player* /*player*/, Spell* /*spell*/, bool /*skipCheck*/)
{
}

void PlayerScript::OnLogin(Player* /*player*/, bool /*firstLogin*/)
{
}

void PlayerScript::OnLogout(Player* /*player*/)
{
}

void PlayerScript::OnCreate(Player* /*player*/)
{
}

void PlayerScript::OnDelete(ObjectGuid /*guid*/, uint32 /*accountId*/)
{
}

void PlayerScript::OnFailedDelete(ObjectGuid /*guid*/, uint32 /*accountId*/)
{
}

void PlayerScript::OnSave(Player* /*player*/)
{
}

void PlayerScript::OnBindToInstance(Player* /*player*/, Difficulty /*difficulty*/, uint32 /*mapId*/, bool /*permanent*/, uint8 /*extendState*/)
{
}

void PlayerScript::OnUpdateZone(Player* /*player*/, uint32 /*newZone*/, uint32 /*newArea*/)
{
}

void PlayerScript::OnMapChanged(Player* /*player*/)
{
}

void PlayerScript::OnQuestStatusChange(Player* /*player*/, uint32 /*questId*/)
{
}

void PlayerScript::OnPlayerRepop(Player* /*player*/)
{
}

void PlayerScript::OnMovieComplete(Player* /*player*/, uint32 /*movieId*/)
{
}

void PlayerScript::OnPlayerChoiceResponse(Player* /*player*/, uint32 /*choiceId*/, uint32 /*responseId*/)
{
}

AccountScript::AccountScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<AccountScript>::Instance()->AddScript(this);
}

AccountScript::~AccountScript() = default;

void AccountScript::OnAccountLogin(uint32 /*accountId*/)
{
}

void AccountScript::OnFailedAccountLogin(uint32 /*accountId*/)
{
}

void AccountScript::OnEmailChange(uint32 /*accountId*/)
{
}

void AccountScript::OnFailedEmailChange(uint32 /*accountId*/)
{
}

void AccountScript::OnPasswordChange(uint32 /*accountId*/)
{
}

void AccountScript::OnFailedPasswordChange(uint32 /*accountId*/)
{
}

GuildScript::GuildScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<GuildScript>::Instance()->AddScript(this);
}

GuildScript::~GuildScript() = default;

void GuildScript::OnAddMember(Guild* /*guild*/, Player* /*player*/, uint8 /*plRank*/)
{
}

void GuildScript::OnRemoveMember(Guild* /*guild*/, ObjectGuid /*guid*/, bool /*isDisbanding*/, bool /*isKicked*/)
{
}

void GuildScript::OnMOTDChanged(Guild* /*guild*/, std::string const& /*newMotd*/)
{
}

void GuildScript::OnInfoChanged(Guild* /*guild*/, std::string const& /*newInfo*/)
{
}

void GuildScript::OnCreate(Guild* /*guild*/, Player* /*leader*/, std::string const& /*name*/)
{
}

void GuildScript::OnDisband(Guild* /*guild*/)
{
}

void GuildScript::OnMemberWitdrawMoney(Guild* /*guild*/, Player* /*player*/, uint64& /*amount*/, bool /*isRepair*/)
{
}

void GuildScript::OnMemberDepositMoney(Guild* /*guild*/, Player* /*player*/, uint64& /*amount*/)
{
}

void GuildScript::OnItemMove(Guild* /*guild*/, Player* /*player*/, Item* /*pItem*/, bool /*isSrcBank*/, uint8 /*srcContainer*/, uint8 /*srcSlotId*/, bool /*isDestBank*/,
    uint8 /*destContainer*/, uint8 /*destSlotId*/)
{
}

void GuildScript::OnEvent(Guild* /*guild*/, uint8 /*eventType*/, ObjectGuid::LowType /*playerGuid1*/, ObjectGuid::LowType /*playerGuid2*/, uint8 /*newRank*/)
{
}

void GuildScript::OnBankEvent(Guild* /*guild*/, uint8 /*eventType*/, uint8 /*tabId*/, ObjectGuid::LowType /*playerGuid*/, uint64 /*itemOrMoney*/, uint16 /*itemStackCount*/,
    uint8 /*destTabId*/)
{
}

GroupScript::GroupScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<GroupScript>::Instance()->AddScript(this);
}

GroupScript::~GroupScript() = default;

void GroupScript::OnAddMember(Group* /*group*/, ObjectGuid /*guid*/)
{
}

void GroupScript::OnInviteMember(Group* /*group*/, ObjectGuid /*guid*/)
{
}

void GroupScript::OnRemoveMember(Group* /*group*/, ObjectGuid /*guid*/, RemoveMethod /*method*/, ObjectGuid /*kicker*/, char const* /*reason*/)
{
}

void GroupScript::OnChangeLeader(Group* /*group*/, ObjectGuid /*newLeaderGuid*/, ObjectGuid /*oldLeaderGuid*/)
{
}

void GroupScript::OnDisband(Group* /*group*/)
{
}

AreaTriggerEntityScript::AreaTriggerEntityScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<AreaTriggerEntityScript>::Instance()->AddScript(this);
}

AreaTriggerEntityScript::~AreaTriggerEntityScript() = default;

AreaTriggerAI* AreaTriggerEntityScript::GetAI(AreaTrigger* /*at*/) const
{
    return nullptr;
}

ConversationScript::ConversationScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<ConversationScript>::Instance()->AddScript(this);
}

ConversationScript::~ConversationScript() = default;

void ConversationScript::OnConversationCreate(Conversation* /*conversation*/, Unit* /*creator*/)
{
}

void ConversationScript::OnConversationStart(Conversation* /*conversation*/ )
{
}

void ConversationScript::OnConversationLineStarted(Conversation* /*conversation*/, uint32 /*lineId*/, Player* /*sender*/)
{
}

void ConversationScript::OnConversationUpdate(Conversation* /*conversation*/, uint32 /*diff*/)
{
}

SceneScript::SceneScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<SceneScript>::Instance()->AddScript(this);
}

SceneScript::~SceneScript() = default;

void SceneScript::OnSceneStart(Player* /*player*/, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/)
{
}

void SceneScript::OnSceneTriggerEvent(Player* /*player*/, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& /*triggerName*/)
{
}

void SceneScript::OnSceneCancel(Player* /*player*/, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/)
{
}

void SceneScript::OnSceneComplete(Player* /*player*/, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/)
{
}

QuestScript::QuestScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<QuestScript>::Instance()->AddScript(this);
}

QuestScript::~QuestScript() = default;

void QuestScript::OnQuestStatusChange(Player* /*player*/, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus /*newStatus*/)
{
}

void QuestScript::OnAcknowledgeAutoAccept(Player* /*player*/, Quest const* /*quest*/)
{
}

void QuestScript::OnQuestObjectiveChange(Player* /*player*/, Quest const* /*quest*/, QuestObjective const& /*objective*/, int32 /*oldAmount*/, int32 /*newAmount*/)
{
}

WorldStateScript::WorldStateScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<WorldStateScript>::Instance()->AddScript(this);
}

WorldStateScript::~WorldStateScript() = default;

void WorldStateScript::OnValueChange(int32 /*worldStateId*/, int32 /*oldValue*/, int32 /*newValue*/, Map const* /*map*/)
{
}

EventScript::EventScript(char const* name)
    : ScriptObject(name)
{
    ScriptRegistry<EventScript>::Instance()->AddScript(this);
}

EventScript::~EventScript() = default;

void EventScript::OnTrigger(WorldObject* /*object*/, WorldObject* /*invoker*/, uint32 /*eventId*/)
{
}

// Specialize for each script type class like so:
template class TC_GAME_API ScriptRegistry<SpellScriptLoader>;
template class TC_GAME_API ScriptRegistry<ServerScript>;
template class TC_GAME_API ScriptRegistry<WorldScript>;
template class TC_GAME_API ScriptRegistry<FormulaScript>;
template class TC_GAME_API ScriptRegistry<WorldMapScript>;
template class TC_GAME_API ScriptRegistry<InstanceMapScript>;
template class TC_GAME_API ScriptRegistry<BattlegroundMapScript>;
template class TC_GAME_API ScriptRegistry<ItemScript>;
template class TC_GAME_API ScriptRegistry<CreatureScript>;
template class TC_GAME_API ScriptRegistry<GameObjectScript>;
template class TC_GAME_API ScriptRegistry<AreaTriggerScript>;
template class TC_GAME_API ScriptRegistry<BattlefieldScript>;
template class TC_GAME_API ScriptRegistry<OutdoorPvPScript>;
template class TC_GAME_API ScriptRegistry<CommandScript>;
template class TC_GAME_API ScriptRegistry<WeatherScript>;
template class TC_GAME_API ScriptRegistry<AuctionHouseScript>;
template class TC_GAME_API ScriptRegistry<ConditionScript>;
template class TC_GAME_API ScriptRegistry<VehicleScript>;
template class TC_GAME_API ScriptRegistry<DynamicObjectScript>;
template class TC_GAME_API ScriptRegistry<TransportScript>;
template class TC_GAME_API ScriptRegistry<AchievementScript>;
template class TC_GAME_API ScriptRegistry<AchievementCriteriaScript>;
template class TC_GAME_API ScriptRegistry<PlayerScript>;
template class TC_GAME_API ScriptRegistry<GuildScript>;
template class TC_GAME_API ScriptRegistry<GroupScript>;
template class TC_GAME_API ScriptRegistry<UnitScript>;
template class TC_GAME_API ScriptRegistry<AccountScript>;
template class TC_GAME_API ScriptRegistry<AreaTriggerEntityScript>;
template class TC_GAME_API ScriptRegistry<ConversationScript>;
template class TC_GAME_API ScriptRegistry<SceneScript>;
template class TC_GAME_API ScriptRegistry<QuestScript>;
template class TC_GAME_API ScriptRegistry<WorldStateScript>;
template class TC_GAME_API ScriptRegistry<EventScript>;
