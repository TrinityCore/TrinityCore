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


#ifndef __ZTRUNNABLE_H__
#define __ZTRUNNABLE_H__

#include "zthread/Config.h"

namespace ZThread {

  /**
   * @class Runnable
   * 
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T17:45:35-0400>
   * @version 2.2.11
   *
   * Encapsulates a Runnable task.
   */
  class Runnable {
  public:

    /**
     * Runnables should never throw in their destructors
     */
    virtual ~Runnable() {}

    /**
     * Task to be performed in another thread of execution
     */
    virtual void run() = 0;

  };
 

}

#endif // __ZTRUNNABLE_H__
