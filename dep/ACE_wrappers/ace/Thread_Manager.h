// -*- C++ -*-

//=============================================================================
/**
 *  @file    Thread_Manager.h
 *
 *  $Id: Thread_Manager.h 82588 2008-08-11 13:37:41Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_THREAD_MANAGER_H
#define ACE_THREAD_MANAGER_H
#include /**/ "ace/pre.h"

#include "ace/Thread.h"
#include "ace/Thread_Adapter.h"
#include "ace/Thread_Exit.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Condition_Thread_Mutex.h"
#include "ace/Unbounded_Queue.h"
#include "ace/Containers.h"
#include "ace/Free_List.h"
#include "ace/Singleton.h"
#include "ace/Log_Msg.h"
#include "ace/Synch_Traits.h"
#include "ace/Basic_Types.h"

// The following macros control how a Thread Manager manages a pool of
// Thread_Descriptor.  Currently, the default behavior is not to
// preallocate any thread descriptor and never (well, almost never)
// free up any thread descriptor until the Thread Manager gets
// destructed.  Which means, once your system is stable, you rarely
// need to pay the price of memory allocation.  On a deterministic
// system, which means, the number of threads spawned can be
// determined before hand, you can either redefine the memory pool
// size macros to suit your need or constructed the Thread_Manager
// accordingly.  That way, you don't pay the price of memory
// allocation when the system is really doing its job.  OTOH, on
// system with resources constraint, you may want to lower the size of
// ACE_DEFAULT_THREAD_MANAGER_HWM to avoid unused memory hanging
// around.

#if !defined (ACE_DEFAULT_THREAD_MANAGER_PREALLOC)
# define ACE_DEFAULT_THREAD_MANAGER_PREALLOC 0
#endif /* ACE_DEFAULT_THREAD_MANAGER_PREALLOC */

#if !defined (ACE_DEFAULT_THREAD_MANAGER_LWM)
# define ACE_DEFAULT_THREAD_MANAGER_LWM 1
#endif /* ACE_DEFAULT_THREAD_MANAGER_LWM */

#if !defined (ACE_DEFAULT_THREAD_MANAGER_INC)
# define ACE_DEFAULT_THREAD_MANAGER_INC 1
#endif /* ACE_DEFAULT_THREAD_MANAGER_INC */

#if !defined (ACE_DEFAULT_THREAD_MANAGER_HWM)
# define ACE_DEFAULT_THREAD_MANAGER_HWM ACE_DEFAULT_FREE_LIST_HWM
// this is a big number
#endif /* ACE_DEFAULT_THREAD_MANAGER_HWM */

// This is the synchronization mechanism used to prevent a thread
// descriptor gets removed from the Thread_Manager before it gets
// stash into it.  If you want to disable this feature (and risk of
// corrupting the freelist,) you define the lock as ACE_Null_Mutex.
// Usually, if you can be sure that your threads will run for an
// extended period of time, you can safely disable the lock.

#if !defined (ACE_DEFAULT_THREAD_MANAGER_LOCK)
# define ACE_DEFAULT_THREAD_MANAGER_LOCK ACE_SYNCH_MUTEX
#endif /* ACE_DEFAULT_THREAD_MANAGER_LOCK */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declarations.
class ACE_Task_Base;
class ACE_Thread_Manager;
class ACE_Thread_Descriptor;

/**
  * @class ACE_At_Thread_Exit
  *
  * @brief Contains a method to be applied when a thread is terminated.
  */
class ACE_Export ACE_At_Thread_Exit
{
  friend class ACE_Thread_Descriptor;
  friend class ACE_Thread_Manager;
public:
  /// Default constructor
  ACE_At_Thread_Exit (void);

  /// The destructor
  virtual ~ACE_At_Thread_Exit (void);

  /// At_Thread_Exit has the ownership?
  bool is_owner (void) const;

  /// Set the ownership of the At_Thread_Exit.
  bool is_owner (bool owner);

  /// This At_Thread_Exit was applied?
  bool was_applied (void) const;

  /// Set applied state of At_Thread_Exit.
  bool was_applied (bool applied);

protected:
  /// The next At_Thread_Exit hook in the list.
  ACE_At_Thread_Exit *next_;

  /// Do the apply if necessary
  void do_apply (void);

  /// The apply method.
  virtual void apply (void) = 0;

  /// The Thread_Descriptor where this at is registered.
  ACE_Thread_Descriptor* td_;

  /// The at was applied?
  bool was_applied_;

  /// The at has the ownership of this?
  bool is_owner_;
};

class ACE_Export ACE_At_Thread_Exit_Func : public ACE_At_Thread_Exit
{
public:
   /// Constructor
   ACE_At_Thread_Exit_Func (void *object,
                            ACE_CLEANUP_FUNC func,
                            void *param = 0);

  virtual ~ACE_At_Thread_Exit_Func (void);

protected:
   /// The object to be cleanup
   void *object_;

   /// The cleanup func
   ACE_CLEANUP_FUNC func_;

   /// A param if required
   void *param_;

   /// The apply method
   void apply (void);
};

/**
 * @class ACE_Thread_Descriptor_Base
 *
 * @brief Basic information for thread descriptors.  These information
 * gets extracted out because we need it after a thread is
 * terminated.
 *
 * @internal
 */
class ACE_Export ACE_Thread_Descriptor_Base : public ACE_OS_Thread_Descriptor
{

  friend class ACE_Thread_Manager;
  friend class ACE_Double_Linked_List<ACE_Thread_Descriptor_Base>;
  friend class ACE_Double_Linked_List_Iterator_Base<ACE_Thread_Descriptor_Base>;
  friend class ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor_Base>;
  friend class ACE_Double_Linked_List<ACE_Thread_Descriptor>;
  friend class ACE_Double_Linked_List_Iterator_Base<ACE_Thread_Descriptor>;
  friend class ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor>;
public:
  ACE_Thread_Descriptor_Base (void);
  ~ACE_Thread_Descriptor_Base (void);

