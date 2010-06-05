// -*- C++ -*-

//=============================================================================
/**
 *  @file    SOCK_CODgram.h
 *
 *  $Id: SOCK_CODgram.h 81509 2008-04-28 22:00:49Z shuston $
 *
 *  @author Doug Schmidt
 */
//=============================================================================

#ifndef ACE_SOCK_CODGRAM_H
#define ACE_SOCK_CODGRAM_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SOCK_IO.h"
#include "ace/Addr.h"
#include "ace/INET_Addr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_SOCK_CODgram
 *
 * @brief Defines the member functions for the ACE_SOCK connected
 * datagram abstraction.
 */
class ACE_Export ACE_SOCK_CODgram : public ACE_SOCK_IO
{
public:
  /// Default constructor.
  ACE_SOCK_CODgram (void);

  /**
   * Constructor with addresses specified. Calls open().
   * This constructor binds and/or connects to a specified address,
   * optionally binding an unused port number.
   *
   * @param remote_sap      The remote address.
   * @param local_sap       The local address.
   * @param protocol_family The protocol family for the new socket. If
   *                        either @p remote_sap or @p local_sap is
   *                        specified (i.e., not ACE_Addr::sap_any) its
   *                        address type is used instead of this value.
   *                        If both addresses are specified, their address
   *                        types must match. If neither address is specified,
   *                        the platform's default IP address type is used.
   * @param protocol        Protocol value for the new socket.
   * @param reuse_addr      Reuse the local address or not.
   *
   * There are four possible combinations of remote_sap and local_sap. The
   * behavior in these combinations is:
   *
   * @li <b>remote_addr == ACE_Addr::sap_any && local_addr == ACE_Addr::sap_any:</b>
   *     If @p protocol_family specifies PF_INET or PF_INET6,
   *     bind the local address to a randomly generated port number.
   *
   * @li <b>remote_addr == ACE_Addr::sap_any && local_addr != ACE_Addr::sap_any:</b>
   *     Bind the local address (used primarily by servers).
   *
   * @li <b>remote_addr != ACE_Addr::sap_any && local_addr == ACE_Addr::sap_any:</b>
   *     Connect to the remote address without binding a local address
   *     (used primarily by clients).
   *
   * @li <b>remote_addr != ACE_Addr::sap_any && local_addr != ACE_Addr::sap_any:</b>
   *     Bind to the local address and connect to the remote address.
   */
  ACE_SOCK_CODgram (const ACE_Addr &remote_sap,
                    const ACE_Addr &local_sap = ACE_Addr::sap_any,
                    int protocol_family = ACE_PROTOCOL_FAMILY_INET,
                    int protocol = 0,
                    int reuse_addr = 0);

  /// Default dtor.
  ~ACE_SOCK_CODgram (void);

  // Initiate a connected dgram.

  /**
   * Initiate a connected datagram socket, optionally binding an
   * unused port number.
   *
   * @param remote_sap      The remote address.
   * @param local_sap       The local address.
   * @param protocol_family The protocol family for the new socket. If
   *                        either @p remote_sap or @p local_sap is
   *                        specified (i.e., not ACE_Addr::sap_any) its
   *                        address type is used instead of this value.
   *                        If both addresses are specified, their address
   *                        types must match. If neither address is specified,
   *                        the platform's default IP address type is used.
   * @param protocol        Protocol value for the new socket.
   * @param reuse_addr      Reuse the local address or not.
   *
   * There are four possible combinations of remote_sap and local_sap. The
   * behavior in these combinations is:
   *
   * @li <b>remote_addr == ACE_Addr::sap_any && local_addr == ACE_Addr::sap_any:</b>
   *     If @p protocol_family specifies PF_INET or PF_INET6,
   *     bind the local address to a randomly generated port number.
   *
   * @li <b>remote_addr == ACE_Addr::sap_any && local_addr != ACE_Addr::sap_any:</b>
   *     Bind the local address (used primarily by servers).
   *
   * @li <b>remote_addr != ACE_Addr::sap_any && local_addr == ACE_Addr::sap_any:</b>
   *     Connect to the remote address without binding a local address
   *     (used primarily by clients).
   *
   * @li <b>remote_addr != ACE_Addr::sap_any && local_addr != ACE_Addr::sap_any:</b>
   *     Bind to the local address and connect to the remote address.
   */
  int open (const ACE_Addr &remote_sap,
            const ACE_Addr &local_sap = ACE_Addr::sap_any,
            int protocol_family = ACE_PROTOCOL_FAMILY_INET,
            int protocol = 0,
            int reuse_addr = 0);

  // = Meta-type info.
  typedef ACE_INET_Addr PEER_ADDR;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/SOCK_CODgram.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SOCK_CODGRAM_H */

