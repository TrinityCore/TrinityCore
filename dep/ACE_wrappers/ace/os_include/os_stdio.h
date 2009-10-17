// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_stdio.h
 *
 *  standard buffered input/output
 *
 *  $Id: os_stdio.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_STDIO_H
#define ACE_OS_INCLUDE_OS_STDIO_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// NOTE: stdarg.h must be #included before stdio.h on LynxOS.
#include "ace/os_include/os_stdarg.h"
#include "ace/os_include/os_stddef.h"

#if !defined (ACE_LACKS_STDIO_H)
#  include /**/ <stdio.h>
#endif /* !ACE_LACKS_STDIO_H */

#if defined (ACE_VXWORKS)
// for remove(), rename()
#  include /**/ <ioLib.h>
// for remCurIdGet()
#  include /**/ <remLib.h>
#  if defined (__RTP__) && ((ACE_VXWORKS >= 0x620) && (ACE_VXWORKS <= 0x650))
#    define L_cuserid       _PARM_L_cuserid
#  endif
#endif /* ACE_VXWORKS */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

# if defined (INTEGRITY)
#   define ACE_MAX_USERID 32
# elif defined (ACE_WIN32)
#   define ACE_MAX_USERID 32
# else
#  if defined (_POSIX_SOURCE) && defined (L_cuserid)
#   define ACE_MAX_USERID L_cuserid
#  else
#   define ACE_MAX_USERID 9
#  endif
# endif /* INTEGRITY */

#if defined (BUFSIZ)
#  define ACE_STREAMBUF_SIZE BUFSIZ
#else
#  define ACE_STREAMBUF_SIZE 1024
#endif /* BUFSIZ */

#if defined (ACE_WIN32)
  typedef OVERLAPPED ACE_OVERLAPPED;
#else
  struct ACE_OVERLAPPED
  {
    unsigned long Internal;
    unsigned long InternalHigh;
    unsigned long Offset;
    unsigned long OffsetHigh;
    ACE_HANDLE hEvent;
  };
#endif /* ACE_WIN32 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_STDIO_H */