  // = We need the following operators to make Borland happy.

  /// Equality operator.
  bool operator== (const ACE_Thread_Descriptor_Base &rhs) const;

  /// Inequality operator.
  bool operator!= (const ACE_Thread_Descriptor_Base &rhs) const;

  /// Group ID.
  int grp_id (void) const;

  /// Current state of the thread.
  ACE_UINT32 state (void) const;

  /// Return the pointer to an ACE_Task_Base or NULL if there's no
  /// ACE_Task_Base associated with this thread.;
  ACE_Task_Base *task (void) const;

protected:
  /// Reset this base thread descriptor.
  void reset (void);

  /// Unique thread ID.
  ACE_thread_t thr_id_;

  /// Unique handle to thread (used by Win32 and AIX).
  ACE_hthread_t thr_handle_;

  /// Group ID.
  int grp_id_;

  /// Current state of the thread.
  ACE_UINT32 thr_state_;

  /// Pointer to an ACE_Task_Base or NULL if there's no
  /// ACE_Task_Base.
  ACE_Task_Base *task_;

  /// We need these pointers to maintain the double-linked list in a
  /// thread managers.
  ACE_Thread_Descriptor_Base *next_;
  ACE_Thread_Descriptor_Base *prev_;
};

/**
 * @class ACE_Thread_Descriptor
 *
 * @brief Information for controlling threads that run under the control
 * of the <Thread_Manager>.
 */
class ACE_Export ACE_Thread_Descriptor : public ACE_Thread_Descriptor_Base
{
  friend class ACE_At_Thread_Exit;
  friend class ACE_Thread_Manager;
  friend class ACE_Double_Linked_List<ACE_Thread_Descriptor>;
  friend class ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor>;
public:
  // = Initialization method.
  ACE_Thread_Descriptor (void);

  // = Accessor methods.
  /// Unique thread id.
  ACE_thread_t self (void) const;

  /// Unique handle to thread (used by Win32 and AIX).
  void self (ACE_hthread_t &);

  /// Dump the state of an object.
  void dump (void) const;

  /**
   * This cleanup function must be called only for ACE_TSS_cleanup.
   * The ACE_TSS_cleanup delegate Log_Msg instance destruction when
   * Log_Msg cleanup is called before terminate.
   */
  void log_msg_cleanup(ACE_Log_Msg* log_msg);

  /**
   * Register an At_Thread_Exit hook and the ownership is acquire by
   * Thread_Descriptor, this is the usual case when the AT is dynamically
   * allocated.
   */
  int at_exit (ACE_At_Thread_Exit* cleanup);

  /// Register an At_Thread_Exit hook and the ownership is retained for the
  /// caller. Normally used when the at_exit hook is created in stack.
  int at_exit (ACE_At_Thread_Exit& cleanup);

  /**
   * Register an object (or array) for cleanup at thread termination.
   * "cleanup_hook" points to a (global, or static member) function
   * that is called for the object or array when it to be destroyed.
   * It may perform any necessary cleanup specific for that object or
   * its class.  "param" is passed as the second parameter to the
   * "cleanup_hook" function; the first parameter is the object (or
   * array) to be destroyed.  Returns 0 on success, non-zero on
   * failure: -1 if virtual memory is exhausted or 1 if the object (or
   * arrayt) had already been registered.
   */
  int at_exit (void *object,
               ACE_CLEANUP_FUNC cleanup_hook,
               void *param);

  /// Do nothing destructor to keep some compilers happy
  ~ACE_Thread_Descriptor (void);

  /**
   * Do nothing but to acquire the thread descriptor's lock and
   * release.  This will first check if the thread is registered or
   * not.  If it is already registered, there's no need to reacquire
   * the lock again.  This is used mainly to get newly spawned thread
   * in synch with thread manager and prevent it from accessing its
   * thread descriptor before it gets fully built.  This function is
   * only called from ACE_Log_Msg::thr_desc.
   */
  void acquire_release (void);
  void acquire (void);
  void release (void);

  /**
   * Set/get the @c next_ pointer.  These are required by the
   * ACE_Free_List.
   */
  void set_next (ACE_Thread_Descriptor *td);
  ACE_Thread_Descriptor *get_next (void) const;

private:
  /// Reset this thread descriptor.
  void reset (ACE_Thread_Manager *tm);

  /// Pop an At_Thread_Exit from at thread termination list, apply the at
  /// if apply is true.
  void at_pop (int apply = 1);

  /// Push an At_Thread_Exit to at thread termination list and set the
  /// ownership of at.
  void at_push (ACE_At_Thread_Exit* cleanup,
                bool is_owner = false);

  /// Run the AT_Thread_Exit hooks.
  void do_at_exit (void);

  /// Terminate realize the cleanup process to thread termination
  void terminate (void);

  /// Thread_Descriptor is the ownership of ACE_Log_Msg if log_msg_!=0
  /// This can occur because ACE_TSS_cleanup was executed before terminate.
  ACE_Log_Msg *log_msg_;

  /// The AT_Thread_Exit list
  ACE_At_Thread_Exit *at_exit_list_;

  /**
   * Stores the cleanup info for a thread.
   * @note This should be generalized to be a stack of ACE_Cleanup_Info's.
   */
  ACE_Cleanup_Info cleanup_info_;

  /// Pointer to an ACE_Thread_Manager or NULL if there's no
  /// ACE_Thread_Manager>
  ACE_Thread_Manager* tm_;

