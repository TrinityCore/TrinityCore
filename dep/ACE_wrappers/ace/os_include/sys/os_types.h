// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_types.h
 *
 *  data types
 *
 *  $Id: os_types.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_SYS_OS_TYPES_H
#define ACE_OS_INCLUDE_SYS_OS_TYPES_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_stddef.h"

#if !defined (ACE_LACKS_SYS_TYPES_H)
#  include /**/ <sys/types.h>
#endif /* !ACE_LACKS_SYS_TYPES_H */

#if defined (ACE_HAS_WINCE)
#  include /**/ <types.h>
#endif /* ACE_HAS_WINCE */

# if defined (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB) && \
             (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB != 0)
using std::time_t;
# endif /* ACE_USES_STD_NAMESPACE_FOR_STDC_LIB */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

typedef double ACE_timer_t;

// todo: don't forget to clean this up!  ;-)
#if !defined (ACE_HAS_CLOCK_GETTIME) && !(defined (_CLOCKID_T_) || defined (_CLOCKID_T))
   typedef int clockid_t;
#  if !defined (CLOCK_REALTIME)
#    define CLOCK_REALTIME 0
#  endif /* CLOCK_REALTIME */
#endif /* ! ACE_HAS_CLOCK_GETTIME && ! _CLOCKID_T_ */

#if defined (ACE_HAS_WINCE)

// CE's add-on for c-style fstat/stat functionalities.  This struct is
// by no mean complete compared to what you usually find in UNIX
// platforms.  Only members that have direct conversion using Win32's
// BY_HANDLE_FILE_INFORMATION are defined so that users can discover
// non-supported members at compile time.  Time values are of type
// ACE_Time_Value for easy comparison.

// Since CE does not have _stat by default as NT/2000 does, the 'stat'
// struct defined here will be used.  Also note that CE file system
// struct is only for the CE 3.0 or later.
// Refer to the WCHAR.H from Visual C++ and WIBASE.H from eVC 3.0.

   typedef unsigned int dev_t;
#endif /* ACE_HAS_WINCE */

#if defined(ACE_WIN32) && defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS==64)
  typedef __int64 ACE_OFF_T;
#else
  typedef off_t ACE_OFF_T;
#endif

#if defined (ACE_SIZEOF_LONG) && ACE_SIZEOF_LONG == 8
   typedef off_t ACE_LOFF_T;
#elif defined (ACE_HAS_RTEMS) || defined (__FreeBSD__) || defined (__NetBSD__) || defined (__OpenBSD__) || defined (__APPLE__) || \
  (defined (ACE_OPENVMS) && defined (_LARGEFILE)) || defined(ACE_MVS)
   typedef off_t ACE_LOFF_T;
#elif defined (__sgi) || defined (AIX) || defined (HPUX) || defined (__QNX__)
   typedef off64_t ACE_LOFF_T;
#elif defined (__sun)
   typedef offset_t ACE_LOFF_T;
#elif defined (WIN32)
   typedef __int64  ACE_LOFF_T;
#elif (defined (ACE_VXWORKS) && (ACE_VXWORKS <= 0x660)) || \
  defined (ACE_LYNXOS_MAJOR) || \
  (defined (ACE_OPENVMS) && !defined (_LARGEFILE)) || \
  defined (__TANDEM)
   typedef long long ACE_LOFF_T;
#else
   typedef loff_t ACE_LOFF_T;
#endif

#if defined (ACE_WIN32)
#  if !defined (__BORLANDC__)
     typedef DWORD nlink_t;
#    if !defined(__MINGW32__)
        typedef int mode_t;
#    endif /* !__MINGW32__ */
     typedef long uid_t;
     typedef long gid_t;
#  endif /* __BORLANDC__ */
   typedef char *caddr_t;
#endif /* ACE_WIN32 */

#if defined (ACE_LACKS_KEY_T)
#  if defined (ACE_WIN32)
   // Win32 doesn't use numeric values to name its semaphores, it uses
   // strings!
     typedef char *key_t;
#  else
     typedef int key_t;
#  endif /* ACE_WIN32 */
#endif /* ACE_LACKS_KEY_T */

#if !defined (ACE_HAS_SSIZE_T)
#  if defined (ACE_WIN64)
  typedef SSIZE_T ssize_t;
#  else
  typedef int ssize_t;
#  endif /* ACE_WIN64 */
#endif /* ACE_HAS_SSIZE_T */

#if defined (ACE_WIN32)
   typedef DWORD ACE_exitcode;
#else
   typedef int ACE_exitcode;
#endif /* ACE_WIN32 */

#if defined (ACE_LACKS_SUSECONDS_T)
  typedef long suseconds_t;
#endif

#if defined (ACE_LACKS_USECONDS_T)
  typedef unsigned long useconds_t;
#endif

#if defined (ACE_WIN32) && !defined(__MINGW32__)
   typedef int pid_t;
#endif /* ACE_WIN32 */

# if !defined (ACE_INVALID_PID)
# define ACE_INVALID_PID ((pid_t) -1)
# endif /* ACE_INVALID_PID */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_SYS_OS_TYPES_H */

