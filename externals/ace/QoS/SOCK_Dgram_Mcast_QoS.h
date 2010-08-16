// -*- C++ -*-

//=============================================================================
/**
 *  @file    SOCK_Dgram_Mcast_QoS.h
 *
 *  $Id: SOCK_Dgram_Mcast_QoS.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Vishal Kachroo <vishal@cs.wustl.edu>
 */
//=============================================================================


#ifndef ACE_SOCK_DGRAM_MCAST_QOS_H
#define ACE_SOCK_DGRAM_MCAST_QOS_H
#include /**/ "ace/pre.h"

#include "ace/SOCK_Dgram_Mcast.h"
#include "QoS_Manager.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_SOCK_Dgram_Mcast_QoS
 *
 * @brief Defines the member functions for the ACE QoS enabled socket
 * wrapper for UDP/IP multicast.
 */
class ACE_QoS_Export ACE_SOCK_Dgram_Mcast_QoS : public ACE_SOCK_Dgram_Mcast
{

public:
  // = Initialization routines.
  /// Ctor, has same defaults as ACE_SOCK_Dgram_Mcast
  ACE_SOCK_Dgram_Mcast_QoS (options opts = DEFOPTS);

  // Note that there is no public <open> method.  Therefore, this
  // class cannot be used unless you <subscribe> to a multicast group.
  // If you just want to send (and not listen) to a multicast group,
  // use <ACE_SOCK_Dgram> or <ACE_SOCK_CODgram> instead.

  /// Default dtor.
  ~ACE_SOCK_Dgram_Mcast_QoS (void);

  // = Multicast group management routines.
  /**
   * This is a QoS-enabled method for joining a multicast group, which
   * passes <qos_params> via <ACE_OS::join_leaf>.  The network
   * interface device driver is instructed to accept datagrams with
   * <mcast_addr> multicast addresses.  If the socket has already been
   * opened, <subscribe> closes the socket and opens a new socket
   * bound to the <mcast_addr>. The session object specifies the QoS
   * session that the socket wants to subscribe to. A socket may
   * subscribe to multiple QoS sessions by calling this method multiple
   * times with different session objects.
   *
   * The <net_if> interface is hardware specific, e.g., use "netstat
   * -i" to find whether your interface is, such as "le0" or something
   * else.  If net_if == 0, <subscribe> uses the default mcast
   * interface.  Returns: -1 if the call fails.
   *
   * Note that some platforms, such as pSoS, support only number, not
   * names, for network interfaces.  For these platforms, just give
   * these numbers in alphanumeric form and <subscribe> will convert
   * them into numbers via <ACE_OS::atoi>.
   */
  int subscribe (const ACE_INET_Addr &mcast_addr,
                 const ACE_QoS_Params &qos_params,
                 int reuse_addr = 1,
                 const ACE_TCHAR *net_if = 0,
                 int protocol_family = PF_INET,
                 int protocol = 0,
                 ACE_Protocol_Info *protocolinfo = 0,
                 ACE_SOCK_GROUP g = 0,
                 u_long flags = 0,
                 ACE_QoS_Session *qos_session = 0);

  // = Data transfer routines.

  /// Send <buffer_count> worth of @a buffers to @a addr using overlapped
  /// I/O (uses <WSASentTo>).  Returns 0 on success.
  ssize_t send (const iovec buffers[],
                int buffer_count,
                size_t &number_of_bytes_sent,
                int flags,
                const ACE_Addr &addr,
                ACE_OVERLAPPED *overlapped,
                ACE_OVERLAPPED_COMPLETION_FUNC func) const;

  /// Send an @a n byte @a buf to the datagram socket (uses <WSASentTo>).
  ssize_t send (const void *buf,
                size_t n,
                const ACE_Addr &addr,
                int flags,
                ACE_OVERLAPPED *overlapped,
                ACE_OVERLAPPED_COMPLETION_FUNC func) const;

  /// Returns the QoS manager for this socket.
  ACE_QoS_Manager qos_manager (void);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  int open (const ACE_INET_Addr &addr,
            const ACE_QoS_Params &qos_params,
            int protocol_family = PF_INET,
            int protocol = 0,
            ACE_Protocol_Info *protocolinfo = 0,
            ACE_SOCK_GROUP g = 0,
            u_long flags = 0,
            int reuse_addr = 0);

private:
  // = Disable public <open> method to ensure class used properly.


  /// Subscribe to the multicast interface using QoS-enabled semantics.
  int subscribe_ifs (const ACE_INET_Addr &mcast_addr,
                     const ACE_QoS_Params &qos_params,
                     const ACE_TCHAR *net_if,
                     int protocol_family,
                     int protocol,
                     int reuse_addr,
                     ACE_Protocol_Info *protocolinfo);

  /// Manages the QoS sessions that this socket subscribes to.
  ACE_QoS_Manager qos_manager_;

};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "SOCK_Dgram_Mcast_QoS.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SOCK_DGRAM_MCAST_QOS_H */
