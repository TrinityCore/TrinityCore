/* -*- C++ -*- */
/**
 * @file Condition_Thread_Mutex.cpp
 *
 * $Id: Condition_Thread_Mutex.cpp 96077 2012-08-20 08:13:23Z johnnyw $
 *
 * Originally in Synch.cpp
 *
 * @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */

#include "ace/Condition_Thread_Mutex.h"

#if defined (ACE_HAS_THREADS)

#if !defined (__ACE_INLINE__)
#include "ace/Condition_Thread_Mutex.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Log_Msg.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Condition<ACE_Thread_Mutex>)

void
ACE_Condition<ACE_Thread_Mutex>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
// ACE_TRACE ("ACE_Condition<ACE_Thread_Mutex>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));
#if defined (ACE_WIN32)
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("waiters = %d\n"),
              this->cond_.waiters ()));
#endif /* ACE_WIN32 */
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Condition<ACE_Thread_Mutex>::ACE_Condition (ACE_Thread_Mutex &m,
                                                const ACE_TCHAR *name,
                                                void *arg)
  : mutex_ (m),
    removed_ (false)
{
// ACE_TRACE ("ACE_Condition<ACE_Thread_Mutex>::ACE_Condition<ACE_Thread_Mutex>");
  if (ACE_OS::cond_init (&this->cond_,
                         (short) USYNC_THREAD,
                         name,
                         arg) != 0)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Condition<ACE_Thread_Mutex>::ACE_Condition<ACE_Thread_Mutex>")));
}

ACE_Condition<ACE_Thread_Mutex>::ACE_Condition (ACE_Thread_Mutex &m,
                                                const ACE_Condition_Attributes &attributes,
                                                const ACE_TCHAR *name,
                                                void *arg)
  : mutex_ (m),
    removed_ (false)
{
// ACE_TRACE ("ACE_Condition<ACE_Thread_Mutex>::ACE_Condition<ACE_Thread_Mutex>");
  if (ACE_OS::cond_init (&this->cond_,
                         const_cast<ACE_condattr_t &> (attributes.attributes ()),
                         name, arg) != 0)
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Condition<ACE_Thread_Mutex>::ACE_Condition<ACE_Thread_Mutex>")));
}

ACE_Condition<ACE_Thread_Mutex>::~ACE_Condition (void)
{
// ACE_TRACE ("ACE_Condition<ACE_Thread_Mutex>::~ACE_Condition<ACE_Thread_Mutex>");
  this->remove ();
}

// Peform an "alertable" timed wait.  If the argument <abstime> == 0
// then we do a regular <cond_wait>, else we do a timed wait for up to
// <abstime> using the <cond_timedwait> function.

int
ACE_Condition<ACE_Thread_Mutex>::wait (void)
{
// ACE_TRACE ("ACE_Condition<ACE_Thread_Mutex>::wait");
  return ACE_OS::cond_wait (&this->cond_, &this->mutex_.lock ());
}

int
ACE_Condition<ACE_Thread_Mutex>::wait (ACE_Thread_Mutex &mutex,
                                  const ACE_Time_Value *abstime)
{
// ACE_TRACE ("ACE_Condition<ACE_Thread_Mutex>::wait");
  return ACE_OS::cond_timedwait (&this->cond_,
                                 &mutex.lock (),
                                 const_cast <ACE_Time_Value *> (abstime));
}

int
ACE_Condition<ACE_Thread_Mutex>::wait (const ACE_Time_Value *abstime)
{
// ACE_TRACE ("ACE_Condition<ACE_Thread_Mutex>::wait");
  return this->wait (this->mutex_, abstime);
}

int
ACE_Condition<ACE_Thread_Mutex>::signal (void)
{
// ACE_TRACE ("ACE_Condition<ACE_Thread_Mutex>::signal");
  return ACE_OS::cond_signal (&this->cond_);
}

int
ACE_Condition<ACE_Thread_Mutex>::broadcast (void)
{
// ACE_TRACE ("ACE_Condition<ACE_Thread_Mutex>::broadcast");
  return ACE_OS::cond_broadcast (&this->cond_);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_THREADS */
