/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "PreparedStatement.h"
#include "MySQLConnection.h"
#include "Log.h"

PreparedStatement::PreparedStatement(uint32 index) :
m_stmt(NULL),
m_index(index)
{
}

PreparedStatement::~PreparedStatement()
{
}

void PreparedStatement::BindParameters()
{
    ASSERT (m_stmt);

    uint32 i = 0;
    for (; i < statement_data.size(); i++)
    {
        switch (statement_data[i].type)
        {
            case TYPE_BOOL:
                m_stmt->setBool(i, statement_data[i].data.boolean);
                break;
            case TYPE_UI8:
            case TYPE_UI16:
            case TYPE_UI32:
                m_stmt->setUInt32(i, statement_data[i].data.ui32);
                break;
            case TYPE_I8:
            case TYPE_I16:
            case TYPE_I32:
                m_stmt->setInt32(i, statement_data[i].data.i32);
                break;
            case TYPE_UI64:
                m_stmt->setUInt64(i, statement_data[i].data.ui64);
                break;
            case TYPE_I64:
                m_stmt->setInt64(i, statement_data[i].data.i64);
                break;
            case TYPE_FLOAT:
                m_stmt->setFloat(i, statement_data[i].data.f);
                break;
            case TYPE_DOUBLE:
                m_stmt->setDouble(i, statement_data[i].data.d);
                break;
            case TYPE_STRING:
                m_stmt->setString(i, statement_data[i].str.c_str());
                break;
        }
    }
    #ifdef _DEBUG
    if (i < m_stmt->m_paramCount)
        sLog.outSQLDriver("[WARNING]: BindParameters() for statement %u did not bind all allocated parameters", m_index);
    #endif
}

//- Bind to buffer
void PreparedStatement::setBool(const uint8 index, const bool value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.boolean = value;
    statement_data[index].type = TYPE_BOOL;
}

void PreparedStatement::setUInt8(const uint8 index, const uint8 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.ui32 = value;
    statement_data[index].type = TYPE_UI8;
}

void PreparedStatement::setUInt16(const uint8 index, const uint16 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.ui32 = value;
    statement_data[index].type = TYPE_UI16;
}

void PreparedStatement::setUInt32(const uint8 index, const uint32 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.ui32 = value;
    statement_data[index].type = TYPE_UI32;
}

void PreparedStatement::setUInt64(const uint8 index, const uint64 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.ui64 = value;
    statement_data[index].type = TYPE_UI64;
}

void PreparedStatement::setInt8(const uint8 index, const int8 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.i32 = value;
    statement_data[index].type = TYPE_I8;
}

void PreparedStatement::setInt16(const uint8 index, const int16 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.i32 = value;
    statement_data[index].type = TYPE_I16;
}

void PreparedStatement::setInt32(const uint8 index, const int32 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.i32 = value;
    statement_data[index].type = TYPE_I32;
}

void PreparedStatement::setInt64(const uint8 index, const int64 value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.i64 = value;
    statement_data[index].type = TYPE_I64;
}

void PreparedStatement::setFloat(const uint8 index, const float value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.f = value;
    statement_data[index].type = TYPE_FLOAT;
}

void PreparedStatement::setDouble(const uint8 index, const double value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].data.d = value;
    statement_data[index].type = TYPE_DOUBLE;
}

void PreparedStatement::setString(const uint8 index, const std::string& value)
{
    if (index >= statement_data.size())
        statement_data.resize(index+1);

    statement_data[index].str = value;
    statement_data[index].type = TYPE_STRING;
}

MySQLPreparedStatement::MySQLPreparedStatement(MYSQL_STMT* stmt) :
m_Mstmt(stmt),
m_bind(NULL)
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

//- Bind on mysql level
bool MySQLPreparedStatement::CheckValidIndex(uint8 index)
{
    if (index >= m_paramCount)
        return false;

    if (m_paramsSet[index])
        sLog.outSQLDriver("[WARNING] Prepared Statement (id: %u) trying to bind value on already bound index (%u).", m_stmt->m_index, index);
    return true;
}

void MySQLPreparedStatement::setBool(const uint8 index,const bool value)
{
    setUInt32(index, value);
}

void MySQLPreparedStatement::setUInt8(const uint8 index, const uint8 value)
{
    setUInt32(index, value);
}

void MySQLPreparedStatement::setUInt16(const uint8 index, const uint16 value)
{
    setUInt32(index, value);
}

void MySQLPreparedStatement::setUInt32(const uint8 index, const uint32 value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_LONG, &value, sizeof(uint32), true);
}

void MySQLPreparedStatement::setUInt64(const uint8 index, const uint64 value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_LONGLONG, &value, sizeof(uint64), true);
}

void MySQLPreparedStatement::setInt8(const uint8 index, const int8 value)
{
    setInt32(index, value);
}

void MySQLPreparedStatement::setInt16(const uint8 index, const int16 value)
{
    setInt32(index, value);
}

void MySQLPreparedStatement::setInt32(const uint8 index, const int32 value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_LONG, &value, sizeof(int32), false);
}

void MySQLPreparedStatement::setInt64(const uint8 index, const int64 value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_LONGLONG, &value, sizeof(int64), false);
}

void MySQLPreparedStatement::setFloat(const uint8 index, const float value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_FLOAT, &value, sizeof(float), (value > 0.0f));
}

void MySQLPreparedStatement::setDouble(const uint8 index, const double value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    setValue(param, MYSQL_TYPE_DOUBLE, &value, sizeof(double), (value > 0.0f));
}

void MySQLPreparedStatement::setString(const uint8 index, const char* value)
{
    CheckValidIndex(index);
    m_paramsSet[index] = true;
    MYSQL_BIND* param = &m_bind[index];
    size_t len = strlen(value) + 1;
    param->buffer_type = MYSQL_TYPE_VAR_STRING;
    delete [] static_cast<char *>(param->buffer);
    param->buffer = new char[len];
    param->buffer_length = len;
    param->is_null_value = 0;
    param->length = new unsigned long(len-1);

    memcpy(param->buffer, value, len);
}

void MySQLPreparedStatement::setValue(MYSQL_BIND* param, enum_field_types type, const void* value, uint32 len, bool isUnsigned)
{
    param->buffer_type = type;
    delete [] static_cast<char *>(param->buffer);
    param->buffer = new char[len];
    param->buffer_length = 0;
    param->is_null_value = 0;
    param->length = NULL;               // Only != NULL for strings
    param->is_unsigned = isUnsigned;

    memcpy(param->buffer, value, len);
}

//- Execution
PreparedStatementTask::PreparedStatementTask(PreparedStatement* stmt) :
m_stmt(stmt)
{
}

PreparedStatementTask::~PreparedStatementTask()
{
    delete m_stmt;
}

bool PreparedStatementTask::Execute()
{
    return m_conn->Execute(m_stmt);
}
