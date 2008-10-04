// $Id: LSOCK.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/LSOCK.h"

ACE_RCSID(ace, LSOCK, "$Id: LSOCK.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)

#include "ace/Log_Msg.h"
#include "ace/OS_NS_sys_socket.h"

#if !defined (__ACE_INLINE__)
#include "ace/LSOCK.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_LSOCK)

void
ACE_LSOCK::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_LSOCK::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("aux_handle_ = %d"), this->aux_handle_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

#if defined (ACE_HAS_MSG)
// This routine sends an open file descriptor to <this->handle_>.

ssize_t
ACE_LSOCK::send_handle (const ACE_HANDLE handle) const
{
  ACE_TRACE ("ACE_LSOCK::send_handle");
  u_char a[2];
  iovec iov;
  msghdr send_msg;
#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
  char cmsgbuf[ACE_BSD_CONTROL_MSG_LEN];
  cmsghdr *cmsgptr = (cmsghdr *) cmsgbuf;
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */

  a[0] = 0xab;
  a[1] = 0xcd;
  iov.iov_base = (char *) a;
  iov.iov_len = sizeof a;
  send_msg.msg_iov = &iov;
  send_msg.msg_iovlen = 1;
  send_msg.msg_name = 0;
  send_msg.msg_namelen = 0;

#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
  cmsgptr->cmsg_level = SOL_SOCKET;
  cmsgptr->cmsg_type = SCM_RIGHTS;
  cmsgptr->cmsg_len = sizeof cmsgbuf;
  send_msg.msg_control = cmsgbuf;
  send_msg.msg_controllen = sizeof cmsgbuf;
  *(ACE_HANDLE *) CMSG_DATA (cmsgptr) = handle;
  send_msg.msg_flags = 0;
#else
  send_msg.msg_accrights = (char *) &handle;
  send_msg.msg_accrightslen = sizeof handle;
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */

  return ACE_OS::sendmsg (this->get_handle (), &send_msg, 0);
}

// This file receives an open file descriptor from <this->handle_>.
// Note, this routine returns -1 if problems occur, 0 if we recv a
// message that does not have file descriptor in it, and 1 otherwise.

ssize_t
ACE_LSOCK::recv_handle (ACE_HANDLE &handle, char *pbuf, ssize_t *len) const
{
  ACE_TRACE ("ACE_LSOCK::recv_handle");
  u_char a[2];
  iovec iov;
  msghdr recv_msg;

#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
  char cmsgbuf[ACE_BSD_CONTROL_MSG_LEN];
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */

  if (pbuf != 0 && len != 0)
    {
      iov.iov_base = pbuf;
      iov.iov_len  = *len;
    }
  else
    {
      iov.iov_base = (char *) a;
      iov.iov_len  = sizeof a;
    }

  recv_msg.msg_iov = &iov;
  recv_msg.msg_iovlen = 1;
  recv_msg.msg_name = 0;
  recv_msg.msg_namelen = 0;
#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
  recv_msg.msg_control = cmsgbuf;
  recv_msg.msg_controllen = sizeof cmsgbuf;
#else
  recv_msg.msg_accrights = (char *) &handle;
  recv_msg.msg_accrightslen = sizeof handle;
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */

#if defined (ACE_HAS_STREAMS)

  ssize_t nbytes = ACE_OS::recvmsg (this->get_handle (), &recv_msg, 0);

  if (nbytes != ACE_INVALID_HANDLE)
    {
      if (len != 0)
        *len = nbytes;

      if (nbytes == sizeof a
          && ((u_char *) iov.iov_base)[0] == 0xab
          && ((u_char *) iov.iov_base)[1] == 0xcd)
        {
#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
          cmsghdr *cmsgptr = (cmsghdr *) cmsgbuf;
          handle = *(ACE_HANDLE *) CMSG_DATA (cmsgptr);
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */
          return 1;
        }
      else
        return 0;
    }
#else
  ssize_t nbytes = ACE_OS::recvmsg (this->get_handle (),
                                    &recv_msg,
                                    MSG_PEEK);

  if (nbytes != ACE_INVALID_HANDLE)
    {
      if (nbytes == sizeof a
          && ((u_char *) iov.iov_base)[0] == 0xab
          && ((u_char *) iov.iov_base)[1] == 0xcd)
        {
#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
          // Close down the socket that was returned by the MSG_PEEK.
          ACE_OS::closesocket (*(ACE_HANDLE *) CMSG_DATA ((cmsghdr *) cmsgbuf));
          recv_msg.msg_control = cmsgbuf;
          recv_msg.msg_controllen = sizeof cmsgbuf;
#else
          recv_msg.msg_accrights = (char *) &handle;
          recv_msg.msg_accrightslen = sizeof handle;
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */

          if (ACE_OS::recvmsg (this->get_handle (),
                               &recv_msg, 0) == ACE_INVALID_HANDLE)
            return ACE_INVALID_HANDLE;
          else
            {
#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
              cmsghdr *cmsgptr = (cmsghdr *) cmsgbuf;
              handle = *(ACE_HANDLE *) CMSG_DATA (cmsgptr);
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */
              return 1;
            }
        }
      else
        {
          if (len != 0)
            *len = nbytes;
          return 0;
        }
    }
#endif /* ACE_HAS_STREAMS */
  else
    return ACE_INVALID_HANDLE;
}
#endif /* ACE_HAS_MSG */

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */
