/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "SQLOperation.h"

class TC_DATABASE_API SQLQueryHolderBase
{
    friend class SQLQueryHolderTask;
    private:
        std::vector<std::pair<PreparedStatementBase*, PreparedQueryResult>> m_queries;
    public:
        SQLQueryHolderBase() { }
        virtual ~SQLQueryHolderBase();
        void SetSize(size_t size);
        PreparedQueryResult GetPreparedResult(size_t index);
        void SetPreparedResult(size_t index, PreparedResultSet* result);

    protected:
        bool SetPreparedQueryImpl(size_t index, PreparedStatementBase* stmt);
};

template<typename T>
class SQLQueryHolder : public SQLQueryHolderBase
{
public:
    bool SetPreparedQuery(size_t index, PreparedStatement<T>* stmt)
    {
        return SetPreparedQueryImpl(index, stmt);
    }
};

class TC_DATABASE_API SQLQueryHolderTask : public SQLOperation
{
    private:
        SQLQueryHolderBase* m_holder;
        QueryResultHolderPromise m_result;
        bool m_executed;

    public:
        SQLQueryHolderTask(SQLQueryHolderBase* holder)
            : m_holder(holder), m_executed(false) { }

        ~SQLQueryHolderTask();

        bool Execute() override;
        QueryResultHolderFuture GetFuture() { return m_result.get_future(); }
};

class TC_DATABASE_API SQLQueryHolderCallback
{
public:
    SQLQueryHolderCallback(QueryResultHolderFuture&& future) : m_future(std::move(future)) { }
    SQLQueryHolderCallback(SQLQueryHolderCallback&&) = default;

    SQLQueryHolderCallback& operator=(SQLQueryHolderCallback&&) = default;

    void AfterComplete(std::function<void(SQLQueryHolderBase*)> callback) &
    {
        m_callback = std::move(callback);
    }

    bool InvokeIfReady();

    QueryResultHolderFuture m_future;
    std::function<void(SQLQueryHolderBase*)> m_callback;
};

#endif
