// -*- C++ -*-

//==========================================================================
/**
 *  @file    Condition_T.h
 *
 *  $Id: Condition_T.h 96061 2012-08-16 09:36:07Z mcorino $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_CONDITION_T_H
#define ACE_CONDITION_T_H

#include /**/ "ace/pre.h"

#include "ace/OS_NS_Thread.h"
#include "ace/Condition_Attributes.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_THREADS) /* ACE platform supports some form of threading. */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;

/**
 * @class ACE_Condition
 *
 * @brief ACE_Condition variable wrapper, which allows threads to block
 * until shared data changes state.
 *
 * A condition variable enables threads to atomically block and
 * test the condition under the protection of a mutual exclusion
 * lock (mutex) until the condition is satisfied.  That is,
 * the mutex must have been held by the thread before calling
 * wait or signal on the condition.  If the condition is false,
 * a thread blocks on a condition variable and atomically
 * releases the mutex that is waiting for the condition to
 * change.  If another thread changes the condition, it may wake
 * up waiting threads by signaling the associated condition
 * variable.  The waiting threads, upon awakening, reacquire the
 * mutex and re-evaluate the condition.
 * Note, you can only parameterize <ACE_Condition> with
 * @a ACE_Thread_Mutex, @a ACE_Recursive_Thread_Mutex, or @a ACE_Null_Mutex.
 */
template <class MUTEX>
class ACE_Condition
{
public:
  /// Initialize the condition variable.
  ACE_Condition (MUTEX &m, int type = USYNC_THREAD,
                 const ACE_TCHAR *name = 0, void *arg = 0);

  /// Initialize the condition variable.
  ACE_Condition (MUTEX &m,
                 const ACE_Condition_Attributes &attributes,
                 const ACE_TCHAR *name = 0,
                 void *arg = 0);

  /// Implicitly destroy the condition variable.
  ~ACE_Condition (void);

  // = Lock accessors.
  /**
   * Block on condition, or until absolute time-of-day has passed.  If
   * @a abstime == 0 use "blocking" <wait> semantics.  Else, if @a abstime
   * != 0 and the call times out before the condition is signaled
   * wait() returns -1 and sets errno to ETIME.
   */
  int wait (const ACE_Time_Value *abstime);

  /// Block on condition.
  int wait (void);

  /**
   * Block on condition or until absolute time-of-day has passed.  If
   * @a abstime == 0 use "blocking" wait() semantics on the @a mutex
   * passed as a parameter (this is useful if you need to store the
   * <Condition> in shared memory).  Else, if @a abstime != 0 and the
   * call times out before the condition is signaled wait() returns -1
   * and sets errno to ETIME.
   */
  int wait (MUTEX &mutex, const ACE_Time_Value *abstime = 0);

  /// Signal one waiting thread.
  int signal (void);

  /// Signal *all* waiting threads.
  int broadcast (void);

  // = Utility methods.
  /// Explicitly destroy the condition variable.
  int remove (void);

  /// Returns a reference to the underlying mutex_;
  MUTEX &mutex (void);

  /// Dump the state of an object.
  void dump (void) const;

  // ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  /// Condition variable.
  ACE_cond_t cond_;

  /// Reference to mutex lock.
  MUTEX &mutex_;

private:
  // = Prevent assignment and initialization.
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Condition<MUTEX> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Condition (const ACE_Condition<MUTEX> &))
};

/**
 * @class ACE_Thread_Condition
 *
 * @brief ACE_Condition variable wrapper that works within processes.
 *
 * A condition variable enables threads to atomically block and
 * test the condition under the protection of a mutual exclu-
 * sion lock (mutex) until the condition is satisfied.  That is,
 * the mutex must have been held by the thread before calling
 * wait or signal on the condition.  If the condition is false,
 * a thread blocks on a condition variable and atomically
 * releases the mutex that is waiting for the condition to
 * change.  If another thread changes the condition, it may wake
 * up waiting threads by signaling the associated condition
 * variable.  The waiting threads, upon awakening, reacquire the
 * mutex and re-evaluate the condition.
 */
template <class MUTEX>
class ACE_Thread_Condition : public ACE_Condition<MUTEX>
{
public:
  // = Initialization method.
  ACE_Thread_Condition (MUTEX &m, const ACE_TCHAR *name = 0, void *arg = 0);

  /// Dump the state of an object.
  void dump (void) const;

  // ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Condition_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Condition_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Condition_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* ACE_HAS_THREADS */

#include /**/ "ace/post.h"
#endif /* ACE_CONDITION_T_H */
