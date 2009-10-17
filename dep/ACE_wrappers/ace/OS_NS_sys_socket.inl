// -*- C++ -*-
//
// $Id: OS_NS_sys_socket.inl 82342 2008-07-17 19:52:57Z shuston $

#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_macros.h"
#include "ace/OS_NS_sys_uio.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_QoS.h"
#include "ace/Global_Macros.h"
#include "ace/os_include/netinet/os_in.h"

#if defined (ACE_GETNAME_RETURNS_RANDOM_SIN_ZERO) \
         && (ACE_GETNAME_RETURNS_RANDOM_SIN_ZERO == 1)
#include "ace/OS_NS_string.h"
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_HAS_VOIDPTR_SOCKOPT)
typedef void *ACE_SOCKOPT_TYPE1;
#elif defined (ACE_HAS_CHARPTR_SOCKOPT)
typedef char *ACE_SOCKOPT_TYPE1;
#else
typedef const char *ACE_SOCKOPT_TYPE1;
#endif /* ACE_HAS_VOIDPTR_SOCKOPT */

ACE_INLINE ACE_HANDLE
ACE_OS::accept (ACE_HANDLE handle,
                struct sockaddr *addr,
                int *addrlen)
{
  ACE_OS_TRACE ("ACE_OS::accept");
  // On a non-blocking socket with no connections to accept, this
  // system call will return EWOULDBLOCK or EAGAIN, depending on the
  // platform.  UNIX 98 allows either errno, and they may be the same
  // numeric value.  So to make life easier for upper ACE layers as
  // well as application programmers, always change EAGAIN to
  // EWOULDBLOCK.  Rather than hack the ACE_OSCALL_RETURN macro, it's
  // handled explicitly here.  If the ACE_OSCALL macro ever changes,
  // this function needs to be reviewed.  On Win32, the regular macros
  // can be used, as this is not an issue.

#if defined (ACE_LACKS_ACCEPT)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (addrlen);
  ACE_NOTSUP_RETURN (ACE_INVALID_HANDLE);
#elif defined (ACE_WIN32)
  ACE_SOCKCALL_RETURN (::accept ((ACE_SOCKET) handle,
                                 addr,
                                 (ACE_SOCKET_LEN *) addrlen),
                       ACE_HANDLE,
                       ACE_INVALID_HANDLE);
#else
#  if defined (ACE_HAS_BROKEN_ACCEPT_ADDR)
  // Apparently some platforms like VxWorks can't correctly deal with
  // a NULL addr.

   sockaddr_in fake_addr;
   int fake_addrlen;

   if (addrlen == 0)
     addrlen = &fake_addrlen;

   if (addr == 0)
     {
       addr = (sockaddr *) &fake_addr;
       *addrlen = sizeof fake_addr;
     }
#  endif /* ACE_HAS_BROKEN_ACCEPT_ADDR */
  ACE_HANDLE ace_result = ::accept ((ACE_SOCKET) handle,
                                    addr,
                                    (ACE_SOCKET_LEN *) addrlen);

# if !(defined (EAGAIN) && defined (EWOULDBLOCK) && EAGAIN == EWOULDBLOCK)
  // Optimize this code out if we can detect that EAGAIN ==
  // EWOULDBLOCK at compile time.  If we cannot detect equality at
  // compile-time (e.g. if EAGAIN or EWOULDBLOCK are not preprocessor
  // macros) perform the check at run-time.  The goal is to avoid two
  // TSS accesses in the _REENTRANT case when EAGAIN == EWOULDBLOCK.
  if (ace_result == ACE_INVALID_HANDLE
#  if !defined (EAGAIN) || !defined (EWOULDBLOCK)
      && EAGAIN != EWOULDBLOCK
#  endif  /* !EAGAIN || !EWOULDBLOCK */
      && errno == EAGAIN)
    {
      errno = EWOULDBLOCK;
    }
# endif /* EAGAIN != EWOULDBLOCK*/

  return ace_result;

#endif /* defined (ACE_WIN32) */
}

