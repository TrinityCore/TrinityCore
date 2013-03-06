#ifndef __ELUNA__H
#define __ELUNA__H
#include <string>
#include <map>
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

class ElunaTemplate;
class ElunaScript;

struct LoadedScripts
{
    std::set<std::string> luaFiles;
};

enum REGISTER_TYPE
{
    REGTYPE_SERVER,
    REGTYPE_CREATURE,
    REGTYPE_CREATURE_GOSSIP,
    REGTYPE_GAMEOBJECT,
    REGTYPE_GAMEOBJECT_GOSSIP,
    REGTYPE_ITEM,
    REGTYPE_ITEM_GOSSIP,
    REGTYPE_PLAYER_GOSSIP,
    REGTYPE_COUNT
};

enum ServerEvents
{
    // Player
    PLAYER_EVENT_ON_CHARACTER_CREATE        =     1,            // Implemented
    PLAYER_EVENT_ON_CHARACTER_DELETE        =     2,            // Implemented
    PLAYER_EVENT_ON_LOGIN                   =     3,            // Implemented
    PLAYER_EVENT_ON_LOGOUT                  =     4,            // Implemented
    PLAYER_EVENT_ON_SPELL_CAST              =     5,            // Implemented
    PLAYER_EVENT_ON_KILL_PLAYER             =     6,            // Implemented
    PLAYER_EVENT_ON_KILL_CREATURE           =     7,            // Implemented
    PLAYER_EVENT_ON_KILLED_BY_CREATURE      =     8,            // Implemented
    PLAYER_EVENT_ON_DUEL_REQUEST            =     9,            // Implemented
    PLAYER_EVENT_ON_DUEL_START              =     10,           // Implemented
    PLAYER_EVENT_ON_DUEL_END                =     11,           // Implemented
    PLAYER_EVENT_ON_GIVE_XP                 =     12,           // Implemented
    PLAYER_EVENT_ON_LEVEL_CHANGE            =     13,           // Implemented -- The level is the old level
    PLAYER_EVENT_ON_MONEY_CHANGE            =     14,           // Implemented
    PLAYER_EVENT_ON_REPUTATION_CHANGE       =     15,           // Implemented
    PLAYER_EVENT_ON_TALENTS_CHANGE          =     16,           // Implemented
    PLAYER_EVENT_ON_TALENTS_RESET           =     17,           // Implemented
    PLAYER_EVENT_ON_CHAT                    =     18,           // Implemented
    PLAYER_EVENT_ON_WHISPER                 =     19,           // Implemented
    PLAYER_EVENT_ON_GROUP_CHAT              =     20,           // Implemented
    PLAYER_EVENT_ON_GUILD_CHAT              =     21,           // Implemented
    PLAYER_EVENT_ON_CHANNEL_CHAT            =     22,           // Implemented
    PLAYER_EVENT_ON_EMOTE                   =     23,           // Implemented -- Not triggered on any known emote
    PLAYER_EVENT_ON_TEXT_EMOTE              =     24,           // Implemented
    PLAYER_EVENT_ON_SAVE                    =     25,           // Implemented
    PLAYER_EVENT_ON_BIND_TO_INSTANCE        =     26,           // Implemented
    PLAYER_EVENT_ON_UPDATE_ZONE             =     27,           // Implemented
    PLAYER_EVENT_ON_MAP_CHANGE              =     28,           // Implemented

    // Guild
    GUILD_EVENT_ON_ADD_MEMBER               =     29,           // Implemented -- Commented out
    GUILD_EVENT_ON_REMOVE_MEMBER            =     30,           // Implemented -- Commented out
    GUILD_EVENT_ON_MOTD_CHANGE              =     31,           // Implemented -- Commented out
    GUILD_EVENT_ON_INFO_CHANGE              =     32,           // Implemented -- Commented out
    GUILD_EVENT_ON_CREATE                   =     33,           // Implemented -- Commented out
    GUILD_EVENT_ON_DISBAND                  =     34,           // Implemented -- Commented out
    GUILD_EVENT_ON_MONEY_WITHDRAW           =     35,           // Implemented -- Commented out
    GUILD_EVENT_ON_MONEY_DEPOSIT            =     36,           // Implemented -- Commented out
    GUILD_EVENT_ON_ITEM_MOVE                =     37,           // Implemented -- Commented out
    GUILD_EVENT_ON_EVENT                    =     38,           // Implemented -- Commented out
    GUILD_EVENT_ON_BANK_EVENT               =     39,           // Implemented -- Commented out

    // Server
    SERVER_EVENT_ON_NETWORK_START           =     40,           // Not Implemented
    SERVER_EVENT_ON_NETWORK_STOP            =     41,           // Not Implemented
    SERVER_EVENT_ON_SOCKET_OPEN             =     42,           // Not Implemented
    SERVER_EVENT_ON_SOCKET_CLOSE            =     43,           // Not Implemented
    SERVER_EVENT_ON_PACKET_RECEIVE          =     44,           // Not Implemented
    SERVER_EVENT_ON_PACKET_RECEIVE_UNKNOWN  =     45,           // Not Implemented
    SERVER_EVENT_ON_PACKET_SEND             =     46,           // Not Implemented

    // World
    WORLD_EVENT_ON_OPEN_STATE_CHANGE        =     47,           // Implemented
    WORLD_EVENT_ON_CONFIG_LOAD              =     48,           // Implemented
    WORLD_EVENT_ON_MOTD_CHANGE              =     49,           // Implemented
    WORLD_EVENT_ON_SHUTDOWN_INIT            =     50,           // Implemented
    WORLD_EVENT_ON_SHUTDOWN_CANCEL          =     51,           // Implemented
    WORLD_EVENT_ON_UPDATE                   =     52,           // Implemented
    WORLD_EVENT_ON_STARTUP                  =     53,           // Implemented -- Actual server start
    WORLD_EVENT_ON_SHUTDOWN                 =     54,           // Implemented

    // Eluna
    ELUNA_EVENT_ON_RESTART                  =     55,           // Implemented

    // Map
    MAP_EVENT_ON_CREATE                     =     56,           // Not Implemented
    MAP_EVENT_ON_DESTROY                    =     57,           // Not Implemented
    MAP_EVENT_ON_LOAD                       =     58,           // Not Implemented
    MAP_EVENT_ON_UNLOAD                     =     59,           // Not Implemented
    MAP_EVENT_ON_PLAYER_ENTER               =     60,           // Not Implemented
    MAP_EVENT_ON_PLAYER_LEAVE               =     61,           // Not Implemented
    MAP_EVENT_ON_UPDATE                     =     62,           // Not Implemented

    // Area trigger
    TRIGGER_EVENT_ON_TRIGGER                =     63,           // Implemented

    // Weather
    WEATHER_EVENT_ON_CHANGE                 =     64,           // Implemented - Add weather object?

    // Auction house
    AUCTION_EVENT_ON_ADD                    =     65,           // Not Implemented
    AUCTION_EVENT_ON_REMOVE                 =     66,           // Not Implemented
    AUCTION_EVENT_ON_SUCCESFUL              =     67,           // Not Implemented
    AUCTION_EVENT_ON_EXPIRE                 =     68,           // Not Implemented

    // Group
    GROUP_EVENT_ON_MEMBER_ADD               =     69,           // Implemented
    GROUP_EVENT_ON_MEMBER_INVITE            =     70,           // Implemented
    GROUP_EVENT_ON_MEMBER_REMOVE            =     71,           // Implemented
    GROUP_EVENT_ON_LEADER_CHANGE            =     72,           // Implemented
    GROUP_EVENT_ON_DISBAND                  =     73,           // Implemented

