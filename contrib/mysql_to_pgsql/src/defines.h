/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
 
#ifndef _DEFINES_
#define _DEFINES_

#ifdef WIN32
#include <winsock2.h>
#pragma warning(disable:4996)
#endif

#include <libpq-fe.h>
#include <mysql.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string.h>
using namespace std;


#ifdef WIN32
typedef unsigned __int64 uint64;
typedef unsigned int     uint32;
#else
#include <stdint.h>
#ifndef uint64_t
#include <linux/types.h>
#endif
typedef uint64_t      uint64;
typedef unsigned int  uint32;
#endif

struct sField
{
    string name;                                            // field name
    string def;                                             // field default data
    string type;                                            // field type
    uint32 flags;                                           // filed flags, see field flags;
};
typedef vector<sField> T_Table;
typedef vector<string> T_TableList;
typedef map< string, T_Table > TDataBase;

static 
void pg_notice(void *arg, const char *message)
{
    /// Do nothing
    //printf("%s\n", message);
}

inline
string ConvertNativeType(enum_field_types mysqlType, uint32 length)
{

    switch (mysqlType)
    {
        case FIELD_TYPE_TIMESTAMP:
            return "timestamp";
        case FIELD_TYPE_BIT:
            return "bit(1)";
        case FIELD_TYPE_DATETIME:
            return "date";
        case FIELD_TYPE_YEAR:
        case FIELD_TYPE_BLOB:
        case FIELD_TYPE_SET:
        case FIELD_TYPE_NULL:
        case FIELD_TYPE_ENUM:
            return "text";
        case FIELD_TYPE_TINY:
        case FIELD_TYPE_SHORT:
        case FIELD_TYPE_INT24:
            return "integer";
        case FIELD_TYPE_LONGLONG:
            return "int8";
        case FIELD_TYPE_LONG:
            return "bigint";
        case FIELD_TYPE_DECIMAL:
        case FIELD_TYPE_FLOAT:
        case FIELD_TYPE_DOUBLE:
            return "float";
        case FIELD_TYPE_STRING:
        {
            string temp;
            char str[10];
            temp = "char";
            if (length)
            {
                temp.append("(");
                sprintf(str,"%d",length);
                temp.append(str);
                temp.append(")");
            }
            return temp;
        }
        case FIELD_TYPE_VAR_STRING:
        {
            string temp;
            char str[10];
            temp = "varchar";
            if (length)
            {
                temp.append("(");
                sprintf(str,"%d",length);
                temp.append(str);
                temp.append(")");
            }
            return temp;
        }
        default:
            return "text";
    }
    return "text";
}

inline
bool IsNeeedEscapeString(enum_field_types mysqlType)
{
    switch(mysqlType)
    {
        case FIELD_TYPE_VAR_STRING:
        case FIELD_TYPE_STRING:
        case FIELD_TYPE_TINY_BLOB:
        case FIELD_TYPE_MEDIUM_BLOB:
        case FIELD_TYPE_LONG_BLOB:
        case FIELD_TYPE_BLOB:
            return true;
        default:
            return false;
    }
    return false;
}

inline
void PG_Exec_str(string sql, PGconn *mPGconn)
{
    PGresult *res = PQexec (mPGconn, sql.c_str());
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        printf( "SQL: %s", sql.c_str() );
        printf( "SQL %s", PQerrorMessage(mPGconn) );
    }
}

void PG_Escape_Str(string& str)
{
    if(str.empty())
        return;
    char* buf = new char[str.size()*2+1];
    PQescapeString(buf,str.c_str(),str.size());
    str = buf;
    delete[] buf;
}

#endif

