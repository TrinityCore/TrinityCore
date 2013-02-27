/*
FOEREAPER TOMMY ENGINE, YEAH!

// Correct Paths (Incase the crap refreshes)
..\LuaEngine\Release\LuaEngine.lib
..\..\..\dep\lualib\Release\lua.lib
*/
#ifndef __ELUNA__H
#define __ELUNA__H
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <set>
#include <hash_map>
#include <map>
#include "Chat.h"
#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Common.h"
#include "Unit.h"
#include "Creature.h"
#include "GameObjectAI.h"

using namespace std;

#define lua_ref(L, lock) ((lock) ? luaL_ref(L, LUA_REGISTRYINDEX) : \
    (lua_pushstring(L, "unlocked references are obsolete"), lua_error(L), 0))

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
    REGTYPE_GOSSIP,
    REGTYPE_CREATURE,
    REGTYPE_GAMEOBJECT,
    REGTYPE_GAMEOBJECT_GOSSIP,
    REGTYPE_ITEM_GOSSIP,
    REGTYPE_PLAYER_GOSSIP,
    REGTYPE_LOG,
    REGTYPE_COUNT
};

enum ServerEvents
{
    // Player
    PLAYER_EVENT_ON_CHARACTER_CREATE        = 1,        // Implemented
    PLAYER_EVENT_ON_KILL_PLAYER             = 2,        // Implemented
    PLAYER_EVENT_ON_LOGIN                   = 4,        // Implemented
    PLAYER_EVENT_ON_LOGOUT                  = 13,       // Implemented
    PLAYER_EVENT_ON_CHAT                    = 16,       // Implemented
    PLAYER_EVENT_ON_LEVEL_CHANGE            = 27,       // Implemented
    PLAYER_EVENT_ON_CHARACTER_DELETE        = 33,       // Implemented
    PLAYER_EVENT_ON_TALENTS_CHANGE          = 34,       // Implemented
    PLAYER_EVENT_ON_TALENTS_RESET           = 35,       // Implemented
    PLAYER_EVENT_ON_MONEY_CHANGE            = 36,       // Implemented
    PLAYER_EVENT_ON_GIVE_XP                 = 37,       // Implemented
    PLAYER_EVENT_ON_REPUTATION_CHANGE       = 38,       // Implemented
    PLAYER_EVENT_ON_DUEL_REQUEST            = 39,       // Implemented
    PLAYER_EVENT_ON_DUEL_START              = 40,       // Implemented
    PLAYER_EVENT_ON_DUEL_END                = 41,       // Implemented
    PLAYER_EVENT_ON_EMOTE                   = 42,       // Implemented
    PLAYER_EVENT_ON_TEXT_EMOTE              = 43,       // Not Implemented
    PLAYER_EVENT_ON_SPELL_CAST              = 44,       // Not Implemented
    PLAYER_EVENT_ON_SAVE                    = 45,       // Implemented
    PLAYER_EVENT_ON_BIND_TO_INSTANCE        = 46,       // Implemented
    PLAYER_EVENT_ON_UPDATE_ZONE             = 47,       // Implemented
    PLAYER_EVENT_ON_KILL_CREATURE           = 48,       // Implemented
    PLAYER_EVENT_ON_KILLED_BY_CREATURE      = 49,       // Implemented
    PLAYER_EVENT_ON_MAP_CHANGE              = 50,       // Not Implemented
	PLAYER_EVENT_ON_AREATRIGGER             = 95,       // Implemented

    // Guild
    GUILD_EVENT_ON_ADD_MEMBER               = 51,       // Not Implemented
    GUILD_EVENT_ON_REMOVE_MEMBER            = 52,       // Not Implemented
    GUILD_EVENT_ON_MOTD_CHANGE              = 53,       // Not Implemented
    GUILD_EVENT_ON_INFO_CHANGE              = 54,       // Not Implemented
    GUILD_EVENT_ON_CREATE                   = 55,       // Not Implemented
    GUILD_EVENT_ON_DISBAND                  = 56,       // Not Implemented
    GUILD_EVENT_ON_MONEY_WITHDRAW           = 57,       // Not Implemented
    GUILD_EVENT_ON_MONEY_DEPOSIT            = 58,       // Not Implemented
    GUILD_EVENT_ON_ITEM_MOVE                = 59,       // Not Implemented
    GUILD_EVENT_ON_EVENT                    = 60,       // Not Implemented
    GUILD_EVENT_ON_BANK_EVENT               = 61,       // Not Implemented

    // Server
    SERVER_EVENT_ON_NETWORK_START           = 62,       // Not Implemented
    SERVER_EVENT_ON_NETWORK_STOP            = 63,       // Not Implemented
    SERVER_EVENT_ON_SOCKET_OPEN             = 64,       // Not Implemented
    SERVER_EVENT_ON_SOCKET_CLOSE            = 65,       // Not Implemented
    SERVER_EVENT_ON_PACKET_RECEIVE          = 66,       // Not Implemented
    SERVER_EVENT_ON_PACKET_RECEIVE_UNKNOWN  = 67,       // Not Implemented
    SERVER_EVENT_ON_PACKET_SEND             = 68,       // Not Implemented

    // World
    WORLD_EVENT_ON_OPEN_STATE_CHANGE        = 69,       // Not Implemented
    WORLD_EVENT_ON_CONFIG_LOAD              = 70,       // Not Implemented
    WORLD_EVENT_ON_MOTD_CHANGE              = 71,       // Not Implemented
    WORLD_EVENT_ON_SHUTDOWN_INIT            = 72,       // Not Implemented
    WORLD_EVENT_ON_SHUTDOWN_CANCEL          = 73,       // Not Implemented
    WORLD_EVENT_ON_UPDATE                   = 74,       // Not Implemented
    WORLD_EVENT_ON_STARTUP                  = 75,       // Not Implemented
    WORLD_EVENT_ON_SHUTDOWN                 = 76,       // Not Implemented

    // Map
    MAP_EVENT_ON_CREATE                     = 77,       // Not Implemented
    MAP_EVENT_ON_DESTROY                    = 78,       // Not Implemented
    MAP_EVENT_ON_LOAD                       = 79,       // Not Implemented
    MAP_EVENT_ON_UNLOAD                     = 80,       // Not Implemented
    MAP_EVENT_ON_PLAYER_ENTER               = 81,       // Not Implemented
    MAP_EVENT_ON_PLAYER_LEAVE               = 82,       // Not Implemented
    MAP_EVENT_ON_UPDATE                     = 83,       // Not Implemented

    // Area trigger
    TRIGGER_EVENT_ON_TRIGGER                = 84,       // Not Implemented

    // Weather
    WEATHER_EVENT_ON_CHANGE                 = 85,       // Not Implemented

    // Auction house
    AUCTION_EVENT_ON_ADD                    = 86,       // Not Implemented
    AUCTION_EVENT_ON_REMOVE                 = 87,       // Not Implemented
    AUCTION_EVENT_ON_SUCCESFUL              = 88,       // Not Implemented
    AUCTION_EVENT_ON_EXPIRE                 = 89,       // Not Implemented

