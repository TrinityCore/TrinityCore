// $Id: Object_Manager.cpp 81450 2008-04-25 21:24:33Z mitza $
#include "ace/Object_Manager.h"
#if !defined (ACE_LACKS_ACE_TOKEN)
# include "ace/Token_Manager.h"
#endif /* ! ACE_LACKS_ACE_TOKEN */
#include "ace/Thread_Manager.h"
#if !defined (ACE_LACKS_ACE_SVCCONF)
#  include "ace/Service_Manager.h"
#  include "ace/Service_Config.h"
#endif /* ! ACE_LACKS_ACE_SVCCONF */
#include "ace/Signal.h"
#include "ace/Log_Msg.h"
#include "ace/Malloc.h"
#include "ace/Sig_Adapter.h"
#include "ace/Framework_Component.h"
#include "ace/DLL_Manager.h"
#include "ace/Atomic_Op.h"
#include "ace/OS_NS_sys_time.h"
#if defined (ACE_HAS_TRACE)
#include "ace/Trace.h"
#endif /* ACE_HAS_TRACE */
#if !defined (__ACE_INLINE__)
# include "ace/Object_Manager.inl"
#endif /* __ACE_INLINE__ */
#include "ace/Guard_T.h"
#include "ace/Null_Mutex.h"
#include "ace/Mutex.h"
#include "ace/RW_Thread_Mutex.h"
ACE_RCSID(ace, Object_Manager, "$Id: Object_Manager.cpp 81450 2008-04-25 21:24:33Z mitza $")
#if ! defined (ACE_APPLICATION_PREALLOCATED_OBJECT_DEFINITIONS)
# define ACE_APPLICATION_PREALLOCATED_OBJECT_DEFINITIONS
#endif /* ACE_APPLICATION_PREALLOCATED_OBJECT_DEFINITIONS */
#if ! defined (ACE_APPLICATION_PREALLOCATED_ARRAY_DEFINITIONS)
# define ACE_APPLICATION_PREALLOCATED_ARRAY_DEFINITIONS
#endif /* ACE_APPLICATION_PREALLOCATED_ARRAY_DEFINITIONS */
#if ! defined (ACE_APPLICATION_PREALLOCATED_OBJECT_DELETIONS)
# define ACE_APPLICATION_PREALLOCATED_OBJECT_DELETIONS
#endif /* ACE_APPLICATION_PREALLOCATED_OBJECT_DELETIONS */
#if ! defined (ACE_APPLICATION_PREALLOCATED_ARRAY_DELETIONS)
# define ACE_APPLICATION_PREALLOCATED_ARRAY_DELETIONS
#endif /* ACE_APPLICATION_PREALLOCATED_ARRAY_DELETIONS */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Singleton pointer.
ACE_Object_Manager *ACE_Object_Manager::instance_ = 0;
void *ACE_Object_Manager::preallocated_object[
  ACE_Object_Manager::ACE_PREALLOCATED_OBJECTS] = { 0 };
void *ACE_Object_Manager::preallocated_array[
  ACE_Object_Manager::ACE_PREALLOCATED_ARRAYS] = { 0 };
// Handy macros for use by ACE_Object_Manager constructor to
// preallocate or delete an object or array, either statically (in
// global data) or dynamically (on the heap).
#if defined (ACE_HAS_STATIC_PREALLOCATION)
# define ACE_PREALLOCATE_OBJECT(TYPE, ID)\
    {\
      static ACE_Cleanup_Adapter<TYPE> obj;\
      preallocated_object[ID] = &obj;\
    }
# define ACE_PREALLOCATE_ARRAY(TYPE, ID, COUNT)\
    {\
      static ACE_Cleanup_Adapter<TYPE> obj[COUNT];\
      preallocated_array[ID] = &obj;\
    }
#else
# define ACE_PREALLOCATE_OBJECT(TYPE, ID)\
    {\
      ACE_Cleanup_Adapter<TYPE> *obj_p;\
      ACE_NEW_RETURN (obj_p, ACE_Cleanup_Adapter<TYPE>, -1);\
      preallocated_object[ID] = obj_p;\
    }
# define ACE_PREALLOCATE_ARRAY(TYPE, ID, COUNT)\
    {\
      ACE_Cleanup_Adapter<TYPE[COUNT]> *array_p;\
      ACE_NEW_RETURN (array_p, ACE_Cleanup_Adapter<TYPE[COUNT]>, -1);\
      preallocated_array[ID] = array_p;\
    }
