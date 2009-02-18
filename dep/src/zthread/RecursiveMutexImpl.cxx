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

#include "Debug.h"

#include "RecursiveMutexImpl.h"
#include "ThreadImpl.h"

#include "zthread/Guard.h"

#include <assert.h>
#include <errno.h>
#include <algorithm>

namespace ZThread {

  /**
   * Create a new RecursiveMutexImpl
   *
   * @exception Initialization_Exception thrown if resources could not be
   * properly allocated
   */
  RecursiveMutexImpl::RecursiveMutexImpl()
    : _owner(0), _count(0) {

  }

  /**
   * Destroy this RecursiveMutexImpl and release its resources
   */
  RecursiveMutexImpl::~RecursiveMutexImpl() {

#ifndef NDEBUG

    // It is an error to destroy a mutex that has not been released
    if(_owner != 0) {

      ZTDEBUG("** You are destroying a mutex which was never released. **\n");
      assert(0); // Destroyed mutex while in use

    }

    if(!_waiters.empty()) {

      ZTDEBUG("** You are destroying a mutex which is blocking %d threads. **\n", _waiters.size());
      assert(0); // Destroyed mutex while in use

    }

#endif

  }


  void RecursiveMutexImpl::acquire() {

    // Get the monitor for the current thread
    Monitor& m = ThreadImpl::current()->getMonitor();
    Monitor::STATE state;

    Guard<FastLock> g1(_lock);

    // If there is an entry count and the current thread is
    // the owner, increment the count and continue.
    if(_owner == &m)
      _count++;

    else {

      // Acquire the lock if it is free and there are no waiting threads
      if(_owner == 0 && _waiters.empty()) {

        assert(_count == 0);

        _owner = &m;
        _count++;

      } else { // Otherwise, wait()

        _waiters.push_back(&m);

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
        List::iterator i = std::find(_waiters.begin(), _waiters.end(), &m);
        if(i != _waiters.end())
          _waiters.erase(i);

        // If awoke due to a notify(), take ownership.
        switch(state) {
          case Monitor::SIGNALED:

            assert(_owner == 0);
            assert(_count == 0);

            _owner = &m;
            _count++;

            break;

          case Monitor::INTERRUPTED:
            throw Interrupted_Exception();

          default:
            throw Synchronization_Exception();
        }

      }

    }

  }

  bool RecursiveMutexImpl::tryAcquire(unsigned long timeout) {

    // Get the monitor for the current thread
    Monitor& m = ThreadImpl::current()->getMonitor();

    Guard<FastLock> g1(_lock);

    // If there is an entry count and the current thread is
    // the owner, increment the count and continue.
    if(_owner == &m)
      _count++;

    else {

      // Acquire the lock if it is free and there are no waiting threads
      if(_owner == 0 && _waiters.empty()) {

        assert(_count == 0);

        _owner = &m;
        _count++;

      } else { // Otherwise, wait()

        _waiters.push_back(&m);

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
        List::iterator i = std::find(_waiters.begin(), _waiters.end(), &m);
        if(i != _waiters.end())
          _waiters.erase(i);

        // If awoke due to a notify(), take ownership.
        switch(state) {
          case Monitor::SIGNALED:

            assert(_count == 0);
            assert(_owner == 0);

            _owner = &m;
            _count++;

            break;

          case Monitor::INTERRUPTED:
            throw Interrupted_Exception();

          case Monitor::TIMEDOUT:
            return false;

          default:
            throw Synchronization_Exception();
        }

      }

    }

    return true;

  }

  void RecursiveMutexImpl::release() {

    // Get the monitor for the current thread
    Monitor& m = ThreadImpl::current()->getMonitor();

    Guard<FastLock> g1(_lock);

    // Make sure the operation is valid
    if(!(_owner == &m))
      throw InvalidOp_Exception();

    // Update the count, if it has reached 0, wake another waiter.
    if(--_count == 0) {

      _owner = 0;

      // Try to find a waiter with a backoff & retry scheme
      for(;;) {

        // Go through the list, attempt to notify() a waiter.
        for(List::iterator i = _waiters.begin(); i != _waiters.end();) {

          // Try the monitor lock, if it cant be locked skip to the next waiter
          Monitor* n = *i;
          if(n->tryAcquire()) {

            // If notify() is not sucessful, it is because the wait() has already
            // been ended (killed/interrupted/notify'd)
            bool woke = n->notify();
            n->release();

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

  }

} // namespace ZThread




