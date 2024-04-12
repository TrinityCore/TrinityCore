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

#include "MySQLPreparedStatement.h"
#include "Errors.h"
#include "Log.h"
#include "MySQLHacks.h"
#include "PreparedStatement.h"
#include <chrono>
#include <cstring>

template<typename T>
struct MySQLType { };

template<> struct MySQLType<uint8> : std::integral_constant<enum_field_types, MYSQL_TYPE_TINY> { };
template<> struct MySQLType<uint16> : std::integral_constant<enum_field_types, MYSQL_TYPE_SHORT> { };
template<> struct MySQLType<uint32> : std::integral_constant<enum_field_types, MYSQL_TYPE_LONG> { };
template<> struct MySQLType<uint64> : std::integral_constant<enum_field_types, MYSQL_TYPE_LONGLONG> { };
template<> struct MySQLType<int8> : std::integral_constant<enum_field_types, MYSQL_TYPE_TINY> { };
template<> struct MySQLType<int16> : std::integral_constant<enum_field_types, MYSQL_TYPE_SHORT> { };
template<> struct MySQLType<int32> : std::integral_constant<enum_field_types, MYSQL_TYPE_LONG> { };
template<> struct MySQLType<int64> : std::integral_constant<enum_field_types, MYSQL_TYPE_LONGLONG> { };
template<> struct MySQLType<float> : std::integral_constant<enum_field_types, MYSQL_TYPE_FLOAT> { };
template<> struct MySQLType<double> : std::integral_constant<enum_field_types, MYSQL_TYPE_DOUBLE> { };

MySQLPreparedStatement::MySQLPreparedStatement(MySQLStmt* stmt, std::string queryString) :
    m_stmt(nullptr), m_Mstmt(stmt), m_bind(nullptr), m_queryString(std::move(queryString))
{
    /// Initialize variable parameters
    m_paramCount = mysql_stmt_param_count(stmt);
    m_paramsSet.assign(m_paramCount, false);
    m_bind = new MySQLBind[m_paramCount];
    memset(m_bind, 0, sizeof(MySQLBind) * m_paramCount);

    /// "If set to 1, causes mysql_stmt_store_result() to update the metadata MYSQL_FIELD->max_length value."
    MySQLBool bool_tmp = MySQLBool(1);
    mysql_stmt_attr_set(stmt, STMT_ATTR_UPDATE_MAX_LENGTH, &bool_tmp);
}

MySQLPreparedStatement::~MySQLPreparedStatement()
{
    ClearParameters();
    if (m_Mstmt->bind_result_done)
    {
        delete[] m_Mstmt->bind->length;
        delete[] m_Mstmt->bind->is_null;
    }
    mysql_stmt_close(m_Mstmt);
    delete[] m_bind;
}

void MySQLPreparedStatement::BindParameters(PreparedStatementBase* stmt)
{
    m_stmt = stmt;     // Cross reference them for debug output

    uint8 pos = 0;
    for (PreparedStatementData const& data : stmt->GetParameters())
    {
        std::visit([&](auto&& param)
        {
            SetParameter(pos, param);
        }, data.data);
        ++pos;
    }
#ifdef _DEBUG
    if (pos < m_paramCount)
        TC_LOG_WARN("sql.sql", "[WARNING]: BindParameters() for statement {} did not bind all allocated parameters", stmt->GetIndex());
#endif
}

void MySQLPreparedStatement::ClearParameters()
{
    for (uint32 i=0; i < m_paramCount; ++i)
    {
        delete m_bind[i].length;
        m_bind[i].length = nullptr;
        delete[] (char*) m_bind[i].buffer;
        m_bind[i].buffer = nullptr;
        m_paramsSet[i] = false;
    }
}

static bool ParamenterIndexAssertFail(uint32 stmtIndex, uint8 index, uint32 paramCount)
{
    TC_LOG_ERROR("sql.driver", "Attempted to bind parameter {}{} on a PreparedStatement {} (statement has only {} parameters)", uint32(index) + 1, (index == 1 ? "st" : (index == 2 ? "nd" : (index == 3 ? "rd" : "nd"))), stmtIndex, paramCount);
    return false;
}

