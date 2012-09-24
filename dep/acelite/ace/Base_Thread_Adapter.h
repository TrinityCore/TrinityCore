// -*- C++ -*-

//=============================================================================
/**
 *  @file    Base_Thread_Adapter.h
 *
 *  $Id: Base_Thread_Adapter.h 95595 2012-03-07 13:33:25Z johnnyw $
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_BASE_THREAD_ADAPTER_H
#define ACE_BASE_THREAD_ADAPTER_H
#include /**/ "ace/pre.h"

#include "ace/OS_Log_Msg_Attributes.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "ace/ACE_export.h"
#include "ace/OS_Log_Msg_Attributes.h"

#ifdef ACE_USES_GPROF
#include "os_include/sys/os_time.h"
#endif // ACE_USES_GPROF

#if (defined (ACE_HAS_VERSIONED_NAMESPACE) && ACE_HAS_VERSIONED_NAMESPACE == 1)
# define ACE_THREAD_ADAPTER_NAME ACE_PREPROC_CONCATENATE(ACE_VERSIONED_NAMESPACE_NAME, _ace_thread_adapter)
#else
# define ACE_THREAD_ADAPTER_NAME ace_thread_adapter
#endif  /* ACE_HAS_VERSIONED_NAMESPACE == 1 */

/// Run the thread entry point for the ACE_Thread_Adapter.  This must
/// be an extern "C" to make certain compilers happy...
extern "C" ACE_Export ACE_THR_FUNC_RETURN ACE_THREAD_ADAPTER_NAME (void *args);

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_OS_Thread_Descriptor
 *
 * @brief Parent class of all ACE_Thread_Descriptor classes.
 *
 * Container for ACE_Thread_Descriptor members that are
 * used in ACE_OS.
 */
class ACE_Export ACE_OS_Thread_Descriptor
{
public:
  /// Get the thread creation flags.
  long flags (void) const;

  virtual ~ACE_OS_Thread_Descriptor (void);

protected:
  /// For use by ACE_Thread_Descriptor.
  ACE_OS_Thread_Descriptor (long flags = 0);

  /**
   * Keeps track of whether this thread was created "detached" or not.
   * If a thread is *not* created detached then if someone calls
   * ACE_Thread_Manager::wait(), we need to join with that thread (and
   * close down the handle).
   */
  long flags_;
};

class ACE_Service_Gestalt;

/**
 * @class ACE_Base_Thread_Adapter
 *
 * @brief Base class for all the Thread_Adapters.
 *
 * Converts a C++ function into a function that can be
 * called from a thread creation routine
 * (e.g., pthread_create() or _beginthreadex()) that expects an
 * extern "C" entry point.  This class also makes it possible to
 * transparently provide hooks to register a thread with an
 * ACE_Thread_Manager.
 * This class is used in ACE_OS::thr_create().  In general, the
 * thread that creates an object of this class is different from
 * the thread that calls @c invoke() on this object.  Therefore,
 * the @c invoke() method is responsible for deleting itself.
 */
class ACE_Export ACE_Base_Thread_Adapter
{
public:

  virtual ~ACE_Base_Thread_Adapter (void);

  /// Virtual method invoked by the thread entry point.
  virtual ACE_THR_FUNC_RETURN invoke (void) = 0;

  /// Accessor for the C entry point function to the OS thread creation
  /// routine.
  ACE_THR_C_FUNC entry_point (void);

#ifdef ACE_USES_GPROF
  /// Accessor to the itimer_
  /// followed http://sam.zoy.org/writings/programming/gprof.html
  struct itimerval* timerval (void);
#endif // ACE_USES_PROF

  /// Invoke the close_log_msg_hook, if it is present
  static void close_log_msg (void);

  /// Invoke the sync_log_msg_hook, if it is present
  static void sync_log_msg (const ACE_TCHAR *prog_name);

  /// Invoke the thr_desc_log_msg_hook, if it is present
  static ACE_OS_Thread_Descriptor *thr_desc_log_msg (void);

protected:
  /// Constructor.
  ACE_Base_Thread_Adapter (ACE_THR_FUNC user_func,
                           void *arg,
                           ACE_THR_C_FUNC entry_point = (ACE_THR_C_FUNC) ACE_THREAD_ADAPTER_NAME,
                           ACE_OS_Thread_Descriptor *td = 0
# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
                           , ACE_SEH_EXCEPT_HANDLER selector = 0
                           , ACE_SEH_EXCEPT_HANDLER handler = 0
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
                           , long cancel_flags = 0
                      );
  /// Inherit the logging features if the parent thread has an
  /// ACE_Log_Msg.
  void inherit_log_msg (void);

private:
  /// The hooks to inherit and cleanup the Log_Msg attributes
  static ACE_INIT_LOG_MSG_HOOK init_log_msg_hook_;
  static ACE_INHERIT_LOG_MSG_HOOK inherit_log_msg_hook_;
  static ACE_CLOSE_LOG_MSG_HOOK close_log_msg_hook_;
  static ACE_SYNC_LOG_MSG_HOOK sync_log_msg_hook_;
  static ACE_THR_DESC_LOG_MSG_HOOK thr_desc_log_msg_hook_;

  /// Set the Log_Msg hooks
  static void set_log_msg_hooks (ACE_INIT_LOG_MSG_HOOK init_hook,
                                 ACE_INHERIT_LOG_MSG_HOOK inherit_hook,
                                 ACE_CLOSE_LOG_MSG_HOOK close_hook,
                                 ACE_SYNC_LOG_MSG_HOOK sync_hook,
                                 ACE_THR_DESC_LOG_MSG_HOOK thr_desc);

  /// Allow the ACE_Log_Msg class to set its hooks.
  friend class ACE_Log_Msg;

protected:
  /// Thread startup function passed in by the user (C++ linkage).
  ACE_THR_FUNC user_func_;

  /// Argument to thread startup function.
  void *arg_;

  /// Entry point to the underlying OS thread creation call (C
  /// linkage).
  ACE_THR_C_FUNC entry_point_;

  /**
   * Optional thread descriptor.  Passing this pointer in will force
   * the spawned thread to cache this location in Log_Msg and wait
   * until Thread_Manager fills in all information in thread
   * descriptor.
   */
  ACE_OS_Thread_Descriptor *thr_desc_;

  /// The ACE_Log_Msg attributes.
  ACE_OS_Log_Msg_Attributes log_msg_attributes_;

  /// That is useful for gprof, define itimerval
#ifdef ACE_USES_GPROF
  struct itimerval itimer_;
#endif // ACE_USES_GPROF

  /// Keep a reference to the configuration context that spawns the
  /// thread so the child can inherit it.
  ACE_Service_Gestalt * const ctx_;

  /// Pass through the thread-creation flags that can only be acted on by
  /// the spawned thread. Currently this is only the cancellation-related
  /// flags.
  long flags_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/Base_Thread_Adapter.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

#include /**/ "ace/post.h"
#endif /* ACE_BASE_THREAD_ADAPTER_H */
