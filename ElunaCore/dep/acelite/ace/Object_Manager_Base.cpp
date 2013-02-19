// $Id: Object_Manager_Base.cpp 92580 2010-11-15 09:48:02Z johnnyw $

#include "ace/Object_Manager_Base.h"
#include "ace/OS_Memory.h"
#include "ace/OS_NS_Thread.h"
#include "ace/OS_NS_sys_socket.h"
#include "ace/OS_NS_signal.h"
#include "ace/OS_NS_stdio.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
int ACE_SEH_Default_Exception_Selector (void *)
{
  // this is only windows and only used here,
  // defined in ace/config-win32-common.h.
  return (DWORD) ACE_SEH_DEFAULT_EXCEPTION_HANDLING_ACTION;
}

int ACE_SEH_Default_Exception_Handler (void *)
{
  return 0;
}
#endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */

# define ACE_OS_PREALLOCATE_OBJECT(TYPE, ID)\
    {\
      TYPE *obj_p = 0;\
      ACE_NEW_RETURN (obj_p, TYPE, -1);\
      preallocated_object[ID] = (void *) obj_p;\
    }
# define ACE_OS_DELETE_PREALLOCATED_OBJECT(TYPE, ID)\
    delete (TYPE *) preallocated_object[ID];\
    preallocated_object[ID] = 0;

ACE_Object_Manager_Base::ACE_Object_Manager_Base (void)
  : object_manager_state_ (OBJ_MAN_UNINITIALIZED)
  , dynamically_allocated_ (false)
  , next_ (0)
{
}

ACE_Object_Manager_Base::~ACE_Object_Manager_Base (void)
{
#if defined (ACE_HAS_NONSTATIC_OBJECT_MANAGER)
  // Clear the flag so that fini () doesn't delete again.
  dynamically_allocated_ = false;
#endif /* ACE_HAS_NONSTATIC_OBJECT_MANAGER */
}

int
ACE_Object_Manager_Base::starting_up_i ()
{
  return object_manager_state_ < OBJ_MAN_INITIALIZED;
}

int
ACE_Object_Manager_Base::shutting_down_i ()
{
  return object_manager_state_ > OBJ_MAN_INITIALIZED;
}

/*****************************************************************************/

extern "C"
void
ACE_OS_Object_Manager_Internal_Exit_Hook (void)
{
  if (ACE_OS_Object_Manager::instance_)
    ACE_OS_Object_Manager::instance ()->fini ();
}

ACE_OS_Object_Manager *ACE_OS_Object_Manager::instance_ = 0;

void *ACE_OS_Object_Manager::preallocated_object[
  ACE_OS_Object_Manager::ACE_OS_PREALLOCATED_OBJECTS] = { 0 };

ACE_OS_Object_Manager::ACE_OS_Object_Manager (void)
  : default_mask_ (0)
  , thread_hook_ (0)
  , exit_info_ ()
#if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
  , seh_except_selector_ (ACE_SEH_Default_Exception_Selector)
  , seh_except_handler_ (ACE_SEH_Default_Exception_Handler)
#endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
{
  // If instance_ was not 0, then another ACE_OS_Object_Manager has
  // already been instantiated (it is likely to be one initialized by
  // way of library/DLL loading).  Let this one go through
  // construction in case there really is a good reason for it (like,
  // ACE is a static/archive library, and this one is the non-static
  // instance (with ACE_HAS_NONSTATIC_OBJECT_MANAGER, or the user has
  // a good reason for creating a separate one) but the original one
  // will be the one retrieved from calls to
  // ACE_Object_Manager::instance().

  // Be sure that no further instances are created via instance ().
  if (instance_ == 0)
    instance_ = this;

  init ();
}

ACE_OS_Object_Manager::~ACE_OS_Object_Manager (void)
{
  dynamically_allocated_ = false;   // Don't delete this again in fini()
  fini ();
}

sigset_t *
ACE_OS_Object_Manager::default_mask (void)
{
  return ACE_OS_Object_Manager::instance ()->default_mask_;
}

ACE_Thread_Hook *
ACE_OS_Object_Manager::thread_hook (void)
{
  return ACE_OS_Object_Manager::instance ()->thread_hook_;
}

#if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
ACE_SEH_EXCEPT_HANDLER
ACE_OS_Object_Manager::seh_except_selector (void)
{
  return ACE_OS_Object_Manager::instance ()->seh_except_selector_;
}

