// -*- C++ -*-
//==========================================================================
/**
 *  @file    Pipe.h
 *
 *  $Id: Pipe.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================
#ifndef ACE_PIPE_H
#define ACE_PIPE_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Default_Constants.h"
#include "ace/OS_NS_sys_uio.h"
#include "ace/OS_NS_unistd.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Forward decl.
class ACE_Message_Block;
class ACE_Time_Value;
/**
 * @class ACE_Pipe
 *
 * @brief Provides a portable bidirectional "pipe" abstraction.
 *
 * This class is designed to work with select()-based demuxers, such
 * as the ACE_Select_Reactor, which is why it uses sockets on Windows
 * rather than Win32 pipes (which aren't select()'able).
 */
class ACE_Export ACE_Pipe
{
public:
  // = Initialization and termination.
  /// Default constructor (does nothing...).
  ACE_Pipe (void);
  /// Open the pipe and initialize the handles.
  ACE_Pipe (ACE_HANDLE handles[2]);
  /// Initialize the ACE_Pipe from the @a read and @a write handles.
  ACE_Pipe (ACE_HANDLE read, ACE_HANDLE write);
  /// Default dtor.  It doesn't close the handles for you.
  ~ACE_Pipe (void);
  /// Open the pipe and initialize the handles.
  int open (ACE_HANDLE handles[2]);
  /// Open the pipe, setting the buffer size to the maximum.
  int open (int buffer_size = ACE_DEFAULT_MAX_SOCKET_BUFSIZ);
  /// Close down the pipe HANDLEs;
  int close (void);
  // = Accessors.
  /**
   * This is the "read" side of the pipe.  Note, however, that
   * processes can also write to this handle as well since pipes are
   * bi-directional.
   */
  ACE_HANDLE read_handle (void) const;
  /**
   * This is the "write" side of the pipe.  Note, however, that
   * processes can also read to this handle as well since pipes are
   * bi-directional.
   */
  ACE_HANDLE write_handle (void) const;
  /// Dump the state of the object.
  void dump (void) const;
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
  /// Send an <iovec> of size @a n to the file.
  ssize_t sendv (const iovec iov[],
                 int n) const;
  /// Send an @c iovec of size @a n to the file.  Will block until all
  /// bytes are sent or an error occurs.
  ssize_t sendv_n (const iovec iov[],
                   int n) const;
  /// Receive an @c iovec of size @a n to the file.
  ssize_t recvv_n (iovec iov[],
                   int n) const;
private:
  ACE_HANDLE handles_[2];
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Pipe.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_PIPE_H */

