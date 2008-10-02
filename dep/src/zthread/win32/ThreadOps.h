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
#include <windows.h>
#include <assert.h>

namespace ZThread {

class Runnable;

/**
 * @class ThreadOps
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T23:33:59-0400>
 * @version 2.2.8
 *
 * This class is an abstraction used to perform various operations on a 
 * native WIN32 thread.
 */
class ThreadOps {

  //! Dispatch function for native thread
  static unsigned int __stdcall _dispatch(void*);

  //! TID while the thread is executing.
  HANDLE _hThread;
  DWORD _tid;

  ThreadOps(DWORD tid) : _tid(tid) { }

 public:

  const static ThreadOps INVALID; 

  /**
   * Create a new ThreadOps to represent a native thread. 
   */  
  ThreadOps() : _tid(0), _hThread(NULL) {}


  inline bool operator==(const ThreadOps& ops) const {
    return _tid == ops._tid;
  }

  
  static ThreadOps self() {
    return ThreadOps(::GetCurrentThreadId());
  }

  /**
   * Update the native tid for this thread so it matches the current
   * thread.
   */ 
  static void activate(ThreadOps* ops) {

    assert(ops);
    assert(ops->_tid == 0);

    ops->_tid = ::GetCurrentThreadId();

  }

  /**
   * Test if this object representative of the currently executing 
   * native thread.
   *
   * @return bool true if successful
   */
  static bool isCurrent(ThreadOps* ops) {

    assert(ops);

    return ops->_tid == ::GetCurrentThreadId();

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
   * @return bool true if successful
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

#endif
