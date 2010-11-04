// $Id: FIFO_Send.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/FIFO_Send.h"
#include "ace/Log_Msg.h"

#if !defined (__ACE_INLINE__)
#include "ace/FIFO_Send.inl"
#endif /* __ACE_INLINE__ */



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_FIFO_Send)

void
ACE_FIFO_Send::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_FIFO_Send::dump");
  ACE_FIFO::dump ();
#endif /* ACE_HAS_DUMP */
}

ACE_FIFO_Send::ACE_FIFO_Send (void)
{
//  ACE_TRACE ("ACE_FIFO_Send::ACE_FIFO_Send");
}

int
ACE_FIFO_Send::open (const ACE_TCHAR *rendezvous_name,
                     int flags,
                     mode_t perms,
                     LPSECURITY_ATTRIBUTES sa)
{
  ACE_TRACE ("ACE_FIFO_Send::open");
  return ACE_FIFO::open (rendezvous_name,
                         flags | O_WRONLY,
                         perms,
                         sa);
}

ACE_FIFO_Send::ACE_FIFO_Send (const ACE_TCHAR *fifo_name,
                              int flags,
                              mode_t perms,
                              LPSECURITY_ATTRIBUTES sa)
{
  ACE_TRACE ("ACE_FIFO_Send::ACE_FIFO_Send");
  if (this->ACE_FIFO_Send::open (fifo_name,
                                 flags,
                                 perms,
                                 sa) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_FIFO_Send::ACE_FIFO_Send")));
}

ACE_END_VERSIONED_NAMESPACE_DECL
