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
#include "GlobalMethods.h"
#include "PlayerMethods.h"
#include "ScriptMgr.h"

using namespace std;

#define lua_ref(L, lock) ((lock) ? luaL_ref(L, LUA_REGISTRYINDEX) : \
	(lua_pushstring(L, "unlocked references are obsolete"), lua_error(L), 0))

extern "C" 
{
		#include "../../dep/lualib/lua.h"
        #include "../../dep/lualib/lualib.h"
        #include "../../dep/lualib/lauxlib.h"
};

class LuaPlayer;
class ElunaTemplate;
class ElunaScript;

struct LoadedScripts
{
    std::set<std::string> luaFiles;
};

enum REGISTER_TYPE
{
    REGTYPE_PLAYER = 1,
    REGTYPE_GOSSIP = 2,
    REGTYPE_CREATURE = 3,
	REGTYPE_LOG = 4,
    REGTYPE_COUNT
};

enum PlayerEvents
{
	PLAYER_EVENT_ON_CHARACTER_CREATE		= 1,
	PLAYER_EVENT_ON_KILL_PLAYER             = 2,
    PLAYER_EVENT_ON_LOGIN                   = 4,
    PLAYER_EVENT_ON_LOGOUT                  = 13,
	PLAYER_EVENT_ON_CHAT                    = 16,
	PLAYER_EVENT_LEVEL_CHANGE	            = 27,
	PLAYER_EVENT_ON_CHARACTER_DELETE		= 33,
	PLAYER_EVENT_ON_TALENTS_CHANGE          = 34,
	PLAYER_EVENT_ON_TALENTS_RESET           = 35,
    PLAYER_EVENT_COUNT
};

enum CreatureEvents
{
    CREATURE_EVENT_ON_COMBAT                = 1,
    CREATURE_EVENT_ON_LEAVE_COMBAT  = 2,
    CREATURE_EVENT_ON_TARGET_DIED   = 3,
    CREATURE_EVENT_ON_DIED                  = 4,
    CREATURE_EVENT_ON_SPAWN                 = 5,
    CREATURE_EVENT_ON_UPDATE                = 6,
    CREATURE_EVENT_COUNT
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
     static Eluna * LuaEngine;
     static ElunaScript * Script;

	public:
		static Eluna * get() { return LuaEngine; }
		static ElunaScript * getScript() { return Script; }

		typedef map<int, std::vector<uint16>> ElunaBindingMap;
		ElunaBindingMap m_playerEventBindings;
		ElunaBindingMap m_gossipEventBindings;

		static void InitTables()
		{
			for (int i = 0; i < PLAYER_EVENT_COUNT; i++)
			{
				vector<uint16> _vector;
				get()->m_playerEventBindings.insert(pair<int, vector<uint16>>(i, _vector));
			}

			for (int i = 0; i < GOSSIP_EVENT_COUNT; i++)
			{
				vector<uint16> _vector;
				get()->m_gossipEventBindings.insert(pair<int, vector<uint16>>(i, _vector));
			}
		}

		~Eluna()
		{
			m_gossipEventBindings.clear();
			m_playerEventBindings.clear();
			//delete Script;
		}

		lua_State * m_luaState;

		void StartEluna();
		void Register(uint8 reg, uint32 id, uint32 evt, uint16 fuc);

		static void report(lua_State *);


