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

#ifndef __ZTTHREADIMPL_H__
#define __ZTTHREADIMPL_H__

#include "zthread/ThreadLocalImpl.h"
#include "zthread/Thread.h"
#include "zthread/Exceptions.h"
#include "IntrusivePtr.h"

#include "Monitor.h"
#include "TSS.h"
#include "ThreadOps.h"
#include "State.h"

#include <map>
#include <deque>

namespace ZThread {

/**
 * @class ThreadImpl
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-27T13:39:03-0400>
 * @version 2.3.0
 */
class ThreadImpl : public IntrusivePtr<ThreadImpl, FastLock>, public ThreadOps {

  typedef std::deque<ThreadImpl*> List;

  //! TSS to store implementation to current thread mapping.
  static TSS<ThreadImpl*> _threadMap;

  //! The Monitor for controlling this thread
  Monitor _monitor;

  //! Current state for the thread
  State _state;

  //! Joining threads
  List _joiners;

 public:

  typedef std::map<const ThreadLocalImpl*, ThreadLocalImpl::ValuePtr > ThreadLocalMap;

 private:

  ThreadLocalMap _tls;

  //! Cached thread priority
  Priority _priority;

  //! Request cancel() when main() goes out of scope
  bool _autoCancel;

  void start(const Task& task);

 public:

  ThreadImpl();

  ThreadImpl(const Task&, bool);

  ~ThreadImpl();

  Monitor& getMonitor();

  void cancel(bool autoCancel = false);

  bool interrupt();

  bool isInterrupted();

  bool isCanceled();

  Priority getPriority() const;

  //  ThreadLocalMap& getThreadLocalMap();
  ThreadLocalMap& getThreadLocalMap() { return _tls; }

  bool join(unsigned long);

  void setPriority(Priority);

  bool isActive();

  bool isReference();

  static void sleep(unsigned long);

  static void yield();

  static ThreadImpl* current();

  static void dispatch(ThreadImpl*, ThreadImpl*, Task);

};

} // namespace ZThread

#endif // __ZTTHREADIMPL_H__

