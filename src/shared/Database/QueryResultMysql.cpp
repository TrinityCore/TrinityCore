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

#ifndef DO_POSTGRESQL

#include "DatabaseEnv.h"

QueryResultMysql::QueryResultMysql(MYSQL_RES *result, MYSQL_FIELD *fields, uint64 rowCount, uint32 fieldCount) :
    QueryResult(rowCount, fieldCount), mResult(result)
{

    mCurrentRow = new Field[mFieldCount];
    ASSERT(mCurrentRow);

    for (uint32 i = 0; i < mFieldCount; i++)
        mCurrentRow[i].SetType(ConvertNativeType(fields[i].type));
}

QueryResultMysql::~QueryResultMysql()
{
    EndQuery();
}

bool QueryResultMysql::NextRow()
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

void QueryResultMysql::EndQuery()
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

enum Field::DataTypes QueryResultMysql::ConvertNativeType(enum_field_types mysqlType) const
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
#endif

