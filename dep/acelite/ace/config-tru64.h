/* -*- C++ -*- */
// $Id: config-tru64.h 87270 2009-10-29 21:47:47Z olli $

// The following configuration file is designed to work for the
// Digital UNIX V4.0a and later platforms.  It relies on
// config-osf1-4.0.h, and adds deltas for newer platforms.

#ifndef ACE_CONFIG_TRU64_H
#define ACE_CONFIG_TRU64_H
#include /**/ "ace/pre.h"

#if !defined (__ACE_INLINE__)
# define __ACE_INLINE__
#endif /* ! __ACE_INLINE__ */

// Compile using multi-thread libraries.
#if !defined (ACE_MT_SAFE)
# define ACE_MT_SAFE 1
#endif /* ! ACE_MT_SAFE */

/*clearerr is not defined when _REENTRANT is not defined*/
#if ACE_MT_SAFE == 0
#define ACE_LACKS_CLEARERR
#endif /* ACE_MT_SAFE == 0 */

#include "ace/config-posix.h"

// Configuration-specific #defines:
// 1) g++ or cxx
// 2) pthreads or DCE threads
#if defined (__GNUG__)
  // g++ with pthreads

  // config-g++-common.h undef's ACE_HAS_STRING_CLASS with -frepo, so
  // this must appear before its #include.
# define ACE_HAS_STRING_CLASS

# include "ace/config-g++-common.h"

# define ACE_HAS_REENTRANT_FUNCTIONS
#elif defined (__DECCXX)

# define ACE_CONFIG_INCLUDE_CXX_COMMON
# include "ace/config-cxx-common.h"

#elif defined (__rational__)
# define ACE_HAS_REENTRANT_FUNCTIONS
# define ACE_HAS_STRING_CLASS
# define ACE_LACKS_LINEBUFFERED_STREAMBUF
# define ACE_LACKS_SIGNED_CHAR

    // Exceptions are enabled by platform_osf1_4.0_rcc.GNU.
# define ACE_HAS_STDCPP_STL_INCLUDES
#else
#  ifdef __cplusplus  /* Let it slide for C compilers. */
#   error unsupported compiler on Digital Unix
#  endif  /* __cplusplus */
#endif /* ! __GNUG__ && ! __DECCXX && ! __rational__ */

#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R
#define ACE_HAS_BROKEN_IF_HEADER
#if (ACE_MT_SAFE != 0)
# define ACE_HAS_PTHREADS
# define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS
#endif /* ACE_MT_SAFE != 0 */
#define ACE_LACKS_T_ERRNO
#if !defined (DIGITAL_UNIX)
#  define DIGITAL_UNIX 0x400
#endif /* ! DIGITAL_UNIX */

#define ACE_SIZEOF_LONG 8

#define ACE_DEFAULT_BASE_ADDR ((char *) 0x80000000)
#define ACE_HAS_AUTOMATIC_INIT_FINI
#define ACE_HAS_NONCONST_SETRLIMIT
#define ACE_HAS_BROKEN_T_ERROR
#define ACE_HAS_NONCONST_WRITEV
#define ACE_HAS_CLOCK_GETTIME
#define ACE_HAS_CLOCK_SETTIME
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES
#define ACE_HAS_CPLUSPLUS_HEADERS
#define ACE_HAS_DIRENT
#define ACE_HAS_GETRUSAGE
#define ACE_HAS_GPERF
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT
#define ACE_HAS_IP_MULTICAST
#define ACE_HAS_LLSEEK
#define ACE_HAS_LONG_MAP_FAILED
#define ACE_HAS_MSG
#define ACE_HAS_NONCONST_SELECT_TIMEVAL
#define ACE_HAS_NONCONST_SENDMSG
#define ACE_HAS_OSF1_GETTIMEOFDAY
#define ACE_HAS_OSF_TIMOD_H
#define ACE_HAS_POLL
#define ACE_HAS_POSIX_NONBLOCK
#define ACE_HAS_POSIX_TIME
#define ACE_HAS_PRIOCNTL
#define ACE_HAS_SIGINFO_T
#define ACE_HAS_SIG_ATOMIC_T
#define ACE_HAS_SSIZE_T
#define ACE_HAS_STRBUF_T
#define ACE_HAS_STREAMS
#define ACE_HAS_STRPTIME
#define ACE_HAS_SVR4_DYNAMIC_LINKING
#define ACE_HAS_SVR4_SIGNAL_T
#define ACE_HAS_SYS_SYSCALL_H
#define ACE_HAS_SYSV_IPC
#if (ACE_MT_SAFE == 0)
// clearerr is not defined when _REENTRANT is not defined
#define ACE_LACKS_CLEARERR
#else  /* ACE_MT_SAFE != 0 */
#define ACE_HAS_THREADS
#define ACE_HAS_THREAD_SPECIFIC_STORAGE
#define ACE_LACKS_PTHREAD_ATTR_SETSTACKADDR
#endif  /* ACE_MT_SAFE != 0 */
#define ACE_HAS_TIUSER_H
#define ACE_HAS_XTI
#define ACE_HAS_TLI_PROTOTYPES
#define ACE_HAS_UALARM
#define ACE_HAS_UCONTEXT_T
#define ACE_LACKS_PRI_T
#define ACE_LACKS_RWLOCK_T
#define ACE_PAGE_SIZE 8192
#define ACE_HAS_SIGTIMEDWAIT
#define ACE_HAS_SIGSUSPEND

// DJT 6/10/96 All these broken macro's can now be removed with the
// approporiate ordering of the include files. The Platinum release
// now temporarily supports both forms.  Platform's implementation of
// sendmsg() has a non-const msgheader parameter.
#define ACE_HAS_NONCONST_SENDMSG
#define ACE_HAS_IDTYPE_T
#define ACE_HAS_NONSTATIC_OBJECT_MANAGER

#if DIGITAL_UNIX >= 0x500
# define ACE_HAS_XPG4_MULTIBYTE_CHAR 1
#endif /* DIGITAL_UNIX >= 0x500 */

#if DIGITAL_UNIX >= 0x40E
# define ACE_LACKS_STDINT_H
#endif /* DIGITAL_UNIX >= 0x40E */

#if (DIGITAL_UNIX >= 0x400) && (DIGITAL_UNIX < 0x500)
#define ACE_LACKS_PREAD_PROTOTYPE
#endif /* (DIGITAL_UNIX >= 0x400) && (DIGITAL_UNIX < 0x500) */

// gethostbyaddr does not handle IPv6-mapped-IPv4 addresses
#define ACE_HAS_BROKEN_GETHOSTBYADDR_V4MAPPED

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_TRU64_H */
