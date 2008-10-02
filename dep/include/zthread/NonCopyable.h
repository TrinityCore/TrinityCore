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

#ifndef __ZTNONCOPYABLE_H__
#define __ZTNONCOPYABLE_H__

namespace ZThread {

  /**
   * @class NonCopyable
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T19:36:00-0400>
   * @version 2.2.11
   *
   * Some objects kind of objects should not be copied. This is particularly true
   * of objects involved in providing mutually exclusive access to something
   * (e.g. Mutexes, Queues, Semaphores, etc.)
   *
   * Based on Dave Abrahams contribution to the Boost library.
   */
  class NonCopyable {

    //! Restrict the copy constructor
    NonCopyable(const NonCopyable&);

    //! Restrict the assignment operator
    const NonCopyable& operator=(const NonCopyable&);

  protected:

    //! Create a NonCopyable object
    NonCopyable() { }

    //! Destroy a NonCopyable object
    ~NonCopyable() { }

  }; /* NonCopyable */

} // namespace ZThread

#endif // __ZTNONCOPYABLE_H__
