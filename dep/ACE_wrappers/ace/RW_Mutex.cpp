/**
 * @file RW_Mutex.cpp
 *
 * $Id: RW_Mutex.cpp 80826 2008-03-04 14:51:23Z wotte $
 *
 * Originally in Synch.cpp
 *
 * @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */

#include "ace/RW_Mutex.h"

#if defined (ACE_HAS_THREADS)

#if !defined (__ACE_INLINE__)
#include "ace/RW_Mutex.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Log_Msg.h"

ACE_RCSID(ace, RW_Mutex, "$Id: RW_Mutex.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

void
ACE_RW_Mutex::dump (void) const
{
#if defined (ACE_HAS_DUMP)
// ACE_TRACE ("ACE_RW_Mutex::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_RW_Mutex::ACE_RW_Mutex (int type, const ACE_TCHAR *name, void *arg)
  : removed_ (0)
{
// ACE_TRACE ("ACE_RW_Mutex::ACE_RW_Mutex");
  if (ACE_OS::rwlock_init (&this->lock_, type, name, arg) != 0)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_RW_Mutex::ACE_RW_Mutex")));
}

ACE_RW_Mutex::~ACE_RW_Mutex (void)
{
// ACE_TRACE ("ACE_RW_Mutex::~ACE_RW_Mutex");
  this->remove ();
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_THREADS */
