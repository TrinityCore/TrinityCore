/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    SPIPE_Stream.h
 *
 *  $Id: SPIPE_Stream.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SPIPE_STREAM_H
#define ACE_SPIPE_STREAM_H
#include /**/ "ace/pre.h"

#include "ace/SPIPE.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SPIPE_Addr.h"
#include "ace/ACE.h"
#include "ace/OS_NS_stropts.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_SPIPE_Stream
 *
 * @brief Defines the methods in the ACE_SPIPE_Stream abstraction.
 *
 * @a buf is the buffer to write from or receive into.
 * @a len is the number of bytes to transfer.
 *
 * The "_n()" I/O methods keep looping until all the data has been
 * transferred.  These methods also work for sockets in non-blocking
 * mode i.e., they keep looping on EWOULDBLOCK.
 *
 * The return values for the "*_n()" methods match the return values
 * from the non "_n()" methods and are specified as follows:
 * - The number of bytes transferred is returned.
 * - On error, -1 is returned, errno is set to appropriate error.
 * - On EOF, 0 is returned, errno is irrelevant.
 *
 * Methods with <iovec> parameter are I/O vector variants of the I/O
 * operations.
 *
 * The <send> and <revc> operations use "message" semantics rather
 * than "bytestream" semantics.
 */
class ACE_Export ACE_SPIPE_Stream : public ACE_SPIPE
{
public:
  friend class ACE_SPIPE_Acceptor;
  friend class ACE_SPIPE_Connector;

  // = Initialization method.
  /// Default constructor.
  ACE_SPIPE_Stream (void);

  /// Obtain the address of whom we are connected with.
  int get_remote_addr (ACE_SPIPE_Addr &remote_sap) const;

  /// Send an open FD to another process.
  int send_handle (ACE_HANDLE handle) const;

  /// Recv an open FD from another process.
  int recv_handle (ACE_HANDLE &handle) const;

  /// Recv an open FD from another process.
  int recv_handle (strrecvfd &recvfd) const;

  /// Send @a len bytes, keep trying until @a len are sent.
  ssize_t send_n (const void *buf, size_t len) const;

  /// Recv @a len bytes, keep trying until @a len are received.
  ssize_t recv_n (void *buf, size_t len) const;

  /// Send bytes via STREAM pipes using "band" mode.
  ssize_t send (const void *buf, size_t len) const;

  /// Recv bytes via STREAM pipes using "band" mode.
  ssize_t recv (void *buf, size_t len) const;

  /// Send <cntl> and <data> via STREAM pipes.
  ssize_t send (const ACE_Str_Buf *cntl,
                const ACE_Str_Buf *data,
                int flags = 0) const;

  /// Recv <cntl> and <data> via STREAM pipes.
  ssize_t recv (ACE_Str_Buf *cntl,
                ACE_Str_Buf *data,
                int *flags) const;

  /// Send bytes via STREAM pipes using "band" mode.
  ssize_t send (const ACE_Str_Buf *cntl,
                const ACE_Str_Buf *data,
                int band,
                int flags) const;

  /// Recv bytes via STREAM pipes using "band" mode.
  ssize_t recv (ACE_Str_Buf *cntl,
                ACE_Str_Buf *data,
                int *band,
                int *flags) const;

  /// Send iovecs via the OS "gather-write" operation.
  ssize_t send (const iovec iov[], int len) const;

  /// Recv iovecs via the OS "scatter-read" operation.
  ssize_t recv (iovec iov[], int len) const;

  /**
   * Send N char *ptrs and int lengths.  Note that the char *'s
   * precede the ints (basically, an varargs version of writev).  The
   * count N is the *total* number of trailing arguments, *not* a
   * couple of the number of tuple pairs!
   */
  ssize_t send (size_t len, ...) const;

  /**
   * This is an interface to ::readv, that doesn't use the struct
   * iovec explicitly.  The ... can be passed as an arbitrary number
   * of (char *ptr, int len) tuples.  However, the count N is the
   * *total* number of trailing arguments, *not* a couple of the
   * number of tuple pairs!
   */
  ssize_t recv (size_t len, ...) const;

  /// Send @a len bytes via Win32 <WriteFile> using overlapped I/O.
  ssize_t send (const void *buf, size_t len, ACE_OVERLAPPED *overlapped) const;

  /// Recv @a len bytes via Win32 <ReadFile> using overlapped I/O.
  ssize_t recv (void *buf, size_t len, ACE_OVERLAPPED *overlapped) const;

  /// Send an <iovec> of size @a len to the stream.
  ssize_t sendv (const iovec iov[],
                 int len) const;

  /// Send an <iovec> of size @a len to the stream.  Will block until all
  /// bytes are sent or an error occurs.
  ssize_t sendv_n (const iovec iov[],
                   int len) const;

  /// Receive an <iovec> of size @a len to the stream.
  ssize_t recvv_n (iovec iov[],
                   int len) const;

  // = Meta-type info
  typedef ACE_SPIPE_Addr PEER_ADDR;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  ACE_SPIPE_Addr remote_addr_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/SPIPE_Stream.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SPIPE_STREAM_H */

