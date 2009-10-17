// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_uio.h
 *
 *  definitions for vector I/O operations
 *
 *  $Id: os_uio.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_SYS_OS_UIO_H
#define ACE_OS_INCLUDE_SYS_OS_UIO_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_types.h"
#include "ace/os_include/os_limits.h"

#if !defined (ACE_LACKS_SYS_UIO_H)
#  include /**/ <sys/uio.h>
#endif /* !ACE_LACKS_SYS_UIO_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if defined (ACE_LACKS_IOVEC)
   /// The ordering of the fields in this struct is important.  It has to
   /// match those in WSABUF.
   struct iovec
   {
     /// byte count to read/write
     u_long iov_len;
     /// data to be read/written
     char *iov_base;

     // WSABUF is a Winsock2-only type.
#  if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
     operator WSABUF &(void) { return *((WSABUF *) this); }
#  endif /* defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) */
   };
#endif /* ACE_LACKS_IOVEC */


# if defined (ACE_LACKS_TIMEDWAIT_PROTOTYPES)

  ssize_t readv_timedwait (ACE_HANDLE handle,
                           const iovec *iov,
                           int iovcnt,
                           struct timespec* timeout);

  ssize_t writev_timedwait (ACE_HANDLE handle,
                            const iovec *iov,
                            int iovcnt,
                            struct timespec *timeout);

# endif /* ACE_LACKS_TIMEDWAIT_PROTOTYPES */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_SYS_OS_UIO_H */

