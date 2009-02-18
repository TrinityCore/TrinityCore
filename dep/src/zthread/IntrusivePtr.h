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

#ifndef __ZTINTRUSIVEPTR_H__
#define __ZTINTRUSIVEPTR_H__

#include "zthread/Guard.h"
#include <cstdlib>

namespace ZThread {

/**
 * @class IntrusivePtr
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T17:54:23-0400>
 * @version 2.2.0
 *
 * This template creates an intrusively reference counted object
 * an IntrusivePtr starts out with a 1 count, which is updated as references are
 * added and removed. When the reference count drops to 0, the
 * IntrusivePtr will delete itself.
 */
template <typename T, class LockType>
class IntrusivePtr : NonCopyable {

  //! Intrusive reference count
  size_t _count;

  //! Synchornization object
  LockType _lock;

public:

  /**
   * Create an IntrusivePtr with a count.
   */
  IntrusivePtr(size_t InitialCount=1) : _count(InitialCount) { }

  /**
   * Destroy an IntrusivePtr
   */
  virtual ~IntrusivePtr() {}

  /**
   * Add a reference to this object, it will take one more
   * call to delReference() for it to be deleted.
   */
  void addReference() {

    Guard<LockType, LockedScope> g(_lock);
    _count++;

  }

  /**
   * Remove a reference from this object, if the reference count
   * drops to 0 as a result, the object deletes itself.
   */
  void delReference() {

    bool result = false;

    {

      Guard<LockType, LockedScope> g(_lock);
      result = (--_count == 0);

    }

    if(result)
      delete this;

  }

};


};

#endif

