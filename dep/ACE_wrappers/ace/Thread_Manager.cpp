// $Id: Thread_Manager.cpp 82600 2008-08-12 08:04:24Z johnnyw $

#include "ace/TSS_T.h"
#include "ace/Thread_Manager.h"
#include "ace/Dynamic.h"
#include "ace/Object_Manager.h"
#include "ace/Singleton.h"
#include "ace/Auto_Ptr.h"
#include "ace/Guard_T.h"
#include "ace/Time_Value.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/Truncate.h"

#if !defined (__ACE_INLINE__)
#include "ace/Thread_Manager.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID (ace,
           Thread_Manager,
           "$Id: Thread_Manager.cpp 82600 2008-08-12 08:04:24Z johnnyw $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_At_Thread_Exit::~ACE_At_Thread_Exit (void)
{
  this->do_apply ();
}

ACE_At_Thread_Exit_Func::~ACE_At_Thread_Exit_Func (void)
{
  this->do_apply ();
}

void
ACE_At_Thread_Exit_Func::apply (void)
{
  this->func_ (this->object_, this->param_);
}

ACE_ALLOC_HOOK_DEFINE(ACE_Thread_Control)
ACE_ALLOC_HOOK_DEFINE(ACE_Thread_Manager)

#if ! defined (ACE_THREAD_MANAGER_LACKS_STATICS)
// Process-wide Thread Manager.
ACE_Thread_Manager *ACE_Thread_Manager::thr_mgr_ = 0;

// Controls whether the Thread_Manager is deleted when we shut down
// (we can only delete it safely if we created it!)
bool ACE_Thread_Manager::delete_thr_mgr_ = false;
#endif /* ! defined (ACE_THREAD_MANAGER_LACKS_STATICS) */

ACE_TSS_TYPE (ACE_Thread_Exit) *ACE_Thread_Manager::thr_exit_ = 0;

int
ACE_Thread_Manager::set_thr_exit (ACE_TSS_TYPE (ACE_Thread_Exit) *ptr)
{
  if (ACE_Thread_Manager::thr_exit_ == 0)
    ACE_Thread_Manager::thr_exit_ = ptr;
  else
    return -1;
  return 0;
}

void
ACE_Thread_Manager::dump (void)
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Thread_Manager::dump");
  // Cast away const-ness of this in order to use its non-const lock_.
  ACE_MT (ACE_GUARD (ACE_Thread_Mutex, ace_mon,
                     ((ACE_Thread_Manager *) this)->lock_));

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ngrp_id_ = %d"), this->grp_id_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ncurrent_count_ = %d"), this->thr_list_.size ()));

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      iter.next ()->dump ();
    }

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Thread_Descriptor::~ACE_Thread_Descriptor (void)
{
  delete this->sync_;
}

void
ACE_Thread_Descriptor::at_pop (int apply)
{
  ACE_TRACE ("ACE_Thread_Descriptor::at_pop");
  // Get first at from at_exit_list
  ACE_At_Thread_Exit* at = this->at_exit_list_;
  // Remove at from at_exit list
  this->at_exit_list_ = at->next_;
  // Apply if required
  if (apply)
   {
     at->apply ();
     // Do the apply method
     at->was_applied (true);
     // Mark at has been applied to avoid double apply from
     // at destructor
   }
  // If at is not owner delete at.
  if (!at->is_owner ())
   delete at;
}

void
ACE_Thread_Descriptor::at_push (ACE_At_Thread_Exit* cleanup, bool is_owner)
{
  ACE_TRACE ("ACE_Thread_Descriptor::at_push");
  cleanup->is_owner (is_owner);
  cleanup->td_ = this;
  cleanup->next_ = at_exit_list_;
  at_exit_list_ = cleanup;
}

int
ACE_Thread_Descriptor::at_exit (ACE_At_Thread_Exit& cleanup)
{
  ACE_TRACE ("ACE_Thread_Descriptor::at_exit");
  at_push (&cleanup, 1);
  return 0;
}

int
ACE_Thread_Descriptor::at_exit (ACE_At_Thread_Exit* cleanup)
{
  ACE_TRACE ("ACE_Thread_Descriptor::at_exit");
  if (cleanup==0)
   return -1;
  else
   {
     this->at_push (cleanup);
     return 0;
   }
}

void
ACE_Thread_Descriptor::do_at_exit ()
{
  ACE_TRACE ("ACE_Thread_Descriptor::do_at_exit");
  while (at_exit_list_!=0)
    this->at_pop ();
}

void
ACE_Thread_Descriptor::terminate ()
{
  ACE_TRACE ("ACE_Thread_Descriptor::terminate");

  if (!terminated_)
   {
     ACE_Log_Msg* log_msg = this->log_msg_;
     terminated_ = true;
     // Run at_exit hooks
     this->do_at_exit ();
     // We must remove Thread_Descriptor from Thread_Manager list
     if (this->tm_ != 0)
      {
         int close_handle = 0;

#if !defined (ACE_HAS_VXTHREADS)
         // Threads created with THR_DAEMON shouldn't exist here, but
         // just to be safe, let's put it here.

         if (ACE_BIT_DISABLED (this->thr_state_, ACE_Thread_Manager::ACE_THR_JOINING))
           {
             if (ACE_BIT_DISABLED (this->flags_, THR_DETACHED | THR_DAEMON)
                 || ACE_BIT_ENABLED (this->flags_, THR_JOINABLE))
               {
                 // Mark thread as terminated.
                 ACE_SET_BITS (this->thr_state_, ACE_Thread_Manager::ACE_THR_TERMINATED);
                 tm_->register_as_terminated (this);
                 // Must copy the information here because td will be
                 // "freed" below.
               }
#if defined (ACE_WIN32)
             else
               {
                 close_handle = 1;
               }
#endif /* ACE_WIN32 */
           }
#endif /* !ACE_HAS_VXTHREADS */

         // Remove thread descriptor from the table.
         if (this->tm_ != 0)
           tm_->remove_thr (this, close_handle);
      }

     // Check if we need delete ACE_Log_Msg instance
     // If ACE_TSS_cleanup was not executed first log_msg == 0
     if (log_msg == 0)
      {
        // Only inform to ACE_TSS_cleanup that it must delete the log instance
        // setting ACE_LOG_MSG thr_desc to 0.
        ACE_LOG_MSG->thr_desc (0);
      }
     else
      {
        // Thread_Descriptor is the owner of the Log_Msg instance!!
        // deleted.
        this->log_msg_ = 0;
        delete log_msg;
      }
   }
}

int
ACE_Thread_Descriptor::at_exit (void *object,
                                ACE_CLEANUP_FUNC cleanup_hook,
                                void *param)
{
  ACE_TRACE ("ACE_Thread_Descriptor::at_exit");
  // To keep compatibility, when cleanup_hook is null really is a at_pop
  // without apply.
  if (cleanup_hook == 0)
   {
     if (this->at_exit_list_!= 0)
      this->at_pop(0);
   }
  else
   {
     ACE_At_Thread_Exit* cleanup = 0;
     ACE_NEW_RETURN (cleanup,
                     ACE_At_Thread_Exit_Func (object,
                                              cleanup_hook,
                                              param),
                     -1);
     this->at_push (cleanup);
   }
  return 0;
}

void
ACE_Thread_Descriptor::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Thread_Descriptor::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nthr_id_ = %d"), this->thr_id_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nthr_handle_ = %d"), this->thr_handle_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ngrp_id_ = %d"), this->grp_id_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nthr_state_ = %d"), this->thr_state_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ncleanup_info_.cleanup_hook_ = %x"), this->cleanup_info_.cleanup_hook_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nflags_ = %x\n"), this->flags_));

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Thread_Descriptor::ACE_Thread_Descriptor (void)
  : log_msg_ (0),
    at_exit_list_ (0),
    terminated_ (false)
{
  ACE_TRACE ("ACE_Thread_Descriptor::ACE_Thread_Descriptor");
  ACE_NEW (this->sync_,
           ACE_DEFAULT_THREAD_MANAGER_LOCK);
}

