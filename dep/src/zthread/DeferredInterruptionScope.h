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

#ifndef __ZTDEFERREDINTERRUPTIONSCOPE_H__
#define __ZTDEFERREDINTERRUPTIONSCOPE_H__

#include "ThreadImpl.h"
#include <cassert>

namespace ZThread {

/**
 * @class DeferredInterruptionScope
 * @author Eric Crahen <http://www.code-foo.com>
 * @date <2003-07-16T19:45:18-0400>
 * @version 2.3.0
 *
 * Locking policy for a Guard that will defer any state reported 
 * for the reported Status of a thread except SIGNALED until the 
 * scope has ended. This allows a Guard to be used to create an
 * uninterruptible region in code. 
 */
class DeferredInterruptionScope {
 public:
  
  template <class LockType>
  static void createScope(LockHolder<LockType>& l) {

    l.getLock().interest(Monitor::SIGNALED);

  }

  template <class LockType>
  static void destroyScope(LockHolder<LockType>& l) {

    l.getLock().interest(Monitor::ANYTHING);

  }

};

}

#endif // __ZTDEFERREDINTERRUPTIONSCOPE_H__