    // Group
    GROUP_EVENT_ON_MEMBER_ADD               = 90,       // Not Implemented
    GROUP_EVENT_ON_MEMBER_INVITE            = 91,       // Not Implemented
    GROUP_EVENT_ON_MEMBER_REMOVE            = 92,       // Not Implemented
    GROUP_EVENT_ON_LEADER_CHANGE            = 93,       // Not Implemented
    GROUP_EVENT_ON_DISBAND                  = 94,       // Not Implemented

    SERVER_EVENT_COUNT
};

enum CreatureEvents
{
    //ARC
    CREATURE_EVENT_ON_ENTER_COMBAT                  = 1,    // Implemented
    CREATURE_EVENT_ON_LEAVE_COMBAT                  = 2,    // Implemented
    CREATURE_EVENT_ON_TARGET_DIED                   = 3,    // Implemented
    CREATURE_EVENT_ON_DIED                          = 4,    // Implemented
    //CREATURE_EVENT_ON_TARGET_PARRIED              = 5,    // Not Implemented
    //CREATURE_EVENT_ON_TARGET_DODGED               = 6,    // Not Implemented
    //CREATURE_EVENT_ON_TARGET_BLOCKED              = 7,    // Not Implemented
    //CREATURE_EVENT_ON_TARGET_CRIT_HIT             = 8,    // Not Implemented
    //CREATURE_EVENT_ON_PARRY                       = 9,    // Not Implemented
    //CREATURE_EVENT_ON_DODGED                      = 10,   // Not Implemented
    //CREATURE_EVENT_ON_BLOCKED                     = 11,   // Not Implemented
    //CREATURE_EVENT_ON_CRIT_HIT                    = 12,   // Not Implemented
    //CREATURE_EVENT_ON_HIT                         = 13,   // Not Implemented
    //CREATURE_EVENT_ON_ASSIST_TARGET_DIED          = 14,   // Not Implemented
    //CREATURE_EVENT_ON_FEAR                        = 15,   // Not Implemented
    //CREATURE_EVENT_ON_FLEE                        = 16,   // Not Implemented
    //CREATURE_EVENT_ON_CALL_FOR_HELP               = 17,   // Not Implemented
    CREATURE_EVENT_ON_SPAWN                         = 18,   // Implemented
    CREATURE_EVENT_ON_REACH_WP                      = 19,   // Implemented
    //CREATURE_EVENT_ON_LOOT_TAKEN                  = 20,   // Not Implemented
    CREATURE_EVENT_ON_AIUPDATE                      = 21,   // Implemented
    CREATURE_EVENT_ON_RECEIVE_EMOTE                 = 22,   // Implemented
    CREATURE_EVENT_ON_DAMAGE_TAKEN                  = 23,   // Implemented
    //CREATURE_EVENT_ON_ENTER_VEHICLE               = 24,   // Not Implemented
    //CREATURE_EVENT_ON_EXIT_VEHICLE                = 25,   // Not Implemented
    //CREATURE_EVENT_ON_FIRST_PASSENGER_ENTERED     = 26,   // Not Implemented
    //CREATURE_EVENT_ON_VEHICLE_FULL                = 27,   // Not Implemented
    //CREATURE_EVENT_ON_LAST_PASSENGER_LEFT         = 28,   // Not Implemented
    //TC
    CREATURE_EVENT_ON_PRE_COMBAT                    = 29,   // Implemented
    CREATURE_EVENT_ON_ATTACKED_AT                   = 30,   // Implemented
    CREATURE_EVENT_ON_OWNER_ATTACKED_AT             = 31,   // Implemented
    CREATURE_EVENT_ON_HIT_BY_SPELL                  = 32,   // Implemented
    CREATURE_EVENT_ON_SPELL_HIT_TARGET              = 33,   // Implemented
    CREATURE_EVENT_ON_SPELL_CLICK                   = 34,   // Implemented
    CREATURE_EVENT_ON_CHARMED                       = 35,   // Implemented
    CREATURE_EVENT_ON_POSSESS                       = 36,   // Implemented
    CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE        = 37,   // Implemented
    CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN     = 38,   // Implemented
    CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED        = 39,   // Implemented
    CREATURE_EVENT_ON_SUMMONED                      = 40,   // Implemented
    CREATURE_EVENT_ON_RESET                         = 41,   // Implemented
    CREATURE_EVENT_ON_REACH_HOME                    = 42,   // Implemented
    CREATURE_EVENT_ON_CAN_RESPAWN                   = 43,   // Implemented
    CREATURE_EVENT_ON_CORPSE_REMOVED                = 44,   // Implemented
    CREATURE_EVENT_ON_MOVE_IN_LOS                   = 45,   // Implemented
    CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS           = 46,   // Implemented
    CREATURE_EVENT_ON_PASSANGER_BOARDED             = 47,   // Implemented
    CREATURE_EVENT_ON_DUMMY_EFFECT                  = 48,   // Not Implemented
    CREATURE_EVENT_ON_QUEST_ACCEPT                  = 49,   // Not Implemented
    CREATURE_EVENT_ON_QUEST_SELECT                  = 50,   // Not Implemented
    CREATURE_EVENT_ON_QUEST_COMPLETE                = 51,   // Not Implemented
    CREATURE_EVENT_ON_QUEST_REWARD                  = 52,   // Not Implemented
    CREATURE_EVENT_ON_DIALOG_STATUS                 = 53,   // Not Implemented
    CREATURE_EVENT_COUNT
};

enum GameObjectEvents
{
    GAMEOBJECT_EVENT_ON_AIUPDATE                    = 1,    // Not Implemented
    GAMEOBJECT_EVENT_ON_RESET                       = 2,    // Not Implemented
    GAMEOBJECT_EVENT_DOACTION                       = 3,    // Not Implemented
    GAMEOBJECT_EVENT_ON_SET_GUID                    = 4,    // Not Implemented
    GAMEOBJECT_EVENT_ON_GET_GUID                    = 5,    // Not Implemented
    GAMEOBJECT_EVENT_ON_DUMMY_EFFECT                = 6,    // Not Implemented
    GAMEOBJECT_EVENT_ON_QUEST_ACCEPT                = 7,    // Not Implemented
    GAMEOBJECT_EVENT_ON_QUEST_REWARD                = 8,    // Not Implemented
    GAMEOBJECT_EVENT_ON_DIALOG_STATUS               = 9,    // Not Implemented
    GAMEOBJECT_EVENT_ON_DESTROYED                   = 10,   // Not Implemented
    GAMEOBJECT_EVENT_ON_DAMAGED                     = 11,   // Not Implemented
    GAMEOBJECT_EVENT_ON_LOOT_STATE_CHANGE           = 12,   // Not Implemented
    GAMEOBJECT_EVENT_ON_GO_STATE_CHANGED            = 13,   // Not Implemented
    GAMEOBJECT_EVENT_COUNT
};

enum ItemEvents
{
    ITEM_EVENT_COUNT = 1 //placeholder
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

struct CreatureBind
{
    uint32 entry;
    uint16 _functionReferences[CREATURE_EVENT_COUNT];
    uint32 _gossipReferences[GOSSIP_EVENT_COUNT];