  /// Registration lock to prevent premature removal of thread descriptor.
  ACE_DEFAULT_THREAD_MANAGER_LOCK *sync_;

  /// Keep track of termination status.
  bool terminated_;
};

// Forward declaration.
class ACE_Thread_Control;

// This typedef should be (and used to be) inside the
// ACE_Thread_Manager declaration.  But, it caused compilation
// problems on g++/VxWorks/i960 with -g.  Note that
// ACE_Thread_Manager::THR_FUNC is only used internally in
// ACE_Thread_Manager, so it's not useful for anyone else.
// It also caused problems on IRIX5 with g++.
#if defined (__GNUG__)
typedef int (ACE_Thread_Manager::*ACE_THR_MEMBER_FUNC)(ACE_Thread_Descriptor *, int);
#endif /* __GNUG__ */

/**
 * @class ACE_Thread_Manager
 *
 * @brief Manages a pool of threads.
 *
 * This class allows operations on groups of threads atomically.
 * The default behavior of thread manager is to wait on
 * all threads under it's management when it gets destructed.
 * Therefore, remember to remove a thread from thread manager if
 * you don't want it to wait for the thread. There are also
 * functions to disable this default wait-on-exit behavior.
 * However, if your program depends on turning this off to run
 * correctly, you are probably doing something wrong.  Rule of
 * thumb, use ACE_Thread to manage your daemon threads.
 * Notice that if there're threads which live beyond the scope of
 * main(), you are sure to have resource leaks in your program.
 * Remember to wait on threads before exiting your main program if that
 * could happen in your programs.
 */
class ACE_Export ACE_Thread_Manager
{
public:
  friend class ACE_Thread_Control;

  // Allow ACE_THread_Exit to register the global TSS instance object.
  friend class ACE_Thread_Exit;
  friend class ACE_Thread_Descriptor;

#if !defined (__GNUG__)
  typedef int (ACE_Thread_Manager::*ACE_THR_MEMBER_FUNC)(ACE_Thread_Descriptor *, int);
#endif /* !__GNUG__ */

  /// These are the various states a thread managed by the
  /// ACE_Thread_Manager can be in.
  enum
  {
    /// Uninitialized.
    ACE_THR_IDLE = 0x00000000,

    /// Created but not yet running.
    ACE_THR_SPAWNED = 0x00000001,

    /// Thread is active (naturally, we don't know if it's actually
    /// *running* because we aren't the scheduler...).
    ACE_THR_RUNNING = 0x00000002,

    /// Thread is suspended.
    ACE_THR_SUSPENDED = 0x00000004,

    /// Thread has been cancelled (which is an indiction that it needs to
    /// terminate...).
    ACE_THR_CANCELLED = 0x00000008,

    /// Thread has shutdown, but the slot in the thread manager hasn't
    /// been reclaimed yet.
    ACE_THR_TERMINATED = 0x00000010,

    /// Join operation has been invoked on the thread by thread manager.
    ACE_THR_JOINING = 0x10000000
  };

  /**
   * @brief Initialization and termination methods.
   *
   * Internally, ACE_Thread_Manager keeps a freelist for caching
   * resources it uses to keep track of managed threads (not the
   * threads themselves.)  @a prealloc, @a lwm, @a inc, @hwm
   * determine the initial size, the low water mark, increment step,
   * and high water mark of the freelist.
   *
   * @sa ACE_Free_List
   */
  ACE_Thread_Manager (size_t preaolloc = ACE_DEFAULT_THREAD_MANAGER_PREALLOC,
                      size_t lwm = ACE_DEFAULT_THREAD_MANAGER_LWM,
                      size_t inc = ACE_DEFAULT_THREAD_MANAGER_INC,
                      size_t hwm = ACE_DEFAULT_THREAD_MANAGER_HWM);
  ~ACE_Thread_Manager (void);

#if ! defined (ACE_THREAD_MANAGER_LACKS_STATICS)
  /// Get pointer to a process-wide ACE_Thread_Manager.
  static ACE_Thread_Manager *instance (void);

  /// Set pointer to a process-wide ACE_Thread_Manager and return
  /// existing pointer.
  static ACE_Thread_Manager *instance (ACE_Thread_Manager *);

  /// Delete the dynamically allocated Singleton
  static void close_singleton (void);
#endif /* ! defined (ACE_THREAD_MANAGER_LACKS_STATICS) */

  /// No-op.  Currently unused.
  int open (size_t size = 0);

  /**
   * Release all resources.
   * By default, this method will wait until all threads exit.
   * However, when called from close_singleton(), most global resources
   * are destroyed and thus, close() does not try to wait; it simply cleans
   * up internal thread records (the thread descriptor list).
   */
  int close (void);

