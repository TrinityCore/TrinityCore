// -*- C++ -*-

//=============================================================================
/**
 *  @file    Process_Manager.h
 *
 *  $Id: Process_Manager.h 84619 2009-02-26 12:26:16Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_PROCESS_MANAGER_H
#define ACE_PROCESS_MANAGER_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Process.h"
#include "ace/Event_Handler.h"
#include "ace/Time_Value.h"

#if defined (ACE_HAS_THREADS)
#  include "ace/Recursive_Thread_Mutex.h"
#endif /* ACE_HAS_THREADS */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Reactor;

/**
 * @class ACE_Process_Manager
 *
 * @brief Manages a group of processes.
 *
 * This class allows applications to control groups of processes,
 * similar to how the ACE_Thread_Manager controls groups of
 * threads.  Naturally, it doesn't work at all on platforms, such
 * as VxWorks or pSoS, that don't support process.
 * There are two main ways of using ACE_Process_Manager,
 * depending on how involved you wish to be with the termination
 * of managed processes.  If you want processes to simply
 * go away when they're finished, register the ACE_Process_Manager with
 * an ACE_Reactor that can handle notifications of child process exit:
 * @code
 * ACE_Process_Manager mgr;
 * // ...
 * mgr.open (100, ACE_Reactor::instance ());
 * @endcode
 * In this usage scenario, the ACE_Process_Manager will clean up after any
 * processes that it spawns.  (On Unix, this means executing a
 * wait(2) to collect the exit status and avoid zombie
 * processes; on Win32, it means closing the process and thread
 * HANDLEs that are created when CreateProcess is called.)
 *
 * @note When you register a ACE_Process_Manager with a
 * ACE_Reactor, the reactor's notification pipe is used to help reap the
 * available process exit statuses.  Therefore, you must not use a
 * reactor whose notify pipe has been disabled.  Here's the
 * sequence of steps used to reap the exit statuses in this case:
 * -# The ACE_Process_Manager registers a signal handler for
 *    SIGCHLD.
 * -# The SIGCHLD handler, when invoked, uses the ACE_Reactor's
 *    notify() method to inform the ACE_Reactor to wake up.
 * -# The ACE_Reactor calls the ACE_Process_Manager's
 *    handle_input() method; this happens synchronously, not in
 *    signal context.
 * -# The handle_input() method collects all available exit
 *    statuses.
 *
 * If, on the other hand you want to wait "in line" to handle the
 * terminated process cleanup code, call one of the wait functions
 * whenever there might be managed processes that have exited.
 *
 * Note that in either case, ACE_Process_Manager allows you to
 * register an ACE_Event_Handler to be called when a specific
 * spawned process exits, or when any process without a specific
 * ACE_Event_Handler exits.  When a process exits, the
 * appropriate ACE_Event_Handler's handle_input() method is called; the
 * ACE_HANDLE passed is either the process's HANDLE (on Win32),
 * or its pid cast to an ACE_HANDLE (on POSIX).
 * It is also possible to call the wait() functions even when the
 * ACE_Process_Manager is registered with a reactor.
 *
 * @note Be aware that the wait functions are "sloppy" on Unix,
 * because there's no good way to wait for a subset of the
 * children of a process.  The wait functions may end up
 * collecting the exit status of a process that's not managed by
 * the ACE_Process_Manager whose wait() you invoked.  It's best to
 * only use a single ACE_Process_Manager, and to create all
 * subprocesses by calling that manager's spawn() method.
 */
class ACE_Export ACE_Process_Manager : protected ACE_Event_Handler
{
public:
  friend class ACE_Process_Control;

  enum
  {
    DEFAULT_SIZE = 100
  };

