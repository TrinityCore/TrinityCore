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

#ifndef __ZTSEMAPHORE_H__
#define __ZTSEMAPHORE_H__

#include "zthread/Lockable.h"
#include "zthread/NonCopyable.h"

namespace ZThread {

  class FifoSemaphoreImpl;

  /**
   * @class Semaphore
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T15:28:01-0400>
   * @version 2.2.1
   *
   * A Semaphore is an owner-less Lockable object. Its probably best described as
   * a set of 'permits'. A Semaphore is initialized with an initial count and
   * a maximum count, these would correspond to the number of 'permits' currently
   * available and the number of' permits' in total.
   *
   * - Acquiring the Semaphore means taking a permit, but if there are none
   *   (the count is 0) the Semaphore will block the calling thread.
   *
   * - Releasing the Semaphore means returning a permit, unblocking a thread
   *   waiting for one.
   *
   * A Semaphore with an initial value of 1 and maximum value of 1 will act as
   * a Mutex.
   *
   * Threads blocked on a Semaphore are resumed in FIFO order.
   *
   */
  class ZTHREAD_API Semaphore : public Lockable, private NonCopyable {

    FifoSemaphoreImpl* _impl;

  public:

    /**
     * Create a new Semaphore.
     *
     * @param count initial count
     * @param maxCount maximum count
     */
    Semaphore(int count = 1, unsigned int maxCount = 1);

    //! Destroy the Semaphore
    virtual ~Semaphore();

    /**
     * <i>Provided to reflect the traditional Semaphore semantics</i>
     *
     * @see acquire()
     */
    void wait();


    /**
     * <i>Provided to reflect the traditional Semaphore semantics</i>
     *
     * @see tryAcquire(unsigned long timeout)
     */
    bool tryWait(unsigned long timeout);

    /**
     * <i>Provided to reflect the traditional Semaphore semantics</i>
     *
     * @see release()
     */
    void post();


    /**
     * Get the current count of the semaphore.
     *
     * This value may change immediately after this function returns to the calling thread.
     *
     * @return <em>int</em> count
     */
    virtual int count();

    /**
     * Decrement the count, blocking that calling thread if the count becomes 0 or
     * less than 0. The calling thread will remain blocked until the count is
     * raised above 0, an exception is thrown or the given amount of time expires.
     *
     * @param timeout maximum amount of time (milliseconds) this method could block
     *
     * @return
     *   - <em>true</em> if the Semaphore was acquired before <i>timeout</i> milliseconds elapse.
     *   - <em>false</em> otherwise.
     *
     * @exception Interrupted_Exception thrown when the calling thread is interrupted.
     *            A thread may be interrupted at any time, prematurely ending any wait.
     *
     * @see Lockable::tryAcquire(unsigned long timeout)
     */
    virtual bool tryAcquire(unsigned long timeout);


    /**
     * Decrement the count, blocking that calling thread if the count becomes 0 or
     * less than 0. The calling thread will remain blocked until the count is
     * raised above 0 or if an exception is thrown.
     *
     * @exception Interrupted_Exception thrown when the calling thread is interrupted.
     *            A thread may be interrupted at any time, prematurely ending any wait.
     *
     * @see Lockable::acquire()
     */
    virtual void acquire();

    /**
     * Increment the count, unblocking one thread if count is positive.
     *
     * @exception InvalidOp_Exception thrown if the maximum count would be exceeded.
     *
     * @see Lockable::release()
     */
    virtual void release();

  };


} // namespace ZThread

#endif // __ZTSEMAPHORE_H__