        void BeginCall(uint16 fReference)
        {
                lua_settop(m_luaState, 0); //stack should be empty
				lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, (fReference));
        }

        bool ExecuteCall(uint8 params, uint8 res)
        {
                bool ret = true;
                int top = lua_gettop(m_luaState); 
                if(strcmp(luaL_typename(m_luaState,top-params), "function") )
                {
                        ret = false;
                        if(params > 0)
                        {
                                for(int i = top; i >= (top-params); i--)
                                {
                                        if(!lua_isnone(m_luaState, i) )
                                                lua_remove(m_luaState, i);
                                }
                        }
                }
                else
                {
                        if(lua_pcall(m_luaState,params,res,0) )
                        {
                                report(m_luaState);
                                ret = false;
                        }
                }
                return ret;
        }

        void EndCall(uint8 res) 
        {
                for(int i = res; i > 0; i--)
                {
                        if(!lua_isnone(m_luaState,res))
                                lua_remove(m_luaState,res);
                }
        }
		static void Init();
		void RegisterGlobals(lua_State * L);
		void LoadDirectory(char * directory, LoadedScripts * scr);
		// Push
		void PushPlayer(lua_State * L, Player * player);
		void PushCreature(lua_State * L, Creature*);
        void PushLong(lua_State * L, uint64);
        void PushInteger(lua_State*, uint32);
        void PushString(lua_State*, const char*);
        void PushGroup(lua_State*, Group*);
        void PushGuild(lua_State*, Guild*);

		// Checks

        Player * CHECK_PLAYER(lua_State* L, int narg)
        {
            if(L == NULL) 
				return ElunaTemplate<Player>::check(m_luaState, narg);
            else 
				return ElunaTemplate<Player>::check(L, narg);
        }

	protected:
		template<typename T>
		class ElunaTemplate
		{
			public:
                typedef int (*m_funcptr)(lua_State* L, T* ptr);
                typedef struct { const char* name; m_funcptr mfunc; } ElunaRegister;

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
                    if(GetMethodTable<T>() == NULL) 
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
                    if(ptrHold != NULL)
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
                    if(ptrHold == NULL)
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
                    if(obj == NULL) return 0;
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
};

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

		void OnChat(uint32 eventId, Player * player, uint32 type, uint32 lang, string& msg)
		{
			for (vector<uint16>::iterator itr = Eluna::get()->m_playerEventBindings.at(PLAYER_EVENT_ON_CHAT).begin(); 
				itr != Eluna::get()->m_playerEventBindings.at(PLAYER_EVENT_ON_CHAT).end(); itr++)
			{
				Eluna::get()->BeginCall((*itr));
				Eluna::get()->PushInteger(Eluna::get()->m_luaState, eventId);
				Eluna::get()->PushPlayer(Eluna::get()->m_luaState, player);
				Eluna::get()->PushInteger(Eluna::get()->m_luaState, type);
				Eluna::get()->PushInteger(Eluna::get()->m_luaState, lang);
				Eluna::get()->PushString(Eluna::get()->m_luaState, msg.c_str());
				Eluna::get()->ExecuteCall(5, 0);
			}
		}

		void OnChat(uint32 eventId, Player * player, uint32 type, uint32 lang, string& msg, Player * receiver)
		{
			for (vector<uint16>::iterator itr = Eluna::get()->m_playerEventBindings.at(PLAYER_EVENT_ON_CHAT).begin(); 
				itr != Eluna::get()->m_playerEventBindings.at(PLAYER_EVENT_ON_CHAT).end(); itr++)
			{
				Eluna::get()->BeginCall((*itr));
				Eluna::get()->PushInteger(Eluna::get()->m_luaState, eventId);
				Eluna::get()->PushPlayer(Eluna::get()->m_luaState, player);
				Eluna::get()->PushInteger(Eluna::get()->m_luaState, type);
				Eluna::get()->PushInteger(Eluna::get()->m_luaState, lang);
				Eluna::get()->PushString(Eluna::get()->m_luaState, msg.c_str());
				Eluna::get()->PushPlayer(Eluna::get()->m_luaState, receiver);
				Eluna::get()->ExecuteCall(6, 0);
			}
		}

		void OnPvPKill(uint32 eventId, Player * killer, Player * victim)
		{
			for (vector<uint16>::iterator itr = Eluna::get()->m_playerEventBindings.at(PLAYER_EVENT_ON_KILL_PLAYER).begin();
				itr != Eluna::get()->m_playerEventBindings.at(PLAYER_EVENT_ON_KILL_PLAYER).end(); itr++)
			{
				Eluna::get()->BeginCall((*itr));
				Eluna::get()->PushInteger(Eluna::get()->m_luaState, eventId);
				Eluna::get()->PushPlayer(Eluna::get()->m_luaState, killer);
				Eluna::get()->PushPlayer(Eluna::get()->m_luaState, victim);
				Eluna::get()->ExecuteCall(3, 0);
			}
		}

		void OnPlayerLevelChanged(uint32 eventId, Player * player, uint8 oldLevel)
		{
			for (vector<uint16>::iterator itr = Eluna::get()->m_playerEventBindings.at(PLAYER_EVENT_LEVEL_CHANGE).begin();
				itr != Eluna::get()->m_playerEventBindings.at(PLAYER_EVENT_LEVEL_CHANGE).end(); itr++)
			{
				Eluna::get()->BeginCall((*itr));
				Eluna::get()->PushInteger(Eluna::get()->m_luaState, eventId);
				Eluna::get()->PushPlayer(Eluna::get()->m_luaState, player);
				Eluna::get()->PushInteger(Eluna::get()->m_luaState, oldLevel);
				Eluna::get()->ExecuteCall(3, 0);
			}
		}

		void OnPlayerTalentsChanged(uint32 eventId, Player * player, uint32 points)
		{
			for (vector<uint16>::iterator itr = Eluna::get()->m_playerEventBindings.at(PLAYER_EVENT_ON_TALENTS_CHANGE).begin();
				itr != Eluna::get()->m_playerEventBindings.at(PLAYER_EVENT_ON_TALENTS_CHANGE).end(); itr++)
			{
				Eluna::get()->BeginCall((*itr));
				Eluna::get()->PushInteger(Eluna::get()->m_luaState, eventId);
				Eluna::get()->PushPlayer(Eluna::get()->m_luaState, player);
				Eluna::get()->PushInteger(Eluna::get()->m_luaState, points);
				Eluna::get()->ExecuteCall(3, 0);
			}
		}
};
#endif