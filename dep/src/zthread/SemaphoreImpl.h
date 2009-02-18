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

#ifndef __ZTSEMAPHOREIMPL_H__
#define __ZTSEMAPHOREIMPL_H__

#include "zthread/Guard.h"

#include "Debug.h"
#include "FastLock.h"
#include "Scheduling.h"

#include <assert.h>

namespace ZThread {

  class Monitor;

  /**
   * @class SemaphoreImpl
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T20:03:20-0400>
   * @version 2.2.11
   *
   * The SemaphoreImpl template allows how waiter lists are sorted
   * to be parameteized
   */
  template <typename List>
    class SemaphoreImpl {

    //! List of waiting events
    List _waiters;

    //! Serialize access to this object
    FastLock _lock;

    //! Current count
    volatile int _count;

    //! Maximum count if any
    volatile int _maxCount;

    //! Flag for bounded or unbounded count
    volatile bool _checked;

    //! Entry count
    volatile int _entryCount;

    public:


    /**
     * Create a new SemaphoreImpl. Initialzes one pthreads mutex for
     * internal use.
     *
     * @exception Initialization_Exception thrown if resources could not be
     * properly allocated
     */
    SemaphoreImpl(int count, unsigned int maxCount, bool checked)
      : _count(count), _maxCount(maxCount), _checked(checked), _entryCount(0) { }


    ~SemaphoreImpl();

    void acquire();

    void release();

    bool tryAcquire(unsigned long timeout);

    int count();

  };


  /**
   * Destroy this SemaphoreImpl and release its resources.
   */
  template <typename List>
    SemaphoreImpl<List>::~SemaphoreImpl() {

#ifndef NDEBUG

    if(!_waiters.empty()) {

      ZTDEBUG("** You are destroying a semaphore which is blocking %d threads. **\n", _waiters.size());
      assert(0); // Destroyed semaphore while in use

    }

#endif

  }


  /**
   * Get the count for the Semaphore
   *
   * @return int
   */
  template <typename List>
    int SemaphoreImpl<List>::count() {

    Guard<FastLock> g(_lock);
    return _count;

  }

  /**
   * Decrement the count, blocking when that count becomes 0 or less.
   *
   * @exception Interrupted_Exception thrown when the caller status is interrupted
   * @exception Synchronization_Exception thrown if there is some other error.
   */
  template <typename List>
    void SemaphoreImpl<List>::acquire() {

    // Get the monitor for the current thread
    ThreadImpl* self = ThreadImpl::current();
    Monitor& m = self->getMonitor();

    Monitor::STATE state;

    Guard<FastLock> g1(_lock);

    // Update the count without waiting if possible.
    if(_count > 0 && _entryCount == 0)
      _count--;

    // Otherwise, wait() for the lock by placing the waiter in the list
    else {

      ++_entryCount;
      _waiters.insert(self);

      m.acquire();

      {

        Guard<FastLock, UnlockedScope> g2(g1);
        state = m.wait();

      }

      m.release();

      // Remove from waiter list, regarless of weather release() is called or
      // not. The monitor is sticky, so its possible a state 'stuck' from a
      // previous operation and will leave the wait() w/o release() having
      // been called.
      typename List::iterator i = std::find(_waiters.begin(), _waiters.end(), self);
      if(i != _waiters.end())
        _waiters.erase(i);

      --_entryCount;

      switch(state) {
        // If awoke due to a notify(), update the count
        case Monitor::SIGNALED:

          _count--;
          break;

        case Monitor::INTERRUPTED:
          throw Interrupted_Exception();

        default:
          throw Synchronization_Exception();
      }

    }

  }

  /**
   * Decrement the count, blocking when it that count is 0 or less. If the timeout
   * expires before the count is raise above 0, the thread will stop blocking
   * and return.
   *
   * @exception Interrupted_Exception thrown when the caller status is interrupted
   * @exception Synchronization_Exception thrown if there is some other error.
   */
  template <typename List>
    bool SemaphoreImpl<List>::tryAcquire(unsigned long timeout) {

    // Get the monitor for the current thread
    ThreadImpl* self = ThreadImpl::current();
    Monitor& m = self->getMonitor();

    Guard<FastLock> g1(_lock);

    // Update the count without waiting if possible.
    if(_count > 0 && _entryCount == 0)
      _count--;

    // Otherwise, wait() for the lock by placing the waiter in the list
    else {

      ++_entryCount;
      _waiters.push_back(self);

      Monitor::STATE state = Monitor::TIMEDOUT;

      // Don't bother waiting if the timeout is 0
      if(timeout) {

        m.acquire();

        {

          Guard<FastLock, UnlockedScope> g2(g1);
          state = m.wait(timeout);

        }

        m.release();

      }

      // Remove from waiter list, regarless of weather release() is called or
      // not. The monitor is sticky, so its possible a state 'stuck' from a
      // previous operation and will leave the wait() w/o release() having
      // been called.
      typename List::iterator i = std::find(_waiters.begin(), _waiters.end(), self);
      if(i != _waiters.end())
        _waiters.erase(i);

      --_entryCount;

      switch(state) {
        // If awoke due to a notify(), update the count
        case Monitor::SIGNALED:

          _count--;
          break;

        case Monitor::INTERRUPTED:
          throw Interrupted_Exception();

        case Monitor::TIMEDOUT:
          return false;

        default:
          throw Synchronization_Exception();
      }

    }

    return true;

  }

  /**
   * Increment the count and release a waiter if there are any. If the semaphore
   * is checked, then an exception will be raised if the maximum count is about to
   * be exceeded.
   *
   * @exception InvalidOp_Exception thrown if the maximum count is exceeded while
   * the checked flag is set.
   */
  template <typename List>
    void SemaphoreImpl<List>::release()  {

    Guard<FastLock> g1(_lock);

    // Make sure the operation is valid
    if(_checked && _count == _maxCount)
      throw InvalidOp_Exception();

    // Increment the count
    _count++;

    // Try to find a waiter with a backoff & retry scheme
    for(;;) {

      // Go through the list, attempt to notify() a waiter.
      for(typename List::iterator i = _waiters.begin(); i != _waiters.end();) {

        // Try the monitor lock, if it cant be locked skip to the next waiter
        ThreadImpl* impl = *i;
        Monitor& m = impl->getMonitor();

        if(m.tryAcquire()) {

          // Notify the monitor & remove from the waiter list so time isn't
          // wasted checking it again.
          i = _waiters.erase(i);

          // If notify() is not sucessful, it is because the wait() has already
          // been ended (killed/interrupted/notify'd)
          bool woke = m.notify();

          m.release();

          // Once notify() succeeds, return
          if(woke)
            return;

        } else ++i;

      }

      if(_waiters.empty())
        return;

      { // Backoff and try again

        Guard<FastLock, UnlockedScope> g2(g1);
        ThreadImpl::yield();

      }

    }

  }

  class FifoSemaphoreImpl : public SemaphoreImpl<fifo_list> {
  public:

    FifoSemaphoreImpl(int count, unsigned int maxCount, bool checked)
      /* throw(Synchronization_Exception) */
      : SemaphoreImpl<fifo_list>(count, maxCount, checked) { }

  };


} // namespace ZThread

#endif //  __ZTSEMAPHOREIMPL_H__

