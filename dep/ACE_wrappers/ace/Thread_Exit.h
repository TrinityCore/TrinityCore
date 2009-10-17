// -*- C++ -*-
//=============================================================================
/**
 *  @file    Thread_Exit.h
 *
 *  $Id: Thread_Exit.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Carlos O'Ryan <coryan@uci.edu>
 */
//=============================================================================

#ifndef ACE_THREAD_EXIT_H
#define ACE_THREAD_EXIT_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Thread_Control.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Thread_Exit
 *
 * @brief Keep exit information for a Thread in thread specific storage.
 * so that the thread-specific exit hooks will get called no
 * matter how the thread exits (e.g., via <ACE_Thread::exit>, C++
 * or Win32 exception, "falling off the end" of the thread entry
 * point function, etc.).
 *
 * This clever little helper class is stored in thread-specific
 * storage using the <ACE_TSS> wrapper.  When a thread exits the
 * <ACE_TSS::cleanup> function deletes this object, thereby
 * closing it down gracefully.
 */
class ACE_Export ACE_Thread_Exit
{
public:
  /// Capture the Thread that will be cleaned up automatically.
  ACE_Thread_Exit (void);
  /// Set the ACE_Thread_Manager.
  void thr_mgr (ACE_Thread_Manager *tm);
  /// Destructor calls the thread-specific exit hooks when a thread
  /// exits.
  ~ACE_Thread_Exit (void);
  /// Singleton access point.
  static ACE_Thread_Exit *instance (void);
  /// Cleanup method, used by the ACE_Object_Manager to destroy the
  /// singleton.
  static void cleanup (void *instance);
private:
  /// Automatically add/remove the thread from the
  /// ACE_Thread_Manager.
  ACE_Thread_Control thread_control_;
  /**
   * Used to detect whether we should create a new instance (or not)
   * within the instance method -- we don't trust the instance_ ptr
   * because the destructor may have run (if ACE::fini() was called).
   * See bug #526.
   * We don't follow the singleton pattern due to dependency issues.
   */
  static bool is_constructed_;
};
/**
 * @class ACE_Thread_Exit_Maybe
 *
 * @brief A version of ACE_Thread_Exit that is created dynamically
 * under the hood if the flag is set to TRUE.
 *
 * Allows the appearance of a "smart pointer", but is not
 * always created.
 */
class ACE_Export ACE_Thread_Exit_Maybe
{
public:
  /// Don't create an ACE_Thread_Exit instance by default.
  ACE_Thread_Exit_Maybe (int flag = 0);
  /// Destroys the underlying ACE_Thread_Exit instance if it exists.
  ~ACE_Thread_Exit_Maybe (void);
  /// Delegates to underlying instance.
  ACE_Thread_Exit * operator -> (void) const;
  /// Returns the underlying instance.
  ACE_Thread_Exit * instance (void) const;
private:
  /// Holds the underlying instance.
  ACE_Thread_Exit *instance_;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#include /**/ "ace/post.h"
#endif /* ACE_THREAD_EXIT_H */

