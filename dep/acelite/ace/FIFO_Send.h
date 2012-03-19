// -*- C++ -*-

//==========================================================================
/**
 *  @file    FIFO_Send.h
 *
 *  $Id: FIFO_Send.h 91574 2010-08-30 16:52:24Z shuston $
 *
 *  @author Doug Schmidt
 */
//==========================================================================


#ifndef ACE_FIFO_SEND_H
#define ACE_FIFO_SEND_H

#include /**/ "ace/pre.h"

#include "ace/FIFO.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_fcntl.h"
#include "ace/Default_Constants.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_FIFO_Send
 *
 * @brief Sender side for the bytestream C++ wrapper for UNIX FIFOs
 */
class ACE_Export ACE_FIFO_Send : public ACE_FIFO
{
public:
  /// @name Initialization methods.
  ///
  /// Note that @c O_WRONLY will be added to any @a flags value passed.
  /// Default behavior is to block until a receiver also opens the fifo.
  /// To use non-blocking behavior include ACE_NONBLOCK in @a flags.
  //@{
  /// Default constructor.
  ACE_FIFO_Send (void);

  /// Open up a bytestream named pipe for writing.
  ACE_FIFO_Send (const ACE_TCHAR *rendezvous,
                 int flags = O_WRONLY,
                 mode_t perms = ACE_DEFAULT_FILE_PERMS,
                 LPSECURITY_ATTRIBUTES sa = 0);

  /// Open up a bytestream named pipe for writing.
  int open (const ACE_TCHAR *rendezvous,
            int flags = O_WRONLY,
            mode_t perms = ACE_DEFAULT_FILE_PERMS,
            LPSECURITY_ATTRIBUTES sa = 0);
  //@}

  /// Send @a buf of up to @a len bytes.
  ssize_t send (const void *buf, size_t len);

  /// Send @a buf of exactly @a len bytes (block until done).
  ssize_t send_n (const void *buf, size_t len);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/FIFO_Send.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_FIFO_SEND_H */
