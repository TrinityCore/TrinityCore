// -*- C++ -*-

//==========================================================================
/**
 *  @file    Condition_Recursive_Thread_Mutex.h
 *
 *  $Id: Condition_Recursive_Thread_Mutex.h 86731 2009-09-17 12:23:48Z johnnyw $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_CONDITION_RECURSIVE_THREAD_MUTEX_H
#define ACE_CONDITION_RECURSIVE_THREAD_MUTEX_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_HAS_THREADS)
#  include "ace/Null_Condition.h"
#else /* ACE_HAS_THREADS */
#include "ace/Recursive_Thread_Mutex.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class ACE_LOCK> class ACE_Condition;

/**
 * @brief ACE_Condition template specialization written using
 *  @a ACE_Recursive_Thread_Mutex.  This allows threads to block until
 *  shared data changes state using recursive mutexes.
 */
template<>
class ACE_Export ACE_Condition<ACE_Recursive_Thread_Mutex>
{
public:
  /// Initialize the condition variable with a recursive mutex.
  ACE_Condition (ACE_Recursive_Thread_Mutex &m);

  /// Implicitly destroy the condition variable.
  ~ACE_Condition (void);

  /**
   * Explicitly destroy the condition variable.  Note that only one
   * thread should call this method since it doesn't protect against
   * race conditions.
   */
  int remove (void);

  /**
   * Block on condition, or until absolute time-of-day has passed.  If
   * abstime == 0 use "blocking" <wait> semantics.  Else, if @a abstime
   * != 0 and the call times out before the condition is signaled
   * <wait> returns -1 and sets errno to ETIME.
   */
  int wait (const ACE_Time_Value *abstime = 0);

  /**
   * Block on condition or until absolute time-of-day has passed.  If
   * abstime == 0 use "blocking" wait() semantics on the recursive @a mutex
   * passed as a parameter (this is useful if you need to store the
   * <Condition> in shared memory).  Else, if <abstime> != 0 and the
   * call times out before the condition is signaled <wait> returns -1
   * and sets errno to ETIME.
   */
  int wait (ACE_Recursive_Thread_Mutex &mutex,
            const ACE_Time_Value *abstime = 0);

  /// Signal one waiting thread.
  int signal (void);

  /// Signal *all* waiting threads.
  int broadcast (void);

  /// Returns a reference to the underlying mutex;
  ACE_Recursive_Thread_Mutex &mutex (void);

  /// Dump the state of an object.
  void dump (void) const;

private:

  // = Prevent assignment and copying.
  void operator= (const ACE_Condition<ACE_Recursive_Thread_Mutex> &);
  ACE_Condition (const ACE_Condition<ACE_Recursive_Thread_Mutex> &);

private:

  /// A normal (i.e., non-recursive) condition variable.
  ACE_cond_t cond_;

  /// Reference to the recursive mutex.
  ACE_Recursive_Thread_Mutex &mutex_;

};

class ACE_Export ACE_Condition_Recursive_Thread_Mutex
  : public ACE_Condition<ACE_Recursive_Thread_Mutex>
{
public:
  /// Initialize the condition variable with a recursive mutex.
  ACE_Condition_Recursive_Thread_Mutex (ACE_Recursive_Thread_Mutex &m);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* !ACE_HAS_THREADS */

#include /**/ "ace/post.h"
#endif /* ACE_CONDITION_RECURSIVE_THREAD_MUTEX_H */
