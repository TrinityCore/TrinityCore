/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    MEM_Connector.h
 *
 *  $Id: MEM_Connector.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_MEM_CONNECTOR_H
#define ACE_MEM_CONNECTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)

#include "ace/SOCK_Connector.h"
#include "ace/MEM_Stream.h"
#include "ace/MEM_Addr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_MEM_Connector
 *
 * @brief Defines the format and interface for connecting to a peer
 * on a @c ACE_MEM_Stream object.
 */
class ACE_Export ACE_MEM_Connector : public ACE_SOCK_Connector
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_MEM_Connector (void);

  /**
   * Actively connect to a peer, producing a connected @c ACE_MEM_Stream
   * object if the connection succeeds.
   *
   * @param new_stream  The @c ACE_MEM_Stream object that will be connected
   *                    to the peer.
   * @param remote_sap  The address that we are trying to connect to.
   *                    The protocol family of @c remote_sap is used for
   *                    the connected socket. That is, if @c remote_sap
   *                    contains an IPv6 address, a socket with family
   *                    PF_INET6 will be used, else it will be PF_INET.
   *                    @note remote_sap must be an address on the local
   *                    host.
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
   */
  ACE_MEM_Connector (ACE_MEM_Stream &new_stream,
                     const ACE_INET_Addr &remote_sap,
                     ACE_Time_Value *timeout = 0,
                     const ACE_Addr &local_sap = ACE_Addr::sap_any,
                     int reuse_addr = 0,
                     int flags = 0,
                     int perms = 0);

  /**
   * Actively connect to a peer, producing a connected @c ACE_MEM_Stream
   * object if the connection succeeds.
   *
   * @param new_stream  The @c ACE_MEM_Stream object that will be connected
   *                    to the peer.
   * @param remote_sap  The address that we are trying to connect to.
   *                    The protocol family of @c remote_sap is used for
   *                    the connected socket. That is, if @c remote_sap
   *                    contains an IPv6 address, a socket with family
   *                    PF_INET6 will be used, else it will be PF_INET.
   *                    @note remote_sap must be an address on the local
   *                    host.
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
  int connect (ACE_MEM_Stream &new_stream,
               const ACE_INET_Addr &remote_sap,
               ACE_Time_Value *timeout = 0,
               const ACE_Addr &local_sap = ACE_Addr::sap_any,
               int reuse_addr = 0,
               int flags = 0,
               int perms = 0);

  /// Get the preferred signaling strategy.
  ACE_MEM_IO::Signal_Strategy preferred_strategy (void) const;

  /// Set the preferred signaling strategy.
  void preferred_strategy (ACE_MEM_IO::Signal_Strategy strategy);

  /// Accessor to underlying malloc options.
  /// @deprecated This method has been deprecated.
  ACE_MEM_SAP::MALLOC_OPTIONS &malloc_options (void);

  // = Meta-type info
  typedef ACE_INET_Addr PEER_ADDR;
  typedef ACE_MEM_Stream PEER_STREAM;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// The acceptor address this connector is connecting to.
  ACE_MEM_Addr address_;

  /// A cached MALLOC_OPTIONS that the MEM_Connector used to initialize
  /// the shared memory malloc update connection establishment.
  ACE_MEM_SAP::MALLOC_OPTIONS malloc_options_;

  /// Preferred signaling strategy.
  ACE_MEM_IO::Signal_Strategy preferred_strategy_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/MEM_Connector.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */

#include /**/ "ace/post.h"
#endif /* ACE_MEM_CONNECTOR_H */