    CreatureBind(uint32 _entry)
    {
        entry = _entry;
    }
};

struct GameObjectBind
{
    uint32 entry;
    uint16 _functionReferences[GAMEOBJECT_EVENT_COUNT];
    uint32 _gossipReferences[GOSSIP_EVENT_COUNT];

    GameObjectBind(uint32 _entry)
    {
        entry = _entry;
    }
};

struct ItemBind
{
    uint32 entry;
    uint16 _functionReferences[ITEM_EVENT_COUNT];
    uint32 _gossipReferences[GOSSIP_EVENT_COUNT];

    ItemBind(uint32 _entry)
    {
        entry = _entry;
    }
};

struct PlayerBind
{
    uint32 menu_id;
    uint32 _gossipReferences[GOSSIP_EVENT_COUNT];

    PlayerBind(uint32 _menu_id)
    {
        menu_id = _menu_id;
    }
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

    typedef map<int, vector<uint16> > ElunaBindingMap;
    ElunaBindingMap _serverEventBindings;

    vector<CreatureBind*> _creatureEventBindings;
    vector<CreatureBind*> _gossipEventBindings;

    vector<GameObjectBind*> _gameObjectAIEventBindings;
    vector<GameObjectBind*> _gameObjectGossipBindings;
    
    vector<ItemBind*> _itemGossipBindings;

    vector<PlayerBind*> _playerGossipBindings;

    static CreatureAI* GetLuaCreatureAI(Creature* creature);
    static GameObjectAI* GetLuaGameObjectAI(GameObject* gameObject);

    static void InitTables()
    {
        for (int i = 0; i < SERVER_EVENT_COUNT; i++)
        {
            vector<uint16> _vector;
            get()->_serverEventBindings.insert(pair<int, vector<uint16> >(i, _vector));
        }
    }

    Eluna()
    {
    }

    ~Eluna()
    {
        _serverEventBindings.clear();
        _gossipEventBindings.clear();
        _creatureEventBindings.clear();
        _gameObjectAIEventBindings.clear();
        _gameObjectGossipBindings.clear();
        _itemGossipBindings.clear();
        _playerGossipBindings.clear();
        luaEventMap::LuaEventsResetAll(); // Unregisters and stops all timed events
        // Need to reset global, creature and gob events
    }

    lua_State* _luaState;

    void StartEluna();
    void Register(uint8 reg, uint32 id, uint32 evt, uint16 fuc);

    static void report(lua_State*);

    void BeginCall(uint16 fReference)
    {
        lua_settop(_luaState, 0); //stack should be empty
        lua_rawgeti(_luaState, LUA_REGISTRYINDEX, (fReference));
    }

    bool ExecuteCall(uint8 params, uint8 res)
    {
        bool ret = true;
        int top = lua_gettop(_luaState);
        if(strcmp(luaL_typename(_luaState,top-params), "function") )
        {
            ret = false;
            if(params > 0)
            {
                for(int i = top; i >= (top-params); i--)
                {
                    if(!lua_isnone(_luaState, i) )
                        lua_remove(_luaState, i);
                }
            }
        }
        else
        {
            if(lua_pcall(_luaState,params,res,0) )
            {
                report(_luaState);
                ret = false;
            }
        }
        return ret;
    }

    void EndCall(uint8 res)
    {
        for(int i = res; i > 0; i--)
        {
            if(!lua_isnone(_luaState,res))
                lua_remove(_luaState,res);
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
    void PushChannel(lua_State*, Channel*);
    void PushItem(lua_State*, Item*);
    // Checks
    Player * CHECK_PLAYER(lua_State* L, int narg)
    {
        if(!L)
            return ElunaTemplate<Player>::check(_luaState, narg);
        else
            return ElunaTemplate<Player>::check(L, narg);
    }

    Unit * CHECK_UNIT(lua_State* L, int narg)
    {
        if(!L)
            return ElunaTemplate<Unit>::check(_luaState, narg);
        else
            return ElunaTemplate<Unit>::check(L, narg);
    }

    Creature * CHECK_CREATURE(lua_State* L, int narg)
    {
        if(!L)
            return ElunaTemplate<Creature>::check(_luaState, narg);
        else
            return ElunaTemplate<Creature>::check(L, narg);
    }

    GameObject* CHECK_OBJECT(lua_State* L, int narg)
    {
        if (!L)
            return ElunaTemplate<GameObject>::check(_luaState, narg);
        else
            return ElunaTemplate<GameObject>::check(L, narg);
    }

    WorldPacket* CHECK_PACKET(lua_State* L, int narg)
    {
        if (!L)
            return ElunaTemplate<WorldPacket>::check(_luaState, narg);
        else
            return ElunaTemplate<WorldPacket>::check(L, narg);
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
            if(!GetMethodTable<T>())
            {
                lua_pop(L, 2);
                return;
            }

            for (ElunaRegister* l = ((ElunaRegister*)GetMethodTable<T>()); l->name; l++)
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
            if(lua_isnil(L, -1))
                luaL_error(L, "%s missing metatable", GetTName<T>());
            int idxMt = lua_gettop(L);
            T** ptrHold = (T**)lua_newuserdata(L, sizeof(T**));
            int ud = lua_gettop(L);
            if(ptrHold)
            {
                *ptrHold = obj;
                lua_pushvalue(L, idxMt);
                lua_setmetatable(L, -2);
                char name[32];
                tostring(name, obj);
                lua_getfield(L, LUA_REGISTRYINDEX, "DO NOT TRASH");
                if(lua_isnil(L, -1))
                {
                    luaL_newmetatable(L, "DO NOT TRASH");
                    lua_pop(L, 1);
                }
                lua_getfield(L, LUA_REGISTRYINDEX, "DO NOT TRASH");
                if(gc == false)
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
            if(!ptrHold)
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
            if(!obj)
                return 0;
            lua_getfield(L, LUA_REGISTRYINDEX, "DO NO TRASH");
            if(lua_istable(L, -1))
            {
                char name[32];
                tostring(name, obj);
                lua_getfield(L, -1, std::string(name).c_str());
                if(lua_isnil(L, -1))
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
            if(lua_istable(L, - 1))
            {
                lua_pushvalue(L, 2);
                lua_rawget(L, -2);
                if(lua_isnil(L, -1))
                {
                    lua_getmetatable(L, -2);
                    if(lua_istable(L, -1))
                    {
                        lua_getfield(L, -1, "__index");
                        if(lua_isfunction(L, -1))
                        {
                            lua_pushvalue(L, 1);
                            lua_pushvalue(L, 2);
                            lua_pcall(L, 2, 1, 0);
                        }
                        else if(lua_istable(L, -1))
                            lua_getfield(L, -1, key);
                        else
                            lua_pushnil(L);
                    }
                    else
                        lua_pushnil(L);
                }
                else if(lua_istable(L, -1))
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
    class luaEventMap
    {
    public:
        luaEventMap() { }
        ~luaEventMap() { LuaEventsReset(); }

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
            for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
            {
                luaL_unref(get()->_luaState, LUA_REGISTRYINDEX, itr->second.funcRef);
                ++itr;
            }
            _eventMap.clear();
            _time = 0;
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

        void LuaEventCancel(uint32 funcRef)
        {
            if (LuaEventsEmpty())
                return;

            for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
            {
                if (funcRef == itr->second.funcRef)
                {
                    luaL_unref(get()->_luaState, LUA_REGISTRYINDEX, itr->second.funcRef);
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

                if(itr->second.calls != 1)
                {
                    if(itr->second.calls > 1)
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
    class LuaWorldScript : public WorldScript, public luaEventMap
    {
    public:
        LuaWorldScript() : WorldScript("LuaWorldScript"), luaEventMap() {}

        void OnUpdate(uint32 diff)
        {
            LuaEventsUpdate(diff);
            LuaEventsExecute();
        }

        // executed when a  timed event fires
        void OnLuaEvent(int funcRef, uint32 delay, uint32 calls)
        {
            Eluna::get()->BeginCall(funcRef);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, funcRef);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, delay);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, calls);
            Eluna::get()->ExecuteCall(3, 0);
        }
    };

public:
    class LuaCreatureScript : CreatureScript
    {
    public:
        struct LuaCreatureAI;
        vector<LuaCreatureAI*> _scriptsToClear;

    public:
        bool IsDatabaseBound() const { return false; }

        LuaCreatureScript() : CreatureScript("luacreature")
        {
            _scriptsToClear = *(new vector<LuaCreatureAI*>());
        }

        ~LuaCreatureScript() { }

        static CreatureBind* GetCreatureBindingForId(uint32 id)
        {
            for (vector<CreatureBind*>::iterator itr = Eluna::get()->_creatureEventBindings.begin(); itr != Eluna::get()->_creatureEventBindings.end(); ++itr)
                if ((*itr)->entry == id)
                    return (*itr);
            return NULL;
        }

        static CreatureBind* GetCreatureGossipBindingForId(uint32 id)
        {
            for (vector<CreatureBind*>::iterator itr = Eluna::get()->_gossipEventBindings.begin(); itr != Eluna::get()->_gossipEventBindings.end(); ++itr)
                if ((*itr)->entry == id)
                    return (*itr);
            return NULL;
        }

        bool RegisterCreatureScript(uint32 id, uint32 _event, uint16 functionRef)
        {
            if (!sObjectMgr->GetCreatureTemplate(id))
            {
                sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a creature with (ID: %d)!", id);
                return false;
            }

            Eluna::get()->_creatureEventBindings.push_back(new CreatureBind(id));
            GetCreatureBindingForId(id)->_functionReferences[_event] = functionRef;
            return true;
        }

        bool RegisterGossipScript(uint32 id, uint32 _event, uint16 functionRef)
        {
            if (!sObjectMgr->GetCreatureTemplate(id))
            {
                sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a creature with (ID: %d)!", id);
                return false;
            }

            Eluna::get()->_gossipEventBindings.push_back(new CreatureBind(id));
            GetCreatureGossipBindingForId(id)->_gossipReferences[_event] = functionRef;
            return true;
        }

        struct LuaCreatureAI : ScriptedAI, public luaEventMap
        {
            LuaCreatureAI(Creature* creature) : ScriptedAI(creature), luaEventMap()
            {
                binding = GetCreatureBindingForId(creature->GetEntry());
            }
            ~LuaCreatureAI() { }
            CreatureBind* binding;

            //Called at World update tick
            void UpdateAI(uint32 const diff)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                LuaEventsUpdate(diff);
                LuaEventsExecute();
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_AIUPDATE]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_AIUPDATE);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, diff);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::UpdateAI(diff);
            }

            // executed when a  timed event fires
            void OnLuaEvent(int funcRef, uint32 delay, uint32 calls)
            {
                Eluna::get()->BeginCall(funcRef);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, funcRef);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, delay);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, calls);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->ExecuteCall(4, 0);
            }

            //Called for reaction at enter to combat if not in combat yet (enemy can be NULL)
            //Called at creature aggro either by MoveInLOS or Attack Start
            void EnterCombat(Unit* target)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_ENTER_COMBAT]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_ENTER_COMBAT);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, target);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::EnterCombat(target);
            }

