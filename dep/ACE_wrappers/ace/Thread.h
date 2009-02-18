// -*- C++ -*-

//==========================================================================
/**
 *  @file    Thread.h
 *
 *  $Id: Thread.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_THREAD_H
#define ACE_THREAD_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/OS_NS_Thread.h"
#include "ace/Thread_Adapter.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

struct cancel_state
{
  /// e.g., PTHREAD_CANCEL_ENABLE, PTHREAD_CANCEL_DISABLE,
  /// PTHREAD_CANCELED.
  int cancelstate;

  /// e.g., PTHREAD_CANCEL_DEFERRED and PTHREAD_CANCEL_ASYNCHRONOUS.
  int canceltype;
};

/**
 * @class ACE_Thread
 *
 * @brief Provides a wrapper for threads.
 *
 * This class provides a common interface that is mapped onto
 * POSIX Pthreads, Solaris threads, Win32 threads, VxWorks
 * threads, or pSoS threads.  Note, however, that it is
 * generally a better idea to use the ACE_Thread_Manager
 * programming API rather than the <ACE_Thread> API since the
 * thread manager is more powerful.
 */
class ACE_Export ACE_Thread
{
public:
  /**
   * Creates a new thread having @a flags attributes and running @a func
   * with <args> (if <thread_adapter> is non-0 then @a func and <args>
   * are ignored and are obtained from <thread_adapter>).  <thr_id>
   * and <t_handle> are set to the thread's ID and handle (?),
   * respectively.  The thread runs at @a priority priority (see
   * below).
   *
   * The @a flags are a bitwise-OR of the following:
   * = BEGIN<INDENT>
   * THR_CANCEL_DISABLE, THR_CANCEL_ENABLE, THR_CANCEL_DEFERRED,
   * THR_CANCEL_ASYNCHRONOUS, THR_BOUND, THR_NEW_LWP, THR_DETACHED,
   * THR_SUSPENDED, THR_DAEMON, THR_JOINABLE, THR_SCHED_FIFO,
   * THR_SCHED_RR, THR_SCHED_DEFAULT, THR_EXPLICIT_SCHED,
   * THR_SCOPE_SYSTEM, THR_SCOPE_PROCESS
   * = END<INDENT>
   *
   * By default, or if @a priority is set to
   * ACE_DEFAULT_THREAD_PRIORITY, an "appropriate" priority value for
   * the given scheduling policy (specified in <flags}>, e.g.,
   * <THR_SCHED_DEFAULT>) is used.  This value is calculated
   * dynamically, and is the median value between the minimum and
   * maximum priority values for the given policy.  If an explicit
   * value is given, it is used.  Note that actual priority values are
   * EXTREMEMLY implementation-dependent, and are probably best
   * avoided.
   *
   * Note that <thread_adapter> is always deleted when <spawn>
   * is called, so it must be allocated with global operator new.
   */
  static int spawn (ACE_THR_FUNC func,
                    void *arg = 0,
                    long flags = THR_NEW_LWP | THR_JOINABLE,
                    ACE_thread_t *t_id = 0,
                    ACE_hthread_t *t_handle = 0,
                    long priority = ACE_DEFAULT_THREAD_PRIORITY,
                    void *stack = 0,
                    size_t stack_size = ACE_DEFAULT_THREAD_STACKSIZE,
                    ACE_Thread_Adapter *thread_adapter = 0,
                    const char** thr_name = 0);

  /**
   * Spawn N new threads, which execute @a func with argument @a arg (if
   * @a thread_adapter is non-0 then @a func and @a args are ignored and
   * are obtained from @a thread_adapter).  If @a stack != 0 it is
   * assumed to be an array of @a n pointers to the base of the stacks
   * to use for the threads being spawned.  Likewise, if @a stack_size
   * != 0 it is assumed to be an array of @a n values indicating how
   * big each of the corresponding @a stacks are.  Returns the number
   * of threads actually spawned (if this doesn't equal the number
   * requested then something has gone wrong and @c errno will
   * explain...).
   *
   * @see spawn()
   */
  static size_t spawn_n (size_t n,
                         ACE_THR_FUNC func,
                         void *arg = 0,
                         long flags = THR_NEW_LWP | THR_JOINABLE,
                         long priority = ACE_DEFAULT_THREAD_PRIORITY,
                         void *stack[] = 0,
                         size_t stack_size[] = 0,
                         ACE_Thread_Adapter *thread_adapter = 0,
                         const char* thr_name[] = 0);

