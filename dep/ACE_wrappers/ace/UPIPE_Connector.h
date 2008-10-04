// -*- C++ -*-

//=============================================================================
/**
 *  @file    UPIPE_Connector.h
 *
 *  $Id: UPIPE_Connector.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Gerhard Lenzer and Douglas C. Schmidt
 */
//=============================================================================


#ifndef ACE_UPIPE_CONNECTOR_H
#define ACE_UPIPE_CONNECTOR_H
#include /**/ "ace/pre.h"

#include "ace/UPIPE_Stream.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_THREADS)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_UPIPE_Connector
 *
 * @brief Defines an active connection factory for the
 * ACE_UPIPE_STREAM wrappers.
 */
class ACE_Export ACE_UPIPE_Connector
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_UPIPE_Connector (void);

  /**
   * Actively connect and produce a @a new_stream if things go well.
   * The @a addr is the address that we are trying to connect
   * with.  The @a timeout is the amount of time to wait to connect.
   * If it's 0 then we block indefinitely.  If *timeout == {0, 0} then
   * the connection is done using non-blocking mode.  In this case, if
   * the connection can't be made immediately the value of -1 is
   * returned with @c errno == EWOULDBLOCK.  If *timeout > {0, 0} then
   * this is the maximum amount of time to wait before timing out.  If the
   * time expires before the connection is made @c errno == ETIME.  The
   * @a local_sap is the value of local address to bind to.  If it's
   * the default value of ACE_Addr::sap_any then the user is letting
   * the OS do the binding.  If @a reuse_addr == 1 then the
   * @a local_addr is reused, even if it hasn't been cleanedup yet.
   * The @a flags and @a perms arguments are passed down to the open()
   * method.
   */
  ACE_UPIPE_Connector (ACE_UPIPE_Stream &new_stream,
                       const ACE_UPIPE_Addr &addr,
                       ACE_Time_Value *timeout = 0,
                       const ACE_Addr &local_sap = ACE_Addr::sap_any,
                       int reuse_addr = 0,
                       int flags = O_RDWR,
                       int perms = 0);

  /**
   * Actively connect and produce a @a new_stream if things go well.
   * The @a addr is the address that we are trying to connect
   * with.  The @a timeout is the amount of time to wait to connect.
   * If it's 0 then we block indefinitely.  If *timeout == {0, 0} then
   * the connection is done using non-blocking mode.  In this case, if
   * the connection can't be made immediately the value of -1 is
   * returned with @c errno == EWOULDBLOCK.  If *timeout > {0, 0} then
   * this is the maximum amount of time to wait before timing out.  If the
   * time expires before the connection is made @c errno == ETIME.  The
   * @a local_sap is the value of local address to bind to.  If it's
   * the default value of ACE_Addr::sap_any then the user is letting
   * the OS do the binding.  If @a reuse_addr == 1 then the
   * @a local_addr is reused, even if it hasn't been cleanedup yet.
   * The @a flags and @a perms arguments are passed down to the open()
   * method.
   */
  int connect (ACE_UPIPE_Stream &new_stream,
               const ACE_UPIPE_Addr &addr,
               ACE_Time_Value *timeout = 0,
               const ACE_Addr &local_sap = ACE_Addr::sap_any,
               int reuse_addr = 0,
               int flags = O_RDWR,
               int perms = 0);

  /// Resets any event associations on this handle
  int reset_new_handle (ACE_HANDLE handle);

  // = Meta-type info
  typedef ACE_UPIPE_Addr PEER_ADDR;
  typedef ACE_UPIPE_Stream PEER_STREAM;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/UPIPE_Connector.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_THREADS */

#include /**/ "ace/post.h"

#endif /* ACE_UPIPE_CONNECTOR_H */
