/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    ATM_Connector.h
 *
 *  $Id: ATM_Connector.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Joe Hoffert <joeh@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_ATM_CONNECTOR_H
#define ACE_ATM_CONNECTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_ATM)

#include "ace/ATM_Stream.h"
#include "ace/ATM_Params.h"
#include "ace/ATM_QoS.h"

#if defined (ACE_WIN32) || defined (ACE_HAS_LINUX_ATM)
#include "ace/SOCK_Connector.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef ACE_SOCK_Connector ATM_Connector;
ACE_END_VERSIONED_NAMESPACE_DECL
#else
#include "ace/XTI_ATM_Mcast.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef ACE_XTI_ATM_Mcast ATM_Connector;
// Open versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL
#endif

// Open versioned namespace, if enabled by the user.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_ATM_Connector
 *
 * @brief Defines an active connection factory for the ACE_ATM C++
 * wrappers.
 */
class ACE_Export ACE_ATM_Connector
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_ATM_Connector (void);

  /**
   * Actively connect and produce a @a new_stream if things go well.
   * The @a remote_sap is the address that we are trying to connect
   * with.  The <params> are the parameters needed for either socket
   * or XTI/ATM connections.  The @a timeout is the amount of time to
   * wait to connect. If it's 0 then we block indefinitely.  If
   * *timeout == {0, 0} then the connection is done using non-blocking
   * mode.  In this case, if the connection can't be made immediately
   * the value of -1 is returned with @c errno == EWOULDBLOCK.  If
   * *timeout > {0, 0} then this is the maximum amount of time to wait before
   * timing out.  If the time expires before the connection is made
   * @c errno == ETIME.  The @a local_sap is the value of local address
   * to bind to.  If it's the default value of <ACE_ATM_Addr::sap_any> then
   * the user is letting the OS do the binding.  If @a reuse_addr == 1
   * then the <local_addr> is reused, even if it hasn't been cleanedup yet.
   */
  ACE_ATM_Connector (ACE_ATM_Stream &new_stream,
                     const ACE_ATM_Addr &remote_sap,
                     ACE_ATM_Params params = ACE_ATM_Params(),
                     ACE_ATM_QoS options = ACE_ATM_QoS(),
                     ACE_Time_Value *timeout = 0,
                     const ACE_ATM_Addr &local_sap = ACE_ATM_Addr( "", 0 ),
                     int reuse_addr = 0,
#if defined (ACE_WIN32)
                     int flags = 0,
#else
                     int flags = O_RDWR,
#endif /* ACE_WIN32 */
                     int perms = 0);

  /**
   * Actively connect and produce a @a new_stream if things go well.
   * The @a remote_sap is the address that we are trying to connect
   * with.  The <params> are the parameters needed for either socket
   * or XTI/ATM connections.  The @a timeout is the amount of time to
   * wait to connect. If it's 0 then we block indefinitely.  If
   * *timeout == {0, 0} then the connection is done using non-blocking
   * mode.  In this case, if the connection can't be made immediately
   * the value of -1 is returned with @c errno == EWOULDBLOCK.  If
   * *timeout > {0, 0} then this is the maximum amount of time to wait before
   * timing out.  If the time expires before the connection is made
   * @c errno == ETIME.  The @a local_sap is the value of local address
   * to bind to.  If it's the default value of <ACE_ATM_Addr::sap_any> then
   * the user is letting the OS do the binding.  If @a reuse_addr == 1
   * then the <local_addr> is reused, even if it hasn't been cleanedup yet.
   */
  int connect (ACE_ATM_Stream &new_stream,
               const ACE_ATM_Addr &remote_sap,
               ACE_ATM_Params params = ACE_ATM_Params(),
               ACE_ATM_QoS options = ACE_ATM_QoS(),
               ACE_Time_Value *timeout = 0,
               const ACE_ATM_Addr &local_sap = ACE_ATM_Addr( "",
                                                             0 ),
               int reuse_addr = 0,
#if defined (ACE_WIN32)
               int flags = 0,
#else
               int flags = O_RDWR,
#endif /* ACE_WIN32 */
               int perms = 0);

  /**
   * Try to complete a non-blocking connection.
   * If connection completion is successful then @a new_stream contains
   * the connected ACE_SOCK_Stream.  If @a remote_sap is non-NULL then it
   * will contain the address of the connected peer.
   */
  int complete (ACE_ATM_Stream &new_stream,
                ACE_ATM_Addr *remote_sap,
                ACE_Time_Value *tv);

  /**
   * Actively add a leaf to the root (i.e., point-to-multipoint). The
   * @a remote_sap is the address of the leaf that we
   * are trying to add.
   */
  int add_leaf (ACE_ATM_Stream &current_stream,
                const ACE_Addr &remote_sap,
                ACE_ATM_QoS &qos);

  /// Resets any event associations on this handle
  int reset_new_handle (ACE_HANDLE handle);

  // = Meta-type info
  typedef ACE_ATM_Addr PEER_ADDR;
  typedef ACE_ATM_Stream PEER_STREAM;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  ATM_Connector connector_;
};

// Open versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/ATM_Connector.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_ATM */
#include /**/ "ace/post.h"
#endif /* ACE_ATM_CONNECTOR_H */

