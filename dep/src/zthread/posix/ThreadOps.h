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

#ifndef __ZTTHREADOPS_H__
#define __ZTTHREADOPS_H__


#include "zthread/Priority.h"
#include <pthread.h>
#include <assert.h>

namespace ZThread {

class Runnable;

//! Dispatch function for native pthreads required extern C
//! linkage.
extern "C" void* _dispatch(void*);

/**
 * @class ThreadOps
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T23:30:25-0400>
 * @version 2.2.8
 *
 * This class is an abstraction used to perform various operations on a
 * native POSIX thread.
 */
class ThreadOps {

  //! Keep track of the pthreads handle for the native thread
  pthread_t _tid;

  ThreadOps(pthread_t tid) : _tid(tid) { }

public:

  const static ThreadOps INVALID;

  /**
   * Create a new ThreadOps to manipulate a native thread.
   */
  ThreadOps() : _tid(0) { }


  inline bool operator==(const ThreadOps& ops) const {
    return pthread_equal(_tid, ops._tid);
  }


  static ThreadOps self() {
    return ThreadOps(pthread_self());
  }

  /**
   * Activating an instance of ThreadOps will map it onto the currently
   * executing thread.
   */
  static void activate(ThreadOps* ops) {

    assert(ops);
    assert(ops->_tid == 0);

    ops->_tid = pthread_self();

  }

  /**
   * Test if this object represents the currently executing
   * native thread.
   *
   * @return bool true if successful
   */

  static bool isCurrent(ThreadOps* ops) {

    assert(ops);

    return pthread_equal(pthread_self(), ops->_tid);

  }

  /**
   * Join a native thread.
   *
   * @return bool true if successful
   */
  static bool join(ThreadOps*);

  /**
   * Force the current native thread to yield, letting the scheduler
   * give the CPU time to another thread.
   *
   * @return bool true if successful, false if the operation can't
   * be supported.
   */
  static bool yield();

  /**
   * Set the priority for the native thread if supported by the
   * system.
   *
   * @param PRIORITY requested priority
   * @return bool false if unsuccessful
   */
  static bool setPriority(ThreadOps*, Priority);

  /**
   * Set the priority for the native thread if supported by the
   * system.
   *
   * @param Thread::PRIORITY& current priority
   * @return bool false if unsuccessful
   */
  static bool getPriority(ThreadOps*, Priority&);

protected:

  /**
   * Spawn a native thread.
   *
   * @param ThreadImpl* parent thread
   * @param ThreadImpl* child thread being started.
   * @param Runnable* task being executed.
   *
   * @return bool true if successful
   */
  bool spawn(Runnable*);

};


}

#endif // __ZTTHREADOPS_H__

