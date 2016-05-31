/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
BasicStatementTask::BasicStatementTask(const char* sql, bool async) :
m_result(nullptr)
{
    m_sql = strdup(sql);
    m_has_result = async; // If the operation is async, then there's a result
    if (async)
        m_result = new QueryResultPromise();
}

BasicStatementTask::~BasicStatementTask()
{
    free((void*)m_sql);
    if (m_has_result && m_result != nullptr)
        delete m_result;
}

bool BasicStatementTask::Execute()
{
    if (m_has_result)
    {
        ResultSet* result = m_conn->Query(m_sql);
        if (!result || !result->GetRowCount() || !result->NextRow())
        {
            delete result;
            m_result->set_value(QueryResult(NULL));
            return false;
        }

        m_result->set_value(QueryResult(result));
        return true;
    }

    return m_conn->Execute(m_sql);
}
