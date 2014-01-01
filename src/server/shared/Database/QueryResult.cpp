/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "DatabaseEnv.h"
#include "Log.h"

ResultSet::ResultSet(MYSQL_RES *result, MYSQL_FIELD *fields, uint64 rowCount, uint32 fieldCount) :
_rowCount(rowCount),
_fieldCount(fieldCount),
_result(result),
_fields(fields)
{
    _currentRow = new Field[_fieldCount];
    ASSERT(_currentRow);
}

PreparedResultSet::PreparedResultSet(MYSQL_STMT* stmt, MYSQL_RES *result, uint64 rowCount, uint32 fieldCount) :
m_rowCount(rowCount),
m_rowPosition(0),
m_fieldCount(fieldCount),
m_rBind(NULL),
m_stmt(stmt),
m_res(result),
m_isNull(NULL),
m_length(NULL)
{
    if (!m_res)
        return;

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
        TC_LOG_WARN("sql.sql", "%s:mysql_stmt_store_result, cannot bind result from MySQL server. Error: %s", __FUNCTION__, mysql_stmt_error(m_stmt));
        delete[] m_rBind;
        delete[] m_isNull;
        delete[] m_length;
        return;
    }

    //- This is where we prepare the buffer based on metadata
    uint32 i = 0;
    MYSQL_FIELD* field = mysql_fetch_field(m_res);
    while (field)
    {
        size_t size = Field::SizeForType(field);

        m_rBind[i].buffer_type = field->type;
        m_rBind[i].buffer = malloc(size);
        memset(m_rBind[i].buffer, 0, size);
        m_rBind[i].buffer_length = size;
        m_rBind[i].length = &m_length[i];
        m_rBind[i].is_null = &m_isNull[i];
        m_rBind[i].error = NULL;
        m_rBind[i].is_unsigned = field->flags & UNSIGNED_FLAG;

        ++i;
        field = mysql_fetch_field(m_res);
    }

    //- This is where we bind the bind the buffer to the statement
    if (mysql_stmt_bind_result(m_stmt, m_rBind))
    {
        TC_LOG_WARN("sql.sql", "%s:mysql_stmt_bind_result, cannot bind result from MySQL server. Error: %s", __FUNCTION__, mysql_stmt_error(m_stmt));
        delete[] m_rBind;
        delete[] m_isNull;
        delete[] m_length;
        return;
    }

    m_rowCount = mysql_stmt_num_rows(m_stmt);

    m_rows.resize(uint32(m_rowCount));
    while (_NextRow())
    {
        m_rows[uint32(m_rowPosition)] = new Field[m_fieldCount];
        for (uint64 fIndex = 0; fIndex < m_fieldCount; ++fIndex)
        {
            if (!*m_rBind[fIndex].is_null)
                m_rows[uint32(m_rowPosition)][fIndex].SetByteValue( m_rBind[fIndex].buffer,
                                                            m_rBind[fIndex].buffer_length,
                                                            m_rBind[fIndex].buffer_type,
                                                           *m_rBind[fIndex].length );
            else
                switch (m_rBind[fIndex].buffer_type)
                {
                    case MYSQL_TYPE_TINY_BLOB:
                    case MYSQL_TYPE_MEDIUM_BLOB:
                    case MYSQL_TYPE_LONG_BLOB:
                    case MYSQL_TYPE_BLOB:
                    case MYSQL_TYPE_STRING:
                    case MYSQL_TYPE_VAR_STRING:
                    m_rows[uint32(m_rowPosition)][fIndex].SetByteValue( "",
                                                            m_rBind[fIndex].buffer_length,
                                                            m_rBind[fIndex].buffer_type,
                                                           *m_rBind[fIndex].length );
                    break;
                    default:
                    m_rows[uint32(m_rowPosition)][fIndex].SetByteValue( 0,
                                                            m_rBind[fIndex].buffer_length,
                                                            m_rBind[fIndex].buffer_type,
                                                           *m_rBind[fIndex].length );
                }
        }
        m_rowPosition++;
    }
    m_rowPosition = 0;

    /// All data is buffered, let go of mysql c api structures
    CleanUp();
}

ResultSet::~ResultSet()
{
    CleanUp();
}

PreparedResultSet::~PreparedResultSet()
{
    for (uint32 i = 0; i < uint32(m_rowCount); ++i)
        delete[] m_rows[i];
}

bool ResultSet::NextRow()
{
    MYSQL_ROW row;

    if (!_result)
        return false;

    row = mysql_fetch_row(_result);
    if (!row)
    {
        CleanUp();
        return false;
    }

    for (uint32 i = 0; i < _fieldCount; i++)
        _currentRow[i].SetStructuredValue(row[i], _fields[i].type);

    return true;
}

bool PreparedResultSet::NextRow()
{
    /// Only updates the m_rowPosition so upper level code knows in which element
    /// of the rows vector to look
    if (++m_rowPosition >= m_rowCount)
        return false;

    return true;
}

bool PreparedResultSet::_NextRow()
{
    /// Only called in low-level code, namely the constructor
    /// Will iterate over every row of data and buffer it
    if (m_rowPosition >= m_rowCount)
        return false;

    int retval = mysql_stmt_fetch( m_stmt );

    if (!retval || retval == MYSQL_DATA_TRUNCATED)
        retval = true;

    if (retval == MYSQL_NO_DATA)
        retval = false;

    return retval;
}

void ResultSet::CleanUp()
{
    if (_currentRow)
    {
        delete [] _currentRow;
        _currentRow = NULL;
    }

    if (_result)
    {
        mysql_free_result(_result);
        _result = NULL;
    }
}

void PreparedResultSet::CleanUp()
{
    /// More of the in our code allocated sources are deallocated by the poorly documented mysql c api
    if (m_res)
        mysql_free_result(m_res);

    FreeBindBuffer();
    mysql_stmt_free_result(m_stmt);

    delete[] m_rBind;
}

void PreparedResultSet::FreeBindBuffer()
{
    for (uint32 i = 0; i < m_fieldCount; ++i)
        free (m_rBind[i].buffer);
}
