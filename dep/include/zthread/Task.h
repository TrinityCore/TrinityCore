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

#ifndef __ZTTASK_H__
#define __ZTTASK_H__

#include "zthread/CountedPtr.h"
#include "zthread/Runnable.h"

namespace ZThread {
  
  class ThreadImpl;
  
  /**
   * @class Task
   *
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-20T05:22:38-0400>
   * @version 2.3.0
   *
   * A Task provides a CountedPtr wrapper for Runnable objects. 
   * This wrapper enables an implicit conversion from a 
   * <i>Runnable*</i> to a <i>Task</i> adding some syntactic sugar 
   * to the interface.
   */
  class ZTHREAD_API Task : public CountedPtr<Runnable, AtomicCount> {
  public:


#if !defined(_MSC_VER) || (_MSC_VER > 1200)
	  
    Task(Runnable* raw)
      : CountedPtr<Runnable, AtomicCount>(raw) { } 

#endif
    
    template <typename U>
      Task(U* raw)
      : CountedPtr<Runnable, AtomicCount>(raw) { } 
    
    Task(const CountedPtr<Runnable, AtomicCount>& ptr) 
      : CountedPtr<Runnable, AtomicCount>(ptr) { } 
    
    template <typename U, typename V>
      Task(const CountedPtr<U, V>& ptr) 
      : CountedPtr<Runnable, AtomicCount>(ptr) { } 
    
    void operator()() {
      (*this)->run();
    }
    
  }; /* Task */
  
} // namespace ZThread

#endif // __ZTTASK_H__