void
ACE_Thread_Descriptor::acquire_release (void)
{
  // Just try to acquire the lock then release it.
#if defined (ACE_THREAD_MANAGER_USES_SAFE_SPAWN)
  if (ACE_BIT_DISABLED (this->thr_state_, ACE_Thread_Manager::ACE_THR_SPAWNED))
#endif /* ACE_THREAD_MANAGER_USES_SAFE_SPAWN */
    {
      this->sync_->acquire ();
      // Acquire the lock before removing <td> from the thread table.  If
      // this thread is in the table already, it should simply acquire the
      // lock easily.

      // Once we get the lock, we must have registered.
      ACE_ASSERT (ACE_BIT_ENABLED (this->thr_state_, ACE_Thread_Manager::ACE_THR_SPAWNED));

      this->sync_->release ();
      // Release the lock before putting it back to freelist.
    }
}

void
ACE_Thread_Descriptor::acquire (void)
{
  // Just try to acquire the lock then release it.
#if defined (ACE_THREAD_MANAGER_USES_SAFE_SPAWN)
  if (ACE_BIT_DISABLED (this->thr_state_, ACE_Thread_Manager::ACE_THR_SPAWNED))
#endif /* ACE_THREAD_MANAGER_USES_SAFE_SPAWN */
    {
      this->sync_->acquire ();
    }
}

void
ACE_Thread_Descriptor::release (void)
{
  // Just try to acquire the lock then release it.
#if defined (ACE_THREAD_MANAGER_USES_SAFE_SPAWN)
  if (ACE_BIT_DISABLED (this->thr_state_, ACE_Thread_Manager::ACE_THR_SPAWNED))
#endif /* ACE_THREAD_MANAGER_USES_SAFE_SPAWN */
    {
      this->sync_->release ();
      // Release the lock before putting it back to freelist.
    }
}

// The following macro simplifies subsequence code.
#define ACE_FIND(OP,INDEX) \
  ACE_Thread_Descriptor *INDEX = OP; \

ACE_Thread_Descriptor *
ACE_Thread_Manager::thread_descriptor (ACE_thread_t thr_id)
{
  ACE_TRACE ("ACE_Thread_Manager::thread_descriptor");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, 0));

  ACE_FIND (this->find_thread (thr_id), ptr);
  return ptr;
}

ACE_Thread_Descriptor *
ACE_Thread_Manager::hthread_descriptor (ACE_hthread_t thr_handle)
{
  ACE_TRACE ("ACE_Thread_Manager::hthread_descriptor");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, 0));

  ACE_FIND (this->find_hthread (thr_handle), ptr);
  return ptr;
}

// Return the thread descriptor (indexed by ACE_hthread_t).

int
ACE_Thread_Manager::thr_self (ACE_hthread_t &self)
{
  ACE_TRACE ("ACE_Thread_Manager::thr_self");

  ACE_Thread_Descriptor *desc =
    this->thread_desc_self ();

  if (desc == 0)
    return -1;
  else
    desc->self (self);

  return 0;
}

// Initialize the synchronization variables.

ACE_Thread_Manager::ACE_Thread_Manager (size_t prealloc,
                                        size_t lwm,
                                        size_t inc,
                                        size_t hwm)
  : grp_id_ (1),
    automatic_wait_ (1)
#if defined (ACE_HAS_THREADS)
    , zero_cond_ (lock_)
#endif /* ACE_HAS_THREADS */
    , thread_desc_freelist_ (ACE_FREE_LIST_WITH_POOL,
                             prealloc, lwm, hwm, inc)
{
  ACE_TRACE ("ACE_Thread_Manager::ACE_Thread_Manager");
}

#if ! defined (ACE_THREAD_MANAGER_LACKS_STATICS)
ACE_Thread_Manager *
ACE_Thread_Manager::instance (void)
{
  ACE_TRACE ("ACE_Thread_Manager::instance");

  if (ACE_Thread_Manager::thr_mgr_ == 0)
    {
      // Perform Double-Checked Locking Optimization.
      ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                                *ACE_Static_Object_Lock::instance (), 0));

      if (ACE_Thread_Manager::thr_mgr_ == 0)
        {
          ACE_NEW_RETURN (ACE_Thread_Manager::thr_mgr_,
                          ACE_Thread_Manager,
                          0);
          ACE_Thread_Manager::delete_thr_mgr_ = true;
        }
    }

  return ACE_Thread_Manager::thr_mgr_;
}

ACE_Thread_Manager *
ACE_Thread_Manager::instance (ACE_Thread_Manager *tm)
{
  ACE_TRACE ("ACE_Thread_Manager::instance");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                            *ACE_Static_Object_Lock::instance (), 0));

  ACE_Thread_Manager *t = ACE_Thread_Manager::thr_mgr_;
  // We can't safely delete it since we don't know who created it!
  ACE_Thread_Manager::delete_thr_mgr_ = false;

  ACE_Thread_Manager::thr_mgr_ = tm;
  return t;
}

void
ACE_Thread_Manager::close_singleton (void)
{
  ACE_TRACE ("ACE_Thread_Manager::close_singleton");

  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex, ace_mon,
                     *ACE_Static_Object_Lock::instance ()));

  if (ACE_Thread_Manager::delete_thr_mgr_)
    {
      // First, we clean up the thread descriptor list.
      ACE_Thread_Manager::thr_mgr_->close ();
      delete ACE_Thread_Manager::thr_mgr_;
      ACE_Thread_Manager::thr_mgr_ = 0;
      ACE_Thread_Manager::delete_thr_mgr_ = false;
    }

  ACE_Thread_Exit::cleanup (ACE_Thread_Manager::thr_exit_);
}
#endif /* ! defined (ACE_THREAD_MANAGER_LACKS_STATICS) */

// Close up and release all resources.

int
ACE_Thread_Manager::close ()
{
  ACE_TRACE ("ACE_Thread_Manager::close");

  // Clean up the thread descriptor list.
  if (this->automatic_wait_)
    this->wait (0, 1);
  else
    {
      ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

      this->remove_thr_all ();
    }

  return 0;
}

ACE_Thread_Manager::~ACE_Thread_Manager (void)
{
  ACE_TRACE ("ACE_Thread_Manager::~ACE_Thread_Manager");
  this->close ();
}


// Run the entry point for thread spawned under the control of the
// <ACE_Thread_Manager>.  This must be an extern "C" to make certain
// compilers happy...
//
// The interaction with <ACE_Thread_Exit> and
// <ace_thread_manager_adapter> works like this, with
// ACE_HAS_THREAD_SPECIFIC_STORAGE or ACE_HAS_TSS_EMULATION:
//
// o Every thread in the <ACE_Thread_Manager> is run with
//   <ace_thread_manager_adapter>.
//
// o <ace_thread_manager_adapter> retrieves the singleton
//   <ACE_Thread_Exit> instance from <ACE_Thread_Exit::instance>.
//   The singleton gets created in thread-specific storage
//   in the first call to that function.  The key point is that the
//   instance is in thread-specific storage.
//
// o A thread can exit by various means, such as <ACE_Thread::exit>, C++
//   or Win32 exception, "falling off the end" of the thread entry
//   point function, etc.
//
// o If you follow this so far, now it gets really fun . . .
//   When the thread-specific storage (for the thread that
//   is being destroyed) is cleaned up, the OS threads package (or
//   the ACE emulation of thread-specific storage) will destroy any
//   objects that are in thread-specific storage.  It has a list of
//   them, and just walks down the list and destroys each one.
//
// o That's where the ACE_Thread_Exit destructor gets called.

