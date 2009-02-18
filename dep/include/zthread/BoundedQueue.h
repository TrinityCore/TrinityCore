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

#ifndef __ZTBOUNDEDQUEUE_H__
#define __ZTBOUNDEDQUEUE_H__

#include "zthread/Condition.h"
#include "zthread/Guard.h"
#include "zthread/Queue.h"

#include <deque>

namespace ZThread {

  /**
   * @class BoundedQueue
   *
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T13:54:04-0400>
   * @version 2.3.0
   *
   * A BoundedQueue provides serialized access to a set of values. It differs from other
   * Queues by adding a maximum capacity, giving it the following properties:
   *
   * - Threads calling the empty() methods will be blocked until the BoundedQueue becomes empty.
   * - Threads calling the next() methods will be blocked until the BoundedQueue has a value to
   *   return.
   * - Threads calling the add() methods will be blocked until the number of values in the
   *   Queue drops below the maximum capacity.
   *
   * @see Queue
   */
  template <class T, class LockType, typename StorageType=std::deque<T> >
    class BoundedQueue : public Queue<T>, public Lockable {

      //! Maximum capacity for the Queue
      size_t _capacity;

      //! Serialize access
      LockType _lock;

      //! Signaled if not full
      Condition _notFull;

      //! Signaled if not empty
      Condition _notEmpty;

      //! Signaled if empty
      Condition _isEmpty;

      //! Storage backing the queue
      StorageType _queue;

      //! Cancellation flag
      volatile bool _canceled;

      public:

      /**
       * Create a BoundedQueue with the given capacity.
       *
       * @param capacity maximum number of values to allow in the Queue at
       *        at any time
       */
      BoundedQueue(size_t capacity)
        : _notFull(_lock), _notEmpty(_lock), _isEmpty(_lock),
          _capacity(capacity), _canceled(false) {}

      //! Destroy this Queue
      virtual ~BoundedQueue() { }

      /**
       * Get the maximum capacity of this Queue.
       *
       * @return <i>size_t</i> maximum capacity
       */
      size_t capacity() {
        return _capacity;
      }

      /**
       * Add a value to this Queue.
       *
       * If the number of values in the queue matches the value returned by <i>capacity</i>()
       * then the calling thread will be blocked until at least one value is removed from
       * the Queue.
       *
       * @param item value to be added to the Queue
       *
       * @exception Cancellation_Exception thrown if this Queue has been canceled.
       * @exception Interrupted_Exception thrown if the thread was interrupted while waiting
       *            to add a value
       *
       * @pre  The Queue should not have been canceled prior to the invocation of this function.
       * @post If no exception is thrown, a copy of <i>item</i> will have been added to the Queue.
       *
       * @see Queue::add(const T& item)
       */
      virtual void add(const T& item) {

        Guard<LockType> g(_lock);

        // Wait for the capacity of the Queue to drop
        while ((_queue.size() == _capacity) && !_canceled)
          _notFull.wait();

        if(_canceled)
          throw Cancellation_Exception();

        _queue.push_back(item);
        _notEmpty.signal(); // Wake any waiters


      }

      /**
       * Add a value to this Queue.
       *
       * If the number of values in the queue matches the value returned by <i>capacity</i>()
       * then the calling thread will be blocked until at least one value is removed from
       * the Queue.
       *
       * @param item value to be added to the Queue
       * @param timeout maximum amount of time (milliseconds) this method may block
       *        the calling thread.
       *
       * @return
       *   - <em>true</em> if a copy of <i>item</i> can be added before <i>timeout</i>
       *     milliseconds elapse.
       *   - <em>false</em> otherwise.
       *
       * @exception Cancellation_Exception thrown if this Queue has been canceled.
       * @exception Interrupted_Exception thrown if the thread was interrupted while waiting
       *            to add a value
       *
       * @pre  The Queue should not have been canceled prior to the invocation of this function.
       * @post If no exception is thrown, a copy of <i>item</i> will have been added to the Queue.
       *
       * @see Queue::add(const T& item, unsigned long timeout)
       */
      virtual bool add(const T& item, unsigned long timeout) {

        try {

          Guard<LockType> g(_lock, timeout);

          // Wait for the capacity of the Queue to drop
          while ((_queue.size() == _capacity) && !_canceled)
            if(!_notFull.wait(timeout))
              return false;

          if(_canceled)
            throw Cancellation_Exception();

          _queue.push_back(item);
          _notEmpty.signal(); // Wake any waiters

        } catch(Timeout_Exception&) { return false; }

        return true;

      }

