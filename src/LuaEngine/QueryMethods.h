#ifndef QUERYMETHODS_H
#define QUERYMETHODS_H

class LuaQuery
{
public:

    // QueryResult methods

    static int GetUnitType(lua_State* L, QueryResult* result)
    {
        if (!result)
            return 0;

        sEluna->PushString(L, "QueryResult");
        return 1;
    }

    static int NextRow(lua_State* L, QueryResult* result)
    {
        if (!result)
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, result->get()->NextRow());
        return 1;
    }

    static int GetColumnCount(lua_State* L, QueryResult* result)
    {
        if (!result)
            sEluna->PushUnsigned(L, 0);
        else
            sEluna->PushUnsigned(L, result->get()->GetFieldCount());
        return 1;
    }

    static int GetRowCount(lua_State* L, QueryResult* result)
    {
        if (!result)
            sEluna->PushUnsigned(L, 0);
        else
        {
            if (result->get()->GetRowCount() > (uint32)-1)
                sEluna->PushUnsigned(L, (uint32)-1);
            else
                sEluna->PushUnsigned(L, result->get()->GetRowCount());
        }
        return 1;
    }


    // Field methods

    static int IsNull(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->PushBoolean(L, true);
        else
            sEluna->PushBoolean(L, result->get()->Fetch()[col].IsNull());
        return 1;
    }

    static int GetBool(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, result->get()->Fetch()[col].GetBool());
        return 1;
    }

    static int GetUInt8(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->PushUnsigned(L, 0);
        else
            sEluna->PushUnsigned(L, result->get()->Fetch()[col].GetUInt8());
        return 1;
    }

    static int GetUInt16(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->PushUnsigned(L, 0);
        else
            sEluna->PushUnsigned(L, result->get()->Fetch()[col].GetUInt16());
        return 1;
    }

    static int GetUInt32(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->PushUnsigned(L, 0);
        else
            sEluna->PushUnsigned(L, result->get()->Fetch()[col].GetUInt32());
        return 1;
    }

    static int GetUInt64(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->PushULong(L, 0);
        else
            sEluna->PushULong(L, result->get()->Fetch()[col].GetUInt64());
        return 1;
    }

    static int GetInt8(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->PushInteger(L, 0);
        else
            sEluna->PushInteger(L, result->get()->Fetch()[col].GetInt8());
        return 1;
    }

    static int GetInt16(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->PushInteger(L, 0);
        else
            sEluna->PushInteger(L, result->get()->Fetch()[col].GetInt16());
        return 1;
    }

    static int GetInt32(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->PushInteger(L, 0);
        else
            sEluna->PushInteger(L, result->get()->Fetch()[col].GetInt32());
        return 1;
    }

    static int GetInt64(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->PushLong(L, 0);
        else
            sEluna->PushLong(L, result->get()->Fetch()[col].GetInt64());
        return 1;
    }

    static int GetFloat(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->PushFloat(L, 0.0f);
        else
            sEluna->PushFloat(L, result->get()->Fetch()[col].GetFloat());
        return 1;
    }

    static int GetDouble(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->PushDouble(L, 0.0);
        else
            sEluna->PushDouble(L, result->get()->Fetch()[col].GetDouble());
        return 1;
    }

    static int GetString(lua_State* L, QueryResult* result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            sEluna->PushString(L, "");
        else
            sEluna->PushString(L, result->get()->Fetch()[col].GetString().c_str());
        return 1;
    }
};
#endif
