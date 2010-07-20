// -*- C++ -*-

//=============================================================================
/**
 *  @file    Task.h
 *
 *  $Id: Task.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_TASK_H
#define ACE_TASK_H
#include /**/ "ace/pre.h"

#include "ace/Service_Object.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Thread_Manager.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Task_Flags
 *
 * @brief These flags are used within the ACE_Task.
 *
 *    These flags should be hidden within ACE_Task.  Unfortunately, the
 *    HP/UX C++ compiler can't grok this...  Fortunately, there's no
 *    code defined here, so we don't have to worry about multiple
 *    definitions.
 */
namespace ACE_Task_Flags
{
  enum
  {
    /// Identifies a Task as being the "reader" in a Module.
    ACE_READER     = 01,
    /// Just flush data messages in the queue.
    ACE_FLUSHDATA  = 02,
    /// Flush all messages in the Queue.
    ACE_FLUSHALL   = 04,
    /// Flush read queue
    ACE_FLUSHR     = 010,
    /// Flush write queue
    ACE_FLUSHW     = 020,
    /// Flush both queues
    ACE_FLUSHRW    = 030
  };
}

/**
 * @class ACE_Task_Base
 *
 * @brief Direct base class for the ACE_Task template.
 *
 * This class factors out the non-template code in order to
 * reduce template bloat, as well as to make it possible for the
 * ACE_Thread_Manager to store ACE_Task_Base *'s
 * polymorphically.
 */
class ACE_Export ACE_Task_Base : public ACE_Service_Object
{
public:
  // = Initialization and termination methods.
  /// Constructor.
  ACE_Task_Base (ACE_Thread_Manager * = 0);

  /// Destructor.
  virtual ~ACE_Task_Base (void);

  // = Initialization and termination hooks.

  // These methods should be overridden by subclasses if you'd like to
  // provide <Task>-specific initialization and termination behavior.

  /// Hook called to initialize a task and prepare it for execution.
  /// @a args can be used to pass arbitrary information into <open>.
  virtual int open (void *args = 0);

  /**
   * Hook called from ACE_Thread_Exit when during thread exit and from
   * the default implementation of <module_closed>.  In general, this
   * method shouldn't be called directly by an application,
   * particularly if the <Task> is running as an Active Object.
   * Instead, a special message should be passed into the <Task> via
   * the <put> method defined below, and the <svc> method should
   * interpret this as a flag to shut down the <Task>.
   */
  virtual int close (u_long flags = 0);

  /**
   * Hook called during <ACE_Module::close>.  The default
   * implementation calls forwards the call to close(1).  Please
   * notice the changed value of the default argument of <close>.
   * This allows tasks to differ between the call has been originated
   * from <ACE_Thread_Exit> or from <module_closed>.  Be aware that
   * close(0) will be also called when a thread associated with the
   * ACE_Task instance exits.
   */
  virtual int module_closed (void);

  // = Immediate and deferred processing methods, respectively.

  // These methods should be overridden by subclasses if you'd like to
  // provide <Task>-specific message processing behavior.

  /// A hook method that can be used to pass a message to a
  /// task, where it can be processed immediately or queued for subsequent
  /// processing in the <svc> hook method.
  virtual int put (ACE_Message_Block *, ACE_Time_Value * = 0);

  /// Run by a daemon thread to handle deferred processing.
  virtual int svc (void);

  // = Active object activation method.
  /**
   * Turn the task into an active object, i.e., having @a n_threads of
   * control, all running at the @a priority level (see below) with the
   * same @a grp_id, all of which invoke <Task::svc>.  Returns -1 if
   * failure occurs, returns 1 if Task is already an active object and
   * @a force_active is false (i.e., do *not* create a new thread in
   * this case), and returns 0 if Task was not already an active
   * object and a thread is created successfully or thread is an
   * active object and @a force_active is true.  Note that if
   * @a force_active is true and there are already threads spawned in
   * this <Task>, the @a grp_id parameter is ignored and the @a grp_id
   * of any newly activated thread(s) will inherit the existing
   * @a grp_id of the existing thread(s) in the <Task>.
   *
   * The <{flags}> are a bitwise-OR of the following:
   * = BEGIN<INDENT>
   * THR_CANCEL_DISABLE, THR_CANCEL_ENABLE, THR_CANCEL_DEFERRED,
   * THR_CANCEL_ASYNCHRONOUS, THR_BOUND, THR_NEW_LWP, THR_DETACHED,
   * THR_SUSPENDED, THR_DAEMON, THR_JOINABLE, THR_SCHED_FIFO,
   * THR_SCHED_RR, THR_SCHED_DEFAULT, THR_EXPLICIT_SCHED,
   * THR_SCOPE_SYSTEM, THR_SCOPE_PROCESS
   * = END<INDENT>
   * If THR_SCHED_INHERIT is not desirable, applications should
   * specifically pass in THR_EXPLICIT_SCHED.
   *
   *
   * By default, or if <{priority}> is set to
   * ACE_DEFAULT_THREAD_PRIORITY, an "appropriate" priority value for
   * the given scheduling policy (specified in <{flags}>, e.g.,
   * <THR_SCHED_DEFAULT>) is used.  This value is calculated
   * dynamically, and is the median value between the minimum and
   * maximum priority values for the given policy.  If an explicit
   * value is given, it is used.  Note that actual priority values are
   * EXTREMEMLY implementation-dependent, and are probably best
   * avoided.
   *
   * If @a thread_handles != 0 it is assumed to be an array of @a n
   * thread_handles that will be assigned the values of the thread
   * handles being spawned.  Returns -1 on failure (@c errno will
   * explain...), otherwise returns the group id of the threads.
   *
   * Assigning @a task allows you to associate the newly spawned
   * threads with an instance of ACE_Task_Base.  If @a task == 0, then
   * the new threads are associated automatically with @c this
   * ACE_Task_Base.  Setting the @a task argument to value other than
   * @c this makes the thread manipulating methods, such as wait(),
   * suspend(), resume(), useless.  Threads spawned with user
   * specified @a task value must therefore be manipulated thru
   * ACE_Thread_Manager directly.
   *
   * If @a stack != 0 it is assumed to be an array of @a n pointers to
   * the base of the stacks to use for the threads being spawned.
   * Likewise, if @a stack_size != 0 it is assumed to be an array of
   * @a n values indicating how big each of the corresponding @a stacks
   * are.
   *
   *
   */
  virtual int activate (long flags = THR_NEW_LWP | THR_JOINABLE | THR_INHERIT_SCHED,
                        int n_threads = 1,
                        int force_active = 0,
                        long priority = ACE_DEFAULT_THREAD_PRIORITY,
                        int grp_id = -1,
                        ACE_Task_Base *task = 0,
                        ACE_hthread_t thread_handles[] = 0,
                        void *stack[] = 0,
                        size_t stack_size[] = 0,
                        ACE_thread_t thread_ids[] = 0,
                        const char* thr_name[] = 0);

