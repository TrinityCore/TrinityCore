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

#ifndef TRINITY_PRODUCER_CONSUMER_QUEUE_H
#define TRINITY_PRODUCER_CONSUMER_QUEUE_H

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <type_traits>

template <typename T>
class ProducerConsumerQueue
{
private:
    mutable std::mutex _queueLock;
    std::queue<T> _queue;
    std::condition_variable _condition;
    std::atomic<bool> _shutdown;

public:

    ProducerConsumerQueue() : _shutdown(false) { }

    void Push(T const& value)
    {
        std::scoped_lock lock(_queueLock);
        _queue.push(value);

        _condition.notify_one();
    }

    void Push(T&& value)
    {
        std::scoped_lock lock(_queueLock);
        _queue.push(std::move(value));

        _condition.notify_one();
    }

    bool Empty() const
    {
        std::scoped_lock lock(_queueLock);

        return _queue.empty();
    }

    size_t Size() const
    {
        std::scoped_lock lock(_queueLock);

        return _queue.size();
    }

    bool Pop(T& value)
    {
        std::scoped_lock lock(_queueLock);

        if (_queue.empty() || _shutdown)
            return false;

        value = std::move(_queue.front());

        _queue.pop();

        return true;
    }

    void WaitAndPop(T& value)
    {
        std::unique_lock lock(_queueLock);

        _condition.wait(lock, [&] { return !_queue.empty() || _shutdown; });

        if (_queue.empty() || _shutdown)
            return;

        value = _queue.front();

        _queue.pop();
    }

    void Cancel()
    {
        std::scoped_lock lock(_queueLock);

        while (!_queue.empty())
        {
            T& value = _queue.front();

            if constexpr (std::is_pointer_v<T>)
                delete value;

            _queue.pop();
        }

        _shutdown = true;

        _condition.notify_all();
    }
};

#endif // TRINITY_PRODUCER_CONSUMER_QUEUE_H