  /**
   * @name Initialization and termination methods
   */
  //@{
  /**
   * Initialize an ACE_Process_Manager with a table containing up to
   * @a size processes.  This table resizes itself automatically as
   * needed.  If a @a reactor is provided, this
   * ACE_Process_Manager uses it to notify an application when a
   * process it controls exits.  By default, however, we don't use an
   * ACE_Reactor.
   */
  ACE_Process_Manager (size_t size = ACE_Process_Manager::DEFAULT_SIZE,
                       ACE_Reactor *reactor = 0);

  /**
   * Initialize an ACE_Process_Manager with a table containing up to
   * @a size processes.  This table resizes itself automatically as
   * needed.  If a @a reactor is provided, this
   * ACE_Process_Manager uses it to notify an application when a
   * process it controls exits.  By default, however, we don't use an
   * ACE_Reactor.
   */
  int open (size_t size = ACE_Process_Manager::DEFAULT_SIZE,
            ACE_Reactor *r = 0);

  /// Release all resources.  Do not wait for processes to exit.
  int close (void);

  /// Destructor releases all resources and does not wait for processes
  /// to exit.
  virtual ~ACE_Process_Manager (void);

  //@}

  /**
   * @name Singleton access and control
   */
  //@{
  /// Get pointer to a process-wide ACE_Process_Manager.
  static ACE_Process_Manager *instance (void);

  /// Set pointer to a process-wide ACE_Process_Manager and return
  /// existing pointer.
  static ACE_Process_Manager *instance (ACE_Process_Manager *);

  /// Delete the dynamically allocated singleton.
  static void close_singleton (void);

  /// Cleanup method, used by the ACE_Object_Manager to destroy the
  /// singleton.
  static void cleanup (void *instance, void *arg);

  //@}

  /**
   * @name Process creation methods
   */
  //@{
  /**
   * Create a new process with specified @a options.
   * Register @a event_handler to be called back when the process exits.
   *
   * On success, returns the process id of the child that was created.
   * On failure, returns ACE_INVALID_PID.
   */
  pid_t spawn (ACE_Process *proc,
               ACE_Process_Options &options,
               ACE_Event_Handler *event_handler = 0);

  /**
   * Create a new process with the specified @a options.
   * Register @a event_handler to be called back when the process exits.
   *
   * On success, returns the process id of the child that was created.
   * On failure, returns ACE_INVALID_PID.
   */
  pid_t spawn (ACE_Process_Options &options,
               ACE_Event_Handler *event_handler = 0);

  /**
   * Create @a n new processes with the same @a options.
   * If @a child_pids is non-0 it is expected to be an array of at least
   * @a n pid_t, which are filled in with the process IDs of the spawned
   * processes.
   * Register @a event_handler to be called back when each process exits.
   * Returns 0 on success and -1 on failure.
   */
  int spawn_n (size_t n,
               ACE_Process_Options &options,
               pid_t *child_pids = 0,
               ACE_Event_Handler *event_Handler = 0);
  //@}

  /**
   * @name Process synchronization operations
   */
  //@{
  /**
   * Abruptly terminate a single process with id @a pid using the
   * ACE::terminate_process() method which works on both signal-capable
   * systems and on Windows.
   *
   * @note This call is potentially dangerous to use since the process
   * being terminated may not have a chance to cleanup before it shuts down.
   *
   * @retval 0 on success and -1 on failure.
   */
  int terminate (pid_t pid);

  /**
   * Sends the specified signal to the specified process.
   *
   * @note This only works on platforms that have signal capability. In
   * particular, it doesn't work on Windows.
   *
   * @retval 0 on success and -1 on failure.
   */
  int terminate (pid_t pid, int sig);

  /**
   * Block until there are no more child processes running that were
   * spawned by this ACE_Process_Manager.  Unlike the wait() method
   * below, this method does not require a signal handler or use of
   * ACE_OS::sigwait() because it simply blocks synchronously waiting
   * for all the children managed by this ACE_Process_Manager to
   * exit.  Note that this does not return any status information
   * about the success or failure of exiting child processes, although
   * any registered exit handlers are called.
   *
   * @param timeout Relative time to wait for processes to terminate.
   *
   * @retval 0 on success; -1 on failure.
   */
  int wait (const ACE_Time_Value &timeout = ACE_Time_Value::max_time);

