/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

template<typename T>
inline void Destroy(T& t)
{
    t.~T();
}

template<typename T>
void DestroyActiveMember(T& obj)
{
    if (!obj._isPrepared)
        Destroy(obj._string);
    else
        Destroy(obj._prepared);
}

template<typename T>
void MoveFrom(T& to, T&& from)
{
    DestroyActiveMember(to);
    to._isPrepared = from._isPrepared;
    if (!to._isPrepared)
        to._string = std::move(from._string);
    else
        to._prepared = std::move(from._prepared);
}

struct QueryCallbackNew::QueryCallbackData
{
public:
    friend class QueryCallbackNew;

    QueryCallbackData(std::function<void(QueryResult)>&& callback) : _string(std::move(callback)), _isPrepared(false) { }
    QueryCallbackData(std::function<void(PreparedQueryResult)>&& callback) : _prepared(std::move(callback)), _isPrepared(true) { }
    QueryCallbackData(QueryCallbackData&& right) { MoveFrom(*this, std::move(right)); }
    QueryCallbackData& operator=(QueryCallbackData&& right) { MoveFrom(*this, std::move(right)); return *this; }
    ~QueryCallbackData() { DestroyActiveMember(*this); }

private:
    QueryCallbackData(QueryCallbackData const&) = delete;
    QueryCallbackData& operator=(QueryCallbackData const&) = delete;

    template<typename T> friend void MoveFrom(T& to, T&& from);
    template<typename T> friend void DestroyActiveMember(T& obj);

    union
    {
        std::function<void(QueryResult)> _string;
        std::function<void(PreparedQueryResult)> _prepared;
    };
    bool _isPrepared;
};

QueryCallbackNew::QueryCallbackNew(std::future<QueryResult>&& result) : _string(std::move(result)), _isPrepared(false)
{
}

QueryCallbackNew::QueryCallbackNew(std::future<PreparedQueryResult>&& result) : _prepared(std::move(result)), _isPrepared(true)
{
}

QueryCallbackNew::QueryCallbackNew(QueryCallbackNew&& right)
{
    MoveFrom(*this, std::move(right));
    _callbacks = std::move(right._callbacks);
}

QueryCallbackNew& QueryCallbackNew::operator=(QueryCallbackNew&& right)
{
    MoveFrom(*this, std::move(right));
    _callbacks = std::move(right._callbacks);
    return *this;
}

QueryCallbackNew::~QueryCallbackNew()
{
    DestroyActiveMember(*this);
}

QueryCallbackNew&& QueryCallbackNew::WithCallback(std::function<void(QueryResult)>&& callback)
{
    ASSERT(!_callbacks.empty() || !_isPrepared, "Attempted to set callback function for string query on a prepared async query");
    _callbacks.emplace(std::move(callback));
    return std::move(*this);
}

QueryCallbackNew&& QueryCallbackNew::WithPreparedCallback(std::function<void(PreparedQueryResult)>&& callback)
{
    ASSERT(!_callbacks.empty() || _isPrepared, "Attempted to set callback function for prepared query on a string async query");
    _callbacks.emplace(std::move(callback));
    return std::move(*this);
}

QueryCallbackNew::Status QueryCallbackNew::InvokeIfReady()
{
    QueryCallbackData& callback = _callbacks.front();
    if (!_isPrepared)
    {
        if (_string.valid() && _string.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        {
            std::function<void(QueryResult)> cb(std::move(callback._string));
            cb(_string.get());
            _callbacks.pop();
            if (_callbacks.empty())
            {
                ASSERT(!_isPrepared ? !_string.valid() : !_prepared.valid());
                return Completed;
            }

            ASSERT(_isPrepared == _callbacks.front()._isPrepared);
            return NextStep;
        }
    }
    else
    {
        if (_prepared.valid() && _prepared.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        {
            std::future<PreparedQueryResult> f(std::move(_prepared));
            std::function<void(PreparedQueryResult)> cb(std::move(callback._prepared));
            cb(_prepared.get());
            _callbacks.pop();
            if (_callbacks.empty())
            {
                ASSERT(!_isPrepared ? !_string.valid() : !_prepared.valid());
                return Completed;
            }

            ASSERT(_isPrepared == _callbacks.front()._isPrepared);
            return NextStep;
        }
    }

    return NotReady;
}
