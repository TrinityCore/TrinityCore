// -*- C++ -*-

//=============================================================================
/**
 *  @file    SOCK_Dgram.h
 *
 *  $Id: SOCK_Dgram.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SOCK_DGRAM_H
#define ACE_SOCK_DGRAM_H
#include /**/ "ace/pre.h"

#include "ace/SOCK.h"
#include "ace/INET_Addr.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Addr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;

/**
 * @class ACE_SOCK_Dgram
 *
 * @brief Defines the member functions for the ACE_SOCK datagram
 * abstraction.
 */
class ACE_Export ACE_SOCK_Dgram : public ACE_SOCK
{
public:
  // = Initialization and termination methods.
  /// Default constructor.
  ACE_SOCK_Dgram (void);

  /// This is a BSD-style method (i.e., no QoS) for initiating a socket
  /// dgram that will accept datagrams at the <local> address.
  ACE_SOCK_Dgram (const ACE_Addr &local,
                  int protocol_family = ACE_PROTOCOL_FAMILY_INET,
                  int protocol = 0,
                  int reuse_addr = 0);

  /**
   * This is a QoS-enabed method for initiating a socket dgram that
   * will accept datagrams at the <local> address.  The @a qos_params
   * are passed to <ACE_OS::join_leaf>.
   */
  ACE_SOCK_Dgram (const ACE_Addr &local,
                  int protocol_family,
                  int protocol,
                  ACE_Protocol_Info *protocolinfo,
                  ACE_SOCK_GROUP g = 0,
                  u_long flags = 0,
                  int reuse_addr = 0);

  /// This is a BSD-style method (i.e., no QoS) for initiating a socket
  /// dgram that will accept datagrams at the <local> address.
  int open (const ACE_Addr &local,
            int protocol_family = ACE_PROTOCOL_FAMILY_INET,
            int protocol = 0,
            int reuse_addr = 0);

  /**
   * This is a QoS-enabed method for initiating a socket dgram that
   * will accept datagrams at the <local> address.  The @a qos_params
   * are passed to <ACE_OS::join_leaf>.
   */
  int open (const ACE_Addr &local,
            int protocol_family,
            int protocol,
            ACE_Protocol_Info *protocolinfo,
            ACE_SOCK_GROUP g = 0,
            u_long flags = 0,
            int reuse_addr = 0);

  /// Default dtor.
  ~ACE_SOCK_Dgram (void);

  // = Data transfer routines.
  /// Send an @a n byte @a buf to the datagram socket (uses <sendto(3)>).
  ssize_t send (const void *buf,
                size_t n,
                const ACE_Addr &addr,
                int flags = 0) const;

  /// Receive an @a n byte @a buf from the datagram socket (uses
  /// <recvfrom(3)>).
  ssize_t recv (void *buf,
                size_t n,
                ACE_Addr &addr,
                int flags = 0) const;

  /**
   * Allows a client to read from a socket without having to provide a
   * buffer to read.  This method determines how much data is in the
   * socket, allocates a buffer of this size, reads in the data, and
   * returns the number of bytes read.  The caller is responsible for
   * deleting the member in the <iov_base> field of <io_vec> using the
   * ``delete []'' syntax.
   */
  ssize_t recv (iovec *io_vec,
                ACE_Addr &addr,
                int flags = 0,
                const ACE_Time_Value *timeout = 0) const;

  /// Send an <iovec> of size @a n to the datagram socket (uses
  /// <sendmsg(3)>).
  ssize_t send (const iovec iov[],
                int n,
                const ACE_Addr &addr,
                int flags = 0) const;

  /// Recv an <iovec> of size @a n to the datagram socket (uses
  /// <recvmsg(3)>).
  ssize_t recv (iovec iov[],
                int n,
                ACE_Addr &addr,
                int flags = 0) const;

