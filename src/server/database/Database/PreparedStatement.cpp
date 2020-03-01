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

PreparedStatement::PreparedStatement(uint32 index, uint8 capacity) :
m_stmt(nullptr), m_index(index), statement_data(capacity) { }

PreparedStatement::~PreparedStatement() { }

void PreparedStatement::BindParameters(MySQLPreparedStatement* stmt)
{
    ASSERT(stmt);
    m_stmt = stmt;

    uint8 pos = 0;
    for (PreparedStatementData const& data : statement_data)
    {
        switch (data.type)
        {
            case TYPE_BOOL:
                stmt->setBool(pos, std::get<bool>(data.data));
                break;
            case TYPE_UI8:
                stmt->setUInt8(pos, std::get<uint8>(data.data));
                break;
            case TYPE_UI16:
                stmt->setUInt16(pos, std::get<uint16>(data.data));
                break;
            case TYPE_UI32:
                stmt->setUInt32(pos, std::get<uint32>(data.data));
                break;
            case TYPE_I8:
                stmt->setInt8(pos, std::get<int8>(data.data));
                break;
            case TYPE_I16:
                stmt->setInt16(pos, std::get<int16>(data.data));
                break;
            case TYPE_I32:
                stmt->setInt32(pos, std::get<int32>(data.data));
                break;
            case TYPE_UI64:
                stmt->setUInt64(pos, std::get<uint64>(data.data));
                break;
            case TYPE_I64:
                stmt->setInt64(pos, std::get<int64>(data.data));
                break;
            case TYPE_FLOAT:
                stmt->setFloat(pos, std::get<float>(data.data));
                break;
            case TYPE_DOUBLE:
                stmt->setDouble(pos, std::get<double>(data.data));
                break;
            case TYPE_STRING:
                stmt->setString(pos, std::get<std::string>(data.data));
                break;
            case TYPE_BINARY:
                stmt->setBinary(pos, std::get<std::vector<uint8>>(data.data));
                break;
            case TYPE_NULL:
                stmt->setNull(pos);
                break;
        }
        ++pos;
    }
    #ifdef _DEBUG
    if (pos < stmt->m_paramCount)
        TC_LOG_WARN("sql.sql", "[WARNING]: BindParameters() for statement %u did not bind all allocated parameters", m_index);
    #endif
}

//- Bind to buffer
void PreparedStatement::setBool(const uint8 index, const bool value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
    statement_data[index].type = TYPE_BOOL;
}

void PreparedStatement::setUInt8(const uint8 index, const uint8 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
    statement_data[index].type = TYPE_UI8;
}

void PreparedStatement::setUInt16(const uint8 index, const uint16 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
    statement_data[index].type = TYPE_UI16;
}

void PreparedStatement::setUInt32(const uint8 index, const uint32 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
    statement_data[index].type = TYPE_UI32;
}

void PreparedStatement::setUInt64(const uint8 index, const uint64 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
    statement_data[index].type = TYPE_UI64;
}

void PreparedStatement::setInt8(const uint8 index, const int8 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
    statement_data[index].type = TYPE_I8;
}

void PreparedStatement::setInt16(const uint8 index, const int16 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
    statement_data[index].type = TYPE_I16;
}

void PreparedStatement::setInt32(const uint8 index, const int32 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
    statement_data[index].type = TYPE_I32;
}

void PreparedStatement::setInt64(const uint8 index, const int64 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
    statement_data[index].type = TYPE_I64;
}

void PreparedStatement::setFloat(const uint8 index, const float value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
    statement_data[index].type = TYPE_FLOAT;
}

void PreparedStatement::setDouble(const uint8 index, const double value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
    statement_data[index].type = TYPE_DOUBLE;
}

void PreparedStatement::setString(const uint8 index, const std::string& value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
    statement_data[index].type = TYPE_STRING;
}

void PreparedStatement::setBinary(const uint8 index, const std::vector<uint8>& value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
    statement_data[index].type = TYPE_BINARY;
}

void PreparedStatement::setNull(const uint8 index)
{
    ASSERT(index < statement_data.size());
    statement_data[index].type = TYPE_NULL;
}

//- Execution
PreparedStatementTask::PreparedStatementTask(PreparedStatement* stmt, bool async) :
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
