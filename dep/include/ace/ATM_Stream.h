/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    ATM_Stream.h
 *
 *  $Id: ATM_Stream.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Joe Hoffert
 */
//=============================================================================

#ifndef ACE_ATM_STREAM_H
#define ACE_ATM_STREAM_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_ATM)

#include "ace/ATM_Addr.h"
#include "ace/ATM_Params.h"

#if defined (ACE_WIN32)
#include "ace/SOCK_Stream.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef ACE_SOCK_Stream ATM_Stream;
ACE_END_VERSIONED_NAMESPACE_DECL
#else
#include "ace/TLI_Stream.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef ACE_TLI_Stream ATM_Stream;
ACE_END_VERSIONED_NAMESPACE_DECL
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_ATM_Stream
 *
 * @brief Defines the member functions for ACE_ATM_Stream abstraction.
 */
class ACE_Export ACE_ATM_Stream
{
public:
  // = Initialization and termination methods.
  /// Default constructor.
  ACE_ATM_Stream (void);

  // = ATM-specific open and shutdown operations.
  /// open the stream.
  int open (ACE_ATM_Params params = ACE_ATM_Params());

  /// Close down and release resources.
  int close (void);

  /// Get the underlying handle.
  ACE_HANDLE get_handle (void) const;

  /// Get the underlying stream.
  ATM_Stream& get_stream (void);

  /// Get the name of the connected host.
  char* get_peer_name (void) const;

  /// Get the VPI and VCI of the stream.
  int get_vpi_vci (ACE_UINT16 &vpi,
                   ACE_UINT16 &vci) const;

  /// Recv an n byte buffer from the connected transport mechanism.
  ssize_t recv (void *buf,
                size_t n,
                int *flags = 0) const;

  /// Send exactly n bytes to the connected transport mechanism.
  ssize_t send_n (const void *buf,
                  size_t n,
                  int flags) const;

  // = Meta-type info
  typedef ACE_ATM_Addr PEER_ADDR;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Typedef'd to the appropriate stream mechanism above.
  ATM_Stream stream_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/ATM_Stream.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_ATM */
#include /**/ "ace/post.h"
#endif /* ACE_ATM_STREAM_H */