    SERVER_EVENT_COUNT
};

enum CreatureEvents
{
    CREATURE_EVENT_ON_ENTER_COMBAT                    = 1,      //Implemented
    CREATURE_EVENT_ON_LEAVE_COMBAT                    = 2,      //Implemented
    CREATURE_EVENT_ON_TARGET_DIED                     = 3,      //Implemented
    CREATURE_EVENT_ON_DIED                            = 4,      //Implemented
    CREATURE_EVENT_ON_SPAWN                           = 5,      //Implemented
    CREATURE_EVENT_ON_REACH_WP                        = 6,      //Implemented
    CREATURE_EVENT_ON_AIUPDATE                        = 7,      //Implemented
    CREATURE_EVENT_ON_RECEIVE_EMOTE                   = 8,      //Implemented
    CREATURE_EVENT_ON_DAMAGE_TAKEN                    = 9,      //Implemented
    CREATURE_EVENT_ON_PRE_COMBAT                      = 10,     //Implemented
    CREATURE_EVENT_ON_ATTACKED_AT                     = 11,     //Implemented
    CREATURE_EVENT_ON_OWNER_ATTACKED                  = 12,     //Implemented
    CREATURE_EVENT_ON_OWNER_ATTACKED_AT               = 13,     //Implemented
    CREATURE_EVENT_ON_HIT_BY_SPELL                    = 14,     //Implemented
    CREATURE_EVENT_ON_SPELL_HIT_TARGET                = 15,     //Implemented
    CREATURE_EVENT_ON_SPELL_CLICK                     = 16,     //Implemented
    CREATURE_EVENT_ON_CHARMED                         = 17,     //Implemented
    CREATURE_EVENT_ON_POSSESS                         = 18,     //Implemented
    CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE          = 19,     //Implemented
    CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN       = 20,     //Implemented
    CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED          = 21,     //Implemented
    CREATURE_EVENT_ON_SUMMONED                        = 22,     //Implemented
    CREATURE_EVENT_ON_RESET                           = 23,     //Implemented
    CREATURE_EVENT_ON_REACH_HOME                      = 24,     //Implemented
    CREATURE_EVENT_ON_CAN_RESPAWN                     = 25,     //Implemented
    CREATURE_EVENT_ON_CORPSE_REMOVED                  = 26,     //Implemented
    CREATURE_EVENT_ON_MOVE_IN_LOS                     = 27,     //Implemented
    CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS             = 28,     //Implemented
    CREATURE_EVENT_ON_PASSANGER_BOARDED               = 29,     //Implemented
    CREATURE_EVENT_ON_DUMMY_EFFECT                    = 30,     //Implemented
    CREATURE_EVENT_ON_QUEST_ACCEPT                    = 31,     //Implemented
    CREATURE_EVENT_ON_QUEST_SELECT                    = 32,     //Implemented
    CREATURE_EVENT_ON_QUEST_COMPLETE                  = 33,     //Implemented
    CREATURE_EVENT_ON_QUEST_REWARD                    = 34,     //Implemented
    CREATURE_EVENT_ON_DIALOG_STATUS                   = 35,     //Implemented
    CREATURE_EVENT_COUNT
};

enum GameObjectEvents
{
    GAMEOBJECT_EVENT_ON_AIUPDATE                    = 1,    // Implemented
    GAMEOBJECT_EVENT_ON_RESET                       = 2,    // Implemented
    GAMEOBJECT_EVENT_ON_DUMMY_EFFECT                = 3,    // Implemented
    GAMEOBJECT_EVENT_ON_QUEST_ACCEPT                = 4,    // Implemented
    GAMEOBJECT_EVENT_ON_QUEST_REWARD                = 5,    // Implemented
    GAMEOBJECT_EVENT_ON_DIALOG_STATUS               = 6,    // Implemented
    GAMEOBJECT_EVENT_ON_DESTROYED                   = 7,    // Implemented
    GAMEOBJECT_EVENT_ON_DAMAGED                     = 8,    // Implemented
    GAMEOBJECT_EVENT_ON_LOOT_STATE_CHANGE           = 9,    // Implemented
    GAMEOBJECT_EVENT_ON_GO_STATE_CHANGED            = 10,   // Implemented
    GAMEOBJECT_EVENT_COUNT
};

enum ItemEvents
{
    ITEM_EVENT_ON_DUMMY_EFFECT                      = 1,    // Implemented
    ITEM_EVENT_ON_USE                               = 2,    // Implemented
    ITEM_EVENT_ON_QUEST_ACCEPT                      = 3,    // Implemented
    ITEM_EVENT_ON_EXPIRE                            = 4,    // Implemented
    ITEM_EVENT_COUNT
};

enum GossipEvents
{
    GOSSIP_EVENT_ON_HELLO = 1,
    GOSSIP_EVENT_ON_SELECT = 2,
    GOSSIP_EVENT_COUNT
};

template<class T>
struct ElunaRegister
{
    const char* name;
    int(*mfunc)(lua_State*, T*);
};

template<typename T> ElunaRegister<T>* GetMethodTable();
template<typename T> const char* GetTName();

class Eluna
{
    friend class ElunaScript;
    friend class ScriptMgr;
    static Eluna* LuaEngine;
    static ElunaScript* Script;

public:
    static Eluna* get() { return LuaEngine; }
    static ElunaScript* getScript() { return Script; }

    typedef map<int, int> ElunaBindingMap;
    typedef UNORDERED_MAP<uint32, ElunaBindingMap> ElunaEntryMap;

