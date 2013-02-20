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
	static int GetLuaEngine(lua_State * L)
	{
		lua_pushstring(L, "Eluna Nova 0.1");
		return 1;
	}

	static int GetCoreVersion(lua_State * L)
	{
		lua_pushstring(L, _FULLVERSION);
		return 1;
	}
}
#endif