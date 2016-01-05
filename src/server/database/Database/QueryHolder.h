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

#ifndef _QUERYHOLDER_H
#define _QUERYHOLDER_H

#include <future>

class SQLQueryHolder
{
    friend class SQLQueryHolderTask;
    private:
        typedef std::pair<SQLElementData, SQLResultSetUnion> SQLResultPair;
        std::vector<SQLResultPair> m_queries;
    public:
        SQLQueryHolder() { }
        ~SQLQueryHolder();
        bool SetQuery(size_t index, const char* sql);
        template<typename Format, typename... Args>
        bool SetPQuery(size_t index, Format&& sql, Args&&... args)
        {
            return SetQuery(index, Trinity::StringFormat(std::forward<Format>(sql), std::forward<Args>(args)...).c_str());
        }
        bool SetPreparedQuery(size_t index, PreparedStatement* stmt);
        void SetSize(size_t size);
        QueryResult GetResult(size_t index);
        PreparedQueryResult GetPreparedResult(size_t index);
        void SetResult(size_t index, ResultSet* result);
        void SetPreparedResult(size_t index, PreparedResultSet* result);
};

typedef std::future<SQLQueryHolder*> QueryResultHolderFuture;
typedef std::promise<SQLQueryHolder*> QueryResultHolderPromise;

class SQLQueryHolderTask : public SQLOperation
{
    private:
        SQLQueryHolder* m_holder;
        QueryResultHolderPromise m_result;
        bool m_executed;

    public:
        SQLQueryHolderTask(SQLQueryHolder* holder)
            : m_holder(holder), m_executed(false) { }

        ~SQLQueryHolderTask();

        bool Execute() override;
        QueryResultHolderFuture GetFuture() { return m_result.get_future(); }
};

#endif
