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

#ifndef __ZTPRIORITYINHERITANCEMUTEX_H__
#define __ZTPRIORITYINHERITANCEMUTEX_H__

#include "zthread/Lockable.h"
#include "zthread/NonCopyable.h"

namespace ZThread {

  class PriorityInheritanceMutexImpl;

  /**
   * @class PriorityInheritanceMutex
   *
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T19:37:36-0400>
   * @version 2.2.1
   *
   * A PriorityInheritanceMutex is similar to a PriorityMutex, it is a non-reentrant,
   * priority sensitive MUTual EXclusion Lockable object. It differs only in its
   * scheduling policy.
   *
   * @see PriorityMutex
   *
   * <b>Scheduling</b>
   *
   * Threads competing to acquire() a PriorityInheritanceMutex are granted access in
   * order of priority. Threads with a higher priority will be given access first.
   *
   * When a higher priority thread tries to acquire() a PriorityInheritanceMutex and is
   * about to be blocked by a lower priority thread that has already acquire()d it, the
   * lower priority thread will temporarily have its effective priority raised to that
   * of the higher priority thread until it release()s the mutex; at which point its
   * previous priority will be restored.
   */
  class ZTHREAD_API PriorityInheritanceMutex : public Lockable, private NonCopyable {

    PriorityInheritanceMutexImpl* _impl;

  public:

    /**
     * @see Mutex::Mutex()
     */
    PriorityInheritanceMutex();

    /**
     * @see Mutex::~Mutex()
     */
    virtual ~PriorityInheritanceMutex();

    /**
     * @see Mutex::acquire()
     */
    virtual void acquire();

    /**
     * @see Mutex::tryAcquire(unsigned long timeout)
     */
    virtual bool tryAcquire(unsigned long timeout);

    /**
     * @see Mutex::release()
     */
    virtual void release();

  };


} // namespace ZThread

#endif // __ZTPRIORITYINHERITANCEMUTEX_H__

