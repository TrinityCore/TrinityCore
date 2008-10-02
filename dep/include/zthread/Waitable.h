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

#ifndef __ZTWAITABLE_H__
#define __ZTWAITABLE_H__

#include "zthread/Exceptions.h"

namespace ZThread { 

  /**
   * @class Waitable
   *
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T22:16:41-0400>
   * @version 2.3.0
   *
   * The Waitable interface defines a common method of adding generic <i>wait</i> semantics
   * to a class. 
   *
   * <b>Waiting</b>
   *
   * An object implementing the Waitable interface externalizes a mechanism for testing
   * some internal condition. Another object may <i>wait()</i>s for a Waitable object; 
   * in doing so, it wait()s for that condition to become true by blocking the caller 
   * while the condition is false.
   *
   * For example, a Condition is Waitable object that extends <i>wait</i> semantics
   * so that wait()ing means a thread is blocked until some external stimulus 
   * specifically performs an operation on the Condition to make its internal condition true. 
   * (serialization aside)
   *
   * A Barrier extends <i>wait</i> semantics so that wait()ing mean waiting for other 
   * waiters, and may include automatically resetting the condition once a wait is complete.
   *
   * @see Condition
   * @see Barrier
   * @see Executor
   */
  class Waitable {
  public:  
  
    //! Destroy a Waitable object.  
    virtual ~Waitable() {}

    /**
     * Waiting on an object will generally cause the calling thread to be blocked
     * for some indefinite period of time. The thread executing will not proceed
     * any further until the Waitable object releases it unless or an exception
     * is thrown.
     */
    virtual void wait() = 0;

    /**
     * Waiting on an object will generally cause the calling thread to be blocked
     * for some indefinite period of time. The thread executing will not proceed
     * any further until the Waitable object releases it unless or an exception
     * is thrown.
     *
     * @param timeout maximum amount of time, in milliseconds, to spend waiting.
     *
     * @return 
     *   - <em>true</em> if the set of tasks being wait for complete before 
     *                   <i>timeout</i> milliseconds elapse.
     *   - <em>false</em> othewise.
     */
    virtual bool wait(unsigned long timeout) = 0;

  
  }; /* Waitable */


} // namespace ZThread

#endif //  __ZTWAITABLE_H__
