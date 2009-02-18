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

#ifndef __ZTCONDITIONIMPL_H__
#define __ZTCONDITIONIMPL_H__

#include "zthread/Guard.h"

#include "Debug.h"
#include "Scheduling.h"
#include "DeferredInterruptionScope.h"

namespace ZThread {

/**
 * @class ConditionImpl
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-18T08:15:37-0400>
 * @version 2.2.11
 *
 * The ConditionImpl template allows how waiter lists are sorted
 * to be parameteized
 */
template <typename List>
class ConditionImpl {

  //! Waiters currently blocked
  List _waiters;

  //! Serialize access to this object
  FastLock _lock;

  //! External lock
  Lockable& _predicateLock;

 public:

  /**
   * Create a new ConditionImpl.
   *
   * @exception Initialization_Exception thrown if resources could not be
   * allocated
   */
  ConditionImpl(Lockable& predicateLock) : _predicateLock(predicateLock) {

  }

  /**
   * Destroy this ConditionImpl, release its resources
   */
  ~ConditionImpl();

  void signal();

  void broadcast();

  void wait();

  bool wait(unsigned long timeout);

};


template <typename List>
ConditionImpl<List>::~ConditionImpl() {

#ifndef NDEBUG

    // It is an error to destroy a condition with threads waiting on it.
    if(!_waiters.empty()) {

      ZTDEBUG("** You are destroying a condition variable which still has waiting threads. **\n");
      assert(0);

    }

#endif

  }


/**
 * Signal the condition variable, waking one thread if any.
 */
template <typename List>
void ConditionImpl<List>::signal() {

    Guard<FastLock> g1(_lock);

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

/**
 * Broadcast to the condition variable, waking all threads waiting at the time of
 * the broadcast.
 */
template <typename List>
void ConditionImpl<List>::broadcast() {

    Guard<FastLock> g1(_lock);

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

          // Try to wake the waiter, it doesn't matter if this is successful
          // or not (only fails when the monitor is already going to stop waiting).
          m.notify();

          m.release();

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

/**
 * Cause the currently executing thread to block until this ConditionImpl has
 * been signaled, the threads state changes.
 *
 * @param predicate Lockable&
 *
 * @exception Interrupted_Exception thrown when the caller status is interrupted
 * @exception Synchronization_Exception thrown if there is some other error.
 */
template <typename List>
void ConditionImpl<List>::wait() {

    // Get the monitor for the current thread
    ThreadImpl* self = ThreadImpl::current();
    Monitor& m = self->getMonitor();

    Monitor::STATE state;

    {

      Guard<FastLock> g1(_lock);

      // Release the _predicateLock
      _predicateLock.release();

      // Stuff the waiter into the list
      _waiters.insert(self);

      // Move to the monitor's lock
      m.acquire();

      {

        Guard<FastLock, UnlockedScope> g2(g1);
        state = m.wait();

      }

      // Move back to the Condition's lock
      m.release();

      // Remove from waiter list, regarless of weather release() is called or
      // not. The monitor is sticky, so its possible a state 'stuck' from a
      // previous operation and will leave the wait() w/o release() having
      // been called.
      typename List::iterator i = std::find(_waiters.begin(), _waiters.end(), self);
      if(i != _waiters.end())
        _waiters.erase(i);

    }

    // Defer interruption until the external lock is acquire()d
    Guard<Monitor, DeferredInterruptionScope> g3(m);
    {

#if !defined(NDEBUG)
      try {
#endif
        _predicateLock.acquire(); // Should not throw
#if !defined(NDEBUG)
      } catch(...) { assert(0); }
#endif

    }

    switch(state) {

      case Monitor::SIGNALED:
        break;

      case Monitor::INTERRUPTED:
        throw Interrupted_Exception();

      default:
        throw Synchronization_Exception();
    }

  }


/**
 * Cause the currently executing thread to block until this ConditionImpl has
 * been signaled, or the timeout expires or the threads state changes.
 *
 * @param _predicateLock Lockable&
 * @param timeout maximum milliseconds to block.
 *
 * @return bool
 *
 * @exception Interrupted_Exception thrown when the caller status is interrupted
 * @exception Synchronization_Exception thrown if there is some other error.
 */
template <typename List>
bool ConditionImpl<List>::wait(unsigned long timeout) {

    // Get the monitor for the current thread
    ThreadImpl* self = ThreadImpl::current();
    Monitor& m = self->getMonitor();

    Monitor::STATE state;

    {

      Guard<FastLock> g1(_lock);

      // Release the _predicateLock
      _predicateLock.release();

      // Stuff the waiter into the list
      _waiters.insert(self);

      state = Monitor::TIMEDOUT;

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

    }


    // Defer interruption until the external lock is acquire()d
    Guard<Monitor, DeferredInterruptionScope> g3(m);
    {

#if !defined(NDEBUG)
      try {
#endif
        _predicateLock.acquire(); // Should not throw
#if !defined(NDEBUG)
      } catch(...) { assert(0); }
#endif

    }

    switch(state) {

      case Monitor::SIGNALED:
        break;

      case Monitor::INTERRUPTED:
        throw Interrupted_Exception();

      case Monitor::TIMEDOUT:
        return false;

      default:
        throw Synchronization_Exception();
    }

    return true;

  }

} // namespace ZThread

#endif // __ZTCONDITIONIMPL_H__

