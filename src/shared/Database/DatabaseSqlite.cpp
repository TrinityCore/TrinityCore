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

#ifndef DO_POSTGRESQL

#include "DatabaseEnv.h"

DatabaseSqlite::DatabaseSqlite() : Database(), mSqlite(0)
{
}

DatabaseSqlite::~DatabaseSqlite()
{
    if (mSqlite)
        sqlite_close(mSqlite);
}

bool DatabaseSqlite::Initialize(const char *infoString)
{
    if(!Database::Initialize(infoString))
        return false;

    char *errmsg;

    mSqlite = sqlite_open(infoString, 0, &errmsg);

    if (!mSqlite)
    {

        if (errmsg)
            sqlite_freemem(errmsg);
        return false;
    }

    return true;
}

QueryResult* DatabaseSqlite::Query(const char *sql)
{
    char *errmsg;

    if (!mSqlite)
        return 0;

    char **tableData;
    int rowCount;
    int fieldCount;

    sqlite_get_table(mSqlite, sql, &tableData, &rowCount, &fieldCount, &errmsg);

    if (!rowCount)
        return 0;

    if (!tableData)
    {

        if (errmsg)
            sqlite_freemem(errmsg);
        return 0;
    }

    QueryResultSqlite *queryResult = new QueryResultSqlite(tableData, rowCount, fieldCount);
    if(!queryResult)
    {

        return 0;
    }

    queryResult->NextRow();

    return queryResult;
}

bool DatabaseSqlite::Execute(const char *sql)
{
    char *errmsg;

    if (!mSqlite)
        return false;

    if(sqlite_exec(mSqlite, sql, NULL, NULL, &errmsg) != SQLITE_OK)
        return false;

    return true;
}
#endif