            // Called at any Damage from any attacker (before damage apply)
            void DamageTaken(Unit* attacker, uint32& damage)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_DAMAGE_TAKEN]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_DAMAGE_TAKEN);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, attacker);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, damage);
                Eluna::get()->ExecuteCall(4, 0);
                ScriptedAI::DamageTaken(attacker, damage);
            }

            //Called at creature death
            void JustDied(Unit* killer)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_DIED]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_DIED);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, killer);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::JustDied(killer);
            }

            //Called at creature killing another unit
            void KilledUnit(Unit* victim)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_TARGET_DIED]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_TARGET_DIED);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, victim);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::KilledUnit(victim);
            }

            // Called when the creature summon successfully other creature
            void JustSummoned(Creature* summon)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, summon);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::JustSummoned(summon);
            }

            // Called when a summoned creature is despawned
            void SummonedCreatureDespawn(Creature* summon)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, summon);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::SummonedCreatureDespawn(summon);
            }

            // Called when hit by a spell
            void SpellHit(Unit* caster, SpellInfo const* spell)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_HIT_BY_SPELL]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_HIT_BY_SPELL);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, caster);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, spell->Id); // Pass spell object?
                Eluna::get()->ExecuteCall(4, 0);
                ScriptedAI::SpellHit(caster, spell);
            }

            // Called when spell hits a target
            void SpellHitTarget(Unit* target, SpellInfo const* spell)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_SPELL_HIT_TARGET]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_SPELL_HIT_TARGET);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, target);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, spell->Id); // Pass spell object?
                Eluna::get()->ExecuteCall(4, 0);
                ScriptedAI::SpellHitTarget(target, spell);
            }

            //Called at waypoint reached or PointMovement end
            void MovementInform(uint32 type, uint32 id)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_REACH_WP]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_REACH_WP);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, type);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, id);
                Eluna::get()->ExecuteCall(4, 0);
                ScriptedAI::MovementInform(type, id);
            }

            // Called when AI is temporarily replaced or put back when possess is applied or removed
            void OnPossess(bool apply)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_POSSESS]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_POSSESS);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushBoolean(Eluna::get()->_luaState, apply);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::OnPossess(apply);
            }

            //Called at creature reset either by death or evade
            void Reset()
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_RESET]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_RESET);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->ExecuteCall(2, 0);
                ScriptedAI::Reset();
            }

            // Called before EnterCombat even before the creature is in combat.
            void AttackStart(Unit* target)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_PRE_COMBAT]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_PRE_COMBAT);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, target);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::AttackStart(target);
            }

            // Called in Creature::Update when deathstate = DEAD. Inherited classes may maniuplate the ability to respawn based on scripted events.
            bool CanRespawn()
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return true;
                bool result = true;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_CAN_RESPAWN]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_CAN_RESPAWN);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                if(Eluna::get()->ExecuteCall(2, 1))
                {
                    lua_State* L = Eluna::get()->_luaState;
                    if(!lua_isnoneornil(L, 1) && !luaL_checkbool(L, 1))
                        result = false;
                    Eluna::get()->EndCall(1);
                }
                ScriptedAI::CanRespawn();
                return result;
            }

            // Called for reaction at stopping attack at no attackers or targets
            void EnterEvadeMode()
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_LEAVE_COMBAT]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_LEAVE_COMBAT);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->ExecuteCall(2, 0);
                ScriptedAI::EnterEvadeMode();
            }

            // Called when the creature is summoned successfully by other creature
            void IsSummonedBy(Unit* summoner)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_SUMMONED]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_SUMMONED);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, summoner);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::IsSummonedBy(summoner);
            }

            void SummonedCreatureDies(Creature* summon, Unit* killer)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, summon);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, killer);
                Eluna::get()->ExecuteCall(4, 0);
                ScriptedAI::SummonedCreatureDies(summon, killer);
            }

            // Called when the creature is target of hostile action: swing, hostile spell landed, fear/etc)
            void AttackedBy(Unit* attacker)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_ATTACKED_AT]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_ATTACKED_AT);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, attacker);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::AttackedBy(attacker);
            }

            // Called when creature is spawned or respawned (for reseting variables)
            void JustRespawned()
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_SPAWN]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_SPAWN);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->ExecuteCall(2, 0);
                ScriptedAI::JustRespawned();
            }

            void OnCharmed(bool apply)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_CHARMED]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_CHARMED);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushBoolean(Eluna::get()->_luaState, apply);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::OnCharmed(apply);
            }

            // Called at reaching home after evade
            void JustReachedHome()
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_REACH_HOME]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_REACH_HOME);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->ExecuteCall(2, 0);
                ScriptedAI::JustReachedHome();
            }

            // Called at text emote receive from player
            void ReceiveEmote(Player* player, uint32 emoteId)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_RECEIVE_EMOTE]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_RECEIVE_EMOTE);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, emoteId);
                Eluna::get()->ExecuteCall(4, 0);
                ScriptedAI::ReceiveEmote(player, emoteId);
            }

            // Called when owner takes damage
            void OwnerAttackedBy(Unit* attacker)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_OWNER_ATTACKED_AT]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_OWNER_ATTACKED_AT);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, attacker);
                Eluna::get()->ExecuteCall(3, 0);
            }

            // Called when owner attacks something
            void OwnerAttacked(Unit* target)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_OWNER_ATTACKED_AT]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_OWNER_ATTACKED_AT);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, target);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::OwnerAttacked(target);
            }

            // called when the corpse of this creature gets removed
            void CorpseRemoved(uint32& respawnDelay)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_CORPSE_REMOVED]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_CORPSE_REMOVED);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, respawnDelay);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::CorpseRemoved(respawnDelay);
            }

            void PassengerBoarded(Unit* passenger, int8 seatId, bool apply)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_PASSANGER_BOARDED]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_PASSANGER_BOARDED);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, passenger);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, seatId);
                Eluna::get()->PushBoolean(Eluna::get()->_luaState, apply);
                Eluna::get()->ExecuteCall(5, 0);
                ScriptedAI::PassengerBoarded(passenger, seatId, apply);
            }

            void OnSpellClick(Unit* clicker)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_SPELL_CLICK]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_SPELL_CLICK);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, clicker);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::OnSpellClick(clicker);
            }

            void MoveInLineOfSight(Unit* who)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_MOVE_IN_LOS]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_MOVE_IN_LOS);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, who);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::MoveInLineOfSight(who);
            }

            // Called if IsVisible(Unit* who) is true at each who move, reaction at visibility zone enter
            void MoveInLineOfSight_Safe(Unit* who)
            {
                CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(me->GetEntry());
                if(!bind)
                    return;
                Eluna::get()->BeginCall(bind->_functionReferences[CREATURE_EVENT_ON_MOVE_IN_LOS]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, who);
                Eluna::get()->ExecuteCall(3, 0);
                ScriptedAI::MoveInLineOfSight_Safe(who);
            }
        };

        LuaCreatureAI* GetLuaAI(Creature* creature)
        {
            CreatureBind* bind = GetCreatureBindingForId(creature->GetEntry());
            if (!bind)
                return NULL;

            if (!_scriptsToClear.empty())
                for (vector<LuaCreatureAI*>::iterator itr = _scriptsToClear.begin(); itr != _scriptsToClear.end(); ++itr)
                    if ((*itr) && (*itr)->binding->entry == creature->GetEntry())
                        return (*itr);

            LuaCreatureAI* luaCreatureAI = new LuaCreatureAI(creature);
            _scriptsToClear.push_back(luaCreatureAI);
            return luaCreatureAI;
        }

        CreatureAI* GetAI(Creature* creature)
        {
            return GetLuaAI(creature);
        }
    };

