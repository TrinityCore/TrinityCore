// -*- C++ -*-

//=============================================================================
/**
 *  @file    SOCK_SEQPACK_Acceptor.h
 *
 *  $Id: SOCK_SEQPACK_Acceptor.h 84325 2009-02-04 22:46:30Z shuston $
 *  @author  Patrick J. Lardieri <plardier@atl.lmco.com>
 *  @author  Gaurav Naik, Lockheed Martin ATL
 *  @author  based on SOCK_STREAM_Acceptor
 *            by Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *
 */
//=============================================================================

#ifndef ACE_SOCK_SEQ_ACCEPTOR_H
#define ACE_SOCK_SEQ_ACCEPTOR_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SOCK_SEQPACK_Association.h"
#include "ace/Multihomed_INET_Addr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;

/**
 * @class ACE_SOCK_SEQPACK_Acceptor
 *
 * @brief Defines a factory that creates new ACE_Associations passively.
 *
 * The <ACE_SOCK_SEQPACK_Acceptor> has its own "passive-mode" socket.
 * This serves as a factory to create so-called "data-mode"
 * sockets, which are what the ACE_SOCK_SEQPACK_Association encapsulates.
 * Therefore, by inheriting from <ACE_SOCK>, <ACE_SOCK_SEQPACK_Acceptor>
 * gets its very own socket.
 */
class ACE_Export ACE_SOCK_SEQPACK_Acceptor : public ACE_SOCK
{
public:
  // = Initialization and termination methods.
  /// Default constructor.
  ACE_SOCK_SEQPACK_Acceptor (void);

  /**
   * Initialize a passive-mode BSD-style acceptor socket (no QoS).
   * @a local_sap is the address that we're going to listen for
   * connections on.  If @a reuse_addr is 1 then we'll use the
   * @c SO_REUSEADDR to reuse this address.
   */
  ACE_SOCK_SEQPACK_Acceptor (const ACE_Addr &local_sap,
                             int reuse_addr = 0,
                             int protocol_family = PF_UNSPEC,
                             int backlog = ACE_DEFAULT_BACKLOG,
                             int protocol = 132);

  /// Multihomed version of same

  ACE_SOCK_SEQPACK_Acceptor (const ACE_Multihomed_INET_Addr &local_sap,
                             int reuse_addr = 0,
                             int protocol_family = PF_UNSPEC,
                             int backlog = ACE_DEFAULT_BACKLOG,
                             int protocol = 132);

  /// Initialize a passive-mode QoS-enabled acceptor socket.  Returns 0
  /// on success and -1 on failure.
  ACE_SOCK_SEQPACK_Acceptor (const ACE_Addr &local_sap,
                             ACE_Protocol_Info *protocolinfo,
                             ACE_SOCK_GROUP g,
                             u_long flags,
                             int reuse_addr,
                             int protocol_family = PF_UNSPEC,
                             int backlog = ACE_DEFAULT_BACKLOG,
                             int protocol = 132);

  /**
   * Initialize a passive-mode BSD-style acceptor socket (no QoS).
   * @a local_sap is the address that we're going to listen for
   * connections on.  If @a reuse_addr is 1 then we'll use the
   * @c SO_REUSEADDR to reuse this address.  Returns 0 on success and
   * -1 on failure.
   */
  int open (const ACE_Addr &local_sap,
            int reuse_addr = 0,
            int protocol_family = PF_UNSPEC,
            int backlog = ACE_DEFAULT_BACKLOG,
            int protocol = 132);

  /// Multihomed version of same

  int open (const ACE_Multihomed_INET_Addr &local_sap,
            int reuse_addr = 0,
            int protocol_family = PF_UNSPEC,
            int backlog = ACE_DEFAULT_BACKLOG,
            int protocol = 132);


  /// Initialize a passive-mode QoS-enabled acceptor socket.  Returns 0
  /// on success and -1 on failure.
  int open (const ACE_Addr &local_sap,
            ACE_Protocol_Info *protocolinfo,
            ACE_SOCK_GROUP g,
            u_long flags,
            int reuse_addr,
            int protocol_family = PF_UNSPEC,
            int backlog = ACE_DEFAULT_BACKLOG,
            int protocol = 132);

  /// Close the socket.  Returns 0 on success and -1 on failure.
  int close (void);

  /// Default dtor.
  ~ACE_SOCK_SEQPACK_Acceptor (void);

  // = Passive connection <accept> methods.
  /**
   * Accept a new ACE_SOCK_SEQPACK_Association connection.  A @a timeout of 0
   * means block forever, a @a timeout of {0, 0} means poll.  <restart>
   * == 1 means "restart if interrupted," i.e., if errno == EINTR.
   * Note that <new_association> inherits the "blocking mode" of @c this
   * <ACE_SOCK_SEQPACK_Acceptor>, i.e., if @c this acceptor factory is in
   * non-blocking mode, the <net_association> will be in non-blocking mode
   * and vice versa.
   */
  int accept (ACE_SOCK_SEQPACK_Association &new_association,
              ACE_Addr *remote_addr = 0,
              ACE_Time_Value *timeout = 0,
              bool restart = true,
              bool reset_new_handle = false) const;

  // = Meta-type info
  typedef ACE_Multihomed_INET_Addr PEER_ADDR;
  typedef ACE_SOCK_SEQPACK_Association PEER_STREAM;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Perform operations that must occur before <ACE_OS::accept> is
  /// called.
  int shared_accept_start (ACE_Time_Value *timeout,
                           bool restart,
                           int &in_blocking_mode) const;

  /// Perform operations that must occur after <ACE_OS::accept> is
  /// called.
  int shared_accept_finish (ACE_SOCK_SEQPACK_Association new_association,
                            int in_blocking_mode,
                            bool reset_new_handle) const;

  /**
   * This method factors out the common <open> code and is called by
   * both the QoS-enabled <open> method and the BSD-style <open>
   * method.
   */
  int shared_open (const ACE_Addr &local_sap,
                   int protocol_family,
                   int backlog);

  /// Multihomed version of same.

  int shared_open (const ACE_Multihomed_INET_Addr &local_sap,
                   int protocol_family,
                   int backlog);

private:
  /// Do not allow this function to percolate up to this interface...
  int get_remote_addr (ACE_Addr &) const;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/SOCK_SEQPACK_Acceptor.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_SOCK_SEQ_ACCEPTOR_H */
