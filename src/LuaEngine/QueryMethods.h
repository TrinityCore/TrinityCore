/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef QUERYMETHODS_H
#define QUERYMETHODS_H

namespace LuaQuery
{
    static int NextRow(lua_State* L, QueryResult* result)
    {
        sEluna.Push(L, (*result)->NextRow());
        return 1;
    }

    static int GetColumnCount(lua_State* L, QueryResult* result)
    {
        sEluna.Push(L, (*result)->GetFieldCount());
        return 1;
    }

    static int GetRowCount(lua_State* L, QueryResult* result)
    {
        sEluna.Push(L, uint32((*result)->GetRowCount()));
        return 1;
    }

    static int IsNull(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (col >= (*result)->GetFieldCount())
            return 0;
        sEluna.Push(L, (*result)->Fetch()[col].IsNull());
        return 1;
    }

    static int GetBool(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (col >= (*result)->GetFieldCount())
            return 0;
        sEluna.Push(L, (*result)->Fetch()[col].GetBool());
        return 1;
    }

    static int GetUInt8(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (col >= (*result)->GetFieldCount())
            return 0;
        sEluna.Push(L, (*result)->Fetch()[col].GetUInt8());
        return 1;
    }

    static int GetUInt16(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (col >= (*result)->GetFieldCount())
            return 0;
        sEluna.Push(L, (*result)->Fetch()[col].GetUInt16());
        return 1;
    }

    static int GetUInt32(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (col >= (*result)->GetFieldCount())
            return 0;
        sEluna.Push(L, (*result)->Fetch()[col].GetUInt32());
        return 1;
    }

    static int GetUInt64(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (col >= (*result)->GetFieldCount())
            return 0;
        sEluna.Push(L, (*result)->Fetch()[col].GetUInt64());
        return 1;
    }

    static int GetInt8(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (col >= (*result)->GetFieldCount())
            return 0;
        sEluna.Push(L, (*result)->Fetch()[col].GetInt8());
        return 1;
    }

    static int GetInt16(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (col >= (*result)->GetFieldCount())
            return 0;
        sEluna.Push(L, (*result)->Fetch()[col].GetInt16());
        return 1;
    }

    static int GetInt32(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (col >= (*result)->GetFieldCount())
            return 0;
        sEluna.Push(L, (*result)->Fetch()[col].GetInt32());
        return 1;
    }

    static int GetInt64(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (col >= (*result)->GetFieldCount())
            return 0;
        sEluna.Push(L, (*result)->Fetch()[col].GetInt64());
        return 1;
    }

    static int GetFloat(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (col >= (*result)->GetFieldCount())
            return 0;
        sEluna.Push(L, (*result)->Fetch()[col].GetFloat());
        return 1;
    }

    static int GetDouble(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (col >= (*result)->GetFieldCount())
            return 0;
        sEluna.Push(L, (*result)->Fetch()[col].GetDouble());
        return 1;
    }

    static int GetString(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (col >= (*result)->GetFieldCount())
            return 0;
        sEluna.Push(L, (*result)->Fetch()[col].GetString());
        return 1;
    }
};
#endif
