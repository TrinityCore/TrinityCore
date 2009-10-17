// -*- C++ -*-

//=============================================================================
/**
 *  @file    SOCK_Dgram_Bcast.h
 *
 *  $Id: SOCK_Dgram_Bcast.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_SOCK_DGRAM_BCAST_H
#define ACE_SOCK_DGRAM_BCAST_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SOCK_Dgram.h"
#include "ace/INET_Addr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Bcast_Node
 *
 * @brief Linked list of broadcast interfaces.
 */
class ACE_Export ACE_Bcast_Node
{
public:
  /// Default constructor.
  ACE_Bcast_Node (ACE_INET_Addr &,
                  ACE_Bcast_Node *);

  /// Destructor.
  ~ACE_Bcast_Node (void);

  /// Broadcast address for the interface.
  ACE_INET_Addr bcast_addr_;

  /// Pointer to the next interface in the chain.
  ACE_Bcast_Node *next_;
};

/**
 * @class ACE_SOCK_Dgram_Bcast
 *
 * @brief Defines the member functions for the ACE_SOCK datagram
 * abstraction.
 */
class ACE_Export ACE_SOCK_Dgram_Bcast : public ACE_SOCK_Dgram
{
public:
  // = Initialization and termination methods.
  /// Default constructor.
  ACE_SOCK_Dgram_Bcast (void);

  ACE_SOCK_Dgram_Bcast (const ACE_Addr &local,
                        int protocol_family = PF_INET,
                        int protocol = 0,
                        int reuse_addr = 0,
                        const ACE_TCHAR *host_name = 0);

  /// Default dtor.
  ~ACE_SOCK_Dgram_Bcast (void);

  // Initiate a connectionless datagram broadcast endpoint.

  /// Initiate a connectionless datagram broadcast endpoint.
  int open (const ACE_Addr &local,
            int protocol_family = PF_INET,
            int protocol = 0,
            int reuse_addr = 0,
            const ACE_TCHAR *host_name = 0);

  /// Close up and release dynamically allocated resources.
  int close (void);

  /// Broadcast the datagram to every interface.  Returns the average
  /// number of bytes sent.
  ssize_t send (const void *buf,
                size_t n,
                u_short portnum,
                int flags = 0) const;

  /// Broadcast the @c iov datagrams to every interface.  Returns the
  /// average number of bytes sent.
  ssize_t send (const iovec iov[],
                int n,
                u_short portnum,
                int flags = 0) const;

  /// Broadcast an N byte datagram to ADDR (note that addr must be
  /// preassigned to the broadcast address of the subnet...).
  ssize_t send (const void *buf,
                size_t n,
                const ACE_Addr &addr,
                int flags = 0) const;

  /**
   * Broadcast an @a iovec of size @a n to @a addr as a datagram (note
   * that addr must be preassigned to the broadcast address of the
   * subnet...)
   */
  ssize_t send (const iovec iov[],
                int n,
                const ACE_Addr &addr,
                int flags = 0) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Make broadcast available for Datagram socket.
  int mk_broadcast (const ACE_TCHAR *host_name);

  /// Points to the head of the list of broadcast interfaces.
  ACE_Bcast_Node *if_list_;

  /// Do not allow this function to percolate up to this interface...
  int get_remote_addr (ACE_Addr &) const;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/SOCK_Dgram_Bcast.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SOCK_DGRAM_BCAST_H */