# define ACE_DELETE_PREALLOCATED_OBJECT(TYPE, ID)\
    ACE_CLEANUP_DESTROYER_NAME (\
      (ACE_Cleanup_Adapter<TYPE> *) preallocated_object[ID], 0);\
    preallocated_object[ID] = 0;
# define ACE_DELETE_PREALLOCATED_ARRAY(TYPE, ID, COUNT)\
    delete (ACE_Cleanup_Adapter<TYPE[COUNT]> *) preallocated_array[ID];\
    preallocated_array[ID] = 0;
#endif /* ACE_HAS_STATIC_PREALLOCATION */
#if !defined (ACE_LACKS_ACE_SVCCONF)
/**
 * @class ACE_Object_Manager_Preallocations
 *
 * @brief Performs preallocations of certain statically allocated services
 * needed by ACE.
 */
class ACE_Object_Manager_Preallocations
{
public:
  ACE_Object_Manager_Preallocations (void);
  ~ACE_Object_Manager_Preallocations (void);
private:
  ACE_Static_Svc_Descriptor ace_svc_desc_ACE_Service_Manager;
};
ACE_Object_Manager_Preallocations::ACE_Object_Manager_Preallocations (void)
{
  ACE_STATIC_SVC_DEFINE (ACE_Service_Manager_initializer,
                         ACE_TEXT ("ACE_Service_Manager"),
                         ACE_SVC_OBJ_T,
                         &ACE_SVC_NAME (ACE_Service_Manager),
                         ACE_Service_Type::DELETE_THIS |
                           ACE_Service_Type::DELETE_OBJ,
                         0)
  // Initialize the static service objects using the descriptors created
  // above.
  ace_svc_desc_ACE_Service_Manager =
    ace_svc_desc_ACE_Service_Manager_initializer;
  // Add to the list of static configured services.
  ACE_Service_Config::static_svcs ()->
    insert (&ace_svc_desc_ACE_Service_Manager);
}
ACE_Object_Manager_Preallocations::~ACE_Object_Manager_Preallocations (void)
{
}
#endif /* ! ACE_LACKS_ACE_SVCCONF */
int
ACE_Object_Manager::starting_up (void)
{
  return ACE_Object_Manager::instance_  ?  instance_->starting_up_i ()  :  1;
}
int
ACE_Object_Manager::shutting_down (void)
{
  return ACE_Object_Manager::instance_  ?  instance_->shutting_down_i ()  :  1;
}
#if defined (ACE_DISABLE_WIN32_ERROR_WINDOWS)
// Instead of popping up a window for exceptions, just print something out
LONG _stdcall ACE_UnhandledExceptionFilter (PEXCEPTION_POINTERS pExceptionInfo)
{
  DWORD dwExceptionCode = pExceptionInfo->ExceptionRecord->ExceptionCode;
  if (dwExceptionCode == EXCEPTION_ACCESS_VIOLATION)
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("\nERROR: ACCESS VIOLATION\n")));
  else
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("\nERROR: UNHANDLED EXCEPTION\n")));
  return EXCEPTION_EXECUTE_HANDLER;
}
#endif /* ACE_DISABLE_WIN32_ERROR_WINDOWS */
// Initialize an ACE_Object_Manager.  There can be instances of this object
// other than The Instance.  This can happen if a user creates one for some
// reason.  All objects set up their per-object information and managed
// objects, but only The Instance sets up the static preallocated objects and
// the (static) ACE_Service_Config signal handler.
int
ACE_Object_Manager::init (void)
{
  if (starting_up_i ())
    {
      // First, indicate that the ACE_Object_Manager instance is being
      // initialized.
      object_manager_state_ = OBJ_MAN_INITIALIZING;
      // Only The Instance sets up with ACE_OS_Object_Manager and initializes
      // the preallocated objects.
      if (this == instance_)
        {
          // Make sure that the ACE_OS_Object_Manager has been created,
          // and register with it for chained fini ().
          ACE_OS_Object_Manager::instance ()->next_ = this;
#     if defined (ACE_HAS_BUILTIN_ATOMIC_OP)
          ACE_Atomic_Op<ACE_Thread_Mutex, long>::init_functions ();
          ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>::init_functions ();
#     endif /* ACE_HAS_BUILTIN_ATOMIC_OP */
#     if !defined (ACE_LACKS_ACE_SVCCONF)
          // Construct the ACE_Service_Config's signal handler.
          ACE_NEW_RETURN (ace_service_config_sig_handler_,
                     ACE_Sig_Adapter (&ACE_Service_Config::handle_signal), -1);
          ACE_Service_Config::signal_handler (ace_service_config_sig_handler_);
#     endif /* ! ACE_LACKS_ACE_SVCCONF */
          // Allocate the preallocated (hard-coded) object instances.
          ACE_PREALLOCATE_OBJECT (ACE_SYNCH_RW_MUTEX, ACE_FILECACHE_LOCK)
#     if defined (ACE_HAS_THREADS)
          ACE_PREALLOCATE_OBJECT (ACE_Recursive_Thread_Mutex,
                                  ACE_STATIC_OBJECT_LOCK)
#     endif /* ACE_HAS_THREADS */
#     if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
          ACE_PREALLOCATE_OBJECT (ACE_Thread_Mutex,
                                  ACE_MT_CORBA_HANDLER_LOCK)
          ACE_PREALLOCATE_OBJECT (ACE_Thread_Mutex, ACE_DUMP_LOCK)
          ACE_PREALLOCATE_OBJECT (ACE_Recursive_Thread_Mutex,
                                  ACE_SIG_HANDLER_LOCK)
          ACE_PREALLOCATE_OBJECT (ACE_Null_Mutex, ACE_SINGLETON_NULL_LOCK)
          ACE_PREALLOCATE_OBJECT (ACE_Recursive_Thread_Mutex,
                                  ACE_SINGLETON_RECURSIVE_THREAD_LOCK)
          ACE_PREALLOCATE_OBJECT (ACE_Thread_Mutex, ACE_THREAD_EXIT_LOCK)
#if !defined (ACE_LACKS_ACE_TOKEN) && defined (ACE_HAS_TOKENS_LIBRARY)
          ACE_PREALLOCATE_OBJECT (ACE_TOKEN_CONST::MUTEX,
                                  ACE_TOKEN_MANAGER_CREATION_LOCK)
          ACE_PREALLOCATE_OBJECT (ACE_TOKEN_CONST::MUTEX,
                                  ACE_TOKEN_INVARIANTS_CREATION_LOCK)
#endif /* ! ACE_LACKS_ACE_TOKEN && ACE_HAS_TOKENS_LIBRARY */
          ACE_PREALLOCATE_OBJECT (ACE_Thread_Mutex,
                                  ACE_PROACTOR_EVENT_LOOP_LOCK)
#     endif /* ACE_MT_SAFE */
        }
      if (this == instance_)
        {
          // Hooks for preallocated objects and arrays provided by application.
          ACE_APPLICATION_PREALLOCATED_OBJECT_DEFINITIONS
          ACE_APPLICATION_PREALLOCATED_ARRAY_DEFINITIONS
#     if defined (ACE_HAS_TSS_EMULATION)
          // Initialize the main thread's TS storage.
          if (!ts_storage_initialized_)
            {
              ACE_TSS_Emulation::tss_open (ts_storage_);
              ts_storage_initialized_ = true;
            }
#     endif /* ACE_HAS_TSS_EMULATION */
#if defined (ACE_DISABLE_WIN32_ERROR_WINDOWS) && \
    defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
#if defined (_DEBUG) && (defined (_MSC_VER) || defined (__INTEL_COMPILER))
          _CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE );
          _CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDERR );
          _CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE );
          _CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDERR );
#endif /* _DEBUG && _MSC_VER || __INTEL_COMPILER */
          // The system does not display the critical-error-handler message box
          SetErrorMode(SEM_FAILCRITICALERRORS);
          // And this will catch all unhandled exceptions.
          SetUnhandledExceptionFilter (&ACE_UnhandledExceptionFilter);
#endif /* ACE_DISABLE_WIN32_ERROR_WINDOWS && ACE_WIN32 && !ACE_HAS_WINCE */

#     if !defined (ACE_LACKS_ACE_SVCCONF)
          ACE_NEW_RETURN (preallocations_,
                          ACE_Object_Manager_Preallocations,
                          -1);
#     endif /* ! ACE_LACKS_ACE_SVCCONF */
          // Open the main thread's ACE_Log_Msg.
          if (0 == ACE_LOG_MSG)
            return -1;
        }
      // Finally, indicate that the ACE_Object_Manager instance has
      // been initialized.
      object_manager_state_ = OBJ_MAN_INITIALIZED;
#if defined (ACE_HAS_TRACE)
      // Allow tracing again (useful if user does init/fini/init)
      ACE_Trace::start_tracing ();
#endif /* ACE_HAS_TRACE */
      return 0;
    } else {
      // Had already initialized.
      return 1;
    }
}
#if defined (ACE_HAS_TSS_EMULATION)
int
ACE_Object_Manager::init_tss (void)
{
  return ACE_Object_Manager::instance ()->init_tss_i ();
}
int
ACE_Object_Manager::init_tss_i (void)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
    *instance_->internal_lock_, -1));
  if (!ts_storage_initialized_)
    {
      ACE_TSS_Emulation::tss_open (ts_storage_);
      ts_storage_initialized_ = true;
    }
  return 0;
}
#endif
ACE_Object_Manager::ACE_Object_Manager (void)
  // With ACE_HAS_TSS_EMULATION, ts_storage_ is initialized by the call to
  // ACE_OS::tss_open () in the function body.
  : exit_info_ ()