  /**
   * Wait up to @a timeout for a single specified process to terminate.
   * If @a pid is 0, this method waits for any of the managed processes
   * (but see the note concerning "sloppy process cleanup on unix").
   * If @a pid != 0, waits for that process only.
   *
   * @param pid     Process ID
   * @param timeout Relative time to wait for process to terminate
   * @param status  Exit status of terminated process
   *
   * @retval The pid of the process which exited, 0
   * if a timeout occurred, or ACE_INVALID_PID on error.
   */
  pid_t wait (pid_t pid,
              const ACE_Time_Value &timeout,
              ACE_exitcode *status = 0);

  /**
   * Wait indefinitely for a single, specified process to terminate.
   * If @a pid is 0, waits for any of the managed processes (but see the
   * note concerning "sloppy process cleanup on unix").
   * If @a pid != 0, this method waits for that process only.
   *
   * @retval The pid of the process which exited, or
   * ACE_INVALID_PID on error.
   */
  pid_t wait (pid_t pid,
              ACE_exitcode *status = 0);

  /**
   * @deprecated
   * Reap the result of a single process by calling ACE_OS::waitpid(),
   * therefore, this method is not portable to Windows.  If the child is
   * successfully reaped, remove() is called automatically.
   * Use one of the wait() methods instead of this method.
   */
  int reap (pid_t pid = -1,
            ACE_exitcode *stat_loc = 0,
            int options = WNOHANG);
  //@}

  /**
   * @name Utility methods
   */
  //@{
  /**
   * Register an event handler to be called back when the specified
   * process exits.  If @a pid == ACE_INVALID_PID this handler is called
   * when any process with no specific handler exits.
   *
   * @warning In multithreaded applications, there is a race condition
   * if a process exits between the time it is spawned and when its
   * handler is registered.  To avoid this, register the handler at
   * the time the process is spawned.
   */
  int register_handler (ACE_Event_Handler *event_handler,
                        pid_t pid = ACE_INVALID_PID);

  /**
   * Remove process @a pid from the ACE_Process_Manager's internal records.
   * This is called automatically by the reap() method after it successfully
   * reaps a process.  It's also possible to call this method
   * directly from a signal handler, but don't call both reap() and
   * remove()!
   */
  int remove (pid_t pid);

  /// Return the number of managed processes.
  size_t managed (void) const;

  /**
   * Sets the scheduling parameters for process identified by @a pid by
   * passing @a params, @a pid to ACE_OS::sched_params().
   *
   * @retval 0 on success, -1 on failure, and ACE_INVALID_PID when the
   * specified @a pid is not managed by this ACE_Process_Manager.
   */
  int set_scheduler (const ACE_Sched_Params &params, pid_t pid);

  /**
   * Sets the scheduling parameters for all the processes managed by
   * this ACE_Process_Manager by passing @a params to
   * ACE_OS::sched_params().
   *
   * @retval 0 on success, -1 on failure.
   */
  int set_scheduler_all (const ACE_Sched_Params &params);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
  //@}

protected:
  // = These methods allow a <Process_Manager> to be an Event_Handler.

  // As an Event_Handler, the <Process_Manager> automagically
  // detects child Processes exiting and calls notify_proc_handler()
  // and remove().  This means that you don't have to (shouldn't!)
  // call the wait(...)  methods yourself.

  // On Unix, we can't detect individual process termination very
  // well; the best method is to catch SIGCHLD and then call the
  // polling wait() function to collect any available exit statuses.
  // However, we don't want to do this from within a signal handler
  // because of the restrictions associated.  Therefore (following the
  // lead in examples/mumble) we open a bogus handle (to ACE_DEV_NULL)
  // and register that handle with our Reactor.  Then, when our
  // SIGCHLD handler gets invoked, we tell the Reactor that the bogus
  // handle is readable.  That will cause the handle_input() function
  // to be called once we're out of the interrupt context, and
  // handle_input() collects exit statuses.

