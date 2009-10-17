// $Id: Process_Manager.cpp 82559 2008-08-07 20:23:07Z parsons $
// Process_Manager.cpp
#include "ace/Process_Manager.h"
#if !defined (__ACE_INLINE__)
#include "ace/Process_Manager.inl"
#endif /* __ACE_INLINE__ */
#include "ace/ACE.h"
#include "ace/Guard_T.h"
#include "ace/Process.h"
#include "ace/Signal.h"
#include "ace/Object_Manager.h"
#include "ace/Log_Msg.h"
#include "ace/Reactor.h"
#include "ace/Countdown_Time.h"
#include "ace/OS_NS_sys_wait.h"
#include "ace/OS_NS_signal.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/Truncate.h"
ACE_RCSID (ace,
           Process_Manager,
           "$Id: Process_Manager.cpp 82559 2008-08-07 20:23:07Z parsons $")
#if defined (ACE_HAS_SIG_C_FUNC)
extern "C" void
ACE_Process_Manager_cleanup (void *instance, void *arg)
{
  ACE_Process_Manager::cleanup (instance, arg);
}
#endif
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
void
ACE_Process_Manager::cleanup (void *, void *)
{
  ACE_Process_Manager::close_singleton ();
}
// This function acts as a signal handler for SIGCHLD. We don't really
// want to do anything with the signal - it's just needed to interrupt
// a sleep.  See wait() for more info.
#if !defined (ACE_WIN32) && !defined (ACE_LACKS_UNIX_SIGNALS)
static void
sigchld_nop (int, siginfo_t *, ucontext_t *)
{
  return;
}
#endif /* ACE_WIN32 */

ACE_ALLOC_HOOK_DEFINE(ACE_Process_Manager)
// Singleton instance.
ACE_Process_Manager *ACE_Process_Manager::instance_ = 0;
// Controls whether the <Process_Manager> is deleted when we shut down
// (we can only delete it safely if we created it!)
bool ACE_Process_Manager::delete_instance_ = false;
ACE_Process_Manager::Process_Descriptor::~Process_Descriptor (void)
{
}
void
ACE_Process_Manager::Process_Descriptor::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Process_Manager::Process_Descriptor::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nproc_id_ = %d"),
                          this->process_->getpid( )));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
void
ACE_Process_Manager::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Process_Manager::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nmax_process_table_size_ = %d"), this->max_process_table_size_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\ncurrent_count_ = %d"), this->current_count_));
  for (size_t i = 0; i < this->current_count_; i++)
    this->process_table_[i].dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
ACE_Process_Manager::Process_Descriptor::Process_Descriptor (void)
  : process_ (0),
    exit_notify_ (0)
{
  ACE_TRACE ("ACE_Process_Manager::Process_Descriptor::Process_Descriptor");
}
ACE_Process_Manager *
ACE_Process_Manager::instance (void)
{
  ACE_TRACE ("ACE_Process_Manager::instance");
  if (ACE_Process_Manager::instance_ == 0)
    {
      // Perform Double-Checked Locking Optimization.
      ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                                *ACE_Static_Object_Lock::instance (), 0));
      if (ACE_Process_Manager::instance_ == 0)
        {
          ACE_NEW_RETURN (ACE_Process_Manager::instance_,
                          ACE_Process_Manager,
                          0);
          ACE_Process_Manager::delete_instance_ = true;
          // Register with the Object_Manager so that the wrapper to
          // delete the proactor will be called when Object_Manager is
          // being terminated.
#if defined ACE_HAS_SIG_C_FUNC
          ACE_Object_Manager::at_exit (ACE_Process_Manager::instance_,
                                       ACE_Process_Manager_cleanup,
                                       0);
#else
          ACE_Object_Manager::at_exit (ACE_Process_Manager::instance_,
                                       ACE_Process_Manager::cleanup,
                                       0);
#endif /* ACE_HAS_SIG_C_FUNC */
        }
    }
  return ACE_Process_Manager::instance_;
}
ACE_Process_Manager *
ACE_Process_Manager::instance (ACE_Process_Manager *tm)
{
  ACE_TRACE ("ACE_Process_Manager::instance");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                            *ACE_Static_Object_Lock::instance (), 0));
  ACE_Process_Manager *t = ACE_Process_Manager::instance_;
  // We can't safely delete it since we don't know who created it!
  ACE_Process_Manager::delete_instance_ = false;
  // Register with the Object_Manager so that the wrapper to
  // delete the proactor will be called when Object_Manager is
  // being terminated.
