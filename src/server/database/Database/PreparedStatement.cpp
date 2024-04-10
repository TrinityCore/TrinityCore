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
#include <fmt/chrono.h>

PreparedStatementBase::PreparedStatementBase(uint32 index, uint8 capacity) :
m_index(index), statement_data(capacity) { }

PreparedStatementBase::~PreparedStatementBase() { }

//- Bind to buffer
void PreparedStatementBase::setBool(uint8 index, bool value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setUInt8(uint8 index, uint8 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setUInt16(uint8 index, uint16 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setUInt32(uint8 index, uint32 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setUInt64(uint8 index, uint64 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setInt8(uint8 index, int8 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setInt16(uint8 index, int16 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setInt32(uint8 index, int32 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setInt64(uint8 index, int64 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setFloat(uint8 index, float value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setDouble(uint8 index, double value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setDate(uint8 index, SystemTimePoint value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setString(uint8 index, std::string const& value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setStringView(uint8 index, std::string_view value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data.emplace<std::string>(value);
}

void PreparedStatementBase::setBinary(uint8 index, std::vector<uint8> const& value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setNull(uint8 index)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = nullptr;
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
    return Trinity::StringFormat("'{}'", value);
}

std::string PreparedStatementData::ToString(std::vector<uint8> const& /*value*/)
{
    return "BINARY";
}

std::string PreparedStatementData::ToString(SystemTimePoint value)
{
    return Trinity::StringFormat("{:%F %T}", value);
}

std::string PreparedStatementData::ToString(std::nullptr_t)
{
    return "NULL";
}