  /**
   * Block until there are no more threads running in this task.
   * This method will not wait for either detached or daemon threads;
   * the threads must have been spawned with the @c THR_JOINABLE flag.
   * Upon successful completion, the threads have been joined, so further
   * attempts to join with any of the waited-for threads will fail.
   *
   * @retval 0  Success.
   * @retval -1 Failure (consult errno for further information).
   */
  virtual int wait (void);

  // = Suspend/resume a Task.

  // Note that these methods are not portable and should be avoided
  // since they are inherently error-prone to use.  They are only here
  // for (the rare) applications that know how to use them correctly.
  /// Suspend a task.
  virtual int suspend (void);
  /// Resume a suspended task.
  virtual int resume (void);

  /// Get the current group id.
  int grp_id (void) const;

  /// Set the current group id.
  void grp_id (int);

  /// Get the thread manager associated with this Task.
  ACE_Thread_Manager *thr_mgr (void) const;

  /// Set the thread manager associated with this Task.
  void thr_mgr (ACE_Thread_Manager *);

  /// True if queue is a reader, else false.
  int is_reader (void) const;

  /// True if queue is a writer, else false.
  int is_writer (void) const;

  /**
   * Returns the number of threads currently running within a task.
   * If we're a passive object this value is 0, else it's greater than
   * 0.
   */
  size_t thr_count (void) const;

  /**
   * Returns the thread ID of the thread whose exit caused this object's
   * thread count to be decremented to 0.
   *
   * When a thread spawned in the context of this object (using activate())
   * returns from its svc() method ACE calls the close() hook. Before it does
   * so, it decrements the number of active threads. If the number of threads
   * is decremented to 0, the thread ID of the current thread is stored for
   * access by this method. If the returned thread ID matches the calling
   * thread's ID, the calling thread knows that there are no other threads
   * still active in the ACE_Task.
   *
   * @retval  ACE_thread_t of the last thread to close. 0 if the last thread
   *          is not yet known; for example, if no threads are active, or if
   *          multiple threads are active.
   */
  ACE_thread_t last_thread (void) const;

  /// Routine that runs the service routine as a daemon thread.
  static ACE_THR_FUNC_RETURN svc_run (void *);

  /// Cleanup hook that is called when a thread exits to gracefully
  /// shutdown an ACE_Task.
  static void cleanup (void *object, void *params);

protected:
  /**
   * Count of the number of threads running within the task.  If this
   * value is greater than 0 then we're an active object and the value
   * of <thr_count_> is the number of active threads at this instant.
   * If the value == 0, then we're a passive object.
   */
  size_t thr_count_;

  /// Multi-threading manager.
  ACE_Thread_Manager *thr_mgr_;

  /// ACE_Task flags.
  u_long flags_;

  /// This maintains the group id of the Task.
  int grp_id_;

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  /// Protect the state of a Task during concurrent operations, but
  /// only if we're configured as MT safe...
  ACE_Thread_Mutex lock_;
#endif /* ACE_MT_SAFE */

  /// Holds the thread ID of the last thread to exit svc() in this object.
  ACE_thread_t  last_thread_id_;

private:

  // = Disallow these operations.
  ACE_Task_Base &operator= (const ACE_Task_Base &);
  ACE_Task_Base (const ACE_Task_Base &);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Task.inl"
#endif /* __ACE_INLINE__ */

// Include the ACE_Task templates classes at this point.
#include "ace/Task_T.h"

#include /**/ "ace/post.h"
#endif /* ACE_TASK_H */