//- Bind on mysql level
void MySQLPreparedStatement::AssertValidIndex(uint8 index)
{
    ASSERT(index < m_paramCount || ParamenterIndexAssertFail(m_stmt->GetIndex(), index, m_paramCount));

    if (m_paramsSet[index])
        TC_LOG_ERROR("sql.sql", "[ERROR] Prepared Statement (id: {}) trying to bind value on already bound index ({}).", m_stmt->GetIndex(), index);
}

void MySQLPreparedStatement::SetParameter(uint8 index, std::nullptr_t)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    param->buffer_type = MYSQL_TYPE_NULL;
    delete[] static_cast<char *>(param->buffer);
    param->buffer = nullptr;
    param->buffer_length = 0;
    param->is_null_value = 1;
    delete param->length;
    param->length = nullptr;
}

void MySQLPreparedStatement::SetParameter(uint8 index, bool value)
{
    SetParameter(index, uint8(value ? 1 : 0));
}

template<typename T>
void MySQLPreparedStatement::SetParameter(uint8 index, T value)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    uint32 len = uint32(sizeof(T));
    param->buffer_type = MySQLType<T>::value;
    delete[] static_cast<char*>(param->buffer);
    param->buffer = new char[len];
    param->buffer_length = 0;
    param->is_null_value = 0;
    param->length = nullptr;               // Only != NULL for strings
    param->is_unsigned = std::is_unsigned_v<T>;

    memcpy(param->buffer, &value, len);
}

void MySQLPreparedStatement::SetParameter(uint8 index, SystemTimePoint value)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    uint32 len = sizeof(MYSQL_TIME);
    param->buffer_type = MYSQL_TYPE_DATETIME;
    delete[] static_cast<char*>(param->buffer);
    param->buffer = new char[len];
    param->buffer_length = len;
    param->is_null_value = 0;
    delete param->length;
    param->length = new unsigned long(len);

    std::chrono::year_month_day ymd(time_point_cast<std::chrono::days>(value));
    std::chrono::hh_mm_ss hms(duration_cast<std::chrono::microseconds>(value - std::chrono::sys_days(ymd)));

    MYSQL_TIME* time = reinterpret_cast<MYSQL_TIME*>(static_cast<char*>(param->buffer));
    time->year = static_cast<int32>(ymd.year());
    time->month = static_cast<uint32>(ymd.month());
    time->day = static_cast<uint32>(ymd.day());
    time->hour = hms.hours().count();
    time->minute = hms.minutes().count();
    time->second = hms.seconds().count();
    time->second_part = hms.subseconds().count();
}

void MySQLPreparedStatement::SetParameter(uint8 index, std::string const& value)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    uint32 len = uint32(value.size());
    param->buffer_type = MYSQL_TYPE_VAR_STRING;
    delete [] static_cast<char*>(param->buffer);
    param->buffer = new char[len];
    param->buffer_length = len;
    param->is_null_value = 0;
    delete param->length;
    param->length = new unsigned long(len);

    memcpy(param->buffer, value.c_str(), len);
}

void MySQLPreparedStatement::SetParameter(uint8 index, std::vector<uint8> const& value)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    uint32 len = uint32(value.size());
    param->buffer_type = MYSQL_TYPE_BLOB;
    delete [] static_cast<char *>(param->buffer);
    param->buffer = new char[len];
    param->buffer_length = len;
    param->is_null_value = 0;
    delete param->length;
    param->length = new unsigned long(len);

    memcpy(param->buffer, value.data(), len);
}

std::string MySQLPreparedStatement::getQueryString() const
{
    std::string queryString(m_queryString);

    size_t pos = 0;
    for (PreparedStatementData const& data : m_stmt->GetParameters())
    {
        pos = queryString.find('?', pos);

        std::string replaceStr = std::visit([&](auto&& data)
        {
            return PreparedStatementData::ToString(data);
        }, data.data);

        queryString.replace(pos, 1, replaceStr);
        pos += replaceStr.length();
    }

    return queryString;
}
