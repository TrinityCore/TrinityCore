// -*- C++ -*-

//=============================================================================
/**
 *  @file    SOCK_Stream.h
 *
 *  $Id: SOCK_Stream.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SOCK_STREAM_H
#define ACE_SOCK_STREAM_H
#include /**/ "ace/pre.h"

#include "ace/SOCK_IO.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/INET_Addr.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declarations.
class ACE_Message_Block;

/**
 * @class ACE_SOCK_Stream
 *
 * @brief Defines the methods in the ACE_SOCK_Stream abstraction.
 *
 * This adds additional wrapper methods atop the ACE_SOCK_IO
 * class.
 *
 * @sa ACE_SOCK_IO
 */
class ACE_Export ACE_SOCK_Stream : public ACE_SOCK_IO
{
public:
  // Initialization and termination methods.
  /// Constructor.
  ACE_SOCK_Stream (void);

  /// Constructor (sets the underlying ACE_HANDLE with @a h).
  ACE_SOCK_Stream (ACE_HANDLE h);

  /// Destructor.
  ~ACE_SOCK_Stream (void);

  /** @name Counted send/receive methods
   *
   * The counted send/receive methods attempt to transfer a specified number
   * of bytes even if they must block and retry the operation in order to
   * transfer the entire amount. The time spent blocking for the entire
   * transfer can be limited by a specified ACE_Time_Value object which is
   * a relative time (i.e., a fixed amount of time, not an absolute time
   * of day). These methods return the count of transferred bytes, or -1
   * if an error occurs or the operation times out before the entire requested
   * amount of data has been transferred. In error or timeout situations it's
   * possible that some data was transferred before the error
   * or timeout. The @c bytes_transferred parameter is used to obtain the
   * count of bytes transferred before the error or timeout occurred. If the
   * total specified number of bytes is transferred without error, the
   * method return value should equal the value of @c bytes_transferred.
   *
   * @param buf      The buffer to write from or receive into.
   * @param iov      An I/O vector containing a specified number of
   *                 count/pointer pairs directing the data to be transferred.
   * @param iovcnt   The number of I/O vectors to be used from @a iov.
   * @param len      The number of bytes to transfer.
   * @param flags    Flags that will be passed through to the @c recv()
   *                 system call.
   * @param timeout  Indicates how long to blocking trying to transfer data.
   *                 If no timeout is supplied (timeout == 0) the method will
   *                 wait indefinitely or until an error occurs for the
   *                 specified number of bytes to be transferred.
   *                 To avoid any waiting, specify a timeout value with
   *                 0 seconds.
   * @param bytes_transferred If non-0, points to a location which receives
   *                 the total number of bytes transferred before the method
   *                 returns, even if it's less than the number requested.
   *
   * @retval      len, the complete number of bytes transferred.
   * @retval      0  EOF, i.e., the peer closed the connection.
   * @retval      -1 an error occurred before the entire amount was
   *                 transferred. Check @c errno for more information.
   *                 If the @a timeout period is reached, errno is ETIME.
   *
   * On partial transfers, i.e., if any data is transferred before
   * timeout/error/EOF, *@a bytes_transferred will contain the number of
   * bytes transferred.
   */
  //@{
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

  /// Receive an @c iovec of size @a iovcnt from the connected socket.
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

  /// Send all the message blocks chained through their @c next and
  /// @c cont pointers.  This call uses the underlying OS gather-write
  /// operation to reduce the domain-crossing penalty.
  ssize_t send_n (const ACE_Message_Block *message_block,
                  const ACE_Time_Value *timeout = 0,
                  size_t *bytes_transferred = 0) const;

  /// Send an @c iovec of size @a iovcnt to the connected socket.
  ssize_t sendv_n (const iovec iov[],
                   int iovcnt,
                   const ACE_Time_Value *timeout = 0,
                   size_t *bytes_transferred = 0) const;

  //@}

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
   * on Win32, which requires use to do a close_writer() before doing
   * the close to avoid losing data).
   */
  int close (void);

  // = Meta-type info
  typedef ACE_INET_Addr PEER_ADDR;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/SOCK_Stream.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SOCK_STREAM_H */
