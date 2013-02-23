#ifndef __GLOBAL_METHODS_ELUNA
#define __GLOBAL_METHODS_ELUNA

#include "SystemConfig.h"
#include "World.h"
#include "MapManager.h"
#include "GuildMgr.h"

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

    static int ReloadEluna(lua_State* L)
    {
        Eluna::get()->Restart();
        return 0;
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

    static int GetPlayersInMap(lua_State* L)
    {
        uint32 mapID = luaL_checkunsigned(L, 1);
        uint32 instanceID = luaL_optunsigned(L, 2, 0);
        int team = luaL_optint(L, 3, 0);

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        Map* map = sMapMgr->FindMap(mapID, instanceID);
        if(!map)
        {
            lua_settop(L, tbl);
            return 1;
        }

        Map::PlayerList const& players = map->GetPlayers();
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            Player* player = itr->getSource();
            if(!player)
                continue;
            if (player->GetSession() && (!team || player->GetTeam() == (team == 1 ? ALLIANCE : HORDE)))
            {
                ++i;
                Eluna::get()->PushUnsigned(L, i);
                Eluna::get()->PushUnit(L, player);
                lua_settable(L, tbl);
            }
        }

        lua_settop(L, tbl);
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

    static int GetGuildByName(lua_State* L)
    {
        const char* name = luaL_checkstring(L, 1);
        Eluna::get()->PushGuild(L, sGuildMgr->GetGuildByName(name));
        return 1;
    }

    static int GetGuildByLeaderGUID(lua_State* L)
    {
        uint32 guidLow = luaL_checkunsigned(L, 1);
        Eluna::get()->PushGuild(L, sGuildMgr->GetGuildByLeader(MAKE_NEW_GUID(guidLow, 0, HIGHGUID_PLAYER)));
        return 1;
    }

    static int GetPlayerCount(lua_State* L)
    {
        Eluna::get()->PushUnsigned(L, sWorld->GetPlayerCount());
        return 1;
    }

    static int CreateLuaEvent(lua_State* L)
    {
        const char* typeName = luaL_typename(L, 1);
        uint32 delay = luaL_checkunsigned(L, 2);
        uint32 repeats = luaL_checkunsigned(L, 3);
        if(!typeName)
            return 0;
        if(!strcmp(luaL_typename(L, 1), "function") || delay > 0)
        {
            int functionRef = lua_ref(L, true);
            Eluna::get()->_luaEventMgr->CreateLuaEvent(functionRef, delay, repeats);
            Eluna::get()->PushInteger(L, functionRef);
        }
        else
            return 0;
        return 1;
    }
}
#endif