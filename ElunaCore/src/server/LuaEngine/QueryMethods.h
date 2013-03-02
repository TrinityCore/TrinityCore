#include "ScriptPCH.h"

#ifndef QUERYMETHODS_H
#define QUERYMETHODS_H

class LuaQuery
{
public:

    // QueryResult methods

    static int GetUnitType(lua_State* L, QueryResult* Result)
    {
        if (!Result)
            return 0;

        Eluna::get()->PushString(L, "QueryResult");
        return 1;
    }

    static int NextRow(lua_State* L, QueryResult* Result)
    {
        if (!Result)
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, Result->get()->NextRow());
        return 1;
    }

    static int GetColumnCount(lua_State* L, QueryResult* Result)
    {
        if (!Result)
            Eluna::get()->PushUnsigned(L, 0);
        else
            Eluna::get()->PushUnsigned(L, Result->get()->GetFieldCount());
        return 1;
    }

    static int GetRowCount(lua_State* L, QueryResult* Result)
    {
        if (!Result)
            Eluna::get()->PushUnsigned(L, 0);
        else
        {
            if (Result->get()->GetRowCount() > (uint32)-1)
                Eluna::get()->PushUnsigned(L, (uint32)-1);
            else
                Eluna::get()->PushUnsigned(L, Result->get()->GetRowCount());
        }
        return 1;
    }


    // Field methods

    static int IsNull(lua_State* L, QueryResult* Result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!Result || !*Result || col >= Result->get()->GetFieldCount())
            Eluna::get()->PushBoolean(L, true);
        else
            Eluna::get()->PushBoolean(L, Result->get()->Fetch()[col].IsNull());
        return 1;
    }

    static int GetBool(lua_State* L, QueryResult* Result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!Result || !*Result || col >= Result->get()->GetFieldCount())
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, Result->get()->Fetch()[col].GetBool());
        return 1;
    }

    static int GetUInt8(lua_State* L, QueryResult* Result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!Result || !*Result || col >= Result->get()->GetFieldCount())
            Eluna::get()->PushUnsigned(L, 0);
        else
            Eluna::get()->PushUnsigned(L, Result->get()->Fetch()[col].GetUInt8());
        return 1;
    }

    static int GetUInt16(lua_State* L, QueryResult* Result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!Result || !*Result || col >= Result->get()->GetFieldCount())
            Eluna::get()->PushUnsigned(L, 0);
        else
            Eluna::get()->PushUnsigned(L, Result->get()->Fetch()[col].GetUInt16());
        return 1;
    }

    static int GetUInt32(lua_State* L, QueryResult* Result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!Result || !*Result || col >= Result->get()->GetFieldCount())
            Eluna::get()->PushUnsigned(L, 0);
        else
            Eluna::get()->PushUnsigned(L, Result->get()->Fetch()[col].GetUInt32());
        return 1;
    }

    static int GetInt8(lua_State* L, QueryResult* Result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!Result || !*Result || col >= Result->get()->GetFieldCount())
            Eluna::get()->PushInteger(L, 0);
        else
            Eluna::get()->PushInteger(L, Result->get()->Fetch()[col].GetInt8());
        return 1;
    }

    static int GetInt16(lua_State* L, QueryResult* Result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!Result || !*Result || col >= Result->get()->GetFieldCount())
            Eluna::get()->PushInteger(L, 0);
        else
            Eluna::get()->PushInteger(L, Result->get()->Fetch()[col].GetInt16());
        return 1;
    }

    static int GetInt32(lua_State* L, QueryResult* Result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!Result || !*Result || col >= Result->get()->GetFieldCount())
            Eluna::get()->PushInteger(L, 0);
        else
            Eluna::get()->PushInteger(L, Result->get()->Fetch()[col].GetInt32());
        return 1;
    }

    static int GetFloat(lua_State* L, QueryResult* Result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!Result || !*Result || col >= Result->get()->GetFieldCount())
            Eluna::get()->PushFloat(L, 0.0f);
        else
            Eluna::get()->PushFloat(L, Result->get()->Fetch()[col].GetFloat());
        return 1;
    }

    static int GetDouble(lua_State* L, QueryResult* Result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!Result || !*Result || col >= Result->get()->GetFieldCount())
            Eluna::get()->PushDouble(L, 0.0);
        else
            Eluna::get()->PushDouble(L, Result->get()->Fetch()[col].GetDouble());
        return 1;
    }

    static int GetString(lua_State* L, QueryResult* Result)
    {
        uint32 col = luaL_checkunsigned(L, 1);
        if (!Result || !*Result || col >= Result->get()->GetFieldCount())
            Eluna::get()->PushString(L, "");
        else
            Eluna::get()->PushString(L, Result->get()->Fetch()[col].GetString().c_str());
        return 1;
    }
};
#endif
