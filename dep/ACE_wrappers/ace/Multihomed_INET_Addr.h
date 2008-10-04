// -*- C++ -*-

//=============================================================================
/**
 *  @file    Multihomed_INET_Addr.h
 *
 *  $Id: Multihomed_INET_Addr.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Edward R. Mulholland <emulholl@atl.lmco.com>
 */
//=============================================================================

#ifndef ACE_MULTIHOMED_INET_ADDR_H
#define ACE_MULTIHOMED_INET_ADDR_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/INET_Addr.h"
#include "ace/Containers_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Multihomed_INET_Addr
 *
 * @brief Extends ACE_INET_Addr with support for multi-homed
 * addresses.
 */
class ACE_Export ACE_Multihomed_INET_Addr : public ACE_INET_Addr
{
public:
  // = Initialization methods.

  /// Default constructor.
  ACE_Multihomed_INET_Addr (void);

  /**
   * Initializes an ACE_Multihomed_INET_Addr from the @a address,
   * which can be "ip-number:port-number" (e.g., "tango.cs.wustl.edu:1234"
   * or "128.252.166.57:1234").  If there is no ':' in the @a address it
   * is assumed to be a port number, with the IP address being
   * INADDR_ANY.
   */
  explicit ACE_Multihomed_INET_Addr (const char address[]);

  /**
   * Constructs an ACE_Multihomed_INET_Addr from a @a port_number, a
   * @a primary_host_name, and an array of <secondary_host_names>.
   * @a size is taken to be the length of the array.  If @a encode is
   * non-zero, then @a port_number is converted into network byte
   * order; otherwise it is assumed to be in network byte order
   * already and is passed straight through.  @a address_family can be
   * used to select IPv4/IPv6 if the OS has IPv6 capability
   * (ACE_HAS_IPV6 is defined). To specify IPv6, use the value
   * AF_INET6. To specify IPv4, use AF_INET.
   */
    ACE_Multihomed_INET_Addr(u_short port_number,
                           const char primary_host_name[],
                           int encode = 1,
                           int address_family = AF_UNSPEC,
                           const char *(secondary_host_names[]) = 0,
                           size_t size = 0);

  /**
   * Constructs an ACE_Multihomed_INET_Addr from a @a port_number,
   * a @a primary_ip_addr, and an array of @a secondary_ip_addrs.  @a
   * size is taken to be the length of the array.  If @a encode is
   * non-zero, then the port number and the IP addresses are converted
   * into network byte order; otherwise they are assumed to be in
   * network byte order already and are passed straight through.
   */
  ACE_Multihomed_INET_Addr(u_short port_number,
                           ACE_UINT32 primary_ip_addr = INADDR_ANY,
                           int encode = 1,
                           const ACE_UINT32 *secondary_ip_addrs = 0,
                           size_t size = 0);

#if defined (ACE_HAS_WCHAR)
    /**
     * WCHAR versions of the methods that take char's as arguments.
     */
  ACE_Multihomed_INET_Addr(u_short port_number,
                           const wchar_t primary_host_name[],
                           int encode = 1,
                           int address_family = AF_UNSPEC,
                           const wchar_t *(secondary_host_names[]) = 0,
                           size_t size = 0);
  int set (u_short port_number,
           const wchar_t primary_host_name[],
           int encode = 1,
           int address_family = AF_UNSPEC,
           const wchar_t *(secondary_host_names[]) = 0,
           size_t size = 0);

#endif /* ACE_HAS_WCHAR */

  /// Use compiler-generated copy constructor.

  /// Use compiler-generated assignment operator.

  /// Default dtor.
  ~ACE_Multihomed_INET_Addr (void);

  // = Direct initialization methods.

  // These methods are useful after the object has been constructed.

  /**
   * Initializes an ACE_Multihomed_INET_Addr from a @a port_number, a
   * @a primary_host_name, and an array of <secondary_host_names>.
   * @a size is taken to be the length of the array.  If @a encode is
   * non-zero, then @a port_number is converted into network byte
   * order; otherwise it is assumed to be in network byte order
   * already and is passed straight through.  @a address_family can be
   * used to select IPv4/IPv6 if the OS has IPv6 capability
   * (ACE_HAS_IPV6 is defined). To specify IPv6, use the value
   * AF_INET6. To specify IPv4, use AF_INET.
   */
  int set (u_short port_number,
           const char primary_host_name[],
           int encode = 1,
           int address_family = AF_UNSPEC,
           const char *(secondary_host_names[]) = 0,
           size_t size = 0);

  /**
   * Initializes an ACE_Multihomed_INET_Addr from a @a port_number,
   * a @a primary_ip_addr, and an array of @a secondary_ip_addrs.  @a
   * size is taken to be the length of the array.  If @a encode is
   * non-zero, then the port number and the IP addresses are converted
   * into network byte order; otherwise they are assumed to be in
   * network byte order already and are passed straight through.
   */
  int set (u_short port_number,
           ACE_UINT32 primary_ip_addr = INADDR_ANY,
           int encode = 1,
           const ACE_UINT32 *secondary_ip_addrs = 0,
           size_t size = 0);

  /**
   * Sets the port number without affecting the host name.  The port
   * numbers of the primary address, and of any and all secondary
   * addresses, are affected.  If @a encode is enabled, then
   * @a port_number is converted into network byte order, otherwise it
   * is assumed to be in network byte order already and is passed
   * straight through.
   */
  void set_port_number (u_short port_number,
                        int encode = 1);

  // = Accessor methods.

  /**
   * Returns the number of secondary addresses.
   */
  size_t get_num_secondary_addresses () const;

  /**
   * Initialize user-supplied array @a secondary_addrs with the current
   * secondary addresses.  @a size is taken as the size of this array.
   */
  int get_secondary_addresses(ACE_INET_Addr *secondary_addrs,
                              size_t size) const;

  /**
   * Initialize user-supplied array @a addrs with the the current
   * primary and secondary addresses.  @a size is taken as the size of
   * this array.
   */
  void get_addresses(sockaddr_in *addrs,
                     size_t size) const;

#if defined (ACE_HAS_IPV6)

  /// IPV6 version of the above.
  void get_addresses(sockaddr_in6 *addrs,
                     size_t size) const;
#endif /* ACE_HAS_IPV6 */

private:
  ACE_Array<ACE_INET_Addr> secondaries_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#  include "ace/Multihomed_INET_Addr.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_MULTIHOMED_INET_ADDR_H */
