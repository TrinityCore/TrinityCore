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

#if !defined(QUERYRESULTMYSQL_H)
#define QUERYRESULTMYSQL_H

#ifdef WIN32
#define FD_SETSIZE 1024
#include <winsock2.h>
#include <mysql/mysql.h>
#else
#include <mysql.h>
#endif

class QueryResultMysql : public QueryResult
{
    public:
        QueryResultMysql(MYSQL_RES *result, MYSQL_FIELD *fields, uint64 rowCount, uint32 fieldCount);

        ~QueryResultMysql();

        bool NextRow();

    private:
        enum Field::DataTypes ConvertNativeType(enum_field_types mysqlType) const;
        void EndQuery();

        MYSQL_RES *mResult;
};
#endif
#endif