#if defined(ACE_USE_THREAD_MANAGER_ADAPTER)
extern "C" void *
ace_thread_manager_adapter (void *args)
{
#if defined (ACE_HAS_TSS_EMULATION)
  // As early as we can in the execution of the new thread, allocate
  // its local TS storage.  Allocate it on the stack, to save dynamic
  // allocation/dealloction.
  void *ts_storage[ACE_TSS_Emulation::ACE_TSS_THREAD_KEYS_MAX];
  ACE_TSS_Emulation::tss_open (ts_storage);
#endif /* ACE_HAS_TSS_EMULATION */

  ACE_Thread_Adapter *thread_args = reinterpret_cast<ACE_Thread_Adapter *> (args);

  // NOTE: this preprocessor directive should match the one in above
  // ACE_Thread_Exit::instance ().  With the Xavier Pthreads package,
  // the exit_hook in TSS causes a seg fault.  So, this works around
  // that by creating exit_hook on the stack.
#if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION)
  // Obtain our thread-specific exit hook and make sure that it knows
  // how to clean us up!  Note that we never use this pointer directly
  // (it's stored in thread-specific storage), so it's ok to
  // dereference it here and only store it as a reference.
  ACE_Thread_Exit &exit_hook = *ACE_Thread_Exit::instance ();
#else
  // Without TSS, create an <ACE_Thread_Exit> instance.  When this
  // function returns, its destructor will be called because the
  // object goes out of scope.  The drawback with this appraoch is
  // that the destructor _won't_ get called if <thr_exit> is called.
  // So, threads shouldn't exit that way.  Instead, they should return
  // from <svc>.
  ACE_Thread_Exit exit_hook;
#endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE || ACE_HAS_TSS_EMULATION */

  // Keep track of the <Thread_Manager> that's associated with this
  // <exit_hook>.
  exit_hook.thr_mgr (thread_args->thr_mgr ());

  // Invoke the user-supplied function with the args.
  void *status = thread_args->invoke ();

  delete static_cast<ACE_Base_Thread_Adapter *> (thread_args);
  return status;
}
#endif

// Call the appropriate OS routine to spawn a thread.  Should *not* be
// called with the lock_ held...

int
ACE_Thread_Manager::spawn_i (ACE_THR_FUNC func,
                             void *args,
                             long flags,
                             ACE_thread_t *t_id,
                             ACE_hthread_t *t_handle,
                             long priority,
                             int grp_id,
                             void *stack,
                             size_t stack_size,
                             ACE_Task_Base *task,
                             const char** thr_name)
{
  // First, threads created by Thread Manager should not be daemon threads.
  // Using assertion is probably a bit too strong.  However, it helps
  // finding this kind of error as early as possible.  Perhaps we can replace
  // assertion by returning error.
  ACE_ASSERT (ACE_BIT_DISABLED (flags, THR_DAEMON));

  // Create a new thread running <func>.  *Must* be called with the
  // <lock_> held...
  // Get a "new" Thread Descriptor from the freelist.
  auto_ptr<ACE_Thread_Descriptor> new_thr_desc (this->thread_desc_freelist_.remove ());

  // Reset thread descriptor status
  new_thr_desc->reset (this);

  ACE_Thread_Adapter *thread_args = 0;
# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
  ACE_NEW_RETURN (thread_args,
                  ACE_Thread_Adapter (func,
                                      args,
                                      (ACE_THR_C_FUNC) ACE_THREAD_ADAPTER_NAME,
                                      this,
                                      new_thr_desc.get (),
                                      ACE_OS_Object_Manager::seh_except_selector(),
                                      ACE_OS_Object_Manager::seh_except_handler()),
                  -1);
# else
  ACE_NEW_RETURN (thread_args,
                  ACE_Thread_Adapter (func,
                                      args,
                                      (ACE_THR_C_FUNC) ACE_THREAD_ADAPTER_NAME,
                                      this,
                                      new_thr_desc.get ()),
                  -1);
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
  auto_ptr <ACE_Base_Thread_Adapter> auto_thread_args (static_cast<ACE_Base_Thread_Adapter *> (thread_args));

  ACE_TRACE ("ACE_Thread_Manager::spawn_i");
  ACE_hthread_t thr_handle;

  ACE_thread_t thr_id;
  if (t_id == 0)
    t_id = &thr_id;

  // Acquire the <sync_> lock to block the spawned thread from
  // removing this Thread Descriptor before it gets put into our
  // thread table.
  new_thr_desc->sync_->acquire ();

  int const result = ACE_Thread::spawn (func,
                                        args,
                                        flags,
                                        t_id,
                                        &thr_handle,
                                        priority,
                                        stack,
                                        stack_size,
                                        thread_args,
                                        thr_name);

  if (result != 0)
    {
      // _Don't_ clobber errno here!  result is either 0 or -1, and
      // ACE_OS::thr_create () already set errno!  D. Levine 28 Mar 1997
      // errno = result;
      ACE_Errno_Guard guard (errno);     // Lock release may smash errno
      new_thr_desc->sync_->release ();
      return -1;
    }
  auto_thread_args.release ();

#if defined (ACE_HAS_WTHREADS)
  // Have to duplicate handle if client asks for it.
  // @@ How are thread handles implemented on AIX?  Do they
  // also need to be duplicated?
  if (t_handle != 0)
# if defined (ACE_HAS_WINCE)
    *t_handle = thr_handle;
# else  /* ! ACE_HAS_WINCE */
  (void) ::DuplicateHandle (::GetCurrentProcess (),
                            thr_handle,
                            ::GetCurrentProcess (),
                            t_handle,
                            0,
                            TRUE,
                            DUPLICATE_SAME_ACCESS);
# endif /* ! ACE_HAS_WINCE */
#else  /* ! ACE_HAS_WTHREADS */
  if (t_handle != 0)
    *t_handle = thr_handle;
#endif /* ! ACE_HAS_WTHREADS */

  // append_thr also put the <new_thr_desc> into Thread_Manager's
  // double-linked list.  Only after this point, can we manipulate
  // double-linked list from a spawned thread's context.
  return this->append_thr (*t_id,
                           thr_handle,
                           ACE_THR_SPAWNED,
                           grp_id,
                           task,
                           flags,
                           new_thr_desc.release ());
}

int
ACE_Thread_Manager::spawn (ACE_THR_FUNC func,
                           void *args,
                           long flags,
                           ACE_thread_t *t_id,
                           ACE_hthread_t *t_handle,
                           long priority,
                           int grp_id,
                           void *stack,
                           size_t stack_size,
                           const char** thr_name)
{
  ACE_TRACE ("ACE_Thread_Manager::spawn");

  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  if (grp_id == -1)
    grp_id = this->grp_id_++; // Increment the group id.

  if (priority != ACE_DEFAULT_THREAD_PRIORITY)
    ACE_CLR_BITS (flags, THR_INHERIT_SCHED);

  if (this->spawn_i (func,
                     args,
                     flags,
                     t_id,
                     t_handle,
                     priority,
                     grp_id,
                     stack,
                     stack_size,
                     0,
                     thr_name) == -1)
    return -1;

  return grp_id;
}

// Create N new threads running FUNC.

int
ACE_Thread_Manager::spawn_n (size_t n,
                             ACE_THR_FUNC func,
                             void *args,
                             long flags,
                             long priority,
                             int grp_id,
                             ACE_Task_Base *task,
                             ACE_hthread_t thread_handles[],
                             void *stack[],
                             size_t stack_size[],
                             const char* thr_name[])
{
  ACE_TRACE ("ACE_Thread_Manager::spawn_n");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  if (grp_id == -1)
    grp_id = this->grp_id_++; // Increment the group id.

  for (size_t i = 0; i < n; i++)
    {
      // @@ What should happen if this fails?! e.g., should we try to
      // cancel the other threads that we've already spawned or what?
      if (this->spawn_i (func,
                         args,
                         flags,
                         0,
                         thread_handles == 0 ? 0 : &thread_handles[i],
                         priority,
                         grp_id,
                         stack == 0 ? 0 : stack[i],
                         stack_size == 0 ? ACE_DEFAULT_THREAD_STACKSIZE : stack_size[i],
                         task,
                         thr_name == 0 ? 0 : &thr_name [i]) == -1)
        return -1;
    }

  return grp_id;
}

