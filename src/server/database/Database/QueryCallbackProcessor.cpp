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

#include "QueryCallbackProcessor.h"
#include "QueryCallback.h"
#include <algorithm>

QueryCallbackProcessor::QueryCallbackProcessor()
{
}

QueryCallbackProcessor::~QueryCallbackProcessor()
{
}

void QueryCallbackProcessor::AddQuery(QueryCallbackNew&& query)
{
    _callbacks.emplace_back(std::move(query));
}

void QueryCallbackProcessor::ProcessReadyQueries()
{
    _callbacks.erase(std::remove_if(_callbacks.begin(), _callbacks.end(), [](QueryCallbackNew& callback)
    {
        return callback.InvokeIfReady() == QueryCallbackNew::Completed;
    }), _callbacks.end());
}
