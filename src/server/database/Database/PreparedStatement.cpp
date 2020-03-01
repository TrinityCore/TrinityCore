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
        std::visit([&](auto&& data) {
            using T = std::decay_t<decltype(data)>;
            if constexpr (std::is_same_v<T, bool>)
                stmt->setBool(pos, data);
            else if constexpr (std::is_same_v<T, uint8>)
                stmt->setUInt8(pos, data);
            else if constexpr (std::is_same_v<T, uint16>)
                stmt->setUInt16(pos, data);
            else if constexpr (std::is_same_v<T, uint32>)
                stmt->setUInt32(pos, data);
            else if constexpr (std::is_same_v<T, uint64>)
                stmt->setUInt64(pos, data);
            else if constexpr (std::is_same_v<T, int8>)
                stmt->setInt8(pos, data);
            else if constexpr (std::is_same_v<T, int16>)
                stmt->setInt16(pos, data);
            else if constexpr (std::is_same_v<T, int32>)
                stmt->setInt32(pos, data);
            else if constexpr (std::is_same_v<T, int64>)
                stmt->setInt64(pos, data);
            else if constexpr (std::is_same_v<T, float>)
                stmt->setFloat(pos, data);
            else if constexpr (std::is_same_v<T, double>)
                stmt->setDouble(pos, data);
            else if constexpr (std::is_same_v<T, std::string>)
                stmt->setString(pos, data);
            else if constexpr (std::is_same_v<T, std::vector<uint8>>)
                stmt->setBinary(pos, data);
            else if constexpr (std::is_same_v<T, decltype(nullptr)>)
                stmt->setNull(pos);

        }, data);

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
    statement_data[index] = value;
}

void PreparedStatement::setUInt8(const uint8 index, const uint8 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index] = value;
}

void PreparedStatement::setUInt16(const uint8 index, const uint16 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index] = value;
}

void PreparedStatement::setUInt32(const uint8 index, const uint32 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index] = value;
}

void PreparedStatement::setUInt64(const uint8 index, const uint64 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index] = value;
}

void PreparedStatement::setInt8(const uint8 index, const int8 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index] = value;
}

void PreparedStatement::setInt16(const uint8 index, const int16 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index] = value;
}

void PreparedStatement::setInt32(const uint8 index, const int32 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index] = value;
}

void PreparedStatement::setInt64(const uint8 index, const int64 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index] = value;
}

void PreparedStatement::setFloat(const uint8 index, const float value)
{
    ASSERT(index < statement_data.size());
    statement_data[index] = value;
}

void PreparedStatement::setDouble(const uint8 index, const double value)
{
    ASSERT(index < statement_data.size());
    statement_data[index] = value;
}

void PreparedStatement::setString(const uint8 index, const std::string& value)
{
    ASSERT(index < statement_data.size());
    statement_data[index] = value;
}

void PreparedStatement::setBinary(const uint8 index, const std::vector<uint8>& value)
{
    ASSERT(index < statement_data.size());
    statement_data[index] = value;
}

void PreparedStatement::setNull(const uint8 index)
{
    ASSERT(index < statement_data.size());
    statement_data[index] = nullptr;
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
