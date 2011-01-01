/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _PREPAREDSTATEMENT_H
#define _PREPAREDSTATEMENT_H

#include "SQLOperation.h"
#include <ace/Future.h>

//- Union for data buffer (upper-level bind -> queue -> lower-level bind)
union PreparedStatementDataUnion
{
    bool boolean;
    uint8 ui8;
    int8 i8;
    uint16 ui16;
    int16 i16;
    uint32 ui32;
    int32 i32;
    uint64 ui64;
    int64 i64;
    float f;
    double d;
};

//- This enum helps us differ data held in above union
enum PreparedStatementValueType
{
    TYPE_BOOL,
    TYPE_UI8,
    TYPE_UI16,
    TYPE_UI32,
    TYPE_UI64,
    TYPE_I8,
    TYPE_I16,
    TYPE_I32,
    TYPE_I64,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_STRING
};

struct PreparedStatementData
{
    PreparedStatementDataUnion data;
    PreparedStatementValueType type;
    std::string str;
};

//- Forward declare
class MySQLPreparedStatement;

//- Upper-level class that is used in code
class PreparedStatement
{
    friend class PreparedStatementTask;
    friend class MySQLPreparedStatement;
    friend class MySQLConnection;

    public:
        explicit PreparedStatement(uint32 index);
        ~PreparedStatement();

        void setBool(const uint8 index,const bool value);
        void setUInt8(const uint8 index, const uint8 value);
        void setUInt16(const uint8 index, const uint16 value);
        void setUInt32(const uint8 index, const uint32 value);
        void setUInt64(const uint8 index, const uint64 value);
        void setInt8(const uint8 index, const int8 value);
        void setInt16(const uint8 index, const int16 value);
        void setInt32(const uint8 index, const int32 value);
        void setInt64(const uint8 index, const int64 value);
        void setFloat(const uint8 index, const float value);
        void setDouble(const uint8 index, const double value);
        void setString(const uint8 index, const std::string& value);

    protected:
        void BindParameters();

    protected:
        MySQLPreparedStatement* m_stmt;
        uint32 m_index;
        std::vector<PreparedStatementData> statement_data;    //- Buffer of parameters, not tied to MySQL in any way yet
};

//- Class of which the instances are unique per MySQLConnection
//- access to these class objects is only done when a prepared statement task
//- is executed.
class MySQLPreparedStatement
{
    friend class MySQLConnection;
    friend class PreparedStatement;

    public:
        MySQLPreparedStatement(MYSQL_STMT* stmt);
        ~MySQLPreparedStatement();

        void setBool(const uint8 index,const bool value);
        void setUInt8(const uint8 index, const uint8 value);
        void setUInt16(const uint8 index, const uint16 value);
        void setUInt32(const uint8 index, const uint32 value);
        void setUInt64(const uint8 index, const uint64 value);
        void setInt8(const uint8 index, const int8 value);
        void setInt16(const uint8 index, const int16 value);
        void setInt32(const uint8 index, const int32 value);
        void setInt64(const uint8 index, const int64 value);
        void setFloat(const uint8 index, const float value);
        void setDouble(const uint8 index, const double value);
        void setString(const uint8 index, const char* value);

    protected:
        MYSQL_STMT* GetSTMT() { return m_Mstmt; }
        MYSQL_BIND* GetBind() { return m_bind; }
        PreparedStatement* m_stmt;
        void ClearParameters();
        bool CheckValidIndex(uint8 index);

    private:
        void setValue(MYSQL_BIND* param, enum_field_types type, const void* value, uint32 len, bool isUnsigned);

    private:
        MYSQL_STMT* m_Mstmt;
        uint32 m_paramCount;
        std::vector<bool> m_paramsSet;
        MYSQL_BIND* m_bind;
};

typedef ACE_Future<PreparedQueryResult> PreparedQueryResultFuture;

//- Lower-level class, enqueuable operation
class PreparedStatementTask : public SQLOperation
{
    public:
        PreparedStatementTask(PreparedStatement* stmt);
        PreparedStatementTask(PreparedStatement* stmt, PreparedQueryResultFuture result);
        ~PreparedStatementTask();

        bool Execute();

    protected:
        PreparedStatement* m_stmt;
        bool m_has_result;
        PreparedQueryResultFuture m_result;
};
#endif