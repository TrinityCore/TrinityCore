#ifndef __GLOBAL_METHODS_ELUNA
#define __GLOBAL_METHODS_ELUNA

#include "SystemConfig.h"

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
}
#endif