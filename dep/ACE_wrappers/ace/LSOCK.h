// -*- C++ -*-
//=============================================================================
/**
 *  @file    LSOCK.h
 *
 *  $Id: LSOCK.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//=============================================================================

#ifndef ACE_LOCAL_SOCK_H
#define ACE_LOCAL_SOCK_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)
#include "ace/SOCK.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_LSOCK
 *
 * @brief Create a Local ACE_SOCK, which is used for passing file
 * descriptors.
 */
class ACE_Export ACE_LSOCK
{
public:
#if defined (ACE_HAS_MSG)
  /// Send an open FD to another process.
  ssize_t send_handle (const ACE_HANDLE handle) const;
  /// Recv an open FD from another process.
  ssize_t recv_handle (ACE_HANDLE &handles,
                       char *pbuf = 0,
                       ssize_t *len = 0) const;
#endif /* ACE_HAS_MSG */
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  // = Ensure that ACE_LSOCK is an abstract base class
  /// Default constructor.
  ACE_LSOCK (void);
  /// Initialize based on @a handle.
  ACE_LSOCK (ACE_HANDLE handle);
  /// Get handle.
  ACE_HANDLE get_handle (void) const;
  /// Set handle.
  void set_handle (ACE_HANDLE handle);
private:
  /// An auxiliary handle used to avoid virtual base classes...
  ACE_HANDLE aux_handle_;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/LSOCK.inl"
#endif /* __ACE_INLINE__ */
#endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */
#include /**/ "ace/post.h"
#endif /* ACE_LOCAL_SOCK_H */

