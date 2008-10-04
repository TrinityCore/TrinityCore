// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_limits.h
 *
 *  implementation-defined constants
 *
 *  $Id: os_limits.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_LIMITS_H
#define ACE_OS_INCLUDE_OS_LIMITS_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_unistd.h"
#include "ace/os_include/os_stdio.h" // for FILENAME_MAX on Windows

#if !defined (ACE_LACKS_LIMITS_H)
# include /**/ <limits.h>
#endif /* !ACE_LACKS_LIMITS_H */

#if !defined (ACE_LACKS_SYS_PARAM_H)
#  include /**/ <sys/param.h>
#endif /* ACE_LACKS_SYS_PARAM_H */

// On VxWorks 5.5.1 _POSIX_TIMER_MAX is defined in time.h
#if defined (ACE_VXWORKS) && (ACE_VXWORKS < 0x620)
#  include /**/ <time.h>
#endif /* ACE_VXWORKS */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if ! defined (howmany)
#  define howmany(x, y)   (((x)+((y)-1))/(y))
#endif /* howmany */

#if !defined (NAME_MAX)
#  if defined (MAXNAMLEN)
#    define NAME_MAX MAXNAMLEN
#  elif defined (MAXNAMELEN)
#    define NAME_MAX MAXNAMELEN
#  elif defined (FILENAME_MAX)
#    define NAME_MAX FILENAME_MAX
#  elif defined (_MAX_FNAME)
#    define NAME_MAX _MAX_FNAME
#  else /* _MAX_FNAME */
#    define NAME_MAX 256
#  endif /* MAXNAMLEN */
#endif /* !NAME_MAX */

#if !defined (MAXNAMELEN)
#  define MAXNAMELEN NAME_MAX
#endif /* MAXNAMELEN */

#if !defined (HOST_NAME_MAX)
#  define HOST_NAME_MAX 256
#endif /* !HOST_NAME_MAX */

// Note that we are using PATH_MAX instead of _POSIX_PATH_MAX, since
// _POSIX_PATH_MAX is the *minimun* maximum value for PATH_MAX and is
// defined by POSIX as 256.
#if !defined (PATH_MAX)
#  if defined (_MAX_PATH)
#    define PATH_MAX _MAX_PATH
#  elif defined (MAX_PATH)
#    define PATH_MAX MAX_PATH
#  else /* !_MAX_PATH */
#    define PATH_MAX 1024
#  endif /* _MAX_PATH */
#endif /* !PATH_MAX */

// Leaving this for backward compatibility, but PATH_MAX should always be
// used directly.
#if !defined (MAXPATHLEN)
#  define MAXPATHLEN  PATH_MAX
#endif /* !MAXPATHLEN */

// This is defined by XOPEN to be a minimum of 16.  POSIX.1g
// also defines this value.  platform-specific config.h can
// override this if need be.
#if !defined (IOV_MAX)
#  define IOV_MAX 16
#endif /* IOV_MAX */

#if !defined (ACE_IOV_MAX)
#  define ACE_IOV_MAX IOV_MAX
#endif /* ACE_IOV_MAX */

#if defined (ACE_VXWORKS) && ((ACE_VXWORKS >= 0x620) && (ACE_VXWORKS <= 0x660)) && !defined (__RTP__)
#  if defined (PIPE_BUF) && (PIPE_BUF == -1)
#    undef PIPE_BUF
#  endif
#endif /* ACE_VXWORKS */

#if !defined (PIPE_BUF)
#  define PIPE_BUF 5120
#endif /* PIPE_BUF */

#if defined (ACE_HAS_POSIX_REALTIME_SIGNALS)
  // = Giving unique ACE scoped names for some important
  // RTSignal-Related constants. Becuase sometimes, different
  // platforms use different names for these constants.

  // Number of realtime signals provided in the system.
  // _POSIX_RTSIG_MAX is the upper limit on the number of real time
  // signals supported in a posix-4 compliant system.
#  if defined (_POSIX_RTSIG_MAX)
#    define ACE_RTSIG_MAX _POSIX_RTSIG_MAX
#  else /* not _POSIX_RTSIG_MAX */
  // POSIX-4 compilant system has to provide atleast 8 RT signals.
  // @@ Make sure the platform does *not* define this constant with
  // some other name. If yes, use that instead of 8.
#     define ACE_RTSIG_MAX 8
#  endif /* _POSIX_RTSIG_MAX */
#endif /* ACE_HAS_POSIX_REALTIME_SIGNALS */

  // The maximum number of concurrent timers per process.
# if !defined (_POSIX_TIMER_MAX)
#   define _POSIX_TIMER_MAX 44
# endif /* _POSIX_TIMER_MAX */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_LIMITS_H */
