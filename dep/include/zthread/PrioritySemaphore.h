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


#ifndef __ZTPRIORITYSEMAPHORE_H__
#define __ZTPRIORITYSEMAPHORE_H__

#include "zthread/Lockable.h"
#include "zthread/NonCopyable.h"

namespace ZThread {

  class PrioritySemaphoreImpl;

  /**
   * @class PrioritySemaphore
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T15:36:07-0400>
   * @version 2.2.1
   *
   * A PrioritySemaphore operates in the same way as a Semaphore. Its an owner-less
   * Lockable object that is sensitive to priority.
   *
   * <b>Scheduling</b>
   *
   * Threads blocked on a PrioritySemaphore are resumed in priority order, highest
   * priority first.
   *
   * <b>Error Checking</b>
   *
   * An attempt to increase a PrioritySemaphore beyond its maximum value will result in
   * an InvalidOp_Exception.
   *
   * @see Semaphore
   */
  class ZTHREAD_API PrioritySemaphore : public Lockable, private NonCopyable {

    PrioritySemaphoreImpl* _impl;

  public:

    /**
     * @see Semaphore::Semaphore(int count, unsigned int maxCount)
     */
    PrioritySemaphore(int count = 1, unsigned int maxCount = 1);

    /**
     * @see Semaphore::~Semaphore()
     */
    virtual ~PrioritySemaphore();

    /**
     * @see Semaphore::wait()
     */
    void wait();

    /**
     * @see Semaphore::tryWait(unsigned long)
     */
    bool tryWait(unsigned long);

    /**
     * @see Semaphore::post()
     */
    void post();

    /**
     * @see Semaphore::count()
     */
    virtual int count();

    /**
     * @see Semaphore::tryAcquire(unsigned long timeout)
     */
    virtual bool tryAcquire(unsigned long timeout);

    /**
     * @see Semaphore::acquire()
     */
    virtual void acquire();

    /**
     * @see Semaphore::release()
     */
    virtual void release();

  };


} // namespace ZThread

#endif // __ZTPRIORITYSEMAPHORE_H__

