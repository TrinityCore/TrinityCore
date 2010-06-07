// -*- C++ -*-
//
// $Id: config-linux.h 80826 2008-03-04 14:51:23Z wotte $

// The following configuration file is designed to work for Linux
// platforms using GNU C++.

#ifndef ACE_CONFIG_LINUX_H
#define ACE_CONFIG_LINUX_H
#include /**/ "ace/pre.h"

#define ACE_PLATFORM_CONFIG config-linux.h

#include "ace/config-linux-common.h"

#define ACE_HAS_SVR4_DYNAMIC_LINKING
#define ACE_HAS_AUTOMATIC_INIT_FINI
#define ACE_HAS_DLSYM_SEGFAULT_ON_INVALID_HANDLE

#if !defined (ACE_MT_SAFE)
#define ACE_MT_SAFE 1                           // JCEJ 12/22/96        #1
#endif

#if ACE_MT_SAFE
// Yes, we do have threads.
#define ACE_HAS_THREADS
// And they're even POSIX pthreads (LinuxThreads implementation)
#define ACE_HAS_PTHREADS

// On linux this is part of pthreads
#  if (defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 199309L)
#    if !defined (ACE_HAS_CLOCK_GETTIME)
#      if !defined(__PGI)
#        define ACE_HAS_CLOCK_GETTIME
#      endif /* __PGI */
#      define ACE_HAS_CLOCK_SETTIME
#    endif  /* !ACE_HAS_CLOCK_GETTIME */
#  endif  /* _POSIX_C_SOURCE >= 199309L */

#if !defined (ACE_HAS_PTHREADS_UNIX98_EXT)
#  define ACE_LACKS_RWLOCK_T
#else
#  define ACE_HAS_RECURSIVE_MUTEXES
#endif  /* !ACE_HAS_PTHREADS_UNIX98_EXT */

#define ACE_HAS_THREAD_SPECIFIC_STORAGE     // jcej 12/22/96         #2

#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS    // JCEJ 1/7-8/96

#if defined(__GLIBC__)
// Platform supports reentrant functions (i.e., all the POSIX *_r
// functions).
#define ACE_HAS_REENTRANT_FUNCTIONS

#if (__GLIBC__ < 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ < 1)
   // Older versions of glibc lacked reentrant netdb functions
#  define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS

   // glibc < 2.1 lacks pthread_attr_setstacksize()
#  define ACE_LACKS_PTHREAD_ATTR_SETSTACKSIZE
#endif /* (__GLIBC__ < 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ < 1) */

// uses ctime_r & asctime_r with only two parameters vs. three
#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R
#endif

#else
// AIO support pulls in the rt library, which pulls in the pthread
// library.  Disable AIO in single-threaded builds.
# undef ACE_HAS_AIO_CALLS
#endif  /* ACE_MT_SAFE */

#include /**/ "ace/post.h"

#endif /* ACE_CONFIG_LINUX_H */