ACE_INLINE int
ACE_OS::bind (ACE_HANDLE handle, struct sockaddr *addr, int addrlen)
{
  ACE_OS_TRACE ("ACE_OS::bind");
#if defined (ACE_LACKS_BIND)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (addrlen);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_VXWORKS) && (ACE_VXWORKS <= 0x640)
  // VxWorks clears the sin_port member after a succesfull bind when
  // sin_addr != INADDR_ANY, so after the bind we do retrieve the
  // original address so that user code can safely check the addr
  // after the bind. See bugzilla 3107 for more details
  int result;
  ACE_SOCKCALL (::bind ((ACE_SOCKET) handle,
                        addr,
                        (ACE_SOCKET_LEN) addrlen), int, -1, result);
  if (result == -1)
    return -1;
  else
    return ACE_OS::getsockname (handle, addr, &addrlen);
#else
  ACE_SOCKCALL_RETURN (::bind ((ACE_SOCKET) handle,
                               addr,
                               (ACE_SOCKET_LEN) addrlen), int, -1);
#endif
}

ACE_INLINE int
ACE_OS::closesocket (ACE_HANDLE handle)
{
  ACE_OS_TRACE ("ACE_OS::closesocket");
#if defined (ACE_WIN32)
  // @note Do not shutdown the write end here.  Doing so will break
  //       applications that duplicate a handle on fork(), for
  //       example, and expect to continue writing in the fork()ed
  //       process.

  ACE_SOCKCALL_RETURN (::closesocket ((SOCKET) handle), int, -1);
#else
  //FUZZ: disable check_for_lack_ACE_OS
  ACE_OSCALL_RETURN (::close (handle), int, -1);
  //FUZZ: enable check_for_lack_ACE_OS
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::connect (ACE_HANDLE handle,
                 struct sockaddr *addr,
                 int addrlen)
{
  ACE_OS_TRACE ("ACE_OS::connect");
#if defined (ACE_LACKS_CONNECT)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (addrlen);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_SOCKCALL_RETURN (::connect ((ACE_SOCKET) handle,
                                  addr,
                                  (ACE_SOCKET_LEN) addrlen), int, -1);
#endif /* ACE_LACKS_CONNECT */
}

ACE_INLINE int
ACE_OS::enum_protocols (int *protocols,
                        ACE_Protocol_Info *protocol_buffer,
                        u_long *buffer_length)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)

  ACE_SOCKCALL_RETURN (::WSAEnumProtocols (protocols,
                                           protocol_buffer,
                                           buffer_length),
                       int,
                       SOCKET_ERROR);

#else
  ACE_UNUSED_ARG (protocols);
  ACE_UNUSED_ARG (protocol_buffer);
  ACE_UNUSED_ARG (buffer_length);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE int
ACE_OS::getpeername (ACE_HANDLE handle, struct sockaddr *addr,
                     int *addrlen)
{
  ACE_OS_TRACE ("ACE_OS::getpeername");

#if defined (ACE_LACKS_GETPEERNAME)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (addrlen);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_GETNAME_RETURNS_RANDOM_SIN_ZERO) \
           && (ACE_GETNAME_RETURNS_RANDOM_SIN_ZERO == 1)
  int result;
  ACE_SOCKCALL (::getpeername ((ACE_SOCKET) handle,
                               addr,
                               (ACE_SOCKET_LEN *) addrlen),
               int,
                -1,
                result);

  // Some platforms, like older versions of the Linux kernel, do not
  // initialize the sin_zero field since that field is generally only
  // used for padding/alignment purposes.  On those platforms
  // memcmp()-based comparisons of the sockaddr_in structure, such as
  // the one in the ACE_INET_Addr equality operator, may fail due to
  // random bytes in the sin_zero field even though that field is
  // unused.  Prevent equality comparison of two different sockaddr_in
  // instances that refer to the same socket from failing by
  // explicitly initializing the sockaddr_in::sin_zero field to a
  // consistent value, e.g. zero.
  if (result != -1 && addr->sa_family == AF_INET)
    {
      ACE_OS::memset (reinterpret_cast<struct sockaddr_in *> (addr)->sin_zero,
                      0,
                      sizeof (reinterpret_cast<struct sockaddr_in *> (addr)->sin_zero));
    }

  return result;
#else
  ACE_SOCKCALL_RETURN (::getpeername ((ACE_SOCKET) handle,
                                      addr,
                                      (ACE_SOCKET_LEN *) addrlen),
                       int,
                       -1);
#endif /* ACE_GETNAME_RETURNS_RANDOM_SIN_ZERO */
}