  /**
   * Spawn @a n new threads, which execute @a func with argument @a arg
   * (if @a thread_adapter is non-0 then @a func and @a args are ignored
   * and are obtained from @a thread_adapter).  The thread_ids of
   * successfully spawned threads will be placed into the <thread_ids>
   * buffer (which must be the same size as @a n).  If @a stack != 0 it
   * is assumed to be an array of @a n pointers to the base of the
   * stacks to use for the threads being spawned.  If @a stack_size !=
   * 0 it is assumed to be an array of @a n values indicating how big
   * each of the corresponding @a stacks are.  If @a thread_handles != 0
   * it is assumed to be an array of @a n thread_handles that will be
   * assigned the values of the thread handles being spawned.  Returns
   * the number of threads actually spawned (if this doesn't equal the
   * number requested then something has gone wrong and @c errno will
   * explain...).
   *
   * @see spawn()
   */
  static size_t spawn_n (ACE_thread_t thread_ids[],
                         size_t n,
                         ACE_THR_FUNC func,
                         void *arg,
                         long flags,
                         long priority = ACE_DEFAULT_THREAD_PRIORITY,
                         void *stack[] = 0,
                         size_t stack_size[] = 0,
                         ACE_hthread_t thread_handles[] = 0,
                         ACE_Thread_Adapter *thread_adapter = 0,
                         const char* thr_name[] = 0);

  /**
   * Wait for one or more threads to exit and reap their exit status.
   * thr_join() returns successfully when the target thread terminates.
   *
   * @param thread_id is the ACE_thread_t ID of the thread to wait for.
   *                  If @a thread_id is 0, join() waits for any
   *                  undetached thread in the process to terminate
   *                  on platforms that support this capability
   *                  (for example, Solaris).
   * @param departed  points to a location that is set to the ID of the
   *                  terminated thread if join() returns successfully.
   *                  If @a departed is 0, it is ignored.
   * @param status    Points to the location that receives the joined
   *                  thread's exit value. If @a status is 0, it is ignored.
   *
   * @retval  0 for success
   * @retval  -1 (with errno set) for failure.
   */
  static int join (ACE_thread_t thread_id,
                   ACE_thread_t *departed,
                   ACE_THR_FUNC_RETURN *status);

  /// Wait for one thread to exit and reap its exit status.
  static int join (ACE_hthread_t,
                   ACE_THR_FUNC_RETURN * = 0);

  /// Continue the execution of a previously suspended thread.
  static int resume (ACE_hthread_t);

  /// Suspend the execution of a particular thread.
  static int suspend (ACE_hthread_t);

  /// Get the priority of a particular thread.
  static int getprio (ACE_hthread_t ht_id, int &priority);

  /// Get the priority and policy of a particular thread.
  static int getprio (ACE_hthread_t ht_id, int &priority, int &policy);

  /// Set the priority of a particular thread.
  static int setprio (ACE_hthread_t ht_id, int priority, int policy = -1);

  /// Send a signal to the thread.
  static int kill (ACE_thread_t, int signum);

  /// Yield the thread to another.
  static void yield (void);

  /**
   * Return the unique kernel handle of the thread.  Note that on
   * Win32 this is actually a pseudohandle, which cannot be shared
   * with other processes or waited on by threads.  To locate the real
   * handle, please use the ACE_Thread_Manager::thr_self() method.
   */
  static void self (ACE_hthread_t &t_handle);

  /// Return the unique ID of the thread.
  static ACE_thread_t self (void);

  /// Exit the current thread and return "status".
  /// Should _not_ be called by main thread.
  static void exit (ACE_THR_FUNC_RETURN status = 0);

  /// Get the LWP concurrency level of the process.
  static int getconcurrency (void);

  /// Set the LWP concurrency level of the process.
  static int setconcurrency (int new_level);

  /// Change and/or examine calling thread's signal mask.
  static int sigsetmask (int how,
                         const sigset_t *sigset,
                         sigset_t *osigset = 0);

  /**
   * Allocates a @a keyp that is used to identify data that is specific
   * to each thread in the process.  The key is global to all threads
   * in the process.
   */
  static int keycreate (ACE_thread_key_t *keyp,
#if defined (ACE_HAS_THR_C_DEST)
                        ACE_THR_C_DEST destructor,
#else
                        ACE_THR_DEST destructor,
#endif /* ACE_HAS_THR_C_DEST */
                        void * = 0);

  /// Free up the key so that other threads can reuse it.
  static int keyfree (ACE_thread_key_t key);

  /// Bind value to the thread-specific data key, @a key, for the calling
  /// thread.
  static int setspecific (ACE_thread_key_t key,
                          void *value);

  /// Stores the current value bound to @a key for the calling thread
  /// into the location pointed to by @a valuep.
  static int getspecific (ACE_thread_key_t key,
                          void **valuep);

  /// Disable thread cancellation.
  static int disablecancel (struct cancel_state *old_state);

  /// Enable thread cancellation.
  static int enablecancel (struct cancel_state *old_state,
                           int flag);

  /// Set the cancellation state.
  static int setcancelstate (struct cancel_state &new_state,
                             struct cancel_state *old_state);

  /**
   * Cancel a thread.
   * @note This method is only portable on platforms, such as POSIX pthreads,
   * that support thread cancellation.
   */
  static int cancel (ACE_thread_t t_id);

  /// Test the cancel.
  static void testcancel (void);

private:
  /// Ensure that we don't get instantiated.
  ACE_Thread (void);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Thread.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_THREAD_H */