// Create N new threads running FUNC.

int
ACE_Thread_Manager::spawn_n (ACE_thread_t thread_ids[],
                             size_t n,
                             ACE_THR_FUNC func,
                             void *args,
                             long flags,
                             long priority,
                             int grp_id,
                             void *stack[],
                             size_t stack_size[],
                             ACE_hthread_t thread_handles[],
                             ACE_Task_Base *task,
                             const char* thr_name[])
{
  ACE_TRACE ("ACE_Thread_Manager::spawn_n");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  if (grp_id == -1)
    grp_id = this->grp_id_++; // Increment the group id.

  for (size_t i = 0; i < n; i++)
    {
      // @@ What should happen if this fails?! e.g., should we try to
      // cancel the other threads that we've already spawned or what?
      if (this->spawn_i (func,
                         args,
                         flags,
                         thread_ids == 0 ? 0 : &thread_ids[i],
                         thread_handles == 0 ? 0 : &thread_handles[i],
                         priority,
                         grp_id,
                         stack == 0 ? 0 : stack[i],
                         stack_size == 0 ? ACE_DEFAULT_THREAD_STACKSIZE : stack_size[i],
                         task,
                         thr_name == 0 ? 0 : &thr_name [i]) == -1)
        return -1;
    }

  return grp_id;
}

// Append a thread into the pool (does not check for duplicates).
// Must be called with locks held.

int
ACE_Thread_Manager::append_thr (ACE_thread_t t_id,
                                ACE_hthread_t t_handle,
                                ACE_UINT32 thr_state,
                                int grp_id,
                                ACE_Task_Base *task,
                                long flags,
                                ACE_Thread_Descriptor *td)
{
  ACE_TRACE ("ACE_Thread_Manager::append_thr");
  ACE_Thread_Descriptor *thr_desc = 0;

  if (td == 0)
    {
      ACE_NEW_RETURN (thr_desc,
                      ACE_Thread_Descriptor,
                      -1);
      thr_desc->tm_ = this;
      // Setup the Thread_Manager.
    }
  else
    thr_desc = td;

  thr_desc->thr_id_ = t_id;
  thr_desc->thr_handle_ = t_handle;
  thr_desc->grp_id_ = grp_id;
  thr_desc->task_ = task;
  thr_desc->flags_ = flags;

  this->thr_list_.insert_head (thr_desc);
  ACE_SET_BITS (thr_desc->thr_state_, thr_state);
  thr_desc->sync_->release ();

  return 0;
}

// Return the thread descriptor (indexed by ACE_hthread_t).

ACE_Thread_Descriptor *
ACE_Thread_Manager::find_hthread (ACE_hthread_t h_id)
{
  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (ACE_OS::thr_cmp (iter.next ()->thr_handle_, h_id))
        {
          return iter.next ();
        }
    }

  return 0;
}

// Locate the index in the table associated with <t_id>.  Must be
// called with the lock held.

ACE_Thread_Descriptor *
ACE_Thread_Manager::find_thread (ACE_thread_t t_id)
{
  ACE_TRACE ("ACE_Thread_Manager::find_thread");

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (ACE_OS::thr_equal (iter.next ()->thr_id_, t_id))
        {
          return iter.next ();
        }
    }
  return 0;
}

// Insert a thread into the pool (checks for duplicates and doesn't
// allow them to be inserted twice).

int
ACE_Thread_Manager::insert_thr (ACE_thread_t t_id,
                                ACE_hthread_t t_handle,
                                int grp_id,
                                long flags)
{
  ACE_TRACE ("ACE_Thread_Manager::insert_thr");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  // Check for duplicates and bail out if we're already registered...
  if (this->find_thread (t_id) != 0 )
    return -1;

  if (grp_id == -1)
    grp_id = this->grp_id_++;

  if (this->append_thr (t_id,
                        t_handle,
                        ACE_THR_SPAWNED,
                        grp_id,
                        0,
                        flags) == -1)
    return -1;

  return grp_id;
}

// Run the registered hooks when the thread exits.

void
ACE_Thread_Manager::run_thread_exit_hooks (int i)
{
#if 0 // currently unused!
  ACE_TRACE ("ACE_Thread_Manager::run_thread_exit_hooks");

  // @@ Currently, we have just one hook.  This should clearly be
  // generalized to support an arbitrary number of hooks.

  ACE_Thread_Descriptor *td = this->thread_desc_self ();
  if (td != 0 && td->cleanup_info.cleanup_hook_ != 0)
    {
      (*td->cleanup_info_.cleanup_hook_)
        (td->cleanup_info_.object_,
         td->cleanup_info_.param_);

      td->cleanup_info_.cleanup_hook_ = 0;
    }
  ACE_UNUSED_ARG (i);
#else
  ACE_UNUSED_ARG (i);
#endif /* 0 */
}

// Remove a thread from the pool.  Must be called with locks held.

void
ACE_Thread_Manager::remove_thr (ACE_Thread_Descriptor *td,
                                int close_handler)
{
  ACE_TRACE ("ACE_Thread_Manager::remove_thr");

  td->tm_ = 0;
  this->thr_list_.remove (td);

#if defined (ACE_WIN32)
  if (close_handler != 0)
    ::CloseHandle (td->thr_handle_);
#else
  ACE_UNUSED_ARG (close_handler);
#endif /* ACE_WIN32 */

  this->thread_desc_freelist_.add (td);

#if defined (ACE_HAS_THREADS)
  // Tell all waiters when there are no more threads left in the pool.
  if (this->thr_list_.size () == 0)
    this->zero_cond_.broadcast ();
#endif /* ACE_HAS_THREADS */
}

// Repeatedly call remove_thr on all table entries until there
// is no thread left.   Must be called with lock held.
void
ACE_Thread_Manager::remove_thr_all (void)
{
  ACE_Thread_Descriptor *td = 0;

  while ((td = this->thr_list_.delete_head ()) != 0)
    {
      this->remove_thr (td, 1);
    }
}

// ------------------------------------------------------------------
// Factor out some common behavior to simplify the following methods.
#define ACE_THR_OP(OP,STATE) \
  int result = OP (td->thr_handle_); \
  if (result == -1) { \
    if (errno != ENOTSUP) \
      this->thr_to_be_removed_.enqueue_tail (td); \
    return -1; \
  } \
  else { \
    ACE_SET_BITS (td->thr_state_, STATE); \
    return 0; \
  }

int
ACE_Thread_Manager::join_thr (ACE_Thread_Descriptor *td, int)
{
  ACE_TRACE ("ACE_Thread_Manager::join_thr");
  int const result = ACE_Thread::join (td->thr_handle_);
  if (result != 0)
    {
      // Since the thread are being joined, we should
      // let it remove itself from the list.

      //      this->remove_thr (td);
      errno = result;
      return -1;
    }

  return 0;
}

int
ACE_Thread_Manager::suspend_thr (ACE_Thread_Descriptor *td, int)
{
  ACE_TRACE ("ACE_Thread_Manager::suspend_thr");

  int const result = ACE_Thread::suspend (td->thr_handle_);
  if (result == -1) {
    if (errno != ENOTSUP)
      this->thr_to_be_removed_.enqueue_tail (td);
    return -1;
  }
  else {
    ACE_SET_BITS (td->thr_state_, ACE_THR_SUSPENDED);
    return 0;
  }
}

int
ACE_Thread_Manager::resume_thr (ACE_Thread_Descriptor *td, int)
{
  ACE_TRACE ("ACE_Thread_Manager::resume_thr");

  int const result = ACE_Thread::resume (td->thr_handle_);
  if (result == -1) {
    if (errno != ENOTSUP)
      this->thr_to_be_removed_.enqueue_tail (td);
    return -1;
  }
  else {
    ACE_CLR_BITS (td->thr_state_, ACE_THR_SUSPENDED);
    return 0;
  }
}