ACE_INLINE int
ACE_OS::getsockname (ACE_HANDLE handle,
                     struct sockaddr *addr,
                     int *addrlen)
{
  ACE_OS_TRACE ("ACE_OS::getsockname");
#if defined (ACE_LACKS_GETSOCKNAME)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (addrlen);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_GETNAME_RETURNS_RANDOM_SIN_ZERO) \
           && (ACE_GETNAME_RETURNS_RANDOM_SIN_ZERO == 1)
  int result;
  ACE_SOCKCALL (::getsockname ((ACE_SOCKET) handle,
                               addr,
                               (ACE_SOCKET_LEN *) addrlen),
               int, -1, result);

  // Some platforms, like older versions of the Linux kernel, do not
  // initialize the sin_zero field since that field is generally only
  // used for padding/alignment purposes.  On those platforms
  // memcmp()-based comparisons of the sockaddr_in structure, such as
  // the one in the ACE_INET_Addr equality operator, may fail due to
  // random bytes in the sin_zero field even though that field is
  // unused.  Prevent equality comparison of two different sockaddr_in
  // instances that refer to the same socket from failing by
  // explicitly initializing the sockaddr_in::sin_zero field to a
  // consistent value, e.g. zero.
  if (result != -1 && addr->sa_family == AF_INET)
    {
      ACE_OS::memset (reinterpret_cast<struct sockaddr_in *> (addr)->sin_zero,
                      0,
                      sizeof (reinterpret_cast<struct sockaddr_in *> (addr)->sin_zero));
    }

  return result;
#else
  ACE_SOCKCALL_RETURN (::getsockname ((ACE_SOCKET) handle,
                                      addr,
                                      (ACE_SOCKET_LEN *) addrlen),
                       int, -1);
#endif /* ACE_GETNAME_RETURNS_RANDOM_SIN_ZERO */
}

ACE_INLINE int
ACE_OS::getsockopt (ACE_HANDLE handle,
                    int level,
                    int optname,
                    char *optval,
                    int *optlen)
{
  ACE_OS_TRACE ("ACE_OS::getsockopt");
#if defined (ACE_LACKS_GETSOCKOPT)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (level);
  ACE_UNUSED_ARG (optname);
  ACE_UNUSED_ARG (optval);
  ACE_UNUSED_ARG (optlen);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_SOCKCALL_RETURN (::getsockopt ((ACE_SOCKET) handle,
                                     level,
                                     optname,
                                     optval,
                                     (ACE_SOCKET_LEN *) optlen),
                       int,
                       -1);
#endif /* ACE_LACKS_GETSOCKOPT */
}

ACE_INLINE int
ACE_OS::listen (ACE_HANDLE handle, int backlog)
{
  ACE_OS_TRACE ("ACE_OS::listen");
#if defined (ACE_LACKS_LISTEN)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (backlog);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_SOCKCALL_RETURN (::listen ((ACE_SOCKET) handle, backlog), int, -1);
#endif /* ACE_LACKS_LISTEN */
}

ACE_INLINE ssize_t
ACE_OS::recv (ACE_HANDLE handle, char *buf, size_t len, int flags)
{
  ACE_OS_TRACE ("ACE_OS::recv");

  // On UNIX, a non-blocking socket with no data to receive, this
  // system call will return EWOULDBLOCK or EAGAIN, depending on the
  // platform.  UNIX 98 allows either errno, and they may be the same
  // numeric value.  So to make life easier for upper ACE layers as
  // well as application programmers, always change EAGAIN to
  // EWOULDBLOCK.  Rather than hack the ACE_OSCALL_RETURN macro, it's
  // handled explicitly here.  If the ACE_OSCALL macro ever changes,
  // this function needs to be reviewed.  On Win32, the regular macros
  // can be used, as this is not an issue.
#if defined (ACE_LACKS_RECV)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (flags);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32)
  ACE_SOCKCALL_RETURN (::recv ((ACE_SOCKET) handle, buf,
                               static_cast<int> (len), flags), ssize_t, -1);
#else
  ssize_t ace_result_;
  ace_result_ = ::recv ((ACE_SOCKET) handle, buf, len, flags);

# if !(defined (EAGAIN) && defined (EWOULDBLOCK) && EAGAIN == EWOULDBLOCK)
  // Optimize this code out if we can detect that EAGAIN ==
  // EWOULDBLOCK at compile time.  If we cannot detect equality at
  // compile-time (e.g. if EAGAIN or EWOULDBLOCK are not preprocessor
  // macros) perform the check at run-time.  The goal is to avoid two
  // TSS accesses in the _REENTRANT case when EAGAIN == EWOULDBLOCK.
  if (ace_result_ == -1
#  if !defined (EAGAIN) || !defined (EWOULDBLOCK)
      && EAGAIN != EWOULDBLOCK
#  endif  /* !EAGAIN || !EWOULDBLOCK */
      && errno == EAGAIN)
    {
      errno = EWOULDBLOCK;
    }
# endif /* EAGAIN != EWOULDBLOCK*/

  return ace_result_;
#endif /* ACE_LACKS_RECV */
}