  /**
   * Create a new thread, which executes @a func with argument @a arg.
   *
   * @param func        The function that is called in the spawned thread.
   *
   * @param arg         The value passed to each spawned thread's @a func.
   *
   * @param flags       Flags to control attributes of the spawned threads.
   *                    @sa ACE_OS::thr_create() for descriptions of the
   *                    possible flags values and their interactions.
   *
   * @param t_id        Pointer to a location to receive the spawned thread's
   *                    ID. If 0, the ID is not returned.
   *
   * @param t_handle    Pointer to a location to receive the spawned thread's
   *                    thread handle. If 0, the handle is not returned.
   *
   * @param priority    The priority at which the thread is spawned.
   *
   * @param grp_id      The thread group that the spawned thread is
   *                    added to. If -1 is specified, a new thread group is
   *                    created for the spawned thread.
   *
   * @param stack       Pointers to the base of a pre-allocated stack space
   *                    for the thread's stack. If 0, the platform allocates
   *                    stack space for the thread. If a stack is specified,
   *                    it is recommended that @a stack_size also be supplied
   *                    to specify the size of the stack.
   *                    Not all platforms support pre-allocated stacks. If
   *                    @a stack is specified for a platform which does not
   *                    allow pre-allocated stack space this parameter is
   *                    ignored.
   *
   * @param stack_size  Indicate how large the thread's stack should be, in
   *                    bytes. If a pre-allocated stack pointer is passed in
   *                    @a stack, @a stack_size indicates the size of that
   *                    stack area. If no pre-allocated stack is passed,
   *                    the stack size specified is passed to the
   *                    operating system to request that it allocate a stack
   *                    of the specified size.
   *
   * @param thr_name    Pointer to a name to assign to the spawned thread.
   *                    This is only meaningful for platforms that have a
   *                    capacity to name threads (e.g., VxWorks and some
   *                    varieties of Pthreads). This argument is ignored if
   *                    specified as 0 and on platforms that do not have the
   *                    capability to name threads.
   *
   * @retval   -1 on failure; @c errno contains an error value.
   * @retval   The group id of the spawned thread.
   */
  int spawn (ACE_THR_FUNC func,
             void *arg = 0,
             long flags = THR_NEW_LWP | THR_JOINABLE | THR_INHERIT_SCHED,
             ACE_thread_t *t_id = 0,
             ACE_hthread_t *t_handle = 0,
             long priority = ACE_DEFAULT_THREAD_PRIORITY,
             int grp_id = -1,
             void *stack = 0,
             size_t stack_size = ACE_DEFAULT_THREAD_STACKSIZE,
             const char** thr_name = 0);

  /**
   * Spawn a specified number of threads, all of which execute @a func
   * with argument @a arg.
   *
   * @param n           The number of threads to spawn.
   *
   * @param func        The function that is called in the spawned thread.
   *
   * @param arg         The value passed to each spawned thread's @a func.
   *
   * @param flags       Flags to control attributes of the spawned threads.
   *                    @sa ACE_OS::thr_create() for descriptions of the
   *                    possible flags values and their interactions.
   *
   * @param priority    The priority at which the threads are spawned.
   *
   * @param grp_id      The thread group that the spawned threads are
   *                    added to. If -1 is specified, a new thread group is
   *                    created for the spawned threads.
   *
   * @param task        The ACE_Task that the spawned threads are associated
   *                    with. If 0, the threads are not associated with an
   *                    ACE_Task. This argument is usually assigned by the
   *                    ACE_Task_Base::activate() method to associate the
   *                    spawned threads with the spawning ACE_Task object.
   *
   * @param thread_handles An array of @a n entries which will receive
   *                    the thread handles of the spawned threads.
   *
   * @param stack       An array of @a n pointers to pre-allocated stack space
   *                    for each thread's stack. If specified as 0, the
   *                    platform allocates stack space for each thread. If
   *                    a stack is specified, it is recommended that a
   *                    @a stack_size element also be supplied that specifies
   *                    the size of the stack.
   *                    Not all platforms support pre-allocated stacks. If
   *                    @a stack is specified for a platform which does not
   *                    allow pre-allocated stack space this parameter is
   *                    ignored.
   *
   * @param stack_size  An array of @a n values which indicate how large
   *                    each thread's stack should be, in bytes.
   *                    If pre-allocated stacks are passed in @a stacks, these
   *                    sizes are for those stacks. If no pre-allocated stacks
   *                    are passed, the stack sizes are specified to the
   *                    operating system to request that it allocate stacks
   *                    of the specified sizes. If an array entry is 0, the
   *                    platform defaults are used for the corresponding thread.
   *                    If a 0 array pointer is specified, platform defaults
   *                    are used for all thread stack sizes.
   *
   * @param thr_name    An array of names to assign to the spawned threads.
   *                    This is only meaningful for platforms that have a
   *                    capacity to name threads (e.g., VxWorks and some
   *                    varieties of Pthreads). This argument is ignored if
   *                    specified as 0 and on platforms that do not have the
   *                    capability to name threads.
   *
   * ACE_Thread_Manager can manipulate threads in groups based on
   * @a grp_id or @a task using functions such as kill_grp() or
   * cancel_task().
   *
   * @retval   -1 on failure; @c errno contains an error value.
   * @retval   The group id of the threads.
   */
  int spawn_n (size_t n,
               ACE_THR_FUNC func,
               void *arg = 0,
               long flags = THR_NEW_LWP | THR_JOINABLE | THR_INHERIT_SCHED,
               long priority = ACE_DEFAULT_THREAD_PRIORITY,
               int grp_id = -1,
               ACE_Task_Base *task = 0,
               ACE_hthread_t thread_handles[] = 0,
               void *stack[] = 0,
               size_t stack_size[] = 0,
               const char* thr_name[] = 0);

