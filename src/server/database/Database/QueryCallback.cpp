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

#include "QueryCallback.h"
#include "Duration.h"
#include "Errors.h"

QueryCallback::QueryCallback(std::future<QueryResult>&& result) : _query(std::move(result))
{
}

QueryCallback::QueryCallback(std::future<PreparedQueryResult>&& result) : _query(std::move(result))
{
}

QueryCallback::QueryCallback(QueryCallback&& right) noexcept : _query(std::move(right._query)), _callbacks(std::move(right._callbacks))
{
}

QueryCallback& QueryCallback::operator=(QueryCallback&& right) noexcept
{
    if (this != &right)
    {
        _query = std::move(right._query);
        _callbacks = std::move(right._callbacks);
    }
    return *this;
}

QueryCallback::~QueryCallback() = default;

QueryCallback&& QueryCallback::WithCallback(std::function<void(QueryResult)>&& callback)
{
    return WithChainingCallback([callback = std::move(callback)](QueryCallback& /*this*/, QueryResult result) { callback(std::move(result)); });
}

QueryCallback&& QueryCallback::WithPreparedCallback(std::function<void(PreparedQueryResult)>&& callback)
{
    return WithChainingPreparedCallback([callback = std::move(callback)](QueryCallback& /*this*/, PreparedQueryResult result) { callback(std::move(result)); });
}

QueryCallback&& QueryCallback::WithChainingCallback(std::function<void(QueryCallback&, QueryResult)>&& callback)
{
    ASSERT(!_callbacks.empty() || std::holds_alternative<std::future<QueryResult>>(_query), "Attempted to set callback function for string query on a prepared async query");
    _callbacks.emplace(std::move(callback));
    return std::move(*this);
}

QueryCallback&& QueryCallback::WithChainingPreparedCallback(std::function<void(QueryCallback&, PreparedQueryResult)>&& callback)
{
    ASSERT(!_callbacks.empty() || std::holds_alternative<std::future<PreparedQueryResult>>(_query), "Attempted to set callback function for prepared query on a string async query");
    _callbacks.emplace(std::move(callback));
    return std::move(*this);
}

void QueryCallback::SetNextQuery(QueryCallback&& next)
{
    if (this != &next)
        _query = std::move(next)._query;
}

bool QueryCallback::InvokeIfReady()
{
    auto checkStateAndReturnCompletion = [this]()
    {
        _callbacks.pop();
        bool hasNext = std::visit([](auto const& future) { return future.valid(); }, _query);
        if (_callbacks.empty())
        {
            ASSERT(!hasNext);
            return true;
        }

        // abort chain
        if (!hasNext)
            return true;

        ASSERT(_query.index() == _callbacks.front().index());
        return false;
    };

    return std::visit([&]<typename Result>(std::future<Result>&& future)
    {
        if (future.valid() && future.wait_for(0s) == std::future_status::ready)
        {
            std::future<Result> f(std::move(future));
            std::function<void(QueryCallback&, Result)> cb(std::get<std::function<void(QueryCallback&, Result)>>(std::move(_callbacks.front())));
            cb(*this, f.get());
            return checkStateAndReturnCompletion();
        }
        return false;
    }, std::move(_query));
}
