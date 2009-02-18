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

#include "zthread/NonCopyable.h"
#include "../ThreadOps.h"
#include <assert.h>
#include <asm/atomic.h>

#if !defined(NDEBUG)
#  include <pthread.h>
#endif

namespace ZThread {

/**
 * @class FastLock
 *
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T23:27:03-0400>
 * @version 2.2.0
 *
 * This implementation of a FastLock uses the atomic operations that
 * linux provides with its kernel sources. This demonstrates how to implement
 * a spinlock with a decrement and test primative.
 */
class FastLock : private NonCopyable {

  atomic_t _value;

#if !defined(NDEBUG)
  pthread_t _owner;
#endif

public:

  inline FastLock() {

    atomic_t tmp =  ATOMIC_INIT(1);
    _value = tmp;

  }

  inline ~FastLock() {

    assert(atomic_read(&_value) == 1);
    assert(_owner == 0);

  }

  inline void acquire() {

    while(!atomic_dec_and_test(&_value)) {

      atomic_inc(&_value);
      ThreadOps::yield();

    }

#if !defined(NDEBUG)
    _owner = pthread_self();
#endif
  }

  inline void release() {

#if !defined(NDEBUG)
    assert(pthread_equal(_owner, pthread_self()) != 0);
#endif

    atomic_inc(&_value);
    _owner = 0;

  }

  inline bool tryAcquire(unsigned long timeout=0) {

    bool wasLocked = atomic_dec_and_test(&_value);
    if(!wasLocked)
      atomic_inc(&_value);

#if !defined(NDEBUG)
    if(wasLocked)
      _owner = pthread_self();
#endif

    return wasLocked;

  }

}; /* FastLock */


} // namespace ZThread

#endif

