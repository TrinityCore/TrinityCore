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

#ifndef TRINITYCORE_ASYNC_CALLBACK_PROCESSOR_H
#define TRINITYCORE_ASYNC_CALLBACK_PROCESSOR_H

#include "AsyncCallbackProcessorFwd.h"
#include <vector>

template<AsyncCallback T>
class AsyncCallbackProcessor
{
public:
    AsyncCallbackProcessor() = default;
    ~AsyncCallbackProcessor() = default;

    T& AddCallback(T&& query)
    {
        return _callbacks.emplace_back(std::move(query));
    }

    void ProcessReadyCallbacks()
    {
        if (_callbacks.empty())
            return;

        std::vector<T> updateCallbacks{ std::move(_callbacks) };

        std::erase_if(updateCallbacks, [](T& callback)
        {
            return InvokeAsyncCallbackIfReady(callback);
        });

        _callbacks.insert(_callbacks.end(), std::make_move_iterator(updateCallbacks.begin()), std::make_move_iterator(updateCallbacks.end()));
    }

    bool Empty() const
    {
        return _callbacks.empty();
    }

    void CancelAll()
    {
        _callbacks.clear();
    }

private:
    AsyncCallbackProcessor(AsyncCallbackProcessor const&) = delete;
    AsyncCallbackProcessor& operator=(AsyncCallbackProcessor const&) = delete;

    std::vector<T> _callbacks;
};

#endif // TRINITYCORE_ASYNC_CALLBACK_PROCESSOR_H
