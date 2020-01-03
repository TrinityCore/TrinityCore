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
#include "Errors.h"

template<typename T, typename... Args>
inline void Construct(T& t, Args&&... args)
{
    new (&t) T(std::forward<Args>(args)...);
}

template<typename T>
inline void Destroy(T& t)
{
    t.~T();
}

template<typename T>
inline void ConstructActiveMember(T* obj)
{
    if (!obj->_isPrepared)
        Construct(obj->_string);
    else
        Construct(obj->_prepared);
}

template<typename T>
inline void DestroyActiveMember(T* obj)
{
    if (!obj->_isPrepared)
        Destroy(obj->_string);
    else
        Destroy(obj->_prepared);
}

template<typename T>
inline void MoveFrom(T* to, T&& from)
{
    ASSERT(to->_isPrepared == from._isPrepared);

    if (!to->_isPrepared)
        to->_string = std::move(from._string);
    else
        to->_prepared = std::move(from._prepared);
}

struct QueryCallback::QueryCallbackData
{
public:
    friend class QueryCallback;

    QueryCallbackData(std::function<void(QueryCallback&, QueryResult)>&& callback) : _string(std::move(callback)), _isPrepared(false) { }
    QueryCallbackData(std::function<void(QueryCallback&, PreparedQueryResult)>&& callback) : _prepared(std::move(callback)), _isPrepared(true) { }
    QueryCallbackData(QueryCallbackData&& right)
    {
        _isPrepared = right._isPrepared;
        ConstructActiveMember(this);
        MoveFrom(this, std::move(right));
    }
    QueryCallbackData& operator=(QueryCallbackData&& right)
    {
        if (this != &right)
        {
            if (_isPrepared != right._isPrepared)
            {
                DestroyActiveMember(this);
                _isPrepared = right._isPrepared;
                ConstructActiveMember(this);
            }
            MoveFrom(this, std::move(right));
        }
        return *this;
    }
    ~QueryCallbackData() { DestroyActiveMember(this); }

private:
    QueryCallbackData(QueryCallbackData const&) = delete;
    QueryCallbackData& operator=(QueryCallbackData const&) = delete;

    template<typename T> friend void ConstructActiveMember(T* obj);
    template<typename T> friend void DestroyActiveMember(T* obj);
    template<typename T> friend void MoveFrom(T* to, T&& from);

    union
    {
        std::function<void(QueryCallback&, QueryResult)> _string;
        std::function<void(QueryCallback&, PreparedQueryResult)> _prepared;
    };
    bool _isPrepared;
};

// Not using initialization lists to work around segmentation faults when compiling with clang without precompiled headers
QueryCallback::QueryCallback(std::future<QueryResult>&& result)
{
    _isPrepared = false;
    Construct(_string, std::move(result));
}

QueryCallback::QueryCallback(std::future<PreparedQueryResult>&& result)
{
    _isPrepared = true;
    Construct(_prepared, std::move(result));
}

QueryCallback::QueryCallback(QueryCallback&& right)
{
    _isPrepared = right._isPrepared;
    ConstructActiveMember(this);
    MoveFrom(this, std::move(right));
    _callbacks = std::move(right._callbacks);
}

QueryCallback& QueryCallback::operator=(QueryCallback&& right)
{
    if (this != &right)
    {
        if (_isPrepared != right._isPrepared)
        {
            DestroyActiveMember(this);
            _isPrepared = right._isPrepared;
            ConstructActiveMember(this);
        }
        MoveFrom(this, std::move(right));
        _callbacks = std::move(right._callbacks);
    }
    return *this;
}

QueryCallback::~QueryCallback()
{
    DestroyActiveMember(this);
}

QueryCallback&& QueryCallback::WithCallback(std::function<void(QueryResult)>&& callback)
{
    return WithChainingCallback([callback](QueryCallback& /*this*/, QueryResult result) { callback(std::move(result)); });
}

QueryCallback&& QueryCallback::WithPreparedCallback(std::function<void(PreparedQueryResult)>&& callback)
{
    return WithChainingPreparedCallback([callback](QueryCallback& /*this*/, PreparedQueryResult result) { callback(std::move(result)); });
}

QueryCallback&& QueryCallback::WithChainingCallback(std::function<void(QueryCallback&, QueryResult)>&& callback)
{
    ASSERT(!_callbacks.empty() || !_isPrepared, "Attempted to set callback function for string query on a prepared async query");
    _callbacks.emplace(std::move(callback));
    return std::move(*this);
}

QueryCallback&& QueryCallback::WithChainingPreparedCallback(std::function<void(QueryCallback&, PreparedQueryResult)>&& callback)
{
    ASSERT(!_callbacks.empty() || _isPrepared, "Attempted to set callback function for prepared query on a string async query");
    _callbacks.emplace(std::move(callback));
    return std::move(*this);
}

void QueryCallback::SetNextQuery(QueryCallback&& next)
{
    MoveFrom(this, std::move(next));
}

QueryCallback::Status QueryCallback::InvokeIfReady()
{
    QueryCallbackData& callback = _callbacks.front();
    auto checkStateAndReturnCompletion = [this]()
    {
        _callbacks.pop();
        bool hasNext = !_isPrepared ? _string.valid() : _prepared.valid();
        if (_callbacks.empty())
        {
            ASSERT(!hasNext);
            return Completed;
        }

        // abort chain
        if (!hasNext)
            return Completed;

        ASSERT(_isPrepared == _callbacks.front()._isPrepared);
        return NextStep;
    };

    if (!_isPrepared)
    {
        if (_string.valid() && _string.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        {
            QueryResultFuture f(std::move(_string));
            std::function<void(QueryCallback&, QueryResult)> cb(std::move(callback._string));
            cb(*this, f.get());
            return checkStateAndReturnCompletion();
        }
    }
    else
    {
        if (_prepared.valid() && _prepared.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        {
            PreparedQueryResultFuture f(std::move(_prepared));
            std::function<void(QueryCallback&, PreparedQueryResult)> cb(std::move(callback._prepared));
            cb(*this, f.get());
            return checkStateAndReturnCompletion();
        }
    }

    return NotReady;
}
