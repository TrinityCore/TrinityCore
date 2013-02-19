// $Id: Log_Msg.cpp 95761 2012-05-15 18:23:04Z johnnyw $

// We need this to get the status of ACE_NTRACE...
#include "ace/config-all.h"

// Turn off tracing for the duration of this file.
#if defined (ACE_NTRACE)
# undef ACE_NTRACE
#endif /* ACE_NTRACE */
#define ACE_NTRACE 1

#include "ace/ACE.h"
#include "ace/Thread_Manager.h"
#include "ace/Guard_T.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/OS_NS_wchar.h"
#include "ace/OS_NS_signal.h"
#include "ace/os_include/os_typeinfo.h"

#if !defined (ACE_MT_SAFE) || (ACE_MT_SAFE != 0)
# include "ace/Object_Manager_Base.h"
#endif /* ! ACE_MT_SAFE */

#if !defined (ACE_LACKS_IOSTREAM_TOTALLY)
// FUZZ: disable check_for_streams_include
# include "ace/streams.h"
#endif /* ! ACE_LACKS_IOSTREAM_TOTALLY */

#if defined (ACE_HAS_TRACE)
# include "ace/Trace.h"
#endif /* ACE_HAS_TRACE */

#include "ace/Log_Msg.h"
#include "ace/Log_Msg_Callback.h"
#include "ace/Log_Msg_IPC.h"
#include "ace/Log_Msg_NT_Event_Log.h"
#include "ace/Log_Msg_UNIX_Syslog.h"
#include "ace/Log_Record.h"
#include "ace/Recursive_Thread_Mutex.h"
#include "ace/Stack_Trace.h"
#include "ace/Atomic_Op.h"

#if !defined (__ACE_INLINE__)
#include "ace/Log_Msg.inl"
#endif /* __ACE_INLINE__ */



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Log_Msg)

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  bool ACE_Log_Msg::key_created_ = 0;
# if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || \
    defined (ACE_HAS_TSS_EMULATION)

static ACE_thread_key_t the_log_msg_tss_key = 0;

ACE_thread_key_t *log_msg_tss_key (void)
{
  return &the_log_msg_tss_key;
}

# endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE || ACE_HAS_TSS_EMULATION */
#else
static ACE_Cleanup_Adapter<ACE_Log_Msg>* log_msg_cleanup = 0;
class ACE_Msg_Log_Cleanup: public ACE_Cleanup_Adapter<ACE_Log_Msg>
{
public:
  virtual ~ACE_Msg_Log_Cleanup (void) {
    if (this == log_msg_cleanup)
      log_msg_cleanup = 0;
  }
};
#endif /* ACE_MT_SAFE */

#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE) && !defined (ACE_HAS_PHARLAP)
#  define ACE_LOG_MSG_SYSLOG_BACKEND ACE_Log_Msg_NT_Event_Log
#elif !defined (ACE_LACKS_UNIX_SYSLOG) && !defined (ACE_HAS_WINCE)
#  define ACE_LOG_MSG_SYSLOG_BACKEND ACE_Log_Msg_UNIX_Syslog
#else
#  define ACE_LOG_MSG_SYSLOG_BACKEND ACE_Log_Msg_IPC
#endif /* ! ACE_WIN32 */

// When doing ACE_OS::s[n]printf() calls in log(), we need to update
// the space remaining in the output buffer based on what's returned from
// the output function. If we could rely on more modern compilers, this
// would be in an unnamed namespace, but it's a macro instead.
// count is a size_t, len is an int and assumed to be non-negative.
#define ACE_UPDATE_COUNT(COUNT, LEN) \
   do { if (static_cast<size_t> (LEN) > COUNT) COUNT = 0; \
     else COUNT -= static_cast<size_t> (LEN); \
   } while (0)

/// Instance count for Log_Msg - used to know when dynamically
/// allocated storage (program name and host name) can be safely
/// deleted.
int ACE_Log_Msg::instance_count_ = 0;

/**
 * @class ACE_Log_Msg_Manager
 *
 * @brief Synchronize output operations.
 *
 * Provides global point of contact for all ACE_Log_Msg instances
 * in a process.
 *
 * For internal use by ACE, only!
 */
class ACE_Log_Msg_Manager
{
public:
  static ACE_Log_Msg_Backend *log_backend_;
  static ACE_Log_Msg_Backend *custom_backend_;

  static u_long log_backend_flags_;

  static int init_backend (const u_long *flags = 0);

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  //FUZZ: disable check_for_lack_ACE_OS
  static void close (void) ACE_GCC_DESTRUCTOR_ATTRIBUTE;
  //FUZZ: enable check_for_lack_ACE_OS

  static ACE_Recursive_Thread_Mutex *get_lock (void);

private:
  static ACE_Recursive_Thread_Mutex *lock_;
#endif /* ! ACE_MT_SAFE */
};

ACE_Log_Msg_Backend *ACE_Log_Msg_Manager::log_backend_ = 0;
ACE_Log_Msg_Backend *ACE_Log_Msg_Manager::custom_backend_ = 0;

u_long ACE_Log_Msg_Manager::log_backend_flags_ = 0;

int ACE_Log_Msg_Manager::init_backend (const u_long *flags)
{
  // If flags have been supplied, and they are different from the flags
  // we had last time, then we may have to re-create the backend as a
  // different type.
  if (flags)
    {
      // Sanity check for custom backend.
      if (ACE_BIT_ENABLED (*flags, ACE_Log_Msg::CUSTOM) &&
          ACE_Log_Msg_Manager::custom_backend_ == 0)
        {
          return -1;
        }

      if ((ACE_BIT_ENABLED (*flags, ACE_Log_Msg::SYSLOG)
            && ACE_BIT_DISABLED (ACE_Log_Msg_Manager::log_backend_flags_, ACE_Log_Msg::SYSLOG))
          || (ACE_BIT_DISABLED (*flags, ACE_Log_Msg::SYSLOG)
            && ACE_BIT_ENABLED (ACE_Log_Msg_Manager::log_backend_flags_, ACE_Log_Msg::SYSLOG)))
        {
          delete ACE_Log_Msg_Manager::log_backend_;
          ACE_Log_Msg_Manager::log_backend_ = 0;
        }

      ACE_Log_Msg_Manager::log_backend_flags_ = *flags;
    }

  if (ACE_Log_Msg_Manager::log_backend_ == 0)
    {
      ACE_NO_HEAP_CHECK;

#if (defined (WIN32) || !defined (ACE_LACKS_UNIX_SYSLOG)) && !defined (ACE_HAS_WINCE) && !defined (ACE_HAS_PHARLAP)
      // Allocate the ACE_Log_Msg_Backend instance.
      if (ACE_BIT_ENABLED (ACE_Log_Msg_Manager::log_backend_flags_, ACE_Log_Msg::SYSLOG))
        ACE_NEW_RETURN (ACE_Log_Msg_Manager::log_backend_,
                        ACE_LOG_MSG_SYSLOG_BACKEND,
                        -1);
      else
#endif /* defined (WIN32) && !defined (ACE_HAS_WINCE) && !defined (ACE_HAS_PHARLAP) */
        ACE_NEW_RETURN (ACE_Log_Msg_Manager::log_backend_,
                        ACE_Log_Msg_IPC,
                        -1);
    }

  return 0;
}

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
ACE_Recursive_Thread_Mutex *ACE_Log_Msg_Manager::lock_ = 0;

ACE_Recursive_Thread_Mutex *
ACE_Log_Msg_Manager::get_lock (void)
{
  // This function is called by the first thread to create an ACE_Log_Msg
  // instance.  It makes the call while holding a mutex, so we don't have
  // to grab another one here.

  if (ACE_Log_Msg_Manager::lock_ == 0)
    {
      ACE_NO_HEAP_CHECK;

      ACE_NEW_RETURN (ACE_Log_Msg_Manager::lock_,
                      ACE_Recursive_Thread_Mutex,
                      0);
    }

  if (init_backend () == -1)
    return 0;

  return ACE_Log_Msg_Manager::lock_;
}

void
ACE_Log_Msg_Manager::close (void)
{
#if defined (ACE_HAS_STHREADS) && ! defined (ACE_HAS_TSS_EMULATION) && ! defined (ACE_HAS_EXCEPTIONS)
  // Delete the (main thread's) Log_Msg instance.  I think that this
  // is only "necessary" if exception handling is not enabled.
  // Without exception handling, main thread TSS destructors don't
  // seem to be called.  It's not really necessary anyways, because
  // this one leak is harmless on Solaris.
  delete ACE_Log_Msg::instance ();
#endif /* ACE_HAS_STHREADS && ! TSS_EMULATION && ! ACE_HAS_EXCEPTIONS */

  // Ugly, ugly, but don't know a better way.
  delete ACE_Log_Msg_Manager::lock_;
  ACE_Log_Msg_Manager::lock_ = 0;

  delete ACE_Log_Msg_Manager::log_backend_;
  ACE_Log_Msg_Manager::log_backend_ = 0;

  // we are never responsible for custom backend
  ACE_Log_Msg_Manager::custom_backend_ = 0;
}

# if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || \
     defined (ACE_HAS_TSS_EMULATION)
/* static */
#  if defined (ACE_HAS_THR_C_DEST)
#   define LOCAL_EXTERN_PREFIX extern "C"
#  else
#   define LOCAL_EXTERN_PREFIX
#  endif /* ACE_HAS_THR_C_DEST */
LOCAL_EXTERN_PREFIX
void
ACE_TSS_CLEANUP_NAME (void *ptr)
{
  // Delegate to thr_desc if this not has terminated
  ACE_Log_Msg* log_msg = (ACE_Log_Msg*) ptr;
  if (log_msg->thr_desc()!=0)
    log_msg->thr_desc()->log_msg_cleanup(log_msg);
  else
    delete log_msg;
}
# endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE || ACE_HAS_TSS_EMULATION */
#endif /* ! ACE_MT_SAFE */

/* static */
int
ACE_Log_Msg::exists (void)
{
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
# if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || \
     defined (ACE_HAS_TSS_EMULATION)
  void *tss_log_msg = 0; // The actual type is ACE_Log_Msg*, but we need this
                         // void to keep G++ from complaining.

  // Get the tss_log_msg from thread-specific storage.
  return ACE_Log_Msg::key_created_
    && ACE_Thread::getspecific (*(log_msg_tss_key ()), &tss_log_msg) != -1
    && tss_log_msg != 0;
# else
#   error "Platform must support thread-specific storage if threads are used."
# endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE || ACE_HAS_TSS_EMULATION */
#else  /* ! ACE_MT_SAFE */
  return 1;
#endif /* ! ACE_MT_SAFE */
}

