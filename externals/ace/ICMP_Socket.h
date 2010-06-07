// -*- C++ -*-

//=============================================================================
/**
 *  @file    ICMP_Socket.h
 *
 *  $Id: ICMP_Socket.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Robert S. Iakobashvili <coroberti@gmail.com> <coroberti@walla.co.il>
 *  @author Gonzalo A. Diethelm <gonzalo.diethelm@aditiva.com>
 */
//=============================================================================

#ifndef ACE_ICMP_SOCKET_H
#define ACE_ICMP_SOCKET_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_ICMP_SUPPORT) && (ACE_HAS_ICMP_SUPPORT == 1)

#include "ace/SOCK.h"
#include "ace/Time_Value.h"
#include "ace/os_include/netinet/os_in.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_ICMP_Socket
 *
 * @brief An abstract class that forms the basis for usage of the ICMP
 * protocol (that is, support for things such as ping).
 */
class ACE_Export ACE_ICMP_Socket : public ACE_SOCK
{
public:
  // = Initialization methods.

  /**
   * @name Data transfer routines.
   *
   * Data transfer routines.
   */
  //@{

  /// Send an @a n byte @a buf to the datagram socket (uses
  /// @c sendto(3) ).
  ssize_t send (void const * buf,
                size_t n,
                ACE_Addr const & addr,
                int flags = 0) const;

  /// Receive an @a n byte @a buf from the datagram socket
  /// (uses @c recvfrom(3) ).
  ssize_t recv (void * buf,
                size_t n,
                ACE_Addr & addr,
                int flags = 0) const;

  /// TODO: comment
  ssize_t recv (void * buf,
                size_t n,
                int flags,
                ACE_Time_Value const * timeout) const;

  //@}

  /// Wrapper around the BSD-style @c socket system call (no QoS).
  int open (ACE_Addr const & local = ACE_Addr::sap_any,
            int protocol = IPPROTO_ICMP,
            int reuse_addr = 0);

  /// Dump the state of object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:

  // Protected constructors, so the class can only be derived from.

  /// Default constructor.
  ACE_ICMP_Socket (void);

  /// Constructor that takes a local listening address.
  ACE_ICMP_Socket (ACE_Addr const & local,
                   int protocol = IPPROTO_ICMP,
                   int reuse_addr = 0);

  /// Wrapper around BSD-style @c bind system call.
  int shared_open (ACE_Addr const & local);

  /// Calculates check-sum.
  unsigned short calculate_checksum (unsigned short* paddress,
                                     int len);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif  /* ACE_HAS_ICMP_SUPPORT == 1 */

#include /**/ "ace/post.h"

#endif /* ACE_ICMP_SOCKET_H */
