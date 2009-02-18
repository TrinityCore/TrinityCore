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

#ifndef __ZTATOMICCOUNT_H__
#define __ZTATOMICCOUNT_H__

#include <cstdlib>

#include "zthread/Config.h"
#include "zthread/NonCopyable.h"

namespace ZThread {

  /**
   * @class AtomicCount
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T09:41:55-0400>
   * @version 2.3.0
   *
   * This class provides an interface to a small integer whose value can be
   * incremented or decremented atomically. It's designed to be as simple and
   * lightweight as possible so that it can be used cheaply to create reference
   * counts.
   */
  class ZTHREAD_API AtomicCount : public NonCopyable {

    void* _value;

  public:

    //! Create a new AtomicCount, initialized to a value of 1
    AtomicCount();

    //! Destroy a new AtomicCount
    ~AtomicCount();

    //! Postfix decrement and return the current value
    size_t operator--(int);

    //! Postfix increment and return the current value
    size_t operator++(int);

    //! Prefix decrement and return the current value
    size_t operator--();

    //! Prefix increment and return the current value
    size_t operator++();


  }; /* AtomicCount */


} // namespace ZThread

#endif // __ZTATOMICCOUNT_H__