#if defined ACE_HAS_SIG_C_FUNC
  ACE_Object_Manager::at_exit (ACE_Process_Manager::instance_,
                                ACE_Process_Manager_cleanup,
                                0);
#else
  ACE_Object_Manager::at_exit (ACE_Process_Manager::instance_,
                                ACE_Process_Manager::cleanup,
                                0);
#endif /* ACE_HAS_SIG_C_FUNC */
  ACE_Process_Manager::instance_ = tm;
  return t;
}
void
ACE_Process_Manager::close_singleton( void )
{
  ACE_TRACE ("ACE_Process_Manager::close_singleton");
  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex, ace_mon,
                     *ACE_Static_Object_Lock::instance ()));
  if (ACE_Process_Manager::delete_instance_)
    {
      delete ACE_Process_Manager::instance_;
      ACE_Process_Manager::instance_ = 0;
      ACE_Process_Manager::delete_instance_ = false;
    }
}
int
ACE_Process_Manager::resize (size_t size)
{
  ACE_TRACE ("ACE_Process_Manager::resize");
  if (size <= this->max_process_table_size_)
    return 0;
  Process_Descriptor *temp = 0;
  ACE_NEW_RETURN (temp,
                  Process_Descriptor[size],
                  -1);
  for (size_t i = 0;
       i < this->current_count_;
       i++)
    // Structure assignment.
    temp[i] = this->process_table_[i];
  this->max_process_table_size_ = size;
  delete [] this->process_table_;
  this->process_table_ = temp;
  return 0;
}
// Create and initialize the table to keep track of the process pool.
int
ACE_Process_Manager::open (size_t size, ACE_Reactor *r)
{
  ACE_TRACE ("ACE_Process_Manager::open");
  if (r)
    {
      this->reactor (r);
#if !defined (ACE_WIN32) && !defined (ACE_LACKS_UNIX_SIGNALS)
      // Register signal handler object.
      if (r->register_handler (SIGCHLD, this) == -1)
        return -1;
#endif /* !defined(ACE_WIN32) */
    }
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
  if (this->max_process_table_size_ < size)
    this->resize (size);
  return 0;
}
// Initialize the synchronization variables.
ACE_Process_Manager::ACE_Process_Manager (size_t size,
                                          ACE_Reactor *r)
  : ACE_Event_Handler (),
    process_table_ (0),
    max_process_table_size_ (0),
    current_count_ (0),
    default_exit_handler_ (0)
#if defined (ACE_HAS_THREADS)
  , lock_ ()