  /**
   * Spawn a specified number of threads, all of which execute @a func
   * with argument @a arg.
   *
   * @param thread_ids  An array to receive the thread IDs of successfully
   *                    spawned buffer. If 0, the thread IDs are not returned.
   *                    If specified, the array must be at least @a n entries.
   *
   * @param n           The number of threads to spawn.
   *
   * @param func        The function that is called in the spawned thread.
   *
   * @param arg         The value passed to each spawned thread's @a func.
   *
   * @param flags       Flags to control attributes of the spawned threads.
   *                    @sa ACE_OS::thr_create() for descriptions of the
   *                    possible flags values and their interactions.
   *
   * @param priority    The priority at which the threads are spawned.
   *
   * @param grp_id      The thread group that the spawned threads are
   *                    added to. If -1 is specified, a new thread group is
   *                    created for the spawned threads.
   *
   * @param stack       An array of @a n pointers to pre-allocated stack space
   *                    for each thread's stack. If specified as 0, the
   *                    platform allocates stack space for each thread. If
   *                    a stack is specified, it is recommended that a
   *                    @a stack_size element also be supplied that specifies
   *                    the size of the stack.
   *                    Not all platforms support pre-allocated stacks. If
   *                    @a stack is specified for a platform which does not
   *                    allow pre-allocated stack space this parameter is
   *                    ignored.
   *
   * @param stack_size  An array of @a n values which indicate how large
   *                    each thread's stack should be, in bytes.
   *                    If pre-allocated stacks are passed in @a stacks, these
   *                    sizes are for those stacks. If no pre-allocated stacks
   *                    are passed, the stack sizes are specified to the
   *                    operating system to request that it allocate stacks
   *                    of the specified sizes. If an array entry is 0, the
   *                    platform defaults are used for the corresponding thread.
   *                    If a 0 array pointer is specified, platform defaults
   *                    are used for all thread stack sizes.
   *
   * @param thread_handles An array of @a n entries which will receive
   *                    the thread handles of the spawned threads.
   *
   * @param task        The ACE_Task that the spawned threads are associated
   *                    with. If 0, the threads are not associated with an
   *                    ACE_Task. This argument is usually assigned by the
   *                    ACE_Task_Base::activate() method to associate the
   *                    spawned threads with the spawning ACE_Task object.
   *
   * @param thr_name    An array of names to assign to the spawned threads.
   *                    This is only meaningful for platforms that have a
   *                    capacity to name threads (e.g., VxWorks and some
   *                    varieties of Pthreads). This argument is ignored if
   *                    specified as 0 and on platforms that do not have the
   *                    capability to name threads.
   *
   * ACE_Thread_Manager can manipulate threads in groups based on
   * @a grp_id or @a task using functions such as kill_grp() or
   * cancel_task().
   *
   * @retval   -1 on failure; @c errno contains an error value.
   * @retval   The group id of the threads.

   */
  int spawn_n (ACE_thread_t thread_ids[],
               size_t n,
               ACE_THR_FUNC func,
               void *arg,
               long flags,
               long priority = ACE_DEFAULT_THREAD_PRIORITY,
               int grp_id = -1,
               void *stack[] = 0,
               size_t stack_size[] = 0,
               ACE_hthread_t thread_handles[] = 0,
               ACE_Task_Base *task = 0,
               const char* thr_name[] = 0);

  /**
   * Called to clean up when a thread exits.
   *
   * @param do_thread_exit If non-0 then ACE_Thread::exit is called to
   *                       exit the thread
   * @param status         If ACE_Thread_Exit is called, this is passed as
   *                       the exit value of the thread.
   * Should _not_ be called by main thread.
   */
  ACE_THR_FUNC_RETURN exit (ACE_THR_FUNC_RETURN status = 0,
                            bool do_thread_exit = true);

  /**
   * Block until there are no more threads running in this thread
   * manager or @c timeout expires.
   *
   * @param timeout is treated as "absolute" time by default, but this
   *                can be changed to "relative" time by setting the @c
   *                use_absolute_time to false.
   * @param abandon_detached_threads If true, @c wait() will first
   *                                 check thru its thread list for
   *                                 threads with THR_DETACHED or
   *                                 THR_DAEMON flags set and remove
   *                                 these threads.  Notice that
   *                                 unlike other @c wait_*() methods,
   *                                 by default, @c wait() does wait on
   *                                 all thread spawned by this
   *                                 thread manager no matter the detached
   *                                 flags are set or not unless it is
   *                                 called with @c
   *                                 abandon_detached_threads flag set.
   * @param use_absolute_time If true then treat @c timeout as
   *                          absolute time, else relative time.
   * @return 0 on success * and -1 on failure.
   *
   * @note If this function is called while the @c
   * ACE_Object_Manager is shutting down (as a result of program
   * rundown via @c ACE::fini()), it will not wait for any threads to
   * complete. If you must wait for threads spawned by this thread
   * manager to complete and you are in a ACE rundown situation (such
   * as your object is being destroyed by the @c ACE_Object_Manager)
   * you can use @c wait_grp() instead.
   */
  int wait (const ACE_Time_Value *timeout = 0,
            bool abandon_detached_threads = false,
            bool use_absolute_time = true);

  /// Join a thread specified by @a tid.  Do not wait on a detached thread.
  int join (ACE_thread_t tid, ACE_THR_FUNC_RETURN *status = 0);

  /**
   * Block until there are no more threads running in a group.
   * Returns 0 on success and -1 on failure.  Notice that wait_grp
   * will not wait on detached threads.
   */
  int wait_grp (int grp_id);

  /**
   * Return the "real" handle to the calling thread, caching it if
   * necessary in TSS to speed up subsequent lookups. This is
   * necessary since on some platforms (e.g., Windows) we can't get this
   * handle via direct method calls.  Notice that you should *not*
   * close the handle passed back from this method.  It is used
   * internally by Thread Manager.  On the other hand, you *have to*
   * use this internal thread handle when working on Thread_Manager.
   * Return -1 if fail.
   */
  int thr_self (ACE_hthread_t &);

  /**
   * Return the unique ID of the calling thread.
   * Same as calling ACE_Thread::self().
   */
  ACE_thread_t thr_self (void);

  /**
   * Returns a pointer to the current ACE_Task_Base we're executing
   * in if this thread is indeed running in an ACE_Task_Base, else
   * return 0.
   */
  ACE_Task_Base *task (void);

  /**
   * @name Suspend and resume methods
   *
   * Suspend/resume is not supported on all platforms. For example, Pthreads
   * does not support these functions.
   */
  //@{

  /// Suspend all threads
  int suspend_all (void);

