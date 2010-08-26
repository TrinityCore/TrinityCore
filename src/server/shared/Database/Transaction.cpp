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

#include "DatabaseEnv.h"
#include "Transaction.h"

void Transaction::Append(const char* sql)
{
    m_queries.push(strdup(sql));
}

void Transaction::PAppend(const char* sql, ...)
{
    va_list ap;
    char szQuery [MAX_QUERY_LEN];
    va_start(ap, sql);
    vsnprintf(szQuery, MAX_QUERY_LEN, sql, ap);
    va_end(ap);

    Append(szQuery);
}

void Transaction::Cleanup()
{
    while (!m_queries.empty())
    {
        free((void*)const_cast<char*>(m_queries.front()));
        m_queries.pop();
    }
}

bool TransactionTask::Execute()
{
    std::queue<char*>& queries = m_trans->m_queries;
    if (queries.empty())
        return false;

    const char* sql;

    m_conn->BeginTransaction();
    while (!queries.empty())
    {
        sql = queries.front();
        if (!m_conn->Execute(sql))
        {
            sLog.outSQLDriver("[Warning] Transaction aborted. %u queries not executed.", (uint32)queries.size());
            free((void*)const_cast<char*>(sql));
            queries.pop();
            m_conn->RollbackTransaction();
            return false;
        }

        free((void*)const_cast<char*>(sql));
        queries.pop();
    }

    m_conn->CommitTransaction();
    return true;
}
