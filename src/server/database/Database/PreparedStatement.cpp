/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "PreparedStatement.h"
#include "Errors.h"
#include "MySQLConnection.h"
#include "MySQLPreparedStatement.h"
#include "QueryResult.h"
#include "Log.h"
#include "MySQLWorkaround.h"

PreparedStatementBase::PreparedStatementBase(uint32 index, uint8 capacity) :
    m_stmt(nullptr), m_index(index), statement_data(capacity) { }

PreparedStatementBase::~PreparedStatementBase() { }

void PreparedStatementBase::BindParameters(MySQLPreparedStatement* stmt)
{
    ASSERT(stmt);
    m_stmt = stmt;

    uint8 i = 0;
    for (; i < statement_data.size(); i++)
    {
        switch (statement_data[i].type)
        {
            case TYPE_BOOL:
                stmt->setBool(i, statement_data[i].data.boolean);
                break;
            case TYPE_UI8:
                stmt->setUInt8(i, statement_data[i].data.ui8);
                break;
            case TYPE_UI16:
                stmt->setUInt16(i, statement_data[i].data.ui16);
                break;
            case TYPE_UI32:
                stmt->setUInt32(i, statement_data[i].data.ui32);
                break;
            case TYPE_I8:
                stmt->setInt8(i, statement_data[i].data.i8);
                break;
            case TYPE_I16:
                stmt->setInt16(i, statement_data[i].data.i16);
                break;
            case TYPE_I32:
                stmt->setInt32(i, statement_data[i].data.i32);
                break;
            case TYPE_UI64:
                stmt->setUInt64(i, statement_data[i].data.ui64);
                break;
            case TYPE_I64:
                stmt->setInt64(i, statement_data[i].data.i64);
                break;
            case TYPE_FLOAT:
                stmt->setFloat(i, statement_data[i].data.f);
                break;
            case TYPE_DOUBLE:
                stmt->setDouble(i, statement_data[i].data.d);
                break;
            case TYPE_STRING:
                stmt->setBinary(i, statement_data[i].binary, true);
                break;
            case TYPE_BINARY:
                stmt->setBinary(i, statement_data[i].binary, false);
                break;
            case TYPE_NULL:
                stmt->setNull(i);
                break;
        }
    }
    #ifdef _DEBUG
    if (i < stmt->m_paramCount)
        TC_LOG_WARN("sql.sql", "[WARNING]: BindParameters() for statement %u did not bind all allocated parameters", m_index);
    #endif
}

//- Bind to buffer
void PreparedStatementBase::setBool(const uint8 index, const bool value)
{
    ASSERT(index < statement_data.size());

    statement_data[index].data.boolean = value;
    statement_data[index].type = TYPE_BOOL;
}

void PreparedStatementBase::setUInt8(const uint8 index, const uint8 value)
{
    ASSERT(index < statement_data.size());

    statement_data[index].data.ui8 = value;
    statement_data[index].type = TYPE_UI8;
}

void PreparedStatementBase::setUInt16(const uint8 index, const uint16 value)
{
    ASSERT(index < statement_data.size());

    statement_data[index].data.ui16 = value;
    statement_data[index].type = TYPE_UI16;
}

void PreparedStatementBase::setUInt32(const uint8 index, const uint32 value)
{
    ASSERT(index < statement_data.size());

    statement_data[index].data.ui32 = value;
    statement_data[index].type = TYPE_UI32;
}

void PreparedStatementBase::setUInt64(const uint8 index, const uint64 value)
{
    ASSERT(index < statement_data.size());

    statement_data[index].data.ui64 = value;
    statement_data[index].type = TYPE_UI64;
}

void PreparedStatementBase::setInt8(const uint8 index, const int8 value)
{
    ASSERT(index < statement_data.size());

    statement_data[index].data.i8 = value;
    statement_data[index].type = TYPE_I8;
}

void PreparedStatementBase::setInt16(const uint8 index, const int16 value)
{
    ASSERT(index < statement_data.size());

    statement_data[index].data.i16 = value;
    statement_data[index].type = TYPE_I16;
}

void PreparedStatementBase::setInt32(const uint8 index, const int32 value)
{
    ASSERT(index < statement_data.size());

    statement_data[index].data.i32 = value;
    statement_data[index].type = TYPE_I32;
}

void PreparedStatementBase::setInt64(const uint8 index, const int64 value)
{
    ASSERT(index < statement_data.size());

    statement_data[index].data.i64 = value;
    statement_data[index].type = TYPE_I64;
}

void PreparedStatementBase::setFloat(const uint8 index, const float value)
{
    ASSERT(index < statement_data.size());

    statement_data[index].data.f = value;
    statement_data[index].type = TYPE_FLOAT;
}

void PreparedStatementBase::setDouble(const uint8 index, const double value)
{
    ASSERT(index < statement_data.size());

    statement_data[index].data.d = value;
    statement_data[index].type = TYPE_DOUBLE;
}

void PreparedStatementBase::setString(const uint8 index, const std::string& value)
{
    ASSERT(index < statement_data.size());

    statement_data[index].binary.resize(value.length() + 1);
    memcpy(statement_data[index].binary.data(), value.c_str(), value.length() + 1);
    statement_data[index].type = TYPE_STRING;
}

void PreparedStatementBase::setBinary(const uint8 index, const std::vector<uint8>& value)
{
    ASSERT(index < statement_data.size());

    statement_data[index].binary = value;
    statement_data[index].type = TYPE_BINARY;
}

void PreparedStatementBase::setNull(const uint8 index)
{
    ASSERT(index < statement_data.size());

    statement_data[index].type = TYPE_NULL;
}

//- Execution
PreparedStatementTask::PreparedStatementTask(PreparedStatementBase* stmt, bool async) :
m_stmt(stmt), m_result(nullptr)
{
    m_has_result = async; // If it's async, then there's a result
    if (async)
        m_result = new PreparedQueryResultPromise();
}

PreparedStatementTask::~PreparedStatementTask()
{
    delete m_stmt;
    if (m_has_result && m_result != nullptr)
        delete m_result;
}

bool PreparedStatementTask::Execute()
{
    if (m_has_result)
    {
        PreparedResultSet* result = m_conn->Query(m_stmt);
        if (!result || !result->GetRowCount())
        {
            delete result;
            m_result->set_value(PreparedQueryResult(nullptr));
            return false;
        }
        m_result->set_value(PreparedQueryResult(result));
        return true;
    }

    return m_conn->Execute(m_stmt);
}