ACE_SEH_EXCEPT_HANDLER
ACE_OS_Object_Manager::seh_except_selector (ACE_SEH_EXCEPT_HANDLER n)
{
  ACE_OS_Object_Manager *instance =
    ACE_OS_Object_Manager::instance ();

  ACE_SEH_EXCEPT_HANDLER retv = instance->seh_except_selector_;
  instance->seh_except_selector_ = n;
  return retv;
}

ACE_SEH_EXCEPT_HANDLER
ACE_OS_Object_Manager::seh_except_handler (void)
{
  return ACE_OS_Object_Manager::instance ()->seh_except_handler_;
}

ACE_SEH_EXCEPT_HANDLER
ACE_OS_Object_Manager::seh_except_handler (ACE_SEH_EXCEPT_HANDLER n)
{
  ACE_OS_Object_Manager *instance =
    ACE_OS_Object_Manager::instance ();

  ACE_SEH_EXCEPT_HANDLER retv = instance->seh_except_handler_;
  instance->seh_except_handler_ = n;
  return retv;
}
#endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */

ACE_Thread_Hook *
ACE_OS_Object_Manager::thread_hook (ACE_Thread_Hook *new_thread_hook)
{
  ACE_OS_Object_Manager *os_om = ACE_OS_Object_Manager::instance ();
  ACE_Thread_Hook *old_hook = os_om->thread_hook_;
  os_om->thread_hook_ = new_thread_hook;
  return old_hook;
}

ACE_OS_Object_Manager *
ACE_OS_Object_Manager::instance (void)
{
  // This function should be called during construction of static
  // instances, or before any other threads have been created in the
  // process.  So, it's not thread safe.

  if (instance_ == 0)
    {
      ACE_OS_Object_Manager *instance_pointer = 0;

      ACE_NEW_RETURN (instance_pointer,
                      ACE_OS_Object_Manager,
                      0);
      // I (coryan) removed it, using asserts in the OS layer
      // brings down the Log msg stuff
      // ACE_ASSERT (instance_pointer == instance_);

      instance_pointer->dynamically_allocated_ = true;

    }

  return instance_;
}

