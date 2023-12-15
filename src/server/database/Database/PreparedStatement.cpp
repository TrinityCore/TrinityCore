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
#include "QueryResult.h"
#include "StringFormat.h"

PreparedStatementBase::PreparedStatementBase(uint32 index, uint8 capacity) :
    m_index(index), statement_data(capacity) { }

PreparedStatementBase::~PreparedStatementBase() { }

//- Bind to buffer
void PreparedStatementBase::setBool(const uint8 index, const bool value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setUInt8(const uint8 index, const uint8 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setUInt16(const uint8 index, const uint16 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setUInt32(const uint8 index, const uint32 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setUInt64(const uint8 index, const uint64 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setInt8(const uint8 index, const int8 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setInt16(const uint8 index, const int16 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setInt32(const uint8 index, const int32 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setInt64(const uint8 index, const int64 value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setFloat(const uint8 index, const float value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setDouble(const uint8 index, const double value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setString(const uint8 index, const std::string& value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setStringView(const uint8 index, const std::string_view value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data.emplace<std::string>(value);
}

void PreparedStatementBase::setBinary(const uint8 index, const std::vector<uint8>& value)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = value;
}

void PreparedStatementBase::setNull(const uint8 index)
{
    ASSERT(index < statement_data.size());
    statement_data[index].data = nullptr;
}

//- Execution
PreparedQueryResult PreparedStatementTask::Query(MySQLConnection* conn, PreparedStatementBase* stmt)
{
    PreparedResultSet* result = conn->Query(stmt);
    if (!result || !result->GetRowCount())
    {
        delete result;
        result = nullptr;
    }

    return PreparedQueryResult(result);
}

bool PreparedStatementTask::Execute(MySQLConnection* conn, PreparedStatementBase* stmt)
{
    return conn->Execute(stmt);
}

template<typename T>
std::string PreparedStatementData::ToString(T value)
{
    return Trinity::StringFormat("{}", value);
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

std::string PreparedStatementData::ToString(std::nullptr_t)
{
    return "NULL";
}