ACE_Log_Msg *
ACE_Log_Msg::instance (void)
{
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
# if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || \
     defined (ACE_HAS_TSS_EMULATION)
  // TSS Singleton implementation.

  if (!ACE_Log_Msg::key_created_)
    {
      ACE_thread_mutex_t *lock =
        reinterpret_cast<ACE_thread_mutex_t *> (
          ACE_OS_Object_Manager::preallocated_object
            [ACE_OS_Object_Manager::ACE_LOG_MSG_INSTANCE_LOCK]);

      if (1 == ACE_OS_Object_Manager::starting_up())
        //This function is called before ACE_OS_Object_Manager is
        //initialized.  So the lock might not be valid.  Assume it's
        //single threaded and so don't need the lock.
        ;
      else
        ACE_OS::thread_mutex_lock (lock);

      if (!ACE_Log_Msg::key_created_)
        {
          // Allocate the Singleton lock.
          ACE_Log_Msg_Manager::get_lock ();

          {
            ACE_NO_HEAP_CHECK;
            if (ACE_Thread::keycreate (log_msg_tss_key (),
                                       &ACE_TSS_CLEANUP_NAME) != 0)
              {
                if (1 == ACE_OS_Object_Manager::starting_up())
                  //This function is called before ACE_OS_Object_Manager is
                  //initialized.  So the lock might not be valid.  Assume it's
                  //single threaded and so don't need the lock.
                  ;
                else
                  ACE_OS::thread_mutex_unlock (lock);
                return 0; // Major problems, this should *never* happen!
              }
          }

          ACE_Log_Msg::key_created_ = true;
        }

      if (1 == ACE_OS_Object_Manager::starting_up())
        //This function is called before ACE_OS_Object_Manager is
        //initialized.  So the lock might not be valid.  Assume it's
        //single threaded and so don't need the lock.
        ;
      else
        ACE_OS::thread_mutex_unlock (lock);
    }

  ACE_Log_Msg *tss_log_msg = 0;
  void *temp = 0;

  // Get the tss_log_msg from thread-specific storage.
  if (ACE_Thread::getspecific (*(log_msg_tss_key ()), &temp) == -1)
    return 0; // This should not happen!

  tss_log_msg = static_cast <ACE_Log_Msg *> (temp);

  // Check to see if this is the first time in for this thread.
  if (tss_log_msg == 0)
    {
      // Allocate memory off the heap and store it in a pointer in
      // thread-specific storage (on the stack...).  Stop heap
      // checking, the memory will always be freed by the thread
      // rundown because of the TSS callback set up when the key was
      // created. This prevents from getting these blocks reported as
      // memory leaks.
      {
        ACE_NO_HEAP_CHECK;

        ACE_NEW_RETURN (tss_log_msg,
                        ACE_Log_Msg,
                        0);
        // Store the dynamically allocated pointer in thread-specific
        // storage.  It gets deleted via the ACE_TSS_cleanup function
        // when the thread terminates.

        if (ACE_Thread::setspecific (*(log_msg_tss_key()),
                                     reinterpret_cast<void *> (tss_log_msg))
            != 0)
          return 0; // Major problems, this should *never* happen!
      }
    }

  return tss_log_msg;
# else
#  error "Platform must support thread-specific storage if threads are used."
# endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE || ACE_HAS_TSS_EMULATION */
#else  /* ! ACE_MT_SAFE */
  // We don't have threads, we cannot call
  // ACE_Log_Msg_Manager::get_lock () to initialize the logger
  // callback, so instead we do it here.
  if (ACE_Log_Msg_Manager::init_backend () == -1)
    return 0;

  // Singleton implementation.

  if (log_msg_cleanup == 0)
    {
      ACE_NEW_RETURN (log_msg_cleanup, ACE_Msg_Log_Cleanup, 0);
      // Register the instance for destruction at program termination.
      ACE_Object_Manager::at_exit (log_msg_cleanup,
                                   0,
                                   typeid (*log_msg_cleanup).name ());
    }

  return &log_msg_cleanup->object ();
#endif /* ! ACE_MT_SAFE */
}

// Not inlined to help prevent having to include OS.h just to
// get ACE_DEBUG, et al, macros.
int
ACE_Log_Msg::last_error_adapter (void)
{
  return ACE_OS::last_error ();
}

// Sets the flag in the default priority mask used to initialize
// ACE_Log_Msg instances, as well as the current per-thread instance.

void
ACE_Log_Msg::enable_debug_messages (ACE_Log_Priority priority)
{
  ACE_SET_BITS (ACE_Log_Msg::default_priority_mask_, priority);
  ACE_Log_Msg *i = ACE_Log_Msg::instance ();
  i->priority_mask (i->priority_mask () | priority);
}

// Clears the flag in the default priority mask used to initialize
// ACE_Log_Msg instances, as well as the current per-thread instance.

void
ACE_Log_Msg::disable_debug_messages (ACE_Log_Priority priority)
{
  ACE_CLR_BITS (ACE_Log_Msg::default_priority_mask_, priority);
  ACE_Log_Msg *i = ACE_Log_Msg::instance ();
  i->priority_mask (i->priority_mask () & ~priority);
}

const ACE_TCHAR *
ACE_Log_Msg::program_name (void)
{
  return ACE_Log_Msg::program_name_;
}

/// Name of the local host.
const ACE_TCHAR *ACE_Log_Msg::local_host_ = 0;

/// Records the program name.
const ACE_TCHAR *ACE_Log_Msg::program_name_ = 0;

/// Default is to use stderr.
u_long ACE_Log_Msg::flags_ = ACE_Log_Msg::STDERR;

/// Process id of the current process.
pid_t ACE_Log_Msg::pid_ = -2;

/// Current offset of msg_[].
ptrdiff_t ACE_Log_Msg::msg_off_ = 0;

/// Default per-thread priority mask
/// By default, no priorities are enabled.
u_long ACE_Log_Msg::default_priority_mask_ = 0;

/// Default per-process priority mask
/// By default, all priorities are enabled.
u_long ACE_Log_Msg::process_priority_mask_ = LM_SHUTDOWN
                                             | LM_TRACE
                                             | LM_DEBUG
                                             | LM_INFO
                                             | LM_NOTICE
                                             | LM_WARNING
                                             | LM_STARTUP
                                             | LM_ERROR
                                             | LM_CRITICAL
                                             | LM_ALERT
                                             | LM_EMERGENCY;

void
ACE_Log_Msg::close (void)
{
  // This call needs to go here to avoid memory leaks.
  ACE_MT (ACE_Log_Msg_Manager::close ());

  // Please note that this will be called by a statement that is
  // harded coded into the ACE_Object_Manager's shutdown sequence, in
  // its destructor.

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0) && \
    (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || \
     defined (ACE_HAS_TSS_EMULATION))

  if (ACE_Log_Msg::key_created_)
    {
      ACE_thread_mutex_t *lock =
        reinterpret_cast<ACE_thread_mutex_t *>
  (ACE_OS_Object_Manager::preallocated_object
   [ACE_OS_Object_Manager::ACE_LOG_MSG_INSTANCE_LOCK]);
     ACE_OS::thread_mutex_lock (lock);

     if (ACE_Log_Msg::key_created_)
       {
         // Clean up this ACE_Log_Msg instance and reset the TSS to
         // prevent any future cleanup attempts via TSS mechanisms at
         // thread exit. Otherwise in the event of a dynamic library
         // unload of libACE, by a program not linked with libACE,
         // ACE_TSS_cleanup will be invoked after libACE has been unloaded.
         // See Bugzilla 2980 for lots of details.
         ACE_Log_Msg *tss_log_msg = 0;
         void *temp = 0;

         // Get the tss_log_msg from thread-specific storage.
         if (ACE_Thread::getspecific (*(log_msg_tss_key ()), &temp) != -1
             && temp)
           {
             tss_log_msg = static_cast <ACE_Log_Msg *> (temp);
             // we haven't been cleaned up
             ACE_TSS_CLEANUP_NAME(tss_log_msg);
             if (ACE_Thread::setspecific(*(log_msg_tss_key()),
                                         reinterpret_cast <void *>(0)) != 0)
               ACE_OS::printf ("ACE_Log_Msg::close failed to ACE_Thread::setspecific to 0\n");
           }

         // The key is not needed any longer; ACE_Log_Msg is closing
         // and will need to be reopened if this process wishes to use
         // logging again. So delete the key.
         ACE_Thread::keyfree (*(log_msg_tss_key()));
         ACE_Log_Msg::key_created_ = false;
       }

     ACE_OS::thread_mutex_unlock (lock);
    }
#endif /* (ACE_HAS_THREAD_SPECIFIC_STORAGE || ACE_HAS_TSS_EMULATION) && ACE_MT_SAFE */
}

void
ACE_Log_Msg::sync_hook (const ACE_TCHAR *prg_name)
{
  ACE_LOG_MSG->sync (prg_name);
}

ACE_OS_Thread_Descriptor *
ACE_Log_Msg::thr_desc_hook (void)
{
  return ACE_LOG_MSG->thr_desc ();
}

// Call after a fork to resynchronize the PID and PROGRAM_NAME
// variables.
void
ACE_Log_Msg::sync (const ACE_TCHAR *prog_name)
{
  ACE_TRACE ("ACE_Log_Msg::sync");

  if (prog_name)
    {
      // Must free if already allocated!!!
      ACE_OS::free ((void *) ACE_Log_Msg::program_name_);

      // Stop heap checking, block will be freed by the destructor when
      // the last ACE_Log_Msg instance is deleted.
      // Heap checking state will be restored when the block is left.
      {
        ACE_NO_HEAP_CHECK;

        ACE_Log_Msg::program_name_ = ACE_OS::strdup (prog_name);
      }
    }

  ACE_Log_Msg::pid_ = ACE_OS::getpid ();
  ACE_Log_Msg::msg_off_ = 0;
}

u_long
ACE_Log_Msg::flags (void)
{
  ACE_TRACE ("ACE_Log_Msg::flags");
  u_long result;
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                            *ACE_Log_Msg_Manager::get_lock (), 0));

  result = ACE_Log_Msg::flags_;
  return result;
}

void
ACE_Log_Msg::set_flags (u_long flgs)
{
  ACE_TRACE ("ACE_Log_Msg::set_flags");
  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex, ace_mon,
                     *ACE_Log_Msg_Manager::get_lock ()));

  ACE_SET_BITS (ACE_Log_Msg::flags_, flgs);
}

void
ACE_Log_Msg::clr_flags (u_long flgs)
{
  ACE_TRACE ("ACE_Log_Msg::clr_flags");
  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex, ace_mon,
                     *ACE_Log_Msg_Manager::get_lock ()));

  ACE_CLR_BITS (ACE_Log_Msg::flags_, flgs);
}

int
ACE_Log_Msg::acquire (void)
{
  ACE_TRACE ("ACE_Log_Msg::acquire");
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  return ACE_Log_Msg_Manager::get_lock ()->acquire ();
#else  /* ! ACE_MT_SAFE */
  return 0;
#endif /* ! ACE_MT_SAFE */
}

u_long
ACE_Log_Msg::priority_mask (u_long n_mask, MASK_TYPE mask_type)
{
  u_long o_mask;

  if (mask_type == THREAD)
    {
      o_mask = this->priority_mask_;
      this->priority_mask_ = n_mask;
    }
  else
    {
      o_mask = ACE_Log_Msg::process_priority_mask_;
      ACE_Log_Msg::process_priority_mask_ = n_mask;
    }

  return o_mask;
}

int
ACE_Log_Msg::release (void)
{
  ACE_TRACE ("ACE_Log_Msg::release");

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  return ACE_Log_Msg_Manager::get_lock ()->release ();
#else  /* ! ACE_MT_SAFE */
  return 0;
#endif /* ! ACE_MT_SAFE */
}