int
ACE_OS_Object_Manager::init (void)
{
  if (starting_up_i ())
    {
      // First, indicate that this ACE_OS_Object_Manager instance is being
      // initialized.
      object_manager_state_ = OBJ_MAN_INITIALIZING;

      if (this == instance_)
        {
# if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
#   if defined (ACE_HAS_WINCE_BROKEN_ERRNO)
          ACE_CE_Errno::init ();
#   endif /* ACE_HAS_WINCE_BROKEN_ERRNO */
          ACE_OS_PREALLOCATE_OBJECT (ACE_thread_mutex_t, ACE_OS_MONITOR_LOCK)
          if (ACE_OS::thread_mutex_init
              // This line must not be broken to avoid tickling a bug with SunC++'s preprocessor.
              (reinterpret_cast <ACE_thread_mutex_t *> (ACE_OS_Object_Manager::preallocated_object[ACE_OS_MONITOR_LOCK])) != 0)
            ACE_OS_Object_Manager::print_error_message (
              __LINE__, ACE_TEXT ("ACE_OS_MONITOR_LOCK"));
          ACE_OS_PREALLOCATE_OBJECT (ACE_recursive_thread_mutex_t,
                                     ACE_TSS_CLEANUP_LOCK)
          if (ACE_OS::recursive_mutex_init
              // This line must not be broken to avoid tickling a bug with SunC++'s preprocessor.
              (reinterpret_cast <ACE_recursive_thread_mutex_t *> (ACE_OS_Object_Manager::preallocated_object[ACE_TSS_CLEANUP_LOCK])) != 0)
            ACE_OS_Object_Manager::print_error_message (
              __LINE__, ACE_TEXT ("ACE_TSS_CLEANUP_LOCK"));
          ACE_OS_PREALLOCATE_OBJECT (ACE_thread_mutex_t,
                                     ACE_LOG_MSG_INSTANCE_LOCK)
          if (ACE_OS::thread_mutex_init
              // This line must not be broken to avoid tickling a bug with SunC++'s preprocessor.
              (reinterpret_cast <ACE_thread_mutex_t *> (ACE_OS_Object_Manager::preallocated_object[ACE_LOG_MSG_INSTANCE_LOCK])) != 0)
            ACE_OS_Object_Manager::print_error_message (
              __LINE__, ACE_TEXT ("ACE_LOG_MSG_INSTANCE_LOCK"));
#   if defined (ACE_HAS_TSS_EMULATION)
          ACE_OS_PREALLOCATE_OBJECT (ACE_recursive_thread_mutex_t,
                                     ACE_TSS_KEY_LOCK)
          if (ACE_OS::recursive_mutex_init
              // This line must not be broken to avoid tickling a bug with SunC++'s preprocessor.
              (reinterpret_cast <ACE_recursive_thread_mutex_t *> (ACE_OS_Object_Manager::preallocated_object[ACE_TSS_KEY_LOCK])) != 0)
            ACE_OS_Object_Manager::print_error_message (
              __LINE__, ACE_TEXT ("ACE_TSS_KEY_LOCK"));
#     if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)
          ACE_OS_PREALLOCATE_OBJECT (ACE_recursive_thread_mutex_t,
                                     ACE_TSS_BASE_LOCK)
          if (ACE_OS::recursive_mutex_init
              // This line must not be broken to avoid tickling a bug with SunC++'s preprocessor.
              (reinterpret_cast <ACE_recursive_thread_mutex_t *> (ACE_OS_Object_Manager::preallocated_object[ACE_TSS_BASE_LOCK])) != 0)
            ACE_OS_Object_Manager::print_error_message (
              __LINE__, ACE_TEXT ("ACE_TSS_BASE_LOCK"));
#     endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE */
#   endif /* ACE_HAS_TSS_EMULATION */
# endif /* ACE_MT_SAFE */

          // Open Winsock (no-op on other platforms).
          ACE_OS::socket_init (ACE_WSOCK_VERSION);

          // Register the exit hook, for use by ACE_OS::exit ().
          ACE_OS::set_exit_hook (&ACE_OS_Object_Manager_Internal_Exit_Hook);
        }

      ACE_NEW_RETURN (default_mask_, sigset_t, -1);
      ACE_OS::sigfillset (default_mask_);

      // Finally, indicate that the ACE_OS_Object_Manager instance has
      // been initialized.
      object_manager_state_ = OBJ_MAN_INITIALIZED;

# if defined (ACE_WIN32)
      ACE_OS::win32_versioninfo_.dwOSVersionInfoSize =
        sizeof (ACE_TEXT_OSVERSIONINFO);
      ACE_TEXT_GetVersionEx (&ACE_OS::win32_versioninfo_);
# endif /* ACE_WIN32 */
      return 0;
    } else {
      // Had already initialized.
      return 1;
    }
}

