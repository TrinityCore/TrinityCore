/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    FIFO_Send_Msg.h
 *
 *  $Id: FIFO_Send_Msg.h 84480 2009-02-16 18:58:16Z johnnyw $
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_FIFO_SEND_MSG_H
#define ACE_FIFO_SEND_MSG_H
#include /**/ "ace/pre.h"

#include "ace/FIFO_Send.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_STREAM_PIPES)
#  include "ace/OS_NS_stropts.h"
#endif /* ACE_HAS_STREAM_PIPES */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward Decls
class ACE_Str_Buf;

/**
 * @class ACE_FIFO_Send_Msg
 *
 * @brief Sender side for the Record oriented C++ wrapper for UNIX
 * FIFOs.
 */
class ACE_Export ACE_FIFO_Send_Msg : public ACE_FIFO_Send
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_FIFO_Send_Msg (void);

  /// Open up a record-oriented named pipe for writing.
  ACE_FIFO_Send_Msg (const ACE_TCHAR *rendezvous,
                     int flags = O_WRONLY,
                     mode_t perms = ACE_DEFAULT_FILE_PERMS,
                     LPSECURITY_ATTRIBUTES sa = 0);

  /// Open up a record-oriented named pipe for writing.
  int open (const ACE_TCHAR *rendezvous,
            int flags = O_WRONLY,
            mode_t perms = ACE_DEFAULT_FILE_PERMS,
            LPSECURITY_ATTRIBUTES sa = 0);

  /// Send @a buf of up to @a len bytes.
  ssize_t send (const ACE_Str_Buf &msg);

  /// Send @a buf of exactly @a len bytes (block until done).
  ssize_t send (const void *buf, size_t len);

#if defined (ACE_HAS_STREAM_PIPES)
  /// Send @a data and @a cntl message via Stream pipes.
  ssize_t send (const ACE_Str_Buf *data,
                const ACE_Str_Buf *cntl = 0,
                int flags = 0);

  /// Send @a data and @a cntl message via Stream pipes in "band" mode.
  ssize_t send (int band,
                const ACE_Str_Buf *data,
                const ACE_Str_Buf *cntl = 0,
                int flags = MSG_BAND);
#endif /* ACE_HAS_STREAM_PIPES */

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/FIFO_Send_Msg.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_FIFO_SEND_MSG_H */
