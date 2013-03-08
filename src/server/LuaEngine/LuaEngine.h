#ifndef __ELUNA__H
#define __ELUNA__H
#include <string>
#include <map>
#include "LuaHooks.h"
#include "AccountMgr.h"
#include "Chat.h"
#include "Channel.h"
#include "Creature.h"
#include "GameObjectAI.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "QuestDef.h"
#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ArenaTeam.h"
#include "Vehicle.h"
#include "SystemConfig.h"
#include "MapManager.h"

using namespace std;

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};

struct LoadedScripts
{
    std::set<std::string> luaFiles;
};

template<class T>
struct ElunaRegister
{
    const char* name;
    int(*mfunc)(lua_State*, T*);
};

class LuaCreatureScript;
class LuaGameObjectScript;
class LuaWorldScript;

class Eluna
{
public:
    friend class ScriptMgr;
    static lua_State* LuaState;
    class LuaEventMap;
    static map<uint64, LuaEventMap*> LuaEventMaps; // Creature and gameobject timed events
    // Gets the event map saved for a guid
    static LuaEventMap* GetEvents(WorldObject* obj)
    {
        if (!obj)
            return NULL;
        map<uint64, LuaEventMap*>::iterator it = LuaEventMaps.find(obj->GetGUID());
        if (it != LuaEventMaps.end())
            return it->second;
        return NULL;
    }
    LuaCreatureScript* CreatureAI;
    LuaGameObjectScript* GameObjectAI;
    LuaWorldScript* WorldAI;

    typedef map<int, int> ElunaBindingMap;
    typedef UNORDERED_MAP<uint32, ElunaBindingMap> ElunaEntryMap;
    struct ElunaBind;
    map<int, vector<int> > ServerEventBindings;
    ElunaBind* CreatureEventBindings;
    ElunaBind* CreatureGossipBindings;
    ElunaBind* GameObjectEventBindings;
    ElunaBind* GameObjectGossipBindings;
    ElunaBind* ItemEventBindings;
    ElunaBind* ItemGossipBindings;
    ElunaBind* playerGossipBindings;
    
    void StartEluna(bool restart = false);
    static void report(lua_State*);
    void Register(uint8 reg, uint32 id, uint32 evt, int func);
    void BeginCall(int fReference);
    bool ExecuteCall(uint8 params, uint8 res);
    void EndCall(uint8 res);
    void RegisterGlobals(lua_State* L);
    void LoadDirectory(char* directory, LoadedScripts* scr);
    // Pushes
    void PushGUID(lua_State*, uint64); // Gets GUIDLow (uint32)
    void PushInteger(lua_State*, int);
    void PushUnsigned(lua_State*, uint32);
    void PushBoolean(lua_State*, bool);
    void PushFloat(lua_State*, float);
    void PushDouble(lua_State*, double);
    void PushString(lua_State*, const char*);
    void PushGroup(lua_State*, Group*);
    void PushGuild(lua_State*, Guild*);
    void PushUnit(lua_State*, Unit*);
    void PushGO(lua_State*, GameObject*);
    void PushQueryResult(lua_State*, QueryResult*);
    void PushAura(lua_State*, Aura*);
    void PushItem(lua_State*, Item*);
	void PushSpell(lua_State*, Spell*);
	void PushQuest(lua_State*, Quest const*);
    void PushPacket(lua_State*, WorldPacket*);
    // Checks
    Player * CHECK_PLAYER(lua_State* L, int narg);
    Unit * CHECK_UNIT(lua_State* L, int narg);
    Creature * CHECK_CREATURE(lua_State* L, int narg);
    GameObject* CHECK_OBJECT(lua_State* L, int narg);
    WorldPacket* CHECK_PACKET(lua_State* L, int narg);
    WorldObject* CHECK_WORLDOBJECT(lua_State* L, int narg);

    // Creates new binding stores
    Eluna()
    {
        LuaState = NULL;
        CreatureAI = NULL;
        GameObjectAI = NULL;
        WorldAI = NULL;

        for (int i = 0; i < SERVER_EVENT_COUNT; ++i)
        {
            vector<int> _vector;
            ServerEventBindings.insert(pair<int, vector<int> >(i, _vector));
        }
        CreatureEventBindings = new ElunaBind;
        CreatureGossipBindings = new ElunaBind;
        GameObjectEventBindings = new ElunaBind;
        GameObjectGossipBindings = new ElunaBind;
        ItemEventBindings = new ElunaBind;
        ItemGossipBindings = new ElunaBind;
        playerGossipBindings = new ElunaBind;
    }