    struct ElunaBind
    {
        // unregisters all registered functions and clears all registered events from the bind maps (reset)
        void Clear()
        {
            for (ElunaEntryMap::iterator itr = Bindings.begin(); itr != Bindings.end(); ++itr)
            {
                for (ElunaBindingMap::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
                    luaL_unref(get()->LuaState, LUA_REGISTRYINDEX, it->second);
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
                luaL_unref(get()->LuaState, LUA_REGISTRYINDEX, funcRef); // free the unused ref
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
    // Binding stores
    map<int, vector<int> > ServerEventBindings;
    ElunaBind* CreatureEventBindings;
    ElunaBind* CreatureGossipBindings;
    ElunaBind* GameObjectEventBindings;
    ElunaBind* GameObjectGossipBindings;
    ElunaBind* ItemEventBindings;
    ElunaBind* ItemGossipBindings;
    ElunaBind* playerGossipBindings;

    // Creates new binding stores
    Eluna()
    {
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
        LuaEventMap::LuaEventsResetAll(); // Unregisters and stops all timed events

        for (map<int, vector<int> >::iterator itr = ServerEventBindings.begin(); itr != ServerEventBindings.end(); ++itr)
        {
            for (vector<int>::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
                luaL_unref(get()->LuaState, LUA_REGISTRYINDEX, (*it));
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

        lua_close(get()->LuaState); // Closing
    }

    lua_State* LuaState;

    void StartEluna();
    void Register(uint8 reg, uint32 id, uint32 evt, int func);

    static void report(lua_State*);

    void BeginCall(int fReference)
    {
        lua_settop(LuaState, 0); //stack should be empty
        lua_rawgeti(LuaState, LUA_REGISTRYINDEX, (fReference));
    }

    bool ExecuteCall(uint8 params, uint8 res)
    {
        bool ret = true;
        int top = lua_gettop(LuaState);
        if (strcmp(luaL_typename(LuaState,top-params), "function") )
        {
            ret = false;
            if (params > 0)
            {
                for (int i = top; i >= (top-params); i--)
                {
                    if (!lua_isnone(LuaState, i) )
                        lua_remove(LuaState, i);
                }
            }
        }
        else
        {
            if (lua_pcall(LuaState,params,res,0) )
            {
                report(LuaState);
                ret = false;
            }
        }
        return ret;
    }

    void EndCall(uint8 res)
    {
        for (int i = res; i > 0; i--)
        {
            if (!lua_isnone(LuaState,res))
                lua_remove(LuaState,res);
        }
    }
    static void Init();
    static void Restart();
    void RegisterGlobals(lua_State* L);
    void LoadDirectory(char* directory, LoadedScripts* scr);
    // Push
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
    Player * CHECK_PLAYER(lua_State* L, int narg)
    {
        if (!L)
            return ElunaTemplate<Player>::check(LuaState, narg);
        else
            return ElunaTemplate<Player>::check(L, narg);
    }

    Unit * CHECK_UNIT(lua_State* L, int narg)
    {
        if (!L)
            return ElunaTemplate<Unit>::check(LuaState, narg);
        else
            return ElunaTemplate<Unit>::check(L, narg);
    }

    Creature * CHECK_CREATURE(lua_State* L, int narg)
    {
        if (!L)
            return ElunaTemplate<Creature>::check(LuaState, narg);
        else
            return ElunaTemplate<Creature>::check(L, narg);
    }

    GameObject* CHECK_OBJECT(lua_State* L, int narg)
    {
        if (!L)
            return ElunaTemplate<GameObject>::check(LuaState, narg);
        else
            return ElunaTemplate<GameObject>::check(L, narg);
    }

    WorldPacket* CHECK_PACKET(lua_State* L, int narg)
    {
        if (!L)
            return ElunaTemplate<WorldPacket>::check(LuaState, narg);
        else
            return ElunaTemplate<WorldPacket>::check(L, narg);
    }

    WorldObject* CHECK_WORLDOBJECT(lua_State* L, int narg)
    {
        if (!L)
            return ElunaTemplate<WorldObject>::check(LuaState, narg);
        else
            return ElunaTemplate<WorldObject>::check(L, narg);
    }

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

public:
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
                luaL_unref(get()->LuaState, LUA_REGISTRYINDEX, itr->second.funcRef);
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
                    luaL_unref(get()->LuaState, LUA_REGISTRYINDEX, itr->second.funcRef);
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

public:
    class LuaWorldScript : public WorldScript, public LuaEventMap
    {
    public:
        LuaWorldScript() : WorldScript("SmartLuaWorldScript"), LuaEventMap() {}

        // Called on every world tick (don't execute too heavy code here).
        void OnUpdate(uint32 diff)
        {
            LuaEventsUpdate(diff);
            LuaEventsExecute();
            for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_UPDATE).begin();
                itr != Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_UPDATE).end(); ++itr)
            {
                Eluna::get()->BeginCall((*itr));
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, WORLD_EVENT_ON_UPDATE);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, diff);
                Eluna::get()->ExecuteCall(2, 0);
            }
        }

        // executed when a  timed event fires
        void OnLuaEvent(int funcRef, uint32 delay, uint32 calls)
        {
            Eluna::get()->BeginCall(funcRef);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, funcRef);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, delay);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, calls);
            Eluna::get()->ExecuteCall(3, 0);
        }

        // Called when the open/closed state of the world changes.
        void OnOpenStateChange(bool open)
        {
            for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_OPEN_STATE_CHANGE).begin();
                itr != Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_OPEN_STATE_CHANGE).end(); ++itr)
            {
                Eluna::get()->BeginCall((*itr));
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, WORLD_EVENT_ON_OPEN_STATE_CHANGE);
                Eluna::get()->PushBoolean(Eluna::get()->LuaState, open);
                Eluna::get()->ExecuteCall(2, 0);
            }
        }

        // Called after the world configuration is (re)loaded.
        void OnConfigLoad(bool reload)
        {
            for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_CONFIG_LOAD).begin();
                itr != Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_CONFIG_LOAD).end(); ++itr)
            {
                Eluna::get()->BeginCall((*itr));
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, WORLD_EVENT_ON_CONFIG_LOAD);
                Eluna::get()->PushBoolean(Eluna::get()->LuaState, reload);
                Eluna::get()->ExecuteCall(2, 0);
            }
        }

        // Called before the message of the day is changed.
        void OnMotdChange(std::string& newMotd)
        {
            for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_MOTD_CHANGE).begin();
                itr != Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_MOTD_CHANGE).end(); ++itr)
            {
                Eluna::get()->BeginCall((*itr));
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, WORLD_EVENT_ON_MOTD_CHANGE);
                Eluna::get()->PushString(Eluna::get()->LuaState, newMotd.c_str());
                Eluna::get()->ExecuteCall(2, 0);
            }
        }

        // Called when a world shutdown is initiated.
        void OnShutdownInitiate(ShutdownExitCode code, ShutdownMask mask)
        {
            for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN_INIT).begin();
                itr != Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN_INIT).end(); ++itr)
            {
                Eluna::get()->BeginCall((*itr));
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, WORLD_EVENT_ON_SHUTDOWN_INIT);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, code);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, mask);
                Eluna::get()->ExecuteCall(3, 0);
            }
        }

        // Called when a world shutdown is cancelled.
        void OnShutdownCancel()
        {
            for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN_CANCEL).begin();
                itr != Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN_CANCEL).end(); ++itr)
            {
                Eluna::get()->BeginCall((*itr));
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, WORLD_EVENT_ON_SHUTDOWN_CANCEL);
                Eluna::get()->ExecuteCall(1, 0);
            }
        }

        // Called when the world is started.
        void OnStartup()
        {
            for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_STARTUP).begin();
                itr != Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_STARTUP).end(); ++itr)
            {
                Eluna::get()->BeginCall((*itr));
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, WORLD_EVENT_ON_STARTUP);
                Eluna::get()->ExecuteCall(1, 0);
            }
        }

        // Called when the world is actually shut down.
        void OnShutdown()
        {
            for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN).begin();
                itr != Eluna::get()->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN).end(); ++itr)
            {
                Eluna::get()->BeginCall((*itr));
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, WORLD_EVENT_ON_SHUTDOWN);
                Eluna::get()->ExecuteCall(1, 0);
            }
        }
    };

public:
    set<LuaEventMap*> scriptsToClear; // Creature and gameobject timed events

