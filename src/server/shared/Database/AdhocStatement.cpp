/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "AdhocStatement.h"
#include "MySQLConnection.h"

/*! Basic, ad-hoc queries. */
BasicStatementTask::BasicStatementTask(const char* sql) :
m_has_result(false)
{
    m_sql = strdup(sql);
}

BasicStatementTask::BasicStatementTask(const char* sql, QueryResultFuture result) :
m_has_result(true),
m_result(result)
{
    m_sql = strdup(sql);
}

BasicStatementTask::~BasicStatementTask()
{
    free((void*)m_sql);
}

bool BasicStatementTask::Execute()
{
    if (m_has_result)
    {
        ResultSet* result = m_conn->Query(m_sql);
        if (!result || !result->GetRowCount())
        {
            delete result;
            m_result.set(QueryResult(NULL));
            return false;
        }
        result->NextRow();
        m_result.set(QueryResult(result));
        return true;
    }

    return m_conn->Execute(m_sql);
}
