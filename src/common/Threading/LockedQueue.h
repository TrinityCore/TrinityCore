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

#ifndef TRINITYCORE_LOCKED_QUEUE_H
#define TRINITYCORE_LOCKED_QUEUE_H

#include "Concepts.h"
#include <deque>
#include <mutex>

template <class T, typename StorageType = std::deque<T>>
class LockedQueue
{
    //! Lock access to the queue.
    std::mutex _lock;

    //! Storage backing the queue.
    StorageType _queue;

    //! Cancellation flag.
    bool _canceled = false;

public:

    //! Adds an item to the queue.
    void add(T const& item)
    {
        std::lock_guard<std::mutex> lock(_lock);
        _queue.push_back(item);
    }

    //! Adds an item to the queue.
    void add(T&& item)
    {
        std::lock_guard<std::mutex> lock(_lock);
        _queue.push_back(std::move(item));
    }

    //! Adds items back to front of the queue
    template<std::input_iterator Iterator>
    void readd(Iterator begin, Iterator end)
    {
        std::lock_guard<std::mutex> lock(_lock);
        _queue.insert(_queue.begin(), begin, end);
    }

    //! Gets the next result in the queue, if any.
    bool next(T& result)
    {
        std::lock_guard<std::mutex> lock(_lock);
        if (_queue.empty())
            return false;

        result = std::move(_queue.front());
        _queue.pop_front();
        return true;
    }

    template<class Checker>
    bool next(T& result, Checker& check)
    {
        std::lock_guard<std::mutex> lock(_lock);
        if (_queue.empty())
            return false;

        decltype(auto) front = _queue.front();
        if (!check.Process(front))
            return false;

        result = std::move(front);
        _queue.pop_front();
        return true;
    }

    //! Cancels the queue.
    void cancel()
    {
        std::lock_guard<std::mutex> lock(_lock);
        _canceled = true;
    }

    //! Checks if the queue is cancelled.
    bool cancelled()
    {
        std::lock_guard<std::mutex> lock(_lock);
        return _canceled;
    }

    ///! Calls pop_front of the queue
    void pop_front()
    {
        std::lock_guard<std::mutex> lock(_lock);
        _queue.pop_front();
    }

    ///! Checks if we're empty or not with locks held
    bool empty()
    {
        std::lock_guard<std::mutex> lock(_lock);
        return _queue.empty();
    }
};
#endif