    ~Eluna()
    {
        Eluna::LuaEventMap::LuaEventsResetAll(); // Unregisters and stops all timed events

        for (map<int, vector<int> >::iterator itr = ServerEventBindings.begin(); itr != ServerEventBindings.end(); ++itr)
        {
            for (vector<int>::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
                luaL_unref(LuaState, LUA_REGISTRYINDEX, (*it));
            itr->second.clear();
        }
        ServerEventBindings.clear();
        CreatureEventBindings->Clear();
        CreatureGossipBindings->Clear();
        GameObjectEventBindings->Clear();
        GameObjectGossipBindings->Clear();
        ItemEventBindings->Clear();
        ItemGossipBindings->Clear();
        playerGossipBindings->Clear();

        lua_close(LuaState); // Closing
    }

    struct ElunaBind
    {
        // unregisters all registered functions and clears all registered events from the bind maps (reset)
        void Clear()
        {
            for (ElunaEntryMap::iterator itr = Bindings.begin(); itr != Bindings.end(); ++itr)
            {
                for (ElunaBindingMap::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
                    luaL_unref(LuaState, LUA_REGISTRYINDEX, it->second);
                itr->second.clear();
            }
            Bindings.clear();
        }

        // Inserts a new registered event
        void Insert(uint32 entryId, uint32 eventId, int funcRef)
        {
            if (Bindings[entryId][eventId])
            {
                sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::A function is already registered for entry %u event %u", entryId, eventId);
                luaL_unref(LuaState, LUA_REGISTRYINDEX, funcRef); // free the unused ref
            }
            else
                Bindings[entryId][eventId] = funcRef;
        }

        // Gets the function ref of an entry for an event
        int GetBind(uint32 entryId, uint32 eventId)
        {
            ElunaEntryMap::iterator itr = Bindings.find(entryId);
            if (itr == Bindings.end())
                return 0;

            return itr->second[eventId];
        }

        // Gets the binding map containing all registered events with the function refs for the entry
        ElunaBindingMap* GetBindMap(uint32 entryId) 
        {
            ElunaEntryMap::iterator itr = Bindings.find(entryId);
            if (itr == Bindings.end())
                return NULL;

            return &itr->second;
        }

        ElunaEntryMap Bindings; // Binding store Bindings[entryId][eventId] = funcRef;
    };

    class LuaEventMap
    {
    public:
        LuaEventMap() { }
        ~LuaEventMap() { LuaEventsReset(); }

        struct eventData
        {
            int funcRef; uint32 delay; uint32 calls;
            eventData(int _funcRef, uint32 _delay, uint32 _calls) :
            funcRef(_funcRef), delay(_delay), calls(_calls) {}
        };

        typedef std::multimap<uint32, eventData> EventStore; // Not to use multimap? Can same function ref ID be used multiple times?

        virtual void OnLuaEvent(int funcRef, uint32 delay, uint32 calls) { }
        static void LuaEventsResetAll(); // Unregisters and stops all timed events

        void LuaEventsReset()
        {
            _time = 0;
            if (LuaEventsEmpty())
                return;
            for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
            {
                luaL_unref(LuaState, LUA_REGISTRYINDEX, itr->second.funcRef);
                ++itr;
            }
            _eventMap.clear();
        }

        void LuaEventsUpdate(uint32 time)
        {
            _time += time;
        }

        bool LuaEventsEmpty() const
        {
            return _eventMap.empty();
        }

        void LuaEventCreate(int funcRef, uint32 delay, uint32 calls)
        {
            _eventMap.insert(EventStore::value_type(_time + delay, eventData(funcRef, delay, calls)));
        }

        void LuaEventCancel(int funcRef)
        {
            if (LuaEventsEmpty())
                return;

            for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
            {
                if (funcRef == itr->second.funcRef)
                {
                    luaL_unref(LuaState, LUA_REGISTRYINDEX, itr->second.funcRef);
                    _eventMap.erase(itr++);
                }
                else
                    ++itr;
            }
        }

        void LuaEventsExecute()
        {
            if (LuaEventsEmpty())
                return;

            for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
            {
                if (itr->first > _time)
                {
                    ++itr;
                    continue;
                }

                OnLuaEvent(itr->second.funcRef, itr->second.delay, itr->second.calls);

                if (itr->second.calls != 1)
                {
                    if (itr->second.calls > 1)
                        itr->second.calls = itr->second.calls-1;
                    _eventMap.insert(EventStore::value_type(_time + itr->second.delay, itr->second));
                }
                _eventMap.erase(itr++);
            }
        }

    private:
        EventStore _eventMap;
        uint32 _time;
    };

protected:
    template<typename T>
    class ElunaTemplate
    {
    public:
        typedef int (*_funcptr)(lua_State* L, T* ptr);
        typedef struct { const char* name; _funcptr mfunc; } ElunaRegister;

        static void Register(lua_State* L)
        {
            lua_newtable(L);
            int methods = lua_gettop(L);

            luaL_newmetatable(L, GetTName<T>());
            int metatable = lua_gettop(L);

            // store method table in globals so that
            // scripts can add functions in Lua
            lua_pushvalue(L, methods);
            lua_setglobal(L, GetTName<T>());

            // hide metatable
            lua_pushvalue(L, methods);
            lua_setfield(L, metatable, "__metatable");

            lua_pushvalue(L, methods);
            lua_setfield(L, metatable, "__index");

            lua_pushcfunction(L, tostringT);
            lua_setfield(L, metatable, "__tostring");

            lua_pushcfunction(L, gcT);
            lua_setfield(L, metatable, "__gc");

            lua_newtable(L);
            lua_setmetatable(L, methods);

            // fill method table.
            if (!GetMethodTable<T>())
            {
                lua_pop(L, 2);
                return;
            }

            for (ElunaRegister* l = ((ElunaRegister*)GetMethodTable<T>()); l->name; ++l)
            {
                lua_pushstring(L, l->name);
                lua_pushlightuserdata(L, (void*)l);
                lua_pushcclosure(L, thunk, 1);
                lua_settable(L, methods);
            }

            lua_pop(L, 2);
        }

        static int push(lua_State* L, T* obj, bool gc = false)
        {
            if (!obj)
            {
                lua_pushnil(L);
                return lua_gettop(L);
            }
            luaL_getmetatable(L, GetTName<T>());
            if (lua_isnil(L, -1))
                luaL_error(L, "%s missing metatable", GetTName<T>());
            int idxMt = lua_gettop(L);
            T** ptrHold = (T**)lua_newuserdata(L, sizeof(T**));
            int ud = lua_gettop(L);
            if (ptrHold)
            {
                *ptrHold = obj;
                lua_pushvalue(L, idxMt);
                lua_setmetatable(L, -2);
                char name[32];
                tostring(name, obj);
                lua_getfield(L, LUA_REGISTRYINDEX, "DO NOT TRASH");
                if (lua_isnil(L, -1))
                {
                    luaL_newmetatable(L, "DO NOT TRASH");
                    lua_pop(L, 1);
                }
                lua_getfield(L, LUA_REGISTRYINDEX, "DO NOT TRASH");
                if (gc == false)
                {
                    lua_pushboolean(L, 1);
                    lua_setfield(L, -2, name);
                }
                lua_pop(L, 1);
            }
            lua_settop(L, ud);
            lua_replace(L, idxMt);
            lua_settop(L, idxMt);
            return idxMt;
        }

        static T* check(lua_State* L, int narg)
        {
            T** ptrHold = static_cast<T**>(lua_touserdata(L, narg));
            if (!ptrHold)
                return NULL;
            return *ptrHold;
        }

    private:
        static int thunk(lua_State* L)
        {
            T* obj = check(L, 1); // get self
            lua_remove(L, 1); // remove self
            ElunaRegister* l = static_cast<ElunaRegister*>(lua_touserdata(L, lua_upvalueindex(1)));
            return l->mfunc(L, obj);
        }

        static int gcT(lua_State* L)
        {
            T* obj = check(L, 1);
            if (!obj)
                return 0;
            lua_getfield(L, LUA_REGISTRYINDEX, "DO NO TRASH");
            if (lua_istable(L, -1))
            {
                char name[32];
                tostring(name, obj);
                lua_getfield(L, -1, std::string(name).c_str());
                if (lua_isnil(L, -1))
                {
                    delete obj;
                    obj = NULL;
                }
            }
            return 1;
        }

        static int tostringT(lua_State* L)
        {
            char buff[32];
            T** ptrHold = (T**)lua_touserdata(L, 1);
            T* obj = *ptrHold;
            sprintf(buff, "%p", obj);
            lua_pushfstring(L, "%s (%s)", GetTName<T>(), buff);
            return 1;
        }

        inline static void tostring(char* buff, void* obj)
        {
            sprintf(buff, "%p", obj);
        }

        static int index(lua_State* L)
        {
            lua_getglobal(L, GetTName<T>());
            const char* key = lua_tostring(L, 2);
            if (lua_istable(L, - 1))
            {
                lua_pushvalue(L, 2);
                lua_rawget(L, -2);
                if (lua_isnil(L, -1))
                {
                    lua_getmetatable(L, -2);
                    if (lua_istable(L, -1))
                    {
                        lua_getfield(L, -1, "__index");
                        if (lua_isfunction(L, -1))
                        {
                            lua_pushvalue(L, 1);
                            lua_pushvalue(L, 2);
                            lua_pcall(L, 2, 1, 0);
                        }
                        else if (lua_istable(L, -1))
                            lua_getfield(L, -1, key);
                        else
                            lua_pushnil(L);
                    }
                    else
                        lua_pushnil(L);
                }
                else if (lua_istable(L, -1))
                {
                    lua_pushvalue(L, 2);
                    lua_rawget(L, -2);
                }
            }
            else
                lua_pushnil(L);
            lua_insert(L, 1);
            lua_settop(L, 1);
            return 1;
        }
    };
};
#define sEluna ACE_Singleton<Eluna, ACE_Null_Mutex>::instance()

class LuaWorldScript : public WorldScript, public Eluna::LuaEventMap
{
public:
    LuaWorldScript() : WorldScript("SmartLuaWorldScript"), Eluna::LuaEventMap()
    {
    }

    void OnOpenStateChange(bool open)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_OPEN_STATE_CHANGE).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_OPEN_STATE_CHANGE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_OPEN_STATE_CHANGE);
            sEluna->PushBoolean(sEluna->LuaState, open);
            sEluna->ExecuteCall(2, 0);
        }
    }
    void OnConfigLoad(bool reload)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_CONFIG_LOAD).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_CONFIG_LOAD).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_CONFIG_LOAD);
            sEluna->PushBoolean(sEluna->LuaState, reload);
            sEluna->ExecuteCall(2, 0);
        }
    }
    void OnMotdChange(std::string& newMotd)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_MOTD_CHANGE).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_MOTD_CHANGE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_MOTD_CHANGE);
            sEluna->PushString(sEluna->LuaState, newMotd.c_str());
            sEluna->ExecuteCall(2, 0);
        }
    }
    void OnShutdownInitiate(ShutdownExitCode code, ShutdownMask mask)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN_INIT).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN_INIT).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_SHUTDOWN_INIT);
            sEluna->PushInteger(sEluna->LuaState, code);
            sEluna->PushInteger(sEluna->LuaState, mask);
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnShutdownCancel()
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN_CANCEL).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN_CANCEL).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_SHUTDOWN_CANCEL);
            sEluna->ExecuteCall(1, 0);
        }
    }
    void OnWorldUpdate(uint32 diff)
    {
        LuaEventsUpdate(diff);
        LuaEventsExecute();
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_UPDATE).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_UPDATE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_UPDATE);
            sEluna->PushUnsigned(sEluna->LuaState, diff);
            sEluna->ExecuteCall(2, 0);
        }
    }
    // executed when a  timed event fires
    void OnLuaEvent(int funcRef, uint32 delay, uint32 calls)
    {
        sEluna->BeginCall(funcRef);
        sEluna->PushUnsigned(sEluna->LuaState, funcRef);
        sEluna->PushUnsigned(sEluna->LuaState, delay);
        sEluna->PushUnsigned(sEluna->LuaState, calls);
        sEluna->ExecuteCall(3, 0);
    }
    void OnStartup()
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_STARTUP).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_STARTUP).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_STARTUP);
            sEluna->ExecuteCall(1, 0);
        }
    }
    void OnShutdown()
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_SHUTDOWN);
            sEluna->ExecuteCall(1, 0);
        }
    }
};