  /// Suspend a single thread.
  int suspend (ACE_thread_t);

  /// Suspend a group of threads.
  int suspend_grp (int grp_id);

  /**
   * True if @a t_id is inactive (i.e., suspended), else false.  Always
   * return false if @a t_id is not managed by the Thread_Manager.
   */
  int testsuspend (ACE_thread_t t_id);

  /// Resume all stopped threads
  int resume_all (void);

  /// Resume a single thread.
  int resume (ACE_thread_t);

  /// Resume a group of threads.
  int resume_grp (int grp_id);

  /**
   * True if @a t_id is active (i.e., resumed), else false.  Always
   * return false if @a t_id is not managed by the Thread_Manager.
   */
  int testresume (ACE_thread_t t_id);

  //@}

  // = Send signals to one or more threads without blocking.
  /**
   * Send @a signum to all stopped threads.  Not supported on platforms
   * that do not have advanced signal support, such as Win32.
   */
  int kill_all (int signum);
  /**
   * Send the @a signum to a single thread.  Not supported on platforms
   * that do not have advanced signal support, such as Win32.
   */
  int kill (ACE_thread_t, int signum);
  /**
   * Send @a signum to a group of threads, not supported on platforms
   * that do not have advanced signal support, such as Win32.
   */
  int kill_grp (int grp_id, int signum);

  // = Cancel methods, which provides a cooperative thread-termination mechanism (will not block).
  /**
   * Cancel's all the threads.
   */
  int cancel_all (int async_cancel = 0);

  /**
   * Cancel a single thread.
   */
  int cancel (ACE_thread_t, int async_cancel = 0);

  /**
   * Cancel a group of threads.
   */
  int cancel_grp (int grp_id, int async_cancel = 0);

  /**
   * True if @a t_id is cancelled, else false.  Always return false if
   * @a t_id is not managed by the Thread_Manager.
   */
  int testcancel (ACE_thread_t t_id);

  /**
   * True if @a t_id has terminated (i.e., is no longer running),
   * but the slot in the thread manager hasn't been reclaimed yet,
   * else false.  Always return false if @a t_id is not managed by the
   * Thread_Manager.
   */
  int testterminate (ACE_thread_t t_id);

  /// Set group ids for a particular thread id.
  int set_grp (ACE_thread_t,
               int grp_id);

  /// Get group ids for a particular thread id.
  int get_grp (ACE_thread_t,
               int &grp_id);

  /**
   * @name Task-related operations
   */
  //@{
  /**
   * Block until there are no more threads running in a specified task.
   * This method will not wait for either detached or daemon threads;
   * the threads must have been spawned with the @c THR_JOINABLE flag.
   * Upon successful completion, the threads have been joined, so further
   * attempts to join with any of the waited-for threads will fail.
   *
   * @param task  The ACE_Task_Base object whose threads are to waited for.
   *
   * @retval 0  Success.
   * @retval -1 Failure (consult errno for further information).
   */
  int wait_task (ACE_Task_Base *task);

  /**
   * Suspend all threads in an ACE_Task.
   */
  int suspend_task (ACE_Task_Base *task);

  /**
   * Resume all threads in an ACE_Task.
   */
  int resume_task (ACE_Task_Base *task);

  /**
   * Send a signal @a signum to all threads in an ACE_Task.
   */
  int kill_task (ACE_Task_Base *task, int signum);

  /**
   * Cancel all threads in an ACE_Task.  If <async_cancel> is non-0,
   * then asynchronously cancel these threads if the OS platform
   * supports cancellation.  Otherwise, perform a "cooperative"
   * cancellation.
   */
  int cancel_task (ACE_Task_Base *task, int async_cancel = 0);

  //@}

  // = Collect thread handles in the thread manager.  Notice that
  //   the collected information is just a snapshot.
  /// Check if the thread is managed by the thread manager.  Return true if
  /// the thread is found, false otherwise.
  int hthread_within (ACE_hthread_t handle);
  int thread_within (ACE_thread_t tid);

  /// Returns the number of ACE_Task_Base in a group.
  int num_tasks_in_group (int grp_id);

  /// Returns the number of threads in an ACE_Task_Base.
  int num_threads_in_task (ACE_Task_Base *task);

  /**
   * Returns a list of ACE_Task_Base pointers corresponding to the tasks
   * that have active threads in a specified thread group.
   *
   * @param grp_id    The thread group ID to obtain task pointers for.
   *
   * @param task_list is a pointer to an array to receive the list of pointers.
   *                  The caller is responsible for supplying an array with at
   *                  least @arg n entries.
   *
   * @param n         The maximum number of ACE_Task_Base pointers to write
   *                  in @arg task_list.
   *
   * @retval  If successful, the number of pointers returned, which will be
   *          no greater than @arg n. Returns -1 on error.
   *
   * @note    This method has no way to indicate if there are more than
   *          @arg n ACE_Task_Base pointers available. Therefore, it may be
   *          wise to guess a larger value of @arg n than one thinks in cases
   *          where the exact number of tasks is not known.
   *
   * @sa      num_tasks_in_group(), task_all_list()
   */
  ssize_t task_list (int grp_id,
                     ACE_Task_Base *task_list[],
                     size_t n);

  /**
   * Returns in @a thread_list a list of up to @a n thread ids in an
   * ACE_Task_Base.  The caller must allocate the memory for
   * @a thread_list.  In case of an error, -1 is returned. If no
   * requested values are found, 0 is returned, otherwise correct
   * number of retrieved values are returned.
   */
  ssize_t thread_list (ACE_Task_Base *task,
                       ACE_thread_t thread_list[],
                       size_t n);

