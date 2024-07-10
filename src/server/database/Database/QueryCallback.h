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

#ifndef _QUERY_CALLBACK_H
#define _QUERY_CALLBACK_H

#include "DatabaseEnvFwd.h"
#include "Define.h"
#include <functional>
#include <future>
#include <list>
#include <queue>
#include <variant>

class TC_DATABASE_API QueryCallback
{
public:
    explicit QueryCallback(std::future<QueryResult>&& result);
    explicit QueryCallback(std::future<PreparedQueryResult>&& result);
    QueryCallback(QueryCallback&& right) noexcept;
    QueryCallback& operator=(QueryCallback&& right) noexcept;
    ~QueryCallback();

    QueryCallback&& WithCallback(std::function<void(QueryResult)>&& callback);
    QueryCallback&& WithPreparedCallback(std::function<void(PreparedQueryResult)>&& callback);

    QueryCallback&& WithChainingCallback(std::function<void(QueryCallback&, QueryResult)>&& callback);
    QueryCallback&& WithChainingPreparedCallback(std::function<void(QueryCallback&, PreparedQueryResult)>&& callback);

    // Moves std::future from next to this object
    void SetNextQuery(QueryCallback&& next);

    // returns true when completed
    bool InvokeIfReady();

private:
    QueryCallback(QueryCallback const& right) = delete;
    QueryCallback& operator=(QueryCallback const& right) = delete;

    std::variant<std::future<QueryResult>, std::future<PreparedQueryResult>> _query;

    using QueryCallbackData = std::variant<std::function<void(QueryCallback&, QueryResult)>, std::function<void(QueryCallback&, PreparedQueryResult)>>;
    std::queue<QueryCallbackData, std::list<QueryCallbackData>> _callbacks;
};

#endif // _QUERY_CALLBACK_H
