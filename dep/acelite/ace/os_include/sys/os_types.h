// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_types.h
 *
 *  data types
 *
 *  $Id: os_types.h 96089 2012-08-21 16:59:07Z johnnyw $
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

#if defined (ACE_HAS_TYPES_H)
#  include /**/ <types.h>
#endif /* ACE_HAS_TYPES_H */

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

#if defined (ACE_LACKS_CLOCKID_T)
   typedef int clockid_t;
#endif /* ACE_LACKS_CLOCKID_T */

#if defined (ACE_LACKS_DEV_T)
   typedef unsigned int dev_t;
#endif /* ACE_LACKS_DEV_T */

#if defined (ACE_HAS_WINCE)
  typedef long off_t;
#endif

#if defined(ACE_WIN32) && defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS==64)
  typedef __int64 ACE_OFF_T;
#else
  typedef off_t ACE_OFF_T;
#endif

#if defined (ACE_SIZEOF_LONG) && ACE_SIZEOF_LONG == 8
   typedef off_t ACE_LOFF_T;
#elif defined (ACE_HAS_RTEMS) || defined (__FreeBSD__) || defined (__NetBSD__) || defined (__OpenBSD__) || defined (__APPLE__) || defined(__INTERIX) || \
  (defined (ACE_OPENVMS) && defined (_LARGEFILE))
   typedef off_t ACE_LOFF_T;
#elif defined (AIX) || defined (HPUX) || defined (__QNX__)
   typedef off64_t ACE_LOFF_T;
#elif defined (__sun)
   typedef offset_t ACE_LOFF_T;
#elif defined (WIN32)
   typedef __int64  ACE_LOFF_T;
#elif (defined (ACE_VXWORKS) && (ACE_VXWORKS <= 0x690)) || \
  defined (ACE_LYNXOS_MAJOR) || \
  (defined (ACE_OPENVMS) && !defined (_LARGEFILE)) || \
  defined (__TANDEM)
   typedef long long ACE_LOFF_T;
#else
   typedef loff_t ACE_LOFF_T;
#endif

#if defined (ACE_LACKS_UID_T)
typedef long uid_t;
#endif /* ACE_LACKS_UID_T */

#if defined (ACE_LACKS_GID_T)
typedef long gid_t;
#endif /* ACE_LACKS_GID_T */

#if defined (ACE_LACKS_CADDR_T)
typedef char *caddr_t;
#endif /* ACE_LACKS_CADDR_T */

#if defined (ACE_LACKS_MODE_T)
typedef u_short mode_t;
#endif /* ACE_LACKS_MODE_T */

#if defined (ACE_LACKS_NLINK_T)
typedef DWORD nlink_t;
#endif /* ACE_LACKS_NLINK_T */

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