#if !defined (ACE_LACKS_ACE_SVCCONF)
  , preallocations_ (0)
  , ace_service_config_sig_handler_ (0)
#endif /* ! ACE_LACKS_ACE_SVCCONF */
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  , singleton_null_lock_ (0)
  , singleton_recursive_lock_ (0)
#endif /* ACE_MT_SAFE */
#if defined (ACE_HAS_TSS_EMULATION)
  , ts_storage_initialized_ (false)
#endif
{
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  ACE_NEW (internal_lock_, ACE_Recursive_Thread_Mutex);
# endif /* ACE_MT_SAFE */
  // If instance_ was not 0, then another ACE_Object_Manager has
  // already been instantiated (it is likely to be one initialized by way
  // of library/DLL loading).  Let this one go through construction in
  // case there really is a good reason for it (like, ACE is a static/archive
  // library, and this one is the non-static instance (with
  // ACE_HAS_NONSTATIC_OBJECT_MANAGER, or the user has a good reason for
  // creating a separate one) but the original one will be the one retrieved
  // from calls to ACE_Object_Manager::instance().
  // Be sure that no further instances are created via instance ().
  if (instance_ == 0)
    instance_ = this;
  init ();
}
ACE_Object_Manager::~ACE_Object_Manager (void)
{
  dynamically_allocated_ = false;   // Don't delete this again in fini()
  fini ();
}
ACE_Object_Manager *
ACE_Object_Manager::instance (void)
{
  // This function should be called during construction of static
  // instances, or before any other threads have been created in
  // the process.  So, it's not thread safe.
  if (instance_ == 0)
    {
      ACE_Object_Manager *instance_pointer = 0;
      ACE_NEW_RETURN (instance_pointer,
                      ACE_Object_Manager,
                      0);
      ACE_ASSERT (instance_pointer == instance_);
      instance_pointer->dynamically_allocated_ = true;
      return instance_pointer;
    }
  else
    return instance_;
}
int
ACE_Object_Manager::at_exit_i (void *object,
                               ACE_CLEANUP_FUNC cleanup_hook,
                               void *param)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
    *instance_->internal_lock_, -1));
  if (shutting_down_i ())
    {
      errno = EAGAIN;
      return -1;
    }
  if (exit_info_.find (object))
    {
      // The object has already been registered.
      errno = EEXIST;
      return -1;
    }
  return exit_info_.at_exit_i (object, cleanup_hook, param);
}
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
int
ACE_Object_Manager::get_singleton_lock (ACE_Null_Mutex *&lock)
{
  if (starting_up ()  ||  shutting_down ())
    {
      // The preallocated lock has not been constructed yet.
      // Therefore, the program is single-threaded at this point.  Or,
      // the ACE_Object_Manager instance has been destroyed, so the
      // preallocated lock is not available.  Allocate a lock to use,
      // for interface compatibility, though there should be no
      // contention on it.
      if (ACE_Object_Manager::instance ()->singleton_null_lock_ == 0)
        {
          ACE_NEW_RETURN (ACE_Object_Manager::instance ()->
                            singleton_null_lock_,
                          ACE_Cleanup_Adapter<ACE_Null_Mutex>,
                          -1);
          // Can't register with the ACE_Object_Manager here!  The
          // lock's declaration is visible to the ACE_Object_Manager
          // destructor, so it will clean it up as a special case.
        }
      if (ACE_Object_Manager::instance ()->singleton_null_lock_ != 0)
        lock = &ACE_Object_Manager::instance ()->singleton_null_lock_->
          object ();
    }
  else
    // Use the Object_Manager's preallocated lock.
    lock = ACE_Managed_Object<ACE_Null_Mutex>::get_preallocated_object
      (ACE_Object_Manager::ACE_SINGLETON_NULL_LOCK);
  return 0;
}
int
ACE_Object_Manager::get_singleton_lock (ACE_Thread_Mutex *&lock)
{
  if (lock == 0)
    {
      if (starting_up () || shutting_down ())
        {
          // The Object_Manager and its internal lock have not been
          // constructed yet.  Therefore, the program is single-
          // threaded at this point.  Or, the ACE_Object_Manager
          // instance has been destroyed, so the internal lock is not
          // available.  Either way, we can not use double-checked
          // locking.  So, we'll leak the lock.
          ACE_NEW_RETURN (lock,
                          ACE_Thread_Mutex,
                          -1);
        }
      else
        {
          // Allocate a new lock, but use double-checked locking to
          // ensure that only one thread allocates it.
          ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex,
                                    ace_mon,
                                    *ACE_Object_Manager::instance ()->
                                    internal_lock_,
                                    -1));
          if (lock == 0)
            {
              ACE_Cleanup_Adapter<ACE_Thread_Mutex> *lock_adapter;
              ACE_NEW_RETURN (lock_adapter,
                              ACE_Cleanup_Adapter<ACE_Thread_Mutex>,
                              -1);
              lock = &lock_adapter->object ();
              // Register the lock for destruction at program
              // termination.  This call will cause us to grab the
              // ACE_Object_Manager::instance ()->internal_lock_
              // again; that's why it is a recursive lock.
              ACE_Object_Manager::at_exit (lock_adapter);
            }
        }
    }
  return 0;
}
int
ACE_Object_Manager::get_singleton_lock (ACE_Mutex *&lock)
{
  if (lock == 0)
    {
      if (starting_up ()  ||  shutting_down ())
        {
          // The Object_Manager and its internal lock have not been
          // constructed yet.  Therefore, the program is single-
          // threaded at this point.  Or, the ACE_Object_Manager
          // instance has been destroyed, so the internal lock is not
          // available.  Either way, we can not use double-checked
          // locking.  So, we'll leak the lock.
          ACE_NEW_RETURN (lock,
                          ACE_Mutex,
                          -1);
        }
      else
        {
          // Allocate a new lock, but use double-checked locking to
          // ensure that only one thread allocates it.
          ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex,
                                    ace_mon,
                                    *ACE_Object_Manager::instance ()->
                                      internal_lock_,
                                    -1));
          if (lock == 0)
            {
              ACE_Cleanup_Adapter<ACE_Mutex> *lock_adapter;
              ACE_NEW_RETURN (lock_adapter,
                              ACE_Cleanup_Adapter<ACE_Mutex>,
                              -1);
              lock = &lock_adapter->object ();
              // Register the lock for destruction at program
              // termination.  This call will cause us to grab the
              // ACE_Object_Manager::instance ()->internal_lock_
              // again; that's why it is a recursive lock.
              ACE_Object_Manager::at_exit (lock_adapter);
            }
        }
    }
  return 0;
}
int
ACE_Object_Manager::get_singleton_lock (ACE_Recursive_Thread_Mutex *&lock)
{
  if (starting_up ()  ||  shutting_down ())
    {
      // The preallocated lock has not been constructed yet.
      // Therefore, the program is single-threaded at this point.  Or,
      // the ACE_Object_Manager instance has been destroyed, so the
      // preallocated lock is not available.  Allocate a lock to use,
      // for interface compatibility, though there should be no
      // contention on it.
      if (ACE_Object_Manager::instance ()->singleton_recursive_lock_ == 0)
        ACE_NEW_RETURN (ACE_Object_Manager::instance ()->
                          singleton_recursive_lock_,
                        ACE_Cleanup_Adapter<ACE_Recursive_Thread_Mutex>,
                        -1);
      // Can't register with the ACE_Object_Manager here!  The lock's
      // declaration is visible to the ACE_Object_Manager destructor,
      // so it will clean it up as a special case.
      if (ACE_Object_Manager::instance ()->singleton_recursive_lock_ != 0)
        lock = &ACE_Object_Manager::instance ()->singleton_recursive_lock_->
          object ();
    }
  else
    {
      // Use the Object_Manager's preallocated lock.
      lock = ACE_Managed_Object<ACE_Recursive_Thread_Mutex>::
        get_preallocated_object (ACE_Object_Manager::
                                 ACE_SINGLETON_RECURSIVE_THREAD_LOCK);
    }
  return 0;
}
int
ACE_Object_Manager::get_singleton_lock (ACE_RW_Thread_Mutex *&lock)
{
  if (lock == 0)
    {
      if (starting_up () || shutting_down ())
        {
          // The Object_Manager and its internal lock have not been
          // constructed yet.  Therefore, the program is single-
          // threaded at this point.  Or, the ACE_Object_Manager
          // instance has been destroyed, so the internal lock is not
          // available.  Either way, we can not use double-checked
          // locking.  So, we'll leak the lock.
          ACE_NEW_RETURN (lock,
                          ACE_RW_Thread_Mutex,
                          -1);
        }
      else
        {
          // Allocate a new lock, but use double-checked locking to
          // ensure that only one thread allocates it.
          ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex,
                                    ace_mon,
                                    *ACE_Object_Manager::instance ()->
                                    internal_lock_,
                                    -1));
          if (lock == 0)
            {
              ACE_Cleanup_Adapter<ACE_RW_Thread_Mutex> *lock_adapter;
              ACE_NEW_RETURN (lock_adapter,
                              ACE_Cleanup_Adapter<ACE_RW_Thread_Mutex>,
                              -1);
              lock = &lock_adapter->object ();

              // Register the lock for destruction at program
              // termination.  This call will cause us to grab the
              // ACE_Object_Manager::instance ()->internal_lock_
              // again; that's why it is a recursive lock.
              ACE_Object_Manager::at_exit (lock_adapter);
            }
        }
    }
  return 0;
}
#endif /* ACE_MT_SAFE */
// Clean up an ACE_Object_Manager.  There can be instances of this object
// other than The Instance.  This can happen if (on Win32) the ACE DLL
// causes one to be created, or if a user creates one for some reason.
// Only The Instance cleans up the static preallocated objects.  All objects
// clean up their per-object information and managed objects.
int
ACE_Object_Manager::fini (void)
{
  if (shutting_down_i ())
    // Too late.  Or, maybe too early.  Either fini () has already
    // been called, or init () was never called.
    return object_manager_state_ == OBJ_MAN_SHUT_DOWN  ?  1  :  -1;
  // No mutex here.  Only the main thread should destroy the singleton
  // ACE_Object_Manager instance.
  // Indicate that this ACE_Object_Manager instance is being
  // shut down.
  object_manager_state_ = OBJ_MAN_SHUTTING_DOWN;
  // Call all registered cleanup hooks, in reverse order of
  // registration.
  exit_info_.call_hooks ();
  if (this == instance_)
    {
#if !defined (ACE_LACKS_ACE_SVCCONF)
      delete preallocations_;
      preallocations_ = 0;
#endif /* ! ACE_LACKS_ACE_SVCCONF */
#if defined (ACE_HAS_TRACE)
      ACE_Trace::stop_tracing ();
#endif /* ACE_HAS_TRACE */
#if !defined (ACE_LACKS_ACE_SVCCONF)
      // Close and possibly delete all service instances in the Service
      // Repository.
      ACE_Service_Config::fini_svcs ();
      // Unlink all services in the Service Repository and close/delete
      // all ACE library services and singletons.
      ACE_Service_Config::close ();
#endif /* ! ACE_LACKS_ACE_SVCCONF */
      // This must come after closing ACE_Service_Config, since it will
      // close down it's dlls--it manages ACE_DLL_Manager.
      ACE_Framework_Repository::close_singleton ();
      ACE_DLL_Manager::close_singleton ();
#  if ! defined (ACE_THREAD_MANAGER_LACKS_STATICS)
      ACE_Thread_Manager::close_singleton ();
#  endif /* ! ACE_THREAD_MANAGER_LACKS_STATICS */
      // Close the main thread's TSS, including its Log_Msg instance.
      ACE_OS::cleanup_tss (1 /* main thread */);
      //
      // Note:  Do not access Log Msg after this since it is gone
      //
      // Close the ACE_Allocator.
      ACE_Allocator::close_singleton ();
#if ! defined (ACE_HAS_STATIC_PREALLOCATION)
      // Hooks for deletion of preallocated objects and arrays provided by
      // application.
      ACE_APPLICATION_PREALLOCATED_ARRAY_DELETIONS
      ACE_APPLICATION_PREALLOCATED_OBJECT_DELETIONS
      // Cleanup the dynamically preallocated arrays.
      // (none)
      // Cleanup the dynamically preallocated objects.
      ACE_DELETE_PREALLOCATED_OBJECT (ACE_SYNCH_RW_MUTEX, ACE_FILECACHE_LOCK)
#if defined (ACE_HAS_THREADS)
      ACE_DELETE_PREALLOCATED_OBJECT (ACE_Recursive_Thread_Mutex,
                                      ACE_STATIC_OBJECT_LOCK)
#endif /* ACE_HAS_THREADS */
# if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
      ACE_DELETE_PREALLOCATED_OBJECT (ACE_Thread_Mutex,
                                      ACE_MT_CORBA_HANDLER_LOCK)
      ACE_DELETE_PREALLOCATED_OBJECT (ACE_Thread_Mutex, ACE_DUMP_LOCK)
      ACE_DELETE_PREALLOCATED_OBJECT (ACE_Recursive_Thread_Mutex,
                                      ACE_SIG_HANDLER_LOCK)
      ACE_DELETE_PREALLOCATED_OBJECT (ACE_Null_Mutex,
                                      ACE_SINGLETON_NULL_LOCK)
      ACE_DELETE_PREALLOCATED_OBJECT (ACE_Recursive_Thread_Mutex,
                                      ACE_SINGLETON_RECURSIVE_THREAD_LOCK)
      ACE_DELETE_PREALLOCATED_OBJECT (ACE_Thread_Mutex, ACE_THREAD_EXIT_LOCK)
#if !defined (ACE_LACKS_ACE_TOKEN) && defined (ACE_HAS_TOKENS_LIBRARY)
      ACE_DELETE_PREALLOCATED_OBJECT (ACE_TOKEN_CONST::MUTEX,
                                      ACE_TOKEN_MANAGER_CREATION_LOCK)
      ACE_DELETE_PREALLOCATED_OBJECT (ACE_TOKEN_CONST::MUTEX,
                                      ACE_TOKEN_INVARIANTS_CREATION_LOCK)
#endif /* ! ACE_LACKS_ACE_TOKEN && ACE_HAS_TOKENS_LIBRARY */
      ACE_DELETE_PREALLOCATED_OBJECT (ACE_Thread_Mutex,
                                      ACE_PROACTOR_EVENT_LOOP_LOCK)
# endif /* ACE_MT_SAFE */
#endif /* ! ACE_HAS_STATIC_PREALLOCATION */
#if defined (ACE_HAS_THREADS)
      ACE_Static_Object_Lock::cleanup_lock ();
#endif /* ACE_HAS_THREADS */
    }
#if !defined (ACE_LACKS_ACE_SVCCONF)
  delete ace_service_config_sig_handler_;
  ace_service_config_sig_handler_ = 0;
#endif /* ! ACE_LACKS_ACE_SVCCONF */
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  delete internal_lock_;
  internal_lock_ = 0;
  delete singleton_null_lock_;
  singleton_null_lock_ = 0;
  delete singleton_recursive_lock_;
  singleton_recursive_lock_ = 0;
#endif /* ACE_MT_SAFE */
  // Indicate that this ACE_Object_Manager instance has been shut down.
  object_manager_state_ = OBJ_MAN_SHUT_DOWN;
  // Then, ensure that the ACE_OS_Object_Manager gets shut down.
  if (this == instance_ && ACE_OS_Object_Manager::instance_)
    ACE_OS_Object_Manager::instance_->fini ();
  if (dynamically_allocated_)
    {
      delete this;
    }
  if (this == instance_)
    instance_ = 0;
  return 0;
}

