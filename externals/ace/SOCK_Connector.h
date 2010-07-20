// -*- C++ -*-

//=============================================================================
/**
 *  @file    SOCK_Connector.h
 *
 *  $Id: SOCK_Connector.h 84816 2009-03-13 08:16:32Z johnnyw $
 *
 *  @author Doug Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SOCK_CONNECTOR_H
#define ACE_SOCK_CONNECTOR_H
#include /**/ "ace/pre.h"

#include "ace/SOCK_Stream.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_QoS_Params;
class ACE_Time_Value;

/**
 * @class ACE_SOCK_Connector
 *
 * @brief Defines a factory that actively connects to a remote IP
 * address and TCP port, creating a new @c ACE_SOCK_Stream object.
 *
 * The @c ACE_SOCK_Connector doesn't have a socket of its own,
 * i.e., it simply "borrows" the one from the @c ACE_SOCK_Stream
 * that's being connected.  The reason for this is that the
 * underlying socket API doesn't use a factory socket to connect
 * data mode sockets.  Therefore, there's no need to inherit
 * @c ACE_SOCK_Connector from @c ACE_SOCK.  A nice side-effect of
 * this is that @c ACE_SOCK_Connector objects do not store state so
 * they can be used reentrantly in multithreaded programs.
 */
class ACE_Export ACE_SOCK_Connector
{
public:
  // = Initialization and termination methods.
  /// Default constructor.
  ACE_SOCK_Connector (void);

  /**
   * Actively connect to a peer, producing a connected @c ACE_SOCK_Stream
   * object if the connection succeeds.
   *
   * @param new_stream  The @c ACE_SOCK_Stream object that will be connected
   *                    to the peer.
   * @param remote_sap  The address that we are trying to connect to.
   *                    The protocol family of @c remote_sap is used for
   *                    the connected socket. That is, if @c remote_sap
   *                    contains an IPv6 address, a socket with family
   *                    PF_INET6 will be used, else it will be PF_INET.
   * @param timeout     Pointer to an @c ACE_Time_Value object with amount
   *                    of time to wait to connect. If the pointer is 0
   *                    then the call blocks until the connection attempt
   *                    is complete, whether it succeeds or fails.  If
   *                    *timeout == {0, 0} then the connection is done
   *                    using nonblocking mode.  In this case, if the
   *                    connection can't be made immediately, this method
   *                    returns -1 and errno == EWOULDBLOCK.
   *                    If *timeout > {0, 0} then this is the maximum amount
   *                    of time to wait before timing out; if the specified
   *                    amount of time passes before the connection is made,
   *                    this method returns -1 and errno == ETIME. Note
   *                    the difference between this case and when a blocking
   *                    connect is attempted that TCP times out - in the latter
   *                    case, errno will be ETIMEDOUT.
   * @param local_sap   (optional) The local address to bind to.  If it's
   *                    the default value of @c ACE_Addr::sap_any then the
   *                    OS will choose an unused port.
   * @param reuse_addr  (optional) If the value is 1, the local address
   *                    (@c local_sap) is reused, even if it hasn't been
   *                    cleaned up yet.
   * @param flags       Ignored.
   * @param perms       Ignored.
   * @param protocol    (optional) If value is 0, default SOCK_STREAM
   *                    protocol is selected by kernel (typically TCP).
   */
  ACE_SOCK_Connector (ACE_SOCK_Stream &new_stream,
                      const ACE_Addr &remote_sap,
                      const ACE_Time_Value *timeout = 0,
                      const ACE_Addr &local_sap = ACE_Addr::sap_any,
                      int reuse_addr = 0,
                      int flags = 0,
                      int perms = 0,
                      int protocol = 0);

#if !defined (ACE_HAS_WINCE)
  /**
   * Actively connect to a peer, producing a connected @c ACE_SOCK_Stream
   * object if the connection succeeds.
   *
   * @param new_stream  The @c ACE_SOCK_Stream object that will be connected
   *                    to the peer.
   * @param remote_sap  The address that we are trying to connect to.
   *                    The protocol family of @c remote_sap is used for
   *                    the connected socket. That is, if @c remote_sap
   *                    contains an IPv6 address, a socket with family
   *                    PF_INET6 will be used, else it will be PF_INET.
   * @param qos_params  Contains QoS parameters that are passed to the
   *                    IntServ (RSVP) and DiffServ protocols.
   *                    @see ACE_QoS_Params.
   * @param timeout     Pointer to an @c ACE_Time_Value object with amount
   *                    of time to wait to connect. If the pointer is 0
   *                    then the call blocks until the connection attempt
   *                    is complete, whether it succeeds or fails.  If
   *                    *timeout == {0, 0} then the connection is done
   *                    using nonblocking mode.  In this case, if the
   *                    connection can't be made immediately, this method
   *                    returns -1 and errno == EWOULDBLOCK.
   *                    If *timeout > {0, 0} then this is the maximum amount
   *                    of time to wait before timing out; if the specified
   *                    amount of time passes before the connection is made,
   *                    this method returns -1 and errno == ETIME. Note
   *                    the difference between this case and when a blocking
   *                    connect is attempted that TCP times out - in the latter
   *                    case, errno will be ETIMEDOUT.
   * @param local_sap   (optional) The local address to bind to.  If it's
   *                    the default value of @c ACE_Addr::sap_any then the
   *                    OS will choose an unused port.
   * @param reuse_addr  (optional) If the value is 1, the local address
   *                    (@c local_sap) is reused, even if it hasn't been
   *                    cleaned up yet.
   * @param flags       Ignored.
   * @param perms       Ignored.
   */
  ACE_SOCK_Connector (ACE_SOCK_Stream &new_stream,
                      const ACE_Addr &remote_sap,
                      ACE_QoS_Params qos_params,
                      const ACE_Time_Value *timeout = 0,
                      const ACE_Addr &local_sap = ACE_Addr::sap_any,
                      ACE_Protocol_Info *protocolinfo = 0,
                      ACE_SOCK_GROUP g = 0,
                      u_long flags = 0,
                      int reuse_addr = 0,
                      int perms = 0);
#endif  // ACE_HAS_WINCE

