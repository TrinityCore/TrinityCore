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

#ifndef __ZTFASTMUTEX_H__
#define __ZTFASTMUTEX_H__

#include "zthread/Lockable.h"
#include "zthread/NonCopyable.h"

namespace ZThread {

  class FastLock;

  /**
   * @class FastMutex
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-19T18:45:39-0400>
   * @version 2.2.0
   *
   * A FastMutex is a small fast implementation of a non-recursive, mutually exclusive
   * Lockable object. This implementation is a bit faster than the other Mutex classes
   * as it involved the least overhead. However, this slight increase in speed is
   * gained by sacrificing the robustness provided by the other classes.
   *
   * A FastMutex has the useful property of not being interruptable; that is to say
   * that acquire() and tryAcquire() will not throw Interrupted_Exceptions.
   *
   * @see Mutex
   *
   * <b>Scheduling</b>
   *
   * Scheduling is left to the operating systems and may vary.
   *
   * <b>Error Checking</b>
   *
   * No error checking is performed, this means there is the potential for deadlock.
   */
  class ZTHREAD_API FastMutex : public Lockable, private NonCopyable {

    FastLock* _lock;

  public:

    //! Create a FastMutex
    FastMutex();

    //! Destroy a FastMutex
    virtual ~FastMutex();

    /**
     * Acquire exclusive access to the mutex. The calling thread will block until the
     * lock can be acquired. No safety or state checks are performed.
     *
     * @pre The calling thread should <i>not</i> have previously acquired this lock.
     *      Deadlock will result if the same thread attempts to acquire the mutex more
     *      than once.
     *
     * @post The calling thread obtains the lock successfully if no exception is thrown.
     * @exception Interrupted_Exception never thrown
     */
    virtual void acquire();

    /**
     * Release exclusive access. No safety or state checks are performed.
     *
     * @pre the caller should have previously acquired this lock
     */
    virtual void release();

    /**
     * Try to acquire exclusive access to the mutex. The calling thread will block until the
     * lock can be acquired. No safety or state checks are performed.
     *
     * @pre The calling thread should <i>not</i> have previously acquired this lock.
     *      Deadlock will result if the same thread attempts to acquire the mutex more
     *      than once.
     *
     * @param timeout unused
     * @return
     * - <em>true</em> if the lock was acquired
     * - <em>false</em> if the lock was acquired
     *
     * @post The calling thread obtains the lock successfully if no exception is thrown.
     * @exception Interrupted_Exception never thrown
     */
    virtual bool tryAcquire(unsigned long timeout);

  }; /* FastMutex */

};

#endif // __ZTFASTMUTEX_H__

