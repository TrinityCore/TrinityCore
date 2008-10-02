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
#include "zthread/Guard.h"
#include "zthread/Runnable.h"
#include <errno.h>

#if defined(HAVE_SCHED_YIELD)
#  include <sched.h>
#endif

namespace ZThread {

const ThreadOps ThreadOps::INVALID(0); 

bool ThreadOps::join(ThreadOps* ops) {

  assert(ops);
  assert(ops->_tid != 0);

  int err = 0;

  do {

    err = pthread_join(ops->_tid, NULL);

  } while(err == EINTR);

  return err == 0;

}

bool ThreadOps::yield() {

  bool result = false;

#if defined(HAVE_SCHED_YIELD)
  result = sched_yield() == 0;
#endif
  
  return result;

}

bool ThreadOps::setPriority(ThreadOps* impl, Priority p) {

  assert(impl);

  bool result = true;
  
#if !defined(ZTHREAD_DISABLE_PRIORITY)
  
  struct sched_param param;
  
  switch(p) {
    case Low:
      param.sched_priority = 0;
      break;
    case High:
      param.sched_priority = 10;
      break;
    case Medium:
    default:
      param.sched_priority = 5;
  }
  
  result = pthread_setschedparam(impl->_tid, SCHED_OTHER, &param) == 0;

#endif

  return result;

}

bool ThreadOps::getPriority(ThreadOps* impl, Priority& p) {

  assert(impl);

  bool result = true;
  
#if !defined(ZTHREAD_DISABLE_PRIORITY)

  struct sched_param param;
  int policy = SCHED_OTHER;
  
  if(result = (pthread_getschedparam(impl->_tid, &policy, &param) == 0)) {
    
    // Convert to one of the PRIORITY values
    if(param.sched_priority < 10)
      p = Low;
    else if(param.sched_priority == 10)
      p = Medium;
    else
      p = High;
    
  }
  
#endif

  return result;

}


bool ThreadOps::spawn(Runnable* task) {
  return pthread_create(&_tid, 0, _dispatch, task) == 0;
}



extern "C" void *_dispatch(void *arg) {

  Runnable* task = reinterpret_cast<Runnable*>(arg);
  assert(task);
  
  // Run the task from the correct context
  task->run();
  
  // Exit the thread
  pthread_exit((void**)0);
  return (void*)0;
  
}
  
} // namespace ZThread


