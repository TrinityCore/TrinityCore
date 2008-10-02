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


#include "ThreadOps.h"
#include "zthread/Exceptions.h"
#include "zthread/Runnable.h"

namespace ZThread {

const ThreadOps ThreadOps::INVALID(0); 

ThreadOps::ThreadOps()  : _queue(0), _tid(0) { 
  
  if(MPCreateQueue(&_queue) != noErr)
    throw Initialization_Exception();

}

ThreadOps::~ThreadOps() throw() {
  
  if(_queue != 0) {

    OSStatus status = MPDeleteQueue(_queue);
    if(status != noErr) 
      assert(0);

  }
    
}

bool ThreadOps::join(ThreadOps* ops) {

  assert(ops);
  assert(ops->_tid != 0);

  OSStatus status = MPWaitOnQueue(ops->_queue, NULL, NULL, NULL, kDurationForever);

  return status == noErr;
 
}

bool ThreadOps::yield() {

  MPYield();
  return true;

}

bool ThreadOps::setPriority(ThreadOps* impl, Priority p) {
  return true;
}

bool ThreadOps::getPriority(ThreadOps* impl, Priority& p) {
  return true;
}


bool ThreadOps::spawn(Runnable* task) {

  OSStatus status =
    MPCreateTask(&_dispatch, task, 0UL, _queue, NULL, NULL, 0UL, &_tid);

  return status == noErr;

}

OSStatus ThreadOps::_dispatch(void *arg) {

  Runnable* task = reinterpret_cast<Runnable*>(arg);
  assert(task);

  // Run the task from the correct context
  task->run();
  
  // Exit the thread
  MPExit(noErr);
  return noErr;

}
  
} // namespace ZThread


