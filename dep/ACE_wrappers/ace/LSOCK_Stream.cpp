// $Id: LSOCK_Stream.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/LSOCK_Stream.h"
#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)
#include "ace/Log_Msg.h"
#include "ace/OS_NS_sys_socket.h"
ACE_RCSID(ace, LSOCK_Stream, "$Id: LSOCK_Stream.cpp 80826 2008-03-04 14:51:23Z wotte $")
#if !defined (__ACE_INLINE__)
#include "ace/LSOCK_Stream.inl"
#endif /* __ACE_INLINE__ */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_ALLOC_HOOK_DEFINE(ACE_LSOCK_Stream)
int
ACE_LSOCK_Stream::get_local_addr (ACE_Addr &addr) const
{
  ACE_TRACE ("ACE_LSOCK_Stream::get_local_addr");
  // Perform the downcast since <addr> had better be an
  // <ACE_UNIX_Addr>.
  ACE_UNIX_Addr *rhs_unix_addr = dynamic_cast<ACE_UNIX_Addr *> (&addr);
  ACE_UNIX_Addr lhs_unix_addr;
  if (rhs_unix_addr == 0)
    return -1;
  else if (ACE_SOCK::get_local_addr (lhs_unix_addr) == -1)
    return -1;
  else
    {
      *rhs_unix_addr = lhs_unix_addr;
      return 0;
    }
}
int
ACE_LSOCK_Stream::get_remote_addr (ACE_Addr &addr) const
{
  ACE_TRACE ("ACE_LSOCK_Stream::get_remote_addr");
  return this->get_local_addr (addr);
}
void
ACE_LSOCK_Stream::dump (void) const
{
  ACE_TRACE ("ACE_LSOCK_Stream::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_SOCK_Stream::dump ();
  ACE_LSOCK::dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}
#if defined (ACE_HAS_MSG)
// Send a readv-style vector of buffers, along with an open I/O
// handle.
ssize_t
ACE_LSOCK_Stream::send_msg (const iovec iov[],
                            size_t n,
                            ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_LSOCK_Stream::send_msg");
  msghdr send_msg;
#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
  char cmsgbuf[ACE_BSD_CONTROL_MSG_LEN];
  cmsghdr *cmsgptr = (cmsghdr *) cmsgbuf;
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */
  send_msg.msg_iov = const_cast <iovec *> (iov);
  send_msg.msg_iovlen = n;
  send_msg.msg_name = 0;
  send_msg.msg_namelen = 0;
#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
  cmsgptr->cmsg_level = SOL_SOCKET;
  cmsgptr->cmsg_type = SCM_RIGHTS;
  cmsgptr->cmsg_len = sizeof cmsgbuf;
  send_msg.msg_control = cmsgbuf;
  send_msg.msg_controllen = sizeof cmsgbuf;
  *(ACE_HANDLE *) CMSG_DATA (cmsgptr) = handle;
  send_msg.msg_flags = 0 ;
#else
  send_msg.msg_accrights    = (char *) &handle;
  send_msg.msg_accrightslen = sizeof handle;
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */
  return ACE_OS::sendmsg (this->ACE_SOCK_Stream::get_handle (),
                          &send_msg, 0);
}
// Read a readv-style vector of buffers, along with an open I/O
// handle.
ssize_t
ACE_LSOCK_Stream::recv_msg (iovec iov[],
                            size_t n,
                            ACE_HANDLE &handle)
{
  ACE_TRACE ("ACE_LSOCK_Stream::recv_msg");
  msghdr recv_msg;
#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
  char cmsgbuf[ACE_BSD_CONTROL_MSG_LEN];
  cmsghdr *cmsgptr = (cmsghdr *) cmsgbuf;
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */
  recv_msg.msg_iov = (iovec *) iov;
  recv_msg.msg_iovlen = n;
  recv_msg.msg_name = 0;
  recv_msg.msg_namelen = 0;
#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
  recv_msg.msg_control = cmsgbuf;
  recv_msg.msg_controllen = sizeof cmsgbuf;
  ssize_t result = ACE_OS::recvmsg (this->ACE_SOCK_Stream::get_handle (),
                                    &recv_msg, 0);
  handle = *(ACE_HANDLE*) CMSG_DATA (cmsgptr) ;
  return result;
#else
  recv_msg.msg_accrights = (char *) &handle;
  recv_msg.msg_accrightslen = sizeof handle;
  return ACE_OS::recvmsg (this->ACE_SOCK_Stream::get_handle (),
                          &recv_msg, 0);
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */
}
#endif /* ACE_HAS_MSG */
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */

