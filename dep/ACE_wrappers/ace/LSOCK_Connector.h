// -*- C++ -*-

//=============================================================================
/**
 *  @file    LSOCK_Connector.h
 *
 *  $Id: LSOCK_Connector.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_LOCAL_SOCK_CONNECTOR_H
#define ACE_LOCAL_SOCK_CONNECTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)

#include "ace/SOCK_Connector.h"
#include "ace/LSOCK_Stream.h"
#include "ace/UNIX_Addr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_LSOCK_Connector
 *
 * @brief Defines the format and interface for the connector side of
 * the ACE_LSOCK_Stream.
 */
class ACE_Export ACE_LSOCK_Connector : public ACE_SOCK_Connector
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_LSOCK_Connector (void);

  /**
   * Actively connect and produce a @a new_stream if things go well.
   * All arguments are relayed to the ACE_SOCK_Connector constructor
   * for handling.
   * @see ACE_SOCK_Connector().
   */
  ACE_LSOCK_Connector (ACE_LSOCK_Stream &new_stream,
                       const ACE_UNIX_Addr &remote_sap,
                       ACE_Time_Value *timeout = 0,
                       const ACE_Addr &local_sap = ACE_Addr::sap_any,
                       int reuse_addr = 0,
                       int flags = 0,
                       int perms = 0);

  /**
   * Actively connect and produce a @a new_stream if things go well.
   * The @c ACE_SOCK_Connector::connect() method is called to perform
   * the actual connection attempt.
   * @see ACE_SOCK_Connector::connect().
   */
  int connect (ACE_LSOCK_Stream &new_stream,
               const ACE_UNIX_Addr &remote_sap,
               ACE_Time_Value *timeout = 0,
               const ACE_Addr &local_sap = ACE_Addr::sap_any,
               int reuse_addr = 0,
               int flags = 0,
               int perms = 0);

  // = Meta-type info
  typedef ACE_UNIX_Addr PEER_ADDR;
  typedef ACE_LSOCK_Stream PEER_STREAM;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/LSOCK_Connector.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */
#include /**/ "ace/post.h"
#endif /* ACE_LOCAL_SOCK_CONNECTOR_H */

