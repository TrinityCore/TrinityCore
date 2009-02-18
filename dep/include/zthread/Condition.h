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

#ifndef __ZTCONDITION_H__
#define __ZTCONDITION_H__

#include "zthread/Lockable.h"
#include "zthread/NonCopyable.h"
#include "zthread/Waitable.h"

namespace ZThread {

  class FifoConditionImpl;

  /**
   * @class Condition
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T14:38:59-0400>
   * @version 2.2.1
   *
   * A Condition is a Waitable object used to block a thread until a particular
   * condition is met. A Condition object is always used in conjunction with Lockable
   * object. This object should be a FastMutex, Mutex, PriorityMutex or PriorityInheritanceMutex.
   *
   * Condition objects are reminiscent of POSIX condition variables in several ways but
   * are slightly different.
   *
   * A Condition is <i>not</i> subject to spurious wakeup.
   *
   * Like all Waitable objects, Conditions are sensitive to Thread::interupt() which can
   * be used to prematurely end a wait().
   *
   * @see Thread::interupt()
   *
   * Before a wait() is performed on a Condition, the associated Lockable object should
   * have been acquire()ed. When the wait() begins, that Lockable object is release()d
   * (wait() will atomically begin the wait and unlock the Lockable).
   *
   * A thread blocked by wait() will remain so until an exception occurs, or until
   * the thread awakened by a signal() or broadcast(). When the thread resumes execution,
   * the associated Lockable is acquire()d before wait() returns.
   *
   * <b>Scheduling</b>
   *
   * Threads blocked on a Condition are resumed in FIFO order.
   */
  class ZTHREAD_API Condition : public Waitable, private NonCopyable {

    FifoConditionImpl* _impl;

  public:

    /**
     * Create a Condition associated with the given Lockable object.
     *
     * @param l Lockable object to associate with this Condition object.
     */
    Condition(Lockable& l);

    //! Destroy Condition object
    virtual ~Condition();

    /**
     * Wake <em>one</em> thread waiting on this Condition.
     *
     * The associated Lockable need not have been acquire when this function is
     * invoked.
     *
     * @post a waiting thread, if any exists, will be awakened.
     */
    void signal();

    /**
     * Wake <em>all</em> threads wait()ing on this Condition.
     *
     * The associated Lockable need not have been acquire when this function is
     * invoked.
     *
     * @post all wait()ing threads, if any exist, will be awakened.
     */
    void broadcast();

    /**
     * Wait for this Condition, blocking the calling thread until a signal or broadcast
     * is received.
     *
     * This operation atomically releases the associated Lockable and blocks the calling thread.
     *
     * @exception Interrupted_Exception thrown when the calling thread is interrupted.
     *            A thread may be interrupted at any time, prematurely ending any wait.
     *
     * @pre The thread calling this method must have first acquired the associated
     *      Lockable object.
     *
     * @post A thread that has resumed execution without exception (because of a signal(),
     *       broadcast() or exception) will have acquire()d the associated Lockable object
     *       before returning from a wait().
     *
     * @see Waitable::wait()
     */
    virtual void wait();

    /**
     * Wait for this Condition, blocking the calling thread until a signal or broadcast
     * is received.
     *
     * This operation atomically releases the associated Lockable and blocks the calling thread.
     *
     * @param timeout maximum amount of time (milliseconds) this method could block
     *
     * @return
     *   - <em>true</em> if the Condition receives a signal or broadcast before
     *                   <i>timeout</i> milliseconds elapse.
     *   - <em>false</em> otherwise.
     *
     * @exception Interrupted_Exception thrown when the calling thread is interrupted.
     *            A thread may be interrupted at any time, prematurely ending any wait.
     *
     * @pre The thread calling this method must have first acquired the associated
     *      Lockable object.
     *
     * @post A thread that has resumed execution without exception (because of a signal(),
     *       broadcast() or exception) will have acquire()d the associated Lockable object
     *       before returning from a wait().
     *
     * @see Waitable::wait(unsigned long timeout)
     */
    virtual bool wait(unsigned long timeout);


  };

} // namespace ZThread

#endif // __ZTCONDITION_H__