  /**
   * Actively connect to a peer, producing a connected @c ACE_SOCK_Stream
   * object if the connection succeeds.
   *
   * @param new_stream  The @c ACE_SOCK_Stream object that will be connected
   *                    to the peer.
   * @param remote_sap  The address that we are trying to connect to.
   *                    The protocol family of @c remote_sap is used for
   *                    the connected socket. That is, if @c remote_sap
   *                    contains an IPv6 address, a socket with family
   *                    PF_INET6 will be used, else it will be PF_INET.
   * @param timeout     Pointer to an @c ACE_Time_Value object with amount
   *                    of time to wait to connect. If the pointer is 0
   *                    then the call blocks until the connection attempt
   *                    is complete, whether it succeeds or fails.  If
   *                    *timeout == {0, 0} then the connection is done
   *                    using nonblocking mode.  In this case, if the
   *                    connection can't be made immediately, this method
   *                    returns -1 and errno == EWOULDBLOCK.
   *                    If *timeout > {0, 0} then this is the maximum amount
   *                    of time to wait before timing out; if the specified
   *                    amount of time passes before the connection is made,
   *                    this method returns -1 and errno == ETIME. Note
   *                    the difference between this case and when a blocking
   *                    connect is attempted that TCP times out - in the latter
   *                    case, errno will be ETIMEDOUT.
   * @param local_sap   (optional) The local address to bind to.  If it's
   *                    the default value of @c ACE_Addr::sap_any then the
   *                    OS will choose an unused port.
   * @param reuse_addr  (optional) If the value is 1, the local address
   *                    (@c local_sap) is reused, even if it hasn't been
   *                    cleaned up yet.
   * @param flags       Ignored.
   * @param perms       Ignored.
   * @param protocol    (optional) If value is 0, default SOCK_STREAM
   *                    protocol is selected by kernel (typically TCP).
   *
   * @return            Returns 0 if the connection succeeds. If it fails,
   *                    -1 is returned and errno contains a specific error
   *                    code.
   */
  int connect (ACE_SOCK_Stream &new_stream,
               const ACE_Addr &remote_sap,
               const ACE_Time_Value *timeout = 0,
               const ACE_Addr &local_sap = ACE_Addr::sap_any,
               int reuse_addr = 0,
               int flags = 0,
               int perms = 0,
               int protocol = 0);

#if !defined (ACE_HAS_WINCE)
  /**
   * Actively connect to a peer, producing a connected @c ACE_SOCK_Stream
   * object if the connection succeeds.
   *
   * @param new_stream  The @c ACE_SOCK_Stream object that will be connected
   *                    to the peer.
   * @param remote_sap  The address that we are trying to connect to.
   *                    The protocol family of @c remote_sap is used for
   *                    the connected socket. That is, if @c remote_sap
   *                    contains an IPv6 address, a socket with family
   *                    PF_INET6 will be used, else it will be PF_INET.
   * @param qos_params  Contains QoS parameters that are passed to the
   *                    IntServ (RSVP) and DiffServ protocols.
   *                    @see ACE_QoS_Params.
   * @param timeout     Pointer to an @c ACE_Time_Value object with amount
   *                    of time to wait to connect. If the pointer is 0
   *                    then the call blocks until the connection attempt
   *                    is complete, whether it succeeds or fails.  If
   *                    *timeout == {0, 0} then the connection is done
   *                    using nonblocking mode.  In this case, if the
   *                    connection can't be made immediately, this method
   *                    returns -1 and errno == EWOULDBLOCK.
   *                    If *timeout > {0, 0} then this is the maximum amount
   *                    of time to wait before timing out; if the specified
   *                    amount of time passes before the connection is made,
   *                    this method returns -1 and errno == ETIME. Note
   *                    the difference between this case and when a blocking
   *                    connect is attempted that TCP times out - in the latter
   *                    case, errno will be ETIMEDOUT.
   * @param local_sap   (optional) The local address to bind to.  If it's
   *                    the default value of @c ACE_Addr::sap_any then the
   *                    OS will choose an unused port.
   * @param reuse_addr  (optional) If the value is 1, the local address
   *                    (@c local_sap) is reused, even if it hasn't been
   *                    cleaned up yet.
   * @param flags       Ignored.
   * @param perms       Ignored.
   *
   * @return            Returns 0 if the connection succeeds. If it fails,
   *                    -1 is returned and errno contains a specific error
   *                    code.
   */
  int connect (ACE_SOCK_Stream &new_stream,
               const ACE_Addr &remote_sap,
               ACE_QoS_Params qos_params,
               const ACE_Time_Value *timeout = 0,
               const ACE_Addr &local_sap = ACE_Addr::sap_any,
               ACE_Protocol_Info *protocolinfo = 0,
               ACE_SOCK_GROUP g = 0,
               u_long flags = 0,
               int reuse_addr = 0,
               int perms = 0);
#endif  // ACE_HAS_WINCE