int
ACE_Thread_Manager::cancel_thr (ACE_Thread_Descriptor *td, int async_cancel)
{
  ACE_TRACE ("ACE_Thread_Manager::cancel_thr");
  // Must set the state first and then try to cancel the thread.
  ACE_SET_BITS (td->thr_state_, ACE_THR_CANCELLED);

  if (async_cancel != 0)
    // Note that this call only does something relevant if the OS
    // platform supports asynchronous thread cancellation.  Otherwise,
    // it's a no-op.
    return ACE_Thread::cancel (td->thr_id_);

  return 0;
}

int
ACE_Thread_Manager::kill_thr (ACE_Thread_Descriptor *td, int signum)
{
  ACE_TRACE ("ACE_Thread_Manager::kill_thr");

  ACE_thread_t tid = td->thr_id_;

  int const result = ACE_Thread::kill (tid, signum);

  if (result != 0)
    {
      // Only remove a thread from us when there is a "real" error.
      if (errno != ENOTSUP)
        this->thr_to_be_removed_.enqueue_tail (td);

      return -1;
    }

    return 0;
}

// ------------------------------------------------------------------
// Factor out some common behavior to simplify the following methods.
#define ACE_EXECUTE_OP(OP, ARG) \
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1)); \
  ACE_ASSERT (this->thr_to_be_removed_.is_empty ()); \
  ACE_FIND (this->find_thread (t_id), ptr); \
  if (ptr == 0) \
    { \
      errno = ENOENT; \
      return -1; \
    } \
  int result = OP (ptr, ARG); \
  ACE_Errno_Guard error (errno); \
  while (! this->thr_to_be_removed_.is_empty ()) { \
    ACE_Thread_Descriptor * td = 0; \
    this->thr_to_be_removed_.dequeue_head (td); \
    this->remove_thr (td, 1); \
  } \
  return result

// Suspend a single thread.

int
ACE_Thread_Manager::suspend (ACE_thread_t t_id)
{
  ACE_TRACE ("ACE_Thread_Manager::suspend");
  ACE_EXECUTE_OP (this->suspend_thr, 0);
}

// Resume a single thread.

int
ACE_Thread_Manager::resume (ACE_thread_t t_id)
{
  ACE_TRACE ("ACE_Thread_Manager::resume");
  ACE_EXECUTE_OP (this->resume_thr, 0);
}

// Cancel a single thread.

int
ACE_Thread_Manager::cancel (ACE_thread_t t_id, int async_cancel)
{
  ACE_TRACE ("ACE_Thread_Manager::cancel");
  ACE_EXECUTE_OP (this->cancel_thr, async_cancel);
}

// Send a signal to a single thread.

int
ACE_Thread_Manager::kill (ACE_thread_t t_id, int signum)
{
  ACE_TRACE ("ACE_Thread_Manager::kill");
  ACE_EXECUTE_OP (this->kill_thr, signum);
}

int
ACE_Thread_Manager::check_state (ACE_UINT32 state,
                                 ACE_thread_t id,
                                 int enable)
{
  ACE_TRACE ("ACE_Thread_Manager::check_state");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  ACE_UINT32 thr_state;

  int self_check = ACE_OS::thr_equal (id, ACE_OS::thr_self ());

  // If we're checking the state of our thread, try to get the cached
  // value out of TSS to avoid lookup.
  if (self_check)
    {
      ACE_Thread_Descriptor *desc = ACE_LOG_MSG->thr_desc ();
      if (desc == 0)
        return 0;               // Always return false.
      thr_state = desc->thr_state_;
    }
  else
    {
      // Not calling from self, have to look it up from the list.
      ACE_FIND (this->find_thread (id), ptr);
      if (ptr == 0)
        return 0;
      thr_state = ptr->thr_state_;
    }
  if (enable)
    return ACE_BIT_ENABLED (thr_state, state);

  return ACE_BIT_DISABLED (thr_state, state);
}

// Test if a single thread has terminated.

int
ACE_Thread_Manager::testterminate (ACE_thread_t t_id)
{
  ACE_TRACE ("ACE_Thread_Manager::testterminate");
  return this->check_state (ACE_THR_TERMINATED, t_id);
}

// Test if a single thread is suspended.

int
ACE_Thread_Manager::testsuspend (ACE_thread_t t_id)
{
  ACE_TRACE ("ACE_Thread_Manager::testsuspend");
  return this->check_state (ACE_THR_SUSPENDED, t_id);
}

// Test if a single thread is active (i.e., resumed).

int
ACE_Thread_Manager::testresume (ACE_thread_t t_id)
{
  ACE_TRACE ("ACE_Thread_Manager::testresume");
  return this->check_state (ACE_THR_SUSPENDED, t_id, 0);
}

// Test if a single thread is cancelled.

int
ACE_Thread_Manager::testcancel (ACE_thread_t t_id)
{
  ACE_TRACE ("ACE_Thread_Manager::testcancel");
  return this->check_state (ACE_THR_CANCELLED, t_id);
}

// Thread information query functions.

int
ACE_Thread_Manager::hthread_within (ACE_hthread_t handle)
{
  ACE_TRACE ("ACE_Thread_Manager::hthread_within");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_monx, this->lock_, -1));

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (ACE_OS::thr_cmp(iter.next ()->thr_handle_, handle))
        {
          return 1;
        }
    }

  return 0;
}

int
ACE_Thread_Manager::thread_within (ACE_thread_t tid)
{
  ACE_TRACE ("ACE_Thread_Manager::thread_within");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_monx, this->lock_, -1));

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (ACE_OS::thr_equal (iter.next ()->thr_id_, tid))
        {
          return 1;
        }
    }

  return 0;
}

// Get group ids for a particular thread id.

int
ACE_Thread_Manager::get_grp (ACE_thread_t t_id, int &grp_id)
{
  ACE_TRACE ("ACE_Thread_Manager::get_grp");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  ACE_FIND (this->find_thread (t_id), ptr);

  if (ptr)
    grp_id = ptr->grp_id_;
  else
    return -1;
  return 0;
}

// Set group ids for a particular thread id.

int
ACE_Thread_Manager::set_grp (ACE_thread_t t_id, int grp_id)
{
  ACE_TRACE ("ACE_Thread_Manager::set_grp");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  ACE_FIND (this->find_thread (t_id), ptr);
  if (ptr)
    ptr->grp_id_ = grp_id;
  else
    return -1;
  return 0;
}

// Suspend a group of threads.

int
ACE_Thread_Manager::apply_grp (int grp_id,
                               ACE_THR_MEMBER_FUNC func,
                               int arg)
{
  ACE_TRACE ("ACE_Thread_Manager::apply_grp");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_monx, this->lock_, -1));
  ACE_ASSERT (this->thr_to_be_removed_.is_empty ());

  int result = 0;

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (iter.next ()->grp_id_ == grp_id)
        {
          if ((this->*func) (iter.next (), arg) == -1)
            {
              result = -1;
            }
        }
    }

  // Must remove threads after we have traversed the thr_list_ to
  // prevent clobber thr_list_'s integrity.

  if (! this->thr_to_be_removed_.is_empty ())
    {
      // Save/restore errno.
      ACE_Errno_Guard error (errno);

      for (ACE_Thread_Descriptor *td;
           this->thr_to_be_removed_.dequeue_head (td) != -1;
           )
        this->remove_thr (td, 1);
    }

  return result;
}

int
ACE_Thread_Manager::suspend_grp (int grp_id)
{
  ACE_TRACE ("ACE_Thread_Manager::suspend_grp");
  return this->apply_grp (grp_id,
                          ACE_THR_MEMBER_FUNC (&ACE_Thread_Manager::suspend_thr));
}

// Resume a group of threads.