// Clean up an ACE_OS_Object_Manager.  There can be instances of this object
// other than The Instance.  This can happen if a user creates one for some
// reason.  All objects clean up their per-object information and managed
// objects, but only The Instance cleans up the static preallocated objects.
int
ACE_OS_Object_Manager::fini (void)
{
  if (instance_ == 0  ||  shutting_down_i ())
    // Too late.  Or, maybe too early.  Either fini () has already
    // been called, or init () was never called.
    return object_manager_state_ == OBJ_MAN_SHUT_DOWN  ?  1  :  -1;

  // No mutex here.  Only the main thread should destroy the singleton
  // ACE_OS_Object_Manager instance.

  // Indicate that the ACE_OS_Object_Manager instance is being shut
  // down.  This object manager should be the last one to be shut
  // down.
  object_manager_state_ = OBJ_MAN_SHUTTING_DOWN;

  // If another Object_Manager has registered for termination, do it.
  if (next_)
    {
      next_->fini ();
      next_ = 0;  // Protect against recursive calls.
    }

  // Call all registered cleanup hooks, in reverse order of
  // registration.
  exit_info_.call_hooks ();

  // Only clean up preallocated objects when the singleton Instance is being
  // destroyed.
  if (this == instance_)
    {
      // Close down Winsock (no-op on other platforms).
      ACE_OS::socket_fini ();

#if ! defined (ACE_HAS_STATIC_PREALLOCATION)
      // Cleanup the dynamically preallocated objects.
# if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
#   if !defined(ACE_HAS_BROKEN_PREALLOCATED_OBJECTS_AFTER_FORK)
      if (ACE_OS::thread_mutex_destroy
          // This line must not be broken to avoid tickling a bug with SunC++'s preprocessor.
          (reinterpret_cast <ACE_thread_mutex_t *> (ACE_OS_Object_Manager::preallocated_object[ACE_OS_MONITOR_LOCK])) != 0)
        ACE_OS_Object_Manager::print_error_message (
          __LINE__, ACE_TEXT ("ACE_OS_MONITOR_LOCK"));
#   endif /* ! ACE_HAS_BROKEN_PREALLOCATED_OBJECTS_AFTER_FORK */
      ACE_OS_DELETE_PREALLOCATED_OBJECT (ACE_thread_mutex_t,
                                         ACE_OS_MONITOR_LOCK)
#   if !defined(ACE_HAS_BROKEN_PREALLOCATED_OBJECTS_AFTER_FORK)
      if (ACE_OS::recursive_mutex_destroy
          // This line must not be broken to avoid tickling a bug with SunC++'s preprocessor.
          (reinterpret_cast <ACE_recursive_thread_mutex_t *> (ACE_OS_Object_Manager::preallocated_object[ACE_TSS_CLEANUP_LOCK])) != 0)
        ACE_OS_Object_Manager::print_error_message (
          __LINE__, ACE_TEXT ("ACE_TSS_CLEANUP_LOCK"));
#   endif /* ! ACE_HAS_BROKEN_PREALLOCATED_OBJECTS_AFTER_FORK */
      ACE_OS_DELETE_PREALLOCATED_OBJECT (ACE_recursive_thread_mutex_t,
                                         ACE_TSS_CLEANUP_LOCK)
#   if !defined(ACE_HAS_BROKEN_PREALLOCATED_OBJECTS_AFTER_FORK)
      if (ACE_OS::thread_mutex_destroy
          // This line must not be broken to avoid tickling a bug with SunC++'s preprocessor.
          (reinterpret_cast <ACE_thread_mutex_t *> (ACE_OS_Object_Manager::preallocated_object [ACE_LOG_MSG_INSTANCE_LOCK])) != 0)
        ACE_OS_Object_Manager::print_error_message (
          __LINE__, ACE_TEXT ("ACE_LOG_MSG_INSTANCE_LOCK "));
#   endif /* ! ACE_HAS_BROKEN_PREALLOCATED_OBJECTS_AFTER_FORK */
      ACE_OS_DELETE_PREALLOCATED_OBJECT (ACE_thread_mutex_t,
                                         ACE_LOG_MSG_INSTANCE_LOCK)
#   if defined (ACE_HAS_TSS_EMULATION)
#     if !defined(ACE_HAS_BROKEN_PREALLOCATED_OBJECTS_AFTER_FORK)
        if (ACE_OS::recursive_mutex_destroy
            // This line must not be broken to avoid tickling a bug with SunC++'s preprocessor.
            (reinterpret_cast <ACE_recursive_thread_mutex_t *> (ACE_OS_Object_Manager::preallocated_object[ACE_TSS_KEY_LOCK])) != 0)
          ACE_OS_Object_Manager::print_error_message (
            __LINE__, ACE_TEXT ("ACE_TSS_KEY_LOCK"));
#     endif /* ! ACE_HAS_BROKEN_PREALLOCATED_OBJECTS_AFTER_FORK */
      ACE_OS_DELETE_PREALLOCATED_OBJECT (ACE_recursive_thread_mutex_t,
                                         ACE_TSS_KEY_LOCK)
#     if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)
#       if !defined(ACE_HAS_BROKEN_PREALLOCATED_OBJECTS_AFTER_FORK)
          if (ACE_OS::recursive_mutex_destroy
              // This line must not be broken to avoid tickling a bug with SunC++'s preprocessor.
              (reinterpret_cast <ACE_recursive_thread_mutex_t *> (ACE_OS_Object_Manager::preallocated_object[ACE_TSS_BASE_LOCK])) != 0)
            ACE_OS_Object_Manager::print_error_message (
              __LINE__, ACE_TEXT ("ACE_TSS_BASE_LOCK"));
#       endif /* ! ACE_HAS_BROKEN_PREALLOCATED_OBJECTS_AFTER_FORK */
      ACE_OS_DELETE_PREALLOCATED_OBJECT (ACE_recursive_thread_mutex_t,
                                         ACE_TSS_BASE_LOCK)
#     endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE */
#   endif /* ACE_HAS_TSS_EMULATION */
#   if defined (ACE_HAS_WINCE_BROKEN_ERRNO)
          ACE_CE_Errno::fini ();
#   endif /* ACE_HAS_WINCE_BROKEN_ERRNO */
# endif /* ACE_MT_SAFE */
#endif /* ! ACE_HAS_STATIC_PREALLOCATION */
    }

  delete default_mask_;
  default_mask_ = 0;

  // Indicate that this ACE_OS_Object_Manager instance has been shut down.
  object_manager_state_ = OBJ_MAN_SHUT_DOWN;

  if (dynamically_allocated_)
    {
      delete this;
    }

  if (this == instance_)
    instance_ = 0;

  return 0;
}