  /// Default dtor.
  ~ACE_SOCK_Connector (void);

  // = Completion routine.
  /**
   * Try to complete a nonblocking connection that was begun by a
   * previous call to connect with a {0, 0} ACE_Time_Value timeout.
   * @see connect().
   *
   * @param new_stream  The @c ACE_SOCK_Stream object that will be connected
   *                    to the peer.
   * @param remote_sap  If non-0, it points to the @c ACE_INET_Addr object
   *                    that will contain the address of the connected peer.
   * @param timeout     Same values and return value possibilites as for
   *                    connect(). @see connect().
   */
  int complete (ACE_SOCK_Stream &new_stream,
                ACE_Addr *remote_sap = 0,
                const ACE_Time_Value *timeout = 0);

  /// Resets any event associations on this handle
  bool reset_new_handle (ACE_HANDLE handle);

  // = Meta-type info
  typedef ACE_INET_Addr PEER_ADDR;
  typedef ACE_SOCK_Stream PEER_STREAM;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Perform operations that ensure the socket is opened using
  /// BSD-style semantics (no QoS).
  int shared_open (ACE_SOCK_Stream &new_stream,
                   int protocol_family,
                   int protocol,
                   int reuse_addr);

  /// Perform operations that ensure the socket is opened using
  /// QoS-enabled semantics.
  int shared_open (ACE_SOCK_Stream &new_stream,
                   int protocol_family,
                   int protocol,
                   ACE_Protocol_Info *protocolinfo,
                   ACE_SOCK_GROUP g,
                   u_long flags,
                   int reuse_addr);

  /// Perform operations that must be called before <ACE_OS::connect>.
  int shared_connect_start (ACE_SOCK_Stream &new_stream,
                            const ACE_Time_Value *timeout,
                            const ACE_Addr &local_sap);

  /// Perform operations that must be called after <ACE_OS::connect>.
  int shared_connect_finish (ACE_SOCK_Stream &new_stream,
                             const ACE_Time_Value *timeout,
                             int result);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/SOCK_Connector.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SOCK_CONNECTOR_H */