#endif /* ACE_HAS_THREADS */
{
  ACE_TRACE ("ACE_Process_Manager::ACE_Process_Manager");
  if (this->open (size,
                  r) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Process_Manager")));
}
// Close up and release all resources.
int
ACE_Process_Manager::close (void)
{
  ACE_TRACE ("ACE_Process_Manager::close");
  if (this->reactor () != 0)
    {
#if !defined (ACE_WIN32) && !defined (ACE_LACKS_UNIX_SIGNALS)
      this->reactor ()->remove_handler (SIGCHLD, (ACE_Sig_Action *) 0);
#endif /*  !ACE_WIN32  */
      this->reactor (0);
    }
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
  if (this->process_table_ != 0)
    {
      while (this->current_count_ > 0)
        this->remove_proc (0);
      delete [] this->process_table_;
      this->process_table_ = 0;
      this->max_process_table_size_ = 0;
      this->current_count_ = 0;
    }
  if (this->default_exit_handler_ != 0)
      this->default_exit_handler_->handle_close (ACE_INVALID_HANDLE,0);
  this->default_exit_handler_ = 0;
  return 0;
}
ACE_Process_Manager::~ACE_Process_Manager (void)
{
  ACE_TRACE ("ACE_Process_Manager::~ACE_Process_Manager");
  this->close ();
}
#if !defined (ACE_WIN32)
// This is called when the Reactor notices that a Process has exited.
// What has actually happened is a SIGCHLD invoked the <handle_signal>
// routine, which fooled the Reactor into thinking that this routine
// needed to be called.  Since we don't know which Process exited, we
// must reap as many exit statuses as are immediately available.
int
ACE_Process_Manager::handle_input (ACE_HANDLE)
{
  ACE_TRACE ("ACE_Process_Manager::handle_input");
   pid_t pid;
   do
     pid = this->wait (0,
                       ACE_Time_Value::zero);
   while (pid != 0 && pid != ACE_INVALID_PID);
  return 0;
}
#endif /* !ACE_WIN32 */
// On Unix, this routine is called asynchronously when a SIGCHLD is
// received.  We just tweak the reactor so that it'll call back our
// <handle_input> function, which allows us to handle Process exits
// synchronously.
//
// On Win32, this routine is called synchronously, and is passed the
// HANDLE of the Process that exited, so we can do all our work here.
int
ACE_Process_Manager::handle_signal (int,
                                    siginfo_t *si,
                                    ucontext_t *)
{
#if defined (ACE_WIN32)
  ACE_HANDLE proc = si->si_handle_;
  ACE_exitcode status = 0;
  BOOL result = ::GetExitCodeProcess (proc,
                                      &status);
  if (result)
    {
      if (status != STILL_ACTIVE)
        {
          {
            ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, lock_, -1));
            ssize_t const i = this->find_proc (proc);
            if (i == -1)
              return -1;
#if 0
            pid_t pid = i != -1
              ? process_table_[i].process_->getpid ()
              : ACE_INVALID_PID;
#endif
            this->notify_proc_handler (i, status);
            this->remove_proc (i);
          }
          return -1; // remove this HANDLE/Event_Handler combination
        }
      else
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("Process still active")
                           ACE_TEXT (" -- shouldn't have been called yet!\n")),
                          0); // return 0 : stay registered
    }
  else
    {
      // <GetExitCodeProcess> failed.
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("GetExitCodeProcess failed")),
                        -1); // return -1: unregister
    }
#else /* !ACE_WIN32 */
  ACE_UNUSED_ARG (si);
  return reactor ()->notify (this, ACE_Event_Handler::READ_MASK);
