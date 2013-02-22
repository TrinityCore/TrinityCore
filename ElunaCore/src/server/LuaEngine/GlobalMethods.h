#ifndef __GLOBAL_METHODS_ELUNA
#define __GLOBAL_METHODS_ELUNA

#include "SystemConfig.h"
#include "World.h"

extern "C" 
{
		#include "lua.h"
        #include "lualib.h"
        #include "lauxlib.h"
};

namespace LuaGlobalFunctions
{
	static int GetLuaEngine(lua_State* L)
	{
		lua_pushstring(L, "Eluna Nova 0.1");
		return 1;
	}

	static int GetCoreVersion(lua_State* L)
	{
		lua_pushstring(L, _FULLVERSION);
		return 1;
	}
    
    static int GetPlayerByGUID(lua_State* L)
    {
        uint32 guidLow = luaL_checkunsigned(L, 1);
        Eluna::get()->PushUnit(L, sObjectAccessor->FindPlayer(MAKE_NEW_GUID(guidLow, 0, HIGHGUID_PLAYER)));
        return 1;
    }

    static int GetPlayerByName(lua_State* L)
    {
        const char* message = luaL_checkstring(L, 1);
        Eluna::get()->PushUnit(L, sObjectAccessor->FindPlayerByName(message));
        return 1;
    }

    static int GetGameTime(lua_State* L)
    {
        Eluna::get()->PushUnsigned(L, sWorld->GetGameTime());
        return 1;
    }

    static int SendWorldMessage(lua_State* L)
    {
        const char* message = luaL_checkstring(L, 1);
        sWorld->SendServerMessage(SERVER_MSG_STRING, message);
        return 0;
    }

    static int GetPlayersInWorld(lua_State* L)
    {
        int team = luaL_optint(L, 1, 0);
        bool onlyGM = luaL_optint(L, 2, false);

		lua_newtable(L);
		int tbl = lua_gettop(L);
		uint32 i = 0;
        
        SessionMap const& sessions = sWorld->GetAllSessions();
        for (SessionMap::const_iterator it = sessions.begin(); it != sessions.end(); ++it)
        {
            if (Player* player = it->second->GetPlayer())
            {
                if (player->GetSession() && ((!team || player->GetTeam() == (team == 1 ? ALLIANCE : HORDE)) && (!onlyGM || player->isGameMaster())))
                {
                    ++i;
                    Eluna::get()->PushUnsigned(L, i);
                    Eluna::get()->PushUnit(L, player);
				    lua_settable(L, tbl);
                }
            }
        }

		lua_settop(L, tbl); // push table to top of stack
        return 1;
    }

	static int WorldDBQuery(lua_State* L)
	{
		const char* query = luaL_checkstring(L, 1);
		if(!query)
            return 0;
		QueryResult result = WorldDatabase.Query(query);
        if(!result)
            return 0;
		lua_settop(L, 0);
        // Cant figure out how to pass the result and succesfully get things from it later (atm just fixed it so it compiles, but doesnt work)
		Eluna::get()->PushQueryResult(L, &result);
		return 1;
	}
}
#endif