int ace_exit_hook_marker = 0;

int
ACE_OS_Object_Manager::at_exit (ACE_EXIT_HOOK func, const char* name)
{
  return exit_info_.at_exit_i (&ace_exit_hook_marker,
                               reinterpret_cast <ACE_CLEANUP_FUNC> (func),
                               0,
                               name);
}

void
ACE_OS_Object_Manager::print_error_message (unsigned int line_number,
                                            const ACE_TCHAR *message)
{
  // To avoid duplication of these const strings in OS.o.
#if !defined (ACE_HAS_WINCE)
  fprintf (stderr, "ace/Object_Manager_Base.cpp, line %u: %s ",
           line_number,
           ACE_TEXT_ALWAYS_CHAR (message));
  perror ("failed");
#else
  // @@ Need to use the following information.
  ACE_UNUSED_ARG (line_number);
  ACE_UNUSED_ARG (message);

  ACE_TCHAR *lpMsgBuf = 0;
  ::FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |
                   FORMAT_MESSAGE_FROM_SYSTEM,
                   0,
                   ::GetLastError (),
                   MAKELANGID (LANG_NEUTRAL,
                               SUBLANG_DEFAULT),
                   // Default language
                   (ACE_TCHAR *) &lpMsgBuf,
                   0,
                   0);
  ::MessageBox (0,
                lpMsgBuf,
                ACE_TEXT ("ACE_OS error"),
                MB_OK);
#endif
}

int
ACE_OS_Object_Manager::starting_up (void)
{
  return ACE_OS_Object_Manager::instance_
    ? instance_->starting_up_i ()
    : 1;
}

int
ACE_OS_Object_Manager::shutting_down (void)
{
  return ACE_OS_Object_Manager::instance_
    ? instance_->shutting_down_i ()
    : 1;
}

/*****************************************************************************/

#if !defined (ACE_HAS_NONSTATIC_OBJECT_MANAGER)
/**
 * @class ACE_OS_Object_Manager_Manager
 *
 * @brief Ensure that the ACE_OS_Object_Manager gets initialized at
 * program startup, and destroyed at program termination.
 *
 * Without ACE_HAS_NONSTATIC_OBJECT_MANAGER, a static instance of this
 * class is created.  Therefore, it gets created before main ()
 * is called.  And it gets destroyed after main () returns.
 */
class ACE_OS_Object_Manager_Manager
{
public:
  /// Constructor.
  ACE_OS_Object_Manager_Manager (void);

  /// Destructor.
  ~ACE_OS_Object_Manager_Manager (void);

private:
  /// Save the main thread ID, so that destruction can be suppressed.
  ACE_thread_t saved_main_thread_id_;
};

ACE_OS_Object_Manager_Manager::ACE_OS_Object_Manager_Manager (void)
  : saved_main_thread_id_ (ACE_OS::thr_self ())
{
  // Ensure that the Object_Manager gets initialized before any
  // application threads have been spawned.  Because this will be called
  // during construction of static objects, that should always be the
  // case.
  (void) ACE_OS_Object_Manager::instance ();
}

ACE_OS_Object_Manager_Manager::~ACE_OS_Object_Manager_Manager (void)
{
  if (ACE_OS::thr_equal (ACE_OS::thr_self (),
                         saved_main_thread_id_))
    {
      delete ACE_OS_Object_Manager::instance_;
      ACE_OS_Object_Manager::instance_ = 0;
    }
  // else if this destructor is not called by the main thread, then do
  // not delete the ACE_OS_Object_Manager.  That causes problems, on
  // WIN32 at least.
}

static ACE_OS_Object_Manager_Manager ACE_OS_Object_Manager_Manager_instance;
#endif /* ! ACE_HAS_NONSTATIC_OBJECT_MANAGER */

ACE_END_VERSIONED_NAMESPACE_DECL