ACE_Log_Msg::ACE_Log_Msg (void)
  : status_ (0),
    errnum_ (0),
    linenum_ (0),
    msg_ (0),
    restart_ (1),  // Restart by default...
    ostream_ (0),
    ostream_refcount_ (0),
    msg_callback_ (0),
    trace_depth_ (0),
    trace_active_ (false),
    tracing_enabled_ (true), // On by default?
    thr_desc_ (0),
    priority_mask_ (default_priority_mask_),
    timestamp_ (0)
{
  // ACE_TRACE ("ACE_Log_Msg::ACE_Log_Msg");

  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex, ace_mon,
                     *ACE_Log_Msg_Manager::get_lock ()));
  ++instance_count_;

  if (this->instance_count_ == 1)
    ACE_Base_Thread_Adapter::set_log_msg_hooks (ACE_Log_Msg::init_hook,
                                                ACE_Log_Msg::inherit_hook,
                                                ACE_Log_Msg::close,
                                                ACE_Log_Msg::sync_hook,
                                                ACE_Log_Msg::thr_desc_hook);

  this->conditional_values_.is_set_ = false;

  char *timestamp = ACE_OS::getenv ("ACE_LOG_TIMESTAMP");
  if (timestamp != 0)
    {
      // If variable is set or is set to date tag so we print date and time.
      if (ACE_OS::strcmp (timestamp, "TIME") == 0)
        {
          this->timestamp_ = 1;
        }
      else if (ACE_OS::strcmp (timestamp, "DATE") == 0)
        {
          this->timestamp_ = 2;
        }
    }

  ACE_NEW_NORETURN (this->msg_, ACE_TCHAR[ACE_MAXLOGMSGLEN+1]);
}

ACE_Log_Msg::~ACE_Log_Msg (void)
{
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)

  int instance_count = 0;

  // Only hold the guard while updating the instance_count_.
  // If ACE_Log_Msg_Manager::close () is called, the lock will
  // be deleted.
  {
    ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex, ace_mon,
                       *ACE_Log_Msg_Manager::get_lock ()));
    instance_count = --instance_count_;
  }
  // Release the guard.

#else  /* ! ACE_MT_SAFE */
  int instance_count = --instance_count_;
#endif /* ! ACE_MT_SAFE */

  // If this is the last instance then cleanup.  Only the last
  // thread to destroy its ACE_Log_Msg instance should execute
  // this block.
  if (instance_count == 0)
    {
      // Destroy the message queue instance.
      if (ACE_Log_Msg_Manager::log_backend_ != 0)
        ACE_Log_Msg_Manager::log_backend_->close ();

      // Close down custom backend
      if (ACE_Log_Msg_Manager::custom_backend_ != 0)
        ACE_Log_Msg_Manager::custom_backend_->close ();

#     if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
#       if defined (ACE_HAS_TSS_EMULATION)
          ACE_Log_Msg_Manager::close ();
#       endif /* ACE_HAS_TSS_EMULATION */
#     endif /* ACE_MT_SAFE */

      if (ACE_Log_Msg::program_name_)
        {
          ACE_OS::free ((void *) ACE_Log_Msg::program_name_);
          ACE_Log_Msg::program_name_ = 0;
        }

      if (ACE_Log_Msg::local_host_)
        {
          ACE_OS::free ((void *) ACE_Log_Msg::local_host_);
          ACE_Log_Msg::local_host_ = 0;
        }
    }

  this->cleanup_ostream ();

  delete[] this->msg_;
}

void
ACE_Log_Msg::cleanup_ostream ()
{
  if (this->ostream_refcount_)
    {
      if (--*this->ostream_refcount_ == 0)
        {
          delete this->ostream_refcount_;
#if defined (ACE_LACKS_IOSTREAM_TOTALLY)
          ACE_OS::fclose (this->ostream_);
#else
          delete this->ostream_;
          this->ostream_ = 0;
#endif
        }
      this->ostream_refcount_ = 0;
    }
}

// Open the sender-side of the message queue.

int
ACE_Log_Msg::open (const ACE_TCHAR *prog_name,
                   u_long flags,
                   const ACE_TCHAR *logger_key)
{
  ACE_TRACE ("ACE_Log_Msg::open");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                            *ACE_Log_Msg_Manager::get_lock (), -1));

  if (prog_name)
    {
      ACE_OS::free ((void *) ACE_Log_Msg::program_name_);

      // Stop heap checking, block will be freed by the destructor.
      {
        ACE_NO_HEAP_CHECK;

        ACE_ALLOCATOR_RETURN (ACE_Log_Msg::program_name_,
                              ACE_OS::strdup (prog_name),
                              -1);
      }
    }
  else if (ACE_Log_Msg::program_name_ == 0)
    {
      // Stop heap checking, block will be freed by the destructor.
      ACE_NO_HEAP_CHECK;
      ACE_ALLOCATOR_RETURN (ACE_Log_Msg::program_name_,
                            ACE_OS::strdup (ACE_TEXT ("<unknown>")),
                            -1);
    }

  int status = 0;

  // Be sure that there is a message_queue_, with multiple threads.
  ACE_MT (ACE_Log_Msg_Manager::init_backend (&flags));

  // Always close the current handle before doing anything else.
  if (ACE_Log_Msg_Manager::log_backend_ != 0)
    ACE_Log_Msg_Manager::log_backend_->reset ();

  if (ACE_Log_Msg_Manager::custom_backend_ != 0)
    ACE_Log_Msg_Manager::custom_backend_->reset ();

  // Note that if we fail to open the message queue the default action
  // is to use stderr (set via static initialization in the
  // Log_Msg.cpp file).

  if (ACE_BIT_ENABLED (flags, ACE_Log_Msg::LOGGER)
      || ACE_BIT_ENABLED (flags, ACE_Log_Msg::SYSLOG))
    {
      // The SYSLOG backends (both NT and UNIX) can get along fine
      // without the logger_key - they will default to prog_name if
      // logger key is 0.
      if (logger_key == 0 && ACE_BIT_ENABLED (flags, ACE_Log_Msg::LOGGER))
        status = -1;
      else
        status = ACE_Log_Msg_Manager::log_backend_->open (logger_key);

      if (status == -1)
        ACE_SET_BITS (ACE_Log_Msg::flags_, ACE_Log_Msg::STDERR);
      else
        {
          if (ACE_BIT_ENABLED (flags, ACE_Log_Msg::LOGGER))
            ACE_SET_BITS (ACE_Log_Msg::flags_, ACE_Log_Msg::LOGGER);
          if (ACE_BIT_ENABLED (flags, ACE_Log_Msg::SYSLOG))
            ACE_SET_BITS (ACE_Log_Msg::flags_, ACE_Log_Msg::SYSLOG);
        }
    }
  else if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::LOGGER)
           || ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::SYSLOG))
    {
      // If we are closing down logger, redirect logging to stderr.
      ACE_CLR_BITS (ACE_Log_Msg::flags_, ACE_Log_Msg::LOGGER);
      ACE_CLR_BITS (ACE_Log_Msg::flags_, ACE_Log_Msg::SYSLOG);
      ACE_SET_BITS (ACE_Log_Msg::flags_, ACE_Log_Msg::STDERR);
    }

  if (ACE_BIT_ENABLED (flags, ACE_Log_Msg::CUSTOM))
    {
      status =
        ACE_Log_Msg_Manager::custom_backend_->open (logger_key);

      if (status != -1)
        ACE_SET_BITS (ACE_Log_Msg::flags_, ACE_Log_Msg::CUSTOM);
    }

  // Remember, ACE_Log_Msg::STDERR bit is on by default...
  if (status != -1
      && ACE_BIT_ENABLED (flags,
                          ACE_Log_Msg::STDERR) == 0)
    ACE_CLR_BITS (ACE_Log_Msg::flags_,
                  ACE_Log_Msg::STDERR);

  // VERBOSE takes precedence over VERBOSE_LITE...
  if (ACE_BIT_ENABLED (flags,
                       ACE_Log_Msg::VERBOSE_LITE))
    ACE_SET_BITS (ACE_Log_Msg::flags_,
                  ACE_Log_Msg::VERBOSE_LITE);
  else if (ACE_BIT_ENABLED (flags,
                            ACE_Log_Msg::VERBOSE))
    ACE_SET_BITS (ACE_Log_Msg::flags_,
                  ACE_Log_Msg::VERBOSE);

  if (ACE_BIT_ENABLED (flags,
                       ACE_Log_Msg::OSTREAM))
    {
      ACE_SET_BITS (ACE_Log_Msg::flags_,
                    ACE_Log_Msg::OSTREAM);
      // Only set this to cerr if it hasn't already been set.
      if (this->msg_ostream () == 0)
        this->msg_ostream (ACE_DEFAULT_LOG_STREAM);
    }

  if (ACE_BIT_ENABLED (flags,
                       ACE_Log_Msg::MSG_CALLBACK))
    ACE_SET_BITS (ACE_Log_Msg::flags_,
                  ACE_Log_Msg::MSG_CALLBACK);

  if (ACE_BIT_ENABLED (flags,
                       ACE_Log_Msg::SILENT))
    ACE_SET_BITS (ACE_Log_Msg::flags_,
                  ACE_Log_Msg::SILENT);

  return status;
}

/**
 * Valid Options (prefixed by '%', as in printf format strings) include:
 *   'A': print an ACE_timer_t value
 *   'a': exit the program at this point (var-argument is the exit status!)
 *   'b': print a ssize_t value
 *   'B': print a size_t value
 *   'c': print a character
 *   'C': print a character string
 *   'i', 'd': print a decimal number
 *   'I', indent according to nesting depth
 *   'e', 'E', 'f', 'F', 'g', 'G': print a double
 *   'l', print line number where an error occurred.
 *   'M': print the name of the priority of the message.
 *   'm': Return the message corresponding to errno value, e.g., as done by <strerror>
 *   'N': print file name where the error occurred.
 *   'n': print the name of the program (or "<unknown>" if not set)
 *   'o': print as an octal number
 *   'P': format the current process id
 *   'p': format the appropriate errno message from sys_errlist, e.g., as done by <perror>
 *   'Q': print out the uint64 number
 *   'q': print out the int64 number
 *   '@': print a void* pointer (in hexadecimal)
 *   'r': call the function pointed to by the corresponding argument
 *   'R': print return status
 *   'S': print out the appropriate signal message corresponding
 *        to var-argument, e.g., as done by strsignal()
 *   's': format a character string
 *   'T': print timestamp in hour:minute:sec:usec format.
 *   'D': print timestamp in month/day/year hour:minute:sec:usec format.
 *   't': print thread id (1 if single-threaded)
 *   'u': print as unsigned int
 *   'x': print as a hex number
 *   'X': print as a hex number
 *   'w': print a wide character
 *   'W': print out a wide character string.
 *   'z': print an ACE_OS::WChar character
 *   'Z': print an ACE_OS::WChar character string
 *   ':': print a time_t value as an integral number
 *   '%': format a single percent sign, '%'
 */
ssize_t
ACE_Log_Msg::log (ACE_Log_Priority log_priority,
                  const ACE_TCHAR *format_str, ...)
{
  ACE_TRACE ("ACE_Log_Msg::log");

  // Start of variable args section.
  va_list argp;

  va_start (argp, format_str);

  ssize_t const result = this->log (format_str,
                                    log_priority,
                                    argp);
  va_end (argp);

  return result;
}

#if defined (ACE_HAS_WCHAR)
/**
 * Since this is the ANTI_TCHAR version, we need to convert
 * the format string over.
 */
