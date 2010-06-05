// -*- C++ -*-

//==========================================================================
/**
 *  @file    RW_Mutex.h
 *
 *  $Id: RW_Mutex.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_RW_MUTEX_H
#define ACE_RW_MUTEX_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// ACE platform supports some form of threading.
#if defined (ACE_HAS_THREADS)

#include "ace/OS_NS_Thread.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_RW_Mutex
 *
 * @brief Wrapper for readers/writer locks.
 *
 * These are most useful for applications that have many more
 * parallel readers than writers...
 */
class ACE_Export ACE_RW_Mutex
{
public:
  /// Initialize a readers/writer lock.
  ACE_RW_Mutex (int type = USYNC_THREAD,
                const ACE_TCHAR *name = 0,
                void *arg = 0);

  /// Implicitly destroy a readers/writer lock
  ~ACE_RW_Mutex (void);

  /**
   * Explicitly destroy a readers/writer lock.  Note that only one
   * thread should call this method since it doesn't protect against
   * race conditions.
   */
  int remove (void);

  /// Acquire a read lock, but block if a writer hold the lock.
  int acquire_read (void);

  /// Acquire a write lock, but block if any readers or a
  /// writer hold the lock.
  int acquire_write (void);

  /**
   * Conditionally acquire a read lock (i.e., won't block).  Returns
   * -1 on failure.  If we "failed" because someone else already had
   * the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire_read (void);

  /// Conditionally acquire a write lock (i.e., won't block).
  int tryacquire_write (void);

  /**
   * Conditionally upgrade a read lock to a write lock.  This only
   * works if there are no other readers present, in which case the
   * method returns 0.  Otherwise, the method returns -1 and sets
   * @c errno to @c EBUSY.  Note that the caller of this method *must*
   * already possess this lock as a read lock (but this condition is
   * not checked by the current implementation).
   */
  int tryacquire_write_upgrade (void);

  /**
   * Note, for interface uniformity with other synchronization
   * wrappers we include the <acquire> method.  This is implemented as
   * a write-lock to safe...
   */
  int acquire (void);

  /**
   * Note, for interface uniformity with other synchronization
   * wrappers we include the <tryacquire> method.  This is implemented
   * as a write-lock to be safe...  Returns -1 on failure.  If we
   * "failed" because someone else already had the lock, @c errno is
   * set to @c EBUSY.
   */
  int tryacquire (void);

  /// Unlock a readers/writer lock.
  int release (void);

  /// Return the underlying lock.
  const ACE_rwlock_t &lock (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Readers/writer lock.
  ACE_rwlock_t lock_;

  /// Keeps track of whether <remove> has been called yet to avoid
  /// multiple <remove> calls, e.g., explicitly and implicitly in the
  /// destructor.  This flag isn't protected by a lock, so make sure
  /// that you don't have multiple threads simultaneously calling
  /// <remove> on the same object, which is a bad idea anyway...
  int removed_;

private:
  // = Prevent assignment and initialization.
  void operator= (const ACE_RW_Mutex &);
  ACE_RW_Mutex (const ACE_RW_Mutex &);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/RW_Mutex.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_THREADS */

#include /**/ "ace/post.h"

#endif /* ACE_RW_MUTEX_H */

