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

#ifndef __ZTREADWRITELOCK_H__
#define __ZTREADWRITELOCK_H__

#include "zthread/Lockable.h"
#include "zthread/NonCopyable.h"

namespace ZThread {
  
  /**
   * @class ReadWriteLock
   * 
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T10:17:31-0400>
   * @version 2.2.7
   *
   * A ReadWriteLock provides a set of coordinated Lockable objects that can be used to
   * guard an object; One for read-only access, and another for read-write access.
   *
   * @see BiasedReadWriteLock
   * @see FairReadWriteLock
   */  
  class ReadWriteLock : public NonCopyable {
  public:

    /**
     * Create a ReadWriteLock
     *
     * @exception Initialization_Exception thrown if resources could not be 
     *            allocated for this object.
     */
    ReadWriteLock() {}
  
    //! Destroy this ReadWriteLock
    virtual ~ReadWriteLock() {} 
  
    /**
     * Get a reference to the read-only Lockable.
     *
     * @return <em>Lockable&</em> reference to a Lockable that provides read-only
     *         access.
     */
    virtual Lockable& getReadLock() = 0;

    /**
     * Get a reference to the read-write Lockable.
     *
     * @return <em>Lockable&</em> reference to a Lockable that provides read-write
     *         access.
     */
    virtual Lockable& getWriteLock() = 0;

      
  }; /* ReadWriteLock */


}; // __ZTREADWRITELOCK_H__

#endif