ssize_t
ACE_Log_Msg::log (ACE_Log_Priority log_priority,
                  const ACE_ANTI_TCHAR *format_str, ...)
{
  ACE_TRACE ("ACE_Log_Msg::log");

  // Start of variable args section.
  va_list argp;

  va_start (argp, format_str);

  ssize_t const result = this->log (ACE_TEXT_ANTI_TO_TCHAR (format_str),
                                    log_priority,
                                    argp);
  va_end (argp);

  return result;
}
#endif /* ACE_HAS_WCHAR */

ssize_t
ACE_Log_Msg::log (const ACE_TCHAR *format_str,
                  ACE_Log_Priority log_priority,
                  va_list argp)
{
  ACE_TRACE ("ACE_Log_Msg::log");
  // External decls.

  typedef void (*PTF)(...);

  // Check if there were any conditional values set.
  bool const conditional_values = this->conditional_values_.is_set_;

  // Reset conditional values.
  this->conditional_values_.is_set_ = false;

  // Only print the message if <priority_mask_> hasn't been reset to
  // exclude this logging priority.
  if (this->log_priority_enabled (log_priority) == 0)
    return 0;

  // If conditional values were set and the log priority is correct,
  // then the values are actually set.
  if (conditional_values)
    this->set (this->conditional_values_.file_,
               this->conditional_values_.line_,
               this->conditional_values_.op_status_,
               this->conditional_values_.errnum_,
               this->restart (),
               this->msg_ostream (),
               this->msg_callback ());

  // Logging is supposed to be a benign activity (i.e., not interfer
  // with normal application operations), so don't inadvertently smash
  // errno!
  ACE_Errno_Guard guard (errno);

  ACE_Log_Record log_record (log_priority,
                             ACE_OS::gettimeofday (),
                             this->getpid ());

  // bp is pointer to where to put next part of logged message.
  // bspace is the number of characters remaining in msg_.
  ACE_TCHAR *bp = const_cast<ACE_TCHAR *> (this->msg ());
  size_t bspace = ACE_MAXLOGMSGLEN;  // Leave room for Nul term.
  if (this->msg_off_ <= ACE_Log_Record::MAXLOGMSGLEN)
    bspace -= static_cast<size_t> (this->msg_off_);

  // If this platform has snprintf() capability to prevent overrunning the
  // output buffer, use it. To avoid adding a maintenance-hassle compile-
  // time couple between here and OS.cpp, don't try to figure this out at
  // compile time. Instead, do a quick check now; if we get a -1 return,
  // the platform doesn't support the length-limiting capability.
  ACE_TCHAR test[2];
  bool can_check = ACE_OS::snprintf (test, 1, ACE_TEXT ("x")) != -1;

  bool abort_prog = false;
  int exit_value = 0;

  if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::VERBOSE))
    {
      // Prepend the program name onto this message

      if (ACE_Log_Msg::program_name_ != 0)
        {
          for (const ACE_TCHAR *s = ACE_Log_Msg::program_name_;
               bspace > 1 && (*bp = *s) != '\0';
               ++s, --bspace)
            bp++;

          *bp++ = '|';
          --bspace;
        }
    }

  if (timestamp_ > 0)
    {
      ACE_TCHAR day_and_time[27];
      const ACE_TCHAR *s = 0;
      if (timestamp_ == 1)
        {
          // Print just the time
          s = ACE::timestamp (day_and_time,
                              sizeof (day_and_time) / sizeof (ACE_TCHAR),
                              true);
        }
      else
        {
          // Print time and date
          ACE::timestamp (day_and_time,
                          sizeof (day_and_time) / sizeof (ACE_TCHAR));
          s = day_and_time;
        }

      for (; bspace > 1 && (*bp = *s) != '\0'; ++s, --bspace)
        ++bp;

      *bp++ = '|';
      --bspace;
    }

  while (*format_str != '\0' && bspace > 0)
    {
      // Copy input to output until we encounter a %, however a
      // % followed by another % is not a format specification.

      if (*format_str != '%')
        {
          *bp++ = *format_str++;
          --bspace;
        }
      else if (format_str[1] == '%') // An "escaped" '%' (just print one '%').
        {
          *bp++ = *format_str++;    // Store first %
          ++format_str;             // but skip second %
          --bspace;
        }
      else
        {
          // This is most likely a format specification that ends with
          // one of the valid options described previously. To enable full
          // use of all sprintf capabilities, save the format specifier
          // from the '%' up to the format letter in a new char array.
          // This allows the full sprintf capability for padding, field
          // widths, alignment, etc.  Any width/precision requiring a
          // caller-supplied argument is extracted and placed as text
          // into the format array. Lastly, we convert the caller-supplied
          // format specifier from the ACE_Log_Msg-supported list to the
          // equivalent sprintf specifier, and run the new format spec
          // through sprintf, adding it to the bp string.

          const ACE_TCHAR *abort_str = ACE_TEXT ("Aborting...");
          const ACE_TCHAR *start_format = format_str;
          ACE_TCHAR format[128]; // Converted format string
          ACE_OS::memset (format, '\0', 128); // Set this string to known values.
          ACE_TCHAR *fp = 0;         // Current format pointer
          int       wp = 0;      // Width/precision extracted from args
          bool      done = false;
          bool      skip_nul_locate = false;
          int       this_len = 0;    // How many chars s[n]printf wrote

          fp = format;
          *fp++ = *format_str++;   // Copy in the %

          // Initialization to satisfy VC6
          int tmp_indent = 0;
          // Work through the format string to copy in the format
          // from the caller. While it's going across, extract ints
          // for '*' width/precision values from the argument list.
          // When the real format specifier is located, change it to
          // one recognized by sprintf, if needed, and do the sprintf
          // call.

          while (!done)
            {
              done = true; // Unless a conversion spec changes it

              switch (*format_str)
                {
                // The initial set of cases are the conversion
                // specifiers. Copy them in to the format array.
                // Note we don't use 'l', a normal conversion spec,
                // as a conversion because it is a ACE_Log_Msg format
                // specifier.
                case '-':
                case '+':
                case '0':
                case ' ':
                case '#':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '.':
                case 'L':
                case 'h':
                  *fp++ = *format_str;
                  done = false;
                  break;

                case '*':
                  wp = va_arg (argp, int);
                  ACE_OS::sprintf (fp, ACE_TEXT ("%d"), wp);
                  fp += ACE_OS::strlen (fp);
                  done = false;
                  break;

                case 'A':             // ACE_timer_t
                  {
                    ACE_OS::strcpy (fp, ACE_TEXT ("f"));
                    double const value = va_arg (argp, double);
                    if (can_check)
                      this_len = ACE_OS::snprintf (bp, bspace, format, value);
                    else
                      this_len = ACE_OS::sprintf (bp, format, value);
                    ACE_UPDATE_COUNT (bspace, this_len);
                  }
                  break;

                case 'a': // Abort program after handling all of format string.
                  abort_prog = true;
                  exit_value = va_arg (argp, int);
                  ACE_OS::strsncpy (bp, abort_str, bspace);
                  if (bspace > ACE_OS::strlen (abort_str))
                    bspace -= ACE_OS::strlen (abort_str);
                  else
                    bspace = 0;
                  break;

                case 'l':             // Source file line number
                  ACE_OS::strcpy (fp, ACE_TEXT ("d"));
                  if (can_check)
                    this_len = ACE_OS::snprintf (bp,
                                                 bspace,
                                                 format,
                                                 this->linenum ());
                  else
                    this_len = ACE_OS::sprintf (bp, format, this->linenum ());
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;

                case 'N':             // Source file name
#if !defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
                  ACE_OS::strcpy (fp, ACE_TEXT ("ls"));
#else
                  ACE_OS::strcpy (fp, ACE_TEXT ("s"));
#endif
                  if (can_check)
                    this_len = ACE_OS::snprintf (bp, bspace, format,
                                                 this->file () ?
                                                 ACE_TEXT_CHAR_TO_TCHAR (this->file ())
                                                 : ACE_TEXT ("<unknown file>"));
                  else
                    this_len = ACE_OS::sprintf (bp, format,
                                                this->file () ?
                                                ACE_TEXT_CHAR_TO_TCHAR (this->file ())
                                                : ACE_TEXT ("<unknown file>"));
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;

                case 'n':             // Program name
#if !defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
                  ACE_OS::strcpy (fp, ACE_TEXT ("ls"));
#else /* ACE_WIN32 && ACE_USES_WCHAR */
                  ACE_OS::strcpy (fp, ACE_TEXT ("s"));
#endif
                  if (can_check)
                    this_len = ACE_OS::snprintf (bp, bspace, format,
                                                 ACE_Log_Msg::program_name_ ?
                                                 ACE_Log_Msg::program_name_ :
                                                 ACE_TEXT ("<unknown>"));
                  else
                    this_len = ACE_OS::sprintf (bp, format,
                                                ACE_Log_Msg::program_name_ ?
                                                ACE_Log_Msg::program_name_ :
                                                ACE_TEXT ("<unknown>"));
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;

                case 'P':             // Process ID
#if defined (ACE_OPENVMS)
                  // Print the process id in hex on OpenVMS.
                  ACE_OS::strcpy (fp, ACE_TEXT ("x"));
#else
                  ACE_OS::strcpy (fp, ACE_TEXT ("d"));
#endif
                  if (can_check)
                    this_len = ACE_OS::snprintf
                      (bp, bspace, format,
                       static_cast<int> (this->getpid ()));
                  else
                    this_len = ACE_OS::sprintf
                      (bp, format, static_cast<int> (this->getpid ()));
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;

                case 'p':             // <errno> string, ala perror()
                  {
                    errno = 0;
                    char *msg = ACE_OS::strerror (ACE::map_errno (this->errnum ()));
                    // Windows can try to translate the errnum using
                    // system calls if strerror() doesn't get anything useful.
#if defined (ACE_WIN32)
                    if (errno == 0)
                      {
#endif

#if !defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
                        ACE_OS::strcpy (fp, ACE_TEXT ("ls: %ls"));
                        wchar_t *str = va_arg (argp, wchar_t *);
#else
                        ACE_OS::strcpy (fp, ACE_TEXT ("s: %s"));
                        ACE_TCHAR *str = va_arg (argp, ACE_TCHAR *);
#endif
                        if (can_check)
                          this_len = ACE_OS::snprintf
                            (bp, bspace, format,
                             str ? str : ACE_TEXT ("(null)"),
                             ACE_TEXT_CHAR_TO_TCHAR (msg));
                        else
                          this_len = ACE_OS::sprintf
                            (bp, format,
                             str ? str : ACE_TEXT ("(null)"),
                             ACE_TEXT_CHAR_TO_TCHAR (msg));
#if defined (ACE_WIN32)
                      }
                    else
                      {
                        errno = ACE::map_errno (this->errnum ());
                        ACE_TCHAR *lpMsgBuf = 0;

     // PharLap can't do FormatMessage, so try for socket
     // error.
# if !defined (ACE_HAS_PHARLAP)
                        ACE_TEXT_FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER
                                                  | FORMAT_MESSAGE_MAX_WIDTH_MASK
                                                  | FORMAT_MESSAGE_FROM_SYSTEM,
                                                  0,
                                                  errno,
                                                  MAKELANGID (LANG_NEUTRAL,
                                                              SUBLANG_DEFAULT),
                                                              // Default language
                                                  (ACE_TCHAR *) &lpMsgBuf,
                                                  0,
                                                  0);
# endif /* ACE_HAS_PHARLAP */

                        // If we don't get a valid response from
                        // <FormatMessage>, we'll assume this is a
                        // WinSock error and so we'll try to convert
                        // it into a string.  If this doesn't work it
                        // returns "unknown error" which is fine for
                        // our purposes.
                        ACE_TCHAR *str = va_arg (argp, ACE_TCHAR *);
                        if (lpMsgBuf == 0)
                          {
                            const ACE_TCHAR *message =
                              ACE::sock_error (errno);
                            ACE_OS::strcpy (fp, ACE_TEXT ("s: %s"));
                            if (can_check)
                              this_len = ACE_OS::snprintf
                                (bp, bspace, format,
                                 str ? str : ACE_TEXT ("(null)"),
                                 message);
                            else
                              this_len = ACE_OS::sprintf
                                (bp, format,
                                 str ? str : ACE_TEXT ("(null)"),
                                 message);
                          }
                        else
                          {
                            ACE_OS::strcpy (fp, ACE_TEXT ("s: %s"));
                            if (can_check)
                              this_len = ACE_OS::snprintf
                                (bp, bspace, format,
                                 str ? str : ACE_TEXT ("(null)"),
                                 lpMsgBuf);
                            else
                              this_len = ACE_OS::sprintf
                                (bp, format,
                                 str ? str : ACE_TEXT ("(null)"),
                                 lpMsgBuf);
                            // Free the buffer.
                            ::LocalFree (lpMsgBuf);
                          }
                      }
#endif /* ACE_WIN32 */
                    ACE_UPDATE_COUNT (bspace, this_len);
                    break;
                  }

                case 'M': // Print the name of the priority of the message.

                    // Look at the format precision specifier. .1 is interpreted
                    // as a single character printout, otherwise we print the name of
                    // the priority.

                  // So, did we find a .1 specifier? Do we need to override it?
                  if (format[1] == ACE_TEXT('.') &&
                      format[2] == ACE_TEXT('1'))
                  {
                      // Yup.
                      // Print a single character signifying the severity of the message
                      fp = format;
                      fp++;

# if defined (ACE_USES_WCHAR)

#     if defined (ACE_WIN32) // Windows uses 'c' for a wide character
                    ACE_OS::strcpy (fp, ACE_TEXT ("c"));
#     else // Other platforms behave differently
#         if defined (HPUX) // HP-Unix compatible
                  ACE_OS::strcpy (fp, ACE_TEXT ("C"));
#         else // Other
                  ACE_OS::strcpy (fp, ACE_TEXT ("lc"));
#         endif /* HPUX */
#     endif

# else /* ACE_USES_WCHAR */

                      // Non-unicode builds simply use a standard character format specifier
                      ACE_OS::strcpy (fp, ACE_TEXT ("c"));

# endif /* ACE_USES_WCHAR */

                      // Below is an optimized (binary search based)
                      // version of the following simple piece of code:
                      //
                      // log_priority == LM_SHUTDOWN  ? 'S' :   // Shutdown
                      // log_priority == LM_TRACE     ? 'T' :   // Trace
                      // log_priority == LM_DEBUG     ? 'D' :   // Debug
                      // log_priority == LM_INFO      ? 'I' :   // Info
                      // log_priority == LM_NOTICE    ? 'N' :   // Notice
                      // log_priority == LM_WARNING   ? 'W' :   // Warning
                      // log_priority == LM_STARTUP   ? 'U' :   // Startup
                      // log_priority == LM_ERROR     ? 'E' :   // Error
                      // log_priority == LM_CRITICAL  ? 'C' :   // Critical
                      // log_priority == LM_ALERT     ? 'A' :   // Alert
                      // log_priority == LM_EMERGENCY ? '!' :   // Emergency
                      //                                '?'      // Unknown

                      if (can_check)
                      {
                        this_len = ACE_OS::snprintf
                          (bp, bspace, format,
#if !defined (ACE_USES_WCHAR) || defined (ACE_WIN32)
                           (int)
#else
                           (wint_t)
#endif
                           (log_priority <= LM_WARNING) ?
                           (log_priority <= LM_DEBUG) ?
                           (log_priority <= LM_TRACE) ?
                           (log_priority == LM_SHUTDOWN) ?
                           ACE_TEXT('S') : ACE_TEXT('T') : ACE_TEXT('D') :
                           (log_priority <= LM_NOTICE) ?
                           (log_priority == LM_INFO) ?
                           ACE_TEXT('I') : ACE_TEXT('N') : ACE_TEXT('W') :
                           (log_priority <= LM_CRITICAL) ?
                           (log_priority <= LM_ERROR) ?
                           (log_priority == LM_STARTUP) ?
                           ACE_TEXT('U') : ACE_TEXT('E') : ACE_TEXT('C') :
                           (log_priority <= LM_EMERGENCY) ?
                           (log_priority == LM_ALERT) ?
                           ACE_TEXT('A') : ACE_TEXT('!') : ACE_TEXT('?'));
                      }
                      else
                      {
                        this_len = ACE_OS::sprintf
                          (bp, format,
#if !defined (ACE_USES_WCHAR) || defined (ACE_WIN32)
                           (int)
#else
                           (wint_t)
#endif
                           (log_priority <= LM_WARNING) ?
                           (log_priority <= LM_DEBUG) ?
                           (log_priority <= LM_TRACE) ?
                           (log_priority == LM_SHUTDOWN) ?
                           ACE_TEXT('S') : ACE_TEXT('T') : ACE_TEXT('D') :
                           (log_priority <= LM_NOTICE) ?
                           (log_priority == LM_INFO) ?
                           ACE_TEXT('I') : ACE_TEXT('N') : ACE_TEXT('W') :
                           (log_priority <= LM_CRITICAL) ?
                           (log_priority <= LM_ERROR) ?
                           (log_priority == LM_STARTUP) ?
                           ACE_TEXT('U') : ACE_TEXT('E') : ACE_TEXT('C') :
                           (log_priority <= LM_EMERGENCY) ?
                           (log_priority == LM_ALERT) ?
                           ACE_TEXT('A') : ACE_TEXT('!') : ACE_TEXT('?'));
                      }

                      ACE_UPDATE_COUNT (bspace, this_len);
                  }
                  else
                  {
                      // Nope, print out standard priority_name() string

#if !defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
                      ACE_OS::strcpy (fp, ACE_TEXT ("ls"));
#else
                      ACE_OS::strcpy (fp, ACE_TEXT ("s"));
#endif
                      if (can_check)
                        this_len = ACE_OS::snprintf
                          (bp, bspace, format,
                           ACE_Log_Record::priority_name (log_priority));
                      else
                        this_len = ACE_OS::sprintf
                          (bp, format,
                           ACE_Log_Record::priority_name (log_priority));
                      ACE_UPDATE_COUNT (bspace, this_len);
                  }
                  break;

                case 'm': // Format the string assocated with the errno value.
                  {
                    errno = 0;
                    char *msg = ACE_OS::strerror (ACE::map_errno (this->errnum ()));
                    // Windows can try to translate the errnum using
                    // system calls if strerror() doesn't get anything useful.
#if defined (ACE_WIN32)
                    if (errno == 0)
                      {
#endif

#if !defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
                        ACE_OS::strcpy (fp, ACE_TEXT ("ls"));
#else /* ACE_WIN32 && ACE_USES_WCHAR */
                        ACE_OS::strcpy (fp, ACE_TEXT ("s"));
#endif
                        if (can_check)
                          this_len = ACE_OS::snprintf
                            (bp, bspace, format, ACE_TEXT_CHAR_TO_TCHAR (msg));
                        else
                          this_len = ACE_OS::sprintf
                            (bp, format, ACE_TEXT_CHAR_TO_TCHAR (msg));
#if defined (ACE_WIN32)
                      }
                    else
                      {
                        errno = ACE::map_errno (this->errnum ());
                        ACE_TCHAR *lpMsgBuf = 0;

     // PharLap can't do FormatMessage, so try for socket
     // error.
# if !defined (ACE_HAS_PHARLAP)
                        ACE_TEXT_FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER
                                                  | FORMAT_MESSAGE_MAX_WIDTH_MASK
                                                  | FORMAT_MESSAGE_FROM_SYSTEM,
                                                  0,
                                                  errno,
                                                  MAKELANGID (LANG_NEUTRAL,
                                                              SUBLANG_DEFAULT),
                                                              // Default language
                                                  (ACE_TCHAR *) &lpMsgBuf,
                                                  0,
                                                  0);
# endif /* ACE_HAS_PHARLAP */

                        // If we don't get a valid response from
                        // <FormatMessage>, we'll assume this is a
                        // WinSock error and so we'll try to convert
                        // it into a string.  If this doesn't work it
                        // returns "unknown error" which is fine for
                        // our purposes.
                        if (lpMsgBuf == 0)
                          {
                            const ACE_TCHAR *message =
                              ACE::sock_error (errno);
                            ACE_OS::strcpy (fp, ACE_TEXT ("s"));
                            if (can_check)
                              this_len = ACE_OS::snprintf
                                (bp, bspace, format, message);
                            else
                              this_len = ACE_OS::sprintf (bp, format, message);
                          }
                        else
                          {
                            ACE_OS::strcpy (fp, ACE_TEXT ("s"));
                            if (can_check)
                              this_len = ACE_OS::snprintf
                                (bp, bspace, format, lpMsgBuf);
                            else
                              this_len = ACE_OS::sprintf
                                (bp, format, lpMsgBuf);
                            // Free the buffer.
                            ::LocalFree (lpMsgBuf);
                          }
                      }
#endif /* ACE_WIN32 */
                    ACE_UPDATE_COUNT (bspace, this_len);
                    break;
                  }

                case 'R': // Format the return status of the operation.
                  this->op_status (va_arg (argp, int));
                  ACE_OS::strcpy (fp, ACE_TEXT ("d"));
                  if (can_check)
                    this_len = ACE_OS::snprintf
                      (bp, bspace, format, this->op_status ());
                  else
                    this_len = ACE_OS::sprintf
                      (bp, format, this->op_status ());
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;

                case '{': // Increment the trace_depth, then indent
                  skip_nul_locate = true;
                  (void) this->inc ();
                  break;

                case '}': // indent, then decrement trace_depth
                  skip_nul_locate = true;
                  (void) this->dec ();
                  break;

                case '$': // insert a newline, then indent the next line
                          // according to %I
                  *bp++ = '\n';
                  --bspace;
                  /* fallthrough */

                case 'I': // Indent with nesting_depth*width spaces
                  // Caller can do %*I to override nesting indent, and
                  // if %*I was done, wp has the extracted width.
#if defined (ACE_HAS_TRACE)
                  if (0 == wp)
                    wp = ACE_Trace::get_nesting_indent ();
#else
                  if (0 == wp)
                    wp = 4;
#endif /* ACE_HAS_TRACE */
                  wp *= this->trace_depth_;
                  if (static_cast<size_t> (wp) > bspace)
                    wp = static_cast<int> (bspace);
                  for (tmp_indent = wp;
                       tmp_indent;
                       --tmp_indent)
                    *bp++ = ' ';

                  *bp = '\0';
                  bspace -= static_cast<size_t> (wp);
                  skip_nul_locate = true;
                  break;

                case 'r': // Run (invoke) this subroutine.
                  {
                    ptrdiff_t const osave = ACE_Log_Msg::msg_off_;

                    if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_,
                                         ACE_Log_Msg::SILENT) &&
                        bspace > 1)
                      {
                        *bp++ = '{';
                        --bspace;
                      }
                    ACE_Log_Msg::msg_off_ =  bp - this->msg_;

                    (*va_arg (argp, PTF))();

                    if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_,
                                         ACE_Log_Msg::SILENT) &&
                        bspace > (1 + ACE_OS::strlen (bp)))
                      {
                        bspace -= (ACE_OS::strlen (bp) + 1);
                        bp += ACE_OS::strlen (bp);
                        *bp++ =  '}';
                      }
                    *bp = '\0';
                    skip_nul_locate = true;
                    ACE_Log_Msg::msg_off_ = osave;
                    break;
                  }

                case 'S': // format the string for with this signal number.
                  {
                    const int sig = va_arg (argp, int);
                    ACE_OS::strcpy (fp, ACE_TEXT ("s"));
                    if (can_check)
                      this_len = ACE_OS::snprintf
                        (bp, bspace, format, ACE_OS::strsignal(sig));
                    else
                      this_len = ACE_OS::sprintf
                        (bp, format, ACE_OS::strsignal(sig));
                    ACE_UPDATE_COUNT (bspace, this_len);
                    break;
                  }

                case 'D': // Format the timestamp in format:
                          // yyyy-mm-dd hour:minute:sec.usec
                          // This is a maximum of 27 characters
                          // including terminator.
                  {
                    ACE_TCHAR day_and_time[27];
                    // Did we find the flag indicating a time value argument
                    if (format[1] == ACE_TEXT('#'))
                    {
                      ACE_Time_Value* time_value = va_arg (argp, ACE_Time_Value*);
                      ACE::timestamp (*time_value,
                                      day_and_time,
                                      sizeof (day_and_time) / sizeof (ACE_TCHAR));
                    }
                    else
                    {
                      ACE::timestamp (day_and_time,
                                      sizeof (day_and_time) / sizeof (ACE_TCHAR));
                    }
#if !defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
                    ACE_OS::strcpy (fp, ACE_TEXT ("ls"));
#else
                    ACE_OS::strcpy (fp, ACE_TEXT ("s"));
#endif
                    if (can_check)
                      this_len = ACE_OS::snprintf
                        (bp, bspace, format, day_and_time);
                    else
                      this_len = ACE_OS::sprintf (bp, format, day_and_time);
                    ACE_UPDATE_COUNT (bspace, this_len);
                    break;
                  }

                case 'T': // Format the timestamp in
                          // hour:minute:sec.usec format.
                  {
                    ACE_TCHAR day_and_time[27];
#if !defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
                    ACE_OS::strcpy (fp, ACE_TEXT ("ls"));
#else
                    ACE_OS::strcpy (fp, ACE_TEXT ("s"));
#endif
                    // Did we find the flag indicating a time value argument
                    if (format[1] == ACE_TEXT('#'))
                    {
                      ACE_Time_Value* time_value = va_arg (argp, ACE_Time_Value*);
                      if (can_check)
                        this_len = ACE_OS::snprintf
                          (bp, bspace, format,
                          ACE::timestamp (*time_value,
                                         day_and_time,
                                         sizeof day_and_time / sizeof (ACE_TCHAR)));
                      else
                        this_len = ACE_OS::sprintf
                          (bp, format, ACE::timestamp (*time_value,
                                                      day_and_time,
                                                      sizeof day_and_time / sizeof (ACE_TCHAR)));
                    }
                    else
                    {
                      if (can_check)
                        this_len = ACE_OS::snprintf
                          (bp, bspace, format,
                          ACE::timestamp (day_and_time, sizeof day_and_time / sizeof (ACE_TCHAR)));
                      else
                        this_len = ACE_OS::sprintf
                          (bp, format, ACE::timestamp (day_and_time,
                                                      sizeof day_and_time / sizeof (ACE_TCHAR)));
                    }
                    ACE_UPDATE_COUNT (bspace, this_len);
                    break;
                  }

                case 't': // Format thread id.
