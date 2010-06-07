// -*- C++ -*-

//=============================================================================
/**
 *  @file    SSL_SOCK_Stream.h
 *
 *  $Id: SSL_SOCK_Stream.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Ossama Othman <ossama@uci.edu>
 *  @author Carlos O'Ryan <coryan@uci.edu>
 *  @author John Heitmann
 */
//=============================================================================


#ifndef ACE_SSL_SOCK_STREAM_H
#define ACE_SSL_SOCK_STREAM_H

#include /**/ "ace/pre.h"

#include "SSL_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// This must be included before any <openssl> include on LynxOS
#include "ace/os_include/os_stdio.h"

#include <openssl/err.h>

#include "SSL_SOCK.h"
#include "SSL_Context.h"

#include "ace/SOCK_Stream.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_SSL_SOCK_Stream
 *
 * @brief Defines methods in the ACE_SSL_SOCK_Stream abstraction.
 *
 * This class encapsulates the methods and functionality necessary to
 * send and receive data over TLS/SSL.
 * @par
 * Since SSL is record-oriented, some additional steps must be taken
 * to make the ACE_SSL_SOCK_Stream interact properly with the
 * Reactor (if one is used) when performing non-blocking IO.  In
 * particular, if ::SSL_pending (ssl), where "ssl" is a pointer to the
 * SSL data structure returned from ACE_SSL_SOCK_Stream::ssl(),
 * returns a non-zero value then the event handler that calls the IO
 * methods in this class should return a value greater than zero to
 * force the Reactor to invoke the event handler before polling for
 * additional events (e.g. blocking on select()).
 *
 * @note The user must currently ensure that only one thread services
 *       a given SSL session at any given time since underlying SSL
 *       implementations, such as OpenSSL, are not entirely
 *       thread-safe or reentrant.
 */
class ACE_SSL_Export ACE_SSL_SOCK_Stream : public ACE_SSL_SOCK
{
public:

  /// Constructor
  /**
   * @param context Pointer to @c ACE_SSL_Context instance containing
   *                the OpenSSL @c SSL data structure to be associated
   *                with this @c ACE_SSL_SOCK_Stream.  The @c SSL data
   *                structure will be copied to make it at least
   *                logically independent of the supplied @a context.
   */
  ACE_SSL_SOCK_Stream (ACE_SSL_Context *context =
                       ACE_SSL_Context::instance ());

  /// Destructor
  ~ACE_SSL_SOCK_Stream (void);

  /// Send an n byte buffer to the ssl socket using the semantics of
  /// send(3n).
  /**
   * ACE_SSL supports no flags for sending at this time.
   */
  ssize_t send (const void *buf,
                size_t n,
                int flags) const;

  /// Recv an n byte buffer from the ssl socket using the semantics of
  /// recv(3n).
  /**
   * ACE_SSL supports MSG_PEEK, but no other flags at this time.
   */
  ssize_t recv (void *buf,
                size_t n,
                int flags) const;

  /// Send an n byte buffer to the ssl socket using the semantics of
  /// write(2).
  ssize_t send (const void *buf,
                size_t n) const;

  /// Recv an n byte buffer from the ssl socket using the semantics of
  /// read(2).
  ssize_t recv (void *buf,
                size_t n) const;

  /// Send an iovec of size n to the ssl socket.
  /**
   * Note that it is not possible to perform a "scattered" write with
   * the underlying OpenSSL implementation.  As such, the expected
   * semantics are not fully reproduced with this implementation.
   */
  ssize_t sendv (const iovec iov[],
                 size_t n,
                 const ACE_Time_Value *timeout = 0) const;

  /**
   * Allows a client to read from a socket without having to provide a
   * buffer to read.  This method determines how much data is in the
   * socket, allocates a buffer of this size, reads in the data, and
   * returns the number of bytes read.  The caller is responsible for
   * deleting the member in the iov_base field of io_vec using
   * delete [] io_vec->iov_base.
   */
  ssize_t recvv (iovec *io_vec,
                 const ACE_Time_Value *timeout = 0) const;

  /**
   * Wait to timeout amount of time to send up to n bytes into buf
   * (uses the send() call).  If send() times out -1 is returned with
   * errno == ETIME.  If it succeeds the number of bytes sent is
   * returned. No flags are supported.
   */
  ssize_t send (const void *buf,
                size_t n,
                int flags,
                const ACE_Time_Value *timeout) const;

  /**
   * Wait up to timeout amount of time to receive up to n bytes into
   * buf (uses the recv() call).  If recv() times out -1 is returned
   * with errno == ETIME.  If it succeeds the number of bytes received
   * is returned.  MSG_PEEK is the only supported flag.
   */
  ssize_t recv (void *buf,
                size_t n,
                int flags,
                const ACE_Time_Value *timeout) const;

