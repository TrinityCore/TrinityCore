/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#ifdef DO_POSTGRESQL

#include "DatabaseEnv.h"

QueryResultPostgre::QueryResultPostgre(PGresult *result, uint64 rowCount, uint32 fieldCount) :
    QueryResult(rowCount, fieldCount), mResult(result),  mTableIndex(0)
{

    mCurrentRow = new Field[mFieldCount];
    ASSERT(mCurrentRow);

    for (uint32 i = 0; i < mFieldCount; i++)
        mCurrentRow[i].SetType(ConvertNativeType(PQftype( result, i )));
}

QueryResultPostgre::~QueryResultPostgre()
{
    EndQuery();
}

bool QueryResultPostgre::NextRow()
{
    if (!mResult)
        return false;

    if (mTableIndex >= mRowCount)
    {
        EndQuery();
        return false;
    }

    char* pPQgetvalue;
    for (int j = 0; j < mFieldCount; j++)
    {
        pPQgetvalue = PQgetvalue(mResult, mTableIndex, j);
        if(pPQgetvalue && !(*pPQgetvalue))
            pPQgetvalue = NULL;

        mCurrentRow[j].SetValue(pPQgetvalue);
    }
    ++mTableIndex;

    return true;
}

void QueryResultPostgre::EndQuery()
{
    if (mCurrentRow)
    {
        delete [] mCurrentRow;
        mCurrentRow = 0;
    }

    if (mResult)
    {
        PQclear(mResult);
        mResult = 0;
    }
}

// see types in #include <postgre/pg_type.h>
enum Field::DataTypes QueryResultPostgre::ConvertNativeType(Oid  pOid ) const
{
    switch (pOid)
    {
        case BPCHAROID:
        case CIDOID:
        case CIDROID:
        case CIRCLEOID:
        case INETOID:
        case NAMEOID:
        case TEXTOID:
        case VARCHAROID:
            return Field::DB_TYPE_STRING;
        case CASHOID:
        case FLOAT4OID:
        case FLOAT8OID:
        case NUMERICOID:
            return Field::DB_TYPE_FLOAT;
        case DATEOID:                                       // Date
        case RELTIMEOID:                                    // Date
        case TIMEOID:                                       // Time
        case TIMETZOID:                                     // Time
        case ABSTIMEOID:                                    // DateTime
        case INTERVALOID:                                   // DateTime
        case TIMESTAMPOID:                                  // DateTime
        case TIMESTAMPTZOID:                                // DateTime
        case INT2OID:                                       // Int
        case INT2VECTOROID:                                 // Int
        case INT4OID:                                       // Int
        case OIDOID:                                        // Int
        case CHAROID:                                       // UInt
        case INT8OID:                                       // LongLong
            return Field::DB_TYPE_INTEGER;
        case BOOLOID:
            return Field::DB_TYPE_BOOL;                     // Bool
/*
        case BOXOID:    Rect;
        case LINEOID:   Rect;
        case VARBITOID: BitArray;
        case BYTEAOID:  ByteArray;
*/
        case LSEGOID:
        case OIDVECTOROID:
        case PATHOID:
        case POINTOID:
        case POLYGONOID:
        case REGPROCOID:
        case TIDOID:
        case TINTERVALOID:
        case UNKNOWNOID:
        case XIDOID:
        default:
            return Field::DB_TYPE_UNKNOWN;
    }
    return Field::DB_TYPE_UNKNOWN;
}
#endif

