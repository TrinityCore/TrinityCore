/*
* Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _PCQ_H
#define _PCQ_H

#include <condition_variable>
#include <mutex>
#include <queue>
#include <atomic>

template <typename T>
class ProducerConsumerQueue
{
    static_assert(std::is_pointer<T>::value, "T for ProducerConsumerQueue must be a pointer");

private:
    std::mutex _queueLock;
    std::queue<T> _queue;
    std::condition_variable _condition;
    std::atomic<bool> _shutdown;

public:

    ProducerConsumerQueue<T>() : _shutdown(false) { }

    void Push(const T& value)
    {
        {
            std::lock_guard<std::mutex> lock(_queueLock);
            _queue.push(std::move(value));
        }

        _condition.notify_one();
    }

    bool Empty()
    {
        std::lock_guard<std::mutex> lock(_queueLock);

        return _queue.empty();
    }

    bool Pop(T& value)
    {
        std::lock_guard<std::mutex> lock(_queueLock);

        if (_queue.empty())
            return false;

        value = _queue.front();

        _queue.pop();

        return true;
    }

    void WaitAndPop(T& value)
    {
        std::unique_lock<std::mutex> lock(_queueLock);

        while (_queue.empty() && !_shutdown)
        {
            _condition.wait(lock);
        }

        if (_queue.empty())
            return;

        value = _queue.front();

        _queue.pop();
    }

    void Cancel()
    {
        _queueLock.lock();

        while (!_queue.empty())
        {
            T& value = _queue.front();

            delete value;

            _queue.pop();
        }

        _shutdown = true;

        _queueLock.unlock();

        _condition.notify_all();
    }
};

#endif