public:
    class LuaCreatureScript : CreatureScript
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

            get()->CreatureEventBindings->Insert(id, evt, functionRef);
            return true;
        }

        bool RegisterCreatureGossipScript(uint32 id, uint32 evt, int functionRef)
        {
            if (!sObjectMgr->GetCreatureTemplate(id))
            {
                sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a creature with (ID: %d)!", id);
                return false;
            }

            get()->CreatureGossipBindings->Insert(id, evt, functionRef);
            return true;
        }

        struct LuaCreatureAI : ScriptedAI, public LuaEventMap
        {
            LuaCreatureAI(Creature* creature) : ScriptedAI(creature), LuaEventMap()
            {
            }
            ~LuaCreatureAI()
            {
                Eluna::get()->scriptsToClear.erase(this);
            }

            //Called at World update tick
            void UpdateAI(uint32 diff)
            {
                ScriptedAI::UpdateAI(diff);
                LuaEventsUpdate(diff);
                LuaEventsExecute();
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_AIUPDATE);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_AIUPDATE);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, diff);
                Eluna::get()->ExecuteCall(3, 0);
            }

            // executed when a  timed event fires
            void OnLuaEvent(int funcRef, uint32 delay, uint32 calls)
            {
                Eluna::get()->BeginCall(funcRef);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, funcRef);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, delay);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, calls);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->ExecuteCall(4, 0);
            }

            //Called for reaction at enter to combat if not in combat yet (enemy can be NULL)
            //Called at creature aggro either by MoveInLOS or Attack Start
            void EnterCombat(Unit* target)
            {
                ScriptedAI::EnterCombat(target);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_ENTER_COMBAT);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_ENTER_COMBAT);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, target);
                Eluna::get()->ExecuteCall(3, 0);
            }

            // Called at any Damage from any attacker (before damage apply)
            void DamageTaken(Unit* attacker, uint32& damage)
            {
                ScriptedAI::DamageTaken(attacker, damage);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_DAMAGE_TAKEN);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_DAMAGE_TAKEN);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, attacker);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, damage);
                Eluna::get()->ExecuteCall(4, 0);
            }

            //Called at creature death
            void JustDied(Unit* killer)
            {
                ScriptedAI::JustDied(killer);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_DIED);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_DIED);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, killer);
                Eluna::get()->ExecuteCall(3, 0);
            }

            //Called at creature killing another unit
            void KilledUnit(Unit* victim)
            {
                ScriptedAI::KilledUnit(victim);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_TARGET_DIED);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_TARGET_DIED);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, victim);
                Eluna::get()->ExecuteCall(3, 0);
            }

            // Called when the creature summon successfully other creature
            void JustSummoned(Creature* summon)
            {
                ScriptedAI::JustSummoned(summon);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, summon);
                Eluna::get()->ExecuteCall(3, 0);
            }

            // Called when a summoned creature is despawned
            void SummonedCreatureDespawn(Creature* summon)
            {
                ScriptedAI::SummonedCreatureDespawn(summon);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, summon);
                Eluna::get()->ExecuteCall(3, 0);
            }

            // Called when hit by a spell
            void SpellHit(Unit* caster, SpellInfo const* spell)
            {
                ScriptedAI::SpellHit(caster, spell);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_HIT_BY_SPELL);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_HIT_BY_SPELL);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, caster);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, spell->Id); // Pass spell object?
                Eluna::get()->ExecuteCall(4, 0);
            }

            // Called when spell hits a target
            void SpellHitTarget(Unit* target, SpellInfo const* spell)
            {
                ScriptedAI::SpellHitTarget(target, spell);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPELL_HIT_TARGET);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_SPELL_HIT_TARGET);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, target);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, spell->Id); // Pass spell object?
                Eluna::get()->ExecuteCall(4, 0);
            }

            //Called at waypoint reached or PointMovement end
            void MovementInform(uint32 type, uint32 id)
            {
                ScriptedAI::MovementInform(type, id);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_REACH_WP);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_REACH_WP);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, type);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, id);
                Eluna::get()->ExecuteCall(4, 0);
            }

            // Called when AI is temporarily replaced or put back when possess is applied or removed
            void OnPossess(bool apply)
            {
                ScriptedAI::OnPossess(apply);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_POSSESS);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_POSSESS);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushBoolean(Eluna::get()->LuaState, apply);
                Eluna::get()->ExecuteCall(3, 0);
            }

            //Called at creature reset either by death or evade
            void Reset()
            {
                ScriptedAI::Reset();
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_RESET);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_RESET);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->ExecuteCall(2, 0);
            }

            // Called before EnterCombat even before the creature is in combat.
            void AttackStart(Unit* target)
            {
                ScriptedAI::AttackStart(target);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_PRE_COMBAT);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_PRE_COMBAT);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, target);
                Eluna::get()->ExecuteCall(3, 0);
            }

            // Called in Creature::Update when deathstate = DEAD. Inherited classes may maniuplate the ability to respawn based on scripted events.
            bool CanRespawn()
            {
                ScriptedAI::CanRespawn();
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CAN_RESPAWN);
                if (!bind)
                    return true;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_CAN_RESPAWN);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->ExecuteCall(2, 0);
                return true;
            }

            // Called for reaction at stopping attack at no attackers or targets
            void EnterEvadeMode()
            {
                ScriptedAI::EnterEvadeMode();
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_LEAVE_COMBAT);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_LEAVE_COMBAT);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->ExecuteCall(2, 0);
            }

            // Called when the creature is summoned successfully by other creature
            void IsSummonedBy(Unit* summoner)
            {
                ScriptedAI::IsSummonedBy(summoner);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_SUMMONED);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, summoner);
                Eluna::get()->ExecuteCall(3, 0);
            }

            void SummonedCreatureDies(Creature* summon, Unit* killer)
            {
                ScriptedAI::SummonedCreatureDies(summon, killer);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, summon);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, killer);
                Eluna::get()->ExecuteCall(4, 0);
            }

            // Called when the creature is target of hostile action: swing, hostile spell landed, fear/etc)
            void AttackedBy(Unit* attacker)
            {
                ScriptedAI::AttackedBy(attacker);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_ATTACKED_AT);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_ATTACKED_AT);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, attacker);
                Eluna::get()->ExecuteCall(3, 0);
            }

            // Called when creature is spawned or respawned (for reseting variables)
            void JustRespawned()
            {
                ScriptedAI::JustRespawned();
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPAWN);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_SPAWN);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->ExecuteCall(2, 0);
            }

            void OnCharmed(bool apply)
            {
                ScriptedAI::OnCharmed(apply);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CHARMED);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_CHARMED);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushBoolean(Eluna::get()->LuaState, apply);
                Eluna::get()->ExecuteCall(3, 0);
            }

            // Called at reaching home after evade
            void JustReachedHome()
            {
                ScriptedAI::JustReachedHome();
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_REACH_HOME);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_REACH_HOME);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->ExecuteCall(2, 0);
            }

            // Called at text emote receive from player
            void ReceiveEmote(Player* player, uint32 emoteId)
            {
                ScriptedAI::ReceiveEmote(player, emoteId);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_RECEIVE_EMOTE);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_RECEIVE_EMOTE);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, emoteId);
                Eluna::get()->ExecuteCall(4, 0);
            }

            // Called when owner takes damage
            void OwnerAttackedBy(Unit* attacker)
            {
                ScriptedAI::OwnerAttackedBy(attacker);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_OWNER_ATTACKED_AT);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_OWNER_ATTACKED_AT);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, attacker);
                Eluna::get()->ExecuteCall(3, 0);
            }

            // Called when owner attacks something
            void OwnerAttacked(Unit* target)
            {
                ScriptedAI::OwnerAttacked(target);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_OWNER_ATTACKED);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_OWNER_ATTACKED);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, target);
                Eluna::get()->ExecuteCall(3, 0);
            }

            // called when the corpse of this creature gets removed
            void CorpseRemoved(uint32& respawnDelay)
            {
                ScriptedAI::CorpseRemoved(respawnDelay);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CORPSE_REMOVED);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_CORPSE_REMOVED);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, respawnDelay);
                Eluna::get()->ExecuteCall(3, 0);
            }

            void PassengerBoarded(Unit* passenger, int8 seatId, bool apply)
            {
                ScriptedAI::PassengerBoarded(passenger, seatId, apply);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_PASSANGER_BOARDED);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_PASSANGER_BOARDED);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, passenger);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, seatId);
                Eluna::get()->PushBoolean(Eluna::get()->LuaState, apply);
                Eluna::get()->ExecuteCall(5, 0);
            }

            void OnSpellClick(Unit* clicker)
            {
                ScriptedAI::OnSpellClick(clicker);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPELL_CLICK);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_SPELL_CLICK);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, clicker);
                Eluna::get()->ExecuteCall(3, 0);
            }

            void MoveInLineOfSight(Unit* who)
            {
                ScriptedAI::MoveInLineOfSight(who);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_MOVE_IN_LOS);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_MOVE_IN_LOS);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, who);
                Eluna::get()->ExecuteCall(3, 0);
            }

            // Called if IsVisible(Unit* who) is true at each who move, reaction at visibility zone enter
            void MoveInLineOfSight_Safe(Unit* who)
            {
                ScriptedAI::MoveInLineOfSight_Safe(who);
                int bind = Eluna::get()->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, me);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, who);
                Eluna::get()->ExecuteCall(3, 0);
            }
        };

        LuaCreatureAI* GetAI(Creature* creature)
        {
            if (!Eluna::get()->CreatureEventBindings->GetBindMap(creature->GetEntry()))
                return NULL;

            LuaCreatureAI* luaCreatureAI = new LuaCreatureAI(creature);
            Eluna::get()->scriptsToClear.insert(luaCreatureAI);
            return luaCreatureAI;
        }
    };

