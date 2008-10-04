// -*- C++ -*-

//=============================================================================
/**
 *  @file    FIFO_Recv_Msg.h
 *
 *  $Id: FIFO_Recv_Msg.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_FIFO_RECV_MSG_H
#define ACE_FIFO_RECV_MSG_H
#include /**/ "ace/pre.h"

#include "ace/FIFO_Recv.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decls
class ACE_Str_Buf;

/**
 * @class ACE_FIFO_Recv_Msg
 *
 * @brief Receiver side for the record oriented C++ wrapper for UNIX FIFOs.
 *
 * This method works slightly differently on platforms with the
 * @c ACE_HAS_STREAM_PIPES configuration setting than those without.
 * With ACE_HAS_STREAM_PIPES, the @c getmsg() system function is used
 * and it preserves message boundaries internally. Without
 * @c ACE_HAS_STREAM_PIPES, the message boundaries are emulated by
 * this class and ACE_FIFO_Send_Msg cooperating. The sending class
 * first writes an integer number of bytes in the message, then the
 * message. ACE_FIFO_Recv_Msg reads the count, then the data.
 * The operational differences occur primarily when a message is larger
 * than what a caller of this class requests. See recv() for details.
 */
class ACE_Export ACE_FIFO_Recv_Msg : public ACE_FIFO_Recv
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_FIFO_Recv_Msg (void);

  /// Open up a record-oriented named pipe for reading.
  ACE_FIFO_Recv_Msg (const ACE_TCHAR *rendezvous,
                     int flags = O_CREAT | O_RDONLY,
                     mode_t perms = ACE_DEFAULT_FILE_PERMS,
                     int persistent = 1,
                     LPSECURITY_ATTRIBUTES sa = 0);

  /// Open up a record-oriented named pipe for reading.
  int open (const ACE_TCHAR *rendezvous,
            int flags = O_CREAT | O_RDONLY,
            mode_t perms = ACE_DEFAULT_FILE_PERMS,
            int persistent = 1,
            LPSECURITY_ATTRIBUTES sa = 0);

  /// Receive a message based on attributes in an ACE_Str_Buf.
  /**
   * @param msg  Reference to an ACE_Str_Buf whose @c buf member points
   *             to the memory to receive the data and @c maxlen member
   *             contains the maximum number of bytes to receive.
   *             On return after successfully reading data, the
   *             @c len member contains the number of bytes received and
   *             placed in the buffer pointed to by @c msg.buf.
   *
   * @retval -1  Error; consult @c errno for specific error number.
   * @return     If the @c ACE_HAS_STREAM_PIPES configuration setting is
   *             defined, the return value is the number of bytes received
   *             in the message and will be the same as @c buf.len.
   *             The return value from the @c getmsg() system function
   *             is discarded.
   *             If @c ACE_HAS_STREAM_PIPES is not defined, the number
   *             of bytes in the message read from the FIFO is returned.
   *             If the message is larger than the maximum length
   *             requested in @c msg.maxlen, the return value reflects
   *             the entire message length, and the @c msg.len member
   *             reflects how many bytes were actually placed in the
   *             caller's buffer. Any part of the message longer than
   *             @c msg.maxlen is discarded.
   */
  ssize_t recv (ACE_Str_Buf &msg);

  /// Receive a message based on buffer pointer and maximum size.
  /**
   * @param buf  Pointer to the memory to receive the data.
   * @param len  The maximum number of bytes to receive.
   *
   * @retval -1  Error; consult @c errno for specific error number.
   * @return     The number of bytes received in the message. For messages
   *             that are larger than the requested maximum size, the
   *             behavior is different depending on the @c ACE_HAS_STREAM_PIPES
   *             configuration setting. With @c ACE_HAS_STREAM_PIPES,
   *             the return value will be the same as @arg len (this is
   *             also possible if the message is exactly the same length
   *             as @arg len, and the two cases are indistinguishable).
   *             Without @c ACE_HAS_STREAM_PIPES, the return value is
   *             the total length of the message, including bytes in
   *             excess of @arg len. The excess bytes are discarded.
   */
  ssize_t recv (void *buf, size_t len);

#if defined (ACE_HAS_STREAM_PIPES)
  /// Recv <data> and <cntl> message via Stream pipes.
  ssize_t recv (ACE_Str_Buf *data,
                ACE_Str_Buf *cntl,
                int *flags);

  /// Recv <data> and <cntl> message via Stream pipes in "band" mode.
  ssize_t recv (int *band,
                ACE_Str_Buf *data,
                ACE_Str_Buf *cntl,
                int *flags);
#endif /* ACE_HAS_STREAM_PIPES */

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/FIFO_Recv_Msg.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_FIFO_RECV_MSG_H */
