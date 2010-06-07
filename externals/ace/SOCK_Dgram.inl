// -*- C++ -*-
//
// $Id: SOCK_Dgram.inl 80826 2008-03-04 14:51:23Z wotte $

// SOCK_Dgram.i

#include "ace/OS_NS_sys_socket.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Here's the simple-minded constructor.

ACE_INLINE
ACE_SOCK_Dgram::ACE_SOCK_Dgram (void)
{
  ACE_TRACE ("ACE_SOCK_Dgram::ACE_SOCK_Dgram");
}

ACE_INLINE
ACE_SOCK_Dgram::~ACE_SOCK_Dgram (void)
{
  ACE_TRACE ("ACE_SOCK_Dgram::~ACE_SOCK_Dgram");
}

// <sendto> an N byte datagram to <addr> (connectionless version).

ACE_INLINE ssize_t
ACE_SOCK_Dgram::send (const void *buf,
                      size_t n,
                      const ACE_Addr &addr,
                      int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::send");
  sockaddr *saddr = (sockaddr *) addr.get_addr ();
  int len = addr.get_size ();
  return ACE_OS::sendto (this->get_handle (),
                         (const char *) buf,
                         n,
                         flags,
                         (struct sockaddr *) saddr,
                         len);
}

// <recvfrom> an n byte datagram (connectionless version).

ACE_INLINE ssize_t
ACE_SOCK_Dgram::recv (void *buf,
                      size_t n,
                      ACE_Addr &addr,
                      int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::recv");
  sockaddr *saddr = (sockaddr *) addr.get_addr ();
  int addr_len = addr.get_size ();

  ssize_t const status = ACE_OS::recvfrom (this->get_handle (),
                                           (char *) buf,
                                           n,
                                           flags,
                                           (sockaddr *) saddr,
                                           &addr_len);
  addr.set_size (addr_len);
  addr.set_type (saddr->sa_family);
  return status;
}

ACE_INLINE ssize_t
ACE_SOCK_Dgram::send (const iovec buffers[],
                      int buffer_count,
                      size_t &number_of_bytes_sent,
                      int flags,
                      const ACE_Addr &addr,
                      ACE_OVERLAPPED *overlapped,
                      ACE_OVERLAPPED_COMPLETION_FUNC func) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::send");
  sockaddr *saddr = (sockaddr *) addr.get_addr ();
  int len = addr.get_size ();
  return ACE_OS::sendto (this->get_handle (),
                         buffers,
                         buffer_count,
                         number_of_bytes_sent,
                         flags,
                         (const sockaddr *) saddr,
                         len,
                         overlapped,
                         func);
}

ACE_INLINE ssize_t
ACE_SOCK_Dgram::recv (iovec buffers[],
                      int buffer_count,
                      size_t &number_of_bytes_recvd,
                      int &flags,
                      ACE_Addr &addr,
                      ACE_OVERLAPPED *overlapped,
                      ACE_OVERLAPPED_COMPLETION_FUNC func) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::recv");
  sockaddr *saddr = (sockaddr *) addr.get_addr ();
  int addr_len = addr.get_size ();

  ssize_t status = ACE_OS::recvfrom (this->get_handle (),
                                     buffers,
                                     buffer_count,
                                     number_of_bytes_recvd,
                                     flags,
                                     (sockaddr *) saddr,
                                     &addr_len,
                                     overlapped,
                                     func);
  addr.set_size (addr_len);
  addr.set_type (saddr->sa_family);
  return status;
}

// <sendto> an N byte datagram to <addr> (connectionless version).

ACE_INLINE ssize_t
ACE_SOCK_Dgram::send (const void *buf,
                      size_t n,
                      const ACE_Addr &addr,
                      int flags,
                      ACE_OVERLAPPED *overlapped,
                      ACE_OVERLAPPED_COMPLETION_FUNC func) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::send");

  iovec buffer[1];
  buffer[0].iov_len = static_cast<u_long> (n);  // Betting on < 4G
  buffer[0].iov_base = (char *) buf;
  size_t number_of_bytes_sent = 0;
  return this->send (buffer,
                     1,
                     number_of_bytes_sent,
                     flags,
                     addr,
                     overlapped,
                     func);
}

// <recvfrom> an n byte datagram (connectionless version).

ACE_INLINE ssize_t
ACE_SOCK_Dgram::recv (void *buf,
                      size_t n,
                      ACE_Addr &addr,
                      int flags,
                      ACE_OVERLAPPED *overlapped,
                      ACE_OVERLAPPED_COMPLETION_FUNC func) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::recv");

  iovec buffer[1];
  buffer[0].iov_len = static_cast<u_long> (n);  // Betting on < 4G
  buffer[0].iov_base = (char *) buf;
  size_t number_of_bytes_recvd = 0;
  return this->recv (buffer,
                     1,
                     number_of_bytes_recvd,
                     flags,
                     addr,
                     overlapped,
                     func);
}

ACE_END_VERSIONED_NAMESPACE_DECL
