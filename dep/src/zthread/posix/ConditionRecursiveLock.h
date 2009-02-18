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
#include <errno.h>
#include <assert.h>

namespace ZThread {

/**
 * @class FastRecursiveLock
 *
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T23:28:37-0400>
 * @version 2.2.0
 *
 * This is an implementation of a FastRecursiveLock for any vannila
 * POSIX system. It is based on a condition variable and a mutex;
 * because of this it is important to not that its waiting properties
 * are not the same as other mutex implementations that generally
 * based on spin locks. Under high contention, this implementation may
 * be preferable to a spin lock, although refactoring the design of
 * code that puts a mutex under alot of preasure may be worth investigating.
 */
class FastRecursiveLock : private NonCopyable {

  //! Serialize state
  pthread_mutex_t _mtx;

  //! Wait for lock
  pthread_cond_t _cond;

  //! Owner
  pthread_t _owner;

  //! Count
  volatile unsigned int _count;

public:

  inline FastRecursiveLock() : _owner(0), _count(0) {

    pthread_mutex_init(&_mtx, 0);
    if(pthread_cond_init(&_cond, 0) != 0) {
      assert(0);
    }

  }

  inline ~FastRecursiveLock() {

    pthread_mutex_destroy(&_mtx);
    if(pthread_cond_destroy(&_cond) != 0) {
      assert(0);
    }

  }

  inline void acquire() {

    pthread_t self = pthread_self();
    pthread_mutex_lock(&_mtx);

    // If the caller does not own the lock, wait until there is no owner
    if(_owner != 0 && !pthread_equal(_owner, self)) {

      int status = 0;
      do { // ignore signals
        status = pthread_cond_wait(&_cond, &_mtx);
      } while(status == EINTR && _owner == 0);

    }

    _owner = self;
    _count++;

    pthread_mutex_unlock(&_mtx);

  }

  inline bool tryAcquire(unsigned long timeout=0) {

    pthread_t self = pthread_self();
    pthread_mutex_lock(&_mtx);

    // If the caller owns the lock, or there is no owner update the count
    bool success = (_owner == 0 || pthread_equal(_owner, self));
    if(success) {

      _owner = self;
      _count++;

    }

    pthread_mutex_unlock(&_mtx);

    return success;

  }

  inline void release() {

    assert(pthread_equal(_owner, pthread_self()));

    pthread_mutex_lock(&_mtx);
    if(--_count == 0) {

      _owner = 0;
      pthread_cond_signal(&_cond);

    }

    pthread_mutex_unlock(&_mtx);

  }


}; /* FastRecursiveLock */


} // namespace ZThread

#endif

