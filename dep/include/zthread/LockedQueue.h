/*
 * Copyright (c) 2005, Eric Crahen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __ZTLOCKEDQUEUE_H__
#define __ZTLOCKEDQUEUE_H__

#include "zthread/Guard.h"
#include "zthread/Queue.h"

#include <deque>

namespace ZThread {

  /**
   * @class LockedQueue
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T11:42:33-0400>
   * @version 2.3.0
   *
   * A LockedQueue is the simple Queue implementation that provides
   * serialized access to the values added to it.
   */
  template <class T, class LockType, typename StorageType=std::deque<T> >
    class LockedQueue : public Queue<T> {

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
      virtual void add(const T& item) {

        Guard<LockType> g(_lock);

        if(_canceled)
          throw Cancellation_Exception();

        _queue.push_back(item);

      }

      /**
       * @see Queue::add(const T& item, unsigned long timeout)
       */
      virtual bool add(const T& item, unsigned long timeout) {

        try {

          Guard<LockType> g(_lock, timeout);

          if(_canceled)
            throw Cancellation_Exception();

          _queue.push_back(item);

        } catch(Timeout_Exception&) { return false; }

        return true;

      }

      /**
       * @see Queue::next()
       */
      virtual T next() {

        Guard<LockType> g(_lock);

        if(_queue.empty() && _canceled)
          throw Cancellation_Exception();

        if(_queue.empty())
          throw NoSuchElement_Exception();

        T item = _queue.front();
        _queue.pop_front();

        return item;

      }


      /**
       * @see Queue::next(unsigned long timeout)
       */
      virtual T next(unsigned long timeout) {

        Guard<LockType> g(_lock, timeout);

        if(_queue.empty() && _canceled)
          throw Cancellation_Exception();

        if(_queue.empty())
          throw NoSuchElement_Exception();

        T item = _queue.front();
        _queue.pop_front();

        return item;

      }

      virtual T front()
      {
          Guard<LockType> g(_lock);

          if(_queue.empty())
              throw NoSuchElement_Exception();

          return _queue.front();
      }

      /**
       * @see Queue::cancel()
       */
      virtual void cancel() {

        Guard<LockType> g(_lock);

        _canceled = true;

      }

      /**
       * @see Queue::isCanceled()
       */
      virtual bool isCanceled() {

        // Faster check since the queue will not become un-canceled
        if(_canceled)
          return true;

        Guard<LockType> g(_lock);

        return _canceled;

      }

      /**
       * @see Queue::size()
       */
      virtual size_t size() {

        Guard<LockType> g(_lock);
        return _queue.size();

      }

      /**
       * @see Queue::size(unsigned long timeout)
       */
      virtual size_t size(unsigned long timeout) {

        Guard<LockType> g(_lock, timeout);
        return _queue.size();

      }

    }; /* LockedQueue */

} // namespace ZThread

#endif // __ZTLOCKEDQUEUE_H__

