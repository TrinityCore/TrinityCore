// -*- C++ -*-

//=============================================================================
/**
 *  @file    MEM_Stream.h
 *
 *  $Id: MEM_Stream.h 92069 2010-09-28 11:38:59Z johnnyw $
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================


#ifndef ACE_MEM_STREAM_H
#define ACE_MEM_STREAM_H
#include /**/ "ace/pre.h"

#include "ace/MEM_IO.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)

#include "ace/INET_Addr.h"

#if !defined (ACE_MEM_STREAM_MIN_BUFFER)
# define ACE_MEM_STREAM_MIN_BUFFER 4096
#endif /* ACE_MEM_STREAM_MIN_BUFFER */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_MEM_Acceptor;
class ACE_MEM_Connector;

/**
 * @class ACE_MEM_Stream
 *
 * @brief Defines the methods in the ACE_MEM_Stream abstraction.
 *
 * This adds additional wrapper methods atop the ACE_MEM_IO
 * class.  Notice that ACE_MEM_Stream can only send messages no bigger
 * than the underlying MMAP file size minus sizeof (ACE_MEM_SAP_Node).
 * The size of the MMAP file is default to ACE_MEM_STREAM_MIN_BUFFER.
 * (Define above in this file, to 4096 bytes.)
 * If you need to increase the size of allowable message
 * ACE_MEM_Stream can handle, you can set it to either
 * @c ACE_MEM_Acceptor::malloc_options(). minimal_bytes_
 * @c ACE_MEM_Acceptor::init_buffer_size (size_t size);
 * before establishing a connection.
 */
class ACE_Export ACE_MEM_Stream : public ACE_MEM_IO
{
public:

  friend class ACE_MEM_Acceptor;
  friend class ACE_MEM_Connector;

  // Initialization and termination methods.
  /// Constructor.
  ACE_MEM_Stream (void);

  /// Constructor (sets the underlying ACE_HANDLE with <h>).
  ACE_MEM_Stream (ACE_HANDLE h);

  /// Destructor.
  ~ACE_MEM_Stream (void);

  //= The following two methods use write and read system calls.
  /// Send n bytes, keep trying until n are sent.
  /// Recv n bytes, keep trying until n are received.
  ssize_t send_n (const void *buf, size_t n);
  ssize_t recv_n (void *buf, size_t n);

  // = The following two methods use the send and recv system calls.
  /// Send n bytes, keep trying until n are sent.
  /// Recv n bytes, keep trying until n are received.
  ssize_t send_n (const void *buf, size_t n, int flags);
  ssize_t recv_n (void *buf, size_t n, int flags);

  // = Selectively close endpoints.

  /// Close down the reader.
  int close_reader (void);

  /// Close down the writer.
  int close_writer (void);

  /**
   * Close down the socket (we need this to make things work correctly
   * on Win32, which requires use to do a <close_writer> before doing
   * the close to avoid losing data).
   */
  int close (void);

  // = Meta-type info
  typedef ACE_Addr PEER_ADDR;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/MEM_Stream.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */

#include /**/ "ace/post.h"
#endif /* ACE_MEM_STREAM_H */