#if defined (ACE_WIN32)
                  ACE_OS::strcpy (fp, ACE_TEXT ("u"));
                  if (can_check)
                    this_len = ACE_OS::snprintf
                      (bp, bspace, format,
                       static_cast<unsigned> (ACE_Thread::self ()));
                  else
                    this_len =
                      ACE_OS::sprintf (bp,
                                       format,
                                       static_cast <unsigned> (ACE_Thread::self ()));
#else
                  ACE_hthread_t t_id;
                  ACE_OS::thr_self (t_id);

                  // Yes, this is an ugly C-style cast, but the correct
                  // C++ cast is different depending on whether the t_id
                  // is an integral type or a pointer type. FreeBSD uses
                  // a pointer type, but doesn't have a _np function to
                  // get an integral type, like the OSes above.
                  ACE_OS::strcpy (fp, ACE_TEXT ("lu"));
                  if (can_check)
                    this_len = ACE_OS::snprintf
                      (bp, bspace, format, (unsigned long)t_id);
                  else
                    this_len = ACE_OS::sprintf
                      (bp, format, (unsigned long)t_id);

#endif /* ACE_WIN32 */
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;

                case 's':                       // String
                  {
#if !defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
                    wchar_t *str = va_arg (argp, wchar_t *);
                    ACE_OS::strcpy (fp, ACE_TEXT ("ls"));
#else /* ACE_WIN32 && ACE_USES_WCHAR */
                    ACE_TCHAR *str = va_arg (argp, ACE_TCHAR *);
                    ACE_OS::strcpy (fp, ACE_TEXT ("s"));
#endif /* ACE_WIN32 && ACE_USES_WCHAR */
                    if (can_check)
                      this_len = ACE_OS::snprintf
                        (bp, bspace, format, str ? str : ACE_TEXT ("(null)"));
                    else
                      this_len = ACE_OS::sprintf
                        (bp, format, str ? str : ACE_TEXT ("(null)"));
                    ACE_UPDATE_COUNT (bspace, this_len);
                  }
                  break;

                case 'C':         // Narrow-char string
                  {
                    char *cstr = va_arg (argp, char *);
#if defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
                    ACE_OS::strcpy (fp, ACE_TEXT ("S"));
#else /* ACE_WIN32 && ACE_USES_WCHAR */
                    ACE_OS::strcpy (fp, ACE_TEXT ("s"));
#endif /* ACE_WIN32 && ACE_USES_WCHAR */
                    if (can_check)
                      this_len = ACE_OS::snprintf
                        (bp, bspace, format, cstr ? cstr : "(null)");
                    else
                      this_len = ACE_OS::sprintf
                        (bp, format, cstr ? cstr : "(null)");
                    ACE_UPDATE_COUNT (bspace, this_len);
                  }
                  break;

                case 'W':
                  {
#if defined (ACE_HAS_WCHAR)
                    wchar_t *wchar_str = va_arg (argp, wchar_t *);
# if defined (HPUX)
                    ACE_OS::strcpy (fp, ACE_TEXT ("S"));
# elif defined (ACE_WIN32)
#   if defined (ACE_USES_WCHAR)
                    ACE_OS::strcpy (fp, ACE_TEXT ("s"));
#   else /* ACE_USES_WCHAR */
                    ACE_OS::strcpy (fp, ACE_TEXT ("S"));
#   endif /* ACE_USES_WCHAR */
# else
                    ACE_OS::strcpy (fp, ACE_TEXT ("ls"));
# endif /* HPUX */
                    if (can_check)
                      this_len = ACE_OS::snprintf
                        (bp, bspace, format, wchar_str ? wchar_str : ACE_TEXT_WIDE("(null)"));
                    else
                      this_len = ACE_OS::sprintf
                        (bp, format, wchar_str ? wchar_str : ACE_TEXT_WIDE("(null)"));
#endif /* ACE_HAS_WCHAR */
                    ACE_UPDATE_COUNT (bspace, this_len);
                  }
                  break;

                case 'w':              // Wide character
