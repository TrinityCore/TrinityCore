/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "Transaction.h"

//- Append a raw ad-hoc query to the transaction
void Transaction::Append(const char* sql)
{
    SQLElementData data;
    data.type = SQL_ELEMENT_RAW;
    data.element.query = strdup(sql);
    m_queries.push(data);
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

//- Append a prepared statement to the transaction
void Transaction::Append(PreparedStatement* stmt)
{
    SQLElementData data;
    data.type = SQL_ELEMENT_PREPARED;
    data.element.stmt = stmt;
    m_queries.push(data);
}

void Transaction::Cleanup()
{
    while (!m_queries.empty())
    {
        SQLElementData data = m_queries.front();
        switch (data.type)
        {
            case SQL_ELEMENT_PREPARED:
                delete data.element.stmt;
            break;
            case SQL_ELEMENT_RAW:
                free((void*)(data.element.query));
            break;
        }
        m_queries.pop();
    }
}

bool TransactionTask::Execute()
{
    std::queue<SQLElementData> &queries = m_trans->m_queries;
    if (queries.empty())
        return false;

    m_conn->BeginTransaction();
    while (!queries.empty())
    {
        SQLElementData data = queries.front();
        switch (data.type)
        {
            case SQL_ELEMENT_PREPARED:
            {
                PreparedStatement* stmt = data.element.stmt;
                ASSERT(stmt);
                if (!m_conn->Execute(stmt))
                {
                    sLog->outSQLDriver("[Warning] Transaction aborted. %u queries not executed.", (uint32)queries.size());
                    m_conn->RollbackTransaction();
                    return false;
                }
                delete data.element.stmt;
            }
            break;
            case SQL_ELEMENT_RAW:
            {
                const char* sql = data.element.query;
                ASSERT(sql);
                if (!m_conn->Execute(sql))
                {
                    sLog->outSQLDriver("[Warning] Transaction aborted. %u queries not executed.", (uint32)queries.size());
                    m_conn->RollbackTransaction();
                    return false;
                }
                free((void*)const_cast<char*>(sql));
            }
            break;
        }
        queries.pop();
    }
    m_conn->CommitTransaction();
    return true;
}