  /**
   * Returns in @a hthread_list a list of up to @a n thread handles in
   * an ACE_Task_Base.  The caller must allocate memory for
   * @a hthread_list.  In case of an error, -1 is returned. If no
   * requested values are found, 0 is returned, otherwise correct
   * number of retrieved values are returned.
   */
  ssize_t hthread_list (ACE_Task_Base *task,
                        ACE_hthread_t hthread_list[],
                        size_t n);

  /**
   * Returns in @a thread_list a list of up to @a n thread ids in a
   * group @a grp_id.  The caller must allocate the memory for
   * @a thread_list.  In case of an error, -1 is returned. If no
   * requested values are found, 0 is returned, otherwise correct
   * number of retrieved values are returned.
   */
  ssize_t thread_grp_list (int grp_id,
                           ACE_thread_t thread_list[],
                           size_t n);

  /**
   * Returns in @a hthread_list a list of up to @a n thread handles in
   * a group @a grp_id.  The caller must allocate memory for
   * @a hthread_list.
   */
  ssize_t hthread_grp_list (int grp_id,
                            ACE_hthread_t hthread_list[],
                            size_t n);

  /**
   * Returns a list of ACE_Task_Base pointers corresponding to the tasks
   * that have active threads managed by this instance.
   *
   * @param task_list is a pointer to an array to receive the list of pointers.
   *                  The caller is responsible for supplying an array with at
   *                  least @arg n entries.
   *
   * @param n         The maximum number of ACE_Task_Base pointers to write
   *                  in @arg task_list.
   *
   * @retval  If successful, the number of pointers returned, which will be
   *          no greater than @arg n. Returns -1 on error.
   *
   * @note    This method has no way to indicate if there are more than
   *          @arg n ACE_Task_Base pointers available. Therefore, it may be
   *          wise to guess a larger value of @arg n than one thinks in cases
   *          where the exact number of tasks is not known.
   *
   * @sa      count_threads()
   */
  ssize_t task_all_list (ACE_Task_Base *task_list[],
                         size_t n);

  /**
   * Returns in @a thread_list a list of up to @a n thread ids.  The
   * caller must allocate the memory for @a thread_list.  In case of an
   * error, -1 is returned. If no requested values are found, 0 is
   * returned, otherwise correct number of retrieved values are
   * returned.
   */
  ssize_t thread_all_list (ACE_thread_t thread_list[],
                           size_t n);

  /// Set group ids for a particular task.
  int set_grp (ACE_Task_Base *task, int grp_id);

  /// Get group ids for a particular task.
  int get_grp (ACE_Task_Base *task, int &grp_id);

  /// Return a count of the current number of threads active in the
  /// <Thread_Manager>.
  size_t count_threads (void) const;

  /// Get the state of the thread. Returns false if the thread is not
  /// managed by this thread manager.
  int thr_state (ACE_thread_t id, ACE_UINT32& state);

  /**
   * Register an At_Thread_Exit hook and the ownership is acquire by
   * Thread_Descriptor, this is the usual case when the AT is dynamically
   * allocated.
   */
  int at_exit (ACE_At_Thread_Exit* cleanup);

  /// Register an At_Thread_Exit hook and the ownership is retained for the
  /// caller. Normally used when the at_exit hook is created in stack.
  int at_exit (ACE_At_Thread_Exit& cleanup);

  /**
   *
   *****
   * @deprecated This function is deprecated.  Please use the previous two
   *    at_exit method.  Notice that you should avoid mixing this method
   *    with the previous two at_exit methods.
   *****
   *
   * Register an object (or array) for cleanup at
   * thread termination.  "cleanup_hook" points to a (global, or
   * static member) function that is called for the object or array
   * when it to be destroyed.  It may perform any necessary cleanup
   * specific for that object or its class.  "param" is passed as the
   * second parameter to the "cleanup_hook" function; the first
   * parameter is the object (or array) to be destroyed.
   * "cleanup_hook", for example, may delete the object (or array).
   * If <cleanup_hook> == 0, the <object> will _NOT_ get cleanup at
   * thread exit.  You can use this to cancel the previously added
   * at_exit.
   */
  int at_exit (void *object,
               ACE_CLEANUP_FUNC cleanup_hook,
               void *param);

  /// Access function to determine whether the Thread_Manager will
  /// wait for its thread to exit or not when being closing down.
  void wait_on_exit (int dowait);
  int wait_on_exit (void);

  /// Dump the state of an object.
  void dump (void);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  // = Accessors for ACE_Thread_Descriptors.
  /**
   * Get a pointer to the calling thread's own thread_descriptor.
   * This must be called from a spawn thread.  This function will
   * fetch the info from TSS.
   */
  ACE_Thread_Descriptor *thread_desc_self (void);

  /// Return a pointer to the thread's Thread_Descriptor,
  /// 0 if fail.
  ACE_Thread_Descriptor *thread_descriptor (ACE_thread_t);

  /// Return a pointer to the thread's Thread_Descriptor,
  /// 0 if fail.
  ACE_Thread_Descriptor *hthread_descriptor (ACE_hthread_t);

  /// Create a new thread (must be called with locks held).
  int spawn_i (ACE_THR_FUNC func,
               void *arg,
               long flags,
               ACE_thread_t * = 0,
               ACE_hthread_t *t_handle = 0,
               long priority = ACE_DEFAULT_THREAD_PRIORITY,
               int grp_id = -1,
               void *stack = 0,
               size_t stack_size = 0,
               ACE_Task_Base *task = 0,
               const char** thr_name = 0);

  /// Run the registered hooks when the thread exits.
  void run_thread_exit_hooks (int i);

  /// Locate the index of the table slot occupied by <t_id>.  Returns
  /// -1 if <t_id> is not in the table doesn't contain <t_id>.
  ACE_Thread_Descriptor *find_thread (ACE_thread_t t_id);