int
ACE_Thread_Manager::resume_grp (int grp_id)
{
  ACE_TRACE ("ACE_Thread_Manager::resume_grp");
  return this->apply_grp (grp_id,
                          ACE_THR_MEMBER_FUNC (&ACE_Thread_Manager::resume_thr));
}

// Kill a group of threads.

int
ACE_Thread_Manager::kill_grp (int grp_id, int signum)
{
  ACE_TRACE ("ACE_Thread_Manager::kill_grp");
  return this->apply_grp (grp_id,
                          ACE_THR_MEMBER_FUNC (&ACE_Thread_Manager::kill_thr), signum);
}

// Cancel a group of threads.

int
ACE_Thread_Manager::cancel_grp (int grp_id, int async_cancel)
{
  ACE_TRACE ("ACE_Thread_Manager::cancel_grp");
  return this->apply_grp (grp_id,
                          ACE_THR_MEMBER_FUNC (&ACE_Thread_Manager::cancel_thr),
                          async_cancel);
}

int
ACE_Thread_Manager::apply_all (ACE_THR_MEMBER_FUNC func, int arg)
{
  ACE_TRACE ("ACE_Thread_Manager::apply_all");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));
  ACE_ASSERT (this->thr_to_be_removed_.is_empty ());

  int result = 0;

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if ((this->*func)(iter.next (), arg) == -1)
        {
          result = -1;
        }
    }

  // Must remove threads after we have traversed the thr_list_ to
  // prevent clobber thr_list_'s integrity.

  if (! this->thr_to_be_removed_.is_empty ())
    {
      // Save/restore errno.
      ACE_Errno_Guard error (errno);

      for (ACE_Thread_Descriptor *td;
           this->thr_to_be_removed_.dequeue_head (td) != -1;
           )
        this->remove_thr (td, 1);
    }

  return result;
}

// Resume all threads that are suspended.

int
ACE_Thread_Manager::resume_all (void)
{
  ACE_TRACE ("ACE_Thread_Manager::resume_all");
  return this->apply_all (ACE_THR_MEMBER_FUNC (&ACE_Thread_Manager::resume_thr));
}

int
ACE_Thread_Manager::suspend_all (void)
{
  ACE_TRACE ("ACE_Thread_Manager::suspend_all");
  return this->apply_all (ACE_THR_MEMBER_FUNC (&ACE_Thread_Manager::suspend_thr));
}

int
ACE_Thread_Manager::kill_all (int sig)
{
  ACE_TRACE ("ACE_Thread_Manager::kill_all");
  return this->apply_all (&ACE_Thread_Manager::kill_thr, sig);
}

int
ACE_Thread_Manager::cancel_all (int async_cancel)
{
  ACE_TRACE ("ACE_Thread_Manager::cancel_all");
  return this->apply_all (ACE_THR_MEMBER_FUNC (&ACE_Thread_Manager::cancel_thr),
                          async_cancel);
}

int
ACE_Thread_Manager::join (ACE_thread_t tid, ACE_THR_FUNC_RETURN *status)
{
  ACE_TRACE ("ACE_Thread_Manager::join");

  bool found = false;
  ACE_Thread_Descriptor tdb;

  {
    ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

#if !defined (ACE_HAS_VXTHREADS)
    for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor_Base> biter (this->terminated_thr_list_);
         !biter.done ();
         biter.advance ())
      {
        if (ACE_OS::thr_equal (biter.next ()->thr_id_, tid))
          {
            ACE_Thread_Descriptor_Base *tdb = biter.advance_and_remove (false);
            if (ACE_Thread::join (tdb->thr_handle_, status) == -1)
              {
                return -1;
              }
            delete tdb;

            // return immediately if we've found the thread we want to join.
            return 0;
          }
      }
#endif /* !ACE_HAS_VXTHREADS */

    for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
         !iter.done ();
         iter.advance ())
      {
        // If threads are created as THR_DETACHED or THR_DAEMON, we
        // can't help much.
        if (ACE_OS::thr_equal (iter.next ()->thr_id_,tid) &&
            (ACE_BIT_DISABLED (iter.next ()->flags_, THR_DETACHED | THR_DAEMON)
             || ACE_BIT_ENABLED (iter.next ()->flags_, THR_JOINABLE)))
          {
            tdb = *iter.next ();
            ACE_SET_BITS (iter.next ()->thr_state_, ACE_THR_JOINING);
            found = 1;
            break;
          }
      }

    if (!found)
      return -1;
    // Didn't find the thread we want or the thread is not joinable.
  }

  if (ACE_Thread::join (tdb.thr_handle_, status) == -1)
    return -1;

  return 0;
}

// Wait for group of threads

int
ACE_Thread_Manager::wait_grp (int grp_id)
{
  ACE_TRACE ("ACE_Thread_Manager::wait_grp");

  int copy_count = 0;
  ACE_Thread_Descriptor_Base *copy_table = 0;

  // We have to make sure that while we wait for these threads to
  // exit, we do not have the lock.  Therefore we make a copy of all
  // interesting entries and let go of the lock.
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

#if !defined (ACE_HAS_VXTHREADS)
    ACE_NEW_RETURN (copy_table,
                    ACE_Thread_Descriptor_Base [this->thr_list_.size ()
                                               + this->terminated_thr_list_.size ()],
                    -1);
#else
    ACE_NEW_RETURN (copy_table,
                    ACE_Thread_Descriptor_Base [this->thr_list_.size ()],
                    -1);
#endif /* !ACE_HAS_VXTHREADS */

    for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
         !iter.done ();
         iter.advance ())
      {
        // If threads are created as THR_DETACHED or THR_DAEMON, we
        // can't help much.
        if (iter.next ()->grp_id_ == grp_id &&
            (ACE_BIT_DISABLED (iter.next ()->flags_, THR_DETACHED | THR_DAEMON)
             || ACE_BIT_ENABLED (iter.next ()->flags_, THR_JOINABLE)))
          {
            ACE_SET_BITS (iter.next ()->thr_state_, ACE_THR_JOINING);
            copy_table[copy_count++] = *iter.next ();
          }
      }

#if !defined (ACE_HAS_VXTHREADS)
    for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor_Base> biter (this->terminated_thr_list_);
         !biter.done ();
         biter.advance ())
      {
        // If threads are created as THR_DETACHED or THR_DAEMON, we
        // can't help much.
        if (biter.next ()->grp_id_ == grp_id)
          {
            ACE_Thread_Descriptor_Base *tdb = biter.advance_and_remove (false);
            copy_table[copy_count++] = *tdb;
            delete tdb;
          }
      }
#endif /* !ACE_HAS_VXTHREADS */
  }

  // Now actually join() with all the threads in this group.
  int result = 0;

  for (int i = 0;
       i < copy_count && result != -1;
       i++)
    {
      if (ACE_Thread::join (copy_table[i].thr_handle_) == -1)
        result = -1;
    }

  delete [] copy_table;

  return result;
}

// Must be called when thread goes out of scope to clean up its table
// slot.

ACE_THR_FUNC_RETURN
ACE_Thread_Manager::exit (ACE_THR_FUNC_RETURN status, bool do_thread_exit)
{
  ACE_TRACE ("ACE_Thread_Manager::exit");
#if defined (ACE_WIN32)
  // Remove detached thread handle.

  if (do_thread_exit)
    {
#if 0
      // @@ This callback is now taken care of by TSS_Cleanup.  Do we
      //    need it anymore?

      // On Win32, if we really wants to exit from a thread, we must
      // first  clean up the thread specific storage.  By doing so,
      // ACE_Thread_Manager::exit will be called again with
      // do_thr_exit = 0 and cleaning up the ACE_Cleanup_Info (but not
      // exiting the thread.)  After the following call returns, we
      // are safe to exit this thread.
      delete ACE_Thread_Exit::instance ();
#endif /* 0 */
      ACE_Thread::exit (status);
    }
#endif /* ACE_WIN32 */

  // Just hold onto the guard while finding this thread's id and
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, 0));

    // Find the thread id, but don't use the cache.  It might have been
    // deleted already.
    ACE_thread_t const id = ACE_OS::thr_self ();
    ACE_Thread_Descriptor* td = this->find_thread (id);
    if (td != 0)
     {
       // @@ We call Thread_Descriptor terminate this realize the cleanup
       // process itself.
       td->terminate();
     }
  }

  if (do_thread_exit)
    {
      ACE_Thread::exit (status);
      // On reasonable systems <ACE_Thread::exit> should not return.
      // However, due to horrible semantics with Win32 thread-specific
      // storage this call can return (don't ask...).
    }

  return 0;
}