#if defined (ACE_WIN32)
# if defined (ACE_USES_WCHAR)
                  ACE_OS::strcpy (fp, ACE_TEXT ("c"));
# else /* ACE_USES_WCHAR */
                  ACE_OS::strcpy (fp, ACE_TEXT ("C"));
# endif /* ACE_USES_WCHAR */
                  if (can_check)
                    this_len = ACE_OS::snprintf
                      (bp, bspace, format, va_arg (argp, int));
                  else
                    this_len = ACE_OS::sprintf
                      (bp, format, va_arg (argp, int));
#elif defined (ACE_USES_WCHAR)
# if defined (HPUX)
                  ACE_OS::strcpy (fp, ACE_TEXT ("C"));
# else
                  ACE_OS::strcpy (fp, ACE_TEXT ("lc"));
# endif /* HPUX */
                  if (can_check)
                    this_len = ACE_OS::snprintf
                      (bp, bspace, format, va_arg (argp, wint_t));
                  else
                    this_len = ACE_OS::sprintf
                      (bp, format, va_arg (argp, wint_t));
#else /* ACE_WIN32 */
                  ACE_OS::strcpy (fp, ACE_TEXT ("u"));
                  if (can_check)
                    this_len = ACE_OS::snprintf
                      (bp, bspace, format, va_arg (argp, int));
                  else
                    this_len = ACE_OS::sprintf
                      (bp, format, va_arg (argp, int));
#endif /* ACE_WIN32 */
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;

                case 'z':              // ACE_OS::WChar character
                  {
                    // On some platforms sizeof (wchar_t) can be 2
                    // on the others 4 ...
                    wchar_t wtchar =
                      static_cast<wchar_t> (va_arg (argp, int));
#if defined (ACE_WIN32)
# if defined (ACE_USES_WCHAR)
                    ACE_OS::strcpy (fp, ACE_TEXT ("c"));
# else /* ACE_USES_WCHAR */
                    ACE_OS::strcpy (fp, ACE_TEXT ("C"));
# endif /* ACE_USES_WCHAR */
#elif defined (ACE_USES_WCHAR)
# if defined (HPUX)
                    ACE_OS::strcpy (fp, ACE_TEXT ("C"));
# else
                    ACE_OS::strcpy (fp, ACE_TEXT ("lc"));
# endif /* HPUX */
#else /* ACE_WIN32 */
                    ACE_OS::strcpy (fp, ACE_TEXT ("u"));
#endif /* ACE_WIN32 */
                    if (can_check)
                      this_len = ACE_OS::snprintf (bp, bspace, format, wtchar);
                    else
                      this_len = ACE_OS::sprintf (bp, format, wtchar);
                    ACE_UPDATE_COUNT (bspace, this_len);
                    break;
                  }

                 case 'Z':              // ACE_OS::WChar character string
                  {
                    ACE_OS::WChar *wchar_str = va_arg (argp, ACE_OS::WChar*);
                    if (wchar_str == 0)
                      break;

                    wchar_t *wchar_t_str = 0;
                    if (sizeof (ACE_OS::WChar) != sizeof (wchar_t))
                      {
                        size_t len = ACE_OS::wslen (wchar_str) + 1;
                        ACE_NEW_NORETURN(wchar_t_str, wchar_t[len]);
                        if (wchar_t_str == 0)
                          break;

                        for (size_t i = 0; i < len; ++i)
                          {
                            wchar_t_str[i] = wchar_str[i];
                          }
                      }

                    if (wchar_t_str == 0)
                      {
                        wchar_t_str = reinterpret_cast<wchar_t*> (wchar_str);
                      }
#if defined (ACE_WIN32)
# if defined (ACE_USES_WCHAR)
                  ACE_OS::strcpy (fp, ACE_TEXT ("s"));
# else /* ACE_USES_WCHAR */
                  ACE_OS::strcpy (fp, ACE_TEXT ("S"));
# endif /* ACE_USES_WCHAR */
#elif defined (ACE_HAS_WCHAR)
# if defined (HPUX)
                  ACE_OS::strcpy (fp, ACE_TEXT ("S"));
# else
                  ACE_OS::strcpy (fp, ACE_TEXT ("ls"));
# endif /* HPUX */
#endif /* ACE_WIN32 / ACE_HAS_WCHAR */
                  if (can_check)
                    this_len = ACE_OS::snprintf
                      (bp, bspace, format, wchar_t_str);
                  else
                    this_len = ACE_OS::sprintf (bp, format, wchar_t_str);
                  if(sizeof(ACE_OS::WChar) != sizeof(wchar_t))
                    {
                      delete [] wchar_t_str;
                    }
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;
                  }

                case 'c':