public:
    class LuaGameObjectScript : GameObjectScript
    {
    public:
        struct LuaGameObjectAI;
        vector<LuaGameObjectAI*> _scriptsToClear;
    public:
        bool IsDatabaseBound() const { return false; }

        LuaGameObjectScript() : GameObjectScript("LuaGameObjectScript")
        {
            _scriptsToClear = *(new vector<LuaGameObjectAI*>());
        }

        ~LuaGameObjectScript() { }

        static GameObjectBind* GetGameObjectAIBindingForId(uint32 entry)
        {
            for(vector<GameObjectBind*>::iterator itr = Eluna::get()->_gameObjectAIEventBindings.begin(); itr != Eluna::get()->_gameObjectAIEventBindings.end(); ++itr)
                if ((*itr)->entry == entry)
                    return (*itr);
            return NULL;
        }

        static GameObjectBind* GetGameObjectGossipBindingForId(uint32 entry)
        {
            for(vector<GameObjectBind*>::iterator itr = Eluna::get()->_gameObjectGossipBindings.begin(); itr != Eluna::get()->_gameObjectGossipBindings.end(); ++itr)
                if ((*itr)->entry == entry)
                    return (*itr);
            return NULL;
        }

        bool RegisterGameObjectScript(uint32 id, uint32 _event, uint16 functionRef)
        {
            if (!sObjectMgr->GetGameObjectTemplate(id))
            {
                sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a gameobject with (ID: %d)!", id);
                return false;
            }

            Eluna::get()->_gameObjectAIEventBindings.push_back(new GameObjectBind(id));
            GetGameObjectAIBindingForId(id)->_functionReferences[_event] = functionRef;
            return true;
        }

        bool RegisterGameObjectGossipScript(uint32 id, uint32 _event, uint16 functionRef)
        {
            if (!sObjectMgr->GetGameObjectTemplate(id))
            {
                sLog->outError(LOG_FILTER_GENERAL, "Eluna Nova::Couldn't find a gameobject with (ID: %d)!", id);
                return false;
            }

            Eluna::get()->_gameObjectGossipBindings.push_back(new GameObjectBind(id));
            GetGameObjectGossipBindingForId(id)->_gossipReferences[_event] = functionRef;
            return true;
        }

        struct LuaGameObjectAI : GameObjectAI, public luaEventMap
        {
            LuaGameObjectAI(GameObject* _go) : GameObjectAI(_go), luaEventMap()
            {
                goBinding = LuaGameObjectScript::GetGameObjectAIBindingForId(_go->GetEntry());
            }

            ~LuaGameObjectAI() { }
            GameObjectBind * goBinding;

            void UpdateAI(uint32 diff)
            {
                LuaEventsUpdate(diff);
                LuaEventsExecute();
                Eluna::get()->BeginCall(GetGameObjectAIBindingForId(go->GetEntry())->_functionReferences[GAMEOBJECT_EVENT_ON_AIUPDATE]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, GAMEOBJECT_EVENT_ON_AIUPDATE);
                Eluna::get()->PushGO(Eluna::get()->_luaState, go);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, diff);
                Eluna::get()->ExecuteCall(3, 0);
            }

            // executed when a  timed event fires
            void OnLuaEvent(int funcRef, uint32 delay, uint32 calls)
            {
                Eluna::get()->BeginCall(funcRef);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, funcRef);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, delay);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, calls);
                Eluna::get()->PushGO(Eluna::get()->_luaState, go);
                Eluna::get()->ExecuteCall(4, 0);
            }

            void Reset()
            {
                Eluna::get()->BeginCall(GetGameObjectAIBindingForId(go->GetEntry())->_functionReferences[GAMEOBJECT_EVENT_ON_RESET]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, GAMEOBJECT_EVENT_ON_RESET);
                Eluna::get()->PushGO(Eluna::get()->_luaState, go);
                Eluna::get()->ExecuteCall(2, 0);
            }

            void DoAction(const int32 param)
            {
                Eluna::get()->BeginCall(GetGameObjectAIBindingForId(go->GetEntry())->_functionReferences[GAMEOBJECT_EVENT_DOACTION]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, GAMEOBJECT_EVENT_DOACTION);
                Eluna::get()->PushGO(Eluna::get()->_luaState, go);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, param);
                Eluna::get()->ExecuteCall(3, 0);
            }

            void SetGUID(uint64 guid, int32 id)
            {
                Eluna::get()->BeginCall(GetGameObjectAIBindingForId(go->GetEntry())->_functionReferences[GAMEOBJECT_EVENT_ON_SET_GUID]);
                Eluna::get()->PushInteger(Eluna::get()->_luaState, GAMEOBJECT_EVENT_ON_SET_GUID);
                Eluna::get()->PushGO(Eluna::get()->_luaState, go);
                Eluna::get()->PushGUID(Eluna::get()->_luaState, guid);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, id);
                Eluna::get()->ExecuteCall(4, 0);
            }
        };

        LuaGameObjectAI* GetLuaAI(GameObject* gameObject)
        {
            GameObjectBind* bind = GetGameObjectAIBindingForId(gameObject->GetEntry());
            if (!bind)
                return NULL;

            if (!_scriptsToClear.empty())
                for (vector<LuaGameObjectAI*>::iterator itr = _scriptsToClear.begin(); itr != _scriptsToClear.end(); ++itr)
                    if ((*itr) && (*itr)->goBinding->entry == gameObject->GetEntry())
                        return (*itr);

            LuaGameObjectAI* luaGameObjectAI = new LuaGameObjectAI(gameObject);
            _scriptsToClear.push_back(luaGameObjectAI);
            return luaGameObjectAI;
        }

        GameObjectAI* GetAI(GameObject* gameObject)
        {
            return GetLuaAI(gameObject);
        }
    };
};

