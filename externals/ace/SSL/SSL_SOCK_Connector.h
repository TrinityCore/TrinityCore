// -*- C++ -*-

//=============================================================================
/**
 *  @file    SSL_SOCK_Connector.h
 *
 *  $Id: SSL_SOCK_Connector.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Ossama Othman <ossama@uci.edu>
 *  @author Carlos O'Ryan <coryan@uci.edu>
 *  @author John Heitmann
 *  @author Chris Zimman
 */
//=============================================================================


#ifndef ACE_SSL_SOCK_CONNECTOR_H
#define ACE_SSL_SOCK_CONNECTOR_H

#include /**/ "ace/pre.h"

#include "SSL_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "SSL_SOCK_Stream.h"

#include "ace/SOCK_Connector.h"
#include "ace/OS_QoS.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_SSL_SOCK_Connector
 *
 * @brief Defines a factory that creates new <ACE_SSL_SOCK_Stream>s
 *        actively.
 *
 * The ACE_SSL_SOCK_Connector doesn't have a socket of its own,
 * i.e., it simply "borrows" the one from the ACE_SSL_SOCK_Stream
 * that's being connected.  The reason for this is that the
 * underlying socket API doesn't use a "factory" socket to connect
 * "data-mode" sockets.  Therefore, there's no need to inherit
 * ACE_SSL_SOCK_Connector from ACE_SSL_SOCK.
 *
 * Since SSL is record-oriented, some additional work is done after
 * the plain socket is connected.
 *
 * @note The user must currently ensure that only one thread services
 *       a given SSL session at any given time since some underlying
 *       SSL implementations, such as OpenSSL, are not entirely
 *       thread-safe or reentrant.
 */
class ACE_SSL_Export ACE_SSL_SOCK_Connector
{

public:

  /// Default constructor.
  ACE_SSL_SOCK_Connector (void);

  /**
   * Actively connect to a peer, producing a connected @c ACE_SSL_SOCK_Stream
   * object if the connection succeeds. This method performs both the
   * initial socket connect and the SSL handshake.
   *
   * @param new_stream  The @c ACE_SSL_SOCK_Stream object that will be
   *                    connected to the peer.
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
   *                    connect is attmpted that TCP times out - in the latter
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
  ACE_SSL_SOCK_Connector (ACE_SSL_SOCK_Stream &new_stream,
                          const ACE_Addr &remote_sap,
                          const ACE_Time_Value *timeout = 0,
                          const ACE_Addr &local_sap = ACE_Addr::sap_any,
                          int reuse_addr = 0,
                          int flags = 0,
                          int perms = 0);

  /**
   * Actively connect to a peer, producing a connected @c ACE_SSL_SOCK_Stream
   * object if the connection succeeds. This method performs both the
   * initial socket connect and the SSL handshake.
   *
   * @param new_stream  The @c ACE_SSL_SOCK_Stream object that will be
   *                    connected to the peer.
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
   *                    connect is attmpted that TCP times out - in the latter
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
  ACE_SSL_SOCK_Connector (ACE_SSL_SOCK_Stream &new_stream,
                          const ACE_Addr &remote_sap,
                          ACE_QoS_Params qos_params,
                          const ACE_Time_Value *timeout = 0,
                          const ACE_Addr &local_sap = ACE_Addr::sap_any,
                          ACE_Protocol_Info *protocolinfo = 0,
                          ACE_SOCK_GROUP g = 0,
                          u_long flags = 0,
                          int reuse_addr = 0,
                          int perms = 0);

  /// Default dtor.
  ~ACE_SSL_SOCK_Connector (void);

  /**
   * Actively connect to a peer, producing a connected @c ACE_SSL_SOCK_Stream
   * object if the connection succeeds. This method performs both the
   * initial socket connect and the SSL handshake.
   *
   * @param new_stream  The @c ACE_SSL_SOCK_Stream object that will be
   *                    connected to the peer.
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
   *                    connect is attmpted that TCP times out - in the latter
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
  int connect (ACE_SSL_SOCK_Stream &new_stream,
               const ACE_Addr &remote_sap,
               const ACE_Time_Value *timeout = 0,
               const ACE_Addr &local_sap = ACE_Addr::sap_any,
               int reuse_addr = 0,
               int flags = 0,
               int perms = 0);

  /**
   * Actively connect to a peer, producing a connected @c ACE_SSL_SOCK_Stream
   * object if the connection succeeds. This method performs both the
   * initial socket connect and the SSL handshake.
   *
   * @param new_stream  The @c ACE_SSL_SOCK_Stream object that will be
   *                    connected to the peer.
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
   *                    connect is attmpted that TCP times out - in the latter
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
  int connect (ACE_SSL_SOCK_Stream &new_stream,
               const ACE_Addr &remote_sap,
               ACE_QoS_Params qos_params,
               const ACE_Time_Value *timeout = 0,
               const ACE_Addr &local_sap = ACE_Addr::sap_any,
               ACE_Protocol_Info *protocolinfo = 0,
               ACE_SOCK_GROUP g = 0,
               u_long flags = 0,
               int reuse_addr = 0,
               int perms = 0);

  /**
   * Try to complete a non-blocking connection.
   * If connection completion is successful then <new_stream> contains
   * the connected ACE_SSL_SOCK_Stream.  If <remote_sap> is non-NULL
   * then it will contain the address of the connected peer.
   */
  int complete (ACE_SSL_SOCK_Stream &new_stream,
                ACE_Addr *remote_sap = 0,
                const ACE_Time_Value *timeout = 0);

  /// Resets any event associations on this handle
  int reset_new_handle (ACE_HANDLE handle);

  /// Meta-type info
  //@{
  typedef ACE_INET_Addr PEER_ADDR;
  typedef ACE_SSL_SOCK_Stream PEER_STREAM;
  //@}

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:

  /// Complete non-blocking SSL active connection.
  int ssl_connect (ACE_SSL_SOCK_Stream &new_stream,
                   const ACE_Time_Value *timeout);

private:

  /// The class that does all of the non-secure socket connection.
  /// It is default contructed, and subsequently used by connect().
  ACE_SOCK_Connector connector_;

};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "SSL_SOCK_Connector.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_SSL_SOCK_CONNECTOR_H */