class LuaCreatureScript : public CreatureScript
{
public:
    bool IsDatabaseBound() const { return false; }

    LuaCreatureScript() : CreatureScript("SmartLuaCreatureScript") // Smart suppressing error @startup
    {
    }
    ~LuaCreatureScript()
    {
    }

    bool RegisterCreatureScript(uint32 id, uint32 evt, int functionRef)
    {
        if (!sObjectMgr->GetCreatureTemplate(id))
        {
            sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a creature with (ID: %d)!", id);
            return false;
        }

        sEluna->CreatureEventBindings->Insert(id, evt, functionRef);
        return true;
    }

    bool RegisterCreatureGossipScript(uint32 id, uint32 evt, int functionRef)
    {
        if (!sObjectMgr->GetCreatureTemplate(id))
        {
            sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a creature with (ID: %d)!", id);
            return false;
        }

        sEluna->CreatureGossipBindings->Insert(id, evt, functionRef);
        return true;
    }

    struct LuaCreatureAI : ScriptedAI, public Eluna::LuaEventMap
    {
        LuaCreatureAI(Creature* creature) : ScriptedAI(creature), Eluna::LuaEventMap()
        {
        }
        ~LuaCreatureAI()
        {
            sEluna->LuaEventMaps.erase(me->GetGUID());
        }