  /**
   * Wait to to timeout amount of time to send up to n bytes into
   * buf (uses the send() call).  If send() times out
   * a -1 is returned with errno == ETIME.  If it succeeds the
   * number of bytes sent is returned.
   */
  ssize_t send (const void *buf,
                size_t n,
                const ACE_Time_Value *timeout) const;

  /**
   * Wait up to timeout amount of time to receive up to n bytes
   * into buf (uses the recv() call).  If recv() times
   * out a -1 is returned with @c errno == ETIME.  If it succeeds the
   * number of bytes received is returned.
   */
  ssize_t recv (void *buf,
                size_t n,
                const ACE_Time_Value *timeout) const;

  /// Send n varargs messages to the connected ssl socket.
  ssize_t send (size_t n,
                ...) const;

  /// Recv n varargs messages to the connected ssl socket.
  ssize_t recv (size_t n,
                ...) const;

  /// Send n bytes, keep trying until n are sent.
  ssize_t send_n (const void *buf, int n) const;

  /// Recv n bytes, keep trying until n are received.
  ssize_t recv_n (void *buf, int n) const;

  /**
   * @note In the following four methods, only MSG_PEEK is supported
   * for recv_n(), and no flags are supported for send_n().
   */
  //@{
  /// Send n bytes, keep trying until n are sent.
  ssize_t send_n (const void *buf, int n, int flags) const;

  /// Recv n bytes, keep trying until n are sent.
  ssize_t recv_n (void *buf, int n, int flags) const;

  /**
   * Try to send exactly len bytes into buf (uses the send() call).
   * If send() blocks for longer than timeout the number of bytes
   * actually sent is returned with errno == ETIME.  If a timeout does
   * not occur, send_n() return len (i.e., the number of bytes
   * requested to be sent).
   */
  ssize_t send_n (const void *buf,
                  size_t len,
                  int flags,
                  const ACE_Time_Value *timeout,
                  size_t *bytes_transferred = 0) const;

  /**
   * Try to receive exactly len bytes into buf (uses the recv() call).
   * The ACE_Time_Value indicates how long to blocking trying to
   * receive.  If timeout == 0, the caller will block until action is
   * possible, else will wait until the relative time specified in
   * timeout elapses).  If recv() blocks for longer than timeout the
   * number of bytes actually read is returned with errno == ETIME.
   * If a timeout does not occur, recv_n return len (i.e., the number
   * of bytes requested to be read).
   */
  ssize_t recv_n (void *buf,
                  size_t len,
                  int flags,
                  const ACE_Time_Value *timeout,
                  size_t *bytes_transferred = 0) const;
  //@}

  /**
   * Send an iovec of size n to the connected socket.  Will block
   * until all bytes are sent or an error occurs.
   */
  ssize_t sendv_n (const iovec iov[],
                   size_t n) const;

  /// Receive an iovec of size n to the connected socket.
  ssize_t recvv_n (iovec iov[],
                   size_t n) const;


  /**
   * Selectively close endpoints.
   */
  //@{
  /// Close down the reader.
  int close_reader (void);

  /// Close down the writer.
  int close_writer (void);
  //@}

  ///Close down the socket.
  int close (void);

  /// Meta-type info
  typedef ACE_INET_Addr PEER_ADDR;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  /// Overridden set_handle() method.
  /**
   * Only an ACE_SSL_SOCK_Acceptor or ACE_SSL_SOCK_Connector should
   * access this method since some state in the underlying "ssl_" data
   * structure is set during SSL connection establishment.
   */
  void set_handle (ACE_HANDLE fd);

  /// Return a pointer to the underlying SSL structure.
  SSL *ssl (void) const;

  /**
   * Return the address of the remotely connected peer (if there is
   * one), in the referenced <ACE_Addr>. Returns 0 if successful, else
   * -1.
   *
   * @note If the TCP connection has been completed but the SSL
   *       connection has not been completed yet, -1 will be
   *       returned.
   */
  int get_remote_addr (ACE_Addr &) const;

  /// Return the underlying ACE_SOCK_Stream which ACE_SSL runs atop of.
  ACE_SOCK_Stream & peer (void);

protected:

  /// Underlying send() helper method common to all public send()
  /// methods.
  ssize_t send_i (const void *buf,
                  size_t n,
                  int flags) const;

  /// Underlying send() helper method common to all public send()
  /// methods.
  ssize_t recv_i (void *buf,
                  size_t n,
                  int flags,
                  const ACE_Time_Value *timeout) const;

private:

  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_SSL_SOCK_Stream &))
  ACE_UNIMPLEMENTED_FUNC (ACE_SSL_SOCK_Stream (const ACE_SSL_SOCK_Stream &))

protected:

  /// The SSL session.
  SSL *ssl_;

  /// The stream which works under the ssl connection.
  ACE_SOCK_Stream stream_;

};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "SSL_SOCK_Stream.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_SSL_SOCK_STREAM_H */
