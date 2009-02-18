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

#ifndef __ZTTHREAD_H__
#define __ZTTHREAD_H__

#include "zthread/Cancelable.h"
#include "zthread/Priority.h"
#include "zthread/NonCopyable.h"
#include "zthread/Task.h"
#include "zthread/Waitable.h"

namespace ZThread {

  class ThreadImpl;

  /**
   * @class Thread
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-27T11:17:59-0400>
   * @version 2.3.0
   *
   *
   * @see Task
   * @see Executor
   *
   * <h2>Examples</h2>
   * - <a href="#ex1">Launching a task</a>
   * - <a href="#ex2">Waiting for a task</a>
   * - <a href="#ex3">Sharing a task</a>
   *
   * <h2><a name="ex1">Launching a task</a></h2>
   *
   * A thread is started simply by constructing a thread object and giving
   * it a task to perform. The thread will continue to run its task, even
   * after the Thread object used to launch the thread has gone out of scope.
   *
   * @code
   * #include "zthread/Thread.h"
   * #include <iostream>
   *
   * using namespace ZThread;
   *
   * class aRunnable : public Runnable {
   *
   *   void run() {
   *
   *     Thread::sleep(1000);
   *     std::cout << "Hello from another thread" << std::endl;
   *
   *   }
   *
   * };
   *
   * int main() {
   *
   *   try {
   *
   *     // Implictly constructs a Task
   *     Thread t(new aRunnable);
   *
   *   } catch(Synchronization_Exception& e) {
   *     std::cerr << e.what() << std::endl;
   *   }
   *
   *   std::cout << "Hello from the main thread" << std::endl;
   *
   *   // Output:
   *
   *   // Hello from the main thread
   *   // Hello from another thread
   *
   *   return 0;
   *
   * }
   *
   * @endcode
   *
   * <h2><a name="ex2">Waiting for a task</a></h2>
   *
   * A user can exercise some simple synchronization by waiting for a thread
   * to complete running its task.
   *
   * @code
   * #include "zthread/Thread.h"
   * #include <iostream>
   *
   * using namespace ZThread;
   *
   * class aRunnable : public Runnable {
   * public:
   *
   *   void run() {
   *
   *     Thread::sleep(1000);
   *     std::cout << "Hello from another thread" << std::endl;
   *
   *   }
   *
   * };
   *
   * int main() {
   *
   *   try {
   *
   *     // Implictly constructs a Task
   *     Thread t(new aRunnable);
   *     t.wait();
   *
   *   } catch(Synchronization_Exception& e) {
   *     std::cerr << e.what() << std::endl;
   *   }
   *
   *   std::cout << "Hello from the main thread" << std::endl;
   *
   *   // Output:
   *
   *   // Hello from another thread
   *   // Hello from the main thread
   *
   *   return 0;
   *
   * }
   *
   * @endcode
   *
   * <h2><a name="ex3">Sharing a task</a></h2>
   *
   * The same task can be shared by more than one thread. A Task is constructed
   * from a Runnable, and that Task object is copied by value and handed off to
   * each thread.
   *
   * @code
   * #include "zthread/Thread.h"
   * #include <iostream>
   *
   * using namespace ZThread;
   *
   * class aRunnable : public Runnable {
   *
   *   void run() {
   *
   *     Thread::sleep(1000);
   *     std::cout << "Hello from another thread" << std::endl;
   *
   *   }
   *
   * };
   *
   * int main() {
   *
   *   try {
   *
   *     // Explictly constructs a Task
   *     Task task(new aRunnable);
   *
   *     // Two threads created to run the same Task
   *     Thread t1(task);
   *     Thread t2(task);
   *
   *   } catch(Synchronization_Exception& e) {
   *     std::cerr << e.what() << std::endl;
   *   }
   *
   *   std::cout << "Hello from the main thread" << std::endl;
   *
   *   // Output:
   *
   *   // Hello from the main thread
   *   // Hello from another thread
   *   // Hello from another thread
   *
   *   return 0;
   *
   * }
   *
   * @endcode
   */
  class ZTHREAD_API Thread
    : public Cancelable, public Waitable, public NonCopyable {

    //! Delegate
    ThreadImpl* _impl;

  public:

    /**
     * Create a Thread that represents the current thread.
     * <em>Using the static members of Thread should be preferred over using this constructor</em>
     */
    Thread();

    /**
     * Create a Thread that spawns a new thread to run the given task.
     *
     * @param task Task to be run by a thread managed by this executor
     * @param autoCancel flag to requestion automatic cancellation
     *
     * @post if the <i>autoCancel</i> flag was true, this thread will
     *       automatically be canceled when main() goes out of scope.
     */
    Thread(const Task&, bool autoCancel = false);

    //! Destroy the Thread
    ~Thread();

    //! Comparison operator
    bool operator==(const Thread& t) const;

    //! Comparison operator
    inline bool operator!=(const Thread& t) const {
      return !(*this == t);
    }

    /**
     * Wait for the thread represented by this object to complete its task.
     * The calling thread is blocked until the thread represented by this
     * object exits.
     *
     * @exception Deadlock_Exception thrown if thread attempts to join itself
     * @exception InvalidOp_Exception thrown if the thread cannot be joined
     * @exception Interrupted_Exception thrown if the joining thread has been interrupt()ed
     */
    void wait();

    /**
     * Wait for the thread represented by this object to complete its task.
     * The calling thread is blocked until the thread represented by this
     * object exits, or until the timeout expires.
     *
     * @param timeout maximum amount of time (milliseconds) this method
     *        could block the calling thread.
     *
     * @return
     *   - <em>true</em> if the thread task complete before <i>timeout</i>
     *     milliseconds elapse.
     *   - <em>false</em> othewise.
     *
     * @exception Deadlock_Exception thrown if thread attempts to join itself
     * @exception InvalidOp_Exception thrown if the thread cannot be joined
     * @exception Interrupted_Exception thrown if the joining thread has been interrupt()ed
     */
    bool wait(unsigned long timeout);

    /**
     * Change the priority of this Thread. This will change the actual
     * priority of the thread when the OS supports it.
     *
     * If there is no real priority support, it's simulated.
     *
     * @param p - new Priority
     */
    void setPriority(Priority p);

    /**
     * Get the priority of this Thread.
     *
     * @return Priority
     */
    Priority getPriority();

    /**
     * Interrupts this thread, setting the <i>interrupted</i> status of the thread.
     * This status is cleared by one of three methods.
     *
     * If this thread is blocked when this method is called, the thread will
     * abort that blocking operation with an Interrupted_Exception.
     *
     *  - The first is by attempting an operation on a synchronization object that
     *    would normally block the calling thread; Instead of blocking the calling
     *    the calling thread, the function that would normally block will thrown an
     *    Interrupted_Exception and clear the <i>interrupted</i> status of the thread.
     *
     *  - The second is by calling Thread::interrupted().
     *
     *  - The third is by calling Thread::canceled().
     *
     * Threads already blocked by an operation on a synchronization object will abort
     * that operation with an Interrupted_Exception, clearing the threads <i>interrupted</i>
     * status as in the first case described above.
     *
     * Interrupting a thread that is no longer running will have no effect.
     *
     * @return
     *   - <em>true</em> if the thread was interrupted while not blocked by a wait
     *     on a synchronization object.
     *   - <em>false</em> othewise.
     */
    bool interrupt();

    /**
     * Tests whether the current Thread has been interrupt()ed, clearing
     * its interruption status.
     *
     * @return
     *   - <em>true</em> if the Thread was interrupted.
     *   - <em>false</em> otherwise.
     *
     * @post The <i>interrupted</i> status of the current thread will be cleared,
     *       allowing it to perform a blocking operation on a synchronization
     *       object without throwing an exception.
     */
    static bool interrupted();

    /**
     * Tests whether the current Thread has been canceled, and clears the
     * interrupted status.
     *
     * @return bool true only if the Thread::cancel() has been invoked.
     */
    static bool canceled();

    /**
     * Tests whether this thread has been canceled. If called from the context
     * of this thread, the interrupted status is cleared.
     *
     * @return
     *   - <em>true</em> if the Thread was canceled.
     *   - <em>false</em> otherwise.
     *
     * @see Cancelable::isCanceled()
     */
    virtual bool isCanceled();

    /**
     * Interrupt and cancel this thread in a single operation. The thread will
     * return <em>true</em> whenever its cancelation status is tested in the future.
     *
     * @exception InvalidOp_Exception thrown if a thread attempts to cancel itself
     *
     * @see Thread::interrupt()
     * @see Cancelable::cancel()
     */
    virtual void cancel();

    /**
     * Put the currently executing thread to sleep for a given amount of
     * time.
     *
     * @param timeout maximum amount of time (milliseconds) this method could block
     *
     * @exception Interrupted_Exception thrown if the threads sleep is interrupted
     *            before <i>timeout</i> milliseconds expire.
     */
    static void sleep(unsigned long timeout);

    /**
     * Cause the currently executing thread to yield, allowing the scheduler
     * to assign some execution time to another thread.
     */
    static void yield();


  }; /* Thread */


} // namespace ZThread

#endif // __ZTTHREAD_H__




