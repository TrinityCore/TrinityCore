// -*- C++ -*-
//
// $Id: SOCK_SEQPACK_Association.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/SOCK_SEQPACK_Association.h"
#include "ace/OS_NS_sys_socket.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE
ACE_SOCK_SEQPACK_Association::ACE_SOCK_SEQPACK_Association (void)
{
  // ACE_TRACE ("ACE_SOCK_SEQPACK_Association::ACE_SOCK_SEQPACK_Association");
}
ACE_INLINE
ACE_SOCK_SEQPACK_Association::ACE_SOCK_SEQPACK_Association (ACE_HANDLE h)
{
  // ACE_TRACE ("ACE_SOCK_SEQPACK_Association::ACE_SOCK_SEQPACK_Association");
  this->set_handle (h);
}
ACE_INLINE
ACE_SOCK_SEQPACK_Association::~ACE_SOCK_SEQPACK_Association (void)
{
  // ACE_TRACE ("ACE_SOCK_SEQPACK_Association::~ACE_SOCK_SEQPACK_Association");
}
ACE_INLINE int
ACE_SOCK_SEQPACK_Association::close_reader (void)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Association::close_reader");
  if (this->get_handle () != ACE_INVALID_HANDLE)
    return ACE_OS::shutdown (this->get_handle (), ACE_SHUTDOWN_READ);
  else
    return 0;
}
// Shut down just the writing end of a ACE_SOCK.
ACE_INLINE int
ACE_SOCK_SEQPACK_Association::close_writer (void)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Association::close_writer");
  if (this->get_handle () != ACE_INVALID_HANDLE)
    return ACE_OS::shutdown (this->get_handle (), ACE_SHUTDOWN_WRITE);
  else
    return 0;
}
ACE_INLINE ssize_t
ACE_SOCK_SEQPACK_Association::recv_n (void *buf,
                         size_t len,
                         int flags,
                         const ACE_Time_Value *timeout,
                         size_t *bytes_transferred) const
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Association::recv_n");
  return ACE::recv_n (this->get_handle (),
                      buf,
                      len,
                      flags,
                      timeout,
                      bytes_transferred);
}
ACE_INLINE ssize_t
ACE_SOCK_SEQPACK_Association::recv_n (void *buf,
                         size_t len,
                         const ACE_Time_Value *timeout,
                         size_t *bytes_transferred) const
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Association::recv_n");
  return ACE::recv_n (this->get_handle (),
                      buf,
                      len,
                      timeout,
                      bytes_transferred);
}
ACE_INLINE ssize_t
ACE_SOCK_SEQPACK_Association::recvv_n (iovec iov[],
                                       int n,
                                       const ACE_Time_Value *timeout,
                                       size_t *bytes_transferred) const
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Association::recvv_n");
  return ACE::recvv_n (this->get_handle (),
                       iov,
                       n,
                       timeout,
                       bytes_transferred);
}
ACE_INLINE ssize_t
ACE_SOCK_SEQPACK_Association::send_n (const void *buf,
                         size_t len,
                         int flags,
                         const ACE_Time_Value *timeout,
                         size_t *bytes_transferred) const
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Association::send_n");
  return ACE::send_n (this->get_handle (),
                      buf,
                      len,
                      flags,
                      timeout,
                      bytes_transferred);
}
ACE_INLINE ssize_t
ACE_SOCK_SEQPACK_Association::send_n (const void *buf,
                         size_t len,
                         const ACE_Time_Value *timeout,
                         size_t *bytes_transferred) const
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Association::send_n");
  return ACE::send_n (this->get_handle (),
                      buf,
                      len,
                      timeout,
                      bytes_transferred);
}
ACE_INLINE ssize_t
ACE_SOCK_SEQPACK_Association::sendv_n (const iovec iov[],
                                       int n,
                                       const ACE_Time_Value *timeout,
                                       size_t *bytes_transferred) const
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Association::sendv_n");
  return ACE::sendv_n (this->get_handle (),
                       iov,
                       n,
                       timeout,
                       bytes_transferred);
}
ACE_INLINE ssize_t
ACE_SOCK_SEQPACK_Association::send_n (const ACE_Message_Block *message_block,
                         const ACE_Time_Value *timeout,
                         size_t *bytes_transferred) const
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Association::send_n");
  return ACE::send_n (this->get_handle (),
                      message_block,
                      timeout,
                      bytes_transferred);
}
ACE_INLINE ssize_t
ACE_SOCK_SEQPACK_Association::send_urg (const void *ptr,
                           size_t len,
                           const ACE_Time_Value *timeout) const
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Association::send_urg");
  return ACE::send (this->get_handle (),
                    ptr,
                    len,
                    MSG_OOB,
                    timeout);
}
ACE_INLINE ssize_t
ACE_SOCK_SEQPACK_Association::recv_urg (void *ptr,
                           size_t len,
                           const ACE_Time_Value *timeout) const
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Association::recv_urg");
  return ACE::recv (this->get_handle (),
                    ptr,
                    len,
                    MSG_OOB,
                    timeout);
}
ACE_END_VERSIONED_NAMESPACE_DECL
