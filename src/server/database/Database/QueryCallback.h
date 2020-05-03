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

#include "Define.h"
#include "DatabaseEnvFwd.h"
#include <functional>
#include <future>
#include <list>
#include <queue>
#include <utility>

class TC_DATABASE_API QueryCallback
{
public:
    explicit QueryCallback(QueryResultFuture&& result);
    explicit QueryCallback(PreparedQueryResultFuture&& result);
    QueryCallback(QueryCallback&& right);
    QueryCallback& operator=(QueryCallback&& right);
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

    template<typename T> friend void ConstructActiveMember(T* obj);
    template<typename T> friend void DestroyActiveMember(T* obj);
    template<typename T> friend void MoveFrom(T* to, T&& from);

    union
    {
        QueryResultFuture _string;
        PreparedQueryResultFuture _prepared;
    };
    bool _isPrepared;

    struct QueryCallbackData;
    std::queue<QueryCallbackData, std::list<QueryCallbackData>> _callbacks;
};

#endif // _QUERY_CALLBACK_H
