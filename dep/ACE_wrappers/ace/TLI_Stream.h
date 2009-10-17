// -*- C++ -*-

//=============================================================================
/**
 *  @file    TLI_Stream.h
 *
 *  $Id: TLI_Stream.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//=============================================================================

#ifndef ACE_TLI_STREAM_H
#define ACE_TLI_STREAM_H
#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/TLI.h"

#include "ace/INET_Addr.h"

#if defined (ACE_HAS_TLI)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;

/**
 * @class ACE_TLI_Stream
 *
 * @brief Defines the member functions for ACE_TLI_Stream abstraction.
 */
class ACE_Export ACE_TLI_Stream : public ACE_TLI
{
public:
  friend class ACE_TLI_Acceptor;
  friend class ACE_TLI_Connector;

  // = Initialization and termination methods.
  /// Default constructor.
  ACE_TLI_Stream (void);

  // = TLI-specific shutdown operations.
  /// Close down and release resources.
  int close (void);

  /// Send a release and then await the release from the other side.
  int active_close (void);

  /// Acknowledge the release from the other side and then send the
  /// release to the other side.
  int passive_close (void);

  /// Return address of remotely connected peer.
  int get_remote_addr (ACE_Addr &) const;

  // =  timod bindings
  /// Send an n byte buffer to the connected socket (uses t_snd(3)).
  ssize_t send (const void *buf,
                size_t n,
                int flags,
                const ACE_Time_Value *timeout = 0) const;

  /// Recv an n byte buffer from the connected socket (uses t_rcv(3)).
  ssize_t recv (void *buf,
                size_t n,
                int *flags,
                const ACE_Time_Value *timeout = 0) const;

  /// Send exactly n bytes to the connected socket (uses t_snd(3)).
  ssize_t send_n (const void *buf,
                  size_t n,
                  int flags,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0) const;

  /// Recv exactly n bytes from the connected socket (uses t_rcv(3)).
  ssize_t recv_n (void *buf,
                  size_t n,
                  int *flags,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0) const;

  // = tirdwr bindings
  /// Send an n byte buffer to the connected socket (uses write(2)).
  ssize_t send (const void *buf,
                size_t n,
                const ACE_Time_Value *timeout = 0) const;

  /// Recv an n byte buffer from the connected socket (uses read(2)).
  ssize_t recv (void *buf,
                size_t n,
                const ACE_Time_Value *timeout = 0) const;

  /// Send n bytes, keep trying until n are sent (uses write(2)).
  ssize_t send_n (const void *buf,
                  size_t n,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0) const;

  /// Recv n bytes, keep trying until n are received (uses read (2)).
  ssize_t recv_n (void *buf,
                  size_t n,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0) const;

  // = Meta-type info
  typedef ACE_INET_Addr PEER_ADDR;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Indicates whether the tirdwr module should be pushed
  int rwflag_;

  /// Get rwflag
  int get_rwflag (void) const;

  /// Set rwflag
  void set_rwflag (int value);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/TLI_Stream.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_TLI */
#include /**/ "ace/post.h"
#endif /* ACE_TLI_STREAM_H */

