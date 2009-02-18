// -*- C++ -*-

/**
 * @file Condition_Recursive_Thread_Mutex.cpp
 *
 * $Id: Condition_Recursive_Thread_Mutex.cpp 80826 2008-03-04 14:51:23Z wotte $
 *
 * Originally in Synch.cpp
 *
 * @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */

#include "ace/Condition_Recursive_Thread_Mutex.h"

#if defined (ACE_HAS_THREADS)

#if defined (ACE_HAS_DUMP)
#  include "ace/Log_Msg.h"
#endif /* ACE_HAS_DUMP */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

int
ACE_Condition<ACE_Recursive_Thread_Mutex>::remove (void)
{
  return ACE_OS::cond_destroy (&this->cond_);
}

void
ACE_Condition<ACE_Recursive_Thread_Mutex>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
// ACE_TRACE ("ACE_Condition<MUTEX>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  // No dump method for ACE_cond_t even in emulated mode.
  // cond_.dump ();
  this->mutex_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Condition<ACE_Recursive_Thread_Mutex>::~ACE_Condition (void)
{
  this->remove ();
}

ACE_Condition<ACE_Recursive_Thread_Mutex>::ACE_Condition (ACE_Recursive_Thread_Mutex &m)
  : mutex_ (m)
{
  ACE_OS::cond_init (&this->cond_);
}

int
ACE_Condition<ACE_Recursive_Thread_Mutex>::wait (const ACE_Time_Value *abstime)
{
  return this->wait (this->mutex_, abstime);
}

int
ACE_Condition<ACE_Recursive_Thread_Mutex>::wait (ACE_Recursive_Thread_Mutex &mutex,
                                                 const ACE_Time_Value *abstime)
{
  ACE_recursive_mutex_state mutex_state_holder;
  ACE_recursive_thread_mutex_t &recursive_mutex = mutex.mutex ();

  if (ACE_OS::recursive_mutex_cond_unlock (&recursive_mutex,
                                           mutex_state_holder) == -1)
    return -1;

  // We wait on the condition, specifying the nesting mutex. For platforms
  // with ACE_HAS_RECURSIVE_MUTEXES, this is the recursive mutex itself,
  // and is the same as recursive_mutex, above. The caller should have been
  // holding the lock on entry to this method, and it is still held.
  // For other platforms, this is the nesting mutex that guards the
  // ACE_recursive_mutex_t internals, and recursive_mutex_cond_unlock()
  // returned with the lock held, but waiters primed and waiting to be
  // released. At cond_wait below, the mutex will be released.
  // On return, it will be reacquired.
  const int result = abstime == 0
    ? ACE_OS::cond_wait (&this->cond_,
                         &mutex.get_nesting_mutex ())
    : ACE_OS::cond_timedwait (&this->cond_,
                              &mutex.get_nesting_mutex (),
                              const_cast <ACE_Time_Value *> (abstime));
  // We are holding the mutex, whether the wait succeeded or failed.
  // Stash errno (in case it failed) and then we need to reset the
  // recursive mutex state to what it was on entry to this method.
  // Resetting it may require a wait for another thread to release
  // the ACE_recursive_thread_mutex_t if this is a platform without
  // ACE_HAS_RECURSIVE_MUTEXES, and recursive_mutex_cond_relock() takes
  // care of that.
  {
    ACE_Errno_Guard error (errno);
    ACE_OS::recursive_mutex_cond_relock (&recursive_mutex,
                                         mutex_state_holder);
  }

  return result;
}

int
ACE_Condition<ACE_Recursive_Thread_Mutex>::signal (void)
{
  return ACE_OS::cond_signal (&this->cond_);
}

int
ACE_Condition<ACE_Recursive_Thread_Mutex>::broadcast (void)
{
  return ACE_OS::cond_broadcast (&this->cond_);
}

ACE_Recursive_Thread_Mutex &
ACE_Condition<ACE_Recursive_Thread_Mutex>::mutex (void)
{
  return this->mutex_;
}

ACE_Condition_Recursive_Thread_Mutex::ACE_Condition_Recursive_Thread_Mutex (
  ACE_Recursive_Thread_Mutex &m) :
    ACE_Condition<ACE_Recursive_Thread_Mutex> (m)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_THREADS */

