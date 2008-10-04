/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    SOCK_Acceptor.h
 *
 *  $Id: SOCK_Acceptor.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SOCK_ACCEPTOR_H
#define ACE_SOCK_ACCEPTOR_H
#include /**/ "ace/pre.h"

#include "ace/SOCK_Stream.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;
class ACE_Accept_QoS_Params;

/**
 * @class ACE_SOCK_Acceptor
 *
 * @brief Defines a factory that creates new ACE_Streams passively.
 *
 * The ACE_SOCK_Acceptor has its own "passive-mode" socket.
 * This serves as a factory to create so-called "data-mode"
 * sockets, which are what the ACE_SOCK_Stream encapsulates.
 * Therefore, by inheriting from ACE_SOCK, ACE_SOCK_Acceptor
 * gets its very own socket.
 */
class ACE_Export ACE_SOCK_Acceptor : public ACE_SOCK
{
public:
  // = Initialization and termination methods.
  /// Default constructor.
  ACE_SOCK_Acceptor (void);

  /**
   * Initialize a passive-mode BSD-style acceptor socket (no QoS).
   * @a local_sap is the address that we're going to listen for
   * connections on.  If @a reuse_addr is 1 then we'll use the
   * @c SO_REUSEADDR to reuse this address.
   */
  ACE_SOCK_Acceptor (const ACE_Addr &local_sap,
                     int reuse_addr = 0,
                     int protocol_family = PF_UNSPEC,
                     int backlog = ACE_DEFAULT_BACKLOG,
                     int protocol = 0);

  /// Initialize a passive-mode QoS-enabled acceptor socket.  Returns 0
  /// on success and -1 on failure.
  ACE_SOCK_Acceptor (const ACE_Addr &local_sap,
                     ACE_Protocol_Info *protocolinfo,
                     ACE_SOCK_GROUP g,
                     u_long flags,
                     int reuse_addr,
                     int protocol_family = PF_UNSPEC,
                     int backlog = ACE_DEFAULT_BACKLOG,
                     int protocol = 0);

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
            int protocol = 0);

  /// Initialize a passive-mode QoS-enabled acceptor socket.  Returns 0
  /// on success and -1 on failure.
  int open (const ACE_Addr &local_sap,
            ACE_Protocol_Info *protocolinfo,
            ACE_SOCK_GROUP g,
            u_long flags,
            int reuse_addr,
            int protocol_family = PF_UNSPEC,
            int backlog = ACE_DEFAULT_BACKLOG,
            int protocol = 0);

  /// Close the socket.  Returns 0 on success and -1 on failure.
  int close (void);

  /// Default dtor.
  ~ACE_SOCK_Acceptor (void);

  // = Passive connection <accept> methods.
  /**
   * Accept a new ACE_SOCK_Stream connection.  A @a timeout of 0
   * means block forever, a @a timeout of {0, 0} means poll.  <restart>
   * == 1 means "restart if interrupted," i.e., if errno == EINTR.
   * Note that @a new_stream inherits the "blocking mode" of @c this
   * ACE_SOCK_Acceptor, i.e., if @c this acceptor factory is in
   * non-blocking mode, the @a new_stream will be in non-blocking mode
   * and vice versa.
   */
  int accept (ACE_SOCK_Stream &new_stream,
              ACE_Addr *remote_addr = 0,
              ACE_Time_Value *timeout = 0,
              int restart = 1,
              int reset_new_handle = 0) const;

#if !defined (ACE_HAS_WINCE)
  /**
   * Accept a new ACE_SOCK_Stream connection using the QoS
   * information in @a qos_params.  A @a timeout of 0 means block
   * forever, a @a timeout of {0, 0} means poll.  @a restart == 1 means
   * "restart if interrupted," i.e., if errno == EINTR.  Note that
   * @a new_stream inherits the "blocking mode" of @c this
   * ACE_SOCK_Acceptor, i.e., if @c this acceptor factory is in
   * non-blocking mode, the @a new_stream will be in non-blocking mode
   * and vice versa.
   */
  int accept (ACE_SOCK_Stream &new_stream,
              ACE_Accept_QoS_Params qos_params,
              ACE_Addr *remote_addr = 0,
              ACE_Time_Value *timeout = 0,
              int restart = 1,
              int reset_new_handle = 0) const;
#endif  // ACE_HAS_WINCE

  // = Meta-type info
  typedef ACE_INET_Addr PEER_ADDR;
  typedef ACE_SOCK_Stream PEER_STREAM;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Perform operations that must occur before <ACE_OS::accept> is
  /// called.
  int shared_accept_start (ACE_Time_Value *timeout,
                           int restart,
                           int &in_blocking_mode) const;

  /// Perform operations that must occur after <ACE_OS::accept> is
  /// called.
  int shared_accept_finish (ACE_SOCK_Stream new_stream,
                            int in_blocking_mode,
                            int reset_new_handle) const;

  /**
   * This method factors out the common <open> code and is called by
   * both the QoS-enabled <open> method and the BSD-style <open>
   * method.
   */
  int shared_open (const ACE_Addr &local_sap,
                   int protocol_family,
                   int backlog);

private:
  /// Do not allow this function to percolate up to this interface...
  int get_remote_addr (ACE_Addr &) const;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/SOCK_Acceptor.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SOCK_ACCEPTOR_H */
