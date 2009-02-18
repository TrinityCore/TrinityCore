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

#ifndef __ZTRECURSIVEMUTEXIMPL_H__
#define __ZTRECURSIVEMUTEXIMPL_H__

#include "zthread/Exceptions.h"

#include "FastLock.h"

#include <vector>

namespace ZThread {

  class Monitor;

  /**
   * @class RecursiveMutexImpl
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T19:58:26-0400>
   * @version 2.1.6
   *
   * This synchronization object provides serialized access
   * through an acquire/release protocol.
   */
  class ZTHREAD_API RecursiveMutexImpl {

    typedef std::vector<Monitor*> List;

    //! List of Events that are waiting for notification
    List _waiters;

    //! Serialize access to this Mutex
    FastLock _lock;

    //! Current owning Event object
    Monitor* _owner;

    //! Entry count
    size_t _count;

  public:

    RecursiveMutexImpl();

    virtual ~RecursiveMutexImpl();

    void acquire();

    bool tryAcquire(unsigned long);

    void release();

  }; /* RecursiveMutexImpl */


};

#endif

