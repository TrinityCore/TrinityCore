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

#ifndef __ZTEXECUTOR_H__
#define __ZTEXECUTOR_H__

#include "zthread/Thread.h"
#include "zthread/Waitable.h"

namespace ZThread {

 
  /**
   * @class Executor
   *
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-16T22:39:39-0400>
   * @version 2.3.0
   *
   * Execeutors are an implementation of the Executor pattern. This is
   * a more versatile construct than a thread pool. A paper describing can
   * be found in the proceedings of the 2002 VikingPLOP conference.
   *
   * <b>Executing</b>
   * 
   * - <em>execute</em>()ing task with an Executor will submit the task, scheduling
   *   it for execution at some future time depending on the Executor being used.
   *
   * <b>Disabling</b>
   *
   * - <em>cancel</em>()ing an Executor will cause it to stop accepting 
   *   new tasks. 
   *
   * <b>Interrupting</b>
   *
   * - <em>interrupt</em>()ing an Executor will cause the any thread running 
   *   a task which was submitted prior to the invocation of this function to 
   *   be interrupted during the execution of that task.
   *
   * <b>Waiting</b>
   *
   * - <em>wait</em>()ing on a PoolExecutor will block the calling thread 
   *   until all tasks that were submitted prior to the invocation of this function
   *   have completed.
   * 
   * @see Cancelable
   * @see Waitable
   */
  class Executor : public Cancelable, public Waitable, private NonCopyable {
  public:

    /**
     * If supported by the Executor, interrupt all tasks submitted prior to 
     * the invocation of this function.
     */    
    virtual void interrupt() = 0;

    /**
     * Submit a task to this Executor. 
     *
     * @param task Task to be run by a thread managed by this executor 
     *
     * @pre  The Executor should have been canceled prior to this invocation.
     * @post The submitted task will be run at some point in the future by this Executor.
     *
     * @exception Cancellation_Exception thrown if the Executor was canceled prior to
     *            the invocation of this function.
     */
    virtual void execute(const Task& task) = 0;
  
  };

} // namespace ZThread

#endif // __ZTEXECUTOR_H__