public:
    class LuaGameObjectScript : GameObjectScript
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

            Eluna::get()->GameObjectEventBindings->Insert(id, _event, functionRef);
            return true;
        }

        bool RegisterGameObjectGossipScript(uint32 id, uint32 _event, int functionRef)
        {
            if (!sObjectMgr->GetGameObjectTemplate(id))
            {
                sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a gameobject with (ID: %u)!", id);
                return false;
            }

            Eluna::get()->GameObjectGossipBindings->Insert(id, _event, functionRef);
            return true;
        }

        struct LuaGameObjectAI : GameObjectAI, public LuaEventMap
        {
            LuaGameObjectAI(GameObject* _go) : GameObjectAI(_go), LuaEventMap()
            {
            }
            ~LuaGameObjectAI()
            {
                Eluna::get()->scriptsToClear.erase(this);
            }

            void UpdateAI(uint32 diff)
            {
                LuaEventsUpdate(diff);
                LuaEventsExecute();
                int bind = Eluna::get()->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_AIUPDATE);
                if (!bind)
                    return;
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushInteger(Eluna::get()->LuaState, GAMEOBJECT_EVENT_ON_AIUPDATE);
                Eluna::get()->PushGO(Eluna::get()->LuaState, go);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, diff);
                Eluna::get()->ExecuteCall(3, 0);
            }

            // executed when a timed event fires
            void OnLuaEvent(int funcRef, uint32 delay, uint32 calls)
            {
                Eluna::get()->BeginCall(funcRef);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, funcRef);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, delay);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, calls);
                Eluna::get()->PushGO(Eluna::get()->LuaState, go);
                Eluna::get()->ExecuteCall(4, 0);
            }

            void Reset()
            {
                Eluna::get()->BeginCall(Eluna::get()->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_RESET));
                Eluna::get()->PushInteger(Eluna::get()->LuaState, GAMEOBJECT_EVENT_ON_RESET);
                Eluna::get()->PushGO(Eluna::get()->LuaState, go);
                Eluna::get()->ExecuteCall(2, 0);
            }
        };

        LuaGameObjectAI* GetAI(GameObject* gameObject)
        {
            if (!Eluna::get()->GameObjectEventBindings->GetBindMap(gameObject->GetEntry()))
                return NULL;

            LuaGameObjectAI* luaGameObjectAI = new LuaGameObjectAI(gameObject);
            Eluna::get()->scriptsToClear.insert(luaGameObjectAI);
            return luaGameObjectAI;
        }
    };
};

#define sLuaCreatureScript ACE_Singleton<Eluna::LuaCreatureScript, ACE_Null_Mutex>::instance()
#define sLuaGameObjectScript ACE_Singleton<Eluna::LuaGameObjectScript, ACE_Null_Mutex>::instance()

class ElunaScript
{
public:
    static ElunaScript* get()
    {
        return Eluna::Script;
    }

    ElunaScript()
    {
    }

    ~ElunaScript()
    {
    }

    /* Item & player Gossip */
    void HandleGossipSelectOption(Player* player, uint64 guid, uint32 sender, uint32 action, std::string code, uint32 menuId)
    {
        if (!player || !player->IsInWorld() || !player->isAlive() || player->GetCharmerGUID())
            return;

        if (player->HasUnitState(UNIT_STATE_DIED))
            player->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);
        player->PlayerTalkClass->ClearMenus();

