// -*- C++ -*-
//==========================================================================
/**
 *  @file    Thread_Mutex.h
 *
 *  $Id: Thread_Mutex.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================
#ifndef ACE_THREAD_MUTEX_H
#define ACE_THREAD_MUTEX_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#if !defined (ACE_HAS_THREADS)
#  include "ace/Null_Mutex.h"
#else /* ACE_HAS_THREADS */
// ACE platform supports some form of threading.
#include /**/ "ace/ACE_export.h"
#include "ace/OS_NS_Thread.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Thread_Mutex
 *
 * @brief ACE_Thread_Mutex wrapper (only valid for threads in the same
 * process).
 *
 * This implementation is optimized for locking threads that are
 * in the same process.  It maps to <CRITICAL_SECTION>s on NT
 * and <ACE_mutex_t> with <type> set to <USYNC_THREAD> on UNIX.
 * ACE_Thread_Mutex is recursive on some platforms (like
 * Win32). However, on most platforms (like Solaris) it is not
 * recursive.  To be totally safe and portable, developers
 * should use ACE_Recursive_Thread_Mutex when they need a
 * recursive mutex.
 */
class ACE_Export ACE_Thread_Mutex
{
  friend class ACE_Condition_Thread_Mutex;
public:
  /// Constructor.
  ACE_Thread_Mutex (const ACE_TCHAR *name = 0,
                    ACE_mutexattr_t *attributes = 0);
  /// Implicitly destroy the mutex.
  ~ACE_Thread_Mutex (void);
  /**
   * Explicitly destroy the mutex.  Note that only one thread should
   * call this method since it doesn't protect against race
   * conditions.
   */
  int remove (void);
  /// Acquire lock ownership (wait on queue if necessary).
  int acquire (void);
  /**
   * Block the thread until we acquire the mutex or until @a tv times
   * out, in which case -1 is returned with @c errno == @c ETIME.  Note
   * that @a tv is assumed to be in "absolute" rather than "relative"
   * time.  The value of @a tv is updated upon return to show the
   * actual (absolute) acquisition time.
   */
  int acquire (ACE_Time_Value &tv);
  /**
   * If @a tv == 0 the call <acquire()> directly.  Otherwise, Block the
   * thread until we acquire the mutex or until @a tv times out, in
   * which case -1 is returned with @c errno == @c ETIME.  Note that
   * @a tv is assumed to be in "absolute" rather than "relative" time.
   * The value of @a tv is updated upon return to show the actual
   * (absolute) acquisition time.
   */
  int acquire (ACE_Time_Value *tv);
  /**
   * Conditionally acquire lock (i.e., don't wait on queue).  Returns
   * -1 on failure.  If we "failed" because someone else already had
   * the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire (void);
  /// Release lock and unblock a thread at head of queue.
  int release (void);
  /**
   * Acquire mutex ownership.  This calls acquire() and is only here
   * to make the ACE_Thread_Mutex interface consistent with the
   * other synchronization APIs.
   */
  int acquire_read (void);
  /**
   * Acquire mutex ownership.  This calls acquire() and is only here
   * to make the ACE_Thread_Mutex interface consistent with the
   * other synchronization APIs.
   */
  int acquire_write (void);
  /**
   * Conditionally acquire mutex (i.e., won't block).  This calls
   * tryacquire() and is only here to make the ACE_Thread_Mutex
   * interface consistent with the other synchronization APIs.
   * Returns -1 on failure.  If we "failed" because someone else
   * already had the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire_read (void);
  /**
   * Conditionally acquire mutex (i.e., won't block).  This calls
   * tryacquire() and is only here to make the ACE_Thread_Mutex
   * interface consistent with the other synchronization APIs.
   * Returns -1 on failure.  If we "failed" because someone else
   * already had the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire_write (void);
  /**
   * This is only here to make the ACE_Thread_Mutex
   * interface consistent with the other synchronization APIs.
   * Assumes the caller has already acquired the mutex using one of
   * the above calls, and returns 0 (success) always.
   */
  int tryacquire_write_upgrade (void);
  /// Return the underlying mutex.
  const ACE_thread_mutex_t &lock (void) const;
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
  // protected:
  /// Mutex type that supports single-process locking efficiently.
  ACE_thread_mutex_t lock_;
  /// Keeps track of whether remove() has been called yet to avoid
  /// multiple <remove> calls, e.g., explicitly and implicitly in the
  /// destructor.  This flag isn't protected by a lock, so make sure
  /// that you don't have multiple threads simultaneously calling
  /// <remove> on the same object, which is a bad idea anyway...
  bool removed_;
private:
  // = Prevent assignment and initialization.
  void operator= (const ACE_Thread_Mutex &);
  ACE_Thread_Mutex (const ACE_Thread_Mutex &);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Thread_Mutex.inl"
#endif /* __ACE_INLINE__ */
#endif /* !ACE_HAS_THREADS */
#include /**/ "ace/post.h"
#endif /* ACE_THREAD_MUTEX_H */

