/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "Log.h"
#ifdef _WIN32 // hack for broken mysql.h not including the correct winsock header for SOCKET definition, fixed in 5.7
#include <winsock2.h>
#endif
#include <mysql.h>
#include <sstream>

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

MySQLPreparedStatement::MySQLPreparedStatement(MYSQL_STMT* stmt, std::string queryString) :
    m_stmt(nullptr), m_Mstmt(stmt), m_bind(nullptr), m_queryString(std::move(queryString))
{
    /// Initialize variable parameters
    m_paramCount = mysql_stmt_param_count(stmt);
    m_paramsSet.assign(m_paramCount, false);
    m_bind = new MYSQL_BIND[m_paramCount];
    memset(m_bind, 0, sizeof(MYSQL_BIND)*m_paramCount);

    /// "If set to 1, causes mysql_stmt_store_result() to update the metadata MYSQL_FIELD->max_length value."
    my_bool bool_tmp = 1;
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
            m_result->set_value(PreparedQueryResult(NULL));
            return false;
        }
        m_result->set_value(PreparedQueryResult(result));
        return true;
    }

    return m_conn->Execute(m_stmt);
}
