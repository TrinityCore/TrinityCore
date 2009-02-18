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

#include "zthread/Runnable.h"
#include "zthread/Thread.h"
#include "ThreadImpl.h"

namespace ZThread {


  Thread::Thread()
    : _impl( ThreadImpl::current() ) {

    // ThreadImpl's start out life with a reference count
    // of one, and the they are added to the ThreadQueue.
    _impl->addReference();

  }

  Thread::Thread(const Task& task, bool autoCancel)
    : _impl( new ThreadImpl(task, autoCancel) ) {

    _impl->addReference();

  }

  bool Thread::operator==(const Thread& t) const {
    return (t._impl == _impl);
  }

  Thread::~Thread() {

    _impl->delReference();

  }

  void Thread::wait() {
    _impl->join(0);
  }

  bool Thread::wait(unsigned long timeout) {

    return _impl->join(timeout == 0 ? 1 : timeout);

  }

  bool Thread::interrupted() {

    return ThreadImpl::current()->isInterrupted();

  }


  bool Thread::canceled() {

    return ThreadImpl::current()->isCanceled();

  }

  void Thread::setPriority(Priority n) {

    _impl->setPriority(n);

  }


  Priority Thread::getPriority() {

    return _impl->getPriority();

  }

  bool Thread::interrupt() {

    return _impl->interrupt();

  }

  void Thread::cancel() {

    if(ThreadImpl::current() == _impl)
      throw InvalidOp_Exception();

    _impl->cancel();

  }

  bool Thread::isCanceled() {

    return _impl->isCanceled();

  }


  void Thread::sleep(unsigned long ms) {

    ThreadImpl::sleep(ms);

  }


  void Thread::yield() {

    ThreadImpl::yield();

  }

} // namespace ZThread
