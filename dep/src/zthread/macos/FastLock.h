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
#include "zthread/Exceptions.h"

#include <assert.h>
#include <CoreServices/CoreServices.h>
//#include <Multiprocessing.h>

namespace ZThread {

/**
 * @class FastLock
 *
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T23:25:31-0400>
 * @version 2.1.6
 *
 */
class FastLock : private NonCopyable {

  MPCriticalRegionID _mtx;

 public:

  /**
   * Create a new FastLock. No safety or state checks are performed.
   *
   * @exception Initialization_Exception - not thrown
   */
  inline FastLock() {

    // Apple TN1071
    static bool init = MPLibraryIsLoaded();

    if(!init || MPCreateCriticalRegion(&_mtx) != noErr) {
      assert(0);
      throw Initialization_Exception();
    }

  }

  /**
   * Destroy a FastLock. No safety or state checks are performed.
   */
  inline ~FastLock() throw () {

    OSStatus status = MPDeleteCriticalRegion(_mtx);
    if(status != noErr)
      assert(false);

  }

  /**
   * Acquire an exclusive lock. No safety or state checks are performed.
   *
   * @exception Synchronization_Exception - not thrown
   */
  inline void acquire() {

    if(MPEnterCriticalRegion(_mtx, kDurationForever) != noErr)
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
  inline bool tryAcquire(unsigned long timeout=0) {

    OSStatus status =
      MPEnterCriticalRegion(_mtx, kDurationMillisecond * timeout);

    switch(status) {
      case kMPTimeoutErr:
        return false;

      case noErr:
        return true;

    }

    assert(0);
    throw Synchronization_Exception();

  }

  /**
   * Release an exclusive lock. No safety or state checks are performed.
   * The caller should have already acquired the lock, and release it
   * only once.
   *
   * @exception Synchronization_Exception - not thrown
   */
  inline void release() {

    if(MPExitCriticalRegion(_mtx) != noErr)
      throw Synchronization_Exception();

  }


}; /* FastLock */


};

#endif




