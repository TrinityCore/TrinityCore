// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_time.h
 *
 *  time types
 *
 *  $Id: os_time.h 87270 2009-10-29 21:47:47Z olli $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_TIME_H
#define ACE_OS_INCLUDE_OS_TIME_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// @todo should we include anything from signal.h?
#include "ace/os_include/sys/os_types.h"

// To get the proper select() signature, this is required for HP-UX, and
// maybe other platforms that offer both int and fdset forms of select().
// For HP-UX, sys/time.h must be included before time.h, or
// _XOPEN_SOURCE_EXTENDED must be defined. It's not nice to require
// the preprocessor macro, so we force our select() preference this way.
#if !defined (ACE_LACKS_SYS_TIME_H)
#  include /**/ <sys/time.h>
#endif /* !ACE_LACKS_SYS_TIME_H */

#if !defined (ACE_LACKS_TIME_H)
#  include /**/ <time.h>
#endif /* !ACE_LACKS_TIME_H */

# if defined (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB) && \
             (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB != 0)
using std::tm;
# if !defined (ACE_HAS_DINKUM_STL)
#  if defined (ACE_WIN32)
using std::_timezone;
#  else
using std::timezone;
#  endif
# endif
using std::difftime;
# endif /* ACE_USES_STD_NAMESPACE_FOR_STDC_LIB */

# if !defined (ACE_HAS_POSIX_TIME)
// Definition per POSIX.
typedef struct timespec
{
  /// Seconds
  time_t tv_sec;
  /// Nanoseconds
  long tv_nsec;
} timespec_t;
# elif defined (ACE_HAS_BROKEN_POSIX_TIME)
#  if defined (ACE_OPENVMS)
#     include /**/ <timers.h>
#  else
// OSF/1 defines struct timespec in <sys/timers.h> - Tom Marrs
#     include /**/ <sys/timers.h>
#  endif
# endif /* !ACE_HAS_POSIX_TIME */

# if defined(ACE_LACKS_TIMESPEC_T)
typedef struct timespec timespec_t;
# endif /* ACE_LACKS_TIMESPEC_T */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

// There are a lot of threads-related macro definitions in the config files.
// They came in at different times and from different places and platform
// requirements as threads evolved.  They are probably not all needed - some
// overlap or are otherwise confused.  This is an attempt to start
// straightening them out.
#if defined (ACE_HAS_PTHREADS)    /* POSIX.1c threads (pthreads) */
   // ... and 2-parameter asctime_r and ctime_r
#  if !defined (ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R) && \
      !defined (ACE_HAS_STHREADS) && !defined (ACE_VXWORKS)
#    define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R
#  endif
#endif /* ACE_HAS_PTHREADS */

#if defined (ACE_LACKS_STRPTIME_PROTOTYPE) && !defined (_XOPEN_SOURCE)
   extern char *strptime (const char *s, const char *fmt, struct tm *tp);
#endif  /* ACE_LACKS_STRPTIME_PROTOTYPE */

#if defined (ACE_LACKS_CONST_TIMESPEC_PTR)
typedef struct timespec * ACE_TIMESPEC_PTR;
#else
typedef const struct timespec * ACE_TIMESPEC_PTR;
#endif /* ACE_LACKS_CONST_TIMESPEC_PTR */

#if defined (DIGITAL_UNIX)
  extern char *_Pctime_r (const time_t *, char *);
  extern struct tm *_Plocaltime_r (const time_t *, struct tm *);
  extern struct tm *_Pgmtime_r (const time_t *, struct tm *);
  extern char *_Pasctime_r (const struct tm *, char *);
#endif /* DIGITAL_UNIX */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_TIME_H */
