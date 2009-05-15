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

        //! Serialize access to the Queue
        LockType _lock;

        //! Storage backing the queue
        StorageType _queue;

        //! Cancellation flag
        volatile bool _canceled;

        public:

            //! Create a LockedQueue
            LockedQueue() : _canceled(false) {}

            //! Destroy a LockedQueue
            virtual ~LockedQueue() { }

            /**
             * @see Queue::add(const T& item)
             */
            void add(const T& item)
            {

                ACE_Guard<LockType> g(_lock);

                ASSERT(!_canceled);
                //	throw Cancellation_Exception();

                _queue.push_back(item);

            }

            /**
             * @see Queue::next()
             */
            T next()
            {

                ACE_Guard<LockType> g(_lock);

                ASSERT (!_queue.empty() || !_canceled);
                //	throw Cancellation_Exception();

                T item = _queue.front();
                _queue.pop_front();

                return item;

            }

            T front()
            {
                ACE_Guard<LockType> g(_lock);

                ASSERT (!_queue.empty());
                //	throw NoSuchElement_Exception();

                return _queue.front();
            }

            /**
             * @see Queue::cancel()
             */
            void cancel()
            {

                ACE_Guard<LockType> g(_lock);

                _canceled = true;

            }

            /**
             * @see Queue::isCanceled()
             */
            bool isCanceled()
            {

                // Faster check since the queue will not become un-canceled
                if(_canceled)
                    return true;

                ACE_Guard<LockType> g(_lock);

                return _canceled;

            }

            /**
             * @see Queue::size()
             */
            size_t size()
            {

                ACE_Guard<LockType> g(_lock);
                return _queue.size();

            }

            bool empty()
            {

                ACE_Guard<LockType> g(_lock);
                return _queue.empty();
            }

    };

}
#endif
