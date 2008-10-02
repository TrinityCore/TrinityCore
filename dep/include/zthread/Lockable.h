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

#ifndef __ZTLOCKABLE_H__
#define __ZTLOCKABLE_H__

#include "zthread/Exceptions.h"

namespace ZThread { 

  /**
   * @class Lockable
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T10:33:32-0400>
   * @version 2.3.0
   *
   * The Lockable interface defines a common method of adding general <i>acquire-release</i> 
   * semantics to an object. An <i>acquire-release</i> protocol does not necessarily imply 
   * exclusive access. 
   */
  class Lockable {
  public:  
  
    //! Destroy a Lockable object.
    virtual ~Lockable() {}

    /** 
     * Acquire the Lockable object. 
     *
     * This method may or may not block the caller for an indefinite amount
     * of time. Those details are defined by specializations of this class.
     *
     * @exception Interrupted_Exception thrown if the calling thread is interrupted before
     *            the operation completes.
     *
     * @post The Lockable is acquired only if no exception was thrown. 
     */
    virtual void acquire() = 0;

    /** 
     * Attempt to acquire the Lockable object. 
     *
     * This method may or may not block the caller for a definite amount
     * of time. Those details are defined by specializations of this class;
     * however, this method includes a timeout value that can be used to 
     * limit the maximum amount of time that a specialization <i>could</i> block. 
     *
     * @param timeout - maximum amount of time (milliseconds) this method could block
     *
     * @return 
     *   - <em>true</em>  if the operation completes and the Lockable is acquired before 
     *     the timeout expires. 
     *   - <em>false</em> if the operation times out before the Lockable can be acquired.
     * 
     * @exception Interrupted_Exception thrown if the calling thread is interrupted before
     *            the operation completes.
     *
     * @post The Lockable is acquired only if no exception was thrown. 
     */
    virtual bool tryAcquire(unsigned long timeout) = 0;
  
    /** 
     * Release the Lockable object.
     *
     * This method may or may not block the caller for an indefinite amount
     * of time. Those details are defined by specializations of this class.
     *
     * @post The Lockable is released only if no exception was thrown. 
     */    
    virtual void release() = 0;

  };


} // namespace ZThread

#endif // __ZTLOCKABLE_H__