  // On Win32, we simply register ourself with the Reactor to deal
  // with the Process handle becoming signaled.  No muss, no fuss, no
  // signal handler, and no dummy handle.

#if !defined(ACE_WIN32)
  /// Collect one (or more, on unix) process exit status.
  virtual int handle_input (ACE_HANDLE proc);
#endif // !defined(ACE_WIN32)

  /**
   * On Unix, this routine is called asynchronously when a SIGCHLD is
   * received.  We just tweak the reactor so that it'll call back our
   * <handle_input> function, which allows us to handle Process exits
   * synchronously.
   *
   * On Win32, this routine is called synchronously, and is passed the
   * HANDLE of the Process that exited, so we can do all our work here
   */
  virtual int handle_signal (int signum,
                             siginfo_t * = 0,
                             ucontext_t * = 0);

private:

  /**
   * @struct Process_Descriptor
   *
   * @internal This struct is for internal use only by ACE_Process_Manager.
   *
   * @brief Information describing each process that's controlled by an
   * ACE_Process_Manager.
   */
  struct Process_Descriptor
  {
    /// Default ctor/dtor.
    Process_Descriptor (void);
    ~Process_Descriptor (void);

    /// Describes the process itself.
    ACE_Process *process_;

    /// Function to call when process exits
    ACE_Event_Handler *exit_notify_;

    /// Dump the state of an object.
    void dump (void) const;
  };

  /// Resize the pool of Process_Descriptors.
  int resize (size_t);

  /// Locate the index of the table slot occupied by @a process_id.
  /// Returns -1 if @a process_id is not in the @c process_table_
  ssize_t find_proc (pid_t process_id);

#if defined (ACE_WIN32)
  /// Locate the index of the table slot occupied by @a process_handle.
  /// Returns ~0 if @a process_handle is not in the @c process_table_
  ssize_t find_proc (ACE_HANDLE process_handle);
#endif /* ACE_WIN32 */

  /// Insert a process in the table (checks for duplicates).  Omitting
  /// the process handle won't work on Win32...
  /// Register @a event_handler to be called back when the process exits.
  int insert_proc (ACE_Process *process,
                   ACE_Event_Handler *event_handler = 0);

  /**
   * Append information about a process, i.e., its <process_id> in the
   * @c process_table_.  Each entry is added at the end, growing the
   * table if necessary.
   * Register @a event_handler to be called back when the process exits.
   */
  int append_proc (ACE_Process *process,
                   ACE_Event_Handler *event_handler = 0);

  /// Actually removes the process at index @a n from the table.  This method
  /// must be called with locks held.
  int remove_proc (size_t n);

  /// If there's a specific handler for the Process at index @a n in the
  /// table, or there's a default handler, call it.
  int notify_proc_handler (size_t n, ACE_exitcode status);

  /// Vector that describes process state within the Process_Manager.
  Process_Descriptor *process_table_;

  /// Maximum number of processes we can manage (should be dynamically
  /// allocated).
  size_t max_process_table_size_;

  /// Current number of processes we are managing.
  size_t current_count_;

  /// This event handler is used to notify when a process we control
  /// exits.
  ACE_Event_Handler *default_exit_handler_;

  /// Singleton pointer.
  static ACE_Process_Manager *instance_;

  /// Controls whether the <Process_Manager> is deleted when we shut
  /// down (we can only delete it safely if we created it!)
  static bool delete_instance_;

#if defined (ACE_HAS_THREADS)
  /// This lock protects access/ops on @c process_table_.
  ACE_Recursive_Thread_Mutex lock_;
#endif /* ACE_HAS_THREADS */
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Process_Manager.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_PROCESS_MANAGER_H */
