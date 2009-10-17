// -*- C++ -*-

//=============================================================================
/**
 *  @file    LSOCK_CODgram.h
 *
 *  $Id: LSOCK_CODgram.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_LOCAL_SOCK_CODGRAM_H
#define ACE_LOCAL_SOCK_CODGRAM_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)

#include "ace/LSOCK.h"
#include "ace/SOCK_CODgram.h"
#include "ace/Addr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_LSOCK_CODgram
 *
 * @brief Defines the member functions for the <ACE_LSOCK> connected
 * datagram abstraction.
 */
class ACE_Export ACE_LSOCK_CODgram : public ACE_SOCK_CODgram, public ACE_LSOCK
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_LSOCK_CODgram (void);

  /// Initiate a connected-datagram.
  ACE_LSOCK_CODgram (const ACE_Addr &remote_sap,
                     const ACE_Addr &local_sap = ACE_Addr::sap_any,
                     int protocol_family = PF_UNIX,
                     int protocol = 0);

  /// Initiate a connected-datagram.
  int open (const ACE_Addr &remote_sap,
            const ACE_Addr &local_sap = ACE_Addr::sap_any,
            int protocol_family = PF_UNIX,
            int protocol = 0);

  /// Get underlying handle.
  ACE_HANDLE get_handle (void) const;

  /// Set underlying handle.
  void set_handle (ACE_HANDLE);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/LSOCK_CODgram.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */
#include /**/ "ace/post.h"
#endif /* ACE_LOCAL_SOCK_CODGRAM_H */

