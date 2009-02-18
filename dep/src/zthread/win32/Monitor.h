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

#ifndef __ZTMONITOR_H__
#define __ZTMONITOR_H__

#include "../Status.h"
#include "../FastLock.h"

namespace ZThread {

/**
 * @class Monitor
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T23:33:10-0400>
 * @version 2.2.11
 */
class Monitor : public Status, private NonCopyable {

  //! Serialize access to external objects
  FastLock _lock;

  //! Event used to block thread
  HANDLE _handle;

  //! Serialize access to the internal state of the monitor
  FastLock _waitLock;

  //! Owning thread
  DWORD _owner;

  //! Waiting flag, to avoid uneccessary signals
  volatile bool _waiting;

  //! State of the monitor
  volatile int _state;

 public:

  //! Create a new monitor.
  Monitor();

  //! Destroy the monitor.
  ~Monitor();

  //! Acquire the external lock for this monitor.
  inline void acquire() {
    _lock.acquire();
  }

  //! Try to acquire the external lock for this monitor.
  inline bool tryAcquire() {
    return _lock.tryAcquire();
  }

  //! Release the external lock for this monitor.
  inline void release() {
    _lock.release();
  }

  /**
   * Wait for a state change and atomically unlock the external lock.
   * Blocks for an indefinent amount of time.
   *
   * @return INTERRUPTED if the wait was ended by a interrupt()
   *         or SIGNALED if the wait was ended by a notify()
   *
   * @post the external lock is always acquired before this function returns
   */
  inline STATE wait() {
    return wait(0);
  }

  /**
   * Wait for a state change and atomically unlock the external lock.
   * May blocks for an indefinent amount of time.
   *
   * @param timeout - maximum time to block (milliseconds) or 0 to
   * block indefinently
   *
   * @return INTERRUPTED if the wait was ended by a interrupt()
   *         or TIMEDOUT if the maximum wait time expired.
   *         or SIGNALED if the wait was ended by a notify()
   *
   * @post the external lock is always acquired before this function returns
   */
  STATE wait(unsigned long timeout);

  /**
   * Interrupt this monitor. If there is a thread blocked on this monitor object
   * it will be signaled and released. If there is no waiter, a flag is set and
   * the next attempt to wait() will return INTERRUPTED w/o blocking.
   *
   * @return false if the thread was previously INTERRUPTED.
   */
  bool interrupt();

  /**
   * Notify this monitor. If there is a thread blocked on this monitor object
   * it will be signaled and released. If there is no waiter, a flag is set and
   * the next attempt to wait() will return SIGNALED w/o blocking, if no other
   * flag is set.
   *
   * @return false if the thread was previously INTERRUPTED.
   */
  bool notify();

  /**
   * Check the state of this monitor, clearing the INTERRUPTED status if set.
   *
   * @return bool true if the monitor was INTERRUPTED.
   * @post INTERRUPTED flag cleared if the calling thread owns the monitor.
   */
  bool isInterrupted();

  /**
   * Mark the Status CANCELED, and INTERRUPT the montor.
   *
   * @see interrupt()
   */
  bool cancel();

  /**
   * Test the CANCELED Status, clearing the INTERRUPTED status if set.
   *
   * @return bool
   */
  bool isCanceled();

};

};

#endif

