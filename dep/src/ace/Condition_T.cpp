// $Id: Condition_T.cpp 81283 2008-04-09 01:28:18Z schmidt $

#ifndef ACE_CONDITION_T_CPP
#define ACE_CONDITION_T_CPP

#include "ace/Condition_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_THREADS)

#include "ace/Log_Msg.h"

#if !defined (__ACE_INLINE__)
#include "ace/Condition_T.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Condition)

template <class MUTEX> void
ACE_Condition<MUTEX>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
// ACE_TRACE ("ACE_Condition<MUTEX>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class MUTEX>
ACE_Thread_Condition<MUTEX>::ACE_Thread_Condition (MUTEX &m,
                                                   const ACE_TCHAR *name,
                                                   void *arg)
  : ACE_Condition<MUTEX> (m, USYNC_THREAD, name, arg)
{
// ACE_TRACE ("ACE_Thread_Condition<MUTEX>::ACE_Thread_Condition");
}

template <class MUTEX> void
ACE_Thread_Condition<MUTEX>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
// ACE_TRACE ("ACE_Thread_Condition<MUTEX>::dump");

  ACE_Condition<MUTEX>::dump ();
#endif /* ACE_HAS_DUMP */
}

template <class MUTEX>
ACE_Condition<MUTEX>::ACE_Condition (MUTEX &m,
                                     int type,
                                     const ACE_TCHAR *name,
                                     void *arg)
  :
    mutex_ (m)
{
  // ACE_TRACE ("ACE_Condition<MUTEX>::ACE_Condition");

  if (ACE_OS::cond_init (&this->cond_,
                         (short) type,
                         name,
                         arg) != 0)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Condition::ACE_Condition")));
}

template <class MUTEX>
ACE_Condition<MUTEX>::~ACE_Condition (void)
{
  // ACE_TRACE ("ACE_Condition<MUTEX>::~ACE_Condition");

  if (this->remove () == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Condition::~ACE_Condition")));
}

template <class MUTEX> int
ACE_Condition<MUTEX>::wait (void)
{
  // ACE_TRACE ("ACE_Condition<MUTEX>::wait");
  return ACE_OS::cond_wait (&this->cond_,
                            &this->mutex_.lock_);
}

template <class MUTEX> int
ACE_Condition<MUTEX>::wait (MUTEX &mutex,
                            const ACE_Time_Value *abstime)
{
// ACE_TRACE ("ACE_Condition<MUTEX>::wait");
  if (abstime == 0)
      return ACE_OS::cond_wait (&this->cond_,
                                &mutex.lock_);
  else
    return ACE_OS::cond_timedwait (&this->cond_,
                                   &mutex.lock_,
                                   (ACE_Time_Value *) abstime);
}

// Peform an "alertable" timed wait.  If the argument ABSTIME == 0
// then we do a regular cond_wait(), else we do a timed wait for up to
// ABSTIME using the Solaris cond_timedwait() function.

template <class MUTEX> int
ACE_Condition<MUTEX>::wait (const ACE_Time_Value *abstime)
{
// ACE_TRACE ("ACE_Condition<MUTEX>::wait");
  return this->wait (this->mutex_, abstime);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_THREADS */

#endif /* ACE_CONDITION_T_CPP */

