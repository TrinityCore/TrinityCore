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

#ifndef __ZTRECURSIVEMUTEX_H__
#define __ZTRECURSIVEMUTEX_H__

#include "zthread/Lockable.h"
#include "zthread/NonCopyable.h"

namespace ZThread {

  class RecursiveMutexImpl;

  /**
   * @class RecursiveMutex
   *
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T17:51:33-0400>
   * @version 2.2.1
   *
   * A RecursiveMutex is a recursive, MUTual EXclusion Lockable object. It is
   * recursive because it can be acquire()d and release()d more than once
   * by the same thread, instead of causing a Deadlock_Exception.
   *
   * @see Mutex
   * @see Guard
   *
   * <b>Scheduling</b>
   *
   * Threads competing to acquire() a Mutex are granted access in FIFO order.
   *
   * <b>Error Checking</b>
   *
   * A Mutex will throw an InvalidOp_Exception if an attempt to release() a Mutex is
   * made from the context of a thread that does not currently own that Mutex.
   */
  class ZTHREAD_API RecursiveMutex : public Lockable, private NonCopyable {

    RecursiveMutexImpl* _impl;

  public:

    //! Create a new RecursiveMutex.
    RecursiveMutex();

    //! Destroy this RecursiveMutex.
    virtual ~RecursiveMutex();

    /**
     * Acquire a RecursiveMutex, possibly blocking until the the current owner of the
     * releases it or until an exception is thrown.
     *
     * Only one thread may acquire the RecursiveMutex at any given time.
     * The same thread may acquire a RecursiveMutex multiple times.
     *
     * @exception Interrupted_Exception thrown when the calling thread is interrupted.
     *            A thread may be interrupted at any time, prematurely ending any wait.
     *
     * @post the calling thread successfully acquire ed RecursiveMutex only if no exception
     *       was thrown.
     *
     * @see Lockable::acquire()
     */
    virtual void acquire();

    /**
     * Acquire a RecursiveMutex, possibly blocking until the the current owner
     * releases it, until an exception is thrown or until the given amount
     * of time expires.
     *
     * Only one thread may acquire the RecursiveMutex at any given time.
     * The same thread may acquire a RecursiveMutex multiple times.
     *
     * @param timeout maximum amount of time (milliseconds) this method could block
     * @return
     * - <em>true</em> if the lock was acquired
     * - <em>false</em> if the lock was acquired
     *
     * @exception Interrupted_Exception thrown when the calling thread is interrupted.
     *            A thread may be interrupted at any time, prematurely ending any wait.
     *
     * @post the calling thread successfully acquired RecursiveMutex only if no exception
     *       was thrown.
     *
     * @see Lockable::tryAcquire(unsigned long timeout)
     */
    virtual bool tryAcquire(unsigned long timeout);


    /**
     * Release exclusive access. No safety or state checks are performed.
     *
     * @pre This should not be called more times than the acquire() method was
     *      called.
     *
     * @see Lockable::release()
     */
    virtual void release();

  };

} // namespace ZThread

#endif // __ZTRECURSIVEMUTEX_H__

