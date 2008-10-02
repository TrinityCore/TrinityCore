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

#include "zthread/Exceptions.h"
#include "zthread/NonCopyable.h"
#include <windows.h>
#include <assert.h>

namespace ZThread {


/**
 * @class FastRecursiveLock
 *
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T23:32:56-0400>
 * @version 2.2.11
 *
 * This FastRecursiveLock implementation is based on a Win32 Mutex
 * object. This will perform better under high contention, 
 * but will not be as fast as the spin lock under reasonable
 * circumstances.
 */ 
class FastRecursiveLock : private NonCopyable {

  HANDLE _hMutex;
  volatile unsigned int _count;

  public:
  
  /**
   * Create a new FastRecursiveLock
   */
  FastRecursiveLock() : _count(0) { 

    _hMutex = ::CreateMutex(0, 0, 0);
    assert(_hMutex != NULL);
    if(_hMutex == NULL)
      throw Initialization_Exception();

  }

  
  ~FastRecursiveLock() {
    ::CloseHandle(_hMutex);
  }

  
  void acquire() {

    if(::WaitForSingleObject(_hMutex, INFINITE) != WAIT_OBJECT_0) {
      assert(0);
      throw Synchronization_Exception();
    }

  }

  void release() {

    if(::ReleaseMutex(_hMutex) == 0) {
      assert(0);
      throw Synchronization_Exception();
    }

  }

  bool tryAcquire(unsigned long) {

    switch(::WaitForSingleObject(_hMutex, 0)) {
      case WAIT_OBJECT_0:
        return true;
      case WAIT_TIMEOUT:
        return false;
      default:
        break;
    }

    assert(0);
    throw Synchronization_Exception();

  }

}; /* FastRecursiveLock */

} // namespace ZThread

#endif
