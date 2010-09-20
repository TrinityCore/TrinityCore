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

#include "MySQLConnection.h"
#include "QueryHolder.h"
#include "PreparedStatement.h"
#include "Log.h"

bool SQLQueryHolder::SetQuery(size_t index, const char *sql)
{
    if (m_queries.size() <= index)
    {
        sLog.outError("Query index (%zu) out of range (size: %u) for query: %s", index, (uint32)m_queries.size(), sql);
        return false;
    }

    /// not executed yet, just stored (it's not called a holder for nothing)
    SQLElementData element;
    element.type = SQL_ELEMENT_RAW;
    element.element.query = strdup(sql);
    
    SQLResultSetUnion result;
    result.qresult = NULL;

    m_queries[index] = SQLResultPair(element, result);
    return true;
}

bool SQLQueryHolder::SetPQuery(size_t index, const char *format, ...)
{
    if (!format)
    {
        sLog.outError("Query (index: %zu) is empty.",index);
        return false;
    }

    va_list ap;
    char szQuery [MAX_QUERY_LEN];
    va_start(ap, format);
    int res = vsnprintf(szQuery, MAX_QUERY_LEN, format, ap);
    va_end(ap);

    if (res == -1)
    {
        sLog.outError("SQL Query truncated (and not execute) for format: %s",format);
        return false;
    }

    return SetQuery(index, szQuery);
}

bool SQLQueryHolder::SetPreparedQuery(size_t index, PreparedStatement* stmt)
{
    if (m_queries.size() <= index)
    {
        sLog.outError("Query index (%zu) out of range (size: %u) for prepared statement", index, (uint32)m_queries.size());
        return false;
    }

    /// not executed yet, just stored (it's not called a holder for nothing)
    SQLElementData element;
    element.type = SQL_ELEMENT_PREPARED;
    element.element.stmt = stmt;
    
    SQLResultSetUnion result;
    result.presult = NULL;

    m_queries[index] = SQLResultPair(element, result);
    return true;
}

QueryResult SQLQueryHolder::GetResult(size_t index)
{
    // Don't call to this function if the index is of an ad-hoc statement
    if (index < m_queries.size())
    {
        /// the query strings are freed on the first GetResult or in the destructor
        if (SQLElementData* data = &m_queries[index].first)
        {
            free((void*)(const_cast<char*>(data->element.query)));
            data->element.query = NULL;
        }

        ResultSet* result = m_queries[index].second.qresult;
        if (!result || !result->GetRowCount())
            return QueryResult(NULL);

        result->NextRow();
        return QueryResult(result);
    }
    else
        return QueryResult(NULL);
}

PreparedQueryResult SQLQueryHolder::GetPreparedResult(size_t index)
{
    // Don't call to this function if the index is of a prepared statement
    if (index < m_queries.size())
    {
        /// the query strings are freed on the first GetResult or in the destructor
        if (SQLElementData* data = &m_queries[index].first)
        {
            delete data->element.stmt;
            data->element.stmt = NULL;
        }

        PreparedResultSet* result = m_queries[index].second.presult;
        if (!result || !result->GetRowCount())
            return PreparedQueryResult(NULL);

        result->NextRow();
        return PreparedQueryResult(result);
    }
    else
        return PreparedQueryResult(NULL);
}

void SQLQueryHolder::SetResult(size_t index, ResultSet* result)
{
    /// store the result in the holder
    if (index < m_queries.size())
        m_queries[index].second.qresult = result;
}

void SQLQueryHolder::SetPreparedResult(size_t index, PreparedResultSet* result)
{
    /// store the result in the holder
    if (index < m_queries.size())
        m_queries[index].second.presult = result;
}

SQLQueryHolder::~SQLQueryHolder()
{
    for (size_t i = 0; i < m_queries.size(); i++)
    {
        /// if the result was never used, free the resources
        /// results used already (getresult called) are expected to be deleted
        if (SQLElementData* data = &m_queries[i].first)
        {
            switch (data->type)
            {
                case SQL_ELEMENT_RAW:
                    free((void*)(const_cast<char*>(data->element.query)));
                    break;
                case SQL_ELEMENT_PREPARED:
                    delete data->element.stmt;
                    break;
            }
        }
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
        if (SQLElementData* data = &queries[i].first)
        {
            switch (data->type)
            {
                case SQL_ELEMENT_RAW:
                {
                    char const *sql = data->element.query;
                    if (sql)
                        m_holder->SetResult(i, m_conn->Query(sql));
                    break;
                }
                case SQL_ELEMENT_PREPARED:
                {
                    PreparedStatement* stmt = data->element.stmt;
                    if (stmt)
                        m_holder->SetPreparedResult(i, m_conn->Query(stmt));
                    break;
                }
            }
        }
    }

    m_result.set(m_holder);
    return true;
}
