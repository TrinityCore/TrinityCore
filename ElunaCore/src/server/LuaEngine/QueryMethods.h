#include "ScriptPCH.h"

#ifndef QUERYMETHODS_H
#define QUERYMETHODS_H

class LuaQuery
{
public:

    // QueryResult methods

    static int GetUnitType(lua_State* L, QueryResult* result)
    {
        if(!result)
            return 0;

        Eluna::get()->PushString(L, "QueryResult");
        return 1;
    }

	/*
	static int GetColumn(lua_State* L, QueryResult* result)
	{
        if (!result)
            return 0;

        uint32 index = luaL_checkunsigned(L, 1);
		uint32 fields = result->get()->GetFieldCount();

        if (index >= fields)
		{
            luaL_error(L, "Bad argument #1 for GetColumn - index (%u) bigger then max column count (%u)", index, result->get()->GetFieldCount());
            return 0;
        }
		else
		{
			Field* field =  &result->get()->Fetch()[index];
			if (field == NULL)
				lua_pushnil(L);
			else
				Eluna::get()->PushQueryField(L, field);
		}
		return 1;
	}*/

	static int NextRow(lua_State* L, QueryResult* result)
	{
        if (!result)
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, result->get()->NextRow());
		return 1;
	}

	static int GetColumnCount(lua_State* L, QueryResult* result)
	{
        if (!result)
            Eluna::get()->PushUnsigned(L, 0);
        else
            Eluna::get()->PushUnsigned(L, result->get()->GetFieldCount());
		return 1;
	}

	static int GetRowCount(lua_State* L, QueryResult* result)
	{
        if (!result)
            Eluna::get()->PushUnsigned(L, 0);
        else
        {
            if(result->get()->GetRowCount() > (uint32)-1)
                Eluna::get()->PushUnsigned(L, (uint32)-1);
            else
                Eluna::get()->PushUnsigned(L, result->get()->GetRowCount());
        }
		return 1;
	}


    // Field methods

	static int IsNull(lua_State* L, QueryResult* result)
	{
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            Eluna::get()->PushBoolean(L, true);
        else
            Eluna::get()->PushBoolean(L, result->get()->Fetch()[col].IsNull());
        return 1;
	}

	static int GetBool(lua_State* L, QueryResult* result)
	{
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, result->get()->Fetch()[col].GetBool());
        return 1;
	}

	static int GetUInt8(lua_State* L, QueryResult* result)
	{
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            Eluna::get()->PushUnsigned(L, 0);
        else
            Eluna::get()->PushUnsigned(L, result->get()->Fetch()[col].GetUInt8());
        return 1;
	}

	static int GetUInt16(lua_State* L, QueryResult* result)
	{
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            Eluna::get()->PushUnsigned(L, 0);
        else
            Eluna::get()->PushUnsigned(L, result->get()->Fetch()[col].GetUInt16());
        return 1;
	}

	static int GetUInt32(lua_State* L, QueryResult* result)
	{
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            Eluna::get()->PushUnsigned(L, 0);
        else
            Eluna::get()->PushUnsigned(L, result->get()->Fetch()[col].GetUInt32());
        return 1;
	}

	static int GetInt8(lua_State* L, QueryResult* result)
	{
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            Eluna::get()->PushInteger(L, 0);
        else
            Eluna::get()->PushInteger(L, result->get()->Fetch()[col].GetInt8());
        return 1;
	}

	static int GetInt16(lua_State* L, QueryResult* result)
	{
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            Eluna::get()->PushInteger(L, 0);
        else
            Eluna::get()->PushInteger(L, result->get()->Fetch()[col].GetInt16());
        return 1;
	}

	static int GetInt32(lua_State* L, QueryResult* result)
	{
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            Eluna::get()->PushInteger(L, 0);
        else
            Eluna::get()->PushInteger(L, result->get()->Fetch()[col].GetInt32());
        return 1;
	}

	static int GetFloat(lua_State* L, QueryResult* result)
	{
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            Eluna::get()->PushFloat(L, 0.0f);
        else
            Eluna::get()->PushFloat(L, result->get()->Fetch()[col].GetFloat());
        return 1;
	}

	static int GetDouble(lua_State* L, QueryResult* result)
	{
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            Eluna::get()->PushDouble(L, 0.0);
        else
            Eluna::get()->PushDouble(L, result->get()->Fetch()[col].GetDouble());
        return 1;
	}

	static int GetCString(lua_State* L, QueryResult* result)
	{
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            Eluna::get()->PushString(L, "");
        else
            Eluna::get()->PushString(L, result->get()->Fetch()[col].GetCString());
        return 1;
	}

	static int GetString(lua_State* L, QueryResult* result)
	{
        uint32 col = luaL_checkunsigned(L, 1);
        if (!result || !*result || col >= result->get()->GetFieldCount())
            Eluna::get()->PushString(L, "");
        else
            Eluna::get()->PushString(L, result->get()->Fetch()[col].GetString().c_str());
        return 1;
	}
};
#endif