ACE_INLINE ssize_t
ACE_OS::recvfrom (ACE_HANDLE handle,
                  char *buf,
                  size_t len,
                  int flags,
                  struct sockaddr *addr,
                  int *addrlen)
{
  ACE_OS_TRACE ("ACE_OS::recvfrom");
#if defined (ACE_LACKS_RECVFROM)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (addrlen);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32)
  int const shortened_len = static_cast<int> (len);
  int const result = ::recvfrom ((ACE_SOCKET) handle,
                                 buf,
                                 shortened_len,
                                 flags,
                                 addr,
                                 (ACE_SOCKET_LEN *) addrlen);
  if (result == SOCKET_ERROR)
    {
      ACE_OS::set_errno_to_wsa_last_error ();
      if (errno == WSAEMSGSIZE &&
          ACE_BIT_ENABLED (flags, MSG_PEEK))
        return shortened_len;
      else
        return -1;
    }
  else
    {
#  if defined (ACE_HAS_PHARLAP)
      // Pharlap ETS (at least to v13) returns a legit address but doesn't
      // include the sin_zero[8] bytes in the count. Correct for this here.
      if (addrlen != 0 && addr != 0 &&
          *addrlen == 8 && addr->sa_family == AF_INET)
        *addrlen = sizeof(sockaddr_in);
#  endif /* ACE_HAS_PHARLAP */
      return result;
    }
#else /* non Win32 */
  ACE_SOCKCALL_RETURN (::recvfrom ((ACE_SOCKET) handle,
                                   buf,
                                   len,
                                   flags,
                                   addr,
                                   (ACE_SOCKET_LEN *) addrlen),
                       ssize_t, -1);
#endif /* ACE_LACKS_RECVFROM */
}

ACE_INLINE ssize_t
ACE_OS::recvfrom (ACE_HANDLE handle,
                  iovec *buffers,
                  int buffer_count,
                  size_t &number_of_bytes_recvd,
                  int &flags,
                  struct sockaddr *addr,
                  int *addrlen,
                  ACE_OVERLAPPED *overlapped,
                  ACE_OVERLAPPED_COMPLETION_FUNC func)
{
  ACE_OS_TRACE ("ACE_OS::recvfrom");

#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  DWORD bytes_recvd;
  DWORD the_flags = flags;
  int result = ::WSARecvFrom ((SOCKET) handle,
                              (WSABUF*)buffers,
                              buffer_count,
                              &bytes_recvd,
                              &the_flags,
                              addr,
                              addrlen,
                              overlapped,
                              func);
  if (result != 0) {
    ACE_OS::set_errno_to_wsa_last_error ();
  }
  flags = the_flags;
  number_of_bytes_recvd = static_cast<size_t> (bytes_recvd);
  return result;
#else
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (buffers);
  ACE_UNUSED_ARG (buffer_count);
  ACE_UNUSED_ARG (number_of_bytes_recvd);
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (addrlen);
  ACE_UNUSED_ARG (overlapped);
  ACE_UNUSED_ARG (func);
  ACE_NOTSUP_RETURN (-1);
#endif /* defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) */
}

