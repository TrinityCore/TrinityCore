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

QueryCallbackNew::QueryCallbackNew(std::future<QueryResult>&& result) : _string(std::move(result)), _isPrepared(false)
{
}

QueryCallbackNew::QueryCallbackNew(std::future<PreparedQueryResult>&& result) : _prepared(std::move(result)), _isPrepared(true)
{
}

QueryCallbackNew::QueryCallbackNew(QueryCallbackNew&& right)
{
    MoveFrom(std::move(right));
}

QueryCallbackNew& QueryCallbackNew::operator=(QueryCallbackNew&& right)
{
    MoveFrom(std::move(right));
    return *this;
}

QueryCallbackNew::~QueryCallbackNew()
{
    DestroyCurrentMember();
}

QueryCallbackNew&& QueryCallbackNew::WithCallback(std::function<void(QueryResult)>&& callback)
{
    ASSERT(!_isPrepared, "Attempted to set callback function for string query on a prepared async query");
    _string.Callback = std::move(callback);
    return std::move(*this);
}

QueryCallbackNew&& QueryCallbackNew::WithPreparedCallback(std::function<void(PreparedQueryResult)>&& callback)
{
    ASSERT(_isPrepared, "Attempted to set callback function for prepared query on a string async query");
    _prepared.Callback = std::move(callback);
    return std::move(*this);
}

QueryCallbackNew::Status QueryCallbackNew::InvokeIfReady()
{
    if (!_isPrepared)
    {
        if (_string.Result.valid() && _string.Result.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        {
            std::function<void(QueryResult)> cb(std::move(_string.Callback));
            cb(_string.Result.get());
            return !_string.Callback ? Completed : NextStep;
        }
    }
    else
    {
        if (_prepared.Result.valid() && _prepared.Result.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        {
            std::function<void(PreparedQueryResult)> cb(std::move(_prepared.Callback));
            cb(_prepared.Result.get());
            return !_prepared.Callback ? Completed : NextStep;
        }
    }

    return NotReady;
}

void QueryCallbackNew::MoveFrom(QueryCallbackNew&& other)
{
    DestroyCurrentMember();
    _isPrepared = other._isPrepared;
    if (!_isPrepared)
        _string = std::move(other._string);
    else
        _prepared = std::move(other._prepared);
}

void QueryCallbackNew::DestroyCurrentMember()
{
    if (!_isPrepared)
        _string.~String();
    else
        _prepared.~Prepared();
}
