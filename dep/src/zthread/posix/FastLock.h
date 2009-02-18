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

#ifndef __ZTFASTLOCK_H__
#define __ZTFASTLOCK_H__

#include "zthread/Exceptions.h"
#include "zthread/NonCopyable.h"
#include <pthread.h>
#include <assert.h>

namespace ZThread {

/**
 * @class FastLock
 *
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T23:28:07-0400>
 * @version 2.2.8
 *
 * This is the smallest and fastest synchronization object in the library.
 * It is an implementation of fast mutex, an all or nothing exclusive
 * lock. It should be used only where you need speed and are willing
 * to sacrifice all the state & safety checking provided by the framework
 * for speed.
 */
class FastLock : private NonCopyable {

  pthread_mutex_t _mtx;

 public:

  /**
   * Create a new FastLock. No safety or state checks are performed.
   *
   * @exception Initialization_Exception - not thrown
   */
  inline FastLock() {

    if(pthread_mutex_init(&_mtx, 0) != 0)
      throw Initialization_Exception();

  }

  /**
   * Destroy a FastLock. No safety or state checks are performed.
   */
  inline ~FastLock() {

    if(pthread_mutex_destroy(&_mtx) != 0) {
      assert(0);
    }

  }

  /**
   * Acquire an exclusive lock. No safety or state checks are performed.
   *
   * @exception Synchronization_Exception - not thrown
   */
  inline void acquire() {

    if(pthread_mutex_lock(&_mtx) != 0)
      throw Synchronization_Exception();

  }

  /**
   * Try to acquire an exclusive lock. No safety or state checks are performed.
   * This function returns immediately regardless of the value of the timeout
   *
   * @param timeout Unused
   * @return bool
   * @exception Synchronization_Exception - not thrown
   */
  inline bool tryAcquire(unsigned long /*timeout*/=0) {

    return (pthread_mutex_trylock(&_mtx) == 0);

  }

  /**
   * Release an exclusive lock. No safety or state checks are performed.
   * The caller should have already acquired the lock, and release it
   * only once.
   *
   * @exception Synchronization_Exception - not thrown
   */
  inline void release() {

    if(pthread_mutex_unlock(&_mtx) != 0)
      throw Synchronization_Exception();

  }


}; /* FastLock */


};

#endif

