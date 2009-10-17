// -*- C++ -*-
//==========================================================================
/**
 *  @file    SOCK_IO.h
 *
 *  $Id: SOCK_IO.h 81014 2008-03-19 11:41:31Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================
#ifndef ACE_SOCK_IO_H
#define ACE_SOCK_IO_H
#include /**/ "ace/pre.h"
#include "ace/SOCK.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/ACE.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_SOCK_IO
 *
 * @brief Defines the methods for the ACE socket wrapper I/O routines
 * (e.g., send/recv).
 *
 * If @a timeout == 0, then the call behaves as a normal
 * send/recv call, i.e., for blocking sockets, the call will
 * block until action is possible; for non-blocking sockets,
 * -1 will be returned with errno == EWOULDBLOCK if no action is
 * immediately possible.
 * If @a timeout != 0, the call will wait until the relative time
 * specified in *@a timeout elapses.
 * Errors are reported by -1 and 0 return values.  If the
 * operation times out, -1 is returned with @c errno == ETIME.
 * If it succeeds the number of bytes transferred is returned.
 * Methods with the extra @a flags argument will always result in
 * @c send getting called. Methods without the extra @a flags
 * argument will result in @c send getting called on Win32
 * platforms, and @c write getting called on non-Win32 platforms.
 */
class ACE_Export ACE_SOCK_IO : public ACE_SOCK
{
public:
  // = Initialization and termination methods.
  /// Constructor.
  ACE_SOCK_IO (void);
  /// Destructor.
  ~ACE_SOCK_IO (void);
  /// Recv an @a n byte buffer from the connected socket.
  ssize_t recv (void *buf,
                size_t n,
                int flags,
                const ACE_Time_Value *timeout = 0) const;
  /// Recv an @a n byte buffer from the connected socket.
  ssize_t recv (void *buf,
                size_t n,
                const ACE_Time_Value *timeout = 0) const;
  /// Recv an <iovec> of size @a n from the connected socket.
  ssize_t recvv (iovec iov[],
                 int n,
                 const ACE_Time_Value *timeout = 0) const;
  /**
   * Allows a client to read from a socket without having to provide a
   * buffer to read.  This method determines how much data is in the
   * socket, allocates a buffer of this size, reads in the data, and
   * returns the number of bytes read.  The caller is responsible for
   * deleting the member in the <iov_base> field of @a io_vec using
   * delete [] io_vec->iov_base.
   */
  ssize_t recvv (iovec *io_vec,
                 const ACE_Time_Value *timeout = 0) const;
  /// Recv @a n varargs messages to the connected socket.
  ssize_t recv (size_t n,
                ...) const;
  /// Recv @a n bytes via Win32 @c ReadFile using overlapped I/O.
  ssize_t recv (void *buf,
                size_t n,
                ACE_OVERLAPPED *overlapped) const;
  /// Send an @a n byte buffer to the connected socket.
  ssize_t send (const void *buf,
                size_t n,
                int flags,
                const ACE_Time_Value *timeout = 0) const;
  /// Send an @a n byte buffer to the connected socket.
  ssize_t send (const void *buf,
                size_t n,
                const ACE_Time_Value *timeout = 0) const;
  /// Send an @c iovec of size @a n to the connected socket.
  ssize_t sendv (const iovec iov[],
                 int n,
                 const ACE_Time_Value *timeout = 0) const;
  /// Send @a n varargs messages to the connected socket.
  ssize_t send (size_t n,
                ...) const;
  /// Send @a n bytes via Win32 <WriteFile> using overlapped I/O.
  ssize_t send (const void *buf,
                size_t n,
                ACE_OVERLAPPED *overlapped) const;
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/SOCK_IO.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_SOCK_IO_H */