#define sLuaCreatureScript ACE_Singleton<Eluna::LuaCreatureScript, ACE_Null_Mutex>::instance()
#define sLuaGameObjectScript ACE_Singleton<Eluna::LuaGameObjectScript, ACE_Null_Mutex>::instance()
#define sLuaWorldScript ACE_Singleton<Eluna::LuaWorldScript, ACE_Null_Mutex>::instance()

class ElunaScript : public ScriptObject
{
public:
    static ElunaScript* get()
    {
        return Eluna::Script;
    }

    ElunaScript(char const* name) : ScriptObject(name)
    {
    }

    bool IsDatabaseBound() const { return false; }

    ~ElunaScript()
    {
        delete this;
    }

    /* Item & player Gossip */
    bool OnGossipHello(uint32 eventId, Player* player, Item* item)
    {
        for(vector<ItemBind*>::iterator itr = Eluna::get()->_itemGossipBindings.begin(); itr != Eluna::get()->_itemGossipBindings.end(); ++itr)
        {
            if ((*itr)->entry == item->GetEntry())
            {
                player->PlayerTalkClass->ClearMenus();
                Eluna::get()->BeginCall((*itr)->_gossipReferences[eventId]);
                Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
                Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
                Eluna::get()->PushItem(Eluna::get()->_luaState, item);
                Eluna::get()->ExecuteCall(3, 0);
            }
        }
        return true;
    }

    void HandleGossipSelectOption(Player* player, uint64 guid, uint32 sender, uint32 action, std::string code, uint32 menuId)
    {
        if(!player || !player->IsInWorld() || !player->isAlive() || player->GetCharmerGUID())
            return;

        if (player->HasUnitState(UNIT_STATE_DIED))
            player->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);
        player->PlayerTalkClass->ClearMenus();

