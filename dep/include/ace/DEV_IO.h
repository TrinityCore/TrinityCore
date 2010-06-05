/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    DEV_IO.h
 *
 *  $Id: DEV_IO.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Gerhard Lenzer
 *  @author Douglas C. Schmidt
 */
//=============================================================================

#ifndef ACE_DEV_IO_H
#define ACE_DEV_IO_H
#include /**/ "ace/pre.h"

#include "ace/DEV.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_STREAM_PIPES)
#  include "ace/OS_NS_stropts.h"
#endif /* ACE_HAS_STREAM_PIPES */

#include "ace/os_include/os_stdio.h"
#include "ace/os_include/sys/os_uio.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;

/**
 * @class ACE_DEV_IO
 *
 * @brief Read/Write operations on Devices.
 */
class ACE_Export ACE_DEV_IO : public ACE_DEV
{
public:
  friend class ACE_DEV_Connector;

  /// Default constructor.
  ACE_DEV_IO (void);

  // = Various send operations.
  /// send upto @a n bytes in @a buf.
  ssize_t send (const void *buf, size_t n) const;

  /// Recv upto @a n bytes in @a buf.
  ssize_t recv (void *buf, size_t n) const;

  /// Send n bytes, keep trying until n are sent.
  ssize_t send_n (const void *buf,
                  size_t n) const;

  /**
   * @name I/O operations
   *
   * Notes on common parameters:
   *
   * @a buf is the buffer to write from or receive into.
   *
   * @a len is the number of bytes to transfer.
   *
   * The @a timeout parameter in the following methods indicates how
   * long to blocking trying to transfer data.  If @a timeout == 0,
   * then the call behaves as a normal send/recv call, i.e., for
   * blocking sockets, the call will block until action is possible;
   * for non-blocking sockets, EWOULDBLOCK will be returned if no
   * action is immediately possible.
   *
   * If @a timeout != 0, the call will wait until the relative time
   * specified in *@a timeout elapses.
   *
   * The "_n()" I/O methods keep looping until all the data has been
   * transferred.  These methods also work for sockets in non-blocking
   * mode i.e., they keep looping on EWOULDBLOCK.  @a timeout is used
   * to make sure we keep making progress, i.e., the same timeout
   * value is used for every I/O operation in the loop and the timeout
   * is not counted down.
   *
   * The return values for the "*_n()" methods match the return values
   * from the non "_n()" methods and are specified as follows:
   *
   * - On complete transfer, the number of bytes transferred is returned.
   * - On timeout, -1 is returned, errno == ETIME.
   * - On error, -1 is returned, errno is set to appropriate error.
   * - On EOF, 0 is returned, errno is irrelevant.
   *
   * On partial transfers, i.e., if any data is transferred before
   * timeout/error/EOF, @a bytes_transferred will contain the number of
   * bytes transferred.
   */
  ssize_t recv_n (void *buf,
                  size_t n,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0) const;

#if defined (ACE_HAS_STREAM_PIPES)
  /// Recv bytes via STREAM pipes using "band" mode.
  ssize_t recv (ACE_Str_Buf *cntl,
                ACE_Str_Buf *data,
                int *band,
                int *flags) const;

  /// Send bytes via STREAM pipes using "band" mode.
  ssize_t send (const ACE_Str_Buf *cntl,
                const ACE_Str_Buf *data,
                int band,
                int flags) const;

  /// Recv @a cntl and @a data via STREAM pipes.
  ssize_t recv (ACE_Str_Buf *cntl,
                ACE_Str_Buf *data,
                int *flags) const;

  /// Send @a cntl and @a data via STREAM pipes.
  ssize_t send (const ACE_Str_Buf *cntl,
                const ACE_Str_Buf *data,
                int flags = 0) const;
#endif /* ACE_HAS_STREAM_PIPES */

  /// Send iovecs via <::writev>.
  ssize_t send (const iovec iov[], size_t n) const;

  /// Recv iovecs via <::readv>.
  ssize_t recv (iovec iov[], size_t n) const;

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
  ssize_t send (const void *buf, size_t n, ACE_OVERLAPPED *overlapped) const;

  /// Recv @a n bytes via Win32 ReadFile using overlapped I/O.
  ssize_t recv (void *buf, size_t n, ACE_OVERLAPPED *overlapped) const;

  /// Dump the state of an object.
  void dump (void) const;

  // = The following two methods are no-ops to keep the
  // ACE_Connector happy.
  /// Return the local endpoint address.
  int get_local_addr (ACE_DEV_Addr &) const;

  /// Return the address of the remotely connected peer (if there is
  /// one).
  int get_remote_addr (ACE_DEV_Addr &) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  // = Meta-type info
  typedef ACE_DEV_Addr PEER_ADDR;

private:
  /// Address of device we are connected to.
  ACE_DEV_Addr addr_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/DEV_IO.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_DEV_IO_H */

