/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2008 MaNGOS <http://getmangos.com/>
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

#ifndef LOCKEDQUEUE_H
#define LOCKEDQUEUE_H

#include <deque>
#include <mutex>



template <class T, typename StorageType = std::deque<T> >
class LockedQueue
{
    //! Lock access to the queue.
    std::mutex _lock;

    //! Storage backing the queue.
    StorageType _queue;

    //! Cancellation flag.
    volatile bool _canceled;

public:

    //! Create a LockedQueue.
    LockedQueue()
        : _canceled(false)
    {
    }

    //! Destroy a LockedQueue.
    virtual ~LockedQueue()
    {
    }

    //! Adds an item to the queue.
    void add(const T& item)
    {
        lock();

        _queue.push_back(item);

        unlock();
    }

    //! Gets the next result in the queue, if any.
    bool next(T& result)
    {
        std::lock_guard<std::mutex> lock(_lock);

        if (_queue.empty())
            return false;

        result = _queue.front();
        _queue.pop_front();

        return true;
    }

    template<class Checker>
    bool next(T& result, Checker& check)
    {
        std::lock_guard<std::mutex> lock(_lock);

        if (_queue.empty())
            return false;

        result = _queue.front();
        if (!check.Process(result))
            return false;

        _queue.pop_front();
        return true;
    }

    //! Peeks at the top of the queue. Check if the queue is empty before calling! Remember to unlock after use if autoUnlock == false.
    T& peek(bool autoUnlock = false)
    {
        lock();

        T& result = _queue.front();

        if (autoUnlock)
            unlock();

        return result;
    }

    //! Cancels the queue.
    void cancel()
    {
        lock();

        _canceled = true;

        unlock();
    }

    //! Checks if the queue is cancelled.
    bool cancelled()
    {
        ACE_Guard<LockType> g(this->_lock);
        return _canceled;
    }

    //! Locks the queue for access.
    void lock()
    {
        this->_lock.lock();
    }

    //! Unlocks the queue.
    void unlock()
    {
        this->_lock.unlock();
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
