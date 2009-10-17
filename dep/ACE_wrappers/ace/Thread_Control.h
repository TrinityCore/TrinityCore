// -*- C++ -*-

//=============================================================================
/**
 *  @file    Thread_Control.h
 *
 *  $Id: Thread_Control.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Carlos O'Ryan <coryan@uci.edu>
 */
//=============================================================================

#ifndef ACE_THREAD_CONTROL_H
#define ACE_THREAD_CONTROL_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Thread_Manager;

/**
 * @class ACE_Thread_Control
 *
 * @brief Used to keep track of a thread's activities within its entry
 * point function.
 *
 * A ACE_Thread_Manager uses this class to ensure that threads
 * it spawns automatically register and unregister themselves
 * with it.
 * This class can be stored in thread-specific storage using the
 * ACE_TSS wrapper.  When a thread exits the
 * <ACE_TSS::cleanup> function deletes this object, thereby
 * ensuring that it gets removed from its associated
 * ACE_Thread_Manager.
 */
class ACE_Export ACE_Thread_Control
{
public:
  /// Initialize the thread control object.  If @a insert != 0, then
  /// register the thread with the Thread_Manager.
  ACE_Thread_Control (ACE_Thread_Manager *tm = 0,
                      int insert = 0);

  /// Remove the thread from its associated <Thread_Manager> and exit
  /// the thread if <do_thr_exit> is enabled.
  ~ACE_Thread_Control (void);

  /// Remove this thread from its associated ACE_Thread_Manager and exit
  /// the thread if @a do_thr_exit is enabled.
  ACE_THR_FUNC_RETURN exit (ACE_THR_FUNC_RETURN status,
                            int do_thr_exit);

  /// Store the <Thread_Manager> and use it to register ourselves for
  /// correct shutdown.
  int insert (ACE_Thread_Manager *tm, int insert = 0);

  /// Returns the current <Thread_Manager>.
  ACE_Thread_Manager *thr_mgr (void);

  /// Atomically set a new <Thread_Manager> and return the old
  /// <Thread_Manager>.
  ACE_Thread_Manager *thr_mgr (ACE_Thread_Manager *);

  /// Set the exit status (and return existing status).
  ACE_THR_FUNC_RETURN status (ACE_THR_FUNC_RETURN status);

  /// Get the current exit status.
  ACE_THR_FUNC_RETURN status (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Pointer to the thread manager for this block of code.
  ACE_Thread_Manager *tm_;

  /// Keeps track of the exit status for the thread.
  ACE_THR_FUNC_RETURN status_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/Thread_Control.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

#include /**/ "ace/post.h"
#endif /* ACE_THREAD_CONTROL_H */

