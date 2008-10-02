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
 * @date <2003-07-16T23:30:59-0400>
 * @version 2.2.8
 *
 * This implementation of a FastRecursiveLock uses the which ever FastLock
 * that is selected to create a recursive spin lock. 
 */ 
class FastRecursiveLock : private NonCopyable {
  
  FastLock _lock;

  ThreadOps _owner;

  volatile unsigned int _count;
  
public:
  
  inline FastRecursiveLock() : _owner(ThreadOps::INVALID), _count(0) {}
  
  inline ~FastRecursiveLock() {

    assert(_owner == ThreadOps::INVALID);
    assert(_count == 0);

  }
  
  inline void acquire() {

    ThreadOps self(ThreadOps::self());
    bool wasLocked = false;

    do {
      
      _lock.acquire();
      
      // If there is no owner, or the owner is the caller
      // update the count
      if(_owner == ThreadOps::INVALID || _owner == self) {

        _owner = self;
        _count++;
        
        wasLocked = true;
  
      }

      _lock.release();
      
    } while(!wasLocked);

    assert(_owner == ThreadOps::self());

  }

  inline void release() {

    assert(_owner == ThreadOps::self());

    _lock.acquire();

    if(--_count == 0)
      _owner = ThreadOps::INVALID;

    _lock.release();
    
  }
  
  inline bool tryAcquire(unsigned long timeout=0) {

    ThreadOps self(ThreadOps::self());
    bool wasLocked = false;

    _lock.acquire();
    
    if(_owner == ThreadOps::INVALID || _owner == self) {
    
      _owner = self;
      _count++;
      
      wasLocked = true;

    }
    
    _lock.release();

    assert(!wasLocked || _owner == ThreadOps::self());
    return wasLocked;    
    
  }
  
}; /* FastRecursiveLock */


} // namespace ZThread

#endif