#if defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
                  ACE_OS::strcpy (fp, ACE_TEXT ("C"));
#else
                  ACE_OS::strcpy (fp, ACE_TEXT ("c"));
#endif /* ACE_WIN32 && ACE_USES_WCHAR */
                  if (can_check)
                    this_len = ACE_OS::snprintf
                      (bp, bspace, format, va_arg (argp, int));
                  else
                    this_len = ACE_OS::sprintf
                      (bp, format, va_arg (argp, int));
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;

                case 'd': case 'i': case 'o':
                case 'u': case 'x': case 'X':
                  fp[0] = *format_str;
                  fp[1] = '\0';
                  if (can_check)
                    this_len = ACE_OS::snprintf
                      (bp, bspace, format, va_arg (argp, int));
                  else
                    this_len = ACE_OS::sprintf
                      (bp, format, va_arg (argp, int));
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;

                case 'F': case 'f': case 'e': case 'E':
                case 'g': case 'G':
                  fp[0] = *format_str;
                  fp[1] = '\0';
                  if (can_check)
                    this_len = ACE_OS::snprintf
                      (bp, bspace, format, va_arg (argp, double));
                  else
                    this_len = ACE_OS::sprintf
                      (bp, format, va_arg (argp, double));
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;

                case 'Q':
                  {
                    const ACE_TCHAR *fmt = ACE_UINT64_FORMAT_SPECIFIER;
                    ACE_OS::strcpy (fp, &fmt[1]);    // Skip leading %
                    if (can_check)
                      this_len = ACE_OS::snprintf (bp, bspace,
                                                   format,
                                                   va_arg (argp, ACE_UINT64));
                    else
                      this_len = ACE_OS::sprintf (bp,
                                                  format,
                                                  va_arg (argp, ACE_UINT64));
                  }
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;

                case 'q':
                   {
                     const ACE_TCHAR *fmt = ACE_INT64_FORMAT_SPECIFIER;
                     ACE_OS::strcpy (fp, &fmt[1]);    // Skip leading %
                     if (can_check)
                       this_len = ACE_OS::snprintf (bp, bspace,
                                                    format,
                                                    va_arg (argp, ACE_INT64));
                     else
                       this_len = ACE_OS::sprintf (bp,
                                                   format,
                                                   va_arg (argp, ACE_INT64));
                   }
                   ACE_UPDATE_COUNT (bspace, this_len);
                   break;

                case 'b':
                  {
                    const ACE_TCHAR *fmt = ACE_SSIZE_T_FORMAT_SPECIFIER;
                    ACE_OS::strcpy (fp, &fmt[1]);    // Skip leading %
                  }
                  if (can_check)
                    this_len = ACE_OS::snprintf (bp, bspace,
                                                 format,
                                                 va_arg (argp, ssize_t));
                  else
                    this_len = ACE_OS::sprintf (bp,
                                                format,
                                                va_arg (argp, ssize_t));
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;

                case 'B':
                  {
                    const ACE_TCHAR *fmt = ACE_SIZE_T_FORMAT_SPECIFIER;
                    ACE_OS::strcpy (fp, &fmt[1]);    // Skip leading %
                  }
                  if (can_check)
                    this_len = ACE_OS::snprintf (bp, bspace,
                                                 format,
                                                 va_arg (argp, size_t));
                  else
                    this_len = ACE_OS::sprintf (bp,
                                                format,
                                                va_arg (argp, size_t));
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;

                case ':':
                  {
                    // Assume a 32 bit time_t and change if needed.
                    const ACE_TCHAR *fmt = ACE_TEXT ("%d");
                    if (sizeof (time_t) == 8)
                      fmt = ACE_INT64_FORMAT_SPECIFIER;

                    ACE_OS::strcpy (fp, &fmt[1]);    // Skip leading %
                  }
                  if (can_check)
                    this_len = ACE_OS::snprintf (bp, bspace,
                                                 format,
                                                 va_arg (argp, time_t));
                  else
                    this_len = ACE_OS::sprintf (bp,
                                                format,
                                                va_arg (argp, time_t));
                  ACE_UPDATE_COUNT (bspace, this_len);
                  break;

                case '@':
                    ACE_OS::strcpy (fp, ACE_TEXT ("p"));
                    if (can_check)
                      this_len = ACE_OS::snprintf
                        (bp, bspace, format, va_arg (argp, void*));
                    else
                      this_len = ACE_OS::sprintf
                        (bp, format, va_arg (argp, void*));
                    ACE_UPDATE_COUNT (bspace, this_len);
                    break;

                case '?':
                  // Stack trace up to this point
                  {
                    // skip the frame that we're currently in
                    ACE_Stack_Trace t(2);
                    ACE_OS::strcpy (fp, ACE_TEXT ("s"));
                    if (can_check)
                      this_len = ACE_OS::snprintf
                        (bp, bspace, format, t.c_str ());
                    else
                      this_len = ACE_OS::sprintf
                        (bp, format, t.c_str ());
                    ACE_UPDATE_COUNT (bspace, this_len);
                    break;
                  }


                default:
                  // So, it's not a legit format specifier after all...
                  // Copy from the original % to where we are now, then
                  // continue with whatever comes next.
                  while (start_format != format_str && bspace > 0)
                    {
                      *bp++ = *start_format++;
                      --bspace;
                    }
                  if (bspace > 0)
                    {
                      *bp++ = *format_str;
                      --bspace;
                    }
                  break;
                }

              // Bump to the next char in the caller's format_str
              ++format_str;
            }

          if (!skip_nul_locate)
            while (*bp != '\0') // Locate end of bp.
              ++bp;
        }
    }

  *bp = '\0'; // Terminate bp, but don't auto-increment this!

  ssize_t result = 0;

  // Check that memory was not corrupted, if it corrupted we can't log anything
  // anymore because all our members could be corrupted.
  if (bp >= (this->msg_ + ACE_MAXLOGMSGLEN+1))
    {
      abort_prog = true;
      ACE_OS::fprintf (stderr,
                       "The following logged message is too long!\n");
    }
  else
    {
      // Copy the message from thread-specific storage into the transfer
      // buffer (this can be optimized away by changing other code...).
      log_record.msg_data (this->msg ());

      // Write the <log_record> to the appropriate location.
      result = this->log (log_record,
                          abort_prog);
    }

  if (abort_prog)
    {
      // Since we are now calling abort instead of exit, this value is
      // not used.
      ACE_UNUSED_ARG (exit_value);

      // *Always* print a message to stderr if we're aborting.  We
      // don't use verbose, however, to avoid recursive aborts if
      // something is hosed.
      log_record.print (ACE_Log_Msg::local_host_, 0, stderr);
      ACE_OS::abort ();
    }

   return result;
}

#if !defined (ACE_WIN32)
/**
 * @class ACE_Log_Msg_Sig_Guard
 *
 * @brief For use only by ACE_Log_Msg.
 *
 * Doesn't require the use of global variables or global
 * functions in an application).
 */
class ACE_Log_Msg_Sig_Guard
{
private:
  ACE_Log_Msg_Sig_Guard (void);
  ~ACE_Log_Msg_Sig_Guard (void);

  /// Original signal mask.
  sigset_t omask_;

  friend ssize_t ACE_Log_Msg::log (ACE_Log_Record &log_record,
                                   int suppress_stderr);
};

ACE_Log_Msg_Sig_Guard::ACE_Log_Msg_Sig_Guard (void)
{
#if !defined (ACE_LACKS_UNIX_SIGNALS)
  ACE_OS::sigemptyset (&this->omask_);

#  if defined (ACE_LACKS_PTHREAD_THR_SIGSETMASK)
  ACE_OS::sigprocmask (SIG_BLOCK,
                       ACE_OS_Object_Manager::default_mask (),
                       &this->omask_);
#  else
  ACE_OS::thr_sigsetmask (SIG_BLOCK,
                          ACE_OS_Object_Manager::default_mask (),
                          &this->omask_);
#  endif /* ACE_LACKS_PTHREAD_THR_SIGSETMASK */
#endif /* ACE_LACKS_UNIX_SIGNALS */
}

ACE_Log_Msg_Sig_Guard::~ACE_Log_Msg_Sig_Guard (void)
{
#if !defined (ACE_LACKS_UNIX_SIGNALS)
# if defined (ACE_LACKS_PTHREAD_THR_SIGSETMASK)
  ACE_OS::sigprocmask (SIG_SETMASK,
                       &this->omask_,
                       0);
# else
  ACE_OS::thr_sigsetmask (SIG_SETMASK,
                          &this->omask_,
                          0);
# endif /* ACE_LACKS_PTHREAD_THR_SIGSETMASK */
#endif /* ! ACE_LACKS_UNIX_SIGNALS */
}
#endif /* ! ACE_WIN32 */

