// -*- C++ -*-

//==========================================================================
/**
 *  @file    FIFO_Recv.h
 *
 *  $Id: FIFO_Recv.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//==========================================================================


#ifndef ACE_FIFO_RECV_H
#define ACE_FIFO_RECV_H

#include /**/ "ace/pre.h"

#include "ace/FIFO.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_fcntl.h"
#include "ace/Default_Constants.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_FIFO_Recv
 *
 * @brief Receiver side of the bytestream C++ wrapper for UNIX
 * FIFOs.
 */
class ACE_Export ACE_FIFO_Recv : public ACE_FIFO
{
public:
  // = Initialization methods.
  /// Default constructor.
  ACE_FIFO_Recv (void);

  /// Open up a bytestream named pipe for reading.
  ACE_FIFO_Recv (const ACE_TCHAR *rendezvous,
                 int flags = O_CREAT | O_RDONLY,
                 mode_t perms = ACE_DEFAULT_FILE_PERMS,
                 int persistent = 1,
                 LPSECURITY_ATTRIBUTES sa = 0);

  /// Open up a bytestream named pipe for reading.
  int open (const ACE_TCHAR *rendezvous,
            int flags = O_CREAT | O_RDONLY,
            mode_t perms = ACE_DEFAULT_FILE_PERMS,
            int persistent = 1,
            LPSECURITY_ATTRIBUTES sa = 0);

  /// Close down the named pipe.
  int close (void);

  /// Recv @a buf of up to @a len bytes.
  ssize_t recv (void *buf, size_t len);

  /// Recv @a buf of exactly @a len bytes (block until done).
  ssize_t recv_n (void *buf, size_t len);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Auxiliary handle that is used to implement persistent FIFOs.
  ACE_HANDLE aux_handle_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/FIFO_Recv.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_FIFO_RECV_H */
