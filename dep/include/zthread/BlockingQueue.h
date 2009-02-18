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

#ifndef __ZTBLOCKINGQUEUE_H__
#define __ZTBLOCKINGQUEUE_H__

#include "zthread/Guard.h"
#include "zthread/Condition.h"
#include "zthread/Queue.h"

#include <deque>

namespace ZThread {

  /**
   * @class BlockingQueue
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T12:01:43-0400>
   * @version 2.3.0
   *
   * Like a LockedQueue, a BlockingQueue is a Queue implementation that provides
   * serialized access to the items added to it. It differs by causing threads
   * accessing the next() methods to block until a value becomes available.
   */
  template <class T, class LockType, typename StorageType = std::deque<T> >
    class BlockingQueue : public Queue<T>, public Lockable {

      //! Serialize access
      LockType _lock;

      //! Signaled when empty
      Condition _notEmpty;

      //! Storage backing the queue
      StorageType _queue;

      //! Cancellation flag
      volatile bool _canceled;

      public:

      //! Create a new BlockingQueue
      BlockingQueue() : _notEmpty(_lock), _canceled(false) {}

      //! Destroy this BlockingQueue
      virtual ~BlockingQueue() { }

      /**
       * @see Queue::add(const T& item)
       */
      virtual void add(const T& item) {

        Guard<LockType> g(_lock);

        if(_canceled)
          throw Cancellation_Exception();

        _queue.push_back(item);

        _notEmpty.signal();

      }

      /**
       * @see Queue::add(const T& item, unsigned long timeout)
       */
      virtual bool add(T item, unsigned long timeout) {

        try {

          Guard<LockType> g(_lock, timeout);

          if(_canceled)
            throw Cancellation_Exception();

          _queue.push_back(item);

          _notEmpty.signal();

        } catch(Timeout_Exception&) { return false; }

        return true;

      }

      /**
       * Get a value from this Queue. The calling thread may block indefinitely.
       *
       * @return <em>T</em> next available value
       *
       * @exception Cancellation_Exception thrown if this Queue has been canceled.
       *
       * @exception Interrupted_Exception thrown if the calling thread is interrupted
       *            before a value becomes available.
       *
       * @pre  The Queue should not have been canceled prior to the invocation of this function.
       * @post The value returned will have been removed from the Queue.
       *
       * @see Queue::next()
       */
      virtual T next() {

        Guard<LockType> g(_lock);

        while(_queue.empty() && !_canceled)
          _notEmpty.wait();

        if( _queue.empty() )
          throw Cancellation_Exception();

        T item = _queue.front();
        _queue.pop_front();

        return item;

      }


      /**
       * Get a value from this Queue. The calling thread may block indefinitely.
       *
       * @param timeout maximum amount of time (milliseconds) this method may block
       *        the calling thread.
       *
       * @return <em>T</em> next available value
       *
       * @exception Cancellation_Exception thrown if this Queue has been canceled.
       * @exception Timeout_Exception thrown if the timeout expires before a value
       *            can be retrieved.
       * @exception Interrupted_Exception thrown if the calling thread is interrupted
       *            before a value becomes available.
       *
       * @pre  The Queue should not have been canceled prior to the invocation of this function.
       * @post The value returned will have been removed from the Queue.
       *
       * @see Queue::next(unsigned long timeout)
       */
      virtual T next(unsigned long timeout) {

        Guard<LockType> g(_lock, timeout);

        while(_queue.empty() && !_canceled) {
          if(!_notEmpty.wait(timeout))
            throw Timeout_Exception();
        }

        if(_queue.empty() )
          throw Cancellation_Exception();

        T item = _queue.front();
        _queue.pop_front();

        return item;

      }


      /**
       * @see Queue::cancel()
       *
       * @post If threads are blocked on one of the next() functions then
       *       they will be awakened with a Cancellation_Exception.
       */
      virtual void cancel() {

        Guard<LockType> g(_lock);

        _notEmpty.broadcast();
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

      public:

      virtual void acquire() {
        _lock.acquire();
      }

      virtual bool tryAcquire(unsigned long timeout) {
        return _lock.tryAcquire(timeout);
      }

      virtual void release() {
        _lock.release();
      }

    }; /* BlockingQueue */

} // namespace ZThread

#endif // __ZTBLOCKINGQUEUE_H__

