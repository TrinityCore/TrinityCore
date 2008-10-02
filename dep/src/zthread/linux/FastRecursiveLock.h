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

#ifndef __ZTFASTRECURSIVELOCK_H__
#define __ZTFASTRECURSIVELOCK_H__

#include "zthread/NonCopyable.h"
#include <pthread.h>

namespace ZThread {

/**
 * @class FastRecursiveLock
 *
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T23:27:14-0400>
 * @version 2.2.0
 *
 * This implementation of a FastRecursiveLock uses the recursive mutex
 * that linux pthreads provides.  
 */ 
class FastRecursiveLock : private NonCopyable {
    
  pthread_mutex_t _mtx;
  
public:
  
  inline FastRecursiveLock() {
    
    static const pthread_mutexattr_t attr = { PTHREAD_MUTEX_RECURSIVE_NP };
    pthread_mutex_init(&_mtx, &attr);

  }
  
  inline ~FastRecursiveLock() {

    pthread_mutex_destroy(&_mtx);

  }
  
  inline void acquire() {
    
    pthread_mutex_lock(&_mtx);

  }

  inline void release() {
    
    pthread_mutex_unlock(&_mtx);
    
  }
  
  inline bool tryAcquire(unsigned long timeout=0) {

    return (pthread_mutex_trylock(&_mtx) == 0);

  }
  
}; /* FastRecursiveLock */


} // namespace ZThread

#endif
