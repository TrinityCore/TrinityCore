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

#include "Define.h"
#include "DatabaseEnvFwd.h"
#include <vector>

class MySQLConnection;

class TC_DATABASE_API SQLQueryHolderBase
{
    friend class SQLQueryHolderTask;
    private:
        std::vector<std::pair<PreparedStatementBase*, PreparedQueryResult>> m_queries;
    public:
        SQLQueryHolderBase() = default;
        virtual ~SQLQueryHolderBase();
        void SetSize(size_t size);
        PreparedQueryResult GetPreparedResult(size_t index) const;
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

class TC_DATABASE_API SQLQueryHolderTask
{
public:
    static bool Execute(MySQLConnection* conn, SQLQueryHolderBase* holder);
};

class TC_DATABASE_API SQLQueryHolderCallback
{
public:
    SQLQueryHolderCallback(std::shared_ptr<SQLQueryHolderBase>&& holder, QueryResultHolderFuture&& future)
        : m_holder(std::move(holder)), m_future(std::move(future)) { }

    SQLQueryHolderCallback(SQLQueryHolderCallback&&) = default;

    SQLQueryHolderCallback& operator=(SQLQueryHolderCallback&&) = default;

    void AfterComplete(std::function<void(SQLQueryHolderBase const&)> callback) &
    {
        m_callback = std::move(callback);
    }

    bool InvokeIfReady();

    std::shared_ptr<SQLQueryHolderBase> m_holder;
    QueryResultHolderFuture m_future;
    std::function<void(SQLQueryHolderBase const&)> m_callback;
};

#endif
