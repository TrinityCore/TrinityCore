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

#include "zthread/CountingSemaphore.h"
#include "SemaphoreImpl.h"

using namespace ZThread;

namespace ZThread {


  CountingSemaphore::CountingSemaphore(int initialCount) {

    _impl = new FifoSemaphoreImpl(initialCount, 0 , false);

  }


  CountingSemaphore::~CountingSemaphore() {

    try {

      if(_impl != 0)
        delete _impl;

    } catch(...) { }

  }


  void CountingSemaphore::wait() {
    _impl->acquire();
  }


  bool CountingSemaphore::tryWait(unsigned long ms) {

    return _impl->tryAcquire(ms);

  }


  void CountingSemaphore::post() {

    _impl->release();

  }

  int CountingSemaphore::count() {

    return _impl->count();

  }

  void CountingSemaphore::acquire() {

    _impl->acquire();

  }

  bool CountingSemaphore::tryAcquire(unsigned long ms) {

    return _impl->tryAcquire(ms);

  }

  void CountingSemaphore::release() {

    _impl->release();

  }

} // namespace ZThread
