// -*- C++ -*-

//==========================================================================
/**
 *  @file    MEM_Addr.h
 *
 *  $Id: MEM_Addr.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_MEM_ADDR_H
#define ACE_MEM_ADDR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)

#include "ace/INET_Addr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_MEM_Addr
 *
 * @brief Defines a C++ wrapper facade for the shared memory transport
 * address family format.
 */
class ACE_Export ACE_MEM_Addr : public ACE_Addr
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_MEM_Addr (void);

  /// Copy constructor.
  ACE_MEM_Addr (const ACE_MEM_Addr &);

  /// Creates an ACE_MEM_Addr from a @a port_number
  ACE_MEM_Addr (u_short port_number);

  /// Creates an ACE_MEM_Addr from a @a port_name.
  explicit ACE_MEM_Addr (const ACE_TCHAR port_name[]);

  /// Default dtor.
  ~ACE_MEM_Addr (void);

  // = Direct initialization methods.

  /// Default initialization routine.
  int initialize_local (u_short port);

  /// Check if @a sap designates an endpoint on the same host.
  int same_host (const ACE_INET_Addr& sap);

  // These methods are useful after the object has been constructed.

  /**
   * Initializes an ACE_MEM_Addr from a @a port_number.  If @a encode
   * is enabled then @a port_number is converted into network byte order,
   * otherwise it is assumed to be in network byte order already and
   * are passed straight through.
   */
  int set (u_short port_number, int encode = 1);

  /// Uses <getservbyname> to initialize an ACE_MEM_Addr from a
  /// <port_name>, the remote <host_name>, and the <protocol>.
  int set (const ACE_TCHAR port_name[]);

  /// Return a pointer to the underlying network address.
  virtual void *get_addr (void) const;

  /// Set a pointer to the address.
  virtual void set_addr (void *, int len);

  /// Transform the external ACE_MEM_Addr address into string
  /// format.
  virtual int addr_to_string (ACE_TCHAR buffer[],
                              size_t size,
                              int ipaddr_format = 1) const;

  /// Initializes the external ACE_MEM_Addr from the @a address.
  virtual int string_to_addr (const ACE_TCHAR address[]);

  /// Sets the port number.
  void set_port_number (u_short,
                        int encode = 1);

  /// Return the port number, converting it into host byte order.
  u_short get_port_number (void) const;

  /// Return the character representation of the hostname.
  int get_host_name (ACE_TCHAR hostname[],
                     size_t hostnamelen) const;

  /**
   * Return the character representation of the hostname (this version
   * is non-reentrant since it returns a pointer to a static data
   * area).
   */
  const char *get_host_name (void) const;

  /// Return the "dotted decimal" external address.
  const char *get_host_addr (void) const;

  /// Return the 4-byte external IP address, converting it into host byte
  /// order.
  ACE_UINT32 get_ip_address (void) const;

  const ACE_INET_Addr &get_remote_addr (void) const;
  const ACE_INET_Addr &get_local_addr (void) const;

  /// Compare two addresses for equality.  The addresses are considered
  /// equal if they contain the same IP address and port number.
  bool operator == (const ACE_MEM_Addr &SAP) const;
  bool operator == (const ACE_INET_Addr &SAP) const;

  /// Compare two addresses for inequality.
  bool operator != (const ACE_MEM_Addr &SAP) const;
  bool operator != (const ACE_INET_Addr &SAP) const;

  /// Computes and returns hash value.
  virtual u_long hash (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// External INET addr used for identifying host.
  ACE_INET_Addr external_;

  /// Internal INET addr for accepting/connecting.
  ACE_INET_Addr internal_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/MEM_Addr.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */

#include /**/ "ace/post.h"
#endif /* ACE_MEM_ADDR_H */

