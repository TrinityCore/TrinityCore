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

#ifndef __ZTFASTRECURSIVEMUTEX_H__
#define __ZTFASTRECURSIVEMUTEX_H__

#include "zthread/Lockable.h"
#include "zthread/NonCopyable.h"

namespace ZThread {

  class FastRecursiveLock;

  /**
   * @class FastRecursiveMutex
   *
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-19T19:00:25-0400>
   * @version 2.2.0
   *
   * A FastRecursiveMutex is a small fast implementation of a recursive, mutally exclusive
   * Lockable object. This implementation is a bit faster than the other Mutex classes
   * as it involved the least overhead. However, this slight increase in speed is 
   * gained by sacrificing the robustness provided by the other classes. 
   *
   * A FastRecursiveMutex has the useful property of not being interruptable; that is to say  
   * that acquire() and tryAcquire() will not throw Interrupted_Exceptions.
   *
   * @see RecursiveMutex
   *
   * <b>Scheduling</b>
   *
   * Scheduling is left to the operating systems and may vary.
   *
   * <b>Error Checking</b>
   *
   * No error checking is performed, this means there is the potential for deadlock.
   */ 
  class ZTHREAD_API FastRecursiveMutex : public Lockable, private NonCopyable {
    
    FastRecursiveLock* _lock;

  public:
  
    //! Create a new FastRecursiveMutex
    FastRecursiveMutex();

    //! Destroy this FastRecursiveMutex
    virtual ~FastRecursiveMutex();

    /**
     * Acquire exclusive access to the mutex. The calling thread will block until the 
     * lock can be acquired. No safety or state checks are performed. The calling thread
     * may acquire the mutex nore than once.
     *
     * @post The calling thread obtains the lock successfully if no exception is thrown.
     * @exception Interrupted_Exception never thrown
     */
    virtual void acquire();
  
    /**
     * Release access. No safety or state checks are performed.
     * 
     * @pre the caller should have previously acquired this lock at least once.
     */
    virtual void release();
  
    /**
     * Try to acquire exclusive access to the mutex. The calling thread will block until the 
     * lock can be acquired. No safety or state checks are performed. The calling thread
     * may acquire the mutex more than once.
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
  
  }; 

} // namespace ZThread

#endif // __ZTFASTRECURSIVEMUTEX_H__
