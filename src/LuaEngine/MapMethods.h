/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 * Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
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