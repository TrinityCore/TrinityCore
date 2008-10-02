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

#include "zthread/PriorityMutex.h"
#include "MutexImpl.h"
#include "ThreadOps.h"


namespace ZThread {

  class PriorityMutexImpl : public MutexImpl<priority_list, NullBehavior> { };

  PriorityMutex::PriorityMutex() { 
  
    _impl = new PriorityMutexImpl();
  
  }

  PriorityMutex::~PriorityMutex() {

    if(_impl != 0) 
      delete _impl;

  }

  // P
  void PriorityMutex::acquire() {

    _impl->acquire(); 

  }


  // P
  bool PriorityMutex::tryAcquire(unsigned long ms) {

    return _impl->tryAcquire(ms); 

  }

  // V
  void PriorityMutex::release() {

    _impl->release(); 

  }


} // namespace ZThread

