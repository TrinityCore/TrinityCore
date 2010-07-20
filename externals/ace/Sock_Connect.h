// -*- C++ -*-

//==========================================================================
/**
 *  @file   Sock_Connect.h
 *
 *  $Id: Sock_Connect.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Priyanka Gontla <pgontla@ece.uci.edu>
 *  @author Based on code that existed formerly in ACE.h.
 */
//==========================================================================

#ifndef ACE_SOCK_CONNECT_H
#define ACE_SOCK_CONNECT_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Basic_Types.h"
#include "ace/os_include/netinet/os_in.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward Declarations
class ACE_INET_Addr;

namespace ACE
{
  // = Socket connection establishment calls.

  /// Bind a new unused port to @a handle.
  extern ACE_Export int bind_port (ACE_HANDLE handle,
                                   ACE_UINT32 ip_addr = INADDR_ANY,
                                   int address_family = AF_UNSPEC);

  /**
   * Get our broadcast address based on our @a host_addr.  If
   * @a hostname is non-0 we'll use it to determine our IP address.  If
   * @a handle is not ACE_INVALID_HANDLE then we'll use this to
   * determine our broadcast address, otherwise we'll have to create a
   * socket internally (and free it).  Returns -1 on failure and 0 on
   * success.
   */
  extern ACE_Export int get_bcast_addr (
    ACE_UINT32 &bcast_addr,
    const ACE_TCHAR *hostname = 0,
    ACE_UINT32 host_addr = 0,
    ACE_HANDLE handle = ACE_INVALID_HANDLE);

  /// Get fully qualified host/domain name.
  extern ACE_Export int get_fqdn (ACE_INET_Addr const & addr,
                                  char hostname[],
                                  size_t len);

  /**
   * Return count and array of all configured IP interfaces on this
   * host, rc = 0 on success (count == number of interfaces else -1).
   * Caller is responsible for calling delete [] on @a addr_array.
   */
  extern ACE_Export int get_ip_interfaces (size_t &count,
                                           ACE_INET_Addr *&addr_array);

  /**
   * Helper routine for get_ip_interfaces, differs by UNIX platform so
   * put into own subroutine.  perform some ioctls to retrieve ifconf
   * list of ifreq structs.
   */
  extern ACE_Export int count_interfaces (ACE_HANDLE handle,
                                          size_t &how_many);

  /// Routine to return a handle from which @c ioctl requests can be
  /// made.  Caller must close the handle.
  extern ACE_Export ACE_HANDLE get_handle (void);

  /// Returns @c true if IPv4 is enabled on the current host; @c false
  /// if not.
  /**
   * This is an execution-time check. If ACE has not been compiled
   * with @c ACE_HAS_IPV6, it always returns @c true. This function
   * tries to create a @c PF_INET socket, returning @c true if it
   * succeeds, and @c false if it fails. Caches the result so it only
     gets checked once.
   */
  extern ACE_Export bool ipv4_enabled (void);

  /**
   * Returns 1 if IPv6 is enabled on the current host; 0 if not.
   * This is an execution-time check. If ACE has not been compiled
   * with ACE_HAS_IPV6, it always returns 0. If ACE_HAS_IPV6 is
   * enabled, this function tries to create a PF_INET6 socket,
   * returning 1 if it succeeds, and 0 if it fails. Caches the result
   * so it only gets checked once.
   */
  extern ACE_Export int ipv6_enabled (void);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif  /* ACE_SOCK_CONNECT_H */