// Wait for all the threads to exit.

int
ACE_Thread_Manager::wait (const ACE_Time_Value *timeout,
                          bool abandon_detached_threads,
                          bool use_absolute_time)
{
  ACE_TRACE ("ACE_Thread_Manager::wait");

  ACE_Time_Value local_timeout;
  // Check to see if we're using absolute time or not.
  if (use_absolute_time == false && timeout != 0)
    {
      local_timeout = *timeout;
      local_timeout += ACE_OS::gettimeofday ();
      timeout = &local_timeout;
    }

#if !defined (ACE_HAS_VXTHREADS)
  ACE_Double_Linked_List<ACE_Thread_Descriptor_Base> term_thr_list_copy;
#endif /* ACE_HAS_VXTHREADS */

#if defined (ACE_HAS_THREADS)
  {
    // Just hold onto the guard while waiting.
    ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

    if (ACE_Object_Manager::shutting_down () != 1)
      {
        // Program is not shutting down.  Perform a normal wait on threads.
        if (abandon_detached_threads != 0)
          {
            ACE_ASSERT (this->thr_to_be_removed_.is_empty ());
            for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor>
                   iter (this->thr_list_);
                 !iter.done ();
                 iter.advance ())
              {
                if (ACE_BIT_ENABLED (iter.next ()->flags_,
                                     THR_DETACHED | THR_DAEMON)
                    && ACE_BIT_DISABLED (iter.next ()->flags_, THR_JOINABLE))
                  {
                    this->thr_to_be_removed_.enqueue_tail (iter.next ());
                    ACE_SET_BITS (iter.next ()->thr_state_, ACE_THR_JOINING);
                  }
              }

            if (! this->thr_to_be_removed_.is_empty ())
              {
                ACE_Thread_Descriptor *td = 0;
                while (this->thr_to_be_removed_.dequeue_head (td) != -1)
                  this->remove_thr (td, 1);
              }
          }

        while (this->thr_list_.size () > 0)
          if (this->zero_cond_.wait (timeout) == -1)
            return -1;
      }
    else
        // Program is shutting down, no chance to wait on threads.
        // Therefore, we'll just remove threads from the list.
        this->remove_thr_all ();

#if !defined (ACE_HAS_VXTHREADS)
  ACE_Thread_Descriptor_Base* item = 0;
  while ((item = this->terminated_thr_list_.delete_head ()) != 0)
    {
      term_thr_list_copy.insert_tail (item);
    }
#endif /* ACE_HAS_VXTHREADS */
    // Release the guard, giving other threads a chance to run.
  }

#if !defined (ACE_HAS_VXTHREADS)
    // @@ VxWorks doesn't support thr_join (yet.)  We are working
    // on our implementation.   Chorus'es thr_join seems broken.
    ACE_Thread_Descriptor_Base *item = 0;

    while ((item = term_thr_list_copy.delete_head ()) != 0)
      {
        if (ACE_BIT_DISABLED (item->flags_, THR_DETACHED | THR_DAEMON)
            || ACE_BIT_ENABLED (item->flags_, THR_JOINABLE))
          // Detached handles shouldn't reached here.
          (void) ACE_Thread::join (item->thr_handle_);

        delete item;
      }

#endif /* !ACE_HAS_VXTHREADS */
#else
  ACE_UNUSED_ARG (timeout);
  ACE_UNUSED_ARG (abandon_detached_threads);
#endif /* ACE_HAS_THREADS */

  return 0;
}

int
ACE_Thread_Manager::apply_task (ACE_Task_Base *task,
                                ACE_THR_MEMBER_FUNC func,
                                int arg)
{
  ACE_TRACE ("ACE_Thread_Manager::apply_task");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));
  ACE_ASSERT (this->thr_to_be_removed_.is_empty ());

  int result = 0;

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    if (iter.next ()->task_ == task
        && (this->*func) (iter.next (), arg) == -1)
      result = -1;

  // Must remove threads after we have traversed the thr_list_ to
  // prevent clobber thr_list_'s integrity.

  if (! this->thr_to_be_removed_.is_empty ())
    {
      // Save/restore errno.
      ACE_Errno_Guard error (errno);

      for (ACE_Thread_Descriptor *td;
           this->thr_to_be_removed_.dequeue_head (td) != -1;
           )
        this->remove_thr (td, 1);
    }

  return result;
}

// Wait for all threads to exit a task.

int
ACE_Thread_Manager::wait_task (ACE_Task_Base *task)
{
  int copy_count = 0;
  ACE_Thread_Descriptor_Base *copy_table = 0;

  // We have to make sure that while we wait for these threads to
  // exit, we do not have the lock.  Therefore we make a copy of all
  // interesting entries and let go of the lock.
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

#if !defined (ACE_HAS_VXTHREADS)
    ACE_NEW_RETURN (copy_table,
                    ACE_Thread_Descriptor_Base [this->thr_list_.size ()
                                                + this->terminated_thr_list_.size ()],
                    -1);
#else
    ACE_NEW_RETURN (copy_table,
                    ACE_Thread_Descriptor_Base [this->thr_list_.size ()],
                    -1);
#endif /* !ACE_HAS_VXTHREADS */

    for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
         !iter.done ();
         iter.advance ())
      {
        // If threads are created as THR_DETACHED or THR_DAEMON, we
        // can't wait on them here.
        if (iter.next ()->task_ == task &&
            (ACE_BIT_DISABLED (iter.next ()->flags_,
                               THR_DETACHED | THR_DAEMON)
             || ACE_BIT_ENABLED (iter.next ()->flags_,
                                 THR_JOINABLE)))
          {
            ACE_SET_BITS (iter.next ()->thr_state_,
                          ACE_THR_JOINING);
            copy_table[copy_count++] = *iter.next ();
          }
      }

#if !defined (ACE_HAS_VXTHREADS)
    for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor_Base> titer (this->terminated_thr_list_);
         !titer.done ();
         titer.advance ())
      {
        // If threads are created as THR_DETACHED or THR_DAEMON, we can't help much here.
        if (titer.next ()->task_ == task)
          {
            ACE_Thread_Descriptor_Base *tdb = titer.advance_and_remove (false);
            copy_table[copy_count++] = *tdb;
            delete tdb;
          }
      }
#endif /* !ACE_HAS_VXTHREADS */
  }

  // Now to do the actual work
  int result = 0;

  for (int i = 0;
       i < copy_count && result != -1;
       i++)
    {
      if (ACE_Thread::join (copy_table[i].thr_handle_) == -1)
        result = -1;
    }

  delete [] copy_table;

  return result;
}

// Suspend a task

int
ACE_Thread_Manager::suspend_task (ACE_Task_Base *task)
{
  ACE_TRACE ("ACE_Thread_Manager::suspend_task");
  return this->apply_task (task,
                           ACE_THR_MEMBER_FUNC (&ACE_Thread_Manager::suspend_thr));
}

// Resume a task.
int
ACE_Thread_Manager::resume_task (ACE_Task_Base *task)
{
  ACE_TRACE ("ACE_Thread_Manager::resume_task");
  return this->apply_task (task,
                           ACE_THR_MEMBER_FUNC (&ACE_Thread_Manager::resume_thr));
}

// Kill a task.