ssize_t
ACE_Log_Msg::log (ACE_Log_Record &log_record,
                  int suppress_stderr)
{
  ssize_t result = 0;

  // Format the message and print it to stderr and/or ship it off to
  // the log_client daemon, and/or print it to the ostream.  Of
  // course, only print the message if "SILENT" mode is disabled.
  if (ACE_BIT_DISABLED (ACE_Log_Msg::flags_,
                        ACE_Log_Msg::SILENT))
    {
      bool tracing = this->tracing_enabled ();
      this->stop_tracing ();

#if !defined (ACE_WIN32)
      // Make this block signal-safe.
      ACE_Log_Msg_Sig_Guard sb;
#endif /* !ACE_WIN32 */

      // Do the callback, if needed, before acquiring the lock
      // to avoid holding the lock during the callback so we don't
      // have deadlock if the callback uses the logger.
      if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_,
                           ACE_Log_Msg::MSG_CALLBACK)
          && this->msg_callback () != 0)
        this->msg_callback ()->log (log_record);

      // Make sure that the lock is held during all this.
      ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                                *ACE_Log_Msg_Manager::get_lock (),
                                -1));

      if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_,
                           ACE_Log_Msg::STDERR)
          && !suppress_stderr) // This is taken care of by our caller.
        log_record.print (ACE_Log_Msg::local_host_,
                          ACE_Log_Msg::flags_,
                          stderr);

      if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::CUSTOM) ||
          ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::SYSLOG) ||
          ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::LOGGER))
        {
          // Be sure that there is a message_queue_, with multiple threads.
          ACE_MT (ACE_Log_Msg_Manager::init_backend ());
        }


      if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::LOGGER) ||
          ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::SYSLOG))
        {
          result =
            ACE_Log_Msg_Manager::log_backend_->log (log_record);
        }

      if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::CUSTOM) &&
          ACE_Log_Msg_Manager::custom_backend_ != 0)
        {
          result =
            ACE_Log_Msg_Manager::custom_backend_->log (log_record);
        }

      // This must come last, after the other two print operations
      // (see the <ACE_Log_Record::print> method for details).
      if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_,
                           ACE_Log_Msg::OSTREAM)
          && this->msg_ostream () != 0)
        log_record.print (ACE_Log_Msg::local_host_,
                          ACE_Log_Msg::flags_,
#if defined (ACE_LACKS_IOSTREAM_TOTALLY)
                          static_cast<FILE *> (this->msg_ostream ())
#else  /* ! ACE_LACKS_IOSTREAM_TOTALLY */
                          *this->msg_ostream ()
#endif /* ! ACE_LACKS_IOSTREAM_TOTALLY */
                          );

      if (tracing)
        this->start_tracing ();
   }

  return result;
}

// Calls log to do the actual print, but formats first.

int
ACE_Log_Msg::log_hexdump (ACE_Log_Priority log_priority,
                          const char *buffer,
                          size_t size,
                          const ACE_TCHAR *text)
{
  // Only print the message if <priority_mask_> hasn't been reset to
  // exclude this logging priority.
  if (this->log_priority_enabled (log_priority) == 0)
    return 0;

  ACE_TCHAR* buf = 0;
  size_t const buf_sz =
    ACE_Log_Record::MAXLOGMSGLEN - ACE_Log_Record::VERBOSE_LEN - 58;
  ACE_NEW_RETURN (buf, ACE_TCHAR[buf_sz], -1);

  ACE_TCHAR *msg_buf = 0;
  const size_t text_sz = text ? ACE_OS::strlen(text) : 0;
  ACE_NEW_RETURN (msg_buf,
                  ACE_TCHAR[text_sz + 58],
                 -1);

  buf[0] = 0; // in case size = 0

  size_t const len = ACE::format_hexdump
    (buffer, size, buf, buf_sz / sizeof (ACE_TCHAR) - text_sz);

  int sz = 0;

  if (text)
    sz = ACE_OS::sprintf (msg_buf,
#if !defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
                          ACE_TEXT ("%ls - "),
#else
                          ACE_TEXT ("%s - "),
#endif
                          text);

  sz += ACE_OS::sprintf (msg_buf + sz,
                         ACE_TEXT ("HEXDUMP ")
                         ACE_SIZE_T_FORMAT_SPECIFIER
                         ACE_TEXT (" bytes"),
                         size);

  if (len < size)
    ACE_OS::sprintf (msg_buf + sz,
                     ACE_TEXT (" (showing first ")
                     ACE_SIZE_T_FORMAT_SPECIFIER
                     ACE_TEXT (" bytes)"),
                     len);

  // Now print out the formatted buffer.
  this->log (log_priority,
             ACE_TEXT ("%s\n%s"),
             msg_buf,
             buf);

  delete [] msg_buf;
  delete [] buf;
  return 0;
}

void
ACE_Log_Msg::set (const char *file,
                  int line,
                  int op_status,
                  int errnum,
                  bool restart,
                  ACE_OSTREAM_TYPE *os,
                  ACE_Log_Msg_Callback *c)
{
  ACE_TRACE ("ACE_Log_Msg::set");
  this->file (file);
  this->linenum (line);
  this->op_status (op_status);
  this->errnum (errnum);
  this->restart (restart);
  this->msg_ostream (os);
  this->msg_callback (c);
}

void
ACE_Log_Msg::conditional_set (const char *filename,
                              int line,
                              int status,
                              int err)
{
  this->conditional_values_.is_set_ = true;
  this->conditional_values_.file_ = filename;
  this->conditional_values_.line_ = line;
  this->conditional_values_.op_status_ = status;
  this->conditional_values_.errnum_ = err;
}

void
ACE_Log_Msg::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Log_Msg::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("status_ = %d\n"), this->status_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nerrnum_ = %d\n"), this->errnum_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nlinenum_ = %d\n"), this->linenum_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nfile_ = %C\n"), this->file_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nmsg_ = %s\n"), this->msg_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nrestart_ = %d\n"), this->restart_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nostream_ = %@\n"), this->ostream_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nmsg_callback_ = %@\n"),
              this->msg_callback_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nprogram_name_ = %s\n"),
              this->program_name_ ? this->program_name_
                                  : ACE_TEXT ("<unknown>")));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nlocal_host_ = %s\n"),
              this->local_host_ ? this->local_host_
                                : ACE_TEXT ("<unknown>")));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\npid_ = %d\n"), this->getpid ()));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nflags_ = 0x%x\n"), this->flags_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ntrace_depth_ = %d\n"),
              this->trace_depth_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ntrace_active_ = %d\n"),
              this->trace_active_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ntracing_enabled_ = %d\n"),
              this->tracing_enabled_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\npriority_mask_ = 0x%x\n"),
              this->priority_mask_));
  if (this->thr_desc_ != 0 && this->thr_desc_->state () != 0)
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nthr_state_ = %d\n"),
                this->thr_desc_->state ()));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nmsg_off_ = %d\n"), this->msg_off_));

  // Be sure that there is a message_queue_, with multiple threads.
  ACE_MT (ACE_Log_Msg_Manager::init_backend ());

  ACE_MT (ACE_Log_Msg_Manager::get_lock ()->dump ());
  // Synchronize output operations.

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

void
ACE_Log_Msg::thr_desc (ACE_Thread_Descriptor *td)
{
  this->thr_desc_ = td;

  if (td != 0)
    td->acquire_release ();
}

ACE_Log_Msg_Backend *
ACE_Log_Msg::msg_backend (ACE_Log_Msg_Backend *b)
{
  ACE_TRACE ("ACE_Log_Msg::msg_backend");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                            *ACE_Log_Msg_Manager::get_lock (), 0));

  ACE_Log_Msg_Backend *tmp  = ACE_Log_Msg_Manager::custom_backend_;
  ACE_Log_Msg_Manager::custom_backend_ = b;
  return tmp;
}

ACE_Log_Msg_Backend *
ACE_Log_Msg::msg_backend (void)
{
  ACE_TRACE ("ACE_Log_Msg::msg_backend");
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                            *ACE_Log_Msg_Manager::get_lock (), 0));

  return ACE_Log_Msg_Manager::custom_backend_;
}

void
ACE_Log_Msg::msg_ostream (ACE_OSTREAM_TYPE *m, bool delete_ostream)
{
  if (this->ostream_ == m)
    {
      // Same stream, allow user to change the delete_ostream "flag"
      if (delete_ostream && !this->ostream_refcount_)
        {
          ACE_NEW (this->ostream_refcount_, Atomic_ULong (1));
        }
      else if (!delete_ostream && this->ostream_refcount_)
        {
          if (--*this->ostream_refcount_ == 0)
            {
              delete this->ostream_refcount_;
            }
          this->ostream_refcount_ = 0;
        }
      // The other two cases are no-ops, the user has requested the same
      // state that's already present.
      return;
    }

  this->cleanup_ostream ();

  if (delete_ostream)
    {
      ACE_NEW (this->ostream_refcount_, Atomic_ULong (1));
    }

  this->ostream_ = m;
}

void
ACE_Log_Msg::local_host (const ACE_TCHAR *s)
{
  if (s)
    {
      ACE_OS::free ((void *) ACE_Log_Msg::local_host_);
      {
        ACE_NO_HEAP_CHECK;

        ACE_ALLOCATOR (ACE_Log_Msg::local_host_, ACE_OS::strdup (s));
      }
    }
}

int
ACE_Log_Msg::log_priority_enabled (ACE_Log_Priority log_priority,
                                   const char *,
                                   ...)
{
  return this->log_priority_enabled (log_priority);
}

#if defined (ACE_USES_WCHAR)
int
ACE_Log_Msg::log_priority_enabled (ACE_Log_Priority log_priority,
                                   const wchar_t *,
                                   ...)
{
  return this->log_priority_enabled (log_priority);
}
#endif /* ACE_USES_WCHAR */

// ****************************************************************

void
ACE_Log_Msg::init_hook (ACE_OS_Log_Msg_Attributes &attributes
# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
                        , ACE_SEH_EXCEPT_HANDLER selector
                        , ACE_SEH_EXCEPT_HANDLER handler
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
                                   )
{
# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
  attributes.seh_except_selector_ = selector;
  attributes.seh_except_handler_ = handler;
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
  if (ACE_Log_Msg::exists ())
    {
      ACE_Log_Msg *inherit_log = ACE_LOG_MSG;
      attributes.ostream_ = inherit_log->msg_ostream ();
      if (attributes.ostream_ && inherit_log->ostream_refcount_)
        {
          ++*inherit_log->ostream_refcount_;
          attributes.ostream_refcount_ = inherit_log->ostream_refcount_;
        }
      else
        {
          attributes.ostream_refcount_ = 0;
        }
      attributes.priority_mask_ = inherit_log->priority_mask ();
      attributes.tracing_enabled_ = inherit_log->tracing_enabled ();
      attributes.restart_ = inherit_log->restart ();
      attributes.trace_depth_ = inherit_log->trace_depth ();
    }
}

void
ACE_Log_Msg::inherit_hook (ACE_OS_Thread_Descriptor *thr_desc,
                           ACE_OS_Log_Msg_Attributes &attributes)
{
#if !defined (ACE_THREADS_DONT_INHERIT_LOG_MSG)  && \
    !defined (ACE_HAS_MINIMAL_ACE_OS)
  // Inherit the logging features if the parent thread has an
  // <ACE_Log_Msg>.  Note that all of the following operations occur
  // within thread-specific storage.
  ACE_Log_Msg *new_log = ACE_LOG_MSG;

  // Note that we do not inherit the callback because this might have
  // been allocated off of the stack of the original thread, in which
  // case all hell would break loose...

  if (attributes.ostream_)
    {
      new_log->ostream_ = attributes.ostream_;
      new_log->ostream_refcount_ =
        static_cast<Atomic_ULong *> (attributes.ostream_refcount_);

      new_log->priority_mask (attributes.priority_mask_);

      if (attributes.tracing_enabled_)
        new_log->start_tracing ();

      new_log->restart (attributes.restart_);
      new_log->trace_depth (attributes.trace_depth_);
    }

  // @@ Now the TSS Log_Msg has been created, cache my thread
  // descriptor in.

  if (thr_desc != 0)
    // This downcast is safe.  We do it to avoid having to #include
    // ace/Thread_Manager.h.
    new_log->thr_desc (static_cast<ACE_Thread_Descriptor *> (thr_desc));
  // Block the thread from proceeding until
  // thread manager has thread descriptor ready.
#endif /* ! ACE_THREADS_DONT_INHERIT_LOG_MSG  &&  ! ACE_HAS_MINIMAL_ACE_OS */
}

ACE_END_VERSIONED_NAMESPACE_DECL