#endif /* !ACE_WIN32 */
}
int
ACE_Process_Manager::register_handler (ACE_Event_Handler *eh,
                                       pid_t pid)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
  if (pid == ACE_INVALID_PID)
    {
      if (this->default_exit_handler_ != 0)
        this->default_exit_handler_->handle_close (ACE_INVALID_HANDLE, 0);
      this->default_exit_handler_ = eh;
      return 0;
    }
  ssize_t const i = this->find_proc (pid);
  if (i == -1)
    {
      errno = EINVAL;
      return -1;
    }
  Process_Descriptor &proc_desc = this->process_table_[i];
  if (proc_desc.exit_notify_ != 0)
    proc_desc.exit_notify_->handle_close (ACE_INVALID_HANDLE, 0);
  proc_desc.exit_notify_ = eh;
  return 0;
}
// Create a new process.
pid_t
ACE_Process_Manager::spawn (ACE_Process_Options &options,
                            ACE_Event_Handler *event_handler)
{
  ACE_Process *process = 0;
  ACE_NEW_RETURN (process,
                  ACE_Managed_Process,
                  ACE_INVALID_PID);
  pid_t const pid = spawn (process, options, event_handler);
  if (pid == ACE_INVALID_PID || pid == 0)
    delete process;
  return pid;
}
// Create a new process.
pid_t
ACE_Process_Manager::spawn (ACE_Process *process,
                            ACE_Process_Options &options,
                            ACE_Event_Handler *event_handler)
{
  ACE_TRACE ("ACE_Process_Manager::spawn");
  pid_t const pid = process->spawn (options);
  // Only include the pid in the parent's table.
  if (pid == ACE_INVALID_PID || pid == 0)
    return pid;
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex,
                            ace_mon, this->lock_, -1));
  if (this->append_proc (process, event_handler) == -1)
    // bad news: spawned, but not registered in table.
    return ACE_INVALID_PID;
  return pid;
}
// Create N new processs.
int
ACE_Process_Manager::spawn_n (size_t n,
                              ACE_Process_Options &options,
                              pid_t *child_pids,
                              ACE_Event_Handler *event_handler)
{
  ACE_TRACE ("ACE_Process_Manager::spawn_n");
  if (child_pids != 0)
    for (size_t i = 0;
         i < n;
         ++i)
      child_pids[i] = ACE_INVALID_PID;
  for (size_t i = 0;
       i < n;
       i++)
    {
      pid_t const pid = this->spawn (options, event_handler);
      if (pid == ACE_INVALID_PID || pid == 0)
        // We're in the child or something's gone wrong.
        return pid;
      else if (child_pids != 0)
        child_pids[i] = pid;
    }
  return 0;
}
// Append a process into the pool (does not check for duplicates).
// Must be called with locks held.
int
ACE_Process_Manager::append_proc (ACE_Process *proc,
                                  ACE_Event_Handler *event_handler)
{
  ACE_TRACE ("ACE_Process_Manager::append_proc");
  // Try to resize the array to twice its existing size (or the DEFAULT_SIZE,
  // if there are no array entries) if we run out of space...
  if (this->current_count_ >= this->max_process_table_size_)
    {
      size_t new_size = this->max_process_table_size_ * 2;
      if (new_size == 0)
        new_size = ACE_Process_Manager::DEFAULT_SIZE;
      if (this->resize (new_size) == -1)
        return -1;
    }
  Process_Descriptor &proc_desc =
    this->process_table_[this->current_count_];
  proc_desc.process_ = proc;
  proc_desc.exit_notify_ = event_handler;
#if defined (ACE_WIN32)
  // If we have a Reactor, then we're supposed to reap Processes
  // automagically.  Get a handle to this new Process and tell the
  // Reactor we're interested in <handling_input> on it.
  ACE_Reactor * const r = this->reactor ();
  if (r != 0)
    r->register_handler (this, proc->gethandle ());
#endif /* ACE_WIN32 */
  ++this->current_count_;
  return 0;
}
// Insert a process into the pool (checks for duplicates and doesn't
// allow them to be inserted twice).
int
ACE_Process_Manager::insert_proc (ACE_Process *proc,
                                  ACE_Event_Handler *event_handler)
{
  ACE_TRACE ("ACE_Process_Manager::insert_proc");
  // Check for duplicates and bail out if they're already
  // registered...
  if (this->find_proc (proc->getpid ()) != -1)
    return -1;
  return this->append_proc (proc, event_handler);
}
// Remove a process from the pool.
int
ACE_Process_Manager::remove (pid_t pid)
{
  ACE_TRACE ("ACE_Process_Manager::remove");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
  ssize_t const i = this->find_proc (pid);
  if (i != -1)
    return this->remove_proc (i);
  // set "process not found" error
  return -1;
}
// Remove a process from the pool.  Must be called with locks held.
int
ACE_Process_Manager::remove_proc (size_t i)
{
  ACE_TRACE ("ACE_Process_Manager::remove_proc");
  // If there's an exit_notify_ <Event_Handler> for this pid, call its
  // <handle_close> method.
  if (this->process_table_[i].exit_notify_ != 0)
    {
      this->process_table_[i].exit_notify_->handle_close
        (this->process_table_[i].process_->gethandle(),
         0);
      this->process_table_[i].exit_notify_ = 0;
    }
#if defined (ACE_WIN32)
  ACE_Reactor * const r = this->reactor ();
  if (r != 0)
    r->remove_handler (this->process_table_[i].process_->gethandle (),
                       ACE_Event_Handler::DONT_CALL);
#endif /* ACE_WIN32 */
  this->process_table_[i].process_->unmanage ();
  this->process_table_[i].process_ = 0;
  this->current_count_--;
  if (this->current_count_ > 0)
    // Compact the table by moving the last item into the slot vacated
    // by the index being removed (this is a structure assignment).
    this->process_table_[i] =
      this->process_table_[this->current_count_];
  return 0;
}
int
ACE_Process_Manager::terminate (pid_t pid)
{
  ACE_TRACE ("ACE_Process_Manager::terminate");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
  // Check for duplicates and bail out if they're already
  // registered...
  ssize_t const i = this->find_proc (pid);
  if (i == -1)
    // set "no such process" error
    return -1;
  return ACE::terminate_process (pid);
}
int
ACE_Process_Manager::terminate (pid_t pid, int sig)
{
  ACE_TRACE ("ACE_Process_Manager::terminate");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
  // Check for duplicates and bail out if they're already
  // registered...
  ssize_t const i = this->find_proc (pid);
  if (i == -1)
    // set "no such process" error
    return -1;
  return ACE_OS::kill (pid, sig);
}

