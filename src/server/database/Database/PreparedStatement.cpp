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
m_index(index), statement_data(capacity) { }

PreparedStatement::~PreparedStatement() { }

//- Bind to buffer
void PreparedStatement::setBool(const uint8 index, const bool value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatement::setUInt8(const uint8 index, const uint8 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatement::setUInt16(const uint8 index, const uint16 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatement::setUInt32(const uint8 index, const uint32 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatement::setUInt64(const uint8 index, const uint64 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatement::setInt8(const uint8 index, const int8 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatement::setInt16(const uint8 index, const int16 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatement::setInt32(const uint8 index, const int32 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatement::setInt64(const uint8 index, const int64 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatement::setFloat(const uint8 index, const float value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatement::setDouble(const uint8 index, const double value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatement::setString(const uint8 index, const std::string& value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatement::setBinary(const uint8 index, const std::vector<uint8>& value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatement::setNull(const uint8 index)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = nullptr;
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

template<typename T>
std::string PreparedStatementData::ToString(T value)
{
    return fmt::format("{}", value);
}

std::string PreparedStatementData::ToString(bool value)
{
    return ToString<uint32>(value);
}

std::string PreparedStatementData::ToString(uint8 value)
{
    return ToString<uint32>(value);
}

template std::string PreparedStatementData::ToString<uint16>(uint16);
template std::string PreparedStatementData::ToString<uint32>(uint32);
template std::string PreparedStatementData::ToString<uint64>(uint64);

std::string PreparedStatementData::ToString(int8 value)
{
    return ToString<int32>(value);
}

template std::string PreparedStatementData::ToString<int16>(int16);
template std::string PreparedStatementData::ToString<int32>(int32);
template std::string PreparedStatementData::ToString<int64>(int64);
template std::string PreparedStatementData::ToString<float>(float);
template std::string PreparedStatementData::ToString<double>(double);

std::string PreparedStatementData::ToString(std::string const& value)
{
    return fmt::format("'{}'", value);
}

std::string PreparedStatementData::ToString(std::vector<uint8> const& /*value*/)
{
    return "BINARY";
}

std::string PreparedStatementData::ToString(std::nullptr_t)
{
    return "NULL";
}
