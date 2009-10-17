// $Id: FIFO_Recv_Msg.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/FIFO_Recv_Msg.h"
#include "ace/Log_Msg.h"
#if !defined (__ACE_INLINE__)
#include "ace/FIFO_Recv_Msg.inl"
#endif /* __ACE_INLINE__ */
ACE_RCSID(ace, FIFO_Recv_Msg, "$Id: FIFO_Recv_Msg.cpp 80826 2008-03-04 14:51:23Z wotte $")
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_ALLOC_HOOK_DEFINE(ACE_FIFO_Recv_Msg)
void
ACE_FIFO_Recv_Msg::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_FIFO_Recv_Msg::dump");
  ACE_FIFO_Recv::dump ();
#endif /* ACE_HAS_DUMP */
}
// Note that persistent means "open FIFO for writing, as well as
// reading."  This ensures that the FIFO never gets EOF, even if there
// aren't any writers at the moment!
int
ACE_FIFO_Recv_Msg::open (const ACE_TCHAR *fifo_name,
                         int flags,
                         mode_t perms,
                         int persistent,
                         LPSECURITY_ATTRIBUTES sa)
{
  ACE_TRACE ("ACE_FIFO_Recv_Msg::open");
  return ACE_FIFO_Recv::open (fifo_name,
                              flags,
                              perms,
                              persistent,
                              sa);
}
ACE_FIFO_Recv_Msg::ACE_FIFO_Recv_Msg (void)
{
  ACE_TRACE ("ACE_FIFO_Recv_Msg::ACE_FIFO_Recv_Msg");
}
ACE_FIFO_Recv_Msg::ACE_FIFO_Recv_Msg (const ACE_TCHAR *fifo_name,
                                      int flags,
                                      mode_t perms,
                                      int persistent,
                                      LPSECURITY_ATTRIBUTES sa)
{
  ACE_TRACE ("ACE_FIFO_Recv_Msg::ACE_FIFO_Recv_Msg");
  if (this->ACE_FIFO_Recv_Msg::open (fifo_name,
                                     flags,
                                     perms,
                                     persistent,
                                     sa) == -1)
    ACE_ERROR ((LM_ERROR,  ACE_TEXT ("%p\n"),  ACE_TEXT ("ACE_FIFO_Recv_Msg")));
}
ACE_END_VERSIONED_NAMESPACE_DECL