        //Called at World update tick
        void UpdateAI(uint32 diff)
        {
            ScriptedAI::UpdateAI(diff);
            LuaEventsUpdate(diff);
            LuaEventsExecute();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_AIUPDATE);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_AIUPDATE);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnsigned(sEluna->LuaState, diff);
            sEluna->ExecuteCall(3, 0);
        }

        // executed when a  timed event fires
        void OnLuaEvent(int funcRef, uint32 delay, uint32 calls)
        {
            sEluna->BeginCall(funcRef);
            sEluna->PushUnsigned(sEluna->LuaState, funcRef);
            sEluna->PushUnsigned(sEluna->LuaState, delay);
            sEluna->PushUnsigned(sEluna->LuaState, calls);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(4, 0);
        }

        //Called for reaction at enter to combat if not in combat yet (enemy can be NULL)
        //Called at creature aggro either by MoveInLOS or Attack Start
        void EnterCombat(Unit* target)
        {
            ScriptedAI::EnterCombat(target);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_ENTER_COMBAT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_ENTER_COMBAT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, target);
            sEluna->ExecuteCall(3, 0);
        }

        // Called at any Damage from any attacker (before damage apply)
        void DamageTaken(Unit* attacker, uint32& damage)
        {
            ScriptedAI::DamageTaken(attacker, damage);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_DAMAGE_TAKEN);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_DAMAGE_TAKEN);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, attacker);
            sEluna->PushUnsigned(sEluna->LuaState, damage);
            sEluna->ExecuteCall(4, 0);
        }

        //Called at creature death
        void JustDied(Unit* killer)
        {
            ScriptedAI::JustDied(killer);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_DIED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_DIED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, killer);
            sEluna->ExecuteCall(3, 0);
        }

        //Called at creature killing another unit
        void KilledUnit(Unit* victim)
        {
            ScriptedAI::KilledUnit(victim);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_TARGET_DIED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_TARGET_DIED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, victim);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when the creature summon successfully other creature
        void JustSummoned(Creature* summon)
        {
            ScriptedAI::JustSummoned(summon);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, summon);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when a summoned creature is despawned
        void SummonedCreatureDespawn(Creature* summon)
        {
            ScriptedAI::SummonedCreatureDespawn(summon);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, summon);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when hit by a spell
        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            ScriptedAI::SpellHit(caster, spell);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_HIT_BY_SPELL);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_HIT_BY_SPELL);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, caster);
            sEluna->PushUnsigned(sEluna->LuaState, spell->Id); // Pass spell object?
            sEluna->ExecuteCall(4, 0);
        }

        // Called when spell hits a target
        void SpellHitTarget(Unit* target, SpellInfo const* spell)
        {
            ScriptedAI::SpellHitTarget(target, spell);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPELL_HIT_TARGET);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SPELL_HIT_TARGET);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, target);
            sEluna->PushUnsigned(sEluna->LuaState, spell->Id); // Pass spell object?
            sEluna->ExecuteCall(4, 0);
        }

        //Called at waypoint reached or PointMovement end
        void MovementInform(uint32 type, uint32 id)
        {
            ScriptedAI::MovementInform(type, id);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_REACH_WP);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_REACH_WP);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnsigned(sEluna->LuaState, type);
            sEluna->PushUnsigned(sEluna->LuaState, id);
            sEluna->ExecuteCall(4, 0);
        }

        // Called when AI is temporarily replaced or put back when possess is applied or removed
        void OnPossess(bool apply)
        {
            ScriptedAI::OnPossess(apply);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_POSSESS);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_POSSESS);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushBoolean(sEluna->LuaState, apply);
            sEluna->ExecuteCall(3, 0);
        }

        //Called at creature reset either by death or evade
        void Reset()
        {
            ScriptedAI::Reset();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_RESET);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_RESET);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
        }

        // Called before EnterCombat even before the creature is in combat.
        void AttackStart(Unit* target)
        {
            ScriptedAI::AttackStart(target);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_PRE_COMBAT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_PRE_COMBAT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, target);
            sEluna->ExecuteCall(3, 0);
        }

        // Called in Creature::Update when deathstate = DEAD. Inherited classes may maniuplate the ability to respawn based on scripted events.
        bool CanRespawn()
        {
            ScriptedAI::CanRespawn();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CAN_RESPAWN);
            if (!bind)
                return true;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_CAN_RESPAWN);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
            return true;
        }

        // Called for reaction at stopping attack at no attackers or targets
        void EnterEvadeMode()
        {
            ScriptedAI::EnterEvadeMode();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_LEAVE_COMBAT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_LEAVE_COMBAT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
        }

        // Called when the creature is summoned successfully by other creature
        void IsSummonedBy(Unit* summoner)
        {
            ScriptedAI::IsSummonedBy(summoner);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SUMMONED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, summoner);
            sEluna->ExecuteCall(3, 0);
        }

        void SummonedCreatureDies(Creature* summon, Unit* killer)
        {
            ScriptedAI::SummonedCreatureDies(summon, killer);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, summon);
            sEluna->PushUnit(sEluna->LuaState, killer);
            sEluna->ExecuteCall(4, 0);
        }

        // Called when the creature is target of hostile action: swing, hostile spell landed, fear/etc)
        void AttackedBy(Unit* attacker)
        {
            ScriptedAI::AttackedBy(attacker);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_ATTACKED_AT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_ATTACKED_AT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, attacker);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when creature is spawned or respawned (for reseting variables)
        void JustRespawned()
        {
            ScriptedAI::JustRespawned();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPAWN);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SPAWN);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
        }

        void OnCharmed(bool apply)
        {
            ScriptedAI::OnCharmed(apply);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CHARMED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_CHARMED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushBoolean(sEluna->LuaState, apply);
            sEluna->ExecuteCall(3, 0);
        }

        // Called at reaching home after evade
        void JustReachedHome()
        {
            ScriptedAI::JustReachedHome();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_REACH_HOME);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_REACH_HOME);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
        }

        // Called at text emote receive from player
        void ReceiveEmote(Player* player, uint32 emoteId)
        {
            ScriptedAI::ReceiveEmote(player, emoteId);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_RECEIVE_EMOTE);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_RECEIVE_EMOTE);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushUnsigned(sEluna->LuaState, emoteId);
            sEluna->ExecuteCall(4, 0);
        }

        // Called when owner takes damage
        void OwnerAttackedBy(Unit* attacker)
        {
            ScriptedAI::OwnerAttackedBy(attacker);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_OWNER_ATTACKED_AT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_OWNER_ATTACKED_AT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, attacker);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when owner attacks something
        void OwnerAttacked(Unit* target)
        {
            ScriptedAI::OwnerAttacked(target);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_OWNER_ATTACKED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_OWNER_ATTACKED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, target);
            sEluna->ExecuteCall(3, 0);
        }

        // called when the corpse of this creature gets removed
        void CorpseRemoved(uint32& respawnDelay)
        {
            ScriptedAI::CorpseRemoved(respawnDelay);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CORPSE_REMOVED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_CORPSE_REMOVED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnsigned(sEluna->LuaState, respawnDelay);
            sEluna->ExecuteCall(3, 0);
        }

        void PassengerBoarded(Unit* passenger, int8 seatId, bool apply)
        {
            ScriptedAI::PassengerBoarded(passenger, seatId, apply);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_PASSANGER_BOARDED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_PASSANGER_BOARDED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, passenger);
            sEluna->PushInteger(sEluna->LuaState, seatId);
            sEluna->PushBoolean(sEluna->LuaState, apply);
            sEluna->ExecuteCall(5, 0);
        }

        void OnSpellClick(Unit* clicker)
        {
            ScriptedAI::OnSpellClick(clicker);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPELL_CLICK);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SPELL_CLICK);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, clicker);
            sEluna->ExecuteCall(3, 0);
        }

        void MoveInLineOfSight(Unit* who)
        {
            ScriptedAI::MoveInLineOfSight(who);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_MOVE_IN_LOS);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_MOVE_IN_LOS);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, who);
            sEluna->ExecuteCall(3, 0);
        }

        // Called if IsVisible(Unit* who) is true at each who move, reaction at visibility zone enter
        void MoveInLineOfSight_Safe(Unit* who)
        {
            ScriptedAI::MoveInLineOfSight_Safe(who);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, who);
            sEluna->ExecuteCall(3, 0);
        }
    };

    LuaCreatureAI* GetAI(Creature* creature)
    {
        if (!sEluna->CreatureEventBindings->GetBindMap(creature->GetEntry()))
            return NULL;

        LuaCreatureAI* luaCreatureAI = new LuaCreatureAI(creature);
        sEluna->LuaEventMaps[creature->GetGUID()] = luaCreatureAI;
        return luaCreatureAI;
    }
};

