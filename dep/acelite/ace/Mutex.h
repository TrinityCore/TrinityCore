// -*- C++ -*-

//==========================================================================
/**
 *  @file    Mutex.h
 *
 *  $Id: Mutex.h 91626 2010-09-07 10:59:20Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_MUTEX_H
#define ACE_MUTEX_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/OS_NS_Thread.h"
#include "ace/OS_NS_unistd.h"
#include "ace/os_include/os_fcntl.h"

# if !defined (ACE_DEFAULT_MUTEX_A)
#   define ACE_DEFAULT_MUTEX_A "ACE_MUTEX"
# endif /* ACE_DEFAULT_MUTEX_A */

# if defined (ACE_HAS_WCHAR)
#   define ACE_DEFAULT_MUTEX_W ACE_TEXT_WIDE(ACE_DEFAULT_MUTEX_A)
# endif /* ACE_HAS_WCHAR */

# define ACE_DEFAULT_MUTEX ACE_TEXT (ACE_DEFAULT_MUTEX_A)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;

/**
 * @class ACE_Mutex
 *
 * @brief @c ACE_Mutex wrapper (valid in same process or across
 *        processes (depending on @a TYPE flag)).  In general,
 *        however, we recommend using @a ACE_Process_Mutex or @a
 *        ACE_Thread_Mutex rather than @a ACE_Mutex.
 */
class ACE_Export ACE_Mutex
{
public:
  /// Initialize the mutex.
  ACE_Mutex (int type = USYNC_THREAD,
             const ACE_TCHAR *name = 0,
             ACE_mutexattr_t *arg = 0,
             mode_t mode = ACE_DEFAULT_FILE_PERMS);

  /// Implicitly destroy the mutex.
  ~ACE_Mutex (void);

  /// Explicitly destroy the mutex.
  /**
   * @note Only one thread should call this method since it doesn't
   *        protect against race conditions.
   */
  int remove (void);

  /// Acquire lock ownership (wait on queue if necessary).
  int acquire (void);

  /// Block the thread until the mutex is acquired or @a tv times out,
  /// in which case -1 is returned and @c errno == @c ETIME.
  /**
   * @note @a tv is assumed  to be in "absolute" rather than
   * "     relative" time.  The value of @a tv is updated upon return
   *       to show the actual(absolute) acquisition time.
   */
  int acquire (ACE_Time_Value &tv);

  /// Block the thread until the mutex is acquired or @a *tv times
  /// out, in which case -1 is returned and @c errno == @c ETIME.
  /**
   * If @a tv == 0 then call @c acquire() directly.  Otherwise, block
   * the thread until the mutex is acquired or @a tv times out, in
   * which case -1 is returned and @c errno == @c ETIME.
   *
   * @note @a *tv is assumed to be in "absolute" rather than
   *       "relative" time.  The value of @a *tv is updated upon
   *       return to show the actual (absolute) acquisition time.
   */
  int acquire (ACE_Time_Value *tv);

  /// Conditionally acquire lock (i.e., don't wait on queue).
  /**
   * @return -1 on failure.  If we "failed" because someone
   *         else already had the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire (void);

  /// Release lock and unblock a thread at head of queue.
  int release (void);

  /// Acquire mutex ownership.
  /**
   * This calls @c acquire and is only here to make the @c ACE_Mutex
   * interface consistent with the other synchronization APIs.
   */
  int acquire_read (void);

  /// Acquire mutex ownership.
  /**
   * This calls @c acquire and is only here to make the @c ACE_Mutex
   * interface consistent with the other synchronization APIs.
   */
  int acquire_write (void);

  /// Conditionally acquire mutex (i.e., won't block).
  /**
   * This calls @c tryacquire and is only here to make the @c ACE_Mutex
   * interface consistent with the other synchronization APIs.
   *
   * @return -1 on failure.  If we "failed" because someone else
   *         already had the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire_read (void);

  /// Conditionally acquire mutex (i.e., won't block).
  /**
   * This calls @c tryacquire and is only here to make the @c ACE_Mutex
   * interface consistent with the other synchronization APIs.
   *
   * @return -1 on failure.  If we "failed" because someone else
   *         already had the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire_write (void);

  /**
   * This is only here for consistency with the other synchronization
   * APIs and usability with Lock adapters. Assumes the caller already has
   * acquired the mutex and returns 0 in all cases.
   */
  int tryacquire_write_upgrade (void);

  /// Return the underlying mutex.
  const ACE_mutex_t &lock (void) const;
  ACE_mutex_t &lock (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  // = This should be protected but some C++ compilers complain...
public:
#if defined (ACE_HAS_PTHREADS) || defined(ACE_HAS_STHREADS)
  /// This lock resides in shared memory.
  ACE_mutex_t *process_lock_;

  /**
   * Remember the name of the mutex if we created it so we can unlink
   * it when we go away (only the actor that initialized the memory
   * can destroy it).
   */
  const ACE_TCHAR *lockname_;
#endif /* ACE_HAS_PTHREADS */

  /// Mutex type supported by the OS.
  ACE_mutex_t lock_;

  /// Keeps track of whether @c remove has been called yet to avoid
  /// multiple @c remove calls, e.g., explicitly and implicitly in the
  /// destructor.  This flag isn't protected by a lock, so make sure
  /// that you don't have multiple threads simultaneously calling
  /// @c remove on the same object, which is a bad idea anyway.
  bool removed_;

private:
  // Prevent assignment and initialization.
  void operator= (const ACE_Mutex &);
  ACE_Mutex (const ACE_Mutex &);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Mutex.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_MUTEX_H */
