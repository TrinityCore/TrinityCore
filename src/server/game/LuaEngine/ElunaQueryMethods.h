/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef QUERYMETHODS_H
#define QUERYMETHODS_H

#ifndef TRINITY
#define RESULT  result
#else
#define RESULT  (*result)
#endif

/***
 * The result of a database query.
 *
 * E.g. the return value of [Global:WorldDBQuery].
 *
 * Inherits all methods from: none
 */
namespace LuaQuery
{
    static void CheckFields(lua_State* L, ElunaQuery* result)
    {
        if (Eluna::CHECKVAL<uint32>(L, 2) >= RESULT->GetFieldCount())
            luaL_argerror(L, 2, "invalid field index");
    }

    /**
     * Returns `true` if the specified column of the current row is `NULL`, otherwise `false`.
     *
     * @param uint32 column
     * @return bool isNull
     */
    int IsNull(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);

#ifndef TRINITY
        Eluna::Push(L, RESULT->Fetch()[col].IsNULL());
#else
        Eluna::Push(L, RESULT->Fetch()[col].IsNull());
#endif
        return 1;
    }

    /**
     * Returns the number of columns in the result set.
     *
     * @return uint32 columnCount
     */
    int GetColumnCount(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        Eluna::Push(L, RESULT->GetFieldCount());
        return 1;
    }

    /**
     * Returns the number of rows in the result set.
     *
     * @return uint32 rowCount
     */
    int GetRowCount(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        if (RESULT->GetRowCount() > (uint32)-1)
            Eluna::Push(L, (uint32)-1);
        else
            Eluna::Push(L, (uint32)(RESULT->GetRowCount()));
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a boolean.
     *
     * @param uint32 column
     * @return bool data
     */
    int GetBool(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].GetBool());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to an unsigned 8-bit integer.
     *
     * @param uint32 column
     * @return uint8 data
     */
    int GetUInt8(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].GetUInt8());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to an unsigned 16-bit integer.
     *
     * @param uint32 column
     * @return uint16 data
     */
    int GetUInt16(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].GetUInt16());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to an unsigned 32-bit integer.
     *
     * @param uint32 column
     * @return uint32 data
     */
    int GetUInt32(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].GetUInt32());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to an unsigned 64-bit integer.
     *
     * @param uint32 column
     * @return uint64 data
     */
    int GetUInt64(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].GetUInt64());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a signed 8-bit integer.
     *
     * @param uint32 column
     * @return int8 data
     */
    int GetInt8(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].GetInt8());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a signed 16-bit integer.
     *
     * @param uint32 column
     * @return int16 data
     */
    int GetInt16(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].GetInt16());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a signed 32-bit integer.
     *
     * @param uint32 column
     * @return int32 data
     */
    int GetInt32(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].GetInt32());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a signed 64-bit integer.
     *
     * @param uint32 column
     * @return int64 data
     */
    int GetInt64(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].GetInt64());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a 32-bit floating point value.
     *
     * @param uint32 column
     * @return float data
     */
    int GetFloat(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].GetFloat());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a 64-bit floating point value.
     *
     * @param uint32 column
     * @return double data
     */
    int GetDouble(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].GetDouble());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a string.
     *
     * @param uint32 column
     * @return string data
     */
    int GetString(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);

#ifndef TRINITY
        Eluna::Push(L, RESULT->Fetch()[col].GetString());
#else
        Eluna::Push(L, RESULT->Fetch()[col].GetCString());
#endif
        return 1;
    }

    /**
     * Advances the [ElunaQuery] to the next row in the result set.
     *
     * *Do not* call this immediately after a query, or you'll skip the first row.
     *
     * Returns `false` if there was no new row, otherwise `true`.
     *
     * @return bool hadNextRow
     */
    int NextRow(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        Eluna::Push(L, RESULT->NextRow());
        return 1;
    }

    /**
     * Returns a table from the current row where keys are field names and values are the row's values.
     *
     * All numerical values will be numbers and everything else is returned as a string.
     *
     * **For example,** the query:
     *
     *     SELECT entry, name FROM creature_template
     *
     * would result in a table like:
     *
     *     { entry = 123, name = "some creature name" }
     *
     * To move to next row use [ElunaQuery:NextRow].
     *
     * @return table rowData : table filled with row columns and data where `T[column] = data`
     */
    int GetRow(Eluna* /*E*/, lua_State* L, ElunaQuery* result)
    {
        lua_newtable(L);
        int tbl = lua_gettop(L);

        uint32 col = RESULT->GetFieldCount();
        Field* row = RESULT->Fetch();

#ifndef TRINITY
        const QueryFieldNames& names = RESULT->GetFieldNames();
#endif

        for (uint32 i = 0; i < col; ++i)
        {
#ifdef TRINITY
            Eluna::Push(L, RESULT->GetFieldName(i));

            const char* str = row[i].GetCString();
            if (row[i].IsNull() || !str)
                Eluna::Push(L);
#else
            Eluna::Push(L, names[i]);

            const char* str = row[i].GetString();
            if (row[i].IsNULL() || !str)
                Eluna::Push(L);
#endif
            else
            {
                // MYSQL_TYPE_LONGLONG Interpreted as string for lua
                switch (row[i].GetType())
                {
                    case MYSQL_TYPE_TINY:
                    case MYSQL_TYPE_SHORT:
                    case MYSQL_TYPE_INT24:
                    case MYSQL_TYPE_LONG:
                    case MYSQL_TYPE_FLOAT:
                    case MYSQL_TYPE_DOUBLE:
                        Eluna::Push(L, strtod(str, NULL));
                        break;
                    default:
                        Eluna::Push(L, str);
                        break;
                }
            }

            lua_settable(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }
};
#undef RESULT

#endif
