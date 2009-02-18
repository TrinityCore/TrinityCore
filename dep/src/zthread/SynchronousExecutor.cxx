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

#include "zthread/SynchronousExecutor.h"

namespace ZThread {

  SynchronousExecutor::SynchronousExecutor()
    : _canceled(false) {}

  SynchronousExecutor::~SynchronousExecutor() {
  }

  void SynchronousExecutor::cancel() {

    Guard<Mutex> g(_lock);
    _canceled = true;

  }

  bool SynchronousExecutor::isCanceled() {

    Guard<Mutex> g(_lock);
    return _canceled;

  }

  void SynchronousExecutor::interrupt() {
  }

  void SynchronousExecutor::execute(const Task& task) {

    // Canceled Executors will not accept new tasks, quick
    // check to avoid excessive locking in the canceled state
    if(_canceled)
      throw Cancellation_Exception();

    Guard<Mutex> g(_lock);

    if(_canceled) // Double check
      throw Cancellation_Exception();

    // Run the task.
    Task(task)->run();

  }

  void SynchronousExecutor::wait() {

    if(Thread::interrupted())
      throw Interrupted_Exception();

    Guard<Mutex> g(_lock);

  }

  /**
   * @see Executor::wait(unsigned long)
   */
  bool SynchronousExecutor::wait(unsigned long) {

    if(Thread::interrupted())
      throw Interrupted_Exception();

    Guard<Mutex> g(_lock);
    return true;

  }


}
