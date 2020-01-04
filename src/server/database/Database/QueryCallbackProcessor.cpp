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

#include "QueryCallbackProcessor.h"
#include "QueryCallback.h"
#include <algorithm>

QueryCallbackProcessor::QueryCallbackProcessor()
{
}

QueryCallbackProcessor::~QueryCallbackProcessor()
{
}

void QueryCallbackProcessor::AddQuery(QueryCallback&& query)
{
    _callbacks.emplace_back(std::move(query));
}

void QueryCallbackProcessor::ProcessReadyQueries()
{
    if (_callbacks.empty())
        return;

    std::vector<QueryCallback> updateCallbacks{ std::move(_callbacks) };

    updateCallbacks.erase(std::remove_if(updateCallbacks.begin(), updateCallbacks.end(), [](QueryCallback& callback)
    {
        return callback.InvokeIfReady() == QueryCallback::Completed;
    }), updateCallbacks.end());

    _callbacks.insert(_callbacks.end(), std::make_move_iterator(updateCallbacks.begin()), std::make_move_iterator(updateCallbacks.end()));
}