class LuaGameObjectScript : public GameObjectScript
{
public:
    bool IsDatabaseBound() const { return false; }

    LuaGameObjectScript() : GameObjectScript("SmartLuaGameObjectScript") // Smart suppressing error @startup
    {
    }
    ~LuaGameObjectScript()
    {
    }

    bool RegisterGameObjectScript(uint32 id, uint32 _event, int functionRef)
    {
        if (!sObjectMgr->GetGameObjectTemplate(id))
        {
            sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a gameobject with (ID: %u)!", id);
            return false;
        }

        sEluna->GameObjectEventBindings->Insert(id, _event, functionRef);
        return true;
    }

    bool RegisterGameObjectGossipScript(uint32 id, uint32 _event, int functionRef)
    {
        if (!sObjectMgr->GetGameObjectTemplate(id))
        {
            sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a gameobject with (ID: %u)!", id);
            return false;
        }

        sEluna->GameObjectGossipBindings->Insert(id, _event, functionRef);
        return true;
    }

    struct LuaGameObjectAI : public GameObjectAI, public Eluna::LuaEventMap
    {
        LuaGameObjectAI(GameObject* _go) : GameObjectAI(_go), Eluna::LuaEventMap()
        {
        }
        ~LuaGameObjectAI()
        {
            sEluna->LuaEventMaps.erase(go->GetGUID());
        }

