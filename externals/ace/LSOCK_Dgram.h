// -*- C++ -*-

//=============================================================================
/**
 *  @file    LSOCK_Dgram.h
 *
 *  $Id: LSOCK_Dgram.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_LOCAL_SOCK_DGRAM_H
#define ACE_LOCAL_SOCK_DGRAM_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)

#include "ace/SOCK_Dgram.h"
#include "ace/LSOCK.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_LSOCK_Dgram
 *
 * @brief Create a Local ACE_SOCK datagram.
 */
class ACE_Export ACE_LSOCK_Dgram : public ACE_SOCK_Dgram, public ACE_LSOCK
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_LSOCK_Dgram (void);

  /// Initiate a local dgram.
  ACE_LSOCK_Dgram (const ACE_Addr &local,
                   int protocol_family = PF_UNIX,
                   int protocol = 0);

  /// Initiate a local dgram.
  int open (const ACE_Addr &local,
            int protocol_family = PF_UNIX,
            int protocol = 0);

  /// Get handle.
  ACE_HANDLE get_handle (void) const;

  /// Set handle.
  void set_handle (ACE_HANDLE);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/LSOCK_Dgram.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */
#include /**/ "ace/post.h"
#endif /* ACE_LOCAL_SOCK_DGRAM_H */
