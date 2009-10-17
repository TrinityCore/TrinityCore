// $Id: Netlink_Addr.h 80826 2008-03-04 14:51:23Z wotte $

//=============================================================================
/**
 *  @file    Netlink_Addr.h
 *
 *  $Id: Netlink_Addr.h 80826 2008-03-04 14:51:23Z wotte $
 *
 * @author Robert Iakobashvilli <coroberti@gmail.com>
 * @author Raz Ben Yehuda <raziebe@gmail.com>
 */
//=============================================================================

#ifndef ACE_NETLINK_ADDR_H
#define ACE_NETLINK_ADDR_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
  #pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#ifdef  ACE_HAS_NETLINK

#include "ace/OS_NS_string.h"
#include "ace/Global_Macros.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_unistd.h"
#include "ace/Addr.h"
#include "ace/os_include/sys/os_socket.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Netlink_Addr
 *
 * @brief Defines a C++ wrapper facade for the netlink sockets
 */
class ACE_Export ACE_Netlink_Addr : public ACE_Addr {
public:
  // = Initialization methods.

  /// Default constructor.
  ACE_Netlink_Addr (void);

  /// Copy constructor.
  ACE_Netlink_Addr (const ACE_Netlink_Addr &);

  /// Creates an ACE_INET_Addr from a sockaddr_in structure.
  ACE_Netlink_Addr (const sockaddr_nl *, int len);

  /// Dtor
  ~ACE_Netlink_Addr (void);

  /**
   * @param naddr sets the nl_ member @see nl_
   */
  int set (const ACE_Netlink_Addr &naddr);
  /**
   * sets the pid and groups fields of member nl_  @see nl_
   */
  void set (int pid, int gid);
  /**
   * set nl_ to nl_  @see nl_
   */
  int set (const sockaddr_nl *, int len);
  /**
   * @return pid
   */
  int get_pid (void) const;
  /**
   * @return the group id @see nl_
   */
  int get_gid (void) const;
  /**
   * @return addr pointer @see nl_
   */
  virtual void *get_addr (void) const;
  /**
   * @return nl_ member  @see nl_  size
   */
  int get_addr_size (void) const;
  /**
   * Set a pointer to the address
   */
  virtual void set_addr (void *, int len= sizeof(sockaddr_nl) );

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /**
   * @return family type  AF_NETLINK
   *
   * */
  int determine_type (void) const;
  /**
   * set nl_  @see nl_ to zero and sets address family to default value
   */
  void reset (void);

  sockaddr_nl  nl_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Netlink_Addr.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_NETLINK */

#include /**/ "ace/post.h"

#endif /* ACE_NETLINK_ADDR_H */




