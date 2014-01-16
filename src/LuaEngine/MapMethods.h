/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef MAPMETHODS_H
#define MAPMETHODS_H

namespace LuaMap
{
    // :GetName()
    int GetName(lua_State* L, Map* map)
    {
        sEluna->Push(L, map->GetMapName());
        return 1;
    }

    // GetHeight(x, y[, phase])
    int GetHeight(lua_State* L, Map* map)
    {
        float x = luaL_checknumber(L, 1);
        float y = luaL_checknumber(L, 2);
        uint32 phasemask = luaL_optunsigned(L, 3, 1);

        float z = map->GetHeight(phasemask, x, y, MAX_HEIGHT);
        if (z == INVALID_HEIGHT)
            return 0;
        sEluna->Push(L, z);
        return 1;
    }

    // :GetDifficulty()
    int GetDifficulty(lua_State* L, Map* map)
    {
        sEluna->Push(L, map->GetDifficulty());
        return 1;
    }

    // :GetInstanceId()
    int GetInstanceId(lua_State* L, Map* map)
    {
        sEluna->Push(L, map->GetInstanceId());
        return 1;
    }

    // :GetPlayerCount()
    int GetPlayerCount(lua_State* L, Map* map)
    {
        sEluna->Push(L, map->GetPlayersCountExceptGMs());
        return 1;
    }

    // :GetMapId()
    int GetMapId(lua_State* L, Map* map)
    {
        sEluna->Push(L, map->GetId());
        return 1;
    }

    // :GetAreaId(x, y, z)
    int GetAreaId(lua_State* L, Map* map)
    {
        float x = luaL_checknumber(L, 1);
        float y = luaL_checknumber(L, 2);
        float z = luaL_checknumber(L, 3);

        sEluna->Push(L, map->GetAreaId(x, y, z));
        return 1;
    }

    // :IsArena()
    int IsArena(lua_State* L, Map* map)
    {
        sEluna->Push(L, map->IsBattleArena());
        return 1;
    }

    // :IsBattleground()
    int IsBattleground(lua_State* L, Map* map)
    {
        sEluna->Push(L, map->IsBattleground());
        return 1;
    }

    // :IsDungeon()
    int IsDungeon(lua_State* L, Map* map)
    {
        sEluna->Push(L, map->IsDungeon());
        return 1;
    }

    // :IsEmpty()
    int IsEmpty(lua_State* L, Map* map)
    {
        sEluna->Push(L, map->isEmpty());
        return 1;
    }

    // :IsHeroic()
    int IsHeroic(lua_State* L, Map* map)
    {
        sEluna->Push(L, map->IsHeroic());
        return 1;
    }

    // :IsRaid()
    int IsRaid(lua_State* L, Map* map)
    {
        sEluna->Push(L, map->IsRaid());
        return 1;
    }
};
#endif