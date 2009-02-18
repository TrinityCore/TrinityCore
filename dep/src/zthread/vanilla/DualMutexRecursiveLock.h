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

#include "../FastLock.h"
#include "../ThreadOps.h"
#include <assert.h>

namespace ZThread {

/**
 * @class FastRecursiveLock
 *
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T23:31:09-0400>
 * @version 2.2.8
 *
 * This is a vanilla FastRecursiveLock implementation for a
 * system that doesn't provide recurisve locks. This implementation
 * is based on using a pair of mutexes, because of this, it performs
 * roughly the same as a spin lock would.
 */
class FastRecursiveLock : private NonCopyable {

  //! Lock for blocking
  FastLock _blockingLock;

  //! Serialize state
  FastLock _stateLock;

  //! Owner
  ThreadOps _owner;

  //! Count
  volatile unsigned int _count;

 public:

  inline FastRecursiveLock() : _owner(ThreadOps::INVALID), _count(0) { }

  inline ~FastRecursiveLock() {

    assert(_owner == ThreadOps::INVALID);
    assert(_count == 0);

  }

  void acquire() {

    ThreadOps self(ThreadOps::self());

    // Try to lock the blocking mutex first
    bool wasLocked = _blockingLock.tryAcquire();
    if(!wasLocked) {

      // Otherwise, grab the lock for the state
      _stateLock.acquire();

      wasLocked = (_owner == self);
      if(wasLocked)
        _count++;

      _stateLock.release();

      if(wasLocked)
        return;

      // Try to be cooperative
      ThreadOps::yield();
      _blockingLock.acquire();

    }

    // Serialze access to the state
    _stateLock.acquire();

    // Take ownership
    assert(_owner == ThreadOps::INVALID || _owner == self);

    _owner = self;
    _count++;

    _stateLock.release();

  }


  bool tryAcquire(unsigned long timeout = 0) {

    ThreadOps self(ThreadOps::self());

    // Try to lock the blocking mutex first
    bool wasLocked = _blockingLock.tryAcquire();
    if(!wasLocked) {

      // Otherwise, grab the lock for the state
      _stateLock.acquire();

      wasLocked = (_owner == self);
      if(wasLocked)
        _count++;

      _stateLock.release();

      return wasLocked;

    }

    // Serialze access to the state
    _stateLock.acquire();

    // Take ownership
    assert(_owner == ThreadOps::INVALID || _owner == self);

    _owner = self;
    _count++;

    _stateLock.release();

    return true;

  }


  void release() {

    // Assume that release is only used by the owning thread, as it
    // should be.
    assert(_count != 0);
    assert(_owner == ThreadOps::self());

    _stateLock.acquire();

    // If the lock was owned and the count has reached 0, give up
    // ownership and release the blocking lock
    if(--_count == 0) {

      _owner = ThreadOps::INVALID;
      _blockingLock.release();

    }

    _stateLock.release();

  }


}; /* FastRecursiveLock */

} // namespace ZThread

#endif

