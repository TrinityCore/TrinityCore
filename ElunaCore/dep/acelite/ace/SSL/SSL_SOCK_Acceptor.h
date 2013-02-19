// -*- C++ -*-

//=============================================================================
/**
 *  @file    SSL_SOCK_Acceptor.h
 *
 *  $Id: SSL_SOCK_Acceptor.h 82723 2008-09-16 09:35:44Z johnnyw $
 *
 *  @author John Heitmann
 *  @author Chris Zimman
 *  @author Ossama Othman <ossama@uci.edu>
 */
//=============================================================================

#ifndef ACE_SSL_SOCK_ACCEPTOR_H
#define ACE_SSL_SOCK_ACCEPTOR_H

#include /**/ "ace/pre.h"

#include "SSL_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "SSL_SOCK_Stream.h"

#include "ace/SOCK_Acceptor.h"
#include "ace/OS_QoS.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_SSL_SOCK_Acceptor
 *
 * @brief Defines a factory that creates new @c ACE_SSL_SOCK_Stream
 * objects passively.
 *
 * The ACE_SSL_SOCK_Acceptor has its own @c ACE_SOCK_Acceptor
 * which handles the basic socket acceptance.  This class is a
 * wrapper which adds the SSL acceptance handshake handling.
 * Since SSL is record oriented, some additional steps must be taken
 * after the basic socket acceptance to complete the SSL handshake that
 * takes place at session establishment.
 *
 * @note The user must currently ensure that only one thread services
 *       a given SSL session at any given time since some underlying
 *       SSL implementations, such as OpenSSL, are not entirely
 *       thread-safe or reentrant.
 */
class ACE_SSL_Export ACE_SSL_SOCK_Acceptor : public ACE_SSL_SOCK
{
public:

  /// Default constructor.
  ACE_SSL_SOCK_Acceptor (void);

  /// Default destructor.
  ~ACE_SSL_SOCK_Acceptor (void);

  /**
   * Initiate a passive mode SSL/BSD-style acceptor socket.
   * @param local_sap  The address that we're going to listen for
   *                   connections on. If this is @c ACE_Addr::sap_any,
   *                   this socket listens on an the "any" IP address
   *                   and selects an unused port. To find out what port
   *                   was selected, call this object's
   *                   @c ACE_SOCK::get_local_addr(ACE_Addr&) method
   *                   upon return.
   */
  ACE_SSL_SOCK_Acceptor (const ACE_Addr &local_sap,
                         int reuse_addr = 0,
                         int protocol_family = PF_UNSPEC,
                         int backlog = ACE_DEFAULT_BACKLOG,
                         int protocol = 0);

  /**
   * Initiate a passive-mode QoS-enabled acceptor socket.
   * @param local_sap  The address that we're going to listen for
   *                   connections on. If this is @c ACE_Addr::sap_any,
   *                   this socket listens on an the "any" IP address
   *                   and selects an unused port. To find out what port
   *                   was selected, call this object's
   *                   @c ACE_SOCK::get_local_addr(ACE_Addr&) method
   *                   upon return.
   */
  ACE_SSL_SOCK_Acceptor (const ACE_Addr &local_sap,
                         ACE_Protocol_Info *protocolinfo,
                         ACE_SOCK_GROUP g,
                         u_long flags,
                         int reuse_addr,
                         int protocol_family = PF_UNSPEC,
                         int backlog = ACE_DEFAULT_BACKLOG,
                         int protocol = 0);

  /**
   * Initiate a passive mode SSL/BSD-style acceptor socket.
   * @param local_sap  The address that we're going to listen for
   *                   connections on. If this is @c ACE_Addr::sap_any,
   *                   this socket listens on an the "any" IP address
   *                   and selects an unused port. To find out what port
   *                   was selected, call this object's
   *                   @c ACE_SOCK::get_local_addr(ACE_Addr&) method
   *                   upon return.
   *
   * @return 0 if success; -1 for failure (errno contains error code).
   */
  int open (const ACE_Addr &local_sap,
            int reuse_addr = 0,
            int protocol_family = PF_UNSPEC,
            int backlog = ACE_DEFAULT_BACKLOG,
            int protocol = 0);

  /// Close the listening socket.
  int close (void);

  /**
   * @name Passive Connection "accept" Methods
   *
   * These are the canonical methods exposed by the Acceptor pattern.
   */
  //@{
  /**
   * Accept a new ACE_SSL_SOCK_Stream connection. On successful return,
   * the socket has been accepted and the SSL handshake has been completed.
   * @param new_stream  The @c ACE_SSL_SOCK_Stream object that will receive
   *                    the new SSL socket.
   * @param remote_addr Pointer to an @c ACE_INET_Addr object that will
   *                    receive the address of the peer that connected.
   * @param timeout     The maximum time to wait for the combined socket
   *                    acceptance and handshake completion. 0 means
   *                    block forever, a timeout of {0, 0} means poll.
   * @param restart     1 means "restart if interrupted," that is,
   *                    if errno == EINTR.
   *
   * @return 0 if success; -1 for failure (errno contains error code).
   */
  int accept (ACE_SSL_SOCK_Stream &new_stream,
              ACE_Addr *remote_addr = 0,
              ACE_Time_Value *timeout = 0,
              bool restart = true,
              bool reset_new_handle = false) const;

  /**
   * Accept a new ACE_SSL_SOCK_Stream connection using the RVSP QoS
   * information in qos_params.
   * @param new_stream  The @c ACE_SSL_SOCK_Stream object that will receive
   *                    the new SSL socket.
   * @param remote_addr Pointer to an @c ACE_INET_Addr object that will
   *                    receive the address of the peer that connected.
   * @param timeout     The maximum time to wait for the combined socket
   *                    acceptance and handshake completion. 0 means
   *                    block forever, a timeout of {0, 0} means poll.
   * @param restart     1 means "restart if interrupted," that is,
   *                    if errno == EINTR.
   *
   * @return 0 if success; -1 for failure (errno contains error code).
   */
  int accept (ACE_SSL_SOCK_Stream &new_stream,
              ACE_Accept_QoS_Params qos_params,
              ACE_Addr *remote_addr = 0,
              ACE_Time_Value *timeout = 0,
              bool restart = true,
              bool reset_new_handle = false) const;
  //@}

  /// Meta-type info
  //@{
  typedef ACE_INET_Addr PEER_ADDR;
  typedef ACE_SSL_SOCK_Stream PEER_STREAM;
  //@}

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:

  /// Complete SSL passive connection establishment.
  int ssl_accept (ACE_SSL_SOCK_Stream &new_stream,
                  ACE_Time_Value *timeout) const;

private:

  /// The BSD-socket workhorse
  ACE_SOCK_Acceptor acceptor_;

};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "SSL_SOCK_Acceptor.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_SSL_SOCK_ACCEPTOR_H */