  /// Locate the index of the table slot occupied by <h_id>.  Returns
  /// -1 if <h_id> is not in the table doesn't contain <h_id>.
  ACE_Thread_Descriptor *find_hthread (ACE_hthread_t h_id);

  /**
   * Locate the thread descriptor address of the list occupied by
   * @a task.  Returns 0 if @a task is not in the table doesn't contain
   * @a task.
   */
  ACE_Thread_Descriptor *find_task (ACE_Task_Base *task,
                                    size_t slot = 0);

  /// Insert a thread in the table (checks for duplicates).
  int insert_thr (ACE_thread_t t_id,
                  ACE_hthread_t,
                  int grp_id = -1,
                  long flags = 0);

  /// Append a thread in the table (adds at the end, growing the table
  /// if necessary).
  int append_thr (ACE_thread_t t_id, ACE_hthread_t,
                  ACE_UINT32,
                  int grp_id,
                  ACE_Task_Base *task = 0,
                  long flags = 0,
                  ACE_Thread_Descriptor *td = 0);

  /// Remove thread from the table.
  void remove_thr (ACE_Thread_Descriptor *td,
                   int close_handler);

  /// Remove all threads from the table.
  void remove_thr_all (void);

  // = The following four methods implement a simple scheme for
  // operating on a collection of threads atomically.

  /**
   * Efficiently check whether @a thread is in a particular @a state.
   * This call updates the TSS cache if possible to speed up
   * subsequent searches.
   */
  int check_state (ACE_UINT32 state,
                   ACE_thread_t thread,
                   int enable = 1);

  /// Apply @a func to all members of the table that match the @a task
  int apply_task (ACE_Task_Base *task,
                  ACE_THR_MEMBER_FUNC func,
                  int = 0);

  /// Apply @a func to all members of the table that match the @a grp_id.
  int apply_grp (int grp_id,
                 ACE_THR_MEMBER_FUNC func,
                 int arg = 0);

  /// Apply @a func to all members of the table.
  int apply_all (ACE_THR_MEMBER_FUNC,
                 int  = 0);

  /// Join the thread described in @a td.
  int join_thr (ACE_Thread_Descriptor *td,
                int = 0);

  /// Resume the thread described in @a td.
  int resume_thr (ACE_Thread_Descriptor *td,
                  int = 0);

  /// Suspend the thread described in @a td.
  int suspend_thr (ACE_Thread_Descriptor *td,
                   int = 0);

  /// Send signal @a signum to the thread described in @a td.
  int kill_thr (ACE_Thread_Descriptor *td,
                int signum);

  /// Set the cancellation flag for the thread described in @a td.
  int cancel_thr (ACE_Thread_Descriptor *td,
                  int async_cancel = 0);

  /// Register a thread as terminated and put it into the <terminated_thr_list_>.
  int register_as_terminated (ACE_Thread_Descriptor *td);

  /// Setting the static ACE_TSS_TYPE (ACE_Thread_Exit) *thr_exit_ pointer.
  static int set_thr_exit (ACE_TSS_TYPE (ACE_Thread_Exit) *ptr);

  /**
   * Keeping a list of thread descriptors within the thread manager.
   * Double-linked list enables us to cache the entries in TSS
   * and adding/removing thread descriptor entries without
   * affecting other thread's descriptor entries.
   */
  ACE_Double_Linked_List<ACE_Thread_Descriptor> thr_list_;

#if !defined (ACE_HAS_VXTHREADS)
  /// Collect terminated but not yet joined thread entries.
  ACE_Double_Linked_List<ACE_Thread_Descriptor_Base> terminated_thr_list_;
#endif /* !ACE_HAS_VXTHREADS */

  /// Collect pointers to thread descriptors of threads to be removed later.
  ACE_Unbounded_Queue<ACE_Thread_Descriptor*> thr_to_be_removed_;

  /// Keeps track of the next group id to assign.
  int grp_id_;

  /// Set if we want the Thread_Manager to wait on all threads before
  /// being closed, reset otherwise.
  int automatic_wait_;

  // = ACE_Thread_Mutex and condition variable for synchronizing termination.
#if defined (ACE_HAS_THREADS)
  /// Serialize access to the <zero_cond_>.
  ACE_Thread_Mutex lock_;

  /// Keep track of when there are no more threads.
  ACE_Condition_Thread_Mutex zero_cond_;
#endif /* ACE_HAS_THREADS */

  ACE_Locked_Free_List<ACE_Thread_Descriptor, ACE_SYNCH_MUTEX> thread_desc_freelist_;

private:
#if ! defined (ACE_THREAD_MANAGER_LACKS_STATICS)
  /// Pointer to a process-wide ACE_Thread_Manager.
  static ACE_Thread_Manager *thr_mgr_;

  /// Must delete the thr_mgr_ if true.
  static bool delete_thr_mgr_;

  /// Global ACE_TSS (ACE_Thread_Exit) object ptr.
  static ACE_TSS_TYPE (ACE_Thread_Exit) *thr_exit_;
#endif /* ! defined (ACE_THREAD_MANAGER_LACKS_STATICS) */
};

#if defined (ACE_THREAD_MANAGER_LACKS_STATICS)
#define ACE_THREAD_MANAGER_SINGLETON_DEFINE \
        ACE_Singleton<ACE_Thread_Manager, ACE_SYNCH_MUTEX>;
typedef ACE_Singleton<ACE_Thread_Manager, ACE_SYNCH_MUTEX> ACE_THREAD_MANAGER_SINGLETON;
#endif /* defined (ACE_THREAD_MANAGER_LACKS_STATICS) */

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Thread_Manager.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_THREAD_MANAGER_H */