      /**
       * Retrieve and remove a value from this Queue.
       *
       * If invoked when there are no values present to return then the calling thread
       * will be blocked until a value arrives in the Queue.
       *
       * @return <em>T</em> next available value
       *
       * @exception Cancellation_Exception thrown if this Queue has been canceled.
       * @exception Interrupted_Exception thrown if the thread was interrupted while waiting
       *            to retrieve a value
       *
       * @pre  The Queue should not have been canceled prior to the invocation of this function.
       * @post The value returned will have been removed from the Queue.
       */
      virtual T next() {

        Guard<LockType> g(_lock);

        while ( _queue.empty() && !_canceled)
          _notEmpty.wait();

        if( _queue.empty()) // Queue canceled
          throw Cancellation_Exception();

        T item = _queue.front();
        _queue.pop_front();

        _notFull.signal(); // Wake any thread trying to add

        if(_queue.empty()) // Wake empty waiters
          _isEmpty.broadcast();

        return item;

      }

      /**
       * Retrieve and remove a value from this Queue.
       *
       * If invoked when there are no values present to return then the calling thread
       * will be blocked until a value arrives in the Queue.
       *
       * @param timeout maximum amount of time (milliseconds) this method may block
       *        the calling thread.
       *
       * @return <em>T</em> next available value
       *
       * @exception Cancellation_Exception thrown if this Queue has been canceled.
       * @exception Timeout_Exception thrown if the timeout expires before a value
       *            can be retrieved.
       *
       * @pre  The Queue should not have been canceled prior to the invocation of this function.
       * @post The value returned will have been removed from the Queue.
       */
      virtual T next(unsigned long timeout) {

        Guard<LockType> g(_lock, timeout);

        // Wait for items to be added
        while (_queue.empty() && !_canceled) {
          if(!_notEmpty.wait(timeout))
            throw Timeout_Exception();
        }

        if(_queue.empty())  // Queue canceled
          throw Cancellation_Exception();

        T item = _queue.front();
        _queue.pop_front();

        _notFull.signal(); // Wake add() waiters

        if(_queue.empty()) // Wake empty() waiters
          _isEmpty.broadcast();

        return item;

      }

      /**
       * Cancel this queue.
       *
       * @post Any threads blocked by an add() function will throw a Cancellation_Exception.
       * @post Any threads blocked by a next() function will throw a Cancellation_Exception.
       *
       * @see Queue::cancel()
       */
      virtual void cancel() {

        Guard<LockType> g(_lock);

        _canceled = true;
        _notEmpty.broadcast(); // Wake next() waiters

      }

      /**
       * @see Queue::isCanceled()
       */
      virtual bool isCanceled() {

        // Faster check since the Queue will not become un-canceled
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

      /**
       * Test whether any values are available in this Queue.
       *
       * The calling thread is blocked until there are no values present
       * in the Queue.
       *
       * @return
       *  - <em>true</em> if there are no values available.
       *  - <em>false</em> if there <i>are</i> values available.
       *
       * @see Queue::empty()
       */
      virtual bool empty() {

        Guard<LockType> g(_lock);

        while(!_queue.empty()) // Wait for an empty signal
          _isEmpty.wait();

        return true;


      }


      /**
       * Test whether any values are available in this Queue.
       *
       * The calling thread is blocked until there are no values present
       * in the Queue.
       *
       * @param timeout maximum amount of time (milliseconds) this method may block
       *        the calling thread.
       *
       * @return
       *  - <em>true</em> if there are no values available.
       *  - <em>false</em> if there <i>are</i> values available.
       *
       * @exception Timeout_Exception thrown if <i>timeout</i> milliseconds
       *            expire before a value becomes available
       *
       * @see Queue::empty()
       */
      virtual bool empty(unsigned long timeout) {

        Guard<LockType> g(_lock, timeout);

        while(!_queue.empty()) // Wait for an empty signal
          _isEmpty.wait(timeout);

        return true;

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

    }; /* BoundedQueue */

} // namespace ZThread

#endif // __ZTBOUNDEDQUEUE_H__

