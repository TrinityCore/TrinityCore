/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "DatabaseEnv.h"
#include "Log.h"

ResultSet::ResultSet(MYSQL_RES *result, MYSQL_FIELD *fields, uint64 rowCount, uint32 fieldCount)
: mFieldCount(fieldCount)
, mRowCount(rowCount)
, mResult(result)
{
    mCurrentRow = new Field[mFieldCount];
    ASSERT(mCurrentRow);

    for (uint32 i = 0; i < mFieldCount; i++)
         mCurrentRow[i].SetType(ConvertNativeType(fields[i].type));
}

ResultSet::~ResultSet()
{
    EndQuery();
}

bool ResultSet::NextRow()
{
    MYSQL_ROW row;

    if (!mResult)
        return false;

    row = mysql_fetch_row(mResult);
    if (!row)
    {
        EndQuery();
        return false;
    }

    for (uint32 i = 0; i < mFieldCount; i++)
        mCurrentRow[i].SetValue(row[i]);

    return true;
}

void ResultSet::EndQuery()
{
    if (mCurrentRow)
    {
        delete [] mCurrentRow;
        mCurrentRow = 0;
    }

    if (mResult)
    {
        mysql_free_result(mResult);
        mResult = 0;
    }
}

enum Field::DataTypes ResultSet::ConvertNativeType(enum_field_types mysqlType) const
{
    switch (mysqlType)
    {
        case FIELD_TYPE_TIMESTAMP:
        case FIELD_TYPE_DATE:
        case FIELD_TYPE_TIME:
        case FIELD_TYPE_DATETIME:
        case FIELD_TYPE_YEAR:
        case FIELD_TYPE_STRING:
        case FIELD_TYPE_VAR_STRING:
        case FIELD_TYPE_BLOB:
        case FIELD_TYPE_SET:
        case FIELD_TYPE_NULL:
            return Field::DB_TYPE_STRING;
        case FIELD_TYPE_TINY:

        case FIELD_TYPE_SHORT:
        case FIELD_TYPE_LONG:
        case FIELD_TYPE_INT24:
        case FIELD_TYPE_LONGLONG:
        case FIELD_TYPE_ENUM:
            return Field::DB_TYPE_INTEGER;
        case FIELD_TYPE_DECIMAL:
        case FIELD_TYPE_FLOAT:
        case FIELD_TYPE_DOUBLE:
            return Field::DB_TYPE_FLOAT;
        default:
            return Field::DB_TYPE_UNKNOWN;
    }
}

void ResultBind::BindResult(uint32& num_rows)
{
    FreeBindBuffer();

    m_res = mysql_stmt_result_metadata(m_stmt);
    if (!m_res)
        return;

    m_fieldCount = mysql_stmt_field_count(m_stmt);

    if (m_stmt->bind_result_done)
    {
        delete[] m_stmt->bind->length;
        delete[] m_stmt->bind->is_null;
    }

    m_rBind = new MYSQL_BIND[m_fieldCount];
    m_isNull = new my_bool[m_fieldCount];
    m_length = new unsigned long[m_fieldCount];
    
    memset(m_isNull, 0, sizeof(my_bool) * m_fieldCount);
    memset(m_rBind, 0, sizeof(MYSQL_BIND) * m_fieldCount);
    memset(m_length, 0, sizeof(unsigned long) * m_fieldCount);

    //- This is where we store the (entire) resultset
    if (mysql_stmt_store_result(m_stmt))
    {
        sLog.outSQLDriver("%s:mysql_stmt_store_result, cannot bind result from MySQL server. Error: %s", __FUNCTION__, mysql_stmt_error(m_stmt));
        return;
    }

    //- This is where we prepare the buffer based on metadata
    uint32 i = 0;
    MYSQL_FIELD* field;
    while ((field = mysql_fetch_field(m_res)))
    {
        size_t size = SizeForType(field);

        m_rBind[i].buffer_type = field->type;
        m_rBind[i].buffer = malloc(size);
        memset(m_rBind[i].buffer, 0, size);
        m_rBind[i].buffer_length = size;
        m_rBind[i].length = &m_length[i];
        m_rBind[i].is_null = &m_isNull[i];
        m_rBind[i].error = NULL;
        m_rBind[i].is_unsigned = field->flags & UNSIGNED_FLAG;

        ++i;
    }

    //- This is where we bind the bind the buffer to the statement
    if (mysql_stmt_bind_result(m_stmt, m_rBind))
    {
        sLog.outSQLDriver("%s:mysql_stmt_bind_result, cannot bind result from MySQL server. Error: %s", __FUNCTION__, mysql_stmt_error(m_stmt));
        delete[] m_rBind;
        delete[] m_isNull;
        delete[] m_length;
        return;
    }

    num_rows = mysql_stmt_num_rows(m_stmt);
}

