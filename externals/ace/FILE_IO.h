/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    FILE_IO.h
 *
 *  $Id: FILE_IO.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_FILE_IO_H
#define ACE_FILE_IO_H
#include /**/ "ace/pre.h"

#include "ace/FILE.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/FILE_Addr.h"

// Used in the FILE_IO.h file...
#include "ace/os_include/os_stdio.h"
#include "ace/os_include/sys/os_uio.h"

#if defined (ACE_HAS_STREAM_PIPES)
#  include "ace/OS_NS_stropts.h"
#endif /* ACE_HAS_STREAM_PIPES */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decl.
class ACE_Message_Block;
class ACE_Time_Value;

/**
 * @class ACE_FILE_IO
 *
 * @brief Read/Write operations on Files
 */
class ACE_Export ACE_FILE_IO : public ACE_FILE
{
public:
  friend class ACE_FILE_Connector;

  // = Initialization method.
  /// Default constructor.
  ACE_FILE_IO (void);

  /// send upto @a n bytes in @a buf.
  ssize_t send (const void *buf, size_t n) const;

  /// Recv upto @a n bytes in @a buf.
  ssize_t recv (void *buf, size_t n) const;

  /// Send n bytes, keep trying until n are sent.
  ssize_t send_n (const void *buf, size_t n) const;

  /// Send all the @a message_blocks chained through their <next> and
  /// <cont> pointers.  This call uses the underlying OS gather-write
  /// operation to reduce the domain-crossing penalty.
  ssize_t send_n (const ACE_Message_Block *message_block,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0);

  /// Recv n bytes, keep trying until n are received.
  ssize_t recv_n (void *buf, size_t n) const;

#if defined (ACE_HAS_STREAM_PIPES)
  /// Send bytes via STREAM pipes.
  ssize_t send (const ACE_Str_Buf *cntl,
                const ACE_Str_Buf *data,
                int flags = 0) const;

  /// Recv bytes via STREAM pipes.
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

#endif /* ACE_HAS_STREAM_PIPES */

  /// Send iovecs via <::writev>.
  ssize_t send (const iovec iov[], int n) const;

  /// Recv iovecs via <::readv>.
  ssize_t recv (iovec iov[], int n) const;

  /**
   * Send N char *ptrs and int lengths.  Note that the char *'s
   * precede the ints (basically, an varargs version of writev).  The
   * count N is the *total* number of trailing arguments, *not* a
   * couple of the number of tuple pairs!
   */
  ssize_t send (size_t n, ...) const;

  /**
   * This is an interface to ::readv, that doesn't use the struct
   * iovec explicitly.  The ... can be passed as an arbitrary number
   * of (char *ptr, int len) tuples.  However, the count N is the
   * *total* number of trailing arguments, *not* a couple of the
   * number of tuple pairs!
   */
  ssize_t recv (size_t n, ...) const;

  /// Send @a n bytes via Win32 WriteFile using overlapped I/O.
  ssize_t send (const void *buf,
                size_t n,
                ACE_OVERLAPPED *overlapped) const;

  /// Recv @a n bytes via Win32 ReadFile using overlapped I/O.
  ssize_t recv (void *buf,
                size_t n,
                ACE_OVERLAPPED *overlapped) const;

  /// Send an @c iovec of size @a n to the file.
  ssize_t sendv (const iovec iov[],
                 int n) const;

  /**
   * Allows a client to read from a file without having to provide a
   * buffer to read.  This method determines how much data is in the
   * file, allocates a buffer of this size, reads in the data, and
   * returns the number of bytes read.  The caller is responsible for
   * deleting the member in the <iov_base> field of <io_vec> using
   * delete [] io_vec->iov_base.
   */
  ssize_t recvv (iovec *io_vec);

  /// Send an <iovec> of size @a n to the file.  Will block until all
  /// bytes are sent or an error occurs.
  ssize_t sendv_n (const iovec iov[],
                   int n) const;

  /// Receive an <iovec> of size @a n to the file.
  ssize_t recvv_n (iovec iov[],
                   int n) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  // = Meta-type info
  typedef ACE_FILE_Addr PEER_ADDR;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/FILE_IO.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_FILE_IO_H */
