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
#include "SQLOperation.h"
#include "MySQLConnection.h"

/*! Basic, ad-hoc queries. */
BasicStatementTask::BasicStatementTask(const char* sql) :
m_has_result(false)
{
    m_sql = strdup(sql);
}

BasicStatementTask::BasicStatementTask(const char* sql, QueryResultFuture result) :
m_result(result),
m_has_result(true)
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
        m_result.set(
            m_conn->Query(m_sql)
            );

        return true;
    }

    return m_conn->Execute(m_sql);
}

/*! Transactions. */
TransactionTask::TransactionTask()
{
}

TransactionTask::~TransactionTask()
{
   
}

void TransactionTask::ForcefulDelete()
{
    while (!m_queries.empty())
    {
        free((void*)const_cast<char*>(m_queries.front()));
        m_queries.pop();
    }
}

bool TransactionTask::Execute()
{
    if (m_queries.empty())
        return false;

    const char* sql;

    m_conn->BeginTransaction();
    while (!m_queries.empty())
    {
        sql = m_queries.front();
        if (!m_conn->Execute(sql))
        {
            free((void*)const_cast<char*>(sql));
            m_queries.pop();
            m_conn->RollbackTransaction();
            ForcefulDelete();
            return false;
        }

        free((void*)const_cast<char*>(sql));
        m_queries.pop();
    }

    m_conn->CommitTransaction();
    return true;
}

bool SQLQueryHolder::SetQuery(size_t index, const char *sql)
{
    if (m_queries.size() <= index)
    {
        sLog.outError("Query index (%u) out of range (size: %u) for query: %s", index, (uint32)m_queries.size(), sql);
        return false;
    }

    if (m_queries[index].first != NULL)
    {
        sLog.outError("Attempt assign query to holder index (%u) where other query stored (Old: [%s] New: [%s])",
            index, m_queries[index].first, sql);
        return false;
    }

    /// not executed yet, just stored (it's not called a holder for nothing)
    m_queries[index] = SQLResultPair(strdup(sql), QueryResult_AutoPtr(NULL));
    return true;
}

bool SQLQueryHolder::SetPQuery(size_t index, const char *format, ...)
{
    if (!format)
    {
        sLog.outError("Query (index: %u) is empty.",index);
        return false;
    }

    va_list ap;
    char szQuery [MAX_QUERY_LEN];
    va_start(ap, format);
    int res = vsnprintf(szQuery, MAX_QUERY_LEN, format, ap);
    va_end(ap);

    if (res==-1)
    {
        sLog.outError("SQL Query truncated (and not execute) for format: %s",format);
        return false;
    }

    return SetQuery(index, szQuery);
}

QueryResult_AutoPtr SQLQueryHolder::GetResult(size_t index)
{
    if (index < m_queries.size())
    {
        /// the query strings are freed on the first GetResult or in the destructor
        if (m_queries[index].first != NULL)
        {
            free((void*)(const_cast<char*>(m_queries[index].first)));
            m_queries[index].first = NULL;
        }
        /// when you get a result aways remember to delete it!
        return m_queries[index].second;
    }
    else
        return QueryResult_AutoPtr(NULL);
}

void SQLQueryHolder::SetResult(size_t index, QueryResult_AutoPtr result)
{
    /// store the result in the holder
    if (index < m_queries.size())
        m_queries[index].second = result;
}

SQLQueryHolder::~SQLQueryHolder()
{
    for (size_t i = 0; i < m_queries.size(); i++)
    {
        /// if the result was never used, free the resources
        /// results used already (getresult called) are expected to be deleted
        if (m_queries[i].first != NULL)
            free((void*)(const_cast<char*>(m_queries[i].first)));
    }
}

void SQLQueryHolder::SetSize(size_t size)
{
    /// to optimize push_back, reserve the number of queries about to be executed
    m_queries.resize(size);
}

bool SQLQueryHolderTask::Execute()
{
    if (!m_holder)
        return false;

    /// we can do this, we are friends
    std::vector<SQLQueryHolder::SQLResultPair> &queries = m_holder->m_queries;

    for (size_t i = 0; i < queries.size(); i++)
    {
        /// execute all queries in the holder and pass the results
        char const *sql = queries[i].first;
        if (sql)
            m_holder->SetResult(i, m_conn->Query(sql));
    }

    m_result.set(m_holder);
    return true;
}
