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
#include <sstream>

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

void MySQLPreparedStatement::ClearParameters()
{
    for (uint32 i=0; i < m_paramCount; ++i)
    {
        delete m_bind[i].length;
        m_bind[i].length = NULL;
        delete[] (char*) m_bind[i].buffer;
        m_bind[i].buffer = NULL;
        m_paramsSet[i] = false;
    }
}

static bool ParamenterIndexAssertFail(uint32 stmtIndex, uint8 index, uint32 paramCount)
{
    TC_LOG_ERROR("sql.driver", "Attempted to bind parameter %u%s on a PreparedStatement %u (statement has only %u parameters)", uint32(index) + 1, (index == 1 ? "st" : (index == 2 ? "nd" : (index == 3 ? "rd" : "nd"))), stmtIndex, paramCount);
    return false;
}

static void SetParameterValue(MYSQL_BIND* param, enum_field_types type, const void* value, uint32 len, bool isUnsigned)
{
    param->buffer_type = type;
    delete[] static_cast<char *>(param->buffer);
    param->buffer = new char[len];
    param->buffer_length = 0;
    param->is_null_value = 0;
    param->length = NULL;               // Only != NULL for strings
    param->is_unsigned = isUnsigned;

    memcpy(param->buffer, value, len);
}

//- Bind on mysql level
void MySQLPreparedStatement::AssertValidIndex(uint8 index)
{
    ASSERT(index < m_paramCount || ParamenterIndexAssertFail(m_stmt->m_index, index, m_paramCount));

    if (m_paramsSet[index])
        TC_LOG_ERROR("sql.sql", "[ERROR] Prepared Statement (id: %u) trying to bind value on already bound index (%u).", m_stmt->m_index, index);
}

void MySQLPreparedStatement::setNull(const uint8 index)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    param->buffer_type = MYSQL_TYPE_NULL;
    delete[] static_cast<char *>(param->buffer);
    param->buffer = NULL;
    param->buffer_length = 0;
    param->is_null_value = 1;
    delete param->length;
    param->length = NULL;
}

void MySQLPreparedStatement::setBool(const uint8 index, const bool value)
{
    setUInt8(index, value ? 1 : 0);
}

void MySQLPreparedStatement::setUInt8(const uint8 index, const uint8 value)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    SetParameterValue(param, MYSQL_TYPE_TINY, &value, sizeof(uint8), true);
}

void MySQLPreparedStatement::setUInt16(const uint8 index, const uint16 value)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    SetParameterValue(param, MYSQL_TYPE_SHORT, &value, sizeof(uint16), true);
}

void MySQLPreparedStatement::setUInt32(const uint8 index, const uint32 value)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    SetParameterValue(param, MYSQL_TYPE_LONG, &value, sizeof(uint32), true);
}

void MySQLPreparedStatement::setUInt64(const uint8 index, const uint64 value)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    SetParameterValue(param, MYSQL_TYPE_LONGLONG, &value, sizeof(uint64), true);
}

void MySQLPreparedStatement::setInt8(const uint8 index, const int8 value)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    SetParameterValue(param, MYSQL_TYPE_TINY, &value, sizeof(int8), false);
}

void MySQLPreparedStatement::setInt16(const uint8 index, const int16 value)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    SetParameterValue(param, MYSQL_TYPE_SHORT, &value, sizeof(int16), false);
}

void MySQLPreparedStatement::setInt32(const uint8 index, const int32 value)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    SetParameterValue(param, MYSQL_TYPE_LONG, &value, sizeof(int32), false);
}

void MySQLPreparedStatement::setInt64(const uint8 index, const int64 value)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    SetParameterValue(param, MYSQL_TYPE_LONGLONG, &value, sizeof(int64), false);
}

void MySQLPreparedStatement::setFloat(const uint8 index, const float value)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    SetParameterValue(param, MYSQL_TYPE_FLOAT, &value, sizeof(float), (value > 0.0f));
}

void MySQLPreparedStatement::setDouble(const uint8 index, const double value)
{
    AssertValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    SetParameterValue(param, MYSQL_TYPE_DOUBLE, &value, sizeof(double), (value > 0.0f));
}

void MySQLPreparedStatement::setBinary(const uint8 index, const std::vector<uint8>& value, bool isString)
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
    if (isString)
    {
        *param->length -= 1;
        param->buffer_type = MYSQL_TYPE_VAR_STRING;
    }

    memcpy(param->buffer, value.data(), len);
}

std::string MySQLPreparedStatement::getQueryString() const
{
    std::string queryString(m_queryString);

    size_t pos = 0;
    for (uint32 i = 0; i < m_stmt->statement_data.size(); i++)
    {
        pos = queryString.find('?', pos);
        std::stringstream ss;

        switch (m_stmt->statement_data[i].type)
        {
            case TYPE_BOOL:
                ss << uint16(m_stmt->statement_data[i].data.boolean);
                break;
            case TYPE_UI8:
                ss << uint16(m_stmt->statement_data[i].data.ui8);  // stringstream will append a character with that code instead of numeric representation
                break;
            case TYPE_UI16:
                ss << m_stmt->statement_data[i].data.ui16;
                break;
            case TYPE_UI32:
                ss << m_stmt->statement_data[i].data.ui32;
                break;
            case TYPE_I8:
                ss << int16(m_stmt->statement_data[i].data.i8);  // stringstream will append a character with that code instead of numeric representation
                break;
            case TYPE_I16:
                ss << m_stmt->statement_data[i].data.i16;
                break;
            case TYPE_I32:
                ss << m_stmt->statement_data[i].data.i32;
                break;
            case TYPE_UI64:
                ss << m_stmt->statement_data[i].data.ui64;
                break;
            case TYPE_I64:
                ss << m_stmt->statement_data[i].data.i64;
                break;
            case TYPE_FLOAT:
                ss << m_stmt->statement_data[i].data.f;
                break;
            case TYPE_DOUBLE:
                ss << m_stmt->statement_data[i].data.d;
                break;
            case TYPE_STRING:
                ss << '\'' << (char const*)m_stmt->statement_data[i].binary.data() << '\'';
                break;
            case TYPE_BINARY:
                ss << "BINARY";
                break;
            case TYPE_NULL:
                ss << "NULL";
                break;
        }

        std::string replaceStr = ss.str();
        queryString.replace(pos, 1, replaceStr);
        pos += replaceStr.length();
    }

    return queryString;
}