#if !defined (ACE_HAS_NONSTATIC_OBJECT_MANAGER)
/**
 * @class ACE_Object_Manager_Manager
 *
 * @brief Ensure that the ACE_Object_Manager gets initialized at program
 * startup, and destroyed at program termination.
 *
 * Without ACE_HAS_NONSTATIC_OBJECT_MANAGER, a static instance of this
 * class is created.  Therefore, it gets created before main ()
 * is called.  And it gets destroyed after main () returns.
 */
class ACE_Export ACE_Object_Manager_Manager
{
public:
  ACE_Object_Manager_Manager (void);
  ~ACE_Object_Manager_Manager (void);
private:
  /// Save the main thread ID, so that destruction can be suppressed.
  ACE_thread_t saved_main_thread_id_;
};
ACE_Object_Manager_Manager::ACE_Object_Manager_Manager (void)
  : saved_main_thread_id_ (ACE_OS::thr_self ())
{
  // Ensure that the Object_Manager gets initialized before any
  // application threads have been spawned.  Because this will be called
  // during construction of static objects, that should always be the
  // case.
  (void) ACE_Object_Manager::instance ();
}
ACE_Object_Manager_Manager::~ACE_Object_Manager_Manager (void)
{
  if (ACE_OS::thr_equal (ACE_OS::thr_self (),
                         saved_main_thread_id_))
    {
      delete ACE_Object_Manager::instance_;
      ACE_Object_Manager::instance_ = 0;
    }
  // else if this destructor is not called by the main thread, then do
  // not delete the ACE_Object_Manager.  That causes problems, on
  // WIN32 at least.
}
static ACE_Object_Manager_Manager ACE_Object_Manager_Manager_instance;
#endif /* ! ACE_HAS_NONSTATIC_OBJECT_MANAGER */
#if defined (ACE_HAS_THREADS)
// hack to get around errors while compiling using split-cpp
#if !defined (ACE_IS_SPLITTING)
// This is global so that it doesn't have to be declared in the header
// file.  That would cause nasty circular include problems.
typedef ACE_Cleanup_Adapter<ACE_Recursive_Thread_Mutex> ACE_Static_Object_Lock_Type;
static ACE_Static_Object_Lock_Type *ACE_Static_Object_Lock_lock = 0;
#endif /* ! ACE_IS_SPLITTING */
// ACE_SHOULD_MALLOC_STATIC_OBJECT_LOCK isn't (currently) used by ACE.
// But, applications may find it useful for avoiding recursive calls
// if they have overridden operator new.  Thanks to Jody Hagins
// <jody@atdesk.com> for contributing it.
ACE_Recursive_Thread_Mutex *
ACE_Static_Object_Lock::instance (void)
{
  if (ACE_Object_Manager::starting_up ()  ||
      ACE_Object_Manager::shutting_down ())
    {
      // The preallocated ACE_STATIC_OBJECT_LOCK has not been
      // constructed yet.  Therefore, the program is single-threaded
      // at this point.  Or, the ACE_Object_Manager instance has been
      // destroyed, so the preallocated lock is not available.
      // Allocate a lock to use, for interface compatibility, though
      // there should be no contention on it.
      if (ACE_Static_Object_Lock_lock == 0)
        {
#     if defined (ACE_SHOULD_MALLOC_STATIC_OBJECT_LOCK)
        // Allocate a buffer with malloc, and then use placement
        // new for the object, on the malloc'd buffer.
        void *buffer =
          ACE_OS::malloc (sizeof (*ACE_Static_Object_Lock_lock));
        if (buffer == 0)
          {
            return 0;
          }
        // do not use ACE_NEW macros for placement new
        ACE_Static_Object_Lock_lock = new (buffer)
                        ACE_Static_Object_Lock_Type ();
#       else   /* ! ACE_SHOULD_MALLOC_STATIC_OBJECT_LOCK */
        ACE_NEW_RETURN (ACE_Static_Object_Lock_lock,
                        ACE_Cleanup_Adapter<ACE_Recursive_Thread_Mutex>,
                        0);
#       endif /* ! ACE_SHOULD_MALLOC_STATIC_OBJECT_LOCK */
        }
      // Can't register with the ACE_Object_Manager here!  The lock's
      // declaration is visible to the ACE_Object_Manager destructor,
      // so it will clean it up as a special case.
      return &ACE_Static_Object_Lock_lock->object ();
    }
  else
    // Return the preallocated ACE_STATIC_OBJECT_LOCK.
    return
      ACE_Managed_Object<ACE_Recursive_Thread_Mutex>::get_preallocated_object
        (ACE_Object_Manager::ACE_STATIC_OBJECT_LOCK);
}
void
ACE_Static_Object_Lock::cleanup_lock (void)
{
# if defined(ACE_SHOULD_MALLOC_STATIC_OBJECT_LOCK)
    // It was malloc'd, so we need to explicitly call the dtor
    // and then free the memory.
    ACE_DES_FREE (ACE_Static_Object_Lock_lock,
                  ACE_OS::free,
                  ACE_Static_Object_Lock_Type);
# else  /* ! ACE_SHOULD_MALLOC_STATIC_OBJECT_LOCK */
    delete ACE_Static_Object_Lock_lock;
# endif /* ! ACE_SHOULD_MALLOC_STATIC_OBJECT_LOCK */
    ACE_Static_Object_Lock_lock = 0;
}
#endif /* ACE_HAS_THREADS */
ACE_END_VERSIONED_NAMESPACE_DECL

