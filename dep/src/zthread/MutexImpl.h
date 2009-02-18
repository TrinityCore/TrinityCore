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

#include "zthread/Exceptions.h"
#include "zthread/Guard.h"

#include "Debug.h"
#include "FastLock.h"
#include "Scheduling.h"

#include <assert.h>
#include <errno.h>

namespace ZThread {


/**
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T19:52:12-0400>
 * @version 2.2.11
 * @class NullBehavior
 */
class NullBehavior {
protected:

  inline void waiterArrived(ThreadImpl*) {  }

  inline void waiterDeparted(ThreadImpl*) {  }

  inline void ownerAcquired(ThreadImpl*) {  }

  inline void ownerReleased(ThreadImpl*) {  }

};

/**
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T19:52:12-0400>
 * @version 2.2.11
 * @class MutexImpl
 *
 * The MutexImpl template allows how waiter lists are sorted, and
 * what actions are taken when a thread interacts with the mutex
 * to be parametized.
 */
template <typename List, typename Behavior>
class MutexImpl : Behavior {

  //! List of Events that are waiting for notification
  List _waiters;

  //! Serialize access to this Mutex
  FastLock _lock;

  //! Current owner
  volatile ThreadImpl* _owner;

 public:


  /**
   * Create a new MutexImpl
   *
   * @exception Initialization_Exception thrown if resources could not be
   * properly allocated
   */
  MutexImpl() : _owner(0) { }

  ~MutexImpl();

  void acquire();

  void release();

  bool tryAcquire(unsigned long timeout);

};

  /**
   * Destroy this MutexImpl and release its resources
   */
template<typename List, typename Behavior>
MutexImpl<List, Behavior>::~MutexImpl() {

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


  /**
   * Acquire a lock on the mutex. If this operation succeeds the calling
   * thread holds an exclusive lock on this mutex, otherwise it is blocked
   * until the lock can be acquired.
   *
   * @exception Deadlock_Exception thrown when the caller attempts to acquire() more
   * than once, If the checking flag is set.
   * @exception Interrupted_Exception thrown when the caller status is interrupted
   * @exception Synchronization_Exception thrown if there is some other error.
   */
template<typename List, typename Behavior>
void MutexImpl<List, Behavior>::acquire() {

    ThreadImpl* self = ThreadImpl::current();
    Monitor& m = self->getMonitor();

    Monitor::STATE state;

    Guard<FastLock> g1(_lock);

    // Deadlock will occur if the current thread is the owner
    // and there is no entry count.
    if(_owner == self)
      throw Deadlock_Exception();

    // Acquire the lock if it is free and there are no waiting threads
    if(_owner == 0 && _waiters.empty()) {

      _owner = self;

      this->ownerAcquired(self);

    }

    // Otherwise, wait for a signal from a thread releasing its
    // ownership of the lock
    else {

      _waiters.insert(self);
      m.acquire();

      this->waiterArrived(self);

      {

        Guard<FastLock, UnlockedScope> g2(g1);
        state = m.wait();

      }

      this->waiterDeparted(self);

      m.release();

      // Remove from waiter list, regardless of wether release() is called or
      // not. The monitor is sticky, so its possible a state 'stuck' from a
      // previous operation and will leave the wait() w/o release() having
      // been called (e.g. interrupted)
      typename List::iterator i = std::find(_waiters.begin(), _waiters.end(), self);
      if(i != _waiters.end())
        _waiters.erase(i);

      // If awoke due to a notify(), take ownership.
      switch(state) {
        case Monitor::SIGNALED:

          assert(_owner == 0);
          _owner = self;

          this->ownerAcquired(self);

          break;

        case Monitor::INTERRUPTED:
          throw Interrupted_Exception();

        default:
          throw Synchronization_Exception();
      }

    }

  }


  /**
   * Acquire a lock on the mutex. If this operation succeeds the calling
   * thread holds an exclusive lock on this mutex. If the lock cannot be
   * obtained before the timeout expires, the caller returns false.
   *
   * @exception Deadlock_Exception thrown when the caller attempts to acquire() more
   * than once, If the checking flag is set.
   * @exception Interrupted_Exception thrown when the caller status is interrupted
   * @exception Synchronization_Exception thrown if there is some other error.
   */
template<typename List, typename Behavior>
bool MutexImpl<List, Behavior>::tryAcquire(unsigned long timeout) {

    ThreadImpl* self = ThreadImpl::current();
    Monitor& m = self->getMonitor();

    Guard<FastLock> g1(_lock);

    // Deadlock will occur if the current thread is the owner
    // and there is no entry count.
    if(_owner == self)
      throw Deadlock_Exception();

    // Acquire the lock if it is free and there are no waiting threads
    if(_owner == 0 && _waiters.empty()) {

      _owner = self;

      this->ownerAcquired(self);

    }

    // Otherwise, wait for a signal from a thread releasing its
    // ownership of the lock
    else {

      _waiters.insert(self);

      Monitor::STATE state = Monitor::TIMEDOUT;

      // Don't bother waiting if the timeout is 0
      if(timeout) {

        m.acquire();

        this->waiterArrived(self);

        {

          Guard<FastLock, UnlockedScope> g2(g1);
          state = m.wait(timeout);

        }

        this->waiterDeparted(self);

        m.release();

      }


      // Remove from waiter list, regarless of weather release() is called or
      // not. The monitor is sticky, so its possible a state 'stuck' from a
      // previous operation and will leave the wait() w/o release() having
      // been called.
      typename List::iterator i = std::find(_waiters.begin(), _waiters.end(), self);
      if(i != _waiters.end())
        _waiters.erase(i);

      // If awoke due to a notify(), take ownership.
      switch(state) {
        case Monitor::SIGNALED:

          assert(0 == _owner);
          _owner = self;

          this->ownerAcquired(self);

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
   * Release a lock on the mutex. If this operation succeeds the calling
   * thread no longer holds an exclusive lock on this mutex. If there are
   * waiting threads, one will be selected, assigned ownership and specifically
   * awakened.
   *
   * @exception InvalidOp_Exception - thrown if an attempt is made to
   * release a mutex not owned by the calling thread.
   */
template<typename List, typename Behavior>
void MutexImpl<List, Behavior>::release() {

    ThreadImpl* impl = ThreadImpl::current();

    Guard<FastLock> g1(_lock);

    // Make sure the operation is valid
    if(_owner != impl)
      throw InvalidOp_Exception();

    _owner = 0;

    this->ownerReleased(impl);

    // Try to find a waiter with a backoff & retry scheme
    for(;;) {

      // Go through the list, attempt to notify() a waiter.
      for(typename List::iterator i = _waiters.begin(); i != _waiters.end();) {

        // Try the monitor lock, if it cant be locked skip to the next waiter
        impl = *i;
        Monitor& m = impl->getMonitor();

        if(m.tryAcquire()) {

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

} // namespace ZThread