        if(IS_ITEM_GUID(guid))
        {
            Item* item = player->GetItemByGuid(guid);
            if(!item)
                return;

            for(vector<ItemBind*>::iterator itr = Eluna::get()->_itemGossipBindings.begin(); itr != Eluna::get()->_itemGossipBindings.end(); ++itr)
            {
                if ((*itr)->entry == item->GetEntry())
                {
                    Eluna::get()->BeginCall((*itr)->_gossipReferences[GOSSIP_EVENT_ON_SELECT]);
                    Eluna::get()->PushUnsigned(Eluna::get()->_luaState, GOSSIP_EVENT_ON_SELECT);
                    Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
                    Eluna::get()->PushItem(Eluna::get()->_luaState, item);
                    Eluna::get()->PushUnsigned(Eluna::get()->_luaState, sender);
                    Eluna::get()->PushUnsigned(Eluna::get()->_luaState, action);
                    if(code.empty())
                        lua_pushnil(Eluna::get()->_luaState);
                    else
                        Eluna::get()->PushString(Eluna::get()->_luaState, code.c_str());
                    Eluna::get()->ExecuteCall(6, 0);
                }
            }
        }
        else if(IS_PLAYER_GUID(guid))
        {
            if(player->GetGUID() != guid)
                return;

            for(vector<PlayerBind*>::iterator itr = Eluna::get()->_playerGossipBindings.begin(); itr != Eluna::get()->_playerGossipBindings.end(); ++itr)
            {
                if ((*itr)->menu_id == menuId)
                {
                    Eluna::get()->BeginCall((*itr)->_gossipReferences[GOSSIP_EVENT_ON_SELECT]);
                    Eluna::get()->PushUnsigned(Eluna::get()->_luaState, GOSSIP_EVENT_ON_SELECT);
                    Eluna::get()->PushUnit(Eluna::get()->_luaState, player); // receiver
                    Eluna::get()->PushUnit(Eluna::get()->_luaState, player); // sender, just not to mess up the amount of args.
                    Eluna::get()->PushUnsigned(Eluna::get()->_luaState, sender);
                    Eluna::get()->PushUnsigned(Eluna::get()->_luaState, action);
                    if(code.empty())
                        lua_pushnil(Eluna::get()->_luaState);
                    else
                        Eluna::get()->PushString(Eluna::get()->_luaState, code.c_str());
                    Eluna::get()->PushUnsigned(Eluna::get()->_luaState, menuId);
                    Eluna::get()->ExecuteCall(6, 0);
                }
            }
        }
    }

    void OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, string& msg)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushString(Eluna::get()->_luaState, msg.c_str());
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, type);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, lang);
            Eluna::get()->ExecuteCall(5, 0);
        }
    }

    void OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, string& msg, Player* receiver)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushString(Eluna::get()->_luaState, msg.c_str());
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, type);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, lang);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, receiver);
            Eluna::get()->ExecuteCall(6, 0);
        }
    }

    void OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, string& msg, Group* group)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushString(Eluna::get()->_luaState, msg.c_str());
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, type);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, lang);
            Eluna::get()->PushGroup(Eluna::get()->_luaState, group);
            Eluna::get()->ExecuteCall(6, 0);
        }
    }

    void OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, string& msg, Guild* guild)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushString(Eluna::get()->_luaState, msg.c_str());
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, type);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, lang);
            Eluna::get()->PushGuild(Eluna::get()->_luaState, guild);
            Eluna::get()->ExecuteCall(6, 0);
        }
    }

    void OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, string& msg, Channel* channel)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushString(Eluna::get()->_luaState, msg.c_str());
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, type);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, lang);
            Eluna::get()->PushChannel(Eluna::get()->_luaState, channel);
            Eluna::get()->ExecuteCall(6, 0);
        }
    }

    void OnPvPKill(uint32 eventId, Player* killer, Player* victim)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, killer);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, victim);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerLevelChanged(uint32 eventId, Player* player, uint8 oldLevel)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, oldLevel);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerTalentsChanged(uint32 eventId, Player* player, uint32 points)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, points);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnCreatureKill(uint32 eventId, Player* player, Creature* creature)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, creature);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerKilledByCreature(uint32 eventId, Creature* creature, Player* player)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, creature);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerTalentsReset(uint32 eventId, Player* player, bool noCost)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushBoolean(Eluna::get()->_luaState, noCost);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerMoneyChanged(uint32 eventId, Player* player, int32& amount)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, amount);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnGivePlayerXP(uint32 eventId, Player* player, uint32& amount, Unit* victim)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, amount);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, victim);
            Eluna::get()->ExecuteCall(4, 0);
        }
    }

    void OnPlayerReputationChange(uint32 eventId, Player* player, uint32 factionID, int32& standing, bool incremental)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, factionID);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, standing);
            Eluna::get()->PushBoolean(Eluna::get()->_luaState, incremental);
            Eluna::get()->ExecuteCall(5, 0);
        }
    }

    void OnPlayerDuelRequest(uint32 eventId, Player* target, Player* challenger)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, target);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, challenger);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerDuelStart(uint32 eventId, Player* player1, Player* player2)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player1);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player2);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerDuelEnd(uint32 eventId, Player* winner, Player* loser, DuelCompleteType type)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, winner);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, loser);
            Eluna::get()->PushInteger(Eluna::get()->_luaState, type);
            Eluna::get()->ExecuteCall(4, 0);
        }
    }

    void OnPlayerEmote(uint32 eventId, Player* player, uint32 emote)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, emote);
            Eluna::get()->ExecuteCall(3, 0);
        }
    }

    void OnPlayerLogin(uint32 eventId, Player* player)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->ExecuteCall(2, 0);
        }
    }

    void OnPlayerLogout(uint32 eventId, Player* player)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->ExecuteCall(2, 0);
        }
    }

    void OnPlayerCreate(uint32 eventId, Player* player)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->ExecuteCall(2, 0);
        }
    }

    void OnPlayerSave(uint32 eventId, Player* player)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->ExecuteCall(2, 0);
        }
    }

    void OnPlayerBindToInstance(uint32 eventId, Player* player, Difficulty difficulty, uint32 mapid, bool permanent)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushInteger(Eluna::get()->_luaState, difficulty);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, mapid);
            Eluna::get()->PushBoolean(Eluna::get()->_luaState, permanent);
            Eluna::get()->ExecuteCall(5, 0);
        }
    }

    void OnPlayerUpdateZone(uint32 eventId, Player* player, uint32 newZone, uint32 newArea)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, newZone);
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, newArea);
            Eluna::get()->ExecuteCall(4, 0);
        }
    }

    void OnPlayerDelete(uint32 eventId, uint64 guid)
    {
        for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
            itr != Eluna::get()->_serverEventBindings.at(eventId).end(); itr++)
        {
            Eluna::get()->BeginCall((*itr));
            Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
            Eluna::get()->PushGUID(Eluna::get()->_luaState, guid);
            Eluna::get()->ExecuteCall(2, 0);
        }
    }

	bool OnTrigger(uint32 eventId, Player* player, AreaTriggerEntry const* trigger)
	{
		bool result = true;
		for (vector<uint16>::iterator itr = Eluna::get()->_serverEventBindings.at(eventId).begin();
			itr != Eluna::get()->_serverEventBindings.at(eventId).end(); ++itr)
		{
			Eluna::get()->BeginCall((*itr));
			Eluna::get()->PushInteger(Eluna::get()->_luaState, eventId);
			Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
			Eluna::get()->PushUnsigned(Eluna::get()->_luaState, trigger->id);
			if(Eluna::get()->ExecuteCall(3, 1))
			{
				lua_State* L = Eluna::get()->_luaState;
				if(!lua_isnoneornil(L, 1) && !luaL_checkbool(L, 1))
				result = false;
				Eluna::get()->EndCall(1);
			}
		}
		return result;
	}

    bool OnGossipHello(uint32 eventId, Player* player, Creature* creature)
    {
        player->PlayerTalkClass->ClearMenus();
        Eluna::get()->BeginCall(Eluna::LuaCreatureScript::GetCreatureGossipBindingForId(creature->GetEntry())->_gossipReferences[eventId]);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, creature);
        Eluna::get()->ExecuteCall(3, 0);
        return true;
    }

    bool OnGossipSelect(uint32 eventId, Player* player, Creature* creature, uint32 sender, uint32 actions)
    {
        player->PlayerTalkClass->ClearMenus();
        Eluna::get()->BeginCall(Eluna::LuaCreatureScript::GetCreatureGossipBindingForId(creature->GetEntry())->_gossipReferences[eventId]);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, creature);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, sender);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, actions);
        Eluna::get()->ExecuteCall(5, 0);
        return true;
    }

    bool OnGossipSelectCode(uint32 eventId, Player* player, Creature* creature, uint32 sender, uint32 actions, const char* code)
    {
        CreatureBind* bind = Eluna::LuaCreatureScript::GetCreatureBindingForId(creature->GetEntry());
        if(!bind)
            return false;
        player->PlayerTalkClass->ClearMenus();
        Eluna::get()->BeginCall(Eluna::LuaCreatureScript::GetCreatureGossipBindingForId(creature->GetEntry())->_gossipReferences[eventId]);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, creature);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, sender);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, actions);
        Eluna::get()->PushString(Eluna::get()->_luaState, code);
        Eluna::get()->ExecuteCall(6, 0);
        return true;
    }

    /* GameObject Gossip */
    bool OnGossipHello(uint32 eventId, Player* player, GameObject* gameObject)
    {
        player->PlayerTalkClass->ClearMenus();
        Eluna::get()->BeginCall(Eluna::LuaGameObjectScript::GetGameObjectGossipBindingForId(gameObject->GetEntry())->_gossipReferences[eventId]);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
        Eluna::get()->PushGO(Eluna::get()->_luaState, gameObject);
        Eluna::get()->ExecuteCall(3, 0);
        return true;
    }

    bool OnGossipSelect(uint32 eventId, Player* player, GameObject* gameObject, uint32 sender, uint32 actions)
    {
        player->PlayerTalkClass->ClearMenus();
        Eluna::get()->BeginCall(Eluna::LuaGameObjectScript::GetGameObjectGossipBindingForId(gameObject->GetEntry())->_gossipReferences[eventId]);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
        Eluna::get()->PushGO(Eluna::get()->_luaState, gameObject);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, sender);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, actions);
        Eluna::get()->ExecuteCall(5, 0);
        return true;
    }

    bool OnGossipSelectCode(uint32 eventId, Player* player, GameObject* gameObject, uint32 sender, uint32 actions, const char* code)
    {
        player->PlayerTalkClass->ClearMenus();
        Eluna::get()->BeginCall(Eluna::LuaGameObjectScript::GetGameObjectGossipBindingForId(gameObject->GetEntry())->_gossipReferences[eventId]);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
        Eluna::get()->PushGO(Eluna::get()->_luaState, gameObject);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, sender);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, actions);
        Eluna::get()->PushString(Eluna::get()->_luaState, code);
        Eluna::get()->ExecuteCall(6, 0);
        return true;
    }

    // Called when a dummy spell effect is triggered on the gameobject.
    bool OnDummyEffect(uint32 eventId, Unit* caster, uint32 spellId, SpellEffIndex effIndex, GameObject* go)
    {
        bool result = true;
        Eluna::get()->BeginCall(Eluna::LuaGameObjectScript::GetGameObjectAIBindingForId(go->GetEntry())->_functionReferences[eventId]);
        Eluna::get()->PushInteger(Eluna::get()->_luaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, caster);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, spellId);
        Eluna::get()->PushInteger(Eluna::get()->_luaState, effIndex);
        Eluna::get()->PushGO(Eluna::get()->_luaState, go);
        if(Eluna::get()->ExecuteCall(5, 1))
        {
            lua_State* L = Eluna::get()->_luaState;
            if(!lua_isnoneornil(L, 1) && !luaL_checkbool(L, 1))
                result = false;
            Eluna::get()->EndCall(1);
        }
        return result;
    }

    // Called when a player accepts a quest from the gameobject.
    bool OnQuestAccept(uint32 eventId, Player* player, GameObject* go, Quest const* quest)
    {
        bool result = true;
        Eluna::get()->BeginCall(Eluna::LuaGameObjectScript::GetGameObjectAIBindingForId(go->GetEntry())->_functionReferences[eventId]);
        Eluna::get()->PushInteger(Eluna::get()->_luaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
        Eluna::get()->PushGO(Eluna::get()->_luaState, go);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, quest->GetQuestId());

        if(Eluna::get()->ExecuteCall(4, 1))
        {
            lua_State* L = Eluna::get()->_luaState;
            if(!lua_isnoneornil(L, 1) && !luaL_checkbool(L, 1))
                result = false;
            Eluna::get()->EndCall(1);
        }
        return result;
    }

    // Called when a player selects a quest reward.
    bool OnQuestReward(uint32 eventId, Player* player, GameObject* go, Quest const* quest, uint32 opt)
    {
        bool result = true;
        Eluna::get()->BeginCall(Eluna::LuaGameObjectScript::GetGameObjectAIBindingForId(go->GetEntry())->_functionReferences[eventId]);
        Eluna::get()->PushInteger(Eluna::get()->_luaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
        Eluna::get()->PushGO(Eluna::get()->_luaState, go);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, quest->GetQuestId());
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, opt);
        if(Eluna::get()->ExecuteCall(5, 1))
        {
            lua_State* L = Eluna::get()->_luaState;
            if(!lua_isnoneornil(L, 1) && !luaL_checkbool(L, 1))
                result = false;
            Eluna::get()->EndCall(1);
        }
        return result;
    }

    uint32 GetDialogStatus(uint32 eventId, Player* player, GameObject* go)
    {
        uint32 result = 100;
        Eluna::get()->BeginCall(Eluna::LuaGameObjectScript::GetGameObjectAIBindingForId(go->GetEntry())->_functionReferences[eventId]);
        Eluna::get()->PushInteger(Eluna::get()->_luaState, eventId);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
        Eluna::get()->PushGO(Eluna::get()->_luaState, go);
        if(Eluna::get()->ExecuteCall(3, 1))
        {
            lua_State* L = Eluna::get()->_luaState;
            if(!lua_isnoneornil(L, 1) && lua_isnumber(L, 1))
                result = luaL_checkunsigned(L, 1);
            Eluna::get()->EndCall(1);
        }
        return result;
    }

    // Called when the game object is destroyed (destructible buildings only).
    void OnDestroyed(uint32 eventId, GameObject* go, Player* player)
    {
        Eluna::get()->BeginCall(Eluna::LuaGameObjectScript::GetGameObjectAIBindingForId(go->GetEntry())->_functionReferences[eventId]);
        Eluna::get()->PushInteger(Eluna::get()->_luaState, eventId);
        Eluna::get()->PushGO(Eluna::get()->_luaState, go);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
        Eluna::get()->ExecuteCall(3, 0);
    }

    // Called when the game object is damaged (destructible buildings only).
    void OnFirstDamaged(uint32 eventId, GameObject* go, Player* player)
    {
        Eluna::get()->BeginCall(Eluna::LuaGameObjectScript::GetGameObjectAIBindingForId(go->GetEntry())->_functionReferences[eventId]);
        Eluna::get()->PushInteger(Eluna::get()->_luaState, eventId);
        Eluna::get()->PushGO(Eluna::get()->_luaState, go);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, player);
        Eluna::get()->ExecuteCall(3, 0);
    }

    // Called when the game object loot state is changed.
    void OnLootStateChanged(uint32 eventId, GameObject* go, uint32 state, Unit* unit)
    {
        Eluna::get()->BeginCall(Eluna::LuaGameObjectScript::GetGameObjectAIBindingForId(go->GetEntry())->_functionReferences[eventId]);
        Eluna::get()->PushInteger(Eluna::get()->_luaState, eventId);
        Eluna::get()->PushGO(Eluna::get()->_luaState, go);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, state);
        Eluna::get()->PushUnit(Eluna::get()->_luaState, unit);
        Eluna::get()->ExecuteCall(4, 0);
    }

    // Called when the game object state is changed.
    void OnGameObjectStateChanged(uint32 eventId, GameObject* go, uint32 state)
    {
        Eluna::get()->BeginCall(Eluna::LuaGameObjectScript::GetGameObjectAIBindingForId(go->GetEntry())->_functionReferences[eventId]);
        Eluna::get()->PushInteger(Eluna::get()->_luaState, eventId);
        Eluna::get()->PushGO(Eluna::get()->_luaState, go);
        Eluna::get()->PushUnsigned(Eluna::get()->_luaState, state);
        Eluna::get()->ExecuteCall(3, 0);
    }
};
#endif