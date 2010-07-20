// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_stropts.h
 *
 *  STREAMS interface (STREAMS)
 *
 *  $Id: os_stropts.h 84660 2009-03-01 20:22:37Z olli $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_STROPTS_H
#define ACE_OS_INCLUDE_OS_STROPTS_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_unistd.h"

#if defined (ACE_HAS_TIMOD_H)
#  include /**/ <sys/timod.h>
#elif defined (ACE_HAS_OSF_TIMOD_H)
#  include /**/ <tli/timod.h>
#endif /* ACE_HAS_TIMOD_H */

#if !defined (ACE_LACKS_SYS_IOCTL_H)
#  include /**/ <sys/ioctl.h>
#endif /* !ACE_LACKS_IOCTL_H */

#if defined (ACE_HAS_SYS_FILIO_H)
#  include /**/ <sys/filio.h>
#endif /* ACE_HAS_SYS_FILIO_H */

#if defined (ACE_HAS_SYS_SOCKIO_H)
#  include /**/ <sys/sockio.h>
#endif /* ACE_HAS_SOCKIO_H */

// This is sorta counter intuitive, but this is how it was done in OS.h
// @todo: fix this...  dhinton
#if defined (ACE_HAS_STREAMS)
#  if defined (AIX)
#    if !defined (_XOPEN_EXTENDED_SOURCE)
#      define _XOPEN_EXTENDED_SOURCE
#    endif /* !_XOPEN_EXTENDED_SOURCE */
#  endif /* AIX */
#endif /* ACE_HAS_STREAMS */

#if !defined (ACE_LACKS_STROPTS_H)
#  include /**/ <stropts.h>
#endif /* !ACE_LACKS_STROPTS_H */

// This is sorta counter intuitive, but this is how it was done in OS.h
// @todo: fix this...  dhinton
#if defined (ACE_HAS_STREAMS)
#  if defined (AIX)
#    undef _XOPEN_EXTENDED_SOURCE
#  endif /* AIX */
#endif /* ACE_HAS_STREAMS */

#if defined (ACE_VXWORKS)
// for ioctl()
#  include /**/ <ioLib.h>
#endif /* ACE_VXWORKS */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if defined (ACE_LACKS_STRRECVFD)
   struct strrecvfd {};
#endif /* ACE_LACKS_STRRECVFD */

# if !defined (SIOCGIFBRDADDR)
#   define SIOCGIFBRDADDR 0
# endif /* SIOCGIFBRDADDR */

# if !defined (SIOCGIFADDR)
#   define SIOCGIFADDR 0
# endif /* SIOCGIFADDR */

# if !defined (ACE_HAS_STRBUF_T)
struct strbuf
{
  /// No. of bytes in buffer.
  int maxlen;
  /// No. of bytes returned.
  int len;
  /// Pointer to data.
  void *buf;
};
# endif /* ACE_HAS_STRBUF_T */

// These prototypes are chronically lacking from many versions of UNIX.
#if !defined (ACE_WIN32) && !defined (ACE_HAS_ISASTREAM_PROTOTYPE)
  int isastream (int);
#endif /* !ACE_WIN32 && ACE_HAS_ISASTREAM_PROTOTYPE */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_STROPTS_H */
