// -*- C++ -*-
//==========================================================================
/**
 *  @file    Semaphore.h
 *
 *  $Id: Semaphore.h 81014 2008-03-19 11:41:31Z johnnyw $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================
#ifndef ACE_SEMAPHORE_H
#define ACE_SEMAPHORE_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/OS_NS_Thread.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Time_Value;
/**
 * @class ACE_Semaphore
 *
 * @brief Wrapper for Dijkstra style general semaphores.
 */
class ACE_Export ACE_Semaphore
{
public:
  // = Initialization and termination.
  /// Initialize the semaphore, with initial value of "count".
  ACE_Semaphore (unsigned int count = 1, // By default make this unlocked.
                 int type = USYNC_THREAD,
                 const ACE_TCHAR *name = 0,
                 void * = 0,
                 int max = 0x7fffffff);
  /// Implicitly destroy the semaphore.
  ~ACE_Semaphore (void);
  /**
   * Explicitly destroy the semaphore.  Note that only one thread
   * should call this method since it doesn't protect against race
   * conditions.
   */
  int remove (void);
  /// Block the thread until the semaphore count becomes
  /// greater than 0, then decrement it.
  int acquire (void);
  /**
   * Block the thread until the semaphore count becomes greater than 0
   * (at which point it is decremented) or until @a tv times out (in
   * which case -1 is returned and @c errno == @c ETIME).  Note that @a tv
   * is assumed to be in "absolute" rather than "relative" time.  The
   * value of @a tv is updated upon return to show the actual
   * (absolute) acquisition time.
   *
   * @note Solaris threads do not support timed semaphores.
   * Therefore, if you're running on Solaris you might want to
   * consider using the ACE POSIX pthreads implementation instead,
   * which can be enabled by compiling ACE with
   * -DACE_HAS_PTHREADS, rather than -DACE_HAS_STHREADS or
   * -DACE_HAS_POSIX_SEM.
   */
  int acquire (ACE_Time_Value &tv);
  /**
   * If @a tv == 0 then call <acquire()> directly.  Otherwise, Block
   * the thread until the semaphore count becomes greater than 0
   * (at which point it is decremented) or until @a tv times out (in
   * which case -1 is returned and @c errno == @c ETIME).  Note that
   * <*tv> is assumed to be in "absolute" rather than "relative" time.
   * The value of <*tv> is updated upon return to show the actual
   * (absolute) acquisition time.
   *
   * @note Solaris threads do not support timed semaphores.
   * Therefore, if you're running on Solaris you might want to
   * consider using the ACE POSIX pthreads implementation instead,
   * which can be enabled by compiling ACE with
   * -DACE_HAS_PTHREADS, rather than -DACE_HAS_STHREADS or
   * -DACE_HAS_POSIX_SEM.  */
  int acquire (ACE_Time_Value *tv);
  /**
   * Conditionally decrement the semaphore if count is greater than 0
   * (i.e., won't block).  Returns -1 on failure.  If we "failed"
   * because someone else already had the lock, @c errno is set to
   * @c EBUSY.
   */
  int tryacquire (void);
  /// Increment the semaphore by 1, potentially unblocking a waiting
  /// thread.
  int release (void);
  /// Increment the semaphore by @a release_count, potentially
  /// unblocking waiting threads.
  int release (unsigned int release_count);
  /**
   * Acquire semaphore ownership.  This calls <acquire> and is only
   * here to make the ACE_Semaphore interface consistent with the
   * other synchronization APIs.
   */
  int acquire_read (void);
  /**
   * Acquire semaphore ownership.  This calls <acquire> and is only
   * here to make the ACE_Semaphore interface consistent with the
   * other synchronization APIs.
   */
  int acquire_write (void);
  /**
   * Conditionally acquire semaphore (i.e., won't block).  This calls
   * <tryacquire> and is only here to make the ACE_Semaphore
   * interface consistent with the other synchronization APIs.
   * Returns -1 on failure.  If we "failed" because someone else
   * already had the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire_read (void);
  /**
   * Conditionally acquire semaphore (i.e., won't block).  This calls
   * <tryacquire> and is only here to make the ACE_Semaphore
   * interface consistent with the other synchronization APIs.
   * Returns -1 on failure.  If we "failed" because someone else
   * already had the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire_write (void);
  /**
   * This is only here to make the ACE_Semaphore
   * interface consistent with the other synchronization APIs.
   * Assumes the caller has already acquired the semaphore using one of
   * the above calls, and returns 0 (success) always.
   */
  int tryacquire_write_upgrade (void);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
  /// Return the underlying lock.
  const ACE_sema_t &lock (void) const;
protected:
  ACE_sema_t semaphore_;
  /// Keeps track of whether remove() has been called yet to avoid
  /// multiple remove() calls, e.g., explicitly and implicitly in the
  /// destructor.  This flag isn't protected by a lock, so make sure
  /// that you don't have multiple threads simultaneously calling
  /// remove () on the same object, which is a bad idea anyway...
  bool removed_;
private:
  // = Prevent assignment and initialization.
  void operator= (const ACE_Semaphore &);
  ACE_Semaphore (const ACE_Semaphore &);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Semaphore.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_SEMAPHORE_H */

