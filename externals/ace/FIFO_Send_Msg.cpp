// $Id: FIFO_Send_Msg.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/FIFO_Send_Msg.h"

#include "ace/Log_Msg.h"
#include "ace/OS_NS_sys_uio.h"

#if !defined (__ACE_INLINE__)
#include "ace/FIFO_Send_Msg.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, FIFO_Send_Msg, "$Id: FIFO_Send_Msg.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_FIFO_Send_Msg)

void
ACE_FIFO_Send_Msg::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_FIFO_Send_Msg::dump");
  ACE_FIFO_Send::dump ();
#endif /* ACE_HAS_DUMP */
}

ssize_t
ACE_FIFO_Send_Msg::send (const ACE_Str_Buf &send_msg)
{
  // ACE_TRACE ("ACE_FIFO_Send_Msg::send");
#if defined (ACE_HAS_STREAM_PIPES)
  if (ACE_OS::putmsg (this->get_handle (),
                      (strbuf *) 0,
                      (strbuf *) &send_msg,
                      0) == -1)
    return -1;
  else
    return send_msg.len;
#else
  iovec iov[2];

  iov[0].iov_base = (char *) &send_msg.len;
  iov[0].iov_len  = sizeof send_msg.len;

  iov[1].iov_base = (char *) send_msg.buf;
  iov[1].iov_len  =  static_cast<u_long> (send_msg.len);

  ssize_t sent = ACE_OS::writev (this->get_handle (), iov, 2);
  if (sent > 0)
    sent -= iov[0].iov_len;       // Don't count the length we added.
  return sent;
#endif /* ACE_HAS_STREAM_PIPES */
}

ACE_FIFO_Send_Msg::ACE_FIFO_Send_Msg (void)
{
//  ACE_TRACE ("ACE_FIFO_Send_Msg::ACE_FIFO_Send_Msg");
}

int
ACE_FIFO_Send_Msg::open (const ACE_TCHAR *fifo_name,
                         int flags,
                         mode_t perms,
                         LPSECURITY_ATTRIBUTES sa)
{
  ACE_TRACE ("ACE_FIFO_Send_Msg::open");
  return ACE_FIFO_Send::open (fifo_name, flags | O_WRONLY, perms, sa);
}

ACE_FIFO_Send_Msg::ACE_FIFO_Send_Msg (const ACE_TCHAR *fifo_name,
                                      int flags,
                                      mode_t perms,
                                      LPSECURITY_ATTRIBUTES sa)
{
  ACE_TRACE ("ACE_FIFO_Send_Msg::ACE_FIFO_Send_Msg");
  if (this->ACE_FIFO_Send_Msg::open (fifo_name, flags, perms, sa) == -1)
    ACE_ERROR ((LM_ERROR,  ACE_TEXT ("%p\n"),  ACE_TEXT ("ACE_FIFO_Send_Msg")));
}

ACE_END_VERSIONED_NAMESPACE_DECL