int
ACE_Process_Manager::set_scheduler (const ACE_Sched_Params & params,
                                    pid_t pid)
{
  ACE_TRACE ("ACE_Process_Manager::set_scheduler");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex,
                            ace_mon, this->lock_, -1));
  // Check to see if the process identified by the given pid is managed by
  // this instance of ACE_Process_Manager.
  ssize_t const i = this->find_proc (pid);
  if (i == -1)
    // set "no such process" error
    return ACE_INVALID_PID;
  return ACE_OS::sched_params (params, pid);
}
int
ACE_Process_Manager::set_scheduler_all (const ACE_Sched_Params & params)
{
  ACE_TRACE ("ACE_Process_Manager::set_scheduler_all");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex,
                            ace_mon, this->lock_, -1));
  for (size_t i = 0; i < this->current_count_; ++i)
    {
      pid_t const pid = this->process_table_[i].process_->getpid ();
      if (ACE_OS::sched_params (params, pid) != 0)
        return -1;
    }
  return 0;
}
// Locate the index in the table associated with <pid>.  Must be
// called with the lock held.
ssize_t
ACE_Process_Manager::find_proc (pid_t pid)
{
  ACE_TRACE ("ACE_Process_Manager::find_proc");
  for (size_t i = 0; i < this->current_count_; ++i)
    {
      if (pid == this->process_table_[i].process_->getpid ())
        {
          return ACE_Utils::truncate_cast<ssize_t> (i);
        }
    }
  return -1;
}
#if defined (ACE_WIN32)
// Locate the index in the table associated with <h>.  Must be
// called with the lock held.
ssize_t
ACE_Process_Manager::find_proc (ACE_HANDLE h)
{
  ACE_TRACE ("ACE_Process_Manager::find_proc");
  for (size_t i = 0; i < this->current_count_; ++i)
    {
      if (h == this->process_table_[i].process_->gethandle ())
        {
          return ACE_Utils::truncate_cast<ssize_t> (i);
        }
    }
  return -1;
}
#endif /* ACE_WIN32 */
// Wait for all the Processs to exit, or until <timeout> elapses.
// Returns the number of Processes remaining, or -1 on an error.
int
ACE_Process_Manager::wait (const ACE_Time_Value &timeout)
{
  ACE_TRACE ("ACE_Process_Manager::wait");
  ACE_Time_Value until = timeout;
  ACE_Time_Value remaining = timeout;
  if (until < ACE_Time_Value::max_time)
    until += ACE_OS::gettimeofday ();
  while (this->current_count_ > 0)
    {
      pid_t const pid = this->wait (0, remaining);
      if (pid == ACE_INVALID_PID)       // wait() failed
        return -1;
      else if (pid == 0)     // timeout
        break;
      remaining = until < ACE_Time_Value::max_time
        ? until - ACE_OS::gettimeofday ()
        : ACE_Time_Value::max_time;
      if (remaining <= ACE_Time_Value::zero)
        break;
      // else Process terminated...wait for more...
    }
  return static_cast<int> (this->current_count_);
}
// Collect a single child process' exit status.  Store the exit code
// in *<stat_loc> if non-zero.  Call the appropriate exit_notify.  If
// <pid> == 0, wait for any of the Process_Manager's children (or as
// near as possible -- on Unix, we might accidentally get some other
// Process_Manager's Process, or an unmanaged Process, or a child
// process started by some other means.
pid_t
ACE_Process_Manager::wait (pid_t pid,
                           ACE_exitcode *status)
{
  ACE_TRACE ("ACE_Process_Manager::wait");
  return this->wait (pid,
                     ACE_Time_Value::max_time,
                     status);
}
// Collect a single child processes' exit status, unless <timeout>
// elapses before the process exits.  Same caveats about accidental
// Process reaping on Unix as above.
pid_t
ACE_Process_Manager::wait (pid_t pid,
                           const ACE_Time_Value &timeout,
                           ACE_exitcode *status)
{
  ACE_TRACE ("ACE_Process_Manager::wait");
  ACE_exitcode local_stat = 0;
  if (status == 0)
    status = &local_stat;
  *status = 0;
  ssize_t idx = -1;
  ACE_Process *proc = 0;
  {
    // fake context after which the lock is released
    ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
    if (pid != 0)
      {
        idx = this->find_proc (pid);
        if (idx == -1)
          return ACE_INVALID_PID;
        else
          proc = process_table_[idx].process_;
      }
    // release the lock.
  }
  if (proc != 0)
    pid = proc->wait (timeout, status);
  else
    {
      ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
      // Wait for any Process spawned by this Process_Manager.
#if defined (ACE_WIN32)
      HANDLE *handles = 0;
      ACE_NEW_RETURN (handles,
                      HANDLE[this->current_count_],
                      ACE_INVALID_PID);
      for (size_t i = 0;
           i < this->current_count_;
           ++i)
        handles[i] =
          process_table_[i].process_->gethandle ();
      DWORD handle_count = static_cast<DWORD> (this->current_count_);
      DWORD result = ::WaitForMultipleObjects (handle_count,
                                               handles,
                                               FALSE,
                                               timeout == ACE_Time_Value::max_time
                                               ? INFINITE
                                               : timeout.msec ());
      if (result == WAIT_FAILED)
        pid = ACE_INVALID_PID;
      else if (result == WAIT_TIMEOUT)
        pid = 0;
      else
        {
          // Green Hills produces a warning that result >=
          // WAIT_OBJECT_0 is a pointless comparison because
          // WAIT_OBJECT_0 is zero and DWORD is unsigned long, so this
          // test is skipped for Green Hills.  Same for mingw.
# if defined (ghs) || defined (__MINGW32__) || (defined (_MSC_VER) && _MSC_VER >= 1300)
          ACE_ASSERT (result < WAIT_OBJECT_0 + this->current_count_);
# else
          ACE_ASSERT (result >= WAIT_OBJECT_0
                      && result < WAIT_OBJECT_0 + this->current_count_);
# endif
          idx = this->find_proc (handles[result - WAIT_OBJECT_0]);
          if (idx != -1)
            {
              pid = process_table_[idx].process_->getpid ();
              result = ::GetExitCodeProcess (handles[result - WAIT_OBJECT_0],
                                             status);
              if (result == 0)
                {
                  // <GetExitCodeProcess> failed!
                  this->remove_proc (idx);
                  pid = ACE_INVALID_PID;
                }
            }
          else
            {
              // uh oh...handle removed from process_table_, even though
              // we're holding a lock!
              delete [] handles;
              ACE_ERROR_RETURN ((LM_ERROR,
                                 ACE_TEXT ("Process removed")
                                 ACE_TEXT (" -- somebody's ignoring the lock!\n")),
                                -1);
            }
        }
      delete [] handles;
#else /* !defined(ACE_WIN32) */
      if (timeout == ACE_Time_Value::max_time)
        pid = ACE_OS::waitpid (-1, status, 0);
      else if (timeout == ACE_Time_Value::zero)
        pid = ACE_OS::waitpid (-1, status, WNOHANG);
      else
        {
# if defined (ACE_LACKS_UNIX_SIGNALS)
          pid = 0;
          ACE_Time_Value sleeptm (1);    // 1 msec
          if (sleeptm > timeout)         // if sleeptime > waittime
            sleeptm = timeout;
          ACE_Time_Value tmo (timeout);  // Need one we can change
          for (ACE_Countdown_Time time_left (&tmo); tmo > ACE_Time_Value::zero ; time_left.update ())
            {
              pid = ACE_OS::waitpid (-1, status, WNOHANG);
              if (pid > 0 || pid == ACE_INVALID_PID)
                break;          // Got a child or an error - all done
              // pid 0, nothing is ready yet, so wait.
              // Do a (very) short sleep (only this thread sleeps).
              ACE_OS::sleep (sleeptm);
            }
# else
          // Force generation of SIGCHLD, even though we don't want to
          // catch it - just need it to interrupt the sleep below.
          // If this object has a reactor set, assume it was given at
          // open(), and there's already a SIGCHLD action set, so no
          // action is needed here.
          ACE_Sig_Action old_action;
          if (this->reactor () == 0)
            {
              ACE_Sig_Action do_sigchld ((ACE_SignalHandler)sigchld_nop);
              do_sigchld.register_action (SIGCHLD, &old_action);
            }
          ACE_Time_Value tmo (timeout);  // Need one we can change
          for (ACE_Countdown_Time time_left (&tmo); ; time_left.update ())
            {
              pid = ACE_OS::waitpid (-1, status, WNOHANG);
#   if defined (ACE_VXWORKS) && (ACE_VXWORKS >= 0x600)
              if (pid > 0 || (pid == ACE_INVALID_PID && errno != EINTR))
#   else
                if (pid > 0 || pid == ACE_INVALID_PID)
#   endif
                  break;          // Got a child or an error - all done
              // pid 0, nothing is ready yet, so wait.
              // Do a sleep (only this thread sleeps) til something
              // happens. This relies on SIGCHLD interrupting the sleep.
              // If SIGCHLD isn't delivered, we'll need to do something
              // with sigaction to force it.
              if (-1 == ACE_OS::sleep (tmo) && errno == EINTR)
                continue;
              // Timed out
              pid = 0;
              break;
            }
          // Restore the previous SIGCHLD action if it was changed.
          if (this->reactor () == 0)
            old_action.register_action (SIGCHLD);
# endif /* !ACE_LACKS_UNIX_SIGNALS */
        }
#endif /* !defined (ACE_WIN32) */
    }
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon, this->lock_, -1));
  if (pid != ACE_INVALID_PID && pid != 0)
    {
      //we always need to get our id, because we could have been moved in the table meanwhile
      idx = this->find_proc (pid);
      if (idx == -1)
        {
          // oops, reaped an unmanaged process!
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("(%P|%t) oops, reaped unmanaged %d\n"),
                      pid));
          return pid;
        }
      else
        proc = process_table_[idx].process_;
      if (proc != 0)
        ACE_ASSERT (pid == proc->getpid ());
      this->notify_proc_handler (idx,
                                 *status);
      this->remove (pid);
    }
  return pid;
}
// Legacy method:
int
ACE_Process_Manager::reap (pid_t pid,
                           ACE_exitcode *stat_loc,
                           int options)
{
  ACE_TRACE ("ACE_Process_Manager::reap");
  return this->wait (pid,
                     (ACE_BIT_ENABLED (options, WNOHANG)
                      ? ACE_Time_Value::zero
                      : ACE_Time_Value::max_time),
                     stat_loc);
}
// Notify either the process-specific handler or the generic handler.
// If process-specific, call handle_close on the handler.  Returns 1
// if process found, 0 if not.  Must be called with locks held.
int
ACE_Process_Manager::notify_proc_handler (size_t i,
                                          ACE_exitcode exit_code)
{
  if (i < this->current_count_)
    {
      Process_Descriptor &proc_desc =
        this->process_table_[i];
      proc_desc.process_->exit_code (exit_code);
      if (proc_desc.exit_notify_ != 0)
        proc_desc.exit_notify_->handle_exit (proc_desc.process_);
      else if (this->default_exit_handler_ != 0
               && this->default_exit_handler_->handle_exit (proc_desc.process_) < 0)
        {
          this->default_exit_handler_->handle_close
            (ACE_INVALID_HANDLE,
             0);
          this->default_exit_handler_ = 0;
        }
      return 1;
    }
  else
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("(%P:%t|%T) ACE_Process_Manager::notify_proc_handler:")
                  ACE_TEXT (" unknown/unmanaged process reaped\n")));
      return 0;
    }
}
ACE_END_VERSIONED_NAMESPACE_DECL

