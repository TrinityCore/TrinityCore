// -*- C++ -*-

//=============================================================================
/**
 *
 *  @file    SOCK_SEQPACK_Association.h
 *
 *  $Id: SOCK_SEQPACK_Association.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author  Patrick J. Lardieri <plardier@atl.lmco.com>
 *  @author  Gaurav Naik, Lockheed Martin ATL
 *  @author  based on SOCK_Stream
 *            by Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *
 */
//=============================================================================

#ifndef ACE_SOCK_SEQPACK_ASSOCIATION_H
#define ACE_SOCK_SEQPACK_ASSOCIATION_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SOCK_IO.h"
#include "ace/Multihomed_INET_Addr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declarations.
class ACE_Message_Block;

/**
 * @class ACE_SOCK_SEQPACK_Association
 *
 * @brief Defines the methods in the ACE_SOCK_SEQPACK_Association abstraction.
 *
 * This adds additional wrapper methods atop the <ACE_SOCK_IO>
 * class.
 *
 * @a buf is the buffer to write from or receive into.
 * @a len is the number of bytes to transfer.
 * The @a timeout parameter in the following methods indicates how
 * long to blocking trying to transfer data.  If @a timeout == 0,
 * then the call behaves as a normal send/recv call, i.e., for
 * blocking sockets, the call will block until action is possible;
 * for non-blocking sockets, EWOULDBLOCK will be returned if no
 * action is immediately possible.
 * If @a timeout != 0, the call will wait for data to arrive no longer
 * than the relative time specified in *@a timeout.
 * The "_n()" I/O methods keep looping until all the data has been
 * transferred.  These methods also work for sockets in non-blocking
 * mode i.e., they keep looping on EWOULDBLOCK.  @a timeout is used
 * to make sure we keep making progress, i.e., the same timeout
 * value is used for every I/O operation in the loop and the timeout
 * is not counted down.
 * The return values for the "*_n()" methods match the return values
 * from the non "_n()" methods and are specified as follows:
 * - On complete transfer, the number of bytes transferred is returned.
 * - On timeout, -1 is returned, errno == ETIME.
 * - On error, -1 is returned, errno is set to appropriate error.
 * - On EOF, 0 is returned, errno is irrelevant.
 *
 * On partial transfers, i.e., if any data is transferred before
 * timeout/error/EOF, <bytes_transferred> will contain the number of
 * bytes transferred.
 * Methods with <iovec> parameter are I/O vector variants of the I/O
 * operations.
 * Methods with the extra @a flags argument will always result in
 * <send> getting called. Methods without the extra @a flags argument
 * will result in <send> getting called on Win32 platforms, and
 * <write> getting called on non-Win32 platforms.
 */
class ACE_Export ACE_SOCK_SEQPACK_Association : public ACE_SOCK_IO
{
public:
  // Initialization and termination methods.
  /// Constructor.
  ACE_SOCK_SEQPACK_Association (void);

  /// Constructor (sets the underlying ACE_HANDLE with <h>).
  ACE_SOCK_SEQPACK_Association (ACE_HANDLE h);

  /// Destructor.
  ~ACE_SOCK_SEQPACK_Association (void);

  /**
   * Return local endpoint addresses in the referenced array of
   * ACE_INET_Addr, which should have the specified @a size.  If the
   * number of local endpoint addresses is less than @a size, then
   * @a size will be set to this number.  If successful, the method
   * returns 0, otherwise returns -1.
   */
  int get_local_addrs (ACE_INET_Addr *addrs, size_t &size) const;

  /**
   * Return remote endpoint addresses in the referenced array of
   * ACE_INET_Addr, which should have the specified @a size.  If the
   * number of remote endpoint addresses is less than @a size, then
   * @a size will be set to this number.  If successful, the method
   * returns 0, otherwise returns -1.
   */
  int get_remote_addrs (ACE_INET_Addr *addrs, size_t &size) const;

  // = I/O functions.

  /// Try to recv exactly @a len bytes into @a buf from the connected socket.
  ssize_t recv_n (void *buf,
                  size_t len,
                  int flags,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0) const;

  /// Try to recv exactly @a len bytes into @a buf from the connected socket.
  ssize_t recv_n (void *buf,
                  size_t len,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0) const;

  /// Receive an <iovec> of size <iovcnt> from the connected socket.
  ssize_t recvv_n (iovec iov[],
                   int iovcnt,
                   const ACE_Time_Value *timeout = 0,
                   size_t *bytes_transferred = 0) const;

  /// Try to send exactly @a len bytes from @a buf to the connection socket.
  ssize_t send_n (const void *buf,
                  size_t len,
                  int flags,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0) const;

  /// Try to send exactly @a len bytes from @a buf to the connected socket.
  ssize_t send_n (const void *buf,
                  size_t len,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0) const;

  /// Send all the @a message_blocks chained through their <next> and
  /// <cont> pointers.  This call uses the underlying OS gather-write
  /// operation to reduce the domain-crossing penalty.
  ssize_t send_n (const ACE_Message_Block *message_block,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0) const;

  /// Send an <iovec> of size <iovcnt> to the connected socket.
  ssize_t sendv_n (const iovec iov[],
                   int iovcnt,
                   const ACE_Time_Value *timeout = 0,
                   size_t *bytes_transferred = 0) const;

  // = Send/receive ``urgent'' data (see TCP specs...).
  ssize_t send_urg (const void *ptr,
                    size_t len = sizeof (char),
                    const ACE_Time_Value *timeout = 0) const;

  ssize_t recv_urg (void *ptr,
                    size_t len = sizeof (char),
                    const ACE_Time_Value *timeout = 0) const;

  // = Selectively close endpoints.
  /// Close down the reader.
  int close_reader (void);

  /// Close down the writer.
  int close_writer (void);

  /**
   * Close down the socket (we need this to make things work correctly
   * on Win32, which requires use to do a <close_writer> before doing
   * the close to avoid losing data).  */
  int close (void);

  /**
   * Abort the association according to RFC 2960 9.1 through the API
   * in draft-ietf-tsvwg-sctpsocket-09 7.1.4.
   */
  int abort (void);

  // = Meta-type info
  typedef ACE_Multihomed_INET_Addr PEER_ADDR;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/SOCK_SEQPACK_Association.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_SOCK_SEQPACK_ASSOCIATION_H */