ACE_INLINE ssize_t
ACE_OS::recvmsg (ACE_HANDLE handle, struct msghdr *msg, int flags)
{
  ACE_OS_TRACE ("ACE_OS::recvmsg");
#if !defined (ACE_LACKS_RECVMSG)
# if (defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0))
  DWORD bytes_received = 0;

  int result = ::WSARecvFrom ((SOCKET) handle,
                              (WSABUF *) msg->msg_iov,
                              msg->msg_iovlen,
                              &bytes_received,
                              (DWORD *) &flags,
                              msg->msg_name,
                              &msg->msg_namelen,
                              0,
                              0);

  if (result != 0)
    {
      ACE_OS::set_errno_to_wsa_last_error ();
      return -1;
    }
  else
    return bytes_received;
# else /* ACE_HAS_WINSOCK2 */
  ACE_SOCKCALL_RETURN (::recvmsg (handle, msg, flags), ssize_t, -1);
# endif /* ACE_HAS_WINSOCK2 */
#else
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (msg);
  ACE_UNUSED_ARG (handle);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_LACKS_RECVMSG */
}

ACE_INLINE ssize_t
ACE_OS::recvv (ACE_HANDLE handle,
               iovec *buffers,
               int n)
{
#if defined (ACE_HAS_WINSOCK2)

  DWORD bytes_received = 0;
  int result = 1;

  // Winsock 2 has WSARecv and can do this directly, but Winsock 1 needs
  // to do the recvs piece-by-piece.

# if (ACE_HAS_WINSOCK2 != 0)
  DWORD flags = 0;
  result = ::WSARecv ((SOCKET) handle,
                      (WSABUF *) buffers,
                      n,
                      &bytes_received,
                      &flags,
                      0,
                      0);
# else
  int i, chunklen;
  char *chunkp = 0;

  // Step through the buffers requested by caller; for each one, cycle
  // through reads until it's filled or an error occurs.
  for (i = 0; i < n && result > 0; ++i)
    {
      chunkp = buffers[i].iov_base;     // Point to part of chunk being read
      chunklen = buffers[i].iov_len;    // Track how much to read to chunk
      while (chunklen > 0 && result > 0)
        {
          result = ::recv ((SOCKET) handle, chunkp, chunklen, 0);
          if (result > 0)
            {
              chunkp += result;
              chunklen -= result;
              bytes_received += result;
            }
        }
    }
# endif /* ACE_HAS_WINSOCK2 != 0 */

  if (result == SOCKET_ERROR)
    {
      ACE_OS::set_errno_to_wsa_last_error ();
      return -1;
    }
  else
    return (ssize_t) bytes_received;
#else
  return ACE_OS::readv (handle, buffers, n);
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE ssize_t
ACE_OS::send (ACE_HANDLE handle, const char *buf, size_t len, int flags)
{
  ACE_OS_TRACE ("ACE_OS::send");

  // On UNIX, a non-blocking socket with no data to receive, this
  // system call will return EWOULDBLOCK or EAGAIN, depending on the
  // platform.  UNIX 98 allows either errno, and they may be the same
  // numeric value.  So to make life easier for upper ACE layers as
  // well as application programmers, always change EAGAIN to
  // EWOULDBLOCK.  Rather than hack the ACE_OSCALL_RETURN macro, it's
  // handled explicitly here.  If the ACE_OSCALL macro ever changes,
  // this function needs to be reviewed.  On Win32, the regular macros
  // can be used, as this is not an issue.
#if defined (ACE_LACKS_SEND)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (flags);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32)
  ACE_SOCKCALL_RETURN (::send ((ACE_SOCKET) handle,
                               buf,
                               static_cast<int> (len),
                               flags), ssize_t, -1);
#else
  ssize_t const ace_result_ = ::send ((ACE_SOCKET) handle, buf, len, flags);

# if !(defined (EAGAIN) && defined (EWOULDBLOCK) && EAGAIN == EWOULDBLOCK)
  // Optimize this code out if we can detect that EAGAIN ==
  // EWOULDBLOCK at compile time.  If we cannot detect equality at
  // compile-time (e.g. if EAGAIN or EWOULDBLOCK are not preprocessor
  // macros) perform the check at run-time.  The goal is to avoid two
  // TSS accesses in the _REENTRANT case when EAGAIN == EWOULDBLOCK.
  if (ace_result_ == -1
#  if !defined (EAGAIN) || !defined (EWOULDBLOCK)
      && EAGAIN != EWOULDBLOCK
#  endif  /* !EAGAIN || !EWOULDBLOCK */
      && errno == EAGAIN)
    {
      errno = EWOULDBLOCK;
    }
# endif /* EAGAIN != EWOULDBLOCK*/

  return ace_result_;
#endif /* defined (ACE_WIN32) */
}

ACE_INLINE ssize_t
ACE_OS::sendmsg (ACE_HANDLE handle,
                 const struct msghdr *msg,
                 int flags)
{
  ACE_OS_TRACE ("ACE_OS::sendmsg");
#if !defined (ACE_LACKS_SENDMSG)
# if (defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0))
  DWORD bytes_sent = 0;
  int result = ::WSASendTo ((SOCKET) handle,
                            (WSABUF *) msg->msg_iov,
                            msg->msg_iovlen,
                            &bytes_sent,
                            flags,
                            msg->msg_name,
                            msg->msg_namelen,
                            0,
                            0);

  if (result != 0)
    {
      ACE_OS::set_errno_to_wsa_last_error ();
      return -1;
    }
  else
    return (ssize_t) bytes_sent;
# elif defined (ACE_HAS_NONCONST_SENDMSG)
  ACE_SOCKCALL_RETURN (::sendmsg (handle,
                                  const_cast<struct msghdr *>(msg),
                                  flags), ssize_t, -1);
# else
  ACE_SOCKCALL_RETURN (::sendmsg (handle, msg, flags), ssize_t, -1);
# endif
#else
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (msg);
  ACE_UNUSED_ARG (handle);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_LACKS_SENDMSG */
}

ACE_INLINE ssize_t
ACE_OS::sendto (ACE_HANDLE handle,
                const char *buf,
                size_t len,
                int flags,
                const struct sockaddr *addr,
                int addrlen)
{
  ACE_OS_TRACE ("ACE_OS::sendto");
#if defined (ACE_LACKS_SENDTO)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (addrlen);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_VXWORKS)
  ACE_SOCKCALL_RETURN (::sendto ((ACE_SOCKET) handle,
                                 const_cast <char *> (buf),
                                 len,
                                 flags,
                                 const_cast<struct sockaddr *> (addr),
                                 addrlen),
                       ssize_t, -1);
#elif defined (ACE_WIN32)
  ACE_SOCKCALL_RETURN (::sendto ((ACE_SOCKET) handle,
                                 buf,
                                 static_cast<int> (len),
                                 flags,
                                 const_cast<struct sockaddr *> (addr),
                                 addrlen),
                       ssize_t, -1);
#else
  ACE_SOCKCALL_RETURN (::sendto ((ACE_SOCKET) handle,
                                 buf,
                                 len,
                                 flags,
                                 const_cast<struct sockaddr *> (addr),
                                 addrlen),
                       ssize_t, -1);
#endif /* ACE_LACKS_SENDTO */
}

ACE_INLINE ssize_t
ACE_OS::sendto (ACE_HANDLE handle,
                const iovec *buffers,
                int buffer_count,
                size_t &number_of_bytes_sent,
                int flags,
                const struct sockaddr *addr,
                int addrlen,
                ACE_OVERLAPPED *overlapped,
                ACE_OVERLAPPED_COMPLETION_FUNC func)
{
  ACE_OS_TRACE ("ACE_OS::sendto");
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  DWORD bytes_sent = 0;
  int result = ::WSASendTo ((SOCKET) handle,
                            (WSABUF*) buffers,
                            buffer_count,
                            &bytes_sent,
                            flags,
                            addr,
                            addrlen,
                            overlapped,
                            func);
  if (result != 0) {
    ACE_OS::set_errno_to_wsa_last_error ();
  }
  number_of_bytes_sent = static_cast<size_t> (bytes_sent);
  return (ssize_t) result;
#else
  ACE_UNUSED_ARG (overlapped);
  ACE_UNUSED_ARG (func);

  number_of_bytes_sent = 0;

  ssize_t result = 0;

  for (int i = 0; i < buffer_count; ++i)
    {
       result = ACE_OS::sendto (handle,
                                reinterpret_cast<char *> (
                                                 buffers[i].iov_base),
                                buffers[i].iov_len,
                                flags,
                                addr,
                                addrlen);
       if (result == -1)
         break;
       number_of_bytes_sent += static_cast<size_t> (result);
    }

  return result;
#endif /* defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) */
}

ACE_INLINE ssize_t
ACE_OS::sendv (ACE_HANDLE handle,
               const iovec *buffers,
               int n)
{
#if defined (ACE_HAS_WINSOCK2)
  DWORD bytes_sent = 0;
  ssize_t result = 0;

  // Winsock 2 has WSASend and can do this directly, but Winsock 1
  // needs to do the sends one-by-one.
# if (ACE_HAS_WINSOCK2 != 0)
  result = ::WSASend ((SOCKET) handle,
                      (WSABUF *) buffers,
                      n,
                      &bytes_sent,
                      0,
                      0,
                      0);
  if (result == SOCKET_ERROR)
    {
      ACE_OS::set_errno_to_wsa_last_error ();
      return -1;
    }
# else
  for (int i = 0; i < n; ++i)
    {
      result = ::send ((SOCKET) handle,
                       buffers[i].iov_base,
                       buffers[i].iov_len,
                       0);

      if (result == SOCKET_ERROR)
        {
          // There is a subtle difference in behaviour depending on
          // whether or not any data was sent.  If no data was sent,
          // then always return -1.  Otherwise return bytes_sent.
          // This gives the caller an opportunity to keep track of
          // bytes that have already been sent.
          if (bytes_sent > 0)
            break;
          else
            {
              ACE_OS::set_errno_to_wsa_last_error ();
              return -1;
            }
        }
      else
        {
          // Gets ignored on error anyway
          bytes_sent += result;

          // If the transfer isn't complete just drop out of the loop.
          if (result < (int)buffers[i].iov_len)
            break;
        }
    }
# endif /* ACE_HAS_WINSOCK2 != 0 */

  return (ssize_t) bytes_sent;

#elif defined (ACE_HAS_SOCK_BUF_SIZE_MAX)

  // Platform limits the maximum socket message size.  Pare down the
  // iovec, if necessary, to obey the limit.
  iovec local_iov[ACE_IOV_MAX];
  long total = 0;
  long new_total = 0;
  for (int i = 0; i < n; i++)
    {
      local_iov[i].iov_base = buffers[i].iov_base;
      local_iov[i].iov_len  = buffers[i].iov_len;

      new_total = total + buffers[i].iov_len;
      if (new_total >= ACE_HAS_SOCK_BUF_SIZE_MAX_VALUE)
        {
          local_iov[i].iov_len = ACE_HAS_SOCK_BUF_SIZE_MAX_VALUE - total;
          n = i+1;
          break;
        }
      total = new_total;
    }
  return ACE_OS::writev (handle, local_iov, n);

#else
  return ACE_OS::writev (handle, buffers, n);
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE int
ACE_OS::setsockopt (ACE_HANDLE handle,
                    int level,
                    int optname,
                    const char *optval,
                    int optlen)
{
  ACE_OS_TRACE ("ACE_OS::setsockopt");
#if defined (ACE_LACKS_SETSOCKOPT)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (level);
  ACE_UNUSED_ARG (optname);
  ACE_UNUSED_ARG (optval);
  ACE_UNUSED_ARG (optlen);
  ACE_NOTSUP_RETURN (-1);
#else
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && defined(SO_REUSEPORT)
  // To work around an inconsistency with Microsofts implementation of
  // sockets, we will check for SO_REUSEADDR, and ignore it. Winsock
  // always behaves as if SO_REUSEADDR=1. Some implementations have
  // the same behaviour as Winsock, but use a new name for
  // it. SO_REUSEPORT.  If you want the normal behaviour for
  // SO_REUSEADDR=0, then NT 4 sp4 and later supports
  // SO_EXCLUSIVEADDRUSE. This also requires using an updated Platform
  // SDK so it was decided to ignore the option for now. (Especially
  // since Windows always sets SO_REUSEADDR=1, which we can mimic by doing
  // nothing.)
  if (level == SOL_SOCKET) {
    if (optname == SO_REUSEADDR) {
      return 0; // Not supported by Winsock
    }
    if (optname == SO_REUSEPORT) {
      optname = SO_REUSEADDR;
    }
  }
#endif /*ACE_HAS_WINSOCK2*/

  int result;
  ACE_SOCKCALL (::setsockopt ((ACE_SOCKET) handle,
                              level,
                              optname,
                              (ACE_SOCKOPT_TYPE1) optval,
                              optlen),
                int,
                -1,
                result);
#if defined (WSAEOPNOTSUPP)
  if (result == -1 && errno == WSAEOPNOTSUPP)
#else
  if (result == -1)
#endif /* WSAEOPNOTSUPP */
    errno = ENOTSUP;
  return result;
#endif
}

ACE_INLINE int
ACE_OS::shutdown (ACE_HANDLE handle, int how)
{
  ACE_OS_TRACE ("ACE_OS::shutdown");
#if defined (ACE_LACKS_SHUTDOWN)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (how);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_SOCKCALL_RETURN (::shutdown ((ACE_SOCKET) handle, how), int, -1);
#endif /* ACE_LACKS_SHUTDOWN */
}

ACE_INLINE ACE_HANDLE
ACE_OS::socket (int domain,
                int type,
                int proto)
{
  ACE_OS_TRACE ("ACE_OS::socket");
#if defined (ACE_LACKS_SOCKET)
  ACE_UNUSED_ARG (domain);
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (proto);
  ACE_NOTSUP_RETURN (ACE_INVALID_HANDLE);
#else
  ACE_SOCKCALL_RETURN (::socket (domain,
                                 type,
                                 proto),
                       ACE_HANDLE,
                       ACE_INVALID_HANDLE);
#endif /* ACE_LACKS_SOCKET */
}

ACE_INLINE ACE_HANDLE
ACE_OS::socket (int domain,
                int type,
                int proto,
                ACE_Protocol_Info *protocolinfo,
                ACE_SOCK_GROUP g,
                u_long flags)
{
  ACE_OS_TRACE ("ACE_OS::socket");

#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  ACE_SOCKCALL_RETURN (::WSASocket (domain,
                                    type,
                                    proto,
                                    protocolinfo,
                                    g,
                                    flags),
                       ACE_HANDLE,
                       ACE_INVALID_HANDLE);
#else
  ACE_UNUSED_ARG (protocolinfo);
  ACE_UNUSED_ARG (g);
  ACE_UNUSED_ARG (flags);

  return ACE_OS::socket (domain,
                         type,
                         proto);
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE int
ACE_OS::socketpair (int domain, int type,
                    int protocol, ACE_HANDLE sv[2])
{
  ACE_OS_TRACE ("ACE_OS::socketpair");
#if defined (ACE_LACKS_SOCKETPAIR)
  ACE_UNUSED_ARG (domain);
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (protocol);
  ACE_UNUSED_ARG (sv);

  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::socketpair (domain, type, protocol, sv),
                     int, -1);
#endif /* ACE_LACKS_SOCKETPAIR */
}

#if defined (__linux__) && defined (ACE_HAS_IPV6)
ACE_INLINE unsigned int
ACE_OS::if_nametoindex (const char *ifname)
{
  ACE_OS_TRACE ("ACE_OS::if_nametoindex");
  ACE_OSCALL_RETURN (::if_nametoindex (ifname), int, 0);
}

ACE_INLINE char *
ACE_OS::if_indextoname (unsigned int ifindex, char *ifname)
{
  ACE_OS_TRACE ("ACE_OS::if_indextoname");
  ACE_OSCALL_RETURN (::if_indextoname (ifindex, ifname), char *, 0);
}

ACE_INLINE struct if_nameindex *
ACE_OS::if_nameindex (void)
{
  ACE_OS_TRACE ("ACE_OS::if_nameindex");
  ACE_OSCALL_RETURN (::if_nameindex (), struct if_nameindex *, 0);
}

ACE_INLINE void
ACE_OS::if_freenameindex (struct if_nameindex *ptr)
{
  ACE_OS_TRACE ("ACE_OS::if_freenameindex");
  if (ptr != 0)
    ::if_freenameindex (ptr);
}
#endif /* __linux__ && ACE_HAS_IPV6 */

ACE_END_VERSIONED_NAMESPACE_DECL
