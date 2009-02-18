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
#include <windows.h>
#include <assert.h>

namespace ZThread {


/**
 * @class FastLock
 *
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T23:32:20-0400>
 * @version 2.1.6
 *
 * This is the smallest and fastest synchronization object in the library.
 * It is an implementation of fast mutex, an all or nothing exclusive
 * lock. It should be used only where you need speed and are willing
 * to sacrifice all the state & safety checking provided by the framework
 * for speed.
 *
 * The current Platform SDK defines:
 *
 *   LONG InterlockedExchange(LPLONG, LONG)
 *   LONG InterlockedCompareExchange(LPLONG, LONG, LONG, LONG)
 *
 * If your compiler complains about LPLONG not being implicitly casted to
 * a PVOID, then you should get the SDK update from microsoft or use the
 * WIN9X implementation of this class.
 *
 * ----
 * Because Windows 95 and earlier can run on processors prior to the 486, they
 * don't all support the CMPXCHG function, and so Windows 95 an earlier dont support
 * InterlockedCompareExchange. For this, you should use the win9x implementation
 * of this class
 */
class FastLock : private NonCopyable {

#pragma pack(push, 8)
  LONG volatile _lock;
#pragma pack(pop)

  public:

  /**
   * Create a new FastLock
   */
  inline FastLock() : _lock(0) { }


  /**
   * Destroy FastLock
   */
  inline ~FastLock() { assert(_lock == 0); }

  /**
   * Lock the fast Lock, no error check.
   *
   * @exception None
   */
  inline void acquire() {

    while (::InterlockedCompareExchange(const_cast<LPLONG>(&_lock), 1, 0) != 0)
      ::Sleep(0);

  }


  /**
   * Release the fast Lock, no error check.
   *
   * @exception None
   */
  inline void release() {

    ::InterlockedExchange(const_cast<LPLONG>(&_lock), (LONG)0);

  }

  /**
   * Try to acquire an exclusive lock. No safety or state checks are performed.
   * This function returns immediately regardless of the value of the timeout
   *
   * @param timeout Unused
   * @return bool
   * @exception Synchronization_Exception - not thrown
   */
 inline bool tryAcquire(unsigned long timeout=0) {

   return ::InterlockedCompareExchange(const_cast<LPLONG>(&_lock), 1, 0) == 0;

 }

}; /* FastLock */


};
#endif