int
ACE_Thread_Manager::kill_task (ACE_Task_Base *task, int /* signum */)
{
  ACE_TRACE ("ACE_Thread_Manager::kill_task");
  return this->apply_task (task,
                           ACE_THR_MEMBER_FUNC (&ACE_Thread_Manager::kill_thr));
}

// Cancel a task.
int
ACE_Thread_Manager::cancel_task (ACE_Task_Base *task,
                                 int async_cancel)
{
  ACE_TRACE ("ACE_Thread_Manager::cancel_task");
  return this->apply_task (task,
                           ACE_THR_MEMBER_FUNC (&ACE_Thread_Manager::cancel_thr),
                           async_cancel);
}

// Locate the index in the table associated with <task> from the
// beginning of the table up to an index.  Must be called with the
// lock held.

ACE_Thread_Descriptor *
ACE_Thread_Manager::find_task (ACE_Task_Base *task, size_t slot)
{
  ACE_TRACE ("ACE_Thread_Manager::find_task");

  size_t i = 0;

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (i >= slot)
        break;

      if (task == iter.next ()->task_)
        return iter.next ();

      ++i;
    }

  return 0;
}

// Returns the number of ACE_Task in a group.

int
ACE_Thread_Manager::num_tasks_in_group (int grp_id)
{
  ACE_TRACE ("ACE_Thread_Manager::num_tasks_in_group");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  int tasks_count = 0;
  size_t i = 0;

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (iter.next ()->grp_id_ == grp_id
          && this->find_task (iter.next ()->task_, i) == 0
          && iter.next ()->task_ != 0)
        {
          ++tasks_count;
        }

      ++i;
    }
  return tasks_count;
}

// Returns the number of threads in an ACE_Task.

int
ACE_Thread_Manager::num_threads_in_task (ACE_Task_Base *task)
{
  ACE_TRACE ("ACE_Thread_Manager::num_threads_in_task");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  int threads_count = 0;

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (iter.next ()->task_ == task)
        {
          ++threads_count;
        }
    }

  return threads_count;
}

// Returns in task_list a list of ACE_Tasks registered with ACE_Thread_Manager.

ssize_t
ACE_Thread_Manager::task_all_list (ACE_Task_Base *task_list[],
                                   size_t n)
{
  ACE_TRACE ("ACE_Thread_Manager::task_all_list");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  size_t task_list_count = 0;

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (task_list_count >= n)
        {
          break;
        }

      ACE_Task_Base *task_p = iter.next ()->task_;

      if (0 != task_p)
        {
          // This thread has a task pointer; see if it's already in the
          // list. Don't add duplicates.
          size_t i = 0;

          for (; i < task_list_count; ++i)
            {
              if (task_list[i] == task_p)
                {
                  break;
                }
            }

          if (i == task_list_count)        // No match - add this one
            {
              task_list[task_list_count++] = task_p;
            }
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (task_list_count);
}

// Returns in thread_list a list of all thread ids

ssize_t
ACE_Thread_Manager::thread_all_list (ACE_thread_t thread_list[],
                                     size_t n)
{
  ACE_TRACE ("ACE_Thread_Manager::thread_all_list");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  size_t thread_count = 0;

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (thread_count >= n)
        {
          break;
        }

      thread_list[thread_count] = iter.next ()->thr_id_;
      ++thread_count;
    }

  return ACE_Utils::truncate_cast<ssize_t> (thread_count);
}


int
ACE_Thread_Manager::thr_state (ACE_thread_t id,
                               ACE_UINT32& state)
{
  ACE_TRACE ("ACE_Thread_Manager::thr_state");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  int const self_check = ACE_OS::thr_equal (id, ACE_OS::thr_self ());

  // If we're checking the state of our thread, try to get the cached
  // value out of TSS to avoid lookup.
  if (self_check)
    {
      ACE_Thread_Descriptor *desc = ACE_LOG_MSG->thr_desc ();

      if (desc == 0)
        {
          return 0;               // Always return false.
        }

      state = desc->thr_state_;
    }
  else
    {
      // Not calling from self, have to look it up from the list.
      ACE_FIND (this->find_thread (id), ptr);

      if (ptr == 0)
        {
          return 0;
        }

      state = ptr->thr_state_;
    }

  return 1;
}

// Returns in task_list a list of ACE_Tasks in a group.

ssize_t
ACE_Thread_Manager::task_list (int grp_id,
                               ACE_Task_Base *task_list[],
                               size_t n)
{
  ACE_TRACE ("ACE_Thread_Manager::task_list");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  ACE_Task_Base **task_list_iterator = task_list;
  size_t task_list_count = 0;
  size_t i = 0;

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (task_list_count >= n)
        {
          break;
        }

      if (iter.next ()->grp_id_ == grp_id
          && this->find_task (iter.next ()->task_, i) == 0)
        {
          task_list_iterator[task_list_count] = iter.next ()->task_;
          ++task_list_count;
        }

      ++i;
    }

  return ACE_Utils::truncate_cast<ssize_t> (task_list_count);
}

// Returns in thread_list a list of thread ids in an ACE_Task.

ssize_t
ACE_Thread_Manager::thread_list (ACE_Task_Base *task,
                                 ACE_thread_t thread_list[],
                                 size_t n)
{
  ACE_TRACE ("ACE_Thread_Manager::thread_list");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  size_t thread_count = 0;

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (thread_count >= n)
        {
          break;
        }

      if (iter.next ()->task_ == task)
        {
          thread_list[thread_count] = iter.next ()->thr_id_;
          ++thread_count;
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (thread_count);
}

// Returns in thread_list a list of thread handles in an ACE_Task.

ssize_t
ACE_Thread_Manager::hthread_list (ACE_Task_Base *task,
                                  ACE_hthread_t hthread_list[],
                                  size_t n)
{
  ACE_TRACE ("ACE_Thread_Manager::hthread_list");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  size_t hthread_count = 0;

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (hthread_count >= n)
        {
          break;
        }

      if (iter.next ()->task_ == task)
        {
          hthread_list[hthread_count] = iter.next ()->thr_handle_;
          ++hthread_count;
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (hthread_count);
}

ssize_t
ACE_Thread_Manager::thread_grp_list (int grp_id,
                                     ACE_thread_t thread_list[],
                                     size_t n)
{
  ACE_TRACE ("ACE_Thread_Manager::thread_grp_list");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  size_t thread_count = 0;

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (thread_count >= n)
        {
          break;
        }

      if (iter.next ()->grp_id_ == grp_id)
        {
          thread_list[thread_count] = iter.next ()->thr_id_;
          thread_count++;
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (thread_count);
}

// Returns in thread_list a list of thread handles in an ACE_Task.

ssize_t
ACE_Thread_Manager::hthread_grp_list (int grp_id,
                                      ACE_hthread_t hthread_list[],
                                      size_t n)
{
  ACE_TRACE ("ACE_Thread_Manager::hthread_grp_list");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  size_t hthread_count = 0;

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (hthread_count >= n)
        {
          break;
        }

      if (iter.next ()->grp_id_ == grp_id)
        {
          hthread_list[hthread_count] = iter.next ()->thr_handle_;
          hthread_count++;
        }
    }

  return ACE_Utils::truncate_cast<ssize_t> (hthread_count);
}

int
ACE_Thread_Manager::set_grp (ACE_Task_Base *task, int grp_id)
{
  ACE_TRACE ("ACE_Thread_Manager::set_grp");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  for (ACE_Double_Linked_List_Iterator<ACE_Thread_Descriptor> iter (this->thr_list_);
       !iter.done ();
       iter.advance ())
    {
      if (iter.next ()->task_ == task)
        {
          iter.next ()->grp_id_ = grp_id;
        }
    }

  return 0;
}

int
ACE_Thread_Manager::get_grp (ACE_Task_Base *task, int &grp_id)
{
  ACE_TRACE ("ACE_Thread_Manager::get_grp");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  ACE_FIND (this->find_task (task), ptr);
  grp_id = ptr->grp_id_;
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

