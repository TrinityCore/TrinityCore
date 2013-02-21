#include "ScriptPCH.h"
#include "Guild.h"
#include "GuildMgr.h"

#ifndef GUILDMETHODS_H
#define GUILDMETHODS_H

class LuaGuild
{
public:

	static int GetMembers(lua_State* L, Guild* pGuild)
	{
		if(!pGuild)
			return 0;

		lua_newtable(L);
		int tbl = lua_gettop(L);
		int i = 0;

		// Note that the following is very hacky, I don't like it and it SHOULD be changed ASAP.

        TRINITY_READ_GUARD(HashMapHolder<Player>::LockType, *HashMapHolder<Player>::GetLock());
        HashMapHolder<Player>::MapType const& m = sObjectAccessor->GetPlayers();
        for (HashMapHolder<Player>::MapType::const_iterator itr = m.begin(); itr != m.end(); ++itr)
        {
			if(itr->second->GetGuildId() == pGuild->GetId())
			{
				i++;
				lua_pushnumber(L, i);
                Eluna::get()->PushUnit(L, itr->second);
				lua_settable(L, tbl);
			}
		}

		lua_settop(L, tbl); // push table to top of stack
		return 1;
	}

	static int GetUnitType(lua_State* L, Guild* pGuild)
	{
		if(!pGuild)
			return 0;

		Eluna::get()->PushString(L, "Guild");
		return 1;
	}

    static int GetLeaderGUID(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;
        
        Eluna::get()->PushUnsigned(L, GUID_LOPART(pGuild->GetLeaderGUID()));
        return 1;
    }
};
#endif
