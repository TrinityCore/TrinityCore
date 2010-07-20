// $Id: Semaphore.cpp 84282 2009-01-30 15:04:29Z msmit $

#include "ace/Semaphore.h"

#if !defined (__ACE_INLINE__)
#include "ace/Semaphore.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Log_Msg.h"
#include "ace/ACE.h"

ACE_RCSID (ace,
           Semaphore,
           "$Id: Semaphore.cpp 84282 2009-01-30 15:04:29Z msmit $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Semaphore)

void
ACE_Semaphore::dump (void) const
{
#if defined (ACE_HAS_DUMP)
// ACE_TRACE ("ACE_Semaphore::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Semaphore::ACE_Semaphore (unsigned int count,
                              int type,
                              const ACE_TCHAR *name,
                              void *arg,
                              int max)
  : removed_ (false)
{
// ACE_TRACE ("ACE_Semaphore::ACE_Semaphore");
#if defined(ACE_LACKS_UNNAMED_SEMAPHORE)
// if the user does not provide a name, we generate a unique name here
  ACE_TCHAR iname[ACE_UNIQUE_NAME_LEN];
  if (name == 0)
    ACE::unique_name (this, iname, ACE_UNIQUE_NAME_LEN);
  if (ACE_OS::sema_init (&this->semaphore_, count, type,
                         name ? name : iname,
                         arg, max) != 0)
#else
  if (ACE_OS::sema_init (&this->semaphore_, count, type,
                         name, arg, max) != 0)
#endif
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Semaphore::ACE_Semaphore")));
}

ACE_Semaphore::~ACE_Semaphore (void)
{
// ACE_TRACE ("ACE_Semaphore::~ACE_Semaphore");

  this->remove ();
}

ACE_END_VERSIONED_NAMESPACE_DECL
