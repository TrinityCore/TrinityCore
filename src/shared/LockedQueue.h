/*
 * Copyright (C) 2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef LOCKEDQUEUE_H
#define LOCKEDQUEUE_H
#include <ace/Guard_T.h>
#include <ace/Thread_Mutex.h>
#include <deque>
#include <assert.h>
#include "Errors.h"
namespace ACE_Based
{
    template <class T, class LockType, typename StorageType=std::deque<T> >
        class LockedQueue
    {
        //! Lock access to the queue.
        LockType _lock;
        //! Storage backing the queue.
        StorageType _queue;
        //! Cancellation flag.
        volatile bool _canceled;
        public:
            //! Create a LockedQueue.
            LockedQueue() : _canceled(false) {}
            //! Destroy a LockedQueue.
            virtual ~LockedQueue() { }
            //! Adds an item to the queue.
            void add(const T& item)
            {
                ACE_Guard<LockType> g(this->_lock);
                //ASSERT(!this->_canceled);
                // throw Cancellation_Exception();
                _queue.push_back(item);
            }
            //! Gets the next result in the queue, if any.
            bool next(T& result)
            {
                ACE_Guard<LockType> g(this->_lock);
                if (_queue.empty())
                    return false;
                //ASSERT (!_queue.empty() || !this->_canceled);
                // throw Cancellation_Exception();
                result = _queue.front();
                _queue.pop_front();
                return true;
            }
            //! Cancels the queue.
            void cancel()
            {
                ACE_Guard<LockType> g(this->_lock);
                _canceled = true;
            }
            //! Checks if the queue is cancelled.
            bool cancelled()
            {
                ACE_Guard<LockType> g(this->_lock);
                return _canceled;
            }
    };
}
#endif
