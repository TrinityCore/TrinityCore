// -*- C++ -*-

//==========================================================================
/**
 *  @file    Lock.h
 *
 *  $Id: Lock.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_LOCK_H
#define ACE_LOCK_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Lock
 *
 * @brief This is the abstract base class that contains the uniform
 * locking API that is supported by all the ACE synchronization
 * mechanisms.
 *
 * This class is typically used in conjunction with the
 * ACE_Lock_Adapter in order to provide a polymorphic
 * interface to the ACE synchronization mechanisms (e.g.,
 * ACE_Mutex, ACE_Semaphore, ACE_RW_Mutex, etc).  Note that
 * the reason that all of ACE doesn't use polymorphic locks is
 * that (1) they add ~20% extra overhead for virtual function
 * calls and (2) objects with virtual functions can't be placed
 * into shared memory.
 */
class ACE_Export ACE_Lock
{
public:
  /// CE needs a default ctor here.
  ACE_Lock (void);

  /// Noop virtual destructor
  virtual ~ACE_Lock (void);

  /**
   * Explicitly destroy the lock.  Note that only one thread should
   * call this method since it doesn't protect against race
   * conditions.
   */
  virtual int remove (void) = 0;

  /// Block the thread until the lock is acquired.  Returns -1 on
  /// failure.
  virtual int acquire (void) = 0;

  /**
   * Conditionally acquire the lock (i.e., won't block).  Returns -1
   * on failure.  If we "failed" because someone else already had the
   * lock, @c errno is set to @c EBUSY.
   */
  virtual int tryacquire (void) = 0;

  /// Release the lock.  Returns -1 on failure.
  virtual int release (void) = 0;

  /**
   * Block until the thread acquires a read lock.  If the locking
   * mechanism doesn't support read locks then this just calls
   * <acquire>.  Returns -1 on failure.
   */
  virtual int acquire_read (void) = 0;

  /**
   * Block until the thread acquires a write lock.  If the locking
   * mechanism doesn't support read locks then this just calls
   * <acquire>.  Returns -1 on failure.
   */
  virtual int acquire_write (void) = 0;

  /**
   * Conditionally acquire a read lock.  If the locking mechanism
   * doesn't support read locks then this just calls <acquire>.
   * Returns -1 on failure.  If we "failed" because someone else
   * already had the lock, @c errno is set to @c EBUSY.
   */
  virtual int tryacquire_read (void) = 0;

  /**
   * Conditionally acquire a write lock.  If the locking mechanism
   * doesn't support read locks then this just calls <acquire>.
   * Returns -1 on failure.  If we "failed" because someone else
   * already had the lock, @c errno is set to @c EBUSY.
   */
  virtual int tryacquire_write (void) = 0;

  /**
   * Conditionally try to upgrade a lock held for read to a write lock.
   * If the locking mechanism doesn't support read locks then this just
   * calls <acquire>. Returns 0 on success, -1 on failure.
   */
  virtual int tryacquire_write_upgrade (void) = 0;
};

/**
 * @class ACE_Adaptive_Lock
 *
 * @brief An adaptive general locking class that defers the decision of
 * lock type to run time.
 *
 * This class, as ACE_Lock, provide a set of general locking APIs.
 * However, it defers our decision of what kind of lock to use
 * to the run time and delegates all locking operations to the actual
 * lock.  Users must define a constructor in their subclass to
 * initialize <lock_>.
 */
class ACE_Export ACE_Adaptive_Lock : public ACE_Lock
{
public:
  /// You must also override the destructor function to match with how
  /// you construct the underneath <lock_>.
  virtual ~ACE_Adaptive_Lock (void);

  // = Lock/unlock operations.

  virtual int remove (void);
  virtual int acquire (void);
  virtual int tryacquire (void);
  virtual int release (void);
  virtual int acquire_read (void);
  virtual int acquire_write (void);
  virtual int tryacquire_read (void);
  virtual int tryacquire_write (void);
  virtual int tryacquire_write_upgrade (void);
  void dump (void) const;

protected:
  /**
   * Create and initialize create the actual lcok used in the class.
   * The default constructor simply set the <lock_> to 0 (null).  You
   * must overwrite this method for this class to work.
   */
  ACE_Adaptive_Lock (void);

  ACE_Lock *lock_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Lock.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_LOCK_H */

