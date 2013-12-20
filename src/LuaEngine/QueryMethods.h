/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef QUERYMETHODS_H
#define QUERYMETHODS_H

namespace LuaQuery
{
    static int NextRow(lua_State* L, QueryResult* result)
    {
        if (!result)
            sEluna->Push(L, false);
        else
            sEluna->Push(L, result->get()->NextRow());
        return 1;
    }

    static int GetColumnCount(lua_State* L, QueryResult* result)
    {
        if (!result)
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, result->get()->GetFieldCount());
        return 1;
    }

    static int GetRowCount(lua_State* L, QueryResult* result)
    {
        if (!result)
            sEluna->Push(L, 0);
        else
        {
            if (result->get()->GetRowCount() > (uint32)-1)
                sEluna->Push(L, (uint32)-1);
            else
                sEluna->Push(L, result->get()->GetRowCount());
        }
        return 1;
    }
    
    static int IsNull(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->Push(L, true);
        else
            sEluna->Push(L, result->get()->Fetch()[col].IsNull());
        return 1;
    }

    static int GetBool(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->Push(L, false);
        else
            sEluna->Push(L, result->get()->Fetch()[col].GetBool());
        return 1;
    }

    static int GetUInt8(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, result->get()->Fetch()[col].GetUInt8());
        return 1;
    }

    static int GetUInt16(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, result->get()->Fetch()[col].GetUInt16());
        return 1;
    }

    static int GetUInt32(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, result->get()->Fetch()[col].GetUInt32());
        return 1;
    }

    static int GetUInt64(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, result->get()->Fetch()[col].GetUInt64());
        return 1;
    }

    static int GetInt8(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, result->get()->Fetch()[col].GetInt8());
        return 1;
    }

    static int GetInt16(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, result->get()->Fetch()[col].GetInt16());
        return 1;
    }

    static int GetInt32(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, result->get()->Fetch()[col].GetInt32());
        return 1;
    }

    static int GetInt64(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, result->get()->Fetch()[col].GetInt64());
        return 1;
    }

    static int GetFloat(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->Push(L, 0.0f);
        else
            sEluna->Push(L, result->get()->Fetch()[col].GetFloat());
        return 1;
    }

    static int GetDouble(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->Push(L, 0.0);
        else
            sEluna->Push(L, result->get()->Fetch()[col].GetDouble());
        return 1;
    }

    static int GetString(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->Push(L, "");
        else
            sEluna->Push(L, result->get()->Fetch()[col].GetString());
        return 1;
    }
};
#endif
