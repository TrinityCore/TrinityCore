// -*- C++ -*-
//
// $Id: IOStream_T.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/Handle_Set.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_sys_select.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class STREAM> ACE_INLINE int
ACE_IOStream<STREAM>::eof (void) const
{
  // Get the timeout value of the streambuf
  ACE_Time_Value *timeout = this->streambuf_->recv_timeout (0);

  // Reset the timeout value of the streambuf.
  (void) this->streambuf_->recv_timeout (timeout);

  char c;
  int rval = this->streambuf_->recv_n (&c,
                                       sizeof c,
                                       MSG_PEEK,
                                       timeout);

  // Timeout, not an eof
  if (this->streambuf_->timeout())
    return 0;

  // No timeout, got enough data:  not eof
  if (rval == sizeof(char))
    return 0;

  // No timeout, not enough data:  definately eof
  return 1;
}

template <class STREAM> ACE_INLINE
ACE_SOCK_Dgram_SC<STREAM>::ACE_SOCK_Dgram_SC (void)
{
}

template <class STREAM> ACE_INLINE
ACE_SOCK_Dgram_SC<STREAM>::ACE_SOCK_Dgram_SC (STREAM &source,
                                              ACE_INET_Addr &dest)
  : STREAM (source),
    peer_ (dest)
{
}

template <class STREAM> ACE_INLINE ssize_t
ACE_SOCK_Dgram_SC<STREAM>::send_n (char *buf,
                                   ssize_t len)
{
  return STREAM::send (buf, len, peer_);
}

template <class STREAM> ACE_INLINE ssize_t
ACE_SOCK_Dgram_SC<STREAM>::recv (char *buf,
                                 ssize_t len,
                                 ACE_Time_Value *tv)
{
  //FUZZ: disable check_for_lack_ACE_OS
  return recv (buf, len, 0, tv);
  //FUZZ: enable check_for_lack_ACE_OS
}

template <class STREAM> ACE_INLINE ssize_t
ACE_SOCK_Dgram_SC<STREAM>::recv (char *buf,
                                 ssize_t len,
                                 int flags,
                                 ACE_Time_Value *tv)
{
  if (tv != 0)
    {
      ACE_HANDLE handle = this->get_handle ();
      ACE_Handle_Set handle_set;

      handle_set.set_bit (handle);

      switch (ACE_OS::select (int (handle) + 1,
                              (fd_set *) handle_set, // read_fds.
                              (fd_set *) 0,          // write_fds.
                              (fd_set *) 0,          // exception_fds.
                              tv))
        {
        case 0:
          errno = ETIME;
        case -1:
          return -1;
        default:
          ;     // Do the 'recv' below
        }
    }

  int rval = STREAM::recv (buf, len, peer_, flags);
#if defined (ACE_WIN32)
  if (rval == SOCKET_ERROR)
    if (::WSAGetLastError () == WSAEMSGSIZE)
      if (ACE_BIT_ENABLED (flags, MSG_PEEK))
        rval = len;
#endif /* ACE_WIN32 */
  return rval < len ? rval : len;
}

template <class STREAM> ACE_INLINE ssize_t
ACE_SOCK_Dgram_SC<STREAM>::recv_n (char *buf,
                                   ssize_t len,
                                   int flags,
                                   ACE_Time_Value *tv)
{
  int rval = this->recv (buf, len, flags, tv);
  return rval;
}

template <class STREAM> ACE_INLINE int
ACE_SOCK_Dgram_SC<STREAM>::get_remote_addr (ACE_INET_Addr &addr) const
{
  addr = peer_;
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