        if (IS_ITEM_GUID(guid))
        {
            Item* item = player->GetItemByGuid(guid);
            if (!item)
                return;

            int bind = Eluna::get()->ItemGossipBindings->GetBind(item->GetEntry(), GOSSIP_EVENT_ON_SELECT);
            if (bind)
            {
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, GOSSIP_EVENT_ON_SELECT);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
                Eluna::get()->PushItem(Eluna::get()->LuaState, item);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, sender);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, action);
                if (code.empty())
                    lua_pushnil(Eluna::get()->LuaState);
                else
                    Eluna::get()->PushString(Eluna::get()->LuaState, code.c_str());
                Eluna::get()->ExecuteCall(6, 0);
            }
        }
        else if (IS_PLAYER_GUID(guid))
        {
            if (player->GetGUID() != guid)
                return;

            int bind = Eluna::get()->playerGossipBindings->GetBind(menuId, GOSSIP_EVENT_ON_SELECT);
            if (bind)
            {
                Eluna::get()->BeginCall(bind);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, GOSSIP_EVENT_ON_SELECT);
                Eluna::get()->PushUnit(Eluna::get()->LuaState, player); // receiver
                Eluna::get()->PushUnit(Eluna::get()->LuaState, player); // sender, just not to mess up the amount of args.
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, sender);
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, action);
                if (code.empty())
                    lua_pushnil(Eluna::get()->LuaState);
                else
                    Eluna::get()->PushString(Eluna::get()->LuaState, code.c_str());
                Eluna::get()->PushUnsigned(Eluna::get()->LuaState, menuId);
                Eluna::get()->ExecuteCall(7, 0);
            }
        }
    }

    bool OnDummyEffect(uint32 eventId, Unit* caster, uint32 spellId, SpellEffIndex effIndex, Item* target)
    {
        int bind = Eluna::get()->ItemEventBindings->GetBind(target->GetEntry(), eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, caster);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, spellId);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, effIndex);
        Eluna::get()->PushItem(Eluna::get()->LuaState, target);
        Eluna::get()->ExecuteCall(5, 0);
        return true;
    }

    bool OnQuestAccept(uint32 eventId, Player* player, Item* item, Quest const* quest)
    {
        int bind = Eluna::get()->ItemEventBindings->GetBind(item->GetEntry(), eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushItem(Eluna::get()->LuaState, item);
        Eluna::get()->PushQuest(Eluna::get()->LuaState, quest);
        Eluna::get()->ExecuteCall(4, 0);
        return true;
    }

    bool OnItemExpire(uint32 eventId, Player* player, ItemTemplate const* proto)
    {
        int bind = Eluna::get()->ItemEventBindings->GetBind(proto->ItemId, eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, proto->ItemId);
        Eluna::get()->ExecuteCall(3, 0);
        return true;
    }

    bool OnItemUse(uint32 eventId, Player* player, Item* item, SpellCastTargets const& targets)
    {
        int bind1 = Eluna::get()->ItemGossipBindings->GetBind(item->GetEntry(), GOSSIP_EVENT_ON_HELLO);
        int bind2 = Eluna::get()->ItemEventBindings->GetBind(item->GetEntry(), eventId);
        if (!bind1 && !bind2)
            return false;
        if (bind1)
        {
            player->PlayerTalkClass->ClearMenus();
            Eluna::get()->BeginCall(bind1);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushItem(Eluna::get()->LuaState, item);
            Eluna::get()->ExecuteCall(3, 0);
        }
        if (bind2)
        {
            Eluna::get()->BeginCall(bind2);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushItem(Eluna::get()->LuaState, item);
            if (GameObject* target = targets.GetGOTarget())
                Eluna::get()->PushGO(Eluna::get()->LuaState, target);
            else if (Item* target = targets.GetItemTarget())
                Eluna::get()->PushItem(Eluna::get()->LuaState, target);
            else if (Unit* target = targets.GetUnitTarget())
                Eluna::get()->PushUnit(Eluna::get()->LuaState, target);
            else
                lua_pushnil(Eluna::get()->LuaState);
            Eluna::get()->ExecuteCall(4, 0);
        }
        return true;
    }

    bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, string& msg)
    {
        bool Result = true;
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushString(Eluna::get()->LuaState, msg.c_str());
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, type);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, lang);
            if (Eluna::get()->ExecuteCall(5, 1))
            {
                lua_State* L = Eluna::get()->LuaState;
                if (!lua_isnoneornil(L, 1) && !lua_toboolean(L, 1))
                    Result = false;
                Eluna::get()->EndCall(1);
            }
        }
        return Result;
    }

    void OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, string& msg, Player* receiver)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushString(Eluna::get()->LuaState, msg.c_str());
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, type);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, lang);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, receiver);
            Eluna::get()->ExecuteCall(6, 0);
        }
    }

    bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, string& msg, Group* group)
    {
        bool Result = true;
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushString(Eluna::get()->LuaState, msg.c_str());
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, type);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, lang);
            Eluna::get()->PushGroup(Eluna::get()->LuaState, group);
            if (Eluna::get()->ExecuteCall(6, 1))
            {
                lua_State* L = Eluna::get()->LuaState;
                if (!lua_isnoneornil(L, 1) && !lua_toboolean(L, 1))
                    Result = false;
                Eluna::get()->EndCall(1);
            }
        }
        return Result;
    }

    bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, string& msg, Guild* guild)
    {
        bool Result = true;
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushString(Eluna::get()->LuaState, msg.c_str());
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, type);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, lang);
            Eluna::get()->PushGuild(Eluna::get()->LuaState, guild);
            if (Eluna::get()->ExecuteCall(6, 1))
            {
                lua_State* L = Eluna::get()->LuaState;
                if (!lua_isnoneornil(L, 1) && !lua_toboolean(L, 1))
                    Result = false;
                Eluna::get()->EndCall(1);
            }
        }
        return Result;
    }

    bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, string& msg, Channel* channel)
    {
        bool Result = true;
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushString(Eluna::get()->LuaState, msg.c_str());
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, type);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, lang);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, channel->GetChannelId());
            if (Eluna::get()->ExecuteCall(6, 1))
            {
                lua_State* L = Eluna::get()->LuaState;
                if (!lua_isnoneornil(L, 1) && !lua_toboolean(L, 1))
                    Result = false;
                Eluna::get()->EndCall(1);
            }
        }
        return Result;
    }

    void OnPvPKill(uint32 eventId, Player* killer, Player* victim)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, killer);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, victim);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerLevelChanged(uint32 eventId, Player* player, uint8 oldLevel)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, oldLevel);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerTalentsChanged(uint32 eventId, Player* player, uint32 points)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, points);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnCreatureKill(uint32 eventId, Player* player, Creature* creature)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, creature);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerKilledByCreature(uint32 eventId, Creature* creature, Player* player)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, creature);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerTalentsReset(uint32 eventId, Player* player, bool noCost)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushBoolean(Eluna::get()->LuaState, noCost);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerMoneyChanged(uint32 eventId, Player* player, int32& amount)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushInteger(Eluna::get()->LuaState, amount);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnGivePlayerXP(uint32 eventId, Player* player, uint32& amount, Unit* victim)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, amount);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, victim);
            Eluna::get()->ExecuteCall(4, 0);
        }
    }

    void OnPlayerReputationChange(uint32 eventId, Player* player, uint32 factionID, int32& standing, bool incremental)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, factionID);
            Eluna::get()->PushInteger(Eluna::get()->LuaState, standing);
            Eluna::get()->PushBoolean(Eluna::get()->LuaState, incremental);
            Eluna::get()->ExecuteCall(5, 0);
        }
    }

    void OnPlayerDuelRequest(uint32 eventId, Player* target, Player* challenger)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, target);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, challenger);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerDuelStart(uint32 eventId, Player* player1, Player* player2)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player1);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player2);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerDuelEnd(uint32 eventId, Player* winner, Player* loser, DuelCompleteType type)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, winner);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, loser);
            Eluna::get()->PushInteger(Eluna::get()->LuaState, type);
            Eluna::get()->ExecuteCall(4, 0);
        }
    }

    void OnPlayerEmote(uint32 eventId, Player* player, uint32 emote)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, emote);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerTextEmote(uint32 eventId, Player* player, uint32 textEmote, uint32 emoteNum, uint64 guid)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, textEmote);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, emoteNum);
            Eluna::get()->PushGUID(Eluna::get()->LuaState, guid);
            Eluna::get()->ExecuteCall(5, 0);
        }
    }

    void OnPlayerSpellCast(uint32 eventId, Player* player, Spell* spell, bool skipCheck)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushSpell(Eluna::get()->LuaState, spell);
            Eluna::get()->PushBoolean(Eluna::get()->LuaState, skipCheck);
            Eluna::get()->ExecuteCall(4, 0);
        }
    }

    void OnPlayerLogin(uint32 eventId, Player* player)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->ExecuteCall(2, 0);
        }
    }

    void OnPlayerLogout(uint32 eventId, Player* player)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->ExecuteCall(2, 0);
        }
    }

    void OnPlayerCreate(uint32 eventId, Player* player)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->ExecuteCall(2, 0);
        }
    }

    void OnPlayerSave(uint32 eventId, Player* player)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->ExecuteCall(2, 0);
        }
    }

    void OnPlayerBindToInstance(uint32 eventId, Player* player, Difficulty difficulty, uint32 mapid, bool permanent)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushInteger(Eluna::get()->LuaState, difficulty);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, mapid);
            Eluna::get()->PushBoolean(Eluna::get()->LuaState, permanent);
            Eluna::get()->ExecuteCall(5, 0);
        }
    }

    void OnMapChanged(uint32 eventId, Player* player)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->ExecuteCall(2, 0);
        }
    }

    void OnPlayerUpdateZone(uint32 eventId, Player* player, uint32 newZone, uint32 newArea)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, newZone);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, newArea);
            Eluna::get()->ExecuteCall(4, 0);
        }
    }

    void OnPlayerDelete(uint32 eventId, uint64 guid)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGUID(Eluna::get()->LuaState, guid);
            Eluna::get()->ExecuteCall(2, 0);
        }
    }

    bool OnGossipHello(uint32 eventId, Player* player, Creature* creature)
    {
        int bind = Eluna::get()->CreatureGossipBindings->GetBind(creature->GetEntry(), eventId);
        if (!bind)
            return false;
        player->PlayerTalkClass->ClearMenus();
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, creature);
        Eluna::get()->ExecuteCall(3, 0);
        return true;
    }

    bool OnGossipSelect(uint32 eventId, Player* player, Creature* creature, uint32 sender, uint32 actions)
    {
        int bind = Eluna::get()->CreatureGossipBindings->GetBind(creature->GetEntry(), eventId);
        if (!bind)
            return false;
        player->PlayerTalkClass->ClearMenus();
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, creature);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, sender);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, actions);
        Eluna::get()->ExecuteCall(5, 0);
        return true;
    }

    bool OnGossipSelectCode(uint32 eventId, Player* player, Creature* creature, uint32 sender, uint32 actions, const char* code)
    {
        int bind = Eluna::get()->CreatureGossipBindings->GetBind(creature->GetEntry(), eventId);
        if (!bind)
            return false;
        player->PlayerTalkClass->ClearMenus();
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, creature);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, sender);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, actions);
        Eluna::get()->PushString(Eluna::get()->LuaState, code);
        Eluna::get()->ExecuteCall(6, 0);
        return true;
    }

    bool OnDummyEffect(uint32 eventId, Unit* caster, uint32 spellId, SpellEffIndex effIndex, Creature* target)
    {
        int bind = Eluna::get()->CreatureEventBindings->GetBind(target->GetEntry(), eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, caster);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, spellId);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, effIndex);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, target);
        Eluna::get()->ExecuteCall(5, 0);
        return true;
    }

    bool OnQuestAccept(uint32 eventId, Player* player, Creature* creature, Quest const* quest)
    {
        int bind = Eluna::get()->CreatureEventBindings->GetBind(creature->GetEntry(), eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, creature);
        Eluna::get()->PushQuest(Eluna::get()->LuaState, quest);
        Eluna::get()->ExecuteCall(4, 0);
        return true;
    }

    bool OnQuestSelect(uint32 eventId, Player* player, Creature* creature, Quest const* quest)
    {
        int bind = Eluna::get()->CreatureEventBindings->GetBind(creature->GetEntry(), eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, creature);
        Eluna::get()->PushQuest(Eluna::get()->LuaState, quest);
        Eluna::get()->ExecuteCall(4, 0);
        return true;
    }

    bool OnQuestReward(uint32 eventId, Player* player, Creature* creature, Quest const* quest, uint32 opt)
    {
        int bind = Eluna::get()->CreatureEventBindings->GetBind(creature->GetEntry(), eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, creature);
        Eluna::get()->PushQuest(Eluna::get()->LuaState, quest);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, opt);
        Eluna::get()->ExecuteCall(5, 0);
        return true;
    }

    bool OnQuestComplete(uint32 eventId, Player* player, Creature* creature, Quest const* quest)
    {
        int bind = Eluna::get()->CreatureEventBindings->GetBind(creature->GetEntry(), eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, creature);
        Eluna::get()->PushQuest(Eluna::get()->LuaState, quest);
        Eluna::get()->ExecuteCall(4, 0);
        return true;
    }

    uint32 GetDialogStatus(uint32 eventId, Player* player, Creature* creature)
    {
        int bind = Eluna::get()->CreatureEventBindings->GetBind(creature->GetEntry(), eventId);
        if (!bind)
            return 100;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, creature);
        Eluna::get()->ExecuteCall(3, 0);
        return 100;
    }

    /* GameObject Gossip */
    bool OnGossipHello(uint32 eventId, Player* player, GameObject* gameObject)
    {
        int bind = Eluna::get()->GameObjectGossipBindings->GetBind(gameObject->GetEntry(), eventId);
        if (!bind)
            return false;
        player->PlayerTalkClass->ClearMenus();
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushGO(Eluna::get()->LuaState, gameObject);
        Eluna::get()->ExecuteCall(3, 0);
        return true;
    }

    bool OnGossipSelect(uint32 eventId, Player* player, GameObject* gameObject, uint32 sender, uint32 actions)
    {
        int bind = Eluna::get()->GameObjectGossipBindings->GetBind(gameObject->GetEntry(), eventId);
        if (!bind)
            return false;
        player->PlayerTalkClass->ClearMenus();
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushGO(Eluna::get()->LuaState, gameObject);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, sender);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, actions);
        Eluna::get()->ExecuteCall(5, 0);
        return true;
    }

    bool OnGossipSelectCode(uint32 eventId, Player* player, GameObject* gameObject, uint32 sender, uint32 actions, const char* code)
    {
        int bind = Eluna::get()->GameObjectGossipBindings->GetBind(gameObject->GetEntry(), eventId);
        if (!bind)
            return false;
        player->PlayerTalkClass->ClearMenus();
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushGO(Eluna::get()->LuaState, gameObject);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, sender);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, actions);
        Eluna::get()->PushString(Eluna::get()->LuaState, code);
        Eluna::get()->ExecuteCall(6, 0);
        return true;
    }

    // Called when a dummy spell effect is triggered on the gameobject.
    bool OnDummyEffect(uint32 eventId, Unit* caster, uint32 spellId, SpellEffIndex effIndex, GameObject* go)
    {
        int bind = Eluna::get()->GameObjectEventBindings->GetBind(go->GetEntry(), eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, caster);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, spellId);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, effIndex);
        Eluna::get()->PushGO(Eluna::get()->LuaState, go);
        Eluna::get()->ExecuteCall(5, 0);
        return true;
    }

    // Called when a player accepts a quest from the gameobject.
    bool OnQuestAccept(uint32 eventId, Player* player, GameObject* go, Quest const* quest)
    {
        int bind = Eluna::get()->GameObjectEventBindings->GetBind(go->GetEntry(), eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushGO(Eluna::get()->LuaState, go);
        Eluna::get()->PushQuest(Eluna::get()->LuaState, quest);
        Eluna::get()->ExecuteCall(4, 0);
        return true;
    }

    // Called when a player selects a quest reward.
    bool OnQuestReward(uint32 eventId, Player* player, GameObject* go, Quest const* quest, uint32 opt)
    {
        int bind = Eluna::get()->GameObjectEventBindings->GetBind(go->GetEntry(), eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushGO(Eluna::get()->LuaState, go);
        Eluna::get()->PushQuest(Eluna::get()->LuaState, quest);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, opt);
        Eluna::get()->ExecuteCall(5, 0);
        return true;
    }

    uint32 GetDialogStatus(uint32 eventId, Player* player, GameObject* go)
    {
        int bind = Eluna::get()->GameObjectEventBindings->GetBind(go->GetEntry(), eventId);
        if (!bind)
            return 100;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->PushGO(Eluna::get()->LuaState, go);
        Eluna::get()->ExecuteCall(3, 0);
        return 100;
    }

    // Called when the game object is destroyed (destructible buildings only).
    bool OnDestroyed(uint32 eventId, GameObject* go, Player* player)
    {
        int bind = Eluna::get()->GameObjectEventBindings->GetBind(go->GetEntry(), eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushGO(Eluna::get()->LuaState, go);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->ExecuteCall(3, 0);
        return true;
    }

    // Called when the game object is damaged (destructible buildings only).
    bool OnFirstDamaged(uint32 eventId, GameObject* go, Player* player)
    {
        int bind = Eluna::get()->GameObjectEventBindings->GetBind(go->GetEntry(), eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushGO(Eluna::get()->LuaState, go);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
        Eluna::get()->ExecuteCall(3, 0);
        return true;
    }

    // Called when the game object loot state is changed.
    bool OnLootStateChanged(uint32 eventId, GameObject* go, uint32 state, Unit* unit)
    {
        int bind = Eluna::get()->GameObjectEventBindings->GetBind(go->GetEntry(), eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushGO(Eluna::get()->LuaState, go);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, state);
        Eluna::get()->PushUnit(Eluna::get()->LuaState, unit);
        Eluna::get()->ExecuteCall(4, 0);
        return true;
    }

    // Called when the game object state is changed.
    bool OnGameObjectStateChanged(uint32 eventId, GameObject* go, uint32 state)
    {
        int bind = Eluna::get()->GameObjectEventBindings->GetBind(go->GetEntry(), eventId);
        if (!bind)
            return false;
        Eluna::get()->BeginCall(bind);
        Eluna::get()->PushInteger(Eluna::get()->LuaState, eventId);
        Eluna::get()->PushGO(Eluna::get()->LuaState, go);
        Eluna::get()->PushUnsigned(Eluna::get()->LuaState, state);
        Eluna::get()->ExecuteCall(3, 0);
        return true;
    }

    void OnGuildAddMember(uint32 eventId, Guild* guild, Player* player, uint8& plRank)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGuild(Eluna::get()->LuaState, guild);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, plRank);
            Eluna::get()->ExecuteCall(4, 0);
        }
    }

    void OnGuildRemoveMember(uint32 eventId, Guild* guild, Player* player, bool isDisbanding, bool isKicked)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGuild(Eluna::get()->LuaState, guild);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushBoolean(Eluna::get()->LuaState, isDisbanding);
            Eluna::get()->PushBoolean(Eluna::get()->LuaState, isKicked);
            Eluna::get()->ExecuteCall(5, 0);
        }
    }

    void OnGuildMOTDChanged(uint32 eventId, Guild* guild, const std::string& newMotd)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGuild(Eluna::get()->LuaState, guild);
            Eluna::get()->PushString(Eluna::get()->LuaState, newMotd.c_str());
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnGuildInfoChanged(uint32 eventId, Guild* guild, const std::string& newInfo)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGuild(Eluna::get()->LuaState, guild);
            Eluna::get()->PushString(Eluna::get()->LuaState, newInfo.c_str());
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnGuildCreate(uint32 eventId, Guild* guild, Player* leader, const std::string& name)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGuild(Eluna::get()->LuaState, guild);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, leader);
            Eluna::get()->PushString(Eluna::get()->LuaState, name.c_str());
            Eluna::get()->ExecuteCall(4, 0);
        }
    }

    void OnGuildDisband(uint32 eventId, Guild* guild)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGuild(Eluna::get()->LuaState, guild);
            Eluna::get()->ExecuteCall(2, 0);
        }
    }

    void OnGuildMemberWitdrawMoney(uint32 eventId, Guild* guild, Player* player, uint32 &amount, bool isRepair)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGuild(Eluna::get()->LuaState, guild);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, amount);
            Eluna::get()->PushBoolean(Eluna::get()->LuaState, isRepair);
            Eluna::get()->ExecuteCall(5, 0);
        }
    }

    void OnGuildMemberDepositMoney(uint32 eventId, Guild* guild, Player* player, uint32 &amount)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGuild(Eluna::get()->LuaState, guild);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, amount);
            Eluna::get()->ExecuteCall(4, 0);
        }
    }

    void OnGuildItemMove(uint32 eventId, Guild* guild, Player* player, Item* pItem, bool isSrcBank, uint8 srcContainer, uint8 srcSlotId,
        bool isDestBank, uint8 destContainer, uint8 destSlotId)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGuild(Eluna::get()->LuaState, guild);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushItem(Eluna::get()->LuaState, pItem);
            Eluna::get()->PushBoolean(Eluna::get()->LuaState, isSrcBank);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, srcContainer);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, srcSlotId);
            Eluna::get()->PushBoolean(Eluna::get()->LuaState, isDestBank);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, destContainer);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, destSlotId);
            Eluna::get()->ExecuteCall(10, 0);
        }
    }

    void OnGuildEvent(uint32 eventId, Guild* guild, uint8 eventType, uint32 playerGuid1, uint32 playerGuid2, uint8 newRank)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGuild(Eluna::get()->LuaState, guild);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventType);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, playerGuid1);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, playerGuid2);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, newRank);
            Eluna::get()->ExecuteCall(6, 0);
        }
    }

    void OnGuildBankEvent(uint32 eventId, Guild* guild, uint8 eventType, uint8 tabId, uint32 playerGuid, uint32 itemOrMoney, uint16 itemStackCount, uint8 destTabId)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGuild(Eluna::get()->LuaState, guild);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventType);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, tabId);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, playerGuid);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, itemOrMoney);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, itemStackCount);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, destTabId);
            Eluna::get()->ExecuteCall(8, 0);
        }
    }

    void OnGroupAddMember(uint32 eventId, Group* group, uint64 guid)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGroup(Eluna::get()->LuaState, group);
            Eluna::get()->PushGUID(Eluna::get()->LuaState, guid);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnGroupInviteMember(uint32 eventId, Group* group, uint64 guid)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGroup(Eluna::get()->LuaState, group);
            Eluna::get()->PushGUID(Eluna::get()->LuaState, guid);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnGroupRemoveMember(uint32 eventId, Group* group, uint64 guid, RemoveMethod method, uint64 kicker, const char* reason)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGroup(Eluna::get()->LuaState, group);
            Eluna::get()->PushGUID(Eluna::get()->LuaState, guid);
            Eluna::get()->PushInteger(Eluna::get()->LuaState, method);
            Eluna::get()->PushGUID(Eluna::get()->LuaState, kicker);
            Eluna::get()->PushString(Eluna::get()->LuaState, reason);
            Eluna::get()->ExecuteCall(6, 0);
        }
    }

    void OnGroupChangeLeader(uint32 eventId, Group* group, uint64 newLeaderGuid, uint64 oldLeaderGuid)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGroup(Eluna::get()->LuaState, group);
            Eluna::get()->PushGUID(Eluna::get()->LuaState, newLeaderGuid);
            Eluna::get()->PushGUID(Eluna::get()->LuaState, oldLeaderGuid);
            Eluna::get()->ExecuteCall(4, 0);
        }
    }

    void OnGroupDisband(uint32 eventId, Group* group)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushGroup(Eluna::get()->LuaState, group);
            Eluna::get()->ExecuteCall(2, 0);
        }
    }

    void OnWeatherChange(uint32 eventId, Weather* weather, WeatherState state, float grade)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, (weather->GetZone()));
            Eluna::get()->PushInteger(Eluna::get()->LuaState, state);
            Eluna::get()->PushFloat(Eluna::get()->LuaState, grade);
            Eluna::get()->ExecuteCall(4, 0);
        }
    }

    bool OnAreaTrigger(uint32 eventId, Player* player, AreaTriggerEntry const* trigger)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->LuaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, trigger->id);
            Eluna::get()->ExecuteCall(3, 0);
        }
        return false;
    }

    void OnElunaRestart(uint32 eventId)
    {
        for (vector<int>::iterator itr = Eluna::get()->ServerEventBindings.at(eventId).begin();
            itr != Eluna::get()->ServerEventBindings.at(eventId).end(); ++itr)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->LuaState, eventId);
            Eluna::get()->ExecuteCall(1, 0);
        }
    }
};
#endif