// -*- C++ -*-
//
// $Id: FIFO_Send_Msg.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_stropts.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ssize_t
ACE_FIFO_Send_Msg::send (const void *buf, size_t len)
{
  ACE_TRACE ("ACE_FIFO_Send_Msg::send");
  ACE_Str_Buf send_msg ((char *) buf, static_cast<int> (len));

  return this->send (send_msg);
}

#if defined (ACE_HAS_STREAM_PIPES)
ACE_INLINE ssize_t
ACE_FIFO_Send_Msg::send (const ACE_Str_Buf *data,
                         const ACE_Str_Buf *cntl,
                         int flags)
{
  ACE_TRACE ("ACE_FIFO_Send_Msg::send");
  if (ACE_OS::putmsg (this->get_handle (),
                      (strbuf *) cntl,
                      (strbuf *) data,
                      flags) == -1)
    return-1;
  else
    return (cntl == 0 ? 0 : cntl->len) + (data == 0 ? 0 : data->len);
}

ACE_INLINE ssize_t
ACE_FIFO_Send_Msg::send (int band,
                         const ACE_Str_Buf *data,
                         const ACE_Str_Buf *cntl,
                         int flags)
{
  ACE_TRACE ("ACE_FIFO_Send_Msg::send");

  if (ACE_OS::putpmsg (this->get_handle (),
                       (strbuf *) cntl,
                       (strbuf *) data,
                       band,
                       flags) == -1)
    return -1;
  else
    return (cntl == 0 ? 0 : cntl->len) + (data == 0 ? 0 : data->len);
}
#endif /* ACE_HAS_STREAM_PIPES */

ACE_END_VERSIONED_NAMESPACE_DECL
