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

#ifndef __ZTMUTEX_H__
#define __ZTMUTEX_H__

#include "zthread/Lockable.h"
#include "zthread/NonCopyable.h"

namespace ZThread { 
  
  class FifoMutexImpl;

  /**
   * @class Mutex
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T19:35:28-0400>
   * @version 2.2.1
   *
   * A Mutex is used to provide serialized (one thread at a time) access to some portion
   * of code. This is accomplished by attempting to acquire the Mutex before entering that
   * piece of code, and by releasing the Mutex when leaving that region. It is a non-reentrant,
   * MUTual EXclusion Lockable object. 
   *
   * @see Guard
   *
   * <b>Scheduling</b>
   *
   * Threads competing to acquire() a Mutex are granted access in FIFO order.
   *
   * <b>Error Checking</b>
   *
   * A Mutex will throw a Deadlock_Exception if an attempt to acquire a Mutex more 
   * than once is made from the context of the same thread.
   *
   * A Mutex will throw an InvalidOp_Exception if an attempt to release a Mutex is 
   * made from the context of a thread that does not currently own that Mutex.
   */
  class ZTHREAD_API Mutex : public Lockable, private NonCopyable {
  
    FifoMutexImpl* _impl;
  
  public:

    //! Create a new Mutex.
    Mutex(); 

    //! Destroy this Mutex.
    virtual ~Mutex();
  
    /**
     * Acquire a Mutex, possibly blocking until either the current owner of the 
     * Mutex releases it or until an exception is thrown.
     *
     * Only one thread may acquire() the Mutex at any given time.
     *
     * @exception Interrupted_Exception thrown when the calling thread is interrupted.
     *            A thread may be interrupted at any time, prematurely ending any wait.
     * @exception Deadlock_Exception thrown when the same thread attempts to acquire
     *            a Mutex more than once, without having first release()ed it.
     *
     * @pre the calling thread must not have already acquired Mutex
     *
     * @post the calling thread successfully acquired Mutex only if no exception
     *       was thrown.
     *
     * @see Lockable::acquire()
     */
    virtual void acquire();

    /**
     * Acquire a Mutex, possibly blocking until the current owner of the 
     * Mutex releases it, until an exception is thrown or until the given amount
     * of time expires.
     *
     * Only one thread may acquire the Mutex at any given time.
     *
     * @param timeout maximum amount of time (milliseconds) this method could block
     * @return 
     * - <em>true</em> if the lock was acquired
     * - <em>false</em> if the lock was acquired
     *
     * @exception Interrupted_Exception thrown when the calling thread is interrupted.
     *            A thread may be interrupted at any time, prematurely ending any wait.
     * @exception Deadlock_Exception thrown when the same thread attempts to acquire
     *            a Mutex more than once, without having first released it.
     *
     * @pre the calling thread must not have already acquired Mutex
     *
     * @post the calling thread successfully acquired Mutex only if no exception
     *       was thrown.
     *
     * @see Lockable::tryAcquire(unsigned long timeout)
     */
    virtual bool tryAcquire(unsigned long timeout);
  
    /**
     * Release a Mutex allowing another thread to acquire it.
     *
     * @exception InvalidOp_Exception - thrown if there is an attempt to release is
     *            a Mutex that was not owner by the calling thread.
     *
     * @pre  the calling thread must have first acquired the Mutex.
     * @post the calling thread successfully released Mutex only if no exception
     *       was thrown.
     *
     * @see Lockable::release()
     */
    virtual void release();
  
  };


} // namespace ZThread

#endif // __ZTMUTEX_H__
