/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    LSOCK_Stream.h
 *
 *  $Id: LSOCK_Stream.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//=============================================================================

#ifndef ACE_LOCAL_SOCK_STREAM_H
#define ACE_LOCAL_SOCK_STREAM_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)
#include "ace/SOCK_Stream.h"
#include "ace/UNIX_Addr.h"
#include "ace/LSOCK.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_LSOCK_Stream
 *
 * @brief Create a Local ACE_SOCK stream.
 */
class ACE_Export ACE_LSOCK_Stream : public ACE_SOCK_Stream, public ACE_LSOCK
{
public:
  // = Send/recv methods.
  /// Send iovecs via <::writev>.
  ssize_t send_msg (const iovec iov[],
                    size_t n,
                    ACE_HANDLE handle);
  /// Send iovecs via <::writev>.
  ssize_t recv_msg (iovec iov[],
                    size_t n,
                    ACE_HANDLE &handle);
  /// Get handle.
  ACE_HANDLE get_handle (void) const;
  /// Overrides set_handle from the base classes.
  void set_handle (ACE_HANDLE fd);
  // = Meta-type info
  typedef ACE_UNIX_Addr PEER_ADDR;
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
  /// This method simply returns the "local" addr.
  int get_local_addr (ACE_Addr &) const;
  /// This method returns the "local" addr since it's the same value
  /// for UNIX domain sockets.
  int get_remote_addr (ACE_Addr &) const;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/LSOCK_Stream.inl"
#endif /* __ACE_INLINE__ */
#endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */
#include /**/ "ace/post.h"
#endif /* ACE_LOCAL_SOCK_STREAM_H */

