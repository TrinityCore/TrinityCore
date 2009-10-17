// $Id: SOCK_Netlink.h 80826 2008-03-04 14:51:23Z wotte $
//=============================================================================
/**
 *  @file    SOCK_Netlink.h
 *
 *  $Id: SOCK_Netlink.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Robert Iakobashvilli <coroberti@gmail.com>
 *  @author Raz Ben Yehuda <raziebe@013.net.il>
 */
//=============================================================================

#ifndef ACE_SOCK_NETLINK_H
#define ACE_SOCK_NETLINK_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
  #pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#ifdef ACE_HAS_NETLINK

#include "ace/SOCK.h"
#include "ace/Netlink_Addr.h"
#include "ace/Addr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_SOCK_Netlink
 *
 * @brief Defines the member functions for the ACE_SOCK Netlink
 * abstraction.

 * Netlink sockets are used in Linux as a communication facilty of kernel to user
 * and user to kernel.
 * This code was created so one could use ACE reactor
 * as a gateway to a linux kernel.
 *
 */
class ACE_Export ACE_SOCK_Netlink : public ACE_SOCK {
public:
  // = Initialization and termination methods.
  /// Default constructor.
  ACE_SOCK_Netlink(void);
  ~ACE_SOCK_Netlink(void);
  ACE_SOCK_Netlink (ACE_Netlink_Addr &local,
                    int protocol_family,
                    int protocol);
  /**
   * opens a RAW socket over an ACE_SOCK and binds it
   *
   **/
  int open (ACE_Netlink_Addr &local,
            int protocol_family,
            int protocol);

  /**
   *  receives abuffer with the size n
   */
  ssize_t recv (void *buf,
                size_t n,
                int flags) const;
  /**
   * send a buffer of size n bytes
   *
   */
  ssize_t send (void *buf,
                size_t n,
                int flags) const;

  /**
   *  Recieves an iovec of size @a n to the netlink socket
  */
  ssize_t recv (iovec iov[],
                int n,
                ACE_Addr &addr,
                int flags = 0) const;

  /**
   *  Sends an iovec of size @a n to the netlink socket
  */
  ssize_t send (const iovec iov[],
                int n,
                const ACE_Addr &addr,
                int flags = 0) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/SOCK_Netlink.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_NETLINK */

#include /**/ "ace/post.h"

#endif /* ACE_SOCK_NETLINK_H */


