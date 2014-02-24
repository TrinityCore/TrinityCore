/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef QUERYMETHODS_H
#define QUERYMETHODS_H

#ifdef MANGOS
#define RESULT  result
#else
#define RESULT  (*result)
#endif
namespace LuaQuery
{
    /* BOOLEAN */
    int IsNull(lua_State* L, QueryResult* result)
    {
        uint32 col = sEluna->CHECKVAL<uint32>(L, 2);
        if (!result || col >= RESULT->GetFieldCount())
            sEluna->Push(L, true);
        else
#ifdef MANGOS
            sEluna->Push(L, RESULT->Fetch()[col].IsNULL());
#else
            sEluna->Push(L, RESULT->Fetch()[col].IsNull());
#endif
        return 1;
    }

    /* GETTERS */
    int GetColumnCount(lua_State* L, QueryResult* result)
    {
        if (!result)
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, RESULT->GetFieldCount());
        return 1;
    }

    int GetRowCount(lua_State* L, QueryResult* result)
    {
        if (!result)
            sEluna->Push(L, 0);
        else
        {
            if (RESULT->GetRowCount() > (uint32) - 1)
                sEluna->Push(L, (uint32) - 1);
            else
                sEluna->Push(L, RESULT->GetRowCount());
        }
        return 1;
    }

    int GetBool(lua_State* L, QueryResult* result)
    {
        uint32 col = sEluna->CHECKVAL<uint32>(L, 2);
        if (!result || col >= RESULT->GetFieldCount())
            sEluna->Push(L, false);
        else
            sEluna->Push(L, RESULT->Fetch()[col].GetBool());
        return 1;
    }

    int GetUInt8(lua_State* L, QueryResult* result)
    {
        uint32 col = sEluna->CHECKVAL<uint32>(L, 2);
        if (!result || col >= RESULT->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, RESULT->Fetch()[col].GetUInt8());
        return 1;
    }

    int GetUInt16(lua_State* L, QueryResult* result)
    {
        uint32 col = sEluna->CHECKVAL<uint32>(L, 2);
        if (!result || col >= RESULT->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, RESULT->Fetch()[col].GetUInt16());
        return 1;
    }

    int GetUInt32(lua_State* L, QueryResult* result)
    {
        uint32 col = sEluna->CHECKVAL<uint32>(L, 2);
        if (!result || col >= RESULT->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, RESULT->Fetch()[col].GetUInt32());
        return 1;
    }

    int GetUInt64(lua_State* L, QueryResult* result)
    {
        uint32 col = sEluna->CHECKVAL<uint32>(L, 2);
        if (!result || col >= RESULT->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, RESULT->Fetch()[col].GetUInt64());
        return 1;
    }

    int GetInt8(lua_State* L, QueryResult* result)
    {
        uint32 col = sEluna->CHECKVAL<uint32>(L, 2);
        if (!result || col >= RESULT->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, RESULT->Fetch()[col].GetInt8());
        return 1;
    }

    int GetInt16(lua_State* L, QueryResult* result)
    {
        uint32 col = sEluna->CHECKVAL<uint32>(L, 2);
        if (!result || col >= RESULT->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, RESULT->Fetch()[col].GetInt16());
        return 1;
    }

    int GetInt32(lua_State* L, QueryResult* result)
    {
        uint32 col = sEluna->CHECKVAL<uint32>(L, 2);
        if (!result || col >= RESULT->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, RESULT->Fetch()[col].GetInt32());
        return 1;
    }

    int GetInt64(lua_State* L, QueryResult* result)
    {
        uint32 col = sEluna->CHECKVAL<uint32>(L, 2);
        if (!result || col >= RESULT->GetFieldCount())
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, RESULT->Fetch()[col].GetInt64());
        return 1;
    }

    int GetFloat(lua_State* L, QueryResult* result)
    {
        uint32 col = sEluna->CHECKVAL<uint32>(L, 2);
        if (!result || col >= RESULT->GetFieldCount())
            sEluna->Push(L, 0.0f);
        else
            sEluna->Push(L, RESULT->Fetch()[col].GetFloat());
        return 1;
    }

    int GetDouble(lua_State* L, QueryResult* result)
    {
        uint32 col = sEluna->CHECKVAL<uint32>(L, 2);
        if (!result || col >= RESULT->GetFieldCount())
            sEluna->Push(L, 0.0);
        else
            sEluna->Push(L, RESULT->Fetch()[col].GetDouble());
        return 1;
    }

    int GetString(lua_State* L, QueryResult* result)
    {
        uint32 col = sEluna->CHECKVAL<uint32>(L, 2);
        if (!result || col >= RESULT->GetFieldCount())
            sEluna->Push(L, "");
        else
            sEluna->Push(L, RESULT->Fetch()[col].GetString());
        return 1;
    }

    /* OTHER */
    int NextRow(lua_State* L, QueryResult* result)
    {
        if (!result)
            sEluna->Push(L, false);
        else
            sEluna->Push(L, RESULT->NextRow());
        return 1;
    }
};
#undef RESULT

#endif
