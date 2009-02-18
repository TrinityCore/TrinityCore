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

#ifndef __ZTTHREADQUEUE_H__
#define __ZTTHREADQUEUE_H__

#include "zthread/Singleton.h"
#include "zthread/Guard.h"
#include "FastLock.h"


namespace ZThread {

  class ThreadImpl;

  /**
   * @class ThreadQueue
   * @version 2.3.0
   * @author Eric Crahen <http://www.code-foo.com>
   * @date <2003-07-27T20:52:05-0400>
   *
   * A ThreadQueue accumulates references to user and reference threads.
   * These are threads that are running outside the scope of the Thread
   * object that created them. ZThreads doesn't have a central manager for
   * all threads (partly why I renamed the ThreadManager to someting more
   * appropriate). Instead, ZThreads will discover threads it did not create
   * and create a reference thread that allows ZThreads to interact with it.
   * Non user threads that are created by the user never have to touch the
   * ThreadQueue.
   */
  class ThreadQueue : public Singleton<ThreadQueue, StaticInstantiation> {

    typedef std::deque<ThreadImpl*> ThreadList;
    typedef std::deque<Task> TaskList;

    //! Managed thread lists
    ThreadList _pendingThreads;
    ThreadList _referenceThreads;
    ThreadList _userThreads;

    //! Shutdown handlers
    TaskList   _shutdownTasks;

    //! Serilize access to the thread list
    FastLock _lock;

    //! Reference thread waiting to cleanup any user & reference threads
    ThreadImpl* _waiter;

  public:

    ThreadQueue();

    /**
     * The thread destroys a ThreadQueue will be a reference thread,
     * probably the main thread; but it could be another thread that
     * started and loaded the library.
     */
    ~ThreadQueue();

    /**
     * Insert a user-thread into the queue. User-threads are inserted as they
     * begin thier task. Once that task completes, user-threads are automatically
     * transitioned to pending-threads via <i>insertPendingThread()</i>.
     *
     * User-threads are known to be executing thier tasks and will be cancel()ed
     * as the ThreadQueue is destroyed when main() goes out of scope. This sends
     * a request to the task to complete soon. Once the task exits, the thread is
     * transitioned to pending-thread status.
     */
    void insertUserThread(ThreadImpl*);

    /**
     * Insert a pending-thread into the queue.
     *
     * Pending-threads are known to have completed thier tasks and thier
     * resources are reclaimed (lazily) as more threads are started or as the
     * ThreadQueue is destroyed.
     */
    void insertPendingThread(ThreadImpl*);


    /**
     * Insert reference thread. Reference threads are not removed until
     * the ThreadQueue goes out of scope.
     */
    void insertReferenceThread(ThreadImpl*);

    /**
     * Insert a task to be run before threads are joined.
     * Any items inserted after the ThreadQueue desctructor has begun to
     * execute will be run() immediately.
     */
    void insertShutdownTask(Task&);

    /**
     * Remove an existing shutdown task.
     */
    bool removeShutdownTask(const Task&);

  private:

    void pollPendingThreads();

    void pollUserThreads();

    void pollReferenceThreads();

  };


} // namespace ZThread


#endif  // __ZTTHREADQUEUE_H__

