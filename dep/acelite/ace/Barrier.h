// -*- C++ -*-

//==========================================================================
/**
 *  @file    Barrier.h
 *
 *  $Id: Barrier.h 92069 2010-09-28 11:38:59Z johnnyw $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_BARRIER_H
#define ACE_BARRIER_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "ace/config-all.h"

// ACE platform supports some form of threading.
#if !defined (ACE_HAS_THREADS)

#include "ace/OS_NS_errno.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Barrier
 *
 * @brief This is a no-op to make ACE "syntactically consistent."
 */
class ACE_Export ACE_Barrier
{
public:
  ACE_Barrier (unsigned int, const ACE_TCHAR * = 0, void * = 0) {}
  ~ACE_Barrier (void) {}
  int wait (void) { ACE_NOTSUP_RETURN (-1); }
  void dump (void) const {}
};

ACE_END_VERSIONED_NAMESPACE_DECL

#else /* ACE_HAS_THREADS */

#include "ace/Condition_Thread_Mutex.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

struct ACE_Export ACE_Sub_Barrier
{
  // = Initialization.
  ACE_Sub_Barrier (unsigned int count,
                   ACE_Thread_Mutex &lock,
                   const ACE_TCHAR *name = 0,
                   void *arg = 0);

  ~ACE_Sub_Barrier (void);

  /// True if this generation of the barrier is done.
  ACE_Condition_Thread_Mutex barrier_finished_;

  /// Number of threads that are still running.
  int running_threads_;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

/**
 * @class ACE_Barrier
 *
 * @brief Implements "barrier synchronization".
 *
 * This class allows <count> number of threads to synchronize
 * their completion of (one round of) a task, which is known as
 * "barrier synchronization".   After all the threads call <wait()>
 * on the barrier they are all atomically released and can begin a new
 * round.
 *
 * This implementation uses a "sub-barrier generation numbering"
 * scheme to avoid overhead and to ensure that all threads wait to
 * leave the barrier correct.  This code is based on an article from
 * SunOpsis Vol. 4, No. 1 by Richard Marejka
 * (Richard.Marejka@canada.sun.com).
 */
class ACE_Export ACE_Barrier
{
public:
  /// Initialize the barrier to synchronize @a count threads.
  ACE_Barrier (unsigned int count,
               const ACE_TCHAR *name = 0,
               void *arg = 0);

  /// Default dtor.
  ~ACE_Barrier (void);

  /// Block the caller until all @c count threads have called @c wait and
  /// then allow all the caller threads to continue in parallel.
  ///
  /// @retval 0 after successfully waiting for all threads to wait.
  /// @retval -1 if an error occurs or the barrier is shut
  /// down (@sa shutdown ()).
  int wait (void);

  /// Shut the barrier down, aborting the wait of all waiting threads.
  /// Any threads waiting on the barrier when it is shut down will return with
  /// value -1, errno ESHUTDOWN.
  ///
  /// @retval 0 for success, -1 if already shut down.
  ///
  /// @since ACE beta 5.4.9.
  int shutdown (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Serialize access to the barrier state.
  ACE_Thread_Mutex lock_;

  /// Either 0 or 1, depending on whether we are the first generation
  /// of waiters or the next generation of waiters.
  int current_generation_;

  /// Total number of threads that can be waiting at any one time.
  int count_;

  /**
   * We keep two @c sub_barriers, one for the first "generation" of
   * waiters, and one for the next "generation" of waiters.  This
   * efficiently solves the problem of what to do if all the first
   * generation waiters don't leave the barrier before one of the
   * threads calls wait() again (i.e., starts up the next generation
   * barrier).
   */
  ACE_Sub_Barrier sub_barrier_1_;
  ACE_Sub_Barrier sub_barrier_2_;
  ACE_Sub_Barrier *sub_barrier_[2];

private:
  // = Prevent assignment and initialization.
  void operator= (const ACE_Barrier &);
  ACE_Barrier (const ACE_Barrier &);
};

/**
 * @class ACE_Thread_Barrier
 *
 * @brief Implements "barrier synchronization" using ACE_Thread_Mutexes!
 *
 * This class is just a simple wrapper for ACE_Barrier that
 * selects the USYNC_THREAD variant for the locks.
 */
class ACE_Export ACE_Thread_Barrier : public ACE_Barrier
{
public:
  /// Create a Thread_Barrier, passing in the optional @a name.
  ACE_Thread_Barrier (unsigned int count, const ACE_TCHAR *name = 0);

  /// Default dtor.
  ~ACE_Thread_Barrier (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Barrier.inl"
#endif /* __ACE_INLINE__ */

#endif /* !ACE_HAS_THREADS */

#include /**/ "ace/post.h"
#endif /* ACE_BARRIER_H */