        void UpdateAI(uint32 diff)
        {
            LuaEventsUpdate(diff);
            LuaEventsExecute();
            int bind = sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_AIUPDATE);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, GAMEOBJECT_EVENT_ON_AIUPDATE);
            sEluna->PushGO(sEluna->LuaState, go);
            sEluna->PushUnsigned(sEluna->LuaState, diff);
            sEluna->ExecuteCall(3, 0);
        }

        // executed when a timed event fires
        void OnLuaEvent(int funcRef, uint32 delay, uint32 calls)
        {
            sEluna->BeginCall(funcRef);
            sEluna->PushUnsigned(sEluna->LuaState, funcRef);
            sEluna->PushUnsigned(sEluna->LuaState, delay);
            sEluna->PushUnsigned(sEluna->LuaState, calls);
            sEluna->PushGO(sEluna->LuaState, go);
            sEluna->ExecuteCall(4, 0);
        }

        void Reset()
        {
            sEluna->BeginCall(sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_RESET));
            sEluna->PushInteger(sEluna->LuaState, GAMEOBJECT_EVENT_ON_RESET);
            sEluna->PushGO(sEluna->LuaState, go);
            sEluna->ExecuteCall(2, 0);
        }
    };

    LuaGameObjectAI* GetAI(GameObject* gameObject)
    {
        if (!sEluna->GameObjectEventBindings->GetBindMap(gameObject->GetEntry()))
            return NULL;

        LuaGameObjectAI* luaGameObjectAI = new LuaGameObjectAI(gameObject);
        sEluna->LuaEventMaps[gameObject->GetGUID()] = luaGameObjectAI;
        return luaGameObjectAI;
    }
};
#endif