void ResultBind::FreeBindBuffer()
{
    for (uint32 i = 0; i < m_fieldCount; ++i)
        free (m_rBind[i].buffer);
}

void ResultBind::CleanUp()
{
    FreeBindBuffer();
    mysql_stmt_free_result(m_stmt);
}

uint8 PreparedResultSet::GetUInt8(uint32 index)
{
    if (!CheckFieldIndex(index))
        return 0;

    return *reinterpret_cast<uint8*>(rbind->m_rBind[index].buffer);
}

int8 PreparedResultSet::GetInt8(uint32 index)
{
    if (!CheckFieldIndex(index))
        return 0;

    return *reinterpret_cast<int8*>(rbind->m_rBind[index].buffer);
}

uint16 PreparedResultSet::GetUInt16(uint32 index)
{
    if (!CheckFieldIndex(index))
        return 0;

    return *reinterpret_cast<uint16*>(rbind->m_rBind[index].buffer);
}

int16 PreparedResultSet::GetInt16(uint32 index)
{
    if (!CheckFieldIndex(index))
        return 0;

    return *reinterpret_cast<int16*>(rbind->m_rBind[index].buffer);
}

uint32 PreparedResultSet::GetUInt32(uint32 index)
{
    if (!CheckFieldIndex(index))
        return 0;

    return *reinterpret_cast<uint32*>(rbind->m_rBind[index].buffer);
}

int32 PreparedResultSet::GetInt32(uint32 index)
{
    if (!CheckFieldIndex(index))
        return 0;

    return *reinterpret_cast<int32*>(rbind->m_rBind[index].buffer);
}

float PreparedResultSet::GetFloat(uint32 index)
{
    if (!CheckFieldIndex(index))
        return 0;

    return *reinterpret_cast<float*>(rbind->m_rBind[index].buffer);
}

uint64 PreparedResultSet::GetUInt64(uint32 index)
{
    if (!CheckFieldIndex(index))
        return 0;            

    return *reinterpret_cast<uint64*>(rbind->m_rBind[index].buffer);
}

int64 PreparedResultSet::GetInt64(uint32 index)
{
    if (!CheckFieldIndex(index))
        return 0;            

    return *reinterpret_cast<int64*>(rbind->m_rBind[index].buffer);
}

std::string PreparedResultSet::GetString(uint32 index)
{
    if (!CheckFieldIndex(index))
        return std::string("");

    return std::string(static_cast<char const*>(rbind->m_rBind[index].buffer), *rbind->m_rBind[index].length);
}

const char* PreparedResultSet::GetCString(uint32 index)
{
    if (!CheckFieldIndex(index))
        return '\0';

    return static_cast<char const*>(rbind->m_rBind[index].buffer);
}

bool PreparedResultSet::NextRow()
{
    if (row_position >= num_rows)
        return false;

    int retval = mysql_stmt_fetch( rbind->m_stmt );

    if (!retval || retval == MYSQL_DATA_TRUNCATED)
        retval = true;

    if (retval == MYSQL_NO_DATA)
        retval = false;

    ++row_position;
    return retval;
}