  /**
   * Wait up to @a timeout amount of time to receive a datagram into
   * @a buf.  The ACE_Time_Value indicates how long to blocking
   * trying to receive.  If @a timeout == 0, the caller will block
   * until action is possible, else will wait until the relative time
   * specified in *@a timeout elapses).  If <recv> times out a -1 is
   * returned with @c errno == ETIME.  If it succeeds the number of
   * bytes received is returned.
   */
  ssize_t recv (void *buf,
                size_t n,
                ACE_Addr &addr,
                int flags,
                const ACE_Time_Value *timeout) const;

  /**
   * Wait up to @a timeout amount of time to send a datagram to
   * @a buf.  The ACE_Time_Value indicates how long to blocking
   * trying to receive.  If @a timeout == 0, the caller will block
   * until action is possible, else will wait until the relative time
   * specified in *@a timeout elapses).  If <send> times out a -1 is
   * returned with @c errno == ETIME.  If it succeeds the number of
   * bytes sent is returned.
   */
  ssize_t send (const void *buf,
                size_t n,
                const ACE_Addr &addr,
                int flags,
                const ACE_Time_Value *timeout) const;

  /// Send <buffer_count> worth of @a buffers to @a addr using overlapped
  /// I/O (uses <WSASendTo>).  Returns 0 on success.
  ssize_t send (const iovec buffers[],
                int buffer_count,
                size_t &number_of_bytes_sent,
                int flags,
                const ACE_Addr &addr,
                ACE_OVERLAPPED *overlapped,
                ACE_OVERLAPPED_COMPLETION_FUNC func) const;

  /// Recv <buffer_count> worth of @a buffers from @a addr using
  /// overlapped I/O (uses <WSARecvFrom>).  Returns 0 on success.
  ssize_t recv (iovec buffers[],
                int buffer_count,
                size_t &number_of_bytes_recvd,
                int &flags,
                ACE_Addr &addr,
                ACE_OVERLAPPED *overlapped,
                ACE_OVERLAPPED_COMPLETION_FUNC func) const;

  /// Send an @a n byte @a buf to the datagram socket (uses <WSASendTo>).
  ssize_t send (const void *buf,
                size_t n,
                const ACE_Addr &addr,
                int flags,
                ACE_OVERLAPPED *overlapped,
                ACE_OVERLAPPED_COMPLETION_FUNC func) const;

  /// Receive an @a n byte @a buf from the datagram socket (uses
  /// <WSARecvFrom>).
  ssize_t recv (void *buf,
                size_t n,
                ACE_Addr &addr,
                int flags,
                ACE_OVERLAPPED *overlapped,
                ACE_OVERLAPPED_COMPLETION_FUNC func) const;

  // = Meta-type info.
  typedef ACE_INET_Addr PEER_ADDR;

  /// Dump the state of an object.
  void dump (void) const;

  /// Set NIC to use as multicast interface.
  int set_nic (const ACE_TCHAR *net_if,
               int addr_family = AF_UNSPEC);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Open is shared by this and by <LSOCK_Dgram>.
  int shared_open (const ACE_Addr &local,
                   int protocol_family);

  /// Create a multicast addr/if pair, in format useful for system calls.
  /// If mreq param is NULL, just verify the passed addr/interface specs.
  int make_multicast_ifaddr (ip_mreq *mreq,     // Put result here, if != NULL.
                             const ACE_INET_Addr &mcast_addr,
                             const ACE_TCHAR *net_if);

#if defined (ACE_HAS_IPV6)
  /// Create a multicast addr/if pair, in format useful for system calls.
  /// If mreq param is NULL, just verify the passed addr/interface specs.
  int make_multicast_ifaddr6 (ipv6_mreq *mreq,   // Put result here, if != NULL.
                              const ACE_INET_Addr &mcast_addr,
                              const ACE_TCHAR *net_if);

#endif /* ACE_HAS_IPV6 */

private:
  /// Do not allow this function to percolate up to this interface...
  int  get_remote_addr (ACE_Addr &) const;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/SOCK_Dgram.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SOCK_DGRAM_H */

